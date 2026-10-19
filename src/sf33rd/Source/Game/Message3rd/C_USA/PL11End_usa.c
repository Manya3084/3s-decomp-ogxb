/* PL11End_usa.c, retail sf33rd.xbe.
 * The PS2 file's data (ps2.path), checked by analysis-ps2map/portdata.py
 * against the XBE: each table at its data.txt address, or at the
 * address a checked table's pointer to it holds ("placed by").
 * msgEndAdrPL11 0x326fdc size 0x3c: match (placed by pl11end_usa_tbl).
 * msgEndCtrPL11 0x327018 size 0xf: match (placed by pl11end_usa_tbl).
 * msgEndPL11_00 0x326f6c size 0x4: match (placed by msgEndAdrPL11).
 * msgEndPL11_01 0x326f70 size 0x8: match (placed by msgEndAdrPL11).
 * msgEndPL11_02 0x326f78 size 0x8: match (placed by msgEndAdrPL11).
 * msgEndPL11_03 0x326f80 size 0x4: match (placed by msgEndAdrPL11).
 * msgEndPL11_04 0x326f84 size 0x8: match (placed by msgEndAdrPL11).
 * msgEndPL11_05 0x326f8c size 0x8: match (placed by msgEndAdrPL11).
 * msgEndPL11_06 0x326f94 size 0x8: match (placed by msgEndAdrPL11).
 * msgEndPL11_07 0x326f9c size 0x8: match (placed by msgEndAdrPL11).
 * msgEndPL11_08 0x326fa4 size 0x8: match (placed by msgEndAdrPL11).
 * msgEndPL11_09 0x326fac size 0x8: match (placed by msgEndAdrPL11).
 * msgEndPL11_10 0x326fb4 size 0x8: match (placed by msgEndAdrPL11).
 * msgEndPL11_11 0x326fbc size 0x8: match (placed by msgEndAdrPL11).
 * msgEndPL11_12 0x326fc4 size 0x8: match (placed by msgEndAdrPL11).
 * msgEndPL11_13 0x326fcc size 0x8: match (placed by msgEndAdrPL11).
 * msgEndPL11_14 0x326fd4 size 0x8: match (placed by msgEndAdrPL11).
 * pl11end_usa_tbl 0x327028 size 0x8: match (placed by pl_end_tbl).
 */

#include "structs.h"
#include <stddef.h>

/* from sf33rd/Source/Game/Message3rd/C_USA/PL11End_usa.h */
extern MessageTable pl11end_usa_tbl;

static s8* msgEndPL11_00[1] = { "" };
static s8* msgEndPL11_01[2] = {
    "   Here we go!                                  ",
    "   Sho... Ryuuuu... Kennnn!                     ",
};
static s8* msgEndPL11_02[2] = {
    "   Oh no! He doesn't seem                       ",
    "   to be getting back up!                       ",
};
static s8* msgEndPL11_03[1] = { "   The battle is over!!                         " };
static s8* msgEndPL11_04[2] = {
    "   Showing the strength that we've              ",
    "   come to expect, the winner is Ken!           ",
};
static s8* msgEndPL11_05[2] = {
    "   Three U.S. Championships in a row!           ",
    "   History has been made!                       ",
};
static s8* msgEndPL11_06[2] = {
    "   This is an exciting moment for Ken,          ",
    "   his family, and his friends!                 ",
};
static s8* msgEndPL11_07[2] = {
    "   See? I knocked him out in                    ",
    "   30 seconds, as I promised!                   ",
};
static s8* msgEndPL11_08[2] = {
    "   Oh yeah! Here you go, Sean...                ",
    "   This is for you!                             ",
};
static s8* msgEndPL11_09[2] = {
    "   The U.S. Championship trophy...              ",
    "   You wanted it, right?                        ",
};
static s8* msgEndPL11_10[2] = {
    "   M... Master!                                 ",
    "   That's not what I meant!                     ",
};
static s8* msgEndPL11_11[2] = {
    "   It's meaningless if I did not                ",
    "   win it with my own effort!                   ",
};
static s8* msgEndPL11_12[2] = {
    "   Oh, is that so? You shouldn't                ",
    "   be too worried about that.                   ",
};
static s8* msgEndPL11_13[2] = {
    "   At the very least, you must pass             ",
    "   the qualifying rounds next time!             ",
};
static s8* msgEndPL11_14[2] = {
    "   But... You won't be the winner,              ",
    "   since you can't beat me! Ha ha ha!           ",
};

static s8** msgEndAdrPL11[15] = {
    msgEndPL11_00, msgEndPL11_01, msgEndPL11_02, msgEndPL11_03, msgEndPL11_04,
    msgEndPL11_05, msgEndPL11_06, msgEndPL11_07, msgEndPL11_08, msgEndPL11_09,
    msgEndPL11_10, msgEndPL11_11, msgEndPL11_12, msgEndPL11_13, msgEndPL11_14,
};

static s8 msgEndCtrPL11[15] = { 1, 2, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 };

MessageTable pl11end_usa_tbl = { msgEndAdrPL11, msgEndCtrPL11 };
