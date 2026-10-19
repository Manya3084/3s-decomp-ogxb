/* PL10Win_usa.c, retail sf33rd.xbe.
 * The PS2 file's data (ps2.path), checked by analysis-ps2map/portdata.py
 * against the XBE: each table at its data.txt address, or at the
 * address a checked table's pointer to it holds ("placed by").
 * msgWinAdrPL10 0x326ed8 size 0x70: match (placed by pl10win_usa_tbl).
 * msgWinCtrPL10 0x326f48 size 0x1c: match (placed by pl10win_usa_tbl).
 * msgWinPL10_00P 0x326e48 size 0x4: match (placed by msgWinAdrPL10).
 * msgWinPL10_01P 0x326e4c size 0x4: match (placed by msgWinAdrPL10).
 * msgWinPL10_02P 0x326e50 size 0x4: match (placed by msgWinAdrPL10).
 * msgWinPL10_03P 0x326e54 size 0x4: match (placed by msgWinAdrPL10).
 * msgWinPL10_04P 0x326e58 size 0x4: match (placed by msgWinAdrPL10).
 * msgWinPL10_05P 0x326e5c size 0x4: match (placed by msgWinAdrPL10).
 * msgWinPL10_06P 0x326e60 size 0x4: match (placed by msgWinAdrPL10).
 * msgWinPL10_07P 0x326e64 size 0x4: match (placed by msgWinAdrPL10).
 * msgWinPL10_08P 0x326e68 size 0x4: match (placed by msgWinAdrPL10).
 * msgWinPL10_09P 0x326e6c size 0x4: match (placed by msgWinAdrPL10).
 * msgWinPL10_10P 0x326e70 size 0x4: match (placed by msgWinAdrPL10).
 * msgWinPL10_11P 0x326e74 size 0x4: match (placed by msgWinAdrPL10).
 * msgWinPL10_12P 0x326e78 size 0x4: match (placed by msgWinAdrPL10).
 * msgWinPL10_13P 0x326e7c size 0x4: match (placed by msgWinAdrPL10).
 * msgWinPL10_14P 0x326e80 size 0x4: match (placed by msgWinAdrPL10).
 * msgWinPL10_15P 0x326e84 size 0x4: match (placed by msgWinAdrPL10).
 * msgWinPL10_16P 0x326e88 size 0x4: match (placed by msgWinAdrPL10).
 * msgWinPL10_17P 0x326e8c size 0x4: match (placed by msgWinAdrPL10).
 * msgWinPL10_18P 0x326e90 size 0x4: match (placed by msgWinAdrPL10).
 * msgWinPL10_19P 0x326e94 size 0x4: match (placed by msgWinAdrPL10).
 * msgWinPL10_20P 0x326e98 size 0x8: match (placed by msgWinAdrPL10).
 * msgWinPL10_21P 0x326ea0 size 0x8: match (placed by msgWinAdrPL10).
 * msgWinPL10_22P 0x326ea8 size 0x8: match (placed by msgWinAdrPL10).
 * msgWinPL10_23P 0x326eb0 size 0x8: match (placed by msgWinAdrPL10).
 * msgWinPL10_24P 0x326eb8 size 0x8: match (placed by msgWinAdrPL10).
 * msgWinPL10_25P 0x326ec0 size 0x8: match (placed by msgWinAdrPL10).
 * msgWinPL10_26P 0x326ec8 size 0x8: match (placed by msgWinAdrPL10).
 * msgWinPL10_27P 0x326ed0 size 0x8: match (placed by msgWinAdrPL10).
 * pl10win_usa_tbl 0x326f64 size 0x8: match (placed by pl_mes_tbl).
 */

#include "structs.h"
#include <stddef.h>

/* from sf33rd/Source/Game/Message3rd/C_USA/PL10Win_usa.h */
extern MessageTable pl10win_usa_tbl;

static s8* msgWinPL10_00P[1] = { "" };
static s8* msgWinPL10_01P[1] = { "" };
static s8* msgWinPL10_02P[1] = { "" };
static s8* msgWinPL10_03P[1] = { "" };
static s8* msgWinPL10_04P[1] = { "" };
static s8* msgWinPL10_05P[1] = { "" };
static s8* msgWinPL10_06P[1] = { "" };
static s8* msgWinPL10_07P[1] = { "" };
static s8* msgWinPL10_08P[1] = { "" };
static s8* msgWinPL10_09P[1] = { "" };
static s8* msgWinPL10_10P[1] = { "" };
static s8* msgWinPL10_11P[1] = { "" };
static s8* msgWinPL10_12P[1] = { "" };
static s8* msgWinPL10_13P[1] = { "" };
static s8* msgWinPL10_14P[1] = { "" };
static s8* msgWinPL10_15P[1] = { "" };
static s8* msgWinPL10_16P[1] = { "" };
static s8* msgWinPL10_17P[1] = { "" };
static s8* msgWinPL10_18P[1] = { "" };
static s8* msgWinPL10_19P[1] = { "" };
static s8* msgWinPL10_20P[2] = {
    "   I was trying not to piss you off...          ",
    "   I guess I wasn't trying hard enough!         ",
};
static s8* msgWinPL10_21P[2] = {
    "   I hope you planned on taking a long          ",
    "   vacation. You'll need it to heal!            ",
};
static s8* msgWinPL10_22P[2] = {
    "   Don't assume that the same patterns          ",
    "   you use on others will work on me!           ",
};
static s8* msgWinPL10_23P[2] = {
    "   Every wound is a punishment                  ",
    "   for your careless training!                  ",
};
static s8* msgWinPL10_24P[2] = {
    "   I wonder if my brother would have            ",
    "   hurt you even more than I did...             ",
};
static s8* msgWinPL10_25P[2] = {
    "   Unless you want to disgrace history,         ",
    "   don't call what we did a fight!              ",
};
static s8* msgWinPL10_26P[2] = {
    "   An angry fighter is an ineffective           ",
    "   one... Not to mention ugly, too...           ",
};
static s8* msgWinPL10_27P[2] = {
    "   I move with the grace of the wind,           ",
    "   you just make it smell bad!                  ",
};

static s8** msgWinAdrPL10[28] = {
    msgWinPL10_00P, msgWinPL10_01P, msgWinPL10_02P, msgWinPL10_03P, msgWinPL10_04P, msgWinPL10_05P, msgWinPL10_06P,
    msgWinPL10_07P, msgWinPL10_08P, msgWinPL10_09P, msgWinPL10_10P, msgWinPL10_11P, msgWinPL10_12P, msgWinPL10_13P,
    msgWinPL10_14P, msgWinPL10_15P, msgWinPL10_16P, msgWinPL10_17P, msgWinPL10_18P, msgWinPL10_19P, msgWinPL10_20P,
    msgWinPL10_21P, msgWinPL10_22P, msgWinPL10_23P, msgWinPL10_24P, msgWinPL10_25P, msgWinPL10_26P, msgWinPL10_27P,
};

static s8 msgWinCtrPL10[28] = {
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2,
};

MessageTable pl10win_usa_tbl = { msgWinAdrPL10, msgWinCtrPL10 };
