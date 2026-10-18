# Count unnamed direct call targets across all named XBE bodies.
import os as _os, sys as _sys
_sys.path.insert(0, _os.path.dirname(_os.path.abspath(__file__)))
from ps2paths import OG as _OG, SP as _SP, PS as _PS
import sys, re, json, pathlib, collections
OG = _OG
sys.path.insert(0, OG + "/tools")
from ogxb.xbe import load
from ogxb.cap import Disassembler
img = load(pathlib.Path(open(OG + "/xbe.path").read().strip()))
fn = {}
for l in open(OG + "/config/sf33rd/symbols/funcs.txt"):
    m = re.match(r"(\S+)\s*=\s*(0x[0-9A-Fa-f]+);.*size:(0x[0-9A-Fa-f]+)", l)
    if m: fn[int(m[2], 16)] = (m[1], int(m[3], 16))
folded = json.load(open(OG + "/analysis-ps2map/folded.json"))
cnt = collections.Counter(); callers = collections.defaultdict(set)
with Disassembler() as d:
    for va, (n, sz) in fn.items():
        for i in d.disasm(img.bytes_at(va, sz), va):
            if i.mnemonic in ("call", "jmp") and re.fullmatch(r"0x[0-9a-f]+", i.op_str):
                t = int(i.op_str, 16)
                if t in fn or va <= t < va + sz: continue
                cnt[t] += 1; callers[t].add(n)
inside = lambda t: any(a < t < a + s for a, (_, s) in fn.items())
for t, c in cnt.most_common(int(sys.argv[1]) if len(sys.argv) > 1 else 60):
    print(f"0x{t:X} {c} {'FOLD' if hex(t) in folded else ''} {'INTERIOR' if inside(t) else ''} {sorted(callers[t])[:4]}")
print("unnamed targets", len(cnt), "calls", sum(cnt.values()))
