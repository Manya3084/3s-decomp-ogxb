/* EFFJ2.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * effJ2_trans 0x4E235 size 0x22.
 * effect_J2_init 0x4E257 size 0x9F.
 * effect_J2_move 0x4E2F6 size 0xC0.
 * Data: bbbs_nando_large is 0x257D90, 0x10 bytes compared.
 * Globals: bbbs_nando_large 0x257D90, Bonus_Stage_Level 0x7A8270, Break_Into
 * 0x7A8802, bg_w 0x7BC520, frw 0xC806A0.
 */

#include "structs.h"

#define EFFECT_MAX 128

extern s16 Bonus_Stage_Level;
extern s8 Break_Into;
void effJ2_trans(WORK* ewk);
void push_effect_work(WORK* wkhd);
extern BG bg_w;
s32 sort_push_request3(WORK* wk);
s16 pull_effect_work(s16 index);
extern uintptr_t frw[EFFECT_MAX][448];

const CONN bbbs_nando_large[2] = { { 92, 78, 0, 0x7EC7 }, { -20, 78, 0, 0x7EC6 } };

void effect_J2_move(WORK_Other_CONN* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        switch (ewk->wu.routine_no[1]) {
        case 0:
            ewk->wu.routine_no[1]++;
            ewk->wu.disp_flag = 0;
            ewk->wu.old_cgnum = 0;
            break;
        }

        if (--ewk->wu.dir_timer > 0) {
            break;
        }

        ewk->wu.routine_no[0] = 1;
        ewk->wu.routine_no[1] = 0;
        ewk->wu.disp_flag = 1;
        ewk->wu.old_cgnum = 0;
        ewk->wu.dir_timer = 60;
        ewk->wu.position_z = ewk->wu.my_priority = 27;
        ewk->conn[0].chr += Bonus_Stage_Level % 10;
        break;

    case 1:
        if (ewk->wu.dead_f == 1 || Break_Into || --ewk->wu.dir_timer <= 0) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0] = 2;
        } else {
            effJ2_trans(&ewk->wu);
        }

        break;

    case 2:
        ewk->wu.routine_no[0] = 3;
        break;

    default:
        push_effect_work(&ewk->wu);
        break;
    }
}

void effJ2_trans(WORK* ewk) {
    ewk->position_x = bg_w.bgw[1].wxy[0].disp.pos;
    ewk->position_y = bg_w.bgw[1].wxy[1].disp.pos;
    sort_push_request3(ewk);
}

s32 effect_J2_init(s16 delay) {
    WORK_Other_CONN* ewk;
    s16 ix;

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }

    ewk = (WORK_Other_CONN*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 192;
    ewk->wu.work_id = 16;
    ewk->wu.my_mts = 14;
    ewk->wu.my_family = 2;
    ewk->wu.cgromtype = 1;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_col_code = 0x49;
    ewk->wu.dir_timer = delay;
    ewk->num_of_conn = 2;
    ewk->conn[0] = bbbs_nando_large[0];
    ewk->conn[1] = bbbs_nando_large[1];
    return 0;
}
