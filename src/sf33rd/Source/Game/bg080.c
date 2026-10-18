/* bg080.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * bg0802_init00 0xB1639 size 0x64.
 * bg080_sync_init 0xB169D size 0xCE.
 * bg080_sync_move 0xB176B size 0x1B.
 * bg0802 0xB1786 size 0x22.
 * bg080_sync_common 0xB17A8 size 0x22.
 * BG080 0xB17CA size 0x5A.
 * bg0801 is folded into 0xB10A1 with 9 other bodies. Unnamed.
 * bg0801_init00 is folded into 0xB2554 with 12 other bodies. Unnamed.
 * bg0801 is folded into 0xB10A1.
 * Globals: bgw_ptr 0x7BC510, bg_w 0x7BC520.
 */

#include "structs.h"

void sub_000B10A1();
extern BGW* bgw_ptr;
extern BG bg_w;
void bg0802();
void bg080_sync_common();
void zoom_ud_check();
void bg_pos_hosei2();
void Bg_Family_Set();
void bg0801_init00();
void bg_move_common();
void bg0802_init00();
void bg_base_move_common();
s32 effect_05_init();
s32 effect_06_init();
s32 effect_44_init(s16 type);
s32 effect_21_init(s16 sync_index);
void bg080_sync_init();
void bg080_sync_move();
void sync_fam_set3(s16 my_fam);
void bg_x_move_check();
void bg_y_move_check();



void BG080() {
    bgw_ptr = &bg_w.bgw[1];
    bg0802();
    bgw_ptr = &bg_w.bgw[0];
    sub_000B10A1();
    bgw_ptr = &bg_w.bgw[2];
    bg080_sync_common();
    bgw_ptr = &bg_w.bgw[5];
    bg080_sync_common();
    bgw_ptr = &bg_w.bgw[6];
    bg080_sync_common();
    zoom_ud_check();
    bg_pos_hosei2();
    Bg_Family_Set();
}

void bg0801() {
    void (*bg0801_jmp[2])() = { bg0801_init00, bg_move_common };
    bg0801_jmp[bgw_ptr->r_no_0]();
}

void bg0801_init00() {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
}

void bg0802() {
    void (*bg0802_jmp[2])() = { bg0802_init00, bg_base_move_common };
    bg0802_jmp[bgw_ptr->r_no_0]();
}

void bg0802_init00() {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
    effect_05_init();
    effect_06_init();
    effect_44_init(0);
    effect_21_init(0);
}

void bg080_sync_common() {
    void (*bg080_sync_jmp[2])() = { bg080_sync_init, bg080_sync_move };
    bg080_sync_jmp[bgw_ptr->r_no_0]();
}

void bg080_sync_init() {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
    bgw_ptr->y_limit = bgw_ptr->y_limit2 = 0xF0;
    bgw_ptr->pos_y_work = 0;
    bgw_ptr->xy[1].disp.pos = 0;

    switch (bgw_ptr->fam_no) {
    case 2:
        bgw_ptr->speed_x = 0xC000;
        bgw_ptr->speed_y = 0xFC00;
        break;

    case 5:
        bgw_ptr->speed_x = 0xB000;
        bgw_ptr->speed_y = 0xFC00;
        break;

    case 6:
        bgw_ptr->speed_x = 0x7000;
        bgw_ptr->speed_y = 0xF100;
        break;
    }

    sync_fam_set3(bgw_ptr->fam_no);
}

void bg080_sync_move() {
    bg_x_move_check();
    bg_y_move_check();
    sync_fam_set3(bgw_ptr->fam_no);
}
