/* Player 16 (Q) special attacks, retail sf33rd.xbe.
 * pl16_extra_attack is 0xE3CCD size 0x12.
 * Att_PL16_TOKUSHUKOUDOU is 0xE3CDF size 0xEB.
 *
 * pl16_extra_attack calls through [routine_no[2] * 4 + 0x2AE4A8]. The
 * - 16 is folded into the base, so pl16_exatt_table is 0x2AE4E8. Its 18
 * entries were checked against the XBE. Att_SLIDE_and_JUMP is folded into
 * 0x8C24E and stays sub_0008C24E. Att_DUMMY is folded into 0x4384A and
 * stays sub_0004384A.
 * Att_PL16_TOKUSHUKOUDOU pushes wk once, before the switch. The pushed
 * value is the argument for both char_move calls and hoken_muriyari_chakuchi.
 * The case 64 tk_success test is unsigned: tk_success is a byte.
 * scr_pos_set_flag is +0x3B0. as is +0x3C0, char_ix at +2. py is +0x3CC,
 * recover at +0xC. tk_success is +0x40C. tk_dageki is +0x40E.
 * tk_konjyou is +0x414. cg_type is +0x214.
 * set_char_move_init is 0x200A9. char_move is 0x2008E.
 * grade_add_personal_action is 0x5DBA6.
 * hoken_muriyari_chakuchi is 0x89050. add_sp_arts_gauge_tokushu is 0x93E9F.
 */

#include "types.h"
#include "structs.h"


typedef struct {
    u8 pad0[0xC];
    s32 recover;
} PLY;



#if defined(__i386__)
_Static_assert(__builtin_offsetof(WORK, id) == 8, "id");
_Static_assert(__builtin_offsetof(WORK, rl_flag) == 0xA, "rl_flag");
_Static_assert(__builtin_offsetof(WORK, rl_waza) == 0xB, "rl_waza");
_Static_assert(__builtin_offsetof(WORK, routine_no) == 0x24, "routine_no");
_Static_assert(__builtin_offsetof(WORK, cg_type) == 0x214, "cg_type");
_Static_assert(sizeof(WORK) == 0x388, "WORK");
_Static_assert(__builtin_offsetof(PLW, scr_pos_set_flag) == 0x3B0, "scr_pos_set_flag");
_Static_assert(__builtin_offsetof(PLW, as) == 0x3C0, "as");
_Static_assert(__builtin_offsetof(PLW, py) == 0x3CC, "py");
_Static_assert(__builtin_offsetof(PLW, tk_success) == 0x40C, "tk_success");
_Static_assert(__builtin_offsetof(PLW, tk_dageki) == 0x40E, "tk_dageki");
_Static_assert(__builtin_offsetof(PLW, tk_konjyou) == 0x414, "tk_konjyou");
#endif

void Att_SENPUUKYAKU(PLW *wk);
void Att_HADOUKEN2(PLW *wk);
void Att_HADOUKEN(PLW *wk);
void sub_0008C24E(PLW *wk);
void sub_0004384A(PLW *wk);
void Att_PL16_TOKUSHUKOUDOU(PLW *wk);
void Att_METAMOR_WAIT(PLW *wk);
void Att_METAMOR_REBIRTH(PLW *wk);
void hoken_muriyari_chakuchi(PLW *wk);
void add_sp_arts_gauge_tokushu(PLW *wk);
void set_char_move_init(WORK *wk, s16 koc, s32 index);
void char_move(WORK *wk);
void grade_add_personal_action(s32 ix);

void (*const pl16_exatt_table[18])(PLW *) = {
    Att_SENPUUKYAKU, Att_HADOUKEN2, Att_HADOUKEN, Att_HADOUKEN,
    sub_0008C24E,    sub_0008C24E,  sub_0008C24E, sub_0004384A,
    sub_0004384A,    sub_0004384A,  sub_0004384A, sub_0004384A,
    sub_0004384A,    sub_0004384A,  Att_PL16_TOKUSHUKOUDOU, sub_0004384A,
    Att_METAMOR_WAIT, Att_METAMOR_REBIRTH,
};

void pl16_extra_attack(PLW *wk) {
    pl16_exatt_table[wk->wu.routine_no[2] - 16](wk);
}

void Att_PL16_TOKUSHUKOUDOU(PLW *wk) {
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
        case 30:
            wk->wu.cg_type = 0;

            if (wk->tk_konjyou == 0) {
                wk->tk_konjyou = 6;
            }

            break;

        case 40:
            wk->wu.cg_type = 0;
            add_sp_arts_gauge_tokushu(wk);
            break;

        case 50:
            wk->wu.cg_type = 0;

            if (wk->tk_dageki <= 9) {
                wk->tk_dageki = 10;
            }

            break;

        case 64:
            grade_add_personal_action(wk->wu.id);
            wk->wu.routine_no[3]++;

            if (wk->tk_success <= 2) {
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
