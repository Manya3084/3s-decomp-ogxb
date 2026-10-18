# Per-function comparison of an XBE body with its PS2 namesake, for ports.
# Flags what the x86 has that the PS2 build does not: callees, non-trivial
# constants (with +-1 for compare rewrites), field offsets, globals, and
# pushed call arguments. Usage: portcheck.py NAME... | --file Game/X.c
import os as _os, sys as _sys
_sys.path.insert(0, _os.path.dirname(_os.path.abspath(__file__)))
from ps2paths import OG as _OG, SP as _SP, PS as _PS
import sys, re, json, struct, bisect, collections, os
sys.path.insert(0, _SP)
from feat import img, text, TVA, PW, pinfo, _dis, ps2_feat, x_feat, ps2_imm_pool, x_callargs, ps2_callargs, TRIV
OG = _OG; PS = _PS
xf = {}; xa = {}
for l in open(OG + "/config/sf33rd/symbols/funcs.txt"):
    m = re.match(r"(\S+)\s*=\s*(0x[0-9A-Fa-f]+);.*size:(0x[0-9A-Fa-f]+)", l)
    if m: xf[m[1]] = (int(m[2], 16), int(m[3], 16)); xa[int(m[2], 16)] = m[1]
FOLD = json.load(open(OG + "/analysis-ps2map/folded.json"))
folded = {int(k, 16) for k in FOLD}
# XBE data names with sizes
dn = []
for l in open(OG + "/config/sf33rd/symbols/data.txt"):
    m = re.match(r"(\S+) = (0x[0-9A-Fa-f]+); // type:data(?: size:(0x[0-9A-Fa-f]+))?", l)
    if m: dn.append((int(m[2], 16), int(m[3], 16) if m[3] else 1, m[1]))
dn.sort(); dstart = [a for a, _, _ in dn]
def xsym(a):
    i = bisect.bisect_right(dstart, a) - 1
    if i >= 0 and dn[i][0] <= a < dn[i][0] + max(dn[i][1], 1): return dn[i][2]
    return None
# PS2 debug ELF data references
d = open(PS + "/THIRD_U.BIN", "rb").read()
def dW(a): return struct.unpack_from("<I", d, 0x80 + a - 0x100000)[0]
GP = 0x57A3F0
dfun = {}; ddata = []
for l in open(PS + "/config/anniversary/symbols/syms_sfiii.txt"):
    m = re.match(r"(\S+) = (0x[0-9A-Fa-f]+);\s*//(.*)", l)
    if not m: continue
    a = int(m[2], 16); c = m[3]
    if "type:func" in c: dfun[m[1]] = a
    else:
        sz = re.search(r"size:(0x[0-9A-Fa-f]+)", c)
        ddata.append((a, int(sz[1], 16) if sz else 1, m[1]))
ddata.sort(); ds = [a for a, _, _ in ddata]
fad = sorted(dfun.values()); fnext = {a: (fad[i + 1] if i + 1 < len(fad) else a + 0x400) for i, a in enumerate(fad)}
def dsym(a):
    i = bisect.bisect_right(ds, a) - 1
    if i >= 0 and ddata[i][0] <= a < ddata[i][0] + max(ddata[i][1], 1): return ddata[i][2]
    return None
def ps2_globals(n):
    if n not in dfun: return None
    a = dfun[n]; out = set(); hi = {}
    for x in range(a, min(fnext[a], a + 0x8000), 4):
        w = dW(x); op = w >> 26; rs = (w >> 21) & 31; rt = (w >> 16) & 31; imm = ((w & 0xFFFF) ^ 0x8000) - 0x8000
        if op == 0x0F: hi[rt] = (w & 0xFFFF) << 16; continue
        if op in (9, 0x20, 0x21, 0x23, 0x24, 0x25, 0x27, 0x28, 0x29, 0x2B, 0x31, 0x39, 0x37, 0x3F, 0x1E, 0x1F):
            base = hi.get(rs) if rs in hi else (GP if rs == 28 else None)
            if base is not None:
                s = dsym((base + imm) & 0xFFFFFFFF)
                if s: out.add(s)
        if op not in (0x28, 0x29, 0x2B, 0x3F, 0x39): hi.pop(rt, None)
    return out
paddr = {a: n for n, (a, s) in pinfo.items()}
def pcallees(n):
    a, s = pinfo[n]; out = collections.Counter()
    for x in range(a, a + s, 4):
        w = PW(x); op = w >> 26
        if op in (2, 3):
            t = (x & 0xF0000000) | ((w & 0x3FFFFFF) << 2)
            if t in paddr and not (a <= t < a + s): out[paddr[t]] += 1
    return out
