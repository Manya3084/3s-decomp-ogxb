/* EFF26.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * effect_26_move 0x39556 size 0xA7.
 * eff26_00 0x395FD size 0x37.
 * eff26_01 0x39634 size 0x94.
 * eff26_02 0x396C8 size 0xC4.
 * eff26_03 0x3978C size 0x10A.
 * eff26_04 0x39896 size 0x121.
 * eff26_05 0x399B7 size 0x13D.
 * effect_26_init 0x39AF4 size 0x152.
 * all_cgps_put_back is folded into 0x4384A.
 * Data: scr_obj_data26 is 0x32ADA4, 1 pointers whose arrays were compared.
 * Data: eff26_num: not located in the XBE, PS2 initializer kept.
 * Data: eff26_data_0000 is 0x24DC94, 0x2 bytes compared.
 * Data: eff26_jp_tbl is 0x32AD8C, 6 entries compared.
 * Unnamed data used (not checked): effect_26_init: 0x24dc90.
 * Globals: eff26_jp_tbl 0x32AD8C, scr_obj_data26 0x32ADA4, char_add 0x332CC8,
 * EXE_obroll 0x7A8111, Game_pause 0x7A89B0, eff_hit_flag 0x7A99C0, bg_w
 * 0x7BC520, EXE_flag 0xC7C834, frw 0xC806A0.
 */

#include "structs.h"

#define EFFECT_MAX 128

void sub_0004384A(WORK* wk);
void eff26_00(WORK_Other* ewk);
void eff26_01(WORK_Other* ewk);
void eff26_02(WORK_Other* ewk);
void eff26_03(WORK_Other* ewk);
void eff26_04(WORK_Other* ewk);
void eff26_05(WORK_Other* ewk);
s32 obr_no_disp_check();
s32 compel_dead_check(WORK_Other* ewk);
void set_char_move_init(WORK* wk, s16 koc, s16 index);
extern s16 EXE_flag;
extern u8 Game_pause;
void disp_pos_trans_entry_rs(WORK_Other* ewk);
void push_effect_work(WORK* wkhd);
void piece_set(WORK_Other* ewk);
extern s8 EXE_obroll;
void char_move(WORK* wk);
extern s16 eff_hit_flag[11];
s16 eff_hit_check(WORK_Other* ewk, s16 type);
s32 effect_27_init(WORK_Other* oya, s16 type);
s16 pull_effect_work(s16 index);
extern uintptr_t frw[EFFECT_MAX][448];
extern u32* char_add[];
extern BG bg_w;
void suzi_offset_set(WORK_Other* ewk);

void (*eff26_jp_tbl[6])(WORK_Other*);

const s16 eff26_num[1] = { 1 };

const s16 eff26_data_0000[1] = { 0 };

void (*eff26_jp_tbl[6])(WORK_Other*) = { eff26_00, eff26_01, eff26_02, eff26_03, eff26_04, eff26_05 };

const s16* scr_obj_data26[1] = { eff26_data_0000 };

void effect_26_move(WORK_Other* ewk) {
    WORK_Other* oya;

    if (obr_no_disp_check()) {
        return;
    }

    if (compel_dead_check(ewk)) {
        ewk->wu.routine_no[0] = 99;
        ewk->wu.disp_flag = 0;
        return;
    }

    oya = (WORK_Other*)ewk->my_master;

    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.routine_no[1] = 0;
        ewk->wu.disp_flag = 1;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        break;

    case 1:
        if (!EXE_flag && !Game_pause) {
            eff26_jp_tbl[ewk->wu.old_rno[2] / 2](ewk);
        }

        disp_pos_trans_entry_rs(ewk);
        break;

    case 2:
        ewk->wu.disp_flag = 0;
        ewk->wu.routine_no[0]++;
        break;

    case 3:
        ewk->wu.routine_no[0]++;
        break;

    default:
        sub_0004384A(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}

void eff26_00(WORK_Other* ewk) {
    WORK_Other* oya = (WORK_Other*)ewk->my_master;

    if (oya->wu.routine_no[1] > 1) {
        ewk->wu.routine_no[0] = 2;
        piece_set(ewk);
        return;
    }

    if (ewk->wu.hit_stop && !EXE_obroll) {
        char_move(&ewk->wu);
    }
}

void eff26_01(WORK_Other* ewk) {
    WORK_Other* oya = (WORK_Other*)ewk->my_master;

    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;

        if (eff_hit_flag[oya->wu.type]) {
            ewk->wu.routine_no[0] = 99;
            break;
        }

        /* fallthrough */

    case 1:
        if (ewk->wu.hit_stop && !EXE_obroll) {
            char_move(&ewk->wu);
        }

        if (oya->wu.routine_no[1] > 1) {
            ewk->wu.routine_no[1]++;
            piece_set(ewk);
            set_char_move_init(&ewk->wu, 0, ewk->wu.old_rno[1]);
        }

        break;

    case 2:
        if (!EXE_obroll) {
            char_move(&ewk->wu);
        }

        if (ewk->wu.cg_type == 1) {
            ewk->wu.routine_no[0] = 2;
        }

        break;
    }
}

