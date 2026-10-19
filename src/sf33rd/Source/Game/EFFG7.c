/* Effect G7, retail sf33rd.xbe.
 * effect_G7_move is 0x4BD0F size 0x73.
 * effect_G7_init is 0x4BD82 size 0x9A.
 *
 * effect_G7_init stores xyz[1].disp.pos first and old_rno[0] after
 * cgromtype. The C keeps the PlayStation 2 order. The character table
 * immediate is 0x2F53B0 (_end_char_table). Those bytes were not compared.
 * end_w.r_no_2 is the word at 0x7AABF4. cg_type is +0x214. old_rno is +0x34.
 * set_char_move_init2 is 0x201B9. char_move is 0x2008E.
 * disp_pos_trans_entry is folded into 0xEF0C0. all_cgps_put_back stays
 * sub_0004384A. push_effect_work is 0x4AC6C. pull_effect_work is 0x4A6A8.
 * get_my_trans_mode is 0xEF70B. frw is 0xC806A0, 0x700 bytes per object.
 */

#include "types.h"
#include "structs.h"




typedef u8 EffectRow[0x700];

#if defined(__i386__)
_Static_assert(__builtin_offsetof(WORK, old_rno) == 0x34, "old_rno");
_Static_assert(__builtin_offsetof(WORK, cgromtype) == 0x48, "cgromtype");
_Static_assert(__builtin_offsetof(WORK, xyz[0].disp.pos) == 0x66, "xyz0");
_Static_assert(__builtin_offsetof(WORK, char_table) == 0x1AC, "char_table");
_Static_assert(__builtin_offsetof(WORK, cg_type) == 0x214, "cg_type");
_Static_assert(__builtin_offsetof(WORK, my_col_mode) == 0x23C, "my_col_mode");
_Static_assert(__builtin_offsetof(WORK, my_mts) == 0x24C, "my_mts");
_Static_assert(__builtin_offsetof(WORK, my_trans_mode) == 0x254, "trans");
_Static_assert(sizeof(WORK) == 0x388, "WORK");
#endif

extern s16 end_w_r_no_2;   /* end_w.r_no_2, 0x7AABF4 */
extern u32 _end_char_table[];
extern EffectRow frw[];

void push_effect_work(WORK *wk);
s16 pull_effect_work(s16 index);
s16 get_my_trans_mode(s16 curr);
void set_char_move_init2(WORK *wk, s32 koc, s32 index, s32 ip, s32 scf);
void char_move(WORK *wk);
void sub_000EF0C0(WORK_Other *ewk);
void sub_0004384A(WORK *wk);

void effect_G7_move(WORK_Other *ewk) {
    if (ewk->wu.old_rno[0] < end_w_r_no_2) {
        ewk->wu.routine_no[0] = 99;
    }

    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init2(&ewk->wu, 0, 51, 1, 0);
        sub_000EF0C0(ewk);
        break;

    case 1:
        char_move(&ewk->wu);

        if (ewk->wu.cg_type == 0xFF) {
            ewk->wu.routine_no[0]++;
        }

        sub_000EF0C0(ewk);
        break;

    default:
        sub_0004384A(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}

s32 effect_G7_init(s32 unused0, s32 unused1) {
    WORK_Other *ewk;
    s16 ix;

    (void)unused0;
    (void)unused1;

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }

    ewk = (WORK_Other *)frw[ix];
    ewk->wu.id = 167;
    ewk->wu.be_flag = 1;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.old_rno[0] = end_w_r_no_2;
    ewk->wu.my_col_mode = 0x4200;
    *ewk->wu.char_table = _end_char_table;
    ewk->wu.my_family = 3;
    ewk->wu.my_col_code = 0x12C;
    ewk->wu.xyz[0].disp.pos = 688;
    ewk->wu.xyz[1].disp.pos = 0;
    ewk->wu.my_priority = ewk->wu.position_z = 74;
    ewk->wu.my_mts = 8;
    ewk->wu.my_trans_mode = get_my_trans_mode(ewk->wu.my_mts);
    return 0;
}
