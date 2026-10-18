/* Eff76.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * EFF76_WAIT_BREAK_INTO 0x5383A size 0x5E.
 * EFF76_SLIDE_IN 0x53898 size 0xB2.
 * EFF76_SUDDENLY 0x5394A size 0x146. FLAG: x86-only offsets -0xb1,-0x81.
 * EFF76_BEFORE 0x53A90 size 0x55.
 * EFF76_SHIFT 0x53AE5 size 0x99.
 * Setup_Color_76 0x53BAC size 0x48. FLAG: x86-only constants 0x23e.
 * Setup_Color_L1 0x53BF4 size 0x42. FLAG: x86-only constants 0x23e.
 * chkNameAkuma 0x53C36 size 0x20.
 * EFF76_WAIT 0x53C56 size 0x92.
 * Setup_Pos_76 0x53CE8 size 0x498. FLAG: x86-only offsets -0xb1,-0x4a,-0x2b.
 * Setup_Char_76 0x541AB size 0x3A6. FLAG: x86-only offsets -0x3b,-0x2b.
 * effect_76_init 0x5457C size 0x9E.
 * EFF76_SLIDE_OUT is folded into 0x4384A with 48 other bodies. Unnamed.
 * Not located in sf33rd.xbe; their PS2 C is kept under #if 0: effect_76_move,
 * Check_Range_Out.
 * Check_Range_Out stays sub_00053B7E, the one unnamed call left in its caller.
 * Data: EFF76_Jmp_Tbl is 0x25C018, 8 entries compared.
 * Unnamed data used (not checked): EFF76_SUDDENLY: 0x267d92,0x267eaa;
 * Setup_Color_76: 0x267f60; Setup_Color_L1: 0x267f60; Setup_Pos_76:
 * 0x267d90,0x267d92,0x267d94,0x267d9c,0x267d9e,0x267da0,0x267e30,0x267e32;
 * effect_76_init: 0x267ec2.
 * Globals: Name_Cover_Pos_Data 0x267828, _sel_pl_char_table 0x2FE100, My_char
 * 0x7A8114, Perfect_Flag 0x7A812C, Suicide 0x7A8268, Order 0x7A8380, Winner_id
 * 0x7A8472, Order_Timer 0x7A8480, Order_Dir 0x7A85E0, Next_Step 0x7A86D2,
 * Country 0x7A8748, Final_Result_id 0x7A8750, Champion 0x7A8931, base_y_pos
 * 0x7BC516, bg_w 0x7BC520, Ranking_Data 0xC7C840, frw 0xC806A0.
 */

#include "structs.h"

#define EFFECT_MAX 128

s16 sub_00053B7E(WORK_Other* ewk);
void EFF76_WAIT(WORK_Other* ewk);
void EFF76_SLIDE_IN(WORK_Other* ewk);
void EFF76_SLIDE_OUT(WORK_Other* );
void EFF76_SUDDENLY(WORK_Other* ewk);
void EFF57_KILL(WORK_Other* ewk);
void EFF76_SHIFT(WORK_Other* ewk);
void EFF76_WAIT_BREAK_INTO(WORK_Other* ewk);
void EFF76_BEFORE(WORK_Other* ewk);
extern u8 Order[148];
extern u8 Order_Timer[148];
extern s8 Suicide[8];
void set_char_move_init2(WORK* wk, s16 koc, s16 index, s16 ip, s16 scf);
s32 Ck_Range_Out_S(WORK_Other* ewk, s16 BG_No, s16 R);
extern s8 Next_Step;
extern BG bg_w;
extern const s16 Pos_Cont_Data_76[][3];
extern const s16 Pos_Data_76[][3];
s32 Cut_Cut_Sub(s16 xx);
s16 pull_effect_work(s16 index);
extern uintptr_t frw[EFFECT_MAX][448];
extern u32 _sel_pl_char_table[];
s16 get_my_trans_mode(s16 curr);
extern const s16 Width_Data_76[];
void Setup_Char_76(WORK_Other* ewk);
void Setup_Pos_76(WORK_Other* ewk);
extern const s16 Bust_Pos_Data_76[20][2];
extern u8 My_char[2];
extern u8 Final_Result_id;
extern u8 Order_Dir[148];
s32 chkNameAkuma(s32 plnum, s32 rnum);
extern s8 Champion;
extern const s16 Name_Cover_Pos_Data[2][2][24][2];
extern s8 Winner_id;
extern RANK_DATA Ranking_Data[20];
extern s8 Perfect_Flag;
extern const s16 Compute_Pos_Data_76[2][6][3];
extern s16 base_y_pos;
void Setup_Color_76(WORK_Other* ewk);
s32 effect_A6_init(WORK_Other* mwk);
s16 grade_get_my_grade(s16 ix);
extern const u8 Victory_Color_Data[20];
extern u8 Country;

