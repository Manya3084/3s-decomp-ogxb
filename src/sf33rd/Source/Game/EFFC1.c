/* EFFC1.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * effect_C1_move 0x44DCF size 0x17A. Read against the x86: 0x300 is master_id
 * * 768 as an imul. The C is the PS2 C.
 * Sound_SE is folded into 0x98407.
 * add_x_sub is folded into 0xEF072.
 * add_y_sub is folded into 0xEF088.
 * Globals: Game_pause 0x7A89B0, EXE_flag 0xC7C834.
 */

#include "structs.h"

void sub_00098407(s16 Code);
void sub_000EF072(WORK_Other* ewk);
void sub_000EF088(WORK_Other* ewk);
void setup_shadow_of_the_Effy(WORK* wk);
void set_char_move_init(WORK* wk, s16 koc, s16 index);
void cal_all_speed_data(WORK* wk, s16 tm, s16 x1, s16 y1, s8 xsw, s8 ysw);
extern s16 EXE_flag;
extern u8 Game_pause;
void char_move_z(WORK* wk);
void suzi_sync_pos_set(WORK_Other* ewk);
s32 sort_push_request(WORK* wk);
void char_move(WORK* wk);



void effect_C1_move(WORK_Other* ewk) {
    WORK* oya_ptr = (WORK*)ewk->my_master;
    s16 work;

    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        setup_shadow_of_the_Effy(&ewk->wu);
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        ewk->wu.old_rno[0] = 64;

        if (oya_ptr->char_index == 67) {
            work = oya_ptr->xyz[0].disp.pos;
        } else if (oya_ptr->rl_flag) {
            work = oya_ptr->xyz[0].disp.pos + 74;
        } else {
            work = oya_ptr->xyz[0].disp.pos - 74;
        }

        cal_all_speed_data(&ewk->wu, ewk->wu.old_rno[0], work, ewk->wu.xyz[1].disp.pos, 2, 2);
        break;

    case 1:
        if (!EXE_flag && !Game_pause) {
            ewk->wu.old_rno[0]--;
            sub_000EF072(ewk);
            sub_000EF088(ewk);
            work = ewk->wu.xyz[0].disp.pos - oya_ptr->xyz[0].disp.pos;

            if (work < 0) {
                work = -work;
            }

            if (work < 0x91) {
                ewk->wu.routine_no[0]++;
                sub_00098407((ewk->master_id * 0x300) + 0x15E);
                char_move_z(&ewk->wu);
            }
        }

        suzi_sync_pos_set(ewk);
        sort_push_request(&ewk->wu);
        break;

    case 2:
        if (!EXE_flag && !Game_pause) {
            char_move(&ewk->wu);
            sub_000EF072(ewk);
            sub_000EF088(ewk);
            ewk->wu.old_rno[0]--;

            if (ewk->wu.old_rno[0] <= 0) {
                ewk->wu.routine_no[0]++;

                if (oya_ptr->char_index == 67) {
                    set_char_move_init(&ewk->wu, 0, 37);
                } else {
                    set_char_move_init(&ewk->wu, 0, 38);
                }
            }
        }

        suzi_sync_pos_set(ewk);
        sort_push_request(&ewk->wu);
        break;

    case 3:
        if (!EXE_flag && !Game_pause) {
            char_move(&ewk->wu);
        }

        suzi_sync_pos_set(ewk);
        sort_push_request(&ewk->wu);
        break;
    }
}
