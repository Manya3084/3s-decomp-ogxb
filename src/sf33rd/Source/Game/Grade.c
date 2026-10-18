/* Grade.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * grade_check_work_1st_init 0x5CD95 size 0x58. Read against the x86: -0x40 and
 * -0x20 are judge_final field offsets from a pointer into it. The C is the PS2
 * C.
 * grade_check_work_stage_init 0x5CDED size 0x83. Read against the x86: 0x4C is
 * the stride of judge_item[ix][Play_Type] (indexed as ix * 2 + Play_Type).
 * Matches the C. The +1 is the (ix + 1) index.
 * grade_check_work_round_init 0x5CE70 size 0x166. Read against the x86: 0x4C
 * is the stride of judge_item[ix][Play_Type] (indexed as ix * 2 + Play_Type).
 * push 0x60 / rep stosd is the C's 384-byte loop clearing ji_sat[ix]; ji_sat
 * is 0xC7F080 (ix * 0x180 added to it). Matches the C. Matches the C. Matches
 * the C. 0x60 is the dword count of the rep stos that clears a judge_gals row.
 * grade_final_grade_bonus 0x5D017 size 0x38. Read against the x86: 0x64 is the
 * * 100 of the bonus. The C is the PS2 C.
 * backup_RO_PT 0x5D131 size 0x1C.
 * grade_makeup_bonus_parameter 0x5D16B size 0x71.
 * get_offence_total 0x5D1DC size 0x150. Read against the x86: 0x4C is the
 * judge_item row stride, and 0x64 the C's * 100. Matches.
 * get_defence_total 0x5D32C size 0x186. Read against the x86: 0x4C is
 * sizeof(GradeData), the judge_item index step. 0x64 and 0xC8 are the 100 and
 * 200 of the percentage math. The C is the PS2 C.
 * get_tech_pts_total 0x5D4B2 size 0x1F6. Read against the x86: 0x4C is
 * sizeof(GradeData), the judge_item index step. The C is the PS2 C.
 * get_ex_point_total 0x5D6A8 size 0x125. Read against the x86: 0x4C is
 * sizeof(GradeData), the judge_item index step. The C is the PS2 C.
 * grade_add_clean_hits 0x5D7CD size 0x44. Read against the x86: 0x4C is
 * sizeof(GradeData), the judge_item index step. The C is the PS2 C.
 * grade_add_att_renew 0x5D811 size 0x44. Read against the x86: 0x4C is
 * sizeof(GradeData), the judge_item index step. The C is the PS2 C.
 * grade_add_guard_success 0x5D855 size 0x24. Read against the x86: 0x4C is
 * sizeof(GradeData), the judge_item index step. The C is the PS2 C.
 * grade_add_em_stun 0x5D879 size 0x2A. Read against the x86: 0x4C is the
 * stride of judge_item[ix][Play_Type] (indexed as ix * 2 + Play_Type). Matches
 * the C.
 * grade_add_leap_attack 0x5D8C9 size 0x2A. Read against the x86: 0x4C is the
 * stride of judge_item[ix][Play_Type] (indexed as ix * 2 + Play_Type). Matches
 * the C.
 * grade_add_grap_def 0x5D8F3 size 0x2A. Read against the x86: 0x4C is the
 * stride of judge_item[ix][Play_Type] (indexed as ix * 2 + Play_Type). Matches
 * the C.
 * grade_add_quick_stand 0x5D91D size 0x2A. Read against the x86: 0x4C is the
 * stride of judge_item[ix][Play_Type] (indexed as ix * 2 + Play_Type). Matches
 * the C.
 * grade_add_nml_nage 0x5D947 size 0x41. Read against the x86: 0x4C is
 * sizeof(GradeData), the judge_item index step. The C is the PS2 C.
 * grade_add_target_combo 0x5D9B2 size 0x2A. Read against the x86: 0x4C is the
 * judge_item row stride. Matches the C.
 * grade_add_command_waza 0x5D9DC size 0x2A. Read against the x86: 0x4C is
 * sizeof(GradeData), the judge_item index step. The C is the PS2 C.
 * grade_add_super_arts 0x5DA06 size 0x2F. Read against the x86: 0x4C is the
 * stride of judge_item[ix][Play_Type] (indexed as ix * 2 + Play_Type). Matches
 * the C.
 * grade_add_blocking 0x5DA5E size 0xA0. Read against the x86: 0x4C is the
 * stride of judge_item[ix][Play_Type] (indexed as ix * 2 + Play_Type). Matches
 * the C.
 * grade_add_personal_action 0x5DBA6 size 0x33. Read against the x86: 0x4C is
 * sizeof(GradeData), the judge_item index step. The C is the PS2 C.
 * grade_add_onaji_waza 0x5DC28 size 0x70. Read against the x86: 0x4C is
 * sizeof(GradeData), the judge_item index step. 0xF0 is a branchless choice
 * between two counts. The C is the PS2 C.
 * grade_get_my_grade 0x5DC98 size 0x1A. Read against the x86: 0x4C is
 * sizeof(GradeData), the judge_item index step. The C is the PS2 C.
 * grade_get_my_point_percentage 0x5DCB2 size 0x95. Read against the x86: 0x4C
 * is sizeof(GradeData), the judge_item index step. 0x64 and 0x1F4 are 100 and
 * 500 of the percentage math. The C is the PS2 C.
 * grade_get_cm_point_percentage 0x5DD47 size 0x71. Read against the x86: 0x64
 * and 0x1F4 are the C's * 100 / 500.
 * get_grade_ix 0x5DDB8 size 0x1C.
 * check_guard_miss 0x5DDD4 size 0xA5. Read against the x86: 0x4C is
 * sizeof(GradeData), the judge_item index step. The C is the PS2 C.
 * grade_makeup_round_parameter 0x5E040 size 0xCA. Read against the x86: 0x4C
 * is the stride of judge_item[ix][Play_Type] (indexed as ix * 2 + Play_Type).
 * Matches the C.
 * grade_makeup_round_para_dko 0x5E10A size 0x5C. Read against the x86: 0x4C is
 * the judge_item row stride and 0x98 the per-player step (two rows); the small
 * offsets are judge_item fields. Matches the C.
 * grade_makeup_judgement_gals 0x5E166 size 0x7B. Read against the x86: the
 * small offsets are judge_gals fields around offence_total. Matches the C.
 * grade_makeup_stage_parameter 0x5E2EA size 0x2E9. Read against the x86: 0x4C
 * is the judge_item row stride, and 0x56 and -1 are field and index
 * arithmetic. Matches the C.
 * Not located in sf33rd.xbe; their PS2 C is kept under #if 0:
 * grade_makeup_final_parameter, renew_judge_final_work, makeup_final_grade,
 * makeup_spp_frdat, rannyuu_Q_check, grade_makeup_stage_para_com,
 * grade_max_combo_check, grade_add_reversal, grade_store_vitality,
 * grade_get_first_attack, grade_set_round_result, grade_check_tairyokusa.
 * grade_makeup_final_parameter has no XBE name and no aligned call.
 * grade_makeup_stage_para_com has no XBE name and no aligned call.
 * old_my_char_check has no XBE name and no aligned call.
 * rannyuu_Q_check has no XBE name and no aligned call.
 * Data: judge_gals: defined elsewhere on Xbox.
 * Data: judge_com: defined elsewhere on Xbox.
 * Data: last_judge_dada: defined elsewhere on Xbox.
 * Data: judge_item: defined elsewhere on Xbox.
 * Data: judge_final 0xC7EDC0.
 * Data: ji_sat 0xC7F080.
 * Data: ji_grd_init_data is 0x25DFD0, 0x20 bytes compared.
 * Data: grade_t_meichuuritsu2 is 0x25DFF0, 0x60 bytes compared.
 * Data: grade_t_meichuuritsu3 is 0x25E050, 0x54 bytes compared.
 * Data: grade_t_em_stun is 0x25E0A4, 0x14 bytes compared.
 * Data: grade_t_max_combo is 0x25E0B8, 0x4C bytes compared.
 * Data: grade_t_bougyoritsu2 is 0x25E104, 0x38 bytes compared.
 * Data: grade_t_bougyoritsu3 is 0x25E13C, 0x34 bytes compared.
 * Data: grade_t_nokori_vital is 0x25E170, 0x34 bytes compared.
 * Data: grade_t_def_nmlblock is 0x25E1A4, 0x2C bytes compared.
 * Data: grade_t_def_rpdblock is 0x25E1D0, 0x2C bytes compared.
 * Data: grade_t_def_grdblock is 0x25E1FC, 0x24 bytes compared.
 * Data: grade_t_first_attack is 0x25E220, 0x4 bytes compared.
 * Data: grade_t_leap_attack is 0x25E224, 0x28 bytes compared.
 * Data: grade_t_target_combo is 0x25E24C, 0x20 bytes compared.
 * Data: grade_t_nml_nage is 0x25E26C, 0x28 bytes compared.
 * Data: grade_t_grap_def is 0x25E294, 0x18 bytes compared.
 * Data: grade_t_quick_stand is 0x25E2AC, 0x10 bytes compared.
 * Data: grade_t_personal_act is 0x25E2BC, 0x10 bytes compared.
 * Data: grade_t_reversal is 0x25E2CC, 0x20 bytes compared.
 * Data: grade_t_command_waza is 0x25E2EC, 0x24 bytes compared.
 * Data: grade_t_sa_stock_3 is 0x25E310, 0x18 bytes compared.
 * Data: grade_t_sa_stock_2 is 0x25E328, 0x18 bytes compared.
 * Data: grade_t_sa_stock_1 is 0x25E340, 0x18 bytes compared.
 * Data: grade_t_tairyokusa is 0x25E358, 0x54 bytes compared.
 * Data: grade_t_app_nmlblock is 0x25E3AC, 0x1C bytes compared.
 * Data: grade_t_app_rpdblock is 0x25E3C8, 0x1C bytes compared.
 * Data: grade_t_app_grdblock is 0x25E3E4, 0x1C bytes compared.
 * Data: grade_t_renshou is 0x25E400, 0x20 bytes compared.
 * Data: grade_t_em_renshou is 0x25E420, 0x20 bytes compared.
 * Data: grade_t_straight is 0x25E440, 0x2C bytes compared.
 * Data: grade_t_round_result is 0x25E46C, 0x8 bytes compared.
 * Data: grade_t_onaji_waza is 0x25E474, 0x18 bytes compared.
 * Data: grade_t_f_stage is 0x25E48C, 0x10 bytes compared.
 * Data: grade_t_f_all is 0x25E220, 0x4 bytes compared.
 * Data: grade_t_f_continue is 0x25E4A0, 0x2C bytes compared.
 * Data: grade_t_f_gradeup is 0x25E4CC, 0x2C bytes compared.
 * Data: grade_t_f_bss_car is 0x25E4F8, 0x10 bytes compared.
 * Data: grade_t_f_bss_ball is 0x25E508, 0x10 bytes compared.
 * Data: grade_t_table is 0x25E518, 0x80 bytes compared.
 * Unnamed data used (not checked): grade_get_cm_point_percentage:
 * 0xc7f4e6,0xc7f4e4,0xc7f4e2,0xc7f4e0; grade_final_grade_bonus: 0x7a892a;
 * grade_add_att_renew: 0xc7f38e; get_tech_pts_total:
 * 0xc7f39c,0xc7f39e,0xc7f3a0,0xc7f3a2,0xc7f3a4,0xc7f3a6,0xc7f3a8,0xc7f3aa;
 * grade_add_leap_attack: 0xc7f39e; grade_makeup_stage_parameter:
 * 0xc7f3c6,0xc7f380,0xc7f382,0xc7f384,0xc7f386,0xc7f3ca,0xc7f3c8,0xc7f3b4;
 * grade_add_target_combo: 0xc7f3a0; grade_add_guard_success: 0xc7f390;
 * grade_add_em_stun: 0xc7f388; get_offence_total:
 * 0xc7f38c,0xc7f398,0xc7f394,0xc7f396,0xc7f390,0xc7f38e,0xc7f3c2,0xc7f3c0;
 * grade_check_work_round_init:
 * 0xc7f388,0xc7f38a,0xc7f38c,0xc7f38e,0xc7f390,0xc7f392,0xc7f394,0xc7f396;
 * grade_makeup_judgement_gals: 0xc7f4c2; grade_add_super_arts: 0xc7f3ae;
 * get_defence_total:
 * 0xc7f38e,0xc7f38c,0xc7f390,0xc7f392,0xc7f394,0xc7f396,0xc7f398;
 * grade_add_grap_def: 0xc7f3a4; check_guard_miss: 0xc7f3c2,0xc7f3c0;
 * get_ex_point_total: 0xc7f3b0,0xc7f3b2,0xc7f3be,0xc7f3b8,0xc7f3ba,0xc7f3bc;
 * grade_get_my_grade: 0xc7f3c4; grade_get_my_point_percentage:
 * 0xc7f386,0xc7f384,0xc7f382,0xc7f380; grade_add_quick_stand: 0xc7f3a6;
 * grade_makeup_round_para_dko: 0xc7f382; grade_add_personal_action: 0xc7f3a8;
 * grade_add_command_waza: 0xc7f3ac; grade_makeup_round_parameter:
 * 0xc7f380,0xc7f382,0xc7f384,0xc7f386,0xc7f3c6,0xc7f3c8;
 * grade_check_work_1st_init: 0xc7f380; grade_add_blocking:
 * 0xc7f3bc,0xc7f398,0xc7f3ba,0xc7f396,0xc7f3b8,0xc7f394;
 * grade_check_work_stage_init:
 * 0xc7f380,0xc7f382,0xc7f384,0xc7f386,0xc7f3c6,0xc7f3c8,0xc7f3b4,0xc7f3b6;
 * grade_add_nml_nage: 0xc7f3a2; grade_add_clean_hits: 0xc7f38c;
 * grade_add_onaji_waza: 0xc7f3be.
 * Globals: ji_grd_init_data 0x25DFD0, grade_t_meichuuritsu2 0x25DFF0,
 * grade_t_meichuuritsu3 0x25E050, grade_t_em_stun 0x25E0A4, grade_t_max_combo
 * 0x25E0B8, grade_t_bougyoritsu2 0x25E104, grade_t_bougyoritsu3 0x25E13C,
 * grade_t_nokori_vital 0x25E170, grade_t_def_nmlblock 0x25E1A4,
 * grade_t_def_rpdblock 0x25E1D0, grade_t_def_grdblock 0x25E1FC,
 * grade_t_first_attack 0x25E220, grade_t_leap_attack 0x25E224,
 * grade_t_target_combo 0x25E24C, grade_t_nml_nage 0x25E26C, grade_t_grap_def
 * 0x25E294, grade_t_quick_stand 0x25E2AC, grade_t_personal_act 0x25E2BC,
 * grade_t_reversal 0x25E2CC, grade_t_command_waza 0x25E2EC, grade_t_sa_stock_3
 * 0x25E310, grade_t_sa_stock_2 0x25E328, grade_t_sa_stock_1 0x25E340,
 * grade_t_tairyokusa 0x25E358, grade_t_app_nmlblock 0x25E3AC,
 * grade_t_app_rpdblock 0x25E3C8, grade_t_app_grdblock 0x25E3E4,
 * grade_t_renshou 0x25E400, grade_t_em_renshou 0x25E420, grade_t_straight
 * 0x25E440, grade_t_round_result 0x25E46C, grade_t_onaji_waza 0x25E474,
 * grade_t_table 0x25E518, My_char 0x7A8114, Play_Type 0x7A812D, Win_Record
 * 0x7A8164, WGJ_Target 0x7A81C4, Mode_Type 0x7A825A, Straight_Counter
 * 0x7A82FA, Round_Operator 0x7A833C, Bonus_Game_ex_result 0x7A842A, Score
 * 0x7A8720, Bonus_Game_result 0x7A881A, WINNER 0x7A89BD, bg_w 0x7BC520, plw
 * 0xC7CEA0, pcon_dp_flag 0xC7D8D0, pcon_rno 0xC7E020, judge_final 0xC7EDC0,
 * ji_sat 0xC7F080.
 */

