/* active03.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * Computer03 0x9F525 size 0x1A.
 * Pattern03_0020 0x9F718 size 0x45.
 * Pattern03_0030 0x9F8C7 size 0x52.
 * Pattern03_0032 0x9F919 size 0x40.
 * Pattern03_0034 0x9F959 size 0x43.
 * Pattern03_0037 0x9F99C size 0x40.
 * Pattern03_0039 0x9F9DC size 0x46.
 * Pattern03_0040 0x9FA22 size 0x43.
 * Pattern03_0041 0x9FA65 size 0x40.
 * Pattern03_0053 0x9FBE1 size 0x45.
 * Pattern03_0065 0x9FDA1 size 0x43.
 * Pattern03_0067 0x9FE14 size 0x2E.
 * Pattern03_0071 is folded into 0x71360 with 1 other bodies. Unnamed.
 * Pattern03_0070 is folded into 0x8078E with 6 other bodies. Unnamed.
 * Pattern03_0019 is folded into 0x9E8D7 with 2 other bodies. Unnamed.
 * Pattern03_0001 is folded into 0x9F53F with 1 other bodies. Unnamed.
 * Pattern03_0002 is folded into 0x9F56D with 1 other bodies. Unnamed.
 * Pattern03_0008 is folded into 0x9F5D5 with 1 other bodies. Unnamed.
 * Pattern03_0014 is folded into 0x9F649 with 1 other bodies. Unnamed.
 * Pattern03_0016 is folded into 0x9F6AC with 1 other bodies. Unnamed.
 * Pattern03_0018 is folded into 0x9F6E9 with 1 other bodies. Unnamed.
 * Pattern03_0021 is folded into 0x9F75D with 1 other bodies. Unnamed.
 * Pattern03_0022 is folded into 0x9F79A with 1 other bodies. Unnamed.
 * Pattern03_0024 is folded into 0x9F805 with 1 other bodies. Unnamed.
 * Pattern03_0029 is folded into 0x9F86D with 1 other bodies. Unnamed.
 * Pattern03_0043 is folded into 0x9FAA5 with 1 other bodies. Unnamed.
 * Pattern03_0044 is folded into 0x9FAE2 with 1 other bodies. Unnamed.
 * Pattern03_0045 is folded into 0x9FB1F with 1 other bodies. Unnamed.
 * Pattern03_0050 is folded into 0x9FB89 with 6 other bodies. Unnamed.
 * Pattern03_0057 is folded into 0x9FC26 with 1 other bodies. Unnamed.
 * Pattern03_0058 is folded into 0x9FC79 with 1 other bodies. Unnamed.
 * Pattern03_0062 is folded into 0x9FD04 with 1 other bodies. Unnamed.
 * Pattern03_0063 is folded into 0x9FD5C with 1 other bodies. Unnamed.
 * Pattern03_0066 is folded into 0x9FDE4 with 1 other bodies. Unnamed.
 * Pattern03_0007 is folded into 0xA4908 with 1 other bodies. Unnamed.
 * Pattern03_0009 is folded into 0xA4955 with 1 other bodies. Unnamed.
 * Pattern03_0031 is folded into 0xA4B13 with 1 other bodies. Unnamed.
 * Pattern03_0038 is folded into 0xA4C15 with 1 other bodies. Unnamed.
 * Pattern03_0042 is folded into 0xA4D54 with 1 other bodies. Unnamed.
 * Pattern03_0054 is folded into 0xA4E1C with 1 other bodies. Unnamed.
 * Pattern03_0055 is folded into 0xA4E73 with 1 other bodies. Unnamed.
 * Pattern03_0056 is folded into 0xA4EAD with 1 other bodies. Unnamed.
 * Pattern03_0059 is folded into 0xA4EF5 with 1 other bodies. Unnamed.
 * Pattern03_0060 is folded into 0xA4F65 with 1 other bodies. Unnamed.
 * Pattern03_0061 is folded into 0xA4FEE with 1 other bodies. Unnamed.
 * Pattern03_0052 is folded into 0xA9D75 with 2 other bodies. Unnamed.
 * Pattern03_0064 is folded into 0xD3DCE with 3 other bodies. Unnamed.
 * Pattern03_0069 is folded into 0xE22FA with 6 other bodies. Unnamed.
 * Pattern03_0068 is folded into 0xE2326 with 8 other bodies. Unnamed.
 * Pattern03_0000 is folded into 0xAB943 with 26 other bodies. Unnamed.
 * Pattern03_0003 is folded into 0x9F59B with 1 other bodies. Unnamed.
 * Pattern03_0004 is folded into 0xE2F43 with 11 other bodies. Unnamed.
 * Pattern03_0005 is folded into 0xDDB8D with 12 other bodies. Unnamed.
 * Pattern03_0006 is folded into 0xA98E2 with 6 other bodies. Unnamed.
 * Pattern03_0010 is folded into 0xA9FCC with 23 other bodies. Unnamed.
 * Pattern03_0011 is folded into 0x9F60F with 4 other bodies. Unnamed.
 * Pattern03_0012 is folded into 0x71E79 with 17 other bodies. Unnamed.
 * Pattern03_0013 is folded into 0xE33B0 with 8 other bodies. Unnamed.
 * Pattern03_0015 is folded into 0x9F683 with 8 other bodies. Unnamed.
 * Pattern03_0017 is folded into 0xA340F with 4 other bodies. Unnamed.
 * Pattern03_0023 is folded into 0x9F7DA with 1 other bodies. Unnamed.
 * Pattern03_0025 is folded into 0xA4A84 with 1 other bodies. Unnamed.
 * Pattern03_0026 is folded into 0x9E60D with 3 other bodies. Unnamed.
 * Pattern03_0027 is folded into 0xDAC4C with 14 other bodies. Unnamed.
 * Pattern03_0028 is folded into 0x9F842 with 1 other bodies. Unnamed.
 * Pattern03_0033 is folded into 0xA4B55 with 1 other bodies. Unnamed.
 * Pattern03_0035 is folded into 0xD47E2 with 16 other bodies. Unnamed.
 * Pattern03_0036 is folded into 0xA9BB4 with 14 other bodies. Unnamed.
 * Pattern03_0046 is folded into 0xAA823 with 7 other bodies. Unnamed.
 * Pattern03_0047 is folded into 0xAA7F4 with 5 other bodies. Unnamed.
 * Pattern03_0048 is folded into 0x9E7DC with 10 other bodies. Unnamed.
 * Pattern03_0049 is folded into 0x9FB5D with 8 other bodies. Unnamed.
 * Pattern03_0051 is folded into 0x9FBB5 with 9 other bodies. Unnamed.
 * Data: Pattern03_Tbl is 0x26E140, 72 entries compared.
 * Globals: Pattern03_Tbl 0x26E140, Pattern_Index 0x7A80C8, CP_Index 0x7A85B0.
 */

