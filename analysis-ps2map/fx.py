# fx.py NAME... : x86 of named XBE functions with callee and data names.
import os as _os, sys as _sys
_sys.path.insert(0, _os.path.dirname(_os.path.abspath(__file__)))
from ps2paths import OG as _OG, SP as _SP, PS as _PS
import sys, re, pathlib
sys.path.insert(0, _SP)
import portcheck as pc
from feat import _dis, text, TVA
for n in sys.argv[1:]:
    # NAME, or ADDR:SIZE for an unnamed body
    va, sz = pc.xf[n] if ":" not in n else (int(n.split(":")[0], 16), int(n.split(":")[1], 16)); print(f"== {n} 0x{va:X} 0x{sz:X}")
    for i in _dis.disasm(text[va - TVA: va - TVA + sz], va):
        o = i.op_str
        for h in re.findall(r"0x[0-9a-f]+", o):
            v = int(h, 16)
            if v in pc.xa: o = o.replace(h, f"{h}<{pc.xa[v]}>")
            elif v >= 0x218DC0:
                s = pc.xsym(v)
                if s: o = o.replace(h, f"{h}<{s}>")
        print(f"  {i.address:x} {i.mnemonic} {o}")
