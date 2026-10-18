/* PLS03.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * hissatsu_setup_union 0x940E9 size 0x3F.
 * cmdixconv 0x94128 size 0xE.
 * execute_super_arts 0x94136 size 0x170. Read against the x86: 0x38F is a PLW
 * flag byte tested with 0x80 and 0x40, and 0xFF the store of -1 to an sa byte.
 * The C is the PS2 C.
 * chainex_spat_cancel_kidou 0x942A6 size 0x64. FLAG: x86-only globals
 * __security_cookie.
 * check_leap_attack 0x9430A size 0x9A. Read against the x86: 0x441 is a PLW
 * flag byte (|= 2). The C is the PS2 C.
 * hikusugi_check 0x943A4 size 0x18.
 * check_nagenuke_cmd 0x943BC size 0x48.
 * set_attack_routine_number 0x94404 size 0x24.
 * get_em_body_range 0x94428 size 0x81.
 * cmd_ex_check 0x944A9 size 0x25.
 * shot_data_convert 0x944CE size 0x26. Read against the x86: -2 is a lea step.
 * The C is the PS2 C.
 * shot_data_refresh 0x944F4 size 0xE.
 * renbanshot_conpaneshot 0x94502 size 0x19.
 * datacmd_conpanecmd 0x9451B size 0x13. Read against the x86: -0xFC80 is the
 * mask 0xFFFF0380 after the
 * check_renda_cancel 0x9452E size 0xAB.
 * get_meoshi_lever 0x945D9 size 0x10.
 * get_meoshi_shot 0x945E9 size 0x14. Read against the x86: (data >> 1) &
 * 0xFFFF0380 is the C's (data & 0x700) >> 1 in the low 16 bits.
 * check_full_gauge_attack 0x945FD size 0x373. Read against the x86: 0x392 &
 * 0x80 is spmv_ng_flag2 & 0x800000, and the array tested and set is
 * chainex_check, indexed [id][exsa_g_ix - 20] with the -20 folded into the
 * base, which then falls on omop_cockpit just before it. chainex_check is
 * 0x7C5C80. 0x1D7, -0x98, and -0x50 are cp table and _assadr_lv_9900 index
 * terms. The C is the PS2 C.
 * check_full_gauge_attack2 0x94970 size 0x373. Read against the x86: the same
 * chainex_check test and index terms as check_full_gauge_attack. The C is the
 * PS2 C.
 * check_super_arts_attack_dc 0x94CE3 size 0x367. Read against the x86: the
 * same chainex_check test and _assadr_lv_9900 index terms; 0x40 and 0xFF are
 * the flag test and the -1 store. The C is the PS2 C.
 * check_special_attack 0x9504A size 0x502. Read against the x86: the same
 * chainex_check test and index terms; 0x391 and 1 are further PLW flag bytes.
 * The C is the PS2 C.
 * check_chouhatsu 0x9554C size 0x95.
 * check_catch_attack 0x955E1 size 0xD6.
 * get_nearing_range 0x956B7 size 0x53.
 * decode_wst_data 0x9570A size 0x1BC.
 * check_super_arts_attack 0x958C6 size 0x64. Read against the x86: 0xFF is the
 * store of -1 to an sa byte. The C is the PS2 C.
 * waza_select 0x9592A size 0x1D2.
 * check_nm_attack 0x95AFC size 0x3A4.
 * check_meoshi_cancel 0x95EA0 size 0x1C0. Read against the x86: 0x231 is a
 * WORK flag byte. The C is the PS2 C.
 * pp_pulpara_remake_at_init2 is folded into 0x4384A.
 * Data: cmdixconv_table is 0x264780, 0x48 bytes compared.
 * Data: nml_catch_h2_ok is 0x2647C8, 0x28 bytes compared.
 * Data: shot_prio is 0x2647F0, 0x18 bytes compared.
 * Data: shot_refresh is 0x264808, 0xC bytes compared.
 * Data: rc_shot_conv is 0x264814, 0x20 bytes compared.
 * Data: renda_status_table is 0x264834, 0x4 bytes compared.
 * Data: cnmc_conv_data is 0x264838, 0x20 bytes compared.
 * Data: cnmc_Z_lever_data is 0x264858, 0xC0 bytes compared.
 * Data: _cnmc_z_lever_data is 0x264918, 0x100 bytes compared.
 * Data: gml_real_lever_data is 0x264A18, 0x20 bytes compared.
 * Data: cmdshot_conv_tbl is 0x264A38, 0x40 bytes compared.
 * Unnamed data used (not checked): check_special_attack: 0x400000;
 * get_nearing_range: 0x2eeb84; waza_select:
 * 0x2eeb84,0x2ef5d4,0x2f0024,0x2f0a74,0x2f14c4; check_nm_attack:
 * 0x2eed64,0x2ef7b4,0x2f0204,0x2f0c54,0x2f16a4.
 * Globals: cmdixconv_table 0x264780, nml_catch_h2_ok 0x2647C8, shot_prio
 * 0x2647F0, shot_refresh 0x264808, rc_shot_conv 0x264814, renda_status_table
 * 0x264834, cnmc_conv_data 0x264838, cnmc_Z_lever_data 0x264858,
 * _cnmc_z_lever_data 0x264918, gml_real_lever_data 0x264A18, cmdshot_conv_tbl
 * 0x264A38, _asstbl_lv_E010 0x2ED850, _asstbl_lv_B010 0x2ED8C8,
 * _asstbl_lv_A010 0x2ED8DA, _asstbl_lv_D010 0x2ED8EC, _assadr_lv_9900
 * 0x2EEA44, __security_cookie 0x43CF74, Bonus_Game_Flag 0x7A8272, Super_Arts
 * 0x7A89FE, chainex_check 0x7C5C80, pcon_dp_flag 0xC7D8D0, cmd_sel 0xC7D9D0.
 */

#include "structs.h"

