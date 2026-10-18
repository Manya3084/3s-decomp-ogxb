/* PLCNT.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * reqPlayerDraw 0x854AA size 0x21.
 * init_app_30000 0x854CB size 0x12B. FLAG: x86-only offsets 0x46c.
 * settle_type_30000 0x8563E size 0x96. FLAG: x86-only constants 0xff.
 * store_player_after_image_data 0x85860 size 0x9A. FLAG: x86-only constants
 * 0x300; x86-only offsets
 * -0x4c,-0x10,-0x2,0x4,0x6,0x8,0xa,0xb,0xc,0x1b9,0x1c4,0x1c6.
 * check_damage_hosei_nage 0x858FA size 0x9B. FLAG: x86-only constants 0x3aa.
 * check_damage_hosei_dageki 0x85995 size 0x30. FLAG: x86-only constants 0x3aa.
 * check_sa_type_rebirth 0x85A16 size 0x28. FLAG: x86-only constants 0xc0;
 * x86-only offsets 0x38f.
 * nekorobi_check 0x85A3E size 0x2C.
 * set_quake 0x85A8C size 0x36.
 * add_next_position 0x85AC2 size 0x2A.
 * erase_extra_plef_work 0x85B12 size 0x66.
 * set_player_shadow 0x85B78 size 0x2F.
 * setup_other_data 0x85BA7 size 0x32.
 * clear_chainex_check 0x85BD9 size 0x19.
 * set_kizetsu_status 0x85BF2 size 0x7B.
 * clear_kizetsu_point 0x85C6D size 0x43.
 * remake_sa_store_max 0x85CB0 size 0x2D.
 * remake_sa_gauge_len 0x85CDD size 0x32.
 * set_super_arts_status_dc 0x85D0F size 0xE2. FLAG: x86-only constants 0x2c.
 * clear_super_arts_point 0x85DF1 size 0x78.
 * check_combo_end 0x85E69 size 0x89.
 * set_scrrrl 0x85EF2 size 0x1E. FLAG: x86-only offsets 0xc0.
 * settle_type_00000 0x85F10 size 0x132.
 * settle_type_10000 0x86042 size 0x4E.
 * settle_type_20000 0x86090 size 0x10C.
 * settle_type_40000 0x8619C size 0x118.
 * move_player_work 0x862B4 size 0xC8. FLAG: PS2-only callees
 * move_P1_move_P2,move_P2_move_P1.
 * check_damage_hosei 0x8637C size 0xA0.
 * set_base_data 0x864C8 size 0x129. FLAG: x86-only constants 0xa8; x86-only
 * offsets -0x1,0x270.
 * set_base_data_metamorphose 0x865F1 size 0x4A.
 * set_super_arts_status 0x866CB size 0x10C. FLAG: x86-only constants 0x2c.
 * Player_control 0x867D7 size 0x12C.
 * plcnt_init 0x86903 size 0x23.
 * plcnt_die 0x86926 size 0x3C.
 * setup_base_and_other_data 0x86A7E size 0x103.
 * init_app_20000 0x86BFA size 0x74. FLAG: x86-only offsets 0x46c.
 * plcnt_move 0x86CA1 size 0x16B.
 * init_app_10000 0x86E0C size 0xD0. FLAG: PS2-only callees
 * pli_0000,pli_1000,pli_0002.
 * pli_0002 is folded into 0x4384A with 48 other bodies. Unnamed.
 * Not located in sf33rd.xbe; their PS2 C is kept under #if 0: pli_0000,
 * pli_1000, move_P1_move_P2, move_P2_move_P1, time_over_check, will_die,
 * setup_settle_rno, settle_check, check_sa_resurrection, footwork_check,
 * setup_gouki_wins, setup_any_data, set_base_data_tiny.
 * footwork_check has no XBE name and no aligned call.
 * grade_check_tairyokusa has no XBE name and no aligned call.
 * grade_set_round_result stays sub_0005DB1A, the one unnamed call left in its
 * caller.
 * grade_store_vitality has no XBE name and no aligned call.
 * move_P1_move_P2 has no XBE name and no aligned call.
 * move_P2_move_P1 has no XBE name and no aligned call.
 * pli_0000 has no XBE name and no aligned call.
 * pli_0002 is folded into 0x4384A.
 * pli_1000 has no XBE name and no aligned call.
 * settle_check has no XBE name and no aligned call.
 * setup_EJG_index stays sub_00047420, the one unnamed call left in its caller.
 * setup_any_data has no XBE name and no aligned call.
 * time_over_check has no XBE name and no aligned call.
 * Data: tsuujyou_dageki: not located in the XBE, PS2 initializer kept.
 * Data: hissatsu_dageki: not located in the XBE, PS2 initializer kept.
 * Data: tsuujyou_nage: not located in the XBE, PS2 initializer kept.
 * Data: hissatsu_nage: not located in the XBE, PS2 initializer kept.
 * Data: super_arts_dageki: not located in the XBE, PS2 initializer kept.
 * Data: super_arts_nage: not located in the XBE, PS2 initializer kept.
 * Data: kizetsu_timer_table: not located in the XBE, PS2 initializer kept.
 * Data: plw 0xC7CEA0.
 * Data: combo_type 0xC7D780.
 * Data: zanzou_table 0xC7D9E0.
 * Data: remake_power 0xC7E040.
 * Data: pcon_rno 0xC7E020.
 * Data: appear_type 0xC7D8E8.
 * Data: round_slow_flag 0xC7D8EA.
 * Data: pcon_dp_flag 0xC7D8D0.
 * Data: win_sp_flag 0xC7D8E0.
 * Data: dead_voice_flag 0xC7D9D4.
 * Data: super_arts 0xC7D940.
 * Data: piyori_type 0xC7D9A0.
 * Data: rambod: defined elsewhere on Xbox.
 * Data: ramhan: defined elsewhere on Xbox.
 * Data: omop_spmv_ng_table 0xC7D8D8.
 * Data: omop_spmv_ng_table2 0xC7D9C8.
 * Data: vital_inc_timer 0xC7D8D2.
 * Data: vital_dec_timer 0xC7D8EC.
 * Data: cmd_sel 0xC7D9D0.
 * Data: vib_sel 0xC7D9D2.
 * Data: sag_inc_timer 0xC7D8E4.
 * Data: no_sa 0xC7D9D6.
 * Data: player_main_process is 0x2618F8, 3 entries compared.
 * Data: appear_initalize is 0x261904, 4 entries compared.
 * Data: settle_process is 0x261914, 5 entries compared.
 * Data: plid_data is 0x261928, 0x14 bytes compared.
 * Data: weight_lv_table is 0x26193C, 0x14 bytes compared.
 * Data: quake_table is 0x261950, 0x80 bytes compared.
 * Data: kage_base is 0x2619D0, 0x50 bytes compared.
 * Data: super_arts_data is 0x261A20, 0x500 bytes compared, found by the bytes.
 * Data: super_arts_DATA is 0x261F20, 0x500 bytes compared.
 * Data: pl_piyo_tbl is 0x262420, 0x28 bytes compared.
 * Data: pl_nr_piyo_tbl is 0x262448, 0x50 bytes compared.
 * Data: tsuujyou_dageki_00: not located in the XBE, PS2 initializer kept.
 * Data: tsuujyou_dageki_01: not located in the XBE, PS2 initializer kept.
 * Data: tsuujyou_dageki_02: not located in the XBE, PS2 initializer kept.
 * Data: hissatsu_dageki_00: not located in the XBE, PS2 initializer kept.
 * Data: hissatsu_dageki_01: not located in the XBE, PS2 initializer kept.
 * Data: hissatsu_dageki_02: not located in the XBE, PS2 initializer kept.
 * Data: tsuujyou_nage_00: not located in the XBE, PS2 initializer kept.
 * Data: tsuujyou_nage_01: not located in the XBE, PS2 initializer kept.
 * Data: tsuujyou_nage_02: not located in the XBE, PS2 initializer kept.
 * Data: hissatsu_nage_00: not located in the XBE, PS2 initializer kept.
 * Data: hissatsu_nage_01: not located in the XBE, PS2 initializer kept.
 * Data: hissatsu_nage_02: not located in the XBE, PS2 initializer kept.
 * Data: super_arts_dageki_00: not located in the XBE, PS2 initializer kept.
 * Data: super_arts_dageki_01: not located in the XBE, PS2 initializer kept.
 * Data: super_arts_dageki_02: not located in the XBE, PS2 initializer kept.
 * Data: super_arts_nage_00: not located in the XBE, PS2 initializer kept.
 * Data: super_arts_nage_01: not located in the XBE, PS2 initializer kept.
 * Data: super_arts_nage_02: not located in the XBE, PS2 initializer kept.
 * Unnamed data used (not checked): remake_sa_store_max: 0x26849c.
 * Globals: player_main_process 0x2618F8, appear_initalize 0x261904,
 * settle_process 0x261914, plid_data 0x261928, weight_lv_table 0x26193C,
 * quake_table 0x261950, kage_base 0x2619D0, super_arts_data 0x261A20,
 * super_arts_DATA 0x261F20, pl_piyo_tbl 0x262420, pl_nr_piyo_tbl 0x262448,
 * stun_gauge_len_omake 0x268480, sag_length_omake 0x2684B4, No_Death 0x7A80CF,
 * ichikannkei 0x7A80D2, aiuchi_flag 0x7A80D3, Event_Judge_Gals 0x7A810E,
 * My_char 0x7A8114, Play_Type 0x7A812D, Operator_Status 0x7A816A, Round_Result
 * 0x7A81B4, scrl 0x7A81D0, players_timer 0x7A81F6, Mode_Type 0x7A825A,
 * paring_ctr_ori 0x7A8260, Timer_Freeze 0x7A82CC, Winner_id 0x7A8472, Loser_id
 * 0x7A875C, Break_Into 0x7A8802, Game_timer 0x7A8830, scrr 0x7A88F8,
 * paring_ctr_vs 0x7A8908, another_bg 0x7A8910, Game_pause 0x7A89B0, Super_Arts
 * 0x7A89FE, Complete_Judgement 0x7A8A02, poison_flag 0x7A8A48, mpp_w 0x7AA5C0,
 * bg_app 0x7BC4A8, bg_app_stop 0x7BC4E8, Training 0x7C5900,
 * omop_stun_gauge_len 0x7C5C48, omop_sag_max_ix 0x7C5C50, chainex_check
 * 0x7C5C80, omop_sag_len_ix 0x7C5CC8, EXE_flag 0xC7C834, pulpul_scene
 * 0xC7CDF0, plw 0xC7CEA0, combo_type 0xC7D780, pcon_dp_flag 0xC7D8D0,
 * vital_inc_timer 0xC7D8D2, omop_spmv_ng_table 0xC7D8D8, sag_inc_timer
 * 0xC7D8E4, appear_type 0xC7D8E8, round_slow_flag 0xC7D8EA, vital_dec_timer
 * 0xC7D8EC, super_arts 0xC7D940, piyori_type 0xC7D9A0, omop_spmv_ng_table2
 * 0xC7D9C8, cmd_sel 0xC7D9D0, dead_voice_flag 0xC7D9D4, no_sa 0xC7D9D6,
 * zanzou_table 0xC7D9E0, pcon_rno 0xC7E020, remake_power 0xC7E040.
 */

