/* active09.c, retail sf33rd.xbe.
 * PlayStation 2 C, not hand-adjusted for Xbox. Each named body was located
 * from the PS2 retail map: call graph, source order, and agreement of
 * constants, field offsets, callees, and size. See docs/decompiling.md.
 * The #include lines name headers in the PS2 tree (ps2.path).
 * Pattern09_0000 0xA35A0 size 0x30.
 * Pattern09_0001 0xA35D0 size 0x31.
 * Pattern09_0002 0xA3601 size 0x49.
 * Pattern09_0003 0xA364A size 0x45.
 * Pattern09_0004 0xA368F size 0x2C.
 * Pattern09_0007 0xA36BB size 0x4D.
 * Pattern09_0009 0xA3708 size 0x49.
 * Pattern09_0010 0xA3751 size 0x48.
 * Pattern09_0011 0xA3799 size 0x48.
 * Pattern09_0012 0xA37E1 size 0x45.
 * Pattern09_0013 0xA3826 size 0x48.
 * Pattern09_0017 0xA386E size 0x46.
 * Pattern09_0019 0xA38B4 size 0x49.
 * Pattern09_0020 0xA38FD size 0x4F.
 * Pattern09_0021 0xA394C size 0x49.
 * Pattern09_0022 0xA3995 size 0x40.
 * Pattern09_0029 0xA39D5 size 0x5D.
 * Pattern09_0030 0xA3A32 size 0x5B.
 * Pattern09_0031 0xA3A8D size 0x5A.
 * Pattern09_0032 0xA3AE7 size 0x34.
 * Pattern09_0033 0xA3B1B size 0x40.
 * Pattern09_0034 0xA3B5B size 0x3B.
 * Pattern09_0035 0xA3B96 size 0x45.
 * Pattern09_0036 0xA3BDB size 0x49.
 * Pattern09_0040 0xA3C60 size 0x43.
 * Pattern09_0041 0xA3CA3 size 0x5A.
 * Pattern09_0043 0xA3D38 size 0x3D.
 * Pattern09_0044 0xA3D75 size 0x3D.
 * Pattern09_0053 0xA3EC7 size 0x30.
 * Pattern09_0057 0xA3EF7 size 0x2F.
 * Pattern09_0058 0xA3F26 size 0x30.
 * Pattern09_0059 0xA3F56 size 0x48.
 * Pattern09_0062 0xA3F9E size 0x2F.
 * Pattern09_0064 0xA3FCD size 0x8C.
 * Pattern09_0068 0xA4091 size 0x38.
 * Pattern09_0072 0xA412B size 0x48.
 * Pattern09_0073 0xA4173 size 0x48.
 * Pattern09_0074 0xA41BB size 0x48.
 * Pattern09_0075 0xA4203 size 0x3A.
 * Pattern09_0076 0xA423D size 0x54.
 * Pattern09_0077 0xA4291 size 0x69.
 * Pattern09_0078 0xA42FA size 0x84.
 * Pattern09_0080 0xA437E size 0x53.
 * Pattern09_0081 0xA43D1 size 0x58.
 * Pattern09_0082 0xA4429 size 0x3B.
 * Pattern09_0083 0xA4464 size 0x44.
 * Pattern09_0085 0xA44E5 size 0x44.
 * Pattern09_0086 0xA4529 size 0x44.
 * Pattern09_0087 0xA456D size 0x44.
 * Pattern09_0088 0xA45B1 size 0x44.
 * Pattern09_0089 0xA45F5 size 0x30.
 * Pattern09_0091 0xA4625 size 0x44.
 * Pattern09_0092 0xA4669 size 0x44.
 * Pattern09_0093 0xA46AD size 0x44.
 * Pattern09_0094 0xA46F1 size 0x30.
 * Pattern09_0095 0xA4721 size 0x45.
 * Pattern09_0096 0xA4766 size 0x47.
 * Pattern09_0097 0xA47AD size 0x47.
 * Pattern09_0098 0xA47F4 size 0x44.
 * Pattern09_0099 0xA4838 size 0x5B.
 * Pattern09_0100 0xA4893 size 0x30.
 * Pattern09_0101 0xA48C3 size 0x2B.
 * Pattern09_0005 is folded into 0xAA590 with 9 other bodies. Unnamed.
 * Pattern09_0006 is folded into 0xA98E2 with 6 other bodies. Unnamed.
 * Pattern09_0008 is folded into 0x9EB76 with 2 other bodies. Unnamed.
 * Pattern09_0014 is folded into 0x9EC05 with 2 other bodies. Unnamed.
 * Pattern09_0015 is folded into 0x9F683 with 8 other bodies. Unnamed.
 * Pattern09_0016 is folded into 0xA2A7B with 6 other bodies. Unnamed.
 * Pattern09_0018 is folded into 0xDC346 with 9 other bodies. Unnamed.
 * Pattern09_0023 is folded into 0xA9A3E with 10 other bodies. Unnamed.
 * Pattern09_0024 is folded into 0xA6B63 with 7 other bodies. Unnamed.
 * Pattern09_0025 is folded into 0xA2C0E with 6 other bodies. Unnamed.
 * Pattern09_0026 is folded into 0x9E60D with 3 other bodies. Unnamed.
 * Pattern09_0027 is folded into 0xDAC4C with 14 other bodies. Unnamed.
 * Pattern09_0028 is folded into 0xA9A3E with 10 other bodies. Unnamed.
 * Pattern09_0037 is folded into 0xDDBBA with 13 other bodies. Unnamed.
 * Pattern09_0038 is folded into 0xA3C24 with 1 other bodies. Unnamed.
 * Pattern09_0039 is folded into 0x9EEAB with 1 other bodies. Unnamed.
 * Pattern09_0042 is folded into 0xA3CFD with 2 other bodies. Unnamed.
 * Pattern09_0045 is folded into 0xA3DB2 with 1 other bodies. Unnamed.
 * Pattern09_0046 is folded into 0xA30C6 with 4 other bodies. Unnamed.
 * Pattern09_0047 is folded into 0xA0D0D with 1 other bodies. Unnamed.
 * Pattern09_0048 is folded into 0xA3DEF with 1 other bodies. Unnamed.
 * Pattern09_0049 is folded into 0xA3E5B with 1 other bodies. Unnamed.
 * Pattern09_0050 is folded into 0xA22B4 with 4 other bodies. Unnamed.
 * Pattern09_0051 is folded into 0xA04DD with 3 other bodies. Unnamed.
 * Pattern09_0052 is folded into 0xA0D4B with 1 other bodies. Unnamed.
 * Pattern09_0054 is folded into 0x9F145 with 2 other bodies. Unnamed.
 * Pattern09_0055 is folded into 0xA0E12 with 1 other bodies. Unnamed.
 * Pattern09_0056 is folded into 0xAA7F4 with 5 other bodies. Unnamed.
 * Pattern09_0060 is folded into 0x9E7DC with 10 other bodies. Unnamed.
 * Pattern09_0061 is folded into 0xAA823 with 7 other bodies. Unnamed.
 * Pattern09_0063 is folded into 0xA06DA with 3 other bodies. Unnamed.
 * Pattern09_0065 is folded into 0x1C420 with 1 other bodies. Unnamed.
 * Pattern09_0069 is folded into 0xA40C9 with 2 other bodies. Unnamed.
 * Pattern09_0070 is folded into 0xA4106 with 2 other bodies. Unnamed.
 * Pattern09_0071 is folded into 0xA5C01 with 1 other bodies. Unnamed.
 * Pattern09_0079 is folded into 0x7D58E with 1 other bodies. Unnamed.
 * Pattern09_0084 is folded into 0xA44A8 with 1 other bodies. Unnamed.
 * Pattern09_0090 is folded into 0x7E385 with 1 other bodies. Unnamed.
 * Pattern09_0066 is folded into 0xA4059 with 1 other bodies. Unnamed.
 * Pattern09_0067 is folded into 0xA67CF with 1 other bodies. Unnamed.
 * The other functions in this file are not located in sf33rd.xbe yet.
 */

