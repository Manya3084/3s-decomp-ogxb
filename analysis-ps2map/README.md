# PS2-map pipeline

These scripts name `sf33rd.xbe` functions from the PS2 decompilation and port
its C files to the Xbox build. Everything in `src/sf33rd/Source/Game` that
says "Ported from the PS2 C" in its header was made with them. Run them from
any directory; paths come from `ps2paths.py`.

## What you need

- Retail `sf33rd.xbe` (see [docs/xbe.md](../docs/xbe.md) for the hashes).
  Write its path to `xbe.path` in the repository root, or set `SF33RD_XBE`.
- A checkout of the PS2 decompilation, <https://github.com/Manya3084/3s-decomp>,
  with its two executables in its root: `THIRD_U.BIN` (the Anniversary debug
  build, which has data symbols) and `THIRD_U.BIN.retail`. That project's
  README says how to get them. Write the path of its `src/` directory to
  `ps2.path`, or set `PS2_ROOT` to its root.
- Python 3, `libcapstone.so.5`, and a GCC that can build 32-bit code
  (`gcc -m32`, multilib). There are no Python packages to install.

None of these files go into git.

## The files that hold the results

| File | What it is |
| --- | --- |
| `config/sf33rd/symbols/funcs.txt` | Function names (also `tests/matched_bytes.py`) |
| `config/sf33rd/symbols/data.txt` | Data names, written by `writedata.py` |
| `analysis-ps2map/folded.json` | Addresses where MSVC merged identical bodies, and the PS2 names merged there. These stay unnamed. |
| `analysis-ps2map/overrides/<File>.c` | Xbox C that replaces the PS2 C: functions, data tables, and the declarations they need |
| `analysis-ps2map/datamap.json`, `denydata.txt` | Data placements from the debug build, and data names to leave out |
| `analysis-ps2map/deny.json` | Function pairings that were checked and rejected |

A ported file is always generated from its PS2 C, the names above, and its
override. Do not edit a ported file by hand: the next regeneration replaces
it. Put the change in the override, or in a "Read against the x86" note
(below), which regeneration keeps.

## Porting a PS2 file

Once per checkout, index the PS2 declarations: `python3 analysis-ps2map/declidx.py` (writes `declidx.json`).

1. `python3 analysis-ps2map/batch.py N` ports the next N placeholder files
   (files whose header says "PlayStation 2 C, not hand-adjusted for Xbox").
   For one file: `python3 analysis-ps2map/regen.py Game/X.c`.
2. The header lists each function with its address. A function whose x86
   has callees, constants, field offsets, or globals that its PS2 body lacks
   is marked `FLAG: ...`. Look at each one:
   - `python3 analysis-ps2map/flagctx.py Game/X.c` prints the x86 lines with
     the flagged values next to the C lines that use them.
   - `python3 analysis-ps2map/fx.py NAME` (or `ADDR:SIZE`) disassembles a body.
   - Most flags are compiler work: strides, folded constants, branchless
     selects, `rep movsd` counts. Some are Xbox changes.
3. Record what you found. Write lines `Game/X.c|FUNC|text` to a file and run
   `python3 analysis-ps2map/annotate.py FILE`. The flag becomes
   "Read against the x86: text".
4. Where the Xbox code differs, copy the function (or data table) into
   `overrides/X.c`, change it, and regenerate the file.
   `python3 analysis-ps2map/freeze.py Game/X.c NAME...` copies items from the
   committed version of a file into its override.
5. Check, then commit:

       python3 analysis-ps2map/ovrcheck.py      # every override reached its file
       python3 analysis-ps2map/lostedits.py Game/X.c   # nothing the committed file had was dropped
       gcc -m32 -std=gnu17 -Wno-incompatible-pointer-types -fsyntax-only -Iinclude src/sf33rd/Source/Game/X.c
       python3 analysis-ps2map/writedata.py
       make test

`portcheck.py` compares sets, so it cannot see a constant that moved, or a
call to a function with no name. Two more scans cover those:
`extracalls.py` (more x86 calls than C call sites) and `unmatchedcalls.py`
(an unnamed call that no C callee accounts for).

## Naming callees

A function that a ported body calls often has no name yet. These scripts
propose names. Each one is checked before it is added.

- `callround.sh SCRATCHDIR` lines up every named caller's x86 calls with its
  PS2 namesake's, in source and in switch-case order, and writes accepted
  proposals to `SCRATCHDIR/accept.txt`. Add them with
  `python3 analysis-ps2map/addnames.py SCRATCHDIR/accept.txt`.
- `tryname.py Game/X.c NAME:VA:SIZE ...` names candidates for unnamed code
  (an address taken from a caller's jump table or call, or an unnamed gap
  between two functions of one port), regenerates the port, and keeps the
  names only if the functions match. `movename.py NAME VA SIZE` moves a name
  whose scanned start or size is wrong.
- `strictpair.py` pairs a caller's unnamed calls with its C callees when the
  two lists have the same length and agree at every named position.
  `jalpair.py` does the same against the PS2 retail `jal` targets, for code
  the PS2 project keeps as asm.
- `callpos.py ADDR` shows each caller's C callee list beside its x86 call
  list, for reading a name off by hand.
- `vcheck.py NAME=ADDR` prints the C next to the x86 at that address.

Add a checked name with `python3 analysis-ps2map/addat.py NAME=ADDR` (it
sizes the body). Then run `python3 analysis-ps2map/unname_folds.py`. It takes
back a name whose body is an MSVC fold of identical PS2 twins. Then
`python3 analysis-ps2map/regen_new.py` regenerates every port that mentions a
new name. `fixnames.py` removes or moves names.

Things that have gone wrong before, and the checks that catch them:

- MSVC lays out switch cases in a different order, so call order can swap two
  callees. Compare sizes and bodies.
- Two PS2 functions with identical bodies share one Xbox address. Record the
  fold in `folded.json` instead of naming it.
- A PS2-only layer (`sce*`, `PS2RNA_*`, the memory card, pads) is replaced by
  Xbox code. Do not give the Xbox code the PS2 name.
- Runtime functions (`vsprintf`, `strncat`, the `/GS` check) belong in
  `config/sf33rd/symbols/xdk.txt`, not `funcs.txt`.

## Bulk naming from the PS2 map

The first pass that located the PS2 Game files is still here. From the
repository root:

    python3 analysis-ps2map/tables.py
    python3 analysis-ps2map/xprop2.py analysis-ps2map/xprop2.json
    python3 analysis-ps2map/gen.py '.'

`xprop2.py` with `HOLDOUT=n BULKONLY=1` hides 30% of the names and reports
how many it derives again, which measures its accuracy.
`datamap.py` places data symbols from the debug build into `datamap.json`.
