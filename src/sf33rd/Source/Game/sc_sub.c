/* sc_sub.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * Sa_frame_Clear 0xE5469 size 0x24. FLAG: x86-only offsets -0x1,0x1,0x2.
 * Sa_frame_Clear2 0xE548D size 0x59. FLAG: x86-only constants 0x30.
 * SSPutStrTexInput 0xE54E6 size 0xEC. FLAG: x86-only offsets 0x80.
 * SSPutStrTexInput2 0xE55D2 size 0xCC. FLAG: x86-only offsets 0x80.
 * SSPutStr 0xE569E size 0xAE. FLAG: x86-only offsets 0x2.
 * SSPutStrTexInputPro 0xE574C size 0x11C. FLAG: x86-only offsets 0x80.
 * SSGetDrawSizePro 0xE5868 size 0x36.
 * SSPutStr2 0xE589E size 0xA3.
 * SSPutStrTexInputB 0xE5941 size 0x13F. FLAG: x86-only offsets 0x80.
 * SSSetUVOffsetForScale 0xE5A80 size 0x55.
 * SSPutStrTexInputB2 0xE5AD5 size 0x111.
 * SSPutStr_Bigger 0xE5BE6 size 0x132. FLAG: x86-only constants 0x18.
 * SSPutDec 0xE5D18 size 0x142.
 * SSPutDec3 0xE5E5A size 0x1AE. FLAG: x86-only constants 0x18.
 * scfont_put 0xE6008 size 0x1B7.
 * scfont_put2 0xE61BF size 0x3F. FLAG: x86-only constants 0x19.
 * scfont_sqput 0xE61FE size 0x1CA.
 * scfont_sqput2 0xE63C8 size 0xDD. FLAG: x86-only offsets
 * -0x19,-0x3,-0x1,0x1,0x2.
 * scfont_sqput3 0xE64A5 size 0x1BB. FLAG: x86-only constants 0x18.
 * sc_clear 0xE6660 size 0x79. FLAG: x86-only offsets -0x19.
 * vital_put 0xE66D9 size 0x178.
 * silver_vital_put 0xE6851 size 0x11A.
 * vital_base_put 0xE696B size 0xD7.
 * spgauge_base_put 0xE6A42 size 0x100. FLAG: x86-only constants 0x2a; x86-only
 * offsets 0x30.
 * stun_put 0xE6B42 size 0x14A.
 * stun_base_put 0xE6C8C size 0xED. FLAG: x86-only constants 0x15; x86-only
 * offsets 0xd8.
 * WipeInit 0xE6D79 size 0x8.
 * WipeIn 0xE6D81 size 0x15D.
 * xb_WipeInRedraw 0xE6EDE size 0x157. FLAG: x86-only callees njDrawPolygon2D.
 * FadeInit 0xE7035 size 0x8.
 * FadeOut 0xE703D size 0xD4. FLAG: x86-only constants 0x18; x86-only offsets
 * -0x4,-0x2.
 * xb_FadeOutRedraw 0xE7111 size 0xCC. FLAG: x86-only callees
 * njColorBlendingMode,njDrawPolygon2D.
 * FadeIn 0xE71DD size 0xD4. FLAG: x86-only constants 0x18; x86-only offsets
 * -0x4,-0x2.
 * xb_FadeInRedraw 0xE72B1 size 0xCC. FLAG: x86-only callees
 * njColorBlendingMode,njDrawPolygon2D.
 * ToneDown 0xE740C size 0x8F. FLAG: x86-only constants 0x18; x86-only offsets
 * -0x4,-0x2.
 * player_name 0xE749B size 0xA9.
 * stun_mark_write 0xE7544 size 0x64.
 * max_mark_write 0xE75A8 size 0x53. FLAG: x86-only offsets -0xa.
 * SF3_logo 0xE75FB size 0x661. FLAG: x86-only constants 0x48,0x70,0x88,0xf8;
 * x86-only offsets -0x70,0x8,0x70,0x80,0xd0.
 * scfont_sqput_face 0xE7C5C size 0x1A6. FLAG: x86-only constants 0x40,0x80.
 * face_base_put 0xE7E02 size 0x104.
 * hnc_set 0xE7F06 size 0x1BE. FLAG: x86-only offsets 0xb8.
 * hnc_wipeinit 0xE80C4 size 0x155. FLAG: x86-only constants 0x18,0xb8;
 * x86-only offsets -0x2.
 * hnc_wipeout 0xE8219 size 0x32E. FLAG: x86-only offsets -0x4,0x8,0xc.
 * ci_set 0xE8547 size 0x6A.
 * nw_set 0xE85B1 size 0x94.
 * score8x16_put 0xE8645 size 0x36.
 * score16x24_put 0xE867B size 0x3B.
 * combo_message_set 0xE86B6 size 0x1A5. FLAG: x86-only offsets -0x2.
 * combo_pts_set 0xE885B size 0x1B0. FLAG: x86-only offsets
 * -0x2,-0x1,0x1,0x2,0x3.
 * naming_set 0xE8A0B size 0x50. FLAG: x86-only constants 0x1b; x86-only
 * offsets 0xd.
 * silver_stun_put 0xE8A5B size 0x13E. FLAG: x86-only offsets 0xd8.
 * overwrite_panel 0xE8B99 size 0xA0. FLAG: x86-only offsets -0x4,-0x2.
 * sa_stock_trans 0xE8C39 size 0x56.
 * sa_fullstock_trans 0xE8C8F size 0x48.
 * sa_number_write 0xE8CD7 size 0x61.
 * sc_ram_to_vram 0xE8D38 size 0xBE. FLAG: x86-only constants 0x19; x86-only
 * offsets 0x4.
 * sc_ram_to_vram_opc 0xE8DF6 size 0x86. FLAG: x86-only offsets 0x4.
 * sq_paint_chenge 0xE8E7C size 0x4B. FLAG: x86-only offsets -0x19.
 * fade_cont_init 0xE8EC7 size 0x39.
 * fade_cont_main 0xE8F00 size 0x7C.
 * Akaobi 0xE8F7C size 0x97. FLAG: x86-only offsets -0x4,-0x2.
 * Training_Disp_Work_Clear 0xE9013 size 0x29. FLAG: x86-only offsets
 * -0x1,0x1,0x2,0x3,0x5,0x7.
 * Training_Damage_Set 0xE903C size 0x71.
 * Training_Data_Disp 0xE90AD size 0x2A8. FLAG: x86-only offsets
 * 0x30,0x3a,0x44.
 * xb_SetScreenShotColor 0xE9355 size 0xA.
 * dispButtonImage 0xE935F size 0x11C. FLAG: x86-only callees
 * xb_QueueButtonImage; PS2-only callees setFilterMode,flSetRenderState,ps2Seqs
 * RenderQuadInit_A,ps2SeqsRenderQuad_A2,ps2SeqsRenderQuadEnd.
 * dispButtonImage2 0xE947B size 0x149.
 * dispSaveLoadTitle 0xE98D8 size 0x16C.
 * Scrscreen_Init 0xE9A44 size 0x14A.
 * Sa_frame_Write 0xE9B8E size 0xF4. FLAG: x86-only constants 0xc0; x86-only
 * offsets -0x2,-0x1,0x1.
 * SSPutStrPro 0xE9C82 size 0xDA. FLAG: x86-only offsets 0x2.
 * WipeOut 0xE9D5C size 0x187. FLAG: x86-only offsets -0xdf.
 * xb_WipeOutRedraw 0xE9EE3 size 0x17D. FLAG: x86-only callees
 * overwrite_panel,njDrawPolygon2D.
 * player_face 0xEA060 size 0x194.
 * stun_gauge_waku_write 0xEA1F4 size 0xE4.
 * player_face_init is folded into 0x4384A with 63 other bodies. Unnamed.
 * Data: ascProData is 0x332FE8, 0x80 bytes compared.
 * Data: sa_frame 0x7A9AC0.
 * Data: scrscrntex 0x7A9D00.
 * Data: WipeLimit 0x7A9AA7.
 * Data: FadeLimit 0x7A9AAC.
 * Data: Hnc_Num 0x7A9AB6.
 * Data: fd_dat 0x7A9AB0.
 * Data: scrnAddTex1UV 0x2AEDD0, 0x24 bytes compared.
 * Unnamed data used (not checked): SSPutStrTexInput:
 * 0x2190f0,0x2aee58,0x2aee5c; SSPutStrTexInput2:
 * 0x2190f0,0x2aee54,0x2aee58,0x2aee5c,0x2aee60; SSPutStrTexInputPro:
 * 0x2190f0,0x2aee58,0x2aee5c; SSPutStrTexInputB:
 * 0x2aee58,0x2aee5c,0x79688c,0x796890,0x796894,0x796898;
 * SSSetUVOffsetForScale:
 * 0x2190ac,0x219400,0x21cce8,0x79688c,0x796890,0x796894,0x796898;
 * SSPutStrTexInputB2: 0x2190f0,0x2aee58,0x2aee5c,0x2aee64,0x2aee68,0x2aee6c;
 * SSPutStr_Bigger: 0x2190c8,0x2aee58,0x2aee5c; SSPutDec3: 0x21ccec,0x2aee6c;
 * scfont_put: 0x2190f0,0x2aee58; scfont_sqput: 0x2190f0,0x2aee58;
 * scfont_sqput3: 0x2190f0,0x2aee58; vital_put:
 * 0x2197ac,0x2aee70,0x2aee74,0x2aee78,0x2aee7c,0x2aee80,0x2aee84,0x2aee88;
 * silver_vital_put:
 * 0x2197ac,0x2498f4,0x2aee5c,0x2aee70,0x2aee74,0x2aee78,0x2aee8c,0x2aee90;
 * vital_base_put: 0x2aee5c,0x2aee74,0x2aee78,0x2aee8c,0x2aee9c,0x2aeea0;
 * spgauge_base_put: 0x249928,0x2aeea4,0x2aeea8,0x2aeeac; stun_put:
 * 0x28667c,0x2aee70,0x2aee74,0x2aee78,0x2aee88,0x2aeeb0,0x2aeeb4;
 * stun_base_put: 0x2aee74,0x2aee78,0x2aeeb8,0x2aeebc; WipeIn:
 * 0x2497e4,0x2497e8; xb_WipeInRedraw: 0x2497e4,0x2497e8; SF3_logo:
 * 0x2190f0,0x2197dc,0x249928,0x2aee50,0x2aee58,0x2aee5c,0x2aeec0,0x2aeec4;
 * scfont_sqput_face: 0x2190f0,0x2aee58; face_base_put:
 * 0x2aeebc,0x2aeed0,0x2aeed4,0x2aeed8,0x2aeedc,0x2aeee0; hnc_set:
 * 0x2190f0,0x2aee54,0x2aee58,0x2aee80,0x2aee90,0x2aeeb4,0x2aeee4,0x2aeee8;
 * hnc_wipeinit: 0x2aee58; hnc_wipeout:
 * 0x2197ac,0x2aee58,0x2aee70,0x2aeee4,0x2aeee8,0x2aeeec; silver_stun_put:
 * 0x28667c,0x2aee70,0x2aee74,0x2aee78,0x2aee90,0x2aee94,0x2aeef4,0x2aeef8;
 * xb_SetScreenShotColor: 0x7a9aa8; dispButtonImage: 0x2197dc,0x7a9aa8;
 * dispButtonImage2: 0x2197dc,0x333068; dispSaveLoadTitle:
 * 0x2190ac,0x2194ec,0x2197dc,0x21cce4,0x2aeefc,0x2aef00,0x2aef04,0x2aef08;
 * Scrscreen_Init: 0x2aef14; WipeOut: 0x2497e4,0x2497e8; xb_WipeOutRedraw:
 * 0x2497e4,0x2497e8.
 * Globals: nwdata_tbl 0x2AE6A0, smark_pos_tbl 0x2AE728, smark_kind_tbl
 * 0x2AE730, combo_mtbl 0x2AE734, Player_Name_Pos_TBL 0x2AE74C, Max_Pos_TBL
 * 0x2AE778, Fade_Pos_tbl 0x2AE77C, Akaobi_Pos_tbl 0x2AE78C, Face_Pos_TBL
 * 0x2AE79C, Grade_Pos_TBL 0x2AE7C8, hnc_wipe_tbl1 0x2AE818, ci_tbl 0x2AEA34,
 * cip_tbl 0x2AEA60, rankname_pos_tbl 0x2AEA68, sa_color_data_tbl 0x2AEAC8,
 * sa_ram_vram_col 0x2AEC78, sc_ram_vram_tbl 0x2AEC98, fade_data_tbl 0x2AECD8,
 * bigger_col_tbl 0x2AED18, Training_combo_pos_tbl 0x2AEDC8,
 * Training_combo_prio_tbl 0x2AEDCC, scrnAddTex1UV 0x2AEDD0, ascProData
 * 0x332FE8, ppgScrListOpt 0x7A7D40, ppgScrTex 0x7A7D60, ppgScrListFace
 * 0x7A7D80, ppgScrPal 0x7A7DA0, ppgScrPalFace 0x7A7EC0, ppgScrList 0x7A7EE0,
 * ppgScrPalOpt 0x7A7F00, ppgScrPalShot 0x7A7F20, ppgScrListShot 0x7A7F38,
 * My_char 0x7A8114, Play_Type 0x7A812D, Training_ID 0x7A81FE, Keep_Grade
 * 0x7A8278, SA_shadow_on 0x7A82EE, Disp_Attack_Data 0x7A82F8, Fade_Number
 * 0x7A8334, Fade_Flag 0x7A851A, Player_Color 0x7A8906, Champion 0x7A8931,
 * Super_Arts 0x7A89FE, WipeLimit 0x7A9AA7, FadeLimit 0x7A9AAC, fd_dat
 * 0x7A9AB0, Hnc_Num 0x7A9AB6, sa_frame 0x7A9AC0, scrscrntex 0x7A9D00, tr_data
 * 0x7A9D60, sa_pa_flag 0x7BC4AA, No_Trans 0x7BD3C9, Frame_Zoom_Y 0x7C5854,
 * Frame_Zoom_X 0x7C5B94, omop_st_bar_disp 0x7C5C60, omop_sa_bar_disp 0x7C5C64,
 * omop_cockpit 0x7C5C6C, PrioBase 0xC7E560.
 */

