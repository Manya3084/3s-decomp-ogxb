/* xb_012146.c: Xbox-only code from the run of Xbox-only functions at 0x12146, which no
 * PS2 file covers.
 * Capcom's source is lost. Its C++ methods are written as C,
 * XB_FASTCALL (__fastcall) with this first. Each body was checked
 * against retail by analysis-ps2map/xbgen.py. The xb_ names are
 * made up. */

#include "types.h"
#include <string.h>

void std__vector_XONLINE_USER__max_size(void);
void XB_STDCALL D3DDevice_CreateVertexShader(s32 a0, s32 a1, s32 a2, s32 a3);
void XB_STDCALL D3DResource_Release(s32 a0);
void XB_STDCALL xb_Font_DrawAt(s32 a0);
void XB_STDCALL D3DDevice_LightEnable(s32 a0, s32 a1);
void D3DDevice_BlockUntilVerticalBlank(void);
void XB_STDCALL sub_0019860A(s32 a0, s32 a1, s32 a2);
void XB_STDCALL D3DDevice_End(void);
extern u8* D_00795C14;
void ADXM_ExecMain(void);
void xb_XactFrame(void);
void xb_PrintReset(void);
void xb_PrintClear(void);
extern u8 D_00463C10[];
s32 xb_PoolUsedSize(u8* pool);
void XB_STDCALL D3DDevice_Swap(s32 flags);
void XB_STDCALL D3DDevice_Begin(s32 type);
void sub_00015BB6(f32 v);
void* std__allocator_XONLINE_USER__allocate(s32 n, s32 hint);
void XB_STDCALL D3DDevice_SetTransform(s32 state, void* m);
void XB_STDCALL D3DDevice_SetVertexDataColor(s32 reg, s32 color);
void XB_STDCALL D3DDevice_SetPalette(s32 stage, void* pal);
extern s32 D_0044D398;
extern s32 D_00461724;
s32 xb_PoolFreeBlock(u8* pool, s32 block, s32 flags);
s32 xb_PoolGetBlock(u8* pool, s32 n, s32* block);
s32 XB_STDCALL D3DDevice_GetBackBuffer2(s32 index);
void XB_STDCALL sub_00184EF0(s32 a, s32 b, s32 c);
void XB_FASTCALL xb_exception_ctor(void* self, s32 edx, void* what);
extern u8 D_00219440[];
s32 XB_STDCALL D3DPalette_Lock2(void* pal, s32 flags);
extern s32 D_0043FE60;
void xb_ApplyRenderFlagChanges(s32 changed, s32 flags);
extern u8 D_0043EDD8[];
extern u32 D_0079579C[];
extern u32 D_00795788[];
extern u32 D_00795790[];

s32 XB_STDCALL xb_SetTransform(s32 state, void* m) {
    D3DDevice_SetTransform(state, m);
    return 0;
}

void xb_vector_XONLINE_USER_Thunk(void) {
    std__vector_XONLINE_USER__max_size();
}

void* XB_FASTCALL xb_vector_XONLINE_USER_Assign(void* self, s32 edx, s32 n) {
    (void)self;
    (void)edx;
    return std__allocator_XONLINE_USER__allocate(n, 0);
}

void* XB_FASTCALL xb_string_ctor(void** self, s32 edx, void* what) {
    xb_exception_ctor(self, edx, what);
    *self = D_00219440;
    return self;
}

void XB_STDCALL xb_CreateVertexShader(s32 a0, s32 a1, s32 a2, s32 a3) {
    D3DDevice_CreateVertexShader(a0, a1, a2, a3);
}

s32 XB_STDCALL xb_SetVertexDataColor(s32 reg, s32 color) {
    D3DDevice_SetVertexDataColor(reg, color);
    return 0;
}

s32 XB_STDCALL xb_Begin(s32 type) {
    D3DDevice_Begin(type);
    return 0;
}

s32 xb_End(void) {
    D3DDevice_End();
    return 0;
}

void XB_STDCALL xb_ReleaseResource(s32 a0) {
    D3DResource_Release(a0);
}

s32 XB_FASTCALL xb_Font_GetPtr(s32* self, s32 edx, s32 ofs) {
    (void)edx;
    return *self + ofs;
}

