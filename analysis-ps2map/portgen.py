# Generate a port draft for one PS2-copy placeholder file.
# Usage: portgen.py Game/X.c [--write]
import os as _os, sys as _sys
_sys.path.insert(0, _os.path.dirname(_os.path.abspath(__file__)))
from ps2paths import OG as _OG, SP as _SP, PS as _PS
import sys, re, json, os, subprocess, struct, collections, tempfile
sys.argv_saved = sys.argv; sys.argv = ["x"]
OG = _OG; PS = _PS
SP = OG + "/analysis-ps2map"
sys.path.insert(0, SP)
_src = open(SP + "/callalign.py").read(); exec(_src[:_src.index("accepted = {}")])
_src = open(SP + "/callalign.py").read(); exec(_src[_src.index("def align("):_src.index("for rnd in range(200):")].replace("for rnd in range(200):", ""))
import portcheck
sys.argv = sys.argv_saved
IDX = json.load(open(SP + "/declidx.json"))
rel = sys.argv[1]; WRITE = "--write" in sys.argv
path = f"{OG}/src/sf33rd/Source/{rel}"
T = open(path).read()
hdr, body = T.split(" */", 1)
assert "PlayStation 2 C, not hand-adjusted" in hdr
entries = [(m[1], int(m[2], 16), int(m[3], 16)) for m in re.finditer(r"^ \* (\w+) 0x([0-9A-F]+) size 0x([0-9A-F]+)\.$", hdr, re.M)]
foldl = re.findall(r"^ \* ((\w+) is folded into 0x[0-9A-F]+.*)$", hdr, re.M)
located = {n for n, _, _ in entries}
FOLDAT = {}
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
def ptwin(a, b):
    return a in pinfo and b in pinfo and a != b and pmask(a) == pmask(b)
for r_, _, fs_ in os.walk(OG + "/src"):
    for f_ in fs_:
        h_ = open(os.path.join(r_, f_), errors="replace").read(6000).split(" */", 1)[0]
        for m_ in re.finditer(r"(\w+) is folded into 0x([0-9A-F]+)", h_): FOLDAT.setdefault(m_[1], int(m_[2], 16))
xname = {va: n for va, (n, _) in xf.items()}
dnames = {}
for l in open(OG + "/config/sf33rd/symbols/data.txt"):
    m = re.match(r"(\S+) = (0x[0-9A-Fa-f]+); // type:data(?: size:(0x[0-9A-Fa-f]+))?", l)
    if m: dnames[m[1]] = (int(m[2], 16), int(m[3], 16) if m[3] else None)

# ---- split the PS2 C into top-level items -----------------------------
def items_of(src):
    out = []; i = 0; n = len(src); start = 0; depth = 0
    while i < n:
        c = src[i]
        if src.startswith("/*", i): i = src.index("*/", i) + 2; continue
        if src.startswith("//", i): i = src.find("\n", i); i = n if i < 0 else i; continue
        if c == '"':
            i += 1
            while src[i] != '"': i += 2 if src[i] == "\\" else 1
            i += 1; continue
        if c == "'":
            i += 1
            while src[i] != "'": i += 2 if src[i] == "\\" else 1
            i += 1; continue
        if c == "#" and depth == 0 and (i == 0 or src[i - 1] == "\n"):
            j = src.find("\n", i)
            while j != -1 and src[j - 1] == "\\": j = src.find("\n", j + 1)
            j = n if j == -1 else j
            if src[start:i].strip(): out.append(("text", src[start:i]))
            out.append(("pp", src[i:j])); i = j + 1; start = i; continue
        if c == "{": depth += 1
        elif c == "}":
            depth -= 1
            if depth == 0:
                head = src[start:src.index("{", start)] if "{" in src[start:i] else ""
                hs = re.sub(r"\s+", " ", re.sub(r"/\*.*?\*/|//[^\n]*", "", head, flags=re.S)).strip()
                isfunc = "(" in hs and "=" not in hs and not re.match(r"^(typedef|struct|union|enum)\b", hs)
                if isfunc:
                    out.append(("func", src[start:i + 1])); start = i + 1
        elif c == ";" and depth == 0:
            d_ = src[start:i + 1].strip()
            while True:
                m_ = re.match(r"^(//[^\n]*\n|/\*.*?\*/)\s*", d_, re.S)
                if not m_: break
                d_ = d_[m_.end():]
            out.append(("decl", d_)); start = i + 1
        i += 1
    if src[start:].strip(): out.append(("text", src[start:]))
    return out
