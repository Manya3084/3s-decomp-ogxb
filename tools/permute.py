#!/usr/bin/env python3
"""Search small source rewrites that bring a function closer to retail.

The PS2 decompilation cannot keep some source details that MSVC's output
depends on. This tries the rewrites that account for most of them, one at a
time, keeping a rewrite only when the function's compiled code gets closer
to the retail body (fewer differing instructions), and repeats until nothing
helps or the function matches:

  - comparison form: `a < N` and `a <= N-1` (or `>`/`>=`) are the same test
    but compile to different bytes; MIPS has only "set less than", so the
    PS2 decompiler normalised them;
  - integer widths: a local or parameter declared s16/u16/s8/u8 that was an
    int in Capcom's code, or the other way round.

Only the function's own text changes (and its prototypes in the same file,
when a parameter type changes). With --apply a result that matches is
written back: into analysis-ps2map/overrides/<File>.c for a generated port,
or into the file itself for a hand port. Run tools/build_c.py and
tools/objdiff.py first; run analysis-ps2map/regen.py for the files that got
overrides afterwards.

    python3 tools/permute.py [--apply] [--max-size N] [-j N] [FUNC ...]
"""

from __future__ import annotations

import argparse
import difflib
import json
import os
import re
import subprocess
import sys
import tempfile
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

OVERRIDES = ROOT / "analysis-ps2map" / "overrides"
GENERATED = "Ported from the PS2"
CMP = re.compile(r"(?<![<>=!])(<=|>=|<|>)(?![<>=])\s*(-?0x[0-9A-Fa-f]+|-?\d+)\b")
NARROW = {"s16": ["s32"], "u16": ["s32", "u32"], "s8": ["s32"], "u8": ["s32", "u32"], "s32": ["s16"]}
LOCAL = re.compile(r"^(\s+)(s16|u16|s8|u8|s32)(\s+)([^;=(){}]+;)", re.M)


def find_definition(text: str, name: str) -> tuple[int, int] | None:
    m = re.search(r"^[A-Za-z_][^\n;{}]*\b" + re.escape(name) + r"\s*\([^;{}]*\)\s*\{", text, re.M)
    if not m:
        return None
    depth, i = 0, m.end() - 1
    while i < len(text):
        if text[i] == "{":
            depth += 1
        elif text[i] == "}":
            depth -= 1
            if depth == 0:
                return m.start(), i + 1
        i += 1
    return None


def mutations(func: str, name: str) -> list[tuple[str, str]]:
    """(description, new function text) for every single rewrite."""
    out = []
    body_start = func.index("{")
    for m in CMP.finditer(func, body_start):
        op, lit = m.group(1), m.group(2)
        v = int(lit, 0)
        new = {"<": ("<=", v - 1), "<=": ("<", v + 1), ">": (">=", v + 1), ">=": (">", v - 1)}[op]
        text = f"{new[0]} {hex(new[1]) if lit.lower().startswith(('0x', '-0x')) else new[1]}"
        out.append((f"{op} {lit} -> {text}", func[:m.start()] + text + func[m.end():]))
    for m in LOCAL.finditer(func, body_start):
        for t in NARROW[m.group(2)]:
            out.append((f"local {m.group(4).strip()[:-1]}: {m.group(2)} -> {t}",
                        func[:m.start(2)] + t + func[m.end(2):]))
    sig_end = func.index("{")
    for m in re.finditer(r"\b(s16|u16|s8|u8|s32)(\s+\w+\s*[,)])", func[:sig_end]):
        for t in NARROW[m.group(1)]:
            out.append((f"param {m.group(2).strip()[:-1].strip()}: {m.group(1)} -> {t}",
                        func[:m.start(1)] + t + func[m.end(1):]))
    return out


def retype_prototypes(text: str, name: str, old_sig: str, new_sig: str) -> str:
    """Keep the file's prototypes of name in step with a parameter change."""
    old_params = re.search(r"\(([^)]*)\)", old_sig).group(1)
    new_params = re.search(r"\(([^)]*)\)", new_sig).group(1)
    if old_params == new_params:
        return text
    old_types = [re.sub(r"\s*\b\w+$", "", p.strip()) for p in old_params.split(",")]
    new_types = [re.sub(r"\s*\b\w+$", "", p.strip()) for p in new_params.split(",")]

    def fix(m: re.Match) -> str:
        parts = m.group(2).split(",")
        if len(parts) != len(old_types):
            return m.group(0)
        out = []
        for p, o, n in zip(parts, old_types, new_types):
            out.append(p.replace(o, n, 1) if o != n else p)
        return m.group(1) + ",".join(out) + m.group(3)

    return re.sub(r"(^[^\n;{}]*\b" + re.escape(name) + r"\s*\()([^;{}()]*)(\)\s*;)", fix, text, flags=re.M)


