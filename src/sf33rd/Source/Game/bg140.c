/* bg140.c, retail sf33rd.xbe.
 * PlayStation 2 C, not hand-adjusted for Xbox. Each named body was located
 * from the PS2 retail map: call graph, source order, and agreement of
 * constants, field offsets, callees, and size. See docs/decompiling.md.
 * The #include lines name headers in the PS2 tree (ps2.path).
 * bg1401_init00 0xB20B5 size 0x5E.
 * bg1401_init00 0xB20B5 size 0x5E.
 * The other functions in this file are not located in sf33rd.xbe yet.
 */

#include "sf33rd/Source/Game/bg140.h"
#include "common.h"
#include "sf33rd/Source/Game/PLCNT.h"
#include "sf33rd/Source/Game/WORK_SYS.h"
#include "sf33rd/Source/Game/bg.h"
#include "sf33rd/Source/Game/bg_data.h"
#include "sf33rd/Source/Game/bg_sub.h"
#include "sf33rd/Source/Game/eff06.h"
#include "sf33rd/Source/Game/eff12.h"
#include "sf33rd/Source/Game/ta_sub.h"

void BG140() {
    bgw_ptr = &bg_w.bgw[1];
    bg1401();
    bgw_ptr = &bg_w.bgw[0];
    bg1400();
    bgw_ptr = &bg_w.bgw[2];
    bg1402();
    zoom_ud_check();
    bg_pos_hosei2();
    Bg_Family_Set();
}

void bg1401() {
    void (*bg1401_jmp[2])() = { bg1401_init00, bg_base_move_common };
    bg1401_jmp[bgw_ptr->r_no_0]();
}

void bg1401_init00() {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
    bg_app = 0;
    effect_06_init();
    effect_12_init(0);
}

void bg1400() {
    void (*bg140_jmp[2])() = { bg1400_init00, bg_move_common };
    bg140_jmp[bgw_ptr->r_no_0]();
}

void bg1400_init00() {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
}

void bg1402() {
    switch (bgw_ptr->r_no_0) {
    case 0:
        bgw_ptr->r_no_0++;
        bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
        bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
        bgw_ptr->xy[1].disp.pos = bgw_ptr->pos_y_work = 0;
        bgw_ptr->fam_no = 2;
        bgw_ptr->xy[0].disp.low = bgw_ptr->xy[1].disp.low = 0;
        bgw_ptr->y_limit = bgw_ptr->y_limit2 = 0xF0;
        bgw_ptr->speed_x = 0xA000;
        bgw_ptr->speed_y = 0xE000;
        break;

    case 1:
        bg_move_common();
        break;
    }
}
