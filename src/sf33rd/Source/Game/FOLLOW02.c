/* FOLLOW02.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * Follow02 0x5978F size 0x1A.
 * Follow02_0000 is folded into 0x59753 with 1 other bodies. Unnamed.
 * Follow02_0001 is folded into 0x597A9 with 1 other bodies. Unnamed.
 * Follow02_0002 is folded into 0x59753 with 1 other bodies. Unnamed.
 * Follow02_0003 is folded into 0x597A9 with 1 other bodies. Unnamed.
 * Data: Follow02_Tbl is 0x25C700, 4 entries compared.
 * Globals: Follow02_Tbl 0x25C700, Pattern_Index 0x7A80C8.
 */

#include "structs.h"

void Follow02_0000(PLW* wk);
void Follow02_0001(PLW* wk);
void Follow02_0002(PLW* wk);
void Follow02_0003(PLW* wk);
extern u16 Pattern_Index[2];
extern u8 CP_Index[2][8];
void Normal_Attack(PLW* wk, s16 Reaction, u16 Lever_Data);
void End_Pattern(PLW* wk);
void Command_Attack(PLW* wk, s16 Reaction, u16 Tech_Number, s16 Power_Level, s16 Ex_Shot);

void (*const Follow02_Tbl[4])(PLW*) = {
    Follow02_0000,
    Follow02_0001,
    Follow02_0002,
    Follow02_0003,
};

void Follow02(PLW* wk) {
    Follow02_Tbl[(s16)Pattern_Index[wk->wu.id]](wk);
}

void Follow02_0000(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x10);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x20);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Follow02_0001(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x20);
        break;

    case 1:
        Command_Attack(wk, 2, 8, 0x1C, 8);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Follow02_0002(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x10);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x20);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Follow02_0003(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x20);
        break;

    case 1:
        Command_Attack(wk, 2, 8, 0x1C, 8);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}
