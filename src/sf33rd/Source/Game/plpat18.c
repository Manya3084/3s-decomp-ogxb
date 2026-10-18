/* plpat18.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * pl18_extra_attack 0xE42DE size 0x12.
 * Att_PL18_NINGENBAKUDAN 0xE42F0 size 0x19B.
 * Att_PL18_TOKUSHUKOUDOU 0xE448B size 0xC0. Read against the x86: 0x78 and
 * 0x64 are recover * 120 / 100 as imul and idiv. The C is the PS2 C.
 * Data: pl18_exatt_table is 0x2AE578, 18 entries compared.
 * Globals: Bonus_Game_Flag 0x7A8272.
 */

#include "structs.h"

void Att_SLIDE_and_JUMP(PLW* wk);
void Att_HADOUKEN2(PLW* wk);
void Att_HADOUKEN(PLW* wk);
void Att_PL18_NINGENBAKUDAN(PLW* wk);
void Att_DUMMY(PLW* );
void Att_PL18_TOKUSHUKOUDOU(PLW* wk);
void Att_METAMOR_WAIT(PLW* wk);
void Att_METAMOR_REBIRTH(PLW* wk);
void hoken_muriyari_chakuchi(PLW* wk);
void set_char_move_init(WORK* wk, s16 koc, s16 index);
void char_move(WORK* wk);
extern s16 Bonus_Game_Flag;
void add_sp_arts_gauge_tokushu(PLW* wk);
void grade_add_personal_action(s16 ix);

void (*const pl18_exatt_table[18])(PLW*) = { Att_SLIDE_and_JUMP,
                                             Att_SLIDE_and_JUMP,
                                             Att_HADOUKEN2,
                                             Att_HADOUKEN2,
                                             Att_SLIDE_and_JUMP,
                                             Att_HADOUKEN2,
                                             Att_HADOUKEN,
                                             Att_PL18_NINGENBAKUDAN,
                                             Att_HADOUKEN,
                                             Att_DUMMY,
                                             Att_DUMMY,
                                             Att_DUMMY,
                                             Att_DUMMY,
                                             Att_DUMMY,
                                             Att_PL18_TOKUSHUKOUDOU,
                                             Att_DUMMY,
                                             Att_METAMOR_WAIT,
                                             Att_METAMOR_REBIRTH };

void pl18_extra_attack(PLW* wk) {
    pl18_exatt_table[wk->wu.routine_no[2] - 16](wk);
}

void Att_PL18_NINGENBAKUDAN(PLW* wk) {
    wk->scr_pos_set_flag = 0;

    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = wk->wu.rl_waza;
        hoken_muriyari_chakuchi(wk);
        set_char_move_init(&wk->wu, 5, wk->as->char_ix);
        break;

    case 1:
        char_move(&wk->wu);

        if (wk->wu.cg_type == 50) {
            wk->wu.routine_no[1] = 1;
            wk->wu.routine_no[2] = 91;
            wk->wu.routine_no[3] = 0;
            wk->wu.dm_vital = 0;
            wk->sa->gauge.i = wk->sa->dtm * wk->sa->dtm_mul;

            if (Bonus_Game_Flag == 20) {
                wk->wu.dm_rl = (wk->wu.rl_flag + 1) & 1;
            } else {
                wk->wu.dm_rl = ((PLW*)wk->wu.target_adrs)->wu.rl_flag;
            }

            wk->wu.dm_attlv = wk->wu.att.level;
            wk->wu.dm_impact = wk->wu.att.impact;
            wk->wu.dm_dir = wk->wu.dir_atthit;
            wk->wu.dm_stop = 1;
            wk->wu.dm_quake = 1;

            if (wk->wu.dm_quake < 0) {
                wk->wu.dm_quake = -wk->wu.dm_quake;
            }

            wk->wu.dm_weight = wk->wu.weight_level;
            wk->wu.dm_butt_type = wk->wu.att.but_ix;
            wk->wu.dm_zuru = wk->wu.att_zuru;
            wk->wu.dm_attribute = wk->wu.at_attribute;
            wk->wu.dm_ten_ix = wk->wu.at_ten_ix;
            wk->wu.dm_koa = wk->wu.at_koa;
            wk->wu.hm_dm_side = wk->wu.att.dmg_mark;
            wk->wu.dm_work_id = wk->wu.work_id;
            wk->wu.dm_arts_point = 0;
            wk->wu.dm_kind_of_waza = wk->wu.kind_of_waza;
            wk->wu.dm_nodeathattack = wk->wu.no_death_attack;
            wk->wu.dm_jump_att_flag = wk->wu.jump_att_flag;
            wk->wu.dm_exdm_ix = wk->exdm_ix;
            wk->wu.dm_plnum = wk->player_number;
            wk->wu.meoshi_hit_flag = 1;
        }

        break;
    }
}

void Att_PL18_TOKUSHUKOUDOU(PLW* wk) {
    wk->scr_pos_set_flag = 0;

    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = wk->wu.rl_waza;
        hoken_muriyari_chakuchi(wk);
        set_char_move_init(&wk->wu, 5, wk->as->char_ix);
        break;

    case 1:
        char_move(&wk->wu);

        if (wk->wu.cg_type == 40) {
            wk->wu.cg_type = 0;
            add_sp_arts_gauge_tokushu(wk);
            wk->tk_konjyou += 4;

            if (wk->tk_konjyou > 12) {
                wk->tk_konjyou = 12;
            }
        }

        if (wk->wu.cg_type == 64) {
            grade_add_personal_action(wk->wu.id);
            wk->wu.routine_no[3]++;

            if (wk->tk_success <= 0) {
                wk->tk_success++;
                wk->py->recover = (wk->py->recover * 120) / 100;
            }
        }

        break;

    default:
        char_move(&wk->wu);
        break;
    }
}
