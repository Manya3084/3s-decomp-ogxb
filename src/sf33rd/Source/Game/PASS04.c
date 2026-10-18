/* PASS04.c, retail sf33rd.xbe.
 * PlayStation 2 C, not hand-adjusted for Xbox. Each named body was located
 * from the PS2 retail map: call graph, source order, and agreement of
 * constants, field offsets, callees, and size. See docs/decompiling.md.
 * The #include lines name headers in the PS2 tree (ps2.path).
 * Passive04_0001 0x714FD size 0x58.
 * Passive04_0004 0x71555 size 0x3A.
 * Passive04_0005 0x7158F size 0x2F.
 * Passive04_0006 0x715BE size 0x58.
 * Passive04_0007 0x71616 size 0x49.
 * Passive04_0008 0x7165F size 0x49.
 * Passive04_0009 0x716A8 size 0x5E.
 * Passive04_0010 0x71706 size 0x48.
 * Passive04_0012 0x7178E size 0x4A.
 * Passive04_0013 0x717D8 size 0x4D.
 * Passive04_0016 0x71825 size 0x4F.
 * Passive04_0017 0x71874 size 0x4C.
 * Passive04_0018 0x718C0 size 0x4F.
 * Passive04_0021 0x7190F size 0x52.
 * Passive04_0023 0x71961 size 0x50.
 * Passive04_0024 0x719B1 size 0x4F.
 * Passive04_0025 0x71A00 size 0x65.
 * Passive04_0026 0x71A65 size 0x48.
 * Passive04_0027 0x71AAD size 0x40.
 * Passive04_0029 0x71AED size 0x33.
 * Passive04_0037 0x71B5D size 0x5A.
 * Passive04_0038 0x71BB7 size 0x57.
 * Passive04_0039 0x71C0E size 0x5A.
 * Passive04_0040 0x71C68 size 0x61.
 * Passive04_0041 0x71CC9 size 0x69.
 * Passive04_0043 0x71D32 size 0x49.
 * Passive04_0044 0x71D7B size 0x5B.
 * Passive04_0047 0x71DD6 size 0x43.
 * Passive04_0048 0x71E19 size 0x38.
 * Passive04_0052 0x71EA1 size 0x3D.
 * Passive04_0057 0x71F40 size 0x40.
 * Passive04_0062 0x71F80 size 0x43.
 * Passive04_0063 0x71FC3 size 0x55.
 * Passive04_0064 0x72018 size 0x4F.
 * Passive04_0065 0x72067 size 0x3D.
 * Passive04_0066 0x720A4 size 0x40.
 * Passive04_0068 0x7210C size 0x52.
 * Passive04_0070 0x721A7 size 0x63.
 * Passive04_0071 0x7220A size 0x61.
 * Passive04_0072 0x7226B size 0x3F.
 * Passive04_0073 0x722AA size 0x43.
 * Passive04_0074 0x722ED size 0x5B.
 * Passive04_0075 0x72348 size 0x5A.
 * Passive04_0076 0x723A2 size 0x4A.
 * Passive04_0079 0x72429 size 0x40.
 * Passive04_0080 0x72469 size 0x43.
 * Passive04_0081 0x724AC size 0x40.
 * Passive04_0082 0x724EC size 0x47.
 * Passive04_0083 0x72533 size 0x4A.
 * Passive04_0084 0x7257D size 0x4A.
 * Passive04_0085 0x725C7 size 0x4A.
 * Passive04_0086 0x72611 size 0x4A.
 * Passive04_0087 0x7265B size 0x3F.
 * Passive04_0089 0x7269A size 0x49.
 * Passive04_0092 0x72741 size 0x2F.
 * Passive04_0094 0x72770 size 0x4E.
 * Passive04_0095 0x727BE size 0x4B.
 * Passive04_0096 0x72809 size 0x60.
 * Passive04_0097 0x72869 size 0x3D.
 * Passive04_0098 0x728A6 size 0x5A.
 * Passive04_0099 0x72900 size 0x49.
 * Passive04_0101 0x72949 size 0x40.
 * Passive04_0102 0x72989 size 0x5C.
 * Passive04_0103 0x729E5 size 0x5F.
 * Passive04_0104 0x72A44 size 0x43.
 * Passive04_0105 0x72A87 size 0x40.
 * Passive04_0106 0x72AC7 size 0x4F.
 * Passive04_0107 0x72B16 size 0x52.
 * Passive04_0108 0x72B68 size 0x56.
 * Passive04_0110 0x72BBE size 0x57.
 * Passive04_0111 0x72C15 size 0x57.
 * Passive04_0112 0x72C6C size 0x6C.
 * Passive04_0113 0x72CD8 size 0x68.
 * Passive04_0114 0x72D40 size 0x4D.
 * Passive04_0115 0x72D8D size 0x2B.
 * Passive04_0116 0x72DB8 size 0x62.
 * Passive04_0118 0x72E1A size 0x3A.
 * Passive04_0119 0x72E54 size 0x4E.
 * Passive04_0120 0x72EA2 size 0x53.
 * Passive04_0121 0x72EF5 size 0x31.
 * Passive04_0125 0x72F26 size 0x2F.
 * Passive04_0126 0x72F55 size 0x2F.
 * Passive04_0127 0x72F84 size 0x45.
 * Passive04_0128 0x72FC9 size 0x45.
 * Passive04_0129 0x7300E size 0x49.
 * Passive04_0130 0x73057 size 0x48.
 * Passive04_0131 0x7309F size 0x4B.
 * Passive04_0132 0x730EA size 0x49.
 * Passive04_0133 0x73133 size 0x5B.
 * Passive04_0134 0x7318E size 0x49.
 * Passive04_0135 0x731D7 size 0x49.
 * Passive04_0139 0x7324C size 0x54.
 * Passive04_0140 0x732A0 size 0x66.
 * Passive04_0141 0x73306 size 0x7B.
 * Passive04_0000 is folded into 0xD0F75 with 14 other bodies. Unnamed.
 * Passive04_0002 is folded into 0x85416 with 5 other bodies. Unnamed.
 * Passive04_0003 is folded into 0x1C045 with 4 other bodies. Unnamed.
 * Passive04_0011 is folded into 0x7174E with 1 other bodies. Unnamed.
 * Passive04_0014 is folded into 0xDC466 with 11 other bodies. Unnamed.
 * Passive04_0015 is folded into 0xDFCF2 with 10 other bodies. Unnamed.
 * Passive04_0019 is folded into 0x6D236 with 17 other bodies. Unnamed.
 * Passive04_0020 is folded into 0x6D236 with 17 other bodies. Unnamed.
 * Passive04_0022 is folded into 0x6E8A9 with 1 other bodies. Unnamed.
 * Passive04_0028 is folded into 0xA9FF7 with 21 other bodies. Unnamed.
 * Passive04_0030 is folded into 0xA9FCC with 23 other bodies. Unnamed.
 * Passive04_0031 is folded into 0x6E9E1 with 10 other bodies. Unnamed.
 * Passive04_0032 is folded into 0xA024B with 1 other bodies. Unnamed.
 * Passive04_0033 is folded into 0x71B20 with 1 other bodies. Unnamed.
 * Passive04_0034 is folded into 0x71E51 with 1 other bodies. Unnamed.
 * Passive04_0035 is folded into 0xA5879 with 6 other bodies. Unnamed.
 * Passive04_0036 is folded into 0x822AE with 19 other bodies. Unnamed.
 * Passive04_0042 is folded into 0xAB943 with 26 other bodies. Unnamed.
 * Passive04_0045 is folded into 0x6E340 with 5 other bodies. Unnamed.
 * Passive04_0046 is folded into 0x706D9 with 9 other bodies. Unnamed.
 * Passive04_0049 is folded into 0x71E51 with 1 other bodies. Unnamed.
 * Passive04_0050 is folded into 0x71E79 with 17 other bodies. Unnamed.
 * Passive04_0051 is folded into 0x73AEB with 3 other bodies. Unnamed.
 * Passive04_0053 is folded into 0x9E572 with 6 other bodies. Unnamed.
 * Passive04_0054 is folded into 0x71EDE with 7 other bodies. Unnamed.
 * Passive04_0055 is folded into 0xA9FA1 with 15 other bodies. Unnamed.
 * Passive04_0056 is folded into 0x71F06 with 1 other bodies. Unnamed.
 * Passive04_0058 is folded into 0xD34B4 with 10 other bodies. Unnamed.
 * Passive04_0059 is folded into 0xE33DD with 8 other bodies. Unnamed.
 * Passive04_0060 is folded into 0x7EE7B with 22 other bodies. Unnamed.
 * Passive04_0061 is folded into 0x6D0D1 with 17 other bodies. Unnamed.
 * Passive04_0067 is folded into 0x720E4 with 4 other bodies. Unnamed.
 * Passive04_0069 is folded into 0x7215E with 2 other bodies. Unnamed.
 * Passive04_0077 is folded into 0x74057 with 2 other bodies. Unnamed.
 * Passive04_0088 is folded into 0xA9BB4 with 14 other bodies. Unnamed.
 * Passive04_0090 is folded into 0x726E3 with 1 other bodies. Unnamed.
 * Passive04_0091 is folded into 0x72712 with 1 other bodies. Unnamed.
 * Passive04_0093 is folded into 0xE1C20 with 9 other bodies. Unnamed.
 * Passive04_0100 is folded into 0xD2718 with 15 other bodies. Unnamed.
 * Passive04_0109 is folded into 0x9E903 with 3 other bodies. Unnamed.
 * Passive04_0117 is folded into 0xDC346 with 9 other bodies. Unnamed.
 * Passive04_0122 is folded into 0xA9FF7 with 21 other bodies. Unnamed.
 * Passive04_0123 is folded into 0x72712 with 1 other bodies. Unnamed.
 * Passive04_0124 is folded into 0x726E3 with 1 other bodies. Unnamed.
 * Passive04_0136 is folded into 0xDAC4C with 14 other bodies. Unnamed.
 * Passive04_0137 is folded into 0x73220 with 1 other bodies. Unnamed.
 * Passive04_0138 is folded into 0xA071D with 1 other bodies. Unnamed.
 * The other functions in this file are not located in sf33rd.xbe yet.
 */

