/* xb_0117C6.c: Xbox-only code from the run of Xbox-only functions at 0x117C6, which no
 * PS2 file covers.
 * Capcom's source is lost. Its C++ methods are written as C,
 * XB_FASTCALL (__fastcall) with this first. Each body was checked
 * against retail by analysis-ps2map/xbgen.py. The xb_ names are
 * made up. */

#include "types.h"

void XB_STDCALL D3DDevice_Reset(s32 a0);
void XB_STDCALL D3DDevice_SetVerticalBlankCallback(s32 a0);
void XB_STDCALL D3DDevice_SetSwapCallback(s32 a0);
void D3DDevice_PersistDisplay(void);
void XB_STDCALL D3D_SetPushBufferSize(s32 size, s32 kick);

s32 XB_STDCALL xb_SetPushBufferSize(s32 size, s32 kick) {
    D3D_SetPushBufferSize(size, kick);
    return 0;
}

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

void xb_PersistDisplay(void) {
    xb_PersistDisplayThunk();
}
