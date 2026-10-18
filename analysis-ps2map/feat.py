# Feature extraction for PS2 (MIPS) and Xbox (x86) bodies: constants and
# memory displacements. Shared by the scorer.
import os as _os, sys as _sys
_sys.path.insert(0, _os.path.dirname(_os.path.abspath(__file__)))
from ps2paths import OG as _OG, SP as _SP, PS as _PS
import sys, re, struct, bisect, collections, pathlib
OG = _OG; PS = _PS
sys.path.insert(0, OG + "/tools")
from ogxb.xbe import load
from ogxb.cap import Disassembler
img = load(pathlib.Path(open(OG + "/xbe.path").read().strip()))
sec, text = img.text
TVA = sec.va; TEND = TVA + len(text)
r = open(PS + "/THIRD_U.BIN.retail", "rb").read()
PW = lambda a: struct.unpack_from("<I", r, 0x80 + a - 0x100000)[0]
prows = []
for l in open(PS + "/config/retail/symbols/funcs.txt"):
    m = re.match(r"(\S+) = (0x[0-9A-Fa-f]+);.*size:(0x[0-9A-Fa-f]+)", l)
    if m: prows.append((m[1], int(m[2], 16), int(m[3], 16)))
pinfo = {n: (a, s) for n, a, s in prows}
LS = set(range(0x20, 0x40))
TRIV = {0, 1, -1, 2, 4, 8, 16}
def ps2_feat(n):
    a, s = pinfo[n]; c = collections.Counter(); o = collections.Counter(); lui = set()
    for x in range(a, a + s, 4):
        w = PW(x); op = w >> 26; rs = (w >> 21) & 31; rt = (w >> 16) & 31
        imm = ((w & 0xFFFF) ^ 0x8000) - 0x8000
        if op == 0x0F: lui.add(rt); continue
        if op in (9, 0x19, 0x0D, 0x0A, 0x0B) and rs == 0: c[imm if op != 0x0D else w & 0xFFFF] += 1
        elif op in (0x0A, 0x0B) : c[imm] += 1
        elif op in LS and rs not in (28, 29) and rs not in lui: o[imm] += 1
        if op not in LS or op in (0x20, 0x21, 0x23, 0x24, 0x25, 0x27, 0x37): lui.discard(rt)
    return c, o
_dis = Disassembler()
IMM = re.compile(r"(?<![\w\[+\-])(-?0x[0-9a-f]+|-?\d+)(?![\w\]])")
DISP = re.compile(r"\[(e[a-z]{2})(?:[^\]]*?)([+-] ?0x[0-9a-f]+|[+-] ?\d+)\]")
def x_feat(va, size):
    c = collections.Counter(); o = collections.Counter()
    for ins in _dis.disasm(text[va - TVA: va - TVA + size], va):
        if ins.mnemonic in ("call", "jmp") or ins.mnemonic.startswith("j"): continue
        ops = ins.op_str
        for m in DISP.finditer(ops):
            if m[1] in ("esp", "ebp"): continue
            o[int(m[2].replace(" ", ""), 0)] += 1
        body = DISP.sub("", re.sub(r"\[[^\]]*\]", "", ops))
        for m in IMM.finditer(body):
            v = int(m[1], 0)
            if v >= 0x10000 and v < 0x80000000: continue   # addresses
            if v >= 0x80000000: v -= 1 << 32
            c[v] += 1
    return c, o
def score(pc, po, xc, xo):
    a = set(pc) - TRIV; b = set(xc) - TRIV
    c_ok = (len(a & b) / len(a)) if a else None
    ao = set(po) - {0}; bo = set(xo) - {0}
    o_ok = (len(ao & bo) / len(ao)) if ao else None
    return c_ok, o_ok
