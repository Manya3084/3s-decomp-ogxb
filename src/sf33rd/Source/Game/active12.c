/* active12.c, retail sf33rd.xbe.
 * PlayStation 2 C, not hand-adjusted for Xbox. Each named body was located
 * from the PS2 retail map: call graph, source order, and agreement of
 * constants, field offsets, callees, and size. See docs/decompiling.md.
 * The #include lines name headers in the PS2 tree (ps2.path).
 * Pattern12_0040 is folded into 0x82A2A with 1 other bodies. Unnamed.
 * Pattern12_0041 is folded into 0x82A82 with 1 other bodies. Unnamed.
 * Pattern12_0035 is folded into 0x833D3 with 1 other bodies. Unnamed.
 * Pattern12_0047 is folded into 0x84130 with 1 other bodies. Unnamed.
 * Pattern12_0036 is folded into 0x847C5 with 1 other bodies. Unnamed.
 * Pattern12_0037 is folded into 0x84E71 with 1 other bodies. Unnamed.
 * Pattern12_0028 0xA5EFE size 0x4C.
 * Pattern12_0029 0xA5F4A size 0x4B.
 * Pattern12_0030 0xA5F95 size 0x47.
 * Pattern12_0031 0xA5FDC size 0x46.
 * Pattern12_0032 0xA6022 size 0x40.
 * Pattern12_0033 is folded into 0xA6062 with 1 other bodies. Unnamed.
 * Pattern12_0038 0xA60E0 size 0x53.
 * Pattern12_0039 is folded into 0xA6133 with 1 other bodies. Unnamed.
 * Pattern12_0042 0xA6195 size 0x6A.
 * Pattern12_0043 is folded into 0xA61FF with 1 other bodies. Unnamed.
 * Pattern12_0045 is folded into 0xA626B with 1 other bodies. Unnamed.
 * Pattern12_0046 0xA62D4 size 0x8C.
 * Pattern12_0049 0xA6360 size 0x2F.
 * Pattern12_0052 is folded into 0xA63B7 with 1 other bodies. Unnamed.
 * Pattern12_0055 is folded into 0xA642D with 1 other bodies. Unnamed.
 * Pattern12_0062 0xA6512 size 0x28.
 * Pattern12_0067 0xA653A size 0x46.
 * Pattern12_0068 0xA6580 size 0x4E.
 * Pattern12_0071 0xA65CE size 0x76.
 * Pattern12_0072 0xA6644 size 0x89.
 * Pattern12_0073 0xA66CD size 0x4D.
 * Pattern12_0074 0xA671A size 0x59.
 * Pattern12_0074 0xA671A size 0x59.
 * Pattern12_0075 0xA6773 size 0x5C.
 * Pattern12_0076 is folded into 0xA67CF with 1 other bodies. Unnamed.
 * Pattern12_0077 0xA6807 size 0x41.
 * Pattern12_0079 0xA688E size 0x46.
 * Pattern12_0080 0xA68D4 size 0x47.
 * Pattern12_0083 0xA6947 size 0x40.
 * Pattern12_0084 0xA6987 size 0x3E.
 * Pattern12_0000 is folded into 0xAB943 with 44 other bodies. Unnamed.
 * Pattern12_0001 is folded into 0x822AE with 23 other bodies. Unnamed.
 * Pattern12_0002 is folded into 0xA50BB with 3 other bodies. Unnamed.
 * Pattern12_0003 is folded into 0xA50FC with 3 other bodies. Unnamed.
 * Pattern12_0004 is folded into 0xD351F with 2 other bodies. Unnamed.
 * Pattern12_0005 is folded into 0x82920 with 4 other bodies. Unnamed.
 * Pattern12_0006 is folded into 0x8294C with 3 other bodies. Unnamed.
 * Pattern12_0007 is folded into 0x82978 with 10 other bodies. Unnamed.
 * Pattern12_0008 is folded into 0x82583 with 2 other bodies. Unnamed.
 * Pattern12_0009 is folded into 0x825AF with 3 other bodies. Unnamed.
 * Pattern12_0010 is folded into 0x825DB with 3 other bodies. Unnamed.
 * Pattern12_0011 is folded into 0xDFCF2 with 13 other bodies. Unnamed.
 * Pattern12_0012 is folded into 0xD47E2 with 27 other bodies. Unnamed.
 * Pattern12_0013 is folded into 0x71E79 with 26 other bodies. Unnamed.
 * Pattern12_0014 is folded into 0xA5E79 with 7 other bodies. Unnamed.
 * Pattern12_0015 is folded into 0xA9FA1 with 25 other bodies. Unnamed.
 * Pattern12_0016 is folded into 0x6D0A6 with 29 other bodies. Unnamed.
 * Pattern12_0017 is folded into 0x8278B with 2 other bodies. Unnamed.
 * Pattern12_0018 is folded into 0x827BA with 2 other bodies. Unnamed.
 * Pattern12_0019 is folded into 0xA5EA4 with 2 other bodies. Unnamed.
 * Pattern12_0020 is folded into 0xA9FA1 with 25 other bodies. Unnamed.
 * Pattern12_0021 is folded into 0xA9FF7 with 32 other bodies. Unnamed.
 * Pattern12_0022 is folded into 0xA9FCC with 33 other bodies. Unnamed.
 * Pattern12_0023 is folded into 0xE33B0 with 14 other bodies. Unnamed.
 * Pattern12_0024 is folded into 0x8303D with 7 other bodies. Unnamed.
 * Pattern12_0025 is folded into 0xDAC4C with 25 other bodies. Unnamed.
 * Pattern12_0026 is folded into 0x80B9B with 4 other bodies. Unnamed.
 * Pattern12_0027 is folded into 0xA5ED3 with 3 other bodies. Unnamed.
 * Pattern12_0034 is folded into 0xA60B5 with 5 other bodies. Unnamed.
 * Pattern12_0044 is folded into 0xA5579 with 7 other bodies. Unnamed.
 * Pattern12_0048 is folded into 0x9E7DC with 17 other bodies. Unnamed.
 * Pattern12_0050 is folded into 0xAA823 with 13 other bodies. Unnamed.
 * Pattern12_0051 is folded into 0xA638F with 4 other bodies. Unnamed.
 * Pattern12_0053 is folded into 0xA6405 with 2 other bodies. Unnamed.
 * Pattern12_0054 is folded into 0x9F53F with 8 other bodies. Unnamed.
 * Pattern12_0056 is folded into 0xA9A3E with 17 other bodies. Unnamed.
 * Pattern12_0057 is folded into 0xA6476 with 1 other bodies. Unnamed.
 * Pattern12_0058 is folded into 0xA5839 with 1 other bodies. Unnamed.
 * Pattern12_0059 is folded into 0xAA09A with 13 other bodies. Unnamed.
 * Pattern12_0060 is folded into 0xA5879 with 9 other bodies. Unnamed.
 * Pattern12_0061 is folded into 0x73AC3 with 5 other bodies. Unnamed.
 * Pattern12_0063 is folded into 0xA638F with 4 other bodies. Unnamed.
 * Pattern12_0064 is folded into 0xA60B5 with 5 other bodies. Unnamed.
 * Pattern12_0065 is folded into 0xA60B5 with 5 other bodies. Unnamed.
 * Pattern12_0066 is folded into 0xA6848 with 1 other bodies. Unnamed.
 * Pattern12_0069 is folded into 0xE2EEB with 25 other bodies. Unnamed.
 * Pattern12_0070 is folded into 0xE2F17 with 22 other bodies. Unnamed.
 * Pattern12_0078 is folded into 0xA6848 with 1 other bodies. Unnamed.
 * Pattern12_0081 is folded into 0xA691B with 1 other bodies. Unnamed.
 * Pattern12_0082 is folded into 0xA691B with 1 other bodies. Unnamed.
 * Pattern12_0085 is folded into 0x9E572 with 12 other bodies. Unnamed.
 * The other functions in this file are not located in sf33rd.xbe yet.
 */

