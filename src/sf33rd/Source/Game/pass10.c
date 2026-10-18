/* pass10.c, retail sf33rd.xbe.
 * PlayStation 2 C, not hand-adjusted for Xbox. Each named body was located
 * from the PS2 retail map: call graph, source order, and agreement of
 * constants, field offsets, callees, and size. See docs/decompiling.md.
 * The #include lines name headers in the PS2 tree (ps2.path).
 * Passive10_0007 0xD2BB7 size 0x43.
 * Passive10_0013 0xD2D07 size 0x88.
 * Passive10_0016 0xD2D8F size 0x70.
 * Passive10_0017 0xD2DFF size 0xA6.
 * Passive10_0018 0xD2EA5 size 0x62.
 * Passive10_0022 0xD2F07 size 0x7D.
 * Passive10_0023 0xD2F84 size 0x71.
 * Passive10_0024 0xD2FF5 size 0x6C.
 * Passive10_0025 0xD3061 size 0x70.
 * Passive10_0032 0xD3116 size 0x5F.
 * Passive10_0034 0xD3175 size 0x40.
 * Passive10_0044 0xD33DF size 0x5A.
 * Passive10_0061 0xD34DC size 0x43.
 * Passive10_0065 0xD355C size 0x52.
 * Passive10_0071 0xD3638 size 0x4B.
 * Passive10_0073 0xD36CA size 0x66.
 * Passive10_0075 0xD3798 size 0x89.
 * Passive10_0076 0xD3821 size 0xA1.
 * Passive10_0078 0xD3913 size 0x6F.
 * Passive10_0083 0xD3AD8 size 0x75.
 * Passive10_0086 0xD3C02 size 0x8D.
 * Passive10_0087 0xD3C8F size 0x96.
 * Passive10_0098 0xD3D53 size 0x7B.
 * Passive10_0100 0xD3E24 size 0x52.
 * Passive10_0102 0xD3E76 size 0x5D.
 * Passive10_0103 0xD3ED3 size 0x4F.
 * Passive10_0104 0xD3F22 size 0x28.
 * Passive10_0112 0xD4038 size 0x5D.
 * Passive10_0115 0xD4095 size 0x4D.
 * Passive10_0120 0xD4119 size 0x3D.
 * Passive10_0121 0xD4156 size 0x58.
 * Passive10_0122 0xD41AE size 0x4A.
 * Passive10_0125 0xD41F8 size 0x4E.
 * Passive10_0126 0xD4246 size 0x40.
 * Passive10_0127 0xD4286 size 0x2F.
 * Passive10_0129 0xD42B5 size 0x51.
 * Passive10_0131 0xD4306 size 0x55.
 * Passive10_0000 is folded into 0xD0F75 with 19 other bodies. Unnamed.
 * Passive10_0001 is folded into 0xAB943 with 44 other bodies. Unnamed.
 * Passive10_0002 is folded into 0xD0FA4 with 3 other bodies. Unnamed.
 * Passive10_0003 is folded into 0xDC466 with 15 other bodies. Unnamed.
 * Passive10_0004 is folded into 0xD2B75 with 1 other bodies. Unnamed.
 * Passive10_0005 is folded into 0x7EE7B with 30 other bodies. Unnamed.
 * Passive10_0006 is folded into 0xE1BAF with 7 other bodies. Unnamed.
 * Passive10_0008 is folded into 0xD3683 with 1 other bodies. Unnamed.
 * Passive10_0009 is folded into 0xD2BFA with 1 other bodies. Unnamed.
 * Passive10_0010 is folded into 0xD2C43 with 1 other bodies. Unnamed.
 * Passive10_0011 is folded into 0xD2C8A with 3 other bodies. Unnamed.
 * Passive10_0012 is folded into 0xD2CC4 with 1 other bodies. Unnamed.
 * Passive10_0014 is folded into 0x70107 with 1 other bodies. Unnamed.
 * Passive10_0015 is folded into 0x6D0D1 with 24 other bodies. Unnamed.
 * Passive10_0019 is folded into 0x6D0D1 with 24 other bodies. Unnamed.
 * Passive10_0020 is folded into 0x6D236 with 23 other bodies. Unnamed.
 * Passive10_0021 is folded into 0xDDE9A with 5 other bodies. Unnamed.
 * Passive10_0026 is folded into 0xD30D1 with 1 other bodies. Unnamed.
 * Passive10_0027 is folded into 0xE2EEB with 25 other bodies. Unnamed.
 * Passive10_0028 is folded into 0x70491 with 1 other bodies. Unnamed.
 * Passive10_0029 is folded into 0xDFCF2 with 13 other bodies. Unnamed.
 * Passive10_0030 is folded into 0x704CE with 2 other bodies. Unnamed.
 * Passive10_0031 is folded into 0x6E9E1 with 12 other bodies. Unnamed.
 * Passive10_0033 is folded into 0xDDB8D with 22 other bodies. Unnamed.
 * Passive10_0035 is folded into 0x705B5 with 1 other bodies. Unnamed.
 * Passive10_0036 is folded into 0xD31B5 with 1 other bodies. Unnamed.
 * Passive10_0037 is folded into 0xD3204 with 1 other bodies. Unnamed.
 * Passive10_0038 is folded into 0xD324E with 1 other bodies. Unnamed.
 * Passive10_0039 is folded into 0xD3296 with 1 other bodies. Unnamed.
 * Passive10_0040 is folded into 0xD32DA with 1 other bodies. Unnamed.
 * Passive10_0041 is folded into 0xD333B with 1 other bodies. Unnamed.
 * Passive10_0042 is folded into 0x705F9 with 3 other bodies. Unnamed.
 * Passive10_0043 is folded into 0xD3396 with 1 other bodies. Unnamed.
 * Passive10_0045 is folded into 0xD3439 with 3 other bodies. Unnamed.
 * Passive10_0046 is folded into 0x706D9 with 12 other bodies. Unnamed.
 * Passive10_0047 is folded into 0x70701 with 1 other bodies. Unnamed.
 * Passive10_0048 is folded into 0xDE286 with 11 other bodies. Unnamed.
 * Passive10_0049 is folded into 0x70746 with 5 other bodies. Unnamed.
 * Passive10_0050 is folded into 0xD3482 with 2 other bodies. Unnamed.
 * Passive10_0051 is folded into 0x7076E with 5 other bodies. Unnamed.
 * Passive10_0052 is folded into 0xA9FF7 with 32 other bodies. Unnamed.
 * Passive10_0053 is folded into 0x705F9 with 3 other bodies. Unnamed.
 * Passive10_0054 is folded into 0xD2C8A with 3 other bodies. Unnamed.
 * Passive10_0055 is folded into 0xE2EEB with 25 other bodies. Unnamed.
 * Passive10_0056 is folded into 0x70799 with 3 other bodies. Unnamed.
 * Passive10_0057 is folded into 0x707D3 with 1 other bodies. Unnamed.
 * Passive10_0058 is folded into 0xD34B4 with 13 other bodies. Unnamed.
 * Passive10_0059 is folded into 0x7080D with 1 other bodies. Unnamed.
 * Passive10_0060 is folded into 0x7EE7B with 30 other bodies. Unnamed.
 * Passive10_0062 is folded into 0xD351F with 2 other bodies. Unnamed.
 * Passive10_0063 is folded into 0xAA267 with 1 other bodies. Unnamed.
 * Passive10_0064 is folded into 0xE33B0 with 14 other bodies. Unnamed.
 * Passive10_0066 is folded into 0xD35AE with 1 other bodies. Unnamed.
 * Passive10_0067 is folded into 0xE2F43 with 17 other bodies. Unnamed.
 * Passive10_0068 is folded into 0x70799 with 3 other bodies. Unnamed.
 * Passive10_0069 is folded into 0xD35F2 with 1 other bodies. Unnamed.
 * Passive10_0070 is folded into 0x7095A with 1 other bodies. Unnamed.
 * Passive10_0072 is folded into 0xD3683 with 1 other bodies. Unnamed.
 * Passive10_0074 is folded into 0xD3730 with 1 other bodies. Unnamed.
 * Passive10_0077 is folded into 0xD38C2 with 1 other bodies. Unnamed.
 * Passive10_0079 is folded into 0xD3982 with 1 other bodies. Unnamed.
 * Passive10_0080 is folded into 0xD39D0 with 1 other bodies. Unnamed.
 * Passive10_0081 is folded into 0xD3A21 with 1 other bodies. Unnamed.
 * Passive10_0082 is folded into 0xD3A84 with 1 other bodies. Unnamed.
 * Passive10_0084 is folded into 0xD3B4D with 1 other bodies. Unnamed.
 * Passive10_0085 is folded into 0xD3BC5 with 1 other bodies. Unnamed.
 * Passive10_0088 is folded into 0x70D80 with 1 other bodies. Unnamed.
 * Passive10_0089 is folded into 0x9FB5D with 12 other bodies. Unnamed.
 * Passive10_0090 is folded into 0x9FB89 with 10 other bodies. Unnamed.
 * Passive10_0091 is folded into 0x9FBB5 with 13 other bodies. Unnamed.
 * Passive10_0092 is folded into 0xD3439 with 3 other bodies. Unnamed.
 * Passive10_0093 is folded into 0xDDAB7 with 9 other bodies. Unnamed.
 * Passive10_0094 is folded into 0xD3D25 with 3 other bodies. Unnamed.
 * Passive10_0095 is folded into 0x70E07 with 1 other bodies. Unnamed.
 * Passive10_0096 is folded into 0xD54CF with 3 other bodies. Unnamed.
 * Passive10_0097 is folded into 0x82147 with 2 other bodies. Unnamed.
 * Passive10_0099 is folded into 0xD3DCE with 3 other bodies. Unnamed.
 * Passive10_0101 is folded into 0x70F73 with 1 other bodies. Unnamed.
 * Passive10_0105 is folded into 0xD3F4A with 1 other bodies. Unnamed.
 * Passive10_0106 is folded into 0x7108B with 1 other bodies. Unnamed.
 * Passive10_0107 is folded into 0xD3FA8 with 1 other bodies. Unnamed.
 * Passive10_0108 is folded into 0xAA09A with 13 other bodies. Unnamed.
 * Passive10_0109 is folded into 0xD3FEF with 1 other bodies. Unnamed.
 * Passive10_0110 is folded into 0x71104 with 1 other bodies. Unnamed.
 * Passive10_0111 is folded into 0x7115F with 1 other bodies. Unnamed.
 * Passive10_0113 is folded into 0x71204 with 1 other bodies. Unnamed.
 * Passive10_0114 is folded into 0xDD6B3 with 6 other bodies. Unnamed.
 * Passive10_0116 is folded into 0x71299 with 1 other bodies. Unnamed.
 * Passive10_0117 is folded into 0xD40E2 with 1 other bodies. Unnamed.
 * Passive10_0118 is folded into 0x712D0 with 1 other bodies. Unnamed.
 * Passive10_0119 is folded into 0x6D0A6 with 29 other bodies. Unnamed.
 * Passive10_0123 is folded into 0xD2718 with 19 other bodies. Unnamed.
 * Passive10_0124 is folded into 0x71307 with 3 other bodies. Unnamed.
 * Passive10_0128 is folded into 0xD4394 with 2 other bodies. Unnamed.
 * Passive10_0130 is folded into 0xD3821 with 1 other bodies. Unnamed.
 * Passive10_0132 is folded into 0xD4394 with 2 other bodies. Unnamed.
 * Passive10_0133 is folded into 0xD435B with 1 other bodies. Unnamed.
 * Passive10_0134 is folded into 0xD4394 with 2 other bodies. Unnamed.
 * Passive10_0135 is folded into 0xD4405 with 4 other bodies. Unnamed.
 * Passive10_0136 is folded into 0xD442A with 1 other bodies. Unnamed.
 * Passive10_0137 is folded into 0xDAC4C with 25 other bodies. Unnamed.
 * The other functions in this file are not located in sf33rd.xbe yet.
 */

