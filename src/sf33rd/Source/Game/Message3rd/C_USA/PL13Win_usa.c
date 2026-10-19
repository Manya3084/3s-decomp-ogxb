/* PL13Win_usa.c, retail sf33rd.xbe.
 * The PS2 file's data (ps2.path), checked by analysis-ps2map/portdata.py
 * against the XBE: each table at its data.txt address, or at the
 * address a checked table's pointer to it holds ("placed by").
 * msgWinAdrPL13 0x327558 size 0x70: match (placed by pl13win_usa_tbl).
 * msgWinCtrPL13 0x3275c8 size 0x1c: match (placed by pl13win_usa_tbl).
 * msgWinPL13_00P 0x3274c8 size 0x4: match (placed by msgWinAdrPL13).
 * msgWinPL13_01P 0x3274cc size 0x4: match (placed by msgWinAdrPL13).
 * msgWinPL13_02P 0x3274d0 size 0x4: match (placed by msgWinAdrPL13).
 * msgWinPL13_03P 0x3274d4 size 0x4: match (placed by msgWinAdrPL13).
 * msgWinPL13_04P 0x3274d8 size 0x4: match (placed by msgWinAdrPL13).
 * msgWinPL13_05P 0x3274dc size 0x4: match (placed by msgWinAdrPL13).
 * msgWinPL13_06P 0x3274e0 size 0x4: match (placed by msgWinAdrPL13).
 * msgWinPL13_07P 0x3274e4 size 0x4: match (placed by msgWinAdrPL13).
 * msgWinPL13_08P 0x3274e8 size 0x4: match (placed by msgWinAdrPL13).
 * msgWinPL13_09P 0x3274ec size 0x4: match (placed by msgWinAdrPL13).
 * msgWinPL13_10P 0x3274f0 size 0x4: match (placed by msgWinAdrPL13).
 * msgWinPL13_11P 0x3274f4 size 0x4: match (placed by msgWinAdrPL13).
 * msgWinPL13_12P 0x3274f8 size 0x4: match (placed by msgWinAdrPL13).
 * msgWinPL13_13P 0x3274fc size 0x4: match (placed by msgWinAdrPL13).
 * msgWinPL13_14P 0x327500 size 0x4: match (placed by msgWinAdrPL13).
 * msgWinPL13_15P 0x327504 size 0x4: match (placed by msgWinAdrPL13).
 * msgWinPL13_16P 0x327508 size 0x4: match (placed by msgWinAdrPL13).
 * msgWinPL13_17P 0x32750c size 0x4: match (placed by msgWinAdrPL13).
 * msgWinPL13_18P 0x327510 size 0x4: match (placed by msgWinAdrPL13).
 * msgWinPL13_19P 0x327514 size 0x4: match (placed by msgWinAdrPL13).
 * msgWinPL13_20P 0x327518 size 0x8: match (placed by msgWinAdrPL13).
 * msgWinPL13_21P 0x327520 size 0x8: match (placed by msgWinAdrPL13).
 * msgWinPL13_22P 0x327528 size 0x8: match (placed by msgWinAdrPL13).
 * msgWinPL13_23P 0x327530 size 0x8: match (placed by msgWinAdrPL13).
 * msgWinPL13_24P 0x327538 size 0x8: match (placed by msgWinAdrPL13).
 * msgWinPL13_25P 0x327540 size 0x8: match (placed by msgWinAdrPL13).
 * msgWinPL13_26P 0x327548 size 0x8: match (placed by msgWinAdrPL13).
 * msgWinPL13_27P 0x327550 size 0x8: match (placed by msgWinAdrPL13).
 * pl13win_usa_tbl 0x3275e4 size 0x8: match (placed by pl_mes_tbl).
 */

#include "structs.h"
#include <stddef.h>

/* from sf33rd/Source/Game/Message3rd/C_USA/PL13Win_usa.h */
extern MessageTable pl13win_usa_tbl;

static s8* msgWinPL13_00P[1] = { "" };
static s8* msgWinPL13_01P[1] = { "" };
static s8* msgWinPL13_02P[1] = { "" };
static s8* msgWinPL13_03P[1] = { "" };
static s8* msgWinPL13_04P[1] = { "" };
static s8* msgWinPL13_05P[1] = { "" };
static s8* msgWinPL13_06P[1] = { "" };
static s8* msgWinPL13_07P[1] = { "" };
static s8* msgWinPL13_08P[1] = { "" };
static s8* msgWinPL13_09P[1] = { "" };
static s8* msgWinPL13_10P[1] = { "" };
static s8* msgWinPL13_11P[1] = { "" };
static s8* msgWinPL13_12P[1] = { "" };
static s8* msgWinPL13_13P[1] = { "" };
static s8* msgWinPL13_14P[1] = { "" };
static s8* msgWinPL13_15P[1] = { "" };
static s8* msgWinPL13_16P[1] = { "" };
static s8* msgWinPL13_17P[1] = { "" };
static s8* msgWinPL13_18P[1] = { "" };
static s8* msgWinPL13_19P[1] = { "" };
static s8* msgWinPL13_20P[2] = {
    "   How dost thou suck? Let me                   ",
    "   count thy wounds! 1, 2, 3...                 ",
};
static s8* msgWinPL13_21P[2] = {
    "   Look! Your cells have                        ",
    "   betrayed you to serve me!                    ",
};
static s8* msgWinPL13_22P[2] = {
    "   That's right... Kneel before me!             ",
    "   How do you like the view now?!               ",
};
static s8* msgWinPL13_23P[2] = {
    "   Lie there as long as you want.               ",
    "   I've had my fun with you.                    ",
};
static s8* msgWinPL13_24P[2] = {
    "   You are not even worthy enough               ",
    "   to do my bidding! Be gone!                   ",
};
static s8* msgWinPL13_25P[2] = {
    "   Pounding on you is satisfying,               ",
    "   but I need something more...                 ",
};
static s8* msgWinPL13_26P[2] = {
    "   Your inferior vital fluids are               ",
    "   tainting the ground! Clean it up!            ",
};
static s8* msgWinPL13_27P[2] = {
    "   How can you refuse to bow                    ",
    "   to a superior being?                         ",
};

static s8** msgWinAdrPL13[28] = {
    msgWinPL13_00P, msgWinPL13_01P, msgWinPL13_02P, msgWinPL13_03P, msgWinPL13_04P, msgWinPL13_05P, msgWinPL13_06P,
    msgWinPL13_07P, msgWinPL13_08P, msgWinPL13_09P, msgWinPL13_10P, msgWinPL13_11P, msgWinPL13_12P, msgWinPL13_13P,
    msgWinPL13_14P, msgWinPL13_15P, msgWinPL13_16P, msgWinPL13_17P, msgWinPL13_18P, msgWinPL13_19P, msgWinPL13_20P,
    msgWinPL13_21P, msgWinPL13_22P, msgWinPL13_23P, msgWinPL13_24P, msgWinPL13_25P, msgWinPL13_26P, msgWinPL13_27P,
};

static s8 msgWinCtrPL13[28] = {
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2,
};

MessageTable pl13win_usa_tbl = { msgWinAdrPL13, msgWinCtrPL13 };
