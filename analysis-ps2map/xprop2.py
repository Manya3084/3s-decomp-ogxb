# Name XBE functions from the PS2 retail map.
# Evidence: (1) call-graph votes from named Xbox functions whose call lists
# line up one to one with their PS2 namesakes; (2) source-order gaps between
# two named Xbox functions from the same PS2 file. Every candidate must pass
# feat.accept (constants and field offsets agree) unless noted.
import os as _os, sys as _sys
_sys.path.insert(0, _os.path.dirname(_os.path.abspath(__file__)))
from ps2paths import OG as _OG, SP as _SP, PS as _PS
import sys, re, json, bisect, collections, os
sys.path.insert(0, _SP)
from feat import *
from feat import _dis

GAME = PS + "/src/anniversary/sf33rd/Source/Game"
DEF = re.compile(r"^(?:static\s+)?(?:inline\s+)?[A-Za-z_][\w\s\*]*?\b([A-Za-z_]\w*)\s*\([^;]*\)\s*\{?\s*$")
pfile = {}; forder = collections.defaultdict(list)
for root, _, fs in os.walk(PS + "/src/anniversary"):
    for f in sorted(fs):
        if not f.endswith(".c"): continue
        p = os.path.join(root, f); rel = os.path.relpath(p, PS + "/src/anniversary")
        for line in open(p, errors="replace"):
            m = DEF.match(line)
            if m and not line.rstrip().endswith(";") and m[1] not in ("if", "while", "for", "switch", "return"):
                n = m[1]
                if n in pinfo and n not in pfile:
                    pfile[n] = rel; forder[rel].append(n)

xname = {}; xsize = {}
for l in open(OG + "/config/sf33rd/symbols/funcs.txt"):
    m = re.match(r"(\S+)\s*=\s*(0x[0-9A-Fa-f]+);.*size:(0x[0-9A-Fa-f]+)", l)
    if m: xname[int(m[2], 16)] = m[1]; xsize[int(m[2], 16)] = int(m[3], 16)
HOLD = {}
if os.environ.get("HOLDOUT"):
    import random
    random.seed(int(os.environ["HOLDOUT"]))
    hand = set(open((_SP + "/handnames.txt")).read().split())
    for va in list(xname):
        if os.environ.get("BULKONLY") and xname[va] in hand: continue
        if os.environ.get("HOLDNAMES"):
            if xname[va] in set(open(os.environ["HOLDNAMES"]).read().split()): HOLD[va] = xname.pop(va)
            continue
        if random.random() < float(os.environ.get("HOLDFRAC", "0.3")): HOLD[va] = xname.pop(va)
starts = set(xname) | set(HOLD)
for l in open(OG + "/build/sf33rd/functions.txt"):
    m = re.match(r"(0x[0-9a-fA-F]+) size", l)
    if m: starts.add(int(m[1], 16))
order = sorted(s for s in starts if TVA <= s < TEND) + [TEND]
calls_at = []
for i in range(len(order) - 1):
    a, b = order[i], order[i + 1]
    for ins in _dis.disasm(text[a - TVA:b - TVA], a):
        if ins.mnemonic in ("call", "jmp") and ins.op_str.startswith("0x"):
            calls_at.append((ins.address, int(ins.op_str, 16), ins.mnemonic))
for _, t, k in calls_at:
    if k == "call" and TVA <= t < TEND: starts.add(t)
# function pointers in .rdata/.data that land after ret/jmp/int3 or on a prologue
_bound = {}; _prev = {}
for i in range(len(order) - 1):
    a, b = order[i], order[i + 1]; pv = None
    for ins in _dis.disasm(text[a - TVA:b - TVA], a):
        _bound[ins.address] = ins; _prev[ins.address] = pv; pv = ins
PRO = ("push", "sub", "mov")
for sname in (".rdata", ".data"):
    s_ = img.section(sname)
    blob = img.bytes_at(s_.va, min(s_.virtual_size, s_.raw_size))
    for i in range(0, len(blob) - 3, 4):
        v = struct.unpack_from("<I", blob, i)[0]
        if not (TVA <= v < TEND) or v in starts or v not in _bound: continue
        pv = _prev.get(v)
        if (pv is not None and (pv.mnemonic in ("ret", "jmp", "int3") or pv.mnemonic == "nop")) or _bound[v].mnemonic == "push":
            if pv is not None and pv.mnemonic == "jmp" and _bound[v].mnemonic not in PRO: continue
            starts.add(v)
