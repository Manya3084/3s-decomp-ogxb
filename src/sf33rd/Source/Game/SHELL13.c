/* SHELL13.c, retail sf33rd.xbe.
 * PlayStation 2 C, not hand-adjusted for Xbox. Each named body was located
 * from the PS2 retail map: call graph, source order, and agreement of
 * constants, field offsets, callees, and size. See docs/decompiling.md.
 * The #include lines name headers in the PS2 tree (ps2.path).
 * Shell13_0000 is folded into 0x991B2 with 19 other bodies. Unnamed.
 * Shell13_0001 is folded into 0x98B30 with 5 other bodies. Unnamed.
 * Shell13_0002 is folded into 0x98EDE with 5 other bodies. Unnamed.
 * Shell13_0006 is folded into 0x98C8C with 5 other bodies. Unnamed.
 * Shell13_0007 is folded into 0xE2EEB with 25 other bodies. Unnamed.
 * Shell13_0009 is folded into 0x9906F with 5 other bodies. Unnamed.
 * Shell13_0010 is folded into 0x991B2 with 19 other bodies. Unnamed.
 * Shell13_0011 is folded into 0x7339B with 1 other bodies. Unnamed.
 * Shell13_0004 0x98781 size 0x6D.
 * Shell13_0005 0x987EE size 0x6D.
 * Shell13_0008 0x9885B size 0x6D.
 * Shell13 0x99198 size 0x1A.
 * Shell13_0003 0x991B7 size 0x73.
 * The other functions in this file are not located in sf33rd.xbe yet.
 */

#include "sf33rd/Source/Game/SHELL13.h"
#include "common.h"
#include "sf33rd/Source/Game/Com_Sub.h"
#include "sf33rd/Source/Game/workuser.h"

void (*const Shell13_Tbl[12])(PLW*);

void Shell13(PLW* wk) {
    Shell13_Tbl[(s16)Pattern_Index[wk->wu.id]](wk);
}

void Shell13_0000(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    default:
        End_Pattern(wk);
        break;
    }
}

void Shell13_0001(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SHELL_Term(wk, 1, 2, 1, -1, -1);
        break;

    case 1:
        Jump(wk, 2);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Shell13_0002(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SHELL_Term(wk, 0, 2, 1, -1, -1);
        break;

    case 1:
        Jump(wk, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Shell13_0003(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SHELL_Term(wk, 0, 2, 1, -1, -1);
        break;

    case 1:
        Jump_Attack_Term(wk, -0x7F78, -0x7FD0, 9, 0x200, 0, -0x7FB0, -1, 0x200);
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

void Shell13_0004(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SHELL_Term(wk, 0, 2, 1, -1, -1);
        break;

    case 1:
        Jump_Attack_Term(wk, -0x7F78, -0x7FD0, 0xB, 0x200, 0, -0x7FB0, -1, 0x20);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x202);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Shell13_0005(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SHELL_Term(wk, 0, 2, 1, -1, -1);
        break;

    case 1:
        Jump_Attack_Term(wk, -0x7F78, -0x7FC0, 0xB, 0x200, 0, -0x7FB0, -1, 0x400);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x40);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Shell13_0006(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SHELL_Term(wk, 1, 2, 1, -1, -1);
        break;

    case 1:
        Jump_Attack_Term(wk, -1, 0x30, 8, 0x400, 2, -1, -1, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Shell13_0007(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Shell13_0008(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SHELL_Term(wk, 0, 2, 1, -1, -1);
        break;

    case 1:
        Jump_Attack_Term(wk, -0x7F78, -0x7FD0, 0xB, 0x20, 0, -0x7FB0, -1, 0x200);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x202);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Shell13_0009(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Off(wk);
        break;

    case 1:
        SHELL_Term(wk, 2, 2, 1, -1, -1);
        break;

    case 2:
        Next_Be_Flip(wk, 8);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Shell13_0010(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    default:
        End_Pattern(wk);
        break;
    }
}

void Shell13_0011(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 8, 0x70);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void (*const Shell13_Tbl[12])(PLW*) = { Shell13_0000, Shell13_0001, Shell13_0002, Shell13_0003,
                                        Shell13_0004, Shell13_0005, Shell13_0006, Shell13_0007,
                                        Shell13_0008, Shell13_0009, Shell13_0010, Shell13_0011 };
