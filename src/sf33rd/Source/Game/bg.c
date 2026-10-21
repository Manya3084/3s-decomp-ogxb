/* bg.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * Bg_TexInit 0xAE547 size 0x63. FLAG: x86-only offsets -0x4.
 * Bg_Kakikae_Set 0xAE5AA size 0x231. FLAG: x86-only offsets
 * -0xe,-0xa,-0x6,-0x2,0x2,0x4.
 * Ed_Kakikae_Set 0xAE7DB size 0x11A. FLAG: x86-only offsets -0x4,0x4,0x6.
 * Bg_Close 0xAE8F5 size 0x7F.
 * Bg_Texture_Load_Ending 0xAE974 size 0x321. FLAG: x86-only constants
 * 0x84,0xf8; x86-only offsets 0x64.
 * bgRWWorkUpdate 0xAEC95 size 0x4E. FLAG: x86-only constants 0x14; x86-only
 * offsets 0x4,0x8,0xc.
 * bgAkebonoDraw 0xAECE3 size 0xD5.
 * ppgCalScrPosition 0xAEDB8 size 0x142.
 * scr_trans_sub2 0xAEEFA size 0x18C. FLAG: x86-only offsets 0x200.
 * scr_calc 0xAF086 size 0xE0.
 * scr_calc2 0xAF166 size 0xE0.
 * Pause_Family_On 0xAF246 size 0x74.
 * Zoomf_Init 0xAF2BA size 0x37.
 * Zoom_Value_Set 0xAF2F1 size 0x75.
 * Frame_Adgjust 0xAF366 size 0x96.
 * Scrn_Pos_Init 0xAF3FC size 0x40. FLAG: x86-only offsets -0x4,-0x2,0x4,0x8.
 * Scrn_Move_Set 0xAF43C size 0x23.
 * Family_Init 0xAF45F size 0x1C. FLAG: x86-only offsets -0x8,-0x4,0x4.
 * Scrn_Renew 0xAF4DC size 0xD.
 * Irl_Family 0xAF4E9 size 0x37. FLAG: x86-only offsets -0x4,0x4,0x8.
 * Irl_Scrn 0xAF520 size 0x69.
 * Family_Move 0xAF589 size 0x38.
 * Ending_Family_Move 0xAF5C1 size 0x40.
 * Bg_Disp_Switch 0xAF601 size 0xA.
 * Bg_Texture_Load_EX 0xAF60B size 0x305. FLAG: x86-only constants 0xf8.
 * Bg_Texture_Load2 0xAF910 size 0x14B.
 * bgDrawOneChip 0xAFA5B size 0x88.
 * Frame_Up 0xAFAE3 size 0x43.
 * Frame_Down 0xAFB26 size 0x43.
 * bgDrawOneScreen 0xAFB69 size 0xEE. FLAG: x86-only constants -8,0x14;
 * x86-only offsets -0xe.
 * scr_trans 0xAFC57 size 0xC25. FLAG: x86-only constants 0x380; x86-only
 * offsets 0x4,0x8,0xc.
 * Family_Set_W is folded into 0xAF47B with 1 other bodies. Unnamed.
 * Family_Set_R is folded into 0xAF47B with 1 other bodies. Unnamed.
 * Bg_On_W is folded into 0xAF4AA with 1 other bodies. Unnamed.
 * Bg_On_R is folded into 0xAF4AA with 1 other bodies. Unnamed.
 * Bg_Off_W is folded into 0xAF4C2 with 1 other bodies. Unnamed.
 * Bg_Off_R is folded into 0xAF4C2 with 1 other bodies. Unnamed.
 * Bg_On_R is folded into 0xAF4AA.
 * mmDebWriteTag is folded into 0x4384A.
 * Data: scrDrawPos 0x7BCB40.
 * Data: bgpoly 0x7BCBE0.
 * Data: bg_priority 0x7BC990.
 * Data: Screen_Switch 0x7BC988.
 * Data: Screen_Switch_Buffer 0x7BC98A.
 * Data: rw_num 0x7BCC45.
 * Data: rw_bg_flag 0x7BC984.
 * Data: tokusyu_stage 0x7BCC44.
 * Data: rw_gbix 0x7BCBA0.
 * Data: stage_flash 0x7BC995.
 * Data: stage_ftimer 0x7BC994.
 * Data: yang_ix_plus 0x7BC948.
 * Data: yang_ix 0x7BC980.
 * Data: yang_timer 0x7BC98C.
 * Data: ending_flag 0x7BC981.
 * Data: end_prm 0x7BC960.
 * Data: gouki_end_gbix 0x7BCC50.
 * Data: rw3col_ptr 0x7BCC40.
 * Data: bg_disp_off 0x7BC982.
 * Data: bgPalCodeOffset 0x7BCC60.
 * Data: bg_w 0x7BC520.
 * Data: rw_dat 0x7BC9A0.
 * TARGET_PS2 block in Bg_Kakikae_Set: kept the PS2 side of a TARGET_PS2 block.
 * TARGET_PS2 block in Bg_Kakikae_Set: kept the PS2 side of a TARGET_PS2 block.
 * TARGET_PS2 block in Bg_Kakikae_Set: kept the PS2 side of a TARGET_PS2 block.
 * TARGET_PS2 block in Bg_Kakikae_Set: kept the PS2 side of a TARGET_PS2 block.
 * Unnamed data used (not checked): Bg_Texture_Load_Ending:
 * 0x273ef0,0x2868f0,0x286918,0x288a30,0x288a34,0x288c24; bgAkebonoDraw:
 * 0x2190ac,0x2197dc,0x2497e4,0x2498f4; ppgCalScrPosition: 0x2197dc;
 * scr_trans_sub2: 0x2190ac; scr_calc: 0x2190d4,0x2497e4; scr_calc2:
 * 0x2190d4,0x2497e4; Pause_Family_On: 0x2190d4,0x2497e4; Zoomf_Init: 0x2190ac;
 * Zoom_Value_Set: 0x2190ac,0x2193f0; Bg_Texture_Load2: 0x273f08,0x273f38;
 * bgDrawOneChip: 0x2497e4,0x2497e8; Frame_Up: 0x2193f0; Frame_Down: 0x273f44;
 * scr_trans:
 * 0x2190ac,0x2190d4,0x2497e4,0x273f48,0x273f4c,0x273f50,0x273f54,0x273f58.
 * Globals: use_real_scr 0x273F78, use_family 0x273F90, rewrite_scr 0x273FA8,
 * stage_bgw_number 0x273FC8, bgtex_stage_gbix 0x2757C8, bgtex_etc_gbix
 * 0x2758D0, stage_priority 0x2758F0, etc_bg_priority 0x275948, bgrw_on
 * 0x275980, rw30 0x275C08, rw30col 0x275CEC, rw31 0x275D10, rw31col 0x275D84,
 * rw190 0x275D94, rw191 0x275DC8, rw192 0x275DE0, bgrw_data_tbl 0x275DF8,
 * stage03rw_data_tbl 0x275EE8, stage03_flash_tbl 0x275F1C, stage19rw_data_tbl
 * 0x275F2C, stage19_loop_tbl1 0x275F3C, stage19_loop_tbl2 0x275F4C,
 * end_use_real_scr 0x2868DC, ending_use_family 0x288C10, edrw_num 0x288C38,
 * edrw_data_tbl 0x2891E0, gedrw_data_tbl 0x2893C0, cedrw_data_tbl 0x289460,
 * gouki_end_nosekae 0x2894E0, bg_map_tbl 0x3305A8, bg_map_tbl2 0x3306B0,
 * etcBgPalCnvTable 0x3306CC, etcBgGixCnvTable 0x3306E8, ending_map_tbl
 * 0x332E30, BgMATRIX 0x795D00, ppgRwBgTex 0x7A7D00, ppgAkeTex 0x7A7D20,
 * ppgAkePal 0x7A7E00, ppgAkanePal 0x7A7E20, ppgRwBgList 0x7A7E38, ppgBgList
 * 0x7A7E60, ppgBgTex 0x7A7F60, ppgAkaneTex 0x7A8000, ppgAkaneList 0x7A8058,
 * ppgAkeList 0x7A8060, judge_flag 0x7A8803, Game_pause 0x7A89B0, end_w
 * 0x7AABF0, g_kakikae 0x7BC4A2, zoom_add 0x7BC4A6, c_kakikae 0x7BC4AB,
 * scrn_adgjust_y 0x7BC4EA, g_number 0x7BC4EE, scr_bcm 0x7BC500, c_number
 * 0x7BC514, nosekae 0x7BC51C, scrn_adgjust_x 0x7BC51E, bg_w 0x7BC520,
 * yang_ix_plus 0x7BC948, end_prm 0x7BC960, yang_ix 0x7BC980, ending_flag
 * 0x7BC981, bg_disp_off 0x7BC982, rw_bg_flag 0x7BC984, Screen_Switch 0x7BC988,
 * Screen_Switch_Buffer 0x7BC98A, yang_timer 0x7BC98C, bg_priority 0x7BC990,
 * stage_ftimer 0x7BC994, stage_flash 0x7BC995, rw_dat 0x7BC9A0, scrDrawPos
 * 0x7BCB40, rw_gbix 0x7BCBA0, bgpoly 0x7BCBE0, rw3col_ptr 0x7BCC40,
 * tokusyu_stage 0x7BCC44, rw_num 0x7BCC45, gouki_end_gbix 0x7BCC50,
 * bgPalCodeOffset 0x7BCC60, No_Trans 0x7BD3C9, sca_x 0x7C55F0, scr_sc
 * 0x7C55F4, fm_pos 0x7C5620, sca_y 0x7C584C, Frame_Zoom_Y 0x7C5854, bg_prm
 * 0x7C5960, Frame_Zoom_X 0x7C5B94, bg_pos 0x7C5BA0, EXE_flag 0xC7C834,
 * PrioBase 0xC7E560.
 */

