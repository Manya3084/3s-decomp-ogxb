/* EFF00.c: effect_00_move, retail sf33rd.xbe.
 * On the PS2, effect 00 draws the hit boxes for the debug switches
 * (Debug_w[18] to [23]). The Xbox build has no debug switches and no
 * effect_00_init call: the move routine is folded into the empty body at
 * 0x4384A, and the rest of the PS2 file is not in the XBE. The routine is
 * still the first entry of EFFXX.c's move table. */

#include "structs.h"

void effect_00_move(WORK_Other_JUDGE* ewk) {
}
