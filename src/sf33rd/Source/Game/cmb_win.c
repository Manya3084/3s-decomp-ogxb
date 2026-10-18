/* cmb_win.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * combo_cont_init 0xB4448 size 0xE9. Read against the x86: memset is inlined
 * as rep stosd; 0x46 dwords is sizeof(cmst_buff). cmst_buff is 0x7BC380.
 * combo_type is 0xC7D780. remake_power is 0xC7E040. The C is the PS2 C.
 * combo_rp_clear_check 0xB4531 size 0x44.
 * super_arts_last_check 0xB4575 size 0x2D.
 * first_attack_pts_check 0xB45A2 size 0x2F.
 * reversal_continue_check 0xB45D1 size 0x1F.
 * reversal_attack_pts_check 0xB45F0 size 0xC.
 * arts_finish_check 0xB45FC size 0x30.
 * arts_finish_check2 0xB462C size 0x3E.
 * SCORE_PLUS 0xB4738 size 0x42.
 * combo_window_push 0xB477A size 0x298. Read against the x86: 0x64 is the C's
 * * 100, setne/dec/and -0x2710/add 0x7530 the branchless choice of 30000 or
 * 20000 points, 0x1C the cmst_buff record stride, and 0xFF the pts_digit end
 * mark. Matches the C.
 * combo_window_trans 0xB4A12 size 0x4B1. Read against the x86: 0x1C is the
 * cmst_buff record stride and 0x15 the per-player stride of the message slots.
 * MSVC merges the C's repeated combo_pts_set, combo_message_set and Score_Sub
 * calls, so the x86 has fewer calls. Matches the C.
 * training_disp_data_set 0xB4EC3 size 0x60.
 * combo_hensuu_clear 0xB5289 size 0x70. Read against the x86: the C's memsets
 * are inlined as stosd. Matches the C.
 * super_arts_finish_check 0xB52F9 size 0x3A.
 * reversal_check 0xB5333 size 0x6D.
 * paring_check 0xB53A0 size 0x3A.
 * hit_combo_check 0xB53DA size 0x72.
 * check_and_set_combo 0xB544C size 0x7B.
 * combo_control 0xB54C7 size 0xD0.
 * combo_cont_main 0xB5597 size 0xB6. Read against the x86: 0xFF is the s8 loop
 * counter's end at -1. Matches the C.
 * Not located in sf33rd.xbe; their PS2 C is kept under #if 0:
 * SCORE_CALCULATION.
 * SCORE_CALCULATION has no XBE name and no aligned call.
 * grade_add_reversal stays sub_0005D988, the one unnamed call left in its
 * caller.
 * grade_get_first_attack has no XBE name and no aligned call.
 * grade_max_combo_check has no XBE name and no aligned call.
 * memset has no XBE name and no aligned call.
 * Data: cmst_buff 0x7BC380.
 * Data: old_cmb_flag: defined elsewhere on Xbox.
 * Data: cmb_stock: defined elsewhere on Xbox.
 * Data: first_attack: defined elsewhere on Xbox.
 * Data: rever_attack: defined elsewhere on Xbox.
 * Data: paring_attack: defined elsewhere on Xbox.
 * Data: bonus_pts: defined elsewhere on Xbox.
 * Data: hit_num: defined elsewhere on Xbox.
 * Data: sa_kind: defined elsewhere on Xbox.
 * Data: end_flag: defined elsewhere on Xbox.
 * Data: calc_hit 0x7BC340.
 * Data: score_calc: defined elsewhere on Xbox.
 * Data: cmb_all_stock: defined elsewhere on Xbox.
 * Data: sarts_finish_flag: defined elsewhere on Xbox.
 * Data: last_hit_time: defined elsewhere on Xbox.
 * Data: cmb_calc_now: defined elsewhere on Xbox.
 * Data: cst_read: defined elsewhere on Xbox.
 * Data: cst_write: defined elsewhere on Xbox.
 * Data: cmb_pos_tbl: not located in the XBE, PS2 initializer kept.
 * Data: cmb_window_move_tbl is 0x27F6CC, 0x7 bytes compared.
 * Data: cmb_window_time_tbl is 0x27F6D4, 0x7 bytes compared.
 * Data: combo_score_tbl is 0x27F6DC, 0x30 bytes compared.
 * Unnamed data used (not checked): combo_cont_main: 0x7bc2d8,0x7bc2d4;
 * super_arts_last_check: 0x7bc2de,0x7bc49c; hit_combo_check:
 * 0x7bc49e,0x7bc2d0; check_and_set_combo: 0x7bc2e2,0x7bc2e4,0x7bc2e0;
 * combo_control: 0x7bc2d6,0x7bc2e0,0x7bc2e4,0x7bc49c; combo_cont_init:
 * 0x7bc498,0x7bc49e,0x7bc49c; super_arts_finish_check: 0x7bc2d0;
 * reversal_check: 0x7bc2e0; reversal_continue_check: 0x7bc2e0;
 * first_attack_pts_check: 0x7bc2e4,0x7bc49e; arts_finish_check: 0x7bc2de;
 * paring_check: 0x7a8314,0x7bc2da; combo_hensuu_clear: 0x7bc49e;
 * reversal_attack_pts_check: 0x7bc49e.
 * Globals: cmb_window_move_tbl 0x27F6CC, cmb_window_time_tbl 0x27F6D4,
 * Play_Type 0x7A812D, Training_ID 0x7A81FE, Mode_Type 0x7A825A,
 * Conclusion_Type 0x7A82D0, Disp_Attack_Data 0x7A82F8, Stop_Combo 0x7A82FC,
 * Demo_Flag 0x7A842D, Score 0x7A8720, Loser_id 0x7A875C, Game_timer 0x7A8830,
 * Conclusion_Flag 0x7A88D4, Champion 0x7A8931, Game_pause 0x7A89B0, tr_data
 * 0x7A9D60, calc_hit 0x7BC340, cmst_buff 0x7BC380, plw 0xC7CEA0, combo_type
 * 0xC7D780, pcon_dp_flag 0xC7D8D0, remake_power 0xC7E040.
 */

