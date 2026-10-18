/* active11.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * Computer11 0xA50A1 size 0x1A.
 * Pattern11_0026 0xA51D6 size 0x4F.
 * Pattern11_0027 0xA5225 size 0x50.
 * Pattern11_0028 0xA5275 size 0x4C.
 * Pattern11_0029 0xA52C1 size 0x4C.
 * Pattern11_0030 0xA530D size 0x47.
 * Pattern11_0031 0xA5354 size 0x46.
 * Pattern11_0032 0xA539A size 0x40.
 * Pattern11_0036 0xA541D size 0x43.
 * Pattern11_0038 0xA5460 size 0x59.
 * Pattern11_0042 0xA5511 size 0x68.
 * Pattern11_0046 0xA563C size 0x8A.
 * Pattern11_0049 0xA56C6 size 0x2F.
 * Pattern11_0052 0xA56F5 size 0x4E.
 * Pattern11_0057 0xA57B4 size 0x85.
 * Pattern11_0062 0xA58A4 size 0x42.
 * Pattern11_0063 0xA58E6 size 0x42.
 * Pattern11_0064 0xA5928 size 0x42.
 * Pattern11_0065 0xA596A size 0x61.
 * Pattern11_0066 0xA59CB size 0x64.
 * Pattern11_0067 0xA5A2F size 0x56.
 * Pattern11_0068 0xA5A85 size 0x4B.
 * Pattern11_0069 0xA5AD0 size 0x42.
 * Pattern11_0070 0xA5B12 size 0x42.
 * Pattern11_0071 0xA5B54 size 0x42.
 * Pattern11_0074 0xA5B96 size 0x30.
 * Pattern11_0076 0xA5BC6 size 0x3B.
 * Pattern11_0081 0xA5C3A size 0x30.
 * Pattern11_0083 0xA5CB1 size 0x30.
 * Pattern11_0084 0xA5CE1 size 0x4B.
 * Pattern11_0085 0xA5D2C size 0x55.
 * Pattern11_0086 0xA5D81 size 0x30.
 * Pattern11_0087 0xA5DB1 size 0x2E.
 * Pattern11_0088 0xA5DDF size 0x2E.
 * Pattern11_0089 0xA5E0D size 0x52.
 * Pattern11_0000 is folded into 0xAB943 with 26 other bodies. Unnamed.
 * Pattern11_0001 is folded into 0x822AE with 19 other bodies. Unnamed.
 * Pattern11_0002 is folded into 0xA50BB with 1 other bodies. Unnamed.
 * Pattern11_0003 is folded into 0xA50FC with 1 other bodies. Unnamed.
 * Pattern11_0005 is folded into 0xE1C20 with 9 other bodies. Unnamed.
 * Pattern11_0006 is folded into 0xE33DD with 8 other bodies. Unnamed.
 * Pattern11_0007 is folded into 0xE3409 with 7 other bodies. Unnamed.
 * Pattern11_0008 is folded into 0x7A0DC with 7 other bodies. Unnamed.
 * Pattern11_0009 is folded into 0x80F0F with 4 other bodies. Unnamed.
 * Pattern11_0010 is folded into 0x8107D with 4 other bodies. Unnamed.
 * Pattern11_0011 is folded into 0xA5181 with 4 other bodies. Unnamed.
 * Pattern11_0012 is folded into 0xD47E2 with 16 other bodies. Unnamed.
 * Pattern11_0013 is folded into 0x71E79 with 17 other bodies. Unnamed.
 * Pattern11_0014 is folded into 0xA5E79 with 3 other bodies. Unnamed.
 * Pattern11_0015 is folded into 0xA9FA1 with 15 other bodies. Unnamed.
 * Pattern11_0016 is folded into 0x6D0A6 with 21 other bodies. Unnamed.
 * Pattern11_0017 is folded into 0xE2326 with 9 other bodies. Unnamed.
 * Pattern11_0018 is folded into 0xE22FA with 8 other bodies. Unnamed.
 * Pattern11_0019 is folded into 0x8078E with 8 other bodies. Unnamed.
 * Pattern11_0021 is folded into 0xA9FF7 with 21 other bodies. Unnamed.
 * Pattern11_0022 is folded into 0xA9FCC with 23 other bodies. Unnamed.
 * Pattern11_0023 is folded into 0xE33B0 with 8 other bodies. Unnamed.
 * Pattern11_0024 is folded into 0x8303D with 4 other bodies. Unnamed.
 * Pattern11_0025 is folded into 0xDAC4C with 14 other bodies. Unnamed.
 * Pattern11_0034 is folded into 0xA60B5 with 1 other bodies. Unnamed.
 * Pattern11_0037 is folded into 0x81182 with 2 other bodies. Unnamed.
 * Pattern11_0040 is folded into 0xA54B9 with 1 other bodies. Unnamed.
 * Pattern11_0043 is folded into 0x80231 with 1 other bodies. Unnamed.
 * Pattern11_0044 is folded into 0xA5579 with 4 other bodies. Unnamed.
 * Pattern11_0047 is folded into 0x80741 with 3 other bodies. Unnamed.
 * Pattern11_0048 is folded into 0x9E7DC with 10 other bodies. Unnamed.
 * Pattern11_0050 is folded into 0xAA823 with 7 other bodies. Unnamed.
 * Pattern11_0051 is folded into 0xA638F with 1 other bodies. Unnamed.
 * Pattern11_0054 is folded into 0x9F53F with 2 other bodies. Unnamed.
 * Pattern11_0055 is folded into 0xA576B with 2 other bodies. Unnamed.
 * Pattern11_0056 is folded into 0xA9A3E with 10 other bodies. Unnamed.
 * Pattern11_0059 is folded into 0xAA09A with 6 other bodies. Unnamed.
 * Pattern11_0060 is folded into 0xA5879 with 6 other bodies. Unnamed.
 * Pattern11_0061 is folded into 0x73AC3 with 3 other bodies. Unnamed.
 * Pattern11_0075 is folded into 0xD2718 with 15 other bodies. Unnamed.
 * Pattern11_0078 is folded into 0x9E572 with 6 other bodies. Unnamed.
 * Pattern11_0080 is folded into 0xA5C01 with 1 other bodies. Unnamed.
 * Pattern11_0033 is folded into 0x7EC16 with 1 other bodies. Unnamed.
 * Pattern11_0041 is folded into 0x7F0C0 with 1 other bodies. Unnamed.
 * Pattern11_0039 is folded into 0x80999 with 1 other bodies. Unnamed.
 * Pattern11_0073 is folded into 0x81C23 with 1 other bodies. Unnamed.
 * Pattern11_0077 is folded into 0x81DE6 with 1 other bodies. Unnamed.
 * Pattern11_0079 is folded into 0x81E13 with 1 other bodies. Unnamed.
 * Pattern11_0004 is folded into 0xA513D with 1 other bodies. Unnamed.
 * Pattern11_0020 is folded into 0xA51A9 with 2 other bodies. Unnamed.
 * Pattern11_0035 is folded into 0xA53DA with 1 other bodies. Unnamed.
 * Pattern11_0045 is folded into 0xA55D3 with 1 other bodies. Unnamed.
 * Pattern11_0053 is folded into 0xA5743 with 1 other bodies. Unnamed.
 * Pattern11_0058 is folded into 0xA5839 with 1 other bodies. Unnamed.
 * Pattern11_0082 is folded into 0xA5C6A with 1 other bodies. Unnamed.
 * Pattern11_0072 is folded into 0x81BE5 with 2 other bodies. Unnamed.
 * Data: Pattern11_Tbl is 0x26EA80, 90 entries compared.
 * Globals: Pattern11_Tbl 0x26EA80, Pattern_Index 0x7A80C8, CP_Index 0x7A85B0.
 */

