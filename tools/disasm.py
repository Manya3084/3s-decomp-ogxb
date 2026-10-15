#!/usr/bin/env python3
"""Disassemble one function from sf33rd.xbe. Stops when the bytes stop decoding."""

from __future__ import annotations

import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))

from ogxb.cap import Disassembler
from ogxb.funcs import containing, function_starts
from ogxb.paths import find_xbe
from ogxb.xbe import load


def main(argv: list[str]) -> int:
    if len(argv) != 2:
        print("usage: disasm.py <va>", file=sys.stderr)
        return 2
    va = int(argv[1], 0)
    path = find_xbe()
    if path is None or not path.is_file():
        print("sf33rd.xbe not found. Set SF33RD_XBE or write xbe.path.", file=sys.stderr)
        return 1
    image = load(path)
    text, blob = image.text
    with Disassembler() as dis:
        starts = function_starts(blob, text.va, image.entry, dis)
        owner = containing(starts, va)
        if owner is None:
            print(f"{va:#x} is outside the scanned starts")
            owner = va
        index = starts.index(owner) if owner in starts else None
        end = starts[index + 1] if index is not None and index + 1 < len(starts) else text.va + text.raw_size
        print(f"function {owner:#010x} span {end - owner:#x}  at {va:#010x}")
        cursor = owner
        while cursor < end:
            window = blob[cursor - text.va : min(cursor - text.va + 16, len(blob))]
            insns = dis.disasm(window, cursor, 1)
            if not insns or insns[0].address != cursor or insns[0].size == 0:
                trail = end - cursor
                print(f"; stop {cursor:#010x}  {trail:#x} bytes until the next start")
                break
            insn = insns[0]
            raw = blob[cursor - text.va : cursor - text.va + insn.size].hex()
            mark = ">" if insn.address == va else " "
            print(f"{mark} {insn.address:08x}  {raw:24}  {insn.mnemonic:8} {insn.op_str}")
            cursor += insn.size
    return 0


if __name__ == "__main__":
    raise SystemExit(main(sys.argv))