#include "structs.h"

#define TO_UV_256(val) ((0.5f + (val)) / 256.0f)
#define TO_UV_256_NEG(val) (((val) - 0.5f) / 256.0f)
#define TO_UV_128(val) ((0.5f + (val)) / 128.0f)
#define TO_UV_256(val) ((val) / 256.0f)
#define TO_UV_256_NEG(val) (TO_UV_256(val))
#define TO_UV_128(val) ((val) / 128.0f)

typedef const u8* UV_POS_TBL;

typedef struct {
    // total size: 0x6
    s16 fade;      // offset 0x0, size 0x2
    s16 fade_kind; // offset 0x2, size 0x2
    u8 fade_prio;  // offset 0x4, size 0x1
} FadeData;

typedef struct {
    // total size: 0x4
    u8 atr;  // offset 0x0, size 0x1
    u8 page; // offset 0x1, size 0x1
    u8 cx;   // offset 0x2, size 0x1
    u8 cy;   // offset 0x3, size 0x1
} SAFrame;

extern u8 No_Trans;
extern const s16 Fade_Pos_tbl[8];
extern f32 PrioBase[];
extern f32 Frame_Zoom_X;
extern f32 Frame_Zoom_Y;
extern const u32 bigger_col_tbl[11][4];
extern void SSSetUVOffsetForScale(f32 arg0, f32 arg1, f32 sc);
extern void njColorBlendingMode(s32 mode, s32 blend);
extern void njDrawPolygon2D(PAL_CURSOR *poly, s32 n, f32 pri, s32 attr, s32 kind);
extern void setFilterMode(s32 mode);
extern void njSetPaletteBankNumG(s32 page, s32 bank);
extern void njDrawSprite(Polygon *poly, s32 n, s32 page, s32 kind);
extern void njDrawTexture(Polygon *poly, s32 n, s32 page, s32 kind);
extern s16 omop_cockpit;
extern s16 omop_st_bar_disp[2];
extern s16 omop_sa_bar_disp[2];
extern s8 SA_shadow_on;
extern u8 My_char[2];
extern PPGDataList ppgScrList;
extern const u8 Player_Name_Pos_TBL[21][2];
extern const u8 smark_pos_tbl[3][2];
extern const u8 smark_kind_tbl[3];
extern const u8 Max_Pos_TBL[2][2];
extern const u8 combo_mtbl[7][3];
extern void ppgSetupCurrentDataList(PPGDataList *dlist);
extern s32 ppgWriteQuadWithST_B(Vertex *pos, u32 col, PPGDataList *tb, s32 tix, s32 cix);
extern s32 chkNameAkuma(s32 plnum, s32 rnum);
extern Texture ppgScrTex;
extern Palette ppgScrPal;
extern Palette ppgScrPalFace;
extern Palette ppgScrPalShot;
extern Palette ppgScrPalOpt;
extern PPGDataList ppgScrListFace;
extern PPGDataList ppgScrListShot;
extern PPGDataList ppgScrListOpt;
extern u32 load_it_use_any_key2(s32 id, void **adrs, s16 *key, s32 arg3, s32 arg4);
extern void flLogOut(const char *text);
extern s32 ppgSetupPalChunk(Palette *pch, u8 *adrs, s32 size, s32 ixNum1st, s32 num, s32 unused);
extern s32 ppgSetupTexChunk_1st(Texture *tch, u8 *adrs, s32 size, s32 ixNum1st, s32 ixNums, s32 ar, s32 arcnt);
extern s32 ppgSetupTexChunk_2nd(Texture *tch, s32 ixNum);
extern s32 ppgSetupTexChunk_3rd(Texture *tch, s32 ixNum, u32 attribute);
extern void Push_ramcnt_key(s16 key);
extern void ppgSourceDataReleased(PPGDataList *dlist);
extern void mlt_obj_matrix(void *ewk, s32 arg1);
extern const u16 sa_color_data_tbl[3];
extern s8 Super_Arts[2];
extern const u16 sa_ram_vram_col[8][2];
extern const UV_POS_TBL sc_ram_vram_tbl[8][2];
extern u16 Fade_Number;
extern const s16 fade_data_tbl[10][3];
extern s8 Fade_Flag;
extern const s16 Akaobi_Pos_tbl[8];
extern u8 Training_ID;
extern TrainingData2 tr_data[2];
extern const u8 Face_Pos_TBL[21][2];
extern const u8 Grade_Pos_TBL[32][2];
extern s8 Player_Color[2];
extern u8 Play_Type;
extern s8 Champion;
extern u16 Keep_Grade[2];
extern const s16 hnc_wipe_tbl1[26][8];
extern const u8 ci_tbl[7][6];
extern const u8 cip_tbl[7];
extern const u8 nwdata_tbl[21][6];
extern const u8 rankname_pos_tbl[48][2];
extern u8 Disp_Attack_Data;
extern s8 sa_pa_flag;
extern const u16 Training_combo_pos_tbl[2];
extern const u16 Training_combo_prio_tbl[2];
extern s32 ppgGetUsingTextureHandle(Texture *tch, s32 ix);
extern s32 ppgGetUsingPaletteHandle(Palette *pch, s32 ix);
extern void njCalcPoint(s32 mtx, Vec3 *src, Vec3 *dst);
extern void xb_QueueButtonImage(Sprite *prm, u32 col, s32 arg2, s32 arg3);
extern void flSetRenderState(s32 kind, u32 texCode);
extern void ps2SeqsRenderQuadInit_A(void);
extern void ps2SeqsRenderQuad_A2(Sprite *prm, u32 col);
extern void ps2SeqsRenderQuadEnd(void);
extern s32 D_007A9AA8;
extern f32 D_0079688C;
extern f32 D_00796890;
extern f32 D_00796894;
extern f32 D_00796898;
void Sa_frame_Clear(void);
void scfont_put(u16 x, u16 y, u8 atr, u8 page, u8 cx, u8 cy, u16 priority);
s32 SSGetDrawSizePro(const s8 *str);
s16 SSPutStrTexInputPro(u16 x, u16 y, u16 ix);
void overwrite_panel(u32 color, u8 priority);
void face_base_put(void);
void silver_stun_put(u8 Pl_Num, s16 len);

u8 ascProData[128] = { 0, 18, 0, 0, 0,  0, 0,  0,  0,  0, 0,  0, 0, 0,  0,  0,  0, 0, 0,  0,  0,  0,  0, 0,  0, 0,
                       0, 0,  0, 0, 0,  0, 34, 19, 18, 0, 0,  0, 0, 34, 34, 34, 1, 1, 34, 1,  34, 0,  0, 18, 0, 0,
                       0, 0,  0, 0, 0,  0, 34, 34, 17, 0, 17, 0, 0, 0,  0,  0,  0, 0, 0,  0,  0,  34, 0, 0,  0, 0,
                       0, 0,  0, 0, 0,  0, 0,  0,  0,  0, 0,  0, 0, 17, 0,  17, 1, 0, 34, 0,  0,  0,  0, 0,  0, 0,
                       0, 34, 2, 0, 34, 0, 0,  0,  0,  0, 16, 0, 0, 0,  0,  0,  0, 0, 0,  18, 35, 33, 0, 33 };

extern SAFrame sa_frame[3][48];

extern Polygon scrscrntex[4];

extern u8 WipeLimit;

extern u8 FadeLimit;

extern s16 Hnc_Num;

extern FadeData fd_dat;

/* Xbox: the button pictures' cells in the Xbox screen texture (the PS2
   table places the PS2's pictures). */
const u8 scrnAddTex1UV[9][4] = { { 64, 0, 32, 32 },  { 96, 0, 32, 32 }, { 64, 32, 32, 32 },
                                 { 0, 32, 32, 32 },  { 0, 0, 32, 32 },  { 32, 0, 32, 32 },
                                 { 96, 32, 32, 32 }, { 32, 32, 32, 32 }, { 96, 96, 32, 32 } };

void Scrscreen_Init(void) {
    void *loadAdrs;
    u32 loadSize;
    s16 i;
    s16 key;

    ppgScrList.tex = ppgScrListFace.tex = ppgScrListShot.tex = ppgScrListOpt.tex = &ppgScrTex;
    ppgScrList.pal = &ppgScrPal;
    ppgScrListFace.pal = &ppgScrPalFace;
    ppgScrListShot.pal = &ppgScrPalShot;
    ppgScrListOpt.pal = &ppgScrPalOpt;
    ppgSetupCurrentDataList(&ppgScrList);
    loadSize = load_it_use_any_key2(0xE, &loadAdrs, &key, 2, 0);

    if (loadSize == 0) {
        flLogOut("スコアスクリーン用のテクスチャが読み込めませんでした。\n");
        for (;;) {
        }
    }

    ppgSetupPalChunk(&ppgScrPalOpt, loadAdrs, loadSize, 0, 3, 1);
    ppgSetupPalChunk(&ppgScrPalShot, loadAdrs, loadSize, 0, 2, 1);
    ppgSetupPalChunk(&ppgScrPalFace, loadAdrs, loadSize, 0, 1, 1);
    ppgSetupPalChunk(0, loadAdrs, loadSize, 0, 0, 1);
    ppgSetupTexChunk_1st(0, loadAdrs, loadSize, 0, 6, 0, 0);

    for (i = 0; i < 3; i++) {
        ppgSetupTexChunk_2nd(0, i);
        ppgSetupTexChunk_3rd(0, i, 1);
    }

    for (i = 3; i < ppgScrTex.textures; i++) {
        ppgSetupTexChunk_2nd(0, i);
        ppgSetupTexChunk_3rd(0, i, 1);
    }

    Push_ramcnt_key(key);
    ppgSourceDataReleased(0);
    Sa_frame_Clear();
}

void Sa_frame_Clear(void) {
    u8 i;
    u8 j;

    for (j = 0; j < 3; j++) {
        for (i = 0; i < 48; i++) {
            sa_frame[j][i].atr = 0;
            sa_frame[j][i].page = 0;
            sa_frame[j][i].cx = 0;
            sa_frame[j][i].cy = 0;
        }
    }
}

void Sa_frame_Clear2(u8 pl) {
    u8 i;
    u8 j;

    for (j = 0; j < 3; j++) {
        for (i = (u8)(pl * 24); i < (u8)((pl * 24) + 24); i++) {
            sa_frame[j][i].atr = 0;
            sa_frame[j][i].page = 0;
            sa_frame[j][i].cx = 0;
            sa_frame[j][i].cy = 0;
        }
    }
}

void Sa_frame_Write(void) {
    u8 i;
    u8 j;

    if (omop_cockpit == 0) {
        return;
    }

    if (No_Trans) {
        return;
    }

    ppgSetupCurrentDataList(&ppgScrList);

    if (omop_sa_bar_disp[0]) {
        for (j = 0; j < 3; j++) {
            for (i = 0; i < 24; i++) {
                if (sa_frame[j][i].atr != 0) {
                    scfont_put(i, (u16)(j + 25), sa_frame[j][i].atr, sa_frame[j][i].page, sa_frame[j][i].cx,
                        sa_frame[j][i].cy, 2);
                }
            }
        }
    }

    if (omop_sa_bar_disp[1]) {
        for (j = 0; j < 3; j++) {
            for (i = 24; i < 48; i++) {
                if (sa_frame[j][i].atr != 0) {
                    scfont_put(i, (u16)(j + 25), sa_frame[j][i].atr, sa_frame[j][i].page, sa_frame[j][i].cx,
                        sa_frame[j][i].cy, 2);
                }
            }
        }
    }
}

void SSPutStrTexInput(u16 x, u16 y, const s8 *str) {
    s32 u;
    s32 v;

    u = ((*str & 0xF) * 8) + 0x80;
    v = ((*str & 0xF0) >> 4) * 8;
    scrscrntex[0].u = (0.5f + u) / 256.0f;
    scrscrntex[3].u = (0.5f + (u + 8)) / 256.0f;
    scrscrntex[0].v = (0.5f + v) / 256.0f;
    scrscrntex[3].v = (0.5f + (v + 8)) / 256.0f;
    scrscrntex[0].x = x * Frame_Zoom_X;
    scrscrntex[3].x = (x + 8) * Frame_Zoom_X;
    scrscrntex[0].y = y * Frame_Zoom_Y;
    scrscrntex[3].y = (y + 8) * Frame_Zoom_Y;
}

void SSPutStrTexInput2(u16 x, u16 y, u8 str) {
    s32 u;

    u = (str * 8) + 128;
    scrscrntex[0].u = (0.5f + u) / 256.0f;
    scrscrntex[3].u = (0.5f + (u + 8)) / 256.0f;
    scrscrntex[0].v = (0.5f + 0.0f) / 256.0f;
    scrscrntex[3].v = (0.5f + 8.0f) / 256.0f;
    scrscrntex[0].x = x * Frame_Zoom_X;
    scrscrntex[3].x = (x + 8) * Frame_Zoom_X;
    scrscrntex[0].y = y * Frame_Zoom_Y;
    scrscrntex[3].y = (y + 8) * Frame_Zoom_Y;
}

