/* EFF57.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * effect_57_move 0x3DCDE size 0x65.
 * EFF57_SLIDE_IN 0x3DD43 size 0x10A.
 * EFF57_WALL 0x3DEA4 size 0xA1.
 * EFF57_SUDDENLY 0x3DF45 size 0x8E. Read against the x86: the position_z
 * choice is branchless (0x1E plus 0x28 masked). The C is the PS2 C.
 * EFF57_KILL 0x3DFD3 size 0x27.
 * effect_57_init 0x3DFFA size 0xC2.
 * EFF57_CHAR_CHANGE is folded into 0x3DE4D with 1 other bodies. Unnamed.
 * EFF57_WAIT is folded into 0x40E7F with 6 other bodies. Unnamed.
 * Data: EFF57_Jmp_Tbl is 0x24F00C, 6 entries compared.
 * Globals: EFF57_Jmp_Tbl 0x24F00C, _sel_pl_char_table 0x2FE100, Order
 * 0x7A8380, Order_Timer 0x7A8480, Order_Dir 0x7A85E0, bg_w 0x7BC520, frw
 * 0xC806A0.
 */

#include "structs.h"

#define EFFECT_MAX 128

void EFF57_WAIT(WORK_Other* ewk);
void EFF57_SLIDE_IN(WORK_Other* ewk);
void EFF57_CHAR_CHANGE(WORK_Other* ewk);
void EFF57_SUDDENLY(WORK_Other* ewk);
void EFF57_KILL(WORK_Other* ewk);
void EFF57_WALL(WORK_Other* ewk);
extern u8 Order[148];
void dispSaveLoadTitle(void* ewk);
s32 sort_push_request4(WORK* wk);
extern u8 Order_Timer[148];
extern BG bg_w;
void set_char_move_init2(WORK* wk, s16 koc, s16 index, s16 ip, s16 scf);
extern u8 Order_Dir[148];
void push_effect_work(WORK* wkhd);
s16 pull_effect_work(s16 index);
extern uintptr_t frw[EFFECT_MAX][448];
extern u32 _sel_pl_char_table[];
s16 get_my_trans_mode(s16 curr);
s32 effect_58_init(s16 id, s16 time0, s16 option);
s32 effect_62_init(WORK_Other* mwk, s16 ID);

void (*const EFF57_Jmp_Tbl[6])();

void (*const EFF57_Jmp_Tbl[6])() = { EFF57_WAIT,     EFF57_SLIDE_IN, EFF57_CHAR_CHANGE,
                                     EFF57_SUDDENLY, EFF57_KILL,     EFF57_WALL };

void effect_57_move(WORK_Other* ewk) {
    if (ewk->wu.routine_no[0] != Order[ewk->wu.dir_old]) {
        ewk->wu.routine_no[0] = Order[ewk->wu.dir_old];
        ewk->wu.routine_no[1] = 0;
    }

    EFF57_Jmp_Tbl[ewk->wu.routine_no[0]](ewk);

    if (ewk->wu.be_flag == 0) {
        return;
    }

    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0xFFFF;
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0xFFFF;

    if (ewk->wu.cg_number == 0x6F86) {
        dispSaveLoadTitle(ewk);
        return;
    }

    sort_push_request4(&ewk->wu);
}

void EFF57_WAIT(WORK_Other* ewk) {
    if ((ewk->wu.routine_no[0] = Order[ewk->wu.dir_old])) {
        ewk->wu.routine_no[1] = 0;
    }
}

