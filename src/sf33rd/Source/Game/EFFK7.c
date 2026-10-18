/* EFFK7.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * K7_mt0_rebirth_check 0x509A4 size 0x36.
 * K7_muriyari_metamor_rebirth 0x509DA size 0x53.
 * effect_K7_init 0x50A2D size 0x73. Read against the x86: 0x2000 and 0x2010
 * are the two my_col_code values, stored through a pointer to +0x23E. The C is
 * the PS2 C.
 * K7_move_type_0 0x50AA0 size 0x1B0. Read against the x86: 0xFF is the compare
 * on the as byte at +0xA, and 0x270 is &wk->cg_ja for a struct copy. The C is
 * the PS2 C.
 * effect_K7_move 0x50C50 size 0xF4.
 * metamor_color_trans stays sub_000D00A8, the one unnamed call left in its
 * caller.
 * Globals: plid_data 0x261928, My_char 0x7A8114, test_flag 0x7A8902,
 * Game_pause 0x7A89B0, EXE_flag 0xC7C834, pcon_dp_flag 0xC7D8D0, pcon_rno
 * 0xC7E020, frw 0xC806A0.
 */

#include "structs.h"

#define EFFECT_MAX 128

void sub_000D00A8(s16 wkid);
void metamor_color_restore(s16 wkid);
extern s16 EXE_flag;
extern u8 Game_pause;
void K7_move_type_0(WORK_Other* ewk, PLW* mwk);
void push_effect_work(WORK* wkhd);
void set_base_data_metamorphose(PLW* wk, s16 dmid);
void Next_Be_Free(PLW* wk);
void metamor_color_copy(s16 wkid);
s16 K7_mt0_rebirth_check(PLW* mwk);
extern s16 pcon_rno[4];
void set_jugde_area(WORK* wk);
extern u8 pcon_dp_flag;
extern u8 My_char[2];
extern const s8 plid_data[20];
extern u8 test_flag;
s16 pull_effect_work(s16 index);
extern uintptr_t frw[EFFECT_MAX][448];



void effect_K7_move(WORK_Other* ewk) {
    PLW* mwk = (PLW*)ewk->my_master;

    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0] = 1;
        break;

    case 1:
        if (ewk->wu.dead_f != 0 || mwk->metamor_index != ewk->wu.myself) {
            ewk->wu.routine_no[0] = 3;
            metamor_color_restore(mwk->wu.id);
            mwk->metamorphose = 0;
            mwk->metamor_over = 0;
            mwk->att_plus = 8;
            mwk->def_plus = 8;
            mwk->wu.my_col_mode = ewk->wu.my_col_mode;
            mwk->wu.my_col_code = ewk->wu.my_col_code;
            mwk->wu.disp_flag = 1;
        } else if (EXE_flag == 0 && Game_pause == 0) {
            K7_move_type_0(ewk, mwk);
        }

        break;

    case 2:
        mwk->metamorphose = 0;
        mwk->metamor_over = 0;
        mwk->att_plus = 8;
        mwk->def_plus = 8;
        mwk->wu.my_col_mode = ewk->wu.my_col_mode;
        mwk->wu.my_col_code = ewk->wu.my_col_code;
        mwk->wu.disp_flag = 1;
        /* fallthrough */

    default:
        push_effect_work(&ewk->wu);
        break;
    }
}

void K7_move_type_0(WORK_Other* ewk, PLW* mwk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (mwk->wu.cg_type != 20) {
            break;
        }

        ewk->wu.routine_no[1] = 1;
        ewk->wu.direction = mwk->player_number;
        ewk->wu.charset_id = mwk->wu.charset_id;
        mwk->player_number = ((PLW*)mwk->wu.target_adrs)->player_number;
        mwk->wu.charset_id = ((PLW*)mwk->wu.target_adrs)->wu.charset_id;
        set_base_data_metamorphose(mwk, mwk->wu.id + 1 & 1);
        mwk->att_plus = 10;
        mwk->def_plus = 6;

        if (mwk->wu.operator == 0) {
            Next_Be_Free(mwk);
        }

        break;

    case 1:
        if (mwk->wu.cg_type != 30) {
            break;
        }

        ewk->wu.routine_no[1] = 2;
        sub_000D00A8(mwk->wu.id);
        metamor_color_copy(mwk->wu.id);
        mwk->metamorphose = 1;
        /* fallthrough */

    case 2:
        if (mwk->dead_flag != 0) {
            ewk->wu.routine_no[1] = 9;
            break;
        }

        if (mwk->sa->ok == -1) {
            break;
        }

        ewk->wu.routine_no[1] = 3;
        mwk->metamor_over = 1;
        /* fallthrough */

    case 3:
        if (K7_mt0_rebirth_check(mwk) == 0) {
            break;
        }

        if (pcon_rno[0] != 1) {
            ewk->wu.routine_no[1] = 9;
            break;
        }

        ewk->wu.routine_no[1] = 4;
        mwk->wu.routine_no[1] = 4;
        mwk->wu.routine_no[2] = 33;
        mwk->wu.routine_no[3] = 0;
        mwk->wu.cg_type = 0;
        mwk->wu.cg_hit_ix = 0;
        mwk->wu.cg_ja = mwk->wu.hit_ix_table[mwk->wu.cg_hit_ix];
        set_jugde_area(&mwk->wu);
        break;

    case 4:
        if (mwk->wu.cg_type != 30) {
            break;
        }

        ewk->wu.routine_no[1] = 5;
        mwk->player_number = ewk->wu.direction;
        mwk->wu.charset_id = ewk->wu.charset_id;
        set_base_data_metamorphose(mwk, mwk->wu.id);
        metamor_color_restore(mwk->wu.id);

        if (mwk->wu.operator == 0) {
            Next_Be_Free(mwk);
        }

        break;

    case 5:
        ewk->wu.routine_no[0] = 2;
        break;
    }
}

s16 K7_mt0_rebirth_check(PLW* mwk) {
    s16 num = 0;

    switch (mwk->wu.routine_no[1]) {
    case 0:
        if (pcon_dp_flag) {
            if (mwk->wu.routine_no[2] == 1 && mwk->wu.routine_no[3] != 0) {
                num = 1;
            }
        } else if (mwk->guard_flag != 3 && !mwk->wu.hit_stop) {
            num = 1;
        }

        break;
    }

    return num;
}

void K7_muriyari_metamor_rebirth(PLW* wk) {
    if (wk->metamorphose == 0) {
        return;
    }

    wk->player_number = My_char[wk->wu.id];
    wk->wu.charset_id = plid_data[My_char[wk->wu.id]];
    set_base_data_metamorphose(wk, wk->wu.id);
    metamor_color_restore(wk->wu.id);
    wk->metamor_over = 0;
    wk->metamorphose = 0;
}

s32 effect_K7_init(PLW* wk) {
    WORK_Other* ewk;
    s16 ix;

    if (test_flag) {
        return -1;
    }

    if ((ix = pull_effect_work(6)) == -1) {
        return -1;
    }

    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 207;
    ewk->wu.work_id = 16;
    ewk->wu.type = 0;
    ewk->my_master = (u32*)wk;
    wk->metamor_index = ewk->wu.myself;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_col_code = 0x2000;

    if (wk->wu.id) {
        ewk->wu.my_col_code += 16;
    }

    return 0;
}
