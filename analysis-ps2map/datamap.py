# Name XBE globals with PS2 names, from the anniversary debug ELF.
# For each function named in both builds, the debug body's data references
# (lui/addiu pairs, gp-relative) give a set of debug symbols (+offsets); the
# XBE body's absolute operands give a set of addresses. An XBE address takes
# the symbol every function that uses it also references. The symbol's XBE
# base is the most common (address - debug offset) that keeps all its
# addresses inside the symbol's size.
import os as _os, sys as _sys
_sys.path.insert(0, _os.path.dirname(_os.path.abspath(__file__)))
from ps2paths import OG as _OG, SP as _SP, PS as _PS
import sys, re, struct, bisect, collections, json, pathlib
OG = _OG; PS = _PS
sys.path.insert(0, OG + "/tools")
from ogxb.xbe import load
from ogxb.cap import Disassembler
img = load(pathlib.Path(open(OG + "/xbe.path").read().strip()))
sec, text = img.text; TVA = sec.va; TEND = TVA + len(text)
DLO = 0x218DC0  # .rdata start; data refs below this are code
d = open(PS + "/THIRD_U.BIN", "rb").read()
# debug ELF program header: assume single load at 0x100000 from file 0x80 (same as retail layout check)
def dW(a): return struct.unpack_from("<I", d, 0x80 + a - 0x100000)[0]
# gp from .reginfo: find section by name
e_shoff = struct.unpack_from("<I", d, 0x20)[0]; e_shentsize, e_shnum, e_shstrndx = struct.unpack_from("<HHH", d, 0x2E)
sh = [struct.unpack_from("<IIIIIIIIII", d, e_shoff + i * e_shentsize) for i in range(e_shnum)]
shstr = sh[e_shstrndx][4]
def sname(s): o = shstr + s[0]; return d[o:d.index(b"\0", o)].decode()
GP = None
for s in sh:
    if sname(s) == ".reginfo": GP = struct.unpack_from("<I", d, s[4] + 20)[0]
print("debug gp", hex(GP))
fun = {}; data = []
for l in open(PS + "/config/anniversary/symbols/syms_sfiii.txt"):
    m = re.match(r"(\S+) = (0x[0-9A-Fa-f]+);\s*//(.*)", l)
    if not m: continue
    a = int(m[2], 16); c = m[3]
    if "ignore" in c.replace(" ", ""): continue
    if "type:func" in c: fun[m[1]] = a
    else:
        sz = re.search(r"size:(0x[0-9A-Fa-f]+)", c)
        if sz and not m[1].startswith("D_"): data.append((a, int(sz[1], 16), m[1]))
data.sort(); dstarts = [a for a, _, _ in data]
fad = sorted(fun.values()); fend = {a: (fad[i + 1] if i + 1 < len(fad) else a + 0x400) for i, a in enumerate(fad)}
def dsym(addr):
    i = bisect.bisect_right(dstarts, addr) - 1
    if i >= 0:
        a, sz, n = data[i]
        if a <= addr < a + max(sz, 1): return n, addr - a
    return None
def debug_refs(name):
    a = fun[name]; e = min(fend[a], a + 0x8000); out = set(); hi = {}
    for x in range(a, e, 4):
        w = dW(x); op = w >> 26; rs = (w >> 21) & 31; rt = (w >> 16) & 31; imm = ((w & 0xFFFF) ^ 0x8000) - 0x8000
        if op == 0x0F: hi[rt] = (w & 0xFFFF) << 16; continue
        if op in (9, 0x20, 0x21, 0x23, 0x24, 0x25, 0x27, 0x28, 0x29, 0x2B, 0x31, 0x39, 0x37, 0x3F, 0x1E, 0x1F):
            if rs in hi:
                s = dsym((hi[rs] + imm) & 0xFFFFFFFF)
                if s: out.add(s)
            elif rs == 28:
                s = dsym((GP + imm) & 0xFFFFFFFF)
                if s: out.add(s)
        if op in (9, 0x0D) and rs in hi and rt != rs: pass
        if op not in (0x28, 0x29, 0x2B, 0x3F, 0x39): hi.pop(rt, None)
    return out