void SSPutStr(u16 x, u16 y, u8 atr, const s8 *str) {
    if (No_Trans) {
        return;
    }

    ppgSetupCurrentDataList(&ppgScrList);
    setFilterMode(0);
    njColorBlendingMode(0, 1);
    scrscrntex[0].col = scrscrntex[3].col = -1;
    scrscrntex[0].z = scrscrntex[3].z = PrioBase[2];
    njSetPaletteBankNumG(1, atr & 0x3F);
    x = (u16)(x * 8);
    y = (u16)(y * 8);

    while (*str != '\0') {
        if (*str != ',') {
            SSPutStrTexInput(x, y, str);
        } else {
            SSPutStrTexInput(x, (u16)(y + 2), str);
        }

        njDrawSprite(scrscrntex, 4, 1, 1);
        x = (u16)(x + 8);
        str++;
    }
}

s32 SSPutStrPro(u16 flag, u16 x, u16 y, u8 atr, u32 col, const s8 *str) {
    s16 pos;
    s32 start;
    s16 step;

    if (No_Trans) {
        return x;
    }

    ppgSetupCurrentDataList(&ppgScrList);
    setFilterMode(0);
    njColorBlendingMode(0, 1);
    scrscrntex[0].col = scrscrntex[3].col = col;
    scrscrntex[0].z = scrscrntex[3].z = PrioBase[2];
    njSetPaletteBankNumG(1, atr & 0x3F);

    if (flag != 0) {
        pos = ((s32)x - SSGetDrawSizePro(str)) / 2;
    } else {
        pos = x;
    }

    start = (u16)pos;

    while (*str != 0) {
        if (*str != ',') {
            step = SSPutStrTexInputPro((u16)pos, y, (u16)*str);
        } else {
            step = SSPutStrTexInputPro((u16)pos, (u16)(y + 2), 0x2C);
        }

        str += 1;
        pos += step;
        njDrawSprite(scrscrntex, 4, 1, 1);
    }

    return start;
}

s16 SSPutStrTexInputPro(u16 x, u16 y, u16 ix) {
    s16 slide;
    s16 sideL;
    s16 sideR;
    s32 u;
    s32 v;

    u = (ix & 0xF) * 8 + 0x80;
    v = ((ix & 0xF0) >> 4) * 8;
    sideL = (s16)((ascProData[ix] >> 4) & 0xF);
    sideR = (s16)(ascProData[ix] & 0xF);
    scrscrntex[0].u = (0.5f + (u + sideL)) / 256.0f;
    scrscrntex[3].u = (0.5f + (u + 8 - sideR)) / 256.0f;
    scrscrntex[0].v = (0.5f + v) / 256.0f;
    scrscrntex[3].v = (0.5f + (v + 8)) / 256.0f;
    slide = (s16)((8 - sideL) - sideR);
    scrscrntex[0].x = x * Frame_Zoom_X;
    scrscrntex[3].x = Frame_Zoom_X * (x + slide);
    scrscrntex[0].y = y * Frame_Zoom_Y;
    scrscrntex[3].y = (y + 8) * Frame_Zoom_Y;
    return slide;
}

s32 SSGetDrawSizePro(const s8 *str) {
    s32 ix;
    s32 size = 0;

    while (*str != '\0') {
        ix = *str++;
        ix &= 0x7F;
        size += 8 - ((ascProData[ix] >> 4) & 0xF) - (ascProData[ix] & 0xF);
    }

    return size;
}

void SSPutStr2(u16 x, u16 y, u8 atr, const s8 *str) {
    if (No_Trans) {
        return;
    }

    ppgSetupCurrentDataList(&ppgScrList);
    setFilterMode(0);
    njColorBlendingMode(0, 1);
    scrscrntex[0].col = scrscrntex[3].col = -1;
    scrscrntex[0].z = scrscrntex[3].z = PrioBase[1];
    njSetPaletteBankNumG(1, atr & 0x3F);
    x = (u16)(x * 8);
    y = (u16)(y * 8);

    while (*str != '\0') {
        SSPutStrTexInput(x, y, str);
        njDrawSprite(scrscrntex, 4, 1, 1);
        x = (u16)(x + 8);
        str++;
    }
}

void SSPutStrTexInputB(f32 x, f32 y, s8 *str, f32 sc) {
    s32 u = ((*str & 0xF) * 8) + 128;
    s32 v = ((*str & 0xF0) >> 4) * 8;

    scrscrntex[0].u = scrscrntex[1].u = (D_0079688C + u) / 256.0f;
    scrscrntex[2].u = scrscrntex[3].u = (D_00796894 + (u + 8)) / 256.0f;
    scrscrntex[0].v = scrscrntex[2].v = (D_00796890 + v) / 256.0f;
    scrscrntex[1].v = scrscrntex[3].v = (D_00796898 + (v + 8)) / 256.0f;
    scrscrntex[0].x = scrscrntex[1].x = x * Frame_Zoom_X;
    scrscrntex[2].x = scrscrntex[3].x = Frame_Zoom_X * (x + (8.0f * sc));
    scrscrntex[0].y = scrscrntex[2].y = y * Frame_Zoom_Y;
    scrscrntex[1].y = scrscrntex[3].y = Frame_Zoom_Y * (y + (8.0f * sc));
}

void SSPutStrTexInputB2(f32 x, f32 y, s8 str) {
    s32 u = str * 11;

    scrscrntex[0].u = scrscrntex[1].u = (0.5f + u) / 256.0f;
    scrscrntex[2].u = scrscrntex[3].u = (0.5f + (u + 11)) / 256.0f;
    scrscrntex[0].v = scrscrntex[2].v = (0.5f + 200.0f) / 256.0f;
    scrscrntex[1].v = scrscrntex[3].v = (0.5f + 208.0f) / 256.0f;
    scrscrntex[0].x = scrscrntex[1].x = x * Frame_Zoom_X;
    scrscrntex[2].x = scrscrntex[3].x = (11.0f + x) * Frame_Zoom_X;
    scrscrntex[0].y = scrscrntex[2].y = y * Frame_Zoom_Y;
    scrscrntex[1].y = scrscrntex[3].y = (8.0f + y) * Frame_Zoom_Y;
}

void SSPutStr_Bigger(u16 x, u16 y, u8 atr, s8 *str, f32 sc, u8 gr, u16 priority) {
    f32 xx;
    f32 yy;
    u8 i;

    if (No_Trans) {
        return;
    }

    ppgSetupCurrentDataList(&ppgScrList);
    SSSetUVOffsetForScale(256.0f, 256.0f, sc);
    setFilterMode(0);
    njColorBlendingMode(0, 1);

    for (i = 0; i < 4; i++) {
        scrscrntex[i].col = bigger_col_tbl[gr][i];
    }

    scrscrntex[0].z = scrscrntex[1].z = scrscrntex[2].z = scrscrntex[3].z = PrioBase[priority];
    njSetPaletteBankNumG(1, atr & 0x3F);
    xx = x;
    yy = y;

    while (*str != '\0') {
        if (*str == '$') {
            xx += sc * 4.0f;
            str++;
            continue;
        }

        SSPutStrTexInputB(xx, yy, str, sc);
        njDrawTexture(scrscrntex, 4, 1, 1);
        xx += sc * 8.0f;
        str++;
    }
}

void SSPutDec(u16 x, u16 y, u8 atr, u8 dec, u8 size) {
    s8 str[3];
    u8 work;
    u8 num;
    u8 i;
    u8 zero_sw;

    if (No_Trans) {
        return;
    }

    if (size == 0) {
        return;
    }

    ppgSetupCurrentDataList(&ppgScrList);
    setFilterMode(0);
    njColorBlendingMode(0, 1);
    scrscrntex[0].col = scrscrntex[3].col = -1;
    scrscrntex[0].z = scrscrntex[3].z = PrioBase[2];
    njSetPaletteBankNumG(1, atr & 0x3F);
    x = (u16)(x * 8);
    y = (u16)(y * 8);
    zero_sw = 0;
    work = 100;

    for (i = 0; i < 3; i++) {
        for (num = 0; dec + 1 > work; dec = (u8)(dec - work), num++) {
        }

        str[i] = (s8)num;
        work = (u8)(work / 10);
    }

    SSPutStrTexInput2(x, y, (u8)str[2]);
    njDrawSprite(scrscrntex, 4, 1, 1);
    x = (u16)(x - 16);

    if (size == 3 && str[0] != 0) {
        SSPutStrTexInput2(x, y, (u8)str[0]);
        njDrawSprite(scrscrntex, 4, 1, 1);
        zero_sw = 1;
    }

    x = (u16)(x + 8);

    if (zero_sw == 1 || (size > 1 && str[1] != 0)) {
        SSPutStrTexInput2(x, y, (u8)str[1]);
        njDrawSprite(scrscrntex, 4, 1, 1);
    }
}

void SSPutDec3(u16 x, u16 y, u8 atr, s16 dec, u8 size, u8 gr, u16 priority) {
    s8 str[3];
    s16 work;
    u8 num;
    u8 i;
    u8 zero_sw;
    f32 xx;
    f32 yy;

    if (No_Trans) {
        return;
    }

    ppgSetupCurrentDataList(&ppgScrList);
    setFilterMode(0);
    njColorBlendingMode(0, 1);

    for (i = 0; i < 4; i++) {
        scrscrntex[i].col = bigger_col_tbl[gr][i];
    }

    scrscrntex[0].z = scrscrntex[1].z = scrscrntex[2].z = scrscrntex[3].z = PrioBase[priority];
    njSetPaletteBankNumG(1, atr & 0x3F);
    xx = x;
    yy = y;
    zero_sw = 0;
    work = 100;

    for (i = 0; i < 3; i++) {
        for (num = 0; dec + 1 > work; dec = (s16)(dec - work), num++) {
        }

        str[i] = (s8)num;
        work = (s16)(work / 10);
    }

    SSPutStrTexInputB2(xx, yy, str[2]);
    njDrawTexture(scrscrntex, 4, 4, 1);

    if (size == 0) {
        return;
    }

    xx -= 22.0f;

    if (size == 3 && str[0] != 0) {
        SSPutStrTexInputB2(xx, yy, str[0]);
        njDrawSprite(scrscrntex, 4, 4, 1);
        zero_sw = 1;
    }

    xx += 11.0f;

    if (zero_sw == 1 || (size > 1 && str[1] != 0)) {
        SSPutStrTexInputB2(xx, yy, str[1]);
        njDrawSprite(scrscrntex, 4, 4, 1);
    }
}

void scfont_put(u16 x, u16 y, u8 atr, u8 page, u8 cx, u8 cy, u16 priority) {
    s32 u;
    s32 v;

    if (No_Trans) {
        return;
    }

    ppgSetupCurrentDataList(&ppgScrList);
    setFilterMode(0);
    njColorBlendingMode(0, 1);
    scrscrntex[0].col = scrscrntex[3].col = -1;
    scrscrntex[0].z = scrscrntex[3].z = PrioBase[priority];
    njSetPaletteBankNumG(page, atr & 0x3F);
    x = (u16)(x * 8);
    y = (u16)(y * 8);
    u = cx * 8;
    v = cy * 8;

    if (atr & 0x80) {
        scrscrntex[3].u = (u - 0.5f) / 256.0f;
        scrscrntex[0].u = ((u + 8) - 0.5f) / 256.0f;
    } else {
        scrscrntex[0].u = (0.5f + u) / 256.0f;
        scrscrntex[3].u = (0.5f + (u + 8)) / 256.0f;
    }

    if (atr & 0x40) {
        scrscrntex[3].v = (v - 0.5f) / 256.0f;
        scrscrntex[0].v = ((v + 8) - 0.5f) / 256.0f;
    } else {
        scrscrntex[0].v = (0.5f + v) / 256.0f;
        scrscrntex[3].v = (0.5f + (v + 8)) / 256.0f;
    }

    scrscrntex[0].x = x * Frame_Zoom_X;
    scrscrntex[3].x = (x + 8) * Frame_Zoom_X;
    scrscrntex[0].y = y * Frame_Zoom_Y;
    scrscrntex[3].y = (y + 8) * Frame_Zoom_Y;
    njDrawSprite(scrscrntex, 4, page, 1);
}

void scfont_put2(u16 x, u16 y, u8 atr, u8 page, u8 cx, u8 cy) {
    sa_frame[y - 25][x].atr = atr;
    sa_frame[y - 25][x].page = page;
    sa_frame[y - 25][x].cx = cx;
    sa_frame[y - 25][x].cy = cy;
}

void scfont_sqput(u16 x, u16 y, u8 atr, u8 page, u8 cx1, u8 cy1, u8 cx2, u8 cy2, u16 priority) {
    s32 u1;
    s32 u2;
    s32 v1;
    s32 v2;

    if (No_Trans) {
        return;
    }

    ppgSetupCurrentDataList(&ppgScrList);
    setFilterMode(0);
    njColorBlendingMode(0, 1);
    scrscrntex[0].col = scrscrntex[3].col = -1;
    scrscrntex[0].z = scrscrntex[3].z = PrioBase[priority];
    njSetPaletteBankNumG(page, atr & 0x3F);
    x = (u16)(x * 8);
    y = (u16)(y * 8);
    u1 = cx1 * 8;
    u2 = u1 + (cx2 * 8);
    v1 = cy1 * 8;
    v2 = v1 + (cy2 * 8);

    if (atr & 0x80) {
        scrscrntex[3].u = (u1 - 0.5f) / 256.0f;
        scrscrntex[0].u = (u2 - 0.5f) / 256.0f;
    } else {
        scrscrntex[0].u = (0.5f + u1) / 256.0f;
        scrscrntex[3].u = (0.5f + u2) / 256.0f;
    }

    if (atr & 0x40) {
        scrscrntex[3].v = (v1 - 0.5f) / 256.0f;
        scrscrntex[0].v = (v2 - 0.5f) / 256.0f;
    } else {
        scrscrntex[0].v = (0.5f + v1) / 256.0f;
        scrscrntex[3].v = (0.5f + v2) / 256.0f;
    }

    scrscrntex[0].x = x * Frame_Zoom_X;
    scrscrntex[3].x = Frame_Zoom_X * (x + (u2 - u1));
    scrscrntex[0].y = y * Frame_Zoom_Y;
    scrscrntex[3].y = Frame_Zoom_Y * (y + (v2 - v1));
    njDrawSprite(scrscrntex, 4, page, 1);
}