#include "structs.h"

typedef struct {
    
    u8 nmsa_g_ix;  
    u8 exsa_g_ix;  
    u8 exs2_g_ix;  
    u8 nmsa_a_ix;  
    u8 exsa_a_ix;  
    u8 exs2_a_ix;  
    u8 ex4th_full; 
    s8 gauge_type; 
    s16 gauge_len; 
    s16 store_max; 
    s32 dtm;       
} SA_DATA;

typedef struct  {
    
    s16 hand_dm[4][4]; 
} RAMHAN;

typedef struct  {
    
    s16 body_dm[4][4]; 
} RAMBOD;

void sub_00047420();
void sub_0005DB1A(s16 ix);
void sub_0004384A();
void plcnt_init();
void plcnt_move();
void plcnt_die();
void init_app_10000();
void init_app_20000();
void init_app_30000();
void settle_type_00000();
void settle_type_10000();
void settle_type_20000();
void settle_type_30000();
void settle_type_40000();
extern u8 pulpul_scene;
extern u8 Game_pause;
extern s16 EXE_flag;
extern u16 players_timer;
void set_scrrrl();
void check_body_touch();
void check_damage_hosei();
void set_quake(PLW* wk);
void hit_push_request(WORK* hpr_wk);
void add_next_position(PLW* wk);
void check_cg_zoom();
void store_player_after_image_data();
void move_effect_work(s16 index);
s32 sort_push_request(WORK* wk);
void move_player_work();
void pli_0000();
extern s8 another_bg[2];
extern u8 Play_Type;
extern MPP mpp_w;
extern u8 My_char[2];
void pli_1000();
extern u8 paring_ctr_vs[2][2];
extern u8 paring_ctr_ori[2];
void setup_any_data();
void K7_muriyari_metamor_rebirth(PLW* wk);
s32 effect_C9_init(PLW* , u8 data);
void load_any_color(u16 ix, u8 kokey);
s32 load_any_texture_patnum(u16 patnum, u8 kokey, u8 _unused);
void effect_work_kill(s16 index, s16 kill_id);
s32 effect_33_init(WORK* wk);
s32 time_over_check();
extern s8 Debug_w[72];
extern s8 No_Death;
extern s8 Break_Into;
extern u8 Mode_Type;
extern TrainingData Training[3];
extern s8 aiuchi_flag;
void subtract_dm_vital_aiuchi(PLW* wk);
void settle_check();
extern u16 Round_Result;
extern s8 gouki_wins;
s32 effect_D3_init(u8 ake_type);
extern s8 Winner_id;
extern s8 Loser_id;
void grade_store_vitality(s16 ix);
void grade_check_tairyokusa();
s16 nekorobi_check(s8 ix);
s16 footwork_check(s8 ix);
void complete_victory_pause();
extern s8 Event_Judge_Gals;
extern s8 Complete_Judgement;
void set_conclusion_slow();
extern s8 ichikannkei;
s16 check_work_position(WORK* p1, WORK* p2);
void set_rl_waza(PLW* wk);
extern s8 Timer_Freeze;
void move_P1_move_P2();
void move_P2_move_P1();
extern u16 Game_timer;
void check_damage_hosei_nage(PLW* as, PLW* ds);
void check_damage_hosei_dageki(PLW* w1, PLW* w2);
extern s8 bg_app_stop;
extern s8 bg_app;
s32 set_field_hosei_flag(PLW* pl, s16 pos, s16 ix);
extern s16 scrr;
extern s16 scrl;
void effect_work_list_init(s16 lix, s16 iid);
void make_texcash_work(s16 ix);
void set_base_data(PLW* wk, s16 ix);
void setup_other_data(PLW* wk);
s32 effect_J7_init(PLW* wk);
s32 effect_E5_init(PLW* wk);
extern s16 poison_flag[2];
s32 effect_E3_init(PLW* wk);
s32 effect_E4_init(PLW* wk);
extern s8 Operator_Status[2];
void set_char_base_data(WORK* wk);
void cmd_init(PLW* pl);
void set_player_shadow(PLW* wk);
void set_jugde_area(WORK* wk);
extern u8 Introduce_Boss[2][2];
s32 setup_GILL_exsa_obj();
s32 effect_01_init(WORK* wk, u8 koolc);
s32 effect_K5_init(PLW* wk);
s32 effect_00_init(WORK* wk);
extern u8 chainex_check[2][36];
extern const s16 stun_gauge_len_omake[5];
extern s16 omop_stun_gauge_len[2];
extern s8 Super_Arts[2];
s16 remake_sa_gauge_len(s16 ix, s16 gauge_len);
s16 remake_sa_store_max(s16 ix, s16 store_max);
extern const s16 sag_stock_omake[11];
extern s16 omop_sag_max_ix[2];
extern const s16 sag_length_omake[17];
extern s16 omop_sag_len_ix[2];
s16 get_center_position();

extern PLW plw[2];

extern ComboType combo_type[2];

extern ZanzouTableEntry zanzou_table[2][48];

extern ComboType remake_power[2];

extern s16 pcon_rno[4];

extern s16 appear_type;

extern u8 round_slow_flag;

extern u8 pcon_dp_flag;

extern u8 win_sp_flag;

extern char dead_voice_flag;

extern SA_WORK super_arts[2];

extern PiyoriType piyori_type[2];

extern RAMBOD rambod[2];

extern RAMHAN ramhan[2];

extern u32 omop_spmv_ng_table[2];

extern u32 omop_spmv_ng_table2[2];

extern u16 vital_inc_timer;

extern u16 vital_dec_timer;

extern char cmd_sel[2];

extern s8 vib_sel[2];

extern s16 sag_inc_timer[2];

extern char no_sa[2];

void (*const player_main_process[3])() = { plcnt_init, plcnt_move, plcnt_die };

void (*const appear_initalize[4])() = { init_app_10000, init_app_10000, init_app_20000, init_app_30000 };

void (*const settle_process[5])() = {
    settle_type_00000, settle_type_10000, settle_type_20000, settle_type_30000, settle_type_40000
};

const s8 plid_data[20] = { 6, 3, 5, 1, 2, 9, 7, 4, 10, 8, 12, 13, 14, 15, 16, 18, 19, 20, 21, 22 };

const s8 weight_lv_table[20] = { 2, 2, 1, 0, 1, 2, 3, 0, 1, 0, 0, 1, 1, 2, 1, 1, 1, 3, 2, 1 };

const s16 quake_table[64] = { 0, -1, 0, -1, 1, -1, 1, -1, 1, -1, 1, -1, 1, -2, 1, -2, 1, -2, 1, -2, 1, -2,
                              1, -2, 2, -2, 2, -2, 2, -2, 2, -2, 2, -2, 2, -2, 2, -2, 2, -2, 2, -3, 2, -3,
                              2, -3, 2, -3, 2, -3, 2, -3, 2, -3, 2, -3, 2, -3, 2, -3, 3, -3, 3, -3 };

const s16 kage_base[20][2] = { { 0, 21 },  { 0, 30 },  { 0, 21 },  { -4, 16 }, { 4, 21 }, { 6, 20 }, { -4, 26 },
                               { -4, 20 }, { 0, 25 },  { -3, 22 }, { -4, 16 }, { 0, 21 }, { 0, 21 }, { 0, 21 },
                               { 0, 21 },  { -8, 21 }, { 0, 23 },  { 0, 24 },  { 6, 25 }, { -6, 21 } };

