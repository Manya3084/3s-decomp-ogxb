/* PL14Win_usa.c, retail sf33rd.xbe.
 * The PS2 file's data (ps2.path), checked by analysis-ps2map/portdata.py
 * against the XBE: each table at its data.txt address, or at the
 * address a checked table's pointer to it holds ("placed by").
 * msgWinAdrPL14 0x3276f8 size 0x70: match (placed by pl14win_usa_tbl).
 * msgWinCtrPL14 0x327768 size 0x1c: match (placed by pl14win_usa_tbl).
 * msgWinPL14_00P 0x327670 size 0x4: match (placed by msgWinAdrPL14).
 * msgWinPL14_01P 0x327674 size 0x4: match (placed by msgWinAdrPL14).
 * msgWinPL14_02P 0x327678 size 0x4: match (placed by msgWinAdrPL14).
 * msgWinPL14_03P 0x32767c size 0x4: match (placed by msgWinAdrPL14).
 * msgWinPL14_04P 0x327680 size 0x4: match (placed by msgWinAdrPL14).
 * msgWinPL14_05P 0x327684 size 0x4: match (placed by msgWinAdrPL14).
 * msgWinPL14_06P 0x327688 size 0x4: match (placed by msgWinAdrPL14).
 * msgWinPL14_07P 0x32768c size 0x4: match (placed by msgWinAdrPL14).
 * msgWinPL14_08P 0x327690 size 0x4: match (placed by msgWinAdrPL14).
 * msgWinPL14_09P 0x327694 size 0x4: match (placed by msgWinAdrPL14).
 * msgWinPL14_10P 0x327698 size 0x4: match (placed by msgWinAdrPL14).
 * msgWinPL14_11P 0x32769c size 0x4: match (placed by msgWinAdrPL14).
 * msgWinPL14_12P 0x3276a0 size 0x4: match (placed by msgWinAdrPL14).
 * msgWinPL14_13P 0x3276a4 size 0x4: match (placed by msgWinAdrPL14).
 * msgWinPL14_14P 0x3276a8 size 0x4: match (placed by msgWinAdrPL14).
 * msgWinPL14_15P 0x3276ac size 0x4: match (placed by msgWinAdrPL14).
 * msgWinPL14_16P 0x3276b0 size 0x4: match (placed by msgWinAdrPL14).
 * msgWinPL14_17P 0x3276b4 size 0x4: match (placed by msgWinAdrPL14).
 * msgWinPL14_18P 0x3276b8 size 0x4: match (placed by msgWinAdrPL14).
 * msgWinPL14_19P 0x3276bc size 0x4: match (placed by msgWinAdrPL14).
 * msgWinPL14_20P 0x3276c0 size 0x4: match (placed by msgWinAdrPL14).
 * msgWinPL14_21P 0x3276c4 size 0x4: match (placed by msgWinAdrPL14).
 * msgWinPL14_22P 0x3276c8 size 0x8: match (placed by msgWinAdrPL14).
 * msgWinPL14_23P 0x3276d0 size 0x8: match (placed by msgWinAdrPL14).
 * msgWinPL14_24P 0x3276d8 size 0x8: match (placed by msgWinAdrPL14).
 * msgWinPL14_25P 0x3276e0 size 0x8: match (placed by msgWinAdrPL14).
 * msgWinPL14_26P 0x3276e8 size 0x8: match (placed by msgWinAdrPL14).
 * msgWinPL14_27P 0x3276f0 size 0x8: match (placed by msgWinAdrPL14).
 * pl14win_usa_tbl 0x327784 size 0x8: match (placed by pl_mes_tbl).
 */

#include "structs.h"
#include <stddef.h>

/* from sf33rd/Source/Game/Message3rd/C_USA/PL14Win_usa.h */
extern MessageTable pl14win_usa_tbl;

static s8* msgWinPL14_00P[1] = { "" };
static s8* msgWinPL14_01P[1] = { "" };
static s8* msgWinPL14_02P[1] = { "" };
static s8* msgWinPL14_03P[1] = { "" };
static s8* msgWinPL14_04P[1] = { "" };
static s8* msgWinPL14_05P[1] = { "" };
static s8* msgWinPL14_06P[1] = { "" };
static s8* msgWinPL14_07P[1] = { "" };
static s8* msgWinPL14_08P[1] = { "" };
static s8* msgWinPL14_09P[1] = { "" };
static s8* msgWinPL14_10P[1] = { "" };
static s8* msgWinPL14_11P[1] = { "" };
static s8* msgWinPL14_12P[1] = { "" };
static s8* msgWinPL14_13P[1] = { "" };
static s8* msgWinPL14_14P[1] = { "" };
static s8* msgWinPL14_15P[1] = { "" };
static s8* msgWinPL14_16P[1] = { "" };
static s8* msgWinPL14_17P[1] = { "" };
static s8* msgWinPL14_18P[1] = { "" };
static s8* msgWinPL14_19P[1] = { "" };
static s8* msgWinPL14_20P[1] = { "   My fist knows no equal!                      " };
static s8* msgWinPL14_21P[1] = { "   Perfection equals obliteration!              " };
static s8* msgWinPL14_22P[2] = {
    "   Your body assumed its proper form            ",
    "   when my fists tore it apart!                 ",
};
static s8* msgWinPL14_23P[2] = {
    "   Weakness is a disease...                     ",
    "   I am the cure!                               ",
};
static s8* msgWinPL14_24P[2] = {
    "   The unworthy must be                         ",
    "   removed from existence.                      ",
};
static s8* msgWinPL14_25P[2] = {
    "   You've fulfilled your purpose in             ",
    "   life by allowing me to end it!               ",
};
static s8* msgWinPL14_26P[2] = {
    "   A weak shell for a weak soul. It was         ",
    "   an easy task to separate the two...          ",
};
static s8* msgWinPL14_27P[2] = {
    "   To show mercy is to show                     ",
    "   proof of your imperfections!                 ",
};

static s8** msgWinAdrPL14[28] = {
    msgWinPL14_00P, msgWinPL14_01P, msgWinPL14_02P, msgWinPL14_03P, msgWinPL14_04P, msgWinPL14_05P, msgWinPL14_06P,
    msgWinPL14_07P, msgWinPL14_08P, msgWinPL14_09P, msgWinPL14_10P, msgWinPL14_11P, msgWinPL14_12P, msgWinPL14_13P,
    msgWinPL14_14P, msgWinPL14_15P, msgWinPL14_16P, msgWinPL14_17P, msgWinPL14_18P, msgWinPL14_19P, msgWinPL14_20P,
    msgWinPL14_21P, msgWinPL14_22P, msgWinPL14_23P, msgWinPL14_24P, msgWinPL14_25P, msgWinPL14_26P, msgWinPL14_27P,
};

static s8 msgWinCtrPL14[28] = {
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2,
};

MessageTable pl14win_usa_tbl = { msgWinAdrPL14, msgWinCtrPL14 };