void scfont_sqput2(u16 x, u16 y, u8 atr, u8 inverse, u8 page, u8 cx1, u8 cy1, u8 cx2, u8 cy2) {
    u8 i;
    u8 j;

    if (inverse == 0) {
        for (j = 0; j < cy2; j++) {
            for (i = 0; i < cx2; i++) {
                sa_frame[y - 25 + j][x + i].atr = atr;
                sa_frame[y - 25 + j][x + i].page = page;
                sa_frame[y - 25 + j][x + i].cx = cx1 + i;
                sa_frame[y - 25 + j][x + i].cy = cy1 + j;
            }
        }
    } else {
        for (j = 0; j < cy2; j++) {
            for (i = 0; i < cx2; i++) {
                sa_frame[y - 25 + j][x + i].atr = atr;
                sa_frame[y - 25 + j][x + i].page = page;
                sa_frame[y - 25 + j][x + i].cx = (cx1 + (cx2 - 1)) - i;
                sa_frame[y - 25 + j][x + i].cy = cy1 + j;
            }
        }
    }
}

void scfont_sqput3(u16 x, u16 y, u8 atr, u8 page, u16 cx1, u16 cy1, u16 cx2, u16 cy2, u8 gr, u16 priority) {
    s32 u1;
    s32 u2;
    s32 v1;
    s32 v2;
    u8 i;

    if (No_Trans) {
        return;
    }

    ppgSetupCurrentDataList(&ppgScrList);
    setFilterMode(0);
    njColorBlendingMode(0, 1);

    for (i = 0; i < 4; i++) {
        scrscrntex[i].col = bigger_col_tbl[gr][i];
    }

    scrscrntex[0].z = scrscrntex[1].z = scrscrntex[2].z = scrscrntex[3].z = PrioBase[priority];
    njSetPaletteBankNumG(page, atr & 0x3F);
    u1 = cx1;
    u2 = u1 + cx2;
    v1 = cy1;
    v2 = v1 + cy2;
    scrscrntex[0].u = scrscrntex[1].u = (0.5f + u1) / 256.0f;
    scrscrntex[2].u = scrscrntex[3].u = (0.5f + u2) / 256.0f;
    scrscrntex[0].v = scrscrntex[2].v = (0.5f + v1) / 256.0f;
    scrscrntex[1].v = scrscrntex[3].v = (0.5f + v2) / 256.0f;
    scrscrntex[0].x = scrscrntex[1].x = x * Frame_Zoom_X;
    scrscrntex[2].x = scrscrntex[3].x = Frame_Zoom_X * (x + (u2 - u1));
    scrscrntex[0].y = scrscrntex[2].y = y * Frame_Zoom_Y;
    scrscrntex[1].y = scrscrntex[3].y = Frame_Zoom_Y * (y + (v2 - v1));
    njDrawTexture(scrscrntex, 4, page, 1);
}

void sc_clear(u16 sposx, u16 sposy, u16 eposx, u16 eposy) {
    u16 i;
    u16 j;

    for (j = 0; j < (eposy - sposy) + 1; j++) {
        for (i = 0; i < (eposx - sposx) + 1; i++) {
            sa_frame[sposy - 25 + j][sposx + i].atr = 0;
            sa_frame[sposy - 25 + j][sposx + i].page = 0;
            sa_frame[sposy - 25 + j][sposx + i].cx = 0;
            sa_frame[sposy - 25 + j][sposx + i].cy = 0;
        }
    }
}

void vital_put(u8 Pl_Num, s8 atr, s16 vital, u8 kind, u16 priority) {
    if (No_Trans) {
        return;
    }

    if (vital == 0) {
        return;
    }

    ppgSetupCurrentDataList(&ppgScrList);
    setFilterMode(0);

    if (vital == -1) {
        vital = 0;
    }

    scrscrntex[0].z = scrscrntex[3].z = PrioBase[priority];
    njSetPaletteBankNumG(0, atr & 0x3F);

    if (kind) {
        scrscrntex[0].u = 0.0f;
        scrscrntex[3].u = 8.0f / 256.0f;
        scrscrntex[0].v = (0.5f + 64.0f) / 256.0f;
        scrscrntex[3].v = (0.5f + 72.0f) / 256.0f;
    } else {
        scrscrntex[0].u = 0.0f;
        scrscrntex[3].u = 8.0f / 256.0f;
        scrscrntex[0].v = (0.5f + 72.0f) / 256.0f;
        scrscrntex[3].v = (0.5f + 80.0f) / 256.0f;
    }

    if (Pl_Num == 0) {
        scrscrntex[0].x = (168 - vital) * Frame_Zoom_X;
        scrscrntex[3].x = 168.0f * Frame_Zoom_X;
    } else {
        scrscrntex[0].x = 216.0f * Frame_Zoom_X;
        scrscrntex[3].x = (vital + 216) * Frame_Zoom_X;
    }

    scrscrntex[0].y = 16.0f * Frame_Zoom_Y;
    scrscrntex[3].y = 24.0f * Frame_Zoom_Y;
    njColorBlendingMode(0, 1);
    scrscrntex[0].col = scrscrntex[3].col = -1;
    njDrawSprite(scrscrntex, 4, 0, 1);
}

void silver_vital_put(u8 Pl_Num) {
    if (No_Trans) {
        return;
    }

    ppgSetupCurrentDataList(&ppgScrList);
    setFilterMode(0);
    scrscrntex[0].z = scrscrntex[3].z = PrioBase[2];
    njSetPaletteBankNumG(0, 9);
    scrscrntex[0].u = 224.0f / 256.0f;
    scrscrntex[3].u = 232.0f / 256.0f;
    scrscrntex[0].v = (0.5f + 176.0f) / 256.0f;
    scrscrntex[3].v = (0.5f + 184.0f) / 256.0f;

    if (Pl_Num == 0) {
        scrscrntex[0].x = 8.0f * Frame_Zoom_X;
        scrscrntex[3].x = 168.0f * Frame_Zoom_X;
    } else {
        scrscrntex[0].x = 216.0f * Frame_Zoom_X;
        scrscrntex[3].x = 376.0f * Frame_Zoom_X;
    }

    scrscrntex[0].y = 16.0f * Frame_Zoom_Y;
    scrscrntex[3].y = 24.0f * Frame_Zoom_Y;
    njColorBlendingMode(0, 1);
    scrscrntex[0].col = scrscrntex[3].col = -1;
    njDrawSprite(scrscrntex, 4, 0, 1);
}

void vital_base_put(u8 Pl_Num) {
    PAL_CURSOR vtx;
    PAL_CURSOR_P pos[4];
    PAL_CURSOR_COL col;

    if (No_Trans || SA_shadow_on) {
        return;
    }

    njColorBlendingMode(0, 1);
    vtx.p = pos;
    vtx.col = &col;
    col.color = 0x40000000;

    if (Pl_Num == 0) {
        pos[0].x = 8.0f * Frame_Zoom_X;
        pos[3].x = 168.0f * Frame_Zoom_X;
    } else {
        pos[0].x = 216.0f * Frame_Zoom_X;
        pos[3].x = 376.0f * Frame_Zoom_X;
    }

    pos[0].y = 18.0f * Frame_Zoom_Y;
    pos[3].y = 23.0f * Frame_Zoom_Y;
    pos[1].x = pos[3].x;
    pos[1].y = pos[0].y;
    pos[2].x = pos[0].x;
    pos[2].y = pos[3].y;
    njDrawPolygon2D(&vtx, 4, PrioBase[4], 0x60, 2);
}

void spgauge_base_put(u8 Pl_Num, s16 len) {
    PAL_CURSOR vtx;
    PAL_CURSOR_P pos[4];
    PAL_CURSOR_COL col;

    if (omop_cockpit == 0) {
        return;
    }

    if (omop_sa_bar_disp[Pl_Num] == 0) {
        return;
    }

    if (No_Trans || SA_shadow_on) {
        return;
    }

    njColorBlendingMode(0, 1);
    vtx.p = pos;
    vtx.col = &col;
    col.color = 0x80000000;

    if (Pl_Num == 0) {
        pos[0].x = 48.0f * Frame_Zoom_X;
        pos[3].x = Frame_Zoom_X * ((len * 8) + 48);
    } else {
        pos[0].x = 336.0f * Frame_Zoom_X;
        pos[3].x = Frame_Zoom_X * (336 - (len * 8));
    }

    pos[0].y = 210.0f * Frame_Zoom_Y;
    pos[3].y = 217.0f * Frame_Zoom_Y;
    pos[1].x = pos[3].x;
    pos[1].y = pos[0].y;
    pos[2].x = pos[0].x;
    pos[2].y = pos[3].y;
    njDrawPolygon2D(&vtx, 4, PrioBase[4], 0x60, 2);
}

void stun_put(u8 Pl_Num, u8 stun) {
    if (No_Trans) {
        return;
    }

    if (stun == 0) {
        return;
    }

    if (omop_st_bar_disp[Pl_Num] == 0) {
        return;
    }

    ppgSetupCurrentDataList(&ppgScrList);
    setFilterMode(0);
    scrscrntex[0].z = scrscrntex[3].z = PrioBase[4];
    njSetPaletteBankNumG(0, 10);
    scrscrntex[0].u = 0.0f;
    scrscrntex[3].u = 8.0f / 256.0f;
    scrscrntex[0].v = (0.5f + 96.0f) / 256.0f;
    scrscrntex[3].v = (0.5f + 104.0f) / 256.0f;

    if (Pl_Num == 0) {
        scrscrntex[0].x = (168 - stun) * Frame_Zoom_X;
        scrscrntex[3].x = 168.0f * Frame_Zoom_X;
    } else {
        scrscrntex[0].x = 216.0f * Frame_Zoom_X;
        scrscrntex[3].x = (stun + 216) * Frame_Zoom_X;
    }

    scrscrntex[0].y = 24.0f * Frame_Zoom_Y;
    scrscrntex[3].y = 32.0f * Frame_Zoom_Y;
    scrscrntex[0].col = scrscrntex[3].col = -1;
    njDrawSprite(scrscrntex, 4, 0, 0);
}

void stun_base_put(u8 Pl_Num, s16 len) {
    PAL_CURSOR vtx;
    PAL_CURSOR_P pos[4];
    PAL_CURSOR_COL col;

    if (No_Trans || SA_shadow_on) {
        return;
    }

    njColorBlendingMode(0, 1);
    vtx.p = pos;
    vtx.col = &col;
    col.color = 0x90000000;

    if (Pl_Num == 0) {
        pos[0].x = Frame_Zoom_X * (168 - (len * 8));
        pos[3].x = 168.0f * Frame_Zoom_X;
    } else {
        pos[0].x = 216.0f * Frame_Zoom_X;
        pos[3].x = Frame_Zoom_X * ((len * 8) + 216);
    }

    pos[0].y = 25.0f * Frame_Zoom_Y;
    pos[3].y = 31.0f * Frame_Zoom_Y;
    pos[1].x = pos[3].x;
    pos[1].y = pos[0].y;
    pos[2].x = pos[0].x;
    pos[2].y = pos[3].y;
    njDrawPolygon2D(&vtx, 4, PrioBase[4], 0x60, 2);
}

void WipeInit(void) {
    WipeLimit = 0;
}

s32 WipeOut(u8 type) {
    PAL_CURSOR wipe_pc;
    PAL_CURSOR_P wipe_p[4];
    PAL_CURSOR_COL wipe_col[4];
    s32 i;
    s32 dmylim;

    if (WipeLimit > 7) {
        overwrite_panel(0xFF000000, 0);
    }

    if (WipeLimit == 9) {
        overwrite_panel(0xFF000000, 0);
        return 1;
    }

    if (!No_Trans) {
        if (WipeLimit > 7) {
            dmylim = 7;
        } else {
            dmylim = WipeLimit;
        }

        wipe_pc.p = wipe_p;
        wipe_pc.col = wipe_col;
        wipe_pc.tex = 0;
        wipe_pc.num = 4;
        wipe_col[0].color = wipe_col[1].color = wipe_col[2].color = wipe_col[3].color = 0xFF000000;

        if (type == 0) {
            wipe_p[0].x = wipe_p[2].x = 0.0f;
            wipe_p[1].x = wipe_p[3].x = 384.0f;

            for (i = 224; i > 0; i -= 8) {
                wipe_p[0].y = wipe_p[1].y = (f32)i;
                wipe_p[2].y = wipe_p[3].y = (f32)(i - (dmylim + 1));
                njDrawPolygon2D(&wipe_pc, 4, PrioBase[0], 0x20, 2);
            }
        } else if (WipeLimit != 8) {
            wipe_p[0].y = wipe_p[1].y = 0.0f;
            wipe_p[2].y = wipe_p[3].y = 224.0f;

            for (i = -224; i < 384; i += 8) {
                wipe_p[0].x = (f32)i;
                wipe_p[1].x = (f32)(i + dmylim + 1);
                wipe_p[2].x = 224.0f + wipe_p[0].x;
                wipe_p[3].x = 224.0f + wipe_p[1].x;
                njDrawPolygon2D(&wipe_pc, 4, PrioBase[0], 0x20, 2);
            }
        }
    }

    WipeLimit = (u8)(WipeLimit + 1);
    return 0;
}