items = items_of(body)
def fname(t):
    t = re.sub(r"/\*.*?\*/|//[^\n]*", "", t, flags=re.S)
    m = re.search(r"\b([A-Za-z_]\w*)\s*\([^;{]*\)\s*\{", t, re.S)
    return m[1] if m else None
funcs = [(fname(t), t.strip()) for k, t in items if k == "func" and fname(t)]
decls = [t.strip() for k, t in items if k == "decl"]
localtypes = [d for d in decls if re.match(r"^(typedef\b|struct\s+\w+\s*\{|union\s+\w+\s*\{|enum\b)", re.sub(r"\s+", " ", d))]
pps = [t for k, t in items if k == "pp" and not t.startswith("#include")]
defined_here = {n for n, _ in funcs}

# ---- callee mapping per located function --------------------------------
notes_callee = {}; rename = {}; pairs1 = []; newnames_pre = []
FOLDNAME0 = {n_ for L_ in json.load(open(SP + "/folded.json")).values() for n_ in L_}
inl = set()
for n, va, sz in entries:
    if n not in pinfo: continue
    R, C = xcalls(va, sz); P = pcalls(n)
    al = pick(R, C, P, xname, set(xname.values()) | set(P)) or []
    got = {p for x, p, k in al if k}
    for x, p, k in al:
        if not k and p not in portcheck.xf:
            nm = f"sub_{x:08X}"
            rename.setdefault(p, nm)
            notes_callee[p] = f"{p} is folded into 0x{x:X}" if x in folded else f"{p} stays {nm}"
    for p in P:
        if p not in portcheck.xf and p not in rename and p not in got: inl.add(p)
    # one unnamed x86 target left and one unplaced PS2 callee left: a pair
    ux = {x for x in R if x not in xname and x not in folded and f"sub_{x:08X}" not in rename.values()}
    up = {p for p in P if p not in portcheck.xf and p not in rename and p not in got and p not in FOLDNAME0}
    if len(ux) == 1 and len(up) == 1:
        x = ux.pop(); p = up.pop()
        pairs1.append((p, x))
for p, x in pairs1:
    if p in rename: continue
    nm = f"sub_{x:08X}"; rename[p] = nm; inl.discard(p)
    notes_callee[p] = f"{p} stays {nm}, the one unnamed call left in its caller"
    if p in [n for n, _ in funcs]: newnames_pre.append((p, x))
# folded callees: the body is known even when alignment did not pin the call
FOLDNAME = {}
for k_, L_ in json.load(open(SP + "/folded.json")).items():
    for n_ in L_: FOLDNAME.setdefault(n_, int(k_, 16))
for p in sorted(inl):
    if p in FOLDNAME and p not in rename:
        rename[p] = f"sub_{FOLDNAME[p]:08X}"; notes_callee[p] = f"{p} is folded into 0x{FOLDNAME[p]:X}"
# unnamed callees that alignment could not place: still need a note
for p in sorted(inl):
    if p not in rename: notes_callee.setdefault(p, f"{p} has no XBE name and no aligned call")

# ---- data definitions ----------------------------------------------------
def gcc(src, extra=()):
    with tempfile.NamedTemporaryFile("w", suffix=".c", delete=False, dir="/tmp/claude-1000") as f:
        f.write(src); fn = f.name
    r = subprocess.run(["gcc", "-m32", "-std=gnu17", "-fsyntax-only", "-Werror=implicit-function-declaration", "-Werror=implicit-int",
                        "-Werror=int-conversion", "-Wno-incompatible-pointer-types", "-I" + OG + "/include", fn, *extra], capture_output=True, text=True)
    os.unlink(fn); return r.stderr
def dump_bytes(prelude, decl, name):
    src = prelude + "\n" + decl + "\nint printf(const char*, ...);\nint main(void){const unsigned char*p=(const unsigned char*)&" + name + ";for(unsigned i=0;i<sizeof(" + name + ");i++)printf(\"%02x\",p[i]);return 0;}\n"
    with tempfile.TemporaryDirectory(dir="/tmp/claude-1000") as td:
        open(td + "/d.c", "w").write(src)
        r = subprocess.run(["gcc", "-m32", "-std=gnu17", "-w", "-I" + OG + "/include", td + "/d.c", "-o", td + "/d"], capture_output=True, text=True)
        if r.returncode: return None
        return bytes.fromhex(subprocess.run([td + "/d"], capture_output=True, text=True).stdout)