void sub_0004384A();
extern u8 pcon_dp_flag;
extern s16 Bonus_Game_Flag;
extern u8 chainex_check[2][36];
void setup_comm_back(WORK* wk);
extern const AS* _assadr_lv_9900[20][4];
void waza_compel_all_init2(PLW* pl);
void chainex_spat_cancel_kidou(WORK* wk);
extern char cmd_sel[2];
extern s8 Super_Arts[2];
void set_super_arts_status_dc(s16 ix);
s32 check_super_arts_attack_dc(PLW* wk);
s32 shell_live_check(PLW* wk, s16 wix);
void waza_flag_clear_only_1(s16 pl_id, s16 wznum);
void grade_add_command_waza(s16 ix);
void setup_mvxy_data(WORK* wk, u16 ix);
extern const AS _asstbl_lv_D010[20];
s16 shot_data_convert(u16 sw);
s16 hikusugi_check(WORK* wk);
s32 waza_select(PLW* wk, s16 kos, s16 sf);
extern const AS _asstbl_lv_3010[20][6][3];
extern const AS _asstbl_lv_2010[20][6][3];
extern const AS _asstbl_lv_4010[20][6][3];
extern const AS _asstbl_lv_1010[20][6][3];
extern const AS _asstbl_lv_0010[20][6][3];
s16 shot_data_refresh(s16 sw);
void set_attack_routine_number(PLW* wk);
extern const AS _asstbl_lv_E010[20];
extern const AS _asstbl_lv_A010[3];
extern const AS _asstbl_lv_B010[3];
extern const u16 _asstbl_lv_0000[20][6][2];
extern const u16 _asstbl_lv_1000[20][6][2];
extern const u16 _asstbl_lv_2000[20][6][2];
extern const u16 _asstbl_lv_3000[20][6][2];
extern const u16 _asstbl_lv_4000[20][6][2];
u16 decode_wst_data(PLW* wk, u16 cmd, s16 cmd_ex);
s32 cmd_ex_check(s16 px, s16 cx);
s16 get_em_body_range(WORK* wk);
s16 get_sel_hosei_tbl_ix(s16 plnum);
s32 char_move_cmms3(PLW* wk);
void char_move_cmms2(WORK* wk);
void grade_add_target_combo(s16 ix);

const s16 cmdixconv_table[36] = { 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                  2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3 };

const u8 nml_catch_h2_ok[2][20] = { { 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16 },
                                    { 0, 0, 0, 0, 0, 0, 0, 17, 0, 17, 0, 0, 0, 0, 0, 17, 0, 0, 0, 0 } };

const s16 shot_prio[6][2] = { { 256, 3 }, { 16, 0 }, { 512, 4 }, { 32, 1 }, { 1024, 5 }, { 64, 2 } };

const s16 shot_refresh[6] = { 16, 32, 64, 256, 512, 1024 };

const s16 rc_shot_conv[16] = { 16, 32, 64, 112, 256, 512, 1024, 1792, 272, 544, 1088, 1904, 0, 0, 0, 0 };

const u8 renda_status_table[4] = { 0, 20, 32, 0 };

const s16 cnmc_conv_data[16] = { 5, 8, 2, 0, 4, 7, 1, 0, 6, 9, 3, 0, 0, 0, 0, 0 };

const s16 cnmc_Z_lever_data[16][6] = { { 0, -1, -1, -1, -1, -1 }, { 1, -1, -1, -1, -1, -1 }, { 2, -1, -1, -1, -1, -1 },
                                       { 3, -1, -1, -1, -1, -1 }, { 4, -1, -1, -1, -1, -1 }, { 5, -1, -1, -1, -1, -1 },
                                       { 6, -1, -1, -1, -1, -1 }, { 7, -1, -1, -1, -1, -1 }, { 8, -1, -1, -1, -1, -1 },
                                       { 9, -1, -1, -1, -1, -1 }, { 4, 5, 6, 7, 8, 9 },      { 1, 2, 3, 4, 5, 6 },
                                       { 4, 5, -1, -1, -1, -1 },  { 5, 6, -1, -1, -1, -1 },  { 4, 6, -1, -1, -1, -1 },
                                       { 4, 5, 6, -1, -1, -1 } };

const s16 _cnmc_z_lever_data[16][8] = { { -1, -1, -1, -1, -1, -1, -1, -1 }, { 4, 1, 2, -1, -1, -1, -1, -1 },
                                        { 1, 2, 3, -1, -1, -1, -1, -1 },    { 2, 3, 6, -1, -1, -1, -1, -1 },
                                        { 1, 4, 7, -1, -1, -1, -1, -1 },    { 1, 2, 3, 4, 6, 7, 8, 9 },
                                        { 3, 6, 9, -1, -1, -1, -1, -1 },    { 4, 7, 8, -1, -1, -1, -1, -1 },
                                        { 7, 8, 9, -1, -1, -1, -1, -1 },    { 8, 9, 6, -1, -1, -1, -1, -1 },
                                        { 1, 3, 4, 5, 6, 7, 8, 9 },         { 1, 2, 3, 4, 5, 6, 7, 9 },
                                        { 1, 4, 5, 7, -1, -1, -1, -1 },     { 3, 5, 6, 9, -1, -1, -1, -1 },
                                        { 1, 4, 7, 3, 6, 9, -1, -1 },       { 1, 4, 7, 5, 3, 6, 9, -1 } };

const s16 gml_real_lever_data[16] = { 0, 6, 2, 10, 4, 0, 8, 5, 1, 9, 0, 0, 4, 8, 4, 8 };

const s16 cmdshot_conv_tbl[32] = { 16,   32,   64,   128,  256,  512,  1024, 2048, 272,  544,  1088, 2176, 0, 0, 0, 0,
                                   1904, 1904, 1904, 1920, 1904, 1904, 1904, 2160, 1904, 1904, 1904, 2176, 0, 0, 0, 0 };

void hissatsu_setup_union(PLW* wk, s16 rno) {
    wk->wu.routine_no[1] = 4;
    wk->wu.routine_no[2] = rno;
    wk->wu.routine_no[3] = 0;
    wk->cancel_timer = 0;
    wk->wu.cg_type = 0;
    wk->wu.att_hit_ok = 0;
    wk->wu.hf.hit_flag = 0;
    wk->wu.meoshi_hit_flag = 0;
    wk->wu.paring_attack_flag = 0;
}

s16 cmdixconv(s16 ix) {
    return cmdixconv_table[ix - 20];
}

