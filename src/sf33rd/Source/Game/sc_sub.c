/* FadeInit, retail sf33rd.xbe 0xE7035, size 0x8, interior after the ret.
 * FadeOut 0xE703D, size 0xD4.
 * FadeIn 0xE71DD, size 0xD4, a scanned start. While the product stays below
 * 255 its alpha is (255 - FadeLimit * step) << 24. FadeOut shifts the product
 * itself. Both draw with a fifth argument of 8.
 * ToneDown 0xE740C, size 0x8F, a scanned start. The color is tone << 24 and
 * the draw's fifth argument is 8. 0xE737D does the same steps with fifth
 * argument 2, so it stays unnamed.
 * player_name 0xE749B, size 0xA9, a scanned start. stun_mark_write 0xE7544,
 * size 0x64, is interior. max_mark_write 0xE75A8, size 0x53, is a scanned
 * start. My_char[0] and My_char[1] are the two bytes of the word at 0x7A8114.
 * omop_cockpit is the s16 at 0x7C5C6C. omop_st_bar_disp is the s16 pair at
 * 0x7C5C60. ppgScrList is 0x7A7EE0. Player_Name_Pos_TBL is 0x2AE74C.
 * smark_pos_tbl is 0x2AE728 and smark_kind_tbl is 0x2AE730. Max_Pos_TBL is
 * 0x2AE778. Those tables match the PS2 bytes. 0xE61FE and 0xE63C8 stay unnamed.
 * FadeLimit is the byte at 0x7A9AAC. No_Trans is the byte at 0x7BD3C9.
 * Fade_Pos_tbl is 0x2AE77C and holds 0, 0, 639, 0, 0, 448, 639, 448.
 * Positions are converted to float. PrioBase is the float table at 0xC7E560.
 * The draw takes a fifth argument, 8. 0x30556 and 0x3099A stay unnamed.
 */

#include "types.h"

typedef struct {
    f32 x;
    f32 y;
} PAL_CURSOR_P;

typedef struct {
    u32 color;
} PAL_CURSOR_COL;

typedef struct {
    PAL_CURSOR_P *p;
    PAL_CURSOR_COL *col;
    PAL_CURSOR_COL *tex;
    u32 num;
} PAL_CURSOR;

#if defined(__i386__)
_Static_assert(sizeof(PAL_CURSOR_P) == 8, "PAL_CURSOR_P");
_Static_assert(sizeof(PAL_CURSOR) == 0x10, "PAL_CURSOR");
#endif

extern u8 No_Trans;
extern u8 FadeLimit;
extern const s16 Fade_Pos_tbl[8];
extern f32 PrioBase[];
extern void sub_00030556(s32 mode, s32 blend);
extern void sub_0003099A(PAL_CURSOR *poly, s32 n, f32 pri, s32 attr, s32 kind);

typedef struct PPGDataList PPGDataList;

extern s16 omop_cockpit;
extern s16 omop_st_bar_disp[2];
extern u8 My_char[2];
extern PPGDataList ppgScrList;
extern const u8 Player_Name_Pos_TBL[21][2];
extern const u8 smark_pos_tbl[3][2];
extern const u8 smark_kind_tbl[3];
extern const u8 Max_Pos_TBL[2][2];
extern void ppgSetupCurrentDataList(PPGDataList *dlist);
extern s32 chkNameAkuma(s32 plnum, s32 rnum);
extern void sub_000E61FE(u16 x, u16 y, u8 atr, u8 page, u8 cx1, u8 cy1, u8 cx2, u8 cy2, u16 priority);
extern void sub_000E63C8(u16 x, u16 y, u8 atr, u8 inverse, u8 page, u8 cx1, u8 cy1, u8 cx2, u8 cy2);

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

    sub_00030556(0, 1);
    fade_pc.p = fade_p;
    fade_pc.col = fade_col;
    fade_pc.num = 4;

    if ((u32)FadeLimit * step < 255) {
        Alpha = ((u32)FadeLimit * step) << 24;
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

    sub_0003099A(&fade_pc, 4, PrioBase[priority], 0x60, 8);

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

    sub_00030556(0, 1);
    fade_pc.p = fade_p;
    fade_pc.col = fade_col;
    fade_pc.num = 4;

    if ((u32)FadeLimit * step < 255) {
        Alpha = (u32)(255 - (u32)FadeLimit * step) << 24;
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

    sub_0003099A(&fade_pc, 4, PrioBase[priority], 0x60, 8);

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

    sub_00030556(0, 1);
    tone_pc.p = tone_p;
    tone_pc.col = tone_col;
    tone_pc.num = 4;

    for (i = 0; i < 4; i++) {
        tone_col[i].color = (u32)tone << 24;
        tone_p[i].x = (f32)Fade_Pos_tbl[i * 2];
        tone_p[i].y = (f32)Fade_Pos_tbl[i * 2 + 1];
    }

    sub_0003099A(&tone_pc, 4, PrioBase[priority], 0x60, 8);
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
    sub_000E61FE(6, 3, 1, 1, Player_Name_Pos_TBL[pl1][0], Player_Name_Pos_TBL[pl1][1], 5, 1, 2);
    sub_000E61FE(37, 3, 1, 1, Player_Name_Pos_TBL[pl2][0], Player_Name_Pos_TBL[pl2][1], 5, 1, 2);
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
    sub_000E61FE(smark_pos_tbl[tlen][Pl_Num], 3, 10, 0, (smark_kind_tbl[tlen] * 4) + 1, 2,
        smark_kind_tbl[tlen] + 4, 1, 2);
}

void max_mark_write(s8 Pl_Num, u8 Gauge_Len, u8 Mchar, u8 Mass_Len) {
    if (Pl_Num == 0) {
        sub_000E63C8(Mass_Len + 6, 26, 17, 0, 0, Max_Pos_TBL[Mchar - 5][0], Max_Pos_TBL[Mchar - 5][1], Mchar, 1);
    } else {
        sub_000E63C8(42 - Gauge_Len + Mass_Len, 26, 17, 0, 0, Max_Pos_TBL[Mchar - 5][0],
            Max_Pos_TBL[Mchar - 5][1], Mchar, 1);
    }
}
