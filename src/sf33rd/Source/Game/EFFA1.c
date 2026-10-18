/* Effect A1, retail sf33rd.xbe.
 * effect_A1_move is 0x42CDE size 0x62.
 *
 * The move stores my_clear_level before it tests type. It otherwise follows
 * the PlayStation 2 C.
 * Menu_Suicide is 0x7A87A0. Flash_Synchro is 0x7A87BC.
 * Cursor_Limit is 0x7A89BA. push_effect_work is 0x4AC6C.
 * sort_push_request4 is 0x9E092.
 */

#include "types.h"

typedef struct {
    s8 be_flag;
    s8 disp_flag;
    u8 pad_type[2];
    u8 type;
    u8 pad_clear[0x24A - 5];
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
_Static_assert(__builtin_offsetof(WORK, my_clear_level) == 0x24A, "clear");
_Static_assert(sizeof(WORK) == 0x388, "WORK");
_Static_assert(__builtin_offsetof(WORK_Other, master_player) == 0x390, "player");
#endif

extern u8 Menu_Suicide[4];
extern s16 Flash_Synchro;
extern s8 Cursor_Limit[2];

void push_effect_work(WORK *wk);
void sort_push_request4(WORK *wk);

void effect_A1_move(WORK_Other *ewk) {
    s16 x;

    ewk->wu.disp_flag = 0;

    if (Menu_Suicide[ewk->master_player]) {
        push_effect_work(&ewk->wu);
        return;
    }

    if (ewk->wu.be_flag == 0) {
        return;
    }

    ewk->wu.my_clear_level = Flash_Synchro;

    if (ewk->wu.type) {
        x = Cursor_Limit[1] - Cursor_Limit[0];

        if (x > 4) {
            ewk->wu.disp_flag = 1;
        }
    } else if (Cursor_Limit[0] > 0) {
        ewk->wu.disp_flag = 1;
    }

    sort_push_request4(&ewk->wu);
}