s32 check_full_gauge_attack(PLW* wk, s8 always) {
    u16* conpane;
    s16 j;
    u16 cusw;
    u16 exsw;

    if (wk->sa->mp != 1) {
        return 0;
    }

    if (pcon_dp_flag) {
        return 0;
    }

    if (((Bonus_Game_Flag == 0x14) && (wk->bs2_on_car)) || (wk->wu.xyz[1].disp.pos <= 0)) {
        if (wk->spmv_ng_flag & 0x40000000) {
            return 0;
        }

        if (wk->sa->exsa_g_ix == 0) {
            return 0;
        }

        if (wk->sa->exsa_g_ix > 0x1C) {
            return 0;
        }

        if (always && !(wk->cp->btix[wk->sa->exsa_g_ix] & 0x100)) {
            return 0;
        }

        if ((wk->spmv_ng_flag2 & 0x800000) && (chainex_check[wk->wu.id][wk->sa->exsa_g_ix - 20])) {
            return 0;
        }

        if (wk->cancel_timer == 0) {
            wk->permited_koa |= 0x40;
        }

        conpane = &wk->cp->sw_lvbt;

        if (wk->cp->waza_flag[wk->sa->exsa_g_ix] == -1) {
            return 0;
        }

        if (((wk->cp->btix[wk->sa->exsa_g_ix] & 0xFF) != 0x80) && (wk->cp->waza_flag[wk->sa->exsa_g_ix])) {
            cusw = conpane[wk->cp->btix[wk->sa->exsa_g_ix] & 0xFF];

            for (j = 3; j >= 0; j--) {
                if ((j == 3) && !(wk->cp->btix[wk->sa->exsa_g_ix] & 0x600)) {
                    continue;
                }

                exsw = cusw & cmdshot_conv_tbl[wk->cp->exdt[wk->sa->exsa_g_ix][j]];

                if (exsw == cmdshot_conv_tbl[wk->cp->exdt[wk->sa->exsa_g_ix][j] & 0xF]) {
                    setup_comm_back(&wk->wu);
                    wk->as = &_assadr_lv_9900[wk->player_number][cmdixconv(wk->sa->exsa_g_ix)]
                                             [j + ((wk->sa->exsa_g_ix - 20) * 4)];
                    wk->wu.cg_cancel = 0;
                    wk->sa->mp = -1;
                    hissatsu_setup_union(wk, wk->cp->waza_r[wk->sa->exsa_g_ix][j]);
                    waza_compel_all_init2(wk);
                    chainex_check[wk->wu.id][wk->sa->exsa_g_ix - 20] = 1;
                    chainex_spat_cancel_kidou(&wk->wu);
                    return 1;
                }
            }
        }

        return 0;
    }

    if (wk->spmv_ng_flag & 0x80000000) {
        return 0;
    }

    if (wk->sa->exsa_a_ix == 0) {
        return 0;
    }

    if ((wk->sa->exsa_a_ix) < 0x1C) {
        return 0;
    }

    if (always && !(wk->cp->btix[wk->sa->exsa_a_ix] & 0x100)) {
        return 0;
    }

    if ((wk->spmv_ng_flag2 & 0x800000) && chainex_check[wk->wu.id][wk->sa->exsa_a_ix - 20]) {
        return 0;
    }

    if (wk->cancel_timer == 0) {
        wk->permited_koa |= 0x40;
    }

    conpane = &wk->cp->sw_lvbt;

    if (wk->cp->waza_flag[wk->sa->exsa_a_ix] == -1) {
        return 0;
    }

    if (((wk->cp->btix[wk->sa->exsa_a_ix] & 0xFF) != 0x80) && (wk->cp->waza_flag[wk->sa->exsa_a_ix])) {
        cusw = conpane[wk->cp->btix[wk->sa->exsa_a_ix] & 0xFF];

        for (j = 3; j >= 0; j--) {
            if ((j == 3) && !(wk->cp->btix[wk->sa->exsa_a_ix] & 0x600)) {
                continue;
            }

            exsw = cusw & cmdshot_conv_tbl[wk->cp->exdt[wk->sa->exsa_a_ix][j]];

            if (exsw == cmdshot_conv_tbl[wk->cp->exdt[wk->sa->exsa_a_ix][j] & 0xF]) {
                setup_comm_back(&wk->wu);
                wk->as = &_assadr_lv_9900[wk->player_number][cmdixconv(wk->sa->exsa_a_ix)]
                                         [j + ((wk->sa->exsa_a_ix - 38) * 4)];
                wk->wu.cg_cancel = 0;
                wk->sa->mp = -1;
                hissatsu_setup_union(wk, wk->cp->waza_r[wk->sa->exsa_a_ix][j]);
                waza_compel_all_init2(wk);
                chainex_check[wk->wu.id][wk->sa->exsa_a_ix - 20] = 1;
                chainex_spat_cancel_kidou(&wk->wu);
                return 1;
            }
        }
    }

    return 0;
}

s32 check_full_gauge_attack2(PLW* wk, s8 always) {
    u16* conpane;
    s16 j;
    u16 cusw;
    u16 exsw;

    if (wk->sa->mp != 1) {
        return 0;
    }

    if (pcon_dp_flag) {
        return 0;
    }

    if (((Bonus_Game_Flag == 0x14) && (wk->bs2_on_car)) || (wk->wu.xyz[1].disp.pos <= 0)) {
        if (wk->spmv_ng_flag & 0x40000000) {
            return 0;
        }

        if (wk->sa->exs2_g_ix == 0) {
            return 0;
        }

        if (wk->sa->exs2_g_ix > 0x1C) {
            return 0;
        }

        if (always && !(wk->cp->btix[wk->sa->exs2_g_ix] & 0x100)) {
            return 0;
        }

        if ((wk->spmv_ng_flag2 & 0x800000) && (chainex_check[wk->wu.id][wk->sa->exs2_g_ix - 20])) {
            return 0;
        }

        if (wk->cancel_timer == 0) {
            wk->permited_koa |= 0x40;
        }

        conpane = &wk->cp->sw_lvbt;

        if (wk->cp->waza_flag[wk->sa->exs2_g_ix] == -1) {
            return 0;
        }

        if (((wk->cp->btix[wk->sa->exs2_g_ix] & 0xFF) != 0x80) && (wk->cp->waza_flag[wk->sa->exs2_g_ix])) {
            cusw = conpane[wk->cp->btix[wk->sa->exs2_g_ix] & 0xFF];

            for (j = 3; j >= 0; j--) {
                if ((j == 3) && !(wk->cp->btix[wk->sa->exs2_g_ix] & 0x600)) {
                    continue;
                }

                exsw = cusw & cmdshot_conv_tbl[wk->cp->exdt[wk->sa->exs2_g_ix][j]];

                if (exsw == cmdshot_conv_tbl[wk->cp->exdt[wk->sa->exs2_g_ix][j] & 0xF]) {
                    setup_comm_back(&wk->wu);
                    wk->as = &_assadr_lv_9900[wk->player_number][cmdixconv(wk->sa->exs2_g_ix)]
                                             [j + ((wk->sa->exs2_g_ix - 20) * 4)];
                    wk->wu.cg_cancel = 0;
                    wk->sa->mp = -1;
                    hissatsu_setup_union(wk, wk->cp->waza_r[wk->sa->exs2_g_ix][j]);
                    waza_compel_all_init2(wk);
                    chainex_check[wk->wu.id][wk->sa->exs2_g_ix - 20] = 1;
                    chainex_spat_cancel_kidou(&wk->wu);
                    return 1;
                }
            }
        }

        return 0;
    }

    if (wk->spmv_ng_flag & 0x80000000) {
        return 0;
    }

    if (wk->sa->exs2_a_ix == 0) {
        return 0;
    }

    if ((wk->sa->exs2_a_ix) < 0x1C) {
        return 0;
    }

    if (always && !(wk->cp->btix[wk->sa->exs2_a_ix] & 0x100)) {
        return 0;
    }

    if ((wk->spmv_ng_flag2 & 0x800000) && (chainex_check[wk->wu.id][wk->sa->exs2_a_ix - 20])) {
        return 0;
    }

    if (wk->cancel_timer == 0) {
        wk->permited_koa |= 0x40;
    }

    conpane = &wk->cp->sw_lvbt;

    if (wk->cp->waza_flag[wk->sa->exs2_a_ix] == -1) {
        return 0;
    }

    if (((wk->cp->btix[wk->sa->exs2_a_ix] & 0xFF) != 0x80) && (wk->cp->waza_flag[wk->sa->exs2_a_ix])) {
        cusw = conpane[wk->cp->btix[wk->sa->exs2_a_ix] & 0xFF];

        for (j = 3; j >= 0; j--) {
            if ((j == 3) && !(wk->cp->btix[wk->sa->exs2_a_ix] & 0x600)) {
                continue;
            }

            exsw = cusw & cmdshot_conv_tbl[wk->cp->exdt[wk->sa->exs2_a_ix][j]];

            if (exsw == cmdshot_conv_tbl[wk->cp->exdt[wk->sa->exs2_a_ix][j] & 0xF]) {
                setup_comm_back(&wk->wu);
                wk->as = &_assadr_lv_9900[wk->player_number][cmdixconv(wk->sa->exs2_a_ix)]
                                         [j + (((wk->sa->exs2_a_ix) - 38) * 4)];
                wk->wu.cg_cancel = 0;
                wk->sa->mp = -1;
                hissatsu_setup_union(wk, wk->cp->waza_r[wk->sa->exs2_a_ix][j]);
                waza_compel_all_init2(wk);
                chainex_check[wk->wu.id][wk->sa->exs2_a_ix - 20] = 1;
                chainex_spat_cancel_kidou(&wk->wu);
                return 1;
            }
        }
    }

    return 0;
}