#include "structs.h"

#define NULL 0

void sub_0004384A(s8* );
extern PPGDataList ppgBgList[4];
extern Texture ppgBgTex[4];
Palette* palGetChunkGhostCP3();
extern PPGDataList ppgRwBgList;
extern Texture ppgRwBgTex;
extern PPGDataList ppgAkeList;
extern Texture ppgAkeTex;
extern Palette ppgAkePal;
extern PPGDataList ppgAkaneList;
extern Texture ppgAkaneTex;
extern Palette ppgAkanePal;
extern const s16 rw30[113];
extern const s32 stage03rw_data_tbl[13];
extern const u32 rw30col[8];
extern const s8 bgrw_on[22][8];
extern const uintptr_t bgrw_data_tbl[20][3];
extern const s16 rw190[26];
extern const s32 stage19rw_data_tbl[4];
extern const uintptr_t gedrw_data_tbl[][2];
extern const uintptr_t cedrw_data_tbl[][2];
extern const s8 edrw_num[20][2];
extern const uintptr_t edrw_data_tbl[][3];
s32 ppgReleaseTextureHandle(Texture* tch, s32 ixNum);
s32 ppgReleasePaletteHandle(Palette* pch, s32 ixNum);
extern const u8 stage_bgw_number[22][3];
extern const u8 use_real_scr[22];
extern const u16* scr_bcm[4];
extern const u16* bg_map_tbl[][3];
void Bg_On_R(u16 s_prm);
s16 Search_ramcnt_type(u8 kokey);
uintptr_t Get_ramcnt_address(s16 key);
size_t Get_size_data_ramcnt_key(s16 key);
extern const u32 stage_priority[22];
extern const u32 bgtex_stage_gbix[22][3];
void ppgSetupCurrentDataList(PPGDataList* dlist);
s32 ppgSetupTexChunk_1st(Texture* tch, u8* adrs, ssize_t size, s32 ixNum1st, s32 ixNums, s32 ar, s32 arcnt);
s32 ppgSetupTexChunk_1st_Accnum(Texture* tch, u16 accnum);
s32 ppgSetupTexChunk_2nd(Texture* tch, s32 ixNum);
s32 ppgSetupTexChunk_3rd(Texture* tch, s32 ixNum, u32 attribute);
extern const u8 rewrite_scr[22];
s32 ppgSetupPalChunk(Palette* pch, u8* adrs, s32 size, s32 ixNum1st, s32 num, s32 );
void ppgSourceDataReleased(PPGDataList* dlist);
extern const u16* bg_map_tbl2[];
s32 flLogOut(s8* format, ...);
extern const u32 bgtex_etc_gbix[7];
extern const u32 etc_bg_priority[7];
extern u8 etcBgGixCnvTable[7][16];
extern s32 etcBgPalCnvTable[7];
extern const u8 end_use_real_scr[];
extern const u16* ending_map_tbl[][3];
s32 load_it_use_any_key2(u16 fnum, void** adrs, s16* key, u8 kokey, u8 group);
extern const u16 bgtex_ending_file[];
extern const u32 ending_priority[];
extern const u32 bgtex_ending_gbix[][6];
extern const u8 ending_rewrite_scr[];
void Push_ramcnt_key(s16 key);
void setFilterMode(s32 mode);
void njUnitMatrix(MTX* mtx);
void njScale(MTX* mtx, f32 x, f32 y, f32 z);
void njTranslate(MTX* mtx, f32 x, f32 y, f32 z);
extern BackgroundParameters bg_prm[8];
extern f32 scr_sc;
extern f32 Frame_Zoom_X;
extern f32 Frame_Zoom_Y;
void njCalcPoints(MTX* mtx, Vec3* ps, Vec3* pd, s32 num);
void njGetMatrix(MTX* m);
extern MTX BgMATRIX[9];
extern f32 PrioBase[128];
void bgAkebonoDraw(void);
s32 ppgCheckTextureNumber(Texture* tex, s32 num);
void bgDrawOneChip(s32 x, s32 y, s32 xs, s32 ys, s32 gbix, u32 vtxCol, s32 ofsPal);
extern s16 EXE_flag;
extern u8 Game_pause;
s32 random_16_bg();
extern const u8 stage03_flash_tbl[16];
extern const s16 rw31[57];
extern const u32 rw31col[4];
extern s8 judge_flag;
extern const s16 rw191[11];
extern const u8 stage19_loop_tbl2[16];
extern const s16 rw192[11];
extern const u8 stage19_loop_tbl1[16];
void bgDrawOneScreen(s32 bgnum, s32 gixbase, s32* xx, s32* yy, s32 ofsPal, PPGDataList* curDataList);
void bgRWWorkUpdate(void);
void scr_calc2(u8 bgnm);
extern u8 nosekae;
extern const s32 gouki_end_nosekae[2][16];
extern u8 g_kakikae[2];
extern u8 g_number[2];
extern u8 c_kakikae;
extern u8 c_number;
extern BG_POS bg_pos[8];
void scr_trans_sub2(s32 x, s32 y, s32 suzi);
extern u8 No_Trans;
void ppgSetupCurrentPaletteNumber(Palette* pal, s32 num);
void njDrawTexture(Polygon* polygon, s32 , s32 tex, s32 );
void ppgCalScrPosition(s32 x, s32 y, s32 xs, s32 ys);
s32 ppgWriteQuadUseTrans(Vertex* pos, u32 col, PPGDataList* tb, s32 tix, s32 cix, s32 flip, s32 pal);
extern u16 zoom_add;
extern s32 sca_x;
extern s32 sca_y;
extern s16 scrn_adgjust_x;
extern s16 scrn_adgjust_y;
void Frame_Adgjust(u16 pos_x, u16 pos_y);
extern BG_POS fm_pos[8];
extern const u8 use_family[22];
extern const u8 ending_use_family[];
extern END_W end_w;

extern Vertex scrDrawPos[4];

extern Polygon bgpoly[4];

extern u8 bg_priority[4];

extern u16 Screen_Switch;

extern u16 Screen_Switch_Buffer;

extern u8 rw_num;

extern u8 rw_bg_flag[4];

extern u8 tokusyu_stage;

extern s32 rw_gbix[13];

extern s8 stage_flash;

extern s8 stage_ftimer;

extern s32 yang_ix_plus;

extern s8 yang_ix;

extern s8 yang_timer;

extern u8 ending_flag;

extern BackgroundParameters end_prm[8];

extern u8 gouki_end_gbix[16];

extern const u32* rw3col_ptr;

extern u8 bg_disp_off;

extern s32 bgPalCodeOffset[8];

extern BG bg_w;

extern RW_DATA rw_dat[20];

void Bg_TexInit() {
    s32 i;

    for (i = 0; i < 3; i++) {
        ppgBgList[i].tex = &ppgBgTex[i];
        ppgBgList[i].pal = palGetChunkGhostCP3();
    }

    ppgRwBgList.tex = &ppgRwBgTex;
    ppgRwBgList.pal = palGetChunkGhostCP3();
    ppgAkeList.tex = &ppgAkeTex;
    ppgAkeList.pal = &ppgAkePal;
    ppgAkaneList.tex = &ppgAkaneTex;
    ppgAkaneList.pal = &ppgAkanePal;
}

