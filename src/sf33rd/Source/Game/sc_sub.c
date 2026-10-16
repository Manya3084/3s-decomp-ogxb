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
 * 0x2AE778. Those tables match the PS2 bytes.
 * scfont_put is 0xE6008 size 0x1B7. scfont_put2 is 0xE61BF size 0x3F.
 * scfont_sqput is 0xE61FE size 0x1CA. scfont_sqput2 is 0xE63C8 size 0xDD.
 * scfont_sqput3 is 0xE64A5 size 0x1BB. All five are scanned starts.
 * UVs are (value + 0.5) / 256 and (value - 0.5) / 256. 256.0f is 0x2AEE58
 * and 0.5f is 0x2190F0. sa_frame is 0x7A9AC0, three rows of 48. scrscrntex
 * is 0x7A9D00 and each vertex is 0x18 bytes. bigger_col_tbl is 0x2AED18 and
 * matches the 11 PS2 rows. 0x1C8ED, 0x309C1, 0x3069E, and 0x3065C stay unnamed.
 * FadeLimit is the byte at 0x7A9AAC. No_Trans is the byte at 0x7BD3C9.
 * Fade_Pos_tbl is 0x2AE77C and holds 0, 0, 639, 0, 0, 448, 639, 448.
 * Positions are converted to float. PrioBase is the float table at 0xC7E560.
 * The draw takes a fifth argument, 8. 0x30556 and 0x3099A stay unnamed.
 * sc_clear is 0xE6660 size 0x79. vital_put is 0xE66D9 size 0x178.
 * silver_vital_put is 0xE6851 size 0x11A and is interior. vital_base_put
 * is 0xE696B size 0xD7. spgauge_base_put is 0xE6A42 size 0x100. stun_put
 * is 0xE6B42 size 0x14A. stun_base_put is 0xE6C8C size 0xED. WipeInit is
 * 0xE6D79 size 0x8 and is interior. SA_shadow_on is the byte at 0x7A82EE.
 * omop_sa_bar_disp is the s16 pair at 0x7C5C64. WipeLimit is the byte at
 * 0x7A9AA7. The gauge polygons pass 2 as the fifth argument. stun_put draws
 * with kind 0 and does not call the blend. The 8/256 and 224/256 edges are
 * raw divisions. The v edges are (value + 0.5) / 256. 0xE6D81 and 0xE6EDE
 * stay unnamed: both strip edges are i - WipeLimit + 7, only 0xE6D81
 * increments WipeLimit, and neither calls overwrite_panel.
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

typedef struct {
    u8 atr;
    u8 page;
    u8 cx;
    u8 cy;
} SAFrame;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
    f32 u;
    f32 v;
    u32 col;
} Polygon;

#if defined(__i386__)
_Static_assert(sizeof(PAL_CURSOR_P) == 8, "PAL_CURSOR_P");
_Static_assert(sizeof(PAL_CURSOR) == 0x10, "PAL_CURSOR");
_Static_assert(sizeof(SAFrame) == 4, "SAFrame");
_Static_assert(sizeof(Polygon) == 0x18, "Polygon");
#endif

extern u8 No_Trans;
extern u8 FadeLimit;
extern const s16 Fade_Pos_tbl[8];
extern f32 PrioBase[];
extern f32 Frame_Zoom_X;
extern f32 Frame_Zoom_Y;
extern SAFrame sa_frame[3][48];
extern Polygon scrscrntex[4];
extern const u32 bigger_col_tbl[11][4];
extern void sub_00030556(s32 mode, s32 blend);
extern void sub_0003099A(PAL_CURSOR *poly, s32 n, f32 pri, s32 attr, s32 kind);
extern void sub_0001C8ED(s32 mode);
extern void sub_000309C1(s32 page, s32 bank);
extern void sub_0003069E(Polygon *poly, s32 n, s32 page, s32 kind);
extern void sub_0003065C(Polygon *poly, s32 n, s32 page, s32 kind);

typedef struct PPGDataList PPGDataList;

