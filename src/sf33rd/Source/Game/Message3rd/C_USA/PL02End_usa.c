/* PL02End_usa.c, retail sf33rd.xbe.
 * The PS2 file's data (ps2.path), checked by analysis-ps2map/portdata.py
 * against the XBE: each table at its data.txt address, or at the
 * address a checked table's pointer to it holds ("placed by").
 * msgEndAdrPL02 0x325bec size 0x2c: match (placed by pl02end_usa_tbl).
 * msgEndCtrPL02 0x325c18 size 0xb: match (placed by pl02end_usa_tbl).
 * msgEndPL02_00 0x325ba4 size 0x4: match (placed by msgEndAdrPL02).
 * msgEndPL02_01 0x325ba8 size 0x4: match (placed by msgEndAdrPL02).
 * msgEndPL02_02 0x325bac size 0x8: match (placed by msgEndAdrPL02).
 * msgEndPL02_03 0x325bb4 size 0x8: match (placed by msgEndAdrPL02).
 * msgEndPL02_04 0x325bbc size 0x8: match (placed by msgEndAdrPL02).
 * msgEndPL02_05 0x325bc4 size 0x8: match (placed by msgEndAdrPL02).
 * msgEndPL02_06 0x325bcc size 0x4: match (placed by msgEndAdrPL02).
 * msgEndPL02_07 0x325bd0 size 0x8: match (placed by msgEndAdrPL02).
 * msgEndPL02_08 0x325bd8 size 0x8: match (placed by msgEndAdrPL02).
 * msgEndPL02_09 0x325be0 size 0x8: match (placed by msgEndAdrPL02).
 * msgEndPL02_10 0x325be8 size 0x4: match (placed by msgEndAdrPL02).
 * pl02end_usa_tbl 0x325c24 size 0x8: match (placed by pl_end_tbl).
 */

#include "structs.h"
#include <stddef.h>

/* from sf33rd/Source/Game/Message3rd/C_USA/PL02End_usa.h */
extern MessageTable pl02end_usa_tbl;

static s8* msgEndPL02_00[1] = { "" };
static s8* msgEndPL02_01[1] = { "   \"What is a true warrior?\"                    " };
static s8* msgEndPL02_02[2] = {
    "   \"Why should I be strong?                     ",
    "   What awaits beyond victory?\"                 ",
};
static s8* msgEndPL02_03[2] = {
    "   Since the days of my youth, these            ",
    "   thoughts have never left my mind.            ",
};
static s8* msgEndPL02_04[2] = {
    "   I had to decide... Either to stop            ",
    "   asking myself those questions...             ",
};
static s8* msgEndPL02_05[2] = {
    "   ...or to struggle to                         ",
    "   find the answers...                          ",
};
static s8* msgEndPL02_06[1] = { "" };
static s8* msgEndPL02_07[2] = {
    "   Hmm. I'm not close. I can't even             ",
    "   tell where the leaves will fall...           ",
};
static s8* msgEndPL02_08[2] = {
    "   As long as strong opponents and              ",
    "   fierce battles excite me...                  ",
};
static s8* msgEndPL02_09[2] = {
    "   As long as I possess the strength            ",
    "   to move even one of my fingers...            ",
};
static s8* msgEndPL02_10[1] = { "   ...I will keep on fighting!                  " };

static s8** msgEndAdrPL02[11] = {
    msgEndPL02_00, msgEndPL02_01, msgEndPL02_02, msgEndPL02_03, msgEndPL02_04, msgEndPL02_05,
    msgEndPL02_06, msgEndPL02_07, msgEndPL02_08, msgEndPL02_09, msgEndPL02_10,
};

static s8 msgEndCtrPL02[11] = { 1, 1, 2, 2, 2, 2, 1, 2, 2, 2, 1 };

MessageTable pl02end_usa_tbl = { msgEndAdrPL02, msgEndCtrPL02 };
