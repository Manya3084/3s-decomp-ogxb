/* PL03End_usa.c, retail sf33rd.xbe.
 * The PS2 file's data (ps2.path), checked by analysis-ps2map/portdata.py
 * against the XBE: each table at its data.txt address, or at the
 * address a checked table's pointer to it holds ("placed by").
 * msgEndAdrPL03 0x325e28 size 0x54: match (placed by pl03end_usa_tbl).
 * msgEndCtrPL03 0x325e7c size 0x15: match (placed by pl03end_usa_tbl).
 * msgEndPL03_00 0x325d98 size 0x4: match (placed by msgEndAdrPL03).
 * msgEndPL03_01 0x325d9c size 0x4: match (placed by msgEndAdrPL03).
 * msgEndPL03_02 0x325da0 size 0x8: match (placed by msgEndAdrPL03).
 * msgEndPL03_03 0x325da8 size 0x8: match (placed by msgEndAdrPL03).
 * msgEndPL03_04 0x325db0 size 0x8: match (placed by msgEndAdrPL03).
 * msgEndPL03_05 0x325db8 size 0x4: match (placed by msgEndAdrPL03).
 * msgEndPL03_06 0x325dbc size 0x8: match (placed by msgEndAdrPL03).
 * msgEndPL03_07 0x325dc4 size 0x8: match (placed by msgEndAdrPL03).
 * msgEndPL03_08 0x325dcc size 0x4: match (placed by msgEndAdrPL03).
 * msgEndPL03_09 0x325dd0 size 0x8: match (placed by msgEndAdrPL03).
 * msgEndPL03_10 0x325dd8 size 0x8: match (placed by msgEndAdrPL03).
 * msgEndPL03_11 0x325de0 size 0x8: match (placed by msgEndAdrPL03).
 * msgEndPL03_12 0x325de8 size 0x8: match (placed by msgEndAdrPL03).
 * msgEndPL03_13 0x325df0 size 0x4: match (placed by msgEndAdrPL03).
 * msgEndPL03_14 0x325df4 size 0x8: match (placed by msgEndAdrPL03).
 * msgEndPL03_15 0x325dfc size 0x8: match (placed by msgEndAdrPL03).
 * msgEndPL03_16 0x325e04 size 0x8: match (placed by msgEndAdrPL03).
 * msgEndPL03_17 0x325e0c size 0x4: match (placed by msgEndAdrPL03).
 * msgEndPL03_18 0x325e10 size 0x8: match (placed by msgEndAdrPL03).
 * msgEndPL03_19 0x325e18 size 0x8: match (placed by msgEndAdrPL03).
 * msgEndPL03_20 0x325e20 size 0x8: match (placed by msgEndAdrPL03).
 * pl03end_usa_tbl 0x325e94 size 0x8: match (placed by pl_end_tbl).
 */

#include "structs.h"
#include <stddef.h>

/* from sf33rd/Source/Game/Message3rd/C_USA/PL03End_usa.h */
extern MessageTable pl03end_usa_tbl;

static s8* msgEndPL03_00[1] = { "" };
static s8* msgEndPL03_01[1] = { "   That was a wonderful performance!            " };
static s8* msgEndPL03_02[2] = {
    "   As a token of my respect, I will             ",
    "   leave this town in your care.                ",
};
static s8* msgEndPL03_03[2] = {
    "   You will also receive the highest            ",
    "   privileges with regards to my plan.          ",
};
static s8* msgEndPL03_04[2] = {
    "   Hey, idiot! Give it up!                      ",
    "   Your plan is totally worthless!              ",
};
static s8* msgEndPL03_05[1] = { "   Ideal society? Get a clue!                   " };
static s8* msgEndPL03_06[2] = {
    "   I'm proposing the most rational              ",
    "   and ideal plan for all people.               ",
};
static s8* msgEndPL03_07[2] = {
    "   Of course, I won't force you to              ",
    "   follow... It's your choice.                  ",
};
static s8* msgEndPL03_08[1] = { "   But... I have no time to waste...            " };
static s8* msgEndPL03_09[2] = {
    "   Two opposite powers have been with           ",
    "   us since the beginning of time...            ",
};
static s8* msgEndPL03_10[2] = {
    "   Birth and death, production and              ",
    "   destruction, love and hate...                ",
};
static s8* msgEndPL03_11[2] = {
    "   The balance between them will                ",
    "   collapse in the near future!                 ",
};
static s8* msgEndPL03_12[2] = {
    "   In order to insure our survival, I           ",
    "   propose the symbiosis of two powers.         ",
};
static s8* msgEndPL03_13[1] = { "   Ha ha ha ha! Now I wonder...                 " };
static s8* msgEndPL03_14[2] = {
    "   How will those fighters survive              ",
    "   the aftermath of destruction...?             ",
};
static s8* msgEndPL03_15[2] = {
    "   It shall be a small enjoyment                ",
    "   for me to find out.                          ",
};
static s8* msgEndPL03_16[2] = {
    "   Brother... I have a bad feeling              ",
    "   about this.                                  ",
};
static s8* msgEndPL03_17[1] = { "   His words... They are troubling me.          " };
static s8* msgEndPL03_18[2] = {
    "   Hey... Get a grip, Yang!                     ",
    "   We're the leaders of the town!               ",
};
static s8* msgEndPL03_19[2] = {
    "   We won't let that wannabe supreme            ",
    "   being do as he wishes, right?                ",
};
static s8* msgEndPL03_20[2] = {
    "   Let's head back to the town!                 ",
    "   We'll make our own dreams come true!         ",
};

static s8** msgEndAdrPL03[21] = {
    msgEndPL03_00, msgEndPL03_01, msgEndPL03_02, msgEndPL03_03, msgEndPL03_04, msgEndPL03_05, msgEndPL03_06,
    msgEndPL03_07, msgEndPL03_08, msgEndPL03_09, msgEndPL03_10, msgEndPL03_11, msgEndPL03_12, msgEndPL03_13,
    msgEndPL03_14, msgEndPL03_15, msgEndPL03_16, msgEndPL03_17, msgEndPL03_18, msgEndPL03_19, msgEndPL03_20,
};

static s8 msgEndCtrPL03[21] = { 1, 1, 2, 2, 2, 1, 2, 2, 1, 2, 2, 2, 2, 1, 2, 2, 2, 1, 2, 2, 2 };

MessageTable pl03end_usa_tbl = { msgEndAdrPL03, msgEndCtrPL03 };
