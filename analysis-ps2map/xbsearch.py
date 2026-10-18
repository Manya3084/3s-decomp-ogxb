# xbsearch.py [-j N] [--hand] [--calls] [--apply] : try the Xbox's usual changes to
# the PS2 C.
#
# The Xbox build drops much of the PS2 debug code and some calls, and it
# returns where the PS2 logs an error and hangs. For every differing
# function of a generated port this builds variants of its C:
#   - each `if` whose condition reads Debug_w removed (an else branch is
#     kept), or only the Debug_w term of an && / || condition removed;
#   - each statement calling Check_Pos_OBJ or Check_Pos_OBJ2 removed (with
#     --calls, each statement that is a call, whatever it calls);
#   - `flLogOut(...); while (1) {}` made a return;
#   - the integer return type changed;
#   - a counted loop given a second, counted-down counter;
#   - with --break, each `return;` of a void function written `break;`
#     (where retail's case ends at the shared epilogue; a break outside a
#     switch or loop does not build, and that variant fails);
#   - with --return, each `break;` of a void function written `return;`
#     (a case that ends by returning lays its blocks out differently from
#     one that breaks to the shared code after the switch: end_01000);
#   - with --swap, each compare of two non-constant operands written the
#     other way round (a == b as b == a, a < b as b > a), which changes
#     which operand VC7.1 loads into a register;
# and each variant's combinations with the others found to help. A variant
# that matches retail is reported; with --apply it is written as an
# override (ovredit.py) and the port regenerated; with --hand the hand ports
# are searched too, and a match there is written into the file. Run tools/build_c.py and
# tools/objdiff.py first.
import sys as _sys
# analysis-ps2map/queue.py would shadow the standard queue the thread pool uses
_here = _sys.path.pop(0)
from concurrent.futures import ThreadPoolExecutor
_sys.path.insert(0, _here)
import os as _os
_sys.path.insert(0, _os.path.dirname(_os.path.abspath(__file__)))
_sys.path.insert(0, _os.path.join(_os.path.dirname(_os.path.abspath(__file__)), "..", "tools"))
from ps2paths import OG
import json, os, re, subprocess, sys, tempfile
from pathlib import Path
import permute

ROOT = Path(OG)
jobs = int(sys.argv[sys.argv.index("-j") + 1]) if "-j" in sys.argv else 24
APPLY = "--apply" in sys.argv
HAND = "--hand" in sys.argv  # also hand ports, edited in place
ANYCALL = "--calls" in sys.argv  # drop any one call statement, not only DROP_CALLS
SWAP = "--swap" in sys.argv  # reverse compares
BREAK = "--break" in sys.argv  # a return in a switch case as a break
RETURN = "--return" in sys.argv  # a break in a switch case as a return
DROP_CALLS = ("Check_Pos_OBJ", "Check_Pos_OBJ2")


def balanced(s, i, op, cl):
    """index just past the bracket that closes s[i] (an op)."""
    d = 0
    while i < len(s):
        if s[i] == op:
            d += 1
        elif s[i] == cl:
            d -= 1
            if d == 0:
                return i + 1
        i += 1
    return None


def statement_end(s, i):
    """end of the statement starting at s[i] (after spaces)."""
    while s[i].isspace():
        i += 1
    if s[i] == "{":
        return balanced(s, i, "{", "}")
    j = s.find(";", i)
    return j + 1 if j >= 0 else None


