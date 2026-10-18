/* EFFH1.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * eff_h1_move 0x4C111 size 0xB9.
 * effect_H1_move 0x4C2A2 size 0x48.
 * Not located in sf33rd.xbe; their PS2 C is kept under #if 0: effect_H1_init.
 * all_cgps_put_back is folded into 0x4384A.
 * disp_pos_trans_entry is folded into 0xEF0C0.
 * Data: effh1_wait_timer is 0x257788, 0x10 bytes compared.
 * Data: effh1_data_tbl is 0x257798, 0x50 bytes compared.
 * Globals: effh1_wait_timer 0x257788, effh1_data_tbl 0x257798, end_w 0x7AABF0,
 * bg_w 0x7BC520.
 */

#include "structs.h"

void sub_0004384A(WORK* wk);
void sub_000EF0C0(WORK_Other* ewk);
extern END_W end_w;
void eff_h1_move(WORK_Other* ewk);
void push_effect_work(WORK* wkhd);
void set_char_move_init(WORK* wk, s16 koc, s16 index);
extern BG bg_w;
void char_move(WORK* wk);
s32 range_x_check(WORK_Other* ewk);
s32 random_16();

const s16 effh1_wait_timer[8] = { 30, 120, 180, 40, 10, 200, 240, 50 };

const s16 effh1_data_tbl[8][5] = { { -96, 256, 74, 34, 10 }, { 64, 288, 74, 34, 8 },  { -64, 256, 78, 35, 4 },
                                   { 128, 272, 78, 35, 28 }, { -32, 240, 74, 34, 2 }, { 96, 240, 74, 34, 2 },
                                   { -160, 224, 78, 35, 2 }, { 128, 224, 78, 35, 2 } };

void effect_H1_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        if (ewk->wu.old_rno[6] < end_w.r_no_2) {
            ewk->wu.routine_no[1] = 99;
            break;
        }

        eff_h1_move(ewk);
        break;

    case 1:
        ewk->wu.routine_no[0]++;
        break;

    default:
        sub_0004384A(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}

void eff_h1_move(WORK_Other* ewk) {
    s16 work;

    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.old_rno[0]--;

        if (ewk->wu.old_rno[0] <= 0) {
            ewk->wu.routine_no[1]++;
            ewk->wu.disp_flag = 1;
            set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
            ewk->wu.xyz[0].disp.pos += bg_w.bgw[1].xy[0].disp.pos;
        }

        break;

    case 1:
        char_move(&ewk->wu);

        if (range_x_check(ewk) && ewk->wu.xyz[1].disp.pos > -8) {
            sub_000EF0C0(ewk);
            break;
        }

        if (ewk->wu.type > 4) {
            ewk->wu.routine_no[0]++;
            break;
        }

        ewk->wu.routine_no[1] = 0;
        ewk->wu.disp_flag = 0;
        work = random_16();
        work &= 7;
        ewk->wu.old_rno[0] = effh1_wait_timer[work];
        ewk->wu.xyz[0].disp.pos = effh1_data_tbl[ewk->wu.type][0];
        ewk->wu.xyz[1].disp.pos = effh1_data_tbl[ewk->wu.type][1];
        break;
    }
}

#if 0
/* PS2 C for functions not located in sf33rd.xbe yet. */

s32 effect_H1_init() {
#if defined(TARGET_PS2)
    s16 get_my_trans_mode(s32 curr);
#endif

    WORK_Other* ewk;
    s16 ix;
    s16 i;
    const s16* data_ptr = &effh1_data_tbl[0][0];

    for (i = 0; i < 8; i++) {
        if ((ix = pull_effect_work(4)) == -1) {
            return -1;
        }

        ewk = (WORK_Other*)frw[ix];
        ewk->wu.id = 171;
        ewk->wu.be_flag = 1;
        ewk->wu.type = i;
        ewk->wu.work_id = 16;
        ewk->wu.cgromtype = 1;
        ewk->wu.old_rno[6] = end_w.r_no_2;
        ewk->wu.my_col_mode = 0x4200;
        ewk->wu.char_table[0] = (u32*)_end_char_table;
        ewk->wu.my_family = 2;
        ewk->wu.my_col_code = 300;
        ewk->wu.xyz[0].disp.pos = *data_ptr++;
        ewk->wu.xyz[1].disp.pos = *data_ptr++;
        ewk->wu.my_priority = ewk->wu.position_z = *data_ptr++;
        ewk->wu.char_index = *data_ptr++;
        ewk->wu.old_rno[0] = *data_ptr++;
        ewk->wu.my_mts = 8;
        ewk->wu.my_trans_mode = get_my_trans_mode(ewk->wu.my_mts);
    }

    return 0;
}
#endif
