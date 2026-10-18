/* EFF85.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * eff85_0000 0x41D56 size 0x1A.
 * eff85_common 0x41D70 size 0x4E.
 * eff85_3000 0x41DBE size 0x8F.
 * eff85_7000 0x41E4D size 0x82.
 * eff85_8000 0x41ECF size 0x44.
 * eff85_9000 0x41F13 size 0xC0.
 * swallow_sprize_check 0x41FD3 size 0x20.
 * eff85_0200 0x41FF3 size 0xF.
 * effect_85_init 0x42002 size 0xAF.
 * eff85_1000 0x420B1 size 0x7B.
 * eff85_5000 0x4212C size 0x5B.
 * eff85_0100 0x42187 size 0x71.
 * effect_85_move 0x421F8 size 0x2A.
 * add_x_sub is folded into 0xEF072.
 * add_y_sub is folded into 0xEF088.
 * all_cgps_put_back is folded into 0x4384A.
 * disp_pos_trans_entry is folded into 0xEF0C0.
 * Data: eff85_char_index_tbl is 0x24F6E4, 0x12 bytes compared.
 * Data: _chn_char_table is 0x2F33C0, the char table effect_85_init stores.
 * Unnamed data used (not checked): eff85_3000: 0x510000; eff85_7000: 0x2c0000;
 * effect_85_init: 0x2c0000; eff85_1000: 0x2c0000.
 * Globals: eff85_char_index_tbl 0x24F6E4, EXE_obroll 0x7A8111, Game_pause
 * 0x7A89B0, bg_w 0x7BC520, EXE_flag 0xC7C834, frw 0xC806A0.
 */

#include "structs.h"

#define EFFECT_MAX 128

void sub_000EF072(WORK_Other* ewk);
void sub_000EF088(WORK_Other* ewk);
void sub_0004384A(WORK* wk);
void sub_000EF0C0(WORK_Other* ewk);
void eff85_0000(WORK_Other* ewk);
void eff85_0100(WORK_Other* ewk);
void eff85_0200(WORK_Other* ewk);
void eff85_1000(WORK_Other* ewk);
void eff85_common(WORK_Other* ewk);
void eff85_3000(WORK_Other* ewk);
void eff85_5000(WORK_Other* ewk);
void eff85_7000(WORK_Other* ewk);
void eff85_8000(WORK_Other* ewk);
void eff85_9000(WORK_Other* ewk);
extern s16 EXE_flag;
extern u8 Game_pause;
extern s8 EXE_obroll;
void set_char_move_init(WORK* wk, s16 koc, s16 index);
s32 swallow_sprize_check(WORK_Other* ewk);
void char_move(WORK* wk);
void cal_initial_speed(WORK* wk, s16 tm, s16 x1, s16 y1);
void cal_all_speed_data(WORK* wk, s16 tm, s16 x1, s16 y1, s8 xsw, s8 ysw);
extern BG bg_w;
void push_effect_work(WORK* wkhd);
s16 pull_effect_work(s16 index);
extern uintptr_t frw[EFFECT_MAX][448];
s16 get_my_trans_mode(s16 curr);
extern u32 _chn_char_table[];

const s16 eff85_char_index_tbl[9] = { 0, 30, 0, 32, 29, 33, 0, 0, 0 };

;

void effect_85_move(WORK_Other* ewk) {
    void (*const eff85_jp_tbl[3])(WORK_Other*) = { eff85_0000, eff85_0100, eff85_0200 };
    eff85_jp_tbl[ewk->wu.routine_no[0]](ewk);
}

void eff85_0000(WORK_Other* ewk) {
    ewk->wu.routine_no[0]++;
    ewk->wu.routine_no[1] = 0;
    ewk->wu.routine_no[2] = 0;
    ewk->wu.rl_flag = 0;
    ewk->wu.old_rno[0] = 0;
}

void eff85_0100(WORK_Other* ewk) {
    void (*const eff85_move_tbl[9])(WORK_Other*) = { eff85_1000,   eff85_common, eff85_3000, eff85_common, eff85_5000,
                                                     eff85_common, eff85_7000,   eff85_8000, eff85_9000 };

    if (!EXE_flag && !Game_pause && !EXE_obroll) {
        eff85_move_tbl[ewk->wu.routine_no[1]](ewk);
    }

    sub_000EF0C0(ewk);
}

void eff85_1000(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[2]) {
    case 0:
        ewk->wu.routine_no[2]++;
        ewk->wu.disp_flag = 1;

        if (ewk->wu.old_rno[0]) {
            set_char_move_init(&ewk->wu, 0, 44);
        } else {
            set_char_move_init(&ewk->wu, 0, 28);
        }

        ewk->wu.old_rno[0]++;
        ewk->wu.old_rno[0] &= 1;
        ewk->wu.xyz[0].cal = 0x1EB0000;
        ewk->wu.xyz[1].cal = 0x2C0000;
        break;

    case 1:
        if (!swallow_sprize_check(ewk)) {
            break;
        }

        char_move(&ewk->wu);

        if (ewk->wu.cg_type == 0xFF) {
            ewk->wu.routine_no[1]++;
            ewk->wu.routine_no[2] = 0;
        }

        break;
    }
}

void eff85_common(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[2]) {
    case 0:
        ewk->wu.routine_no[2]++;
        set_char_move_init(&ewk->wu, 0, eff85_char_index_tbl[ewk->wu.routine_no[1]]);
        break;

    case 1:
        char_move(&ewk->wu);

        if (ewk->wu.cg_type == 0xFF) {
            ewk->wu.routine_no[1]++;
            ewk->wu.routine_no[2] = 0;
        }

        break;
    }
}

