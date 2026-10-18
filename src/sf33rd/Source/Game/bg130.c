/* bg130.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * bg1301_init00 0xB1F4E size 0x4E.
 * bg1302 0xB1F9C size 0xBB.
 * bg1301 0xB2057 size 0x22.
 * BG130 0xB2079 size 0x3C.
 * Not located in sf33rd.xbe; their PS2 C is kept under #if 0: bg1300,
 * bg1300_init00.
 * bg1300 is folded into 0xB10A1.
 * Globals: bgw_ptr 0x7BC510, bg_w 0x7BC520.
 */

#include "structs.h"

void sub_000B10A1();
extern BGW* bgw_ptr;
extern BG bg_w;
void bg1301();
void bg1302();
void zoom_ud_check();
void bg_pos_hosei2();
void Bg_Family_Set();
void bg1301_init00();
void bg_base_move_common();
s32 effect_05_init();
void sync_fam_set3(s16 my_fam);
void bg_x_move_check();
void bg_y_move_check();



void BG130() {
    bgw_ptr = &bg_w.bgw[1];
    bg1301();
    bgw_ptr = &bg_w.bgw[0];
    sub_000B10A1();
    bgw_ptr = &bg_w.bgw[2];
    bg1302();
    zoom_ud_check();
    bg_pos_hosei2();
    Bg_Family_Set();
}

void bg1301() {
    void (*bg1301_jmp[2])() = { bg1301_init00, bg_base_move_common };
    bg1301_jmp[bgw_ptr->r_no_0]();
}

void bg1301_init00() {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
    effect_05_init();
}

void bg1302() {
    switch (bgw_ptr->r_no_0) {
    case 0:
        bgw_ptr->r_no_0++;
        bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
        bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
        bgw_ptr->zuubun = 0;
        bgw_ptr->fam_no = 2;
        bgw_ptr->xy[1].disp.pos = bgw_ptr->pos_y_work = 0;
        bgw_ptr->y_limit = bgw_ptr->y_limit2 = 0xD0;
        bgw_ptr->speed_x = 0xE000;
        bgw_ptr->speed_y = 0xE000;
        sync_fam_set3(2);
        break;

    case 1:
        bg_x_move_check();
        bg_y_move_check();
        sync_fam_set3(2);
        break;
    }
}

#if 0
/* PS2 C for functions not located in sf33rd.xbe yet. */

void bg1300() {
    void (*bg1300_jmp[2])() = { bg1300_init00, bg_move_common };
    bg1300_jmp[bgw_ptr->r_no_0]();
}

void bg1300_init00() {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
}
#endif
