/* PL04Win_usa.c, retail sf33rd.xbe.
 * The PS2 file's data (ps2.path), checked by analysis-ps2map/portdata.py
 * against the XBE: each table at its data.txt address, or at the
 * address a checked table's pointer to it holds ("placed by").
 * msgWinAdrPL04 0x326188 size 0x70: match (placed by pl04win_usa_tbl).
 * msgWinCtrPL04 0x3261f8 size 0x1c: match (placed by pl04win_usa_tbl).
 * msgWinPL04_00P 0x3260f8 size 0x4: match (placed by msgWinAdrPL04).
 * msgWinPL04_01P 0x3260fc size 0x4: match (placed by msgWinAdrPL04).
 * msgWinPL04_02P 0x326100 size 0x4: match (placed by msgWinAdrPL04).
 * msgWinPL04_03P 0x326104 size 0x4: match (placed by msgWinAdrPL04).
 * msgWinPL04_04P 0x326108 size 0x4: match (placed by msgWinAdrPL04).
 * msgWinPL04_05P 0x32610c size 0x4: match (placed by msgWinAdrPL04).
 * msgWinPL04_06P 0x326110 size 0x4: match (placed by msgWinAdrPL04).
 * msgWinPL04_07P 0x326114 size 0x4: match (placed by msgWinAdrPL04).
 * msgWinPL04_08P 0x326118 size 0x4: match (placed by msgWinAdrPL04).
 * msgWinPL04_09P 0x32611c size 0x4: match (placed by msgWinAdrPL04).
 * msgWinPL04_10P 0x326120 size 0x4: match (placed by msgWinAdrPL04).
 * msgWinPL04_11P 0x326124 size 0x4: match (placed by msgWinAdrPL04).
 * msgWinPL04_12P 0x326128 size 0x4: match (placed by msgWinAdrPL04).
 * msgWinPL04_13P 0x32612c size 0x4: match (placed by msgWinAdrPL04).
 * msgWinPL04_14P 0x326130 size 0x4: match (placed by msgWinAdrPL04).
 * msgWinPL04_15P 0x326134 size 0x4: match (placed by msgWinAdrPL04).
 * msgWinPL04_16P 0x326138 size 0x4: match (placed by msgWinAdrPL04).
 * msgWinPL04_17P 0x32613c size 0x4: match (placed by msgWinAdrPL04).
 * msgWinPL04_18P 0x326140 size 0x4: match (placed by msgWinAdrPL04).
 * msgWinPL04_19P 0x326144 size 0x4: match (placed by msgWinAdrPL04).
 * msgWinPL04_20P 0x326148 size 0x8: match (placed by msgWinAdrPL04).
 * msgWinPL04_21P 0x326150 size 0x8: match (placed by msgWinAdrPL04).
 * msgWinPL04_22P 0x326158 size 0x8: match (placed by msgWinAdrPL04).
 * msgWinPL04_23P 0x326160 size 0x8: match (placed by msgWinAdrPL04).
 * msgWinPL04_24P 0x326168 size 0x8: match (placed by msgWinAdrPL04).
 * msgWinPL04_25P 0x326170 size 0x8: match (placed by msgWinAdrPL04).
 * msgWinPL04_26P 0x326178 size 0x8: match (placed by msgWinAdrPL04).
 * msgWinPL04_27P 0x326180 size 0x8: match (placed by msgWinAdrPL04).
 * pl04win_usa_tbl 0x326214 size 0x8: match (placed by pl_mes_tbl).
 */

#include "structs.h"
#include <stddef.h>

/* from sf33rd/Source/Game/Message3rd/C_USA/PL04Win_usa.h */
extern MessageTable pl04win_usa_tbl;

static s8* msgWinPL04_00P[1] = { "" };
static s8* msgWinPL04_01P[1] = { "" };
static s8* msgWinPL04_02P[1] = { "" };
static s8* msgWinPL04_03P[1] = { "" };
static s8* msgWinPL04_04P[1] = { "" };
static s8* msgWinPL04_05P[1] = { "" };
static s8* msgWinPL04_06P[1] = { "" };
static s8* msgWinPL04_07P[1] = { "" };
static s8* msgWinPL04_08P[1] = { "" };
static s8* msgWinPL04_09P[1] = { "" };
static s8* msgWinPL04_10P[1] = { "" };
static s8* msgWinPL04_11P[1] = { "" };
static s8* msgWinPL04_12P[1] = { "" };
static s8* msgWinPL04_13P[1] = { "" };
static s8* msgWinPL04_14P[1] = { "" };
static s8* msgWinPL04_15P[1] = { "" };
static s8* msgWinPL04_16P[1] = { "" };
static s8* msgWinPL04_17P[1] = { "" };
static s8* msgWinPL04_18P[1] = { "" };
static s8* msgWinPL04_19P[1] = { "" };
static s8* msgWinPL04_20P[2] = {
    "   Fight like a gentleman...                    ",
    "   Live like a gentleman!                       ",
};
static s8* msgWinPL04_21P[2] = {
    "   Not very articulated, are you?               ",
    "   Work on your movements, chap!                ",
};
static s8* msgWinPL04_22P[2] = {
    "   Learn to fight with class!                   ",
    "   Self-respect breeds discipline!              ",
};
static s8* msgWinPL04_23P[2] = {
    "   Even a spectator needs to be sharp           ",
    "   to comprehend the grace of boxing!           ",
};
static s8* msgWinPL04_24P[2] = {
    "   A champion does not achieve                  ",
    "   victory when fueled by anger.                ",
};
static s8* msgWinPL04_25P[2] = {
    "   A punching bag that can bleed                ",
    "   is not a suitable rival for me.              ",
};
static s8* msgWinPL04_26P[2] = {
    "   To win with prestige and glory               ",
    "   is a sensation like no other!                ",
};
static s8* msgWinPL04_27P[2] = {
    "   Despite your manners, I like your            ",
    "   style. Let me buy you a drink...             ",
};

static s8** msgWinAdrPL04[28] = {
    msgWinPL04_00P, msgWinPL04_01P, msgWinPL04_02P, msgWinPL04_03P, msgWinPL04_04P, msgWinPL04_05P, msgWinPL04_06P,
    msgWinPL04_07P, msgWinPL04_08P, msgWinPL04_09P, msgWinPL04_10P, msgWinPL04_11P, msgWinPL04_12P, msgWinPL04_13P,
    msgWinPL04_14P, msgWinPL04_15P, msgWinPL04_16P, msgWinPL04_17P, msgWinPL04_18P, msgWinPL04_19P, msgWinPL04_20P,
    msgWinPL04_21P, msgWinPL04_22P, msgWinPL04_23P, msgWinPL04_24P, msgWinPL04_25P, msgWinPL04_26P, msgWinPL04_27P,
};

static s8 msgWinCtrPL04[28] = {
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2,
};

MessageTable pl04win_usa_tbl = { msgWinAdrPL04, msgWinCtrPL04 };
