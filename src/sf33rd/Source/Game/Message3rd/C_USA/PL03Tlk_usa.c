/* PL03Tlk_usa.c, retail sf33rd.xbe.
 * The PS2 file's data (ps2.path), checked by analysis-ps2map/portdata.py
 * against the XBE: each table at its data.txt address, or at the
 * address a checked table's pointer to it holds ("placed by").
 * msgTalkAdrPL03 0x325ecc size 0x1c: match (placed by pl03tlk_usa_tbl).
 * msgTalkCtrPL03 0x325ee8 size 0x7: match (placed by pl03tlk_usa_tbl).
 * msgTlkPL03_00P 0x325e9c size 0x4: match (placed by msgTalkAdrPL03).
 * msgTlkPL03_01P 0x325ea0 size 0x4: match (placed by msgTalkAdrPL03).
 * msgTlkPL03_02P 0x325ea4 size 0x8: match (placed by msgTalkAdrPL03).
 * msgTlkPL03_03P 0x325eac size 0x8: match (placed by msgTalkAdrPL03).
 * msgTlkPL03_04P 0x325eb4 size 0x8: match (placed by msgTalkAdrPL03).
 * msgTlkPL03_05P 0x325ebc size 0x8: match (placed by msgTalkAdrPL03).
 * msgTlkPL03_06P 0x325ec4 size 0x8: match (placed by msgTalkAdrPL03).
 * pl03tlk_usa_tbl 0x325ef0 size 0x8: match (placed by pl_tlk_tbl).
 */

#include "structs.h"
#include <stddef.h>

/* from sf33rd/Source/Game/Message3rd/C_USA/PL03Tlk_usa.h */
extern MessageTable pl03tlk_usa_tbl;

static s8* msgTlkPL03_00P[1] = { "" };
static s8* msgTlkPL03_01P[1] = { "  So, you are Gill...                           " };
static s8* msgTlkPL03_02P[2] = {
    "  What's up with your plan to conquer           ",
    "  the world?! Wake up, already!                 ",
};
static s8* msgTlkPL03_03P[2] = {
    "  Youth tends to be reckless, but it            ",
    "  is not my intention to blame you.             ",
};
static s8* msgTlkPL03_04P[2] = {
    "  Just think about it... What is                ",
    "  the ideal way for you to live?                ",
};
static s8* msgTlkPL03_05P[2] = {
    "  It should be obvious to a boy like            ",
    "  you. Just leave everything to me!             ",
};
static s8* msgTlkPL03_06P[2] = {
    "  Arrrgh! Stop preaching to me!                 ",
    "  Let our fists do the talking!                 ",
};

static s8** msgTalkAdrPL03[7] = {
    msgTlkPL03_00P, msgTlkPL03_01P, msgTlkPL03_02P, msgTlkPL03_03P, msgTlkPL03_04P, msgTlkPL03_05P, msgTlkPL03_06P,
};

static s8 msgTalkCtrPL03[7] = { 1, 1, 2, 2, 2, 2, 2 };

MessageTable pl03tlk_usa_tbl = { msgTalkAdrPL03, msgTalkCtrPL03 };
