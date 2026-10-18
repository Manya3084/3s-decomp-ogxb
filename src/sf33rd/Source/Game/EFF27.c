/* EFF27.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * xb_effect_27_draw 0x39C46 size 0x1C. FLAG: x86-only callees
 * obr_no_disp_check,sort_push_request4.
 * effect_27_move 0x39C62 size 0xB9.
 * eff27_02 0x39D1B size 0x34.
 * eff27_06 0x39D4F size 0x31.
 * eff27_09 0x39D80 size 0x58.
 * set_second_hop 0x39DD8 size 0x61. Read against the x86: 0x26 is the 38-byte
 * scr_obj record size, and +2 and +0x16 are the ptr += 2 steps into it. The C
 * is the PS2 C.
 * dead_check27 0x39E39 size 0x1B.
 * effect_27_init 0x39E54 size 0x1C7.
 * eff27_00 0x3A01B size 0x4C.
 * eff27_03 0x3A067 size 0x9A.
 * eff27_04 0x3A101 size 0x67.
 * eff27_05 0x3A168 size 0x6D.
 * eff27_07 0x3A1D5 size 0x9D.
 * eff27_08 0x3A272 size 0x34.
 * add_x_sub is folded into 0xEF072.
 * add_y_sub is folded into 0xEF088.
 * all_cgps_put_back is folded into 0x4384A.
 * Data: scr_obj_data27 is 0x32ADA8, 2 pointers whose arrays were compared.
 * Data: scr_obj_num27 is 0x24DC98, 0x4 bytes compared.
 * Data: piece_0000 is 0x24DCA0, 0x72 bytes compared.
 * Data: piece_0001 is 0x24DD18, 0x72 bytes compared.
 * Data: eff27_jp_tbl is 0x32ADB0, 11 entries compared.
 * Globals: scr_obj_num27 0x24DC98, scr_obj_data27 0x32ADA8, eff27_jp_tbl
 * 0x32ADB0, char_add 0x332CC8, EXE_obroll 0x7A8111, Game_pause 0x7A89B0, bg_w
 * 0x7BC520, EXE_flag 0xC7C834, frw 0xC806A0.
 */

#include "structs.h"

#define EFFECT_MAX 128

void sub_000EF072(WORK_Other* ewk);
void sub_000EF088(WORK_Other* ewk);
void sub_0004384A(WORK* wk);
s32 sort_push_request4(WORK* wk);
s32 obr_no_disp_check(void);
void eff27_00(WORK_Other* ewk);
void eff27_02(WORK_Other* ewk);
void eff27_03(WORK_Other* ewk);
void eff27_04(WORK_Other* ewk);
void eff27_05(WORK_Other* ewk);
void eff27_06(WORK_Other* ewk);
void eff27_07(WORK_Other* ewk);
void eff27_08(WORK_Other* ewk);
void eff27_09(WORK_Other* ewk);
void set_char_move_init(WORK* wk, s16 koc, s16 index);
s32 compel_dead_check(WORK_Other* ewk);
extern s16 EXE_flag;
extern u8 Game_pause;
extern s8 EXE_obroll;
void disp_pos_trans_entry_rs(WORK_Other* ewk);
void push_effect_work(WORK* wkhd);
void char_move(WORK* wk);
void dead_check27(WORK_Other* ewk);
void char_move_z(WORK* wk);
void set_second_hop(WORK_Other* ewk);
s32 effect_27_init(WORK_Other* oya, s16 type);
s16 pull_effect_work(s16 index);
extern uintptr_t frw[EFFECT_MAX][448];
extern u32* char_add[];
extern BG bg_w;
void suzi_offset_set(WORK_Other* ewk);
s16 get_my_trans_mode(s16 curr);

void (*eff27_jp_tbl[11])(WORK_Other*);

const s16 scr_obj_num27[2] = { 3, 3 };