s32 WipeIn(u8 type) {
    PAL_CURSOR wipe_pc;
    PAL_CURSOR_P wipe_p[4];
    PAL_CURSOR_COL wipe_col[4];
    s32 i;

    if (WipeLimit == 9) {
        return 1;
    }

    if ((WipeLimit != 8) && (!No_Trans)) {
        wipe_pc.p = wipe_p;
        wipe_pc.col = wipe_col;
        wipe_pc.tex = 0;
        wipe_pc.num = 4;
        wipe_col[0].color = wipe_col[1].color = wipe_col[2].color = wipe_col[3].color = 0xFF000000;

        if (type == 0) {
            wipe_p[0].x = wipe_p[2].x = 0.0f;
            wipe_p[1].x = wipe_p[3].x = 384.0f;

            for (i = 0; i < 224; i += 8) {
                wipe_p[0].y = wipe_p[1].y = (f32)i;
                wipe_p[2].y = wipe_p[3].y = (f32)((i + 8) - (WipeLimit + 1));
                njDrawPolygon2D(&wipe_pc, 4, PrioBase[0], 0x20, 2);
            }
        } else {
            wipe_p[0].y = wipe_p[1].y = 0.0f;
            wipe_p[2].y = wipe_p[3].y = 224.0f;

            for (i = -224; i < 384; i += 8) {
                wipe_p[0].x = (f32)i;
                wipe_p[1].x = (f32)((i + 8) - (WipeLimit + 1));
                wipe_p[2].x = 224.0f + wipe_p[0].x;
                wipe_p[3].x = 224.0f + wipe_p[1].x;
                njDrawPolygon2D(&wipe_pc, 4, PrioBase[0], 0x20, 2);
            }
        }
    }

    WipeLimit = (u8)(WipeLimit + 1);
    return 0;
}

void FadeInit(void) {
    FadeLimit = 1;
}

s32 FadeOut(u8 type, u8 step, u8 priority) {
    PAL_CURSOR fade_pc;
    PAL_CURSOR_P fade_p[4];
    PAL_CURSOR_COL fade_col[4];
    u32 Alpha;
    u8 i;
    u8 flag;

    Alpha = 0xFF000000;
    flag = 0;

    if (No_Trans) {
        return 0;
    }

    njColorBlendingMode(0, 1);
    fade_pc.p = fade_p;
    fade_pc.col = fade_col;
    fade_pc.num = 4;

    if (FadeLimit * step < 255) {
        Alpha = (FadeLimit * step) << 24;
    } else {
        flag = 1;
    }

    if (type == 0) {
        Alpha |= 0x00FFFFFF;
    }

    for (i = 0; i < 4; i++) {
        fade_col[i].color = Alpha;
        fade_p[i].x = (f32)Fade_Pos_tbl[i * 2];
        fade_p[i].y = (f32)Fade_Pos_tbl[i * 2 + 1];
    }

    njDrawPolygon2D(&fade_pc, 4, PrioBase[priority], 0x60, 8);

    if (flag) {
        return 1;
    }

    FadeLimit = (u8)(FadeLimit + 1);
    return 0;
}

s32 FadeIn(u8 type, u8 step, u8 priority) {
    PAL_CURSOR fade_pc;
    PAL_CURSOR_P fade_p[4];
    PAL_CURSOR_COL fade_col[4];
    u32 Alpha;
    u8 i;
    u8 flag;

    Alpha = 0;
    flag = 0;

    if (No_Trans) {
        return 0;
    }

    njColorBlendingMode(0, 1);
    fade_pc.p = fade_p;
    fade_pc.col = fade_col;
    fade_pc.num = 4;

    if (FadeLimit * step < 255) {
        Alpha = (255 - FadeLimit * step) << 24;
    } else {
        flag = 1;
    }

    if (type == 0) {
        Alpha |= 0x00FFFFFF;
    }

    for (i = 0; i < 4; i++) {
        fade_col[i].color = Alpha;
        fade_p[i].x = (f32)Fade_Pos_tbl[i * 2];
        fade_p[i].y = (f32)Fade_Pos_tbl[i * 2 + 1];
    }

    njDrawPolygon2D(&fade_pc, 4, PrioBase[priority], 0x60, 8);

    if (flag) {
        return 1;
    }

    FadeLimit = (u8)(FadeLimit + 1);
    return 0;
}

void ToneDown(u8 tone, u8 priority) {
    PAL_CURSOR tone_pc;
    PAL_CURSOR_P tone_p[4];
    PAL_CURSOR_COL tone_col[4];
    u8 i;

    if (No_Trans) {
        return;
    }

    njColorBlendingMode(0, 1);
    tone_pc.p = tone_p;
    tone_pc.col = tone_col;
    tone_pc.num = 4;

    for (i = 0; i < 4; i++) {
        tone_col[i].color = (u32)tone << 24;
        tone_p[i].x = (f32)Fade_Pos_tbl[i * 2];
        tone_p[i].y = (f32)Fade_Pos_tbl[i * 2 + 1];
    }

    njDrawPolygon2D(&tone_pc, 4, PrioBase[priority], 0x60, 8);
}

void player_name(void) {
    u8 pl1;
    u8 pl2;

    if (omop_cockpit == 0) {
        return;
    }

    if (No_Trans) {
        return;
    }

    ppgSetupCurrentDataList(&ppgScrList);
    pl1 = My_char[0];
    pl2 = My_char[1];
    pl1 += chkNameAkuma(pl1, 6);
    pl2 += chkNameAkuma(pl2, 6);
    scfont_sqput(6, 3, 1, 1, Player_Name_Pos_TBL[pl1][0], Player_Name_Pos_TBL[pl1][1], 5, 1, 2);
    scfont_sqput(37, 3, 1, 1, Player_Name_Pos_TBL[pl2][0], Player_Name_Pos_TBL[pl2][1], 5, 1, 2);
}

void stun_mark_write(u8 Pl_Num, s16 Len) {
    s16 tlen;

    if (No_Trans) {
        return;
    }

    if (omop_st_bar_disp[Pl_Num] == 0) {
        return;
    }

    ppgSetupCurrentDataList(&ppgScrList);
    tlen = (s16)(Len - 7);
    scfont_sqput(smark_pos_tbl[tlen][Pl_Num], 3, 10, 0, (smark_kind_tbl[tlen] * 4) + 1, 2,
        smark_kind_tbl[tlen] + 4, 1, 2);
}

void max_mark_write(s8 Pl_Num, u8 Gauge_Len, u8 Mchar, u8 Mass_Len) {
    if (Pl_Num == 0) {
        scfont_sqput2(Mass_Len + 6, 26, 17, 0, 0, Max_Pos_TBL[Mchar - 5][0], Max_Pos_TBL[Mchar - 5][1], Mchar, 1);
    } else {
        scfont_sqput2(42 - Gauge_Len + Mass_Len, 26, 17, 0, 0, Max_Pos_TBL[Mchar - 5][0],
            Max_Pos_TBL[Mchar - 5][1], Mchar, 1);
    }
}

void SF3_logo(u8 step) {
    s32 i;
    Vertex pos[4];

    if (No_Trans) {
        return;
    }

    ppgSetupCurrentDataList(&ppgScrList);
    setFilterMode(0);
    njColorBlendingMode(0, 1);
    njSetPaletteBankNumG(0, 29);
    pos[0].z = pos[1].z = pos[2].z = pos[3].z = PrioBase[2];

    if (step < 9) {
        pos[0].x = pos[1].x = 128.0f;
        pos[2].y = pos[3].y = 128.0f;
        pos[0].s = pos[1].s = (0.5f + pos[0].x) / 256.0f;
        pos[2].t = pos[3].t = (0.5f + 240.0f) / 256.0f;

        for (i = 48; i > 0; i -= 8) {
            pos[0].y = i + 80;
            pos[1].y = pos[0].y - step;
            pos[2].x = 176 - i;
            pos[3].x = pos[2].x + step;
            pos[0].t = (0.5f + (i + 192)) / 256.0f;
            pos[1].t = (0.5f + ((i + 192) - step)) / 256.0f;
            pos[2].s = (0.5f + (176 - i)) / 256.0f;
            pos[3].s = (0.5f + ((176 - i) + step)) / 256.0f;
            ppgWriteQuadWithST_B(pos, (u32)-1, 0, 0, -1);
        }

        pos[0].y = pos[1].y = 80.0f;
        pos[2].y = pos[3].y = 128.0f;
        pos[0].t = pos[1].t = (0.5f + 192.0f) / 256.0f;
        pos[2].t = pos[3].t = (0.5f + 240.0f) / 256.0f;

        for (i = 128; i < 208; i += 8) {
            pos[0].x = i;
            pos[1].x = i + step;
            pos[2].x = 48.0f + pos[0].x;
            pos[3].x = 48.0f + pos[1].x;
            pos[0].s = (0.5f + pos[0].x) / 256.0f;
            pos[1].s = (0.5f + pos[1].x) / 256.0f;
            pos[2].s = (0.5f + pos[2].x) / 256.0f;
            pos[3].s = (0.5f + pos[3].x) / 256.0f;
            ppgWriteQuadWithST_B(pos, (u32)-1, 0, 0, -1);
        }

        pos[0].y = pos[1].y = 80.0f;
        pos[2].x = pos[3].x = 256.0f;
        pos[0].t = pos[1].t = (0.5f + 192.0f) / 256.0f;
        pos[2].s = pos[3].s = (0.5f + 256.0f) / 256.0f;

        for (i = 0; i < 48; i += 8) {
            pos[0].x = i + 208;
            pos[1].x = pos[0].x + step;
            pos[2].y = 128 - i;
            pos[3].y = pos[2].y - step;
            pos[0].s = (0.5f + pos[0].x) / 256.0f;
            pos[1].s = (0.5f + pos[1].x) / 256.0f;
            pos[2].t = (0.5f + (240 - i)) / 256.0f;
            pos[3].t = (0.5f + ((240 - i) - step)) / 256.0f;
            ppgWriteQuadWithST_B(pos, (u32)-1, 0, 0, -1);
        }
    } else {
        step -= 8;
        pos[0].x = pos[1].x = 128.0f;
        pos[2].y = pos[3].y = 128.0f;
        pos[0].s = pos[1].s = (0.5f + pos[0].x) / 256.0f;
        pos[2].t = pos[3].t = (0.5f + 240.0f) / 256.0f;

        for (i = 40; i >= 0; i -= 8) {
            pos[1].y = i + 80;
            pos[0].y = (8.0f + pos[1].y) - step;
            pos[3].x = 176 - i;
            pos[2].x = (pos[3].x - 8.0f) + step;
            pos[0].t = (0.5f + ((i + 200) - step)) / 256.0f;
            pos[1].t = (0.5f + (i + 192)) / 256.0f;
            pos[2].s = (0.5f + ((168 - i) + step)) / 256.0f;
            pos[3].s = (0.5f + (176 - i)) / 256.0f;
            ppgWriteQuadWithST_B(pos, (u32)-1, 0, 0, -1);
        }

        pos[0].y = pos[1].y = 80.0f;
        pos[2].y = pos[3].y = 128.0f;
        pos[0].t = pos[1].t = (0.5f + 192.0f) / 256.0f;
        pos[2].t = pos[3].t = (0.5f + 240.0f) / 256.0f;

        for (i = 128; i < 208; i += 8) {
            pos[0].x = i + step;
            pos[1].x = i + 8;
            pos[2].x = 48.0f + pos[0].x;
            pos[3].x = 48.0f + pos[1].x;
            pos[0].s = (0.5f + pos[0].x) / 256.0f;
            pos[1].s = (0.5f + pos[1].x) / 256.0f;
            pos[2].s = (0.5f + pos[2].x) / 256.0f;
            pos[3].s = (0.5f + pos[3].x) / 256.0f;
            ppgWriteQuadWithST_B(pos, (u32)-1, 0, 0, -1);
        }

        pos[0].y = pos[1].y = 80.0f;
        pos[2].x = pos[3].x = 256.0f;
        pos[0].t = pos[1].t = (0.5f + 192.0f) / 256.0f;
        pos[2].s = pos[3].s = (0.5f + 256.0f) / 256.0f;

        for (i = 0; i < 48; i += 8) {
            pos[0].x = i + 208 + step;
            pos[1].x = i + 216;
            pos[2].y = 128 - i - step;
            pos[3].y = 120 - i;
            pos[0].s = (0.5f + pos[0].x) / 256.0f;
            pos[1].s = (0.5f + pos[1].x) / 256.0f;
            pos[2].t = (0.5f + (240 - i - step)) / 256.0f;
            pos[3].t = (0.5f + (232 - i)) / 256.0f;
            ppgWriteQuadWithST_B(pos, (u32)-1, 0, 0, -1);
        }
    }
}

void player_face_init() {
    // Do nothing
}