datanotes = []; datakeep = []; dataext = []; found = []; newnames = list(newnames_pre); newfolds = []; refold = []
for d in decls:
    one = re.sub(r"\s+", " ", d)
    if re.fullmatch(r"extern \w+;", one): continue
    if one.startswith("extern") or one.startswith("typedef") or "(" in one.split("=")[0] and "(*" not in one.split("=")[0]:
        continue
    lhs = one.split("=")[0]
    m = re.search(r"\(\s*\*\s*(?:const\s+)?(\w+)\s*(?:\[[^\]]*\]\s*)*\)", lhs) or re.search(r"([A-Za-z_]\w*)\s*(?:\[[^\]]*\]\s*)*;?\s*$", lhs.strip().rstrip(";"))
    if not m: datakeep.append((None, d, "?")); continue
    nm = m[1]
    datakeep.append((nm, d, None))
# verified later, once declarations resolve
# ---- assemble -------------------------------------------------------------
# folds recorded in folded.json for functions defined here
_FOJ = json.load(open(SP + "/folded.json"))
_have = {n for _, n in foldl}
for _a, _ns in sorted(_FOJ.items()):
    for _n in _ns:
        if _n in dict(funcs) and _n not in located and _n not in _have:
            foldl.append((f"{_n} is folded into 0x{int(_a, 16):X} with {len(_ns) - 1} other bodies. Unnamed.", _n)); _have.add(_n)
foldnames = {n for _, n in foldl}
# Xbox rewrites kept outside the generated file: overrides/<File>.c holds
# whole function definitions that replace the PS2 ones.
OVR = {}; OVRDECL = []; OVRDATA = {}
_op = SP + "/overrides/" + os.path.basename(rel)
if os.path.exists(_op):
    for k_, t_ in items_of(open(_op).read()):
        if k_ == "func" and fname(t_): OVR[fname(t_)] = t_.strip()
        elif k_ != "pp" and "=" in re.sub(r"/\*.*?\*/|//[^\n]*", "", t_, flags=re.S):
            # an Xbox data definition: it replaces the PS2 one of that name
            lhs_ = re.sub(r"/\*.*?\*/|//[^\n]*", "", t_, flags=re.S).split("=")[0]
            m_ = re.search(r"([A-Za-z_]\w*)\s*(?:\[[^\]]*\]\s*)*$", lhs_.strip())
            if m_: OVRDATA[m_[1]] = t_.strip()
        elif k_ != "pp":
            # declarations the rewrites need; each replaces a generated one
            for l_ in re.sub(r"/\*.*?\*/|//[^\n]*", "", t_, flags=re.S).split(";"):
                l_ = re.sub(r"\s+", " ", l_).strip()
                if l_: OVRDECL.append(l_ + ";")
    funcs = [(n_, OVR.get(n_, t_)) for n_, t_ in funcs]
    datakeep = [(n_, OVRDATA.get(n_, d_), x_) if n_ in OVRDATA and "=" in d_ else (n_, d_, x_) for n_, d_, x_ in datakeep]
loc_funcs = [(n, t) for n, t in funcs if n in located or n in foldnames]
unloc = [(n, t) for n, t in funcs if n not in located and n not in foldnames]
def strip_ps2_local_protos(t):
    return re.sub(r"#if defined\(TARGET_PS2\)\n(?:[^\n]*\);\n)+#endif\n\n?", "", t)
def apply_rename(t):
    # rename calls only: a function definition keeps its own name
    head = ""
    m_ = re.match(r"^([A-Za-z_][\w \*]*\b\w+\s*\([^;{]*\)\s*)\{", t)
    if m_: head, t = m_[1], t[len(m_[1]):]
    for p, x in rename.items():
        t = re.sub(r"\b" + re.escape(p) + r"\b(?=\s*\()", x, t)
    return head + t
