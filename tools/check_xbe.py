#!/usr/bin/env python3
"""Check the local sf33rd.xbe against the recorded retail image.

Exits 0 when the file is absent, so a checkout without the disc still passes.
A present file that is not this retail build fails.
"""

from __future__ import annotations

import hashlib
import shutil
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))

from ogxb.cap import Disassembler
from ogxb.funcs import containing, function_starts
from ogxb.krnl import load_ordinals
from ogxb.paths import find_shaders, find_xbe
from ogxb.spirv import combiner_spirv, validate_spirv, vertex_spirv
from ogxb.strings import c_strings, imm_sites
from ogxb.xbe import load
from ogxb.xpu import list_xpu
from ogxb.xvs import list_shaders

SHA256 = "a04b2e91d65096f438790c14c95cf17272ef50c345b7a071d703a79d2ee9f3d6"
SIZE = 4526080
ENTRY = 0x125FF7
TEXT_VA = 0x11000
TEXT_SIZE = 0x1709E4
TITLE = 0x4343000F
IMPORTS = 150
# Starts from the padded-ret / frame-pointer scan on this retail .text.
STARTS = 2393


def main() -> int:
    path = find_xbe()
    if path is None or not path.is_file():
        print("sf33rd.xbe absent; skip")
        return 0
    data = path.read_bytes()
    digest = hashlib.sha256(data).hexdigest()
    if len(data) != SIZE or digest != SHA256:
        print(f"unexpected xbe size {len(data)} sha256 {digest}", file=sys.stderr)
        return 1
    image = load(path)
    text, blob = image.text
    if image.title_id != TITLE or image.key_kind != "retail" or image.xdk_build != 5849:
        print("unexpected title, key, or XDK build", file=sys.stderr)
        return 1
    if image.entry != ENTRY or text.va != TEXT_VA or text.raw_size != TEXT_SIZE:
        print("unexpected entry or .text", file=sys.stderr)
        return 1
    if len(image.imports) != IMPORTS:
        print(f"unexpected import count {len(image.imports)}", file=sys.stderr)
        return 1
    names = load_ordinals()
    missing = [item.ordinal for item in image.imports if item.ordinal not in names]
    if missing:
        print(f"unnamed kernel ordinals {missing}", file=sys.stderr)
        return 1
    if not image.debug_path.endswith(r"sf33rd\Project\SF33rdACR for XBOX\Release\sf33rd.exe"):
        print(f"unexpected debug path {image.debug_path}", file=sys.stderr)
        return 1
    with Disassembler() as dis:
        starts = function_starts(blob, text.va, image.entry, dis)
    if len(starts) != STARTS or ENTRY not in starts:
        print(f"unexpected starts {len(starts)}", file=sys.stderr)
        return 1
    sites = imm_sites(blob, text.va)
    game = []
    for section in image.sections:
        if section.name != ".rdata":
            continue
        raw = image.data[section.raw : section.raw + section.raw_size]
        for va, literal in c_strings(raw, section.va):
            if literal.endswith(r"\sf33rd\Source\Game\Game.c"):
                game.append((va, sites.get(va, [])))
    if len(game) != 1 or len(game[0][1]) != 1 or game[0][1][0][1] != "push":
        print(f"Game.c xref {game}", file=sys.stderr)
        return 1
    owner = containing(starts, game[0][1][0][0])
    if owner is None:
        print("Game.c push is outside a function", file=sys.stderr)
        return 1
    shaders = find_shaders()
    if shaders is not None:
        programs, _other = list_shaders(shaders)
        if len(programs) != 490:
            print(f"unexpected xvu count {len(programs)}", file=sys.stderr)
            return 1
        combiners, bad_xpu = list_xpu(shaders)
        if len(combiners) != 2 or bad_xpu:
            print(f"unexpected xpu count {len(combiners)} bad {len(bad_xpu)}", file=sys.stderr)
            return 1
        if shutil.which("spirv-val") is None:
            print("spirv-val absent; shader modules skipped")
        else:
            for program in programs:
                module = vertex_spirv(program.path.read_bytes())
                if module is None or validate_spirv(module):
                    print(f"shader rejected {program.path.name}", file=sys.stderr)
                    return 1
            for path, _shader in combiners:
                module = combiner_spirv(path.read_bytes())
                if module is None or validate_spirv(module):
                    print(f"shader rejected {path.name}", file=sys.stderr)
                    return 1
    print(f"sf33rd.xbe ok  starts {len(starts)}  Game.c in {owner:#x}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
