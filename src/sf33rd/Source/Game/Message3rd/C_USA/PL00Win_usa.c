/* PL00Win_usa.c, retail sf33rd.xbe.
 * The PS2 file's data (ps2.path), checked by analysis-ps2map/portdata.py
 * against the XBE: each table at its data.txt address, or at the
 * address a checked table's pointer to it holds ("placed by").
 * msgWinAdrPL00 0x3258d8 size 0x70: match (placed by pl00win_usa_tbl).
 * msgWinCtrPL00 0x325948 size 0x1c: match (placed by pl00win_usa_tbl).
 * msgWinPL00_00P 0x3257f8 size 0x8: match (placed by msgWinAdrPL00).
 * msgWinPL00_01P 0x325800 size 0x8: match (placed by msgWinAdrPL00).
 * msgWinPL00_02P 0x325808 size 0x8: match (placed by msgWinAdrPL00).
 * msgWinPL00_03P 0x325810 size 0x8: match (placed by msgWinAdrPL00).
 * msgWinPL00_04P 0x325818 size 0x8: match (placed by msgWinAdrPL00).
 * msgWinPL00_05P 0x325820 size 0x8: match (placed by msgWinAdrPL00).
 * msgWinPL00_06P 0x325828 size 0x8: match (placed by msgWinAdrPL00).
 * msgWinPL00_07P 0x325830 size 0x8: match (placed by msgWinAdrPL00).
 * msgWinPL00_08P 0x325838 size 0x8: match (placed by msgWinAdrPL00).
 * msgWinPL00_09P 0x325840 size 0x8: match (placed by msgWinAdrPL00).
 * msgWinPL00_10P 0x325848 size 0x8: match (placed by msgWinAdrPL00).
 * msgWinPL00_11P 0x325850 size 0x8: match (placed by msgWinAdrPL00).
 * msgWinPL00_12P 0x325858 size 0x8: match (placed by msgWinAdrPL00).
 * msgWinPL00_13P 0x325860 size 0x8: match (placed by msgWinAdrPL00).
 * msgWinPL00_14P 0x325868 size 0x8: match (placed by msgWinAdrPL00).
 * msgWinPL00_15P 0x325870 size 0x8: match (placed by msgWinAdrPL00).
 * msgWinPL00_16P 0x325878 size 0x8: match (placed by msgWinAdrPL00).
 * msgWinPL00_17P 0x325880 size 0x8: match (placed by msgWinAdrPL00).
 * msgWinPL00_18P 0x325888 size 0x8: match (placed by msgWinAdrPL00).
 * msgWinPL00_19P 0x325890 size 0x8: match (placed by msgWinAdrPL00).
 * msgWinPL00_20P 0x325898 size 0x8: match (placed by msgWinAdrPL00).
 * msgWinPL00_21P 0x3258a0 size 0x8: match (placed by msgWinAdrPL00).
 * msgWinPL00_22P 0x3258a8 size 0x8: match (placed by msgWinAdrPL00).
 * msgWinPL00_23P 0x3258b0 size 0x8: match (placed by msgWinAdrPL00).
 * msgWinPL00_24P 0x3258b8 size 0x8: match (placed by msgWinAdrPL00).
 * msgWinPL00_25P 0x3258c0 size 0x8: match (placed by msgWinAdrPL00).
 * msgWinPL00_26P 0x3258c8 size 0x8: match (placed by msgWinAdrPL00).
 * msgWinPL00_27P 0x3258d0 size 0x8: match (placed by msgWinAdrPL00).
 * pl00win_usa_tbl 0x325964 size 0x8: match (placed by pl_mes_tbl).
 */

#include "structs.h"
#include <stddef.h>

/* from sf33rd/Source/Game/Message3rd/C_USA/PL00Win_usa.h */
extern MessageTable pl00win_usa_tbl;

static s8* msgWinPL00_00P[2] = { "", "" };
static s8* msgWinPL00_01P[2] = { "", "" };
static s8* msgWinPL00_02P[2] = { "", "" };
static s8* msgWinPL00_03P[2] = { "", "" };
static s8* msgWinPL00_04P[2] = { "", "" };
static s8* msgWinPL00_05P[2] = { "", "" };
static s8* msgWinPL00_06P[2] = { "", "" };
static s8* msgWinPL00_07P[2] = { "", "" };
static s8* msgWinPL00_08P[2] = { "", "" };
static s8* msgWinPL00_09P[2] = { "", "" };
static s8* msgWinPL00_10P[2] = { "", "" };
static s8* msgWinPL00_11P[2] = { "", "" };
static s8* msgWinPL00_12P[2] = { "", "" };
static s8* msgWinPL00_13P[2] = { "", "" };
static s8* msgWinPL00_14P[2] = { "", "" };
static s8* msgWinPL00_15P[2] = { "", "" };
static s8* msgWinPL00_16P[2] = { "", "" };
static s8* msgWinPL00_17P[2] = { "", "" };
static s8* msgWinPL00_18P[2] = { "", "" };
static s8* msgWinPL00_19P[2] = { "", "" };
static s8* msgWinPL00_20P[2] = {
    "   You will have to exceed your                 ",
    "   limitations if you wish to survive.          ",
};
static s8* msgWinPL00_21P[2] = {
    "   Immortality is not a gift.                   ",
    "   It is a responsibility.                      ",
};
static s8* msgWinPL00_22P[2] = {
    "   It is natural for you to desire that         ",
    "   which you can never have or achieve!         ",
};
static s8* msgWinPL00_23P[2] = {
    "   A supreme being's influence                  ",
    "   is the key to his power.                     ",
};
static s8* msgWinPL00_24P[2] = {
    "   Two centuries... A mere blink                ",
    "   upon the face of eternity...                 ",
};
static s8* msgWinPL00_25P[2] = {
    "   Rest for now, then perform the               ",
    "   great work that is ahead of you!             ",
};
static s8* msgWinPL00_26P[2] = {
    "   My methods may seem harsh in                 ",
    "   contrast to my true intentions.              ",
};
static s8* msgWinPL00_27P[2] = {
    "   The stage has been set. Do not               ",
    "   interfere with my grand performance!         ",
};

static s8** msgWinAdrPL00[28] = {
    msgWinPL00_00P, msgWinPL00_01P, msgWinPL00_02P, msgWinPL00_03P, msgWinPL00_04P, msgWinPL00_05P, msgWinPL00_06P,
    msgWinPL00_07P, msgWinPL00_08P, msgWinPL00_09P, msgWinPL00_10P, msgWinPL00_11P, msgWinPL00_12P, msgWinPL00_13P,
    msgWinPL00_14P, msgWinPL00_15P, msgWinPL00_16P, msgWinPL00_17P, msgWinPL00_18P, msgWinPL00_19P, msgWinPL00_20P,
    msgWinPL00_21P, msgWinPL00_22P, msgWinPL00_23P, msgWinPL00_24P, msgWinPL00_25P, msgWinPL00_26P, msgWinPL00_27P,
};

static s8 msgWinCtrPL00[28] = {
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
};

MessageTable pl00win_usa_tbl = { msgWinAdrPL00, msgWinCtrPL00 };
