/* EFFB0.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * effect_B0_move 0x43B3D size 0xBF.
 * Not located in sf33rd.xbe; their PS2 C is kept under #if 0: effect_B0_init.
 * disp_pos_trans_entry is folded into 0xEF0C0.
 * Data: effb0_timer_tbl is 0x251828, 0x10 bytes compared.
 * Data: effb0_data_tbl is 0x251838, 0x20 bytes compared.
 * Globals: effb0_timer_tbl 0x251828, effb0_data_tbl 0x251838, end_w 0x7AABF0.
 */

#include "structs.h"

void sub_000EF0C0(WORK_Other* ewk);
extern END_W end_w;
void set_char_move_init(WORK* wk, s16 koc, s16 index);
void char_move(WORK* wk);
s32 random_16();
void push_effect_work(WORK* wkhd);

const s16 effb0_timer_tbl[8] = { 60, 30, 120, 150, 8, 20, 10, 90 };

const s16 effb0_data_tbl[8][2] = { { 656, 112 }, { 328, 96 },  { 352, 224 }, { 688, 144 },
                                   { 344, 128 }, { 640, 224 }, { 336, 176 }, { 672, 72 } };

void effect_B0_move(WORK_Other* ewk) {
    s16 work;

    if (ewk->wu.old_rno[6] < end_w.r_no_2) {
        ewk->wu.routine_no[0] = 99;
    }

    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.old_rno[5]--;

        if (ewk->wu.old_rno[5] <= 0) {
            ewk->wu.routine_no[0]++;
            ewk->wu.disp_flag = 1;
            set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        }

        break;

    case 1:
        char_move(&ewk->wu);

        if (ewk->wu.cg_type) {
            ewk->wu.routine_no[0] = 0;
            ewk->wu.disp_flag = 0;
            work = random_16();
            work &= 7;
            ewk->wu.old_rno[5] = effb0_timer_tbl[work];
            work = random_16();
            work &= 7;
            ewk->wu.xyz[0].disp.pos = effb0_data_tbl[work][0];
            work = random_16();
            work &= 7;
            ewk->wu.xyz[1].disp.pos = effb0_data_tbl[work][1];
        }

        sub_000EF0C0(ewk);
        break;

    default:
        push_effect_work(&ewk->wu);
        break;
    }
}

#if 0
/* PS2 C for functions not located in sf33rd.xbe yet. */

s32 effect_B0_init() {
#if defined(TARGET_PS2)
    s16 get_my_trans_mode(s32 curr);
#endif

    WORK_Other* ewk;
    s16 ix;
    s16 i;
    s16 work;

    for (i = 0; i < 8; i++) {
        if ((ix = pull_effect_work(4)) == -1) {
            return -1;
        }

        ewk = (WORK_Other*)frw[ix];
        ewk->wu.id = 110;
        ewk->wu.be_flag = 1;
        ewk->wu.type = i;
        ewk->wu.work_id = 16;
        ewk->wu.cgromtype = 1;
        ewk->wu.old_rno[0] = end_w.r_no_2;
        ewk->wu.my_col_mode = 0x4200;
        ewk->wu.char_table[0] = (u32*)_end_char_table;
        ewk->wu.my_col_code = 300;
        ewk->wu.my_family = 1;
        ewk->wu.old_rno[6] = 0;
        ewk->wu.old_rno[6] += end_w.r_no_2;
        ewk->wu.xyz[0].disp.pos = effb0_data_tbl[i][0];
        ewk->wu.xyz[1].disp.pos = effb0_data_tbl[i][1];
        ewk->wu.my_priority = ewk->wu.position_z = 80;
        ewk->wu.char_index = 29;
        work = random_16();
        work &= 7;
        ewk->wu.old_rno[5] = effb0_timer_tbl[work];
        ewk->wu.my_mts = 8;
        ewk->wu.my_trans_mode = get_my_trans_mode(ewk->wu.my_mts);
    }

    return 0;
}
#endif