const s16 piece_0000[57] = { 2, 8492, -36, 15, 70, 7, 1, 0, 6, 0,   -16, 2,  0,      0, 0, 5, -32768, -1, -32768,
                             2, 8492, -52, 18, 10, 8, 1, 0, 6, 0,   -16, 2,  0,      0, 0, 5, -32768, -1, -32768,
                             2, 8492, -40, 22, 70, 9, 1, 0, 2, 120, 0,   -2, -32768, 0, 0, 6, 0,      -1, -32768 };

const s16 piece_0001[57] = { 2, 8492, 14,  80, 70, 51, 1, 0, 2, 32, 32, 2,  0, 0, 0, 6, -32768, -1, -24576,
                             2, 8492, -4,  96, 10, 50, 1, 0, 2, 52, 52, -2, 0, 0, 0, 7, -32768, -1, -24576,
                             2, 8492, -26, 88, 10, 49, 1, 0, 7, 16, 16, -3, 0, 0, 0, 6, -32768, -1, -12288 };

const s16* scr_obj_data27[2] = { piece_0000, piece_0001 };

void (*eff27_jp_tbl[11])(WORK_Other*) = { eff27_00, eff27_00, eff27_02, eff27_03, eff27_04, eff27_05,
                                          eff27_06, eff27_06, eff27_07, eff27_08, eff27_09 };

void effect_27_move(WORK_Other* ewk) {
    WORK_Other* oya;

    if (obr_no_disp_check()) {
        return;
    }

    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.routine_no[1] = 0;
        ewk->wu.disp_flag = 1;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        oya = (WORK_Other*)ewk->my_master;
        ewk->wu.old_rno[3] = oya->wu.routine_no[1];
        /* fallthrough */

    case 1:
        if (compel_dead_check(ewk)) {
            ewk->wu.routine_no[0] = 99;
            ewk->wu.disp_flag = 0;
            break;
        }

        if (!EXE_flag && !Game_pause && !EXE_obroll) {
            eff27_jp_tbl[ewk->wu.old_rno[0]](ewk);
        }

        disp_pos_trans_entry_rs(ewk);
        break;

    case 2:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 0;
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

void eff27_00(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (ewk->wu.hit_stop) {
            char_move(&ewk->wu);
        }

        sub_000EF072(ewk);
        sub_000EF088(ewk);

        if (ewk->wu.xyz[1].disp.pos < ewk->wu.old_rno[1]) {
            ewk->wu.routine_no[1]++;
        }

        break;

    case 1:
        if (!ewk->wu.old_rno[0]) {
            dead_check27(ewk);
        }

        break;
    }
}

void eff27_02(WORK_Other* ewk) {
    if (ewk->wu.hit_stop) {
        char_move(&ewk->wu);
    }

    sub_000EF072(ewk);
    sub_000EF088(ewk);

    ewk->wu.old_rno[1]--;

    if (ewk->wu.old_rno[1] < 0) {
        ewk->wu.routine_no[0] = 2;
    }
}

void eff27_03(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (ewk->wu.cg_type != 2) {
            char_move(&ewk->wu);
        }

        sub_000EF072(ewk);
        sub_000EF088(ewk);

        if (ewk->wu.xyz[1].disp.pos < ewk->wu.old_rno[1]) {
            char_move_z(&ewk->wu);
            ewk->wu.routine_no[1]++;
            set_second_hop(ewk);
        }

        break;

    case 1:
        if (ewk->wu.cg_type != 2) {
            char_move(&ewk->wu);
        }

        sub_000EF072(ewk);
        sub_000EF088(ewk);

        if (ewk->wu.xyz[1].disp.pos <= ewk->wu.old_rno[2]) {
            ewk->wu.routine_no[1]++;
        }

        break;

    case 2:
        if (ewk->wu.cg_type != 1) {
            char_move(&ewk->wu);
        }

        dead_check27(ewk);
        break;
    }
}

