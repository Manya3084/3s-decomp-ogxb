/* EFF38.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * effect_38_move 0x3B313 size 0x30.
 * EFF38_SUDDENLY 0x3B343 size 0x53.
 * Exit_Slide_in_38 0x3B396 size 0x76.
 * EFF38_SLIDE_OUT 0x3B40C size 0x9E.
 * Move_X_Sub_38 0x3B4AA size 0x3F.
 * Move_Y_Sub_38 0x3B4E9 size 0x49.
 * EFF38_MOVE 0x3B532 size 0x16A.
 * effect_38_init 0x3B69C size 0x22B. Read against the x86: 0x110 is the 272
 * offset, applied with lea, and 0x2C a table row size. The C is the PS2 C.
 * EFF38_SLIDE_IN 0x3B8C7 size 0x104.
 * Shift_38 0x3B9CB size 0x5A. Read against the x86: 1 is the loop flag. The C
 * is the PS2 C.
 * EFF38_SHIFT 0x3BA25 size 0x17E. Read against the x86: 0x2C is a table row
 * size. The C is the PS2 C.
 * EFF38_KILL is folded into 0x52476 with 4 other bodies. Unnamed.
 * EFF38_WAIT is folded into 0x5230F with 2 other bodies. Unnamed.
 * Data: EFF38_Base_XY is 0x24DE40, 0x10 bytes compared.
 * Data: EFF38_Jmp_Tbl is 0x24DE50, 7 entries compared.
 * Globals: EFF38_Base_XY 0x24DE40, EFF38_Jmp_Tbl 0x24DE50, EFF38_Correct_Data
 * 0x267C18, _sel_pl_char_table 0x2FE100, My_char 0x7A8114, Play_Type 0x7A812D,
 * Sel_PL_Complete 0x7A81BC, Cursor_X 0x7A81D4, ID_of_Face 0x7A8240, Order
 * 0x7A8380, Scene_Cut 0x7A8461, Order_Timer 0x7A8480, Order_Dir 0x7A85E0,
 * Cursor_Y 0x7A8812, Select_Start 0x7A8A36, bg_w 0x7BC520, plw 0xC7CEA0, frw
 * 0xC806A0.
 */

#include "structs.h"

#define EFFECT_MAX 128

void EFF38_WAIT(WORK_Other* ewk);
void EFF38_SLIDE_IN(WORK_Other* ewk);
void EFF38_SLIDE_OUT(WORK_Other* ewk);
void EFF38_SUDDENLY(WORK_Other* ewk);
void EFF38_SHIFT(WORK_Other* ewk);
void EFF38_MOVE(WORK_Other* ewk);
void EFF38_KILL(WORK_Other* ewk);
s32 sort_push_request4(WORK* wk);
extern u8 Order[148];
extern u8 Order_Timer[148];
void set_char_move_init2(WORK* wk, s16 koc, s16 index, s16 ip, s16 scf);
s32 Cut_Cut_Sub(s16 xx);
extern BG bg_w;
void Exit_Slide_in_38(WORK_Other* ewk);
extern s8 Select_Start[2];
extern u8 Order_Dir[148];
s32 Ck_Range_Out_S(WORK_Other* ewk, s16 BG_No, s16 R);
void push_effect_work(WORK* wkhd);
extern const s16 EFF38_Correct_Data[2][2][22][2];
void cal_delta_speed(WORK* wk, s16 tm, s16 x1, s16 y1, s8 xsw, s8 ysw);
s32 Shift_38(WORK_Other* ewk);
extern u8 Scene_Cut;
s32 Move_X_Sub_38(WORK_Other* ewk);
s32 Move_Y_Sub_38(WORK_Other* ewk, s16 Target_Y);
extern s16 Sel_PL_Complete[2];
extern PLW plw[2];
extern s8 ID_of_Face[3][8];
extern s8 Cursor_Y[2];
extern s8 Cursor_X[2];
extern u8 Play_Type;
s16 pull_effect_work(s16 index);
extern uintptr_t frw[EFFECT_MAX][448];
extern u32 _sel_pl_char_table[];
s16 get_my_trans_mode(s16 curr);
extern u8 My_char[2];