#include "structs.h"

void Pattern03_0000(PLW* wk);
void Pattern03_0001(PLW* wk);
void Pattern03_0002(PLW* wk);
void Pattern03_0003(PLW* wk);
void Pattern03_0004(PLW* wk);
void Pattern03_0005(PLW* wk);
void Pattern03_0006(PLW* wk);
void Pattern03_0007(PLW* wk);
void Pattern03_0008(PLW* wk);
void Pattern03_0009(PLW* wk);
void Pattern03_0010(PLW* wk);
void Pattern03_0011(PLW* wk);
void Pattern03_0012(PLW* wk);
void Pattern03_0013(PLW* wk);
void Pattern03_0014(PLW* wk);
void Pattern03_0015(PLW* wk);
void Pattern03_0016(PLW* wk);
void Pattern03_0017(PLW* wk);
void Pattern03_0018(PLW* wk);
void Pattern03_0019(PLW* wk);
void Pattern03_0020(PLW* wk);
void Pattern03_0021(PLW* wk);
void Pattern03_0022(PLW* wk);
void Pattern03_0023(PLW* wk);
void Pattern03_0024(PLW* wk);
void Pattern03_0025(PLW* wk);
void Pattern03_0026(PLW* wk);
void Pattern03_0027(PLW* wk);
void Pattern03_0028(PLW* wk);
void Pattern03_0029(PLW* wk);
void Pattern03_0030(PLW* wk);
void Pattern03_0031(PLW* wk);
void Pattern03_0032(PLW* wk);
void Pattern03_0033(PLW* wk);
void Pattern03_0034(PLW* wk);
void Pattern03_0035(PLW* wk);
void Pattern03_0036(PLW* wk);
void Pattern03_0037(PLW* wk);
void Pattern03_0038(PLW* wk);
void Pattern03_0039(PLW* wk);
void Pattern03_0040(PLW* wk);
void Pattern03_0041(PLW* wk);
void Pattern03_0042(PLW* wk);
void Pattern03_0043(PLW* wk);
void Pattern03_0044(PLW* wk);
void Pattern03_0045(PLW* wk);
void Pattern03_0046(PLW* wk);
void Pattern03_0047(PLW* wk);
void Pattern03_0048(PLW* wk);
void Pattern03_0049(PLW* wk);
void Pattern03_0050(PLW* wk);
void Pattern03_0051(PLW* wk);
void Pattern03_0052(PLW* wk);
void Pattern03_0053(PLW* wk);
void Pattern03_0054(PLW* wk);
void Pattern03_0055(PLW* wk);
void Pattern03_0056(PLW* wk);
void Pattern03_0057(PLW* wk);
void Pattern03_0058(PLW* wk);
void Pattern03_0059(PLW* wk);
void Pattern03_0060(PLW* wk);
void Pattern03_0061(PLW* wk);
void Pattern03_0062(PLW* wk);
void Pattern03_0063(PLW* wk);
void Pattern03_0064(PLW* wk);
void Pattern03_0065(PLW* wk);
void Pattern03_0066(PLW* wk);
void Pattern03_0067(PLW* wk);
void Pattern03_0068(PLW* wk);
void Pattern03_0069(PLW* wk);
void Pattern03_0070(PLW* wk);
void Pattern03_0071(PLW* wk);
extern u16 Pattern_Index[2];
extern u8 CP_Index[2][8];
void Lever_Off(PLW* wk);
void Look(PLW* wk, s16 Time);
void End_Pattern(PLW* wk);
void Normal_Attack(PLW* wk, s16 Reaction, u16 Lever_Data);
void Branch_Unit_Area(PLW* wk, s16 Next_Action, s16 Menu, s16 Menu_01, s16 Menu_02, s16 Menu_03);
void Adjust_Attack(PLW* wk, s16 Reaction, u16 Lever_Data);
void Command_Attack(PLW* wk, s16 Reaction, u16 Tech_Number, s16 Power_Level, s16 Ex_Shot);
void Lever_Attack(PLW* wk, s16 Reaction, u16 Lever, u16 Lever_Data);
void Wait(PLW* wk, s16 Time);
void Search_Back_Term(PLW* wk, s16 Move_Value, s16 Next_Action, s16 Next_Menu);
void Pierce_On(PLW* wk);
void Jump(PLW* wk, s16 Time);
void Jump_Attack_Term(PLW* wk, s16 Range_X, s16 Range_Y, s16 Reaction, u16 Lever_Data, s16 Jump_Dir, s16 Range_JX, s16 Range_JY, s16 J_Lever_Data);
void Walk(PLW* wk, u16 Lever, s16 Time, s16 unused);
void Jump_Attack(PLW* wk, s16 Reaction, s16 Time_Data, u16 Lever_Data, s16 Jump_Dir);
void Hi_Jump_Attack_Term(PLW* wk, s16 Range_X, s16 Range_Y, s16 Reaction, u16 Lever_Data, s16 Jump_Dir, s16 Range_JX, s16 Range_JY, u16 J_Lever_Data);
void Approach_Walk(PLW* wk, s16 Target_Pos, s16 Option);
void J_Command_Attack(PLW* wk, s16 Reaction, u16 Tech_Number, s16 Power_Level, s16 Ex_Shot);
void SA_Term(PLW* wk, u16 SA0, u16 SA1, u16 SA2, u16 Term_No);
void Com_Random_Select(PLW* wk, s16 Next_Action, s16 Menu_00, s16 Menu_01, s16 Menu_02, s16 Menu_03, s16 Rnd_Type);

