# Decompiling

Name functions in retail `sf33rd.xbe` after the PS2 retail names exist. The shared fight code is the same C. This XBE does not store those function names.

## Setup

`sf33rd.xbe` from the US Anniversary Collection disc:

| | |
| --- | --- |
| Size | 4,526,080 bytes |
| SHA-256 | `a04b2e91d65096f438790c14c95cf17272ef50c345b7a071d703a79d2ee9f3d6` |
| SHA-1 | `473b8c8bde2eb2eca2419ff4d0789cbd0aa3dcd8` |

```bash
make check
make scan
make xref S=Game.c
make disasm VA=0x125FF7
```

`make check` prints `sf33rd.xbe absent; skip` when the binary is not on this machine.

## What a name is

Names live in `config/sf33rd/symbols/funcs.txt`:

```
Name = 0x00ADDR; // type:func size:0xNN
```

`size` is the matched body, including that function's own int3 padding, up to the next function. When MSVC leaves no int3 between a `ret` or a tail `jmp` and the next function, the scan keeps only the earlier start, and `size` is shorter than that scanned span. A jump table between two functions stays inside the size. `make disasm` stops at the first byte that does not decode and prints how many bytes remain until the next scanned start.

A name belongs in that file when the bytes match the C under `src/`. The names already there are a matched sample, not a guess from a candidate list. These are enough:

- The function's own string names it, and the body implements that string. `make xref S=...` shows the push and the scanned start around it.
- The PS2 source has one function that contains that string, and the Xbox body is that function. `make candidates` writes those as suggestions in `build/sf33rd/candidates.txt`.

A suggestion is not a name. `candidates.py` does not edit `funcs.txt`.

## Bodies located from the PS2 map

The PS2 retail tree (`ps2.path`) now names every function on the disc. Files that the Xbox tree did not have yet are brought in from that map. Their `src/` file is the PS2 C, copied unchanged. A header lists each Xbox address and size and says `PlayStation 2 C, not hand-adjusted for Xbox`. Those bodies were not read line by line against the C. Each one was accepted only when all of these hold:

- Evidence places it. A function-pointer table in `.rdata` or `.data`, or one a function builds on its stack with `mov [ebp - n], imm32`, lines up with a PS2 table, or with a window of one when tables sit back to back. At least two named entries agree, and none disagree except where MSVC folded two byte-identical PS2 bodies into one. The body is the entry at that index. A folded body stays unnamed: one that two paired table slots map to different PS2 names. MSVC merged byte-identical functions, so for example `Passive00_0004` through `Passive19_0004` are one body at `0xD4486`. The file header records such a name as `folded into 0xADDR`. Or a table with no named entries lines up with a PS2 table slot by slot, by call-argument signature: each body's (named callee, small constant arguments) calls appear in the PS2 function at that index. Every comparable slot must match, and the next-best window must have clear mismatches. Or a named function's own C declares a function-pointer array, local or file-scope. Its x86 stores that many pointers to consecutive stack slots, or indexes one table address, and entry i is the array's i-th initializer. Or a named caller's call list lines up with its PS2 namesake's (in order between agreeing anchors, or by unique call counts). Or it is the matching position between two named functions from the same PS2 file in source order. Or its constant, offset, and callee sets equal one PS2 function's and no other's. Or its fingerprint is the mutual best match.
- The non-trivial constants and the struct field offsets in the x86 body agree with the PS2 body.
- Every named function it calls is also called by the PS2 body, and the call counts are close.
- The number of call sites differs by no more than a factor of 3, the x86 size is 0.2 to 2 times the PS2 size, and the PS2 function has no byte-identical twin that MSVC could fold (a table index pins twins).
- No constant pushed as an argument to a named callee is missing from the PS2 body's immediates.

A size is the body's control-flow extent: branches, jump tables, and in-range jumps out to the last instruction, plus `int3` or `nop` padding. The same walk reproduces every hand-checked size. The table rule does not use the constant check, because some structures sit at other offsets on Xbox.

Hiding 30% of the hand-checked names and running the same rules recovered about 45% of them with no wrong name, over four runs. A body under 0x60 PS2 bytes needs two agreeing callers or a source-order position. These names are still a lower bar than a hand port. When one is ported by hand, replace the header and adjust the C as for the other files.

## Callees named from call order