#include "structs.h"

void Pattern11_0000(PLW* wk);
void Pattern11_0001(PLW* wk);
void Pattern11_0002(PLW* wk);
void Pattern11_0003(PLW* wk);
void Pattern11_0004(PLW* wk);
void Pattern11_0005(PLW* wk);
void Pattern11_0006(PLW* wk);
void Pattern11_0007(PLW* wk);
void Pattern11_0008(PLW* wk);
void Pattern11_0009(PLW* wk);
void Pattern11_0010(PLW* wk);
void Pattern11_0011(PLW* wk);
void Pattern11_0012(PLW* wk);
void Pattern11_0013(PLW* wk);
void Pattern11_0014(PLW* wk);
void Pattern11_0015(PLW* wk);
void Pattern11_0016(PLW* wk);
void Pattern11_0017(PLW* wk);
void Pattern11_0018(PLW* wk);
void Pattern11_0019(PLW* wk);
void Pattern11_0020(PLW* wk);
void Pattern11_0021(PLW* wk);
void Pattern11_0022(PLW* wk);
void Pattern11_0023(PLW* wk);
void Pattern11_0024(PLW* wk);
void Pattern11_0025(PLW* wk);
void Pattern11_0026(PLW* wk);
void Pattern11_0027(PLW* wk);
void Pattern11_0028(PLW* wk);
void Pattern11_0029(PLW* wk);
void Pattern11_0030(PLW* wk);
void Pattern11_0031(PLW* wk);
void Pattern11_0032(PLW* wk);
void Pattern11_0033(PLW* wk);
void Pattern11_0034(PLW* wk);
void Pattern11_0035(PLW* wk);
void Pattern11_0036(PLW* wk);
void Pattern11_0037(PLW* wk);
void Pattern11_0038(PLW* wk);
void Pattern11_0039(PLW* wk);
void Pattern11_0040(PLW* wk);
void Pattern11_0041(PLW* wk);
void Pattern11_0042(PLW* wk);
void Pattern11_0043(PLW* wk);
void Pattern11_0044(PLW* wk);
void Pattern11_0045(PLW* wk);
void Pattern11_0046(PLW* wk);
void Pattern11_0047(PLW* wk);
void Pattern11_0048(PLW* wk);
void Pattern11_0049(PLW* wk);
void Pattern11_0050(PLW* wk);
void Pattern11_0051(PLW* wk);
void Pattern11_0052(PLW* wk);
void Pattern11_0053(PLW* wk);
void Pattern11_0054(PLW* wk);
void Pattern11_0055(PLW* wk);
void Pattern11_0056(PLW* wk);
void Pattern11_0057(PLW* wk);
void Pattern11_0058(PLW* wk);
void Pattern11_0059(PLW* wk);
void Pattern11_0060(PLW* wk);
void Pattern11_0061(PLW* wk);
void Pattern11_0062(PLW* wk);
void Pattern11_0063(PLW* wk);
void Pattern11_0064(PLW* wk);
void Pattern11_0065(PLW* wk);
void Pattern11_0066(PLW* wk);
void Pattern11_0067(PLW* wk);
void Pattern11_0068(PLW* wk);
void Pattern11_0069(PLW* wk);
void Pattern11_0070(PLW* wk);
void Pattern11_0071(PLW* wk);
void Pattern11_0072(PLW* wk);
void Pattern11_0073(PLW* wk);
void Pattern11_0074(PLW* wk);
void Pattern11_0075(PLW* wk);
void Pattern11_0076(PLW* wk);
void Pattern11_0077(PLW* wk);
void Pattern11_0078(PLW* wk);
void Pattern11_0079(PLW* wk);
void Pattern11_0080(PLW* wk);
void Pattern11_0081(PLW* wk);
void Pattern11_0082(PLW* wk);
void Pattern11_0083(PLW* wk);
void Pattern11_0084(PLW* wk);
void Pattern11_0085(PLW* wk);
void Pattern11_0086(PLW* wk);
void Pattern11_0087(PLW* wk);
void Pattern11_0088(PLW* wk);
void Pattern11_0089(PLW* wk);
extern u16 Pattern_Index[2];
extern u8 CP_Index[2][8];
void Lever_Off(PLW* wk);
void Look(PLW* wk, s16 Time);
void End_Pattern(PLW* wk);
void Wait(PLW* wk, s16 Time);
void Approach_Walk(PLW* wk, s16 Target_Pos, s16 Option);
void Lever_Attack(PLW* wk, s16 Reaction, u16 Lever, u16 Lever_Data);
void J_Command_Attack(PLW* wk, s16 Reaction, u16 Tech_Number, s16 Power_Level, s16 Ex_Shot);
void Normal_Attack(PLW* wk, s16 Reaction, u16 Lever_Data);
void Command_Attack(PLW* wk, s16 Reaction, u16 Tech_Number, s16 Power_Level, s16 Ex_Shot);
void Normal_Attack_SP(PLW* wk, s16 Reaction, u16 Lever_Data, s16 Time);
void Jump(PLW* wk, s16 Time);
void Walk(PLW* wk, u16 Lever, s16 Time, s16 unused);
void ETC_Term(PLW* wk, s16 Exit_No, u32 Next_Action, u16 Next_Menu);
void Next_Another_Menu(PLW* wk, s16 Next_Action, u16 Next_Menu);
void Keep_Away(PLW* wk, s16 Target_Pos, s16 Option);
void Pierce_On(PLW* wk);
void Com_Random_Select(PLW* wk, s16 Next_Action, s16 Menu_00, s16 Menu_01, s16 Menu_02, s16 Menu_03, s16 Rnd_Type);
void SA_Term(PLW* wk, u16 SA0, u16 SA1, u16 SA2, u16 Term_No);
void Jump_Attack_Term(PLW* wk, s16 Range_X, s16 Range_Y, s16 Reaction, u16 Lever_Data, s16 Jump_Dir, s16 Range_JX, s16 Range_JY, s16 J_Lever_Data);
void Jump_Command_Attack_Term(PLW* wk, s16 Reaction, u16 Tech_Number, s16 Power_Level, s16 Ex_Shot, s16 RX, s16 RY, s16 Jump_Dir, s16 JRX, s16 JRY, u16 JLD);
void Hi_Jump_Command_Attack_Term(PLW* wk, s16 Reaction, u16 Tech_Number, s16 Power_Level, s16 Ex_Shot, s16 RX, s16 RY, s16 Jump_Dir, s16 JRX, s16 JRY, u16 JLD);
void Provoke(PLW* wk, s16 Lever);
void Lever_Attack_SP(PLW* wk, s16 Reaction, u16 Lever, u16 Lever_Data, s16 Time);
void Lever_On(PLW* wk, u16 LR_Lever, u16 UD_Lever);
void Branch_Unit_Area(PLW* wk, s16 Next_Action, s16 Menu, s16 Menu_01, s16 Menu_02, s16 Menu_03);