void eff26_02(WORK_Other* ewk) {
    WORK_Other* oya = (WORK_Other*)ewk->my_master;

    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;

        if (eff_hit_flag[oya->wu.type]) {
            ewk->wu.routine_no[1] = 3;
            ewk->wu.disp_flag = 1;
            set_char_move_init(&ewk->wu, 0, ewk->wu.old_rno[7]);
            break;
        }

        /* fallthrough */

    case 1:
        if (ewk->wu.hit_stop && !EXE_obroll) {
            char_move(&ewk->wu);
        }

        if (oya->wu.routine_no[1] > 1) {
            ewk->wu.routine_no[1]++;
            piece_set(ewk);
            set_char_move_init(&ewk->wu, 0, ewk->wu.old_rno[1]);
        }

        break;

    case 2:
        if (!EXE_obroll) {
            char_move(&ewk->wu);
        }

        if (ewk->wu.cg_type == 1) {
            ewk->wu.routine_no[1]++;
        }

        break;

    case 3:
        if (!EXE_obroll) {
            char_move(&ewk->wu);
        }

        break;
    }
}

void eff26_03(WORK_Other* ewk) {
    WORK_Other* oya = (WORK_Other*)ewk->my_master;

    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;

        if (eff_hit_flag[oya->wu.type]) {
            ewk->wu.routine_no[1] = 3;
            set_char_move_init(&ewk->wu, 0, ewk->wu.old_rno[1]);
            goto case_3;
        }

    case 1:
        if (ewk->wu.hit_stop && !EXE_obroll) {
            char_move(&ewk->wu);
        }

        if (oya->wu.routine_no[1] > 1) {
            ewk->wu.routine_no[1]++;
            piece_set(ewk);
            set_char_move_init(&ewk->wu, 0, ewk->wu.old_rno[1]);
        }

        break;

    case 2:
        if (!EXE_obroll) {
            char_move(&ewk->wu);
        }

        if (ewk->wu.cg_type == 1) {
            ewk->wu.routine_no[1]++;
        }

        break;

    case 3:
    case_3:
        ewk->wu.routine_no[1]++;

        if (eff_hit_flag[ewk->wu.type]) {
            ewk->wu.routine_no[0] = 99;
            break;
        }

        ewk->wu.disp_flag = 1;

    case 4:
        if (eff_hit_check(ewk, ewk->wu.old_rno[4])) {
            if (ewk->wu.old_rno[2] & 1 && ewk->wu.old_rno[5] > 0) {
                effect_27_init(ewk, ewk->wu.old_rno[5]);
            }

            ewk->wu.routine_no[0] = 2;
        }

        break;
    }
}

void eff26_04(WORK_Other* ewk) {
    WORK_Other* oya = (WORK_Other*)ewk->my_master;

    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (eff_hit_flag[oya->wu.type]) {
            ewk->wu.routine_no[1] = 2;
            goto case_2;
        }

        if (ewk->wu.hit_stop && !EXE_obroll) {
            char_move(&ewk->wu);
        }

        if (oya->wu.routine_no[1] > 1) {
            ewk->wu.routine_no[1]++;
            piece_set(ewk);
            set_char_move_init(&ewk->wu, 0, ewk->wu.old_rno[1]);
        }

        break;

    case 1:
        if (!EXE_obroll) {
            char_move(&ewk->wu);
        }

        if (ewk->wu.cg_type == 1) {
            ewk->wu.routine_no[1]++;
        }

        break;

    case 2:
    case_2:
        ewk->wu.routine_no[1]++;

        if (eff_hit_flag[ewk->wu.type]) {
            ewk->wu.routine_no[0] = 99;
            break;
        }

        /* fallthrough */

    case 3:
        if (eff_hit_check(ewk, ewk->wu.old_rno[4])) {
            ewk->wu.routine_no[1]++;

            if (ewk->wu.old_rno[2] & 1 && ewk->wu.old_rno[5] > 0) {
                effect_27_init(ewk, ewk->wu.old_rno[5]);
            }

            set_char_move_init(&ewk->wu, 0, ewk->wu.old_rno[3]);
        }

        /* fallthrough */

    case 4:
        if (!EXE_obroll) {
            char_move(&ewk->wu);
        }

        if (ewk->wu.cg_type == 1) {
            ewk->wu.routine_no[0] = 2;
        }

        break;
    }
}

