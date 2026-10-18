# Name unnamed XBE call targets by aligning call sequences.
# For each function named in both builds, the XBE direct call/tail-jump
# targets (in address order) are aligned with the PS2 retail jal/j targets.
# Known pairs must agree; an unnamed XBE target aligned to a PS2 callee that
# has no XBE name yet votes for that name. Names with consistent votes are
# accepted, and the pass repeats with the new anchors.
# Usage: callalign.py [--write]   (prints proposals; --write adds them)
import os as _os, sys as _sys
_sys.path.insert(0, _os.path.dirname(_os.path.abspath(__file__)))
from ps2paths import OG as _OG, SP as _SP, PS as _PS
import sys, re, json, struct, collections, bisect
sys.path.insert(0, _SP)
from feat import img, text, TVA, TEND, PW, prows, pinfo, _dis, cfg_extent, padded_end
OG = _OG
WRITE = "--write" in sys.argv
folded = set(int(k, 16) for k in json.load(open(OG + "/analysis-ps2map/folded.json")))
deny = json.load(open(OG + "/analysis-ps2map/deny.json"))
denyset = set()
for d in (deny if isinstance(deny, list) else deny.items()):
    try: denyset.add((d[0], int(str(d[1]), 16) if not isinstance(d[1], int) else d[1]))
    except Exception: pass
xf = {}
for l in open(OG + "/config/sf33rd/symbols/funcs.txt"):
    m = re.match(r"(\S+)\s*=\s*(0x[0-9A-Fa-f]+);.*size:(0x[0-9A-Fa-f]+)", l)
    if m: xf[int(m[2], 16)] = (m[1], int(m[3], 16))
paddr = {a: n for n, a, s in prows}
_JTX = re.compile(r"dword ptr \[(e\w\w)\*4 \+ (0x[0-9a-f]+)\]")
def xcalls(va, sz):
    """(raw order, case order) of direct call/tail-jump targets."""
    ins = list(_dis.disasm(text[va - TVA: va - TVA + sz], va))
    calls = []
    for i in ins:
        if i.mnemonic in ("call", "jmp") and re.fullmatch(r"0x[0-9a-f]+", i.op_str):
            t = int(i.op_str, 16)
            if not (va <= t < va + sz): calls.append((i.address, t))
    raw = [t for _, t in calls]
    # dispatch targets in case order: first compare chain or jump table
    order = []
    for k, i in enumerate(ins):
        jm = _JTX.search(i.op_str) if i.mnemonic == "jmp" else None
        if jm:
            tb = int(jm[2], 16)
            for q in range(256):
                try: v = struct.unpack("<I", img.bytes_at(tb + 4 * q, 4))[0]
                except Exception: break
                if not (va <= v < va + sz): break
                if v not in order: order.append(v)
            dflt = [int(j.op_str, 16) for j in ins[max(0, k - 3):k] if j.mnemonic == "ja" and j.op_str.startswith("0x")]
            order += [d for d in dflt if d not in order]
            break
        if i.mnemonic in ("sub", "cmp", "dec", "test") and k + 1 < len(ins) and ins[k + 1].mnemonic in ("je", "jz"):
            j = k; E = []
            while j < len(ins) and ins[j].mnemonic in ("sub", "cmp", "dec", "test", "je", "jz"):
                if ins[j].mnemonic in ("je", "jz") and ins[j].op_str.startswith("0x"): E.append(int(ins[j].op_str, 16))
                j += 1
            if len(E) >= 1 and j < len(ins):
                order = [e for n_, e in enumerate(E) if e not in E[:n_]] + [ins[j].address]
            break
    if len(order) < 2: return raw, raw
    lo = min(order); srt = sorted(order); rank = {a: n_ for n_, a in enumerate(order)}
    def key(a):
        if a < lo: return (-1, a)
        b = srt[bisect.bisect_right(srt, a) - 1]
        return (rank[b], a)
    return raw, [t for _, t in sorted(calls, key=lambda c: key(c[0]))]
def pcalls(n):
    a, s = pinfo[n]; out = []
    for x in range(a, a + s, 4):
        w = PW(x); op = w >> 26
        if op in (2, 3):
            t = (x & 0xF0000000) | ((w & 0x3FFFFFF) << 2)
            if t in paddr and not (a <= t < a + s): out.append(paddr[t])
    return out
