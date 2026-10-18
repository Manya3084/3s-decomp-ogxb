/* FOLLOW02.c, retail sf33rd.xbe.
 * PlayStation 2 C, not hand-adjusted for Xbox. Each named body was located
 * from the PS2 retail map: call graph, source order, and agreement of
 * constants, field offsets, callees, and size. See docs/decompiling.md.
 * The #include lines name headers in the PS2 tree (ps2.path).
 * Follow02 0x5978F size 0x1A.
 * The other functions in this file are not located in sf33rd.xbe yet.
 */

#include "sf33rd/Source/Game/FOLLOW02.h"
#include "common.h"
#include "sf33rd/Source/Game/Com_Sub.h"
#include "sf33rd/Source/Game/workuser.h"

void (*const Follow02_Tbl[4])(PLW*);

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

void (*const Follow02_Tbl[4])(PLW*) = {
    Follow02_0000,
    Follow02_0001,
    Follow02_0002,
    Follow02_0003,
};
