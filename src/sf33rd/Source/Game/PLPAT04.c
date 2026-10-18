/* Player 04 special move, retail sf33rd.xbe.
 * pl04_extra_attack is 0x8A27D size 0x12.
 * Att_PL04_TOKUSHUKOUDOU is 0x8A28F size 0x9B.
 *
 * The x86 tests cg_type 20 first, then 40, then 64. The C keeps the
 * PlayStation 2 case order.
 * pl04_exatt_table is 0x262A50. routine_no[2] is +0x28 and routine_no[3]
 * +0x2A. scr_pos_set_flag is +0x3B0. as is +0x3C0, char_ix at +2.
 * tk_dageki is +0x40E. cg_type is +0x214.
 * hoken_muriyari_chakuchi is 0x89050. add_sp_arts_gauge_tokushu is 0x93E9F.
 * set_char_move_init stays sub_000200A9. char_move stays sub_0002008E.
 * grade_add_personal_action stays sub_0005DBA6.
 */

#include "types.h"

typedef struct {
    s8 be_flag;
    s8 disp_flag;
    u8 pad_type[6];
    s16 id;
    s8 rl_flag;
    s8 rl_waza;
    u8 pad_rno[0x24 - 0xC];
    s16 routine_no[8];
    u8 pad_cg[0x214 - 0x34];
    u8 cg_type;
    u8 pad_end[0x388 - 0x215];
} WORK;

typedef struct {
    u8 pad[2];
    s16 char_ix;
} ATTACK_SET;

typedef struct {
    WORK wu;
    u8 pad_scr[0x3B0 - 0x388];
    s8 scr_pos_set_flag;
    u8 pad_as[0x3C0 - 0x3B1];
    ATTACK_SET *as;
    u8 pad_tk[0x40E - 0x3C4];
    s16 tk_dageki;
    s16 tk_nage;
} PLW;

#if defined(__i386__)
_Static_assert(__builtin_offsetof(WORK, rl_flag) == 0xA, "rl_flag");
_Static_assert(__builtin_offsetof(WORK, rl_waza) == 0xB, "rl_waza");
_Static_assert(__builtin_offsetof(WORK, routine_no) == 0x24, "routine_no");
_Static_assert(__builtin_offsetof(WORK, cg_type) == 0x214, "cg_type");
_Static_assert(sizeof(WORK) == 0x388, "WORK");
_Static_assert(__builtin_offsetof(PLW, scr_pos_set_flag) == 0x3B0, "scr_pos_set_flag");
_Static_assert(__builtin_offsetof(PLW, as) == 0x3C0, "as");
_Static_assert(__builtin_offsetof(PLW, tk_dageki) == 0x40E, "tk_dageki");
_Static_assert(__builtin_offsetof(PLW, tk_nage) == 0x410, "tk_nage");
#endif

void hoken_muriyari_chakuchi(PLW *wk);
void add_sp_arts_gauge_tokushu(PLW *wk);
void sub_000200A9(WORK *wk, s16 koc, s32 index);
void sub_0002008E(WORK *wk);
void sub_0005DBA6(s32 ix);

extern void (*const pl04_exatt_table[])(PLW *wk);

void pl04_extra_attack(PLW *wk) {
    pl04_exatt_table[wk->wu.routine_no[2] - 16](wk);
}

void Att_PL04_TOKUSHUKOUDOU(PLW *wk) {
    wk->scr_pos_set_flag = 0;

    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = wk->wu.rl_waza;
        hoken_muriyari_chakuchi(wk);
        sub_000200A9(&wk->wu, 5, wk->as->char_ix);
        break;

    case 1:
        sub_0002008E(&wk->wu);

        switch (wk->wu.cg_type) {
        case 40:
            wk->wu.cg_type = 0;
            add_sp_arts_gauge_tokushu(wk);
            break;

        case 20:
            wk->wu.cg_type = 0;
            wk->tk_dageki += 8;
            break;

        case 64:
            sub_0005DBA6(wk->wu.id);
            break;
        }

        if (wk->tk_dageki > 8) {
            wk->tk_dageki = 8;
        }

        break;
    }
}