#include "structs.h"

void sub_0005D988(s16 ix);
void work_init_zero(s32* adrs_int, s32 xx);
extern ComboType combo_type[2];
extern ComboType remake_power[2];
extern void* memset(void* s, int c, size_t n);
extern s8 Stop_Combo;
extern s8 Demo_Flag;
extern u8 Game_pause;
extern u16 Game_timer;
void combo_control(s8 PL);
void combo_window_trans(s8 PL);
s16 check_combo_end(s16 ix);
s32 reversal_check(s8 PL);
void reversal_continue_check(s8 PL);
s32 paring_check(s8 PL);
extern PLW plw[2];
void combo_window_push(s8 PL, s8 KIND);
extern u8 pcon_dp_flag;
void super_arts_last_check(s8 PL);
void training_disp_data_set(s8 PL, s16 hnum);
void super_arts_finish_check(s8 PL);
void combo_hensuu_clear(s8 PL);
void check_and_set_combo(s8 PL);
void first_attack_pts_check(s8 PL);
void reversal_attack_pts_check(s8 PL);
void hit_combo_check(s8 PL);
void combo_rp_clear_check(s8 PL);
extern TrainingData2 tr_data[];
s32 arts_finish_check2(u8 PL);
extern u8 paring_bonus_r[2];
s32 arts_finish_check(s8 PL);
extern u8 Conclusion_Flag;
extern u8 Conclusion_Type;
extern s8 Loser_id;
extern u32 Score[2][3];
extern u8 Play_Type;
u32 SCORE_CALCULATION(s8 PL);
void grade_max_combo_check(s16 ix, s16 num);
void grade_get_first_attack(s16 ix);
extern u8 paring_counter[2];
extern u8 Mode_Type;
void Score_Sub();
extern u8 Training_ID;
void combo_message_set(u8 pl, u8 kind, u8 x, u8 num, u8 hi, u8 low);
void combo_pts_set(u8 pl, u8 x, u8 num, s8* pts, s8 digit);
extern u8 Disp_Attack_Data;
extern s8 Champion;
void SsRequest(u16 ReqNumber);

extern CMST_BUFF cmst_buff[2][5];

