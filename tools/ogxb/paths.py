"""Locate the retail XBE and the shader directory without copying them into git."""

from __future__ import annotations

import os
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
BUILD = ROOT / "build" / "sf33rd"


def find_xbe() -> Path | None:
    env = os.environ.get("SF33RD_XBE")
    if env:
        return Path(env)
    pointer = ROOT / "xbe.path"
    if pointer.is_file():
        line = pointer.read_text().strip()
        if line:
            return Path(line)
    return None


def find_shaders() -> Path | None:
    env = os.environ.get("SF33RD_SHADERS")
    if env:
        return Path(env)
    xbe = find_xbe()
    if xbe is None:
        return None
    shaders = xbe.parent / "media" / "Shaders"
    if shaders.is_dir():
        return shaders
    return None