void (*const EFF76_Jmp_Tbl[8])() = { EFF76_WAIT, EFF76_SLIDE_IN, EFF76_SLIDE_OUT,       EFF76_SUDDENLY,
                                     EFF57_KILL, EFF76_SHIFT,    EFF76_WAIT_BREAK_INTO, EFF76_BEFORE };

void EFF76_WAIT(WORK_Other* ewk) {
    if (sub_00053B7E(ewk)) {
        Order[ewk->wu.dir_old] = 4;
        ewk->wu.routine_no[0] = 4;
        ewk->wu.routine_no[1] = 0;
        Order_Timer[ewk->wu.dir_old] = 1;
    } else if (Suicide[ewk->wu.direction] != 0) {
        Order[ewk->wu.dir_old] = 4;
        ewk->wu.routine_no[0] = 4;
        ewk->wu.routine_no[1] = 1;
        Order_Timer[ewk->wu.dir_old] = 1;
        ewk->wu.disp_flag = 0;
    } else if ((ewk->wu.routine_no[0] = Order[ewk->wu.dir_old])) {
        ewk->wu.routine_no[1] = 0;
    }
}

void EFF76_WAIT_BREAK_INTO(WORK_Other* ewk) {
    if (Suicide[ewk->wu.direction] != 0) {
        Order[ewk->wu.dir_old] = 4;
        ewk->wu.routine_no[0] = 4;
        ewk->wu.routine_no[1] = 1;
        Order_Timer[ewk->wu.dir_old] = 1;
        ewk->wu.disp_flag = 0;
    } else if ((ewk->wu.routine_no[0] = Order[ewk->wu.dir_old])) {
        ewk->wu.routine_no[1] = 0;
    }
}

void EFF76_SLIDE_IN(WORK_Other* ewk) {
    if (Order[ewk->wu.dir_old] != 1) {
        ewk->wu.routine_no[0] = Order[ewk->wu.dir_old];
        ewk->wu.routine_no[1] = 0;
        return;
    }

    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (!--Order_Timer[ewk->wu.dir_old]) {
            ewk->wu.routine_no[1]++;
            ewk->wu.disp_flag = 1;
            set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
        }

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

void EFF76_SLIDE_OUT(WORK_Other* /* unused */) {
    // Do nothing
}

void EFF76_SUDDENLY(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (--Order_Timer[ewk->wu.dir_old] == 0) {
            ewk->wu.routine_no[1]++;
            ewk->wu.disp_flag = 0;
        }

        /* fallthrough */

    case 1:
        if (Ck_Range_Out_S(ewk, ewk->wu.my_family - 1, ewk->wu.dm_vital)) {
            break;
        }

        ewk->wu.disp_flag = 1;

        switch (ewk->wu.dir_old) {
        case 0x3D:
            ewk->wu.routine_no[1] = 2;
            break;

        case 0x42:
            ewk->wu.routine_no[1] = 3;
            break;

        default:
            ewk->wu.routine_no[0] = 0;
            Order[ewk->wu.dir_old] = 0;
            break;
        }

        set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
        break;

    case 2:
        if (Next_Step) {
            ewk->wu.my_family = 1;
            ewk->wu.xyz[0].disp.pos = bg_w.bgw[0].wxy[0].disp.pos;
            ewk->wu.xyz[1].disp.pos = bg_w.bgw[0].wxy[1].disp.pos + Pos_Cont_Data_76[ewk->wu.dir_old - 59][1];
            ewk->wu.routine_no[0] = 0;
            Order[ewk->wu.dir_old] = 0;
        }

        break;

    case 3:
        if (Next_Step) {
            ewk->wu.my_family = 4;
            ewk->wu.xyz[0].disp.pos = bg_w.bgw[3].wxy[0].disp.pos - 8;
            ewk->wu.xyz[1].disp.pos = bg_w.bgw[3].wxy[1].disp.pos + Pos_Data_76[ewk->wu.dir_old - 43][1];
            ewk->wu.routine_no[0] = 0;
            Order[ewk->wu.dir_old] = 0;
        }

        break;
    }
}

