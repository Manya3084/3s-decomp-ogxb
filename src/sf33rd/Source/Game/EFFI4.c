/* EFFI4.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * effi4_down_to_up 0x4D228 size 0x9E.
 * effi4_up_to_down 0x4D2C6 size 0x23.
 * effect_I4_init 0x4D2E9 size 0xB3.
 * effect_i4_hit_sub 0x4D39C size 0x76.
 * effect_I4_move 0x4D412 size 0x87.
 * all_cgps_put_back is folded into 0x4384A.
 * Globals: _chn_char_table 0x2F33C0, EXE_obroll 0x7A8111, Game_pause 0x7A89B0,
 * eff_hit_flag 0x7A99C0, EXE_flag 0xC7C834, frw 0xC806A0.
 */

#include "structs.h"

#define EFFECT_MAX 128

void sub_0004384A(WORK* wk);
s32 obr_no_disp_check();
void set_char_move_init(WORK* wk, s16 koc, s16 index);
extern s16 eff_hit_flag[11];
extern s16 EXE_flag;
extern u8 Game_pause;
extern s8 EXE_obroll;
void effect_i4_hit_sub(WORK_Other* ewk);
void disp_pos_trans_entry_r(WORK_Other* ewk);
void push_effect_work(WORK* wkhd);
s16 eff_hit_check2(WORK_Other* ewk, s16 type, s16 where_type);
void effi4_up_to_down(WORK_Other* ewk);
void effi4_down_to_up(WORK_Other* ewk);
void char_move(WORK* wk);
s16 pull_effect_work(s16 index);
extern uintptr_t frw[EFFECT_MAX][448];
s16 get_my_trans_mode(s16 curr);
extern u32 _chn_char_table[];
s32 effect_J6_init(WORK_Other* oya);



void effect_I4_move(WORK_Other* ewk) {
    if (obr_no_disp_check()) {
        return;
    }

    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);

        if (eff_hit_flag[1]) {
            ewk->wu.routine_no[0] = 2;
            break;
        }

        break;

    case 1:
        if (!EXE_flag && !Game_pause && !EXE_obroll) {
            effect_i4_hit_sub(ewk);
        }

        /* fallthrough */

    case 2:
        disp_pos_trans_entry_r(ewk);
        break;

    default:
        sub_0004384A(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}

/* The Xbox returns where the PS2 breaks out of the switch. */
void effect_i4_hit_sub(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (eff_hit_check2(ewk, 0, 2)) {
            set_char_move_init(&ewk->wu, 0, 25);
            ewk->wu.routine_no[1]++;
            ewk->wu.routine_no[2] = 1;
            ewk->wu.routine_no[3] = 0;
            break;
        }

        if (eff_hit_check2(ewk, 0, 0)) {
            set_char_move_init(&ewk->wu, 0, 24);
            ewk->wu.routine_no[1]++;
            ewk->wu.routine_no[2] = 0;
            ewk->wu.routine_no[3] = 0;
        }

        break;

    case 1:
        if (ewk->wu.routine_no[2]) {
            effi4_up_to_down(ewk);
            return;
        }

        effi4_down_to_up(ewk);
        break;
    }
}

void effi4_down_to_up(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[3]) {
    case 0:
        char_move(&ewk->wu);

        if (!ewk->wu.cg_type) {
            break;
        }

        ewk->wu.type = 2;

        if (eff_hit_check2(ewk, 0, 2)) {
            ewk->wu.routine_no[3]++;
            break;
        }

        if (ewk->wu.cg_type == 0xFF) {
            eff_hit_flag[1] = 0;
            ewk->wu.routine_no[1] = 0;
            ewk->wu.type = 1;
        }

        break;

    case 1:
        char_move(&ewk->wu);

        if (ewk->wu.cg_type) {
            ewk->wu.routine_no[3]++;
            set_char_move_init(&ewk->wu, 0, 26);
            break;
        }

        break;

    case 2:
        char_move(&ewk->wu);

        if (ewk->wu.cg_type == 0xFF) {
            ewk->wu.routine_no[1] = 99;
            ewk->wu.routine_no[0] = 2;
        }

        break;
    }
}

void effi4_up_to_down(WORK_Other* ewk) {
    char_move(&ewk->wu);

    if (ewk->wu.cg_type == 0xFF) {
        ewk->wu.routine_no[1] = 99;
        ewk->wu.routine_no[0] = 2;
    }
}

s32 effect_I4_init() {
    WORK_Other* ewk;
    s16 ix;

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }

    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 184;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.rl_flag = 0;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.type = 1;
    ewk->wu.dead_f = 0;
    ewk->wu.my_family = 2;
    ewk->wu.my_col_code = 8492;
    ewk->wu.my_mts = 7;
    ewk->wu.my_trans_mode = get_my_trans_mode(ewk->wu.my_mts);
    ewk->wu.char_table[0] = _chn_char_table;
    ewk->wu.xyz[0].disp.pos = 832;
    ewk->wu.xyz[1].disp.pos = 192;
    ewk->wu.my_priority = ewk->wu.position_z = 72;
    ewk->wu.char_index = 5;
    ewk->wu.routine_no[1] = 0;
    effect_J6_init(ewk);
    return 0;
}
