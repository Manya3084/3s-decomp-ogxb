/* PASS06.c, retail sf33rd.xbe.
 * PlayStation 2 C, not hand-adjusted for Xbox. Each named body was located
 * from the PS2 retail map: call graph, source order, and agreement of
 * constants, field offsets, callees, and size. See docs/decompiling.md.
 * The #include lines name headers in the PS2 tree (ps2.path).
 * Passive06 0x7458D size 0x1A.
 * Passive06_0002 0x745A7 size 0x45.
 * Passive06_0003 0x745EC size 0x45.
 * Passive06_0012 0x74631 size 0x48.
 * Passive06_0025 0x74725 size 0x5A.
 * Passive06_0026 0x7477F size 0x5A.
 * Passive06_0027 0x747D9 size 0x5A.
 * Passive06_0028 0x74833 size 0x5D.
 * Passive06_0029 0x74890 size 0x5D.
 * Passive06_0030 0x748ED size 0x70.
 * Passive06_0031 0x7495D size 0x70.
 * Passive06_0034 0x74A24 size 0x6F.
 * Passive06_0035 0x74A93 size 0x6C.
 * Passive06_0036 0x74AFF size 0x6C.
 * Passive06_0037 0x74B6B size 0x6C.
 * Passive06_0038 0x74BD7 size 0x6C.
 * Passive06_0040 0x74C43 size 0x60.
 * Passive06_0041 0x74CA3 size 0x73.
 * Passive06_0042 0x74D16 size 0x84.
 * Passive06_0043 0x74D9A size 0x45.
 * Passive06_0044 0x74DDF size 0x45.
 * Passive06_0045 0x74E24 size 0x48.
 * Passive06_0046 0x74E6C size 0x48.
 * Passive06_0047 0x74EB4 size 0x45.
 * Passive06_0048 0x74EF9 size 0x73.
 * Passive06_0049 0x74F6C size 0x45.
 * Passive06_0050 0x74FB1 size 0x48.
 * Passive06_0051 0x74FF9 size 0x57.
 * Passive06_0052 0x75050 size 0x49.
 * Passive06_0053 0x75099 size 0x42.
 * Passive06_0055 0x750DB size 0x6D.
 * Passive06_0056 0x75148 size 0x67.
 * Passive06_0057 0x751AF size 0x82.
 * Passive06_0058 0x75231 size 0x44.
 * Passive06_0059 0x75275 size 0x66.
 * Passive06_0060 0x752DB size 0x3D.
 * Passive06_0061 0x75318 size 0x3D.
 * Passive06_0062 0x75355 size 0x40.
 * Passive06_0063 0x75395 size 0x3D.
 * Passive06_0064 0x753D2 size 0x69.
 * Passive06_0065 0x7543B size 0x49.
 * Passive06_0066 0x75484 size 0x61.
 * Passive06_0067 0x754E5 size 0x4F.
 * Passive06_0068 0x75534 size 0x4C.
 * Passive06_0069 0x75580 size 0x50.
 * Passive06_0070 0x755D0 size 0x5F.
 * Passive06_0071 0x7562F size 0x71.
 * Passive06_0072 0x756A0 size 0x71.
 * Passive06_0073 0x75711 size 0x6E.
 * Passive06_0074 0x7577F size 0x6E.
 * Passive06_0075 0x757ED size 0x6E.
 * Passive06_0076 0x7585B size 0x51.
 * Passive06_0077 0x758AC size 0x86.
 * Passive06_0078 0x75932 size 0x43.
 * Passive06_0079 0x75975 size 0x3A.
 * Passive06_0080 0x759AF size 0x3A.
 * Passive06_0081 0x759E9 size 0x3A.
 * Passive06_0082 0x75A23 size 0x3D.
 * Passive06_0083 0x75A60 size 0x3D.
 * Passive06_0085 0x75ADA size 0x28.
 * Passive06_0086 0x75B02 size 0x3B.
 * Passive06_0087 0x75B3D size 0x3B.
 * Passive06_0088 0x75B78 size 0x27.
 * Passive06_0089 0x75B9F size 0x50.
 * Passive06_0090 0x75BEF size 0x53.
 * Passive06_0091 0x75C42 size 0x53.
 * Passive06_0092 0x75C95 size 0x62.
 * Passive06_0093 0x75CF7 size 0x3C.
 * Passive06_0094 0x75D33 size 0x42.
 * Passive06_0095 0x75D75 size 0x42.
 * Passive06_0101 0x75DE3 size 0x3F.
 * Passive06_0103 0x75E22 size 0x6A.
 * Passive06_0104 0x75E8C size 0x57.
 * Passive06_0105 0x75EE3 size 0x47.
 * Passive06_0106 0x75F2A size 0x44.
 * Passive06_0109 0x75FCB size 0x45.
 * Passive06_0112 0x7603E size 0x4C.
 * Passive06_0113 0x7608A size 0x33.
 * Passive06_0115 0x760BD size 0x3D.
 * Passive06_0117 0x760FA size 0x3A.
 * Passive06_0118 0x76134 size 0x51.
 * Passive06_0119 0x76185 size 0x67.
 * Passive06_0120 0x761EC size 0x67.
 * Passive06_0121 0x76253 size 0x49.
 * Passive06_0123 0x7629C size 0x45.
 * Passive06_0124 0x762E1 size 0x45.
 * Passive06_0125 0x76326 size 0x48.
 * Passive06_0126 0x7636E size 0x48.
 * Passive06_0127 0x763B6 size 0x4C.
 * Passive06_0128 0x76402 size 0x48.
 * Passive06_0130 0x7644A size 0x58.
 * Passive06_0132 0x764A2 size 0xA6.
 * Passive06_0133 0x76548 size 0x9F.
 * Passive06_0134 0x765E7 size 0x49.
 * Passive06_0135 0x76630 size 0x47.
 * Passive06_0136 0x76677 size 0x92.
 * Passive06_0138 0x76709 size 0x4C.
 * Passive06_0139 0x76755 size 0x61.
 * Passive06_0140 0x767B6 size 0x57.
 * Passive06_0141 0x7680D size 0x5A.
 * Passive06_0142 0x76867 size 0x54.
 * Passive06_0143 0x768BB size 0x54.
 * Passive06_0144 0x7690F size 0x54.
 * Passive06_0145 0x76963 size 0x3A.
 * Passive06_0000 is folded into 0xD0F75 with 14 other bodies. Unnamed.
 * Passive06_0001 is folded into 0xAB943 with 26 other bodies. Unnamed.
 * Passive06_0004 is folded into 0x73AC3 with 3 other bodies. Unnamed.
 * Passive06_0005 is folded into 0x71EDE with 7 other bodies. Unnamed.
 * Passive06_0007 is folded into 0xA5E79 with 3 other bodies. Unnamed.
 * Passive06_0009 is folded into 0x6D0A6 with 21 other bodies. Unnamed.
 * Passive06_0010 is folded into 0xA5879 with 6 other bodies. Unnamed.
 * Passive06_0011 is folded into 0xA9FF7 with 21 other bodies. Unnamed.
 * Passive06_0016 is folded into 0xE2EEB with 17 other bodies. Unnamed.
 * Passive06_0017 is folded into 0xE2F17 with 13 other bodies. Unnamed.
 * Passive06_0018 is folded into 0xE2F43 with 11 other bodies. Unnamed.
 * Passive06_0019 is folded into 0x746F9 with 3 other bodies. Unnamed.
 * Passive06_0020 is folded into 0x85416 with 5 other bodies. Unnamed.
 * Passive06_0021 is folded into 0x1C045 with 4 other bodies. Unnamed.
 * Passive06_0022 is folded into 0xA340F with 4 other bodies. Unnamed.
 * Passive06_0023 is folded into 0x9E8D7 with 2 other bodies. Unnamed.
 * Passive06_0024 is folded into 0x9E903 with 3 other bodies. Unnamed.
 * Passive06_0039 is folded into 0x75F6E with 1 other bodies. Unnamed.
 * Passive06_0084 is folded into 0x75A9D with 3 other bodies. Unnamed.
 * Passive06_0097 is folded into 0xA12F9 with 1 other bodies. Unnamed.
 * Passive06_0099 is folded into 0xDAC4C with 14 other bodies. Unnamed.
 * Passive06_0102 is folded into 0x822AE with 19 other bodies. Unnamed.
 * Passive06_0108 is folded into 0x75F6E with 1 other bodies. Unnamed.
 * Passive06_0110 is folded into 0x822AE with 19 other bodies. Unnamed.
 * Passive06_0111 is folded into 0x76010 with 1 other bodies. Unnamed.
 * Passive06_0114 is folded into 0xD4405 with 1 other bodies. Unnamed.
 * Passive06_0116 is folded into 0x741D3 with 2 other bodies. Unnamed.
 * Passive06_0122 is folded into 0xA9BB4 with 14 other bodies. Unnamed.
 * Passive06_0129 is folded into 0x7EE7B with 22 other bodies. Unnamed.
 * Passive06_0137 is folded into 0x76010 with 1 other bodies. Unnamed.
 * Passive06_0146 is folded into 0x7C96F with 2 other bodies. Unnamed.
 * Passive06_0006 is folded into 0xA10BA with 1 other bodies. Unnamed.
 * Passive06_0008 is folded into 0x81439 with 1 other bodies. Unnamed.
 * Passive06_0013 is folded into 0xA10FF with 1 other bodies. Unnamed.
 * Passive06_0014 is folded into 0x74679 with 1 other bodies. Unnamed.
 * Passive06_0015 is folded into 0x746B9 with 1 other bodies. Unnamed.
 * Passive06_0032 is folded into 0x749CD with 1 other bodies. Unnamed.
 * Passive06_0033 is folded into 0xA0F50 with 1 other bodies. Unnamed.
 * Passive06_0054 is folded into 0xA1239 with 2 other bodies. Unnamed.
 * Passive06_0096 is folded into 0xA12D1 with 1 other bodies. Unnamed.
 * Passive06_0098 is folded into 0xA1324 with 1 other bodies. Unnamed.
 * Passive06_0100 is folded into 0x75DB7 with 1 other bodies. Unnamed.
 * Passive06_0107 is folded into 0x7E5AA with 1 other bodies. Unnamed.
 * Passive06_0131 is folded into 0xA14B4 with 1 other bodies. Unnamed.
 */

