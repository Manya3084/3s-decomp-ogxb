/* xb_0F4537.c: Xbox-only code from the run of Xbox-only functions at 0xF45CC, which no PS2 file covers.
 * Capcom's source is lost. The C++ methods are written as C,
 * XB_FASTCALL (__fastcall) with this first (analysis-ps2map/xbgen.py wrote
 * these from their shapes). The names are made up (xb_). */

#include "types.h"

extern s32 D_007970F8;
void xb_RestoreQuadStates(void);

void ps2SeqsRenderQuadEnd(void) {
    xb_RestoreQuadStates();
}

s32 getCP3toFullScreenDrawFlag(void) {
    return D_007970F8;
}
