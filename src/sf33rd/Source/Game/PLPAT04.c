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
 * set_char_move_init is 0x200A9. char_move is 0x2008E.
 * grade_add_personal_action is 0x5DBA6.
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
void set_char_move_init(WORK *wk, s16 koc, s32 index);
void char_move(WORK *wk);
void grade_add_personal_action(s32 ix);

void Att_SENPUUKYAKU(PLW*);
void Att_HADOUKEN(PLW*);
void Att_SHOURYUUREPPA(PLW*);
void Att_HADOUKEN2(PLW*);
void Att_CHOUCHUURENGEKI(PLW*);
void Att_SLIDE_and_JUMP(PLW*);
void Att_NM_OKIAGARI(PLW*);
void Att_DUMMY(PLW*);
void Att_HOMING_JUMP(PLW*);
void Att_PL04_TOKUSHUKOUDOU(PLW*);
void Att_METAMOR_WAIT(PLW*);
void Att_METAMOR_REBIRTH(PLW*);
/* Pasted from the PS2 file. */
void (*const pl04_exatt_table[18])(PLW*) = { Att_SENPUUKYAKU,     Att_SENPUUKYAKU,    Att_HADOUKEN,
                                             Att_SHOURYUUREPPA,   Att_HADOUKEN2,      Att_CHOUCHUURENGEKI,
                                             Att_CHOUCHUURENGEKI, Att_SLIDE_and_JUMP, Att_SLIDE_and_JUMP,
                                             Att_HADOUKEN,        Att_NM_OKIAGARI,    Att_DUMMY,
                                             Att_HOMING_JUMP,     Att_DUMMY,          Att_PL04_TOKUSHUKOUDOU,
                                             Att_DUMMY,           Att_METAMOR_WAIT,   Att_METAMOR_REBIRTH };

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
            wk->tk_dageki += 8;
            break;

        case 64:
            grade_add_personal_action(wk->wu.id);
            break;
        }

        if (wk->tk_dageki > 8) {
            wk->tk_dageki = 8;
        }

        break;
    }
}
