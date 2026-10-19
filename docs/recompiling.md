# Recompiling

The tree aims to hold enough C to rebuild the game for another platform. This page says what that C covers, what a port has to supply itself, and how far the non-matching C can be trusted.

## What has C

- Game code. Every function of the game proper (`src/sf33rd/Source/Game`, `Common`, `AcrSDK`, and the Xbox-only files in `src/sf33rd/Source/XBOX`) has C, apart from two unreferenced functions behind an unused two-entry jump table at `0x25C3B8` (dead code between `effect_A9_init` and `Setup_EffD8_Pos`).
- The Xbox platform layer: graphics (`flSetRenderState`, the render-state and blend mapping, texture and palette handles, `flLockTexture`/`flUnlockTexture`, the quad renderers, frame end and present), input (`xb_PADRead`, the stick and button conversion), the debug print layer, the XACT sound banks and voices, and start-up (`njUserInit`, `xb_InitGraphics`, `xb_InitVideoMemory`).
- CRI ADX and AIX (`src/cri`): the ADX decoders and header parsers (ADX, AHX, WAV, AU, AIFF, SPSD), streaming, AIX demux and playback, the `wx_ci` file layer and the `wxfic` directory cache, and the DirectSound voice writer (`mw_snd`).

A scan of the game's part of `.text` against every named range (sizes from `funcs.txt`, starts from `folded.json` and `xdk.txt`) finds no other unclaimed code: what remains between named functions is data (jump and switch-index tables), STL template instances, and the XDK sample code below.

## What a port supplies

- The XDK libraries: D3D, DSOUND, XACT, XAPI, XGRAPHICS, the C runtime. Their names and addresses are in `config/sf33rd/symbols/xdk.txt` (see [xdk.md](xdk.md)); none of their code is in the tree. The game calls D3D through `D3DDevice__*` header wrappers and the `xb_` wrappers in `xb_012146.c`; a port maps those to its own renderer.
- The copies of XDK sample code (`CXB*`, `XBUtil_*`, `XBInput_*`, `CXHV*`, `_xbOnlineTask`), which have no C (see [decompiling.md](decompiling.md)). The game uses `XBInput_CreateGamepads`/`XBInput_GetInput` for pads and `CXBFont` for the sample font.
- The Xbox Live code (`src/sf33rd/Source/XBOX/xlive`, `NetSync`, the online objects): about 280 named functions and 83 KB of unnamed code have no C. Offline play reaches it only through a few calls (`xb_LiveWork_*` at start-up and in `Game.c`), which a port can stub.

## How far the C can be trusted

10255 placed functions build to retail's bytes. About 400 more have C that does not. For those, `tools/behave.py` runs the C and the retail body side by side on random inputs (see [relink.md](relink.md#checking-differing-code-by-running-it)). Its known differences:

- Register-argument calls. Retail's D3D library and some CRI and Xbox functions take arguments in registers. The C passes them on the stack, which changes the bytes but not what is computed.
- Uninitialized results that retail returns on unsupported input (`xb_GetImagePixel` with an unknown pixel size). The C also returns an unset value; the two differ.
- Floating point. Retail's CRI code keeps intermediates on the x87 stack; a port compiled with SSE rounds them to float or double. `ADX_GetCoefficient` is written in double for that reason. Retail's Xbox colour conversion rounds with `cvtss2si`, which `xb_SaturateColor` reproduces.
- Out-of-range input. With random arguments, some functions read tables out of bounds; one side may crash where the other does not.
