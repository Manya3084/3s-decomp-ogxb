# XDK symbols

Retail `sf33rd.xbe` links XDK 5849 static libraries. The game's own code is `.text`. D3D, DSOUND, XACTENG, and the other libraries keep their own sections. `config/sf33rd/symbols/xdk.txt` names the symbols an OOVPA scan found in this image. Those names are not game functions and they do not go in `funcs.txt`.

The scan is [XbSymbolDatabase](https://github.com/Cxbx-Reloaded/XbSymbolDatabase) (`XbSymbolDatabaseCLI -e sf33rd.xbe`). That database is not part of this tree. It named 405 symbols. Six more XAPILIB bodies are named from their bytes: `QueryPerformanceFrequency`, `XGetVideoFlags`, `XGetAVPack`, and `XGetVideoStandard` between `QueryPerformanceCounter` and `CreateEventA`, and `XCalculateSignatureUpdate` and `XCalculateSignatureEnd` between `XCalculateSignatureBegin` and `GetTimeZoneInformation`. That first list had 411 symbols at image addresses, and 6 field offsets. Two device-type variables were printed twice by the scanner; the list keeps one of each. Two pairs share an address and both names stay:

| Address | Names |
| --- | --- |
| `0x191FA0` | `D3DRS_FogEnable`, `D3D_g_DeferredRenderState` |
| `0x192050` | `D3DRS_PSTextureModes`, `D3D_g_ComplexRenderState` |

`calls` counts direct `call` and `jmp` instructions in `.text` whose target is that address. The walk starts at each scanned function and stops at the first byte that does not decode, so a call after a jump table is not included. Indirect calls are not included. 167 of the addresses are reached that way, 386 times.

`prefix` is the first 8 bytes at the address when those bytes are in the file. `bss:1` means the address is inside a section and past that section's file bytes. The six `kind:offset` lines are struct fields, not virtual addresses. `__tls_array` is one of those, at offset 4. `_tls_index` at `0x7A4A88` is a real BSS dword, and `mainXapiStartup` reads it.

## Matching the XDK libraries

The list now has 3895 symbols at image addresses. Most of them were found by matching the XDK 5849 static libraries (the version this build links) against the image. Each function in a library object is cut out at its symbols. The bytes its relocations patch are masked, and the rest must agree at exactly one place in a code section. That alone is not enough, because two functions can differ only in a masked byte: `ReadFile` and `ReadFileScatter` differ only in the kernel call. So every match is checked against its relocations. A kernel import must hit the thunk slot of that kernel function, and a `call` or `jmp` must land where its callee was resolved. A call that lands on a callee is enough to name that callee, even when its own body is too short to match. A body that several functions share stays unnamed, and so does any match inside game code. The exceptions are the C++ `D3DDevice::` header wrappers (`D3DDevice__SetTexture` and so on, which call the C `D3DDevice_SetTexture`) and D3DX's private zlib deflate code.

The matches confirmed the earlier names, apart from naming style (XbSymbolDatabase writes `CDirectSoundStream_SetVolume`, the objects say `?SetVolume@CDirectSoundStream@DirectSound@@`). They also corrected six names read from bodies: `wsprintfW` and `wvsprintfW` (the game's format strings are UTF-16), `lstrcatW`, `_stricmp` (which falls through to `__ascii_stricmp` while the locale is unchanged), and `atol`. A 10-byte match of `iswupper` at `operator new` was a coincidence: both push 1 and call one helper, and the helper is `_nh_malloc`. Short matches therefore need a confirmed call or import. In game code, D3DX's `jzero_far` loop matched `work_init_zero`, which is why matches there are not used.

XbSymbolDatabase had given the plain Winsock names (`socket`, `bind`, `recv`, ...) to the `CXnSock` methods. The library objects name those methods `?socket@CXnSock@@`, so they are `CXnSock_socket` and so on. The public functions are the thunks that load the socket singleton (`0x7A50A0`) and jump to a method. Their order follows the Winsock ordinals, with the unused thunks left out by the linker. With the argument counts, that names the six thunks too short to match: `listen`, `accept`, `recv`, `recvfrom`, `send`, and `sendto`. The matcher named the others and agrees with that order.

Three XOnline thunks are named from how AcrSDK's `_xbOnlineTask.cpp` uses them. `0x12AB0` closes a task handle through `0x1D516B` and clears it, so that is `XOnlineTaskClose`. `0x12AC4` drives a task through `0x1D5160` each frame, so that is `XOnlineTaskContinue`. `0x1D5176` takes two arguments and enumerates the accounts on memory units, so it is `XOnlineGetUsers`. The order, both task calls, then `XOnlineGetUsers`, then `XOnlineLogon` (already named), is the XDK's API order. `0x1C2289` and `0x1C2294` tail-jump to `CXn_XNetRegisterKey` and `CXn_XNetUnregisterKey`, and `0x1D51FB` to `CXo_XOnlineMatchSessionGetInfo`, so they are `XNetRegisterKey`, `XNetUnregisterKey`, and `XOnlineMatchSessionGetInfo`.

`std::vector` instances in the online code were matched by compiling explicit instantiations (`template class std::vector<E>;`) of plain structs of each element size, with the same flags plus `/EHsc` (the game's online code uses C++ exceptions). A body that depends on the element size matches one size, and its name gives the method: `std__vector_Elem14__size`, `std__vector_Elem88__capacity`, `std___Copy_opt_Elem18`. `Elem14` means an element of 0x14 bytes whose type is not known. A body that does not depend on the size, such as some `_Buy` and `_Construct_n` instances, matches every size and stays unnamed.

The game's zlib inflate code is byte-identical to D3DX's private copy. Its names stay in `funcs.txt`, because the PS2 map has the same functions. The custom-soundtrack path is CRI's. Names that start with `s` go to `XOpenSoundtrackSong`. The soundtrack enumeration functions (`XFindFirstSoundtrack`, `XGetSoundtrackSongInfo`) are not linked, so the game does not list soundtracks itself.

## Using your own XDK

Nothing from the XDK is in this tree: no libraries, headers, PDBs, sample sources, or tools. `xdk.txt` holds only names and image addresses. To check them or extend them you need your own XDK 5849 install, the version the XBE's library records name (see Libraries below).

- The build only needs its compiler. Point `XDK` at the install root, or write that path to an untracked `xdk.path` (see `docs/relink.md`).
- The libraries are in `<XDK>/xbox/lib`. The `*ltcg.lib` files hold compiler intermediate code, not machine code, so match against the plain `.lib` files. `<XDK>/lib` holds PC libraries and does not apply.
- A name and its argument size can be read from a library's symbol table, for example `strings <XDK>/xbox/lib/xgraphics.lib | grep XGMatrixPerspectiveFovLH`. That prints `_XGMatrixPerspectiveFovLH@20`, a stdcall with 0x14 bytes of arguments.
- To repeat the matching above, cut each library function out at its COFF symbols, mask the bytes its relocations patch, and look for the rest in the image's code sections (`tools/ogxb/coff.py` reads the objects). Then check the relocations as described.
- `XGMatrixPerspectiveFovLH` at `0x12A6D7` was named from its body. It takes 0x14 bytes of arguments and computes `fsincos` of half the field of view. The xgraphics symbol table has that name with that argument size.

## Libraries

Every library record is build 5849. The flag word's low 13 bits are the QFE field. Bit 15 is the debug-build flag, and it is clear on every record here. Bits 13–14 are an approval field; 2 is the usual retail encoding and 1 is the "possibly approved" encoding.

| Library | Flags | Low 13 bits | Bits 13–14 | Symbols |
| --- | --- | --- | --- | --- |
| XAPILIB | `0x4001` | 1 | 2 | 65, in `.text`, XPP, and `.data` |
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

Where those 411 symbols sit:

| Section | Symbols |
| --- | --- |
| DSOUND | 165 |
| D3D | 139 |
| `.text` | 42 |
| XPP | 20 |
| XACTENG | 16 |
| XONLINE | 13 |
| XNET | 10 |
| `.data` | 4 |
| XGRPH | 2 |

`XNetGetEthernetLinkStatus` at `0x16453D` is the one XONLINES symbol inside `.text`. The XACTENG section also contains the literal `XACT::CSoundCue::SubmitEvent` at `0x1C1E98`. That is library text, not a game function.

`.text` calls these library entry points directly. The busiest are `XapiSetLastNTError` (46), `SetLastError` (35), `GetLastError` (32), `QueryPerformanceCounter` (11), `SetThreadPriority` (10), `QueryPerformanceFrequency` (7), `XLaunchNewImageA` (6), `XCalculateSignatureUpdate` (6), `DirectSoundCreate` (5), `XCalculateSignatureEnd` (5), and `XInputGetState` (3). `Direct3D_CreateDevice` at `0x181A20` is called once. Many `D3DDevice_SetRenderState_*` helpers are called once each. The full list is the symbol file.

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

## Controllers

`.text` calls `XGetDevices` once, `XInputOpen` twice, `XInputGetCapabilities` twice, `XInputGetState` three times, `XInputClose` once, and `XInputSetState` once. `XGetDeviceChanges` is called twice. The game bodies stay unnamed.

`0x11357` calls `0x17592`. That body calls `0x211EF7` with the dword at `0x795C04` and 0. `0x211EF7` is `jmp XInitDevices`, so the symbol's own call count stays 0. `0x17592` then calls `0x1312C(0x795C00)`. A negative result returns 0. On success it copies the four handles at `0x43EA04`, stride `0xE0`, into `0x7957B4`, stride `0x34`, calls `0x171DB`, and returns 1.

`0x1312C` calls `XGetDevices(g_DeviceType_Gamepad)` and walks four ports. Each port is `0xE0` bytes at `0x43E930`, and each state is `0x16` bytes at `0x43E8D8`. The body clears both. A set mask bit calls `XInputOpen(g_DeviceType_Gamepad, port, 0, 0x2EC810)`, stores the handle at offset `0xD4`, calls `XInputGetCapabilities` into offset `0xBA`, and calls `XInputGetState` into the state. The buttons word at state+4 is stored at offset `0x24`. The eight bytes at state+6 become dwords at offset `0x28`, each 1 when the byte is above `0x1E`. A nonzero argument receives `0x43E930`. The body returns 0. The eight bytes at `0x2EC810` are `03 08 08 00 00 00 00 00`.

`0x116E5` calls `0x175D7`, which calls `0x13314(0)`. `0x13314` calls `0x131F7` and then reads each open handle. `0x131F7` calls `XGetDeviceChanges` with `g_DeviceType_Gamepad` and two out-pointers. A removal bit closes the handle with `XInputClose`, clears it, and clears the words at offsets `0xB6` and `0xB8`. An insertion bit opens that port again and refills the capabilities, the buttons word, and the eight dwords.

The poll copies `0x12` bytes from state+4 onto the start of the port record: the buttons word, eight analog bytes, and four thumb shorts. Each short becomes a float at offsets `0x14`, `0x18`, `0x1C`, and `0x20`. The quotient is `(value + 0.5) / 32767.5`, from the floats at `0x2190F0` and `0x2194F8`. The sign is the float at `0x2190AC` (`1.0`) when the quotient is at least 0, and the float at `0x2190D4` (`-1.0`) otherwise. `0x132FA` receives the quotient. The stored value is 0 when `(result - 0.24) / 0.76` is negative or zero. Otherwise it is that quotient times the sign. Those two constants are the floats at `0x2194F4` and `0x2194F0`.

The previous buttons word stays at offset `0x24`. Newly pressed bits are stored at offset `0x48`. Each analog byte above `0x1E` stores 1 at offset `0x28`, and the dword `0x24` bytes later stores 1 when that level was 0. If any edge is set, one code is written at offset `0x6C`. The first match wins:

| Code | Source |
| --- | --- |
| 1 | newly pressed bit `0x10` |
| 2 | newly pressed bit `0x20` |
| 3 through 8 | analog bytes 0 through 5 just crossed `0x1E` |
| 9 | newly pressed bit `0x1` |
| `0xA` | newly pressed bit `0x2` |
| `0xB` | newly pressed bit `0x4` |
| `0xC` | newly pressed bit `0x8` |
| `0xD` and `0xE` | analog bytes 6 and 7 just crossed `0x1E` |

Those bits, and the analog order, are the XInput gamepad fields.

`0x175D7` copies each `0xE0`-byte record to `0x795880`, stride `0xE0`. When `0x17273` returns nonzero, the low nibble of the port dword is mixed through the byte table at `0x21CC70`, and the two stick pairs go through `0x17469` and `0x17566`. `0x17469` passes the two shorts to `0x175BB8`. A negative result is increased by the 2π float at `0x219094`. Dividing by that float and multiplying by the 360 float at `0x2190B4` produces the word at offset 6. The magnitude is clamped to `0x7F` at offset 4. A magnitude below the second argument clears the record. `0x17566` returns 0 when that word is below `0x10`, and otherwise reads a byte from `0x21CBD8`. The two bytes are packed into the high half of the port dword at `0x7957B8`, stride `0x34`.

The rumble loop skips a port whose handle is 0 or whose dword at offset `0x74` is `0x3E5`. It copies words from `0x795788` and `0x795790` to offsets `0xB6` and `0xB8`, then calls `XInputSetState(handle, record+0x74)`. `XInputSetState` writes 0 at feedback+`0x40` and a byte at feedback+`0x41`, then calls `0x214C5F`. When bit `0x20` is set in the byte at offset `0x28` of the object reached through handle+`0xA3`, it returns `0x57`.

`0x11BF0` jumps to `0x176FF`, which increments `0x795C08`.

`0x1370F` forwards two pointers to `XGetDeviceChanges` with `g_DeviceType_MU`. The caller is `0x112316`. `XReadMUMetaData` and `MU_Init` have no direct caller. `XGetDeviceEnumerationStatus` is called from `0x12A2A`. That body returns at `0x12A7F`, and the `m_hOnlineTask == NULL` assert follows it in the same scanned span.

## Save games

`XCalculateSignatureUpdate` and `XCalculateSignatureEnd` were named from their bytes. Begin passes the flag and the pointer at `[0x10118]+8` to `0x1252E2`.

Update and End read the flag stored in the context. Flags 0, 1, 2, and 4 update through `0x1251E5`, which jumps through `0x1652A6` to `XcSHAUpdate` and returns 0. Flags 0 and 1 end through `0x1251FF`. Flags 2 and 4 end through `0x125297`, which jumps through `0x1652B2` to `XcSHAFinal`. Flag 8 calls `0x7A4914` from Update and `0x7A4918` from End. Begin's flag 8 calls `0x7A4910`. Any other flag makes Update and End return `0x32`, and Begin calls `SetLastError(0x32)` and returns -1. The XONLINE section references `0x7A4914` and `0x7A4918`.

Flags 2 and 4 share `0x125261`. It stores 2 in the new context and jumps through `0x1652AC` to `XcSHAInit`. Flags 0 and 1 allocate `0x7C` bytes through `0xF4553(0x7C, 0x24830000)`. A null pointer sets last error 8 and returns -1. `0x125165` stores the flag. Begin passes the pointer at `[0x10118]+8`, and that match stores `XboxSignatureKey` in the context. A different pointer searches sixteen dwords at the object+`0x5C` and stores `XboxAlternateSignatureKeys` plus the matching index times 16. A miss sets last error 5 and returns -1. `0x125017` then clamps the 16-byte key to `0x40` bytes, XORs sixteen dwords with `0x36363636`, and calls `XcSHAInit` and `XcSHAUpdate`. `0x12507E` XORs its copy with `0x5C5C5C5C`, finishes the inner hash, and calls `XcSHAInit`, `XcSHAUpdate` of `0x54` bytes, and `XcSHAFinal`. When the context's low bit is set, End runs `0x1250F0` over the 20-byte result with `XboxHDKey`. If those 16 bytes are all zero, `0x1250F0` calls `0x1274BA` first. End releases the context through `0xF4593` with tag `0x24830000`.

`0x1252C1` returns `0x14` for flags 0, 1, 2, and 4, and `0x64` for flag 8. Nothing in `.text` calls it.

The save cluster starts at `0x12058B`. `0x5B3FB` calls it. Four sequences call Begin, Update, and End. The reads and the writes call Begin with 0. The context's low bit stays clear.

A read opens the path through `0x12400E(path, 0x80000000, 0, 0, 3, 0x80, 0)`. That body returns `0x1C` and calls `NtCreateFile`. Handle `0xFFFFFFFF` stores `0xFFFFFF03`. `0x123FD3` returns the length. On the first read the file size and the size minus `0x14` are compared with a dword shifted left by 14, and a payload of 0 fails. `0x123A8C` reads the first `0x14` bytes and then the payload into a block from `0x12492F`. `0x123A8C` returns `0x14` and calls `NtReadFile` and `NtWaitForSingleObject`. The handle is closed through `0x123A48`. Update hashes the payload and End writes 20 bytes. The first read compares those 20 bytes as five dwords with the bytes from the file. A match clears the status dword. The second read's failure path stores `0xFFFFFF00`. Both paths release the block through `0x12499F`, which jumps to `MmFreeContiguousMemory`.

One read calls `0x1259A8` and `0x1254D5` and stores the year, month, day, and time bytes. `0x1254D5` calls `RtlTimeToTimeFields` at thunk `0x218EF4`. When the name pointer is set, that read calls `0x125D20` with `0x104` and appends `\` and the name. `0x125D20` contains `\SaveMeta.xbx` and calls `NtCreateFile`. `mainXapiStartup` is later in that scanned span.

A write calls `0x123604` first. That body returns `0x10` and calls `NtOpenFile` and `NtQueryVolumeInformationFile`. A failed compare stores `0xFFFFFF04`. The create is `0x12400E(path, 0x40000000, 0, 0, 2, ...)`. Begin, Update, and End run with flag 0. `0x123B79` writes the 20-byte result and then the payload. It returns `0x14` and calls `NtWriteFile` and `NtWaitForSingleObject`. The handle is closed through `0x123A48`. The same body loads the literal `saveimage.xbx`.

Three records at `0x436E58`, `0x436E90`, and `0x436EC8` name `S.F.III 3rd System`, `S.F.III 3rd Direction`, and `S.F.III 3rd Replay`. They point at `d:\XB_HostPC\saveimage_sf33rd0.xbx`, `saveimage_sf33rd1.xbx`, and `saveimage_sf33rd2.xbx`, and at the directory name `SaveGame`. The dword at offset `0x18` is `0x218`, `0x58`, and `0x7458`. The replay record also points at `sub.bin`. `0x120A13` calls through the five code pointers at `0x436F0C`. The pointer at `0x436F54` addresses `There aren't enough free blocks to save game data.` The pointer at `0x436F68` addresses `If you do not save game data, it will be lost.`

`0x12185A` calls `XLaunchNewImageA(0, buffer)`. The buffer is `0xC00` bytes. Its first dword is 2, the dword at offset 8 is `0x55`, and the dword at offset `0xC` comes from the argument at `+0x48`. The address of `0x12185A` is stored at `0x437FC8`, `0x437FFC`, and `0x438030`.

`0x164E85` calls Begin with 8, Update on the payload, Update on `0xC` bytes at `0xCCEFE0`, and End at `0xCCEFEC`. It then writes `0x70` bytes from `0xCCEFE0`. `0x165223`, `0x165230`, and `0x16523B` call it. `0xC` plus the `0x64` that `0x1252C1` returns for flag 8 is `0x70`.

`\Device\Harddisk0\partition1\UDATA` is referenced from `0x438260`. The `TDATA` literal is referenced from `0x438250` and `0x43B024`. The format `\Device\Harddisk0\Partition1\TDATA\%08x\$u\%s` is pushed at `0x127126`.

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
