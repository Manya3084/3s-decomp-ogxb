/* PLPAT07.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * pl07_extra_attack 0x8A648 size 0x12.
 * Att_PL07_SA2 0x8A65A size 0xA4.
 * Att_PL07_AT1 0x8A6FE size 0x109.
 * Att_PL07_AT2 0x8A807 size 0xB7.
 * Att_PL07_AT3 0x8A8BE size 0x61.
 * Att_PL07_SA3 0x8A91F size 0x98.
 * Att_PL07_TOKUSHUKOUDOU 0x8A9B7 size 0x13B.
 * Data: pl07_exatt_table is 0x262B68, 18 entries compared.
 * Globals: pl07_exatt_table 0x262B68.
 */

#include "structs.h"

void Att_SHOURYUUKEN(PLW* wk);
void Att_PL07_AT1(PLW* wk);
void Att_CHOUCHUURENGEKI(PLW* wk);
void Att_SLIDE_and_JUMP(PLW* wk);
void Att_PL07_SA2(PLW* wk);
void Att_PL07_AT2(PLW* wk);
void Att_PL07_AT3(PLW* wk);
void Att_PL07_SA3(PLW* wk);
void Att_HOMING_JUMP(PLW* wk);
void Att_DUMMY(PLW* );
void Att_PL07_TOKUSHUKOUDOU(PLW* wk);
void Att_METAMOR_WAIT(PLW* wk);
void Att_METAMOR_REBIRTH(PLW* wk);
void hoken_muriyari_chakuchi(PLW* wk);
void reset_mvxy_data(WORK* wk);
void set_char_move_init(WORK* wk, s16 koc, s16 index);
void char_move(WORK* wk);
void cal_mvxy_speed(WORK* wk);
void add_mvxy_speed(WORK* wk);
void setup_mvxy_data(WORK* wk, u16 ix);
void jumping_union_process(WORK* wk, s16 num);
void add_sp_arts_gauge_tokushu(PLW* wk);
void grade_add_personal_action(s16 ix);

void (*const pl07_exatt_table[18])(PLW*);

void (*const pl07_exatt_table[18])(PLW*) = {
    Att_SHOURYUUKEN, Att_PL07_AT1, Att_CHOUCHUURENGEKI,    Att_SLIDE_and_JUMP, Att_CHOUCHUURENGEKI, Att_PL07_SA2,
    Att_PL07_AT2,    Att_PL07_AT3, Att_PL07_SA3,           Att_SLIDE_and_JUMP, Att_HOMING_JUMP,     Att_DUMMY,
    Att_DUMMY,       Att_DUMMY,    Att_PL07_TOKUSHUKOUDOU, Att_DUMMY,          Att_METAMOR_WAIT,    Att_METAMOR_REBIRTH
};

void pl07_extra_attack(PLW* wk) {
    pl07_exatt_table[wk->wu.routine_no[2] - 16](wk);
}

/* The Xbox returns where the PS2 breaks out of the switch. */
void Att_PL07_SA2(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        hoken_muriyari_chakuchi(wk);
        wk->wu.rl_flag = wk->wu.rl_waza;
        reset_mvxy_data(&wk->wu);
        wk->wu.mvxy.index = wk->as->r_no;
        set_char_move_init(&wk->wu, 5, wk->as->char_ix);
        break;

    default:
        char_move(&wk->wu);
        cal_mvxy_speed(&wk->wu);
        add_mvxy_speed(&wk->wu);

        switch (wk->wu.cg_type) {
        case 20:
            setup_mvxy_data(&wk->wu, wk->wu.mvxy.index);
            wk->wu.cg_type = 0;
            break;

        case 30:
            wk->wu.mvxy.index = wk->as->data_ix;
            setup_mvxy_data(&wk->wu, wk->wu.mvxy.index);
            wk->wu.cg_type = 0;
            return;

        case 88:
            reset_mvxy_data(&wk->wu);
            wk->wu.cg_type = 0;
            break;
        }

        break;
    }
}