const SA_DATA super_arts_data[20][4] = { { { 20, 24, 25, 0, 0, 0, 0, 3, 128, 1, 65536 },
                                           { 21, 24, 25, 0, 0, 0, 0, 3, 128, 1, 65536 },
                                           { 22, 24, 25, 0, 0, 0, 0, 3, 128, 1, 65536 },
                                           { 0, 0, 0, 0, 0, 0, 0, 0, 64, 1, 65536 } },
                                         { { 20, 0, 0, 0, 0, 0, 0, 0, 128, 1, 65536 },
                                           { 21, 0, 0, 0, 0, 0, 0, 0, 96, 2, 65536 },
                                           { 22, 0, 0, 0, 0, 0, 0, 0, 80, 1, 65536 },
                                           { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 65536 } },
                                         { { 20, 0, 0, 0, 0, 0, 0, 0, 112, 2, 65536 },
                                           { 22, 0, 0, 0, 0, 0, 0, 0, 128, 1, 65536 },
                                           { 21, 0, 0, 0, 0, 0, 0, 0, 96, 1, 65536 },
                                           { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 65536 } },
                                         { { 22, 0, 0, 0, 0, 0, 0, 0, 120, 1, 65536 },
                                           { 21, 0, 0, 0, 0, 0, 0, 0, 88, 3, 65536 },
                                           { 20, 0, 0, 0, 0, 0, 0, 1, 72, 1, 16384 },
                                           { 0, 0, 0, 0, 0, 0, 0, 0, 64, 1, 65536 } },
                                         { { 20, 0, 0, 0, 0, 0, 0, 0, 96, 2, 65536 },
                                           { 21, 0, 0, 0, 0, 0, 0, 0, 112, 1, 65536 },
                                           { 22, 0, 0, 0, 0, 0, 0, 0, 80, 3, 65536 },
                                           { 0, 0, 0, 0, 0, 0, 0, 0, 64, 1, 65536 } },
                                         { { 20, 0, 0, 0, 0, 0, 0, 0, 88, 1, 65536 },
                                           { 22, 0, 0, 0, 0, 0, 0, 0, 104, 1, 65536 },
                                           { 21, 0, 0, 0, 0, 0, 0, 0, 72, 2, 65536 },
                                           { 0, 0, 0, 0, 0, 0, 0, 0, 64, 1, 65536 } },
                                         { { 20, 0, 0, 0, 0, 0, 0, 0, 128, 1, 65536 },
                                           { 21, 0, 0, 0, 0, 0, 0, 0, 112, 2, 65536 },
                                           { 22, 0, 0, 0, 0, 0, 0, 0, 88, 2, 65536 },
                                           { 0, 0, 0, 0, 0, 0, 0, 0, 64, 1, 65536 } },
                                         { { 0, 0, 0, 38, 0, 0, 0, 0, 88, 3, 65536 },
                                           { 21, 0, 0, 0, 0, 0, 0, 0, 120, 1, 65536 },
                                           { 20, 0, 0, 0, 0, 0, 0, 0, 80, 1, 65536 },
                                           { 0, 0, 0, 0, 0, 0, 0, 0, 64, 1, 65536 } },
                                         { { 20, 0, 0, 0, 0, 0, 0, 0, 80, 3, 65536 },
                                           { 21, 0, 0, 0, 0, 0, 0, 0, 104, 2, 65536 },
                                           { 22, 0, 0, 0, 0, 0, 0, 0, 128, 1, 65536 },
                                           { 0, 0, 0, 0, 0, 0, 0, 0, 64, 1, 65536 } },
                                         { { 22, 0, 0, 0, 0, 0, 1, 1, 104, 1, 16384 },
                                           { 21, 24, 0, 0, 0, 0, 0, 0, 88, 3, 65536 },
                                           { 20, 0, 0, 0, 0, 0, 1, 1, 112, 1, 13107 },
                                           { 0, 0, 0, 0, 0, 0, 0, 0, 64, 0, 65536 } },
                                         { { 21, 0, 0, 0, 0, 0, 0, 0, 120, 1, 65536 },
                                           { 22, 0, 0, 0, 0, 0, 0, 0, 104, 2, 65536 },
                                           { 20, 0, 0, 0, 0, 0, 0, 1, 64, 1, 13107 },
                                           { 0, 0, 0, 0, 0, 0, 0, 0, 64, 1, 65536 } },
                                         { { 20, 0, 0, 0, 0, 0, 0, 0, 112, 2, 65536 },
                                           { 21, 0, 0, 0, 0, 0, 0, 0, 104, 1, 65536 },
                                           { 22, 0, 0, 0, 0, 0, 0, 0, 80, 3, 65536 },
                                           { 0, 0, 0, 0, 0, 0, 0, 0, 64, 1, 65536 } },
                                         { { 20, 0, 0, 0, 0, 0, 0, 0, 72, 3, 65536 },
                                           { 21, 0, 0, 0, 0, 0, 0, 0, 96, 2, 65536 },
                                           { 22, 0, 0, 0, 0, 0, 0, 0, 120, 1, 65536 },
                                           { 0, 0, 0, 0, 0, 0, 0, 0, 64, 1, 65536 } },
                                         { { 20, 0, 0, 0, 0, 0, 0, 0, 104, 2, 65536 },
                                           { 21, 0, 0, 0, 0, 0, 0, 0, 80, 2, 65536 },
                                           { 22, 0, 0, 0, 0, 0, 0, 0, 88, 2, 65536 },
                                           { 0, 0, 0, 0, 0, 0, 0, 0, 64, 1, 65536 } },
                                         { { 20, 24, 25, 38, 0, 0, 0, 0, 112, 2, 65536 },
                                           { 21, 24, 25, 0, 0, 0, 0, 0, 112, 2, 65536 },
                                           { 22, 24, 25, 39, 0, 0, 0, 0, 112, 2, 65536 },
                                           { 0, 0, 0, 0, 0, 0, 0, 0, 64, 1, 65536 } },
                                         { { 20, 0, 0, 0, 0, 0, 0, 0, 88, 1, 65536 },
                                           { 21, 0, 0, 0, 0, 0, 0, 0, 104, 2, 65536 },
                                           { 22, 0, 0, 0, 0, 0, 0, 0, 72, 3, 65536 },
                                           { 0, 0, 0, 0, 0, 0, 0, 0, 64, 1, 65536 } },
                                         { { 22, 0, 0, 0, 0, 0, 0, 0, 120, 1, 65536 },
                                           { 20, 0, 0, 0, 0, 0, 0, 0, 88, 2, 65536 },
                                           { 21, 0, 0, 0, 0, 0, 0, 1, 96, 1, 10922 },
                                           { 0, 0, 0, 0, 0, 0, 0, 0, 64, 1, 65536 } },
                                         { { 20, 0, 0, 0, 0, 0, 0, 0, 96, 2, 65536 },
                                           { 21, 0, 0, 0, 0, 0, 0, 0, 120, 1, 65536 },
                                           { 22, 0, 0, 0, 0, 0, 0, 1, 112, 1, 10922 },
                                           { 0, 0, 0, 0, 0, 0, 0, 0, 64, 1, 65536 } },
                                         { { 20, 0, 0, 0, 0, 0, 0, 0, 96, 2, 65536 },
                                           { 0, 0, 0, 38, 0, 0, 0, 0, 112, 1, 65536 },
                                           { 21, 0, 0, 0, 0, 0, 0, 1, 128, 1, 6553 },
                                           { 0, 0, 0, 0, 0, 0, 0, 0, 64, 1, 65536 } },
                                         { { 20, 0, 0, 0, 0, 0, 0, 0, 104, 2, 65536 },
                                           { 22, 0, 0, 0, 0, 0, 0, 0, 120, 2, 65536 },
                                           { 21, 0, 0, 0, 0, 0, 0, 0, 80, 1, 65536 },
                                           { 0, 0, 0, 0, 0, 0, 0, 0, 64, 1, 65536 } } };