#include "structs.h"

void work_init_zero(s32* adrs_int, s32 xx);
extern u8 Play_Type;
extern u16 Win_Record[2];
extern s8 Round_Operator[2];
s32 Setup_Lv10(s16 xx);
extern u8 WGJ_Target;
extern u8 Final_Play_Type[2];
extern u32 Score[2][3];
s16 get_offence_total(s16 ix);
s16 get_defence_total(s16 ix, s16 wf);
s16 get_tech_pts_total(s16 ix);
s16 get_ex_point_total(s16 ix, s16 wf);
void backup_RO_PT();
extern u8 RO_backup[2];
extern u8 PT_backup;
s16 get_grade_ix(s16 pts);
extern u8 Mode_Type;
void grade_makeup_stage_para_com(s16 ix);
extern u8 Straight_Counter[2];
extern s8 WINNER;
extern BG bg_w;
s32 rannyuu_Q_check(s16 ix);
u8 old_my_char_check(u8 num, u8 flag);
extern u8 My_char[2];
void grade_makeup_final_parameter(s16 ix, s16 pt);
extern s16 Bonus_Game_result;
extern s16 Bonus_Game_ex_result;
s16 remake_2_10(s16 num, s16 keta);
extern PLW plw[2];
extern s16 pcon_rno[4];
s32 check_normal_attack(u8 waza);
extern u8 pcon_dp_flag;

