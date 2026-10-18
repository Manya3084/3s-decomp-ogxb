/* EFFE4.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * effect_E4_move 0x49535 size 0x19C. Read against the x86: spmv_ng_flag &=
 * ~0x80 and &= ~0xF00 are merged into one and with 0xF07F, and spmv_ng_flag2
 * |= 0xD0000 is a byte or of 0xD at +0x392. The C is the PS2 C.
 * effect_E4_init 0x496D1 size 0x8A.
 * Globals: Mode_Type 0x7A825A, New_Challenger 0x7A86D6, Training 0x7C5900,
 * omop_vital_ix 0x7C5C70, omop_spmv_ng_table 0xC7D8D8, omop_spmv_ng_table2
 * 0xC7D9C8, vib_sel 0xC7D9D2, frw 0xC806A0.
 */

#include "structs.h"

#define EFFECT_MAX 128

extern u8 Mode_Type;
extern TrainingData Training[3];
extern s8 New_Challenger;
extern s8 vib_sel[2];
extern s16 omop_vital_ix[2];
void demo_set_sa_full(SA_WORK* sa);
void tr_spgauge_cont_init2(s8 pl);
void clear_super_arts_point(PLW* wk);
void tr_spgauge_cont_init(s8 pl);
extern u32 omop_spmv_ng_table[2];
extern u32 omop_spmv_ng_table2[2];
void push_effect_work(WORK* wkhd);
s16 pull_effect_work(s16 index);
extern uintptr_t frw[EFFECT_MAX][448];



void effect_E4_move(WORK_Other* ewk) {
    PLW* mwk = (PLW*)ewk->my_master;
    s16 num;

    switch (ewk->wu.routine_no[0]) {
    case 0:
        if (mwk->wu.E4_work_index != ewk->wu.myself || ewk->wu.dead_f != 0 || (Mode_Type != 3 && Mode_Type != 4)) {
            ewk->wu.routine_no[0] = 2;
            break;
        }

        if (mwk->init_E4_flag == 0) {
            break;
        }

        mwk->init_E4_flag = 0;

        if (Mode_Type != 4) {
            break;
        }

        if (Training->contents[1][1][3] == 0 || mwk->wu.id == New_Challenger) {
            vib_sel[mwk->wu.id] = 0;
        }

        omop_vital_ix[mwk->wu.id] = 1;
        mwk->spmv_ng_flag &= 0xFFFEFFFF;
        num = 0;

        if (New_Challenger == mwk->wu.id) {
            num = Training->contents[1][0][1];
        } else {
            num = Training->contents[1][0][3];
        }

        switch (num) {
        case 1:
            mwk->spmv_ng_flag2 &= 0xFFFBFFFF;
            mwk->spmv_ng_flag2 |= 0x90000;
            demo_set_sa_full(mwk->sa);
            tr_spgauge_cont_init2(mwk->wu.id);
            break;

        case 3:
            mwk->spmv_ng_flag2 &= 0xFFF7FFFF;
            mwk->spmv_ng_flag2 |= 0x50000;
            demo_set_sa_full(mwk->sa);
            tr_spgauge_cont_init2(mwk->wu.id);
            break;

        case 2:
            mwk->spmv_ng_flag2 &= 0xFFFEFFFF;
            mwk->spmv_ng_flag2 |= 0xC0000;
            clear_super_arts_point(mwk);
            tr_spgauge_cont_init(mwk->wu.id);
            break;

        case 0:
            mwk->spmv_ng_flag2 |= 0xD0000;
            clear_super_arts_point(mwk);
            tr_spgauge_cont_init(mwk->wu.id);
            break;
        }

        if (mwk->wu.id == New_Challenger || Training->contents[1][0][2] == 0) {
            mwk->spmv_ng_flag |= 0x80;
        } else {
            mwk->spmv_ng_flag &= ~0x80;
            mwk->spmv_ng_flag &= ~0xF00;
        }

        omop_spmv_ng_table[mwk->wu.id] = mwk->spmv_ng_flag;
        omop_spmv_ng_table2[mwk->wu.id] = mwk->spmv_ng_flag2;
        break;

    case 1:
    case 2:
    default:
        push_effect_work(&ewk->wu);
        break;
    }
}

s32 effect_E4_init(PLW* wk) {
    WORK_Other* ewk;
    s16 ix;

    if ((ix = pull_effect_work(3)) == -1) {
        return -1;
    }

    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 144;
    ewk->wu.work_id = 16;
    ewk->my_master = (u32*)wk;
    ewk->master_work_id = wk->wu.work_id;
    ewk->master_id = wk->wu.id;
    ewk->master_player = wk->player_number;
    ewk->master_ng_flag = wk->spmv_ng_flag;
    ewk->master_ng_flag2 = wk->spmv_ng_flag2;
    wk->init_E4_flag = 1;
    wk->wu.E4_work_index = ewk->wu.myself;
    return 0;
}