void scfont_sqput_face(u16 x, u16 y, u16 atr, u8 page, u8 cx1, u8 cy1, u8 cx2, u8 cy2, u16 priority) {
    s32 u1;
    s32 u2;
    s32 v1;
    s32 v2;

    njColorBlendingMode(0, 1);
    scrscrntex[0].col = scrscrntex[3].col = -1;
    scrscrntex[0].z = scrscrntex[3].z = PrioBase[priority];
    njSetPaletteBankNumG(0, atr & 0x3FFF);
    x = (u16)(x * 8);
    y = (u16)(y * 8);
    u1 = cx1 * 8;
    u2 = u1 + (cx2 * 8);
    v1 = cy1 * 8;
    v2 = v1 + (cy2 * 8);

    if (atr & 0x8000) {
        scrscrntex[3].u = (u1 - 0.5f) / 256.0f;
        scrscrntex[0].u = (u2 - 0.5f) / 256.0f;
    } else {
        scrscrntex[0].u = (0.5f + u1) / 256.0f;
        scrscrntex[3].u = (0.5f + u2) / 256.0f;
    }

    if (atr & 0x4000) {
        scrscrntex[3].v = (v1 - 0.5f) / 256.0f;
        scrscrntex[0].v = (v2 - 0.5f) / 256.0f;
    } else {
        scrscrntex[0].v = (0.5f + v1) / 256.0f;
        scrscrntex[3].v = (0.5f + v2) / 256.0f;
    }

    scrscrntex[0].x = x * Frame_Zoom_X;
    scrscrntex[3].x = Frame_Zoom_X * (x + (u2 - u1));
    scrscrntex[0].y = y * Frame_Zoom_Y;
    scrscrntex[3].y = Frame_Zoom_Y * (y + (v2 - v1));
    njDrawSprite(scrscrntex, 4, page, 1);
}

void player_face(void) {
    u8 grade_tmp;

    if (omop_cockpit == 0) {
        return;
    }

    if (No_Trans) {
        return;
    }

    face_base_put();
    ppgSetupCurrentDataList(&ppgScrListFace);
    scfont_sqput_face(0, 3, (u16)(Player_Color[0] + (My_char[0] * 13)), 0, Face_Pos_TBL[My_char[0]][0],
        Face_Pos_TBL[My_char[0]][1], 5, 3, 2);

    if (My_char[1] == 0) {
        scfont_sqput_face(0x2B, 3, (u16)((Player_Color[1] + (My_char[1] * 13)) | 0x8000), 0, Face_Pos_TBL[20][0],
            Face_Pos_TBL[20][1], 5, 3, 2);
    } else {
        scfont_sqput_face(0x2B, 3, (u16)((Player_Color[1] + (My_char[1] * 13)) | 0x8000), 0,
            Face_Pos_TBL[My_char[1]][0], Face_Pos_TBL[My_char[1]][1], 5, 3, 2);
    }

    ppgSetupCurrentDataList(&ppgScrList);
    scfont_put(5, 3, 1, 0, 0, 19, 2);
    scfont_put(5, 4, 1, 0, 0, 20, 2);
    scfont_put(42, 3, 129, 0, 0, 19, 2);
    scfont_put(42, 4, 129, 0, 0, 20, 2);

    if (Play_Type == 0) {
        return;
    }

    if (Keep_Grade[Champion] == 0) {
        return;
    }

    grade_tmp = (u8)(Keep_Grade[Champion] - 1);

    if (grade_tmp < 0x18) {
        scfont_sqput((u16)((Champion * 41) + 1), 1, 27, 2, Grade_Pos_TBL[grade_tmp][0], Grade_Pos_TBL[grade_tmp][1], 5,
            1, 2);
    } else {
        scfont_sqput((u16)((Champion * 41) + 1), 1, 28, 2, Grade_Pos_TBL[grade_tmp][0], Grade_Pos_TBL[grade_tmp][1], 5,
            1, 2);
    }
}

void face_base_put(void) {
    PAL_CURSOR vtx;
    PAL_CURSOR_P pos[4];
    PAL_CURSOR_COL col;

    if (No_Trans || SA_shadow_on) {
        return;
    }

    njColorBlendingMode(0, 1);
    vtx.p = pos;
    vtx.col = &col;
    col.color = 0x50000000;
    pos[0].x = 5.6f * Frame_Zoom_X;
    pos[3].x = 34.4f * Frame_Zoom_X;
    pos[0].y = 25.0f * Frame_Zoom_Y;
    pos[3].y = 45.0f * Frame_Zoom_Y;
    pos[1].x = pos[3].x;
    pos[1].y = pos[0].y;
    pos[2].x = pos[0].x;
    pos[2].y = pos[3].y;
    njDrawPolygon2D(&vtx, 4, PrioBase[4], 0x60, 2);
    pos[0].x = 348.8f * Frame_Zoom_X;
    pos[3].x = 377.6f * Frame_Zoom_X;
    pos[1].x = pos[3].x;
    pos[2].x = pos[0].x;
    njDrawPolygon2D(&vtx, 4, PrioBase[4], 0x60, 2);
}

void hnc_set(u8 num, u8 atr) {
    u8 i;

    if (No_Trans) {
        return;
    }

    ppgSetupCurrentDataList(&ppgScrList);
    setFilterMode(0);
    scrscrntex[0].z = scrscrntex[3].z = PrioBase[2];
    njSetPaletteBankNumG(1, atr & 0x3F);
    njColorBlendingMode(0, 1);

    for (i = 0; i < 2; i++) {
        if (i) {
            scrscrntex[0].u = (0.5f + 0.0f) / 256.0f;
            scrscrntex[3].u = (0.5f + (num * 8)) / 256.0f;
            scrscrntex[0].v = (0.5f + 96.0f) / 256.0f;
            scrscrntex[3].v = (0.5f + 120.0f) / 256.0f;
            scrscrntex[0].x = 184.0f * Frame_Zoom_X;
            scrscrntex[3].x = Frame_Zoom_X * ((num + 23) * 8);
        } else {
            scrscrntex[0].u = (0.5f + ((23 - num) * 8)) / 256.0f;
            scrscrntex[3].u = (0.5f + 184.0f) / 256.0f;
            scrscrntex[0].v = (0.5f + 72.0f) / 256.0f;
            scrscrntex[3].v = (0.5f + 96.0f) / 256.0f;
            scrscrntex[0].x = Frame_Zoom_X * ((23 - num) * 8);
            scrscrntex[3].x = 184.0f * Frame_Zoom_X;
        }

        scrscrntex[0].y = 88.0f * Frame_Zoom_Y;
        scrscrntex[3].y = 112.0f * Frame_Zoom_Y;
        scrscrntex[0].col = scrscrntex[3].col = -1;
        njDrawSprite(scrscrntex, 4, 1, 1);
    }
}

void hnc_wipeinit(u8 atr) {
    Polygon dmyvtx[4];
    s16 i;
    s16 j;
    s16 k;

    ppgSetupCurrentDataList(&ppgScrList);
    setFilterMode(0);
    Hnc_Num = 0;
    scrscrntex[0].z = scrscrntex[1].z = scrscrntex[2].z = scrscrntex[3].z = PrioBase[2];
    njSetPaletteBankNumG(1, atr & 0x3F);
    njColorBlendingMode(0, 1);
    scrscrntex[0].col = scrscrntex[1].col = scrscrntex[2].col = scrscrntex[3].col = 0xFFFFFFFF;

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 26; j++) {
            for (k = 0; k < 4; k++) {
                scrscrntex[k].u = (f32)hnc_wipe_tbl1[j][k * 2] / 256.0f;
                scrscrntex[k].v = (f32)((i * 24) + hnc_wipe_tbl1[j][(k * 2) + 1]) / 256.0f;
                scrscrntex[k].x = Frame_Zoom_X * (f32)((i * 184) + hnc_wipe_tbl1[j][k * 2]);
                scrscrntex[k].y = Frame_Zoom_Y * (f32)(hnc_wipe_tbl1[j][(k * 2) + 1] + 16);
                dmyvtx[k] = scrscrntex[k];
            }

            if (!No_Trans) {
                njDrawTexture(dmyvtx, 4, 1, 1);
            }
        }
    }
}

s32 hnc_wipeout(u8 atr) {
    Polygon vtx[4];
    s32 i;
    s16 j;
    s32 k;
    s32 ipx;
    s32 ipy;
    s32 ipu;
    s32 ipv;
    s32 len;

    if (!No_Trans) {
        ppgSetupCurrentDataList(&ppgScrList);
        setFilterMode(0);
        njSetPaletteBankNumG(1, atr & 0x3F);
        njColorBlendingMode(0, 1);
        vtx[0].z = vtx[1].z = vtx[2].z = vtx[3].z = PrioBase[2];
        vtx[0].col = vtx[1].col = vtx[2].col = vtx[3].col = 0xFFFFFFFF;
        ipx = 8;
        ipy = 88;
        ipu = 8;
        ipv = 72;
        len = 8 - Hnc_Num;

        for (i = 0; i < 2; i++) {
            for (j = 0; j < 23; j++) {
                vtx[0].x = (f32)ipx;
                vtx[1].x = vtx[0].x - (f32)len;
                vtx[2].x = 16.0f + vtx[0].x;
                vtx[3].x = vtx[2].x - (f32)len;
                vtx[0].y = vtx[1].y = (f32)ipy;
                vtx[2].y = vtx[3].y = (f32)(ipy + 24);
                vtx[0].u = (f32)ipu;
                vtx[1].u = vtx[0].u - (f32)len;
                vtx[2].u = 16.0f + vtx[0].u;
                vtx[3].u = vtx[2].u - (f32)len;
                vtx[0].v = vtx[1].v = (f32)ipv;
                vtx[2].v = vtx[3].v = (f32)(ipv + 24);

                for (k = 0; k < 4; k++) {
                    vtx[k].x *= Frame_Zoom_X;
                    vtx[k].y *= Frame_Zoom_Y;
                    vtx[k].u /= 256.0f;
                    vtx[k].v /= 256.0f;
                }

                njDrawTexture(vtx, 4, 1, 1);
                ipx += 8;
                ipu += 8;
            }

            ipu = 8;
            ipv += 24;
        }

        ipx = 184;
        ipu = 0;
        ipv -= 24;

        for (j = 0; j < 2; j++) {
            vtx[0].x = vtx[1].x = (f32)ipx;
            vtx[2].x = vtx[0].x + (f32)(16 - (j * 8));
            vtx[3].x = vtx[2].x - (f32)len;
            vtx[0].y = (f32)ipy;
            vtx[1].y = vtx[0].y + ((24.0f * (f32)len) / 16.0f);
            vtx[2].y = vtx[3].y = vtx[0].y + (f32)(24 - (j * 12));
            vtx[0].u = vtx[1].u = (f32)ipu;
            vtx[2].u = vtx[0].u + (f32)(16 - (j * 8));
            vtx[3].u = vtx[2].u - (f32)len;
            vtx[0].v = (f32)ipv;
            vtx[1].v = vtx[0].v + ((24.0f * (f32)len) / 16.0f);
            vtx[2].v = vtx[3].v = vtx[0].v + (f32)(24 - (j * 12));

            for (k = 0; k < 4; k++) {
                vtx[k].x *= Frame_Zoom_X;
                vtx[k].y *= Frame_Zoom_Y;
                vtx[k].u /= 256.0f;
                vtx[k].v /= 256.0f;
            }

            njDrawTexture(vtx, 4, 1, 1);
            ipy += 12;
            ipv += 12;
        }
    }

    Hnc_Num = (s16)(Hnc_Num + 1);

    if (Hnc_Num == 8) {
        return 1;
    }

    return 0;
}

void ci_set(u8 type, u8 atr) {
    if (No_Trans) {
        return;
    }

    ppgSetupCurrentDataList(&ppgScrList);
    scfont_sqput(ci_tbl[type][4],
                 ci_tbl[type][5],
                 atr,
                 cip_tbl[type],
                 ci_tbl[type][0],
                 ci_tbl[type][1],
                 ci_tbl[type][2],
                 ci_tbl[type][3],
                 2);
}

void nw_set(u8 PL_num, u8 atr) {
    if (No_Trans) {
        return;
    }

    ppgSetupCurrentDataList(&ppgScrList);
    PL_num = (u8)(PL_num + chkNameAkuma(PL_num, 6));
    scfont_sqput(nwdata_tbl[PL_num][3],
                 9,
                 atr,
                 nwdata_tbl[PL_num][4],
                 nwdata_tbl[PL_num][0],
                 nwdata_tbl[PL_num][1],
                 nwdata_tbl[PL_num][2],
                 4,
                 2);
    scfont_sqput(nwdata_tbl[PL_num][5], 9, atr, 2, 17, 22, 13, 4, 2);
}

void score8x16_put(u16 x, u16 y, u8 atr, u8 chr) {
    if (No_Trans) {
        return;
    }

    ppgSetupCurrentDataList(&ppgScrList);
    scfont_sqput(x, y, atr, 0, chr, 6, 1, 2, 2);
}

void score16x24_put(u16 x, u16 y, u8 atr, u8 chr) {
    if (No_Trans) {
        return;
    }

    ppgSetupCurrentDataList(&ppgScrList);
    scfont_sqput(x, y, atr, 2, (u8)(chr * 2), 6, 2, 3, 2);
}

