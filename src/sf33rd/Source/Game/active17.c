/* active17.c, retail sf33rd.xbe.
 * PlayStation 2 C, not hand-adjusted for Xbox. Each named body was located
 * from the PS2 retail map: call graph, source order, and agreement of
 * constants, field offsets, callees, and size. See docs/decompiling.md.
 * The #include lines name headers in the PS2 tree (ps2.path).
 * Computer17 0xAA5E3 size 0x1A.
 * Pattern17_0018 0xAA5FD size 0x2F.
 * Pattern17_0020 0xAA62C size 0x3A.
 * Pattern17_0021 0xAA666 size 0x3A.
 * Pattern17_0031 0xAA6A0 size 0x51.
 * Pattern17_0033 0xAA6F1 size 0x40.
 * Pattern17_0037 0xAA731 size 0x43.
 * Pattern17_0039 0xAA774 size 0x4E.
 * Pattern17_0041 0xAA7C2 size 0x32.
 * Pattern17_0052 0xAA8DF size 0x5E.
 * Pattern17_0053 0xAA93D size 0x87.
 * Pattern17_0054 0xAA9C4 size 0x45.
 * Pattern17_0066 0xAAA09 size 0x40.
 * Pattern17_0068 0xAAA49 size 0x5B.
 * Pattern17_0069 0xAAAA4 size 0x4B.
 * Pattern17_0070 0xAAAEF size 0x59.
 * Pattern17_0071 0xAAB48 size 0x48.
 * Pattern17_0072 0xAAB90 size 0x6A.
 * Pattern17_0073 0xAABFA size 0x8C.
 * Pattern17_0074 0xAAC86 size 0x73.
 * Pattern17_0075 0xAACF9 size 0x83.
 * Pattern17_0079 0xAAD7C size 0x8A.
 * Pattern17_0082 0xAAEBD size 0x8A.
 * Pattern17_0000 is folded into 0xAB943 with 44 other bodies. Unnamed.
 * Pattern17_0001 is folded into 0x9F53F with 8 other bodies. Unnamed.
 * Pattern17_0002 is folded into 0xA9EDD with 1 other bodies. Unnamed.
 * Pattern17_0003 is folded into 0xAB976 with 4 other bodies. Unnamed.
 * Pattern17_0004 is folded into 0xE2F17 with 22 other bodies. Unnamed.
 * Pattern17_0005 is folded into 0xAAF61 with 2 other bodies. Unnamed.
 * Pattern17_0006 is folded into 0xA98E2 with 12 other bodies. Unnamed.
 * Pattern17_0007 is folded into 0xAB9B3 with 5 other bodies. Unnamed.
 * Pattern17_0008 is folded into 0xA9FA1 with 25 other bodies. Unnamed.
 * Pattern17_0009 is folded into 0xAAFA5 with 4 other bodies. Unnamed.
 * Pattern17_0010 is folded into 0xA9FCC with 33 other bodies. Unnamed.
 * Pattern17_0011 is folded into 0xA9FF7 with 32 other bodies. Unnamed.
 * Pattern17_0012 is folded into 0x71E79 with 26 other bodies. Unnamed.
 * Pattern17_0013 is folded into 0xD47E2 with 27 other bodies. Unnamed.
 * Pattern17_0014 is folded into 0xDB121 with 9 other bodies. Unnamed.
 * Pattern17_0015 is folded into 0x9F683 with 14 other bodies. Unnamed.
 * Pattern17_0016 is folded into 0xA2A7B with 10 other bodies. Unnamed.
 * Pattern17_0017 is folded into 0xE2F43 with 17 other bodies. Unnamed.
 * Pattern17_0019 is folded into 0x9E572 with 12 other bodies. Unnamed.
 * Pattern17_0022 is folded into 0x9E5E1 with 4 other bodies. Unnamed.
 * Pattern17_0023 is folded into 0xA9A3E with 17 other bodies. Unnamed.
 * Pattern17_0024 is folded into 0xA6B63 with 12 other bodies. Unnamed.
 * Pattern17_0025 is folded into 0xA2C0E with 10 other bodies. Unnamed.
 * Pattern17_0026 is folded into 0x9E60D with 9 other bodies. Unnamed.
 * Pattern17_0027 is folded into 0xDAC4C with 25 other bodies. Unnamed.
 * Pattern17_0028 is folded into 0xAA09A with 13 other bodies. Unnamed.
 * Pattern17_0029 is folded into 0xAB0A0 with 4 other bodies. Unnamed.
 * Pattern17_0030 is folded into 0xA9AA4 with 4 other bodies. Unnamed.
 * Pattern17_0032 is folded into 0xAA14C with 3 other bodies. Unnamed.
 * Pattern17_0034 is folded into 0xABAEC with 5 other bodies. Unnamed.
 * Pattern17_0035 is folded into 0xD47E2 with 27 other bodies. Unnamed.
 * Pattern17_0036 is folded into 0xA9BB4 with 20 other bodies. Unnamed.
 * Pattern17_0038 is folded into 0xAA1CC with 3 other bodies. Unnamed.
 * Pattern17_0040 is folded into 0x9E759 with 3 other bodies. Unnamed.
 * Pattern17_0042 is folded into 0xABC66 with 3 other bodies. Unnamed.
 * Pattern17_0043 is folded into 0xDF251 with 11 other bodies. Unnamed.
 * Pattern17_0044 is folded into 0xE12D6 with 11 other bodies. Unnamed.
 * Pattern17_0045 is folded into 0xA9CD2 with 11 other bodies. Unnamed.
 * Pattern17_0046 is folded into 0x9E7DC with 17 other bodies. Unnamed.
 * Pattern17_0047 is folded into 0xAA7F4 with 10 other bodies. Unnamed.
 * Pattern17_0048 is folded into 0xAA823 with 13 other bodies. Unnamed.
 * Pattern17_0049 is folded into 0xAA852 with 1 other bodies. Unnamed.
 * Pattern17_0050 is folded into 0xAA881 with 1 other bodies. Unnamed.
 * Pattern17_0051 is folded into 0xAA8B0 with 3 other bodies. Unnamed.
 * Pattern17_0055 is folded into 0xAB943 with 44 other bodies. Unnamed.
 * Pattern17_0056 is folded into 0xE02DF with 8 other bodies. Unnamed.
 * Pattern17_0057 is folded into 0xE02B3 with 9 other bodies. Unnamed.
 * Pattern17_0058 is folded into 0xE19B6 with 11 other bodies. Unnamed.
 * Pattern17_0059 is folded into 0xD5FA5 with 2 other bodies. Unnamed.
 * Pattern17_0060 is folded into 0x9E95E with 3 other bodies. Unnamed.
 * Pattern17_0061 is folded into 0xD6098 with 1 other bodies. Unnamed.
 * Pattern17_0062 is folded into 0xDDB8D with 22 other bodies. Unnamed.
 * Pattern17_0063 is folded into 0xDDBBA with 20 other bodies. Unnamed.
 * Pattern17_0064 is folded into 0xAA590 with 13 other bodies. Unnamed.
 * Pattern17_0065 is folded into 0x6E340 with 7 other bodies. Unnamed.
 * Pattern17_0067 is folded into 0x9E903 with 8 other bodies. Unnamed.
 * Pattern17_0076 is folded into 0xAAE06 with 2 other bodies. Unnamed.
 * Pattern17_0077 is folded into 0xAAE5E with 2 other bodies. Unnamed.
 * Pattern17_0078 is folded into 0xDF5A4 with 1 other bodies. Unnamed.
 * Pattern17_0080 is folded into 0xAAE06 with 2 other bodies. Unnamed.
 * Pattern17_0081 is folded into 0xAAE5E with 2 other bodies. Unnamed.
 */