void (*const Pattern11_Tbl[90])();

void (*const Pattern11_Tbl[90])(PLW*) = {
    Pattern11_0000, Pattern11_0001, Pattern11_0002, Pattern11_0003, Pattern11_0004, Pattern11_0005, Pattern11_0006,
    Pattern11_0007, Pattern11_0008, Pattern11_0009, Pattern11_0010, Pattern11_0011, Pattern11_0012, Pattern11_0013,
    Pattern11_0014, Pattern11_0015, Pattern11_0016, Pattern11_0017, Pattern11_0018, Pattern11_0019, Pattern11_0020,
    Pattern11_0021, Pattern11_0022, Pattern11_0023, Pattern11_0024, Pattern11_0025, Pattern11_0026, Pattern11_0027,
    Pattern11_0028, Pattern11_0029, Pattern11_0030, Pattern11_0031, Pattern11_0032, Pattern11_0033, Pattern11_0034,
    Pattern11_0035, Pattern11_0036, Pattern11_0037, Pattern11_0038, Pattern11_0039, Pattern11_0040, Pattern11_0041,
    Pattern11_0042, Pattern11_0043, Pattern11_0044, Pattern11_0045, Pattern11_0046, Pattern11_0047, Pattern11_0048,
    Pattern11_0049, Pattern11_0050, Pattern11_0051, Pattern11_0052, Pattern11_0053, Pattern11_0054, Pattern11_0055,
    Pattern11_0056, Pattern11_0057, Pattern11_0058, Pattern11_0059, Pattern11_0060, Pattern11_0061, Pattern11_0062,
    Pattern11_0063, Pattern11_0064, Pattern11_0065, Pattern11_0066, Pattern11_0067, Pattern11_0068, Pattern11_0069,
    Pattern11_0070, Pattern11_0071, Pattern11_0072, Pattern11_0073, Pattern11_0074, Pattern11_0075, Pattern11_0076,
    Pattern11_0077, Pattern11_0078, Pattern11_0079, Pattern11_0080, Pattern11_0081, Pattern11_0082, Pattern11_0083,
    Pattern11_0084, Pattern11_0085, Pattern11_0086, Pattern11_0087, Pattern11_0088, Pattern11_0089
};

