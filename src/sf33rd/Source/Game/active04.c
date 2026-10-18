/* active04.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * Computer04 0x9FE42 size 0x1A.
 * Pattern04_0001 0x9FE5C size 0x31.
 * Pattern04_0003 0x9FE8D size 0x2E.
 * Pattern04_0007 0x9FEBB size 0x4D.
 * Pattern04_0008 0x9FF08 size 0x3D.
 * Pattern04_0014 0x9FF45 size 0x43.
 * Pattern04_0018 0x9FF88 size 0x5E.
 * Pattern04_0019 0x9FFE6 size 0x46.
 * Pattern04_0020 0xA002C size 0x38.
 * Pattern04_0022 0xA0064 size 0x3D.
 * Pattern04_0028 0xA00A1 size 0x2B.
 * Pattern04_0029 0xA00CC size 0x43.
 * Pattern04_0030 0xA010F size 0x4C.
 * Pattern04_0031 0xA015B size 0x5A.
 * Pattern04_0033 0xA01B5 size 0x4F.
 * Pattern04_0034 0xA0204 size 0x47.
 * Pattern04_0038 0xA028C size 0x69.
 * Pattern04_0040 0xA02F5 size 0x56.
 * Pattern04_0041 0xA034B size 0x52.
 * Pattern04_0042 0xA039D size 0x4A.
 * Pattern04_0043 0xA03E7 size 0x3D.
 * Pattern04_0047 0xA0461 size 0x3E.
 * Pattern04_0048 0xA049F size 0x3E.
 * Pattern04_0058 0xA057D size 0x56.
 * Pattern04_0059 0xA05D3 size 0x3A.
 * Pattern04_0060 0xA060D size 0x6D.
 * Pattern04_0061 0xA067A size 0x30.
 * Pattern04_0062 0xA06AA size 0x30.
 * Pattern04_0005 is folded into 0x71B20 with 1 other bodies. Unnamed.
 * Pattern04_0064 is folded into 0x73220 with 1 other bodies. Unnamed.
 * Pattern04_0037 is folded into 0xA024B with 1 other bodies. Unnamed.
 * Pattern04_0045 is folded into 0xA0424 with 1 other bodies. Unnamed.
 * Pattern04_0054 is folded into 0xA054E with 1 other bodies. Unnamed.
 * Pattern04_0067 is folded into 0xA071D with 1 other bodies. Unnamed.
 * Pattern04_0023 is folded into 0xA12F9 with 1 other bodies. Unnamed.
 * Pattern04_0044 is folded into 0xA2169 with 2 other bodies. Unnamed.
 * Pattern04_0039 is folded into 0xA2EB1 with 1 other bodies. Unnamed.
 * Pattern04_0046 is folded into 0xA30C6 with 4 other bodies. Unnamed.
 * Pattern04_0065 is folded into 0xD8A85 with 1 other bodies. Unnamed.
 * Pattern04_0066 is folded into 0xD8AB1 with 1 other bodies. Unnamed.
 * Pattern04_0002 is folded into 0xE1C20 with 9 other bodies. Unnamed.
 * Pattern04_0009 is folded into 0xE33DD with 8 other bodies. Unnamed.
 * Pattern04_0000 is folded into 0xAB943 with 26 other bodies. Unnamed.
 * Pattern04_0004 is folded into 0x1C045 with 4 other bodies. Unnamed.
 * Pattern04_0006 is folded into 0xA98E2 with 6 other bodies. Unnamed.
 * Pattern04_0010 is folded into 0xA9FCC with 23 other bodies. Unnamed.
 * Pattern04_0011 is folded into 0xA9FF7 with 21 other bodies. Unnamed.
 * Pattern04_0012 is folded into 0x71E79 with 17 other bodies. Unnamed.
 * Pattern04_0013 is folded into 0xD47E2 with 16 other bodies. Unnamed.
 * Pattern04_0015 is folded into 0x9F683 with 8 other bodies. Unnamed.
 * Pattern04_0016 is folded into 0xA2A7B with 6 other bodies. Unnamed.
 * Pattern04_0017 is folded into 0xA340F with 4 other bodies. Unnamed.
 * Pattern04_0021 is folded into 0x825AF with 2 other bodies. Unnamed.
 * Pattern04_0024 is folded into 0xA6B63 with 7 other bodies. Unnamed.
 * Pattern04_0025 is folded into 0xA2C0E with 6 other bodies. Unnamed.
 * Pattern04_0026 is folded into 0xA08E8 with 3 other bodies. Unnamed.
 * Pattern04_0027 is folded into 0xDAC4C with 14 other bodies. Unnamed.
 * Pattern04_0032 is folded into 0xA0A12 with 2 other bodies. Unnamed.
 * Pattern04_0035 is folded into 0xD47E2 with 16 other bodies. Unnamed.
 * Pattern04_0036 is folded into 0xA9BB4 with 14 other bodies. Unnamed.
 * Pattern04_0049 is folded into 0xE2EEB with 17 other bodies. Unnamed.
 * Pattern04_0050 is folded into 0xA22B4 with 4 other bodies. Unnamed.
 * Pattern04_0051 is folded into 0xA04DD with 3 other bodies. Unnamed.
 * Pattern04_0052 is folded into 0xA0514 with 1 other bodies. Unnamed.
 * Pattern04_0053 is folded into 0x9E7DC with 10 other bodies. Unnamed.
 * Pattern04_0055 is folded into 0xAA823 with 7 other bodies. Unnamed.
 * Pattern04_0056 is folded into 0xE2F17 with 13 other bodies. Unnamed.
 * Pattern04_0057 is folded into 0xE2F43 with 11 other bodies. Unnamed.
 * Pattern04_0063 is folded into 0xA06DA with 3 other bodies. Unnamed.
 * Data: Pattern04_Tbl is 0x26E260, 68 entries compared.
 * Globals: Pattern04_Tbl 0x26E260, Pattern_Index 0x7A80C8, CP_Index 0x7A85B0.
 */

