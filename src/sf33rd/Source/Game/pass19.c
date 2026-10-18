/* pass19.c, retail sf33rd.xbe.
 * PlayStation 2 C, not hand-adjusted for Xbox. Each named body was located
 * from the PS2 retail map: call graph, source order, and agreement of
 * constants, field offsets, callees, and size. See docs/decompiling.md.
 * The #include lines name headers in the PS2 tree (ps2.path).
 * Passive19 0xE1B95 size 0x1A.
 * Passive19_0016 0xE1C4C size 0x72.
 * Passive19_0018 0xE1CBE size 0x81.
 * Passive19_0021 0xE1D3F size 0x40.
 * Passive19_0027 0xE1EA0 size 0x43.
 * Passive19_0032 0xE1F12 size 0x51.
 * Passive19_0034 0xE1F63 size 0x40.
 * Passive19_0035 0xE1FA3 size 0x3F.
 * Passive19_0036 0xE1FE2 size 0x48.
 * Passive19_0038 0xE202A size 0x48.
 * Passive19_0039 0xE2072 size 0x48.
 * Passive19_0040 0xE20BA size 0x48.
 * Passive19_0041 0xE2102 size 0x57.
 * Passive19_0043 0xE2159 size 0x49.
 * Passive19_0044 0xE21A2 size 0x5A.
 * Passive19_0045 0xE21FC size 0x48.
 * Passive19_0047 0xE2244 size 0x43.
 * Passive19_0063 0xE23F4 size 0x60.
 * Passive19_0065 0xE2454 size 0x64.
 * Passive19_0066 0xE24B8 size 0x40.
 * Passive19_0069 0xE2538 size 0x2F.
 * Passive19_0072 0xE2567 size 0x4D.
 * Passive19_0074 0xE25B4 size 0x54.
 * Passive19_0075 0xE2608 size 0x45.
 * Passive19_0078 0xE2707 size 0x5B.
 * Passive19_0079 0xE2762 size 0x57.
 * Passive19_0081 0xE2810 size 0x5B.
 * Passive19_0082 0xE286B size 0x54.
 * Passive19_0084 0xE28BF size 0x53.
 * Passive19_0085 0xE2912 size 0x41.
 * Passive19_0092 0xE29D1 size 0x49.
 * Passive19_0096 0xE2A5F size 0x5A.
 * Passive19_0098 0xE2AB9 size 0x73.
 * Passive19_0100 0xE2B2C size 0x65.
 * Passive19_0101 0xE2B91 size 0x5A.
 * Passive19_0111 0xE2C3A size 0x61.
 * Passive19_0113 0xE2CC8 size 0x47.
 * Passive19_0114 0xE2D0F size 0x49.
 * Passive19_0133 0xE2FA6 size 0x46.
 * Passive19_0137 0xE309E size 0x49.
 * Passive19_0139 0xE30E7 size 0x2F.
 * Passive19_0144 0xE3116 size 0x5C.
 * Passive19_0145 0xE3172 size 0x80.
 * Passive19_0146 0xE31F2 size 0x5B.
 * Passive19_0155 0xE331D size 0x3F.
 * Passive19_0156 0xE335C size 0x54.
 * Passive19_0166 0xE3435 size 0x5F.
 * Passive19_0025 is folded into 0xE1DE4 with 2 other bodies. Unnamed.
 * Passive19_0000 is folded into 0xD0F75 with 14 other bodies. Unnamed.
 * Passive19_0001 is folded into 0xAB943 with 26 other bodies. Unnamed.
 * Passive19_0002 is folded into 0xDB0BC with 3 other bodies. Unnamed.
 * Passive19_0003 is folded into 0xDC466 with 11 other bodies. Unnamed.
 * Passive19_0004 is folded into 0xD4486 with 6 other bodies. Unnamed.
 * Passive19_0005 is folded into 0x7EE7B with 22 other bodies. Unnamed.
 * Passive19_0006 is folded into 0xE1BAF with 5 other bodies. Unnamed.
 * Passive19_0007 is folded into 0xE2326 with 9 other bodies. Unnamed.
 * Passive19_0008 is folded into 0xE22FA with 8 other bodies. Unnamed.
 * Passive19_0009 is folded into 0x8078E with 8 other bodies. Unnamed.
 * Passive19_0010 is folded into 0xE1BF4 with 6 other bodies. Unnamed.
 * Passive19_0011 is folded into 0xDB121 with 3 other bodies. Unnamed.
 * Passive19_0012 is folded into 0x6D0A6 with 21 other bodies. Unnamed.
 * Passive19_0013 is folded into 0xDB15B with 4 other bodies. Unnamed.
 * Passive19_0014 is folded into 0xE1C20 with 9 other bodies. Unnamed.
 * Passive19_0015 is folded into 0x6D0D1 with 17 other bodies. Unnamed.
 * Passive19_0017 is folded into 0x6D16B with 3 other bodies. Unnamed.
 * Passive19_0019 is folded into 0xD46A1 with 1 other bodies. Unnamed.
 * Passive19_0020 is folded into 0x6D236 with 17 other bodies. Unnamed.
 * Passive19_0022 is folded into 0xDC634 with 2 other bodies. Unnamed.
 * Passive19_0023 is folded into 0xE1D7F with 2 other bodies. Unnamed.
 * Passive19_0024 is folded into 0xDC6A6 with 2 other bodies. Unnamed.
 * Passive19_0026 is folded into 0xE1E5B with 3 other bodies. Unnamed.
 * Passive19_0028 is folded into 0xE1EE3 with 3 other bodies. Unnamed.
 * Passive19_0029 is folded into 0xDFCF2 with 10 other bodies. Unnamed.
 * Passive19_0030 is folded into 0xDB301 with 2 other bodies. Unnamed.
 * Passive19_0031 is folded into 0x6E9E1 with 10 other bodies. Unnamed.
 * Passive19_0033 is folded into 0xDC875 with 3 other bodies. Unnamed.
 * Passive19_0037 is folded into 0xDE0BD with 1 other bodies. Unnamed.
 * Passive19_0042 is folded into 0xABA00 with 1 other bodies. Unnamed.
 * Passive19_0046 is folded into 0x706D9 with 9 other bodies. Unnamed.
 * Passive19_0049 is folded into 0xE2287 with 3 other bodies. Unnamed.
 * Passive19_0050 is folded into 0xDCC3E with 3 other bodies. Unnamed.
 * Passive19_0051 is folded into 0xDB66C with 2 other bodies. Unnamed.
 * Passive19_0052 is folded into 0xA9FF7 with 21 other bodies. Unnamed.
 * Passive19_0053 is folded into 0xE2326 with 9 other bodies. Unnamed.
 * Passive19_0054 is folded into 0xE22CC with 1 other bodies. Unnamed.
 * Passive19_0055 is folded into 0xE22FA with 8 other bodies. Unnamed.
 * Passive19_0056 is folded into 0x6D640 with 3 other bodies. Unnamed.
 * Passive19_0057 is folded into 0xDCCB4 with 3 other bodies. Unnamed.
 * Passive19_0058 is folded into 0xD34B4 with 10 other bodies. Unnamed.
 * Passive19_0059 is folded into 0xE2326 with 9 other bodies. Unnamed.
 * Passive19_0060 is folded into 0x7EE7B with 22 other bodies. Unnamed.
 * Passive19_0061 is folded into 0xE2352 with 1 other bodies. Unnamed.
 * Passive19_0062 is folded into 0xE2394 with 2 other bodies. Unnamed.
 * Passive19_0064 is folded into 0x6D0A6 with 21 other bodies. Unnamed.
 * Passive19_0067 is folded into 0xDE4E3 with 5 other bodies. Unnamed.
 * Passive19_0068 is folded into 0xE24F8 with 3 other bodies. Unnamed.
 * Passive19_0070 is folded into 0xDE4E3 with 5 other bodies. Unnamed.
 * Passive19_0071 is folded into 0xDCE5F with 3 other bodies. Unnamed.
 * Passive19_0073 is folded into 0xDE578 with 1 other bodies. Unnamed.
 * Passive19_0076 is folded into 0xE264D with 1 other bodies. Unnamed.
 * Passive19_0077 is folded into 0xE26B3 with 3 other bodies. Unnamed.
 * Passive19_0080 is folded into 0xE27B9 with 2 other bodies. Unnamed.
 * Passive19_0083 is folded into 0xDD13A with 2 other bodies. Unnamed.
 * Passive19_0086 is folded into 0xE2953 with 2 other bodies. Unnamed.
 * Passive19_0087 is folded into 0xE2953 with 2 other bodies. Unnamed.
 * Passive19_0088 is folded into 0xE2953 with 2 other bodies. Unnamed.
 * Passive19_0089 is folded into 0x9FB5D with 8 other bodies. Unnamed.
 * Passive19_0090 is folded into 0x9FB89 with 6 other bodies. Unnamed.
 * Passive19_0091 is folded into 0x9FBB5 with 9 other bodies. Unnamed.
 * Passive19_0093 is folded into 0xE0AC4 with 4 other bodies. Unnamed.
 * Passive19_0094 is folded into 0xA7073 with 8 other bodies. Unnamed.
 * Passive19_0095 is folded into 0xE2A1A with 1 other bodies. Unnamed.
 * Passive19_0097 is folded into 0xDFE9B with 4 other bodies. Unnamed.
 * Passive19_0099 is folded into 0x6DEE5 with 3 other bodies. Unnamed.
 * Passive19_0102 is folded into 0x6E008 with 4 other bodies. Unnamed.
 * Passive19_0103 is folded into 0xA9BB4 with 14 other bodies. Unnamed.
 * Passive19_0104 is folded into 0x9FB5D with 8 other bodies. Unnamed.
 * Passive19_0105 is folded into 0x9FB89 with 6 other bodies. Unnamed.
 * Passive19_0106 is folded into 0x9FBB5 with 9 other bodies. Unnamed.
 * Passive19_0107 is folded into 0xDD545 with 3 other bodies. Unnamed.
 * Passive19_0108 is folded into 0xDBDD0 with 4 other bodies. Unnamed.
 * Passive19_0109 is folded into 0x6E04F with 4 other bodies. Unnamed.
 * Passive19_0110 is folded into 0xE2BEB with 1 other bodies. Unnamed.
 * Passive19_0112 is folded into 0xE2C9B with 1 other bodies. Unnamed.
 * Passive19_0115 is folded into 0xE2D58 with 4 other bodies. Unnamed.
 * Passive19_0116 is folded into 0x6E0D7 with 4 other bodies. Unnamed.
 * Passive19_0117 is folded into 0xDD684 with 4 other bodies. Unnamed.
 * Passive19_0118 is folded into 0xA9FA1 with 15 other bodies. Unnamed.
 * Passive19_0119 is folded into 0xE2D92 with 2 other bodies. Unnamed.
 * Passive19_0120 is folded into 0xDD6B3 with 3 other bodies. Unnamed.
 * Passive19_0121 is folded into 0xE2DFF with 4 other bodies. Unnamed.
 * Passive19_0122 is folded into 0xDBF61 with 4 other bodies. Unnamed.
 * Passive19_0123 is folded into 0xDD6EA with 3 other bodies. Unnamed.
 * Passive19_0124 is folded into 0xDD721 with 4 other bodies. Unnamed.
 * Passive19_0125 is folded into 0xE2E32 with 4 other bodies. Unnamed.
 * Passive19_0126 is folded into 0xE2E66 with 5 other bodies. Unnamed.
 * Passive19_0127 is folded into 0x71E79 with 17 other bodies. Unnamed.
 * Passive19_0128 is folded into 0xE2EA8 with 1 other bodies. Unnamed.
 * Passive19_0129 is folded into 0xE2EEB with 17 other bodies. Unnamed.
 * Passive19_0130 is folded into 0xE2F17 with 13 other bodies. Unnamed.
 * Passive19_0131 is folded into 0xE2F43 with 11 other bodies. Unnamed.
 * Passive19_0132 is folded into 0xE2F6F with 4 other bodies. Unnamed.
 * Passive19_0134 is folded into 0xE2FEC with 2 other bodies. Unnamed.
 * Passive19_0135 is folded into 0xE3018 with 1 other bodies. Unnamed.
 * Passive19_0136 is folded into 0xE305B with 1 other bodies. Unnamed.
 * Passive19_0138 is folded into 0xDC0EC with 1 other bodies. Unnamed.
 * Passive19_0140 is folded into 0x822AE with 19 other bodies. Unnamed.
 * Passive19_0141 is folded into 0xDC12F with 3 other bodies. Unnamed.
 * Passive19_0142 is folded into 0xD2718 with 15 other bodies. Unnamed.
 * Passive19_0143 is folded into 0xDD8E3 with 3 other bodies. Unnamed.
 * Passive19_0147 is folded into 0x6E26C with 1 other bodies. Unnamed.
 * Passive19_0148 is folded into 0xDC346 with 9 other bodies. Unnamed.
 * Passive19_0149 is folded into 0xE324D with 2 other bodies. Unnamed.
 * Passive19_0150 is folded into 0xE3284 with 2 other bodies. Unnamed.
 * Passive19_0151 is folded into 0xDDAB7 with 6 other bodies. Unnamed.
 * Passive19_0152 is folded into 0xDC37B with 4 other bodies. Unnamed.
 * Passive19_0153 is folded into 0xDF176 with 4 other bodies. Unnamed.
 * Passive19_0154 is folded into 0xE32D5 with 4 other bodies. Unnamed.
 * Passive19_0157 is folded into 0xDDB8D with 12 other bodies. Unnamed.
 * Passive19_0158 is folded into 0xDDBBA with 13 other bodies. Unnamed.
 * Passive19_0159 is folded into 0xAA590 with 9 other bodies. Unnamed.
 * Passive19_0160 is folded into 0xDF251 with 5 other bodies. Unnamed.
 * Passive19_0161 is folded into 0xE12D6 with 5 other bodies. Unnamed.
 * Passive19_0162 is folded into 0xA9CD2 with 5 other bodies. Unnamed.
 * Passive19_0163 is folded into 0xE33B0 with 8 other bodies. Unnamed.
 * Passive19_0164 is folded into 0xE33DD with 8 other bodies. Unnamed.
 * Passive19_0165 is folded into 0xE3409 with 7 other bodies. Unnamed.
 * Passive19_0167 is folded into 0xE3494 with 1 other bodies. Unnamed.
 * Passive19_0168 is folded into 0xE34D0 with 1 other bodies. Unnamed.
 * Passive19_0169 is folded into 0xE3515 with 1 other bodies. Unnamed.
 * Passive19_0170 is folded into 0xABDD0 with 1 other bodies. Unnamed.
 * Passive19_0171 is folded into 0xABE16 with 1 other bodies. Unnamed.
 * Passive19_0172 is folded into 0xD2718 with 15 other bodies. Unnamed.
 * Passive19_0173 is folded into 0xD2718 with 15 other bodies. Unnamed.
 * Passive19_0174 is folded into 0xD2718 with 15 other bodies. Unnamed.
 * Passive19_0175 is folded into 0xD2718 with 15 other bodies. Unnamed.
 * Passive19_0048 is folded into 0xD3482 with 2 other bodies. Unnamed.
 */

