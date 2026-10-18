/* PASS03.c, retail sf33rd.xbe.
 * PlayStation 2 C, not hand-adjusted for Xbox. Each named body was located
 * from the PS2 retail map: call graph, source order, and agreement of
 * constants, field offsets, callees, and size. See docs/decompiling.md.
 * The #include lines name headers in the PS2 tree (ps2.path).
 * Passive03 0x6FF97 size 0x1A.
 * Passive03_0006 0x6FFB1 size 0x45.
 * Passive03_0007 0x6FFF6 size 0x43.
 * Passive03_0013 0x70080 size 0x87.
 * Passive03_0016 0x7014F size 0x70.
 * Passive03_0017 0x701BF size 0xA6.
 * Passive03_0018 0x70265 size 0x62.
 * Passive03_0022 0x702C7 size 0x7D.
 * Passive03_0023 0x70344 size 0x71.
 * Passive03_0024 0x703B5 size 0x6C.
 * Passive03_0025 0x70421 size 0x70.
 * Passive03_0032 0x70516 size 0x5F.
 * Passive03_0034 0x70575 size 0x40.
 * Passive03_0043 0x70636 size 0x49.
 * Passive03_0044 0x7067F size 0x5A.
 * Passive03_0061 0x70841 size 0x46.
 * Passive03_0062 0x70887 size 0x41.
 * Passive03_0063 0x708C8 size 0x40.
 * Passive03_0065 0x70908 size 0x52.
 * Passive03_0071 0x7099F size 0x4B.
 * Passive03_0073 0x709EA size 0x66.
 * Passive03_0075 0x70A50 size 0x88.
 * Passive03_0076 0x70AD8 size 0xA1.
 * Passive03_0078 0x70B79 size 0x6F.
 * Passive03_0083 0x70BE8 size 0x75.
 * Passive03_0086 0x70C5D size 0x8D.
 * Passive03_0087 0x70CEA size 0x96.
 * Passive03_0097 0x70E4B size 0x5B.
 * Passive03_0098 0x70EA6 size 0x7B.
 * Passive03_0100 0x70F21 size 0x52.
 * Passive03_0102 0x70FB8 size 0x5D.
 * Passive03_0103 0x71015 size 0x4E.
 * Passive03_0104 0x71063 size 0x28.
 * Passive03_0112 0x711A7 size 0x5D.
 * Passive03_0115 0x7124A size 0x4F.
 * Passive03_0121 0x71332 size 0x2E.
 * Passive03_0127 0x7138C size 0x39.
 * Passive03_0128 0x713C5 size 0x2C.
 * Passive03_0129 0x713F1 size 0x2F.
 * Passive03_0131 0x71420 size 0x40.
 * Passive03_0132 0x71460 size 0x40.
 * Passive03_0133 0x714A0 size 0x43.
 * Passive03_0088 is folded into 0x70D80 with 1 other bodies. Unnamed.
 * Passive03_0000 is folded into 0xD0F75 with 19 other bodies. Unnamed.
 * Passive03_0001 is folded into 0xAB943 with 44 other bodies. Unnamed.
 * Passive03_0002 is folded into 0xD0FA4 with 3 other bodies. Unnamed.
 * Passive03_0003 is folded into 0xDC466 with 15 other bodies. Unnamed.
 * Passive03_0004 is folded into 0xD2B75 with 1 other bodies. Unnamed.
 * Passive03_0005 is folded into 0x7EE7B with 30 other bodies. Unnamed.
 * Passive03_0008 is folded into 0x70039 with 1 other bodies. Unnamed.
 * Passive03_0009 is folded into 0xD2BFA with 1 other bodies. Unnamed.
 * Passive03_0010 is folded into 0xD2C43 with 1 other bodies. Unnamed.
 * Passive03_0011 is folded into 0xD2C8A with 3 other bodies. Unnamed.
 * Passive03_0012 is folded into 0xD2CC4 with 1 other bodies. Unnamed.
 * Passive03_0014 is folded into 0x70107 with 1 other bodies. Unnamed.
 * Passive03_0015 is folded into 0x6D0D1 with 24 other bodies. Unnamed.
 * Passive03_0019 is folded into 0x6D0D1 with 24 other bodies. Unnamed.
 * Passive03_0020 is folded into 0x6D236 with 23 other bodies. Unnamed.
 * Passive03_0021 is folded into 0xDDE9A with 5 other bodies. Unnamed.
 * Passive03_0026 is folded into 0xD30D1 with 1 other bodies. Unnamed.
 * Passive03_0027 is folded into 0xE2EEB with 25 other bodies. Unnamed.
 * Passive03_0028 is folded into 0x70491 with 1 other bodies. Unnamed.
 * Passive03_0029 is folded into 0xDFCF2 with 13 other bodies. Unnamed.
 * Passive03_0030 is folded into 0x704CE with 2 other bodies. Unnamed.
 * Passive03_0031 is folded into 0x6E9E1 with 12 other bodies. Unnamed.
 * Passive03_0033 is folded into 0xDDB8D with 22 other bodies. Unnamed.
 * Passive03_0035 is folded into 0x705B5 with 1 other bodies. Unnamed.
 * Passive03_0036 is folded into 0xD31B5 with 1 other bodies. Unnamed.
 * Passive03_0037 is folded into 0xD3204 with 1 other bodies. Unnamed.
 * Passive03_0038 is folded into 0xD324E with 1 other bodies. Unnamed.
 * Passive03_0039 is folded into 0xD3296 with 1 other bodies. Unnamed.
 * Passive03_0040 is folded into 0xD32DA with 1 other bodies. Unnamed.
 * Passive03_0041 is folded into 0xD333B with 1 other bodies. Unnamed.
 * Passive03_0042 is folded into 0x705F9 with 3 other bodies. Unnamed.
 * Passive03_0045 is folded into 0xD3439 with 3 other bodies. Unnamed.
 * Passive03_0046 is folded into 0x706D9 with 12 other bodies. Unnamed.
 * Passive03_0047 is folded into 0x70701 with 1 other bodies. Unnamed.
 * Passive03_0048 is folded into 0xDE286 with 11 other bodies. Unnamed.
 * Passive03_0049 is folded into 0x70746 with 5 other bodies. Unnamed.
 * Passive03_0050 is folded into 0xD3482 with 2 other bodies. Unnamed.
 * Passive03_0051 is folded into 0x7076E with 5 other bodies. Unnamed.
 * Passive03_0052 is folded into 0xA9FF7 with 32 other bodies. Unnamed.
 * Passive03_0053 is folded into 0x705F9 with 3 other bodies. Unnamed.
 * Passive03_0054 is folded into 0xD2C8A with 3 other bodies. Unnamed.
 * Passive03_0055 is folded into 0xA340F with 7 other bodies. Unnamed.
 * Passive03_0056 is folded into 0x70799 with 3 other bodies. Unnamed.
 * Passive03_0057 is folded into 0x707D3 with 1 other bodies. Unnamed.
 * Passive03_0058 is folded into 0xD34B4 with 13 other bodies. Unnamed.
 * Passive03_0059 is folded into 0x7080D with 1 other bodies. Unnamed.
 * Passive03_0060 is folded into 0x7EE7B with 30 other bodies. Unnamed.
 * Passive03_0064 is folded into 0xE33B0 with 14 other bodies. Unnamed.
 * Passive03_0066 is folded into 0xD35AE with 1 other bodies. Unnamed.
 * Passive03_0067 is folded into 0x9E903 with 8 other bodies. Unnamed.
 * Passive03_0068 is folded into 0x70799 with 3 other bodies. Unnamed.
 * Passive03_0069 is folded into 0xD35F2 with 1 other bodies. Unnamed.
 * Passive03_0070 is folded into 0x7095A with 1 other bodies. Unnamed.
 * Passive03_0072 is folded into 0x70039 with 1 other bodies. Unnamed.
 * Passive03_0074 is folded into 0xD3730 with 1 other bodies. Unnamed.
 * Passive03_0077 is folded into 0xD38C2 with 1 other bodies. Unnamed.
 * Passive03_0079 is folded into 0xD3982 with 1 other bodies. Unnamed.
 * Passive03_0080 is folded into 0xD39D0 with 1 other bodies. Unnamed.
 * Passive03_0081 is folded into 0xD3A21 with 1 other bodies. Unnamed.
 * Passive03_0082 is folded into 0xD3A84 with 1 other bodies. Unnamed.
 * Passive03_0084 is folded into 0xD3B4D with 1 other bodies. Unnamed.
 * Passive03_0085 is folded into 0xD3BC5 with 1 other bodies. Unnamed.
 * Passive03_0089 is folded into 0x9FB5D with 12 other bodies. Unnamed.
 * Passive03_0090 is folded into 0x9FB89 with 10 other bodies. Unnamed.
 * Passive03_0091 is folded into 0x9FBB5 with 13 other bodies. Unnamed.
 * Passive03_0092 is folded into 0xD3439 with 3 other bodies. Unnamed.
 * Passive03_0093 is folded into 0xDDAB7 with 9 other bodies. Unnamed.
 * Passive03_0094 is folded into 0xD3D25 with 3 other bodies. Unnamed.
 * Passive03_0095 is folded into 0x70E07 with 1 other bodies. Unnamed.
 * Passive03_0096 is folded into 0xD54CF with 3 other bodies. Unnamed.
 * Passive03_0099 is folded into 0xD3DCE with 3 other bodies. Unnamed.
 * Passive03_0101 is folded into 0x70F73 with 1 other bodies. Unnamed.
 * Passive03_0105 is folded into 0xD3F4A with 1 other bodies. Unnamed.
 * Passive03_0106 is folded into 0x7108B with 1 other bodies. Unnamed.
 * Passive03_0107 is folded into 0xD3FA8 with 1 other bodies. Unnamed.
 * Passive03_0108 is folded into 0x710D9 with 1 other bodies. Unnamed.
 * Passive03_0109 is folded into 0xD3FEF with 1 other bodies. Unnamed.
 * Passive03_0110 is folded into 0x71104 with 1 other bodies. Unnamed.
 * Passive03_0111 is folded into 0x7115F with 1 other bodies. Unnamed.
 * Passive03_0113 is folded into 0x71204 with 1 other bodies. Unnamed.
 * Passive03_0114 is folded into 0xDD6B3 with 6 other bodies. Unnamed.
 * Passive03_0116 is folded into 0x71299 with 1 other bodies. Unnamed.
 * Passive03_0117 is folded into 0xD40E2 with 1 other bodies. Unnamed.
 * Passive03_0118 is folded into 0x712D0 with 1 other bodies. Unnamed.
 * Passive03_0119 is folded into 0x6D0A6 with 29 other bodies. Unnamed.
 * Passive03_0120 is folded into 0x71307 with 3 other bodies. Unnamed.
 * Passive03_0122 is folded into 0xE2326 with 16 other bodies. Unnamed.
 * Passive03_0123 is folded into 0xE22FA with 13 other bodies. Unnamed.
 * Passive03_0124 is folded into 0x8078E with 13 other bodies. Unnamed.
 * Passive03_0125 is folded into 0x71360 with 1 other bodies. Unnamed.
 * Passive03_0126 is folded into 0xD2718 with 19 other bodies. Unnamed.
 * Passive03_0130 is folded into 0xD435B with 1 other bodies. Unnamed.
 * Passive03_0134 is folded into 0xD4405 with 4 other bodies. Unnamed.
 * Passive03_0135 is folded into 0xDAC4C with 25 other bodies. Unnamed.
 */

