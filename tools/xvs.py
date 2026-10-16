#!/usr/bin/env python3
"""List .xvu vertex programs, or disassemble the files named on the command line."""

from __future__ import annotations

import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))

from ogxb.paths import find_shaders
from ogxb.xvs import decode_program, format_slot, list_shaders


def disassemble(paths: list[str]) -> int:
    status = 0
    for arg in paths:
        path = Path(arg)
        slots = decode_program(path.read_bytes())
        if slots is None:
            print(f"bad {path.name}", file=sys.stderr)
            status = 1
            continue
        print(f"{path.name}  {len(slots)}")
        for index, slot in enumerate(slots):
            print(format_slot(index, slot))
    return status


def summarize() -> int:
    directory = find_shaders()
    if directory is None or not directory.is_dir():
        print("shader directory not found. Set SF33RD_SHADERS.", file=sys.stderr)
        return 1
    programs, other = list_shaders(directory)
    counts = [item.count for item in programs]
    final_last = 0
    final_early = 0
    word0 = 0
    for item in programs:
        slots = decode_program(item.path.read_bytes())
        if not slots:
            continue
        if slots[-1].final:
            final_last += 1
        for index, slot in enumerate(slots):
            if slot.word0:
                word0 += 1
            if slot.final and index != len(slots) - 1:
                final_early += 1
    print(f"dir   {directory}")
    print(f"xvu   {len(programs)}  instructions {min(counts)}..{max(counts)}")
    print(f"slots {sum(counts)}  final-on-last {final_last}  final-early {final_early}  word0 {word0}")
    print(f"other {len(other)}")
    for path in other:
        if path.suffix.lower() == ".xvu":
            print(f"  bad {path.name}")
    return 0


def main() -> int:
    if len(sys.argv) > 1:
        return disassemble(sys.argv[1:])
    return summarize()


if __name__ == "__main__":
    raise SystemExit(main())
