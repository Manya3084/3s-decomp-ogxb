/* TITLE_Init, retail sf33rd.xbe 0x69786, size 0xC9.
 * TITLE_Move 0x6984F, size 0x11B, interior after the ret.
 * sound_trg_init 0x6996A, size 0x11, interior after the ret.
 * sound_trg_move 0x6997B, size 0x32, interior after the ret.
 * OPBG_Trans 0x699AD, size 0xC5, interior after the ret.
 * oh_tsr_ck 0x69A72, size 0x27, interior after the ret.
 * oh_reload_tex 0x69A99, size 0x62, interior after the ret.
 * oh_bg_blk_w 0x69AFB, size 0x4B. oh_bg_blk_wh 0x69B46, size 0x4C.
 * oh_bg_blk_wv 0x69B92, size 0x4C. oh_bg_blk_whv 0x69BDE, size 0x4C.
 * opening_init 0x69C2A, size 0x8B, interior after the ret.
 * op_work_clear 0x69CB5, size 0x18, interior after the ret.
 * opning_init_00000 0x69CCD, size 0xE5, interior after the ret.
 * opning_init_01000 0x69DB2, size 0x41, interior after the ret.
 * opning_init_02000 0x69DF3, size 0x5E, interior after the ret.
 * opening_move 0x69E51, size 0x66, interior after the ret.
 * op_bg1_0000 0x69EB7, size 0x2B, interior after the ret.
 * op_bg1_0001 0x69EE2, size 0x81, interior after the ret.
 * op_bg1_0002 0x69F63, size 0xF0, interior after the ret.
 * op_bg1_0003 0x6A053, size 0x15A, interior after the ret.
 * op_bg2_0000 0x6A1AD, size 0x3A, interior after the ret.
 * op_bg2_0001 0x6A1E7, size 0x23, interior after the ret.
 * op_bg2_0002 0x6A20A, size 0x3A, interior after the ret.
 * op_bg2_0003 0x6A244, size 0x3A, interior after the ret.
 * opening_title_01 0x6A27E, size 0xB8, interior after the ret.
 * op_scrn_pos_set2 0x6A336, size 0x2E, interior after the ret.
 * Bg_Family_Set_op 0x6A364, size 0x9C, interior after the ret.
 * OPBG_Init 0x6A400, size 0xDC, interior after the ret.
 * opening_init2 0x6A4DC, size 0x2A, interior after the ret.
 * opening_title 0x6B5ED, size 0x2C, interior after the ret.
 * oh_opening_demo 0x6B619, size 0x3A.
 * op_bg1_move 0x6B547, size 0x57, interior after the ret.
 * op_bg2_move 0x6B59E, size 0x4F, interior after the ret.
 * op_bg0_move 0x6B653, size 0x24E.
 * OPBG_Move 0x6B8A1, size 0x12, interior after the ret.
 * op_bg_move 0x6B8B3, size 0x1C, interior after the ret.
 * opening_demo 0x6B8CF, size 0xBA, interior after the ret.
 * op_101_move 0x6B989, size 0x7F, interior after the ret.
 * op_117_move 0x6CEA5, size 0x78, interior after a tail jmp.
 * op_118_move 0x6CF1D, size 0x8D, interior after the ret.
 * op_100_move 0x6CFAA, size 0x10, interior after the ret.
 * op_102_move 0x6BA08, size 0xAF, interior after the ret.
 * op_103_move 0x6BAB7, size 0x28E, interior after the ret. Its jump table is
 * inside the size.
 * op_104_move 0x6BD45, size 0x1AB. It follows op_103_move's jump table.
 * op_105_move 0x6BEF0, size 0x47, interior after the ret.
 * op_106_move 0x6BF37, size 0xFC, interior after the ret.
 * op_107_move 0x6C033, size 0x288, interior after the ret. Its jump table is
 * inside the size.
 * op_108_move 0x6C2BB, size 0x309, interior because the three bytes before
 * this start decode as ret 6. Its jump table is inside the size.
 * op_109_move 0x6C5C4, size 0x117. It follows op_108_move's jump table.
 * op_110_move 0x6C6DB, size 0x13D, interior after the ret.
 * op_111_move 0x6C818, size 0xE8, interior after the ret.
 * op_112_move 0x6C900, size 0x228, interior after the ret. Its jump table is
 * inside the size.
 * op_113_move 0x6CB28, size 0xF4. It follows op_112_move's jump table.
 * op_114_move 0x6CC1C, size 0x13F, interior after the ret.
 * op_115_move 0x6CD5B, size 0x6B, interior after the ret.
 * op_116_move 0x6CDC6, size 0xDF, interior after the ret.
 *
 * Country is the byte at 0x7A8748. Opening_Now is the word at 0x7968A8.
 * ppgTitleList is 0x7A7E40 and ppgTitleTex is 0x7A7DC0. title_tex_flag is
 * the word at 0xC7E19E. op_w is 0xC7E1C0. op_timer0 is the word at 0xC7E4F0.
 * scr_sc is the float at 0x7C55F4. title[0] and title[1] both hold 0x25F3E8.
 * music_scene is the word at 0xC7E190. music_time is the word at 0xC7E54A.
 * op_plmove_timer is the word at 0xC7E19C. gSeqStatus[0] is the byte at
 * 0xC7C836. The time table is 0x25F4C8 and the trigger table is 0x25F6D0.
 * Both tables are the 257 PS2 entries, ending in -1.
 * ppgOpnBgList is 0x7A7DB8 and ppgOpnBgTex is 0x7A7DE0. Its textures word
 * is at 0x7A7DF0. optsr_tbl is 0x25F450 and holds 34 through 91, then -1.
 * No_Trans is the byte at 0x7BD3C9. Screen_Switch is the byte at 0x7BC988.
 * bg_prm[0] shifts are the words at 0x7C5960 and 0x7C5962. Layer 1 is
 * 0x7C5964 and 0x7C5966. Layer 2 is 0x7C5968 and 0x7C596A. mts is 0x7A8F20
 * and each element is 0x64 bytes, so mts[9] is 0x7A92A4.
 *
 * The load index is 0x54 when Country is 1 or 2, and 0x53 otherwise.
 * TITLE_Init also stores 1 at 0x32F858. Put_char is called with priority 2.
 * State 2 steps the timer on every call. OPBG_Trans returns after the three
 * screen tests and has no debug print. oh_tsr_ck compares 34 as an immediate,
 * then reads the table from the second entry through -1. OPBG_Init is the
 * only caller of sound_trg_init. bg_w is 0x7BC520. scno is the byte at
 * 0x7BC530 and pos_offset is the word at 0x7BC53C. The position_x store
 * subtracts the dword at that address, so it includes quake_x_index.
 * op_end_flag is the word at 0xC7E198. bg_stop is the word at 0x7BC4A0.
 * akebono_flag, bg_app, and sa_pa_flag are the bytes at 0x7BC4A9, 0x7BC4A8,
 * and 0x7BC4AA. aku_flag is 0x7BC4F0 and bg_app_stop is 0x7BC4E8.
 * base_y_pos is the word at 0x7BC516. op_demo_index is 0xC7E548.
 * op_sound_status is 0xC7E1A2. Game_timer is the word at 0x7A8830.
 * op_change_sound_tbl is 0x25F8D4. opening_move_jp is 0x32F860.
 * opening_move has no debug print. opening_init2 tail-jumps to the three
 * inits. opning_init_01000 calls 0xAF4C2 for both off helpers. opening_title
 * does not call the empty opening_title_00. opening_title_01 loads the dword
 * at pos_offset, adds -0x200, and keeps the low word. It does not clear
 * bg_app_stop. Bg_Family_Set_op subtracts the pos_offset word on the first
 * four layers. Layer 5 subtracts the dword at pos_offset from the dword at
 * wxy[0].disp.pos, masks the dword at xy[1].disp.pos with 0xFFFF03FF, and
 * keeps each low word. The loop uses that same mask on a zero-extended word.
 * opw_ptr is 0xC7E194 and bgw_ptr is 0x7BC510. D_No[3] is the byte at
 * 0x7A8203. op_obj_disp is the word at 0xC7E19A. opening_demo does not test
 * Game_pause, and its fade call passes 1. op_100_move does not call
 * Disp_Sound_Code. op_101_move compares 11 and 0x65 as immediates.
 * op_102_move compares 9, 0x66, and 12 as immediates. op_106_move compares
 * 1, 0x6A, 3, and 7 as immediates. op_115_move compares 7 and 0x73 as
 * immediates. op_116_move passes 1 to FadeOut and calls 0x4384A with 2.
 * op_103_move, op_107_move, and op_109_move through op_114_move compare
 * sound thresholds as immediates. op_104_move reads op_104_sound at
 * 0x32F8AC, the words 0, 5, 6, 7, 9, 10, and 11. op_108_move compares
 * mv_ctr as immediates and skips the background move when cases 2, 4, 6,
 * 8, 10, and 12 are still short. op_scrn_end is the byte at 0xC7E1A0.
 * op_110_move case 1 only rejects 0x6E. op_107_move case 0 increments
 * op_plmove_timer, then r_no_2, then stores obj.
 * op_bg1_0000, op_bg1_0001, and op_bg2_0001 store 1 into r_no_0. The other
 * five handlers increment it. xy[1].disp.pos is cleared with and. The shift
 * into 0xAF4AA uses the low byte of fam_no. op_bg_mvxy is 0xC7E500 and each
 * entry is 0x18 bytes. op_bg2_0000 subtracts 0x10000 from wxy[0].cal. The
 * PS2 source spells that same delta as (0x8000 + 0x8000). r_limit is the
 * word at bgw+0x64 and l_limit is the word at bgw+0x68. Index 83 writes
 * layer 0 at 0xC7E1CC. Index 62 and the layer-1 block writes use 0xC7E2D8.
 * 0x4384A, 0x59FD2, 0x13EFE, 0xF2B0A, 0xF2CFD, 0xF3F82, 0xF31A8, 0x97103,
 * 0x1C902, 0x1C8ED, 0xAF2F1, 0xAFAE3, 0xAFB26, 0x30AAF, 0xAF4DC, 0xAF4E9,
 * 0xAF520, 0xAF086, 0xD0E20, 0xF416A, 0xB58A7, 0xEF72E, 0x629B7, 0xAF45F,
 * 0xAF3FC, 0xAF2BA, 0xAF43C, 0xAF4C2, 0xAF4AA, 0x48F0E, 0x4AFFA, and 0xAF47B
 * stay unnamed.
 */