const SA_DATA super_arts_DATA[20][4] = { { { 20, 24, 25, 0, 0, 0, 0, 3, 120, 2, 65536 },
                                           { 21, 24, 25, 0, 0, 0, 0, 3, 120, 2, 65536 },
                                           { 22, 24, 25, 0, 0, 0, 0, 3, 120, 2, 65536 },
                                           { 0, 0, 0, 0, 0, 0, 0, 0, 64, 1, 65536 } },
                                         { { 20, 0, 0, 0, 0, 0, 0, 0, 120, 2, 65536 },
                                           { 21, 0, 0, 0, 0, 0, 0, 0, 120, 2, 65536 },
                                           { 22, 0, 0, 0, 0, 0, 0, 0, 120, 2, 65536 },
                                           { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 65536 } },
                                         { { 20, 0, 0, 0, 0, 0, 0, 0, 120, 2, 65536 },
                                           { 22, 0, 0, 0, 0, 0, 0, 0, 120, 2, 65536 },
                                           { 21, 0, 0, 0, 0, 0, 0, 0, 120, 2, 65536 },
                                           { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 65536 } },
                                         { { 22, 0, 0, 0, 0, 0, 0, 0, 120, 2, 65536 },
                                           { 21, 0, 0, 0, 0, 0, 0, 0, 120, 2, 65536 },
                                           { 20, 0, 0, 0, 0, 0, 0, 1, 120, 2, 16384 },
                                           { 0, 0, 0, 0, 0, 0, 0, 0, 64, 1, 65536 } },
                                         { { 20, 0, 0, 0, 0, 0, 0, 0, 120, 2, 65536 },
                                           { 21, 0, 0, 0, 0, 0, 0, 0, 120, 2, 65536 },
                                           { 22, 0, 0, 0, 0, 0, 0, 0, 120, 2, 65536 },
                                           { 0, 0, 0, 0, 0, 0, 0, 0, 64, 1, 65536 } },
                                         { { 20, 0, 0, 0, 0, 0, 0, 0, 120, 2, 65536 },
                                           { 22, 0, 0, 0, 0, 0, 0, 0, 120, 2, 65536 },
                                           { 21, 0, 0, 0, 0, 0, 0, 0, 120, 2, 65536 },
                                           { 0, 0, 0, 0, 0, 0, 0, 0, 64, 1, 65536 } },
                                         { { 20, 0, 0, 0, 0, 0, 0, 0, 120, 2, 65536 },
                                           { 21, 0, 0, 0, 0, 0, 0, 0, 120, 2, 65536 },
                                           { 22, 0, 0, 0, 0, 0, 0, 0, 120, 2, 65536 },
                                           { 0, 0, 0, 0, 0, 0, 0, 0, 64, 1, 65536 } },
                                         { { 0, 0, 0, 38, 0, 0, 0, 0, 120, 2, 65536 },
                                           { 21, 0, 0, 0, 0, 0, 0, 0, 120, 2, 65536 },
                                           { 20, 0, 0, 0, 0, 0, 0, 0, 120, 2, 65536 },
                                           { 0, 0, 0, 0, 0, 0, 0, 0, 64, 1, 65536 } },
                                         { { 20, 0, 0, 0, 0, 0, 0, 0, 120, 2, 65536 },
                                           { 21, 0, 0, 0, 0, 0, 0, 0, 120, 2, 65536 },
                                           { 22, 0, 0, 0, 0, 0, 0, 0, 120, 2, 65536 },
                                           { 0, 0, 0, 0, 0, 0, 0, 0, 64, 1, 65536 } },
                                         { { 22, 24, 0, 0, 0, 0, 1, 1, 120, 2, 16384 },
                                           { 21, 24, 0, 0, 0, 0, 0, 0, 120, 2, 65536 },
                                           { 20, 24, 0, 0, 0, 0, 1, 1, 120, 2, 13107 },
                                           { 0, 0, 0, 0, 0, 0, 0, 0, 64, 0, 65536 } },
                                         { { 21, 0, 0, 0, 0, 0, 0, 0, 120, 2, 65536 },
                                           { 22, 0, 0, 0, 0, 0, 0, 0, 120, 2, 65536 },
                                           { 20, 0, 0, 0, 0, 0, 0, 1, 120, 2, 13107 },
                                           { 0, 0, 0, 0, 0, 0, 0, 0, 64, 1, 65536 } },
                                         { { 20, 0, 0, 0, 0, 0, 0, 0, 120, 2, 65536 },
                                           { 21, 0, 0, 0, 0, 0, 0, 0, 120, 2, 65536 },
                                           { 22, 0, 0, 0, 0, 0, 0, 0, 120, 2, 65536 },
                                           { 0, 0, 0, 0, 0, 0, 0, 0, 64, 1, 65536 } },
                                         { { 20, 0, 0, 0, 0, 0, 0, 0, 120, 2, 65536 },
                                           { 21, 0, 0, 0, 0, 0, 0, 0, 120, 2, 65536 },
                                           { 22, 0, 0, 0, 0, 0, 0, 0, 120, 2, 65536 },
                                           { 0, 0, 0, 0, 0, 0, 0, 0, 64, 1, 65536 } },
                                         { { 20, 0, 0, 0, 0, 0, 0, 0, 120, 2, 65536 },
                                           { 21, 0, 0, 0, 0, 0, 0, 0, 120, 2, 65536 },
                                           { 22, 0, 0, 0, 0, 0, 0, 0, 120, 2, 65536 },
                                           { 0, 0, 0, 0, 0, 0, 0, 3, 64, 1, 65536 } },
                                         { { 20, 24, 25, 38, 0, 0, 0, 0, 120, 2, 65536 },
                                           { 21, 24, 25, 0, 0, 0, 0, 0, 120, 2, 65536 },
                                           { 22, 24, 25, 39, 0, 0, 0, 0, 120, 2, 65536 },
                                           { 0, 0, 0, 0, 0, 0, 0, 3, 64, 1, 65536 } },
                                         { { 20, 0, 0, 0, 0, 0, 0, 0, 120, 2, 65536 },
                                           { 21, 0, 0, 0, 0, 0, 0, 0, 120, 2, 65536 },
                                           { 22, 0, 0, 0, 0, 0, 0, 0, 120, 2, 65536 },
                                           { 0, 0, 0, 0, 0, 0, 0, 0, 64, 1, 65536 } },
                                         { { 22, 0, 0, 0, 0, 0, 0, 0, 120, 2, 65536 },
                                           { 20, 0, 0, 0, 0, 0, 0, 0, 120, 2, 65536 },
                                           { 21, 0, 0, 0, 0, 0, 0, 1, 120, 2, 10922 },
                                           { 0, 0, 0, 0, 0, 0, 0, 0, 64, 1, 65536 } },
                                         { { 20, 0, 0, 0, 0, 0, 0, 0, 120, 2, 65536 },
                                           { 21, 0, 0, 0, 0, 0, 0, 0, 120, 2, 65536 },
                                           { 22, 0, 0, 0, 0, 0, 0, 1, 120, 2, 10922 },
                                           { 0, 0, 0, 0, 0, 0, 0, 0, 64, 1, 65536 } },
                                         { { 20, 0, 0, 0, 0, 0, 0, 0, 120, 2, 65536 },
                                           { 0, 0, 0, 38, 0, 0, 0, 0, 120, 2, 65536 },
                                           { 21, 0, 0, 0, 0, 0, 0, 1, 120, 2, 6553 },
                                           { 0, 0, 0, 0, 0, 0, 0, 0, 64, 1, 65536 } },
                                         { { 20, 0, 0, 0, 0, 0, 0, 0, 120, 2, 65536 },
                                           { 22, 0, 0, 0, 0, 0, 0, 0, 120, 2, 65536 },
                                           { 21, 0, 0, 0, 0, 0, 0, 0, 120, 2, 65536 },
                                           { 0, 0, 0, 0, 0, 0, 0, 0, 64, 1, 65536 } } };

const s16 pl_piyo_tbl[20] = { 72, 72, 64, 64, 72, 64, 72, 64, 64, 72, 64, 64, 64, 64, 56, 64, 64, 72, 64, 56 };

const s32 pl_nr_piyo_tbl[20] = { 3276, 2849, 2978, 2730, 2978, 2849, 3120, 2730, 2978, 2730,
                                 2730, 2978, 2849, 3120, 2849, 2978, 3276, 2978, 2849, 3120 };

const s16 tsuujyou_dageki_00[16] = { 150, 150, 130, 130, 130, 110, 110, 110, 110, 110, 90, 90, 90, 90, 90, 90 };

const s16 tsuujyou_dageki_01[16] = { 150, 150, 150, 150, 130, 130, 130, 130, 110, 110, 110, 110, 90, 90, 90, 90 };

const s16 tsuujyou_dageki_02[16] = { 150, 150, 150, 150, 150, 150, 130, 130, 130, 130, 130, 110, 110, 110, 90, 90 };

const s16* tsuujyou_dageki[4] = { tsuujyou_dageki_00, tsuujyou_dageki_01, tsuujyou_dageki_02, tsuujyou_dageki_02 };

const s16 hissatsu_dageki_00[16] = { 210, 210, 190, 190, 190, 170, 170, 170, 170, 170, 150, 150, 150, 150, 150, 150 };

const s16 hissatsu_dageki_01[16] = { 210, 210, 210, 210, 190, 190, 190, 190, 170, 170, 170, 170, 150, 150, 150, 150 };

const s16 hissatsu_dageki_02[16] = { 210, 210, 210, 210, 210, 210, 190, 190, 190, 190, 190, 170, 170, 170, 150, 150 };

const s16* hissatsu_dageki[4] = {
    hissatsu_dageki_00,
    hissatsu_dageki_01,
    hissatsu_dageki_02,
    hissatsu_dageki_02,
};

const s16 tsuujyou_nage_00[16] = { 180, 180, 160, 160, 160, 140, 140, 140, 140, 140, 120, 120, 120, 120, 120, 120 };

const s16 tsuujyou_nage_01[16] = { 180, 180, 180, 180, 160, 160, 160, 160, 140, 140, 140, 140, 120, 120, 120, 120 };

const s16 tsuujyou_nage_02[16] = { 180, 180, 180, 180, 180, 180, 160, 160, 160, 160, 160, 140, 140, 140, 120, 120 };

const s16* tsuujyou_nage[4] = { tsuujyou_nage_00, tsuujyou_nage_01, tsuujyou_nage_02, tsuujyou_nage_02 };

const s16 hissatsu_nage_00[16] = { 240, 240, 200, 200, 200, 160, 160, 160, 160, 160, 120, 120, 120, 120, 120, 120 };

const s16 hissatsu_nage_01[16] = { 240, 240, 240, 240, 200, 200, 200, 200, 160, 160, 160, 160, 120, 120, 120, 120 };

const s16 hissatsu_nage_02[16] = { 240, 240, 240, 240, 240, 240, 200, 200, 200, 200, 200, 160, 160, 160, 120, 120 };

const s16* hissatsu_nage[4] = { hissatsu_nage_00, hissatsu_nage_01, hissatsu_nage_02, hissatsu_nage_02 };

const s16 super_arts_dageki_00[16] = { 240, 240, 200, 200, 200, 160, 160, 160, 160, 160, 120, 120, 120, 120, 120, 120 };

const s16 super_arts_dageki_01[16] = { 240, 240, 240, 240, 200, 200, 200, 200, 160, 160, 160, 160, 120, 120, 120, 120 };

const s16 super_arts_dageki_02[16] = { 240, 240, 240, 240, 240, 240, 200, 200, 200, 200, 200, 160, 160, 160, 120, 120 };

const s16* super_arts_dageki[4] = {
    super_arts_dageki_00, super_arts_dageki_01, super_arts_dageki_02, super_arts_dageki_02
};

const s16 super_arts_nage_00[16] = { 270, 270, 230, 230, 230, 190, 190, 190, 190, 190, 150, 150, 150, 150, 150, 150 };

const s16 super_arts_nage_01[16] = { 270, 270, 270, 270, 230, 230, 230, 230, 190, 190, 190, 190, 150, 150, 150, 150 };

