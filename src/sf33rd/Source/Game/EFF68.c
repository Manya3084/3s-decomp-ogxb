/* EFF68.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * effect_68_move 0x40116 size 0x25F.
 * effect_68_init 0x40375 size 0x131.
 * add_x_sub is folded into 0xEF072.
 * add_y_sub is folded into 0xEF088.
 * all_cgps_put_back is folded into 0x4384A.
 * disp_pos_trans_entry is folded into 0xEF0C0.
 * Data: eff68_data_tbl is 0x24F5D0, 0x68 bytes compared.
 * Data: _brz_char_table is 0x302E30, the char table effect_68_init stores.
 * Globals: eff68_data_tbl 0x24F5D0, Game_pause 0x7A89B0, EXE_flag 0xC7C834,
 * frw 0xC806A0.
 */

#include "structs.h"

#define EFFECT_MAX 128

void sub_000EF072(WORK_Other* ewk);
void sub_000EF088(WORK_Other* ewk);
void sub_0004384A(WORK* wk);
void sub_000EF0C0(WORK_Other* ewk);
void set_char_move_init(WORK* wk, s16 koc, s16 index);
extern s16 EXE_flag;
extern u8 Game_pause;
void cal_all_speed_data(WORK* wk, s16 tm, s16 x1, s16 y1, s8 xsw, s8 ysw);
void cal_delta_speed(WORK* wk, s16 tm, s16 x1, s16 y1, s8 xsw, s8 ysw);
void char_move(WORK* wk);
void push_effect_work(WORK* wkhd);
s16 pull_effect_work(s16 index);
extern uintptr_t frw[EFFECT_MAX][448];
s16 get_my_trans_mode(s16 curr);
extern u32 _brz_char_table[];
void suzi_offset_set(WORK_Other* ewk);

const s16 eff68_data_tbl[52] = { 2, 432, 192, 504, 180, 576, 172, 522, 160, 8,  9,  73, 0,
                                 2, 592, 208, 664, 196, 736, 188, 682, 176, 8,  9,  73, 20,
                                 3, 736, 160, 808, 148, 880, 140, 826, 128, 10, 11, 83, 50,
                                 3, 624, 192, 696, 180, 768, 172, 714, 160, 10, 11, 83, 40 };

void effect_68_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        sub_000EF0C0(ewk);
        break;

    case 1:
        if (!EXE_flag && !Game_pause) {
            ewk->wu.routine_no[4]--;

            if (ewk->wu.routine_no[4] < 1) {
                ewk->wu.routine_no[0]++;
                ewk->wu.routine_no[4] = 50;
                cal_all_speed_data(&ewk->wu, ewk->wu.routine_no[4], ewk->wu.old_rno[2], ewk->wu.old_rno[3], 1, 1);
                ewk->wu.char_index = ewk->wu.routine_no[6];
                set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
            }
        }

        sub_000EF0C0(ewk);
        break;

    case 2:
        if (!EXE_flag && !Game_pause) {
            ewk->wu.routine_no[4]--;

            if (ewk->wu.routine_no[4] < 1) {
                ewk->wu.routine_no[0]++;
                ewk->wu.routine_no[4] = 50;
                cal_delta_speed(&ewk->wu, ewk->wu.routine_no[4], ewk->wu.old_rno[4], ewk->wu.old_rno[5], 2, 2);
                ewk->wu.char_index = ewk->wu.routine_no[6];
                set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
            }

            sub_000EF072(ewk);
            sub_000EF088(ewk);
        }

        sub_000EF0C0(ewk);
        break;

    case 3:
        if (!EXE_flag && !Game_pause) {
            ewk->wu.routine_no[4]--;

            if (ewk->wu.routine_no[4] < 1) {
                ewk->wu.routine_no[0]++;
                ewk->wu.routine_no[4] = 40;
                cal_all_speed_data(&ewk->wu, ewk->wu.routine_no[4], ewk->wu.old_rno[6], ewk->wu.old_rno[7], 1, 1);
            }

            sub_000EF072(ewk);
            sub_000EF088(ewk);
            char_move(&ewk->wu);
        }

        sub_000EF0C0(ewk);
        break;

    case 4:
        if (!EXE_flag && !Game_pause) {
            ewk->wu.routine_no[4]--;

            if (ewk->wu.routine_no[4] < 1) {
                ewk->wu.routine_no[0]++;
                ewk->wu.routine_no[4] = 60;
                cal_delta_speed(&ewk->wu, ewk->wu.routine_no[4], ewk->wu.old_rno[0], ewk->wu.old_rno[1], 2, 2);
                ewk->wu.char_index = ewk->wu.routine_no[5];
                set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
            }

            sub_000EF072(ewk);
            sub_000EF088(ewk);
            char_move(&ewk->wu);
        }

        sub_000EF0C0(ewk);
        break;

    case 5:
        if (!EXE_flag && !Game_pause) {
            ewk->wu.routine_no[4]--;

            if (ewk->wu.routine_no[4] < 1) {
                ewk->wu.routine_no[0] = 2;
                ewk->wu.routine_no[4] = 50;
                cal_all_speed_data(&ewk->wu, ewk->wu.routine_no[4], ewk->wu.old_rno[2], ewk->wu.old_rno[3], 1, 1);
                ewk->wu.char_index = ewk->wu.routine_no[6];
                set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
            }

            sub_000EF072(ewk);
            sub_000EF088(ewk);
        }

        sub_000EF0C0(ewk);
        break;

    default:
        sub_0004384A(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}

s32 effect_68_init() {
    WORK_Other* ewk;
    s16 ix;
    s16 i;
    const s16* data_ptr = eff68_data_tbl;

    for (i = 0; i < 3; i++) {
        if ((ix = pull_effect_work(4)) == -1) {
            return -1;
        }

        ewk = (WORK_Other*)frw[ix];
        ewk->wu.be_flag = 1;
        ewk->wu.id = 68;
        ewk->wu.work_id = 16;
        ewk->wu.cgromtype = 1;
        ewk->wu.rl_flag = 0;
        ewk->wu.dead_f = 1;
        ewk->wu.my_col_mode = 0x4200;
        ewk->wu.my_col_code = 8492;
        ewk->wu.my_mts = 7;
        ewk->wu.my_trans_mode = get_my_trans_mode(ewk->wu.my_mts);
        ewk->wu.my_family = *data_ptr++;
        ewk->wu.xyz[0].disp.pos = ewk->wu.old_rno[0] = *data_ptr++;
        ewk->wu.xyz[1].disp.pos = ewk->wu.old_rno[1] = *data_ptr++;
        ewk->wu.old_rno[2] = *data_ptr++;
        ewk->wu.old_rno[3] = *data_ptr++;
        ewk->wu.old_rno[4] = *data_ptr++;
        ewk->wu.old_rno[5] = *data_ptr++;
        ewk->wu.old_rno[6] = *data_ptr++;
        ewk->wu.old_rno[7] = *data_ptr++;
        ewk->wu.char_index = ewk->wu.routine_no[5] = *data_ptr++;
        ewk->wu.routine_no[6] = *data_ptr++;
        ewk->wu.my_priority = ewk->wu.position_z = *data_ptr++;
        ewk->wu.routine_no[4] = *data_ptr++;
        ewk->wu.sync_suzi = 0;
        ewk->wu.char_table[0] = _brz_char_table;
        suzi_offset_set(ewk);
    }

    return 0;
}