void EFF76_BEFORE(WORK_Other* ewk) {
    if (--Order_Timer[ewk->wu.dir_old] != 0) {
        return;
    }

    ewk->wu.routine_no[1]++;
    ewk->wu.disp_flag = 1;
    ewk->wu.position_z = 8;
    ewk->wu.routine_no[0] = 0;
    ewk->wu.routine_no[1] = 0;
    Order[ewk->wu.dir_old] = 0;
    set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
}

void EFF76_SHIFT(WORK_Other* ewk) {
    s16 cut;

    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (--Order_Timer[ewk->wu.dir_old] == 0) {
            ewk->wu.routine_no[1]++;
            ewk->wu.hit_quake = ewk->wu.xyz[0].disp.pos - 160;
            ewk->wu.mvxy.a[0].sp = -0x60000;
            ewk->wu.mvxy.d[0].sp = -0x4000;
        }

        break;

    case 1:
        cut = Cut_Cut_Sub(3);
        ewk->wu.xyz[0].cal += ewk->wu.mvxy.a[0].sp * cut;
        ewk->wu.mvxy.a[0].sp += ewk->wu.mvxy.d[0].sp;

        if (ewk->wu.hit_quake >= ewk->wu.xyz[0].disp.pos) {
            ewk->wu.routine_no[0] = 0;
            Order[ewk->wu.dir_old] = 0;
            ewk->wu.xyz[0].disp.pos = ewk->wu.hit_quake;
        }

        break;
    }
}

s32 effect_76_init(s16 dir_old) {
    WORK_Other* ewk;
    s16 ix;

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }

    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 76;
    ewk->wu.work_id = 16;
    ewk->wu.my_col_code = 0x2090;
    ewk->wu.my_family = 3;
    *ewk->wu.char_table = _sel_pl_char_table;
    ewk->wu.my_mts = 13;
    ewk->wu.my_trans_mode = get_my_trans_mode(ewk->wu.my_mts);
    ewk->wu.dir_old = dir_old;
    ewk->wu.direction = 2;
    ewk->wu.dm_vital = Width_Data_76[dir_old - 43];
    Setup_Char_76(ewk);
    Setup_Pos_76(ewk);
    return 0;
}

