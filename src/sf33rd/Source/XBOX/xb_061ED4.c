/* xb_061ED4.c: Xbox-only code from the run of Xbox-only functions at 0x61ED4, which no
 * PS2 file covers.
 * Capcom's source is lost. Its C++ methods are written as C,
 * XB_FASTCALL (__fastcall) with this first. Each body was checked
 * against retail by analysis-ps2map/xbgen.py. The xb_ names are
 * made up. */

#include "types.h"
#include <string.h>

extern u8 D_00C7E780[];
extern u8 PrioBase[];

void xb_RestorePrioBase(void) {
    memcpy(PrioBase, D_00C7E780, 0x200);
}
