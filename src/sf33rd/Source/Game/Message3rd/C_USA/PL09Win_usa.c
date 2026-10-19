/* PL09Win_usa.c, retail sf33rd.xbe.
 * The PS2 file's data (ps2.path), checked by analysis-ps2map/portdata.py
 * against the XBE: each table at its data.txt address, or at the
 * address a checked table's pointer to it holds ("placed by").
 * msgWinAdrPL09 0x326c58 size 0x70: match (placed by pl09win_usa_tbl).
 * msgWinCtrPL09 0x326cc8 size 0x1c: match (placed by pl09win_usa_tbl).
 * msgWinPL09_00P 0x326bc8 size 0x4: match (placed by msgWinAdrPL09).
 * msgWinPL09_01P 0x326bcc size 0x4: match (placed by msgWinAdrPL09).
 * msgWinPL09_02P 0x326bd0 size 0x4: match (placed by msgWinAdrPL09).
 * msgWinPL09_03P 0x326bd4 size 0x4: match (placed by msgWinAdrPL09).
 * msgWinPL09_04P 0x326bd8 size 0x4: match (placed by msgWinAdrPL09).
 * msgWinPL09_05P 0x326bdc size 0x4: match (placed by msgWinAdrPL09).
 * msgWinPL09_06P 0x326be0 size 0x4: match (placed by msgWinAdrPL09).
 * msgWinPL09_07P 0x326be4 size 0x4: match (placed by msgWinAdrPL09).
 * msgWinPL09_08P 0x326be8 size 0x4: match (placed by msgWinAdrPL09).
 * msgWinPL09_09P 0x326bec size 0x4: match (placed by msgWinAdrPL09).
 * msgWinPL09_10P 0x326bf0 size 0x4: match (placed by msgWinAdrPL09).
 * msgWinPL09_11P 0x326bf4 size 0x4: match (placed by msgWinAdrPL09).
 * msgWinPL09_12P 0x326bf8 size 0x4: match (placed by msgWinAdrPL09).
 * msgWinPL09_13P 0x326bfc size 0x4: match (placed by msgWinAdrPL09).
 * msgWinPL09_14P 0x326c00 size 0x4: match (placed by msgWinAdrPL09).
 * msgWinPL09_15P 0x326c04 size 0x4: match (placed by msgWinAdrPL09).
 * msgWinPL09_16P 0x326c08 size 0x4: match (placed by msgWinAdrPL09).
 * msgWinPL09_17P 0x326c0c size 0x4: match (placed by msgWinAdrPL09).
 * msgWinPL09_18P 0x326c10 size 0x4: match (placed by msgWinAdrPL09).
 * msgWinPL09_19P 0x326c14 size 0x4: match (placed by msgWinAdrPL09).
 * msgWinPL09_20P 0x326c18 size 0x8: match (placed by msgWinAdrPL09).
 * msgWinPL09_21P 0x326c20 size 0x8: match (placed by msgWinAdrPL09).
 * msgWinPL09_22P 0x326c28 size 0x8: match (placed by msgWinAdrPL09).
 * msgWinPL09_23P 0x326c30 size 0x8: match (placed by msgWinAdrPL09).
 * msgWinPL09_24P 0x326c38 size 0x8: match (placed by msgWinAdrPL09).
 * msgWinPL09_25P 0x326c40 size 0x8: match (placed by msgWinAdrPL09).
 * msgWinPL09_26P 0x326c48 size 0x8: match (placed by msgWinAdrPL09).
 * msgWinPL09_27P 0x326c50 size 0x8: match (placed by msgWinAdrPL09).
 * pl09win_usa_tbl 0x326ce4 size 0x8: match (placed by pl_mes_tbl).
 */

#include "structs.h"
#include <stddef.h>

/* from sf33rd/Source/Game/Message3rd/C_USA/PL09Win_usa.h */
extern MessageTable pl09win_usa_tbl;

static s8* msgWinPL09_00P[1] = { "" };
static s8* msgWinPL09_01P[1] = { "" };
static s8* msgWinPL09_02P[1] = { "" };
static s8* msgWinPL09_03P[1] = { "" };
static s8* msgWinPL09_04P[1] = { "" };
static s8* msgWinPL09_05P[1] = { "" };
static s8* msgWinPL09_06P[1] = { "" };
static s8* msgWinPL09_07P[1] = { "" };
static s8* msgWinPL09_08P[1] = { "" };
static s8* msgWinPL09_09P[1] = { "" };
static s8* msgWinPL09_10P[1] = { "" };
static s8* msgWinPL09_11P[1] = { "" };
static s8* msgWinPL09_12P[1] = { "" };
static s8* msgWinPL09_13P[1] = { "" };
static s8* msgWinPL09_14P[1] = { "" };
static s8* msgWinPL09_15P[1] = { "" };
static s8* msgWinPL09_16P[1] = { "" };
static s8* msgWinPL09_17P[1] = { "" };
static s8* msgWinPL09_18P[1] = { "" };
static s8* msgWinPL09_19P[1] = { "" };
static s8* msgWinPL09_20P[2] = {
    "   Your moves are deadly... They could          ",
    "   kill me by boring me to death!               ",
};
static s8* msgWinPL09_21P[2] = {
    "   Have you no sense of defense?                ",
    "   Or do you just like to feel pain?            ",
};
static s8* msgWinPL09_22P[2] = {
    "   If we went home right now, would             ",
    "   anyone really care? Probably not.",
};
static s8* msgWinPL09_23P[2] = {
    "   Keep it up and you'll suffer the             ",
    "   horror of pain!                              ",
};
static s8* msgWinPL09_24P[2] = {
    "   Would you like to meet my pets?              ",
    "   Or are you too injured?                      ",
};
static s8* msgWinPL09_25P[2] = {
    "   If you are angry, how can you                ",
    "   hope to strike accurately?                   ",
};
static s8* msgWinPL09_26P[2] = {
    "   If I kept fighting against you,              ",
    "   I might actually get worse!                  ",
};
static s8* msgWinPL09_27P[2] = {
    "   I'm so bored! I feel so limited!             ",
    "   Huh? You feel the same way?                  ",
};

static s8** msgWinAdrPL09[28] = {
    msgWinPL09_00P, msgWinPL09_01P, msgWinPL09_02P, msgWinPL09_03P, msgWinPL09_04P, msgWinPL09_05P, msgWinPL09_06P,
    msgWinPL09_07P, msgWinPL09_08P, msgWinPL09_09P, msgWinPL09_10P, msgWinPL09_11P, msgWinPL09_12P, msgWinPL09_13P,
    msgWinPL09_14P, msgWinPL09_15P, msgWinPL09_16P, msgWinPL09_17P, msgWinPL09_18P, msgWinPL09_19P, msgWinPL09_20P,
    msgWinPL09_21P, msgWinPL09_22P, msgWinPL09_23P, msgWinPL09_24P, msgWinPL09_25P, msgWinPL09_26P, msgWinPL09_27P,
};

static s8 msgWinCtrPL09[28] = {
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2,
};

MessageTable pl09win_usa_tbl = { msgWinAdrPL09, msgWinCtrPL09 };
