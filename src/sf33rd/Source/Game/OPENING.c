/* TITLE_Init, retail sf33rd.xbe 0x69786, size 0xC9.
 * TITLE_Move 0x6984F, size 0x11B, interior after the ret.
 * sound_trg_move 0x6997B, size 0x32, interior after the ret.
 *
 * Country is the byte at 0x7A8748. Opening_Now is the word at 0x7968A8.
 * ppgTitleList is 0x7A7E40 and ppgTitleTex is 0x7A7DC0. title_tex_flag is
 * the word at 0xC7E19E. op_w.r_no_0 is the byte at 0xC7E1C0. op_timer0 is
 * the word at 0xC7E4F0. scr_sc is the float at 0x7C55F4. title[0] and
 * title[1] both hold 0x25F3E8. music_scene is the word at 0xC7E190.
 * op_plmove_timer is the word at 0xC7E19C. gSeqStatus[0] is the byte at
 * 0xC7C836. The time table is 0x25F4C8 and the trigger table is 0x25F6D0.
 * Both tables are the 257 PS2 entries, ending in -1.
 *
 * The load index is 0x54 when Country is 1 or 2, and 0x53 otherwise.
 * The body also stores 1 at 0x32F858. Put_char is called with priority 2.
 * State 2 steps the timer on every call. 0x4384A, 0x59FD2, 0x13EFE,
 * 0xF2B0A, 0xF2CFD, 0xF3F82, 0xF31A8, 0x97103, 0x1C902, 0x1C8ED,
 * 0xAF2F1, 0xAFAE3, 0xAFB26, and 0x30AAF stay unnamed.
 */

#include "types.h"

typedef struct Texture Texture;
typedef struct Palette Palette;

typedef struct {
    Texture *tex;
    Palette *pal;
} PPGDataList;

typedef struct {
    s8 r_no_0;
} OP_W;

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
extern s16 op_plmove_timer;
extern const s16 sound_time_tbl[];
extern const s16 sound_trg_tbl[];
extern u8 gSeqStatus[1];

extern void ppgSetupCurrentDataList(PPGDataList *dlist);
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