void eff27_04(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (ewk->wu.cg_type != 2) {
            char_move(&ewk->wu);
        }

        sub_000EF072(ewk);
        sub_000EF088(ewk);

        if (ewk->wu.xyz[1].disp.pos < ewk->wu.old_rno[1]) {
            char_move_z(&ewk->wu);
            ewk->wu.routine_no[1]++;
        }

        break;

    case 1:
        char_move(&ewk->wu);

        if (ewk->wu.cg_type == 1) {
            ewk->wu.routine_no[1]++;
        }

        break;

    case 2:
        dead_check27(ewk);
        break;
    }
}

void eff27_05(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (ewk->wu.cg_type != 2) {
            char_move(&ewk->wu);
        }

        sub_000EF072(ewk);
        sub_000EF088(ewk);

        if (ewk->wu.xyz[1].disp.pos < ewk->wu.old_rno[1]) {
            char_move_z(&ewk->wu);
            ewk->wu.routine_no[1]++;
        }

        break;

    case 1:
        char_move(&ewk->wu);

        if (ewk->wu.cg_type == 1) {
            ewk->wu.routine_no[1]++;
            set_second_hop(ewk);
        }

        break;

    case 2:
        eff27_03(ewk);
        break;
    }
}

void eff27_06(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        char_move(&ewk->wu);

        if (ewk->wu.cg_type != 1) {
            break;
        }

        if (ewk->wu.old_rno[0] == 6) {
            ewk->wu.routine_no[1]++;
            break;
        }

        ewk->wu.routine_no[0] = 2;
        break;

    case 1:
        break;
    }
}

void eff27_07(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (ewk->wu.cg_type != 2) {
            char_move(&ewk->wu);
        }

        sub_000EF072(ewk);
        sub_000EF088(ewk);

        if (ewk->wu.xyz[1].disp.pos < ewk->wu.old_rno[1]) {
            char_move_z(&ewk->wu);
            ewk->wu.routine_no[1]++;
            set_second_hop(ewk);
        }

        break;

    case 1:
        if (ewk->wu.cg_type != 2) {
            char_move(&ewk->wu);
        }

        sub_000EF072(ewk);
        sub_000EF088(ewk);

        if (ewk->wu.xyz[1].disp.pos <= ewk->wu.old_rno[2]) {
            ewk->wu.routine_no[1]++;
        }

        break;

    case 2:
        if (ewk->wu.cg_type != 1) {
            char_move(&ewk->wu);
            break;
        }

        ewk->wu.routine_no[1]++;
        break;

    case 3:
        break;
    }
}

void eff27_08(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        eff27_03(ewk);
        break;

    case 1:
        effect_27_init(ewk, 4);
        ewk->wu.routine_no[1]++;
        break;

    case 2:
        ewk->wu.routine_no[0] = 2;
        break;
    }
}

void eff27_09(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        char_move(&ewk->wu);

        if (ewk->wu.cg_type != 1) {
            break;
        }

        ewk->wu.routine_no[1]++;
        ewk->wu.xyz[0].disp.pos = ewk->wu.old_rno[1];
        ewk->wu.xyz[1].disp.pos = ewk->wu.old_rno[2];

        if (ewk->wu.mvxy.a[0].real.h > 0) {
            set_char_move_init(&ewk->wu, 0, ewk->wu.mvxy.a[0].real.h);
        }

        break;

    case 1:
        char_move(&ewk->wu);
        break;
    }
}