#include "structs.h"

void Pattern04_0000(PLW* wk);
void Pattern04_0001(PLW* wk);
void Pattern04_0002(PLW* wk);
void Pattern04_0003(PLW* wk);
void Pattern04_0004(PLW* wk);
void Pattern04_0005(PLW* wk);
void Pattern04_0006(PLW* wk);
void Pattern04_0007(PLW* wk);
void Pattern04_0008(PLW* wk);
void Pattern04_0009(PLW* wk);
void Pattern04_0010(PLW* wk);
void Pattern04_0011(PLW* wk);
void Pattern04_0012(PLW* wk);
void Pattern04_0013(PLW* wk);
void Pattern04_0014(PLW* wk);
void Pattern04_0015(PLW* wk);
void Pattern04_0016(PLW* wk);
void Pattern04_0017(PLW* wk);
void Pattern04_0018(PLW* wk);
void Pattern04_0019(PLW* wk);
void Pattern04_0020(PLW* wk);
void Pattern04_0021(PLW* wk);
void Pattern04_0022(PLW* wk);
void Pattern04_0023(PLW* wk);
void Pattern04_0024(PLW* wk);
void Pattern04_0025(PLW* wk);
void Pattern04_0026(PLW* wk);
void Pattern04_0027(PLW* wk);
void Pattern04_0028(PLW* wk);
void Pattern04_0029(PLW* wk);
void Pattern04_0030(PLW* wk);
void Pattern04_0031(PLW* wk);
void Pattern04_0032(PLW* wk);
void Pattern04_0033(PLW* wk);
void Pattern04_0034(PLW* wk);
void Pattern04_0035(PLW* wk);
void Pattern04_0036(PLW* wk);
void Pattern04_0037(PLW* wk);
void Pattern04_0038(PLW* wk);
void Pattern04_0039(PLW* wk);
void Pattern04_0040(PLW* wk);
void Pattern04_0041(PLW* wk);
void Pattern04_0042(PLW* wk);
void Pattern04_0043(PLW* wk);
void Pattern04_0044(PLW* wk);
void Pattern04_0045(PLW* wk);
void Pattern04_0046(PLW* wk);
void Pattern04_0047(PLW* wk);
void Pattern04_0048(PLW* wk);
void Pattern04_0049(PLW* wk);
void Pattern04_0050(PLW* wk);
void Pattern04_0051(PLW* wk);
void Pattern04_0052(PLW* wk);
void Pattern04_0053(PLW* wk);
void Pattern04_0054(PLW* wk);
void Pattern04_0055(PLW* wk);
void Pattern04_0056(PLW* wk);
void Pattern04_0057(PLW* wk);
void Pattern04_0058(PLW* wk);
void Pattern04_0059(PLW* wk);
void Pattern04_0060(PLW* wk);
void Pattern04_0061(PLW* wk);
void Pattern04_0062(PLW* wk);
void Pattern04_0063(PLW* wk);
void Pattern04_0064(PLW* wk);
void Pattern04_0065(PLW* wk);
void Pattern04_0066(PLW* wk);
void Pattern04_0067(PLW* wk);
extern u16 Pattern_Index[2];
extern u8 CP_Index[2][8];
void Lever_Off(PLW* wk);
void Look(PLW* wk, s16 Time);
void End_Pattern(PLW* wk);
void Normal_Attack(PLW* wk, s16 Reaction, u16 Lever_Data);
void J_Command_Attack(PLW* wk, s16 Reaction, u16 Tech_Number, s16 Power_Level, s16 Ex_Shot);
void Adjust_Attack(PLW* wk, s16 Reaction, u16 Lever_Data);
void Command_Attack(PLW* wk, s16 Reaction, u16 Tech_Number, s16 Power_Level, s16 Ex_Shot);
void Approach_Walk(PLW* wk, s16 Target_Pos, s16 Option);
void Wait(PLW* wk, s16 Time);
void Search_Back_Term(PLW* wk, s16 Move_Value, s16 Next_Action, s16 Next_Menu);
void Pierce_On(PLW* wk);
void Jump_Attack_Term(PLW* wk, s16 Range_X, s16 Range_Y, s16 Reaction, u16 Lever_Data, s16 Jump_Dir, s16 Range_JX, s16 Range_JY, s16 J_Lever_Data);
void Walk(PLW* wk, u16 Lever, s16 Time, s16 unused);
void Jump(PLW* wk, s16 Time);
void EM_Term(PLW* wk, s16 Range_X, s16 Range_Y, s16 Exit_Number, s16 Next_Action, s16 Next_Menu);
void Lever_Attack(PLW* wk, s16 Reaction, u16 Lever, u16 Lever_Data);
void SA_Term(PLW* wk, u16 SA0, u16 SA1, u16 SA2, u16 Term_No);
void Hi_Jump_Command_Attack_Term(PLW* wk, s16 Reaction, u16 Tech_Number, s16 Power_Level, s16 Ex_Shot, s16 RX, s16 RY, s16 Jump_Dir, s16 JRX, s16 JRY, u16 JLD);
void Hi_Jump_Attack(PLW* wk, s16 Reaction, s16 Time_Data, u16 Lever_Data, s16 Jump_Dir);
void Hi_Jump_Attack_Term(PLW* wk, s16 Range_X, s16 Range_Y, s16 Reaction, u16 Lever_Data, s16 Jump_Dir, s16 Range_JX, s16 Range_JY, u16 J_Lever_Data);
void Com_Random_Select(PLW* wk, s16 Next_Action, s16 Menu_00, s16 Menu_01, s16 Menu_02, s16 Menu_03, s16 Rnd_Type);

