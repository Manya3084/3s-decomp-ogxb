/* bg020.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * bg0202_init00 0xB0D14 size 0x53.
 * bg020_sync_init 0xB0D67 size 0x97.
 * bg020_sync_move 0xB0DFE size 0x13.
 * bg0202 0xB0E11 size 0x22.
 * bg020_sync_common 0xB0E33 size 0x22.
 * BG020 0xB0E55 size 0x5F.
 * bg0201 is folded into 0xB10A1 with 9 other bodies. Unnamed.
 * bg0201_init00 is folded into 0xB2554 with 12 other bodies. Unnamed.
 * bg0201 is folded into 0xB10A1.
 * Globals: bgw_ptr 0x7BC510, bg_w 0x7BC520.
 */

#include "structs.h"

void sub_000B10A1();
extern BGW* bgw_ptr;
extern BG bg_w;
void bg0202();
void bg020_sync_common();
void zoom_ud_check();
void bg_pos_hosei2();
void Bg_Family_Set_appoint(s32 num_of_bg);
void Bg_Family_Set_2_appoint(s32 num_of_bg);
void bg0201_init00();
void bg_move_common();
void bg0202_init00();
void bg_base_move_common();
s32 effect_06_init();
s32 effect_78_init();
void bg020_sync_init();
void bg020_sync_move();
void sync_fam_set3(s16 my_fam);
void bg_x_move_check();
void bg_y_move_check();



void BG020() {
    bgw_ptr = &bg_w.bgw[1];
    bg0202();
    bgw_ptr = &bg_w.bgw[0];
    sub_000B10A1();
    bgw_ptr = &bg_w.bgw[2];
    sub_000B10A1();
    bgw_ptr = &bg_w.bgw[5];
    bg020_sync_common();
    zoom_ud_check();
    bg_pos_hosei2();
    Bg_Family_Set_appoint(1);
    Bg_Family_Set_2_appoint(0);
    Bg_Family_Set_appoint(2);
}

void bg0201() {
    void (*bg0201_jmp[2])() = { bg0201_init00, bg_move_common };
    bg0201_jmp[bgw_ptr->r_no_0]();
}

void bg0201_init00() {
    bgw_ptr->r_no_0 += 1;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
}

void bg0202() {
    void (*bg0202_jmp[2])() = { bg0202_init00, bg_base_move_common };
    bg0202_jmp[bgw_ptr->r_no_0]();
}

void bg0202_init00() {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
    effect_06_init();
    effect_78_init();
}

void bg020_sync_common() {
    void (*bg020_sync_jmp[2])() = { bg020_sync_init, bg020_sync_move };
    bg020_sync_jmp[bgw_ptr->r_no_0]();
}

void bg020_sync_init() {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
    bgw_ptr->y_limit = bgw_ptr->y_limit2 = 0xF0;
    bgw_ptr->pos_y_work = 0;
    bgw_ptr->xy[1].disp.pos = 0;
    bgw_ptr->speed_x = 0xE000;
    bgw_ptr->speed_y = 0xE000;
    sync_fam_set3(5);
}

void bg020_sync_move() {
    bg_x_move_check();
    bg_y_move_check();
    sync_fam_set3(5);
}
