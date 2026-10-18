/* EFF86.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * eff86_0000 0x42235 size 0x75.
 * effect_86_init 0x422AA size 0xCF. Read against the x86: +2 is a word field
 * of the work. Matches the C.
 * effect_86_move 0x42379 size 0x53.
 * all_cgps_put_back is folded into 0x4384A.
 * disp_pos_trans_entry is folded into 0xEF0C0.
 * Data: eff86_adrs_tbl is 0x32B588, 1 pointers whose arrays were compared.
 * Data: eff86_data_tbl00 is 0x24F6F8, 0xE bytes compared.
 * Globals: _etc_char_table 0x2F9850, eff86_adrs_tbl 0x32B588, EXE_obroll
 * 0x7A8111, Game_pause 0x7A89B0, EXE_flag 0xC7C834, plw 0xC7CEA0, frw
 * 0xC806A0.
 */

#include "structs.h"

#define EFFECT_MAX 128

void sub_0004384A(WORK* wk);
void sub_000EF0C0(WORK_Other* ewk);
void eff86_0000(WORK_Other* ewk);
extern s16 EXE_flag;
extern u8 Game_pause;
extern s8 EXE_obroll;
void push_effect_work(WORK* wkhd);
extern PLW plw[2];
void set_char_move_init(WORK* wk, s16 koc, s16 index);
void char_move(WORK* wk);
s16 pull_effect_work(s16 index);
extern uintptr_t frw[EFFECT_MAX][448];
extern u32 _etc_char_table[];
s16 get_my_trans_mode(s16 curr);

const s16 eff86_data_tbl00[7] = { 0, 2, 8224, 511, 56, 10, 18 };

const s16* eff86_adrs_tbl[1] = { eff86_data_tbl00 };

void effect_86_move(WORK_Other* ewk) {
    void (*eff86_jp_tbl[1])(WORK_Other*) = { eff86_0000 };

    switch (ewk->wu.routine_no[0]) {
    case 0:
        if (!EXE_flag && !Game_pause && !EXE_obroll) {
            eff86_jp_tbl[ewk->wu.routine_no[1]](ewk);
        }

        sub_000EF0C0(ewk);
        return;

    default:
        sub_0004384A(&ewk->wu);
        push_effect_work(&ewk->wu);
    }
}

void eff86_0000(WORK_Other* ewk) {
    s16 work;

    switch (ewk->wu.routine_no[2]) {
    case 0:
        ewk->wu.routine_no[2]++;
        ewk->wu.disp_flag = 1;
        work = plw[0].wu.position_x + plw[1].wu.position_x;
        work >>= 1;
        ewk->wu.xyz[0].disp.pos = work;
        work = plw[1].wu.position_y + plw[1].wu.position_y;
        work >>= 1;
        ewk->wu.xyz[1].disp.pos = work + 92;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        break;

    case 1:
        char_move(&ewk->wu);

        if (ewk->wu.cg_type == 0xFF) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0]++;
        }

        break;
    }
}

s32 effect_86_init(s16 type86) {
    WORK_Other* ewk;
    s16 ix;
    const s16* data_ptr;

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }

    ewk = (WORK_Other*)frw[ix];
    data_ptr = eff86_adrs_tbl[type86];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 86;
    ewk->wu.work_id = 16;
    ewk->wu.type = type86;
    ewk->wu.cgromtype = 1;
    ewk->wu.rl_flag = 0;
    ewk->wu.dead_f = 1;
    ewk->wu.routine_no[1] = *data_ptr++;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_family = *data_ptr++;
    ewk->wu.my_col_code = *data_ptr++;
    ewk->wu.xyz[0].disp.pos = *data_ptr++;
    ewk->wu.xyz[1].disp.pos = *data_ptr++;
    ewk->wu.my_priority = ewk->wu.position_z = *data_ptr++;
    ewk->wu.char_index = *data_ptr++;
    ewk->wu.char_table[0] = _etc_char_table;
    ewk->wu.my_mts = 14;
    ewk->wu.my_trans_mode = get_my_trans_mode(ewk->wu.my_mts);
    return 0;
}
