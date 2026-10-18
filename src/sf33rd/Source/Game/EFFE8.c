/* EFFE8.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * effe8_zanzou_process 0x4A2BC size 0x168. Read against the x86: zanzou_table
 * is 0xC7D9E0. The [type - 1] reads land at 0xC7D9D0, which is cmd_sel's
 * address. The C is the PS2 C.
 * effE8_trans 0x4A424 size 0x3A.
 * effect_E8_init 0x4A45E size 0x79.
 * effect_E8_move 0x4A52A size 0xCE. Read against the x86: every
 * effe8_zanzou_process and effE8_trans pair is tail-merged into one call site,
 * and case 0's type >= charset_id test is always true after the assignment.
 * The C is the PS2 C.
 * Globals: after_image_color 0x255E28, Game_pause 0x7A89B0, cmd_sel 0xC7D9D0,
 * vib_sel 0xC7D9D2, pcon_rno 0xC7E020, frw 0xC806A0.
 */

#include "structs.h"

#define EFFECT_MAX 128

void effe8_zanzou_process(WORK_Other* ewk, PLW* mwk);
void effE8_trans(WORK_Other* ewk, PLW* mwk);
extern u8 Game_pause;
extern s16 pcon_rno[4];
void push_effect_work(WORK* wkhd);
extern ZanzouTableEntry zanzou_table[2][48];
extern const u16 after_image_color[][2];
void get_attdata_of_illusion(WORK_Other* ewk);
s32 sort_push_request(WORK* wk);
s16 pull_effect_work(s16 index);
extern uintptr_t frw[EFFECT_MAX][448];
void effect_e7_e8_init_union(WORK_Other* nwk, WORK_Other* ek, PLW* mk);



void effect_E8_move(WORK_Other* ewk) {
    PLW* mwk = (PLW*)ewk->my_master;
    WORK_Other* cwk = (WORK_Other*)ewk->wu.target_adrs;
    WORK* mtwk;

    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.type = ewk->wu.charset_id;
        ewk->wu.cg_att_ix = 0;
        ewk->wu.cg_hit_ix = 0;

        if (ewk->wu.type >= ewk->wu.charset_id) {
            ewk->wu.type = ewk->wu.charset_id;
            ewk->wu.routine_no[0] = 1;
        }

        effe8_zanzou_process(ewk, mwk);
        effE8_trans(ewk, mwk);
        break;

    case 1:
        if (ewk->wu.dead_f == 1) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0] = 2;
            break;
        }

        if (Game_pause == 0x81) {
            effE8_trans(ewk, mwk);
            break;
        }

        switch (ewk->wu.routine_no[1]) {
        case 0:
            if (cwk->wu.routine_no[0] != 1 || cwk->wu.routine_no[1] != 1) {
                ewk->wu.routine_no[1] = 1;
            }

            effe8_zanzou_process(ewk, mwk);
            effE8_trans(ewk, mwk);
            break;

        default:
            ewk->wu.type -= ewk->wu.rl_waza;

            if (ewk->wu.type <= 0) {
                ewk->wu.disp_flag = 0;
                ewk->wu.routine_no[0] = 2;
            } else {
                effe8_zanzou_process(ewk, mwk);
                effE8_trans(ewk, mwk);
            }

            break;
        }

        break;

    case 2:
        if (*pcon_rno != 2) {
            mtwk = (WORK*)mwk->wu.target_adrs;

            if (mtwk->routine_no[0] == 4 && mtwk->routine_no[1] == 1 && mtwk->routine_no[3] < 2) {
                break;
            }
        }

        ewk->wu.routine_no[0] = 3;
        break;

    default:
        push_effect_work(&ewk->wu);
        break;
    }
}

void effe8_zanzou_process(WORK_Other* ewk, PLW* mwk) {
    if (ewk->wu.old_rno[5]) {
        if (ewk->wu.type == 0) {
            ewk->wu.position_x = mwk->wu.position_x;
            ewk->wu.position_y = mwk->wu.position_y;
        } else {
            ewk->wu.position_x = zanzou_table[ewk->master_id][ewk->wu.type - 1].pos_x;
            ewk->wu.position_y = zanzou_table[ewk->master_id][ewk->wu.type - 1].pos_y;
        }
    } else {
        ewk->wu.position_x = zanzou_table[ewk->master_id][ewk->wu.type].pos_x;
        ewk->wu.position_y = zanzou_table[ewk->master_id][ewk->wu.type].pos_y;
    }

    ewk->wu.position_z = mwk->wu.position_z;

    if (ewk->wu.old_rno[3] == 0) {
        ewk->wu.old_cgnum = ewk->wu.cg_number = mwk->wu.cg_number;
        ewk->wu.rl_flag = mwk->wu.rl_flag;
        ewk->wu.cg_flip = mwk->wu.cg_flip;
    } else {
        ewk->wu.cg_number = zanzou_table[ewk->master_id][ewk->wu.type].cg_num;
        ewk->wu.rl_flag = zanzou_table[ewk->master_id][ewk->wu.type].flip;
        ewk->wu.cg_flip = zanzou_table[ewk->master_id][ewk->wu.type].cg_flp;
    }

    if (ewk->wu.old_rno[0]) {
        ewk->wu.position_z -= ewk->wu.rl_waza;
    } else {
        ewk->wu.position_z += ewk->wu.rl_waza;
    }

    if (ewk->wu.old_rno[4]) {
        if (ewk->wu.olc_work_ix[2] && mwk->metamorphose) {
            ewk->wu.extra_col = after_image_color[ewk->wu.old_rno[4] + ewk->wu.rl_waza - 1][(ewk->master_id + 1) & 1];
        } else {
            ewk->wu.extra_col = after_image_color[ewk->wu.old_rno[4] + ewk->wu.rl_waza - 1][ewk->master_id];
        }
    } else {
        ewk->wu.extra_col = mwk->wu.current_colcd;
    }

    if (ewk->wu.old_rno[1]) {
        get_attdata_of_illusion(ewk);
    }
}

void effE8_trans(WORK_Other* ewk, PLW* mwk) {
    if (ewk->wu.old_rno[3] == 0) {
        return;
    }

    ewk->wu.old_rno[6] = ewk->wu.rl_waza - 1;
    ewk->wu.my_bright_level = (ewk->wu.old_rno[6] * 3) + 1;

    if (mwk->wu.disp_flag != 0 && mwk->sa_stop_flag == 0) {
        sort_push_request(&ewk->wu);
    }
}

s32 effect_E8_init(WORK_Other* ek, PLW* mk, s16 data) {
    WORK_Other* ewk;
    s16 ix;

    if ((ix = pull_effect_work(3)) == -1) {
        return -1;
    }

    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.disp_flag = ek->wu.disp_flag;
    ewk->wu.id = 148;
    ewk->wu.type = 0;
    ewk->wu.charset_id = data;
    ewk->wu.rl_waza = data / ek->wu.dmcal_m;

    if (ek->wu.old_rno[1]) {
        ewk->wu.work_id = 8;
    } else {
        ewk->wu.work_id = 16;
    }

    effect_e7_e8_init_union(ewk, ek, mk);
    return 0;
}
