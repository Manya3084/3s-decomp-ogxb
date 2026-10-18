# Gather what a hand port of one PS2-copy file needs.
# Usage: portinfo.py Game/EFF90.c
import os as _os, sys as _sys
_sys.path.insert(0, _os.path.dirname(_os.path.abspath(__file__)))
from ps2paths import OG as _OG, SP as _SP, PS as _PS
import sys, re, os, collections
OG = _OG; PS = _PS
sys.path.insert(0, OG + "/tools")
import pathlib
sys.path.insert(0, OG + "/analysis-ps2map")
import notefix
from ogxb.xbe import load
from ogxb.cap import Disassembler
img = load(pathlib.Path(open(OG + "/xbe.path").read().strip()))
rel = sys.argv[1]
path = f"{OG}/src/sf33rd/Source/{rel}"
t = open(path).read()
hdr = t.split(" */", 1)[0]
items = [(m[1], int(m[2], 16), int(m[3], 16)) for m in re.finditer(r"^ \* (\w+) 0x([0-9A-F]+) size 0x([0-9A-F]+)\.$", hdr, re.M)]
folded = re.findall(r"^ \* (\w+ is folded into 0x[0-9A-F]+.*)$", hdr, re.M)
xn = {}
for l in open(OG + "/config/sf33rd/symbols/funcs.txt"):
    m = re.match(r"(\S+)\s*=\s*(0x[0-9A-Fa-f]+);", l)
    if m: xn[int(m[2], 16)] = m[1]
# data names recorded in hand ports: "NAME is 0xADDR"
dnames = {}
for root, _, fs in os.walk(OG + "/src"):
    for f in fs:
        s = notefix.fix(open(os.path.join(root, f), errors="replace").read(20000))
        if "not hand-adjusted" in s[:3000]: continue
        for m in re.finditer(r"\b([A-Za-z_]\w*(?:\[[^\]]*\])?(?:\.\w+)*) is (?:the (?:word|dword|byte|float|table) at )?(0x[0-9A-F]{5,})", s):
            dnames.setdefault(int(m[2], 16), m[1])
for l in open(OG + "/config/sf33rd/symbols/data.txt"):
    m = re.match(r"(\S+) = (0x[0-9A-Fa-f]+); // type:data", l)
    if m: dnames.setdefault(int(m[2], 16), m[1])
body = t.split(" */", 1)[1]
def cfunc(name):
    m = re.search(r"^[A-Za-z_][\w\s\*]*\b" + re.escape(name) + r"\s*\([^;{]*\)\s*\{", body, re.M)
    if not m: return "(no C body)"
    i = m.start(); d = 0
    for j in range(m.end() - 1, len(body)):
        if body[j] == "{": d += 1
        elif body[j] == "}":
            d -= 1
            if d == 0: return body[i:j + 1]
used = collections.Counter()
with Disassembler() as dis:
    for n, va, sz in items:
        print(f"===== {n} 0x{va:X} size 0x{sz:X}")
        print(cfunc(n))
        print("----- x86")
        for i in dis.disasm(img.bytes_at(va, sz), va):
            o = i.op_str
            for h in re.findall(r"0x[0-9a-f]+", o):
                v = int(h, 16)
                if v in xn and i.mnemonic in ("call", "jmp"): o = o.replace(h, f"{h} <{xn[v]}>")
                elif v >= 0x200000: used[v] += 1; o = o.replace(h, f"{h}" + (f" <{dnames[v]}>" if v in dnames else ""))
            print(f"  {i.address:08x}  {i.mnemonic:6} {o}")
print("===== data addresses")
for v, c in sorted(used.items()): print(f"  0x{v:X} x{c} {dnames.get(v, '?')}")
if folded: print("===== folded:", *folded, sep="\n  ")
