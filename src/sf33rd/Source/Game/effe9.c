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
 * njDrawPolygon2D. push_effect_work is 0x4AC6C.
 * pull_effect_work is 0x4A6A8. frw is 0xC806A0
 * and each object is 0x700 bytes.
 */

#include "types.h"
#include "structs.h"







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
extern u8 End_PL;
extern END_W end_w;
extern u8 No_Trans;

void njDrawPolygon2D(PAL_CURSOR *poly, s32 n, f32 pri, s32 attr, s32 kind);
void push_effect_work(WORK *wk);
s16 pull_effect_work(s16 index);

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
            njDrawPolygon2D((PAL_CURSOR *)&ita.p, 4, prio, 0x60, 2);
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
            njDrawPolygon2D((PAL_CURSOR *)&ita.p, 4, prio, 0x60, 2);
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
            njDrawPolygon2D((PAL_CURSOR *)&ita.p, 4, prio, 0x60, 2);
        }

        break;

    default:
        push_effect_work(&ewk->wu);
        break;
    }
}

s32 effect_E9_init(void) {
    WORK_Other *ewk;
    s16 ix;
    s16 i;

    for (i = 0; i < 4; i++) {

        if ((ix = pull_effect_work(4)) == -1) {
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
