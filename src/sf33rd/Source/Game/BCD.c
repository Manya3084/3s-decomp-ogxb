/* BCD.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * sbcd 0x1CF59 size 0x75.
 * Data: bcdext 0xCBA91C.
 * Globals: bcdext 0xCBA91C.
 */

#include "structs.h"



extern s16 bcdext;

u8 sbcd(u8 a, u8 b) {
    s16 c, d;

    if ((d = (b & 0xF) - (a & 0xF) - (bcdext & 1)) < 0) {
        d += 10;
        d |= 16;
    }

    c = (b & 0xF0) - (a & 0xF0) - (d & 0xF0);
    d &= 0xF;

    if ((d |= c) < 0) {
        d += 160;
        bcdext = 1;
    } else {
        bcdext = 0;
    }

    return d;
}