ps2blocks = []
PS2ONLY = re.compile(r"__asm__|\bsce[A-Z]\w*|\bSCE[A-Z]\w*|\bps2slot\b|\bsceGs|\bsceVu0")
def resolve_ps2(t, fn_name):
    # The Xbox build compiled the original source, which is the PS2 side of
    # these blocks, unless that side uses PS2-only facilities.
    def blk(m):
        neg, a, b = m[1] == "!", m[2], m[3]
        ps2, other = (b, a) if neg else (a, b)
        if ps2 is None: ps2 = ""
        if other is None: other = ""
        if PS2ONLY.search(ps2):
            ps2blocks.append(f"{fn_name}: kept the portable side of a TARGET_PS2 block (the PS2 side uses PS2-only calls)")
            return other
        if other.strip():
            ps2blocks.append(f"{fn_name}: kept the PS2 side of a TARGET_PS2 block")
        return ps2
    pat = re.compile(r"#if\s+(!?)defined\(TARGET_PS2\)\n(.*?)(?:#else\n(.*?))?#endif\n", re.S)
    return pat.sub(blk, t)
# Xbox-wide change: every FadeIn/FadeOut call passes priority 1 where the
# PS2 C passes 8 (PrioBase index; all literal call sites in the XBE push 1).
FADE_RE = re.compile(r"\b(Fade(?:In|Out))\(([^,()]+),\s*([^,()]+),\s*8\)")
fade_fixed = []
def xbox_rules(t, n):
    t2 = FADE_RE.sub(r"\1(\2, \3, 1)", t)
    if t2 != t: fade_fixed.append(n)
    return t2
loc_text = [xbox_rules(apply_rename(resolve_ps2(strip_ps2_local_protos(t), n)), n) for n, t in loc_funcs]
localdefs = set()
for lt in localtypes:
    one_ = re.sub(r"\s+", " ", lt)
    m_ = re.search(r"\}\s*(\w+)\s*;$", one_) or re.search(r"typedef .*?\b(\w+)\s*(?:\[[^\]]*\])*\s*;$", one_)
    if m_: localdefs.add(m_[1])
    m_ = re.match(r"^(?:typedef\s+)?(struct|union|enum)\s+(\w+)", one_)
    if m_: localdefs.add(m_[2])
    if one_.startswith("enum") or "enum {" in one_:
        localdefs |= set(re.findall(r"[{,]\s*([A-Za-z_]\w*)", one_))
proto_lines = []; declset = []
def add(line):
    if line not in declset: declset.append(line)
_cnt = collections.Counter(rename.values())
for p, x in rename.items():
    pr = IDX["func"].get(p)
    if _cnt[x] > 1:
        m_ = re.match(r"^(.*?)\b" + re.escape(p) + r"\s*\(", pr or "")
        add(re.sub(r"^static\s+", "", (m_[1] if m_ else "void ")) + x + "();")
    elif pr: add(re.sub(r"^static\s+", "", re.sub(r"\b" + re.escape(p) + r"\b", x, pr, count=1)))
def decl_id(d_):
    m_ = re.search(r"\b(\w+)\s*(?:\(|\[|;)", d_)
    return m_[1] if m_ else None
for d_ in OVRDECL:
    declset[:] = [x for x in declset if decl_id(x) != decl_id(d_)]
    add(d_)
macros = [pp for pp in pps if pp.startswith("#define")]
other_pp = [pp for pp in pps if not pp.startswith("#define")]
def assemble(datablock):
    istype = lambda x: bool(re.match(r"^(typedef\b|enum\b|struct\s+\w+\s*\{|union\s+\w+\s*\{)", x))
    tdecl = [x for x in declset if istype(x)]; odecl = [x for x in declset if not istype(x)]
    return ("#include \"structs.h\"\n\n" + "\n".join(macros) + ("\n\n" if macros else "") + "\n\n".join(tdecl) + ("\n\n" if tdecl else "")
            + "\n\n".join(localtypes) + ("\n\n" if localtypes else "") + "\n".join(odecl) + "\n\n" + datablock + "\n\n" + "\n\n".join(loc_text) + "\n")
