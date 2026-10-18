/* EFF24.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * dog24_data_set 0x38C6D size 0x4D.
 * eff24_sp_data_set 0x38CBA size 0xD3.
 * effect_24_init 0x38D8D size 0x112.
 * eff24_quake_sub 0x38E9F size 0x143.
 * effect_24_move 0x38FE2 size 0x7D.
 * add_x_sub is folded into 0xEF072.
 * add_y_sub is folded into 0xEF088.
 * all_cgps_put_back is folded into 0x4384A.
 * disp_pos_trans_entry is folded into 0xEF0C0.
 * Data: eff24_data_tbl is 0x24DA10, 0x70 bytes compared, found by the bytes.
 * Data: eff24_quake_index_tbl is 0x24DA80, 0xDE bytes compared, found by the
 * bytes.
 * Data: eff24_quake_speed_y_tbl is 0x24DB60, 0x80 bytes compared, found by the
 * bytes.
 * Data: eff24_quake_speed_x_tbl is 0x24DBE0, 0x80 bytes compared, found by the
 * bytes.
 * Data: dog24_x_data is 0x24DC60, 0x10 bytes compared, found by the bytes.
 * Globals: eff24_data_tbl 0x24DA10, eff24_quake_index_tbl 0x24DA80,
 * eff24_quake_speed_y_tbl 0x24DB60, eff24_quake_speed_x_tbl 0x24DBE0,
 * dog24_x_data 0x24DC60, EXE_obroll 0x7A8111, Game_pause 0x7A89B0, bg_w
 * 0x7BC520, EXE_flag 0xC7C834, frw 0xC806A0.
 */

#include "structs.h"

void sub_000EF072(WORK_Other* ewk);
void sub_000EF088(WORK_Other* ewk);
void sub_0004384A(WORK* wk);
void sub_000EF0C0(WORK_Other* ewk);
void set_char_move_init(WORK* wk, s16 koc, s16 index);
extern s16 EXE_flag;
extern u8 Game_pause;
extern s8 EXE_obroll;
void eff24_quake_sub(WORK_Other* ewk);
void disp_pos_trans_entry_r(WORK_Other* ewk);
void push_effect_work(WORK* wkhd);
extern BG bg_w;
void eff24_sp_data_set(WORK_Other* ewk);
void dog24_data_set(WORK_Other* ewk);
void char_move(WORK* wk);
void cal_all_speed_data(WORK* wk, s16 tm, s16 x1, s16 y1, s8 xsw, s8 ysw);
void cal_initial_speed(WORK* wk, s16 tm, s16 x1, s16 y1);
s32 random_16();

const s16 eff24_data_tbl[56] = { 8492, 480, 6,  10, 12, 2, 0, 300,  224, 43, 81, 3, 1, 1, 300, 288, 44, 80, 4, 2, 1,
                                 300,  512, 48, 80, 5,  1, 0, 8492, 512, 48, 80, 6, 2, 0, 300, 644, 48, 80, 7, 1, 1,
                                 300,  752, 48, 81, 8,  3, 1, 300,  800, 32, 80, 9, 3, 1 };

const s16 eff24_quake_index_tbl[111] = { 0, 0, 0, 1, 1, 1, 2, 2, 3, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 7, 7, 7, 7,
                                         7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
                                         7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
                                         7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
                                         7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7 };

const s32 eff24_quake_speed_y_tbl[4][8] = { { 0x10000, 0x20000, 0x30000, 0x40000, 0x50000, 0x60000, 0x70000, 0xC0000 },
                                            { 0xE000, 0x10000, 0x1C000, 0x24000, 0x30000, 0x48000, 0x60000, 0x80000 },
                                            { 0xC000, 0xE000, 0x10000, 0x18000, 0x20000, 0x30000, 0x48000, 0x60000 },
                                            { 0x2000, 0x8000, 0xC000, 0x10000, 0x18000, 0x20000, 0x30000, 0x60000 } };

const s32 eff24_quake_speed_x_tbl[4][8] = { { 0x1200, 0x1200, 0x1400, 0x1400, 0x1000, 0x1200, 0x1200, 0x1400 },
                                            { 0x1800, 0x1800, 0x1400, 0x1400, 0x1000, 0x1800, 0x1400, 0x1400 },
                                            { 0x1000, 0x1000, 0x800, 0x800, 0x800, 0x800, 0x400, 0x400 },
                                            { 0x400, 0x400, 0x800, 0x800, 0x400, 0x400, 0x400, 0x400 } };

const s16 dog24_x_data[8] = { 0, 0, 0, 6, 10, 16, 32, 40 };

void effect_24_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.old_rno[0] = 0;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        break;

    case 1:
        if (!EXE_flag && !Game_pause && !EXE_obroll) {
            eff24_quake_sub(ewk);
        }

        if (ewk->wu.old_rno[7]) {
            disp_pos_trans_entry_r(ewk);
            break;
        }

        sub_000EF0C0(ewk);
        break;

    default:
        sub_0004384A(&ewk->wu);
        push_effect_work(&ewk->wu);
    }
}