extern JudgeGals judge_gals[2];

extern JudgeCom judge_com[2];

extern s16 last_judge_dada[2][5];

extern GradeData judge_item[2][2];

extern GradeFinalData judge_final[2][2];

extern u8 ji_sat[2][384];

const s16 ji_grd_init_data[16] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 1, 1, 1, 1, 1, 1 };

const s16 grade_t_meichuuritsu2[24][2] = {
    { 0, 35 },   { 6, 50 },   { 11, 65 },  { 16, 80 },  { 21, 95 },  { 26, 110 }, { 31, 125 }, { 36, 140 },
    { 41, 155 }, { 46, 170 }, { 51, 185 }, { 56, 200 }, { 61, 210 }, { 66, 220 }, { 71, 230 }, { 76, 240 },
    { 81, 250 }, { 86, 260 }, { 91, 270 }, { 93, 280 }, { 95, 300 }, { 97, 320 }, { 99, 340 }, { 100, 360 }
};

const s16 grade_t_meichuuritsu3[21][2] = { { 0, 2 },   { 5, 10 },  { 10, 18 }, { 15, 22 }, { 20, 26 }, { 25, 28 },
                                           { 30, 30 }, { 35, 31 }, { 40, 32 }, { 45, 33 }, { 50, 34 }, { 55, 36 },
                                           { 60, 38 }, { 65, 40 }, { 70, 42 }, { 75, 44 }, { 80, 48 }, { 85, 52 },
                                           { 90, 56 }, { 95, 60 }, { 100, 64 } };

const s16 grade_t_em_stun[5][2] = { { 0, 0 }, { 1, 100 }, { 2, 130 }, { 3, 145 }, { 4, 150 } };

const s16 grade_t_max_combo[19][2] = { { 0, 0 },    { 2, 10 },   { 3, 30 },   { 4, 60 },   { 5, 80 },
                                       { 6, 100 },  { 7, 110 },  { 8, 120 },  { 9, 130 },  { 10, 140 },
                                       { 12, 150 }, { 14, 160 }, { 16, 170 }, { 18, 175 }, { 19, 180 },
                                       { 20, 185 }, { 24, 190 }, { 28, 195 }, { 32, 200 } };

const s16 grade_t_bougyoritsu2[14][2] = { { 0, 10 },   { 10, 20 },  { 20, 40 },  { 30, 60 },  { 40, 80 },
                                          { 50, 100 }, { 60, 120 }, { 70, 140 }, { 80, 160 }, { 85, 180 },
                                          { 90, 200 }, { 95, 220 }, { 98, 230 }, { 100, 250 } };

const s16 grade_t_bougyoritsu3[13][2] = { { 0, 10 },   { 10, 20 },  { 20, 30 },  { 30, 40 }, { 40, 50 },
                                          { 50, 60 },  { 60, 70 },  { 70, 80 },  { 80, 90 }, { 85, 100 },
                                          { 90, 110 }, { 95, 130 }, { 100, 150 } };

const s16 grade_t_nokori_vital[13][2] = { { 0, 60 },   { 1, 0 },     { 16, 10 },  { 32, 20 },  { 48, 30 },
                                          { 64, 40 },  { 80, 50 },   { 96, 60 },  { 112, 70 }, { 128, 80 },
                                          { 144, 90 }, { 152, 120 }, { 160, 160 } };

const s16 grade_t_def_nmlblock[11][2] = { { 0, 0 },   { 1, 80 },  { 2, 90 },  { 3, 100 }, { 4, 110 }, { 5, 120 },
                                          { 6, 130 }, { 7, 135 }, { 8, 140 }, { 9, 145 }, { 10, 150 } };

const s16 grade_t_def_rpdblock[11][2] = { { 0, 0 },   { 1, 60 },  { 2, 70 },  { 3, 80 },  { 4, 90 },  { 5, 100 },
                                          { 6, 110 }, { 7, 120 }, { 8, 130 }, { 9, 140 }, { 10, 150 } };

const s16 grade_t_def_grdblock[9][2] = { { 0, 0 },   { 1, 100 }, { 2, 110 }, { 3, 120 }, { 4, 130 },
                                         { 5, 135 }, { 6, 140 }, { 7, 145 }, { 8, 150 } };

const s16 grade_t_first_attack[2] = { 0, 100 };

const s16 grade_t_leap_attack[10][2] = { { 0, 0 },  { 1, 50 }, { 2, 60 },  { 3, 65 },  { 4, 70 },
                                         { 8, 60 }, { 9, 40 }, { 10, 20 }, { 11, 10 }, { 12, 0 } };

const s16 grade_t_target_combo[8][2] = { { 0, 0 },  { 1, 40 },   { 2, 50 },   { 4, 60 },
                                         { 8, 80 }, { 12, 100 }, { 16, 120 }, { 24, 140 } };

const s16 grade_t_nml_nage[10][2] = { { 0, 0 },  { 1, 50 }, { 2, 60 }, { 3, 70 },  { 4, 75 },
                                      { 5, 80 }, { 6, 60 }, { 8, 40 }, { 10, 20 }, { 12, 0 } };

const s16 grade_t_grap_def[6][2] = { { 0, 0 }, { 1, 60 }, { 2, 80 }, { 4, 100 }, { 8, 120 }, { 16, 140 } };

const s16 grade_t_quick_stand[4][2] = { { 0, 0 }, { 1, 40 }, { 3, 50 }, { 6, 60 } };

const s16 grade_t_personal_act[4][2] = { { 0, 0 }, { 1, 50 }, { 2, 53 }, { 3, 55 } };

const s16 grade_t_reversal[8][2] = { { 0, 0 },  { 1, 50 }, { 2, 60 }, { 3, 70 },
                                     { 4, 80 }, { 6, 90 }, { 8, 95 }, { 10, 100 } };

const s16 grade_t_command_waza[9][2] = { { 0, 0 },   { 1, 30 },  { 3, 40 },  { 6, 50 },  { 10, 60 },
                                         { 15, 70 }, { 21, 80 }, { 28, 90 }, { 36, 100 } };

const s16 grade_t_sa_stock_3[6][2] = { { 0, 0 }, { 1, 50 }, { 2, 60 }, { 3, 70 }, { 4, 80 }, { 5, 90 } };

const s16 grade_t_sa_stock_2[6][2] = { { 0, 0 }, { 1, 55 }, { 2, 65 }, { 3, 75 }, { 4, 85 }, { 5, 95 } };