void combo_message_set(u8 pl, u8 kind, u8 x, u8 num, u8 hi, u8 low) {
    u8 xw;
    u8 xw2;

    if (No_Trans) {
        return;
    }

    ppgSetupCurrentDataList(&ppgScrList);

    if (num > combo_mtbl[kind][2]) {
        xw = combo_mtbl[kind][2];
        xw2 = (u8)(num - combo_mtbl[kind][2]);
    } else {
        xw = num;
        xw2 = 0;
    }

    switch (kind) {
    case 0:
    case 1:
    case 2:
        if (pl == 0) {
            if (hi != 0) {
                scfont_sqput(x, 7, 8, 0, hi, 6, 1, 2, 2);
            }

            if (num > 1) {
                scfont_sqput((u16)(x + 1), 7, 8, 0, low, 6, 1, 2, 2);
            }

            if (num > 3) {
                scfont_sqput((u16)(x + 3), 7, 8, 2, combo_mtbl[kind][0], combo_mtbl[kind][1], xw, 2, 2);
            }
        } else {
            scfont_sqput(xw2, 7, 8, 2, (u8)((combo_mtbl[kind][0] + combo_mtbl[kind][2]) - xw), combo_mtbl[kind][1], xw, 2, 2);

            if (xw2 > 1) {
                scfont_sqput((u16)(xw2 - 2), 7, 8, 0, low, 6, 1, 2, 2);
            }

            if (xw2 > 2 && hi != 0) {
                scfont_sqput((u16)(xw2 - 3), 7, 8, 0, hi, 6, 1, 2, 2);
            }
        }

        break;

    case 3:
    case 4:
    case 5:
    case 6:
        if (pl == 0) {
            scfont_sqput(x, 7, 8, 2, combo_mtbl[kind][0], combo_mtbl[kind][1], xw, 2, 2);
        } else {
            scfont_sqput(xw2, 7, 8, 2, (u8)((combo_mtbl[kind][0] + combo_mtbl[kind][2]) - xw), combo_mtbl[kind][1], xw, 2, 2);
        }

        break;
    }
}

void combo_pts_set(u8 pl, u8 x, u8 num, s8 *pts, s8 digit) {
    s8 i;
    s8 j;

    if (No_Trans) {
        return;
    }

    ppgSetupCurrentDataList(&ppgScrList);

    if (pl == 0) {
        for (i = digit, j = 1; i >= 0; i--, j++, x = (u8)(x + 1)) {
            score8x16_put(x, 10, 8, (u8)pts[i]);

            if (num - j == 0) {
                return;
            }
        }

        if (num < digit + 1) {
            return;
        }

        score8x16_put(x, 10, 8, 0);

        if (num < digit + 2) {
            return;
        }

        score8x16_put((u16)(x + 1), 10, 8, 0);

        if (num < digit + 3) {
            return;
        }

        scfont_put((u16)(x + 2), 11, 8, 0, 6, 13, 2);

        if (num < digit + 4) {
            return;
        }

        scfont_put((u16)(x + 3), 11, 8, 0, 7, 13, 2);
    } else {
        scfont_put(x, 11, 8, 0, 7, 13, 2);

        if (num > 1) {
            scfont_put((u16)(x - 1), 11, 8, 0, 6, 13, 2);
        }

        if (num > 2) {
            score8x16_put((u16)(x - 2), 10, 8, 0);
        }

        if (num > 3) {
            score8x16_put((u16)(x - 3), 10, 8, 0);
        }

        if (num > 4) {
            for (i = 0; i <= digit; i++, x = (u8)(x - 1)) {
                score8x16_put((u16)(x - 4), 10, 8, (u8)pts[i]);

                if (num - i == 0) {
                    break;
                }
            }
        }
    }
}

void naming_set(u8 pl, s16 place, u16 atr, u16 chr) {
    if (No_Trans) {
        return;
    }

    ppgSetupCurrentDataList(&ppgScrList);
    scfont_put((u16)(place + 13 + (pl * 27)), 0, (u8)atr, 0, rankname_pos_tbl[chr][0], rankname_pos_tbl[chr][1], 2);
}

void stun_gauge_waku_write(s16 p1len, s16 p2len) {
    if (omop_cockpit == 0) {
        return;
    }

    if (No_Trans) {
        return;
    }

    ppgSetupCurrentDataList(&ppgScrList);

    if (omop_st_bar_disp[0]) {
        scfont_sqput((u16)(21 - p1len), 3, 10, 0, (u8)(12 - p1len), (u8)(p1len + 1), (u8)p1len, 1, 3);
    } else {
        silver_stun_put(0, p1len);
    }

    scfont_sqput(11, 3, 1, 0, 2, (u8)(p1len + 1), (u8)(10 - p1len), 1, 3);

    if (omop_st_bar_disp[1]) {
        scfont_sqput(27, 3, 10, 0, 2, (u8)(p2len + 12), (u8)p2len, 1, 3);
    } else {
        silver_stun_put(1, p2len);
    }

    scfont_sqput((u16)(p2len + 27), 3, 1, 0, (u8)(p2len + 2), (u8)(p2len + 12), (u8)(10 - p2len), 1, 3);
}

void silver_stun_put(u8 Pl_Num, s16 len) {
    if (No_Trans) {
        return;
    }

    ppgSetupCurrentDataList(&ppgScrList);
    setFilterMode(0);
    scrscrntex[0].z = scrscrntex[3].z = PrioBase[3];
    njSetPaletteBankNumG(0, 1);
    scrscrntex[0].u = 240.0f / 256.0f;
    scrscrntex[3].u = 248.0f / 256.0f;
    scrscrntex[0].v = (0.5f + 176.0f) / 256.0f;
    scrscrntex[3].v = (0.5f + 184.0f) / 256.0f;

    if (Pl_Num == 0) {
        scrscrntex[0].x = Frame_Zoom_X * (f32)((21 - len) * 8);
        scrscrntex[3].x = 168.0f * Frame_Zoom_X;
    } else {
        scrscrntex[0].x = 216.0f * Frame_Zoom_X;
        scrscrntex[3].x = Frame_Zoom_X * (f32)((len * 8) + 216);
    }

    scrscrntex[0].y = 24.0f * Frame_Zoom_Y;
    scrscrntex[3].y = 32.0f * Frame_Zoom_Y;
    njColorBlendingMode(0, 1);
    scrscrntex[0].col = scrscrntex[3].col = 0xFFFFFFFF;
    njDrawSprite(scrscrntex, 4, 0, 1);
}

void overwrite_panel(u32 color, u8 priority) {
    PAL_CURSOR panel_pc;
    PAL_CURSOR_P panel_p[4];
    PAL_CURSOR_COL panel_col[4];
    u8 i;

    if (No_Trans) {
        return;
    }

    ppgSetupCurrentDataList(&ppgScrList);
    setFilterMode(0);
    njColorBlendingMode(0, 1);
    panel_pc.p = panel_p;
    panel_pc.col = panel_col;
    panel_pc.num = 4;

    for (i = 0; i < 4; i++) {
        panel_p[i].x = Fade_Pos_tbl[i * 2];
        panel_p[i].y = Fade_Pos_tbl[(i * 2) + 1];
        panel_col[i].color = color;
    }

    njDrawPolygon2D(&panel_pc, 4, PrioBase[priority], 0x60, 2);
}

void sa_stock_trans(s16 St_Num, s16 Spg_Col, s8 Stpl_Num) {
    if (Stpl_Num == 0) {
        scfont_put2(3, 25, sa_color_data_tbl[Spg_Col], 2, St_Num + 21, 4);
        scfont_put2(3, 26, sa_color_data_tbl[Spg_Col], 2, St_Num + 21, 5);
    } else {
        scfont_put2(44, 25, sa_color_data_tbl[Spg_Col], 2, St_Num + 21, 4);
        scfont_put2(44, 26, sa_color_data_tbl[Spg_Col], 2, St_Num + 21, 5);
    }
}

void sa_fullstock_trans(s16 St_Num, s16 Spg_Col, s8 Stpl_Num) {
    if (Stpl_Num == 0) {
        scfont_put2(1, 26, sa_color_data_tbl[Spg_Col], 2, St_Num + 21, 6);
    } else {
        scfont_put2(46, 26, sa_color_data_tbl[Spg_Col], 2, St_Num + 21, 7);
    }
}

void sa_number_write(s8 Stpl_Num, u16 x) {
    if (Stpl_Num == 0) {
        if (My_char[0] == 0) {
            scfont_sqput2(x, 26, 14, 0, 2, 27, 2, 2, 2);
        } else {
            scfont_sqput2(x, 26, 14, 0, 2, (Super_Arts[0] * 2) + 21, 2, 2, 2);
        }
    } else if (My_char[1] == 0) {
        scfont_sqput2(x, 26, 142, 1, 2, 27, 2, 2, 2);
    } else {
        scfont_sqput2(x, 26, 142, 1, 2, (Super_Arts[1] * 2) + 21, 2, 2, 2);
    }
}

void sc_ram_to_vram(s8 sc_num) {
    const u8 *sc_pos_ptr;
    const u8 *sc_uv_ptr;
    u16 loop;
    u16 i;

    sc_pos_ptr = sc_ram_vram_tbl[sc_num][0];
    sc_uv_ptr = sc_ram_vram_tbl[sc_num][1];
    loop = *sc_uv_ptr++;

    for (i = 0; i < loop; i++) {
        sa_frame[sc_pos_ptr[1] - 25][sc_pos_ptr[0]].atr = sa_ram_vram_col[sc_num][0];
        sa_frame[sc_pos_ptr[1] - 25][sc_pos_ptr[0]].page = sa_ram_vram_col[sc_num][1];
        sa_frame[sc_pos_ptr[1] - 25][sc_pos_ptr[0]].cx = *sc_uv_ptr++;
        sa_frame[sc_pos_ptr[1] - 25][sc_pos_ptr[0]].cy = *sc_uv_ptr++;
        sc_pos_ptr += 2;
    }
}

void sc_ram_to_vram_opc(s8 sc_num, s8 x, s8 y, u16 atr) {
    const u8 *sc_pos_ptr;
    const u8 *sc_uv_ptr;
    u16 loop;
    u16 i;

    if (No_Trans) {
        return;
    }

    ppgSetupCurrentDataList(&ppgScrList);
    sc_pos_ptr = sc_ram_vram_tbl[sc_num][0];
    sc_uv_ptr = sc_ram_vram_tbl[sc_num][1];
    loop = *sc_uv_ptr++;

    for (i = 0; i < loop; i++) {
        scfont_put(sc_pos_ptr[0] + x, sc_pos_ptr[1] + y, atr, sa_ram_vram_col[sc_num][1], sc_uv_ptr[0], sc_uv_ptr[1], 3);
        sc_uv_ptr += 2;
        sc_pos_ptr += 2;
    }
}

void sq_paint_chenge(u16 x, u16 y, u16 sx, u16 sy, u16 atr) {
    u16 i;
    u16 j;

    for (j = 0; j < sy; j++) {
        for (i = 0; i < sx; i++) {
            sa_frame[y - 25 + j][x + i].atr = atr;
        }
    }
}

void fade_cont_init(void) {
    FadeInit();
    fd_dat.fade_kind = fade_data_tbl[Fade_Number][0];
    fd_dat.fade = fade_data_tbl[Fade_Number][1];
    fd_dat.fade_prio = fade_data_tbl[Fade_Number][2];
}

void fade_cont_main(void) {
    u8 flag;

    flag = 0;

    switch (fd_dat.fade_kind) {
    case 0:
        flag = FadeIn(1, fd_dat.fade, fd_dat.fade_prio);
        break;

    case 1:
        flag = FadeOut(1, fd_dat.fade, fd_dat.fade_prio);
        break;

    case 2:
        flag = FadeIn(0, fd_dat.fade, fd_dat.fade_prio);
        break;

    case 3:
        flag = FadeOut(0, fd_dat.fade, fd_dat.fade_prio);
        break;
    }

    if (flag == 1) {
        Fade_Flag = 0;
    }
}

void Akaobi(void) {
    PAL_CURSOR apc;
    PAL_CURSOR_P ap[4];
    PAL_CURSOR_COL acol[4];
    u8 i;

    if (No_Trans) {
        return;
    }

    ppgSetupCurrentDataList(&ppgScrList);
    njColorBlendingMode(0, 1);
    apc.p = ap;
    apc.col = acol;
    apc.num = 4;

    for (i = 0; i < 4; i++) {
        ap[i].x = Akaobi_Pos_tbl[i * 2];
        ap[i].y = Akaobi_Pos_tbl[(i * 2) + 1];
        acol[i].color = 0xA0D00000;
    }

    njDrawPolygon2D(&apc, 4, PrioBase[2], 0x60, 2);
}

void Training_Disp_Work_Clear(void) {
    u8 i;

    for (i = 0; i < 2; i++) {
        tr_data[i].max_hitcombo = 0;
        tr_data[i].new_max_flag = 0;
        tr_data[i].frash_flag = 0;
        tr_data[i].frash_switch = 2;
        tr_data[i].damage = 0;
        tr_data[i].total_damage = 0;
        tr_data[i].disp_total_damage = 0;
    }
}

void Training_Damage_Set(s16 damage, s16 arg1, u8 kezuri) {
    u8 j;

    (void)arg1;

    if (Training_ID == 0) {
        j = 1;
    } else {
        j = 0;
    }

    if (damage == 0) {
        return;
    }

    tr_data[j].damage = damage;

    if (tr_data[j].damage > 999) {
        tr_data[j].damage = 999;
    }

    if (kezuri) {
        tr_data[j].disp_total_damage = damage;
        tr_data[j].total_damage = 0;
    } else {
        tr_data[j].total_damage = damage + tr_data[j].total_damage;
        tr_data[j].disp_total_damage = tr_data[j].total_damage;
    }

    if (tr_data[j].disp_total_damage > 999) {
        tr_data[j].disp_total_damage = 999;
    }
}

