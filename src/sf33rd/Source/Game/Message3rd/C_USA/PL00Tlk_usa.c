/* PL00Tlk_usa.c, retail sf33rd.xbe.
 * The PS2 file's data (ps2.path), checked by analysis-ps2map/portdata.py
 * against the XBE: each table at its data.txt address, or at the
 * address a checked table's pointer to it holds ("placed by").
 * msgTalkAdrPL00 0x3257c0 size 0x24: match (placed by pl00tlk_usa_tbl).
 * msgTalkCtrPL00 0x3257e4 size 0x9: match (placed by pl00tlk_usa_tbl).
 * msgTlkPL00_00P 0x325784 size 0x4: match (placed by msgTalkAdrPL00).
 * msgTlkPL00_01P 0x325788 size 0x4: match (placed by msgTalkAdrPL00).
 * msgTlkPL00_02P 0x32578c size 0x8: match (placed by msgTalkAdrPL00).
 * msgTlkPL00_03P 0x325794 size 0x8: match (placed by msgTalkAdrPL00).
 * msgTlkPL00_04P 0x32579c size 0x8: match (placed by msgTalkAdrPL00).
 * msgTlkPL00_05P 0x3257a4 size 0x8: match (placed by msgTalkAdrPL00).
 * msgTlkPL00_06P 0x3257ac size 0x8: match (placed by msgTalkAdrPL00).
 * msgTlkPL00_07P 0x3257b4 size 0x8: match (placed by msgTalkAdrPL00).
 * msgTlkPL00_08P 0x3257bc size 0x4: match (placed by msgTalkAdrPL00).
 * pl00tlk_usa_tbl 0x3257f0 size 0x8: match (placed by pl_tlk_tbl).
 */

#include "structs.h"
#include <stddef.h>

/* from sf33rd/Source/Game/Message3rd/C_USA/PL00Tlk_usa.h */
extern MessageTable pl00tlk_usa_tbl;

static s8* msgTlkPL00_00P[1] = { "" };
static s8* msgTlkPL00_01P[1] = { "  I've been waiting for you, Alex.              " };
static s8* msgTlkPL00_02P[2] = {
    "  Since the first time we met, I knew           ",
    "  that our destinies were intertwined...        ",
};
static s8* msgTlkPL00_03P[2] = {
    "  I knew that you would seek me out to          ",
    "  learn the truth...                            ",
};
static s8* msgTlkPL00_04P[2] = {
    "  What you do mean you knew I would             ",
    "  come here...?                                 ",
};
static s8* msgTlkPL00_05P[2] = {
    "  Your visions don't impress me.                ",
    "  I just want to beat you down!!                ",
};
static s8* msgTlkPL00_06P[2] = {
    "  I know that I'll find what I've been          ",
    "  looking for, once I destroy you.              ",
};
static s8* msgTlkPL00_07P[2] = {
    "  I knew you would say that...                  ",
    "  Ha ha ha!                                     ",
};
static s8* msgTlkPL00_08P[1] = { "  Let us embrace our destiny!!                  " };

static s8** msgTalkAdrPL00[9] = {
    msgTlkPL00_00P, msgTlkPL00_01P, msgTlkPL00_02P, msgTlkPL00_03P, msgTlkPL00_04P,
    msgTlkPL00_05P, msgTlkPL00_06P, msgTlkPL00_07P, msgTlkPL00_08P,
};

static s8 msgTalkCtrPL00[9] = { 1, 1, 2, 2, 2, 2, 2, 2, 1 };

MessageTable pl00tlk_usa_tbl = { msgTalkAdrPL00, msgTalkCtrPL00 };
