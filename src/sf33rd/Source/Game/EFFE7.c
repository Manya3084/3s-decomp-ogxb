/* EFFE7.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * effe7_get_zanzou_data 0x4A076 size 0x56. Read against the x86: the unnamed
 * addresses are zanzou_table fields (0xC7D9E0). The C is the PS2 C.
 * effect_E7_init 0x4A0CC size 0x58.
 * effect_E7_move 0x4A124 size 0x198. Read against the x86: -1 is the rounding
 * term of the pricol division. The C is the PS2 C.
 * Globals: after_image_color 0x255E28, Game_pause 0x7A89B0, EXE_flag 0xC7C834,
 * zanzou_table 0xC7D9E0, frw 0xC806A0.
 */

#include "structs.h"

#define EFFECT_MAX 128

void effe7_get_zanzou_data(WORK_Other* ewk);
extern u8 Game_pause;
extern s16 EXE_flag;
extern const u16 after_image_color[][2];
void get_attdata_of_illusion(WORK_Other* ewk);
s32 sort_push_request(WORK* wk);
void push_effect_work(WORK* wkhd);
extern ZanzouTableEntry zanzou_table[2][48];
s16 pull_effect_work(s16 index);
extern uintptr_t frw[EFFECT_MAX][448];
void effect_e7_e8_init_union(WORK_Other* nwk, WORK_Other* ek, PLW* mk);



void effect_E7_move(WORK_Other* ewk) {
    PLW* mwk = (PLW*)ewk->my_master;
    s16 pricol;

    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.cg_att_ix = 0;
        ewk->wu.cg_hit_ix = 0;
        effe7_get_zanzou_data(ewk);
        /* fallthrough */

    case 1:
        if (ewk->wu.dead_f == 1) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0]++;
            break;
        }

        if (Game_pause != 0x81) {
            if (ewk->wu.old_rno[5]) {
                ewk->wu.position_x = mwk->wu.position_x;
                ewk->wu.position_y = mwk->wu.position_y;
            }

            ewk->wu.position_z = mwk->wu.position_z;

            if (ewk->wu.old_rno[3] == 0) {
                ewk->wu.cg_number = mwk->wu.cg_number;
                ewk->wu.rl_flag = mwk->wu.rl_flag;
                ewk->wu.cg_flip = mwk->wu.cg_flip;
            }

            if (EXE_flag == 0 && Game_pause == 0 && --ewk->wu.dir_timer <= 0) {
                ewk->wu.disp_flag = 0;
                ewk->wu.routine_no[0]++;
                break;
            }

            pricol = ewk->wu.dmcal_d - (ewk->wu.dir_timer + ewk->wu.dmcal_m - 1) / ewk->wu.dmcal_m;
            ewk->wu.old_rno[6] = pricol;

            if (ewk->wu.old_rno[0]) {
                ewk->wu.position_z -= pricol;
            } else {
                ewk->wu.position_z += pricol;
            }

            if (ewk->wu.old_rno[4]) {
                if (ewk->wu.olc_work_ix[2] && mwk->metamorphose) {
                    ewk->wu.extra_col = after_image_color[ewk->wu.old_rno[4] + pricol][(ewk->master_id + 1) & 1];
                } else {
                    ewk->wu.extra_col = after_image_color[ewk->wu.old_rno[4] + pricol][ewk->master_id];
                }
            } else {
                ewk->wu.extra_col = mwk->wu.current_colcd;
            }

            if (ewk->wu.old_rno[1]) {
                get_attdata_of_illusion(ewk);
            }

            ewk->wu.my_bright_level = (ewk->wu.old_rno[6] * 3) + 1;
        }

        if (mwk->wu.disp_flag != 0 && mwk->sa_stop_flag == 0) {
            sort_push_request(&ewk->wu);
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

void effe7_get_zanzou_data(WORK_Other* ewk) {
    ewk->wu.position_x = zanzou_table[ewk->master_id]->pos_x;
    ewk->wu.position_y = zanzou_table[ewk->master_id]->pos_y;
    ewk->wu.position_z = zanzou_table[ewk->master_id]->pos_z;
    ewk->wu.cg_number = zanzou_table[ewk->master_id]->cg_num;
    ewk->wu.rl_flag = zanzou_table[ewk->master_id]->flip;
    ewk->wu.cg_flip = zanzou_table[ewk->master_id]->cg_flp;
}

s32 effect_E7_init(WORK_Other* ek, PLW* mk) {
    WORK_Other* ewk;
    s16 ix;

    if ((ix = pull_effect_work(3)) == -1) {
        return -1;
    }

    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.disp_flag = ek->wu.disp_flag;
    ewk->wu.id = 147;

    if (ek->wu.old_rno[1]) {
        ewk->wu.work_id = 8;
    } else {
        ewk->wu.work_id = 16;
    }

    effect_e7_e8_init_union(ewk, ek, mk);
    return 0;
}
