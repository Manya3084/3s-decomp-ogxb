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
| `src/cri/` (CRI middleware) | `/O2 /Gy` | 147 of 255 |
| everything else (Capcom) | `/O1 /arch:SSE /Op /Gy /GS` | 367 of 499 |

`/Oy-`, the flag found on the XDK sample code in the Live layer, matches 96
of the 499 game functions: the C game code omits the frame pointer. `/G7`
lowers both trees. `/GS` adds four game matches, and retail calls
`__security_check_cookie` in those functions.

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
| Capcom | 4955 | 460 | 1086 |
| CRI | 152 | 47 | 142 |
| all | 5107 of 6845 | 507 | 1228 |

The matching functions are 0x75055 of the 0xD4BA5 bytes that have C.

## Relinking

`relink.py` starts from the retail file and writes each chosen function into
its slot with its relocations applied. Named targets get their retail
addresses, and local data is pointed at the copy `objdiff.py` placed. Section
digests (SHA-1 of the section's raw size as four little-endian bytes, then
its raw bytes) are recomputed for each section that changed.

By default only `match` functions are written, so the result must be
identical to retail. It is: 5068 compiled functions go in, and
`build/sf33rd.xbe` has the retail SHA-256
`a04b2e91d65096f438790c14c95cf17272ef50c345b7a071d703a79d2ee9f3d6`. 39 more
matches are skipped because they use a local section that could not be
placed.

`--nonmatching` also writes each `reloc` and `diff` function that fits its
slot and whose relocations all resolve (398 of them). That image runs this
tree's C in place of Capcom's code. It has not been booted, and a function
that differs in behaviour will show up there. The RSA signature in the
header is Microsoft's and is not recomputed, so like any modified XBE it
needs an emulator or a console that does not check it.

`folded.json` has three entries whose key is not an image address (`0x4`
`VS_Q_DS`, `0xD` `Passive16_0122`, `0xE2D` `Passive18_0115`). `relink.py`
skips them.
