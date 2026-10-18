/* EFF98.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * effect_98_move 0x42816 size 0x2B.
 * EFF98_SLIDE_IN 0x42841 size 0x165. Read against the x86: the unnamed words
 * are a position table at 0x267ABC, 12 bytes per entry. The C is the PS2 C.
 * EFF98_SUDDENLY 0x429A6 size 0xA0. Read against the x86: the same position
 * table at 0x267ABC. The C is the PS2 C.
 * effect_98_init 0x42A46 size 0xA8.
 * EFF98_KILL is folded into 0x52476 with 4 other bodies. Unnamed.
 * EFF98_WAIT is folded into 0x40E7F with 6 other bodies. Unnamed.
 * EFF98_SLIDE_OUT is folded into 0x4384A with 41 other bodies. Unnamed.
 * Data: EFF98_Jmp_Tbl is 0x24FB28, 5 entries compared.
 * Unnamed data used (not checked): EFF98_SLIDE_IN: 0x267abc,0x267abe;
 * EFF98_SUDDENLY: 0x267abc,0x267abe.
 * Globals: EFF98_Jmp_Tbl 0x24FB28, _sel_pl_char_table 0x2FE100, Order
 * 0x7A8380, Order_Timer 0x7A8480, Disp_Command_Name 0x7A8528, Stop_Cursor
 * 0x7A8A30, bg_w 0x7BC520, frw 0xC806A0.
 */

#include "structs.h"

#define EFFECT_MAX 128

void EFF98_WAIT(WORK_Other* ewk);
void EFF98_SLIDE_IN(WORK_Other* ewk);
void EFF98_SLIDE_OUT(WORK_Other* );
void EFF98_SUDDENLY(WORK_Other* ewk);
void EFF98_KILL(WORK_Other* ewk);
s32 sort_push_request4(WORK* wk);
extern u8 Order[148];
extern u8 Order_Timer[148];
extern BG bg_w;
extern const s16 Plate_Pos_Data_79[2][2][3][2];
extern s8 Stop_Cursor[2];
extern u8 Disp_Command_Name[2][3];
s32 effect_80_init(WORK_Other* mwk, s16 PL_id, s16 Plate_id, s16 Target_BG);
void set_char_move_init2(WORK* wk, s16 koc, s16 index, s16 ip, s16 scf);
void push_effect_work(WORK* wkhd);
s16 pull_effect_work(s16 index);
extern uintptr_t frw[EFFECT_MAX][448];
extern u32 _sel_pl_char_table[];
s16 get_my_trans_mode(s16 curr);

void (*const EFF98_Jmp_Tbl[5])();

void (*const EFF98_Jmp_Tbl[5])() = { EFF98_WAIT, EFF98_SLIDE_IN, EFF98_SLIDE_OUT, EFF98_SUDDENLY, EFF98_KILL };

void effect_98_move(WORK_Other* ewk) {
    EFF98_Jmp_Tbl[ewk->wu.routine_no[0]](ewk);
    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0xFFFF;
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0xFFFF;
    sort_push_request4(&ewk->wu);
}

void EFF98_WAIT(WORK_Other* ewk) {
    if ((ewk->wu.routine_no[0] = Order[ewk->wu.dir_old])) {
        ewk->wu.routine_no[1] = 0;
    }
}

void EFF98_SLIDE_IN(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (--Order_Timer[ewk->wu.dir_old]) {
            break;
        }

        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.vital_new =
            bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos + Plate_Pos_Data_79[1][ewk->master_id][0][0];
        ewk->wu.xyz[1].disp.pos =
            bg_w.bgw[ewk->wu.my_family - 1].wxy[1].disp.pos + Plate_Pos_Data_79[1][ewk->master_id][0][1];
        Stop_Cursor[ewk->master_id] = 1;
        Disp_Command_Name[ewk->master_id][ewk->master_player] = 1;
        effect_80_init(ewk, ewk->master_id, ewk->master_player, ewk->wu.my_family - 1);

        if (ewk->master_id == 0) {
            ewk->wu.xyz[0].disp.pos = 0xF0;
            ewk->wu.mvxy.a[0].sp = 0xF0000;
            ewk->wu.mvxy.d[0].sp = 0x8000;
        } else {
            ewk->wu.xyz[0].disp.pos = 0x310;
            ewk->wu.mvxy.a[0].sp = -0xF0000;
            ewk->wu.mvxy.d[0].sp = -0x8000;
        }

        set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
        break;

    default:
        ewk->wu.xyz[0].cal += ewk->wu.mvxy.a[0].sp;
        ewk->wu.mvxy.a[0].sp += ewk->wu.mvxy.d[0].sp;

        if (0 < ewk->wu.mvxy.a[0].sp) {
            if (ewk->wu.vital_new <= ewk->wu.xyz[0].disp.pos) {
                Order[ewk->wu.dir_old] = 0;
                ewk->wu.routine_no[0] = 0;
                ewk->wu.xyz[0].disp.pos = ewk->wu.vital_new;
            }
        } else if (ewk->wu.vital_new >= ewk->wu.xyz[0].disp.pos) {
            Order[ewk->wu.dir_old] = 0;
            ewk->wu.routine_no[0] = 0;
            ewk->wu.xyz[0].disp.pos = ewk->wu.vital_new;
        }

        break;
    }
}

void EFF98_SLIDE_OUT(WORK_Other* /* unused */) {}

void EFF98_SUDDENLY(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (--Order_Timer[ewk->wu.dir_old]) {
            break;
        }

        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.xyz[0].disp.pos =
            bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos + Plate_Pos_Data_79[1][ewk->master_id][0][0];
        ewk->wu.xyz[1].disp.pos =
            bg_w.bgw[ewk->wu.my_family - 1].wxy[1].disp.pos + Plate_Pos_Data_79[1][ewk->master_id][0][1];
        set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
        break;

    default:
        ewk->wu.routine_no[0] = 0;
        Order[ewk->wu.dir_old] = 0;
        break;
    }
}

void EFF98_KILL(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (--Order_Timer[ewk->wu.dir_old] == 0) {
            ewk->wu.routine_no[1]++;
            ewk->wu.disp_flag = 0;
        }

        break;

    default:
        push_effect_work(&ewk->wu);
        break;
    }
}

s32 effect_98_init(s16 PL_id, s16 dir_old, s16 master_player, s16 Target_BG) {
    WORK_Other* ewk;
    s16 ix;

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }

    ewk = (WORK_Other*)frw[ix];
    ewk->master_player = master_player;
    ewk->wu.be_flag = 1;
    ewk->wu.id = 98;
    ewk->wu.work_id = 16;
    ewk->wu.my_col_code = 0x2090;
    ewk->wu.my_family = Target_BG + 1;
    *ewk->wu.char_table = _sel_pl_char_table;
    ewk->master_id = PL_id;
    ewk->wu.my_mts = 13;
    ewk->wu.my_trans_mode = get_my_trans_mode(ewk->wu.my_mts);
    ewk->wu.dir_old = dir_old;
    ewk->wu.char_index = 14;
    ewk->wu.dir_step = 30;
    ewk->wu.position_z = 35;
    return 0;
}