#include "types.h"

typedef struct {
    u8 prefix[0x10];
    u16 textures;
} Texture;

typedef struct Palette Palette;

typedef struct {
    Texture *tex;
    Palette *pal;
} PPGDataList;

typedef union {
    s32 full;
} OPTW_Color;

typedef struct {
    u32 g_no;
    s32 trans;
    u16 hv;
    s16 ok;
    OPTW_Color col;
} OPTW_Small;

typedef struct {
    s8 r_no_0;
    s8 r_no_1;
    s8 dir;
    s8 ctr;
    s16 bg_no;
    u16 blk_no;
    s32 prio;
    OPTW_Small map[4][4];
} OPBW;

typedef struct {
    s8 r_no_0;
    s8 r_no_1;
    s8 r_no_2;
    s8 old_rno;
    s16 index;
    s16 mv_ctr;
    s16 free_work;
    s16 dummy;
    OPBW bgw[3];
} OP_W;

typedef struct {
    u16 bg_h_shift;
    u16 bg_v_shift;
} BackgroundParameters;

typedef struct {
    u8 bytes[0x64];
} MultiTexture;

typedef union {
    s32 cal;
    struct {
        s16 low;
        s16 pos;
    } disp;
} XY;

typedef union {
    s32 sp;
} Reg32SpReal;

typedef struct {
    Reg32SpReal a[2];
    Reg32SpReal d[2];
    s16 kop[2];
    u16 index;
} MVXY;

typedef struct {
    u8 raw0[2];
    s16 fam_no;
    u8 raw1[6];
    s16 position_x;
    s16 position_y;
    u8 raw2[0xA];
    XY xy[2];
    XY wxy[2];
    u8 raw3[0xC];
    s32 zuubun;
    u8 raw4[0x10];
    s16 pos_x_work;
    s16 pos_y_work;
    s8 rewrite_flag;
    u8 raw5[3];
    XY hos_xy[2];
    u8 raw6[0xC];
    s16 r_limit;
    u8 raw7[2];
    s16 l_limit;
    u8 raw8[0x26];
} BGW;

typedef struct {
    u8 raw0[0x10];
    u8 scno;
    u8 raw1[8];
    s8 chase_flag;
    u8 raw2[2];
    s16 pos_offset;
    s16 quake_x_index;
    u8 raw3[0x18];
    BGW bgw[7];
} BG;

#if defined(__i386__)
_Static_assert(sizeof(OPTW_Small) == 0x10, "OPTW_Small");
_Static_assert(sizeof(OPBW) == 0x10C, "OPBW");
_Static_assert(sizeof(OP_W) == 0x330, "OP_W");
_Static_assert(__builtin_offsetof(OPBW, map) == 0xC, "OPBW.map");
_Static_assert(__builtin_offsetof(OP_W, bgw) == 0xC, "OP_W.bgw");
_Static_assert(__builtin_offsetof(Texture, textures) == 0x10, "Texture.textures");
_Static_assert(sizeof(BackgroundParameters) == 4, "BackgroundParameters");
_Static_assert(sizeof(MultiTexture) == 0x64, "MultiTexture");
_Static_assert(sizeof(XY) == 4, "XY");
_Static_assert(__builtin_offsetof(XY, disp.pos) == 2, "XY.disp.pos");
_Static_assert(sizeof(BGW) == 0x90, "BGW");
_Static_assert(sizeof(BG) == 0x428, "BG");
_Static_assert(__builtin_offsetof(BGW, fam_no) == 0x2, "fam_no");
_Static_assert(__builtin_offsetof(BGW, position_x) == 0xA, "position_x");
_Static_assert(__builtin_offsetof(BGW, xy) == 0x18, "xy");
_Static_assert(__builtin_offsetof(BGW, wxy) == 0x20, "wxy");
_Static_assert(__builtin_offsetof(BGW, zuubun) == 0x34, "zuubun");
_Static_assert(__builtin_offsetof(BGW, pos_x_work) == 0x48, "pos_x_work");
_Static_assert(__builtin_offsetof(BGW, rewrite_flag) == 0x4C, "rewrite_flag");
_Static_assert(__builtin_offsetof(BGW, hos_xy) == 0x50, "hos_xy");
_Static_assert(__builtin_offsetof(BGW, r_limit) == 0x64, "r_limit");
_Static_assert(__builtin_offsetof(BGW, l_limit) == 0x68, "l_limit");
_Static_assert(sizeof(MVXY) == 0x18, "MVXY");
_Static_assert(__builtin_offsetof(MVXY, d) == 8, "MVXY.d");
_Static_assert(__builtin_offsetof(BG, scno) == 0x10, "scno");
_Static_assert(__builtin_offsetof(BG, chase_flag) == 0x19, "chase_flag");
_Static_assert(__builtin_offsetof(BG, pos_offset) == 0x1C, "pos_offset");
_Static_assert(__builtin_offsetof(BG, quake_x_index) == 0x1E, "quake_x_index");
_Static_assert(__builtin_offsetof(BG, bgw) == 0x38, "bgw");
#endif

extern u8 Country;
extern s16 Opening_Now;
extern PPGDataList ppgTitleList;
extern Texture ppgTitleTex;
extern s16 title_tex_flag;
extern s32 dword_0032F858;
extern OP_W op_w;
extern s16 op_timer0;
extern const f32 title00[];
extern f32 scr_sc;
extern s16 music_scene;
extern s16 music_time;
extern s16 op_plmove_timer;
extern const s16 sound_time_tbl[];
extern const s16 sound_trg_tbl[];
extern u8 gSeqStatus[1];
extern PPGDataList ppgOpnBgList;
extern Texture ppgOpnBgTex;
extern const s16 optsr_tbl[];
extern u8 No_Trans;
extern u8 Screen_Switch;
extern BackgroundParameters bg_prm[3];
extern MultiTexture mts[];
extern BG bg_w;
extern s16 op_end_flag;
extern s16 bg_stop;
extern s16 base_y_pos;
extern s8 akebono_flag;
extern s8 aku_flag;
extern s8 sa_pa_flag;
extern s8 bg_app;
extern s8 bg_app_stop;
extern s16 op_demo_index;
extern s16 op_sound_status;
extern u16 Game_timer;
extern const s16 op_change_sound_tbl[];
extern void (*opening_move_jp[19])(void);