void eff24_quake_sub(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (bg_w.quake_y_index > 0) {
            ewk->wu.routine_no[1]++;
            eff24_sp_data_set(ewk);
        }

        break;

    case 1:
        sub_000EF072(ewk);
        sub_000EF088(ewk);

        if (ewk->wu.xyz[1].disp.pos < ewk->wu.old_rno[2]) {
            ewk->wu.routine_no[1]++;
            ewk->wu.xyz[1].disp.pos = ewk->wu.old_rno[2];
            ewk->wu.xyz[1].disp.low = 0;
            eff24_sp_data_set(ewk);
        }

        break;

    case 2:
        sub_000EF072(ewk);
        sub_000EF088(ewk);
        ewk->wu.old_rno[5]--;

        if (ewk->wu.old_rno[5] > 0) {
            break;
        }

        ewk->wu.xyz[0].disp.pos = ewk->wu.old_rno[4];
        ewk->wu.xyz[0].disp.low = 0;
        ewk->wu.xyz[1].disp.pos = ewk->wu.old_rno[2];
        ewk->wu.xyz[1].disp.low = 0;

        if (ewk->wu.type == 0 && ewk->wu.old_rno[1] > 2) {
            ewk->wu.routine_no[1]++;
            dog24_data_set(ewk);

            if (ewk->wu.old_rno[6]) {
                set_char_move_init(&ewk->wu, 0, 14);
            } else {
                set_char_move_init(&ewk->wu, 0, 13);
            }

            ewk->wu.old_rno[6] ^= 1;
            break;
        }

        ewk->wu.routine_no[1] = 0;
        ewk->wu.old_rno[1] = 0;
        ewk->wu.old_rno[0] = 0;
        break;

    case 3:
        char_move(&ewk->wu);
        sub_000EF072(ewk);
        ewk->wu.old_rno[5]--;

        if (ewk->wu.old_rno[5] > 0) {
            break;
        }

        ewk->wu.routine_no[1]++;
        // fallthrough

    case 4:
        char_move(&ewk->wu);
        sub_000EF072(ewk);

        if (ewk->wu.cg_type) {
            ewk->wu.routine_no[1] = 0;
            ewk->wu.old_rno[1] = 0;
            ewk->wu.old_rno[0] = 0;
            ewk->wu.old_rno[4] = ewk->wu.xyz[0].disp.pos;
            ewk->wu.xyz[0].disp.low = 0;
            ewk->wu.old_rno[2] = ewk->wu.xyz[1].disp.pos;
            ewk->wu.xyz[1].disp.low = 0;
        }

        break;
    }
}

void dog24_data_set(WORK_Other* ewk) {
    s16 work;

    ewk->wu.old_rno[5] = 40;

    if (ewk->wu.old_rno[6]) {
        work = ewk->wu.xyz[0].disp.pos + dog24_x_data[ewk->wu.old_rno[1]];
    } else {
        work = ewk->wu.xyz[0].disp.pos - dog24_x_data[ewk->wu.old_rno[1]];
    }

    cal_all_speed_data(&ewk->wu, ewk->wu.old_rno[5], work, ewk->wu.xyz[1].disp.pos, 2, 0);
}

void eff24_sp_data_set(WORK_Other* ewk) {
    s16 work;

    if (ewk->wu.old_rno[0]) {
        ewk->wu.old_rno[5] = 12;
        ewk->wu.mvxy.d[0].sp = 0;

        switch (ewk->wu.old_rno[1]) {
        case 0:
        case 1:
            ewk->wu.mvxy.d[1].sp = -0x2000;
            break;

        case 2:
        case 3:
            ewk->wu.mvxy.d[1].sp = -0x4000;
            break;

        default:
            ewk->wu.mvxy.d[1].sp = -0x5000;
            break;
        }

        cal_initial_speed(&ewk->wu, ewk->wu.old_rno[5], ewk->wu.old_rno[4], ewk->wu.old_rno[2]);
    } else {
        ewk->wu.old_rno[1] = eff24_quake_index_tbl[bg_w.quake_y_index];
        ewk->wu.mvxy.a[0].sp = eff24_quake_speed_x_tbl[ewk->wu.old_rno[3]][ewk->wu.old_rno[1]];
        ewk->wu.mvxy.d[0].sp = 0;
        work = random_16();

        if (work & 1) {
            ewk->wu.mvxy.a[0].sp = -ewk->wu.mvxy.a[0].sp;
        }

        ewk->wu.mvxy.a[1].sp = eff24_quake_speed_y_tbl[ewk->wu.old_rno[3]][ewk->wu.old_rno[1]];
        ewk->wu.mvxy.d[1].sp = -0x6000;
    }

    ewk->wu.old_rno[0]++;
    ewk->wu.old_rno[0] &= 1;
}