def accept(pn, va, size):
    pc, po = ps2_feat(pn); xc, xo = x_feat(va, size)
    a = set(pc) - TRIV; b = set(xc) - TRIV; ao = set(po) - {0}; bo = set(xo) - {0}
    ev = 0; ok = True
    if len(a) >= 1:
        f = len(a & b) / len(a); ok &= f >= 0.5; ev += len(a & b)
    if len(ao) >= 1:
        f = len(ao & bo) / len(ao); ok &= f >= 0.6; ev += len(ao & bo)
    return ok and ev >= 2, ev

# ---- call-argument signatures ------------------------------------------
PNAME = {a: n for n, (a, s) in pinfo.items()}
ARGREG = {4, 5, 6, 7, 8, 9, 10, 11}
def ps2_callargs(n):
    a, s = pinfo[n]; out = collections.Counter(); regs = {}
    x = a
    while x < a + s:
        w = PW(x); op = w >> 26; rs = (w >> 21) & 31; rt = (w >> 16) & 31
        imm = ((w & 0xFFFF) ^ 0x8000) - 0x8000
        if op in (9, 0x19) and rs == 0 and rt in ARGREG: regs[rt] = imm
        elif op == 0x0D and rs == 0 and rt in ARGREG: regs[rt] = w & 0xFFFF
        elif op == 0 and (w & 0x3F) in (0x2D, 0x25, 0x21) and ((w >> 11) & 31) in ARGREG and rs == 0 and rt == 0: regs[(w >> 11) & 31] = 0
        elif op == 3:
            # delay slot may set an arg too
            w2 = PW(x + 4); op2 = w2 >> 26; rs2 = (w2 >> 21) & 31; rt2 = (w2 >> 16) & 31
            if op2 in (9, 0x19) and rs2 == 0 and rt2 in ARGREG: regs[rt2] = ((w2 & 0xFFFF) ^ 0x8000) - 0x8000
            t = (w & 0x3FFFFFF) << 2
            out[(PNAME.get(t, "?"), tuple(sorted(v & 0xFFFF for v in regs.values())))] += 1
            regs = {}; x += 8; continue
        elif op in (4, 5, 6, 7, 1) or (op == 0 and (w & 0x3F) == 8): regs = {}
        x += 4
    return out
_PUSHIMM = re.compile(r"^(-?0x[0-9a-f]+|-?\d+)$")
def x_callargs(va, size, xnames):
    out = collections.Counter(); args = []; rc = {}
    L = _dis.disasm(text[va - TVA: va - TVA + size], va)
    for idx, ins in enumerate(L):
        m, o = ins.mnemonic, ins.op_str
        if m == "push" and idx + 1 < len(L) and L[idx + 1].mnemonic == "pop":
            rc[L[idx + 1].op_str] = int(o, 0) if _PUSHIMM.match(o) else None
            continue
        if m == "xor":
            p = [q.strip() for q in o.split(",")]
            if len(p) == 2 and p[0] == p[1]: rc[p[0]] = 0
        elif m == "mov":
            p = [q.strip() for q in o.split(",")]
            if len(p) == 2 and _PUSHIMM.match(p[1]): rc[p[0]] = int(p[1], 0)
            elif len(p) == 2: rc.pop(p[0], None)
        elif m == "or" and o.endswith(", 0xffffffff"): rc[o.split(",")[0].strip()] = -1
        elif m == "push":
            if _PUSHIMM.match(o):
                v = int(o, 0)
                if v >= 0x80000000: v -= 1 << 32
                if -0x8000 <= v < 0x10000: args.append(v)
            elif o in rc and -0x8000 <= rc[o] < 0x10000: args.append(rc[o])
        elif m == "call" and o.startswith("0x"):
            t = int(o, 16)
            out[(xnames.get(t, "?"), tuple(sorted(v & 0xFFFF for v in args)))] += 1
            args = []
        elif m in ("ret",) or m.startswith("j"): args = []
    return out
def callargs_match(n, va, size, xnames):
    p = ps2_callargs(n); x = x_callargs(va, size, xnames)
    # only compare call sites whose callee is named on both sides
    pk = collections.Counter({k: v for k, v in p.items() if k[0] != "?" and k[0] in set(xnames.values())})
    xk = collections.Counter({k: v for k, v in x.items() if k[0] != "?"})
    return pk == xk and sum(pk.values()) > 0, pk, xk
