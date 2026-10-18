/* EFF45.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * effect_45_move 0x3C89B size 0x78.
 * EFF45_DISP 0x3C913 size 0x2A.
 * EFF45_SUSPEND 0x3C93D size 0x48.
 * Centering_Sub 0x3C985 size 0x94. Read against the x86: -2 is a lea step in
 * the centering arithmetic. The C is the PS2 C.
 * Convert_16_10_2 0x3CA19 size 0x18.
 * Convert_16_10_3 0x3CA31 size 0x27.
 * Check_Pig_Pig 0x3CA58 size 0x1A1.
 * Setup_Message 0x3CBF9 size 0xC4.
 * EFF45_CHANGE 0x3CCBD size 0x69.
 * effect_45_init 0x3CD26 size 0x94.
 * Data: Message_Data: defined elsewhere on Xbox.
 * Data: EFF45_Jmp_Tbl is 0x24E360, 3 entries compared.
 * Unnamed data used (not a difference): EFF45_SUSPEND:
 * 0xcb8800,0xcb8803,0xcb8804; Check_Pig_Pig: 0xcb8803; Setup_Message:
 * 0xcb8803,0xcb8804,0xcb8801,0xcb8802,0xcb8806,0xcb8808,0xcb880a;
 * effect_45_move: 0xcb8800; effect_45_init: 0xcb8804,0xcb8800; EFF45_DISP:
 * 0xcb8800; EFF45_CHANGE: 0xcb8805,0xcb8800.
 * Globals: EFF45_Jmp_Tbl 0x24E360, bg_w 0x7BC520, vm_w 0x7C5580, frw 0xC806A0.
 */

#include "structs.h"

#define EFFECT_MAX 128

void EFF45_DISP(WORK_Other_CONN* ewk);
void EFF45_CHANGE(WORK_Other_CONN* ewk);
void EFF45_SUSPEND(WORK_Other_CONN* ewk);
void Check_Pos_OBJ2(WORK_Other* ewk);
s32 Check_Die_61(WORK_Other* ewk);
void push_effect_work(WORK* wkhd);
s32 sort_push_request3(WORK* wk);
void Setup_Message(WORK_Other_CONN* ewk);
s16 pull_effect_work(s16 index);
extern uintptr_t frw[EFFECT_MAX][448];
extern s8 Debug_w[72];
void get_message_conn_data(WORK_Other_CONN* ewk, s16 kind, s16 pl, s16 msg);
extern BG bg_w;
s16 Centering_Sub(WORK_Other_CONN* ewk, s16 dot_type);
void Check_Pig_Pig(WORK_Other_CONN* ewk);
void Convert_16_10_2(WORK_Other_CONN* ewk, u16 target);
extern struct _VM_W vm_w;

extern MessageData Message_Data[4];

void (*const EFF45_Jmp_Tbl[3])() = { EFF45_DISP, EFF45_CHANGE, EFF45_SUSPEND };

void effect_45_move(WORK_Other_CONN* ewk) {
    Check_Pos_OBJ2((WORK_Other*)ewk);

    if (Check_Die_61((WORK_Other*)ewk) != 0 || Message_Data[ewk->wu.dir_old].order == 3) {
        push_effect_work(&ewk->wu);
        return;
    }

    if (ewk->wu.routine_no[0] != Message_Data[ewk->wu.dir_old].order) {
        ewk->wu.routine_no[0] = Message_Data[ewk->wu.dir_old].order;
        ewk->wu.routine_no[1] = 0;
    }

    EFF45_Jmp_Tbl[ewk->wu.routine_no[0]](ewk);

    if (ewk->wu.be_flag != 0) {
        ewk->wu.dir_step = Message_Data[ewk->wu.dir_old].order;
        sort_push_request3(&ewk->wu);
    }
}

void EFF45_DISP(WORK_Other_CONN* ewk) {
    ewk->wu.disp_flag = 1;

    if ((ewk->wu.routine_no[0] = Message_Data[ewk->wu.dir_old].order)) {
        ewk->wu.routine_no[1] = 0;
    }
}

void EFF45_SUSPEND(WORK_Other_CONN* ewk) {
    ewk->wu.disp_flag = 0;

    if (Message_Data[ewk->wu.dir_old].order != 2) {
        ewk->wu.routine_no[0] = Message_Data[ewk->wu.dir_old].order;
        ewk->wu.routine_no[1] = 0;
    } else {
        Message_Data[ewk->wu.dir_old].request = 0xFF;
        Message_Data[ewk->wu.dir_old].contents = 0xFF;
    }
}

void EFF45_CHANGE(WORK_Other_CONN* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 0;
        break;

    case 1:
        if (--Message_Data[ewk->wu.dir_old].timer == 0) {
            ewk->wu.disp_flag = 1;
            ewk->wu.routine_no[0] = 0;
            Setup_Message(ewk);
            Message_Data[ewk->wu.dir_old].order = 0;
        }

        break;
    }
}

s32 effect_45_init(u8 id, s16 sync_bg, s16 master_player) {
    WORK_Other_CONN* ewk;
    s16 ix;

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }

    ewk = (WORK_Other_CONN*)frw[ix];
    ewk->wu.routine_no[0] = 0;
    ewk->wu.be_flag = 1;
    ewk->wu.disp_flag = 0;
    ewk->wu.id = 45;
    ewk->wu.work_id = 16;
    ewk->wu.rl_flag = 0;
    ewk->wu.my_col_code = 0x1AC;
    ewk->wu.my_family = sync_bg + 1;
    ewk->master_player = master_player;
    ewk->wu.dir_old = id;
    Message_Data[ewk->wu.dir_old].contents = 0xFF;
    ewk->wu.routine_no[0] = Message_Data[ewk->wu.dir_old].order;
    ewk->wu.my_mts = 12;
    Setup_Message(ewk);
    return 0;
}