const s16 EFF38_Base_XY[2][2][2] = { { { -64, 16 }, { -128, 32 } }, { { 64, 16 }, { 128, -32 } } };

void (*const EFF38_Jmp_Tbl[7])() = { EFF38_WAIT,  EFF38_SLIDE_IN, EFF38_SLIDE_OUT, EFF38_SUDDENLY,
                                     EFF38_SHIFT, EFF38_MOVE,     EFF38_KILL };

void effect_38_move(WORK_Other* ewk) {
    EFF38_Jmp_Tbl[ewk->wu.routine_no[0]](ewk);

    if (ewk->wu.be_flag != 0) {
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0xFFFF;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0xFFFF;
        sort_push_request4(&ewk->wu);
    }
}

void EFF38_WAIT(WORK_Other* ewk) {
    if ((ewk->wu.routine_no[0] = Order[ewk->wu.dir_old])) {
        ewk->wu.routine_no[1] = 0;
        ewk->wu.routine_no[6] = 0;
    }
}

void EFF38_SUDDENLY(WORK_Other* ewk) {
    if (--Order_Timer[ewk->wu.dir_old] == 0) {
        ewk->wu.disp_flag = 1;
        Order[ewk->wu.dir_old] = 0;
        ewk->wu.routine_no[0] = 0;
        ewk->wu.xyz[0].disp.pos = ewk->wu.hit_quake;
        set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
    }
}

void EFF38_SLIDE_IN(WORK_Other* ewk) {
    u16 cut = Cut_Cut_Sub(3);

    switch (ewk->wu.routine_no[6]) {
    case 0:
        if (Order[ewk->wu.dir_old] != 1) {
            if (ewk->master_id == 0) {
                ewk->wu.hit_quake = bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos - 128;
                ewk->wu.xyz[1].disp.pos = ewk->wu.vital_new = bg_w.bgw[ewk->wu.my_family - 1].wxy[1].disp.pos + 32;
            } else {
                ewk->wu.hit_quake = bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos + 128;
                ewk->wu.xyz[1].disp.pos = ewk->wu.vital_new = bg_w.bgw[ewk->wu.my_family - 1].wxy[1].disp.pos - 32;
            }

            Order[ewk->wu.dir_old] = 1;
            break;
        }

        if (--Order_Timer[ewk->wu.dir_old] == 0) {
            ewk->wu.routine_no[6]++;
            ewk->wu.disp_flag = 1;
            set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
        }

        break;

    case 1:
        ewk->wu.xyz[0].cal += ewk->wu.mvxy.a[0].sp * cut;
        ewk->wu.mvxy.a[0].sp += ewk->wu.mvxy.d[0].sp;

        if (0 < ewk->wu.mvxy.a[0].sp) {
            if (ewk->wu.hit_quake <= ewk->wu.xyz[0].disp.pos) {
                Exit_Slide_in_38(ewk);
            }
        } else if (ewk->wu.hit_quake >= ewk->wu.xyz[0].disp.pos) {
            Exit_Slide_in_38(ewk);
        }

        break;
    }
}

void Exit_Slide_in_38(WORK_Other* ewk) {
    ewk->wu.xyz[0].disp.pos = ewk->wu.hit_quake;

    if (--Select_Start[ewk->master_id] < 0) {
        Select_Start[ewk->master_id] = 0;
    }

    ewk->wu.routine_no[1] = 0;
    ewk->wu.routine_no[6] = 0;

    if (Order[ewk->wu.dir_old] != 1) {
        ewk->wu.routine_no[0] = Order[ewk->wu.dir_old];
        return;
    }

    if (ewk->wu.vital_old == 0x7F) {
        ewk->wu.routine_no[0] = 5;
        Order[ewk->wu.dir_old] = 5;
        return;
    }

    ewk->wu.routine_no[0] = 0;
    Order[ewk->wu.dir_old] = 0;
}

