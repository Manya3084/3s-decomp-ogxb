/* Effect J6, retail sf33rd.xbe.
 * effect_j6_hit_sub is 0xB8B3E size 0x24 and is interior.
 * effect_J6_init is 0xB8B62 size 0xB6 and is interior.
 * effect_J6_move is 0xB8C18 size 0xBB and is interior.
 * The pull failure is an early ret.
 * 0xB8B17 stays unnamed. 0xB8CD3 stays unnamed.
 *
 * The init stores dead_f before my_master. It stores
 * routine_no[1] before my_trans_mode. Case 3 stores
 * routine_no[0] between the pushes and the call. The C
 * keeps the PlayStation 2 order. eff_hit_flag is
 * 0x7A99C0. EXE_obroll is 0x7A8111. EXE_flag is
 * 0xC7C834. Game_pause is 0x7A89B0. The character
 * table immediate is 0x2F33C0. Those bytes were not
 * compared. effect_27_init is 0x39E54.
 * obr_no_disp_check and disp_pos_trans_entry_r are
 * named. eff_hit_check is named. get_my_trans_mode
 * is named. set_char_move_init is 0x200A9.
 * all_cgps_put_back stays sub_0004384A.
 * push_effect_work is 0x4AC6C.
 * pull_effect_work is 0x4A6A8.
 * frw is 0xC806A0 and each object is 0x700 bytes.
 * 0xB6890 stays unnamed. 0xB61A0 is push_color_trans_req.
 * 0xB7EC3 stays unnamed. 0xB82C0 stays unnamed.
 * 0xB888D stays unnamed.
 */

#include "types.h"
#include "structs.h"

/* Retail addresses the code used as numbers. */
extern u32 _chn_char_table[];




typedef uintptr_t EffectRow[448]; /* 0x700 bytes on the 32-bit retail build */

#if defined(__i386__)
_Static_assert(__builtin_offsetof(WORK, disp_flag) == 1, "disp_flag");
_Static_assert(__builtin_offsetof(WORK, type) == 4, "type");
_Static_assert(__builtin_offsetof(WORK, work_id) == 6, "work_id");
_Static_assert(__builtin_offsetof(WORK, id) == 8, "id");
_Static_assert(__builtin_offsetof(WORK, rl_flag) == 0xA, "rl_flag");
_Static_assert(__builtin_offsetof(WORK, dead_f) == 0x20, "dead_f");
_Static_assert(__builtin_offsetof(WORK, routine_no) == 0x24, "routine_no");
_Static_assert(__builtin_offsetof(WORK, routine_no[1]) == 0x26, "rno1");
_Static_assert(__builtin_offsetof(WORK, cgromtype) == 0x48, "cgromtype");
_Static_assert(__builtin_offsetof(WORK, position_z) == 0x58, "position_z");
_Static_assert(__builtin_offsetof(WORK, xyz[0].disp.pos) == 0x66, "xyz0");
_Static_assert(__builtin_offsetof(WORK, xyz[1].disp.pos) == 0x6A, "xyz1");
_Static_assert(__builtin_offsetof(WORK, char_table) == 0x1AC, "char_table");
_Static_assert(__builtin_offsetof(WORK, char_index) == 0x208, "char_index");
_Static_assert(__builtin_offsetof(WORK, my_col_mode) == 0x23C, "my_col_mode");
_Static_assert(__builtin_offsetof(WORK, my_col_code) == 0x23E, "my_col_code");
_Static_assert(__builtin_offsetof(WORK, my_priority) == 0x240, "my_priority");
_Static_assert(__builtin_offsetof(WORK, my_family) == 0x242, "my_family");
_Static_assert(__builtin_offsetof(WORK, my_mts) == 0x24C, "my_mts");
_Static_assert(__builtin_offsetof(WORK, my_trans_mode) == 0x254, "my_trans_mode");
_Static_assert(sizeof(WORK) == 0x388, "WORK");
_Static_assert(__builtin_offsetof(WORK_Other, my_master) == 0x388, "my_master");
#endif

extern EffectRow frw[];
extern s16 eff_hit_flag[11];
extern s16 EXE_flag;
extern u8 Game_pause;
extern s8 EXE_obroll;

s32 obr_no_disp_check(void);
void disp_pos_trans_entry_r(WORK_Other *ewk);
s16 eff_hit_check(WORK_Other *ewk, s16 type);
void set_char_move_init(WORK *wk, s16 koc, s16 index);
void sub_0004384A(WORK *wk);
void push_effect_work(WORK *wk);
s16 pull_effect_work(s16 index);
s16 get_my_trans_mode(s16 curr);
s32 effect_27_init(WORK_Other *ewk, s16 type);

void effect_j6_hit_sub(WORK_Other *ewk);

void effect_J6_move(WORK_Other *ewk) {
    WORK_Other *oya_ptr;

    if (obr_no_disp_check() != 0) {
        return;
    }

    oya_ptr = (WORK_Other *)ewk->my_master;

    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;

        if (eff_hit_flag[ewk->wu.type] != 0) {
            ewk->wu.routine_no[0] = 4;
            set_char_move_init(&ewk->wu, 0, 3);
        } else {
            set_char_move_init(&ewk->wu, 0, 4);
        }

        break;

    case 1:
        if (oya_ptr->wu.routine_no[0] >= 2) {
            ewk->wu.routine_no[0]++;
        }

        disp_pos_trans_entry_r(ewk);
        break;

    case 2:
        if (EXE_flag == 0 && Game_pause == 0 && EXE_obroll == 0) {
            effect_j6_hit_sub(ewk);
        }

        disp_pos_trans_entry_r(ewk);
        break;

    case 3:
        ewk->wu.routine_no[0]++;
        set_char_move_init(&ewk->wu, 0, 3);
        /* fallthrough */

    case 4:
        disp_pos_trans_entry_r(ewk);
        break;

    default:
        sub_0004384A(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}

void effect_j6_hit_sub(WORK_Other *ewk) {
    if (eff_hit_check(ewk, 0) != 0) {
        ewk->wu.routine_no[0]++;
        effect_27_init(ewk, 1);
    }
}

s32 effect_J6_init(WORK_Other *oya) {
    WORK_Other *ewk;
    s16 ix;

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }

    ewk = (WORK_Other *)frw[ix];
    ewk->my_master = (u32 *)oya;
    ewk->wu.be_flag = 1;
    ewk->wu.id = 196;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.rl_flag = 0;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.type = 3;
    ewk->wu.dead_f = 0;
    ewk->wu.my_family = 2;
    ewk->wu.my_mts = 7;
    ewk->wu.my_trans_mode = get_my_trans_mode(ewk->wu.my_mts);
    ewk->wu.my_col_code = 0x212C;
    ewk->wu.char_table[0] = _chn_char_table;
    ewk->wu.xyz[0].disp.pos = 904;
    ewk->wu.xyz[1].disp.pos = 16;
    ewk->wu.my_priority = ewk->wu.position_z = 10;
    ewk->wu.char_index = 4;
    ewk->wu.routine_no[1] = 0;
    return 0;
}
