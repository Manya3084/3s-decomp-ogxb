/* PL04Tlk_usa.c, retail sf33rd.xbe.
 * The PS2 file's data (ps2.path), checked by analysis-ps2map/portdata.py
 * against the XBE: each table at its data.txt address, or at the
 * address a checked table's pointer to it holds ("placed by").
 * msgTalkAdrPL04 0x3260d0 size 0x18: match (placed by pl04tlk_usa_tbl).
 * msgTalkCtrPL04 0x3260e8 size 0x6: match (placed by pl04tlk_usa_tbl).
 * msgTlkPL04_00P 0x3260a4 size 0x4: match (placed by msgTalkAdrPL04).
 * msgTlkPL04_01P 0x3260a8 size 0x8: match (placed by msgTalkAdrPL04).
 * msgTlkPL04_02P 0x3260b0 size 0x8: match (placed by msgTalkAdrPL04).
 * msgTlkPL04_03P 0x3260b8 size 0x8: match (placed by msgTalkAdrPL04).
 * msgTlkPL04_04P 0x3260c0 size 0x8: match (placed by msgTalkAdrPL04).
 * msgTlkPL04_05P 0x3260c8 size 0x8: match (placed by msgTalkAdrPL04).
 * pl04tlk_usa_tbl 0x3260f0 size 0x8: match (placed by pl_tlk_tbl).
 */

#include "structs.h"
#include <stddef.h>

/* from sf33rd/Source/Game/Message3rd/C_USA/PL04Tlk_usa.h */
extern MessageTable pl04tlk_usa_tbl;

static s8* msgTlkPL04_00P[1] = { "" };
static s8* msgTlkPL04_01P[2] = {
    "  So, you're that famous                        ",
    "  Samurai fighter, aren't you?                  ",
};
static s8* msgTlkPL04_02P[2] = {
    "  What a coincidence! I've                      ",
    "  been looking for you, too!                    ",
};
static s8* msgTlkPL04_03P[2] = {
    "  I'd love a chance to fight with               ",
    "  England's #1 perfect boxer!                   ",
};
static s8* msgTlkPL04_04P[2] = {
    "  Good show lad! You behave like a              ",
    "  gentleman, yet have great strength!           ",
};
static s8* msgTlkPL04_05P[2] = {
    "  This shall be quite enjoyable!                ",
    "  Don't you agree?                              ",
};

static s8** msgTalkAdrPL04[6] = {
    msgTlkPL04_00P, msgTlkPL04_01P, msgTlkPL04_02P, msgTlkPL04_03P, msgTlkPL04_04P, msgTlkPL04_05P,
};

static s8 msgTalkCtrPL04[6] = { 1, 2, 2, 2, 2, 2 };

MessageTable pl04tlk_usa_tbl = { msgTalkAdrPL04, msgTalkCtrPL04 };