void (*const Pattern03_Tbl[72])();

void (*const Pattern03_Tbl[72])(PLW*) = {
    Pattern03_0000, Pattern03_0001, Pattern03_0002, Pattern03_0003, Pattern03_0004, Pattern03_0005, Pattern03_0006,
    Pattern03_0007, Pattern03_0008, Pattern03_0009, Pattern03_0010, Pattern03_0011, Pattern03_0012, Pattern03_0013,
    Pattern03_0014, Pattern03_0015, Pattern03_0016, Pattern03_0017, Pattern03_0018, Pattern03_0019, Pattern03_0020,
    Pattern03_0021, Pattern03_0022, Pattern03_0023, Pattern03_0024, Pattern03_0025, Pattern03_0026, Pattern03_0027,
    Pattern03_0028, Pattern03_0029, Pattern03_0030, Pattern03_0031, Pattern03_0032, Pattern03_0033, Pattern03_0034,
    Pattern03_0035, Pattern03_0036, Pattern03_0037, Pattern03_0038, Pattern03_0039, Pattern03_0040, Pattern03_0041,
    Pattern03_0042, Pattern03_0043, Pattern03_0044, Pattern03_0045, Pattern03_0046, Pattern03_0047, Pattern03_0048,
    Pattern03_0049, Pattern03_0050, Pattern03_0051, Pattern03_0052, Pattern03_0053, Pattern03_0054, Pattern03_0055,
    Pattern03_0056, Pattern03_0057, Pattern03_0058, Pattern03_0059, Pattern03_0060, Pattern03_0061, Pattern03_0062,
    Pattern03_0063, Pattern03_0064, Pattern03_0065, Pattern03_0066, Pattern03_0067, Pattern03_0068, Pattern03_0069,
    Pattern03_0070, Pattern03_0071
};

