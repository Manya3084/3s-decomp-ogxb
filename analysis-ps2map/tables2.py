# Pair function-pointer tables that have no named anchors, by structure.
# Each table slot is compared by its call-argument signature: the x86 body's
# (named callee, pushed small constants) calls must all appear among the PS2
# function's calls at that index. A window pairs when at least 70% of the
# comparable slots (and at least 6) agree, and it beats the next window by 2x.
# Output: tables2.json {va: name} for unnamed, unfolded slots.
import os as _os, sys as _sys
_sys.path.insert(0, _os.path.dirname(_os.path.abspath(__file__)))
from ps2paths import OG as _OG, SP as _SP, PS as _PS
import sys, re, json, struct, collections, bisect
D = (_SP + "/")
sys.path.insert(0, D)
from feat import *
from feat import _dis
OG = _OG
xn = {}
for l in open(OG + "/config/sf33rd/symbols/funcs.txt"):
    m = re.match(r"(\S+)\s*=\s*(0x[0-9A-Fa-f]+);", l)
    if m: xn[int(m[2], 16)] = m[1]
byname = {v: k for k, v in xn.items()}
FOLD = {int(k, 16) for k in json.load(open(D + "folded.json"))}
r = open(PS + "/THIRD_U.BIN.retail", "rb").read()
pn = {a: n for n, (a, s) in pinfo.items()}
ptabs = []; run = []
for off in range(0x80 + (0x373780 - 0x100000), len(r) - 3, 4):
    v = struct.unpack_from("<I", r, off)[0]
    if v in pn: run.append(pn[v])
    else:
        if len(run) >= 5: ptabs.append(run)
        run = []
xtabs = []
for sname in (".rdata", ".data"):
    s_ = img.section(sname); blob = img.bytes_at(s_.va, min(s_.virtual_size, s_.raw_size)); run = []
    for i in range(0, len(blob) - 3, 4):
        v = struct.unpack_from("<I", blob, i)[0]
        if TVA <= v < TEND: run.append(v)
        else:
            if len(run) >= 5: xtabs.append(run)
            run = []
rel = sorted(set(xn) | {a for xt in xtabs for a in xt})
REFC = collections.Counter(a for xt in xtabs for a in xt)
_xs = {}; _ps = {}
def xsig(va):
    if va not in _xs:
        i = bisect.bisect_right(rel, va); nx = rel[i] if i < len(rel) else TEND
        s = padded_end(cfg_extent(va, rel), nx) - va
        x = x_callargs(va, max(s, 1), xn)
        _xs[va] = frozenset(k for k in x if k[0] != "?" and k[1])
    return _xs[va]
def psig(n):
    if n not in _ps:
        p = ps2_callargs(n)
        _ps[n] = frozenset(k for k in p if k[0] != "?" and k[1] and k[0] in byname)
    return _ps[n]
def slot_eq(va, n):
    xs = xsig(va); ps = psig(n)
    if not xs or not ps: return None
    for c, a in xs:
        if (c, a) in ps: continue
        if not any(c == c2 and set(a) <= set(a2) for c2, a2 in ps): return False
    return True
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
out = {}; conflict = set(); used = 0; NEWFOLD = {}
for pt in ptabs:
    # skip PS2 tables already mostly named on the Xbox side
    if sum(1 for n in pt if n in byname) * 2 > len(pt): continue
    cands = []
    for xt in xtabs:
        if len(xt) < len(pt): continue
        for o in range(len(xt) - len(pt) + 1):
            w = xt[o:o + len(pt)]
            # anchors that contradict rule the window out
            bad = False; newfold = []
            for a, b in zip(w, pt):
                if a in xn and xn[a] != b and a not in FOLD:
                    e_ = slot_eq(a, b)
                    if e_ is True or (e_ is None and REFC[a] >= 2): newfold.append(a)
                    else: bad = True; break
            if bad: continue
            ok = cmp_ = 0
            for a, b in zip(w, pt):
                e = slot_eq(a, b)
                if e is None: continue
                cmp_ += 1; ok += e
            if cmp_ >= 6 and ok * 10 >= cmp_ * 7: cands.append((ok, cmp_, id(xt), o, w, newfold))
    if not cands: continue
    cands.sort(key=lambda c: (-(c[0] == c[1]), -c[0]))
    b0 = cands[0]
    if b0[0] != b0[1]: continue
    if len(cands) > 1:
        b1 = cands[1]
        if not (b1[1] - b1[0] >= max(3, b1[1] // 10) or b1[0] * 2 <= b0[0]): continue
    ok, cmp_, _, o, w, newfold = b0; used += 1
    for a in newfold: NEWFOLD.setdefault(a, set()).update({xn[a], dict(zip(w, pt))[a]})
    for a, b in zip(w, pt):
        if a in xn or a in FOLD: continue
        if a in out and out[a] != b: conflict.add(a)
        out[a] = b
for a in conflict: out.pop(a, None)
cnt = collections.Counter(out.values())
out = {a: b for a, b in out.items() if cnt[b] == 1 and b not in byname}
print("structurally paired tables", used, "new names", len(out), "new folded", len(NEWFOLD))
json.dump({hex(a): sorted(v) for a, v in NEWFOLD.items()}, open(D + "newfold2.json", "w"))
json.dump({hex(a): b for a, b in sorted(out.items())}, open(D + "tables2.json", "w"))
