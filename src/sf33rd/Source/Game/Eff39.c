/* Eff39.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * effect_39_move 0x522DF size 0x30.
 * EFF39_SUDDENLY 0x52336 size 0x98.
 * EFF39_SLIDE_OUT 0x523CE size 0xA8.
 * effect_39_init 0x524AD size 0x110.
 * Get_Pos39 0x525BD size 0x31. Read against the x86: the table read is
 * Name_Pos_Data at 0x2676A8; data.txt gives Face_Pos_Data (0x267658) a size
 * that overruns it. Name_Pos_Data is 0x2676A8. The C is the PS2 C.
 * EFF39_SLIDE_IN 0x525EE size 0x167.
 * EFF39_MOVE 0x52755 size 0x127.
 * EFF39_KILL is folded into 0x52476 with 4 other bodies. Unnamed.
 * EFF39_WAIT is folded into 0x5230F with 2 other bodies. Unnamed.
 * Data: EFF39_Jmp_Tbl is 0x25BF10, 6 entries compared.
 * Globals: EFF39_Jmp_Tbl 0x25BF10, Name_Pos_Data 0x2676A8, _sel_pl_char_table
 * 0x2FE100, Play_Type 0x7A812D, Sel_PL_Complete 0x7A81BC, Cursor_X 0x7A81D4,
 * ID_of_Face 0x7A8240, Order 0x7A8380, Order_Timer 0x7A8480, Order_Dir
 * 0x7A85E0, Cursor_Y 0x7A8812, Select_Start 0x7A8A36, bg_w 0x7BC520, plw
 * 0xC7CEA0, frw 0xC806A0.
 */

#include "structs.h"

#define EFFECT_MAX 128

void EFF39_WAIT(WORK_Other* ewk);
void EFF39_SLIDE_IN(WORK_Other* ewk);
void EFF39_SLIDE_OUT(WORK_Other* ewk);
void EFF39_SUDDENLY(WORK_Other* ewk);
void EFF39_MOVE(WORK_Other* ewk);
void EFF39_KILL(WORK_Other* ewk);
s32 sort_push_request4(WORK* wk);
extern u8 Order[148];
extern u8 Order_Timer[148];
extern BG bg_w;
extern const s16 Name_Pos_Data[2][2][24][2];
void set_char_move_init2(WORK* wk, s16 koc, s16 index, s16 ip, s16 scf);
s32 Get_Pos39(WORK_Other* ewk, s16 Who, s16 Get_Type);
extern s8 Select_Start[2];
extern u8 Order_Dir[148];
s32 Ck_Range_Out_S(WORK_Other* ewk, s16 BG_No, s16 R);
void push_effect_work(WORK* wkhd);
extern s16 Sel_PL_Complete[2];
extern PLW plw[2];
extern s8 ID_of_Face[3][8];
extern s8 Cursor_Y[2];
extern s8 Cursor_X[2];
s32 chkNameAkuma(s32 plnum, s32 rnum);
s16 pull_effect_work(s16 index);
extern uintptr_t frw[EFFECT_MAX][448];
extern u32 _sel_pl_char_table[];
s16 get_my_trans_mode(s16 curr);
s32 chkNameSuv(s32 plnum, s32 rnum);
s32 effect_59_init(WORK_Other* mwk, s16 Synchro_BG, s16 ID, s16 direction);
extern u8 Play_Type;

void (*const EFF39_Jmp_Tbl[6])() = {
    EFF39_WAIT, EFF39_SLIDE_IN, EFF39_SLIDE_OUT, EFF39_SUDDENLY, EFF39_MOVE, EFF39_KILL
};

void effect_39_move(WORK_Other* ewk) {
    EFF39_Jmp_Tbl[ewk->wu.routine_no[0]](ewk);

    if (ewk->wu.be_flag != 0) {
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0xFFFF;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0xFFFF;
        sort_push_request4(&ewk->wu);
    }
}