#include "sf33rd/Source/Game/PASS03.h"
#include "common.h"
#include "sf33rd/Source/Game/Com_Sub.h"
#include "sf33rd/Source/Game/workuser.h"

void (*const Passive03_Tbl[136])();

void Passive03(PLW* wk) {
    Passive03_Tbl[(s16)Pattern_Index[wk->wu.id]](wk);
}

void Passive03_0000(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xD, M_Lv[wk->wu.id]);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0001(PLW* wk) {
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

void Passive03_0002(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 3, -1);
        break;

    case 1:
        Pierce_On(wk);
        break;

    case 2:
        Command_Attack(wk, 8, 0, 10, -1);
        break;

    case 3:
        EM_Term(wk, 0x7FFF, -1, 1, 1, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0003(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        VS_Jump_Guard(wk);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0004(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x70, 6, 0x53);
        break;

    case 1:
        Command_Attack(wk, 8, 1, 0xB, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0005(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Forced_Guard(wk, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0006(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x77, 2);
        break;

    case 1:
        EM_Term(wk, 0x7FFF, -1, 1, 1, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0007(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xB7, 2);
        break;

    case 1:
        Command_Attack(wk, 8, 0x20, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0008(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;

    case 1:
        Command_Attack(wk, 0xC, 0, 0xB, -1);
        break;

    case 2:
        Command_Attack(wk, 8, 0x20, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0009(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, -0x7FD0, 6, 1, -1);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1E, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0010(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F80, 0, 0, 2, 0);
        break;

    case 1:
        Short_Range_Attack(wk, 8, 0x40, 6, 0x1D);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0011(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, -0x7FA0, -1, 8, 0x8400, 2, -0x7FA0, -1, 0x8400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0012(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F90, 0, 0, 2, 0);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0013(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0xFFFF, 0xFFFF, 0x30, 0);
        break;

    case 1:
        Wait_Get_Up(wk, 0, -1);
        break;

    case 2:
        SA_Term(wk, 0xFFFF, 0x2F, 0xFFFF, 0);
        break;

    case 3:
        Normal_Attack(wk, 0xB, 0x10);
        break;

    case 4:
        Normal_Attack(wk, 8, 0x20);
        break;

    case 5:
        Normal_Attack(wk, 8, 0x40);
        break;

    case 6:
        Com_Random_Select(wk, 6, 0x37, 0x37, 0x27, 0x27, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0014(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7FB0, -0x7FB0, 0, 1, -1);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0015(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0016(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x2F, 2);
        break;

    case 1:
        Wait_Get_Up(wk, 3, -1);
        break;

    case 2:
        Normal_Attack(wk, 0xB, 0x10);
        break;

    case 3:
        Normal_Attack(wk, 8, 0x20);
        break;

    case 4:
        Normal_Attack(wk, 0xC, 0x40);
        break;

    case 5:
        Command_Attack(wk, 8, 0x20, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0017(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x70, 6, 0x6C);
        break;

    case 1:
        Pierce_On(wk);
        break;

    case 2:
        Keep_Away(wk, 0x81, 0);
        break;

    case 3:
        Wait_Get_Up(wk, 0, -1);
        break;

    case 4:
        Normal_Attack(wk, 0xB, 0x100);
        break;

    case 5:
        Normal_Attack(wk, 8, 0x20);
        break;

    case 6:
        Normal_Attack(wk, 0xC, 0x40);
        break;

    case 7:
        Command_Attack(wk, 8, 0x20, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0018(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x39, 2);
        break;

    case 1:
        Wait_Get_Up(wk, 3, -1);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x102);
        break;

    case 3:
        Normal_Attack(wk, 0xB, 0x202);
        break;

    case 4:
        Normal_Attack(wk, 8, 0x402);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0019(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0020(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 3, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0021(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1E, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0022(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;

    case 1:
        Jump_Attack_Term(wk, -0x7FA0, -0x7FD0, 0xB, 0x100, 0, -0x7FA0, -1, 0x40);
        break;

    case 2:
        Normal_Attack(wk, 0xB, 0x10);
        break;

    case 3:
        Normal_Attack(wk, 8, 0x10);
        break;

    case 4:
        Command_Attack(wk, 8, 0x20, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0023(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;

    case 1:
        Jump_Attack_Term(wk, -0x7FA0, -1, 0xB, 0x8100, 0, -0x7FA0, -1, 0x40);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x10);
        break;

    case 3:
        Command_Attack(wk, 8, 0x20, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0024(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x70, 6, 0x6C);
        break;

    case 1:
        Pierce_On(wk);
        break;

    case 2:
        Keep_Away(wk, 0x81, 0);
        break;

    case 3:
        Wait_Get_Up(wk, 0, -1);
        break;

    case 4:
        Normal_Attack(wk, 8, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0025(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x70, 6, 0x68);
        break;

    case 1:
        Pierce_On(wk);
        break;

    case 2:
        Keep_Away(wk, 0x81, 0);
        break;

    case 3:
        Wait_Get_Up(wk, 3, -1);
        break;

    case 4:
        Command_Attack(wk, 8, 0x1E, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0026(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, -0x7FF0, 6, 1, -1);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0027(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0028(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA0, -1, 8, 0x8400, 2, -0x7FA0, -1, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0029(PLW* wk) {
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

void Passive03_0030(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, -0x7FD0, 6, 1, -1);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0031(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 1, 0x20, 1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0032(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x2E, 0x2F, 0xFFFF, 0);
        break;

    case 1:
        Normal_Attack(wk, 0xB, 0x22);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x12);
        break;

    case 3:
        Command_Attack(wk, 8, 0x1F, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0033(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x110);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0034(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xC, 0x20);
        break;

    case 1:
        Command_Attack(wk, 8, 0x20, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0035(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x102);
        break;

    case 1:
        Normal_Attack(wk, 0xB, 0x202);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x402);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0036(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x102);
        break;

    case 1:
        Normal_Attack(wk, 0xB, 0x202);
        break;

    case 2:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0037(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, -0x7FF8, 6, 1, -1);
        break;

    case 1:
        Lever_Attack(wk, 8, 0, 0x110);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0038(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, -0x7FF0, 6, 1, -1);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x110);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0039(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ETC_Term(wk, 0, 2, 0x42);
        break;

    case 1:
        Branch_Unit_Area(wk, 6, 0x59, 0x5A, 0x5A, 0x5B);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0040(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7FA0, -0x7FF8, 6, 1, -1);
        break;

    case 1:
        Normal_Attack(wk, 9, 0x100);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x100);
        break;

    case 3:
        Normal_Attack(wk, 8, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0041(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, -0x7FB0, 6, 1, -1);
        break;

    case 1:
        Lever_Attack(wk, 8, 0, 0x200);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x42);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0042(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA0, -1, 8, 0x8400, 2, -0x7FA0, -1, -0x7C00);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0043(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, -0x7FD8, 6, 1, -1);
        break;

    case 1:
        Command_Attack(wk, 8, 0x20, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0044(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x39, 2);
        break;

    case 1:
        EM_Term(wk, -1, -0x7FD0, 6, 1, -1);
        break;

    case 2:
        Command_Attack(wk, 8, 0x1E, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0045(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, -0x7FE0, 6, 1, -1);
        break;

    case 1:
        Branch_Unit_Area(wk, 6, 0x59, 0x5A, 0x5B, 0x5B);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0046(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Status(wk, 2, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0047(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xB, 0x102);
        break;

    case 1:
        Branch_Unit_Area(wk, 6, 0x59, 0x5A, 0x5B, 0x5B);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0048(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x102);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x402);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0049(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 8, 0x10);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0050(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x12);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x22);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0051(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x220);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0052(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x202);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0053(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA0, -1, 8, 0x8400, 2, -0x7FA0, -1, -0x7C00);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0054(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, -0x7FA0, -1, 8, 0x8400, 2, -0x7FA0, -1, 0x8400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0055(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x20, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0056(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA0, -0x7FD0, 8, 0x40, 0, -0x7FA0, -1, 0x40);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0057(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA0, -0x7FD0, 8, 0x20, 0, -0x7FA0, -1, 0x40);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0058(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Status(wk, 2, 1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0059(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xB, 0x20);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x40);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0060(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Forced_Guard(wk, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0061(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0xFFFF, 0x2F, 0x30, 0);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0062(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x2F, 2);
        break;

    case 1:
        Lever_Attack(wk, 8, 0, 0x110);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0063(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xC, 0x20);
        break;

    case 1:
        Command_Attack(wk, 8, 0x20, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0064(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0065(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x2F, 2);
        break;

    case 1:
        Normal_Attack(wk, 0xC, 0x100);
        break;

    case 2:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0066(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ETC_Term(wk, 0, 6, 0x40);
        break;

    case 1:
        Branch_Unit_Area(wk, 6, 0x59, 0x5A, 0x5A, 0x5B);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0067(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x20, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0068(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA0, -0x7FD0, 8, 0x40, 0, -0x7FA0, -1, 0x40);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0069(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 0xC, 0, 0xB, -1);
        break;

    case 1:
        Branch_Unit_Area(wk, 6, 0x59, 0x5A, 0x5B, 0x5B);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0070(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;

    case 1:
        Command_Attack(wk, 8, 0, 0xB, -1);
        break;

    case 2:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0071(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x2F, 2);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1C, 10, -1);
        break;

    case 2:
        Command_Attack(wk, 8, 0x1E, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0072(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;

    case 1:
        Command_Attack(wk, 0xC, 0, 0xB, -1);
        break;

    case 2:
        Command_Attack(wk, 8, 0x20, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0073(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xB7, 2);
        break;

    case 1:
        Hi_Jump_Attack_Term(wk, -0x7FA0, -1, 0xB, 0x8400, 0, -0x7FA0, -1, 0x40);
        break;

    case 2:
        Command_Attack(wk, 8, 0x20, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0074(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x2E, 0x2F, 0x30, 0);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x10);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x20);
        break;

    case 3:
        Normal_Attack(wk, 0xC, 0x40);
        break;

    case 4:
        Com_Random_Select(wk, 6, 0x37, 0x37, 0x27, 0x27, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0075(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0xFFFF, 0xFFFF, 0x30, 0);
        break;

    case 1:
        Approach_Walk(wk, 0x2F, 2);
        break;

    case 2:
        SA_Term(wk, 0xFFFF, 0x2F, 0xFFFF, 0);
        break;

    case 3:
        Normal_Attack(wk, 8, 0x10);
        break;

    case 4:
        Normal_Attack(wk, 8, 0x20);
        break;

    case 5:
        Normal_Attack(wk, 0xC, 0x40);
        break;

    case 6:
        Com_Random_Select(wk, 6, 0x37, 0x37, 0x27, 0x27, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0076(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0xFFFF, 0xFFFF, 0x30, 0);
        break;

    case 1:
        Approach_Walk(wk, 0xB7, 2);
        break;

    case 2:
        Hi_Jump_Attack_Term(wk, -0x7FA0, -1, 8, 0x8400, 0, -0x7FA0, -1, 0x40);
        break;

    case 3:
        Normal_Attack(wk, 0xB, 0x10);
        break;

    case 4:
        Normal_Attack(wk, 8, 0x20);
        break;

    case 5:
        Normal_Attack(wk, 0xC, 0x40);
        break;

    case 6:
        Com_Random_Select(wk, 6, 0x37, 0x37, 0x27, 0x27, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0077(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA0, -0x7FD0, 0xB, 0x20, 0, -0x7FA0, -1, 0x40);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0078(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FB0, -1, 8, 0x8400, 0, -0x7FA0, -1, 0x40);
        break;

    case 1:
        Normal_Attack(wk, 0xB, 0x10);
        break;

    case 2:
        Normal_Attack(wk, 0xC, 0x40);
        break;

    case 3:
        Command_Attack(wk, 8, 0x20, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0079(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA0, -0x7FD0, 0xB, 0x20, 0, -1, -1, -1);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x40);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0080(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, -0x7FA0, -0x7FD0, 0xB, 0x40, 0, -0x7FA0, -1, 0x40);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0081(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, -0x7FA0, -1, 0xB, 0x8200, 0, -0x7FA0, -1, 0x40);
        break;

    case 1:
        Normal_Attack(wk, 0xB, 0x10);
        break;

    case 2:
        Lever_Attack(wk, 8, 0, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0082(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, -0x7FA0, -0x7FC0, 0xB, 0x40, 0, -1, -1, 0xFFFF);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0083(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, -0x7FA0, -0x7FC0, 0xB, 0x40, 0, -0x7FA0, -1, 0x40);
        break;

    case 1:
        Normal_Attack(wk, 0xB, 0x10);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x20);
        break;

    case 3:
        Normal_Attack(wk, 0xC, 0x40);
        break;

    case 4:
        Command_Attack(wk, 8, 0x20, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0084(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, -0x7FA0, -1, 8, 0x8400, 0, -0x7FA0, -1, 0x40);
        break;

    case 1:
        Normal_Attack(wk, 0xB, 0x10);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x20);
        break;

    case 3:
        Normal_Attack(wk, 0xC, 0x40);
        break;

    case 4:
        Com_Random_Select(wk, 6, 0x37, 0x37, 0x27, 0x27, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0085(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 10);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1E, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0086(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x2F, 2);
        break;

    case 1:
        EM_Term(wk, -1, -0x7FF8, 6, 1, -1);
        break;

    case 2:
        SA_Term(wk, 0x2E, 0x2F, 0xFFFF, 0);
        break;

    case 3:
        Normal_Attack(wk, 0xB, 0x12);
        break;

    case 4:
        Normal_Attack(wk, 8, 0x42);
        break;

    case 5:
        Com_Random_Select(wk, 6, 0x37, 0x37, 0x27, 0x27, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0087(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x2F, 2);
        break;

    case 1:
        EM_Term(wk, -1, -0x7FF8, 6, 1, -1);
        break;

    case 2:
        SA_Term(wk, 0xFFFF, 0x2F, 0xFFFF, 0);
        break;

    case 3:
        Normal_Attack(wk, 0xB, 0x10);
        break;

    case 4:
        Normal_Attack(wk, 8, 0x20);
        break;

    case 5:
        Normal_Attack(wk, 0xC, 0x40);
        break;

    case 6:
        Com_Random_Select(wk, 6, 0x37, 0x37, 0x27, 0x27, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0088(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, -0x7FD8, 6, 1, -1);
        break;

    case 1:
        SA_Term(wk, 0xFFFF, 0xFFFF, 0x30, 0);
        break;

    case 2:
        Normal_Attack(wk, 0xB, 0x10);
        break;

    case 3:
        Normal_Attack(wk, 8, 0x20);
        break;

    case 4:
        Normal_Attack(wk, 0xC, 0x40);
        break;

    case 5:
        Com_Random_Select(wk, 6, 0x37, 0x37, 0x27, 0x27, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0089(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1F, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0090(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1F, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0091(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1F, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0092(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, -0x7FE0, 6, 1, -1);
        break;

    case 1:
        Branch_Unit_Area(wk, 6, 0x59, 0x5A, 0x5B, 0x5B);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0093(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x102);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x102);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0094(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Branch_Unit_Area(wk, 6, 0x59, 0x5A, 0x5B, 1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0095(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 1, 0x30, 0);
        break;

    case 1:
        Branch_Unit_Area(wk, 6, 0x59, 0x5A, 0x5B, 0x5B);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0096(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, -0x7FF0, 6, 1, -1);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x402);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0097(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x2F, 2);
        break;

    case 1:
        EM_Term(wk, -1, -0x7FF8, 6, 1, -1);
        break;

    case 2:
        Lever_Attack(wk, 8, 0, 0x110);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0098(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x2F, 2);
        break;

    case 1:
        EM_Term(wk, -1, -0x7FF0, 6, 1, -1);
        break;

    case 2:
        Normal_Attack(wk, 0xB, 0x10);
        break;

    case 3:
        Normal_Attack(wk, 8, 0x20);
        break;

    case 4:
        Normal_Attack(wk, 0xC, 0x40);
        break;

    case 5:
        Command_Attack(wk, 8, 0x20, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0099(PLW* wk) {
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

void Passive03_0100(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 1, 0x30, 0);
        break;

    case 1:
        Wait_Get_Up(wk, 0, -1);
        break;

    case 2:
        Command_Attack(wk, 8, 0x1D, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0101(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F80, -1, 6, 1, -1);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0102(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7FB0, -0x7FB0, 6, 1, -1);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x200);
        break;

    case 2:
        Command_Attack(wk, 8, 0x20, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0103(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x70, 6, 0x68);
        break;

    case 1:
        Walk(wk, 1, 0x20, 0);
        break;

    case 2:
        Wait_Get_Up(wk, 0, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0104(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump(wk, 3, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0105(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x70, 6, 0x68);
        break;

    case 1:
        Pierce_On(wk);
        break;

    case 2:
        Command_Attack(wk, 8, 1, 10, -1);
        break;

    case 3:
        Wait_Get_Up(wk, 3, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0106(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x70, 6, 0x68);
        break;

    case 1:
        Walk(wk, 1, 0x38, 0);
        break;

    case 2:
        Wait_Get_Up(wk, 0, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0107(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x2E, 0x2F, 0x30, 0);
        break;

    case 1:
        Com_Random_Select(wk, 6, 0x37, 0x37, 0x27, 0x27, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0108(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xB7, 2);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0109(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x2E, 0xFFFF, 0x30, 0);
        break;

    case 1:
        Branch_Unit_Area(wk, 6, 0x59, 0x5A, 0x5B, 0x5B);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0110(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xC, 0x20);
        break;

    case 1:
        SA_Term(wk, 0x2E, 0x2F, 0xFFFF, 0);
        break;

    case 2:
        Com_Random_Select(wk, 6, 0x37, 0x37, 0x27, 0x27, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0111(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, -0x7FB0, 6, 1, -1);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0112(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, -0x7FB0, 6, 1, -1);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x200);
        break;

    case 2:
        Command_Attack(wk, 8, 0x20, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0113(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x20, 6, 1, -1);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1F, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0114(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x20, 8, 0x400, 1, -1, 0x20, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0115(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x220);
        break;

    case 1:
        Normal_Attack(wk, 0xB, 0x102);
        break;

    case 2:
        Command_Attack(wk, 8, 0x1F, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0116(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x20, 8, 0x400, 0, -1, 0x20, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0117(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x20, 8, 0x200, 1, -1, 0x20, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0118(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x20, 8, 0x200, 0, -1, 0x20, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0119(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0120(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xD, 0x100);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0121(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Branch_Unit_Area(wk, 6, 0x7A, 0x7B, 0x7C, 0x7D);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0122(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1D, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0123(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1D, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0124(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1D, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0125(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1D, 0xB, 0x70);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0126(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Provoke(wk, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0127(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;

    case 1:
        Normal_Attack(wk, 0xD, 0x402);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0128(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x20, 0xB, 0x70);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0129(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1F, 0xB, 0x700);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0130(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Provoke(wk, -1);
        break;

    case 1:
        Wait_Get_Up(wk, 0, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0131(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1D, 0xB, 0x70);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0132(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;

    case 1:
        Command_Attack(wk, 8, 0x20, 0xB, 0x70);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0133(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1F, 0xB, 0x700);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0134(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump(wk, 1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive03_0135(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump(wk, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void (*const Passive03_Tbl[136])(PLW*) = {
    Passive03_0000, Passive03_0001, Passive03_0002, Passive03_0003, Passive03_0004, Passive03_0005, Passive03_0006,
    Passive03_0007, Passive03_0008, Passive03_0009, Passive03_0010, Passive03_0011, Passive03_0012, Passive03_0013,
    Passive03_0014, Passive03_0015, Passive03_0016, Passive03_0017, Passive03_0018, Passive03_0019, Passive03_0020,
    Passive03_0021, Passive03_0022, Passive03_0023, Passive03_0024, Passive03_0025, Passive03_0026, Passive03_0027,
    Passive03_0028, Passive03_0029, Passive03_0030, Passive03_0031, Passive03_0032, Passive03_0033, Passive03_0034,
    Passive03_0035, Passive03_0036, Passive03_0037, Passive03_0038, Passive03_0039, Passive03_0040, Passive03_0041,
    Passive03_0042, Passive03_0043, Passive03_0044, Passive03_0045, Passive03_0046, Passive03_0047, Passive03_0048,
    Passive03_0049, Passive03_0050, Passive03_0051, Passive03_0052, Passive03_0053, Passive03_0054, Passive03_0055,
    Passive03_0056, Passive03_0057, Passive03_0058, Passive03_0059, Passive03_0060, Passive03_0061, Passive03_0062,
    Passive03_0063, Passive03_0064, Passive03_0065, Passive03_0066, Passive03_0067, Passive03_0068, Passive03_0069,
    Passive03_0070, Passive03_0071, Passive03_0072, Passive03_0073, Passive03_0074, Passive03_0075, Passive03_0076,
    Passive03_0077, Passive03_0078, Passive03_0079, Passive03_0080, Passive03_0081, Passive03_0082, Passive03_0083,
    Passive03_0084, Passive03_0085, Passive03_0086, Passive03_0087, Passive03_0088, Passive03_0089, Passive03_0090,
    Passive03_0091, Passive03_0092, Passive03_0093, Passive03_0094, Passive03_0095, Passive03_0096, Passive03_0097,
    Passive03_0098, Passive03_0099, Passive03_0100, Passive03_0101, Passive03_0102, Passive03_0103, Passive03_0104,
    Passive03_0105, Passive03_0106, Passive03_0107, Passive03_0108, Passive03_0109, Passive03_0110, Passive03_0111,
    Passive03_0112, Passive03_0113, Passive03_0114, Passive03_0115, Passive03_0116, Passive03_0117, Passive03_0118,
    Passive03_0119, Passive03_0120, Passive03_0121, Passive03_0122, Passive03_0123, Passive03_0124, Passive03_0125,
    Passive03_0126, Passive03_0127, Passive03_0128, Passive03_0129, Passive03_0130, Passive03_0131, Passive03_0132,
    Passive03_0133, Passive03_0134, Passive03_0135
};
