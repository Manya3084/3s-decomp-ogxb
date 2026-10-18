/* bg120.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * bg1202_init00 0xB1D98 size 0x61.
 * bg_fam0C00 0xB1DF9 size 0xD9.
 * BG120 0xB1EF4 size 0x5A.
 * Not located in sf33rd.xbe; their PS2 C is kept under #if 0: bg1201,
 * bg1201_init00, bg1202.
 * bg1201 has no XBE name and no aligned call.
 * bg1202 has no XBE name and no aligned call.
 * Globals: bgw_ptr 0x7BC510, bg_w 0x7BC520.
 */

#include "structs.h"

extern BGW* bgw_ptr;
extern BG bg_w;
void bg1202();
void bg1201();
void bg_fam0C00();
void zoom_ud_check();
void bg_pos_hosei2();
void Bg_Family_Set();
s32 effect_05_init();
s32 effect_06_init();
s32 effect_55_init();
s32 effect_12_init(s16 type);
void sync_fam_set3(s16 my_fam);
void bg_x_move_check();
void bg_y_move_check();



void BG120() {
    bgw_ptr = &bg_w.bgw[1];
    bg1202();
    bgw_ptr = &bg_w.bgw[0];
    bg1201();
    bgw_ptr = &bg_w.bgw[2];
    bg_fam0C00();
    bgw_ptr = &bg_w.bgw[6];
    bg_fam0C00();
    bgw_ptr = &bg_w.bgw[5];
    bg_fam0C00();
    zoom_ud_check();
    bg_pos_hosei2();
    Bg_Family_Set();
}

void bg1202_init00() {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
    effect_05_init();
    effect_06_init();
    effect_55_init();
    effect_12_init(2);
}

void bg_fam0C00() {
    switch (bgw_ptr->r_no_0) {
    case 0:
        bgw_ptr->r_no_0++;
        bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
        bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
        bgw_ptr->xy[1].disp.pos = bgw_ptr->pos_y_work = 0;

        switch (bgw_ptr->fam_no) {
        case 2:
            bgw_ptr->speed_x = 0xC000;
            bgw_ptr->speed_y = 0x10000;
            break;
        case 6:
            bgw_ptr->speed_x = 0x9000;
            bgw_ptr->speed_y = 0x10000;
            break;
        default:
            bgw_ptr->speed_x = 0x12000;
            bgw_ptr->speed_y = 0x10000;
            break;
        }

        bgw_ptr->xy[0].disp.low = bgw_ptr->xy[1].disp.low = 0;
        bgw_ptr->y_limit = bgw_ptr->y_limit2 = 0xF0;
        sync_fam_set3(bgw_ptr->fam_no);
        break;

    default:
        // Do nothing

    case 1:
        bg_x_move_check();
        bg_y_move_check();
        sync_fam_set3(bgw_ptr->fam_no);
        break;
    }
}

#if 0
/* PS2 C for functions not located in sf33rd.xbe yet. */

void bg1201() {
    void (*bg1201_jmp[2])() = { bg1201_init00, bg_move_common };
    bg1201_jmp[bgw_ptr->r_no_0]();
}

void bg1201_init00() {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
}

void bg1202() {
    void (*bg1202_jmp[2])() = { bg1202_init00, bg_base_move_common };
    bg1202_jmp[bgw_ptr->r_no_0]();
}
#endif
