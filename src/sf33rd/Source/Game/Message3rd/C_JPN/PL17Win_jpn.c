/* PL17Win_jpn.c, retail sf33rd.xbe.
 * The Japanese counterpart of C_USA/PL17Win_usa.c: the table at 0x324B34, which
 * D_0032C150's win table lists for character 17, walked with
 * the US file's 28 messages (analysis-ps2map/jpnmsg.py). */

#include "structs.h"

static s8* msgWinPL17_00J[1] = {
    "\201@\201@\201@\201H\201H\201H\201d\201d\201I\201I\201I",
};
static s8* msgWinPL17_01J[2] = {
    "\201@\201@\201@\201I\201d\201d\201d\201d\201H",
    "\201@\201@\201@\201I\201I",
};
static s8* msgWinPL17_02J[2] = {
    "\201@\201@\201@\201I\201d\201d\201d\201d\201I\201I",
    "\201@\201@\201@\201d\201d\201I\201H",
};
static s8* msgWinPL17_03J[2] = {
    "\201@\201@\201@\201d\201d\201d\201d\201I",
    "\201@\201@\201@\201d\201d\201H",
};
static s8* msgWinPL17_04J[2] = {
    "\201@\201@\201@\201d\201d\201d\201d\201d\201d\201H",
    "\201@\201@\201@\201I\201d\201d\201d\201d\201d\201d",
};
static s8* msgWinPL17_05J[2] = {
    "\201@\201@\201@\201H\201d\201d\201d\201d\201d\201d\201I",
    "\201@\201@\201@\201I\201H",
};
static s8* msgWinPL17_06J[2] = {
    "\201@\201@\201@\201I\201d\201d\201d\201d\201I",
    "\201@\201@\201@\201I\201d\201d\201d\201d\201I",
};
static s8* msgWinPL17_07J[1] = {
    "\201@\201@\201@\201d\201d\201d\201I\201Hbh\201d\201d\201d\201I\201I",
};
static s8* msgWinPL17_08J[1] = {
    "\201@\201@\201@\201d\201d\201Ibh\201d\201d\201I",
};
static s8* msgWinPL17_09J[2] = {
    "\201@\201@\201@\201H\201d\201d\201d\201d",
    "\201@\201@\201@\201H\201d\201d\201d\201d",
};
static s8* msgWinPL17_10J[2] = {
    "\201@\201@\201@\201d\201d\201d\201d\201d\201d\201d\201d",
    "\201@\201@\201@\201d\201d\201d\201Ibh\201d\201d\201d\201H",
};
static s8* msgWinPL17_11J[1] = {
    "\201@\201@\201@\201Ibh\201d\201d\201d\201I\201I",
};
static s8* msgWinPL17_12J[2] = {
    "\201@\201@\201@\201Hbh\201H",
    "\201@\201@\201@\201d\201d\201d\201d\201I\201d\201d\201d\201d",
};
static s8* msgWinPL17_13J[1] = {
    "\201@\201@\201@\201Ibh\201d\201d\201d\201Hbh\201d\201d\201d\201I\201I",
};
static s8* msgWinPL17_14J[1] = {
    "\201@\201@\201@\201I\201Hbh\201d\201d\201d\201d\201I\201I\201I",
};
static s8* msgWinPL17_15J[2] = {
    "\201@\201@\201@\201I\201d\201d\201d\201I\201I",
    "\201@\201@\201@\201d\201d\201d\201Ibh\201d\201d\201I\201H",
};
static s8* msgWinPL17_16J[2] = {
    "\201@\201@\201@\201I\201H",
    "\201@\201@\201@\201d\201d\201d\201d\201d\201H",
};
static s8* msgWinPL17_17J[1] = {
    "\201@\201@\201@\201I\201I\201I\201I\201I",
};
static s8* msgWinPL17_18J[1] = {
    "\201@\201@\201@\201Hbh\201d\201d\201H\201H",
};
static s8* msgWinPL17_19J[1] = {
    "\201@\201@\201@\201H\201d\201d\201I\201d\201d\201H\201d\201d\201I\201I",
};
static s8* msgWinPL17_20J[1] = {
    "\201@\201@\201@\201I\201d\201d\201d\201d",
};
static s8* msgWinPL17_21J[1] = {
    "\201@\201@\201@\201H\201d\201d\201d\201d",
};
static s8* msgWinPL17_22J[1] = {
    "\201@\201@\201@\201I\201H\201d\201d\201d\201d",
};
static s8* msgWinPL17_23J[1] = {
    "\201@\201@\201@\201d\201d\201d\201d",
};
static s8* msgWinPL17_24J[2] = {
    "\201@\201@\201@\201d\201d\201d\201d\201d\201d\201d\201d\201d\201d\201d\201d",
    "\201@\201@\201@\201d\201d\201d\201d\201d\201d\201d\201d\201d\201d\201d\201d",
};
static s8* msgWinPL17_25J[1] = {
    "\201@\201@\201@\201d\201d\201d\201d\201d\201d\201d\201d\201d\201d\201d\201d",
};
static s8* msgWinPL17_26J[1] = {
    "\201@\201@\201@\201d\201d\201d\201d\201H",
};
static s8* msgWinPL17_27J[1] = {
    "\201@\201@\201@\201d\201d\201d\201d\201I",
};

static s8** msgWinAdrPL17J[28] = {
    msgWinPL17_00J, msgWinPL17_01J, msgWinPL17_02J, msgWinPL17_03J, msgWinPL17_04J, msgWinPL17_05J,
    msgWinPL17_06J, msgWinPL17_07J, msgWinPL17_08J, msgWinPL17_09J, msgWinPL17_10J, msgWinPL17_11J,
    msgWinPL17_12J, msgWinPL17_13J, msgWinPL17_14J, msgWinPL17_15J, msgWinPL17_16J, msgWinPL17_17J,
    msgWinPL17_18J, msgWinPL17_19J, msgWinPL17_20J, msgWinPL17_21J, msgWinPL17_22J, msgWinPL17_23J,
    msgWinPL17_24J, msgWinPL17_25J, msgWinPL17_26J, msgWinPL17_27J,
};

static s8 msgWinCtrPL17J[28] = {
    1, 2, 2, 2, 2, 2, 2, 1, 1, 2, 2, 1, 2, 1, 1, 2, 2, 1, 1, 1, 1, 1, 1, 1,
    2, 1, 1, 1,
};

/* xb_pl17win_jpn_tbl is 0x324B34. */
MessageTable xb_pl17win_jpn_tbl = { msgWinAdrPL17J, msgWinCtrPL17J };
