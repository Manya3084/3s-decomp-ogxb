/* SHELL04.c, retail sf33rd.xbe.
 * PlayStation 2 C, not hand-adjusted for Xbox. Each named body was located
 * from the PS2 retail map: call graph, source order, and agreement of
 * constants, field offsets, callees, and size. See docs/decompiling.md.
 * The #include lines name headers in the PS2 tree (ps2.path).
 * Shell04_0007 0x98BE0 size 0x49.
 * Shell04_0011 0x98C29 size 0x49.
 * Shell04_0000 is folded into 0x991B2 with 19 other bodies. Unnamed.
 * Shell04_0001 is folded into 0x98B30 with 5 other bodies. Unnamed.
 * Shell04_0002 is folded into 0x98EDE with 5 other bodies. Unnamed.
 * Shell04_0003 is folded into 0x990D3 with 1 other bodies. Unnamed.
 * Shell04_0004 is folded into 0x992BA with 3 other bodies. Unnamed.
 * Shell04_0005 is folded into 0x98B6F with 1 other bodies. Unnamed.
 * Shell04_0006 is folded into 0x98C8C with 5 other bodies. Unnamed.
 * Shell04_0008 is folded into 0x98D17 with 4 other bodies. Unnamed.
 * Shell04_0009 is folded into 0x9906F with 5 other bodies. Unnamed.
 * Shell04_0010 is folded into 0x991B2 with 19 other bodies. Unnamed.
 * The other functions in this file are not located in sf33rd.xbe yet.
 */

#include "sf33rd/Source/Game/SHELL04.h"
#include "common.h"
#include "sf33rd/Source/Game/Com_Sub.h"
#include "sf33rd/Source/Game/workuser.h"

void (*const Shell04_Tbl[12])(PLW*);

void Shell04(PLW* wk) {
    Shell04_Tbl[(s16)Pattern_Index[wk->wu.id]](wk);
}

void Shell04_0000(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    default:
        End_Pattern(wk);
        break;
    }
}

void Shell04_0001(PLW* wk) {
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

void Shell04_0002(PLW* wk) {
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

void Shell04_0003(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SHELL_Term(wk, 0, 2, 1, -1, -1);
        break;

    case 1:
        Jump_Attack_Term(wk, -0x7FA8, -0x7FD0, 9, 0x200, 0, -0x7FB0, -1, 0x200);
        break;

    case 2:
        Normal_Attack(wk, 0xB, 0x20);
        break;

    case 3:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Shell04_0004(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SHELL_Term(wk, 0, 2, 1, -1, -1);
        break;

    case 1:
        Jump_Attack_Term(wk, -0x7FA8, -0x7FD0, 0xB, 0x200, 0, -0x7FB0, -1, 0x20);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x202);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Shell04_0005(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SHELL_Term(wk, 0, 2, 1, -1, -1);
        break;

    case 1:
        Jump_Attack_Term(wk, -0x7FA8, -0x7FC0, 0xB, 0x200, 0, -0x7FB0, -1, 0x400);
        break;

    case 2:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Shell04_0006(PLW* wk) {
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

void Shell04_0007(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SHELL_Term(wk, 3, 2, 1, -1, -1);
        break;

    case 1:
        Command_Attack(wk, 0xD, 0x20, 0x30A, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Shell04_0008(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SHELL_Term(wk, 0, 2, 1, -1, -1);
        break;

    case 1:
        Jump_Attack_Term(wk, -0x7FA8, -0x7FD0, 0xB, 0x20, 0, -0x7FB0, -1, 0x200);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x202);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Shell04_0009(PLW* wk) {
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

void Shell04_0010(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    default:
        End_Pattern(wk);
        break;
    }
}

void Shell04_0011(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SHELL_Term(wk, 3, 2, 1, -1, -1);
        break;

    case 1:
        Command_Attack(wk, 0xD, 0x20, 0x60A, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void (*const Shell04_Tbl[12])(PLW*) = { Shell04_0000, Shell04_0001, Shell04_0002, Shell04_0003,
                                        Shell04_0004, Shell04_0005, Shell04_0006, Shell04_0007,
                                        Shell04_0008, Shell04_0009, Shell04_0010, Shell04_0011 };
