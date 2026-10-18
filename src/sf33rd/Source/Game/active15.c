/* active15.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * Computer15 0xA9824 size 0x1A.
 * Pattern15_0002 0xA9870 size 0x2E.
 * Pattern15_0005 0xA989E size 0x44.
 * Pattern15_0009 0xA9907 size 0x48.
 * Pattern15_0016 0xA994F size 0x3E.
 * Pattern15_0020 0xA99BC size 0x45.
 * Pattern15_0025 0xA9A66 size 0x3E.
 * Pattern15_0032 0xA9B2F size 0x40.
 * Pattern15_0033 0xA9B6F size 0x45.
 * Pattern15_0037 0xA9BDC size 0x40.
 * Pattern15_0039 0xA9C1C size 0x3A.
 * Pattern15_0041 0xA9C56 size 0x40.
 * Pattern15_0042 0xA9C96 size 0x3C.
 * Pattern15_0052 0xA9D2A size 0x4B.
 * Pattern15_0054 0xA9DBA size 0x68.
 * Pattern15_0061 0xA9E22 size 0x43.
 * Pattern15_0066 0xA9E94 size 0x2F.
 * Pattern15_0000 is folded into 0xAB943 with 44 other bodies. Unnamed.
 * Pattern15_0001 is folded into 0xA983E with 1 other bodies. Unnamed.
 * Pattern15_0003 is folded into 0xAB976 with 4 other bodies. Unnamed.
 * Pattern15_0004 is folded into 0xE2F43 with 17 other bodies. Unnamed.
 * Pattern15_0006 is folded into 0xA98E2 with 12 other bodies. Unnamed.
 * Pattern15_0007 is folded into 0xAB9B3 with 5 other bodies. Unnamed.
 * Pattern15_0008 is folded into 0xA9FA1 with 25 other bodies. Unnamed.
 * Pattern15_0010 is folded into 0xA9FCC with 33 other bodies. Unnamed.
 * Pattern15_0011 is folded into 0xA9FF7 with 32 other bodies. Unnamed.
 * Pattern15_0012 is folded into 0x71E79 with 26 other bodies. Unnamed.
 * Pattern15_0013 is folded into 0xD47E2 with 27 other bodies. Unnamed.
 * Pattern15_0014 is folded into 0xDB121 with 9 other bodies. Unnamed.
 * Pattern15_0015 is folded into 0x9F683 with 14 other bodies. Unnamed.
 * Pattern15_0017 is folded into 0xE2F17 with 22 other bodies. Unnamed.
 * Pattern15_0018 is folded into 0xA998D with 1 other bodies. Unnamed.
 * Pattern15_0019 is folded into 0x9E572 with 12 other bodies. Unnamed.
 * Pattern15_0021 is folded into 0xA9A01 with 4 other bodies. Unnamed.
 * Pattern15_0022 is folded into 0x9E5E1 with 4 other bodies. Unnamed.
 * Pattern15_0023 is folded into 0xA9A3E with 17 other bodies. Unnamed.
 * Pattern15_0024 is folded into 0xA6B63 with 12 other bodies. Unnamed.
 * Pattern15_0026 is folded into 0x9E60D with 9 other bodies. Unnamed.
 * Pattern15_0027 is folded into 0xDAC4C with 25 other bodies. Unnamed.
 * Pattern15_0028 is folded into 0xAA09A with 13 other bodies. Unnamed.
 * Pattern15_0029 is folded into 0xAB0A0 with 4 other bodies. Unnamed.
 * Pattern15_0030 is folded into 0xA9AA4 with 4 other bodies. Unnamed.
 * Pattern15_0031 is folded into 0xA9ADE with 1 other bodies. Unnamed.
 * Pattern15_0034 is folded into 0xABAEC with 5 other bodies. Unnamed.
 * Pattern15_0035 is folded into 0xD47E2 with 27 other bodies. Unnamed.
 * Pattern15_0036 is folded into 0xA9BB4 with 20 other bodies. Unnamed.
 * Pattern15_0038 is folded into 0xAA1CC with 3 other bodies. Unnamed.
 * Pattern15_0040 is folded into 0x9E759 with 3 other bodies. Unnamed.
 * Pattern15_0043 is folded into 0xDF251 with 11 other bodies. Unnamed.
 * Pattern15_0044 is folded into 0xE12D6 with 11 other bodies. Unnamed.
 * Pattern15_0045 is folded into 0xA9CD2 with 11 other bodies. Unnamed.
 * Pattern15_0046 is folded into 0x9E7DC with 17 other bodies. Unnamed.
 * Pattern15_0047 is folded into 0xAA7F4 with 10 other bodies. Unnamed.
 * Pattern15_0048 is folded into 0xAA823 with 13 other bodies. Unnamed.
 * Pattern15_0049 is folded into 0x746F9 with 7 other bodies. Unnamed.
 * Pattern15_0050 is folded into 0x85416 with 8 other bodies. Unnamed.
 * Pattern15_0051 is folded into 0x1C045 with 8 other bodies. Unnamed.
 * Pattern15_0053 is folded into 0xA9D75 with 2 other bodies. Unnamed.
 * Pattern15_0055 is folded into 0xAB943 with 44 other bodies. Unnamed.
 * Pattern15_0056 is folded into 0xD5FA5 with 2 other bodies. Unnamed.
 * Pattern15_0057 is folded into 0xE02DF with 8 other bodies. Unnamed.
 * Pattern15_0058 is folded into 0xE02B3 with 9 other bodies. Unnamed.
 * Pattern15_0059 is folded into 0xE19B6 with 11 other bodies. Unnamed.
 * Pattern15_0060 is folded into 0x9E95E with 3 other bodies. Unnamed.
 * Pattern15_0062 is folded into 0xDDB8D with 22 other bodies. Unnamed.
 * Pattern15_0063 is folded into 0xDDBBA with 20 other bodies. Unnamed.
 * Pattern15_0064 is folded into 0xE2EEB with 25 other bodies. Unnamed.
 * Pattern15_0065 is folded into 0xA9E65 with 1 other bodies. Unnamed.
 * Pattern15_0067 is folded into 0xA51A9 with 2 other bodies. Unnamed.
 * Pattern15_0068 is folded into 0xA9E65 with 1 other bodies. Unnamed.
 * Data: Pattern15_Tbl is 0x26F0E8, 69 entries compared.
 * Globals: Pattern15_Tbl 0x26F0E8, Pattern_Index 0x7A80C8, CP_Index 0x7A85B0.
 */

