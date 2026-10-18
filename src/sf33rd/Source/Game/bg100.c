/* bg100.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * bg1000_init00 0xB1C35 size 0x6A.
 * bg1001_init00 0xB1C9F size 0x88.
 * BG100 0xB1D6B size 0x2D.
 * Not located in sf33rd.xbe; their PS2 C is kept under #if 0: bg1000, bg1001.
 * bg1000 has no XBE name and no aligned call.
 * bg1001 has no XBE name and no aligned call.
 * Globals: bgw_ptr 0x7BC510, bg_w 0x7BC520.
 */

#include "structs.h"

extern BGW* bgw_ptr;
extern BG bg_w;
void bg1001();
void bg1000();
void zoom_ud_check();
void bg_pos_hosei2();
void Bg_Family_Set();
s32 effect_29_init();
s32 effect_05_init();
s32 effect_06_init();
s32 effect_44_init(s16 type);



void BG100() {
    bgw_ptr = &bg_w.bgw[1];
    bg1001();
    bgw_ptr = &bg_w.bgw[0];
    bg1000();
    zoom_ud_check();
    bg_pos_hosei2();
    Bg_Family_Set();
}

void bg1000_init00() {
    bgw_ptr->r_no_1 = 0;
    bgw_ptr->r_no_0++;
    bgw_ptr->zuubun = 0;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->hos_xy[0].disp.pos = bgw_ptr->wxy[0].disp.pos - bg_w.pos_offset;
    bgw_ptr->hos_xy[0].disp.low = 0;
    effect_29_init();
}

void bg1001_init00() {
    bgw_ptr->r_no_1 = 0;
    bgw_ptr->r_no_0++;
    bgw_ptr->zuubun = 0;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->hos_xy[0].disp.pos = bgw_ptr->wxy[0].disp.pos - bg_w.pos_offset;
    bgw_ptr->hos_xy[0].disp.low = 0;
    bgw_ptr->wxy[1].cal = 0;
    bgw_ptr->xy[1].cal = 0;
    effect_05_init();
    effect_06_init();
    effect_44_init(5);
}

#if 0
/* PS2 C for functions not located in sf33rd.xbe yet. */

void bg1000() {
    void (*bg1000_jmp[2])() = { bg1000_init00, bg_move_common };
    bg1000_jmp[bgw_ptr->r_no_0]();
}

void bg1001() {
    void (*bg1001_jmp[2])() = { bg1001_init00, bg_base_move_common };
    bg1001_jmp[bgw_ptr->r_no_0]();
}
#endif