const s16 super_arts_nage_02[16] = { 270, 270, 270, 270, 270, 270, 230, 230, 230, 230, 230, 190, 190, 190, 150, 150 };

const s16* super_arts_nage[4] = { super_arts_nage_00, super_arts_nage_01, super_arts_nage_02, super_arts_nage_02 };

const s16** kizetsu_timer_table[9] = { tsuujyou_dageki,   hissatsu_dageki,   tsuujyou_nage,
                                       hissatsu_nage,     super_arts_dageki, super_arts_nage,
                                       super_arts_dageki, super_arts_nage,   super_arts_dageki };

void Player_control() {
    pulpul_scene = 1;

    if (pcon_rno[0] + pcon_rno[1] != 0) {
        if (Game_pause || EXE_flag) {
            goto end;
        } else {
            if (pcon_dp_flag == 0) {
                if (--vital_inc_timer > 50) {
                    vital_inc_timer = 50;
                }

                if (--vital_dec_timer > 40) {
                    vital_dec_timer = 40;
                }
            } else {
                vital_inc_timer = 50;
                vital_dec_timer = 40;
                sag_inc_timer[0] = sag_inc_timer[1] = 20;
            }
        }
    }

    players_timer++;
    players_timer &= 0x7FFF;
    set_scrrrl();
    player_main_process[pcon_rno[0]]();
    check_body_touch();
    check_damage_hosei();
    set_quake(&plw[0]);
    set_quake(&plw[1]);

    if ((plw[0].zuru_flag == 0) && (plw[0].zettai_muteki_flag == 0)) {
        hit_push_request(&plw[0].wu);
    }

    if ((plw[1].zuru_flag == 0) && (plw[1].zettai_muteki_flag == 0)) {
        hit_push_request(&plw[1].wu);
    }

    add_next_position(&plw[0]);
    add_next_position(&plw[1]);
    check_cg_zoom();

end:
    if (Game_pause != 0x81) {
        store_player_after_image_data();
    }
}

/* Xbox: no Debug_w[15] test */
void reqPlayerDraw() {
    move_effect_work(6);
    sort_push_request(&plw[0].wu);
    sort_push_request(&plw[1].wu);
}

void plcnt_init() {
    plw[0].reserv_add_y = plw[1].reserv_add_y = 0;
    appear_initalize[appear_type]();
    move_player_work();
}

void init_app_10000() {
    switch (pcon_rno[1]) {
    case 0:
        pli_0000();
        pcon_rno[1] = 2;
        pcon_dp_flag = 0;
        round_slow_flag = 0;
        dead_voice_flag = 0;
        another_bg[0] = another_bg[1] = 0;
        plw[0].scr_pos_set_flag = plw[1].scr_pos_set_flag = 1;

        if (Play_Type == 0) {
            if (plw[0].wu.operator) {
                mpp_w.useChar[My_char[0]]++;
            }

            if (plw[1].wu.operator) {
                mpp_w.useChar[My_char[1]]++;
                return;
            }
        }

        break;

    case 1:
        pli_1000();
        break;

    case 2:
        pcon_rno[1] = 3;

        if (plw[0].wu.operator) {
            paring_ctr_vs[0][0] = paring_ctr_ori[0];
        } else {
            paring_ctr_vs[0][0] = 0;
        }

        if (plw[1].wu.operator) {
            paring_ctr_vs[0][1] = paring_ctr_ori[1];
            return;
        }

        paring_ctr_vs[0][1] = 0;
        break;

    case 3:
        pcon_rno[1] = 1;
        sub_0004384A();
        break;
    }
}

void init_app_20000() {
    s16 i;

    switch (pcon_rno[1]) {
    case 0:
        pcon_rno[1]++;
        round_slow_flag = 0;
        dead_voice_flag = 0;
        pcon_dp_flag = 0;
        another_bg[0] = another_bg[1] = 0;

        for (i = 0; i < 8; i++) {
            plw[0].wu.routine_no[i] = plw[1].wu.routine_no[i] = 0;
        }

        setup_any_data();
        plw[0].do_not_move = plw[1].do_not_move = 0;
        plw[0].scr_pos_set_flag = plw[1].scr_pos_set_flag = 1;
        break;

    case 1:
        pli_1000();
        break;
    }
}

void init_app_30000() {
    s16 i;

    switch (pcon_rno[1]) {
    case 0:
        pcon_rno[1]++;
        round_slow_flag = 0;
        dead_voice_flag = 0;

        for (i = 1; i < 8; i++) {
            plw[0].wu.routine_no[i] = plw[1].wu.routine_no[i] = 0;
        }

        plw[0].wu.routine_no[0] = plw[1].wu.routine_no[0] = 1;
        another_bg[0] = another_bg[1] = 0;
        plw[0].do_not_move = plw[1].do_not_move = 0;
        K7_muriyari_metamor_rebirth(&plw[0]);
        K7_muriyari_metamor_rebirth(&plw[1]);
        break;

    case 1:
        if (plw[0].wu.routine_no[0] != 3 || plw[1].wu.routine_no[0] != 3) {
            break;
        }

        pcon_rno[0] = 2;
        pcon_rno[1] = 3;
        pcon_rno[2] = 1;
        sub_00047420();
        effect_C9_init(plw, 0);
        effect_C9_init(plw, 1);
        effect_C9_init(plw, 2);
        load_any_color(0x3F, 0);
        load_any_texture_patnum(0x71E0, 0xE, 0);
        effect_work_kill(4, 0xD9);

        if (plw[0].player_number == 6) {
            effect_33_init(&plw[0].wu);
        }

        if (plw[1].player_number == 6) {
            effect_33_init(&plw[1].wu);
        }

        break;
    }
}

void pli_0002() {}

void plcnt_move() {
    if (time_over_check() != 0) {
        return;
    }

    if (Debug_w[0x1B]) {
        plw[0].wu.dm_vital = 0;
    }

    if (Debug_w[0x1C]) {
        plw[1].wu.dm_vital = 0;
    }

    if (Debug_w[0x19]) {
        plw[0].wu.vital_new = 0;
    }

    if (Debug_w[0x1A]) {
        plw[1].wu.vital_new = 0;
    }

    if (No_Death) {
        plw[0].wu.dm_vital = plw[1].wu.dm_vital = 0;
    }

    if (Break_Into) {
        plw[0].wu.dm_vital = plw[1].wu.dm_vital = 0;
    }

    if (Mode_Type == 3 && Training->contents[0][1][3] == 0) {
        plw[0].wu.dm_nodeathattack = 1;
        plw[1].wu.dm_nodeathattack = 1;
    }

    move_player_work();

    if (aiuchi_flag) {
        subtract_dm_vital_aiuchi(&plw[0]);
        subtract_dm_vital_aiuchi(&plw[1]);

        if ((plw[0].dead_flag != 0) && (plw[1].dead_flag != 0)) {
            plw[0].wu.hit_stop = plw[1].wu.hit_stop = 2;
            plw[0].wu.dm_stop = plw[1].wu.dm_stop = 0;
            plw[0].wu.hit_quake = plw[1].wu.hit_quake = 4;
            plw[0].wu.dm_quake = plw[1].wu.dm_quake = 0;
        } else if ((plw[0].dead_flag != 0) || (plw[1].dead_flag != 0)) {
            plw[0].wu.hit_stop = plw[1].wu.hit_stop = 4;
            plw[0].wu.dm_stop = plw[1].wu.dm_stop = 0;
            plw[0].wu.hit_quake = plw[1].wu.hit_quake = 8;
            plw[0].wu.dm_quake = plw[1].wu.dm_quake = 0;
        }
    }

    settle_check();

    if (pcon_rno[0] == 2) {
        if (Round_Result & 0x980) {
            if ((Round_Result & 0x800) && gouki_wins) {
                effect_D3_init(1);
            } else {
                effect_D3_init(0);
            }
        }

        if ((plw[0].kezurijini_flag == 1) || (plw[1].kezurijini_flag == 1)) {
            Round_Result |= 0x200;
        }

        if (Winner_id != Loser_id) {
            grade_store_vitality(Winner_id + 0);
        }
    }

    grade_check_tairyokusa();
}

void plcnt_die() {
    plw[0].wu.dm_vital = plw[1].wu.dm_vital = 0;
    settle_process[pcon_rno[1]]();
    move_player_work();

    if (pcon_rno[1] == 3) {
        plw[0].scr_pos_set_flag = plw[1].scr_pos_set_flag = 0;
    }
}

void settle_type_00000() {
    switch (pcon_rno[2]) {
    case 0:
        plw[Winner_id].wu.dir_timer = 60;
        pcon_rno[2]++;
        /* fallthrough */

    case 1:
        if (nekorobi_check(Loser_id)) {
            pcon_rno[2]++;
            plw[Winner_id].wkey_flag = 1;
        }

        if (--plw[Winner_id].wu.dir_timer == 0) {
            plw[Winner_id].wkey_flag = 1;
        }

        break;

    case 2:
        if (footwork_check(Winner_id)) {
            sub_0005DB1A(Winner_id + 0);
            pcon_rno[2]++;
            plw[Winner_id].wu.routine_no[2] = 40;
            plw[Winner_id].wu.routine_no[3] = 0;
            plw[Loser_id].wu.routine_no[1] = 0;
            plw[Loser_id].wu.routine_no[2] = 41;
            plw[Loser_id].wu.routine_no[3] = 0;
            plw[0].wu.cg_type = plw[1].wu.cg_type = 0;
            plw[0].image_setup_flag = plw[1].image_setup_flag = 0;
            complete_victory_pause();
        }

        break;

    case 3:
        if (plw[Winner_id].wu.routine_no[3] == 9) {
            pcon_rno[2]++;
        }

        break;
    }
}