#include "sf33rd/Source/Game/active09.h"
#include "common.h"
#include "sf33rd/Source/Game/Com_Sub.h"
#include "sf33rd/Source/Game/workuser.h"

void (*const Pattern09_Tbl[102])();

void Computer09(PLW* wk) {
    Pattern09_Tbl[(s16)Pattern_Index[wk->wu.id]](wk);
}

void Pattern09_0000(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 2, 0x47, 0x47, 0x46, 0x46, 1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0001(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x102);
        break;

    case 1:
        Normal_Attack(wk, 9, 0x102);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0002(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7FC0, -1, 5, 1, -1);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1C, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0003(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7FA0, -1, 5, 1, -1);
        break;

    case 1:
        Adjust_Attack(wk, 8, 0x10);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0004(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 1, 0x1E, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0005(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x110);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0006(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 0x1E);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0007(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x60, 1, -1);
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

void Pattern09_0008(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7F90, -0x7FC0, 0, 0x200, 0, -1, -1, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0009(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7FC0, -1, 5, 1, -1);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1C, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0010(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7FA0, -1, 5, 1, -1);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x402);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0011(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7FA0, -1, 5, 1, -1);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x202);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0012(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7FA0, -1, 5, 1, -1);
        break;

    case 1:
        Normal_Attack(wk, 9, 0x40);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0013(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F98, -1, 5, 1, -1);
        break;

    case 1:
        Normal_Attack(wk, 9, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0014(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA0, -0x7FC8, 8, 0x200, 2, -0x7F80, -1, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0015(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 0, 0x30, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0016(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 1, 0x30, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0017(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x58, -1, 5, 2, 0);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1F, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0018(PLW* wk) {
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

void Pattern09_0019(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F98, -1, 0, 2, 5);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1D, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0020(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;

    case 1:
        Lever_On(wk, 1, 2);
        break;

    case 2:
        Com_Random_Select(wk, 2, 0x41, 0x42, 0x43, 0x44, 1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0021(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F10, -1, 5, 2, 0);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1F, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0022(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7F98, -0x7FA8, 8, 0x40, 0, -0x7F90, -1, 0x100);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0023(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x7F, 2);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0024(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 0, 0x60, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0025(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 1, 0x60, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0026(PLW* wk) {
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

void Pattern09_0027(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump(wk, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0028(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x7F, 2);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0029(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7FB0, -1, 5, 1, -1);
        break;

    case 1:
        Adjust_Attack(wk, 9, 0x100);
        break;

    case 2:
        Command_Attack(wk, 8, 0x1E, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0030(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7FB0, -1, 5, 1, -1);
        break;

    case 1:
        Adjust_Attack(wk, 9, 0x100);
        break;

    case 2:
        Lever_Attack(wk, 8, 0, 0x40);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0031(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA0, -0x7FC0, 8, 0x400, 0, -0x7F68, -1, 0x200);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x402);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0032(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 9, 0x10);
        break;

    case 1:
        Adjust_Attack(wk, 8, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0033(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 9, 0x10);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0034(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0, 0x100);
        break;

    case 1:
        Look(wk, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0035(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7FA0, -1, 5, 1, -1);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0036(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F60, -1, 5, 2, 0);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1F, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0037(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 1, 0x110);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0038(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x100);
        break;

    case 1:
        Normal_Attack(wk, 9, 0x10);
        break;

    case 2:
        Normal_Attack(wk, 9, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0039(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0, 0xB, -1);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1C, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0040(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x202);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1F, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0041(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7FA0, -1, 5, 1, -1);
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

void Pattern09_0042(PLW* wk) {
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

    case 3:
        Normal_Attack(wk, 8, 0x202);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0043(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7F98, -0x7FA8, 8, 0x40, 0, -1, 0x30, 0x401F);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0044(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA0, -0x7FB0, 8, 0x40, 0, -1, 0x30, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0045(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA0, -0x7FC0, 8, 0x400, 0, -1, -1, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0046(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 0, 0x15, 0);
        break;

    case 1:
        Walk(wk, 1, 0x13, 0);
        break;

    case 2:
        Walk(wk, 0, 0x10, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0047(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Command_Attack_Term(wk, 8, 0x1F, 0xA, -1, -0x7FA0, 0x30, 0, -1, 0x30, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0048(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA0, -0x7FC0, -0x5FF7, 0x400, 0, -0x7FB0, -1, 0x400);
        break;

    case 1:
        Normal_Attack(wk, 9, 0x22);
        break;

    case 2:
        Command_Attack(wk, 0xC, 0x1C, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0049(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7F98, -0x7FA8, 9, 0x40, 0, -0x7FB0, -1, 0x400);
        break;

    case 1:
        Normal_Attack(wk, 9, 0x200);
        break;

    case 2:
        Command_Attack(wk, 0xC, 0x1D, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0050(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack(wk, 8, 0xA, 0x400, 2);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0051(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, -1, 0x30, 8, 0x40, 0, -1, -1, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0052(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Command_Attack_Term(wk, 8, 0x1F, 0xA, -1, -1, 0x30, 0, -1, -1, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0053(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 2, 0x39, 0x39, 0x3D, 0x3D, 1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0054(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8015, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0055(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8015, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0056(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8015, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0057(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8018, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0058(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 2, 0x39, 0x39, 0x3C, 0x3C, 1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0059(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F90, -1, 5, 1, -1);
        break;

    case 1:
        Normal_Attack(wk, 9, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0060(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8014, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0061(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8016, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0062(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, -1, 0x64, -1, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0063(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7F90, -0x7FC0, 8, 0x200, 0, -0x7F68, -1, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0064(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA0, -0x7FA8, 9, 0x40, 0, -0x7FB0, -1, 0x400);
        break;

    case 1:
        Normal_Attack(wk, 9, 0x202);
        break;

    case 2:
        Command_Attack(wk, 0xC, 0x1E, 0xA, -1);
        break;

    case 3:
        Wait(wk, 5);
        break;

    case 4:
        SA_Term(wk, 0x35, 0x64, 0x3A, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0065(PLW* wk) {
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

void Pattern09_0066(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0067(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1E, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0068(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0069(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x2F, 9, -1, -1, -0x7FC0, 0, -1, -1, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0070(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Look(wk, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0071(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_On(wk, 1, 2);
        break;

    case 1:
        Look(wk, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0072(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7FA0, -0x7FF0, 5, 1, -1);
        break;

    case 1:
        Normal_Attack(wk, 9, 0x40);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0073(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7FC0, -0x7FF0, 5, 1, -1);
        break;

    case 1:
        Adjust_Attack(wk, 8, 0x10);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0074(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7FB8, -0x7FF0, 5, 1, -1);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0075(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA0, -0x7FC8, 8, 0x40, 0, -0x7FA0, -1, 0x40);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0076(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA0, -0x7FD0, 8, 0x200, 0, -0x7FA0, -1, 0x20);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x402);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0077(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA0, -0x7FC0, -0x5FF7, 0x400, 0, -0x7FA0, -1, 0x40);
        break;

    case 1:
        Normal_Attack(wk, 9, 0x22);
        break;

    case 2:
        Command_Attack(wk, 0xC, 0x1C, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0078(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x60, 2, 0x4F);
        break;

    case 1:
        SA_Term(wk, 0x35, -1, -1, 0x9F);
        break;

    case 2:
        Pierce_On(wk);
        break;

    case 3:
        Command_Attack(wk, 8, 1, 0xB, -1);
        break;

    case 4:
        SA_Term(wk, -1, 100, 0x3A, 0);
        break;

    case 5:
        Command_Attack(wk, 8, 0x8016, 10, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0079(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x35, -1, -1, 0x9F);
        break;

    case 1:
        SA_Term(wk, -1, 0x64, 0x3A, 0);
        break;

    case 2:
        Command_Attack(wk, 8, 0x8016, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0080(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_On(wk, 1, 2);
        break;

    case 1:
        Command_Attack(wk, 8, 0, 0xB, -1);
        break;

    case 2:
        J_Command_Attack(wk, 8, 0x1C, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0081(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA0, -0x7FD0, 0x2008, 0x200, 0, -0x7FA0, -1, 0x20);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1C, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0082(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ETC_Term(wk, 5, 2, 0);
        break;

    case 1:
        Provoke(wk, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0083(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ORO_JA_Term(wk, 8, 0, 0x30, 1, -1, -0x7FA0, 0x400, -0x7FB0, -0x7FD0, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0084(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FD0, 0x10, 8, 0x110, 0, -0x7FA0, -1, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0085(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ORO_JA_Term(wk, 8, 2, 0x40, 1, -1, -1, -1, -0x7FB0, -0x7FD0, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0086(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ORO_JA_Term(wk, 8, 0, 0x50, 1, -1, -1, -1, -0x7FB0, -0x7FD0, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0087(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ORO_JA_Term(wk, 8, 1, 0x40, 2, -1, -1, -1, -0x7FB0, -0x7FD0, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0088(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ORO_JA_Term(wk, 8, 1, 0x40, 1, -1, -1, -1, -0x7FB0, -0x7FD0, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0089(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 2, 0x55, 0x56, 0x57, 0x58, 1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0090(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ORO_JA_Term(wk, 8, 0, 0x50, 0, -1, -1, -1, -0x7FB0, -0x7FD0, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0091(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ORO_JA_Term(wk, 8, 0, 0x50, 2, -1, -1, -1, -0x7FB0, -0x7FD0, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0092(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ORO_JA_Term(wk, 8, 2, 0x40, 0, -1, -1, -1, -0x7FB0, -0x7FD0, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0093(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ORO_JA_Term(wk, 8, 1, 0x50, 0, -1, -1, -1, -0x7FB0, -0x7FD0, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0094(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 2, 0x5A, 0x5B, 0x5C, 0x5D, 1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0095(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ORO_JCA_Term(wk, 8, 0, 0x40, 1, -1, -0x7FB0, 0x2F, 0xA, -1, -0x7FB0, -0x7FD0, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0096(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ORO_JCA_Term(wk, 8, 0, 0x40, 0, -0x7FA0, -1, 0x2F, 0xA, -1, -0x7FB0, -0x7FD0, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0097(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ORO_HJCA_Term(wk, 8, 0, 0x40, 0, -0x7FA0, -1, 0x2F, 0xA, -1, -0x7FB0, -0x7FD0, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0098(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ORO_HJA_Term(wk, 8, 1, 0x50, 0, -1, -1, -1, -0x7FB0, -0x7FD0, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0099(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x35, -1, -1, 0x9F);
        break;

    case 1:
        SA_Term(wk, -1, -1, 0x3A, 0);
        break;

    case 2:
        Command_Attack(wk, 8, 0x8015, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0100(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 2, 0x36, 0x37, 0x38, 0x39, 1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0101(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_On(wk, -1, 2);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void (*const Pattern09_Tbl[102])(PLW*) = {
    Pattern09_0000, Pattern09_0001, Pattern09_0002, Pattern09_0003, Pattern09_0004, Pattern09_0005, Pattern09_0006,
    Pattern09_0007, Pattern09_0008, Pattern09_0009, Pattern09_0010, Pattern09_0011, Pattern09_0012, Pattern09_0013,
    Pattern09_0014, Pattern09_0015, Pattern09_0016, Pattern09_0017, Pattern09_0018, Pattern09_0019, Pattern09_0020,
    Pattern09_0021, Pattern09_0022, Pattern09_0023, Pattern09_0024, Pattern09_0025, Pattern09_0026, Pattern09_0027,
    Pattern09_0028, Pattern09_0029, Pattern09_0030, Pattern09_0031, Pattern09_0032, Pattern09_0033, Pattern09_0034,
    Pattern09_0035, Pattern09_0036, Pattern09_0037, Pattern09_0038, Pattern09_0039, Pattern09_0040, Pattern09_0041,
    Pattern09_0042, Pattern09_0043, Pattern09_0044, Pattern09_0045, Pattern09_0046, Pattern09_0047, Pattern09_0048,
    Pattern09_0049, Pattern09_0050, Pattern09_0051, Pattern09_0052, Pattern09_0053, Pattern09_0054, Pattern09_0055,
    Pattern09_0056, Pattern09_0057, Pattern09_0058, Pattern09_0059, Pattern09_0060, Pattern09_0061, Pattern09_0062,
    Pattern09_0063, Pattern09_0064, Pattern09_0065, Pattern09_0066, Pattern09_0067, Pattern09_0068, Pattern09_0069,
    Pattern09_0070, Pattern09_0071, Pattern09_0072, Pattern09_0073, Pattern09_0074, Pattern09_0075, Pattern09_0076,
    Pattern09_0077, Pattern09_0078, Pattern09_0079, Pattern09_0080, Pattern09_0081, Pattern09_0082, Pattern09_0083,
    Pattern09_0084, Pattern09_0085, Pattern09_0086, Pattern09_0087, Pattern09_0088, Pattern09_0089, Pattern09_0090,
    Pattern09_0091, Pattern09_0092, Pattern09_0093, Pattern09_0094, Pattern09_0095, Pattern09_0096, Pattern09_0097,
    Pattern09_0098, Pattern09_0099, Pattern09_0100, Pattern09_0101
};
