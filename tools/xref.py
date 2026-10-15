#!/usr/bin/env python3
"""Show functions that push or mov a string containing the given text."""

from __future__ import annotations

import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))

from ogxb.cap import Disassembler
from ogxb.funcs import containing, function_starts
from ogxb.paths import find_xbe
from ogxb.strings import c_strings, imm_sites
from ogxb.xbe import load


def main(argv: list[str]) -> int:
    if len(argv) != 2:
        print("usage: xref.py <text>", file=sys.stderr)
        return 2
    needle = argv[1]
    path = find_xbe()
    if path is None or not path.is_file():
        print("sf33rd.xbe not found. Set SF33RD_XBE or write xbe.path.", file=sys.stderr)
        return 1
    image = load(path)
    text, blob = image.text
    with Disassembler() as dis:
        starts = function_starts(blob, text.va, image.entry, dis)
    sites = imm_sites(blob, text.va)
    hits = 0
    for section in image.sections:
        if section.name not in (".rdata", ".data", ".text"):
            continue
        raw = image.data[section.raw : section.raw + section.raw_size]
        for va, literal in c_strings(raw, section.va):
            if needle not in literal:
                continue
            refs = sites.get(va, [])
            hits += 1
            print(f"{va:#010x} {section.name} refs {len(refs)}")
            print(f"  {literal}")
            for site, kind in refs:
                owner = containing(starts, site)
                owner_s = f"{owner:#010x}" if owner is not None else "-"
                print(f"  {site:#010x} {kind} in {owner_s}")
    if not hits:
        print("no string")
        return 1
    return 0


if __name__ == "__main__":
    raise SystemExit(main(sys.argv))
