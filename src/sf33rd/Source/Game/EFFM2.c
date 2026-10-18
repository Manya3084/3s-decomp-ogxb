/* EFFM2.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * effm2_move 0x51FBB size 0xEA.
 * effm2_move2 0x520A5 size 0x111. Read against the x86: 0x30 is the 48 added
 * to pos_offset and the 48 distance check. The C is the PS2 C.
 * effect_M2_init 0x521B6 size 0xB9.
 * effect_M2_move 0x5226F size 0x70.
 * add_x_sub is folded into 0xEF072.
 * all_cgps_put_back is folded into 0x4384A.
 * Data: effm2_char_tbl is 0x25B2B8, 0x8 bytes compared.
 * Data: _etc2_char_table is 0x2F77F0, the char table effect_M2_init stores.
 * Globals: effm2_char_tbl 0x25B2B8, Win_Record 0x7A8164, Game_pause 0x7A89B0,
 * bg_w 0x7BC520, EXE_flag 0xC7C834, frw 0xC806A0.
 */

#include "structs.h"

#define EFFECT_MAX 128

void sub_000EF072(WORK_Other* ewk);
void sub_0004384A(WORK* wk);
s32 random_16();
extern s16 EXE_flag;
extern u8 Game_pause;
void effm2_move2(WORK_Other* ewk);
void effm2_move(WORK_Other* ewk);
void pl_eff_trans_entry(WORK_Other* ewk);
void push_effect_work(WORK* wkhd);
void set_char_move_init(WORK* wk, s16 koc, s16 index);
void char_move(WORK* wk);
void cat_run_set2(WORK_Other* ewk);
s32 range_x_check3(WORK_Other* ewk, s16 optional_range);
extern BG bg_w;
void cat_walk_set(WORK_Other* ewk);
extern u16 Win_Record[2];
s16 pull_effect_work(s16 index);
extern uintptr_t frw[EFFECT_MAX][448];
extern u32 _etc2_char_table[];
s16 get_my_trans_mode(s16 curr);

const s16 effm2_char_tbl[4] = { 50, 50, 29, 46 };

void effect_M2_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.old_rno[0] = random_16();
        ewk->wu.old_rno[0] &= 3;
        break;

    case 1:
        if (!EXE_flag && !Game_pause) {
            if (ewk->wu.type) {
                effm2_move2(ewk);
            } else {
                effm2_move(ewk);
            }
        }

        pl_eff_trans_entry(ewk);
        break;

    case 99:
        ewk->wu.routine_no[0]++;
        break;

    default:
        sub_0004384A(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}

void effm2_move(WORK_Other* ewk) {
    WORK* oya_ptr = (WORK*)ewk->my_master;

    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.dead_f = 1;
        ewk->wu.kage_flag = 1;
        ewk->wu.kage_hx = 0;
        ewk->wu.kage_hy = 7;
        ewk->wu.kage_prio = 71;
        ewk->wu.kage_char = 3;

        if (oya_ptr->id) {
            ewk->wu.xyz[0].disp.pos = oya_ptr->xyz[0].disp.pos + 60;
        } else {
            ewk->wu.xyz[0].disp.pos = oya_ptr->xyz[0].disp.pos - 60;
        }

        ewk->wu.xyz[1].disp.pos = 7;
        ewk->wu.my_priority = ewk->wu.position_z = 67;
        set_char_move_init(&ewk->wu, 0, effm2_char_tbl[ewk->wu.old_rno[0]]);
        break;

    case 1:
        char_move(&ewk->wu);

        if (ewk->wu.cg_type == 0xFF) {
            ewk->wu.routine_no[1]++;

            if (ewk->wu.old_rno[0] == 2) {
                ewk->wu.rl_flag ^= 1;
            }

            cat_run_set2(ewk);
        }

        break;

    case 2:
        char_move(&ewk->wu);
        sub_000EF072(ewk);

        if (!range_x_check3(ewk, 64)) {
            ewk->wu.routine_no[0] = 99;
            ewk->wu.routine_no[1]++;
        }

        break;
    }
}

void effm2_move2(WORK_Other* ewk) {
    WORK* oya_ptr = (WORK*)ewk->my_master;
    s16 dis_w;

    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.dead_f = 1;
        ewk->wu.kage_flag = 1;
        ewk->wu.kage_hx = 0;
        ewk->wu.kage_hy = 7;
        ewk->wu.kage_prio = 71;
        ewk->wu.kage_char = 3;

        if (oya_ptr->rl_flag) {
            ewk->wu.xyz[0].disp.pos = bg_w.bgw[1].wxy[0].disp.pos - bg_w.pos_offset - 48;

            if (oya_ptr->xyz[0].disp.pos > bg_w.bgw[1].wxy[0].disp.pos) {
                cat_run_set2(ewk);
            } else {
                cat_walk_set(ewk);
            }
        } else {
            ewk->wu.xyz[0].disp.pos = bg_w.bgw[1].wxy[0].disp.pos + bg_w.pos_offset + 48;

            if (oya_ptr->xyz[0].disp.pos < bg_w.bgw[1].wxy[0].disp.pos) {
                cat_run_set2(ewk);
            } else {
                cat_walk_set(ewk);
            }
        }

        ewk->wu.xyz[1].disp.pos = 7;
        ewk->wu.my_priority = ewk->wu.position_z = 70;
        break;

    case 1:
        char_move(&ewk->wu);
        sub_000EF072(ewk);
        dis_w = oya_ptr->xyz[0].disp.pos - ewk->wu.xyz[0].disp.pos;

        if (dis_w < 0) {
            dis_w = -dis_w;
        }

        if (dis_w < 48) {
            ewk->wu.routine_no[1]++;
            set_char_move_init(&ewk->wu, 0, 51);
        }

        break;

    case 2:
        char_move(&ewk->wu);

        if (ewk->wu.cg_type == 0xFF) {
            ewk->wu.routine_no[1]++;
            set_char_move_init(&ewk->wu, 0, 28);
        }

        break;

    case 3:
        char_move(&ewk->wu);
        break;
    }
}

s32 effect_M2_init(WORK* wk, u8 data) {
    WORK_Other* ewk;
    s16 ix;

    if (data) {
        if (Win_Record[wk->id] < 4) {
            return 0;
        }
    } else if (Win_Record[wk->id] < 3) {
        return 0;
    }

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }

    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 222;
    ewk->wu.cgromtype = 1;
    ewk->my_master = (u32*)wk;
    ewk->wu.rl_flag = wk->rl_flag;
    ewk->wu.type = data;
    ewk->wu.work_id = 16;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.char_table[0] = _etc2_char_table;
    ewk->wu.my_family = 2;
    ewk->wu.my_col_code = 59;
    ewk->wu.my_mts = 14;
    ewk->wu.my_trans_mode = get_my_trans_mode(ewk->wu.my_mts);
    return 0;
}