s16 check_super_arts_attack(PLW* wk) {
    s16 rnum = 0;
    s16 i;

    if (cmd_sel[wk->wu.id]) {
        if (wk->sa->ok != -1) {
            for (i = 0; i < 3; i++) {
                Super_Arts[wk->wu.id] = i;
                set_super_arts_status_dc(wk->wu.id);
                rnum = check_super_arts_attack_dc(wk);

                if (rnum) {
                    wk->sa->gt2 = wk->sa->gauge_type;
                    break;
                }
            }
        }
    } else {
        rnum = check_super_arts_attack_dc(wk);
    }

    return rnum;
}

s32 check_super_arts_attack_dc(PLW* wk) {
    s16 j;
    u16 cusw;
    u16 exsw;
    u16* conpane;

    if (wk->sa->ok != 1) {
        return 0;
    }

    if (pcon_dp_flag) {
        return 0;
    }

    if (wk->cancel_timer == 0) {
        wk->permited_koa |= 1;
    }

    if (((Bonus_Game_Flag == 0x14) && wk->bs2_on_car) || (wk->wu.xyz[1].disp.pos <= 0)) {
        if (wk->spmv_ng_flag & 0x40000000) {
            return 0;
        }

        if (wk->sa->nmsa_g_ix == 0) {
            return 0;
        }

        if ((wk->sa->nmsa_g_ix) > 0x1C) {
            return 0;
        }

        if ((wk->spmv_ng_flag2 & 0x800000) && (chainex_check[wk->wu.id][wk->sa->nmsa_g_ix - 20])) {
            return 0;
        }

        conpane = &wk->cp->sw_lvbt;

        if (wk->cp->waza_flag[wk->sa->nmsa_g_ix] == -1) {
            return 0;
        }

        if (((wk->cp->btix[wk->sa->nmsa_g_ix] & 0xFF) != 0x80) && (wk->cp->waza_flag[wk->sa->nmsa_g_ix])) {
            cusw = conpane[wk->cp->btix[wk->sa->nmsa_g_ix] & 0xFF];

            for (j = 3; j >= 0; j--) {
                if (j == 3) {
                    if (!(wk->cp->btix[wk->sa->nmsa_g_ix] & 0x600) || ((wk->sa->ex4th_full) && (wk->sa->mp != 1))) {
                        continue;
                    }
                }

                exsw = cusw & cmdshot_conv_tbl[wk->cp->exdt[wk->sa->nmsa_g_ix][j]];

                if (exsw == cmdshot_conv_tbl[wk->cp->exdt[wk->sa->nmsa_g_ix][j] & 0xF]) {
                    setup_comm_back(&wk->wu);
                    wk->as = &_assadr_lv_9900[wk->player_number][cmdixconv(wk->sa->nmsa_g_ix)]
                                             [j + ((wk->sa->nmsa_g_ix - 20) * 4)];
                    wk->sa->ex4th_exec = (j == 3) * wk->sa->ex4th_full;
                    wk->wu.cg_cancel = 0;
                    wk->sa->ok = -1;
                    hissatsu_setup_union(wk, wk->cp->waza_r[wk->sa->nmsa_g_ix][j]);
                    waza_compel_all_init2(wk);
                    chainex_check[wk->wu.id][wk->sa->nmsa_g_ix - 20] = 1;
                    chainex_spat_cancel_kidou(&wk->wu);
                    return 1;
                }
            }
        }

        return 0;
    }

    if (wk->spmv_ng_flag & 0x80000000) {
        return 0;
    }

    if (wk->sa->nmsa_a_ix == 0) {
        return 0;
    }

    if ((wk->sa->nmsa_a_ix) < 0x1C) {
        return 0;
    }

    if ((wk->spmv_ng_flag2 & 0x800000) && (chainex_check[wk->wu.id][wk->sa->nmsa_a_ix - 20])) {
        return 0;
    }

    conpane = &wk->cp->sw_lvbt;

    if (wk->cp->waza_flag[wk->sa->nmsa_a_ix] == -1) {
        return 0;
    }

    if (((wk->cp->btix[wk->sa->nmsa_a_ix] & 0xFF) != 0x80) && (wk->cp->waza_flag[wk->sa->nmsa_a_ix])) {
        cusw = conpane[wk->cp->btix[wk->sa->nmsa_a_ix] & 0xFF];

        for (j = 3; j >= 0; j--) {
            if (j == 3) {
                if (!(wk->cp->btix[wk->sa->nmsa_a_ix] & 0x600) || (wk->sa->ex4th_full && (wk->sa->mp != 1))) {
                    continue;
                }
            }

            exsw = cusw & cmdshot_conv_tbl[wk->cp->exdt[wk->sa->nmsa_a_ix][j]];

            if (exsw == cmdshot_conv_tbl[wk->cp->exdt[wk->sa->nmsa_a_ix][j] & 0xF]) {
                setup_comm_back(&wk->wu);
                wk->as = &_assadr_lv_9900[wk->player_number][cmdixconv(wk->sa->nmsa_a_ix)]
                                         [j + (((wk->sa->nmsa_a_ix) - 38) * 4)];
                wk->sa->ex4th_exec = ((j == 3) * (wk->sa->ex4th_full));
                wk->wu.cg_cancel = 0;
                wk->sa->ok = -1;
                hissatsu_setup_union(wk, wk->cp->waza_r[wk->sa->nmsa_a_ix][j]);
                waza_compel_all_init2(wk);
                chainex_check[wk->wu.id][wk->sa->nmsa_a_ix - 20] = 1;
                chainex_spat_cancel_kidou(&wk->wu);
                return 1;
            }
        }
    }

    return 0;
}

