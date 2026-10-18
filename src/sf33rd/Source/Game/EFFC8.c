/* EFFC8.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * effect_C8_move 0x46DB6 size 0x16D. Read against the x86: MSVC folded
 * effc8_data_tbl into immediates: a[0] 0x30000, d[0] 0x200, a[1] 0, d[1]
 * -0x1800, with a[0] and d[0] negated on the other side, which is the table's
 * contents. The C is the PS2 C.
 * effect_C8_init 0x46F23 size 0xBC.
 * add_x_sub is folded into 0xEF072.
 * add_y_sub is folded into 0xEF088.
 * all_cgps_put_back is folded into 0x4384A.
 * Data: effc8_data_tbl: not located in the XBE, PS2 initializer kept.
 * Globals: _etc_char_table 0x2F9850, Game_pause 0x7A89B0, EXE_flag 0xC7C834,
 * frw 0xC806A0.
 */

#include "structs.h"

#define EFFECT_MAX 128

void sub_000EF072(WORK_Other* ewk);
void sub_000EF088(WORK_Other* ewk);
void sub_0004384A(WORK* wk);
void set_char_move_init(WORK* wk, s16 koc, s16 index);
void set_char_move_init2(WORK* wk, s16 koc, s16 index, s16 ip, s16 scf);
void pl_eff_trans_entry(WORK_Other* ewk);
extern s16 EXE_flag;
extern u8 Game_pause;
void char_move(WORK* wk);
void push_effect_work(WORK* wkhd);
s16 pull_effect_work(s16 index);
extern uintptr_t frw[EFFECT_MAX][448];
extern u32 _etc_char_table[];
s16 get_my_trans_mode(s16 curr);

const s32 effc8_data_tbl[4] = { 0x30000, 0x200, 0, -0x1800 };

void effect_C8_move(WORK_Other* ewk) {
    PLW* oya_pl = (PLW*)ewk->my_master;
    s16 work;
    const s32* ptr;

    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init(&ewk->wu, 0, 12);
        break;

    case 1:
        switch (oya_pl->wu.routine_no[3]) {
        case 1:
            break;

        case 0:
        case 2:
            if (oya_pl->wu.cg_ix != ewk->wu.cg_ix) {
                work = oya_pl->wu.cg_ix / oya_pl->wu.cgd_type + 1;
                set_char_move_init2(&ewk->wu, 0, 12, work + 1, 0);
                ewk->wu.cg_ix = oya_pl->wu.cg_ix;
            }

            break;

        case 3:
            ewk->wu.routine_no[0]++;
            break;
        }

        pl_eff_trans_entry(ewk);
        break;

    case 2:
        ewk->wu.routine_no[0]++;
        set_char_move_init(&ewk->wu, 0, 13);
        ptr = effc8_data_tbl;

        if (oya_pl->wu.id) {
            ewk->wu.xyz[0].disp.pos += 61;
            ewk->wu.mvxy.a[0].sp = *ptr++;
            ewk->wu.mvxy.d[0].sp = *ptr++;
            ewk->wu.mvxy.a[1].sp = *ptr++;
            ewk->wu.mvxy.d[1].sp = *ptr++;
        } else {
            ewk->wu.xyz[0].disp.pos -= 61;
            ewk->wu.mvxy.a[0].sp = -*ptr;
            ptr++;
            ewk->wu.mvxy.d[0].sp = -*ptr;
            ptr++;
            ewk->wu.mvxy.a[1].sp = *ptr++;
            ewk->wu.mvxy.d[1].sp = *ptr++;
        }

        ewk->wu.xyz[1].disp.pos = 137;
        pl_eff_trans_entry(ewk);
        break;

    case 3:
        if (!EXE_flag && !Game_pause) {
            sub_000EF072(ewk);
            sub_000EF088(ewk);
            char_move(&ewk->wu);

            if (ewk->wu.cg_type) {
                ewk->wu.routine_no[0]++;
                ewk->wu.disp_flag = 0;
            }
        }

        pl_eff_trans_entry(ewk);
        break;

    case 4:
        ewk->wu.routine_no[0]++;
        break;

    case 5:
        sub_0004384A(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}

s32 effect_C8_init(PLW* wk) {
    WORK_Other* ewk;
    s16 ix;

    if ((ix = pull_effect_work(2)) == -1) {
        return -1;
    }

    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 128;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.my_family = 2;
    ewk->wu.rl_flag = wk->wu.rl_flag;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_priority = ewk->wu.position_z = 20;
    *ewk->wu.char_table = _etc_char_table;
    ewk->wu.my_col_code = wk->wu.my_col_code;
    ewk->my_master = (u32*)wk;
    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos = wk->wu.xyz[0].disp.pos;
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos = wk->wu.xyz[1].disp.pos;
    ewk->wu.xyz[0].disp.low = ewk->wu.xyz[1].disp.low = 0;
    ewk->wu.my_mts = 14;
    ewk->wu.my_trans_mode = get_my_trans_mode(ewk->wu.my_mts);
    return 0;
}
