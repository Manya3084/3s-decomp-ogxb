/* Effect E9, retail sf33rd.xbe.
 * effect_E9_move is 0xBDE15 size 0x289.
 * effect_E9_init is 0xBE09E size 0x60 and is interior.
 * The pull failure jumps to its own epilogue.
 * 0xBE0FE stays unnamed.
 *
 * effect_E9_move uses SSE for the corner math and
 * passes a fifth argument, 2, to the polygon draw, as
 * the Xbox sc_sub.c draws pass 8. The draw call and its
 * ita_pos copies are shared by cases 0, 1, and 2. The
 * init stores type and the loop counter before id. The
 * C keeps the PlayStation 2 order. The float constants
 * 33.0 (0x285550), 224.0 (0x2497E4), 384.0 (0x2497E8),
 * 175.0 (0x28554C), 385.0 (0x285548), 207.0 (0x285544),
 * 16.0 (0x2197AC), 48.0 (0x249928), and 1.0 (0x2190AC)
 * were read from the image. Frame_Zoom_X is 0x7C5B94.
 * Frame_Zoom_Y is 0x7C5854. PrioBase is 0xC7E560.
 * scr_sc is 0x7C55F4. End_PL is 0x7A89CC. end_w is
 * 0x7AABF0. No_Trans is 0x7BD3C9. njDrawPolygon2D stays
 * sub_0003099A. push_effect_work stays sub_0004AC6C.
 * pull_effect_work stays sub_0004A6A8. frw is 0xC806A0
 * and each object is 0x700 bytes.
 */

#include "types.h"

typedef struct {
    s8 be_flag;
    s8 disp_flag;
    u8 pad_type[2];
    u8 type;
    u8 pad_work[1];
    s16 work_id;
    s16 id;
    u8 pad_dead[0x20 - 0xA];
    s16 dead_f;
    u8 pad_rno[2];
    s16 routine_no[8];
    u8 pad_cg[0x48 - 0x34];
    s8 cgromtype;
    u8 pad_col[0x23C - 0x49];
    s16 my_col_mode;
    s16 my_col_code;
    s16 my_priority;
    s16 my_family;
    u8 pad_end[0x388 - 0x244];
} WORK;

typedef struct {
    WORK wu;
} WORK_Other;

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
    s16 r_no_0;
    s16 r_no_1;
    s16 r_no_2;
    s16 type;
    s16 end_flag;
    s16 timer;
} END_W;

typedef u8 EffectRow[0x700];

#if defined(__i386__)
_Static_assert(__builtin_offsetof(WORK, disp_flag) == 1, "disp_flag");
_Static_assert(__builtin_offsetof(WORK, type) == 4, "type");
_Static_assert(__builtin_offsetof(WORK, work_id) == 6, "work_id");
_Static_assert(__builtin_offsetof(WORK, id) == 8, "id");
_Static_assert(__builtin_offsetof(WORK, dead_f) == 0x20, "dead_f");
_Static_assert(__builtin_offsetof(WORK, routine_no) == 0x24, "routine_no");
_Static_assert(__builtin_offsetof(WORK, cgromtype) == 0x48, "cgromtype");
_Static_assert(__builtin_offsetof(WORK, my_col_mode) == 0x23C, "my_col_mode");
_Static_assert(__builtin_offsetof(WORK, my_priority) == 0x240, "my_priority");
_Static_assert(__builtin_offsetof(WORK, my_family) == 0x242, "my_family");
_Static_assert(sizeof(WORK) == 0x388, "WORK");
_Static_assert(sizeof(PAL_CURSOR) == 0x10, "PAL_CURSOR");
#endif

extern EffectRow frw[];
extern f32 Frame_Zoom_X;
extern f32 Frame_Zoom_Y;
extern f32 PrioBase[];
extern f32 scr_sc;
extern s8 End_PL;
extern END_W end_w;
extern u8 No_Trans;

void sub_0003099A(PAL_CURSOR *poly, s32 n, f32 pri, s32 attr, s32 kind);
void sub_0004AC6C(WORK *wk);
s16 sub_0004A6A8(s16 index);

