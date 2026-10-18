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

A name that starts with `xb_` was made up for this project. Capcom's Xbox-only code (the D3D layer, the pad layer, the save, Xbox Live, and menu code) and CRI's internal static helpers have no PS2 body and no string that names them, so their real names are lost. Each `xb_` name says what the body does, or which field it touches when its purpose is not clear (`xb_LiveWork_Set2334`). The module goes after the prefix when it is known (`xb_mwsnd_CreateBuffer`, `xb_rebattle_Select`). Every name without the prefix is a real one.

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

A final pass realigns every caller with all names in place. An accepted callee is kept when it lines up with its name at least as often as it fails to: a hit is a caller where the address lines up with its name, a miss is one where it does not. With fewer than five hits, its x86 size must be 0.15 to 2.5 times the PS2 size. The selection also uses link order. The name's PS2 address should lie between the PS2 addresses of the nearest named Xbox functions on each side. A callee seen in two or more callers is accepted unless it has three hits or fewer and fails link order. A callee seen in one caller needs link order on both sides, or on one side together with the constant and offset check above. 316 names came from this, in three rounds. 89 proposals were held back, among them the `bg0101`-style background routines, whose PS2 bodies are byte-identical twins. Nineteen of those names were later taken back (`analysis-ps2map/unname_folds.py`). Each body's PS2 function has a byte-identical twin with no Xbox address of its own, and the twin's callers call that same body. So the body is an MSVC fold and stays unnamed, as other folds do. Examples are `disp_pos_trans_entry` with `disp_pos_trans_entry5`, `add_x_sub` with `add_x_sub2`, `BGM_Request` with `Sound_SE`, and `SJRBF_EntryErrFunc` with `ADXSTM_EntryEosFunc`. Hand ports call such a body as `sub_ADDR`.

