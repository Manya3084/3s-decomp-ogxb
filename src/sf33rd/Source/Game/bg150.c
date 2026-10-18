/* bg150.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * bg1502_init00 0xB2225 size 0x83.
 * bg1502_sync_common 0xB22A8 size 0xC3.
 * bg1502 0xB236B size 0x22.
 * BG150 0xB238D size 0x3C.
 * bg1501 is folded into 0xB10A1 with 9 other bodies. Unnamed.
 * bg1501_init00 is folded into 0xB2554 with 12 other bodies. Unnamed.
 * bg1501 is folded into 0xB10A1.
 * Globals: bgw_ptr 0x7BC510, bg_w 0x7BC520.
 */

#include "structs.h"

extern BGW* bgw_ptr;
extern BG bg_w;
void bg1502();
void bg1501();
void bg1502_sync_common();
void zoom_ud_check();
void bg_pos_hosei2();
void Bg_Family_Set();
void bg1501_init00();
void bg_move_common();
void bg1502_init00();
void bg_base_move_common();
s32 effect_05_init();
s32 effect_12_init(s16 type);
s32 effect_06_init();
s32 effect_44_init(s16 type);
s32 effect_25_init(s8 num);
s32 effect_94_init(u8 type94);
s32 effect_I4_init();
s32 effect_85_init();
void sync_fam_set3(s16 my_fam);
void bg_x_move_check();
void bg_y_move_check();



void BG150() {
    bgw_ptr = &bg_w.bgw[1];
    bg1502();
    bgw_ptr = &bg_w.bgw[0];
    bg1501();
    bgw_ptr = &bg_w.bgw[2];
    bg1502_sync_common();
    zoom_ud_check();
    bg_pos_hosei2();
    Bg_Family_Set();
}

void bg1501() {
    void (*bg1501_jmp[2])() = { bg1501_init00, bg_move_common };
    bg1501_jmp[bgw_ptr->r_no_0]();
}

void bg1501_init00() {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
}

void bg1502() {
    void (*bg1502_jmp[2])() = { bg1502_init00, bg_base_move_common };
    bg1502_jmp[bgw_ptr->r_no_0]();
}

void bg1502_init00() {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
    effect_05_init();
    effect_12_init(5);
    effect_06_init();
    effect_44_init(8);
    effect_25_init(0);
    effect_94_init(0);
    effect_94_init(1);
    effect_I4_init();
    effect_85_init();
}

void bg1502_sync_common() {
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
        bgw_ptr->speed_x = 0xF000;
        bgw_ptr->speed_y = 0xF000;
        sync_fam_set3(bgw_ptr->fam_no);
        break;

    case 1:
        bg_x_move_check();
        bg_y_move_check();
        sync_fam_set3(bgw_ptr->fam_no);
        break;
    }
}
