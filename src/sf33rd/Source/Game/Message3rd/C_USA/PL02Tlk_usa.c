/* PL02Tlk_usa.c, retail sf33rd.xbe.
 * The PS2 file's data (ps2.path), checked by analysis-ps2map/portdata.py
 * against the XBE: each table at its data.txt address, or at the
 * address a checked table's pointer to it holds ("placed by").
 * msgTalkAdrPL02 0x325c48 size 0x14: match (placed by pl02tlk_usa_tbl).
 * msgTalkCtrPL02 0x325c5c size 0x5: match (placed by pl02tlk_usa_tbl).
 * msgTlkPL02_00P 0x325c2c size 0x4: match (placed by msgTalkAdrPL02).
 * msgTlkPL02_01P 0x325c30 size 0x4: match (placed by msgTalkAdrPL02).
 * msgTlkPL02_02P 0x325c34 size 0x4: match (placed by msgTalkAdrPL02).
 * msgTlkPL02_03P 0x325c38 size 0x8: match (placed by msgTalkAdrPL02).
 * msgTlkPL02_04P 0x325c40 size 0x8: match (placed by msgTalkAdrPL02).
 * pl02tlk_usa_tbl 0x325c64 size 0x8: match (placed by pl_tlk_tbl).
 */

#include "structs.h"
#include <stddef.h>

/* from sf33rd/Source/Game/Message3rd/C_USA/PL02Tlk_usa.h */
extern MessageTable pl02tlk_usa_tbl;

static s8* msgTlkPL02_00P[1] = { "" };
static s8* msgTlkPL02_01P[1] = { "  You never get bored of this, do you?          " };
static s8* msgTlkPL02_02P[1] = { "  I could say the same to you...                " };
static s8* msgTlkPL02_03P[2] = {
    "  Okay then, I'll make this quick and           ",
    "  easy for you. Prepare for defeat!             ",
};
static s8* msgTlkPL02_04P[2] = {
    "  You may think so, but I've still got          ",
    "  the better win record! Stand strong!          ",
};

static s8** msgTalkAdrPL02[5] = {
    msgTlkPL02_00P, msgTlkPL02_01P, msgTlkPL02_02P, msgTlkPL02_03P, msgTlkPL02_04P,
};

static s8 msgTalkCtrPL02[5] = { 1, 1, 1, 2, 2 };

MessageTable pl02tlk_usa_tbl = { msgTalkAdrPL02, msgTalkCtrPL02 };
