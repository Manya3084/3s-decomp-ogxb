/* PL17Win_usa.c, retail sf33rd.xbe.
 * The PS2 file's data (ps2.path), checked by analysis-ps2map/portdata.py
 * against the XBE: each table at its data.txt address, or at the
 * address a checked table's pointer to it holds ("placed by").
 * msgWinAdrPL17 0x327d88 size 0x70: match (placed by pl17win_usa_tbl).
 * msgWinCtrPL17 0x327df8 size 0x1c: match (placed by pl17win_usa_tbl).
 * msgWinPL17_00P 0x327d18 size 0x4: match (placed by msgWinAdrPL17).
 * msgWinPL17_01P 0x327d1c size 0x4: match (placed by msgWinAdrPL17).
 * msgWinPL17_02P 0x327d20 size 0x4: match (placed by msgWinAdrPL17).
 * msgWinPL17_03P 0x327d24 size 0x4: match (placed by msgWinAdrPL17).
 * msgWinPL17_04P 0x327d28 size 0x4: match (placed by msgWinAdrPL17).
 * msgWinPL17_05P 0x327d2c size 0x4: match (placed by msgWinAdrPL17).
 * msgWinPL17_06P 0x327d30 size 0x4: match (placed by msgWinAdrPL17).
 * msgWinPL17_07P 0x327d34 size 0x4: match (placed by msgWinAdrPL17).
 * msgWinPL17_08P 0x327d38 size 0x4: match (placed by msgWinAdrPL17).
 * msgWinPL17_09P 0x327d3c size 0x4: match (placed by msgWinAdrPL17).
 * msgWinPL17_10P 0x327d40 size 0x4: match (placed by msgWinAdrPL17).
 * msgWinPL17_11P 0x327d44 size 0x4: match (placed by msgWinAdrPL17).
 * msgWinPL17_12P 0x327d48 size 0x4: match (placed by msgWinAdrPL17).
 * msgWinPL17_13P 0x327d4c size 0x4: match (placed by msgWinAdrPL17).
 * msgWinPL17_14P 0x327d50 size 0x4: match (placed by msgWinAdrPL17).
 * msgWinPL17_15P 0x327d54 size 0x4: match (placed by msgWinAdrPL17).
 * msgWinPL17_16P 0x327d58 size 0x4: match (placed by msgWinAdrPL17).
 * msgWinPL17_17P 0x327d5c size 0x4: match (placed by msgWinAdrPL17).
 * msgWinPL17_18P 0x327d60 size 0x4: match (placed by msgWinAdrPL17).
 * msgWinPL17_19P 0x327d64 size 0x4: match (placed by msgWinAdrPL17).
 * msgWinPL17_20P 0x327d68 size 0x4: match (placed by msgWinAdrPL17).
 * msgWinPL17_21P 0x327d6c size 0x4: match (placed by msgWinAdrPL17).
 * msgWinPL17_22P 0x327d70 size 0x4: match (placed by msgWinAdrPL17).
 * msgWinPL17_23P 0x327d74 size 0x4: match (placed by msgWinAdrPL17).
 * msgWinPL17_24P 0x327d78 size 0x4: match (placed by msgWinAdrPL17).
 * msgWinPL17_25P 0x327d7c size 0x4: match (placed by msgWinAdrPL17).
 * msgWinPL17_26P 0x327d80 size 0x4: match (placed by msgWinAdrPL17).
 * msgWinPL17_27P 0x327d84 size 0x4: match (placed by msgWinAdrPL17).
 * pl17win_usa_tbl 0x327e14 size 0x8: match (placed by pl_mes_tbl).
 */

#include "structs.h"
#include <stddef.h>

/* from sf33rd/Source/Game/Message3rd/C_USA/PL17Win_usa.h */
extern MessageTable pl17win_usa_tbl;

static s8* msgWinPL17_00P[1] = { "" };
static s8* msgWinPL17_01P[1] = { "" };
static s8* msgWinPL17_02P[1] = { "" };
static s8* msgWinPL17_03P[1] = { "" };
static s8* msgWinPL17_04P[1] = { "" };
static s8* msgWinPL17_05P[1] = { "" };
static s8* msgWinPL17_06P[1] = { "" };
static s8* msgWinPL17_07P[1] = { "" };
static s8* msgWinPL17_08P[1] = { "" };
static s8* msgWinPL17_09P[1] = { "" };
static s8* msgWinPL17_10P[1] = { "" };
static s8* msgWinPL17_11P[1] = { "" };
static s8* msgWinPL17_12P[1] = { "" };
static s8* msgWinPL17_13P[1] = { "" };
static s8* msgWinPL17_14P[1] = { "" };
static s8* msgWinPL17_15P[1] = { "" };
static s8* msgWinPL17_16P[1] = { "" };
static s8* msgWinPL17_17P[1] = { "" };
static s8* msgWinPL17_18P[1] = { "" };
static s8* msgWinPL17_19P[1] = { "" };
static s8* msgWinPL17_20P[1] = { "" };
static s8* msgWinPL17_21P[1] = { "" };
static s8* msgWinPL17_22P[1] = { "" };
static s8* msgWinPL17_23P[1] = { "" };
static s8* msgWinPL17_24P[1] = { "" };
static s8* msgWinPL17_25P[1] = { "" };
static s8* msgWinPL17_26P[1] = { "" };
static s8* msgWinPL17_27P[1] = { "" };

static s8** msgWinAdrPL17[28] = {
    msgWinPL17_00P, msgWinPL17_01P, msgWinPL17_02P, msgWinPL17_03P, msgWinPL17_04P, msgWinPL17_05P, msgWinPL17_06P,
    msgWinPL17_07P, msgWinPL17_08P, msgWinPL17_09P, msgWinPL17_10P, msgWinPL17_11P, msgWinPL17_12P, msgWinPL17_13P,
    msgWinPL17_14P, msgWinPL17_15P, msgWinPL17_16P, msgWinPL17_17P, msgWinPL17_18P, msgWinPL17_19P, msgWinPL17_20P,
    msgWinPL17_21P, msgWinPL17_22P, msgWinPL17_23P, msgWinPL17_24P, msgWinPL17_25P, msgWinPL17_26P, msgWinPL17_27P,
};

static s8 msgWinCtrPL17[28] = {
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
};

MessageTable pl17win_usa_tbl = { msgWinAdrPL17, msgWinCtrPL17 };
