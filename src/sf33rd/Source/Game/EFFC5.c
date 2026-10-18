/* EFFC5.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * effect_C5_move 0x466E1 size 0x204. Read against the x86: 0x300 is master_id
 * * 768 as an imul. The C is the PS2 C.
 * effect_C5_init 0x468E5 size 0x126. Read against the x86: ±0x140 is the C's
 * pos_x_work ± 320. Matches.
 * Sound_SE is folded into 0x98407.
 * add_x_sub is folded into 0xEF072.
 * all_cgps_put_back is folded into 0x4384A.
 * Globals: _etc_char_table 0x2F9850, Demo_Flag 0x7A842D, Game_pause 0x7A89B0,
 * demo_car_flag 0x7BC4DA, bg_w 0x7BC520, Appear_car_stop 0x7BCC88, EXE_flag
 * 0xC7C834, frw 0xC806A0.
 */

#include "structs.h"

#define EFFECT_MAX 128

void sub_00098407(s16 Code);
void sub_000EF072(WORK_Other* ewk);
void sub_0004384A(WORK* wk);
extern s16 EXE_flag;
extern u8 Game_pause;
void set_char_move_init(WORK* wk, s16 koc, s16 index);
void char_move(WORK* wk);
extern s8 Appear_car_stop[2];
extern s8 Demo_Flag;
void SsRequestPan(u16 reqNum, s16 start, s16 , s32 , s32 );
void suzi_sync_pos_set(WORK_Other* ewk);
s32 sort_push_request(WORK* wk);
extern s8 demo_car_flag[2];
void push_effect_work(WORK* wkhd);
s16 pull_effect_work(s16 index);
extern uintptr_t frw[EFFECT_MAX][448];
extern u32 _etc_char_table[];
s16 get_my_trans_mode(s16 curr);
extern BG bg_w;
void cal_all_speed_data(WORK* wk, s16 tm, s16 x1, s16 y1, s8 xsw, s8 ysw);
void suzi_offset_set(WORK_Other* ewk);
s32 effect_C6_init(WORK_Other* oya);



/* Rewritten to match retail (tools/permute.py): < 1 -> <= 0; set_char_move_init parameter 3: s16 -> s32. */
void effect_C5_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        if (!EXE_flag && !Game_pause) {
            ewk->wu.routine_no[0]++;
            ewk->wu.disp_flag = 1;
            set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
            sub_00098407(ewk->master_id * 0x300 + 0x134);
        }

        break;

    case 1:
        if (!EXE_flag && !Game_pause) {
            char_move(&ewk->wu);
            ewk->wu.old_rno[0]--;

            if (ewk->wu.old_rno[0] <= 0) {
                ewk->wu.routine_no[0]++;
                Appear_car_stop[ewk->master_id] = 1;
                set_char_move_init(&ewk->wu, 0, 9);

                if (Demo_Flag != 0) {
                    SsRequestPan(0x135, 0x40, 0x40, 0, 2);
                }
            } else {
                sub_000EF072(ewk);
            }
        }

        suzi_sync_pos_set(ewk);
        sort_push_request(&ewk->wu);
        break;

    case 2:
        if (!EXE_flag && !Game_pause) {
            char_move(&ewk->wu);

            if (ewk->wu.cg_type == 1) {
                ewk->wu.routine_no[0]++;
                ewk->wu.old_rno[0] = 20;
            } else if (ewk->wu.cg_type == 2) {
                demo_car_flag[ewk->master_id] = 1;
            }
        }

        suzi_sync_pos_set(ewk);
        sort_push_request(&ewk->wu);
        break;

    case 3:
        if (!EXE_flag && !Game_pause) {
            ewk->wu.old_rno[0]--;

            if (ewk->wu.old_rno[0] < 0) {
                ewk->wu.routine_no[0]++;
                ewk->wu.old_rno[0] = 48;

                if (ewk->wu.rl_flag) {
                    ewk->wu.mvxy.a[0].sp = -0x20000;
                    ewk->wu.mvxy.d[0].sp = -0x1000;
                } else {
                    ewk->wu.mvxy.a[0].sp = 0x20000;
                    ewk->wu.mvxy.d[0].sp = 0x1000;
                }
            }
        }

        suzi_sync_pos_set(ewk);
        sort_push_request(&ewk->wu);
        break;

    case 4:
        if (!EXE_flag && !Game_pause) {
            ewk->wu.old_rno[0]--;

            if (ewk->wu.old_rno[0] < 0) {
                ewk->wu.routine_no[0]++;
            } else {
                sub_000EF072(ewk);
            }
        }

        suzi_sync_pos_set(ewk);
        sort_push_request(&ewk->wu);
        break;

    case 5:
        ewk->wu.routine_no[0]++;
        demo_car_flag[ewk->master_id] = 0;
        ewk->wu.disp_flag = 0;
        break;

    case 6:
        ewk->wu.routine_no[0]++;
        break;

    default:
        sub_0004384A(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}

s32 effect_C5_init(PLW* oya, s16 reverse_f) {
    WORK_Other* ewk;
    s16 ix;
    s16 work;
    s16 id_num;

    if ((ix = pull_effect_work(3)) == -1) {
        return -1;
    }

    ewk = (WORK_Other*)frw[ix];
    demo_car_flag[oya->wu.id] = 0;
    Appear_car_stop[oya->wu.id] = 0;
    ewk->wu.be_flag = 1;
    ewk->wu.id = 125;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.disp_flag = 0;
    ewk->wu.my_family = 2;
    ewk->wu.char_index = 8;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_priority = ewk->wu.position_z = 57;
    *ewk->wu.char_table = _etc_char_table;
    ewk->wu.my_col_code = oya->wu.my_col_code + 6;
    ewk->wu.sync_suzi = 0;
    ewk->master_id = oya->wu.id;
    ewk->wu.my_mts = 14;
    ewk->wu.my_trans_mode = get_my_trans_mode(ewk->wu.my_mts);
    id_num = oya->wu.id ^ reverse_f;

    if (id_num) {
        ewk->wu.xyz[0].disp.low = 0;
        ewk->wu.xyz[1].cal = 0;
        ewk->wu.rl_flag = 0;
        ewk->wu.old_rno[0] = 40;
        work = (bg_w.bgw[1].pos_x_work + 192) & 0xFFFF;
        ewk->wu.xyz[0].disp.pos = (bg_w.bgw[1].pos_x_work + 320) & 0xFFFF;
        cal_all_speed_data(&ewk->wu, ewk->wu.old_rno[0], work, 0, 1, 1);
    } else {
        ewk->wu.xyz[1].cal = 0;
        ewk->wu.xyz[0].disp.low = 0;
        ewk->wu.rl_flag = 1;
        ewk->wu.old_rno[0] = 40;
        work = (bg_w.bgw[1].pos_x_work - 192) & 0xFFFF;
        ewk->wu.xyz[0].disp.pos = (bg_w.bgw[1].pos_x_work - 320) & 0xFFFF;
        cal_all_speed_data(&ewk->wu, ewk->wu.old_rno[0], work, 0, 1, 1);
    }

    suzi_offset_set(ewk);
    effect_C6_init(ewk);
    return 0;
}
