/* PL01Tlk_usa.c, retail sf33rd.xbe.
 * The PS2 file's data (ps2.path), checked by analysis-ps2map/portdata.py
 * against the XBE: each table at its data.txt address, or at the
 * address a checked table's pointer to it holds ("placed by").
 * msgTalkAdrPL01 0x325a5c size 0x14: match (placed by pl01tlk_usa_tbl).
 * msgTalkCtrPL01 0x325a70 size 0x5: match (placed by pl01tlk_usa_tbl).
 * msgTlkPL01_00P 0x325a38 size 0x4: match (placed by msgTalkAdrPL01).
 * msgTlkPL01_01P 0x325a3c size 0x8: match (placed by msgTalkAdrPL01).
 * msgTlkPL01_02P 0x325a44 size 0x8: match (placed by msgTalkAdrPL01).
 * msgTlkPL01_03P 0x325a4c size 0x8: match (placed by msgTalkAdrPL01).
 * msgTlkPL01_04P 0x325a54 size 0x8: match (placed by msgTalkAdrPL01).
 * pl01tlk_usa_tbl 0x325a78 size 0x8: match (placed by pl_tlk_tbl).
 */

#include "structs.h"
#include <stddef.h>

/* from sf33rd/Source/Game/Message3rd/C_USA/PL01Tlk_usa.h */
extern MessageTable pl01tlk_usa_tbl;

static s8* msgTlkPL01_00P[1] = { "" };
static s8* msgTlkPL01_01P[2] = {
    "  A karate uniform and headband...              ",
    "  You must be Ryu.                              ",
};
static s8* msgTlkPL01_02P[2] = {
    "  I've heard a lot about you!                   ",
    "  Now, I'll confirm those rumors.               ",
};
static s8* msgTlkPL01_03P[2] = {
    "  Hmm... I can see the                          ",
    "  power in your eyes...                         ",
};
static s8* msgTlkPL01_04P[2] = {
    "  Don't hold back!                              ",
    "  Show me everything you've got!                ",
};

static s8** msgTalkAdrPL01[5] = {
    msgTlkPL01_00P, msgTlkPL01_01P, msgTlkPL01_02P, msgTlkPL01_03P, msgTlkPL01_04P,
};

static s8 msgTalkCtrPL01[5] = { 1, 2, 2, 2, 2 };

MessageTable pl01tlk_usa_tbl = { msgTalkAdrPL01, msgTalkCtrPL01 };
