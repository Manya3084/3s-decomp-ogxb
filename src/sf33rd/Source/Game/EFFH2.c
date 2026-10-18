/* EFFH2.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * xb_effect_H2_draw 0x4C2EA size 0x4D. FLAG: x86-only callees
 * sort_push_request.
 * effect_H2_move 0x4C337 size 0x10C.
 * effect_H2_init 0x4C443 size 0x78. Read against the x86: the unnamed address
 * is the char table store. _ag_face_panel_table is 0x3082F0. The C is the PS2
 * C.
 * Data: panel_guide is 0x2577E8, 0x20 bytes compared.
 * Globals: panel_guide 0x2577E8, _ag_face_panel_table 0x3082F0, frw 0xC806A0.
 */

#include "structs.h"

#define EFFECT_MAX 128

s32 sort_push_request(WORK* wk);
extern const s16 panel_guide[8][2];
extern void (*const D_0024D368[17])();
void set_char_move_init2(WORK* wk, s16 koc, s16 index, s16 ip, s16 scf);
void push_effect_work(WORK* wkhd);
s16 pull_effect_work(s16 index);
extern uintptr_t frw[EFFECT_MAX][448];
extern u32 _ag_face_panel_table[];

const s16 panel_guide[8][2] = { { 0, 6 }, { 0, 5 }, { 0, 4 }, { 0, 2 }, { 0, 0 }, { 0, 2 }, { 0, 4 }, { 0, 5 } };

void effect_H2_move(WORK_Other* ewk) {
    WORK* mwk = (WORK*)ewk->my_master;

    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 0;
        ewk->wu.my_col_mode = 0x4200;
        ewk->wu.my_col_code = 0x22;
        set_char_move_init2(&ewk->wu, 0, 0, ewk->wu.type + 21, 0);
        ewk->wu.disp_flag = 0;
        ewk->wu.direction = 7;
        ewk->wu.dir_old = 7;
        ewk->wu.dir_timer = 0;
        ewk->wu.dir_step = 0;
        break;

    case 1:
        if (ewk->wu.dead_f == 1) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0] = 2;
            break;
        }

        if (mwk->disp_flag == 1) {
            ewk->wu.disp_flag = 1;
        }

        ewk->wu.dir_timer = ewk->wu.dir_timer + 1 & ewk->wu.dir_old;

        if (ewk->wu.dir_timer == 0) {
            ewk->wu.dir_step = ewk->wu.dir_step + 1 & ewk->wu.direction;
        }

        ewk->wu.position_x = mwk->position_x + panel_guide[ewk->wu.dir_step][0];
        ewk->wu.position_y = mwk->position_y + panel_guide[ewk->wu.dir_step][1] + 17;
        sort_push_request(&ewk->wu);
        break;

    case 2:
        ewk->wu.routine_no[0] = 3;
        break;

    default:
        push_effect_work(&ewk->wu);
        break;
    }
}

s32 effect_H2_init(WORK* wk, u8 gal, u8 ohen) {
    WORK_Other* ewk;
    s16 ix;

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }

    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 172;
    ewk->wu.work_id = 16;
    ewk->wu.my_mts = 14;
    ewk->wu.charset_id = gal;
    ewk->wu.type = ohen;
    ewk->wu.rl_flag = 0;
    ewk->my_master = (u32*)wk;
    ewk->wu.cgromtype = 1;
    ewk->wu.my_family = 2;
    ewk->wu.position_z = wk->position_z - 1;
    ewk->wu.char_table[0] = _ag_face_panel_table;
    return 0;
}

void xb_effect_H2_draw(WORK_Other* ewk) {
    WORK* mwk = (WORK*)ewk->my_master;

    switch (ewk->wu.routine_no[0]) {
    case 1:
        if (ewk->wu.dead_f != 1) {
            ewk->wu.position_x = mwk->position_x + panel_guide[ewk->wu.dir_step][0];
            ewk->wu.position_y = mwk->position_y + panel_guide[ewk->wu.dir_step][1] + 17;
            sort_push_request(&ewk->wu);
        }

        break;
    }
}
