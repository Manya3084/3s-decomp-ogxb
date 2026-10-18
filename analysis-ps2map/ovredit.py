# ovredit.py Game/X.c FUNC NOTE [OLD NEW]... | --body FILE
#
# Put an Xbox version of FUNC into overrides/X.c: the function as the
# generated port has it, with each OLD replaced by NEW (or the definition in
# FILE with --body), under a comment NOTE. An existing override of FUNC is
# replaced. Regenerate the port afterwards (regen.py Game/X.c).
import os as _os, sys as _sys
_sys.path.insert(0, _os.path.dirname(_os.path.abspath(__file__)))
_sys.path.insert(0, _os.path.join(_os.path.dirname(_os.path.abspath(__file__)), "..", "tools"))
from ps2paths import OG as _OG
import os, sys
import permute

rel, name, note = sys.argv[1], sys.argv[2], sys.argv[3]
rest = sys.argv[4:]
src = open(f"{_OG}/src/sf33rd/Source/{rel}").read()
if rest[:1] == ["--body"]:
    func = open(rest[1]).read().strip()
else:
    span = permute.find_definition(src, name)
    if span is None:
        sys.exit(f"{name} is not defined in {rel}")
    func = src[span[0]:span[1]]
    for i in range(0, len(rest), 2):
        if rest[i] not in func:
            sys.exit(f"not in {name}: {rest[i]!r}")
        func = func.replace(rest[i], rest[i + 1], 1)
ovp = f"{_OG}/analysis-ps2map/overrides/{os.path.basename(rel)}"
ov = open(ovp).read() if os.path.exists(ovp) else ""
block = f"/* {note} */\n{func}"
span = permute.find_definition(ov, name)
if span:
    # drop the comment right above the old definition too
    start = span[0]
    before = ov[:start].rstrip("\n")
    if before.endswith("*/"):
        c = before.rfind("/*")
        if c >= 0 and "\n" not in ov[c:start].strip().split("*/")[-1]:
            start = c
    ov = ov[:start] + block + ov[span[1]:]
else:
    ov = (ov.rstrip("\n") + "\n\n" if ov else "") + block + "\n"
open(ovp, "w").write(ov)
print(f"{name} -> {os.path.relpath(ovp, _OG)}")