const s16 grade_t_sa_stock_1[6][2] = { { 0, 0 }, { 1, 60 }, { 2, 70 }, { 3, 80 }, { 4, 90 }, { 5, 100 } };

const s16 grade_t_tairyokusa[21][2] = { { 0, 0 },     { 9, 10 },    { 17, 20 },   { 25, 30 },   { 33, 40 },
                                        { 41, 50 },   { 49, 60 },   { 57, 80 },   { 65, 100 },  { 73, 120 },
                                        { 81, 140 },  { 89, 160 },  { 97, 180 },  { 105, 200 }, { 113, 220 },
                                        { 121, 240 }, { 129, 260 }, { 137, 270 }, { 145, 280 }, { 153, 290 },
                                        { 160, 300 } };

const s16 grade_t_app_nmlblock[7][2] = { { 0, 120 }, { 1, 110 }, { 9, 100 }, { 17, 80 },
                                         { 33, 50 }, { 49, 30 }, { 81, 15 } };

const s16 grade_t_app_rpdblock[7][2] = {
    { 0, 90 }, { 1, 80 }, { 9, 70 }, { 17, 50 }, { 33, 30 }, { 49, 20 }, { 81, 10 }
};

const s16 grade_t_app_grdblock[7][2] = { { 0, 150 }, { 1, 140 }, { 9, 120 }, { 17, 100 },
                                         { 33, 70 }, { 49, 40 }, { 81, 20 } };

const s16 grade_t_renshou[8][2] = { { 0, 0 },    { 2, 20 },   { 5, 50 },   { 8, 80 },
                                    { 11, 100 }, { 16, 120 }, { 21, 160 }, { 31, 200 } };

const s16 grade_t_em_renshou[8][2] = { { 0, 0 },   { 2, 20 },   { 4, 50 },   { 6, 80 },
                                       { 9, 100 }, { 12, 120 }, { 16, 160 }, { 20, 200 } };

const s16 grade_t_straight[11][2] = { { 0, 0 },   { 2, 40 },  { 3, 60 },  { 4, 80 },   { 5, 100 }, { 6, 120 },
                                      { 7, 140 }, { 8, 160 }, { 9, 180 }, { 10, 190 }, { 11, 200 } };

const s16 grade_t_round_result[4] = { 0, 50, 100, 160 };

const s16 grade_t_onaji_waza[6][2] = { { 0, 100 }, { 6, 70 }, { 12, 50 }, { 18, 30 }, { 24, 10 }, { 30, 0 } };

const s16 grade_t_f_stage[4][2] = { { 0, -40 }, { 4, -20 }, { 8, 0 }, { 10, 60 } };

const s16 grade_t_f_all[2] = { 0, 100 };

const s16 grade_t_f_continue[11][2] = { { 0, 100 },  { 1, -100 }, { 2, -150 }, { 3, -180 }, { 4, -200 }, { 5, -210 },
                                        { 6, -220 }, { 7, -230 }, { 8, -240 }, { 9, -250 }, { 10, -260 } };

const s16 grade_t_f_gradeup[11][2] = { { 0, 0 },   { 1, 40 },  { 2, 55 },  { 3, 70 },  { 4, 85 },  { 5, 100 },
                                       { 6, 120 }, { 7, 140 }, { 8, 160 }, { 9, 180 }, { 10, 200 } };

const s16 grade_t_f_bss_car[4][2] = { { 0, 0 }, { 1, 80 }, { 2, 40 }, { 3, 100 } };

const s16 grade_t_f_bss_ball[4][2] = { { 0, 0 }, { 1, 100 }, { 2, 80 }, { 3, 160 } };

const s16 grade_t_table[32][2] = { { 0, 20 },       { 75, 20 },     { 150, 20 },    { 225, 40 },    { 300, 40 },
                                   { 375, 40 },     { 450, 60 },    { 525, 60 },    { 600, 60 },    { 675, 80 },
                                   { 750, 80 },     { 825, 80 },    { 900, 100 },   { 975, 100 },   { 1050, 100 },
                                   { 1125, 150 },   { 1200, 200 },  { 1275, 300 },  { 1350, 400 },  { 1425, 600 },
                                   { 1500, 800 },   { 1550, 1000 }, { 1600, 1300 }, { 1650, 1600 }, { 1700, 2000 },
                                   { 1750, 3000 },  { 1800, 4000 }, { 1850, 5000 }, { 1900, 6000 }, { 1940, 8000 },
                                   { 1980, 10000 }, { 2020, 20000 } };

void grade_check_work_1st_init(s16 ix, s16 ix2) {
    s16 i;

    work_init_zero((s32*)&judge_item[ix][ix2], sizeof(GradeData));
    work_init_zero((s32*)&judge_final[ix][ix2], sizeof(GradeFinalData));

    for (i = 0; i < 16; i++) {
        judge_final[ix][ix2].vs_cpu_result[i] = -1;
        judge_final[ix][ix2].vs_cpu_player[i] = -1;
        judge_final[ix][ix2].vs_cpu_grade[i] = -1;
    }
}

void grade_check_work_stage_init(s16 ix) {
    judge_item[ix][Play_Type].offence_total = 0;
    judge_item[ix][Play_Type].defence_total = 0;
    judge_item[ix][Play_Type].tech_pts_total = 0;
    judge_item[ix][Play_Type].ex_point_total = 0;
    judge_item[ix][Play_Type].round = 0;
    judge_item[ix][Play_Type].win_round = 0;

    if (Play_Type == 1) {
        judge_item[ix][Play_Type].renshou = Win_Record[ix];
        judge_item[ix][Play_Type].em_renshou = Win_Record[(ix + 1) & 1];
        return;
    }

    judge_item[ix][Play_Type].renshou = 0;
    judge_item[ix][Play_Type].em_renshou = 0;
}

void grade_check_work_round_init(s16 ix) {
    s16 i;

    judge_item[ix][Play_Type].em_stun = 0;
    judge_item[ix][Play_Type].max_combo = 0;
    judge_item[ix][Play_Type].clean_hits = 0;
    judge_item[ix][Play_Type].att_renew = 0;
    judge_item[ix][Play_Type].guard_succ = 0;
    judge_item[ix][Play_Type].vitality = 0;
    judge_item[ix][Play_Type].nml_blocking = 0;
    judge_item[ix][Play_Type].rpd_blocking = 0;
    judge_item[ix][Play_Type].grd_blocking = 0;
    judge_item[ix][Play_Type].first_attack = 0;
    judge_item[ix][Play_Type].leap_attack = 0;
    judge_item[ix][Play_Type].target_combo = 0;
    judge_item[ix][Play_Type].nml_nage = 0;
    judge_item[ix][Play_Type].grap_def = 0;
    judge_item[ix][Play_Type].quick_stand = 0;
    judge_item[ix][Play_Type].personal_act = 0;
    judge_item[ix][Play_Type].reversal = 0;
    judge_item[ix][Play_Type].comwaza = 0;
    judge_item[ix][Play_Type].sa_exec = 0;
    judge_item[ix][Play_Type].tairyokusa = 0;
    judge_item[ix][Play_Type].kimarite = 0;
    judge_item[ix][Play_Type].app_nml_block = -1;
    judge_item[ix][Play_Type].app_rpd_block = -1;
    judge_item[ix][Play_Type].app_grd_block = -1;
    judge_item[ix][Play_Type].onaji_waza = 0;

    if (Round_Operator[ix] == 0) {
        judge_item[ix][Play_Type].grd_miss = ji_grd_init_data[Setup_Lv10(0)];
        judge_item[ix][Play_Type].grd_mcnt = ji_grd_init_data[Setup_Lv10(0)];
    } else {
        judge_item[ix][Play_Type].grd_miss = 0;
        judge_item[ix][Play_Type].grd_mcnt = 0;
    }

    for (i = 0; i < 384; i++) {
        ji_sat[ix][i] = 0;
    }

    judge_gals[ix].grade = 0;
    judge_gals[ix].offence_total = 0;
    judge_gals[ix].defence_total = 0;
    judge_gals[ix].tech_pts_total = 0;
    judge_gals[ix].ex_point_total = 0;

    for (i = 0; i < 5; i++) {
        last_judge_dada[0][i] = last_judge_dada[1][i] = 0;
    }
}

