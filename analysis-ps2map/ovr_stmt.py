# ovr_stmt.py Game/X.c FUNC "statement;" "comment" : copy FUNC's C from the
# ported file into overrides/X.c with the statement put before its first
# top-level switch (the Xbox screen-id stores sit there), or with "@top "
# after its local declarations.
import os as _os, sys as _sys
_sys.path.insert(0, _os.path.dirname(_os.path.abspath(__file__)))
from ps2paths import OG as _OG, SP as _SP, PS as _PS
import sys, re
OG = _OG
rel, fn, stmt, com = sys.argv[1:5]
t = open(f"{OG}/src/sf33rd/Source/{rel}").read().split(" */", 1)[1]
b = re.search(r"^[A-Za-z_][\w \*]*\b" + re.escape(fn) + r"\([^;{]*\) \{\n.*?^\}", t, re.M | re.S)[0]
if stmt.startswith("@top "):
    # after the local declarations
    stmt = stmt[5:]; lines = b.split("\n"); k = 1
    while k < len(lines) and re.match(r"^    (?:const |static |struct )?\w+[\w\* ]* \**\w+(?:\[[^\]]*\])*(?: = [^;]+)?;$", lines[k]): k += 1
    lines.insert(k, ("\n" if k > 1 else "") + "    " + stmt.replace("\n", "\n    ")); b = "\n".join(lines)
else:
    i = b.index("\n    switch (")
    b = b[:i] + "\n    " + stmt + "\n" + b[i:]
open(f"{OG}/analysis-ps2map/overrides/{rel.split('/')[-1]}", "a").write(f"\n/* {com} */\n{b}\n")
print(fn, "ok")
