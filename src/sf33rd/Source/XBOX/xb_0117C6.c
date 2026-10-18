/* xb_0117C6.c: Xbox-only code from the run of Xbox-only functions at 0x11E3F, which no PS2 file covers.
 * Capcom's source is lost. The C++ methods are written as C,
 * XB_FASTCALL (__fastcall) with this first (analysis-ps2map/xbgen.py wrote
 * these from their shapes). The names are made up (xb_). */

#include "types.h"

void D3DDevice_PersistDisplay(void);
void XB_STDCALL D3DDevice_Reset(s32 a0);
void XB_STDCALL D3DDevice_SetSwapCallback(s32 a0);
void XB_STDCALL D3DDevice_SetVerticalBlankCallback(s32 a0);

void XB_STDCALL xb_ResetDevice(s32 a0) {
    D3DDevice_Reset(a0);
}

void XB_STDCALL xb_SetVerticalBlankCallback(s32 a0) {
    D3DDevice_SetVerticalBlankCallback(a0);
}

void XB_STDCALL xb_SetSwapCallback(s32 a0) {
    D3DDevice_SetSwapCallback(a0);
}

void xb_PersistDisplayThunk(void) {
    D3DDevice_PersistDisplay();
}