pairs = [(va, sz, n) for va, (n, sz) in xf.items() if n in pinfo]
PC = {n: pcalls(n) for _, _, n in pairs}
XC = {va: xcalls(va, sz) for va, sz, _ in pairs}
alltargets = set(t for v in XC.values() for t in v[0])
accepted = {}; stat = {}
WATCH = set(sys.argv[2:]) if len(sys.argv) > 2 and sys.argv[1] == '--watch' else set()
XIN = collections.Counter(t for v in XC.values() for t in v[0])
def align(X, P, xname, named):
    # DP maximizing score; returns list of (xtok, pname) matches
    n, m = len(X), len(P)
    S = [[0] * (m + 1) for _ in range(n + 1)]
    for i in range(n - 1, -1, -1):
        for j in range(m - 1, -1, -1):
            best = max(S[i + 1][j], S[i][j + 1])
            x = X[i]; p = P[j]
            if x in xname:
                if xname[x] == p: best = max(best, 3 + S[i + 1][j + 1])
            elif x in folded:
                best = max(best, 2 + S[i + 1][j + 1])
            elif p not in named:
                best = max(best, 1 + S[i + 1][j + 1])
            S[i][j] = best
    i = j = 0; out = []
    while i < n and j < m:
        x = X[i]; p = P[j]
        if x in xname and xname[x] == p and S[i][j] == 3 + S[i + 1][j + 1]: out.append((x, p, True)); i += 1; j += 1
        elif x not in xname and x in folded and S[i][j] == 2 + S[i + 1][j + 1]: i += 1; j += 1
        elif x not in xname and x not in folded and p not in named and S[i][j] == 1 + S[i + 1][j + 1]: out.append((x, p, False)); i += 1; j += 1
        elif S[i][j] == S[i + 1][j]: i += 1
        else: j += 1
    return out
def pick(R, C, P, xname, named):
    a1 = align(R, P, xname, named)
    if C == R: return a1
    a2 = align(C, P, xname, named)
    k1 = sum(1 for *_, k in a1 if k); k2 = sum(1 for *_, k in a2 if k)
    if k1 > k2: return a1
    if k2 > k1: return a2
    v1 = sorted((x, p) for x, p, k in a1 if not k); v2 = sorted((x, p) for x, p, k in a2 if not k)
    return a1 if v1 == v2 else None
for rnd in range(200):
    xname = {va: n for va, (n, _) in xf.items()}; xname.update({a: n for a, (n, _) in accepted.items()})
    named = set(xname.values())
    votes = collections.defaultdict(collections.Counter); callers = collections.defaultdict(set)
    for va, sz, n in pairs:
        (R, C), P = XC[va], PC[n]
        if not R or not P: continue
        al = pick(R, C, P, xname, named)
        if al is None: continue
        X = R
        known = sum(1 for _, _, k in al if k)
        unk = [(x, p) for x, p, k in al if not k]
        # trust: either anchored by known matches, or exact same length
        if not unk: continue
        if known == 0 and len(X) != len(P): continue
        w = 2 if len(X) == len(P) else 1
        for x, p in unk: votes[x][p] += w; callers[x].add(va)
    new = {}
    byname = collections.defaultdict(list)
    for x, c in votes.items():
        for p, v in c.items(): byname[p].append((v, x))
    for p in byname: byname[p].sort(reverse=True)
    cand = []
    for x, c in votes.items():
        (p, v) = c.most_common(1)[0]; tot = sum(c.values())
        if v < 2 or v * 3 < tot or (p, x) in denyset: continue
        if byname[p][0][1] != x: continue          # mutual best
        cand.append((v, x, p))
    cand.sort(reverse=True)
    # accept the strongest quarter each round so anchors settle gradually
    for v, x, p in cand[:max(1, len(cand) // 4)]:
        new[x] = p; stat[x] = (v, sum(votes[x].values()), len(callers[x]), XIN[x])
    if not new: break
    stops = sorted(set(xf) | alltargets | set(accepted))
    for x, p in new.items():
        k = bisect.bisect_right(stops, x); nx = stops[k] if k < len(stops) else x + 0x4000
        e = padded_end(cfg_extent(x, stops), nx)
        accepted[x] = (p, e - x)
    print("round", rnd, "new", len(new), file=sys.stderr)
xname = {va: n for va, (n, _) in xf.items()}; xname.update({a: n for a, (n, _) in accepted.items()})
hit = collections.Counter(); miss = collections.Counter()
for va, sz, n in pairs:
    (R, C), P = XC[va], PC[n]
    if not R or not P: continue
    al = pick(R, C, P, xname, set(xname.values()) | set(PC[n])) or []
    X = R
    m = {x for x, p, k in al if k}
    for x in set(X):
        if x in accepted and accepted[x][0] in P:
            (hit if x in m else miss)[x] += 1
def keep(x):
    s = accepted[x][1]; ps = pinfo[accepted[x][0]][1]; r = s / ps
    if hit[x] >= 5 and hit[x] >= 2 * miss[x]: return True
    if hit[x] < max(1, miss[x]): return False
    if hit[x] >= 2: return 0.15 <= r <= 2.5
    return 0.3 <= r <= 1.5
bad = [x for x in accepted if not keep(x)]
for x in bad: print("REJECT", accepted[x][0], hex(x), hit[x], miss[x], file=sys.stderr); accepted.pop(x)
for x, (p, s) in sorted(accepted.items()):
    ps = pinfo[p][1]
    v, tot, nc, xin = stat[x]; xin = f'{xin} hit {hit[x]} miss {miss[x]}'
    print(f"{p} 0x{x:X} 0x{s:X} ps2size 0x{ps:X} votes {v}/{tot} callers {nc} xin {xin}")
json.dump({hex(x): [p, s, *stat[x]] for x, (p, s) in accepted.items()}, open(OG + "/analysis-ps2map/callalign.json", "w"), indent=0)
