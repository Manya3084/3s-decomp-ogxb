/* pass00.c, retail sf33rd.xbe.
 * PlayStation 2 C, not hand-adjusted for Xbox. Each named body was located
 * from the PS2 retail map: call graph, source order, and agreement of
 * constants, field offsets, callees, and size. See docs/decompiling.md.
 * The #include lines name headers in the PS2 tree (ps2.path).
 * Passive00_0031 is folded into 0x6E9E1 with 10 other bodies. Unnamed.
 * Passive00_0046 is folded into 0x706D9 with 9 other bodies. Unnamed.
 * Passive00_0049 is folded into 0x70746 with 3 other bodies. Unnamed.
 * Passive00_0134 is folded into 0x720E4 with 4 other bodies. Unnamed.
 * Passive00_0002 is folded into 0xD0FA4 with 1 other bodies. Unnamed.
 * Passive00_0008 is folded into 0xD1009 with 1 other bodies. Unnamed.
 * Passive00_0009 0xD1050 size 0x46.
 * Passive00_0012 is folded into 0xD1096 with 1 other bodies. Unnamed.
 * Passive00_0013 0xD10D9 size 0x4F.
 * Passive00_0017 is folded into 0xD1128 with 1 other bodies. Unnamed.
 * Passive00_0018 0xD118F size 0x52.
 * Passive00_0021 0xD11E1 size 0x52.
 * Passive00_0022 0xD1233 size 0x77.
 * Passive00_0023 0xD12AA size 0x64.
 * Passive00_0027 0xD134B size 0x58.
 * Passive00_0032 is folded into 0xD13A3 with 1 other bodies. Unnamed.
 * Passive00_0036 0xD13DD size 0x7D.
 * Passive00_0040 0xD14B5 size 0x6A.
 * Passive00_0041 is folded into 0xD151F with 1 other bodies. Unnamed.
 * Passive00_0042 0xD1570 size 0x3A.
 * Passive00_0043 0xD15AA size 0x5A.
 * Passive00_0045 0xD1604 size 0x5A.
 * Passive00_0051 0xD1692 size 0x41.
 * Passive00_0054 0xD16D3 size 0x3D.
 * Passive00_0055 0xD1710 size 0x2A.
 * Passive00_0056 0xD173A size 0x3D.
 * Passive00_0057 0xD1777 size 0x36.
 * Passive00_0059 is folded into 0xD17AD with 1 other bodies. Unnamed.
 * Passive00_0062 0xD17EE size 0x3D.
 * Passive00_0069 0xD1870 size 0x4D.
 * Passive00_0071 0xD18BD size 0x50.
 * Passive00_0072 is folded into 0xD190D with 1 other bodies. Unnamed.
 * Passive00_0073 0xD195B size 0x5A.
 * Passive00_0074 is folded into 0xD19B5 with 1 other bodies. Unnamed.
 * Passive00_0075 0xD19F5 size 0x49.
 * Passive00_0076 0xD1A3E size 0x81.
 * Passive00_0077 0xD1ABF size 0x54.
 * Passive00_0078 0xD1B13 size 0x69.
 * Passive00_0079 0xD1B7C size 0x4A.
 * Passive00_0080 0xD1BC6 size 0x5D.
 * Passive00_0081 0xD1C23 size 0x5D.
 * Passive00_0082 0xD1C80 size 0x51.
 * Passive00_0083 0xD1CD1 size 0x6F.
 * Passive00_0084 0xD1D40 size 0x72.
 * Passive00_0086 0xD1DB2 size 0x82.
 * Passive00_0087 0xD1E34 size 0x9A.
 * Passive00_0088 0xD1ECE size 0xB0.
 * Passive00_0094 is folded into 0xD1F7E with 1 other bodies. Unnamed.
 * Passive00_0095 is folded into 0xD1FAE with 1 other bodies. Unnamed.
 * Passive00_0098 0xD1FF3 size 0x84.
 * Passive00_0099 0xD2077 size 0x49.
 * Passive00_0100 0xD20C0 size 0x52.
 * Passive00_0104 0xD2112 size 0x27.
 * Passive00_0106 0xD2197 size 0x4E.
 * Passive00_0109 0xD21E5 size 0x6A.
 * Passive00_0112 0xD224F size 0x65.
 * Passive00_0113 0xD22B4 size 0x7B.
 * Passive00_0114 0xD232F size 0x54.
 * Passive00_0115 0xD2383 size 0x7B.
 * Passive00_0116 0xD23FE size 0x37.
 * Passive00_0117 0xD2435 size 0x37.
 * Passive00_0118 0xD246C size 0x34.
 * Passive00_0119 0xD24A0 size 0x37.
 * Passive00_0120 0xD24D7 size 0x37.
 * Passive00_0121 0xD250E size 0x34.
 * Passive00_0123 is folded into 0xD2542 with 1 other bodies. Unnamed.
 * Passive00_0127 is folded into 0xD25A6 with 1 other bodies. Unnamed.
 * Passive00_0128 is folded into 0xD25F5 with 1 other bodies. Unnamed.
 * Passive00_0129 0xD2640 size 0x4F.
 * Passive00_0131 0xD268F size 0x47.
 * Passive00_0132 0xD26D6 size 0x42.
 * Passive00_0138 0xD273D size 0x3B.
 * Passive00_0140 0xD2778 size 0x37.
 * Passive00_0141 0xD27AF size 0x54.
 * Passive00_0142 0xD2803 size 0x66.
 * Passive00_0144 0xD288E size 0x45.
 * Passive00_0145 0xD28D3 size 0x48.
 * Passive00_0146 0xD291B size 0x48.
 * Passive00_0147 0xD2963 size 0x48.
 * Passive00_0148 0xD29AB size 0x3D.
 * Passive00_0150 0xD29E8 size 0x45.
 * Passive00_0151 0xD2A2D size 0x48.
 * Passive00_0152 is folded into 0xD2A75 with 2 other bodies. Unnamed.
 * Passive00_0153 0xD2AB2 size 0x36.
 * Passive00_0154 0xD2AE8 size 0x36.
 * Passive00_0156 0xD2B1E size 0x3D.
 * Passive00_0058 is folded into 0xD34B4 with 10 other bodies. Unnamed.
 * Passive00_0004 is folded into 0xD4486 with 6 other bodies. Unnamed.
 * Passive00_0006 is folded into 0xD44C8 with 1 other bodies. Unnamed.
 * Passive00_0016 is folded into 0xD45F7 with 1 other bodies. Unnamed.
 * Passive00_0030 is folded into 0xD480A with 2 other bodies. Unnamed.
 * Passive00_0035 is folded into 0xD4893 with 1 other bodies. Unnamed.
 * Passive00_0038 is folded into 0xD493D with 1 other bodies. Unnamed.
 * Passive00_0039 is folded into 0xD4985 with 1 other bodies. Unnamed.
 * Passive00_0048 is folded into 0xD4B17 with 1 other bodies. Unnamed.
 * Passive00_0068 is folded into 0xD4D4A with 1 other bodies. Unnamed.
 * Passive00_0085 is folded into 0xD5294 with 1 other bodies. Unnamed.
 * Passive00_0092 is folded into 0xD5486 with 1 other bodies. Unnamed.
 * Passive00_0096 is folded into 0xD54CF with 1 other bodies. Unnamed.
 * Passive00_0101 is folded into 0xD5615 with 1 other bodies. Unnamed.
 * Passive00_0102 is folded into 0xD5658 with 1 other bodies. Unnamed.
 * Passive00_0103 is folded into 0xD569B with 1 other bodies. Unnamed.
 * Passive00_0107 is folded into 0xD5760 with 1 other bodies. Unnamed.
 * Passive00_0108 is folded into 0xD57B7 with 1 other bodies. Unnamed.
 * Passive00_0111 is folded into 0xD589D with 1 other bodies. Unnamed.
 * Passive00_0124 is folded into 0xD5C24 with 1 other bodies. Unnamed.
 * Passive00_0125 is folded into 0xD5C89 with 1 other bodies. Unnamed.
 * Passive00_0130 is folded into 0xD5CDB with 1 other bodies. Unnamed.
 * Passive00_0139 is folded into 0xDC346 with 9 other bodies. Unnamed.
 * Passive00_0093 is folded into 0xDDAB7 with 6 other bodies. Unnamed.
 * Passive00_0044 is folded into 0xDE16D with 2 other bodies. Unnamed.
 * Passive00_0047 is folded into 0xDE286 with 8 other bodies. Unnamed.
 * Passive00_0029 is folded into 0xDFCF2 with 10 other bodies. Unnamed.
 * Passive00_0155 is folded into 0xE1487 with 1 other bodies. Unnamed.
 * Passive00_0110 is folded into 0xE19B6 with 6 other bodies. Unnamed.
 * Passive00_0010 is folded into 0xE1BF4 with 6 other bodies. Unnamed.
 * Passive00_0122 is folded into 0xE2E66 with 5 other bodies. Unnamed.
 * Passive00_0000 is folded into 0xD0F75 with 14 other bodies. Unnamed.
 * Passive00_0001 is folded into 0xAB943 with 26 other bodies. Unnamed.
 * Passive00_0003 is folded into 0xDC466 with 11 other bodies. Unnamed.
 * Passive00_0005 is folded into 0x7EE7B with 22 other bodies. Unnamed.
 * Passive00_0007 is folded into 0xE2EEB with 17 other bodies. Unnamed.
 * Passive00_0011 is folded into 0x82978 with 9 other bodies. Unnamed.
 * Passive00_0014 is folded into 0xA9FA1 with 15 other bodies. Unnamed.
 * Passive00_0015 is folded into 0x6D0D1 with 17 other bodies. Unnamed.
 * Passive00_0019 is folded into 0x6D0D1 with 17 other bodies. Unnamed.
 * Passive00_0020 is folded into 0x6D236 with 17 other bodies. Unnamed.
 * Passive00_0024 is folded into 0xD130E with 4 other bodies. Unnamed.
 * Passive00_0025 is folded into 0xD2139 with 3 other bodies. Unnamed.
 * Passive00_0026 is folded into 0xD47E2 with 16 other bodies. Unnamed.
 * Passive00_0028 is folded into 0x7076E with 2 other bodies. Unnamed.
 * Passive00_0033 is folded into 0xD4852 with 6 other bodies. Unnamed.
 * Passive00_0034 is folded into 0x6D0A6 with 21 other bodies. Unnamed.
 * Passive00_0037 is folded into 0xD145A with 3 other bodies. Unnamed.
 * Passive00_0050 is folded into 0xD165E with 2 other bodies. Unnamed.
 * Passive00_0052 is folded into 0xA9FF7 with 21 other bodies. Unnamed.
 * Passive00_0053 is folded into 0x82920 with 3 other bodies. Unnamed.
 * Passive00_0060 is folded into 0x7EE7B with 22 other bodies. Unnamed.
 * Passive00_0061 is folded into 0xD182B with 2 other bodies. Unnamed.
 * Passive00_0063 is folded into 0xE2F17 with 13 other bodies. Unnamed.
 * Passive00_0064 is folded into 0x1C720 with 2 other bodies. Unnamed.
 * Passive00_0065 is folded into 0xD4852 with 6 other bodies. Unnamed.
 * Passive00_0066 is folded into 0xD182B with 2 other bodies. Unnamed.
 * Passive00_0067 is folded into 0x82978 with 9 other bodies. Unnamed.
 * Passive00_0070 is folded into 0xD4852 with 6 other bodies. Unnamed.
 * Passive00_0089 is folded into 0xE2EEB with 17 other bodies. Unnamed.
 * Passive00_0090 is folded into 0xE2F17 with 13 other bodies. Unnamed.
 * Passive00_0091 is folded into 0xE2F43 with 11 other bodies. Unnamed.
 * Passive00_0097 is folded into 0xD145A with 3 other bodies. Unnamed.
 * Passive00_0105 is folded into 0xD2139 with 3 other bodies. Unnamed.
 * Passive00_0126 is folded into 0x71E79 with 17 other bodies. Unnamed.
 * Passive00_0133 is folded into 0x822AE with 19 other bodies. Unnamed.
 * Passive00_0135 is folded into 0xD2718 with 15 other bodies. Unnamed.
 * Passive00_0136 is folded into 0xE33B0 with 8 other bodies. Unnamed.
 * Passive00_0137 is folded into 0x71EDE with 7 other bodies. Unnamed.
 * Passive00_0143 is folded into 0xD2869 with 1 other bodies. Unnamed.
 * Passive00_0149 is folded into 0xA9FCC with 23 other bodies. Unnamed.
 * Passive00_0157 is folded into 0x1C78D with 1 other bodies. Unnamed.
 * The other functions in this file are not located in sf33rd.xbe yet.
 */

