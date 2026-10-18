/* EFF78.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * crow_fuss_check 0x412DD size 0x5E.
 * crow_fuss_move 0x4133B size 0x214. Read against the x86: the unnamed words
 * are a position table at 0x24F6C8. The C is the PS2 C.
 * effect_78_init 0x4154F size 0xD4.
 * effect_78_move 0x41623 size 0x99.
 * add_x_sub is folded into 0xEF072.
 * add_y_sub is folded into 0xEF088.
 * all_cgps_put_back is folded into 0x4384A.
 * disp_pos_trans_entry is folded into 0xEF0C0.
 * Data: eff78_data_tbl is 0x24F6C0, 0x8 bytes compared.
 * Data: crow_char_tbl is 0x24F6C8, 0x12 bytes compared, found by the bytes.
 * Data: _j10_char_table is 0x304C90, the char table effect_78_init stores.
 * Globals: eff78_data_tbl 0x24F6C0, crow_char_tbl 0x24F6C8, EXE_obroll
 * 0x7A8111, Game_pause 0x7A89B0, bg_w 0x7BC520, EXE_flag 0xC7C834, plw
 * 0xC7CEA0, frw 0xC806A0.
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
extern s8 EXE_obroll;
s32 crow_fuss_check(WORK_Other* ewk);
void char_move(WORK* wk);
void crow_fuss_move(WORK_Other* ewk);
void push_effect_work(WORK* wkhd);
extern BG bg_w;
extern PLW plw[2];
void cal_all_speed_data(WORK* wk, s16 tm, s16 x1, s16 y1, s8 xsw, s8 ysw);
s16 pull_effect_work(s16 index);
extern uintptr_t frw[EFFECT_MAX][448];
s16 get_my_trans_mode(s16 curr);
extern u32 _j10_char_table[];

const s16 eff78_data_tbl[4] = { 416, 71, 912, 64 };

const s16 crow_char_tbl[3][3] = { { 8, 0, 64 }, { 18, -16, 64 }, { 13, 16, 64 } };

void effect_78_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        break;

    case 1:
        if (!EXE_flag && !Game_pause && !EXE_obroll && crow_fuss_check(ewk)) {
            char_move(&ewk->wu);
        }

        sub_000EF0C0(ewk);
        break;

    case 2:
        if (!EXE_flag && !Game_pause && !EXE_obroll) {
            crow_fuss_move(ewk);
        }

        sub_000EF0C0(ewk);
        break;

    default:
        sub_0004384A(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}

s32 crow_fuss_check(WORK_Other* ewk) {
    s16 work;

    if (bg_w.quake_y_index > 3) {
        ewk->wu.routine_no[0]++;
        ewk->wu.routine_no[1] = 0;
        ewk->wu.direction = 0;

        work = plw[0].wu.xyz[0].disp.pos + plw[1].wu.xyz[0].disp.pos;
        work >>= 1;
        work = ewk->wu.xyz[0].disp.pos - work;

        if (work > 64) {
            ewk->wu.direction = 2;
        } else if (work < -64) {
            ewk->wu.direction = 1;
        }

        return 0;
    }

    return 1;
}

void crow_fuss_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;
        ewk->wu.old_rno[0] = crow_char_tbl[ewk->wu.direction][0];
        set_char_move_init(&ewk->wu, 0, ewk->wu.old_rno[0]);
        break;

    case 1:
        char_move(&ewk->wu);

        if (ewk->wu.cg_type == 0xFF) {
            ewk->wu.routine_no[1]++;
            set_char_move_init(&ewk->wu, 0, ewk->wu.old_rno[0] + 1);
            ewk->wu.dir_timer = 28;
            ewk->wu.old_rno[1] = ewk->wu.xyz[0].disp.pos + crow_char_tbl[ewk->wu.direction][1];
            ewk->wu.old_rno[2] = ewk->wu.xyz[1].disp.pos + crow_char_tbl[ewk->wu.direction][2];
            cal_all_speed_data(&ewk->wu, ewk->wu.dir_timer, ewk->wu.old_rno[1], ewk->wu.old_rno[2], 2, 2);
        }

        break;

    case 2:
        char_move(&ewk->wu);
        ewk->wu.dir_timer--;

        if (ewk->wu.dir_timer < 1) {
            ewk->wu.routine_no[1]++;
            ewk->wu.dir_timer = 4;
            set_char_move_init(&ewk->wu, 0, ewk->wu.old_rno[0] + 2);
        } else {
            sub_000EF072(ewk);
            sub_000EF088(ewk);
        }

        break;

    case 3:
        char_move(&ewk->wu);
        ewk->wu.dir_timer--;

        if (ewk->wu.dir_timer < 1) {
            ewk->wu.routine_no[1]++;
        }

        break;

    case 4:
        char_move(&ewk->wu);

        if (ewk->wu.cg_type == 0xFF) {
            ewk->wu.routine_no[1]++;
            set_char_move_init(&ewk->wu, 0, ewk->wu.old_rno[0] + 3);
            ewk->wu.dir_timer = 48;
            ewk->wu.old_rno[1] = eff78_data_tbl[ewk->wu.type << 1];
            ewk->wu.old_rno[2] = eff78_data_tbl[(ewk->wu.type << 1) + 1];
            cal_all_speed_data(&ewk->wu, ewk->wu.dir_timer, ewk->wu.old_rno[1], ewk->wu.old_rno[2] + 4, 0, 0);
        }

        break;

    case 5:
        ewk->wu.dir_timer--;
        sub_000EF072(ewk);
        sub_000EF088(ewk);
        char_move(&ewk->wu);

        if (ewk->wu.cg_type == 2) {
            ewk->wu.routine_no[1]++;
        }

        break;

    case 6:
        ewk->wu.dir_timer--;

        if (ewk->wu.dir_timer < 1) {
            ewk->wu.routine_no[1]++;
            ewk->wu.xyz[0].disp.pos = ewk->wu.old_rno[1];
            ewk->wu.xyz[1].disp.pos = ewk->wu.old_rno[2];
            set_char_move_init(&ewk->wu, 0, ewk->wu.old_rno[0] + 4);
        } else {
            sub_000EF072(ewk);
            sub_000EF088(ewk);
        }

        break;

    case 7:
        char_move(&ewk->wu);

        if (ewk->wu.cg_type == 0xFF) {
            ewk->wu.routine_no[0] = 1;
            set_char_move_init(&ewk->wu, 0, 4);
        }

        break;
    }
}

s32 effect_78_init() {
    WORK_Other* ewk;
    s16 ix;
    s16 i;
    const s16* data_ptr = eff78_data_tbl;

    for (i = 0; i < 2; i++) {
        if ((ix = pull_effect_work(4)) == -1) {
            return -1;
        }

        ewk = (WORK_Other*)frw[ix];
        ewk->wu.be_flag = 1;
        ewk->wu.id = 78;
        ewk->wu.work_id = 16;
        ewk->wu.cgromtype = 1;
        ewk->wu.rl_flag = 0;
        ewk->wu.type = i;
        ewk->wu.dead_f = 0;
        ewk->wu.my_family = 2;
        ewk->wu.my_col_mode = 0x4200;
        ewk->wu.my_col_code = 8492;
        ewk->wu.my_mts = 7;
        ewk->wu.my_trans_mode = get_my_trans_mode(ewk->wu.my_mts);
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos = *data_ptr++;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos = *data_ptr++;
        ewk->wu.position_z = ewk->wu.my_priority = 83;
        ewk->wu.char_index = 4;
        ewk->wu.char_table[0] = _j10_char_table;
        ewk->wu.hit_stop = 0;
    }

    return 0;
}
