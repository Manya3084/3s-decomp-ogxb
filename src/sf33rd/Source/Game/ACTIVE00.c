/* ACTIVE00.c, retail sf33rd.xbe.
 * PlayStation 2 C, not hand-adjusted for Xbox. Each named body was located
 * from the PS2 retail map: call graph, source order, and agreement of
 * constants, field offsets, callees, and size. See docs/decompiling.md.
 * The #include lines name headers in the PS2 tree (ps2.path).
 * Pattern00_0005 is folded into 0x1C071 with 1 other bodies. Unnamed.
 * Pattern00_0040 is folded into 0x1C420 with 1 other bodies. Unnamed.
 * Pattern00_0000 is folded into 0xAB943 with 26 other bodies. Unnamed.
 * Pattern00_0002 is folded into 0xE2EEB with 17 other bodies. Unnamed.
 * Pattern00_0004 is folded into 0x1C045 with 4 other bodies. Unnamed.
 * Pattern00_0004 is folded into 0x85416 with 5 other bodies. Unnamed.
 * Pattern00_0006 is folded into 0x822AE with 19 other bodies. Unnamed.
 * Pattern00_0006 is folded into 0xA98E2 with 6 other bodies. Unnamed.
 * Pattern00_0007 is folded into 0x6D0A6 with 21 other bodies. Unnamed.
 * Pattern00_0010 is folded into 0xA9FCC with 23 other bodies. Unnamed.
 * Pattern00_0012 is folded into 0x71E79 with 17 other bodies. Unnamed.
 * Pattern00_0013 is folded into 0xA9FA1 with 15 other bodies. Unnamed.
 * Pattern00_0015 is folded into 0x9F683 with 8 other bodies. Unnamed.
 * Pattern00_0017 is folded into 0xE2EEB with 17 other bodies. Unnamed.
 * Pattern00_0018 is folded into 0x82978 with 9 other bodies. Unnamed.
 * Pattern00_0019 is folded into 0xD182B with 2 other bodies. Unnamed.
 * Pattern00_0019 is folded into 0xE19B6 with 6 other bodies. Unnamed.
 * Pattern00_0023 is folded into 0x9F7DA with 1 other bodies. Unnamed.
 * Pattern00_0023 is folded into 0xA2BE6 with 3 other bodies. Unnamed.
 * Pattern00_0024 is folded into 0xA6B63 with 7 other bodies. Unnamed.
 * Pattern00_0025 is folded into 0xA4A84 with 1 other bodies. Unnamed.
 * Pattern00_0026 is folded into 0x9E60D with 3 other bodies. Unnamed.
 * Pattern00_0028 is folded into 0x9F842 with 1 other bodies. Unnamed.
 * Pattern00_0028 is folded into 0xA2BE6 with 3 other bodies. Unnamed.
 * Pattern00_0033 is folded into 0xA4B55 with 1 other bodies. Unnamed.
 * Pattern00_0035 is folded into 0xD47E2 with 16 other bodies. Unnamed.
 * Pattern00_0036 is folded into 0xA9BB4 with 14 other bodies. Unnamed.
 * Pattern00_0046 is folded into 0x1C542 with 2 other bodies. Unnamed.
 * Pattern00_0046 is folded into 0xE02B3 with 4 other bodies. Unnamed.
 * Pattern00_0047 is folded into 0x1C542 with 2 other bodies. Unnamed.
 * Pattern00_0047 is folded into 0x9E7DC with 10 other bodies. Unnamed.
 * Pattern00_0048 is folded into 0x1C542 with 2 other bodies. Unnamed.
 * Pattern00_0048 is folded into 0x9E7DC with 10 other bodies. Unnamed.
 * Pattern00_0049 is folded into 0xE2EEB with 17 other bodies. Unnamed.
 * Pattern00_0050 is folded into 0xE2F17 with 13 other bodies. Unnamed.
 * Pattern00_0051 is folded into 0xE2F43 with 11 other bodies. Unnamed.
 * Pattern00_0060 is folded into 0xE33B0 with 8 other bodies. Unnamed.
 * Pattern00_0060 is folded into 0xA0DE3 with 1 other bodies. Unnamed.
 * Pattern00_0061 is folded into 0xD165E with 2 other bodies. Unnamed.
 * Pattern00_0061 is folded into 0xAA823 with 7 other bodies. Unnamed.
 * Pattern00_0064 is folded into 0xD2869 with 1 other bodies. Unnamed.
 * Pattern00_0064 is folded into 0xD5EE8 with 1 other bodies. Unnamed.
 * Pattern00_0066 is folded into 0x1C78D with 1 other bodies. Unnamed.
 * Pattern00_0066 is folded into 0xA6F87 with 1 other bodies. Unnamed.
 * Pattern00_0008 0x1C0B2 size 0x3A.
 * Pattern00_0009 0x1C0EC size 0x48.
 * Pattern00_0016 0x1C134 size 0x3D.
 * Pattern00_0020 0x1C171 size 0x36.
 * Pattern00_0021 0x1C1A7 size 0x40.
 * Pattern00_0022 0x1C1E7 size 0x60.
 * Pattern00_0027 0x1C247 size 0x3A.
 * Pattern00_0029 0x1C281 size 0x3D.
 * Pattern00_0030 0x1C2BE size 0x3B.
 * Pattern00_0032 0x1C2F9 size 0x3E.
 * Pattern00_0034 0x1C337 size 0x59.
 * Pattern00_0037 0x1C390 size 0x3E.
 * Pattern00_0038 0x1C3CE size 0x52.
 * Pattern00_0041 0x1C452 size 0x43.
 * Pattern00_0042 0x1C495 size 0x3A.
 * Pattern00_0044 0x1C4CF size 0x36.
 * Pattern00_0045 0x1C505 size 0x3D.
 * Pattern00_0052 0x1C572 size 0x48.
 * Pattern00_0054 0x1C5BA size 0x30.
 * Pattern00_0055 0x1C5EA size 0x3D.
 * Pattern00_0056 0x1C627 size 0x56.
 * Pattern00_0057 0x1C67D size 0x43.
 * Pattern00_0058 0x1C6C0 size 0x34.
 * Pattern00_0059 0x1C6F4 size 0x2C.
 * Pattern00_0065 0x1C74A size 0x43.
 * Pattern00_0067 0x1C7D2 size 0x4B.
 * Pattern00_0001 0xA69DF size 0x34.
 * Pattern00_0014 0xA6AEF size 0x3A.
 * Pattern00_0031 0xA6C03 size 0x40.
 * Pattern00_0039 0xA6D58 size 0x43.
 * Pattern00_0043 0xA6DE4 size 0x39.
 * Pattern00_0053 0xA6E4D size 0x30.
 * The other functions in this file are not located in sf33rd.xbe yet.
 */

