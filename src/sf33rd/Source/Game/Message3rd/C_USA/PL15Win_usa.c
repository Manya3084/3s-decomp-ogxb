/* PL15Win_usa.c, retail sf33rd.xbe.
 * The PS2 file's data (ps2.path), checked by analysis-ps2map/portdata.py
 * against the XBE: each table at its data.txt address, or at the
 * address a checked table's pointer to it holds ("placed by").
 * msgWinAdrPL15 0x327930 size 0x70: match (placed by pl15win_usa_tbl).
 * msgWinCtrPL15 0x3279a0 size 0x1c: match (placed by pl15win_usa_tbl).
 * msgWinPL15_00P 0x3278a0 size 0x4: match (placed by msgWinAdrPL15).
 * msgWinPL15_01P 0x3278a4 size 0x4: match (placed by msgWinAdrPL15).
 * msgWinPL15_02P 0x3278a8 size 0x4: match (placed by msgWinAdrPL15).
 * msgWinPL15_03P 0x3278ac size 0x4: match (placed by msgWinAdrPL15).
 * msgWinPL15_04P 0x3278b0 size 0x4: match (placed by msgWinAdrPL15).
 * msgWinPL15_05P 0x3278b4 size 0x4: match (placed by msgWinAdrPL15).
 * msgWinPL15_06P 0x3278b8 size 0x4: match (placed by msgWinAdrPL15).
 * msgWinPL15_07P 0x3278bc size 0x4: match (placed by msgWinAdrPL15).
 * msgWinPL15_08P 0x3278c0 size 0x4: match (placed by msgWinAdrPL15).
 * msgWinPL15_09P 0x3278c4 size 0x4: match (placed by msgWinAdrPL15).
 * msgWinPL15_10P 0x3278c8 size 0x4: match (placed by msgWinAdrPL15).
 * msgWinPL15_11P 0x3278cc size 0x4: match (placed by msgWinAdrPL15).
 * msgWinPL15_12P 0x3278d0 size 0x4: match (placed by msgWinAdrPL15).
 * msgWinPL15_13P 0x3278d4 size 0x4: match (placed by msgWinAdrPL15).
 * msgWinPL15_14P 0x3278d8 size 0x4: match (placed by msgWinAdrPL15).
 * msgWinPL15_15P 0x3278dc size 0x4: match (placed by msgWinAdrPL15).
 * msgWinPL15_16P 0x3278e0 size 0x4: match (placed by msgWinAdrPL15).
 * msgWinPL15_17P 0x3278e4 size 0x4: match (placed by msgWinAdrPL15).
 * msgWinPL15_18P 0x3278e8 size 0x4: match (placed by msgWinAdrPL15).
 * msgWinPL15_19P 0x3278ec size 0x4: match (placed by msgWinAdrPL15).
 * msgWinPL15_20P 0x3278f0 size 0x8: match (placed by msgWinAdrPL15).
 * msgWinPL15_21P 0x3278f8 size 0x8: match (placed by msgWinAdrPL15).
 * msgWinPL15_22P 0x327900 size 0x8: match (placed by msgWinAdrPL15).
 * msgWinPL15_23P 0x327908 size 0x8: match (placed by msgWinAdrPL15).
 * msgWinPL15_24P 0x327910 size 0x8: match (placed by msgWinAdrPL15).
 * msgWinPL15_25P 0x327918 size 0x8: match (placed by msgWinAdrPL15).
 * msgWinPL15_26P 0x327920 size 0x8: match (placed by msgWinAdrPL15).
 * msgWinPL15_27P 0x327928 size 0x8: match (placed by msgWinAdrPL15).
 * pl15win_usa_tbl 0x3279bc size 0x8: match (placed by pl_mes_tbl).
 */

#include "structs.h"
#include <stddef.h>

/* from sf33rd/Source/Game/Message3rd/C_USA/PL15Win_usa.h */
extern MessageTable pl15win_usa_tbl;

static s8* msgWinPL15_00P[1] = { "" };
static s8* msgWinPL15_01P[1] = { "" };
static s8* msgWinPL15_02P[1] = { "" };
static s8* msgWinPL15_03P[1] = { "" };
static s8* msgWinPL15_04P[1] = { "" };
static s8* msgWinPL15_05P[1] = { "" };
static s8* msgWinPL15_06P[1] = { "" };
static s8* msgWinPL15_07P[1] = { "" };
static s8* msgWinPL15_08P[1] = { "" };
static s8* msgWinPL15_09P[1] = { "" };
static s8* msgWinPL15_10P[1] = { "" };
static s8* msgWinPL15_11P[1] = { "" };
static s8* msgWinPL15_12P[1] = { "" };
static s8* msgWinPL15_13P[1] = { "" };
static s8* msgWinPL15_14P[1] = { "" };
static s8* msgWinPL15_15P[1] = { "" };
static s8* msgWinPL15_16P[1] = { "" };
static s8* msgWinPL15_17P[1] = { "" };
static s8* msgWinPL15_18P[1] = { "" };
static s8* msgWinPL15_19P[1] = { "" };
static s8* msgWinPL15_20P[2] = {
    "   It's been much too long since                ",
    "   I've been in a fair fight!                   ",
};
static s8* msgWinPL15_21P[2] = {
    "   Hey, leave me alone!                         ",
    "   I'm a fighter, not a news reporter!          ",
};
static s8* msgWinPL15_22P[2] = {
    "   No, I've never thrown any of my              ",
    "   bracelets away. Why do you ask?              ",
};
static s8* msgWinPL15_23P[2] = {
    "   Power is useless without                     ",
    "   skill and speed!                             ",
};
static s8* msgWinPL15_24P[2] = {
    "   Put some thought into your actions           ",
    "   and you will eliminate your regrets.         ",
};
static s8* msgWinPL15_25P[2] = {
    "   You haven't seen my best yet!                ",
    "   Please let me show you!                      ",
};
static s8* msgWinPL15_26P[2] = {
    "   You'd be great if you found a                ",
    "   better reason to fight!                      ",
};
static s8* msgWinPL15_27P[2] = {
    "   Am I still the strongest                     ",
    "   woman in the world? Tell me!                 ",
};

static s8** msgWinAdrPL15[28] = {
    msgWinPL15_00P, msgWinPL15_01P, msgWinPL15_02P, msgWinPL15_03P, msgWinPL15_04P, msgWinPL15_05P, msgWinPL15_06P,
    msgWinPL15_07P, msgWinPL15_08P, msgWinPL15_09P, msgWinPL15_10P, msgWinPL15_11P, msgWinPL15_12P, msgWinPL15_13P,
    msgWinPL15_14P, msgWinPL15_15P, msgWinPL15_16P, msgWinPL15_17P, msgWinPL15_18P, msgWinPL15_19P, msgWinPL15_20P,
    msgWinPL15_21P, msgWinPL15_22P, msgWinPL15_23P, msgWinPL15_24P, msgWinPL15_25P, msgWinPL15_26P, msgWinPL15_27P,
};

static s8 msgWinCtrPL15[28] = {
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2,
};

MessageTable pl15win_usa_tbl = { msgWinAdrPL15, msgWinCtrPL15 };