void XB_STDCALL xb_Font_Thunk12E09(s32 a0) {
    xb_Font_DrawAt(a0);
}

s32 xb_PoolFree(s32 block) {
    return xb_PoolFreeBlock(D_00463C10, block, 0);
}

s32 xb_PoolAlloc(s32* block) {
    return xb_PoolGetBlock(D_00463C10, 0, block);
}

s32 xb_PoolReset(void) {
    return xb_PoolUsedSize(D_00463C10);
}

s32 xb_ConvertLightType(void) {
    return 0x3;
}

s32 xb_CopyStateRecord(s32 i, void* src) {
    memcpy(D_0043EDD8 + i * 0x4C, src, 0x4C);
    return 1;
}

s32 XB_STDCALL xb_Swap(s32 a0, s32 a1, s32 a2, s32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    D3DDevice_Swap(0);
    return 0;
}

s32 XB_STDCALL xb_GetBackBuffer(s32 index, s32 type, s32* out) {
    (void)type;
    *out = D3DDevice_GetBackBuffer2(index);
    return 0;
}

void xb_SetDisplayArgs(s32 a, s32 b) {
    D_0044D398 = a;
    D_00461724 = b;
}

void XB_STDCALL xb_LightEnable(s32 a0, s32 a1) {
    D3DDevice_LightEnable(a0, a1);
}

s32 XB_STDCALL xb_SetPalette(s32 stage, void* pal) {
    D3DDevice_SetPalette(stage, pal);
    return 0;
}

void xb_BlockUntilVerticalBlank(void) {
    D3DDevice_BlockUntilVerticalBlank();
}

void* XB_FASTCALL xb_CopyMatrix(void* self, s32 edx, void* src) {
    (void)edx;
    memcpy(self, src, 0x40);
    return self;
}

void xb_UpdateRenderFlags(s32 flags) {
    xb_ApplyRenderFlagChanges(D_0043FE60 ^ flags, flags);
    D_0043FE60 = flags;
}

void xb_SetLightAttenuation(f32 v) {
    sub_00015BB6(v);
}

void xb_SetLightRange(f32 v) {
    xb_SetLightAttenuation(v);
}

s32 XB_STDCALL xb_GetLevelDesc(s32 a, s32 b, s32 c) {
    sub_00184EF0(a, b, c);
    return 0;
}

s32 XB_STDCALL xb_LockPalette(void* pal, s32* out, s32 flags) {
    *out = D3DPalette_Lock2(pal, flags);
    return 0;
}

void xb_PADClearVibration(void) {
    memset(D_0079579C, 0, 0x10);
    memset(D_00795788, 0, 8);
    memset(D_00795790, 0, 8);
}

void xb_SoundFrame(void) {
    ADXM_ExecMain();
    xb_XactFrame();
}

void XB_STDCALL xb_DirectSoundThunk(s32 a0, s32 a1, s32 a2) {
    sub_0019860A(a0, a1, a2);
}

s32 xb_GetExtraLoadBufferSize(void) {
    return 0xD400;
}

s32 xb_GetExtraLoadBuffer(void) {
    return *(s32*)(D_00795C14 + 0xC);
}

void xb_SetExtraLoadBuffer(s32 p) {
    *(s32*)(D_00795C14 + 0xC) = p;
}

void xb_PrintSetColor(u8 a, u8 b) {
    u8* p = D_00795C14;

    p[0x1C] = a;
    p[0x1D] = b;
}

void xb_PrintSetPos(s16 x, s16 y) {
    u8* p = D_00795C14;

    *(s16*)(p + 0x10) = x;
    *(s16*)(p + 0x12) = y;
}

void xb_PrintSetScale(f32 scale) {
    *(f32*)(D_00795C14 + 0x14) = scale;
}

void xb_PrintSetAttr(s16 attr) {
    *(u16*)(D_00795C14 + 0x1E) = attr % 16;
}

void xb_PrintSetPage(s32 page) {
    *(s32*)(D_00795C14 + 0x20) = page;
}

void xb_PrintResetAll(void) {
    xb_PrintReset();
    xb_PrintClear();
}
