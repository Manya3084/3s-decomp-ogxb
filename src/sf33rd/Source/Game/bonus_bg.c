/* bonus_bg.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * bns01_init00 0xB4234 size 0x7B.
 * bns02_init00 0xB42B9 size 0x71.
 * bns03_init00 0xB432A size 0x71.
 * bns01 0xB439B size 0x22.
 * bns02 0xB43BD size 0x22.
 * bns03 0xB43DF size 0x22.
 * Bonus_bg 0xB4401 size 0x47.
 * bns03_move is folded into 0x4384A with 47 other bodies. Unnamed.
 * bns02_move is folded into 0xB259E with 5 other bodies. Unnamed.
 * bns01_move is folded into 0xB42AF with 1 other bodies. Unnamed.
 * Globals: Player_id 0x7A810F, bg_app 0x7BC4A8, bgw_ptr 0x7BC510, bg_w
 * 0x7BC520.
 */

#include "structs.h"

extern BGW* bgw_ptr;
extern BG bg_w;
void bns02();
void bns01();
void bns03();
void bg_pos_hosei_sub3(s16 bg_no);
void Bg_Family_Set_appoint(s32 num_of_bg);
void bg_pos_hosei2();
void Bg_Family_Set();
void bns01_init00();
void bns01_move();
extern s8 Player_id;
extern s8 bg_app;
s32 effect_05_init();
void bg_base_x_move_check();
void bg_base_y_move_check();
void bns02_init00();
void bns02_move();
void bg_x_move_check();
void bg_y_move_check();
void bns03_init00();
void bns03_move();



void Bonus_bg() {
    bgw_ptr = &bg_w.bgw[1];
    bns02();
    bgw_ptr = &bg_w.bgw[0];
    bns01();
    bgw_ptr = &bg_w.bgw[2];
    bns03();
    bg_pos_hosei_sub3(2);
    Bg_Family_Set_appoint(2);
    bg_pos_hosei2();
    Bg_Family_Set();
}

void bns01() {
    void (*bns01_jmp[2])() = { bns01_init00, bns01_move };
    bns01_jmp[bgw_ptr->r_no_0]();
}

void bns01_init00() {
    bgw_ptr->r_no_0++;

    if (Player_id == 0) {
        bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x1C5;
    } else {
        bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x209;
    }

    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
    bg_app = 0;
    effect_05_init();
}

void bns01_move() {
    bg_base_x_move_check();
    bg_base_y_move_check();
}

void bns02() {
    void (*bns02_jmp[2])() = { bns02_init00, bns02_move };
    bns02_jmp[bgw_ptr->r_no_0]();
}

void bns02_init00() {
    bgw_ptr->r_no_0++;

    if (Player_id == 0) {
        bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x1C5;
    } else {
        bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x209;
    }

    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
}

void bns02_move() {
    bg_x_move_check();
    bg_y_move_check();
}

void bns03() {
    void (*bns03_jmp[2])() = { bns03_init00, bns03_move };
    bns03_jmp[bgw_ptr->r_no_0]();
}

void bns03_init00() {
    bgw_ptr->r_no_0++;

    if (Player_id == 0) {
        bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x1C4;
    } else {
        bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x20D;
    }

    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
}

void bns03_move() {
    // Do nothing
}
