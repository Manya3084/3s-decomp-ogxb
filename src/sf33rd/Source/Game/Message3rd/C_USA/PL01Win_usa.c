/* PL01Win_usa.c, retail sf33rd.xbe.
 * The PS2 file's data (ps2.path), checked by analysis-ps2map/portdata.py
 * against the XBE: each table at its data.txt address, or at the
 * address a checked table's pointer to it holds ("placed by").
 * msgWinAdrPL01 0x325b10 size 0x70: match (placed by pl01win_usa_tbl).
 * msgWinCtrPL01 0x325b80 size 0x1c: match (placed by pl01win_usa_tbl).
 * msgWinPL01_00P 0x325a80 size 0x4: match (placed by msgWinAdrPL01).
 * msgWinPL01_01P 0x325a84 size 0x4: match (placed by msgWinAdrPL01).
 * msgWinPL01_02P 0x325a88 size 0x4: match (placed by msgWinAdrPL01).
 * msgWinPL01_03P 0x325a8c size 0x4: match (placed by msgWinAdrPL01).
 * msgWinPL01_04P 0x325a90 size 0x4: match (placed by msgWinAdrPL01).
 * msgWinPL01_05P 0x325a94 size 0x4: match (placed by msgWinAdrPL01).
 * msgWinPL01_06P 0x325a98 size 0x4: match (placed by msgWinAdrPL01).
 * msgWinPL01_07P 0x325a9c size 0x4: match (placed by msgWinAdrPL01).
 * msgWinPL01_08P 0x325aa0 size 0x4: match (placed by msgWinAdrPL01).
 * msgWinPL01_09P 0x325aa4 size 0x4: match (placed by msgWinAdrPL01).
 * msgWinPL01_10P 0x325aa8 size 0x4: match (placed by msgWinAdrPL01).
 * msgWinPL01_11P 0x325aac size 0x4: match (placed by msgWinAdrPL01).
 * msgWinPL01_12P 0x325ab0 size 0x4: match (placed by msgWinAdrPL01).
 * msgWinPL01_13P 0x325ab4 size 0x4: match (placed by msgWinAdrPL01).
 * msgWinPL01_14P 0x325ab8 size 0x4: match (placed by msgWinAdrPL01).
 * msgWinPL01_15P 0x325abc size 0x4: match (placed by msgWinAdrPL01).
 * msgWinPL01_16P 0x325ac0 size 0x4: match (placed by msgWinAdrPL01).
 * msgWinPL01_17P 0x325ac4 size 0x4: match (placed by msgWinAdrPL01).
 * msgWinPL01_18P 0x325ac8 size 0x4: match (placed by msgWinAdrPL01).
 * msgWinPL01_19P 0x325acc size 0x4: match (placed by msgWinAdrPL01).
 * msgWinPL01_20P 0x325ad0 size 0x8: match (placed by msgWinAdrPL01).
 * msgWinPL01_21P 0x325ad8 size 0x8: match (placed by msgWinAdrPL01).
 * msgWinPL01_22P 0x325ae0 size 0x8: match (placed by msgWinAdrPL01).
 * msgWinPL01_23P 0x325ae8 size 0x8: match (placed by msgWinAdrPL01).
 * msgWinPL01_24P 0x325af0 size 0x8: match (placed by msgWinAdrPL01).
 * msgWinPL01_25P 0x325af8 size 0x8: match (placed by msgWinAdrPL01).
 * msgWinPL01_26P 0x325b00 size 0x8: match (placed by msgWinAdrPL01).
 * msgWinPL01_27P 0x325b08 size 0x8: match (placed by msgWinAdrPL01).
 * pl01win_usa_tbl 0x325b9c size 0x8: match (placed by pl_mes_tbl).
 */

#include "structs.h"
#include <stddef.h>

/* from sf33rd/Source/Game/Message3rd/C_USA/PL01Win_usa.h */
extern MessageTable pl01win_usa_tbl;

static s8* msgWinPL01_00P[1] = { "" };
static s8* msgWinPL01_01P[1] = { "" };
static s8* msgWinPL01_02P[1] = { "" };
static s8* msgWinPL01_03P[1] = { "" };
static s8* msgWinPL01_04P[1] = { "" };
static s8* msgWinPL01_05P[1] = { "" };
static s8* msgWinPL01_06P[1] = { "" };
static s8* msgWinPL01_07P[1] = { "" };
static s8* msgWinPL01_08P[1] = { "" };
static s8* msgWinPL01_09P[1] = { "" };
static s8* msgWinPL01_10P[1] = { "" };
static s8* msgWinPL01_11P[1] = { "" };
static s8* msgWinPL01_12P[1] = { "" };
static s8* msgWinPL01_13P[1] = { "" };
static s8* msgWinPL01_14P[1] = { "" };
static s8* msgWinPL01_15P[1] = { "" };
static s8* msgWinPL01_16P[1] = { "" };
static s8* msgWinPL01_17P[1] = { "" };
static s8* msgWinPL01_18P[1] = { "" };
static s8* msgWinPL01_19P[1] = { "" };
static s8* msgWinPL01_20P[2] = {
    "   Defeat will help you                         ",
    "   to solve your ego problem.                   ",
};
static s8* msgWinPL01_21P[2] = {
    "   Be a master of your mind before              ",
    "   attempting to master your body!              ",
};
static s8* msgWinPL01_22P[2] = {
    "   Don't waste my time.                         ",
    "   I can learn nothing from you.                ",
};
static s8* msgWinPL01_23P[2] = {
    "   Study your opponents and exploit             ",
    "   their weaknesses. That is the key...         ",
};
static s8* msgWinPL01_24P[2] = {
    "   Use your head, or I will!                    ",
    "   I need a new bowling ball...                 ",
};
static s8* msgWinPL01_25P[2] = {
    "   You don't have to be big,                    ",
    "   to look like a big loser.                    ",
};
static s8* msgWinPL01_26P[2] = {
    "   You can't escape! Real fighters              ",
    "   know their true calling!                     ",
};
static s8* msgWinPL01_27P[2] = {
    "   A lack of spirit will                        ",
    "   always lead to defeat!                       ",
};

static s8** msgWinAdrPL01[28] = {
    msgWinPL01_00P, msgWinPL01_01P, msgWinPL01_02P, msgWinPL01_03P, msgWinPL01_04P, msgWinPL01_05P, msgWinPL01_06P,
    msgWinPL01_07P, msgWinPL01_08P, msgWinPL01_09P, msgWinPL01_10P, msgWinPL01_11P, msgWinPL01_12P, msgWinPL01_13P,
    msgWinPL01_14P, msgWinPL01_15P, msgWinPL01_16P, msgWinPL01_17P, msgWinPL01_18P, msgWinPL01_19P, msgWinPL01_20P,
    msgWinPL01_21P, msgWinPL01_22P, msgWinPL01_23P, msgWinPL01_24P, msgWinPL01_25P, msgWinPL01_26P, msgWinPL01_27P,
};

static s8 msgWinCtrPL01[28] = {
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2,
};

MessageTable pl01win_usa_tbl = { msgWinAdrPL01, msgWinCtrPL01 };
