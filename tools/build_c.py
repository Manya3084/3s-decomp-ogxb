#!/usr/bin/env python3
"""Compile src/ with the XDK 5849 compiler (vc71 CL.Exe under Wine).

Objects go to build/obj/<path under src>.obj, and build/compile.json records
each file's result. The flags are Capcom's (see docs/relink.md). The XDK is
not part of this tree: point XDK at its root (the directory that holds
xbox/bin/vc71), or put that path in a one-line xdk.path.

    python3 tools/build_c.py [-j N] [--force] [FILE ...]
"""

from __future__ import annotations

import argparse
import json
import os
import re
import subprocess
import sys
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))

from ogxb.paths import ROOT

COMMON = ["/nologo", "/c"]
# Flags per source tree, longest prefix first. Chosen by how many functions
# each set compiles to the retail bytes (docs/relink.md).
FLAGS = [
    ("src/cri/", ["/O2", "/Gy"]),
    ("src/", ["/O1", "/arch:SSE", "/Op", "/Gy", "/GS"]),
]


def flags_for(src: Path) -> list[str]:
    rel = src.relative_to(ROOT).as_posix()
    return next(f for prefix, f in FLAGS if rel.startswith(prefix))
SRC = ROOT / "src"
OBJ = ROOT / "build" / "obj"
LOG = ROOT / "build" / "compile.json"
PREP = ROOT / "build" / "prep"


def find_xdk() -> Path | None:
    env = os.environ.get("XDK")
    if env:
        return Path(env)
    pointer = ROOT / "xdk.path"
    if pointer.is_file() and pointer.read_text().strip():
        return Path(pointer.read_text().strip())
    return None


def wine_path(p: Path) -> str:
    return "Z:" + str(p.resolve()).replace("/", "\\")


def find_ps2() -> Path | None:
    env = os.environ.get("SF33RD_PS2")
    if env:
        return Path(env)
    pointer = ROOT / "ps2.path"
    if pointer.is_file() and pointer.read_text().strip():
        return Path(pointer.read_text().strip())
    return None


QUALIFIERS = {"const", "volatile", "struct", "union", "enum", "unsigned", "signed", "register"}
DEFINITION = re.compile(r"^([A-Za-z_][^\n;=()]*?\b\w+\s*)\(([^()]*)\)(\s*\{)", re.M)
STATIC_PROTO = re.compile(r"^static\s+([^;(){}=]*?\b(\w+))\s*\(([^;{}]*)\)\s*;", re.M)


def name_params(params: str, count: list[int]) -> str:
    out = []
    for p in params.split(","):
        bare = re.sub(r"/\*.*?\*/", "", p).strip()
        idents = [w for w in re.findall(r"[A-Za-z_]\w*", bare) if w not in QUALIFIERS]
        if bare and bare != "void" and bare != "..." and len(idents) == 1 and "(" not in bare and "[" not in bare:
            count[0] += 1
            p = f"{bare} xb_unused{count[0]}"
        out.append(p)
    return ",".join(out)


STRUCT = re.compile(r"typedef struct\s*\w*\s*\{([^{}]*)\}\s*\w+\s*;")
GROUP = re.compile(r"\{(\s*\.\w+\s*=[^{}]*)\}")


def strip_designators(text: str, count: list[int]) -> str:
    """C89 has no designated initializers. A brace group whose designators
    name a struct's fields in declaration order, with none skipped, means the
    same thing positionally, so its designators are dropped. Any other group
    is left alone and fails to compile."""
    orders = []
    for body in STRUCT.findall(text):
        fields = [re.findall(r"(\w+)\s*(?:\[[^\]]*\])?\s*$", d.strip())
                  for d in re.sub(r"//[^\n]*|/\*.*?\*/", "", body, flags=re.S).split(";") if d.strip()]
        orders.append([f[0] for f in fields if f])

    def fix(m: re.Match) -> str:
        names = re.findall(r"\.(\w+)\s*=", m.group(1))
        if not any(o[:len(names)] == names for o in orders):
            return m.group(0)
        count[0] += 1
        return "{" + re.sub(r"\.\w+\s*=\s*", "", m.group(1)) + "}"

    return GROUP.sub(fix, text)