void grade_final_grade_bonus() {
    u32 bonus_point = grade_t_table[judge_final[WGJ_Target][Final_Play_Type[WGJ_Target]].grade][1];
    bonus_point *= 0x64;
    Score[WGJ_Target][Final_Play_Type[WGJ_Target]] += bonus_point;
}

void grade_makeup_round_parameter(s16 ix) {
    s16 ix2 = (ix + 1) & 1;

    judge_item[ix][Play_Type].offence_total += get_offence_total(ix);
    judge_item[ix2][Play_Type].offence_total += get_offence_total(ix2);
    judge_item[ix][Play_Type].defence_total += get_defence_total(ix, 1);
    judge_item[ix2][Play_Type].defence_total += get_defence_total(ix2, 0);
    judge_item[ix][Play_Type].tech_pts_total += get_tech_pts_total(ix);
    judge_item[ix2][Play_Type].tech_pts_total += get_tech_pts_total(ix2);
    judge_item[ix][Play_Type].ex_point_total += get_ex_point_total(ix, 1);
    judge_item[ix2][Play_Type].ex_point_total += get_ex_point_total(ix2, 0);
    judge_item[ix][Play_Type].round++;
    judge_item[ix2][Play_Type].round++;
    judge_item[ix][Play_Type].win_round++;

    backup_RO_PT();
}

void backup_RO_PT() {
    RO_backup[0] = Round_Operator[0];
    RO_backup[1] = Round_Operator[1];
    PT_backup = Play_Type;
}

void grade_makeup_round_para_dko() {
    s16 i;

    for (i = 0; i < 2; i++) {
        judge_item[i][Play_Type].offence_total += get_offence_total(i);
        judge_item[i][Play_Type].defence_total += get_defence_total(i, 0);
        judge_item[i][Play_Type].tech_pts_total += get_tech_pts_total(i);
        judge_item[i][Play_Type].ex_point_total += get_ex_point_total(i, 0);
        judge_item[i][Play_Type].round += 1;
    }

    backup_RO_PT();
}

void grade_makeup_judgement_gals() {
    s16 i;

    for (i = 0; i < 2; i++) {
        judge_gals[i].offence_total = get_offence_total(i);
        judge_gals[i].defence_total = get_defence_total(i, 0);
        judge_gals[i].tech_pts_total = get_tech_pts_total(i);
        judge_gals[i].ex_point_total = get_ex_point_total(i, 0);
        judge_gals[i].grade = get_grade_ix(judge_gals[i].offence_total + judge_gals[i].defence_total +
                                           judge_gals[i].tech_pts_total + judge_gals[i].ex_point_total);
    }
}

void grade_makeup_stage_parameter(s16 ix) {
    s16 i;
    s16 grade;
    s16 plnum;
    s16 point = 0;
    s16 bs;
    s16 qc;

    if ((Mode_Type != 5) && (Mode_Type != 1) && (Round_Operator[ix] == 0)) {
        grade_makeup_stage_para_com(ix);
        return;
    }

    qc = bs = 0;

    if (judge_item[ix][Play_Type].round == 0) {
        judge_item[ix][Play_Type].round = 1;
    }

    judge_item[ix][Play_Type].offence_total /= judge_item[ix][Play_Type].round;
    judge_item[ix][Play_Type].defence_total /= judge_item[ix][Play_Type].round;
    judge_item[ix][Play_Type].tech_pts_total /= judge_item[ix][Play_Type].round;
    judge_item[ix][Play_Type].ex_point_total /= judge_item[ix][Play_Type].round;
    judge_item[ix][Play_Type].no_lose = 0;

    if (judge_item[ix][Play_Type].round == judge_item[ix][Play_Type].win_round) {
        judge_item[ix][Play_Type].no_lose = Straight_Counter[ix];
    }

    if (ix == WINNER) {
        if (Play_Type == 0) {
            for (i = 0; i < 10; i++) {
                if (judge_item[ix][Play_Type].no_lose < grade_t_straight[i + 1][0]) {
                    break;
                }
            }

            judge_item[ix][Play_Type].ex_point_total += grade_t_straight[i][1];
        } else if (judge_item[ix][Play_Type].renshou) {
            for (i = 0; i < 7; i++) {
                if (judge_item[ix][Play_Type].renshou < grade_t_renshou[i + 1][0]) {
                    break;
                }
            }

            point += grade_t_renshou[i][1];
        } else {
            for (i = 0; i < 7; i++) {
                if (judge_item[ix][Play_Type].em_renshou < grade_t_em_renshou[i + 1][0]) {
                    break;
                }
            }

            point += grade_t_em_renshou[i][1];
        }
    }

    point = judge_item[ix][Play_Type].offence_total + judge_item[ix][Play_Type].defence_total +
            judge_item[ix][Play_Type].tech_pts_total + judge_item[ix][Play_Type].ex_point_total;
    grade = get_grade_ix(point);

    if (Play_Type == 0) {
        switch (bg_w.stage) {
        case 21:
        case 20:
            bs = 1;
            break;

        default:
            if ((qc = rannyuu_Q_check((ix + 1) & 1))) {
                judge_final[ix][Play_Type].vs_cpu_result[15] = point;
                judge_final[ix][Play_Type].vs_cpu_grade[15] = grade;
                judge_final[ix][Play_Type].vs_cpu_player[15] = judge_final[ix][Play_Type].vcr_ix;
            } else {
                plnum = old_my_char_check(My_char[(ix + 1) & 1], 0);
                judge_final[ix][Play_Type].vs_cpu_result[judge_final[ix][Play_Type].vcr_ix] = point;
                judge_final[ix][Play_Type].vs_cpu_grade[judge_final[ix][Play_Type].vcr_ix] = grade;
                judge_final[ix][Play_Type].vs_cpu_player[judge_final[ix][Play_Type].vcr_ix] = plnum;
                judge_final[ix][Play_Type].vcr_ix += 1;
            }

            judge_item[ix][Play_Type].grade = grade;
            break;
        }

        grade_makeup_final_parameter(ix, Play_Type + 0);

        if (ix == WINNER) {
            return;
        }

        if (bs != 0) {
            return;
        }

        if (qc) {
            judge_final[ix][Play_Type].vs_cpu_result[15] = -1;
            judge_final[ix][Play_Type].vs_cpu_grade[15] = -1;
            judge_final[ix][Play_Type].vs_cpu_player[15] = -1;
            return;
        } else {
            judge_final[ix][Play_Type].vcr_ix--;
        }
    } else {
        judge_item[ix][Play_Type].grade = grade;
    }
}

void grade_makeup_bonus_parameter(s16 ix) {
    if (Round_Operator[ix] != 0) {
        switch (bg_w.stage) {
        case 21:
            judge_final[ix][Play_Type].vs_cpu_grade[13] = (Bonus_Game_result == 20) + (Bonus_Game_ex_result == 20) * 2;
            break;

        case 20:
            judge_final[ix][Play_Type].vs_cpu_grade[14] = Bonus_Game_result;
            break;
        }
    }
}

