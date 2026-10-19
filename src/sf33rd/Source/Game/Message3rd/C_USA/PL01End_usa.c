/* PL01End_usa.c, retail sf33rd.xbe.
 * The PS2 file's data (ps2.path), checked by analysis-ps2map/portdata.py
 * against the XBE: each table at its data.txt address, or at the
 * address a checked table's pointer to it holds ("placed by").
 * msgEndAdrPL01 0x3259e0 size 0x40: match (placed by pl01end_usa_tbl).
 * msgEndCtrPL01 0x325a20 size 0x10: match (placed by pl01end_usa_tbl).
 * msgEndPL01_00 0x325970 size 0x4: match (placed by msgEndAdrPL01).
 * msgEndPL01_01 0x325974 size 0x8: match (placed by msgEndAdrPL01).
 * msgEndPL01_02 0x32597c size 0x8: match (placed by msgEndAdrPL01).
 * msgEndPL01_03 0x325984 size 0x8: match (placed by msgEndAdrPL01).
 * msgEndPL01_04 0x32598c size 0x8: match (placed by msgEndAdrPL01).
 * msgEndPL01_05 0x325994 size 0x8: match (placed by msgEndAdrPL01).
 * msgEndPL01_06 0x32599c size 0x8: match (placed by msgEndAdrPL01).
 * msgEndPL01_07 0x3259a4 size 0x4: match (placed by msgEndAdrPL01).
 * msgEndPL01_08 0x3259a8 size 0x8: match (placed by msgEndAdrPL01).
 * msgEndPL01_09 0x3259b0 size 0x8: match (placed by msgEndAdrPL01).
 * msgEndPL01_10 0x3259b8 size 0x4: match (placed by msgEndAdrPL01).
 * msgEndPL01_11 0x3259bc size 0x8: match (placed by msgEndAdrPL01).
 * msgEndPL01_12 0x3259c4 size 0x4: match (placed by msgEndAdrPL01).
 * msgEndPL01_13 0x3259c8 size 0x8: match (placed by msgEndAdrPL01).
 * msgEndPL01_14 0x3259d0 size 0x8: match (placed by msgEndAdrPL01).
 * msgEndPL01_15 0x3259d8 size 0x4: match (placed by msgEndAdrPL01).
 * pl01end_usa_tbl 0x325a30 size 0x8: match (placed by pl_end_tbl).
 */

#include "structs.h"
#include <stddef.h>

/* from sf33rd/Source/Game/Message3rd/C_USA/PL01End_usa.h */
extern MessageTable pl01end_usa_tbl;

static s8* msgEndPL01_00[1] = { "" };
static s8* msgEndPL01_01[2] = {
    "   Ugh! I couldn't counter even                 ",
    "   one of his blows!                            ",
};
static s8* msgEndPL01_02[2] = {
    "   (His reputation does not do him              ",
    "   justice! He is much stronger!)               ",
};
static s8* msgEndPL01_03[2] = {
    "   \"I'm sorry that I can't go camping.          ",
    "   Please give my apologies to Pat.\"            ",
};
static s8* msgEndPL01_04[2] = {
    "   \"...I know it sounds crazy, but              ",
    "   I just can't control myself.\"                ",
};
static s8* msgEndPL01_05[2] = {
    "   \"To see him again and to fight!              ",
    "   That's the only thing on my mind!\"           ",
};
static s8* msgEndPL01_06[2] = {
    "   \"I'll be on the road for a while...          ",
    "   Tom, I'll catch up with you later!\"          ",
};
static s8* msgEndPL01_07[1] = { "   (Now, his time has come...)                  " };
static s8* msgEndPL01_08[2] = {
    "   (I guess he thinks that I'm no               ",
    "   longer a match for him...)                   ",
};
static s8* msgEndPL01_09[2] = {
    "   (Alex, when you return, I'll see for         ",
    "   myself how strong you've become!)            ",
};
static s8* msgEndPL01_10[1] = { "   Dad! Hey, where's Alex, anyway?              " };
static s8* msgEndPL01_11[2] = {
    "   We need him to set up our tent               ",
    "   by the lake, you know.                       ",
};
static s8* msgEndPL01_12[1] = { "   Hey daddy, are you listening?!               " };
static s8* msgEndPL01_13[2] = {
    "   What's the matter?!                          ",
    "   Is that all you've got?                      ",
};
static s8* msgEndPL01_14[2] = {
    "   Ha ha... No way!                             ",
    "   The show has just begun!                     ",
};
static s8* msgEndPL01_15[1] = { "   Get ready!                                   " };

static s8** msgEndAdrPL01[16] = {
    msgEndPL01_00, msgEndPL01_01, msgEndPL01_02, msgEndPL01_03, msgEndPL01_04, msgEndPL01_05,
    msgEndPL01_06, msgEndPL01_07, msgEndPL01_08, msgEndPL01_09, msgEndPL01_10, msgEndPL01_11,
    msgEndPL01_12, msgEndPL01_13, msgEndPL01_14, msgEndPL01_15,
};

static s8 msgEndCtrPL01[16] = { 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 1, 2, 1, 2, 2, 1 };

MessageTable pl01end_usa_tbl = { msgEndAdrPL01, msgEndCtrPL01 };
