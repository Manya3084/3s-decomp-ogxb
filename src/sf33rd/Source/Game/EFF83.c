/* EFF83.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * effect_83_move 0x41950 size 0x151. Read against the x86: 0x300 is master_id
 * * 768 as an imul. The C is the PS2 C.
 * effect_83_init 0x41AA1 size 0x143. FLAG: x86-only offsets 0x20.
 * effect_83_init 0x41AA1 size 0x143. FLAG: x86-only offsets 0x20.
 * Sound_SE is folded into 0x98407.
 * add_x_sub is folded into 0xEF072.
 * add_y_sub is folded into 0xEF088.
 * Globals: _etc2_char_table 0x2F77F0, Game_pause 0x7A89B0, bg_w 0x7BC520,
 * EXE_flag 0xC7C834, frw 0xC806A0.
 */

#include "structs.h"

#define EFFECT_MAX 128

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
s16 pull_effect_work(s16 index);
extern uintptr_t frw[EFFECT_MAX][448];
extern BG bg_w;
extern u32 _etc2_char_table[];
void suzi_offset_set(WORK_Other* ewk);



/* Rewritten to match retail (tools/permute.py): set_char_move_init parameter 3: s16 -> s32; < 113 -> <= 112. */
void effect_83_move(WORK_Other* ewk) {
    WORK* oya_ptr = (WORK*)ewk->my_master;
    s16 work;

    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        setup_shadow_of_the_Effy(&ewk->wu);
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        ewk->wu.old_rno[0] = 50;
        cal_all_speed_data(&ewk->wu, ewk->wu.old_rno[0], oya_ptr->xyz[0].disp.pos, ewk->wu.xyz[1].disp.pos, 2, 2);
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

            if (work <= 112) {
                ewk->wu.routine_no[0]++;
                sub_00098407((ewk->master_id * 768) + 350);
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
                oya_ptr->cmwk[1] = 9;
                set_char_move_init(&ewk->wu, 0, 35);
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

s32 effect_83_init(WORK* wk, s32 /* unused */) {
    s16 get_my_trans_mode(s32 curr);

    WORK_Other* ewk;
    s16 ix;

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }

    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 83;
    ewk->master_id = wk->id;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.my_col_mode = wk->my_col_mode;
    ewk->wu.my_col_code = wk->my_col_code + 6;
    ewk->wu.my_family = wk->my_family;
    ewk->my_master = (u32*)wk;
    ewk->wu.rl_flag = wk->rl_flag;

    if (wk->rl_flag) {
        if (wk->xyz[0].disp.pos > bg_w.bgw[1].wxy[0].disp.pos) {
            ewk->wu.xyz[0].disp.pos = wk->xyz[0].disp.pos + 256;
        } else {
            ewk->wu.xyz[0].disp.pos = bg_w.bgw[1].wxy[0].disp.pos + (bg_w.pos_offset + 32);
        }

        ewk->wu.old_rno[2] = wk->xyz[0].disp.pos + 56;
    } else {
        if (wk->xyz[0].disp.pos < bg_w.bgw[1].wxy[0].disp.pos) {
            ewk->wu.xyz[0].disp.pos = wk->xyz[0].disp.pos - 256;
        } else {
            ewk->wu.xyz[0].disp.pos = bg_w.bgw[1].wxy[0].disp.pos - (bg_w.pos_offset + 32);
        }

        ewk->wu.old_rno[2] = wk->xyz[0].disp.pos - 56;
    }

    ewk->wu.xyz[1].disp.pos = wk->xyz[1].disp.pos - 12;
    ewk->wu.my_priority = wk->my_priority - 12;
    ewk->wu.position_z = ewk->wu.my_priority - 12;
    *ewk->wu.char_table = _etc2_char_table;
    ewk->wu.char_index = 34;
    ewk->wu.sync_suzi = 0;
    suzi_offset_set(ewk);
    ewk->wu.my_mts = 14;
    ewk->wu.my_trans_mode = get_my_trans_mode(ewk->wu.my_mts);
    return 0;
}
