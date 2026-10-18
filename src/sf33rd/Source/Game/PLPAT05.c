/* PLPAT05.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * pl05_extra_attack 0x8A32A size 0x12.
 * Att_PL05_TOKUSHUKOUDOU is folded into 0x8B639 with 2 other bodies. Unnamed.
 * Data: pl05_exatt_table is 0x262AD8, 18 entries compared.
 */

#include "structs.h"

void Att_CHOUCHUURENGEKI(PLW* wk);
void Att_HADOUKEN(PLW* wk);
void Att_SENPUUKYAKU(PLW* wk);
void Att_JINNCHUUWATARI(PLW* wk);
void Att_SLIDE_and_JUMP(PLW* wk);
void Att_DUMMY(PLW* );
void Att_PL05_TOKUSHUKOUDOU(PLW* wk);
void Att_METAMOR_WAIT(PLW* wk);
void Att_METAMOR_REBIRTH(PLW* wk);
void hoken_muriyari_chakuchi(PLW* wk);
void set_char_move_init(WORK* wk, s16 koc, s16 index);
void char_move(WORK* wk);
void add_sp_arts_gauge_tokushu(PLW* wk);
void grade_add_personal_action(s16 ix);

void (*const pl05_exatt_table[18])(PLW* wk) = { Att_CHOUCHUURENGEKI, Att_HADOUKEN,       Att_HADOUKEN,
                                                Att_HADOUKEN,        Att_HADOUKEN,       Att_SENPUUKYAKU,
                                                Att_HADOUKEN,        Att_HADOUKEN,       Att_HADOUKEN,
                                                Att_JINNCHUUWATARI,  Att_SLIDE_and_JUMP, Att_DUMMY,
                                                Att_DUMMY,           Att_DUMMY,          Att_PL05_TOKUSHUKOUDOU,
                                                Att_DUMMY,           Att_METAMOR_WAIT,   Att_METAMOR_REBIRTH };

void pl05_extra_attack(PLW* wk) {
    pl05_exatt_table[wk->wu.routine_no[2] - 16](wk);
}

void Att_PL05_TOKUSHUKOUDOU(PLW* wk) {
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

        case 20:
            wk->wu.cg_type = 0;
            wk->tk_dageki += 10;

            if (wk->tk_dageki > 10) {
                wk->tk_dageki = 10;
            }

            break;

        case 64:
            grade_add_personal_action(wk->wu.id);
            break;
        }

        break;
    }
}
