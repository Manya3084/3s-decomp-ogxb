/* EFF31.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * effect_31_move 0x3A6C5 size 0x145.
 * effect_31_init 0x3A80A size 0x13C. Read against the x86: 0x20 is the C's 32
 * in the position set beside the screen (bg_w.pos_offset + 32, added or
 * subtracted). Matches.
 * add_x_sub is folded into 0xEF072.
 * add_y_sub is folded into 0xEF088.
 * Data: _etc3_char_table is 0x303250, the char table effect_31_init stores.
 * Globals: Game_pause 0x7A89B0, bg_w 0x7BC520, EXE_flag 0xC7C834, frw
 * 0xC806A0.
 */

#include "structs.h"

#define EFFECT_MAX 128

void sub_000EF072(WORK_Other* ewk);
void sub_000EF088(WORK_Other* ewk);
void set_char_move_init(WORK* wk, s16 koc, s16 index);
void cal_initial_speed(WORK* wk, s16 tm, s16 x1, s16 y1);
extern s16 EXE_flag;
extern u8 Game_pause;
void char_move(WORK* wk);
void suzi_sync_pos_set(WORK_Other* ewk);
s32 sort_push_request(WORK* wk);
void push_effect_work(WORK* wkhd);
s16 pull_effect_work(s16 index);
extern uintptr_t frw[EFFECT_MAX][448];
extern BG bg_w;
extern u32 _etc3_char_table[];
void suzi_offset_set(WORK_Other* ewk);
s16 get_my_trans_mode(s16 curr);



void effect_31_move(WORK_Other* ewk) {
    WORK* oya_ptr = (WORK*)ewk->my_master;

    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.kage_flag = 1;
        ewk->wu.kage_hx = 0;
        ewk->wu.kage_hy = -10;
        ewk->wu.kage_prio = 71;
        ewk->wu.kage_char = 16;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        ewk->wu.old_rno[0] = 120;
        cal_initial_speed(&ewk->wu, ewk->wu.old_rno[0], ewk->wu.old_rno[1], ewk->wu.xyz[1].disp.pos);
        break;

    case 1:
        if (!EXE_flag && !Game_pause) {
            char_move(&ewk->wu);
            sub_000EF072(ewk);
            sub_000EF088(ewk);
            ewk->wu.old_rno[0]--;

            if (ewk->wu.old_rno[0] < 1) {
                ewk->wu.routine_no[0]++;
                set_char_move_init(&ewk->wu, 0, 1);
            }
        }

        suzi_sync_pos_set(ewk);
        sort_push_request(&ewk->wu);
        break;

    case 2:
        if (!EXE_flag && !Game_pause && (char_move(&ewk->wu), ewk->wu.cg_type == 0xFF)) {
            ewk->wu.routine_no[0]++;
            set_char_move_init(&ewk->wu, 0, 3);
        }

        suzi_sync_pos_set(ewk);
        sort_push_request(&ewk->wu);
        break;

    case 3:
        if (!EXE_flag && !Game_pause && (char_move(&ewk->wu), ewk->wu.cg_type == 10)) {
            ewk->wu.cg_type = 0;
            ewk->wu.kage_hx += 4;
        }

        suzi_sync_pos_set(ewk);
        sort_push_request(&ewk->wu);
        break;

    case 4:
        ewk->wu.disp_flag = 0;
        ewk->wu.kage_flag = 0;
        ewk->wu.routine_no[0]++;
        break;

    case 5:
        ewk->wu.routine_no[0]++;
        break;

    default:
        push_effect_work(&ewk->wu);
        break;
    }
}

s32 effect_31_init(WORK* wk) {
    WORK_Other* ewk;
    s16 ix;

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }

    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 31;
    ewk->wu.work_id = 16;
    ewk->master_id = wk->id;
    ewk->wu.cgromtype = 1;
    ewk->wu.my_col_mode = wk->my_col_mode;
    ewk->wu.my_col_code = wk->my_col_code + 1;
    ewk->wu.my_family = wk->my_family;
    ewk->my_master = (u32*)wk;
    ewk->wu.target_adrs = wk->target_adrs;
    ewk->wu.rl_flag = wk->rl_flag;

    if (wk->rl_flag) {
        if (wk->xyz[0].disp.pos < bg_w.bgw[1].wxy[0].disp.pos) {
            ewk->wu.xyz[0].disp.pos = wk->xyz[0].disp.pos - 256;
        } else {
            ewk->wu.xyz[0].disp.pos = bg_w.bgw[1].wxy[0].disp.pos - (bg_w.pos_offset + 32);
        }

        ewk->wu.old_rno[1] = wk->xyz[0].disp.pos + 80;
    } else {
        if (wk->xyz[0].disp.pos > bg_w.bgw[1].wxy[0].disp.pos) {
            ewk->wu.xyz[0].disp.pos = wk->xyz[0].disp.pos + 256;
        } else {
            ewk->wu.xyz[0].disp.pos = bg_w.bgw[1].wxy[0].disp.pos + (bg_w.pos_offset + 32);
        }

        ewk->wu.old_rno[1] = wk->xyz[0].disp.pos - 80;
    }

    ewk->wu.xyz[1].disp.pos = wk->xyz[1].disp.pos - 12;
    ewk->wu.my_priority = 28;
    ewk->wu.position_z = 28;
    ewk->wu.char_table[0] = _etc3_char_table;
    ewk->wu.char_index = 0;
    ewk->wu.sync_suzi = 0;
    suzi_offset_set(ewk);
    ewk->wu.my_mts = 14;
    ewk->wu.my_trans_mode = get_my_trans_mode(ewk->wu.my_mts);
    return 0;
}