def callargs_veto(n, va, size, xnames):
    """True when an x86 call site to a named callee carries constant args that no
    PS2 call site to that callee has."""
    p = ps2_callargs(n); x = x_callargs(va, size, xnames)
    pset = {k for k in p}
    pnames = {k[0] for k in p}
    for k in x:
        if k[0] == "?" or k[0] not in pnames or not k[1]: continue
        if k not in pset:
            # allow subsets: shared tails can split args
            if not any(c == k[0] and set(k[1]) <= set(a) for c, a in pset): return True
    return False
def ps2_imm_pool(n):
    a, s = pinfo[n]; pool = set()
    for x in range(a, a + s, 4):
        w = PW(x); op = w >> 26
        if op in (8, 9, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x18, 0x19):
            pool.add(w & 0xFFFF); pool.add((-(((w & 0xFFFF) ^ 0x8000) - 0x8000)) & 0xFFFF)
        if op == 0x0F: pool.add(w & 0xFFFF)
        if op == 0 and (w & 0x3F) in (0, 2, 3): pool.add(1 << ((w >> 6) & 31) & 0xFFFF)
    return pool
def pushed_const_veto(n, va, size, xnames):
    pool = ps2_imm_pool(n)
    x = x_callargs(va, size, xnames)
    for (c, args), k in x.items():
        if c == "?": continue
        for v in args:
            if v in (0, 1, 0xFFFF, 2, 3, 4): continue
            if v not in pool: return True
    return False

# ---- control-flow extent ------------------------------------------------
_JT = re.compile(r"dword ptr \[(e\w\w)\*4 \+ (0x[0-9a-f]+)\]")
def cfg_extent(va, stop_starts=(), limit=0x4000):
    """End address of the function at va. Conditional branches and jump tables
    are followed. An unconditional jmp is followed only when its target lies
    inside the code reached so far (plus 0x20); otherwise it is a tail call."""
    stop = set(stop_starts) - {va}
    seen = set(); todo = [va]; deferred = set(); end = va
    def walk(x):
        nonlocal end
        while True:
            if x in seen or not (TVA <= x < TEND) or x - va > limit or x < va: return
            if x in stop: return
            ins = _dis.disasm(text[x - TVA: x - TVA + 16], x, 1)
            if not ins: return
            i = ins[0]; seen.add(x); end = max(end, i.address + i.size)
            m, o = i.mnemonic, i.op_str
            if m in ("ret", "int3", "hlt"): return
            if m == "jmp":
                if o.startswith("0x"):
                    t = int(o, 16)
                    if t not in stop and va <= t < va + limit: deferred.add(t)
                else:
                    jm = _JT.search(o)
                    if jm:
                        tb = int(jm[2], 16); k = 0
                        while k < 256:
                            try: v = struct.unpack("<I", img.bytes_at(tb + 4 * k, 4))[0]
                            except Exception: break
                            if not (va <= v < va + limit) or v in stop or (tb <= v < tb + 4 * (k + 1)): break
                            todo.append(v); k += 1
                        if va <= tb < va + limit: end = max(end, tb + 4 * k)
                return
            if m.startswith("j") and o.startswith("0x"):
                t = int(o, 16)
                if t not in stop and va <= t < va + limit: todo.append(t)
            x = i.address + i.size
    while True:
        while todo: walk(todo.pop())
        nxt = [t for t in deferred if t not in seen and (t <= end + 0x20 or (t <= end + 0x200 and not any(end <= q <= t for q in stop)))]
        if not nxt: break
        for t in nxt: deferred.discard(t); todo.append(t)
    return end
def padded_end(end, nextstart):
    x = end
    while x < nextstart and x - TVA < len(text) and text[x - TVA] in (0xCC, 0x90): x += 1
    return x
