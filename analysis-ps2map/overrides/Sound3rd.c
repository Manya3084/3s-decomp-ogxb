/* Notes from the hand port this file replaced:
 * Go_BGM is 0x9C646 size 0x29 and is a scanned start.
 * SsRequest is 0x9C5BF size 0x29 and is a scanned start.
 * SsRequest_CC is 0x9C5E8 size 0x2F and is a scanned start.
 * Standby_BGM is 0x9C617 size 0x2F and is a scanned start.
 * SsBgmOff is 0x9C66F size 0x29 and is a scanned start.
 * SsBgmFadeIn is 0x9C698 size 0x46 and is a scanned start.
 * SsBgmFadeOut is 0x9C6DE size 0x35 and is a scanned start.
 * SsBgmControl is 0x9C713 size 0x44 and is a scanned start.
 * SsBgmHalfVolume is 0x9C757 size 0x33 and is a scanned start.
 * Init_bgm_work is 0x9B845 size 0x1C, interior after the ret.
 * spu_all_off is 0x9B861 size 0xF, interior after the ret.
 * setSeVolume is 0x9B870 size 0x28, interior after the ret.
 * setupSoundMode is 0x9B898 size 0x26, interior after the ret.
 * Exit_sound_system is 0x9BCEC size 0x45, interior after the ret.
 * SE_cursor_move is 0x9C78A size 0x9, interior after the ret.
 * SE_dir_cursor_move is 0x9C79C size 0xC, interior after the ret.
 * sound_bgm_off is 0x9C7A8 size 0x18, interior after the ret.
 * sound_all_off is 0x9C7C0 size 0xA, interior after the jmp.
 * SsAllNoteOff is 0x9C7CA size 0x5, interior after the jmp.
 * ptix is 0x7F. system_init_level is the dword at 0x7AABDC.
 * se_level is the word at 0x9CA4B4. bgm_half_down is 0x8813F8.
 * bgm_exe is 0x8813E0 and bgm_req is 0xC7C810. adxt is 0x8813DC.
 * sound_mode is the byte at 0x7C5958. These requests do not call
 * Store_Sound_Code. 0x9BD31 and 0x9C57A are sound_request_for_dc and
 * SsRequestPan. 0x9C793 stays
 * unnamed because SE_selected and SE_dir_selected share that body.
 * checkAdxFileLoaded is 0x9B7DC size 0x69. It loads the BGM pack file 85
 * (bgm_type 0) or 86 (PS2: 89 and 90). adx_NowOnMemoryType is the byte at
 * 0x32FE2C, bgm_type (sys_w.bgm_type) the byte at 0x7C595A, adx_VS is
 * 0xC4BEE0 and adx_EmSel is 0xB24A00. sub_00097103 is Push_ramcnt_key's
 * body, unnamed here.
 * cseSysSetMono (0xF4510), cseSysSetMasterVolume (0xF451D), and
 * cseSeStopAll (0xF452A) sit with cseTsbRequest, so their C is in
 * AcrSDK/MiddleWare/PS2/CapSndEng/cse.c. Here the compiler would inline
 * them, and retail calls them (spu_all_off jumps to cseSeStopAll).
 * mlSysSetMono is 0xF4D61 size 0xA and only stores the switch in the dword
 * at 0x797100. mlSysSetMasterVolume is 0xF4FF2 size 0x2A: the volume is
 * clamped to 0..127 and looked up in the table at 0x3F3510.
 */
/* Xbox: mlSysSetBankVolume is __stdcall (mlSysSetMasterVolume does not clean up after it). */
extern void XB_STDCALL mlSysSetBankVolume(s32 port, s32 mask, s32 vol);
/* Xbox versions defined below; the PS2 headers declare them returning s32. */
void mlSysSetMono(u32 mono_sw);
void mlSysSetMasterVolume(s32 vol);
void ADXT_Init(void);

extern s32 dword_795CF4;
extern u8 sound_mode;
extern void work_init_zero(void *dst, s32 size);
extern void ADXT_SetOutputMono(u32 mono_sw);
extern void AIXP_Finish(void);
extern void ADXT_Finish(void);
void sound_all_off(void);
extern u8 bgm_type;
extern s16 load_it_use_any_key(u16 fnum, u8 kokey, u8 group);
extern void* Get_ramcnt_address(s16 key);
extern s32 ppgSetupCmpChunk(u8* srcAdrs, s32 num, void* dstAdrs);
extern void sub_00097103(s16 key);
extern s32 D_00797100;
extern s32 D_00797BA8;
extern s32 D_003F3510[128];

void Init_bgm_work(void) {
    work_init_zero(&bgm_exe, sizeof(BGMExecution));
    work_init_zero(&bgm_req, sizeof(BGMRequest));
}

