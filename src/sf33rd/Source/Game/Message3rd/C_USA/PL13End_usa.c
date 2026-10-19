/* PL13End_usa.c, retail sf33rd.xbe.
 * The PS2 file's data (ps2.path), checked by analysis-ps2map/portdata.py
 * against the XBE: each table at its data.txt address, or at the
 * address a checked table's pointer to it holds ("placed by").
 * msgEndAdrPL13 0x327420 size 0x30: match (placed by pl13end_usa_tbl).
 * msgEndCtrPL13 0x327450 size 0xc: match (placed by pl13end_usa_tbl).
 * msgEndPL13_00 0x3273c4 size 0x4: match (placed by msgEndAdrPL13).
 * msgEndPL13_01 0x3273c8 size 0x8: match (placed by msgEndAdrPL13).
 * msgEndPL13_02 0x3273d0 size 0x8: match (placed by msgEndAdrPL13).
 * msgEndPL13_03 0x3273d8 size 0x8: match (placed by msgEndAdrPL13).
 * msgEndPL13_04 0x3273e0 size 0x8: match (placed by msgEndAdrPL13).
 * msgEndPL13_05 0x3273e8 size 0x8: match (placed by msgEndAdrPL13).
 * msgEndPL13_06 0x3273f0 size 0x8: match (placed by msgEndAdrPL13).
 * msgEndPL13_07 0x3273f8 size 0x8: match (placed by msgEndAdrPL13).
 * msgEndPL13_08 0x327400 size 0x8: match (placed by msgEndAdrPL13).
 * msgEndPL13_09 0x327408 size 0x8: match (placed by msgEndAdrPL13).
 * msgEndPL13_10 0x327410 size 0x8: match (placed by msgEndAdrPL13).
 * msgEndPL13_11 0x327418 size 0x8: match (placed by msgEndAdrPL13).
 * pl13end_usa_tbl 0x32745c size 0x8: match (placed by pl_end_tbl).
 */

#include "structs.h"
#include <stddef.h>

/* from sf33rd/Source/Game/Message3rd/C_USA/PL13End_usa.h */
extern MessageTable pl13end_usa_tbl;

static s8* msgEndPL13_00[1] = { "" };
static s8* msgEndPL13_01[2] = {
    "   So those \"brains\" they've collected          ",
    "   for 2000 years are stored here...            ",
};
static s8* msgEndPL13_02[2] = {
    "   I don't know the value of these,             ",
    "   but they are ugly and stupid.                ",
};
static s8* msgEndPL13_03[2] = {
    "   ...Just a mass of junk with no               ",
    "   ability to take positive action!             ",
};
static s8* msgEndPL13_04[2] = {
    "   Brother! What are you looking at             ",
    "   now? Can you see the world?                  ",
};
static s8* msgEndPL13_05[2] = {
    "   Are you watching how your                    ",
    "   ideal world is being built?                  ",
};
static s8* msgEndPL13_06[2] = {
    "   Ha... ha ha ha ha ha!                        ",
    "   Ha ha ha ha ha ha ha ha!!                    ",
};
static s8* msgEndPL13_07[2] = {
    "   Checking ID... Verified as                   ",
    "   the legitimate successor...                  ",
};
static s8* msgEndPL13_08[2] = {
    "   Enter self-destruction code:                 ",
    "   A22ST8996HYXW...                             ",
};
static s8* msgEndPL13_09[2] = {
    "   There is no mission or legacy                ",
    "   left for me to succeed!                      ",
};
static s8* msgEndPL13_10[2] = {
    "   Now, my own story will                       ",
    "   unfold from this moment on!                  ",
};
static s8* msgEndPL13_11[2] = {
    "   I hereby define this year as the             ",
    "   first year of \"A.U.\"(After Urien)!!          ",
};

static s8** msgEndAdrPL13[12] = {
    msgEndPL13_00, msgEndPL13_01, msgEndPL13_02, msgEndPL13_03, msgEndPL13_04, msgEndPL13_05,
    msgEndPL13_06, msgEndPL13_07, msgEndPL13_08, msgEndPL13_09, msgEndPL13_10, msgEndPL13_11,
};

static s8 msgEndCtrPL13[12] = { 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 };

MessageTable pl13end_usa_tbl = { msgEndAdrPL13, msgEndCtrPL13 };
