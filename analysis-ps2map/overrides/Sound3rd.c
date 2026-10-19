/* The Xbox BGM tables: bgm_tableDC is 0x32FE30, bgm_exdataDC is 0x330050,
 * bgm_tableAC is 0x3301D0, bgm_exdataAC is 0x3303F0, bgm_table is 0x3304F0
 * and bgm_exdata is 0x3304F8. */
/* The sound event tables cseTSBDataTable points at: TSB_SE is 0x422C00, TSB_PL00 is 0x418980, TSB_PL01 is 0x4191A0, TSB_PL02 is 0x4199C0, TSB_PL03 is 0x41A1E0, TSB_PL04 is 0x41AA00, TSB_PL05 is 0x41B220, TSB_PL06 is 0x41BA40, TSB_PL07 is 0x41C260, TSB_PL08 is 0x41CA80, TSB_PL09 is 0x41D2A0, TSB_PL10 is 0x41DAC0, TSB_PL11 is 0x41E2E0, TSB_PL12 is 0x41EB00, TSB_PL13 is 0x41F320, TSB_PL14 is 0x41FB40, TSB_PL15 is 0x420360, TSB_PL16 is 0x420B80, TSB_PL17 is 0x4213A0, TSB_PL18 is 0x421BC0, TSB_PL19 is 0x4223E0. */

/* Data read off the retail code: bgm_fade is 0xAE6FE0. */

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
 * 0xC4BEE0 and adx_EmSel is 0xB24A00. Push_ramcnt_key is Push_ramcnt_key's
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
extern void Push_ramcnt_key(s16 key);
extern s32 D_00797100;
extern s32 D_00797BA8;
/* D_003F3510 is 0x3F3510. */
s32 D_003F3510[128] = {
    -9999, -3612, -3260, -3010, -2816, -2658, -2524, -2408, -2305, -2214, -2131, -2056, -1986,
    -1922, -1862, -1806, -1753, -1703, -1656, -1612, -1569, -1529, -1490, -1453, -1418, -1384,
    -1351, -1320, -1289, -1260, -1231, -1204, -1177, -1151, -1126, -1101, -1078, -1054, -1032,
    -1010, -988, -967, -947, -927, -907, -888, -870, -851, -834, -816, -799, -782, -765, -749, -733,
    -718, -702, -687, -672, -658, -643, -629, -615, -602, -588, -575, -562, -549, -536, -524, -511,
    -499, -487, -475, -464, -452, -441, -430, -419, -408, -397, -386, -376, -365, -355, -345, -335,
    -325, -315, -305, -296, -286, -277, -268, -258, -249, -240, -231, -223, -214, -205, -197, -188,
    -180, -172, -163, -155, -147, -139, -131, -123, -115, -108, -100, -93, -85, -78, -70, -63, -56,
    -48, -41, -34, -27, -20, -13, -6, 0,
};

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
    Push_ramcnt_key(key);
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

void XB_STDCALL IXACTSoundBank__Stop(s32 a0, s32 a1, s32 a2, s32 a3) {
    IXACTSoundBank_Stop(a0, a1, a2, a3);
}

/* The xact.h IXACTSoundSource:: inline wrappers, out of line: jumps to
 * the library's IXACTSoundSource_SetMixBins (0x1B807F) and
 * IXACTSoundSource_StopSoundCues (0x1B8089). */
void XB_STDCALL IXACTSoundSource_SetMixBins(s32 a0, s32 a1);
void XB_STDCALL IXACTSoundSource_StopSoundCues(s32 a0);

void XB_STDCALL IXACTSoundSource__SetMixBins(s32 a0, s32 a1) {
    IXACTSoundSource_SetMixBins(a0, a1);
}