void Bg_Kakikae_Set() {
    u8 i;
    const uintptr_t* rwtbl_ptr;
    s8 rw;

    switch (bg_w.stage) {
    case 3:
        tokusyu_stage = 1;
        stage_flash = 0;
        stage_ftimer = 0;
        rw_dat->rwd_ptr = rw_dat->brw_ptr = (s16*)rw30;
        rw_dat->rw_cnt = 2;

        for (i = 0; i < 13; i++) {
            rw_gbix[i] = stage03rw_data_tbl[i];
        }

        rw3col_ptr = (u32*)rw30col;

        for (i = 0; i < 4; i++) {
            rw = bgrw_on[bg_w.stage][i];

            rwtbl_ptr = bgrw_data_tbl[rw];
            rw_dat[i + 1].bg_num = *rwtbl_ptr++;
            rw_dat[i + 1].rwgbix = *rwtbl_ptr++;
            rw_dat[i + 1].rwd_ptr = rw_dat[i + 1].brw_ptr = (s16*)rwtbl_ptr[0];

            rw_dat[i + 1].rw_cnt = *rw_dat[i + 1].rwd_ptr++;
            rw_dat[i + 1].gbix = *rw_dat[i + 1].rwd_ptr++;
        }
        break;

    case 10:
        tokusyu_stage = 2;
        yang_ix = 0;
        yang_ix_plus = 0;
        yang_timer = 4;
        break;

    case 19:
        tokusyu_stage = 3;
        stage_flash = 0;
        stage_ftimer = 2;
        rw_dat->rwd_ptr = rw_dat->brw_ptr = (s16*)rw190;
        rw_dat->rw_cnt = 2;

        for (i = 0; i < 4; i++) {
            rw_gbix[i] = stage19rw_data_tbl[i];
        }

        rw = bgrw_on[bg_w.stage][0];

        rwtbl_ptr = bgrw_data_tbl[rw];
        rw_dat[1].bg_num = *rwtbl_ptr++;
        rw_dat[1].rwgbix = *rwtbl_ptr++;
        rw_dat[1].rwd_ptr = rw_dat[1].brw_ptr = (s16*)rwtbl_ptr[0];

        rw_dat[1].rw_cnt = *rw_dat[1].rwd_ptr++;
        rw_dat[1].gbix = *rw_dat[1].rwd_ptr++;
        break;

    default:
        if (bg_w.stage == 7) {
            tokusyu_stage = 4;
        } else {
            tokusyu_stage = 0;
        }

        rw_num = 0;

        for (i = 0; i < 4; i++) {
            rw_bg_flag[i] = 0;
        }

        for (i = 0; i < 8; i++) {
            rw = bgrw_on[bg_w.stage][i];

            if (rw == -1) {
                break;
            }

            rw_num += 1;

            rwtbl_ptr = bgrw_data_tbl[rw];
            rw_dat[i].bg_num = *rwtbl_ptr++;
            rw_bg_flag[rw_dat[i].bg_num] = 1;
            rw_dat[i].rwgbix = *rwtbl_ptr++;
            rw_dat[i].rwd_ptr = rw_dat[i].brw_ptr = (s16*)rwtbl_ptr[0];

            rw_dat[i].rw_cnt = *rw_dat[i].rwd_ptr++;
            rw_dat[i].gbix = *rw_dat[i].rwd_ptr++;
        }

        break;
    }
}

void Ed_Kakikae_Set(s16 type) {
    u8 i;
    const uintptr_t* rwtbl_ptr;
    s8 rw;

    rw_num = 0;

    for (i = 0; i < 4; i++) {
        rw_bg_flag[i] = 0;
    }

    switch (type) {
    case 14:
        for (i = 0; i < 20; i++) {
            rwtbl_ptr = &gedrw_data_tbl[i][0];
            rw_dat[i].rwgbix = *rwtbl_ptr++;
            rw_dat[i].rwd_ptr = rw_dat[i].brw_ptr = (s16*)rwtbl_ptr[0];
        }

        break;

    case 15:
        for (i = 0; i < 16; i++) {
            rwtbl_ptr = &cedrw_data_tbl[i][0];
            rw_dat[i].rwgbix = *rwtbl_ptr++;
            rw_dat[i].rwd_ptr = rw_dat[i].brw_ptr = (s16*)rwtbl_ptr[0];
        }

        break;

    default:
        if (edrw_num[type][0] != -1) {
            rw = edrw_num[type][0];

            for (i = 0; i < edrw_num[type][1]; i++) {
                rw_num += 1;
                rwtbl_ptr = &edrw_data_tbl[rw + i][0];
                rw_dat[i].bg_num = *rwtbl_ptr++;
                rw_bg_flag[rw_dat[i].bg_num] = 1;
                rw_dat[i].rwgbix = *rwtbl_ptr++;
                rw_dat[i].rwd_ptr = rw_dat[i].brw_ptr = (s16*)rwtbl_ptr[0];
                rw_dat[i].rw_cnt = *rw_dat[i].rwd_ptr++;
                rw_dat[i].gbix = *rw_dat[i].rwd_ptr++;
            }
        }

        break;
    }
}

void Bg_Close() {
    u32 i;

    tokusyu_stage = 0;
    rw_num = 0;

    for (i = 0; i < 3; i++) {
        ppgReleaseTextureHandle(&ppgBgTex[i], -1);
    }

    ppgReleaseTextureHandle(&ppgRwBgTex, -1);
    ppgReleaseTextureHandle(&ppgAkeTex, -1);
    ppgReleasePaletteHandle(&ppgAkePal, -1);
    ppgReleaseTextureHandle(&ppgAkaneTex, -1);
    ppgReleasePaletteHandle(&ppgAkanePal, -1);
    Screen_Switch = 0;
    Screen_Switch_Buffer = 0;
    bg_disp_off = 0;
}

void Bg_Texture_Load_EX() {
    void* loadAdrs;
    u32 loadSize;
    u32 tgbix;
    u32 prio;
    u32 mask;
    u32 pmask;
    s16 key1;
    u16 accnum;
    u8 i;
    u8 j;
    u8 x;
    u8 shift;
    u8 stg;
    u8* akeAdrs;
    s32 akeSize;
    s16 akeKey;

    u32 assign1;
    u32 assign2;
    u8 assign3;

    sub_0004384A("\nSTAGE\n\n");
    Bg_TexInit();

    for (i = 0; i < 8; i++) {
        bgPalCodeOffset[i] = 0x12C;
    }

    ending_flag = 0;

    for (stg = 0; stg < 3; stg++) {
        if (stage_bgw_number[bg_w.stage][stg] != 0) {
            break;
        }
    }

    for (i = 0; i < use_real_scr[bg_w.stage]; i++) {
        scr_bcm[stg + i] = bg_map_tbl[bg_w.stage][i];
    }

    for (i = 0; i < 3; i++) {
        if (stage_bgw_number[bg_w.stage][i] > 0) {
            Bg_On_R(1 << i);
        }
    }

    if (bg_w.stage == 7) {
        Bg_On_R(4);
    }

    key1 = Search_ramcnt_type(0x12);
    loadAdrs = (void*)Get_ramcnt_address(key1);
    loadSize = Get_size_data_ramcnt_key(key1);
    pmask = 0xFF000000;
    shift = 0x18;

    for (j = 0; j < 3; j++, shift -= 8, assign1 = pmask >>= 8) {
        prio = stage_priority[bg_w.stage];
        prio &= pmask;
        prio >>= shift;
        bg_priority[j] = prio;
    }

    bg_priority[3] = 70;
    accnum = 0;

    for (j = 0; j < bg_w.scrno; j++, assign3 = stg++) {
        tgbix = bgtex_stage_gbix[bg_w.stage][j];
        mask = 0x80000000;
        ppgSetupCurrentDataList(&ppgBgList[stg]);
        ppgSetupTexChunk_1st(NULL, loadAdrs, loadSize, (stg * 64) + 0x84, 32, 0, 0);
        ppgSetupTexChunk_1st_Accnum(0, accnum);

        for (i = 0; i < 32; i++, assign2 = mask >>= 1) {
            if (tgbix & mask) {
                accnum = ppgSetupTexChunk_2nd(NULL, i + ((stg * 64) + 0x84));
                ppgSetupTexChunk_3rd(NULL, i + ((stg * 64) + 0x84), 1);
            }
        }
    }

    x = rewrite_scr[bg_w.stage];

    if (x) {
        ppgSetupCurrentDataList(&ppgRwBgList);
        ppgSetupTexChunk_1st(NULL, loadAdrs, loadSize, (stg * 64) + 0x64, x, 0, 0);
        ppgSetupTexChunk_1st_Accnum(0, accnum);

        for (i = 0; i < x; i++) {
            accnum = ppgSetupTexChunk_2nd(NULL, i + ((stg * 64) + 0x64));
            ppgSetupTexChunk_3rd(NULL, i + ((stg * 64) + 0x64), 1);
        }
    }

    if (bg_w.stage == 7) {
        ppgSetupCurrentDataList(&ppgAkaneList);
        ppgSetupPalChunk(NULL, loadAdrs, loadSize, 0, 0, 1);
        ppgSetupTexChunk_1st(NULL, loadAdrs, loadSize, 0, 3, 0, 0);
        ppgSetupTexChunk_1st_Accnum(0, accnum);

        for (i = 0; i < 3; i++) {
            accnum = ppgSetupTexChunk_2nd(NULL, i);
            ppgSetupTexChunk_3rd(NULL, i, 1);
        }

        ppgSourceDataReleased(&ppgAkaneList);
    }

    if (bg_w.stage != 20 && bg_w.stage != 21) {
        akeKey = Search_ramcnt_type(0x1F);
        akeSize = Get_size_data_ramcnt_key(akeKey);
        akeAdrs = (u8*)Get_ramcnt_address(akeKey);
        ppgSetupCurrentDataList(&ppgAkeList);
        ppgSetupPalChunk(NULL, akeAdrs, akeSize, 0, 0, 1);
        ppgSetupTexChunk_1st(NULL, akeAdrs, akeSize, 0, 3, 0, 0);

        for (i = 0; i < 3; i++) {
            ppgSetupTexChunk_2nd(NULL, i);
            ppgSetupTexChunk_3rd(NULL, i, 1);
        }

        ppgSourceDataReleased(&ppgAkeList);
    }
}

