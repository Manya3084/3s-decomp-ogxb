/* PL03Win_usa.c, retail sf33rd.xbe.
 * The PS2 file's data (ps2.path), checked by analysis-ps2map/portdata.py
 * against the XBE: each table at its data.txt address, or at the
 * address a checked table's pointer to it holds ("placed by").
 * msgWinAdrPL03 0x325f88 size 0x70: match (placed by pl03win_usa_tbl).
 * msgWinCtrPL03 0x325ff8 size 0x1c: match (placed by pl03win_usa_tbl).
 * msgWinPL03_00P 0x325ef8 size 0x4: match (placed by msgWinAdrPL03).
 * msgWinPL03_01P 0x325efc size 0x4: match (placed by msgWinAdrPL03).
 * msgWinPL03_02P 0x325f00 size 0x4: match (placed by msgWinAdrPL03).
 * msgWinPL03_03P 0x325f04 size 0x4: match (placed by msgWinAdrPL03).
 * msgWinPL03_04P 0x325f08 size 0x4: match (placed by msgWinAdrPL03).
 * msgWinPL03_05P 0x325f0c size 0x4: match (placed by msgWinAdrPL03).
 * msgWinPL03_06P 0x325f10 size 0x4: match (placed by msgWinAdrPL03).
 * msgWinPL03_07P 0x325f14 size 0x4: match (placed by msgWinAdrPL03).
 * msgWinPL03_08P 0x325f18 size 0x4: match (placed by msgWinAdrPL03).
 * msgWinPL03_09P 0x325f1c size 0x4: match (placed by msgWinAdrPL03).
 * msgWinPL03_10P 0x325f20 size 0x4: match (placed by msgWinAdrPL03).
 * msgWinPL03_11P 0x325f24 size 0x4: match (placed by msgWinAdrPL03).
 * msgWinPL03_12P 0x325f28 size 0x4: match (placed by msgWinAdrPL03).
 * msgWinPL03_13P 0x325f2c size 0x4: match (placed by msgWinAdrPL03).
 * msgWinPL03_14P 0x325f30 size 0x4: match (placed by msgWinAdrPL03).
 * msgWinPL03_15P 0x325f34 size 0x4: match (placed by msgWinAdrPL03).
 * msgWinPL03_16P 0x325f38 size 0x4: match (placed by msgWinAdrPL03).
 * msgWinPL03_17P 0x325f3c size 0x4: match (placed by msgWinAdrPL03).
 * msgWinPL03_18P 0x325f40 size 0x4: match (placed by msgWinAdrPL03).
 * msgWinPL03_19P 0x325f44 size 0x4: match (placed by msgWinAdrPL03).
 * msgWinPL03_20P 0x325f48 size 0x8: match (placed by msgWinAdrPL03).
 * msgWinPL03_21P 0x325f50 size 0x8: match (placed by msgWinAdrPL03).
 * msgWinPL03_22P 0x325f58 size 0x8: match (placed by msgWinAdrPL03).
 * msgWinPL03_23P 0x325f60 size 0x8: match (placed by msgWinAdrPL03).
 * msgWinPL03_24P 0x325f68 size 0x8: match (placed by msgWinAdrPL03).
 * msgWinPL03_25P 0x325f70 size 0x4: match (placed by msgWinAdrPL03).
 * msgWinPL03_26P 0x325f74 size 0x8: match (placed by msgWinAdrPL03).
 * msgWinPL03_27P 0x325f7c size 0x8: match (placed by msgWinAdrPL03).
 * pl03win_usa_tbl 0x326014 size 0x8: match (placed by pl_mes_tbl).
 */

#include "structs.h"
#include <stddef.h>

/* from sf33rd/Source/Game/Message3rd/C_USA/PL03Win_usa.h */
extern MessageTable pl03win_usa_tbl;

static s8* msgWinPL03_00P[1] = { "" };
static s8* msgWinPL03_01P[1] = { "" };
static s8* msgWinPL03_02P[1] = { "" };
static s8* msgWinPL03_03P[1] = { "" };
static s8* msgWinPL03_04P[1] = { "" };
static s8* msgWinPL03_05P[1] = { "" };
static s8* msgWinPL03_06P[1] = { "" };
static s8* msgWinPL03_07P[1] = { "" };
static s8* msgWinPL03_08P[1] = { "" };
static s8* msgWinPL03_09P[1] = { "" };
static s8* msgWinPL03_10P[1] = { "" };
static s8* msgWinPL03_11P[1] = { "" };
static s8* msgWinPL03_12P[1] = { "" };
static s8* msgWinPL03_13P[1] = { "" };
static s8* msgWinPL03_14P[1] = { "" };
static s8* msgWinPL03_15P[1] = { "" };
static s8* msgWinPL03_16P[1] = { "" };
static s8* msgWinPL03_17P[1] = { "" };
static s8* msgWinPL03_18P[1] = { "" };
static s8* msgWinPL03_19P[1] = { "" };
static s8* msgWinPL03_20P[2] = {
    "   I see why you lost... You weren't            ",
    "   having any fun during the fight!             ",
};
static s8* msgWinPL03_21P[2] = {
    "   My style may change, but the outcome         ",
    "   is always the same. I win. You lose!         ",
};
static s8* msgWinPL03_22P[2] = {
    "   Now you're always afraid of things           ",
    "   falling on you from above? Sorry!            ",
};
static s8* msgWinPL03_23P[2] = {
    "   I'd rather rave than                         ",
    "   misbehave! Later!                            ",
};
static s8* msgWinPL03_24P[2] = {
    "   Perhaps you'd prefer to challenge            ",
    "   me at a skateboarding game?                  ",
};
static s8* msgWinPL03_25P[1] = { "   Cheap? I paid a lot for this hat!            " };
static s8* msgWinPL03_26P[2] = {
    "   My skateboard isn't a stretcher,             ",
    "   but it'll get you to the hospital!           ",
};
static s8* msgWinPL03_27P[2] = {
    "   Don't you know it's rude to ask your         ",
    "   opponent to let you win a round?!            ",
};

static s8** msgWinAdrPL03[28] = {
    msgWinPL03_00P, msgWinPL03_01P, msgWinPL03_02P, msgWinPL03_03P, msgWinPL03_04P, msgWinPL03_05P, msgWinPL03_06P,
    msgWinPL03_07P, msgWinPL03_08P, msgWinPL03_09P, msgWinPL03_10P, msgWinPL03_11P, msgWinPL03_12P, msgWinPL03_13P,
    msgWinPL03_14P, msgWinPL03_15P, msgWinPL03_16P, msgWinPL03_17P, msgWinPL03_18P, msgWinPL03_19P, msgWinPL03_20P,
    msgWinPL03_21P, msgWinPL03_22P, msgWinPL03_23P, msgWinPL03_24P, msgWinPL03_25P, msgWinPL03_26P, msgWinPL03_27P,
};

static s8 msgWinCtrPL03[28] = {
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 1, 2, 2,
};

MessageTable pl03win_usa_tbl = { msgWinAdrPL03, msgWinCtrPL03 };