s16 get_offence_total(s16 ix) {
    s32 num;
    s32 num2;
    s32 point;
    s32 point2;
    s16 i;
    s16 ix2;

    ix2 = (ix + 1) & 1;
    point = point2 = 0;
    num2 = judge_item[ix2][Play_Type].guard_succ + judge_item[ix2][Play_Type].nml_blocking +
           judge_item[ix2][Play_Type].rpd_blocking + judge_item[ix2][Play_Type].grd_blocking +
           judge_item[ix][Play_Type].clean_hits;

    if (num2 != 0) {
        num = (judge_item[ix][Play_Type].clean_hits * 100) / num2;
    } else {
        num = 0;
    }

    last_judge_dada[ix][0] = remake_2_10(num, 3);

    for (i = 0; i < 23; i++) {
        if (num < grade_t_meichuuritsu2[i + 1][0]) {
            break;
        }
    }

    point2 = grade_t_meichuuritsu2[i][1];

    if (judge_item[ix][Play_Type].att_renew) {
        num = (num2 * 100) / judge_item[ix][Play_Type].att_renew;
    } else {
        num = 0;
    }

    last_judge_dada[ix][1] = remake_2_10(num, 3);
    point2 = (point2 * num) / 100;

    if (judge_item[ix2][Play_Type].grd_mcnt) {
        num = (judge_item[ix2][Play_Type].grd_miss * 100) / judge_item[ix2][Play_Type].grd_mcnt;
    } else {
        num = 0;
    }

    last_judge_dada[ix][2] = remake_2_10(num, 3);

    for (i = 0; i < 20; i++) {
        if (num < grade_t_meichuuritsu3[i + 1][0]) {
            break;
        }
    }

    point2 *= grade_t_meichuuritsu3[i][1];
    point2 /= 32;

    point = point2;

    for (i = 0; i < 4; i++) {
        if (judge_item[ix][Play_Type].em_stun < grade_t_em_stun[i + 1][0]) {
            break;
        }
    }

    point += grade_t_em_stun[i][1];

    for (i = 0; i < 18; i++) {
        if (judge_item[ix][Play_Type].max_combo < grade_t_max_combo[i + 1][0]) {
            break;
        }
    }

    point += grade_t_max_combo[i][1];

    return point;
}

s16 get_defence_total(s16 ix, s16 wf) {
    s32 num = 0;
    s16 i;
    s16 ix2;
    s32 point;
    s32 point2;

    ix2 = (ix + 1) & 1;

    if (judge_item[ix2][Play_Type].att_renew) {
        point2 = ((judge_item[ix2][Play_Type].att_renew - judge_item[ix2][Play_Type].clean_hits) * 100) /
                 judge_item[ix2][Play_Type].att_renew;
    } else {
        point2 = 0;
    }

    last_judge_dada[ix][3] = remake_2_10(point2, 3);

    for (i = 0; i < 13; i++) {
        if (point2 < grade_t_bougyoritsu2[i + 1][0]) {
            break;
        }
    }

    num += grade_t_bougyoritsu2[i][1];
    point2 = judge_item[ix][Play_Type].clean_hits + judge_item[ix2][Play_Type].guard_succ;

    if (judge_item[ix][Play_Type].att_renew) {
        point2 = (point2 * 100) / judge_item[ix][Play_Type].att_renew;
    } else {
        point2 = 0;
    }

    last_judge_dada[ix][4] = remake_2_10(point2, 3);

    for (i = 0; i < 12; i++) {
        if (point2 < grade_t_bougyoritsu3[i + 1][0]) {
            break;
        }
    }

    point = grade_t_bougyoritsu3[i][1];

    if (judge_item[ix2][Play_Type].att_renew == 0) {
        point = (point * 200) / 100;
    }

    num += point;

    if (wf) {
        for (i = 0; i < 12; i++) {
            if (judge_item[ix][Play_Type].vitality < grade_t_nokori_vital[i + 1][0]) {
                break;
            }
        }

        num += grade_t_nokori_vital[i][1];
    }

    for (i = 0; i < 10; i++) {
        if (judge_item[ix][Play_Type].nml_blocking < grade_t_def_nmlblock[i + 1][0]) {
            break;
        }
    }

    num += grade_t_def_nmlblock[i][1];

    for (i = 0; i < 10; i++) {
        if (judge_item[ix][Play_Type].rpd_blocking < grade_t_def_rpdblock[i + 1][0]) {
            break;
        }
    }

    num += grade_t_def_rpdblock[i][1];

    for (i = 0; i < 8; i++) {
        if (judge_item[ix][Play_Type].grd_blocking < grade_t_def_grdblock[i + 1][0]) {
            break;
        }
    }

    num += grade_t_def_grdblock[i][1];

    return num;
}

s16 get_tech_pts_total(s16 ix) {
    s16 i;
    s16 point = 0;

    point += grade_t_first_attack[judge_item[ix][Play_Type].first_attack];

    for (i = 0; i < 9; i++) {
        if (judge_item[ix][Play_Type].leap_attack < grade_t_leap_attack[i + 1][0]) {
            break;
        }
    }

    point += grade_t_leap_attack[i][1];

    for (i = 0; i < 7; i++) {
        if (judge_item[ix][Play_Type].target_combo < grade_t_target_combo[i + 1][0]) {
            break;
        }
    }

    point += grade_t_target_combo[i][1];

    for (i = 0; i < 9; i++) {
        if (judge_item[ix][Play_Type].nml_nage < grade_t_nml_nage[i + 1][0]) {
            break;
        }
    }

    point += grade_t_nml_nage[i][1];

    for (i = 0; i < 5; i++) {
        if (judge_item[ix][Play_Type].grap_def < grade_t_grap_def[i + 1][0]) {
            break;
        }
    }

    point += grade_t_grap_def[i][1];

    for (i = 0; i < 3; i++) {
        if (judge_item[ix][Play_Type].quick_stand < grade_t_quick_stand[i + 1][0]) {
            break;
        }
    }

    point += grade_t_quick_stand[i][1];

    for (i = 0; i < 3; i++) {
        if (judge_item[ix][Play_Type].personal_act < grade_t_personal_act[i + 1][0]) {
            break;
        }
    }

    point += grade_t_personal_act[i][1];

    for (i = 0; i < 7; i++) {
        if (judge_item[ix][Play_Type].reversal < grade_t_reversal[i + 1][0]) {
            break;
        }
    }

    point += grade_t_reversal[i][1];

    for (i = 0; i < 8; i++) {
        if (judge_item[ix][Play_Type].comwaza < grade_t_command_waza[i + 1][0]) {
            break;
        }
    }

    point += grade_t_command_waza[i][1];

    switch (plw[ix].sa->store_max) {
    case 1:
        for (i = 0; i < 5; i++) {
            if (judge_item[ix][Play_Type].sa_exec < grade_t_sa_stock_1[i + 1][0]) {
                break;
            }
        }

        point += grade_t_sa_stock_1[i][1];
        break;

    case 2:
        for (i = 0; i < 5; i++) {
            if (judge_item[ix][Play_Type].sa_exec < grade_t_sa_stock_2[i + 1][0]) {
                break;
            }
        }

        point += grade_t_sa_stock_2[i][1];
        break;

    default:
        for (i = 0; i < 5; i++) {
            if (judge_item[ix][Play_Type].sa_exec < grade_t_sa_stock_3[i + 1][0]) {
                break;
            }
        }

        point += grade_t_sa_stock_3[i][1];
        break;
    }

    return point;
}

s16 get_ex_point_total(s16 ix, s16 wf) {
    s16 i;
    s16 point;

    point = 0;

    if (wf) {
        for (i = 0; i < 20; i++) {
            if (judge_item[ix][Play_Type].tairyokusa < grade_t_tairyokusa[i + 1][0]) {
                break;
            }
        }

        point += grade_t_tairyokusa[i][1];
        point += grade_t_round_result[judge_item[ix][Play_Type].kimarite];
    }

    for (i = 0; i < 5; i++) {
        if (judge_item[ix][Play_Type].onaji_waza < grade_t_onaji_waza[i + 1][0]) {
            break;
        }
    }

    point += grade_t_onaji_waza[i][1];

    if (judge_item[ix][Play_Type].app_nml_block != -1) {
        for (i = 0; i < 6; i++) {
            if (judge_item[ix][Play_Type].app_nml_block < grade_t_app_nmlblock[i + 1][0]) {
                break;
            }
        }

        point += grade_t_app_nmlblock[i][1];
    }

    if (judge_item[ix][Play_Type].app_rpd_block != -1) {
        for (i = 0; i < 6; i++) {
            if (judge_item[ix][Play_Type].app_rpd_block < grade_t_app_rpdblock[i + 1][0]) {
                break;
            }
        }

        point += grade_t_app_rpdblock[i][1];
    }

    if (judge_item[ix][Play_Type].app_grd_block != -1) {
        for (i = 0; i < 6; i++) {
            if (judge_item[ix][Play_Type].app_grd_block < grade_t_app_grdblock[i + 1][0]) {
                break;
            }
        }

        point += grade_t_app_grdblock[i][1];
    }

    return point;
}

