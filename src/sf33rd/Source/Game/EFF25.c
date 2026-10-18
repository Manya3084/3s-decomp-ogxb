/* EFF25.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * xb_effect_25_draw 0x3905F size 0x33. FLAG: x86-only callees
 * compel_dead_check,obr_no_disp_check,range_x_check,sort_push_request4.
 * effect_25_move 0x39092 size 0x77.
 * eff25_char_set 0x39109 size 0x20.
 * piece_set 0x39129 size 0x20.
 * effect_25_init 0x39149 size 0x144.
 * eff25_00 0x3928D size 0xA4.
 * eff25_02 0x39331 size 0xB5.
 * eff25_06 0x393E6 size 0xCC.
 * eff25_04 is folded into 0x394B2 with 1 other bodies. Unnamed.
 * eff25_08 is folded into 0x394B2 with 1 other bodies. Unnamed.
 * all_cgps_put_back is folded into 0x4384A.
 * Data: scr_obj_data25 is 0x32AD60, 1 pointers whose arrays were compared.
 * Data: eff25_data_0000 is 0x24DC70, 0x20 bytes compared.
 * Data: eff25_jp_tbl is 0x32AD64, 10 entries compared.
 * Globals: scr_obj_data25 0x32AD60, eff25_jp_tbl 0x32AD64, char_add 0x332CC8,
 * EXE_obroll 0x7A8111, Game_pause 0x7A89B0, eff_hit_flag 0x7A99C0, bg_w
 * 0x7BC520, EXE_flag 0xC7C834, frw 0xC806A0.
 */

#include "structs.h"

#define EFFECT_MAX 128

void sub_0004384A(WORK* wk);
s32 sort_push_request4(WORK* wk);
s32 obr_no_disp_check(void);
s32 compel_dead_check(WORK_Other* ewk);
s32 range_x_check(WORK_Other* ewk);
extern void (*const D_0025B2C0[])(WORK* wk);
void eff25_00(WORK_Other* ewk);
void eff25_02(WORK_Other* ewk);
void eff25_04(WORK_Other* ewk);
void eff25_06(WORK_Other* ewk);
void eff25_08(WORK_Other* ewk);
extern s16 EXE_flag;
extern u8 Game_pause;
void disp_pos_trans_entry_rs(WORK_Other* ewk);
void push_effect_work(WORK* wkhd);
extern s16 eff_hit_flag[11];
void eff25_char_set(WORK_Other* ewk);
s16 eff_hit_check(WORK_Other* ewk, s16 type);
void piece_set(WORK_Other* ewk);
void set_char_move_init(WORK* wk, s16 koc, s16 index);
extern s8 EXE_obroll;
void char_move(WORK* wk);
s32 effect_27_init(WORK_Other* oya, s16 type);
s16 pull_effect_work(s16 index);
extern uintptr_t frw[EFFECT_MAX][448];
s32 effect_26_init(WORK_Other* oya, s16 type26);
extern u32* char_add[];
extern BG bg_w;
void suzi_offset_set(WORK_Other* ewk);
s16 get_my_trans_mode(s16 curr);

const s16 eff25_data_0000[16] = { 0, 2, 300, 160, 32, 71, 6, 0, 0, 0, 6, 6, 66, 9, 0, -1 };

const s16* scr_obj_data25[1] = { eff25_data_0000 };

void (*eff25_jp_tbl[10])(WORK_Other* ewk) = { eff25_00, eff25_00, eff25_02, eff25_02, eff25_04,
                                              eff25_04, eff25_06, eff25_06, eff25_08, eff25_08 };

void effect_25_move(WORK_Other* ewk) {
    if (compel_dead_check(ewk)) {
        ewk->wu.routine_no[0] = 99;
        ewk->wu.disp_flag = 0;
        return;
    }

    switch (ewk->wu.routine_no[0]) {
    case 0:
        if (!EXE_flag && !Game_pause) {
            eff25_jp_tbl[ewk->wu.old_rno[2]](ewk);
        }

        disp_pos_trans_entry_rs(ewk);
        break;

    case 1:
    case 2:
    case 3:
        ewk->wu.disp_flag = 0;
        ewk->wu.routine_no[0]++;
        break;

    case 4:
        ewk->wu.routine_no[0]++;
        break;

    default:
        sub_0004384A(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}

void eff25_00(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (eff_hit_flag[ewk->wu.type]) {
            ewk->wu.routine_no[0] = 4;
            break;
        }

        eff25_char_set(ewk);
        break;

    case 1:
        if (eff_hit_check(ewk, ewk->wu.old_rno[4])) {
            piece_set(ewk);
            set_char_move_init(&ewk->wu, 0, ewk->wu.old_rno[1]);
            ewk->wu.routine_no[1]++;
            break;
        }

        if (ewk->wu.hit_stop && !EXE_obroll) {
            char_move(&ewk->wu);
        }

        break;

    case 2:
        if (!EXE_obroll) {
            char_move(&ewk->wu);
        }

        if (ewk->wu.cg_type) {
            ewk->wu.routine_no[1]++;
        }

        /* fallthrough */

    case 3:
        ewk->wu.routine_no[0]++;
        break;
    }
}

void eff25_02(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (eff_hit_flag[ewk->wu.type]) {
            ewk->wu.disp_flag = 1;
            ewk->wu.routine_no[1] = 4;
            set_char_move_init(&ewk->wu, 0, ewk->wu.old_rno[7]);
            break;
        }

        eff25_char_set(ewk);
        break;

    case 1:
        if (eff_hit_check(ewk, ewk->wu.old_rno[4])) {
            piece_set(ewk);
            ewk->wu.routine_no[1]++;
            set_char_move_init(&ewk->wu, 0, ewk->wu.old_rno[1]);
            break;
        }

        if (ewk->wu.hit_stop && !EXE_obroll) {
            char_move(&ewk->wu);
        }

        break;

    case 2:
        if (!EXE_obroll) {
            char_move(&ewk->wu);
        }

        if (ewk->wu.cg_type) {
            ewk->wu.routine_no[1]++;
        }

        break;

    case 3:
        break;

    case 4:
        if (!EXE_obroll) {
            char_move(&ewk->wu);
        }

        break;
    }
}

