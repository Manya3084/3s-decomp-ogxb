/* PL17End_usa.c, retail sf33rd.xbe.
 * The PS2 file's data (ps2.path), checked by analysis-ps2map/portdata.py
 * against the XBE: each table at its data.txt address, or at the
 * address a checked table's pointer to it holds ("placed by").
 * msgEndAdrPL17 0x327cb0 size 0x48: match (placed by pl17end_usa_tbl).
 * msgEndCtrPL17 0x327cf8 size 0x12: match (placed by pl17end_usa_tbl).
 * msgEndPL17_00 0x327c28 size 0x4: match (placed by msgEndAdrPL17).
 * msgEndPL17_01 0x327c2c size 0x8: match (placed by msgEndAdrPL17).
 * msgEndPL17_02 0x327c34 size 0x8: match (placed by msgEndAdrPL17).
 * msgEndPL17_03 0x327c3c size 0x8: match (placed by msgEndAdrPL17).
 * msgEndPL17_04 0x327c44 size 0x8: match (placed by msgEndAdrPL17).
 * msgEndPL17_05 0x327c4c size 0x8: match (placed by msgEndAdrPL17).
 * msgEndPL17_06 0x327c54 size 0x8: match (placed by msgEndAdrPL17).
 * msgEndPL17_07 0x327c5c size 0x8: match (placed by msgEndAdrPL17).
 * msgEndPL17_08 0x327c64 size 0x4: match (placed by msgEndAdrPL17).
 * msgEndPL17_09 0x327c68 size 0x8: match (placed by msgEndAdrPL17).
 * msgEndPL17_10 0x327c70 size 0x8: match (placed by msgEndAdrPL17).
 * msgEndPL17_11 0x327c78 size 0x8: match (placed by msgEndAdrPL17).
 * msgEndPL17_12 0x327c80 size 0x4: match (placed by msgEndAdrPL17).
 * msgEndPL17_13 0x327c84 size 0x8: match (placed by msgEndAdrPL17).
 * msgEndPL17_14 0x327c8c size 0x8: match (placed by msgEndAdrPL17).
 * msgEndPL17_15 0x327c94 size 0x8: match (placed by msgEndAdrPL17).
 * msgEndPL17_16 0x327c9c size 0x8: match (placed by msgEndAdrPL17).
 * msgEndPL17_17 0x327ca4 size 0x8: match (placed by msgEndAdrPL17).
 * pl17end_usa_tbl 0x327d0c size 0x8: match (placed by pl_end_tbl).
 */

#include "structs.h"
#include <stddef.h>

/* from sf33rd/Source/Game/Message3rd/C_USA/PL17End_usa.h */
extern MessageTable pl17end_usa_tbl;

static s8* msgEndPL17_00[1] = { "" };
static s8* msgEndPL17_01[2] = {
    "   13 bizarre cases in the last 10 days         ",
    "   at sites located around the world...         ",
};
static s8* msgEndPL17_02[2] = {
    "   After seeing those on-site pictures,         ",
    "   haven't you noticed something?               ",
};
static s8* msgEndPL17_03[2] = {
    "   What's up, Juliana? You don't have           ",
    "   to beat around the bush with me!             ",
};
static s8* msgEndPL17_04[2] = {
    "   Were you going to say that some              ",
    "   spooky guy appears in every scene?           ",
};
static s8* msgEndPL17_05[2] = {
    "   David... You may have some                   ",
    "   telepathic talent, after all.                ",
};
static s8* msgEndPL17_06[2] = {
    "   Look here... In every picture,               ",
    "   a man in a trench coat appears.              ",
};
static s8* msgEndPL17_07[2] = {
    "   No way! These cases all happened             ",
    "   in different parts of the world!             ",
};
static s8* msgEndPL17_08[1] = { "   It couldn't be the same person!              " };
static s8* msgEndPL17_09[2] = {
    "   Well, they at least have similar             ",
    "   taste in clothing...                         ",
};
static s8* msgEndPL17_10[2] = {
    "   Anyway, this \"mysterious guy\" is the         ",
    "   common thread in all of the cases.           ",
};
static s8* msgEndPL17_11[2] = {
    "   So, have you                                 ",
    "   identified that man?                         ",
};
static s8* msgEndPL17_12[1] = { "   Unfortunately, not yet...                    " };
static s8* msgEndPL17_13[2] = {
    "   But, we have used photo analysis             ",
    "   to synthesize his face.                      ",
};
static s8* msgEndPL17_14[2] = {
    "   Well, not exactly his face...                ",
    "   But... Anyway, have a look.                  ",
};
static s8* msgEndPL17_15[2] = {
    "   What's this?!                                ",
    "   A mask... An iron mask?                      ",
};
static s8* msgEndPL17_16[2] = {
    "   Okay! Send this picture out to each          ",
    "   of our branches, security level 4!           ",
};
static s8* msgEndPL17_17[2] = {
    "   You are to start an investigation            ",
    "   on this man immediately. Dismissed!          ",
};

static s8** msgEndAdrPL17[18] = {
    msgEndPL17_00, msgEndPL17_01, msgEndPL17_02, msgEndPL17_03, msgEndPL17_04, msgEndPL17_05,
    msgEndPL17_06, msgEndPL17_07, msgEndPL17_08, msgEndPL17_09, msgEndPL17_10, msgEndPL17_11,
    msgEndPL17_12, msgEndPL17_13, msgEndPL17_14, msgEndPL17_15, msgEndPL17_16, msgEndPL17_17,
};

static s8 msgEndCtrPL17[18] = { 1, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 1, 2, 2, 2, 2, 2 };

MessageTable pl17end_usa_tbl = { msgEndAdrPL17, msgEndCtrPL17 };
