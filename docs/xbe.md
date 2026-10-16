# Retail sf33rd.xbe

US Street Fighter Anniversary Collection, file `sf33rd.xbe`. The checked-in copy of these facts is `config/sf33rd/xbe.txt`.

| | |
| --- | --- |
| Size | 4,526,080 |
| SHA-256 | `a04b2e91d65096f438790c14c95cf17272ef50c345b7a071d703a79d2ee9f3d6` |
| SHA-1 | `473b8c8bde2eb2eca2419ff4d0789cbd0aa3dcd8` |
| Title id | `0x4343000F` |
| Built | 2004-09-13 00:26:26 UTC |
| XDK | 5849 |
| Keys | retail. Entry XOR `0xA8FC57AB`, kernel thunk XOR `0x5B6D40B6` |
| Entry | `0x125FF7` |
| `.text` | VA `0x11000`, file size `0x1709E4` |
| Imports | 150 kernel ordinals at the decoded thunk VA |
| Debug path | `d:\ac_work\bloom_projects\StreetFighterAnniversaryCollection_20040826v00\sf33rd\Project\SF33rdACR for XBOX\Release\sf33rd.exe` |
| PDB | `sf33rd.pdb`, RSDS age 1, not on the disc |

The disc file is `sf33rd.xbe`. Three header fields store the XDK linker's output name, `sf33rd.exe`:

| Field | File offset | VA | Bytes |
| --- | --- | --- | --- |
| Debug pathname | `0x14C` | `0x108E2` | the path in the table above |
| Debug filename | `0x150` | `0x10955` | `sf33rd.exe` |
| Unicode filename | `0x154` | `0x108CC` | UTF-16LE `sf33rd.exe` |

The image contains the ASCII string `sf33rd.exe` once and `sf33rd.xbe` zero times. `make check` requires the debug pathname to end in `sf33rd.exe`.

The non-kernel import directory is zero. `D3D`, `DSOUND`, `XACTENG`, `XONLINE`, `WMADEC`, and the other XDK libraries are linked into their own sections. The symbols an OOVPA scan found are in [XDK](xdk.md).

`Game.c` is the assert path `\ac_work\bloom_projects\StreetFighterAnniversaryCollection_20040826v00\sf33rd\Source\Game\Game.c`. One `push imm32` in `.text` references it. `make check` requires that.

Vertex programs are `media/Shaders/*.xvu` beside the XBE: 490 files, magic `0x2078`, each a count plus 16-byte NV2A slots. `tools/ogxb/xvs.py` decodes those slots. `DOF1.xpu` and `DOF2.xpu` are `PSB0` register-combiner programs, 244 bytes each. `tools/ogxb/xpu.py` decodes them. `media/Shaders/CVS` is CVS metadata, not shader source. `tools/ogxb/spirv.py` turns one decoded program into SPIR-V 1.0. `make check` runs `spirv-val` on the local `.xvu` and `.xpu` files when that tool is installed. The modules are not stored in the repository.