void effect_E9_move(WORK_Other *ewk) {
    PAL_CURSOR ita;
    PAL_CURSOR_P ita_p[4];
    PAL_CURSOR_P ita_pos[4];
    PAL_CURSOR_COL ita_col[4];
    f32 prio;

    ita.p = &ita_pos[0];
    ita.col = &ita_col[0];
    ita.num = 4;
    ita_col[0].color = ita_col[1].color = ita_col[2].color = ita_col[3].color = 0xFF000000;
    prio = PrioBase[ewk->wu.my_priority];

    if (ewk->wu.type < 2) {
        ita_p[0].x = ita_p[1].x = 0.0f;
        ita_p[2].x = ita_p[3].x = 384.0f * Frame_Zoom_X;

        if (ewk->wu.type == 0) {
            ita_p[0].y = ita_p[3].y = 175.0f * Frame_Zoom_Y;
            ita_p[1].y = ita_p[2].y = 224.0f * Frame_Zoom_Y;
        } else {
            ita_p[0].y = ita_p[3].y = 0.0f;
            ita_p[1].y = ita_p[2].y = 33.0f * Frame_Zoom_Y;
        }
    } else {
        ita_p[0].y = ita_p[2].y = 0.0f;
        ita_p[1].y = ita_p[3].y = 224.0f * Frame_Zoom_Y;

        if (ewk->wu.type == 2) {
            ita_p[0].x = ita_p[1].x = 0.0f;
            ita_p[2].x = ita_p[3].x = Frame_Zoom_X;
        } else {
            ita_p[0].x = ita_p[1].x = 384.0f * Frame_Zoom_X;
            ita_p[2].x = ita_p[3].x = 385.0f * Frame_Zoom_X;
        }
    }

    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;

        if (!No_Trans) {
            ita_pos[0] = ita_p[0];
            ita_pos[1] = ita_p[3];
            ita_pos[2] = ita_p[1];
            ita_pos[3] = ita_p[2];
            sub_0003099A((PAL_CURSOR *)&ita.p, 4, prio, 0x60, 2);
        }

        break;

    case 1:
        if (ewk->wu.dead_f == 1) {
            ewk->wu.routine_no[0] = 3;
            ewk->wu.disp_flag = 0;
            break;
        }

        if (End_PL == 14 && ewk->wu.type < 2) {
            if (ewk->wu.type) {
                ita_p[0].y = ita_p[3].y = 0.0f;
                ita_p[1].y = ita_p[2].y = (33.0f - ((33.0f * scr_sc) - 33.0f)) * Frame_Zoom_Y;
            } else {
                ita_p[0].y = ita_p[3].y = (224.0f - (1.0f + (48.0f - ((48.0f * scr_sc) - 48.0f)))) * Frame_Zoom_Y;
                ita_p[1].y = ita_p[2].y = 224.0f * Frame_Zoom_Y;
            }
        }

        if (end_w.r_no_0 >= 6) {
            ewk->wu.routine_no[0]++;
        }

        if (!No_Trans) {
            ita_pos[0] = ita_p[0];
            ita_pos[1] = ita_p[3];
            ita_pos[2] = ita_p[1];
            ita_pos[3] = ita_p[2];
            sub_0003099A((PAL_CURSOR *)&ita.p, 4, prio, 0x60, 2);
            break;
        }

        break;

    case 2:
        if (ewk->wu.type) {
            ita_p[0].y = ita_p[3].y = 0.0f;
            ita_p[1].y = ita_p[2].y = 16.0f * Frame_Zoom_Y;
        } else {
            ita_p[0].y = ita_p[3].y = 207.0f * Frame_Zoom_Y;
            ita_p[1].y = ita_p[2].y = 224.0f * Frame_Zoom_Y;
        }

        if (!No_Trans) {
            ita_pos[0] = ita_p[0];
            ita_pos[1] = ita_p[3];
            ita_pos[2] = ita_p[1];
            ita_pos[3] = ita_p[2];
            sub_0003099A((PAL_CURSOR *)&ita.p, 4, prio, 0x60, 2);
        }

        break;

    default:
        sub_0004AC6C(&ewk->wu);
        break;
    }
}

s32 effect_E9_init(void) {
    WORK_Other *ewk;
    s16 ix;
    s16 i;

    for (i = 0; i < 4; i++) {

        if ((ix = sub_0004A6A8(4)) == -1) {
            return -1;
        }
        ewk = (WORK_Other *)frw[ix];
        ewk->wu.id = 149;
        ewk->wu.be_flag = 1;
        ewk->wu.type = i;
        ewk->wu.work_id = 16;
        ewk->wu.cgromtype = 1;
        ewk->wu.my_col_mode = 0x4200;
        ewk->wu.my_family = 4;
        ewk->wu.my_priority = 19;
    }

    return 0;
}
