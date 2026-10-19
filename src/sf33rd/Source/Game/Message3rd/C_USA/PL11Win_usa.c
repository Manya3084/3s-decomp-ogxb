/* PL11Win_usa.c, retail sf33rd.xbe.
 * The PS2 file's data (ps2.path), checked by analysis-ps2map/portdata.py
 * against the XBE: each table at its data.txt address, or at the
 * address a checked table's pointer to it holds ("placed by").
 * msgWinAdrPL11 0x327110 size 0x70: match (placed by pl11win_usa_tbl).
 * msgWinCtrPL11 0x327180 size 0x1c: match (placed by pl11win_usa_tbl).
 * msgWinPL11_00P 0x327080 size 0x4: match (placed by msgWinAdrPL11).
 * msgWinPL11_01P 0x327084 size 0x4: match (placed by msgWinAdrPL11).
 * msgWinPL11_02P 0x327088 size 0x4: match (placed by msgWinAdrPL11).
 * msgWinPL11_03P 0x32708c size 0x4: match (placed by msgWinAdrPL11).
 * msgWinPL11_04P 0x327090 size 0x4: match (placed by msgWinAdrPL11).
 * msgWinPL11_05P 0x327094 size 0x4: match (placed by msgWinAdrPL11).
 * msgWinPL11_06P 0x327098 size 0x4: match (placed by msgWinAdrPL11).
 * msgWinPL11_07P 0x32709c size 0x4: match (placed by msgWinAdrPL11).
 * msgWinPL11_08P 0x3270a0 size 0x4: match (placed by msgWinAdrPL11).
 * msgWinPL11_09P 0x3270a4 size 0x4: match (placed by msgWinAdrPL11).
 * msgWinPL11_10P 0x3270a8 size 0x4: match (placed by msgWinAdrPL11).
 * msgWinPL11_11P 0x3270ac size 0x4: match (placed by msgWinAdrPL11).
 * msgWinPL11_12P 0x3270b0 size 0x4: match (placed by msgWinAdrPL11).
 * msgWinPL11_13P 0x3270b4 size 0x4: match (placed by msgWinAdrPL11).
 * msgWinPL11_14P 0x3270b8 size 0x4: match (placed by msgWinAdrPL11).
 * msgWinPL11_15P 0x3270bc size 0x4: match (placed by msgWinAdrPL11).
 * msgWinPL11_16P 0x3270c0 size 0x4: match (placed by msgWinAdrPL11).
 * msgWinPL11_17P 0x3270c4 size 0x4: match (placed by msgWinAdrPL11).
 * msgWinPL11_18P 0x3270c8 size 0x4: match (placed by msgWinAdrPL11).
 * msgWinPL11_19P 0x3270cc size 0x4: match (placed by msgWinAdrPL11).
 * msgWinPL11_20P 0x3270d0 size 0x8: match (placed by msgWinAdrPL11).
 * msgWinPL11_21P 0x3270d8 size 0x8: match (placed by msgWinAdrPL11).
 * msgWinPL11_22P 0x3270e0 size 0x4: match (placed by msgWinAdrPL11).
 * msgWinPL11_23P 0x3270e4 size 0x8: match (placed by msgWinAdrPL11).
 * msgWinPL11_24P 0x3270ec size 0x8: match (placed by msgWinAdrPL11).
 * msgWinPL11_25P 0x3270f4 size 0x8: match (placed by msgWinAdrPL11).
 * msgWinPL11_26P 0x3270fc size 0x8: match (placed by msgWinAdrPL11).
 * msgWinPL11_27P 0x327104 size 0x8: match (placed by msgWinAdrPL11).
 * pl11win_usa_tbl 0x32719c size 0x8: match (placed by pl_mes_tbl).
 */

#include "structs.h"
#include <stddef.h>

/* from sf33rd/Source/Game/Message3rd/C_USA/PL11Win_usa.h */
extern MessageTable pl11win_usa_tbl;

static s8* msgWinPL11_00P[1] = { "" };
static s8* msgWinPL11_01P[1] = { "" };
static s8* msgWinPL11_02P[1] = { "" };
static s8* msgWinPL11_03P[1] = { "" };
static s8* msgWinPL11_04P[1] = { "" };
static s8* msgWinPL11_05P[1] = { "" };
static s8* msgWinPL11_06P[1] = { "" };
static s8* msgWinPL11_07P[1] = { "" };
static s8* msgWinPL11_08P[1] = { "" };
static s8* msgWinPL11_09P[1] = { "" };
static s8* msgWinPL11_10P[1] = { "" };
static s8* msgWinPL11_11P[1] = { "" };
static s8* msgWinPL11_12P[1] = { "" };
static s8* msgWinPL11_13P[1] = { "" };
static s8* msgWinPL11_14P[1] = { "" };
static s8* msgWinPL11_15P[1] = { "" };
static s8* msgWinPL11_16P[1] = { "" };
static s8* msgWinPL11_17P[1] = { "" };
static s8* msgWinPL11_18P[1] = { "" };
static s8* msgWinPL11_19P[1] = { "" };
static s8* msgWinPL11_20P[2] = {
    "   Whether you are reckless or brave,           ",
    "   use the style that suits you best!           ",
};
static s8* msgWinPL11_21P[2] = {
    "   Look forward to the battle! Live             ",
    "   for the excitement of the fight!             ",
};
static s8* msgWinPL11_22P[1] = { "   I wish you good luck!                        " };
static s8* msgWinPL11_23P[2] = {
    "   That's the spirit! Fight fiercely            ",
    "   every moment of the battle!                  ",
};
static s8* msgWinPL11_24P[2] = {
    "   I will fight with style and finesse,         ",
    "   no matter what the outcome may be!           ",
};
static s8* msgWinPL11_25P[2] = {
    "   Maybe my kid should practice                 ",
    "   sparring with you!                           ",
};
static s8* msgWinPL11_26P[2] = {
    "   Thanks for helping me to show Mel            ",
    "   who has the world's strongest fists!         ",
};
static s8* msgWinPL11_27P[2] = {
    "   Hey, they might make an action               ",
    "   figure out of you too, someday!              ",
};

static s8** msgWinAdrPL11[28] = {
    msgWinPL11_00P, msgWinPL11_01P, msgWinPL11_02P, msgWinPL11_03P, msgWinPL11_04P, msgWinPL11_05P, msgWinPL11_06P,
    msgWinPL11_07P, msgWinPL11_08P, msgWinPL11_09P, msgWinPL11_10P, msgWinPL11_11P, msgWinPL11_12P, msgWinPL11_13P,
    msgWinPL11_14P, msgWinPL11_15P, msgWinPL11_16P, msgWinPL11_17P, msgWinPL11_18P, msgWinPL11_19P, msgWinPL11_20P,
    msgWinPL11_21P, msgWinPL11_22P, msgWinPL11_23P, msgWinPL11_24P, msgWinPL11_25P, msgWinPL11_26P, msgWinPL11_27P,
};

static s8 msgWinCtrPL11[28] = {
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 1, 2, 2, 2, 2, 2,
};

MessageTable pl11win_usa_tbl = { msgWinAdrPL11, msgWinCtrPL11 };
