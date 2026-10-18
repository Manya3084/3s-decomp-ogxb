/* PLPAT00.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * pl00_extra_attack 0x8990C size 0x12.
 * Att_MOONSALT_KNEE_DROP 0x8991E size 0xED.
 * get_life_add_point 0x89A0B size 0x21.
 * Att_PL00_TOKUSHUKOUDOU 0x89A2C size 0xE5.
 * Att_JYOUKA 0x89B11 size 0x249.
 * Att_RESURRECTION 0x89D5A size 0xF4.
 * Data: mnd_em_tall is 0x2628B0, 0x54 bytes compared.
 * Data: glap_table is 0x262904, 0xA bytes compared.
 * Data: pl00_exatt_table is 0x262910, 18 entries compared.
 * Globals: mnd_em_tall 0x2628B0, glap_table 0x262904, pl00_exatt_table
 * 0x262910, Bonus_Game_Flag 0x7A8272, bg_w 0x7BC520, round_slow_flag 0xC7D8EA.
 */

#include "structs.h"

void Att_HADOUKEN(PLW* wk);
void Att_MOONSALT_KNEE_DROP(PLW* wk);
void Att_SLIDE_and_JUMP(PLW* wk);
void Att_SENPUUKYAKU(PLW* wk);
void Att_RESURRECTION(PLW* wk);
void Att_JYOUKA(PLW* wk);
void Att_DUMMY(PLW* );
void Att_PL00_TOKUSHUKOUDOU(PLW* wk);
void Att_METAMOR_WAIT(PLW* wk);
void Att_METAMOR_REBIRTH(PLW* wk);
void set_char_move_init(WORK* wk, s16 koc, s16 index);
void setup_mvxy_data(WORK* wk, u16 ix);
void cal_delta_speed(WORK* wk, s16 tm, s16 x1, s16 y1, s8 xsw, s8 ysw);
void char_move(WORK* wk);
void add_mvxy_speed(WORK* wk);
void jumping_union_process(WORK* wk, s16 num);
void reset_mvxy_data(WORK* wk);
extern u8 round_slow_flag;
s16 get_life_add_point(u8 num, s16 ori_add);
void char_move_cmja(WORK* wk);
void hoken_muriyari_chakuchi(PLW* wk);
void add_sp_arts_gauge_tokushu(PLW* wk);
void grade_add_personal_action(s16 ix);
extern s16 Bonus_Game_Flag;
extern BG bg_w;
void cal_all_speed_data(WORK* wk, s16 tm, s16 x1, s16 y1, s8 xsw, s8 ysw);
s32 effect_I3_init(WORK* wk, u8 tix);
void Bg_Y_Sitei(u8 on_off, s16 pos);
s32 setup_kuzureochi(PLW* wk);
void set_char_move_init2(WORK* wk, s16 koc, s16 index, s16 ip, s16 scf);
void cal_mvxy_speed(WORK* wk);

void (*const pl00_exatt_table[18])(PLW*);

const s16 mnd_em_tall[21][2] = { { 28, 56 }, { 24, 44 }, { 24, 40 }, { 20, 32 }, { 24, 48 }, { 24, 40 }, { 28, 60 },
                                 { 16, 44 }, { 32, 32 }, { 28, 24 }, { 20, 32 }, { 24, 40 }, { 24, 40 }, { 28, 56 },
                                 { 24, 40 }, { 24, 40 }, { 24, 40 }, { 24, 40 }, { 24, 40 }, { 24, 40 }, { 24, 40 } };

const s16 glap_table[5] = { 1, 2, 3, 4, 0 };

