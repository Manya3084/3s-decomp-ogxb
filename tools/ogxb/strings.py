"""C strings and the push/mov immediates that name functions."""

from __future__ import annotations


def c_strings(blob: bytes, va: int, min_len: int = 6) -> list[tuple[int, str]]:
    found: list[tuple[int, str]] = []
    index = 0
    limit = len(blob)
    while index < limit:
        byte = blob[index]
        if byte < 0x20 or byte > 0x7E or (index and blob[index - 1] != 0):
            index += 1
            continue
        end = index
        while end < limit and 0x20 <= blob[end] <= 0x7E:
            end += 1
        if end < limit and blob[end] == 0 and end - index >= min_len:
            found.append((va + index, blob[index:end].decode("ascii")))
        index = end + 1 if end > index else index + 1
    return found


def imm_sites(blob: bytes, blob_va: int) -> dict[int, list[tuple[int, str]]]:
    """Immediate values from `push imm32` and `mov r32, imm32`.

    The scan is a byte scan, so a hit still has to be read back in the disassembly
    before it is used as a name.
    """
    sites: dict[int, list[tuple[int, str]]] = {}
    index = 0
    limit = len(blob)
    while index < limit - 4:
        opcode = blob[index]
        if opcode == 0x68 and index + 5 <= limit:
            kind = "push"
            step = 5
        elif 0xB8 <= opcode <= 0xBF and index + 5 <= limit:
            kind = "mov"
            step = 5
        else:
            index += 1
            continue
        immediate = int.from_bytes(blob[index + 1 : index + 5], "little")
        sites.setdefault(immediate, []).append((blob_va + index, kind))
        index += step
    return sites