#include "structs.h"

void Pattern15_0000(PLW* wk);
void Pattern15_0001(PLW* wk);
void Pattern15_0002(PLW* wk);
void Pattern15_0003(PLW* wk);
void Pattern15_0004(PLW* wk);
void Pattern15_0005(PLW* wk);
void Pattern15_0006(PLW* wk);
void Pattern15_0007(PLW* wk);
void Pattern15_0008(PLW* wk);
void Pattern15_0009(PLW* wk);
void Pattern15_0010(PLW* wk);
void Pattern15_0011(PLW* wk);
void Pattern15_0012(PLW* wk);
void Pattern15_0013(PLW* wk);
void Pattern15_0014(PLW* wk);
void Pattern15_0015(PLW* wk);
void Pattern15_0016(PLW* wk);
void Pattern15_0017(PLW* wk);
void Pattern15_0018(PLW* wk);
void Pattern15_0019(PLW* wk);
void Pattern15_0020(PLW* wk);
void Pattern15_0021(PLW* wk);
void Pattern15_0022(PLW* wk);
void Pattern15_0023(PLW* wk);
void Pattern15_0024(PLW* wk);
void Pattern15_0025(PLW* wk);
void Pattern15_0026(PLW* wk);
void Pattern15_0027(PLW* wk);
void Pattern15_0028(PLW* wk);
void Pattern15_0029(PLW* wk);
void Pattern15_0030(PLW* wk);
void Pattern15_0031(PLW* wk);
void Pattern15_0032(PLW* wk);
void Pattern15_0033(PLW* wk);
void Pattern15_0034(PLW* wk);
void Pattern15_0035(PLW* wk);
void Pattern15_0036(PLW* wk);
void Pattern15_0037(PLW* wk);
void Pattern15_0038(PLW* wk);
void Pattern15_0039(PLW* wk);
void Pattern15_0040(PLW* wk);
void Pattern15_0041(PLW* wk);
void Pattern15_0042(PLW* wk);
void Pattern15_0043(PLW* wk);
void Pattern15_0044(PLW* wk);
void Pattern15_0045(PLW* wk);
void Pattern15_0046(PLW* wk);
void Pattern15_0047(PLW* wk);
void Pattern15_0048(PLW* wk);
void Pattern15_0049(PLW* wk);
void Pattern15_0050(PLW* wk);
void Pattern15_0051(PLW* wk);
void Pattern15_0052(PLW* wk);
void Pattern15_0053(PLW* wk);
void Pattern15_0054(PLW* wk);
void Pattern15_0055(PLW* wk);
void Pattern15_0056(PLW* wk);
void Pattern15_0057(PLW* wk);
void Pattern15_0058(PLW* wk);
void Pattern15_0059(PLW* wk);
void Pattern15_0060(PLW* wk);
void Pattern15_0061(PLW* wk);
void Pattern15_0062(PLW* wk);
void Pattern15_0063(PLW* wk);
void Pattern15_0064(PLW* wk);
void Pattern15_0065(PLW* wk);
void Pattern15_0066(PLW* wk);
void Pattern15_0067(PLW* wk);
void Pattern15_0068(PLW* wk);
extern u16 Pattern_Index[2];
extern u8 CP_Index[2][8];
void Lever_Off(PLW* wk);
void Look(PLW* wk, s16 Time);
void End_Pattern(PLW* wk);
void Normal_Attack(PLW* wk, s16 Reaction, u16 Lever_Data);
void Branch_Unit_Area(PLW* wk, s16 Next_Action, s16 Menu, s16 Menu_01, s16 Menu_02, s16 Menu_03);
void Adjust_Attack(PLW* wk, s16 Reaction, u16 Lever_Data);
void Command_Attack(PLW* wk, s16 Reaction, u16 Tech_Number, s16 Power_Level, s16 Ex_Shot);
void Approach_Walk(PLW* wk, s16 Target_Pos, s16 Option);
void Com_Random_Select(PLW* wk, s16 Next_Action, s16 Menu_00, s16 Menu_01, s16 Menu_02, s16 Menu_03, s16 Rnd_Type);
void Wait(PLW* wk, s16 Time);
void Search_Back_Term(PLW* wk, s16 Move_Value, s16 Next_Action, s16 Next_Menu);
void Pierce_On(PLW* wk);
void Jump(PLW* wk, s16 Time);
void Jump_Attack_Term(PLW* wk, s16 Range_X, s16 Range_Y, s16 Reaction, u16 Lever_Data, s16 Jump_Dir, s16 Range_JX, s16 Range_JY, s16 J_Lever_Data);
void Walk(PLW* wk, u16 Lever, s16 Time, s16 unused);
void Jump_Attack(PLW* wk, s16 Reaction, s16 Time_Data, u16 Lever_Data, s16 Jump_Dir);
void Lever_Attack(PLW* wk, s16 Reaction, u16 Lever, u16 Lever_Data);
void SA_Term(PLW* wk, u16 SA0, u16 SA1, u16 SA2, u16 Term_No);
void Check_EX(PLW* wk, s16 Next_Action, s16 Next_Menu);
void Rapid_Command_Attack(PLW* wk, s16 Reaction, u16 Tech_Number, s16 Shot, u16 Time);
void Normal_Attack_SP(PLW* wk, s16 Reaction, u16 Lever_Data, s16 Time);

