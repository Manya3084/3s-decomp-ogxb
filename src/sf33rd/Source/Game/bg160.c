/* bg160.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * bg1602_init00 0xB23C9 size 0x69.
 * bg1602_sync_common 0xB2432 size 0xC4.
 * bg1602 0xB24F6 size 0x22.
 * BG160 0xB2518 size 0x3C.
 * bg1601 is folded into 0xB10A1 with 9 other bodies. Unnamed.
 * bg1601_init00 is folded into 0xB2554 with 12 other bodies. Unnamed.
 * bg1601 is folded into 0xB10A1.
 * Globals: bgw_ptr 0x7BC510, bg_w 0x7BC520.
 */

#include "structs.h"

extern BGW* bgw_ptr;
extern BG bg_w;
void bg1602();
void bg1601();
void bg1602_sync_common();
void zoom_ud_check();
void bg_pos_hosei2();
void Bg_Family_Set();
void bg1601_init00();
void bg_move_common();
void bg1602_init00();
void bg_base_move_common();
s32 effect_05_init();
s32 effect_06_init();
s32 effect_44_init(s16 type);
s32 effect_19_init();
s32 effect_94_init(u8 type94);
void sync_fam_set3(s16 my_fam);
void bg_x_move_check();
void bg_y_move_check();



void BG160() {
    bgw_ptr = &bg_w.bgw[1];
    bg1602();
    bgw_ptr = &bg_w.bgw[0];
    bg1601();
    bgw_ptr = &bg_w.bgw[2];
    bg1602_sync_common();
    zoom_ud_check();
    bg_pos_hosei2();
    Bg_Family_Set();
}

void bg1601() {
    void (*bg1601_jmp[2])() = { bg1601_init00, bg_move_common };
    bg1601_jmp[bgw_ptr->r_no_0]();
}

void bg1601_init00() {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
}

void bg1602() {
    void (*bg1602_jmp[2])() = { bg1602_init00, bg_base_move_common };
    bg1602_jmp[bgw_ptr->r_no_0]();
}

void bg1602_init00() {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
    effect_05_init();
    effect_06_init();
    effect_44_init(2);
    effect_19_init();
    effect_94_init(2);
}

void bg1602_sync_common() {
    switch (bgw_ptr->r_no_0) {
    case 0:
        bgw_ptr->r_no_0++;
        bgw_ptr->fam_no = 2;
        bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
        bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
        bgw_ptr->zuubun = 0;
        bgw_ptr->y_limit = bgw_ptr->y_limit2 = 0xF0;
        bgw_ptr->pos_y_work = 0;
        bgw_ptr->xy[1].disp.pos = 0;
        bgw_ptr->speed_x = 0x12000;
        bgw_ptr->speed_y = 0x10000;
        sync_fam_set3(bgw_ptr->fam_no);
        break;

    case 1:
        bg_x_move_check();
        bg_y_move_check();
        sync_fam_set3(bgw_ptr->fam_no);
        break;
    }
}
