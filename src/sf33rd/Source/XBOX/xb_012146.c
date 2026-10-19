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
f32 xb_sinf(f32 v);
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
s32 xb_DrawTexQuadInternal(void* q);
s32 xb_DrawRectInternal(void* q);
/* A texture handle's entry. */
typedef struct {
    XB_IMAGEINFO info;
    XB_IMAGEINFO src;
    void* tex;
    XB_LEVELDESC desc;
    XB_LOCKEDRECT lr;
    s32* rectp;
    s32 rect[4];
    s32 unkCC;
    s32 mode;
} XB_TEXENTRY;
extern XB_TEXENTRY D_0043FF90[];
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
s32 XBInput_CreateGamepads(void* p);
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
s32 XBUtil_CreateVertexShader(const char* file, const u32* decl, u32* out);
s32 xb_PrintQueueText(void);
void xb_PrintDrawQueued(void);
extern u8 D_0021CBD8[];
s32 xb_MapTextureFormat(s32 fmt);
s32 xb_FormatInfo(XB_LEVELDESC* desc, u32* a, u32* r, u32* g, u32* b);
s32 XB_STDCALL D3DDevice__CreateTexture(s32 w, s32 h, s32 levels, s32 usage, s32 fmt, s32 pool, s32* out);
void xb_FillTextureDesc(XB_IMAGEINFO* dst, XB_LEVELDESC* desc);
extern XB_PALSLOT D_0044D3A8[];
s32 flCreateTextureHandle(void* bits, u32 attribute);
s32 flCreatePaletteHandle(void* bits, s32 flag);
extern u8 D_00321F10[];
extern XB_PLCTX D_00321EC8;
s32 flUnlockPalette(u32 th);
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

/* xb_SetTextureStageState 0x12CEE.
 *
 * IDirect3DDevice8::SetTextureStageState (the library function takes
 * its arguments in registers). */

void D3DDevice_SetTextureStageState(s32 stage, s32 state, s32 value);

s32 XB_STDCALL xb_SetTextureStageState(s32 stage, s32 state, s32 value) {
    D3DDevice_SetTextureStageState(stage, state, value);
    return 0;
}

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

/* cvtss2si: round to nearest, as retail converts these colours. */
#if defined(_MSC_VER)
/* The two SSE intrinsics, declared here rather than through xmmintrin.h,
 * which brings in malloc.h's free. */
typedef union __declspec(intrin_type) __declspec(align(16)) __m128 {
    float m128_f32[4];
} __m128;
extern int _mm_cvt_ss2si(__m128 a);
extern __m128 _mm_set_ss(float a);
#define XB_RINT(x) _mm_cvt_ss2si(_mm_set_ss(x))
#else
#define XB_RINT(x) ((s32)__builtin_lrintf(x))
#endif

u32 XB_FASTCALL xb_SaturateColor(const XB_COLORVALUE* c) {
    f32 r = c->v[0] >= 1.0f ? 255.0f : c->v[0] <= 0.0f ? 0.0f : c->v[0] * 255.0f + 0.5f;
    f32 g = c->v[1] >= 1.0f ? 255.0f : c->v[1] <= 0.0f ? 0.0f : c->v[1] * 255.0f + 0.5f;
    f32 b = c->v[2] >= 1.0f ? 255.0f : c->v[2] <= 0.0f ? 0.0f : c->v[2] * 255.0f + 0.5f;
    f32 a = c->v[3] >= 1.0f ? 255.0f : c->v[3] <= 0.0f ? 0.0f : c->v[3] * 255.0f + 0.5f;

    return (XB_RINT(a) << 24) | (XB_RINT(r) << 16) | (XB_RINT(g) << 8) | XB_RINT(b);
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
    XB_ALIGN16 XB_MATRIX m;
    XB_ARG arg;
    XB_VIEWPORT vp;
    XB_COLORVALUE col;
    XB_VIEWPORT* in;
    void* surf;
    s32 i;
    s32 f;
    f32 ff;

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
        switch (value) {
        case 1:
            f = 4;
            break;
        case 2:
            f = 7;
            break;
        default:
            f = 1;
            break;
        }

        D_0043EE30[i] = value;
        xb_SetTextureStageState(i, 0xC, f);
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
        ff = -*(f32*)&value;
        xb_SetRenderState(0x5E, *(s32*)&ff);
        break;

    case 0x11:
        D_00463BF8 = *(f32*)&value;
        ff = -*(f32*)&value;
        xb_SetRenderState(0x5F, *(s32*)&ff);
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
        if (value == 0) {
            xb_SetRenderState(0x69, 1);
        } else {
            xb_SetRenderState(0x69, 0);
        }

        break;

    case 0x16:
        arg.v = value;
        ((void* (XB_FASTCALL*)(void*, XB_ARG))xb_CopyMatrix)(&m, arg);
        D_004617F0[0x21] = m;
        xb_SetTransform(0, &D_004617F0[0x21]);
        break;

    case 0x17:
        arg.v = value;
        ((void* (XB_FASTCALL*)(void*, XB_ARG))xb_CopyMatrix)(&m, arg);
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
        arg.v = value;
        ((void* (XB_FASTCALL*)(void*, XB_ARG))xb_CopyMatrix)(&m, arg);
        D_004617F0[0x23] = m;
        break;

    case 0x5E:
        switch (value & 0xF) {
        case 0x1:
            xb_SetRenderState(0x3E, 0x1);
            break;
        case 0x0:
            xb_SetRenderState(0x3E, 0x0);
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
        arg.v = value;
        ((f32* (XB_FASTCALL*)(f32*, XB_ARG))xb_ColorToFloat4)(col.v, arg);
        D_004617C8 = col;
        D_00463C30 = xb_SaturateColor(&D_004617C8);
        break;

    case 0x68:
        xb_SetTextureStageState(0, 6, value);
        break;
    }

    return 1;
}

/* xb_SetBlendMode 0x149AE.
 *
 * Applies the blend-state bits that differ between cur and next and
 * makes next current: the blend factors (0xFF), blend op (0xC00), the
 * texture colour/alpha ops (0x10000, 0x60000), alpha test and its
 * function (0x380000), the depth function (0x7000), depth writes
 * (0x8000), stage 0 texture addressing (0xC00000) and dithering
 * (0x1000000). */

extern u32 D_004616B0;