Porting adds a second source. When a port lines up a caller with its PS2 C and exactly one call stays unnamed, the header says so ("X stays sub_ADDR, the one unnamed call left in its caller"). Those notes were collected across all ports and none conflicted. PS2 library calls (`sce*`, `njSetMatrix`, `waitVsyncDummy`) were skipped, because the Xbox calls other code there. A name was added after its size ratio was checked, and the outliers were checked by hand: `Pause_1st_Sub` (the PS2 map size covers the functions after it), `grade_check_work_round_init`, `appear_player`, and `Load_Replay_Sub`. 55 names came from this. Eleven more were read from call order by hand: the Manage.c helpers (`Quick_Entry`, `Pool_Score`, `Additional_Bonus`, `Check_Break_Into_CPU`, `Clear_1Stage_Work`), `SA_Range_Check`, `DENJIN_Check`, `YAGYOU_Check`, `Decide_PL`, `checkAdxFileLoaded`, and `pulpul_request_again`. Further `callround.sh` rounds added 23. A later pass verified the held `callround.sh` proposals body by body against their C, and read more callees off call position (`analysis-ps2map/callpos.py` prints a caller's C callees beside its x86 calls). That added 61 names and corrected `setup_dm_rl`, which had started 9 bytes into its body. `0x1725E0` is a bare `ret` that three CRI callers reach with different signatures, so it is a fold and `ADXF_Ocbi` is not named. `0xE737D` is a second compiled copy of `ToneDown`, used only by `After_Replay`. It is named `xb_ToneDownCopy`. The background routines that are byte-identical PS2 twins (`bg0202`, `bg020_sync_common`, `bg0301`, and the like) were named from their `BGnnn` callers, since each one has its own Xbox address. Only the ten first routines (`bg0201`, `bg0300`, ..., `bg1801`) share `0xB10A1`, and `bg050_sync_common` shares `0xB10E5` with `bg180_sync_common`. `unname_folds.py`'s join step had put all of them into one fold group, which was undone. `0x9A8D0` is a fold of `All_Clear_Random_ix` and `Setup_Net_Random_ix`. `extracalls.py` lists ported functions whose x86 makes more calls than their C, which is how the Xbox-only calls in `Purge_memory_of_list` and the button-image effects were found. `strictpair.py` pairs a caller's unnamed x86 calls with its C callees when both lists have the same length and every named position agrees. Its proposals were read against their C; in `K5_main_process` MSVC had put case 1 first, so `k5_add_sub` and `get_okuri_time` came out swapped and were corrected. The `end_*_move` routines follow their callers' call order, which is not their address order. `jalpair.py` does the same against the `jal` targets of the PS2 retail body, which names callees whose PS2 code is still asm (CRI's `ADXB_*`/`ADX_Decode*`, the sound driver's `mlSys*`). PS2-only layers it proposes (`PS2RNA_*`, `sce*`, `tarPAD*`, the memory card) are not taken, since the Xbox runs other code there. `unmatchedcalls.py` lists ported functions that call an unnamed target while every callee in their C is accounted for. `unname_folds.py` then took back `Break_Into_09` (the twin of `Break_Into_10`) and `get_comm_djmp_lever_dir` (the twin of `get_lever_dir`).

The `mlt_obj_*` names in MTRANS.c follow `Mtrans_use_trans_mode`'s mode compares: mode 17 calls `mlt_obj_trans` (0x63732), 18 `mlt_obj_trans_cp3` (0x63FA9), 20 `mlt_obj_trans_rgb`, 33 `mlt_obj_disp` (0x62BAC), and 36 `mlt_obj_disp_rgb` (0x62DB6). The relative sizes agree, and so does the `0x1FF` mask that only `mlt_obj_trans_cp3_ext` (0x63A4D) has. An earlier "swap" fix had paired them the wrong way.

## Names from the Xbox build alone

Some code has no PS2 body to match: CRI's Xbox layers and the XDK. These names come from the XBE itself.

- `ADXRNA_*` (0x170760 to 0x1708A0) are one-line wrappers in the PS2 `adx_rnap.c` order. That order names the five that were left: `ADXRNA_EntryErrFunc`, `ADXRNA_Destroy`, `ADXRNA_Stop` (the Xbox has no `ADXRNA_Start`), `ADXRNA_GetTime`, and `ADXRNA_GetNumRoom`. Each body a wrapper jumps to takes the wrapper's name with the `mwRna` prefix that `mwRnaCreate`, `mwRnaSetNumChan`, and `mwRnaCalcSfreq` carry in their own error strings (`mwRnaInit`, `mwRnaSetPlaySw`, `mwRnaGetTime`, and so on). The `mwRna` names are inferred this way and do not come from strings.
- In the CRI code shared with the PS2 (`adx_tsvr.c`, `adx_bsc.c`), the remaining calls line up one to one with the PS2 source: `ADXT_GetTranspose`, `ADXT_SetTranspose` (both empty on PS2), `ADXAMP_SetSfreq`, `ADXSJD_GetSpsdInfo`, `adxt_stat_decend`, the trap and EOS callbacks, `ADXB_EvokeExpandMono`, `ADXPD_Init`, and `ADXB_DecodeHeaderAc3`.
- `ADXB_GetLpEndPos` and `ADXSJD_GetLpEndPos` had been put one slot early. The getters read `+0x28`, `+0x2C`, `+0x30`, and `+0x34`, which is the PS2 order of start position, start offset (the getter with a null check, as in the PS2 map), end position, and end offset. `0x172D10` and `0x170230` are `GetLpStartPos`. The Xbox `ADXB_GetLpEndPos` body is `0x16D550`, which sits among the SJRBF code and is recorded as a fold.
- `AIXP_*` (CRI's AIX player) is Xbox-only. Its NULL-handle errors are numbered `E20030502nn`, and the numbers follow CRI's API order (09 `AIXP_GetStat`, 10 `AIXP_GetAdxt`, and 11 `AIXP_SetLpSw` were already named). The game names `AIXP_Create` itself: `0x1678C0` is the call before its "AIXP_Create Failed." log. `AIXP_Init` is called right after `ADXT_Init`. `AIXP_Destroy` (02), `AIXP_StartFname` (03), `AIXP_Stop` (08), and `AIXP_Finish` follow from their bodies. `0x167520` (04) sets per-speaker channels and then calls `AIXP_StartFname`. Its name is not known, so it stays unnamed.
- `wxCi*` and `mfCi*` are cvFs devices. Their function tables (`0x43C8F8` and `0x43C960`) have the PS2 `CVFSDevice` layout, so each slot names its function. The PS2 `dvci.c` has `dvci_call_errfn`, `dvci_alloc`, and `dvci_free`, and the Xbox modules have the matching `wxci_*` and `mfci_*` helpers.
- zlib's inflate code (the `zlib_Decompress` callees) is named in full: `inflateInit_` passes 15 (`MAX_WBITS`) to `inflateInit2_`, `inflateEnd` frees the blocks and then the state, the tree builders carry zlib's own error strings ("oversubscribed dynamic bit lengths tree" and so on), and `jalpair.py` matched the rest against the PS2 `jal` targets. `inflate_codes` ends at `inflate_codes_free`. The size scan stops at its switch table.
- The `xb_` names. Capcom's `_assert` calls give the source files of the Xbox Live code: `xlive_friend.cpp` (0x102D50 to 0x104DD8), `xlive_main.cpp` (0x105910 to 0x107FE2), `xlive_match.cpp`, `xlive_qos.cpp`, `xlive_signon.cpp`, `xlive_startmenu.cpp`, `xlive_stat.cpp` (0x1156DF to 0x11AAB8), `rebattle.c` (0x11F690), `VoiceChat.cpp`, and the AcrSDK `_xbOnlineTask.cpp` and `_xbsocket.cpp`. That is how Mode Select's Xbox-only entry was identified as the online mode. Two real names were found along the way: `njSetMatrix` (`0x30494`, the same body as the PS2 `DC_Ghost.c` one) and `CP3toPS2DrawOff` (`0xF4743`, beside the named `CP3toPS2DrawOn`). Left unnamed: `0x1669A0` (a bare `return 0`, most likely a fold), the XACT thunk at `0x1B7EFE`, and two targets read from data.
- Real names found while naming the Xbox-only layers. `BGM_Server`'s calls line up with its PS2 C, which names `bgm_seamless_clear`, `bgm_separate_check`, `bgm_volume_setup`, `bgm_play_request`, and `ADXT_StartSeamless`. Its two Xbox-only calls stop and resume the AIX opening theme (BGM 0x34). `Init_sound_system` and `sndInitialLoad` sit in `Sound3rd.c` order and do the PS2 work with Xbox paths and three banks. `dspwhUnpack` follows `dspwhPack`. `Setup_Directory_Record_Data` loads `D:\XB_HostPC\SF33RDXB.AFS` and polls `ADXF_GetPtStat` (a jump to `ADXF_GetPtStatEx`); its Xbox C is in the GD3rd.c override. `dispControllerWasRemovedMessage` is called where the PS2 `menu.c` calls it. The Xbox version takes the player, ignores its position arguments, and prints the port number with the debug font (the Pause.c override). `0x13EE0` loads the XDK sample font `d:\media\Fonts\Font.xpr` for that print layer.
- XDK sample code. AcrSDK's `_xbOnlineTask.cpp`, `_xbsocket.cpp`, and `_xbSockAddr.cpp`, the `XHVVoiceManager.cpp` and `VoiceChat.cpp` files, and parts of the Xbox Live code are copies of XDK 5849 sample code (`Samples/Xbox/Common/Src`, the Friends, voice-chat, and Integrated samples). The samples were compiled with the XDK's own `vc71` compiler under Wine using `/O1 /Oy- /arch:SSE /Op /Gy`, with `assert` left on as in Capcom's build, and the objects were matched with the same masked-byte check as the libraries. Bodies that match keep the sample's class and method names (`CXBStopWatch_GetTicks`, `CXBSocket_RecvFrom`, `CXBFont_Create`, `CXHVVoiceManager_SetRemoteTalkerPriority`). A few unmatched neighbours are named from the sample's order and bodies (`CXBSocket_Open`, `CXBOnlineTask_Continue`, `XBUtil_GetWide`). `std::vector` and allocator instances whose element type and method the objects name (`vector<XONLINE_USER>`, `vector<ACTIONS>`) go in `xdk.txt` as `std__vector_XONLINE_USER__size` and so on. Most of Capcom's copies were changed, so only 53 bodies match byte for byte.
- Library code goes in `xdk.txt`. Its 70 new entries were read from their bodies. An XAPI wrapper is named by the kernel imports it calls: `NtReadFile` plus a wait is `ReadFile`, and `FileNetworkOpenInformation`'s `EndOfFile` is `GetFileSizeEx`. Setting 7 and setting 0x104 are `XGetLanguage` and `XGetGameRegion`. The saved-game metadata strings and six arguments identify `XCreateSaveGame`, and the `TDATA\FFFE0000\Music` path identifies `XOpenSoundtrackSong`. Runtime functions are named by their code: "Assertion failed!" is `_assert`, `fsqrt`, `fsin`, and a cleared sign bit are `sqrt`, `sin`, and `fabs`, and the `0x343FD`/`0x269EC3` step is `rand`. Byte-identical twins that MSVC ships separately (`memcpy` and `memmove`, `_itoa` and `_ltoa`) cannot be told apart from one copy, so `0x176B70` and `0x17A3D0` stay unnamed.

## The Xbox Live classes

The game has no RTTI (only the library exception classes have type names), so the Live code's classes are rebuilt from how `this` is passed. `XLw`, the name the asserts use (`XLw->m_Players`), is the pointer at `0x798CAC`. It points at a global object at `0x79B838`. A static initializer at `0x18198F` constructs that object with `0x11DB86` and registers `0x11DBA2` as its destructor. The class derives from a base whose constructor is `0x109B12` (vtable `0x2B50F0`). Its own vtable is `0x2B8708`. A method belongs to a member object when it is called with `ecx = XLw + offset`, or with `ecx = this + k` from a method already placed. Members built by the same constructor are the same class. Only callees that read `ecx` before writing it count as methods.

Two class names are real: `WINSTR_CLASS` and `CONNECT_USER_CLASS` appear in assert strings. The others are made up in Capcom's `NAME_CLASS` style and carry the `xb_` prefix. So does every method name that the binary does not give:

| Member of `XLw` | Class | Evidence |
| --- | --- | --- |
| the object itself | `xb_XLIVE_WORK_CLASS` (base `xb_XLIVE_WORKBASE_CLASS`) | state at `+0x2364`/`+0x236C`/`+0x2370`, `CXBNetLink` at `+0xD8`, `CXBOnlineTask` members at `+0xF8` to `+0x118`, QoS at `+0x290`/`+0x2C8` (`XNetQosRelease`) |
| `+0x25D0` | `xb_XLIVE_FRIEND_CLASS` | 66 of its 71 methods are in `xlive_friend.cpp`. The `m_dwCurrFriend < m_FriendList.size()` asserts compare `this+0x8C4` with the vector at `this+0x860` (0x60-byte entries). `this+0x960` is the XUID sent to `XOnlineFriendsRequest`. `this+0xA8C` holds the two window handles that `no < WIN_MAX` checks. |
| `+0x24C0` | `xb_XLIVE_STARTMENU_CLASS` | start-menu state machine (`xlive_startmenu.cpp`, `xlive_stat.cpp`) |
| `+0x2544` | `xb_XLIVE_STATMENU_CLASS` | stat menu steps |
| `+0x5090`, `+0x5538` | `xb_XLIVE_STAT_CLASS` | one constructor (`0x109829`), both instances, methods in `xlive_stat.cpp` |
| `+0x59E0` | `CONNECT_USER_CLASS` (real name) | `0xF7EF0` holds the "CONNECT_USER_CLASS::state_ is illegal parameter!!" assert (`xlive_connectuser.cpp` line 96). The class polls the match search (`XOnlineMatchSearchGetResults`). Its constructor builds a `WINSTR_CLASS` first. |
| the global `0x798D00`, and `*0x3F8310`/`*0x3F8314` | `WINSTR_CLASS` (real name) | `0x106A84` holds the "WINSTR_CLASS::SetCenteringState" assert (`xlive_main.cpp` line 1649), so it is `WINSTR_CLASS_SetCenteringState`. The class's other methods (`xb_WINSTR_CLASS_SetString`, `_SetPos`, `_Update`, ...) are named from their bodies. |
| `+0x2408` | `xb_VOICECHAT_CLASS` | vtable `0x2B4560`, methods in `VoiceChat.cpp` |

`+0x24C0`, `+0x2544`, `+0x25D0`, and the stat objects share one small base (`xb_XLIVE_PAGE_CLASS`, vtable `0x2B8328`). Its first slot clears 0x14 dwords at `+4`. Methods named `Page_ADDR` or `Step_ADDR` are page and state handlers whose purpose is not known. `0x10371A` passes the user index, a null event, and the friends task handle to `0x1D52B7`, which is `XOnlineFriendsEnumerate`'s signature.

Matchmaking runs as modes of `xb_XLIVE_WORK_CLASS`. `xb_XLIVE_WORK_CLASS_ModeStep` (`0x108DB5`) switches on the mode at `+0x2368`. Modes 2 and 3 are state machines on `+0x236C`, each with an update table and a draw table, and sub-states sit at `+0x2370`. Mode 2 (`xb_XLIVE_WORK_CLASS_JoinStep`, tables `0x10F0E8`/`0x10F128`) is the joining side. Its state 2 reads `XOnlineMatchSearchGetResults` into a vector of 0xBC-byte search results, and `xb_xlive_match_JoinFromID` (`XOnlineMatchSessionFindFromID`) enters it at state 2. Mode 3 (`xb_XLIVE_WORK_CLASS_HostStep`, tables `0x10EA5A`/`0x10EA96`) is the hosting side. Its state 2 finishes `XOnlineMatchSessionCreate` with `XOnlineMatchSessionGetInfo` and `XNetRegisterKey`, state 13 calls `XOnlineMatchSessionDelete`, and it draws "HERE COMES A NEW CHALLENGER!". The handlers are named `JoinUpdate_StateN`, `JoinDraw_StateN`, `HostUpdate_StateN` and `HostDraw_StateN` after their table slot, with a role in place of the number where the body shows one. Most of the match code reads a global match record through `xb_GetMatchInfo` (`0x798EA8`) rather than `this`, so its helpers are free functions named `xb_xlive_match_*`. The search-result vector's size-specific STL bodies are in `xdk.txt` (`std__vector_ElemBC__size` and so on). Its other helpers match no compiled instance and keep `xb_SearchResult*` names.

## Ports of the PS2-copy files

The scripts, the overrides, and the fold list are in `analysis-ps2map/`. [Its README](../analysis-ps2map/README.md) says what you need and how to port a file, name a callee, and check the result.

`include/structs.h` holds the game structures from the PS2 tree. Both builds are 32-bit with the same field sizes, so the layouts are unchanged. The `_Static_assert` block at its end lists offsets read from XBE code. Sources are checked with `gcc -m32 -std=gnu17 -Wno-incompatible-pointer-types -fsyntax-only -Iinclude FILE`. The last flag allows the PS2 function-pointer tables whose declared type has no parameter list, which newer GCC rejects by default.

A PS2-copy file is ported in four steps:

- `analysis-ps2map/portgen.py` keeps the functions that are located or folded and moves the rest under `#if 0`. It names each callee that has no XBE name by its aligned call target (`sub_ADDR`), or records that it is folded or has no aligned call. Declarations come from the PS2 headers until GCC is satisfied.
- A file-scope table with an XBE address is compared with the XBE: byte for byte for plain data (compiled for `-m32` and dumped), entry by entry for function pointers, where a folded entry must sit at the address its fold note gives. A table with no address is searched for: near the unnamed addresses its functions use, and for pointer tables also through `.rdata` and `.data`. The file header gives every comparison's result.
- `analysis-ps2map/portcheck.py` compares each function with its PS2 namesake. Anything the x86 has that the PS2 body lacks is flagged: callees, constants other than small ones (within 1, for compare rewrites), field offsets, globals (from the anniversary debug ELF), and unnamed data. Frame adjustments, the `frw` stride `0x700`, and the `WORK`/`PLW` sizes are ignored. On the hand-ported files it flags `Country` in `effect_51_init`, the one real change there, plus two strength-reduction constants and one char table.
- Each flagged function is read against its x86. The header says what was found ("Read against the x86: ..."), and the C is changed where the Xbox code differs.

A function without a flag has the same callees, constants, offsets, and named globals as the PS2 body. The check compares sets, so it misses a constant moved from one place to another within a function (the swapped page-change results in menu.c were found by comparing the stored values). Data addresses without a name in `data.txt` are listed on a separate header line. Those lines were written as "not a difference", but some were differences: the menu screen id at `0x796884` and the Xbox bytes inside `mpp_w` were found there. Naming a structure's base in `data.txt` (as `mpp_w` was) makes `portcheck.py` flag every function whose C does not use it.

Where the Xbox code is not the PS2 C, or the PS2 decompilation has no C for a function, the Xbox C is kept in `analysis-ps2map/overrides/<File>.c`, and `portgen.py` uses it in place of the PS2 definition. Its control flow was not read line by line. `analysis-ps2map/regen.py` regenerates a port from its last placeholder, keeping each "Read against the x86" note, so any other hand edit has to live in an override. `ovrcheck.py` confirms that every override reached its file, and `bodydiff.py` lists bodies that changed beyond renames.

Every PS2-copy file is now ported. The three outside `Source/Game` were ported by hand. `adler32.c` is stock zlib. `lsc_svr.c` has C for the three functions the PS2 tree keeps as asm, written from the x86. `mlPAD.c` has four pads.

## Xbox changes found by porting

Code differences between sf33rd.xbe and the PS2 build that porting has turned up so far. Each one is in the C and in its file's header.

- `effect_51_init` (Eff51.c) subtracts 3 from `position_y` only when `Country` is not 1. The PS2 retail build always subtracts it.
- `initRenderState` (AcrUtil.c) ends with `xb_SetViewportRect(0, 0, 640, 448)`, an Xbox-only routine that stores a viewport origin and size.
- The byte at `0x7AA5F1` (`D_007AA5F1` in the C) selects Japanese names. Init code sets it to 1 together with `Country = 1`, and a getter at `0xC80C8` returns it. Text tables carry two blocks indexed by it: `Letter_Data_99` (Eff99.c) differs in `AKUMA STAGE`/`GOUKI STAGE`, and `Letter_Data_A3` (EFFA3.c) in `PARRYING`/`BLOCKING`. It is also read by `effect_61_init`, `Setup_A8_Sub`, `get_message_conn_data`, `Setup_Letter_C4`, `Setup_Next_Page`, `Extra_Option`, `Direction_Menu`, and `checkSelObjFileLoaded`.
- `effect_A3_move` (EFFA3.c) passes its 1.4f/1.2f `zoom` to `SSPutStr_Bigger` truncated to a 16-bit integer, so the text is drawn at 1.0.
- `Menu_Letter_Data` (EFF61.c) has 67 entries per block, not 66: "Xbox Live" is inserted at index 6, so every later menu-letter index is one more than on PS2, and "ANALOG STICK" reads "Thumbsticks". `Ex_Letter_Data` (indexed in EFFC4.c) also has two blocks (SEMI-/AUTO PARRYING or BLOCKING).
- `Letter_Data_A8` (EFFA8.c) is `[2][2]`, with Japanese copies of the music-player lists that read Gouki Stage.
- `Letter_Data_63` (EFF63.c) offers eight screen sizes, 86% to 100%, where the PS2 build has 94% to 100%. `Disp_63_Sub` subtracts 86 from `Disp_Size_H`/`Disp_Size_V` and divides `X_Adjust`/`Y_Adjust` by 4, so those adjusts are stored times 4 on Xbox.
- `effect_B8_move` (EFFB8.c) holds `mes_already` to 20..27 outside Japan when `xb_GetOnlineFlag()` (the dword at `0x79A170`) is nonzero.
- `vibParamTrans` (PulPul.c) is rewritten for the Xbox motors: it calls `xb_PADSetVibration(port, level, 0xF0)` with a level of 1 to 7, where the PS2 code built DualShock actuator packets.
- `Init_Task_Aload` (init3rd.c) no longer loads the save at boot. `Game0_0` and `Game0_1` call `SaveInit` and `SaveMove` instead.
- `njScale`, `njTranslate`, and `njCalcPoint` (DC_Ghost.c) use D3DX math routines (`0x19496B`, `0x1949C7`, `0x194A23`, `0x1948E0`) where the PS2 code used VU0 macro asm.
- `fsUpdateDiskDriveError` (GD3rd.c) only sets `DskDrvErrType = 0xFFFF`; the PS2 disc polling is gone. `fsOpen`, `fsCansel`, and `fsCheckCommandExecuting` keep the PS2 logic over the Xbox ADXF.
- `Warning_Init` (DEMO00.c) loads warning file 18 when `Country` is 3 and 17 otherwise. The PS2 build loads 12.
- The save autoload runs in `Game0_0`/`Game0_1` (Game.c). `Game0_1` draws a frame (`xb_DrawSaveFrame`) and holds `Pause` while `SaveMove()` runs.
- `Game2_1` (Game.c) makes none of the PS2 build's three `ppgPurgeFromVRAM` calls.
- The dword at `0x79A170` (read by `xb_GetOnlineFlag`) gates Xbox-only code: `effect_B8_move` holds `mes_already` to 20..27 when it is set, `Game2_0` calls `xb_rebattle_Select(0)` and skips `All_Clear_ETC`, and `Game02` reads it before `Cut_Cut_Cut`.
- `effect_61_init` (EFF61.c) places a slash in the 14-pixel font differently with Japanese wording: it only sets `ny = 1`, where the PS2 code shifts it by -8, +17.
- `Game2_0` and `Game0_0`/`Game0_1` (Game.c) now carry their Xbox code. Earlier ports had kept the PS2 C there, because the generator skipped an override whose leading comment held parentheses.
- `Game00` (Game.c) sets the byte `0x7AA5EB` to 1 while `G_No[2]` is below 2.
- `emLevelRemake` (Com_Sub.c) lowers the cap in Japan: when `Country` is 1, `max` drops by `exd`, by `exd >> 1` at difficulty 6 and not at all at 7.
- `checkAdxFileLoaded` (Sound3rd.c) loads BGM pack files 85 and 86. The PS2 build loads 89 and 90.
- `mpp_w` is `0x7AA5C0`; `initTrainingData` (+0x29) and `inGame` (+0x2A) are where the PS2 layout puts them. From +0x2B on, the Xbox bytes do not fit the PS2 fields: `0x7AA5EC` is set after each `After_Title` step, `0x7AA5ED` on entering the training button config, `0x7AA5EF` supplies `Decide_ID` in `Load_Replay`, `0x7AA5F1` is the Japanese flag, and `0x7AA5F6`/`0x7AA5FA` are per-port bytes. The C keeps their addresses (`D_007AA5EC`, ...).
- menu.c has its own Xbox menu code:
  - Each menu sets a screen id in the dword `0x796884` on entry: 10 for button config, 12 for sound test, 13 for memory card, 19 for after replay, and 20 for mode select. `MC_Move_Sub` reads the id and moves again past the rows that screen leaves out: sound test below row 3, button config rows 3 and 7, after replay row 1, and memory card row 2.
  - `Setup_Button_Sub` draws no rows 3 and 7, and `Sound_Test` starts the cursor on row 3. The sound test's reset entry sets both levels to 11 (PS2: 15).
  - The page-change results are `0x400` for left and `0x40` for right, in `Dir_Move_Sub_LR`, `Ex_Move_Sub_LR`, `Extra_Option`, and `Direction_Menu`. `Extra_Option` and `Direction_Menu` also lose their cursor sound.
  - Menu labels from 7 up are one higher (the `Menu_Letter_Data` insert): `Training_Mode`, `Option_Select`, `System_Direction`, `Game_Option`, `Screen_Adjust`, `Sound_Test`, `Memory_Card`, and `After_Replay`.
  - `Mode_Select` has eight entries. Entry 6 enters an Xbox-only mode (task state 14) through Xbox code at `0x1072A9`, `0x11053D`, `0xCBA99`, and `0x113175`, and the first frame goes there directly when `xb_LiveWork_Get1C4()` and the dword `0x32F858` allow it. Back soft-resets.
  - `Screen_Move_Sub_LR` steps the position by 1 and allows sizes down to 88. `Screen_Adjust` stores the position times 4 and copies the settings into `Convert_Buff` and `save_w[1]` every frame.
  - `Yes_No_Cursor_Move_Sub` reads the pad through `xb_GetStartBackPress`: START soft-resets and BACK returns.
  - `toSelectGame` draws its button with `xb_DrawSystemMessage` and exits through Xbox code instead of `jmpRebootProgram`. `Pause_1st_Sub` leaves with `r_no[2] = 0` (PS2: `0x63`).
  - `Wait_Pause_in_Tr` shows the removed-controller message through `dispControllerWasRemovedMessage(132, 70, 16, Pause_ID)`. That routine is an Xbox rewrite of `dispControllerWasRemovedMessage` that prints the port number.
  - `Load_Replay` takes `Decide_ID` from `0x7AA5EF`.
- Every FadeIn/FadeOut call passes priority 1 (the `PrioBase` index) where the PS2 C passes 8. All 69 literal call sites in the XBE push 1. The hand ports already used 1, and `portgen.py` now rewrites the PS2-copy calls.
- `Check_Reset` (Reset.c) also blocks the reset while `Present_Mode` is 2, the Xbox-only mode.
- `Purge_memory_of_list` (MMTMCNT.c) releases sound banks 1 and 2 (`xb_PurgeListEntry`) when list entries 3 and 4 are set.
- `effect_23_move` and `effect_A8_move` call the Xbox-only `xb_SetButtonImageScale` (a 2D scale setup) before `dispButtonImage`, and draw the button at a smaller size.
- `cseSysSetMono` and `cseSysSetMasterVolume` (Sound3rd.c) return 0 instead of the inner call's result.
- `Game01`, `Game03`, `Game12`, and `Game12_2` (Game.c) call Xbox-only code: Game01 starts with a guard that can return early, a versus win in Game03 goes to G_No 13 through `xb_ClearRebattleWork`, and Game12_2 calls `xb_LiveWork_Set2330(0)` on leaving.
- `Judge_Winner` (Manage.c) gives a tie to player 1 while `xb_GetOnlineFlag` is set; `effb8_normal_or_senyou` (EFFB8.c) also picks randomly then.
- `Ck_Coin` (Game.c) takes the joining player from `xb_GetJoiningPlayer` (START or A, 0x4100; PS2 START only).
- `load_it_use_any_key2` (GD3rd.c) has no file-number check, and a file of size 0 enters the disc-error loop `xb_ShowDiskReadError`.
- `Menu_Init` (menu.c) also calls `Setup_BG_General`, and `EFF57_WALL` (EFF57.c) calls the Xbox-only `xb_CreateScreenTextures`.
- `waitVsyncDummy` (GD3rd.c) waits for no vsync; it only runs `ADXM_ExecMain` and the folded `cseExecServer`.
- `CAPLOGO_Init` (DEMO00.c) loads the logo from file 80 (PS2 75), another case of the Xbox file renumbering.
- `Game_Data_Init` (SYS_sub.c) has no analog-stick check; `mlSysSetMono` only stores its switch, and `mlSysSetMasterVolume` clamps to 0..127 and looks the volume up in a table (Sound3rd.c).
- The pad layer (mlPAD.c) handles four pads. `flpad_root`, `flpad_conf`, `flpad_config`, and `tarpad_root` have four entries, and `flPADInitialize`, `flPADGetALL`, and `flPADACRConf` loop over all of them (PS2: two). `tarPADInit`, `tarPADRead`, and `flPADConfigSetACRtoXX` are Xbox routines (`0x17592`, `0x175D7`, `0x171AF`).

## Data names

`config/sf33rd/symbols/data.txt` names globals with their PS2 names: `Name = 0x00ADDR; // type:data size:0xNN hand|map`. `hand` rows were read off bodies in hand-ported files. `map` rows come from the anniversary debug ELF. For each function named in both builds, the debug body's data references are compared with the XBE body's absolute operands. A symbol's XBE base is the one that makes every function's addresses fall on offsets that same function used. Checked against the hand rows, 264 of 270 map placements agree. A hand row can be wrong too: `F_No0` to `F_No3` had been read off a chained assignment, which does not fix their order. They were corrected from `Flash_Start`, `Flash_Please`, and `Exit_Title_Sub_Entry`, each of which uses a different subset. A map row that conflicts with a hand row is dropped. `size` is the PS2 debug size, and the Xbox layout can differ.

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
