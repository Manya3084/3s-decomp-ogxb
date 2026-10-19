/* Effect L0, retail sf33rd.xbe.
 * effect_L0_move is 0x510B7 size 0x129.
 * effect_L0_init is 0x511E0 size 0x87.
 *
 * effect_L0_move drops the second dead_f test, because dead_f is already
 * known to be 0 there. dir_timer is read once for the > 0 and >= 30 tests
 * and read again for the < 10 test.
 * effect_L0_init stores my_master first. The C keeps the PS2 order.
 * Suicide is 0x7A8268. Game_pause is 0x7A89B0. EXE_flag is 0xC7C834.
 * frw is 0xC806A0, 0x700 bytes per object.
 * sa_stop_flag is +0x3F0. my_bright_type is +0x246. my_bright_level is
 * +0x248. now_koc is +0x206. kind_of_waza is +0x20F.
 * push_effect_work is 0x4AC6C. pull_effect_work is 0x4A6A8.
 */

#include "types.h"
#include "structs.h"




typedef u8 EffectRow[0x700];

#if defined(__i386__)
_Static_assert(__builtin_offsetof(WORK, id) == 8, "id");
_Static_assert(__builtin_offsetof(WORK, dead_f) == 0x20, "dead_f");
_Static_assert(__builtin_offsetof(WORK, routine_no) == 0x24, "routine_no");
_Static_assert(__builtin_offsetof(WORK, dir_timer) == 0x9A, "dir_timer");
_Static_assert(__builtin_offsetof(WORK, now_koc) == 0x206, "now_koc");
_Static_assert(__builtin_offsetof(WORK, char_index) == 0x208, "char_index");
_Static_assert(__builtin_offsetof(WORK, kind_of_waza) == 0x20F, "kind_of_waza");
_Static_assert(__builtin_offsetof(WORK, my_col_mode) == 0x23C, "my_col_mode");
_Static_assert(__builtin_offsetof(WORK, my_bright_type) == 0x246, "my_bright_type");
_Static_assert(__builtin_offsetof(WORK, my_clear_level) == 0x24A, "clear");
_Static_assert(sizeof(WORK) == 0x388, "WORK");
_Static_assert(__builtin_offsetof(WORK_Other, my_master) == 0x388, "my_master");
_Static_assert(__builtin_offsetof(PLW, sa_stop_flag) == 0x3F0, "sa_stop_flag");
#endif

extern s8 Suicide[8];
extern u8 Game_pause;
extern u16 EXE_flag;
extern EffectRow frw[];

void push_effect_work(WORK *wk);
s16 pull_effect_work(s16 index);

void effect_L0_move(WORK_Other *ewk) {
    PLW *mwk = (PLW *)ewk->my_master;

    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        mwk->wu.disp_flag = 0;
        /* fallthrough */

    case 1:
        if (ewk->wu.dead_f == 0 && Suicide[0] == 0) {
            if (Game_pause || EXE_flag) {
                break;
            }

            if (mwk->sa_stop_flag != 1) {
                ewk->wu.dir_timer--;
            }

            if (ewk->wu.dir_timer > 0 && mwk->wu.routine_no[1] != 1 && mwk->wu.routine_no[1] != 2 &&
                mwk->wu.routine_no[1] != 3 &&
                (mwk->wu.now_koc != 5 ||
                 (!(mwk->wu.kind_of_waza & 0x20) && mwk->wu.char_index != 0x40 && mwk->wu.char_index != 1))) {

                if (ewk->wu.dir_timer >= 30) {
                    break;
                }

                mwk->wu.my_bright_type = 1;

                if (ewk->wu.dir_timer < 10) {
                    mwk->wu.disp_flag = 1;
                    mwk->wu.my_bright_level = ewk->wu.dir_timer;
                } else {
                    mwk->wu.disp_flag = 2;
                    mwk->wu.my_bright_level = 13;
                    mwk->wu.my_col_mode = 0x4400;
                }

                break;
            }

            mwk->wu.disp_flag = 1;
            mwk->wu.my_bright_type = 0;
            mwk->wu.my_bright_level = 0;
            mwk->wu.my_clear_level = 0;
            mwk->wu.my_col_mode = 0x4200;
        }

        ewk->wu.routine_no[0]++;
        break;

    default:
    case 2:
        push_effect_work(&ewk->wu);
        break;
    }
}

s32 effect_L0_init(WORK *wk, s16 data) {
    WORK_Other *ewk;
    s16 ix;

    if ((ix = pull_effect_work(3)) == -1) {
        return -1;
    }

    ewk = (WORK_Other *)frw[ix];
    ewk->my_master = (u32 *)wk;
    ewk->wu.be_flag = 1;
    ewk->wu.id = 210;
    ewk->wu.dir_timer = data;
    ewk->wu.work_id = 16;
    ewk->wu.my_col_mode = wk->my_col_mode;
    ewk->wu.my_col_code = wk->my_col_code;
    ewk->wu.now_koc = wk->now_koc;
    ewk->wu.char_index = wk->char_index;
    effect_L0_move(ewk);
    return 0;
}
