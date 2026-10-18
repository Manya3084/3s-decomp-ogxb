/* SHELL13.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * Shell13 0x99198 size 0x1A.
 * Shell13_0003 0x991B7 size 0x73.
 * Shell13_0000 is folded into 0x991B2 with 19 other bodies. Unnamed.
 * Shell13_0001 is folded into 0x98B30 with 5 other bodies. Unnamed.
 * Shell13_0002 is folded into 0x98EDE with 5 other bodies. Unnamed.
 * Shell13_0006 is folded into 0x98C8C with 5 other bodies. Unnamed.
 * Shell13_0007 is folded into 0xE2EEB with 25 other bodies. Unnamed.
 * Shell13_0009 is folded into 0x9906F with 5 other bodies. Unnamed.
 * Shell13_0010 is folded into 0x991B2 with 19 other bodies. Unnamed.
 * Shell13_0011 is folded into 0x7339B with 1 other bodies. Unnamed.
 * Shell13_0004 is folded into 0x98781 with 1 other bodies. Unnamed.
 * Shell13_0005 is folded into 0x987EE with 1 other bodies. Unnamed.
 * Shell13_0008 is folded into 0x9885B with 1 other bodies. Unnamed.
 * Data: Shell13_Tbl is 0x2654A0, 12 entries compared.
 * Globals: Shell13_Tbl 0x2654A0, Pattern_Index 0x7A80C8, CP_Index 0x7A85B0.
 */

#include "structs.h"

void Shell13_0000(PLW* wk);
void Shell13_0001(PLW* wk);
void Shell13_0002(PLW* wk);
void Shell13_0003(PLW* wk);
void Shell13_0004(PLW* wk);
void Shell13_0005(PLW* wk);
void Shell13_0006(PLW* wk);
void Shell13_0007(PLW* wk);
void Shell13_0008(PLW* wk);
void Shell13_0009(PLW* wk);
void Shell13_0010(PLW* wk);
void Shell13_0011(PLW* wk);
extern u16 Pattern_Index[2];
extern u8 CP_Index[2][8];
void End_Pattern(PLW* wk);
void SHELL_Term(PLW* wk, s16 Next_Command, s16 Exit_Number, s16 Next_Action, s16 Next_Menu, s16 unused);
void Jump(PLW* wk, s16 Time);
void Jump_Attack_Term(PLW* wk, s16 Range_X, s16 Range_Y, s16 Reaction, u16 Lever_Data, s16 Jump_Dir, s16 Range_JX, s16 Range_JY, s16 J_Lever_Data);
void Normal_Attack(PLW* wk, s16 Reaction, u16 Lever_Data);
void Command_Attack(PLW* wk, s16 Reaction, u16 Tech_Number, s16 Power_Level, s16 Ex_Shot);
void Lever_Off(PLW* wk);
void Next_Be_Flip(PLW* wk, s16 xx);

void (*const Shell13_Tbl[12])(PLW*) = { Shell13_0000, Shell13_0001, Shell13_0002, Shell13_0003,
                                        Shell13_0004, Shell13_0005, Shell13_0006, Shell13_0007,
                                        Shell13_0008, Shell13_0009, Shell13_0010, Shell13_0011 };

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
