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
 * OPBG_Init 0x6A400, size 0xDC, interior after the ret.
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
 * only caller of sound_trg_init. 0x4384A, 0x59FD2, 0x13EFE, 0xF2B0A,
 * 0xF2CFD, 0xF3F82, 0xF31A8, 0x97103, 0x1C902, 0x1C8ED, 0xAF2F1, 0xAFAE3,
 * 0xAFB26, 0x30AAF, 0xAF4DC, 0xAF4E9, 0xAF520, 0xAF086, 0xD0E20, 0xF416A,
 * 0xB58A7, 0xEF72E, and 0x629B7 stay unnamed.
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

#if defined(__i386__)
_Static_assert(sizeof(OPTW_Small) == 0x10, "OPTW_Small");
_Static_assert(sizeof(OPBW) == 0x10C, "OPBW");
_Static_assert(sizeof(OP_W) == 0x330, "OP_W");
_Static_assert(__builtin_offsetof(OPBW, map) == 0xC, "OPBW.map");
_Static_assert(__builtin_offsetof(OP_W, bgw) == 0xC, "OP_W.bgw");
_Static_assert(__builtin_offsetof(Texture, textures) == 0x10, "Texture.textures");
_Static_assert(sizeof(BackgroundParameters) == 4, "BackgroundParameters");
_Static_assert(sizeof(MultiTexture) == 0x64, "MultiTexture");
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
