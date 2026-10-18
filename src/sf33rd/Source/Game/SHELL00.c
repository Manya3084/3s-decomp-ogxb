/* SHELL00.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * Shell00 0x98767 size 0x1A.
 * Shell00_0000 is folded into 0x991B2 with 26 other bodies. Unnamed.
 * Shell00_0001 is folded into 0x98B30 with 9 other bodies. Unnamed.
 * Shell00_0002 is folded into 0x98EDE with 9 other bodies. Unnamed.
 * Shell00_0003 is folded into 0x82920 with 5 other bodies. Unnamed.
 * Shell00_0006 is folded into 0x98C8C with 8 other bodies. Unnamed.
 * Shell00_0007 is folded into 0xE2EEB with 29 other bodies. Unnamed.
 * Shell00_0009 is folded into 0x9906F with 9 other bodies. Unnamed.
 * Shell00_0010 is folded into 0x991B2 with 26 other bodies. Unnamed.
 * Shell00_0004 is folded into 0x98781 with 1 other bodies. Unnamed.
 * Shell00_0005 is folded into 0x987EE with 1 other bodies. Unnamed.
 * Shell00_0008 is folded into 0x9885B with 1 other bodies. Unnamed.
 * Data: Shell00_Tbl is 0x265330, 11 entries compared.
 * Globals: Shell00_Tbl 0x265330, Pattern_Index 0x7A80C8.
 */

#include "structs.h"

void Shell00_0000(PLW* wk);
void Shell00_0001(PLW* wk);
void Shell00_0002(PLW* wk);
void Shell00_0003(PLW* wk);
void Shell00_0004(PLW* wk);
void Shell00_0005(PLW* wk);
void Shell00_0006(PLW* wk);
void Shell00_0007(PLW* wk);
void Shell00_0008(PLW* wk);
void Shell00_0009(PLW* wk);
void Shell00_0010(PLW* wk);
extern u16 Pattern_Index[2];
extern u8 CP_Index[2][8];
void End_Pattern(PLW* wk);
void SHELL_Term(PLW* wk, s16 Next_Command, s16 Exit_Number, s16 Next_Action, s16 Next_Menu, s16 unused);
void Jump(PLW* wk, s16 Time);
void J_Command_Attack(PLW* wk, s16 Reaction, u16 Tech_Number, s16 Power_Level, s16 Ex_Shot);
void Jump_Attack_Term(PLW* wk, s16 Range_X, s16 Range_Y, s16 Reaction, u16 Lever_Data, s16 Jump_Dir, s16 Range_JX, s16 Range_JY, s16 J_Lever_Data);
void Normal_Attack(PLW* wk, s16 Reaction, u16 Lever_Data);
void Command_Attack(PLW* wk, s16 Reaction, u16 Tech_Number, s16 Power_Level, s16 Ex_Shot);
void Lever_Off(PLW* wk);
void Next_Be_Flip(PLW* wk, s16 xx);

void (*const Shell00_Tbl[11])(PLW*) = { Shell00_0000, Shell00_0001, Shell00_0002, Shell00_0003,
                                        Shell00_0004, Shell00_0005, Shell00_0006, Shell00_0007,
                                        Shell00_0008, Shell00_0009, Shell00_0010 };

void Shell00(PLW* wk) {
    Shell00_Tbl[(s16)Pattern_Index[wk->wu.id]](wk);
}

void Shell00_0000(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    default:
        End_Pattern(wk);
    }
}

void Shell00_0001(PLW* wk) {
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

void Shell00_0002(PLW* wk) {
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

void Shell00_0003(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1D, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Shell00_0004(PLW* wk) {
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

void Shell00_0005(PLW* wk) {
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

void Shell00_0006(PLW* wk) {
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

void Shell00_0007(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Shell00_0008(PLW* wk) {
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

void Shell00_0009(PLW* wk) {
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

void Shell00_0010(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    default:
        End_Pattern(wk);
    }
}
