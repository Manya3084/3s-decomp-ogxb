/* PLPAT08.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * pl08_extra_attack 0x8AAF2 size 0x12.
 * Att_PL08_HEALING 0x8AB04 size 0xE9. Read against the x86: (sw_now & 0x770)
 * >> 4 is computed as (sw_now >> 4) & 0x77, the same value.
 * Att_PL08_TOKUSHUKOUDOU is folded into 0xE5266 with 1 other bodies. Unnamed.
 * Data: pl08_hcs_tbl is 0x262BB0, 0x8 bytes compared.
 * Data: pl08_exatt_table is 0x262BB8, 18 entries compared.
 * Globals: pl08_hcs_tbl 0x262BB0, pl08_exatt_table 0x262BB8, pcon_dp_flag
 * 0xC7D8D0.
 */

#include "structs.h"

void Att_SHOURYUUKEN(PLW* wk);
void Att_SENPUUKYAKU(PLW* wk);
void Att_SHOURYUUREPPA(PLW* wk);
void Att_PL08_HEALING(PLW* wk);
void Att_DUMMY(PLW* );
void Att_SLIDE_and_JUMP(PLW* wk);
void Att_HADOUKEN(PLW* wk);
void Att_PL08_TOKUSHUKOUDOU(PLW* wk);
void Att_METAMOR_WAIT(PLW* wk);
void Att_METAMOR_REBIRTH(PLW* wk);
void hoken_muriyari_chakuchi(PLW* wk);
void set_char_move_init(WORK* wk, s16 koc, s16 index);
void char_move(WORK* wk);
void char_move_cmms(WORK* wk);
extern u8 pcon_dp_flag;
void add_sp_arts_gauge_tokushu(PLW* wk);
void grade_add_personal_action(s16 ix);

const u8 pl08_hcs_tbl[8] = { 0, 0, 0, 1, 0, 1, 1, 1 };

void (*const pl08_exatt_table[18])(PLW*);

void (*const pl08_exatt_table[18])(PLW*) = { Att_SHOURYUUKEN,   Att_SENPUUKYAKU,    Att_SENPUUKYAKU,
                                             Att_SHOURYUUREPPA, Att_SHOURYUUREPPA,  Att_PL08_HEALING,
                                             Att_DUMMY,         Att_SLIDE_and_JUMP, Att_HADOUKEN,
                                             Att_DUMMY,         Att_DUMMY,          Att_DUMMY,
                                             Att_DUMMY,         Att_DUMMY,          Att_PL08_TOKUSHUKOUDOU,
                                             Att_DUMMY,         Att_METAMOR_WAIT,   Att_METAMOR_REBIRTH };

void pl08_extra_attack(PLW* wk) {
    pl08_exatt_table[wk->wu.routine_no[2] - 16](wk);
}

void Att_PL08_HEALING(PLW* wk) {
    u16 cpsw;

    wk->scr_pos_set_flag = 0;

    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        hoken_muriyari_chakuchi(wk);
        set_char_move_init(&wk->wu, 5, wk->as->char_ix);
        break;

    case 1:
        char_move(&wk->wu);

        if (wk->wu.cmwk[0]) {
            cpsw = (wk->cp->sw_now & 0x770);
            cpsw >>= 4;

            if (pl08_hcs_tbl[cpsw & 7] || pl08_hcs_tbl[(cpsw >> 4) & 7]) {
                wk->wu.cmwk[0] = 0;
                char_move_cmms(&wk->wu);
            }
        }

        if (pcon_dp_flag == 0) {
            switch (wk->wu.cg_type) {
            case 24:
                wk->wu.vital_new += 3;
                break;

            case 22:
                wk->wu.vital_new += 2;
                break;

            case 20:
                wk->wu.vital_new += 1;
                break;
            }
        }

        if (wk->wu.vital_new > wk->wu.vitality) {
            wk->wu.vital_new = wk->wu.vitality;
            wk->sa_healing = 1;
        }

        break;
    }
}

void Att_PL08_TOKUSHUKOUDOU(PLW* wk) {
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
            wk->tk_kizetsu += 6;

            if (wk->tk_kizetsu > 24) {
                wk->tk_kizetsu = 24;
            }

            grade_add_personal_action(wk->wu.id);
        }

        break;

    default:
        char_move(&wk->wu);
        break;
    }
}
