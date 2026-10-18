/* PASS02.c, retail sf33rd.xbe.
 * PlayStation 2 C, not hand-adjusted for Xbox. Each named body was located
 * from the PS2 retail map: call graph, source order, and agreement of
 * constants, field offsets, callees, and size. See docs/decompiling.md.
 * The #include lines name headers in the PS2 tree (ps2.path).
 * Passive02 0x6E5CB size 0x1A.
 * Passive02_0001 0x6E5E5 size 0x4D.
 * Passive02_0003 0x6E632 size 0x49.
 * Passive02_0009 0x6E6C4 size 0x5F.
 * Passive02_0010 0x6E723 size 0x48.
 * Passive02_0012 0x6E76B size 0x3A.
 * Passive02_0016 0x6E7A5 size 0x4F.
 * Passive02_0018 0x6E7F4 size 0x66.
 * Passive02_0021 0x6E85A size 0x4F.
 * Passive02_0023 0x6E8FC size 0x50.
 * Passive02_0024 0x6E94C size 0x52.
 * Passive02_0027 0x6E99E size 0x43.
 * Passive02_0039 0x6EA54 size 0x49.
 * Passive02_0040 0x6EA9D size 0x53.
 * Passive02_0041 0x6EAF0 size 0x5A.
 * Passive02_0043 0x6EB4A size 0x5A.
 * Passive02_0044 0x6EBA4 size 0x5B.
 * Passive02_0045 0x6EBFF size 0x3A.
 * Passive02_0047 0x6EC39 size 0x43.
 * Passive02_0049 0x6EC7C size 0x45.
 * Passive02_0050 0x6ECC1 size 0x48.
 * Passive02_0057 0x6ED09 size 0x40.
 * Passive02_0059 0x6ED49 size 0x49.
 * Passive02_0062 0x6ED92 size 0x43.
 * Passive02_0064 0x6EE17 size 0x69.
 * Passive02_0065 0x6EE80 size 0x52.
 * Passive02_0066 0x6EED2 size 0x56.
 * Passive02_0068 0x6EF28 size 0x39.
 * Passive02_0070 0x6EF61 size 0x85.
 * Passive02_0071 0x6EFE6 size 0xB5.
 * Passive02_0072 0x6F09B size 0x45.
 * Passive02_0073 0x6F0E0 size 0x68.
 * Passive02_0074 0x6F148 size 0x55.
 * Passive02_0075 0x6F19D size 0x5A.
 * Passive02_0078 0x6F1F7 size 0xD2.
 * Passive02_0080 0x6F2C9 size 0x8C.
 * Passive02_0081 0x6F355 size 0x9D.
 * Passive02_0082 0x6F3F2 size 0x8D.
 * Passive02_0083 0x6F47F size 0x3B.
 * Passive02_0084 0x6F4BA size 0x3D.
 * Passive02_0085 0x6F4F7 size 0x59.
 * Passive02_0087 0x6F550 size 0x3E.
 * Passive02_0091 0x6F679 size 0x70.
 * Passive02_0092 0x6F6E9 size 0x4D.
 * Passive02_0093 0x6F736 size 0x7A.
 * Passive02_0095 0x6F7B0 size 0x2F.
 * Passive02_0096 0x6F7DF size 0x2F.
 * Passive02_0097 0x6F80E size 0x2F.
 * Passive02_0099 0x6F86C size 0x2F.
 * Passive02_0100 0x6F89B size 0x47.
 * Passive02_0101 0x6F8E2 size 0x46.
 * Passive02_0102 0x6F928 size 0x59.
 * Passive02_0105 0x6F9CD size 0x62.
 * Passive02_0106 0x6FA2F size 0x66.
 * Passive02_0107 0x6FA95 size 0x30.
 * Passive02_0108 0x6FAC5 size 0x30.
 * Passive02_0110 0x6FAF5 size 0x3A.
 * Passive02_0111 0x6FB2F size 0x4A.
 * Passive02_0112 0x6FB79 size 0x49.
 * Passive02_0113 0x6FBC2 size 0x44.
 * Passive02_0114 0x6FC06 size 0x91.
 * Passive02_0116 0x6FC97 size 0x5A.
 * Passive02_0117 0x6FCF1 size 0x4C.
 * Passive02_0121 0x6FDCF size 0x85.
 * Passive02_0125 0x6FEA5 size 0x46.
 * Passive02_0127 0x6FEEB size 0x69.
 * Passive02_0128 0x6FF54 size 0x43.
 * Passive02_0088 is folded into 0x6F58E with 1 other bodies. Unnamed.
 * Passive02_0000 is folded into 0xD0F75 with 14 other bodies. Unnamed.
 * Passive02_0002 is folded into 0x8107D with 4 other bodies. Unnamed.
 * Passive02_0004 is folded into 0xD2718 with 15 other bodies. Unnamed.
 * Passive02_0005 is folded into 0x7F823 with 1 other bodies. Unnamed.
 * Passive02_0006 is folded into 0xE2FEC with 2 other bodies. Unnamed.
 * Passive02_0007 is folded into 0x6E67B with 1 other bodies. Unnamed.
 * Passive02_0008 is folded into 0x6E67B with 1 other bodies. Unnamed.
 * Passive02_0011 is folded into 0x7174E with 1 other bodies. Unnamed.
 * Passive02_0013 is folded into 0x742E1 with 3 other bodies. Unnamed.
 * Passive02_0014 is folded into 0xDC466 with 11 other bodies. Unnamed.
 * Passive02_0015 is folded into 0xDFCF2 with 10 other bodies. Unnamed.
 * Passive02_0017 is folded into 0x7CD4A with 1 other bodies. Unnamed.
 * Passive02_0019 is folded into 0x6D0D1 with 17 other bodies. Unnamed.
 * Passive02_0020 is folded into 0x6D236 with 17 other bodies. Unnamed.
 * Passive02_0022 is folded into 0x6E8A9 with 1 other bodies. Unnamed.
 * Passive02_0025 is folded into 0x7CEF4 with 1 other bodies. Unnamed.
 * Passive02_0026 is folded into 0xE1BAF with 5 other bodies. Unnamed.
 * Passive02_0028 is folded into 0xA9FCC with 23 other bodies. Unnamed.
 * Passive02_0029 is folded into 0xDFCF2 with 10 other bodies. Unnamed.
 * Passive02_0030 is folded into 0x6D0A6 with 21 other bodies. Unnamed.
 * Passive02_0031 is folded into 0x6E9E1 with 10 other bodies. Unnamed.
 * Passive02_0032 is folded into 0xDDB8D with 12 other bodies. Unnamed.
 * Passive02_0033 is folded into 0xDDBBA with 13 other bodies. Unnamed.
 * Passive02_0034 is folded into 0x70746 with 3 other bodies. Unnamed.
 * Passive02_0035 is folded into 0xA5879 with 6 other bodies. Unnamed.
 * Passive02_0036 is folded into 0x822AE with 19 other bodies. Unnamed.
 * Passive02_0037 is folded into 0x6EA0B with 1 other bodies. Unnamed.
 * Passive02_0038 is folded into 0x738BB with 1 other bodies. Unnamed.
 * Passive02_0042 is folded into 0xAB943 with 26 other bodies. Unnamed.
 * Passive02_0046 is folded into 0x706D9 with 9 other bodies. Unnamed.
 * Passive02_0048 is folded into 0xDE286 with 8 other bodies. Unnamed.
 * Passive02_0051 is folded into 0x73AEB with 3 other bodies. Unnamed.
 * Passive02_0052 is folded into 0xA9FF7 with 21 other bodies. Unnamed.
 * Passive02_0053 is folded into 0x7A0DC with 7 other bodies. Unnamed.
 * Passive02_0054 is folded into 0xE2326 with 9 other bodies. Unnamed.
 * Passive02_0055 is folded into 0x80F0F with 4 other bodies. Unnamed.
 * Passive02_0056 is folded into 0x71F06 with 1 other bodies. Unnamed.
 * Passive02_0058 is folded into 0xD34B4 with 10 other bodies. Unnamed.
 * Passive02_0060 is folded into 0x7EE7B with 22 other bodies. Unnamed.
 * Passive02_0061 is folded into 0x6D0D1 with 17 other bodies. Unnamed.
 * Passive02_0063 is folded into 0x6EDD5 with 1 other bodies. Unnamed.
 * Passive02_0067 is folded into 0x720E4 with 4 other bodies. Unnamed.
 * Passive02_0069 is folded into 0x7215E with 2 other bodies. Unnamed.
 * Passive02_0076 is folded into 0x74010 with 1 other bodies. Unnamed.
 * Passive02_0077 is folded into 0x74057 with 2 other bodies. Unnamed.
 * Passive02_0079 is folded into 0x8373A with 5 other bodies. Unnamed.
 * Passive02_0086 is folded into 0x843D9 with 6 other bodies. Unnamed.
 * Passive02_0089 is folded into 0x6F628 with 1 other bodies. Unnamed.
 * Passive02_0090 is folded into 0x8078E with 8 other bodies. Unnamed.
 * Passive02_0094 is folded into 0x6F83D with 1 other bodies. Unnamed.
 * Passive02_0098 is folded into 0x6F83D with 1 other bodies. Unnamed.
 * Passive02_0103 is folded into 0x6F981 with 1 other bodies. Unnamed.
 * Passive02_0104 is folded into 0x6F981 with 1 other bodies. Unnamed.
 * Passive02_0109 is folded into 0x80741 with 3 other bodies. Unnamed.
 * Passive02_0115 is folded into 0xDAC4C with 14 other bodies. Unnamed.
 * Passive02_0124 is folded into 0xA5ED3 with 1 other bodies. Unnamed.
 * Passive02_0126 is folded into 0xAB943 with 26 other bodies. Unnamed.
 * Passive02_0129 is folded into 0xE3409 with 7 other bodies. Unnamed.
 * Passive02_0130 is folded into 0xE33DD with 8 other bodies. Unnamed.
 * Passive02_0131 is folded into 0x7F083 with 1 other bodies. Unnamed.
 * Passive02_0132 is folded into 0x85442 with 1 other bodies. Unnamed.
 * Passive02_0118 is folded into 0x6FD3D with 1 other bodies. Unnamed.
 * Passive02_0119 is folded into 0x6FD86 with 1 other bodies. Unnamed.
 * Passive02_0120 is folded into 0x7EA49 with 1 other bodies. Unnamed.
 * Passive02_0122 is folded into 0x803C3 with 2 other bodies. Unnamed.
 * Passive02_0123 is folded into 0x6FE54 with 1 other bodies. Unnamed.
 */

