/* EFF41.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * effect_41_move 0x3BE20 size 0x160.
 * gauge_minus 0x3BF80 size 0x48. Read against the x86: grade_add_super_arts is
 * reached through a shared tail; 0xFF is the store to the as flag bytes. The C
 * is the PS2 C.
 * effect_41_init 0x3BFC8 size 0x97.
 * eff41_process_00 0x3C05F size 0x60.
 * eff41_process_01 0x3C0BF size 0xAD.
 * Data: sa_sign_data is 0x24DE98, 0x2B2 bytes compared.
 * Data: eff41_main_process is 0x24E14C, 2 entries compared.
 * Data: _plef_char_table is 0x308B40, the char table effect_41_init stores.
 * Globals: sa_sign_data 0x24DE98, eff41_main_process 0x24E14C, sa_gauge_flash
 * 0x7A820E, test_flag 0x7A8902, Game_pause 0x7A89B0, bg_w 0x7BC520, EXE_flag
 * 0xC7C834, frw 0xC806A0.
 */

#include "structs.h"

#define EFFECT_MAX 128

void eff41_process_00(WORK_Other* ewk, PLW* mwk);
void eff41_process_01(WORK_Other* ewk, PLW* mwk);
extern s8 sa_gauge_flash[2];
void set_char_move_init(WORK* wk, s16 koc, s16 index);
extern s16 EXE_flag;
extern u8 Game_pause;
void char_move(WORK* wk);
s32 effect_D9_init(PLW* wk, u8 data);
void push_color_trans_req(s16 from_col, s16 to_col);
s32 sort_push_request(WORK* wk);
s32 erase_my_shell_ix(WORK* wk, s16 ix);
void push_effect_work(WORK* wkhd);
void gauge_minus(WORK_Other* ewk, PLW* mwk);
extern BG bg_w;
void grade_add_super_arts(s16 ix, s16 num);
extern u8 test_flag;
s16 pull_effect_work(s16 index);
extern uintptr_t frw[EFFECT_MAX][448];
void write_my_shell_ix(WORK* wk, s16 ix);
extern u32 _plef_char_table[];

const s16 sa_sign_data[69][5] = {
    { 28, 70, 156, 1, 1 },  { -41, 37, 156, 1, 1 },  { 12, 56, 156, 1, 1 },  { -14, 80, 156, 1, 1 },
    { -14, 48, 156, 1, 1 }, { -28, 56, 156, 1, 1 },  { -12, 56, 156, 1, 1 }, { -20, 84, 156, 1, 1 },
    { -38, 44, 156, 1, 1 }, { 48, 92, 156, 1, 1 },   { -44, 51, 156, 1, 1 }, { -30, 28, 156, 1, 1 },
    { -30, 28, 156, 1, 1 }, { 28, 70, 156, 1, 1 },   { -32, 42, 156, 1, 1 }, { 0, 72, 156, 1, 1 },
    { 14, 65, 156, 1, 1 },  { -30, 28, 156, 1, 1 },  { -58, 60, 156, 1, 1 }, { -20, 64, 156, 1, 1 },
    { -22, 66, 156, 1, 1 }, { 22, 66, 156, 1, 1 },   { 0, 48, 156, 1, 1 },   { -22, 74, 156, 1, 1 },
    { -36, 52, 156, 1, 1 }, { -32, 48, 156, 1, 1 },  { -12, 40, 156, 1, 1 }, { -24, 68, 156, 1, 1 },
    { -3, 72, 156, 1, 1 },  { 2, 72, 156, 1, 1 },    { 20, 130, 159, 2, 0 }, { 0, 72, 156, 1, 1 },
    { 28, 10, 156, 1, 1 },  { -48, 144, 158, 2, 0 }, { -16, 88, 156, 1, 1 }, { -58, 74, 156, 1, 1 },
    { -16, 88, 156, 1, 1 }, { -9, 100, 158, 2, 0 },  { -57, 48, 157, 0, 0 }, { 25, 53, 156, 1, 1 },
    { -28, 44, 156, 1, 1 }, { -22, 72, 156, 1, 1 },  { -22, 72, 156, 1, 1 }, { -21, 123, 156, 1, 1 },
    { -13, 67, 156, 1, 1 }, { -22, 56, 156, 1, 1 },  { 32, 24, 156, 1, 1 },  { -64, 62, 156, 1, 1 },
    { -32, 64, 156, 1, 1 }, { -17, 52, 156, 1, 1 },  { 3, 53, 156, 1, 1 },   { -12, 104, 160, 2, 0 },
    { 14, 56, 158, 2, 0 },  { 31, 90, 156, 1, 1 },   { -16, 80, 156, 1, 1 }, { -2, 58, 156, 1, 1 },
    { 24, 105, 156, 1, 1 }, { -37, 70, 156, 1, 1 },  { -21, 87, 156, 1, 1 }, { -11, 83, 156, 1, 1 },
    { -4, 120, 158, 1, 0 }, { -36, 76, 156, 1, 1 },  { 38, 60, 156, 1, 1 },  { -8, 74, 156, 1, 1 },
    { -5, 52, 158, 1, 0 },  { -7, 73, 156, 1, 1 },   { -8, 90, 156, 1, 1 },  { -18, 16, 156, 1, 1 },
    { 14, 56, 158, 1, 0 }
};