void grade_add_clean_hits(WORK_Other* wk) {
    WORK* mwk;
    s16 ix;

    if (pcon_rno[0] != 0) {
        ix = wk->wu.id;

        if (wk->wu.work_id != 1) {
            mwk = (WORK*)(wk->my_master);

            if (mwk->work_id != 1) {
                return;
            }
            ix = mwk->id;
        }
        judge_item[ix][Play_Type].clean_hits += 1;
    }
}

void grade_add_att_renew(WORK_Other* wk) {
    WORK* mwk;
    s16 ix;

    if (pcon_rno[0] != 0) {
        ix = wk->wu.id;

        if (wk->wu.work_id != 1) {
            mwk = (WORK*)(wk->my_master);

            if (mwk->work_id != 1) {
                return;
            }
            ix = mwk->id;
        }
        judge_item[ix][Play_Type].att_renew += 1;
    }
}

void grade_add_guard_success(s16 ix) {
    if ((u16)ix < 2) {
        judge_item[ix][Play_Type].guard_succ++;
    }
}

void grade_add_em_stun(s16 ix) {
    judge_item[ix][Play_Type].em_stun++;

    if (judge_item[ix][Play_Type].em_stun > 4) {
        judge_item[ix][Play_Type].em_stun = 4;
    }
}

void grade_add_leap_attack(s16 ix) {
    judge_item[ix][Play_Type].leap_attack += 1;

    if (judge_item[ix][Play_Type].leap_attack > 12) {
        judge_item[ix][Play_Type].leap_attack = 12;
    }
}

void grade_add_grap_def(s16 ix) {
    judge_item[ix][Play_Type].grap_def += 1;

    if (judge_item[ix][Play_Type].grap_def > 16) {
        judge_item[ix][Play_Type].grap_def = 16;
    }
}

void grade_add_quick_stand(s16 ix) {
    judge_item[ix][Play_Type].quick_stand++;

    if (judge_item[ix][Play_Type].quick_stand > 6) {
        judge_item[ix][Play_Type].quick_stand = 6;
    }
}

void grade_add_nml_nage(WORK* wk) {
    s16 ix;

    if (check_normal_attack(wk->kind_of_waza)) {
        ix = wk->id;
        judge_item[ix][Play_Type].nml_nage += 1;
        if (judge_item[ix][Play_Type].nml_nage > 0xC) {
            judge_item[ix][Play_Type].nml_nage = 0xC;
        }
    }
}

void grade_add_target_combo(s16 ix) {
    judge_item[ix][Play_Type].target_combo++;

    if (judge_item[ix][Play_Type].target_combo > 24) {
        judge_item[ix][Play_Type].target_combo = 24;
    }
}

void grade_add_command_waza(s16 ix) {
    judge_item[ix][Play_Type].comwaza += 1;

    if (judge_item[ix][Play_Type].comwaza > 36) {
        judge_item[ix][Play_Type].comwaza = 36;
    }
}

void grade_add_super_arts(s16 ix, s16 num) {
    judge_item[ix][Play_Type].sa_exec += num;

    if (judge_item[ix][Play_Type].sa_exec > 5) {
        judge_item[ix][Play_Type].sa_exec = 5;
    }
}

void grade_add_blocking(PLW* wk) {
    s16 ix = wk->wu.id;

    switch (wk->kind_of_blocking) {
    case 0:
        judge_item[ix][Play_Type].app_nml_block = wk->wu.vital_new;

        if ((judge_item[ix][Play_Type].nml_blocking += 1) > 15) {
            judge_item[ix][Play_Type].nml_blocking = 15;
            break;
        }

        break;

    case 1:
        judge_item[ix][Play_Type].app_rpd_block = wk->wu.vital_new;

        if ((judge_item[ix][Play_Type].rpd_blocking += 1) > 15) {
            judge_item[ix][Play_Type].rpd_blocking = 15;
            return;
        }

        break;

    case 2:
        judge_item[ix][Play_Type].app_grd_block = wk->wu.vital_new;

        if ((judge_item[ix][Play_Type].grd_blocking += 1) > 15) {
            judge_item[ix][Play_Type].grd_blocking = 15;
        }

        break;
    }
}

void grade_add_personal_action(s16 ix) {
    if (!pcon_dp_flag) {
        judge_item[ix][Play_Type].personal_act++;

        if (judge_item[ix][Play_Type].personal_act > 3) {
            judge_item[ix][Play_Type].personal_act = 3;
        }
    }
}

void grade_add_onaji_waza(s16 ix) {
    s16 num;

    num = plw[ix].wu.char_index + ((plw[ix].wu.now_koc == 5) * 0xF0);
    if (num < 0x180) {
        if (ji_sat[ix][num] != 0xFF) {
            ji_sat[ix][num]++;
        }

        if (judge_item[ix][Play_Type].onaji_waza < ji_sat[ix][num]) {
            judge_item[ix][Play_Type].onaji_waza = ji_sat[ix][num];
        }
    }
}

s16 grade_get_my_grade(s16 ix) {
    return judge_item[ix][Play_Type].grade;
}

s16 grade_get_my_point_percentage(s16 ix, s16 flag) {
    s32 rnum;

    switch (flag) {
    case 0:
        rnum = judge_item[ix][Play_Type].offence_total * 100;
        rnum /= 500;
        break;

    case 1:
        rnum = judge_item[ix][Play_Type].defence_total * 100;
        rnum /= 500;
        break;

    case 2:
        rnum = judge_item[ix][Play_Type].tech_pts_total * 100;
        rnum /= 500;
        break;

    case 3:
        rnum = judge_item[ix][Play_Type].ex_point_total * 100;
        rnum /= 500;
        break;
    }

    if (rnum > 120) {
        rnum = 120;
    }

    return rnum;
}

s16 grade_get_cm_point_percentage(s16 ix, s16 flag) {
    s32 rnum;

    switch (flag) {
    case 0:
        rnum = judge_com[ix].offence_total * 100;
        rnum /= 500;
        break;

    case 1:
        rnum = judge_com[ix].defence_total * 100;
        rnum /= 500;
        break;

    case 2:
        rnum = judge_com[ix].tech_pts_total * 100;
        rnum /= 500;
        break;

    case 3:
        rnum = judge_com[ix].ex_point_total * 100;
        rnum /= 500;
        break;
    }

    if (rnum > 120) {
        rnum = 120;
    }

    return rnum;
}

s16 get_grade_ix(s16 pts) {
    s16 i;

    for (i = 0; i < 31; i++) {
        if (pts < grade_t_table[i + 1][0]) {
            break;
        }
    }

    return i;
}

void check_guard_miss(WORK* as, PLW* ds, s8 gddir) {
    if (ds->rp->total) {
        return;
    }

    judge_item[ds->wu.id][Play_Type].grd_mcnt++;

    if ((ds->guard_flag != 3) && (as->att.guard & 0x3F) && (ds->wu.xyz[1].disp.pos < 2) &&
        (as->work_id != 1 || !as->jump_att_flag || !(ds->cp->sw_new & 0xF)) && (!(ds->cp->sw_new & 1)) &&
        (!(ds->saishin_lvdir & gddir)) && ((ds->cp->waza_flag[3] + ds->cp->waza_flag[4]) == 0)) {
        return;
    }

    judge_item[ds->wu.id][Play_Type].grd_miss++;
}

#if 0
/* PS2 C for functions not located in sf33rd.xbe yet. */

void grade_makeup_final_parameter(s16 ix, s16 pt) {
#if defined(TARGET_PS2)
    void renew_judge_final_work(s32 ix, s32 pt);
    void makeup_spp_frdat(s32 ix, s32 pt);
    void makeup_final_grade(s32 ix, s32 pt);
#endif

    renew_judge_final_work(ix, pt);
    judge_final[ix][pt].all_clear = (VS_Index[WINNER] < 10) ^ 1;
    judge_final[ix][pt].keizoku = Continue_Coin[ix];
    makeup_spp_frdat(ix, pt);
    makeup_final_grade(ix, pt);
}