void Bg_Texture_Load2(u8 type) {
    void* loadAdrs;
    u32 loadSize;
    s16 key;
    u32 tgbix;
    u32 prio;
    u32 mask;
    u32 pmask;
    u8 i;
    u8 j;
    u8 shift;

    u32 assign;

    sub_0004384A("\nBG ETC.\n\n");
    Bg_TexInit();
    (void)assign;
    ending_flag = 0;
    tokusyu_stage = 0;
    rw_num = 0;

    for (i = 0; i < 4; i++) {
        rw_bg_flag[i] = 0;
    }

    for (i = 0; i < bg_w.scno; i++) {
        scr_bcm[i] = bg_map_tbl2[type];
        Bg_On_R(1 << i);
    }

    ppgSetupCurrentDataList(ppgBgList);
    ppgReleaseTextureHandle(NULL, -1);
    key = Search_ramcnt_type(0x18);

    if (key == 0) {
        flLogOut("背景用テクスチャが読み込まれていませんでした。\n");
        while (!NULL) {};
    }

    loadSize = Get_size_data_ramcnt_key(key);
    loadAdrs = (void*)Get_ramcnt_address(key);
    ppgSetupTexChunk_1st(0, loadAdrs, loadSize, 0x84, 0x20, 0, 0);
    pmask = 0xFF000000;
    shift = 24;
    tgbix = bgtex_etc_gbix[type];
    mask = 0x80000000;
    prio = etc_bg_priority[type];
    prio &= pmask;
    prio >>= shift;
    bg_priority[0] = prio;

    for (j = 0, i = 0; i < 32; i++, assign = mask >>= 1) {
        if (tgbix & mask) {
            ppgBgList->tex->accnum = etcBgGixCnvTable[type][j];
            ppgSetupTexChunk_2nd(NULL, i + 0x84);
            ppgSetupTexChunk_3rd(NULL, i + 0x84, 1);
            j++;
        }
    }

    bgPalCodeOffset[0] = etcBgPalCnvTable[type] + 144;
}

void Bg_Texture_Load_Ending(s16 type) {
    void *loadAdrs;
    u32 loadSize;
    s32 accnum;
    u32 tgbix[2];
    u32 prio;
    u32 mask;
    u32 pmask;
    s16 key1;
    u8 i;
    u8 j;
    u8 k;
    u8 x;
    u8 shift;

    sub_0004384A("\nENDING\n\n");
    rw_num = 0;
    Bg_TexInit();
    ending_flag = 1;

    for (i = 0; i < end_use_real_scr[type]; i++) {
        scr_bcm[i] = ending_map_tbl[type][i];
    }

    loadSize = load_it_use_any_key2(bgtex_ending_file[type], &loadAdrs, &key1, 2, 0);
    pmask = 0xFF000000;
    shift = 0x18;

    for (j = 0; j < 4; j++) {
        prio = ending_priority[0];
        prio &= pmask;
        prio >>= shift;
        bg_priority[j] = (u8)prio;
        shift = (u8)(shift - 8);
        pmask >>= 8;
    }

    accnum = 0;

    for (j = 0; j < bg_w.scrno; j++) {
        tgbix[0] = bgtex_ending_gbix[type][j * 2];
        tgbix[1] = bgtex_ending_gbix[type][(j * 2) + 1];
        mask = 0x80000000;
        ppgSetupCurrentDataList(&ppgBgList[j]);
        ppgSetupTexChunk_1st((void *)0, loadAdrs, loadSize, (j * 64) + 100, 64, 0, 0);
        ppgSetupTexChunk_1st_Accnum((void *)0, (u16)accnum);

        for (k = 0; k < 2; k++) {
            for (i = 0; i < 32; i++) {
                if (mask & tgbix[k]) {
                    accnum = ppgSetupTexChunk_2nd((void *)0, i + ((j * 64) + 100 + (k * 32)));
                    ppgSetupTexChunk_3rd((void *)0, i + ((j * 64) + 100 + (k * 32)), 1);
                }

                mask >>= 1;
            }

            mask = 0x80000000;
        }
    }

    x = ending_rewrite_scr[type];

    if (x != 0) {
        ppgSetupCurrentDataList(&ppgRwBgList);
        ppgSetupTexChunk_1st((void *)0, loadAdrs, loadSize, (j * 64) + 100, x, 0, 0);
        ppgSetupTexChunk_1st_Accnum((void *)0, (u16)accnum);

        for (i = 0; i < x; i++) {
            accnum = ppgSetupTexChunk_2nd((void *)0, i + ((j * 64) + 100));
            ppgSetupTexChunk_3rd((void *)0, i + ((j * 64) + 100), 1);
        }
    }

    switch (type) {
    case 14:
        tokusyu_stage = 5;

        for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++) {
                gouki_end_gbix[j + (i * 4)] = (u8)(j + ((i * 8) + 100));
            }
        }

        ppgSetupCurrentDataList(&ppgAkeList);
        ppgSetupPalChunk((void *)0, loadAdrs, loadSize, 0, 0, 1);
        ppgSetupTexChunk_1st((void *)0, loadAdrs, loadSize, 0x1A0, 0x18, 0, 0);
        ppgSetupTexChunk_1st_Accnum((void *)0, (u16)accnum);

        for (i = 0; i < 0x18; i++) {
            accnum = ppgSetupTexChunk_2nd((void *)0, i + 0x1A0);
            ppgSetupTexChunk_3rd((void *)0, i + 0x1A0, 1);
        }

        break;

    case 15:
        tokusyu_stage = 6;
        break;

    case 19:
        tokusyu_stage = 7;
        ppgSetupCurrentDataList(&ppgAkeList);
        ppgSetupPalChunk((void *)0, loadAdrs, loadSize, 0, 0, 1);
        ppgSetupTexChunk_1st((void *)0, loadAdrs, loadSize, 0xE4, 1, 0, 0);
        ppgSetupTexChunk_1st_Accnum((void *)0, (u16)accnum);
        accnum = ppgSetupTexChunk_2nd((void *)0, 0xE4);
        ppgSetupTexChunk_3rd((void *)0, 0xE4, 1);
        break;

    default:
        tokusyu_stage = 7;
        break;
    }

    Push_ramcnt_key(key1);
    Ed_Kakikae_Set(type);
    ppgSourceDataReleased(&ppgBgList[0]);
    ppgSourceDataReleased(&ppgBgList[1]);
    ppgSourceDataReleased(&ppgBgList[2]);
    ppgSourceDataReleased(&ppgRwBgList);
    ppgSourceDataReleased(&ppgAkeList);
}

/* Xbox: no Debug_w[42] check, bgDrawOneScreen takes no unused fifth
   argument, and case 4 does not halve and negate suzi_pos (the retail
   x86 passes bg_pos[2] - 320 as it is). Several compares are written the
   other way round. */
