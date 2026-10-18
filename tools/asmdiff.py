#!/usr/bin/env python3
"""Compiled vs retail disassembly of one function, side by side.

Relocated operands are shown by symbol on the compiled side, so a line that
differs only by an address the relink resolves is not marked. Lines marked
'|' differ, '<' and '>' exist on one side only.

    python3 tools/asmdiff.py FUNC [FUNC ...]
    python3 tools/asmdiff.py --list [N]    # smallest differing functions
"""

from __future__ import annotations

import difflib
import json
import re
import struct
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))

from objdiff import OBJ, OUT, function_ranges, symbol_maps
from ogxb import coff
from ogxb.cap import Disassembler
from ogxb.paths import find_xbe
from ogxb.xbe import load

HEX = re.compile(r"0x[0-9a-f]+")


def names_by_addr() -> dict[int, str]:
    addr, _ = symbol_maps()
    return {a: n for n, a in addr.items()}


def norm(text: str, names: dict[int, str]) -> str:
    def sub(m: re.Match) -> str:
        v = int(m.group(0), 16)
        return names.get(v, m.group(0)) if v >= 0x10000 else m.group(0)
    return HEX.sub(sub, text)


def lines_for(d: Disassembler, code: bytes, va: int, relocs: dict[int, str], names: dict[int, str]) -> list[str]:
    out = []
    for i in d.disasm(code, va):
        text = f"{i.mnemonic} {i.op_str}".strip()
        hit = [n for o, n in relocs.items() if i.address <= o < i.address + i.size]
        if hit:
            # replace the relocated immediate/displacement with the symbol
            text = HEX.sub(lambda m: hit[0] if int(m.group(0), 16) >= 0x10 or len(hit) else m.group(0), text, count=1) if False else text
            text = re.sub(r"0x[0-9a-f]{2,}|\b0\b(?=\]|$)", hit[0], text, count=1) if re.search(r"0x[0-9a-f]{2,}|\b0\b(?=\]|$)", text) else text + f" ; {hit[0]}"
        else:
            text = norm(text, names)
        if text.startswith(("call ", "jmp ")) and not hit and re.fullmatch(r"(call|jmp) 0x[0-9a-f]+", text):
            t = int(text.split()[1], 16)
            text = f"{text.split()[0]} +{t - va:#x}" if va <= t < va + len(code) else text
        if text.startswith("j") and re.fullmatch(r"j\w+ 0x[0-9a-f]+", text):
            t = int(text.split()[1], 16)
            if va <= t < va + len(code):
                text = f"{text.split()[0]} +{t - va:#x}"
        out.append(text)
    return out


def show(name: str, report: dict, img, names: dict[int, str], d: Disassembler) -> None:
    for rel, entry in report.items():
        for f in entry["functions"]:
            if f["name"] != name or "va" not in f:
                continue
            obj = coff.read((OBJ / rel).read_bytes())
            for sec in obj.sections:
                if not sec.code:
                    continue
                for sym, start, end in function_ranges(sec, obj):
                    if coff.undecorate(sym.name) != name:
                        continue
                    body = sec.data[start:end]
                    va = f["va"]
                    relocs = {va + r.offset - start: coff.undecorate(obj.symbols[r.symbol].name)
                              for r in sec.relocs if start <= r.offset < end}
                    mine = lines_for(d, body, va, relocs, names)
                    retail = lines_for(d, img.bytes_at(va, f["slot"]), va, {}, names)
                    while retail and retail[-1] in ("int3", "nop"):
                        retail.pop()
                    print(f"== {name} {va:#x} ({rel}) compiled {len(body):#x} retail slot {f['slot']:#x}")
                    w = max([len(x) for x in mine] + [10])
                    sm = difflib.SequenceMatcher(a=mine, b=retail, autojunk=False)
                    for tag, a0, a1, b0, b1 in sm.get_opcodes():
                        for k in range(max(a1 - a0, b1 - b0)):
                            l = mine[a0 + k] if a0 + k < a1 else ""
                            r = retail[b0 + k] if b0 + k < b1 else ""
                            mark = " " if tag == "equal" else ("|" if l and r else ("<" if l else ">"))
                            print(f"  {l:<{w}} {mark} {r}")
                    return


def main() -> int:
    report = json.loads(OUT.read_text())
    if sys.argv[1:2] == ["--list"]:
        n = int(sys.argv[2]) if len(sys.argv) > 2 else 40
        rows = sorted((f["size"], f["name"], rel) for rel, e in report.items() for f in e["functions"] if f["status"] == "diff" and "va" in f)
        for size, name, rel in rows[:n]:
            print(f"{size:#6x} {name:32s} {rel}")
        return 0
    img = load(find_xbe())
    names = names_by_addr()
    with Disassembler() as d:
        for name in sys.argv[1:]:
            show(name, report, img, names, d)
    return 0


if __name__ == "__main__":
    sys.exit(main())