s32 execute_super_arts(PLW* wk) {
    if (wk->cancel_timer == 0) {
        wk->permited_koa |= 1;
    }

    if ((wk->sa->gauge_type != 3) && pcon_dp_flag) {
        return 0;
    }

    if (((Bonus_Game_Flag == 0x14) && wk->bs2_on_car) || (wk->wu.xyz[1].disp.pos <= 0)) {
        if (wk->spmv_ng_flag & 0x40000000) {
            return 0;
        }

        if (wk->sa->ok != 1) {
            return 0;
        }

        if (wk->sa->nmsa_g_ix > 28) {
            return 0;
        }

        setup_comm_back(&wk->wu);
        wk->as = _assadr_lv_9900[wk->player_number][cmdixconv(wk->sa->nmsa_g_ix)] + (wk->sa->nmsa_g_ix - 20) * 4;
        wk->sa->ex4th_exec = 0;
        wk->wu.cg_cancel = 0;
        wk->sa->ok = -1;
        hissatsu_setup_union(wk, wk->cp->waza_r[wk->sa->nmsa_g_ix][0]);
        waza_compel_all_init2(wk);
        wk->sa->gt2 = wk->sa->gauge_type;
        return 1;
    }

    if (wk->spmv_ng_flag & 0x80000000) {
        return 0;
    }

    if (wk->sa->ok != 1) {
        return 0;
    }

    if (wk->sa->nmsa_a_ix < 0x1C) {
        return 0;
    }

    setup_comm_back(&wk->wu);
    wk->as = _assadr_lv_9900[wk->player_number][cmdixconv(wk->sa->nmsa_a_ix)] + (wk->sa->nmsa_a_ix - 38) * 4;
    wk->sa->ex4th_exec = 0;
    wk->wu.cg_cancel = 0;
    wk->sa->ok = -1;
    hissatsu_setup_union(wk, wk->cp->waza_r[wk->sa->nmsa_a_ix][0]);
    waza_compel_all_init2(wk);
    wk->sa->gt2 = wk->sa->gauge_type;
    return 1;
}

s32 check_special_attack(PLW* wk) {
    s16 i;
    s16 j;
    u16 cusw;
    u16 exsw;
    u16* conpane;

    if (wk->cancel_timer == 0) {
        wk->permited_koa |= 2;
    }

    if (pcon_dp_flag) {
        return 0;
    }

    if (((Bonus_Game_Flag == 0x14) && wk->bs2_on_car) || (wk->wu.xyz[1].disp.pos <= 0)) {
        conpane = (u16*)wk->cp;

        for (i = 28; i < 38; i++) {
            if ((wk->spmv_ng_flag2 & 0x400000) && chainex_check[wk->wu.id][i - 20]) {
                continue;
            }

            if (wk->cp->waza_flag[i] == -1) {
                continue;
            }

            if ((wk->cp->btix[i] & 0x800) && shell_live_check(wk, i)) {
                continue;
            }

            if ((wk->cp->btix[i] & 0x1000) && (wk->metamorphose || (wk->sa->ok != -1))) {
                continue;
            }

            if (((wk->cp->btix[i] & 0xFF) == 0x80) || !wk->cp->waza_flag[i]) {
                continue;
            }

            cusw = conpane[wk->cp->btix[i] & 0xFF];

            for (j = 3; j >= 0; j--) {
                exsw = cusw & cmdshot_conv_tbl[wk->cp->exdt[i][j]];

                if (exsw != cmdshot_conv_tbl[wk->cp->exdt[i][j] & 0xF]) {
                    continue;
                }

                if (j == 3) {
                    if (!(wk->cp->btix[i] & 0x600)) {
                        continue;
                    }

                    if ((wk->cp->btix[i] & 0x200) && (wk->spmv_ng_flag & 0x10000000)) {
                        continue;
                    }

                    if (wk->metamorphose) {
                        if (wk->cp->btix[i] & 0x400) {
                            continue;
                        }
                    } else {
                        if ((wk->sa->mp == -1) || (wk->sa->ok == -1)) {
                            continue;
                        }

                        if (wk->cp->btix[i] & 0x400) {
                            if ((wk->spmv_ng_flag2 & 0x1000) || (wk->sa->ex != 1)) {
                                continue;
                            }

                            wk->sa->ex = -1;
                        }
                    }
                } else if (wk->spmv_ng_flag & 0x10000000) {
                    continue;
                }

                setup_comm_back(&wk->wu);
                wk->as = &_assadr_lv_9900[wk->player_number][cmdixconv(i)][j + (i - 28) * 4];
                wk->wu.cg_cancel &= 0x40;
                hissatsu_setup_union(wk, wk->cp->waza_r[i][j]);
                waza_flag_clear_only_1(wk->wu.id, i);
                grade_add_command_waza(wk->wu.id);
                chainex_check[wk->wu.id][i - 20] = 1;
                chainex_spat_cancel_kidou(&wk->wu);
                return 1;
            }
        }

        return 0;
    }

    if ((wk->spmv_ng_flag2 & 2) && (wk->wu.mvxy.a[1].sp > 0) && (wk->wu.xyz[1].disp.pos < 32)) {
        return 0;
    }

    conpane = (u16*)wk->cp;

    for (i = 46; i < 56; i++) {
        if ((wk->spmv_ng_flag2 & 0x400000) && chainex_check[wk->wu.id][i - 20]) {
            continue;
        }

        if (wk->cp->waza_flag[i] == -1) {
            continue;
        }

        if ((wk->cp->btix[i] & 0x1000) && (wk->metamorphose || (wk->sa->ok != -1))) {
            continue;
        }

        if ((wk->cp->btix[i] & 0x2000) && (wk->wu.mvxy.a[0].sp < 0)) {
            continue;
        }

        if ((wk->cp->btix[i] & 0xFF) != 0x80) {
            if (!wk->cp->waza_flag[i]) {
                continue;
            }

            cusw = conpane[wk->cp->btix[i] & 0xFF];

            for (j = 3; j >= 0; j--) {
                exsw = cusw & cmdshot_conv_tbl[wk->cp->exdt[i][j]];

                if (exsw != cmdshot_conv_tbl[wk->cp->exdt[i][j] & 0xF]) {
                    continue;
                }

                if (j == 3) {
                    if (!(wk->cp->btix[i] & 0x600)) {
                        continue;
                    }

                    if ((wk->cp->btix[i] & 0x200) && (wk->spmv_ng_flag & 0x20000000)) {
                        continue;
                    }

                    if (wk->metamorphose) {
                        if (wk->cp->btix[i] & 0x400) {
                            continue;
                        }
                    } else {
                        if ((wk->sa->mp == -1) || (wk->sa->ok == -1)) {
                            continue;
                        }

                        if (wk->cp->btix[i] & 0x400) {
                            if ((wk->spmv_ng_flag2 & 0x1000) || (wk->sa->ex != 1)) {
                                continue;
                            }

                            wk->sa->ex = -1;
                        }
                    }
                } else if (wk->spmv_ng_flag & 0x20000000) {
                    continue;
                }

                setup_comm_back(&wk->wu);
                wk->as = &_assadr_lv_9900[wk->player_number][cmdixconv(i)][j + (i - 46) * 4];
                wk->wu.cg_cancel &= 0x40;
                hissatsu_setup_union(wk, wk->cp->waza_r[i][j]);
                waza_flag_clear_only_1(wk->wu.id, i);
                grade_add_command_waza(wk->wu.id);
                chainex_check[wk->wu.id][i - 20] = 1;
                chainex_spat_cancel_kidou(&wk->wu);
                return 1;
            }

            continue;
        }

        if (wk->cp->waza_flag[i]) {
            setup_comm_back(&wk->wu);
            wk->as = &_assadr_lv_9900[wk->player_number][cmdixconv(i)][(i - 46) * 4];
            wk->wu.cg_cancel &= 0x40;
            hissatsu_setup_union(wk, wk->cp->waza_r[i][0]);
            waza_flag_clear_only_1(wk->wu.id, i);
            grade_add_command_waza(wk->wu.id);
            chainex_check[wk->wu.id][i - 20] = 1;
            chainex_spat_cancel_kidou(&wk->wu);
            return 1;
        }
    }

    return 0;
}

