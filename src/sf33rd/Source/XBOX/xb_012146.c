/* xb_012146.c: Xbox-only code from the run of Xbox-only functions at 0x121F2, which no PS2 file covers.
 * Capcom's source is lost. The C++ methods are written as C,
 * XB_FASTCALL (__fastcall) with this first (analysis-ps2map/xbgen.py wrote
 * these from their shapes). The names are made up (xb_). */

#include "types.h"

void D3DDevice_BlockUntilVerticalBlank(void);
void XB_STDCALL D3DDevice_CreateVertexShader(s32 a0, s32 a1, s32 a2, s32 a3);
void XB_STDCALL D3DDevice_LightEnable(s32 a0, s32 a1);
void XB_STDCALL D3DResource_Release(s32 a0);
void XB_STDCALL sub_0019860A(s32 a0, s32 a1, s32 a2);
void XB_STDCALL xb_Font_DrawAt(s32 a0);
void std__vector_XONLINE_USER__max_size(void);

void xb_vector_XONLINE_USER_Thunk(void) {
    std__vector_XONLINE_USER__max_size();
}

void XB_STDCALL xb_CreateVertexShader(s32 a0, s32 a1, s32 a2, s32 a3) {
    D3DDevice_CreateVertexShader(a0, a1, a2, a3);
}

void XB_STDCALL xb_ReleaseResource(s32 a0) {
    D3DResource_Release(a0);
}

void XB_STDCALL xb_Font_Thunk12E09(s32 a0) {
    xb_Font_DrawAt(a0);
}

s32 xb_ConvertLightType(void) {
    return 0x3;
}

void XB_STDCALL xb_LightEnable(s32 a0, s32 a1) {
    D3DDevice_LightEnable(a0, a1);
}

void xb_BlockUntilVerticalBlank(void) {
    D3DDevice_BlockUntilVerticalBlank();
}

void XB_STDCALL xb_DirectSoundThunk(s32 a0, s32 a1, s32 a2) {
    sub_0019860A(a0, a1, a2);
}

s32 xb_GetExtraLoadBufferSize(void) {
    return 0xD400;
}
