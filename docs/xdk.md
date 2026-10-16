# XDK symbols

Retail `sf33rd.xbe` links XDK 5849 static libraries. The game's own code is `.text`. D3D, DSOUND, XACTENG, and the other libraries keep their own sections. `config/sf33rd/symbols/xdk.txt` names the symbols an OOVPA scan found in this image. Those names are not game functions and they do not go in `funcs.txt`.

The scan is [XbSymbolDatabase](https://github.com/Cxbx-Reloaded/XbSymbolDatabase) (`XbSymbolDatabaseCLI -e sf33rd.xbe`). That database is not part of this tree. The checked-in list is the result: 405 symbols at image addresses, and 6 field offsets. Two device-type variables were printed twice by the scanner; the list keeps one of each. Two pairs share an address and both names stay:

| Address | Names |
| --- | --- |
| `0x191FA0` | `D3DRS_FogEnable`, `D3D_g_DeferredRenderState` |
| `0x192050` | `D3DRS_PSTextureModes`, `D3D_g_ComplexRenderState` |

`calls` counts direct `call` and `jmp` instructions in `.text` whose target is that address. The walk starts at each scanned function and stops at the first byte that does not decode, so a call after a jump table is not included. Indirect calls are not included. 161 of the addresses are reached that way, 362 times.

`prefix` is the first 8 bytes at the address when those bytes are in the file. `bss:1` means the address is inside a section and past that section's file bytes. The six `kind:offset` lines are struct fields, not virtual addresses. `__tls_array` is one of those, at offset 4. `_tls_index` at `0x7A4A88` is a real BSS dword, and `mainXapiStartup` reads it.

## Libraries

Every library record is build 5849. The flag word's low 13 bits are the QFE field. Bit 15 is the debug-build flag, and it is clear on every record here. Bits 13–14 are an approval field; 2 is the usual retail encoding and 1 is the "possibly approved" encoding.

| Library | Flags | Low 13 bits | Bits 13–14 | Symbols |
| --- | --- | --- | --- | --- |
| XAPILIB | `0x4001` | 1 | 2 | 59, in `.text`, XPP, and `.data` |
| D3D8 | `0x4001` | 1 | 2 | 139, in the D3D section |
| D3DX8 | `0x4001` | 1 | 2 | none |
| XGRAPHC | `0x4001` | 1 | 2 | 2, in XGRPH |
| DSOUND | `0x4001` | 1 | 2 | 165, in DSOUND |
| XACTENG | `0x4006` | 6 | 2 | 16, in XACTENG |
| XVOICE | `0x4004` | 4 | 2 | none |
| VOICMAIL | `0x4804` | `0x804` | 2 | none |
| XONLINES | `0x2007` | 7 | 1 | 24, in XONLINE, XNET, and one in `.text` |
| XBOXKRNL | `0x4001` | 1 | 2 | the 150 kernel imports, not this list |
| LIBCMT | `0x4001` | 1 | 2 | none |
| LIBCPMT | `0x4001` | 1 | 2 | none |

There is no `D3D8LTCG` record. The D3D8 signatures hit the separate D3D section, whose file bytes end at `0x191010`. The render-state variables from `0x191C30` up are past that and are marked `bss:1`.

D3DX, WMADEC, DOLBY, XVOICE, and VOICMAIL are in the image and this signature set did not name them. XBOXKRNL stays in the import table (`tools/data/xboxkrnl.txt`).

Where those 405 symbols sit:

| Section | Symbols |
| --- | --- |
| DSOUND | 165 |
| D3D | 139 |
| `.text` | 36 |
| XPP | 20 |
| XACTENG | 16 |
| XONLINE | 13 |
| XNET | 10 |
| `.data` | 4 |
| XGRPH | 2 |

`XNetGetEthernetLinkStatus` at `0x16453D` is the one XONLINES symbol inside `.text`. The XACTENG section also contains the literal `XACT::CSoundCue::SubmitEvent` at `0x1C1E98`. That is library text, not a game function.

`.text` calls these library entry points directly. The busiest are `XapiSetLastNTError` (46), `SetLastError` (35), `GetLastError` (32), `QueryPerformanceCounter` (11), `SetThreadPriority` (10), `XLaunchNewImageA` (6), `DirectSoundCreate` (5), and `XInputGetState` (3). `Direct3D_CreateDevice` at `0x181A20` is called once. Many `D3DDevice_SetRenderState_*` helpers are called once each. The full list is the symbol file.

## Startup

The XBE entry `0x125FF7` is `mainCRTStartup`. It grows a heap, stores a size at `0xCCAAF8`, and calls `CreateThread` at `0x124F9C` with start address `0x125F83` (`mainXapiStartup`) and the other arguments zero. A null thread handle goes to `XapiBootToDash` at `0x1265A7` with arguments `(1, 1, 0)`. Otherwise it calls `0x123A48` with that handle and returns.

`0x123A48` is not an OOVPA hit. It is the instruction after `XMountUtilityDrive`'s `ret 4`, with no `int3` between them, so the scanner keeps it in the span that starts at `0x123943`. The body pushes its one argument, calls the `NtClose` import at thunk `0x218E08` (ordinal 187), and returns 1, or passes a negative status to `XapiSetLastNTError` and returns 0.

`mainXapiStartup` calls `0x127885` (unnamed), `XapiInitProcess` (`0x12661D`), `_rtinit` (`0x1277F8`), and `_cinit` (`0x1277A0`). It then calls `0x1204A(0, 0, 0)` and `XapiBootToDash(1, 1, 0)`, and returns with `ret 4`. Nothing in `.text` calls `mainXapiStartup` directly. The entry passes that address to `CreateThread`.

`main` is `0x1204A`. It is not a scanned start. The span that contains it starts at `0x11C39`. The body calls `0x11E67` and returns 0 when that result is negative. Otherwise it clears `0x4616AC` and `0x43FE58` and loops at `0x12064`: when `0x43FE58` is nonzero it calls `0x11C0E` and stores 1 at `0x4616AC` only if that call returned 0, then it calls `0xC86E7` and jumps back.

## Xbox-only source files

Assert paths in `.rdata` show which Xbox files were compiled into this image. A path does not name a function. One scanned start can contain several pushes, and several functions, when MSVC left no `int3` between them. `make xref` shows the push. The function still has to be matched from its own body before it goes in `funcs.txt`.

| File under `sf33rd\` | String | Sites | Scanned starts |
| --- | --- | --- | --- |
| `AcrSDK\xbox\base\_xbOnlineTask.cpp` | `0x219478` | 1 | 1 |
| `AcrSDK\xbox\base\_xbsocket.cpp` | `0x219538` | 5 | 4 |
| `AcrSDK\xbox\base\_xbutil.cpp` | `0x2196A0` | 1 | 1 |
| `Source\XBOX\xlive\VoiceChat.cpp` | `0x2B4580` | 5 | 4 |
| `Source\XBOX\xlive\VoiceChatMessage.cpp` | `0x2B4640` | 5 | 1 |
| `Source\XBOX\xlive\VoiceManager.cpp` | `0x2B46C8` | 1 | 1 |
| `Source\XBOX\xlive\Voicecommunicator.cpp` | `0x2B4860` | 1 | 1 |
| `Source\XBOX\xlive\XHVVoiceManager.cpp` | `0x2B4908` | 4 | 2 |
| `Source\XBOX\xlive\_xbSockAddr.cpp` | `0x2B49B8` | 1 | 1 |
| `Source\XBOX\xlive\xlive_connectuser.cpp` | `0x2B4A40` | 2 | 1 |
| `Source\XBOX\xlive\xlive_disp.cpp` | `0x2B4B48` | 11 | 7 |
| `Source\XBOX\xlive\xlive_font.cpp` | `0x2B4C78` | 2 | 2 |
| `Source\XBOX\xlive\xlive_friend.cpp` | `0x2B4D08` | 46 | 24 |
| `Source\XBOX\xlive\xlive_main.cpp` | `0x2B4F50` | 18 | 7 |
| `Source\XBOX\xlive\xlive_qos.cpp` | `0x2B81C8` | 2 | 2 |
| `Source\XBOX\xlive\xlive_startmenu.cpp` | `0x2B8350` | 1 | 1 |
| `Source\XBOX\srcnet\netm.c` | `0x2B87B8` | 1 | 1 |
| `Source\XBOX\srcnet\rebattle.c` | `0x2B8970` | 3 | 2 |

The start-menu C string begins at `0x2B834E` with a stray `@C`. The push uses `0x2B8350`, which is the path. `Source\Game\Game.c` at `0x25CCA8` is the one shared assert `make check` already requires.
