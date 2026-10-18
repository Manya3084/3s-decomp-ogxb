/* SHELL12.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * Shell12 0x990B9 size 0x1A.
 * Shell12_0007 0x99152 size 0x46.
 * Shell12_0000 is folded into 0x991B2 with 26 other bodies. Unnamed.
 * Shell12_0001 is folded into 0x98B30 with 9 other bodies. Unnamed.
 * Shell12_0002 is folded into 0x98EDE with 9 other bodies. Unnamed.
 * Shell12_0003 is folded into 0x990D3 with 2 other bodies. Unnamed.
 * Shell12_0004 is folded into 0x992BA with 5 other bodies. Unnamed.
 * Shell12_0005 is folded into 0x98B6F with 2 other bodies. Unnamed.
 * Shell12_0006 is folded into 0x98C8C with 8 other bodies. Unnamed.
 * Shell12_0008 is folded into 0x98D17 with 6 other bodies. Unnamed.
 * Shell12_0009 is folded into 0x9906F with 9 other bodies. Unnamed.
 * Shell12_0010 is folded into 0x991B2 with 26 other bodies. Unnamed.
 * Data: Shell12_Tbl is 0x265474, 11 entries compared.
 * Globals: Shell12_Tbl 0x265474, Pattern_Index 0x7A80C8, CP_Index 0x7A85B0.
 */

#include "structs.h"

void Shell12_0000(PLW* wk);
void Shell12_0001(PLW* wk);
void Shell12_0002(PLW* wk);
void Shell12_0003(PLW* wk);
void Shell12_0004(PLW* wk);
void Shell12_0005(PLW* wk);
void Shell12_0006(PLW* wk);
void Shell12_0007(PLW* wk);
void Shell12_0008(PLW* wk);
void Shell12_0009(PLW* wk);
void Shell12_0010(PLW* wk);
extern u16 Pattern_Index[2];
extern u8 CP_Index[2][8];
void End_Pattern(PLW* wk);
void SHELL_Term(PLW* wk, s16 Next_Command, s16 Exit_Number, s16 Next_Action, s16 Next_Menu, s16 unused);
void Jump(PLW* wk, s16 Time);
void Jump_Attack_Term(PLW* wk, s16 Range_X, s16 Range_Y, s16 Reaction, u16 Lever_Data, s16 Jump_Dir, s16 Range_JX, s16 Range_JY, s16 J_Lever_Data);
void Normal_Attack(PLW* wk, s16 Reaction, u16 Lever_Data);
void J_Command_Attack(PLW* wk, s16 Reaction, u16 Tech_Number, s16 Power_Level, s16 Ex_Shot);
void Lever_Off(PLW* wk);
void Next_Be_Flip(PLW* wk, s16 xx);

void (*const Shell12_Tbl[11])(PLW*);

void (*const Shell12_Tbl[11])(PLW*) = { Shell12_0000, Shell12_0001, Shell12_0002, Shell12_0003,
                                        Shell12_0004, Shell12_0005, Shell12_0006, Shell12_0007,
                                        Shell12_0008, Shell12_0009, Shell12_0010 };

void Shell12(PLW* wk) {
    Shell12_Tbl[(s16)Pattern_Index[wk->wu.id]](wk);
}

void Shell12_0000(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    default:
        End_Pattern(wk);
        break;
    }
}

void Shell12_0001(PLW* wk) {
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

void Shell12_0002(PLW* wk) {
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

void Shell12_0003(PLW* wk) {
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

void Shell12_0004(PLW* wk) {
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

void Shell12_0005(PLW* wk) {
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

void Shell12_0006(PLW* wk) {
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

void Shell12_0007(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SHELL_Term(wk, 3, 2, 1, -1, -1);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Shell12_0008(PLW* wk) {
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

void Shell12_0009(PLW* wk) {
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

void Shell12_0010(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    default:
        End_Pattern(wk);
        break;
    }
}
