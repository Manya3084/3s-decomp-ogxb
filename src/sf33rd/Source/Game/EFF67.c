/* EFF67.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * xb_effect_67_draw 0x3FA2D size 0x2F. FLAG: x86-only callees
 * sort_push_request3,sort_push_request4.
 * effect_67_move 0x3FA5C size 0x1F0.
 * effect_67_init 0x3FC4C size 0x4B1. Read against the x86: the my_col_code
 * choice is branchless (0x6A plus 0x26 masked). The C is the PS2 C.
 * Globals: _sel_pl_char_table 0x2FE100, frw 0xC806A0.
 */

#include "structs.h"

#define EFFECT_MAX 128

s32 sort_push_request3(WORK* wk);
s32 sort_push_request4(WORK* wk);
extern void (*const D_0025B2C0[])(WORK* wk);
void set_char_move_init2(WORK* wk, s16 koc, s16 index, s16 ip, s16 scf);
s16 pull_effect_work(s16 index);
extern uintptr_t frw[EFFECT_MAX][448];
s16 get_my_trans_mode(s16 curr);
extern u32 _sel_pl_char_table[];



void effect_67_move(WORK_Other_CONN* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        switch (ewk->wu.routine_no[1]) {
        case 0:
            ewk->wu.routine_no[1]++;
            ewk->wu.disp_flag = 1;
            set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
            break;

        case 1:
            if (!--ewk->wu.dir_timer) {
                ewk->wu.routine_no[1]++;
                ewk->wu.dir_timer = 40;
            }

            break;

        case 2:
            if (--ewk->wu.dir_timer) {
                ewk->wu.xyz[0].disp.pos = ewk->wu.xyz[0].disp.pos - 10;
            } else {
                ewk->wu.routine_no[0] = 3;
            }

            break;
        }

        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0xFFFF;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0xFFFF;
        sort_push_request4(&ewk->wu);
        break;

    case 1:
        switch (ewk->wu.routine_no[1]) {
        case 0:
            ewk->wu.routine_no[1]++;
            ewk->wu.disp_flag = 1;
            set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
            break;

        case 1:
            if (!--ewk->wu.dir_timer) {
                ewk->wu.routine_no[1]++;
                ewk->wu.dir_timer = 39;
            }

            break;

        case 2:
            if (--ewk->wu.dir_timer) {
                ewk->wu.xyz[0].disp.pos = ewk->wu.xyz[0].disp.pos + 10;
            } else {
                ewk->wu.routine_no[0] = 3;
            }

            break;
        }

        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0xFFFF;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0xFFFF;
        sort_push_request4(&ewk->wu);
        break;

    case 2:
        switch (ewk->wu.routine_no[1]) {
        case 0:
            ewk->wu.routine_no[1]++;
            ewk->wu.disp_flag = 1;
            ewk->wu.old_cgnum = ewk->wu.cg_number = 0;
            ewk->wu.cg_number++;
            ewk->wu.cg_number &= 0x7FFF;
            ewk->prio_reverse = 1;
            break;

        case 1:
            if (!--ewk->wu.dir_timer) {
                ewk->wu.routine_no[1]++;
                ewk->wu.dir_timer = 40;
            }

            break;

        case 2:
            if (--ewk->wu.dir_timer) {
                ewk->wu.xyz[0].disp.pos = ewk->wu.xyz[0].disp.pos - 10;
            } else {
                ewk->wu.routine_no[0] = 4;
            }

            break;
        }

        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0xFFFF;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0xFFFF;
        ewk->wu.cg_number++;
        ewk->wu.cg_number &= 0x7FFF;
        sort_push_request3(&ewk->wu);
        break;

    case 3:
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0xFFFF;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0xFFFF;
        sort_push_request4(&ewk->wu);
        break;

    case 4:
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0xFFFF;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0xFFFF;
        sort_push_request3(&ewk->wu);
        break;

    case 5:
        switch (ewk->wu.routine_no[1]) {
        case 0:
            ewk->wu.routine_no[1]++;
            ewk->wu.disp_flag = 1;
            set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
            break;
        }

        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0xFFFF;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0xFFFF;
        sort_push_request4(&ewk->wu);
        break;

    case 6:
        switch (ewk->wu.routine_no[1]) {
        case 0:
            ewk->wu.routine_no[1]++;
            ewk->wu.disp_flag = 1;
            ewk->wu.old_cgnum = ewk->wu.cg_number = 0;
            ewk->wu.cg_number++;
            ewk->wu.cg_number &= 0x7FFF;
            break;
        }

        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0xFFFF;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0xFFFF;
        ewk->wu.cg_number++;
        ewk->wu.cg_number &= 0x7FFF;
        sort_push_request3(&ewk->wu);
        break;
    }
}