void scr_trans(u8 bgnm) {
    PPGDataList* curDataList;
    Vec3 point[2];
    s32 xx[2];
    s32 yy[2];
    s32 i;
    s32 x;
    s32 y;
    s32 global_index;
    s32 global_index_real;
    s32 palOffset;
    u32 vtxColor;
    s32 suzi_pos;

    setFilterMode(0);
    njUnitMatrix(0);
    njScale(0, 1.0f, -1.0f, 1.0f);
    njTranslate(0, 0.0f, -1024.0f, 0.0f);
    njTranslate(0, (s16)bg_prm[bgnm].bg_h_shift, (s16)bg_prm[bgnm].bg_v_shift, 0.0f);
    njScale(0, 1.0f, -1.0f, 1.0f);
    njTranslate(0, 0.0f, -224.0f, 0.0f);
    njScale(0, 1.0f / scr_sc, 1.0f / scr_sc, 1.0f);
    njScale(0, 1.0f / Frame_Zoom_X, 1.0f / Frame_Zoom_Y, 1.0f);
    point[0].x = 0.0f;
    point[0].y = 0.0f;
    point[0].z = 00.f;
    point[1].x = 648.0f;
    point[1].y = 488.0f;
    point[1].z = 0.0f;
    njCalcPoints(0, &point[0], &point[0], 2);
    xx[0] = ((s32)point[0].x) & ~0x7F;
    yy[0] = ((s32)point[0].y) & ~0x7F;
    xx[1] = ((s32)point[1].x + 0x7F) & ~0x7F;
    yy[1] = ((s32)point[1].y + 0x7F) & ~0x7F;

    for (x = 0; x < 2; x++) {
        if (xx[x] < 0) {
            xx[x] = 0;
        }

        if (0x3FF < xx[x]) {
            xx[x] = 0x3FF;
        }

        if (yy[x] < 0) {
            yy[x] = 0;
        }

        if (0x3FF < yy[x]) {
            yy[x] = 0x3FF;
        }
    }

    njUnitMatrix(0);
    njScale(0, Frame_Zoom_X, Frame_Zoom_Y, 1.0);
    njScale(0, scr_sc, scr_sc, 1.0);
    njTranslate(0, 0, 224.0, 0);
    njScale(0, 1.0, -1.0, 1.0);
    njTranslate(0, (s16)-bg_prm[bgnm].bg_h_shift, (s16)-bg_prm[bgnm].bg_v_shift, 0);
    njGetMatrix(&BgMATRIX[bgnm + 1]);
    njTranslate(0, 0, 1024.0, PrioBase[bg_priority[bgnm]]);
    njScale(0, 1.0, -1.0, 1.0);

    palOffset = bgPalCodeOffset[bgnm];

    if (ending_flag == 0) {
        if (bgnm == 3) {
            ppgSetupCurrentDataList(&ppgAkeList);
            bgAkebonoDraw();
            return;
        }

        global_index = (bgnm * 64) + 100;
        ppgSetupCurrentDataList(&ppgBgList[bgnm]);
        curDataList = &ppgBgList[bgnm];
    } else {
        global_index = (bgnm * 64) + 100;
        ppgSetupCurrentDataList(&ppgBgList[bgnm]);
        curDataList = &ppgBgList[bgnm];
    }

    switch (tokusyu_stage) {
    case 1:
        for (y = yy[0]; y < yy[1]; y += 128) {
            for (x = xx[0]; x < xx[1]; x += 128) {
                global_index_real = global_index + (((y >> 7) << 3) + (x >> 7));
                vtxColor = 0xFFFFFFFF;

                if (bgnm == 0) {
                    for (i = 0; i < 4; i++) {
                        if (rw_dat[i + 1].rwgbix == global_index_real) {
                            global_index_real = rw_dat[i + 1].gbix;
                            if (ppgCheckTextureNumber(0, global_index_real) == 0) {
                                ppgSetupCurrentDataList(&ppgRwBgList);
                            }
                            break;
                        }
                    }
                } else {
                    for (i = 0; i < 13; i++) {
                        if (rw_gbix[i] == global_index_real) {
                            global_index_real = *(rw_dat[0].rwd_ptr + i + 1);
                            vtxColor = *rw3col_ptr;

                            if (ppgCheckTextureNumber(0, global_index_real) == 0) {
                                ppgSetupCurrentDataList(&ppgRwBgList);
                            }
                            break;
                        }
                    }
                }

                bgDrawOneChip(x, y, 128, 128, global_index_real, vtxColor, palOffset);
                ppgSetupCurrentDataList(curDataList);
            }
        }

        if (EXE_flag != 0 || Game_pause != 0) {
            return;
        }

        if (bgnm == 0) {
            for (i = 0; i < 4; i = i + 1) {
                rw_dat[i + 1].rw_cnt--;

                if (rw_dat[i + 1].rw_cnt == 0) {
                    if (rw_dat[i + 1].rwd_ptr[0] == -1) {
                        rw_dat[i + 1].rwd_ptr = rw_dat[i + 1].brw_ptr;
                        rw_dat[i + 1].rw_cnt = *rw_dat[i + 1].rwd_ptr++;
                        rw_dat[i + 1].gbix = *rw_dat[i + 1].rwd_ptr++;
                    } else {
                        rw_dat[i + 1].rw_cnt = *rw_dat[i + 1].rwd_ptr++;
                        rw_dat[i + 1].gbix = *rw_dat[i + 1].rwd_ptr++;
                    }
                }
            }

            break;
        }

        rw_dat[0].rw_cnt--;

        if (rw_dat[0].rw_cnt != 0) {
            break;
        }

        if (stage_flash == 0) {
            rw_dat[0].rwd_ptr += 14;
            rw3col_ptr++;
            rw_dat[0].rw_cnt = rw_dat[0].rwd_ptr[0];

            if (rw_dat[0].rw_cnt != -1) {
                break;
            }

            stage_flash = random_16_bg();
            stage_flash = stage03_flash_tbl[stage_flash];

            if (stage_flash == 0) {
                rw_dat[0].rwd_ptr = rw_dat[0].brw_ptr;
                rw_dat[0].rw_cnt = rw_dat[0].rwd_ptr[0];
                rw3col_ptr = &rw30col[0];
            } else {
                rw_dat[0].rwd_ptr = &rw31[0];
                rw_dat[0].rw_cnt = 2;
                stage_ftimer = stage_flash;
                rw3col_ptr = rw31col;
            }

            break;
        }

        rw_dat[0].rwd_ptr += 14;
        rw3col_ptr++;
        rw_dat[0].rw_cnt = rw_dat[0].rwd_ptr[0];

        if (rw_dat[0].rw_cnt != -1) {
            break;
        }

        stage_ftimer--;

        if (stage_ftimer <= 0) {
            stage_flash = 0;
            rw_dat[0].rwd_ptr = rw_dat[0].brw_ptr;
            rw_dat[0].rw_cnt = 2;
            rw3col_ptr = rw30col;
        } else {
            rw_dat[0].rwd_ptr = rw31;
            rw_dat[0].rw_cnt = 2;
            rw3col_ptr = rw31col;
        }

        break;

    case 2:
        if (judge_flag == 1 && bgnm == 1) {
            vtxColor = 0xFFA0A0A0;
        } else {
            vtxColor = 0xFFFFFFFF;
        }

        for (y = yy[0]; y < yy[1]; y += 128) {
            for (x = xx[0]; x < xx[1]; x += 128) {
                global_index_real = global_index + (((y >> 7) << 3) + (x >> 7));

                if (bgnm == 1) {
                    global_index_real += yang_ix_plus;
                }

                if (ppgCheckTextureNumber(0, global_index_real) == 0) {
                    ppgSetupCurrentDataList(&ppgRwBgList);
                }
                bgDrawOneChip(x, y, 128, 128, global_index_real, vtxColor, palOffset);
                ppgSetupCurrentDataList(curDataList);
            }
        }

        if (EXE_flag != 0 || Game_pause != 0) {
            return;
        }

        if (bgnm != 1) {
            break;
        }

        yang_timer--;

        if (yang_timer != 0) {
            break;
        }

        yang_timer = 4;
        yang_ix++;

        if (yang_ix == 4) {
            yang_ix = 0;
        }

        yang_ix_plus = yang_ix << 5;
        break;

    case 3:
        for (y = yy[0]; y < yy[1]; y += 128) {
            for (x = xx[0]; x < xx[1]; x += 128) {
                global_index_real = global_index + (((y >> 7) << 3) + (x >> 7));

                if (bgnm == 1) {
                    if (rw_dat[1].rwgbix == global_index_real) {
                        global_index_real = rw_dat[1].gbix;

                        if (!ppgCheckTextureNumber(0, global_index_real)) {
                            ppgSetupCurrentDataList(&ppgRwBgList);
                        }
                    } else {
                        for (i = 0; i < 4; i++) {
                            if (rw_gbix[i] == global_index_real) {
                                global_index_real = *(rw_dat[0].rwd_ptr + i + 1);

                                if (!ppgCheckTextureNumber(0, global_index_real)) {
                                    ppgSetupCurrentDataList(&ppgRwBgList);
                                }

                                break;
                            }
                        }
                    }
                }

                bgDrawOneChip(x, y, 128, 128, global_index_real, -1, palOffset);
                ppgSetupCurrentDataList(curDataList);
            }
        }

        if (EXE_flag != 0 || Game_pause != 0) {
            return;
        }

        if (bgnm != 1) {
            break;
        }

        rw_dat[0].rw_cnt--;

        if (rw_dat[0].rw_cnt == 0) {
            rw_dat[0].rwd_ptr += 5;
            rw_dat[0].rw_cnt = rw_dat[0].rwd_ptr[0];

            if (rw_dat[0].rw_cnt == -1) {
                stage_ftimer--;

                if (stage_ftimer == 0) {
                    stage_flash = random_16_bg();
                    stage_ftimer = random_16_bg();

                    switch (stage_flash) {
                    case 0:
                    case 1:
                        rw_dat[0].rwd_ptr = rw_dat[0].brw_ptr = rw191;
                        rw_dat[0].rw_cnt = 1;
                        stage_ftimer = stage19_loop_tbl2[stage_ftimer];
                        break;

                    case 2:
                    case 3:
                        rw_dat[0].rwd_ptr = rw_dat[0].brw_ptr = rw192;
                        rw_dat[0].rw_cnt = 1;
                        stage_ftimer = stage19_loop_tbl2[stage_ftimer];
                        break;

                    default:
                        rw_dat[0].rwd_ptr = rw_dat[0].brw_ptr = rw190;
                        rw_dat[0].rw_cnt = 2;
                        stage_ftimer = stage19_loop_tbl1[stage_ftimer];
                        break;
                    }
                } else {
                    rw_dat[0].rwd_ptr = rw_dat[0].brw_ptr;
                    rw_dat[0].rw_cnt = rw_dat[0].rwd_ptr[0];
                }
            }
        }

        rw_dat[1].rw_cnt--;

        if (rw_dat[1].rw_cnt != 0) {
            break;
        }

        if (rw_dat[1].rwd_ptr[0] == -1) {
            rw_dat[1].rwd_ptr = rw_dat[1].brw_ptr;
            rw_dat[1].rw_cnt = *rw_dat[1].rwd_ptr++;
            rw_dat[1].gbix = *rw_dat[1].rwd_ptr++;
        } else {
            rw_dat[1].rw_cnt = *rw_dat[1].rwd_ptr++;
            rw_dat[1].gbix = *rw_dat[1].rwd_ptr++;
        }

        break;

    case 7:
        bgDrawOneScreen(bgnm, global_index, &xx[0], &yy[0], palOffset, curDataList);

        if (EXE_flag != 0) {
            break;
        }

        if (Game_pause != 0) {
            break;
        }

        if (rw_bg_flag[bgnm] && rw_num) {
            bgRWWorkUpdate();
        }

        scr_calc2(bgnm);
        break;

    case 5:
        for (y = yy[0]; y < yy[1]; y += 128) {
            for (x = xx[0]; x < xx[1]; x += 128) {
                global_index_real = global_index + (((y >> 7) << 3) + (x >> 7));

                if (nosekae != 0) {
                    for (i = 0; i < 16; i++) {
                        if (gouki_end_gbix[i] == global_index_real) {
                            global_index_real = gouki_end_nosekae[nosekae - 1][i];

                            if (ppgCheckTextureNumber(0, global_index_real) == 0) {
                                if (ppgCheckTextureNumber(&ppgRwBgTex, global_index_real)) {
                                    ppgSetupCurrentDataList(&ppgRwBgList);
                                } else {
                                    ppgSetupCurrentDataList(&ppgAkeList);
                                }
                            }

                            break;
                        }
                    }
                }

                if (bgnm == 0) {
                    if (g_kakikae[0]) {
                        for (i = 0; i < 12; i++) {
                            if (rw_dat[i].rwgbix == global_index_real) {
                                global_index_real = rw_dat[i].rwd_ptr[g_number[0]];

                                if (ppgCheckTextureNumber(0, global_index_real) == 0) {
                                    if (ppgCheckTextureNumber(&ppgRwBgTex, global_index_real)) {
                                        ppgSetupCurrentDataList(&ppgRwBgList);
                                    } else {
                                        ppgSetupCurrentDataList(&ppgAkeList);
                                    }
                                }

                                break;
                            }
                        }
                    }

                    if (g_kakikae[1]) {
                        for (i = 12; i < 20; i++) {
                            if (rw_dat[i].rwgbix == global_index_real) {
                                global_index_real = rw_dat[i].rwd_ptr[g_number[1]];

                                if (!ppgCheckTextureNumber(0, global_index_real)) {
                                    if (ppgCheckTextureNumber(&ppgRwBgTex, global_index_real)) {
                                        ppgSetupCurrentDataList(&ppgRwBgList);
                                    } else {
                                        ppgSetupCurrentDataList(&ppgAkeList);
                                    }
                                }

                                break;
                            }
                        }
                    }
                }

                bgDrawOneChip(x, y, 128, 128, global_index_real, -1, palOffset);
                ppgSetupCurrentDataList(curDataList);
            }
        }

        scr_calc2(bgnm);
        break;

    case 6:
        for (y = yy[0]; y < yy[1]; y += 128) {
            for (x = xx[0]; x < xx[1]; x += 128) {
                global_index_real = global_index + (((y >> 7) << 3) + (x >> 7));

                if (bgnm == 0) {
                    switch (c_kakikae) {
                    case 1:
                        for (i = 0; i < 8; i++) {
                            if (rw_dat[i].rwgbix == global_index_real) {
                                global_index_real = rw_dat[i].rwd_ptr[c_number];

                                if (!ppgCheckTextureNumber(0, global_index_real)) {
                                    ppgSetupCurrentDataList(&ppgRwBgList);
                                }

                                break;
                            }
                        }

                        break;

                    case 2:
                        for (i = 8; i < 16; i++) {
                            if (rw_dat[i].rwgbix == global_index_real) {
                                global_index_real = rw_dat[i].rwd_ptr[c_number];

                                if (!ppgCheckTextureNumber(0, global_index_real)) {
                                    ppgSetupCurrentDataList(&ppgRwBgList);
                                }

                                break;
                            }
                        }
                    }
                }

                bgDrawOneChip(x, y, 128, 128, global_index_real, -1, palOffset);
                ppgSetupCurrentDataList(curDataList);
            }
        }

        scr_calc2(bgnm);
        break;

    case 4:
        if (bgnm == 2) {
            suzi_pos = bg_pos[2].scr_x_buff.word_pos.h - 320;
            ppgSetupCurrentDataList(&ppgAkaneList);

            for (x = 0; x < 3; x = x + 1) {
                scr_trans_sub2(x * 256 + 128, 128, suzi_pos);

                if (No_Trans == 0) {
                    ppgSetupCurrentPaletteNumber(0, x);
                    njDrawTexture(bgpoly, 4, x, 0);
                }
            }
        }

        /* fallthrough */

    default:
        bgDrawOneScreen(bgnm, global_index, &xx[0], &yy[0], palOffset, curDataList);

        if (EXE_flag == 0 && Game_pause == 0 && rw_bg_flag[bgnm] && rw_num) {
            bgRWWorkUpdate();
        }

        break;
    }
}

