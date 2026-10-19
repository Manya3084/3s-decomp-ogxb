/* PL16Win_usa.c, retail sf33rd.xbe.
 * The PS2 file's data (ps2.path), checked by analysis-ps2map/portdata.py
 * against the XBE: each table at its data.txt address, or at the
 * address a checked table's pointer to it holds ("placed by").
 * msgWinAdrPL16 0x327b90 size 0x70: match (placed by pl16win_usa_tbl).
 * msgWinCtrPL16 0x327c00 size 0x1c: match (placed by pl16win_usa_tbl).
 * msgWinPL16_00P 0x327b00 size 0x4: match (placed by msgWinAdrPL16).
 * msgWinPL16_01P 0x327b04 size 0x4: match (placed by msgWinAdrPL16).
 * msgWinPL16_02P 0x327b08 size 0x4: match (placed by msgWinAdrPL16).
 * msgWinPL16_03P 0x327b0c size 0x4: match (placed by msgWinAdrPL16).
 * msgWinPL16_04P 0x327b10 size 0x4: match (placed by msgWinAdrPL16).
 * msgWinPL16_05P 0x327b14 size 0x4: match (placed by msgWinAdrPL16).
 * msgWinPL16_06P 0x327b18 size 0x4: match (placed by msgWinAdrPL16).
 * msgWinPL16_07P 0x327b1c size 0x4: match (placed by msgWinAdrPL16).
 * msgWinPL16_08P 0x327b20 size 0x4: match (placed by msgWinAdrPL16).
 * msgWinPL16_09P 0x327b24 size 0x4: match (placed by msgWinAdrPL16).
 * msgWinPL16_10P 0x327b28 size 0x4: match (placed by msgWinAdrPL16).
 * msgWinPL16_11P 0x327b2c size 0x4: match (placed by msgWinAdrPL16).
 * msgWinPL16_12P 0x327b30 size 0x4: match (placed by msgWinAdrPL16).
 * msgWinPL16_13P 0x327b34 size 0x4: match (placed by msgWinAdrPL16).
 * msgWinPL16_14P 0x327b38 size 0x4: match (placed by msgWinAdrPL16).
 * msgWinPL16_15P 0x327b3c size 0x4: match (placed by msgWinAdrPL16).
 * msgWinPL16_16P 0x327b40 size 0x4: match (placed by msgWinAdrPL16).
 * msgWinPL16_17P 0x327b44 size 0x4: match (placed by msgWinAdrPL16).
 * msgWinPL16_18P 0x327b48 size 0x4: match (placed by msgWinAdrPL16).
 * msgWinPL16_19P 0x327b4c size 0x4: match (placed by msgWinAdrPL16).
 * msgWinPL16_20P 0x327b50 size 0x8: match (placed by msgWinAdrPL16).
 * msgWinPL16_21P 0x327b58 size 0x8: match (placed by msgWinAdrPL16).
 * msgWinPL16_22P 0x327b60 size 0x8: match (placed by msgWinAdrPL16).
 * msgWinPL16_23P 0x327b68 size 0x8: match (placed by msgWinAdrPL16).
 * msgWinPL16_24P 0x327b70 size 0x8: match (placed by msgWinAdrPL16).
 * msgWinPL16_25P 0x327b78 size 0x8: match (placed by msgWinAdrPL16).
 * msgWinPL16_26P 0x327b80 size 0x8: match (placed by msgWinAdrPL16).
 * msgWinPL16_27P 0x327b88 size 0x8: match (placed by msgWinAdrPL16).
 * pl16win_usa_tbl 0x327c1c size 0x8: match (placed by pl_mes_tbl).
 */

#include "structs.h"
#include <stddef.h>

/* from sf33rd/Source/Game/Message3rd/C_USA/PL16Win_usa.h */
extern MessageTable pl16win_usa_tbl;

static s8* msgWinPL16_00P[1] = { "" };
static s8* msgWinPL16_01P[1] = { "" };
static s8* msgWinPL16_02P[1] = { "" };
static s8* msgWinPL16_03P[1] = { "" };
static s8* msgWinPL16_04P[1] = { "" };
static s8* msgWinPL16_05P[1] = { "" };
static s8* msgWinPL16_06P[1] = { "" };
static s8* msgWinPL16_07P[1] = { "" };
static s8* msgWinPL16_08P[1] = { "" };
static s8* msgWinPL16_09P[1] = { "" };
static s8* msgWinPL16_10P[1] = { "" };
static s8* msgWinPL16_11P[1] = { "" };
static s8* msgWinPL16_12P[1] = { "" };
static s8* msgWinPL16_13P[1] = { "" };
static s8* msgWinPL16_14P[1] = { "" };
static s8* msgWinPL16_15P[1] = { "" };
static s8* msgWinPL16_16P[1] = { "" };
static s8* msgWinPL16_17P[1] = { "" };
static s8* msgWinPL16_18P[1] = { "" };
static s8* msgWinPL16_19P[1] = { "" };
static s8* msgWinPL16_20P[2] = {
    "   You'd fare better if you                     ",
    "   would just cheer up!                         ",
};
static s8* msgWinPL16_21P[2] = {
    "   That was a lot easier than                   ",
    "   I thought it would be!                       ",
};
static s8* msgWinPL16_22P[2] = {
    "   That couldn't have been your                 ",
    "   best effort! Stop holding back!              ",
};
static s8* msgWinPL16_23P[2] = {
    "   It'll take a lot more than that to           ",
    "   take me out! Let's do it again!              ",
};
static s8* msgWinPL16_24P[2] = {
    "   It hurts twice as much when you              ",
    "   know that it was your fault!                 ",
};
static s8* msgWinPL16_25P[2] = {
    "   What's going through your mind               ",
    "   when we fight? I want to know!               ",
};
static s8* msgWinPL16_26P[2] = {
    "   Let's keep fighting until we are             ",
    "   both completely satisfied!                   ",
};
static s8* msgWinPL16_27P[2] = {
    "   Daddy, you believed in me!                   ",
    "   That win was for our Dojo!                   ",
};

static s8** msgWinAdrPL16[28] = {
    msgWinPL16_00P, msgWinPL16_01P, msgWinPL16_02P, msgWinPL16_03P, msgWinPL16_04P, msgWinPL16_05P, msgWinPL16_06P,
    msgWinPL16_07P, msgWinPL16_08P, msgWinPL16_09P, msgWinPL16_10P, msgWinPL16_11P, msgWinPL16_12P, msgWinPL16_13P,
    msgWinPL16_14P, msgWinPL16_15P, msgWinPL16_16P, msgWinPL16_17P, msgWinPL16_18P, msgWinPL16_19P, msgWinPL16_20P,
    msgWinPL16_21P, msgWinPL16_22P, msgWinPL16_23P, msgWinPL16_24P, msgWinPL16_25P, msgWinPL16_26P, msgWinPL16_27P,
};

static s8 msgWinCtrPL16[28] = {
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2,
};

MessageTable pl16win_usa_tbl = { msgWinAdrPL16, msgWinCtrPL16 };