void eff85_3000(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[2]) {
    case 0:
        ewk->wu.routine_no[2]++;
        set_char_move_init(&ewk->wu, 0, 31);
        ewk->wu.dir_timer = 34;
        ewk->wu.mvxy.d[0].sp = 0;
        ewk->wu.mvxy.d[1].sp = -0x2000;
        cal_initial_speed(&ewk->wu, ewk->wu.dir_timer, 400, 81);
        break;

    case 1:
        char_move(&ewk->wu);
        ewk->wu.dir_timer--;

        if (ewk->wu.dir_timer <= 0) {
            ewk->wu.routine_no[1]++;
            ewk->wu.routine_no[2] = 0;
            ewk->wu.xyz[0].cal = 0x1900000;
            ewk->wu.xyz[1].cal = 0x510000;
            break;
        }

        sub_000EF072(ewk);
        sub_000EF088(ewk);
        break;
    }
}

void eff85_5000(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[2]) {
    case 0:
        ewk->wu.routine_no[2]++;
        set_char_move_init(&ewk->wu, 0, eff85_char_index_tbl[ewk->wu.routine_no[1]]);
        break;

    case 1:
        if (!swallow_sprize_check(ewk)) {
            break;
        }

        char_move(&ewk->wu);

        if (ewk->wu.cg_type == 0xFF) {
            ewk->wu.routine_no[1]++;
            ewk->wu.routine_no[2] = 0;
        }

        break;
    }
}

void eff85_7000(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[2]) {
    case 0:
        ewk->wu.routine_no[2]++;
        set_char_move_init(&ewk->wu, 0, 34);
        ewk->wu.dir_timer = 110;
        cal_all_speed_data(&ewk->wu, ewk->wu.dir_timer, 491, 44, 2, 0);
        break;

    case 1:
        char_move(&ewk->wu);
        ewk->wu.dir_timer--;

        if (ewk->wu.dir_timer < 0) {
            ewk->wu.routine_no[1]++;
            ewk->wu.routine_no[2] = 0;
            ewk->wu.xyz[0].cal = 0x1EB0000;
            ewk->wu.xyz[1].cal = 0x2C0000;
            break;
        }

        sub_000EF072(ewk);
        sub_000EF088(ewk);
        break;
    }
}

void eff85_8000(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[2]) {
    case 0:
        ewk->wu.routine_no[2]++;
        set_char_move_init(&ewk->wu, 0, 35);
        break;

    case 1:
        char_move(&ewk->wu);

        if (ewk->wu.cg_type == 0xFF) {
            ewk->wu.routine_no[1] = 0;
            ewk->wu.routine_no[2] = 0;
        }

        break;
    }
}

void eff85_9000(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[2]) {
    case 0:
        ewk->wu.routine_no[2]++;

        if (ewk->wu.cg_flip == 0) {
            ewk->wu.mvxy.a[0].sp = -0x50000;
            ewk->wu.mvxy.a[1].sp = 0xC000;
            ewk->wu.mvxy.d[0].sp = 0;
            ewk->wu.mvxy.d[1].sp = 0;
            set_char_move_init(&ewk->wu, 0, 45);
        } else {
            ewk->wu.mvxy.a[0].sp = 0x50000;
            ewk->wu.mvxy.a[1].sp = 0xC000;
            ewk->wu.mvxy.d[0].sp = 0;
            ewk->wu.mvxy.d[1].sp = 0;
            set_char_move_init(&ewk->wu, 0, 46);
        }

        break;

    case 1:
        char_move(&ewk->wu);
        sub_000EF072(ewk);
        sub_000EF088(ewk);

        if (ewk->wu.xyz[0].disp.pos >= bg_w.bgw[1].l_limit2 - bg_w.pos_offset &&
            ewk->wu.xyz[0].disp.pos <= bg_w.bgw[1].r_limit2 + bg_w.pos_offset) {
            break;
        }

        ewk->wu.routine_no[2]++;
        ewk->wu.disp_flag = 0;
        break;

    case 2:
        if (bg_w.bgw[1].wxy[0].disp.pos > 720) {
            ewk->wu.routine_no[1] = 0;
            ewk->wu.routine_no[2] = 0;
        }

        break;
    }
}

s32 swallow_sprize_check(WORK_Other* ewk) {
    if (bg_w.quake_y_index > 3) {
        ewk->wu.routine_no[1] = 8;
        ewk->wu.routine_no[2] = 0;
        return 0;
    }

    return 1;
}

void eff85_0200(WORK_Other* ewk) {
    sub_0004384A(&ewk->wu);
    push_effect_work(&ewk->wu);
}

s32 effect_85_init() {
    WORK_Other* ewk;
    s16 ix;

    if (EXE_obroll) {
        return 0;
    }

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }

    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 85;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.rl_flag = 0;
    ewk->wu.dead_f = 1;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_family = 2;
    ewk->wu.my_col_code = 8492;
    ewk->wu.my_mts = 7;
    ewk->wu.my_trans_mode = get_my_trans_mode(ewk->wu.my_mts);
    ewk->wu.xyz[0].cal = 0x1EB0000;
    ewk->wu.xyz[1].cal = 0x2C0000;
    ewk->wu.my_priority = ewk->wu.position_z = 10;
    ewk->wu.sync_suzi = 0;
    ewk->wu.char_table[0] = _chn_char_table;
    return 0;
}
