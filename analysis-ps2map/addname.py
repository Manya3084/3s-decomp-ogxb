# addname.py NAME VA SIZE : add a funcs.txt row and a matched_bytes entry
import os as _os, sys as _sys
_sys.path.insert(0, _os.path.dirname(_os.path.abspath(__file__)))
from ps2paths import OG as _OG, SP as _SP, PS as _PS
import sys, re, pathlib
OG = _OG
sys.path.insert(0, OG + "/tools")
from ogxb.xbe import load
from ogxb.cap import Disassembler
img = load(pathlib.Path(open(OG + "/xbe.path").read().strip()))
n, va, sz = sys.argv[1], int(sys.argv[2], 16), int(sys.argv[3], 16)
fp = OG + "/config/sf33rd/symbols/funcs.txt"; f = open(fp).read()
assert not re.search(rf"^{n} = ", f, re.M), "name exists"
blob = img.bytes_at(va, sz); im = []
with Disassembler() as d:
    for i in d.disasm(blob, va):
        if i.mnemonic == "call" or i.mnemonic.startswith("j"): continue
        for h in re.findall(r"0x[0-9a-f]+", i.op_str):
            v = int(h, 16)
            if 0x11000 <= v < 0xD20000 and v.to_bytes(4, "little") in blob and v not in im: im.append(v)
open(fp, "a").write(f"{n} = 0x{va:08X}; // type:func size:0x{sz:X}\n")
mp = OG + "/tests/matched_bytes.py"; t = open(mp).read().rstrip()
t = t[:-1].rstrip() + "\n" + f'    ("{n}", 0x{va:08X}, 0x{sz:X}, ({"".join(f"0x{x:X}," for x in im)}),\n     "{blob.hex()}"),' + "\n)\n"
open(mp, "w").write(t); print("added", n)
