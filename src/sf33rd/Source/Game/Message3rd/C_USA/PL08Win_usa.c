/* PL08Win_usa.c, retail sf33rd.xbe.
 * The PS2 file's data (ps2.path), checked by analysis-ps2map/portdata.py
 * against the XBE: each table at its data.txt address, or at the
 * address a checked table's pointer to it holds ("placed by").
 * msgWinAdrPL08 0x326a40 size 0x70: match (placed by pl08win_usa_tbl).
 * msgWinCtrPL08 0x326ab0 size 0x1c: match (placed by pl08win_usa_tbl).
 * msgWinPL08_00P 0x3269b0 size 0x4: match (placed by msgWinAdrPL08).
 * msgWinPL08_01P 0x3269b4 size 0x4: match (placed by msgWinAdrPL08).
 * msgWinPL08_02P 0x3269b8 size 0x4: match (placed by msgWinAdrPL08).
 * msgWinPL08_03P 0x3269bc size 0x4: match (placed by msgWinAdrPL08).
 * msgWinPL08_04P 0x3269c0 size 0x4: match (placed by msgWinAdrPL08).
 * msgWinPL08_05P 0x3269c4 size 0x4: match (placed by msgWinAdrPL08).
 * msgWinPL08_06P 0x3269c8 size 0x4: match (placed by msgWinAdrPL08).
 * msgWinPL08_07P 0x3269cc size 0x4: match (placed by msgWinAdrPL08).
 * msgWinPL08_08P 0x3269d0 size 0x4: match (placed by msgWinAdrPL08).
 * msgWinPL08_09P 0x3269d4 size 0x4: match (placed by msgWinAdrPL08).
 * msgWinPL08_10P 0x3269d8 size 0x4: match (placed by msgWinAdrPL08).
 * msgWinPL08_11P 0x3269dc size 0x4: match (placed by msgWinAdrPL08).
 * msgWinPL08_12P 0x3269e0 size 0x4: match (placed by msgWinAdrPL08).
 * msgWinPL08_13P 0x3269e4 size 0x4: match (placed by msgWinAdrPL08).
 * msgWinPL08_14P 0x3269e8 size 0x4: match (placed by msgWinAdrPL08).
 * msgWinPL08_15P 0x3269ec size 0x4: match (placed by msgWinAdrPL08).
 * msgWinPL08_16P 0x3269f0 size 0x4: match (placed by msgWinAdrPL08).
 * msgWinPL08_17P 0x3269f4 size 0x4: match (placed by msgWinAdrPL08).
 * msgWinPL08_18P 0x3269f8 size 0x4: match (placed by msgWinAdrPL08).
 * msgWinPL08_19P 0x3269fc size 0x4: match (placed by msgWinAdrPL08).
 * msgWinPL08_20P 0x326a00 size 0x8: match (placed by msgWinAdrPL08).
 * msgWinPL08_21P 0x326a08 size 0x8: match (placed by msgWinAdrPL08).
 * msgWinPL08_22P 0x326a10 size 0x8: match (placed by msgWinAdrPL08).
 * msgWinPL08_23P 0x326a18 size 0x8: match (placed by msgWinAdrPL08).
 * msgWinPL08_24P 0x326a20 size 0x8: match (placed by msgWinAdrPL08).
 * msgWinPL08_25P 0x326a28 size 0x8: match (placed by msgWinAdrPL08).
 * msgWinPL08_26P 0x326a30 size 0x8: match (placed by msgWinAdrPL08).
 * msgWinPL08_27P 0x326a38 size 0x8: match (placed by msgWinAdrPL08).
 * pl08win_usa_tbl 0x326acc size 0x8: match (placed by pl_mes_tbl).
 */

#include "structs.h"
#include <stddef.h>

/* from sf33rd/Source/Game/Message3rd/C_USA/PL08Win_usa.h */
extern MessageTable pl08win_usa_tbl;

static s8* msgWinPL08_00P[1] = { "" };
static s8* msgWinPL08_01P[1] = { "" };
static s8* msgWinPL08_02P[1] = { "" };
static s8* msgWinPL08_03P[1] = { "" };
static s8* msgWinPL08_04P[1] = { "" };
static s8* msgWinPL08_05P[1] = { "" };
static s8* msgWinPL08_06P[1] = { "" };
static s8* msgWinPL08_07P[1] = { "" };
static s8* msgWinPL08_08P[1] = { "" };
static s8* msgWinPL08_09P[1] = { "" };
static s8* msgWinPL08_10P[1] = { "" };
static s8* msgWinPL08_11P[1] = { "" };
static s8* msgWinPL08_12P[1] = { "" };
static s8* msgWinPL08_13P[1] = { "" };
static s8* msgWinPL08_14P[1] = { "" };
static s8* msgWinPL08_15P[1] = { "" };
static s8* msgWinPL08_16P[1] = { "" };
static s8* msgWinPL08_17P[1] = { "" };
static s8* msgWinPL08_18P[1] = { "" };
static s8* msgWinPL08_19P[1] = { "" };
static s8* msgWinPL08_20P[2] = {
    "   I hope this moment of friendship             ",
    "   will bring you many happy memories!          ",
};
static s8* msgWinPL08_21P[2] = {
    "   My accent? I must have picked                ",
    "   it up during my travels!                     ",
};
static s8* msgWinPL08_22P[2] = {
    "   That was my best dance,                      ",
    "   performed especially for you!                ",
};
static s8* msgWinPL08_23P[2] = {
    "   When you feel the wind, you can feel         ",
    "   many elements of nature at work.             ",
};
static s8* msgWinPL08_24P[2] = {
    "   You need to be more flexible. Let            ",
    "   me help you to stretch your body!            ",
};
static s8* msgWinPL08_25P[2] = {
    "   Forget about your troubles and               ",
    "   realize the harmony around us!               ",
};
static s8* msgWinPL08_26P[2] = {
    "   Get addicted to the beat!                    ",
    "   Rhythm can be your friend too!               ",
};
static s8* msgWinPL08_27P[2] = {
    "   You could teach me some new moves!           ",
    "   Let's dance together again!                  ",
};

static s8** msgWinAdrPL08[28] = {
    msgWinPL08_00P, msgWinPL08_01P, msgWinPL08_02P, msgWinPL08_03P, msgWinPL08_04P, msgWinPL08_05P, msgWinPL08_06P,
    msgWinPL08_07P, msgWinPL08_08P, msgWinPL08_09P, msgWinPL08_10P, msgWinPL08_11P, msgWinPL08_12P, msgWinPL08_13P,
    msgWinPL08_14P, msgWinPL08_15P, msgWinPL08_16P, msgWinPL08_17P, msgWinPL08_18P, msgWinPL08_19P, msgWinPL08_20P,
    msgWinPL08_21P, msgWinPL08_22P, msgWinPL08_23P, msgWinPL08_24P, msgWinPL08_25P, msgWinPL08_26P, msgWinPL08_27P,
};

static s8 msgWinCtrPL08[28] = {
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2,
};

MessageTable pl08win_usa_tbl = { msgWinAdrPL08, msgWinCtrPL08 };
