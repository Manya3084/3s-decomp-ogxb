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


def follows_terminator(dis: Disassembler, blob: bytes, text_va: int, va: int) -> bool:
    """True when va begins after a ret, padding, or a jmp that ends on va.

    MSVC sometimes places the next function immediately after a tail jmp, with
    no int3. The scanner keeps the earlier start. The byte before va is then
    the last byte of that jmp, not C3/CC/90.
    """
    off = va - text_va
    if not (0 < off < len(blob)):
        return False
    if blob[off - 1] in (0xC3, 0xCC, 0x90):
        return True
    for back in range(2, 16):
        start = off - back
        if start < 0:
            break
        insns = dis.disasm(blob[start:off], text_va + start, 1)
        if (
            len(insns) == 1
            and insns[0].address == text_va + start
            and insns[0].size == back
            and insns[0].mnemonic in ("jmp", "ret")
        ):
            return True
    return False


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
    rows = named()
    on_start = []
    interior = []
    missed = []
    with Disassembler() as dis:
        starts = function_starts(blob, text.va, image.entry, dis)
        start_set = set(starts)
        for name, va in rows:
            off = va - text.va
            if va in start_set:
                on_start.append((name, va))
                continue
            # MSVC often emits the next function immediately after ret or a
            # tail jmp, with no int3. The scan keeps the earlier start. A name
            # there is still the real function when that boundary is a ret,
            # padding, or a jmp that ends on this address, and the address
            # itself disassembles.
            pre_ok = follows_terminator(dis, blob, text.va, va)
            insns = dis.disasm(blob[off : off + 32], va, 2) if 0 <= off < len(blob) else []
            if pre_ok and len(insns) >= 2 and insns[0].address == va:
                interior.append((name, va))
            else:
                missed.append((name, va))
    print(f"named {len(rows)}")
    print(f"on a scanned start {len(on_start)}")
    print(f"inside a scanned span {len(interior)}")
    print(f"scanned {len(starts)}")
    for name, va in interior:
        print(f"  interior {name} {va:#x}")
    for name, va in missed:
        print(f"  not code {name} {va:#x}")
    return 1 if missed else 0


if __name__ == "__main__":
    raise SystemExit(main())
