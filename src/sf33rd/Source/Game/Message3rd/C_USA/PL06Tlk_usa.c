/* PL06Tlk_usa.c, retail sf33rd.xbe.
 * The PS2 file's data (ps2.path), checked by analysis-ps2map/portdata.py
 * against the XBE: each table at its data.txt address, or at the
 * address a checked table's pointer to it holds ("placed by").
 * msgTalkAdrPL06 0x326530 size 0x18: match (placed by pl06tlk_usa_tbl).
 * msgTalkCtrPL06 0x326548 size 0x6: match (placed by pl06tlk_usa_tbl).
 * msgTlkPL06_00P 0x326504 size 0x4: match (placed by msgTalkAdrPL06).
 * msgTlkPL06_01P 0x326508 size 0x8: match (placed by msgTalkAdrPL06).
 * msgTlkPL06_02P 0x326510 size 0x8: match (placed by msgTalkAdrPL06).
 * msgTlkPL06_03P 0x326518 size 0x8: match (placed by msgTalkAdrPL06).
 * msgTlkPL06_04P 0x326520 size 0x8: match (placed by msgTalkAdrPL06).
 * msgTlkPL06_05P 0x326528 size 0x8: match (placed by msgTalkAdrPL06).
 * pl06tlk_usa_tbl 0x326550 size 0x8: match (placed by pl_tlk_tbl).
 */

#include "structs.h"
#include <stddef.h>

/* from sf33rd/Source/Game/Message3rd/C_USA/PL06Tlk_usa.h */
extern MessageTable pl06tlk_usa_tbl;

static s8* msgTlkPL06_00P[1] = { "" };
static s8* msgTlkPL06_01P[2] = {
    "  So, you must be the one that                  ",
    "  Poison has been talking about.                ",
};
static s8* msgTlkPL06_02P[2] = {
    "  We're recruiting those who have the           ",
    "  potential to become great wrestlers.          ",
};
static s8* msgTlkPL06_03P[2] = {
    "  Now, let's make a deal. Promise me            ",
    "  that you will join us if you lose!            ",
};
static s8* msgTlkPL06_04P[2] = {
    "  That's fine... Maybe I can learn              ",
    "  something worthwhile from wrestling.          ",
};
static s8* msgTlkPL06_05P[2] = {
    "  However, I won't lose! I'll                   ",
    "  show you what true strength is!               ",
};

static s8** msgTalkAdrPL06[6] = {
    msgTlkPL06_00P, msgTlkPL06_01P, msgTlkPL06_02P, msgTlkPL06_03P, msgTlkPL06_04P, msgTlkPL06_05P,
};

static s8 msgTalkCtrPL06[6] = { 1, 2, 2, 2, 2, 2 };

MessageTable pl06tlk_usa_tbl = { msgTalkAdrPL06, msgTalkCtrPL06 };