void Computer03(PLW* wk) {
    Pattern03_Tbl[(s16)Pattern_Index[wk->wu.id]](wk);
}

void Pattern03_0000(PLW* wk) {
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

void Pattern03_0001(PLW* wk) {
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

void Pattern03_0002(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Branch_Unit_Area(wk, 2, 0x31, 0x32, 0x33, 1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern03_0003(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 9, 0x10);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern03_0004(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern03_0005(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x110);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern03_0006(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 0x1E);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern03_0007(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x70, 2, 1);
        break;

    case 1:
        Pierce_On(wk);
        break;

    case 2:
        Command_Attack(wk, 8, 1, 0xB, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern03_0008(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x100);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern03_0009(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x70, 2, 0x10);
        break;

    case 1:
        Jump(wk, 1);
        break;

    case 2:
        Look(wk, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern03_0010(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x402);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern03_0011(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x102);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x202);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern03_0012(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x40);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern03_0013(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern03_0014(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA0, -0x7FD0, 8, 0x20, 2, -0x7fa0, 8, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern03_0015(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 0, 0x30, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern03_0016(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x70, 2, 0);
        break;

    case 1:
        Walk(wk, 1, 0x30, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern03_0017(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x20, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern03_0018(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack(wk, 8, 0xC, 0x8400, 2);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern03_0019(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x20, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern03_0020(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x200);
        break;

    case 1:
        Command_Attack(wk, 8, 0x20, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern03_0021(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA0, -0x7FD0, 8, 0x40, 0, -0x7fa0, 8, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern03_0022(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, -0x7FB0, -1, 8, 0x8100, 0, -0x7fa0, 8, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern03_0023(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x83, 2);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern03_0024(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, -0x7FA0, -0x7FD0, 8, 0x20, 2, -0x7FA0, 8, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern03_0025(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x70, 2, 0);
        break;

    case 1:
        Walk(wk, 1, 0x60, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern03_0026(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0, 0xB, -1);
        break;

    case 1:
        Look(wk, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern03_0027(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump(wk, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern03_0028(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xC3, 2);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern03_0029(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 9, 0x100);
        break;

    case 1:
        Adjust_Attack(wk, 0xC, 0x100);
        break;

    case 2:
        Adjust_Attack(wk, 0xC, 0x202);
        break;

    case 3:
        Lever_Attack(wk, 8, 0, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern03_0030(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 9, 0x10);
        break;

    case 1:
        Adjust_Attack(wk, 0xC, 0x20);
        break;

    case 2:
        Adjust_Attack(wk, 8, 0x40);
        break;

    case 3:
        Command_Attack(wk, 8, 0x20, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern03_0031(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xC, 0x20);
        break;

    case 1:
        Branch_Unit_Area(wk, 2, 0x31, 0x32, 0x33, 0x33);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern03_0032(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 0xB, 0x10);
        break;

    case 1:
        Command_Attack(wk, 8, 0x20, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern03_0033(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 9, 0x10);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x110);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern03_0034(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 9, 0x102);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern03_0035(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern03_0036(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x42);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern03_0037(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xC, 0x40);
        break;

    case 1:
        Command_Attack(wk, 8, 0x20, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern03_0038(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 0xB, 0x20);
        break;

    case 1:
        Normal_Attack(wk, 0xA, 0x202);
        break;

    case 2:
        Branch_Unit_Area(wk, 2, 0x31, 0x32, 0x33, 1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern03_0039(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;

    case 1:
        Branch_Unit_Area(wk, 2, 0x31, 0x32, 0x33, 1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern03_0040(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x202);
        break;

    case 1:
        Command_Attack(wk, 8, 0x20, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern03_0041(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xB, 0x42);
        break;

    case 1:
        Command_Attack(wk, 8, 0x20, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern03_0042(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x12);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x12);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x402);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern03_0043(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA0, 8, 8, 0x8400, 0, -1, -0x7FA0, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern03_0044(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA0, -0x7FC0, 8, 0x20, 0, -0x7FA0, 8, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern03_0045(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 0, 0x14, 0);
        break;

    case 1:
        Walk(wk, 1, 0x16, 0);
        break;

    case 2:
        Walk(wk, 0, 0x18, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern03_0046(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8016, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern03_0047(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8015, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern03_0048(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8014, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern03_0049(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1F, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern03_0050(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1F, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern03_0051(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1F, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern03_0052(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x2E, 0x2F, 0xFFFF, 0);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern03_0053(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0xFFFF, 0x2F, 0x30, 0);
        break;

    case 1:
        Command_Attack(wk, 8, 0x20, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern03_0054(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0xFFFF, 0xFFFF, 0x30, 0);
        break;

    case 1:
        Hi_Jump_Attack_Term(wk, -0x7FB0, 8, 8, 0x8400, 0, -0x7FA0, 8, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern03_0055(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, -0x7FA0, -0x7FD0, 8, 0x40, 0, -0x7FA0, 8, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern03_0056(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;

    case 1:
        Com_Random_Select(wk, 2, 0x31, 4, 5, 1, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern03_0057(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x70, 6, 0x12);
        break;

    case 1:
        Jump_Attack_Term(wk, -0x7FA0, -0x7FC0, 8, 0x20, 1, -0x7FA0, 8, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern03_0058(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x70, 2, 0x11);
        break;

    case 1:
        Hi_Jump_Attack_Term(wk, -0x7FA0, -0x7FC0, 8, 0x20, 1, -0x7FA0, 8, 0x200);
        break;

    case 2:
        Pierce_On(wk);
        break;

    case 3:
        Command_Attack(wk, 8, 0, 0xB, -1);
        break;

    case 4:
        Com_Random_Select(wk, 2, 0x18, 0x18, 0x11, 0x11, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern03_0059(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x70, 2, 0x11);
        break;

    case 1:
        Pierce_On(wk);
        break;

    case 2:
        Command_Attack(wk, 8, 1, 0xB, -1);
        break;

    case 3:
        Command_Attack(wk, 8, 0, 0xB, -1);
        break;

    case 4:
        Com_Random_Select(wk, 2, 0x18, 0x18, 0x11, 0x11, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern03_0060(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x70, 2, 0);
        break;

    case 1:
        Jump_Attack_Term(wk, -0x7FA0, -0x7FC0, 8, 0x200, 0, -1, -1, -1);
        break;

    case 2:
        Pierce_On(wk);
        break;

    case 3:
        Command_Attack(wk, 8, 0, 0xB, -1);
        break;

    case 4:
        Com_Random_Select(wk, 2, 0x18, 0x18, 0x11, 0x11, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern03_0061(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x70, 2, 0);
        break;

    case 1:
        Pierce_On(wk);
        break;

    case 2:
        Command_Attack(wk, 8, 1, 0xB, -1);
        break;

    case 3:
        Hi_Jump_Attack_Term(wk, -0x7FA0, -1, 8, 0x8400, 0, -0x7FA0, -1, 0x8400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern03_0062(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, -0x7FA0, -0x7FC0, 8, 0x20, 0, -0x7FA0, 8, 0x200);
        break;

    case 1:
        Com_Random_Select(wk, 2, 0x18, 0x18, 0x11, 0x11, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern03_0063(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x200);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1F, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern03_0064(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xB, 0x10);
        break;
    case 1:
        Normal_Attack(wk, 8, 0x20);
        break;
    case 2:
        Normal_Attack(wk, 0xC, 0x40);
        break;
    case 3:
        Com_Random_Select(wk, 6, 0x37, 0x37, 0x27, 0x27, 0);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern03_0065(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xB, 0x200);
        break;

    case 1:
        Command_Attack(wk, 8, 0x20, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern03_0066(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 6, 0x2D, 0x19, 0x10, 0x17, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern03_0067(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Branch_Unit_Area(wk, 6, 0x44, 0x45, 0x46, 0x47);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern03_0068(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1D, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern03_0069(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1D, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern03_0070(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern03_0071(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1D, 0xB, 0x70);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}
