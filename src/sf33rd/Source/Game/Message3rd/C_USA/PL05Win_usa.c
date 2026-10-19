/* PL05Win_usa.c, retail sf33rd.xbe.
 * The PS2 file's data (ps2.path), checked by analysis-ps2map/portdata.py
 * against the XBE: each table at its data.txt address, or at the
 * address a checked table's pointer to it holds ("placed by").
 * msgWinAdrPL05 0x3263b0 size 0x70: match (placed by pl05win_usa_tbl).
 * msgWinCtrPL05 0x326420 size 0x1c: match (placed by pl05win_usa_tbl).
 * msgWinPL05_00P 0x326320 size 0x4: match (placed by msgWinAdrPL05).
 * msgWinPL05_01P 0x326324 size 0x4: match (placed by msgWinAdrPL05).
 * msgWinPL05_02P 0x326328 size 0x4: match (placed by msgWinAdrPL05).
 * msgWinPL05_03P 0x32632c size 0x4: match (placed by msgWinAdrPL05).
 * msgWinPL05_04P 0x326330 size 0x4: match (placed by msgWinAdrPL05).
 * msgWinPL05_05P 0x326334 size 0x4: match (placed by msgWinAdrPL05).
 * msgWinPL05_06P 0x326338 size 0x4: match (placed by msgWinAdrPL05).
 * msgWinPL05_07P 0x32633c size 0x4: match (placed by msgWinAdrPL05).
 * msgWinPL05_08P 0x326340 size 0x4: match (placed by msgWinAdrPL05).
 * msgWinPL05_09P 0x326344 size 0x4: match (placed by msgWinAdrPL05).
 * msgWinPL05_10P 0x326348 size 0x4: match (placed by msgWinAdrPL05).
 * msgWinPL05_11P 0x32634c size 0x4: match (placed by msgWinAdrPL05).
 * msgWinPL05_12P 0x326350 size 0x4: match (placed by msgWinAdrPL05).
 * msgWinPL05_13P 0x326354 size 0x4: match (placed by msgWinAdrPL05).
 * msgWinPL05_14P 0x326358 size 0x4: match (placed by msgWinAdrPL05).
 * msgWinPL05_15P 0x32635c size 0x4: match (placed by msgWinAdrPL05).
 * msgWinPL05_16P 0x326360 size 0x4: match (placed by msgWinAdrPL05).
 * msgWinPL05_17P 0x326364 size 0x4: match (placed by msgWinAdrPL05).
 * msgWinPL05_18P 0x326368 size 0x4: match (placed by msgWinAdrPL05).
 * msgWinPL05_19P 0x32636c size 0x4: match (placed by msgWinAdrPL05).
 * msgWinPL05_20P 0x326370 size 0x8: match (placed by msgWinAdrPL05).
 * msgWinPL05_21P 0x326378 size 0x8: match (placed by msgWinAdrPL05).
 * msgWinPL05_22P 0x326380 size 0x8: match (placed by msgWinAdrPL05).
 * msgWinPL05_23P 0x326388 size 0x8: match (placed by msgWinAdrPL05).
 * msgWinPL05_24P 0x326390 size 0x8: match (placed by msgWinAdrPL05).
 * msgWinPL05_25P 0x326398 size 0x8: match (placed by msgWinAdrPL05).
 * msgWinPL05_26P 0x3263a0 size 0x8: match (placed by msgWinAdrPL05).
 * msgWinPL05_27P 0x3263a8 size 0x8: match (placed by msgWinAdrPL05).
 * pl05win_usa_tbl 0x32643c size 0x8: match (placed by pl_mes_tbl).
 */

#include "structs.h"
#include <stddef.h>

/* from sf33rd/Source/Game/Message3rd/C_USA/PL05Win_usa.h */
extern MessageTable pl05win_usa_tbl;

static s8* msgWinPL05_00P[1] = { "" };
static s8* msgWinPL05_01P[1] = { "" };
static s8* msgWinPL05_02P[1] = { "" };
static s8* msgWinPL05_03P[1] = { "" };
static s8* msgWinPL05_04P[1] = { "" };
static s8* msgWinPL05_05P[1] = { "" };
static s8* msgWinPL05_06P[1] = { "" };
static s8* msgWinPL05_07P[1] = { "" };
static s8* msgWinPL05_08P[1] = { "" };
static s8* msgWinPL05_09P[1] = { "" };
static s8* msgWinPL05_10P[1] = { "" };
static s8* msgWinPL05_11P[1] = { "" };
static s8* msgWinPL05_12P[1] = { "" };
static s8* msgWinPL05_13P[1] = { "" };
static s8* msgWinPL05_14P[1] = { "" };
static s8* msgWinPL05_15P[1] = { "" };
static s8* msgWinPL05_16P[1] = { "" };
static s8* msgWinPL05_17P[1] = { "" };
static s8* msgWinPL05_18P[1] = { "" };
static s8* msgWinPL05_19P[1] = { "" };
static s8* msgWinPL05_20P[2] = {
    "   What's that smell? That's the aroma          ",
    "   of freshly cooked brain matter!              ",
};
static s8* msgWinPL05_21P[2] = {
    "   The pain sensitivity of the flesh            ",
    "   varies. Where does it hurt the most?         ",
};
static s8* msgWinPL05_22P[2] = {
    "   Freedom was once just a dream.               ",
    "   Now, I can fight to achieve it!              ",
};
static s8* msgWinPL05_23P[2] = {
    "   When I realized that I was no longer         ",
    "   alone, I became determined to win!           ",
};
static s8* msgWinPL05_24P[2] = {
    "   I'm long and I'm strong!                     ",
    "   To challenge me would be so wrong!           ",
};
static s8* msgWinPL05_25P[2] = {
    "   You think I'm a freak? You should            ",
    "   see some of these other characters!          ",
};
static s8* msgWinPL05_26P[2] = {
    "   A little battery won't kill ya...            ",
    "   Or will it?                                  ",
};
static s8* msgWinPL05_27P[2] = {
    "   If you thought that was abnormal,            ",
    "   wait until you see THIS!!                    ",
};

static s8** msgWinAdrPL05[28] = {
    msgWinPL05_00P, msgWinPL05_01P, msgWinPL05_02P, msgWinPL05_03P, msgWinPL05_04P, msgWinPL05_05P, msgWinPL05_06P,
    msgWinPL05_07P, msgWinPL05_08P, msgWinPL05_09P, msgWinPL05_10P, msgWinPL05_11P, msgWinPL05_12P, msgWinPL05_13P,
    msgWinPL05_14P, msgWinPL05_15P, msgWinPL05_16P, msgWinPL05_17P, msgWinPL05_18P, msgWinPL05_19P, msgWinPL05_20P,
    msgWinPL05_21P, msgWinPL05_22P, msgWinPL05_23P, msgWinPL05_24P, msgWinPL05_25P, msgWinPL05_26P, msgWinPL05_27P,
};

static s8 msgWinCtrPL05[28] = {
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2,
};

MessageTable pl05win_usa_tbl = { msgWinAdrPL05, msgWinCtrPL05 };
