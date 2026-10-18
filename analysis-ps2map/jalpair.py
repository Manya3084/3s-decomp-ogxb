# jalpair.py : like strictpair.py, but pairs a named caller's x86 calls with
# the jal targets of its PS2 retail body (for asm-only PS2 code, e.g. CRI).
import os as _os, sys as _sys
_sys.path.insert(0, _os.path.dirname(_os.path.abspath(__file__)))
from ps2paths import OG as _OG, SP as _SP, PS as _PS
import sys, re, collections, json
sys.path.insert(0, _SP)
from feat import _dis, text, TVA, PW, pinfo, prows
import portcheck as pc
names = {v: n for n, (v, s) in pc.xf.items()}
byaddr = {a: n for n, a, s in prows}
FO = json.load(open((_SP + "/folded.json")))
fold_of = {n: int(k, 16) for k, v in FO.items() for n in v}
CRT = {0x175BFC, 0x175B40, 0x1764D2}
lo, hi = [int(x, 16) for x in sys.argv[1:3]] if len(sys.argv) > 2 else (0, 0x200000)
props = collections.defaultdict(collections.Counter)
for n, (va, sz) in pc.xf.items():
    if not (lo <= va < hi) or n not in pinfo: continue
    a, s = pinfo[n]; js = []
    for x in range(a, a + s, 4):
        w = PW(x); op = w >> 26
        if op in (2, 3):
            t = (w & 0x3FFFFFF) << 2
            if op == 2 and t in range(a, a + s): continue
            if t in byaddr: js.append(byaddr[t])
    xs = []
    for i in _dis.disasm(text[va - TVA: va - TVA + sz], va):
        if i.mnemonic in ("call", "jmp") and re.fullmatch(r"0x[0-9a-f]+", i.op_str):
            t = int(i.op_str, 16)
            if va <= t < va + sz or t in CRT: continue
            if i.mnemonic == "jmp" and t not in names and not (0x11000 <= t < 0x180000): continue
            xs.append(t)
    if len(xs) != len(js) or not xs: continue
    ok = True; pend = []
    for t, c in zip(xs, js):
        if t in names:
            if names[t] != c and fold_of.get(c) != t: ok = False; break
        elif fold_of.get(c) == t: continue
        elif c in pc.xf or c in fold_of: ok = False; break
        else: pend.append((t, c))
    if ok:
        for t, c in pend: props[t][c] += 1
for t, c in sorted(props.items()):
    print(f"{list(c)[0]}=0x{t:x}" if len(c) == 1 else f"CONFLICT {hex(t)} {dict(c)}", sum(c.values()))