void EFF38_SLIDE_OUT(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[6]) {
    case 0:
        if (--Order_Timer[ewk->wu.dir_old] == 0) {
            ewk->wu.routine_no[6]++;

            if (Order_Dir[ewk->wu.dir_old] == 8) {
                ewk->wu.mvxy.a[0].sp = 0xF0000;
                ewk->wu.mvxy.d[0].sp = 0x8000;
            } else {
                ewk->wu.mvxy.a[0].sp = -0xF0000;
                ewk->wu.mvxy.d[0].sp = -0x8000;
            }
        }

        break;

    case 1:
        ewk->wu.xyz[0].cal += ewk->wu.mvxy.a[0].sp;
        ewk->wu.mvxy.a[0].sp += ewk->wu.mvxy.d[0].sp;

        if (Ck_Range_Out_S(ewk, ewk->wu.my_family - 1, 80)) {
            ewk->wu.routine_no[6]++;
            ewk->wu.disp_flag = 0;
        }

        break;

    default:
        push_effect_work(&ewk->wu);
        break;
    }
}

void EFF38_KILL(WORK_Other* ewk) {
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

void EFF38_SHIFT(WORK_Other* ewk) {
    u16 cut = Cut_Cut_Sub(3);

    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (--Order_Timer[ewk->wu.dir_old] != 0) {
            break;
        }

        ewk->wu.routine_no[1]++;

        if (ewk->master_id == 0) {
            ewk->wu.hit_quake = bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos + EFF38_Base_XY[ewk->master_id][1][0] +
                                EFF38_Correct_Data[ewk->master_id][1][ewk->wu.dir_step][0];
            ewk->wu.vital_new = bg_w.bgw[ewk->wu.my_family - 1].wxy[1].disp.pos + EFF38_Base_XY[ewk->master_id][1][1] +
                                EFF38_Correct_Data[ewk->master_id][1][ewk->wu.dir_step][1];
            ewk->wu.mvxy.a[0].sp = -0x60000;
            ewk->wu.mvxy.a[1].sp = 0x30000;
            cal_delta_speed(&ewk->wu, 10, ewk->wu.hit_quake, ewk->wu.vital_new, 1, 1);
            ewk->wu.dir_timer = 10;
        } else {
            ewk->wu.hit_quake = 128 + bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos +
                                EFF38_Correct_Data[ewk->master_id][1][ewk->wu.dir_step][0];
            ewk->wu.vital_new = -32 + bg_w.bgw[ewk->wu.my_family - 1].wxy[1].disp.pos +
                                EFF38_Correct_Data[ewk->master_id][1][ewk->wu.dir_step][1];
            ewk->wu.mvxy.a[0].sp = 0x60000;
            ewk->wu.mvxy.a[1].sp = -0x30000;
            cal_delta_speed(&ewk->wu, 10, ewk->wu.hit_quake, ewk->wu.vital_new, 1, 1);
            ewk->wu.dir_timer = 10;
        }

        break;

    case 1:
        if (Shift_38(ewk)) {
            ewk->wu.routine_no[0] = 5;
            Order[ewk->wu.dir_old] = 5;
            ewk->wu.routine_no[1] = 0;
            ewk->wu.routine_no[6] = 0;

            if (--Select_Start[ewk->master_id] < 0) {
                Select_Start[ewk->master_id] = 0;
            }
        }

        break;
    }
}

s32 Shift_38(WORK_Other* ewk) {
    s16 ix;
    s16 loop;

    if (Scene_Cut) {
        loop = 3;
    } else {
        loop = 1;
    }

    for (ix = 0; ix < loop; ix++) {
        Move_X_Sub_38(ewk);
        Move_Y_Sub_38(ewk, ewk->wu.vital_new);

        if (--ewk->wu.dir_timer == 0) {
            return 1;
        }
    }

    return 0;
}

