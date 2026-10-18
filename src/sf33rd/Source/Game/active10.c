/* active10.c, retail sf33rd.xbe.
 * PlayStation 2 C, not hand-adjusted for Xbox. Each named body was located
 * from the PS2 retail map: call graph, source order, and agreement of
 * constants, field offsets, callees, and size. See docs/decompiling.md.
 * The #include lines name headers in the PS2 tree (ps2.path).
 * Pattern10_0017 0xA499D size 0x51.
 * Pattern10_0019 0xA49EE size 0x51.
 * Pattern10_0020 0xA4A3F size 0x45.
 * Pattern10_0030 0xA4AC1 size 0x52.
 * Pattern10_0034 0xA4B92 size 0x43.
 * Pattern10_0037 0xA4BD5 size 0x40.
 * Pattern10_0039 0xA4C69 size 0x46.
 * Pattern10_0040 0xA4CAF size 0x43.
 * Pattern10_0041 0xA4CF2 size 0x62.
 * Pattern10_0052 0xA4D92 size 0x45.
 * Pattern10_0053 0xA4DD7 size 0x45.
 * Pattern10_0065 0xA505E size 0x43.
 * Pattern10_0000 is folded into 0xAB943 with 44 other bodies. Unnamed.
 * Pattern10_0001 is folded into 0x9F53F with 8 other bodies. Unnamed.
 * Pattern10_0002 is folded into 0x9F56D with 1 other bodies. Unnamed.
 * Pattern10_0003 is folded into 0x9F59B with 2 other bodies. Unnamed.
 * Pattern10_0004 is folded into 0x9E903 with 8 other bodies. Unnamed.
 * Pattern10_0005 is folded into 0xDDB8D with 22 other bodies. Unnamed.
 * Pattern10_0006 is folded into 0xA98E2 with 12 other bodies. Unnamed.
 * Pattern10_0007 is folded into 0xA4908 with 1 other bodies. Unnamed.
 * Pattern10_0008 is folded into 0x9F5D5 with 1 other bodies. Unnamed.
 * Pattern10_0009 is folded into 0xA4955 with 1 other bodies. Unnamed.
 * Pattern10_0010 is folded into 0xA9FCC with 33 other bodies. Unnamed.
 * Pattern10_0011 is folded into 0x9F60F with 7 other bodies. Unnamed.
 * Pattern10_0012 is folded into 0x71E79 with 26 other bodies. Unnamed.
 * Pattern10_0013 is folded into 0xE33B0 with 14 other bodies. Unnamed.
 * Pattern10_0014 is folded into 0x9F649 with 1 other bodies. Unnamed.
 * Pattern10_0015 is folded into 0x9F683 with 14 other bodies. Unnamed.
 * Pattern10_0016 is folded into 0x9F6AC with 1 other bodies. Unnamed.
 * Pattern10_0018 is folded into 0x9F6E9 with 1 other bodies. Unnamed.
 * Pattern10_0021 is folded into 0x9F75D with 1 other bodies. Unnamed.
 * Pattern10_0022 is folded into 0x9F79A with 1 other bodies. Unnamed.
 * Pattern10_0023 is folded into 0x9F7DA with 3 other bodies. Unnamed.
 * Pattern10_0024 is folded into 0x9F805 with 1 other bodies. Unnamed.
 * Pattern10_0025 is folded into 0xA4A84 with 2 other bodies. Unnamed.
 * Pattern10_0026 is folded into 0x9E60D with 9 other bodies. Unnamed.
 * Pattern10_0027 is folded into 0xDAC4C with 25 other bodies. Unnamed.
 * Pattern10_0028 is folded into 0x9F842 with 3 other bodies. Unnamed.
 * Pattern10_0029 is folded into 0x9F86D with 1 other bodies. Unnamed.
 * Pattern10_0031 is folded into 0xA4B13 with 1 other bodies. Unnamed.
 * Pattern10_0032 is folded into 0xAA14C with 3 other bodies. Unnamed.
 * Pattern10_0033 is folded into 0xA4B55 with 2 other bodies. Unnamed.
 * Pattern10_0035 is folded into 0xD47E2 with 27 other bodies. Unnamed.
 * Pattern10_0036 is folded into 0xA9BB4 with 20 other bodies. Unnamed.
 * Pattern10_0038 is folded into 0xA4C15 with 1 other bodies. Unnamed.
 * Pattern10_0042 is folded into 0xA4D54 with 1 other bodies. Unnamed.
 * Pattern10_0043 is folded into 0x9FAA5 with 1 other bodies. Unnamed.
 * Pattern10_0044 is folded into 0x9FAE2 with 1 other bodies. Unnamed.
 * Pattern10_0045 is folded into 0x9FB1F with 1 other bodies. Unnamed.
 * Pattern10_0046 is folded into 0xAA7F4 with 10 other bodies. Unnamed.
 * Pattern10_0047 is folded into 0xAA823 with 13 other bodies. Unnamed.
 * Pattern10_0048 is folded into 0x9E7DC with 17 other bodies. Unnamed.
 * Pattern10_0049 is folded into 0x9FB5D with 12 other bodies. Unnamed.
 * Pattern10_0050 is folded into 0x9FB89 with 10 other bodies. Unnamed.
 * Pattern10_0051 is folded into 0x9FBB5 with 13 other bodies. Unnamed.
 * Pattern10_0054 is folded into 0xA4E1C with 1 other bodies. Unnamed.
 * Pattern10_0055 is folded into 0xA4E73 with 1 other bodies. Unnamed.
 * Pattern10_0056 is folded into 0xA4EAD with 1 other bodies. Unnamed.
 * Pattern10_0057 is folded into 0x9FC26 with 1 other bodies. Unnamed.
 * Pattern10_0058 is folded into 0x9FC79 with 1 other bodies. Unnamed.
 * Pattern10_0059 is folded into 0xA4EF5 with 1 other bodies. Unnamed.
 * Pattern10_0060 is folded into 0xA4F65 with 1 other bodies. Unnamed.
 * Pattern10_0061 is folded into 0xA4FEE with 1 other bodies. Unnamed.
 * Pattern10_0062 is folded into 0x9FD04 with 1 other bodies. Unnamed.
 * Pattern10_0063 is folded into 0x9FD5C with 1 other bodies. Unnamed.
 * Pattern10_0064 is folded into 0xD3DCE with 3 other bodies. Unnamed.
 * Pattern10_0066 is folded into 0x9FDE4 with 1 other bodies. Unnamed.
 * Pattern10_0067 is folded into 0x71307 with 3 other bodies. Unnamed.
 * Pattern10_0068 is folded into 0xE2326 with 16 other bodies. Unnamed.
 * Pattern10_0069 is folded into 0xD442A with 1 other bodies. Unnamed.
 * The other functions in this file are not located in sf33rd.xbe yet.
 */

