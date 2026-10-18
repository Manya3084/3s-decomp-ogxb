/* plpat17.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * pl17_extra_attack 0xE3DCA size 0x12.
 * set_kabe_move_spd 0xE3DDC size 0x53.
 * kabe_check 0xE3E2F size 0x3A.
 * Att_PL17_AT2 0xE3E69 size 0x5B.
 * Att_PL17_TOKUSHUKOUDOU 0xE3EC4 size 0xF4. Read against the x86: 0x6E and
 * 0x64 are recover * 110 / 100 as imul and idiv. The C is the PS2 C.
 * Att_PL17_AT1 0xE3FB8 size 0x326.
 * Data: pl17_exatt_table is 0x2AE530, 18 entries compared.
 * Globals: pl16_exatt_table 0x2AE4E8, Bonus_Game_Flag 0x7A8272.
 */

#include "structs.h"

void Att_CHOUCHUURENGEKI(PLW* wk);
void Att_PL17_AT1(PLW* wk);
void Att_HADOUKEN2(PLW* wk);
void Att_PL17_AT2(PLW* wk);
void Att_KUUCHUUJINNCHUUWATARI(PLW* wk);
void Att_DUMMY(PLW* );
void Att_PL17_TOKUSHUKOUDOU(PLW* wk);
void Att_METAMOR_WAIT(PLW* wk);
void Att_METAMOR_REBIRTH(PLW* wk);
void reset_mvxy_data(WORK* wk);
void setup_mvxy_data(WORK* wk, u16 ix);
extern s16 Bonus_Game_Flag;
void set_char_move_init(WORK* wk, s16 koc, s16 index);
void set_kabe_move_spd(WORK* wk, s16 tm);
void char_move(WORK* wk);
s32 effect_I3_init(WORK* wk, u8 tix);
void add_mvxy_speed(WORK* wk);
void jumping_union_process(WORK* wk, s16 num);
void cal_mvxy_speed(WORK* wk);
s16 get_center_position();
s32 kabe_check(WORK* wk);
void char_move_cmj4(WORK* wk);
void cal_all_speed_data(WORK* wk, s16 tm, s16 x1, s16 y1, s8 xsw, s8 ysw);
void hoken_muriyari_chakuchi(PLW* wk);
s32 effect_L8_init(PLW* wk);
void add_sp_arts_gauge_tokushu(PLW* wk);
void grade_add_personal_action(s16 ix);

void (*const pl17_exatt_table[18])(PLW*);

void (*const pl17_exatt_table[18])(PLW*) = {
    Att_CHOUCHUURENGEKI, Att_PL17_AT1,     Att_HADOUKEN2,      Att_PL17_AT2, Att_KUUCHUUJINNCHUUWATARI,
    Att_DUMMY,           Att_DUMMY,        Att_DUMMY,          Att_DUMMY,    Att_DUMMY,
    Att_DUMMY,           Att_DUMMY,        Att_DUMMY,          Att_DUMMY,    Att_PL17_TOKUSHUKOUDOU,
    Att_DUMMY,           Att_METAMOR_WAIT, Att_METAMOR_REBIRTH
};

void pl17_extra_attack(PLW* wk) {
    pl17_exatt_table[wk->wu.routine_no[2] - 16](wk);
}

