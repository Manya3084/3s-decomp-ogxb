/* PL14End_usa.c, retail sf33rd.xbe.
 * The PS2 file's data (ps2.path), checked by analysis-ps2map/portdata.py
 * against the XBE: each table at its data.txt address, or at the
 * address a checked table's pointer to it holds ("placed by").
 * msgEndAdrPL14 0x327630 size 0x2c: match (placed by pl14end_usa_tbl).
 * msgEndCtrPL14 0x32765c size 0xb: match (placed by pl14end_usa_tbl).
 * msgEndPL14_00 0x3275ec size 0x4: match (placed by msgEndAdrPL14).
 * msgEndPL14_01 0x3275f0 size 0x8: match (placed by msgEndAdrPL14).
 * msgEndPL14_02 0x3275f8 size 0x8: match (placed by msgEndAdrPL14).
 * msgEndPL14_03 0x327600 size 0x8: match (placed by msgEndAdrPL14).
 * msgEndPL14_04 0x327608 size 0x4: match (placed by msgEndAdrPL14).
 * msgEndPL14_05 0x32760c size 0x8: match (placed by msgEndAdrPL14).
 * msgEndPL14_06 0x327614 size 0x4: match (placed by msgEndAdrPL14).
 * msgEndPL14_07 0x327618 size 0x8: match (placed by msgEndAdrPL14).
 * msgEndPL14_08 0x327620 size 0x8: match (placed by msgEndAdrPL14).
 * msgEndPL14_09 0x327628 size 0x4: match (placed by msgEndAdrPL14).
 * msgEndPL14_10 0x32762c size 0x4: match (placed by msgEndAdrPL14).
 * pl14end_usa_tbl 0x327668 size 0x8: match (placed by pl_end_tbl).
 */

#include "structs.h"
#include <stddef.h>

/* from sf33rd/Source/Game/Message3rd/C_USA/PL14End_usa.h */
extern MessageTable pl14end_usa_tbl;

static s8* msgEndPL14_00[1] = { "" };
static s8* msgEndPL14_01[2] = {
    "   This is Deep Sea 3000.                       ",
    "   150m to the destination... Over.             ",
};
static s8* msgEndPL14_02[2] = {
    "   We expect to reach the observation           ",
    "   point in approximately 40 seconds.           ",
};
static s8* msgEndPL14_03[2] = {
    "   Confirmed visual contact with ship.          ",
    "   Switching to phase three... Over.            ",
};
static s8* msgEndPL14_04[1] = { "   ...What?!                                    " };
static s8* msgEndPL14_05[2] = {
    "   Is that... a man?!                           ",
    "   No... it can't be!                           ",
};
static s8* msgEndPL14_06[1] = { "   This can't be happening...                   " };
static s8* msgEndPL14_07[2] = {
    "   What? What did you see?!                     ",
    "   Respond!! Over!                              ",
};
static s8* msgEndPL14_08[2] = {
    "   Something is wrong!                          ",
    "   The radio has been cut... Uwaahh!!           ",
};
static s8* msgEndPL14_09[1] = { "   Muuuuuuunn!!                                 " };
static s8* msgEndPL14_10[1] = { "   Tenshou Kaireki Jin!!                        " };

static s8** msgEndAdrPL14[11] = {
    msgEndPL14_00, msgEndPL14_01, msgEndPL14_02, msgEndPL14_03, msgEndPL14_04, msgEndPL14_05,
    msgEndPL14_06, msgEndPL14_07, msgEndPL14_08, msgEndPL14_09, msgEndPL14_10,
};

static s8 msgEndCtrPL14[11] = { 1, 2, 2, 2, 1, 2, 1, 2, 2, 1, 1 };

MessageTable pl14end_usa_tbl = { msgEndAdrPL14, msgEndCtrPL14 };