void Att_PL07_AT1(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        hoken_muriyari_chakuchi(wk);
        wk->wu.rl_flag = wk->wu.rl_waza;
        set_char_move_init(&wk->wu, 5, wk->as->char_ix);
        reset_mvxy_data(&wk->wu);
        wk->wu.mvxy.index = wk->as->r_no;
        break;

    case 1:
        char_move(&wk->wu);
        cal_mvxy_speed(&wk->wu);
        add_mvxy_speed(&wk->wu);

        switch (wk->wu.cg_type) {
        case 20:
            setup_mvxy_data(&wk->wu, wk->wu.mvxy.index);
            wk->wu.mvxy.index++;
            wk->wu.cg_type = 0;
            break;

        case 21:
            reset_mvxy_data(&wk->wu);
            wk->wu.cg_type = 0;
            break;

        case 30:
            wk->wu.routine_no[3] = 2;
            wk->wu.cg_type = 0;
            break;
        }

        break;
    case 2:
        char_move(&wk->wu);

        if (wk->wu.cg_type == 1) {
            setup_mvxy_data(&wk->wu, wk->wu.mvxy.index);
            wk->wu.routine_no[3] = 3;
            wk->wu.cg_type = 0;
        }

        break;

    case 3:
        jumping_union_process(&wk->wu, 4);
        break;

    case 4:
        char_move(&wk->wu);
        break;
    }
}

void Att_PL07_AT2(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = wk->wu.rl_waza;
        set_char_move_init(&wk->wu, 5, wk->as->char_ix);
        reset_mvxy_data(&wk->wu);
        break;

    case 1:
        char_move(&wk->wu);
        add_mvxy_speed(&wk->wu);
        cal_mvxy_speed(&wk->wu);

        if (wk->wu.cg_type == 20) {
            setup_mvxy_data(&wk->wu, wk->as->r_no);
            wk->wu.routine_no[3] = 2;
            wk->wu.cg_type = 0;
        }

        break;

    case 2:
        jumping_union_process(&wk->wu, 3);

        if (wk->wu.cg_type == 30) {
            setup_mvxy_data(&wk->wu, wk->wu.mvxy.index);
            wk->wu.cg_type = 0;
        }

        break;

    case 3:
        char_move(&wk->wu);
        break;
    }
}

void Att_PL07_AT3(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        set_char_move_init(&wk->wu, 5, wk->as->char_ix);
        break;

    case 1:
        char_move(&wk->wu);

        if (wk->wu.cg_type == 20) {
            wk->wu.routine_no[3]++;
        }

        break;

    case 2:
        jumping_union_process(&wk->wu, 3);
        break;

    case 3:
        char_move(&wk->wu);
        break;
    }
}

void Att_PL07_SA3(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = wk->wu.rl_waza;
        set_char_move_init(&wk->wu, 5, wk->as->char_ix);
        /* fallthrough */

    case 1:
        jumping_union_process(&wk->wu, 2);

        if (wk->wu.routine_no[3] != 2) {
            if (wk->wu.cg_type == 20) {
                setup_mvxy_data(&wk->wu, wk->as->data_ix);
                wk->wu.cg_type = 0;
            }

            if (wk->wu.cg_type == 30) {
                setup_mvxy_data(&wk->wu, wk->as->r_no);
                wk->wu.cg_type = 0;
            }
        }

        break;

    case 2:
        char_move(&wk->wu);
        break;
    }
}

void Att_PL07_TOKUSHUKOUDOU(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        hoken_muriyari_chakuchi(wk);
        wk->wu.rl_flag = wk->wu.rl_waza;
        setup_mvxy_data(&wk->wu, wk->as->data_ix);
        wk->wu.mvxy.index++;
        set_char_move_init(&wk->wu, 5, wk->as->char_ix);
        break;

    case 1:
        char_move(&wk->wu);

        if (wk->wu.cg_type == 20) {
            wk->wu.cg_type = 0;
            wk->wu.routine_no[3]++;
            add_mvxy_speed(&wk->wu);
            cal_mvxy_speed(&wk->wu);
        }

        break;

    case 2:
        jumping_union_process(&wk->wu, 3);

        if (wk->wu.cg_type == 40) {
            wk->wu.cg_type = 0;
            add_sp_arts_gauge_tokushu(wk);
        }

        if (wk->wu.cg_type == 20) {
            wk->wu.cg_type = 0;
            wk->wu.mvxy.index++;
            setup_mvxy_data(&wk->wu, wk->wu.mvxy.index);
        }

        break;

    case 3:
        char_move(&wk->wu);
        break;

    case 4:
        jumping_union_process(&wk->wu, 3);

        if (wk->wu.cg_type == 30) {
            wk->wu.cg_type = 0;
            wk->tk_dageki += 14;
            wk->tk_nage += 14;
        }

        if (wk->tk_dageki > 28) {
            wk->tk_dageki = 28;
        }

        if (wk->tk_nage > 28) {
            wk->tk_nage = 28;
        }

        if (wk->wu.cg_type == 64) {
            grade_add_personal_action(wk->wu.id);
        }

        break;
    }
}
