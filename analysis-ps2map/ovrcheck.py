# ovrcheck.py : every function in overrides/<File>.c must appear verbatim
# (comments and spacing aside) in the generated Game/<File>.c.
import os as _os, sys as _sys
_sys.path.insert(0, _os.path.dirname(_os.path.abspath(__file__)))
from ps2paths import OG as _OG, SP as _SP, PS as _PS
import re, os
SP = _SP
src = open(SP + "/portgen.py").read()
s = src.index("def items_of"); e = src.index("\n", src.index("    return out", s))
g = {"re": re}; exec(src[s:e], g)
def fname(t):
    t = re.sub(r"/\*.*?\*/|//[^\n]*", "", t, flags=re.S)
    m = re.search(r"\b([A-Za-z_]\w*)\s*\([^;{]*\)\s*\{", t, re.S); return m[1] if m else None
import json
FO = json.load(open(SP + "/folded.json"))
FREN = {n: "sub_%08X" % int(a, 16) for a, ns in FO.items() for n in ns}
def fold_rename_calls(x):
    # rename calls (not the definition head) the way portgen does
    head, rest = x.split("{", 1)
    return head + "{" + re.sub(r"\b(\w+)(?=\s*\()", lambda m: FREN.get(m[1], m[1]), rest)
norm = lambda x: re.sub(r"\s+", " ", re.sub(r"/\*.*?\*/", "", x, flags=re.S)).strip()
bad = 0
for f in sorted(os.listdir(SP + "/overrides")):
    G = norm(open(f"{SP}/../src/sf33rd/Source/Game/{f}").read())
    for k, t in g["items_of"](open(SP + "/overrides/" + f).read()):
        if k != "func": continue
        n = fname(t); body = re.sub(r"^.*?(?=^[A-Za-z_][^\n]*\b" + n + r"\s*\()", "", t, flags=re.S | re.M)
        if norm(body) not in G and norm(fold_rename_calls(body)) not in G: print("MISSING", f, n); bad += 1
print("overrides checked;", bad, "missing")
