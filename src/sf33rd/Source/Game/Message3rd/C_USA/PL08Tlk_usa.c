/* PL08Tlk_usa.c, retail sf33rd.xbe.
 * The PS2 file's data (ps2.path), checked by analysis-ps2map/portdata.py
 * against the XBE: each table at its data.txt address, or at the
 * address a checked table's pointer to it holds ("placed by").
 * msgTalkAdrPL08 0x326988 size 0x18: match (placed by pl08tlk_usa_tbl).
 * msgTalkCtrPL08 0x3269a0 size 0x6: match (placed by pl08tlk_usa_tbl).
 * msgTlkPL08_00P 0x326960 size 0x4: match (placed by msgTalkAdrPL08).
 * msgTlkPL08_01P 0x326964 size 0x8: match (placed by msgTalkAdrPL08).
 * msgTlkPL08_02P 0x32696c size 0x8: match (placed by msgTalkAdrPL08).
 * msgTlkPL08_03P 0x326974 size 0x4: match (placed by msgTalkAdrPL08).
 * msgTlkPL08_04P 0x326978 size 0x8: match (placed by msgTalkAdrPL08).
 * msgTlkPL08_05P 0x326980 size 0x8: match (placed by msgTalkAdrPL08).
 * pl08tlk_usa_tbl 0x3269a8 size 0x8: match (placed by pl_tlk_tbl).
 */

#include "structs.h"
#include <stddef.h>

/* from sf33rd/Source/Game/Message3rd/C_USA/PL08Tlk_usa.h */
extern MessageTable pl08tlk_usa_tbl;

static s8* msgTlkPL08_00P[1] = { "" };
static s8* msgTlkPL08_01P[2] = {
    "  What's wrong with you?! Stop smiling          ",
    "  like that! It's creepy!                       ",
};
static s8* msgTlkPL08_02P[2] = {
    "  I'm here for a serious fight! I'll            ",
    "  punish you if you make fun of me!             ",
};
static s8* msgTlkPL08_03P[1] = { "  I just want to be your friend!                " };
static s8* msgTlkPL08_04P[2] = {
    "  That's the reason why we fight!               ",
    "  So let's enjoy the battle!                    ",
};
static s8* msgTlkPL08_05P[2] = {
    "  Friend?! I don't think I                      ",
    "  could ever understand you.                    ",
};

static s8** msgTalkAdrPL08[6] = {
    msgTlkPL08_00P, msgTlkPL08_01P, msgTlkPL08_02P, msgTlkPL08_03P, msgTlkPL08_04P, msgTlkPL08_05P,
};

static s8 msgTalkCtrPL08[6] = { 1, 2, 2, 1, 2, 2 };

MessageTable pl08tlk_usa_tbl = { msgTalkAdrPL08, msgTalkCtrPL08 };
