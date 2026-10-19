/* PL18Tlk_usa.c, retail sf33rd.xbe.
 * The PS2 file's data (ps2.path), checked by analysis-ps2map/portdata.py
 * against the XBE: each table at its data.txt address, or at the
 * address a checked table's pointer to it holds ("placed by").
 * msgTalkAdrPL18 0x327f24 size 0x18: match (placed by pl18tlk_usa_tbl).
 * msgTalkCtrPL18 0x327f3c size 0x6: match (placed by pl18tlk_usa_tbl).
 * msgTlkPL18_00P 0x327ef8 size 0x4: match (placed by msgTalkAdrPL18).
 * msgTlkPL18_01P 0x327efc size 0x8: match (placed by msgTalkAdrPL18).
 * msgTlkPL18_02P 0x327f04 size 0x8: match (placed by msgTalkAdrPL18).
 * msgTlkPL18_03P 0x327f0c size 0x8: match (placed by msgTalkAdrPL18).
 * msgTlkPL18_04P 0x327f14 size 0x8: match (placed by msgTalkAdrPL18).
 * msgTlkPL18_05P 0x327f1c size 0x8: match (placed by msgTalkAdrPL18).
 * pl18tlk_usa_tbl 0x327f44 size 0x8: match (placed by pl_tlk_tbl).
 */

#include "structs.h"
#include <stddef.h>

/* from sf33rd/Source/Game/Message3rd/C_USA/PL18Tlk_usa.h */
extern MessageTable pl18tlk_usa_tbl;

static s8* msgTlkPL18_00P[1] = { "" };
static s8* msgTlkPL18_01P[2] = {
    "  Why?! Why can't you                           ",
    "  just leave me alone?!                         ",
};
static s8* msgTlkPL18_02P[2] = {
    "  I'm just a failure, right?!                   ",
    "  I have nothing you want!                      ",
};
static s8* msgTlkPL18_03P[2] = {
    "  Your body is full of dangerous,               ",
    "  confidential information.                     ",
};
static s8* msgTlkPL18_04P[2] = {
    "  Knowledge of your existence can               ",
    "  never be allowed into the world.              ",
};
static s8* msgTlkPL18_05P[2] = {
    "  It's up to each of us to decide               ",
    "  whether or not we should exist!               ",
};

static s8** msgTalkAdrPL18[6] = {
    msgTlkPL18_00P, msgTlkPL18_01P, msgTlkPL18_02P, msgTlkPL18_03P, msgTlkPL18_04P, msgTlkPL18_05P,
};

static s8 msgTalkCtrPL18[6] = { 1, 2, 2, 2, 2, 2 };

MessageTable pl18tlk_usa_tbl = { msgTalkAdrPL18, msgTalkCtrPL18 };