#include "sf33rd/Source/Game/pass10.h"
#include "common.h"
#include "sf33rd/Source/Game/Com_Sub.h"
#include "sf33rd/Source/Game/workuser.h"

void (*const Passive10_Tbl[138])();

void Passive10(PLW* wk) {
    Passive10_Tbl[(s16)Pattern_Index[wk->wu.id]](wk);
}

void Passive10_0000(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xD, M_Lv[wk->wu.id]);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0001(PLW* wk) {
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

void Passive10_0002(PLW* wk) {
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
        EM_Term(wk, 0x7fff, -1, 1, 1, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0003(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        VS_Jump_Guard(wk);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0004(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x70, 6, 0x53);
        break;

    case 1:
        Command_Attack(wk, 8, 1, 0xb, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0005(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Forced_Guard(wk, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0006(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x7f, 2);
        break;

    case 1:
        EM_Term(wk, 0x7fff, -1, 1, 1, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0007(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xbf, 2);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1e, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0008(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;

    case 1:
        Command_Attack(wk, 0xc, 0, 0xb, -1);
        break;

    case 2:
        Command_Attack(wk, 8, 0x1e, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0009(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, -0x7FD0, 6, 1, -1);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1e, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0010(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F80, 0, 0, 2, 0);
        break;

    case 1:
        Short_Range_Attack(wk, 8, 0x40, 6, 0x1d);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0011(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, -0x7FA0, -1, 8, 0x8400, 2, -0x7FA0, -1, 0x8400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0012(PLW* wk) {
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

void Passive10_0013(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0xffff, 0xffff, 0x30, 0);
        break;

    case 1:
        Wait_Get_Up(wk, 0, -1);
        break;

    case 2:
        SA_Term(wk, 0x2e, 0x2f, 0xffff, 0);
        break;

    case 3:
        Normal_Attack(wk, 0xb, 0x10);
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

void Passive10_0014(PLW* wk) {
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

void Passive10_0015(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0016(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;

    case 1:
        Wait_Get_Up(wk, 3, -1);
        break;

    case 2:
        Normal_Attack(wk, 0xb, 0x10);
        break;

    case 3:
        Normal_Attack(wk, 8, 0x20);
        break;

    case 4:
        Normal_Attack(wk, 0xc, 0x40);
        break;

    case 5:
        Command_Attack(wk, 8, 0x1e, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0017(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x70, 6, 0x6c);
        break;

    case 1:
        Pierce_On(wk);
        break;

    case 2:
        Keep_Away(wk, 0x89, 0);
        break;

    case 3:
        Wait_Get_Up(wk, 0, -1);
        break;

    case 4:
        Normal_Attack(wk, 0xb, 0x100);
        break;

    case 5:
        Normal_Attack(wk, 8, 0x20);
        break;

    case 6:
        Normal_Attack(wk, 0xc, 0x40);
        break;

    case 7:
        Command_Attack(wk, 8, 0x1e, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0018(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x41, 2);
        break;

    case 1:
        Wait_Get_Up(wk, 3, -1);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x102);
        break;

    case 3:
        Normal_Attack(wk, 0xb, 0x202);
        break;

    case 4:
        Normal_Attack(wk, 8, 0x402);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0019(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0020(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 3, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0021(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1e, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0022(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;

    case 1:
        Jump_Attack_Term(wk, -0x7FA0, -0x7FD0, 0xb, 0x100, 0, -0x7FA0, -1, 0x40);
        break;

    case 2:
        Normal_Attack(wk, 0xb, 0x10);
        break;

    case 3:
        Normal_Attack(wk, 8, 0x10);
        break;

    case 4:
        Command_Attack(wk, 8, 0x1e, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0023(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;

    case 1:
        Jump_Attack_Term(wk, -0x7FA0, -1, 0xb, 0x8100, 0, -0x7FA0, -1, 0x40);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x10);
        break;

    case 3:
        Command_Attack(wk, 8, 0x1e, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0024(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x70, 6, 0x6c);
        break;

    case 1:
        Pierce_On(wk);
        break;

    case 2:
        Keep_Away(wk, 0x89, 0);
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

void Passive10_0025(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x70, 6, 0x68);
        break;

    case 1:
        Pierce_On(wk);
        break;

    case 2:
        Keep_Away(wk, 0x89, 0);
        break;

    case 3:
        Wait_Get_Up(wk, 3, -1);
        break;

    case 4:
        Command_Attack(wk, 8, 0x1e, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0026(PLW* wk) {
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

void Passive10_0027(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1e, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0028(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA0, -1, 8, 0x8400, 2, -0x7FA0, -1, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0029(PLW* wk) {
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

void Passive10_0030(PLW* wk) {
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

void Passive10_0031(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 1, 0x20, 1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0032(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x2e, 0x2f, 0xffff, 0);
        break;

    case 1:
        Normal_Attack(wk, 0xb, 0x22);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x12);
        break;

    case 3:
        J_Command_Attack(wk, 8, 0x1f, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0033(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x110);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0034(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xc, 0x20);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1e, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0035(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x102);
        break;

    case 1:
        Normal_Attack(wk, 0xb, 0x202);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x402);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0036(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x102);
        break;

    case 1:
        Normal_Attack(wk, 0xb, 0x202);
        break;

    case 2:
        Command_Attack(wk, 8, 0x1e, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0037(PLW* wk) {
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

void Passive10_0038(PLW* wk) {
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

void Passive10_0039(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ETC_Term(wk, 0, 2, 0x42);
        break;

    case 1:
        Branch_Unit_Area(wk, 6, 0x59, 0x5a, 0x5a, 0x5b);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0040(PLW* wk) {
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

void Passive10_0041(PLW* wk) {
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

void Passive10_0042(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA0, -1, 8, 0x8400, 2, -0x7FA0, -1, -0x7C00);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0043(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, -0x7FD8, 6, 1, -1);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1e, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0044(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x41, 2);
        break;

    case 1:
        EM_Term(wk, -1, -0x7FD0, 6, 1, -1);
        break;

    case 2:
        Command_Attack(wk, 8, 0x1e, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0045(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, -0x7FE0, 6, 1, -1);
        break;

    case 1:
        Branch_Unit_Area(wk, 6, 0x59, 0x5a, 0x5b, 0x5b);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0046(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Status(wk, 2, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0047(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xb, 0x102);
        break;

    case 1:
        Branch_Unit_Area(wk, 6, 0x59, 0x5a, 0x5b, 0x5b);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0048(PLW* wk) {
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

void Passive10_0049(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 8, 0x10);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0050(PLW* wk) {
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

void Passive10_0051(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x220);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0052(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x202);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0053(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA0, -1, 8, 0x8400, 2, -0x7FA0, -1, -0x7C00);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0054(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, -0x7FA0, -1, 8, 0x8400, 2, -0x7FA0, -1, 0x8400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0055(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1e, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0056(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA0, -0x7FD0, 8, 0x40, 0, -0x7FA0, -1, 0x40);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0057(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA0, -0x7FD0, 8, 0x20, 0, -0x7FA0, -1, 0x40);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0058(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Status(wk, 2, 1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0059(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xb, 0x20);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x40);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0060(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Forced_Guard(wk, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0061(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x2e, 0x2f, 0x30, 0);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0062(PLW* wk) {
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

void Passive10_0063(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xc, 0x20);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1e, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0064(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0065(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;

    case 1:
        Normal_Attack(wk, 0xc, 0x100);
        break;

    case 2:
        Command_Attack(wk, 8, 0x1e, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0066(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ETC_Term(wk, 0, 6, 0x40);
        break;

    case 1:
        Branch_Unit_Area(wk, 6, 0x59, 0x5a, 0x5a, 0x5b);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0067(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1e, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0068(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA0, -0x7FD0, 8, 0x40, 0, -0x7FA0, -1, 0x40);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0069(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 0xc, 0, 0xb, -1);
        break;

    case 1:
        Branch_Unit_Area(wk, 6, 0x59, 0x5a, 0x5b, 0x5b);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0070(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;

    case 1:
        Command_Attack(wk, 8, 0, 0xb, -1);
        break;

    case 2:
        Command_Attack(wk, 8, 0x1e, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0071(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1c, 10, -1);
        break;

    case 2:
        Command_Attack(wk, 8, 0x1e, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0072(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;

    case 1:
        Command_Attack(wk, 0xc, 0, 0xb, -1);
        break;

    case 2:
        Command_Attack(wk, 8, 0x1e, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0073(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xbf, 2);
        break;

    case 1:
        Hi_Jump_Attack_Term(wk, -0x7FA0, -1, 0xb, 0x8400, 0, -0x7FA0, -1, 0x40);
        break;

    case 2:
        Command_Attack(wk, 8, 0x1e, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0074(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x2e, 0x2f, 0x30, 0);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x10);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x20);
        break;

    case 3:
        Normal_Attack(wk, 0xc, 0x40);
        break;

    case 4:
        Com_Random_Select(wk, 6, 0x37, 0x37, 0x27, 0x27, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0075(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x2e, 0xffff, 0x30, 0);
        break;

    case 1:
        Approach_Walk(wk, 0x37, 2);
        break;

    case 2:
        SA_Term(wk, 0xffff, 0x2f, 0xffff, 0);
        break;

    case 3:
        Normal_Attack(wk, 8, 0x10);
        break;

    case 4:
        Normal_Attack(wk, 8, 0x20);
        break;

    case 5:
        Normal_Attack(wk, 0xc, 0x40);
        break;

    case 6:
        Com_Random_Select(wk, 6, 0x37, 0x37, 0x27, 0x27, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0076(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0xffff, 0x2f, 0x30, 0);
        break;

    case 1:
        Approach_Walk(wk, 0xbf, 2);
        break;

    case 2:
        Hi_Jump_Attack_Term(wk, -0x7FA0, -1, 8, 0x8400, 0, -0x7FA0, -1, 0x40);
        break;

    case 3:
        Normal_Attack(wk, 0xb, 0x10);
        break;

    case 4:
        Normal_Attack(wk, 8, 0x20);
        break;

    case 5:
        Normal_Attack(wk, 0xc, 0x40);
        break;

    case 6:
        Com_Random_Select(wk, 6, 0x37, 0x37, 0x27, 0x27, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0077(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA0, -0x7FD0, 0xb, 0x20, 0, -0x7FA0, -1, 0x40);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0078(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FB0, -1, 8, 0x8400, 0, -0x7FA0, -1, 0x40);
        break;

    case 1:
        Normal_Attack(wk, 0xb, 0x10);
        break;

    case 2:
        Normal_Attack(wk, 0xc, 0x40);
        break;

    case 3:
        Command_Attack(wk, 8, 0x1e, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0079(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA0, -0x7FD0, 0xb, 0x20, 0, -1, -1, -1);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x40);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0080(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, -0x7FA0, -0x7FD0, 0xb, 0x40, 0, -0x7FA0, -1, 0x40);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0081(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, -0x7FA0, -1, 0xb, 0x8200, 0, -0x7FA0, -1, 0x40);
        break;

    case 1:
        Normal_Attack(wk, 0xb, 0x10);
        break;

    case 2:
        Lever_Attack(wk, 8, 0, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0082(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, -0x7FA0, -0x7FC0, 0xb, 0x40, 0, -1, -1, 0xFFFF);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0083(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, -0x7FA0, -0x7FC0, 0xb, 0x40, 0, -0x7FA0, -1, 0x40);
        break;

    case 1:
        Normal_Attack(wk, 0xb, 0x10);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x20);
        break;

    case 3:
        Normal_Attack(wk, 0xc, 0x40);
        break;

    case 4:
        Command_Attack(wk, 8, 0x1e, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0084(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, -0x7FA0, -1, 8, 0x8400, 0, -0x7FA0, -1, 0x40);
        break;

    case 1:
        Normal_Attack(wk, 0xb, 0x10);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x20);
        break;

    case 3:
        Normal_Attack(wk, 0xc, 0x40);
        break;

    case 4:
        Com_Random_Select(wk, 6, 0x37, 0x37, 0x27, 0x27, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0085(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 0xa);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1e, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0086(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;

    case 1:
        EM_Term(wk, -1, -0x7FF8, 6, 1, -1);
        break;

    case 2:
        SA_Term(wk, 0x2e, 0x2f, 0xffff, 0);
        break;

    case 3:
        Normal_Attack(wk, 0xb, 0x12);
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

void Passive10_0087(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;

    case 1:
        EM_Term(wk, -1, -0x7FF8, 6, 1, -1);
        break;

    case 2:
        SA_Term(wk, 0xffff, 0x2f, 0xffff, 0);
        break;

    case 3:
        Normal_Attack(wk, 0xb, 0x10);
        break;

    case 4:
        Normal_Attack(wk, 8, 0x20);
        break;

    case 5:
        Normal_Attack(wk, 0xc, 0x40);
        break;

    case 6:
        Com_Random_Select(wk, 6, 0x37, 0x37, 0x27, 0x27, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0088(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, -0x7FD8, 6, 1, -1);
        break;

    case 1:
        SA_Term(wk, 0xffff, 0xffff, 0x30, 0);
        break;

    case 2:
        Normal_Attack(wk, 0xb, 0x10);
        break;

    case 3:
        Normal_Attack(wk, 8, 0x20);
        break;

    case 4:
        Normal_Attack(wk, 0xc, 0x40);
        break;

    case 5:
        Com_Random_Select(wk, 6, 0x37, 0x37, 0x27, 0x27, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0089(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1f, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0090(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1f, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0091(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1f, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0092(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, -0x7FE0, 6, 1, -1);
        break;

    case 1:
        Branch_Unit_Area(wk, 6, 0x59, 0x5a, 0x5b, 0x5b);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0093(PLW* wk) {
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

void Passive10_0094(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Branch_Unit_Area(wk, 6, 0x59, 0x5a, 0x5b, 1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0095(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 1, 0x30, 0);
        break;

    case 1:
        Branch_Unit_Area(wk, 6, 0x59, 0x5a, 0x5b, 0x5b);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0096(PLW* wk) {
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

void Passive10_0097(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
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

void Passive10_0098(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;

    case 1:
        EM_Term(wk, -1, -0x7FF0, 6, 1, -1);
        break;

    case 2:
        Normal_Attack(wk, 0xb, 0x10);
        break;

    case 3:
        Normal_Attack(wk, 8, 0x20);
        break;

    case 4:
        Normal_Attack(wk, 0xc, 0x40);
        break;

    case 5:
        Command_Attack(wk, 8, 0x1e, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0099(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xb, 0x10);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x20);
        break;

    case 2:
        Normal_Attack(wk, 0xc, 0x40);
        break;

    case 3:
        Com_Random_Select(wk, 6, 0x37, 0x37, 0x27, 0x27, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0100(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 1, 0x30, 0);
        break;

    case 1:
        Wait_Get_Up(wk, 0, -1);
        break;

    case 2:
        J_Command_Attack(wk, 8, 0x1f, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0101(PLW* wk) {
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

void Passive10_0102(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7FB0, -0x7FB0, 6, 1, -1);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x200);
        break;

    case 2:
        Command_Attack(wk, 8, 0x1e, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0103(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x70, 6, 0x68);
        break;

    case 1:
        Walk(wk, 1, 0x20, 0);
        break;

    case 2:
        Wait_Get_Up(wk, 3, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0104(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump(wk, 0xa, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0105(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x70, 6, 0x68);
        break;

    case 1:
        Pierce_On(wk);
        break;

    case 2:
        Command_Attack(wk, 8, 1, 0xa, -1);
        break;

    case 3:
        Wait_Get_Up(wk, 3, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0106(PLW* wk) {
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

void Passive10_0107(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x2e, 0x2f, 0x30, 0);
        break;

    case 1:
        Com_Random_Select(wk, 6, 0x37, 0x37, 0x27, 0x27, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0108(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xbf, 2);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0109(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x2e, 0xffff, 0x30, 0);
        break;

    case 1:
        Branch_Unit_Area(wk, 6, 0x59, 0x5a, 0x5b, 0x5b);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0110(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xc, 0x20);
        break;

    case 1:
        SA_Term(wk, 0x2e, 0x2f, 0xffff, 0);
        break;

    case 2:
        Com_Random_Select(wk, 6, 0x37, 0x37, 0x27, 0x27, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0111(PLW* wk) {
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

void Passive10_0112(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, -0x7FB0, 6, 1, -1);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x200);
        break;

    case 2:
        Command_Attack(wk, 8, 0x1e, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0113(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x20, 6, 1, -1);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1f, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0114(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x20, 8, 0x400, 1, -1, 0x20, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0115(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xb, 0x220);
        break;

    case 1:
        Normal_Attack(wk, 0xb, 0x102);
        break;

    case 2:
        Command_Attack(wk, 8, 0x1f, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0116(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x20, 8, 0x400, 0, -1, 0x20, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0117(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x20, 8, 0x200, 1, -1, 0x20, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0118(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x20, 8, 0x200, 0, -1, 0x20, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0119(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0120(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;

    case 1:
        Command_Attack(wk, 0xe, 0x1e, 10, -1);
        break;

    case 2:
        Command_Attack(wk, 0xe, 0x1e, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0121(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;

    case 1:
        Command_Attack(wk, 0xe, 0x1e, 10, -1);
        break;

    case 2:
        Command_Attack(wk, 0xe, 0x1e, 10, -1);
        break;

    case 3:
        Wait(wk, 0xe);
        break;

    case 4:
        Command_Attack(wk, 8, 0x1e, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0122(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;

    case 1:
        Command_Attack(wk, 0xe, 0x1e, 10, -1);
        break;

    case 2:
        Command_Attack(wk, 8, 0x1e, 10, -1);
        break;

    case 3:
        Command_Attack(wk, 8, 0x1e, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0123(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Provoke(wk, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0124(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xd, 0x100);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0125(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;

    case 1:
        Command_Attack(wk, 0xe, 0x1e, 10, -1);
        break;

    case 2:
        Command_Attack(wk, 0xe, 0x1e, 10, -1);
        break;

    case 3:
        Wait(wk, 0xe);
        break;

    case 4:
        Command_Attack(wk, 0xe, 0x1e, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0126(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;

    case 1:
        Command_Attack(wk, 0xe, 0x1e, 10, -1);
        break;

    case 2:
        Command_Attack(wk, 0xe, 0x1e, 10, -1);
        break;

    case 3:
        Command_Attack(wk, 0xe, 0x1e, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0127(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1F, 0xB, 0x700);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0128(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;

    case 1:
        Command_Attack(wk, 0xe, 0x1e, 0xb, 0x70);
        break;

    case 2:
        Wait(wk, 0xe);
        break;

    case 3:
        Command_Attack(wk, 0xe, 0x1e, 0xb, 0x70);
        break;

    case 4:
        Wait(wk, 0xe);
        break;

    case 5:
        Command_Attack(wk, 0xe, 0x1e, 0xb, 0x70);
        break;

    case 6:
        Wait(wk, 0xe);
        break;

    case 7:
        Command_Attack(wk, 0xe, 0x1e, 0xb, 0x70);
        break;

    case 8:
        Wait(wk, 0xe);
        break;

    case 9:
        Command_Attack(wk, 0xe, 0x1e, 0xb, 0x70);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0129(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;

    case 1:
        Command_Attack(wk, 0xe, 0x1e, 10, -1);
        break;

    case 2:
        Wait(wk, 0xe);
        break;

    case 3:
        Command_Attack(wk, 0xe, 0x1e, 10, -1);
        break;

    case 4:
        Wait(wk, 0xe);
        break;

    case 5:
        Command_Attack(wk, 0xe, 0x1e, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0130(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0xffff, 0x2f, 0x30, 0);
        break;

    case 1:
        Approach_Walk(wk, 0xbf, 2);
        break;

    case 2:
        Hi_Jump_Attack_Term(wk, -0x7FA0, -1, 8, 0x8400, 0, -0x7FA0, -1, 0x40);
        break;

    case 3:
        Normal_Attack(wk, 0xb, 0x10);
        break;

    case 4:
        Normal_Attack(wk, 8, 0x20);
        break;

    case 5:
        Normal_Attack(wk, 0xc, 0x40);
        break;

    case 6:
        Com_Random_Select(wk, 6, 0x37, 0x37, 0x27, 0x27, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0131(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 1, 0x30, 0);
        break;

    case 1:
        Wait_Get_Up(wk, 0, -1);
        break;

    case 2:
        J_Command_Attack(wk, 8, 0x1F, 0xB, 0x700);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0132(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;

    case 1:
        Command_Attack(wk, 0xe, 0x1e, 0xb, 0x70);
        break;

    case 2:
        Wait(wk, 0xe);
        break;

    case 3:
        Command_Attack(wk, 0xe, 0x1e, 0xb, 0x70);
        break;

    case 4:
        Wait(wk, 0xe);
        break;

    case 5:
        Command_Attack(wk, 0xe, 0x1e, 0xb, 0x70);
        break;

    case 6:
        Wait(wk, 0xe);
        break;

    case 7:
        Command_Attack(wk, 0xe, 0x1e, 0xb, 0x70);
        break;

    case 8:
        Wait(wk, 0xe);
        break;

    case 9:
        Command_Attack(wk, 0xe, 0x1e, 0xb, 0x70);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0133(PLW* wk) {
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

void Passive10_0134(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;

    case 1:
        Command_Attack(wk, 0xe, 0x1e, 0xb, 0x70);
        break;

    case 2:
        Wait(wk, 0xe);
        break;

    case 3:
        Command_Attack(wk, 0xe, 0x1e, 0xb, 0x70);
        break;

    case 4:
        Wait(wk, 0xe);
        break;

    case 5:
        Command_Attack(wk, 0xe, 0x1e, 0xb, 0x70);
        break;

    case 6:
        Wait(wk, 0xe);
        break;

    case 7:
        Command_Attack(wk, 0xe, 0x1e, 0xb, 0x70);
        break;

    case 8:
        Wait(wk, 0xe);
        break;

    case 9:
        Command_Attack(wk, 0xe, 0x1e, 0xb, 0x70);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0135(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump(wk, 1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive10_0136(PLW* wk) {
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

void Passive10_0137(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump(wk, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void (*const Passive10_Tbl[138])(PLW*) = {
    Passive10_0000, Passive10_0001, Passive10_0002, Passive10_0003, Passive10_0004, Passive10_0005, Passive10_0006,
    Passive10_0007, Passive10_0008, Passive10_0009, Passive10_0010, Passive10_0011, Passive10_0012, Passive10_0013,
    Passive10_0014, Passive10_0015, Passive10_0016, Passive10_0017, Passive10_0018, Passive10_0019, Passive10_0020,
    Passive10_0021, Passive10_0022, Passive10_0023, Passive10_0024, Passive10_0025, Passive10_0026, Passive10_0027,
    Passive10_0028, Passive10_0029, Passive10_0030, Passive10_0031, Passive10_0032, Passive10_0033, Passive10_0034,
    Passive10_0035, Passive10_0036, Passive10_0037, Passive10_0038, Passive10_0039, Passive10_0040, Passive10_0041,
    Passive10_0042, Passive10_0043, Passive10_0044, Passive10_0045, Passive10_0046, Passive10_0047, Passive10_0048,
    Passive10_0049, Passive10_0050, Passive10_0051, Passive10_0052, Passive10_0053, Passive10_0054, Passive10_0055,
    Passive10_0056, Passive10_0057, Passive10_0058, Passive10_0059, Passive10_0060, Passive10_0061, Passive10_0062,
    Passive10_0063, Passive10_0064, Passive10_0065, Passive10_0066, Passive10_0067, Passive10_0068, Passive10_0069,
    Passive10_0070, Passive10_0071, Passive10_0072, Passive10_0073, Passive10_0074, Passive10_0075, Passive10_0076,
    Passive10_0077, Passive10_0078, Passive10_0079, Passive10_0080, Passive10_0081, Passive10_0082, Passive10_0083,
    Passive10_0084, Passive10_0085, Passive10_0086, Passive10_0087, Passive10_0088, Passive10_0089, Passive10_0090,
    Passive10_0091, Passive10_0092, Passive10_0093, Passive10_0094, Passive10_0095, Passive10_0096, Passive10_0097,
    Passive10_0098, Passive10_0099, Passive10_0100, Passive10_0101, Passive10_0102, Passive10_0103, Passive10_0104,
    Passive10_0105, Passive10_0106, Passive10_0107, Passive10_0108, Passive10_0109, Passive10_0110, Passive10_0111,
    Passive10_0112, Passive10_0113, Passive10_0114, Passive10_0115, Passive10_0116, Passive10_0117, Passive10_0118,
    Passive10_0119, Passive10_0120, Passive10_0121, Passive10_0122, Passive10_0123, Passive10_0124, Passive10_0125,
    Passive10_0126, Passive10_0127, Passive10_0128, Passive10_0129, Passive10_0130, Passive10_0131, Passive10_0132,
    Passive10_0133, Passive10_0134, Passive10_0135, Passive10_0136, Passive10_0137
};
