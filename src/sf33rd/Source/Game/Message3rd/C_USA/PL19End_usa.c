/* PL19End_usa.c, retail sf33rd.xbe.
 * The PS2 file's data (ps2.path), checked by analysis-ps2map/portdata.py
 * against the XBE: each table at its data.txt address, or at the
 * address a checked table's pointer to it holds ("placed by").
 * msgEndAdrPL19 0x3280d0 size 0x44: match (placed by pl19end_usa_tbl).
 * msgEndCtrPL19 0x328114 size 0x11: match (placed by pl19end_usa_tbl).
 * msgEndPL19_00 0x328058 size 0x4: match (placed by msgEndAdrPL19).
 * msgEndPL19_01 0x32805c size 0x8: match (placed by msgEndAdrPL19).
 * msgEndPL19_02 0x328064 size 0x8: match (placed by msgEndAdrPL19).
 * msgEndPL19_03 0x32806c size 0x8: match (placed by msgEndAdrPL19).
 * msgEndPL19_04 0x328074 size 0x8: match (placed by msgEndAdrPL19).
 * msgEndPL19_05 0x32807c size 0x8: match (placed by msgEndAdrPL19).
 * msgEndPL19_06 0x328084 size 0x8: match (placed by msgEndAdrPL19).
 * msgEndPL19_07 0x32808c size 0x8: match (placed by msgEndAdrPL19).
 * msgEndPL19_08 0x328094 size 0x8: match (placed by msgEndAdrPL19).
 * msgEndPL19_09 0x32809c size 0x4: match (placed by msgEndAdrPL19).
 * msgEndPL19_10 0x3280a0 size 0x8: match (placed by msgEndAdrPL19).
 * msgEndPL19_11 0x3280a8 size 0x4: match (placed by msgEndAdrPL19).
 * msgEndPL19_12 0x3280ac size 0x8: match (placed by msgEndAdrPL19).
 * msgEndPL19_13 0x3280b4 size 0x4: match (placed by msgEndAdrPL19).
 * msgEndPL19_14 0x3280b8 size 0x8: match (placed by msgEndAdrPL19).
 * msgEndPL19_15 0x3280c0 size 0x8: match (placed by msgEndAdrPL19).
 * msgEndPL19_16 0x3280c8 size 0x8: match (placed by msgEndAdrPL19).
 * pl19end_usa_tbl 0x328128 size 0x8: match (placed by pl_end_tbl).
 */

#include "structs.h"
#include <stddef.h>

/* from sf33rd/Source/Game/Message3rd/C_USA/PL19End_usa.h */
extern MessageTable pl19end_usa_tbl;

static s8* msgEndPL19_00[1] = { "" };
static s8* msgEndPL19_01[2] = {
    "   Whenever I dive into this sea                ",
    "   of Bisque, I feel so cold.                   ",
};
static s8* msgEndPL19_02[2] = {
    "   It is as cold as my heart,                   ",
    "   which cannot be healed.                      ",
};
static s8* msgEndPL19_03[2] = {
    "   (The tides are increasing in their           ",
    "   speed and frequency...)                      ",
};
static s8* msgEndPL19_04[2] = {
    "   (This will be the last time                  ",
    "   I visit this place...)                       ",
};
static s8* msgEndPL19_05[2] = {
    "   I've been struggling in the                  ",
    "   darkness for a long time...                  ",
};
static s8* msgEndPL19_06[2] = {
    "   I've been trying to paint the                ",
    "   darkness with another shadow...              ",
};
static s8* msgEndPL19_07[2] = {
    "   After all... It was the darkness             ",
    "   of being a \"warrior\"...                      ",
};
static s8* msgEndPL19_08[2] = {
    "   That caused our father to disappear,         ",
    "   leaving my sister and me alone...            ",
};
static s8* msgEndPL19_09[1] = { "   ...I cannot forgive him yet.                 " };
static s8* msgEndPL19_10[2] = {
    "   But... Nothing would change                  ",
    "   if I went on like this.                      ",
};
static s8* msgEndPL19_11[1] = { "   So... I'll forget everything.                " };
static s8* msgEndPL19_12[2] = {
    "   I believe that doing so                      ",
    "   could lead to our happiness.                 ",
};
static s8* msgEndPL19_13[1] = { "   Goodbye... My sister!                        " };
static s8* msgEndPL19_14[2] = {
    "   After saying goodbye, Remy                   ",
    "   sees a light on his way back.                ",
};
static s8* msgEndPL19_15[2] = {
    "   He never believed that he would              ",
    "   be able to see such a light...               ",
};
static s8* msgEndPL19_16[2] = {
    "   To discover the meaning of the               ",
    "   light, Remy begins to walk forth...          ",
};

static s8** msgEndAdrPL19[17] = {
    msgEndPL19_00, msgEndPL19_01, msgEndPL19_02, msgEndPL19_03, msgEndPL19_04, msgEndPL19_05,
    msgEndPL19_06, msgEndPL19_07, msgEndPL19_08, msgEndPL19_09, msgEndPL19_10, msgEndPL19_11,
    msgEndPL19_12, msgEndPL19_13, msgEndPL19_14, msgEndPL19_15, msgEndPL19_16,
};

static s8 msgEndCtrPL19[17] = { 1, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 1, 2, 1, 2, 2, 2 };

MessageTable pl19end_usa_tbl = { msgEndAdrPL19, msgEndCtrPL19 };
