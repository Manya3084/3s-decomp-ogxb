/* PL05End_usa.c, retail sf33rd.xbe.
 * The PS2 file's data (ps2.path), checked by analysis-ps2map/portdata.py
 * against the XBE: each table at its data.txt address, or at the
 * address a checked table's pointer to it holds ("placed by").
 * msgEndAdrPL05 0x32627c size 0x3c: match (placed by pl05end_usa_tbl).
 * msgEndCtrPL05 0x3262b8 size 0xf: match (placed by pl05end_usa_tbl).
 * msgEndPL05_00 0x32621c size 0x4: match (placed by msgEndAdrPL05).
 * msgEndPL05_01 0x326220 size 0x8: match (placed by msgEndAdrPL05).
 * msgEndPL05_02 0x326228 size 0x8: match (placed by msgEndAdrPL05).
 * msgEndPL05_03 0x326230 size 0x8: match (placed by msgEndAdrPL05).
 * msgEndPL05_04 0x326238 size 0x4: match (placed by msgEndAdrPL05).
 * msgEndPL05_05 0x32623c size 0x8: match (placed by msgEndAdrPL05).
 * msgEndPL05_06 0x326244 size 0x8: match (placed by msgEndAdrPL05).
 * msgEndPL05_07 0x32624c size 0x8: match (placed by msgEndAdrPL05).
 * msgEndPL05_08 0x326254 size 0x4: match (placed by msgEndAdrPL05).
 * msgEndPL05_09 0x326258 size 0x8: match (placed by msgEndAdrPL05).
 * msgEndPL05_10 0x326260 size 0x4: match (placed by msgEndAdrPL05).
 * msgEndPL05_11 0x326264 size 0x8: match (placed by msgEndAdrPL05).
 * msgEndPL05_12 0x32626c size 0x4: match (placed by msgEndAdrPL05).
 * msgEndPL05_13 0x326270 size 0x4: match (placed by msgEndAdrPL05).
 * msgEndPL05_14 0x326274 size 0x8: match (placed by msgEndAdrPL05).
 * pl05end_usa_tbl 0x3262c8 size 0x8: match (placed by pl_end_tbl).
 */

#include "structs.h"
#include <stddef.h>

/* from sf33rd/Source/Game/Message3rd/C_USA/PL05End_usa.h */
extern MessageTable pl05end_usa_tbl;

static s8* msgEndPL05_00[1] = { "" };
static s8* msgEndPL05_01[2] = {
    "   Ahh!                                         ",
    "   We're cornered!!                             ",
};
static s8* msgEndPL05_02[2] = {
    "   Don't say that! We can't stop!!              ",
    "   We must never give up! Run!!                 ",
};
static s8* msgEndPL05_03[2] = {
    "   We're about to reach the woods of            ",
    "   the country border! Almost there!            ",
};
static s8* msgEndPL05_04[1] = { "   They're on the roof!                         " };
static s8* msgEndPL05_05[2] = {
    "   You! Go to the first car and we'll           ",
    "   attack them from both sides!                 ",
};
static s8* msgEndPL05_06[2] = {
    "   We can never let them fall                   ",
    "   into the hands of the enemy!                 ",
};
static s8* msgEndPL05_07[2] = {
    "   Their very cells pose                        ",
    "   a threat to us!                              ",
};
static s8* msgEndPL05_08[1] = { "   Is this the end...?                          " };
static s8* msgEndPL05_09[2] = {
    "   No... Not yet!                               ",
    "   Come with me, Effie!                         ",
};
static s8* msgEndPL05_10[1] = { "   ...Iyaaaaaaaah!                              " };
static s8* msgEndPL05_11[2] = {
    "   Aaaaah!!                                     ",
    "   Illiaaaaaaaaa!!                              ",
};
static s8* msgEndPL05_12[1] = { "   Effieeeeee!!                                 " };
static s8* msgEndPL05_13[1] = { "   It's a miracle...                            " };
static s8* msgEndPL05_14[2] = {
    "   For the first time... I feel                 ",
    "   thankful for this body of mine!              ",
};

static s8** msgEndAdrPL05[15] = {
    msgEndPL05_00, msgEndPL05_01, msgEndPL05_02, msgEndPL05_03, msgEndPL05_04,
    msgEndPL05_05, msgEndPL05_06, msgEndPL05_07, msgEndPL05_08, msgEndPL05_09,
    msgEndPL05_10, msgEndPL05_11, msgEndPL05_12, msgEndPL05_13, msgEndPL05_14,
};

static s8 msgEndCtrPL05[15] = { 1, 2, 2, 2, 1, 2, 2, 2, 1, 2, 1, 2, 1, 1, 2 };

MessageTable pl05end_usa_tbl = { msgEndAdrPL05, msgEndCtrPL05 };