extern void ppgSetupCurrentDataList(PPGDataList *dlist);
extern s16 Search_ramcnt_type(u8 kokey);
extern u32 Get_size_data_ramcnt_key(s16 key);
extern void *Get_ramcnt_address(s16 key);
extern void sub_0004384A(const char *tag);
extern u32 sub_00059FD2(s32 id, void **adrs, s16 *key, s32 arg3, s32 arg4);
extern void sub_00013EFE(const char *text);
extern void sub_000F2B0A(void *tex, void *adrs, u32 size, s32 ix, s32 count, s32 arg5, s32 arg6);
extern void sub_000F2CFD(void *tex, s32 ix);
extern void sub_000F3F82(void *tex, s32 ix, s32 arg2);
extern void sub_00097103(s16 key);
extern void sub_000F31A8(void *dlist);
extern void sub_0001C902(s32 mode);
extern void sub_0001C8ED(s32 mode);
extern void sub_000AF2F1(s32 value);
extern void sub_000AFAE3(u16 x, u16 y, s32 add);
extern void sub_000AFB26(u16 x, u16 y, s32 add);
extern void sub_00030AAF(const f32 *ptr, u32 indexG, u16 prio, s16 x, s16 y, f32 zx, f32 zy);
extern void sub_000AF4DC(void);
extern void sub_000AF4E9(void);
extern void sub_000AF520(void);
extern void sub_000AF086(s32 index);
extern void sub_000D0E20(OPBW *opbw, u16 h_shift, u16 v_shift);
extern void sub_000F416A(Texture *tex, u32 g_no);
extern Palette *sub_000B58A7(void);
extern void sub_000EF72E(s32 index);
extern void sub_000629B7(MultiTexture *obj, s32 size);
extern void sub_000AF45F(void);
extern void sub_000AF3FC(void);
extern void sub_000AF2BA(void);
extern void sub_000AF4C2(s32 bits);
extern void sub_000AF4AA(s32 bits);
extern void sub_000AF43C(s32 bgnm, s32 x, s32 y);
extern void sub_00048F0E(s32 a, s32 b, s32 c);
extern void sub_0004AFFA(s32 kind);
extern void sub_000AF47B(s32 fmnm, s32 x, s32 y);
extern void Disp_Copyright(void);
extern void Go_BGM(void);
extern OPBW *opw_ptr;
extern BGW *bgw_ptr;
extern MVXY op_bg_mvxy[3];
extern s16 op_obj_disp;
extern s8 op_scrn_end;
extern const s16 op_104_sound[7];
extern u8 D_No[4];
extern void sub_0006A506(s16 r_index);
extern void sub_0006A539(s16 r_index);
extern void sub_0006A966(s16 r_index);
extern void sub_0006AA4B(s16 r_index);
extern void sub_0006AB58(s16 r_index);
extern void sub_0006ACFF(s16 r_index);
extern void sub_0006AE4B(s16 r_index);
extern void sub_0006AEE0(s16 r_index);
extern void sub_0006AF91(s16 r_index);
extern void sub_0006B041(s16 r_index);
extern void sub_0006B0FA(s16 r_index);
extern void sub_0006B1D2(s16 r_index);
extern void sub_0006B29C(s16 r_index);
extern void sub_0006B34C(s16 r_index);
extern void sub_0006B351(s16 r_index);
extern void sub_0006B477(s16 r_index);
extern void sub_000E740C(s32 tone, s32 priority);
extern void sub_000BE5C7(s32 id);
extern void sub_0003D388(s32 id);
extern void sub_000B7DD7(s32 id);
extern s32 sub_000E71DD(s32 type, s32 step, s32 priority);
extern void FadeInit(void);
extern s32 FadeOut(u8 type, u8 step, u8 priority);
extern void sub_0009D7C3(s32 group);
extern void sub_000EFA99(s32 index);
extern void sub_000D0D33(void);
extern s32 sub_0009A8EB(s32 code);
extern s32 sub_0009A934(void);

static const f32 *title[2] = { title00, title00 };

void TITLE_Init(void) {
    void *loadAdrs;
    u32 loadSize;
    s16 key;
    s32 id;

    sub_0004384A("\nMAIN TITLE\n\n");
    Opening_Now = 0;
    ppgTitleList.tex = &ppgTitleTex;
    ppgTitleList.pal = 0;
    ppgSetupCurrentDataList(&ppgTitleList);

    if (Country == 1 || Country == 2) {
        id = 0x54;
    } else {
        id = 0x53;
    }

    loadSize = sub_00059FD2(id, &loadAdrs, &key, 2, 1);

    if (loadSize == 0) {
        sub_00013EFE("メインタイトルのテクスチャが読み込めませんでした。\n");

        for (;;) {
        }
    }

    sub_000F2B0A(0, loadAdrs, loadSize, 601, 1, 0, 0);
    sub_000F2CFD(0, 601);
    sub_000F3F82(0, 601, 1);
    sub_00097103(key);
    sub_000F31A8(0);
    title_tex_flag = 1;
    dword_0032F858 = 1;
    op_w.r_no_0 = 0;
}

s16 TITLE_Move(u16 type) {
    ppgSetupCurrentDataList(&ppgTitleList);
    sub_0001C902(0);
    sub_0001C8ED(0);

    switch (type) {
    case 0:
        switch (op_w.r_no_0) {
        case 0:
            op_w.r_no_0 = (s8)(op_w.r_no_0 + 1);
            sub_000AF2F1(0x40);
            sub_000AFAE3(192, 112, 0x13);
            op_timer0 = 10;
            break;

        case 1:
            op_timer0 = (s16)(op_timer0 - 1);

            if (op_timer0 <= 0) {
                op_w.r_no_0 = (s8)(op_w.r_no_0 + 1);
                op_timer0 = 19;
            }

            break;

        case 2:
            if (op_timer0-- >= 0) {
                sub_000AFB26(0xC0, 0x70, 1);
            } else {
                op_w.r_no_0 = (s8)(op_w.r_no_0 + 1);
            }

            break;

        default:
            sub_000AF2F1(0x40);
            break;
        }

        sub_00030AAF(title[type], 601, 2, 192, 96, scr_sc, scr_sc);
        return 0;

    case 1:
        sub_00030AAF(title[type], 601, 2, 192, 96, 1.0f, 1.0f);
        return 0;

    default:
        return 0;
    }
}

void sound_trg_init(void) {
    music_time = 0;
    music_scene = 0;
}

void sound_trg_move(void) {
    s16 buff;

    if (op_plmove_timer >= sound_time_tbl[music_scene]) {
        buff = sound_trg_tbl[music_scene];

        if (buff >= 0) {
            music_scene = (s16)(music_scene + 1);
            gSeqStatus[0] = (u8)buff;
        }
    }
}

void OPBG_Trans(void) {
    if (No_Trans) {
        return;
    }

    sub_0001C902(1);
    sub_0001C8ED(0);
    ppgSetupCurrentDataList(&ppgOpnBgList);
    sub_000AF4DC();
    sub_000AF4E9();
    sub_000AF520();
    sub_000AF086(0);
    sub_000AF086(1);
    sub_000AF086(2);

    if (Screen_Switch & 1) {
        sub_000D0E20(&op_w.bgw[0], bg_prm[0].bg_h_shift, bg_prm[0].bg_v_shift);
    }

    if (Screen_Switch & 2) {
        sub_000D0E20(&op_w.bgw[1], bg_prm[1].bg_h_shift, bg_prm[1].bg_v_shift);
    }

    if (Screen_Switch & 4) {
        sub_000D0E20(&op_w.bgw[2], bg_prm[2].bg_h_shift, bg_prm[2].bg_v_shift);
    }
}

s16 oh_tsr_ck(s32 blk_no) {
    s16 i;

    for (i = 0; optsr_tbl[i] != -1; i++) {
        if (optsr_tbl[i] == (s16)blk_no) {
            return 1;
        }
    }

    return 0;
}

void oh_reload_tex(OPBW *opbw, s32 blk_no, s16 mapx, s16 mapy) {
    if (!oh_tsr_ck(blk_no) && (opbw->map[mapx][mapy].g_no != (u32)(blk_no + 0x259))) {
        if (opbw->map[mapx][mapy].g_no && !oh_tsr_ck(opbw->map[mapx][mapy].g_no - 0x259)) {
            sub_000F416A(&ppgOpnBgTex, opbw->map[mapx][mapy].g_no);
        }

        opbw->map[mapx][mapy].ok = 1;
    }
}

void oh_bg_blk_w(OPBW *opbw, s32 blk_no, s16 mapx, s16 mapy, s32 trans) {
    oh_reload_tex(opbw, blk_no, mapx, mapy);
    opbw->map[mapx][mapy].g_no = blk_no + 0x259;
    opbw->map[mapx][mapy].hv = 0;
    opbw->map[mapx][mapy].trans = trans;
    opbw->blk_no = (u16)blk_no;
    opbw->map[mapx][mapy].col.full = -1;
}

void oh_bg_blk_wh(OPBW *opbw, s32 blk_no, s16 mapx, s16 mapy, s32 trans) {
    oh_reload_tex(opbw, blk_no, mapx, mapy);
    opbw->map[mapx][mapy].g_no = blk_no + 0x259;
    opbw->map[mapx][mapy].hv = 1;
    opbw->map[mapx][mapy].trans = trans;
    opbw->blk_no = (u16)blk_no;
    opbw->map[mapx][mapy].col.full = -1;
}

void oh_bg_blk_wv(OPBW *opbw, s32 blk_no, s16 mapx, s16 mapy, s32 trans) {
    oh_reload_tex(opbw, blk_no, mapx, mapy);
    opbw->map[mapx][mapy].g_no = blk_no + 0x259;
    opbw->map[mapx][mapy].hv = 2;
    opbw->map[mapx][mapy].trans = trans;
    opbw->blk_no = (u16)blk_no;
    opbw->map[mapx][mapy].col.full = -1;
}