extern s16 old_cmb_flag[2];

extern s8 cmb_stock[2];

extern s8 first_attack;

extern s8 rever_attack[2];

extern s8 paring_attack[2];

extern s8 bonus_pts[2];

extern s16 hit_num;

extern u8 sa_kind;

extern u8 end_flag[2];

extern s16 calc_hit[2][10];

extern s16 score_calc[2][12];

extern s8 cmb_all_stock[];

extern s8 sarts_finish_flag[2];

extern s8 last_hit_time;

extern s8 cmb_calc_now[];

extern u8 cst_read[2];

extern u8 cst_write[2];

const u8 cmb_pos_tbl[2][21] = { { 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27 },
                                { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 } };

const u8 cmb_window_move_tbl[7] = { 12, 16, 20, 16, 12, 10, 12 };

const u8 cmb_window_time_tbl[7] = { 28, 40, 60, 60, 50, 50, 24 };

const u16 combo_score_tbl[12][2] = { { 300, 200 },   { 500, 400 },   { 1000, 600 },  { 1000, 600 },
                                     { 2000, 800 },  { 3000, 600 },  { 4000, 800 },  { 5000, 1000 },
                                     { 6000, 2000 }, { 8000, 2000 }, { 9000, 3000 }, { 10000, 4000 } };

void combo_cont_init() {
    u8 i;

    for (i = 0; i < 2; i++) {
        old_cmb_flag[i] = 0;
        cmb_stock[i] = 0;
        rever_attack[i] = 0;
        paring_attack[i] = 0;
        bonus_pts[i] = 0;
        sarts_finish_flag[i] = 0;
        cmb_calc_now[i] = 0;
        cst_read[i] = 0;
        cst_write[i] = 0;
        work_init_zero((s32*)&combo_type[i], sizeof(ComboType));
        work_init_zero((s32*)&remake_power[i], sizeof(ComboType));
        memset(calc_hit[i], 0, sizeof(calc_hit[0]));
        memset(score_calc[i], 0, sizeof(score_calc[0]));
    }

    first_attack = 0;
    hit_num = 0;
    sa_kind = 0;
    cmb_all_stock[0] = 0;
    last_hit_time = 0;
    memset(&cmst_buff, 0, sizeof(cmst_buff));
}

void combo_cont_main() {
    s8 i;

    if (Stop_Combo) {
        if (Demo_Flag) {
            return;
        }
        combo_cont_init();

        if (Demo_Flag) {
            Stop_Combo = 0;
        }

        return;
    }

    if (Demo_Flag != 0) {
        if (Game_pause == 0) {
            if (Game_timer & 1) {
                for (i = 0; i < 2; i++) {
                    combo_control(i);
                    combo_window_trans(i);
                }
            } else {
                for (i = 1; i > -1; i--) {
                    combo_control(i);
                    combo_window_trans(i);
                }
            }
        } else {
            for (i = 0; i < 2; i++) {
                combo_window_trans(i);
            }
        }

        cmb_all_stock[0] = cmb_stock[0] + cmb_stock[1];
    }
}

void combo_control(s8 PL) {
    s16 cmb_flag;

    cmb_flag = check_combo_end(PL + 0);

    if (cmb_flag) {
        cmb_calc_now[PL] = 1;
    } else {
        cmb_calc_now[PL] = 0;
    }

    if (reversal_check(PL) == 0) {
        if (rever_attack[PL]) {
            reversal_continue_check(PL);
        }

        if (!paring_check(PL) && plw[PL].cb->total) {
            if (first_attack == 0) {
                first_attack = plw[PL].wu.id + 1;
                combo_window_push(PL, 4);
                return;
            }

            if (pcon_dp_flag == 1 && last_hit_time == 0) {
                super_arts_last_check(PL);
            }

            if (cmb_flag != 0) {
                return;
            } else if (plw[PL].cb->total == 1) {
                training_disp_data_set(PL, 1);
                super_arts_finish_check(PL);
                combo_hensuu_clear(PL);
                first_attack = 3;
                return;
            }

            check_and_set_combo(PL);
        }
    }
}

