/* CHARID.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * set_char_base_data 0x1D69B size 0x128. Read against the x86: 0x64 is
 * sizeof(CharInitData), the index multiplier. The C is the PS2 C.
 * copy_char_base_data 0x1D7C3 size 0x23. Read against the x86: two 0x64-byte
 * rep movsd copies from char_init_data_ex. char_init_data_ex is 0x240C90; its
 * initializer holds pointers, so its bytes were not compared. The C is the PS2
 * C.
 * Data: char_init_data 0xCBA020.
 * Data: parabora_own_table 0xCB9FC0.
 * Data: char_init_data2 is 0x240BD8, 0xB8 bytes compared.
 * Data: char_init_data_ex 0x240C90, not compared.
 * Globals: char_init_data2 0x240BD8, char_init_data_ex 0x240C90,
 * char_init_data 0xCBA020.
 */

#include "structs.h"

#define NULL 0

extern u32 _ef13_char_table[];
extern u32 _ef13_stepxy_table[];
extern u32 _ef13_movexy_table[];
extern u32 _ef13_hit_ix_table[];
extern u32 _ef13_body_box[];
extern u32 _ef13_hand_box[];
extern u32 _ef13_cat_box[];
extern u32 _ef13_cau_box[];
extern u32 _ef13_att_box[];
extern u32 _ef13_hos_box[];
extern u32 _ef13_catt_table[];
extern u32 _bonus_char_table[];

extern CharInitData char_init_data[23];

extern UNK_Data* parabora_own_table[20];

const CharInitData2 char_init_data2[23] = {
    { 0x0000, 0x0000, 0x0000, 0x0000 }, { 0x4200, 0x2000, 0x0026, 0x0002 }, { 0x4200, 0x2000, 0x0032, 0x0002 },
    { 0x4200, 0x2000, 0x0034, 0x0002 }, { 0x4200, 0x2000, 0x002a, 0x0002 }, { 0x4200, 0x2000, 0x0030, 0x0002 },
    { 0x4200, 0x2000, 0x0036, 0x0002 }, { 0x4200, 0x2000, 0x0038, 0x0002 }, { 0x4200, 0x2000, 0x0028, 0x0002 },
    { 0x4200, 0x2000, 0x002e, 0x0002 }, { 0x4200, 0x2000, 0x002c, 0x0002 }, { 0x4200, 0x2000, 0x001c, 0x0002 },
    { 0x4200, 0x2000, 0x0026, 0x0002 }, { 0x4200, 0x2000, 0x0030, 0x0002 }, { 0x4200, 0x2000, 0x0030, 0x0002 },
    { 0x4200, 0x2000, 0x0036, 0x0002 }, { 0x4200, 0x2000, 0x0030, 0x0002 }, { 0x4200, 0x2000, 0x001c, 0x0002 },
    { 0x4200, 0x2000, 0x0032, 0x0002 }, { 0x4200, 0x2000, 0x0032, 0x0002 }, { 0x4200, 0x2000, 0x0036, 0x0002 },
    { 0x4200, 0x2000, 0x0038, 0x0002 }, { 0x4200, 0x2000, 0x0028, 0x0002 }
};

const CharInitData char_init_data_ex[2] = { { _ef13_char_table,
                                              NULL,
                                              NULL,
                                              NULL,
                                              NULL,
                                              NULL,
                                              NULL,
                                              NULL,
                                              NULL,
                                              NULL,
                                              (s16*)_ef13_stepxy_table,
                                              (s16*)_ef13_movexy_table,
                                              NULL,
                                              NULL,
                                              NULL,
                                              NULL,
                                              (UNK_0*)_ef13_hit_ix_table,
                                              (UNK_1*)_ef13_body_box,
                                              (UNK_2*)_ef13_hand_box,
                                              (UNK_3*)_ef13_cat_box,
                                              (UNK_4*)_ef13_cau_box,
                                              (UNK_5*)_ef13_att_box,
                                              (UNK_6*)_ef13_hos_box,
                                              (UNK_7*)_ef13_catt_table,
                                              NULL },
                                            { (u32*)_bonus_char_table,
                                              NULL,
                                              NULL,
                                              NULL,
                                              NULL,
                                              NULL,
                                              NULL,
                                              NULL,
                                              NULL,
                                              NULL,
                                              (s16*)_ef13_stepxy_table,
                                              (s16*)_ef13_movexy_table,
                                              NULL,
                                              NULL,
                                              NULL,
                                              NULL,
                                              (UNK_0*)_ef13_hit_ix_table,
                                              (UNK_1*)_ef13_body_box,
                                              (UNK_2*)_ef13_hand_box,
                                              (UNK_3*)_ef13_cat_box,
                                              (UNK_4*)_ef13_cau_box,
                                              (UNK_5*)_ef13_att_box,
                                              (UNK_6*)_ef13_hos_box,
                                              (UNK_7*)_ef13_catt_table,
                                              NULL } };

void set_char_base_data(WORK* wk) {
    CharInitData* cdat = &char_init_data[wk->charset_id];
    const CharInitData2* cdat2 = &char_init_data2[wk->charset_id];

    wk->char_table[0] = cdat->nmca;
    wk->char_table[1] = cdat->dmca;
    wk->char_table[6] = cdat->btca;
    wk->char_table[2] = cdat->caca;
    wk->char_table[3] = cdat->cuca;
    wk->char_table[4] = cdat->atca;
    wk->char_table[5] = cdat->saca;
    wk->char_table[7] = cdat->exca;
    wk->char_table[8] = cdat->cbca;
    wk->char_table[9] = cdat->yuca;
    wk->step_xy_table = cdat->stxy;
    wk->move_xy_table = cdat->mvxy;
    wk->se_random_table = cdat->sernd;
    wk->overlap_char_tbl = cdat->ovct;
    wk->olc_ix_table = cdat->ovix;
    wk->rival_catch_tbl = cdat->rict;
    wk->hit_ix_table = cdat->hiit;
    wk->body_adrs = cdat->boda;
    wk->hand_adrs = cdat->hana;
    wk->catch_adrs = cdat->cata;
    wk->caught_adrs = cdat->caua;
    wk->attack_adrs = cdat->atta;
    wk->hosei_adrs = cdat->hosa;
    wk->att_ix_table = cdat->atit;
    wk->my_col_mode = cdat2->my_cm;
    wk->my_col_code = cdat2->my_cc;
    wk->my_priority = cdat2->my_pr;
    wk->my_family = cdat2->my_fm;
    wk->position_z = wk->my_priority;
}

void copy_char_base_data() {
    char_init_data[11] = char_init_data_ex[0];
    char_init_data[17] = char_init_data_ex[1];
}