void (*const Pattern15_Tbl[69])();

void (*const Pattern15_Tbl[69])(PLW*) = {
    Pattern15_0000, Pattern15_0001, Pattern15_0002, Pattern15_0003, Pattern15_0004, Pattern15_0005, Pattern15_0006,
    Pattern15_0007, Pattern15_0008, Pattern15_0009, Pattern15_0010, Pattern15_0011, Pattern15_0012, Pattern15_0013,
    Pattern15_0014, Pattern15_0015, Pattern15_0016, Pattern15_0017, Pattern15_0018, Pattern15_0019, Pattern15_0020,
    Pattern15_0021, Pattern15_0022, Pattern15_0023, Pattern15_0024, Pattern15_0025, Pattern15_0026, Pattern15_0027,
    Pattern15_0028, Pattern15_0029, Pattern15_0030, Pattern15_0031, Pattern15_0032, Pattern15_0033, Pattern15_0034,
    Pattern15_0035, Pattern15_0036, Pattern15_0037, Pattern15_0038, Pattern15_0039, Pattern15_0040, Pattern15_0041,
    Pattern15_0042, Pattern15_0043, Pattern15_0044, Pattern15_0045, Pattern15_0046, Pattern15_0047, Pattern15_0048,
    Pattern15_0049, Pattern15_0050, Pattern15_0051, Pattern15_0052, Pattern15_0053, Pattern15_0054, Pattern15_0055,
    Pattern15_0056, Pattern15_0057, Pattern15_0058, Pattern15_0059, Pattern15_0060, Pattern15_0061, Pattern15_0062,
    Pattern15_0063, Pattern15_0064, Pattern15_0065, Pattern15_0066, Pattern15_0067, Pattern15_0068
};

void Computer15(PLW* wk) {
    Pattern15_Tbl[(s16)Pattern_Index[wk->wu.id]](wk);
}