void oh_bg_blk_whv(OPBW *opbw, s32 blk_no, s16 mapx, s16 mapy, s32 trans) {
    oh_reload_tex(opbw, blk_no, mapx, mapy);
    opbw->map[mapx][mapy].g_no = blk_no + 0x259;
    opbw->map[mapx][mapy].hv = 3;
    opbw->map[mapx][mapy].trans = trans;
    opbw->blk_no = (u16)blk_no;
    opbw->map[mapx][mapy].col.full = -1;
}

void opening_init(void) {
    s16 i;
    s16 j;
    s16 k;

    op_w.r_no_0 = 0;
    op_w.r_no_1 = 0;
    op_w.r_no_2 = 0;
    op_w.index = 0;
    op_w.mv_ctr = 0;
    op_w.bgw[0].blk_no = op_w.bgw[1].blk_no = op_w.bgw[2].blk_no = 0;
    op_w.bgw[0].prio = 75;
    op_w.bgw[1].prio = 80;
    op_w.bgw[2].prio = 85;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            for (k = 0; k < 4; k++) {
                op_w.bgw[i].map[j][k].g_no = 0;
                op_w.bgw[i].map[j][k].trans = 0;
                op_w.bgw[i].map[j][k].hv = 0;
                op_w.bgw[i].map[j][k].ok = 0;
            }
        }
    }
}

void op_work_clear(void) {
    s16 i;

    for (i = 0; i < 3; i++) {
        op_w.bgw[i].r_no_0 = 0;
        op_w.bgw[i].r_no_1 = 0;
    }
}

void OPBG_Init(void) {
    void *loadAdrs;
    u32 loadSize;
    s16 i;
    s16 key;

    sub_0004384A("\nOPENING\n\n");
    ppgOpnBgList.tex = &ppgOpnBgTex;
    ppgOpnBgList.pal = sub_000B58A7();
    ppgSetupCurrentDataList(&ppgOpnBgList);
    key = Search_ramcnt_type(0x1D);

    if (key == 0) {
        sub_00013EFE("オープニングデモテクスチャが読み込まれていません。\n");

        for (;;) {
        }
    }

    loadSize = Get_size_data_ramcnt_key(key);
    loadAdrs = Get_ramcnt_address(key);
    sub_000F2B0A(0, loadAdrs, loadSize, 602, 91, 0, 0);

    for (i = 0; i < ppgOpnBgTex.textures; i++) {
        sub_000F2CFD(0, i + 602);
        sub_000F3F82(0, i + 602, 1);
    }

    Opening_Now = 1;
    sub_000EF72E(9);
    sub_000629B7(&mts[9], 0x8C40);
    sound_trg_init();
    opening_init();
    sub_000AF2F1(0x40);
}

void opning_init_00000(void) {
    s16 i;
    s32 span;

    op_w.r_no_1 = (s8)(op_w.r_no_1 + 1);
    op_end_flag = 0;
    sub_000AF45F();
    sub_000AF3FC();
    sub_000AF2BA();
    sub_000AF2F1(0x40);
    bg_w.scno = 3;
    bg_w.pos_offset = 192;

    for (i = 0; i < 6; i++) {
        bg_w.bgw[i].pos_x_work = bg_w.bgw[i].pos_y_work = 0;
        bg_w.bgw[i].rewrite_flag = 0;
        bg_w.bgw[i].fam_no = 0;
        bg_w.bgw[i].zuubun = 0;
        bg_w.bgw[i].wxy[0].cal = 0x02000000;
        bg_w.bgw[i].xy[1].cal = 0;
        bg_w.bgw[i].wxy[0].cal = 0x02000000;
        bg_w.bgw[i].wxy[1].cal = 0;
        bg_w.bgw[i].hos_xy[0].cal = 0x02000000;
        bg_w.bgw[i].hos_xy[1].cal = 0;
        span = (s32)((u16)bg_w.pos_offset | ((u32)(u16)bg_w.quake_x_index << 16));
        bg_w.bgw[i].position_x = (s16)(0x200 - span);
        bg_w.bgw[i].position_y = 0;
    }

    for (i = 0; i < 3; i++) {
        bg_w.bgw[i].fam_no = i;
        op_w.bgw[i].r_no_0 = 0;
        op_w.bgw[i].r_no_1 = 0;
        op_w.bgw[i].bg_no = i;
    }

    op_w.r_no_2 = 0;
    op_end_flag = 0;
    bg_stop = 0;
    akebono_flag = 0;
    aku_flag = 0;
    sa_pa_flag = 0;
    bg_app = 0;
    bg_app_stop = 0;
    bg_w.chase_flag = 0;
}

void opning_init_01000(void) {
    op_w.r_no_1 = (s8)(op_w.r_no_1 + 1);
    sub_000AF4C2(0xF);
    sub_000AF4C2(0xF);
    op_w.free_work = 8;
    sub_000AF43C(0, 0x200 - bg_w.pos_offset, 0x200);
    base_y_pos = 40;
}

void opning_init_02000(void) {
    op_w.free_work = (s16)(op_w.free_work - 1);

    if (op_w.free_work < 0) {
        op_w.r_no_0 = (s8)(op_w.r_no_0 + 1);
        op_w.r_no_1 = 0;
        op_w.r_no_2 = 0;
    }

    sub_000AF43C(0, 0x200 - bg_w.pos_offset, 0x200);
    op_demo_index = 0;
    gSeqStatus[0] = 0;
    op_w.index = 0;
    op_sound_status = 0;
    op_plmove_timer = 2;
}

void opening_move(void) {
    s16 work2;

    op_plmove_timer = (s16)(op_plmove_timer + 1);
    sound_trg_move();

    if (op_w.r_no_1 < 18) {
        work2 = (s16)gSeqStatus[0];

        if (op_sound_status != work2) {
            if (work2 == op_change_sound_tbl[op_w.r_no_1]) {
                op_w.r_no_1 = (s8)(op_w.r_no_1 + 1);
                op_w.r_no_2 = 0;
                op_work_clear();
            }
        }
    }

    opening_move_jp[op_w.r_no_1]();
    op_sound_status = (s16)gSeqStatus[0];
}

void op_bg1_0000(s16 /* unused */) {
    switch (opw_ptr->r_no_0) {
    case 0:
        opw_ptr->r_no_0 = 1;
        bgw_ptr->wxy[0].disp.pos = 0x200;
        bgw_ptr->xy[1].disp.pos = 0;
        sub_000AF4C2(2);
        break;

    case 1:
    case 2:
        break;
    }
}

void op_bg1_0001(s16 r_index) {
    switch (opw_ptr->r_no_0) {
    case 0:
        opw_ptr->r_no_0 = 1;
        sub_000AF4AA(1 << (u8)bgw_ptr->fam_no);
        bgw_ptr->wxy[0].cal = 0x02000000;
        bgw_ptr->xy[1].cal = 0;

        switch (r_index) {
        case 0x37:
            oh_bg_blk_w(&op_w.bgw[1], 1, 1, 0, 0);
            oh_bg_blk_w(&op_w.bgw[1], 2, 2, 0, 0);
            break;

        case 0x38:
            oh_bg_blk_w(&op_w.bgw[1], 3, 1, 0, 0);
            oh_bg_blk_w(&op_w.bgw[1], 4, 2, 0, 0);
            break;
        }

        break;

    case 1:
        break;
    }
}

void op_bg1_0002(s16 r_index) {
    switch (opw_ptr->r_no_0) {
    case 0:
        opw_ptr->r_no_0 = (s8)(opw_ptr->r_no_0 + 1);
        sub_000AF4AA(1 << (u8)bgw_ptr->fam_no);

        switch (r_index) {
        case 0x3C:
            bgw_ptr->wxy[0].cal = 0x01000000;
            bgw_ptr->xy[1].cal = 0;
            oh_bg_blk_w(&op_w.bgw[1], 7, 0, 0, 0);
            oh_bg_blk_w(&op_w.bgw[1], 8, 1, 0, 0);
            oh_bg_blk_w(&op_w.bgw[1], 9, 2, 0, 0);
            op_bg_mvxy[bgw_ptr->fam_no].a[0].sp = 0xC0000;
            op_bg_mvxy[bgw_ptr->fam_no].d[0].sp = 0;
            bgw_ptr->r_limit = 0x1E0;
            break;
        }

        break;

    case 1:
        op_bg_mvxy[bgw_ptr->fam_no].a[0].sp += op_bg_mvxy[bgw_ptr->fam_no].d[0].sp;
        bgw_ptr->wxy[0].cal += op_bg_mvxy[bgw_ptr->fam_no].a[0].sp;

        if (bgw_ptr->wxy[0].disp.pos >= bgw_ptr->r_limit) {
            opw_ptr->r_no_0 = (s8)(opw_ptr->r_no_0 + 1);
        }

        break;

    case 2:
        break;
    }
}

