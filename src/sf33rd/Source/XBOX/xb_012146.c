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
typedef struct {
    s32 pitch;
    void* bits;
} XB_LOCKEDRECT;
typedef struct {
    s32 d[7];
} XB_LEVELDESC;
typedef struct {
    s32 d[0x12];
} XB_IMAGEINFO;
typedef struct {
    s32 d[4];
    s32 bits;
    s32 e[0xD];
} XB_PALINFO;
typedef struct {
    XB_PALINFO info;
    void* pal;
} XB_PALSLOT;
typedef struct {
    u8 pad0[0x24];
    u8* pal_buf;
    u8 pad28[0x3E20];
    s32 tex;
    s32 pal[16];
} XB_PRINTWORK;
typedef struct {
    u8 pad0[0x10];
    u8* ptr;
} XB_PLCTX;
typedef struct {
    f32 m[4][4];
} XB_MATRIX;
typedef struct {
    s32 x;
    s32 y;
    s32 w;
    s32 h;
    f32 min_z;
    f32 max_z;
} XB_VIEWPORT;
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
s32 xb_PoolAllocAligned(u8* pool, s32 block, s32 flags);
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
s32 xb_ApplyRenderFlagChanges(s32 changed, s32 flags);
void xb_SetViewportRect4(void* m, s32 x, s32 y, s32 w, s32 h, f32 zmin, f32 zmax);
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
s32 XB_STDCALL sub_0019860A(s32 a0, s32 a1, s32 a2);
static u8* D_00795C14;
extern s32 D_00795C10;
s32 XB_STDCALL DirectSoundCreate(void* guid, s32* ds, void* outer);
s32 XB_STDCALL DirectSoundUseFullHRTF(void);
extern char D_0021CCC4[];
extern char D_0021CCA4[];
extern const char* D_00795C0C;
void xb_adxm_SetupFileSystems(void* p);
void xb_adxm_CallIfSet(const char* path, s32 a, s32 b, s32 c);
void xb_adxm_SetRnaInterface(s32 ds);
void xb_adxm_SetSoundCallback(s32 cb);
extern u8 D_00474DA0[];
s32 xb_ConvertImagePixels(u8* img, s32 src);
extern char D_002197EC[];
s32 XB_STDCALL D3DTexture__LockRect(void* tex, s32 level, XB_LOCKEDRECT* lr, void* rect, s32 flags);
s32 XB_STDCALL XGSwizzleRect(void* src, s32 pitch, void* rect, void* dst, s32 w, s32 h, void* point, s32 bpp);
s32 XBUtil_LoadFile(s32 a, s32 b, s32* out);
s32 xb_PrintNextLine(void);
void xb_PrintDrawQueued(void);
extern u8 D_0021CBD8[];
s32 xb_MapTextureFormat(s32 fmt);
s32 XB_STDCALL D3DDevice__CreateTexture(s32 w, s32 h, s32 levels, s32 usage, s32 fmt, s32 pool, s32* out);
void xb_FillTextureDesc(XB_IMAGEINFO* dst, XB_LEVELDESC* desc);
extern XB_PALSLOT D_0044D3A8[];
s32 flCreateTextureHandle(void* bits, u32 attribute);
s32 flCreatePaletteHandle(void* bits, s32 flag);
extern u8 D_00321F10[];
extern XB_PLCTX D_00321EC8;
void flUnlockPalette(u32 th);
extern u32 D3D_g_RenderState[];
extern u32 D3D_g_DeferredTextureState[];
void XB_STDCALL D3DDevice_SetVertexData2f(s32 reg, f32 a, f32 b);
s32 flSetRenderState(s32 state, u32 value);
s32 sub_0009B78F(s32 flags);
typedef struct {
    f32 v[4];
} XB_COLORVALUE;
typedef struct {
    f32 v[3];
} XB_VECTOR3;
/* D3DLIGHT8 */
typedef struct {
    s32 type;
    XB_COLORVALUE diffuse;
    XB_COLORVALUE specular;
    XB_COLORVALUE ambient;
    XB_VECTOR3 position;
    XB_VECTOR3 direction;
    f32 range;
    f32 falloff;
    f32 att0;
    f32 att1;
    f32 att2;
    f32 theta;
    f32 phi;
} XB_D3DLIGHT;
/* the game's light, as xb_SetLight is given it */
typedef struct {
    s32 type;
    XB_COLORVALUE diffuse;
    XB_COLORVALUE specular;
    XB_COLORVALUE ambient;
    XB_VECTOR3 direction;
    XB_VECTOR3 position;
    f32 att0;
    f32 att1;
    f32 att2;
    f32 range;
    f32 theta;
    f32 phi;
    f32 falloff;
} XB_LIGHT;
extern XB_D3DLIGHT D_004616B8[3];
extern XB_LIGHT D_00461728[1];
XB_VECTOR3* XB_STDCALL XGVec3Normalize(XB_VECTOR3* out, const XB_VECTOR3* v);
extern XB_MATRIX D_004617F0[];
extern f32 D_00462070;
extern f32 D_00462084;
extern f32 D_00462098;
extern f32 D_004620A0;
extern f32 D_004620A4;
extern f32 D_004620A8;
XB_MATRIX* XB_STDCALL XGMatrixPerspectiveFovLH(XB_MATRIX* out, f32 fovy, f32 aspect, f32 zn, f32 zf);

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

