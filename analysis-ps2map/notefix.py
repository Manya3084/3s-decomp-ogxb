# Normalize "immediate is" notes before the "NAME is 0xADDR" scan.
# "table immediate is 0xA (_name)" and "_name immediate is 0xA" name _name;
# any other "immediate is" names nothing.
import re
def fix(s):
    s = re.sub(r"\n \* ", " ", s)
    s = re.sub(r"\b\w+(\s+\*)?\s+immediate is (0x[0-9A-F]+)\s*\((_\w+)\)", r"\3 is \2", s)
    s = re.sub(r"\b(_\w+)(\s+\*)?\s+immediate is (0x[0-9A-F]+)", r"\1 is \3", s)
    return s.replace("immediate is", "immediate at")