xn = {}; xs = {}
for l in open(OG + "/config/sf33rd/symbols/funcs.txt"):
    m = re.match(r"(\S+)\s*=\s*(0x[0-9A-Fa-f]+);.*size:(0x[0-9A-Fa-f]+)", l)
    if m: xn[int(m[2], 16)] = m[1]; xs[int(m[2], 16)] = int(m[3], 16)
def xbox_refs(va, sz):
    out = set()
    with Disassembler() as dis_:
        for i in dis_.disasm(img.bytes_at(va, sz), va):
            if i.mnemonic == "call" or i.mnemonic.startswith("j"): continue
            for h in re.findall(r"0x[0-9a-f]+", i.op_str):
                v = int(h, 16)
                if DLO <= v < 0xD20000 and v.to_bytes(4, "little") in img.bytes_at(va, sz): out.add(v)
    return out
cand = {}   # xbox addr -> set of debug symbol names (intersection)
pairs = collections.defaultdict(list)  # sym -> list of (xbox addrs set, debug offsets set) per function
nf = 0
for va, n in xn.items():
    if n not in fun: continue
    dr = debug_refs(n); xr = xbox_refs(va, xs[va])
    if not dr or not xr: continue
    nf += 1
    names = {s for s, _ in dr}
    for A in xr:
        cand[A] = names if A not in cand else (cand[A] & names)
    for s in names:
        pairs[s].append((xr, {o for s2, o in dr if s2 == s}))
print("functions compared", nf, "xbox addresses", len(cand))
size = {n: sz for _, sz, n in data}
offs_of = collections.defaultdict(set)
for sym, L in pairs.items():
    for xr, os_ in L: offs_of[sym] |= os_
final = {}
for it in range(20):
    uniq = {A: next(iter(c)) for A, c in cand.items() if len(c) == 1}
    bysym = collections.defaultdict(set)
    for A, sym in uniq.items(): bysym[sym].add(A)
    changed = False
    for sym, As in bysym.items():
        if sym in final: continue
        votes = collections.Counter(A - o for A in As for o in offs_of[sym])
        if not votes: continue
        best = None
        for base, c in votes.most_common(8):
            # per-function consistency: each function's addresses for sym must be offsets it used
            sc = tot = 0
            for xr, os_ in pairs[sym]:
                mine = [A for A in xr if A in As]
                tot += len(mine); sc += sum(1 for A in mine if (A - base) in os_)
            tz = (base & -base).bit_length() if base else 32
            if best is None or (sc, tz) > (best[1], best[3]): best = (base, sc, tot, tz)
        base, sc, tot, _ = best
        if tot == 0 or sc * 10 < tot * 9: continue
        final[sym] = (base, size[sym], len(As)); changed = True
    # eliminate placed symbols from addresses outside their ranges, pin those inside
    for A in list(cand):
        c = cand[A]
        inr = {sym for sym in c if sym in final and final[sym][0] - 0x400 <= A < final[sym][0] + max(final[sym][1], 1)}
        new = inr if inr else {sym for sym in c if sym not in final}
        if new and new != c: cand[A] = new; changed = True
    if not changed: break
# symbols referenced by exactly the same functions cannot be told apart
fsets = collections.defaultdict(list)
for sym in list(final):
    fsets[frozenset(id(xr) for xr, _ in pairs[sym])].append(sym)
for k_, L in fsets.items():
    if len(L) > 1:
        for sym in L: final.pop(sym, None)
# a base claimed by two symbols: keep the one with more addresses
byb = collections.defaultdict(list)
for sym, (bb, sz, k) in final.items(): byb[bb].append((k, sym))
for bb, L in byb.items():
    if len(L) > 1:
        L.sort(reverse=True)
        for k, sym in L[1:]: final.pop(sym, None)
print("symbols placed", len(final))
json.dump({s: [hex(b), sz, k] for s, (b, sz, k) in sorted(final.items(), key=lambda x: x[1][0])}, open(OG + "/analysis-ps2map/datamap.json", "w"), indent=0)