s32 Move_X_Sub_38(WORK_Other* ewk) {
    ewk->wu.xyz[0].cal += ewk->wu.mvxy.a[0].sp;
    ewk->wu.mvxy.a[0].sp += ewk->wu.mvxy.d[0].sp;

    if (0 < ewk->wu.mvxy.a[0].sp) {
        if (ewk->wu.hit_quake <= ewk->wu.xyz[0].disp.pos) {
            ewk->wu.xyz[0].disp.pos = ewk->wu.hit_quake;
            ewk->wu.mvxy.a[0].sp = 0;
            ewk->wu.mvxy.d[0].sp = 0;
            return 1;
        }

        return 0;
    }

    if (ewk->wu.hit_quake >= ewk->wu.xyz[0].disp.pos) {
        ewk->wu.xyz[0].disp.pos = ewk->wu.hit_quake;
        ewk->wu.mvxy.a[0].sp = 0;
        ewk->wu.mvxy.d[0].sp = 0;
        return 1;
    }

    return 0;
}

s32 Move_Y_Sub_38(WORK_Other* ewk, s16 Target_Y) {
    ewk->wu.xyz[1].cal += ewk->wu.mvxy.a[1].sp;
    ewk->wu.mvxy.a[1].sp += ewk->wu.mvxy.d[1].sp;

    if (0 > ewk->wu.mvxy.a[1].sp) {
        if (Target_Y >= ewk->wu.xyz[1].disp.pos) {
            ewk->wu.xyz[1].disp.pos = Target_Y;
            ewk->wu.mvxy.a[1].sp = 0;
            ewk->wu.mvxy.d[1].sp = 0;
            return 1;
        }
    } else if (Target_Y <= ewk->wu.xyz[1].disp.pos) {
        ewk->wu.xyz[1].disp.pos = Target_Y;
        ewk->wu.mvxy.a[1].sp = 0;
        ewk->wu.mvxy.d[1].sp = 0;
        return 1;
    }

    return 0;
}

void EFF38_MOVE(WORK_Other* ewk) {
    if (Order[ewk->wu.dir_old] != 5) {
        ewk->wu.routine_no[0] = Order[ewk->wu.dir_old];
        ewk->wu.routine_no[1] = 0;
        ewk->wu.routine_no[6] = 0;
        return;
    }

    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (Sel_PL_Complete[ewk->master_id] || plw[ewk->master_id].wu.operator == 0) {
            ewk->wu.routine_no[1] = 2;
        } else {
            ewk->wu.routine_no[1]++;
        }

        break;

    case 1:
        if (ewk->wu.dir_step != ID_of_Face[Cursor_Y[ewk->master_id]][Cursor_X[ewk->master_id]]) {
            ewk->wu.dir_step = ID_of_Face[Cursor_Y[ewk->master_id]][Cursor_X[ewk->master_id]];
            ewk->wu.xyz[0].disp.pos = bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos +
                                      EFF38_Base_XY[ewk->master_id][Play_Type][0] +
                                      EFF38_Correct_Data[ewk->master_id][Play_Type][ewk->wu.dir_step][0];
            ewk->wu.xyz[1].disp.pos = bg_w.bgw[ewk->wu.my_family - 1].wxy[1].disp.pos +
                                      EFF38_Base_XY[ewk->master_id][Play_Type][1] +
                                      EFF38_Correct_Data[ewk->master_id][Play_Type][ewk->wu.dir_step][1];

            if (ewk->master_id == 0 && ewk->wu.dir_step == 0) {
                ewk->wu.dir_step = 23;
            }

            set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
        }

        if (Sel_PL_Complete[ewk->master_id]) {
            ewk->wu.routine_no[1]++;
        }

        break;

    case 2:
        break;
    }
}

