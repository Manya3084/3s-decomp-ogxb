# Map function-pointer tables in the PS2 data to tables in the XBE data.
# A PS2 table is a run of >= 3 words that each point at a named PS2 function.
# An Xbox table is a run of >= 3 words that each point into .text.
# Tables pair when they have the same length and every Xbox entry that is
# already named agrees with the PS2 entry at that index (>= 2 agreements, no
# disagreement). Unnamed Xbox entries then take the PS2 name at their index.
import os as _os, sys as _sys
_sys.path.insert(0, _os.path.dirname(_os.path.abspath(__file__)))
from ps2paths import OG as _OG, SP as _SP, PS as _PS
import sys, re, json, struct, collections, pathlib
OG = _OG; PS = _PS
S = (_SP + "/")
sys.path.insert(0, OG + "/tools")
from ogxb.xbe import load
img = load(pathlib.Path(open(OG + "/xbe.path").read().strip()))
sec, text = img.text; TVA = sec.va; TEND = TVA + len(text)

r = open(PS + "/THIRD_U.BIN.retail", "rb").read()
pn = {}
for l in open(PS + "/config/retail/symbols/funcs.txt"):
    m = re.match(r"(\S+) = (0x[0-9A-Fa-f]+);", l)
    if m: pn[int(m[2], 16)] = m[1]
# PS2 data range: after code
ptabs = []; run = []
for off in range(0x80 + (0x373780 - 0x100000), len(r) - 3, 4):
    v = struct.unpack_from("<I", r, off)[0]
    if v in pn: run.append(pn[v])
    else:
        if len(run) >= 3: ptabs.append(run)
        run = []
xn = {}
for l in open(OG + "/config/sf33rd/symbols/funcs.txt"):
    m = re.match(r"(\S+)\s*=\s*(0x[0-9A-Fa-f]+);", l)
    if m: xn[int(m[2], 16)] = m[1]
byname = {v: k for k, v in xn.items()}
xtabs = []
for sname in (".rdata", ".data"):
    s_ = img.section(sname); blob = img.bytes_at(s_.va, min(s_.virtual_size, s_.raw_size)); run = []
    for i in range(0, len(blob) - 3, 4):
        v = struct.unpack_from("<I", blob, i)[0]
        if TVA <= v < TEND: run.append(v)
        else:
            if len(run) >= 3: xtabs.append(run)
            run = []
# PS2 bodies masked for relocation: identical masks are twins MSVC may fold
pinfo = {}
for l in open(PS + "/config/retail/symbols/funcs.txt"):
    m = re.match(r"(\S+) = (0x[0-9A-Fa-f]+);.*size:(0x[0-9A-Fa-f]+)", l)
    if m: pinfo[m[1]] = (int(m[2], 16), int(m[3], 16))
PW = lambda a: struct.unpack_from("<I", r, 0x80 + a - 0x100000)[0]
def pmask(n):
    a, sz = pinfo[n]; o = []
    for x in range(a, a + sz, 4):
        w = PW(x); op = w >> 26
        if op in (2, 3):
            t_ = (w & 0x3FFFFFF) << 2
            o.append(("call", op, PN_.get(t_, t_ - a if a <= t_ < a + sz else "?")))
        else: o.append(op << 26 if op == 0x0F else (w & 0xFFFF0000 if ((w >> 21) & 31) == 28 else w))
    while o and o[-1] == 0: o.pop()
    return tuple(o)
PN_ = {v[0]: k for k, v in pinfo.items()}
_mk = {}
def twin(a, b):
    if a not in pinfo or b not in pinfo: return False
    for n in (a, b):
        if n not in _mk: _mk[n] = pmask(n)
    return _mk[a] == _mk[b]
REFC = collections.Counter()
for sname in (".rdata", ".data"):
    s_ = img.section(sname); blob_ = img.bytes_at(s_.va, min(s_.virtual_size, s_.raw_size))
    for i in range(0, len(blob_) - 3, 4):
        v = struct.unpack_from("<I", blob_, i)[0]
        if TVA <= v < TEND: REFC[v] += 1
