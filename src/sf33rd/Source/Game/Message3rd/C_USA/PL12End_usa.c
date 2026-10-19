/* PL12End_usa.c, retail sf33rd.xbe.
 * The PS2 file's data (ps2.path), checked by analysis-ps2map/portdata.py
 * against the XBE: each table at its data.txt address, or at the
 * address a checked table's pointer to it holds ("placed by").
 * msgEndAdrPL12 0x3271f8 size 0x34: match (placed by pl12end_usa_tbl).
 * msgEndCtrPL12 0x32722c size 0xd: match (placed by pl12end_usa_tbl).
 * msgEndPL12_00 0x3271a4 size 0x4: match (placed by msgEndAdrPL12).
 * msgEndPL12_01 0x3271a8 size 0x4: match (placed by msgEndAdrPL12).
 * msgEndPL12_02 0x3271ac size 0x8: match (placed by msgEndAdrPL12).
 * msgEndPL12_03 0x3271b4 size 0x4: match (placed by msgEndAdrPL12).
 * msgEndPL12_04 0x3271b8 size 0x4: match (placed by msgEndAdrPL12).
 * msgEndPL12_05 0x3271bc size 0x8: match (placed by msgEndAdrPL12).
 * msgEndPL12_06 0x3271c4 size 0x8: match (placed by msgEndAdrPL12).
 * msgEndPL12_07 0x3271cc size 0x4: match (placed by msgEndAdrPL12).
 * msgEndPL12_08 0x3271d0 size 0x8: match (placed by msgEndAdrPL12).
 * msgEndPL12_09 0x3271d8 size 0x8: match (placed by msgEndAdrPL12).
 * msgEndPL12_10 0x3271e0 size 0x8: match (placed by msgEndAdrPL12).
 * msgEndPL12_11 0x3271e8 size 0x8: match (placed by msgEndAdrPL12).
 * msgEndPL12_12 0x3271f0 size 0x8: match (placed by msgEndAdrPL12).
 * pl12end_usa_tbl 0x32723c size 0x8: match (placed by pl_end_tbl).
 */

#include "structs.h"
#include <stddef.h>

/* from sf33rd/Source/Game/Message3rd/C_USA/PL12End_usa.h */
extern MessageTable pl12end_usa_tbl;

static s8* msgEndPL12_00[1] = { "" };
static s8* msgEndPL12_01[1] = { "   Victory!!                                    " };
static s8* msgEndPL12_02[2] = {
    "   Sean has won the first tournament            ",
    "   of his fighting career!                      ",
};
static s8* msgEndPL12_03[1] = { "   I did it! Finally!                           " };
static s8* msgEndPL12_04[1] = { "   Now... I'm the U.S. Champion!                " };
static s8* msgEndPL12_05[2] = {
    "   Now I'm at the same level as my              ",
    "   master! It's a dream come true!              ",
};
static s8* msgEndPL12_06[2] = {
    "   ...llo ...Hello? Sean!                       ",
    "   (...Wh ...What?)                             ",
};
static s8* msgEndPL12_07[1] = { "   Are you okay?!                               " };
static s8* msgEndPL12_08[2] = {
    "   Good! You've come to your senses...          ",
    "   I think...                                   ",
};
static s8* msgEndPL12_09[2] = {
    "   It was close... You almost passed            ",
    "   the qualifying rounds!                       ",
};
static s8* msgEndPL12_10[2] = {
    "   You did not train yourself                   ",
    "   properly. Try harder next time!              ",
};
static s8* msgEndPL12_11[2] = {
    "   Okay then, leave it to me! I'll get          ",
    "   my revenge by winning the next one!          ",
};
static s8* msgEndPL12_12[2] = {
    "   Wha? It was just a dream?!                   ",
    "   But someday... Someday I will win!           ",
};

static s8** msgEndAdrPL12[13] = {
    msgEndPL12_00, msgEndPL12_01, msgEndPL12_02, msgEndPL12_03, msgEndPL12_04, msgEndPL12_05, msgEndPL12_06,
    msgEndPL12_07, msgEndPL12_08, msgEndPL12_09, msgEndPL12_10, msgEndPL12_11, msgEndPL12_12,
};

static s8 msgEndCtrPL12[13] = { 1, 1, 2, 1, 1, 2, 2, 1, 2, 2, 2, 2, 2 };

MessageTable pl12end_usa_tbl = { msgEndAdrPL12, msgEndCtrPL12 };
