/* Xbox-only functions of this object (analysis-ps2map/xbgen.py checked each). */
s32 sort_push_request3(WORK* wk);
s32 sort_push_request4(WORK* wk);
void Att_DUMMY();
void xb_effect_01_draw();
void xb_effect_02_draw();
void xb_effect_03_draw();
void xb_effect_04_draw();
void xb_effect_05_draw();
void xb_effect_06_draw();
void xb_effect_07_draw();
void xb_effect_09_draw();
void xb_effect_11_draw();
void xb_effect_12_draw();
void xb_effect_13_draw();
void xb_effect_15_draw();
void xb_effect_17_draw();
void xb_effect_19_draw();
void xb_effect_20_draw();
void xb_effect_21_draw();
void xb_effect_22_draw();
void xb_effect_24_draw();
void xb_effect_25_draw();
void xb_effect_26_draw();
void xb_effect_27_draw();
void xb_effect_29_draw();
void xb_effect_32_draw();
void xb_effect_37_draw();
void xb_effect_38_draw();
void xb_effect_41_draw();
void xb_effect_42_draw();
void xb_effect_43_draw();
void xb_effect_45_draw();
void xb_effect_47_draw();
void xb_effect_50_draw();
void xb_effect_51_draw();
void xb_effect_53_draw();
void xb_effect_54_draw();
void xb_effect_55_draw();
void xb_effect_56_draw();
void xb_effect_57_draw();
void xb_effect_59_draw();
void xb_effect_60_draw();
void xb_effect_62_draw();
void xb_effect_66_draw();
void xb_effect_67_draw();
void xb_effect_68_draw();
void xb_effect_70_draw();
void xb_effect_73_draw();
void xb_effect_76_draw();
void xb_effect_78_draw();
void xb_effect_79_draw();
void xb_effect_80_draw();
void xb_effect_81_draw();
void xb_effect_85_draw();
void xb_effect_86_draw();
void xb_effect_92_draw();
void xb_effect_94_draw();
void xb_effect_95_draw();
void xb_effect_96_draw();
void xb_effect_97_draw();
void xb_effect_A2_draw();
void xb_effect_A7_draw();
void xb_effect_B3_draw();
void xb_effect_B5_draw();
void xb_effect_B8_draw();
void xb_effect_B9_draw();
void xb_effect_C0_draw();
void xb_effect_C5_draw();
void xb_effect_C6_draw();
void xb_effect_C7_draw();
void xb_effect_C8_draw();
void xb_effect_C9_draw();
void xb_effect_D0_draw();
void xb_effect_D1_draw();
void xb_effect_D3_draw();
void xb_effect_D5_draw();
void xb_effect_E2_draw();
void xb_effect_E5_draw();
void xb_effect_E7_draw();
void xb_effect_E8_draw();
void xb_effect_F0_draw();
void xb_effect_G0_draw();
void xb_effect_G5_draw();
void xb_effect_G8_draw();
void xb_effect_H2_draw();
void xb_effect_I0_draw();
void xb_effect_I6_draw();
void xb_effect_J4_draw();
void xb_effect_J6_draw();
void xb_effect_K8_draw();
void xb_effect_L1_draw();
void xb_effect_L2_draw();
void xb_effect_L3_draw();
void xb_effect_L4_draw();
void xb_effect_L5_draw();
void xb_effect_L6_draw();
void xb_effect_L7_draw();
void xb_effect_M3_draw();
void xb_effect_M7_draw();
/* D_0025B2C0 is 0x25B2C0. */
void (*const D_0025B2C0[230])(WORK* wk) = {
    Att_DUMMY, xb_effect_01_draw, xb_effect_02_draw, xb_effect_03_draw, xb_effect_04_draw,
    xb_effect_05_draw, xb_effect_06_draw, xb_effect_07_draw, Att_DUMMY, xb_effect_09_draw,
    Att_DUMMY, xb_effect_11_draw, xb_effect_12_draw, xb_effect_13_draw, Att_DUMMY,
    xb_effect_15_draw, Att_DUMMY, xb_effect_17_draw, Att_DUMMY, xb_effect_19_draw,
    xb_effect_20_draw, xb_effect_21_draw, xb_effect_22_draw, Att_DUMMY, xb_effect_24_draw,
    xb_effect_25_draw, xb_effect_26_draw, xb_effect_27_draw, Att_DUMMY, xb_effect_29_draw,
    xb_effect_32_draw, xb_effect_32_draw, xb_effect_32_draw, xb_effect_32_draw, xb_effect_32_draw,
    Att_DUMMY, Att_DUMMY, xb_effect_37_draw, xb_effect_38_draw, xb_effect_38_draw, Att_DUMMY,
    xb_effect_41_draw, xb_effect_42_draw, xb_effect_43_draw, xb_effect_06_draw, xb_effect_45_draw,
    xb_effect_41_draw, xb_effect_47_draw, Att_DUMMY, Att_DUMMY, xb_effect_50_draw,
    xb_effect_51_draw, xb_effect_42_draw, xb_effect_53_draw, xb_effect_54_draw, xb_effect_55_draw,
    xb_effect_56_draw, xb_effect_57_draw, Att_DUMMY, xb_effect_59_draw, xb_effect_60_draw,
    xb_effect_45_draw, xb_effect_62_draw, Att_DUMMY, xb_effect_45_draw, Att_DUMMY,
    xb_effect_66_draw, xb_effect_67_draw, xb_effect_68_draw, xb_effect_38_draw, xb_effect_70_draw,
    xb_effect_53_draw, xb_effect_19_draw, xb_effect_73_draw, Att_DUMMY, xb_effect_38_draw,
    xb_effect_76_draw, Att_DUMMY, xb_effect_78_draw, xb_effect_79_draw, xb_effect_80_draw,
    xb_effect_81_draw, xb_effect_32_draw, xb_effect_32_draw, Att_DUMMY, xb_effect_85_draw,
    xb_effect_86_draw, Att_DUMMY, Att_DUMMY, Att_DUMMY, Att_DUMMY, xb_effect_42_draw,
    xb_effect_92_draw, Att_DUMMY, xb_effect_94_draw, xb_effect_95_draw, xb_effect_96_draw,
    xb_effect_97_draw, xb_effect_17_draw, Att_DUMMY, xb_effect_51_draw, Att_DUMMY,
    xb_effect_A2_draw, Att_DUMMY, Att_DUMMY, Att_DUMMY, xb_effect_51_draw, xb_effect_A7_draw,
    Att_DUMMY, xb_effect_79_draw, Att_DUMMY, Att_DUMMY, Att_DUMMY, xb_effect_B3_draw,
    xb_effect_41_draw, xb_effect_B5_draw, Att_DUMMY, xb_effect_B5_draw, xb_effect_B8_draw,
    xb_effect_B9_draw, xb_effect_C0_draw, xb_effect_32_draw, Att_DUMMY, Att_DUMMY,
    xb_effect_51_draw, xb_effect_C5_draw, xb_effect_C6_draw, xb_effect_C7_draw, xb_effect_C8_draw,
    xb_effect_C9_draw, xb_effect_D0_draw, xb_effect_D1_draw, Att_DUMMY, xb_effect_D3_draw,
    Att_DUMMY, xb_effect_D5_draw, xb_effect_41_draw, xb_effect_41_draw, xb_effect_17_draw,
    Att_DUMMY, Att_DUMMY, Att_DUMMY, xb_effect_E2_draw, Att_DUMMY, Att_DUMMY, xb_effect_E5_draw,
    Att_DUMMY, xb_effect_E7_draw, xb_effect_E8_draw, Att_DUMMY, xb_effect_F0_draw, Att_DUMMY,
    Att_DUMMY, Att_DUMMY, Att_DUMMY, Att_DUMMY, xb_effect_86_draw, Att_DUMMY, xb_effect_D5_draw,
    Att_DUMMY, xb_effect_G0_draw, Att_DUMMY, Att_DUMMY, xb_effect_41_draw, xb_effect_41_draw,
    xb_effect_G5_draw, Att_DUMMY, Att_DUMMY, xb_effect_G8_draw, xb_effect_G5_draw, Att_DUMMY,
    Att_DUMMY, xb_effect_H2_draw, Att_DUMMY, Att_DUMMY, Att_DUMMY, Att_DUMMY, Att_DUMMY, Att_DUMMY,
    Att_DUMMY, xb_effect_I0_draw, Att_DUMMY, Att_DUMMY, Att_DUMMY, xb_effect_22_draw, Att_DUMMY,
    xb_effect_I6_draw, xb_effect_D5_draw, Att_DUMMY, Att_DUMMY, xb_effect_D5_draw, Att_DUMMY,
    Att_DUMMY, Att_DUMMY, xb_effect_J4_draw, Att_DUMMY, xb_effect_J6_draw, Att_DUMMY,
    xb_effect_12_draw, Att_DUMMY, Att_DUMMY, Att_DUMMY, Att_DUMMY, Att_DUMMY, Att_DUMMY, Att_DUMMY,
    xb_effect_G8_draw, Att_DUMMY, xb_effect_K8_draw, xb_effect_41_draw, Att_DUMMY,
    xb_effect_L1_draw, xb_effect_L2_draw, xb_effect_L3_draw, xb_effect_L4_draw, xb_effect_L5_draw,
    xb_effect_L6_draw, xb_effect_L7_draw, Att_DUMMY, xb_effect_20_draw, xb_effect_85_draw,
    xb_effect_L3_draw, xb_effect_L3_draw, xb_effect_M3_draw, Att_DUMMY, xb_effect_C5_draw,
    xb_effect_C6_draw, xb_effect_M7_draw, xb_effect_L7_draw, 0,
};

void xb_effect_67_draw(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        sort_push_request4(&ewk->wu);
        break;

    case 1:
        sort_push_request4(&ewk->wu);
        break;

    case 2:
        sort_push_request3(&ewk->wu);
        break;

    case 3:
        sort_push_request4(&ewk->wu);
        break;

    case 4:
        sort_push_request3(&ewk->wu);
        break;

    case 5:
        sort_push_request4(&ewk->wu);
        break;

    case 6:
        sort_push_request3(&ewk->wu);
        break;
    }
}