TABLE = {}
if os.path.exists((_SP + "/tables.json")) and not os.environ.get("NOTABLES"):
    TABLE = {int(k, 16): v for k, v in json.load(open((_SP + "/tables.json"))).items()}
    if os.path.exists((_SP + "/localtabs.json")):
        for k_, v_ in json.load(open((_SP + "/localtabs.json"))).items():
            TABLE.setdefault(int(k_, 16), v_)
    if os.path.exists((_SP + "/tables2.json")):
        for k_, v_ in json.load(open((_SP + "/tables2.json"))).items():
            TABLE.setdefault(int(k_, 16), v_)
    starts |= set(TABLE)
# chain starts through packed functions: the padded end of each extent is a start
if not os.environ.get("NOCHAIN"):
    rel = sorted(s for s in starts if TVA <= s < TEND)
    queue = list(rel); seen_ = set(rel)
    while queue:
        st_ = queue.pop()
        stops = rel
        i_ = bisect.bisect_right(stops, st_); nx_ = stops[i_] if i_ < len(stops) else TEND
        e_ = padded_end(cfg_extent(st_, stops), nx_)
        if e_ < TEND and e_ not in seen_ and e_ < nx_:
            ins_ = _dis.disasm(text[e_ - TVA:e_ - TVA + 16], e_, 2)
            if len(ins_) == 2 and ins_[0].mnemonic not in ("int3", "add", "nop"):
                seen_.add(e_); starts.add(e_); queue.append(e_)
                bisect.insort(rel, e_)
S = sorted(s for s in starts if TVA <= s < TEND)
def owner(x):
    i = bisect.bisect_right(S, x) - 1
    return S[i] if i >= 0 else None
def span(va):
    i = bisect.bisect_left(S, va)
    return (S[i + 1] if i + 1 < len(S) else TEND) - va
xcalls = collections.defaultdict(list)
for at, t, k in calls_at:
    o = owner(at)
    if o is None or not (TVA <= t < TEND): continue
    if k == "jmp" and (t not in starts or owner(t) == o): continue
    xcalls[o].append(t)

# PS2 call lists
paddr = {a: n for n, (a, s) in pinfo.items()}
pcalls = {}
for n, (a, s) in pinfo.items():
    lst = []
    for x in range(a, a + s, 4):
        w = PW(x); op = w >> 26
        if op in (2, 3):
            t = (w & 0x3FFFFFF) << 2
            if op == 2 and a <= t < a + s: continue
            if t in paddr: lst.append(paddr[t])
            elif op == 3: lst.append("?")
    pcalls[n] = lst
# PS2 twins (likely folded on Xbox): identical masked bodies
def pmask(n):
    a, s = pinfo[n]; out = []
    for x in range(a, a + s, 4):
        w = PW(x); op = w >> 26
        if op in (2, 3):
            t_ = (w & 0x3FFFFFF) << 2
            out.append(("call", op, paddr.get(t_, t_ - a if a <= t_ < a + s else "?")))
        else: out.append(op << 26 if op == 0x0F else (w & 0xFFFF0000 if ((w >> 21) & 31) == 28 else w))
    while out and out[-1] == 0: out.pop()
    return tuple(out)
bodies = collections.defaultdict(list)
for n in pinfo: bodies[pmask(n)].append(n)
twins = {n for v in bodies.values() if len(v) > 1 for n in v}

XIN = collections.Counter(t for lst in xcalls.values() for t in lst)
PIN = collections.Counter(c for lst in pcalls.values() for c in lst)
DEBUG = {"printf", "flLogOut", "flPrintL", "flPrintColor", "flPS2SystemError", "__assert", "sprintf"}
known = dict(xname); byname = {v: k for k, v in known.items()}
prop = {}; why = {}
_EXT = {}
REL = sorted(set(xname) | set(HOLD) | {t for _, t, k in calls_at if k == "call" and TVA <= t < TEND} | set(TABLE))
def size_of(va):
    if va in xsize: return xsize[va]
    if va not in _EXT:
        i_ = bisect.bisect_right(REL, va); nx_ = REL[i_] if i_ < len(REL) else TEND
        _EXT[va] = padded_end(cfg_extent(va, REL), nx_) - va
    return _EXT[va] or span(va)
