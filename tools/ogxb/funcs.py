"""Function starts in an MSVC x86 .text.

A start is one of:

- the image entry point
- the first byte of .text
- `push ebp; mov ebp, esp` when the byte before it is a ret, int3, or nop
- the first byte after a `ret` and one or more int3/nop padding bytes
- the first byte after a `ret imm16` when padding follows, or the address is 16-byte aligned

`size` elsewhere is the distance to the next start. A jump table between two
functions stays inside that size. The disassembler stops when the bytes stop
decoding, so the table is visible as trailing data.
"""

from __future__ import annotations

from ogxb.cap import Disassembler


def function_starts(text: bytes, text_va: int, entry: int, dis: Disassembler) -> list[int]:
    limit = len(text)
    candidates: set[int] = {0}
    entry_off = entry - text_va
    if 0 <= entry_off < limit:
        candidates.add(entry_off)

    def boundary_before(index: int) -> bool:
        if index <= 0:
            return True
        if text[index - 1] in (0xCC, 0xC3, 0x90):
            return True
        return index >= 3 and text[index - 3] == 0xC2

    cursor = 0
    while True:
        found = text.find(b"\x55\x8B\xEC", cursor)
        if found < 0:
            break
        if boundary_before(found):
            candidates.add(found)
        cursor = found + 1

    index = 0
    while index < limit - 1:
        if text[index] == 0xC3:
            nxt = index + 1
            pads = 0
            while nxt < limit and text[nxt] in (0xCC, 0x90):
                pads += 1
                nxt += 1
            if pads and nxt < limit and text[nxt] not in (0xCC, 0x90):
                candidates.add(nxt)
            index += 1
            continue
        if text[index] == 0xC2 and index + 3 <= limit:
            nxt = index + 3
            pads = 0
            while nxt < limit and text[nxt] in (0xCC, 0x90):
                pads += 1
                nxt += 1
            if nxt < limit and text[nxt] not in (0xCC, 0x90) and (pads or nxt % 16 == 0):
                candidates.add(nxt)
            index += 3
            continue
        index += 1

    starts: list[int] = []
    for off in sorted(candidates):
        if off < 0 or off >= limit or text[off] in (0xCC, 0x90):
            continue
        if len(dis.disasm(text[off : off + 32], text_va + off, 4)) >= 2:
            starts.append(text_va + off)
    return starts


def function_sizes(starts: list[int], text_va: int, text_size: int) -> list[tuple[int, int]]:
    end = text_va + text_size
    bounds = starts + [end]
    return [(start, bounds[index + 1] - start) for index, start in enumerate(starts)]


def containing(starts: list[int], va: int) -> int | None:
    if not starts or va < starts[0]:
        return None
    lo = 0
    hi = len(starts) - 1
    while lo < hi:
        mid = (lo + hi + 1) // 2
        if starts[mid] <= va:
            lo = mid
        else:
            hi = mid - 1
    return starts[lo]
