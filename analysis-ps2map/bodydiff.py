# bodydiff.py Game/X.c... : functions whose body in HEAD differs from the
# working copy beyond sub_ADDR -> name renames (lost hand edits after regen).
import os as _os, sys as _sys
_sys.path.insert(0, _os.path.dirname(_os.path.abspath(__file__)))
from ps2paths import OG as _OG, SP as _SP, PS as _PS
import sys, re, subprocess
OG = _OG
xa = {}
for l in open(OG + "/config/sf33rd/symbols/funcs.txt"):
    m = re.match(r"(\S+)\s*=\s*0x([0-9A-Fa-f]+);", l)
    if m: xa["sub_%08X" % int(m[2], 16)] = m[1]
def bodies(t):
    t = t.split(" */", 1)[1] if " */" in t else t
    out = {}
    for m in re.finditer(r"^[A-Za-z_][\w \*]*?\b(\w+)\s*\([^;{]*\)\s*\{", t, re.M):
        d = 0
        for j in range(m.end() - 1, len(t)):
            if t[j] == "{": d += 1
            elif t[j] == "}":
                d -= 1
                if d == 0: break
        b = t[m.start():j + 1]
        b = re.sub(r"\bsub_[0-9A-F]{8}\b", lambda x: xa.get(x[0], x[0]), b)
        out.setdefault(m[1], []).append(re.sub(r"\s+", " ", b))
    return out
import difflib
SHOW = "--show" in sys.argv
for rel in [a for a in sys.argv[1:] if a != "--show"]:
    p = f"src/sf33rd/Source/{rel}"
    old = subprocess.run(["git", "-C", OG, "show", "HEAD:" + p], capture_output=True, text=True).stdout
    new = open(f"{OG}/{p}").read()
    bo, bn = bodies(old), bodies(new)
    for n, L in bo.items():
        if n in bn and L != bn[n]:
            print(rel, "CHANGED", n)
            if SHOW:
                a = L[0].replace("; ", ";\n").split("\n"); b = bn[n][0].replace("; ", ";\n").split("\n")
                for l in difflib.unified_diff(a, b, lineterm="", n=0):
                    if l[:1] in "+-" and l[:3] not in ("+++", "---"): print("    ", l[:170])
        elif n not in bn: print(rel, "GONE", n)
