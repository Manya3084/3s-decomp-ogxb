#!/usr/bin/env python3
"""Replace a file's local copies of the shared game structs with structs.h.

Many generated files declare their own partial copy of WORK, WORK_Other,
PLW, BG and the rest: the fields the file uses, with byte-array padding
between them computed for the retail 32-bit layout. On a 32-bit build the
copy and include/structs.h agree; on a 64-bit build they do not, because
the shared struct has pointers before those fields, and one file writes a
field where another reads a different one.

For each file this removes every top-level struct typedef whose name
structs.h also defines, and includes structs.h instead. The change is kept
only when the file still compiles for i386 and its code and relocations
are byte-for-byte what they were (so the retail relink cannot change), and
it also compiles for x86-64. Otherwise the file is left as it was and
reported.

    python3 tools/unify_structs.py [--write] FILE...
"""

from __future__ import annotations

import argparse
import os
import re
import subprocess
import sys
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
CFLAGS = ["-std=gnu17", "-O1", "-fno-pic", "-fcommon", "-fno-stack-protector", "-w",
          "-Wno-incompatible-pointer-types", "-Wno-int-conversion", "-Wno-implicit-function-declaration",
          "-I" + str(ROOT / "include")]


def shared_names() -> set[str]:
    text = (ROOT / "include" / "structs.h").read_text(errors="replace")
    names = set(re.findall(r"^\}\s*([A-Za-z_]\w*)\s*;", text, re.M))
    names |= set(re.findall(r"^typedef\s+struct\s+\w*\s*\{", text, re.M) and [])
    return names


def strip_comments_keep(text: str) -> str:
    """the text with comments blanked (same length), for finding braces"""
    return re.sub(r"/\*.*?\*/|//[^\n]*", lambda m: re.sub(r"[^\n]", " ", m[0]), text, flags=re.S)


def local_typedefs(text: str, names: set[str]) -> list[tuple[int, int, str]]:
    """(start, end, name) of each top-level `typedef struct ... { } NAME;` with a shared name"""
    bare = strip_comments_keep(text)
    out = []
    for m in re.finditer(r"^typedef\s+(?:struct|union)\b[^{;]*\{", bare, re.M):
        depth = 0
        i = m.end() - 1
        while i < len(bare):
            if bare[i] == "{":
                depth += 1
            elif bare[i] == "}":
                depth -= 1
                if depth == 0:
                    break
            i += 1
        t = re.match(r"\}\s*([A-Za-z_]\w*)\s*;[ \t]*\n?", bare[i:])
        if t and t[1] in names:
            out.append((m.start(), i + t.end(), t[1]))
    return out


def compile_obj(src: Path, arch: str, out: str) -> bool:
    r = subprocess.run(["gcc", f"-m{arch}", *CFLAGS, "-c", str(src), "-o", out], capture_output=True, text=True)
    return r.returncode == 0


def code_of(obj: str) -> str:
    r = subprocess.run(["objdump", "-dr", "--no-show-raw-insn", obj], capture_output=True, text=True)
    lines = r.stdout.splitlines()
    return "\n".join(l for l in lines if not l.startswith(obj) and "file format" not in l)


def data_of(obj: str) -> str:
    r = subprocess.run(["objdump", "-s", "-j", ".data", "-j", ".rodata", obj], capture_output=True, text=True)
    return "\n".join(l for l in r.stdout.splitlines() if "file format" not in l)


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--write", action="store_true")
    ap.add_argument("files", nargs="+")
    a = ap.parse_args()
    names = shared_names()
    changed = kept = 0
    for f in a.files:
        path = Path(f)
        text = path.read_text(errors="surrogateescape")
        defs = local_typedefs(text, names)
        if not defs:
            continue
        new = text
        for start, end, _ in sorted(defs, reverse=True):
            new = new[:start] + new[end:]
        if not re.search(r'^#include\s+"structs\.h"', new, re.M):
            new = re.sub(r'^(#include\s+"types\.h"[^\n]*\n)', r'\1#include "structs.h"\n', new, count=1, flags=re.M)
            if '#include "structs.h"' not in new:
                new = '#include "structs.h"\n' + new
        with tempfile.TemporaryDirectory() as td:
            tmp = Path(td) / path.name
            tmp.write_text(new, errors="surrogateescape")
            orig = Path(td) / ("orig_" + path.name)
            orig.write_text(text, errors="surrogateescape")
            # compile both from the file's own directory so its includes resolve
            ok_old = compile_obj(path, "32", td + "/a.o")
            probe = path.parent / ("._unify_" + path.name)
            probe.write_text(new, errors="surrogateescape")
            try:
                ok_new = compile_obj(probe, "32", td + "/b.o")
                ok_64 = compile_obj(probe, "64", td + "/c.o") if ok_new else False
            finally:
                probe.unlink()
            why = None
            if not ok_old:
                why = "does not compile for i386 as it is"
            elif not ok_new:
                why = "no longer compiles for i386"
            elif not ok_64:
                why = "does not compile for x86-64"
            elif code_of(td + "/a.o") != code_of(td + "/b.o"):
                why = "i386 code changes"
            elif data_of(td + "/a.o") != data_of(td + "/b.o"):
                why = "i386 data changes"
        names_here = ", ".join(sorted({n for _, _, n in defs}))
        if why:
            print(f"{f}: kept its copies ({names_here}): {why}")
            kept += 1
            continue
        changed += 1
        print(f"{f}: uses structs.h for {names_here}")
        if a.write:
            path.write_text(new, errors="surrogateescape")
    print(f"{changed} files can use structs.h, {kept} kept", file=sys.stderr)
    return 0


if __name__ == "__main__":
    sys.exit(main())
