# XDK symbols

Retail `sf33rd.xbe` links XDK 5849 static libraries. The game's own code is `.text`. D3D, DSOUND, XACTENG, and the other libraries keep their own sections. `config/sf33rd/symbols/xdk.txt` names the symbols an OOVPA scan found in this image. Those names are not game functions and they do not go in `funcs.txt`.

The scan is [XbSymbolDatabase](https://github.com/Cxbx-Reloaded/XbSymbolDatabase) (`XbSymbolDatabaseCLI -e sf33rd.xbe`). That database is not part of this tree. It named 405 symbols. Four more XAPILIB bodies, between `QueryPerformanceCounter` and `CreateEventA`, are named from their bytes. The list has 409 symbols at image addresses, and 6 field offsets. Two device-type variables were printed twice by the scanner; the list keeps one of each. Two pairs share an address and both names stay:

| Address | Names |
| --- | --- |
| `0x191FA0` | `D3DRS_FogEnable`, `D3D_g_DeferredRenderState` |
| `0x192050` | `D3DRS_PSTextureModes`, `D3D_g_ComplexRenderState` |

`calls` counts direct `call` and `jmp` instructions in `.text` whose target is that address. The walk starts at each scanned function and stops at the first byte that does not decode, so a call after a jump table is not included. Indirect calls are not included. 165 of the addresses are reached that way, 375 times.

`prefix` is the first 8 bytes at the address when those bytes are in the file. `bss:1` means the address is inside a section and past that section's file bytes. The six `kind:offset` lines are struct fields, not virtual addresses. `__tls_array` is one of those, at offset 4. `_tls_index` at `0x7A4A88` is a real BSS dword, and `mainXapiStartup` reads it.

## Libraries

Every library record is build 5849. The flag word's low 13 bits are the QFE field. Bit 15 is the debug-build flag, and it is clear on every record here. Bits 13–14 are an approval field; 2 is the usual retail encoding and 1 is the "possibly approved" encoding.

| Library | Flags | Low 13 bits | Bits 13–14 | Symbols |
| --- | --- | --- | --- | --- |
| XAPILIB | `0x4001` | 1 | 2 | 63, in `.text`, XPP, and `.data` |
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

Where those 409 symbols sit:

| Section | Symbols |
| --- | --- |
| DSOUND | 165 |
| D3D | 139 |
| `.text` | 40 |
| XPP | 20 |
| XACTENG | 16 |
| XONLINE | 13 |
| XNET | 10 |
| `.data` | 4 |
| XGRPH | 2 |

`XNetGetEthernetLinkStatus` at `0x16453D` is the one XONLINES symbol inside `.text`. The XACTENG section also contains the literal `XACT::CSoundCue::SubmitEvent` at `0x1C1E98`. That is library text, not a game function.

`.text` calls these library entry points directly. The busiest are `XapiSetLastNTError` (46), `SetLastError` (35), `GetLastError` (32), `QueryPerformanceCounter` (11), `SetThreadPriority` (10), `QueryPerformanceFrequency` (7), `XLaunchNewImageA` (6), `DirectSoundCreate` (5), and `XInputGetState` (3). `Direct3D_CreateDevice` at `0x181A20` is called once. Many `D3DDevice_SetRenderState_*` helpers are called once each. The full list is the symbol file.

## Startup

The XBE entry `0x125FF7` is `mainCRTStartup`. It grows a heap, stores a size at `0xCCAAF8`, and calls `CreateThread` at `0x124F9C` with start address `0x125F83` (`mainXapiStartup`) and the other arguments zero. A null thread handle goes to `XapiBootToDash` at `0x1265A7` with arguments `(1, 1, 0)`. Otherwise it calls `0x123A48` with that handle and returns.

`0x123A48` is not an OOVPA hit. It is the instruction after `XMountUtilityDrive`'s `ret 4`, with no `int3` between them, so the scanner keeps it in the span that starts at `0x123943`. The body pushes its one argument, calls the `NtClose` import at thunk `0x218E08` (ordinal 187), and returns 1, or passes a negative status to `XapiSetLastNTError` and returns 0.

`mainXapiStartup` calls `0x127885` (unnamed), `XapiInitProcess` (`0x12661D`), `_rtinit` (`0x1277F8`), and `_cinit` (`0x1277A0`). It then calls `0x1204A(0, 0, 0)` and `XapiBootToDash(1, 1, 0)`, and returns with `ret 4`. Nothing in `.text` calls `mainXapiStartup` directly. The entry passes that address to `CreateThread`.

`main` is `0x1204A`. It is not a scanned start. The span that contains it starts at `0x11C39`. The body calls `0x11E67` and returns 0 when that result is negative. Otherwise it clears `0x4616AC` and `0x43FE58` and loops at `0x12064`: when `0x43FE58` is nonzero it calls `0x11C0E` and stores 1 at `0x4616AC` only if that call returned 0, then it calls `0xC86E7` and jumps back.

## Device setup

`0x11E67` is the device setup `main` calls before the frame loop. It has no error string and no PS2 counterpart, so it stays unnamed. A zero from `0x184E30(0)` returns `0x80004005`. That callee is eight bytes, `mov eax, 1; ret 4`, and the only caller stores the 1 at `0x43ED08`.

The setup calls `D3D_SetPushBufferSize(0x30000, 0x2000)` through `0x11C42`. `0x11C42` pushes both arguments, calls `0x181A00`, and returns 0. It then zeroes the `0x44`-byte present parameters at `0x43FF48`.

`XGetVideoStandard` is stored at `0x43FF44`, the dword in front of that struct. `XGetAVPack` is stored at `0x43ED14`. `XGetVideoFlags` is stored at `0x43EE24`. Standards 1 and 2 store refresh `0x3C` at `0x43FF74`. Standard 3 does the same, and when video-flag bit `0x40` is clear it sets bit 1 of the byte at `0x43FF71` (present `Flags` bit `0x200`).

The mode list is two 16-byte records, `0x2EC774` then `0x2EC764`. Both are 640 by 480. The third dword is 1, then 0. The fourth dword is 0. `0x11BA8` takes height, that third dword, that fourth dword, and the video flags. Height `0x1E0` is accepted when the third dword is 0, or when it is nonzero and flag bit `0x8` is set. A nonzero fourth dword also requires flag bit `0x1`. Height `0x2D0` requires bit `0x2`. Height `0x438` requires bit `0x4`. Any other height is rejected. The accepted index is stored at `0x44D390`. If both records fail, that dword is reloaded.

The chosen third dword becomes present flag `0x40` when nonzero and `0x20` when zero. A nonzero fourth dword ors `0x10`. Video-flag bit `0x1` ors `0x10` again and copies the 16/9 float at `0x2193CC` to `0x43FF8C`. Otherwise the 4/3 float at `0x2193C8` is copied. Width of `0x280` or less sets bit 0 of the byte at `0x43FF71` (`Flags` bit `0x100`). The other stored fields are format 7, back-buffer count 2, swap effect 1, auto depth-stencil 1, depth format `0x2A`, and presentation interval 1. `0x43FF8C` is the dword after the `0x44`-byte struct.

`0x11C39` is `push ebp; mov ebp, esp; pop ebp; jmp Direct3D_CreateDevice`. The call passes adapter 0, device type 1, window 0, behavior `0x40`, the present struct, and the device out-pointer at `0x43FE5C`. A negative result returns `0x80004005`.

On success the setup calls `D3DDevice_GetDisplayMode` through `0x11E31`, which pushes one pointer and returns 0. It then calls `0x11E44(0x41, 1)`, clears `0x43EE28`, calls `D3DDevice_SetVerticalBlankCallback` with `0x11BF0`, calls `D3DDevice_SetSwapCallback` with `0x11BFB`, calls `0x11355`, and returns 0. `0x11BF0` increments `0x43EE28` and jumps to `0x176FF`. `0x11BFB` copies five dwords from its argument to `0x43E894`.

`0x11E44` is the stdcall render-state wrapper the game calls. It puts the state in `eax` and the value in `edi`, calls `0x11C54`, and returns 0. Fifty-two `.text` sites call it. `D3DDevice_SetRenderStateNotInline` at `0x181B30` has no caller. Its first compare is `cmp esi, 0x5C`, the same split `0x11C54` uses. A state below `0x5C` goes to `D3DDevice_SetRenderState_Simple` with the method dword at `state*4 + 0x219200`, and the value is stored in `D3D_g_RenderState` (`0x191E30`). States `0x5C` through `0x87` OR a mask from `state*4 + 0x218FE0` into the dword at `0x191C28` and store the value. States `0x88` through `0xA5` call the matching `D3DDevice_SetRenderState_*` helper, from `D3DDevice_SetRenderState_PSTextureModes` at `0x88` through `D3DDevice_SetRenderState_DoNotCullUncompressed` at `0xA5`. State `0x41` is below `0x5C`. The same numbering puts `D3DRS_DITHERENABLE` at 65, so the setup enables dither.

`0x1202F` sets back-buffer count to 1, calls `D3DDevice_Reset` through the tail `jmp` at `0x11E3F`, and jumps to itself when the result is nonzero. The callers are `0xC8F55` and `0xCBB2B`. `0x12083` tail-jumps to `D3DDevice_PersistDisplay`. The callers are `0xF4537` and `0xFBA0C`.

`QueryPerformanceFrequency` at `0x123331` writes `0x2BB5C755` and a zero high dword, then returns 1. `XGetAVPack` at `0x12338E` returns the dword at `HalBootSMCVideoMode` (thunk `0x218DD0`, ordinal 356) with no mask. `XGetVideoStandard` at `0x123396` calls the `ExQueryNonVolatileSetting` thunk at `0x1652A0` with setting `0x103` and returns byte 1 of that dword, or 0 when the status is negative. `XGetVideoFlags` at `0x123345` queries setting `0x8`, keeps `(value >> 16) & 0x5F`, and clears bits `0xE` unless `XGetAVPack` returned 1 and `XGetVideoStandard` returned something other than 3. `CreateEventA` begins at the next byte, `0x1233BF`.

## Sound

`.text` calls `DirectSoundCreate` five times and `XACTEngineCreate` once. Those callers stay unnamed.

The first pass of `0xC86E7` clears the dword at `0x7AABDC` and calls `0xC832C`. That body returns at `0xC85E8`. It calls `0x9B6DC`, later `0x9B793`, and later `0x11ED6C`.

`0x9B6DC` pushes `D:\XB_HostPC\` and calls `0x17715`. `0x17715` calls `DirectSoundCreate(0, 0x795C10, 0)`. A negative result prints `Cannot create DirectSound!` through `OutputDebugStringA` and jumps to itself. It then calls `0x19860A` with the device, 0, and 2. `0x19860A` is `xor eax, eax; ret 0xC`, the five bytes before `IDirectSound_Release`. A negative result would print `Cannot set cooperative levele!` and hang. The stub returns 0. The path is stored at `0x795C0C` and passed to `0x165A40`. `0x165AC0` and `0x165A30` follow, and `0x165AB0` receives the device pointer. The body tail-jumps to `DirectSoundUseFullHRTF`.

`0x9B6DC` then calls `ADXT_Init` and `ADXT_Create(2, 0xAE7000, 0x3D9E4)`. `0x12492F(0x6952C, -1, 0, 4)` calls `MmAllocateContiguousMemoryEx` at thunk `0x218E88` (ordinal 166). A null block prints `AIXP_Create Failed.` through `0x13EFE`. The block is passed to `0x1678C0(3, 2, block, 0x6952C)`, and that result is stored at `0xAE6FEC`. `AIXP_SetOutVolDolbyDigital`, `AIXP_SetLpSw`, and `AIXP_Pause` later take that handle. The body sets bit 2 of `0x7AABDC`.

`0x9B793` calls `0xF53C4` and continues whether that result is 0 or 1. `0xF53C4` clears 48 slots of `0x38` bytes at `0x797128`. It calls `XACTEngineCreate` with five dwords, `0xBC`, `0`, `0`, `0x5DC`, `0xFA`, and stores the engine at `0x797BA8`. A negative create returns 0. On success it calls `IXACTEngine_CreateSoundSource` through `0xF4E40` once per slot, with the second argument 1, then calls `0xF4FF2(0x7F)` and returns 1. After `0xF53C4`, `0x9B793` calls `0xF44B2`, then `0xB637F(0x6D, 0x14)`, `0xB637F(0x6E, 0x14)`, and `0xB637F(0x6F, 0x14)`. It calls `0xF4532(0, dword at 0x32FD28)` and `0xF44CA(0, 0, 0, 0)`, then sets bit 1 of `0x7AABDC`.

Inside XACTENG, `XACTEngineCreate` copies those five dwords to engine+`0x80` and calls `DirectSoundCreate(0, &engine+0x10, 0)`. That object is private to the engine. The initializer subtracts the third dword from the first and calls `IDirectSound_SetMixBinHeadroom(device, bin, 0)` for bins 0 through 31.

`0x11ED6C` calls `0x59FD2`. A zero return prints the string at `0x2B877C`, `ボイスエフェクトイメージファイルが読み込めませんでした。` (the voice effect image file could not be read), through `0x13EFE` and jumps to itself. Otherwise it calls `DirectSoundCreate(0, 0x795C10, 0)` again, which overwrites the global, then `DirectSoundUseLightHRTF`, then `IDirectSound_DownloadEffectsImage` through `0xF4E37`. The image is the dword at `0x79B834` and the size is the value `0x59FD2` returned. The dwords at `0x79B828` and `0x79B830` are cleared and passed as the last two arguments. The first device pointer was already passed to `0x165AB0`, which forwards it to `0x16B080`.

`0xF4E37` is `push ebp; mov ebp, esp; pop ebp; jmp IDirectSound_DownloadEffectsImage`. The following bytes are bare jumps, with no `int3` between them, so the scanner keeps one span: `IXACTEngine_CreateSoundSource`, `CreateSoundBank`, `RegisterWaveBank`, `UnRegisterWaveBank`, then `0x1B7EFE`, `RegisterNotification`, `GetNotification`, `0x1B807F`, `0x1B8084`, and `0x1B8089`. `0x1B7EFE` is outside the OOVPA set. It returns `0xC` and forwards to `0x1B8CE1`. The three jumps land on `0x1BAF1E`, `0x1BAF64`, and `0x1BAE13`.

`0x150FE` calls `0x17706` while the dword at `0x4616AC` is zero. `main` clears that dword and stores 1 there only when `0x43FE58` is nonzero and `0x11C0E` returns 0. `0x17706` calls `0x165470` and jumps to `0xF55AE`. When `0x797BA8` is nonzero, `0xF55AE` calls `0xF54B0` and then jumps to `XACTEngineDoWork`.

The other three `DirectSoundCreate` calls are the methods at `0x12B760`, `0x12C00C`, and `0x12C538`. Each stores the object on its `this` pointer, and their callers stay inside `0x12B000`..`0x130000`. `DirectSoundDoWork` is reached only from that range. `0x12E9CE` calls `DirectSoundCreateStream` with flags `0x40000000` and a PCM format: tag 1, one channel, 8000 Hz, 16000 bytes per second, block align 2, and 16 bits.

The matched `mwSnd*` bodies call `IDirectSoundBuffer` on the CRI side. `0x16C4F0` still pushes `E2003100700:DirectSound Object is NULL. Probably ADX??_SetupSound was not called properly.` and stays unnamed.

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
