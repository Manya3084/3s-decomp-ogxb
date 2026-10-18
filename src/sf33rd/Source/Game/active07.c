/* active07.c, retail sf33rd.xbe.
 * PlayStation 2 C, not hand-adjusted for Xbox. Each named body was located
 * from the PS2 retail map: call graph, source order, and agreement of
 * constants, field offsets, callees, and size. See docs/decompiling.md.
 * The #include lines name headers in the PS2 tree (ps2.path).
 * Computer07 0xA1613 size 0x1A.
 * Pattern07_0001 0xA162D size 0x44.
 * Pattern07_0002 0xA1671 size 0x55.
 * Pattern07_0003 0xA16C6 size 0x45.
 * Pattern07_0004 0xA170B size 0x42.
 * Pattern07_0005 0xA174D size 0x4F.
 * Pattern07_0007 0xA179C size 0x4D.
 * Pattern07_0008 0xA17E9 size 0x75.
 * Pattern07_0009 0xA185E size 0x42.
 * Pattern07_0010 0xA18A0 size 0x69.
 * Pattern07_0011 0xA1909 size 0x51.
 * Pattern07_0012 0xA195A size 0x44.
 * Pattern07_0013 0xA199E size 0x69.
 * Pattern07_0014 0xA1A07 size 0x6E.
 * Pattern07_0018 0xA1A75 size 0x53.
 * Pattern07_0019 0xA1AC8 size 0x79.
 * Pattern07_0020 0xA1B41 size 0x42.
 * Pattern07_0021 0xA1B83 size 0x78.
 * Pattern07_0022 0xA1BFB size 0x58.
 * Pattern07_0026 0xA1C7E size 0x52.
 * Pattern07_0027 0xA1CD0 size 0x75.
 * Pattern07_0029 0xA1D6D size 0x43.
 * Pattern07_0030 0xA1DB0 size 0x47.
 * Pattern07_0031 0xA1DF7 size 0x57.
 * Pattern07_0032 0xA1E4E size 0x5D.
 * Pattern07_0033 0xA1EAB size 0x40.
 * Pattern07_0034 0xA1EEB size 0x5D.
 * Pattern07_0037 0xA1F48 size 0x56.
 * Pattern07_0038 0xA1F9E size 0x72.
 * Pattern07_0039 0xA2010 size 0x42.
 * Pattern07_0040 0xA2052 size 0x43.
 * Pattern07_0041 0xA2095 size 0x4A.
 * Pattern07_0042 0xA20DF size 0x4D.
 * Pattern07_0043 0xA212C size 0x3D.
 * Pattern07_0047 0xA21A6 size 0x3E.
 * Pattern07_0048 0xA21E4 size 0x64.
 * Pattern07_0049 0xA2248 size 0x6C.
 * Pattern07_0051 0xA22E3 size 0x55.
 * Pattern07_0052 0xA2338 size 0x3D.
 * Pattern07_0053 0xA2375 size 0x2E.
 * Pattern07_0056 0xA23A3 size 0x3D.
 * Pattern07_0057 0xA23E0 size 0x3D.
 * Pattern07_0058 0xA241D size 0x3D.
 * Pattern07_0059 0xA245A size 0x58.
 * Pattern07_0060 0xA24B2 size 0x3E.
 * Pattern07_0061 0xA24F0 size 0x41.
 * Pattern07_0062 0xA2531 size 0x47.
 * Pattern07_0067 0xA25BF size 0x2C.
 * Pattern07_0068 0xA25EB size 0x2C.
 * Pattern07_0069 0xA2617 size 0x3A.
 * Pattern07_0072 0xA2651 size 0x2E.
 * Pattern07_0073 0xA267F size 0x2F.
 * Pattern07_0074 0xA26AE size 0x2F.
 * Pattern07_0075 0xA26DD size 0x2F.
 * Pattern07_0000 is folded into 0xAB943 with 26 other bodies. Unnamed.
 * Pattern07_0006 is folded into 0x822AE with 19 other bodies. Unnamed.
 * Pattern07_0015 is folded into 0x9F683 with 8 other bodies. Unnamed.
 * Pattern07_0016 is folded into 0xA2A7B with 6 other bodies. Unnamed.
 * Pattern07_0017 is folded into 0x825DB with 2 other bodies. Unnamed.
 * Pattern07_0023 is folded into 0xA1C53 with 1 other bodies. Unnamed.
 * Pattern07_0024 is folded into 0xA6B63 with 7 other bodies. Unnamed.
 * Pattern07_0025 is folded into 0xA2C0E with 6 other bodies. Unnamed.
 * Pattern07_0028 is folded into 0xA1D45 with 1 other bodies. Unnamed.
 * Pattern07_0035 is folded into 0xD47E2 with 16 other bodies. Unnamed.
 * Pattern07_0036 is folded into 0xA9BB4 with 14 other bodies. Unnamed.
 * Pattern07_0044 is folded into 0xA2169 with 2 other bodies. Unnamed.
 * Pattern07_0045 is folded into 0xA3DB2 with 1 other bodies. Unnamed.
 * Pattern07_0046 is folded into 0x991B2 with 7 other bodies. Unnamed.
 * Pattern07_0050 is folded into 0xA22B4 with 4 other bodies. Unnamed.
 * Pattern07_0054 is folded into 0xAA7F4 with 5 other bodies. Unnamed.
 * Pattern07_0055 is folded into 0x9E7DC with 10 other bodies. Unnamed.
 * Pattern07_0063 is folded into 0xA2578 with 1 other bodies. Unnamed.
 * Pattern07_0064 is folded into 0x9FBB5 with 9 other bodies. Unnamed.
 * Pattern07_0065 is folded into 0x9FB89 with 6 other bodies. Unnamed.
 * Pattern07_0066 is folded into 0x9FB5D with 8 other bodies. Unnamed.
 * Pattern07_0070 is folded into 0x79913 with 1 other bodies. Unnamed.
 * Pattern07_0071 is folded into 0x79967 with 1 other bodies. Unnamed.
 */