#include "sf33rd/Source/Game/PASS04.h"
#include "common.h"
#include "sf33rd/Source/Game/Com_Sub.h"
#include "sf33rd/Source/Game/workuser.h"

void (*const Passive04_Tbl[142])();

void Passive04(PLW* wk) {
    Passive04_Tbl[(s16)Pattern_Index[wk->wu.id]](wk);
}

void Passive04_0000(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xD, M_Lv[wk->wu.id]);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0001(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x30, 6, 0x58);
        break;

    case 1:
        Pierce_On(wk);
        break;

    case 2:
        Command_Attack(wk, 8, 1, 0xB, -1);
        break;

    case 3:
        Command_Attack(wk, 8, 0x1F, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0002(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1F, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0003(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1F, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0004(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0, -1, -1);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1F, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0005(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 0xD, 0x20, 0x30A, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0006(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x30, 6, 0x58);
        break;

    case 1:
        Pierce_On(wk);
        break;

    case 2:
        Command_Attack(wk, 8, 1, 0xB, -1);
        break;

    case 3:
        Command_Attack(wk, 8, 0x1F, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0007(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F98, -1, 0, 1, -1);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1C, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0008(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F98, -1, 0, 1, -1);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1C, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0009(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F98, -1, 0, 1, -1);
        break;

    case 1:
        SA_Term(wk, 0x35, 0xFFFF, 0xFFFF, 0);
        break;

    case 2:
        J_Command_Attack(wk, 8, 0x1C, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0010(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7FD0, -0x7FC0, 0, 1, -1);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x40);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0011(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA0, -0x7FD0, 8, 0x200, 0, -0x7F70, -1, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0012(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F90, 0, 0, 2, 0);
        break;

    case 1:
        Command_Attack(wk, 0xD, 0x20, 0x60A, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0013(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x30, 6, 0x58);
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

void Passive04_0014(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        VS_Jump_Guard(wk);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0015(PLW* wk) {
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

void Passive04_0016(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;

    case 1:
        Wait_Get_Up(wk, 0, -1);
        break;

    case 2:
        Lever_Attack(wk, 0xD, 0, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0017(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;

    case 1:
        Wait_Get_Up(wk, 0, -1);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x402);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0018(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;

    case 1:
        Wait_Get_Up(wk, 0, -1);
        break;

    case 2:
        Lever_Attack(wk, 8, 0, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0019(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 3, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0020(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 3, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0021(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x9F, 2);
        break;

    case 1:
        Wait_Get_Up(wk, 0, -1);
        break;

    case 2:
        Command_Attack(wk, 8, 0x1F, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0022(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;

    case 1:
        Jump_Attack_Term(wk, -0x7F90, -0x7FC0, 8, 0x400, 0, -0x7F68, -1, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0023(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;

    case 1:
        Jump_Attack_Term(wk, -0x7FA0, -0x7FC0, 8, 0x40, 0, -0x7F78, -1, 0x40);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0024(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xDF, 2);
        break;

    case 1:
        Wait_Get_Up(wk, 0, -1);
        break;

    case 2:
        Lever_Attack(wk, 8, 0, 0x40);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0025(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;

    case 1:
        Wait_Get_Up(wk, 3, -1);
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

void Passive04_0026(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x9F, 2);
        break;

    case 1:
        EM_Term(wk, 0x7FFF, -1, 1, 1, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0027(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x22);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1F, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0028(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x202);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0029(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x10);
        break;

    case 1:
        Lever_Attack(wk, 8, 0, 0x10);
        break;

    case 2:
        Lever_Attack(wk, 8, 0, 0x10);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0030(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x402);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0031(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 1, 0x20, 1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0032(PLW* wk) {
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

void Passive04_0033(PLW* wk) {
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

void Passive04_0034(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 8, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0035(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x102);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0036(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0037(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;

    case 1:
        EM_Term(wk, -1, -0x7FF8, 0, 1, -1);
        break;

    case 2:
        Lever_Attack(wk, 8, 0, 0x110);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0038(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;

    case 1:
        EM_Term(wk, -1, -0x7FF8, 0, 1, -1);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x110);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0039(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;

    case 1:
        EM_Term(wk, -1, -0x7FE0, 0, 1, -1);
        break;

    case 2:
        J_Command_Attack(wk, 8, 0x1C, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0040(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;

    case 1:
        EM_Term(wk, -1, -0x7FF0, 0, 1, -1);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x10);
        break;

    case 3:
        Normal_Attack(wk, 8, 0x10);
        break;

    case 4:
        Normal_Attack(wk, 8, 0x10);
        break;

    case 5:
        Normal_Attack(wk, 8, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0041(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;

    case 1:
        EM_Term(wk, -1, -0x7FE8, 0, 1, -1);
        break;

    case 2:
        Normal_Attack(wk, 9, 0x20);
        break;

    case 3:
        J_Command_Attack(wk, 8, 0x1C, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0042(PLW* wk) {
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

void Passive04_0043(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, -0x7FD8, 0, 1, -1);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1C, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0044(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;

    case 1:
        EM_Term(wk, -1, -0x7FF8, 3, 1, -1);
        break;

    case 2:
        Lever_Attack(wk, 8, 0, 0x110);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0045(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x40);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0046(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Status(wk, 2, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0047(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xB, 0x102);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1C, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0048(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x102);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x202);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0049(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 8, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0050(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x40);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0051(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x12);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x12);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0052(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x202);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0053(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0054(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x22);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0055(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0056(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x40, 8, 0x400, 0, -0x7F68, -1, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0057(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA0, -0x7FC0, 8, 0x100, 0, -0x7F78, -1, 0x40);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0058(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Status(wk, 2, 1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0059(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1C, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0060(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Forced_Guard(wk, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0061(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0062(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xB, 0x20);
        break;

    case 1:
        Command_Attack(wk, 0xD, 0x20, 0x60A, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0063(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0xFFFF, 0x36, 0x37, 0);
        break;

    case 1:
        Approach_Walk(wk, 0x9F, 2);
        break;

    case 2:
        SA_Term(wk, 0x35, 0xFFFF, 0xFFFF, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0064(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;

    case 1:
        Normal_Attack(wk, 0xB, 0x20);
        break;

    case 2:
        J_Command_Attack(wk, 8, 0x1C, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0065(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;

    case 1:
        Normal_Attack(wk, 0xD, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0066(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;

    case 1:
        SA_Term(wk, 0x35, 0x36, 0x37, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0067(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Attack_Complete(wk, 3, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0068(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xDF, 2);
        break;

    case 1:
        Wait_Get_Up(wk, 0, -1);
        break;

    case 2:
        Command_Attack(wk, 8, 0x1F, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0069(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Attack_Complete(wk, 3, 1);
        break;

    case 1:
        SA_Term(wk, 0x35, 0xFFFF, 0x37, 0);
        break;

    case 2:
        Wait_Attack_Complete(wk, 3, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0070(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x9F, 2);
        break;

    case 1:
        Wait_Get_Up(wk, 0, -1);
        break;

    case 2:
        SA_Term(wk, 0x35, 0x36, 0x37, 0);
        break;

    case 3:
        Normal_Attack(wk, 8, 0x202);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0071(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7FB0, -0x7FF0, 0, 1, -1);
        break;

    case 1:
        SA_Term(wk, 0xFFFF, 0x36, 0xFFFF, 0);
        break;

    case 2:
        Command_Attack(wk, 8, 0x1F, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0072(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x35, 0xFFFF, 0x37, 0);
        break;

    case 1:
        Forced_Guard(wk, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0073(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x35, 0xFFFF, 0x37, 0);
        break;

    case 1:
        Normal_Attack(wk, 0xD, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0074(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0xFFFF, 0x36, 0x37, 0);
        break;

    case 1:
        SA_Term(wk, 0x35, 0xFFFF, 0xFFFF, 0x9F);
        break;

    case 2:
        Command_Attack(wk, 0xD, 0x20, 0x30A, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0075(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7FC0, -1, 5, 6, 0x1F);
        break;

    case 1:
        Normal_Attack(wk, 9, 0x22);
        break;

    case 2:
        Command_Attack(wk, 8, 0x1F, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0076(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7FB0, -1, 5, 6, 0x1C);
        break;

    case 1:
        Lever_Attack(wk, 8, 0, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0077(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Attack_Complete(wk, 3, 1);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x402);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0078(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x402);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0079(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1F, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0080(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;

    case 1:
        Command_Attack(wk, 0xD, 0x20, 0x30A, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0081(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;

    case 1:
        Command_Attack(wk, 8, 0x20, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0082(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x35, 0xFFFF, 0x37, 0);
        break;

    case 1:
        Lever_Attack(wk, 0xD, 0, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0083(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F90, 0, 0, 2, 0);
        break;

    case 1:
        Command_Attack(wk, 0xD, 0x20, 0x609, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0084(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7FB0, 0, 0, 2, 0);
        break;

    case 1:
        Command_Attack(wk, 0xD, 0x20, 0x608, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0085(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F90, 0, 0, 2, 0);
        break;

    case 1:
        Command_Attack(wk, 0xD, 0x20, 0x309, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0086(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7FB0, 0, 0, 2, 0);
        break;

    case 1:
        Command_Attack(wk, 0xD, 0x20, 0x308, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0087(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0xFFFF, 0xFFFF, 0x37, 0);
        break;

    case 1:
        Forced_Guard(wk, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0088(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x42);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0089(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Attack_Complete(wk, 3, 1);
        break;

    case 1:
        SA_Term(wk, 0xFFFF, 0x36, 0x37, 0);
        break;

    case 2:
        Wait_Attack_Complete(wk, 3, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0090(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 0xD, 0x20, 0x608, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0091(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 0xD, 0x20, 0x609, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0092(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 0xD, 0x20, 0x60A, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0093(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1C, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0094(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7FC0, -0x7FF0, 6, 1, -1);
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

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0095(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7FB0, -0x7FC0, 0, 1, -1);
        break;

    case 1:
        Normal_Attack(wk, 0xB, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0096(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7FB0, -0x7FC0, 0, 1, -1);
        break;

    case 1:
        Normal_Attack(wk, 0xB, 0x202);
        break;

    case 2:
        J_Command_Attack(wk, 8, 0x1C, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0097(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x47, 2);
        break;

    case 1:
        Normal_Attack(wk, 0xB, 0x202);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0098(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Check_EX(wk, 6, 8);
        break;

    case 1:
        EM_Term(wk, -0x7FA0, -1, 0, 1, -1);
        break;

    case 2:
        J_Command_Attack(wk, 8, 0x1C, 9, 0x70);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0099(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, -0x7FD8, 0, 1, -1);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1C, 10, 0x70);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0100(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Provoke(wk, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0101(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x7F, 2);
        break;

    case 1:
        Command_Attack(wk, 8, 0x21, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0102(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7FA0, -1, 0, 1, -1);
        break;

    case 1:
        Search_Back_Term(wk, 0x30, 6, 0x6D);
        break;

    case 2:
        Command_Attack(wk, 8, 0x21, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0103(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7FA0, -1, 0, 1, -1);
        break;

    case 1:
        Search_Back_Term(wk, 0x30, 6, 0x6D);
        break;

    case 2:
        Command_Attack(wk, 8, 0x21, 9, 0x700);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0104(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x7F, 2);
        break;

    case 1:
        Command_Attack(wk, 8, 0x21, 10, 0x700);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0105(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;

    case 1:
        Command_Attack(wk, 8, 0x21, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0106(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x7F, 2);
        break;

    case 1:
        Wait_Get_Up(wk, 0, -1);
        break;

    case 2:
        Command_Attack(wk, 8, 0x21, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0107(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x7F, 2);
        break;

    case 1:
        Wait_Get_Up(wk, 0, -1);
        break;

    case 2:
        Command_Attack(wk, 8, 0x21, 10, 0x700);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0108(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 2);
        break;

    case 1:
        EM_Term(wk, -0x7FA0, -1, 0, 1, -1);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0109(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x20, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0110(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 2);
        break;

    case 1:
        EM_Term(wk, -0x7F98, -1, 0, 1, -1);
        break;

    case 2:
        J_Command_Attack(wk, 8, 0x1C, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0111(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 2);
        break;

    case 1:
        EM_Term(wk, -0x7F98, -1, 0, 1, -1);
        break;

    case 2:
        J_Command_Attack(wk, 8, 0x1C, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0112(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 2);
        break;

    case 1:
        EM_Term(wk, -0x7F98, -1, 0, 1, -1);
        break;

    case 2:
        SA_Term(wk, 0x35, 0xFFFF, 0xFFFF, 0);
        break;

    case 3:
        J_Command_Attack(wk, 8, 0x1C, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0113(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 2);
        break;

    case 1:
        Check_EX(wk, 6, 0x6F);
        break;

    case 2:
        EM_Term(wk, -0x7F98, -1, 0, 1, -1);
        break;

    case 3:
        J_Command_Attack(wk, 8, 0x1C, 9, 0x70);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0114(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x30, 6, 0x33);
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

void Passive04_0115(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Away(wk, 0xDF, 2);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0116(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7FB0, -0x7FF0, 5, 1, -1);
        break;

    case 1:
        SA_Term(wk, 0xFFFF, 0x36, 0xFFFF, 0);
        break;

    case 2:
        Command_Attack(wk, 8, 0x1F, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0117(PLW* wk) {
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

void Passive04_0118(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FB0, -1, 8, 0x400, 1, -1, 0x20, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0119(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FB0, -0x7FB0, 8, 0x40, 2, -1, -0x7FB0, 0x40);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1C, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0120(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FB0, -0x7FB0, 8, 0x40, 2, -1, -0x7FB0, 0x40);
        break;

    case 1:
        Normal_Attack(wk, 0xB, 0x20);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x40);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0121(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x12);
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

void Passive04_0122(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x202);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0123(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 0xD, 0x20, 0x609, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0124(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 0xD, 0x20, 0x608, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0125(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 0xD, 0x20, 0x309, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0126(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 0xD, 0x20, 0x308, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0127(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F90, -1, 0, 1, -1);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0128(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F90, -1, 0, 1, -1);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x22);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0129(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F90, -1, 0, 1, -1);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1C, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0130(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F80, -1, 0, 1, -1);
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

void Passive04_0131(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F80, -1, 0, 1, -1);
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

void Passive04_0132(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F90, -1, 0, 1, -1);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1C, 9, 0x70);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0133(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F90, -1, 0, 1, -1);
        break;

    case 1:
        SA_Term(wk, 0x35, 0x36, 0x37, 0);
        break;

    case 2:
        J_Command_Attack(wk, 8, 0x1C, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0134(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F80, -1, 0, 1, -1);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1C, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0135(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F80, -1, 0, 1, -1);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1C, 9, 0x70);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0136(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump(wk, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0137(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x21, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0138(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x21, 10, 0x700);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0139(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xB3, 2);
        break;

    case 1:
        Hi_Jump_Attack_Term(wk, -0x7FA0, -0x7FA0, 8, 0x400, 0, -0x7F78, -1, 0x40);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0140(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xB3, 2);
        break;

    case 1:
        Hi_Jump_Attack_Term(wk, -0x7FA0, -0x7FA0, 8, 0x400, 0, -0x7F78, -1, 0x40);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive04_0141(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xB3, 2);
        break;

    case 1:
        Hi_Jump_Attack_Term(wk, -0x7FA0, -0x7FA0, 8, 0x400, 0, -0x7F78, -1, 0x40);
        break;

    case 2:
        SA_Term(wk, 0x35, 0x36, 0x37, 0);
        break;

    case 3:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void (*const Passive04_Tbl[142])(PLW*) = {
    Passive04_0000, Passive04_0001, Passive04_0002, Passive04_0003, Passive04_0004, Passive04_0005, Passive04_0006,
    Passive04_0007, Passive04_0008, Passive04_0009, Passive04_0010, Passive04_0011, Passive04_0012, Passive04_0013,
    Passive04_0014, Passive04_0015, Passive04_0016, Passive04_0017, Passive04_0018, Passive04_0019, Passive04_0020,
    Passive04_0021, Passive04_0022, Passive04_0023, Passive04_0024, Passive04_0025, Passive04_0026, Passive04_0027,
    Passive04_0028, Passive04_0029, Passive04_0030, Passive04_0031, Passive04_0032, Passive04_0033, Passive04_0034,
    Passive04_0035, Passive04_0036, Passive04_0037, Passive04_0038, Passive04_0039, Passive04_0040, Passive04_0041,
    Passive04_0042, Passive04_0043, Passive04_0044, Passive04_0045, Passive04_0046, Passive04_0047, Passive04_0048,
    Passive04_0049, Passive04_0050, Passive04_0051, Passive04_0052, Passive04_0053, Passive04_0054, Passive04_0055,
    Passive04_0056, Passive04_0057, Passive04_0058, Passive04_0059, Passive04_0060, Passive04_0061, Passive04_0062,
    Passive04_0063, Passive04_0064, Passive04_0065, Passive04_0066, Passive04_0067, Passive04_0068, Passive04_0069,
    Passive04_0070, Passive04_0071, Passive04_0072, Passive04_0073, Passive04_0074, Passive04_0075, Passive04_0076,
    Passive04_0077, Passive04_0078, Passive04_0079, Passive04_0080, Passive04_0081, Passive04_0082, Passive04_0083,
    Passive04_0084, Passive04_0085, Passive04_0086, Passive04_0087, Passive04_0088, Passive04_0089, Passive04_0090,
    Passive04_0091, Passive04_0092, Passive04_0093, Passive04_0094, Passive04_0095, Passive04_0096, Passive04_0097,
    Passive04_0098, Passive04_0099, Passive04_0100, Passive04_0101, Passive04_0102, Passive04_0103, Passive04_0104,
    Passive04_0105, Passive04_0106, Passive04_0107, Passive04_0108, Passive04_0109, Passive04_0110, Passive04_0111,
    Passive04_0112, Passive04_0113, Passive04_0114, Passive04_0115, Passive04_0116, Passive04_0117, Passive04_0118,
    Passive04_0119, Passive04_0120, Passive04_0121, Passive04_0122, Passive04_0123, Passive04_0124, Passive04_0125,
    Passive04_0126, Passive04_0127, Passive04_0128, Passive04_0129, Passive04_0130, Passive04_0131, Passive04_0132,
    Passive04_0133, Passive04_0134, Passive04_0135, Passive04_0136, Passive04_0137, Passive04_0138, Passive04_0139,
    Passive04_0140, Passive04_0141
};
