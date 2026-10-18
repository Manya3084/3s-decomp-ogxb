# Building and relinking

`src/` compiles with the XDK 5849 compiler, and the objects are put back into
the retail image. The retail XBE supplies everything that has no C yet.

```
make build     # tools/build_c.py: src/ -> build/obj/*.obj
make objdiff   # tools/objdiff.py: compare each function with retail
make relink    # tools/relink.py: build/sf33rd.xbe from the objects + retail
```

You need Wine, the XDK 5849 install (point `XDK` at its root, the directory
that holds `xbox/bin/vc71`, or write that path to an untracked `xdk.path`),
and the retail `sf33rd.xbe`. The XDK is proprietary: nothing from it is in
this tree, and the shims in `include/msvc/` are written here.

## Compiling

`build_c.py` runs `xbox/bin/vc71/CL.Exe` under Wine, 24 files at a time, and
writes `build/compile.json` with each file's result. All 442 files compile.

Three more rewrites come from comparing builds, and each is listed in a
file `build_c.py` reads:

- `config/sf33rd/noproto.txt`: callees a file calls with no prototype in
  scope. C's default promotions then widen a `u16` or `s16` argument at the
  call (`movzx`/`movsx` before the push), as the retail code does, where a
  prototype passes it as it is. The list came from building every file with
  all its integer-only declarations unprototyped and keeping, per file and
  callee, those that made a caller match while no matching caller needed the
  prototype: 819 of them in 126 files, which matched 357 more functions and
  lost none.
