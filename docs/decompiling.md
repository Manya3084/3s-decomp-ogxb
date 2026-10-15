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

`size` is the matched body, including that function's own int3 padding, up to the next function. When MSVC leaves no int3 between a `ret` and the next function, the scan keeps only the earlier start, and `size` is shorter than that scanned span. A jump table between two functions stays inside the size. `make disasm` stops at the first byte that does not decode and prints how many bytes remain until the next scanned start.

A name belongs in that file when the bytes match the C under `src/`. The names already there are a matched sample, not a guess from a candidate list. These are enough:

- The function's own string names it, and the body implements that string. `make xref S=...` shows the push and the scanned start around it.
- The PS2 source has one function that contains that string, and the Xbox body is that function. `make candidates` writes those as suggestions in `build/sf33rd/candidates.txt`.

A suggestion is not a name. `candidates.py` does not edit `funcs.txt`.

## How starts are found

`.text` is MSVC x86 from XDK 5849. The scan keeps a start when it is:

- the entry point `0x125FF7`, or the first byte of `.text`
- `push ebp; mov ebp, esp` with a ret, int3, or nop before it
- the instruction after a `ret` and at least one int3 or nop
- the instruction after `ret imm16` when padding follows, or that address is 16-byte aligned

Each of those addresses has to decode as at least two instructions. A `ret` that is really the middle of another instruction is left out, because the following bytes do not decode.

Calls into `D3D`, `DSOUND`, `XACTENG`, `XONLINE`, and `WMADEC` leave `.text`. Those sections are the XDK libraries. The 150 kernel imports are in `build/sf33rd/imports.txt` after `make scan`.

## Shaders

`media/Shaders` next to the XBE holds the vertex programs. `make shaders` checks that each `.xvu` is magic `0x2078` plus a 16-byte instruction count that matches the file size. Decoding those instructions, and the register-combiner pixel state, comes after the CPU names.