def variants(body):
    out = []
    for m in re.finditer(r"\bif\s*\(", body):
        cs = m.end() - 1
        ce = balanced(body, cs, "(", ")")
        if ce is None:
            continue
        cond = body[cs + 1:ce - 1]
        if "Debug_w" not in cond:
            continue
        te = statement_end(body, ce)
        if te is None:
            continue
        # the whole if, with its else branch kept in its place
        rest = body[te:]
        em = re.match(r"\s*else\b", rest)
        start = body.rfind("\n", 0, m.start()) + 1
        indent = body[start:m.start()]
        if em:
            ee = statement_end(body, te + em.end())
            if ee is None:
                continue
            inner = body[te + em.end():ee].strip()
            if inner.startswith("if"):
                pass  # an else-if chain: only the term variants below
            elif inner.startswith("{"):
                lines = inner[1:-1].strip("\n").split("\n")
                inner = "\n".join(l[4:] if l.startswith("    ") else l for l in lines) + "\n"
                out.append(body[:start] + inner + body[ee:].lstrip(" ").removeprefix("\n"))
            else:
                out.append(body[:start] + indent + inner + "\n" + body[ee:].lstrip(" ").removeprefix("\n"))
        else:
            tail = body[te:].removeprefix("\n")
            if body[start - 2:start] == "\n\n":
                tail = tail.removeprefix("\n")
            out.append(body[:start] + tail)
        # one term of the condition
        for op in ("&&", "||"):
            parts = [p for p in re.split(r"\s*" + re.escape(op) + r"\s*", cond)]
            if len(parts) > 1 and all(p.count("(") == p.count(")") for p in parts):
                keep = [p for p in parts if "Debug_w" not in p]
                if keep and len(keep) < len(parts):
                    out.append(body[:cs + 1] + f" {op} ".join(keep) + body[ce - 1:])
    names = DROP_CALLS if not ANYCALL else (r"\w+",)
    for name in names:
        for m in re.finditer(r"^[ \t]*" + name + r"\([^;]*\);\n(?:[ \t]*\n)?", body, re.M):
            out.append(body[:m.start()] + body[m.end():])
    # a loop that retail runs with a separate down counter (dec; jne): for
    # (i = 0, cnt = N; cnt != 0; i++, cnt--), and the same with i an s32
    for m in re.finditer(r"for \((\w+) = 0; \1 < (0x[0-9A-Fa-f]+|\d+); \1\+\+\)", body):
        if "cnt" in re.findall(r"\b\w+\b", body):
            break
        head = body.index("{") + 1
        loop = body[:m.start()] + f"for ({m.group(1)} = 0, cnt = {m.group(2)}; cnt != 0; {m.group(1)}++, cnt--)" + body[m.end():]
        two = loop[:head] + "\n    s32 cnt;" + loop[head:]
        out.append(two)
        out.append(re.sub(r"^(\s*)(?:s16|u16|s8|u8) " + m.group(1) + r";", r"\1s32 " + m.group(1) + ";", two, count=1, flags=re.M))
    if BREAK and re.match(r"\s*(?:static\s+)?void\b", body):
        for m in re.finditer(r"\breturn;", body):
            out.append(body[:m.start()] + "break;" + body[m.end():])
    if RETURN and re.match(r"\s*(?:static\s+)?void\b", body):
        for m in re.finditer(r"\bbreak;", body):
            out.append(body[:m.start()] + "return;" + body[m.end():])
    if SWAP:
        opd = r"[A-Za-z_][\w.\[\]]*(?:->[\w.\[\]]+)*"
        flip = {"==": "==", "!=": "!=", "<": ">", ">": "<", "<=": ">=", ">=": "<="}
        for m in re.finditer(r"(?<![\w.\]>*&])(" + opd + r") (==|!=|<=|>=|<|>) (" + opd + r")(?![\w.\[(])", body):
            a, op, b = m.groups()
            if a == b or re.fullmatch(r"[A-Z_][A-Z0-9_]*", b) or re.fullmatch(r"[A-Z_][A-Z0-9_]*", a):
                continue
            if a.count("[") != a.count("]") or b.count("[") != b.count("]"):
                continue
            out.append(body[:m.start()] + f"{b} {flip[op]} {a}" + body[m.end():])
    # the return type: an Xbox function returning a narrower or wider int
    rm = re.match(r"(\s*(?:static\s+)?)(s8|u8|s16|u16|s32|u32)(\s+\w+\s*\()", body)
    if rm:
        for ty in ("s8", "u8", "s16", "u16", "s32"):
            if ty != rm.group(2):
                out.append(rm.group(1) + ty + rm.group(3) + body[rm.end():])
    ret = "return;" if re.match(r"\s*(?:static\s+)?void\b", body) else "return 0;"
    hang = re.sub(r"(\n[ \t]*)flLogOut\([^;]*\);\n[ \t]*while \(1\) \{\}", lambda m: m.group(1) + ret, body)
    if hang != body:
        out.append(hang)
    return [v for v in dict.fromkeys(out) if v != body]


