/* msgMenu_usa.c, retail sf33rd.xbe.
 * The PS2 file's data (ps2.path), checked by analysis-ps2map/portdata.py
 * against the XBE: each table at its data.txt address, or at the
 * address a checked table's pointer to it holds ("placed by").
 * msgMenuAdr 0x328428 size 0x4: match (placed by msgMenuTbl_usa).
 * msgMenuCtr 0x32842c size 0x1: the Xbox count (placed by msgMenuTbl_usa).
 * msgMenuTbl_usa 0x328430 size 0x8: match (placed by msgMenuTbl).
 * msgMenu_000 0x328410 size 0x18: the Xbox text, six lines (PS2 three), taken
 * from the XBE (placed by msgMenuAdr).
 */

#include "structs.h"
#include <stddef.h>

/* from sf33rd/Source/Game/Message3rd/C_USA/msgMenu_usa.h */
extern MessageTable msgMenuTbl_usa;

static s8* msgMenu_000[6] = {
    "Returning to game select menu.",
    "All unsaved data will be lost.",
    "",
    "Is this OK ?",
    "",
    "        Yes:   No:            ",
};

static s8** msgMenuAdr[1] = { msgMenu_000 };

static s8 msgMenuCtr[1] = { 6 };

MessageTable msgMenuTbl_usa = { msgMenuAdr, msgMenuCtr };