void check_and_set_combo(s8 PL) {
    s8 PLS;

    if (PL == 0) {
        PLS = 1;
    } else {
        PLS = 0;
    }

    hit_num = plw[PL].cb->total;

    if (hit_num > 99) {
        hit_num = 99;
    }

    training_disp_data_set(PL, hit_num);

    if (first_attack == 1 || first_attack == 2) {
        first_attack_pts_check(PL);
    }

    if (rever_attack[PLS] == 1) {
        reversal_attack_pts_check(PL);
    }

    hit_combo_check(PL);
    combo_hensuu_clear(PL);
}

void combo_hensuu_clear(s8 PL) {
    work_init_zero((s32*)plw[PL].cb, sizeof(ComboType));
    combo_rp_clear_check(PL);
    memset(calc_hit[PL], 0, sizeof(calc_hit[0]));
    memset(score_calc[PL], 0, sizeof(score_calc[0]));
    bonus_pts[PL] = 0;
    plw[PL].cb->total = 0;
    hit_num = 0;
    tr_data[PL].total_damage = 0;
}

void combo_rp_clear_check(s8 PL) {
    if (plw[PL].wu.routine_no[1] != 1 || plw[PL].wu.routine_no[2] != 17 || plw[PL].wu.routine_no[3] == 0 ||
        plw[PL].wu.routine_no[3] == 3) {
        work_init_zero((s32*)plw[PL].rp, sizeof(ComboType));
    }
}

void super_arts_finish_check(s8 PL) {
    if (arts_finish_check2(PL) != 0) {
        if ((plw[PL].cb->new_dm & 0x3F) < 48) {
            sa_kind = 2;
        } else {
            sa_kind = 3;
        }

        combo_window_push(PL, 3);
    }
}

void super_arts_last_check(s8 PL) {
    if ((plw[PL].cb->new_dm & 0x3F) >= 0x20) {
        sarts_finish_flag[PL] = 1;
    } else {
        sarts_finish_flag[PL] = 0;
    }

    last_hit_time = 1;
}

void first_attack_pts_check(s8 PL) {
    if (first_attack - 1 == plw[PL].wu.id) {
        first_attack = 3;
        bonus_pts[PL] += 2;
    }
}

s32 reversal_check(s8 PL) {
    s8 PLS;

    if (rever_attack[PL]) {
        return 0;
    }

    if (plw[PL].wu.routine_no[1] == 4 && plw[PL].wu.old_rno[1] == 1 && pcon_dp_flag == 0 &&
        plw[PL].wu.routine_no[2] >= 0x10) {
        rever_attack[PL] = 1;

        if (PL == 0) {
            PLS = (1);
        } else {
            PLS = 0;
        }

        combo_window_push(PLS, 5);
        sub_0005D988(PL);
        return 1;
    }

    return 0;
}

void reversal_continue_check(s8 PL) {
    if (plw[PL].wu.routine_no[1] != 4) {
        rever_attack[PL] = 0;
    } else {
        return;
    }
}

void reversal_attack_pts_check(s8 PL) {
    bonus_pts[PL]++;
}

s32 paring_check(s8 PL) {
    s8 PLS;

    if (paring_bonus_r[PL]) {
        paring_bonus_r[PL] = 0;
        paring_attack[PL] = 1;

        if (PL == 0) {
            PLS = 1;
        } else {
            PLS = 0;
        }

        combo_window_push(PLS, 6);
        return 1;
    }

    return 0;
}

void hit_combo_check(s8 PL) {
    s32* sa_ptr = (s32*)plw[PL].cb->kind_of[4][0];
    s8 lpx;

    for (lpx = 0; lpx < 20; lpx++) {
        if (!(*sa_ptr++ == 0)) {
            if (arts_finish_check(PL)) {
                if (lpx < 8) {
                    bonus_pts[PL] += 2;
                    sa_kind = 2;
                } else {
                    bonus_pts[PL] += 3;
                    sa_kind = 3;
                }

                combo_window_push(PL, 2);
                return;
            }

            combo_window_push(PL, 1);
            return;
        }
    }

    combo_window_push(PL, 0);
}

s32 arts_finish_check(s8 PL) {
    if (Conclusion_Flag && Conclusion_Type == 0 && Loser_id == PL && sarts_finish_flag[PL]) {
        return 1;
    }

    return 0;
}

