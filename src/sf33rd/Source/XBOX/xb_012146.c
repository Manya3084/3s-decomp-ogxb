/* xb_012146.c: Xbox-only code from the run of Xbox-only functions at 0x12146, which no
 * PS2 file covers.
 * Capcom's source is lost. Its C++ methods are written as C,
 * XB_FASTCALL (__fastcall) with this first. Each body was checked
 * against retail by analysis-ps2map/xbgen.py. The xb_ names are
 * made up. */

#include "types.h"
#include <string.h>
#include <stdarg.h>

typedef struct {
    s16 a;
    s16 b;
    s16 c;
    s16 d;
} XB_PADCFG;
void XB_STDCALL D3DDevice_SetTransform(s32 state, void* m);
void std__vector_XONLINE_USER__max_size(void);
void* std__allocator_XONLINE_USER__allocate(s32 n, s32 hint);
void XB_FASTCALL xb_exception_ctor(void* self, s32 edx, void* what);
extern u8 D_00219440[];
void XB_STDCALL D3DDevice_CreateVertexShader(s32 a0, s32 a1, s32 a2, s32 a3);
void XB_STDCALL D3DDevice_SetVertexDataColor(s32 reg, s32 color);
void XB_STDCALL D3DDevice_Begin(s32 type);
void XB_STDCALL D3DDevice_End(void);
void XB_STDCALL D3DResource_Release(s32 a0);
void* XB_STDCALL D3DTexture_GetSurfaceLevel2(void* tex, s32 level);
void XB_STDCALL xb_Font_DrawAt(s32 a0);
extern u8 D_00463C10[];
s32 xb_PoolFreeBlock(u8* pool, s32 block, s32 flags);
s32 xb_PoolGetBlock(u8* pool, s32 n, s32* block);
s32 xb_PoolUsedSize(u8* pool);
s32 vsprintf(char* buf, const char* fmt, va_list ap);
void XB_STDCALL OutputDebugStringA(const char* s);
extern u8 D_0043EDD8[];
void XB_STDCALL D3DDevice_Swap(s32 flags);
s32 XB_STDCALL D3DDevice_GetBackBuffer2(s32 index);
extern s32 D_0044D398;
extern s32 D_00461724;
extern s32 D_0043ED18;
extern s32 D_0044D394;
extern s32 D_0043ED0C;
extern s32 D_0043ED10;
void XB_STDCALL D3DDevice_LightEnable(s32 a0, s32 a1);
void XB_STDCALL D3DDevice_SetPalette(s32 stage, void* pal);
void D3DDevice_BlockUntilVerticalBlank(void);
extern u8 D_00440020[];
extern s32 D_00474CAC;
void XB_STDCALL D3DDevice__SetTexture(s32 stage, s32 tex);
s32 XB_STDCALL xb_SetRenderState(s32 state, s32 value);
extern s32 D_0043FE60;
void xb_ApplyRenderFlagChanges(s32 changed, s32 flags);
void xb_SetViewportRect4(s32 a, s32 b, s32 c, s32 d, s32 e, f32 f, f32 g);
void sub_00015BB6(f32 v);
extern s32 D_00474D9C;
extern s32 D_00474D80;
extern s32 D_00474D98;
extern s32 D_00474D74;
extern s32 D_00474D88;
extern s32 D_00474D94;
extern s32 D_00474D84;
extern s32 D_00474D90;
extern s32 D_00474D7C;
s32 XB_STDCALL xb_SetTextureStageState(s32 stage, s32 state, s32 value);
extern s32 dword_4616AC;
void xb_SaveQuadStates(s32 a);
s32 xb_DrawQuadInternal(void* q);
s32 sub_00015E96(void* q);
s32 xb_DrawRectInternal(void* q);
extern u8 D_0043FF90[];
void* XB_STDCALL D3DDevice_CreatePalette2(s32 size);
void XB_STDCALL sub_00184EF0(s32 a, s32 b, s32 c);
s32 XB_STDCALL D3DPalette_Lock2(void* pal, s32 flags);
extern XB_PADCFG D_00795768[];
extern u32 D_0079579C[];
extern u16 D_00795790[];
extern u16 D_00795788[];
void XB_STDCALL sub_00211EF7(s32 a, s32 b);
extern s32 D_00795C04;
extern u8 D_00795C00[];
s32 xb_PADOpenDevices(void* p);
extern u8 D_007957B4[];
extern u8 D_0043EA04[];
void ADXM_ExecMain(void);
void xb_XactFrame(void);
void XB_STDCALL sub_0019860A(s32 a0, s32 a1, s32 a2);
extern u8* D_00795C14;
void xb_PrintReset(void);

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

