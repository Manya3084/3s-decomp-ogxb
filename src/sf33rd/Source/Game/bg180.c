/* bg180.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * bg1802_init00 0xB25A8 size 0x61.
 * bg1802 0xB26B3 size 0x22.
 * BG180 0xB26D5 size 0x3C.
 * bg1801 is folded into 0xB10A1 with 9 other bodies. Unnamed.
 * bg180_sync_common is folded into 0xB10E5 with 1 other bodies. Unnamed.
 * bg1801_init00 is folded into 0xB2554 with 12 other bodies. Unnamed.
 * bg1801_move is folded into 0xB259E with 5 other bodies. Unnamed.
 * bg180_sync_init is folded into 0xB2609 with 1 other bodies. Unnamed.
 * bg180_sync_move is folded into 0xB26A0 with 1 other bodies. Unnamed.
 * bg1802_move is folded into 0xB4063 with 1 other bodies. Unnamed.
 * bg1801 is folded into 0xB10A1.
 * bg180_sync_common is folded into 0xB10E5.
 * Globals: bgw_ptr 0x7BC510, bg_w 0x7BC520.
 */

#include "structs.h"

void sub_000B10A1();
void sub_000B10E5();
extern BGW* bgw_ptr;
extern BG bg_w;
void bg1802();
void zoom_ud_check();
void bg_pos_hosei2();
void Bg_Family_Set();
void bg1801_init00();
void bg1801_move();
void bg_x_move_check();
void bg_y_move_check();
void bg1802_init00();
void bg1802_move();
s32 effect_05_init();
s32 effect_06_init();
s32 effect_22_init();
s32 effect_44_init(s16 type);
void bg_base_x_move_check();
void bg_base_y_move_check();
void bg_chase_move();
void bg180_sync_init();
void bg180_sync_move();
void sync_fam_set3(s16 my_fam);



void BG180() {
    bgw_ptr = &bg_w.bgw[1];
    bg1802();
    bgw_ptr = &bg_w.bgw[0];
    sub_000B10A1();
    bgw_ptr = &bg_w.bgw[2];
    sub_000B10E5();
    zoom_ud_check();
    bg_pos_hosei2();
    Bg_Family_Set();
}

void bg1801() {
    void (*bg1801_jmp[2])() = { bg1801_init00, bg1801_move };
    bg1801_jmp[bgw_ptr->r_no_0]();
}

void bg1801_init00() {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
}

void bg1801_move() {
    bg_x_move_check();
    bg_y_move_check();
}

void bg1802() {
    void (*bg1802_jmp[2])() = { bg1802_init00, bg1802_move };
    bg1802_jmp[bgw_ptr->r_no_0]();
}

void bg1802_init00() {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
    effect_05_init();
    effect_06_init();
    effect_22_init();
    effect_44_init(4);
}

void bg1802_move() {
    bg_base_x_move_check();
    bg_base_y_move_check();
    bg_chase_move();
}

void bg180_sync_common() {
    void (*bg1800_sync_jmp[2])() = { bg180_sync_init, bg180_sync_move };
    bg1800_sync_jmp[bgw_ptr->r_no_0]();
}

void bg180_sync_init() {
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

void bg180_sync_move() {
    bg_x_move_check();
    bg_y_move_check();
    sync_fam_set3(2);
}
