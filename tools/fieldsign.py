#!/usr/bin/env python3
"""Search the signedness of struct fields and globals against retail.

A 16- or 8-bit value is sign-extended (movsx) or zero-extended (movzx, or
xor and a narrow mov) depending on its declared type, and the PS2
decompilation guessed many of those types. This finds the loads where the
compiled code and retail extend the same operand differently, turns them
into candidates, and tries each one over the whole tree:

  - a load from [reg + disp] of width w: every field of include/structs.h
    at offset disp with size w (the offset comments give it) whose type has
    the compiled side's signedness;
  - a load from an absolute address: the global at that address, flipped in
    every declaration in src/;
  - a function whose declarations disagree on an integer parameter's type:
    each variant, written into its definition and every declaration.

A candidate is a single flip (s16 <-> u16, s8 <-> u8). It is kept when the
whole tree, built with it, matches more functions and loses none; kept
flips accumulate, so later candidates are tried on top of them.

    python3 tools/fieldsign.py [--apply] [--max N] [-j N]

Without --apply, kept flips are only reported. Run tools/build_c.py and
tools/objdiff.py first.
"""

from __future__ import annotations

import argparse
import collections
import difflib
import json
import os
import re
import shutil
import subprocess
import sys
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))

import asmdiff
import build_c
from objdiff import OBJ, OUT, Checker, check_object, function_ranges, symbol_maps
from ogxb import coff
from ogxb.cap import Disassembler
from ogxb.paths import ROOT, find_xbe
from ogxb.xbe import load

STRUCTS = ROOT / "include" / "structs.h"
WORK = ROOT / "build" / "fieldsign"
FIELD = re.compile(r"^(\s+)(s16|u16|s8|u8)(\s+)(\w+)((?:\[[^\]]*\])*;\s*// offset 0x([0-9A-Fa-f]+), size 0x([0-9A-Fa-f]+))", re.M)
FLIP = {"s16": "u16", "u16": "s16", "s8": "u8", "u8": "s8"}
LOAD = re.compile(r"^(movsx|movzx|mov) (\w+), (byte|word) ptr \[([^\]]+)\]$")


def loads(lines: list[str]) -> list[tuple[str, int, str]]:
    """(operand, width, 'signed'/'unsigned') for each narrow load. A narrow
    mov right after xor of the same register is a zero-extension."""
    out = []
    for k, l in enumerate(lines):
        m = LOAD.match(l)
        if not m:
            continue
        w = 1 if m.group(3) == "byte" else 2
        if m.group(1) == "movsx":
            out.append((m.group(4), w, "signed"))
        elif m.group(1) == "movzx":
            out.append((m.group(4), w, "unsigned"))
        elif k and re.match(r"xor (e\w\w), \1$", lines[k - 1]) and m.group(2)[-1] in "xl":
            out.append((m.group(4), w, "unsigned"))
    return out


def evidence(report: dict, img, names) -> collections.Counter:
    """(operand kind, key, width, wanted signedness) -> how many functions."""
    ev = collections.Counter()
    with Disassembler() as d:
        for rel, e in report.items():
            diffs = {f["name"]: f for f in e["functions"] if f["status"] == "diff" and "va" in f}
            if not diffs:
                continue
            o = coff.read((OBJ / rel).read_bytes())
            for sec in o.sections:
                if not sec.code:
                    continue
                for sym, s, en in function_ranges(sec, o):
                    f = diffs.get(coff.undecorate(sym.name))
                    if not f:
                        continue
                    va = f["va"]
                    rl = {va + r.offset - s: coff.undecorate(o.symbols[r.symbol].name) for r in sec.relocs if s <= r.offset < en}
                    a = asmdiff.lines_for(d, sec.data[s:en], va, rl, names)
                    b = asmdiff.lines_for(d, img.bytes_at(va, f["slot"]), va, {}, names)
                    mine = {(op, w): k for op, w, k in loads(a)}
                    seen = set()
                    for op, w, k in loads(b):
                        if mine.get((op, w)) and mine[(op, w)] != k:
                            m = re.fullmatch(r"e\w\w(?: \+ (0x[0-9a-f]+|\d+))?", op)
                            if m:
                                key = ("disp", int(m.group(1) or "0", 0), w, k)
                            elif re.fullmatch(r"[A-Za-z_]\w*", op):
                                key = ("global", op, w, k)
                            else:
                                continue
                            if key not in seen:
                                seen.add(key)
                                ev[key] += 1
    return ev