s32 arts_finish_check2(u8 PL) {
    if (Conclusion_Flag && Conclusion_Type == 0 && Loser_id == PL && (plw[PL].cb->new_dm & 0x3F) >= 32) {
        return 1;
    }

    return 0;
}

void SCORE_PLUS(s8 PL, u32 PTS) {
    Score[PL][2] += PTS;
    if (Score[PL][2] >= 99999900) {
        Score[PL][2] = 99999900;
    }

    Score[PL][Play_Type] += PTS;
    if (Score[PL][Play_Type] >= 99999900) {
        Score[PL][Play_Type] = 99999900;
    }
}

void combo_window_push(s8 PL, s8 KIND) {
    u32 score;
    s8 PLS;
    u32 Pts_Buff;
    s32 xx;
    s16 i;

    s32 assign1;
    s32 assign2;

    if (KIND < 3) {
        score = SCORE_CALCULATION(PL);
        grade_max_combo_check(PL ^ 1, hit_num);
    }

    if (PL == 0) {
        PLS = 1;
    } else {
        PLS = 0;
    }

    if (cmb_stock[PL] == 5) {
        switch (KIND) {
        case 2:
            if (sa_kind == 2) {
                score += 20000;
            } else {
                score += 30000;
            }
            break;

        case 3:
            if (sa_kind == 2) {
                score = 20000;
            } else {
                score = 30000;
            }
            break;

        case 4:
            score = 1500;
            grade_get_first_attack(PLS);
            break;

        case 6:
            score = paring_counter[PLS] * 100;
            break;
        }

        if (score >= 1000000) {
            score = 999900;
        }

        SCORE_PLUS(PLS, score);

        if (Mode_Type == 1) {
            Score_Sub();
        } else if (plw[PLS].wu.operator) {
            Score_Sub();
        }

        return;
    } else {
        cmb_stock[PL]++;
        cmst_buff[PL][cst_write[PL]].routine_num = 0;
        cmst_buff[PL][cst_write[PL]].hit_hi = (u8)hit_num / 10;
        cmst_buff[PL][cst_write[PL]].hit_low = (u8)hit_num - (cmst_buff[PL][cst_write[PL]].hit_hi * 10);
        cmst_buff[PL][cst_write[PL]].kind = KIND;

        if (Mode_Type == 1) {
            cmst_buff[PL][cst_write[PL]].pts_flag = 1;
        } else if (Mode_Type == 5) {
            cmst_buff[PL][cst_write[PL]].pts_flag = 1;
        } else if (plw[PLS].wu.operator) {
            cmst_buff[PL][cst_write[PL]].pts_flag = 1;
        } else {
            cmst_buff[PL][cst_write[PL]].pts_flag = 0;
        }

        switch (KIND) {
        case 0:
        case 1:
            break;

        case 2:
            if (sa_kind == 2) {
                score += 20000;
            } else {
                score += 30000;
            }
            break;

        case 3:
            if (sa_kind == 2) {
                score = 20000;
            } else {
                score = 30000;
            }
            break;

        case 4:
            score = 1500;
            grade_get_first_attack(PLS);
            break;

        case 5:
            score = 0;
            cmst_buff[PL][cst_write[PL]].pts_flag = 0;
            break;

        case 6:
            score = paring_counter[PLS] * 100;
            break;
        }

        if (score >= 1000000) {
            score = 999900;
        }

        Pts_Buff = cmst_buff[PL][cst_write[PL]].pts = score;
        i = 3;
        xx = 100000;

        assign1 = cmst_buff[PL][cst_write[PL]].first_digit = -1;

        while (i >= 0) {
            cmst_buff[PL][cst_write[PL]].pts_digit[i] = Pts_Buff / xx & 0xFF;
            Pts_Buff -= (cmst_buff[PL][cst_write[PL]].pts_digit[i] * xx);

            if (cmst_buff[PL][cst_write[PL]].first_digit < 0 && cmst_buff[PL][cst_write[PL]].pts_digit[i]) {
                cmst_buff[PL][cst_write[PL]].first_digit = i;
            }

            i--;
            assign2 = xx /= 10;
        }

        cmst_buff[PL][cst_write[PL]].move[1] = cmst_buff[PL][cst_write[PL]].first_digit + 6;

        if (cst_write[PL] == 4) {
            cst_write[PL] = 0;
        } else {
            cst_write[PL]++;
        }
    }
}

