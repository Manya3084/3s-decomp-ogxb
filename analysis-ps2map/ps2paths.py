# Paths for the analysis-ps2map scripts. OG is this repository, SP this
# folder, and PS the root of the PS2 decompilation (sf33rd), found from
# PS2_ROOT or from the parent of the directory named in ps2.path (which
# points at its src/). The XBE comes from xbe.path or SF33RD_XBE, as for
# the other tools.
import os, sys
# Set iteration order depends on the string hash seed; fix it so that
# generated files are the same on every run and machine.
if os.environ.get("PYTHONHASHSEED") != "0" and sys.argv and os.path.isfile(sys.argv[0]):
    os.environ["PYTHONHASHSEED"] = "0"
    os.execv(sys.executable, [sys.executable] + sys.argv)
SP = os.path.dirname(os.path.abspath(__file__))
OG = os.path.dirname(SP)
def _ps2_root():
    env = os.environ.get("PS2_ROOT")
    if env: return env.rstrip("/")
    p = os.path.join(OG, "ps2.path")
    if os.path.isfile(p):
        src = open(p).read().strip().rstrip("/")
        return os.path.dirname(src) if os.path.basename(src) == "src" else src
    return ""
PS = _ps2_root()
