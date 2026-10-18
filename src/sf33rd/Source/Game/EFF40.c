/* EFF40.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * effect_40_move 0x3BBA3 size 0x61.
 * EFF40_EXIT 0x3BC04 size 0x32.
 * EFF40_BACK 0x3BC36 size 0x41.
 * EFF40_ARROW 0x3BC77 size 0x77.
 * effect_40_init 0x3BCEE size 0x132.
 * Data: EFF40_Jmp_Tbl is 0x24DE6C, 4 entries compared.
 * Data: Pos_Data_40 is 0x24DE7C, 0x18 bytes compared.
 * Globals: EFF40_Jmp_Tbl 0x24DE6C, Pos_Data_40 0x24DE7C, _sel_pl_char_table
 * 0x2FE100, Menu_Max 0x7A81B6, Menu_Cursor_Y 0x7A827E, Menu_Suicide 0x7A87A0,
 * Menu_Page_Buff 0x7A8810, bg_w 0x7BC520, save_w 0x7BD3E0, system_dir
 * 0x7C59E0, frw 0xC806A0.
 */

#include "structs.h"

#define EFFECT_MAX 128

void EFF40_EXIT(WORK_Other* ewk);
void EFF40_BACK(WORK_Other* ewk);
void EFF40_ARROW(WORK_Other* ewk);
extern u8 Menu_Suicide[4];
void push_effect_work(WORK* wkhd);
extern struct _SAVE_W save_w[6];
extern s8 Menu_Page_Buff;
extern s8 Menu_Max;
extern SystemDir system_dir[6];
s32 sort_push_request4(WORK* wk);
extern s8 Menu_Cursor_Y[2];
void set_char_move_init2(WORK* wk, s16 koc, s16 index, s16 ip, s16 scf);
void set_char_move_init(WORK* wk, s16 koc, s16 index);
void char_move(WORK* wk);
s16 pull_effect_work(s16 index);
extern uintptr_t frw[EFFECT_MAX][448];
extern u32 _sel_pl_char_table[];
s16 get_my_trans_mode(s16 curr);
extern BG bg_w;

void (*const EFF40_Jmp_Tbl[4])() = { EFF40_EXIT, EFF40_BACK, EFF40_ARROW, EFF40_ARROW };

const s16 Pos_Data_40[4][3] = { { 0, 77, 70 }, { 0, 77, 72 }, { 0, 77, 68 }, { 0, 77, 68 } };

/* The Xbox does not call Check_Pos_OBJ2. */
void effect_40_move(WORK_Other* ewk) {
    if (Menu_Suicide[ewk->master_player]) {
        push_effect_work(&ewk->wu);
        return;
    }

    if (ewk->master_id) {
        ewk->wu.rl_waza = save_w[1].extra_option.contents[Menu_Page_Buff][Menu_Max];
    } else {
        ewk->wu.rl_waza = system_dir[1].contents[Menu_Page_Buff][Menu_Max];
    }

    EFF40_Jmp_Tbl[ewk->wu.routine_no[0]](ewk);
    sort_push_request4(&ewk->wu);
}

void EFF40_EXIT(WORK_Other* ewk) {
    if (Menu_Cursor_Y[0] == Menu_Max && ewk->wu.rl_waza == ewk->master_priority) {
        ewk->wu.my_clear_level = 0;
    } else {
        ewk->wu.my_clear_level = 128;
    }
}

void EFF40_BACK(WORK_Other* ewk) {
    s16 ix;

    if (Menu_Cursor_Y[0] == Menu_Max && ewk->wu.rl_waza == ewk->master_priority) {
        ix = 1;
    } else {
        ix = 0;
    }

    set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ix + 1, 0);
}

void EFF40_ARROW(WORK_Other* ewk) {
    if (Menu_Cursor_Y[0] != Menu_Max) {
        set_char_move_init2(&ewk->wu, 0, 76, (ewk->master_priority / 2) + 1, 0);
        ewk->wu.routine_no[1] = 0;
    } else if (ewk->wu.rl_waza == ewk->master_priority) {
        if (ewk->wu.routine_no[1] == 0) {
            set_char_move_init(&ewk->wu, 0, ewk->wu.dir_step);
            ewk->wu.routine_no[1] = 1;
        } else {
            char_move(&ewk->wu);
        }
    } else {
        set_char_move_init2(&ewk->wu, 0, 76, (ewk->master_priority / 2) + 1, 0);
        ewk->wu.routine_no[1] = 0;
    }
}

s32 effect_40_init(s16 id, s16 type, s16 char_ix, s16 sync_bg, s16 master_player, s16 master_priority) {
    WORK_Other* ewk;
    s16 ix;

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }

    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.disp_flag = 1;
    ewk->wu.id = 40;
    ewk->wu.work_id = 16;
    ewk->wu.my_col_code = 0x1AC;
    ewk->master_id = id;
    ewk->wu.type = type;
    ewk->wu.routine_no[0] = type;
    ewk->wu.char_index = char_ix;
    ewk->wu.dir_step = char_ix;
    ewk->wu.my_family = sync_bg + 1;
    ewk->master_player = master_player;
    ewk->master_priority = master_priority;
    *ewk->wu.char_table = _sel_pl_char_table;
    ewk->wu.my_mts = 13;
    ewk->wu.my_trans_mode = get_my_trans_mode(ewk->wu.my_mts);
    ewk->wu.position_x = bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos + Pos_Data_40[type][0];
    ewk->wu.position_y = bg_w.bgw[ewk->wu.my_family - 1].wxy[1].disp.pos + Pos_Data_40[type][1];
    ewk->wu.position_z = Pos_Data_40[type][2];

    if (master_priority < 2) {
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
    } else {
        set_char_move_init2(&ewk->wu, 0, 76, (ewk->master_priority / 2) + 1, 0);
    }

    return 0;
}
