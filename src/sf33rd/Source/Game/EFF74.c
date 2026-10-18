/* EFF74.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * effect_74_move 0x40D0A size 0x7A.
 * EFF74_SUDDENLY 0x40D84 size 0xCB. Read against the x86: the 136/104 pos_y
 * choice is branchless, 0x88 plus (-0x20 masked). The C is the PS2 C.
 * EFF74_WAIT is folded into 0x40E7F with 6 other bodies. Unnamed.
 * Data: EFF74_Pos_Data is 0x24F65C, 0x18 bytes compared.
 * Data: EFF74_Jmp_Tbl is 0x24F674, 5 entries compared.
 * Globals: EFF74_Pos_Data 0x24F65C, EFF74_Jmp_Tbl 0x24F674, Menu_Cursor_Y
 * 0x7A827E, Order 0x7A8380, Order_Timer 0x7A8480, Menu_Suicide 0x7A87A0, bg_w
 * 0x7BC520.
 */

#include "structs.h"

void EFF74_WAIT(WORK_Other* ewk);
void EFF74_SUDDENLY(WORK_Other* ewk);
void EFF57_KILL(WORK_Other* ewk);
extern u8 Menu_Suicide[4];
void push_effect_work(WORK* wkhd);
extern u8 Order[148];
extern s8 Menu_Cursor_Y[2];
void set_char_move_init2(WORK* wk, s16 koc, s16 index, s16 ip, s16 scf);
s32 sort_push_request4(WORK* wk);
extern u8 Order_Timer[148];
extern BG bg_w;

const s16 EFF74_Pos_Data[3][2][2] = { { { 0, 148 }, { 0, 116 } },
                                      { { -48, 104 }, { 48, 104 } },
                                      { { -48, 80 }, { 48, 80 } } };

void (*const EFF74_Jmp_Tbl[5])();

void (*const EFF74_Jmp_Tbl[5])() = { EFF74_WAIT, EFF74_SUDDENLY, EFF74_SUDDENLY, EFF74_SUDDENLY, EFF57_KILL };

void effect_74_move(WORK_Other* ewk) {
    if (Menu_Suicide[ewk->master_player]) {
        push_effect_work(&ewk->wu);
        return;
    }

    if (Order[ewk->wu.dir_old] == 4) {
        ewk->wu.routine_no[0] = 4;
    }

    EFF74_Jmp_Tbl[ewk->wu.routine_no[0]](ewk);

    if (ewk->wu.be_flag == 0) {
        return;
    }

    if (Menu_Cursor_Y[0] == ewk->master_id) {
        set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, 2, 0);
    } else {
        set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, 1, 0);
    }

    sort_push_request4(&ewk->wu);
}

void EFF74_WAIT(WORK_Other* ewk) {
    if ((ewk->wu.routine_no[0] = Order[ewk->wu.dir_old])) {
        ewk->wu.routine_no[1] = 0;
    }
}

void EFF74_SUDDENLY(WORK_Other* ewk) {
    s16 pos_y;

    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (--Order_Timer[ewk->wu.dir_old]) {
            break;
        }

        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;

        if (ewk->master_id) {
            pos_y = 104;
        } else {
            pos_y = 136;
        }

        ewk->wu.position_x = bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos + 0;
        ewk->wu.position_y = bg_w.bgw[ewk->wu.my_family - 1].wxy[1].disp.pos + pos_y + 12;
        ewk->wu.position_z = 64;

        if (ewk->master_id) {
            pos_y = 104;
        } else {
            pos_y = 136;
        }

        ewk->wu.position_x =
            bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos + EFF74_Pos_Data[ewk->wu.type][ewk->master_id][0];
        ewk->wu.position_y =
            bg_w.bgw[ewk->wu.my_family - 1].wxy[1].disp.pos + EFF74_Pos_Data[ewk->wu.type][ewk->master_id][1];
        ewk->wu.position_z = 64;
        break;

    default:
        ewk->wu.routine_no[0] = 0;
        Order[ewk->wu.dir_old] = 0;
        break;
    }
}
