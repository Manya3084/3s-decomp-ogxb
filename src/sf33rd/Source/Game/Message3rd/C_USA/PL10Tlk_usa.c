/* PL10Tlk_usa.c, retail sf33rd.xbe.
 * The PS2 file's data (ps2.path), checked by analysis-ps2map/portdata.py
 * against the XBE: each table at its data.txt address, or at the
 * address a checked table's pointer to it holds ("placed by").
 * msgTalkAdrPL10 0x326e1c size 0x1c: match (placed by pl10tlk_usa_tbl).
 * msgTalkCtrPL10 0x326e38 size 0x7: match (placed by pl10tlk_usa_tbl).
 * msgTlkPL10_00P 0x326dec size 0x4: match (placed by msgTalkAdrPL10).
 * msgTlkPL10_01P 0x326df0 size 0x8: match (placed by msgTalkAdrPL10).
 * msgTlkPL10_02P 0x326df8 size 0x8: match (placed by msgTalkAdrPL10).
 * msgTlkPL10_03P 0x326e00 size 0x4: match (placed by msgTalkAdrPL10).
 * msgTlkPL10_04P 0x326e04 size 0x8: match (placed by msgTalkAdrPL10).
 * msgTlkPL10_05P 0x326e0c size 0x8: match (placed by msgTalkAdrPL10).
 * msgTlkPL10_06P 0x326e14 size 0x8: match (placed by msgTalkAdrPL10).
 * pl10tlk_usa_tbl 0x326e40 size 0x8: match (placed by pl_tlk_tbl).
 */

#include "structs.h"
#include <stddef.h>

/* from sf33rd/Source/Game/Message3rd/C_USA/PL10Tlk_usa.h */
extern MessageTable pl10tlk_usa_tbl;

static s8* msgTlkPL10_00P[1] = { "" };
static s8* msgTlkPL10_01P[2] = {
    "  ...Why do you care about                      ",
    "  that so much?                                 ",
};
static s8* msgTlkPL10_02P[2] = {
    "  It's just a waste of time                     ",
    "  to determine who is stronger.                 ",
};
static s8* msgTlkPL10_03P[1] = { "  I know. I just...                             " };
static s8* msgTlkPL10_04P[2] = {
    "  I'd like you to see the progress              ",
    "  I've made in last couple of weeks.            ",
};
static s8* msgTlkPL10_05P[2] = {
    "  Okay then.                                    ",
    "  I have no choice but to accept...             ",
};
static s8* msgTlkPL10_06P[2] = {
    "  Let me show you what kind of walls            ",
    "  will always block your progress!              ",
};

static s8** msgTalkAdrPL10[7] = {
    msgTlkPL10_00P, msgTlkPL10_01P, msgTlkPL10_02P, msgTlkPL10_03P, msgTlkPL10_04P, msgTlkPL10_05P, msgTlkPL10_06P,
};

static s8 msgTalkCtrPL10[7] = { 1, 2, 2, 1, 2, 2, 2 };

MessageTable pl10tlk_usa_tbl = { msgTalkAdrPL10, msgTalkCtrPL10 };