void (*const Pattern04_Tbl[68])();

void (*const Pattern04_Tbl[68])(PLW*) = {
    Pattern04_0000, Pattern04_0001, Pattern04_0002, Pattern04_0003, Pattern04_0004, Pattern04_0005, Pattern04_0006,
    Pattern04_0007, Pattern04_0008, Pattern04_0009, Pattern04_0010, Pattern04_0011, Pattern04_0012, Pattern04_0013,
    Pattern04_0014, Pattern04_0015, Pattern04_0016, Pattern04_0017, Pattern04_0018, Pattern04_0019, Pattern04_0020,
    Pattern04_0021, Pattern04_0022, Pattern04_0023, Pattern04_0024, Pattern04_0025, Pattern04_0026, Pattern04_0027,
    Pattern04_0028, Pattern04_0029, Pattern04_0030, Pattern04_0031, Pattern04_0032, Pattern04_0033, Pattern04_0034,
    Pattern04_0035, Pattern04_0036, Pattern04_0037, Pattern04_0038, Pattern04_0039, Pattern04_0040, Pattern04_0041,
    Pattern04_0042, Pattern04_0043, Pattern04_0044, Pattern04_0045, Pattern04_0046, Pattern04_0047, Pattern04_0048,
    Pattern04_0049, Pattern04_0050, Pattern04_0051, Pattern04_0052, Pattern04_0053, Pattern04_0054, Pattern04_0055,
    Pattern04_0056, Pattern04_0057, Pattern04_0058, Pattern04_0059, Pattern04_0060, Pattern04_0061, Pattern04_0062,
    Pattern04_0063, Pattern04_0064, Pattern04_0065, Pattern04_0066, Pattern04_0067
};

void Computer04(PLW* wk) {
    Pattern04_Tbl[(s16)Pattern_Index[wk->wu.id]](wk);
}