s32 effect_67_init(s16 id, s16 X, s16 Y, s16 time0, s16 Char_Index, s16 Priority, s16 no, s16 col) {
    WORK_Other_CONN* ewk;
    s16 ix;

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }

    ewk = (WORK_Other_CONN*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 67;
    ewk->wu.work_id = 16;

    if (col) {
        ewk->wu.my_col_code = 0x90;
    } else {
        ewk->wu.my_col_code = 0x6A;
    }

    ewk->wu.my_mts = 14;
    ewk->wu.my_trans_mode = get_my_trans_mode(ewk->wu.my_mts);
    ewk->wu.my_family = 1;
    ewk->wu.position_z = Priority;
    ewk->wu.dir_timer = time0;
    ewk->wu.routine_no[0] = no;
    ewk->wu.routine_no[1] = 0;
    ewk->wu.xyz[0].disp.pos = X;
    ewk->wu.xyz[1].disp.pos = Y;

    if (!id) {
        ewk->prio_reverse = 1;
        ewk->num_of_conn = 2;
        ewk->conn[0].col = 0;
        ewk->conn[1].col = 0;
        ewk->conn[0].nx = 0;
        ewk->conn[0].ny = 0;
        ewk->conn[1].nx = 0;
        ewk->conn[1].ny = 0;

        switch (Char_Index) {
        case 0:
            ewk->conn[0].chr = 0x6F38;
            ewk->conn[1].chr = 0x6F43;
            break;

        case 1:
            ewk->num_of_conn++;
            ewk->conn[0].chr = 0x6F38;
            ewk->conn[1].chr = 0x6F43;
            ewk->conn[2].nx = 0;
            ewk->conn[2].ny = 0;
            ewk->conn[2].chr = 0x6F44;
            ewk->conn[2].col = 0;
            break;

        case 2:
            ewk->num_of_conn++;
            ewk->conn[0].chr = 0x6F38;
            ewk->conn[1].chr = 0x6F43;
            ewk->conn[2].nx = 0;
            ewk->conn[2].ny = 0;
            ewk->conn[2].chr = 0x6F45;
            ewk->conn[2].col = 0;
            break;

        case 3:
            ewk->conn[0].chr = 0x6F38;
            ewk->conn[1].chr = 0x6F42;
            break;

        case 4:
            ewk->num_of_conn++;
            ewk->conn[0].chr = 0x6F38;
            ewk->conn[1].chr = 0x6F42;
            ewk->conn[2].nx = 0;
            ewk->conn[2].ny = 0;
            ewk->conn[2].chr = 0x6F44;
            ewk->conn[2].col = 0;
            break;

        case 5:
            ewk->num_of_conn++;
            ewk->conn[0].chr = 0x6F38;
            ewk->conn[1].chr = 0x6F42;
            ewk->conn[2].nx = 0;
            ewk->conn[2].ny = 0;
            ewk->conn[2].chr = 0x6F45;
            ewk->conn[2].col = 0;
            break;

        case 6:
            ewk->conn[0].chr = 0x6F38;
            ewk->conn[1].chr = 0x6F41;
            break;

        case 7:
            ewk->num_of_conn++;
            ewk->conn[0].chr = 0x6F38;
            ewk->conn[1].chr = 0x6F41;
            ewk->conn[2].nx = 0;
            ewk->conn[2].ny = 0;
            ewk->conn[2].chr = 0x6F44;
            ewk->conn[2].col = 0;
            break;

        case 8:
            ewk->num_of_conn++;
            ewk->conn[0].chr = 0x6F38;
            ewk->conn[1].chr = 0x6F41;
            ewk->conn[2].nx = 0;
            ewk->conn[2].ny = 0;
            ewk->conn[2].chr = 0x6F45;
            ewk->conn[2].col = 0;
            break;

        case 9:
            ewk->conn[0].chr = 0x6F37;
            ewk->conn[1].chr = 0x6F40;
            break;

        case 10:
            ewk->num_of_conn++;
            ewk->conn[0].chr = 0x6F37;
            ewk->conn[1].chr = 0x6F40;
            ewk->conn[2].nx = 0;
            ewk->conn[2].ny = 0;
            ewk->conn[2].chr = 0x6F44;
            ewk->conn[2].col = 0;
            break;

        case 11:
            ewk->num_of_conn++;
            ewk->conn[0].chr = 0x6F37;
            ewk->conn[1].chr = 0x6F40;
            ewk->conn[2].nx = 0;
            ewk->conn[2].ny = 0;
            ewk->conn[2].chr = 0x6F45;
            ewk->conn[2].col = 0;
            break;

        case 12:
            ewk->conn[0].chr = 0x6F37;
            ewk->conn[1].chr = 0x6F3F;
            break;

        case 13:
            ewk->num_of_conn++;
            ewk->conn[0].chr = 0x6F37;
            ewk->conn[1].chr = 0x6F3F;
            ewk->conn[2].nx = 0;
            ewk->conn[2].ny = 0;
            ewk->conn[2].chr = 0x6F44;
            ewk->conn[2].col = 0;
            break;

        case 14:
            ewk->num_of_conn++;
            ewk->conn[0].chr = 0x6F37;
            ewk->conn[1].chr = 0x6F3F;
            ewk->conn[2].nx = 0;
            ewk->conn[2].ny = 0;
            ewk->conn[2].chr = 0x6F45;
            ewk->conn[2].col = 0;
            break;

        case 15:
            ewk->conn[0].chr = 0x6F36;
            ewk->conn[1].chr = 0x6F3E;
            break;

        case 16:
            ewk->num_of_conn++;
            ewk->conn[0].chr = 0x6F36;
            ewk->conn[1].chr = 0x6F3E;
            ewk->conn[2].nx = 0;
            ewk->conn[2].ny = 0;
            ewk->conn[2].chr = 0x6F44;
            ewk->conn[2].col = 0;
            break;

        case 17:
            ewk->num_of_conn++;
            ewk->conn[0].chr = 0x6F36;
            ewk->conn[1].chr = 0x6F3E;
            ewk->conn[2].nx = 0;
            ewk->conn[2].ny = 0;
            ewk->conn[2].chr = 0x6F45;
            ewk->conn[2].col = 0;
            break;

        case 18:
            ewk->conn[0].chr = 0x6F35;
            ewk->conn[1].chr = 0x6F3D;
            break;

        case 19:
            ewk->num_of_conn++;
            ewk->conn[0].chr = 0x6F35;
            ewk->conn[1].chr = 0x6F3D;
            ewk->conn[2].nx = 0;
            ewk->conn[2].ny = 0;
            ewk->conn[2].chr = 0x6F44;
            ewk->conn[2].col = 0;
            break;

        case 20:
            ewk->num_of_conn++;
            ewk->conn[0].chr = 0x6F35;
            ewk->conn[1].chr = 0x6F3D;
            ewk->conn[2].nx = 0;
            ewk->conn[2].ny = 0;
            ewk->conn[2].chr = 0x6F45;
            ewk->conn[2].col = 0;
            break;

        case 21:
            ewk->conn[0].chr = 0x6F35;
            ewk->conn[1].chr = 0x6F3C;
            break;

        case 22:
            ewk->num_of_conn++;
            ewk->conn[0].chr = 0x6F35;
            ewk->conn[1].chr = 0x6F3C;
            ewk->conn[2].nx = 0;
            ewk->conn[2].ny = 0;
            ewk->conn[2].chr = 0x6F44;
            ewk->conn[2].col = 0;
            break;

        case 23:
            ewk->num_of_conn++;
            ewk->conn[0].chr = 0x6F35;
            ewk->conn[1].chr = 0x6F3C;
            ewk->conn[2].nx = 0;
            ewk->conn[2].ny = 0;
            ewk->conn[2].chr = 0x6F45;
            ewk->conn[2].col = 0;
            break;

        case 24:
            ewk->conn[0].chr = 0x6F34;
            ewk->conn[1].chr = 0x6F3B;
            break;

        case 25:
            ewk->num_of_conn++;
            ewk->conn[0].chr = 0x6F34;
            ewk->conn[1].chr = 0x6F3B;
            ewk->conn[2].nx = 0;
            ewk->conn[2].ny = 0;
            ewk->conn[2].chr = 0x6EE2;
            ewk->conn[2].col = 0;
            break;

        case 26:
            ewk->num_of_conn++;
            ewk->conn[0].chr = 0x6F34;
            ewk->conn[1].chr = 0x6F3B;
            ewk->conn[2].nx = 0;
            ewk->conn[2].ny = 0;
            ewk->conn[2].chr = 0x6EE1;
            ewk->conn[2].col = 0;
            break;

        case 27:
            ewk->conn[0].chr = 0x6F33;
            ewk->conn[1].chr = 0x6F3A;
            break;

        case 28:
            ewk->num_of_conn++;
            ewk->conn[0].chr = 0x6F33;
            ewk->conn[1].chr = 0x6F3A;
            ewk->conn[2].nx = 0;
            ewk->conn[2].ny = 0;
            ewk->conn[2].chr = 0x6EE3;
            ewk->conn[2].col = 0;
            break;

        case 29:
            ewk->num_of_conn++;
            ewk->conn[0].chr = 0x6F33;
            ewk->conn[1].chr = 0x6F3A;
            ewk->conn[2].nx = 0;
            ewk->conn[2].ny = 0;
            ewk->conn[2].chr = 0x6EE4;
            ewk->conn[2].col = 0;
            break;

        case 30:
            ewk->num_of_conn++;
            ewk->conn[0].chr = 0x6F33;
            ewk->conn[1].chr = 0x6F3A;
            ewk->conn[2].nx = 0;
            ewk->conn[2].ny = 0;
            ewk->conn[2].chr = 0x6EE5;
            ewk->conn[2].col = 0;
            break;

        case 31:
            ewk->conn[0].chr = 0x6F32;
            ewk->conn[1].chr = 0x6F39;
        }
    } else {
        *ewk->wu.char_table = _sel_pl_char_table;
        ewk->wu.char_index = id;
        ewk->wu.dir_step = Char_Index;
    }

    return 0;
}

void xb_effect_67_draw(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        sort_push_request4(&ewk->wu);
        break;

    case 1:
        sort_push_request4(&ewk->wu);
        break;

    case 2:
        sort_push_request3(&ewk->wu);
        break;

    case 3:
        sort_push_request4(&ewk->wu);
        break;

    case 4:
        sort_push_request3(&ewk->wu);
        break;

    case 5:
        sort_push_request4(&ewk->wu);
        break;

    case 6:
        sort_push_request3(&ewk->wu);
        break;
    }
}
