# Add "folded into" notes to PS2-copy headers for folded functions not yet noted.
import os as _os, sys as _sys
_sys.path.insert(0, _os.path.dirname(_os.path.abspath(__file__)))
from ps2paths import OG as _OG, SP as _SP, PS as _PS
import json, re, os, collections
OG = _OG; D = OG + "/analysis-ps2map/"
F = {int(k, 16): v for k, v in json.load(open(D + "folded.json")).items()}
pf = json.load(open(D + "xprop2.json"))["pfile"]
named = {l.split(" = ")[0] for l in open(OG + "/config/sf33rd/symbols/funcs.txt") if " = " in l}
byfile = collections.defaultdict(list)
for a, ns in F.items():
    for n in ns:
        if n not in named and n in pf: byfile[pf[n]].append((a, n, len(ns)))
added = 0
for rel, items in byfile.items():
    p = f"{OG}/src/{rel}"
    if not os.path.exists(p): continue
    t = open(p).read()
    if " * PlayStation 2 C, not hand-adjusted for Xbox." not in t[:3000]: continue
    anchor = " * The other functions in this file are not located in sf33rd.xbe yet.\n"
    if anchor not in t: continue
    new = [f" * {n} is folded into 0x{a:X} with {k - 1} other bodies. Unnamed." for a, n, k in sorted(items, key=lambda x: x[1]) if f" * {n} is folded into" not in t]
    if new: t = t.replace(anchor, "\n".join(new) + "\n" + anchor, 1); open(p, "w").write(t); added += len(new)
print("folded notes added", added)