def note_for(old, new):
    parts = []
    if new.count("Debug_w") < old.count("Debug_w"):
        parts.append("has no Debug_w test")
    gone = [n for n in dict.fromkeys(re.findall(r"\b(\w+)\(", old))
            if len(re.findall(r"\b" + n + r"\(", new)) < len(re.findall(r"\b" + n + r"\(", old))
            and n not in ("flLogOut", "if", "while", "for", "switch")]
    for name in gone:
        parts.append(f"does not call {name}" + (" there" if re.search(r"\b" + name + r"\(", new) else ""))
    ro, rn = re.match(r"\s*(?:static\s+)?(\w+)", old), re.match(r"\s*(?:static\s+)?(\w+)", new)
    if ro and rn and ro.group(1) != rn.group(1):
        parts.append(f"returns an {rn.group(1)}")
    if BREAK and new.count("return;") < old.count("return;") and new.count("break;") > old.count("break;"):
        parts.append("breaks out of the switch where the PS2 returns")
    if RETURN and new.count("break;") < old.count("break;") and new.count("return;") > old.count("return;"):
        parts.append("returns where the PS2 breaks out of the switch")
    if SWAP and len(old) == len(new) and new.count("Debug_w") == old.count("Debug_w") and not gone:
        parts.append("compare written the other way round")
    if new.count("flLogOut") < old.count("flLogOut"):
        parts.append("returns where the PS2 logs an error and hangs")
    return "The Xbox " + " and ".join(parts or ["drops this PS2 code"]) + "."


def main():
    R = json.load(open(ROOT / "build" / "objdiff.json"))
    sc = permute.Scorer()
    work = []
    for o, r in R.items():
        src = ROOT / "src" / (o[:-4] + ".c")
        if not src.is_file():
            continue
        text = src.read_text(errors="replace")
        if "Ported from the PS2" not in text[:4000] and not HAND:
            continue
        for f in r["functions"]:
            if f.get("status") != "diff" or "va" not in f:
                continue
            span = permute.find_definition(text, f["name"])
            if not span:
                continue
            body = text[span[0]:span[1]]
            vs = variants(body)
            if vs:
                work.append((src, text, span, f, vs))
    print(f"{len(work)} functions, {sum(len(w[4]) for w in work)} variants", flush=True)

    def run(item):
        src, text, span, f, vs = item
        base = sc.score(src, text, f["name"], f["va"], f["slot"], "b")
        best, good = None, []
        for v in vs:
            s = sc.score(src, text[:span[0]] + v + text[span[1]:], f["name"], f["va"], f["slot"], "v")
            if s[0] == "match":
                return f, v, s
            if s[1] < base[1]:
                good.append((s[1], v))
        # helpful edits taken one after another, best first, while each helps
        cur, cur_s = text[span[0]:span[1]], base[1]
        while good:
            good.sort(key=lambda x: x[0])
            cur = good[0][1]
            cur_s = good[0][0]
            good = []
            for nv in variants(cur):
                s = sc.score(src, text[:span[0]] + nv + text[span[1]:], f["name"], f["va"], f["slot"], "c")
                if s[0] == "match":
                    return f, nv, s
                if s[1] < cur_s:
                    good.append((s[1], nv))
        return f, None, base

    found = []
    with ThreadPoolExecutor(jobs) as pool:
        for (src, text, span, f, vs), (f2, v, s) in zip(work, pool.map(run, work)):
            if v:
                found.append((src, f["name"], v, note_for(text[span[0]:span[1]], v)))
                print(f"match: {src.relative_to(ROOT)} {f['name']}", flush=True)
    print(f"{len(found)} matched")
    if APPLY and found:
        files = set()
        for src, name, v, note in found:
            text = src.read_text(errors="replace")
            if "Ported from the PS2" not in text[:4000]:
                span = permute.find_definition(text, name)
                src.write_text(text[:span[0]] + "/* " + note + " */\n" + v + text[span[1]:])
                continue
            rel = src.relative_to(ROOT / "src" / "sf33rd" / "Source").as_posix()
            with tempfile.NamedTemporaryFile("w", suffix=".c", delete=False, dir=ROOT / "build") as t:
                t.write(v)
            subprocess.run(["python3", str(ROOT / "analysis-ps2map" / "ovredit.py"), rel, name,
                            note,
                            "--body", t.name], cwd=ROOT, capture_output=True)
            os.unlink(t.name)
            files.add(rel)
        if files:
            subprocess.run(["python3", str(ROOT / "analysis-ps2map" / "regen.py"), *sorted(files)], cwd=ROOT)


main()