Many PS2-located bodies called functions that had no name yet. These callees were named from their callers. For each function named in both builds, its x86 direct call and tail-jump targets are lined up with the `jal` and `j` targets of its PS2 retail namesake. Named targets must match by name. An unnamed target lined up with a PS2 callee that has no Xbox name yet is one vote for that name. The best mutual pair (the address's top name, and that name's top address) is accepted first, a quarter of the candidates per round, and the round repeats with the new anchors. A folded target uses up one PS2 call without voting.

MSVC lays out switch cases in a different order from the source, often reversed. The call list is therefore also built in case order. The order comes from the first compare chain (`sub`/`cmp`/`dec` followed by `je`, with the fallthrough as the default) or jump table (`jmp [reg*4 + table]`, with the `ja` target as the default). Each call is sorted by the case block that holds it. The order whose alignment matches more named targets is used. When the two orders tie and give different votes, the caller is skipped. Without this step, `End_Pattern` (a 5-byte `jmp` to `Next_Be_Free` at `0x281A9`, 2208 calls) and `EM_Term` (`0x2D707`) were swapped.

A final pass realigns every caller with all names in place. An accepted callee is kept when it lines up with its name at least as often as it fails to: a hit is a caller where the address lines up with its name, a miss is one where it does not. With fewer than five hits, its x86 size must be 0.15 to 2.5 times the PS2 size. The selection also uses link order. The name's PS2 address should lie between the PS2 addresses of the nearest named Xbox functions on each side. A callee seen in two or more callers is accepted unless it has three hits or fewer and fails link order. A callee seen in one caller needs link order on both sides, or on one side together with the constant and offset check above. 316 names came from this, in three rounds. 89 proposals were held back, among them the `bg0101`-style background routines, whose PS2 bodies are byte-identical twins. Rerun against the names already in `funcs.txt`, the same alignment contradicts one of them, `SJRBF_EntryErrFunc`: its PS2 body is a twin of `ADXSTM_EntryEosFunc`, so the Xbox address is likely one folded body.

## Ports of the PS2-copy files

`include/structs.h` holds the game structures from the PS2 tree. Both builds are 32-bit with the same field sizes, so the layouts are unchanged. The `_Static_assert` block at its end lists offsets read from XBE code. Sources are checked with `gcc -m32 -std=gnu17 -Wno-incompatible-pointer-types -fsyntax-only -Iinclude FILE`. The last flag allows the PS2 function-pointer tables whose declared type has no parameter list, which newer GCC rejects by default.

A PS2-copy file is ported in four steps:

- `analysis-ps2map/portgen.py` keeps the functions that are located or folded and moves the rest under `#if 0`. It names each callee that has no XBE name by its aligned call target (`sub_ADDR`), or records that it is folded or has no aligned call. Declarations come from the PS2 headers until GCC is satisfied.
- A file-scope table with an XBE address is compared with the XBE: byte for byte for plain data (compiled for `-m32` and dumped), entry by entry for function pointers, where a folded entry must sit at the address its fold note gives. A table with no address is searched for: near the unnamed addresses its functions use, and for pointer tables also through `.rdata` and `.data`. The file header gives every comparison's result.
- `analysis-ps2map/portcheck.py` compares each function with its PS2 namesake. Anything the x86 has that the PS2 body lacks is flagged: callees, constants other than small ones (within 1, for compare rewrites), field offsets, globals (from the anniversary debug ELF), and unnamed data. Frame adjustments, the `frw` stride `0x700`, and the `WORK`/`PLW` sizes are ignored. On the hand-ported files it flags `Country` in `effect_51_init`, the one real change there, plus two strength-reduction constants and one char table.
- Each flagged function is read against its x86. The header says what was found ("Read against the x86: ..."), and the C is changed where the Xbox code differs.

A function without a flag has the same callees, constants, offsets, and globals as the PS2 body. Its control flow was not read line by line.

## Data names

`config/sf33rd/symbols/data.txt` names globals with their PS2 names: `Name = 0x00ADDR; // type:data size:0xNN hand|map`. `hand` rows were read off bodies in hand-ported files. `map` rows come from the anniversary debug ELF. For each function named in both builds, the debug body's data references are compared with the XBE body's absolute operands. A symbol's XBE base is the one that makes every function's addresses fall on offsets that same function used. Checked against the hand rows, 264 of 270 map placements agree. A map row that conflicts with a hand row is dropped. `size` is the PS2 debug size, and the Xbox layout can differ.

