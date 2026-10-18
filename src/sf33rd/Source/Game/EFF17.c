/* Effect 17, retail sf33rd.xbe.
 * EFF17_Bowan is 0x38036 size 0x4E.
 * effect_17_move is 0x38084 size 0x4C.
 *
 * EFF17_Bowan keeps routine_no[1] in a register through both cases and
 * stores it once, after the clamp.
 * The else path of effect_17_move clears routine_no[1] before it stores
 * 0x80 into my_clear_level. The C here follows the XBE order.
 * Menu_Suicide is 0x7A87A0. Menu_Cursor_Y is 0x7A827E.
 * my_clear_level is +0x24A. routine_no is +0x24. master_player is +0x390.
 * push_effect_work is 0x4AC6C. sort_push_request4 is 0x9E092.
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
    u8 pad_rno[0x24 - 0xA];
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
extern s8 Menu_Cursor_Y[2];

void push_effect_work(WORK *wk);
void sort_push_request4(WORK *wk);
void EFF17_Bowan(WORK_Other *ewk);

void effect_17_move(WORK_Other *ewk) {
    if (Menu_Suicide[ewk->master_player]) {
        push_effect_work(&ewk->wu);
    } else if (Menu_Cursor_Y[0] == ewk->wu.type) {
        EFF17_Bowan(ewk);
    } else {
        ewk->wu.routine_no[1] = 0;
        ewk->wu.my_clear_level = 128;
    }

    sort_push_request4(&ewk->wu);
}

void EFF17_Bowan(WORK_Other *ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.my_clear_level -= 4;

        if (ewk->wu.my_clear_level < 20) {
            ewk->wu.routine_no[1]++;
            ewk->wu.my_clear_level = 20;
        }

        break;

    case 1:
        ewk->wu.my_clear_level += 4;

        if (ewk->wu.my_clear_level > 127) {
            ewk->wu.routine_no[1]--;
            ewk->wu.my_clear_level = 127;
        }

        break;
    }
}
