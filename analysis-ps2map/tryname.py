# tryname.py Game/X.c NAME:VAHEX:SIZEHEX ... [--keep-all] : name candidate
# functions (addname.py: funcs.txt and the matched sample), regenerate the
# port, build, and report each one's status. Unless every one is match or
# reloc, funcs.txt, the sample, and the port are put back (--keep-all keeps
# them, to work on a near miss).
import sys, subprocess, json, re, shutil
import os
OG=os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
rel=sys.argv[1]; cands=[a.split(':') for a in sys.argv[2:] if not a.startswith('--')]
keepall='--keep-all' in sys.argv
F=OG+'/config/sf33rd/symbols/funcs.txt'; M=OG+'/tests/matched_bytes.py'
bak={p:open(p).read() for p in (F,M,OG+'/src/sf33rd/Source/'+rel)}
for n,a,s in cands:
    r=subprocess.run(['python3',OG+'/analysis-ps2map/addname.py',n,a,s],capture_output=True,text=True)
    print(r.stdout.strip(), r.stderr.strip()[-200:])
r=subprocess.run(['python3',OG+'/analysis-ps2map/regen.py',rel],capture_output=True,text=True,cwd=OG); print(r.stdout.strip()[-300:], r.stderr.strip()[-300:])
subprocess.run('python3 tools/build_c.py && python3 tools/objdiff.py',shell=True,cwd=OG,capture_output=True)
R=json.load(open(OG+'/build/objdiff.json'))
st={f['name']:f['status'] for o in R.values() for f in o['functions']}
ok=True
for n,a,s in cands:
    print(n, st.get(n)); ok = ok and st.get(n) in ('match','reloc')
if not ok and not keepall:
    for p,t in bak.items(): open(p,'w').write(t)
    subprocess.run(['python3',OG+'/analysis-ps2map/regen.py',rel],capture_output=True,cwd=OG)
    print('reverted')
