/* bg190.c, retail sf33rd.xbe.
 * PlayStation 2 C, not hand-adjusted for Xbox. Each named body was located
 * from the PS2 retail map: call graph, source order, and agreement of
 * constants, field offsets, callees, and size. See docs/decompiling.md.
 * The #include lines name headers in the PS2 tree (ps2.path).
 * bg1901_init00 0xB2711 size 0x4A.
 * bg1902_init00 0xB275B size 0x69.
 * The other functions in this file are not located in sf33rd.xbe yet.
 */

#include "sf33rd/Source/Game/bg190.h"
#include "common.h"
#include "sf33rd/Source/Game/EFF44.h"
#include "sf33rd/Source/Game/PLCNT.h"
#include "sf33rd/Source/Game/WORK_SYS.h"
#include "sf33rd/Source/Game/bg.h"
#include "sf33rd/Source/Game/bg_data.h"
#include "sf33rd/Source/Game/bg_sub.h"
#include "sf33rd/Source/Game/eff05.h"
#include "sf33rd/Source/Game/eff06.h"
#include "sf33rd/Source/Game/eff12.h"
#include "sf33rd/Source/Game/effL4.h"
#include "sf33rd/Source/Game/ta_sub.h"

void BG190() {
    bgw_ptr = &bg_w.bgw[1];
    bg1902();
    bgw_ptr = &bg_w.bgw[0];
    bg1901();
    bgw_ptr = &bg_w.bgw[2];
    sync_bg14_common();
    zoom_ud_check();
    bg_pos_hosei2();
    Bg_Family_Set();
}

void bg1901() {
    void (*bg1901_jmp[2])() = { bg1901_init00, bg_move_common };
    bg1901_jmp[bgw_ptr->r_no_0]();
}

void bg1901_init00() {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x1D0;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
}

void bg1902() {
    void (*bg1902_jmp[2])() = { bg1902_init00, bg_base_move_common };
    bg1902_jmp[bgw_ptr->r_no_0]();
}

void bg1902_init00() {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x1D0;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
    effect_05_init();
    effect_06_init();
    effect_L4_init();
    effect_44_init(6);
    effect_12_init(3);
}

void sync_bg14_common() {
    switch (bgw_ptr->r_no_0) {
    case 0:
        bgw_ptr->r_no_0++;
        bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x1D0;
        bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
        bgw_ptr->xy[1].disp.pos = bgw_ptr->pos_y_work = 0;
        bgw_ptr->fam_no = 2;
        bgw_ptr->xy[0].disp.low = bgw_ptr->xy[1].disp.low = 0;
        bgw_ptr->y_limit = bgw_ptr->y_limit2 = 0xF0;
        bgw_ptr->speed_x = 0xD000;
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
