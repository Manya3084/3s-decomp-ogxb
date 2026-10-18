/* bg060.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * bg0601_init00 0xB1143 size 0x76.
 * bg0602_init00 0xB11B9 size 0x98.
 * bg0603 0xB1251 size 0xC6.
 * BG060 0xB135B size 0x3C.
 * Not located in sf33rd.xbe; their PS2 C is kept under #if 0: bg0601, bg0602.
 * bg0601 has no XBE name and no aligned call.
 * bg0602 has no XBE name and no aligned call.
 * Globals: bgw_ptr 0x7BC510, bg_w 0x7BC520.
 */

#include "structs.h"

extern BGW* bgw_ptr;
extern BG bg_w;
void bg0602();
void bg0601();
void bg0603();
void zoom_ud_check();
void bg_pos_hosei2();
void Bg_Family_Set();
s32 effect_05_init();
s32 effect_60_init(s16 type);
s32 effect_44_init(s16 type);
s32 effect_24_init();
void sync_fam_set3(s16 my_fam);
void bg_x_move_check();
void bg_y_move_check();



void BG060() {
    bgw_ptr = &bg_w.bgw[1];
    bg0602();
    bgw_ptr = &bg_w.bgw[0];
    bg0601();
    bgw_ptr = &bg_w.bgw[2];
    bg0603();
    zoom_ud_check();
    bg_pos_hosei2();
    Bg_Family_Set();
}

void bg0601_init00() {
    bgw_ptr->r_no_1 = 0;
    bgw_ptr->r_no_0++;
    bgw_ptr->zuubun = 0;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->hos_xy[0].disp.pos = bgw_ptr->wxy[0].disp.pos - bg_w.pos_offset;
    bgw_ptr->hos_xy[0].disp.low = 0;
    bgw_ptr->wxy[1].cal = 0;
    bgw_ptr->xy[1].cal = 0;
}

void bg0602_init00() {
    bgw_ptr->r_no_1 = 0;
    bgw_ptr->r_no_0++;
    bgw_ptr->zuubun = 0;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->hos_xy[0].disp.pos = bgw_ptr->wxy[0].disp.pos - bg_w.pos_offset;
    bgw_ptr->hos_xy[0].disp.low = 0;
    bgw_ptr->wxy[1].cal = 0;
    bgw_ptr->xy[1].cal = 0;
    effect_05_init();
    effect_60_init(0);
    effect_60_init(1);
    effect_44_init(1);
    effect_24_init();
}

void bg0603() {
    switch (bgw_ptr->r_no_0) {
    case 0:
        bgw_ptr->r_no_0++;
        bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
        bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
        bgw_ptr->xy[1].disp.pos = bgw_ptr->pos_y_work = 0;
        bgw_ptr->fam_no = 2;
        bgw_ptr->xy[0].disp.low = bgw_ptr->xy[1].disp.low = 0;
        bgw_ptr->y_limit = bgw_ptr->y_limit2 = 0xF0;
        bgw_ptr->speed_x = 0x10800;
        bgw_ptr->speed_y = 0x10000;
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

void bg0601() {
    void (*bg0601_jmp[2])() = { bg0601_init00, bg_move_common };
    bg0601_jmp[bgw_ptr->r_no_0]();
}

void bg0602() {
    void (*bg0602_jmp[2])() = { bg0602_init00, bg_base_move_common };
    bg0602_jmp[bgw_ptr->r_no_0]();
}
#endif
