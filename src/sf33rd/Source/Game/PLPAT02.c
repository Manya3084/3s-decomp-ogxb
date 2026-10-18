/* PLPAT02.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * pl02_extra_attack 0x8A03E size 0x12.
 * Att_DENJINHADOUKEN 0x8A050 size 0xA3.
 * Att_PL02_TOKUSHUKOUDOU 0x8A0F3 size 0xA3. Read against the x86: 0x6E and
 * 0x64 are recover * 110 / 100 as imul and idiv. The C is the PS2 C.
 * Data: lgix_table is 0x2629F0, 0x10 bytes compared.
 * Data: pl02_exatt_table is 0x262A00, 18 entries compared.
 * Globals: lgix_table 0x2629F0, pl02_exatt_table 0x262A00.
 */

#include "structs.h"

void Att_HADOUKEN(PLW* wk);
void Att_SHOURYUUKEN(PLW* wk);
void Att_SENPUUKYAKU(PLW* wk);
void Att_SHINSHOURYUUKEN(PLW* wk);
void Att_DENJINHADOUKEN(PLW* wk);
void Att_KUUCHUUNICHIRINSHOU(PLW* wk);
void Att_SLIDE_and_JUMP(PLW* wk);
void Att_DUMMY(PLW* );
void Att_PL02_TOKUSHUKOUDOU(PLW* wk);
void Att_METAMOR_WAIT(PLW* wk);
void Att_METAMOR_REBIRTH(PLW* wk);
void hoken_muriyari_chakuchi(PLW* wk);
void set_char_move_init(WORK* wk, s16 koc, s16 index);
void char_move(WORK* wk);
void add_sp_arts_gauge_tokushu(PLW* wk);
void grade_add_personal_action(s16 ix);

void (*const pl02_exatt_table[18])(PLW*);

const s16 lgix_table[8] = { 0, 1, 2, 3, 3, 4, 4, 5 };

void (*const pl02_exatt_table[18])(PLW*) = { Att_HADOUKEN,
                                             Att_SHOURYUUKEN,
                                             Att_SENPUUKYAKU,
                                             Att_HADOUKEN,
                                             Att_SHINSHOURYUUKEN,
                                             Att_DENJINHADOUKEN,
                                             Att_KUUCHUUNICHIRINSHOU,
                                             Att_SLIDE_and_JUMP,
                                             Att_DUMMY,
                                             Att_DUMMY,
                                             Att_DUMMY,
                                             Att_DUMMY,
                                             Att_DUMMY,
                                             Att_DUMMY,
                                             Att_PL02_TOKUSHUKOUDOU,
                                             Att_DUMMY,
                                             Att_METAMOR_WAIT,
                                             Att_METAMOR_REBIRTH };

void pl02_extra_attack(PLW* wk) {
    pl02_exatt_table[wk->wu.routine_no[2] - 16](wk);
}

void Att_DENJINHADOUKEN(PLW* wk) {
    s16 i;
    s16 lgix;

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

        if (wk->wu.now_koc == 8 && wk->wu.char_index == 13) {
            if (wk->cp->lgp > 13) {
                lgix = 5;
            } else {
                lgix = lgix_table[wk->cp->lgp / 2];
            }

            if (lgix) {
                for (i = 0; i < lgix; i++) {
                    char_move(&wk->wu);
                }
            }
        }

        break;
    }
}

void Att_PL02_TOKUSHUKOUDOU(PLW* wk) {
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

            if (wk->tk_success < 3) {
                wk->tk_success++;
                wk->py->recover = (wk->py->recover * 110) / 100;
                grade_add_personal_action(wk->wu.id);
            }
        }

        break;

    default:
        char_move(&wk->wu);
        break;
    }
}