void EFF57_SLIDE_IN(WORK_Other* ewk) {
    if (Order[ewk->wu.dir_old] != 1) {
        ewk->wu.routine_no[0] = Order[ewk->wu.dir_old];
        ewk->wu.routine_no[1] = 0;
        return;
    }

    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (--Order_Timer[ewk->wu.dir_old]) {
            break;
        }

        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.xyz[0].disp.pos = bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos - 384;
        ewk->wu.xyz[1].disp.pos = bg_w.bgw[ewk->wu.my_family - 1].wxy[1].disp.pos + 236;
        ewk->wu.position_z = 70;
        ewk->wu.hit_quake = bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos + 0;
        ewk->wu.mvxy.a[0].sp = 0x100000;
        ewk->wu.mvxy.d[0].sp = 0x8000;
        set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
        break;

    default:
        ewk->wu.xyz[0].cal += ewk->wu.mvxy.a[0].sp;
        ewk->wu.mvxy.a[0].sp += ewk->wu.mvxy.d[0].sp;

        if (0 < ewk->wu.mvxy.a[0].sp) {
            if (ewk->wu.hit_quake <= ewk->wu.xyz[0].disp.pos) {
                if (Order[ewk->wu.dir_old] == ewk->wu.routine_no[0]) {
                    Order[ewk->wu.dir_old] = 0;
                }

                ewk->wu.routine_no[0] = 0;
                ewk->wu.xyz[0].disp.pos = ewk->wu.hit_quake;
            }
        } else {
            if (ewk->wu.hit_quake >= ewk->wu.xyz[0].disp.pos) {
                if (Order[ewk->wu.dir_old] == ewk->wu.routine_no[0]) {
                    Order[ewk->wu.dir_old] = 0;
                }

                ewk->wu.routine_no[0] = 0;
                ewk->wu.xyz[0].disp.pos = ewk->wu.hit_quake;
            }
        }

        break;
    }
}

void EFF57_CHAR_CHANGE(WORK_Other* ewk) {
    if (--Order_Timer[ewk->wu.dir_old] == 0) {
        ewk->wu.routine_no[0] = 0;
        Order[ewk->wu.dir_old] = 0;
        ewk->wu.dir_step = Order_Dir[ewk->wu.dir_old];
        set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
    }
}

void EFF57_WALL(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (--Order_Timer[ewk->wu.dir_old]) {
            break;
        }

        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.xyz[0].disp.pos = bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos + 0;
        ewk->wu.xyz[1].disp.pos = bg_w.bgw[ewk->wu.my_family - 1].wxy[1].disp.pos + 16;
        ewk->wu.position_z = 78;
        ewk->wu.dir_step = Order_Dir[ewk->wu.dir_old];
        set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
        break;

    default:
        ewk->wu.routine_no[0] = 0;
        Order[ewk->wu.dir_old] = 0;
        break;
    }
}

void EFF57_SUDDENLY(WORK_Other* ewk) {
    if (--Order_Timer[ewk->wu.dir_old] != 0) {
        return;
    }

    ewk->wu.routine_no[0] = 0;
    Order[ewk->wu.dir_old] = 0;
    ewk->wu.disp_flag = 1;
    ewk->wu.xyz[0].disp.pos = bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos + 0;
    ewk->wu.xyz[1].disp.pos = bg_w.bgw[ewk->wu.my_family - 1].wxy[1].disp.pos + 236;

    if (ewk->master_priority != 999) {
        ewk->wu.position_z = 70;
    } else {
        ewk->wu.position_z = 30;
    }

    set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
}

void EFF57_KILL(WORK_Other* ewk) {
    if (--Order_Timer[ewk->wu.dir_old] == 0) {
        push_effect_work(&ewk->wu);
    }
}

s32 effect_57_init(s16 dir_old, s16 ID, s16 Target_BG, s16 char_ix, s16 option) {
    WORK_Other* ewk;
    s16 ix;

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }

    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 57;
    ewk->wu.work_id = 16;
    ewk->wu.my_col_code = 0x1AC;
    ewk->wu.my_family = Target_BG + 1;
    *ewk->wu.char_table = _sel_pl_char_table;
    ewk->wu.dir_step = ID;
    ewk->wu.type = ID;
    ewk->wu.dir_old = dir_old;
    ewk->wu.my_mts = 13;
    ewk->wu.my_trans_mode = get_my_trans_mode(ewk->wu.my_mts);
    ewk->wu.char_index = char_ix;
    ewk->master_priority = option;

    switch (option) {
    case 1:
        effect_58_init(4, 1, 78);
        break;

    case 2:
        effect_62_init(ewk, 0);
        break;
    }

    return 0;
}
