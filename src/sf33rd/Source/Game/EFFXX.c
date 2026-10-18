/* EFFXX.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * effect_dummy_init 0x120EC size 0x4.
 * effect_dummy_move is folded into 0x4384A with 20 other bodies. Unnamed.
 * effect_00_move is folded into 0x4384A with 48 other bodies. Unnamed.
 * effect_28_move is folded into 0x4384A with 48 other bodies. Unnamed.
 * effect_87_move is folded into 0x4384A with 48 other bodies. Unnamed.
 * effect_F4_move is folded into 0x4384A with 48 other bodies. Unnamed.
 * Data: effmovejptbl is 0x25B658, 229 entries compared.
 * Data: effinitjptbl 0x25B9F0, entries DIFFER.
 */

#include "structs.h"

#define NULL 0

void effect_00_move(WORK_Other_JUDGE* ewk);
void effect_01_move(WORK_Other* ewk);
void effect_02_move(WORK_Other* ewk);
void effect_03_move(WORK_Other* ewk);
void effect_04_move(WORK_Other* ewk);
void effect_05_move(WORK_Other* ewk);
void effect_06_move(WORK_Other* ewk);
void effect_07_move(WORK_Other* ewk);
void effect_08_move(WORK_Other* ewk);
void effect_09_move(WORK_Other* ewk);
void effect_10_move(WORK_Other* ewk);
void effect_11_move(WORK_Other* ewk);
void effect_12_move(WORK_Other* ewk);
void effect_13_move(WORK_Other* ewk);
void effect_14_move(WORK_Other* ewk);
void effect_15_move(WORK_Other* ewk);
void effect_16_move(WORK_Other* ewk);
void effect_17_move(WORK_Other* ewk);
void effect_18_move(WORK_Other_CONN* ewk);
void effect_19_move(WORK_Other* ewk);
void effect_20_move(WORK_Other* ewk);
void effect_21_move(WORK_Other* ewk);
void effect_22_move(WORK_Other* ewk);
void effect_23_move(WORK_Other_CONN* ewk);
void effect_24_move(WORK_Other* ewk);
void effect_25_move(WORK_Other* ewk);
void effect_26_move(WORK_Other* ewk);
void effect_27_move(WORK_Other* ewk);
void effect_28_move(WORK_Other* );
void effect_29_move(WORK_Other* ewk);
void effect_30_move(WORK_Other* ewk);
void effect_31_move(WORK_Other* ewk);
void effect_32_move(WORK_Other* ewk);
void effect_33_move(WORK_Other* ewk);
void effect_34_move(WORK_Other* ewk);
void effect_35_move(WORK_Other* ewk);
void effect_36_move(WORK_Other* ewk);
void effect_37_move(WORK_Other* ewk);
void effect_38_move(WORK_Other* ewk);
void effect_39_move(WORK_Other* ewk);
void effect_40_move(WORK_Other* ewk);
void effect_41_move(WORK_Other* ewk);
void effect_42_move(WORK_Other* ewk);
void effect_43_move(WORK_Other* ewk);
void effect_44_move(WORK_Other* ewk);
void effect_45_move(WORK_Other_CONN* ewk);
void effect_46_move(WORK_Other* ewk);
void effect_47_move(WORK_Other* ewk);
void effect_48_move(WORK_Other* ewk);
void effect_49_move(WORK_Other* ewk);
void effect_50_move(WORK_Other* ewk);
void effect_51_move(WORK_Other_CONN* ewk);
void effect_52_move(WORK_Other* ewk);
void effect_53_move(WORK_Other* ewk);
void effect_54_move(WORK_Other* ewk);
void effect_55_move(WORK_Other* ewk);
void effect_56_move(WORK_Other* ewk);
void effect_57_move(WORK_Other* ewk);
void effect_58_move(WORK_Other* ewk);
void effect_59_move(WORK_Other* ewk);
void effect_60_move(WORK_Other* ewk);
void effect_61_move(WORK_Other_CONN* ewk);
void effect_62_move(WORK_Other* ewk);
void effect_63_move(WORK_Other_CONN* ewk);
void effect_64_move(WORK_Other_CONN* ewk);
void effect_65_move(WORK_Other* ewk);
void effect_66_move(WORK_Other* ewk);
void effect_67_move(WORK_Other_CONN* ewk);
void effect_68_move(WORK_Other* ewk);
void effect_69_move(WORK_Other* ewk);
void effect_70_move(WORK_Other* ewk);
void effect_71_move(WORK_Other* ewk);
void effect_72_move(WORK_Other* ewk);
void effect_73_move(WORK_Other* ewk);
void effect_74_move(WORK_Other* ewk);
void effect_75_move(WORK_Other* ewk);
void effect_76_move(WORK_Other* ewk);
void effect_77_move(WORK_Other* ewk);
void effect_78_move(WORK_Other* ewk);
void effect_79_move(WORK_Other* ewk);
void effect_80_move(WORK_Other* ewk);
void effect_81_move(WORK_Other* ewk);
void effect_82_move(WORK_Other* ewk);
void effect_83_move(WORK_Other* ewk);
void effect_84_move(WORK_Other* ewk);
void effect_85_move(WORK_Other* ewk);
void effect_86_move(WORK_Other* ewk);
void effect_87_move(WORK_Other* );
void effect_dummy_move();
void effect_90_move(WORK_Other_CONN* ewk);
void effect_91_move(WORK_Other* ewk);
void effect_92_move(WORK_Other* ewk);
void effect_93_move(WORK_Other* ewk);
void effect_94_move(WORK_Other* ewk);
void effect_95_move(WORK_Other* ewk);
void effect_96_move(WORK_Other* ewk);
void effect_97_move(WORK_Other* ewk);
void effect_98_move(WORK_Other* ewk);
void effect_99_move(WORK_Other_CONN* ewk);
void effect_A0_move(WORK_Other_CONN* ewk);
void effect_A1_move(WORK_Other* ewk);
void effect_A2_move(WORK_Other* ewk);
void effect_A3_move(WORK_Other* ewk);
void effect_A5_move(WORK_Other* ewk);
void effect_A6_move(WORK_Other_CONN* ewk);
void effect_A7_move(WORK_Other* ewk);
void effect_A8_move(WORK_Other_CONN* ewk);
void effect_A9_move(WORK_Other* ewk);
void effect_B0_move(WORK_Other* ewk);
void effect_B1_move(WORK_Other_CONN* ewk);
void effect_B2_move(WORK_Other* ewk);
void effect_B3_move(WORK_Other* ewk);
void effect_B4_move(WORK_Other* ewk);
void effect_B5_move(WORK_Other* ewk);
void effect_B6_move(WORK_Other_CONN* ewk);
void effect_B7_move(WORK_Other* ewk);
void effect_B8_move(WORK_Other_CONN* ewk);
void effect_B9_move(WORK_Other* ewk);
void effect_C0_move(WORK_Other* ewk);
void effect_C1_move(WORK_Other* ewk);
void effect_C2_move(WORK_Other* ewk);
void effect_C3_move(WORK_Other* ewk);
void effect_C4_move(WORK_Other_CONN* ewk);
void effect_C5_move(WORK_Other* ewk);
void effect_C6_move(WORK_Other* ewk);
void effect_C7_move(WORK_Other* ewk);
void effect_C8_move(WORK_Other* ewk);
void effect_C9_move(WORK_Other* ewk);
void effect_D0_move(WORK_Other* ewk);
void effect_D1_move(WORK_Other* ewk);
void effect_D3_move(WORK_Other* ewk);
void effect_D4_move(WORK_Other* ewk);
void effect_D5_move(WORK_Other* ewk);
void effect_D6_move(WORK_Other* ewk);
void effect_D7_move(WORK_Other* ewk);
void effect_D8_move(WORK_Other* ewk);
void effect_D9_move(WORK_Other* ewk);
void effect_E0_move(WORK_Other* ewk);
void effect_E1_move(WORK_Other* ewk);
void effect_E2_move(WORK_Other* ewk);
void effect_E3_move(WORK_Other* ewk);
void effect_E4_move(WORK_Other* ewk);
void effect_E5_move(WORK_Other* ewk);
void effect_E6_move(WORK_Other* ewk);
void effect_E7_move(WORK_Other* ewk);
void effect_E8_move(WORK_Other* ewk);
void effect_E9_move(WORK_Other* ewk);
void effect_F0_move(WORK_Other* ewk);
void effect_F2_move(WORK_Other* ewk);
void effect_F4_move();
void effect_F5_move(WORK_Other* ewk);
void effect_F6_move(WORK_Other* ewk);
void effect_F8_move(WORK_Other* ewk);
void effect_F9_move(WORK_Other* ewk);
void effect_G0_move(WORK_Other* ewk);
void effect_G3_move(WORK_Other* ewk);
void effect_G4_move(WORK_Other* ewk);
void effect_G5_move(WORK_Other* ewk);
void effect_G6_move(WORK_Other* ewk);
void effect_G7_move(WORK_Other* ewk);
void effect_G8_move(WORK_Other* ewk);
void effect_G9_move(WORK_Other* ewk);
void effect_H0_move(WORK_Other_CONN* ewk);
void effect_H1_move(WORK_Other* ewk);
void effect_H2_move(WORK_Other* ewk);
void effect_H6_move(WORK_Other* ewk);
void effect_H9_move(WORK_Other_CONN* ewk);
void effect_I0_move(WORK_Other* ewk);
void effect_I3_move(WORK_Other* ewk);
void effect_I4_move(WORK_Other* ewk);
void effect_I6_move(WORK_Other* ewk);
void effect_I7_move(WORK_Other* ewk);
void effect_I8_move(WORK_Other* ewk);
void effect_I9_move(WORK_Other* ewk);
void effect_J0_move(WORK_Other* ewk);
void effect_J2_move(WORK_Other_CONN* ewk);
void effect_J4_move(WORK_Other* ewk);
void effect_J6_move(WORK_Other* ewk);
void effect_J7_move(WORK_Other* ewk);
void effect_J8_move(WORK_Other* ewk);
void effect_J9_move(WORK_Other* ewk);
void effect_K2_move(WORK_Other* ewk);
void effect_K3_move(WORK_Other* ewk);
void effect_K4_move(WORK_Other* ewk);
void effect_K5_move(WORK_Other* ewk);
void effect_K6_move(WORK_Other* ewk);
void effect_K7_move(WORK_Other* ewk);
void effect_K8_move(WORK_Other* ewk);
void effect_K9_move(WORK_Other* ewk);
void effect_L0_move(WORK_Other* ewk);
void effect_L1_move(WORK_Other_CONN* ewk);
void effect_L2_move(WORK_Other* ewk);
void effect_L3_move(WORK_Other* ewk);
void effect_L4_move(WORK_Other* ewk);
void effect_L5_move(WORK_Other* ewk);
void effect_L6_move(WORK_Other* ewk);
void effect_L7_move(WORK_Other* ewk);
void effect_L8_move(WORK_Other* ewk);
void effect_L9_move(WORK_Other* ewk);
void effect_M0_move(WORK_Other* ewk);
void effect_M1_move(WORK_Other* ewk);
void effect_M2_move(WORK_Other* ewk);
void effect_M3_move(WORK_Other* ewk);
void effect_M5_move(WORK_Other* ewk);
void effect_M6_move(WORK_Other* ewk);
void effect_M7_move(WORK_Other* ewk);
void effect_M8_move(WORK_Other* ewk);
s32 effect_03_init(WORK* wk, u8 data);
s32 effect_13_init(WORK* wk, const u8 data);
s32 effect_09_init(WORK* wk, u8 data);
s32 effect_G7_init(s32 , s32 );
s32 effect_C0_init(PLW* wk, s32 );
s32 effect_C7_init(PLW* wk, u8 data);
s32 effect_D0_init(PLW* oya, s32 );
s32 effect_D1_init(WORK_Other* oya, s32 );
s32 effect_F4_init();
s32 effect_34_init(WORK* wk, s32 );
s32 effect_37_init(WORK* wk, u8 gal, u8 ohen);
s32 effect_09_init2(WORK* wk, u8 data);
s32 effect_41_init(PLW* wk, u8 data);
s32 effect_D4_init(WORK* wk, u8 data);
s32 set_tenguiwa(PLW* wk, u8 data);
s32 effect_D9_init(PLW* wk, u8 data);
s32 setup_accessories(PLW* wk, u8 data);
s32 setup_after_images(PLW* wk, u8 ix);
s32 erase_after_images(PLW* wk, u8 who);
s32 effect_dummy_init();
s32 clear_caution_flag(PLW* wk, u8 );
s32 setup_status_flag(WORK* wk, u8 data);
s32 reset_extra_bg_flag(WORK* wk, u8 );
s32 flip_my_rl_flag(WORK* wk, u8 );
s32 effect_F8_init(PLW* wk, u8 data);
s32 effect_G3_init(WORK* wk, u8 data);
s32 effect_G4_init(WORK* wk, u8 data);
s32 setup_ase_extra(WORK* wk, u8 num);
s32 effect_G6_init(WORK* wk, u8 dat);
s32 setup_meoshi_hit_flag(WORK* wk, u8 data);
s32 exec_char_asxy(WORK* wk, u8 data);
s32 set_caution_flag(PLW* wk, u8 );
s32 setup_my_clear_level(WORK* wk, u8 data);
s32 setup_my_bright_level(WORK* wk, u8 data);
s32 setup_free_program(s32 , s32 );
s32 setup_bg_quake_x(s32 , u8 data);
s32 setup_bg_quake_y(s32 , u8 data);
s32 effect_47_init(WORK* wk, s32 );
s32 setup_koishi_extra(WORK* wk, u8 num);
s32 effect_77_init(u8 , u8 data);
s32 setup_exdm_ix(PLW* wk, u8 data);
s32 setup_dmv_use_flag(PLW* wk, u8 data);
s32 effect_D5_init(WORK* wk, s32 );
s32 effect_D6_init(WORK_Other* wk, s16 dr, s16 sp, s16 dl, s16 acc);
s32 setup_disp_flag(WORK* wk, u8 data);
s32 setup_command_number(PLW* wk, u8 data);
s32 effect_I7_init(PLW* wk, u8 data);
s32 setup_sa_shadow(u8 , u8 data);
s32 effect_73_init(WORK_Other* oya);
s32 effect_K8_init(WORK* wk, u8 data);
s32 effect_K9_init(WORK* wk, u8 data);
s32 effect_L7_init(WORK* wk, s32 );
s32 effect_M2_init(WORK* wk, u8 data);
s32 effect_M8_init(WORK* oya, u8 data);
s32 effect_F0_init(WORK* wk);

