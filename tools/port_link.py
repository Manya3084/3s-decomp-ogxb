#!/usr/bin/env python3
"""Check what a port has to supply to link the tree's C.

Compiles every src/ file with the host gcc (-m32), and build/xbe_tables.c
when it exists (tools/xbe_tables.py), then lists every global the objects
reference and none defines, by kind:

  xdk       an XDK function or data name (config/sf33rd/symbols/xdk.txt),
            or a kernel import slot
  libc      the C runtime and compiler helpers
  fold      a sub_ADDR call to a folded body with C (tools/fold_aliases.py)
  live      a function of the Xbox Live code (0xF5000 to 0x12B000)
  sample    XDK sample code and STL instances (CXB*, XBUtil_*, ...)
  data      a global no object or table defines
  other     anything else

and any global two objects define. With -v each name is listed.

    python3 tools/port_link.py [-v] [-j N]
"""

from __future__ import annotations

import argparse
import json
import os
import re
import subprocess
import sys
import tempfile
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
SYM = ROOT / "config" / "sf33rd" / "symbols"
LIBC = set("""memset memcpy memmove memcmp strcpy strncpy strcat strncat strcmp strncmp strlen strchr
strrchr strstr sprintf vsprintf printf sscanf atoi atol abs sqrt sqrtf sin cos sinf cosf atan2 atan2f
fabs fabsf floor floorf ceil pow powf qsort rand srand malloc free mbstowcs wcscpy wcslen swprintf
_snprintf _vsnprintf lrintf fmod fmodf tan tanf log logf exp expf asin acos toupper tolower""".split())
SAMPLE = re.compile(r"^(CXB|XBUtil_|XBInput_|CXHV|_xbOnline|xb_vector|xb_list|xb_tree|xb_deque|xb_string_|xb_exception_|xb_Font_)")


def names(f: str) -> dict[str, int]:
    out: dict[str, int] = {}
    for line in (SYM / f).read_text(errors="replace").splitlines():
        m = re.match(r"(\S+) = 0x([0-9A-Fa-f]+);", line)
        if m:
            out.setdefault(m[1], int(m[2], 16))
    return out


def nm(obj: str) -> list[tuple[str, str]]:
    r = subprocess.run(["nm", obj], capture_output=True, text=True)
    out = []
    for line in r.stdout.splitlines():
        p = line.split()
        if len(p) == 2:
            out.append((p[0], p[1]))
        elif len(p) == 3:
            out.append((p[1], p[2]))
    return out


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("-v", action="store_true")
    ap.add_argument("-j", type=int, default=os.cpu_count() or 4)
    a = ap.parse_args()
    srcs = sorted(str(p) for p in (ROOT / "src").rglob("*.c"))
    tables = ROOT / "build" / "xbe_tables.c"
    if tables.is_file():
        srcs.append(str(tables))
    env = dict(os.environ)
    ps2 = (ROOT / "ps2.path").read_text().strip() if (ROOT / "ps2.path").is_file() else ""
    for z in (Path(ps2) / "zlib", Path(ps2).parent / "zlib"):
        if (z / "zlib.h").is_file():
            env["C_INCLUDE_PATH"] = str(z)  # zlib.h for the stock adler32.c
            break
    with tempfile.TemporaryDirectory() as td:
        def cc(i_src):
            i, src = i_src
            obj = os.path.join(td, f"{i}.o")
            r = subprocess.run(["gcc", "-m32", "-std=gnu17", "-O0", "-fno-pic", "-fcommon", "-fno-stack-protector",
                                "-w", "-Wno-incompatible-pointer-types", "-Wno-int-conversion",
                                "-Wno-implicit-function-declaration", "-I" + str(ROOT / "include"), "-c", src, "-o", obj],
                               capture_output=True, text=True, env=env)
            return src, obj if r.returncode == 0 else None
        with ThreadPoolExecutor(a.j) as pool:
            res = list(pool.map(cc, enumerate(srcs)))
        failed = [s for s, o in res if o is None]
        defined: dict[str, int] = {}
        undef: set[str] = set()
        for _, o in res:
            if o is None:
                continue
            for t, n in nm(o):
                if t in "TDRB":
                    defined[n] = defined.get(n, 0) + 1
                elif t == "C":
                    defined.setdefault(n, 0)
                elif t == "U":
                    undef.add(n)
    xdk = names("xdk.txt")
    fold = {}
    r = subprocess.run([sys.executable, str(ROOT / "tools" / "fold_aliases.py")], capture_output=True, text=True)
    for line in r.stdout.splitlines():
        p = line.split()
        if len(p) == 2:
            fold[p[0]] = p[1]
    # the kernel import slots, from the XBE when there is one
    thunks = (0, 0)
    try:
        sys.path.insert(0, str(ROOT / "tools"))
        from ogxb.paths import find_xbe
        from ogxb.xbe import load
        img = load(find_xbe())
        raw = Path(img.path).read_bytes()
        sec = next(x for x in img.sections if x.va <= img.thunk_va < x.va + x.virtual_size)
        end = img.thunk_va
        while raw[sec.raw + end - sec.va:sec.raw + end - sec.va + 4] != b"\0\0\0\0":
            end += 4
        thunks = (img.thunk_va, end)
    except Exception:
        pass
    kinds: dict[str, list[str]] = {}
    for n in sorted(undef - set(defined)):
        slot = re.fullmatch(r"D_([0-9A-F]{8})", n)
        if n in xdk or n.startswith(("_Interlocked", "Interlocked", "__WSA")) or (
                slot and thunks[0] <= int(slot[1], 16) < thunks[1]):
            k = "xdk"
        elif n in LIBC or n.startswith("__"):
            k = "libc"
        elif n in fold:
            k = "fold"
        elif (m := re.fullmatch(r"sub_([0-9A-F]{8})", n)):
            v = int(m[1], 16)
            k = "xdk" if v >= 0x181A00 else "live" if 0xF5000 <= v < 0x12B000 or v == 0x1219E else "other"
        elif SAMPLE.match(n):
            k = "sample"
        elif "live" in n.lower() or "online" in n.lower() or n.startswith(("xb_xlive", "xb_XLIVE", "xb_NetSync", "xb_WINSTR", "xb_SearchResult")):
            k = "live"
        elif re.fullmatch(r"D_[0-9A-F]{8}", n) or n in names("data.txt"):
            k = "data"
        else:
            k = "other"
        kinds.setdefault(k, []).append(n)
    dups = sorted(n for n, c in defined.items() if c > 1)
    print(f"{len(srcs)} files, {len(failed)} failed to compile" + (": " + " ".join(failed[:5]) if failed else ""))
    for k in ("xdk", "libc", "fold", "live", "sample", "data", "other"):
        v = kinds.get(k, [])
        print(f"{k:7} {len(v)}" + (": " + " ".join(v) if a.v and v else ""))
    print(f"defined twice {len(dups)}" + (": " + " ".join(dups) if dups else ""))
    return 1 if failed or dups else 0


if __name__ == "__main__":
    sys.exit(main())
