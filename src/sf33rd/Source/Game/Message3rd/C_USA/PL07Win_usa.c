/* PL07Win_usa.c, retail sf33rd.xbe.
 * The PS2 file's data (ps2.path), checked by analysis-ps2map/portdata.py
 * against the XBE: each table at its data.txt address, or at the
 * address a checked table's pointer to it holds ("placed by").
 * msgWinAdrPL07 0x326830 size 0x70: match (placed by pl07win_usa_tbl).
 * msgWinCtrPL07 0x3268a0 size 0x1c: match (placed by pl07win_usa_tbl).
 * msgWinPL07_00P 0x3267a0 size 0x4: match (placed by msgWinAdrPL07).
 * msgWinPL07_01P 0x3267a4 size 0x4: match (placed by msgWinAdrPL07).
 * msgWinPL07_02P 0x3267a8 size 0x4: match (placed by msgWinAdrPL07).
 * msgWinPL07_03P 0x3267ac size 0x4: match (placed by msgWinAdrPL07).
 * msgWinPL07_04P 0x3267b0 size 0x4: match (placed by msgWinAdrPL07).
 * msgWinPL07_05P 0x3267b4 size 0x4: match (placed by msgWinAdrPL07).
 * msgWinPL07_06P 0x3267b8 size 0x4: match (placed by msgWinAdrPL07).
 * msgWinPL07_07P 0x3267bc size 0x4: match (placed by msgWinAdrPL07).
 * msgWinPL07_08P 0x3267c0 size 0x4: match (placed by msgWinAdrPL07).
 * msgWinPL07_09P 0x3267c4 size 0x4: match (placed by msgWinAdrPL07).
 * msgWinPL07_10P 0x3267c8 size 0x4: match (placed by msgWinAdrPL07).
 * msgWinPL07_11P 0x3267cc size 0x4: match (placed by msgWinAdrPL07).
 * msgWinPL07_12P 0x3267d0 size 0x4: match (placed by msgWinAdrPL07).
 * msgWinPL07_13P 0x3267d4 size 0x4: match (placed by msgWinAdrPL07).
 * msgWinPL07_14P 0x3267d8 size 0x4: match (placed by msgWinAdrPL07).
 * msgWinPL07_15P 0x3267dc size 0x4: match (placed by msgWinAdrPL07).
 * msgWinPL07_16P 0x3267e0 size 0x4: match (placed by msgWinAdrPL07).
 * msgWinPL07_17P 0x3267e4 size 0x4: match (placed by msgWinAdrPL07).
 * msgWinPL07_18P 0x3267e8 size 0x4: match (placed by msgWinAdrPL07).
 * msgWinPL07_19P 0x3267ec size 0x4: match (placed by msgWinAdrPL07).
 * msgWinPL07_20P 0x3267f0 size 0x8: match (placed by msgWinAdrPL07).
 * msgWinPL07_21P 0x3267f8 size 0x8: match (placed by msgWinAdrPL07).
 * msgWinPL07_22P 0x326800 size 0x8: match (placed by msgWinAdrPL07).
 * msgWinPL07_23P 0x326808 size 0x8: match (placed by msgWinAdrPL07).
 * msgWinPL07_24P 0x326810 size 0x8: match (placed by msgWinAdrPL07).
 * msgWinPL07_25P 0x326818 size 0x8: match (placed by msgWinAdrPL07).
 * msgWinPL07_26P 0x326820 size 0x8: match (placed by msgWinAdrPL07).
 * msgWinPL07_27P 0x326828 size 0x8: match (placed by msgWinAdrPL07).
 * pl07win_usa_tbl 0x3268bc size 0x8: match (placed by pl_mes_tbl).
 */

#include "structs.h"
#include <stddef.h>

/* from sf33rd/Source/Game/Message3rd/C_USA/PL07Win_usa.h */
extern MessageTable pl07win_usa_tbl;

static s8* msgWinPL07_00P[1] = { "" };
static s8* msgWinPL07_01P[1] = { "" };
static s8* msgWinPL07_02P[1] = { "" };
static s8* msgWinPL07_03P[1] = { "" };
static s8* msgWinPL07_04P[1] = { "" };
static s8* msgWinPL07_05P[1] = { "" };
static s8* msgWinPL07_06P[1] = { "" };
static s8* msgWinPL07_07P[1] = { "" };
static s8* msgWinPL07_08P[1] = { "" };
static s8* msgWinPL07_09P[1] = { "" };
static s8* msgWinPL07_10P[1] = { "" };
static s8* msgWinPL07_11P[1] = { "" };
static s8* msgWinPL07_12P[1] = { "" };
static s8* msgWinPL07_13P[1] = { "" };
static s8* msgWinPL07_14P[1] = { "" };
static s8* msgWinPL07_15P[1] = { "" };
static s8* msgWinPL07_16P[1] = { "" };
static s8* msgWinPL07_17P[1] = { "" };
static s8* msgWinPL07_18P[1] = { "" };
static s8* msgWinPL07_19P[1] = { "" };
static s8* msgWinPL07_20P[2] = {
    "   I can't let anyone know that I               ",
    "   wasted my time on a loser like you!          ",
};
static s8* msgWinPL07_21P[2] = {
    "   I'm sorry it went so quickly!                ",
    "   A girl's gotta have fun, you know!           ",
};
static s8* msgWinPL07_22P[2] = {
    "   What a crazy graduation exam!                ",
    "   Being a Shinobi isn't easy!                  ",
};
static s8* msgWinPL07_23P[2] = {
    "   I have clothes that are much more            ",
    "   fashionable than this! Believe me!           ",
};
static s8* msgWinPL07_24P[2] = {
    "   Please don't look. I have to change          ",
    "   outfits and I'm out of bombs...              ",
};
static s8* msgWinPL07_25P[2] = {
    "   Hey, I'll tell everyone you                  ",
    "   put up a good fight, okay?                   ",
};
static s8* msgWinPL07_26P[2] = {
    "   That wasn't the most efficient way           ",
    "   to knock you out, but it worked!             ",
};
static s8* msgWinPL07_27P[2] = {
    "   I don't think you'd last long at             ",
    "   all if you were in my village...             ",
};

static s8** msgWinAdrPL07[28] = {
    msgWinPL07_00P, msgWinPL07_01P, msgWinPL07_02P, msgWinPL07_03P, msgWinPL07_04P, msgWinPL07_05P, msgWinPL07_06P,
    msgWinPL07_07P, msgWinPL07_08P, msgWinPL07_09P, msgWinPL07_10P, msgWinPL07_11P, msgWinPL07_12P, msgWinPL07_13P,
    msgWinPL07_14P, msgWinPL07_15P, msgWinPL07_16P, msgWinPL07_17P, msgWinPL07_18P, msgWinPL07_19P, msgWinPL07_20P,
    msgWinPL07_21P, msgWinPL07_22P, msgWinPL07_23P, msgWinPL07_24P, msgWinPL07_25P, msgWinPL07_26P, msgWinPL07_27P,
};

static s8 msgWinCtrPL07[28] = {
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2,
};

MessageTable pl07win_usa_tbl = { msgWinAdrPL07, msgWinCtrPL07 };
