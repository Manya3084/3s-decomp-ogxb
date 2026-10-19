# jpnmsg.py [--write]: the Japanese message tables of the XBE as C.
#
# The PS2 tree has only the US text (Message3rd/C_USA). The Xbox build
# also carries the Japanese text, which EFFB6's get_message_conn_data
# reads through D_0032C150 when mpp_w.language is 1: six tables, the
# win, talk and end messages of the 20 characters and the system
# direction, extra and menu messages, in the US tables' layout. This
# writes them to Message3rd/C_JPN, one file per US file, walking each
# table with the US file's message count. A table or message array two
# entries share is written once. The names are invented (xb_), and each
# table's address is noted so data.txt places it; portdata.py checks the
# files against the XBE.
import os, re, sys, struct
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from ps2paths import OG
sys.path.insert(0, OG + "/tools")
from ogxb.paths import find_xbe
from ogxb.xbe import load

img = load(find_xbe())
RAW = open(img.path, "rb").read()
USA = OG + "/src/sf33rd/Source/Game/Message3rd/C_USA/"
JPN = OG + "/src/sf33rd/Source/Game/Message3rd/C_JPN/"


def rd(va, n):
    for s in img.sections:
        if s.va <= va < s.va + s.virtual_size:
            o = va - s.va
            return RAW[s.raw + o:s.raw + o + n]
    raise ValueError(hex(va))


def W(va, n=1):
    return struct.unpack("<%dI" % n, rd(va, 4 * n))


def cstr(va):
    b = rd(va, 0x400)
    return b[:b.find(b"\0")]


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


def usa_count(fname, adr):
    t = open(USA + fname).read()
    m = re.search(r"static s8\*\* " + adr + r"\[(\d+)\]", t)
    return int(m[1])


def table_c(tname, tva, pre, adrname, ctrname, count, head):
    """one MessageTable: its message arrays, address and count tables"""
    adr, ctr = W(tva, 2)
    msgs = W(adr, count)
    nums = rd(ctr, count)
    out = [head, '#include "structs.h"', ""]
    seen = {}
    for k, (m, n) in enumerate(zip(msgs, nums)):
        if m in seen:
            continue
        nm = f"{pre}_{k:02d}J" if count > 99 or True else ""
        nm = f"{pre}_{k:03d}J" if count > 100 else f"{pre}_{k:02d}J"
        seen[m] = nm
        lines = W(m, n)
        body = ",\n".join("    " + lit(cstr(l)) for l in lines)
        out.append(f"static s8* {nm}[{n}] = {{\n{body},\n}};")
    out.append("")
    names = [seen[m] for m in msgs]
    rows = []
    for i in range(0, count, 6):
        rows.append("    " + ", ".join(names[i:i + 6]) + ",")
    out.append(f"static s8** {adrname}[{count}] = {{\n" + "\n".join(rows) + "\n};")
    out.append("")
    rows = []
    for i in range(0, count, 24):
        rows.append("    " + ", ".join(str(x) for x in nums[i:i + 24]) + ",")
    out.append(f"static s8 {ctrname}[{count}] = {{\n" + "\n".join(rows) + "\n};")
    out.append("")
    out.append(f"/* {tname} is 0x{tva:X}. */")
    out.append(f"MessageTable {tname} = {{ {adrname}, {ctrname} }};")
    return "\n".join(out) + "\n"