void op_bg1_0003(s16 r_index) {
    switch (opw_ptr->r_no_0) {
    case 0:
        opw_ptr->r_no_0 = (s8)(opw_ptr->r_no_0 + 1);
        sub_000AF4AA(1 << (u8)bgw_ptr->fam_no);

        switch (r_index) {
        case 83:
            bgw_ptr->wxy[0].cal = 0x2200000;
            bgw_ptr->xy[1].cal = 0;
            oh_bg_blk_w(op_w.bgw, 0x10, 1, 0, 0);
            oh_bg_blk_w(op_w.bgw, 0x11, 2, 0, 0);
            op_bg_mvxy[bgw_ptr->fam_no].a[0].sp = 0x80000;
            op_bg_mvxy[bgw_ptr->fam_no].d[0].sp = -0x8000;
            bgw_ptr->r_limit = 0x200;
            break;

        case 62:
            bgw_ptr->wxy[0].cal = 0x1E00000;
            bgw_ptr->xy[1].cal = 0;
            oh_bg_blk_w(&op_w.bgw[1], 0xA, 0, 0, 0);
            oh_bg_blk_w(&op_w.bgw[1], 0xB, 1, 0, 0);
            oh_bg_blk_w(&op_w.bgw[1], 0xC, 2, 0, 0);
            op_bg_mvxy[bgw_ptr->fam_no].a[0].sp = (s32)0xFFF80000;
            op_bg_mvxy[bgw_ptr->fam_no].d[0].sp = 0;
            break;
        }

        break;

    case 1:
        op_bg_mvxy[bgw_ptr->fam_no].a[0].sp += op_bg_mvxy[bgw_ptr->fam_no].d[0].sp;
        bgw_ptr->wxy[0].cal += op_bg_mvxy[bgw_ptr->fam_no].a[0].sp;

        if (bgw_ptr->wxy[0].disp.pos <= bgw_ptr->l_limit) {
            opw_ptr->r_no_0 = (s8)(opw_ptr->r_no_0 + 1);
        }

        break;

    case 2:
        break;
    }
}

void op_bg2_0000(void) {
    switch (opw_ptr->r_no_0) {
    case 0:
        opw_ptr->r_no_0 = (s8)(opw_ptr->r_no_0 + 1);
        bgw_ptr->wxy[0].disp.pos = 0x200;
        bgw_ptr->xy[1].disp.pos = 0;
        break;

    case 1:
        bgw_ptr->wxy[0].cal -= 0x10000;
        break;

    case 2:
        break;
    }
}

void op_bg2_0001(void) {
    switch (opw_ptr->r_no_0) {
    case 0:
        opw_ptr->r_no_0 = 1;
        bgw_ptr->wxy[0].disp.pos = 0x200;
        bgw_ptr->xy[1].disp.pos = 0;
        break;

    case 1:
        break;
    }
}

void op_bg2_0002(void) {
    switch (opw_ptr->r_no_0) {
    case 0:
        opw_ptr->r_no_0 = (s8)(opw_ptr->r_no_0 + 1);
        bgw_ptr->wxy[0].disp.pos = 0x200;
        bgw_ptr->xy[1].disp.pos = 0;
        break;

    case 1:
        bgw_ptr->xy[1].cal += 0x10000;
        break;

    case 2:
        break;
    }
}

void op_bg2_0003(void) {
    switch (opw_ptr->r_no_0) {
    case 0:
        opw_ptr->r_no_0 = (s8)(opw_ptr->r_no_0 + 1);
        bgw_ptr->wxy[0].disp.pos = 0x200;
        bgw_ptr->xy[1].disp.pos = 0;
        break;

    case 1:
        bgw_ptr->wxy[0].cal += 0x10000;
        break;

    case 2:
        break;
    }
}

void opening_title_01(void) {
    s16 pos_work_x;
    s32 span;

    sub_00048F0E(1, 0, 1);
    sub_00048F0E(0, 0, 1);
    sub_0004AFFA(0x10);
    sub_0004AFFA(0x11);
    sub_0004AFFA(0x12);
    sub_0004AFFA(9);
    Disp_Copyright();
    sub_000AF4C2(0xF);
    sub_000AF43C(0, 0x200 - bg_w.pos_offset, 0);
    sub_000AF43C(1, 0x200 - bg_w.pos_offset, 0);
    span = (s32)((u16)bg_w.pos_offset | ((u32)(u16)bg_w.quake_x_index << 16));
    pos_work_x = (s16)(span - 0x200);
    sub_000AF47B(1, pos_work_x, 0x300);
    op_end_flag = 1;
    bg_stop = 0;
    akebono_flag = 0;
    aku_flag = 0;
    sa_pa_flag = 0;
    bg_app = 0;
    bg_w.chase_flag = 0;
}

void op_scrn_pos_set2(s16 bg_no) {
    s16 pos_x;
    s16 pos_y;

    pos_x = bg_w.bgw[bg_no].wxy[0].disp.pos;
    pos_y = bg_w.bgw[bg_no].xy[1].disp.pos;
    sub_000AF43C(bg_no, pos_x - bg_w.pos_offset, pos_y);
}

void Bg_Family_Set_op(void) {
    s16 pos_work_x;
    s16 pos_work_y;
    s16 i;
    s32 wx;
    s32 span;
    s32 yspan;

    for (i = 0; i < 4; i++) {
        bg_w.bgw[i].xy[0].cal = bg_w.bgw[i].wxy[0].cal;
        bg_w.bgw[i].position_y = bg_w.bgw[i].xy[1].disp.pos;
        bg_w.bgw[i].position_x = (s16)(bg_w.bgw[i].wxy[0].disp.pos - bg_w.pos_offset);
        pos_work_x = (s16)(-bg_w.bgw[i].position_x);
        pos_work_y = bg_w.bgw[i].position_y;
        pos_work_y = (s16)(0x300 - (pos_work_y & 0x3FF));
        sub_000AF47B(i + 1, pos_work_x, pos_work_y);
    }

    bg_w.bgw[5].position_y = bg_w.bgw[5].xy[1].disp.pos;
    wx = (s32)((u16)bg_w.bgw[5].wxy[0].disp.pos | ((u32)(u16)bg_w.bgw[5].wxy[1].disp.low << 16));
    span = (s32)((u16)bg_w.pos_offset | ((u32)(u16)bg_w.quake_x_index << 16));
    bg_w.bgw[5].position_x = (s16)(wx - span);
    pos_work_x = (s16)(-bg_w.bgw[5].position_x);
    yspan = (s32)((u16)bg_w.bgw[5].xy[1].disp.pos | ((u32)(u16)bg_w.bgw[5].wxy[0].disp.low << 16));
    pos_work_y = (s16)(0x300 - (s32)((u32)yspan & 0xFFFF03FFu));
    sub_000AF47B(6, pos_work_x, pos_work_y);
}

void opening_init2(void) {
    Game_timer = 0;

    switch (op_w.r_no_1) {
    case 0:
        opning_init_00000();
        break;

    case 1:
        opning_init_01000();
        break;

    case 2:
        opning_init_02000();
        break;
    }
}

void opening_title(void) {
    switch (op_w.r_no_1) {
    case 0:
        op_w.r_no_1 = (s8)(op_w.r_no_1 + 1);
        break;

    case 1:
        op_w.free_work = (s16)(op_w.free_work - 1);

        if (op_w.free_work <= 0) {
            opening_title_01();
            op_w.r_no_1 = (s8)(op_w.r_no_1 + 1);
        }

        break;

    case 2:
        break;
    }
}

s16 oh_opening_demo(void) {
    void (*opening_demo_jp[3])(void) = { opening_init2, opening_move, opening_title };

    Game_timer = (u16)(Game_timer + 1);
    opening_demo_jp[op_w.r_no_0]();
    Bg_Family_Set_op();
    return op_end_flag;
}

void op_bg1_move(s16 r_index) {
    opw_ptr = &op_w.bgw[1];
    bgw_ptr = &bg_w.bgw[1];

    switch (r_index) {
    case 55:
    case 56:
        op_bg1_0001(r_index);
        break;

    case 60:
        op_bg1_0002(r_index);
        break;

    case 62:
        op_bg1_0003(r_index);
        break;

    default:
        op_bg1_0000(r_index);
        break;
    }

    op_scrn_pos_set2(1);
}

void op_bg2_move(s16 r_index) {
    opw_ptr = &op_w.bgw[2];
    bgw_ptr = &bg_w.bgw[2];

    switch (r_index) {
    case 0:
    case 24:
        op_bg2_0000();
        break;

    case 2:
        op_bg2_0002();
        break;

    case 28:
        op_bg2_0003();
        break;

    default:
        op_bg2_0001();
        break;
    }

    op_scrn_pos_set2(2);
}

