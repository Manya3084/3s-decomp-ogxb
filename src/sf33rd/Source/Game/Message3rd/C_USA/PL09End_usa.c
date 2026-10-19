/* PL09End_usa.c, retail sf33rd.xbe.
 * The PS2 file's data (ps2.path), checked by analysis-ps2map/portdata.py
 * against the XBE: each table at its data.txt address, or at the
 * address a checked table's pointer to it holds ("placed by").
 * msgEndAdrPL09 0x326b24 size 0x30: match (placed by pl09end_usa_tbl).
 * msgEndCtrPL09 0x326b54 size 0xc: match (placed by pl09end_usa_tbl).
 * msgEndPL09_00 0x326ad4 size 0x4: match (placed by msgEndAdrPL09).
 * msgEndPL09_01 0x326ad8 size 0x8: match (placed by msgEndAdrPL09).
 * msgEndPL09_02 0x326ae0 size 0x8: match (placed by msgEndAdrPL09).
 * msgEndPL09_03 0x326ae8 size 0x8: match (placed by msgEndAdrPL09).
 * msgEndPL09_04 0x326af0 size 0x4: match (placed by msgEndAdrPL09).
 * msgEndPL09_05 0x326af4 size 0x8: match (placed by msgEndAdrPL09).
 * msgEndPL09_06 0x326afc size 0x8: match (placed by msgEndAdrPL09).
 * msgEndPL09_07 0x326b04 size 0x8: match (placed by msgEndAdrPL09).
 * msgEndPL09_08 0x326b0c size 0x8: match (placed by msgEndAdrPL09).
 * msgEndPL09_09 0x326b14 size 0x8: match (placed by msgEndAdrPL09).
 * msgEndPL09_10 0x326b1c size 0x4: match (placed by msgEndAdrPL09).
 * msgEndPL09_11 0x326b20 size 0x4: match (placed by msgEndAdrPL09).
 * pl09end_usa_tbl 0x326b60 size 0x8: match (placed by pl_end_tbl).
 */

#include "structs.h"
#include <stddef.h>

/* from sf33rd/Source/Game/Message3rd/C_USA/PL09End_usa.h */
extern MessageTable pl09end_usa_tbl;

static s8* msgEndPL09_00[1] = { "" };
static s8* msgEndPL09_01[2] = {
    "   Hee hee hee... It's been 50 years            ",
    "   since I've trained this seriously!           ",
};
static s8* msgEndPL09_02[2] = {
    "   Whenever I see that kid,                     ",
    "   my blood begins to boil again...             ",
};
static s8* msgEndPL09_03[2] = {
    "   He's pretty unique... I guess I              ",
    "   won't be bored for the time being!           ",
};
static s8* msgEndPL09_04[1] = { "   Hmm??                                        " };
static s8* msgEndPL09_05[2] = {
    "   I thought I heard that                       ",
    "   strange old man's voice...?                  ",
};
static s8* msgEndPL09_06[2] = {
    "   Maybe it was just                            ",
    "   my imagination...                            ",
};
static s8* msgEndPL09_07[2] = {
    "   He must be training so                       ",
    "   hard, this very moment!                      ",
};
static s8* msgEndPL09_08[2] = {
    "   I hope that he becomes so strong,            ",
    "   that I'll have to use both my arms!          ",
};
static s8* msgEndPL09_09[2] = {
    "   But... It would take at least 15             ",
    "   years before that could happen...            ",
};
static s8* msgEndPL09_10[1] = { "   Maybe I should take a rest now...            " };
static s8* msgEndPL09_11[1] = { "   Whew!                                        " };

static s8** msgEndAdrPL09[12] = {
    msgEndPL09_00, msgEndPL09_01, msgEndPL09_02, msgEndPL09_03, msgEndPL09_04, msgEndPL09_05,
    msgEndPL09_06, msgEndPL09_07, msgEndPL09_08, msgEndPL09_09, msgEndPL09_10, msgEndPL09_11,
};

static s8 msgEndCtrPL09[12] = { 1, 2, 2, 2, 1, 2, 2, 2, 2, 2, 1, 1 };

MessageTable pl09end_usa_tbl = { msgEndAdrPL09, msgEndCtrPL09 };
