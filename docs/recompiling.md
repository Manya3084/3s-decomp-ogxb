# Recompiling

The tree aims to hold enough C to rebuild the game for another platform. This page says what that C covers, what a port has to supply itself, and how far the non-matching C can be trusted.

## What has C

- Game code. Every function of the game proper (`src/sf33rd/Source/Game`, `Common`, `AcrSDK`, and the Xbox-only files in `src/sf33rd/Source/XBOX`) has C, apart from two unreferenced functions behind an unused two-entry jump table at `0x25C3B8` (dead code between `effect_A9_init` and `Setup_EffD8_Pos`).
- The Xbox save system: the save menu (`SaveInit`, `SaveMove` and the `xb_SaveMenu*` states and steps, with their tables in C), the file side (`xb_SaveState*`: headers, reads and writes with their `XCalculateSignature` checks, the room checks on `U:`), and the three kinds' descriptors (system data, directions, replays).
- The Xbox platform layer: graphics (`flSetRenderState`, the render-state and blend mapping, texture and palette handles, `flLockTexture`/`flUnlockTexture`, the quad renderers, frame end and present), input (`xb_PADRead`, the stick and button conversion), the debug print layer, the XACT sound banks and voices, and start-up (`njUserInit`, `xb_InitGraphics`, `xb_InitVideoMemory`).
- CRI ADX and AIX (`src/cri`): the ADX decoders and header parsers (ADX, AHX, WAV, AU, AIFF, SPSD), streaming, AIX demux and playback, the `wx_ci` file layer and the `wxfic` directory cache, and the DirectSound voice writer (`mw_snd`).

A scan of the game's part of `.text` against every named range (sizes from `funcs.txt`, starts from `folded.json` and `xdk.txt`) finds no other unclaimed code: what remains between named functions is data (jump and switch-index tables), STL template instances, and the XDK sample code below.

## Data

Most of the game's initialized data is in C: the tables of the generated and hand-ported files, and the PS2 data files (`Com_Data.c`, `cmd_data.c`, the US message text and the rest), each compared with the XBE by `analysis-ps2map/portdata.py` and given the Xbox values where they differ (see [decompiling.md](decompiling.md#the-ps2-data-files)). The CRI tables (the SJ vtables and UUIDs, the build strings) are in C too.

What the C declares and does not define comes from the XBE: the character tables the PS2 build also takes from the game binary (`_etc_char_table`, `_sel_pl_char_table`, the `_asstbl_*` tables and the others in the PS2 tree's `include/bin2obj/char_table.h`), the staff roll, a few Xbox-only tables, the Xbox Live strings, and the XDK's own data. They are not in the tree, as the binaries are not; a port reads them from its own `sf33rd.xbe` at the addresses `config/sf33rd/symbols/data.txt` gives (or the `D_ADDR` in the name). `tools/xbe_tables.py` writes them to `build/xbe_tables.c` as byte arrays (about 390 tables, 39 KB) and lists the ones holding words that look like image addresses: those are pointers only where the image is mapped at its own addresses, and a port that does not map it has to fix them (the staff roll's strings, the Live string pairs). A `D_ADDR` name without a `data.txt` size gets four bytes. Zero-initialized globals need only storage.

## What a port supplies

- The XDK libraries: D3D, DSOUND, XACT, XAPI, XGRAPHICS, the C runtime. Their names and addresses are in `config/sf33rd/symbols/xdk.txt` (see [xdk.md](xdk.md)); none of their code is in the tree. The game calls D3D through `D3DDevice__*` header wrappers and the `xb_` wrappers in `xb_012146.c`; a port maps those to its own renderer.
- The copies of XDK sample code (`CXB*`, `XBUtil_*`, `XBInput_*`, `CXHV*`, `_xbOnlineTask`), which have no C (see [decompiling.md](decompiling.md)). The game uses `XBInput_CreateGamepads`/`XBInput_GetInput` for pads and `CXBFont` for the sample font.
- The Xbox Live code (`src/sf33rd/Source/XBOX/xlive`, `NetSync`, the online objects): about 250 named functions and 76 KB of unnamed code have no C. The parts offline play runs do have C:
  - at start-up, `xb_LiveWork_Init` (with `xb_SetupLiveLanguage` and `xb_XLIVE_WORK_CLASS_ResetState`) and `xb_InitOnlineBuffers`, which sets up the Live text layer (`xlive_font.c`);
  - every frame, the debug print layer, which draws its glyphs through `xb_xlive_font_DrawQueue`;
  - before each match, `Game01`'s settings exchange (`xb_NetSync_Step`, `xb_NetSync_CheckPlayers` and the message queue), which writes `save_w[2]` and `permission_player` even offline.

  The rest is reached only with the online flag set, or once the player opens the Xbox Live menu (`xb_Menu_XboxLive`, which sets the Live work's `+0x2330`, `+0x235C` or start-menu `+0x6D` state that `xb_RunFrame`'s `xb_OnlineUpdate`, `xb_OnlineMenuDraw` and `xb_LiveWork_Update24C0`/`Poll24C0` test). `xb_NetSync_ParsePacket` only sees messages from a peer. A port can stub all of that. The global Live work object's constructor and destructor (`xb_XLIVE_WORKBASE_CLASS_ctor`/`dtor`) are C++ with exception frames and have no C; a port builds that object its own way.

## How far the C can be trusted

10274 placed functions build to retail's bytes. About 410 more have C that does not. For those, `tools/behave.py` runs the C and the retail body side by side on random inputs (see [relink.md](relink.md#checking-differing-code-by-running-it)). Its known differences:

- Register-argument calls. Retail's D3D library and some CRI and Xbox functions take arguments in registers. The C passes them on the stack, which changes the bytes but not what is computed.
- Uninitialized results that retail returns on unsupported input (`xb_GetImagePixel` with an unknown pixel size). The C also returns an unset value; the two differ.
- Floating point. Retail's CRI code keeps intermediates on the x87 stack; a port compiled with SSE rounds them to float or double. `ADX_GetCoefficient` is written in double for that reason. Retail's Xbox colour conversion rounds with `cvtss2si`, which `xb_SaturateColor` reproduces.
- Out-of-range input. With random arguments, some functions read tables out of bounds; one side may crash where the other does not.
