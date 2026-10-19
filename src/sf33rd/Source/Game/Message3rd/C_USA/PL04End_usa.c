/* PL04End_usa.c, retail sf33rd.xbe.
 * The PS2 file's data (ps2.path), checked by analysis-ps2map/portdata.py
 * against the XBE: each table at its data.txt address, or at the
 * address a checked table's pointer to it holds ("placed by").
 * msgEndAdrPL04 0x326064 size 0x2c: match (placed by pl04end_usa_tbl).
 * msgEndCtrPL04 0x326090 size 0xb: match (placed by pl04end_usa_tbl).
 * msgEndPL04_00 0x32601c size 0x4: match (placed by msgEndAdrPL04).
 * msgEndPL04_01 0x326020 size 0x8: match (placed by msgEndAdrPL04).
 * msgEndPL04_02 0x326028 size 0x8: match (placed by msgEndAdrPL04).
 * msgEndPL04_03 0x326030 size 0x8: match (placed by msgEndAdrPL04).
 * msgEndPL04_04 0x326038 size 0x8: match (placed by msgEndAdrPL04).
 * msgEndPL04_05 0x326040 size 0x4: match (placed by msgEndAdrPL04).
 * msgEndPL04_06 0x326044 size 0x8: match (placed by msgEndAdrPL04).
 * msgEndPL04_07 0x32604c size 0x4: match (placed by msgEndAdrPL04).
 * msgEndPL04_08 0x326050 size 0x4: match (placed by msgEndAdrPL04).
 * msgEndPL04_09 0x326054 size 0x8: match (placed by msgEndAdrPL04).
 * msgEndPL04_10 0x32605c size 0x8: match (placed by msgEndAdrPL04).
 * pl04end_usa_tbl 0x32609c size 0x8: match (placed by pl_end_tbl).
 */

#include "structs.h"
#include <stddef.h>

/* from sf33rd/Source/Game/Message3rd/C_USA/PL04End_usa.h */
extern MessageTable pl04end_usa_tbl;

static s8* msgEndPL04_00[1] = { "" };
static s8* msgEndPL04_01[2] = {
    "   The subtle beauty of St. Swithun...          ",
    "   The aroma of Abraham Darby...                ",
};
static s8* msgEndPL04_02[2] = {
    "   The lightness of Dainty Bess...              ",
    "   The style of Uncle Walter...                 ",
};
static s8* msgEndPL04_03[2] = {
    "   Dad... You left this majestic                ",
    "   rose garden for me...                        ",
};
static s8* msgEndPL04_04[2] = {
    "   The roses' ever-changing                     ",
    "   beauty still heals my heart.                 ",
};
static s8* msgEndPL04_05[1] = { "   Sir Dudley... It's about time...             " };
static s8* msgEndPL04_06[2] = {
    "   Oh, that's right. Today is the day           ",
    "   of that important royal match...             ",
};
static s8* msgEndPL04_07[1] = { "   When does the match start?                   " };
static s8* msgEndPL04_08[1] = { "   It starts at 8:00 PM, sharp.                 " };
static s8* msgEndPL04_09[2] = {
    "   What...?!                                    ",
    "   We only have five hours left?!               ",
};
static s8* msgEndPL04_10[2] = {
    "   We've got to get back to the                 ",
    "   mansion immediately! Run!!                   ",
};

static s8** msgEndAdrPL04[11] = {
    msgEndPL04_00, msgEndPL04_01, msgEndPL04_02, msgEndPL04_03, msgEndPL04_04, msgEndPL04_05,
    msgEndPL04_06, msgEndPL04_07, msgEndPL04_08, msgEndPL04_09, msgEndPL04_10,
};

static s8 msgEndCtrPL04[11] = { 1, 2, 2, 2, 2, 1, 2, 1, 1, 2, 2 };

MessageTable pl04end_usa_tbl = { msgEndAdrPL04, msgEndCtrPL04 };
