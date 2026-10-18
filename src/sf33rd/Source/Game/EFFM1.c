/* EFFM1.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * effm1_move 0x51D52 size 0xD6.
 * effect_M1_init 0x51E28 size 0x11A. Read against the x86: sbb/and -0x80/add
 * 0x40 is the branchless form of the C's rl_flag ? -64 : 64, and 0x20 is the
 * C's + 32. Matches.
 * effect_M1_move 0x51F42 size 0x79.
 * add_x_sub is folded into 0xEF072.
 * Globals: _etc3_char_table 0x303250, Game_pause 0x7A89B0, bg_w 0x7BC520,
 * EXE_flag 0xC7C834, frw 0xC806A0.
 */

#include "structs.h"

#define EFFECT_MAX 128

void sub_000EF072(WORK_Other* ewk);
void set_char_move_init(WORK* wk, s16 koc, s16 index);
extern s16 EXE_flag;
extern u8 Game_pause;
void effm1_move(WORK_Other* ewk);
void pl_eff_trans_entry(WORK_Other* ewk);
void push_effect_work(WORK* wkhd);
void char_move(WORK* wk);
void set_char_move_init2(WORK* wk, s16 koc, s16 index, s16 ip, s16 scf);
void cal_initial_speed(WORK* wk, s16 tm, s16 x1, s16 y1);
void suzi_sync_pos_set(WORK_Other* ewk);
s32 sort_push_request(WORK* wk);
s16 pull_effect_work(s16 index);
extern uintptr_t frw[EFFECT_MAX][448];
extern u32 _etc3_char_table[];
extern BG bg_w;
void suzi_offset_set(WORK_Other* ewk);
s16 get_my_trans_mode(s16 curr);



void effect_M1_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.kage_flag = 1;
        ewk->wu.kage_hx = 0;
        ewk->wu.kage_hy = 0;
        ewk->wu.kage_prio = 71;
        ewk->wu.kage_char = 16;
        set_char_move_init(&ewk->wu, 0, 12);
        break;

    case 1:
        if (!EXE_flag && !Game_pause) {
            effm1_move(ewk);
        }

        pl_eff_trans_entry(ewk);
        break;

    case 99:
        ewk->wu.routine_no[0]++;
        break;

    default:
        push_effect_work(&ewk->wu);
        break;
    }
}

void effm1_move(WORK_Other* ewk) {
    WORK* oya_ptr = (WORK*)ewk->my_master;

    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (oya_ptr->cmwk[0]) {
            ewk->wu.routine_no[1]++;
            set_char_move_init(&ewk->wu, 0, 13);
        } else {
            char_move(&ewk->wu);
        }

        break;

    case 1:
        char_move(&ewk->wu);

        if (ewk->wu.cg_type != 0xFF) {
            break;
        }

        oya_ptr->cmwk[0] = 2;
        ewk->wu.routine_no[1]++;
        set_char_move_init2(&ewk->wu, 0, 0, 3, 0);
        ewk->wu.rl_flag ^= 1;
        ewk->wu.old_rno[0] = 60;
        cal_initial_speed(&ewk->wu, ewk->wu.old_rno[0], ewk->wu.old_rno[1], ewk->wu.xyz[1].disp.pos);
        break;

    case 2:
        ewk->wu.old_rno[0]--;

        if (ewk->wu.old_rno[0] < 0) {
            ewk->wu.routine_no[1]++;
            ewk->wu.routine_no[0] = 99;
            ewk->wu.disp_flag = 0;
            break;
        }

        char_move(&ewk->wu);
        sub_000EF072(ewk);
        suzi_sync_pos_set(ewk);
        sort_push_request(&ewk->wu);
        break;
    }
}

s32 effect_M1_init(WORK* wk) {
    WORK_Other* ewk;
    s16 ix;

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }

    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 221;
    ewk->wu.work_id = 16;
    ewk->master_id = wk->id;
    ewk->wu.cgromtype = 1;
    ewk->wu.my_col_mode = wk->my_col_mode;
    ewk->wu.my_col_code = wk->my_col_code + 1;
    ewk->wu.my_family = wk->my_family;
    ewk->my_master = (u32*)wk;
    ewk->wu.rl_flag = wk->rl_flag;
    ewk->wu.xyz[0].disp.pos = wk->xyz[0].disp.pos;
    ewk->wu.xyz[0].disp.pos += wk->rl_flag ? -64 : 64;
    ewk->wu.xyz[1].disp.pos = wk->xyz[1].disp.pos - 2;
    ewk->wu.position_z = wk->my_priority - 12;
    ewk->wu.my_priority = wk->my_priority - 12;
    *ewk->wu.char_table = _etc3_char_table;
    ewk->wu.sync_suzi = 0;

    if (wk->rl_flag) {
        ewk->wu.old_rno[1] = bg_w.bgw[1].wxy[0].disp.pos - (bg_w.pos_offset + 32);
    } else {
        ewk->wu.old_rno[1] = bg_w.bgw[1].wxy[0].disp.pos + (bg_w.pos_offset + 32);
    }

    suzi_offset_set(ewk);
    ewk->wu.my_mts = 14;
    ewk->wu.my_trans_mode = get_my_trans_mode(ewk->wu.my_mts);
    return 0;
}
