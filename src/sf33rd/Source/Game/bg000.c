/* bg000.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * bg0001_init00 0xB087C size 0xF8. Read against the x86: 0xE0 and -0xC0 are
 * speed_x * 0xE0 and -= speed_x * 0xC0 as imul. The C is the PS2 C.
 * bg0000_init00 0xB0974 size 0xCF. Read against the x86: 0xE0 and -0xC0 are
 * speed_x * 0xE0 and -= speed_x * 0xC0 as imul. The C is the PS2 C.
 * bg0000_demo 0xB0A43 size 0xAB.
 * BG000 0xB0B42 size 0x2D.
 * Not located in sf33rd.xbe; their PS2 C is kept under #if 0: bg0001, bg0000.
 * bg0000 has no XBE name and no aligned call.
 * bg0001 has no XBE name and no aligned call.
 * setup_GILL_Opening_Ceremony is folded into 0x9B78F.
 * Globals: bg_app 0x7BC4A8, bgw_ptr 0x7BC510, bg_w 0x7BC520, Gill_Appear_Flag
 * 0x7C56B0, plw 0xC7CEA0.
 */

#include "structs.h"

s32 sub_0009B78F();
extern BGW* bgw_ptr;
extern BG bg_w;
void bg0001();
void bg0000();
void zoom_ud_check();
void bg_pos_hosei2();
void Bg_Family_Set();
extern s8 Gill_Appear_Flag;
s16 gill_appear_check();
void make_texcash_work(s16 ix);
s32 effect_06_init();
s32 effect_44_init(s16 type);
s32 effect_60_init(s16 type);
extern PLW plw[2];
extern s8 bg_app;



void BG000() {
    bgw_ptr = &bg_w.bgw[1];
    bg0001();
    bgw_ptr = &bg_w.bgw[0];
    bg0000();
    zoom_ud_check();
    bg_pos_hosei2();
    Bg_Family_Set();
}

void bg0001_init00() {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x1D0;
    bgw_ptr->hos_xy[0].disp.pos = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
    Gill_Appear_Flag = gill_appear_check();

    if (Gill_Appear_Flag == 0) {
        make_texcash_work(0x10);
        sub_0009B78F();
    }

    effect_06_init();
    effect_44_init(7);
    effect_60_init(2);

    if (bg_w.area) {
        bgw_ptr->r_no_0 = 2;
        return;
    } else if (Gill_Appear_Flag) {
        bgw_ptr->r_no_0 = 2;
        return;
    }

    if (plw->player_number == 0) {
        bgw_ptr->u_line = 0;
        bgw_ptr->xy[0].cal += bgw_ptr->speed_x * 0xE0;
        bgw_ptr->old_pos_x = bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
        return;
    }

    bgw_ptr->u_line = 1;
    bgw_ptr->xy[0].cal -= bgw_ptr->speed_x * 0xC0;
    bgw_ptr->old_pos_x = bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
}

void bg0000_init00() {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x1D0;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;

    if (Gill_Appear_Flag) {
        bgw_ptr->r_no_0 = 2;
        bg_app = 0;
        return;
    }

    bg_app = 1;

    if (plw->player_number == 0) {
        bgw_ptr->u_line = 0;
        bgw_ptr->xy[0].cal += bgw_ptr->speed_x * 0xE0;
        bgw_ptr->old_pos_x = bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
        return;
    }

    bgw_ptr->u_line = 1;
    bgw_ptr->xy[0].cal -= bgw_ptr->speed_x * 0xC0;
    bgw_ptr->old_pos_x = bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
}

void bg0000_demo() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->free = 0x1E;
        break;

    case 1:
        bgw_ptr->free--;

        if (bgw_ptr->free <= 0) {
            bgw_ptr->r_no_1 += 1;
        }

        break;

    case 2:
        if (bgw_ptr->u_line) {
            bgw_ptr->wxy[0].cal += bgw_ptr->speed_x;

            if (bgw_ptr->wxy[0].disp.pos > 0x1D0) {
                bgw_ptr->r_no_1 += 1;
                bgw_ptr->wxy[0].disp.pos = 0x1D0;
                bgw_ptr->wxy[0].disp.low = 0;
                bgw_ptr->xy[0].cal = bgw_ptr->wxy[0].cal;
                bgw_ptr->old_pos_x = 0x1D0;
                break;
            }
        } else {
            bgw_ptr->wxy[0].cal -= bgw_ptr->speed_x;

            if (bgw_ptr->wxy[0].disp.pos < 0x1D0) {
                bgw_ptr->r_no_1 += 1;
                bgw_ptr->wxy[0].disp.pos = 0x1D0;
                bgw_ptr->wxy[0].disp.low = 0;
                bgw_ptr->xy[0].cal = bgw_ptr->wxy[0].cal;
                bgw_ptr->old_pos_x = 0x1D0;
                break;
            }
        }
        break;

    case 3:
        bg_app = 0;
        bgw_ptr->r_no_0 = 2;
        break;
    }
}

#if 0
/* PS2 C for functions not located in sf33rd.xbe yet. */

void bg0001() {
    void (*bg0002_jmp[3])() = { bg0001_init00, bg0000_demo, bg_base_move_common };
    bg0002_jmp[bgw_ptr->r_no_0]();
}

void bg0000() {
    void (*bg0000_jmp[3])() = { bg0000_init00, bg0000_demo, bg_move_common };
    bg0000_jmp[bgw_ptr->r_no_0]();
}
#endif