#include "sf33rd/Source/Game/ACTIVE00.h"
#include "common.h"
#include "sf33rd/Source/Game/Com_Sub.h"
#include "sf33rd/Source/Game/workuser.h"

void (*const Pattern00_Tbl[68])();

void Computer00(PLW* wk) {
    Pattern00_Tbl[(s16)Pattern_Index[wk->wu.id]](wk);
}

void Pattern00_0000(PLW* wk) {
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

void Pattern00_0001(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xB, 0x10);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x10);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern00_0002(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern00_0003(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 9, 0x10);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern00_0004(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1F, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern00_0005(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3B, 2);
        break;

    case 1:
        Lever_Attack(wk, 8, 0, 0x110);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern00_0006(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern00_0007(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern00_0008(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xB, 0x100);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern00_0009(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x60, 2, 0x10);
        break;

    case 1:
        Jump(wk, 1);
        break;

    case 2:
        Look(wk, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern00_0010(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x402);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern00_0011(PLW* wk) {
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

void Pattern00_0012(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x40);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern00_0013(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern00_0014(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, -0x7FC0, 8, 0x40, 2, -0x7F90, 8, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern00_0015(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 0, 0x30, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern00_0016(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x50, 2, 0);
        break;

    case 1:
        Walk(wk, 1, 0x30, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern00_0017(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern00_0018(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern00_0019(PLW* wk) {
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

void Pattern00_0020(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, -0x7FB0, 8, 0x10, 0, 8, 8, 8);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern00_0021(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, -0x7FC0, 8, 0x400, 0, -0x7F90, 8, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern00_0022(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;

    case 1:
        Search_Back_Term(wk, 0x60, 2, 0x12);
        break;

    case 2:
        Command_Attack(wk, 8, 1, 0xB, -1);
        break;

    case 3:
        J_Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern00_0023(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x83, 2);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern00_0024(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 0, 0x60, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern00_0025(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x70, 2, 0);
        break;

    case 1:
        Walk(wk, 1, 0x60, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern00_0026(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0, 0xB, -1);
        break;

    case 1:
        Look(wk, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern00_0027(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, -0x7FB0, 0xB, 0x20, 0, -0x7F90, 8, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern00_0028(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xC3, 2);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern00_0029(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 0xC, 0x100);
        break;

    case 1:
        Adjust_Attack(wk, 0xC, 0x100);
        break;

    case 2:
        Adjust_Attack(wk, 8, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern00_0030(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 0xC, 0x10);
        break;

    case 1:
        Adjust_Attack(wk, 0xC, 0x20);
        break;

    case 2:
        Adjust_Attack(wk, 8, 0x40);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern00_0031(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x20);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern00_0032(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 0xB, 0x10);
        break;

    case 1:
        Lever_Attack(wk, 8, 1, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern00_0033(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 9, 0x10);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x110);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern00_0034(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 9, 0x100);
        break;

    case 1:
        ETC_Term(wk, 0, 6, 0x99);
        break;

    case 2:
        Command_Attack(wk, 8, 0x1C, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern00_0035(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern00_0036(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x42);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern00_0037(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x40);
        break;

    case 1:
        Lever_Attack(wk, 8, 1, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern00_0038(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 0xB, 0x20);
        break;

    case 1:
        Normal_Attack(wk, 0xA, 0x202);
        break;

    case 2:
        Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern00_0039(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x200);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern00_0040(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern00_0041(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1F, 9, -1);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x402);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern00_0042(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x12);
        break;

    case 1:
        Normal_Attack(wk, 9, 0x12);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x402);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern00_0043(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, -0x7FC0, 8, 0x400, 0, -1, -1, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern00_0044(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, -0x7FC0, 8, 0x40, 0, -1, -1, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern00_0045(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, -1, -0x7FC0, 8, 0x400, 0, -1, -1, 0xFFFF);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern00_0046(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 2, 0x39, 0x39, 0x41, 0x41, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern00_0047(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 2, 0x39, 0x39, 0x41, 0x41, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern00_0048(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 2, 0x39, 0x39, 0x41, 0x41, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern00_0049(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern00_0050(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern00_0051(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern00_0052(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ETC_Term(wk, 0, 6, 0x9A);
        break;

    case 1:
        Com_Random_Select(wk, 2, 0x31, 0x31, 0x31, 0x32, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern00_0053(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 2, 0x31, 0x31, 0x32, 0x33, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern00_0054(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 2, 0x31, 0x32, 0x32, 0x33, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern00_0055(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x3B, 2);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x110);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern00_0056(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x60, 2, 0x10);
        break;

    case 1:
        Jump_Attack_Term(wk, -1, -0x7FB8, 8, 0x400, 1, -0x7F90, -1, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern00_0057(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Check_SA(wk, 2, 0x34);
        break;

    case 1:
        Command_Attack(wk, 8, 0x8018, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern00_0058(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump(wk, 0);
        break;

    case 1:
        Look(wk, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern00_0059(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 1, 0xB, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern00_0060(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern00_0061(PLW* wk) {
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

void Pattern00_0062(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x22);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern00_0063(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 1, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern00_0064(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 0xA);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern00_0065(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Check_SA(wk, 2, 0x34);
        break;

    case 1:
        Command_Attack(wk, 8, 0x8019, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern00_0066(PLW* wk) {
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

void Pattern00_0067(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ETC_Term(wk, 0, 6, 0x9A);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;

    case 2:
        ETC_Term(wk, 0, 6, 0x9A);
        break;

    case 3:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void (*const Pattern00_Tbl[68])(PLW*) = {
    Pattern00_0000, Pattern00_0001, Pattern00_0002, Pattern00_0003, Pattern00_0004, Pattern00_0005, Pattern00_0006,
    Pattern00_0007, Pattern00_0008, Pattern00_0009, Pattern00_0010, Pattern00_0011, Pattern00_0012, Pattern00_0013,
    Pattern00_0014, Pattern00_0015, Pattern00_0016, Pattern00_0017, Pattern00_0018, Pattern00_0019, Pattern00_0020,
    Pattern00_0021, Pattern00_0022, Pattern00_0023, Pattern00_0024, Pattern00_0025, Pattern00_0026, Pattern00_0027,
    Pattern00_0028, Pattern00_0029, Pattern00_0030, Pattern00_0031, Pattern00_0032, Pattern00_0033, Pattern00_0034,
    Pattern00_0035, Pattern00_0036, Pattern00_0037, Pattern00_0038, Pattern00_0039, Pattern00_0040, Pattern00_0041,
    Pattern00_0042, Pattern00_0043, Pattern00_0044, Pattern00_0045, Pattern00_0046, Pattern00_0047, Pattern00_0048,
    Pattern00_0049, Pattern00_0050, Pattern00_0051, Pattern00_0052, Pattern00_0053, Pattern00_0054, Pattern00_0055,
    Pattern00_0056, Pattern00_0057, Pattern00_0058, Pattern00_0059, Pattern00_0060, Pattern00_0061, Pattern00_0062,
    Pattern00_0063, Pattern00_0064, Pattern00_0065, Pattern00_0066, Pattern00_0067
};