void combo_window_trans(s8 PL) {
    s8 PLS;

    if (cmb_stock[PL] != 0) {
        if (Mode_Type == 3 && Training_ID == PL) {
            cmb_stock[PL]--;
            return;
        }

        if (cmst_buff[PL][cst_read[PL]].pts_flag) {
            switch (cmst_buff[PL][cst_read[PL]].routine_num) {
            case 0:
                end_flag[PL] = 0;
                cmst_buff[PL][cst_read[PL]].move[0] = cmb_window_move_tbl[(cmst_buff[PL][cst_read[PL]].kind)];
                cmst_buff[PL][cst_read[PL]].x_posnum[0] = 0;
                cmst_buff[PL][cst_read[PL]].timer[0] = 8;
                cmst_buff[PL][cst_read[PL]].x_posnum[1] = 0;
                cmst_buff[PL][cst_read[PL]].routine_num++;
                break;

            case 1:
                if (cmst_buff[PL][cst_read[PL]].x_posnum[0] != 0) {
                    combo_message_set(PL,
                                      cmst_buff[PL][cst_read[PL]].kind,
                                      cmb_pos_tbl[PL][cmst_buff[PL][cst_read[PL]].x_posnum[0] - 1],
                                      cmst_buff[PL][cst_read[PL]].x_posnum[0],
                                      cmst_buff[PL][cst_read[PL]].hit_hi,
                                      cmst_buff[PL][cst_read[PL]].hit_low);
                }

                if (!(Game_pause & 0x80) && !(end_flag[PL] & 1)) {
                    if ((cmst_buff[PL][cst_read[PL]].x_posnum[0]) < (cmst_buff[PL][cst_read[PL]].move[0])) {
                        cmst_buff[PL][cst_read[PL]].x_posnum[0]++;
                    } else {
                        end_flag[PL] |= 1;
                    }
                }

                if (!(end_flag[PL] & 2)) {
                    if (!(Game_pause & 0x80)) {
                        cmst_buff[PL][cst_read[PL]].timer[0]--;
                    }

                    if (((cmst_buff[PL][cst_read[PL]].timer[0])) < 0) {
                        if ((cmst_buff[PL][cst_read[PL]].x_posnum[1]) < ((cmst_buff[PL][cst_read[PL]].move[1]) + 2)) {
                            if ((cmst_buff[PL][cst_read[PL]].x_posnum[1]) < (cmst_buff[PL][cst_read[PL]].move[1])) {
                                if (cmst_buff[PL][cst_read[PL]].x_posnum[1] != 0) {
                                    combo_pts_set(PL,
                                                  cmb_pos_tbl[PL][cmst_buff[PL][cst_read[PL]].x_posnum[1] - 1],
                                                  cmst_buff[PL][cst_read[PL]].x_posnum[1],
                                                  &cmst_buff[PL][cst_read[PL]].pts_digit[0],
                                                  cmst_buff[PL][cst_read[PL]].first_digit);
                                }
                            } else if (cmst_buff[PL][cst_read[PL]].x_posnum[1] != 0) {
                                combo_pts_set(PL,
                                              cmb_pos_tbl[PL][cmst_buff[PL][cst_read[PL]].x_posnum[1] - 1],
                                              (cmst_buff[PL][cst_read[PL]].move[1] - 1),
                                              &cmst_buff[PL][cst_read[PL]].pts_digit[0],
                                              cmst_buff[PL][cst_read[PL]].first_digit);
                            }

                            if (!(Game_pause & 0x80)) {
                                cmst_buff[PL][cst_read[PL]].x_posnum[1]++;
                            }
                        } else {
                            end_flag[PL] |= 2;
                            combo_pts_set(PL,
                                          cmb_pos_tbl[PL][cmst_buff[PL][cst_read[PL]].x_posnum[1] - 1],
                                          (cmst_buff[PL][cst_read[PL]].move[1] - 1),
                                          &cmst_buff[PL][cst_read[PL]].pts_digit[0],
                                          cmst_buff[PL][cst_read[PL]].first_digit);
                        }
                    }
                } else {
                    combo_pts_set(PL,
                                  cmb_pos_tbl[PL][cmst_buff[PL][cst_read[PL]].x_posnum[1] - 1],
                                  (cmst_buff[PL][cst_read[PL]].move[1] - 1),
                                  &cmst_buff[PL][cst_read[PL]].pts_digit[0],
                                  cmst_buff[PL][cst_read[PL]].first_digit);
                }

                if (!(Game_pause & 0x80) && ((end_flag[PL] & 3) == 3)) {
                    cmst_buff[PL][cst_read[PL]].routine_num++;
                    cmst_buff[PL][cst_read[PL]].timer[1] = cmb_window_time_tbl[(cmst_buff[PL][cst_read[PL]].kind)];

                    if (PL == 0) {
                        PLS = 1;
                    } else {
                        PLS = 0;
                    }

                    SCORE_PLUS(PLS, cmst_buff[PL][cst_read[PL]].pts);

                    if (Mode_Type == 1) {
                        Score_Sub();
                        return;
                    }

                    if (plw[PLS].wu.operator) {
                        Score_Sub();
                        return;
                    }
                }

                break;

            case 2:
                if (!(Game_pause & 0x80)) {
                    cmst_buff[PL][cst_read[PL]].timer[1]--;

                    if (cmst_buff[PL][cst_read[PL]].timer[1]) {
                        combo_message_set(PL,
                                          cmst_buff[PL][cst_read[PL]].kind,
                                          cmb_pos_tbl[PL][cmst_buff[PL][cst_read[PL]].x_posnum[0] - 1],
                                          cmst_buff[PL][cst_read[PL]].x_posnum[0],
                                          cmst_buff[PL][cst_read[PL]].hit_hi,
                                          cmst_buff[PL][cst_read[PL]].hit_low);
                        combo_pts_set(PL,
                                      cmb_pos_tbl[PL][cmst_buff[PL][cst_read[PL]].x_posnum[1] - 1],
                                      (cmst_buff[PL][cst_read[PL]].move[1] - 1),
                                      &cmst_buff[PL][cst_read[PL]].pts_digit[0],
                                      cmst_buff[PL][cst_read[PL]].first_digit);
                        return;
                    }
                } else {
                    combo_message_set(PL,
                                      cmst_buff[PL][cst_read[PL]].kind,
                                      cmb_pos_tbl[PL][cmst_buff[PL][cst_read[PL]].x_posnum[0] - 1],
                                      cmst_buff[PL][cst_read[PL]].x_posnum[0],
                                      cmst_buff[PL][cst_read[PL]].hit_hi,
                                      cmst_buff[PL][cst_read[PL]].hit_low);
                    combo_pts_set(PL,
                                  cmb_pos_tbl[PL][cmst_buff[PL][cst_read[PL]].x_posnum[1] - 1],
                                  (cmst_buff[PL][cst_read[PL]].move[1] - 1),
                                  &cmst_buff[PL][cst_read[PL]].pts_digit[0],
                                  cmst_buff[PL][cst_read[PL]].first_digit);
                    return;
                }

                if (cst_read[PL] == 4) {
                    cst_read[PL] = 0;
                } else {
                    cst_read[PL]++;
                }

                cmb_stock[PL]--;
                break;
            }
        } else {
            switch ((cmst_buff[PL][cst_read[PL]].routine_num)) {
            case 0:
                cmst_buff[PL][cst_read[PL]].move[0] = cmb_window_move_tbl[(cmst_buff[PL][cst_read[PL]].kind)];
                cmst_buff[PL][cst_read[PL]].x_posnum[0] = 1;
                cmst_buff[PL][cst_read[PL]].routine_num++;
                break;

            case 1:
                if (!(Game_pause & 0x80)) {
                    if ((cmst_buff[PL][cst_read[PL]].x_posnum[0]) < (cmst_buff[PL][cst_read[PL]].move[0])) {
                        cmst_buff[PL][cst_read[PL]].x_posnum[0]++;
                    } else {
                        cmst_buff[PL][cst_read[PL]].timer[1] = 36;
                        cmst_buff[PL][cst_read[PL]].routine_num++;
                    }
                }

                combo_message_set(PL,
                                  cmst_buff[PL][cst_read[PL]].kind,
                                  cmb_pos_tbl[PL][cmst_buff[PL][cst_read[PL]].x_posnum[0] - 1],
                                  cmst_buff[PL][cst_read[PL]].x_posnum[0],
                                  cmst_buff[PL][cst_read[PL]].hit_hi,
                                  cmst_buff[PL][cst_read[PL]].hit_low);
                break;

            case 2:
                if (!(Game_pause & 0x80)) {
                    cmst_buff[PL][cst_read[PL]].timer[1]--;

                    if (cmst_buff[PL][cst_read[PL]].timer[1]) {
                        combo_message_set(PL,
                                          cmst_buff[PL][cst_read[PL]].kind,
                                          cmb_pos_tbl[PL][cmst_buff[PL][cst_read[PL]].x_posnum[0] - 1],
                                          cmst_buff[PL][cst_read[PL]].x_posnum[0],
                                          cmst_buff[PL][cst_read[PL]].hit_hi,
                                          cmst_buff[PL][cst_read[PL]].hit_low);
                        return;
                    }
                } else {
                    combo_message_set(PL,
                                      cmst_buff[PL][cst_read[PL]].kind,
                                      cmb_pos_tbl[PL][cmst_buff[PL][cst_read[PL]].x_posnum[0] - 1],
                                      cmst_buff[PL][cst_read[PL]].x_posnum[0],
                                      cmst_buff[PL][cst_read[PL]].hit_hi,
                                      cmst_buff[PL][cst_read[PL]].hit_low);
                    return;
                }

                if (cmst_buff[PL][cst_read[PL]].pts_flag) {
                    cmst_buff[PL][cst_read[PL]].routine_num++;
                    return;
                }

                if (cst_read[PL] == 4) {
                    cst_read[PL] = 0;
                } else {
                    cst_read[PL]++;
                }

                cmb_stock[PL]--;
            }
        }
    }
}

