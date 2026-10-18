/* PLPAT01.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * pl01_extra_attack 0x89E4E size 0x12.
 * Att_PL01_DDT 0x89E60 size 0x110.
 * Att_PL01_TOKUSHUKOUDOU 0x89F70 size 0xCE.
 * Data: pl01_ddt_dat is 0x262958, 0x50 bytes compared, found by the bytes.
 * Data: pl01_exatt_table is 0x2629A8, 18 entries compared.
 * Globals: pl01_ddt_dat 0x262958.
 */

#include "structs.h"

void Att_CHOUCHUURENGEKI(PLW* wk);
void Att_SHOURYUUKEN(PLW* wk);
void Att_HADOUKEN(PLW* wk);
void Att_HADOUKEN2(PLW* wk);
void Att_SENPUUKYAKU2(PLW* wk);
void Att_SENPUUKYAKU(PLW* wk);
void Att_NM_OKIAGARI(PLW* wk);
void Att_PL01_DDT(PLW* wk);
void Att_HOMING_JUMP(PLW* wk);
void Att_SLIDE_and_JUMP(PLW* wk);
void Att_DUMMY(PLW* );
void Att_PL01_TOKUSHUKOUDOU(PLW* wk);
void Att_METAMOR_WAIT(PLW* wk);
void Att_METAMOR_REBIRTH(PLW* wk);
void hoken_muriyari_chakuchi(PLW* wk);
void reset_mvxy_data(WORK* wk);
void set_char_move_init(WORK* wk, s16 koc, s16 index);
void char_move(WORK* wk);
void setup_mvxy_data(WORK* wk, u16 ix);
void cal_initial_speed_y(WORK* wk, s16 tm, s16 y1);
void jumping_union_process(WORK* wk, s16 num);
void add_sp_arts_gauge_tokushu(PLW* wk);
void grade_add_personal_action(s16 ix);

const s16 pl01_ddt_dat[20][2] = { { 46, 11 }, { 32, 12 }, { 28, 13 }, { 16, 14 }, { 36, 15 }, { 16, 16 }, { 60, 17 },
                                  { 20, 18 }, { 24, 19 }, { 12, 20 }, { 16, 14 }, { 28, 13 }, { 28, 13 }, { 46, 11 },
                                  { 28, 13 }, { 24, 21 }, { 18, 22 }, { 52, 23 }, { 18, 16 }, { 38, 24 } };

void (*const pl01_exatt_table[18])(PLW*) = { Att_CHOUCHUURENGEKI, Att_SHOURYUUKEN,     Att_HADOUKEN,
                                             Att_HADOUKEN2,       Att_CHOUCHUURENGEKI, Att_SENPUUKYAKU2,
                                             Att_SENPUUKYAKU,     Att_NM_OKIAGARI,     Att_PL01_DDT,
                                             Att_HOMING_JUMP,     Att_SLIDE_and_JUMP,  Att_DUMMY,
                                             Att_DUMMY,           Att_DUMMY,           Att_PL01_TOKUSHUKOUDOU,
                                             Att_DUMMY,           Att_METAMOR_WAIT,    Att_METAMOR_REBIRTH };

void pl01_extra_attack(PLW* wk) {
    pl01_exatt_table[wk->wu.routine_no[2] - 16](wk);
}

void Att_PL01_DDT(PLW* wk) {
    PLW* twk = (PLW*)wk->wu.target_adrs;

    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        hoken_muriyari_chakuchi(wk);
        wk->wu.rl_flag = wk->wu.rl_waza;
        reset_mvxy_data(&wk->wu);
        wk->wu.mvxy.index = wk->as->data_ix;
        set_char_move_init(&wk->wu, 5, wk->as->char_ix);
        break;

    case 1:
        char_move(&wk->wu);

        if (wk->wu.cg_type == 20) {
            wk->wu.cg_type = 0;
            setup_mvxy_data(&wk->wu, wk->wu.mvxy.index);
            wk->wu.mvxy.index++;
            wk->wu.routine_no[3] = 2;
            cal_initial_speed_y(&wk->wu, wk->as->r_no, pl01_ddt_dat[twk->player_number][0]);
        }

        break;

    case 2:
        jumping_union_process(&wk->wu, 3);

        if (wk->wu.routine_no[3] != 3 && wk->wu.cg_ja.caix) {
            wk->wu.cg_ja.caix = pl01_ddt_dat[twk->player_number][1];
            wk->wu.h_cat = wk->wu.cg_ja.caix + wk->wu.catch_adrs;
        }

        break;

    case 3:
        char_move(&wk->wu);
        break;
    }
}

void Att_PL01_TOKUSHUKOUDOU(PLW* wk) {
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

        switch (wk->wu.cg_type) {
        case 20:
            wk->wu.cg_type = 0;
            wk->tk_dageki += 3;
            wk->tk_nage += 2;
            break;

        case 30:
            wk->wu.cg_type = 0;
            wk->tk_dageki += 2;
            wk->tk_nage += 2;
            break;

        case 64:
            grade_add_personal_action(wk->wu.id);
            break;
        }

        if (wk->tk_dageki > 12) {
            wk->tk_dageki = 12;
        }

        if (wk->tk_nage > 16) {
            wk->tk_nage = 16;
        }

        break;
    }
}
