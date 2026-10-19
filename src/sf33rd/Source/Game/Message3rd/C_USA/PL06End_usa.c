/* PL06End_usa.c, retail sf33rd.xbe.
 * The PS2 file's data (ps2.path), checked by analysis-ps2map/portdata.py
 * against the XBE: each table at its data.txt address, or at the
 * address a checked table's pointer to it holds ("placed by").
 * msgEndAdrPL06 0x3264b0 size 0x3c: match (placed by pl06end_usa_tbl).
 * msgEndCtrPL06 0x3264ec size 0xf: match (placed by pl06end_usa_tbl).
 * msgEndPL06_00 0x326444 size 0x4: match (placed by msgEndAdrPL06).
 * msgEndPL06_01 0x326448 size 0x8: match (placed by msgEndAdrPL06).
 * msgEndPL06_02 0x326450 size 0x8: match (placed by msgEndAdrPL06).
 * msgEndPL06_03 0x326458 size 0x4: match (placed by msgEndAdrPL06).
 * msgEndPL06_04 0x32645c size 0x4: match (placed by msgEndAdrPL06).
 * msgEndPL06_05 0x326460 size 0x8: match (placed by msgEndAdrPL06).
 * msgEndPL06_06 0x326468 size 0x8: match (placed by msgEndAdrPL06).
 * msgEndPL06_07 0x326470 size 0x8: match (placed by msgEndAdrPL06).
 * msgEndPL06_08 0x326478 size 0x8: match (placed by msgEndAdrPL06).
 * msgEndPL06_09 0x326480 size 0x8: match (placed by msgEndAdrPL06).
 * msgEndPL06_10 0x326488 size 0x8: match (placed by msgEndAdrPL06).
 * msgEndPL06_11 0x326490 size 0x8: match (placed by msgEndAdrPL06).
 * msgEndPL06_12 0x326498 size 0x8: match (placed by msgEndAdrPL06).
 * msgEndPL06_13 0x3264a0 size 0x8: match (placed by msgEndAdrPL06).
 * msgEndPL06_14 0x3264a8 size 0x8: match (placed by msgEndAdrPL06).
 * pl06end_usa_tbl 0x3264fc size 0x8: match (placed by pl_end_tbl).
 */

#include "structs.h"
#include <stddef.h>

/* from sf33rd/Source/Game/Message3rd/C_USA/PL06End_usa.h */
extern MessageTable pl06end_usa_tbl;

static s8* msgEndPL06_00[1] = { "" };
static s8* msgEndPL06_01[2] = {
    "   The arena is exploding with                  ",
    "   excitement tonight!                          ",
};
static s8* msgEndPL06_02[2] = {
    "   The winner has been decided for the          ",
    "   world's tag team championship!               ",
};
static s8* msgEndPL06_03[1] = { "" };
static s8* msgEndPL06_04[1] = { "   Er... Earthquake!!                           " };
static s8* msgEndPL06_05[2] = {
    "   Sorry to interrupt, but we have              ",
    "   an important announcement...                 ",
};
static s8* msgEndPL06_06[2] = {
    "   We are from the H.W.A.!                      ",
    "   ...The Huge Wrestling Army!                  ",
};
static s8* msgEndPL06_07[2] = {
    "   Effective immediately,                       ",
    "   you belong to us!                            ",
};
static s8* msgEndPL06_08[2] = {
    "   If you have any objections, you              ",
    "   must defeat our Hugo, first!                 ",
};
static s8* msgEndPL06_09[2] = {
    "   So far, over 50 have challenged and          ",
    "   they have all become our soldiers!           ",
};
static s8* msgEndPL06_10[2] = {
    "   Oh no... Why am I here?                      ",
    "   Hey... Ryu?!                                 ",
};
static s8* msgEndPL06_11[2] = {
    "   Hmm. This could be exciting. I               ",
    "   believe this will be a good test!            ",
};
static s8* msgEndPL06_12[2] = {
    "   (Ryu! I can't believe you're having          ",
    "   fun in a situation like this!)               ",
};
static s8* msgEndPL06_13[2] = {
    "   What's up? Are you scared                    ",
    "   of our members, or what?!                    ",
};
static s8* msgEndPL06_14[2] = {
    "   No objections? Okay then! This ring          ",
    "   will become our base of operations!          ",
};

static s8** msgEndAdrPL06[15] = {
    msgEndPL06_00, msgEndPL06_01, msgEndPL06_02, msgEndPL06_03, msgEndPL06_04,
    msgEndPL06_05, msgEndPL06_06, msgEndPL06_07, msgEndPL06_08, msgEndPL06_09,
    msgEndPL06_10, msgEndPL06_11, msgEndPL06_12, msgEndPL06_13, msgEndPL06_14,
};

static s8 msgEndCtrPL06[15] = { 1, 2, 2, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 };

MessageTable pl06end_usa_tbl = { msgEndAdrPL06, msgEndCtrPL06 };
