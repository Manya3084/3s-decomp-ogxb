/* xb_0C7E80.c: Xbox-only code from the run of Xbox-only functions at 0xC8101, which no PS2 file covers.
 * Capcom's source is lost. The C++ methods are written as C,
 * XB_FASTCALL (__fastcall) with this first (analysis-ps2map/xbgen.py wrote
 * these from their shapes). The names are made up (xb_). */

#include "types.h"

void xb_PoolFree(void);

void xb_PoolFreeThunk(void) {
    xb_PoolFree();
}
