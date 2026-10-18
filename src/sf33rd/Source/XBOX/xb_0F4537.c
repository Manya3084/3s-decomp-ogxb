/* xb_0F4537.c: Xbox-only code from the run of Xbox-only functions at 0xF4537, which no
 * PS2 file covers.
 * Capcom's source is lost. Its C++ methods are written as C,
 * XB_FASTCALL (__fastcall) with this first. Each body was checked
 * against retail by analysis-ps2map/xbgen.py. The xb_ names are
 * made up. */

#include "types.h"

void xb_PersistDisplay(void);
s32 XB_STDCALL XLaunchNewImageA(const char* path, void* data);
extern s32 D_007970F4;
void xb_RestoreQuadStates(void);
extern s32 D_007970F8;
extern u8 D_007C5959;
extern s32 D_0043FE5C;
void xb_SaveQuadStates(s32 a);
void XB_STDCALL D3DDevice__SetVertexShader(s32 handle);

s32 xb_LaunchImage(const char* path) {
    xb_PersistDisplay();
    return XLaunchNewImageA(path, 0);
}

void xb_Set7970F4(void) {
    D_007970F4 = 1;
}

void ps2SeqsRenderQuadEnd(void) {
    xb_RestoreQuadStates();
}

s32 getCP3toFullScreenDrawFlag(void) {
    return D_007970F8;
}

void CP3toPS2DrawOn(void) {
    D_007970F8 = 1;
}

void CP3toPS2DrawOff(void) {
    D_007970F8 = 0;
}

s32 xb_Get7C5959(void) {
    return D_007C5959;
}

s32 ps2SeqsRenderQuadInit_A(void) {
    if (D_0043FE5C == 0) {
        return 0;
    }

    xb_SaveQuadStates(1);
    D3DDevice__SetVertexShader(0x144);
    return 1;
}

s32 ps2SeqsRenderQuadInit_B(void) {
    if (D_0043FE5C == 0) {
        return 0;
    }

    xb_SaveQuadStates(0);
    D3DDevice__SetVertexShader(0x44);
    return 1;
}