void spu_all_off(void) {
    if (system_init_level & 1) {
        cseSeStopAll();
    }
}

void setSeVolume(void) {
    f32 vol;

    if (system_init_level & 2) {
        vol = (127.0f / 15.0f) * (f32)se_level;
        cseSysSetMasterVolume((s32)vol);
    }
}

void setupSoundMode(void) {
    if (system_init_level & 2) {
        cseSysSetMono(sound_mode);
        ADXT_SetOutputMono(sound_mode);
    }
}

void Exit_sound_system(void) {
    if (system_init_level & 2) {
        if (dword_795CF4 != 0) {
            AIXP_Finish();
        }

        ADXT_Destroy(adxt);
        ADXT_Finish();
        system_init_level &= ~2;
    }

    if (system_init_level & 1) {
        spu_all_off();
        system_init_level &= ~1;
    }
}

void SsRequest(u16 ReqNumber) {
    SoundPatchConfig rmcode;

    if (remake_sound_code_for_DC(ReqNumber, &rmcode)) {
        return;
    }

    sound_request_for_dc(&rmcode, 0);
}

void SsRequest_CC(u16 num) {
    SoundPatchConfig rmcode;

    if (remake_sound_code_for_DC(num, &rmcode)) {
        return;
    }

    rmcode.bank = 9;
    sound_request_for_dc(&rmcode, 0);
}

void Standby_BGM(u16 num) {
    SoundPatchConfig rmcode;

    if (remake_sound_code_for_DC(num, &rmcode)) {
        return;
    }

    rmcode.bank = 2;
    sound_request_for_dc(&rmcode, 0);
}

void Go_BGM(void) {
    SoundPatchConfig rmcode;

    rmcode.ptix = 0x7F;
    rmcode.bank = 3;
    rmcode.port = 0;
    rmcode.code = 0;
    sound_request_for_dc(&rmcode, 0);
}

void SsBgmOff(void) {
    SoundPatchConfig rmcode;

    rmcode.ptix = 0x7F;
    rmcode.bank = 1;
    rmcode.port = 0;
    rmcode.code = 0;
    sound_request_for_dc(&rmcode, 0);
}

void SsBgmFadeIn(u16 ReqNumber, u16 FadeSpeed) {
    SoundPatchConfig rmcode;
    s32 fade_time;

    if (remake_sound_code_for_DC(ReqNumber, &rmcode) || rmcode.ptix != 0x7F) {
        return;
    }

    fade_time = 0x8000 / (s32)FadeSpeed;
    rmcode.bank = 6;
    rmcode.port = (s16)fade_time;
    sound_request_for_dc(&rmcode, 0);
}

void SsBgmFadeOut(u16 time) {
    SoundPatchConfig rmcode;
    s32 fade_time = 0x8000 / (s32)time;

    rmcode.ptix = 0x7F;
    rmcode.bank = 5;
    rmcode.code = 0;
    rmcode.port = (s16)fade_time;
    sound_request_for_dc(&rmcode, 0);
}

void SsBgmControl(s8 unused, s8 volume) {
    SoundPatchConfig rmcode;

    (void)unused;
    rmcode.ptix = 0x7F;
    rmcode.bank = 7;
    rmcode.code = 0;
    rmcode.port = volume;

    if (rmcode.port < -0x7F) {
        rmcode.port = -0x7F;
    }

    if (rmcode.port > 0) {
        rmcode.port = 0;
    }

    sound_request_for_dc(&rmcode, 0);
}

void SsBgmHalfVolume(s16 flag) {
    SoundPatchConfig rmcode;

    bgm_half_down = flag;
    rmcode.ptix = 0x7F;
    rmcode.bank = 7;
    rmcode.code = 0;
    rmcode.port = 0;
    sound_request_for_dc(&rmcode, 0);
}

void SE_cursor_move(void) {
    SsRequest(96);
}

void SE_dir_cursor_move(void) {
    SsRequest(343);
}

void sound_bgm_off(void) {
    if ((system_init_level & 2) && adx_now_playing() != 0) {
        SsBgmOff();
    }
}

void sound_all_off(void) {
    sound_bgm_off();
    spu_all_off();
}

void SsAllNoteOff(void) {
    sound_all_off();
}

void checkAdxFileLoaded(void) {
    u8* adr;
    s16 key;
    u16 fnum;

    if (adx_NowOnMemoryType == bgm_type) {
        return;
    }

    if (bgm_type == 0) {
        fnum = 85;
    } else {
        fnum = 86;
    }

    do {
        key = load_it_use_any_key(fnum, 21, 0);
    } while (key == 0);

    adr = (u8*)Get_ramcnt_address(key);
    ppgSetupCmpChunk(adr, 0, adx_VS);
    ppgSetupCmpChunk(adr, 1, adx_EmSel);
    sub_00097103(key);
    adx_NowOnMemoryType = bgm_type;
}

