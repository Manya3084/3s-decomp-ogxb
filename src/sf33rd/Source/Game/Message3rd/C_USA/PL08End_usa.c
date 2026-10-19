/* PL08End_usa.c, retail sf33rd.xbe.
 * The PS2 file's data (ps2.path), checked by analysis-ps2map/portdata.py
 * against the XBE: each table at its data.txt address, or at the
 * address a checked table's pointer to it holds ("placed by").
 * msgEndAdrPL08 0x32691c size 0x30: match (placed by pl08end_usa_tbl).
 * msgEndCtrPL08 0x32694c size 0xc: match (placed by pl08end_usa_tbl).
 * msgEndPL08_00 0x3268c4 size 0x4: match (placed by msgEndAdrPL08).
 * msgEndPL08_01 0x3268c8 size 0x4: match (placed by msgEndAdrPL08).
 * msgEndPL08_02 0x3268cc size 0x8: match (placed by msgEndAdrPL08).
 * msgEndPL08_03 0x3268d4 size 0x8: match (placed by msgEndAdrPL08).
 * msgEndPL08_04 0x3268dc size 0x8: match (placed by msgEndAdrPL08).
 * msgEndPL08_05 0x3268e4 size 0x8: match (placed by msgEndAdrPL08).
 * msgEndPL08_06 0x3268ec size 0x8: match (placed by msgEndAdrPL08).
 * msgEndPL08_07 0x3268f4 size 0x8: match (placed by msgEndAdrPL08).
 * msgEndPL08_08 0x3268fc size 0x8: match (placed by msgEndAdrPL08).
 * msgEndPL08_09 0x326904 size 0x8: match (placed by msgEndAdrPL08).
 * msgEndPL08_10 0x32690c size 0x8: match (placed by msgEndAdrPL08).
 * msgEndPL08_11 0x326914 size 0x8: match (placed by msgEndAdrPL08).
 * pl08end_usa_tbl 0x326958 size 0x8: match (placed by pl_end_tbl).
 */

#include "structs.h"
#include <stddef.h>

/* from sf33rd/Source/Game/Message3rd/C_USA/PL08End_usa.h */
extern MessageTable pl08end_usa_tbl;

static s8* msgEndPL08_00[1] = { "" };
static s8* msgEndPL08_01[1] = { "   My dear Naru-chan,                           " };
static s8* msgEndPL08_02[2] = {
    "   How are you?                                 ",
    "   I'm fine as always.                          ",
};
static s8* msgEndPL08_03[2] = {
    "   I feel lonely, now that the Harvest          ",
    "   Festival here in France is over.             ",
};
static s8* msgEndPL08_04[2] = {
    "   As I sip my tea, I'm reminded of             ",
    "   our happy days of summer in Japan.           ",
};
static s8* msgEndPL08_05[2] = {
    "   ...When we went to the festival all          ",
    "   dressed up, and saw the fireworks...         ",
};
static s8* msgEndPL08_06[2] = {
    "   Everything was so fun! Fights                ",
    "   were especially exciting, too!               ",
};
static s8* msgEndPL08_07[2] = {
    "   I'd like to invite your family to            ",
    "   visit the great plain in my country.         ",
};
static s8* msgEndPL08_08[2] = {
    "   I'm sure that my                             ",
    "   family will like you!                        ",
};
static s8* msgEndPL08_09[2] = {
    "   Maybe next winter holiday... I know          ",
    "   you're working hard on your exams.           ",
};
static s8* msgEndPL08_10[2] = {
    "   Take good care of your health!               ",
    "   See you again soon!                          ",
};
static s8* msgEndPL08_11[2] = {
    "   There's a lot of hard work ahead             ",
    "   of me! I'll be studying, too!                ",
};

static s8** msgEndAdrPL08[12] = {
    msgEndPL08_00, msgEndPL08_01, msgEndPL08_02, msgEndPL08_03, msgEndPL08_04, msgEndPL08_05,
    msgEndPL08_06, msgEndPL08_07, msgEndPL08_08, msgEndPL08_09, msgEndPL08_10, msgEndPL08_11,
};

static s8 msgEndCtrPL08[12] = { 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 };

MessageTable pl08end_usa_tbl = { msgEndAdrPL08, msgEndCtrPL08 };
