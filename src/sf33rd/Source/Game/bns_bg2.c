/* bns_bg2.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * bns11_init00 0xB4072 size 0xAF.
 * bns12_init00 0xB4121 size 0x66.
 * bns11 0xB4187 size 0x22.
 * bns12 0xB41A9 size 0x22.
 * bns13 0xB41CB size 0x22.
 * Bonus_bg2 0xB41ED size 0x47.
 * bns13_move is folded into 0x4384A with 58 other bodies. Unnamed.
 * bns13_init00 is folded into 0xB2554 with 12 other bodies. Unnamed.
 * bns12_move is folded into 0xB259E with 5 other bodies. Unnamed.
 * bns11_move is folded into 0xB42AF with 1 other bodies. Unnamed.
 * Globals: Player_id 0x7A810F, bg_app 0x7BC4A8, bgw_ptr 0x7BC510, bg_w
 * 0x7BC520, plw 0xC7CEA0.
 */

#include "structs.h"

extern BGW* bgw_ptr;
extern BG bg_w;
void bns11();
void bns12();
void bns13();
void bg_pos_hosei_sub3(s16 bg_no);
void Bg_Family_Set_appoint(s32 num_of_bg);
void bg_pos_hosei2();
void Bg_Family_Set();
void bns11_init00();
void bns11_move();
extern s8 Player_id;
extern s8 bg_app;
s32 effect_05_init();
s32 effect_12_init(s16 type);
extern PLW plw[2];
s32 effect_35_init(s16 wait_timer, s16 c_type);
void bg_base_x_move_check();
void bg_base_y_move_check();
void bns12_init00();
void bns12_move();
void bg_x_move_check();
void bg_y_move_check();
void bns13_init00();
void bns13_move();



void Bonus_bg2() {
    bgw_ptr = &bg_w.bgw[1];
    bns11();
    bgw_ptr = &bg_w.bgw[0];
    bns12();
    bgw_ptr = &bg_w.bgw[2];
    bns13();
    bg_pos_hosei_sub3(2);
    Bg_Family_Set_appoint(2);
    bg_pos_hosei2();
    Bg_Family_Set();
}

void bns11() {
    void (*bns11_jmp[2])() = { bns11_init00, bns11_move };
    bns11_jmp[bgw_ptr->r_no_0]();
}

void bns11_init00() {
    bgw_ptr->r_no_0++;

    if (Player_id == 0) {
        bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = 0x223;
    } else {
        bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = 0x1EB;
    }

    bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
    bg_app = 0;
    effect_05_init();
    effect_12_init(4);

    if (!plw->wu.operator) {
        effect_35_init(2, 1);
    } else {
        effect_35_init(2, 0);
    }

    effect_35_init(0xC, 2);
    effect_35_init(0x12, 3);
    effect_35_init(2, 4);
}

void bns11_move() {
    bg_base_x_move_check();
    bg_base_y_move_check();
}

void bns12() {
    void (*bns12_jmp[2])() = { bns12_init00, bns12_move };
    bns12_jmp[bgw_ptr->r_no_0]();
}

void bns12_init00() {
    bgw_ptr->r_no_0++;

    if (Player_id == 0) {
        bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = 0x211;
    } else {
        bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = 0x1F5;
    }

    bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
}

void bns12_move() {
    bg_x_move_check();
    bg_y_move_check();
}

void bns13() {
    void (*bns13_jmp[2])() = { bns13_init00, bns13_move };
    bns13_jmp[bgw_ptr->r_no_0]();
}

void bns13_init00() {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
}

void bns13_move() {
    // Do nothing
}