def prepare(src: Path) -> Path:
    """Return the file to hand to CL. Two PS2-tree habits are C99 or C++ and
    VC7.1's C89 rejects them, so a prepared copy fixes them:
      - a parameter with no name (`s32 /* unused */`, `DADD*`) gets one;
      - a static prototype whose body is not in the file (it sits under
        #if 0) loses `static`, so the call is an external reference;
      - designated initializers in struct order become positional.
    The #line keeps diagnostics on the original file."""
    text = src.read_text(errors="replace")
    count = [0]
    fixed = DEFINITION.sub(lambda m: m.group(1) + "(" + name_params(m.group(2), count) + ")" + m.group(3), text)
    live = re.sub(r"^#if 0\b.*?^#endif\b", "", fixed, flags=re.M | re.S)

    def unstatic(m: re.Match) -> str:
        if re.search(r"^[^;\n]*\b" + m.group(2) + r"\s*\([^;]*\)\s*\{", live, re.M):
            return m.group(0)
        count[0] += 1
        return m.group(0)[len("static"):].lstrip()

    fixed = STATIC_PROTO.sub(unstatic, fixed)
    fixed = strip_designators(fixed, count)
    if not count[0]:
        return src
    out = PREP / src.relative_to(SRC)
    out.parent.mkdir(parents=True, exist_ok=True)
    out.write_text(f'#line 1 "{src}"\n' + fixed)
    return out


def obj_for(src: Path) -> Path:
    return OBJ / src.relative_to(SRC).with_suffix(".obj")


def compile_one(cl: Path, env: dict, src: Path, force: bool, newest_header: float) -> tuple[str, dict]:
    obj = obj_for(src)
    rel = str(src.relative_to(ROOT))
    if not force and obj.is_file() and obj.stat().st_mtime >= max(src.stat().st_mtime, newest_header):
        return rel, {"ok": True, "cached": True}
    obj.parent.mkdir(parents=True, exist_ok=True)
    if obj.exists():
        obj.unlink()
    cmd = ["wine", str(cl), *COMMON, *flags_for(src), "/Fo" + wine_path(obj), wine_path(prepare(src))]
    r = subprocess.run(cmd, env=env, capture_output=True, text=True, errors="replace")
    lines = [l.strip() for l in (r.stdout + r.stderr).splitlines()]
    msgs = [l for l in lines if ": error " in l or ": warning " in l or "fatal error" in l]
    ok = r.returncode == 0 and obj.is_file()
    return rel, {"ok": ok, "errors": [m for m in msgs if "error" in m][:20], "warnings": len([m for m in msgs if "warning" in m])}


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("-j", type=int, default=min(16, os.cpu_count() or 4))
    ap.add_argument("--force", action="store_true")
    ap.add_argument("files", nargs="*")
    a = ap.parse_args()
    xdk = find_xdk()
    if xdk is None or not (xdk / "xbox" / "bin" / "vc71" / "CL.Exe").is_file():
        print("XDK not found: set XDK or write its root to xdk.path", file=sys.stderr)
        return 2
    cl = xdk / "xbox" / "bin" / "vc71" / "CL.Exe"
    inc = [ROOT / "include", ROOT / "include" / "msvc", xdk / "xbox" / "include"]
    ps2 = find_ps2()
    for z in ([ps2 / "zlib", ps2.parent / "zlib"] if ps2 is not None else []):
        if (z / "zlib.h").is_file():
            inc.append(z)  # zlib.h for the stock adler32.c
            break
    env = dict(os.environ, WINEDEBUG="-all", INCLUDE=";".join(wine_path(p) for p in inc))
    files = [Path(f).resolve() for f in a.files] if a.files else sorted(SRC.rglob("*.c"))
    newest_header = max((h.stat().st_mtime for h in (ROOT / "include").rglob("*.h")), default=0)
    results = json.loads(LOG.read_text()) if LOG.is_file() else {}
    with ThreadPoolExecutor(a.j) as pool:
        for rel, res in pool.map(lambda s: compile_one(cl, env, s, a.force, newest_header), files):
            if res.get("cached") and rel in results:
                continue
            results[rel] = res
            if not res["ok"]:
                print(f"FAIL {rel}: {res['errors'][0] if res['errors'] else 'no object'}")
    LOG.parent.mkdir(parents=True, exist_ok=True)
    LOG.write_text(json.dumps(results, indent=1, sort_keys=True))
    ok = sum(1 for r in results.values() if r["ok"])
    print(f"compiled {ok} of {len(results)} files")
    return 0 if ok == len(results) else 1


if __name__ == "__main__":
    sys.exit(main())
