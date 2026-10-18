# Name entries of stack-built function tables from the C initializers.
# A named XBE function F that stores function pointers into consecutive stack
# slots is matched with the local array initializer in F's PS2 C body:
#   void (*tbl[N])(...) = { a, b, ... };
# When the slot count equals the initializer length (or several arrays are
# concatenated in declaration order), entry i is named after the i-th
# initializer. Repeated initializer names must map to one address.
import os as _os, sys as _sys
_sys.path.insert(0, _os.path.dirname(_os.path.abspath(__file__)))
from ps2paths import OG as _OG, SP as _SP, PS as _PS
import sys, re, os, json, collections
D = (_SP + "/")
sys.path.insert(0, D)
from feat import *
from feat import _dis
OG = _OG
xn = {}; xs = {}
for l in open(OG + "/config/sf33rd/symbols/funcs.txt"):
    m = re.match(r"(\S+)\s*=\s*(0x[0-9A-Fa-f]+);.*size:(0x[0-9A-Fa-f]+)", l)
    if m: xn[int(m[2], 16)] = m[1]; xs[int(m[2], 16)] = int(m[3], 16)
byname = {v: k for k, v in xn.items()}
FOLD = {int(k, 16) for k in json.load(open(D + "folded.json"))}
# C initializers per function
INIT = re.compile(r"\(\s*\*\s*\w+\s*\[\s*\w*\s*\]\s*\)\s*\([^)]*\)\s*=\s*\{([^}]*)\}", re.S)
tabs = {}
for root, _, fs in os.walk(PS + "/src/anniversary"):
    for f in fs:
        if not f.endswith(".c"): continue
        t = open(os.path.join(root, f), errors="replace").read()
        for m in re.finditer(r"^[A-Za-z_][\w\s\*]*?\b(\w+)\s*\([^;{]*\)\s*\{", t, re.M):
            fn = m.group(1); i = m.end() - 1; depth = 0
            for j in range(i, len(t)):
                if t[j] == "{": depth += 1
                elif t[j] == "}":
                    depth -= 1
                    if depth == 0: break
            body = t[i:j]
            lists = [[x.strip() for x in g.split(",") if x.strip()] for g in INIT.findall(body)]
            if lists: tabs[fn] = lists
# global function-pointer arrays: name -> initializer list
GINIT = re.compile(r"\(\s*\*\s*(\w+)\s*\[\s*\w*\s*\]\s*\)\s*\([^)]*\)\s*=\s*\{([^}]*)\}", re.S)
gtabs = {}; fbody = {}
for root, _, fs in os.walk(PS + "/src/anniversary"):
    for f in fs:
        if not f.endswith(".c"): continue
        t = open(os.path.join(root, f), errors="replace").read()
        # strip function bodies to find file-scope arrays
        depth = 0; outside = []
        for ch in t:
            if ch == "{": depth += 1
            if depth == 0: outside.append(ch)
            elif depth == 1 and ch == "{" : outside.append("{")
            if ch == "}":
                depth -= 1
                if depth == 0: outside.append("}")
        for m in re.finditer(r"^[A-Za-z_][\w\s\*]*?\b(\w+)\s*\([^;{]*\)\s*\{", t, re.M):
            fn = m.group(1); i = m.end() - 1; d_ = 0
            for j in range(i, len(t)):
                if t[j] == "{": d_ += 1
                elif t[j] == "}":
                    d_ -= 1
                    if d_ == 0: break
            fbody.setdefault(fn, t[i:j])
        for m in GINIT.finditer(t):
            # file scope only: the match must not lie inside a function body
            pre = t[:m.start()]
            if pre.count("{") - pre.count("}") != 0: continue
            gtabs[m.group(1)] = [x.strip() for x in m.group(2).split(",") if x.strip()]
