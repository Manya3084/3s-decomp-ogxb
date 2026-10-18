# Merge newfold2.json into folded.json and unname bulk names on folded bodies.
import os as _os, sys as _sys
_sys.path.insert(0, _os.path.dirname(_os.path.abspath(__file__)))
from ps2paths import OG as _OG, SP as _SP, PS as _PS
import json, re, os, sys
OG = _OG; D = OG + "/analysis-ps2map/"
F = json.load(open(D + "folded.json"))
NF = json.load(open(D + "newfold2.json")) if os.path.exists(D + "newfold2.json") else {}
for k, v in NF.items(): F[k] = sorted(set(F.get(k, [])) | set(v))
json.dump(F, open(D + "folded.json", "w"))
hand = set(open(D + "handnames.txt").read().split())
cur = {}
for l in open(OG + "/config/sf33rd/symbols/funcs.txt"):
    m = re.match(r"(\S+)\s*=\s*(0x[0-9A-Fa-f]+);", l)
    if m: cur[int(m[2], 16)] = m[1]
U = [(int(k, 16), cur[int(k, 16)], v) for k, v in F.items() if int(k, 16) in cur and cur[int(k, 16)] not in hand]
fp = OG + "/config/sf33rd/symbols/funcs.txt"; f = open(fp).read()
mp = OG + "/tests/matched_bytes.py"; m = open(mp).read()
hdr = {}
for r, _, fs in os.walk(OG + "/src"):
    for x in fs:
        p = os.path.join(r, x); t = open(p, errors="replace").read()
        if " * PlayStation 2 C, not hand-adjusted for Xbox." in t[:3000]: hdr[p] = t
for a, n, ns in U:
    f, k = re.subn(rf"^{n} = 0x{a:08X}; // type:func size:0x[0-9A-F]+\n", "", f, flags=re.M); assert k == 1, n
    m, k = re.subn(rf'    \("{n}", 0x{a:08X}, 0x[0-9A-F]+, \([^)]*\),\n     "[0-9a-f]*"\),\n', "", m); assert k == 1, n
    for p, t in hdr.items():
        t2, k = re.subn(rf"^ \* {n} 0x{a:X} size 0x[0-9A-F]+\.$", f" * {n} is folded into 0x{a:X} with {len(ns) - 1} other bodies. Unnamed.", t, flags=re.M)
        if k: hdr[p] = t2
open(fp, "w").write(f); open(mp, "w").write(m)
for p, t in hdr.items(): open(p, "w").write(t)
print("unfolded", len(U))