void mlSysSetMono(u32 mono_sw) {
    D_00797100 = mono_sw;
}

void mlSysSetMasterVolume(s32 vol) {
    if (vol < 0) {
        vol = 0;
    }

    if (vol > 127) {
        vol = 127;
    }

    mlSysSetBankVolume(D_00797BA8, 0xFF, D_003F3510[vol]);
}

/* Xbox: 2 only while adx_now_playing() returns 1 (branchless in retail). */
s32 bgm_play_status() {
    if (bgm_exe.kind == 5) {
        return 1;
    }

    if (adx_now_playing() == 1) {
        return 2;
    }

    return 0;
}

/* Xbox: also ends when the AIX player (handle at 0xAE6FEC) is in state 3. */
extern void *D_00AE6FEC;
void xb_ClearAdxtError(s32 which);
void xb_CreateDirectSound(const char* path);
void AIXP_Init(void);
void* AIXP_Create(s32 maxnch, s32 nstm, void* work, s32 worksize);
void* XB_STDCALL XPhysicalAlloc(u32 size, u32 address, u32 alignment, u32 protect);
extern const struct _SAVE_W Game_Default_Data;
void xb_InitSoundBankList(void);
void xb_ClearColorRamEntries(void);
void xb_SetColorRamEntry(void* addr, u32 size, s32 id, s32 index);
s32 AIXP_GetStat(void *aixp);
s32 adx_now_playend() {
    bgm_exe.state = ADXT_GetStat(adxt);

    if (bgm_exe.state == ADXT_STAT_PLAYEND) {
        return 1;
    }

    return AIXP_GetStat(D_00AE6FEC) == 3;
}

/* Xbox: no Debug_w[5] test */
s32 bgm_separate_check() {
    return (mpp_w.inGame | bgm_seamless_always) != 0;
}

/* Xbox: always 1; the code after it in the PS2 slot (0x9B792) is another function */
s32 sndCheckVTransStatus(s32 type) {
    return 1;
}

/* Xbox: an ADXT error state (6) is cleared, and the AIX player (handle at 0xAE6FEC) also counts: state 2 is playing, state 4 an error that is cleared */
s32 adx_now_playing() {
    s32 stat;

    bgm_exe.state = ADXT_GetStat(adxt);

    if ((bgm_exe.state == ADXT_STAT_PLAYING) || (bgm_exe.state == ADXT_STAT_DECEND)) {
        return 1;
    }

    if (bgm_exe.state == 6) {
        xb_ClearAdxtError(0);
    }

    stat = AIXP_GetStat(D_00AE6FEC);

    if (stat == 2) {
        return 1;
    }

    if (stat == 4) {
        xb_ClearAdxtError(1);
    }

    return 0;
}

/* The Xbox sets up its sound bank list and color RAM entries, loads three color files (109, 110, 111), and sets init level bit 0; it has no SPU memory map. */
void sndInitialLoad() {
    xb_InitSoundBankList();
    xb_ClearColorRamEntries();
    load_any_color(109, 20); // This loads SE.bd (index 7)
    load_any_color(110, 20);
    load_any_color(111, 20);
    cseTsbSetBankAddr(0, *cseTSBDataTable);
    xb_SetColorRamEntry(0, 0, 0, 0);
    system_init_level |= 1;
}

/* The flag test is inverted, as the retail branch layout has it. */
void bgm_play_request(s32 filenum, s32 flag) {
    if (flag != 0) {
        ADXT_StartAfs(adxt, 0, bgm_table[sys_w.bgm_type][filenum].fnum);
    } else {
        ADXT_EntryAfs(adxt, 0, filenum);
    }
}

/* The Xbox does not call Store_Sound_Code. */
void SsRequestPan(u16 reqNum, s16 start, s16 /* unused */, s32 /* unused */, s32 /* unused */) {
    SoundPatchConfig rmcode;

    start -= 0x40;

    if (start < -0x3F) {
        start = -0x3F;
    }

    if (start > 0x3F) {
        start = 0x3F;
    }

    if (remake_sound_code_for_DC(reqNum, &rmcode)) {
        return;
    }

    sound_request_for_dc(&rmcode, start);
}