void settle_type_10000() {
    switch (pcon_rno[2]) {
    case 0:
        if (nekorobi_check(0) && nekorobi_check(1)) {
            pcon_rno[2]++;
        }

        break;

    case 1:
        complete_victory_pause();
        pcon_rno[2]++;
        plw[0].image_setup_flag = plw[1].image_setup_flag = 0;
        break;
    }
}

void settle_type_20000() {
    switch (pcon_rno[2]) {
    case 0:
        plw[0].wkey_flag = plw[1].wkey_flag = 1;
        plw[0].image_setup_flag = plw[1].image_setup_flag = 0;
        pcon_rno[2]++;
        /* fallthrough */

    case 1:
        if (footwork_check(0) && footwork_check(1)) {
            pcon_rno[2]++;
        }

        break;

    case 2:
        complete_victory_pause();

        if (plw[0].wu.vital_new == plw[1].wu.vital_new) {
            pcon_rno[2] = 4;
            return;
        }

        sub_0005DB1A(Winner_id + 0);
        plw[Winner_id].wu.routine_no[2] = 40;
        plw[Loser_id].wu.routine_no[2] = 41;
        plw[0].wu.routine_no[1] = plw[1].wu.routine_no[1] = 0;
        plw[0].wu.routine_no[3] = plw[1].wu.routine_no[3] = 0;
        plw[0].wu.cg_type = plw[1].wu.cg_type = 0;
        pcon_rno[2]++;
        break;

    case 3:
        if ((plw[0].wu.routine_no[3] == 9) && (plw[1].wu.routine_no[3] == 9)) {
            pcon_rno[2]++;
        }

        break;
    }
}

void settle_type_30000() {
    switch (pcon_rno[2]) {
    case 0:
        break;

    case 1:
        if ((Event_Judge_Gals == -1) && Complete_Judgement) {
            plw[Winner_id].wu.routine_no[2] = 40;
            plw[Loser_id].wu.routine_no[2] = 41;
            plw[0].wu.routine_no[3] = plw[1].wu.routine_no[3] = 0;
            plw[0].wu.cg_type = plw[1].wu.cg_type = 0;
            sub_0005DB1A(Winner_id + 0);
            complete_victory_pause();
            pcon_rno[2]++;
        }

        break;

    case 2:
        if ((plw[0].wu.routine_no[3] == 9) && (plw[1].wu.routine_no[3] == 9)) {
            pcon_rno[2]++;
        }

        break;
    }
}

void settle_type_40000() {
    switch (pcon_rno[2]) {
    case 0:
        plw[Winner_id].wkey_flag = 1;
        pcon_rno[2]++;
        /* fallthrough */

    case 1:
        if (nekorobi_check(Loser_id) != 0) {
            pcon_rno[2]++;
        case 2:
            if (footwork_check(Winner_id)) {
                pcon_rno[2]++;
                plw[Winner_id].wu.routine_no[2] = 40;
                plw[Winner_id].wu.routine_no[3] = 0;
                plw[Loser_id].wu.routine_no[1] = 0;
                plw[Loser_id].wu.routine_no[2] = 41;
                plw[Loser_id].wu.routine_no[3] = 0;
                plw[Winner_id].wu.cg_type = 0;
                sub_0005DB1A(Winner_id + 0);
                plw[0].image_setup_flag = plw[1].image_setup_flag = 0;
                plw[Winner_id].wu.dir_timer = 60;
                set_conclusion_slow();
                return;
            }
        }

        break;

    case 3:
        if (--plw[Winner_id].wu.dir_timer <= 0) {
            complete_victory_pause();
            pcon_rno[2]++;
        }

        break;

    case 4:
        if (plw[Winner_id].wu.routine_no[3] == 9) {
            pcon_rno[2]++;
        }

        break;
    }
}

void move_player_work() {
    if (plw[0].reserv_add_y) {
        plw[0].wu.xyz[1].disp.pos += plw[0].reserv_add_y;
        plw[0].reserv_add_y = 0;
    }

    if (plw[1].reserv_add_y) {
        plw[1].wu.xyz[1].disp.pos += plw[1].reserv_add_y;
        plw[1].reserv_add_y = 0;
    }

    ichikannkei = check_work_position(&plw[0].wu, &plw[1].wu);
    set_rl_waza(&plw[0]);
    set_rl_waza(&plw[1]);
    Timer_Freeze = 0;

    switch (plw[0].tsukami_f + (plw[1].tsukami_f * 2)) {
    case 1:
        move_P1_move_P2();
        break;

    case 2:
        move_P2_move_P1();
        break;

    default:
        switch (plw[0].wu.operator + (plw[1].wu.operator * 2)) {
        case 1:
            move_P1_move_P2();
            break;

        case 2:
            move_P2_move_P1();
            break;

        default:
            switch ((plw[0].wu.routine_no[1] == 4) + ((plw[1].wu.routine_no[1] == 4) * 2)) {
            case 1:
                move_P1_move_P2();
                break;

            case 2:
                move_P2_move_P1();
                break;

            default:
                if (Game_timer & 1) {
                    move_P1_move_P2();
                    break;
                }

                move_P2_move_P1();
                break;
            }

            break;
        }

        break;
    }
}

void store_player_after_image_data() {
    s16 i;

    for (i = 47; i > 0; i--) {
        zanzou_table[0][i] = zanzou_table[0][i - 1];
        zanzou_table[1][i] = zanzou_table[1][i - 1];
    }

    for (i = 0; i < 2; i++) {
        zanzou_table[i]->pos_x = plw[i].wu.position_x;
        zanzou_table[i]->pos_y = plw[i].wu.position_y;
        zanzou_table[i]->pos_z = plw[i].wu.position_z;
        zanzou_table[i]->cg_num = plw[i].wu.cg_number;
        zanzou_table[i]->renew = plw[i].wu.renew_attack;
        zanzou_table[i]->hit_ix = plw[i].wu.cg_hit_ix;
        zanzou_table[i]->flip = plw[i].wu.rl_flag;
        zanzou_table[i]->cg_flp = plw[i].wu.cg_flip;
        zanzou_table[i]->kowaza = plw[i].wu.kind_of_waza;
    }
}

void check_damage_hosei() {
    plw[0].muriyari_ugoku = plw[0].hosei_amari;
    plw[1].muriyari_ugoku = plw[1].hosei_amari;

    if (plw[0].tsukami_f && plw[1].tsukamare_f) {
        check_damage_hosei_nage(&plw[0], &plw[1]);
    } else if (plw[1].tsukami_f && plw[0].tsukamare_f) {
        check_damage_hosei_nage(&plw[1], &plw[0]);
    } else {
        switch ((plw[0].hosei_amari != 0) + ((plw[1].hosei_amari != 0) * 2)) {
        case 1:
            check_damage_hosei_dageki(&plw[0], &plw[1]);
            break;
        case 2:
            check_damage_hosei_dageki(&plw[1], &plw[0]);
            break;
        }
    }

    plw[0].hosei_amari = plw[1].hosei_amari = 0;
}

void check_damage_hosei_nage(PLW* as, PLW* ds) {
    if (as->kind_of_catch) {
        if (ds->hosei_amari != 0) {
            as->wu.xyz[0].disp.pos += ds->hosei_amari;
            as->muriyari_ugoku += ds->hosei_amari;
            return;
        }

        if (bg_app_stop == 0 && bg_app == 0 && set_field_hosei_flag(as, scrr, 1) != 0) {
            set_field_hosei_flag(as, scrl, 0);
        }

        if (as->hosei_amari != 0) {
            ds->wu.xyz[0].disp.pos += as->hosei_amari;
            ds->muriyari_ugoku += as->hosei_amari;
        }
    } else if (ds->hosei_amari != 0) {
        as->wu.xyz[0].disp.pos += ds->hosei_amari;
        as->muriyari_ugoku += ds->hosei_amari;
    }
}

void check_damage_hosei_dageki(PLW* w1, PLW* w2) {
    if ((w1->dm_hos_flag != 0) && (w2->wu.hit_stop == 0)) {
        w2->wu.xyz[0].disp.pos += w1->hosei_amari;
        w2->muriyari_ugoku += w1->hosei_amari;
    }
}

s32 check_sa_type_rebirth(PLW* wk) {
    if ((wk->spmv_ng_flag & 0x40000000) || (wk->spmv_ng_flag & 0x80000000)) {
        return 0;
    }

    if (wk->sa->gauge_type != 3) {
        return 0;
    }

    if (wk->sa->ok != 1) {
        return 0;
    }

    return 1;
}

s16 nekorobi_check(s8 ix) {
    s16 rnum = 0;

    if ((plw[ix].wu.routine_no[1] == 1) && (plw[ix].wu.routine_no[2] == 0) && (plw[ix].wu.routine_no[3] > 2)) {
        rnum = 1;
    }

    return rnum;
}

void set_quake(PLW* wk) {
    if (wk->wu.hit_quake) {
        wk->wu.hit_quake--;
        wk->wu.next_x = quake_table[wk->wu.hit_quake];

        if (wk->wu.rl_flag) {
            wk->wu.next_x = -wk->wu.next_x;
        }
    } else {
        wk->wu.next_x = 0;
    }
}

void add_next_position(PLW* wk) {
    wk->wu.position_x = wk->wu.xyz[0].disp.pos + wk->wu.next_x;
    wk->wu.position_y = wk->wu.xyz[1].disp.pos + wk->wu.next_y;
    wk->wu.position_z = wk->wu.next_z;
    wk->wu.next_y = 0;
}

