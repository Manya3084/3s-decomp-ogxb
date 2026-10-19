# xbdata.py FILE NAME[:COUNT]... [--write]: write a table the C declares
# from the retail XBE, as C.
#
# FILE is a file of this tree (src/...) that declares NAME extern. The file
# is built with gcc -m32 -g, and the table's type is read from the DWARF:
# scalars, arrays, structs, unions (by their first member), pointers and
# function pointers. The bytes come from the XBE at NAME's address (the
# D_ADDR in the name, else data.txt). An array the C leaves unsized gets
# COUNT elements, else data.txt's size, else as many as fit before the next
# address the tree knows.
#
# A pointer is written as what it points at: 0, a string literal (a char
# pointer to a terminated string), a function (funcs.txt, folded.json,
# xdk.txt), or a global (data.txt, a D_ADDR name), with an offset when it
# points inside one. A pointer to data no name covers gets a table of its
# own, D_ADDR of the pointer's target type, written the same way before
# the table that points at it.
#
# Without --write the C is printed. With --write each extern declaration is
# replaced by the definition (the reached tables go before it), and the file
# should then be checked with portdata.py.
import os, re, sys, json, struct, bisect, subprocess, tempfile
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from ps2paths import OG
sys.path.insert(0, OG + "/tools")
from ogxb.paths import find_xbe
from ogxb.xbe import load
from elftools.elf.elffile import ELFFile

img = load(find_xbe())
RAW = open(img.path, "rb").read()
SYM = OG + "/config/sf33rd/symbols/"


def section(va):
    for s in img.sections:
        if s.va <= va < s.va + s.virtual_size:
            return s
    return None


def rd(va, n):
    s = section(va)
    if s is None:
        return None
    o = va - s.va
    b = RAW[s.raw + o:s.raw + min(o + n, s.raw_size)] if o < s.raw_size else b""
    return b + b"\0" * (n - len(b))


def init_end(va):
    s = section(va)
    return s.va + min(s.raw_size, s.virtual_size) if s else va


def read_syms(f):
    out = {}
    for l in open(SYM + f, errors="replace"):
        m = re.match(r"(\S+)\s*=\s*0x([0-9A-Fa-f]+);(.*)", l)
        if m:
            out.setdefault(m[1], (int(m[2], 16), m[3]))
    return out


FUNCS = read_syms("funcs.txt")
XDK = read_syms("xdk.txt")
DATA = {n: (v, int(m[1], 16) if (m := re.search(r"size:0x([0-9A-Fa-f]+)", c)) else None)
        for n, (v, c) in read_syms("data.txt").items()}
FOLDED = json.load(open(OG + "/analysis-ps2map/folded.json"))

# names with C: the compiled objects of this tree
def defined_names():
    out = set()
    objdir = OG + "/build/obj"
    for r, _, fs in os.walk(objdir):
        for f in fs:
            if f.endswith(".obj"):
                o = subprocess.run(["nm", os.path.join(r, f)], capture_output=True, text=True).stdout
                for l in o.splitlines():
                    p = l.split()
                    if len(p) == 3 and p[1] in "TDRBC":
                        out.add(p[2].lstrip("_").split("@")[0])
    return out


CDEF = defined_names()
FUNC_AT = {}
for n, (v, c) in FUNCS.items():
    if n in CDEF:
        FUNC_AT.setdefault(v, n)
for a, ns in FOLDED.items():
    for n in ns:
        if n in CDEF:
            FUNC_AT.setdefault(int(a, 16), n)
for n, (v, c) in FUNCS.items():
    FUNC_AT.setdefault(v, n)
for n, (v, c) in XDK.items():
    if "func" in c:
        FUNC_AT.setdefault(v, n)
DATA_AT = {}
for n, (v, size) in DATA.items():
    DATA_AT.setdefault(v, (n, size))
SRCD = set()
for r, _, fs in os.walk(OG + "/src"):
    for f in fs:
        if f.endswith(".c"):
            SRCD.update(int(h, 16) for h in re.findall(r"\bD_([0-9A-F]{8})\b", open(os.path.join(r, f), errors="replace").read()))
for v in SRCD:
    DATA_AT.setdefault(v, ("D_%08X" % v, None))
BOUNDS = sorted(set(DATA_AT) | set(FUNC_AT))