# local tables: function-pointer immediates a function stores to consecutive stack slots
def _local_tables():
    import bisect as _b
    from ogxb.cap import Disassembler as _D
    st = sorted(int(l.split()[0], 16) for l in open(OG + "/build/sf33rd/functions.txt") if l.startswith("0x"))
    st = sorted(set(st) | set(xn))
    res = []
    with _D() as d_:
        for a_, b_ in zip(st, st[1:] + [TEND]):
            slots = {}
            for ins in d_.disasm(text[a_ - TVA:b_ - TVA], a_):
                if ins.mnemonic != "mov" or not ins.op_str.startswith("dword ptr ["): continue
                m_ = re.match(r"dword ptr \[(ebp|esp)\s*([+-])\s*(0x[0-9a-f]+|\d+)\], (0x[0-9a-f]+)$", ins.op_str)
                if not m_: continue
                v_ = int(m_[4], 16)
                if not (TVA <= v_ < TEND): continue
                off_ = int(m_[3], 0) * (-1 if m_[2] == "-" else 1)
                slots[(m_[1], off_)] = v_
            if len(slots) >= 3:
                for base in ("ebp", "esp"):
                    ks = sorted(o for (b2, o) in slots if b2 == base)
                    run_ = []
                    for i_, o in enumerate(ks):
                        if run_ and o != prev + 4:
                            if len(run_) >= 3: res.append(run_)
                            run_ = []
                        run_.append(slots[(base, o)]); prev = o
                    if len(run_) >= 3: res.append(run_)
    return res
xtabs += _local_tables()
out = {}; conflict = set(); used = 0
# slide each PS2 run along each Xbox run (both directions of containment)
def try_window(xw, pw):
    agree = sum(1 for a, b in zip(xw, pw) if xn.get(a) == b)
    hard = sum(1 for a, b in zip(xw, pw) if a in xn and xn[a] != b and not twin(xn[a], b) and REFC[a] < 2)
    soft = sum(1 for a, b in zip(xw, pw) if a in xn and xn[a] != b and not twin(xn[a], b) and REFC[a] >= 2)
    named = sum(1 for a in xw if a in xn)
    if hard or (soft and (agree < 3 or soft * 4 > agree)) or agree * 2 < named: return agree, 1
    return agree, 0
pairs = []
for xi, xt in enumerate(xtabs):
    for pi, pt in enumerate(ptabs):
        L = min(len(xt), len(pt))
        if L < 3: continue
        big, small, xbig = (xt, pt, True) if len(xt) >= len(pt) else (pt, xt, False)
        hits = []
        for o in range(len(big) - len(small) + 1):
            w = big[o:o + len(small)]
            xw, pw = (w, small) if xbig else (small, w)
            ag, ds = try_window(xw, pw)
            if ag >= 2 and ds == 0: hits.append((o, xw, pw, ag))
        if len(hits) == 1: pairs.append(hits[0])
for o, xw, pw, ag in pairs:
    used += 1
    for a, b in zip(xw, pw):
        if a in xn: continue
        if a in out and out[a] != b: conflict.add(a)
        out[a] = b
# folded: an address the paired windows map to two different PS2 names
seen_names = collections.defaultdict(set)
for o, xw, pw, ag in pairs:
    for a, b in zip(xw, pw): seen_names[a].add(b)
folded = {a: sorted(v) for a, v in seen_names.items() if len(v) > 1}
json.dump({hex(a): v for a, v in folded.items()}, open(S + "folded.json", "w"))
for a in conflict: out.pop(a, None)
for a in folded: out.pop(a, None)
# a twin-named address referenced from more than one data slot is a folded body: leave it unnamed
refc = collections.Counter()
for sname in (".rdata", ".data"):
    s_ = img.section(sname); blob = img.bytes_at(s_.va, min(s_.virtual_size, s_.raw_size))
    for i in range(0, len(blob) - 3, 4):
        v = struct.unpack_from("<I", blob, i)[0]
        if v in out: refc[v] += 1
masks = collections.defaultdict(list)
for n_ in pinfo: masks[pmask(n_)].append(n_)
tw = {n_ for v_ in masks.values() if len(v_) > 1 for n_ in v_}
out = {a: b for a, b in out.items() if not (b in tw and refc[a] > 1)}
# drop names already used elsewhere or proposed twice
cnt = collections.Counter(out.values())
out = {a: b for a, b in out.items() if cnt[b] == 1 and b not in byname}
print("ps2 tables", len(ptabs), "xbox tables", len(xtabs), "paired", used, "new names", len(out))
json.dump({hex(a): b for a, b in sorted(out.items())}, open(S + "tables.json", "w"))
