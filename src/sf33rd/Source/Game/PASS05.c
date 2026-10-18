/* PASS05.c, retail sf33rd.xbe.
 * PlayStation 2 C, not hand-adjusted for Xbox. Each named body was located
 * from the PS2 retail map: call graph, source order, and agreement of
 * constants, field offsets, callees, and size. See docs/decompiling.md.
 * The #include lines name headers in the PS2 tree (ps2.path).
 * Passive05_0000 is folded into 0xD0F75 with 14 other bodies. Unnamed.
 * Passive05_0001 is folded into 0xD2718 with 15 other bodies. Unnamed.
 * Passive05_0002 is folded into 0x7A0DC with 7 other bodies. Unnamed.
 * Passive05_0003 is folded into 0x80F0F with 4 other bodies. Unnamed.
 * Passive05_0005 is folded into 0xE19B6 with 6 other bodies. Unnamed.
 * Passive05_0006 is folded into 0xAB943 with 26 other bodies. Unnamed.
 * Passive05_0007 is folded into 0x733C7 with 1 other bodies. Unnamed.
 * Passive05_0008 is folded into 0x733C7 with 1 other bodies. Unnamed.
 * Passive05_0013 is folded into 0x742E1 with 3 other bodies. Unnamed.
 * Passive05_0014 is folded into 0xDC466 with 11 other bodies. Unnamed.
 * Passive05_0015 is folded into 0xA5181 with 4 other bodies. Unnamed.
 * Passive05_0019 is folded into 0x6D0D1 with 17 other bodies. Unnamed.
 * Passive05_0020 is folded into 0x6D236 with 17 other bodies. Unnamed.
 * Passive05_0027 is folded into 0x73805 with 1 other bodies. Unnamed.
 * Passive05_0030 is folded into 0x6D0A6 with 21 other bodies. Unnamed.
 * Passive05_0031 is folded into 0x6E9E1 with 10 other bodies. Unnamed.
 * Passive05_0032 is folded into 0xDDB8D with 12 other bodies. Unnamed.
 * Passive05_0033 is folded into 0xDDBBA with 13 other bodies. Unnamed.
 * Passive05_0034 is folded into 0x70746 with 3 other bodies. Unnamed.
 * Passive05_0035 is folded into 0xA5879 with 6 other bodies. Unnamed.
 * Passive05_0036 is folded into 0x822AE with 19 other bodies. Unnamed.
 * Passive05_0037 is folded into 0x6EA0B with 1 other bodies. Unnamed.
 * Passive05_0038 is folded into 0x738BB with 1 other bodies. Unnamed.
 * Passive05_0042 is folded into 0xAB943 with 26 other bodies. Unnamed.
 * Passive05_0045 is folded into 0x6D0A6 with 21 other bodies. Unnamed.
 * Passive05_0046 is folded into 0x706D9 with 9 other bodies. Unnamed.
 * Passive05_0048 is folded into 0xA9FCC with 23 other bodies. Unnamed.
 * Passive05_0049 is folded into 0x73AC3 with 3 other bodies. Unnamed.
 * Passive05_0050 is folded into 0xA9FA1 with 15 other bodies. Unnamed.
 * Passive05_0051 is folded into 0x73AEB with 3 other bodies. Unnamed.
 * Passive05_0052 is folded into 0xA9FF7 with 21 other bodies. Unnamed.
 * Passive05_0053 is folded into 0x9FB5D with 8 other bodies. Unnamed.
 * Passive05_0055 is folded into 0x9FBB5 with 9 other bodies. Unnamed.
 * Passive05_0058 is folded into 0xD34B4 with 10 other bodies. Unnamed.
 * Passive05_0060 is folded into 0x7EE7B with 22 other bodies. Unnamed.
 * Passive05_0061 is folded into 0x6D0D1 with 17 other bodies. Unnamed.
 * Passive05_0063 is folded into 0x73C73 with 1 other bodies. Unnamed.
 * Passive05_0067 is folded into 0x720E4 with 4 other bodies. Unnamed.
 * Passive05_0069 is folded into 0x7215E with 2 other bodies. Unnamed.
 * Passive05_0076 is folded into 0x74010 with 1 other bodies. Unnamed.
 * Passive05_0077 is folded into 0x74057 with 2 other bodies. Unnamed.
 * Passive05_0078 is folded into 0x74094 with 1 other bodies. Unnamed.
 * Passive05_0079 is folded into 0x8373A with 5 other bodies. Unnamed.
 * Passive05_0080 is folded into 0x991B2 with 7 other bodies. Unnamed.
 * Passive05_0083 is folded into 0x741D3 with 2 other bodies. Unnamed.
 * Passive05_0088 is folded into 0x742E1 with 3 other bodies. Unnamed.
 * Passive05_0092 is folded into 0x98CDD with 1 other bodies. Unnamed.
 * Passive05_0099 is folded into 0xDAC4C with 14 other bodies. Unnamed.
 * Passive05_0101 is folded into 0x71EDE with 7 other bodies. Unnamed.
 * Passive05_0087 is folded into 0x710D9 with 1 other bodies. Unnamed.
 * Passive05_0004 is folded into 0x7339B with 1 other bodies. Unnamed.
 * Passive05 0x73381 size 0x1A.
 * Passive05_0009 0x73413 size 0x61.
 * Passive05_0010 0x73474 size 0x48.
 * Passive05_0011 0x734BC size 0x48.
 * Passive05_0012 0x73504 size 0x48.
 * Passive05_0016 0x7354C size 0x4F.
 * Passive05_0017 0x7359B size 0x4C.
 * Passive05_0018 0x735E7 size 0x4F.
 * Passive05_0021 0x73636 size 0x4F.
 * Passive05_0022 0x73685 size 0x50.
 * Passive05_0023 0x736D5 size 0x50.
 * Passive05_0024 0x73725 size 0x52.
 * Passive05_0025 0x73777 size 0x49.
 * Passive05_0026 0x737C0 size 0x45.
 * Passive05_0028 0x73848 size 0x49.
 * Passive05_0029 0x73891 size 0x2A.
 * Passive05_0039 0x73905 size 0x48.
 * Passive05_0040 0x7394D size 0x49.
 * Passive05_0041 0x73996 size 0x43.
 * Passive05_0043 0x739D9 size 0x4C.
 * Passive05_0044 0x73A25 size 0x5B.
 * Passive05_0047 0x73A80 size 0x43.
 * Passive05_0054 0x73B19 size 0x49.
 * Passive05_0056 0x73B62 size 0x4C.
 * Passive05_0057 0x73BAE size 0x3A.
 * Passive05_0059 0x73BE8 size 0x4F.
 * Passive05_0062 0x73C37 size 0x3C.
 * Passive05_0064 0x73C9F size 0x4F.
 * Passive05_0065 0x73CEE size 0x52.
 * Passive05_0066 0x73D40 size 0x43.
 * Passive05_0068 0x73D83 size 0x28.
 * Passive05_0070 0x73DAB size 0x64.
 * Passive05_0071 0x73E0F size 0x62.
 * Passive05_0072 0x73E71 size 0x5C.
 * Passive05_0073 0x73ECD size 0x79.
 * Passive05_0074 0x73F46 size 0x62.
 * Passive05_0075 0x73FA8 size 0x68.
 * Passive05_0081 0x740D1 size 0x83.
 * Passive05_0082 0x74154 size 0x7F.
 * Passive05_0084 0x741F8 size 0x3D.
 * Passive05_0085 0x74235 size 0x4B.
 * Passive05_0086 0x74280 size 0x61.
 * Passive05_0089 0x74323 size 0x2B.
 * Passive05_0090 0x7434E size 0x3A.
 * Passive05_0091 0x74388 size 0x59.
 * Passive05_0093 0x743E1 size 0x3D.
 * Passive05_0094 0x7441E size 0x42.
 * Passive05_0095 0x74460 size 0x49.
 * Passive05_0096 0x744A9 size 0x48.
 * Passive05_0097 0x744F1 size 0x28.
 * Passive05_0098 0x74519 size 0x2C.
 * Passive05_0100 0x74545 size 0x48.
 * The other functions in this file are not located in sf33rd.xbe yet.
 */

