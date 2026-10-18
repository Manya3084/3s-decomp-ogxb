/* PLPAT12.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * pl12_extra_attack 0x8B322 size 0x12.
 * Att_PL12_TOKUSHUKOUDOU 0x8B334 size 0x173.
 * Att_PL12_BONUS_STAGE 0x8B4A7 size 0x93.
 * effect_D7_init stays sub_000486D6, the one unnamed call left in its caller.
 * Data: pl12_exatt_table is 0x262E00, 18 entries compared.
 * Globals: pl11_exatt_table 0x262DB8.
 */

#include "structs.h"

s32 sub_000486D6(PLW* wk);
void Att_HADOUKEN(PLW* wk);
void Att_SHOURYUUREPPA(PLW* wk);
void Att_SLIDE_and_JUMP(PLW* wk);
void Att_ABISEGERI(PLW* wk);
void Att_CHOUCHUURENGEKI(PLW* wk);
void Att_SHOURYUUKEN(PLW* wk);
void Att_KUUCHUUNICHIRINSHOU(PLW* wk);
void Att_SENPUUKYAKU(PLW* wk);
void Att_HOMING_JUMP(PLW* wk);
void Att_DUMMY(PLW* );
void Att_PL12_TOKUSHUKOUDOU(PLW* wk);
void Att_PL12_BONUS_STAGE(PLW* wk);
void Att_METAMOR_WAIT(PLW* wk);
void Att_METAMOR_REBIRTH(PLW* wk);
void hoken_muriyari_chakuchi(PLW* wk);
void set_char_move_init(WORK* wk, s16 koc, s16 index);
void char_move(WORK* wk);
void setup_mvxy_data(WORK* wk, u16 ix);
void char_move_cmj4(WORK* wk);
void add_sp_arts_gauge_tokushu(PLW* wk);
void jumping_union_process(WORK* wk, s16 num);
void grade_add_personal_action(s16 ix);

void (*const pl12_exatt_table[18])(PLW*) = { Att_HADOUKEN,
                                             Att_SHOURYUUREPPA,
                                             Att_SLIDE_and_JUMP,
                                             Att_ABISEGERI,
                                             Att_CHOUCHUURENGEKI,
                                             Att_SHOURYUUKEN,
                                             Att_CHOUCHUURENGEKI,
                                             Att_KUUCHUUNICHIRINSHOU,
                                             Att_SENPUUKYAKU,
                                             Att_HOMING_JUMP,
                                             Att_DUMMY,
                                             Att_DUMMY,
                                             Att_DUMMY,
                                             Att_DUMMY,
                                             Att_PL12_TOKUSHUKOUDOU,
                                             Att_PL12_BONUS_STAGE,
                                             Att_METAMOR_WAIT,
                                             Att_METAMOR_REBIRTH };

void pl12_extra_attack(PLW* wk) {
    pl12_exatt_table[wk->wu.routine_no[2] - 16](wk);
}

void Att_PL12_TOKUSHUKOUDOU(PLW* wk) {
    wk->scr_pos_set_flag = 0;

    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = wk->wu.rl_waza;
        hoken_muriyari_chakuchi(wk);
        wk->wu.mvxy.index = wk->as->data_ix;
        wk->wu.cmwk[6] = 0;
        wk->wu.cmwk[7] = 0;
        wk->tk_success++;

        if (wk->metamorphose) {
            set_char_move_init(&wk->wu, 5, wk->as->char_ix + 1);
            break;
        }

        if (sub_000486D6(wk)) {
            set_char_move_init(&wk->wu, 5, wk->as->char_ix + 1);
            break;
        }

        set_char_move_init(&wk->wu, 5, wk->as->char_ix);
        break;

    case 1:
        char_move(&wk->wu);

        if (wk->wu.cg_type == 20) {
            setup_mvxy_data(&wk->wu, wk->wu.mvxy.index);
            wk->wu.mvxy.index++;
            wk->wu.routine_no[3]++;
            wk->wu.cg_type = 0;
        }

        break;

    case 2:
        if (wk->wu.cmwk[7] != 0) {
            char_move_cmj4(&wk->wu);
            wk->wu.cmwk[7] = 0;
            wk->wu.mvxy.index++;
            add_sp_arts_gauge_tokushu(wk);
        }

        jumping_union_process(&wk->wu, 3);

        if (wk->wu.cg_type == 20) {
            setup_mvxy_data(&wk->wu, wk->wu.mvxy.index);
            wk->wu.cg_type = 0;
        }

        if (wk->wu.cg_type == 30) {
            wk->wu.cg_type = 0;
            wk->tk_kizetsu += 4;

            if (wk->tk_kizetsu > 12) {
                wk->tk_kizetsu = 12;
            }
        }

        break;

    case 3:
        char_move(&wk->wu);

        if (wk->wu.cg_type == 64) {
            grade_add_personal_action(wk->wu.id);
        }

        break;
    }
}

void Att_PL12_BONUS_STAGE(PLW* wk) {
    wk->scr_pos_set_flag = 0;

    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = wk->wu.rl_waza;
        wk->wu.cmwk[6] = 0;
        wk->wu.cmwk[7] = 0;
        set_char_move_init(&wk->wu, 5, wk->wu.char_index);
        break;

    case 1:
        char_move(&wk->wu);

        if (wk->wu.cg_type == 20) {
            wk->wu.routine_no[3]++;
        }

        break;

    case 2:
        if (wk->wu.cmwk[7] != 0) {
            char_move_cmj4(&wk->wu);
            wk->wu.cmwk[7] = 0;
        }

        jumping_union_process(&wk->wu, 3);
        break;

    case 3:
        char_move(&wk->wu);
        break;
    }
}