#include "sf33rd/Source/Game/active10.h"
#include "common.h"
#include "sf33rd/Source/Game/Com_Sub.h"
#include "sf33rd/Source/Game/workuser.h"

void (*const Pattern10_Tbl[70])();

void Computer10(PLW* wk) {
    Pattern10_Tbl[(s16)Pattern_Index[wk->wu.id]](wk);
}

void Pattern10_0000(PLW* wk) {
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

void Pattern10_0001(PLW* wk) {
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

void Pattern10_0002(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Branch_Unit_Area(wk, 2, 0x31, 0x32, 0x33, 1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern10_0003(PLW* wk) {
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

void Pattern10_0004(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x20, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern10_0005(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x110);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern10_0006(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 0x1E);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern10_0007(PLW* wk) {
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

void Pattern10_0008(PLW* wk) {
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

void Pattern10_0009(PLW* wk) {
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

void Pattern10_0010(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x402);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern10_0011(PLW* wk) {
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

void Pattern10_0012(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x40);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern10_0013(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern10_0014(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA0, -0x7FD0, 8, 0x20, 2, -0x7FA0, 8, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern10_0015(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 0, 0x30, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern10_0016(PLW* wk) {
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

void Pattern10_0017(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;

    case 1:
        Command_Attack(wk, 0xe, 0x1e, 8, -1);
        break;

    case 2:
        Wait(wk, 0xe);
        break;

    case 3:
        Command_Attack(wk, 0xe, 0x1e, 8, -1);
        break;

    case 4:
        Wait(wk, 0xe);
        break;

    case 5:
        Command_Attack(wk, 0xe, 0x1e, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern10_0018(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack(wk, 8, 0xC, 0x8400, 2);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern10_0019(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;

    case 1:
        Command_Attack(wk, 0xe, 0x1e, 9, -1);
        break;

    case 2:
        Wait(wk, 0xe);
        break;

    case 3:
        Command_Attack(wk, 0xe, 0x1e, 9, -1);
        break;

    case 4:
        Wait(wk, 0xe);
        break;

    case 5:
        Command_Attack(wk, 0xe, 0x1e, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern10_0020(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x200);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern10_0021(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA0, -0x7FD0, 8, 0x40, 0, -0x7FA0, 8, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern10_0022(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, -0x7FB0, -1, 8, 0x8100, 0, -0x7FA0, 8, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern10_0023(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x83, 2);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern10_0024(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, -0x7FA0, -0x7FD0, 8, 0x20, 2, -0x7FA0, 8, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern10_0025(PLW* wk) {
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

void Pattern10_0026(PLW* wk) {
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

void Pattern10_0027(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump(wk, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern10_0028(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xC3, 2);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern10_0029(PLW* wk) {
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

void Pattern10_0030(PLW* wk) {
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
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern10_0031(PLW* wk) {
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

void Pattern10_0032(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 0xB, 0x10);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern10_0033(PLW* wk) {
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

void Pattern10_0034(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 9, 0x102);
        break;

    case 1:
        Command_Attack(wk, 8, 0x20, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern10_0035(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern10_0036(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x42);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern10_0037(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xC, 0x40);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern10_0038(PLW* wk) {
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

void Pattern10_0039(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x20, 8, -1);
        break;

    case 1:
        Branch_Unit_Area(wk, 2, 0x31, 0x32, 0x33, 1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern10_0040(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x202);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern10_0041(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xb, 0x42);
        break;

    case 1:
        Pierce_On(wk);
        break;

    case 2:
        Command_Attack(wk, 0xe, 0x1e, 8, -1);
        break;

    case 3:
        Wait(wk, 0xe);
        break;

    case 4:
        Command_Attack(wk, 0xe, 0x1e, 8, -1);
        break;

    case 5:
        Wait(wk, 0xe);
        break;

    case 6:
        Command_Attack(wk, 0xe, 0x1e, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern10_0042(PLW* wk) {
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

void Pattern10_0043(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA0, 8, 8, 0x8400, 0, -1, -0x7FA0, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern10_0044(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA0, -0x7FC0, 8, 0x20, 0, -0x7FA0, 8, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern10_0045(PLW* wk) {
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

void Pattern10_0046(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8015, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern10_0047(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8016, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern10_0048(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8014, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern10_0049(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1F, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern10_0050(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1F, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern10_0051(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1F, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern10_0052(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x2E, 0x2F, 0xFFFF, 0);
        break;

    case 1:
        Command_Attack(wk, 8, 0x20, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern10_0053(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x2E, 0x2F, 0x30, 0x8040);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern10_0054(PLW* wk) {
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

void Pattern10_0055(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, -0x7FA0, -0x7FD0, 8, 0x40, 0, -0x7FA0, 8, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern10_0056(PLW* wk) {
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

void Pattern10_0057(PLW* wk) {
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

void Pattern10_0058(PLW* wk) {
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

void Pattern10_0059(PLW* wk) {
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

void Pattern10_0060(PLW* wk) {
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

void Pattern10_0061(PLW* wk) {
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

void Pattern10_0062(PLW* wk) {
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

void Pattern10_0063(PLW* wk) {
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

void Pattern10_0064(PLW* wk) {
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

void Pattern10_0065(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xB, 0x200);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1E, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern10_0066(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 6, 0x2D, 0x19, 0x10, 0x17, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern10_0067(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xD, 0x100);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern10_0068(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1D, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern10_0069(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1D, 8, -1);
        break;

    case 1:
        Lever_Attack(wk, 8, 0, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void (*const Pattern10_Tbl[70])(PLW*) = {
    Pattern10_0000, Pattern10_0001, Pattern10_0002, Pattern10_0003, Pattern10_0004, Pattern10_0005, Pattern10_0006,
    Pattern10_0007, Pattern10_0008, Pattern10_0009, Pattern10_0010, Pattern10_0011, Pattern10_0012, Pattern10_0013,
    Pattern10_0014, Pattern10_0015, Pattern10_0016, Pattern10_0017, Pattern10_0018, Pattern10_0019, Pattern10_0020,
    Pattern10_0021, Pattern10_0022, Pattern10_0023, Pattern10_0024, Pattern10_0025, Pattern10_0026, Pattern10_0027,
    Pattern10_0028, Pattern10_0029, Pattern10_0030, Pattern10_0031, Pattern10_0032, Pattern10_0033, Pattern10_0034,
    Pattern10_0035, Pattern10_0036, Pattern10_0037, Pattern10_0038, Pattern10_0039, Pattern10_0040, Pattern10_0041,
    Pattern10_0042, Pattern10_0043, Pattern10_0044, Pattern10_0045, Pattern10_0046, Pattern10_0047, Pattern10_0048,
    Pattern10_0049, Pattern10_0050, Pattern10_0051, Pattern10_0052, Pattern10_0053, Pattern10_0054, Pattern10_0055,
    Pattern10_0056, Pattern10_0057, Pattern10_0058, Pattern10_0059, Pattern10_0060, Pattern10_0061, Pattern10_0062,
    Pattern10_0063, Pattern10_0064, Pattern10_0065, Pattern10_0066, Pattern10_0067, Pattern10_0068, Pattern10_0069
};