#include "sf33rd/Source/Game/PASS06.h"
#include "common.h"
#include "sf33rd/Source/Game/Com_Sub.h"
#include "sf33rd/Source/Game/workuser.h"

void (*const Passive06_Tbl[147])();

void Passive06(PLW* wk) {
    Passive06_Tbl[(s16)Pattern_Index[wk->wu.id]](wk);
}

void Passive06_0000(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xD, M_Lv[wk->wu.id]);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0001(PLW* wk) {
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

void Passive06_0002(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, -0x7FB8, 6, 1, -1);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0003(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, -0x7F80, 6, 1, -1);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x40);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0004(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x12);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0005(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x22);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0006(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, -0x7FB8, 6, 1, -1);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x42);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0007(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x100);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0008(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, -0x7FD0, 6, 1, -1);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0009(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0010(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x102);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0011(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x202);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0012(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, -0x7FC0, 6, 1, -1);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x402);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0013(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x70, 2);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1C, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0014(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x68, 2);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1C, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0015(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x60, 2);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1C, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0016(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0017(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0018(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0019(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1F, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0020(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1F, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0021(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1F, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0022(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x20, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0023(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x20, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0024(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x20, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0025(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x70, 2);
        break;

    case 1:
        EM_Term(wk, -1, -0x7FF8, 6, 1, -1);
        break;

    case 2:
        Command_Attack(wk, 8, 0x1C, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0026(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x68, 2);
        break;

    case 1:
        EM_Term(wk, -1, -0x7FF8, 6, 1, -1);
        break;

    case 2:
        Command_Attack(wk, 8, 0x1C, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0027(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x60, 2);
        break;

    case 1:
        EM_Term(wk, -1, -0x7FF8, 6, 1, -1);
        break;

    case 2:
        Command_Attack(wk, 8, 0x1C, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0028(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x80, 2);
        break;

    case 1:
        EM_Term(wk, -1, -0x7F80, 6, 1, -1);
        break;

    case 2:
        Command_Attack(wk, 8, 0x1F, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0029(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x80, 2);
        break;

    case 1:
        EM_Term(wk, -1, -0x7F80, 6, 1, -1);
        break;

    case 2:
        Command_Attack(wk, 8, 0x1F, 10, 0x70);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0030(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x78, 2);
        break;

    case 1:
        EM_Term(wk, -1, -0x7FF8, 6, 1, -1);
        break;

    case 2:
        SA_Term(wk, 1, 0xFFFF, 3, 0x78);
        break;

    case 3:
        Command_Attack(wk, 8, 0x1C, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0031(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x78, 2);
        break;

    case 1:
        EM_Term(wk, -1, -0x7F80, 6, 1, -1);
        break;

    case 2:
        Command_Attack(wk, 0xC, 0x1F, 10, 0x70);
        break;

    case 3:
        SA_Term(wk, 0xFFFF, 2, 3, 0x78);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0032(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x44, 2);
        break;

    case 1:
        EM_Term(wk, -1, -0x7FFC, 6, 1, -1);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x110);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0033(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x44, 2);
        break;

    case 1:
        EM_Term(wk, -1, -0x7FFC, 6, 1, -1);
        break;

    case 2:
        Lever_Attack(wk, 8, 0, 0x110);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0034(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x80, 2);
        break;

    case 1:
        EM_Term(wk, -1, -0x7F80, 6, 1, -1);
        break;

    case 2:
        Command_Attack(wk, 8, 0x1F, 10, -1);
        break;

    case 3:
        Normal_Attack(wk, 8, 0x100);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0035(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x60, 2);
        break;

    case 1:
        EM_Term(wk, -1, -0x7F80, 6, 1, -1);
        break;

    case 2:
        Command_Attack(wk, 8, 0x1F, 10, -1);
        break;

    case 3:
        Normal_Attack(wk, 8, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0036(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x80, 2);
        break;

    case 1:
        EM_Term(wk, -1, -0x7F80, 6, 1, -1);
        break;

    case 2:
        Command_Attack(wk, 8, 0x1F, 10, -1);
        break;

    case 3:
        Normal_Attack(wk, 8, 0x10);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0037(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x80, 2);
        break;

    case 1:
        EM_Term(wk, -1, -0x7F80, 6, 1, -1);
        break;

    case 2:
        Command_Attack(wk, 8, 0x1F, 10, -1);
        break;

    case 3:
        Normal_Attack(wk, 8, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0038(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x80, 2);
        break;

    case 1:
        EM_Term(wk, -1, -0x7F80, 6, 1, -1);
        break;

    case 2:
        Command_Attack(wk, 8, 0x1F, 10, -1);
        break;

    case 3:
        Normal_Attack(wk, 8, 0x40);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0039(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x80, 2);
        break;

    case 1:
        EM_Term(wk, -1, -0x7FB0, 6, 1, -1);
        break;

    case 2:
        Command_Attack(wk, 8, 0x20, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0040(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x80, 2);
        break;

    case 1:
        EM_Term(wk, -1, -0x7FB0, 6, 1, -1);
        break;

    case 2:
        Command_Attack(wk, 8, 0x20, 8, 0x700);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0041(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x80, 2);
        break;

    case 1:
        EM_Term(wk, -1, -0x7F80, 6, 1, -1);
        break;

    case 2:
        Pierce_On(wk);
        break;

    case 3:
        Command_Attack(wk, 8, 0x1F, 10, 0x70);
        break;

    case 4:
        Command_Attack(wk, 8, 0x20, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0042(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x80, 2);
        break;

    case 1:
        EM_Term(wk, -1, -0x7F80, 6, 1, -1);
        break;

    case 2:
        Check_EX(wk, 6, 0x18);
        break;

    case 3:
        Pierce_On(wk);
        break;

    case 4:
        Command_Attack(wk, 0xB, 0x1F, 10, 0x70);
        break;

    case 5:
        Command_Attack(wk, 8, 0x1E, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0043(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F60, -1, 6, 1, -1);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0044(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F60, -1, 6, 1, -1);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x40);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0045(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F60, -1, 6, 1, -1);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0046(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F60, -1, 6, 1, -1);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0047(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F60, -1, 6, 1, -1);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x10);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0048(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x9F, 2);
        break;

    case 1:
        EM_Term(wk, -1, -0x7FF8, 6, 1, -1);
        break;

    case 2:
        SA_Term(wk, 1, 0xFFFF, 3, 0xFFFF);
        break;

    case 3:
        Command_Attack(wk, 8, 0x1C, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0049(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F60, -1, 6, 1, -1);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x42);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0050(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F40, -1, 6, 1, -1);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x402);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0051(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F60, -1, 6, 1, -1);
        break;

    case 1:
        Jump_Attack_Term(wk, -0x7F90, 0x38, 8, 0x400, 2, -1, -1, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0052(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F60, -1, 6, 1, -1);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1E, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0053(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0xFFFF, 2, 0xFFFF, 0xFFFF);
        break;

    case 1:
        Next_Another_Menu(wk, 6, 0x2F);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0054(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x58, 2);
        break;

    case 1:
        Pierce_On(wk);
        break;

    case 2:
        Command_Attack(wk, 0xB, 0x21, 10, -1);
        break;

    case 3:
        Command_Attack(wk, 8, 0x1E, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0055(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x58, 2);
        break;

    case 1:
        Pierce_On(wk);
        break;

    case 2:
        Command_Attack(wk, 0xB, 0x21, 10, -1);
        break;

    case 3:
        SA_Term(wk, 0xFFFF, 2, 0xFFFF, 0xFFFF);
        break;

    case 4:
        Command_Attack(wk, 8, 0x1E, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0056(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x58, 2);
        break;

    case 1:
        Check_EX(wk, 6, 0x65);
        break;

    case 2:
        Pierce_On(wk);
        break;

    case 3:
        Command_Attack(wk, 0xB, 0x1F, 10, 0x70);
        break;

    case 4:
        Command_Attack(wk, 8, 0x1E, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0057(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, -0x7FA0, 6, 1, -1);
        break;

    case 1:
        Approach_Walk(wk, 0x58, 2);
        break;

    case 2:
        EM_Term(wk, -1, -0x7FF8, 6, 1, -1);
        break;

    case 3:
        Pierce_On(wk);
        break;

    case 4:
        Command_Attack(wk, 0xB, 0x21, 10, -1);
        break;

    case 5:
        Command_Attack(wk, 8, 0x1E, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0058(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0xFFFF, 2, 0xFFFF, 0xFFFF);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1E, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0059(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x60, 6, 0x2D);
        break;

    case 1:
        Pierce_On(wk);
        break;

    case 2:
        Command_Attack(wk, 8, 1, -1, -1);
        break;

    case 3:
        Com_Random_Select(wk, 6, 0x41, 0x2D, 0x31, 0x3C, 1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0060(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA8, -0x7FC0, 8, 0x200, 0, -0x7FA8, -1, 0x40);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0061(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7F88, -0x7FC0, 8, 0x400, 0, -0x7F88, -1, 0x40);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0062(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7F68, -0x7FC0, 8, 0x200, 0, -0x7F68, -1, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0063(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7F68, -0x7FC0, 8, 0x400, 0, -0x7F68, -1, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0064(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA8, -0x7FC0, 9, 0x200, 0, -0x7FA8, -1, 0x400);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1F, 10, -1);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x10);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0065(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F00, -1, 6, 1, -1);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1F, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0066(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F60, -1, 6, 1, -1);
        break;

    case 1:
        Pierce_On(wk);
        break;

    case 2:
        Command_Attack(wk, 0xB, 0x1F, 10, 0x70);
        break;

    case 3:
        Command_Attack(wk, 8, 0x1E, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0067(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x60, 2);
        break;

    case 1:
        Wait_Get_Up(wk, 0, -1);
        break;

    case 2:
        Command_Attack(wk, 8, 0x1C, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0068(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x44, 2);
        break;

    case 1:
        Wait_Get_Up(wk, 0, -1);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x110);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0069(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x44, 2);
        break;

    case 1:
        Wait_Get_Up(wk, 0, -1);
        break;

    case 2:
        Lever_Attack(wk, 8, 1, 0x110);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0070(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x80, 2);
        break;

    case 1:
        Wait_Get_Up(wk, 0, 0);
        break;

    case 2:
        Wait(wk, 10);
        break;

    case 3:
        Command_Attack(wk, 8, 0x1F, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0071(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x80, 2);
        break;

    case 1:
        Wait_Get_Up(wk, 0, 0);
        break;

    case 2:
        Wait(wk, 10);
        break;

    case 3:
        Command_Attack(wk, 8, 0x1F, 10, -1);
        break;

    case 4:
        Normal_Attack(wk, 8, 0x100);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0072(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x80, 2);
        break;

    case 1:
        Wait_Get_Up(wk, 0, 0);
        break;

    case 2:
        Wait(wk, 10);
        break;

    case 3:
        Command_Attack(wk, 8, 0x1F, 10, -1);
        break;

    case 4:
        Normal_Attack(wk, 8, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0073(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x80, 2);
        break;

    case 1:
        Wait_Get_Up(wk, 0, 0);
        break;

    case 2:
        Wait(wk, 10);
        break;

    case 3:
        Command_Attack(wk, 8, 0x1F, 10, -1);
        break;

    case 4:
        Normal_Attack(wk, 8, 0x10);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0074(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x80, 2);
        break;

    case 1:
        Wait_Get_Up(wk, 0, 0);
        break;

    case 2:
        Wait(wk, 10);
        break;

    case 3:
        Command_Attack(wk, 8, 0x1F, 10, -1);
        break;

    case 4:
        Normal_Attack(wk, 8, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0075(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x80, 2);
        break;

    case 1:
        Wait_Get_Up(wk, 0, 0);
        break;

    case 2:
        Wait(wk, 10);
        break;

    case 3:
        Command_Attack(wk, 8, 0x1F, 10, -1);
        break;

    case 4:
        Normal_Attack(wk, 8, 0x40);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0076(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x80, 2);
        break;

    case 1:
        Wait_Get_Up(wk, 0, 0);
        break;

    case 2:
        Command_Attack(wk, 8, 0x20, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0077(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x80, 2);
        break;

    case 1:
        Wait_Get_Up(wk, 0, 0);
        break;

    case 2:
        Check_EX(wk, 6, 0x4E);
        break;

    case 3:
        Wait(wk, 10);
        break;

    case 4:
        Pierce_On(wk);
        break;

    case 5:
        Command_Attack(wk, 0xB, 0x1F, 10, 0x70);
        break;

    case 6:
        Command_Attack(wk, 8, 0x1E, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0078(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 3, 0);
        break;

    case 1:
        Com_Random_Select(wk, 6, 0x41, 0x2D, 0x31, 0x65, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0079(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 3, 0);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x12);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0080(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 3, 0);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x22);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0081(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 3, 0);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x42);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0082(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 3, 0);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x102);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0083(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 3, 0);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x202);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0084(PLW* wk) {
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

void Passive06_0085(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 3, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0086(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Away(wk, 0x9F, 0);
        break;

    case 1:
        Wait_Get_Up(wk, 0, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0087(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Away(wk, 0xFF, 0);
        break;

    case 1:
        Wait_Get_Up(wk, 0, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0088(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0089(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Away(wk, 0x9F, 0);
        break;

    case 1:
        Wait_Get_Up(wk, 0, 0);
        break;

    case 2:
        Command_Attack(wk, 8, 0x20, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0090(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Away(wk, 0x9F, 0);
        break;

    case 1:
        Wait_Get_Up(wk, 0, 0);
        break;

    case 2:
        Com_Random_Select(wk, 6, 0x41, 0x2D, 0x31, 0x65, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0091(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Away(wk, 0xFF, 0);
        break;

    case 1:
        Wait_Get_Up(wk, 0, 0);
        break;

    case 2:
        Com_Random_Select(wk, 6, 0x3C, 0x3D, 0x3F, 0x65, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0092(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x80, 2);
        break;

    case 1:
        Wait_Get_Up(wk, 0, 0);
        break;

    case 2:
        Pierce_On(wk);
        break;

    case 3:
        Command_Attack(wk, 8, 0x1F, 10, -1);
        break;

    case 4:
        Command_Attack(wk, 8, 0x1F, 10, -1);
        break;

    case 5:
        Command_Attack(wk, 8, 0x1F, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0093(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, 0);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0094(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, 0);
        break;

    case 1:
        Com_Random_Select(wk, 6, 0x41, 0x2D, 0x31, 0x65, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0095(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, 0);
        break;

    case 1:
        Com_Random_Select(wk, 6, 0x3C, 0x3D, 0x3F, 0x65, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0096(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x44, 2);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0097(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x9F, 2);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0098(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xFF, 2);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0099(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump(wk, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0100(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0101(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, 0);
        break;

    case 1:
        Command_Attack(wk, 8, 0x20, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0102(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0103(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x80, 2);
        break;

    case 1:
        Check_EX(wk, 6, 0x36);
        break;

    case 2:
        Pierce_On(wk);
        break;

    case 3:
        Command_Attack(wk, 0xB, 0x1F, 10, 0x70);
        break;

    case 4:
        Command_Attack(wk, 8, 0x1E, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0104(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ETC_Term(wk, 5, 6, 0xF);
        break;

    case 1:
        Pierce_On(wk);
        break;

    case 2:
        Provoke(wk, -1);
        break;

    case 3:
        Next_Another_Menu(wk, 6, 0xF);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0105(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;

    case 1:
        Command_Attack(wk, 0xC, 0, -1, -1);
        break;

    case 2:
        Command_Attack(wk, 8, 0x20, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0106(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0xFFFF, 0xFFFF, 3, 0xFFFF);
        break;

    case 1:
        Command_Attack(wk, 0xC, 0, -1, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0107(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ETC_Term(wk, 4, 6, 0x36);
        break;

    case 1:
        Provoke(wk, -1);
        break;

    case 2:
        Next_Another_Menu(wk, 6, 0x37);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0108(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x80, 2);
        break;

    case 1:
        EM_Term(wk, -1, -0x7FB0, 6, 1, -1);
        break;

    case 2:
        Command_Attack(wk, 8, 0x20, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0109(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, -0x7FB8, 6, 1, -1);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x10);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0110(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0111(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Branch_Unit_Area(wk, 6, 0x16, 0x16, 0x17, 0x18);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0112(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;

    case 1:
        Provoke(wk, -1);
        break;

    case 2:
        Com_Random_Select(wk, 6, 0x65, 0x5B, 0x5A, 0x58, 4);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0113(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;

    case 1:
        Provoke(wk, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0114(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump(wk, 1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0115(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA8, -0x7FC0, 8, 0x200, 1, -0x7FA8, -1, 0x40);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0116(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump(wk, 2);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0117(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7F68, 0x40, 8, 0x40, 2, -0x7F68, -1, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0118(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;

    case 1:
        Command_Attack(wk, 0xC, 1, -1, -1);
        break;

    case 2:
        Branch_Unit_Area(wk, 6, 0x16, 0x16, 0x17, 0x18);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0119(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x58, 2);
        break;

    case 1:
        Check_EX(wk, 6, 0x6F);
        break;

    case 2:
        Pierce_On(wk);
        break;

    case 3:
        Command_Attack(wk, 0xB, 0x1F, 10, 0x70);
        break;

    case 4:
        Command_Attack(wk, 8, 0x1E, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0120(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x58, 2);
        break;

    case 1:
        Check_EX(wk, 6, 0x79);
        break;

    case 2:
        Pierce_On(wk);
        break;

    case 3:
        Command_Attack(wk, 0xB, 0x1F, 10, 0x70);
        break;

    case 4:
        Command_Attack(wk, 8, 0x1E, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0121(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, -0x7FB0, 6, 1, -1);
        break;

    case 1:
        Branch_Unit_Area(wk, 6, 0x16, 0x16, 0x17, 0x18);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0122(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x42);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0123(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F40, -1, 0, 1, -1);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x12);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0124(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F20, -1, 0, 1, -1);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x22);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0125(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F60, -1, 0, 1, -1);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x102);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0126(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F40, -1, 0, 1, -1);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x202);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0127(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;

    case 1:
        Jump(wk, 0);
        break;

    case 2:
        Com_Random_Select(wk, 6, 0x16, 0x13, 0x2C, 8, 1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0128(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0xFFFF, 0xFFFF, 3, 0xFFFF);
        break;

    case 1:
        Branch_Unit_Area(wk, 6, 0x16, 0x16, 0x17, 0x18);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0129(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Forced_Guard(wk, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0130(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x9F, 2);
        break;

    case 1:
        SA_Term(wk, 1, 0xFFFF, 0xFFFF, -1);
        break;

    case 2:
        Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0131(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Turn_Over_On(wk);
        break;

    case 1:
        Jump_Attack_Term(wk, -0x7F90, -0x7FA8, 8, 0x42, 0, -0x7F68, -1, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0132(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Turn_Over_On(wk);
        break;

    case 1:
        Jump_Attack_Term(wk, -0x7F90, -0x7FA8, 9, 0x42, 0, -0x7F68, -1, 0x400);
        break;

    case 2:
        Normal_Attack(wk, 0xB, 0x100);
        break;

    case 3:
        Wait(wk, 9);
        break;

    case 4:
        EM_Term(wk, -0x7F90, -1, 4, 6, 0x89);
        break;

    case 5:
        Command_Attack(wk, 8, 0x1C, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0133(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, 0);
        break;

    case 1:
        Turn_Over_On(wk);
        break;

    case 2:
        Jump_Attack_Term(wk, -0x7F90, -0x7FA8, 9, 0x42, 0, -0x7F68, -1, 0x400);
        break;

    case 3:
        Normal_Attack(wk, 0xB, 0x100);
        break;

    case 4:
        Wait(wk, 9);
        break;

    case 5:
        Com_Random_Select(wk, 6, 0x8A, 0x16, 0x86, 0x87, 5);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0134(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 1, 0xFFFF, 3, -1);
        break;

    case 1:
        Branch_Unit_Area(wk, 6, 0x16, 0x16, 0x17, 0x18);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0135(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;

    case 1:
        Command_Attack(wk, 0xB, 0x21, 0xA, -1);
        break;

    case 2:
        Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0136(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Turn_Over_On(wk);
        break;

    case 1:
        Jump_Attack_Term(wk, -0x7F90, -0x7FA8, 9, 0x42, 0, -0x7F68, -1, 0x400);
        break;

    case 2:
        Normal_Attack(wk, 0xB, 0x100);
        break;

    case 3:
        Wait(wk, 9);
        break;

    case 4:
        Com_Random_Select(wk, 6, 0x89, 0x86, 0x16, 0x87, 5);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0137(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Branch_Unit_Area(wk, 6, 0x16, 0x16, 0x17, 0x18);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0138(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F90, -1, 4, 6, 0x89);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1C, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0139(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, -0x7F88, -0x7FA8, 9, 0x400, 0, -0x7F68, -1, 0x400);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x102);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x202);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0140(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, -0x7F88, -0x7FA8, 9, 0x400, 0, -0x7F68, -1, 0x400);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x402);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0141(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, -0x7F88, -0x7FA8, 9, 0x400, 0, -0x7F68, -1, 0x400);
        break;

    case 1:
        Branch_Unit_Area(wk, 6, 0x16, 0x16, 0x17, 0x18);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0142(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, -0x7F88, -0x7FA8, 9, 0x400, 0, -0x7F68, -1, 0x400);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x42);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0143(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, -0x7F88, -0x7FA8, 9, 0x400, 0, -0x7F68, -1, 0x400);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x40);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0144(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, -0x7F88, -0x7FA8, 9, 0x400, 0, -0x7F68, -1, 0x400);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0145(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7F00, 0x38, 8, 0x400, 1, -1, -1, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive06_0146(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7F00, 0x38, 8, 0x200, 1, -1, -1, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void (*const Passive06_Tbl[147])(PLW*) = {
    Passive06_0000, Passive06_0001, Passive06_0002, Passive06_0003, Passive06_0004, Passive06_0005, Passive06_0006,
    Passive06_0007, Passive06_0008, Passive06_0009, Passive06_0010, Passive06_0011, Passive06_0012, Passive06_0013,
    Passive06_0014, Passive06_0015, Passive06_0016, Passive06_0017, Passive06_0018, Passive06_0019, Passive06_0020,
    Passive06_0021, Passive06_0022, Passive06_0023, Passive06_0024, Passive06_0025, Passive06_0026, Passive06_0027,
    Passive06_0028, Passive06_0029, Passive06_0030, Passive06_0031, Passive06_0032, Passive06_0033, Passive06_0034,
    Passive06_0035, Passive06_0036, Passive06_0037, Passive06_0038, Passive06_0039, Passive06_0040, Passive06_0041,
    Passive06_0042, Passive06_0043, Passive06_0044, Passive06_0045, Passive06_0046, Passive06_0047, Passive06_0048,
    Passive06_0049, Passive06_0050, Passive06_0051, Passive06_0052, Passive06_0053, Passive06_0054, Passive06_0055,
    Passive06_0056, Passive06_0057, Passive06_0058, Passive06_0059, Passive06_0060, Passive06_0061, Passive06_0062,
    Passive06_0063, Passive06_0064, Passive06_0065, Passive06_0066, Passive06_0067, Passive06_0068, Passive06_0069,
    Passive06_0070, Passive06_0071, Passive06_0072, Passive06_0073, Passive06_0074, Passive06_0075, Passive06_0076,
    Passive06_0077, Passive06_0078, Passive06_0079, Passive06_0080, Passive06_0081, Passive06_0082, Passive06_0083,
    Passive06_0084, Passive06_0085, Passive06_0086, Passive06_0087, Passive06_0088, Passive06_0089, Passive06_0090,
    Passive06_0091, Passive06_0092, Passive06_0093, Passive06_0094, Passive06_0095, Passive06_0096, Passive06_0097,
    Passive06_0098, Passive06_0099, Passive06_0100, Passive06_0101, Passive06_0102, Passive06_0103, Passive06_0104,
    Passive06_0105, Passive06_0106, Passive06_0107, Passive06_0108, Passive06_0109, Passive06_0110, Passive06_0111,
    Passive06_0112, Passive06_0113, Passive06_0114, Passive06_0115, Passive06_0116, Passive06_0117, Passive06_0118,
    Passive06_0119, Passive06_0120, Passive06_0121, Passive06_0122, Passive06_0123, Passive06_0124, Passive06_0125,
    Passive06_0126, Passive06_0127, Passive06_0128, Passive06_0129, Passive06_0130, Passive06_0131, Passive06_0132,
    Passive06_0133, Passive06_0134, Passive06_0135, Passive06_0136, Passive06_0137, Passive06_0138, Passive06_0139,
    Passive06_0140, Passive06_0141, Passive06_0142, Passive06_0143, Passive06_0144, Passive06_0145, Passive06_0146
};