#include "sf33rd/Source/Game/PASS05.h"
#include "common.h"
#include "sf33rd/Source/Game/Com_Sub.h"
#include "sf33rd/Source/Game/workuser.h"

void (*const Passive05_Tbl[102])();

void Passive05(PLW* wk) {
    Passive05_Tbl[(s16)Pattern_Index[wk->wu.id]](wk);
}

void Passive05_0000(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xD, M_Lv[wk->wu.id]);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive05_0001(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Provoke(wk, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive05_0002(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive05_0003(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1E, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive05_0004(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 8, 0x70);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive05_0005(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1C, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive05_0006(PLW* wk) {
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

void Passive05_0007(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F88, -1, 0, 1, -1);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x41D, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive05_0008(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F88, -1, 0, 1, -1);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x41D, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive05_0009(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F88, -1, 0, 1, -1);
        break;

    case 1:
        SA_Term(wk, 0x35, 0xFFFF, 0xFFFF, 0);
        break;

    case 2:
        J_Command_Attack(wk, 8, 0x41D, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive05_0010(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7FD0, -0x7FC8, 0, 1, -1);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x42);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive05_0011(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F78, -0x7FB8, 0, 1, -1);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x22);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive05_0012(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F90, 0, 0, 2, 0);
        break;

    case 1:
        Lever_Attack(wk, 8, 1, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive05_0013(PLW* wk) {
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

void Passive05_0014(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        VS_Jump_Guard(wk);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive05_0015(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x10);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive05_0016(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3F, 2);
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

void Passive05_0017(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x67, 2);
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

void Passive05_0018(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x67, 2);
        break;

    case 1:
        Wait_Get_Up(wk, 0, -1);
        break;

    case 2:
        J_Command_Attack(wk, 8, 0x1F, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive05_0019(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive05_0020(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 3, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive05_0021(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x67, 2);
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

void Passive05_0022(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;

    case 1:
        Jump_Attack_Term(wk, -0x7F90, 0x40, 8, 0x402, 0, -0x7F68, -1, 0x10);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive05_0023(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;

    case 1:
        Jump_Attack_Term(wk, -0x7F90, -0x7FA8, 8, 0x40, 0, -0x7F78, -1, 0x10);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive05_0024(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xB7, 2);
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

void Passive05_0025(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0, 0xB, -1);
        break;

    case 1:
        EM_Term(wk, 0x7FFF, -1, 1, 1, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive05_0026(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x67, 2);
        break;

    case 1:
        EM_Term(wk, 0x7FFF, -1, 1, 1, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive05_0027(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xB, 0x202);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive05_0028(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F80, -1, 0, 1, -1);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1C, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive05_0029(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 1, 0x10);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive05_0030(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive05_0031(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 1, 0x20, 1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive05_0032(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x110);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive05_0033(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 1, 0x110);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive05_0034(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 8, 0x10);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive05_0035(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x102);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive05_0036(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive05_0037(PLW* wk) {
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

void Passive05_0038(PLW* wk) {
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

void Passive05_0039(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7FCB, -0x7FF8, 0, 1, -1);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x40);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive05_0040(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, -0x7FC0, 0, 1, -1);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x20, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive05_0041(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x42);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x41D, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive05_0042(PLW* wk) {
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

void Passive05_0043(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7FB0, -1, 0, 6, 0x1F);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x41D, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive05_0044(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3F, 2);
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

void Passive05_0045(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive05_0046(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Status(wk, 2, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive05_0047(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xB, 0x102);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1E, 8, 0x70);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive05_0048(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x402);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive05_0049(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x12);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive05_0050(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive05_0051(PLW* wk) {
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

void Passive05_0052(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x202);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive05_0053(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1F, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive05_0054(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x87, 0, 1, -1);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1F, 9, 0x70);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive05_0055(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1F, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive05_0056(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, -0x7FC0, 0, 1, -1);
        break;

    case 1:
        Command_Attack(wk, 8, 0x20, 10, 0x700);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive05_0057(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x40, 8, 0x402, 2, -0x7F80, -1, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive05_0058(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Status(wk, 2, 1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive05_0059(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 0xC, 0x1E, 10, -1);
        break;

    case 1:
        SA_Term(wk, 0x35, 0x36, 0x37, 0x60);
        break;

    case 2:
        J_Command_Attack(wk, 8, 0x1C, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive05_0060(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Forced_Guard(wk, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive05_0061(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Get_Up(wk, 0, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive05_0062(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xB, 0x200);
        break;

    case 1:
        Normal_Attack(wk, 0xB, 0x20);
        break;

    case 2:
        Normal_Attack(wk, 0xB, 0x40);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive05_0063(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x35, 0x36, 0x37, 0x60);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive05_0064(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x67, 2);
        break;

    case 1:
        Normal_Attack(wk, 0xB, 0x40);
        break;

    case 2:
        J_Command_Attack(wk, 8, 0x1E, 10, 0x70);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive05_0065(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x67, 2);
        break;

    case 1:
        Normal_Attack(wk, 0xB, 0x200);
        break;

    case 2:
        J_Command_Attack(wk, 8, 0x1F, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive05_0066(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xB7, 2);
        break;

    case 1:
        SA_Term(wk, 0x35, 0x36, 0x37, 0x60);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive05_0067(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Attack_Complete(wk, 3, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive05_0068(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait_Attack_Complete(wk, 3, 1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive05_0069(PLW* wk) {
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

void Passive05_0070(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x67, 2);
        break;

    case 1:
        Wait_Get_Up(wk, 0, -1);
        break;

    case 2:
        SA_Term(wk, 0x35, 0x36, 0x37, 0x60);
        break;

    case 3:
        Wait_Get_Up(wk, 0, -1);
        break;

    case 4:
        Normal_Attack(wk, 8, 0x202);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive05_0071(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7FA8, -0x7FF8, 6, 1, -1);
        break;

    case 1:
        SA_Term(wk, 0xFFFF, 0x36, 0xFFFF, 0);
        break;

    case 2:
        J_Command_Attack(wk, 8, 0x1E, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive05_0072(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F80, -0x7FF8, 5, 1, -1);
        break;

    case 1:
        SA_Term(wk, 0x35, 0xFFFF, 0x37, 0);
        break;

    case 2:
        Forced_Guard(wk, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive05_0073(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F80, -1, 5, 1, -1);
        break;

    case 1:
        SA_Term(wk, 0x35, 0xFFFF, 0x37, 0);
        break;

    case 2:
        Adjust_Attack(wk, 0xB, 0x10);
        break;

    case 3:
        Normal_Attack(wk, 10, 0x202);
        break;

    case 4:
        Normal_Attack(wk, 10, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive05_0074(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F80, -0x7FF0, 5, 1, -1);
        break;

    case 1:
        SA_Term(wk, 0x35, 0xFFFF, 0x37, 0);
        break;

    case 2:
        J_Command_Attack(wk, 8, 0x1E, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive05_0075(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7FC0, -1, 5, 6, 0x1F);
        break;

    case 1:
        Pierce_On(wk);
        break;

    case 2:
        Normal_Attack(wk, 0xB, 0x12);
        break;

    case 3:
        J_Command_Attack(wk, 8, 0x41D, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive05_0076(PLW* wk) {
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

void Passive05_0077(PLW* wk) {
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

void Passive05_0078(PLW* wk) {
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

void Passive05_0079(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Forced_Guard(wk, 2);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive05_0080(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    default:
        End_Pattern(wk);
        break;
    }
}

void Passive05_0081(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA0, -0x7FA8, 9, 0x40, 0, -0x7FB0, -1, 0x400);
        break;

    case 1:
        Normal_Attack(wk, 9, 0x20);
        break;

    case 2:
        Normal_Attack(wk, 9, 0x40);
        break;

    case 3:
        Command_Attack(wk, 9, 0x1E, 10, -1);
        break;

    case 4:
        SA_Term(wk, 0x35, 0x36, 0x37, 0x60);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive05_0082(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3F, 2);
        break;

    case 1:
        EM_Term(wk, -1, -0x7FF0, 6, 1, -1);
        break;

    case 2:
        Normal_Attack(wk, 9, 0x200);
        break;

    case 3:
        Command_Attack(wk, 9, 0x1C, 10, -1);
        break;

    case 4:
        SA_Term(wk, 0x35, 0x36, 0x37, 0x60);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive05_0083(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump(wk, 2);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive05_0084(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, -0x7FC0, 9, 0x202, 1, -0x7FB0, -1, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive05_0085(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7FA0, -0x7FF8, 5, 1, -1);
        break;

    case 1:
        Normal_Attack(wk, 0xD, 0x100);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive05_0086(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Check_SA(wk, 6, 0x5A);
        break;

    case 1:
        Command_Attack(wk, 0xC, 0x1E, 10, -1);
        break;

    case 2:
        Wait(wk, 5);
        break;

    case 3:
        SA_Term(wk, 0x35, 0x36, 0x37, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive05_0087(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xB7, 2);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive05_0088(PLW* wk) {
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

void Passive05_0089(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x220);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive05_0090(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 10, -1);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1C, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive05_0091(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F80, -1, 5, 1, -1);
        break;

    case 1:
        SA_Term(wk, 0x35, 0xFFFF, 0xFFFF, 0);
        break;

    case 2:
        Forced_Guard(wk, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive05_0092(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x50, 8, 0x202, 2, -0x7F80, -1, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive05_0093(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, -0x7F78, 9, 0x400, 0, -0x7FA0, -1, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive05_0094(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, 0x30, 0, 1, -1);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x22);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive05_0095(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, -1, 0, 1, -1);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x41D, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive05_0096(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, -0x7FF8, 0, 1, -1);
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

void Passive05_0097(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x67, 2);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive05_0098(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0, 0xB, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive05_0099(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump(wk, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive05_0100(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x35, 0xFFFF, 0xFFFF, 0);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x41D, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Passive05_0101(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x22);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void (*const Passive05_Tbl[102])(PLW*) = {
    Passive05_0000, Passive05_0001, Passive05_0002, Passive05_0003, Passive05_0004, Passive05_0005, Passive05_0006,
    Passive05_0007, Passive05_0008, Passive05_0009, Passive05_0010, Passive05_0011, Passive05_0012, Passive05_0013,
    Passive05_0014, Passive05_0015, Passive05_0016, Passive05_0017, Passive05_0018, Passive05_0019, Passive05_0020,
    Passive05_0021, Passive05_0022, Passive05_0023, Passive05_0024, Passive05_0025, Passive05_0026, Passive05_0027,
    Passive05_0028, Passive05_0029, Passive05_0030, Passive05_0031, Passive05_0032, Passive05_0033, Passive05_0034,
    Passive05_0035, Passive05_0036, Passive05_0037, Passive05_0038, Passive05_0039, Passive05_0040, Passive05_0041,
    Passive05_0042, Passive05_0043, Passive05_0044, Passive05_0045, Passive05_0046, Passive05_0047, Passive05_0048,
    Passive05_0049, Passive05_0050, Passive05_0051, Passive05_0052, Passive05_0053, Passive05_0054, Passive05_0055,
    Passive05_0056, Passive05_0057, Passive05_0058, Passive05_0059, Passive05_0060, Passive05_0061, Passive05_0062,
    Passive05_0063, Passive05_0064, Passive05_0065, Passive05_0066, Passive05_0067, Passive05_0068, Passive05_0069,
    Passive05_0070, Passive05_0071, Passive05_0072, Passive05_0073, Passive05_0074, Passive05_0075, Passive05_0076,
    Passive05_0077, Passive05_0078, Passive05_0079, Passive05_0080, Passive05_0081, Passive05_0082, Passive05_0083,
    Passive05_0084, Passive05_0085, Passive05_0086, Passive05_0087, Passive05_0088, Passive05_0089, Passive05_0090,
    Passive05_0091, Passive05_0092, Passive05_0093, Passive05_0094, Passive05_0095, Passive05_0096, Passive05_0097,
    Passive05_0098, Passive05_0099, Passive05_0100, Passive05_0101
};
