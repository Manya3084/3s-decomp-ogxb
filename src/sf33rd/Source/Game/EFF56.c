/* Effect 56, retail sf33rd.xbe.
 * effect_56_move is 0x3DB95 size 0xF2.
 * effect_56_init is 0x3DC87 size 0x40.
 *
 * Case 0 of the move does not read the first two table bytes at run time.
 * It stores ci_col and ci_timer as constants (0x14, 0x0C for the bonus table;
 * 0x15, 0x02 otherwise) and points ci_pointer two bytes into the table. The C
 * keeps the PlayStation 2 reads. Case 2 is tested first in the x86.
 * The init stores type first and charset_id last.
 * ci_pointer is 0xCB87DC. ci_col is 0xCB87E0. ci_timer is 0xCB87E1.
 * ci_color_tbl is 0x24EFE8 and bonus_ci_color_tbl is 0x24F004. Both match
 * the PS2 bytes. Message_Suicide is 0x7A87F8. Bonus_Game_Flag is 0x7A8272.
 * bg_w.stage is 0x7BC523. charset_id is +5.
 * ci_set is 0xE8547. nw_set is 0xE85B1. push_effect_work is 0x4AC6C.
 * pull_effect_work is 0x4A6A8. frw is 0xC806A0, 0x700 bytes per object.
 */

#include "types.h"
#include "structs.h"




typedef u8 EffectRow[0x700];

#if defined(__i386__)
_Static_assert(__builtin_offsetof(WORK, type) == 4, "type");
_Static_assert(__builtin_offsetof(WORK, charset_id) == 5, "charset_id");
_Static_assert(__builtin_offsetof(WORK, routine_no) == 0x24, "routine_no");
_Static_assert(sizeof(WORK) == 0x388, "WORK");
#endif

const u8 *ci_pointer;
u8 ci_col;
u8 ci_timer;

const u8 ci_color_tbl[26] = { 21, 2,  22, 2,  21, 2,  20, 2,  21, 2,  22, 2,  21,
                              2,  20, 2,  21, 2,  22, 2,  21, 2,  20, 2,  20, 255 };
const u8 bonus_ci_color_tbl[6] = { 20, 12, 20, 12, 20, 255 };

extern s16 Bonus_Game_Flag;
extern u8 Message_Suicide[4];
extern BG bg_w;
extern EffectRow frw[];

void ci_set(u8 type, u8 col);
void nw_set(u8 type, u8 col);
void push_effect_work(WORK *wk);
s16 pull_effect_work(s16 index);

void effect_56_move(WORK_Other *ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        if (Bonus_Game_Flag && bg_w.stage == 20) {
            ci_pointer = bonus_ci_color_tbl;
            ci_col = *ci_pointer++;
            ci_timer = *ci_pointer++;
        } else {
            ci_pointer = ci_color_tbl;
            ci_col = *ci_pointer++;
            ci_timer = *ci_pointer++;
        }

        /* fallthrough */

    case 1:
        if (ewk->wu.type < 7) {
            ci_set(ewk->wu.type, ci_col);
        } else {
            nw_set(ewk->wu.type - 7, ci_col);
        }

        break;

    default:
    case 2:
        if (Message_Suicide[ewk->wu.charset_id]) {
            push_effect_work(&ewk->wu);
            return;
        }

        if (ewk->wu.type < 7) {
            ci_set(ewk->wu.type, 20);
        } else {
            nw_set(ewk->wu.type - 7, 20);
        }

        return;
    }

    if (ci_timer > 1) {
        ci_timer--;
        return;
    }

    ci_col = *ci_pointer++;
    ci_timer = *ci_pointer++;

    if (ci_timer == 0xFF) {
        ewk->wu.routine_no[0]++;
    }
}

s32 effect_56_init(u8 type, u8 kill) {
    WORK_Other *ewk;
    s16 ix;

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }

    ewk = (WORK_Other *)frw[ix];
    ewk->wu.type = type;
    ewk->wu.be_flag = 1;
    ewk->wu.id = 56;
    ewk->wu.work_id = 16;
    ewk->wu.charset_id = kill;
    return 0;
}

/* Xbox-only functions of this object (analysis-ps2map/xbgen.py checked each). */
void xb_effect_56_draw(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 1:
        if (ewk->wu.type < 7) {
            ci_set(ewk->wu.type, ci_col);
        } else {
            nw_set(ewk->wu.type - 7, ci_col);
        }

        break;

    default:
        if (Message_Suicide[ewk->wu.charset_id]) {
            push_effect_work(&ewk->wu);
            return;
        }

        if (ewk->wu.type < 7) {
            ci_set(ewk->wu.type, 20);
        } else {
            nw_set(ewk->wu.type - 7, 20);
        }

        break;
    }
}