#include "sf33rd/Source/Game/pass00.h"
#include "common.h"
#include "sf33rd/Source/Game/Com_Sub.h"
#include "sf33rd/Source/Game/workuser.h"

void (*const Passive00_Tbl[158])();

void Passive00(PLW* wk) {
    Passive00_Tbl[(s16)Pattern_Index[wk->wu.id]](wk);
}

void Passive00_0000(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xD, M_Lv[wk->wu.id]);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0001(PLW* wk) {
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

void Passive00_0002(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 3, -1);
        break;

    case 1:
        Pierce_On(wk);
        break;

    case 2:
        Command_Attack(wk, 8, 0, 0xA, -1);
        break;

    case 3:
        EM_Term(wk, 0x7FFF, -1, 1, 1, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0003(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        VS_Jump_Guard(wk);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0004(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x60, 6, 0x53);
        break;

    case 1:
        Command_Attack(wk, 8, 1, 0xB, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0005(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Forced_Guard(wk, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0006(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x7B, 2);
        break;

    case 1:
        EM_Term(wk, 0x7FFF, -1, 1, 1, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0007(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0008(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;

    case 1:
        Command_Attack(wk, 0xC, 0, 0xB, -1);
        break;

    case 2:
        Command_Attack(wk, 8, 0x1C, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0009(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x38, 7, 1, -1);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1F, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0010(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Short_Range_Attack(wk, 8, 0x40, 6, 0x1D);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0011(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0012(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F80, 0, 0, 2, 0);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0013(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 3, -1);
        break;

    case 1:
        Normal_Attack(wk, 9, 0x10);
        break;

    case 2:
        Normal_Attack(wk, 0xB, 0x20);
        break;

    case 3:
        Normal_Attack(wk, 8, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0014(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0015(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0016(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x71, 2);
        break;

    case 1:
        Wait_Get_Up(wk, 3, -1);
        break;

    case 2:
        Normal_Attack(wk, 9, 0x12);
        break;

    case 3:
        Normal_Attack(wk, 0xB, 0x202);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0017(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x71, 2);
        break;

    case 1:
        Wait_Get_Up(wk, 0, -1);
        break;

    case 2:
        Normal_Attack(wk, 9, 0x10);
        break;

    case 3:
        Normal_Attack(wk, 0xB, 0x20);
        break;

    case 4:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0018(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x71, 2);
        break;

    case 1:
        Wait_Get_Up(wk, 3, -1);
        break;

    case 2:
        Normal_Attack(wk, 0xB, 0x20);
        break;

    case 3:
        Normal_Attack(wk, 8, 0x40);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0019(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0020(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 3, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0021(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x12);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x12);
        break;

    case 2:
        Wait_Get_Up(wk, 3, -1);
        break;

    case 3:
        Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0022(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;

    case 1:
        Check_BOSS(wk, 6, 0x17);
        break;

    case 2:
        Jump_Attack_Term(wk, -1, -0x7FC0, 0xB, 0x40, 0, -0x7F90, -1, 0x20);
        break;

    case 3:
        Normal_Attack(wk, 0xB, 0x20);
        break;

    case 4:
        Normal_Attack(wk, 8, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0023(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;

    case 1:
        Jump_Attack_Term(wk, -1, -0x7FC0, 0xB, 0x10, 0, -1, -1, -1);
        break;

    case 2:
        Normal_Attack(wk, 9, 0x10);
        break;

    case 3:
        Normal_Attack(wk, 8, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0024(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0025(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x60, 6, 0x68);
        break;

    case 1:
        Pierce_On(wk);
        break;

    case 2:
        Command_Attack(wk, 8, 1, 0xA, -1);
        break;

    case 3:
        Wait_Get_Up(wk, 3, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0026(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0027(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x33, 2);
        break;

    case 1:
        EM_Term(wk, -1, -0x7FA0, 6, 1, -1);
        break;

    case 2:
        Lever_Attack(wk, 8, 1, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0028(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x220);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0029(PLW* wk) {
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

void Passive00_0030(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F80, -0x7FD0, 6, 1, -1);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x40);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0031(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 1, 0x20, 1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0032(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x100);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0033(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x33, 2);
        break;

    case 1:
        Lever_Attack(wk, 8, 0, 0x110);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0034(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0035(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x102);
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

void Passive00_0036(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, -0x7FE8, 6, 1, -1);
        break;

    case 1:
        Normal_Attack(wk, 0xB, 0x102);
        break;

    case 2:
        Normal_Attack(wk, 0xB, 0x202);
        break;

    case 3:
        ETC_Term(wk, 0, 6, 0x99);
        break;

    case 4:
        Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0037(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x33, 2);
        break;

    case 1:
        EM_Term(wk, -1, -0x7FFE, 6, 1, -1);
        break;

    case 2:
        Lever_Attack(wk, 8, 0, 0x110);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0038(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, -0x7FFE, 6, 1, -1);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x110);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0039(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x7B, 2);
        break;

    case 1:
        EM_Term(wk, -1, -0x7FD0, 6, 1, -1);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x42);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0040(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;

    case 1:
        EM_Term(wk, -0x7F80, -0x7FB0, 6, 1, -1);
        break;

    case 2:
        Normal_Attack(wk, 9, 0x42);
        break;

    case 3:
        Wait(wk, 5);
        break;

    case 4:
        Normal_Attack(wk, 8, 0x40);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0041(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, -0x7FF0, 6, 1, -1);
        break;

    case 1:
        Normal_Attack(wk, 0xB, 0x100);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x40);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0042(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, -0x7FC0, 8, 0x40, 0, -0x7F90, -1, 0x40);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0043(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Check_BOSS(wk, 6, 0x1B);
        break;

    case 1:
        EM_Term(wk, -0x7F80, -0x7FB0, 6, 1, -1);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0044(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, -0x7FC0, 6, 1, -1);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0045(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Check_BOSS(wk, 6, 0x1B);
        break;

    case 1:
        EM_Term(wk, -1, -0x7F90, 6, 1, -1);
        break;

    case 2:
        J_Command_Attack(wk, 8, 0x1F, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0046(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Status(wk, 2, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0047(PLW* wk) {
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

void Passive00_0048(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F80, -0x7FC0, 6, 1, -1);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x12);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x12);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0049(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 8, 0x10);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0050(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x12);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x22);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0051(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xB, 0x220);
        break;

    case 1:
        Normal_Attack(wk, 0xB, 0x12);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x402);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0052(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x202);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0053(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1D, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0054(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
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

void Passive00_0055(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 8, 0x40);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0056(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, -1, -0x7FA8, 8, 0x100, 0, -1, -1, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0057(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, -0x7FA8, 8, 0x10, 0, -1, -1, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0058(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Status(wk, 2, 1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0059(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ETC_Term(wk, 0, 6, 0x34);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0060(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Forced_Guard(wk, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0061(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ETC_Term(wk, 0, 6, 0x99);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0062(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x43, 2);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x110);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0063(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0064(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 1, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0065(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x33, 2);
        break;

    case 1:
        Lever_Attack(wk, 8, 0, 0x110);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0066(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ETC_Term(wk, 0, 6, 0x99);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0067(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0068(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 6, 0x59, 0x59, 0x59, 0x5a, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0069(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;

    case 1:
        Command_Attack(wk, 0xC, 0, 0xB, -1);
        break;

    case 2:
        J_Command_Attack(wk, 8, 0x1F, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0070(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x33, 2);
        break;

    case 1:
        Lever_Attack(wk, 8, 0, 0x110);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0071(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x33, 2);
        break;

    case 1:
        Normal_Attack(wk, 0xB, 0x220);
        break;

    case 2:
        Normal_Attack(wk, 0xB, 0x12);
        break;

    case 3:
        Normal_Attack(wk, 8, 0x402);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0072(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;

    case 1:
        Command_Attack(wk, 0xC, 0, 0xB, -1);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0073(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, -1, -0x7FA0, 8, 0x400, 0, -0x7F90, -1, 0x20);
        break;

    case 1:
        Normal_Attack(wk, 0xB, 0x12);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x42);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0074(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x10);
        break;

    case 1:
        Normal_Attack(wk, 0xB, 0x20);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0075(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x20);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x42);
        break;

    case 2:
        J_Command_Attack(wk, 8, 0x1F, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0076(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xB1, 2);
        break;

    case 1:
        Jump_Attack_Term(wk, -1, -0x7FC0, 8, 0x400, 0, -0x7F90, -1, 0x20);
        break;

    case 2:
        Normal_Attack(wk, 9, 0x10);
        break;

    case 3:
        Normal_Attack(wk, 8, 0x42);
        break;

    case 4:
        J_Command_Attack(wk, 8, 0x1F, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0077(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, -0x7FC0, 0xB, 0x40, 0, -0x7F90, -1, 0x200);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0078(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, -0x7FC0, 0xB, 0x400, 0, -0x7F90, -1, 0x20);
        break;

    case 1:
        Normal_Attack(wk, 9, 0x100);
        break;

    case 2:
        Normal_Attack(wk, 0xB, 0x20);
        break;

    case 3:
        Normal_Attack(wk, 8, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0079(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, -0x7FC0, 0xB, 0x40, 0, -1, -1, -1);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x40);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0080(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, -1, -0x7FB0, 0xB, 0x40, 0, -0x7F90, -1, 0x200);
        break;

    case 1:
        Normal_Attack(wk, 0xB, 0x200);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x40);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0081(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, -1, -0x7FA0, 0xB, 0x400, 0, -0x7F90, -1, 0x20);
        break;

    case 1:
        Normal_Attack(wk, 0xB, 0x10);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0082(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, -1, -0x7FA0, 0xB, 0x40, 0, -1, -1, -1);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0083(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, -1, -0x7FA0, 0xB, 0x400, 0, -0x7F90, -1, 0x20);
        break;

    case 1:
        Normal_Attack(wk, 9, 0x10);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x42);
        break;

    case 3:
        J_Command_Attack(wk, 8, 0x1F, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0084(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, -1, -0x7FA0, 0xB, 0x400, 0, -0x7F90, -1, 0x200);
        break;

    case 1:
        Normal_Attack(wk, 9, 0x10);
        break;

    case 2:
        Normal_Attack(wk, 0xB, 0x20);
        break;

    case 3:
        Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0085(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 8);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0086(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Check_BOSS(wk, 6, 0x49);
        break;

    case 1:
        Pierce_On(wk);
        break;

    case 2:
        EM_Term(wk, -1, -0x7FD0, 6, 1, -1);
        break;

    case 3:
        Normal_Attack(wk, 8, 0x42);
        break;

    case 4:
        Wait(wk, 5);
        break;

    case 5:
        Command_Attack(wk, 8, 0x1C, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0087(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Check_BOSS(wk, 6, 0x49);
        break;

    case 1:
        Pierce_On(wk);
        break;

    case 2:
        EM_Term(wk, -1, -0x7FD0, 6, 1, -1);
        break;

    case 3:
        Normal_Attack(wk, 8, 0x42);
        break;

    case 4:
        J_Command_Attack(wk, 0xB, 0x1F, 10, -1);
        break;

    case 5:
        ETC_Term(wk, 2, 6, 1);
        break;

    case 6:
        Command_Attack(wk, 8, 0x1C, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0088(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;

    case 1:
        Approach_Walk(wk, 0xB1, 2);
        break;

    case 2:
        Jump_Attack_Term(wk, -1, -0x7FC0, 0xB, 0x400, 0, -0x7F90, -1, 0x200);
        break;

    case 3:
        Normal_Attack(wk, 8, 0x42);
        break;

    case 4:
        J_Command_Attack(wk, 0xB, 0x1F, 10, -1);
        break;

    case 5:
        ETC_Term(wk, 2, 6, 1);
        break;

    case 6:
        Command_Attack(wk, 8, 0x1C, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0089(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0090(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0091(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0092(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, -0x7FB8, 6, 1, -1);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0093(PLW* wk) {
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

void Passive00_0094(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 6, 0x59, 0x5A, 0x5A, 0x5B, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0095(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 1, 0x30, 0);
        break;

    case 1:
        Com_Random_Select(wk, 6, 0x59, 0x59, 0x59, 0x5A, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0096(PLW* wk) {
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

void Passive00_0097(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x33, 2);
        break;

    case 1:
        EM_Term(wk, -1, -0x7FFE, 6, 1, -1);
        break;

    case 2:
        Lever_Attack(wk, 8, 0, 0x110);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0098(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x33, 2);
        break;

    case 1:
        EM_Term(wk, -1, -0x7FF0, 6, 1, -1);
        break;

    case 2:
        Normal_Attack(wk, 9, 0x100);
        break;

    case 3:
        Normal_Attack(wk, 8, 0x42);
        break;

    case 4:
        Check_BOSS(wk, 6, 0xe);
        break;

    case 5:
        J_Command_Attack(wk, 8, 0x1f, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0099(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x10);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x42);
        break;

    case 2:
        J_Command_Attack(wk, 8, 0x1F, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0100(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;

    case 1:
        Check_BOSS(wk, 6, 0x88);
        break;

    case 2:
        Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0101(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;

    case 1:
        Com_Random_Select(wk, 6, 0x59, 0x5A, 0x5A, 0x5B, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0102(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;

    case 1:
        Com_Random_Select(wk, 6, 0x59, 0x59, 0x59, 0x5A, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0103(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x60, 6, 0x68);
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

void Passive00_0104(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump(wk, 0, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0105(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x60, 6, 0x68);
        break;

    case 1:
        Pierce_On(wk);
        break;

    case 2:
        Command_Attack(wk, 8, 1, 0xA, -1);
        break;

    case 3:
        Wait_Get_Up(wk, 3, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0106(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x60, 6, 0x68);
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

void Passive00_0107(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;

    case 1:
        EM_Term(wk, -1, -0x7FD0, 6, 1, -1);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x42);
        break;

    case 3:
        Normal_Attack(wk, 8, 0x40);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0108(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBB, 2);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0109(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;

    case 1:
        EM_Term(wk, -1, -0x7F90, 6, 1, -1);
        break;

    case 2:
        J_Command_Attack(wk, 0xB, 0x1F, 0xA, -1);
        break;

    case 3:
        Lever_Attack(wk, 8, 0, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0110(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0111(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x7B, 2);
        break;

    case 1:
        EM_Term(wk, -1, -0x7FA0, 6, 1, -1);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x42);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0112(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;

    case 1:
        EM_Term(wk, -1, -0x7FB0, 6, 1, -1);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x42);
        break;

    case 3:
        J_Command_Attack(wk, 8, 0x1F, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0113(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Check_BOSS(wk, 6, 0x70);
        break;

    case 1:
        Pierce_On(wk);
        break;

    case 2:
        EM_Term(wk, -1, -0x7FA8, 6, 1, -1);
        break;

    case 3:
        Normal_Attack(wk, 8, 0x42);
        break;

    case 4:
        J_Command_Attack(wk, 0xB, 0x1F, 10, -1);
        break;

    case 5:
        Normal_Attack(wk, 8, 0x40);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0114(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;

    case 1:
        EM_Term(wk, -1, 0x30, 7, 1, -1);
        break;

    case 2:
        J_Command_Attack(wk, 0xB, 0x1F, 0xA, -1);
        break;

    case 3:
        J_Command_Attack(wk, 0xB, 0x1F, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0115(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;

    case 1:
        EM_Term(wk, -1, -0x7FB0, 6, 1, -1);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x42);
        break;

    case 3:
        J_Command_Attack(wk, 0xb, 0x1f, 10, -1);
        break;

    case 4:
        ETC_Term(wk, 2, 6, 1);
        break;

    case 5:
        Normal_Attack(wk, 8, 0x42);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0116(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x10, 8, 0x400, 1, -1, 0x10, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0117(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x10, 8, 0x200, 1, -1, 0x10, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0118(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x10, 8, 0x20, 1, -1, 0x10, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0119(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x10, 8, 0x400, 0, -1, 0x10, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0120(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x10, 8, 0x200, 0, -1, 0x10, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0121(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x10, 8, 0x20, 0, -1, 0x10, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0122(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x30, 6, 1, -1);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x42);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0123(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;

    case 1:
        EM_Term(wk, -1, 0x30, 6, 1, -1);
        break;

    case 2:
        Normal_Attack(wk, 9, 0x42);
        break;

    case 3:
        Wait(wk, 5);
        break;

    case 4:
        Normal_Attack(wk, 8, 0x40);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0124(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;

    case 1:
        EM_Term(wk, -1, 0x30, 6, 1, -1);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x42);
        break;

    case 3:
        Wait(wk, 5);
        break;

    case 4:
        Normal_Attack(wk, 8, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0125(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x48, 6, 0x22);
        break;

    case 1:
        Walk(wk, 1, 0x18, 0);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0126(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x40);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0127(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x48, 6, 0x7E);
        break;

    case 1:
        Walk(wk, 1, 0x18, 0);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x40);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0128(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F80, -0x7FB0, 6, 1, -1);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x12);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x12);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0129(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x40, 6, 0x40);
        break;

    case 1:
        Walk(wk, 1, 0x10, 0);
        break;

    case 2:
        Lever_Attack(wk, 8, 1, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0130(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x50, 6, 0x6E);
        break;

    case 1:
        Walk(wk, 1, 0x18, 0);
        break;

    case 2:
        EM_Term(wk, -1, -0x7FB0, 6, 1, -1);
        break;

    case 3:
        Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0131(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x71, 2);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x100);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0132(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x2E, 0x2F, 0x30, 0);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0133(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0134(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Attack_Complete(wk, 3, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0135(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Provoke(wk, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0136(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0137(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x22);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0138(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 5);
        break;

    case 1:
        Lever_Attack(wk, 8, 1, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0139(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump(wk, 1);
        break;

    case 1:
        Look(wk, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0140(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7F70, -1, 8, 0x40, 1, -1, 0x20, 0x40);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0141(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7F70, -0x7FC0, 8, 0x40, 2, -1, -0x7FB0, 0x40);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0142(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7F70, -0x7FC0, 9, 0x40, 2, -1, -1, -1);
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

void Passive00_0143(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 0xA);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0144(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F80, -1, 6, 1, -1);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x42);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0145(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F90, -1, 6, 1, -1);
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

void Passive00_0146(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F70, -1, 6, 1, -1);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0147(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F90, -1, 6, 1, -1);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x12);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x12);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0148(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, -0x7FC0, 0xB, 0x400, 1, -0x7F90, -1, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0149(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x402);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0150(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F90, -1, 6, 1, -1);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x42);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0151(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F90, -1, 6, 1, -1);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0152(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0153(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 6, 0x59, 0x6E, 0x89, 0x98, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0154(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 6, 0x6C, 0x9B, 0x5A, 0x98, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0155(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 0xC, 0, 0xB, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0156(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 5);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1E, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive00_0157(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ETC_Term(wk, 0, 6, 0x9A);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void (*const Passive00_Tbl[158])(PLW*) = {
    Passive00_0000, Passive00_0001, Passive00_0002, Passive00_0003, Passive00_0004, Passive00_0005, Passive00_0006,
    Passive00_0007, Passive00_0008, Passive00_0009, Passive00_0010, Passive00_0011, Passive00_0012, Passive00_0013,
    Passive00_0014, Passive00_0015, Passive00_0016, Passive00_0017, Passive00_0018, Passive00_0019, Passive00_0020,
    Passive00_0021, Passive00_0022, Passive00_0023, Passive00_0024, Passive00_0025, Passive00_0026, Passive00_0027,
    Passive00_0028, Passive00_0029, Passive00_0030, Passive00_0031, Passive00_0032, Passive00_0033, Passive00_0034,
    Passive00_0035, Passive00_0036, Passive00_0037, Passive00_0038, Passive00_0039, Passive00_0040, Passive00_0041,
    Passive00_0042, Passive00_0043, Passive00_0044, Passive00_0045, Passive00_0046, Passive00_0047, Passive00_0048,
    Passive00_0049, Passive00_0050, Passive00_0051, Passive00_0052, Passive00_0053, Passive00_0054, Passive00_0055,
    Passive00_0056, Passive00_0057, Passive00_0058, Passive00_0059, Passive00_0060, Passive00_0061, Passive00_0062,
    Passive00_0063, Passive00_0064, Passive00_0065, Passive00_0066, Passive00_0067, Passive00_0068, Passive00_0069,
    Passive00_0070, Passive00_0071, Passive00_0072, Passive00_0073, Passive00_0074, Passive00_0075, Passive00_0076,
    Passive00_0077, Passive00_0078, Passive00_0079, Passive00_0080, Passive00_0081, Passive00_0082, Passive00_0083,
    Passive00_0084, Passive00_0085, Passive00_0086, Passive00_0087, Passive00_0088, Passive00_0089, Passive00_0090,
    Passive00_0091, Passive00_0092, Passive00_0093, Passive00_0094, Passive00_0095, Passive00_0096, Passive00_0097,
    Passive00_0098, Passive00_0099, Passive00_0100, Passive00_0101, Passive00_0102, Passive00_0103, Passive00_0104,
    Passive00_0105, Passive00_0106, Passive00_0107, Passive00_0108, Passive00_0109, Passive00_0110, Passive00_0111,
    Passive00_0112, Passive00_0113, Passive00_0114, Passive00_0115, Passive00_0116, Passive00_0117, Passive00_0118,
    Passive00_0119, Passive00_0120, Passive00_0121, Passive00_0122, Passive00_0123, Passive00_0124, Passive00_0125,
    Passive00_0126, Passive00_0127, Passive00_0128, Passive00_0129, Passive00_0130, Passive00_0131, Passive00_0132,
    Passive00_0133, Passive00_0134, Passive00_0135, Passive00_0136, Passive00_0137, Passive00_0138, Passive00_0139,
    Passive00_0140, Passive00_0141, Passive00_0142, Passive00_0143, Passive00_0144, Passive00_0145, Passive00_0146,
    Passive00_0147, Passive00_0148, Passive00_0149, Passive00_0150, Passive00_0151, Passive00_0152, Passive00_0153,
    Passive00_0154, Passive00_0155, Passive00_0156, Passive00_0157
};