void erase_extra_plef_work() {
    effect_work_list_init(0, 0);
    effect_work_list_init(1, 1);
    effect_work_list_init(3, 0x91);
    effect_work_list_init(3, 0x93);
    effect_work_list_init(3, 0x94);
    effect_work_list_init(4, 0x81);
    effect_work_list_init(4, 0x25);
    effect_work_list_init(4, 0xAC);
    effect_work_list_init(6, -1);
}

void setup_base_and_other_data() {
    make_texcash_work(3);
    make_texcash_work(4);
    make_texcash_work(6);
    plw[0].wu.my_mts = 3;
    plw[1].wu.my_mts = 4;
    set_base_data(&plw[0], 0);
    set_base_data(&plw[1], 1);
    plw[0].sa = &super_arts[0];
    plw[1].sa = &super_arts[1];
    plw[0].py = &piyori_type[0];
    plw[1].py = &piyori_type[1];
    setup_other_data(&plw[0]);
    setup_other_data(&plw[1]);
    effect_work_list_init(6, 0xC5);
    plw[0].gill_ccch_go = plw[1].gill_ccch_go = 0;
    effect_J7_init(&plw[0]);
    effect_J7_init(&plw[1]);
    effect_E5_init(&plw[0]);
    effect_E5_init(&plw[1]);

    if (plw[0].wu.my_priority == plw[1].wu.my_priority) {
        plw[0].the_same_players = plw[1].the_same_players = 1;
    }

    poison_flag[0] = 0;
    poison_flag[1] = 0;

    if (Mode_Type == 3 || Mode_Type == 4) {
        effect_E3_init(&plw[0]);
        effect_E3_init(&plw[1]);
        effect_E4_init(&plw[0]);
        effect_E4_init(&plw[1]);
    }
}

void set_base_data(PLW* wk, s16 ix) {
    wk->wu.be_flag = 1;
    wk->wu.disp_flag = 0;
    wk->wu.blink_timing = ix;
    wk->wu.id = ix;
    wk->wu.work_id = 1;
    wk->wu.operator = Operator_Status[ix];
    wk->wu.charset_id = plid_data[My_char[ix]];
    wk->wkey_flag = wk->dead_flag = 0;
    set_char_base_data(&wk->wu);
    wk->wu.target_adrs = (u32*)&plw[(ix + 1) & 1];
    wk->player_number = My_char[ix];
    wk->wu.hit_adrs = wk->wu.target_adrs;
    wk->wu.dmg_adrs = wk->wu.target_adrs;
    cmd_init(wk);
    wk->cb = &combo_type[ix];
    wk->rp = &remake_power[ix];

    if (ix) {
        wk->wu.my_col_code |= 0x10;
    }

    wk->spmv_ng_flag = omop_spmv_ng_table[wk->wu.id];
    wk->spmv_ng_flag2 = omop_spmv_ng_table2[wk->wu.id];
    wk->wu.weight_level = weight_lv_table[wk->player_number];
    set_player_shadow(wk);
    wk->wu.cg_olc_ix = wk->wu.cg_hit_ix = 0;
    wk->wu.cg_olc = wk->wu.olc_ix_table[wk->wu.cg_olc_ix];
    wk->wu.cg_ja = wk->wu.hit_ix_table[wk->wu.cg_hit_ix];

    set_jugde_area(&wk->wu);
}

void set_base_data_metamorphose(PLW* wk, s16 dmid) {
    set_char_base_data(&wk->wu);

    if (wk->wu.id) {
        wk->wu.my_col_code |= 0x10;
    }

    cmd_init(wk);
    wk->spmv_ng_flag = omop_spmv_ng_table[dmid];
    wk->spmv_ng_flag2 = omop_spmv_ng_table2[dmid];
    set_player_shadow(wk);
}

void set_player_shadow(PLW* wk) {
    wk->wu.kage_flag = 1;
    wk->wu.kage_prio = 68;
    wk->wu.kage_hx = kage_base[wk->player_number][0];
    wk->wu.kage_char = kage_base[wk->player_number][1];
}

void setup_other_data(PLW* wk) {
    s16 i;

    if (wk->player_number == 0) {
        (Introduce_Boss[wk->wu.id][1] & 0x80) == 0;
        setup_GILL_exsa_obj();
    }

    for (i = 0; i < 4; i++) {
        effect_01_init(&wk->wu, i);
    }

    effect_K5_init(wk);
    effect_00_init(&wk->wu);
}

void clear_chainex_check(s16 ix) {
    s16 i;

    for (i = 0; i < 36; i++) {
        chainex_check[ix][i] = 0;
    }
}

/* Notes from the hand port this file replaced:
 * set_kizetsu_status is 0x85BF2 size 0x7B, interior after the ret.
 * clear_kizetsu_point is 0x85C6D size 0x43, interior after the ret.
 * check_damage_hosei_nage is 0x858FA size 0x9B.
 * check_damage_hosei_dageki is 0x85995 size 0x30.
 * set_scrrrl is 0x85EF2 size 0x1E.
 * check_damage_hosei is 0x8637C size 0xA0.
 * These four are the PS2 C. scrr is the word at 0x7A88F8 and scrl the word at
 * 0x7A81D0. hosei_amari is PLW + 0x3AA, dm_hos_flag + 0x3AC, and
 * muriyari_ugoku + 0x3AE.
 * piyori_type is 0xC7D9A0, stride 0x14. flag is +0, genkai is +2,
 * time is +4, now.timer is +8, recover is +0xC, and store is +0x10.
 * My_char is 0x7A8114. omop_stun_gauge_len is 0x7C5C48.
 * stun_gauge_len_omake is 0x268480 and matches the 5 PlayStation 2
 * words. pl_piyo_tbl is 0x262420 and matches the 20 words.
 * pl_nr_piyo_tbl is 0x262448 and matches the 20 dwords.
 * player_number is PLW + 0x394. py is PLW + 0x3CC.
 */

/* The hand port's bodies (they matched as written): set_kizetsu_status,
 * clear_kizetsu_point, set_scrrrl, check_damage_hosei_nage,
 * check_damage_hosei_dageki, check_damage_hosei. */
void set_kizetsu_status(s16 ix) {
    s16 plnum = My_char[ix];

    piyori_type[ix].flag = 0;
    piyori_type[ix].time = 0;
    piyori_type[ix].now.timer = 0;
    piyori_type[ix].store = 0;
    piyori_type[ix].recover = pl_nr_piyo_tbl[plnum];
    piyori_type[ix].genkai = pl_piyo_tbl[plnum] + stun_gauge_len_omake[omop_stun_gauge_len[ix]];

    if (piyori_type[ix].genkai < 56) {
        piyori_type[ix].genkai = 56;
    }

    if (piyori_type[ix].genkai > 72) {
        piyori_type[ix].genkai = 72;
    }
}

void clear_kizetsu_point(PLW *wk) {
    wk->py->flag = 0;
    wk->py->time = 0;
    wk->py->now.timer = 0;
    wk->py->store = 0;
    wk->py->recover = pl_nr_piyo_tbl[wk->player_number];
}

void set_super_arts_status(s16 ix) {
    const SA_DATA* saptr;

    if (cmd_sel[ix] || no_sa[ix]) {
        saptr = &super_arts_DATA[My_char[ix]][Super_Arts[ix]];
    } else {
        saptr = &super_arts_data[My_char[ix]][Super_Arts[ix]];
    }

    super_arts[ix].kind_of_arts = Super_Arts[ix];
    super_arts[ix].nmsa_g_ix = saptr->nmsa_g_ix;
    super_arts[ix].exsa_g_ix = saptr->exsa_g_ix;
    super_arts[ix].exs2_g_ix = saptr->exs2_g_ix;
    super_arts[ix].nmsa_a_ix = saptr->nmsa_a_ix;
    super_arts[ix].exsa_a_ix = saptr->exsa_a_ix;
    super_arts[ix].exs2_a_ix = saptr->exs2_a_ix;
    super_arts[ix].ex4th_full = saptr->ex4th_full;
    super_arts[ix].gauge_type = saptr->gauge_type;
    super_arts[ix].gt2 = saptr->gauge_type;
    super_arts[ix].gauge_len = remake_sa_gauge_len(ix, saptr->gauge_len);
    super_arts[ix].store_max = remake_sa_store_max(ix, saptr->store_max);
    super_arts[ix].dtm = saptr->dtm;
    super_arts[ix].dtm_mul = 1;
    super_arts[ix].store = 0;
    super_arts[ix].gauge.s.h = 0;
    super_arts[ix].gauge.s.l = -1;
    super_arts[ix].sa_rno = 0;
    super_arts[ix].ok = 0;
}

/* Xbox: written num < 1 */
s16 remake_sa_store_max(s16 ix, s16 store_max) {
    s16 num = store_max + sag_stock_omake[omop_sag_max_ix[ix]];

    if (num < 1) {
        num = 1;
    }

    if (num > 9) {
        num = 9;
    }

    return num;
}

s16 remake_sa_gauge_len(s16 ix, s16 gauge_len) {
    s16 num = gauge_len + sag_length_omake[omop_sag_len_ix[ix]] * 8;

    if (num < 0x40) {
        num = 0x40;
    }

    if (num > 0x80) {
        num = 0x80;
    }

    return num;
}