void Att_PL17_AT1(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = wk->wu.rl_waza;
        wk->scr_pos_set_flag = 0;
        reset_mvxy_data(&wk->wu);
        setup_mvxy_data(&wk->wu, wk->as->r_no);
        wk->wu.mvxy.index = wk->as->data_ix;

        if (Bonus_Game_Flag != 20 || (Bonus_Game_Flag == 20 && wk->bs2_on_car == 0)) {
            wk->wu.xyz[1].disp.pos = 0;
        }

        set_char_move_init(&wk->wu, 5, wk->as->char_ix);
        set_kabe_move_spd(&wk->wu, 28);
        wk->rl_save = 0;
        break;

    case 1:
        char_move(&wk->wu);

        if (wk->wu.cg_type == 10) {
            wk->wu.routine_no[3] = 3;
            effect_I3_init(&wk->wu, 2);
        }

        if (wk->wu.routine_no[3] != 1) {
            add_mvxy_speed(&wk->wu);
        }

        break;

    case 2:
        char_move(&wk->wu);

        if (wk->wu.cg_type == 20) {
            setup_mvxy_data(&wk->wu, wk->wu.mvxy.index);
            wk->wu.mvxy.index++;
            wk->wu.routine_no[3] = 3;
            wk->wu.cg_type = 0;
        }

        if (wk->wu.cg_type == 30) {
            setup_mvxy_data(&wk->wu, wk->wu.mvxy.index);
            wk->wu.mvxy.a[1].sp = wk->wu.mvxy.d[1].sp = wk->wu.mvxy.kop[1] = 0;
            wk->wu.mvxy.index++;
            wk->wu.routine_no[3] = 4;
            wk->wu.cg_type = 0;
        }

        if (wk->wu.routine_no[3] != 2) {
            add_mvxy_speed(&wk->wu);
        }

        break;

    case 3:
        jumping_union_process(&wk->wu, 2);

        if (wk->wu.routine_no[3] != 2) {
            if (wk->wu.cg_type == 20) {
                setup_mvxy_data(&wk->wu, wk->wu.mvxy.index);
                wk->wu.mvxy.index++;
                wk->wu.cg_type = 0;
            }

            if (wk->wu.cg_type == 21) {
                reset_mvxy_data(&wk->wu);
                wk->wu.cg_type = 0;
                wk->wu.routine_no[3] = 2;
            }

            if (wk->wu.cg_type == 25) {
                wk->wu.cg_type = 0;
                wk->wu.routine_no[3] = 5;
            }
        }

        break;

    case 4:
        char_move(&wk->wu);
        cal_mvxy_speed(&wk->wu);
        add_mvxy_speed(&wk->wu);

        if (wk->wu.cg_type == 20) {
            setup_mvxy_data(&wk->wu, wk->wu.mvxy.index);
            wk->wu.mvxy.index++;
            wk->wu.routine_no[3] = 3;
            wk->wu.cg_type = 0;
        }

        if (wk->wu.cg_type == 21) {
            reset_mvxy_data(&wk->wu);
            wk->wu.cg_type = 0;
            wk->wu.routine_no[3] = 2;
        }

        if (wk->wu.cg_type == 30) {
            setup_mvxy_data(&wk->wu, wk->wu.mvxy.index);
            wk->wu.mvxy.a[1].sp = wk->wu.mvxy.d[1].sp = wk->wu.mvxy.kop[1] = 0;
            wk->wu.mvxy.index++;
            wk->wu.cg_type = 0;
        }

        break;

    case 5:
        jumping_union_process(&wk->wu, 2);

        if (wk->wu.routine_no[3] != 2) {
            if (wk->wu.cg_type == 21) {
                reset_mvxy_data(&wk->wu);
                wk->wu.cg_type = 0;
                wk->wu.routine_no[3] = 2;
            }

            if (wk->wu.cg_type == 26) {
                wk->wu.cg_type = 0;
                wk->wu.routine_no[3] = 3;
            }

            if (wk->wu.cg_type == 30) {
                wk->wu.cg_type = 0;
                wk->wu.mvxy.d[0].sp = 0;
            }

            if (wk->rl_save) {
                wk->rl_save = 0;
                wk->wu.routine_no[3] = 2;
                wk->wu.xyz[0].disp.pos = get_center_position();

                if (wk->wu.rl_flag) {
                    wk->wu.xyz[0].disp.pos -= 142;
                } else {
                    wk->wu.xyz[0].disp.pos += 142;
                }
            }
        }

        if ((wk->wu.routine_no[3] == 5) && (kabe_check(&wk->wu))) {
            char_move_cmj4(&wk->wu);
            reset_mvxy_data(&wk->wu);
            wk->rl_save = 1;
        }

        break;
    }
}

void set_kabe_move_spd(WORK* wk, s16 tm) {
    s16 tar_pos;

    tar_pos = get_center_position();

    if (wk->rl_flag) {
        tar_pos -= 192;
    } else {
        tar_pos += 192;
    }

    cal_all_speed_data(wk, tm, tar_pos, wk->xyz[1].disp.pos + 120, 2, 2);

    if (!wk->rl_flag) {
        wk->mvxy.a[0].sp = -wk->mvxy.a[0].sp;
        wk->mvxy.d[0].sp = -wk->mvxy.d[0].sp;
    }

    wk->mvxy.kop[0] = 1;
}

s32 kabe_check(WORK* wk) {
    s16 tar_pos;

    if (wk->xyz[1].disp.pos < 85) {
        return 0;
    }

    tar_pos = get_center_position();

    if (wk->rl_flag) {
        tar_pos -= 142;

        if (!(wk->xyz[0].disp.pos > tar_pos)) {
            wk->xyz[0].disp.pos = tar_pos;
            return 1;
        }

        return 0;
    }

    tar_pos += 142;

    if (wk->xyz[0].disp.pos >= tar_pos) {
        wk->xyz[0].disp.pos = tar_pos;
        return 1;
    }

    return 0;
}

void Att_PL17_AT2(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = wk->wu.rl_waza;
        hoken_muriyari_chakuchi(wk);
        set_char_move_init(&wk->wu, 5, wk->as->char_ix);
        break;

    case 1:
        char_move(&wk->wu);

        if (wk->wu.cg_type == 10) {
            wk->wu.cg_type = 0;
            effect_L8_init(wk);
        }

        break;
    }
}

void Att_PL17_TOKUSHUKOUDOU(PLW* wk) {
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

        switch (wk->wu.cg_type) {
        case 40:
            wk->wu.cg_type = 0;
            add_sp_arts_gauge_tokushu(wk);
            break;

        case 10:
            wk->wu.cg_type = 0;
            wk->tk_dageki += 10;

            if (wk->tk_dageki > 10) {
                wk->tk_dageki = 10;
            }

            grade_add_personal_action(wk->wu.id);
            break;

        case 20:
            wk->wu.cg_type = 0;
            wk->tk_dageki += 10;

            if (wk->tk_dageki > 20) {
                wk->tk_dageki = 20;
            }

            break;

        case 30:
            wk->wu.routine_no[3]++;

            if (wk->tk_success < 3) {
                wk->tk_success++;
                wk->py->recover = (wk->py->recover * 110) / 100;
            }

            break;
        }

        break;

    default:
        char_move(&wk->wu);
        break;
    }
}