void op_bg0_move(s16 r_index) {
    void (*op_bg0_move_jp[94])(s16) = {
        sub_0006A506, sub_0006A539, sub_0006A506, sub_0006A539, sub_0006A539, sub_0006A539, sub_0006A506, sub_0006A539,
        sub_0006B351, sub_0006A539, sub_0006A506, sub_0006A539, sub_0006A539, sub_0006A506, sub_0006B351, sub_0006A539,
        sub_0006A506, sub_0006A506, sub_0006A539, sub_0006A539, sub_0006A506, sub_0006A539, sub_0006A539, sub_0006A506,
        sub_0006A506, sub_0006A506, sub_0006A506, sub_0006A506, sub_0006A506, sub_0006A506, sub_0006A539, sub_0006A539,
        sub_0006A539, sub_0006A539, sub_0006A506, sub_0006A539, sub_0006A539, sub_0006A506, sub_0006A539, sub_0006A539,
        sub_0006A506, sub_0006A966, sub_0006AA4B, sub_0006A966, sub_0006AA4B, sub_0006A966, sub_0006AA4B, sub_0006A966,
        sub_0006AA4B, sub_0006A966, sub_0006AA4B, sub_0006A966, sub_0006AA4B, sub_0006A506, sub_0006AB58, sub_0006A539,
        sub_0006A539, sub_0006AB58, sub_0006ACFF, sub_0006A966, sub_0006A539, sub_0006A966, sub_0006A539, sub_0006A966,
        sub_0006AE4B, sub_0006A539, sub_0006A539, sub_0006A539, sub_0006AEE0, sub_0006AF91, sub_0006A506, sub_0006A506,
        sub_0006A539, sub_0006A539, sub_0006A506, sub_0006A539, sub_0006A539, sub_0006A506, sub_0006A506, sub_0006AB58,
        sub_0006A539, sub_0006AB58, sub_0006A539, sub_0006A966, op_bg1_0003, sub_0006A966, sub_0006B041, sub_0006A966,
        sub_0006B0FA, sub_0006B1D2, sub_0006B29C, sub_0006B34C, sub_0006A966, sub_0006B477
    };

    opw_ptr = &op_w.bgw[0];
    bgw_ptr = &bg_w.bgw[0];
    op_bg0_move_jp[r_index](r_index);
}

s16 OPBG_Move(s32) {
    s16 flag;

    flag = oh_opening_demo();
    OPBG_Trans();
    return flag;
}

void op_bg_move(s16 r_index) {
    op_bg0_move(r_index);
    op_bg1_move(r_index);
    op_bg2_move(r_index);
}

s16 opening_demo(void) {
    switch (D_No[3]) {
    case 0:
        D_No[3] = (u8)(D_No[3] + 1);
        OPBG_Init();
        break;

    case 1:
        if (OPBG_Move(0)) {
            D_No[3] = (u8)(D_No[3] + 1);
            sub_0009D7C3(0x8C40);
            sub_000EFA99(9);
            sub_000D0D33();
            TITLE_Init();
            FadeInit();
        }

        break;

    case 2:
        TITLE_Move(0);

        if (sub_000E71DD(0, 4, 1) != 0) {
            D_No[3] = (u8)(D_No[3] + 1);
            op_timer0 = 300;
        }

        break;

    case 3:
        op_timer0 = (s16)(op_timer0 - 1);

        if (op_timer0 == 0) {
            D_No[3] = 99;
        }

        TITLE_Move(1);
        Disp_Copyright();
        break;

    default:
        TITLE_Move(1);
        Disp_Copyright();
        return 1;
    }

    return 0;
}

void op_101_move(void) {
    switch (op_w.r_no_2) {
    case 0:
        op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
        sub_000E740C(0xFF, 0);
        op_bg_move(0);
        sub_000BE5C7(0);
        sub_000BE5C7(1);
        op_obj_disp = 0;
        sub_0003D388(0);
        break;

    case 1:
        if (gSeqStatus[0] >= 11 && gSeqStatus[0] != 0x65) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_w.index = 1;
            op_obj_disp = 1;
            op_work_clear();
            break;
        }

        op_bg_move(0);
        break;

    default:
        op_bg_move(1);
        break;
    }
}

void op_102_move(void) {
    switch (op_w.r_no_2) {
    case 0:
        op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
        op_w.index = 2;
        sub_000BE5C7(2);
        sub_000BE5C7(3);
        sub_000BE5C7(4);
        op_obj_disp = 0;
        sub_0003D388(1);
        op_work_clear();
        op_bg_move(2);
        break;

    case 1:
        if (gSeqStatus[0] >= 9 && gSeqStatus[0] != 0x66) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_w.index = 3;
            op_obj_disp = 1;
            op_work_clear();
            op_bg_move(3);
            break;
        }

        op_bg_move(2);
        break;

    case 2:
        if (gSeqStatus[0] >= 12) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_w.index = 4;
            op_work_clear();
            op_bg_move(4);
            break;
        }

        op_bg_move(3);
        break;

    default:
        op_bg_move(4);
        break;
    }
}

void op_103_move(void) {
    switch (op_w.r_no_2) {
    case 0:
        op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
        op_w.index = 5;
        sub_000BE5C7(5);
        sub_000BE5C7(6);
        sub_000BE5C7(7);
        sub_000BE5C7(8);
        sub_000BE5C7(9);
        sub_000BE5C7(10);
        op_work_clear();
        op_bg_move(5);
        break;

    case 1:
        if (gSeqStatus[0] >= 1 && gSeqStatus[0] != 0x67) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_w.index = 6;
            op_work_clear();
            sub_000BE5C7(11);
            sub_000BE5C7(12);
            sub_000BE5C7(13);
            sub_000BE5C7(14);
            sub_000BE5C7(15);
            sub_000BE5C7(16);
            break;
        }

        op_bg_move(5);
        break;

    case 2:
        if (gSeqStatus[0] >= 2) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 7;
            op_obj_disp = 0;
            sub_0003D388(8);
            break;
        }

        op_bg_move(6);
        break;

    case 3:
        if (gSeqStatus[0] >= 3) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 8;
            op_obj_disp = 1;
            op_scrn_end = 0;
            sub_000B7DD7(22);
            break;
        }

        op_bg_move(7);
        break;

    case 4:
        if (gSeqStatus[0] >= 4) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 9;
            break;
        }

        op_bg_move(8);
        break;

    case 5:
        if (gSeqStatus[0] >= 5) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 10;
            break;
        }

        op_bg_move(9);
        break;

    case 6:
        if (gSeqStatus[0] >= 7) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 11;
            break;
        }

        op_bg_move(10);
        break;

    case 7:
        if (gSeqStatus[0] >= 8) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 12;
            op_obj_disp = 0;
            sub_0003D388(9);
            break;
        }

        op_bg_move(11);
        break;

    case 8:
        if (gSeqStatus[0] >= 9) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 13;
            op_obj_disp = 1;
            break;
        }

        op_bg_move(12);
        break;

    case 9:
        if (gSeqStatus[0] >= 11) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 14;
            op_scrn_end = 0;
            sub_000B7DD7(23);
            break;
        }

        op_bg_move(13);
        break;

    case 10:
        if (gSeqStatus[0] >= 12) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 15;
        }

        op_bg_move(14);
        break;

    case 11:
        if (gSeqStatus[0] >= 13) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 16;
            break;
        }

        op_bg_move(15);
        break;

    default:
        op_bg_move(16);
        break;
    }
}

void op_104_move(void) {
    switch (op_w.r_no_2) {
    case 0:
        op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
        op_work_clear();
        op_w.index = 17;
        op_bg_move(17);
        sub_000BE5C7(17);
        sub_000BE5C7(18);
        sub_000BE5C7(19);
        sub_000BE5C7(20);
        sub_000BE5C7(21);
        sub_000BE5C7(22);
        sub_000BE5C7(23);
        break;

    case 1:
        if (gSeqStatus[0] >= op_104_sound[op_w.r_no_2] && gSeqStatus[0] != 0x68) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 18;
            break;
        }

        op_bg_move(17);
        break;

    case 2:
        if (gSeqStatus[0] >= op_104_sound[op_w.r_no_2]) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 19;
            op_obj_disp = 0;
            sub_0003D388(10);
            break;
        }

        op_bg_move(18);
        break;

    case 3:
        if (gSeqStatus[0] >= op_104_sound[op_w.r_no_2]) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 20;
            op_obj_disp = 1;
            break;
        }

        op_bg_move(19);
        break;

    case 4:
        if (gSeqStatus[0] >= op_104_sound[op_w.r_no_2]) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 21;
            op_obj_disp = 0;
            sub_0003D388(11);
            break;
        }

        op_bg_move(20);
        break;

    case 5:
        if (gSeqStatus[0] >= op_104_sound[op_w.r_no_2]) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 22;
            op_obj_disp = 1;
            break;
        }

        op_bg_move(21);
        break;

    case 6:
        if (gSeqStatus[0] >= op_104_sound[op_w.r_no_2]) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 23;
            break;
        }

        op_bg_move(22);
        break;

    default:
        op_bg_move(23);
        break;
    }
}

void op_105_move(void) {
    switch (op_w.r_no_2) {
    case 0:
        op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
        op_work_clear();
        op_w.index = 24;
        op_bg_move(24);
        sub_000BE5C7(24);
        op_obj_disp = 0;
        sub_0003D388(12);
        break;

    case 1:
    default:
        op_bg_move(24);
        break;
    }
}