void bgRWWorkUpdate(void) {
    s32 i;

    for (i = 0; i < rw_num; i++) {
        rw_dat[i].rw_cnt--;

        if (rw_dat[i].rw_cnt == 0) {
            if (*rw_dat[i].rwd_ptr == -1) {
                rw_dat[i].rwd_ptr = rw_dat[i].brw_ptr;
            }

            rw_dat[i].rw_cnt = *rw_dat[i].rwd_ptr++;
            rw_dat[i].gbix = *rw_dat[i].rwd_ptr++;
        }
    }
}

/* Xbox: no unused fifth parameter; the compares are written the other way
   round. */
void bgDrawOneScreen(s32 bgnum, s32 gixbase, s32* xx, s32* yy, s32 ofsPal, PPGDataList* curDataList) {
    s32 i, x, y, gbix;

    for (y = yy[0]; y < yy[1]; y += 128) {
        for (x = xx[0]; x < xx[1]; x += 128) {
            gbix = ((y >> 7) << 3) + (x >> 7) + gixbase;

            if (rw_bg_flag[bgnum] && rw_num) {
                for (i = 0; i < rw_num; i++) {
                    if (rw_dat[i].bg_num == bgnum && rw_dat[i].rwgbix == gbix) {
                        gbix = rw_dat[i].gbix;
                        if (!(ppgCheckTextureNumber(0, gbix))) {
                            ppgSetupCurrentDataList(&ppgRwBgList);
                        }
                        break;
                    }
                }
            }

            bgDrawOneChip(x, y, 128, 128, gbix, -1, ofsPal);
            ppgSetupCurrentDataList(curDataList);
        }
    }
}

void bgDrawOneChip(s32 x, s32 y, s32 xs, s32 ys, s32 gbix, u32 vtxCol, s32 ofsPal) {
    if (No_Trans != 0) {
        return;
    }

    if (ppgCheckTextureNumber((void *)0, gbix) == 0) {
        return;
    }

    ppgCalScrPosition(x, y, xs, ys);

    if (!(scrDrawPos[0].x < 384.0f && scrDrawPos[3].x >= 0.0f && scrDrawPos[0].y < 224.0f &&
          scrDrawPos[3].y >= 0.0f)) {
        return;
    }

    ppgWriteQuadUseTrans(scrDrawPos, vtxCol, (void *)0, gbix, 0, 0, ofsPal);
}

