# strictpair.py : for each named caller whose x86 call list and C call list
# have the same length and agree at every named position (source order or,
# failing that, sorted case order is not tried), pair unnamed x86 targets
# with the C callee at the same position. Prints proposals with agreement.
import os as _os, sys as _sys
_sys.path.insert(0, _os.path.dirname(_os.path.abspath(__file__)))
from ps2paths import OG as _OG, SP as _SP, PS as _PS
import sys, re, os, collections, json
sys.path.insert(0, _SP)
from feat import _dis, text, TVA
import portcheck as pc
OG = _OG; PS = (_PS + "/src")
names = {v: n for n, (v, s) in pc.xf.items()}
FO = json.load(open(OG + "/analysis-ps2map/folded.json"))
fold_of = {n: int(k, 16) for k, v in FO.items() for n in v}
CRT = {0x175BFC, 0x175B40, 0x1764D2}
KW = {"if", "for", "while", "switch", "return", "sizeof", "defined"}
cache = {}
for root in (OG + "/src", PS):
    for r, _, fs in os.walk(root):
        for f in fs:
            if f.endswith(".c"):
                s = open(os.path.join(r, f), errors="replace").read()
                for m in re.finditer(r"^[A-Za-z_][\w \*]*?\b(\w+)\s*\([^;{]*\)\s*\{\n(.*?)^\}", s, re.M | re.S):
                    if "INCLUDE_ASM" in m[0]: continue
                    cache.setdefault(m[1], m[2])
props = collections.defaultdict(collections.Counter)
for n, (va, sz) in pc.xf.items():
    b = cache.get(n)
    if not b: continue
    b = re.sub(r"/\*.*?\*/|//[^\n]*|\"(?:\\.|[^\"])*\"", "", b, flags=re.S)
    b = re.sub(r"#if defined\(TARGET_PS2\)\n.*?#endif", "", b, flags=re.S)
    cs = [x for x in re.findall(r"\b([A-Za-z_]\w*)\s*\(", b) if x not in KW]
    xs = []
    for i in _dis.disasm(text[va - TVA: va - TVA + sz], va):
        if i.mnemonic in ("call", "jmp") and re.fullmatch(r"0x[0-9a-f]+", i.op_str):
            t = int(i.op_str, 16)
            if va <= t < va + sz or t in CRT: continue
            if i.mnemonic == "jmp" and t not in names and not (0x11000 <= t < 0x180000): continue
            xs.append(t)
    if len(xs) != len(cs) or not xs: continue
    ok = True; pend = []
    for t, c in zip(xs, cs):
        if t in names:
            if names[t] != c and fold_of.get(c) != t: ok = False; break
        elif fold_of.get(c) == t or c == "sub_%08X" % t: continue
        elif c in pc.xf or c in fold_of or c.startswith("sub_"): ok = False; break
        else: pend.append((t, c))
    if ok:
        for t, c in pend: props[t][c] += 1
for t, c in sorted(props.items()):
    if len(c) == 1: print(f"{list(c)[0]}=0x{t:x}", sum(c.values()))
    else: print("CONFLICT", hex(t), dict(c))
