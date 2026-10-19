/* PL13Tlk_usa.c, retail sf33rd.xbe.
 * The PS2 file's data (ps2.path), checked by analysis-ps2map/portdata.py
 * against the XBE: each table at its data.txt address, or at the
 * address a checked table's pointer to it holds ("placed by").
 * msgTalkAdrPL13 0x327498 size 0x1c: match (placed by pl13tlk_usa_tbl).
 * msgTalkCtrPL13 0x3274b4 size 0x7: match (placed by pl13tlk_usa_tbl).
 * msgTlkPL13_00P 0x327464 size 0x4: match (placed by msgTalkAdrPL13).
 * msgTlkPL13_01P 0x327468 size 0x8: match (placed by msgTalkAdrPL13).
 * msgTlkPL13_02P 0x327470 size 0x8: match (placed by msgTalkAdrPL13).
 * msgTlkPL13_03P 0x327478 size 0x8: match (placed by msgTalkAdrPL13).
 * msgTlkPL13_04P 0x327480 size 0x8: match (placed by msgTalkAdrPL13).
 * msgTlkPL13_05P 0x327488 size 0x8: match (placed by msgTalkAdrPL13).
 * msgTlkPL13_06P 0x327490 size 0x8: match (placed by msgTalkAdrPL13).
 * pl13tlk_usa_tbl 0x3274bc size 0x8: match (placed by pl_tlk_tbl).
 */

#include "structs.h"
#include <stddef.h>

/* from sf33rd/Source/Game/Message3rd/C_USA/PL13Tlk_usa.h */
extern MessageTable pl13tlk_usa_tbl;

static s8* msgTlkPL13_00P[1] = { "" };
static s8* msgTlkPL13_01P[2] = {
    "  I understand your jealousy. There is          ",
    "  a huge gap between humans and a god.          ",
};
static s8* msgTlkPL13_02P[2] = {
    "  You cannot forgive me                         ",
    "  because you cannot deny me.                   ",
};
static s8* msgTlkPL13_03P[2] = {
    "  Let me grant you your death as a              ",
    "  show of mercy from your brother!              ",
};
static s8* msgTlkPL13_04P[2] = {
    "  When I look into the past,                    ",
    "  I see dishonor and hatred.                    ",
};
static s8* msgTlkPL13_05P[2] = {
    "  When I look into the future,                  ",
    "  I am free from the corruption.                ",
};
static s8* msgTlkPL13_06P[2] = {
    "  How glorious it is...                         ",
    "  A world without you!                          ",
};

static s8** msgTalkAdrPL13[7] = {
    msgTlkPL13_00P, msgTlkPL13_01P, msgTlkPL13_02P, msgTlkPL13_03P, msgTlkPL13_04P, msgTlkPL13_05P, msgTlkPL13_06P,
};

static s8 msgTalkCtrPL13[7] = { 1, 2, 2, 2, 2, 2, 2 };

MessageTable pl13tlk_usa_tbl = { msgTalkAdrPL13, msgTalkCtrPL13 };