const void (*effmovejptbl[229])() = {
    effect_00_move,    effect_01_move,    effect_02_move,    effect_03_move,    effect_04_move,    effect_05_move,
    effect_06_move,    effect_07_move,    effect_08_move,    effect_09_move,    effect_10_move,    effect_11_move,
    effect_12_move,    effect_13_move,    effect_14_move,    effect_15_move,    effect_16_move,    effect_17_move,
    effect_18_move,    effect_19_move,    effect_20_move,    effect_21_move,    effect_22_move,    effect_23_move,
    effect_24_move,    effect_25_move,    effect_26_move,    effect_27_move,    effect_28_move,    effect_29_move,
    effect_30_move,    effect_31_move,    effect_32_move,    effect_33_move,    effect_34_move,    effect_35_move,
    effect_36_move,    effect_37_move,    effect_38_move,    effect_39_move,    effect_40_move,    effect_41_move,
    effect_42_move,    effect_43_move,    effect_44_move,    effect_45_move,    effect_46_move,    effect_47_move,
    effect_48_move,    effect_49_move,    effect_50_move,    effect_51_move,    effect_52_move,    effect_53_move,
    effect_54_move,    effect_55_move,    effect_56_move,    effect_57_move,    effect_58_move,    effect_59_move,
    effect_60_move,    effect_61_move,    effect_62_move,    effect_63_move,    effect_64_move,    effect_65_move,
    effect_66_move,    effect_67_move,    effect_68_move,    effect_69_move,    effect_70_move,    effect_71_move,
    effect_72_move,    effect_73_move,    effect_74_move,    effect_75_move,    effect_76_move,    effect_77_move,
    effect_78_move,    effect_79_move,    effect_80_move,    effect_81_move,    effect_82_move,    effect_83_move,
    effect_84_move,    effect_85_move,    effect_86_move,    effect_87_move,    effect_dummy_move, effect_dummy_move,
    effect_90_move,    effect_91_move,    effect_92_move,    effect_93_move,    effect_94_move,    effect_95_move,
    effect_96_move,    effect_97_move,    effect_98_move,    effect_99_move,    effect_A0_move,    effect_A1_move,
    effect_A2_move,    effect_A3_move,    effect_dummy_move, effect_A5_move,    effect_A6_move,    effect_A7_move,
    effect_A8_move,    effect_A9_move,    effect_B0_move,    effect_B1_move,    effect_B2_move,    effect_B3_move,
    effect_B4_move,    effect_B5_move,    effect_B6_move,    effect_B7_move,    effect_B8_move,    effect_B9_move,
    effect_C0_move,    effect_C1_move,    effect_C2_move,    effect_C3_move,    effect_C4_move,    effect_C5_move,
    effect_C6_move,    effect_C7_move,    effect_C8_move,    effect_C9_move,    effect_D0_move,    effect_D1_move,
    effect_dummy_move, effect_D3_move,    effect_D4_move,    effect_D5_move,    effect_D6_move,    effect_D7_move,
    effect_D8_move,    effect_D9_move,    effect_E0_move,    effect_E1_move,    effect_E2_move,    effect_E3_move,
    effect_E4_move,    effect_E5_move,    effect_E6_move,    effect_E7_move,    effect_E8_move,    effect_E9_move,
    effect_F0_move,    effect_dummy_move, effect_F2_move,    effect_dummy_move, effect_F4_move,    effect_F5_move,
    effect_F6_move,    effect_dummy_move, effect_F8_move,    effect_F9_move,    effect_G0_move,    effect_dummy_move,
    effect_dummy_move, effect_G3_move,    effect_G4_move,    effect_G5_move,    effect_G6_move,    effect_G7_move,
    effect_G8_move,    effect_G9_move,    effect_H0_move,    effect_H1_move,    effect_H2_move,    effect_dummy_move,
    effect_dummy_move, effect_dummy_move, effect_H6_move,    effect_dummy_move, effect_dummy_move, effect_H9_move,
    effect_I0_move,    effect_dummy_move, effect_dummy_move, effect_I3_move,    effect_I4_move,    effect_dummy_move,
    effect_I6_move,    effect_I7_move,    effect_I8_move,    effect_I9_move,    effect_J0_move,    effect_dummy_move,
    effect_J2_move,    effect_dummy_move, effect_J4_move,    effect_dummy_move, effect_J6_move,    effect_J7_move,
    effect_J8_move,    effect_J9_move,    effect_dummy_move, effect_dummy_move, effect_K2_move,    effect_K3_move,
    effect_K4_move,    effect_K5_move,    effect_K6_move,    effect_K7_move,    effect_K8_move,    effect_K9_move,
    effect_L0_move,    effect_L1_move,    effect_L2_move,    effect_L3_move,    effect_L4_move,    effect_L5_move,
    effect_L6_move,    effect_L7_move,    effect_L8_move,    effect_L9_move,    effect_M0_move,    effect_M1_move,
    effect_M2_move,    effect_M3_move,    effect_dummy_move, effect_M5_move,    effect_M6_move,    effect_M7_move,
    effect_M8_move,
};