s32 effect_38_init(s16 PL_id, s16 dir_old, s16 Your_Char, s16 Play_Status, s16 Target_BG) {
    WORK_Other* ewk;
    s16 ix;

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }

    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 38;
    ewk->wu.work_id = 16;
    ewk->wu.my_col_code = 0x90;
    ewk->wu.my_family = Target_BG + 1;
    ewk->wu.xyz[1].disp.pos = bg_w.bgw[ewk->wu.my_family - 1].wxy[1].disp.pos + 16;
    ewk->wu.char_index = 2;
    *ewk->wu.char_table = _sel_pl_char_table;
    ewk->master_id = PL_id;
    ewk->wu.dir_old = Play_Status;
    ewk->wu.dir_old = dir_old;
    ewk->wu.vital_old = Your_Char;
    ewk->wu.my_mts = 13;
    ewk->wu.my_trans_mode = get_my_trans_mode(ewk->wu.my_mts);

    if (Your_Char == 0x7F) {
        ewk->wu.dir_step = ID_of_Face[Cursor_Y[ewk->master_id]][Cursor_X[ewk->master_id]];

        if (ewk->wu.dir_step == 0 && PL_id == 0) {
            ewk->wu.dir_step = 23;
        }
    } else {
        ewk->wu.dir_step = Your_Char;
    }

    ewk->wu.rl_flag = PL_id ^ 1;

    if (PL_id) {
        if (My_char[PL_id] == 21) {
            ewk->wu.dir_step++;
        }

        ewk->wu.xyz[0].disp.pos = bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos + 272;
        ewk->wu.position_z = 75;
        ewk->wu.mvxy.a[0].sp = -0xF0000;
        ewk->wu.mvxy.d[0].sp = -0x8000;
        ewk->wu.mvxy.d[1].sp = 0;

        if (Play_Status == 0) {
            ewk->wu.hit_quake = bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos + EFF38_Base_XY[ewk->master_id][0][0] +
                                EFF38_Correct_Data[ewk->master_id][0][ewk->wu.dir_step][0];
            ewk->wu.xyz[1].disp.pos = ewk->wu.vital_new = bg_w.bgw[ewk->wu.my_family - 1].wxy[1].disp.pos +
                                                          EFF38_Base_XY[ewk->master_id][0][1] +
                                                          EFF38_Correct_Data[ewk->master_id][0][ewk->wu.dir_step][1];
        } else {
            ewk->wu.hit_quake = bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos + EFF38_Base_XY[ewk->master_id][1][0] +
                                EFF38_Correct_Data[ewk->master_id][1][ewk->wu.dir_step][0];
            ewk->wu.xyz[1].disp.pos = ewk->wu.vital_new = bg_w.bgw[ewk->wu.my_family - 1].wxy[1].disp.pos +
                                                          EFF38_Base_XY[ewk->master_id][1][1] +
                                                          EFF38_Correct_Data[ewk->master_id][1][ewk->wu.dir_step][1];
        }
    } else {
        if (Your_Char != 0x7F && My_char[PL_id] == 0) {
            ewk->wu.dir_step = 0x17;
        }

        ewk->wu.xyz[0].disp.pos = bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos - 272;
        ewk->wu.position_z = 77;
        ewk->wu.mvxy.a[0].sp = 0xF0000;
        ewk->wu.mvxy.d[0].sp = 0x8000;
        ewk->wu.mvxy.d[1].sp = 0;

        if (Play_Status == 0) {
            ewk->wu.hit_quake = bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos + EFF38_Base_XY[ewk->master_id][0][0] +
                                EFF38_Correct_Data[ewk->master_id][0][ewk->wu.dir_step][0];
            ewk->wu.xyz[1].disp.pos = ewk->wu.vital_new = bg_w.bgw[ewk->wu.my_family - 1].wxy[1].disp.pos +
                                                          EFF38_Base_XY[ewk->master_id][0][1] +
                                                          EFF38_Correct_Data[ewk->master_id][0][ewk->wu.dir_step][1];
        } else {
            ewk->wu.hit_quake = bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos + EFF38_Base_XY[ewk->master_id][1][0] +
                                EFF38_Correct_Data[ewk->master_id][1][ewk->wu.dir_step][0];
            ewk->wu.xyz[1].disp.pos = ewk->wu.vital_new = bg_w.bgw[ewk->wu.my_family - 1].wxy[1].disp.pos +
                                                          EFF38_Base_XY[ewk->master_id][1][1] +
                                                          EFF38_Correct_Data[ewk->master_id][1][ewk->wu.dir_step][1];
        }
    }

    return 0;
}
