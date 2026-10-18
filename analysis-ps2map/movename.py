# movename.py NAME VAHEX SIZEHEX : move NAME's funcs.txt row and its
# matched-sample entry to a new start and size (a scanned start that is
# wrong, or a size that took in the next function). Regenerate the port
# afterwards (regen.py).
import sys, re, subprocess
import os
OG=os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
n, va, sz = sys.argv[1:4]
F=OG+'/config/sf33rd/symbols/funcs.txt'; M=OG+'/tests/matched_bytes.py'
f=open(F).read()
f2=re.sub(r'^' + re.escape(n) + r' = 0x[0-9A-F]+; // type:func size:0x[0-9A-F]+\n', '', f, count=1, flags=re.M)
assert f2!=f, 'no row'
open(F,'w').write(f2)
m=open(M).read()
L=m.split('\n')
i=next(k for k,l in enumerate(L) if l.startswith('    ("%s", 0x' % n))
j=i+1
while not (L[j].strip().startswith('"') and L[j].rstrip().endswith('"),')): j+=1
del L[i:j+1]
open(M,'w').write('\n'.join(L))
print(subprocess.run(['python3',OG+'/analysis-ps2map/addname.py',n,va,sz],capture_output=True,text=True).stdout.strip())
