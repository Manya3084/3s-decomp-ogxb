/* PASS08.c, retail sf33rd.xbe.
 * PlayStation 2 C, not hand-adjusted for Xbox. Each named body was located
 * from the PS2 retail map: call graph, source order, and agreement of
 * constants, field offsets, callees, and size. See docs/decompiling.md.
 * The #include lines name headers in the PS2 tree (ps2.path).
 * Passive08_0002 0x799EB size 0x5B.
 * Passive08_0004 0x79A8F size 0x5F.
 * Passive08_0005 0x79AEE size 0x3B.
 * Passive08_0009 0x79B84 size 0x49.
 * Passive08_0010 0x79BCD size 0x6C.
 * Passive08_0012 0x79C39 size 0x41.
 * Passive08_0013 0x79C7A size 0x3A.
 * Passive08_0014 0x79CB4 size 0x49.
 * Passive08_0015 0x79CFD size 0x46.
 * Passive08_0016 0x79D43 size 0x3D.
 * Passive08_0020 0x79DC8 size 0x41.
 * Passive08_0021 0x79E09 size 0x41.
 * Passive08_0023 0x79E4A size 0x43.
 * Passive08_0024 0x79E8D size 0x40.
 * Passive08_0025 0x79ECD size 0x40.
 * Passive08_0029 0x79F0D size 0x45.
 * Passive08_0030 0x79F52 size 0x52.
 * Passive08_0031 0x79FA4 size 0x59.
 * Passive08_0032 0x79FFD size 0x4B.
 * Passive08_0033 0x7A048 size 0x3E.
 * Passive08_0034 0x7A086 size 0x56.
 * Passive08_0039 0x7A108 size 0x49.
 * Passive08_0041 0x7A151 size 0x5F.
 * Passive08_0043 0x7A1B0 size 0x40.
 * Passive08_0044 0x7A1F0 size 0x40.
 * Passive08_0049 0x7A230 size 0x31.
 * Passive08_0050 0x7A261 size 0x40.
 * Passive08_0051 0x7A2A1 size 0x4D.
 * Passive08_0056 0x7A397 size 0x6D.
 * Passive08_0057 0x7A404 size 0x65.
 * Passive08_0060 0x7A469 size 0x40.
 * Passive08_0061 0x7A4A9 size 0x48.
 * Passive08_0063 0x7A4F1 size 0x4C.
 * Passive08_0066 0x7A5A7 size 0x9A.
 * Passive08_0068 0x7A641 size 0x48.
 * Passive08_0072 0x7A6BD size 0x4A.
 * Passive08_0076 0x7A764 size 0x3D.
 * Passive08_0078 0x7A7A1 size 0x51.
 * Passive08_0080 0x7A7F2 size 0x6C.
 * Passive08_0081 0x7A85E size 0x6A.
 * Passive08_0082 is folded into 0x7A8C8 with 1 other bodies. Unnamed.
 * Passive08_0090 0x7A961 size 0x68.
 * Passive08_0091 0x7A9C9 size 0x67.
 * Passive08_0092 0x7AA30 size 0x73.
 * Passive08_0094 0x7AB01 size 0x4F.
 * Passive08_0096 0x7AB50 size 0x46.
 * Passive08_0097 0x7AB96 size 0x45.
 * Passive08_0101 0x7ABDB size 0x59.
 * Passive08_0102 0x7AC34 size 0x6A.
 * Passive08_0104 0x7AC9E size 0x43.
 * Passive08_0105 0x7ACE1 size 0x70.
 * Passive08_0106 0x7AD51 size 0x40.
 * Passive08_0107 0x7AD91 size 0x49.
 * Passive08_0108 0x7ADDA size 0x49.
 * Passive08_0110 0x7AE6C size 0x65.
 * Passive08_0111 0x7AED1 size 0x62.
 * Passive08_0115 0x7AF33 size 0x7E.
 * Passive08_0117 0x7AFB1 size 0x43.
 * Passive08_0118 0x7AFF4 size 0x43.
 * Passive08_0120 0x7B07A size 0x46.
 * Passive08_0124 0x7B0C0 size 0x4F.
 * Passive08_0125 0x7B10F size 0x52.
 * Passive08_0126 0x7B161 size 0x5E.
 * Passive08_0127 0x7B1BF size 0x80.
 * Passive08_0128 0x7B23F size 0x7B.
 * Passive08_0129 0x7B2BA size 0x89.
 * Passive08_0130 0x7B343 size 0x81.
 * Passive08_0131 0x7B3C4 size 0x45.
 * Passive08_0133 0x7B409 size 0x81.
 * Passive08_0134 0x7B48A size 0x75.
 * Passive08_0136 0x7B548 size 0x57.
 * Passive08_0137 0x7B59F size 0x4F.
 * Passive08_0138 0x7B5EE size 0x4F.
 * Passive08_0139 0x7B63D size 0x64.
 * Passive08_0140 0x7B6A1 size 0x61.
 * Passive08_0141 0x7B702 size 0x77.
 * Passive08_0142 0x7B779 size 0x98.
 * Passive08_0143 0x7B811 size 0x92.
 * Passive08_0144 0x7B8A3 size 0x7C.
 * Passive08_0145 0x7B91F size 0x80.
 * Passive08_0147 0x7B99F size 0x3A.
 * Passive08_0148 0x7B9D9 size 0x32.
 * Passive08_0149 0x7BA0B size 0x38.
 * Passive08_0150 0x7BA43 size 0x53.
 * Passive08_0151 0x7BA96 size 0x7B.
 * Passive08_0152 0x7BB11 size 0x5F.
 * Passive08_0153 0x7BB70 size 0x52.
 * Passive08_0156 0x7BBC2 size 0x51.
 * Passive08_0157 0x7BC13 size 0xA2.
 * Passive08_0158 0x7BCB5 size 0x91.
 * Passive08_0159 0x7BD46 size 0xB1.
 * Passive08_0161 0x7BDF7 size 0x6A.
 * Passive08_0162 0x7BE61 size 0x6A.
 * Passive08_0164 0x7BF50 size 0x6E.
 * Passive08_0166 0x7BFBE size 0x64.
 * Passive08_0167 0x7C022 size 0x7A.
 * Passive08_0173 0x7C0D8 size 0x2F.
 * Passive08_0174 0x7C107 size 0x8A.
 * Passive08_0178 0x7C1FB size 0x7B.
 * Passive08_0180 0x7C276 size 0x59.
 * Passive08_0181 0x7C2CF size 0x59.
 * Passive08_0182 0x7C328 size 0x28.
 * Passive08_0184 0x7C350 size 0x9A.
 * Passive08_0186 0x7C3EA size 0x60.
 * Passive08_0187 0x7C44A size 0x60.
 * Passive08_0188 0x7C4AA size 0x60.
 * Passive08_0197 0x7C634 size 0x45.
 * Passive08_0200 0x7C679 size 0x71.
 * Passive08_0201 0x7C6EA size 0x61.
 * Passive08_0202 0x7C74B size 0x53.
 * Passive08_0203 0x7C79E size 0x3D.
 * Passive08_0204 0x7C7DB size 0x3D.
 * Passive08_0207 0x7C818 size 0x55.
 * Passive08_0208 0x7C86D size 0x5F.
 * Passive08_0209 0x7C8CC size 0x52.
 * Passive08_0210 0x7C91E size 0x51.
 * Passive08_0000 is folded into 0xD0F75 with 14 other bodies. Unnamed.
 * Passive08_0001 is folded into 0xAB943 with 26 other bodies. Unnamed.
 * Passive08_0003 is folded into 0x79A46 with 1 other bodies. Unnamed.
 * Passive08_0006 is folded into 0x79B29 with 1 other bodies. Unnamed.
 * Passive08_0007 is folded into 0x79B29 with 1 other bodies. Unnamed.
 * Passive08_0008 is folded into 0x76C4C with 1 other bodies. Unnamed.
 * Passive08_0011 is folded into 0x822AE with 19 other bodies. Unnamed.
 * Passive08_0017 is folded into 0x74094 with 1 other bodies. Unnamed.
 * Passive08_0018 is folded into 0x79D80 with 1 other bodies. Unnamed.
 * Passive08_0019 is folded into 0x76DCC with 1 other bodies. Unnamed.
 * Passive08_0026 is folded into 0x82920 with 3 other bodies. Unnamed.
 * Passive08_0027 is folded into 0x8294C with 2 other bodies. Unnamed.
 * Passive08_0028 is folded into 0x82978 with 9 other bodies. Unnamed.
 * Passive08_0035 is folded into 0x7A0DC with 7 other bodies. Unnamed.
 * Passive08_0036 is folded into 0x80F0F with 4 other bodies. Unnamed.
 * Passive08_0037 is folded into 0x8107D with 4 other bodies. Unnamed.
 * Passive08_0038 is folded into 0x7ED44 with 1 other bodies. Unnamed.
 * Passive08_0040 is folded into 0x7EDD6 with 1 other bodies. Unnamed.
 * Passive08_0042 is folded into 0x7EE7B with 22 other bodies. Unnamed.
 * Passive08_0045 is folded into 0xE1C20 with 9 other bodies. Unnamed.
 * Passive08_0046 is folded into 0xE33DD with 8 other bodies. Unnamed.
 * Passive08_0047 is folded into 0xE3409 with 7 other bodies. Unnamed.
 * Passive08_0048 is folded into 0xA5181 with 4 other bodies. Unnamed.
 * Passive08_0052 is folded into 0xA54B9 with 1 other bodies. Unnamed.
 * Passive08_0053 is folded into 0x7A2EE with 1 other bodies. Unnamed.
 * Passive08_0054 is folded into 0x7F129 with 2 other bodies. Unnamed.
 * Passive08_0058 is folded into 0xD2718 with 15 other bodies. Unnamed.
 * Passive08_0059 is folded into 0x7F25E with 1 other bodies. Unnamed.
 * Passive08_0062 is folded into 0x75A9D with 3 other bodies. Unnamed.
 * Passive08_0064 is folded into 0xD130E with 4 other bodies. Unnamed.
 * Passive08_0065 is folded into 0x7A53D with 1 other bodies. Unnamed.
 * Passive08_0067 is folded into 0x7771D with 1 other bodies. Unnamed.
 * Passive08_0069 is folded into 0x6D0D1 with 17 other bodies. Unnamed.
 * Passive08_0070 is folded into 0x7778B with 1 other bodies. Unnamed.
 * Passive08_0071 is folded into 0x7A689 with 2 other bodies. Unnamed.
 * Passive08_0073 is folded into 0x6D236 with 17 other bodies. Unnamed.
 * Passive08_0074 is folded into 0x82E9B with 2 other bodies. Unnamed.
 * Passive08_0075 is folded into 0x7A707 with 1 other bodies. Unnamed.
 * Passive08_0077 is folded into 0x6D0A6 with 21 other bodies. Unnamed.
 * Passive08_0079 is folded into 0x82F7D with 2 other bodies. Unnamed.
 * Passive08_0083 is folded into 0x6E340 with 5 other bodies. Unnamed.
 * Passive08_0084 is folded into 0xE33B0 with 8 other bodies. Unnamed.
 * Passive08_0085 is folded into 0x9E572 with 6 other bodies. Unnamed.
 * Passive08_0086 is folded into 0xAA09A with 6 other bodies. Unnamed.
 * Passive08_0087 is folded into 0x8303D with 4 other bodies. Unnamed.
 * Passive08_0088 is folded into 0xDAC4C with 14 other bodies. Unnamed.
 * Passive08_0089 is folded into 0x77980 with 1 other bodies. Unnamed.
 * Passive08_0093 is folded into 0x7AAA3 with 2 other bodies. Unnamed.
 * Passive08_0095 is folded into 0x77B61 with 1 other bodies. Unnamed.
 * Passive08_0098 is folded into 0x71E79 with 17 other bodies. Unnamed.
 * Passive08_0099 is folded into 0xA9FF7 with 21 other bodies. Unnamed.
 * Passive08_0100 is folded into 0xA9FCC with 23 other bodies. Unnamed.
 * Passive08_0103 is folded into 0x77D35 with 1 other bodies. Unnamed.
 * Passive08_0109 is folded into 0x7AE23 with 1 other bodies. Unnamed.
 * Passive08_0112 is folded into 0xA2BE6 with 3 other bodies. Unnamed.
 * Passive08_0113 is folded into 0xA9FA1 with 15 other bodies. Unnamed.
 * Passive08_0114 is folded into 0x77FD4 with 2 other bodies. Unnamed.
 * Passive08_0116 is folded into 0x8373A with 5 other bodies. Unnamed.
 * Passive08_0121 is folded into 0x78169 with 2 other bodies. Unnamed.
 * Passive08_0122 is folded into 0x9F60F with 4 other bodies. Unnamed.
 * Passive08_0123 is folded into 0x83897 with 2 other bodies. Unnamed.
 * Passive08_0132 is folded into 0x80231 with 1 other bodies. Unnamed.
 * Passive08_0135 is folded into 0x7B4FF with 1 other bodies. Unnamed.
 * Passive08_0146 is folded into 0x80741 with 3 other bodies. Unnamed.
 * Passive08_0154 is folded into 0x7C09C with 2 other bodies. Unnamed.
 * Passive08_0155 is folded into 0x843D9 with 6 other bodies. Unnamed.
 * Passive08_0160 is folded into 0x78EB5 with 1 other bodies. Unnamed.
 * Passive08_0163 is folded into 0x7BECB with 1 other bodies. Unnamed.
 * Passive08_0165 is folded into 0x79069 with 1 other bodies. Unnamed.
 * Passive08_0168 is folded into 0x80B9B with 2 other bodies. Unnamed.
 * Passive08_0169 is folded into 0xDE286 with 8 other bodies. Unnamed.
 * Passive08_0170 is folded into 0x843D9 with 6 other bodies. Unnamed.
 * Passive08_0171 is folded into 0x7C09C with 2 other bodies. Unnamed.
 * Passive08_0172 is folded into 0x843D9 with 6 other bodies. Unnamed.
 * Passive08_0175 is folded into 0xA576B with 2 other bodies. Unnamed.
 * Passive08_0176 is folded into 0x7C191 with 1 other bodies. Unnamed.
 * Passive08_0177 is folded into 0x792CE with 1 other bodies. Unnamed.
 * Passive08_0179 is folded into 0x84AD3 with 2 other bodies. Unnamed.
 * Passive08_0185 is folded into 0xD47E2 with 16 other bodies. Unnamed.
 * Passive08_0189 is folded into 0x7C50A with 1 other bodies. Unnamed.
 * Passive08_0190 is folded into 0x7C553 with 1 other bodies. Unnamed.
 * Passive08_0191 is folded into 0x84D57 with 2 other bodies. Unnamed.
 * Passive08_0192 is folded into 0x810A9 with 1 other bodies. Unnamed.
 * Passive08_0193 is folded into 0x7C59C with 2 other bodies. Unnamed.
 * Passive08_0194 is folded into 0x84D9B with 2 other bodies. Unnamed.
 * Passive08_0195 is folded into 0x795CE with 2 other bodies. Unnamed.
 * Passive08_0196 is folded into 0x7C5EB with 1 other bodies. Unnamed.
 * Passive08_0198 is folded into 0x796A9 with 1 other bodies. Unnamed.
 * Passive08_0199 is folded into 0x81182 with 2 other bodies. Unnamed.
 * Passive08_0205 is folded into 0xDC346 with 9 other bodies. Unnamed.
 * Passive08_0206 is folded into 0x797D9 with 1 other bodies. Unnamed.
 * Passive08_0211 is folded into 0xA9FCC with 23 other bodies. Unnamed.
 * Passive08_0212 is folded into 0xA343B with 1 other bodies. Unnamed.
 * Passive08_0213 is folded into 0x7C96F with 2 other bodies. Unnamed.
 * The other functions in this file are not located in sf33rd.xbe yet.
 */