DENY = {(int(a_, 16), n_) for a_, n_ in json.load(open((_SP + "/deny.json")))} if os.path.exists((_SP + "/deny.json")) else set()
def try_add(va, n, src, strong=False, votes=0):
    if (va, n) in DENY: return False
    if va in known or n in byname or n in twins or n not in pinfo: return False
    psz = pinfo[n][1]; xsz = size_of(va)
    if not (0.2 <= xsz / psz <= 2.0): return False
    ok, ev = accept(n, va, xsz)
    if not ok and not (strong and ev == 0): return False
    if pushed_const_veto(n, va, xsz, known): return False
    a_, b_ = PIN.get(n, 0), XIN.get(va, 0)
    if max(a_, b_) >= 3 and not (b_ * 3 >= a_ and a_ * 3 >= b_) and votes < 5: return False
    # callee consistency
    xl = xcalls.get(va, []); pl = [c for c in pcalls.get(n, []) if c not in DEBUG]
    kx = {known[t] for t in xl if t in known}
    if kx - set(pl): return False
    if len(xl) > len(pl) + 2: return False
    if len(pl) >= 3 and len(xl) == 0: return False
    if len(pl) == 0 and len(xl) >= 2: return False
    if psz < 0x60 and src == "calls" and not strong: return False
    if psz < 0x60 and src == "fingerprint": return False
    if src == "fingerprint" and ev < 4: return False
    known[va] = n; byname[n] = va; prop[va] = n; why[va] = src
    return True

def diag(va, n):
    r = []
    if (va, n) in DENY: r.append("deny")
    if va in known: r.append("addr-named:" + known[va])
    if n in byname: r.append("name-used@" + hex(byname[n]))
    if n in twins: r.append("twin:" + ",".join(m for m in bodies[pmask(n)] if m != n)[:80])
    if n not in pinfo: r.append("no-ps2"); return r
    psz = pinfo[n][1]; xsz = size_of(va)
    if not (0.2 <= xsz / psz <= 2.0): r.append(f"size x{xsz:#x}/p{psz:#x}")
    ok, ev = accept(n, va, xsz)
    if not ok: r.append(f"accept-fail ev={ev}")
    if pushed_const_veto(n, va, xsz, known): r.append("pushed-const")
    a_, b_ = PIN.get(n, 0), XIN.get(va, 0)
    if max(a_, b_) >= 3 and not (b_ * 3 >= a_ and a_ * 3 >= b_): r.append(f"incount p{a_}/x{b_}")
    xl = xcalls.get(va, []); pl = [c for c in pcalls.get(n, []) if c not in DEBUG]
    kx = {known[t] for t in xl if t in known}
    if kx - set(pl): r.append("callee-mismatch:" + ",".join(sorted(kx - set(pl)))[:80])
    if len(xl) > len(pl) + 2: r.append(f"ncalls x{len(xl)}>p{len(pl)}")
    if len(pl) >= 3 and len(xl) == 0: r.append("no-xcalls")
    if len(pl) == 0 and len(xl) >= 2: r.append("p-no-calls")
    return r or ["ok"]
if os.environ.get("DIAG"):
    for item in json.load(open(os.environ["DIAG"])).items():
        va, n = int(item[0], 16), item[1][0]
        print(n, hex(va), *diag(va, n))
    sys.exit(0)
for va_, n_ in TABLE.items():
    if va_ in known or n_ in byname or n_ not in pinfo: continue
    if HOLD and va_ in HOLD: continue
    known[va_] = n_; byname[n_] = va_; prop[va_] = n_; why[va_] = "table"