def main():
    write = "--write" in sys.argv
    kinds = W(0x32C150, 6)
    files = {}
    tops = []
    # the characters' win, talk and end tables
    for kind, (word, usa_word, adrw) in enumerate((("win", "Win", "msgWinAdrPL"), ("tlk", "Tlk", "msgTlkAdrPL"),
                                                    ("end", "End", "msgEndAdrPL"))):
        ptrs = W(kinds[kind], 20)
        names = {}
        for i, tva in enumerate(ptrs):
            if tva in names:
                continue
            usaf = f"PL{i:02d}{usa_word}_usa.c"
            if not os.path.exists(USA + usaf):
                sys.exit(f"{usaf} missing")
            ua = open(USA + usaf).read()
            m = re.search(r"static s8\*\* (\w+)\[(\d+)\]", ua)
            mc = re.search(r"static s8 (\w+)\[(\d+)\]", ua)
            count = int(m[2])
            tname = f"xb_pl{i:02d}{word}_jpn_tbl"
            names[tva] = tname
            pre = re.search(r"static s8\* (\w+?)_\d+P?\[", ua)[1]
            head = (f"/* PL{i:02d}{usa_word}_jpn.c, retail sf33rd.xbe.\n"
                    f" * The Japanese counterpart of C_USA/{usaf}: the table at 0x{tva:X}, which\n"
                    f" * D_0032C150's {('win', 'talk', 'end')[kind]} table lists for character {i}, walked with\n"
                    f" * the US file's {count} messages (analysis-ps2map/jpnmsg.py). */\n")
            files[f"PL{i:02d}{usa_word}_jpn.c"] = table_c(tname, tva, pre, m[1] + "J", mc[1] + "J", count, head)
        tops.append((f"xb_pl_{('mes', 'tlk', 'end')[kind]}_tbl_jpn", kinds[kind], [names[p] for p in ptrs]))
    # the system direction, extra and menu tables
    for kind, (usaf, base) in zip((3, 4, 5), (("msgSysDir_usa.c", "msgSysDir"), ("msgExtra_usa.c", "msgExtra"),
                                             ("msgMenu_usa.c", "msgMenu"))):
        ua = open(USA + usaf).read()
        m = re.search(r"static s8\*\* (\w+)\[(\d+)\]", ua)
        mc = re.search(r"static s8 (\w+)\[(\d+)\]", ua)
        count = int(m[2])
        tva = W(kinds[kind])[0]
        tname = f"xb_{base}_jpn_tbl"
        pre = re.search(r"static s8\* (\w+?)_\d+\[", ua)[1]
        head = (f"/* {base}_jpn.c, retail sf33rd.xbe.\n"
                f" * The Japanese counterpart of C_USA/{usaf}: the table at 0x{tva:X}, walked\n"
                f" * with the US file's {count} messages (analysis-ps2map/jpnmsg.py). */\n")
        files[f"{base}_jpn.c"] = table_c(tname, tva, pre, m[1] + "J", mc[1] + "J", count, head)
        tops.append((f"xb_{base}Tbl_jpn", kinds[kind], [tname]))
    # the lists D_0032C150 points at
    out = ["/* msgTable_jpn.c, retail sf33rd.xbe.",
           " * The Japanese message lists: D_0032C150 (EFFB6's get_message_conn_data)",
           " * points at the win, talk and end lists of the 20 characters and at the",
           " * system direction, extra and menu lists, which sit beside the US ones",
           " * (analysis-ps2map/jpnmsg.py). */", "", '#include "structs.h"', ""]
    decl = sorted({n for _, _, ns in tops for n in ns})
    out += [f"extern MessageTable {n};" for n in decl] + [""]
    for name, va, ns in tops:
        out.append(f"/* {name} is 0x{va:X}. */")
        rows = []
        for i in range(0, len(ns), 4):
            rows.append("    " + ", ".join("&" + n for n in ns[i:i + 4]) + ",")
        out.append(f"MessageTable* {name}[{len(ns)}] = {{\n" + "\n".join(rows) + "\n};")
        out.append("")
    out.append("/* D_0032C150 is 0x32C150. */")
    out.append("MessageTable** D_0032C150[6] = { " + ", ".join(n for n, _, _ in tops) + " };")
    files["msgTable_jpn.c"] = "\n".join(out) + "\n"
    for f, t in files.items():
        if write:
            os.makedirs(JPN, exist_ok=True)
            open(JPN + f, "w").write(t)
    print(len(files), "files" + (" written" if write else ""))


if __name__ == "__main__":
    main()