s32 XB_STDCALL xb_GetSurfaceLevel(void* tex, s32 level, void** out) {
    void* p = D3DTexture_GetSurfaceLevel2(tex, level);

    *out = p;
    return p != 0 ? 0 : 0x8007000E;
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

s32 flLogOut(const char* fmt, ...) {
    char buf[0x800];
    va_list ap;

    va_start(ap, fmt);
    vsprintf(buf, fmt, ap);
    OutputDebugStringA(buf);
    return 1;
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

void xb_SetViewportRect(s32 x, s32 y, s32 w, s32 h) {
    D_0043ED18 = x;
    D_0044D394 = y;
    D_0043ED0C = w;
    D_0043ED10 = h;
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

f32* XB_FASTCALL xb_ColorToFloat4(f32* out, s32 edx, u32 c) {
    (void)edx;
    out[0] = (u8)(c >> 16) * (1.0f / 255.0f);
    out[1] = (u8)(c >> 8) * (1.0f / 255.0f);
    out[2] = (u8)c * (1.0f / 255.0f);
    out[3] = (s32)(c >> 24) * (1.0f / 255.0f);
    return out;
}

void xb_MatrixIdentity(f32* m) {
    m[1] = m[2] = m[3] = m[4] = m[6] = m[7] = m[8] = m[9] = m[11] = m[12] = m[13] = m[14] = 0.0f;
    m[0] = m[5] = m[10] = m[15] = 1.0f;
}

s32 xb_BindTextureHandle(s32 stage, u32 handle) {
    s32 tex;

    if (handle >= 1 && handle < 0x100) {
        tex = *(s32*)(D_00440020 + handle * 0xD4);

        if (tex) {
            D_00474CAC = handle;
            D3DDevice__SetTexture(stage, tex);
            return 1;
        }
    }

    return 0;
}

s32 xb_ApplyFlags03(s32 flags) {
    switch (flags & 3) {
    case 0:
        xb_SetRenderState(0x69, 1);
        break;

    case 2:
        xb_SetRenderState(0x69, 0);
        break;
    }

    return 1;
}

s32 xb_ApplyFlags1C(s32 flags) {
    switch (flags & 0x1C) {
    case 0:
        xb_SetRenderState(0x67, 0);
        break;

    case 4:
    case 8:
    case 0xC:
    case 0x10:
    case 0x14:
    case 0x18:
        xb_SetRenderState(0x67, 1);
        break;
    }

    return 1;
}

s32 xb_ApplyFlags60(s32 flags) {
    switch (flags & 0x60) {
    case 0:
        xb_SetRenderState(0x93, 0);
        break;

    case 0x20:
        xb_SetRenderState(0x93, 0x900);
        break;

    case 0x40:
        xb_SetRenderState(0x93, 0x901);
        break;
    }

    return 1;
}

s32 xb_ApplyFlags18000(s32 flags) {
    switch (flags & 0x18000) {
    case 0:
        xb_SetRenderState(0x5C, 0);
        break;

    case 0x8000:
        xb_SetRenderState(0x5C, 1);
        break;
    }

    return 1;
}

void xb_UpdateRenderFlags(s32 flags) {
    xb_ApplyRenderFlagChanges(D_0043FE60 ^ flags, flags);
    D_0043FE60 = flags;
}

void xb_SetViewportFloat(s32 a, s32 b, s32 c, s32 d, s32 e, f32 f, f32 g) {
    xb_SetViewportRect4(a, b, c, d, e, f, g);
}

void xb_SetLightAttenuation(f32 v) {
    sub_00015BB6(v);
}

void xb_SetLightRange(f32 v) {
    xb_SetLightAttenuation(v);
}

void xb_RestoreQuadStates(void) {
    if (D_00474D9C) {
        xb_SetRenderState(0x66, D_00474D80);
    }

    if (D_00474D98) {
        xb_SetRenderState(0x5C, D_00474D74);
    }

    if (D_00474D88) {
        xb_SetRenderState(0x93, D_00474D94);
    }

    if (D_00474D84) {
        xb_SetTextureStageState(0, 0xC, D_00474D90);
        xb_SetTextureStageState(0, 0x10, D_00474D7C);
    }
}

s32 xb_DrawQuadWithSavedStates(void* q) {
    s32 r;

    if (dword_4616AC) {
        return 0;
    }

    xb_SaveQuadStates(0);
    r = xb_DrawQuadInternal(q);
    xb_RestoreQuadStates();
    return r;
}

s32 xb_DrawQuadSaved2(void* q) {
    s32 r;

    if (dword_4616AC) {
        return 0;
    }

    xb_SaveQuadStates(1);
    r = sub_00015E96(q);
    xb_RestoreQuadStates();
    return r;
}

s32 xb_DrawFilledRectSaved(void* q) {
    s32 r;

    if (dword_4616AC) {
        return 0;
    }

    xb_SaveQuadStates(0);
    r = xb_DrawRectInternal(q);
    xb_RestoreQuadStates();
    return r;
}

s32 xb_GetTextureHandleInfo(void* out, s32 handle) {
    if (handle == 0) {
        return 0;
    }

    memcpy(out, D_0043FF90 + handle * 0xD4, 0x48);
    return 1;
}

s32 XB_STDCALL xb_CreatePalette(s32 size, void** out) {
    void* p = D3DDevice_CreatePalette2(size);

    *out = p;
    return p != 0 ? 0 : 0x8007000E;
}

s32 XB_STDCALL xb_GetLevelDesc(s32 a, s32 b, s32 c) {
    sub_00184EF0(a, b, c);
    return 0;
}

s32 XB_STDCALL xb_LockPalette(void* pal, s32* out, s32 flags) {
    *out = D3DPalette_Lock2(pal, flags);
    return 0;
}

void xb_PADSetConfig(s32 i, s16 a, s16 b, s16 c) {
    D_00795768[i].a = a;
    D_00795768[i].b = b;
    D_00795768[i].c = c;
}

void xb_PADClearVibration(void) {
    memset(D_0079579C, 0, 0x10);
    memset(D_00795788, 0, 8);
    memset(D_00795790, 0, 8);
}

void xb_PADVibrationTick(void) {
    u32 i;

    for (i = 0; i < 4; i++) {
        if (D_0079579C[i]) {
            D_0079579C[i]--;
        } else {
            D_00795790[i] = 0;
            D_00795788[i] = 0;
        }
    }
}

s32 xb_PADSetVibration(s32 pad, s32 level, u32 time) {
    u32 v = (level << 13) + 0x1FFF;

    if ((u16)v > 0xFFFF) {
        v = 0xFFFF;
    }

    if (pad >= 0 && pad < 4) {
        D_00795790[pad] = v;
        D_00795788[pad] = v;
        D_0079579C[pad] = time;
        return 1;
    }

    return 0;
}

s32 xb_PADInit(void) {
    s32 i;

    sub_00211EF7(D_00795C04, 0);

    if (xb_PADOpenDevices(D_00795C00) < 0) {
        return 0;
    }

    for (i = 0; i < 4; i++) {
        *(s32*)(D_007957B4 + i * 0x34) = *(s32*)(D_0043EA04 + i * 0xE0);
    }

    xb_PADClearVibration();
    return 1;
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

void xb_PrintClear(void) {
    u8* p = D_00795C14;
    u32* q = (u32*)(p + 0x142);
    s32 i;

    for (i = 0; i < 0xF40; i++) {
        q[i] = 0xFF00FF;
    }

    *(s32*)(p + 0x3E44) = 0;
    *(s32*)(p + 0x48) = 0;
    *(s32*)(p + 0x4C) = 0;
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
