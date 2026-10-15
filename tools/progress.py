#!/usr/bin/env python3
"""Count names in funcs.txt against the scanned starts."""

from __future__ import annotations

import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))

from ogxb.cap import Disassembler
from ogxb.funcs import function_starts
from ogxb.paths import ROOT, find_xbe
from ogxb.xbe import load

FUNCS = ROOT / "config" / "sf33rd" / "symbols" / "funcs.txt"
NAME = re.compile(r"^([A-Za-z_.$][\w.$]*)\s*=\s*(0x[0-9A-Fa-f]+)\s*;.*\btype:func\b")


def named() -> list[tuple[str, int]]:
    found = []
    if not FUNCS.is_file():
        return found
    for line in FUNCS.read_text().splitlines():
        match = NAME.match(line.strip())
        if match:
            found.append((match.group(1), int(match.group(2), 16)))
    return found


def main() -> int:
    path = find_xbe()
    if path is None or not path.is_file():
        print("sf33rd.xbe not found. Set SF33RD_XBE or write xbe.path.", file=sys.stderr)
        return 1
    image = load(path)
    text, blob = image.text
    with Disassembler() as dis:
        starts = function_starts(blob, text.va, image.entry, dis)
    start_set = set(starts)
    rows = named()
    matched = [item for item in rows if item[1] in start_set]
    missed = [item for item in rows if item[1] not in start_set]
    print(f"named {len(rows)}")
    print(f"on a start {len(matched)}")
    print(f"scanned {len(starts)}")
    for name, va in missed:
        print(f"  not a start {name} {va:#x}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