datablock = "\n\n".join(d for _, d, _ in datakeep)
# resolve declarations
def resolve_decls(datablock):
    moved = collections.Counter()
    for it in range(400):
        err = gcc(assemble(datablock))
        need = []
        for m in re.finditer(r"‘(\w+)’ undeclared|implicit declaration of function ‘(\w+)’|unknown type name ‘(\w+)’|storage size of ‘\w+’ isn’t known|field ‘\w+’ has incomplete type", err):
            need.append(m[1] or m[2] or m[3])
        need = [x for x in need if x]
        fixed = False
        for m in re.finditer(r"too (?:few|many) arguments to function ‘(\w+)’", err):
            x = m[1]
            for k_, dl in enumerate(declset):
                mm = re.match(r"^(.*?\b" + re.escape(x) + r")\s*\(.*\);$", dl)
                if mm and not dl.endswith(x + "();"):
                    declset[k_] = mm[1] + "();"; fixed = True
        if fixed: continue
        if not need: break
        progress = False
        for x in dict.fromkeys(need):
            cand = None
            if x in localdefs: continue
            if x in defined_here:
                t = dict(funcs)[x]; cand = re.sub(r"\s+", " ", re.sub(r"/\*.*?\*/|//[^\n]*", "", t[:t.index("{")], flags=re.S)).strip() + ";"
            for kind in ("type", "enum", "macro", "var", "func"):
                if cand: break
                if x in IDX[kind]: cand = IDX[kind][x]
            if x.startswith("sub_"):
                cand = f"void {x}();"
            if cand and cand in declset and re.match(r"^(typedef\b|enum\b|struct\s+\w+\s*\{|union\s+\w+\s*\{)", cand) and moved[cand] < 20:
                declset.remove(cand); declset.insert(0, cand); moved[cand] += 1; progress = True
                continue
            if cand and cand not in declset and cand not in localtypes:
                if cand.startswith("#define"): macros.append(cand)
                elif re.match(r"^(typedef\b|enum\b|struct\s+\w+\s*\{|union\s+\w+\s*\{)", cand): declset.insert(0, cand)
                else: declset.append(cand)
                progress = True
        if not progress: break

resolve_decls(datablock)
err = gcc(assemble(datablock))
# ---- verify file data against the XBE -------------------------------------
prelude = "#include \"structs.h\"\n" + "\n".join(macros) + "\n" + "\n".join(x for x in declset if not x.startswith("extern"))
final_data = []
unref = set()
for n_, va_, sz_ in entries:
    for i in _dis.disasm(text[va_ - TVA: va_ - TVA + sz_], va_):
        for h in re.findall(r"0x[0-9a-f]+", i.op_str):
            v = int(h, 16)
            if 0x218DC0 <= v < 0xD20000 and not re.fullmatch(r"0x[0-9a-f]+", i.op_str) and portcheck.xsym(v) is None: unref.add(v)
def bytesearch(b):
    hits = set()
    for c in unref:
        for k in range(-0x100, min(len(b), 0x200) + 1, 1):
            a = c - k
            try:
                if img.bytes_at(a, len(b)) == b: hits.add(a)
            except Exception: pass
    return hits
_order = sorted(range(len(datakeep)), key=lambda i_: 0 if ("=" in datakeep[i_][1] and re.search(r"\*\s*(?:const\s+)?\w+\s*\[", datakeep[i_][1].split("=")[0]) and not re.search(r"\(\s*\*", datakeep[i_][1].split("=")[0])) else 1)
_slots = {}
class _FD(list):
    def append(self, x): _slots[_cur[0]] = x
