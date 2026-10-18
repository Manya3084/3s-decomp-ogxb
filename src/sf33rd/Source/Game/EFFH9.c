/* EFFH9.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * nokori_ball_effH9 0x4CC0B size 0x29.
 * effect_H9_init 0x4CC34 size 0x93.
 * effect_H9_move 0x4CCC7 size 0x109.
 * effH9_trans is folded into 0x37DBB with 3 other bodies. Unnamed.
 * effH9_trans is folded into 0x37DBB.
 * Data: bbbs_ball is 0x257888, 0x60 bytes compared.
 * Globals: bbbs_ball 0x257888, Game_pause 0x7A89B0, Bonus_Game_Work 0x7A8A00,
 * EXE_flag 0xC7C834, frw 0xC806A0.
 */

#include "structs.h"

#define EFFECT_MAX 128

void sub_00037DBB(WORK* ewk);
void nokori_ball_effH9(WORK_Other_CONN* ewk, s16 num);
extern u8 Game_pause;
extern s16 EXE_flag;
extern s16 Bonus_Game_Work;
void push_effect_work(WORK* wkhd);
extern BG bg_w;
s32 sort_push_request3(WORK* wk);
s16 pull_effect_work(s16 index);
extern uintptr_t frw[EFFECT_MAX][448];

const CONN bbbs_ball[4][3] = {
    { { 153, 0, 0, 32464 }, { 142, 0, 0, 32464 }, { 172, 8, 0, 32488 } },
    { { -141, 0, 0, 32464 }, { -152, 0, 0, 32464 }, { -174, 8, 0, 32488 } },
    { { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 } },
    { { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 } },
};

void effect_H9_move(WORK_Other_CONN* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        switch (ewk->wu.routine_no[1]) {
        case 0:
            ewk->wu.routine_no[1]++;
            ewk->wu.disp_flag = 1;
            ewk->wu.old_cgnum = 0;
            ewk->wu.position_z = ewk->wu.my_priority = 9;
            ewk->wu.direction = 0;
            ewk->wu.dir_timer = 0;
            nokori_ball_effH9(ewk, ewk->wu.direction);
            break;

        case 1:
            if (Game_pause || EXE_flag) {
                break;
            }

            if (--ewk->wu.dir_timer > 0) {
                break;
            }

            ewk->wu.dir_timer = 3;
            ewk->wu.direction++;
            nokori_ball_effH9(ewk, ewk->wu.direction);

            if (ewk->wu.direction >= Bonus_Game_Work) {
                ewk->wu.routine_no[0] = 1;
                ewk->wu.routine_no[1] = 0;
            }

            break;
        }

        sub_00037DBB(&ewk->wu);
        break;

    case 1:
        if (ewk->wu.dead_f == 1) {
            ewk->wu.disp_flag = 0;
            ewk->wu.type = 0;
            ewk->wu.routine_no[0] = 2;
            break;
        }

        nokori_ball_effH9(ewk, Bonus_Game_Work);
        sub_00037DBB(&ewk->wu);
        break;

    case 2:
        ewk->wu.routine_no[0] = 3;
        break;

    default:
        push_effect_work(&ewk->wu);
        break;
    }
}

void effH9_trans(WORK* ewk) {
    ewk->position_x = bg_w.bgw[2].wxy[0].disp.pos;
    ewk->position_y = bg_w.bgw[2].wxy[1].disp.pos;
    sort_push_request3(ewk);
}

void nokori_ball_effH9(WORK_Other_CONN* ewk, s16 num) {
    ewk->conn[0].chr = (num % 10) + 32464;
    ewk->conn[1].chr = (num / 10) + 32464;
}

s32 effect_H9_init(PLW* wk) {
    WORK_Other_CONN* ewk;
    s16 ix;
    s16 i;

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }

    ewk = (WORK_Other_CONN*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 179;
    ewk->wu.work_id = 16;
    ewk->wu.my_mts = 14;
    ewk->wu.my_family = 3;
    ewk->wu.cgromtype = 1;
    ewk->wu.type = wk->wu.rl_flag;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_col_code = 73;
    ewk->num_of_conn = 3;

    if (wk->wu.rl_flag) {
        ix = 1;
    } else {
        ix = 0;
    }

    for (i = 0; i < 3; i++) {
        ewk->conn[i] = bbbs_ball[ix][i];
    }

    return 0;
}