#include "sf33rd/Source/Game/active12.h"
#include "common.h"
#include "sf33rd/Source/Game/Com_Sub.h"
#include "sf33rd/Source/Game/workuser.h"

void (*const Pattern12_Tbl[86])();

void Computer12(PLW* wk) {
    Pattern12_Tbl[(s16)Pattern_Index[wk->wu.id]](wk);
}

void Pattern12_0000(PLW* wk) {
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

void Pattern12_0001(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern12_0002(PLW* wk) {
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

void Pattern12_0003(PLW* wk) {
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

void Pattern12_0004(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x110);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern12_0005(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1D, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern12_0006(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1D, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern12_0007(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern12_0008(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x20, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern12_0009(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x20, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern12_0010(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x20, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern12_0011(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x10);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x10);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x10);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern12_0012(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern12_0013(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x40);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern12_0014(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x100);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern12_0015(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern12_0016(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern12_0017(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1C, 0x4008, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern12_0018(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1C, 0x4009, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern12_0019(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1C, 0x400A, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern12_0020(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern12_0021(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x202);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern12_0022(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x402);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern12_0023(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern12_0024(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0, -1, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern12_0025(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump(wk, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern12_0026(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 1, 0x20, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern12_0027(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Away(wk, 0xBF, 1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern12_0028(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;

    case 1:
        Jump(wk, 0);
        break;

    case 2:
        Com_Random_Select(wk, 6, 2, 4, 0x20, 0xA, 4);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern12_0029(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;

    case 1:
        Jump(wk, 0);
        break;

    case 2:
        Com_Random_Select(wk, 6, 2, 4, 0, 0xD, 3);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern12_0030(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Away(wk, 0xBF, 1);
        break;

    case 1:
        Com_Random_Select(wk, 6, 0x11, 0, 0x10, 0x2F, 3);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern12_0031(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 1, 0x20, -1);
        break;

    case 1:
        Com_Random_Select(wk, 6, 0x11, 0, 0x24, 0x23, 3);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern12_0032(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x20);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern12_0033(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;

    case 1:
        SA_Term(wk, 0x30, 0x31, 0x32, 0);
        break;

    case 2:
        J_Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern12_0034(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Away(wk, 0xBF, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern12_0035(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xB, 0x202);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1C, 0x4009, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern12_0036(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x400);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1C, 0x400A, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern12_0037(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xC, 0x40);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern12_0038(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1D, 9, -1);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1D, 9, -1);
        break;

    case 2:
        J_Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;

    case 3:
        Com_Random_Select(wk, 6, 0, 0xA, 0x13, 0x1F, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern12_0039(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;

    case 1:
        Normal_Attack(wk, 0xC, 0x40);
        break;

    case 2:
        SA_Term(wk, 0x30, 0x31, 0x32, 0);
        break;

    case 3:
        J_Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern12_0040(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA8, -0x7FC0, 9, 0x20, 0, -0x7FB0, -1, 0x200);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1D, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern12_0041(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA8, -0x7FC0, 9, 0x200, 0, -0x7FB0, -1, 0x20);
        break;

    case 1:
        Normal_Attack(wk, 0xB, 0x20);
        break;

    case 2:
        J_Command_Attack(wk, 8, 0x20, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern12_0042(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA8, -0x7FC0, 0xB, 0x200, 0, -1, -1, -1);
        break;

    case 1:
        SA_Term(wk, 0x30, 0x31, 0x32, 0);
        break;

    case 2:
        Command_Attack(wk, 8, 0x1C, 0x400A, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern12_0043(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA8, -0x7FC0, 0xB, 0x200, 0, -0x7FB0, -1, 0x40);
        break;

    case 1:
        Normal_Attack(wk, 0xB, 0x400);
        break;

    case 2:
        J_Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern12_0044(PLW* wk) {
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

void Pattern12_0045(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA0, -0x7FC0, 9, 0x40, 0, -0x7FB0, -1, 0x200);
        break;

    case 1:
        Normal_Attack(wk, 9, 0x40);
        break;

    case 2:
        J_Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern12_0046(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA0, -0x7FC0, 9, 0x40, 0, -0x7FB0, -1, 0x200);
        break;

    case 1:
        Normal_Attack(wk, 9, 0x40);
        break;

    case 2:
        Command_Attack(wk, 0xC, 0x1C, 0x400A, -1);
        break;

    case 3:
        Wait(wk, 5);
        break;

    case 4:
        SA_Term(wk, 0x30, 0x31, 0x32, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern12_0047(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;

    case 1:
        Command_Attack(wk, 0xC, 0, -1, -1);
        break;

    case 2:
        J_Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern12_0048(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8014, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern12_0049(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x8215, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern12_0050(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8016, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern12_0051(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Away(wk, 0x7F, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern12_0052(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x20, 0xA, -1);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x402);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern12_0053(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern12_0054(PLW* wk) {
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

void Pattern12_0055(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x10);
        break;

    case 1:
        Normal_Attack(wk, 0xB, 0x10);
        break;

    case 2:
        J_Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern12_0056(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x7F, 2);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern12_0057(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, 0x8058, 0x8040, 9, 0x20, 0, 0x8050, -1, 0x200);
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
        Command_Attack(wk, 8, 0x1c, 0x4008, -1);
        break;

    case 5:
        Com_Random_Select(wk, 6, 0x2d, 0xff, 0xff, 0xff, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern12_0058(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA8, -0x7FC0, 9, 0x200, 0, -0x7FB0, -1, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern12_0059(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBF, 2);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern12_0060(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x102);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern12_0061(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x12);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern12_0062(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Away(wk, 0x37, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern12_0063(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Away(wk, 0x7F, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern12_0064(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Away(wk, 0xBF, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern12_0065(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Away(wk, 0xBF, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern12_0066(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xB, 0x12);
        break;

    case 1:
        Normal_Attack(wk, 0xB, 0x12);
        break;

    case 2:
        Command_Attack(wk, 8, 0x1C, 0x400A, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern12_0067(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x102);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x102);
        break;

    case 2:
        Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern12_0068(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x10);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x20);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x40);
        break;

    case 3:
        Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern12_0069(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern12_0070(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern12_0071(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA8, -0x7FC0, 9, 0x200, 0, -0x7FB0, -1, 0x200);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x102);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x202);
        break;

    case 3:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern12_0072(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA0, -0x7FC0, 9, 0x200, 0, -0x7FB0, -1, 0x200);
        break;

    case 1:
        Normal_Attack(wk, 9, 0x40);
        break;

    case 2:
        Command_Attack(wk, 0xC, 0x1D, 0xA, -1);
        break;

    case 3:
        Wait(wk, 5);
        break;

    case 4:
        SA_Term(wk, 0x30, 0x31, 0x32, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern12_0073(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x40);
        break;

    case 1:
        Command_Attack(wk, 0xC, 0x1C, 9, -1);
        break;

    case 2:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern12_0074(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x93, 2);
        break;

    case 1:
        SA_Term(wk, 0xFFFF, 0x31, 0xFFFF, 0);
        break;

    case 2:
        J_Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern12_0075(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x202);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x202);
        break;

    case 2:
        SA_Term(wk, 0xFFFF, 0x30, 0xFFFF, 0);
        break;

    case 3:
        J_Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern12_0076(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1E, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern12_0077(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Away(wk, 0xBF, 0);
        break;

    case 1:
        Keep_Away(wk, 0x7F, 0);
        break;

    case 2:
        Keep_Away(wk, 0xBF, 0);
        break;

    case 3:
        Keep_Away(wk, 0x37, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern12_0078(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xB, 0x12);
        break;

    case 1:
        Normal_Attack(wk, 0xB, 0x12);
        break;

    case 2:
        Command_Attack(wk, 8, 0x1C, 0x400A, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern12_0079(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xB, 0x402);
        break;

    case 1:
        Normal_Attack(wk, 0xB, 0x402);
        break;

    case 2:
        Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern12_0080(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x10);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x20);
        break;

    case 2:
        J_Command_Attack(wk, 8, 0x1D, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern12_0081(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 0xC, 0x20, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern12_0082(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 0xC, 0x20, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern12_0083(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump(wk, 0xC, 1);
        break;

    case 1:
        Command_Attack(wk, 0xC, 0x20, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern12_0084(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ETC_Term(wk, 5, 1, 0xFFFF);
        break;

    case 1:
        Provoke(wk, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern12_0085(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void (*const Pattern12_Tbl[86])(PLW*) = {
    Pattern12_0000, Pattern12_0001, Pattern12_0002, Pattern12_0003, Pattern12_0004, Pattern12_0005, Pattern12_0006,
    Pattern12_0007, Pattern12_0008, Pattern12_0009, Pattern12_0010, Pattern12_0011, Pattern12_0012, Pattern12_0013,
    Pattern12_0014, Pattern12_0015, Pattern12_0016, Pattern12_0017, Pattern12_0018, Pattern12_0019, Pattern12_0020,
    Pattern12_0021, Pattern12_0022, Pattern12_0023, Pattern12_0024, Pattern12_0025, Pattern12_0026, Pattern12_0027,
    Pattern12_0028, Pattern12_0029, Pattern12_0030, Pattern12_0031, Pattern12_0032, Pattern12_0033, Pattern12_0034,
    Pattern12_0035, Pattern12_0036, Pattern12_0037, Pattern12_0038, Pattern12_0039, Pattern12_0040, Pattern12_0041,
    Pattern12_0042, Pattern12_0043, Pattern12_0044, Pattern12_0045, Pattern12_0046, Pattern12_0047, Pattern12_0048,
    Pattern12_0049, Pattern12_0050, Pattern12_0051, Pattern12_0052, Pattern12_0053, Pattern12_0054, Pattern12_0055,
    Pattern12_0056, Pattern12_0057, Pattern12_0058, Pattern12_0059, Pattern12_0060, Pattern12_0061, Pattern12_0062,
    Pattern12_0063, Pattern12_0064, Pattern12_0065, Pattern12_0066, Pattern12_0067, Pattern12_0068, Pattern12_0069,
    Pattern12_0070, Pattern12_0071, Pattern12_0072, Pattern12_0073, Pattern12_0074, Pattern12_0075, Pattern12_0076,
    Pattern12_0077, Pattern12_0078, Pattern12_0079, Pattern12_0080, Pattern12_0081, Pattern12_0082, Pattern12_0083,
    Pattern12_0084, Pattern12_0085
};