#include "sf33rd/Source/Game/active17.h"
#include "common.h"
#include "sf33rd/Source/Game/Com_Sub.h"
#include "sf33rd/Source/Game/workuser.h"

void (*const Pattern17_Tbl[83])();

void Computer17(PLW* wk) {
    Pattern17_Tbl[(s16)Pattern_Index[wk->wu.id]](wk);
}

void Pattern17_0000(PLW* wk) {
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

void Pattern17_0001(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x10);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x10);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern17_0002(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x41, 2);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1F, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern17_0003(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 8, 0x10);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern17_0004(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern17_0005(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x37, 2);
        break;

    case 1:
        Com_Random_Select(wk, 2, 0x3E, 0x3F, 0x40, 0x40, 1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern17_0006(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 0x1E);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern17_0007(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x30, 2, 1);
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

void Pattern17_0008(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern17_0009(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x60, 6, 0x10);
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

void Pattern17_0010(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x402);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern17_0011(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x202);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern17_0012(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x40);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern17_0013(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern17_0014(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, -0x7FB0, 0xB, 0x20, 2, -0x7FA0, -1, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern17_0015(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 0, 0x30, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern17_0016(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 1, 0x30, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern17_0017(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern17_0018(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack(wk, 8, 8, 0x402, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern17_0019(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern17_0020(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1C, 9, -1);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern17_0021(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, -0x7FA0, 0xB, 0x200, 0, -0x7FA0, -1, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern17_0022(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack(wk, 8, 0xF, 0x40, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern17_0023(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x7F, 2);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern17_0024(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 0, 0x60, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern17_0025(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 1, 0x60, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern17_0026(PLW* wk) {
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

void Pattern17_0027(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump(wk, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern17_0028(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBF, 2);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern17_0029(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 8, 0x100);
        break;

    case 1:
        Adjust_Attack(wk, 8, 0x200);
        break;

    case 2:
        Adjust_Attack(wk, 8, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern17_0030(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 9, 0x100);
        break;

    case 1:
        Adjust_Attack(wk, 8, 0x402);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern17_0031(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -1, 0x40, 0xB, 0x40, 0, -0x7FA0, -1, 0x200);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern17_0032(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 0xB, 0x10);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern17_0033(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 8, 0x10);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1F, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern17_0034(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 8, 0x102);
        break;

    case 1:
        Adjust_Attack(wk, 8, 0x102);
        break;

    case 2:
        Adjust_Attack(wk, 8, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern17_0035(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern17_0036(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x42);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern17_0037(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern17_0038(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 0xB, 0x20);
        break;

    case 1:
        Normal_Attack(wk, 0xA, 0x202);
        break;

    case 2:
        Lever_Attack(wk, 8, 0, 0x40);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern17_0039(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1F, 8, -1);
        break;

    case 1:
        Wait(wk, 6);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x40);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern17_0040(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x202);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1E, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern17_0041(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x22);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x42);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern17_0042(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x12);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x12);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x402);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern17_0043(PLW* wk) {
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

void Pattern17_0044(PLW* wk) {
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

void Pattern17_0045(PLW* wk) {
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

void Pattern17_0046(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8014, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern17_0047(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8015, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern17_0048(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8016, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern17_0049(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x8016, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern17_0050(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x8016, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern17_0051(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x8016, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern17_0052(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, -0x7FD0, 5, 2, 0);
        break;

    case 1:
        SA_Term(wk, 0x2E, 0x2F, 0xFFFF, 0);
        break;

    case 2:
        Command_Attack(wk, 8, 0x1F, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern17_0053(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -1, -0x7FD0, 5, 2, 0);
        break;

    case 1:
        SA_Term(wk, 0x2e, -1, -1, 0);
        break;

    case 2:
        Approach_Walk(wk, 0x7f, 2);
        break;

    case 3:
        SA_Term(wk, -1, 0x2f, -1, 0);
        break;

    case 4:
        Approach_Walk(wk, 0x41, 2);
        break;

    case 5:
        Command_Attack(wk, 8, 0x1f, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern17_0054(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0xFFFF, 0xFFFF, 0x30, 0);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern17_0055(PLW* wk) {
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

void Pattern17_0056(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1C, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern17_0057(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1C, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern17_0058(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern17_0059(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1C, 9, 0x700);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern17_0060(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 9, 0x70);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern17_0061(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1D, 0xA, 0x700);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern17_0062(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x110);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern17_0063(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 1, 0x110);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern17_0064(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x110);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern17_0065(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x40);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern17_0066(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x4B, 2);
        break;

    case 1:
        Command_Attack(wk, 8, 0x21, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern17_0067(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x20, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern17_0068(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;

    case 1:
        Command_Attack(wk, 9, 0x1F, 8, -1);
        break;

    case 2:
        Wait(wk, 2);
        break;

    case 3:
        Lever_Attack(wk, 8, 0, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern17_0069(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;

    case 1:
        Command_Attack(wk, 9, 0x1F, 8, -1);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x40);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern17_0070(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;

    case 1:
        Command_Attack(wk, 9, 0x1F, 8, -1);
        break;

    case 2:
        Walk(wk, 0, 8, 0);
        break;

    case 3:
        Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern17_0071(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 9, 0x1F, 0xA, -1);
        break;

    case 1:
        Pierce_On(wk);
        break;

    case 2:
        Provoke(wk, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern17_0072(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 9, 0x1F, 0xA, -1);
        break;

    case 1:
        Pierce_On(wk);
        break;

    case 2:
        Provoke(wk, 1);
        break;

    case 3:
        Com_Random_Select(wk, 6, 0x85, 0x86, 0x87, 0x70, 1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern17_0073(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Check_SA(wk, 2, 0x44);
        break;

    case 1:
        Pierce_On(wk);
        break;

    case 2:
        Command_Attack(wk, 9, 0x1f, 8, -1);
        break;

    case 3:
        Walk(wk, 0, 8, 0);
        break;

    case 4:
        EM_Term(wk, -1, -0x7FD0, 6, 1, -1);
        break;

    case 5:
        SA_Term(wk, -1, 0x2f, -1, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern17_0074(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;

    case 1:
        Command_Attack(wk, 9, 0x1F, 8, -1);
        break;

    case 2:
        Walk(wk, 0, 8, 0);
        break;

    case 3:
        EM_Term(wk, -1, -0x7FD0, 6, 1, -1);
        break;

    case 4:
        Command_Attack(wk, 8, 0x20, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern17_0075(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;

    case 1:
        Hi_Jump_Attack_Term(wk, -1, 0x40, 8, 0x40, 0, -0x7FA0, -1, 0x200);
        break;

    case 2:
        Lever_On(wk, 1, 0xffff);
        break;

    case 3:
        Normal_Attack(wk, 8, 0x12);
        break;

    case 4:
        Normal_Attack(wk, 8, 0x12);
        break;

    case 5:
        Command_Attack(wk, 8, 0x1c, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern17_0076(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_On(wk, 1, 0xFFFF);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x12);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x12);
        break;

    case 3:
        Command_Attack(wk, 8, 0x1C, 0x4008, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern17_0077(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_On(wk, 1, 0xFFFF);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x102);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x202);
        break;

    case 3:
        Command_Attack(wk, 8, 0x1D, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern17_0078(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;

    case 1:
        Lever_On(wk, 1, 0xFFFF);
        break;

    case 2:
        Lever_Attack(wk, 8, 1, 0x402);
        break;

    case 3:
        Command_Attack(wk, 8, 0x1D, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern17_0079(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;

    case 1:
        Hi_Jump_Attack_Term(wk, -1, 0x40, 8, 0x400, 0, -0x7FA0, -1, 0x200);
        break;

    case 2:
        Lever_On(wk, 1, 0xFFFF);
        break;

    case 3:
        Lever_Attack(wk, 8, 1, 0x402);
        break;

    case 4:
        Command_Attack(wk, 8, 0x1C, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern17_0080(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_On(wk, 1, 0xFFFF);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x12);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x12);
        break;

    case 3:
        Command_Attack(wk, 8, 0x1C, 0x4008, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern17_0081(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_On(wk, 1, 0xFFFF);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x102);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x202);
        break;

    case 3:
        Command_Attack(wk, 8, 0x1D, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern17_0082(PLW* wk)

{
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;
    case 1:
        Hi_Jump_Attack_Term(wk, -1, 0x40, 8, 0x400, 0, -0x7FA0, -1, 0x200);
        break;
    case 2:
        Lever_On(wk, 1, 0xffff);
        break;
    case 3:
        Normal_Attack(wk, 8, 0x12);
        break;
    case 4:
        Normal_Attack(wk, 8, 0x22);
        break;
    case 5:
        Command_Attack(wk, 8, 0x1c, 8, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}

void (*const Pattern17_Tbl[83])(PLW*) = {
    Pattern17_0000, Pattern17_0001, Pattern17_0002, Pattern17_0003, Pattern17_0004, Pattern17_0005, Pattern17_0006,
    Pattern17_0007, Pattern17_0008, Pattern17_0009, Pattern17_0010, Pattern17_0011, Pattern17_0012, Pattern17_0013,
    Pattern17_0014, Pattern17_0015, Pattern17_0016, Pattern17_0017, Pattern17_0018, Pattern17_0019, Pattern17_0020,
    Pattern17_0021, Pattern17_0022, Pattern17_0023, Pattern17_0024, Pattern17_0025, Pattern17_0026, Pattern17_0027,
    Pattern17_0028, Pattern17_0029, Pattern17_0030, Pattern17_0031, Pattern17_0032, Pattern17_0033, Pattern17_0034,
    Pattern17_0035, Pattern17_0036, Pattern17_0037, Pattern17_0038, Pattern17_0039, Pattern17_0040, Pattern17_0041,
    Pattern17_0042, Pattern17_0043, Pattern17_0044, Pattern17_0045, Pattern17_0046, Pattern17_0047, Pattern17_0048,
    Pattern17_0049, Pattern17_0050, Pattern17_0051, Pattern17_0052, Pattern17_0053, Pattern17_0054, Pattern17_0055,
    Pattern17_0056, Pattern17_0057, Pattern17_0058, Pattern17_0059, Pattern17_0060, Pattern17_0061, Pattern17_0062,
    Pattern17_0063, Pattern17_0064, Pattern17_0065, Pattern17_0066, Pattern17_0067, Pattern17_0068, Pattern17_0069,
    Pattern17_0070, Pattern17_0071, Pattern17_0072, Pattern17_0073, Pattern17_0074, Pattern17_0075, Pattern17_0076,
    Pattern17_0077, Pattern17_0078, Pattern17_0079, Pattern17_0080, Pattern17_0081, Pattern17_0082
};