void Pattern15_0000(PLW* wk) {
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

void Pattern15_0001(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x10);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x40);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern15_0002(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Branch_Unit_Area(wk, 2, 0x41, 0x31, 0x32, 0x33);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern15_0003(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 8, 0x10);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern15_0004(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern15_0005(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;

    case 1:
        Com_Random_Select(wk, 2, 0x3E, 0x3E, 0x3F, 0x3F, 1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern15_0006(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 0x1E);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern15_0007(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x30, 2, 1);
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

void Pattern15_0008(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern15_0009(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x30, 6, 0x12);
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

void Pattern15_0010(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x402);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern15_0011(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x202);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern15_0012(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x40);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern15_0013(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern15_0014(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, -0x7FB0, 0xB, 0x20, 2, -0x7FA0, -1, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern15_0015(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 0, 0x30, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern15_0016(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x30, 6, 0xF);
        break;

    case 1:
        Walk(wk, 1, 0x30, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern15_0017(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern15_0018(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack(wk, 8, 0xC, 0x202, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern15_0019(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern15_0020(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;

    case 1:
        Jump_Attack(wk, 8, 0xC, 0x202, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern15_0021(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, -0x7FA0, 0xB, 0x400, 0, -0x7FA0, -1, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern15_0022(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack(wk, 8, 0xF, 0x40, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern15_0023(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x7F, 2);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern15_0024(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 0, 0x60, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern15_0025(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x30, 6, 0xF);
        break;

    case 1:
        Walk(wk, 1, 0x60, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern15_0026(PLW* wk) {
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

void Pattern15_0027(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump(wk, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern15_0028(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBF, 2);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern15_0029(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 8, 0x100);
        break;

    case 1:
        Adjust_Attack(wk, 8, 0x200);
        break;

    case 2:
        Adjust_Attack(wk, 8, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern15_0030(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 9, 0x100);
        break;

    case 1:
        Adjust_Attack(wk, 8, 0x402);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern15_0031(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, -0x7FA0, 0xB, 0x200, 0, -0x7FA0, -1, 0x200);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern15_0032(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 0xB, 0x10);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1E, 8, 0x70);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern15_0033(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 8, 0x100);
        break;

    case 1:
        Branch_Unit_Area(wk, 2, 1, 0x31, 0x32, 0x33);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern15_0034(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 8, 0x102);
        break;

    case 1:
        Adjust_Attack(wk, 8, 0x102);
        break;

    case 2:
        Adjust_Attack(wk, 8, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern15_0035(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern15_0036(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x42);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern15_0037(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x40);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern15_0038(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 0xB, 0x20);
        break;

    case 1:
        Normal_Attack(wk, 0xA, 0x202);
        break;

    case 2:
        Lever_Attack(wk, 8, 0, 0x40);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern15_0039(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1F, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern15_0040(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x202);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1E, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern15_0041(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xB, 0x20);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern15_0042(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x12);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x22);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x402);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern15_0043(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x30, 2, 0xF);
        break;

    case 1:
        Walk(wk, 1, 0x20, 0);
        break;

    case 2:
        Wait(wk, 3);
        break;

    case 3:
        Walk(wk, 0, 0x30, 0);
        break;

    case 4:
        Wait(wk, 9);
        break;

    case 5:
        Walk(wk, 0, 0x20, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern15_0044(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x20, 2, 0x1B);
        break;

    case 1:
        Walk(wk, 1, 0x18, 0);
        break;

    case 2:
        Wait(wk, 8);
        break;

    case 3:
        Search_Back_Term(wk, 0x30, 2, 0x1B);
        break;

    case 4:
        Walk(wk, 1, 0x20, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern15_0045(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 0, 0x20, 0);
        break;

    case 1:
        Search_Back_Term(wk, 0x30, 2, 6);
        break;

    case 2:
        Walk(wk, 1, 0x28, 0);
        break;

    case 3:
        Wait(wk, 8);
        break;

    case 4:
        Walk(wk, 0, 0x20, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern15_0046(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8014, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern15_0047(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8015, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern15_0048(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8016, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern15_0049(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1F, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern15_0050(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1F, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern15_0051(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1F, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern15_0052(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0xFFFF, 0x2F, 0x30, 0);
        break;

    case 1:
        Com_Random_Select(wk, 2, 0x3E, 0x3E, 0x3F, 0x3F, 1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern15_0053(PLW* wk) {
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

void Pattern15_0054(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0xFFFF, 0x2F, 0xFFFF, 0);
        break;

    case 1:
        Approach_Walk(wk, 0xBF, 2);
        break;

    case 2:
        SA_Term(wk, 0x2E, 0xFFFF, 0xFFFF, 0);
        break;

    case 3:
        Command_Attack(wk, 8, 0x1F, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern15_0055(PLW* wk) {
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

void Pattern15_0056(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1C, 9, 0x700);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern15_0057(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1C, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern15_0058(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1C, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern15_0059(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern15_0060(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 9, 0x70);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern15_0061(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Check_EX(wk, 2, 2);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1F, 0xA, 0x700);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern15_0062(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x110);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern15_0063(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 1, 0x110);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern15_0064(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern15_0065(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Rapid_Command_Attack(wk, 8, 0x4D, 0x100, 0x78);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern15_0066(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Rapid_Command_Attack(wk, 8, 0x4D, 0x400, 0x78);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern15_0067(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack_SP(wk, 8, 0x200, 0x12);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern15_0068(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Rapid_Command_Attack(wk, 8, 0x4D, 0x100, 0x78);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}
