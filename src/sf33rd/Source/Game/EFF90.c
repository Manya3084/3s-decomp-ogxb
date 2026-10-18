/* Effect 90, retail sf33rd.xbe.
 * Check_Disp_90 is 0x423CC size 0x47.
 * Check_Disp_Pos_90 is 0x42413 size 0x4B.
 * effect_90_move is 0x4245E size 0x70.
 *
 * effect_90_move does not call Check_Pos_OBJ2, the debug position check.
 * The PS2 retail build leaves it out too. The my_clear_level choice is
 * branchless: 0x80 unless Menu_Cursor_Y[1] equals master_priority, 0 when
 * master_priority is 0xFF. Check_Disp_Pos_90 computes
 * (Cursor_Limit[0] - master_priority) * 20 + the BG y + 158. That is the
 * PS2 sum regrouped.
 * Menu_Suicide is 0x7A87A0. Menu_Cursor_Y is 0x7A827E.
 * Cursor_Limit is 0x7A89BA. bg_w is 0x7BC520, bgw at +0x38, stride 0x90.
 * bgw[f - 1].wxy[1].disp.pos is read as 0x7BC4EE + f * 0x90.
 * dir_step is +0x98. master_priority is +0x392.
 * push_effect_work is 0x4AC6C. sort_push_request3 is 0x9E423.
 */

#include "types.h"

typedef union {
    s32 cal;
    struct {
        s16 low;
        s16 pos;
    } disp;
} XY;

typedef struct {
    s8 be_flag;
    s8 disp_flag;
    u8 pad_type[0x56 - 2];
    s16 position_y;
    u8 pad_dir[0x98 - 0x58];
    s16 dir_step;
    u8 pad_fam[0x242 - 0x9A];
    s16 my_family;
    u8 pad_clear[0x24A - 0x244];
    s16 my_clear_level;
    u8 pad_end[0x388 - 0x24C];
} WORK;

typedef struct {
    WORK wu;
    u32 *my_master;
    s16 master_work_id;
    s16 master_id;
    s16 master_player;
    s16 master_priority;
} WORK_Other_CONN;

typedef struct {
    u8 raw0[0x18];
    XY xy[2];
    XY wxy[2];
    u8 raw1[0x90 - 0x28];
} BGW;

typedef struct {
    u8 raw0[0x38];
    BGW bgw[7];
} BG;

#if defined(__i386__)
_Static_assert(__builtin_offsetof(WORK, disp_flag) == 1, "disp_flag");
_Static_assert(__builtin_offsetof(WORK, position_y) == 0x56, "position_y");
_Static_assert(__builtin_offsetof(WORK, dir_step) == 0x98, "dir_step");
_Static_assert(__builtin_offsetof(WORK, my_family) == 0x242, "my_family");
_Static_assert(__builtin_offsetof(WORK, my_clear_level) == 0x24A, "clear");
_Static_assert(sizeof(WORK) == 0x388, "WORK");
_Static_assert(__builtin_offsetof(WORK_Other_CONN, master_player) == 0x390, "player");
_Static_assert(__builtin_offsetof(WORK_Other_CONN, master_priority) == 0x392, "priority");
_Static_assert(sizeof(BGW) == 0x90, "BGW");
_Static_assert(__builtin_offsetof(BG, bgw[0].wxy[1].disp.pos) == 0x5E, "wxy1");
#endif

extern u8 Menu_Suicide[4];
extern s8 Menu_Cursor_Y[2];
extern s8 Cursor_Limit[2];
extern BG bg_w;

void push_effect_work(WORK *wk);
void sort_push_request3(WORK *wk);

s32 Check_Disp_90(WORK_Other_CONN *ewk) {
    if (ewk->wu.dir_step == 2 || ewk->wu.dir_step == 6) {
        return 1;
    }

    if (ewk->master_priority < Cursor_Limit[0]) {
        return 0;
    }

    if (ewk->master_priority > Cursor_Limit[0] + 3) {
        return 0;
    }

    return 1;
}

s16 Check_Disp_Pos_90(WORK_Other_CONN *ewk) {
    if (ewk->wu.dir_step == 2 || ewk->wu.dir_step == 6) {
        return ewk->wu.position_y;
    }

    return (Cursor_Limit[0] - ewk->master_priority) * 20 + bg_w.bgw[ewk->wu.my_family - 1].wxy[1].disp.pos + 158;
}

void effect_90_move(WORK_Other_CONN *ewk) {
    if (Menu_Suicide[ewk->master_player]) {
        push_effect_work(&ewk->wu);
        return;
    }

    if (ewk->master_priority == 0xFF) {
        ewk->wu.my_clear_level = 0;
    } else if (Menu_Cursor_Y[1] == ewk->master_priority) {
        ewk->wu.my_clear_level = 0;
    } else {
        ewk->wu.my_clear_level = 0x80;
    }

    ewk->wu.disp_flag = Check_Disp_90(ewk);
    ewk->wu.position_y = Check_Disp_Pos_90(ewk);
    sort_push_request3(&ewk->wu);
}
