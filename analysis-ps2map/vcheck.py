# vcheck.py NAME=VA ... : the C of NAME (this tree, else the PS2 tree) next to
# the x86 at VA (extent as addat.py computes it), with callee names.
import os as _os, sys as _sys
_sys.path.insert(0, _os.path.dirname(_os.path.abspath(__file__)))
from ps2paths import OG as _OG, SP as _SP, PS as _PS
import sys, re, os, bisect, json
sys.path.insert(0, _SP)
from feat import cfg_extent, padded_end, pinfo, TEND, _dis, text, TVA
import portcheck as pc
OG = _OG; PS = (_PS + "/src")
FO = json.load(open(OG + "/analysis-ps2map/folded.json"))
names = {v: n for n, (v, s) in pc.xf.items()}
stops = sorted(set(names) | {int(k, 16) for k in FO})
def cbody(n):
    for root in (OG + "/src", PS):
        for r, _, fs in os.walk(root):
            for f in fs:
                if not f.endswith(".c"): continue
                s = open(os.path.join(r, f), errors="replace").read()
                m = re.search(r"^[A-Za-z_][\w \*]*\b" + re.escape(n) + r"\s*\([^;{]*\)\s*\{\n.*?^\}", s, re.M | re.S)
                if m and "INCLUDE_ASM" not in m[0]: return os.path.relpath(os.path.join(r, f), root), m[0]
    return None, "(no C)"
for a in sys.argv[1:]:
    n, v = a.split("="); v = int(v, 16)
    i = bisect.bisect_right(stops, v); nx = stops[i] if i < len(stops) else TEND
    sz = padded_end(cfg_extent(v, stops), nx) - v
    f, c = cbody(n)
    print(f"######## {n} 0x{v:X} size 0x{sz:X} ps2 0x{pinfo.get(n, (0, 0))[1]:X} [{f}]")
    print(c[:2500])
    print("---- x86")
    for ins in _dis.disasm(text[v - TVA: v - TVA + sz], v):
        o = ins.op_str
        for h in re.findall(r"0x[0-9a-f]+", o):
            if int(h, 16) in names: o = o.replace(h, h + "<" + names[int(h, 16)] + ">")
        print(f"  {ins.address:x} {ins.mnemonic} {o}")
