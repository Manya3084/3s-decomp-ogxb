/* plpat14.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * pl14_extra_attack 0xE377F size 0x12.
 * Att_PL14_AT1 0xE3791 size 0x149.
 * Att_PL14_AT2 0xE38DA size 0xCF.
 * Att_PL14_AT3 0xE39A9 size 0x273.
 * Att_PL14_TOKUSHUKOUDOU 0xE3C1C size 0xB1.
 * Data: stop_count 0x7A9D74.
 * Data: pl14_HYAKKI_dat is 0x2AE478, 0x28 bytes compared.
 * Data: pl14_exatt_table is 0x2AE4A0, 18 entries compared.
 * Globals: pl14_HYAKKI_dat 0x2AE478, pl14_exatt_table 0x2AE4A0, stop_count
 * 0x7A9D74.
 */

#include "structs.h"

void Att_HADOUKEN(PLW* wk);
void Att_SHOURYUUKEN(PLW* wk);
void Att_SENPUUKYAKU(PLW* wk);
void Att_KUUCHUUJINNCHUUWATARI(PLW* wk);
void Att_SHOURYUUREPPA(PLW* wk);
void Att_SLIDE_and_JUMP(PLW* wk);
void Att_KUUCHUUNICHIRINSHOU(PLW* wk);
void Att_PL14_AT1(PLW* wk);
void Att_CHOUCHUURENGEKI(PLW* wk);
void Att_PL14_AT2(PLW* wk);
void Att_PL14_AT3(PLW* wk);
void Att_DUMMY(PLW* );
void Att_PL14_TOKUSHUKOUDOU(PLW* wk);
void Att_METAMOR_WAIT(PLW* wk);
void Att_METAMOR_REBIRTH(PLW* wk);
void hoken_muriyari_chakuchi(PLW* wk);
void reset_mvxy_data(WORK* wk);
void set_char_move_init(WORK* wk, s16 koc, s16 index);
void char_move(WORK* wk);
void cal_mvxy_speed(WORK* wk);
void setup_mvxy_data(WORK* wk, u16 ix);
void char_move_z(WORK* wk);
void add_to_mvxy_data(WORK* wk, u16 ix);
void jumping_union_process(WORK* wk, s16 num);
void add_mvxy_speed(WORK* wk);
void add_sp_arts_gauge_tokushu(PLW* wk);
void grade_add_personal_action(s16 ix);

extern s8 stop_count[2];

const s16 pl14_HYAKKI_dat[20] = { 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 7, 6, 6, 4, 6, 14, 15, 16, 17, 18 };

void (*const pl14_exatt_table[18])(PLW*);

void (*const pl14_exatt_table[18])(PLW*) = { Att_HADOUKEN,
                                             Att_SHOURYUUKEN,
                                             Att_SENPUUKYAKU,
                                             Att_KUUCHUUJINNCHUUWATARI,
                                             Att_SHOURYUUREPPA,
                                             Att_SLIDE_and_JUMP,
                                             Att_KUUCHUUNICHIRINSHOU,
                                             Att_PL14_AT1,
                                             Att_CHOUCHUURENGEKI,
                                             Att_PL14_AT2,
                                             Att_HADOUKEN,
                                             Att_PL14_AT3,
                                             Att_DUMMY,
                                             Att_DUMMY,
                                             Att_PL14_TOKUSHUKOUDOU,
                                             Att_DUMMY,
                                             Att_METAMOR_WAIT,
                                             Att_METAMOR_REBIRTH };

void pl14_extra_attack(PLW* wk) {
    pl14_exatt_table[wk->wu.routine_no[2] - 16](wk);
}

void Att_PL14_AT1(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        hoken_muriyari_chakuchi(wk);
        wk->wu.rl_flag = wk->wu.rl_waza;
        wk->rl_save = wk->wu.rl_flag;
        reset_mvxy_data(&wk->wu);
        wk->wu.mvxy.index = wk->as->r_no;
        set_char_move_init(&wk->wu, 5, wk->as->char_ix);
        stop_count[wk->wu.id] = 0;
        break;

    case 1:
        char_move(&wk->wu);
        cal_mvxy_speed(&wk->wu);

        if (wk->rl_save) {
            wk->wu.xyz[0].cal += wk->wu.mvxy.a[0].sp;
        } else {
            wk->wu.xyz[0].cal -= wk->wu.mvxy.a[0].sp;
        }

        wk->wu.xyz[1].cal += wk->wu.mvxy.a[1].sp;

        switch (wk->wu.cg_type) {
        case 10:
            wk->wu.routine_no[3]++;
            /* fallthrough */

        case 20:
            setup_mvxy_data(&wk->wu, wk->wu.mvxy.index);
            wk->wu.mvxy.index++;
            wk->wu.cg_type = 0;
            break;

        case 21:
            reset_mvxy_data(&wk->wu);
            wk->wu.cg_type = 0;
            break;
        }

        break;

    default:
        char_move(&wk->wu);
        cal_mvxy_speed(&wk->wu);

        if (wk->rl_save) {
            wk->wu.xyz[0].cal += wk->wu.mvxy.a[0].sp;
        } else {
            wk->wu.xyz[0].cal -= wk->wu.mvxy.a[0].sp;
        }

        wk->wu.xyz[1].cal += wk->wu.mvxy.a[1].sp;
        wk->wu.rl_flag = wk->wu.rl_waza;

        if ((wk->wu.mvxy.a[0].sp != 0) && wk->old_pos_data[0] == wk->old_pos_data[1]) {
            char_move_z(&wk->wu);
        }

        switch (wk->wu.cg_type) {
        case 20:
            setup_mvxy_data(&wk->wu, wk->wu.mvxy.index);
            wk->wu.mvxy.index++;
            wk->wu.cg_type = 0;
            break;

        case 21:
            reset_mvxy_data(&wk->wu);
            wk->wu.cg_type = 0;
            char_move_z(&wk->wu);
            break;
        }

        break;
    }
}

