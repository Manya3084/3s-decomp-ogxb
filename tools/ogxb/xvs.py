"""Xbox vertex-program files (.xvu).

A file is a uint16 magic 0x2078, a uint16 instruction count, then count
16-byte NV2A transform instructions. This module checks that shape. It does
not decode the ISA.
"""

from __future__ import annotations

import struct
from dataclasses import dataclass
from pathlib import Path

XVS_MAGIC = 0x2078


@dataclass(frozen=True)
class Xvu:
    path: Path
    count: int

    @property
    def size(self) -> int:
        return 4 + self.count * 16


def parse_xvu(blob: bytes) -> int | None:
    if len(blob) < 4:
        return None
    magic, count = struct.unpack_from("<HH", blob, 0)
    if magic != XVS_MAGIC:
        return None
    if 4 + count * 16 != len(blob):
        return None
    return count


def list_shaders(directory: Path) -> tuple[list[Xvu], list[Path]]:
    programs: list[Xvu] = []
    other: list[Path] = []
    for path in sorted(directory.iterdir()):
        if not path.is_file():
            continue
        count = parse_xvu(path.read_bytes())
        if count is None:
            other.append(path)
        else:
            programs.append(Xvu(path, count))
    return programs, other
