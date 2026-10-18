/* bg010.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * bg0101_init00 0xB0B6F size 0x5F.
 * bg0103 0xB0BCE size 0xC6.
 * bg0101 0xB0C94 size 0x22.
 * bg0102 0xB0CB6 size 0x22.
 * BG010 0xB0CD8 size 0x3C.
 * Not located in sf33rd.xbe; their PS2 C is kept under #if 0: bg0102_init00.
 * Globals: bgw_ptr 0x7BC510, bg_w 0x7BC520.
 */

#include "structs.h"

extern BGW* bgw_ptr;
extern BG bg_w;
void bg0102();
void bg0101();
void bg0103();
void zoom_ud_check();
void bg_pos_hosei2();
void Bg_Family_Set();
void bg0101_init00();
void bg_move_common();
s32 effect_07_init();
s32 effect_05_init();
s32 effect_06_init();
s32 effect_11_init();
void bg0102_init00();
void bg_base_move_common();
void sync_fam_set3(s16 my_fam);
void bg_x_move_check();
void bg_y_move_check();



void BG010() {
    bgw_ptr = &bg_w.bgw[1];
    bg0102();
    bgw_ptr = &bg_w.bgw[0];
    bg0101();
    bgw_ptr = &bg_w.bgw[2];
    bg0103();
    zoom_ud_check();
    bg_pos_hosei2();
    Bg_Family_Set();
}

void bg0101() {
    void (*bg0101_jmp[2])() = { bg0101_init00, bg_move_common };
    bg0101_jmp[bgw_ptr->r_no_0]();
}

void bg0101_init00() {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].disp.pos = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
    effect_07_init();
    effect_05_init();
    effect_06_init();
    effect_11_init();
}

void bg0102() {
    void (*bg0102_jmp[2])() = { bg0102_init00, bg_base_move_common };
    bg0102_jmp[bgw_ptr->r_no_0]();
}

void bg0103() {
    switch (bgw_ptr->r_no_0) {
    case 0:
        bgw_ptr->r_no_0++;
        bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
        bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
        bgw_ptr->xy[1].disp.pos = bgw_ptr->pos_y_work = 0;
        bgw_ptr->fam_no = 2;
        bgw_ptr->xy[0].disp.low = bgw_ptr->xy[1].disp.low = 0;
        bgw_ptr->y_limit = bgw_ptr->y_limit2 = 0xF0;
        bgw_ptr->speed_x = 0xB000;
        bgw_ptr->speed_y = 0xE000;
        sync_fam_set3(2);
        break;

    case 1:
        bg_x_move_check();
        bg_y_move_check();
        sync_fam_set3(2);
    }
}

#if 0
/* PS2 C for functions not located in sf33rd.xbe yet. */

void bg0102_init00() {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
}
#endif