void Setup_Message(WORK_Other_CONN* ewk) {
    Message_Data[ewk->wu.dir_old].contents = Message_Data[ewk->wu.dir_old].request;
    Message_Data[ewk->wu.dir_old].kind_cnt = Message_Data[ewk->wu.dir_old].kind_req;

    if (Debug_w[68]) {
        Message_Data[ewk->wu.dir_old].request = Debug_w[68] - 1;
        Message_Data[ewk->wu.dir_old].contents = Debug_w[68] - 1;
    }

    get_message_conn_data(ewk, Message_Data[ewk->wu.dir_old].kind_cnt, 0, Message_Data[ewk->wu.dir_old].request + 0);
    ewk->wu.position_x = bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos + Message_Data[ewk->wu.dir_old].pos_x;
    ewk->wu.position_x -= Centering_Sub(ewk, 16);
    ewk->wu.position_y = bg_w.bgw[ewk->wu.my_family - 1].wxy[1].disp.pos + Message_Data[ewk->wu.dir_old].pos_y;
    ewk->wu.position_z = Message_Data[ewk->wu.dir_old].pos_z;
    Check_Pig_Pig(ewk);
}

s16 Centering_Sub(WORK_Other_CONN* ewk, s16 dot_type) {
    s16 i;
    s16 ix;
    s16 ny;
    s16 len;
    s16 max;

    dot_type /= 2;
    max = dot_type;
    ix = 0;
    ny = ewk->conn[0].ny;

    for (i = 0; i < ewk->num_of_conn; i++) {
        if (ny != ewk->conn[i].ny) {
            ny = ewk->conn[i].ny;
            ix = i;
        }

        len = ewk->conn[i].nx - ewk->conn[ix].nx;

        if (max < len + dot_type) {
            max = len + dot_type;
        }
    }

    return max / 2;
}

void Check_Pig_Pig(WORK_Other_CONN* ewk) {
    s16 ix;

    if (Debug_w[68]) {
        Convert_16_10_2(ewk, vm_w.Block_Size);

        for (ix = 0; ix < ewk->num_of_conn; ix++) {
            if (ewk->conn[ix].chr != 0x8020) {
                continue;
            }

            ewk->conn[ix].chr = ewk->wu.old_rno[1] + 0x80C3;
            ewk->conn[ix].col = 0x17;

            if (ewk->wu.old_rno[1] == 0) {
                ewk->conn[ix].ny -= 0x100;
            }

            ewk->conn[ix + 1].chr = ewk->wu.old_rno[0] + 0x80C3;
            ewk->conn[ix + 1].col = 0x17;
            return;
        }
    }

    switch (Message_Data[ewk->wu.dir_old].request) {
    case 22:
        for (ix = 0; ix < ewk->num_of_conn; ix++) {
            if (ewk->conn[ix].chr != 0x8020) {
                continue;
            }

            ewk->conn[ix].chr = vm_w.Block_Size + 0x7F81;
            ewk->conn[ix].col = 0x17;
            return;
        }

        break;

    case 23:
    case 25:
        Convert_16_10_2(ewk, vm_w.Block_Size);

        for (ix = 0; ix < ewk->num_of_conn; ix++) {
            if (ewk->conn[ix].chr != 0x8020) {
                continue;
            }

            ewk->conn[ix].chr = ewk->wu.old_rno[1] + 0x7F81;
            ewk->conn[ix].col = 0x17;

            if (ewk->wu.old_rno[1] == 0) {
                ewk->conn[ix].ny -= 0x100;
            }

            ewk->conn[(ix) + 1].chr = ewk->wu.old_rno[0] + 0x7F81;
            ewk->conn[(ix) + 1].col = 0x17;
            return;
        }

        break;

    case 24:
        for (ix = 0; ix < ewk->num_of_conn; ix++) {
            if (ewk->conn[ix].chr != 0x8020) {
                continue;
            }

            ewk->conn[ix].chr = ewk->wu.old_rno[2] + 0x7F81;
            ewk->conn[ix].col = 0x17;

            if (ewk->wu.old_rno[2] == 0) {
                ewk->conn[ix].ny -= 0x100;
            }

            ewk->conn[ix + 1].chr = ewk->wu.old_rno[1] + 0x7F81;
            ewk->conn[ix + 1].col = 0x17;

            if (ewk->wu.old_rno[1] == 0 && ewk->wu.old_rno[2] == 0) {
                ewk->conn[ix + 1].ny -= 0x100;
            }

            ewk->conn[ix + 2].chr = ewk->wu.old_rno[0] + 0x7F81;
            ewk->conn[ix + 2].col = 0x17;
            return;
        }

        break;
    }
}

void Convert_16_10_2(WORK_Other_CONN* ewk, u16 target) {
    ewk->wu.old_rno[1] = target / 10;
    target %= 10;
    ewk->wu.old_rno[0] = target;
}

void Convert_16_10_3(WORK_Other_CONN* ewk, u16 target) {
    ewk->wu.old_rno[2] = target / 100;
    target %= 100;
    ewk->wu.old_rno[1] = target / 10;
    target %= 10;
    ewk->wu.old_rno[0] = target;
}