void set_super_arts_status_dc(s16 ix) {
    const SA_DATA* saptr;

    if (cmd_sel[ix] || no_sa[ix]) {
        saptr = &super_arts_DATA[My_char[ix]][Super_Arts[ix]];
    } else {
        saptr = &super_arts_data[My_char[ix]][Super_Arts[ix]];
    }

    super_arts[ix].kind_of_arts = Super_Arts[ix];
    super_arts[ix].nmsa_g_ix = saptr->nmsa_g_ix;
    super_arts[ix].exsa_g_ix = saptr->exsa_g_ix;
    super_arts[ix].exs2_g_ix = saptr->exs2_g_ix;
    super_arts[ix].nmsa_a_ix = saptr->nmsa_a_ix;
    super_arts[ix].exsa_a_ix = saptr->exsa_a_ix;
    super_arts[ix].exs2_a_ix = saptr->exs2_a_ix;
    super_arts[ix].ex4th_full = saptr->ex4th_full;
    super_arts[ix].gauge_type = saptr->gauge_type;
    super_arts[ix].gauge_len = remake_sa_gauge_len(ix, saptr->gauge_len);
    super_arts[ix].store_max = remake_sa_store_max(ix, saptr->store_max);
    super_arts[ix].dtm = saptr->dtm;
    super_arts[ix].dtm_mul = 1;
}

void clear_super_arts_point(PLW* wk) {
    wk->sa->store = 0;
    wk->sa->gauge.s.h = 0;
    wk->sa->gauge.s.l = -1;
    wk->sa->mp_rno = 0;
    wk->sa->mp_rno2 = 0;
    wk->sa->sa_rno = 0;
    wk->sa->sa_rno2 = 0;
    wk->sa->ex_rno = 0;
    wk->sa->mp = 0;
    wk->sa->ok = 0;
    wk->sa->ex = 0;
    wk->sa->bacckup_g_h = 0;
}

s16 check_combo_end(s16 ix) {
    s16 rnum;

    if (plw[ix].py->flag) {
        return 1;
    }

    if (plw[ix].tsukamare_f) {
        return 1;
    }

    if (pcon_rno[0] == 2 && pcon_rno[1] == 0 && pcon_rno[2] == 2) {
        return 0;
    }

    if (plw[ix].wu.cg_ja.boix == 0 && plw[ix].wu.cg_ja.cuix == 0 && plw[ix].wu.pat_status == 38) {
        return 0;
    }

    if (plw[ix].zuru_flag) {
        return 0;
    }

    if (plw[ix].wu.routine_no[1] != 1 && plw[ix].wu.routine_no[1] != 3) {
        return 0;
    }

    if (plw[ix].old_gdflag != plw[ix].guard_flag) {
        if (plw[ix].guard_flag == 0) {
            rnum = 0;
        } else {
            rnum = 1;
        }
    } else if (plw[ix].guard_flag == 0) {
        rnum = 0;
    } else {
        rnum = 1;
    }

    return rnum;
}

void set_scrrrl() {
    s16 scrc = get_center_position();

    scrr = scrc + 192;
    scrl = scrc - 192;
}

#if 0
/* PS2 C for functions not located in sf33rd.xbe yet. */

void pli_0000() {
    pcon_rno[1]++;
    round_slow_flag = 0;
    work_init_zero((s32*)&plw[0], sizeof(PLW));
    work_init_zero((s32*)&plw[1], sizeof(PLW));
    setup_base_and_other_data();
}

void pli_1000() {
    if (plw[0].wu.routine_no[0] != 3) {
        return;
    }

    if (plw[1].wu.routine_no[0] != 3) {
        return;
    }

    if (!Allow_a_battle_f) {
        return;
    }

    pcon_rno[0] = 1;
    pcon_rno[1] = 0;
    plw[0].wu.routine_no[0] = 4;
    plw[1].wu.routine_no[0] = 4;
    ca_check_flag = 1;
}

void move_P1_move_P2() {
#if defined(TARGET_PS2)
    void Player_move(PLW * wk, u32 lv_data);
    s32 set_field_hosei_flag(PLW * pl, s32 pos, s16 ix);
#endif

    if (plw[0].do_not_move == 0) {
        Player_move(&plw[0], processed_lvbt(Convert_User_Setting(0)));
    }

    if (bg_app_stop == 0 && bg_app == 0 && set_field_hosei_flag(&plw[0], scrr, 1) != 0) {
        set_field_hosei_flag(&plw[0], scrl, 0);
    }

    if (plw[1].do_not_move == 0) {
        Player_move(&plw[1], processed_lvbt(Convert_User_Setting(1)));
    }

    if (bg_app_stop == 0 && bg_app == 0 && set_field_hosei_flag(&plw[1], scrr, 1) != 0) {
        set_field_hosei_flag(&plw[1], scrl, 0);
    }
}

void move_P2_move_P1() {
#if defined(TARGET_PS2)
    void Player_move(PLW * wk, u32 lv_data);
    s32 set_field_hosei_flag(PLW * pl, s32 pos, s16 ix);
#endif

    if (plw[1].do_not_move == 0) {
        Player_move(&plw[1], processed_lvbt(Convert_User_Setting(1)));
    }

    if (bg_app_stop == 0 && bg_app == 0 && set_field_hosei_flag(&plw[1], scrr, 1) != 0) {
        set_field_hosei_flag(&plw[1], scrl, 0);
    }

    if (plw[0].do_not_move == 0) {
        Player_move(&plw[0], processed_lvbt(Convert_User_Setting(0)));
    }

    if (bg_app_stop == 0 && bg_app == 0 && set_field_hosei_flag(&plw[0], scrr, 1) != 0) {
        set_field_hosei_flag(&plw[0], scrl, 0);
    }
}

s32 time_over_check() {
    if ((will_die() != 0) && (round_timer.size.full == 0)) {
        Winner_id = 0;
        Loser_id = 1;

        if (plw[0].wu.vital_new < plw[1].wu.vital_new) {
            Winner_id = 1;
            Loser_id = 0;
        }

        Conclusion_Flag = 1;
        Conclusion_Type = 2;
        setup_settle_rno(2);

        if (Demo_Flag) {
            request_center_message(2);
        }

        plw[0].wu.dm_vital = plw[1].wu.dm_vital = 0;
        Round_Result |= 1;
        return 1;
    }

    return 0;
}

s32 will_die() {
    if (plw[0].wu.dm_vital > plw[0].wu.vital_new) {
        return 0;
    }

    if (plw[1].wu.dm_vital > plw[1].wu.vital_new) {
        return 0;
    }

    return 1;
}

void setup_settle_rno(s16 kos) {
    pcon_rno[0] = 2;
    pcon_rno[1] = kos;
    pcon_rno[2] = 0;
    ca_check_flag = 0;
    pcon_dp_flag = 1;
}

void settle_check() {
    while (1) {
        switch ((plw[0].dead_flag) + (plw[1].dead_flag * 2)) {
        case 1:
            if (1) {
                Winner_id = 1;
                Loser_id = 0;
            } else {
                /* fallthrough */

            case 2:
                Winner_id = 0;
                Loser_id = 1;
            }

            if (check_sa_resurrection(&plw[Loser_id]) == 0) {
                setup_gouki_wins();
                Round_Result |= plw[Loser_id].wu.dm_koa;

                if ((Round_Result & 0x800) && gouki_wins) {
                    Forbid_Break = -1;
                    Shin_Gouki_BGM = 1;
                    Control_Music_Fade(0x96);
                    setup_settle_rno(4);
                    break;
                }

                setup_settle_rno(0);
                Conclusion_Flag = 1;
                Conclusion_Type = 0;

                if (Demo_Flag) {
                    request_center_message(0);
                }
            }

            break;

        case 3:
            if ((check_sa_resurrection(&plw[0]) == 0) && (check_sa_resurrection(&plw[1]) == 0)) {
                Conclusion_Flag = 1;
                Conclusion_Type = 1;
                setup_settle_rno(1);

                if (Demo_Flag) {
                    request_center_message(1);
                }
            } else {
                continue;
            }

            break;

        default:
            break;
        }

        break;
    }
}

s32 check_sa_resurrection(PLW* wk) {
    if (check_sa_type_rebirth(wk) == 0) {
        return 0;
    }

    wk->kezurijini_flag = 0;
    wk->dead_flag = 0;
    wk->resurrection_resv = 1;
    return 1;
}

s16 footwork_check(s8 ix) {
    s16 rnum = 0;

    if (plw[ix].wu.routine_no[1] == 0 && plw[ix].wu.routine_no[2] == 1) {
        rnum = 1;
    }

    return rnum;
}

void setup_gouki_wins() {
    gouki_wins = 0;

    if (plw[Winner_id].player_number == 14) {
        gouki_wins = 1;
    }
}

void setup_any_data() {
    set_base_data_tiny(&plw[0]);
    set_base_data_tiny(&plw[1]);
    setup_other_data(&plw[0]);
    setup_other_data(&plw[1]);
    effect_work_list_init(6, 0xC5);
    plw[0].gill_ccch_go = plw[1].gill_ccch_go = 0;
    effect_J7_init(&plw[0]);
    effect_J7_init(&plw[1]);
    effect_E5_init(&plw[0]);
    effect_E5_init(&plw[1]);

    if (plw[0].wu.my_priority == plw[1].wu.my_priority) {
        plw[0].the_same_players = plw[1].the_same_players = 1;
    }
}

void set_base_data_tiny(PLW* wk) {
    wk->wu.charset_id = plid_data[My_char[wk->wu.id]];
    wk->player_number = My_char[wk->wu.id];
    set_char_base_data(&wk->wu);

    if (wk->wu.id) {
        wk->wu.my_col_code |= 0x10;
    }

    wk->wu.be_flag = 1;
    wk->wu.disp_flag = 0;
    wk->wkey_flag = wk->dead_flag = 0;
    cmd_init(wk);
    wk->spmv_ng_flag = omop_spmv_ng_table[wk->wu.id];
    wk->spmv_ng_flag2 = omop_spmv_ng_table2[wk->wu.id];
    wk->wu.weight_level = weight_lv_table[wk->player_number];
    set_player_shadow(wk);
}
#endif