void Setup_Pos_76(WORK_Other* ewk) {
    s16 ix;
    u8 my_char;

    switch (ewk->wu.dir_old) {
    case 0x2B:
    case 0x2C:
    case 0x2E:
    case 0x2F:
    case 0x30:
    case 0x31:
    case 0x32:
    case 0x33:
    case 0x34:
    case 0x35:
    case 0x36:
    case 0x38:
    case 0x39:
    case 0x3A:
    case 0x40:
    case 0x42:
        ewk->wu.xyz[0].disp.pos =
            bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos + Pos_Data_76[ewk->wu.dir_old - 0x2B][0];
        ewk->wu.xyz[1].disp.pos =
            bg_w.bgw[ewk->wu.my_family - 1].wxy[1].disp.pos + Pos_Data_76[ewk->wu.dir_old - 0x2B][1];
        ewk->wu.position_z = Pos_Data_76[ewk->wu.dir_old - 0x2B][2];
        break;

    case 0x41:
        ewk->wu.xyz[0].disp.pos = bg_w.bgw[0].wxy[0].disp.pos + Bust_Pos_Data_76[My_char[Final_Result_id]][0];
        ewk->wu.xyz[1].disp.pos = bg_w.bgw[0].wxy[1].disp.pos + Bust_Pos_Data_76[My_char[Final_Result_id]][1];
        ewk->wu.position_z = 72;
        break;

    case 0x3B:
    case 0x3C:
    case 0x3D:
    case 0x3E:
    case 0x3F:
        ewk->wu.xyz[0].disp.pos = bg_w.bgw[1].wxy[0].disp.pos + 458 + Pos_Cont_Data_76[ewk->wu.dir_old - 0x3B][0];
        ewk->wu.xyz[1].disp.pos = bg_w.bgw[1].wxy[1].disp.pos + Pos_Cont_Data_76[ewk->wu.dir_old - 0x3B][1];
        ewk->wu.position_z = Pos_Cont_Data_76[ewk->wu.dir_old - 0x3B][2];
        break;

    case 0x43:
    case 0x44:
        ewk->wu.xyz[0].disp.pos =
            bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos + Pos_Data_76[ewk->wu.dir_old - 0x2B][0];
        ewk->wu.xyz[1].disp.pos =
            bg_w.bgw[ewk->wu.my_family - 1].wxy[1].disp.pos + Pos_Data_76[ewk->wu.dir_old - 0x2B][1];
        ewk->wu.position_z = Pos_Data_76[ewk->wu.dir_old - 0x2B][2];

        if (Order_Dir[ewk->wu.dir_old] == 4) {
            ewk->wu.hit_quake = bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos + 64;
            ewk->wu.mvxy.a[0].sp = -0x100000;
            ewk->wu.mvxy.d[0].sp = 0;
        } else {
            ewk->wu.hit_quake = bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos - 64;
            ewk->wu.mvxy.a[0].sp = 0x100000;
            ewk->wu.mvxy.d[0].sp = 0;
        }

        break;

    case 0x2D:
        ewk->wu.xyz[0].disp.pos =
            bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos + Pos_Data_76[ewk->wu.dir_old - 0x2B][0];
        ewk->wu.xyz[1].disp.pos =
            bg_w.bgw[ewk->wu.my_family - 1].wxy[1].disp.pos + Pos_Data_76[ewk->wu.dir_old - 0x2B][1];
        ewk->wu.position_z = Pos_Data_76[ewk->wu.dir_old - 0x2B][2];

        if (Order_Dir[ewk->wu.dir_old] == 4) {
            ewk->wu.hit_quake = bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos + 32;
            ewk->wu.mvxy.a[0].sp = -0x100000;
            ewk->wu.mvxy.d[0].sp = 0;
        } else {
            ewk->wu.hit_quake = bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos - 32;
            ewk->wu.mvxy.a[0].sp = 0x100000;
            ewk->wu.mvxy.d[0].sp = 0;
        }

        break;

    case 0x48:
        ix = chkNameAkuma(My_char[Champion], 9);
        ewk->wu.xyz[0].disp.pos = bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos +
                                  Name_Cover_Pos_Data[Champion][1][My_char[Champion] + ix][0];
        ewk->wu.xyz[1].disp.pos = bg_w.bgw[ewk->wu.my_family - 1].wxy[1].disp.pos +
                                  Name_Cover_Pos_Data[Champion][1][My_char[Champion] + ix][1];
        ewk->wu.position_z = 70;

        if (Champion == 0) {
            ewk->wu.xyz[0].disp.pos += 24;
        } else {
            ewk->wu.xyz[0].disp.pos -= 24;
        }

        break;

    case 0x49:
        ix = chkNameAkuma(My_char[Champion], 9);
        ewk->wu.xyz[0].disp.pos = bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos +
                                  Name_Cover_Pos_Data[Champion][1][My_char[Champion] + ix][0];
        ewk->wu.xyz[1].disp.pos = bg_w.bgw[ewk->wu.my_family - 1].wxy[1].disp.pos +
                                  Name_Cover_Pos_Data[Champion][1][My_char[Champion] + ix][1] - 2;
        ewk->wu.position_z = 69;

        if (Champion == 0) {
            ewk->wu.xyz[0].disp.pos += 23;
        } else {
            ewk->wu.xyz[0].disp.pos -= 25;
        }

        break;

    case 0x37:
    case 0x55:
        if (ewk->wu.dir_old == 0x37) {
            my_char = My_char[Winner_id];
        } else {
            my_char = Ranking_Data[Order_Dir[ewk->wu.dir_old]].player;
        }

        ewk->wu.xyz[0].disp.pos = bg_w.bgw[0].wxy[0].disp.pos + Bust_Pos_Data_76[my_char][0] - 48;
        ewk->wu.hit_quake = bg_w.bgw[0].wxy[0].disp.pos + Bust_Pos_Data_76[my_char][0];
        ewk->wu.xyz[1].disp.pos = bg_w.bgw[0].wxy[1].disp.pos + Bust_Pos_Data_76[my_char][1];

        if (ewk->wu.dir_old == 0x37) {
            ewk->wu.position_z = 72;
            ewk->wu.mvxy.a[0].sp = 0x10000;
            ewk->wu.mvxy.d[0].sp = 0;
            break;
        }
        ewk->wu.xyz[1].disp.pos = bg_w.bgw[0].wxy[1].disp.pos + Bust_Pos_Data_76[my_char][1] - 32;

        if (Order[ewk->wu.dir_old] == 1) {
            ewk->wu.xyz[0].disp.pos = bg_w.bgw[0].wxy[0].disp.pos + Bust_Pos_Data_76[my_char][0] + 384;
        }

        ewk->wu.position_z = 79;
        ewk->wu.mvxy.a[0].sp = -0xA0000;
        ewk->wu.mvxy.d[0].sp = 0;
        break;

    case 0x4A:
    case 0x4B:
    case 0x4C:
    case 0x4D:
    case 0x4E:
    case 0x4F:
        if (Perfect_Flag) {
            ix = 1;
        } else {
            ix = 0;
        }

        ewk->wu.my_mts = 14;
        ewk->wu.my_trans_mode = get_my_trans_mode(ewk->wu.my_mts);
        ewk->wu.hit_quake =
            bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos + Compute_Pos_Data_76[ix][Order_Dir[ewk->wu.dir_old]][0];
        ewk->wu.xyz[0].disp.pos = ewk->wu.hit_quake + 0x1A0;
        ewk->wu.xyz[1].disp.pos = bg_w.bgw[ewk->wu.my_family - 1].wxy[1].disp.pos +
                                  Compute_Pos_Data_76[ix][Order_Dir[ewk->wu.dir_old]][1] + base_y_pos;
        ewk->wu.position_z = Compute_Pos_Data_76[ix][ewk->wu.dir_old - 0x4A][2];
        ewk->wu.mvxy.a[0].sp = -0x18000;
        ewk->wu.mvxy.d[0].sp = -0x28000;
        break;
    }
}