void Training_Data_Disp(void) {
    u8 i;
    u8 j;
    u8 atr;
    u8 gr;

    if (No_Trans) {
        return;
    }

    ppgSetupCurrentDataList(&ppgScrList);

    if (Disp_Attack_Data == 0) {
        return;
    }

    if (Training_ID == 0) {
        j = 1;
    } else {
        j = 0;
    }

    for (i = 0; i < 2; i++) {
        scfont_sqput3(i + Training_combo_pos_tbl[j],
                      i + 48,
                      13,
                      4,
                      0,
                      176,
                      76,
                      8,
                      i + 5,
                      Training_combo_prio_tbl[i] + (sa_pa_flag * 14) * i);
        SSPutDec3(i + (Training_combo_pos_tbl[j] + 158),
                  i + 48,
                  13,
                  tr_data[j].damage,
                  3,
                  i + 7,
                  Training_combo_prio_tbl[i] + (sa_pa_flag * 14) * i);
    }

    for (i = 0; i < 2; i++) {
        scfont_sqput3(i + (Training_combo_pos_tbl[j] + 1),
                      i + 58,
                      13,
                      4,
                      0,
                      184,
                      134,
                      8,
                      i + 5,
                      Training_combo_prio_tbl[i] + (sa_pa_flag * 14) * i);
        SSPutDec3(i + (Training_combo_pos_tbl[j] + 158),
                  i + 58,
                  13,
                  tr_data[j].disp_total_damage,
                  3,
                  i + 7,
                  Training_combo_prio_tbl[i] + (sa_pa_flag * 14) * i);
    }

    if (tr_data[j].frash_flag) {
        atr = 0x1E;
        gr = 9;
    } else {
        atr = 13;
        gr = 7;
    }

    tr_data[j].frash_switch--;

    if (tr_data[j].new_max_flag != 0 && tr_data[j].frash_switch == 0) {
        tr_data[j].frash_switch = 2;
        tr_data[j].new_max_flag--;
        tr_data[j].frash_flag = (u8)~tr_data[j].frash_flag;

        if (tr_data[j].frash_flag) {
            atr = 0x1E;
            gr = 0;
        }
    }

    for (i = 0; i < 2; i++) {
        scfont_sqput3(i + (Training_combo_pos_tbl[j] + 1),
                      i + 68,
                      13,
                      4,
                      0,
                      192,
                      98,
                      8,
                      i + 3,
                      Training_combo_prio_tbl[i] + (sa_pa_flag * 14) * i);
        SSPutDec3(i + (Training_combo_pos_tbl[j] + 158),
                  i + 68,
                  atr,
                  tr_data[j].max_hitcombo,
                  2,
                  gr + i,
                  Training_combo_prio_tbl[i] + (sa_pa_flag * 14) * i);
    }
}

void dispButtonImage(s32 px, s32 py, s32 pz, s32 sx, s32 sy, s32 cl, s32 ix) {
    Sprite prm;
    u32 col;

    if (No_Trans) {
        return;
    }

    col = ((u32)D_007A9AA8 & 0x00FFFFFF) | ((u32)(u8)(0xFF - (u8)cl) << 24);
    prm.texCode = (u32)ppgGetUsingTextureHandle(&ppgScrTex, 5) | ((u32)ppgGetUsingPaletteHandle(&ppgScrPalShot, 0) << 16);
    prm.v[0].x = (f32)px;
    prm.v[0].y = (f32)py;
    prm.v[3].x = (f32)(px + sx);
    prm.v[3].y = (f32)(py - sy);
    njCalcPoint(0, &prm.v[0], &prm.v[0]);
    njCalcPoint(0, &prm.v[3], &prm.v[3]);
    prm.v[0].z = prm.v[3].z = PrioBase[pz];
    prm.t[0].s = (f32)scrnAddTex1UV[ix][0] / 128.0f;
    prm.t[3].s = (f32)(scrnAddTex1UV[ix][0] + scrnAddTex1UV[ix][2]) / 128.0f;
    prm.t[0].t = (f32)scrnAddTex1UV[ix][1] / 128.0f;
    prm.t[3].t = (f32)(scrnAddTex1UV[ix][1] + scrnAddTex1UV[ix][3]) / 128.0f;
    xb_QueueButtonImage(&prm, col, 0, 0);
}

void dispButtonImage2(s32 px, s32 py, s32 pz, s32 sx, s32 sy, s32 cl, s32 ix) {
    Sprite prm;
    u32 col;
    f32 z;

    if (No_Trans) {
        return;
    }

    setFilterMode(1);
    col = 0x00FFFFFF | ((u32)(u8)(0xFF - (u8)cl) << 24);
    prm.texCode = (u32)ppgGetUsingTextureHandle(&ppgScrTex, 5) | ((u32)ppgGetUsingPaletteHandle(&ppgScrPalShot, 0) << 16);
    prm.v[0].x = (f32)px * Frame_Zoom_X;
    prm.v[0].y = (f32)py * Frame_Zoom_Y;
    prm.v[3].x = Frame_Zoom_X * (f32)(px + sx);
    prm.v[3].y = Frame_Zoom_Y * (f32)(py + sy);

    if (pz > 127) {
        z = -1.0f;
    } else {
        z = PrioBase[pz];
    }

    prm.v[0].z = prm.v[3].z = z;
    prm.t[0].s = (f32)scrnAddTex1UV[ix][0] / 128.0f;
    prm.t[3].s = (f32)(scrnAddTex1UV[ix][0] + scrnAddTex1UV[ix][2]) / 128.0f;
    prm.t[0].t = (f32)scrnAddTex1UV[ix][1] / 128.0f;
    prm.t[3].t = (f32)(scrnAddTex1UV[ix][1] + scrnAddTex1UV[ix][3]) / 128.0f;
    flSetRenderState(4, prm.texCode);
    ps2SeqsRenderQuadInit_A();
    ps2SeqsRenderQuad_A2(&prm, col);
    ps2SeqsRenderQuadEnd();
}

void dispSaveLoadTitle(void *ewk) {
    WORK *wk;
    Sprite prm;
    Vec3 pos[2];
    f32 step_t;
    u32 col;
    s32 i;

    if (No_Trans) {
        return;
    }

    setFilterMode(0);
    wk = ewk;
    mlt_obj_matrix(wk, 0);
    col = 0x00FFFFFF | ((u32)(u8)(0xFF - wk->my_clear_level) << 24);
    prm.texCode = (u32)ppgGetUsingTextureHandle(&ppgScrTex, 6) | ((u32)ppgGetUsingPaletteHandle(&ppgScrPalOpt, 0) << 16);
    flSetRenderState(4, prm.texCode);
    prm.t[0].s = 0.0f;
    prm.t[3].s = 1.0f;
    prm.t[0].t = 0.5f / 128.0f;
    prm.t[3].t = (0.5f + 36.0f) / 128.0f;
    step_t = 36.5f;
    pos[0].x = -192.0f;
    pos[0].y = -12.0f;
    pos[1].x = -64.0f;
    pos[1].y = -48.0f;
    pos[0].z = pos[1].z = 0.0f;

    for (i = 0; i < 3; i++) {
        njCalcPoint(0, &pos[0], &prm.v[0]);
        njCalcPoint(0, &pos[1], &prm.v[3]);
        ps2SeqsRenderQuadInit_A();
        ps2SeqsRenderQuad_A2(&prm, col);
        ps2SeqsRenderQuadEnd();
        step_t += 36.0f;
        prm.t[0].t = prm.t[3].t;
        prm.t[3].t = step_t / 128.0f;
        pos[0].x += 128.0f;
        pos[1].x += 128.0f;
    }
}

void xb_SetScreenShotColor(s32 color) {
    D_007A9AA8 = color;
}

void SSSetUVOffsetForScale(f32 arg0, f32 arg1, f32 sc) {
    f32 u;
    f32 v;

    u = (sc > 1.0f) ? 0.02f : 0.1f;
    D_0079688C = u;
    D_00796894 = u;
    v = (sc > 1.0f) ? 0.02f : 0.1f;
    D_00796890 = v;
    D_00796898 = v;
}

/* Xbox: WipeIn without the WipeLimit step; it redraws the current state. */
s32 xb_WipeInRedraw(u8 type) {
    PAL_CURSOR wipe_pc;
    PAL_CURSOR_P wipe_p[4];
    PAL_CURSOR_COL wipe_col[4];
    s32 i;

    if (WipeLimit == 9) {
        return 1;
    }

    if ((WipeLimit != 8) && (!No_Trans)) {
        wipe_pc.p = wipe_p;
        wipe_pc.col = wipe_col;
        wipe_pc.tex = 0;
        wipe_pc.num = 4;
        wipe_col[0].color = wipe_col[1].color = wipe_col[2].color = wipe_col[3].color = 0xFF000000;

        if (type == 0) {
            wipe_p[0].x = wipe_p[2].x = 0.0f;
            wipe_p[1].x = wipe_p[3].x = 384.0f;

            for (i = 0; i < 224; i += 8) {
                wipe_p[0].y = wipe_p[1].y = (f32)i;
                wipe_p[2].y = wipe_p[3].y = (f32)((i + 8) - (WipeLimit + 1));
                njDrawPolygon2D(&wipe_pc, 4, PrioBase[0], 0x20, 2);
            }
        } else {
            wipe_p[0].y = wipe_p[1].y = 0.0f;
            wipe_p[2].y = wipe_p[3].y = 224.0f;

            for (i = -224; i < 384; i += 8) {
                wipe_p[0].x = (f32)i;
                wipe_p[1].x = (f32)((i + 8) - (WipeLimit + 1));
                wipe_p[2].x = 224.0f + wipe_p[0].x;
                wipe_p[3].x = 224.0f + wipe_p[1].x;
                njDrawPolygon2D(&wipe_pc, 4, PrioBase[0], 0x20, 2);
            }
        }
    }

    return 0;
}

/* Xbox: FadeOut without the FadeLimit step; it redraws the current state. */
s32 xb_FadeOutRedraw(u8 type, u8 step, u8 priority) {
    PAL_CURSOR fade_pc;
    PAL_CURSOR_P fade_p[4];
    PAL_CURSOR_COL fade_col[4];
    u32 Alpha;
    u8 i;
    u8 flag;

    Alpha = 0xFF000000;
    flag = 0;

    if (No_Trans) {
        return 0;
    }

    njColorBlendingMode(0, 1);
    fade_pc.p = fade_p;
    fade_pc.col = fade_col;
    fade_pc.num = 4;

    if (FadeLimit * step < 255) {
        Alpha = (FadeLimit * step) << 24;
    } else {
        flag = 1;
    }

    if (type == 0) {
        Alpha |= 0x00FFFFFF;
    }

    for (i = 0; i < 4; i++) {
        fade_col[i].color = Alpha;
        fade_p[i].x = (f32)Fade_Pos_tbl[i * 2];
        fade_p[i].y = (f32)Fade_Pos_tbl[i * 2 + 1];
    }

    njDrawPolygon2D(&fade_pc, 4, PrioBase[priority], 0x60, 8);

    return flag != 0;
}

/* Xbox: FadeIn without the FadeLimit step; it redraws the current state. */
s32 xb_FadeInRedraw(u8 type, u8 step, u8 priority) {
    PAL_CURSOR fade_pc;
    PAL_CURSOR_P fade_p[4];
    PAL_CURSOR_COL fade_col[4];
    u32 Alpha;
    u8 i;
    u8 flag;

    Alpha = 0;
    flag = 0;

    if (No_Trans) {
        return 0;
    }

    njColorBlendingMode(0, 1);
    fade_pc.p = fade_p;
    fade_pc.col = fade_col;
    fade_pc.num = 4;

    if (FadeLimit * step < 255) {
        Alpha = (255 - FadeLimit * step) << 24;
    } else {
        flag = 1;
    }

    if (type == 0) {
        Alpha |= 0x00FFFFFF;
    }

    for (i = 0; i < 4; i++) {
        fade_col[i].color = Alpha;
        fade_p[i].x = (f32)Fade_Pos_tbl[i * 2];
        fade_p[i].y = (f32)Fade_Pos_tbl[i * 2 + 1];
    }

    njDrawPolygon2D(&fade_pc, 4, PrioBase[priority], 0x60, 8);

    return flag != 0;
}

/* Xbox: WipeOut without the WipeLimit step; it redraws the current state. */
s32 xb_WipeOutRedraw(u8 type) {
    PAL_CURSOR wipe_pc;
    PAL_CURSOR_P wipe_p[4];
    PAL_CURSOR_COL wipe_col[4];
    s32 i;
    s32 dmylim;

    if (WipeLimit > 7) {
        overwrite_panel(0xFF000000, 0);
    }

    if (WipeLimit == 9) {
        overwrite_panel(0xFF000000, 0);
        return 1;
    }

    if (!No_Trans) {
        if (WipeLimit > 7) {
            dmylim = 7;
        } else {
            dmylim = WipeLimit;
        }

        wipe_pc.p = wipe_p;
        wipe_pc.col = wipe_col;
        wipe_pc.tex = 0;
        wipe_pc.num = 4;
        wipe_col[0].color = wipe_col[1].color = wipe_col[2].color = wipe_col[3].color = 0xFF000000;

        if (type == 0) {
            wipe_p[0].x = wipe_p[2].x = 0.0f;
            wipe_p[1].x = wipe_p[3].x = 384.0f;

            for (i = 224; i > 0; i -= 8) {
                wipe_p[0].y = wipe_p[1].y = (f32)i;
                wipe_p[2].y = wipe_p[3].y = (f32)(i - (dmylim + 1));
                njDrawPolygon2D(&wipe_pc, 4, PrioBase[0], 0x20, 2);
            }
        } else if (WipeLimit != 8) {
            wipe_p[0].y = wipe_p[1].y = 0.0f;
            wipe_p[2].y = wipe_p[3].y = 224.0f;

            for (i = -224; i < 384; i += 8) {
                wipe_p[0].x = (f32)i;
                wipe_p[1].x = (f32)(i + dmylim + 1);
                wipe_p[2].x = 224.0f + wipe_p[0].x;
                wipe_p[3].x = 224.0f + wipe_p[1].x;
                njDrawPolygon2D(&wipe_pc, 4, PrioBase[0], 0x20, 2);
            }
        }
    }

    return 0;
}
