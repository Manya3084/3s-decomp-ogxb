/* PL02Win_usa.c, retail sf33rd.xbe.
 * The PS2 file's data (ps2.path), checked by analysis-ps2map/portdata.py
 * against the XBE: each table at its data.txt address, or at the
 * address a checked table's pointer to it holds ("placed by").
 * msgWinAdrPL02 0x325d00 size 0x70: match (placed by pl02win_usa_tbl).
 * msgWinCtrPL02 0x325d70 size 0x1c: match (placed by pl02win_usa_tbl).
 * msgWinPL02_00P 0x325c70 size 0x4: match (placed by msgWinAdrPL02).
 * msgWinPL02_01P 0x325c74 size 0x4: match (placed by msgWinAdrPL02).
 * msgWinPL02_02P 0x325c78 size 0x4: match (placed by msgWinAdrPL02).
 * msgWinPL02_03P 0x325c7c size 0x4: match (placed by msgWinAdrPL02).
 * msgWinPL02_04P 0x325c80 size 0x4: match (placed by msgWinAdrPL02).
 * msgWinPL02_05P 0x325c84 size 0x4: match (placed by msgWinAdrPL02).
 * msgWinPL02_06P 0x325c88 size 0x4: match (placed by msgWinAdrPL02).
 * msgWinPL02_07P 0x325c8c size 0x4: match (placed by msgWinAdrPL02).
 * msgWinPL02_08P 0x325c90 size 0x4: match (placed by msgWinAdrPL02).
 * msgWinPL02_09P 0x325c94 size 0x4: match (placed by msgWinAdrPL02).
 * msgWinPL02_10P 0x325c98 size 0x4: match (placed by msgWinAdrPL02).
 * msgWinPL02_11P 0x325c9c size 0x4: match (placed by msgWinAdrPL02).
 * msgWinPL02_12P 0x325ca0 size 0x4: match (placed by msgWinAdrPL02).
 * msgWinPL02_13P 0x325ca4 size 0x4: match (placed by msgWinAdrPL02).
 * msgWinPL02_14P 0x325ca8 size 0x4: match (placed by msgWinAdrPL02).
 * msgWinPL02_15P 0x325cac size 0x4: match (placed by msgWinAdrPL02).
 * msgWinPL02_16P 0x325cb0 size 0x4: match (placed by msgWinAdrPL02).
 * msgWinPL02_17P 0x325cb4 size 0x4: match (placed by msgWinAdrPL02).
 * msgWinPL02_18P 0x325cb8 size 0x4: match (placed by msgWinAdrPL02).
 * msgWinPL02_19P 0x325cbc size 0x4: match (placed by msgWinAdrPL02).
 * msgWinPL02_20P 0x325cc0 size 0x8: match (placed by msgWinAdrPL02).
 * msgWinPL02_21P 0x325cc8 size 0x8: match (placed by msgWinAdrPL02).
 * msgWinPL02_22P 0x325cd0 size 0x8: match (placed by msgWinAdrPL02).
 * msgWinPL02_23P 0x325cd8 size 0x8: match (placed by msgWinAdrPL02).
 * msgWinPL02_24P 0x325ce0 size 0x8: match (placed by msgWinAdrPL02).
 * msgWinPL02_25P 0x325ce8 size 0x8: match (placed by msgWinAdrPL02).
 * msgWinPL02_26P 0x325cf0 size 0x8: match (placed by msgWinAdrPL02).
 * msgWinPL02_27P 0x325cf8 size 0x8: match (placed by msgWinAdrPL02).
 * pl02win_usa_tbl 0x325d8c size 0x8: match (placed by pl_mes_tbl).
 */

#include "structs.h"
#include <stddef.h>

/* from sf33rd/Source/Game/Message3rd/C_USA/PL02Win_usa.h */
extern MessageTable pl02win_usa_tbl;

static s8* msgWinPL02_00P[1] = { "" };
static s8* msgWinPL02_01P[1] = { "" };
static s8* msgWinPL02_02P[1] = { "" };
static s8* msgWinPL02_03P[1] = { "" };
static s8* msgWinPL02_04P[1] = { "" };
static s8* msgWinPL02_05P[1] = { "" };
static s8* msgWinPL02_06P[1] = { "" };
static s8* msgWinPL02_07P[1] = { "" };
static s8* msgWinPL02_08P[1] = { "" };
static s8* msgWinPL02_09P[1] = { "" };
static s8* msgWinPL02_10P[1] = { "" };
static s8* msgWinPL02_11P[1] = { "" };
static s8* msgWinPL02_12P[1] = { "" };
static s8* msgWinPL02_13P[1] = { "" };
static s8* msgWinPL02_14P[1] = { "" };
static s8* msgWinPL02_15P[1] = { "" };
static s8* msgWinPL02_16P[1] = { "" };
static s8* msgWinPL02_17P[1] = { "" };
static s8* msgWinPL02_18P[1] = { "" };
static s8* msgWinPL02_19P[1] = { "" };
static s8* msgWinPL02_20P[2] = {
    "   The eyes of a warrior never stray            ",
    "   from the spectacle of battle.                ",
};
static s8* msgWinPL02_21P[2] = {
    "   Every moment gives us a chance to            ",
    "   become more than what we are.                ",
};
static s8* msgWinPL02_22P[2] = {
    "   Range... Speed... Priority...                ",
    "   Know and master all of your attacks!         ",
};
static s8* msgWinPL02_23P[2] = {
    "   A defeat learned from is more                ",
    "   important than an empty victory.             ",
};
static s8* msgWinPL02_24P[2] = {
    "   Seek an opponent who is your equal.          ",
    "   Only then can you improve.                   ",
};
static s8* msgWinPL02_25P[2] = {
    "   It's better to conquer a hardship            ",
    "   than to conquer nothing at all.              ",
};
static s8* msgWinPL02_26P[2] = {
    "   Keep your mind calm and pure.                ",
    "   Focus on what is important!                  ",
};
static s8* msgWinPL02_27P[2] = {
    "   To try something new, is to                  ",
    "   explore your true potential.                 ",
};

static s8** msgWinAdrPL02[28] = {
    msgWinPL02_00P, msgWinPL02_01P, msgWinPL02_02P, msgWinPL02_03P, msgWinPL02_04P, msgWinPL02_05P, msgWinPL02_06P,
    msgWinPL02_07P, msgWinPL02_08P, msgWinPL02_09P, msgWinPL02_10P, msgWinPL02_11P, msgWinPL02_12P, msgWinPL02_13P,
    msgWinPL02_14P, msgWinPL02_15P, msgWinPL02_16P, msgWinPL02_17P, msgWinPL02_18P, msgWinPL02_19P, msgWinPL02_20P,
    msgWinPL02_21P, msgWinPL02_22P, msgWinPL02_23P, msgWinPL02_24P, msgWinPL02_25P, msgWinPL02_26P, msgWinPL02_27P,
};

static s8 msgWinCtrPL02[28] = {
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2,
};

MessageTable pl02win_usa_tbl = { msgWinAdrPL02, msgWinCtrPL02 };