- `config/sf33rd/static.txt`: functions that were `static`. VC7.1 gives a
  static function whose address is not taken its first argument in `eax`
  (`remake_x_mvstep` starts with `movsx eax, ax`), and the PS2
  decompilation declares them global. Making every file-local function
  static loses 995 matches, so only the functions whose retail body reads a
  register argument were tried, and the 11 that match are listed.
  `tools/knrsearch.py --static` later tried every function its own file
  calls, one file at a time, and added 9 more (`mlt_obj_trans_cp3_ext`
  and CRI's `toUpperStr` among them).
- `config/sf33rd/knr.txt`: definitions that were old-style. A caller in
  the same file then sign-extends each `s16` argument to `int` (`movsx`),
  where a prototyped `s16` parameter lets it pass only the low half
  (`xor ecx, ecx; mov cx, ...`), while the body still narrows the value
  back. `set_char_move_init2` is old-style: its 26 `comm_*` callers in
  CHARSET.c match only that way, and its own body matches both ways.
  `tools/knrsearch.py` tries every in-file-called definition with a narrow
  parameter this way, one file at a time; it found 10 more (14 matches).
- `config/sf33rd/declfix.txt`: a callee's parameter or return type as one
  file's declaration has it. Capcom's prototypes differed between files
  (`set_char_move_init`'s index is `s32` where its callers sign-extend it),
  so a search that changes every declaration at once loses as much as it
  gains; `tools/permute.py` tries it per caller and writes the line when
  the caller then matches.
- A declaration takes the integer return type of the function's one
  definition in `src/` (`Game.c` declared `s32 Title_At_a_Dash()`, which
  returns `s16`).

VC7.1 compiles C89. The headers get two shims: `types.h` defines
`_Static_assert` (a negative array size is the failure) and
`__builtin_offsetof` when `_MSC_VER` is set, and `include/msvc/stdint.h`
supplies the fixed-width types. Three habits of the PS2 tree are not C89, and
the generated ports may not be edited by hand, so `build_c.py` compiles a
prepared copy (in `build/prep/`, with a `#line` back to the original):

- A parameter with no name (`s32 /* unused */`, `DADD*`) gets one.
- A `static` prototype whose body is not in the file (the body is under
  `#if 0`) loses `static`, so the call becomes an external reference that
  the relink resolves to the retail address.
- Designated initializers become positional when they name the struct's
  fields in declaration order with none skipped (`efff6_etc_data`).

`tests/test_build_prep.py` covers the three rewrites.

## Flags

The flags were chosen by compiling a sample of each tree with each candidate
set and counting the functions whose bytes and relocations match retail.

| Tree | Flags | Sample match |
| --- | --- | --- |
| `src/cri/` (CRI middleware) | `/O2 /Ob1 /Gy` | 235 of 341 |
| everything else (Capcom) | `/O1 /Ob1 /Oi /arch:SSE /Op /Gy /GS` | 367 of 499 before `/Ob1` |
| `src/sf33rd/Source/Compress/zlib/` (stock zlib 1.1.4) | `/O1 /Oi /arch:SSE /Op /Gy /GS` | all 19 placed |
| `src/sf33rd/Source/Compress/` (zlibApp.c, Lz77) | `/O1 /arch:SSE /Op /Gy /GS` | |

zlib is `/Oi`: `inflate_flush` and `inflate_blocks` inline their `zmemcpy`
(`memcpy`) copies, and without `/Oi` both come out shorter than retail.
`decLZ77withSizeCheck` differs with `/Oi`, so `Lz77` and `zlibApp.c` keep
the set without it.

`/Oy-`, the flag found on the XDK sample code in the Live layer, matches 96
of the 499 game functions: the C game code omits the frame pointer. `/G7`
lowers both trees. `/GS` adds four game matches, and retail calls
`__security_check_cookie` in those functions. CRI's code never inlines a
function that is not marked inline (`cvFsError` calls `cvFsCallUsrErrFn`),
so it is `/Ob1`: `/O2` alone matched 199 of the 341, with no function that
`/Ob1` loses. The CRI version string ends "Append: MSC1310", the same VC7.1.
Capcom's code is `/Ob1` too: compiling every Capcom file with it against `/O1` alone gains 128 functions (106 of them in `Ck_Pass.c`) and loses one, in the stock `adler32.c`, which keeps `/O1`.
It is `/Oi` as well: `work_init_zero` is an inline `memset` (`rep stosd`, then `rep stosb`), and `/Oi` over the whole tree gains four functions and loses none.
`build/compile.json` records a hash of each file's flags and prepared text,
and a file is rebuilt when it changes (the prepared text also depends on
other files: the definitions elsewhere in `src/` and the lists in
`config/`).

## Comparing

`objdiff.py` compares every function in every object with the retail body at
its `funcs.txt` address. A folded name (`analysis-ps2map/folded.json`) is
compared with the body it was merged into. Bytes that a relocation patches
are masked, and each relocation is checked separately:

- A named target (`funcs.txt`, `xdk.txt`, `data.txt`, or a `sub_`/`D_`/`dat_`
  placeholder) must be the address the retail code uses at that spot.
- A target local to the object (a string literal, a float constant, a static
  table) has no name. Its address is read off the retail code. Every use of
  one local section must agree on that address, and the section's bytes are
  then compared with the retail bytes there.

A function is `match` when its bytes and all its relocations agree and the
rest of its retail slot is padding. `reloc` means the bytes agree but a
relocation does not; that is usually a wrong name or a wrong placeholder, and
the notes in `build/objdiff.json` say which target. `diff` means the bytes
differ.

Results, counting each retail address once:

| Tree | match | reloc | diff |
| --- | --- | --- | --- |
| Capcom | 6117 | 0 | 480 |
| CRI | 254 | 0 | 87 |
| all | 6371 of 6941 | 0 | 567 |

The matching functions are 0xABCEF of the 0xD3B20 bytes that have C.

## Fixing the decompile from the comparison

A function whose bytes match but whose relocations do not is a fault in the
names, not in the code, and the retail code says what the target should be.
The first comparison had 507 of them.

- A global the C uses that `data.txt` does not name is reported with the
  address the retail code uses (`unresolved NAME (retail ADDR)`). Only
  functions whose bytes match are used, so the C's field offset is the
  retail one and ADDR is the symbol's base. `analysis-ps2map/relinkdata.py`
  collects these into `relinkdata.json` (a name is kept only when every use
  agrees, and rounds accumulate), and `writedata.py` writes the ones at data
  addresses as `relink` rows: 343 so far, with no conflict against a hand or
  map row.
- A name at a code address is a function the C calls or puts in a table
  while its own C is still under `#if 0`. `analysis-ps2map/relinkfuncs.py`
  names it with `addat.py` when it is alone at an unnamed address (90 new
  locations), and records a fold when several names share the address (11
  addresses). Where a fold address had a `funcs.txt` name, the PS2 C shows
  identical twins (`bg_move_common` and `bg0701_move00` both call
  `bg_x_move_check` and `bg_y_move_check`), so as for every fold the name is
  removed: `bg_move_common`, `bg_base_move_common`, `bg0401_init01`, and
  `end_C00_2000`. `regen_new.py` then brings the new locations' C out of
  `#if 0`, which compiles and is compared in the next round. A second round
  found 9 more; a third found none.

The loop is:

```
python3 analysis-ps2map/relinkdata.py
python3 analysis-ps2map/relinkfuncs.py --apply
python3 analysis-ps2map/regen_new.py
python3 analysis-ps2map/writedata.py
make relink
```

`regen.py` used to write some header notes twice: a carried "Read against
the x86" note can contain lines that `portgen.py` writes itself, and repeats
built up over earlier runs (one `menu.c` note held a sentence eight times).
A carried note now drops any sentence the new header already has or that
repeats an earlier one, and the regenerated files lost those repeats.

The last 21 `reloc` functions were each read against the x86. They came
down to nine faults:

- `MPP` had the PS2 layout. Five Xbox bytes follow `inGame`, so `ctrDemo`,
  `language`, `cutAnalogStickData`, and `useAnalogStickData` are 5 bytes
  later (`include/structs.h`, and the local copies in `SYS_sub.c` and
  `texgroup.c`, whose asserts gave the PS2 offsets). `Replay` stores to one
  of those Xbox bytes (0x7AA5EE), not to `initTrainingData`: the PS2
  `Replay` has no such store, and the training code uses
  `initTrainingData` at +0x29.
- Four bases were wrong, and `relinkdata.py` now moves a base when every
  byte-matching use agrees on one shift and no fully matching function uses
  the old address: `effinitjptbl` starts at 0x25B9F0 with its `NULL` entry
  (the table check had placed it at its first non-null entry),
  `pl03_exatt_table` and `pl04_exatt_table` are 0x40 later (the hand rows
  had been read off an operand with the C's `-0x40` index folded in), and
  `Face_Pos_Data` is 0x267658. `plw` and the `ppg*` textures stay where they
  are, because matching functions use them there.
- The AIXP getters call AIX's own error jump `xb_aixerr_CallErrFunc1`.
- `ppgWorkInitializeApprication` clears the loading-message texture right
  after the `ppgScr` group, not last.
- `ta_sub.c` and `win_pl.c` had a partial `PLW` that ended at
  `player_number`, so `&plw[1]` came out 0x398 in; `PLW` is 0x46C.
- `cseSysSetMono`, `cseSysSetMasterVolume`, `cseSeStopAll`, and
  `cseTsbSetBankAddr` sit with `cseTsbRequest`, so their C moved to
  `cse.c`. In `Sound3rd.c` and `color3rd.c` the compiler inlined them, and
  retail calls them.
- Two folds were twins that are separate bodies: `end_C01_0000` and
  `end_301_0003` each sit next to the table that uses them, so
  `end_400_1000` and `end_401_0000` are their own functions too. Removing a
  fold exposed that `headers.py` and `portgen.py` read fold lines back from
  old headers; both now drop a fold line once `folded.json` no longer has
  the name or `funcs.txt` gives it an address.

`tools/relocat.py FUNC` prints the compiled and retail instruction at each
flagged relocation, with the C's addend. The 1245 `diff` functions differ in
code and are fixed by reading each one against the x86.

## Fixing differing code

`tools/asmdiff.py FUNC` prints the compiled and retail code side by side
(`--list N` gives the smallest differing functions). `tools/permute.py`
tries the source rewrites that the PS2 decompilation cannot preserve, one at
a time, and keeps a rewrite only when the function's code gets closer to
retail: a comparison against a constant in its other form (`< 31` and
`<= 30`; MIPS has only "set less than", so the decompiler normalised them),
the width of a local or parameter (s16/u16/s8/u8 against s32), the
operands of a comparison in the other order (`a < b` as `b > a`), an early
return turned round, two independent assignments in the other order, and,
in the file's declaration of a callee, its return type (when it has no C
definition) or the type of one integer parameter (a caller's prototype
decides how a narrow argument is extended), an if/else that assigns one
target as a conditional expression (MSVC computes a ternary of constants
with `neg`/`sbb`/`and`/`add`), and `if (x) return 1; return 0;` as
`return x != 0;`. A match
is written back as an override for a generated port, or into a hand port.
Over the 617 Capcom functions of 0x200 bytes or less it matched 81, and 5 of the 94 larger ones; with the further rewrites a pass over all 720 left matched 17 more, and a pass with the callee-declaration rewrites 64 more, without a regression elsewhere (a full rebuild is compared before a result is kept). Each override note says which rewrite was made.

`--accept-reloc` also writes a result whose bytes match but whose relocations the check cannot resolve yet, a global the C names that `data.txt` lacks. `relinkdata.py` then names those globals from the next `objdiff.py` report; 18 functions matched that way. Run `objdiff.py` before `relinkdata.py`, since it reads that report.

## Relinking

`relink.py` starts from the retail file and writes each chosen function into
its slot with its relocations applied. Named targets get their retail
addresses, and local data is pointed at the copy `objdiff.py` placed. Section
digests (SHA-1 of the section's raw size as four little-endian bytes, then
its raw bytes) are recomputed for each section that changed.

By default only `match` functions are written, so the result must be
identical to retail. It is: every matching function goes in, and
`build/sf33rd.xbe` has the retail SHA-256
`a04b2e91d65096f438790c14c95cf17272ef50c345b7a071d703a79d2ee9f3d6`. 39 more
matches are skipped because they use a local section that could not be
placed.

`--nonmatching` also writes each `reloc` and `diff` function that fits its
slot and whose relocations all resolve. That image runs this
tree's C in place of Capcom's code. It has not been booted, and a function
that differs in behaviour will show up there. The RSA signature in the
header is Microsoft's and is not recomputed, so like any modified XBE it
needs an emulator or a console that does not check it.

`folded.json` has three entries whose key is not an image address (`0x4`
`VS_Q_DS`, `0xD` `Passive16_0122`, `0xE2D` `Passive18_0115`). `relink.py`
skips them.