void chainex_spat_cancel_kidou(WORK* wk) {
    MVXY curr;

    if (wk->old_rno[1] == 4 && wk->old_rno[2] > 15) {
        curr = wk->mvxy;
        setup_mvxy_data(wk, 10);
        wk->mvxy.a[0].sp = curr.a[0].sp / 2;
        wk->mvxy.d[0].sp = 0;
        wk->mvxy.a[1].sp = curr.a[1].sp / 2;
    }
}

s32 check_leap_attack(PLW* wk) {
    if (wk->spmv_ng_flag2 & 0x10) {
        return 0;
    }

    if (pcon_dp_flag) {
        return 0;
    }

    wk->permited_koa |= 0x200;

    if (wk->spmv_ng_flag2 & 0x20) {
        if (wk->cp->ca25 == 0) {
            return 0;
        }

        if (wk->cp->sw_lvbt & 0xF) {
            return 0;
        }
    } else {
        if (wk->cp->waza_flag[14] == 0) {
            return 0;
        }

        if (!(wk->cp->sw_now & 0x770)) {
            return 0;
        }
    }

    if (((Bonus_Game_Flag != 0x14) || !wk->bs2_on_car) && (wk->wu.xyz[1].disp.pos > 0)) {
        return 0;
    }

    setup_comm_back(&wk->wu);
    wk->as = &_asstbl_lv_D010[wk->player_number];
    hissatsu_setup_union(wk, wk->cp->waza_r[14][0]);
    return 1;
}

s32 check_nm_attack(PLW* wk) {
    s16 kos;
    s16 koa;

    wk->permited_koa |= 4;

    if ((kos = shot_data_convert(wk->cp->sw_now)) < 0) {
        return 0;
    }

    switch (wk->wu.pat_status) {
    case 20:
        if (hikusugi_check(&wk->wu)) {
            return 0;
        }

        koa = waza_select(wk, kos, 3);
        wk->as = &_asstbl_lv_3010[wk->player_number][kos][koa];
        break;

    case 14:
        if (hikusugi_check(&wk->wu)) {
            return 0;
        }

        koa = waza_select(wk, kos, 6);
        wk->as = &_asstbl_lv_3010[wk->player_number][kos][koa];
        break;

    case 26:
        if (hikusugi_check(&wk->wu)) {
            return 0;
        }

        koa = waza_select(wk, kos, 9);
        wk->as = &_asstbl_lv_3010[wk->player_number][kos][koa];
        break;

    case 22:
        if (hikusugi_check(&wk->wu)) {
            return 0;
        }

        koa = waza_select(wk, kos, 2);
        wk->as = &_asstbl_lv_2010[wk->player_number][kos][koa];
        break;

    case 16:
        if (hikusugi_check(&wk->wu)) {
            return 0;
        }

        koa = waza_select(wk, kos, 5);
        wk->as = &_asstbl_lv_2010[wk->player_number][kos][koa];
        break;

    case 28:
        if (hikusugi_check(&wk->wu)) {
            return 0;
        }

        koa = waza_select(wk, kos, 8);
        wk->as = &_asstbl_lv_2010[wk->player_number][kos][koa];
        break;

    case 24:
        if (hikusugi_check(&wk->wu)) {
            return 0;
        }

        koa = waza_select(wk, kos, 4);
        wk->as = &_asstbl_lv_4010[wk->player_number][kos][koa];
        break;

    case 18:
        if (hikusugi_check(&wk->wu)) {
            return 0;
        }

        koa = waza_select(wk, kos, 7);
        wk->as = &_asstbl_lv_4010[wk->player_number][kos][koa];
        break;

    case 30:
        if (hikusugi_check(&wk->wu)) {
            return 0;
        }

        koa = waza_select(wk, kos, 10);
        wk->as = &_asstbl_lv_4010[wk->player_number][kos][koa];
        break;

    default:
        if (((Bonus_Game_Flag != 0x14) || !wk->bs2_on_car) && (wk->wu.xyz[1].disp.pos > 0)) {
            return 0;
        }

        if (wk->cp->sw_lvbt & 2) {
            koa = waza_select(wk, kos, 1);
            wk->as = &_asstbl_lv_1010[wk->player_number][kos][koa];
        } else {
            koa = waza_select(wk, kos, 0);
            wk->as = &_asstbl_lv_0010[wk->player_number][kos][koa];
        }

        break;
    }

    setup_comm_back(&wk->wu);
    wk->current_attack = shot_data_refresh(kos);
    set_attack_routine_number(wk);
    wk->wu.paring_attack_flag = 0;
    wk->wu.meoshi_hit_flag = 0;
    wk->wu.att_hit_ok = 0;
    wk->wu.hf.hit_flag = 0;
    wk->wu.cg_cancel &= 0xF8;
    return 1;
}

s16 hikusugi_check(WORK* wk) {
    s16 rnum = 0;

    if ((wk->mvxy.a[1].real.h < 0) && (wk->xyz[1].disp.pos < 16)) {
        rnum = 1;
    }

    return rnum;
}

