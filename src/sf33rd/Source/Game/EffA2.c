/* EffA2.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * effect_A2_move 0x56417 size 0x14C.
 * effect_A2_init 0x56563 size 0x47.
 * Data: hnc_pointer: defined elsewhere on Xbox.
 * Data: hnc_timer: defined elsewhere on Xbox.
 * Data: hnc_end_timer 0xC80635.
 * Data: hnc_col: defined elsewhere on Xbox.
 * Data: hnc_color_tbl is 0x25C360, 0x58 bytes compared.
 * Globals: hnc_color_tbl 0x25C360, Game_pause 0x7A89B0, hnc_end_timer
 * 0xC80635, frw 0xC806A0.
 */

#include "structs.h"

#define EFFECT_MAX 128

extern u8 Game_pause;
extern s8 Disp_PERFECT;
void hnc_set(u8 num, u8 atr);
void hnc_wipeinit(u8 atr);
s32 hnc_wipeout(u8 atr);
void push_effect_work(WORK* wkhd);
s16 pull_effect_work(s16 index);
extern uintptr_t frw[EFFECT_MAX][448];
void Switch_Priority_76();

extern const u8* hnc_pointer;

extern u8 hnc_timer;

extern u8 hnc_end_timer;

extern u8 hnc_col;

const u8 hnc_color_tbl[88] = { 21, 2, 22, 1, 21, 2, 20, 18, 21, 2, 22, 1, 21, 2, 20, 32, 21, 2, 22, 1, 21, 2,
                               20, 4, 21, 2, 22, 1, 21, 2,  20, 4, 21, 2, 22, 1, 21, 2,  20, 4, 21, 2, 22, 1,
                               21, 2, 20, 4, 21, 2, 22, 1,  21, 2, 20, 4, 21, 2, 22, 1,  21, 2, 20, 4, 21, 2,
                               22, 1, 21, 2, 20, 4, 21, 2,  22, 1, 21, 2, 20, 4, 21, 2,  22, 1, 21, 2, 20, 255 };

void effect_A2_move(WORK_Other* ewk) {
    if (!(Game_pause & 0x80)) {
        hnc_end_timer++;
    }

    switch (ewk->wu.routine_no[0]) {
    case 0:
        Disp_PERFECT = 0;
        ewk->wu.routine_no[0]++;

    case 1:
        if ((Game_pause & 0x80) != 0) {
            hnc_set(ewk->wu.direction, 20);
            return;
        }

        hnc_set(ewk->wu.direction, 20);

        if (ewk->wu.direction < 23) {
            ewk->wu.direction++;
        }

        if (ewk->wu.direction == 18) {
            ewk->wu.routine_no[0]++;
            hnc_pointer = hnc_color_tbl;
            hnc_col = *hnc_pointer++;
            hnc_timer = *hnc_pointer++;
        }

        return;

    case 2:
        if (Game_pause & 0x80) {
            hnc_set(ewk->wu.direction, hnc_col);
            return;
        }

        hnc_set(ewk->wu.direction, hnc_col);

        if (ewk->wu.direction < 23) {
            ewk->wu.direction++;
        }

        if (ewk->wu.direction == 23) {
            ewk->wu.routine_no[0]++;
        }

        break;

    case 3:
        if (Game_pause & 0x80) {
            hnc_set(ewk->wu.direction, hnc_col);
            return;
        }

        if (hnc_end_timer > 142) {
            ewk->wu.routine_no[0]++;
        }

        hnc_set(ewk->wu.direction, hnc_col);
        break;

    case 4:
        if (Game_pause & 0x80) {
            hnc_wipeinit(hnc_col);
            return;
        }

        hnc_wipeinit(hnc_col);
        ewk->wu.routine_no[0]++;
        /* fallthrough */

    case 5:
    default:
        if (hnc_wipeout(hnc_col)) {
            push_effect_work(&ewk->wu);
        }
    }

    if (!(Game_pause & 0x80)) {
        if (hnc_timer > 1) {
            hnc_timer--;
        } else {
            hnc_col = *hnc_pointer++;
            hnc_timer = *hnc_pointer++;
        }
    }
}

s32 effect_A2_init() {
    WORK_Other* ewk;
    s16 ix;

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }

    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 102;
    ewk->wu.work_id = 16;
    ewk->wu.direction = 1;
    hnc_end_timer = 0;
    Switch_Priority_76();
    return 0;
}