void set_second_hop(WORK_Other* ewk) {
    const s16* ptr;

    ewk->wu.xyz[1].disp.pos = ewk->wu.old_rno[1];
    ewk->wu.mvxy.d[0].sp = ewk->wu.mvxy.d[0].sp >> 1;
    ewk->wu.mvxy.d[1].sp = ewk->wu.mvxy.d[1].sp >> 1;
    ptr = scr_obj_data27[ewk->wu.type];
    ptr += 11;
    ptr += ewk->wu.direction * 19;
    ewk->wu.mvxy.a[0].real.h = *ptr++;
    ewk->wu.mvxy.a[0].real.l = *ptr++;
    ptr += 2;
    ewk->wu.mvxy.a[1].real.h = *ptr++;
    ewk->wu.mvxy.a[1].real.l = *ptr++;
    ewk->wu.mvxy.a[0].sp = ewk->wu.mvxy.a[0].sp >> 1;
    ewk->wu.mvxy.a[1].sp = ewk->wu.mvxy.a[1].sp >> 1;
}

void dead_check27(WORK_Other* ewk) {
    WORK_Other* oya = (WORK_Other*)ewk->my_master;

    if (ewk->wu.old_rno[3] != oya->wu.routine_no[1]) {
        ewk->wu.routine_no[0] = 2;
    }
}

s32 effect_27_init(WORK_Other* oya, s16 type) {
    WORK_Other* ewk;
    s16 ix;
    s16 lp_cnt = scr_obj_num27[type];
    s16 i;
    const s16* data_ptr;

    if (!lp_cnt) {
        return 0;
    }

    for (data_ptr = scr_obj_data27[type], i = 0; i < lp_cnt; i++) {
        if ((ix = pull_effect_work(4)) == -1) {
            return -1;
        }

        ewk = (WORK_Other*)frw[ix];
        ewk->my_master = (u32*)oya;
        ewk->wu.be_flag = 1;
        ewk->wu.id = 0x1B;
        ewk->wu.work_id = 0x10;
        ewk->wu.cgromtype = 1;
        ewk->wu.rl_flag = 0;
        ewk->wu.my_col_mode = 0x4200;
        ewk->wu.type = type;
        ewk->wu.direction = i;
        ewk->wu.dead_f = 1;
        ewk->wu.my_family = *data_ptr++;
        ewk->wu.my_col_code = *data_ptr++;
        ewk->wu.xyz[0].disp.pos = *data_ptr++;
        ewk->wu.xyz[1].disp.pos = *data_ptr++;
        ewk->wu.xyz[0].disp.pos += oya->wu.xyz[0].disp.pos;
        ewk->wu.xyz[1].disp.pos += oya->wu.xyz[1].disp.pos;
        ewk->wu.my_priority = ewk->wu.position_z = *data_ptr++;
        ewk->wu.char_index = *data_ptr++;
        ewk->wu.hit_stop = *data_ptr++;
        ewk->wu.sync_suzi = *data_ptr++;
        ewk->wu.old_rno[0] = *data_ptr++;
        ewk->wu.old_rno[1] = *data_ptr++;
        ewk->wu.old_rno[2] = *data_ptr++;
        ewk->wu.mvxy.a[0].real.h = *data_ptr++;
        ewk->wu.mvxy.a[0].real.l = *data_ptr++;
        ewk->wu.mvxy.d[0].real.h = *data_ptr++;
        ewk->wu.mvxy.d[0].real.l = *data_ptr++;
        ewk->wu.mvxy.a[1].real.h = *data_ptr++;
        ewk->wu.mvxy.a[1].real.l = *data_ptr++;
        ewk->wu.mvxy.d[1].real.h = *data_ptr++;
        ewk->wu.mvxy.d[1].real.l = *data_ptr++;
        ewk->wu.char_table[0] = char_add[bg_w.bg_index];
        suzi_offset_set(ewk);
        ewk->wu.my_mts = 7;
        ewk->wu.my_trans_mode = get_my_trans_mode(ewk->wu.my_mts);
    }

    return 0;
}

void xb_effect_27_draw(WORK_Other* ewk) {
    if (obr_no_disp_check()) {
        return;
    }

    switch (ewk->wu.routine_no[0]) {
    case 1:
        sort_push_request4(&ewk->wu);
        break;
    }
}