def next_bound(va):
    i = bisect.bisect_right(BOUNDS, va)
    return min(BOUNDS[i] if i < len(BOUNDS) else init_end(va), init_end(va))


# ---- DWARF types ----
class T:
    pass


def die_type(die):
    a = die.attributes.get("DW_AT_type")
    return die.get_DIE_from_attribute("DW_AT_type") if a else None


def strip(t):
    while t is not None and t.tag in ("DW_TAG_typedef", "DW_TAG_const_type", "DW_TAG_volatile_type"):
        t = die_type(t)
    return t


def name_of(t):
    a = t.attributes.get("DW_AT_name")
    return a.value.decode() if a else None


def size_of(t):
    t = strip(t)
    if t is None:
        return 1
    if "DW_AT_byte_size" in t.attributes:
        return t.attributes["DW_AT_byte_size"].value
    if t.tag == "DW_TAG_array_type":
        n = 1
        for d in dims(t):
            n *= d or 0
        return n * size_of(die_type(t))
    if t.tag == "DW_TAG_pointer_type":
        return 4
    return 4


def dims(t):
    out = []
    for c in t.iter_children():
        if c.tag == "DW_TAG_subrange_type":
            if "DW_AT_upper_bound" in c.attributes:
                out.append(c.attributes["DW_AT_upper_bound"].value + 1)
            elif "DW_AT_count" in c.attributes:
                out.append(c.attributes["DW_AT_count"].value)
            else:
                out.append(None)
    return out


def c_type(t):
    """a C spelling of a type, for a reached table's element"""
    if t is None:
        return "void"
    if t.tag in ("DW_TAG_typedef", "DW_TAG_base_type"):
        return name_of(t)
    if t.tag == "DW_TAG_const_type":
        return "const " + c_type(die_type(t))
    if t.tag == "DW_TAG_volatile_type":
        return c_type(die_type(t))
    if t.tag == "DW_TAG_pointer_type":
        return c_type(die_type(t)) + "*"
    if t.tag in ("DW_TAG_structure_type", "DW_TAG_union_type"):
        n = name_of(t)
        return ("struct " if t.tag == "DW_TAG_structure_type" else "union ") + n if n else "u8"
    if t.tag == "DW_TAG_enumeration_type":
        return "s32"
    return "u8"


def is_char(t):
    t = strip(t)
    return t is not None and t.tag == "DW_TAG_base_type" and size_of(t) == 1


def lit(b):
    o = ""
    for c in b:
        if c == 0x22:
            o += '\\"'
        elif c == 0x5C:
            o += "\\\\"
        elif 0x20 <= c < 0x7F:
            o += chr(c)
        elif c == 10:
            o += "\\n"
        else:
            o += "\\%03o" % c
    return '"' + o + '"'


def cstring_at(v):
    b = rd(v, min(0x400, max(0, init_end(v) - v)))
    if not b:
        return None
    e = b.find(b"\0")
    if e < 0:
        return None
    return b[:e]