void Pattern04_0000(PLW* wk) {
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

void Pattern04_0001(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x12);
        break;

    case 1:
        Normal_Attack(wk, 9, 0x12);
        break;

    case 2:
        Normal_Attack(wk, 9, 0x12);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern04_0002(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1C, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern04_0003(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 8, 0x10);
        break;

    case 1:
        Adjust_Attack(wk, 8, 0x10);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern04_0004(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1F, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern04_0005(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x110);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern04_0006(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 0x1E);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern04_0007(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x30, 2, 0x14);
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

void Pattern04_0008(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7F90, -0x7FC0, 8, 0x400, 0, -1, -1, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern04_0009(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1C, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern04_0010(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x402);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern04_0011(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x202);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern04_0012(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x40);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern04_0013(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern04_0014(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA0, -0x7FC8, 8, 0x200, 2, -0x7F80, -1, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern04_0015(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 0, 0x30, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern04_0016(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 1, 0x30, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern04_0017(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x20, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern04_0018(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x30, 2, 0x31);
        break;

    case 1:
        Pierce_On(wk);
        break;

    case 2:
        Jump(wk, 1);
        break;

    case 3:
        Lever_Off(wk);
        break;

    case 4:
        Look(wk, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern04_0019(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x88, -1, 0, 2, 5);
        break;

    case 1:
        Lever_Attack(wk, 8, 0, 0x40);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern04_0020(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1F, 8, -1);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1F, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern04_0021(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x20, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern04_0022(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA0, -0x7FC8, 8, 0x40, 0, -0x7F90, -1, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern04_0023(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x9F, 2);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern04_0024(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 0, 0x60, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern04_0025(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 1, 0x60, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern04_0026(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0, 0xB, -1);
        break;

    case 1:
        Lever_Off(wk);
        break;

    case 2:
        Look(wk, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern04_0027(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump(wk, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern04_0028(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xDF, 2);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern04_0029(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 9, 0x102);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1F, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern04_0030(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;

    case 1:
        Adjust_Attack(wk, 9, 0x100);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x40);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern04_0031(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA0, -0x7FD0, 8, 0x400, 0, -0x7F68, -1, 0x200);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x402);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern04_0032(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 0xB, 0x10);
        break;

    case 1:
        Adjust_Attack(wk, 8, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern04_0033(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;

    case 1:
        Adjust_Attack(wk, 0xB, 0x10);
        break;

    case 2:
        J_Command_Attack(wk, 8, 0x1C, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern04_0034(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x100);
        break;

    case 1:
        Lever_Off(wk);
        break;

    case 2:
        Look(wk, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern04_0035(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern04_0036(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x42);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern04_0037(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;

    case 1:
        Lever_Attack(wk, 8, 0, 0x110);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern04_0038(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x35, 0xFFFF, 0x37, 0);
        break;

    case 1:
        Pierce_On(wk);
        break;

    case 2:
        Adjust_Attack(wk, 0xB, 0x20);
        break;

    case 3:
        Normal_Attack(wk, 0xA, 0x102);
        break;

    case 4:
        Normal_Attack(wk, 8, 0x40);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern04_0039(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0, 0xB, -1);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1C, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern04_0040(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;

    case 1:
        Lever_Attack(wk, 9, 0, 0x200);
        break;

    case 2:
        J_Command_Attack(wk, 8, 0x1C, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern04_0041(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
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

void Pattern04_0042(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x12);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x12);
        break;

    case 3:
        Normal_Attack(wk, 8, 0x12);
        break;

    case 4:
        Normal_Attack(wk, 8, 0x202);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern04_0043(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA0, -0x7FD0, 8, 0x40, 0, -1, 0x30, 0x4020);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern04_0044(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA0, -0x7FC0, 8, 0x40, 0, -1, 0x30, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern04_0045(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA0, -0x7FD0, 8, 0x400, 0, -1, -1, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern04_0046(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 0, 0x15, 0);
        break;

    case 1:
        Walk(wk, 1, 0x13, 0);
        break;

    case 2:
        Walk(wk, 0, 0x10, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern04_0047(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Command_Attack_Term(wk, 8, 0x20, 0xA, -1, -0x7FA0, 0x30, 0, -1, 0x30, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern04_0048(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;

    case 1:
        Lever_Attack(wk, 0xD, 0, 0x10);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern04_0049(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern04_0050(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack(wk, 8, 0xA, 0x400, 2);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern04_0051(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, -1, 0x30, 8, 0x40, 0, -1, -1, 0xFFFF);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern04_0052(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Command_Attack_Term(wk, 8, 0x20, 0xA, -1, -1, 0x30, 0, -1, -1, 0xFFFF);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern04_0053(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8014, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern04_0054(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8215, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern04_0055(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8016, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern04_0056(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern04_0057(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern04_0058(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x20, 9, -1);
        break;

    case 1:
        Approach_Walk(wk, 0x47, 2);
        break;

    case 2:
        Lever_Attack(wk, 0xD, 0, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern04_0059(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x20, 8, -1);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1F, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern04_0060(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F90, 0, 0, 2, 0);
        break;

    case 1:
        Command_Attack(wk, 0xD, 0x20, 0x609, -1);
        break;

    case 2:
        Approach_Walk(wk, 0x47, 2);
        break;

    case 3:
        Normal_Attack(wk, 0xD, 0x100);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern04_0061(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 2, 0x40, 0x41, 0x43, 0x43, 1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern04_0062(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 2, 0x40, 0x41, 0x42, 0x43, 1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern04_0063(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7F90, -0x7FC0, 8, 0x200, 0, 0 - 0x7F68, -1, 0x400);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern04_0064(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x21, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern04_0065(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x21, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern04_0066(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x21, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern04_0067(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x21, 0xA, 0x700);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}