void eff25_04(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (eff_hit_flag[ewk->wu.type]) {
            ewk->wu.routine_no[0] = 4;
            break;
        }

        eff25_char_set(ewk);
        break;

    case 1:
        if (eff_hit_check(ewk, ewk->wu.old_rno[4])) {
            piece_set(ewk);
            ewk->wu.routine_no[1]++;
            break;
        }

        if (ewk->wu.hit_stop && !EXE_obroll) {
            char_move(&ewk->wu);
        }

        break;

    case 2:
        ewk->wu.routine_no[0]++;
        break;
    }
}

void eff25_06(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (eff_hit_flag[ewk->wu.type]) {
            ewk->wu.disp_flag = 1;
            set_char_move_init(&ewk->wu, 0, ewk->wu.old_rno[7]);
            ewk->wu.routine_no[1] = 4;
            break;
        }

        eff25_char_set(ewk);
        break;

    case 1:
        if (eff_hit_check(ewk, ewk->wu.old_rno[4])) {
            piece_set(ewk);
            ewk->wu.routine_no[1]++;
            set_char_move_init(&ewk->wu, 0, ewk->wu.old_rno[1]);
            break;
        }

        if (ewk->wu.hit_stop && !EXE_obroll) {
            char_move(&ewk->wu);
        }

        break;

    case 2:
        if (!EXE_obroll) {
            char_move(&ewk->wu);
        }

        if (ewk->wu.cg_type) {
            set_char_move_init(&ewk->wu, 0, ewk->wu.old_rno[3]);
            ewk->wu.routine_no[1]++;
            break;
        }

        break;

    case 3:
        break;

    case 4:
        if (!EXE_obroll) {
            char_move(&ewk->wu);
        }

        break;
    }
}

void eff25_08(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (eff_hit_flag[ewk->wu.type]) {
            ewk->wu.routine_no[0] = 4;
            break;
        }

        eff25_char_set(ewk);
        break;

    case 1:
        if (eff_hit_check(ewk, ewk->wu.old_rno[4])) {
            piece_set(ewk);
            ewk->wu.routine_no[1]++;
            break;
        }

        if (ewk->wu.hit_stop && !EXE_obroll) {
            char_move(&ewk->wu);
        }

        break;

    case 2:
        ewk->wu.routine_no[0]++;
        break;
    }
}

void eff25_char_set(WORK_Other* ewk) {
    ewk->wu.routine_no[1]++;
    ewk->wu.disp_flag = 1;
    set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
}

void piece_set(WORK_Other* ewk) {
    if (!(ewk->wu.old_rno[2] & 1)) {
        return;
    }

    if (ewk->wu.old_rno[0] < 0) {
        return;
    }

    effect_27_init(ewk, ewk->wu.old_rno[0]);
}

s32 effect_25_init(s8 num) {
    WORK_Other* ewk;
    s16 ix;
    const s16* data_ptr = scr_obj_data25[num];

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }

    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 25;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.rl_flag = 0;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.type = num;
    ewk->wu.dead_f = *data_ptr++;
    ewk->wu.my_family = *data_ptr++;
    ewk->wu.my_col_code = *data_ptr++;
    ewk->wu.xyz[0].disp.pos = *data_ptr++;
    ewk->wu.xyz[1].disp.pos = *data_ptr++;
    ewk->wu.my_priority = *data_ptr++;
    ewk->wu.char_index = *data_ptr++;
    ewk->wu.hit_stop = *data_ptr++;
    ewk->wu.sync_suzi = *data_ptr++;
    ewk->wu.old_rno[0] = *data_ptr++;
    ewk->wu.old_rno[1] = *data_ptr++;
    ewk->wu.old_rno[7] = *data_ptr++;
    ewk->wu.old_rno[3] = *data_ptr++;
    ewk->wu.old_rno[2] = *data_ptr++;
    ewk->wu.old_rno[4] = *data_ptr++;
    ewk->wu.position_z = ewk->wu.my_priority;

    if (*data_ptr >= 0) {
        effect_26_init(ewk, *data_ptr);
    }

    *data_ptr++;
    ewk->wu.char_table[0] = char_add[bg_w.bg_index];
    suzi_offset_set(ewk);
    ewk->wu.my_mts = 7;
    ewk->wu.my_trans_mode = get_my_trans_mode(ewk->wu.my_mts);
    return 0;
}

void xb_effect_25_draw(WORK_Other* ewk) {
    if (compel_dead_check(ewk)) {
        return;
    }

    if (ewk->wu.routine_no[0] == 0 && obr_no_disp_check() == 0 && range_x_check(ewk)) {
        sort_push_request4(&ewk->wu);
    }
}
