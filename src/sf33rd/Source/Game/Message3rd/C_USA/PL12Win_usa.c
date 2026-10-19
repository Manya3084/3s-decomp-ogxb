/* PL12Win_usa.c, retail sf33rd.xbe.
 * The PS2 file's data (ps2.path), checked by analysis-ps2map/portdata.py
 * against the XBE: each table at its data.txt address, or at the
 * address a checked table's pointer to it holds ("placed by").
 * msgWinAdrPL12 0x327330 size 0x70: match (placed by pl12win_usa_tbl).
 * msgWinCtrPL12 0x3273a0 size 0x1c: match (placed by pl12win_usa_tbl).
 * msgWinPL12_00P 0x3272a0 size 0x4: match (placed by msgWinAdrPL12).
 * msgWinPL12_01P 0x3272a4 size 0x4: match (placed by msgWinAdrPL12).
 * msgWinPL12_02P 0x3272a8 size 0x4: match (placed by msgWinAdrPL12).
 * msgWinPL12_03P 0x3272ac size 0x4: match (placed by msgWinAdrPL12).
 * msgWinPL12_04P 0x3272b0 size 0x4: match (placed by msgWinAdrPL12).
 * msgWinPL12_05P 0x3272b4 size 0x4: match (placed by msgWinAdrPL12).
 * msgWinPL12_06P 0x3272b8 size 0x4: match (placed by msgWinAdrPL12).
 * msgWinPL12_07P 0x3272bc size 0x4: match (placed by msgWinAdrPL12).
 * msgWinPL12_08P 0x3272c0 size 0x4: match (placed by msgWinAdrPL12).
 * msgWinPL12_09P 0x3272c4 size 0x4: match (placed by msgWinAdrPL12).
 * msgWinPL12_10P 0x3272c8 size 0x4: match (placed by msgWinAdrPL12).
 * msgWinPL12_11P 0x3272cc size 0x4: match (placed by msgWinAdrPL12).
 * msgWinPL12_12P 0x3272d0 size 0x4: match (placed by msgWinAdrPL12).
 * msgWinPL12_13P 0x3272d4 size 0x4: match (placed by msgWinAdrPL12).
 * msgWinPL12_14P 0x3272d8 size 0x4: match (placed by msgWinAdrPL12).
 * msgWinPL12_15P 0x3272dc size 0x4: match (placed by msgWinAdrPL12).
 * msgWinPL12_16P 0x3272e0 size 0x4: match (placed by msgWinAdrPL12).
 * msgWinPL12_17P 0x3272e4 size 0x4: match (placed by msgWinAdrPL12).
 * msgWinPL12_18P 0x3272e8 size 0x4: match (placed by msgWinAdrPL12).
 * msgWinPL12_19P 0x3272ec size 0x4: match (placed by msgWinAdrPL12).
 * msgWinPL12_20P 0x3272f0 size 0x8: match (placed by msgWinAdrPL12).
 * msgWinPL12_21P 0x3272f8 size 0x8: match (placed by msgWinAdrPL12).
 * msgWinPL12_22P 0x327300 size 0x8: match (placed by msgWinAdrPL12).
 * msgWinPL12_23P 0x327308 size 0x8: match (placed by msgWinAdrPL12).
 * msgWinPL12_24P 0x327310 size 0x8: match (placed by msgWinAdrPL12).
 * msgWinPL12_25P 0x327318 size 0x8: match (placed by msgWinAdrPL12).
 * msgWinPL12_26P 0x327320 size 0x8: match (placed by msgWinAdrPL12).
 * msgWinPL12_27P 0x327328 size 0x8: match (placed by msgWinAdrPL12).
 * pl12win_usa_tbl 0x3273bc size 0x8: match (placed by pl_mes_tbl).
 */

#include "structs.h"
#include <stddef.h>

/* from sf33rd/Source/Game/Message3rd/C_USA/PL12Win_usa.h */
extern MessageTable pl12win_usa_tbl;

static s8* msgWinPL12_00P[1] = { "" };
static s8* msgWinPL12_01P[1] = { "" };
static s8* msgWinPL12_02P[1] = { "" };
static s8* msgWinPL12_03P[1] = { "" };
static s8* msgWinPL12_04P[1] = { "" };
static s8* msgWinPL12_05P[1] = { "" };
static s8* msgWinPL12_06P[1] = { "" };
static s8* msgWinPL12_07P[1] = { "" };
static s8* msgWinPL12_08P[1] = { "" };
static s8* msgWinPL12_09P[1] = { "" };
static s8* msgWinPL12_10P[1] = { "" };
static s8* msgWinPL12_11P[1] = { "" };
static s8* msgWinPL12_12P[1] = { "" };
static s8* msgWinPL12_13P[1] = { "" };
static s8* msgWinPL12_14P[1] = { "" };
static s8* msgWinPL12_15P[1] = { "" };
static s8* msgWinPL12_16P[1] = { "" };
static s8* msgWinPL12_17P[1] = { "" };
static s8* msgWinPL12_18P[1] = { "" };
static s8* msgWinPL12_19P[1] = { "" };
static s8* msgWinPL12_20P[2] = {
    "   Wow! That actually worked?!                  ",
    "   Next time I'll do it with skill!             ",
};
static s8* msgWinPL12_21P[2] = {
    "   I'm so eager to try out new and              ",
    "   different things! This is great!             ",
};
static s8* msgWinPL12_22P[2] = {
    "   Tell me who just rocked                      ",
    "   your world with skill!                       ",
};
static s8* msgWinPL12_23P[2] = {
    "   With every match, my timing                  ",
    "   becomes more precise!                        ",
};
static s8* msgWinPL12_24P[2] = {
    "   Oh yeah! I'll start using                    ",
    "   that move more often now!                    ",
};
static s8* msgWinPL12_25P[2] = {
    "   My master was right... I have to             ",
    "   improve myself with every battle!            ",
};
static s8* msgWinPL12_26P[2] = {
    "   Now I understand why they fight!             ",
    "   This feeling is incredible!                  ",
};
static s8* msgWinPL12_27P[2] = {
    "   Call the fire department,                    ",
    "   cause I'm on fire, baby!                     ",
};

static s8** msgWinAdrPL12[28] = {
    msgWinPL12_00P, msgWinPL12_01P, msgWinPL12_02P, msgWinPL12_03P, msgWinPL12_04P, msgWinPL12_05P, msgWinPL12_06P,
    msgWinPL12_07P, msgWinPL12_08P, msgWinPL12_09P, msgWinPL12_10P, msgWinPL12_11P, msgWinPL12_12P, msgWinPL12_13P,
    msgWinPL12_14P, msgWinPL12_15P, msgWinPL12_16P, msgWinPL12_17P, msgWinPL12_18P, msgWinPL12_19P, msgWinPL12_20P,
    msgWinPL12_21P, msgWinPL12_22P, msgWinPL12_23P, msgWinPL12_24P, msgWinPL12_25P, msgWinPL12_26P, msgWinPL12_27P,
};

static s8 msgWinCtrPL12[28] = {
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2,
};

MessageTable pl12win_usa_tbl = { msgWinAdrPL12, msgWinCtrPL12 };