void renew_judge_final_work(s16 ix, s16 pt) {
    u32* frsd;
    s16 i;

    judge_final[ix][pt].all_clear = 0;
    judge_final[ix][pt].keizoku = 0;
    judge_final[ix][pt].sp_point = 0;
    judge_final[ix][pt].fr_ix = 0;
    frsd = (u32*)judge_final[ix][pt].fr_sort_data;

    for (i = 0; i < 16; i++) {
        *frsd++ = 0;
    }
}

void makeup_final_grade(s16 ix, s16 pt) {
#if defined(TARGET_PS2)
    s16 get_grade_ix(s32 pts);
#endif
    s16 i;
    s16 tt = 0;
    s16 dt;

    if ((dt = judge_final[ix][pt].vcr_ix) == 0) {
        dt = 1;
    }

    for (i = 0; i < judge_final[ix][pt].vcr_ix; i++) {
        tt += judge_final[ix][pt].vs_cpu_result[i];
    }

    if (judge_final[ix][pt].vs_cpu_result[15] != -1) {
        tt += judge_final[ix][pt].vs_cpu_result[15];
        dt += 1;
    }

    if (dt) {
        judge_final[ix][pt].vs_cpu_result[11] = tt / dt;
    } else {
        judge_final[ix][pt].vs_cpu_result[11] = 0;
    }

    judge_final[ix][pt].vs_cpu_grade[11] = get_grade_ix(judge_final[ix][pt].vs_cpu_result[11]);

    if (judge_final[ix][pt].vs_cpu_result[15] != -1) {
        tt /= 11;
    } else {
        tt /= 10;
    }

    for (i = 0; i < 3; i++) {
        if (judge_final[ix][pt].vcr_ix < grade_t_f_stage[i + 1][0]) {
            break;
        }
    }

    tt += grade_t_f_stage[i][1];

    if (judge_final[ix][pt].all_clear) {
        tt += grade_t_f_all[judge_final[ix][pt].all_clear];

        for (i = 0; i < 10; i++) {
            if (judge_final[ix][pt].keizoku < grade_t_f_continue[i + 1][0]) {
                break;
            }
        }

        tt += grade_t_f_continue[i][1];

        for (i = 0; i < 10; i++) {
            if (judge_final[ix][pt].sp_point < grade_t_f_gradeup[i + 1][0]) {
                break;
            }
        }

        tt += grade_t_f_gradeup[i][1];

        if (judge_final[ix][pt].vs_cpu_grade[13] != -1) {
            for (i = 0; i < 3; i++) {
                if (judge_final[ix][pt].vs_cpu_grade[13] < grade_t_f_bss_ball[i + 1][0]) {
                    break;
                }
            }

            tt += grade_t_f_bss_ball[i][1];
        }

        if (judge_final[ix][pt].vs_cpu_grade[14] != -1) {
            for (i = 0; i < 3; i++) {
                if (judge_final[ix][pt].vs_cpu_grade[14] < grade_t_f_bss_car[i + 1][0]) {
                    break;
                }
            }

            tt += grade_t_f_bss_car[i][1];
        }
    }

    if (tt < 0) {
        tt = 0;
    }

    judge_final[ix][pt].vs_cpu_result[12] = tt;
    judge_final[ix][pt].vs_cpu_grade[12] = judge_final[ix][pt].grade = get_grade_ix(tt);
}

void makeup_spp_frdat(s16 ix, s16 pt) {
    s16 i;
    s16 j;
    s16 k;
    u8* dmw;

    dmw = *judge_final[ix][pt].fr_sort_data;

    for (j = 0, i = 0; i < judge_final[ix][pt].vcr_ix; j++, i++) {
        if (i == judge_final[ix][pt].vs_cpu_player[0xF]) {
            *(dmw + (j * 4)) = 9;
            *(dmw + ((((j)) * 4) + 1)) = judge_final[ix][pt].vs_cpu_grade[0xF];
            *(dmw + ((((j)) * 4) + 2)) = 0x12;
            j++;
        }
        *(dmw + (((j)) * 4)) = i;
        *(dmw + ((((j)) * 4) + 1)) = judge_final[ix][pt].vs_cpu_grade[(i)];
        *(dmw + ((((j)) * 4) + 2)) = judge_final[ix][pt].vs_cpu_player[(i)];
    }

    judge_final[ix][pt].fr_ix = j;

    for (k = i; k < 0xA; j++, k++) {
        *(dmw + (((j)) * 4)) = k;
    }

    judge_final[ix][pt].sp_point = 0;

    for (i = 1; i < judge_final[ix][pt].fr_ix; i++) {
        if ((*(dmw + (((((i))) * 4) + 1))) > (*(dmw + ((((i)-1) * 4) + 1)))) {
            judge_final[ix][pt].sp_point += 1;
            *(dmw + ((((i)) * 4) + 3)) = 1;
        }
    }
}

s32 rannyuu_Q_check(s16 ix) {
    if ((Round_Operator[ix] == 0) && (My_char[ix] == 17)) {
        return 1;
    }

    return 0;
}

void grade_makeup_stage_para_com(s16 ix) {
#if defined(TARGET_PS2)
    s16 get_grade_ix(s32 pts);
#endif

    judge_com[ix].round = judge_item[ix][Play_Type].round;

    if (judge_com[ix].round == 0) {
        judge_com[ix].round = 1;
    }

    judge_com[ix].offence_total = judge_item[ix][Play_Type].offence_total / judge_com[ix].round;
    judge_com[ix].defence_total = judge_item[ix][Play_Type].defence_total / judge_com[ix].round;
    judge_com[ix].tech_pts_total = judge_item[ix][Play_Type].tech_pts_total / judge_com[ix].round;
    judge_com[ix].ex_point_total = judge_item[ix][Play_Type].ex_point_total / judge_com[ix].round;
    judge_com[ix].grade = get_grade_ix(judge_com[ix].offence_total + judge_com[ix].defence_total +
                                       judge_com[ix].tech_pts_total + judge_com[ix].ex_point_total);
}

void grade_max_combo_check(s16 ix, s16 num) {
    if (judge_item[ix][Play_Type].max_combo < num) {
        judge_item[ix][Play_Type].max_combo = num;
    }
}

void grade_add_reversal(s16 ix) {
    judge_item[ix][Play_Type].reversal += 1;

    if (judge_item[ix][Play_Type].reversal > 10) {
        judge_item[ix][Play_Type].reversal = 10;
    }
}

void grade_store_vitality(s16 ix) {
    judge_item[ix][Play_Type].vitality = plw[ix].wu.vital_new;
}

void grade_get_first_attack(s16 ix) {
    judge_item[ix][Play_Type].first_attack = 1;
}

void grade_set_round_result(s16 ix) {
    if (Round_Result & 0x8201) {
        judge_item[ix][Play_Type].kimarite = 0;
        return;
    }

    if (Round_Result & 0x2C) {
        judge_item[ix][Play_Type].kimarite = 1;
        return;
    }

    if (Round_Result & 0x50) {
        judge_item[ix][Play_Type].kimarite = 2;
        return;
    }

    if (Round_Result & 0x980) {
        judge_item[ix][Play_Type].kimarite = 3;
        return;
    }

    judge_item[ix][Play_Type].kimarite = 0;
}

void grade_check_tairyokusa() {
    s16 vwork = plw[1].wu.vital_new - plw[0].wu.vital_new;

    if (vwork > 0 && judge_item[0][Play_Type].tairyokusa < vwork) {
        judge_item[0][Play_Type].tairyokusa = vwork;
    }

    vwork = plw[0].wu.vital_new - plw[1].wu.vital_new;

    if (vwork > 0 && judge_item[1][Play_Type].tairyokusa < vwork) {
        judge_item[1][Play_Type].tairyokusa = vwork;
    }
}
#endif