static void xb_ReadRenderState(u32 state, u32* value) {
    *value = D3D_g_RenderState[state];
}

static void xb_ReadTextureStageState(u32 stage, u32 state, u32* value) {
    *value = D3D_g_DeferredTextureState[(stage << 5) + state];
}

s32 XB_STDCALL xb_GetRenderState(u32 state, u32* value) {
    xb_ReadRenderState(state, value);
    return 0;
}

s32 XB_STDCALL xb_GetTextureStageState(u32 stage, u32 state, u32* value) {
    xb_ReadTextureStageState(stage, state, value);
    return 0;
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

s32 xb_WorkPoolAlloc(s32 block) {
    return xb_PoolAllocAligned(D_00463C10, block, 0);
}

s32 xb_WorkPoolGetBlock(s32* block) {
    return xb_PoolGetBlock(D_00463C10, 0, block);
}

s32 xb_WorkPoolUsedSize(void) {
    return xb_PoolUsedSize(D_00463C10);
}

void xb_memset_bytes(void* p, s32 v, s32 n) {
    if (n > 0) {
        memset(p, v, n);
    }
}

s32 flLogOut(const char* fmt, ...) {
    char buf[0x800];
    va_list ap;

    va_start(ap, fmt);
    vsprintf(buf, fmt, ap);
    OutputDebugStringA(buf);
    return 1;
}

s32 xb_ConvertLightType(s32 type) {
    (void)type;
    return 0x3;
}

/* xb_SetLight 0x13F42.
 *
 * Keeps a copy of the game's light and fills the D3D light from it
 * (always directional), with its direction normalized. Only light 0. */

s32 xb_SetLight(s32 i, XB_LIGHT* in) {
    XB_D3DLIGHT* l;

    if (i >= 1 || i < 0) {
        return 0;
    }

    D_00461728[i] = *in;
    l = &D_004616B8[i];
    memset(l, 0, sizeof(XB_D3DLIGHT));
    l->type = xb_ConvertLightType(in->type);
    l->diffuse = in->diffuse;
    l->specular = in->specular;
    l->ambient = in->ambient;
    l->position = in->position;
    l->direction = in->direction;
    XGVec3Normalize(&l->direction, &l->direction);
    l->range = in->range;
    l->att0 = in->att0;
    l->att1 = in->att1;
    l->att2 = in->att2;
    l->falloff = in->falloff;
    l->theta = in->theta;
    l->phi = in->phi;
    return 1;
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

/* xb_SaturateColor 0x14117.
 *
 * D3DXCOLOR's conversion to a D3DCOLOR (a C++ operator, this in ecx):
 * each channel clamped to 0..1 and scaled to 0..255, rounded. Retail
 * rounds with cvtss2si. */

u32 XB_FASTCALL xb_SaturateColor(const XB_COLORVALUE* c) {
    u32 r = c->v[0] >= 1.0f ? 0xFF : c->v[0] <= 0.0f ? 0 : (u32)(c->v[0] * 255.0f + 0.5f);
    u32 g = c->v[1] >= 1.0f ? 0xFF : c->v[1] <= 0.0f ? 0 : (u32)(c->v[1] * 255.0f + 0.5f);
    u32 b = c->v[2] >= 1.0f ? 0xFF : c->v[2] <= 0.0f ? 0 : (u32)(c->v[2] * 255.0f + 0.5f);
    u32 a = c->v[3] >= 1.0f ? 0xFF : c->v[3] <= 0.0f ? 0 : (u32)(c->v[3] * 255.0f + 0.5f);

    return (a << 24) | (r << 16) | (g << 8) | b;
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

/* xb_ApplyFlagsF00 0x14357.
 *
 * Lighting: 0 turns it off; 0x100 and 0x300 light with one directional
 * or point light, 0x200 and 0x400 with three. */

s32 xb_ApplyFlagsF00(s32 flags) {
    switch (flags & 0xF00) {
    case 0:
        xb_SetRenderState(0x66, 0);
        xb_LightEnable(0, 0);
        xb_LightEnable(1, 0);
        xb_LightEnable(2, 0);
        break;

    case 0x100:
        D_004616B8[0].type = 3;
        xb_SetRenderState(0x66, 1);
        xb_LightEnable(0, 1);
        xb_LightEnable(1, 0);
        xb_LightEnable(2, 0);
        break;

    case 0x200:
        D_004616B8[0].type = 3;
        D_004616B8[1].type = 3;
        D_004616B8[2].type = 3;
        xb_SetRenderState(0x66, 1);
        xb_LightEnable(0, 1);
        xb_LightEnable(1, 1);
        xb_LightEnable(2, 1);
        break;

    case 0x300:
        D_004616B8[0].type = 1;
        xb_SetRenderState(0x66, 1);
        xb_LightEnable(0, 1);
        xb_LightEnable(1, 0);
        xb_LightEnable(2, 0);
        break;

    case 0x400:
        D_004616B8[0].type = 1;
        D_004616B8[1].type = 1;
        D_004616B8[2].type = 1;
        xb_SetRenderState(0x66, 1);
        xb_LightEnable(0, 1);
        xb_LightEnable(1, 1);
        xb_LightEnable(2, 1);
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

/* xb_ApplyRenderFlagChanges 0x14407.
 *
 * Applies each group of render flags that changed. The 0x3000 and
 * 0x20000 groups have nothing to set (the shared "return 1" body). */

s32 xb_ApplyRenderFlagChanges(s32 changed, s32 flags) {
    s32 r = 0;

    if (changed & 3) {
        r = xb_ApplyFlags03(flags);
    }

    if (changed & 0x1C) {
        r |= xb_ApplyFlags1C(flags);
    }

    if (changed & 0x60) {
        r |= xb_ApplyFlags60(flags);
    }

    if (changed & 0xF00) {
        r |= xb_ApplyFlagsF00(flags);
    }

    if (changed & 0x3000) {
        r |= sub_0009B78F(flags);
    }

    if (changed & 0x18000) {
        r |= xb_ApplyFlags18000(flags);
    }

    if (changed & 0x20000) {
        r |= sub_0009B78F(flags);
    }

    return r;
}

void xb_UpdateRenderFlags(s32 flags) {
    xb_ApplyRenderFlagChanges(D_0043FE60 ^ flags, flags);
    D_0043FE60 = flags;
}

/* xb_SetMappedRenderState 0x144A3.
 *
 * The Xbox side of flSetRenderState: sets one of the library's render
 * states on the device. 4-7 bind a texture handle to a stage (with its
 * palette in the high half), 8-0xB a stage's addressing, 0x16, 0x17 and
 * 0x19 the world, view and projection matrices (kept in
 * D_004617F0[0x20..0x23]), 0x18 the viewport (and the viewport matrix),
 * 0x5E the blend factors (source in the low nibble, destination in the
 * next), 0x65 the render target (-1 is the back buffer) and 0x67 the
 * ambient colour. Returns 1. */

extern s32 D_0043EE40[4];
extern s32 D_0043EE30[4];
extern u8 D_0044D3F0[];
extern s32 D_00474CC0;
extern s32 D_0043ECC4;
extern s32 D_00463BF0;
extern f32 D_00463C90;
extern f32 D_00463BF8;
extern s32 D_002ECA1C;
extern XB_VIEWPORT D_0043EDBC;
extern s32 D_0043FE68;
extern s32 D_00463C88;
extern void* D_00474CC4;
extern XB_COLORVALUE D_004617C8;
extern u32 D_00463C30;
void XB_STDCALL D3DDevice__SetViewport(XB_VIEWPORT* vp);
void XB_STDCALL D3DDevice__SetRenderTarget(void* target, void* zbuf);

s32 xb_SetMappedRenderState(s32 state, u32 value) {
    XB_MATRIX m;
    XB_VIEWPORT vp;
    XB_COLORVALUE col;
    XB_VIEWPORT* in;
    void* surf;
    s32 i;
    f32 f;

    switch (state) {
    case 4:
    case 5:
    case 6:
    case 7:
        i = state - 4;
        D_0043EE40[i] = value;
        xb_BindTextureHandle(i, value & 0xFFFF);

        if (value & 0xFFFF0000) {
            xb_SetPalette(0, *(void**)(D_0044D3F0 + (value >> 16) * 0x4C));
        }

        break;

    case 8:
    case 9:
    case 0xA:
    case 0xB:
        i = state - 8;
        D_0043EE30[i] = value;
        xb_SetTextureStageState(i, 0xC, value == 1 ? 4 : value == 2 ? 7 : 1);
        xb_SetTextureStageState(i, 0xE, 2);
        xb_SetTextureStageState(i, 0xF, 1);
        break;

    case 0xD:
        switch (value & 0xC00) {
        case 0:
            xb_SetRenderState(0x4A, 0x8006);
            break;
        case 0x400:
            xb_SetRenderState(0x4A, 0x800A);
            break;
        case 0x800:
            xb_SetRenderState(0x4A, 0x800B);
            break;
        }

        break;

    case 0xE:
        D_00474CC0 = value;
        D_0043ECC4 = value;
        xb_SetRenderState(0x73, value);
        break;

    case 0xF:
        D_00463BF0 = value;
        xb_SetRenderState(0x8A, value);
        break;

    case 0x10:
        D_00463C90 = *(f32*)&value;
        f = -*(f32*)&value;
        xb_SetRenderState(0x5E, *(s32*)&f);
        break;

    case 0x11:
        D_00463BF8 = *(f32*)&value;
        f = -*(f32*)&value;
        xb_SetRenderState(0x5F, *(s32*)&f);
        break;

    case 0x12:
        if (value == 0) {
            xb_SetRenderState(0x5C, 0);
        } else if (value == 0x8000) {
            xb_SetRenderState(0x5D, 3);
            xb_SetRenderState(0x5C, 1);
        }

        break;

    case 0x14:
        D_002ECA1C = value;
        break;

    case 0x15:
        xb_SetRenderState(0x69, value == 0);
        break;

    case 0x16:
        xb_CopyMatrix(&m, 0, (void*)value);
        D_004617F0[0x21] = m;
        xb_SetTransform(0, &D_004617F0[0x21]);
        break;

    case 0x17:
        xb_CopyMatrix(&m, 0, (void*)value);
        D_004617F0[0x20] = m;
        xb_SetTransform(1, &D_004617F0[0x20]);
        break;

    case 0x18:
        in = (XB_VIEWPORT*)value;
        D_0043EDBC = *in;
        vp.x = in->x;
        vp.y = in->y;
        vp.w = in->w;
        vp.h = in->h;
        vp.min_z = in->min_z;
        vp.max_z = in->max_z;
        D3DDevice__SetViewport(&vp);
        xb_MatrixIdentity(&D_004617F0[0x22].m[0][0]);
        D_004617F0[0x22].m[0][0] = (f32)in->w / 2.0f;
        D_004617F0[0x22].m[1][1] = (f32)-in->h / 2.0f;
        D_004617F0[0x22].m[2][2] = in->max_z - in->min_z;
        D_004617F0[0x22].m[3][0] = (f32)(in->w / 2) + (f32)in->x;
        D_004617F0[0x22].m[3][1] = (f32)(in->h / 2) + (f32)in->y;
        D_004617F0[0x22].m[3][2] = in->min_z;
        D_004617F0[0x22].m[3][3] = 1.0f;
        break;

    case 0x19:
        xb_CopyMatrix(&m, 0, (void*)value);
        D_004617F0[0x23] = m;
        break;

    case 0x5E:
        switch (value & 0xF) {
        case 0x0:
            xb_SetRenderState(0x3E, 0x0);
            break;
        case 0x1:
            xb_SetRenderState(0x3E, 0x1);
            break;
        case 0x2:
            xb_SetRenderState(0x3E, 0x302);
            break;
        case 0x3:
            xb_SetRenderState(0x3E, 0x303);
            break;
        case 0x4:
            xb_SetRenderState(0x3E, 0x304);
            break;
        case 0x5:
            xb_SetRenderState(0x3E, 0x305);
            break;
        case 0x6:
            xb_SetRenderState(0x3E, 0x300);
            break;
        case 0x7:
            xb_SetRenderState(0x3E, 0x301);
            break;
        case 0x8:
            xb_SetRenderState(0x3E, 0x306);
            break;
        case 0x9:
            xb_SetRenderState(0x3E, 0x307);
            break;
        }

        switch (value & 0xF0) {
        case 0x0:
            xb_SetRenderState(0x3F, 0x0);
            break;
        case 0x10:
            xb_SetRenderState(0x3F, 0x1);
            break;
        case 0x20:
            xb_SetRenderState(0x3F, 0x302);
            break;
        case 0x30:
            xb_SetRenderState(0x3F, 0x303);
            break;
        case 0x40:
            xb_SetRenderState(0x3F, 0x304);
            break;
        case 0x50:
            xb_SetRenderState(0x3F, 0x305);
            break;
        case 0x60:
            xb_SetRenderState(0x3F, 0x300);
            break;
        case 0x70:
            xb_SetRenderState(0x3F, 0x301);
            break;
        case 0x80:
            xb_SetRenderState(0x3F, 0x306);
            break;
        case 0x90:
            xb_SetRenderState(0x3F, 0x307);
            break;
        }

        break;

    case 0x60:
        D_0043FE68 = value;
        D_00463C88 = value;
        xb_SetRenderState(0x3D, value);
        break;

    case 0x65:
        if (value == (u32)-1) {
            D3DDevice__SetRenderTarget(D_00474CC4, 0);
        } else {
            xb_GetSurfaceLevel(*(void**)(D_00440020 + value * 0xD4), 0, &surf);
            D3DDevice__SetRenderTarget(surf, 0);
            xb_ReleaseResource((s32)surf);
        }

        break;

    case 0x67:
        xb_ColorToFloat4(col.v, 0, value);
        D_004617C8 = col;
        D_00463C30 = xb_SaturateColor(&D_004617C8);
        break;

    case 0x68:
        xb_SetTextureStageState(0, 6, value);
        break;
    }

    return 1;
}

/* flSetRenderState 0x14D2F.
 *
 * The library's render state call. 0x1A-0x39 set a matrix (0 marks it
 * unset in D_0043EE50), 0x3A-0x59 a material record and 0x5A-0x5C a
 * light. The others either go straight to the device
 * (xb_SetMappedRenderState) or change bits of the render flags
 * (D_00463C84, applied by xb_UpdateRenderFlags) or of the blend state
 * (D_00474CB0 against the current D_004616B0, applied by
 * xb_SetBlendMode). */

extern u32 D_004616B0;
extern u32 D_00474CB0;
extern u32 D_0043EE50;
extern u32 D_00463C84;
void xb_SetBlendMode(u32 cur, u32 next);

s32 flSetRenderState(s32 func, u32 value) {
    XB_MATRIX m;
    u32 bit;

    D_00474CB0 = D_004616B0;

    if ((u32)(func - 0x1A) <= 0x1F) {
        bit = 1 << (func - 0x1A);

        if (value != 0) {
            D_0043EE50 |= bit;
            xb_CopyMatrix(&m, 0, (void*)value);
            D_004617F0[func - 0x1A] = m;
        } else {
            D_0043EE50 &= ~bit;
        }

        return 1;
    }

    if ((u32)(func - 0x3A) <= 0x1F) {
        xb_CopyStateRecord(func - 0x3A, (void*)value);
        return 1;
    }

    if ((u32)(func - 0x5A) <= 2) {
        xb_SetLight(func - 0x5A, (XB_LIGHT*)value);
        return 1;
    }

    switch (func) {
    case 0:
        D_00463C84 = (D_00463C84 & ~0x60) | value;
        break;

    case 1:
        D_00463C84 &= ~0xF00;

        switch (value) {
        case 0x100:
        case 0x200:
        case 0x300:
        case 0x400:
        case 0x500:
        case 0x600:
        case 0x700:
        case 0x800:
            D_00463C84 |= value;
            break;
        }

        break;

    case 2:
        D_00463C84 &= ~0x1C;

        switch (value) {
        case 4:
        case 8:
        case 0xC:
        case 0x10:
        case 0x14:
        case 0x18:
            D_00463C84 |= value;
            break;
        }

        break;

    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 0xA:
    case 0xB:
    case 0xE:
    case 0xF:
    case 0x10:
    case 0x11:
    case 0x14:
    case 0x16:
    case 0x17:
    case 0x18:
    case 0x19:
    case 0x60:
    case 0x67:
    case 0x68:
        xb_SetMappedRenderState(func, value);
        break;

    case 0xD:
        D_00474CB0 = (D_004616B0 & ~0xC00) | value;
        break;

    case 0x12:
        D_00463C84 = (D_00463C84 & ~0x18000) | value;
        break;

    case 0x13:
        if (value == 0x100 || value == 0x200) {
            D_00474CB0 = D_004616B0 | value;
        }

        break;

    case 0x15:
        D_00463C84 &= ~3;

        if (value != 0 && value == 2) {
            D_00463C84 |= 2;
        }

        break;

    case 0x5D:
        D_00463C84 &= 0xFFFFFF;
        D_00463C84 |= value;
        break;

    case 0x5E:
        D_00474CB0 &= ~0xFF;
        D_00474CB0 |= value;
        break;

    case 0x5F:
        D_00474CB0 = (D_004616B0 & ~0x380000) | (value << 19);
        break;

    case 0x61:
        D_00474CB0 = D_004616B0 & ~0x1000000;

        if (value != 0) {
            D_00474CB0 |= 0x1000000;
        }

        break;

    case 0x62:
        D_00463C84 &= ~0x4000;

        if (value != 0) {
            D_00463C84 |= 0x4000;
        }

        break;

    case 0x63:
        D_00474CB0 = (D_004616B0 & ~0x10000) | value;
        break;

    case 0x64:
        D_00474CB0 = (D_004616B0 & ~0x60000) | value;
        break;

    case 0x66:
        D_00463C84 &= ~0x20000;

        if (value != 0) {
            D_00463C84 |= 0x20000;
        }

        break;

    case 0x6B:
        D_00474CB0 = (D_004616B0 & ~0xC00000) | value;
        break;

    case 0x6C:
        D_00474CB0 = D_004616B0 & ~0x8000;

        if (value != 0) {
            D_00474CB0 |= 0x8000;
        }

        break;

    case 0x6D:
        D_00474CB0 = (D_004616B0 & ~0x7000) | (value << 12);
        break;
    }

    if (D_0043FE60 != D_00463C84) {
        xb_UpdateRenderFlags(D_00463C84);
    }

    if (D_004616B0 != D_00474CB0) {
        xb_SetBlendMode(D_004616B0, D_00474CB0);
    }

    return 1;
}

void flmatMakeViewport(s32 a, s32 b, s32 c, s32 d, s32 e, f32 f, f32 g) {
    xb_SetViewportRect4((void*)a, b, c, d, e, f, g);
}

void xb_SetLightByType(s32 type) {
    XB_VIEWPORT vp;

    switch (type) {
    case 0x20:
        flSetRenderState(0x17, (u32)&D_004617F0[0x20]);
        break;

    case 0x21:
        flSetRenderState(0x16, (u32)&D_004617F0[0x21]);
        break;

    case 0x22:
        vp.x = D_004620A0 - D_00462070;
        vp.y = D_00462084 + D_004620A4;
        vp.w = D_00462070 * 2.0f;
        vp.h = 0.5f - D_00462084 * 2.1428571f;
        vp.min_z = D_004620A8;
        vp.max_z = D_00462098 + D_004620A8;
        flSetRenderState(0x18, (u32)&vp);
        break;
    }
}

void xb_SetLightAttenuation(f32 v) {
    sub_00015BB6(v);
}

void xb_SetLightFloat(s32 type, f32 a, f32 b, f32 c, f32 d) {
    XGMatrixPerspectiveFovLH(&D_004617F0[type], c, d, b, a);
    xb_SetLightByType(type);
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

s32 XB_STDCALL xb_SetVertexData2f(s32 reg, f32 a, f32 b) {
    D3DDevice_SetVertexData2f(reg, a, b);
    return 0;
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

s32 xb_FormatForImage(u8* img) {
    s32 r = 6;

    switch (*(s32*)(img + 0x14)) {
    case 0:
    case 1:
        r = 0xB;
        break;

    case 2:
        if (*(s32*)(img + 0x3C) != 0) {
            r = *(s32*)(img + 0x3C) == 1 ? 2 : 4;
        } else {
            r = 5;
        }

        break;

    case 3:
    case 4:
        r = *(s32*)(img + 0x3C) ? 6 : 7;
        break;
    }

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

s32 xb_ChooseTextureFormat(u8* img, s32 levels, s32 mode) {
    s32 w;
    s32 h;
    s32 fmt;
    s32 tex;

    if ((w = *(s32*)(img + 4)) > 640 || (h = *(s32*)(img + 8)) > 640) {
        return 0;
    }

    if (mode == 6) {
        fmt = (*(s32*)(img + 0x14) == 4) ? 0x2E : 0x30;
    } else {
        fmt = xb_FormatForImage(img);

        if (mode == 7) {
            fmt = xb_MapTextureFormat(fmt);
        }
    }

    D3DDevice__CreateTexture(w, h, levels, 0, fmt, 0, &tex);
    return tex;
}

void xb_LockTextureLevel(XB_IMAGEINFO* src, XB_IMAGEINFO* dst, u8* tex, s32 level) {
    XB_LEVELDESC desc;

    xb_GetLevelDesc(*(s32*)(tex + 0x90), level, (s32)&desc);

    if (level == 0) {
        *(XB_LEVELDESC*)(tex + 0x94) = desc;
    }

    xb_FillTextureDesc(dst, &desc);
    dst->d[0] = src->d[0];
    *(XB_IMAGEINFO*)(tex + 0x48) = *src;
    *(XB_IMAGEINFO*)tex = *dst;
}

s32 xb_ConvertAndSwizzleImage(s32 src, u8* img, u8* tex, s32 level) {
    XB_LOCKEDRECT lr;

    *(u8**)(img + 0x10) = D_00474DA0;

    if (xb_ConvertImagePixels(img, src) == 0) {
        flLogOut(D_002197EC);
        return 0;
    }

    D3DTexture__LockRect(*(void**)(tex + 0x90), level, &lr, 0, 0);

    if (*(s32*)(tex + 0x94) >= 0x10) {
        memcpy(lr.bits, *(void**)(img + 0x10), *(s32*)(img + 0x14) * *(s32*)(img + 8) * *(s32*)(img + 4));
    } else {
        XGSwizzleRect(*(void**)(img + 0x10), 0, 0, lr.bits, *(s32*)(img + 4), *(s32*)(img + 8), 0, *(s32*)(img + 0x14));
    }

    *(void**)(img + 0x10) = 0;
    return 1;
}

s32 flReleasePaletteHandle(s32 h) {
    if (D_0044D3A8[h].pal != 0) {
        xb_ReleaseResource((s32)D_0044D3A8[h].pal);
        D_0044D3A8[h].pal = 0;
    }

    return 1;
}

s32 flLockPalette(void* rect, u32 th, XB_PALINFO* out, s32 flag) {
    s32 bits;

    if (xb_LockPalette(D_0044D3A8[th].pal, &bits, 0) < 0) {
        return 0;
    }

    D_0044D3A8[th].info.bits = bits;
    *out = D_0044D3A8[th].info;
    return 1;
}

s32 xb_LoadFormatEntry(s32 a, s32 b) {
    s32 v;

    XBUtil_LoadFile(b, a, &v);
    return v;
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

u8 xb_PADTriggerToButton(u8* pad) {
    if (*(s16*)(pad + 4) < 0x10) {
        return 0;
    }

    return *(D_0021CBD8 - (s32)(*(s16*)(pad + 6) / -22.5f));
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

s32 XB_STDCALL xb_DirectSoundThunk(s32 a0, s32 a1, s32 a2) {
    return sub_0019860A(a0, a1, a2);
}

s32 xb_CreateDirectSound(const char* path) {
    if (DirectSoundCreate(0, &D_00795C10, 0) < 0) {
        OutputDebugStringA(D_0021CCC4);
        while (1) {}
    }

    if (xb_DirectSoundThunk(D_00795C10, 0, 2) < 0) {
        OutputDebugStringA(D_0021CCA4);
        while (1) {}
    }

    D_00795C0C = path;
    xb_adxm_SetupFileSystems(&D_00795C0C);
    xb_adxm_CallIfSet(path, -1, 0, 0);
    xb_adxm_SetRnaInterface(D_00795C10);
    xb_adxm_SetSoundCallback(0);
    return DirectSoundUseFullHRTF();
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

void xb_PrintReset(void) {
    u8* p = D_00795C14;

    memset(p + 0x28, 0, 8);
    *(s16*)(p + 0x10) = 0;
    *(s16*)(p + 0x12) = 0;
    *(f32*)(p + 0x14) = 10.0f;
    p[0x1C] = p[4];
    p[0x1D] = p[8];
    *(s16*)(p + 0x1E) = 0;
    *(s32*)(p + 0x38) = 0;
    *(s32*)(p + 0x40) = 1;
    *(s32*)(p + 0x4C) = *(s32*)(p + 0x48);
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

void xb_PrintSetPalette(s32 page, u32 c0, u32 c1, u32 c2, u32 c3) {
    u8 rgb[12];
    XB_PALINFO ctx;
    u8* dst;
    u8* src;
    u32* d;
    u32* s;
    u8 a;
    u8 r;
    u8 g;
    u8 b;
    s32 i;
    s32 ofs;
    u32 th;

    page %= 16;
    ofs = page * 0x40;
    dst = *(u8**)(D_00795C14 + 0x24) + ofs;
    a = (c0 & 0xFF000000) ? 0xFF : 0;

    for (i = 0; i < 3; i++) {
        rgb[0 * 3 + i] = c0;
        c0 >>= 8;
    }

    for (i = 0; i < 3; i++) {
        rgb[1 * 3 + i] = c1;
        c1 >>= 8;
    }

    for (i = 0; i < 3; i++) {
        rgb[2 * 3 + i] = c2;
        c2 >>= 8;
    }

    for (i = 0; i < 3; i++) {
        rgb[3 * 3 + i] = c3;
        c3 >>= 8;
    }

    for (i = 0; i < 4; i++) {
        r = rgb[i * 3];
        g = rgb[i * 3 + 1];
        b = rgb[i * 3 + 2];
        *dst++ = r;
        *dst++ = g;
        *dst++ = b;

        if ((i == 0) | a) {
            *dst = a;
        } else if (r == 0 && g == 0 && b == 0) {
            *dst = 0;
        } else {
            *dst = 0xFF;
        }

        dst++;
    }

    th = ((u32*)(D_00795C14 + 0x3E4C))[page];

    if (th != 0) {
        flLockPalette(0, th, &ctx, 2);
        s = (u32*)(*(u8**)(D_00795C14 + 0x24) + ofs);
        d = (u32*)ctx.bits;

        for (i = 0; i < 4; i++) {
            *d++ = *s++;
        }

        flUnlockPalette(th);
    }
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

s32 xb_PrintLoadFont(void) {
    s32 i;

    ((XB_PRINTWORK*)D_00795C14)->tex = flCreateTextureHandle(D_00321F10, 3);

    for (i = 0; i < 16; i++) {
        D_00321EC8.ptr = ((XB_PRINTWORK*)D_00795C14)->pal_buf + i * 0x40;
        ((XB_PRINTWORK*)D_00795C14)->pal[i] = flCreatePaletteHandle(&D_00321EC8, 3);
    }

    xb_PrintSetPalette(0, 0, 0xFF333333, 0xFF999999, 0xFFFFFFFF);
    xb_PrintClear();
    return ((XB_PRINTWORK*)D_00795C14)->tex;
}

s32 XB_FASTCALL xb_SjisToIndex(u32 code) {
    u32 hi = code >> 8 & 0xFF;
    u32 lo = code & 0xFF;

    if (hi >= 0x81 && hi <= 0x9F) {
        hi -= 0x81;
    } else if (hi >= 0xE0 && hi <= 0xEF) {
        hi -= 0xC1;
    }

    hi <<= 1;

    if (lo >= 0x40 && lo <= 0x7E) {
        lo -= 0x40;
    } else if (lo >= 0x80 && lo <= 0x9E) {
        lo -= 0x41;
    } else if (lo >= 0x9F && lo <= 0xFC) {
        lo -= 0x9F;
        hi++;
    }

    return (hi << 8) + lo + 0x2121;
}

void xb_PrintInit(u8* buf) {
    u8* w = buf;
    s32 i;

    memset(w, 0, 0xD400);
    buf += 0x4000;
    *(u8**)(w + 0x24) = buf;
    D_00795C14 = w;
    buf += 0x400;

    for (i = 0; i < 2; i++) {
        ((u8**)(w + 0x30))[i] = buf;
        buf += 0xA00;
    }

    *(u8**)(w + 0x3C) = buf;
    *(s32*)(w + 4) = 0x16;
    *(s32*)(w + 8) = 0x16;
    *(s32*)D_00795C14 = xb_PrintLoadFont();
    xb_PrintSetPage(-1);
}

void xb_PrintResetAll(void) {
    xb_PrintReset();
    xb_PrintClear();
}

s32 XB_FASTCALL xb_PrintSjisIndex(u32 code) {
    s32 r = xb_SjisToIndex(code);
    s32 idx = (r >> 8) * 94 + (r & 0xFF) - 0xC3F;

    if (idx >= 0x1E80) {
        return -1;
    }

    return idx;
}

void xb_PrintDrawPending(void) {
    *(s32*)(D_00795C14 + 0x44) = -1;

    if (xb_PrintNextLine()) {
        xb_PrintClear();
        xb_PrintNextLine();
    }

    xb_PrintDrawQueued();
}