#include "sf33rd/Source/Game/active07.h"
#include "common.h"
#include "sf33rd/Source/Game/Com_Sub.h"
#include "sf33rd/Source/Game/workuser.h"

void (*const Pattern07_Tbl[76])();

void Computer07(PLW* wk) {
    Pattern07_Tbl[(s16)Pattern_Index[wk->wu.id]](wk);
}

void Pattern07_0000(PLW* wk) {
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

void Pattern07_0001(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x102);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x102);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0002(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 0xB, 0x1C, 8, -1);
        break;

    case 1:
        Search_Back_Term(wk, 0x60, 1, -1);
        break;

    case 2:
        Command_Attack(wk, 8, 1, 0xB, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0003(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x10);
        break;

    case 1:
        Normal_Attack(wk, 9, 0x20);
        break;

    case 2:
        Normal_Attack(wk, 9, 0x400);
        break;

    case 3:
        Normal_Attack(wk, 8, 0x40);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0004(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1F, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0005(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x40);
        break;

    case 1:
        Lever_Attack(wk, 0xB, 0, 0x400);
        break;

    case 2:
        Command_Attack(wk, 8, 1, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0006(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0007(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x60, 1, -1);
        break;

    case 1:
        Pierce_On(wk);
        break;

    case 2:
        Command_Attack(wk, 8, 1, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0008(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7F90, -0x7FC0, 8, 0x40, 0, -0x7F90, -1, 0x200);
        break;

    case 1:
        Normal_Attack(wk, 9, 0x102);
        break;

    case 2:
        Lever_Attack(wk, 8, 0, 0x200);
        break;

    case 3:
        Normal_Attack(wk, 8, 0x402);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0009(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x20, 8, -1);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1E, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0010(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7F90, -0x7FC0, 8, 0x40, 0, -0x7F90, -1, 0x200);
        break;
    case 1:
        Normal_Attack(wk, 9, 0x102);
        break;
    case 2:
        Lever_Attack(wk, 8, 0, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0011(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x200);
        break;

    case 1:
        Lever_Attack(wk, 0xB, 0, 0x202);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0012(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x400);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x402);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0013(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xB, 0x200);
        break;

    case 1:
        J_Command_Attack(wk, 9, 0x1E, 9, -1);
        break;

    case 2:
        Search_Back_Term(wk, 0x60, 1, -1);
        break;

    case 3:
        Command_Attack(wk, 8, 1, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0014(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA0, -0x7FC0, 8, 0x200, 2, -0x7F80, -1, 0x200);
        break;

    case 1:
        Lever_Attack(wk, 9, 0, 0x200);
        break;

    case 2:
        Command_Attack(wk, 8, 0x1F, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0015(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 0, 0x30, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0016(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 1, 0x30, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0017(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x20, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0018(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x50, 1, -1);
        break;

    case 1:
        Jump(wk, 1);
        break;

    case 2:
        Lever_Off(wk);
        break;

    case 3:
        Look(wk, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0019(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7F9C, -0x7FC0, 8, 0x100, 0, -0x7F90, -1, 0x200);
        break;

    case 1:
        Normal_Attack(wk, 9, 0x102);
        break;

    case 2:
        Normal_Attack(wk, 9, 0x100);
        break;

    case 3:
        J_Command_Attack(wk, 8, 0x20, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0020(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1F, 0xA, -1);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1C, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0021(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7F9C, -0x7FC0, 8, 0x20, 0, -0x7F90, -1, 0x200);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x102);
        break;

    case 2:
        Normal_Attack(wk, 9, 0x400);
        break;

    case 3:
        J_Command_Attack(wk, 8, 0x1C, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0022(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA0, -0x7FC0, 8, 0x40, 0, -0x7F90, -1, 0x100);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1F, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0023(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xC7, 2);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0024(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 0, 0x60, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0025(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 1, 0x60, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0026(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0, 0xA, -1);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;

    case 2:
        Lever_Off(wk);
        break;

    case 3:
        Look(wk, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0027(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump(wk, 0);
        break;

    case 1:
        Normal_Attack(wk, 9, 0x10);
        break;

    case 2:
        Command_Attack(wk, 8, 0x1d, 10, -1);
        break;

    case 3:
        Normal_Attack(wk, 8, 0x10);
        break;

    case 4:
        Search_Back_Term(wk, 0x60, 1, -1);
        break;

    case 5:
        Command_Attack(wk, 8, 1, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0028(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x78, 2);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0029(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 9, 0x100);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1F, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0030(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 9, 0x100);
        break;

    case 1:
        Adjust_Attack(wk, 9, 0x100);
        break;

    case 2:
        Lever_Attack(wk, 8, 0, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0031(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA0, -0x7FC0, 9, 0x200, 0, -0x7F68, -1, 0x200);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x402);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0032(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xB, 0x10);
        break;

    case 1:
        Normal_Attack(wk, 0xB, 0x20);
        break;

    case 2:
        Lever_Attack(wk, 0xB, 0, 0x100);
        break;

    case 3:
        J_Command_Attack(wk, 8, 0x1F, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0033(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 0xB, 0x10);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x20, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0034(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x100);
        break;

    case 1:
        Normal_Attack(wk, 0xB, 0x202);
        break;

    case 2:
        Normal_Attack(wk, 0xB, 0x200);
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

void Pattern07_0035(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0036(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x42);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0037(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x110);
        break;

    case 1:
        Search_Back_Term(wk, 0x60, 1, -1);
        break;

    case 2:
        Command_Attack(wk, 8, 1, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0038(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x35, 0x36, 0x37, 0);
        break;

    case 1:
        Pierce_On(wk);
        break;

    case 2:
        Adjust_Attack(wk, 0xB, 0x20);
        break;

    case 3:
        Normal_Attack(wk, 0xB, 0x202);
        break;

    case 4:
        Lever_Attack(wk, 8, 0, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0039(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0, 0xA, -1);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0040(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x202);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0041(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xB, 0x102);
        break;

    case 1:
        Normal_Attack(wk, 0xB, 0x20);
        break;

    case 2:
        J_Command_Attack(wk, 8, 0x20, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0042(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x12);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x12);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x202);
        break;

    case 3:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0043(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA0, -0x7FC0, 8, 0x40, 0, -1, 0x30, 0x4020);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0044(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA0, -0x7FC0, 8, 0x40, 0, -1, 0x30, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0045(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA0, -0x7FC0, 8, 0x400, 0, -1, -1, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0046(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0047(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Command_Attack_Term(wk, 8, 0x2E, 9, -1, -0x7FA0, 0x38, 0x0, -1, 0x30, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0048(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x20);
        break;

    case 1:
        Lever_Attack(wk, 8, 0, 0x100);
        break;

    case 2:
        Jump_Command_Attack_Term(wk, 8, 0x2E, 0xA, -1, -1, 0x38, 1, -1, -1, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0049(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, -1, -0x7FC8, 8, 0x200, 0, -0x7FA8, -1, 0x200);
        break;

    case 1:
        Lever_Attack(wk, 9, 0, 0x100);
        break;

    case 2:
        Lever_Attack(wk, 9, 0, 0x100);
        break;

    case 3:
        Normal_Attack(wk, 8, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0050(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack(wk, 8, 0xA, 0x400, 2);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0051(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, -1, -0x7FC8, 8, 0x20, 0, -0x7FA8, -1, 0x200);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0052(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Command_Attack_Term(wk, 8, 0x8126, 0xA, -1, -1, 0x30, 0, -1, -1, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0053(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Branch_Unit_Area(wk, 2, 0x38, 0x3A, 0x3A, 0x3A);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0054(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8015, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0055(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8014, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0056(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x8126, 9, -1, -1, 0x40, 1, -1, -1, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0057(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x8126, 9, -1, -1, 0x40, 2, -1, -1, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0058(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x8126, 0xA, -1, -1, 0x30, 2, -1, -1, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0059(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0, 0xB, -1);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1D, 9, -1);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x200);
        break;

    case 3:
        Normal_Attack(wk, 8, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0060(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 0, 0x15, 0);
        break;

    case 1:
        Walk(wk, 1, 0x14, 0);
        break;

    case 2:
        Walk(wk, 0, 0x10, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0061(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 1, 0x14, 0);
        break;

    case 1:
        Walk(wk, 0, 0x10, 0);
        break;

    case 2:
        Walk(wk, 1, 0x18, 0);
        break;

    case 3:
        Walk(wk, 0, 0x10, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0062(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 0, 0x10, 0);
        break;

    case 1:
        Walk(wk, 1, 0x18, 0);
        break;

    case 2:
        Wait(wk, 0x10);
        break;

    case 3:
        Walk(wk, 0, 0x10, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0063(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F98, 0, 4, 2, 0);
        break;

    case 1:
        Command_Attack(wk, 8, 0, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0064(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1F, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0065(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1F, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0066(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1F, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0067(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x22, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0068(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x22, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0069(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x22, 0xA, -1);
        break;

    case 1:
        Command_Attack(wk, 8, 0x20, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0070(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1F, 0xA, -1);
        break;

    case 1:
        EM_Term(wk, 0x50, -0x7FB0, 8, 1, -1);
        break;

    case 2:
        Command_Attack(wk, 8, 0x2E, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0071(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1F, 0xA, -1);
        break;

    case 1:
        EM_Term(wk, 0x50, -0x7FB0, 8, 1, -1);
        break;

    case 2:
        SA_Term(wk, 0x48, 0xFFFF, 0xFFFF, 0);
        break;

    case 3:
        Command_Attack(wk, 8, 0x2E, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0072(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Branch_Unit_Area(wk, 2, 0x49, 0x49, 0x4A, 0x4B);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0073(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8126, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0074(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8126, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0075(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8126, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void (*const Pattern07_Tbl[76])(PLW*) = {
    Pattern07_0000, Pattern07_0001, Pattern07_0002, Pattern07_0003, Pattern07_0004, Pattern07_0005, Pattern07_0006,
    Pattern07_0007, Pattern07_0008, Pattern07_0009, Pattern07_0010, Pattern07_0011, Pattern07_0012, Pattern07_0013,
    Pattern07_0014, Pattern07_0015, Pattern07_0016, Pattern07_0017, Pattern07_0018, Pattern07_0019, Pattern07_0020,
    Pattern07_0021, Pattern07_0022, Pattern07_0023, Pattern07_0024, Pattern07_0025, Pattern07_0026, Pattern07_0027,
    Pattern07_0028, Pattern07_0029, Pattern07_0030, Pattern07_0031, Pattern07_0032, Pattern07_0033, Pattern07_0034,
    Pattern07_0035, Pattern07_0036, Pattern07_0037, Pattern07_0038, Pattern07_0039, Pattern07_0040, Pattern07_0041,
    Pattern07_0042, Pattern07_0043, Pattern07_0044, Pattern07_0045, Pattern07_0046, Pattern07_0047, Pattern07_0048,
    Pattern07_0049, Pattern07_0050, Pattern07_0051, Pattern07_0052, Pattern07_0053, Pattern07_0054, Pattern07_0055,
    Pattern07_0056, Pattern07_0057, Pattern07_0058, Pattern07_0059, Pattern07_0060, Pattern07_0061, Pattern07_0062,
    Pattern07_0063, Pattern07_0064, Pattern07_0065, Pattern07_0066, Pattern07_0067, Pattern07_0068, Pattern07_0069,
    Pattern07_0070, Pattern07_0071, Pattern07_0072, Pattern07_0073, Pattern07_0074, Pattern07_0075
};