s32 check_chouhatsu(PLW* wk) {
    if (wk->spmv_ng_flag & 1) {
        return 0;
    }

    if ((wk->spmv_ng_flag & 2) && pcon_dp_flag) {
        return 0;
    }

    wk->permited_koa |= 0x80;

    if (wk->wu.xyz[1].disp.pos > 0) {
        return 0;
    }

    if (wk->player_number == 6) {
        if (wk->cp->sw_lvbt & 0xE) {
            return 0;
        }
    } else if (wk->cp->sw_lvbt & 0xF) {
        return 0;
    }

    if (wk->cp->ca36 == 0) {
        return 0;
    }

    wk->as = &_asstbl_lv_E010[wk->player_number];
    setup_comm_back(&wk->wu);
    set_attack_routine_number(wk);
    wk->wu.paring_attack_flag = 0;
    wk->wu.meoshi_hit_flag = 0;
    wk->wu.att_hit_ok = 0;
    wk->wu.hf.hit_flag = 0;
    return 1;
}

s32 check_nagenuke_cmd(PLW* wk) {
    if (wk->spmv_ng_flag2 & 0x400) {
        return 0;
    }

    if (wk->cat_break_reserve) {
        return 1;
    }

    if ((wk->spmv_ng_flag2 & 0x800) && (wk->cp->sw_lvbt & 3)) {
        return 0;
    }

    if (wk->cp->sw_now & 0x660) {
        return 0;
    }

    if (wk->cp->ca14) {
        return 1;
    }

    return 0;
}

s32 check_catch_attack(PLW* wk) {
    s16 kos;

    if (pcon_dp_flag) {
        return 0;
    }

    if (wk->spmv_ng_flag2 & 0x100) {
        return 0;
    }

    wk->permited_koa |= 0x100;

    if (wk->cp->ca14 == 0) {
        return 0;
    }

    kos = ((wk->cp->sw_new & 4) != 0) + (((wk->cp->sw_new & 8) != 0) * 2);

    if ((wk->wu.pat_status < 0xE) || (wk->wu.pat_status > 0x1E)) {
        if (wk->cp->sw_lvbt & 3) {
            return 0;
        }

        wk->as = &_asstbl_lv_A010[kos];
    } else {
        if (!(nml_catch_h2_ok[1][wk->player_number] & 0x10)) {
            return 0;
        }

        if (wk->wu.xyz[1].disp.pos < 24) {
            return 0;
        }

        wk->as = &_asstbl_lv_B010[kos];
    }

    setup_comm_back(&wk->wu);
    set_attack_routine_number(wk);
    wk->cancel_timer = 0;
    wk->wu.paring_attack_flag = 0;
    wk->wu.meoshi_hit_flag = 0;
    wk->wu.att_hit_ok = 0;
    wk->wu.hf.hit_flag = 0;
    wk->wu.cg_cancel = 0;
    return 1;
}

void set_attack_routine_number(PLW* wk) {
    wk->wu.routine_no[1] = 4;
    wk->wu.routine_no[2] = wk->as->r_no;
    wk->wu.routine_no[3] = 0;
    wk->wu.cg_type = 0;
}

u16 get_nearing_range(s16 pnum, s16 kos) {
    const u16* asstbl;
    u16 nrange = 0;
    u16 lwork;

    if ((kos = shot_data_convert(kos)) < 0) {
        return nrange;
    }

    asstbl = _asstbl_lv_0000[pnum][kos];

    if ((lwork = asstbl[0] & 0x7FF)) {
        nrange = lwork;
    } else {
        if ((lwork = asstbl[1] & 0x7FF)) {
            nrange = lwork;
        }
    }

    return nrange;
}

s32 waza_select(PLW* wk, s16 kos, s16 sf) {
    const u16* wst;

    switch (sf) {
    case 0:
        wst = _asstbl_lv_0000[wk->player_number][kos];
        break;

    case 1:
        wst = _asstbl_lv_1000[wk->player_number][kos];
        break;

    case 2:
        wst = _asstbl_lv_2000[wk->player_number][kos];
        break;

    case 3:
        wst = _asstbl_lv_3000[wk->player_number][kos];
        break;

    case 4:
        wst = _asstbl_lv_4000[wk->player_number][kos];
        break;

    case 5:
        wst = _asstbl_lv_2000[wk->player_number][kos];
        break;

    case 6:
        wst = _asstbl_lv_3000[wk->player_number][kos];
        break;

    case 7:
        wst = _asstbl_lv_4000[wk->player_number][kos];
        break;

    case 8:
        wst = _asstbl_lv_2000[wk->player_number][kos];
        break;

    case 9:
        wst = _asstbl_lv_3000[wk->player_number][kos];
        break;

    case 10:
        wst = _asstbl_lv_4000[wk->player_number][kos];
        break;

    default:
        return 0;
    }

    if (decode_wst_data(wk, wst[0], wst[1])) {
        return 2;
    }

    if (decode_wst_data(wk, wst[1], wst[1])) {
        return 1;
    }

    return 0;
}

u16 decode_wst_data(PLW* wk, u16 cmd, s16 cmd_ex) {
    u16 lever;
    u16 rnum;

    if (cmd == 0) {
        return 0;
    }

    rnum = 0;
    lever = cmd & 0xF;

    switch (cmd & 0xF000) {
    case 0x4000:
        rnum = wk->cp->sw_new & lever;
        break;

    case 0x8000:
        rnum = (lever == (wk->cp->sw_new & 0xF));
        break;

    case 0x3000:
        rnum = cmd_ex_check(wk->wu.xyz[1].disp.pos, cmd_ex);
        break;

    case 0x7000:
        if ((wk->cp->sw_new & lever) && (cmd_ex_check(wk->wu.xyz[1].disp.pos, cmd_ex))) {
            rnum = 1;
        }

        break;

    case 0xB000:
        if ((lever == (wk->cp->sw_new & 0xF)) && (cmd_ex_check(wk->wu.xyz[1].disp.pos, cmd_ex))) {
            rnum = 1;
        }

        break;

    case 0x2000:
        if ((wk->wu.mvxy.a[1].sp > 0) && (cmd_ex_check(wk->wu.xyz[1].disp.pos, cmd_ex))) {
            rnum = 1;
        }

        break;

    case 0x1000:
        if ((wk->wu.mvxy.a[1].sp <= 0) && (cmd_ex_check(wk->wu.xyz[1].disp.pos, cmd_ex))) {
            rnum = 1;
        }

        break;

    case 0xA000:
        if ((wk->wu.mvxy.a[1].sp > 0) && (lever == (wk->cp->sw_new & 0xF)) &&
            (cmd_ex_check(wk->wu.xyz[1].disp.pos, cmd_ex))) {
            rnum = 1;
        }

        break;

    case 0x9000:
        if ((wk->wu.mvxy.a[1].sp <= 0) && (lever == (wk->cp->sw_new & 0xF)) &&
            (cmd_ex_check(wk->wu.xyz[1].disp.pos, cmd_ex))) {
            rnum = 1;
        }

        break;

    case 0x6000:
        if ((wk->wu.mvxy.a[1].sp > 0) && (cmd_ex_check(wk->wu.xyz[1].disp.pos, cmd_ex))) {
            rnum = wk->cp->sw_new & lever;
        }

        break;

    case 0x5000:
        if ((wk->wu.mvxy.a[1].sp <= 0) && (cmd_ex_check(wk->wu.xyz[1].disp.pos, cmd_ex))) {
            rnum = wk->cp->sw_new & lever;
        }

        break;

    default:
        if (get_em_body_range(&wk->wu) >= cmd) {
            rnum = 1;
        }

        break;
    }

    return rnum;
}