void EFF39_WAIT(WORK_Other* ewk) {
    if ((ewk->wu.routine_no[0] = Order[ewk->wu.dir_old])) {
        ewk->wu.routine_no[1] = 0;
        ewk->wu.routine_no[6] = 0;
    }
}

void EFF39_SUDDENLY(WORK_Other* ewk) {
    if (--Order_Timer[ewk->wu.dir_old] != 0) {
        return;
    }

    ewk->wu.disp_flag = 1;
    Order[ewk->wu.dir_old] = 0;
    ewk->wu.routine_no[0] = 0;
    ewk->wu.routine_no[6] = 0;
    ewk->wu.xyz[0].disp.pos =
        bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos + Name_Pos_Data[ewk->master_id][1][ewk->wu.dir_step][0];
    ewk->wu.xyz[1].disp.pos =
        bg_w.bgw[ewk->wu.my_family - 1].wxy[1].disp.pos + Name_Pos_Data[ewk->master_id][1][ewk->wu.dir_step][1];
    set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
}

void EFF39_SLIDE_IN(WORK_Other* ewk) {
    if (Order[ewk->wu.dir_old] == 5) {
        ewk->wu.routine_no[0] = 5;
        ewk->wu.routine_no[1] = 0;
        return;
    }

    switch (ewk->wu.routine_no[6]) {
    case 0:
        if (--Order_Timer[ewk->wu.dir_old] != 0) {
            break;
        }

        ewk->wu.routine_no[6]++;
        ewk->wu.disp_flag = 1;

        if (ewk->master_id) {
            ewk->wu.mvxy.a[0].sp = -0xF0000;
            ewk->wu.mvxy.d[0].sp = 0;
            ewk->wu.hit_quake = bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos + Get_Pos39(ewk, ewk->wu.dir_step, 0);
            ewk->wu.xyz[0].disp.pos = ewk->wu.hit_quake + 256;
            ewk->wu.xyz[1].disp.pos =
                bg_w.bgw[ewk->wu.my_family - 1].wxy[1].disp.pos + Get_Pos39(ewk, ewk->wu.dir_step, 1);
        } else {
            ewk->wu.xyz[0].disp.pos = bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos - 272;
            ewk->wu.mvxy.a[0].sp = 0xF0000;
            ewk->wu.mvxy.d[0].sp = 0;
            ewk->wu.hit_quake = Get_Pos39(ewk, ewk->wu.dir_step, 0) + 512;
            ewk->wu.xyz[0].disp.pos = ewk->wu.hit_quake - 256;
            ewk->wu.xyz[1].disp.pos =
                bg_w.bgw[ewk->wu.my_family - 1].wxy[1].disp.pos + Get_Pos39(ewk, ewk->wu.dir_step, 1);
        }

        set_char_move_init2(&ewk->wu, 0, (s16)(ewk->wu.char_index), (ewk->wu.dir_step) + 1, 0);
        break;

    default:
        ewk->wu.xyz[0].cal += ewk->wu.mvxy.a[0].sp;
        ewk->wu.mvxy.a[0].sp += ewk->wu.mvxy.d[0].sp;

        if (0 < ewk->wu.mvxy.a[0].sp) {
            if (ewk->wu.hit_quake <= ewk->wu.xyz[0].disp.pos) {
                ewk->wu.routine_no[0] = 4;
                Order[ewk->wu.dir_old] = 4;
                ewk->wu.routine_no[6] = 0;
                ewk->wu.xyz[0].disp.pos = ewk->wu.hit_quake;

                if (--Select_Start[ewk->master_id] < 0) {
                    Select_Start[ewk->master_id] = 0;
                }
            }

            break;
        }

        if (ewk->wu.hit_quake >= ewk->wu.xyz[0].disp.pos) {
            ewk->wu.routine_no[0] = 4;
            Order[ewk->wu.dir_old] = 4;
            ewk->wu.routine_no[6] = 0;
            ewk->wu.xyz[0].disp.pos = ewk->wu.hit_quake;

            if (--Select_Start[ewk->master_id] < 0) {
                Select_Start[ewk->master_id] = 0;
            }
        }

        break;
    }
}

