/* bg070.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * bg0701_init00 0xB1397 size 0x6E.
 * bg0702_init00 0xB1405 size 0x5B.
 * bg0703 0xB1460 size 0xC6.
 * bg0704_init00 0xB1526 size 0x62.
 * bg0701 0xB1588 size 0x22.
 * bg0702 0xB15AA size 0x22.
 * bg0704 0xB15CC size 0x22.
 * BG070 0xB15EE size 0x4B.
 * Not located in sf33rd.xbe; their PS2 C is kept under #if 0: bg0701_move00,
 * bg0704_move00.
 * Globals: bgw_ptr 0x7BC510, bg_w 0x7BC520.
 */

#include "structs.h"

extern BGW* bgw_ptr;
extern BG bg_w;
void bg0702();
void bg0701();
void bg0704();
void bg0703();
void zoom_ud_check();
void bg_pos_hosei2();
void Bg_Family_Set();
void bg0701_init00();
void bg0701_move00();
void bg0702_init00();
void bg_base_move_common();
s32 effect_06_init();
s32 effect_94_init(u8 type94);
s32 effect_J8_init();
void sync_fam_set3(s16 my_fam);
void bg_x_move_check();
void bg_y_move_check();
void bg0704_init00();
void bg0704_move00();



void BG070() {
    bgw_ptr = &bg_w.bgw[1];
    bg0702();
    bgw_ptr = &bg_w.bgw[0];
    bg0701();
    bgw_ptr = &bg_w.bgw[2];
    bg0704();
    bgw_ptr = &bg_w.bgw[5];
    bg0703();
    zoom_ud_check();
    bg_pos_hosei2();
    Bg_Family_Set();
}

void bg0701() {
    void (*bg0701_jmp[2])() = { bg0701_init00, bg0701_move00 };
    bg0701_jmp[bgw_ptr->r_no_0]();
}

void bg0701_init00() {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->xy[1].disp.pos = bgw_ptr->wxy[1].disp.pos = bgw_ptr->pos_y_work = 0x10;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0xE3;
}

void bg0702() {
    void (*bg0702_jmp[2])() = { bg0702_init00, bg_base_move_common };
    bg0702_jmp[bgw_ptr->r_no_0]();
}

void bg0702_init00() {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
    effect_06_init();
    effect_94_init(3);
    effect_J8_init();
}

void bg0703() {
    switch (bgw_ptr->r_no_0) {
    case 0:
        bgw_ptr->r_no_0 += 1;
        bgw_ptr->fam_no = 5;
        bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
        bgw_ptr->xy[0].disp.low = bgw_ptr->xy[1].disp.low = 0;
        bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
        bgw_ptr->xy[1].disp.pos = bgw_ptr->pos_y_work = 0;
        bgw_ptr->y_limit = bgw_ptr->y_limit2 = 0xC0;
        bgw_ptr->speed_x = 0xE000;
        bgw_ptr->speed_y = 0xF800;
        sync_fam_set3(5);
        break;

    case 1:
        bg_x_move_check();
        bg_y_move_check();
        sync_fam_set3(5);
        break;
    }
}

void bg0704() {
    void (*bg0704_jmp[2])() = { bg0704_init00, bg0704_move00 };
    bg0704_jmp[bgw_ptr->r_no_0]();
}

void bg0704_init00() {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->xy[1].disp.pos = bgw_ptr->wxy[1].disp.pos = bgw_ptr->pos_y_work = 0x10;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
}

#if 0
/* PS2 C for functions not located in sf33rd.xbe yet. */

void bg0701_move00() {
    bg_x_move_check();
    bg_y_move_check();
}

void bg0704_move00() {
    bg_x_move_check();
    bg_y_move_check();
}
#endif