void (*const pl00_exatt_table[18])(PLW*) = { Att_HADOUKEN,
                                             Att_MOONSALT_KNEE_DROP,
                                             Att_SLIDE_and_JUMP,
                                             Att_SENPUUKYAKU,
                                             Att_HADOUKEN,
                                             Att_RESURRECTION,
                                             Att_JYOUKA,
                                             Att_DUMMY,
                                             Att_DUMMY,
                                             Att_DUMMY,
                                             Att_DUMMY,
                                             Att_DUMMY,
                                             Att_DUMMY,
                                             Att_DUMMY,
                                             Att_PL00_TOKUSHUKOUDOU,
                                             Att_DUMMY,
                                             Att_METAMOR_WAIT,
                                             Att_METAMOR_REBIRTH };

void pl00_extra_attack(PLW* wk) {
    pl00_exatt_table[wk->wu.routine_no[2] - 16](wk);
}

void Att_MOONSALT_KNEE_DROP(PLW* wk) {
    PLW* twk;
    s16 ex;
    s16 ey;

    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = wk->wu.rl_waza;
        set_char_move_init(&wk->wu, 5, wk->as->char_ix);
        setup_mvxy_data(&wk->wu, wk->as->data_ix);
        twk = (PLW*)wk->wu.target_adrs;

        if (wk->wu.rl_flag) {
            ex = twk->wu.position_x - mnd_em_tall[twk->player_number][0];
        } else {
            ex = twk->wu.position_x + mnd_em_tall[twk->player_number][0];
        }

        ey = mnd_em_tall[twk->player_number][1];
        wk->wu.mvxy.a[0].sp = 0;
        cal_delta_speed(&wk->wu, wk->as->r_no, ex, ey, 2, 2);

        if (wk->wu.rl_flag == 0) {
            wk->wu.mvxy.a[0].sp = -wk->wu.mvxy.a[0].sp;
            wk->wu.mvxy.d[0].sp = -wk->wu.mvxy.d[0].sp;
        }

        break;

    case 1:
        char_move(&wk->wu);

        if (wk->wu.cg_type == 20) {
            wk->wu.routine_no[3]++;
            wk->wu.cg_type = 0;
            add_mvxy_speed(&wk->wu);
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

void Att_RESURRECTION(PLW* wk) {
    wk->scr_pos_set_flag = 0;

    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.direction = 0;
        reset_mvxy_data(&wk->wu);
        set_char_move_init(&wk->wu, 5, wk->as->char_ix);
        round_slow_flag = 0;
        wk->resurrection_resv = 0;
        break;

    case 1:
        char_move(&wk->wu);

        if (wk->wu.cg_type) {
            wk->wu.direction = get_life_add_point(wk->wu.cg_type, wk->wu.direction);
            wk->wu.cg_type = 0;
        }

        wk->wu.vital_new += wk->wu.direction;

        if (wk->wu.vital_new >= wk->wu.vitality) {
            wk->wu.vital_new = wk->wu.vitality;
            wk->wu.mvxy.d[1].sp = -0x8000;
            wk->wu.direction = 0;
            wk->wu.routine_no[3]++;

            if (wk->wu.vital_new < 0) {
                wk->wu.vital_new = 0;
            }

            char_move_cmja(&wk->wu);
        }

        break;

    case 2:
        jumping_union_process(&wk->wu, 3);
        break;

    default:
        char_move(&wk->wu);
        break;
    }
}

s16 get_life_add_point(u8 num, s16 ori_add) {
    s16 add_pts = ori_add;
    u16 ix = num - 20;

    if (ix < 9) {
        add_pts = glap_table[ix / 2];
    }

    return add_pts;
}

void Att_PL00_TOKUSHUKOUDOU(PLW* wk) {
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
            wk->wu.routine_no[3]++;
            wk->tk_dageki += 16;
            wk->tk_nage += 8;
            wk->tk_kizetsu += 2;

            if (wk->tk_dageki > 16) {
                wk->tk_dageki = 16;
            }

            if (wk->tk_nage > 8) {
                wk->tk_nage = 8;
            }

            if (wk->tk_kizetsu > 2) {
                wk->tk_kizetsu = 2;
            }

            grade_add_personal_action(wk->wu.id);
        }

        break;

    default:
        char_move(&wk->wu);
        break;
    }
}