void Setup_Char_76(WORK_Other* ewk) {
    switch (ewk->wu.dir_old) {
    case 0x38:
    case 0x42:
        ewk->wu.my_family = 1;
        ewk->wu.direction = 0;
        ewk->wu.my_col_code = 1;
        ewk->wu.my_clear_level = 0x80;
        ewk->wu.shell_ix[0] = -0xC8;
        ewk->wu.shell_ix[1] = 0x192;
        ewk->wu.shell_ix[2] = -0x10;
        ewk->wu.shell_ix[3] = 0x110;
        break;

    case 0x39:
        ewk->wu.char_index = 4;
        ewk->wu.dir_step = 7;
        Setup_Color_76(ewk);
        break;

    case 0x3A:
        ewk->wu.my_col_code = 0x1FF;
        ewk->wu.my_clear_level = 0x80;
        ewk->wu.char_index = 4;
        ewk->wu.dir_step = 8;
        break;

    case 0x36:
        ewk->wu.my_family = 1;
        /* fallthrough */

    case 0x34:
        ewk->wu.my_col_code = 0x1FF;
        ewk->wu.my_clear_level = 0x80;
        ewk->wu.char_index = 9;
        ewk->wu.dir_step = My_char[Winner_id] + 0x15;
        ewk->wu.dir_step += chkNameAkuma(My_char[Winner_id], 6);
        break;

    case 0x2D:
        ewk->wu.my_col_mode = 0x4400;
        ewk->wu.my_family = 1;
        ewk->wu.my_col_code = 0x1FF;
        ewk->wu.my_clear_level = 0x80;
        ewk->wu.char_index = 4;
        ewk->wu.dir_step = ewk->wu.dir_old - 0x2B;
        break;

    case 0x30:
    case 0x31:
        ewk->wu.my_col_mode = 0x4400;
        ewk->wu.my_family = 1;
        ewk->wu.my_col_code = 0x1FB;
        ewk->wu.my_clear_level = 0x80;
        ewk->wu.char_index = 4;
        ewk->wu.dir_step = ewk->wu.dir_old - 0x2B;
        break;

    case 0x43:
    case 0x44:
        ewk->wu.my_family = 1;
        ewk->wu.my_col_code = 0x1FF;
        ewk->wu.my_clear_level = 0x80;
        ewk->wu.char_index = 4;
        ewk->wu.dir_step = 2;
        ewk->wu.direction = 3;
        effect_A6_init(ewk);
        break;

    case 0x2E:
    case 0x2F:
        ewk->wu.my_family = 1;
        ewk->wu.char_index = 4;
        ewk->wu.dir_step = ewk->wu.dir_old - 0x2B;
        Setup_Color_76(ewk);
        break;

    case 0x2B:
    case 0x2C:
        ewk->wu.char_index = 4;
        ewk->wu.dir_step = ewk->wu.dir_old - 0x2B;
        Setup_Color_76(ewk);
        break;

    case 0x37:
    case 0x55:
        ewk->wu.my_family = 1;
        ewk->wu.my_col_code = 0x90;
        ewk->wu.char_index = 2;
        ewk->wu.direction = 3;

        if (ewk->wu.dir_old == 0x37) {
            ewk->wu.dir_step = My_char[Winner_id];
        } else {
            ewk->wu.dir_step = Ranking_Data[Order_Dir[ewk->wu.dir_old]].player;
            ewk->wu.direction = 7;
        }

        break;

    case 0x41:
        ewk->wu.my_family = 1;
        ewk->wu.my_col_code = 0x90;
        ewk->wu.char_index = 2;
        ewk->wu.dir_step = My_char[Final_Result_id];
        ewk->wu.direction = 0;
        break;

    case 0x40:
        ewk->wu.my_family = 1;
        /* fallthrough */

    case 0x35:
        ewk->wu.char_index = 9;
        ewk->wu.dir_step = My_char[Winner_id];
        ewk->wu.dir_step += chkNameAkuma(My_char[Winner_id], 6);
        Setup_Color_76(ewk);
        break;

    case 0x3D:
        ewk->wu.my_mr_flag = 1;
        ewk->wu.my_mr.size.x = 0x5F;
        ewk->wu.my_mr.size.y = 0x3F;
        ewk->wu.my_family = 2;
        ewk->wu.char_index = 0x53;
        ewk->wu.dir_step = ewk->wu.dir_old - 0x3B;
        /* fallthrough */

    case 0x3B:
    case 0x3C:
    case 0x3E:
    case 0x3F:
        ewk->wu.direction = 3;
        ewk->wu.my_family = 2;
        ewk->wu.char_index = 0x53;
        ewk->wu.dir_step = ewk->wu.dir_old - 0x3B;
        break;

    case 0x32:
    case 0x33:
        ewk->wu.my_family = 1;
        ewk->wu.char_index = 0x56;
        ewk->wu.dir_step = ewk->wu.dir_old - 0x32;
        ewk->wu.direction = 7;
        break;

    case 0x48:
        ewk->wu.my_family = 3;
        ewk->wu.char_index = 0x50;
        ewk->wu.dir_step = grade_get_my_grade(Champion);
        break;

    case 0x49:
        ewk->wu.my_family = 3;
        ewk->wu.char_index = 0x10;
        ewk->wu.dir_step = 8;
        break;

    case 0x4A:
    case 0x4B:
    case 0x4C:
    case 0x4D:
    case 0x4E:
    case 0x4F:
        ewk->wu.my_family = 2;
        ewk->wu.my_col_code = 0x2052;
        ewk->wu.char_index = 0x3D;
        ewk->wu.dir_step = ewk->wu.dir_old - 0x4A;
        break;
    }
}

