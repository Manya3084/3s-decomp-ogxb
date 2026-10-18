/* bg030.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * bg0301_init00 0xB0EB4 size 0x5D.
 * BG030 0xB0F33 size 0x2D.
 * Not located in sf33rd.xbe; their PS2 C is kept under #if 0: bg0300,
 * bg0300_init00, bg0301.
 * bg0300 has no XBE name and no aligned call.
 * bg0301 has no XBE name and no aligned call.
 * Globals: bgw_ptr 0x7BC510, bg_w 0x7BC520.
 */

#include "structs.h"

extern BGW* bgw_ptr;
extern BG bg_w;
void bg0301();
void bg0300();
void zoom_ud_check();
void bg_pos_hosei2();
void Bg_Family_Set();
s32 effect_05_init();
s32 effect_06_init();
s32 effect_71_init();
s32 effect_L2_init();



void BG030() {
    bgw_ptr = &bg_w.bgw[1];
    bg0301();
    bgw_ptr = &bg_w.bgw[0];
    bg0300();
    zoom_ud_check();
    bg_pos_hosei2();
    Bg_Family_Set();
}

void bg0301_init00() {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
    effect_05_init();
    effect_06_init();
    effect_71_init();
    effect_L2_init();
}

#if 0
/* PS2 C for functions not located in sf33rd.xbe yet. */

void bg0300() {
    void (*bg0300_jmp[2])() = { bg0300_init00, bg_move_common };
    bg0300_jmp[bgw_ptr->r_no_0]();
}

void bg0300_init00() {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
}

void bg0301() {
    void (*bg0301_jmp[2])() = { bg0301_init00, bg_base_move_common };
    bg0301_jmp[bgw_ptr->r_no_0]();
}
#endif