for rnd in range(40):
    added = 0
    # (1) call-graph votes: segments between agreeing anchors
    votes = collections.defaultdict(collections.Counter)
    for va, n in list(known.items()):
        if n not in pcalls: continue
        xl = xcalls.get(va, []); pl = [c for c in pcalls[n] if c not in DEBUG]
        if not xl or not pl: continue
        # anchors: positions where known(xl[i]) == pl[j], increasing in both
        anc = [(-1, -1)]
        j0 = 0
        for i, t in enumerate(xl):
            kt = known.get(t)
            if kt is None: continue
            for j in range(j0, len(pl)):
                if pl[j] == kt:
                    anc.append((i, j)); j0 = j + 1; break
        anc.append((len(xl), len(pl)))
        for (i1, j1), (i2, j2) in zip(anc, anc[1:]):
            xs = xl[i1 + 1:i2]; ps = pl[j1 + 1:j2]
            if not xs or len(xs) != len(ps): continue
            if any(known.get(t) is not None for t in xs): continue
            for t, c in zip(xs, ps):
                if c != "?" and not (c in byname and byname[c] != t): votes[t][c] += 1
        # order-free: unknown targets/names paired by unique call counts
        xc_ = collections.Counter(t for t in xl if t not in known)
        pc_ = collections.Counter(c for c in pl if c != "?" and c not in byname)
        kx = collections.Counter(known[t] for t in xl if t in known)
        kp = collections.Counter(c for c in pl if c in byname)
        if xc_ and pc_ and kx == kp and sum(xc_.values()) == sum(pc_.values()):
            bx = collections.defaultdict(list); bp = collections.defaultdict(list)
            for t, k in xc_.items(): bx[k].append(t)
            for c, k in pc_.items(): bp[k].append(c)
            if sorted(bx) == sorted(bp):
                for k in bx:
                    if len(bx[k]) == 1 and len(bp[k]) == 1: votes[bx[k][0]][bp[k][0]] += 1
    for t, cnt in votes.items():
        (c, v), *rest = cnt.most_common()
        second = rest[0][1] if rest else 0
        if second == 0 or (v >= 2 and v >= 3 * second):
            added += try_add(t, c, "calls", strong=(v >= 2 and second == 0), votes=(v if second == 0 else 0))
    # (2) source-order gaps
    kv = sorted((va, n) for va, n in known.items() if n in pfile)
    for (a, na), (b, nb) in zip(kv, kv[1:]):
        if pfile[na] != pfile[nb]: continue
        fo = forder[pfile[na]]
        if na not in fo or nb not in fo: continue
        i, j = fo.index(na), fo.index(nb)
        if j <= i + 1: continue
        mid = [n for n in fo[i + 1:j] if n not in byname and n not in twins]
        xs = [s_ for s_ in S if a < s_ < b and s_ not in known]
        if not mid or not xs or len(xs) > 60 or len(mid) > 60: continue
        if len(mid) == len(xs):
            allok = True
            for s_, n in zip(xs, mid):
                ok_, ev_ = accept(n, s_, size_of(s_))
                if not (ok_ or ev_ == 0): allok = False; break
            if allok:
                for s_, n in zip(xs, mid):
                    added += try_add(s_, n, "gap", strong=True)
                continue
        # order-preserving DP over accepted pairs
        acc = {}
        for ii, n in enumerate(mid):
            for jj, s_ in enumerate(xs):
                ok, ev = accept(n, s_, size_of(s_))
                if ok: acc[(ii, jj)] = ev
        if not acc: continue
        L = [[0] * (len(xs) + 1) for _ in range(len(mid) + 1)]
        for ii in range(len(mid) - 1, -1, -1):
            for jj in range(len(xs) - 1, -1, -1):
                best = max(L[ii + 1][jj], L[ii][jj + 1])
                if (ii, jj) in acc: best = max(best, 1 + L[ii + 1][jj + 1])
                L[ii][jj] = best
        ii = jj = 0
        while ii < len(mid) and jj < len(xs):
            if (ii, jj) in acc and L[ii][jj] == 1 + L[ii + 1][jj + 1]:
                # uniqueness: this name accepts no other x in the gap, and x no other name
                if sum(1 for q in range(len(xs)) if (ii, q) in acc) == 1 and sum(1 for q in range(len(mid)) if (q, jj) in acc) == 1:
                    added += try_add(xs[jj], mid[ii], "order")
                ii += 1; jj += 1
            elif L[ii + 1][jj] >= L[ii][jj + 1]: ii += 1
            else: jj += 1
    # (2b) exact signature: identical constant/offset/callee sets, unique both sides
    if not added:
        def sig_x(va):
            c, o = x_feat(va, size_of(va))
            ks = tuple(sorted(known[t] for t in xcalls.get(va, []) if t in known))
            return (frozenset(v for v in c if v != 0), frozenset(v for v in o if v != 0 and abs(v) < 0x10000), ks, len(xcalls.get(va, [])))
        def sig_p(n):
            c, o = ps2_feat(n)
            pl = [x for x in pcalls.get(n, []) if x not in DEBUG]
            ks = tuple(sorted(x for x in pl if x in byname))
            return (frozenset(v for v in c if v != 0), frozenset(v for v in o if v != 0), ks, len(pl))
        SX = collections.defaultdict(list); SP = collections.defaultdict(list)
        for va in S:
            if va not in known: SX[sig_x(va)].append(va)
        for n in pinfo:
            if n not in byname and n not in twins and n in pfile: SP[sig_p(n)].append(n)
        for k, ns in SP.items():
            if len(ns) == 1 and len(SX.get(k, [])) == 1 and (len(k[0]) + len(k[1])) >= 3:
                added += try_add(SX[k][0], ns[0], "signature")
    # (3) global fingerprint match, mutual best with margin
    if not added:
        import math
        def fp_x(va):
            c, o = x_feat(va, size_of(va))
            f = {("c", v) for v in c if v not in TRIV} | {("o", v) for v in o if v != 0 and abs(v) < 0x10000}
            f |= {("k", known[t]) for t in xcalls.get(va, []) if t in known}
            return f
        def fp_p(n):
            c, o = ps2_feat(n)
            f = {("c", v) for v in c if v not in TRIV} | {("o", v) for v in o if v != 0}
            f |= {("k", x) for x in pcalls.get(n, []) if x in byname}
            return f
        ux = [va for va in S if va not in known]
        up = [n for n in pinfo if n not in byname and n not in twins and n in pfile]
        FX = {va: fp_x(va) for va in ux}; FP = {n: fp_p(n) for n in up}
        inv = collections.defaultdict(set)
        for va, f in FX.items():
            for k in f: inv[k].add(va)
        df = collections.Counter()
        for f in list(FX.values()) + list(FP.values()):
            for k in f: df[k] += 1
        idf = {k: math.log(1 + (len(FX) + len(FP)) / v) for k, v in df.items()}
        bestp = {}
        for n, f in FP.items():
            if len(f) < 3: continue
            sc = collections.Counter()
            for k in f:
                if len(inv[k]) > 400: continue
                for va in inv[k]: sc[va] += idf[k]
            if not sc: continue
            top = sc.most_common(2)
            tot = sum(idf[k] for k in f)
            if top[0][1] < 0.6 * tot: continue
            if len(top) > 1 and top[1][1] > 0.6 * top[0][1]: continue
            bestp[n] = top[0][0]
        rev = collections.defaultdict(list)
        for n, va in bestp.items(): rev[va].append(n)
        for va, ns in rev.items():
            if len(ns) == 1:
                added += try_add(va, ns[0], "fingerprint")
    if not added: break
if HOLD:
    res = collections.Counter()
    for va, n in prop.items():
        if va in HOLD: res[(why[va], HOLD[va] == n)] += 1
        elif n in HOLD.values(): res[(why[va], "name-elsewhere")] += 1
    print("HOLDOUT", len(HOLD), sorted(res.items(), key=str))
    bad = [(hex(va), HOLD[va], n, why[va]) for va, n in prop.items() if va in HOLD and HOLD[va] != n]
    print(bad[:20])
    out = {"hold": {hex(k): v for k, v in HOLD.items()}, "prop": {hex(k): v for k, v in prop.items()}}
    json.dump(out, open(sys.argv[1] + ".audit", "w"))
json.dump({"prop": {hex(k): [v, why[k], size_of(k)] for k, v in sorted(prop.items())},
           "pfile": pfile}, open(sys.argv[1], "w"))
print("rounds", rnd + 1, "proposed", len(prop), collections.Counter(why.values()))
