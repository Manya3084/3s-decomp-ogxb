/* EFF75.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * effect_75_move 0x40E4F size 0x30.
 * EFF75_SUDDENLY 0x40EA1 size 0x9A.
 * effect_75_init 0x40F3B size 0x8D.
 * EFF75_CHAR_CHANGE is folded into 0x3DE4D with 1 other bodies. Unnamed.
 * EFF75_WAIT is folded into 0x40E7F with 6 other bodies. Unnamed.
 * EFF75_SLIDE_IN is folded into 0x4384A with 17 other bodies. Unnamed.
 * Data: EFF75_Jmp_Tbl is 0x24F688, 5 entries compared.
 * Globals: EFF75_Jmp_Tbl 0x24F688, _sel_pl_char_table 0x2FE100, Order
 * 0x7A8380, Order_Timer 0x7A8480, Order_Dir 0x7A85E0, bg_w 0x7BC520, frw
 * 0xC806A0.
 */

#include "structs.h"

#define EFFECT_MAX 128

void EFF75_WAIT(WORK_Other* ewk);
void EFF75_SLIDE_IN(WORK_Other* /* unused */);
void EFF75_CHAR_CHANGE(WORK_Other* ewk);
void EFF75_SUDDENLY(WORK_Other* ewk);
void EFF57_KILL(WORK_Other* ewk);
s32 sort_push_request4(WORK* wk);
extern u8 Order[148];
extern u8 Order_Timer[148];
extern u8 Order_Dir[148];
void set_char_move_init2(WORK* wk, s16 koc, s16 index, s16 ip, s16 scf);
extern BG bg_w;
s16 pull_effect_work(s16 index);
extern uintptr_t frw[EFFECT_MAX][448];
extern u32 _sel_pl_char_table[];
s16 get_my_trans_mode(s16 curr);

void (*const EFF75_Jmp_Tbl[5])() = { EFF75_WAIT, EFF75_SLIDE_IN, EFF75_CHAR_CHANGE, EFF75_SUDDENLY, EFF57_KILL };

void effect_75_move(WORK_Other* ewk) {
    EFF75_Jmp_Tbl[ewk->wu.routine_no[0]](ewk);

    if (ewk->wu.be_flag != 0) {
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0xFFFF;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0xFFFF;
        sort_push_request4(&ewk->wu);
    }
}

void EFF75_WAIT(WORK_Other* ewk) {
    if ((ewk->wu.routine_no[0] = Order[ewk->wu.dir_old])) {
        ewk->wu.routine_no[1] = 0;
    }
}

void EFF75_SLIDE_IN(WORK_Other* /* unused */) {}

void EFF75_CHAR_CHANGE(WORK_Other* ewk) {
    if (--Order_Timer[ewk->wu.dir_old] != 0) {
        return;
    }

    ewk->wu.routine_no[0] = 0;
    Order[ewk->wu.dir_old] = 0;
    ewk->wu.dir_step = Order_Dir[ewk->wu.dir_old];
    set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
}

void EFF75_SUDDENLY(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (--Order_Timer[ewk->wu.dir_old]) {
            break;
        }

        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.xyz[0].disp.pos = bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos + 1;
        ewk->wu.xyz[1].disp.pos = bg_w.bgw[ewk->wu.my_family - 1].wxy[1].disp.pos + 1;
        ewk->wu.position_z = 76;
        ewk->wu.dir_step = Order_Dir[ewk->wu.dir_old];
        set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
        break;

    default:
        ewk->wu.routine_no[0] = 0;
        Order[ewk->wu.dir_old] = 0;
        break;
    }
}

s32 effect_75_init(s16 dir_old, s16 ID, s16 Target_BG) {
    WORK_Other* ewk;
    s16 ix;

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }

    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 75;
    ewk->wu.work_id = 16;
    ewk->wu.my_col_code = 0x90;
    ewk->wu.my_family = Target_BG + 1;
    *ewk->wu.char_table = _sel_pl_char_table;
    ewk->wu.char_index = 19;
    ewk->wu.dir_step = ID;
    ewk->wu.dir_old = dir_old;
    ewk->wu.my_mts = 13;
    ewk->wu.my_trans_mode = get_my_trans_mode(ewk->wu.my_mts);
    return 0;
}
