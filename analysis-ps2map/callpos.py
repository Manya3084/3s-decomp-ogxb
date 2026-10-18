# callpos.py ADDR... : for each named caller of ADDR, its C callee list (in
# source order) beside its x86 call sequence, to read the callee's name off.
import os as _os, sys as _sys
_sys.path.insert(0, _os.path.dirname(_os.path.abspath(__file__)))
from ps2paths import OG as _OG, SP as _SP, PS as _PS
import sys, re, os
sys.path.insert(0, _SP)
from feat import _dis, text, TVA
import portcheck as pc
OG = _OG; PS = (_PS + "/src")
names = {v: n for n, (v, s) in pc.xf.items()}
SKIP = {"if", "for", "while", "switch", "return", "sizeof"}
def cbody(n):
    for root in (OG + "/src", PS):
        for r, _, fs in os.walk(root):
            for f in fs:
                if not f.endswith(".c"): continue
                s = open(os.path.join(r, f), errors="replace").read()
                m = re.search(r"^[A-Za-z_][\w \*]*\b" + re.escape(n) + r"\s*\([^;{]*\)\s*\{\n.*?^\}", s, re.M | re.S)
                if m and "INCLUDE_ASM" not in m[0]: return m[0]
    return ""
for a in sys.argv[1:]:
    t = int(a, 16)
    for n, (va, sz) in sorted(pc.xf.items(), key=lambda x: x[1][0]):
        seq = []; hit = False
        for i in _dis.disasm(text[va - TVA: va - TVA + sz], va):
            if i.mnemonic in ("call", "jmp") and re.fullmatch(r"0x[0-9a-f]+", i.op_str):
                v = int(i.op_str, 16)
                if va <= v < va + sz: continue
                if v == t: hit = True
                seq.append("*" + hex(v) if v == t else names.get(v, hex(v)))
        if not hit: continue
        c = cbody(n)
        cc = [m for m in re.findall(r"\b([A-Za-z_]\w*)\s*\(", c.split("{", 1)[1] if "{" in c else "") if m not in SKIP]
        print(f"== {hex(t)} in {n}\n   x86: {' '.join(seq)}\n   C:   {' '.join(cc)}")
