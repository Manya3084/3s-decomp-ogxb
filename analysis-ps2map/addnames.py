# addnames.py FILE : add funcs.txt rows and matched_bytes entries for each
# "NAME VAHEX SIZEHEX" line in FILE (same as addname.py, batched).
import os as _os, sys as _sys
_sys.path.insert(0, _os.path.dirname(_os.path.abspath(__file__)))
from ps2paths import OG as _OG, SP as _SP, PS as _PS
import sys, re, pathlib
OG = _OG
sys.path.insert(0, OG + "/tools")
from ogxb.xbe import load
from ogxb.cap import Disassembler
img = load(pathlib.Path(open(OG + "/xbe.path").read().strip()))
fp = OG + "/config/sf33rd/symbols/funcs.txt"; f = open(fp).read()
mp = OG + "/tests/matched_bytes.py"; t = open(mp).read().rstrip()
assert t.endswith(")"); t = t[:-1].rstrip()
rows = []; ents = []
with Disassembler() as d:
    for line in open(sys.argv[1]):
        n, va, sz = line.split(); va = int(va, 16); sz = int(sz, 16)
        assert not re.search(rf"^{n} = ", f, re.M), n
        blob = img.bytes_at(va, sz); im = []
        for i in d.disasm(blob, va):
            if i.mnemonic == "call" or i.mnemonic.startswith("j"): continue
            for h in re.findall(r"0x[0-9a-f]+", i.op_str):
                v = int(h, 16)
                if 0x11000 <= v < 0xD20000 and v.to_bytes(4, "little") in blob and v not in im: im.append(v)
        rows.append(f"{n} = 0x{va:08X}; // type:func size:0x{sz:X}\n")
        ents.append(f'    ("{n}", 0x{va:08X}, 0x{sz:X}, ({"".join(f"0x{x:X}," for x in im)}),\n     "{blob.hex()}"),')
open(fp, "a").write("".join(rows))
open(mp, "w").write(t + "\n" + "\n".join(ents) + "\n)\n")
print("added", len(rows))