def candidates(ev: collections.Counter, structs_text: str) -> list[tuple[int, str, dict]]:
    """(evidence count, description, change) in the order to try them."""
    by_slot = collections.defaultdict(list)
    for m in FIELD.finditer(structs_text):
        by_slot[(int(m.group(6), 16), int(m.group(7), 16))].append(m)
    out = []
    for (kind, key, w, want), n in ev.items():
        if kind == "disp":
            for m in by_slot.get((key, w), []):
                have = "signed" if m.group(2).startswith("s") else "unsigned"
                if have != want:
                    out.append((n, f"field {m.group(4)} (+{key:#x}): {m.group(2)} -> {FLIP[m.group(2)]}",
                                {"kind": "field", "pos": m.start(2), "old": m.group(2), "name": m.group(4)}))
        else:
            out.append((n, f"global {key}: make it {want}", {"kind": "global", "name": key, "want": want, "width": w}))
    out.sort(key=lambda c: -c[0])
    return out


GLOBAL_DECL = r"^((?:extern\s+)?(?:const\s+)?)(s16|u16|s8|u8)(\s+{name}\b)"
PROTO = re.compile(r"^(?:extern\s+|static\s+)?[A-Za-z_][\w \*]*?\b(\w+)\s*\(([^;{}()]*)\)\s*[;{]", re.M)
INT_PARAM = re.compile(r"^(\s*(?:const\s+)?)(s8|u8|s16|u16|s32|u32|int)\b(?!\s*\*)")


def param_types(params: str) -> list[str]:
    out = []
    for x in params.split(","):
        x = re.sub(r"/\*.*?\*/", "", x)
        m = INT_PARAM.match(x)
        out.append(m.group(2) if m else "other")
    return out


def proto_candidates(files: list[Path]) -> list[tuple[int, str, dict]]:
    """Functions whose declarations in src/ disagree on an integer
    parameter's type: try each variant everywhere. Capcom's headers were
    consistent, and a caller's prototype decides how a narrow argument is
    extended (set_char_move_init's index is s16 in 117 declarations and s32
    in 15, and retail sign-extends it)."""
    sigs = collections.defaultdict(collections.Counter)
    for p in files:
        text = re.sub(r"^#if 0\b.*?^#endif\b", "", p.read_text(errors="replace"), flags=re.M | re.S)
        for m in PROTO.finditer(text):
            if m.group(1) in ("if", "while", "for", "switch"):
                continue
            sigs[m.group(1)][tuple(param_types(m.group(2)))] += 1
    out = []
    for name, variants in sigs.items():
        lengths = {len(v) for v in variants}
        if len(variants) < 2 or len(lengths) != 1:
            continue
        cols = list(zip(*variants))
        if not any(len({c for c in col if c != "other"}) > 1 and "other" not in col for col in cols):
            continue
        for v, n in variants.items():
            out.append((n, f"{name}({', '.join(v)}) everywhere", {"kind": "proto", "name": name, "types": list(v)}))
    out.sort(key=lambda c: (c[2]["name"], -c[0]))
    return out


def apply_proto(texts: dict[Path, str], name: str, types: list[str]) -> dict[Path, str]:
    pat = re.compile(r"^((?:extern\s+|static\s+)?[A-Za-z_][\w \*]*?\b" + re.escape(name) + r"\s*\()([^;{}()]*)(\)\s*[;{])", re.M)
    out = {}
    for p, t in texts.items():
        def fix(m):
            params = m.group(2).split(",")
            if len(params) != len(types):
                return m.group(0)
            new = []
            for x, want in zip(params, types):
                tm = INT_PARAM.match(x)
                if tm and want != "other" and tm.group(2) != want:
                    x = x[:tm.start(2)] + want + x[tm.end(2):]
                new.append(x)
            return m.group(1) + ",".join(new) + m.group(3)
        nt = pat.sub(fix, t)
        if nt != t:
            out[p] = nt
    return out


def apply_global(texts: dict[Path, str], name: str, want: str, width: int) -> dict[Path, str]:
    out = {}
    pat = re.compile(GLOBAL_DECL.format(name=re.escape(name)), re.M)
    for p, t in texts.items():
        def fix(m):
            ty = m.group(2)
            if ("signed" if ty.startswith("s") else "unsigned") == want:
                return m.group(0)
            return m.group(1) + FLIP[ty] + m.group(3)
        nt = pat.sub(fix, t)
        if nt != t:
            out[p] = nt
    return out