class Scorer:
    def __init__(self):
        self.img = load(find_xbe())
        self.names = asmdiff.names_by_addr()
        addr, size = symbol_maps()
        self.ck = Checker(self.img, addr, size)
        xdk = build_c.find_xdk()
        self.cl = xdk / "xbox" / "bin" / "vc71" / "CL.Exe"
        inc = [ROOT / "include", ROOT / "include" / "msvc", xdk / "xbox" / "include"]
        self.env = dict(os.environ, WINEDEBUG="-all", INCLUDE=";".join(build_c.wine_path(p) for p in inc))
        self.tmp = Path(tempfile.mkdtemp(prefix="permute", dir=ROOT / "build"))

    def score(self, src: Path, text: str, name: str, va: int, slot: int, tag: str) -> tuple[str, int]:
        rel = src.relative_to(ROOT).as_posix()
        prepared, _ = build_c.prepare_text(text, rel)
        cfile = self.tmp / f"{tag}.c"
        obj = self.tmp / f"{tag}.obj"
        cfile.write_text(f'#line 1 "{src}"\n' + prepared)
        r = subprocess.run(["wine", str(self.cl), *build_c.COMMON, *build_c.flags_for(src),
                            "/Fo" + build_c.wine_path(obj), build_c.wine_path(cfile)],
                           env=self.env, capture_output=True)
        if r.returncode or not obj.is_file():
            return "error", 10 ** 6
        status = next((f["status"] for f in check_object(obj, self.ck, False)["functions"] if f["name"] == name), "missing")
        o = coff.read(obj.read_bytes())
        with Disassembler() as d:
            for sec in o.sections:
                if not sec.code:
                    continue
                for sym, s, e in function_ranges(sec, o):
                    if coff.undecorate(sym.name) != name:
                        continue
                    rl = {va + x.offset - s: coff.undecorate(o.symbols[x.symbol].name) for x in sec.relocs if s <= x.offset < e}
                    a = asmdiff.lines_for(d, sec.data[s:e], va, rl, self.names)
                    b = asmdiff.lines_for(d, self.img.bytes_at(va, slot), va, {}, self.names)
                    while b and b[-1] in ("int3", "nop"):
                        b.pop()
                    sm = difflib.SequenceMatcher(a=a, b=b, autojunk=False)
                    nd = sum(max(a1 - a0, b1 - b0) for t, a0, a1, b0, b1 in sm.get_opcodes() if t != "equal")
                    for f in (cfile, obj):
                        f.unlink(missing_ok=True)
                    return status, nd
        return status, 10 ** 6


def search(sc: Scorer, src: Path, name: str, va: int, slot: int, pool: ThreadPoolExecutor, rounds: int = 4):
    text = src.read_text(errors="replace")
    span = find_definition(text, name)
    if span is None:
        return None
    best_status, best = sc.score(src, text, name, va, slot, f"{name}_0")
    applied = []
    for rnd in range(rounds):
        if best_status == "match":
            break
        a, b = find_definition(text, name)
        func = text[a:b]
        cands = []
        for desc, new in mutations(func, name):
            t = text[:a] + new + text[b:]
            t = retype_prototypes(t, name, func[:func.index("{")], new[:new.index("{")])
            cands.append((desc, t))
        if not cands:
            break
        results = list(pool.map(lambda c: (c[0], c[1], *sc.score(src, c[1], name, va, slot, f"{name}_{rnd}_{abs(hash(c[0])) % 10**8}")), cands))
        results.sort(key=lambda r: (r[3], r[2] != "match"))
        desc, t, st, nd = results[0]
        if nd < best or (st == "match" and best_status != "match"):
            text, best, best_status = t, nd, st
            applied.append(desc)
        else:
            break
    return best_status, best, applied, text


def write_back(src: Path, name: str, text: str, applied: list[str]) -> str:
    a, b = find_definition(text, name)
    func = text[a:b]
    if GENERATED not in src.read_text(errors="replace")[:4000]:
        src.write_text(text)
        return str(src.relative_to(ROOT))
    ov = OVERRIDES / src.name
    old = ov.read_text() if ov.is_file() else ""
    note = f"/* Rewritten to match retail (tools/permute.py): {'; '.join(applied)}. */\n"
    span = find_definition(old, name)
    if span:
        old = old[:span[0]] + func + old[span[1]:]
    else:
        old = (old.rstrip("\n") + "\n\n" if old else "") + note + func + "\n"
    ov.write_text(old)
    return str(ov.relative_to(ROOT))


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--apply", action="store_true")
    ap.add_argument("--max-size", type=lambda s: int(s, 0), default=0x80)
    ap.add_argument("-j", type=int, default=24)
    ap.add_argument("--include-cri", action="store_true")
    ap.add_argument("funcs", nargs="*")
    a = ap.parse_args()
    report = json.loads(OUT.read_text())
    targets = []
    for rel, e in report.items():
        if rel.startswith("cri/") and not a.include_cri:
            continue
        for f in e["functions"]:
            if f["status"] != "diff" or "va" not in f or f.get("fold"):
                continue
            if a.funcs and f["name"] not in a.funcs:
                continue
            if not a.funcs and f["size"] > a.max_size:
                continue
            targets.append((f["size"], f["name"], ROOT / "src" / Path(rel).with_suffix(".c"), f["va"], f["slot"]))
    targets.sort()
    sc = Scorer()
    found = []
    with ThreadPoolExecutor(a.j) as pool:
        for size, name, src, va, slot in targets:
            r = search(sc, src, name, va, slot, pool)
            if r is None:
                print(f"{name}: definition not found in {src.relative_to(ROOT)}")
                continue
            st, nd, applied, text = r
            print(f"{name}: {st} ({nd} lines differ) {'; '.join(applied) if applied else 'no rewrite helped'}", flush=True)
            if st == "match" and applied:
                found.append(name)
                if a.apply:
                    print(f"  -> {write_back(src, name, text, applied)}")
    print(f"{len(found)} of {len(targets)} now match")
    return 0


if __name__ == "__main__":
    sys.exit(main())
