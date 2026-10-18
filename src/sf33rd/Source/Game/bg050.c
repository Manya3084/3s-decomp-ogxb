/* bg050.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * bg0502_init00 0xB104E size 0x53.
 * bg0502 0xB10C3 size 0x22.
 * BG050 0xB1107 size 0x3C.
 * bg0501 is folded into 0xB10A1 with 9 other bodies. Unnamed.
 * bg050_sync_common is folded into 0xB10E5 with 1 other bodies. Unnamed.
 * bg0501_init00 is folded into 0xB2554 with 12 other bodies. Unnamed.
 * bg050_sync_init is folded into 0xB2609 with 1 other bodies. Unnamed.
 * bg050_sync_move is folded into 0xB26A0 with 1 other bodies. Unnamed.
 * bg0501 is folded into 0xB10A1.
 * bg050_sync_common is folded into 0xB10E5.
 * Globals: bgw_ptr 0x7BC510, bg_w 0x7BC520.
 */

#include "structs.h"

extern BGW* bgw_ptr;
extern BG bg_w;
void bg0502();
void bg0501();
void bg050_sync_common();
void zoom_ud_check();
void bg_pos_hosei2();
void Bg_Family_Set();
void bg0501_init00();
void bg_move_common();
void bg0502_init00();
void bg_base_move_common();
s32 effect_05_init();
s32 effect_06_init();
void bg050_sync_init();
void bg050_sync_move();
void sync_fam_set3(s16 my_fam);
void bg_x_move_check();
void bg_y_move_check();



void BG050() {
    bgw_ptr = &bg_w.bgw[1];
    bg0502();
    bgw_ptr = &bg_w.bgw[0];
    bg0501();
    bgw_ptr = &bg_w.bgw[2];
    bg050_sync_common();
    zoom_ud_check();
    bg_pos_hosei2();
    Bg_Family_Set();
}

void bg0501() {
    void (*bg0501_jmp[2])() = { bg0501_init00, bg_move_common };
    bg0501_jmp[bgw_ptr->r_no_0]();
}

void bg0501_init00() {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
}

void bg0502() {
    void (*bg0502_jmp[2])() = { bg0502_init00, bg_base_move_common };
    bg0502_jmp[bgw_ptr->r_no_0]();
}

void bg0502_init00() {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
    effect_05_init();
    effect_06_init();
}

void bg050_sync_common() {
    void (*bg050_sync_jmp[2])() = { bg050_sync_init, bg050_sync_move };
    bg050_sync_jmp[bgw_ptr->r_no_0]();
}

void bg050_sync_init() {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
    bgw_ptr->y_limit = bgw_ptr->y_limit2 = 0xF0;
    bgw_ptr->pos_y_work = 0;
    bgw_ptr->xy[1].disp.pos = 0;
    bgw_ptr->speed_x = 0xE000;
    bgw_ptr->speed_y = 0xE000;
    sync_fam_set3(2);
}

void bg050_sync_move() {
    bg_x_move_check();
    bg_y_move_check();
    sync_fam_set3(2);
}