void XB_STDCALL IXACTSoundSource__StopSoundCues(s32 a0) {
    IXACTSoundSource_StopSoundCues(a0);
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

/* Xbox-only: the opening-BGM AIX stream. xb_AixBgmVolume (static: the
 * fade comes in edx) sets the six speaker volumes from bgm_vol_now; the
 * stream is ST3_3_OP.aix on the AIX handle D_00AE6FEC. */
void AIXP_SetLpSw(void *aixp, s32 sw);
void AIXP_Stop(s32 aixp);
void AIXP_SetOutVolDolbyDigital(void *aixp, s32 spkid, s32 vol);
s32 xb_aixp_StartFnameSurround(void *aixp, const char *fname, void *dir);

void xb_AixBgmVolume(s32 fade) {
    s32 i;

    bgm_fade_ix = fade;
    bgm_vol_now = bgm_vol_mix + fade;

    if (bgm_half_down != 0) {
        if (Country == 1) {
            bgm_vol_now = bgm_vol_now / 3;
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

    for (i = 0; i < 6; i++) {
        if (i != 5) {
            AIXP_SetOutVolDolbyDigital(D_00AE6FEC, i, adx_volume[bgm_vol_now]);
        } else {
            AIXP_SetOutVolDolbyDigital(D_00AE6FEC, 5, adx_volume[bgm_vol_now]);
        }
    }
}

s32 xb_AixBgmStop(u16 bgm, s32 fade) {
    if (bgm == 0x34 && bgm_type == 0) {
        if (dword_795CF4 != 0) {
            AIXP_Stop((s32)D_00AE6FEC);
            AIXP_SetLpSw(D_00AE6FEC, 0);
            AIXP_Pause((s32)D_00AE6FEC, 1);
            xb_aixp_StartFnameSurround(D_00AE6FEC, "ST3_3_OP.aix", 0);
            xb_AixBgmVolume(fade);
        }

        return 1;
    }

    return 0;
}

s32 xb_AixBgmResume(u16 bgm) {
    if (bgm == 0x34 && bgm_type == 0) {
        if (dword_795CF4 != 0) {
            AIXP_Pause((s32)D_00AE6FEC, 0);
        }

        return 1;
    }

    return 0;
}

/* Xbox: a bad code is reported in the return value; the PS2 loop that
 * printed it forever is gone. sdcode_conv is 0x265808. */
u16 remake_sound_code_for_DC(u16 code, SoundPatchConfig* rmcode) {
    u16 cd;
    u16 mtf;
    u16 p2s;
    u16 rnum;

    rnum = mtf = p2s = 0;

    if (code >= 0x760) {
        code -= 0x600;
        mtf = 1;
    }

    if (code >= 0x400) {
        code -= 0x300;
        p2s = 1;
    }

    rmcode->code = (cd = sdcode_conv[code]) & 0xFFF;

    switch (cd & 0xF000) {
    case 0x0:
        switch (p2s + mtf * 2) {
        case 0:
            rmcode->ptix = 1;
            rmcode->bank = 0;
            rmcode->port = 0;
            break;

        case 1:
            rmcode->ptix = 2;
            rmcode->bank = 1;
            rmcode->port = 3;
            break;

        case 2:
            rmcode->ptix = 2;
            rmcode->bank = 1;
            rmcode->port = 0;
            rmcode->code += 32;
            break;

        case 3:
            rmcode->ptix = 1;
            rmcode->bank = 0;
            rmcode->port = 3;
            rmcode->code += 32;
            break;
        }

        break;

    case 0x2000:
        rmcode->ptix = 0;
        rmcode->bank = 0;

        if (p2s) {
            rmcode->port = 3;
        } else {
            rmcode->port = 0;
        }

        break;

    case 0x3000:
        rmcode->ptix = 0;
        rmcode->bank = 0;

        if (p2s) {
            rmcode->port = -3;
        } else {
            rmcode->port = 0;
        }

        break;

    case 0x8000:
        rmcode->ptix = 0x7F;
        rmcode->bank = 4;
        rmcode->port = 0;
        break;

    default:
        rmcode->ptix = 0x7FFF;
        rmcode->bank = 0;
        rmcode->port = 0;
        rnum = 1;
        break;
    }

    return rnum;
}

s32 xb_AixBgmStop(u16 bgm, s32 fade);
s32 xb_AixBgmResume(u16 bgm);

/* Xbox: the AIX player is stopped with ADXT; a track change goes through
   xb_AixBgmStop and a resume through xb_AixBgmResume, and the opening
   theme (0x34) in the new arrangement plays as ST3_3_OP.aix. */
void BGM_Server() {
    if (!(system_init_level & 2)) {
        return;
    }

    if (bgm_req.req) {
        bgm_req.req = 0;
        bgm_exe.kind = bgm_req.kind;
        bgm_exe.data = bgm_req.data;

        if (bgm_req.code != -1) {
            bgm_exe.code = bgm_req.code;
        }

        bgm_exe.rno = 0;

        if (bgm_table[sys_w.bgm_type][bgm_exe.code].data & 0x8000) {
            bgm_exe.kind = 0;
        }
    }

    if (bgm_exe.code != 0) {
        bgm_vol_mix = bgm_level * bgm_table[sys_w.bgm_type][bgm_exe.code].vol / 15;
    }

    switch (bgm_exe.kind) {
    case 1:
        AIXP_Stop((s32)D_00AE6FEC);
        ADXT_Stop(adxt);
        bgm_seamless_clear();
        current_bgm = 0;
        bgm_exe.kind = 0;
        break;

    case 2:
        AIXP_Stop((s32)D_00AE6FEC);
        ADXT_Stop(adxt);

        if ((bgm_table[sys_w.bgm_type][bgm_exe.code].data & 0x4000) && (bgm_separate_check() != 0)) {
            bgm_exe.exIndex = bgm_table[sys_w.bgm_type][bgm_exe.code].data & 0xFF;
            bgm_exe.exEntry = bgm_exdata[sys_w.bgm_type][bgm_exe.exIndex].numStart;
            ADXT_Destroy(adxt);
            adxt = ADXT_Create(2, adx_stm_work, ADX_STM_WORK_SIZE);
            bgm_volume_setup(0);
            ADXT_Pause(adxt, 1);
            bgm_play_request(bgm_exe.exEntry, 0);
            bgm_exe.nowSeamless = 1;
            ADXT_StartSeamless(adxt);
        } else if (xb_AixBgmStop(bgm_exe.code, 0) != 1) {
            bgm_seamless_clear();
            bgm_volume_setup(0);
            ADXT_Pause(adxt, 1);

            if (adx_NowOnMemoryType == sys_w.bgm_type) {
                switch (bgm_exe.code) {
                case 0x33:
                    ADXT_StartMem(adxt, adx_VS);
                    break;

                case 0x39:
                    ADXT_StartMem(adxt, adx_EmSel);
                    break;

                default:
                    bgm_play_request(bgm_exe.code, 1);
                    break;
                }
            } else {
                bgm_play_request(bgm_exe.code, 1);
            }
        }

        current_bgm = bgm_exe.code;
        bgm_exe.kind = 0;
        break;

    case 3:
        if (xb_AixBgmResume(bgm_exe.code) != 1) {
            ADXT_Pause(adxt, 0);
        }

        bgm_exe.kind = 0;
        break;

    case 4:
        if ((bgm_table[sys_w.bgm_type][bgm_exe.code].data & 0x4000) && (bgm_separate_check() != 0)) {
            if ((bgm_exe.nowSeamless == 0) || (bgm_exe.code != current_bgm)) {
                bgm_exe.exIndex = bgm_table[sys_w.bgm_type][bgm_exe.code].data & 0xFF;
                bgm_exe.exEntry = bgm_exdata[sys_w.bgm_type][bgm_exe.exIndex].numStart;

                if (bgm_exe.nowSeamless == 0) {
                    ADXT_Destroy(adxt);
                    adxt = ADXT_Create(2, adx_stm_work, ADX_STM_WORK_SIZE);
                    bgm_volume_setup(0);
                }

                bgm_play_request(bgm_exe.exEntry, 0);

                if (bgm_exe.nowSeamless == 0) {
                    bgm_exe.nowSeamless = 1;
                    ADXT_StartSeamless(adxt);
                }
            }
        } else {
            bgm_seamless_clear();
            AIXP_Stop((s32)D_00AE6FEC);
            bgm_volume_setup(0);

            /* Xbox: the opening theme in the new arrangement is the 5.1
               AIX stream */
            if (bgm_exe.code == 0x34 && sys_w.bgm_type == 0) {
                ADXT_Stop(adxt);
                xb_aixp_StartFnameSurround(D_00AE6FEC, "ST3_3_OP.aix", 0);
            } else if (adx_NowOnMemoryType == sys_w.bgm_type) {
                switch (bgm_exe.code) {
                case 0x33:
                    ADXT_StartMem(adxt, adx_VS);
                    break;

                case 0x39:
                    ADXT_StartMem(adxt, adx_EmSel);
                    break;

                default:
                    bgm_play_request(bgm_exe.code, 1);
                    break;
                }
            } else {
                bgm_play_request(bgm_exe.code, 1);
            }
        }

        if (ADXT_GetStatPause(adxt) != 0) {
            ADXT_Pause(adxt, 0);
        }

        current_bgm = bgm_exe.code;
        bgm_exe.kind = 0;
        break;

    case 5:
        switch (bgm_exe.rno) {
        case 0:
            bgm_fade.in.dex.hi = bgm_vol_now;
            bgm_fade.in.dex.low = -0x8000;
            bgm_fade.speed = -(bgm_fade.in.cal / bgm_exe.data);
            bgm_fade.in.cal = 0;
            bgm_exe.rno = 1;
            /* fallthrough */

        case 1:
            if (adx_now_playing() == 0) {
                bgm_exe.rno = 3;
                break;
            } else {
                bgm_exe.rno = 2;
                bgm_exe.volume = 0;
            }

            /* fallthrough */

        case 2:
            bgm_fade.in.cal += bgm_fade.speed;
            bgm_volume_setup(bgm_fade.in.dex.hi);

            if (bgm_vol_now) {
                break;
            }

            /* fallthrough */

        default:
            bgm_exe.kind = 1;
            break;
        }

        break;

    case 6:
        switch (bgm_exe.rno) {
        case 0:
            bgm_fade.in.dex.hi = bgm_vol_mix;
            bgm_fade.in.dex.low = -0x8000;
            bgm_fade.speed = bgm_fade.in.cal / bgm_exe.data;

            if ((bgm_table[sys_w.bgm_type][bgm_exe.code].data & 0x4000) && (bgm_separate_check() != 0)) {
                if ((bgm_exe.nowSeamless == 0) || (bgm_exe.code != current_bgm)) {
                    bgm_exe.exIndex = bgm_table[sys_w.bgm_type][bgm_exe.code].data & 0xFF;
                    bgm_exe.exEntry = bgm_exdata[sys_w.bgm_type][bgm_exe.exIndex].numStart;

                    if (bgm_exe.nowSeamless == 0) {
                        ADXT_Destroy(adxt);
                        adxt = ADXT_Create(2, adx_stm_work, ADX_STM_WORK_SIZE);
                    }

                    bgm_play_request(bgm_exe.exEntry, 0);

                    if (bgm_exe.nowSeamless == 0) {
                        bgm_exe.nowSeamless = 1;
                        ADXT_StartSeamless(adxt);
                    }
                }
            } else {
                bgm_seamless_clear();

                if (adx_NowOnMemoryType == sys_w.bgm_type) {
                    switch (bgm_exe.code) {
                    case 0x33:
                        ADXT_StartMem(adxt, adx_VS);
                        break;

                    case 0x39:
                        ADXT_StartMem(adxt, adx_EmSel);
                        break;

                    default:
                        bgm_play_request(bgm_exe.code, 1);
                        break;
                    }
                } else {
                    bgm_play_request(bgm_exe.code, 1);
                }
            }

            if (ADXT_GetStatPause(adxt) != 0) {
                ADXT_Pause(adxt, 0);
            }

            bgm_volume_setup(-0x7F);
            current_bgm = bgm_exe.code;
            bgm_exe.rno = 1;
            bgm_fade.in.dex.hi = -bgm_vol_mix;
            bgm_fade.in.dex.low = -0x8000;
            /* fallthrough */

        case 1:
            if (adx_now_playing() != 0) {
                bgm_exe.rno = 2;
                bgm_exe.volume = 0;
            } else {
                break;
            }

            /* fallthrough */

        case 2:
            bgm_fade.in.cal += bgm_fade.speed;
            bgm_volume_setup(bgm_fade.in.dex.hi);

            if (bgm_vol_now < bgm_vol_mix) {
                break;
            }

            /* fallthrough */

        default:
            bgm_exe.kind = 0;
            break;
        }

        break;

    case 7:
        bgm_vol_mix = bgm_level * bgm_table[sys_w.bgm_type][current_bgm].vol / 15;
        bgm_volume_setup(bgm_exe.data);
        bgm_exe.kind = 0;
        break;

    case 8:
        bgm_exe.kind = 0;
        break;
    }

    if (bgm_exe.nowSeamless && (ADXT_GetNumFiles(adxt) <= 0)) {
        bgm_exe.exEntry += 1;

        if (bgm_exe.exEntry > bgm_exdata[sys_w.bgm_type][bgm_exe.exIndex].numEnd) {
            bgm_exe.exEntry = bgm_exdata[sys_w.bgm_type][bgm_exe.exIndex].numLoop;
        }

        bgm_play_request(bgm_exe.exEntry, 0);
    }
}

/* Xbox: no SPU sound banks; the PS2 bank headers (PHD_*) are not in the
   image, and nothing reads this table. */
s8* csePHDDataTable[21] = { 0 };

/* Xbox: the BGM tables have the Xbox AFS file numbers and stem ranges,
 * taken from the XBE. */
BGMTableEntry bgm_tableDC[68] = {
    { 0, 0, 0 }, { 16384, 58, 568 }, { 16385, 64, 584 }, { 16386, 64, 594 }, { 16387, 60, 612 }, { 16388, 60, 638 },
    { 16389, 60, 649 }, { 16390, 72, 677 }, { 16391, 72, 691 }, { 16392, 72, 712 }, { 16393, 74, 724 },
    { 16394, 76, 738 }, { 16395, 74, 754 }, { 16396, 80, 772 }, { 16397, 72, 786 }, { 16398, 76, 804 },
    { 16399, 72, 818 }, { 16400, 72, 829 }, { 16401, 72, 840 }, { 16402, 72, 853 }, { 16403, 72, 867 },
    { 16404, 72, 881 }, { 16405, 64, 900 }, { 16406, 64, 914 }, { 16407, 64, 928 }, { 16408, 64, 942 },
    { 16409, 64, 959 }, { 16410, 64, 973 }, { 16411, 78, 990 }, { 16412, 74, 1008 }, { 16413, 74, 1022 },
    { 16414, 78, 1040 }, { 16415, 76, 1060 }, { 16416, 76, 1071 }, { 16417, 78, 1089 }, { 16418, 78, 1106 },
    { 16419, 78, 1120 }, { 16420, 68, 1136 }, { 16421, 68, 1150 }, { 16422, 68, 1164 }, { 16423, 72, 1182 },
    { 16424, 72, 1200 }, { 16425, 72, 1219 }, { 16426, 56, 1237 }, { 16427, 56, 1251 }, { 16428, 56, 1265 },
    { 16429, 64, 1284 }, { 16430, 64, 1302 }, { 16431, 64, 1321 }, { 0, 72, 1340 }, { 0, 72, 1341 },
    { 0, 72, 1342 }, { 0, 84, 1343 }, { 0, 86, 1344 }, { 0, 56, 1345 }, { 0, 76, 1346 }, { 0, 72, 1347 },
    { 0, 72, 1348 }, { 0, 64, 1349 }, { 0, 72, 1350 }, { 0, 56, 1351 }, { 0, 60, 1352 }, { 0, 60, 1353 },
    { 0, 72, 1354 }, { 0, 72, 1355 }, { 0, 48, 1356 }, { 0, 64, 1357 }, { 0, 112, 1358 }
};

BGMExecutionData bgm_exdataDC[48] = {
    { 569, 583, 570, 0 }, { 585, 593, 586, 0 }, { 595, 611, 596, 0 }, { 613, 637, 614, 0 }, { 639, 648, 641, 0 },
    { 650, 676, 653, 0 }, { 678, 690, 683, 0 }, { 692, 711, 696, 0 }, { 713, 723, 716, 0 }, { 725, 737, 726, 0 },
    { 739, 753, 742, 0 }, { 755, 771, 760, 0 }, { 773, 785, 774, 0 }, { 787, 803, 788, 0 }, { 805, 817, 806, 0 },
    { 819, 828, 820, 0 }, { 830, 839, 831, 0 }, { 841, 852, 842, 0 }, { 854, 866, 855, 0 }, { 868, 880, 869, 0 },
    { 882, 899, 884, 0 }, { 901, 913, 902, 0 }, { 915, 927, 916, 0 }, { 929, 941, 930, 0 }, { 943, 958, 947, 0 },
    { 960, 972, 961, 0 }, { 974, 989, 978, 0 }, { 991, 1007, 996, 0 }, { 1009, 1021, 1010, 0 },
    { 1023, 1039, 1024, 0 }, { 1041, 1059, 1044, 0 }, { 1061, 1070, 1063, 0 }, { 1072, 1088, 1073, 0 },
    { 1090, 1105, 1092, 0 }, { 1107, 1119, 1108, 0 }, { 1121, 1135, 1122, 0 }, { 1137, 1149, 1138, 0 },
    { 1151, 1163, 1152, 0 }, { 1165, 1181, 1166, 0 }, { 1183, 1199, 1184, 0 }, { 1201, 1218, 1203, 0 },
    { 1220, 1236, 1221, 0 }, { 1238, 1250, 1239, 0 }, { 1252, 1264, 1253, 0 }, { 1266, 1283, 1268, 0 },
    { 1285, 1301, 1286, 0 }, { 1303, 1320, 1305, 0 }, { 1322, 1339, 1324, 0 }
};

BGMTableEntry bgm_tableAC[68] = {
    { 0, 0, 0 }, { 16384, 104, 87 }, { 16385, 104, 103 }, { 32768, 0, 0 }, { 16386, 104, 115 }, { 16387, 104, 129 },
    { 32768, 0, 0 }, { 16388, 104, 140 }, { 16389, 104, 155 }, { 32768, 0, 0 }, { 16390, 104, 178 },
    { 16391, 104, 192 }, { 32768, 0, 0 }, { 16392, 104, 208 }, { 16393, 104, 223 }, { 32768, 0, 0 },
    { 16394, 104, 242 }, { 16395, 104, 253 }, { 32768, 0, 0 }, { 16396, 104, 264 }, { 16397, 104, 278 },
    { 32768, 0, 0 }, { 16398, 104, 292 }, { 16399, 104, 306 }, { 32768, 0, 0 }, { 16400, 104, 321 },
    { 16401, 104, 338 }, { 32768, 0, 0 }, { 16402, 104, 352 }, { 16403, 104, 370 }, { 32768, 0, 0 },
    { 16404, 104, 385 }, { 16405, 104, 405 }, { 32768, 0, 0 }, { 16406, 104, 415 }, { 16407, 104, 432 },
    { 32768, 0, 0 }, { 16408, 104, 447 }, { 16409, 104, 461 }, { 32768, 0, 0 }, { 16410, 104, 477 },
    { 16411, 104, 495 }, { 32768, 0, 0 }, { 16412, 104, 513 }, { 16413, 104, 521 }, { 32768, 0, 0 },
    { 16414, 104, 530 }, { 16415, 104, 540 }, { 32768, 0, 0 }, { 0, 104, 551 }, { 0, 104, 552 }, { 0, 104, 553 },
    { 0, 104, 554 }, { 0, 104, 555 }, { 0, 104, 556 }, { 0, 104, 557 }, { 0, 104, 558 }, { 0, 104, 559 },
    { 0, 104, 560 }, { 0, 104, 561 }, { 0, 104, 562 }, { 0, 104, 563 }, { 0, 104, 564 }, { 0, 104, 565 },
    { 0, 72, 1355 }, { 0, 48, 1356 }, { 0, 104, 566 }, { 0, 104, 567 }
};

BGMExecutionData bgm_exdataAC[32] = {
    { 88, 102, 89, 0 }, { 104, 114, 107, 0 }, { 116, 128, 117, 0 }, { 130, 139, 132, 0 }, { 141, 154, 147, 0 },
    { 156, 177, 162, 0 }, { 179, 191, 180, 0 }, { 193, 207, 196, 0 }, { 209, 222, 211, 0 }, { 224, 241, 226, 0 },
    { 243, 252, 245, 0 }, { 254, 263, 256, 0 }, { 265, 277, 266, 0 }, { 279, 291, 280, 0 }, { 293, 305, 294, 0 },
    { 307, 320, 309, 0 }, { 322, 337, 326, 0 }, { 339, 351, 340, 0 }, { 353, 369, 358, 0 }, { 371, 384, 373, 0 },
    { 386, 404, 389, 0 }, { 406, 414, 407, 0 }, { 416, 431, 418, 0 }, { 433, 446, 435, 0 }, { 448, 460, 449, 0 },
    { 462, 476, 465, 0 }, { 478, 494, 479, 0 }, { 496, 512, 497, 0 }, { 514, 520, 515, 0 }, { 522, 529, 524, 0 },
    { 531, 539, 532, 0 }, { 541, 550, 543, 0 }
};