#include "sf33rd/Source/Game/pass19.h"
#include "common.h"
#include "sf33rd/Source/Game/Com_Sub.h"
#include "sf33rd/Source/Game/workuser.h"

void (*const Passive19_Tbl[176])();

void Passive19(PLW* wk) {
    Passive19_Tbl[(s16)Pattern_Index[wk->wu.id]](wk);
}

void Passive19_0000(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xD, M_Lv[wk->wu.id]);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0001(PLW* wk) {
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

void Passive19_0002(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 3, -1);
        break;

    case 1:
        Pierce_On(wk);
        break;

    case 2:
        Command_Attack(wk, 8, 0, 0xB, -1);
        break;

    case 3:
        EM_Term(wk, 0x7FFF, -1, 1, 1, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0003(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        VS_Jump_Guard(wk);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0004(PLW* wk) {
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

void Passive19_0005(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Forced_Guard(wk, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0006(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x7F, 2);
        break;

    case 1:
        EM_Term(wk, 0x7FFF, -1, 1, 1, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0007(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1D, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0008(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1D, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0009(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1D, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0010(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Short_Range_Attack(wk, 8, 0x40, 6, 0x1D);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0011(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, -0x7FB0, 0xB, 0x20, 2, -0x7FA0, -1, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0012(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0013(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x60, 6, 0x6C);
        break;

    case 1:
        Command_Attack(wk, 8, 1, 0xB, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0014(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1C, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0015(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0016(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x60, 6, 0x6C);
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
        Branch_Unit_Area(wk, 6, 0x68, 0x69, 0x6A, 0x6A);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0017(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x102);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x102);
        break;

    case 3:
        Normal_Attack(wk, 8, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0018(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x60, 6, 0x6C);
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
        Normal_Attack(wk, 8, 0x12);
        break;

    case 5:
        Branch_Unit_Area(wk, 6, 0x68, 0x69, 0x6A, 0x6A);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0019(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, 1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0020(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 3, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0021(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1D, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0022(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;

    case 1:
        Jump_Attack_Term(wk, -0x7F80, -0x7FB0, 0xB, 0x100, 0, -0x7FA0, -1, 0x200);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x10);
        break;

    case 3:
        Normal_Attack(wk, 8, 0x10);
        break;

    case 4:
        Normal_Attack(wk, 8, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0023(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7F60, -0x7FB0, 0xB, 0x20, 0, -0x7FA0, -1, 0x200);
        break;

    case 1:
        Wait_Get_Up(wk, 0, -1);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0024(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x60, 6, 0x6C);
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
        Normal_Attack(wk, 8, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0025(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x60, 6, 0x6C);
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
        Normal_Attack(wk, 8, 0x10);
        break;

    case 5:
        Normal_Attack(wk, 8, 0x10);
        break;

    case 6:
        Normal_Attack(wk, 8, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0026(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, -0x7FB0, 6, 1, -1);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x42);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0027(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1D, 8, -1);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x402);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0028(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack(wk, 8, 10, 0x400, 1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0029(PLW* wk) {
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

void Passive19_0030(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F80, -0x7FB8, 6, 1, -1);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0031(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 1, 0x20, 1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0032(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x2E, 0x2F, 0x30, 0);
        break;

    case 1:
        Com_Random_Select(wk, 6, 0x9D, 0x9E, 0x9F, 0x9F, 1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0033(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 6, 0x9D, 0x9E, 0x9F, 0x9F, 1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0034(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xC, 0x12);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1C, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0035(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x12);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x102);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0036(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 0xB, 0x1D, 8, -1);
        break;

    case 1:
        Com_Random_Select(wk, 6, 0x42, 0x46, 0x4A, 0x4A, 1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0037(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, -0x7FF8, 6, 1, -1);
        break;

    case 1:
        Com_Random_Select(wk, 6, 0x9D, 0x9E, 0x9F, 0x9F, 1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0038(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, -0x7FE8, 6, 1, -1);
        break;

    case 1:
        Branch_Unit_Area(wk, 2, 0x4B, 0x4B, 0x4B, 0x4B);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0039(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, -0x7FE8, 6, 1, -1);
        break;

    case 1:
        Branch_Unit_Area(wk, 2, 0x4D, 0x4D, 0x4D, 0x4D);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0040(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, -0x7FE8, 6, 1, -1);
        break;

    case 1:
        Branch_Unit_Area(wk, 2, 0x4E, 0x4E, 0x4E, 0x4E);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0041(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Away(wk, 0x7F, 3);
        break;

    case 1:
        EM_Term(wk, -0x7F80, -0x7FC0, 6, 1, -1);
        break;

    case 2:
        Normal_Attack(wk, 0xB, 0x40);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0042(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack(wk, 8, 0xC, 0x400, 2);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0043(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F80, -0x7F80, 6, 1, -1);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1E, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0044(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x4B, 2);
        break;

    case 1:
        EM_Term(wk, -1, -0x7F80, 6, 1, -1);
        break;

    case 2:
        J_Command_Attack(wk, 8, 0x1C, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0045(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F80, -0x7FD8, 6, 1, -1);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x40);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0046(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Status(wk, 2, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0047(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xB, 0x102);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1D, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0048(PLW* wk) {
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

void Passive19_0049(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F80, -1, 6, 1, -1);
        break;

    case 1:
        Adjust_Attack(wk, 8, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0050(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F80, -1, 6, 1, -1);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0051(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x220);
        break;

    case 1:
        Normal_Attack(wk, 0xB, 0x102);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0052(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x202);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0053(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1D, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0054(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Branch_Unit_Area(wk, 6, 0x68, 0x69, 0x69, 0x6A);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0055(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1D, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0056(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7F60, -0x7FA0, 8, 0x200, 0, -0x7FA0, -1, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0057(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7F60, -0x7FA0, 8, 0x20, 0, -0x7FA0, -1, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0058(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Status(wk, 2, 1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0059(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1D, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0060(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Forced_Guard(wk, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0061(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x2E, 0x2F, 0x30, 0);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1F, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0062(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;

    case 1:
        ETC_Term(wk, 0, 2, 0xD);
        break;

    case 2:
        Com_Random_Select(wk, 6, 0x9D, 0x9E, 0x9F, 0x9F, 1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0063(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ETC_Term(wk, 0, 6, 0x21);
        break;

    case 1:
        Normal_Attack(wk, 0xB, 0x10);
        break;

    case 2:
        Com_Random_Select(wk, 6, 0x9D, 0x9E, 0x9F, 0x9F, 1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0064(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0065(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1D, 10, -1);
        break;

    case 2:
        Com_Random_Select(wk, 6, 0x42, 0x46, 0x4A, 0x4A, 1);
        break;

    case 3:
        Command_Attack(wk, 8, 0x1E, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0066(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x4B, 2);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1C, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0067(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x7F, 2);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x402);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0068(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7F60, -0x7FA0, 8, 0x200, 0, -0x7FA0, -1, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0069(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack(wk, 0xC, 0xC, 0x400, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0070(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x7F, 2);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x402);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0071(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;

    case 1:
        Com_Random_Select(wk, 6, 0x9D, 0x9E, 0x9F, 0x9F, 1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0072(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;

    case 1:
        Command_Attack(wk, 0xC, 0, 0xB, -1);
        break;

    case 2:
        J_Command_Attack(wk, 8, 0x1C, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0073(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBF, 2);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x12);
        break;

    case 2:
        Branch_Unit_Area(wk, 6, 0x68, 0x69, 0x69, 0x6A);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0074(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x2E, 0x2F, 0xFFFF, 0);
        break;

    case 1:
        Com_Random_Select(wk, 6, 0x9D, 0x9E, 0x9F, 0x9F, 1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0075(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x2E, 0x2F, 0xFFFF, 0);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1F, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0076(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x2E, 0xFFFF, 0xFFFF, 0);
        break;

    case 1:
        Approach_Walk(wk, 0x93, 2);
        break;

    case 2:
        SA_Term(wk, 0x2E, 0x2F, 0xFFFF, 0);
        break;

    case 3:
        Command_Attack(wk, 8, 0x1F, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0077(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7F60, -0x7FA0, 0xB, 0x40, 0, -0x7FA0, -1, 0x200);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0078(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7F60, -0x7FB0, 0xB, 0x10, 0, -0x7FA0, -1, 0x20);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x10);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0079(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7F60, -0x7FB0, 0xB, 0x400, 0, -0x7FA0, -1, 0x20);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0080(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, -0x7F60, -0x7FA0, 0xB, 0x200, 0, -0x7FA0, -1, 0x400);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0081(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, -0x7F60, -0x7FA0, 0xB, 0x10, 0, -0x7FA0, -1, 0x400);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x10);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0082(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, -0x7F60, -0x7FA0, 0xB, 0x400, 0, -0x7FA0, -1, 0x20);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0083(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, -1, -0x7FA0, 0xB, 0x200, 0, -0x7FA0, -1, 0x20);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x100);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x100);
        break;

    case 3:
        Normal_Attack(wk, 8, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0084(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack(wk, 0xC, 0xC, 0x402, 0);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x102);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x102);
        break;

    case 3:
        Normal_Attack(wk, 8, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0085(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 2);
        break;

    case 1:
        Com_Random_Select(wk, 6, 5, 5, 7, 8, 1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0086(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, -0x7FD8, 6, 1, -1);
        break;

    case 1:
        SA_Term(wk, 0xFFFF, 0x2F, 0xFFFF, 0);
        break;

    case 2:
        EM_Term(wk, -1, -0x7FF8, 6, 1, -1);
        break;

    case 3:
        SA_Term(wk, 0x2E, 0xFFFF, 0xFFFF, 0);
        break;

    case 4:
        Command_Attack(wk, 8, 0x1F, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0087(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, -0x7FD8, 6, 1, -1);
        break;

    case 1:
        SA_Term(wk, 0xFFFF, 0x2F, 0xFFFF, 0);
        break;

    case 2:
        EM_Term(wk, -1, -0x7FF8, 6, 1, -1);
        break;

    case 3:
        SA_Term(wk, 0x2E, 0xFFFF, 0xFFFF, 0);
        break;

    case 4:
        Command_Attack(wk, 8, 0x1F, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0088(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, -0x7FD8, 6, 1, -1);
        break;

    case 1:
        SA_Term(wk, 0xFFFF, 0x2F, 0xFFFF, 0);
        break;

    case 2:
        EM_Term(wk, -1, -0x7FF8, 6, 1, -1);
        break;

    case 3:
        SA_Term(wk, 0x2E, 0xFFFF, 0xFFFF, 0);
        break;

    case 4:
        Command_Attack(wk, 8, 0x1F, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0089(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1F, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0090(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1F, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0091(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1F, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0092(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, -0x7FA0, 6, 1, -1);
        break;

    case 1:
        Branch_Unit_Area(wk, 6, 0x59, 0x5A, 0x5B, 0x5B);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0093(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x102);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x12);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0094(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0095(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x12);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x12);
        break;

    case 2:
        Branch_Unit_Area(wk, 6, 0x68, 0x69, 0x6A, 1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0096(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Away(wk, 0x7F, 3);
        break;

    case 1:
        EM_Term(wk, -0x7F80, -0x7FD8, 6, 1, -1);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x402);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0097(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;

    case 1:
        EM_Term(wk, -1, -0x7FF8, 6, 1, -1);
        break;

    case 2:
        Com_Random_Select(wk, 6, 0x9D, 0x9E, 0x9F, 0x9F, 1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0098(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;

    case 1:
        EM_Term(wk, -1, -0x7FC0, 6, 1, -1);
        break;

    case 2:
        Command_Attack(wk, 8, 0x1D, 10, -1);
        break;

    case 3:
        Com_Random_Select(wk, 6, 0x42, 0x46, 0x4A, 0x4A, 1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0099(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, -1, -0x7FA0, 0xB, 0x200, 0, -0x7FA0, -1, 0x200);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x100);
        break;

    case 2:
        Lever_Attack(wk, 8, 0, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0100(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x4B, 2);
        break;

    case 1:
        Wait_Get_Up(wk, 3, -1);
        break;

    case 2:
        SA_Term(wk, 0x2E, 0x2F, 0xFFFF, 0);
        break;

    case 3:
        Command_Attack(wk, 8, 0x1F, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0101(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x100);
        break;

    case 1:
        SA_Term(wk, 0x2E, 0x2F, 0x30, 0);
        break;

    case 2:
        Branch_Unit_Area(wk, 6, 0x68, 0x69, 0x6A, 0x6A);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0102(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F80, -1, 6, 1, -1);
        break;

    case 1:
        Lever_Attack(wk, 8, 0, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0103(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x42);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0104(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1F, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0105(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1F, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0106(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1F, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0107(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x60, 6, 0x6C);
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

void Passive19_0108(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump(wk, 1, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0109(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x60, 6, 0x6C);
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

void Passive19_0110(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x60, 6, 0x6C);
        break;

    case 1:
        Walk(wk, 1, 0x38, 0);
        break;

    case 2:
        Wait_Get_Up(wk, 3, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0111(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, -0x7FB0, 6, 1, -1);
        break;

    case 1:
        Normal_Attack(wk, 0xC, 0x400);
        break;

    case 2:
        Com_Random_Select(wk, 6, 0x4B, 0x36, 0x3B, 0x70, 1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0112(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 1, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0113(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xC, 0x400);
        break;

    case 1:
        Com_Random_Select(wk, 6, 0x4B, 0x36, 0x3B, 0x70, 1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0114(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, -0x7FB0, 6, 1, -1);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1D, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0115(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, -1, -0x7FA0, 0xB, 0x200, 0, -0x7FA0, -1, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0116(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, -0x7FA0, 0xB, 0x400, 0, -0x7FA0, -1, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0117(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack(wk, 8, 0xC, 0x100, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0118(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0119(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_On(wk, 1, 2);
        break;

    case 1:
        EM_Term(wk, -1, -0x7FD0, 6, 1, -1);
        break;

    case 2:
        Check_Store_Lever(wk, 0x1F, 1, -1);
        break;

    case 3:
        Branch_Unit_Area(wk, 6, 0x69, 0x6A, 1, 1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0120(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x20, 8, 0x400, 1, -1, 0x20, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0121(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x20, 8, 0x20, 1, -1, 0x20, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0122(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x20, 8, 0x40, 1, -1, 0x20, 0x40);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0123(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x20, 8, 0x400, 2, -1, 0x20, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0124(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x20, 8, 0x20, 2, -1, 0x20, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0125(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x20, 8, 0x40, 2, -1, 0x20, 0x40);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0126(PLW* wk) {
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

void Passive19_0127(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x40);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0128(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Check_EX(wk, 6, 0x36);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1F, 9, 0x700);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0129(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0130(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0131(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0132(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Branch_Unit_Area(wk, 6, 0x81, 0x82, 0x82, 0x83);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0133(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Check_EX(wk, 6, 0x84);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1E, 10, 0x700);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0134(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1D, 10, 0x70);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0135(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Check_EX(wk, 6, 1);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1F, 10, 0x700);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0136(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Check_EX(wk, 6, 0x36);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1F, 10, 0x700);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0137(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, -0x7F80, 6, 1, -1);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1E, 10, 0x70);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0138(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Check_EX(wk, 6, 0x22);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1F, 10, 0x700);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0139(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack(wk, 0xC, 0xD, 0x400, 2);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0140(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0141(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, -0x7FB0, 6, 1, -1);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x40);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0142(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Provoke(wk, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0143(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Provoke(wk, 1);
        break;

    case 1:
        Com_Random_Select(wk, 6, 0x85, 0x86, 0x7F, 0x70, 1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0144(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Provoke(wk, 1);
        break;

    case 1:
        SA_Term(wk, 0x2E, 0x2F, 0x30, 0);
        break;

    case 2:
        Com_Random_Select(wk, 6, 0x85, 0x86, 0x7F, 0x70, 1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0145(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Provoke(wk, 1);
        break;

    case 1:
        SA_Term(wk, 0x2E, 0xFFFF, 0xFFFF, 0);
        break;

    case 2:
        Approach_Walk(wk, 0x93, 2);
        break;

    case 3:
        SA_Term(wk, 0x2E, 0x2F, 0xFFFF, 0);
        break;

    case 4:
        Com_Random_Select(wk, 6, 0x85, 0x86, 0x7F, 0x70, 1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0146(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Provoke(wk, 1);
        break;

    case 1:
        Pierce_On(wk);
        break;

    case 2:
        Command_Attack(wk, 0xC, 0, 0xB, -1);
        break;

    case 3:
        J_Command_Attack(wk, 8, 0x1C, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0147(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Check_EX(wk, 6, 0x85);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1F, 10, 0x700);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0148(PLW* wk) {
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

void Passive19_0149(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7F70, -1, 8, 0x20, 1, -1, 0x20, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0150(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7F70, -0x7FB0, 8, 0x20, 2, -1, -0x7FB0, 0x20);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0151(PLW* wk) {
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

void Passive19_0152(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F70, -1, 6, 1, -1);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x102);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x102);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0153(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F70, -1, 6, 1, -1);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x402);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0154(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F70, -1, 6, 1, -1);
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

void Passive19_0155(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 3);
        break;

    case 1:
        Branch_Unit_Area(wk, 6, 0x59, 0x59, 0x5A, 0x5B);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0156(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Check_EX(wk, 6, 0x9B);
        break;

    case 1:
        Wait(wk, 3);
        break;

    case 2:
        J_Command_Attack(wk, 8, 0x1F, 9, 0x700);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0157(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x110);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0158(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 1, 0x110);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0159(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x110);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0160(PLW* wk) {
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

void Passive19_0161(PLW* wk) {
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

void Passive19_0162(PLW* wk) {
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

void Passive19_0163(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0164(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1C, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0165(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1C, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0166(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F80, -1, 6, 1, -1);
        break;

    case 1:
        SA_Term(wk, 0xFFFF, 0x2F, 0xFFFF, 0);
        break;

    case 2:
        Command_Attack(wk, 8, 0x1D, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0167(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 0xC, 0x1D, 8, -1);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1C, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0168(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;

    case 2:
        Command_Attack(wk, 8, 0x1C, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0169(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1D, 10, -1);
        break;

    case 2:
        Command_Attack(wk, 8, 0x1F, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0170(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x102);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x102);
        break;

    case 2:
        Command_Attack(wk, 8, 0x1C, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0171(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, -0x7FA0, 8, 0x402, 0, -0x7FA0, -1, 0x200);
        break;

    case 1:
        Normal_Attack(wk, 0xC, 0x102);
        break;

    case 2:
        Normal_Attack(wk, 0xC, 0x102);
        break;

    case 3:
        Command_Attack(wk, 8, 0x1C, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0172(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Provoke(wk, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0173(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Provoke(wk, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0174(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Provoke(wk, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive19_0175(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Provoke(wk, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void (*const Passive19_Tbl[176])(PLW*) = {
    Passive19_0000, Passive19_0001, Passive19_0002, Passive19_0003, Passive19_0004, Passive19_0005, Passive19_0006,
    Passive19_0007, Passive19_0008, Passive19_0009, Passive19_0010, Passive19_0011, Passive19_0012, Passive19_0013,
    Passive19_0014, Passive19_0015, Passive19_0016, Passive19_0017, Passive19_0018, Passive19_0019, Passive19_0020,
    Passive19_0021, Passive19_0022, Passive19_0023, Passive19_0024, Passive19_0025, Passive19_0026, Passive19_0027,
    Passive19_0028, Passive19_0029, Passive19_0030, Passive19_0031, Passive19_0032, Passive19_0033, Passive19_0034,
    Passive19_0035, Passive19_0036, Passive19_0037, Passive19_0038, Passive19_0039, Passive19_0040, Passive19_0041,
    Passive19_0042, Passive19_0043, Passive19_0044, Passive19_0045, Passive19_0046, Passive19_0047, Passive19_0048,
    Passive19_0049, Passive19_0050, Passive19_0051, Passive19_0052, Passive19_0053, Passive19_0054, Passive19_0055,
    Passive19_0056, Passive19_0057, Passive19_0058, Passive19_0059, Passive19_0060, Passive19_0061, Passive19_0062,
    Passive19_0063, Passive19_0064, Passive19_0065, Passive19_0066, Passive19_0067, Passive19_0068, Passive19_0069,
    Passive19_0070, Passive19_0071, Passive19_0072, Passive19_0073, Passive19_0074, Passive19_0075, Passive19_0076,
    Passive19_0077, Passive19_0078, Passive19_0079, Passive19_0080, Passive19_0081, Passive19_0082, Passive19_0083,
    Passive19_0084, Passive19_0085, Passive19_0086, Passive19_0087, Passive19_0088, Passive19_0089, Passive19_0090,
    Passive19_0091, Passive19_0092, Passive19_0093, Passive19_0094, Passive19_0095, Passive19_0096, Passive19_0097,
    Passive19_0098, Passive19_0099, Passive19_0100, Passive19_0101, Passive19_0102, Passive19_0103, Passive19_0104,
    Passive19_0105, Passive19_0106, Passive19_0107, Passive19_0108, Passive19_0109, Passive19_0110, Passive19_0111,
    Passive19_0112, Passive19_0113, Passive19_0114, Passive19_0115, Passive19_0116, Passive19_0117, Passive19_0118,
    Passive19_0119, Passive19_0120, Passive19_0121, Passive19_0122, Passive19_0123, Passive19_0124, Passive19_0125,
    Passive19_0126, Passive19_0127, Passive19_0128, Passive19_0129, Passive19_0130, Passive19_0131, Passive19_0132,
    Passive19_0133, Passive19_0134, Passive19_0135, Passive19_0136, Passive19_0137, Passive19_0138, Passive19_0139,
    Passive19_0140, Passive19_0141, Passive19_0142, Passive19_0143, Passive19_0144, Passive19_0145, Passive19_0146,
    Passive19_0147, Passive19_0148, Passive19_0149, Passive19_0150, Passive19_0151, Passive19_0152, Passive19_0153,
    Passive19_0154, Passive19_0155, Passive19_0156, Passive19_0157, Passive19_0158, Passive19_0159, Passive19_0160,
    Passive19_0161, Passive19_0162, Passive19_0163, Passive19_0164, Passive19_0165, Passive19_0166, Passive19_0167,
    Passive19_0168, Passive19_0169, Passive19_0170, Passive19_0171, Passive19_0172, Passive19_0173, Passive19_0174,
    Passive19_0175
};
