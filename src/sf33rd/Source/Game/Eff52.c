/* Eff52.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * effect_52_move 0x52F38 size 0x30.
 * EFF52_SUDDENLY 0x52F68 size 0xBC.
 * EFF52_SLIDE_IN 0x53024 size 0xA5.
 * EFF52_SLIDE_OUT 0x530C9 size 0x9E.
 * Setup_Char_52 0x53167 size 0x8A. Read against the x86: the unnamed words are
 * a table at 0x267A50. The C is the PS2 C.
 * Setup_Pos_52 0x531F1 size 0xA5. Read against the x86: 0x15 is a 21-entry row
 * and the words a position table at 0x2679A8. The C is the PS2 C.
 * effect_52_init 0x53296 size 0xB5.
 * EFF52_KILL is folded into 0x52476 with 4 other bodies. Unnamed.
 * EFF52_WAIT is folded into 0x5230F with 2 other bodies. Unnamed.
 * Data: EFF52_Jmp_Tbl is 0x25BF28, 5 entries compared.
 * Unnamed data used (not checked): Setup_Char_52: 0x267a50,0x267a52;
 * Setup_Pos_52: 0x2679a8,0x2679aa.
 * Globals: EFF52_Jmp_Tbl 0x25BF28, _sel_pl_char_table 0x2FE100, Cursor_X
 * 0x7A81D4, ID_of_Face 0x7A8240, Order 0x7A8380, Order_Timer 0x7A8480,
 * Order_Dir 0x7A85E0, Cursor_Y 0x7A8812, Select_Start 0x7A8A36, frw 0xC806A0.
 */

#include "structs.h"

#define EFFECT_MAX 128

void EFF52_WAIT(WORK_Other* ewk);
void EFF52_SLIDE_IN(WORK_Other* ewk);
void EFF52_SLIDE_OUT(WORK_Other* ewk);
void EFF52_SUDDENLY(WORK_Other* ewk);
void EFF52_KILL(WORK_Other* ewk);
s32 sort_push_request4(WORK* wk);
extern u8 Order[148];
extern u8 Order_Timer[148];
void set_char_move_init2(WORK* wk, s16 koc, s16 index, s16 ip, s16 scf);
void char_move(WORK* wk);
extern s8 Select_Start[2];
extern u8 Order_Dir[148];
s32 Ck_Range_Out_S(WORK_Other* ewk, s16 BG_No, s16 R);
void push_effect_work(WORK* wkhd);
s16 pull_effect_work(s16 index);
extern uintptr_t frw[EFFECT_MAX][448];
extern u32 _sel_pl_char_table[];
s16 get_my_trans_mode(s16 curr);
void Setup_Char_52(WORK_Other* ewk);
void Setup_Pos_52(WORK_Other* ewk);
extern s8 ID_of_Face[3][8];
extern s8 Cursor_Y[2];
extern s8 Cursor_X[2];
s32 chkNameAkuma(s32 plnum, s32 rnum);
extern const s16 Pattern_Data_52[21][2];
extern const s16 Pos_Data_52[2][21][2];

void (*const EFF52_Jmp_Tbl[5])();

void (*const EFF52_Jmp_Tbl[5])() = { EFF52_WAIT, EFF52_SLIDE_IN, EFF52_SLIDE_OUT, EFF52_SUDDENLY, EFF52_KILL };

void effect_52_move(WORK_Other* ewk) {
    EFF52_Jmp_Tbl[ewk->wu.routine_no[0]](ewk);

    if (ewk->wu.be_flag != 0) {
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0xFFFF;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0xFFFF;
        sort_push_request4(&ewk->wu);
    }
}

void EFF52_WAIT(WORK_Other* ewk) {
    if ((ewk->wu.routine_no[0] = Order[ewk->wu.dir_old])) {
        ewk->wu.routine_no[1] = 0;
        ewk->wu.routine_no[6] = 0;
    }
}

void EFF52_SUDDENLY(WORK_Other* ewk) {
    s16 x;

    switch (ewk->wu.routine_no[6]) {
    case 0:
        if (--Order_Timer[ewk->wu.dir_old] != 0) {
            break;
        }

        ewk->wu.routine_no[6]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.position_z = 72;
        set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
        break;

    case 1:
        char_move(&ewk->wu);
        x = ewk->wu.cg_ix / ewk->wu.cgd_type;

        if (x < ewk->wu.direction) {
            break;
        }

        ewk->wu.routine_no[6]++;

    case 2:
        if (Select_Start[ewk->master_id] != 0) {
            break;
        }

        Order[ewk->wu.dir_old] = 4;
        ewk->wu.routine_no[0] = 4;
        ewk->wu.routine_no[1] = 0;
        Order_Timer[ewk->wu.dir_old] = 1;
        break;
    }
}

