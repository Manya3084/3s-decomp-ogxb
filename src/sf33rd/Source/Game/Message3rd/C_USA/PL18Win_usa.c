/* PL18Win_usa.c, retail sf33rd.xbe.
 * The PS2 file's data (ps2.path), checked by analysis-ps2map/portdata.py
 * against the XBE: each table at its data.txt address, or at the
 * address a checked table's pointer to it holds ("placed by").
 * msgWinAdrPL18 0x327fc0 size 0x70: match (placed by pl18win_usa_tbl).
 * msgWinCtrPL18 0x328030 size 0x1c: match (placed by pl18win_usa_tbl).
 * msgWinPL18_00P 0x327f50 size 0x4: match (placed by msgWinAdrPL18).
 * msgWinPL18_01P 0x327f54 size 0x4: match (placed by msgWinAdrPL18).
 * msgWinPL18_02P 0x327f58 size 0x4: match (placed by msgWinAdrPL18).
 * msgWinPL18_03P 0x327f5c size 0x4: match (placed by msgWinAdrPL18).
 * msgWinPL18_04P 0x327f60 size 0x4: match (placed by msgWinAdrPL18).
 * msgWinPL18_05P 0x327f64 size 0x4: match (placed by msgWinAdrPL18).
 * msgWinPL18_06P 0x327f68 size 0x4: match (placed by msgWinAdrPL18).
 * msgWinPL18_07P 0x327f6c size 0x4: match (placed by msgWinAdrPL18).
 * msgWinPL18_08P 0x327f70 size 0x4: match (placed by msgWinAdrPL18).
 * msgWinPL18_09P 0x327f74 size 0x4: match (placed by msgWinAdrPL18).
 * msgWinPL18_10P 0x327f78 size 0x4: match (placed by msgWinAdrPL18).
 * msgWinPL18_11P 0x327f7c size 0x4: match (placed by msgWinAdrPL18).
 * msgWinPL18_12P 0x327f80 size 0x4: match (placed by msgWinAdrPL18).
 * msgWinPL18_13P 0x327f84 size 0x4: match (placed by msgWinAdrPL18).
 * msgWinPL18_14P 0x327f88 size 0x4: match (placed by msgWinAdrPL18).
 * msgWinPL18_15P 0x327f8c size 0x4: match (placed by msgWinAdrPL18).
 * msgWinPL18_16P 0x327f90 size 0x4: match (placed by msgWinAdrPL18).
 * msgWinPL18_17P 0x327f94 size 0x4: match (placed by msgWinAdrPL18).
 * msgWinPL18_18P 0x327f98 size 0x4: match (placed by msgWinAdrPL18).
 * msgWinPL18_19P 0x327f9c size 0x4: match (placed by msgWinAdrPL18).
 * msgWinPL18_20P 0x327fa0 size 0x4: match (placed by msgWinAdrPL18).
 * msgWinPL18_21P 0x327fa4 size 0x4: match (placed by msgWinAdrPL18).
 * msgWinPL18_22P 0x327fa8 size 0x4: match (placed by msgWinAdrPL18).
 * msgWinPL18_23P 0x327fac size 0x4: match (placed by msgWinAdrPL18).
 * msgWinPL18_24P 0x327fb0 size 0x4: match (placed by msgWinAdrPL18).
 * msgWinPL18_25P 0x327fb4 size 0x4: match (placed by msgWinAdrPL18).
 * msgWinPL18_26P 0x327fb8 size 0x4: match (placed by msgWinAdrPL18).
 * msgWinPL18_27P 0x327fbc size 0x4: match (placed by msgWinAdrPL18).
 * pl18win_usa_tbl 0x32804c size 0x8: match (placed by pl_mes_tbl).
 */

#include "structs.h"
#include <stddef.h>

/* from sf33rd/Source/Game/Message3rd/C_USA/PL18Win_usa.h */
extern MessageTable pl18win_usa_tbl;

static s8* msgWinPL18_00P[1] = { "" };
static s8* msgWinPL18_01P[1] = { "" };
static s8* msgWinPL18_02P[1] = { "" };
static s8* msgWinPL18_03P[1] = { "" };
static s8* msgWinPL18_04P[1] = { "" };
static s8* msgWinPL18_05P[1] = { "" };
static s8* msgWinPL18_06P[1] = { "" };
static s8* msgWinPL18_07P[1] = { "" };
static s8* msgWinPL18_08P[1] = { "" };
static s8* msgWinPL18_09P[1] = { "" };
static s8* msgWinPL18_10P[1] = { "" };
static s8* msgWinPL18_11P[1] = { "" };
static s8* msgWinPL18_12P[1] = { "" };
static s8* msgWinPL18_13P[1] = { "" };
static s8* msgWinPL18_14P[1] = { "" };
static s8* msgWinPL18_15P[1] = { "" };
static s8* msgWinPL18_16P[1] = { "" };
static s8* msgWinPL18_17P[1] = { "" };
static s8* msgWinPL18_18P[1] = { "" };
static s8* msgWinPL18_19P[1] = { "" };
static s8* msgWinPL18_20P[1] = { "   00100.00101.00001.10100.01000                " };
static s8* msgWinPL18_21P[1] = { "   01011.01001.01100.01100                      " };
static s8* msgWinPL18_22P[1] = { "   10000.00001.01001.01110                      " };
static s8* msgWinPL18_23P[1] = { "   00110.01001.01110.01001.10011.01000          " };
static s8* msgWinPL18_24P[1] = { "   01011.01111                                  " };
static s8* msgWinPL18_25P[1] = { "   10100.01000.00101.00101.01110.00100          " };
static s8* msgWinPL18_26P[1] = { "   10100.10111.00101.01100.10110.00101          " };
static s8* msgWinPL18_27P[1] = { "   00101.11010.01010.01111.00010                " };

static s8** msgWinAdrPL18[28] = {
    msgWinPL18_00P, msgWinPL18_01P, msgWinPL18_02P, msgWinPL18_03P, msgWinPL18_04P, msgWinPL18_05P, msgWinPL18_06P,
    msgWinPL18_07P, msgWinPL18_08P, msgWinPL18_09P, msgWinPL18_10P, msgWinPL18_11P, msgWinPL18_12P, msgWinPL18_13P,
    msgWinPL18_14P, msgWinPL18_15P, msgWinPL18_16P, msgWinPL18_17P, msgWinPL18_18P, msgWinPL18_19P, msgWinPL18_20P,
    msgWinPL18_21P, msgWinPL18_22P, msgWinPL18_23P, msgWinPL18_24P, msgWinPL18_25P, msgWinPL18_26P, msgWinPL18_27P,
};

static s8 msgWinCtrPL18[28] = {
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
};

MessageTable pl18win_usa_tbl = { msgWinAdrPL18, msgWinCtrPL18 };