const s32 (*effinitjptbl[59])() = {
    NULL,
    effect_03_init,
    effect_13_init,
    effect_09_init,
    effect_G7_init,
    effect_C0_init,
    effect_C7_init,
    effect_D0_init,
    effect_D1_init,
    effect_F4_init,
    effect_34_init,
    effect_37_init,
    effect_09_init2,
    effect_41_init,
    effect_D4_init,
    set_tenguiwa,
    effect_D9_init,
    setup_accessories,
    setup_after_images,
    erase_after_images,
    effect_dummy_init,
    clear_caution_flag,
    setup_status_flag,
    reset_extra_bg_flag,
    flip_my_rl_flag,
    effect_F8_init,
    clear_caution_flag,
    effect_G3_init,
    effect_G4_init,
    setup_ase_extra,
    effect_G6_init,
    setup_meoshi_hit_flag,
    exec_char_asxy,
    set_caution_flag,
    setup_my_clear_level,
    setup_my_bright_level,
    effect_dummy_init,
    setup_free_program,
    setup_bg_quake_x,
    setup_bg_quake_y,
    effect_47_init,
    setup_koishi_extra,
    effect_77_init,
    setup_exdm_ix,
    setup_dmv_use_flag,
    effect_D5_init,
    effect_D6_init,
    setup_disp_flag,
    setup_command_number,
    effect_I7_init,
    effect_dummy_init,
    setup_sa_shadow,
    effect_73_init,
    effect_K8_init,
    effect_K9_init,
    effect_L7_init,
    effect_M2_init,
    effect_M8_init,
    effect_F0_init,
};

s32 effect_dummy_init() {
    return -1;
}

void effect_dummy_move() {
    // Do nothing
}
