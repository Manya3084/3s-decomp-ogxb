/* EFF21.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * effect_21_move 0x384ED size 0xB0.
 * effect_21_init 0x3859D size 0x156.
 * all_cgps_put_back is folded into 0x4384A.
 * Data: eff21_data_adrs is 0x32AC98, 1 pointers whose arrays were compared.
 * Data: eff21_num: not located in the XBE, PS2 initializer kept.
 * Data: eff21_sp_tbl is 0x24D668, 0x8 bytes compared.
 * Data: eff21_data_tbl_00 is 0x24D670, 0x36 bytes compared.
 * Globals: eff21_sp_tbl 0x24D668, eff21_data_adrs 0x32AC98, char_add 0x332CC8,
 * EXE_obroll 0x7A8111, Game_pause 0x7A89B0, bg_w 0x7BC520, EXE_flag 0xC7C834,
 * frw 0xC806A0.
 */

#include "structs.h"

#define EFFECT_MAX 128

void sub_0004384A(WORK* wk);
void set_char_move_init(WORK* wk, s16 koc, s16 index);
extern s16 EXE_flag;
extern u8 Game_pause;
extern s8 EXE_obroll;
void char_move(WORK* wk);
extern BG bg_w;
void disp_pos_trans_entry_rs(WORK_Other* ewk);
void disp_pos_trans_entry_s(WORK_Other* ewk);
void push_effect_work(WORK* wkhd);
s16 pull_effect_work(s16 index);
extern uintptr_t frw[EFFECT_MAX][448];
extern u32* char_add[];
void suzi_offset_set(WORK_Other* ewk);
s16 get_my_trans_mode(s16 curr);

const s16 eff21_num[1] = { 3 };

const s32 eff21_sp_tbl[1][2] = { { 0x2000, 0x2000 } };

const s16 eff21_data_tbl_00[27] = { 1,  2,  8492, 640, 0, 10, 17,   0,   0, 0,  2,  8492, 192, 0,
                                    10, 18, 0,    0,   1, 2,  8492, 736, 0, 10, 19, 0,    0 };

const s16* eff21_data_adrs[1] = { eff21_data_tbl_00 };

void effect_21_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        break;

    case 1:
        if (!EXE_flag && !Game_pause && !EXE_obroll) {
            char_move(&ewk->wu);
        }

        ewk->wu.xyz[0].disp.pos = ewk->wu.old_rno[0];
        ewk->wu.xyz[0].disp.low = 0;
        ewk->wu.xyz[0].cal -= (ewk->wu.mvxy.a[0].sp * bg_w.bg2_sp_x2);
        ewk->wu.xyz[1].disp.pos = ewk->wu.old_rno[2];
        ewk->wu.xyz[1].disp.low = 0;
        ewk->wu.xyz[1].cal += (ewk->wu.mvxy.a[1].sp * bg_w.bg2_sp_y);

        if (ewk->wu.old_rno[3]) {
            disp_pos_trans_entry_rs(ewk);
            break;
        }

        disp_pos_trans_entry_s(ewk);
        break;

    default:
        sub_0004384A(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}

s32 effect_21_init(s16 sync_index) {
    WORK_Other* ewk;
    s16 ix;
    s16 lp_cnt = eff21_num[sync_index];
    s16 i;
    const s16* data_ptr;

    if (lp_cnt == 0) {
        return 0;
    }

    data_ptr = eff21_data_adrs[sync_index];

    for (i = 0; i < lp_cnt; i++) {
        if ((ix = pull_effect_work(4)) == -1) {
            return -1;
        }

        ewk = (WORK_Other*)frw[ix];
        ewk->wu.be_flag = 1;
        ewk->wu.id = 21;
        ewk->wu.work_id = 16;
        ewk->wu.cgromtype = 1;
        ewk->wu.rl_flag = 0;
        ewk->wu.my_col_mode = 0x4200;
        ewk->wu.type = i;
        ewk->wu.old_rno[3] = *data_ptr++;
        ewk->wu.my_family = *data_ptr++;
        ewk->wu.my_col_code = *data_ptr++;
        ewk->wu.old_rno[0] = *data_ptr++;
        ewk->wu.old_rno[2] = *data_ptr++;
        ewk->wu.my_priority = ewk->wu.position_z = *data_ptr++;
        ewk->wu.char_index = *data_ptr++;
        ewk->wu.sync_suzi = *data_ptr++;
        ewk->wu.mvxy.a[0].sp = eff21_sp_tbl[*data_ptr][0];
        ewk->wu.mvxy.a[1].sp = eff21_sp_tbl[*data_ptr][1];
        *data_ptr++;
        ewk->wu.char_table[0] = char_add[bg_w.bg_index];
        ewk->wu.xyz[0].disp.pos = ewk->wu.old_rno[0];
        ewk->wu.xyz[1].disp.pos = ewk->wu.old_rno[2];
        suzi_offset_set(ewk);
        ewk->wu.my_mts = 7;
        ewk->wu.my_trans_mode = get_my_trans_mode(ewk->wu.my_mts);
    }

    return 0;
}
