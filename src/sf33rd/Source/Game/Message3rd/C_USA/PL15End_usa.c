/* PL15End_usa.c, retail sf33rd.xbe.
 * The PS2 file's data (ps2.path), checked by analysis-ps2map/portdata.py
 * against the XBE: each table at its data.txt address, or at the
 * address a checked table's pointer to it holds ("placed by").
 * msgEndAdrPL15 0x3277e8 size 0x38: match (placed by pl15end_usa_tbl).
 * msgEndCtrPL15 0x327820 size 0xe: match (placed by pl15end_usa_tbl).
 * msgEndPL15_00 0x32778c size 0x4: match (placed by msgEndAdrPL15).
 * msgEndPL15_01 0x327790 size 0x4: match (placed by msgEndAdrPL15).
 * msgEndPL15_02 0x327794 size 0x4: match (placed by msgEndAdrPL15).
 * msgEndPL15_03 0x327798 size 0x4: match (placed by msgEndAdrPL15).
 * msgEndPL15_04 0x32779c size 0x8: match (placed by msgEndAdrPL15).
 * msgEndPL15_05 0x3277a4 size 0x8: match (placed by msgEndAdrPL15).
 * msgEndPL15_06 0x3277ac size 0x8: match (placed by msgEndAdrPL15).
 * msgEndPL15_07 0x3277b4 size 0x8: match (placed by msgEndAdrPL15).
 * msgEndPL15_08 0x3277bc size 0x8: match (placed by msgEndAdrPL15).
 * msgEndPL15_09 0x3277c4 size 0x8: match (placed by msgEndAdrPL15).
 * msgEndPL15_10 0x3277cc size 0x8: match (placed by msgEndAdrPL15).
 * msgEndPL15_11 0x3277d4 size 0x8: match (placed by msgEndAdrPL15).
 * msgEndPL15_12 0x3277dc size 0x8: match (placed by msgEndAdrPL15).
 * msgEndPL15_13 0x3277e4 size 0x4: match (placed by msgEndAdrPL15).
 * pl15end_usa_tbl 0x327830 size 0x8: match (placed by pl_end_tbl).
 */

#include "structs.h"
#include <stddef.h>

/* from sf33rd/Source/Game/Message3rd/C_USA/PL15End_usa.h */
extern MessageTable pl15end_usa_tbl;

static s8* msgEndPL15_00[1] = { "" };
static s8* msgEndPL15_01[1] = { "   \"Miss!\"                                      " };
static s8* msgEndPL15_02[1] = { "   \"You're going to be okay now...\"             " };
static s8* msgEndPL15_03[1] = { "   ...It's been 6 months since then...          " };
static s8* msgEndPL15_04[2] = {
    "   ...When I held in my arms,                   ",
    "   the girl whose life I had saved...           ",
};
static s8* msgEndPL15_05[2] = {
    "   I finally realized what my                   ",
    "   true \"fight\" should be...                    ",
};
static s8* msgEndPL15_06[2] = {
    "   For our mother country,                      ",
    "   that my father tried to protect...           ",
};
static s8* msgEndPL15_07[2] = {
    "   Ya!                                          ",
    "   Haah!                                        ",
};
static s8* msgEndPL15_08[2] = {
    "   For all of the warm-hearted people           ",
    "   I've met throughout the world...             ",
};
static s8* msgEndPL15_09[2] = {
    "   Ha!                                          ",
    "   Taaah!                                       ",
};
static s8* msgEndPL15_10[2] = {
    "   To teach the meaning of true                 ",
    "   strength and beauty to these kids...         ",
};
static s8* msgEndPL15_11[2] = {
    "   That is the purpose of my life,              ",
    "   and my future.                               ",
};
static s8* msgEndPL15_12[2] = {
    "   I'll use my fists to                         ",
    "   create our tomorrow!                         ",
};
static s8* msgEndPL15_13[1] = { "   Iyaaaaahh!!                                  " };

static s8** msgEndAdrPL15[14] = {
    msgEndPL15_00, msgEndPL15_01, msgEndPL15_02, msgEndPL15_03, msgEndPL15_04, msgEndPL15_05, msgEndPL15_06,
    msgEndPL15_07, msgEndPL15_08, msgEndPL15_09, msgEndPL15_10, msgEndPL15_11, msgEndPL15_12, msgEndPL15_13,
};

static s8 msgEndCtrPL15[14] = { 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1 };

MessageTable pl15end_usa_tbl = { msgEndAdrPL15, msgEndCtrPL15 };