## How starts are found

`.text` is MSVC x86 from XDK 5849. The scan keeps a start when it is:

- the entry point `0x125FF7`, or the first byte of `.text`
- `push ebp; mov ebp, esp` with a ret, int3, or nop before it
- the instruction after a `ret` and at least one int3 or nop
- the instruction after `ret imm16` when padding follows, or that address is 16-byte aligned

Each of those addresses has to decode as at least two instructions. A `ret` that is really the middle of another instruction is left out, because the following bytes do not decode.

Calls into `D3D`, `DSOUND`, `XACTENG`, `XONLINE`, and `WMADEC` leave `.text`. Those sections are the XDK libraries. The 150 kernel imports are in `build/sf33rd/imports.txt` after `make scan`.

Library symbols detected in this image are listed in `config/sf33rd/symbols/xdk.txt`. They are not game names and they do not go in `funcs.txt`. See [XDK](xdk.md). An assert path such as `Source\XBOX\xlive\xlive_main.cpp` shows which file was compiled. It does not name the function that pushes it.

## Shaders

`media/Shaders` next to the XBE holds the vertex programs. `make shaders` checks that each `.xvu` is magic `0x2078` plus a 16-byte instruction count that matches the file size. `tools/ogxb/xvs.py` decodes each slot. A slot issues one MAC op (`NOP`, `MOV`, `MUL`, `ADD`, `MAD`, `DP3`, `DPH`, `DP4`, `DST`, `MIN`, `MAX`, `SLT`, `SGE`, `ARL`) and one ILU op (`NOP`, `MOV`, `RCP`, `RCC`, `RSQ`, `EXP`, `LOG`, `LIT`). Each of the three sources has a negate, a swizzle, and a mux (temporary, input, or constant). R12 reads as `oPos`. When both opcodes are set, the ILU result is written to R1. D3D constant `c0` is slot 96. `python3 tools/xvs.py FILE.xvu` prints one program. `DOF1.xpu` and `DOF2.xpu` are `PSB0` files: a 240-byte combiner definition, not vertex programs. `tools/ogxb/xpu.py` decodes the eight general stages and the final stage. A general stage computes A·B and C·D, then writes the sum or a mux on `r0.a`. The final stage computes A·B + (1−A)·C + D. `python3 tools/xpu.py FILE.xpu` prints one program.

`python3 tools/spirv.py FILE -o OUT.spv` writes SPIR-V 1.0 for one file. The module is not written next to the shader. A vertex module runs each slot through the last `FINAL`. `ARL` sets the address register to `floor(x + 0.001)` before the rest of that slot. Screen x and y snap to 1/16 of a pixel. Y is not flipped. `gl_Position` is `((x * 2 / width - 1) * w, (y * 2 / height - 1) * w, 0.5 * w, w)`, with x and y clamped to ±1e38 and w held in `[2^-64, 2^64]`. Point size is `clamp(oPts.x, 1, 64)`. `MUL`, `RCP`, and `LOG` are ordinary floats. `RCC` is a reciprocal clamped to that same range of magnitudes. Vertex set 0 binding 1 is a vec4 whose xy is the surface size in pixels. Binding 0 is present when a slot reads or writes a constant, and it holds 192 vec4s. A constant write stays in the shader. Locations 0 and 1 are the front colors, 2 and 3 the back colors, 4 through 7 the texture coordinates, 8 is fog, and 9 is window z as `(z, 16777215 - z) * w`.

A combiner module samples `2D_PROJECTIVE` and `3D_PROJECTIVE`. The 3D mode is the first slice of a 2D sample, with the coordinate divided by w and clamped to ±65536. `PASS_THROUGH` clamps the varying to `[0, 1]`. `CLIP_PLANE` discards on the compare word. Cube, bump, BRDF, and dot-product modes leave that texture at zero. `r0` starts as `(0, 0, 0, t0.a)`. The general stages and the final formula are the words stored in the file. `DOF1` and `DOF2` store a zero final combiner, so the fragment color is black and the lerp stays in `r0`. Fragment set 0 binding 0 is 16 vec4 pixel constants followed by the fog color. Fragment set 1 bindings 0 through 3 are `sampler2D`. Locations 0 and 1 are the front colors, 4 through 7 are texture coordinates, and 8 is fog.
