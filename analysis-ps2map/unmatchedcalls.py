# unmatchedcalls.py : ported functions whose x86 calls an unnamed, non-fold,
# non-CRT target while every callee in their C has an XBE name or fold, so
# the call cannot be one of the C's: an Xbox-only call.
import os as _os, sys as _sys
_sys.path.insert(0, _os.path.dirname(_os.path.abspath(__file__)))
from ps2paths import OG as _OG, SP as _SP, PS as _PS
import sys, re, os, json
sys.path.insert(0, _SP)
from feat import _dis, text, TVA
import portcheck as pc
OG = _OG
FO = json.load(open(OG + "/analysis-ps2map/folded.json"))
folds = {int(k, 16) for k in FO}; foldnames = {n for v in FO.values() for n in v}
names = {v: n for n, (v, s) in pc.xf.items()}
CRT = {0x175BFC, 0x175B40, 0x1764D2, 0x175C0B, 0x175B9E}
KW = {"if", "for", "while", "switch", "return", "sizeof", "defined"}
for r, _, fs in os.walk(OG + "/src/sf33rd/Source/Game"):
    for f in sorted(fs):
        s = open(os.path.join(r, f), errors="replace").read()
        if "Ported from the PS2" not in s[:4000]: continue
        hdr, body = s.split(" */", 1)
        live = body.split("\n#if 0\n/* PS2 C for functions not located")[0]
        hflat = re.sub(r"\n \* ", " ", hdr)
        for m in re.finditer(r"^[A-Za-z_][\w \*]*?\b(\w+)\([^;{]*\) \{\n(.*?)^\}", live, re.M | re.S):
            n, b = m[1], m[2]
            if n not in pc.xf: continue
            if re.search(re.escape(n) + r" 0x[0-9A-F]+ size 0x[0-9A-F]+\. Read against the x86: [^.]*Xbox", hflat): continue
            b = re.sub(r"/\*.*?\*/|//[^\n]*|\"(?:\\.|[^\"])*\"", "", b, flags=re.S)
            cc = {x for x in re.findall(r"\b([A-Za-z_]\w*)\s*\(", b) if x not in KW}
            unresolved = [c for c in cc if c not in pc.xf and c not in foldnames and not c.startswith("sub_")]
            subs = {int(c[4:], 16) for c in cc if re.fullmatch(r"sub_[0-9A-F]{8}", c)}
            va, sz = pc.xf[n]; extra = set()
            for i in _dis.disasm(text[va - TVA: va - TVA + sz], va):
                if i.mnemonic in ("call", "jmp") and re.fullmatch(r"0x[0-9a-f]+", i.op_str):
                    t = int(i.op_str, 16)
                    if va <= t < va + sz or t in CRT or t in names or t in folds or t in subs: continue
                    if i.mnemonic == "jmp" and not (0x11000 <= t < 0x200000): continue
                    extra.add(hex(t))
            if extra and not unresolved: print(f"{f} {n}: {sorted(extra)}")
