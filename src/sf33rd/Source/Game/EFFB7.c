/* Effect B7, retail sf33rd.xbe.
 * effect_B7_move is 0x44802 size 0x55.
 *
 * The PS2 C reads my_master into a NAME_WK pointer it never uses; the x86
 * does not load it. old_rno is +0x34.
 * set_char_move_init2 is 0x201B9. disp_pos_trans_entry stays
 * disp_pos_trans_entry. all_cgps_put_back stays sub_0004384A.
 * push_effect_work is 0x4AC6C.
 */

#include "types.h"

typedef struct {
    s8 be_flag;
    s8 disp_flag;
    u8 pad_rno[0x24 - 2];
    s16 routine_no[8];
    s16 old_rno[8];
    u8 pad_end[0x388 - 0x44];
} WORK;

typedef struct {
    WORK wu;
    u32 *my_master;
} WORK_Other;

#if defined(__i386__)
_Static_assert(__builtin_offsetof(WORK, routine_no) == 0x24, "routine_no");
_Static_assert(__builtin_offsetof(WORK, old_rno) == 0x34, "old_rno");
_Static_assert(sizeof(WORK) == 0x388, "WORK");
#endif

void push_effect_work(WORK *wk);
void set_char_move_init2(WORK *wk, s32 koc, s32 index, s32 ip, s32 scf);
void sub_000EF0C0(WORK_Other *ewk);
void sub_0004384A(WORK *wk);

void effect_B7_move(WORK_Other *ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init2(&ewk->wu, 0, 7, ewk->wu.old_rno[0] + 1, 0);
        break;

    case 1:
        sub_000EF0C0(ewk);
        break;

    case 2:
        ewk->wu.routine_no[0]++;
        break;

    default:
        sub_0004384A(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}