CTAB = {}
def code_size(va, sz):
    # stop before a jump table that sits inside the function's extent
    end = va + sz
    for i in _dis.disasm(text[va - TVA: va - TVA + sz], va):
        if i.address >= end: break
        m = re.search(r"\*4 \+ (0x[0-9a-f]+)\]", i.op_str)
        if m and i.mnemonic in ("jmp", "mov", "movzx", "movsx"):
            tb = int(m[1], 16)
            if va < tb < end: end = tb
    return end - va
def check(n):
    va, sz = xf[n]; rep = []
    sz = code_size(va, sz)
    ins = list(_dis.disasm(text[va - TVA: va - TVA + sz], va))
    # callees
    xc = collections.Counter(); unk = collections.Counter()
    gl = collections.Counter(); ung = collections.Counter(); gaddr = {}; ctab = set()
    for i in ins:
        if i.mnemonic in ("call", "jmp") and re.fullmatch(r"0x[0-9a-f]+", i.op_str):
            t = int(i.op_str, 16)
            if va <= t < va + sz: continue
            if t in xa: xc[xa[t]] += 1
            elif t in folded:
                for fn_ in FOLD[hex(t)]: xc[fn_] += 1
            else: unk[hex(t)] += 1
            continue
        for h in re.findall(r"0x[0-9a-f]+", i.op_str):
            v = int(h, 16)
            if 0x218DC0 <= v < 0xD20000 and v.to_bytes(4, "little") in text[i.address - TVA:i.address - TVA + i.size]:
                if i.mnemonic == "mov" and re.search(r"\+ 0x1ac\], " + h + "$", i.op_str):
                    ctab.add(v); continue
                s = xsym(v)
                if s: gl[s] += 1; gaddr[s] = v
                else: ung[hex(v)] += 1
    pc = pcallees(n) if n in pinfo else collections.Counter()
    extra = [c for c in xc if c not in pc and not any(c in FOLD.get(hex(t_), ()) for t_ in folded if c in FOLD.get(hex(t_), ()))]
    missing = [c for c in pc if c not in xc and not re.match(r"^(fptodp|litodp|dptofp|dptoli|dptoul|fptoli|litofp|dpadd|dpsub|dpmul|dpdiv|dpcmp|dpneg|__\w+)$", c)]
    if extra: rep.append("x86-only callees " + ",".join(extra))
    if missing and sum(pc[c] for c in missing) > sum(unk.values()):
        rep.append("PS2-only callees " + ",".join(missing))
    if n in pinfo:
        pcn, pon = ps2_feat(n); xcn, xon = x_feat(va, sz)  # sz is the code size here
        for i in ins:
            if i.mnemonic in ("add", "sub") and i.op_str.startswith("esp, "):
                v = int(i.op_str.split(", ")[1], 0); xcn[v] -= 1
                if xcn[v] <= 0: del xcn[v]
        for v in (0x700, 0x388, 0x46C, 0x90):
            xcn.pop(v, None)
        pool = ps2_imm_pool(n) | {v & 0xFFFF for v in pcn}
        near = lambda v: any(((v + k) & 0xFFFF) in pool for k in (-1, 0, 1))
        bc = sorted(v for v in xcn if v not in TRIV and not near(v) and not (-1 <= v <= 16))
        if bc: rep.append("x86-only constants " + ",".join(hex(v) if abs(v) > 9 else str(v) for v in bc[:12]))
        po = set(pon)
        bo = sorted(v for v in xon if v not in po and v != 0 and abs(v) < 0x2000)
        if bo: rep.append("x86-only offsets " + ",".join(hex(v) for v in bo[:12]))
    pg = ps2_globals(n)
    if pg is not None:
        # an address up to 0x400 below or inside a PS2-referenced global is that global
        base = {nm: (a, s) for a, s, nm in dn}
        def near_pg(addr):
            return any(g in base and base[g][0] - 0x400 <= addr < base[g][0] + max(base[g][1], 1) for g in pg)
        for h in list(ung):
            if near_pg(int(h, 16)): del ung[h]
        eg = [g for g in gl if g not in pg and not near_pg(gaddr[g]) and not re.search(r"_char_table$|_panel_table$|^cookie$", g)]
        if eg: rep.append("x86-only globals " + ",".join(eg))
    if ung: rep.append("unnamed data " + ",".join(sorted(ung)[:8]))
    CTAB[n] = ctab
    return rep
if __name__ == "__main__":
    names = sys.argv[1:]
    if names and names[0] == "--file":
        t = open(f"{OG}/src/sf33rd/Source/{names[1]}").read().split(" */", 1)[0]
        names = re.findall(r"^ \* (\w+)(?: is)? 0x[0-9A-F]+ size", t, re.M)
    for n in names:
        if n not in xf: print(n, "not named"); continue
        r = check(n); print(n, "CLEAN" if not r else "| " + " | ".join(r))
