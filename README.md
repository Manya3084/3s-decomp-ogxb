# 3S Decomp OGXB

A decompilation of Street Fighter III: 3rd Strike for the original Xbox, from Street Fighter Anniversary Collection.

The binary is retail `sf33rd.xbe`. Do not commit it. Point the tools at your copy with `SF33RD_XBE`, or a one-line `xbe.path` (that file stays untracked).

| | |
| --- | --- |
| Size | 4,526,080 bytes |
| SHA-256 | `a04b2e91d65096f438790c14c95cf17272ef50c345b7a071d703a79d2ee9f3d6` |
| SHA-1 | `473b8c8bde2eb2eca2419ff4d0789cbd0aa3dcd8` |

`make check` confirms that file and runs the unit tests. `make info` prints the XBE identity.

## Target

Release build, 13 September 2004, XDK 5849, retail XOR keys. Title id `0x4343000F`. The disc file is `sf33rd.xbe`. The header's debug pathname, debug filename, and UTF-16 filename are the linker output `sf33rd.exe` (`SF33rdACR for XBOX\Release\sf33rd.exe`). The image contains that ASCII string once and `sf33rd.xbe` zero times. The RSDS record names `sf33rd.pdb`, which is not on the disc. Game code is `.text` at `0x11000`, size `0x1709E4`. XDK libraries sit in their own sections. The kernel thunk table has 150 `xboxkrnl` imports.

`config/sf33rd/symbols/funcs.txt` names 99 functions. The matching C is under `src/`. `make progress` counts those names. Twenty-five of them sit inside a scanned span, because this build often leaves no `int3` between a `ret` or a tail `jmp` and the next function. The rest of `.text` is still unnamed. `hsf.xbe` and `default.xbe` are not part of this tree.

`config/sf33rd/symbols/xdk.txt` records 405 XDK symbols at image addresses, plus 6 field offsets. Those names come from OOVPA signatures for this XDK, not from the game source.

Some of this build is not a paste of the PS2 source. `Init_ram_control_work` passes heap unit 16 and writes `rckeyctr` only. `ADXT_Pause` stores `tvofst` as a truncated integer and, when pausing, also calls the still-unnamed function at `0x16BF80`. `ADXT_EntryAfs` does not test the handle for null. `ADXT_SetOutVol` stores `outvol` as a 16-bit word. `ADXF_ReadNw` rejects a buffer that is not 4-byte aligned. `cvFsAddDev` loads the pointer at `0x2E0200`. That pointer addresses `0x2E0204`, the Xbox CVFS build string.

## Tools

The host needs `libcapstone.so.5` (`capstone` on Arch). There are no Python packages to install.

| Command | Result |
| --- | --- |
| `make scan` | `build/sf33rd/functions.txt`, `imports.txt`, `strings.txt`, `xrefs.txt` |
| `make disasm VA=0x125FF7` | One function, stopping where the bytes stop decoding |
| `make xref S=Game.c` | String and the function that pushes it |
| `make candidates` | `build/sf33rd/candidates.txt`. Does not edit `funcs.txt` |
| `make progress` | Names in `funcs.txt` against scanned starts |
| `make shaders` | Counts the `.xvu` vertex programs next to the XBE |

`make candidates` reads PS2 sources from `PS2_SRC`, or from a one-line `ps2.path` (that file stays untracked). A line there is a suggestion.

The 490 `.xvu` files are NV2A vertex programs (magic `0x2078`). `make shaders` checks the header and the file size. Turning them into SPIR-V is later work.

## Where to start

- [Decompiling](docs/decompiling.md) covers how a name gets into `funcs.txt`.
- [XBE](docs/xbe.md) covers the retail image the tools expect.
- [XDK](docs/xdk.md) covers the library symbols, the startup chain, and the Xbox-only source files.

The tools in this repository are MIT. `tools/data/xboxkrnl.txt` is the nxdk kernel export list, CC0-1.0, © 2017 Stefan Schmidt.