_cur = [0]
final_data = _FD()
for _i in _order:
    _cur[0] = _i
    nm, d, _ = datakeep[_i]
    if nm is None: final_data.append(d); continue
    addr = dnames.get(nm, (None,))[0]
    ext = IDX["var"].get(nm) or ("extern " + d.split("=")[0].strip().rstrip(";") + ";")
    if "=" not in d and any(n2 == nm and "=" in d2 for n2, d2, _ in datakeep):
        final_data.append(d); continue   # forward declaration, kept in place
    if "=" not in d:
        final_data.append(ext); datanotes.append(f"{nm}: defined elsewhere on Xbox" if addr is None else f"{nm} 0x{addr:X}"); continue
    # table of pointers to data arrays defined in this file
    elems = re.findall(r"\b([A-Za-z_]\w*)\b", d.split("=", 1)[1]) if "=" in d else []
    datanames = {n2 for n2, d2, _ in datakeep if n2 and "=" in d2 and n2 != nm}
    if elems and all(e in datanames for e in elems) and re.search(r"\*\s*(?:const\s+)?" + re.escape(nm) + r"\s*\[", d.split("=")[0]):
        eb = {}
        for e in set(elems):
            de = next(d2 for n2, d2, _ in datakeep if n2 == e and "=" in d2)
            eb[e] = dump_bytes(prelude, de, e)
        def dpok(a0):
            try:
                for k, e in enumerate(elems):
                    v = struct.unpack("<I", img.bytes_at(a0 + 4 * k, 4))[0]
                    if eb[e] is None or img.bytes_at(v, len(eb[e])) != eb[e]: return False
                return True
            except Exception: return False
        cands = [addr] if addr is not None else sorted(unref)
        hits = [c for c in cands if dpok(c)]
        if len(hits) == 1:
            a0 = hits[0]
            if addr is None: found.append((nm, a0, 4 * len(elems)))
            datanotes.append(f"{nm} is 0x{a0:X}, {len(elems)} pointers whose arrays were compared")
            for k, e in enumerate(elems):
                v = struct.unpack("<I", img.bytes_at(a0 + 4 * k, 4))[0]
                if e not in dnames and all(e != f_[0] for f_ in found): found.append((e, v, len(eb[e]))); datanotes.append(f"{e} is 0x{v:X}, 0x{len(eb[e]):X} bytes compared")
            final_data.append(d); continue
    fptr = re.search(r"\(\s*\*", d.split("=")[0])
    if not fptr:
        # an array whose element type is a function-pointer typedef
        tn_ = re.findall(r"\b([A-Za-z_]\w*)\s+\**\s*" + re.escape(nm) + r"\s*\[", d.split("=")[0])
        fptr = bool(tn_) and re.search(r"typedef[^;]*\(\s*\*\s*" + re.escape(tn_[0]) + r"\s*\)", prelude)
    if fptr:
        names = [w for w in re.findall(r"\b([A-Za-z_]\w*)\b", d.split("=", 1)[1]) if w not in ("NULL",)]
        def fpok(a0):
            good = 0
            for k, w in enumerate(names):
                try: v = struct.unpack("<I", img.bytes_at(a0 + 4 * k, 4))[0]
                except Exception: return False
                xn_ = xname.get(v)
                if xn_ == w or FOLDAT.get(w) == v: good += 1; continue
                if xn_ is not None and ptwin(w, xn_): continue
                if w not in portcheck.xf and w not in FOLDAT and (v in folded or (xn_ is None and 0x11000 <= v < 0x190000)): continue
                return False
            return good >= need_good
        need_good = 1
        if addr is None:
            hits = {c + 4 * k for c in unref for k in range(-64, 65) if fpok(c + 4 * k)}
            if len(hits) > 1 and len(hits & unref) == 1: hits = hits & unref
            if not hits:
                own = set()
                for n_, va_, sz_ in entries:
                    if not re.search(r"\b" + re.escape(nm) + r"\b", dict(funcs).get(n_, "")): continue
                    for i in _dis.disasm(text[va_ - TVA: va_ - TVA + sz_], va_):
                        mm = re.search(r"\*4 \+ (0x[0-9a-f]+)\]", i.op_str)
                        if mm and portcheck.xsym(int(mm[1], 16)) is None: own.add(int(mm[1], 16))
                need_good = 0
                hits = {c for c in own if fpok(c)}
                if len(own) != 1 or len(hits) != 1: hits = set()
                need_good = 1
            if not hits:
                first = [(k, portcheck.xf[w][0]) for k, w in enumerate(names) if w in portcheck.xf][:1]
                if first:
                    k0, v0 = first[0]; pat = struct.pack("<I", v0)
                    for sn in (".rdata", ".data"):
                        s_ = img.section(sn); blob = img.bytes_at(s_.va, min(s_.virtual_size, s_.raw_size)); o = 0
                        while True:
                            o = blob.find(pat, o)
                            if o < 0: break
                            if o % 4 == 0 and fpok(s_.va + o - 4 * k0): hits.add(s_.va + o - 4 * k0)
                            o += 4
            if len(hits) == 1: addr = hits.pop(); found.append((nm, addr, 4 * len(names)))
            else:
                final_data.append(apply_rename(d)); datanotes.append(f"{nm}: not located in the XBE"); continue
        names = [w for w in re.findall(r"\b([A-Za-z_]\w*)\b", d.split("=", 1)[1]) if w not in ("NULL",)]
        ok = True
        for k, w in enumerate(names):
            v = struct.unpack("<I", img.bytes_at(addr + 4 * k, 4))[0]
            xn_ = xname.get(v)
            if xn_ == w or FOLDAT.get(w) == v: continue
            if xn_ is not None and ptwin(w, xn_): continue
            if w not in portcheck.xf and w not in FOLDAT and (v in folded or xn_ is None): continue
            ok = False; break
        if ok:
            vals = [struct.unpack("<I", img.bytes_at(addr + 4 * k, 4))[0] for k in range(len(names))]
            for k, w in enumerate(names):
                v = vals[k]
                if w not in portcheck.xf and v in xname and xname[v] != w and ptwin(w, xname[v]):
                    refold.append((xname[v], w, v)); continue
                if w in portcheck.xf or w in FOLDAT or v in xname: continue
                shared = any(vals[j] == v and names[j] != w for j in range(len(names)))
                if v in folded or shared: newfolds.append((w, v))
                elif w in defined_here: newnames.append((w, v))
            final_data.append(apply_rename(d)); datanotes.append(f"{nm} is 0x{addr:X}, {len(names)} entries compared")
        else:
            final_data.append(apply_rename(d)); datanotes.append(f"{nm} 0x{addr:X}, entries DIFFER")
        continue
    if addr is None and any(f_[0] == nm for f_ in found):
        final_data.append(d); continue
    if addr is None:
        b = dump_bytes(prelude, d, nm) if not re.search(r"\(\s*\*", d.split("=")[0]) else None
        hits = bytesearch(b) if b and len(b) >= 4 else set()
        if len(hits) == 1:
            a = hits.pop(); found.append((nm, a, len(b)))
            final_data.append(d); datanotes.append(f"{nm} is 0x{a:X}, 0x{len(b):X} bytes compared, found by the bytes")
        else:
            final_data.append(d); datanotes.append(f"{nm}: not located in the XBE, PS2 initializer kept")
        continue
    b = dump_bytes(prelude, d, nm)
    if b is None:
        final_data.append(d); datanotes.append(f"{nm} 0x{addr:X}, not compared"); continue
    try:
        xb = img.bytes_at(addr, len(b))
    except ValueError:
        final_data.append(d); datanotes.append(f"{nm} 0x{addr:X}, in .bss, so it has no initial bytes to compare"); continue
    if xb == b: final_data.append(d); datanotes.append(f"{nm} is 0x{addr:X}, 0x{len(b):X} bytes compared")
    else:
        # a map address can be biased by an index offset: look nearby for the bytes
        hits = set()
        for c in unref | {addr}:
            for k in range(-0x400, 0x401, 2):
                try:
                    if img.bytes_at(c + k, len(b)) == b: hits.add(c + k)
                except Exception: pass
        if len(hits) == 1:
            a = hits.pop(); found.append((nm, a, len(b)))
            final_data.append(d); datanotes.append(f"{nm} is 0x{a:X}, 0x{len(b):X} bytes compared (data.txt had 0x{addr:X}, an index-biased address)")
        else:
            # a table of pointers (strings, other tables) cannot match byte for byte
            ptr_ = "*" in d.split("=")[0] or re.search(r"=\s*\{[^}]*\"", d)
            final_data.append(d); datanotes.append(f"{nm} 0x{addr:X}" + (", a pointer table, not compared" if ptr_ else ", bytes DIFFER"))
