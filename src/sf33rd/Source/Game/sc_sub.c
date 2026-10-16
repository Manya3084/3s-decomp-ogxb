/* FadeInit, retail sf33rd.xbe 0xE7035, size 0x8, interior after the ret.
 * FadeOut 0xE703D, size 0xD4.
 * FadeIn 0xE71DD, size 0xD4, a scanned start. While the product stays below
 * 255 its alpha is (255 - FadeLimit * step) << 24. FadeOut shifts the product
 * itself. Both draw with a fifth argument of 8.
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
