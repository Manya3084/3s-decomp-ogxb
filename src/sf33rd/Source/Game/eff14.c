/* Bonus digits, retail sf33rd.xbe.
 * effect_14_move is 0xB6EC9 size 0xD8 and is interior.
 * effect_14_init is 0xB6FA1 size 0x65 and is interior.
 *
 * Suicide[5] is 0x7A826D. PB_Status is 0x7A8932.
 * Rewrite_Color_Data_08 is the effect 8 table at 0x2841C8.
 * The index is type. Disp_Score_Buff is 0x7A8738.
 * Disp_Bonus_Contents is 0xC7E550.
 * The sign-bit tail jump is written as a call.
 * Disp_Digit16x24 receives the full position words.
 * pull_effect_work is 0x4A6A8. push_effect_work stays
 * push_effect_work. frw is 0xC806A0 and each object is 0x700 bytes.
 */

#include "types.h"
#include "structs.h"



typedef u8 EffectRow[0x700];

#if defined(__i386__)
_Static_assert(__builtin_offsetof(WORK, type) == 4, "type");
_Static_assert(__builtin_offsetof(WORK, work_id) == 6, "work_id");
_Static_assert(__builtin_offsetof(WORK, id) == 8, "id");
_Static_assert(__builtin_offsetof(WORK, routine_no) == 0x24, "routine_no");
_Static_assert(__builtin_offsetof(WORK, position_x) == 0x54, "position_x");
_Static_assert(__builtin_offsetof(WORK, position_y) == 0x56, "position_y");
_Static_assert(__builtin_offsetof(WORK, dir_step) == 0x98, "dir_step");
_Static_assert(__builtin_offsetof(WORK, dir_timer) == 0x9A, "dir_timer");
_Static_assert(__builtin_offsetof(WORK, my_col_code) == 0x23E, "my_col_code");
_Static_assert(sizeof(WORK) == 0x388, "WORK");
#endif

extern s8 Suicide[8];
extern u8 PB_Status;
extern const u8 Rewrite_Color_Data_08[2][13][2];
extern u32 Disp_Score_Buff[2];
extern u8 Disp_Bonus_Contents;
extern EffectRow frw[];

void push_effect_work(WORK *wk);
s16 pull_effect_work(s16 index);
void Disp_Digit16x24(u32 Score_Buff, s16 Disp_X, s16 Disp_Y, s16 Color);
void effect_14_move(WORK_Other *ewk);

void effect_14_move(WORK_Other *ewk) {
    if ((Suicide[5] & 0x80) != 0) {
        push_effect_work(&ewk->wu);
        return;
    }

    switch (ewk->wu.routine_no[0]) {
    case 0:
        if ((Suicide[5] & 1) != 0) {
            if ((PB_Status & 3) != 0) {
                ewk->wu.routine_no[0]++;
                ewk->wu.dir_timer = 1;
                ewk->wu.dir_step = 0;
            } else {
                ewk->wu.routine_no[0] = 99;
            }
        }

        break;

    case 1:
        if (--ewk->wu.dir_timer == 0) {
            ewk->wu.my_col_code = Rewrite_Color_Data_08[ewk->wu.type][ewk->wu.dir_step][0] + 0;
            ewk->wu.dir_timer = Rewrite_Color_Data_08[ewk->wu.type][ewk->wu.dir_step][1];

            if (ewk->wu.dir_timer == 0xFF) {
                ewk->wu.routine_no[0] = 99;
            } else {
                ewk->wu.dir_step++;
            }
        }

        break;
    }

    Disp_Digit16x24(Disp_Score_Buff[ewk->wu.type], ewk->wu.position_x, ewk->wu.position_y, ewk->wu.my_col_code);
}

s32 effect_14_init(s16 id, s16 x, s16 y, s16 atr) {
    WORK_Other *ewk;
    s16 ix;

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }

    ewk = (WORK_Other *)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 14;
    ewk->wu.work_id = 16;
    ewk->wu.type = id;
    ewk->wu.position_x = x;
    ewk->wu.position_y = y;
    ewk->wu.my_col_code = atr;
    Disp_Bonus_Contents = 0;
    effect_14_move(ewk);
    return 0;
}
