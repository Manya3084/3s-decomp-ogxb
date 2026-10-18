# extracalls.py : functions in ported files whose x86 makes more direct calls
# than their C has call sites (inlining and tail merging only lower the x86
# count, so a surplus suggests Xbox-only calls). CRT helpers are ignored.
import os as _os, sys as _sys
_sys.path.insert(0, _os.path.dirname(_os.path.abspath(__file__)))
from ps2paths import OG as _OG, SP as _SP, PS as _PS
import sys, re, os, collections
sys.path.insert(0, _SP)
from feat import _dis, text, TVA
import portcheck as pc
OG = _OG
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
            if re.search(re.escape(n) + r" 0x[0-9A-F]+ size 0x[0-9A-F]+\. Read against the x86: [^.]*(?:rewritten for Xbox|Xbox)", hflat): continue
            b = re.sub(r"/\*.*?\*/|//[^\n]*|\"(?:\\.|[^\"])*\"", "", b, flags=re.S)
            cc = [x for x in re.findall(r"\b([A-Za-z_]\w*)\s*\(", b) if x not in KW and not x.isupper()]
            va, sz = pc.xf[n]; xc = []
            for i in _dis.disasm(text[va - TVA: va - TVA + sz], va):
                if i.mnemonic in ("call", "jmp") and re.fullmatch(r"0x[0-9a-f]+", i.op_str):
                    t = int(i.op_str, 16)
                    if va <= t < va + sz or t in CRT: continue
                    if i.mnemonic == "jmp" and t not in names and not (0x11000 <= t < 0x190000): continue
                    if i.mnemonic == "jmp" and t not in names: continue
                    xc.append(names.get(t, hex(t)))
                elif i.mnemonic == "call" and i.op_str.startswith(("dword ptr [e", "e")): xc.append("(indirect)")
            if len(xc) > len(cc):
                extra = collections.Counter(xc) - collections.Counter(names.get(pc.xf.get(c, (0,))[0], c) for c in cc)
                print(f"{f} {n}: x86 {len(xc)} C {len(cc)} extra {dict(extra)}")
