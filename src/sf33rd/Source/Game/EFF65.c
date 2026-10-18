/* Effect 65, retail sf33rd.xbe.
 * effect_65_move is 0x3F3A5 size 0xC4.
 *
 * The x86 lays the cases out default first and shares the
 * set_char_move_init and set_char_move_init2 calls between them. The C keeps
 * the PlayStation 2 order.
 * vm_w.Connect is read at 0x7C5598. Menu_Suicide is 0x7A87A0.
 * Menu_Cursor_X is 0x7A8218. my_clear_level is +0x24A.
 * set_char_move_init is 0x200A9. set_char_move_init2 stays
 * set_char_move_init2. char_move is 0x2008E. push_effect_work is 0x4AC6C.
 * sort_push_request4 is 0x9E092.
 */

#include "types.h"

typedef struct {
    s8 be_flag;
    s8 disp_flag;
    u8 pad_type[2];
    u8 type;
    u8 pad_rno[0x24 - 5];
    s16 routine_no[8];
    u8 pad_clear[0x24A - 0x34];
    s16 my_clear_level;
    u8 pad_end[0x388 - 0x24C];
} WORK;

typedef struct {
    WORK wu;
    u32 *my_master;
    s16 master_work_id;
    s16 master_id;
    s16 master_player;
} WORK_Other;

#if defined(__i386__)
_Static_assert(__builtin_offsetof(WORK, type) == 4, "type");
_Static_assert(__builtin_offsetof(WORK, routine_no) == 0x24, "routine_no");
_Static_assert(__builtin_offsetof(WORK, my_clear_level) == 0x24A, "clear");
_Static_assert(sizeof(WORK) == 0x388, "WORK");
_Static_assert(__builtin_offsetof(WORK_Other, master_player) == 0x390, "player");
#endif

extern u8 Menu_Suicide[4];
extern s8 Menu_Cursor_X[2];
extern u8 vm_w_Connect[];   /* vm_w.Connect, 0x7C5598 */

void push_effect_work(WORK *wk);
void sort_push_request4(WORK *wk);
void set_char_move_init(WORK *wk, s16 koc, s32 index);
void set_char_move_init2(WORK *wk, s32 koc, s32 index, s32 ip, s32 scf);
void char_move(WORK *wk);

void effect_65_move(WORK_Other *ewk) {
    ewk->wu.my_clear_level = 0x80;

    if (Menu_Suicide[ewk->master_player]) {
        push_effect_work(&ewk->wu);
        return;
    }

    switch (ewk->wu.routine_no[0]) {
    case 0:
        if (vm_w_Connect[ewk->wu.type] == 0) {
            set_char_move_init(&ewk->wu, 0, 0x46);
            break;
        }

        ewk->wu.routine_no[0] = 1;
        /* fallthrough */

    case 1:
        if (vm_w_Connect[ewk->wu.type] == 0) {
            set_char_move_init(&ewk->wu, 0, 0x46);
        } else if (ewk->wu.type == Menu_Cursor_X[0]) {
            ewk->wu.routine_no[0] = 2;
            ewk->wu.my_clear_level = 0;
            set_char_move_init2(&ewk->wu, 0, 0x46, 3, 0);
        } else {
            set_char_move_init2(&ewk->wu, 0, 0x46, 2, 0);
        }

        break;

    default:
        if (vm_w_Connect[ewk->wu.type] == 0) {
            ewk->wu.routine_no[0] = 0;
            set_char_move_init(&ewk->wu, 0, 0x46);
        } else if (ewk->wu.type != Menu_Cursor_X[0]) {
            ewk->wu.routine_no[0] = 1;
            set_char_move_init2(&ewk->wu, 0, 0x46, 2, 0);
        } else {
            ewk->wu.my_clear_level = 0;
            char_move(&ewk->wu);
        }

        break;
    }

    sort_push_request4(&ewk->wu);
}