class Writer:
    def __init__(self, used_names):
        self.new = []          # (name, ctype, count, init text)
        self.newat = {}        # va -> name
        self.funcs = set()     # function names the tables use
        self.used = used_names

    def pointer(self, t, v):
        if v == 0:
            return "0"
        target = strip(die_type(t))
        cast = "(" + c_type(t) + ")"
        if target is not None and target.tag == "DW_TAG_subroutine_type":
            n = FUNC_AT.get(v)
            if n is None:
                return "0x%08X /* no function */" % v
            self.funcs.add(n)
            return n
        if target is None or is_char(target):
            s = cstring_at(v)
            if s is not None and section(v) and v < init_end(v):
                return lit(s)
        if v in DATA_AT:
            n = DATA_AT[v][0]
            return f"{cast}&{n}"
        if v in self.newat:
            return f"{cast}{self.newat[v]}"
        i = bisect.bisect_right(BOUNDS, v) - 1
        if i >= 0 and BOUNDS[i] in DATA_AT:
            n, size = DATA_AT[BOUNDS[i]]
            if size and v < BOUNDS[i] + size:
                return f"{cast}((u8*)&{n} + 0x{v - BOUNDS[i]:X})"
        for va2, n in self.newat.items():
            pass
        if section(v) and v < init_end(v) and target is not None:
            # an unnamed table of the target type
            n = "D_%08X" % v
            self.newat[v] = n
            el = size_of(target) or 1
            cnt = max(1, (next_bound(v) - v) // el)
            body = self.array_of(target, v, cnt)
            self.new.append((n, c_type(target), cnt, body, v))
            return f"{cast}{n}"
        return "0x%08X /* unresolved */" % v

    def value(self, t, va, indent):
        t0 = t
        t = strip(t)
        if t is None:
            return "0"
        if t.tag == "DW_TAG_base_type":
            n = size_of(t)
            enc = t.attributes["DW_AT_encoding"].value
            b = rd(va, n)
            if enc == 4:  # float
                f = struct.unpack("<f" if n == 4 else "<d", b)[0]
                r = repr(f)
                if "inf" in r or "nan" in r:
                    return "0x%X /* raw float */" % struct.unpack("<I", b)[0]
                return r + ("f" if n == 4 else "")
            signed = enc in (5, 6)
            v = int.from_bytes(b, "little", signed=signed)
            return str(v) if signed or v < 0x100 else "0x%X" % v
        if t.tag == "DW_TAG_enumeration_type":
            return str(int.from_bytes(rd(va, size_of(t)), "little", signed=True))
        if t.tag == "DW_TAG_pointer_type":
            return self.pointer(t, struct.unpack("<I", rd(va, 4))[0])
        if t.tag == "DW_TAG_array_type":
            ds = dims(t)
            return self.array(die_type(t), va, ds, indent)
        if t.tag in ("DW_TAG_structure_type", "DW_TAG_union_type"):
            parts = []
            for m in t.iter_children():
                if m.tag != "DW_TAG_member":
                    continue
                off = m.attributes["DW_AT_data_member_location"].value if "DW_AT_data_member_location" in m.attributes else 0
                if "DW_AT_bit_size" in m.attributes:
                    raise ValueError("bit fields are not handled")
                parts.append(self.value(die_type(m), va + off, indent + "    "))
                if t.tag == "DW_TAG_union_type":
                    break
            return "{ " + ", ".join(parts) + " }"
        return "0"

    def array(self, el, va, ds, indent):
        n = ds[0]
        rest = ds[1:]
        esz = size_of(el)
        for d in rest:
            esz *= d
        if not rest and is_char(el):
            b = rd(va, n)
            e = b.find(b"\0")
            if e >= 0 and not any(b[e:]) and all(c >= 0x20 or c in (9, 10, 13) or c >= 0x80 for c in b[:e]):
                return lit(b[:e])
        items = []
        for i in range(n):
            if rest:
                items.append(self.array(el, va + i * esz, rest, indent + "    "))
            else:
                items.append(self.value(el, va + i * esz, indent + "    "))
        return fmt(items, indent)

    def array_of(self, el, va, cnt):
        return self.array(el, va, [cnt], "")


def fmt(items, indent):
    one = "{ " + ", ".join(items) + " }"
    if len(one) + len(indent) <= 100 and "\n" not in one:
        return one
    out, line = [], indent + "    "
    for it in items:
        s = it + ","
        if "\n" in it or len(line) + len(s) > 100:
            if line.strip():
                out.append(line.rstrip())
            line = indent + "    "
        line += s + " "
    if line.strip():
        out.append(line.rstrip())
    return "{\n" + "\n".join(out) + "\n" + indent + "}"


def build(path, names):
    src = open(path, errors="replace").read()
    # make sure every name is referenced, so gcc describes it
    probe = src + "\nvoid *__xbdata_refs[] = { " + ", ".join(f"(void *)&{n}" for n in names) + " };\n"
    flags = ["-m32", "-std=gnu17", "-O0", "-g", "-fno-pic", "-w", "-Wno-incompatible-pointer-types", "-Wno-int-conversion",
             "-I" + OG + "/include", "-I" + os.path.dirname(path)]
    with tempfile.TemporaryDirectory() as td:
        c = os.path.join(td, os.path.basename(path))
        open(c, "w").write(probe)
        o = os.path.join(td, "f.o")
        r = subprocess.run(["gcc", *flags, "-c", c, "-o", o], capture_output=True, text=True)
        if r.returncode:
            sys.exit(r.stderr[-2000:])
        f = open(o, "rb")
        elf = ELFFile(f)
        dw = elf.get_dwarf_info()
        found = {}
        for cu in dw.iter_CUs():
            for die in cu.iter_DIEs():
                if die.tag == "DW_TAG_variable" and name_of(die) in names and name_of(die) not in found:
                    found[name_of(die)] = die
        return src, found, f


def main():
    args = [a for a in sys.argv[1:] if not a.startswith("--")]
    write = "--write" in sys.argv
    path = os.path.join(OG, args[0]) if not os.path.isabs(args[0]) else args[0]
    want = {}
    for a in args[1:]:
        n, _, c = a.partition(":")
        want[n] = int(c, 0) if c else None
    src, found, f = build(path, list(want))
    # the reached tables bound each other: walk until no new one appears
    for _ in range(8):
        out, w = render(want, found, args)
        new = set(w.newat) - set(BOUNDS)
        if not new:
            break
        for v in new:
            bisect.insort(BOUNDS, v)
    f.close()
    emit(src, out, w, write, path, args)


def render(want, found, args):
    out = {}
    w = Writer(set())
    for n, cnt in want.items():
        die = found.get(n)
        if die is None:
            sys.exit(f"{n}: not declared in {args[0]}")
        m = re.fullmatch(r"D_([0-9A-F]{8})", n)
        va = int(m[1], 16) if m else DATA[n][0]
        t = die_type(die)
        st = strip(t)
        if st.tag == "DW_TAG_array_type":
            ds = dims(st)
            if ds[0] is None:
                el = size_of(die_type(st))
                for d in ds[1:]:
                    el *= d
                size = DATA.get(n, (0, None))[1]
                if not cnt and not size and len(ds) == 1 and is_char(die_type(st)) and cstring_at(va) is not None:
                    size = len(cstring_at(va)) + 1  # a string: up to its terminator
                ds[0] = cnt or (size // el if size else max(1, (next_bound(va) - va) // el))
            init = w.array(die_type(st), va, ds, "")
            out[n] = (va, init, ds)
        else:
            out[n] = (va, w.value(t, va, ""), None)
    return out, w


def emit(src, out, w, write, path, args):
    for n, (va, init, ds) in out.items():
        print(f"/* {n} 0x{va:X} */ {init[:300]}{' ...' if len(init) > 300 else ''}")
    for n, ct, cnt, body, va in w.new:
        print(f"/* reached: {ct} {n}[{cnt}] 0x{va:X} */ {body[:200]}")
    if not write:
        return
    text = src
    for n, (va, init, ds) in out.items():
        # the extern declaration, maybe one of several declarators
        m = re.search(r"^extern\s+([^;\n]*?)\b" + n + r"\b([^;\n]*);[^\n]*$", text, re.M)
        if not m:
            sys.exit(f"{n}: extern declaration not found")
        line = m[0]
        decl = re.match(r"^extern\s+(.*);", line)[1]
        if "," in decl and "(" not in decl:
            # extern T a[], b[], c[]; -> keep the others, define this one apart
            base = re.match(r"((?:const\s+)?\w+\s*)", decl)[1]
            parts = [p.strip() for p in decl[len(base):].split(",")]
            mine = next(p for p in parts if re.match(r"\**" + n + r"\b", p))
            rest = [p for p in parts if p is not mine]
            keep = f"extern {base}{', '.join(rest)};\n" if rest else ""
            d = base + mine
        else:
            keep = ""
            d = decl
        if ds is not None and ds[0] is not None:
            d = re.sub(r"\b" + n + r"\s*\[\s*\]", f"{n}[{ds[0]}]", d)
        reached = ""
        for rn, ct, cnt, body, rva in w.new:
            if f"/* {rn} is" not in text:
                reached += f"/* {rn} is 0x{rva:X}, reached by a pointer. */\n{ct} {rn}[{cnt}] = {body};\n"
        w.new = []
        protos = ""
        for fn_ in sorted(w.funcs):
            if not re.search(r"\b" + fn_ + r"\s*\(", text[:m.start()]):
                protos += f"void {fn_}();\n"
        w.funcs = set()
        text = text[:m.start()] + keep + protos + reached + f"/* {n} is 0x{va:X}. */\n{d} = {init};" + text[m.end():]
    open(path, "w").write(text)
    print("written", args[0])


if __name__ == "__main__":
    main()
