/* PL05Tlk_usa.c, retail sf33rd.xbe.
 * The PS2 file's data (ps2.path), checked by analysis-ps2map/portdata.py
 * against the XBE: each table at its data.txt address, or at the
 * address a checked table's pointer to it holds ("placed by").
 * msgTalkAdrPL05 0x3262f8 size 0x18: match (placed by pl05tlk_usa_tbl).
 * msgTalkCtrPL05 0x326310 size 0x6: match (placed by pl05tlk_usa_tbl).
 * msgTlkPL05_00P 0x3262d0 size 0x4: match (placed by msgTalkAdrPL05).
 * msgTlkPL05_01P 0x3262d4 size 0x8: match (placed by msgTalkAdrPL05).
 * msgTlkPL05_02P 0x3262dc size 0x8: match (placed by msgTalkAdrPL05).
 * msgTlkPL05_03P 0x3262e4 size 0x4: match (placed by msgTalkAdrPL05).
 * msgTlkPL05_04P 0x3262e8 size 0x8: match (placed by msgTalkAdrPL05).
 * msgTlkPL05_05P 0x3262f0 size 0x8: match (placed by msgTalkAdrPL05).
 * pl05tlk_usa_tbl 0x326318 size 0x8: match (placed by pl_tlk_tbl).
 */

#include "structs.h"
#include <stddef.h>

/* from sf33rd/Source/Game/Message3rd/C_USA/PL05Tlk_usa.h */
extern MessageTable pl05tlk_usa_tbl;

static s8* msgTlkPL05_00P[1] = { "" };
static s8* msgTlkPL05_01P[2] = {
    "  Stop already! It's time for                   ",
    "  you to show your true self!                   ",
};
static s8* msgTlkPL05_02P[2] = {
    "  It's clear to me! Gill was the                ",
    "  one who sent you, right?!                     ",
};
static s8* msgTlkPL05_03P[1] = { "" };
static s8* msgTlkPL05_04P[2] = {
    "  I won't lose to a mass production             ",
    "  model, even if you are \"perfect!\"             ",
};
static s8* msgTlkPL05_05P[2] = {
    "  I'll put what's left of you into              ",
    "  a box that I will send to Gill!               ",
};

static s8** msgTalkAdrPL05[6] = {
    msgTlkPL05_00P, msgTlkPL05_01P, msgTlkPL05_02P, msgTlkPL05_03P, msgTlkPL05_04P, msgTlkPL05_05P,
};

static s8 msgTalkCtrPL05[6] = { 1, 2, 2, 1, 2, 2 };

MessageTable pl05tlk_usa_tbl = { msgTalkAdrPL05, msgTalkCtrPL05 };
