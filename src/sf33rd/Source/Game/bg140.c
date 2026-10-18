/* bg140.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * bg1401_init00 0xB20B5 size 0x5E.
 * bg1402 0xB2113 size 0xB4.
 * bg1401 0xB21C7 size 0x22.
 * BG140 0xB21E9 size 0x3C.
 * bg1400 is folded into 0xB10A1 with 9 other bodies. Unnamed.
 * bg1400_init00 is folded into 0xB2554 with 12 other bodies. Unnamed.
 * bg1400 is folded into 0xB10A1.
 * bg_move_common is folded into 0xB259E.
 * Globals: bg_app 0x7BC4A8, bgw_ptr 0x7BC510, bg_w 0x7BC520.
 */

#include "structs.h"

void sub_000B259E();
extern BGW* bgw_ptr;
extern BG bg_w;
void bg1401();
void bg1400();
void bg1402();
void zoom_ud_check();
void bg_pos_hosei2();
void Bg_Family_Set();
void bg1401_init00();
void bg_base_move_common();
extern s8 bg_app;
s32 effect_06_init();
s32 effect_12_init(s16 type);
void bg1400_init00();
void bg_move_common();



void BG140() {
    bgw_ptr = &bg_w.bgw[1];
    bg1401();
    bgw_ptr = &bg_w.bgw[0];
    bg1400();
    bgw_ptr = &bg_w.bgw[2];
    bg1402();
    zoom_ud_check();
    bg_pos_hosei2();
    Bg_Family_Set();
}

void bg1401() {
    void (*bg1401_jmp[2])() = { bg1401_init00, bg_base_move_common };
    bg1401_jmp[bgw_ptr->r_no_0]();
}

void bg1401_init00() {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
    bg_app = 0;
    effect_06_init();
    effect_12_init(0);
}

void bg1400() {
    void (*bg140_jmp[2])() = { bg1400_init00, bg_move_common };
    bg140_jmp[bgw_ptr->r_no_0]();
}

void bg1400_init00() {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
}

void bg1402() {
    switch (bgw_ptr->r_no_0) {
    case 0:
        bgw_ptr->r_no_0++;
        bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
        bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
        bgw_ptr->xy[1].disp.pos = bgw_ptr->pos_y_work = 0;
        bgw_ptr->fam_no = 2;
        bgw_ptr->xy[0].disp.low = bgw_ptr->xy[1].disp.low = 0;
        bgw_ptr->y_limit = bgw_ptr->y_limit2 = 0xF0;
        bgw_ptr->speed_x = 0xA000;
        bgw_ptr->speed_y = 0xE000;
        break;

    case 1:
        sub_000B259E();
        break;
    }
}
