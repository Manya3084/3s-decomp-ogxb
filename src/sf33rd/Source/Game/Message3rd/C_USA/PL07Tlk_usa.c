/* PL07Tlk_usa.c, retail sf33rd.xbe.
 * The PS2 file's data (ps2.path), checked by analysis-ps2map/portdata.py
 * against the XBE: each table at its data.txt address, or at the
 * address a checked table's pointer to it holds ("placed by").
 * msgTalkAdrPL07 0x32676c size 0x20: match (placed by pl07tlk_usa_tbl).
 * msgTalkCtrPL07 0x32678c size 0x8: match (placed by pl07tlk_usa_tbl).
 * msgTlkPL07_00P 0x326738 size 0x4: match (placed by msgTalkAdrPL07).
 * msgTlkPL07_01P 0x32673c size 0x4: match (placed by msgTalkAdrPL07).
 * msgTlkPL07_02P 0x326740 size 0x8: match (placed by msgTalkAdrPL07).
 * msgTlkPL07_03P 0x326748 size 0x8: match (placed by msgTalkAdrPL07).
 * msgTlkPL07_04P 0x326750 size 0x8: match (placed by msgTalkAdrPL07).
 * msgTlkPL07_05P 0x326758 size 0x8: match (placed by msgTalkAdrPL07).
 * msgTlkPL07_06P 0x326760 size 0x4: match (placed by msgTalkAdrPL07).
 * msgTlkPL07_07P 0x326764 size 0x8: match (placed by msgTalkAdrPL07).
 * pl07tlk_usa_tbl 0x326794 size 0x8: match (placed by pl_tlk_tbl).
 */

#include "structs.h"
#include <stddef.h>

/* from sf33rd/Source/Game/Message3rd/C_USA/PL07Tlk_usa.h */
extern MessageTable pl07tlk_usa_tbl;

static s8* msgTlkPL07_00P[1] = { "" };
static s8* msgTlkPL07_01P[1] = { "  Excuse me, are you a Sennin?                  " };
static s8* msgTlkPL07_02P[2] = {
    "  That's right. I'm the great Sennin!           ",
    "  What do you want, girl?                       ",
};
static s8* msgTlkPL07_03P[2] = {
    "  (He's as old as they get, but he is           ",
    "  also a master fighter, I guess...)            ",
};
static s8* msgTlkPL07_04P[2] = {
    "  Well, I know it's unusual, but I'm            ",
    "  in the middle of graduation exam.             ",
};
static s8* msgTlkPL07_05P[2] = {
    "  They won't allow me to pass unless            ",
    "  I defeat you in 5 minutes... So...            ",
};
static s8* msgTlkPL07_06P[1] = { "  Fight with me!                                " };
static s8* msgTlkPL07_07P[2] = {
    "  What?! I thought you wanted to go on          ",
    "  a date with me! I'm disappointed!             ",
};

static s8** msgTalkAdrPL07[8] = {
    msgTlkPL07_00P, msgTlkPL07_01P, msgTlkPL07_02P, msgTlkPL07_03P,
    msgTlkPL07_04P, msgTlkPL07_05P, msgTlkPL07_06P, msgTlkPL07_07P,
};

static s8 msgTalkCtrPL07[8] = { 1, 1, 2, 2, 2, 2, 1, 2 };

MessageTable pl07tlk_usa_tbl = { msgTalkAdrPL07, msgTalkCtrPL07 };
