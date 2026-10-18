# Index of PS2 declarations: extern variables, prototypes, macros, typedefs,
# enums, from the PS2 headers and the file-scope definitions in PS2 .c files.
import os as _os, sys as _sys
_sys.path.insert(0, _os.path.dirname(_os.path.abspath(__file__)))
from ps2paths import OG as _OG, SP as _SP, PS as _PS
import os, re, json
PS = _PS
IDX = {"var": {}, "func": {}, "macro": {}, "type": {}, "enum": {}}
def strip_comments(s):
    s = re.sub(r"/\*.*?\*/", lambda m: " " * 0 if "\n" not in m[0] else "\n" * m[0].count("\n"), s, flags=re.S)
    return re.sub(r"//[^\n]*", "", s)
def scan(path, is_c):
    raw = open(path, errors="replace").read()
    s = strip_comments(raw)
    # macros
    for m in re.finditer(r"^#define\s+(\w+)((?:[^\n\\]|\\\n)*)$", s, re.M):
        if not is_c: IDX["macro"].setdefault(m[1], m[0].strip())
    # walk top-level statements
    depth = 0; start = 0; i = 0; n = len(s)
    while i < n:
        c = s[i]
        if c == "#" and (i == 0 or s[i - 1] == "\n"):
            j = s.find("\n", i)
            while j != -1 and s[j - 1] == "\\": j = s.find("\n", j + 1)
            i = n if j == -1 else j + 1; start = i; continue
        if c == "{": depth += 1
        elif c == "}":
            depth -= 1
            if depth == 0:
                k = i + 1
                while k < n and s[k] in " \t": k += 1
                if k < n and s[k] in ";\n" and s[k] != ";":
                    # function body end
                    stmt = s[start:i + 1].strip()
                    m = re.match(r"^((?:static\s+|inline\s+|const\s+)*[A-Za-z_][\w\s\*]*?\b([A-Za-z_]\w*)\s*\([^{;]*\))\s*\{", stmt, re.S)
                    if m and is_c and not stmt.startswith("static"): IDX["func"].setdefault(m[2], re.sub(r"\s+", " ", m[1]) + ";")
                    start = i + 1
        elif c == ";" and depth == 0:
            stmt = s[start:i + 1].strip(); start = i + 1
            handle(stmt, is_c, path)
        i += 1
def handle(stmt, is_c, path):
    one = re.sub(r"\s+", " ", stmt)
    if one.startswith("typedef"):
        m = re.search(r"(\w+)\s*(?:\[[^\]]*\])*\s*;$", one) or re.search(r"\(\s*\*\s*(\w+)\s*\)", one)
        if m: IDX["type"].setdefault(m[1], stmt)
        return
    if one.startswith("enum") or re.match(r"^(typedef )?enum\b", one):
        for e in re.findall(r"[{,]\s*([A-Za-z_]\w*)", one): IDX["enum"].setdefault(e, stmt)
        return
    if one.startswith("struct") or one.startswith("union"): 
        m = re.match(r"^(struct|union) (\w+) \{", one)
        if m: IDX["type"].setdefault(m[1] + " " + m[2], stmt)
        return
    if "(" in one and re.search(r"\)\s*;$", one) and "=" not in one.split("(")[0]:
        m = re.search(r"\b([A-Za-z_]\w*)\s*\([^()]*(?:\([^()]*\)[^()]*)*\)\s*;$", one)
        if m and not one.startswith("extern") or (m and "(*" not in one):
            if m and m[1] not in ("if", "while", "return", "sizeof"):
                IDX["func"].setdefault(m[1], one); return
    # variables
    if one.startswith("static"): return
    decl = one[7:] if one.startswith("extern ") else one
    lhs = decl.split("=")[0].strip().rstrip(";").strip()
    m = re.search(r"\(\s*\*\s*(?:const\s+)?(\w+)\s*(?:\[[^\]]*\]\s*)*\)", lhs) or re.search(r"([A-Za-z_]\w*)\s*(?:\[[^\]]*\]\s*)*$", lhs)
    if not m: return
    name = m[1]
    if name in ("void",): return
    ext = "extern " + lhs + ";"
    if one.startswith("extern"): IDX["var"].setdefault(name, ext)
    elif is_c: IDX["var"].setdefault(name, ext); IDX.setdefault("defin", {})[name] = (os.path.relpath(path, PS), stmt)
for root, _, fs in os.walk(PS + "/include"):
    for f in sorted(fs):
        if f.endswith(".h"): scan(os.path.join(root, f), False)
for root, _, fs in os.walk(PS + "/src/anniversary"):
    for f in sorted(fs):
        if f.endswith(".c"): scan(os.path.join(root, f), True)
json.dump(IDX, open((_SP + "/declidx.json"), "w"))
print({k: len(v) for k, v in IDX.items()})
for k in ("frw", "Suicide", "EXE_flag", "eff29_vanish_time", "_etc_char_table", "Game_pause", "bg_w"):
    print(k, IDX["var"].get(k))
for k in ("set_char_move_init", "char_move", "push_effect_work", "effect_56_init", "random_16", "Bg_Y_Sitei"):
    print(k, IDX["func"].get(k))
print(IDX["macro"].get("EFFECT_MAX"), IDX["type"].get("BG", "")[:60])
