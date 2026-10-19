/* Effect F0, retail sf33rd.xbe.
 * effect_F0_move is 0xBE103 size 0x97 and is interior.
 * effect_F0_init is 0xBE19A size 0x9C and is interior.
 * The pull failure is an early ret.
 * 0xBE0FE stays unnamed.
 *
 * 0xBE0FE is a five-byte jump to sort_push_request with
 * the caller's argument. The PlayStation 2 source has
 * no such function. effect_F0_move compares cg_number
 * unsigned against 0x1B59 and 0x1B5D, and shares the
 * push_effect_work call of the dead and routine paths.
 * The C keeps the PlayStation 2 order.
 * sort_push_request is 0x9DF9A.
 * push_effect_work is 0x4AC6C. pull_effect_work
 * stays pull_effect_work. get_my_trans_mode is named. frw
 * is 0xC806A0 and each object is 0x700 bytes.
 */

#include "types.h"
#include "structs.h"



typedef u8 EffectRow[0x700];

#if defined(__i386__)
_Static_assert(__builtin_offsetof(WORK, disp_flag) == 1, "disp_flag");
_Static_assert(__builtin_offsetof(WORK, work_id) == 6, "work_id");
_Static_assert(__builtin_offsetof(WORK, id) == 8, "id");
_Static_assert(__builtin_offsetof(WORK, rl_flag) == 0xA, "rl_flag");
_Static_assert(__builtin_offsetof(WORK, dead_f) == 0x20, "dead_f");
_Static_assert(__builtin_offsetof(WORK, routine_no) == 0x24, "routine_no");
_Static_assert(__builtin_offsetof(WORK, cgromtype) == 0x48, "cgromtype");
_Static_assert(__builtin_offsetof(WORK, position_x) == 0x54, "position_x");
_Static_assert(__builtin_offsetof(WORK, position_z) == 0x58, "position_z");
_Static_assert(__builtin_offsetof(WORK, dir_old) == 0x96, "dir_old");
_Static_assert(__builtin_offsetof(WORK, now_koc) == 0x206, "now_koc");
_Static_assert(__builtin_offsetof(WORK, cg_number) == 0x21A, "cg_number");
_Static_assert(__builtin_offsetof(WORK, my_col_code) == 0x23E, "my_col_code");
_Static_assert(__builtin_offsetof(WORK, my_family) == 0x242, "my_family");
_Static_assert(__builtin_offsetof(WORK, my_mts) == 0x24C, "my_mts");
_Static_assert(__builtin_offsetof(WORK, my_trans_mode) == 0x254, "my_trans_mode");
_Static_assert(sizeof(WORK) == 0x388, "WORK");
_Static_assert(__builtin_offsetof(WORK_Other, master_work_id) == 0x38C, "master_work_id");
_Static_assert(__builtin_offsetof(WORK_Other, master_id) == 0x38E, "master_id");
#endif

extern EffectRow frw[];

void sort_push_request(WORK *wk);
void push_effect_work(WORK *wk);
s16 pull_effect_work(s16 index);
s16 get_my_trans_mode(s16 curr);

void effect_F0_move(WORK_Other *ewk) {
    WORK *mwk = (WORK *)ewk->my_master;

    if (!ewk->wu.routine_no[0]) {
        if ((ewk->wu.dead_f == 1) || (ewk->wu.dir_old != mwk->now_koc)) {
            ewk->wu.disp_flag = 0;
            push_effect_work(&ewk->wu);
            return;
        }

        ewk->wu.disp_flag = ((mwk->cg_number >= 0x1B59) && (mwk->cg_number <= 0x1b5d)) ? 1 : 0;
        ewk->wu.cg_number = mwk->cg_number;
        ewk->wu.position_x = mwk->position_x;
        ewk->wu.position_y = mwk->position_y;
        ewk->wu.position_z = mwk->position_z - 1;
        ewk->wu.rl_flag = mwk->rl_flag;
        ewk->wu.my_col_code = mwk->my_col_code;
        sort_push_request(&ewk->wu);
        return;
    }

    push_effect_work(&ewk->wu);
}

s32 effect_F0_init(WORK *wk) {
    WORK_Other *ewk;
    s16 ix;

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }

    ewk = (WORK_Other *)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 150;
    ewk->wu.work_id = 16;
    ewk->wu.my_family = wk->my_family;
    ewk->my_master = (u32 *)wk;
    ewk->master_work_id = wk->work_id;
    ewk->master_id = wk->id;
    ewk->wu.cgromtype = wk->cgromtype;
    ewk->wu.my_mts = 14;
    ewk->wu.my_trans_mode = get_my_trans_mode(ewk->wu.my_mts);
    ewk->wu.disp_flag = 0;
    ewk->wu.dir_old = wk->now_koc;
    effect_F0_move(ewk);
    return 0;
}

/* Xbox-only functions of this object (analysis-ps2map/xbgen.py checked each). */
void xb_effect_F0_draw(WORK_Other* ewk) {
    sort_push_request(&ewk->wu);
}