#include "sf33rd/Source/Game/PASS08.h"
#include "common.h"
#include "sf33rd/Source/Game/Com_Sub.h"
#include "sf33rd/Source/Game/workuser.h"

void (*const Passive08_Tbl[214])();

void Passive08(PLW* wk) {
    Passive08_Tbl[(s16)Pattern_Index[wk->wu.id]](wk);
}

void Passive08_0000(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xD, M_Lv[wk->wu.id]);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0001(PLW* wk) {
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

void Passive08_0002(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;

    case 1:
        Normal_Attack(wk, 0xB, 0x402);
        break;

    case 2:
        J_Command_Attack(wk, 9, 0x1E, 8, -1);
        break;

    case 3:
        J_Command_Attack(wk, 8, 0x1C, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0003(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7FB0, 0x28, 7, 1, -1);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1C, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0004(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F70, 0x28, 7, 1, -1);
        break;

    case 1:
        SA_Term(wk, 0xFFFF, 0x3A, 0xFFFF, 0);
        break;

    case 2:
        J_Command_Attack(wk, 8, 0x1C, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0005(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x50, 1, -1);
        break;

    case 1:
        Jump(wk, 1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0006(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3F, 2);
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

void Passive08_0007(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3F, 2);
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

void Passive08_0008(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x60, 1, -1);
        break;

    case 1:
        Command_Attack(wk, 8, 1, -1, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0009(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, -0x7FB0, 6, 1, -1);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1C, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0010(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3F, 2);
        break;

    case 1:
        EM_Term(wk, -1, -0x7FD0, 6, 1, -1);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x202);
        break;

    case 3:
        J_Command_Attack(wk, 8, 0x1E, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0011(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0012(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3F, 2);
        break;

    case 1:
        Lever_Attack(wk, 8, 0, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0013(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3F, 2);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x40);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0014(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3F, 2);
        break;

    case 1:
        Normal_Attack(wk, 9, 0x100);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x100);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0015(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3F, 2);
        break;

    case 1:
        Normal_Attack(wk, 9, 0x200);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0016(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3F, 2);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0017(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3F, 2);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x402);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0018(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, -0x7FB8, 6, 1, -1);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x402);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0019(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x20);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1E, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0020(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3F, 2);
        break;

    case 1:
        Lever_Attack(wk, 8, 0, 0x110);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0021(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3F, 2);
        break;

    case 1:
        Lever_Attack(wk, 8, 0, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0022(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x402);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0023(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3F, 2);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1C, 8, -1);
        break;

    case 2:
        J_Command_Attack(wk, 8, 0x1C, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0024(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3F, 2);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1C, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0025(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3F, 2);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1C, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0026(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1D, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0027(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1D, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0028(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1D, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0029(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1E, 9, -1);
        break;

    case 2:
        J_Command_Attack(wk, 8, 0x1C, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0030(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3F, 2);
        break;

    case 1:
        Normal_Attack(wk, 9, 0x202);
        break;

    case 2:
        J_Command_Attack(wk, 8, 0x1E, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0031(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3F, 2);
        break;

    case 1:
        Normal_Attack(wk, 9, 0x10);
        break;

    case 2:
        Lever_Attack(wk, 9, 0, 0x20);
        break;

    case 3:
        Normal_Attack(wk, 8, 0x402);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0032(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3F, 2);
        break;

    case 1:
        Lever_Attack(wk, 0xB, 0, 0x20);
        break;

    case 2:
        Lever_Attack(wk, 8, 0, 0x402);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0033(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3F, 2);
        break;

    case 1:
        Lever_Attack(wk, 8, 0, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0034(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3F, 2);
        break;

    case 1:
        SA_Term(wk, 0x39, 0x3A, 0xFFFF, 0);
        break;

    case 2:
        J_Command_Attack(wk, 8, 0x1C, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0035(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0036(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1E, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0037(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1E, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0038(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F80, -1, 6, 1, -1);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1C, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0039(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F80, -1, 6, 1, -1);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1E, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0040(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F80, -1, 6, 1, -1);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1C, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0041(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F80, -1, 6, 1, -1);
        break;

    case 1:
        SA_Term(wk, 0x39, 0xFFFF, 0xFFFF, 0);
        break;

    case 2:
        J_Command_Attack(wk, 8, 0x1C, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0042(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Forced_Guard(wk, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0043(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA0, 0x40, 8, 0x100, 0, -0x7FC0, -1, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0044(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA0, 0x40, 8, 0x400, 0, -0x7FC0, -1, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0045(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1C, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0046(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1C, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0047(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1C, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0048(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x10);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0049(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x100);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x100);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0050(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x10);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1C, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0051(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x102);
        break;

    case 1:
        Normal_Attack(wk, 9, 0x100);
        break;

    case 2:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0052(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA8, -0x7FC0, 9, 0x20, 0, -0x7FB0, -1, 0x200);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1C, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0053(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA8, -0x7FC0, 9, 0x200, 0, -0x7FB0, -1, 0x20);
        break;

    case 1:
        Normal_Attack(wk, 0xB, 0x400);
        break;

    case 2:
        J_Command_Attack(wk, 8, 0x1C, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0054(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 3, -1);
        break;

    case 1:
        Normal_Attack(wk, 9, 0x102);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x202);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0055(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;

    case 1:
        Lever_Attack(wk, 8, 0, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0056(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Check_EX(wk, 6, 0xBC);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1D, 8, 0x700);
        break;

    case 2:
        Command_Attack(wk, 8, 1, -1, -1);
        break;

    case 3:
        Search_Back_Term(wk, 0x60, 1, -1);
        break;

    case 4:
        Command_Attack(wk, 8, 1, -1, -1);
        break;

    case 5:
        Search_Back_Term(wk, 0x60, 1, -1);
        break;

    case 6:
        Command_Attack(wk, 8, 1, -1, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0057(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 3, -1);
        break;

    case 1:
        Normal_Attack(wk, 0xC, 0x22);
        break;

    case 2:
        SA_Term(wk, 0x39, 0xFFFF, 0x3B, 0);
        break;

    case 3:
        Command_Attack(wk, 8, 0x1E, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0058(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Provoke(wk, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0059(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;

    case 1:
        Lever_Attack(wk, 8, 0, 0x110);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0060(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Check_EX(wk, 6, 0x3A);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1E, 10, 0x70);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0061(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Lie(wk, 0);
        break;

    case 1:
        Approach_Walk(wk, 0x3F, 2);
        break;

    case 2:
        Wait_Get_Up(wk, 3, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0062(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 3, -1);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x402);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0063(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7FB0, 0x28, 7, 1, -1);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1C, 10, 0x700);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0064(PLW* wk) {
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

void Passive08_0065(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, 0);
        break;

    case 1:
        Jump_Attack_Term(wk, -0x7FA8, -0x7FC0, 0xB, 0x200, 0, -0x7FB0, -1, 0x400);
        break;

    case 2:
        J_Command_Attack(wk, 8, 0x1C, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0066(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, 0);
        break;

    case 1:
        Walk(wk, 0, 0x10, 0);
        break;

    case 2:
        Pierce_On(wk);
        break;

    case 3:
        J_Command_Attack(wk, 8, 0x1C, 9, -1);
        break;

    case 4:
        Search_Back_Term(wk, 0x60, 1, -1);
        break;

    case 5:
        Command_Attack(wk, 8, 1, -1, -1);
        break;

    case 6:
        Search_Back_Term(wk, 0x60, 1, -1);
        break;

    case 7:
        Command_Attack(wk, 8, 1, -1, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0067(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, 0);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0068(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Lie(wk, 0);
        break;

    case 1:
        Approach_Walk(wk, 0x7B, 2);
        break;

    case 2:
        Wait_Get_Up(wk, 3, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0069(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0070(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, 0);
        break;

    case 1:
        Jump_Attack_Term(wk, -0x7FA0, -0x7FC0, 0xB, 0x400, 0, -0x7FB0, -1, 0x200);
        break;

    case 2:
        J_Command_Attack(wk, 8, 0x1C, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0071(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Lie(wk, 0);
        break;

    case 1:
        Jump(wk, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0072(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Lie(wk, 0);
        break;

    case 1:
        Approach_Walk(wk, 0xBF, 2);
        break;

    case 2:
        Wait_Get_Up(wk, 0, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0073(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 3, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0074(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7FC0, -1, 6, 1, -1);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x100);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0075(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7FB0, -1, 0, 1, -1);
        break;

    case 1:
        Normal_Attack(wk, 0xB, 0x102);
        break;

    case 2:
        J_Command_Attack(wk, 8, 0x1C, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0076(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3F, 2);
        break;

    case 1:
        Normal_Attack(wk, 0xB, 0x402);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0077(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0078(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;

    case 1:
        Command_Attack(wk, 8, 0, -1, -1);
        break;

    case 2:
        Branch_Unit_Area(wk, 6, 0x55, 0x2F, 0x1B, 0x25);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0079(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;

    case 1:
        Command_Attack(wk, 8, 0, -1, -1);
        break;

    case 2:
        Branch_Unit_Area(wk, 6, 0x53, 0x2F, 0x24, 0x25);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0080(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA8, -0x7FC0, 9, 0x200, 0, -0x7FB0, -1, 0x20);
        break;

    case 1:
        Normal_Attack(wk, 9, 0x202);
        break;

    case 2:
        Command_Attack(wk, 8, 0x1D, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0081(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA8, -0x7FC0, 0xB, 0x200, 0, -0x7FB0, -1, 0x40);
        break;

    case 1:
        SA_Term(wk, 0x39, 0x3A, 0x3B, 0);
        break;

    case 2:
        J_Command_Attack(wk, 8, 0x1D, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0082(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA8, -0x7FC0, 9, 0x20, 0, -0x7FB0, -1, 0x200);
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
        Command_Attack(wk, 8, 0x1C, 10, -1);
        break;

    case 5:
        Com_Random_Select(wk, 6, 0x2D, 0xFF, 0xFF, 0xFF, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0083(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x40);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0084(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0085(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0086(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBF, 2);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0087(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0, -1, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0088(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump(wk, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0089(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;

    case 1:
        Command_Attack(wk, 0xC, 0, -1, -1);
        break;

    case 2:
        Command_Attack(wk, 8, 0x1C, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0090(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3F, 2);
        break;

    case 1:
        Normal_Attack(wk, 9, 0x100);
        break;

    case 2:
        SA_Term(wk, 0x39, 0x3A, 0xFFFF, 0);
        break;

    case 3:
        Command_Attack(wk, 8, 0x1C, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0091(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3F, 2);
        break;

    case 1:
        Lever_Attack(wk, 0xC, 0, 0x20);
        break;

    case 2:
        SA_Term(wk, 0x39, 0x3A, 0xFFFF, 0);
        break;

    case 3:
        Normal_Attack(wk, 8, 0x402);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0092(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3F, 2);
        break;

    case 1:
        Lever_Attack(wk, 0xC, 0, 0x20);
        break;

    case 2:
        SA_Term(wk, 0x39, 0x3A, 0xFFFF, 0);
        break;

    case 3:
        J_Command_Attack(wk, 8, 0x1C, 8, -1);
        break;

    case 4:
        J_Command_Attack(wk, 8, 0x1E, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0093(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F80, 0x28, 7, 1, -1);
        break;

    case 1:
        Lever_Attack(wk, 9, 0, 0x200);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x402);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0094(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3F, 2);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x20);
        break;

    case 2:
        J_Command_Attack(wk, 8, 0x1C, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0095(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x100);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1C, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0096(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x39, 0x3A, 0xFFFF, 0);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0097(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x39, 0x3A, 0xFFFF, 0);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1C, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0098(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x40);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0099(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x202);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0100(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x402);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0101(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xC, 0x202);
        break;

    case 1:
        SA_Term(wk, 0x39, 0x3A, 0xFFFF, 0);
        break;

    case 2:
        Command_Attack(wk, 8, 0x1C, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0102(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA8, -0x7FC0, 0xB, 0x200, 0, -1, -1, -1);
        break;

    case 1:
        SA_Term(wk, 0x39, 0x3A, 0xFFFF, 0);
        break;

    case 2:
        Command_Attack(wk, 8, 0x1C, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0103(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xB, 0x202);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1E, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0104(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x402);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1D, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0105(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3F, 2);
        break;

    case 1:
        EM_Term(wk, -1, -0x7FD0, 6, 1, -1);
        break;

    case 2:
        SA_Term(wk, 0x39, 0x3A, 0xFFFF, 0);
        break;

    case 3:
        J_Command_Attack(wk, 8, 0x1C, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0106(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA8, -0x7FC0, 0xB, 0x200, 0, -0x7FB0, -1, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0107(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, -0x7FC0, 6, 1, -1);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1D, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0108(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, -0x7FC8, 6, 1, -1);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1D, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0109(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, -0x7FC8, 0, 1, -1);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1C, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0110(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3F, 2);
        break;

    case 1:
        Normal_Attack(wk, 0xC, 0x20);
        break;

    case 2:
        SA_Term(wk, 0x39, 0x3A, 0xFFFF, 0);
        break;

    case 3:
        J_Command_Attack(wk, 8, 0x1E, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0111(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3F, 2);
        break;

    case 1:
        Normal_Attack(wk, 0xC, 0x20);
        break;

    case 2:
        SA_Term(wk, 0x39, 0x3A, 0x3B, 0);
        break;

    case 3:
        Command_Attack(wk, 8, 0x1C, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0112(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x7B, 2);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0113(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0114(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA8, -0x7FC0, 9, 0x200, 0, -0x7FB0, -1, 0x20);
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

void Passive08_0115(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA8, -0x7FC0, 0xB, 0x200, 0, -0x7FB0, -1, 0x20);
        break;

    case 1:
        Normal_Attack(wk, 9, 0x40);
        break;

    case 2:
        Command_Attack(wk, 0xC, 0x1E, 10, -1);
        break;

    case 3:
        SA_Term(wk, 0x39, 0x3A, 0xFFFF, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0116(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Forced_Guard(wk, 2);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0117(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x100);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1D, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0118(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x100);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1D, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0119(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x100);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1D, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0120(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x102);
        break;

    case 1:
        Normal_Attack(wk, 9, 0x102);
        break;

    case 2:
        Command_Attack(wk, 8, 0x1D, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0121(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x102);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0122(PLW* wk) {
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

void Passive08_0123(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x102);
        break;

    case 1:
        Normal_Attack(wk, 9, 0x202);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x402);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0124(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x102);
        break;

    case 1:
        Normal_Attack(wk, 0xB, 0x202);
        break;

    case 2:
        Command_Attack(wk, 8, 0x1D, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0125(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xB, 0x102);
        break;

    case 1:
        SA_Term(wk, 0x39, 0x3A, 0xFFFF, 0);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x402);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0126(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x102);
        break;

    case 1:
        Normal_Attack(wk, 0xB, 0x102);
        break;

    case 2:
        SA_Term(wk, 0x39, 0x3A, 0xFFFF, 0);
        break;

    case 3:
        Normal_Attack(wk, 8, 0x402);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0127(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x100);
        break;

    case 1:
        Jump_Attack_Term(wk, -0x7FA8, -0x7FC0, 9, 0x200, 0, -0x7FB0, -1, 0x20);
        break;

    case 2:
        Normal_Attack(wk, 0xB, 0x12);
        break;

    case 3:
        SA_Term(wk, 0x39, 0x3A, 0x3B, 0);
        break;

    case 4:
        Normal_Attack(wk, 8, 0x402);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0128(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x100);
        break;

    case 1:
        Jump_Attack_Term(wk, -0x7FA8, -0x7FC0, 0xB, 0x200, 0, -1, -1, -1);
        break;

    case 2:
        SA_Term(wk, 0x39, 0x3A, 0x3B, 0);
        break;

    case 3:
        Command_Attack(wk, 8, 0x1C, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0129(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x100);
        break;

    case 1:
        Jump_Attack_Term(wk, -0x7FA8, -0x7FC0, 9, 0x20, 0, -0x7FB0, -1, 0x200);
        break;

    case 2:
        Normal_Attack(wk, 9, 0x12);
        break;

    case 3:
        Normal_Attack(wk, 9, 0x102);
        break;

    case 4:
        Normal_Attack(wk, 8, 0x202);
        break;

    case 5:
        J_Command_Attack(wk, 8, 0x1C, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0130(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x100);
        break;

    case 1:
        Jump_Attack_Term(wk, -0x7FA8, -0x7FC0, 0xB, 0x200, 0, -0x7FB0, -1, 0x40);
        break;

    case 2:
        SA_Term(wk, 0x39, 0x3A, 0xFFFF, 0);
        break;

    case 3:
        J_Command_Attack(wk, 8, 0x1D, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0131(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x39, 0x3A, 0xFFFF, 0);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0132(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA8, -0x7FC0, 0xB, 0x200, 0, -0x7FB0, -1, 0x40);
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

void Passive08_0133(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA8, -0x7FC0, 0xB, 0x200, 0, -0x7FB0, -1, 0x40);
        break;

    case 1:
        Normal_Attack(wk, 0xB, 0x400);
        break;

    case 2:
        SA_Term(wk, 0x39, 0x3A, 0xFFFF, 0);
        break;

    case 3:
        J_Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0134(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA8, -0x7FC0, 9, 0x20, 0, -0x7FB0, -1, 0x200);
        break;

    case 1:
        Normal_Attack(wk, 9, 0x40);
        break;

    case 2:
        Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;

    case 3:
        Normal_Attack(wk, 8, 0x402);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0135(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, -0x7FB0, 6, 1, -1);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1E, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0136(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3F, 2);
        break;

    case 1:
        EM_Term(wk, -1, -0x7FC0, 6, 1, -1);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x402);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0137(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;

    case 1:
        Normal_Attack(wk, 0xC, 0x40);
        break;

    case 2:
        J_Command_Attack(wk, 8, 0x1E, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0138(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;

    case 1:
        Normal_Attack(wk, 0xC, 0x40);
        break;

    case 2:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0139(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;

    case 1:
        Normal_Attack(wk, 0xC, 0x40);
        break;

    case 2:
        SA_Term(wk, 0x39, 0x3A, 0xFFFF, 0);
        break;

    case 3:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0140(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;

    case 1:
        Normal_Attack(wk, 0xC, 0x40);
        break;

    case 2:
        SA_Term(wk, 0x39, 0x3A, 0x3B, 0);
        break;

    case 3:
        J_Command_Attack(wk, 8, 0x1E, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0141(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1D, 10, -1);
        break;

    case 2:
        Pierce_On(wk);
        break;

    case 3:
        Search_Back_Term(wk, 0x60, 1, -1);
        break;

    case 4:
        Command_Attack(wk, 8, 1, 10, -1);
        break;

    case 5:
        Search_Back_Term(wk, 0x60, 1, -1);
        break;

    case 6:
        Command_Attack(wk, 8, 1, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0142(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3F, 2);
        break;

    case 1:
        EM_Term(wk, -1, -0x7FC0, 6, 1, -1);
        break;

    case 2:
        Command_Attack(wk, 0xC, 0x1C, 8, -1);
        break;

    case 3:
        SA_Term(wk, 0x39, 0x3A, 0x3B, 0);
        break;

    case 4:
        Pierce_On(wk);
        break;

    case 5:
        Search_Back_Term(wk, 0x60, 1, -1);
        break;

    case 6:
        Command_Attack(wk, 8, 1, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0143(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3F, 2);
        break;

    case 1:
        EM_Term(wk, -1, -0x7FF0, 6, 1, -1);
        break;

    case 2:
        Normal_Attack(wk, 0xC, 0x40);
        break;

    case 3:
        Command_Attack(wk, 8, 0x1C, 10, -1);
        break;

    case 4:
        Pierce_On(wk);
        break;

    case 5:
        Search_Back_Term(wk, 0x60, 1, -1);
        break;

    case 6:
        Command_Attack(wk, 8, 1, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0144(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3F, 2);
        break;

    case 1:
        EM_Term(wk, -1, -0x7FF8, 6, 1, -1);
        break;

    case 2:
        Normal_Attack(wk, 0xC, 0x40);
        break;

    case 3:
        SA_Term(wk, 0x39, 0x3A, 0x3B, 0);
        break;

    case 4:
        Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0145(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3F, 2);
        break;

    case 1:
        EM_Term(wk, -1, -0x7FD0, 6, 1, -1);
        break;

    case 2:
        Search_Back_Term(wk, 0x60, 1, -1);
        break;

    case 3:
        Command_Attack(wk, 8, 1, -1, -1);
        break;

    case 4:
        J_Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0146(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;

    case 1:
        Command_Attack(wk, 0xC, 0, -1, -1);
        break;

    case 2:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0147(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;

    case 1:
        Command_Attack(wk, 8, 0x20, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0148(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 0xE, 0x20, 0xA, -1);
        break;

    case 1:
        Command_Attack(wk, 0xE, 0x20, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0149(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 0xE, 0x20, 9, -1);
        break;

    case 1:
        Command_Attack(wk, 0xE, 0x20, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0150(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Check_EX(wk, 6, 0x95);
        break;

    case 1:
        Command_Attack(wk, 0xE, 0x20, 0xA, 0x700);
        break;

    case 2:
        Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0151(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;

    case 1:
        Command_Attack(wk, 8, 0, -1, -1);
        break;

    case 2:
        Normal_Attack(wk, 9, 0x102);
        break;

    case 3:
        Normal_Attack(wk, 0xB, 0x102);
        break;

    case 4:
        SA_Term(wk, 0x39, 0x3A, 0xFFFF, 0);
        break;

    case 5:
        Normal_Attack(wk, 8, 0x202);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0152(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x200);
        break;

    case 1:
        Normal_Attack(wk, 0xB, 0x400);
        break;

    case 2:
        Normal_Attack(wk, 0xB, 0x202);
        break;

    case 3:
        Com_Random_Select(wk, 6, 0x2D, 0xFF, 0xFF, 0xFF, 2);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0153(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;

    case 1:
        SA_Term(wk, 0x39, 0x3A, 0x3B, 0);
        break;

    case 2:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0154(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Away(wk, 0xBF, 0);
        break;

    case 1:
        Wait_Get_Up(wk, 0, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0155(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Away(wk, 0xBF, 0);
        break;

    case 1:
        Wait_Get_Up(wk, 3, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0156(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Away(wk, 0xBF, 0);
        break;

    case 1:
        Wait_Get_Up(wk, 0, -1);
        break;

    case 2:
        Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0157(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;

    case 1:
        Command_Attack(wk, 8, 0, -1, -1);
        break;

    case 2:
        Jump_Attack_Term(wk, -0x7FA8, -0x7FC0, 0xB, 0x200, 0, -0x7FB0, -1, 0x40);
        break;

    case 3:
        Normal_Attack(wk, 0xB, 0x400);
        break;

    case 4:
        SA_Term(wk, 0x39, 0x3A, 0xFFFF, 0);
        break;

    case 5:
        J_Command_Attack(wk, 8, 0x1C, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0158(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;

    case 1:
        Command_Attack(wk, 8, 0, -1, -1);
        break;

    case 2:
        Jump_Attack_Term(wk, -0x7FA8, -0x7FC0, 0xB, 0x200, 0, -1, -1, -1);
        break;

    case 3:
        Normal_Attack(wk, 0xB, 0x12);
        break;

    case 4:
        SA_Term(wk, 0x39, 0x3A, 0xFFFF, 0);
        break;

    case 5:
        Normal_Attack(wk, 8, 0x402);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0159(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3F, 2);
        break;

    case 1:
        Normal_Attack(wk, 0xC, 0x40);
        break;

    case 2:
        SA_Term(wk, 0x39, 0x3A, 0x3B, 0);
        break;

    case 3:
        J_Command_Attack(wk, 8, 0x1E, 10, -1);
        break;

    case 4:
        Normal_Attack(wk, 8, 0x402);
        break;

    case 5:
        Pierce_On(wk);
        break;

    case 6:
        Search_Back_Term(wk, 0x60, 1, -1);
        break;

    case 7:
        Command_Attack(wk, 8, 1, -1, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0160(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA8, -0x7FC0, 9, 0x200, 0, -0x7FB0, -1, 0x20);
        break;

    case 1:
        Normal_Attack(wk, 0xB, 0x202);
        break;

    case 2:
        J_Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0161(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA8, -0x7FC0, 0xB, 0x200, 0, -0x7FB0, -1, 0x40);
        break;

    case 1:
        SA_Term(wk, 0x39, 0x3A, 0x3B, 0);
        break;

    case 2:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0162(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA8, -0x7FC0, 9, 0x20, 0, -0x7FB0, -1, 0x200);
        break;

    case 1:
        Normal_Attack(wk, 9, 0x12);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x202);
        break;

    case 3:
        Normal_Attack(wk, 9, 0x402);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0163(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA8, -0x7FC0, 9, 0x200, 0, -0x7FB0, -1, 0x200);
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
        Com_Random_Select(wk, 6, 0x2D, 0xFF, 0xFF, 0xFF, 2);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0164(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA0, -0x7FC0, 9, 0x400, 0, -0x7FB0, -1, 0x200);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x102);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x400);
        break;

    case 3:
        Normal_Attack(wk, 8, 0x402);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0165(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA0, -0x7FC0, 9, 0x400, 0, -0x7FB0, -1, 0x200);
        break;

    case 1:
        Normal_Attack(wk, 9, 0x402);
        break;

    case 2:
        J_Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0166(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA0, -0x7FC0, 9, 0x400, 0, -0x7FB0, -1, 0x200);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x102);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x402);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0167(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA0, -0x7FC0, 9, 0x400, 0, -0x7FB0, -1, 0x200);
        break;

    case 1:
        Normal_Attack(wk, 9, 0x402);
        break;

    case 2:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;

    case 3:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0168(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 1, 0x20, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0169(PLW* wk) {
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

void Passive08_0170(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Away(wk, 0xBF, 0);
        break;

    case 1:
        Wait_Get_Up(wk, 3, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0171(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Away(wk, 0xBF, 0);
        break;

    case 1:
        Wait_Get_Up(wk, 0, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0172(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Away(wk, 0xBF, 0);
        break;

    case 1:
        Wait_Get_Up(wk, 3, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0173(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0xFFFF, 0xFFFF, 0x3B, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0174(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3F, 2);
        break;

    case 1:
        EM_Term(wk, -1, -0x7FF0, 6, 1, -1);
        break;

    case 2:
        Normal_Attack(wk, 9, 0x40);
        break;

    case 3:
        J_Command_Attack(wk, 0xC, 0x1E, 9, -1);
        break;

    case 4:
        Wait(wk, 5);
        break;

    case 5:
        SA_Term(wk, 0x39, 0x3A, 0x3B, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0175(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x10);
        break;

    case 1:
        Normal_Attack(wk, 0xB, 0x10);
        break;

    case 2:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0176(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x10);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x10);
        break;

    case 2:
        Normal_Attack(wk, 0xB, 0x200);
        break;

    case 3:
        J_Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;

    case 4:
        Com_Random_Select(wk, 6, 0x2D, 0xFF, 0xFF, 0xFF, 2);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0177(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xB, 0x200);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;

    case 2:
        Com_Random_Select(wk, 6, 0x2D, 0xFF, 0xFF, 0xFF, 2);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0178(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA0, -0x7FC0, 9, 0x40, 0, -0x7FB0, -1, 0x200);
        break;

    case 1:
        Normal_Attack(wk, 0xB, 0x40);
        break;

    case 2:
        J_Command_Attack(wk, 0xC, 0x1E, 0xA, -1);
        break;

    case 3:
        SA_Term(wk, 0x39, 0x3A, 0x3B, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0179(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x200);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0180(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x200);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;

    case 2:
        J_Command_Attack(wk, 8, 0x1E, 9, -1);
        break;

    case 3:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0181(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x200);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x400);
        break;

    case 2:
        J_Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0182(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3F, 2);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0183(PLW* wk) {
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

void Passive08_0184(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA8, -0x7FC0, 9, 0x200, 0, -0x7FB0, -1, 0x200);
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
        J_Command_Attack(wk, 8, 0x1D, 10, -1);
        break;

    case 5:
        Com_Random_Select(wk, 6, 0x2D, 0xFF, 0xFF, 0xFF, 2);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0185(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0186(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1D, 8, -1);
        break;

    case 2:
        Search_Back_Term(wk, 0x60, 1, -1);
        break;

    case 3:
        Command_Attack(wk, 8, 1, -1, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0187(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1D, 9, -1);
        break;

    case 2:
        Search_Back_Term(wk, 0x60, 1, -1);
        break;

    case 3:
        Command_Attack(wk, 8, 1, -1, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0188(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;

    case 2:
        Search_Back_Term(wk, 0x60, 1, -1);
        break;

    case 3:
        Command_Attack(wk, 8, 1, -1, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0189(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F70, 0x28, 7, 1, -1);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1C, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0190(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F70, 0x28, 7, 1, -1);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0191(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x60, 2);
        break;

    case 1:
        Com_Random_Select(wk, 6, 0x3F, 0x40, 0x41, 0x43, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0192(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Away(wk, 0xBF, 1);
        break;

    case 1:
        Com_Random_Select(wk, 6, 0xBA, 1, 0xAF, 0x92, 3);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0193(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 1, 0x20, -1);
        break;

    case 1:
        Com_Random_Select(wk, 6, 0xBA, 1, 0xAF, 0x92, 3);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0194(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x200);
        break;

    case 1:
        Com_Random_Select(wk, 6, 1, 1, 0xC0, 0xC0, 4);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0195(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x400);
        break;

    case 1:
        Com_Random_Select(wk, 6, 1, 1, 0xC0, 0xC0, 4);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0196(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F70, 0x28, 7, 1, -1);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0197(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F70, 0x28, 7, 1, -1);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0198(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F70, 0x28, 7, 1, -1);
        break;

    case 1:
        Lever_Attack(wk, 8, 0, 0x402);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0199(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xC, 0x40);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0200(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xC, 0x40);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;

    case 2:
        Pierce_On(wk);
        break;

    case 3:
        Search_Back_Term(wk, 0x60, 1, -1);
        break;

    case 4:
        Command_Attack(wk, 8, 1, -1, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0201(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x40);
        break;

    case 1:
        J_Command_Attack(wk, 0xC, 0x1C, 0xA, -1);
        break;

    case 2:
        Wait(wk, 5);
        break;

    case 3:
        SA_Term(wk, 0x39, 0x3A, 0x3B, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0202(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xC, 0x40);
        break;

    case 1:
        SA_Term(wk, 0x39, 0x3A, 0x3B, 0);
        break;

    case 2:
        J_Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0203(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 2);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0204(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 6);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0205(PLW* wk) {
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

void Passive08_0206(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA0, -1, 8, 0x400, 1, -1, 0x20, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0207(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA8, -0x7FB0, 8, 0x200, 2, -1, -0x7FB0, 0x200);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0208(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA0, -0x7FB0, 8, 0x400, 2, -1, -0x7FB0, 0x400);
        break;

    case 1:
        Com_Random_Select(wk, 6, 0xAF, 0xB0, 0x78, 0x7B, 1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0209(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA0, -0x7FB0, 8, 0x40, 2, -1, -0x7FB0, 0x40);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x20, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0210(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA8, -0x7FB0, 8, 0x200, 2, -1, -0x7FB0, 0x200);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0211(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x402);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0212(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 9, 0x1F, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive08_0213(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7F00, 0x38, 8, 0x200, 1, -1, -1, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void (*const Passive08_Tbl[214])(PLW*) = {
    Passive08_0000, Passive08_0001, Passive08_0002, Passive08_0003, Passive08_0004, Passive08_0005, Passive08_0006,
    Passive08_0007, Passive08_0008, Passive08_0009, Passive08_0010, Passive08_0011, Passive08_0012, Passive08_0013,
    Passive08_0014, Passive08_0015, Passive08_0016, Passive08_0017, Passive08_0018, Passive08_0019, Passive08_0020,
    Passive08_0021, Passive08_0022, Passive08_0023, Passive08_0024, Passive08_0025, Passive08_0026, Passive08_0027,
    Passive08_0028, Passive08_0029, Passive08_0030, Passive08_0031, Passive08_0032, Passive08_0033, Passive08_0034,
    Passive08_0035, Passive08_0036, Passive08_0037, Passive08_0038, Passive08_0039, Passive08_0040, Passive08_0041,
    Passive08_0042, Passive08_0043, Passive08_0044, Passive08_0045, Passive08_0046, Passive08_0047, Passive08_0048,
    Passive08_0049, Passive08_0050, Passive08_0051, Passive08_0052, Passive08_0053, Passive08_0054, Passive08_0055,
    Passive08_0056, Passive08_0057, Passive08_0058, Passive08_0059, Passive08_0060, Passive08_0061, Passive08_0062,
    Passive08_0063, Passive08_0064, Passive08_0065, Passive08_0066, Passive08_0067, Passive08_0068, Passive08_0069,
    Passive08_0070, Passive08_0071, Passive08_0072, Passive08_0073, Passive08_0074, Passive08_0075, Passive08_0076,
    Passive08_0077, Passive08_0078, Passive08_0079, Passive08_0080, Passive08_0081, Passive08_0082, Passive08_0083,
    Passive08_0084, Passive08_0085, Passive08_0086, Passive08_0087, Passive08_0088, Passive08_0089, Passive08_0090,
    Passive08_0091, Passive08_0092, Passive08_0093, Passive08_0094, Passive08_0095, Passive08_0096, Passive08_0097,
    Passive08_0098, Passive08_0099, Passive08_0100, Passive08_0101, Passive08_0102, Passive08_0103, Passive08_0104,
    Passive08_0105, Passive08_0106, Passive08_0107, Passive08_0108, Passive08_0109, Passive08_0110, Passive08_0111,
    Passive08_0112, Passive08_0113, Passive08_0114, Passive08_0115, Passive08_0116, Passive08_0117, Passive08_0118,
    Passive08_0119, Passive08_0120, Passive08_0121, Passive08_0122, Passive08_0123, Passive08_0124, Passive08_0125,
    Passive08_0126, Passive08_0127, Passive08_0128, Passive08_0129, Passive08_0130, Passive08_0131, Passive08_0132,
    Passive08_0133, Passive08_0134, Passive08_0135, Passive08_0136, Passive08_0137, Passive08_0138, Passive08_0139,
    Passive08_0140, Passive08_0141, Passive08_0142, Passive08_0143, Passive08_0144, Passive08_0145, Passive08_0146,
    Passive08_0147, Passive08_0148, Passive08_0149, Passive08_0150, Passive08_0151, Passive08_0152, Passive08_0153,
    Passive08_0154, Passive08_0155, Passive08_0156, Passive08_0157, Passive08_0158, Passive08_0159, Passive08_0160,
    Passive08_0161, Passive08_0162, Passive08_0163, Passive08_0164, Passive08_0165, Passive08_0166, Passive08_0167,
    Passive08_0168, Passive08_0169, Passive08_0170, Passive08_0171, Passive08_0172, Passive08_0173, Passive08_0174,
    Passive08_0175, Passive08_0176, Passive08_0177, Passive08_0178, Passive08_0179, Passive08_0180, Passive08_0181,
    Passive08_0182, Passive08_0183, Passive08_0184, Passive08_0185, Passive08_0186, Passive08_0187, Passive08_0188,
    Passive08_0189, Passive08_0190, Passive08_0191, Passive08_0192, Passive08_0193, Passive08_0194, Passive08_0195,
    Passive08_0196, Passive08_0197, Passive08_0198, Passive08_0199, Passive08_0200, Passive08_0201, Passive08_0202,
    Passive08_0203, Passive08_0204, Passive08_0205, Passive08_0206, Passive08_0207, Passive08_0208, Passive08_0209,
    Passive08_0210, Passive08_0211, Passive08_0212, Passive08_0213
};