s16 get_em_body_range(WORK* wk) {
    WORK* em;
    s16* dad;
    s16 res_hs;

    if (Bonus_Game_Flag == 20 && wk->operator != 0) {
        em = (WORK*)((WORK*)wk->target_adrs)->my_effadrs;
        dad = (s16*)(em->hosei_adrs + (get_sel_hosei_tbl_ix(((WORK_Other*)em)->master_player) + 1));
        res_hs = wk->xyz[0].disp.pos - (em->xyz[0].disp.pos + dad[0] + (dad[1] / 2));

        if (res_hs < 0) {
            res_hs = -res_hs;
        }

        res_hs -= (dad[1] / 2);

        return res_hs;
    }

    em = (WORK*)wk->target_adrs;
    res_hs = (wk->xyz[0].disp.pos) - (em->xyz[0].disp.pos);

    if (res_hs < 0) {
        res_hs = -res_hs;
    }

    res_hs += em->hosei_adrs[1].hos_box[0];

    return res_hs;
}

s32 cmd_ex_check(s16 px, s16 cx) {
    if (cx) {
        if (cx < 0) {
            if (px + cx <= 0) {
                return 1;
            }
        } else if (px - cx >= 0) {
            return 1;
        }
    } else {
        return 1;
    }

    return 0;
}

s16 shot_data_convert(u16 sw) {
    s16 i;
    s16 rnum = -1;

    for (i = 0; i < 6; i++) {
        if (sw & shot_prio[i][0]) {
            rnum = shot_prio[i][1];
        }
    }

    return rnum;
}

s16 shot_data_refresh(s16 sw) {
    return shot_refresh[sw];
}

s16 renbanshot_conpaneshot(const s16* dadr, s16 pow) {
    return rc_shot_conv[dadr[pow] & 0xF];
}

s16 datacmd_conpanecmd(s16 dat) {
    dat = (dat & 0x700) >> 1 | (dat & 0x7F);
    return dat;
}

s32 check_renda_cancel(PLW* wk) {
    if (wk->wu.rl_flag != wk->wu.rl_waza) {
        return 0;
    }

    wk->permited_koa |= 32;

    if (wk->wu.pat_status == renda_status_table[(wk->cp->sw_new & 3)] &&
        wk->current_attack == (wk->cp->sw_now & 0x770)) {
        setup_comm_back(&wk->wu);
        wk->wu.cg_ix = wk->wu.cg_eftype * wk->wu.cgd_type - (wk->wu.cgd_type * 2);
        wk->wu.cg_next_ix = 0;
        wk->wu.cg_ctr = 1;
        wk->wu.meoshi_hit_flag = 0;
        wk->wu.att_hit_ok = 0;
        wk->wu.hf.hit_flag = 0;
        wk->caution_flag = 1;
        wk->cancel_timer = 0;
        wk->wu.cg_cancel &= 0xE0;
        sub_0004384A(&wk->wu);
        return 1;
    }

    return 0;
}

s32 check_meoshi_cancel(PLW* wk) {
    s16 i;
    s16 tdat;
    s16 wdat;

    wk->permited_koa |= 0x10;

    if (wk->wu.meoshi_hit_flag == 0) {
        return 0;
    }

    tdat = wk->wu.cg_meoshi & 0x8F;

    switch (tdat) {
    default:
        wdat = cnmc_conv_data[wk->cp->sw_new & 0xF];
        tdat &= 0xF;

        while (1) {
            if (wk->wu.cg_meoshi & 0x80) {
                for (i = 0; i < 6; i++) {
                    if (cnmc_Z_lever_data[tdat][i] == -1) {
                        return 0;
                    }

                    if (wdat == cnmc_Z_lever_data[tdat][i]) {
                        goto case_0;
                    }
                }
            } else {
                for (i = 0; i < 8; i++) {
                    if (_cnmc_z_lever_data[tdat][i] == -1) {
                        return 0;
                    }

                    if (wdat == _cnmc_z_lever_data[tdat][i]) {
                        goto case_0;
                    }
                }
            }
            return 0;
        }

    case 0:
    case_0:
        if ((tdat = wk->wu.cg_meoshi & 0x770) == 0) {
            if (!(wk->wu.cg_meoshi & 0x800)) {
                return 0;
            }

            break;
        }

        wdat = wk->cp->sw_new & 0x770;

        if (wdat & ~tdat) {
            return 0;
        }

        if (shot_data_convert(wk->cp->sw_now) >= 0) {
            if ((wk->wu.cg_meoshi & 0x800)) {
                break;
            }

            goto end;
        }

        if (!(wk->wu.cg_cancel & 0x80)) {
            return 0;
        }

        wdat = wk->cp->sw_off & 0x770;

        if (wdat & ~tdat) {
            return 0;
        }

        if (shot_data_convert(wk->cp->sw_off) < 0) {
            return 0;
        }

        if (!(wk->wu.cg_meoshi & 0x800)) {
            return 0;
        }

        break;
    }

    if (wk->wu.cg_meoshi & 0x1000) {
        if (char_move_cmms3(wk) == 0) {
            return 0;
        }
    } else {
        char_move_cmms2(&wk->wu);
    }

    wk->wu.hf.hit_flag = 0;
    wk->wu.att_hit_ok = 0;
    wk->wu.meoshi_hit_flag = 0;
    wk->wu.cg_cancel &= 0x60;

    if ((wk->tc_1st_flag == 0) && (wk->wu.now_koc == 4)) {
        grade_add_target_combo(wk->wu.id);
    }

    wk->tc_1st_flag = 1;
    sub_0004384A(wk);
    return 1;

end:
    if ((wk->tc_1st_flag == 0) && wk->wu.now_koc == 4) {
        grade_add_target_combo(wk->wu.id);
    }

    check_nm_attack(wk);
    wk->tc_1st_flag = 1;
    return 1;
}

s16 get_meoshi_lever(s16 data) {
    return gml_real_lever_data[data & 0xF];
}

s16 get_meoshi_shot(s16 data) {
    return ((data & 0x700) >> 1) + (data & 0x70);
}
