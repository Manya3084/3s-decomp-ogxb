/* EFF69.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * effect_69_move 0x404C7 size 0x30.
 * EFF69_SLIDE_OUT 0x404F7 size 0xAC.
 * EFF69_SUDDENLY 0x405A3 size 0x7E. Read against the x86: the unnamed words
 * are a position table at 0x267BC4. The C is the PS2 C.
 * effect_69_init 0x40621 size 0xE2. Read against the x86: the same position
 * table at 0x267BC4; +2 is its second short. The C is the PS2 C.
 * Setup_Clear_OBJ 0x40703 size 0x2A.
 * EFF69_SLIDE_IN 0x4072D size 0xEE.
 * EFF69_WAIT is folded into 0x40E7F with 6 other bodies. Unnamed.
 * Data: EFF69_Jmp_Tbl is 0x24F638, 5 entries compared.
 * Globals: EFF69_Jmp_Tbl 0x24F638, Pos_Data_69 0x267BC4, _sel_pl_char_table
 * 0x2FE100, Present_Mode 0x7A819C, Order 0x7A8380, Order_Timer 0x7A8480,
 * Order_Dir 0x7A85E0, frw 0xC806A0.
 */

#include "structs.h"

#define EFFECT_MAX 128

void EFF69_WAIT(WORK_Other* ewk);
void EFF69_SLIDE_IN(WORK_Other* ewk);
void EFF69_SLIDE_OUT(WORK_Other* ewk);
void EFF69_SUDDENLY(WORK_Other* ewk);
void EFF57_KILL(WORK_Other* ewk);
s32 sort_push_request4(WORK* wk);
extern u8 Order[148];
extern u8 Order_Timer[148];
void Setup_Clear_OBJ(WORK_Other* ewk);
extern u8 Order_Dir[148];
void set_char_move_init2(WORK* wk, s16 koc, s16 index, s16 ip, s16 scf);
s32 Ck_Range_Out_S(WORK_Other* ewk, s16 BG_No, s16 R);
void push_effect_work(WORK* wkhd);
extern const s16 Pos_Data_69[][2];
extern u8 Present_Mode;
s16 pull_effect_work(s16 index);
extern uintptr_t frw[EFFECT_MAX][448];
extern u32 _sel_pl_char_table[];
s16 get_my_trans_mode(s16 curr);
s32 effect_59_init(WORK_Other* mwk, s16 Synchro_BG, s16 ID, s16 direction);

void (*const EFF69_Jmp_Tbl[5])();

void (*const EFF69_Jmp_Tbl[5])() = { EFF69_WAIT, EFF69_SLIDE_IN, EFF69_SLIDE_OUT, EFF69_SUDDENLY, EFF57_KILL };

void effect_69_move(WORK_Other* ewk) {
    EFF69_Jmp_Tbl[ewk->wu.routine_no[0]](ewk);

    if (ewk->wu.be_flag != 0) {
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0xFFFF;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0xFFFF;
        sort_push_request4(&ewk->wu);
    }
}

void EFF69_WAIT(WORK_Other* ewk) {
    if ((ewk->wu.routine_no[0] = Order[ewk->wu.dir_old])) {
        ewk->wu.routine_no[1] = 0;
    }
}

void EFF69_SLIDE_IN(WORK_Other* ewk) {
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
        Setup_Clear_OBJ(ewk);

        if (Order_Dir[ewk->wu.dir_old] == 4) {
            ewk->wu.mvxy.a[0].sp = -0x100000;
            ewk->wu.mvxy.d[0].sp = 0;
        } else {
            ewk->wu.mvxy.a[0].sp = 0x100000;
            ewk->wu.mvxy.d[0].sp = 0x8000;
        }

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
        } else if (ewk->wu.hit_quake >= ewk->wu.xyz[0].disp.pos) {
            if (Order[ewk->wu.dir_old] == ewk->wu.routine_no[0]) {
                Order[ewk->wu.dir_old] = 0;
            }

            ewk->wu.routine_no[0] = 0;
            ewk->wu.xyz[0].disp.pos = ewk->wu.hit_quake;
        }

        break;
    }
}

void EFF69_SLIDE_OUT(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (ewk->wu.disp_flag == 0) {
            ewk->wu.routine_no[1] = 99;
        } else {
            if (--Order_Timer[ewk->wu.dir_old]) {
                break;
            }
            ewk->wu.routine_no[1]++;
        }

        if (Order_Dir[ewk->wu.dir_old] == 4) {
            ewk->wu.mvxy.a[0].sp = -0x100000;
            ewk->wu.mvxy.d[0].sp = -0x8000;
        } else {
            ewk->wu.mvxy.a[0].sp = 0x100000;
            ewk->wu.mvxy.d[0].sp = 0x8000;
        }

        break;

    case 1:
        ewk->wu.xyz[0].cal += ewk->wu.mvxy.a[0].sp;
        ewk->wu.mvxy.a[0].sp += ewk->wu.mvxy.d[0].sp;

        if (Ck_Range_Out_S(ewk, 2, 128)) {
            ewk->wu.routine_no[1]++;
            ewk->wu.disp_flag = 0;
        }

        break;

    default:
        push_effect_work(&ewk->wu);
        break;
    }
}

void EFF69_SUDDENLY(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (--Order_Timer[ewk->wu.dir_old]) {
            break;
        }

        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.xyz[0].disp.pos = Pos_Data_69[ewk->wu.dir_old][0] + 512;
        ewk->wu.xyz[1].disp.pos = Pos_Data_69[ewk->wu.dir_old][1] + 0;
        set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
        break;

    default:
        ewk->wu.routine_no[0] = 0;
        Order[ewk->wu.dir_old] = 0;
        break;
    }
}

s32 effect_69_init(s16 dir_old) {
    WORK_Other* ewk;
    s16 ix;

    if ((dir_old == 3 || dir_old == 4) && (Present_Mode == 4 || Present_Mode == 5)) {
        return 0;
    }

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }

    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 69;
    ewk->wu.work_id = 16;
    ewk->wu.my_col_code = 0x2090;
    ewk->wu.my_family = 3;
    *ewk->wu.char_table = _sel_pl_char_table;
    ewk->wu.char_index = 16;
    ewk->wu.dir_step = dir_old + 2;
    ewk->wu.dir_old = dir_old;
    ewk->wu.my_mts = 13;
    ewk->wu.my_trans_mode = get_my_trans_mode(ewk->wu.my_mts);
    ewk->wu.xyz[0].disp.pos = 800;
    ewk->wu.mvxy.a[0].sp = -0xF0000;
    ewk->wu.hit_quake = Pos_Data_69[dir_old][0] + 512;
    ewk->wu.xyz[1].disp.pos = Pos_Data_69[dir_old][1] + 0;
    ewk->wu.position_z = 73 - dir_old;
    return 0;
}

void Setup_Clear_OBJ(WORK_Other* ewk) {
    if (ewk->wu.dir_old < 3) {
        effect_59_init(ewk, ewk->wu.my_family, ewk->wu.dir_old, 1);
    }
}
