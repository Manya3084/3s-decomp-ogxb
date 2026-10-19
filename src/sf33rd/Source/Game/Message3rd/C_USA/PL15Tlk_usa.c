/* PL15Tlk_usa.c, retail sf33rd.xbe.
 * The PS2 file's data (ps2.path), checked by analysis-ps2map/portdata.py
 * against the XBE: each table at its data.txt address, or at the
 * address a checked table's pointer to it holds ("placed by").
 * msgTalkAdrPL15 0x327870 size 0x20: match (placed by pl15tlk_usa_tbl).
 * msgTalkCtrPL15 0x327890 size 0x8: match (placed by pl15tlk_usa_tbl).
 * msgTlkPL15_00P 0x327838 size 0x4: match (placed by msgTalkAdrPL15).
 * msgTlkPL15_01P 0x32783c size 0x8: match (placed by msgTalkAdrPL15).
 * msgTlkPL15_02P 0x327844 size 0x8: match (placed by msgTalkAdrPL15).
 * msgTlkPL15_03P 0x32784c size 0x4: match (placed by msgTalkAdrPL15).
 * msgTlkPL15_04P 0x327850 size 0x8: match (placed by msgTalkAdrPL15).
 * msgTlkPL15_05P 0x327858 size 0x8: match (placed by msgTalkAdrPL15).
 * msgTlkPL15_06P 0x327860 size 0x8: match (placed by msgTalkAdrPL15).
 * msgTlkPL15_07P 0x327868 size 0x8: match (placed by msgTalkAdrPL15).
 * pl15tlk_usa_tbl 0x327898 size 0x8: match (placed by pl_tlk_tbl).
 */

#include "structs.h"
#include <stddef.h>

/* from sf33rd/Source/Game/Message3rd/C_USA/PL15Tlk_usa.h */
extern MessageTable pl15tlk_usa_tbl;

static s8* msgTlkPL15_00P[1] = { "" };
static s8* msgTlkPL15_01P[2] = {
    "  I don't know what your                        ",
    "  scheme is...                                  ",
};
static s8* msgTlkPL15_02P[2] = {
    "  But I can't let you                           ",
    "  harm small children!                          ",
};
static s8* msgTlkPL15_03P[1] = { "  Where is that girl?                           " };
static s8* msgTlkPL15_04P[2] = {
    "  How could you ask to see me for such          ",
    "  a trifle thing? You must be a fool!           ",
};
static s8* msgTlkPL15_05P[2] = {
    "  I'll give you the girl, but you               ",
    "  must entertain me in return.                  ",
};
static s8* msgTlkPL15_06P[2] = {
    "  Your legendary legs are said to               ",
    "  have destroyed \"that organization.\"           ",
};
static s8* msgTlkPL15_07P[2] = {
    "  Let me find out for myself,                   ",
    "  if the rumors about you are true...           ",
};

static s8** msgTalkAdrPL15[8] = {
    msgTlkPL15_00P, msgTlkPL15_01P, msgTlkPL15_02P, msgTlkPL15_03P,
    msgTlkPL15_04P, msgTlkPL15_05P, msgTlkPL15_06P, msgTlkPL15_07P,
};

static s8 msgTalkCtrPL15[8] = { 1, 2, 2, 1, 2, 2, 2, 2 };

MessageTable pl15tlk_usa_tbl = { msgTalkAdrPL15, msgTalkCtrPL15 };
