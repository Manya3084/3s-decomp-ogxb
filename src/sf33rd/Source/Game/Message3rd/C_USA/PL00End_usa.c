/* PL00End_usa.c, retail sf33rd.xbe.
 * The PS2 file's data (ps2.path), checked by analysis-ps2map/portdata.py
 * against the XBE: each table at its data.txt address, or at the
 * address a checked table's pointer to it holds ("placed by").
 * msgEndAdrPL00 0x325720 size 0x48: match (placed by pl00end_usa_tbl).
 * msgEndCtrPL00 0x325768 size 0x12: match (placed by pl00end_usa_tbl).
 * msgEndPL00_00 0x3256b8 size 0x4: match (placed by msgEndAdrPL00).
 * msgEndPL00_01 0x3256bc size 0x4: match (placed by msgEndAdrPL00).
 * msgEndPL00_02 0x3256c0 size 0x8: match (placed by msgEndAdrPL00).
 * msgEndPL00_03 0x3256c8 size 0x8: match (placed by msgEndAdrPL00).
 * msgEndPL00_04 0x3256d0 size 0x8: match (placed by msgEndAdrPL00).
 * msgEndPL00_05 0x3256d8 size 0x8: match (placed by msgEndAdrPL00).
 * msgEndPL00_06 0x3256e0 size 0x4: match (placed by msgEndAdrPL00).
 * msgEndPL00_07 0x3256e4 size 0x4: match (placed by msgEndAdrPL00).
 * msgEndPL00_08 0x3256e8 size 0x8: the Xbox text, taken from the XBE (placed by msgEndAdrPL00).
 * msgEndPL00_09 0x3256f0 size 0x8: the Xbox text, taken from the XBE (placed by msgEndAdrPL00).
 * msgEndPL00_10 0x3256f8 size 0x4: match (placed by msgEndAdrPL00).
 * msgEndPL00_11 0x3256fc size 0x4: match (placed by msgEndAdrPL00).
 * msgEndPL00_12 0x325700 size 0x4: match (placed by msgEndAdrPL00).
 * msgEndPL00_13 0x325704 size 0x8: match (placed by msgEndAdrPL00).
 * msgEndPL00_14 0x32570c size 0x4: match (placed by msgEndAdrPL00).
 * msgEndPL00_15 0x325710 size 0x4: match (placed by msgEndAdrPL00).
 * msgEndPL00_16 0x325714 size 0x8: match (placed by msgEndAdrPL00).
 * msgEndPL00_17 0x32571c size 0x4: match (placed by msgEndAdrPL00).
 * pl00end_usa_tbl 0x32577c size 0x8: match (placed by pl_end_tbl).
 */

#include "structs.h"
#include <stddef.h>

/* from sf33rd/Source/Game/Message3rd/C_USA/PL00End_usa.h */
extern MessageTable pl00end_usa_tbl;

static s8* msgEndPL00_00[1] = { "" };
static s8* msgEndPL00_01[1] = { "   You were wrong...                            " };
static s8* msgEndPL00_02[2] = {
    "   People can't control hatred or love          ",
    "   within their minds...                        ",
};
static s8* msgEndPL00_03[2] = {
    "   Every soul feeds and survives upon           ",
    "   feelings...                                  ",
};
static s8* msgEndPL00_04[2] = {
    "   If you try and ignore certain emotions,      ",
    "   people may be damaged or destroyed!          ",
};
static s8* msgEndPL00_05[2] = {
    "   Open your mind and accept the truth that     ",
    "   one feeling needs the other...               ",
};
static s8* msgEndPL00_06[1] = { "   Let me lead you...                           " };
static s8* msgEndPL00_07[1] = { "   \"...Huh? What is going on...?\"               " };
static s8* msgEndPL00_08[2] = {
    "   \"Something has been taken away... And        ",
    "   yet, something new has been added...\"        ",
};
static s8* msgEndPL00_09[2] = {
    "   Paradise... Everyone dreams of it and        ",
    "   searches their entire life for it...         ",
};
static s8* msgEndPL00_10[1] = { "   But paradise doesn't exist.                  " };
static s8* msgEndPL00_11[1] = { "   People are blind to the truth...             " };
static s8* msgEndPL00_12[1] = { "   2000 years was too long.                     " };
static s8* msgEndPL00_13[2] = {
    "   I'm going to complete the mission which      ",
    "   my predecessor tried to accomplish.          ",
};
static s8* msgEndPL00_14[1] = { "   The dark future is now over...               " };
static s8* msgEndPL00_15[1] = { "   Now... The road has been shown.              " };
static s8* msgEndPL00_16[2] = {
    "   This road will lead the pitiful people       ",
    "   of this world to evolution...                ",
};
static s8* msgEndPL00_17[1] = { "   Yes... This is the way to the paradise!      " };

static s8** msgEndAdrPL00[18] = {
    msgEndPL00_00, msgEndPL00_01, msgEndPL00_02, msgEndPL00_03, msgEndPL00_04, msgEndPL00_05,
    msgEndPL00_06, msgEndPL00_07, msgEndPL00_08, msgEndPL00_09, msgEndPL00_10, msgEndPL00_11,
    msgEndPL00_12, msgEndPL00_13, msgEndPL00_14, msgEndPL00_15, msgEndPL00_16, msgEndPL00_17,
};

static s8 msgEndCtrPL00[18] = { 1, 1, 2, 2, 2, 2, 1, 1, 2, 2, 1, 1, 1, 2, 1, 1, 2, 1 };

MessageTable pl00end_usa_tbl = { msgEndAdrPL00, msgEndCtrPL00 };