void Computer11(PLW* wk) {
    Pattern11_Tbl[(s16)Pattern_Index[wk->wu.id]](wk);
}

void Pattern11_0000(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Off(wk);
        break;

    case 1:
        Look(wk, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern11_0001(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern11_0002(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;

    case 1:
        Lever_Attack(wk, 8, 0, 0x110);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern11_0003(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;

    case 1:
        Lever_Attack(wk, 8, 1, 0x110);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern11_0004(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;

    case 1:
        Lever_Attack(wk, 8, 0xFFFF, 0x110);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern11_0005(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1C, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern11_0006(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1C, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern11_0007(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern11_0008(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern11_0009(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1E, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern11_0010(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern11_0011(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x10);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern11_0012(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern11_0013(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x40);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern11_0014(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x100);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern11_0015(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern11_0016(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern11_0017(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1D, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern11_0018(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1D, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern11_0019(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern11_0020(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack_SP(wk, 8, 0x200, 0x12);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern11_0021(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x202);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern11_0022(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x402);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern11_0023(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern11_0024(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0, -1, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern11_0025(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump(wk, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern11_0026(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 1, 0x20, -1);
        break;

    case 1:
        ETC_Term(wk, 4, 2, 0x13);
        break;

    case 2:
        Next_Another_Menu(wk, 2, 0x37);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern11_0027(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Away(wk, 0xBF, 1);
        break;

    case 1:
        ETC_Term(wk, 4, 2, 0x13);
        break;

    case 2:
        Next_Another_Menu(wk, 2, 0x37);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern11_0028(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;

    case 1:
        Jump(wk, 0);
        break;

    case 2:
        Com_Random_Select(wk, 2, 0x53, 0x4D, 0x20, 0xA, 4);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern11_0029(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;

    case 1:
        Jump(wk, 0);
        break;

    case 2:
        Com_Random_Select(wk, 2, 0x53, 0x4E, 0x51, 0x59, 1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern11_0030(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Away(wk, 0xBF, 1);
        break;

    case 1:
        Com_Random_Select(wk, 2, 0x11, 0, 0x56, 0x2F, 3);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern11_0031(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 1, 0x20, -1);
        break;

    case 1:
        Com_Random_Select(wk, 2, 0x11, 0, 0x24, 0x23, 3);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern11_0032(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x20);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern11_0033(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;

    case 1:
        SA_Term(wk, 0x30, 0x31, 0x32, 0x7F);
        break;

    case 2:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern11_0034(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Away(wk, 0xBF, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern11_0035(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xB, 0x202);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1D, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern11_0036(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x400);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern11_0037(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xC, 0x40);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern11_0038(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1C, 8, -1);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1C, 9, -1);
        break;

    case 2:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;

    case 3:
        Com_Random_Select(wk, 2, 0, 0xA, 0x13, 0x1F, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern11_0039(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;

    case 1:
        Normal_Attack(wk, 0xC, 0x40);
        break;

    case 2:
        SA_Term(wk, 0x30, 0x31, 0x32, 0x7F);
        break;

    case 3:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern11_0040(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA8, -0x7FC0, 9, 0x20, 0, -0x7FB0, -1, 0x200);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1C, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern11_0041(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA8, -0x7FC0, 9, 0x200, 0, -0x7FB0, -1, 0x20);
        break;

    case 1:
        Normal_Attack(wk, 0xB, 0x20);
        break;

    case 2:
        J_Command_Attack(wk, 8, 0x1E, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern11_0042(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA8, -0x7FC0, 0xB, 0x200, 0, -1, -1, -1);
        break;

    case 1:
        SA_Term(wk, 0x30, 0x31, 0x32, 0x7F);
        break;

    case 2:
        Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern11_0043(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA8, -0x7FC0, 0xB, 0x200, 0, -0x7FB0, -1, 0x40);
        break;

    case 1:
        Normal_Attack(wk, 0xB, 0x400);
        break;

    case 2:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern11_0044(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA0, -0x7FC0, 9, 0x400, 0, -0x7FB0, -1, 0x200);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x402);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern11_0045(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA0, -0x7FC0, 9, 0x40, 0, -0x7FB0, -1, 0x200);
        break;

    case 1:
        Normal_Attack(wk, 9, 0x40);
        break;

    case 2:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern11_0046(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA0, -0x7FC0, 9, 0x40, 0, -0x7FB0, -1, 0x200);
        break;

    case 1:
        Normal_Attack(wk, 9, 0x40);
        break;

    case 2:
        Command_Attack(wk, 0xC, 0x1D, 0xA, -1);
        break;

    case 3:
        Wait(wk, 0xA);
        break;

    case 4:
        SA_Term(wk, 0x30, 0x31, 0x32, 0x7F);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern11_0047(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;

    case 1:
        Command_Attack(wk, 0xC, 0, -1, -1);
        break;

    case 2:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern11_0048(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8014, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern11_0049(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x8115, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern11_0050(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8016, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern11_0051(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Away(wk, 0x7F, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern11_0052(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x402);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern11_0053(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern11_0054(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x10);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x10);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern11_0055(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x10);
        break;

    case 1:
        Normal_Attack(wk, 0xB, 0x10);
        break;

    case 2:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern11_0056(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x7F, 2);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern11_0057(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA8, -0x7FC0, 9, 0x20, 0, -0x7FB0, -1, 0x200);
        break;

    case 1:
        Normal_Attack(wk, 9, 0x12);
        break;

    case 2:
        Normal_Attack(wk, 9, 0x102);
        break;

    case 3:
        Normal_Attack(wk, 8, 0x202);
        break;

    case 4:
        Com_Random_Select(wk, 2, 0x2D, 0x13, 0x13, 0xFF, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern11_0058(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA8, -0x7FC0, 9, 0x200, 0, -0x7FB0, -1, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern11_0059(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBF, 2);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern11_0060(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x102);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern11_0061(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x12);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern11_0062(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ETC_Term(wk, 3, 2, 0x11);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern11_0063(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ETC_Term(wk, 3, 2, 0x12);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1E, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern11_0064(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ETC_Term(wk, 3, 2, 0x13);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern11_0065(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;

    case 2:
        Normal_Attack(wk, 0xC, 0x202);
        break;

    case 3:
        Command_Attack(wk, 8, 0x1D, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern11_0066(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1C, 8, -1);
        break;

    case 2:
        J_Command_Attack(wk, 8, 0x1C, 9, -1);
        break;

    case 3:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;

    case 4:
        Com_Random_Select(wk, 2, 0, 0xA, 0x13, 0x1F, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern11_0067(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1C, 8, -1);
        break;

    case 2:
        J_Command_Attack(wk, 8, 0x1C, 9, -1);
        break;

    case 3:
        Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern11_0068(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1C, 8, -1);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1C, 9, -1);
        break;

    case 2:
        Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern11_0069(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ETC_Term(wk, 3, 2, 0);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern11_0070(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ETC_Term(wk, 3, 2, 0);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1E, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern11_0071(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ETC_Term(wk, 3, 2, 0);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern11_0072(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x1E, 0xA, 0x700, -1, 0x30, 0, -1, -1, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern11_0073(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Command_Attack_Term(wk, 8, 0x1E, 0xA, 0x700, -1, 0x30, 0, -1, -1, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern11_0074(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 2, 0xA, 0x48, 0x48, 0x49, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern11_0075(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Provoke(wk, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern11_0076(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ETC_Term(wk, 5, 6, 0);
        break;

    case 1:
        Provoke(wk, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern11_0077(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 1, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern11_0078(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern11_0079(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack_SP(wk, 8, 0, 0x400, 0x12);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern11_0080(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_On(wk, 1, 2);
        break;

    case 1:
        Look(wk, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern11_0081(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 2, 0x4D, 0x4E, 0x14, 0x17, 3);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern11_0082(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;

    case 1:
        Lever_Attack(wk, 8, 0, 0x400);
        break;

    case 2:
        Lever_Attack(wk, 8, 1, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern11_0083(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 2, 0x53, 0x54, 0x55, 0x55, 4);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern11_0084(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack_SP(wk, 8, 0, 0x400, 0x12);
        break;

    case 1:
        Com_Random_Select(wk, 2, 2, 3, 4, 4, 4);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern11_0085(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;

    case 1:
        Lever_Attack_SP(wk, 8, 0, 0x400, 0x12);
        break;

    case 2:
        Com_Random_Select(wk, 2, 0x25, 0x23, 0x52, 0x41, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern11_0086(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 2, 0x4D, 0x4E, 0x10, 0x14, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern11_0087(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 6, 0, 0, 0, 0x50, 3);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern11_0088(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 6, 0x50, 0, 0, 0, 2);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern11_0089(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ETC_Term(wk, 5, 6, 0x57);
        break;

    case 1:
        Branch_Unit_Area(wk, 2, 0x53, 0x56, 0x55, 0x4C);
        break;

    case 2:
        Provoke(wk, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}