void Att_PL14_AT2(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        set_char_move_init(&wk->wu, 5, wk->as->char_ix);
        wk->wu.mvxy.index = wk->as->r_no;
        break;

    case 1:
        char_move(&wk->wu);

        switch (wk->wu.cg_type) {
        case 10:
            wk->wu.routine_no[3]++;
            wk->wu.cg_type = 0;
            break;

        case 20:
            setup_mvxy_data(&wk->wu, wk->wu.mvxy.index);
            wk->wu.mvxy.index++;
            wk->wu.cg_type = 0;
            break;

        case 30:
            add_to_mvxy_data(&wk->wu, wk->wu.mvxy.index);
            wk->wu.mvxy.index++;
            wk->wu.cg_type = 0;
            break;
        }
        break;

    case 2:
        jumping_union_process(&wk->wu, 3);

        if (wk->wu.cg_type == 40) {
            wk->wu.routine_no[3] = 1;
            wk->wu.cg_type = 0;
        }

        break;

    case 3:
        char_move(&wk->wu);
        break;
    }
}

void Att_PL14_AT3(PLW* wk) {
    PLW* twk = (PLW*)wk->wu.target_adrs;

    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        hoken_muriyari_chakuchi(wk);
        wk->wu.rl_flag = wk->wu.rl_waza;
        reset_mvxy_data(&wk->wu);
        wk->wu.mvxy.index = wk->as->r_no;
        set_char_move_init(&wk->wu, 5, wk->as->char_ix);
        break;

    case 1:
        char_move(&wk->wu);

        if (wk->wu.cg_type == 20) {
            setup_mvxy_data(&wk->wu, wk->wu.mvxy.index);
            wk->wu.mvxy.index++;
            wk->wu.routine_no[3] = 2;
            wk->wu.cg_type = 0;
        }

        if (wk->wu.cg_type == 30) {
            setup_mvxy_data(&wk->wu, wk->wu.mvxy.index);
            wk->wu.mvxy.a[1].sp = wk->wu.mvxy.d[1].sp = wk->wu.mvxy.kop[1] = 0;
            wk->wu.mvxy.index++;
            wk->wu.routine_no[3] = 3;
            wk->wu.cg_type = 0;
        }

        if (wk->wu.routine_no[3] != 1) {
            add_mvxy_speed(&wk->wu);
        }

        break;

    case 2:
        jumping_union_process(&wk->wu, 1);

        if (wk->wu.cg_type == 1) {
            wk->wu.cg_type = 0;
            wk->wu.routine_no[3] = 4;
        }

        if ((wk->wu.routine_no[3] != 1) && (wk->wu.cg_type == 20)) {
            setup_mvxy_data(&wk->wu, wk->wu.mvxy.index);
            wk->wu.mvxy.index++;
            wk->wu.cg_type = 0;
        }

        if ((wk->wu.routine_no[3] != 1) && wk->wu.cg_ja.caix) {
            wk->wu.cg_ja.caix = pl14_HYAKKI_dat[twk->player_number];
            wk->wu.h_cat = wk->wu.catch_adrs + wk->wu.cg_ja.caix;
        }

        break;

    case 3:
        char_move(&wk->wu);
        cal_mvxy_speed(&wk->wu);
        add_mvxy_speed(&wk->wu);

        if (wk->wu.cg_type == 20) {
            setup_mvxy_data(&wk->wu, wk->wu.mvxy.index);
            wk->wu.mvxy.index++;
            wk->wu.routine_no[3] = 2;
            wk->wu.cg_type = 0;
        }

        if (wk->wu.cg_type == 21) {
            reset_mvxy_data(&wk->wu);
            wk->wu.cg_type = 0;
            wk->wu.routine_no[3] = 1;
        }

        if (wk->wu.cg_type == 30) {
            setup_mvxy_data(&wk->wu, wk->wu.mvxy.index);
            wk->wu.mvxy.a[1].sp = wk->wu.mvxy.d[1].sp = wk->wu.mvxy.kop[1] = 0;
            wk->wu.mvxy.index++;
            wk->wu.cg_type = 0;
        }

        break;

    case 4:
        char_move(&wk->wu);

        if (wk->wu.cg_type == 1) {
            wk->wu.cg_type = 0;
            wk->wu.routine_no[3] = 2;
        }

        if ((wk->wu.routine_no[3] != 2) && (wk->wu.cg_type == 20)) {
            setup_mvxy_data(&wk->wu, wk->wu.mvxy.index);
            wk->wu.mvxy.index++;
            wk->wu.cg_type = 0;
        }

        if ((wk->wu.routine_no[3] != 2) && wk->wu.cg_ja.caix) {
            wk->wu.cg_ja.caix = pl14_HYAKKI_dat[(twk->player_number)];
            wk->wu.h_cat = wk->wu.catch_adrs + wk->wu.cg_ja.caix;
        }

        break;
    }
}

void Att_PL14_TOKUSHUKOUDOU(PLW* wk) {
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
        }

        if (wk->wu.cg_type == 64) {
            wk->wu.cg_type = 0;
            wk->tk_dageki += 14;
            wk->tk_kizetsu += 9;

            if (wk->tk_dageki > 14) {
                wk->tk_dageki = 14;
            }

            if (wk->tk_kizetsu > 9) {
                wk->tk_kizetsu = 9;
            }

            grade_add_personal_action(wk->wu.id);
        }

        break;
    }
}