extern s16 omop_cockpit;
extern s16 omop_st_bar_disp[2];
extern s16 omop_sa_bar_disp[2];
extern s8 SA_shadow_on;
extern u8 WipeLimit;
extern u8 My_char[2];
extern PPGDataList ppgScrList;
extern const u8 Player_Name_Pos_TBL[21][2];
extern const u8 smark_pos_tbl[3][2];
extern const u8 smark_kind_tbl[3];
extern const u8 Max_Pos_TBL[2][2];
extern void ppgSetupCurrentDataList(PPGDataList *dlist);
extern s32 chkNameAkuma(s32 plnum, s32 rnum);

#if defined(__i386__)
_Static_assert(sizeof(sa_frame) == 0x240, "sa_frame");
_Static_assert(sizeof(scrscrntex) == 0x60, "scrscrntex");
#endif

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

void scfont_put(u16 x, u16 y, u8 atr, u8 page, u8 cx, u8 cy, u16 priority) {
    s32 u;
    s32 v;

    if (No_Trans) {
        return;
    }

    ppgSetupCurrentDataList(&ppgScrList);
    sub_0001C8ED(0);
    sub_00030556(0, 1);
    scrscrntex[0].col = scrscrntex[3].col = -1;
    scrscrntex[0].z = scrscrntex[3].z = PrioBase[priority];
    sub_000309C1(page, atr & 0x3F);
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
    sub_0003069E(scrscrntex, 4, page, 1);
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
    sub_0001C8ED(0);
    sub_00030556(0, 1);
    scrscrntex[0].col = scrscrntex[3].col = -1;
    scrscrntex[0].z = scrscrntex[3].z = PrioBase[priority];
    sub_000309C1(page, atr & 0x3F);
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
    sub_0003069E(scrscrntex, 4, page, 1);
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
    sub_0001C8ED(0);
    sub_00030556(0, 1);

    for (i = 0; i < 4; i++) {
        scrscrntex[i].col = bigger_col_tbl[gr][i];
    }

    scrscrntex[0].z = scrscrntex[1].z = scrscrntex[2].z = scrscrntex[3].z = PrioBase[priority];
    sub_000309C1(page, atr & 0x3F);
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
    sub_0003065C(scrscrntex, 4, page, 1);
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
    sub_0001C8ED(0);

    if (vital == -1) {
        vital = 0;
    }

    scrscrntex[0].z = scrscrntex[3].z = PrioBase[priority];
    sub_000309C1(0, atr & 0x3F);

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
    sub_00030556(0, 1);
    scrscrntex[0].col = scrscrntex[3].col = -1;
    sub_0003069E(scrscrntex, 4, 0, 1);
}

void silver_vital_put(u8 Pl_Num) {
    if (No_Trans) {
        return;
    }

    ppgSetupCurrentDataList(&ppgScrList);
    sub_0001C8ED(0);
    scrscrntex[0].z = scrscrntex[3].z = PrioBase[2];
    sub_000309C1(0, 9);
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
    sub_00030556(0, 1);
    scrscrntex[0].col = scrscrntex[3].col = -1;
    sub_0003069E(scrscrntex, 4, 0, 1);
}

void vital_base_put(u8 Pl_Num) {
    PAL_CURSOR vtx;
    PAL_CURSOR_P pos[4];
    PAL_CURSOR_COL col;

    if (No_Trans || SA_shadow_on) {
        return;
    }

    sub_00030556(0, 1);
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
    sub_0003099A(&vtx, 4, PrioBase[4], 0x60, 2);
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

    sub_00030556(0, 1);
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
    sub_0003099A(&vtx, 4, PrioBase[4], 0x60, 2);
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
    sub_0001C8ED(0);
    scrscrntex[0].z = scrscrntex[3].z = PrioBase[4];
    sub_000309C1(0, 10);
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
    sub_0003069E(scrscrntex, 4, 0, 0);
}

void stun_base_put(u8 Pl_Num, s16 len) {
    PAL_CURSOR vtx;
    PAL_CURSOR_P pos[4];
    PAL_CURSOR_COL col;

    if (No_Trans || SA_shadow_on) {
        return;
    }

    sub_00030556(0, 1);
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
    sub_0003099A(&vtx, 4, PrioBase[4], 0x60, 2);
}

void WipeInit(void) {
    WipeLimit = 0;
}