void Setup_Color_76(WORK_Other* ewk) {
    ewk->wu.my_col_code = Victory_Color_Data[My_char[Winner_id]] + 0x2000;
    ewk->wu.my_col_code = Victory_Color_Data[My_char[Winner_id]] + 0x2090;
}

void Setup_Color_L1(WORK_Other* ewk) {
    ewk->wu.my_col_code = Victory_Color_Data[My_char[Winner_id]];
    ewk->wu.my_col_code = Victory_Color_Data[My_char[Winner_id]] + 0x90;
}

/* Notes from the hand port this file replaced:
 * Country is the byte at 0x7A8748. The character test is the dword 14.
 * A character of 20 with the same country test is a different function.
 */

s32 chkNameAkuma(s32 plnum, s32 rnum) {
    if (plnum == 14 && (Country == 4 || Country == 2 || Country == 3)) {
        return rnum;
    }

    return 0;
}

#if 0
/* PS2 C for functions not located in sf33rd.xbe yet. */

void effect_76_move(WORK_Other* ewk) {
    EFF76_Jmp_Tbl[ewk->wu.routine_no[0]](ewk);

    if (ewk->wu.be_flag == 0) {
        return;
    }

    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos;
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos;

    switch (ewk->wu.dir_old) {
    case 0x38:
    case 0x42:
        sort_push_requestA(&ewk->wu);
        break;

    case 0x30:
        Check_Pos_OBJ(ewk);
        /* fallthrough */

    default:
        sort_push_request4(&ewk->wu);
        break;
    }
}

s16 Check_Range_Out(WORK_Other* ewk) {
    if (ewk->wu.disp_flag == 0) {
        return 0;
    }

    return Ck_Range_Out_S(ewk, ewk->wu.my_family - 1, ewk->wu.dm_vital);
}
#endif