#include "sf33rd/Source/Game/PASS02.h"
#include "common.h"
#include "sf33rd/Source/Game/Com_Sub.h"
#include "sf33rd/Source/Game/workuser.h"

void (*const Passive02_Tbl[133])();

void Passive02(PLW* wk) {
    Passive02_Tbl[(s16)Pattern_Index[wk->wu.id]](wk);
}

void Passive02_0000(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xD, M_Lv[wk->wu.id]);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0001(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x60, 1, -1);
        break;

    case 1:
        Command_Attack(wk, 8, 1, 0xB, -1);
        break;

    case 2:
        Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0002(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0003(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F88, -1, 0, 1, -1);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1C, 8, 0x70);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0004(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Provoke(wk, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0005(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1E, 0xA, 0x700);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0006(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1D, 0xA, 0x70);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0007(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F88, -1, 0, 1, -1);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1C, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0008(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F88, -1, 0, 1, -1);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1C, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0009(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F88, -1, 0, 1, -1);
        break;

    case 1:
        SA_Term(wk, 0xFFFF, 0x36, 0xFFFF, 0x47);
        break;

    case 2:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0010(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7FB0, -0x7FA8, 0, 1, -1);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x40);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0011(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA0, -0x7FD0, 8, 0x200, 0, -0x7F70, -1, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0012(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Check_BOSS(wk, 6, 0x6F);
        break;

    case 1:
        Next_Another_Menu(wk, 6, 3);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0013(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x60, 1, -1);
        break;

    case 1:
        Command_Attack(wk, 8, 1, 0xB, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0014(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        VS_Jump_Guard(wk);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0015(PLW* wk) {
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

void Passive02_0016(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;

    case 1:
        Wait_Get_Up(wk, 0, -1);
        break;

    case 2:
        Lever_Attack(wk, 8, 0, 0x110);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0017(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x7F, 2);
        break;

    case 1:
        Wait_Get_Up(wk, 0, -1);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x202);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0018(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x7F, 2);
        break;

    case 1:
        Wait_Get_Up(wk, 0, -1);
        break;

    case 2:
        EM_Term(wk, -0x7FB0, -1, 5, 6, 0x1C);
        break;

    case 3:
        Lever_Attack(wk, 8, 0, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0019(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0020(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 3, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0021(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x7F, 2);
        break;

    case 1:
        Wait_Get_Up(wk, 0, -1);
        break;

    case 2:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0022(PLW* wk) {
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

void Passive02_0023(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;

    case 1:
        Jump_Attack_Term(wk, -0x7FA0, -0x7FC8, 8, 0x40, 0, -0x7F78, -1, 0x40);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0024(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBF, 2);
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

void Passive02_0025(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 3, -1);
        break;

    case 1:
        Command_Attack(wk, 8, 0, 0xB, -1);
        break;

    case 2:
        EM_Term(wk, 0x7FFF, -1, 1, 1, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0026(PLW* wk) {
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

void Passive02_0027(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xB, 0x202);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1D, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0028(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x402);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0029(PLW* wk) {
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

void Passive02_0030(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0031(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 1, 0x20, 1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0032(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x110);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0033(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 1, 0x110);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0034(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 8, 0x10);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0035(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x102);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0036(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0037(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, -0x7FF8, 0, 1, -1);
        break;

    case 1:
        Lever_Attack(wk, 8, 0, 0x110);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0038(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, -0x7FF8, 0, 1, -1);
        break;

    case 1:
        Lever_Attack(wk, 8, 1, 0x110);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0039(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, -0x7FD0, 0, 1, -1);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1C, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0040(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;

    case 1:
        EM_Term(wk, -1, -0x7FF0, 0, 1, -1);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0041(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, -0x7FF0, 0, 6, 0x1F);
        break;

    case 1:
        Normal_Attack(wk, 9, 0x40);
        break;

    case 2:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0042(PLW* wk) {
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

void Passive02_0043(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;

    case 1:
        EM_Term(wk, -1, -0x7FD0, 0, 6, 0x1F);
        break;

    case 2:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0044(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
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

void Passive02_0045(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Check_BOSS(wk, 6, 0x70);
        break;

    case 1:
        Next_Another_Menu(wk, 6, 3);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0046(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Status(wk, 2, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0047(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xB, 0x102);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1C, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0048(PLW* wk) {
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

void Passive02_0049(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7FB0, -1, 5, 6, 0x1F);
        break;

    case 1:
        Adjust_Attack(wk, 8, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0050(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7FB0, -1, 5, 6, 0x1F);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0051(PLW* wk) {
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

void Passive02_0052(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x202);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0053(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0054(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1D, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0055(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1E, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0056(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x40, 8, 0x400, 0, -0x7F68, -1, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0057(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA0, -0x7FC8, 8, 0x100, 0, -0x7F78, -1, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0058(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Status(wk, 2, 1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0059(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7FB0, -1, 5, 6, 0x1F);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1C, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0060(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Forced_Guard(wk, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0061(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0062(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xB, 0x200);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1F, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0063(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x35, 0x36, 0xFFFF, 0x47);
        break;

    case 1:
        SA_Term(wk, 0xFFFF, 0xFFFF, 0x19, 0x3C);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0064(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x10, 2);
        break;

    case 1:
        EM_Term(wk, -1, -0x7FE8, 6, 1, -1);
        break;

    case 2:
        Normal_Attack(wk, 9, 0x40);
        break;

    case 3:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0065(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;

    case 1:
        Normal_Attack(wk, 0xB, 0x200);
        break;

    case 2:
        Command_Attack(wk, 8, 0x1F, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0066(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBF, 2);
        break;

    case 1:
        SA_Term(wk, 0x35, 0x36, 0xFFFF, 0x47);
        break;

    case 2:
        SA_Term(wk, 0xFFFF, 0xFFFF, 0x19, 0x3C);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0067(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Attack_Complete(wk, 3, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0068(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Attack_Complete(wk, 3, 1);
        break;

    case 1:
        Next_Be_Passive(wk, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0069(PLW* wk) {
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

void Passive02_0070(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x40, 2);
        break;

    case 1:
        Wait_Get_Up(wk, 0, -1);
        break;

    case 2:
        Wait(wk, 10);
        break;

    case 3:
        SA_Term(wk, 0x35, 0x36, 0xFFFF, 0x47);
        break;

    case 4:
        SA_Term(wk, 0xFFFF, 0xFFFF, 0x19, 0x3C);
        break;

    case 5:
        Wait_Get_Up(wk, 0, -1);
        break;

    case 6:
        Normal_Attack(wk, 8, 0x202);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0071(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;

    case 1:
        EM_Term(wk, -1, -0x7FF0, 0, 1, -1);
        break;

    case 2:
        ETC_Term(wk, 8, 6, 7);
        break;

    case 3:
        Check_SA(wk, 6, 7);
        break;

    case 4:
        Pierce_On(wk);
        break;

    case 5:
        Command_Attack(wk, 8, 0x8016, 10, -1);
        break;

    case 6:
        Wait(wk, 1);
        break;

    case 7:
        Command_Attack(wk, 8, 0x1D, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0072(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x35, 0xFFFF, 0xFFFF, 0);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0073(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x35, 0xFFFF, 0x37, 0);
        break;

    case 1:
        Adjust_Attack(wk, 0xB, 0x10);
        break;

    case 2:
        Normal_Attack(wk, 0xA, 0x202);
        break;

    case 3:
        Command_Attack(wk, 8, 0x1F, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0074(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x35, 0x36, 0xFFFF, 0x47);
        break;

    case 1:
        SA_Term(wk, 0xFFFF, 0xFFFF, 0x19, 0x3C);
        break;

    case 2:
        Command_Attack(wk, 8, 0x1F, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0075(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7FC0, -1, 5, 6, 0x1F);
        break;

    case 1:
        Normal_Attack(wk, 0xB, 0x12);
        break;

    case 2:
        J_Command_Attack(wk, 8, 0x1C, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0076(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7FB0, -1, 5, 6, 0x1C);
        break;

    case 1:
        Lever_Attack(wk, 8, 0, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0077(PLW* wk) {
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

void Passive02_0078(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBF, 2);
        break;

    case 1:
        Wait_Get_Up(wk, 0, -1);
        break;

    case 2:
        Check_EX(wk, 6, 0x70);
        break;

    case 3:
        Pierce_On(wk);
        break;

    case 4:
        Command_Attack(wk, 8, 0x1F, 8, 0x700);
        break;

    case 5:
        Check_BOSS_EX(wk, 1, 0xFFFF);
        break;

    case 6:
        EM_Term(wk, -0x7F58, -1, 0, 1, -1);
        break;

    case 7:
        Wait(wk, 2);
        break;

    case 8:
        J_Command_Attack(wk, 8, 0x1C, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0079(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Forced_Guard(wk, 2);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0080(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA0, -0x7FC0, 9, 0x400, 0, -0x7FB0, -1, 0x200);
        break;

    case 1:
        Normal_Attack(wk, 9, 0x42);
        break;

    case 2:
        Command_Attack(wk, 0xC, 0x1C, 0xA, -1);
        break;

    case 3:
        Wait(wk, 5);
        break;

    case 4:
        SA_Term(wk, 0x35, 0x36, 0x37, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0081(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA0, -0x7FC0, 9, 0x40, 0, -0x7FB0, -1, 0x400);
        break;

    case 1:
        Normal_Attack(wk, 9, 0x40);
        break;

    case 2:
        Command_Attack(wk, 0xC, 0x1D, 10, -1);
        break;

    case 3:
        Wait(wk, 5);
        break;

    case 4:
        SA_Term(wk, 0x35, 0x36, 0xFFFF, 0x47);
        break;

    case 5:
        SA_Term(wk, 0xFFFF, 0xFFFF, 0x19, 0x3C);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0082(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x10, 2);
        break;

    case 1:
        EM_Term(wk, -1, -0x7FF0, 6, 1, -1);
        break;

    case 2:
        Normal_Attack(wk, 9, 0x202);
        break;

    case 3:
        Command_Attack(wk, 0xC, 0x1D, 10, -1);
        break;

    case 4:
        Wait(wk, 5);
        break;

    case 5:
        SA_Term(wk, 0x35, 0x36, 0x37, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0083(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ETC_Term(wk, 4, 6, 0x2A);
        break;

    case 1:
        Provoke(wk, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0084(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, -0x7FC0, 9, 0x100, 1, -0x7FB0, -1, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0085(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x220);
        break;

    case 1:
        Normal_Attack(wk, 9, 0x102);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x202);
        break;

    case 3:
        Command_Attack(wk, 8, 0x1D, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0086(PLW* wk) {
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

void Passive02_0087(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x2E, 8, 0x700, -0x7FA0, 0x48, 0, 0x700, 0x30, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0088(PLW* wk) {
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
        Command_Attack(wk, 8, 0x1D, 10, -1);
        break;

    case 5:
        Com_Random_Select(wk, 6, 0x2D, 0xFF, 0xFF, 0xFF, 2);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0089(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;

    case 1:
        Command_Attack(wk, 8, 0, -1, -1);
        break;

    case 2:
        Branch_Unit_Area(wk, 6, 0x20, 0x3B, 0x36, 0x5A);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0090(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0091(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7FB0, -0x7FF0, 6, 1, -1);
        break;

    case 1:
        Command_Attack(wk, 0xC, 0x1D, 0xA, -1);
        break;

    case 2:
        Wait(wk, 5);
        break;

    case 3:
        SA_Term(wk, 0x35, 0xFFFF, 0x37, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0092(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, -0x7FF0, 0, 1, -1);
        break;

    case 1:
        Com_Random_Select(wk, 6, 0x60, 0x61, 0x62, 99, 1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0093(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA0, -0x7FC0, 9, 0x40, 0, -0x7FB0, -1, 0x400);
        break;

    case 1:
        Normal_Attack(wk, 9, 0x202);
        break;

    case 2:
        Command_Attack(wk, 0xC, 0x1D, 0xA, -1);
        break;

    case 3:
        Wait(wk, 5);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0094(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0xFFFF, 0xFFFF, 3, 0x3C);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0095(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0xFFFF, 0xFFFF, 0xD, 0x3B);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0096(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0xFFFF, 0xFFFF, 0xF, 0x3C);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0097(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0xFFFF, 0xFFFF, 0xF, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0098(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0xFFFF, 0xFFFF, 3, 0x3C);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0099(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0xFFFF, 0xFFFF, 0x11, 0x3C);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0100(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, -0x7FA0, 0, 2, 0);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0101(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x30, 0, 1, -1);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0102(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x30, 0, 1, -1);
        break;

    case 1:
        Jump_Attack_Term(wk, -0x7FA0, -0x7FD0, 8, 0x200, 0, -0x7F70, -1, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0103(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F88, -0x7FC0, 0, 1, -1);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1C, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0104(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F88, -0x7FC0, 0, 1, -1);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1C, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0105(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F88, -0x7FC0, 0, 1, -1);
        break;

    case 1:
        SA_Term(wk, 0xFFFF, 0x36, 0xFFFF, 0x47);
        break;

    case 2:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0106(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x60, 6, 9);
        break;

    case 1:
        Pierce_On(wk);
        break;

    case 2:
        Command_Attack(wk, 8, 1, -1, -1);
        break;

    case 3:
        Com_Random_Select(wk, 6, 0xB, 2, 0xC, 0x5A, 1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0107(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 6, 7, 0x67, 8, 0x68, 1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0108(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 6, 9, 0x69, 9, 0x69, 1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0109(PLW* wk) {
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

void Passive02_0110(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Check_BOSS(wk, 6, 0x6A);
        break;

    case 1:
        Next_Another_Menu(wk, 6, 3);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0111(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F88, -0x7FD0, 0, 2, 0);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0112(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, -0x7FF0, 0, 6, 0x1F);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1F, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0113(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Check_BOSS_EX(wk, 6, 0x72);
        break;

    case 1:
        Com_Random_Select(wk, 6, 0x4C, 0x37, 0x37, 0x30, 1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0114(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7FD0, -0x7FF0, 5, 6, 1);
        break;

    case 1:
        Normal_Attack(wk, 9, 0x20);
        break;

    case 2:
        Wait(wk, 5);
        break;

    case 3:
        SA_Term(wk, 0x35, 0x36, 0xFFFF, 0);
        break;

    case 4:
        SA_Term(wk, 0xFFFF, 0xFFFF, 0x19, 0x3C);
        break;

    case 5:
        Command_Attack(wk, 0xC, 0x1C, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0115(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump(wk, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0116(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7F90, -0x7FC0, 9, 0x400, 0, -0x7FB0, -1, 0x200);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x402);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0117(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;

    case 1:
        Jump(wk, 0);
        break;

    case 2:
        Com_Random_Select(wk, 6, 0x20, 0x21, 0x40, 0x78, 4);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0118(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, -0x7FD0, 6, 1, -1);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0119(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, -0x7FD0, 6, 1, -1);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1E, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0120(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, -0x7FD0, 6, 1, -1);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0121(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7F90, -0x7FC0, 0xB, 0x400, 0, -0x7FB0, -1, 0x20);
        break;

    case 1:
        EM_Term(wk, -1, -0x8000, 4, 1, -1);
        break;

    case 2:
        SA_Term(wk, 0x35, 0x36, 0x37, 0x7F);
        break;

    case 3:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0122(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x1E, 10, -1, -1, 0x30, 0, -1, -1, 0xFFFF);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0123(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1E, 0xA, 0x700);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x402);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0124(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Away(wk, 0xBF, 1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0125(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 1, 0x20, -1);
        break;

    case 1:
        Com_Random_Select(wk, 6, 0x36, 0x7E, 0x37, 0x6D, 3);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0126(PLW* wk) {
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

void Passive02_0127(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7F90, -0x7FC0, 9, 0x40, 0, -0x7FB0, -1, 0x200);
        break;

    case 1:
        Normal_Attack(wk, 9, 0x40);
        break;

    case 2:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0128(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x402);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0129(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0130(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1C, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0131(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, -0x7FA0, -0x7FD0, 8, 0x40, 0, -1, -1, 0xFFFF);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive02_0132(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;

    case 1:
        Command_Attack(wk, 8, 0, -1, -1);
        break;

    case 2:
        EM_Term(wk, -1, -0x7FD0, 6, 1, -1);
        break;

    case 3:
        Normal_Attack(wk, 9, 0x402);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void (*const Passive02_Tbl[133])(PLW*) = {
    Passive02_0000, Passive02_0001, Passive02_0002, Passive02_0003, Passive02_0004, Passive02_0005, Passive02_0006,
    Passive02_0007, Passive02_0008, Passive02_0009, Passive02_0010, Passive02_0011, Passive02_0012, Passive02_0013,
    Passive02_0014, Passive02_0015, Passive02_0016, Passive02_0017, Passive02_0018, Passive02_0019, Passive02_0020,
    Passive02_0021, Passive02_0022, Passive02_0023, Passive02_0024, Passive02_0025, Passive02_0026, Passive02_0027,
    Passive02_0028, Passive02_0029, Passive02_0030, Passive02_0031, Passive02_0032, Passive02_0033, Passive02_0034,
    Passive02_0035, Passive02_0036, Passive02_0037, Passive02_0038, Passive02_0039, Passive02_0040, Passive02_0041,
    Passive02_0042, Passive02_0043, Passive02_0044, Passive02_0045, Passive02_0046, Passive02_0047, Passive02_0048,
    Passive02_0049, Passive02_0050, Passive02_0051, Passive02_0052, Passive02_0053, Passive02_0054, Passive02_0055,
    Passive02_0056, Passive02_0057, Passive02_0058, Passive02_0059, Passive02_0060, Passive02_0061, Passive02_0062,
    Passive02_0063, Passive02_0064, Passive02_0065, Passive02_0066, Passive02_0067, Passive02_0068, Passive02_0069,
    Passive02_0070, Passive02_0071, Passive02_0072, Passive02_0073, Passive02_0074, Passive02_0075, Passive02_0076,
    Passive02_0077, Passive02_0078, Passive02_0079, Passive02_0080, Passive02_0081, Passive02_0082, Passive02_0083,
    Passive02_0084, Passive02_0085, Passive02_0086, Passive02_0087, Passive02_0088, Passive02_0089, Passive02_0090,
    Passive02_0091, Passive02_0092, Passive02_0093, Passive02_0094, Passive02_0095, Passive02_0096, Passive02_0097,
    Passive02_0098, Passive02_0099, Passive02_0100, Passive02_0101, Passive02_0102, Passive02_0103, Passive02_0104,
    Passive02_0105, Passive02_0106, Passive02_0107, Passive02_0108, Passive02_0109, Passive02_0110, Passive02_0111,
    Passive02_0112, Passive02_0113, Passive02_0114, Passive02_0115, Passive02_0116, Passive02_0117, Passive02_0118,
    Passive02_0119, Passive02_0120, Passive02_0121, Passive02_0122, Passive02_0123, Passive02_0124, Passive02_0125,
    Passive02_0126, Passive02_0127, Passive02_0128, Passive02_0129, Passive02_0130, Passive02_0131, Passive02_0132
};
