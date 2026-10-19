/* PL11Tlk_usa.c, retail sf33rd.xbe.
 * The PS2 file's data (ps2.path), checked by analysis-ps2map/portdata.py
 * against the XBE: each table at its data.txt address, or at the
 * address a checked table's pointer to it holds ("placed by").
 * msgTalkAdrPL11 0x327058 size 0x18: match (placed by pl11tlk_usa_tbl).
 * msgTalkCtrPL11 0x327070 size 0x6: match (placed by pl11tlk_usa_tbl).
 * msgTlkPL11_00P 0x327030 size 0x4: match (placed by msgTalkAdrPL11).
 * msgTlkPL11_01P 0x327034 size 0x4: match (placed by msgTalkAdrPL11).
 * msgTlkPL11_02P 0x327038 size 0x8: match (placed by msgTalkAdrPL11).
 * msgTlkPL11_03P 0x327040 size 0x8: match (placed by msgTalkAdrPL11).
 * msgTlkPL11_04P 0x327048 size 0x8: match (placed by msgTalkAdrPL11).
 * msgTlkPL11_05P 0x327050 size 0x8: match (placed by msgTalkAdrPL11).
 * pl11tlk_usa_tbl 0x327078 size 0x8: match (placed by pl_tlk_tbl).
 */

#include "structs.h"
#include <stddef.h>

/* from sf33rd/Source/Game/Message3rd/C_USA/PL11Tlk_usa.h */
extern MessageTable pl11tlk_usa_tbl;

static s8* msgTlkPL11_00P[1] = { "" };
static s8* msgTlkPL11_01P[1] = { "  You're not quite what I expected...           " };
static s8* msgTlkPL11_02P[2] = {
    "  But, you sure do have                         ",
    "  the face of a fighter!                        ",
};
static s8* msgTlkPL11_03P[2] = {
    "  Behave yourself... I am destined to           ",
    "  become the king of the new century.           ",
};
static s8* msgTlkPL11_04P[2] = {
    "  You should thank me for using                 ",
    "  you as my entertainment!                      ",
};
static s8* msgTlkPL11_05P[2] = {
    "  Keep talking like that, and I'll do           ",
    "  much more than just entertain you!            ",
};

static s8** msgTalkAdrPL11[6] = {
    msgTlkPL11_00P, msgTlkPL11_01P, msgTlkPL11_02P, msgTlkPL11_03P, msgTlkPL11_04P, msgTlkPL11_05P,
};

static s8 msgTalkCtrPL11[6] = { 1, 1, 2, 2, 2, 2 };

MessageTable pl11tlk_usa_tbl = { msgTalkAdrPL11, msgTalkCtrPL11 };
