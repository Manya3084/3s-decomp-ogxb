/* bg040.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * bg0401_init00 0xB0F60 size 0x63.
 * bg0401_init01 0xB0FC3 size 0xA.
 * bg0401 0xB0FCD size 0x2A.
 * bg0402 0xB0FF7 size 0x2A.
 * BG040 0xB1021 size 0x2D.
 * Not located in sf33rd.xbe; their PS2 C is kept under #if 0: bg0402_init00,
 * bg0402_init01.
 * Globals: bgw_ptr 0x7BC510, bg_w 0x7BC520.
 */

#include "structs.h"

extern BGW* bgw_ptr;
extern BG bg_w;
void bg0402();
void bg0401();
void zoom_ud_check();
void bg_pos_hosei2();
void Bg_Family_Set_2();
void bg0401_init00();
void bg0401_init01();
void bg_move_common();
s32 effect_12_init(s16 type);
s32 effect_06_init();
s32 effect_44_init(s16 type);
s32 effect_53_init();
void bg0402_init00();
void bg0402_init01();
void bg_base_move_common();



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

#if 0
/* PS2 C for functions not located in sf33rd.xbe yet. */

void bg0402_init00() {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
}

void bg0402_init01() {
    bgw_ptr->r_no_0++;
}
#endif