class Tree:
    """Builds all of src/ with given replacement texts and compares."""

    def __init__(self, jobs: int):
        xdk = build_c.find_xdk()
        self.cl = xdk / "xbox" / "bin" / "vc71" / "CL.Exe"
        self.inc = [WORK / "include", ROOT / "include", ROOT / "include" / "msvc", xdk / "xbox" / "include"]
        self.env = dict(os.environ, WINEDEBUG="-all", INCLUDE=";".join(build_c.wine_path(p) for p in self.inc))
        self.jobs = jobs
        addr, size = symbol_maps()
        self.ck = Checker(load(find_xbe()), addr, size)
        self.files = sorted(build_c.SRC.rglob("*.c"))

    def build(self, structs_text: str, sources: dict[Path, str], tag: str, only: list[Path] | None = None) -> dict[str, str]:
        d = WORK / tag
        shutil.rmtree(d, ignore_errors=True)
        (WORK / "include").mkdir(parents=True, exist_ok=True)
        (WORK / "include" / "structs.h").write_text(structs_text)

        def job(src: Path):
            rel = src.relative_to(ROOT).as_posix()
            text = sources.get(src) or src.read_text(errors="replace")
            prepared, _ = build_c.prepare_text(text, rel)
            c = d / "src" / src.relative_to(build_c.SRC)
            c.parent.mkdir(parents=True, exist_ok=True)
            c.write_text(f'#line 1 "{src}"\n' + prepared)
            o = d / "obj" / src.relative_to(build_c.SRC).with_suffix(".obj")
            o.parent.mkdir(parents=True, exist_ok=True)
            subprocess.run(["wine", str(self.cl), *build_c.COMMON, *build_c.flags_for(src),
                            "/Fo" + build_c.wine_path(o), build_c.wine_path(c)], env=self.env, capture_output=True)
            if not o.is_file():
                return {}
            rel_o = src.relative_to(build_c.SRC).with_suffix(".obj").as_posix()
            return {f"{rel_o}|{f['name']}": f["status"] for f in check_object(o, self.ck, False)["functions"] if "va" in f}

        with ThreadPoolExecutor(self.jobs) as pool:
            res = {}
            for r in pool.map(job, only if only is not None else self.files):
                res.update(r)
        shutil.rmtree(d, ignore_errors=True)
        return res


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--apply", action="store_true")
    ap.add_argument("--max", type=int, default=200)
    ap.add_argument("-j", type=int, default=24)
    a = ap.parse_args()
    report = json.loads(OUT.read_text())
    img = load(find_xbe())
    ev = evidence(report, img, asmdiff.names_by_addr())
    print(f"{sum(ev.values())} differing extensions at {len(ev)} operands", flush=True)
    structs_text = STRUCTS.read_text()
    sources: dict[Path, str] = {}
    tree = Tree(a.j)
    base = tree.build(structs_text, sources, "base")
    base_n = sum(1 for s in base.values() if s == "match")
    print(f"baseline: {base_n} matches", flush=True)
    kept = []
    tried = set()
    texts_cache: dict[Path, str] = {}
    cands = proto_candidates(tree.files) + candidates(ev, structs_text)[:a.max]
    print(f"{len(cands)} candidates", flush=True)
    for n, desc, ch in cands:
        if desc in tried:
            continue
        tried.add(desc)
        new_structs, new_sources = structs_text, dict(sources)
        if ch["kind"] == "field":
            pos = ch["pos"]
            if new_structs[pos:pos + len(ch["old"])] != ch["old"]:
                continue  # already flipped by a kept candidate
            new_structs = new_structs[:pos] + FLIP[ch["old"]] + new_structs[pos + len(ch["old"]):]
        else:
            texts = {p: new_sources.get(p) or p.read_text(errors="replace") for p in tree.files}
            if ch["kind"] == "proto":
                changed = apply_proto(texts, ch["name"], ch["types"])
            else:
                changed = apply_global(texts, ch["name"], ch["want"], ch["width"])
            if not changed:
                continue
            new_sources.update(changed)
        # only the files the change can reach are rebuilt; the rest keep
        # their baseline results
        if ch["kind"] == "field":
            word = re.compile(r"(?:\.|->)\s*" + re.escape(ch["name"]) + r"\b")
        else:
            word = re.compile(r"\b" + re.escape(ch["name"]) + r"\b")
        only = [p for p in tree.files if word.search(new_sources.get(p) or texts_cache.setdefault(p, p.read_text(errors="replace")))]
        if not only:
            continue
        res = tree.build(new_structs, new_sources, "try", only)
        prefixes = {p.relative_to(build_c.SRC).with_suffix(".obj").as_posix() + "|" for p in only}
        scope = {k: s for k, s in base.items() if any(k.startswith(x) for x in prefixes)}
        gained = [k for k, s in res.items() if s == "match" and scope.get(k) != "match"]
        lost = [k for k, s in scope.items() if s == "match" and res.get(k) != "match"]
        verdict = "keep" if gained and not lost else "no"
        print(f"[{n}] {desc} ({len(only)} files): +{len(gained)} -{len(lost)} {verdict}", flush=True)
        if verdict == "keep":
            structs_text, sources = new_structs, new_sources
            base.update(res)
            kept.append((desc, gained))
    print(f"kept {len(kept)} flips, {sum(1 for s in base.values() if s == 'match') - base_n} more matches")
    if a.apply and kept:
        STRUCTS.write_text(structs_text)
        for p, t in sources.items():
            p.write_text(t)
        print("written: include/structs.h" + (f" and {len(sources)} sources" if sources else ""))
    (ROOT / "build" / "fieldsign.json").write_text(json.dumps(kept, indent=1))
    return 0


if __name__ == "__main__":
    sys.exit(main())