/* The Xbox takes the levels from Game_Default_Data, creates DirectSound, and allocates an AIX player (D_00AE6FEC) in 0x6952C bytes of physical memory; it has no PS2 sound driver. */
void Init_sound_system() {
    bgm_level = Game_Default_Data.BGM_Level;
    se_level = Game_Default_Data.SE_Level;
    bgm_half_down = 0;
    current_bgm = 0;
    bgm_seamless_always = 0;
    sys_w.sound_mode = 0;
    sys_w.bgm_type = 0;
    xb_CreateDirectSound("D:\\XB_HostPC\\");
    ADXT_Init();
    AIXP_Init();
    adxt = ADXT_Create(2, adx_stm_work, ADX_STM_WORK_SIZE);
    dword_795CF4 = (s32)XPhysicalAlloc(0x6952C, -1, 0, 4);

    if (dword_795CF4 != 0) {
        D_00AE6FEC = AIXP_Create(3, 2, (void*)dword_795CF4, 0x6952C);
    } else {
        flLogOut("AIXP_Create Failed.\n");
    }

    system_init_level |= 2;
}

/* Xbox-only functions in this object (moved from src/sf33rd/Source/XBOX/xb_09B8BE.c; analysis-ps2map/xbgen.py checked each). */
void ADXT_ClearErrCode(ADXT adxt);

void xb_ClearAdxtError(s32 which) {
    if (which == 0) {
        ADXT_ClearErrCode(adxt);
    }
}

/* Xbox-only functions in this object (moved from src/sf33rd/Source/XBOX/xb_0F4D6B.c; analysis-ps2map/xbgen.py checked each). */
void XB_STDCALL IXACTEngine_CreateSoundSource(s32 a0, s32 a1, s32 a2);
void XB_STDCALL IXACTEngine_CreateSoundBank(s32 a0, s32 a1, s32 a2, s32 a3);
void XB_STDCALL IXACTEngine_RegisterWaveBank(s32 a0, s32 a1, s32 a2, s32 a3);
void XB_STDCALL IXACTEngine_UnRegisterWaveBank(s32 a0, s32 a1);
void XB_STDCALL IXACTEngine_SetMasterVolume(s32 a0, s32 a1, s32 a2);
void XB_STDCALL IXACTEngine_GetNotification(s32 a0, s32 a1, s32 a2);
void XB_STDCALL IXACTSoundBank_Release(s32 a0);
void XB_STDCALL IXACTSoundBank_Stop(s32 a0, s32 a1, s32 a2, s32 a3);
extern s32 D_00795C10;
extern u8 D_00797120[];
s32 XB_STDCALL xb_DownloadEffectsImage(s32 dsound, s32 a, s32 b, s32* loc, void* out);

void XB_STDCALL xb_CreateSoundSource(s32 a0, s32 a1, s32 a2) {
    IXACTEngine_CreateSoundSource(a0, a1, a2);
}

void XB_STDCALL xb_CreateSoundBank(s32 a0, s32 a1, s32 a2, s32 a3) {
    IXACTEngine_CreateSoundBank(a0, a1, a2, a3);
}

void XB_STDCALL xb_RegisterWaveBank(s32 a0, s32 a1, s32 a2, s32 a3) {
    IXACTEngine_RegisterWaveBank(a0, a1, a2, a3);
}

void XB_STDCALL xb_UnRegisterWaveBank(s32 a0, s32 a1) {
    IXACTEngine_UnRegisterWaveBank(a0, a1);
}

void XB_STDCALL mlSysSetBankVolume(s32 a0, s32 a1, s32 a2) {
    IXACTEngine_SetMasterVolume(a0, a1, a2);
}

void XB_STDCALL xb_GetNotification(s32 a0, s32 a1, s32 a2) {
    IXACTEngine_GetNotification(a0, a1, a2);
}

void XB_STDCALL xb_XactCall_1B7FB7(s32 a0) {
    IXACTSoundBank_Release(a0);
}

void XB_STDCALL xb_XactCall_1B8048(s32 a0, s32 a1, s32 a2, s32 a3) {
    IXACTSoundBank_Stop(a0, a1, a2, a3);
}

s32 xb_PlaySoundCue(s32 addr, s32 size) {
    s32 loc[2];

    loc[0] = -1;
    loc[1] = -1;
    return xb_DownloadEffectsImage(D_00795C10, addr, size, loc, D_00797120) >= 0;
}

/* The Xbox has no Debug_w[44] test. */
void bgm_volume_setup(s16 data) {
    s16 bhd;

    bgm_fade_ix = data;
    bhd = bgm_fade_ix;
    bgm_vol_now = bhd + bgm_vol_mix;

    if (bgm_half_down) {
        if (Country == 1) {
            bgm_vol_now /= 3;
        } else {
            bgm_vol_now = 0;
        }
    }

    if (bgm_vol_now > bgm_vol_mix) {
        bgm_vol_now = bgm_vol_mix;
    }

    if (bgm_vol_now < 0) {
        bgm_vol_now = 0;
    }

    ADXT_SetOutVol(adxt, adx_volume[bgm_vol_now]);
}

/* Xbox-only functions of this object (analysis-ps2map/xbgen.py checked each). */
s32 AIXP_Pause(s32 aixp, s32 sw);

