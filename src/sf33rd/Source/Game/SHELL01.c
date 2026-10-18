/* SHELL01.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * Shell01 0x988C8 size 0x1A.
 * Shell01_0003 0x988E2 size 0x53.
 * Shell01_0004 0x98935 size 0x4D.
 * Shell01_0005 0x98982 size 0x51.
 * Shell01_0006 0x989D3 size 0x67.
 * Shell01_0007 0x98A3A size 0x5E.
 * Shell01_0008 0x98A98 size 0x64.
 * Shell01_0000 is folded into 0x991B2 with 26 other bodies. Unnamed.
 * Shell01_0001 is folded into 0x98B30 with 9 other bodies. Unnamed.
 * Shell01_0002 is folded into 0x98EDE with 9 other bodies. Unnamed.
 * Shell01_0009 is folded into 0x9906F with 9 other bodies. Unnamed.
 * Data: Shell01_Tbl is 0x26535C, 10 entries compared.
 * Globals: Shell01_Tbl 0x26535C, Pattern_Index 0x7A80C8, CP_Index 0x7A85B0.
 */

#include "structs.h"

void Shell01_0000(PLW* wk);
void Shell01_0001(PLW* wk);
void Shell01_0002(PLW* wk);
void Shell01_0003(PLW* wk);
void Shell01_0004(PLW* wk);
void Shell01_0005(PLW* wk);
void Shell01_0006(PLW* wk);
void Shell01_0007(PLW* wk);
void Shell01_0008(PLW* wk);
void Shell01_0009(PLW* wk);
extern u16 Pattern_Index[2];
extern u8 CP_Index[2][8];
void End_Pattern(PLW* wk);
void SHELL_Term(PLW* wk, s16 Next_Command, s16 Exit_Number, s16 Next_Action, s16 Next_Menu, s16 unused);
void Jump(PLW* wk, s16 Time);
void Jump_Attack_Term(PLW* wk, s16 Range_X, s16 Range_Y, s16 Reaction, u16 Lever_Data, s16 Jump_Dir, s16 Range_JX, s16 Range_JY, s16 J_Lever_Data);
void Normal_Attack(PLW* wk, s16 Reaction, u16 Lever_Data);
void Lever_Off(PLW* wk);
void Next_Be_Flip(PLW* wk, s16 xx);

void (*const Shell01_Tbl[10])(PLW*);

void (*const Shell01_Tbl[10])(PLW*) = { Shell01_0000, Shell01_0001, Shell01_0002, Shell01_0003, Shell01_0004,
                                        Shell01_0005, Shell01_0006, Shell01_0007, Shell01_0008, Shell01_0009 };

void Shell01(PLW* wk) {
    Shell01_Tbl[(s16)Pattern_Index[wk->wu.id]](wk);
}

void Shell01_0000(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    default:
        End_Pattern(wk);
        break;
    }
}

void Shell01_0001(PLW* wk) {
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

void Shell01_0002(PLW* wk) {
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

void Shell01_0003(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SHELL_Term(wk, 0, 2, 1, -1, -1);
        break;

    case 1:
        Jump_Attack_Term(wk, -0x7FA0, 0x30, 8, 0x400, 0, -1, -1, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Shell01_0004(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SHELL_Term(wk, 0, 2, 1, -1, -1);
        break;

    case 1:
        Jump_Attack_Term(wk, -1, 0x30, 8, 0x40, 0, -1, -1, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Shell01_0005(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SHELL_Term(wk, 0, 2, 1, -1, -1);
        break;

    case 1:
        Jump_Attack_Term(wk, -1, 0x30, 8, 0x400, 2, -1, -1, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Shell01_0006(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SHELL_Term(wk, 0, 2, 1, -1, -1);
        break;

    case 1:
        Jump_Attack_Term(wk, -0x7FA0, 0x30, 8, 0x200, 0, -1, -1, -1);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x202);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Shell01_0007(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SHELL_Term(wk, 0, 2, 1, -1, -1);
        break;

    case 1:
        Jump_Attack_Term(wk, -1, 0x30, 8, 0x40, 0, -1, -1, -1);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x22);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Shell01_0008(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SHELL_Term(wk, 0, 2, 1, -1, -1);
        break;

    case 1:
        Jump_Attack_Term(wk, -1, 0x30, 0xB, 0x200, 0, -1, -1, -1);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x202);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Shell01_0009(PLW* wk) {
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
