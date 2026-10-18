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
import threading
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


OPERAND = r"[A-Za-z_][\w]*(?:(?:->|\.)\w+|\[[^\]\[]*\])*"
PAIR_CMP = re.compile(r"(?<![\w\]\)])(" + OPERAND + r")\s*(<=|>=|==|!=|<|>)\s*(" + OPERAND + r")(?![\w\[(])")
MIRROR = {"<": ">", ">": "<", "<=": ">=", ">=": "<=", "==": "==", "!=": "!="}
INVERT = {"<": ">=", ">=": "<", ">": "<=", "<=": ">", "==": "!=", "!=": "=="}
EARLY = re.compile(r"^(\s*)if \((.+)\) \{\n\s*return ([^;\n]+);\n\1\}\n(\s*\n)?\1return ([^;\n]+);", re.M)
ASSIGN = re.compile(r"^(\s+)([^;=\n{}()]+?)\s*=\s*([^;=\n][^;\n]*);$", re.M)
CALLEE_DECL = r"^((?:extern\s+)?)(s32|u32|int|s16|u16|s8|u8)(\s+)({name})(\s*\([^;{{}}]*\)\s*;)"
WIDTHS = ["s32", "u32", "s16", "u16", "s8", "u8"]


IFELSE = re.compile(r"^(\s*)if \((.+)\) \{\n\s*([^;\n=]+?) = ([^;\n]+);\n\1\} else \{\n\s*\3 = ([^;\n]+);\n\1\}", re.M)
BOOLRET = re.compile(r"^(\s*)if \((.+)\) \{\n\s*return (0|1);\n\1\}\n(\s*\n)?\1return (0|1);", re.M)


def invert(cond: str) -> str:
    m = re.fullmatch(r"\s*(" + OPERAND + r"|-?\w+)\s*(<=|>=|==|!=|<|>)\s*(" + OPERAND + r"|-?\w+)\s*", cond)
    if m:
        return f"{m.group(1)} {INVERT[m.group(2)]} {m.group(3)}"
    return f"!({cond})"


def idents(s: str) -> set[str]:
    return set(re.findall(r"[A-Za-z_]\w*", s))


def mutations(func: str, name: str, file_text: str = "") -> list[tuple[str, str]]:
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
    # a comparison of two operands written the other way round
    for m in PAIR_CMP.finditer(func, body_start):
        a, op, b = m.group(1), m.group(2), m.group(3)
        if a.isdigit() or b.isdigit() or a == b or op in ("==", "!=") and False:
            continue
        text = f"{b} {MIRROR[op]} {a}"
        out.append((f"{a} {op} {b} -> {text}", func[:m.start()] + text + func[m.end():]))
    # an early return turned round: if (c) return x; return y;
    for m in EARLY.finditer(func, body_start):
        ind, cond, x, y = m.group(1), m.group(2), m.group(3), m.group(5)
        text = f"{ind}if ({invert(cond)}) {{\n{ind}    return {y};\n{ind}}}\n\n{ind}return {x};"
        out.append((f"if ({cond}) return {x}; return {y} -> inverted", func[:m.start()] + text + func[m.end():]))
    # if/else assigning one target becomes a conditional expression (MSVC
    # computes a ternary of constants without a branch: neg/sbb/and/add)
    for m in IFELSE.finditer(func, body_start):
        ind, cond, lv, x, y = m.group(1), m.group(2), m.group(3).strip(), m.group(4), m.group(5)
        text = f"{ind}{lv} = ({cond}) ? {x} : {y};"
        out.append((f"if/else on {lv} -> ?:", func[:m.start()] + text + func[m.end():]))
    # if (x) return 1; return 0;  ->  return x != 0;
    for m in BOOLRET.finditer(func, body_start):
        ind, cond, a, b = m.group(1), m.group(2), m.group(3), m.group(5)
        if a == b:
            continue
        expr = f"({cond}) != 0" if a == "1" else f"({cond}) == 0"
        out.append((f"if ({cond}) return {a}; return {b} -> return {expr}", func[:m.start()] + f"{ind}return {expr};" + func[m.end():]))
    # two adjacent independent assignments in the other order
    stmts = list(ASSIGN.finditer(func, body_start))
    for s1, s2 in zip(stmts, stmts[1:]):
        if func[s1.end():s2.start()].strip() or s1.group(1) != s2.group(1):
            continue
        l1, l2 = s1.group(2).strip(), s2.group(2).strip()
        # independent when neither statement reads or writes the other's target
        if l1 in s2.group(0) or l2 in s1.group(0) or "(" in l1 + l2:
            continue
        swapped = s2.group(0).lstrip("\n") + "\n" + s1.group(0).lstrip("\n")
        out.append((f"swap '{s1.group(2).strip()} =' and '{s2.group(2).strip()} ='",
                    func[:s1.start()] + s1.group(1) + swapped.lstrip() + func[s2.end():]))
    return out


PARAM_ALT = {"u16": ["s16", "s32"], "s16": ["u16", "s32"], "s32": ["s16", "u16"],
             "u8": ["s8", "s32"], "s8": ["u8", "s32"], "u32": ["s32"]}