void bgAkebonoDraw(void) {
    s32 i;

    scrDrawPos[0].x = 0.0f;
    scrDrawPos[0].y = 0.0f;
    scrDrawPos[3].x = 128.0f;
    scrDrawPos[3].y = 224.0f;
    scrDrawPos[0].z = scrDrawPos[3].z = PrioBase[bg_priority[3]];
    scrDrawPos[0].s = scrDrawPos[0].t = 0.0f;
    scrDrawPos[3].s = 1.0f;
    scrDrawPos[3].t = 0.875f;

    for (i = 0; i < 3; i++) {
        ppgWriteQuadUseTrans(scrDrawPos, 0xFFFFFFFF, (void *)0, i, i, 0, 0);
        scrDrawPos[0].x += 128.0f;
        scrDrawPos[3].x += 128.0f;
    }
}

void ppgCalScrPosition(s32 x, s32 y, s32 xs, s32 ys) {
    Vec3 point[2];

    point[0].x = (f32)x;
    point[0].y = (f32)y;
    point[1].x = (f32)(x + xs);
    point[1].y = (f32)(y + ys);
    point[0].z = point[1].z = 0;
    njCalcPoints(0, point, point, 2);
    scrDrawPos[0].x = scrDrawPos[2].x = point[0].x;
    scrDrawPos[0].y = scrDrawPos[1].y = point[0].y;
    scrDrawPos[1].x = scrDrawPos[3].x = point[1].x;
    scrDrawPos[2].y = scrDrawPos[3].y = point[1].y;
    scrDrawPos[0].z = scrDrawPos[1].z = scrDrawPos[2].z = scrDrawPos[3].z = point[0].z;
    scrDrawPos[0].s = (f32)(x & 0x7F) / 128.0f;
    scrDrawPos[0].t = (f32)(y & 0x7F) / 128.0f;
    scrDrawPos[3].s = (f32)((x & 0x7F) + xs) / 128.0f;
    scrDrawPos[3].t = (f32)((y & 0x7F) + ys) / 128.0f;
    scrDrawPos[1].s = scrDrawPos[3].s;
    scrDrawPos[2].s = scrDrawPos[0].s;
    scrDrawPos[1].t = scrDrawPos[0].t;
    scrDrawPos[2].t = scrDrawPos[3].t;
}

void scr_trans_sub2(s32 x, s32 y, s32 suzi) {
    Vec3 point[2];
    Vec3 spoint[2];

    point[0].x = (f32)x;
    spoint[0].x = (f32)(x + suzi);
    point[0].y = spoint[0].y = (f32)(y + 0x200);
    point[1].x = (f32)(x + 0x100);
    spoint[1].x = (f32)(x + suzi + 0x100);
    point[1].y = spoint[1].y = (f32)(y + 0x300);
    point[0].z = point[1].z = spoint[0].z = spoint[1].z = 0;
    njCalcPoints(NULL, &point[0], &point[0], 2);
    njCalcPoints(NULL, &spoint[0], &spoint[0], 2);
    bgpoly[0].x = spoint[0].x;
    bgpoly[0].y = point[0].y;
    bgpoly[0].z = point[0].z;
    bgpoly[0].u = 0.0f;
    bgpoly[0].v = 0.0f;
    bgpoly[0].col = 0xFFFFFFFF;
    bgpoly[1].x = spoint[1].x;
    bgpoly[1].y = point[0].y;
    bgpoly[1].z = point[0].z;
    bgpoly[1].u = 1.0f;
    bgpoly[1].v = 0.0f;
    bgpoly[1].col = 0xFFFFFFFF;
    bgpoly[2].x = point[0].x;
    bgpoly[2].y = point[1].y;
    bgpoly[2].z = point[1].z;
    bgpoly[2].u = 0.0f;
    bgpoly[2].v = 1.0f;
    bgpoly[2].col = 0xFFFFFFFF;
    bgpoly[3].x = point[1].x;
    bgpoly[3].y = point[1].y;
    bgpoly[3].z = point[1].z;
    bgpoly[3].u = 1.0f;
    bgpoly[3].v = 1.0f;
    bgpoly[3].col = 0xFFFFFFFF;
}

/* Notes from the hand port this file replaced:
 * Zoomf_Init 0xAF2BA size 0x37, interior after the ret.
 * Zoom_Value_Set 0xAF2F1 size 0x75, interior after the ret.
 * Frame_Adgjust 0xAF366 size 0x96, interior after the ret.
 * Scrn_Pos_Init 0xAF3FC size 0x40, interior after the ret.
 * Scrn_Move_Set 0xAF43C size 0x23, interior after the ret.
 * Family_Init 0xAF45F size 0x1C, interior after the ret.
 * Scrn_Renew 0xAF4DC size 0xD, interior after the ret.
 * Irl_Family 0xAF4E9 size 0x37, interior after the ret.
 * Irl_Scrn 0xAF520 size 0x69, interior after the ret.
 * Frame_Up 0xAFAE3 size 0x43, interior after the ret.
 * Frame_Down 0xAFB26 size 0x43, interior after the ret.
 * scr_calc 0xAF086 size 0xE0, interior after the ret.
 * scr_calc2 0xAF166 size 0xE0, interior after the ret.
 * Pause_Family_On 0xAF246 size 0x74, interior after the ret.
 * Family_Move 0xAF589 size 0x38, a scanned start.
 * Ending_Family_Move 0xAF5C1 size 0x40, a scanned start.
 * Bg_Disp_Switch 0xAF601 size 0xA, interior after the ret.
 *
 * zoom_add is the word at 0x7BC4A6. scr_sc is the float at 0x7C55F4.
 * sca_x is the dword at 0x7C55F0 and sca_y is the dword at 0x7C584C.
 * scrn_adgjust_x is the word at 0x7BC51E. scrn_adgjust_y is the word at
 * 0x7BC4EA. bg_pos is 0x7C5BA0 and fm_pos is 0x7C5620, eight entries of
 * 0x10 bytes. bg_prm is 0x7C5960 and end_prm is 0x7BC960, stride 4.
 * Screen_Switch is the word at 0x7BC988. Screen_Switch_Buffer is the word
 * at 0x7BC98A. 1.0f is 0x2190AC and 64.0f is 0x2193F0. Frame_Down's clamp
 * constant is 0x273F44.
 *
 * Frame_Adgjust's >= 0x40 path multiplies in 32 bits, shifts, masks with
 * 0xFFFF01FF, negates, and stores the low word. The < 0x40 path masks with
 * 0x1FF. The stored word matches the PS2 u16 product. Frame_Up and
 * Frame_Down are the only callers. Irl_Scrn does not emit the PS2 statements
 * that only name a shift. 0xAF47B is both Family_Set_R and Family_Set_W.
 * 0xAF4AA is both Bg_On_R and Bg_On_W. 0xAF4C2 is both Bg_Off_R and Bg_Off_W.
 * Those three stay unnamed.
 *
 * scr_calc reads bg_prm. scr_calc2 reads end_prm[bgnm + 1]. Both store
 * BgMATRIX[bgnm + 1]. BgMATRIX is 0x795D00 and each entry is 0x40 bytes, so
 * index 1 is 0x795D40 and index 8 is 0x795F00. -1.0f is 0x2190D4. 224.0f is
 * 0x2497E4. use_family is 0x273F90 and matches the 22 PS2 bytes. bg_w.stage
 * is the byte at 0x7BC523. ending_use_family is 0x288C10 and matches the 20
 * PS2 bytes. end_w.type is the word at 0x7AABF6. bg_disp_off is the byte at
 * 0x7BC982. The matrix calls stay unnamed. Family_Move and
 * Ending_Family_Move do not keep the unused assign from the PS2 for-loop.
 * Bg_Texture_Load_Ending is 0xAE974 size 0x321 and is a scanned start.
 * It prints the ending tag, copies ending_map_tbl into scr_bcm, and loads
 * through load_it_use_any_key2. Cases 14, 15, and 19 store tokusyu_stage 5, 6, and
 * 7. bgRWWorkUpdate is 0xAEC95 size 0x4E and bgAkebonoDraw is 0xAECE3 size
 * 0xD5. Both are interior. ppgCalScrPosition is 0xAEDB8 size 0x142 and is a
 * scanned start. Its UVs are the cell offset divided by 128, with no 0.5
 * bias. y, xs, and ys arrive in ebx, edi, and esi. bgDrawOneChip is 0xAFA5B
 * size 0x88 and is a scanned start. rw_dat is 0x7BC9A4. Each entry is 0x14
 * bytes, with rw_cnt at +8 and gbix at +0xC. rw_num is the byte at
 * 0x7BCC45. scrDrawPos is 0x7BCB40. bg_priority is 0x7BC990. tokusyu_stage
 * is the byte at 0x7BCC44. gouki_end_gbix is 0x7BCC50. ending_flag is the
 * byte at 0x7BC981. ppgBgList is 0x7A7E60, ppgRwBgList is 0x7A7E38, and
 * ppgAkeList is 0x7A8060. 0xAE547 and 0xAE7DB are Bg_TexInit and
 * Ed_Kakikae_Set.
 */

