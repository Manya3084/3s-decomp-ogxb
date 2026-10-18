# Unname bodies that are MSVC folds of byte-identical PS2 twins: a named body
# whose twin has no XBE address and whose twin's callers call that body.
# Records the fold in folded.json and in file headers, and switches hand
# ports to sub_ADDR for the folded name.
import os as _os, sys as _sys
_sys.path.insert(0, _os.path.dirname(_os.path.abspath(__file__)))
from ps2paths import OG as _OG, SP as _SP, PS as _PS
import sys, re, collections, json, os
sys.argv = ["x"]
SP = _SP; OG = _OG
src = open(SP + "/callalign.py").read(); exec(src[:src.index("accepted = {}")])
from feat import PW
def pmask(n):
    a, s = pinfo[n]; out = []
    for x in range(a, a + s, 4):
        w = PW(x); op = w >> 26
        if op in (2, 3):
            t_ = (w & 0x3FFFFFF) << 2
            out.append(("call", op, paddr.get(t_, t_ - a if a <= t_ < a + s else "?")))
        else: out.append(op << 26 if op == 0x0F else (w & 0xFFFF0000 if ((w >> 21) & 31) == 28 else w))
    while out and out[-1] == 0: out.pop()
    return tuple(out)
groups = collections.defaultdict(list)
for n in pinfo: groups[pmask(n)].append(n)
byname = {n: va for va, (n, s) in xf.items()}
pcallers = collections.defaultdict(set)
for va, sz, n in pairs:
    for c in PC[n]: pcallers[c].add(va)
unname = {}
for g in groups.values():
    named = [n for n in g if n in byname]
    if len(g) < 2 or len(named) != 1: continue
    x = byname[named[0]]
    tw = [w for w in g if w not in byname and any(x in XC[va][0] for va in pcallers.get(w, ()))]
    if tw: unname[named[0]] = (x, tw)
FO = json.load(open(SP + "/folded.json"))
# twins of members of an existing fold group, with no address of their own,
# whose callers call the group's body, join the group
join = 0
member = {n: int(k, 16) for k, L in FO.items() for n in L}
for g in groups.values():
    if len(g) < 2: continue
    xs = {member[n] for n in g if n in member}
    if len(xs) != 1: continue
    x = xs.pop()
    for w in g:
        if w in byname or w in member: continue
        if any(x in XC[va][0] for va in pcallers.get(w, ())):
            FO[hex(x)].append(w); join += 1
print("joined", join)
fp = OG + "/config/sf33rd/symbols/funcs.txt"
_rows = open(fp).readlines()
open(fp, "w").write("".join(l for l in _rows if l.split(" = ")[0] not in unname))
mp = OG + "/tests/matched_bytes.py"; mt = open(mp).read()
for n in unname: mt = re.sub(r'    \("' + re.escape(n) + r'", 0x[0-9A-F]+, .*?"\),\n', "", mt, flags=re.S)
open(mp, "w").write(mt)
allnames = {}
for n, (x, tw) in unname.items():
    L = FO.setdefault(hex(x), [])
    for m in [n] + tw:
        if m not in L: L.append(m)
        allnames[m] = x
json.dump(FO, open(SP + "/folded.json", "w"), indent=0)
for r, _, fs in os.walk(OG + "/src"):
    for f in fs:
        p = os.path.join(r, f); t = open(p, errors="replace").read(); o = t
        hdr, body = t.split(" */", 1) if " */" in t else (t, "")
        ph = "PlayStation 2 C, not hand-adjusted" in hdr
        for m, x in allnames.items():
            k = len(FO[hex(x)]) - 1
            defined = re.search(r"^[A-Za-z_][\w \*]*\b" + re.escape(m) + r"\s*\([^;]*\)\s*\{", body, re.M)
            # header address line -> fold note
            pat = r"\n \* " + re.escape(m) + r" (?:is )?0x[0-9A-F]+ size 0x[0-9A-F]+\.[^\n]*(?:\n \*  [^\n]*)*"
            if re.search(pat, hdr):
                hdr = re.sub(pat, f"\n * {m} is folded into 0x{x:X} with {k} other bodies. Unnamed.", hdr)
            elif defined and f" * {m} is folded" not in hdr:
                hdr += f"\n * {m} is folded into 0x{x:X} with {k} other bodies. Unnamed."
            if not ph:
                hdr = re.sub(r"\b" + re.escape(m) + r" is 0x" + f"{x:X}" + r"\b", f"{m} is folded into 0x{x:X}", hdr)
                if not defined:
                    body = re.sub(r"\b" + re.escape(m) + r"\b(?=\s*\()", f"sub_{x:08X}", body)
        t = hdr + (" */" + body if body else "")
        if t != o: open(p, "w").write(t)
print("unnamed", len(unname), sorted(unname))