CALLEE_PROTO = r"^((?:extern\s+)?[A-Za-z_][\w \*]*?\b{name}\s*\()([^;{{}}()]+)(\)\s*;)"


def callee_mutations(text: str, func: str) -> list[tuple[str, str]]:
    """Rewrites of the file's declarations of the function's callees (the
    file text changes, not the function's): the return type of a callee with
    no C definition, and the type of one integer parameter. A caller's
    prototype decides how a narrow argument is extended at the call, and
    Capcom's prototypes did not always agree with the definition."""
    out = []
    defined = build_c.return_types()
    for callee in sorted(set(re.findall(r"\b([A-Za-z_]\w*)\s*\(", func[func.index("{"):]))):
        m = re.search(CALLEE_DECL.format(name=re.escape(callee)), text, re.M)
        if m and callee not in defined:
            for w in WIDTHS:
                if w != m.group(2):
                    out.append((f"{callee} returns {w}", text[:m.start(2)] + w + text[m.end(2):]))
        m = re.search(CALLEE_PROTO.format(name=re.escape(callee)), text, re.M)
        if not m:
            continue
        params = m.group(2).split(",")
        for k, p in enumerate(params):
            tm = re.match(r"\s*(u16|s16|s32|u8|s8|u32)\b", p)
            if not tm or "*" in p:
                continue
            for alt in PARAM_ALT[tm.group(1)]:
                new = params[:k] + [p[:tm.start(1)] + alt + p[tm.end(1):]] + params[k + 1:]
                out.append((f"{callee} parameter {k + 1}: {tm.group(1)} -> {alt}",
                            text[:m.start(2)] + ",".join(new) + text[m.end(2):]))
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
        self._n = 0
        self._lock = threading.Lock()

    def score(self, src: Path, text: str, name: str, va: int, slot: int, tag: str) -> tuple[str, int]:
        rel = src.relative_to(ROOT).as_posix()
        prepared, _ = build_c.prepare_text(text, rel)
        with self._lock:
            self._n += 1
            tag = f"{tag[:40]}_{self._n}"
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
        cands += callee_mutations(text, func)
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


WRITE_LOCK = threading.Lock()


def write_back(src: Path, name: str, text: str, applied: list[str]) -> str:
    """Write one function's result into the current file (or override), so
    results for other functions of the same file are kept."""
    a, b = find_definition(text, name)
    func = text[a:b]
    rel = src.relative_to(ROOT).as_posix()
    decl = []
    for part in applied:
        pm = re.match(r"(\w+) parameter (\d+): (\w+) -> (\w+)$", part)
        rm = re.match(r"(\w+) returns (\w+)$", part)
        if pm:
            decl.append(f"{rel} {pm.group(1)} param {pm.group(2)} {pm.group(4)}")
        elif rm:
            decl.append(f"{rel} {rm.group(1)} return {rm.group(2)}")
    with WRITE_LOCK:
        if decl:
            # a callee's declaration is not part of the function: it goes in
            # config/sf33rd/declfix.txt, which the build applies
            lines = build_c.DECLFIX.read_text().splitlines() if build_c.DECLFIX.is_file() else []
            head = [l for l in lines if l.startswith("#") or not l.strip()]
            body = sorted(set(l for l in lines if l.strip() and not l.startswith("#")) | set(decl))
            build_c.DECLFIX.write_text("\n".join(head + body) + "\n")
        cur = src.read_text(errors="replace")
        if GENERATED not in cur[:4000]:
            span = find_definition(cur, name)
            old_func = cur[span[0]:span[1]]
            cur = cur[:span[0]] + func + cur[span[1]:]
            cur = retype_prototypes(cur, name, old_func[:old_func.index("{")], func[:func.index("{")])
            src.write_text(cur)
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
    ap.add_argument("--accept-reloc", action="store_true",
                    help="also write results whose bytes match but whose relocations the check could not resolve")
    ap.add_argument("--parallel", type=int, default=6, help="functions searched at once")
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
    log_lock = threading.Lock()

    def one(target):
        size, name, src, va, slot = target
        r = search(sc, src, name, va, slot, pool)
        with log_lock:
            if r is None:
                print(f"{name}: definition not found in {src.relative_to(ROOT)}", flush=True)
                return
            st, nd, applied, text = r
            print(f"{name}: {st} ({nd} lines differ) {'; '.join(applied) if applied else 'no rewrite helped'}", flush=True)
        if (st == "match" or a.accept_reloc and st == "reloc") and applied:
            found.append(name)
            if a.apply:
                dest = write_back(src, name, text, applied)
                with log_lock:
                    print(f"  -> {dest}", flush=True)

    # several functions at once over one pool of compiles, so a function
    # with few candidates does not leave workers idle
    with ThreadPoolExecutor(a.j) as pool, ThreadPoolExecutor(a.parallel) as outer:
        list(outer.map(one, targets))
    print(f"{len(found)} of {len(targets)} now match")
    return 0


if __name__ == "__main__":
    sys.exit(main())