datablock = "\n\n".join(_slots[i_] for i_ in sorted(_slots))
resolve_decls(datablock)
# ---- header ---------------------------------------------------------------
for nm_, a_, s_ in found: portcheck.dn.append((a_, s_, nm_))
portcheck.dn.sort(); portcheck.dstart[:] = [a for a, _, _ in portcheck.dn]
fileglob = {nm for nm, _, _ in datakeep if nm}
def _filt(r):
    out = []
    for x in r:
        if x.startswith("x86-only globals "):
            g = [y for y in x[17:].split(",") if y not in fileglob]
            if g: out.append("x86-only globals " + ",".join(g))
        else: out.append(x)
    return out
chk = {n: _filt(portcheck.check(n)) for n in located if n in portcheck.xf}
for n_, ct_ in portcheck.CTAB.items():
    if n_ not in dict(funcs) or not ct_: continue
    nm_ = set(re.findall(r"char_table(?:\[0\])?\s*=\s*(_\w+)", dict(funcs)[n_]))
    ct_ = {v for v in ct_ if portcheck.xsym(v) is None}
    if len(nm_) == 1 and len(ct_) == 1:
        datanotes.append(f"{nm_.pop()} is 0x{ct_.pop():X}, the char table {n_} stores")
base = os.path.basename(rel)
H = [f"/* {base}, retail sf33rd.xbe.",
     " * Ported from the PS2 C (ps2.path). Each function was compared with its",
     " * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,",
     " * and globals. Unless a note says otherwise the C is the PS2 C."]