void op_106_move(void) {
    switch (op_w.r_no_2) {
    case 0:
        op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
        op_work_clear();
        op_w.index = 25;
        op_obj_disp = 1;
        op_bg_move(25);
        sub_000BE5C7(25);
        sub_000BE5C7(26);
        sub_000BE5C7(27);
        sub_000BE5C7(28);
        sub_000B7DD7(18);
        sub_000B7DD7(19);
        sub_000B7DD7(20);
        sub_000B7DD7(21);
        break;

    case 1:
        if (gSeqStatus[0] >= 1 && gSeqStatus[0] != 0x6A) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 26;
            break;
        }

        op_bg_move(25);
        break;

    case 2:
        if (gSeqStatus[0] >= 3) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 27;
            break;
        }

        op_bg_move(26);
        break;

    case 3:
        if (gSeqStatus[0] >= 7) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 28;
            op_obj_disp = 0;
            sub_0003D388(15);
            break;
        }

        op_bg_move(27);
        break;

    default:
        op_bg_move(28);
        break;
    }
}

void op_107_move(void) {
    switch (op_w.r_no_2) {
    case 0:
        op_plmove_timer = (s16)(op_plmove_timer + 1);
        op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
        op_obj_disp = 1;
        op_work_clear();
        op_w.index = 29;
        op_bg_move(29);
        sub_000BE5C7(29);
        sub_000BE5C7(30);
        sub_000BE5C7(31);
        sub_000BE5C7(32);
        sub_000BE5C7(33);
        sub_000BE5C7(34);
        break;

    case 1:
        if (gSeqStatus[0] >= 1 && gSeqStatus[0] != 0x6B) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 30;
            break;
        }

        op_bg_move(29);
        break;

    case 2:
        if (gSeqStatus[0] >= 2) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 31;
            break;
        }

        op_bg_move(30);
        break;

    case 3:
        if (gSeqStatus[0] >= 3) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 32;
            op_obj_disp = 0;
            sub_0003D388(13);
            break;
        }

        op_bg_move(31);
        break;

    case 4:
        if (gSeqStatus[0] >= 4) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 33;
            op_obj_disp = 1;
            break;
        }

        op_bg_move(32);
        break;

    case 5:
        if (gSeqStatus[0] >= 5) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 34;
            sub_000BE5C7(35);
            sub_000BE5C7(36);
            sub_000BE5C7(37);
            sub_000BE5C7(38);
            sub_000BE5C7(39);
            sub_000BE5C7(40);
            break;
        }

        op_bg_move(33);
        break;

    case 6:
        if (gSeqStatus[0] >= 7) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 35;
            break;
        }

        op_bg_move(34);
        break;

    case 7:
        if (gSeqStatus[0] >= 8) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 36;
            op_obj_disp = 0;
            sub_0003D388(14);
            break;
        }

        op_bg_move(35);
        break;

    case 8:
        if (gSeqStatus[0] >= 9) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 37;
            op_obj_disp = 1;
            break;
        }

        op_bg_move(36);
        break;

    case 9:
        if (gSeqStatus[0] >= 11) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 38;
            break;
        }

        op_bg_move(37);
        break;

    case 10:
        if (gSeqStatus[0] >= 12) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 39;
            break;
        }

        op_bg_move(38);
        break;

    case 11:
        if (gSeqStatus[0] >= 13) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 40;
            break;
        }

        op_bg_move(39);
        break;

    default:
        op_bg_move(40);
        break;
    }
}

void op_108_move(void) {
    switch (op_w.r_no_2) {
    case 0:
        op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
        op_work_clear();
        op_w.index = 41;
        op_bg_move(41);
        op_w.mv_ctr = 0;
        sub_000B7DD7(0);
        sub_000B7DD7(1);
        sub_000B7DD7(2);
        sub_000B7DD7(3);
        sub_000B7DD7(4);
        sub_000B7DD7(5);
        sub_000B7DD7(6);
        sub_000B7DD7(7);
        break;

    case 1:
        op_w.mv_ctr = (s16)(op_w.mv_ctr + 1);

        if (op_w.mv_ctr >= 4) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 42;
            op_bg_move(42);
            break;
        }

        op_bg_move(41);
        break;

    case 2:
        op_w.mv_ctr = (s16)(op_w.mv_ctr + 1);

        if (op_w.mv_ctr >= 20) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 43;
            op_bg_move(43);
            sub_000B7DD7(8);
            sub_000B7DD7(9);
            sub_000B7DD7(10);
            sub_000B7DD7(11);
            sub_000B7DD7(12);
            sub_000B7DD7(13);
            sub_000B7DD7(14);
            sub_000B7DD7(15);
        }

        break;

    case 3:
        op_w.mv_ctr = (s16)(op_w.mv_ctr + 1);

        if (op_w.mv_ctr >= 24) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 44;
            op_bg_move(44);
            break;
        }

        op_bg_move(43);
        break;

    case 4:
        op_w.mv_ctr = (s16)(op_w.mv_ctr + 1);

        if (op_w.mv_ctr >= 28) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 45;
            op_bg_move(45);
        }

        break;

    case 5:
        op_w.mv_ctr = (s16)(op_w.mv_ctr + 1);

        if (op_w.mv_ctr >= 32) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 46;
            op_bg_move(46);
            break;
        }

        op_bg_move(45);
        break;

    case 6:
        op_w.mv_ctr = (s16)(op_w.mv_ctr + 1);

        if (op_w.mv_ctr >= 48) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 47;
            op_bg_move(47);
        }

        break;

    case 7:
        op_w.mv_ctr = (s16)(op_w.mv_ctr + 1);

        if (op_w.mv_ctr >= 52) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 48;
            op_bg_move(48);
            break;
        }

        op_bg_move(47);
        break;

    case 8:
        op_w.mv_ctr = (s16)(op_w.mv_ctr + 1);

        if (op_w.mv_ctr >= 60) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 49;
            op_bg_move(49);
        }

        break;

    case 9:
        op_w.mv_ctr = (s16)(op_w.mv_ctr + 1);

        if (op_w.mv_ctr >= 64) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 50;
            op_bg_move(50);
            break;
        }

        op_bg_move(49);
        break;

    case 10:
        op_w.mv_ctr = (s16)(op_w.mv_ctr + 1);

        if (op_w.mv_ctr >= 76) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 51;
            op_bg_move(51);
        }

        break;

    case 11:
        op_w.mv_ctr = (s16)(op_w.mv_ctr + 1);

        if (op_w.mv_ctr >= 80) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 52;
            op_bg_move(52);
            break;
        }

        op_bg_move(51);
        break;

    case 12:
        op_w.mv_ctr = (s16)(op_w.mv_ctr + 1);

        if (op_w.mv_ctr >= 86) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 53;
            op_bg_move(53);
        }

        break;

    default:
        break;
    }
}

void op_109_move(void) {
    switch (op_w.r_no_2) {
    case 0:
        op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
        op_scrn_end = 0;
        op_work_clear();
        op_w.index = 54;
        op_bg_move(54);
        op_obj_disp = 0;
        sub_0003D388(16);
        break;

    case 1:
        if (gSeqStatus[0] >= 3 && gSeqStatus[0] != 0x6D) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 55;
            op_obj_disp = 1;
            break;
        }

        op_bg_move(54);
        break;

    case 2:
        if (gSeqStatus[0] >= 5) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 56;
            break;
        }

        op_bg_move(55);
        break;

    case 3:
        if (gSeqStatus[0] >= 7) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_scrn_end = 0;
            op_work_clear();
            op_w.index = 57;
            op_obj_disp = 0;
            sub_0003D388(17);
            break;
        }

        op_bg_move(56);
        break;

    case 4:
        if (gSeqStatus[0] >= 11) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 58;
            op_obj_disp = 1;
            break;
        }

        op_bg_move(57);
        break;

    default:
        op_bg_move(58);
        break;
    }
}

void op_110_move(void) {
    switch (op_w.r_no_2) {
    case 0:
        op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
        sub_000AF2F1(64);
        op_work_clear();
        op_w.index = 59;
        op_bg_move(59);
        op_obj_disp = 0;
        sub_0003D388(2);
        break;

    case 1:
        /* The PS2 threshold is 0. */
        if (gSeqStatus[0] != 0x6E) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 60;
            op_obj_disp = 1;
            break;
        }

        op_bg_move(59);
        break;

    case 2:
        if (gSeqStatus[0] >= 3) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 61;
            op_obj_disp = 0;
            sub_0003D388(3);
            break;
        }

        op_bg_move(60);
        break;

    case 3:
        if (gSeqStatus[0] >= 4) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 62;
            op_obj_disp = 1;
            break;
        }

        op_bg_move(61);
        break;

    case 4:
        if (gSeqStatus[0] >= 7) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 63;
            op_obj_disp = 0;
            sub_0003D388(4);
            break;
        }

        op_bg_move(62);
        break;

    case 5:
        if (gSeqStatus[0] >= 9) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 64;
            op_obj_disp = 1;
            break;
        }

        op_bg_move(63);
        break;

    default:
        op_bg_move(64);
        break;
    }
}