void (*const eff41_main_process[2])() = { eff41_process_00, eff41_process_01 };

void effect_41_move(WORK_Other* ewk) {
    PLW* mwk = (PLW*)ewk->my_master;

    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.routine_no[1] = 0;
        ewk->wu.disp_flag = 1;
        ewk->wu.my_col_mode = 0x4200;
        ewk->wu.my_col_code = 0xA;
        ewk->wu.position_z = 24;

        switch (sa_sign_data[ewk->wu.type][3]) {
        case 1:
            sa_gauge_flash[mwk->wu.id] |= 4;
            break;
        case 2:
            sa_gauge_flash[mwk->wu.id] |= 4;
            break;
        }

        set_char_move_init(&ewk->wu, 0, sa_sign_data[ewk->wu.type][2]);
        goto jump;

    case 1:
        if (ewk->wu.dead_f == 1 || mwk->wu.routine_no[1] != 4) {
            ewk->wu.routine_no[0]++;
            ewk->wu.disp_flag = 0;
            break;
        }

        if (EXE_flag == 0 && Game_pause == 0) {
            if (ewk->wu.hit_stop) {
                ewk->wu.hit_stop--;
            } else {
                char_move(&ewk->wu);
            }
        }

        if (ewk->wu.cg_type == 4) {
            ewk->wu.cg_type = 0;
            effect_D9_init(mwk, 7);
        }

        if (ewk->wu.cg_type == 0xFF) {
            ewk->wu.routine_no[0]++;
            ewk->wu.disp_flag = 0;
            return;
        }

    jump:
        eff41_main_process[sa_sign_data[ewk->wu.type][4]](ewk, mwk);
        ewk->wu.cg_type = 0;

        if (ewk->wu.extra_col != 0) {
            push_color_trans_req(ewk->wu.extra_col & 0x1FF, 10);
            ewk->wu.extra_col = 0;
        }

        sort_push_request(&ewk->wu);
        break;

    case 2:
        erase_my_shell_ix((WORK*)ewk->my_master, ewk->wu.myself);
        ewk->wu.routine_no[0] = 3;
        break;

    default:
        push_effect_work(&ewk->wu);
        break;
    }
}

void eff41_process_00(WORK_Other* ewk, PLW* mwk) {
    if (ewk->wu.cg_type == 1) {
        gauge_minus(ewk, mwk);
    }

    ewk->wu.position_x = mwk->wu.position_x;

    if (mwk->wu.rl_flag) {
        ewk->wu.position_x -= sa_sign_data[ewk->wu.type][0];
    } else {
        ewk->wu.position_x += sa_sign_data[ewk->wu.type][0];
    }

    ewk->wu.position_y = mwk->wu.position_y + sa_sign_data[ewk->wu.type][1];
}

void eff41_process_01(WORK_Other* ewk, PLW* mwk) {
    switch (ewk->wu.cg_type) {
    case 1:
        gauge_minus(ewk, mwk);
        ewk->wu.routine_no[1] = 1;
        break;

    case 2:
        ewk->wu.routine_no[1] = 2;
        break;
    }

    switch (ewk->wu.routine_no[1]) {
    case 1:
        ewk->wu.position_x = mwk->wu.position_x;
        ewk->wu.position_y = 0;
        break;

    case 2:
        ewk->wu.position_x = bg_w.bgw[1].position_x + bg_w.pos_offset;
        ewk->wu.position_y = mwk->wu.position_y + sa_sign_data[ewk->wu.type][1];
        break;

    default:
        ewk->wu.position_x = mwk->wu.position_x;

        if (mwk->wu.rl_flag) {
            ewk->wu.position_x -= sa_sign_data[ewk->wu.type][0];
        } else {
            ewk->wu.position_x += sa_sign_data[ewk->wu.type][0];
        }

        ewk->wu.position_y = mwk->wu.position_y + sa_sign_data[ewk->wu.type][1];
        break;
    }
}

void gauge_minus(WORK_Other* ewk, PLW* mwk) {
    switch (sa_sign_data[ewk->wu.type][3]) {
    case 1:
        mwk->sa->saeff_ok = -1;
        grade_add_super_arts(mwk->wu.id, 1);
        break;

    case 2:
        mwk->sa->saeff_mp = -1;
        grade_add_super_arts(mwk->wu.id, 2);
        break;
    }
}

s32 effect_41_init(PLW* wk, u8 data) {
    WORK_Other* ewk;
    s16 ix;

    if (test_flag) {
        return 0;
    }

    if ((ix = pull_effect_work(3)) == -1) {
        return -1;
    }

    ewk = (WORK_Other*)frw[ix];
    write_my_shell_ix(&wk->wu, ix);
    ewk->wu.be_flag = 1;
    ewk->wu.type = data;
    ewk->wu.id = 41;
    ewk->wu.work_id = 16;
    ewk->wu.my_mts = 15;
    ewk->wu.my_family = wk->wu.my_family;
    ewk->my_master = (u32*)wk;
    ewk->master_work_id = wk->wu.work_id;
    ewk->master_id = wk->wu.id;
    *ewk->wu.char_table = _plef_char_table;
    return 0;
}