TBLREF = re.compile(r"dword ptr \[e\w\w\*4 \+ (0x[0-9a-f]+)\]")
def global_table_props():
    out = {}
    for va, fn in xn.items():
        body = fbody.get(fn)
        if not body: continue
        used_ = [g for g in gtabs if re.search(r"\b" + re.escape(g) + r"\s*\[", body)]
        if len(used_) != 1: continue
        addrs = {int(m_[1], 16) for ins in _dis.disasm(text[va - TVA: va - TVA + xs[va]], va) for m_ in [TBLREF.search(ins.op_str)] if m_}
        if len(addrs) != 1: continue
        ta = addrs.pop(); L = gtabs[used_[0]]
        try: ents = [struct.unpack("<I", img.bytes_at(ta + 4 * k, 4))[0] for k in range(len(L))]
        except Exception: continue
        if not all(TVA <= e < TEND for e in ents): continue
        out[fn] = list(zip(ents, L))
    return out
GPAIRS = global_table_props()
def stack_table(va, size):
    slots = {}
    for ins in _dis.disasm(text[va - TVA: va - TVA + size], va):
        if ins.mnemonic != "mov": continue
        m = re.match(r"dword ptr \[(ebp|esp)\s*([+-])\s*(0x[0-9a-f]+|\d+)\], (0x[0-9a-f]+|e\w\w)$", ins.op_str)
        if m:
            off = int(m[3], 0) * (-1 if m[2] == "-" else 1)
            v = m[4]
            slots[(m[1], off)] = v
    # resolve register sources: mov reg, imm earlier
    regs = {}; out = {}
    for ins in _dis.disasm(text[va - TVA: va - TVA + size], va):
        if ins.mnemonic == "mov":
            p = [q.strip() for q in ins.op_str.split(",")]
            if len(p) == 2 and re.match(r"^e\w\w$", p[0]) and re.match(r"^0x[0-9a-f]+$", p[1]): regs[p[0]] = int(p[1], 16)
            m = re.match(r"dword ptr \[(ebp|esp)\s*([+-])\s*(0x[0-9a-f]+|\d+)\], (0x[0-9a-f]+|e\w\w)$", ins.op_str)
            if m:
                off = int(m[3], 0) * (-1 if m[2] == "-" else 1)
                v = int(m[4], 16) if m[4].startswith("0x") else regs.get(m[4])
                if v is not None and TVA <= v < TEND: out[(m[1], off)] = v
    return [out[k] for k in sorted(out)]
prop = {}; bad = set(); used = 0
for va, fn in xn.items():
    if fn not in tabs: continue
    vals = stack_table(va, xs[va])
    flat = [x for L in tabs[fn] for x in L]
    if not vals or len(vals) != len(flat): continue
    pairs = list(zip(vals, flat))
    # consistency: one name per address, one address per name; agree with known names
    a2n = collections.defaultdict(set); n2a = collections.defaultdict(set)
    for a, n in pairs: a2n[a].add(n); n2a[n].add(a)
    if any(len(v) > 1 for v in n2a.values()): continue
    if any(a in xn and xn[a] not in ns and a not in FOLD for a, ns in a2n.items()): continue
    used += 1
    for a, ns in a2n.items():
        if len(ns) > 1 or a in xn or a in FOLD: continue
        n = next(iter(ns))
        if n not in pinfo or n in byname: continue
        if a in prop and prop[a] != n: bad.add(a)
        prop[a] = n
for fn, pairs in GPAIRS.items():
    a2n = collections.defaultdict(set); n2a = collections.defaultdict(set)
    for a, n in pairs: a2n[a].add(n); n2a[n].add(a)
    if any(a in xn and xn[a] not in ns and a not in FOLD for a, ns in a2n.items()): continue
    used += 1
    for a, ns in a2n.items():
        if len(ns) > 1:
            continue
        n = next(iter(ns))
        if len(n2a[n]) > 1 or a in xn or a in FOLD or n not in pinfo or n in byname: continue
        if a in prop and prop[a] != n: bad.add(a)
        prop[a] = n
for a in bad: prop.pop(a, None)
cnt = collections.Counter(prop.values())
prop = {a: n for a, n in prop.items() if cnt[n] == 1}
print("functions with stack tables matched", used, "new names", len(prop))
json.dump({hex(a): n for a, n in sorted(prop.items())}, open(D + "localtabs.json", "w"))