void op_111_move(void) {
    switch (op_w.r_no_2) {
    case 0:
        op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
        op_work_clear();
        op_w.index = 65;
        op_bg_move(65);
        sub_000BE5C7(41);
        sub_000BE5C7(42);
        sub_000BE5C7(43);
        break;

    case 1:
        if (gSeqStatus[0] >= 2 && gSeqStatus[0] != 0x6F) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 66;
            break;
        }

        op_bg_move(65);
        break;

    case 2:
        if (gSeqStatus[0] >= 4) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 67;
            break;
        }

        op_bg_move(66);
        break;

    case 3:
        if (gSeqStatus[0] >= 7) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 68;
            break;
        }

        op_bg_move(67);
        break;

    case 4:
        if (gSeqStatus[0] >= 11) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 69;
            break;
        }

        op_bg_move(68);
        break;

    default:
        op_bg_move(69);
        break;
    }
}

void op_112_move(void) {
    switch (op_w.r_no_2) {
    case 0:
        op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
        op_work_clear();
        op_w.index = 70;
        op_bg_move(70);
        sub_000BE5C7(54);
        sub_000BE5C7(44);
        sub_000BE5C7(45);
        sub_000BE5C7(46);
        sub_000BE5C7(47);
        sub_000BE5C7(48);
        sub_000BE5C7(49);
        sub_000BE5C7(50);
        sub_000BE5C7(51);
        break;

    case 1:
        if (gSeqStatus[0] >= 8 && gSeqStatus[0] != 0x70) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.mv_ctr = 0;
            op_w.index = 71;
            break;
        }

        op_bg_move(70);
        break;

    case 2:
        op_w.mv_ctr = (s16)(op_w.mv_ctr + 1);

        if (op_w.mv_ctr >= 8) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 72;
            break;
        }

        op_bg_move(71);
        break;

    case 3:
        op_w.mv_ctr = (s16)(op_w.mv_ctr + 1);

        if (op_w.mv_ctr >= 14) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 73;
            op_obj_disp = 0;
            sub_0003D388(18);
            break;
        }

        op_bg_move(72);
        break;

    case 4:
        op_w.mv_ctr = (s16)(op_w.mv_ctr + 1);

        if (op_w.mv_ctr >= 19) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 74;
            op_obj_disp = 1;
            break;
        }

        op_bg_move(73);
        break;

    case 5:
        op_w.mv_ctr = (s16)(op_w.mv_ctr + 1);

        if (op_w.mv_ctr >= 26) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 75;
            break;
        }

        op_bg_move(74);
        break;

    case 6:
        op_w.mv_ctr = (s16)(op_w.mv_ctr + 1);

        if (op_w.mv_ctr >= 34) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 76;
            op_obj_disp = 0;
            sub_0003D388(19);
            break;
        }

        op_bg_move(75);
        break;

    case 7:
        op_w.mv_ctr = (s16)(op_w.mv_ctr + 1);

        if (op_w.mv_ctr >= 40) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 77;
            op_obj_disp = 1;
            break;
        }

        op_bg_move(76);
        break;

    case 8:
        op_w.mv_ctr = (s16)(op_w.mv_ctr + 1);

        if (op_w.mv_ctr >= 44) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 78;
            break;
        }

        op_bg_move(77);
        break;

    default:
        op_bg_move(78);
        break;
    }
}

void op_113_move(void) {
    switch (op_w.r_no_2) {
    case 0:
        op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
        op_scrn_end = 0;
        op_work_clear();
        op_w.index = 79;
        op_bg_move(79);
        sub_000BE5C7(52);
        sub_000BE5C7(53);
        op_obj_disp = 0;
        sub_0003D388(20);
        break;

    case 1:
        if (gSeqStatus[0] >= 3 && gSeqStatus[0] != 0x71) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 80;
            op_obj_disp = 1;
            break;
        }

        op_bg_move(79);
        break;

    case 2:
        if (gSeqStatus[0] >= 7) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_scrn_end = 0;
            op_work_clear();
            op_w.index = 81;
            op_obj_disp = 0;
            sub_0003D388(21);
            break;
        }

        op_bg_move(80);
        break;

    case 3:
        if (gSeqStatus[0] >= 11) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 82;
            op_obj_disp = 1;
            break;
        }

        op_bg_move(81);
        break;

    default:
        op_bg_move(82);
        break;
    }
}

void op_114_move(void) {
    switch (op_w.r_no_2) {
    case 0:
        op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
        op_work_clear();
        op_w.index = 83;
        op_bg_move(83);
        op_obj_disp = 0;
        sub_0003D388(5);
        break;

    case 1:
        if (gSeqStatus[0] >= 2 && gSeqStatus[0] != 0x72) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 84;
            op_obj_disp = 1;
            break;
        }

        op_bg_move(83);
        break;

    case 2:
        if (gSeqStatus[0] >= 3) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 85;
            op_obj_disp = 0;
            sub_0003D388(6);
            break;
        }

        op_bg_move(84);
        break;

    case 3:
        if (gSeqStatus[0] >= 4) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 86;
            op_obj_disp = 1;
            break;
        }

        op_bg_move(85);
        break;

    case 4:
        if (gSeqStatus[0] >= 7) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            sub_000AF2F1(64);
            op_work_clear();
            op_w.index = 87;
            op_obj_disp = 0;
            sub_0003D388(7);
            break;
        }

        op_bg_move(86);
        break;

    case 5:
        if (gSeqStatus[0] >= 9) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 88;
            op_obj_disp = 1;
            break;
        }

        op_bg_move(87);
        break;

    default:
        op_bg_move(88);
        break;
    }
}

void op_115_move(void) {
    switch (op_w.r_no_2) {
    case 0:
        op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
        sub_000AF2F1(64);
        op_work_clear();
        op_w.index = 89;
        op_bg_move(89);
        sub_000B7DD7(16);
        break;

    case 1:
        if (gSeqStatus[0] >= 7 && gSeqStatus[0] != 0x73) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 90;
            break;
        }

        op_bg_move(89);
        break;

    default:
        op_bg_move(90);
        break;
    }
}

void op_116_move(void) {
    switch (op_w.r_no_2) {
    case 0:
        op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
        op_work_clear();
        op_w.index = 91;
        sub_0004384A((const char *)2);
        op_bg_move(91);
        sub_000B7DD7(17);
        sub_000B7DD7(28);
        op_w.mv_ctr = 88;
        FadeInit();
        break;

    case 1:
        op_bg_move(91);

        if (op_w.mv_ctr < 4) {
            FadeOut(0, 8, 1);
        }

        op_w.mv_ctr = (s16)(op_w.mv_ctr - 1);

        if (op_w.mv_ctr <= 0) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_w.mv_ctr = 16;
        }

        break;

    case 2:
        if (FadeOut(0, 8, 1) != 0) {
            op_w.mv_ctr = (s16)(op_w.mv_ctr - 1);

            if (op_w.mv_ctr <= 0) {
                op_w.index = 0x7FFF;
                op_end_flag = 1;
                op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            }
        }

        op_bg_move(91);
        break;

    default:
        op_bg_move(91);
        break;
    }
}

void op_117_move(void) {
    switch (op_w.r_no_2) {
    case 0:
        op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
        sub_000AF2BA();
        op_work_clear();
        op_w.index = 92;
        op_bg_move(92);
        sub_00048F0E(1, 0, 1);
        sub_00048F0E(0, 0, 1);
        sub_0004AFFA(0x10);
        sub_0004AFFA(0x11);
        sub_0004AFFA(0x12);
        sub_0004AFFA(9);
        op_bg_move(92);
        op_w.r_no_1 = (s8)(op_w.r_no_1 + 1);
        op_w.r_no_2 = 0;
        op_work_clear();
        break;
    }
}

void op_118_move(void) {
    switch (op_w.r_no_2) {
    case 0:
        op_w.mv_ctr = 60;
        op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
        break;

    case 1:
    case 4:
        op_w.mv_ctr = (s16)(op_w.mv_ctr - 1);

        if (op_w.mv_ctr < 0) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
        }

        break;

    case 2:
        if (sub_0009A8EB(0x28) != 0) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
        }

        break;

    case 3:
        if (sub_0009A934() != 0) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            Disp_Copyright();
            op_w.mv_ctr = 240;
        }

        op_w.index = 93;
        op_bg_move(93);
        break;

    case 5:
        op_end_flag = 1;
        sub_000AF4C2(14);
        op_bg_move(93);
        break;
    }
}

void op_100_move(void) {
    op_w.r_no_1 = (s8)(op_w.r_no_1 + 1);
    Go_BGM();
    op_101_move();
}