void EFF39_SLIDE_OUT(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[6]) {
    case 0:
        if (ewk->wu.disp_flag == 0) {
            ewk->wu.routine_no[1] = 99;
        } else {
            if (--Order_Timer[ewk->wu.dir_old]) {
                break;
            }

            ewk->wu.routine_no[6]++;
        }

        if (Order_Dir[ewk->wu.dir_old] == 4) {
            ewk->wu.mvxy.a[0].sp = -0xF0000;
            ewk->wu.mvxy.d[0].sp = 0;
        } else {
            ewk->wu.mvxy.a[0].sp = 0xF0000;
            ewk->wu.mvxy.d[0].sp = 0;
        }

        break;

    case 1:
        ewk->wu.xyz[0].cal += ewk->wu.mvxy.a[0].sp;
        ewk->wu.mvxy.a[0].sp += ewk->wu.mvxy.d[0].sp;

        if (Ck_Range_Out_S(ewk, ewk->wu.my_family - 1, 48)) {
            ewk->wu.routine_no[6]++;
            ewk->wu.disp_flag = 0;
        }

        break;

    default:
        push_effect_work(&ewk->wu);
        break;
    }
}

void EFF39_KILL(WORK_Other* ewk) {
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

void EFF39_MOVE(WORK_Other* ewk) {
    if (Order[ewk->wu.dir_old] != 4) {
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

        /* fallthrough */

    case 1:
        if (ewk->wu.dir_step != ID_of_Face[Cursor_Y[ewk->master_id]][Cursor_X[ewk->master_id]]) {
            ewk->wu.dir_step = ID_of_Face[Cursor_Y[ewk->master_id]][Cursor_X[ewk->master_id]];
            ewk->wu.dir_step += chkNameAkuma(ewk->wu.dir_step, 9);
            ewk->wu.xyz[0].disp.pos =
                bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos + Get_Pos39(ewk, ewk->wu.dir_step, 0);
            ewk->wu.xyz[1].disp.pos =
                bg_w.bgw[ewk->wu.my_family - 1].wxy[1].disp.pos + Get_Pos39(ewk, ewk->wu.dir_step, 1);
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

s32 effect_39_init(s16 PL_id, s16 dir_old, s16 Your_Char, s16 Target_BG, s16 Option) {
    WORK_Other* ewk;
    s16 ix;

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }

    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 39;
    ewk->wu.work_id = 16;
    ewk->wu.my_col_code = 0x2090;
    ewk->wu.my_family = Target_BG + 1;
    ewk->wu.position_z = 71;
    ewk->wu.char_index = 1;
    *ewk->wu.char_table = _sel_pl_char_table;
    ewk->master_id = PL_id;
    ewk->wu.dir_old = dir_old;
    ewk->wu.my_mts = 13;
    ewk->wu.my_trans_mode = get_my_trans_mode(ewk->wu.my_mts);

    if (Your_Char == 0x7F) {
        ewk->wu.dir_step = ID_of_Face[Cursor_Y[ewk->master_id]][Cursor_X[ewk->master_id]];
    } else {
        ewk->wu.dir_step = Your_Char;
    }

    ewk->wu.dir_step += chkNameAkuma(ewk->wu.dir_step, 9);
    ewk->wu.dir_step += chkNameSuv(ewk->wu.dir_step, 2);

    if (Option == 1) {
        effect_59_init(ewk, ewk->wu.my_family, 5, 1);
    }

    return 0;
}

s32 Get_Pos39(WORK_Other* ewk, s16 Who, s16 Get_Type) {
    return Name_Pos_Data[ewk->master_id][Play_Type][Who][Get_Type];
}