void xb_SetBlendMode(u32 cur, u32 next) {
    u32 changed = cur ^ next;

    D_004616B0 = next;

    if (changed & 0xF) {
        switch (next & 0xF) {
        case 0x1:
            xb_SetRenderState(0x3E, 0x1);
            break;
        case 0x0:
            xb_SetRenderState(0x3E, 0x0);
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
    }

    if (changed & 0xF0) {
        switch (next & 0xF0) {
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
    }

    if (changed & 0xC00) {
        switch (next & 0xC00) {
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
    }

    if (changed & 0x10000) {
        switch (next & 0x10000) {
        case 0:
            xb_SetTextureStageState(0, 4, 2);
            xb_SetTextureStageState(0, 3, 2);
            break;
        case 0x10000:
            xb_SetTextureStageState(0, 4, 1);
            xb_SetTextureStageState(0, 3, 1);
            break;
        }
    }

    if (changed & 0x60000) {
        switch (next & 0x60000) {
        case 0:
            xb_SetTextureStageState(0, 0, 1);
            xb_SetTextureStageState(0, 1, 1);
            break;
        case 0x20000:
            xb_SetTextureStageState(0, 0, 3);
            xb_SetTextureStageState(0, 1, 3);
            break;
        case 0x40000:
            xb_SetTextureStageState(0, 0, 2);
            xb_SetTextureStageState(0, 1, 2);
            break;
        }
    }

    if (changed & 0x380000) {
        switch ((next >> 19) & 7) {
        case 0:
            xb_SetRenderState(0x3C, 1);
            xb_SetRenderState(0x3A, 0x200);
            break;
        case 1:
            xb_SetRenderState(0x3C, 1);
            xb_SetRenderState(0x3A, 0x201);
            break;
        case 2:
            xb_SetRenderState(0x3C, 1);
            xb_SetRenderState(0x3A, 0x202);
            break;
        case 3:
            xb_SetRenderState(0x3C, 1);
            xb_SetRenderState(0x3A, 0x203);
            break;
        case 4:
            xb_SetRenderState(0x3C, 1);
            xb_SetRenderState(0x3A, 0x204);
            break;
        case 5:
            xb_SetRenderState(0x3C, 1);
            xb_SetRenderState(0x3A, 0x205);
            break;
        case 6:
            xb_SetRenderState(0x3C, 1);
            xb_SetRenderState(0x3A, 0x206);
            break;
        case 7:
            xb_SetRenderState(0x3C, 0);
            xb_SetRenderState(0x3A, 0x207);
            break;
        }
    }

    if (changed & 0x7000) {
        switch ((next >> 12) & 7) {
        case 0:
            xb_SetRenderState(0x39, 0x200);
            break;
        case 1:
            xb_SetRenderState(0x39, 0x201);
            break;
        case 2:
            xb_SetRenderState(0x39, 0x202);
            break;
        case 3:
            xb_SetRenderState(0x39, 0x203);
            break;
        case 4:
            xb_SetRenderState(0x39, 0x204);
            break;
        case 5:
            xb_SetRenderState(0x39, 0x205);
            break;
        case 6:
            xb_SetRenderState(0x39, 0x206);
            break;
        case 7:
            xb_SetRenderState(0x39, 0x207);
            break;
        }
    }

    if (changed & 0x8000) {
        switch (next & 0x8000) {
        case 0:
            xb_SetRenderState(0x40, 0);
            break;
        case 0x8000:
            xb_SetRenderState(0x40, 1);
            break;
        }
    }

    if (changed & 0xC00000) {
        switch (next & 0xC00000) {
        case 0:
            xb_SetTextureStageState(0, 5, 0);
            break;
        case 0x400000:
            xb_SetTextureStageState(0, 5, 1);
            break;
        case 0x800000:
            xb_SetTextureStageState(0, 5, 2);
            break;
        }
    }

    if (changed & 0x1000000) {
        switch (next & 0x1000000) {
        case 0:
            xb_SetRenderState(0x3B, 0);
            break;
        case 0x1000000:
            xb_SetRenderState(0x3B, 1);
            break;
        }
    }
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

extern u32 D_00474CB0;
extern u32 D_0043EE50;
extern u32 D_00463C84;
void xb_SetBlendMode(u32 cur, u32 next);

s32 flSetRenderState(s32 func, u32 value) {
    XB_ALIGN16 XB_MATRIX m;
    XB_ARG arg;
    u32 bit;

    D_00474CB0 = D_004616B0;

    if ((u32)(func - 0x1A) <= 0x1F) {
        bit = 1 << (func - 0x1A);

        if (value != 0) {
            D_0043EE50 |= bit;
            arg.v = value;
        ((void* (XB_FASTCALL*)(void*, XB_ARG))xb_CopyMatrix)(&m, arg);
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

/* xb_EndFrame 0x150FE.
 *
 * Ends a frame: copies the game's screen texture (D_0044D3A0, the
 * 640x448 area at D_0043ED18/D_0044D394 sized D_0043ED0C x D_0043ED10)
 * onto the back buffer at D_0044D398/D_00461724 + 16 as a blended
 * quad, puts back the stage 0 and render states it changed, waits for
 * the vertical blank (twice when D_0043FE64 asks for 30 fps on odd
 * frames), presents, and clears the next target to D_002ECA1C. Returns
 * 0 while dword_4616AC holds the display. */

typedef struct {
    f32 x;
    f32 y;
    f32 z;
    f32 rhw;
    f32 u;
    f32 v;
} XB_TLVERTEX;
extern s32 D_0043EDB8;
extern void* D_00474CC8;
extern void* D_00474CCC;
extern s32 D_0044D3A0;
extern s32 D_0043FE64;
extern u32 D_0043EE28;
void xb_SoundFrame(void);
s32 xb_Get7C5959(void);
void XB_STDCALL D3DDevice__SetShaderConstantMode(s32 mode);
void XB_STDCALL D3DDevice__GetViewport(XB_VIEWPORT* vp);
void XB_STDCALL D3DDevice__SetPixelShader(s32 handle);
void XB_STDCALL D3DDevice__SetVertexShader(s32 handle);
void XB_STDCALL D3DDevice__DrawPrimitiveUP(s32 type, s32 count, void* data, s32 stride);
void XB_STDCALL D3DDevice__Clear(s32 count, void* rects, s32 flags, u32 color, f32 z, s32 stencil);

s32 xb_EndFrame(void) {
    XB_VIEWPORT saved;
    XB_TLVERTEX v[4];
    XB_VIEWPORT vp;
    u32 op_c;
    u32 op_e;
    u32 op_f;
    u32 op_10;
    u32 op_12;
    u32 op_13;
    f32 x0;
    f32 y0;
    f32 u0;
    f32 v0;
    f32 u1;
    f32 v1;

    if (dword_4616AC != 0) {
        return 0;
    }

    xb_SoundFrame();

    if (D_0043EDB8 != 0) {
        D3DDevice__SetShaderConstantMode(0);
        D_0043EDB8 = 0;
    }

    D3DDevice__GetViewport(&saved);
    vp.min_z = 0.0f;
    vp.y = 0;
    vp.x = 0;
    vp.w = 640;
    vp.h = 480;
    vp.max_z = 1.0f;
    D3DDevice__SetViewport(&vp);
    xb_UpdateRenderFlags(0);
    D3DDevice__SetRenderTarget(D_00474CC4, D_00474CC8);
    xb_GetTextureStageState(0, 0xC, &op_c);
    xb_GetTextureStageState(0, 0xE, &op_e);
    xb_GetTextureStageState(0, 0xF, &op_f);
    xb_GetTextureStageState(0, 0x10, &op_10);
    xb_GetTextureStageState(0, 0x12, &op_12);
    xb_GetTextureStageState(0, 0x13, &op_13);
    D3DDevice__SetTexture(0, D_0044D3A0);
    xb_SetTextureStageState(0, 0, 3);
    xb_SetTextureStageState(0, 1, 3);
    xb_SetTextureStageState(0, 0xC, 2);
    xb_SetTextureStageState(0, 0xE, 2);
    xb_SetTextureStageState(0, 0xF, 1);
    xb_SetTextureStageState(0, 0x10, 2);
    xb_SetTextureStageState(0, 0x12, 2);
    xb_SetTextureStageState(0, 0x13, 1);

    if (xb_Get7C5959()) {
        xb_SetTextureStageState(0, 4, 2);
        xb_SetTextureStageState(0, 3, 2);
    } else {
        xb_SetTextureStageState(0, 4, 1);
        xb_SetTextureStageState(0, 3, 1);
    }

    xb_SetTextureStageState(0, 5, 0);
    xb_SetRenderState(0x3C, 1);
    xb_SetRenderState(0x4A, 0x8006);
    xb_SetRenderState(0x3E, 0x302);
    xb_SetRenderState(0x3F, 0x303);

    x0 = (f32)D_0044D398 + 0.0f;
    y0 = (f32)D_00461724 + 16.0f;
    u0 = (f32)D_0043ED18 + 0.5f;
    v0 = (f32)D_0044D394 + 0.5f;
    u1 = (f32)D_0043ED0C + 0.5f;
    v1 = (f32)D_0043ED10 + 0.5f;
    v[0].x = x0;
    v[0].y = y0;
    v[0].z = 0.0f;
    v[0].rhw = 1.0f;
    v[0].u = u0;
    v[0].v = v0;
    v[1].x = x0 + 640.0f;
    v[1].y = y0;
    v[1].z = 0.0f;
    v[1].rhw = 1.0f;
    v[1].u = u1;
    v[1].v = v0;
    v[2].x = x0;
    v[2].y = y0 + 448.0f;
    v[2].z = 0.0f;
    v[2].rhw = 1.0f;
    v[2].u = u0;
    v[2].v = v1;
    v[3].x = x0 + 640.0f;
    v[3].y = y0 + 448.0f;
    v[3].z = 0.0f;
    v[3].rhw = 1.0f;
    v[3].u = u1;
    v[3].v = v1;
    D3DDevice__SetPixelShader(0);
    D3DDevice__SetVertexShader(0x104);
    D3DDevice__DrawPrimitiveUP(6, 2, v, sizeof(XB_TLVERTEX));
    D3DDevice__SetTexture(0, 0);
    xb_SetTextureStageState(0, 0xC, op_c);
    xb_SetTextureStageState(0, 0xE, op_e);
    xb_SetTextureStageState(0, 0xF, op_f);
    xb_SetTextureStageState(0, 0x10, op_10);
    xb_SetTextureStageState(0, 0x12, op_12);
    xb_SetTextureStageState(0, 0x13, op_13);
    xb_UpdateRenderFlags(D_00463C84);
    xb_ApplyRenderFlagChanges(-1, D_0043FE60);
    xb_SetBlendMode(~D_004616B0, D_004616B0);

    if (D_0043FE64 != 0 && (D_0043EE28 & 1)) {
        xb_BlockUntilVerticalBlank();
    }

    xb_BlockUntilVerticalBlank();
    xb_Swap(0, 0, 0, 0);
    D3DDevice__SetRenderTarget(D_00474CCC, D_00474CC8);
    D3DDevice__Clear(0, 0, 0xF3, D_002ECA1C, 1.0f, 0);
    D3DDevice__SetViewport(&saved);
    return 1;
}

/* xb_DrawCP3Screen 0x1546B.
 *
 * xb_EndFrame's copy of the screen texture onto the back buffer
 * without presenting: the back buffer is cleared first, the quad is
 * drawn opaque with dithering, and the screen texture is cleared to
 * black afterwards. */

void xb_DrawCP3Screen(void) {
    XB_VIEWPORT saved;
    XB_TLVERTEX v[4];
    XB_VIEWPORT vp;
    u32 op_c;
    u32 op_e;
    u32 op_f;
    u32 op_10;
    u32 op_12;
    u32 op_13;
    f32 x0;
    f32 y0;
    f32 u0;
    f32 v0;
    f32 u1;
    f32 v1;

    if (dword_4616AC != 0) {
        return;
    }

    D3DDevice__GetViewport(&saved);
    vp.min_z = 0.0f;
    vp.y = 0;
    vp.x = 0;
    vp.w = 640;
    vp.h = 480;
    vp.max_z = 1.0f;
    D3DDevice__SetViewport(&vp);
    xb_UpdateRenderFlags(0);
    D3DDevice__SetRenderTarget(D_00474CC4, D_00474CC8);
    D3DDevice__Clear(0, 0, 0xF3, D_002ECA1C, 1.0f, 0);
    xb_GetTextureStageState(0, 0xC, &op_c);
    xb_GetTextureStageState(0, 0xE, &op_e);
    xb_GetTextureStageState(0, 0xF, &op_f);
    xb_GetTextureStageState(0, 0x10, &op_10);
    xb_GetTextureStageState(0, 0x12, &op_12);
    xb_GetTextureStageState(0, 0x13, &op_13);
    D3DDevice__SetTexture(0, D_0044D3A0);
    xb_SetTextureStageState(0, 0, 3);
    xb_SetTextureStageState(0, 1, 3);
    xb_SetTextureStageState(0, 0xC, 2);
    xb_SetTextureStageState(0, 0xE, 2);
    xb_SetTextureStageState(0, 0xF, 1);
    xb_SetTextureStageState(0, 0x10, 2);
    xb_SetTextureStageState(0, 0x12, 2);
    xb_SetTextureStageState(0, 0x13, 1);

    if (xb_Get7C5959()) {
        xb_SetTextureStageState(0, 4, 2);
        xb_SetTextureStageState(0, 3, 2);
    } else {
        xb_SetTextureStageState(0, 4, 1);
        xb_SetTextureStageState(0, 3, 1);
    }

    xb_SetTextureStageState(0, 5, 0);
    xb_SetRenderState(0x3C, 0);
    xb_SetRenderState(0x3B, 1);
    xb_SetRenderState(0x4A, 0x8006);
    xb_SetRenderState(0x3E, 1);
    xb_SetRenderState(0x3F, 0);

    x0 = (f32)D_0044D398 + 0.0f;
    y0 = (f32)D_00461724 + 16.0f;
    u0 = (f32)D_0043ED18 + 0.5f;
    v0 = (f32)D_0044D394 + 0.5f;
    u1 = (f32)D_0043ED0C + 0.5f;
    v1 = (f32)D_0043ED10 + 0.5f;
    v[0].x = x0;
    v[0].y = y0;
    v[0].z = 0.0f;
    v[0].rhw = 1.0f;
    v[0].u = u0;
    v[0].v = v0;
    v[1].x = x0 + 640.0f;
    v[1].y = y0;
    v[1].z = 0.0f;
    v[1].rhw = 1.0f;
    v[1].u = u1;
    v[1].v = v0;
    v[2].x = x0;
    v[2].y = y0 + 448.0f;
    v[2].z = 0.0f;
    v[2].rhw = 1.0f;
    v[2].u = u0;
    v[2].v = v1;
    v[3].x = x0 + 640.0f;
    v[3].y = y0 + 448.0f;
    v[3].z = 0.0f;
    v[3].rhw = 1.0f;
    v[3].u = u1;
    v[3].v = v1;
    D3DDevice__SetPixelShader(0);
    D3DDevice__SetVertexShader(0x104);
    D3DDevice__DrawPrimitiveUP(6, 2, v, sizeof(XB_TLVERTEX));
    D3DDevice__SetTexture(0, 0);
    xb_SetTextureStageState(0, 0xC, op_c);
    xb_SetTextureStageState(0, 0xE, op_e);
    xb_SetTextureStageState(0, 0xF, op_f);
    xb_SetTextureStageState(0, 0x10, op_10);
    xb_SetTextureStageState(0, 0x12, op_12);
    xb_SetTextureStageState(0, 0x13, op_13);
    xb_UpdateRenderFlags(D_00463C84);
    xb_ApplyRenderFlagChanges(-1, D_0043FE60);
    xb_SetBlendMode(~D_004616B0, D_004616B0);
    D3DDevice__SetRenderTarget(D_00474CCC, D_00474CC8);
    D3DDevice__Clear(0, 0, 0xF3, 0, 1.0f, 0);
    D3DDevice__SetViewport(&saved);
}

/* xb_LoadDebugFont 0x13EE0.
 *
 * Loads the XDK sample font d:\media\Fonts\Font.xpr into the CXBFont at
 * D_00474CD8. Returns whether it loaded. */

extern s32 D_00474C9C;
extern u8 D_00474CD8[];
s32 XB_FASTCALL CXBFont_Create2(void* self, s32 edx, const char* file, s32 offset);

u8 xb_LoadDebugFont(void) {
    XB_ARG file;
    XB_ARG ofs;

    D_00474C9C = 0;
    file.v = (s32)"d:\\media\\Fonts\\Font.xpr";
    ofs.v = 0;
    return ((s32 (XB_FASTCALL*)(void*, XB_ARG, XB_ARG))CXBFont_Create2)(D_00474CD8, file, ofs) >= 0;
}

/* xb_InitVideoMemory 0x157AC.
 *
 * Allocates the 24 MB of physical memory the game works in (10 MB work
 * pool, then a 14 MB pool at D_004616A8), sets the default render and
 * stage states, loads the debug font and the vertex shaders, points
 * zlib's allocator at the work pool, clears both back buffers, creates
 * the 640x480 screen texture (D_0044D3A0) and makes it the render
 * target, and resets the display area to 640x448. */

extern u8* D_0043FF40;
extern u8* D_004616A8;
extern u32 D_0043EDD4;
extern u32 D_00461720;
extern u8 zlib[];
void* XB_STDCALL XPhysicalAlloc(u32 size, u32 addr, u32 align, u32 protect);
void xb_InitWorkPool(s32 a, s32 b, s32 c);
s32 xb_PoolInit(u32* pool, u32 base, u32 size, u32 align);
void sub_0004384A();
void xb_LoadVertexShaders(void);
void XB_STDCALL D3DDevice__GetDepthStencilSurface(void** out);
void free(void* p);

s32 xb_InitVideoMemory(void) {
    XB_VIEWPORT vp;

    D_0043EDD4 = 0xE00000;
    D_00461720 = 0xA00000;
    D_0043FF40 = XPhysicalAlloc(0x1800000, -1, 0, 4);

    if (D_0043FF40 != 0) {
        memset(D_0043FF40, 0, D_00461720 + D_0043EDD4);
    }

    D_004616A8 = D_0043FF40 + D_00461720;
    xb_InitWorkPool((s32)D_0043FF40, D_00461720, 0x20);
    xb_PoolInit((u32*)D_00463C10, (u32)D_004616A8, D_0043EDD4, 0x40);
    sub_0004384A();
    xb_SetRenderState(0x67, 0);
    xb_SetRenderState(0x93, 0);
    xb_SetRenderState(0x8F, 1);
    xb_SetRenderState(0x40, 1);
    xb_SetRenderState(0x3C, 1);
    xb_SetRenderState(0x3A, 0x205);
    xb_SetRenderState(0x3D, 0);
    xb_SetTextureStageState(0, 0xC, 4);
    xb_SetTextureStageState(0, 0xE, 2);
    xb_SetTextureStageState(0, 0xF, 1);
    xb_SetTextureStageState(0, 0x10, 4);
    xb_SetTextureStageState(0, 0x12, 2);
    xb_SetTextureStageState(0, 0x13, 1);
    D_00463C84 = 0x202;
    xb_ApplyRenderFlagChanges(-1, 0x202);
    D_00474CB0 = 0x138B032;
    xb_SetBlendMode(0, 0x138B032);
    xb_LoadDebugFont();
    *(void**)(zlib + 0x68) = (void*)xb_WorkPoolAlloc;
    *(void**)(zlib + 0x6C) = (void*)free;
    xb_LoadVertexShaders();
    xb_GetBackBuffer(0, 0, (s32*)&D_00474CC4);
    D3DDevice__GetDepthStencilSurface(&D_00474CC8);
    D3DDevice__SetRenderTarget(D_00474CC4, D_00474CC8);
    D3DDevice__Clear(0, 0, 0xF3, 0xFF000000, 1.0f, 0);
    xb_Swap(0, 0, 0, 0);
    xb_GetBackBuffer(0, 0, (s32*)&D_00474CC4);
    D3DDevice__GetDepthStencilSurface(&D_00474CC8);
    D3DDevice__SetRenderTarget(D_00474CC4, D_00474CC8);
    D3DDevice__Clear(0, 0, 0xF3, 0xFF000000, 1.0f, 0);
    D3DDevice__CreateTexture(640, 480, 1, 0, 0x12, 0, &D_0044D3A0);
    xb_GetSurfaceLevel((void*)D_0044D3A0, 0, &D_00474CCC);
    D3DDevice__SetRenderTarget(D_00474CCC, D_00474CC8);
    D3DDevice__Clear(0, 0, 0xF3, 0xFF000000, 1.0f, 0);
    D_0043EDB8 = -1;
    D_00461724 = 0;
    D_0044D398 = 0;
    D_0043ED18 = 0;
    D_0043ED0C = 640;
    D_0044D394 = 0;
    D_0043ED10 = 448;
    D_0043FE64 = 0;
    vp.y = 0;
    vp.x = 0;
    vp.w = 640;
    vp.h = 480;
    vp.min_z = 0.0f;
    vp.max_z = 1.0f;
    D3DDevice__SetViewport(&vp);
    return 1;
}

/* xb_SetTransformRect 0x15A6C.
 *
 * Keeps the camera's eye, target and up vectors and builds the
 * right-handed look-at matrix from them. */

extern XB_VECTOR3 D_004617B0;
extern XB_VECTOR3 D_004617BC;
extern XB_VECTOR3 D_004617D8;
XB_MATRIX* XB_STDCALL XGMatrixLookAtRH(XB_MATRIX* out, const XB_VECTOR3* eye, const XB_VECTOR3* at, const XB_VECTOR3* up);

void xb_SetTransformRect(XB_MATRIX* out, XB_VECTOR3* eye, XB_VECTOR3* at, XB_VECTOR3* up) {
    D_004617B0.v[0] = eye->v[0];
    D_004617B0.v[1] = eye->v[1];
    D_004617B0.v[2] = eye->v[2];
    D_004617BC.v[0] = at->v[0];
    D_004617BC.v[1] = at->v[1];
    D_004617BC.v[2] = at->v[2];
    D_004617D8.v[0] = up->v[0];
    D_004617D8.v[1] = up->v[1];
    D_004617D8.v[2] = up->v[2];
    XGMatrixLookAtRH(out, eye, at, up);
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

/* xb_sinf 0x15BB6: sin at float precision. */

double sin(double x);

f32 xb_sinf(f32 v) {
    return (f32)sin(v);
}

f32 xb_SetLightAttenuation(f32 v) {
    return xb_sinf(v);
}

void xb_SetLightFloat(s32 type, f32 a, f32 b, f32 c, f32 d) {
    XGMatrixPerspectiveFovLH(&D_004617F0[type], c, d, b, a);
    xb_SetLightByType(type);
}

f32 xb_SetLightRange(f32 v) {
    return xb_SetLightAttenuation(v);
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

/* xb_TexCoordU 0x15C2B and xb_TexCoordV 0x15CA1.
 *
 * A texel coordinate on the bound texture (D_00474CAC) as D3D wants it:
 * kept in texels for a linear texture, normalized for a swizzled one,
 * and mirrored when the blend state flips that axis (bits 8 and 9). */

extern u8 D_004616B1;
extern s32 D_0043FE5C;
void XB_STDCALL D3DDevice__SetVertexShader(s32 handle);
void XB_STDCALL D3DDevice__SetVertexData4f(s32 reg, f32 a, f32 b, f32 c, f32 d);

f32 xb_TexCoordU(f32 u) {
    f32 r;

    if (D_0043FF90[D_00474CAC].desc.d[0] >= 0x10) {
        r = (D_004616B1 & 1) ? D_0043FF90[D_00474CAC].info.d[1] - u : u;
        return r;
    }

    u /= D_0043FF90[D_00474CAC].info.d[1];
    r = (D_004616B1 & 1) ? 1.0f - u : u;
    return r;
}

f32 xb_TexCoordV(f32 v) {
    f32 r;

    if (D_0043FF90[D_00474CAC].desc.d[0] >= 0x10) {
        r = (D_004616B1 & 2) ? D_0043FF90[D_00474CAC].info.d[2] - v : v;
        return r;
    }

    v /= D_0043FF90[D_00474CAC].info.d[2];
    r = (D_004616B1 & 2) ? 1.0f - v : v;
    return r;
}

/* xb_DrawTexQuadInternal 0x15E96.
 *
 * A textured rectangle: s16 x, y, w, h, the colour, then the texel
 * corners u0, v0, u1, v1; drawn half a pixel up and left so texels
 * land on pixels. */

typedef struct {
    s16 x;
    s16 y;
    s16 w;
    s16 h;
    u32 color;
    s16 u0;
    s16 v0;
    s16 u1;
    s16 v1;
} XB_TEXQUAD;

s32 xb_DrawTexQuadInternal(void* p) {
    XB_TEXQUAD* q;

    if (D_0043FE5C == 0) {
        return 0;
    }

    D3DDevice__SetVertexShader(0x144);
    xb_Begin(6);
    q = p;
    xb_SetVertexDataColor(3, q->color);
    xb_SetVertexData2f(9, xb_TexCoordU(q->u0), xb_TexCoordV(q->v0));
    D3DDevice__SetVertexData4f(-1, q->x - 0.5f, q->y - 0.5f, 0.0f, 1.0f);
    xb_SetVertexData2f(9, xb_TexCoordU(q->u1), xb_TexCoordV(q->v0));
    D3DDevice__SetVertexData4f(-1, (q->w + q->x) - 0.5f, q->y - 0.5f, 0.0f, 1.0f);
    xb_SetVertexData2f(9, xb_TexCoordU(q->u0), xb_TexCoordV(q->v1));
    D3DDevice__SetVertexData4f(-1, q->x - 0.5f, (q->h + q->y) - 0.5f, 0.0f, 1.0f);
    xb_SetVertexData2f(9, xb_TexCoordU(q->u1), xb_TexCoordV(q->v1));
    D3DDevice__SetVertexData4f(-1, (q->w + q->x) - 0.5f, (q->y + q->h) - 0.5f, 0.0f, 1.0f);
    xb_End();
    return 1;
}

/* xb_SaveQuadStates 0x161C5.
 *
 * Before an untextured 2D draw: turns lighting (0x66), fog (0x5C) and
 * 0x93 off, and unless flags bit 0 is set unbinds the texture and sets
 * stage 0's colour and alpha ops to select the diffuse colour, saving
 * each state it changes for xb_RestoreQuadStates. */

extern s32 D_0043EDB8;
void XB_STDCALL D3DDevice__SetShaderConstantMode(s32 mode);
void XB_STDCALL D3DDevice__SetVertexShader(s32 handle);
void XB_STDCALL D3DDevice__SetVertexData4f(s32 reg, f32 a, f32 b, f32 c, f32 d);
extern s32 D_0043FE5C;

void xb_SaveQuadStates(s32 flags) {
    xb_GetRenderState(0x66, (u32*)&D_00474D80);

    if (D_00474D80 == 1) {
        D_00474D9C = 1;
        xb_SetRenderState(0x66, 0);
    } else {
        D_00474D9C = 0;
    }

    xb_GetRenderState(0x5C, (u32*)&D_00474D74);

    if (D_00474D74 == 1) {
        D_00474D98 = 1;
        xb_SetRenderState(0x5C, 0);
    } else {
        D_00474D98 = 0;
    }

    if (!(flags & 1)) {
        D3DDevice__SetTexture(0, 0);
        xb_GetTextureStageState(0, 0xC, (u32*)&D_00474D90);
        xb_GetTextureStageState(0, 0x10, (u32*)&D_00474D7C);
        xb_SetTextureStageState(0, 0xC, 1);
        xb_SetTextureStageState(0, 0x10, 1);
        D_00474D84 = 1;
    } else {
        D_00474D84 = 0;
    }

    xb_GetRenderState(0x93, (u32*)&D_00474D94);

    if (D_00474D94 != 0) {
        D_00474D88 = 1;
        xb_SetRenderState(0x93, 0);
    } else {
        D_00474D88 = 0;
    }

    if (D_0043EDB8 != 0) {
        D3DDevice__SetShaderConstantMode(0);
        D_0043EDB8 = 0;
    }
}

/* xb_DrawQuadInternal 0x15DA1.
 *
 * Draws a flat-coloured rectangle given as s16 x0, y0, x1, y1 and a
 * D3DCOLOR, as a pretransformed triangle strip. */

typedef struct {
    s16 x0;
    s16 y0;
    s16 x1;
    s16 y1;
    u32 color;
} XB_QUAD;

s32 xb_DrawQuadInternal(void* p) {
    XB_QUAD* q;

    if (D_0043FE5C == 0) {
        return 0;
    }

    D3DDevice__SetVertexShader(0x44);
    xb_Begin(6);
    q = p;
    xb_SetVertexDataColor(3, q->color);
    D3DDevice__SetVertexData4f(-1, q->x0, q->y0, 0.0f, 1.0f);
    D3DDevice__SetVertexData4f(-1, q->x1, q->y0, 0.0f, 1.0f);
    D3DDevice__SetVertexData4f(-1, q->x0, q->y1, 0.0f, 1.0f);
    D3DDevice__SetVertexData4f(-1, q->x1, q->y1, 0.0f, 1.0f);
    xb_End();
    return 1;
}

/* xb_DrawRectInternal 0x160B0.
 *
 * The same with float corners, a depth (mapped from -1..1 to 0..1) and
 * an rhw. */

typedef struct {
    f32 x0;
    f32 y0;
    f32 z;
    f32 rhw;
    f32 x1;
    f32 y1;
    f32 pad[2];
    u32 color;
} XB_RECTF;

s32 xb_DrawRectInternal(void* p) {
    XB_RECTF* r;

    if (D_0043FE5C == 0) {
        return 0;
    }

    D3DDevice__SetVertexShader(0x44);
    xb_Begin(6);
    r = p;
    xb_SetVertexDataColor(3, r->color);
    D3DDevice__SetVertexData4f(-1, r->x0, r->y0, (r->z + 1.0f) / 2.0f, r->rhw);
    D3DDevice__SetVertexData4f(-1, r->x1, r->y0, (r->z + 1.0f) / 2.0f, r->rhw);
    D3DDevice__SetVertexData4f(-1, r->x0, r->y1, (r->z + 1.0f) / 2.0f, r->rhw);
    D3DDevice__SetVertexData4f(-1, r->x1, r->y1, (r->z + 1.0f) / 2.0f, r->rhw);
    xb_End();
    return 1;
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
    r = xb_DrawTexQuadInternal(q);
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

    memcpy(out, &D_0043FF90[handle], 0x48);
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

/* xb_MapTextureFormat 0x1632B.
 *
 * A swizzled D3D format to its linear twin; others are returned as
 * they are. */

s32 xb_MapTextureFormat(s32 fmt) {
    switch (fmt) {
    case 0x0:
        return 0x13;
    case 0x1:
        return 0x1B;
    case 0x2:
        return 0x10;
    case 0x3:
        return 0x1C;
    case 0x4:
        return 0x1D;
    case 0x5:
        return 0x11;
    case 0x6:
        return 0x12;
    case 0x7:
        return 0x1E;
    case 0x19:
        return 0x1F;
    case 0x1A:
        return 0x20;
    case 0x27:
        return 0x37;
    case 0x28:
        return 0x17;
    case 0x29:
        return 0x16;
    case 0x2A:
        return 0x2E;
    case 0x2B:
        return 0x2F;
    case 0x2C:
        return 0x30;
    case 0x2D:
        return 0x31;
    case 0x32:
        return 0x35;
    case 0x33:
        return 0x36;
    case 0x38:
        return 0x3D;
    case 0x39:
        return 0x3E;
    case 0x3A:
        return 0x3F;
    case 0x3B:
        return 0x40;
    case 0x3C:
        return 0x41;
    }

    return fmt;
}

/* xb_FormatInfo 0x16443.
 *
 * A surface format's bytes per pixel and alpha, red, green and blue
 * masks (0 for an unknown format, 1 for P8). Retail's R5G6B5 red mask
 * is 0xF100, not 0xF800. */

s32 xb_FormatInfo(XB_LEVELDESC* desc, u32* a, u32* r, u32* g, u32* b) {
    switch (desc->d[0]) {
    case 0x6:
    case 0x12:
        *a = 0xFF000000;
        *r = 0xFF0000;
        *g = 0xFF00;
        *b = 0xFF;
        return 4;
    case 0x7:
    case 0x1E:
        *a = 0;
        *r = 0xFF0000;
        *g = 0xFF00;
        *b = 0xFF;
        return 4;
    case 0xB:
        *a = 0;
        *r = 0;
        *g = 0;
        *b = 0;
        return 1;
    case 0x4:
    case 0x1D:
        *a = 0xF000;
        *r = 0xF00;
        *g = 0xF0;
        *b = 0xF;
        return 2;
    case 0x5:
    case 0x11:
        *a = 0;
        *r = 0xF100;
        *g = 0x7E0;
        *b = 0x1F;
        return 2;
    case 0x2:
    case 0x10:
        *a = 0x8000;
        *r = 0x7C00;
        *g = 0x3E0;
        *b = 0x1F;
        return 2;
    }

    *a = 0;
    *r = 0;
    *g = 0;
    *b = 0;
    return 0;
}

/* xb_FillTextureDesc 0x1653F.
 *
 * An image description (see xb_StoreImagePixel) for a texture level:
 * size, pitch and each channel's bit count, shift and maximum. */

#define XB_MASK_FIELDS(m, bits, shift, max)                  \
    shift = 0;                                               \
    if (m == 0) {                                            \
        bits = 0;                                            \
    } else {                                                 \
        for (; shift < 32 && !(m & 1); shift++) {            \
            m >>= 1;                                         \
        }                                                    \
        for (bits = 0; bits < 32 && (m & 1); bits++) {       \
            m >>= 1;                                         \
        }                                                    \
    }                                                        \
    max = (1 << bits) - 1

void xb_FillTextureDesc(XB_IMAGEINFO* dst, XB_LEVELDESC* desc) {
    u32 a;
    u32 r;
    u32 g;
    u32 b;

    memset(dst, 0, sizeof(XB_IMAGEINFO));
    dst->d[1] = desc->d[5];
    dst->d[2] = desc->d[6];
    dst->d[4] = 0;
    dst->d[5] = xb_FormatInfo(desc, &a, &r, &g, &b);
    dst->d[3] = dst->d[1] * dst->d[5];
    XB_MASK_FIELDS(r, dst->d[6], dst->d[7], dst->d[8]);
    XB_MASK_FIELDS(g, dst->d[9], dst->d[10], dst->d[11]);
    XB_MASK_FIELDS(b, dst->d[12], dst->d[13], dst->d[14]);
    XB_MASK_FIELDS(a, dst->d[15], dst->d[16], dst->d[17]);
    dst->d[0] = 0;
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


/* The image descriptions differ in anything but flags, pitch and bits. */
#define XB_IMAGEINFO_DIFFERS(a, b)                                                                  \
    ((a)->d[1] != (b)->d[1] || (a)->d[2] != (b)->d[2] || (a)->d[5] != (b)->d[5] ||                  \
     (a)->d[6] != (b)->d[6] || (a)->d[7] != (b)->d[7] || (a)->d[8] != (b)->d[8] ||                  \
     (a)->d[9] != (b)->d[9] || (a)->d[10] != (b)->d[10] || (a)->d[11] != (b)->d[11] ||              \
     (a)->d[12] != (b)->d[12] || (a)->d[13] != (b)->d[13] || (a)->d[14] != (b)->d[14] ||            \
     (a)->d[15] != (b)->d[15] || (a)->d[16] != (b)->d[16] || (a)->d[17] != (b)->d[17])

/* flLockTexture 0x16993.
 *
 * The Xbox flLockTexture (PPGFile calls it where the PS2 code does).
 * Each texture handle's 0xD4-byte entry holds the texture's image
 * description (+0), the caller's (+0x48), the D3D texture (+0x90), its
 * level description (+0x94), the locked rectangle (+0xB0), the lock
 * rectangle's pointer and corners (+0xB8, +0xBC) and the lock mode
 * (+0xD0). A linear texture, or mode 1, is locked in place and handed
 * out directly. A swizzled one is unswizzled into the work buffer at
 * 0x604EA0 (not for mode 2, which only writes) and handed out in the
 * caller's format, converted when that differs. */

extern u8 D_00604EA0[];
void XB_STDCALL XGUnswizzleRect(void* src, s32 w, s32 h, void* rect, void* dst, s32 pitch, void* point, s32 bpp);

s32 flLockTexture(s16* r, u32 h, XB_IMAGEINFO* out, s32 mode) {
    XB_IMAGEINFO tmp = D_0043FF90[h].info;
    s32 pt[2];

    if (D_0043FF90[h].tex == 0) {
        return 0;
    }

    xb_GetLevelDesc((s32)D_0043FF90[h].tex, 0, (s32)&D_0043FF90[h].desc);

    if (r != 0) {
        D_0043FF90[h].rectp = D_0043FF90[h].rect;
        D_0043FF90[h].rect[0] = r[0];
        D_0043FF90[h].rect[1] = r[1];
        D_0043FF90[h].rect[2] = r[2];
        D_0043FF90[h].rect[3] = r[3];
    } else {
        D_0043FF90[h].rectp = 0;
    }

    if (mode == 1 || D_0043FF90[h].desc.d[0] >= 0x10) {
        if (D3DTexture__LockRect(D_0043FF90[h].tex, 0, &D_0043FF90[h].lr, D_0043FF90[h].rectp, 0) < 0) {
            return 0;
        }

        *out = D_0043FF90[h].info;
        D_0043FF90[h].info.d[4] = (s32)D_0043FF90[h].lr.bits;
        D_0043FF90[h].src.d[4] = (s32)D_0043FF90[h].lr.bits;
        out->d[4] = (s32)D_0043FF90[h].lr.bits;
    } else {
        if (D3DTexture__LockRect(D_0043FF90[h].tex, 0, &D_0043FF90[h].lr, 0, 0) < 0) {
            return 0;
        }

        if (mode != 2) {
            if (D_0043FF90[h].rectp != 0) {
                pt[1] = 0;
                pt[0] = 0;
                XGUnswizzleRect(D_0043FF90[h].lr.bits, D_0043FF90[h].desc.d[5], D_0043FF90[h].desc.d[6],
                                D_0043FF90[h].rectp, D_00604EA0,
                                D_0043FF90[h].desc.d[5] * D_0043FF90[h].info.d[5], pt, D_0043FF90[h].info.d[5]);
            } else {
                XGUnswizzleRect(D_0043FF90[h].lr.bits, D_0043FF90[h].desc.d[5], D_0043FF90[h].desc.d[6], 0,
                                D_00604EA0, 0, 0, D_0043FF90[h].info.d[5]);
            }
        }

        if (!XB_IMAGEINFO_DIFFERS(&D_0043FF90[h].info, &D_0043FF90[h].src)) {
            *out = D_0043FF90[h].info;
            D_0043FF90[h].info.d[4] = (s32)D_00604EA0;
            D_0043FF90[h].src.d[4] = (s32)D_00604EA0;
            out->d[4] = (s32)D_00604EA0;
        } else {
            tmp = D_0043FF90[h].info;
            *out = D_0043FF90[h].src;
            out->d[4] = (s32)D_00474DA0;
            D_0043FF90[h].src.d[4] = (s32)D_00474DA0;
            tmp.d[4] = (s32)D_00604EA0;

            if (xb_ConvertImagePixels((u8*)out, (s32)&tmp) == 0) {
                flLogOut(D_002197EC);
                return 0;
            }
        }
    }

    D_0043FF90[h].mode = mode;
    out->d[0] |= 2;
    return 1;
}

/* flUnlockTexture 0x16C67.
 *
 * The Xbox flUnlockTexture. Re-uploads a swizzled texture's image: when the image description
 * (+0x48) no longer matches the texture's (+0), the pixels are
 * converted into the work buffer first; then the dirty rectangle
 * (+0xB8 set, corners at +0xBC) or the whole image is swizzled into the
 * locked bits at +0xB4. Linear textures (format 0x10 and up) and ones
 * flagged at +0xD0 are left alone. */

s32 flUnlockTexture(u32 h) {
    s32 rect[4];
    s32 pt[2];

    if (D_0043FF90[h].tex == 0) {
        return 0;
    }

    if (D_0043FF90[h].mode == 1 || D_0043FF90[h].desc.d[0] >= 0x10) {
        return 1;
    }

    if (XB_IMAGEINFO_DIFFERS(&D_0043FF90[h].info, &D_0043FF90[h].src)) {
        D_0043FF90[h].info.d[4] = (s32)D_00474DA0;

        if (xb_ConvertImagePixels((u8*)&D_0043FF90[h].info, (s32)&D_0043FF90[h].src) == 0) {
            flLogOut(D_002197EC);
            return 0;
        }
    }

    if (D_0043FF90[h].rectp != 0) {
        pt[0] = D_0043FF90[h].rect[0];
        pt[1] = D_0043FF90[h].rect[1];
        rect[0] = 0;
        rect[1] = 0;
        rect[2] = D_0043FF90[h].rect[2] - pt[0];
        rect[3] = D_0043FF90[h].rect[3] - pt[1];
        XGSwizzleRect((void*)D_0043FF90[h].info.d[4], D_0043FF90[h].desc.d[5] * D_0043FF90[h].info.d[5], rect,
                      D_0043FF90[h].lr.bits, D_0043FF90[h].desc.d[5], D_0043FF90[h].desc.d[6], pt,
                      D_0043FF90[h].info.d[5]);
    } else {
        XGSwizzleRect((void*)D_0043FF90[h].info.d[4], 0, 0, D_0043FF90[h].lr.bits, D_0043FF90[h].desc.d[5],
                      D_0043FF90[h].desc.d[6], 0, D_0043FF90[h].info.d[5]);
    }

    return 1;
}

/* flCreateTextureHandle 0x16867.
 *
 * Takes the first free texture handle from 1 (each 0xD4-byte entry of
 * D_0043FF90 holds the D3D texture at +0x90), creates the texture for
 * the image and, when the image has bits, converts and swizzles them in.
 * Returns the handle, or 0 if creation or conversion failed. There is no
 * check for a full table. */

extern s32 D_00474CB8;

s32 flCreateTextureHandle(void* bits, u32 attribute) {
    XB_IMAGEINFO info;
    u8* img = bits;
    s32 h = 1;
    void** p;

    for (p = &D_0043FF90[1].tex; (s32)p < (s32)&D_0043FF90[0x100].tex; p = (void**)((u8*)p + sizeof(XB_TEXENTRY))) {
        if (*p == 0) {
            break;
        }

        h++;
    }

    D_0043FF90[h].tex = (void*)xb_ChooseTextureFormat(img, 1, attribute);

    if (D_0043FF90[h].tex == 0) {
        flLogOut("Creating texture failed @flCreateTextureHandle\n");
        return 0;
    }

    xb_LockTextureLevel((XB_IMAGEINFO*)img, &info, (u8*)&D_0043FF90[h], 0);

    if (*(s32*)(img + 0x10) == 0 || xb_ConvertAndSwizzleImage((s32)img, (u8*)&info, (u8*)&D_0043FF90[h], 0) != 0) {
        D_00474CB8++;
        return h;
    }

    if (D_0043FF90[h].tex != 0) {
        D3DDevice__SetTexture(0, 0);
        D3DDevice__SetTexture(1, 0);
        D3DDevice__SetTexture(2, 0);
        D3DDevice__SetTexture(3, 0);
        xb_ReleaseResource((s32)D_0043FF90[h].tex);
        D_0043FF90[h].tex = 0;
    }

    return 0;
}

/* flReleaseTextureHandle 0x1693D.
 *
 * Unbinds every stage and releases the handle's texture. */

s32 flReleaseTextureHandle(u32 h) {
    if (h >= 0x100) {
        return 0;
    }

    if (D_0043FF90[h].tex != 0) {
        D3DDevice__SetTexture(0, 0);
        D3DDevice__SetTexture(1, 0);
        D3DDevice__SetTexture(2, 0);
        D3DDevice__SetTexture(3, 0);
        xb_ReleaseResource((s32)D_0043FF90[h].tex);
        D_00474CB8--;
        D_0043FF90[h].tex = 0;
    }

    return 1;
}

/* flCreatePaletteHandle 0x16E46.
 *
 * Takes the first free palette handle from 1 and creates a D3D palette
 * of the image's width (256, 128, 64, or up to 32 entries), describing
 * it as 32-bit A8R8G8B8, and converts the image's colours into it. */

s32 flCreatePaletteHandle(void* bits_, s32 flag) {
    u8* img = bits_;
    XB_PALINFO info;
    s32 bits;
    s32 h = 1;
    void** p;
    s32 size;

    for (p = &D_0044D3A8[1].pal; (s32)p < (s32)&D_0044D3A8[1088].pal; p = (void**)((u8*)p + sizeof(XB_PALSLOT))) {
        if (*p == 0) {
            break;
        }

        h++;
    }

    if (*(s32*)(img + 4) == 0x100) {
        size = 0;
    } else if (*(s32*)(img + 4) == 0x80) {
        size = 1;
    } else if (*(s32*)(img + 4) == 0x40) {
        size = 2;
    } else if (*(s32*)(img + 4) <= 0x20) {
        size = 3;
    } else {
        return 0;
    }

    if (xb_CreatePalette(size, &D_0044D3A8[h].pal) < 0 || xb_LockPalette(D_0044D3A8[h].pal, &bits, 0) < 0) {
        return 0;
    }

    info.d[0] = *(s32*)img;
    info.d[1] = *(s32*)(img + 4);
    info.d[2] = *(s32*)(img + 8);
    info.d[3] = *(s32*)(img + 4) * 4;
    info.bits = bits;
    info.e[0] = 4;
    info.e[1] = 8;
    info.e[2] = 0x10;
    info.e[3] = 0xFF;
    info.e[4] = 8;
    info.e[5] = 8;
    info.e[6] = 0xFF;
    info.e[7] = 8;
    info.e[8] = 0;
    info.e[9] = 0xFF;
    info.e[10] = 8;
    info.e[11] = 0x18;
    info.e[12] = 0xFF;
    D_0044D3A8[h].info = info;

    if (*(s32*)(img + 0x10) != 0) {
        xb_ConvertImagePixels((u8*)&info, (s32)img);
    }

    return h;
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

/* xb_LoadVertexShader 0x16FB3.
 *
 * Creates a vertex shader from a compiled .xvu file with the given
 * vertex declaration; returns its handle. */

u32 xb_LoadVertexShader(const u32* decl, const char* file) {
    u32 v;

    XBUtil_CreateVertexShader(file, decl, &v);
    return v;
}

/* xb_LoadVertexShaders 0x16FCE.
 *
 * Loads the game's vertex shaders: the 9 x 4 x 14 table of
 * Shaders\VS_NL_*.xvu files (each run of 7 uses the declarations A, B,
 * B, C, C, C, C) and the nine Shaders\VS_SP*.xvu ones. */

extern const u32 D_002ED274[];
extern const u32 D_002ED23C[];
extern const u32 D_002ED254[];
extern const u32 D_002ED298[];
extern const char* D_002ECA30[9][4][14];
extern u32 D_00794EB0[9][4][14];
extern const char* D_002ED210[9];
extern u32 D_00795690[9];

void xb_LoadVertexShaders(void) {
    s32 i;
    s32 j;

    for (i = 0; i < 9; i++) {
        for (j = 0; j < 4; j++) {
            D_00794EB0[i][j][0] = xb_LoadVertexShader(D_002ED274, D_002ECA30[i][j][0]);
            D_00794EB0[i][j][1] = xb_LoadVertexShader(D_002ED23C, D_002ECA30[i][j][1]);
            D_00794EB0[i][j][2] = xb_LoadVertexShader(D_002ED23C, D_002ECA30[i][j][2]);
            D_00794EB0[i][j][3] = xb_LoadVertexShader(D_002ED254, D_002ECA30[i][j][3]);
            D_00794EB0[i][j][4] = xb_LoadVertexShader(D_002ED254, D_002ECA30[i][j][4]);
            D_00794EB0[i][j][5] = xb_LoadVertexShader(D_002ED254, D_002ECA30[i][j][5]);
            D_00794EB0[i][j][6] = xb_LoadVertexShader(D_002ED254, D_002ECA30[i][j][6]);
            D_00794EB0[i][j][7] = xb_LoadVertexShader(D_002ED274, D_002ECA30[i][j][7]);
            D_00794EB0[i][j][8] = xb_LoadVertexShader(D_002ED23C, D_002ECA30[i][j][8]);
            D_00794EB0[i][j][9] = xb_LoadVertexShader(D_002ED23C, D_002ECA30[i][j][9]);
            D_00794EB0[i][j][10] = xb_LoadVertexShader(D_002ED254, D_002ECA30[i][j][10]);
            D_00794EB0[i][j][11] = xb_LoadVertexShader(D_002ED254, D_002ECA30[i][j][11]);
            D_00794EB0[i][j][12] = xb_LoadVertexShader(D_002ED254, D_002ECA30[i][j][12]);
            D_00794EB0[i][j][13] = xb_LoadVertexShader(D_002ED254, D_002ECA30[i][j][13]);
        }
    }

    D_00795690[0] = xb_LoadVertexShader(D_002ED23C, D_002ED210[0]);
    D_00795690[1] = xb_LoadVertexShader(D_002ED254, D_002ED210[1]);
    D_00795690[2] = xb_LoadVertexShader(D_002ED254, D_002ED210[2]);
    D_00795690[3] = xb_LoadVertexShader(D_002ED23C, D_002ED210[3]);
    D_00795690[4] = xb_LoadVertexShader(D_002ED23C, D_002ED210[4]);
    D_00795690[5] = xb_LoadVertexShader(D_002ED23C, D_002ED210[5]);
    D_00795690[6] = xb_LoadVertexShader(D_002ED23C, D_002ED210[6]);
    D_00795690[7] = xb_LoadVertexShader(D_002ED254, D_002ED210[7]);
    D_00795690[8] = xb_LoadVertexShader(D_002ED298, D_002ED210[8]);
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

/* xb_PADConvertStick 0x17469.
 *
 * The PS2 update_pad_stick_dir: the stick's angle (radians and
 * degrees) and strength, capped at 0x7F, with the stick zeroed below
 * the dead zone depth. */

typedef struct {
    s16 x;
    s16 y;
    s16 pow;
    s16 ang;
    f32 rad;
} XB_PADSTICK;

/* TARPAD */
typedef struct {
    u8 state;
    u8 anstate;
    u16 kind;
    u32 conn;
    u32 sw;
    u8 pow[16];
    XB_PADSTICK stick[2];
} XB_TARPAD;

extern XB_TARPAD tarpad_root[4];
extern u32 flpad_io_map[];
extern u8 D_00795880[4][0xE0];
extern u16 D_0021CC80[8][2];
extern u32 D_0021CBE8[16][2];
double atan2(double y, double x);
double sqrt(double x);

void xb_PADConvertStick(XB_PADSTICK* st, s16 depth) {
    f32 radian;

    if ((st->y | st->x) == 0) {
        radian = 0.0f;
    } else {
        radian = atan2(-st->y, st->x);

        if (radian < 0.0f) {
            radian += 6.2831855f;
        }
    }

    st->rad = radian;
    st->ang = 360.0f * (st->rad / 6.2831855f);
    st->pow = sqrt((double)(st->y * st->y) + (double)(st->x * st->x));

    if (st->pow > 0x7F) {
        st->pow = 0x7F;
    }

    if (st->pow < depth) {
        st->x = 0;
        st->y = 0;
        st->rad = 0.0f;
        st->ang = 0;
        st->pow = 0;
    }
}

/* xb_PADReadOne 0x17273.
 *
 * The Xbox PADRead_for_PS2: fills tarpad_root[i] from the gamepad state
 * XBInput_GetInput left in D_00795880. The low byte of wButtons gives
 * the d-pad, Start, Back and the stick clicks, and an analog button
 * held past 0x1F (at half scale) adds its bit (D_0021CC80). The 16
 * library buttons (D_0021CBE8: hardware bits and analog index) map to
 * flpad_io_map, each with its strength (0x7F for a digital one, nothing
 * below the configured threshold). The sticks scale from -1..1 to
 * -127..127, with y up. */

s32 xb_PADReadOne(s32 i) {
    u8 kan[8];
    u32 io;
    u32 sw;
    s32 j;

    tarpad_root[i].state = 1;

    if (*(s32*)(*(u8**)D_00795C00 + i * 0xE0 + 0xD4) != 0) {
        tarpad_root[i].kind = 1;
    } else {
        tarpad_root[i].kind = 0;
    }

    tarpad_root[i].anstate = 0x63;

    if (tarpad_root[i].kind != 0 && !(tarpad_root[i].kind & 3)) {
        tarpad_root[i].kind = 0x8000;
    }

    memset(tarpad_root[i].pow, 0, 16);

    switch (tarpad_root[i].kind) {
    case 1:
    case 2:
    case 4:
    case 8:
    case 16:
    case 32:
        io = D_00795880[i][0] & 0xFF;

        for (j = 0; j < 8; j++) {
            kan[j] = D_00795880[i][2 + j] >> 1;
        }

        for (j = 0; j < 8; j++) {
            if (kan[D_0021CC80[j][0]] > 0x1F) {
                io |= D_0021CC80[j][1];
            }
        }

        sw = 0;

        for (j = 0; j < 16; j++) {
            if (io & D_0021CBE8[j][0]) {
                sw |= flpad_io_map[j];

                if (D_0021CBE8[j][1] != 0) {
                    u8 v = kan[D_0021CBE8[j][1] - 1];

                    tarpad_root[i].pow[j] = (v < D_00795768[i].a) ? 0 : v;
                } else {
                    tarpad_root[i].pow[j] = 0x7F;
                }
            }
        }

        tarpad_root[i].stick[0].x = *(f32*)(D_00795880[i] + 0x14) * 127.5f;
        tarpad_root[i].stick[1].x = *(f32*)(D_00795880[i] + 0x1C) * 127.5f;
        tarpad_root[i].stick[0].y = *(f32*)(D_00795880[i] + 0x18) * -127.5f;
        tarpad_root[i].sw = sw;
        tarpad_root[i].stick[1].y = *(f32*)(D_00795880[i] + 0x20) * -127.5f;
        break;

    default:
        tarpad_root[i].sw = 0;
        tarpad_root[i].stick[0].x = 0;
        tarpad_root[i].stick[0].y = 0;
        tarpad_root[i].stick[1].x = 0;
        tarpad_root[i].stick[1].y = 0;
        break;
    }

    return 1;
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

    if (XBInput_CreateGamepads(D_00795C00) < 0) {
        return 0;
    }

    for (i = 0; i < 4; i++) {
        *(s32*)(D_007957B4 + i * 0x34) = *(s32*)(D_0043EA04 + i * 0xE0);
    }

    xb_PADClearVibration();
    return 1;
}

/* xb_PADRead 0x175D7.
 *
 * The Xbox tarPADRead: polls the pads, fills tarpad_root from each
 * connected one (d-pad corrected through D_0021CC70, sticks with their
 * dead zones, and each stick's 8-way direction in bits 16-23), then
 * steps the rumble timers and sends each pad its motor speeds unless a
 * send is still pending. */

extern u8 D_0043E930[4][0xE0];
extern u8 D_0021CC70[16];
void XBInput_GetInput(void* pads);
void XB_STDCALL XInputSetState(s32 dev, void* feedback);

void xb_PADRead(void) {
    s32 i;
    u8* gp;

    XBInput_GetInput(0);

    for (i = 0; i < 4; i++) {
        memcpy(D_00795880[i], D_0043E930[i], 0xE0);

        if (xb_PADReadOne(i)) {
            tarpad_root[i].conn = *(s32*)(D_0043EA04 + i * 0xE0);
            tarpad_root[i].sw = (tarpad_root[i].sw & 0xFFF0) | D_0021CC70[tarpad_root[i].sw & 0xF];
            xb_PADConvertStick(&tarpad_root[i].stick[0], D_00795768[i].b);
            xb_PADConvertStick(&tarpad_root[i].stick[1], D_00795768[i].c);
            tarpad_root[i].sw |= ((xb_PADTriggerToButton((u8*)&tarpad_root[i].stick[1]) << 4) |
                                  xb_PADTriggerToButton((u8*)&tarpad_root[i].stick[0]))
                                 << 16;
        }
    }

    xb_PADVibrationTick();

    for (i = 0; i < 4; i++) {
        gp = *(u8**)D_00795C00 + i * 0xE0;

        if (*(s32*)(gp + 0xD4) != 0 && *(s32*)(gp + 0x74) != 0x3E5) {
            *(u16*)(gp + 0xB6) = D_00795788[i];
            *(u16*)(*(u8**)D_00795C00 + i * 0xE0 + 0xB8) = D_00795790[i];
            gp = *(u8**)D_00795C00 + i * 0xE0;
            XInputSetState(*(s32*)(gp + 0xD4), gp + 0x74);
        }
    }
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

/* The debug print layer (D_00795C14). Its work area holds the glyph
 * source (+0xC), the pen (+0x10 x, +0x12 y, +0x14 scale), the drawing
 * position (+0x18, +0x1A), the character cell (+0x1C width, +0x1D
 * height), attribute (+0x1E) and colour (+0x20), two lists of strings
 * (counts at +0x28, 0x14-byte entries at +0x30) for small and large
 * text, the text buffer (+0x38 used, +0x3C), half-width ASCII (+0x40),
 * the glyph queue (+0x48 drawn, +0x4C queued, indices at +0x50), each
 * glyph's cache slot (+0x142, 0xFF when not cached), the next free slot
 * (+0x3E44) and the cache texture and palettes (+0x3E48, +0x3E4C).
 * 0x79 glyphs of 22x22 fit the cache texture, 11 to a row. */

u32 xb_AsciiToSjis(u8 c);
void XB_FASTCALL xb_xlive_font_DrawQueue(u8* dst, u8* src);
void ps2SeqsRenderQuadInit_A(void);
void ps2SeqsRenderQuadEnd(void);
void ps2SeqsRenderQuad_Ax(void* quad);
void sub_0004384A();
s32 flLockTexture(s16* r, u32 h, XB_IMAGEINFO* out, s32 mode);
s32 flUnlockTexture(u32 h);

#define XB_PW_COUNT(p, k) (((s32*)((p) + 0x28))[k])
#define XB_PW_LIST(p, k) (((u8**)((p) + 0x30))[k])
#define XB_IS_SJIS_LEAD(c) (((c) >= 0x80 && (c) <= 0x9F) || ((c) >= 0xE0 && (c) <= 0xFF))

/* xb_PrintTextWidth 0x179B1.
 *
 * A string's width in pixels: a full cell for a two-byte character,
 * half or two thirds of one for ASCII. The text is read as signed
 * chars, so in retail the two-byte test never passes. */

s32 xb_PrintTextWidth(const char* s) {
    u8* p;
    s32 w = 0;
    s32 c = *s++;

    if (c == 0) {
        return 0;
    }

    p = D_00795C14;

    do {
        if (c == '\n') {
        } else if (XB_IS_SJIS_LEAD(c)) {
            if (*s == 0) {
                break;
            }

            s++;
            w += p[0x1C];
        } else if (*(s32*)(p + 0x40) != 0) {
            w += p[0x1C] >> 1;
        } else {
            w += p[0x1C] * 2 / 3;
        }

        c = *s++;
    } while (c != 0);

    return w;
}

/* xb_PrintGlyphUV 0x17A98.
 *
 * Draws one cached glyph at the drawing position as a textured quad
 * (bilinear filtering for cells of 22 pixels and up). */

static void xb_PrintGlyphUV(s32 idx, u8* e) {
    u8* p = D_00795C14;
    s32 slot = ((u16*)(p + 0x142))[idx];
    s32 cell = slot % 0x79;
    u32 th = (((s32*)(p + 0x3E4C))[*(s16*)(e + 0xA)] << 16) | ((s32*)(p + 0x3E48))[slot / 0x79];
    f32 q[12];
    f32 off;

    sub_0004384A(1, &th);
    flSetRenderState(4, th);
    flSetRenderState(0x63, (e[8] >= 0x16 && e[9] >= 0x16) ? 0x10000 : 0);
    p = D_00795C14;
    q[0] = *(s16*)(p + 0x18);
    q[1] = *(s16*)(p + 0x1A);
    q[3] = e[8] + q[0];
    q[4] = e[9] + q[1];
    q[5] = *(f32*)(e + 4);
    q[2] = *(f32*)(e + 4);
    off = ((q[3] - q[0]) / 22.0f > 1.0f) ? 0.02f : 0.1f;
    *(s32*)&q[10] = *(s32*)(e + 0xC);
    *(u32*)&q[11] = th;
    q[6] = ((f32)(cell % 11) * 22.0f + off) * 0.00390625f;
    q[7] = ((f32)(cell / 11) * 22.0f + off) * 0.00390625f;
    q[8] = ((f32)(cell % 11) * 22.0f + off + 22.0f) * 0.00390625f;
    q[9] = ((f32)(cell / 11) * 22.0f + off + 22.0f) * 0.00390625f;
    ps2SeqsRenderQuad_Ax(q);
}

/* xb_PrintQueueGlyph 0x17C64.
 *
 * Gives a glyph not yet cached the next cache slot and queues it to be
 * drawn into the cache texture. */

static void xb_PrintQueueGlyph(u16 idx) {
    u8* p = D_00795C14;
    u16* slot = &((u16*)(p + 0x142))[idx];

    if (*slot == 0xFF) {
        *slot = *(u16*)(p + 0x3E44);
        (*(s32*)(p + 0x3E44))++;
        ((u16*)(p + 0x50))[(*(s32*)(p + 0x4C))++] = idx;
    }
}

/* xb_PrintString 0x17D00.
 *
 * printf to the print layer: adds the formatted string at the pen to the
 * small or large list (by scale; 0x80 each) and moves the pen past it.
 * Returns 0 when the list is full. */

s32 xb_PrintString(const char* fmt, ...) {
    u8* p = D_00795C14;
    s32 k = (s32)(*(f32*)(p + 0x14) / 1000.0f * 2.0f);
    u8* e;
    s32* used;
    s32 w;
    va_list ap;

    if (k < 0) {
        k = 0;
    }

    if (k >= 2) {
        k = 1;
    }

    if (XB_PW_COUNT(p, k) >= 0x80) {
        return 0;
    }

    e = XB_PW_LIST(p, k) + XB_PW_COUNT(p, k)++ * 0x14;
    *(s16*)e = *(s16*)(p + 0x10);
    *(s16*)(e + 2) = *(s16*)(p + 0x12);
    *(f32*)(e + 4) = *(f32*)(p + 0x14);
    e[8] = p[0x1C];
    e[9] = p[0x1D];
    *(s16*)(e + 0xA) = *(s16*)(p + 0x1E);
    *(s32*)(e + 0xC) = *(s32*)(p + 0x20);
    used = (s32*)(p + 0x38);
    *(char**)(e + 0x10) = *(char**)(p + 0x3C) + *used;
    va_start(ap, fmt);
    *used += vsprintf(*(char**)(e + 0x10), fmt, ap);
    va_end(ap);

    if ((u32)*used >= 0x8000) {
        *used = 0x7FFF;
    }

    p = D_00795C14;
    (*(char**)(p + 0x3C))[*used] = 0;
    (*used)++;
    w = xb_PrintTextWidth(*(char**)(e + 0x10));
    *(s16*)(p + 0x10) += w;
    return w;
}

/* xb_PrintDrawQueued 0x17DF3.
 *
 * Draws the queued glyphs into the cache texture, locking it once per
 * texture page. */

void xb_PrintDrawQueued(void) {
    u8* p = D_00795C14;
    XB_IMAGEINFO info;
    u32 th;
    s32 pg;
    s32 n;
    s32 cell;

    if (*(s32*)(p + 0x48) == *(s32*)(p + 0x4C)) {
        return;
    }

    for (pg = *(s32*)(p + 0x48) / 0x79; pg <= *(s32*)(p + 0x4C) / 0x79; pg++) {
        th = ((s32*)(p + 0x3E48))[pg];
        flLockTexture(0, th, &info, 0);
        p = D_00795C14;

        while ((n = *(s32*)(p + 0x48)) / 0x79 == pg && n < 0x79 && n != *(s32*)(p + 0x4C)) {
            cell = n % 0x79;
            xb_xlive_font_DrawQueue((u8*)info.d[4] + (((cell / 11) << 8) + n % 11) * 0x16,
                                    *(u8**)(p + 0xC) + ((u16*)(p + 0x50))[n] * 0x64);
            (*(s32*)(p + 0x48))++;
        }

        flUnlockTexture(th);
        p = D_00795C14;
    }
}

/* xb_PrintQueueText 0x17ED5.
 *
 * Queues every glyph of both string lists that is not cached yet.
 * Returns 1 when the queue (0x79) fills first. */

s32 xb_PrintQueueText(void) {
    u8* p = D_00795C14;
    s32 k;
    s32 i;
    const u8* s;
    u32 c;
    s32 idx;

    for (k = 0; k < 2; k++) {
        for (i = 0; i < XB_PW_COUNT(p, k); i++) {
            s = *(u8**)(XB_PW_LIST(p, k) + i * 0x14 + 0x10);

            while ((c = *s++) != 0) {
                if (c == '\n') {
                    continue;
                }

                if (XB_IS_SJIS_LEAD(c)) {
                    if (*s == 0) {
                        break;
                    }

                    c = (c << 8) | *s++;
                } else {
                    c = xb_AsciiToSjis(c);
                }

                if (c == 0x8140) {
                    continue;
                }

                idx = xb_PrintSjisIndex(c);

                if (idx < 0 || idx >= 0x1E80) {
                    continue;
                }

                xb_PrintQueueGlyph(idx);

                if (*(s32*)(D_00795C14 + 0x4C) >= 0x79) {
                    return 1;
                }
            }
        }
    }

    return 0;
}

/* xb_PrintDrawGlyph 0x17FA2.
 *
 * Draws one string entry's glyphs from the cache, starting at its pen
 * position; a newline goes back to its x and down a cell. */

static void xb_PrintDrawGlyph(u8* e, const u8* s) {
    u8* p = D_00795C14;
    u32 c;
    s32 idx;
    s32 half;

    *(s16*)(p + 0x18) = *(s16*)e;
    *(s16*)(p + 0x1A) = *(s16*)(e + 2);
    ps2SeqsRenderQuadInit_A();

    while ((c = *s++) != 0) {
        p = D_00795C14;

        if (c == '\n') {
            *(s16*)(p + 0x18) = *(s16*)e;
            *(s16*)(p + 0x1A) += e[9];
            continue;
        }

        if (XB_IS_SJIS_LEAD(c)) {
            if (*s == 0) {
                break;
            }

            c = (c << 8) | *s++;
            half = 0;
        } else {
            c = xb_AsciiToSjis(c);
            half = 1;
        }

        if (c != 0x8140 && (idx = xb_PrintSjisIndex(c)) >= 0) {
            xb_PrintGlyphUV(idx, e);
            p = D_00795C14;
        }

        if (!half) {
            *(s16*)(p + 0x18) += e[8];
        } else if (*(s32*)(p + 0x40) != 0) {
            *(s16*)(p + 0x18) += e[8] >> 1;
        } else {
            *(s16*)(p + 0x18) += e[8] * 2 / 3;
        }
    }

    ps2SeqsRenderQuadEnd();
}

void xb_PrintDrawPending(void) {
    *(s32*)(D_00795C14 + 0x44) = -1;

    if (xb_PrintQueueText()) {
        xb_PrintClear();
        xb_PrintQueueText();
    }

    xb_PrintDrawQueued();
}

/* xb_PrintFlush 0x180B1.
 *
 * Caches any new glyphs, then draws the large strings and the small
 * ones. */

void xb_PrintFlush(void) {
    u8* e;
    s32 k;
    s32 i;

    xb_PrintDrawPending();

    for (k = 1; k >= 0; k--) {
        e = XB_PW_LIST(D_00795C14, k);

        for (i = 0; i < XB_PW_COUNT(D_00795C14, k); i++, e += 0x14) {
            xb_PrintDrawGlyph(e, *(u8**)(e + 0x10));
        }
    }
}

/* xb_IncVBlankCount 0x176FF: counts vertical blanks for the pad layer. */

extern u32 D_00795C08;

void xb_IncVBlankCount(void) {
    D_00795C08++;
}
