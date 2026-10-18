/* bg190.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * bg1901_init00 0xB2711 size 0x4A.
 * bg1902_init00 0xB275B size 0x69.
 * sync_bg14_common 0xB27C4 size 0xC6.
 * BG190 0xB28CE size 0x3C.
 * Not located in sf33rd.xbe; their PS2 C is kept under #if 0: bg1901, bg1902.
 * bg1901 has no XBE name and no aligned call.
 * bg1902 has no XBE name and no aligned call.
 * Globals: bgw_ptr 0x7BC510, bg_w 0x7BC520.
 */

#include "structs.h"

extern BGW* bgw_ptr;
extern BG bg_w;
void bg1902();
void bg1901();
void sync_bg14_common();
void zoom_ud_check();
void bg_pos_hosei2();
void Bg_Family_Set();
s32 effect_05_init();
s32 effect_06_init();
s32 effect_L4_init();
s32 effect_44_init(s16 type);
s32 effect_12_init(s16 type);
void sync_fam_set3(s16 my_fam);
void bg_x_move_check();
void bg_y_move_check();



void BG190() {
    bgw_ptr = &bg_w.bgw[1];
    bg1902();
    bgw_ptr = &bg_w.bgw[0];
    bg1901();
    bgw_ptr = &bg_w.bgw[2];
    sync_bg14_common();
    zoom_ud_check();
    bg_pos_hosei2();
    Bg_Family_Set();
}

void bg1901_init00() {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x1D0;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
}

void bg1902_init00() {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x1D0;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
    effect_05_init();
    effect_06_init();
    effect_L4_init();
    effect_44_init(6);
    effect_12_init(3);
}

void sync_bg14_common() {
    switch (bgw_ptr->r_no_0) {
    case 0:
        bgw_ptr->r_no_0++;
        bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x1D0;
        bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
        bgw_ptr->xy[1].disp.pos = bgw_ptr->pos_y_work = 0;
        bgw_ptr->fam_no = 2;
        bgw_ptr->xy[0].disp.low = bgw_ptr->xy[1].disp.low = 0;
        bgw_ptr->y_limit = bgw_ptr->y_limit2 = 0xF0;
        bgw_ptr->speed_x = 0xD000;
        bgw_ptr->speed_y = 0xE000;
        sync_fam_set3(2);
        break;

    case 1:
        bg_x_move_check();
        bg_y_move_check();
        sync_fam_set3(2);
        break;
    }
}

#if 0
/* PS2 C for functions not located in sf33rd.xbe yet. */

void bg1901() {
    void (*bg1901_jmp[2])() = { bg1901_init00, bg_move_common };
    bg1901_jmp[bgw_ptr->r_no_0]();
}

void bg1902() {
    void (*bg1902_jmp[2])() = { bg1902_init00, bg_base_move_common };
    bg1902_jmp[bgw_ptr->r_no_0]();
}
#endif
