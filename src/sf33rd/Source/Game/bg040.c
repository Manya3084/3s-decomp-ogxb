/* bg040.c, retail sf33rd.xbe.
 * PlayStation 2 C, not hand-adjusted for Xbox. Each named body was located
 * from the PS2 retail map: call graph, source order, and agreement of
 * constants, field offsets, callees, and size. See docs/decompiling.md.
 * The #include lines name headers in the PS2 tree (ps2.path).
 * bg0401_init00 0xB0F60 size 0x63.
 * bg0401_init00 0xB0F60 size 0x63.
 * bg0401_init01 0xB0FC3 size 0xA.
 * The other functions in this file are not located in sf33rd.xbe yet.
 */

#include "sf33rd/Source/Game/bg040.h"
#include "common.h"
#include "sf33rd/Source/Game/EFF44.h"
#include "sf33rd/Source/Game/EFF53.h"
#include "sf33rd/Source/Game/PLCNT.h"
#include "sf33rd/Source/Game/WORK_SYS.h"
#include "sf33rd/Source/Game/bg.h"
#include "sf33rd/Source/Game/bg_data.h"
#include "sf33rd/Source/Game/bg_sub.h"
#include "sf33rd/Source/Game/eff06.h"
#include "sf33rd/Source/Game/eff12.h"
#include "sf33rd/Source/Game/ta_sub.h"

void BG040() {
    bgw_ptr = &bg_w.bgw[1];
    bg0402();
    bgw_ptr = &bg_w.bgw[0];
    bg0401();
    zoom_ud_check();
    bg_pos_hosei2();
    Bg_Family_Set_2();
}

void bg0401() {
    void (*bg0401_jmp[3])() = { bg0401_init00, bg0401_init01, bg_move_common };
    bg0401_jmp[bgw_ptr->r_no_0]();
}

void bg0401_init00() {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
    effect_12_init(1);
    effect_06_init();
    effect_44_init(3);
    effect_53_init();
}

void bg0401_init01() {
    bgw_ptr->r_no_0++;
}

void bg0402() {
    void (*bg0402_jmp[3])() = { bg0402_init00, bg0402_init01, bg_base_move_common };
    bg0402_jmp[bgw_ptr->r_no_0]();
}

void bg0402_init00() {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
}

void bg0402_init01() {
    bgw_ptr->r_no_0++;
}
