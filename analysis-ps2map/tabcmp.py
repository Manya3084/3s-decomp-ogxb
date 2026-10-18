# tabcmp.py FILE TABLE ADDR : compare a function-pointer initializer with the XBE.
import os as _os, sys as _sys
_sys.path.insert(0, _os.path.dirname(_os.path.abspath(__file__)))
from ps2paths import OG as _OG, SP as _SP, PS as _PS
import sys, re, struct, json
sys.path.insert(0, _SP)
import portcheck as pc
from feat import img
src = open(f"{_OG}/src/sf33rd/Source/{sys.argv[1]}").read()
m = re.search(re.escape(sys.argv[2]) + r"\s*\[[^\]]*\]\s*\)\s*\([^)]*\)\s*=\s*\{(.*?)\}", src, re.S)
names = re.findall(r"\b([A-Za-z_]\w*)\b", m[1])
a = int(sys.argv[3], 16)
for k, w in enumerate(names):
    v = struct.unpack("<I", img.bytes_at(a + 4 * k, 4))[0]
    x = pc.xa.get(v, "fold" if v in pc.folded else "?")
    if x != w: print(k, w, hex(v), x, "" if w not in pc.xf else f"(named 0x{pc.xf[w][0]:X})")
print(len(names), "entries; next dword", hex(struct.unpack("<I", img.bytes_at(a + 4 * len(names), 4))[0]))
