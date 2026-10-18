/* Effect 18, retail sf33rd.xbe.
 * effect_18_move is 0x380D0 size 0x41.
 * Check_TenTen is 0x38111 size 0x3C.
 * Setup_Pos_18 is 0x3814D size 0x4D.
 * effect_18_init is 0x3819A size 0x8B.
 *
 * effect_18_move picks my_clear_level branchless. Setup_Pos_18 stores
 * position_z before position_y. effect_18_init stores my_family, type, and
 * master_player before routine_no[0] and be_flag. The C keeps the PlayStation
 * 2 order.
 * Menu_Suicide is 0x7A87A0. Menu_Cursor_Y is 0x7A827E. bg_w is 0x7BC520,
 * bgw at +0x38, stride 0x90. bgw[f - 1].wxy[0].disp.pos is read as
 * 0x7BC4EA + f * 0x90.
 * num_of_conn is +0x396. conn is +0x398, 8 bytes each, chr at +6.
 * get_message_conn_data stays sub_000446DF. push_effect_work is 0x4AC6C.
 * pull_effect_work is 0x4A6A8. sort_push_request3 is 0x9E423.
 * frw is 0xC806A0, 0x700 bytes per object.
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
    u8 pad_type[2];
    u8 type;
    u8 pad_work[1];
    s16 work_id;
    s16 id;
    s8 rl_flag;
    u8 pad_rno[0x24 - 0xB];
    s16 routine_no[8];
    u8 pad_pos[0x54 - 0x34];
    s16 position_x;
    s16 position_y;
    s16 position_z;
    u8 pad_col[0x23E - 0x5A];
    s16 my_col_code;
    s16 my_priority;
    s16 my_family;
    u8 pad_clear[6];
    s16 my_clear_level;
    s16 my_mts;
    u8 pad_end[0x388 - 0x24E];
} WORK;

typedef struct {
    s16 nx;
    s16 ny;
    s16 col;
    u16 chr;
} CONN;

typedef struct {
    WORK wu;
    u32 *my_master;
    s16 master_work_id;
    s16 master_id;
    s16 master_player;
    s16 master_priority;
    s16 prem;
    s16 num_of_conn;
    CONN conn[24];
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

typedef u8 EffectRow[0x700];

#if defined(__i386__)
_Static_assert(__builtin_offsetof(WORK, rl_flag) == 0xA, "rl_flag");
_Static_assert(__builtin_offsetof(WORK, routine_no) == 0x24, "routine_no");
_Static_assert(__builtin_offsetof(WORK, position_x) == 0x54, "position_x");
_Static_assert(__builtin_offsetof(WORK, my_col_code) == 0x23E, "my_col_code");
_Static_assert(__builtin_offsetof(WORK, my_family) == 0x242, "my_family");
_Static_assert(__builtin_offsetof(WORK, my_clear_level) == 0x24A, "clear");
_Static_assert(__builtin_offsetof(WORK, my_mts) == 0x24C, "my_mts");
_Static_assert(sizeof(WORK) == 0x388, "WORK");
_Static_assert(__builtin_offsetof(WORK_Other_CONN, master_player) == 0x390, "player");
_Static_assert(__builtin_offsetof(WORK_Other_CONN, num_of_conn) == 0x396, "num_of_conn");
_Static_assert(__builtin_offsetof(WORK_Other_CONN, conn[0].chr) == 0x39E, "chr");
_Static_assert(__builtin_offsetof(BG, bgw[0].wxy[0].disp.pos) == 0x5A, "wxy0");
#endif

extern u8 Menu_Suicide[4];
extern s8 Menu_Cursor_Y[2];
extern BG bg_w;
extern EffectRow frw[];

void push_effect_work(WORK *wk);
void sort_push_request3(WORK *wk);
s16 pull_effect_work(s16 index);
void sub_000446DF(WORK_Other_CONN *ewk, s32 kind, s32 pl, s32 msg);
void Setup_Pos_18(WORK_Other_CONN *ewk);

void effect_18_move(WORK_Other_CONN *ewk) {
    if (Menu_Suicide[ewk->master_player]) {
        push_effect_work(&ewk->wu);
        return;
    }

    if (Menu_Cursor_Y[0] == ewk->wu.type) {
        ewk->wu.my_clear_level = 0;
    } else {
        ewk->wu.my_clear_level = 128;
    }

    sort_push_request3(&ewk->wu);
}

void Check_TenTen(WORK_Other_CONN *ewk) {
    s16 ix;

    for (ix = 0; ix < ewk->num_of_conn; ix++) {
        if (ewk->conn[ix].chr == 0x855B) {
            ewk->conn[ix].chr = 0x80EA;
        }

        if (ewk->conn[ix].chr == 0x862C) {
            ewk->conn[ix].chr = 0x80EB;
        }
    }
}

void Setup_Pos_18(WORK_Other_CONN *ewk) {
    ewk->wu.position_x = bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos - 143;
    ewk->wu.position_y = bg_w.bgw[ewk->wu.my_family - 1].wxy[1].disp.pos + 199 - ewk->wu.type * 18;
    ewk->wu.position_z = 68;
    Check_TenTen(ewk);
}

s32 effect_18_init(s16 disp_index, s16 cursor_id, s16 sync_bg, s16 master_player) {
    WORK_Other_CONN *ewk;
    s16 ix;

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }

    ewk = (WORK_Other_CONN *)frw[ix];
    ewk->wu.routine_no[0] = 0;
    ewk->wu.be_flag = 1;
    ewk->wu.disp_flag = 1;
    ewk->wu.id = 18;
    ewk->wu.work_id = 16;
    ewk->wu.rl_flag = 0;
    ewk->wu.my_col_code = 428;
    ewk->wu.my_family = sync_bg + 1;
    ewk->wu.type = cursor_id;
    ewk->master_player = master_player;
    sub_000446DF(ewk, 3, 0, disp_index);
    ewk->wu.my_mts = 12;
    Setup_Pos_18(ewk);
    return 0;
}