void eff26_05(WORK_Other* ewk) {
    WORK_Other* oya = (WORK_Other*)ewk->my_master;

    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;

        if (eff_hit_flag[oya->wu.type]) {
            ewk->wu.routine_no[2] = 3;
            set_char_move_init(&ewk->wu, 0, ewk->wu.old_rno[1]);
            goto case_3;
        }

        /* fallthrough */

    case 1:
        if (ewk->wu.hit_stop && !EXE_obroll) {
            char_move(&ewk->wu);
        }

        if (oya->wu.routine_no[1] > 1) {
            ewk->wu.routine_no[1]++;
            piece_set(ewk);
            set_char_move_init(&ewk->wu, 0, ewk->wu.old_rno[1]);
        }

        break;

    case 2:
        if (!EXE_obroll) {
            char_move(&ewk->wu);
        }

        if (ewk->wu.cg_type == 1) {
            ewk->wu.routine_no[1]++;
        }

        break;

    case 3:
    case_3:
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;

        if (eff_hit_flag[ewk->wu.type]) {
            ewk->wu.routine_no[1] = 7;
            set_char_move_init(&ewk->wu, 0, ewk->wu.old_rno[7]);
            break;
        }

        /* fallthrough */

    case 4:
        if (!eff_hit_check(ewk, ewk->wu.old_rno[4])) {
            break;
        }

        ewk->wu.routine_no[1]++;

        if (ewk->wu.old_rno[2] & 1 && ewk->wu.old_rno[5] > 0) {
            effect_27_init(ewk, ewk->wu.old_rno[5]);
        }

        set_char_move_init(&ewk->wu, 0, ewk->wu.old_rno[3]);
        break;

    case 5:
        if (!EXE_obroll) {
            char_move(&ewk->wu);
        }

        if (ewk->wu.cg_type == 1) {
            ewk->wu.routine_no[1]++;
        }

        break;

    case 7:
        if (!EXE_obroll) {
            char_move(&ewk->wu);
        }

        break;
    }
}

s32 effect_26_init(WORK_Other* oya, s16 type26) {
    WORK_Other* ewk;
    s16 ix;
    s16 lp_cnt = eff26_num[type26];
    s16 i;
    const s16* data_ptr;

    if (!lp_cnt) {
        return 0;
    }

    for (data_ptr = scr_obj_data26[type26], i = 0; i < lp_cnt; i++) {
        if ((ix = pull_effect_work(4)) == -1) {
            return -1;
        }

        ewk = (WORK_Other*)frw[ix];
        ewk->wu.be_flag = 1;
        ewk->wu.id = 26;
        ewk->wu.work_id = 16;
        ewk->my_master = (u32*)oya;
        ewk->wu.cgromtype = 1;
        ewk->wu.rl_flag = 0;
        ewk->wu.my_col_mode = 0x4200;
        ewk->wu.dead_f = *data_ptr++;
        ewk->wu.type = (s8)*data_ptr++;
        ewk->wu.my_family = *data_ptr++;
        ewk->wu.my_col_code = *data_ptr++;
        ewk->wu.xyz[0].disp.pos = *data_ptr++;
        ewk->wu.xyz[1].disp.pos = *data_ptr++;
        ewk->wu.position_z = *data_ptr++;
        ewk->wu.char_index = *data_ptr++;
        ewk->wu.hit_stop = *data_ptr++;
        ewk->wu.sync_suzi = *data_ptr++;
        ewk->wu.old_rno[0] = *data_ptr++;
        ewk->wu.old_rno[1] = *data_ptr++;
        ewk->wu.old_rno[2] = *data_ptr++;
        ewk->wu.old_rno[3] = *data_ptr++;
        ewk->wu.old_rno[7] = *data_ptr++;
        ewk->wu.old_rno[4] = *data_ptr++;
        ewk->wu.old_rno[5] = *data_ptr++;
        ewk->wu.char_table[0] = char_add[bg_w.bg_index];
        suzi_offset_set(ewk);
    }

    return 0;
}
