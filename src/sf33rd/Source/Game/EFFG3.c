/* Effect G3, retail sf33rd.xbe.
 * effect_G3_move is 0x4B4BF size 0xFA.
 * effect_G3_init is 0x4B5B9 size 0x8C.
 *
 * effect_G3_move shares one exit for its three "routine_no[0] = 3,
 * disp_flag = 0" paths. When mwk->dir_timer runs out, routine_no[1] is
 * stored as 1, not incremented, because it is known to be 0 there.
 * The +80/-80 adjust is chosen with push/pop of the constant.
 * _effD4_char_table is 0x308AA0. Suicide[6] is 0x7A826E.
 * Game_pause is 0x7A89B0. EXE_flag is 0xC7C834.
 * frw is 0xC806A0, 0x700 bytes per object. target_adrs is +0xC.
 * set_char_move_init stays sub_000200A9. char_move stays sub_0002008E.
 * push_effect_work is 0x4AC6C. pull_effect_work is 0x4A6A8.
 * sort_push_request is 0x9DF9A.
 */

#include "types.h"

typedef struct {
    s8 be_flag;
    s8 disp_flag;
    u8 pad_type[2];
    u8 type;
    u8 pad_work[1];
    s16 work_id;
    s16 id;
    s8 rl_flag;
    u8 pad_ta[1];
    u32 *target_adrs;
    u8 pad_dead[0x20 - 0x10];
    s16 dead_f;
    u8 pad_rno[2];
    s16 routine_no[8];
    u8 pad_cgr[0x48 - 0x34];
    s8 cgromtype;
    u8 pad_pos[0x54 - 0x49];
    s16 position_x;
    s16 position_y;
    s16 position_z;
    u8 pad_dir[0x9A - 0x5A];
    s16 dir_timer;
    u8 pad_ct[0x1AC - 0x9C];
    u32 *char_table[1];
    u8 pad_cg[0x214 - 0x1B0];
    u8 cg_type;
    u8 pad_col[0x23C - 0x215];
    s16 my_col_mode;
    s16 my_col_code;
    u8 pad_fam[2];
    s16 my_family;
    u8 pad_mts[0x24C - 0x244];
    s16 my_mts;
    u8 pad_end[0x388 - 0x24E];
} WORK;

typedef struct {
    WORK wu;
    u32 *my_master;
    s16 master_work_id;
    s16 master_id;
} WORK_Other;

typedef struct {
    WORK wu;
} PLW;

typedef u8 EffectRow[0x700];

#if defined(__i386__)
_Static_assert(__builtin_offsetof(WORK, type) == 4, "type");
_Static_assert(__builtin_offsetof(WORK, rl_flag) == 0xA, "rl_flag");
_Static_assert(__builtin_offsetof(WORK, target_adrs) == 0xC, "target_adrs");
_Static_assert(__builtin_offsetof(WORK, dead_f) == 0x20, "dead_f");
_Static_assert(__builtin_offsetof(WORK, routine_no) == 0x24, "routine_no");
_Static_assert(__builtin_offsetof(WORK, cgromtype) == 0x48, "cgromtype");
_Static_assert(__builtin_offsetof(WORK, position_x) == 0x54, "position_x");
_Static_assert(__builtin_offsetof(WORK, dir_timer) == 0x9A, "dir_timer");
_Static_assert(__builtin_offsetof(WORK, char_table) == 0x1AC, "char_table");
_Static_assert(__builtin_offsetof(WORK, cg_type) == 0x214, "cg_type");
_Static_assert(__builtin_offsetof(WORK, my_col_mode) == 0x23C, "my_col_mode");
_Static_assert(__builtin_offsetof(WORK, my_family) == 0x242, "my_family");
_Static_assert(__builtin_offsetof(WORK, my_mts) == 0x24C, "my_mts");
_Static_assert(sizeof(WORK) == 0x388, "WORK");
_Static_assert(__builtin_offsetof(WORK_Other, master_work_id) == 0x38C, "master_work_id");
_Static_assert(__builtin_offsetof(WORK_Other, master_id) == 0x38E, "master_id");
#endif

extern u32 _effD4_char_table[];
extern s8 Suicide[8];
extern u8 Game_pause;
extern u16 EXE_flag;
extern EffectRow frw[];

void push_effect_work(WORK *wk);
s16 pull_effect_work(s16 index);
void sort_push_request(WORK *wk);
void sub_000200A9(WORK *wk, s16 koc, s32 index);
void sub_0002008E(WORK *wk);

void effect_G3_move(WORK_Other *ewk) {
    WORK_Other *mwk;
    PLW *pwk = (PLW *)ewk->wu.target_adrs;
    s16 adjust;

    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.routine_no[1] = 0;
        ewk->wu.disp_flag = 1;
        ewk->wu.my_col_mode = 0x4200;
        ewk->wu.my_col_code = 0x2020;
        ewk->wu.position_y = pwk->wu.position_y - 8;
        ewk->wu.position_z = pwk->wu.position_z - 4;
        sub_000200A9(&ewk->wu, 0, 0);
        /* fallthrough */

    case 1:
        if (ewk->wu.dead_f || Suicide[6] != 0) {
            ewk->wu.routine_no[0] = 3;
            ewk->wu.disp_flag = 0;
            break;
        }

        if (!ewk->wu.routine_no[1]) {
            mwk = (WORK_Other *)ewk->my_master;

            if (mwk->wu.dead_f) {
                ewk->wu.routine_no[0] = 3;
                ewk->wu.disp_flag = 0;
                break;
            }

            if (mwk->wu.dir_timer <= 0) {
                ewk->wu.routine_no[1]++;
                sub_000200A9(&ewk->wu, 0, 1);
            }
        } else if (ewk->wu.cg_type == 0xFF) {
            ewk->wu.routine_no[0] = 3;
            ewk->wu.disp_flag = 0;
            break;
        }

        if (EXE_flag == 0 && Game_pause == 0) {
            if (!ewk->wu.routine_no[1]) {
                adjust = 80;

                if (ewk->wu.rl_flag) {
                    adjust = -adjust;
                }

                ewk->wu.position_x = pwk->wu.position_x + adjust;
            }

            sub_0002008E(&ewk->wu);
        }

        sort_push_request(&ewk->wu);
        break;

    default:
    case 2:
    case 3:
        push_effect_work(&ewk->wu);
        break;
    }
}

s32 effect_G3_init(WORK *wk, u8 data) {
    WORK_Other *ewk;
    WORK_Other *ewk2;
    s16 ix;

    if ((ix = pull_effect_work(3)) == -1) {
        return -1;
    }

    ewk = (WORK_Other *)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.type = data;
    ewk->wu.id = 163;
    ewk->wu.work_id = 16;
    ewk->wu.my_mts = 14;
    ewk->wu.my_family = wk->my_family;
    ewk->wu.cgromtype = 1;
    ewk->my_master = (u32 *)wk;
    ewk->master_work_id = wk->work_id;
    ewk->master_id = wk->id;
    ewk2 = (WORK_Other *)wk;
    ewk->wu.target_adrs = ewk2->my_master;
    ewk->wu.rl_flag = data;
    *ewk->wu.char_table = _effD4_char_table;
    return 0;
}