void EFF52_SLIDE_IN(WORK_Other* ewk) {
    if (Order[ewk->wu.dir_old] == 4) {
        ewk->wu.routine_no[0] = 4;
        ewk->wu.routine_no[1] = 0;
        return;
    }

    switch (ewk->wu.routine_no[6]) {
    case 0:
        if (--Order_Timer[ewk->wu.dir_old] == 0) {
            ewk->wu.routine_no[6]++;
            ewk->wu.disp_flag = 1;
            set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
        }

        break;

    default:
        ewk->wu.xyz[0].cal += ewk->wu.mvxy.a[0].sp;
        ewk->wu.mvxy.a[0].sp += ewk->wu.mvxy.d[0].sp;

        if (0 < ewk->wu.mvxy.a[0].sp) {
            if (ewk->wu.hit_quake <= ewk->wu.xyz[0].disp.pos) {
                ewk->wu.routine_no[0] = 0;
                Order[ewk->wu.dir_old] = 0;
                ewk->wu.routine_no[6] = 0;
                ewk->wu.xyz[0].disp.pos = ewk->wu.hit_quake;
            }
        } else if (ewk->wu.hit_quake >= ewk->wu.xyz[0].disp.pos) {
            ewk->wu.routine_no[0] = 0;
            Order[ewk->wu.dir_old] = 0;
            ewk->wu.routine_no[6] = 0;
            ewk->wu.xyz[0].disp.pos = ewk->wu.hit_quake;
        }

        break;
    }
}

void EFF52_SLIDE_OUT(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[6]) {
    case 0:
        if (ewk->wu.disp_flag == 0) {
            ewk->wu.routine_no[1] = 99;
        } else if (--Order_Timer[ewk->wu.dir_old]) {
            break;
        } else {
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

        if (Ck_Range_Out_S(ewk, 2, 128)) {
            ewk->wu.routine_no[6]++;
            ewk->wu.disp_flag = 0;
        }

        break;

    default:
        push_effect_work(&ewk->wu);
        break;
    }
}

void EFF52_KILL(WORK_Other* ewk) {
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

s32 effect_52_init(s16 PL_id, s16 dir_old) {
    WORK_Other* ewk;
    s16 ix;

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }

    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 52;
    ewk->wu.work_id = 16;
    ewk->wu.my_col_code = 0x2090;
    ewk->wu.my_family = 3;
    ewk->wu.dir_step = 1;
    *ewk->wu.char_table = _sel_pl_char_table;
    ewk->master_id = PL_id;
    ewk->wu.my_mts = 13;
    ewk->wu.my_trans_mode = get_my_trans_mode(ewk->wu.my_mts);
    ewk->wu.dir_old = dir_old;
    ewk->wu.dir_timer = Order_Timer[dir_old];
    ewk->wu.rl_flag = PL_id;
    ewk->wu.position_z = 74;
    Setup_Char_52(ewk);
    Setup_Pos_52(ewk);
    return 0;
}

void Setup_Char_52(WORK_Other* ewk) {
    s16 ix;

    if (ewk->wu.dir_old == 37) {
        ewk->wu.char_index = 16;
        return;
    }

    ewk->wu.char_index = 18;
    ewk->wu.dir_step = ID_of_Face[Cursor_Y[ewk->master_id]][Cursor_X[ewk->master_id]];
    ix = chkNameAkuma(ewk->wu.dir_step, 6);
    ewk->wu.dm_vital = Pattern_Data_52[ewk->wu.dir_step + ix][0];
    ewk->wu.direction = Pattern_Data_52[ewk->wu.dir_step + ix][1];
}

void Setup_Pos_52(WORK_Other* ewk) {
    s16 ix;

    if (ewk->wu.dir_old == 37) {
        ewk->wu.xyz[1].disp.pos = 208;

        if (ewk->master_id) {
            ewk->wu.xyz[0].disp.pos = 720;
            ewk->wu.hit_quake = 502;
            ewk->wu.mvxy.a[0].sp = -0x11FFFD;
            ewk->wu.mvxy.d[0].sp = -0x10000;
        } else {
            ewk->wu.xyz[0].disp.pos = 304;
            ewk->wu.hit_quake = 520;
            ewk->wu.mvxy.a[0].sp = 0x11FFFD;
            ewk->wu.mvxy.d[0].sp = 0x10000;
        }
    } else {
        ix = chkNameAkuma(ewk->wu.dir_step, 6);
        ewk->wu.xyz[0].disp.pos = Pos_Data_52[ewk->master_id][ewk->wu.dir_step + ix][0] + 512;
        ewk->wu.xyz[1].disp.pos = Pos_Data_52[ewk->master_id][ewk->wu.dir_step + ix][1] + 0;
    }
}