void Att_JYOUKA(PLW* wk) {
    s16 x1;
    s16 y1;

    wk->wu.swallow_no_effect = 1;

    switch (wk->wu.routine_no[3]) {
    case 0:
        if (Bonus_Game_Flag == 20) {
            wk->wu.routine_no[3] = 10;
            wk->wu.rl_flag = wk->wu.rl_waza;
            set_char_move_init(&wk->wu, 5, wk->as->char_ix);
            x1 = bg_w.bgw[1].wxy[0].disp.pos;
            y1 = 80;
            cal_all_speed_data(&wk->wu, 20, x1, y1, 1, 2);

            if (wk->wu.rl_flag == 0) {
                wk->wu.mvxy.a[0].sp = -wk->wu.mvxy.a[0].sp;
                wk->wu.mvxy.d[0].sp = -wk->wu.mvxy.d[0].sp;
            }

            effect_I3_init(&wk->wu, 3);
            wk->sfwing_pos = 88;
            Bg_Y_Sitei(1, wk->sfwing_pos);
            break;
        }

        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = wk->wu.rl_waza;
        set_char_move_init(&wk->wu, 5, (wk->as->char_ix));
        x1 = bg_w.bgw[1].wxy[0].disp.pos;
        y1 = 40;
        cal_all_speed_data(&wk->wu, 20, x1, y1, 1, 1);

        if (wk->wu.rl_flag == 0) {
            wk->wu.mvxy.a[0].sp = -wk->wu.mvxy.a[0].sp;
            wk->wu.mvxy.d[0].sp = -wk->wu.mvxy.d[0].sp;
        }

        effect_I3_init(&wk->wu, 3);

        break;

    case 1:
    case 10:
        if ((setup_kuzureochi(wk) == 0) && (char_move(&wk->wu), wk->wu.cg_type == 20)) {
            wk->wu.routine_no[3]++;
            wk->wu.cg_type = 0;
        }

        break;

    case 2:
        if (wk->resurrection_resv) {
            set_char_move_init2(&wk->wu, 5, 60, 8, 1);
            reset_mvxy_data(&wk->wu);
            wk->wu.routine_no[3] = 3;
            break;
        }
        char_move(&wk->wu);
        add_mvxy_speed(&wk->wu);
        cal_mvxy_speed(&wk->wu);

        if (wk->wu.cg_type == 30) {
            wk->wu.routine_no[3]++;
            wk->wu.cg_type = 0;
            reset_mvxy_data(&wk->wu);
        }

        break;

    case 3:
        char_move(&wk->wu);

        if (wk->wu.cg_type == 20) {
            wk->wu.routine_no[3]++;
            wk->wu.cg_type = 0;
            wk->wu.mvxy.d[1].sp = 0xFFFFA000;
            add_mvxy_speed(&wk->wu);
        }

        break;

    case 4:
        jumping_union_process(&wk->wu, 5);
        break;

    case 5:
        char_move(&wk->wu);
        break;

    case 11:
        wk->sfwing_pos += 2;
        char_move(&wk->wu);
        add_mvxy_speed(&wk->wu);
        cal_mvxy_speed(&wk->wu);

        if (wk->wu.cg_type == 30) {
            wk->wu.routine_no[3]++;
            wk->wu.cg_type = 0;
            reset_mvxy_data(&wk->wu);
        }

        Bg_Y_Sitei(1, wk->sfwing_pos);
        break;

    case 12:
        char_move(&wk->wu);

        if (wk->wu.cg_type == 20) {
            wk->wu.routine_no[3] = 4;
            wk->wu.cg_type = 0;
            wk->wu.mvxy.d[1].sp = 0xFFFFA000;
            add_mvxy_speed(&wk->wu);
        }

        break;
    }
}
