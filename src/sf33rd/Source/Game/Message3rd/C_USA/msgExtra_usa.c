/* msgExtra_usa.c, retail sf33rd.xbe.
 * The PS2 file's data (ps2.path), checked by analysis-ps2map/portdata.py
 * against the XBE: each table at its data.txt address, or at the
 * address a checked table's pointer to it holds ("placed by").
 * msgEXTRA_000 0x3282c8 size 0x4: match (placed by msgExtraAdr).
 * msgEXTRA_001 0x3282cc size 0x4: match (placed by msgExtraAdr).
 * msgEXTRA_002 0x3282d0 size 0x4: match (placed by msgExtraAdr).
 * msgEXTRA_003 0x3282d4 size 0x4: match (placed by msgExtraAdr).
 * msgEXTRA_004 0x3282d8 size 0x4: match (placed by msgExtraAdr).
 * msgEXTRA_005 0x3282dc size 0x4: match (placed by msgExtraAdr).
 * msgEXTRA_006 0x3282e0 size 0x4: match (placed by msgExtraAdr).
 * msgEXTRA_008 0x3282e4 size 0x4: match (placed by msgExtraAdr).
 * msgEXTRA_009 0x3282e8 size 0x4: match (placed by msgExtraAdr).
 * msgEXTRA_010 0x3282ec size 0x8: match (placed by msgExtraAdr).
 * msgEXTRA_011 0x3282f4 size 0x8: match (placed by msgExtraAdr).
 * msgEXTRA_012 0x3282fc size 0x8: match (placed by msgExtraAdr).
 * msgEXTRA_013 0x328304 size 0x8: match (placed by msgExtraAdr).
 * msgEXTRA_014 0x32830c size 0x4: match (placed by msgExtraAdr).
 * msgEXTRA_016 0x328310 size 0x4: match (placed by msgExtraAdr).
 * msgEXTRA_017 0x328314 size 0x4: match (placed by msgExtraAdr).
 * msgEXTRA_018 0x328318 size 0x8: match (placed by msgExtraAdr).
 * msgEXTRA_019 0x328320 size 0x8: match (placed by msgExtraAdr).
 * msgEXTRA_024 0x328328 size 0x8: match (placed by msgExtraAdr).
 * msgEXTRA_025 0x328330 size 0x4: match (placed by msgExtraAdr).
 * msgEXTRA_026 0x328334 size 0x4: match (placed by msgExtraAdr).
 * msgEXTRA_027 0x328338 size 0x4: match (placed by msgExtraAdr).
 * msgEXTRA_028 0x32833c size 0x4: match (placed by msgExtraAdr).
 * msgEXTRA_029 0x328340 size 0x8: match (placed by msgExtraAdr).
 * msgEXTRA_100 0x328348 size 0x4: match (placed by msgExtraAdr).
 * msgEXTRA_101 0x32834c size 0x4: match (placed by msgExtraAdr).
 * msgEXTRA_102 0x328350 size 0x4: match (placed by msgExtraAdr).
 * msgEXTRA_xxx 0x328354 size 0x4: match (placed by msgExtraAdr).
 * msgExtraAdr 0x328358 size 0x8c: match (placed by msgExtraTbl_usa).
 * msgExtraCtr 0x3283e4 size 0x23: match (placed by msgExtraTbl_usa).
 * msgExtraTbl_usa 0x328408 size 0x8: match (placed by msgExtraTbl).
 */

#include "structs.h"
#include <stddef.h>

/* from sf33rd/Source/Game/Message3rd/C_USA/msgExtra_usa.h */
extern MessageTable msgExtraTbl_usa;

static s8* msgEXTRA_000[1] = { "Change the Life Gauge settings." };
static s8* msgEXTRA_001[1] = { "Adjust the vitality of Player 1." };
static s8* msgEXTRA_002[1] = { "Adjust the vitality of Player 2." };
static s8* msgEXTRA_003[1] = { "Change the guard type." };
static s8* msgEXTRA_004[1] = { "Turn rapid fire on and off." };
static s8* msgEXTRA_005[1] = { "Turn bonus stages on and off." };
static s8* msgEXTRA_006[1] = { "Restore the initial settings." };
static s8* msgEXTRA_008[1] = { "Select the Super Arts Gauge type for Player 1." };
static s8* msgEXTRA_009[1] = { "Select the Super Arts Gauge type for Player 2." };
static s8* msgEXTRA_010[2] = { "Change the number of the Super Arts Gauge", "stocks of Player 1." };
static s8* msgEXTRA_011[2] = { "Change the number of the Super Arts Gauge", "stocks of Player 2." };
static s8* msgEXTRA_012[2] = { "Adjust the Super Arts Gauge length of", "Player 1." };
static s8* msgEXTRA_013[2] = { "Adjust the Super Arts Gauge length of", "Player 2." };
static s8* msgEXTRA_014[1] = { "Adjust the rate that the Super Arts Gauge." };
static s8* msgEXTRA_016[1] = { "Adjust the Stun Gauge length of Player 1." };
static s8* msgEXTRA_017[1] = { "Adjust the Stun Gauge length of Player 2." };
static s8* msgEXTRA_018[2] = { "Adjust the rate that the Stun Gauge", "increases." };
static s8* msgEXTRA_019[2] = { "Adjust the rate that the Stun Gauge", "recovers." };
static s8* msgEXTRA_024[2] = {
    "Show/Erase the screen text display. This",
    "includes the Timer, S.A. Gauge, etc.",
};
static s8* msgEXTRA_025[1] = { "Show/Erase the Life Gauge." };
static s8* msgEXTRA_026[1] = { "Show/Erase the Timer." };
static s8* msgEXTRA_027[1] = { "Show/Erase the Stun Gauge." };
static s8* msgEXTRA_028[1] = { "Show/Erase the Super Arts Gauge." };
static s8* msgEXTRA_029[2] = { "Turn the \"PRESS START\" displayed", "onscreen on and off." };
static s8* msgEXTRA_100[1] = { "Return to the previous page." };
static s8* msgEXTRA_101[1] = { "Return to the Option Menu." };
static s8* msgEXTRA_102[1] = { "Proceed to the next page." };
static s8* msgEXTRA_xxx[1] = { "..." };

static s8** msgExtraAdr[35] = { msgEXTRA_000, msgEXTRA_001, msgEXTRA_002, msgEXTRA_003, msgEXTRA_004, msgEXTRA_005,
                                msgEXTRA_006, msgEXTRA_xxx, msgEXTRA_008, msgEXTRA_009, msgEXTRA_010, msgEXTRA_011,
                                msgEXTRA_012, msgEXTRA_013, msgEXTRA_014, msgEXTRA_xxx, msgEXTRA_016, msgEXTRA_017,
                                msgEXTRA_018, msgEXTRA_019, msgEXTRA_xxx, msgEXTRA_xxx, msgEXTRA_xxx, msgEXTRA_xxx,
                                msgEXTRA_024, msgEXTRA_025, msgEXTRA_026, msgEXTRA_027, msgEXTRA_028, msgEXTRA_029,
                                msgEXTRA_xxx, msgEXTRA_xxx, msgEXTRA_100, msgEXTRA_101, msgEXTRA_102 };

static s8 msgExtraCtr[35] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 1, 1, 1, 1,
                              2, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1 };

MessageTable msgExtraTbl_usa = { msgExtraAdr, msgExtraCtr };