void scr_calc(u8 bgnm) {
    njUnitMatrix((void *)0);
    njScale((void *)0, Frame_Zoom_X, Frame_Zoom_Y, 1.0f);
    njScale((void *)0, scr_sc, scr_sc, 1.0f);
    njTranslate((void *)0, 0.0f, 224.0f, 0.0f);
    njScale((void *)0, 1.0f, -1.0f, 1.0f);
    njTranslate((void *)0,
        (f32)(s16)-bg_prm[bgnm].bg_h_shift,
        (f32)(s16)-bg_prm[bgnm].bg_v_shift,
        0.0f);
    njGetMatrix(&BgMATRIX[bgnm + 1]);
}

void scr_calc2(u8 bgnm) {
    njUnitMatrix((void *)0);
    njScale((void *)0, Frame_Zoom_X, Frame_Zoom_Y, 1.0f);
    njScale((void *)0, scr_sc, scr_sc, 1.0f);
    njTranslate((void *)0, 0.0f, 224.0f, 0.0f);
    njScale((void *)0, 1.0f, -1.0f, 1.0f);
    njTranslate((void *)0,
        (f32)(s16)-end_prm[bgnm + 1].bg_h_shift,
        (f32)(s16)-end_prm[bgnm + 1].bg_v_shift,
        0.0f);
    njGetMatrix(&BgMATRIX[bgnm + 1]);
}

void Pause_Family_On(void) {
    njUnitMatrix((void *)0);
    njScale((void *)0, Frame_Zoom_X, Frame_Zoom_Y, 1.0f);
    njTranslate((void *)0, 0.0f, 224.0f, 0.0f);
    njScale((void *)0, 1.0f, -1.0f, 1.0f);
    njGetMatrix(&BgMATRIX[8]);
}

void Zoomf_Init(void) {
    zoom_add = 64;
    scr_sc = 1.0f;
    sca_x = 0;
    sca_y = 1023;
    scrn_adgjust_x = 0;
    scrn_adgjust_y = 0;
}

void Zoom_Value_Set(u16 zadd) {
    f32 work;
    u16 add;

    if (zadd < 0x40) {
        scr_sc = 64.0f / zadd;
        return;
    }

    if (zadd == 0x40) {
        scr_sc = 1.0f;
        return;
    }

    add = (u16)(zadd & 0x3F);
    work = 1.0f / (64.0f / add);
    add = (u16)(zadd & 0xFFC0);
    add >>= 6;
    scr_sc = 1.0f / (add + work);
}

/* <= 1, as retail compares. */
void Frame_Up(u16 x, u16 y, u16 add) {
    if (zoom_add <= 1) {
        scr_sc = 64.0f;
        return;
    }

    zoom_add = (u16)(zoom_add - add);
    Zoom_Value_Set(zoom_add);
    Frame_Adgjust(x, y);
}

void Frame_Down(u16 x, u16 y, u16 add) {
    if (zoom_add >= 0xFFC0) {
        scr_sc = 0.0009775171f;
        return;
    }

    zoom_add = (u16)(zoom_add + add);
    Zoom_Value_Set(zoom_add);
    Frame_Adgjust(x, y);
}

void Frame_Adgjust(u16 pos_x, u16 pos_y) {
    u16 buff;

    if (zoom_add >= 0x40) {
        buff = (u16)(zoom_add - 0x40);
        buff = (u16)(buff * pos_x);
        buff >>= 6;
        buff &= 0x1FF;
        scrn_adgjust_x = (s16)-buff;
    } else {
        buff = (u16)(0x40 - zoom_add);
        buff = (u16)(buff * pos_x);
        buff >>= 6;
        buff &= 0x1FF;
        scrn_adgjust_x = (s16)buff;
    }

    if (zoom_add >= 0x40) {
        buff = (u16)(zoom_add - 0x40);
        buff = (u16)(buff * (pos_y + 0x15));
        buff >>= 6;
        buff &= 0x1FF;
        scrn_adgjust_y = (s16)-buff;

        if (scrn_adgjust_y == -0x14) {
            scrn_adgjust_y = (s16)(scrn_adgjust_y + 1);
        }
    } else {
        buff = (u16)(0x40 - zoom_add);
        buff = (u16)(buff * (pos_y + 0x15));
        buff >>= 6;
        buff &= 0x1FF;
        scrn_adgjust_y = (s16)buff;

        if (scrn_adgjust_y == -0x14) {
            scrn_adgjust_y = (s16)(scrn_adgjust_y + 1);
        }
    }
}

void Scrn_Pos_Init(void) {
    u8 i;

    for (i = 0; i < 8; i++) {
        bg_pos[i].scr_x.long_pos = 0;
        bg_pos[i].scr_x_buff.long_pos = 0;
        bg_pos[i].scr_y.long_pos = 0;
        bg_pos[i].scr_y_buff.long_pos = 0;
        bg_prm[i].bg_h_shift = 0;
        bg_prm[i].bg_v_shift = 0;
        end_prm[i].bg_h_shift = 0;
        end_prm[i].bg_v_shift = 0;
    }
}

void Scrn_Move_Set(s8 bgnm, s16 x, s16 y) {
    bg_pos[bgnm].scr_x.word_pos.h = x;
    bg_pos[bgnm].scr_y.word_pos.h = (s16)(y + 16);
}

void Family_Init(void) {
    u8 i;

    for (i = 0; i < 8; i++) {
        fm_pos[i].scr_x.long_pos = 0;
        fm_pos[i].scr_y.long_pos = 0;
        fm_pos[i].scr_x_buff.long_pos = 0;
        fm_pos[i].scr_y_buff.long_pos = 0;
    }
}

void Family_Set_R(s8 fmnm, s16 x, s16 y) {
    fm_pos[fmnm].scr_x.word_pos.h = x;
    fm_pos[fmnm].scr_y.word_pos.h = y;
    fm_pos[fmnm].scr_x_buff.word_pos.h = x;
    fm_pos[fmnm].scr_y_buff.word_pos.h = y;
}

void Family_Set_W(s8 fmnm, s16 x, s16 y) {
    fm_pos[fmnm].scr_x.word_pos.h = x;
    fm_pos[fmnm].scr_y.word_pos.h = y;
    fm_pos[fmnm].scr_x_buff.word_pos.h = x;
    fm_pos[fmnm].scr_y_buff.word_pos.h = y;
}

void Bg_On_R(u16 s_prm) {
    Screen_Switch |= s_prm;
    Screen_Switch_Buffer = Screen_Switch;
}

void Bg_On_W(u16 s_prm) {
    Screen_Switch |= s_prm;
    Screen_Switch_Buffer = Screen_Switch;
}

void Bg_Off_R(u16 s_prm) {
    s_prm = ~s_prm;
    Screen_Switch &= s_prm;
    Screen_Switch_Buffer = Screen_Switch;
}

void Bg_Off_W(u16 s_prm) {
    s_prm = ~s_prm;
    Screen_Switch &= s_prm;
    Screen_Switch_Buffer = Screen_Switch;
}

void Scrn_Renew(void) {
    Screen_Switch_Buffer = Screen_Switch;
}

void Irl_Family(void) {
    u8 i;

    for (i = 0; i < 8; i++) {
        fm_pos[i].scr_x_buff.long_pos = fm_pos[i].scr_x.long_pos;
        fm_pos[i].scr_y_buff.long_pos = fm_pos[i].scr_y.long_pos;
        bg_pos[i].scr_x_buff.long_pos = bg_pos[i].scr_x.long_pos;
        bg_pos[i].scr_y_buff.long_pos = bg_pos[i].scr_y.long_pos;
    }
}

void Irl_Scrn(void) {
    s8 i;

    for (i = 0; i < 8; i++) {
        bg_prm[i].bg_h_shift = (u16)(scrn_adgjust_x + bg_pos[i].scr_x_buff.word_pos.h);
        end_prm[i].bg_h_shift = (u16)(scrn_adgjust_x + fm_pos[i].scr_x_buff.word_pos.h);
        bg_prm[i].bg_v_shift = (u16)(bg_pos[i].scr_y_buff.word_pos.h - scrn_adgjust_y);
        end_prm[i].bg_v_shift = (u16)(fm_pos[i].scr_y_buff.word_pos.h - scrn_adgjust_y);
    }
}

/* The mask shifts after the index increments. */
void Family_Move(void) {
    u8 fam_ix;
    u8 i;
    u8 mask;

    fam_ix = use_family[bg_w.stage];
    mask = 0x80;

    for (i = 0; i < 8; i++, mask >>= 1) {
        if (fam_ix & mask) {
            scr_calc(i);
        }
    }
}

/* The mask shifts after the index increments. */
void Ending_Family_Move(void) {
    u8 mask_val;
    u8 i;
    u8 mask;

    mask_val = ending_use_family[end_w.type];
    mask = 0x80;

    for (i = 0; i < 8; i++, mask >>= 1) {
        if (mask_val & mask) {
            scr_calc2(i);
        }
    }

    scr_calc(3);
}

void Bg_Disp_Switch(u8 on_off) {
    bg_disp_off = on_off;
}
