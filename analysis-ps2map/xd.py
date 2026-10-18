import os as _os, sys as _sys
_sys.path.insert(0, _os.path.dirname(_os.path.abspath(__file__)))
from ps2paths import OG as _OG, SP as _SP, PS as _PS
import sys, pathlib
sys.path.insert(0, (_OG + "/tools"))
from ogxb.xbe import load
from ogxb.cap import Disassembler
img = load(pathlib.Path(open((_OG + "/xbe.path")).read().strip()))
va = int(sys.argv[1], 16); size = int(sys.argv[2], 16)
with Disassembler() as d:
    for i in d.disasm(img.bytes_at(va, size), va):
        print(f"{i.address:08x}  {i.mnemonic:6} {i.op_str}")
