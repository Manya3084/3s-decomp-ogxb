/* PL16Tlk_usa.c, retail sf33rd.xbe.
 * The PS2 file's data (ps2.path), checked by analysis-ps2map/portdata.py
 * against the XBE: each table at its data.txt address, or at the
 * address a checked table's pointer to it holds ("placed by").
 * msgTalkAdrPL16 0x327ad4 size 0x18: match (placed by pl16tlk_usa_tbl).
 * msgTalkCtrPL16 0x327aec size 0x6: match (placed by pl16tlk_usa_tbl).
 * msgTlkPL16_00P 0x327aac size 0x4: match (placed by msgTalkAdrPL16).
 * msgTlkPL16_01P 0x327ab0 size 0x8: match (placed by msgTalkAdrPL16).
 * msgTlkPL16_02P 0x327ab8 size 0x8: match (placed by msgTalkAdrPL16).
 * msgTlkPL16_03P 0x327ac0 size 0x4: match (placed by msgTalkAdrPL16).
 * msgTlkPL16_04P 0x327ac4 size 0x8: match (placed by msgTalkAdrPL16).
 * msgTlkPL16_05P 0x327acc size 0x8: match (placed by msgTalkAdrPL16).
 * pl16tlk_usa_tbl 0x327af4 size 0x8: match (placed by pl_tlk_tbl).
 */

#include "structs.h"
#include <stddef.h>

/* from sf33rd/Source/Game/Message3rd/C_USA/PL16Tlk_usa.h */
extern MessageTable pl16tlk_usa_tbl;

static s8* msgTlkPL16_00P[1] = { "" };
static s8* msgTlkPL16_01P[2] = {
    "  I've heard about you...                       ",
    "  You're Ryu, aren't you?                       ",
};
static s8* msgTlkPL16_02P[2] = {
    "  Your headband and that all-season             ",
    "  Karate uniform! I can't be mistaken!          ",
};
static s8* msgTlkPL16_03P[1] = { "  Now, accept my challenge!                     " };
static s8* msgTlkPL16_04P[2] = {
    "  Hmm... Your style is Karate...                ",
    "  And you seem to be skilled...                 ",
};
static s8* msgTlkPL16_05P[2] = {
    "  Interesting!                                  ",
    "  Show me your best!!                           ",
};

static s8** msgTalkAdrPL16[6] = {
    msgTlkPL16_00P, msgTlkPL16_01P, msgTlkPL16_02P, msgTlkPL16_03P, msgTlkPL16_04P, msgTlkPL16_05P,
};

static s8 msgTalkCtrPL16[6] = { 1, 2, 2, 1, 2, 2 };

MessageTable pl16tlk_usa_tbl = { msgTalkAdrPL16, msgTalkCtrPL16 };