unnamed_info = []
for n_ in sorted(chk, key=lambda k: dict((e[0], e[1]) for e in entries).get(k, 0)):
    keep = []
    for x in chk[n_]:
        if x.startswith("unnamed data "): unnamed_info.append(f"{n_}: {x[13:]}")
        else: keep.append(x)
    chk[n_] = keep
for n, va, sz in sorted(entries, key=lambda e: e[1]):
    r = chk.get(n, ["not compared"])
    H.append(f" * {n} 0x{va:X} size 0x{sz:X}." + ("" if not r else " FLAG: " + "; ".join(r) + "."))
for l, _ in foldl: H.append(" * " + l)
if unloc: H.append(" * Not located in sf33rd.xbe; their PS2 C is kept under #if 0: " + ", ".join(n for n, _ in unloc) + ".")
for x in sorted(notes_callee.values()): H.append(f" * {x}.")
for x in datanotes: H.append(f" * Data: {x}.")
for x in ps2blocks: H.append(f" * TARGET_PS2 block in {x}.")
gl = collections.Counter()
for n, va, sz in entries:
    pg = portcheck.ps2_globals(n) or set()
    for i in _dis.disasm(text[va - TVA: va - TVA + sz], va):
        if i.mnemonic in ("call", "jmp") and re.fullmatch(r"0x[0-9a-f]+", i.op_str): continue
        for h in re.findall(r"0x[0-9a-f]+", i.op_str):
            v = int(h, 16)
            if not (0x218DC0 <= v < 0xD20000): continue
            s = portcheck.xsym(v)
            if s not in pg:
                for g in sorted(pg):
                    if g in dnames and dnames[g][0] - 0x400 <= v < dnames[g][0] + max(dnames[g][1] or 1, 1): s = g; break
            if s:
                a = dnames[s][0] if s in dnames else min([a_ for n_, a_, _ in found if n_ == s] or [v])
                gl[(s, a)] += 1
if unnamed_info: H.append(" * Unnamed data used (not checked): " + "; ".join(unnamed_info) + ".")
if fade_fixed: H.append(" * FadeIn/FadeOut priority is 1 on Xbox (PS2 8) in " + ", ".join(sorted(set(fade_fixed))) + ".")
if gl: H.append(" * Globals: " + ", ".join(f"{s} 0x{a:X}" for (s, a) in sorted(gl, key=lambda z: z[1])) + ".")
import textwrap
out = []
for l in H:
    if len(l) <= 79: out.append(l); continue
    w = textwrap.wrap(l[3:], 76, break_on_hyphens=False)
    out.append(" * " + w[0]); out += [" * " + x for x in w[1:]]
src = "\n".join(out) + "\n */\n\n" + assemble(datablock)
if unloc:
    src += "\n#if 0\n/* PS2 C for functions not located in sf33rd.xbe yet. */\n\n" + "\n\n".join(t for _, t in unloc) + "\n#endif\n"
err = gcc(src)
print(src if not WRITE else "", file=sys.stdout)
print("GCC:", (err.strip() or "clean")[:3000], file=sys.stderr)
if newnames or newfolds or refold:
    json.dump({"file": rel, "names": newnames, "folds": newfolds, "refold": refold}, open(SP + "/portgen_new.json", "w"))
    print("NEW", len(newnames), "names", len(newfolds), "folds", len(refold), "refold", file=sys.stderr)
if WRITE and "error" not in err:
    open(path, "w").write(src)
elif WRITE:
    print("NOT WRITTEN", file=sys.stderr)
