"""xboxkrnl ordinal names. The table is CC0, from nxdk."""

from __future__ import annotations

from pathlib import Path

_TABLE = Path(__file__).resolve().parents[1] / "data" / "xboxkrnl.txt"


def load_ordinals(path: Path = _TABLE) -> dict[int, tuple[str, int, str]]:
    names: dict[int, tuple[str, int, str]] = {}
    for line in path.read_text().splitlines():
        if not line or line.startswith("#"):
            continue
        ordinal_s, name, argbytes_s, convention = line.split("\t")
        names[int(ordinal_s)] = (name, int(argbytes_s), convention)
    return names
