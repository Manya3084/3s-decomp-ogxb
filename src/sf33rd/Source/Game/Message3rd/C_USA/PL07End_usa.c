/* PL07End_usa.c, retail sf33rd.xbe.
 * The PS2 file's data (ps2.path), checked by analysis-ps2map/portdata.py
 * against the XBE: each table at its data.txt address, or at the
 * address a checked table's pointer to it holds ("placed by").
 * msgEndAdrPL07 0x3266e4 size 0x3c: match (placed by pl07end_usa_tbl).
 * msgEndCtrPL07 0x326720 size 0xf: match (placed by pl07end_usa_tbl).
 * msgEndPL07_00 0x32667c size 0x4: match (placed by msgEndAdrPL07).
 * msgEndPL07_01 0x326680 size 0x8: match (placed by msgEndAdrPL07).
 * msgEndPL07_02 0x326688 size 0x8: match (placed by msgEndAdrPL07).
 * msgEndPL07_03 0x326690 size 0x8: match (placed by msgEndAdrPL07).
 * msgEndPL07_04 0x326698 size 0x4: match (placed by msgEndAdrPL07).
 * msgEndPL07_05 0x32669c size 0x8: match (placed by msgEndAdrPL07).
 * msgEndPL07_06 0x3266a4 size 0x8: match (placed by msgEndAdrPL07).
 * msgEndPL07_07 0x3266ac size 0x8: match (placed by msgEndAdrPL07).
 * msgEndPL07_08 0x3266b4 size 0x8: match (placed by msgEndAdrPL07).
 * msgEndPL07_09 0x3266bc size 0x8: match (placed by msgEndAdrPL07).
 * msgEndPL07_10 0x3266c4 size 0x8: match (placed by msgEndAdrPL07).
 * msgEndPL07_11 0x3266cc size 0x8: match (placed by msgEndAdrPL07).
 * msgEndPL07_12 0x3266d4 size 0x8: match (placed by msgEndAdrPL07).
 * msgEndPL07_13 0x3266dc size 0x4: match (placed by msgEndAdrPL07).
 * msgEndPL07_14 0x3266e0 size 0x4: match (placed by msgEndAdrPL07).
 * pl07end_usa_tbl 0x326730 size 0x8: match (placed by pl_end_tbl).
 */

#include "structs.h"
#include <stddef.h>

/* from sf33rd/Source/Game/Message3rd/C_USA/PL07End_usa.h */
extern MessageTable pl07end_usa_tbl;

static s8* msgEndPL07_00[1] = { "" };
static s8* msgEndPL07_01[2] = {
    "   \"Sarusuberi University\"...                   ",
    "   I made it, after all!                        ",
};
static s8* msgEndPL07_02[2] = {
    "   After a lifetime of training, I can          ",
    "   finally live like an ordinary girl!          ",
};
static s8* msgEndPL07_03[2] = {
    "   Exploring the campus... Making new           ",
    "   friends... Oh, I'm so excited!               ",
};
static s8* msgEndPL07_04[1] = { "   Hi there, cutie!                             " };
static s8* msgEndPL07_05[2] = {
    "   Why don't you join my club?                  ",
    "   It's so fun, you'll never leave!             ",
};
static s8* msgEndPL07_06[2] = {
    "   (And so, I devoted myself to the fun         ",
    "   activities of the club every day...          ",
};
static s8* msgEndPL07_07[2] = {
    "   I receive painful endurance training         ",
    "   under the senior's guidance...               ",
};
static s8* msgEndPL07_08[2] = {
    "   I train on the surface                       ",
    "   of the water...                              ",
};
static s8* msgEndPL07_09[2] = {
    "   And practice riding on a kite in a           ",
    "   raging storm...) Hey! Wait a minute!         ",
};
static s8* msgEndPL07_10[2] = {
    "   Ha ha ha! Ibuki! You've                      ",
    "   still got a blind side!                      ",
};
static s8* msgEndPL07_11[2] = {
    "   If you're careless like that, I'll           ",
    "   cut your carotids off next time!             ",
};
static s8* msgEndPL07_12[2] = {
    "   Ha ha ha! I can tell that you love           ",
    "   the excitement of studying Ninjitsu!         ",
};
static s8* msgEndPL07_13[1] = { "   ...What?                                     " };
static s8* msgEndPL07_14[1] = { "   ...This is not what I expected!              " };

static s8** msgEndAdrPL07[15] = {
    msgEndPL07_00, msgEndPL07_01, msgEndPL07_02, msgEndPL07_03, msgEndPL07_04,
    msgEndPL07_05, msgEndPL07_06, msgEndPL07_07, msgEndPL07_08, msgEndPL07_09,
    msgEndPL07_10, msgEndPL07_11, msgEndPL07_12, msgEndPL07_13, msgEndPL07_14,
};

static s8 msgEndCtrPL07[15] = { 1, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1 };

MessageTable pl07end_usa_tbl = { msgEndAdrPL07, msgEndCtrPL07 };