void training_disp_data_set(s8 PL, s16 hnum) {
    if (tr_data[PL].max_hitcombo < (u8)hnum) {
        if (Disp_Attack_Data != 0) {
            if (Champion != PL) {
                SsRequest(0x9C);
            }

            tr_data[PL].new_max_flag = 0x14;
            tr_data[PL].frash_switch = 2;
        }

        tr_data[PL].frash_flag = 0;
        tr_data[PL].max_hitcombo = hnum;

        if (tr_data[PL].max_hitcombo > 99) {
            tr_data[PL].max_hitcombo = 99;
        }
    }
}

#if 0
/* PS2 C for functions not located in sf33rd.xbe yet. */

u32 SCORE_CALCULATION(s8 PL) {
    s16* c_ptr;
    s16* s_ptr;
    s16* k_ptr;
    s8 lpx;
    s8 lpy;
    s16 hit;
    s16 h;
    u32 score;
    s8 last;

    k_ptr = plw[PL].cb->kind_of[0][0];
    c_ptr = &calc_hit[PL][1];
    s_ptr = score_calc[PL];

    for (lpx = 0; lpx < 4; lpx++) {
        *s_ptr++ = k_ptr[0] + k_ptr[1];
        k_ptr += 2;
    }

    s_ptr = &score_calc[PL][4];

    for (lpy = 0; lpy < 8; lpy++) {
        *s_ptr++ = *c_ptr++;
    }

    hit = 0;
    score = 0;

    for (lpy = 0; lpy < 12; lpy++) {
        if (score_calc[PL][lpy]) {
            last = lpy;
            h = score_calc[PL][lpy];
            hit += h;
            score += *combo_score_tbl[lpy];

            if (h - 1) {
                score += (hit - 1) * combo_score_tbl[lpy][1];
            }
        }
    }

    if (bonus_pts[PL]) {
        score += bonus_pts[PL] * combo_score_tbl[last][1];
    }

    return score;
}
#endif
