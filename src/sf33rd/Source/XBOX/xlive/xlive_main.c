/* xlive_main.c: Xbox-only code from Capcom's xlive_main.cpp. Its _assert path names it, and the
 * code that pushes the path places it at 0x10668F to 0x109C88.
 * Capcom's source is lost. Its C++ methods are written as C,
 * XB_FASTCALL (__fastcall) with this first. Each body was checked
 * against retail by analysis-ps2map/xbgen.py. The xb_ names are
 * made up. */

#include "types.h"
#include <string.h>

void _assert(const char* expr, const char* file, u32 line);
extern char D_002B4FC0[];
extern char D_002B4F50[];
void xb_xlive_friend_Release(s32 id);
extern char D_002B5048[];
s8 xb_OnlineObj_Exists(s32 id);
void xb_xlive_disp_DrawCell(s32 a, s32 b, s32 c, s32 d, f32 e, f32 f, s32 g);
extern s32 D_003F8318;
extern u8* D_00798CAC;
extern char D_002B5094[];
s32 xb_OnlineStartup(s32 params);
void xb_LiveWork_InitTaskThunk(void);
void XB_FASTCALL xb_XLIVE_WORK_CLASS_Setup(void* self);
s32 xb_xlive_disp_DrawRectF(f32 a, f32 b, f32 c, f32 d, f32 e);
s32 xb_xlive_disp_SetObj0C(s32 id, s32 v);
s32 xb_xlive_ResetObj(s32 id, s32 keep);
extern s32 D_00798C9C;
extern s32 D_00798CA0;
void XB_STDCALL xb_ReleaseResource(s32 res);
s32 XB_STDCALL D3DDevice__CreateTexture(s32 w, s32 h, s32 levels, s32 usage, s32 fmt, s32 pool, s32* out);
s32 XB_STDCALL xb_GetSurfaceLevel(void* tex, s32 level, void** out);
s32 XB_STDCALL D3DDevice__Clear(s32 count, void* rects, s32 flags, u32 color, f32 z, s32 stencil);
extern u8 D_00798D50[];
void XB_FASTCALL CXBStopWatch_StartZero(void* self);
f32 XB_FASTCALL CXBStopWatch_GetElapsedSeconds(void* self);
void XB_FASTCALL CXBStopWatch_Stop(void* self);
void XB_FASTCALL CXBStopWatch_Reset(void* self);
extern u8 D_002B8328[];
s32 XB_FASTCALL CXBNetLink_IsActive(void* self);
void XB_FASTCALL xb_XLIVE_WORK_CLASS_ResetSessions(void* self);
extern u8 D_00798D00[];
extern char* D_007993A8;
extern u8* D_003F8314;
void XB_FASTCALL xb_WINSTR_CLASS_SetPos(u8* self, s32 edx, f32 x, f32 y, f32 w, f32 h, const char* str);
void XB_FASTCALL WINSTR_CLASS_SetCenteringState(u8* self, s32 edx, s32 state);
void XB_FASTCALL xb_WINSTR_CLASS_Reset(u8* self);
void XB_FASTCALL xb_LiveObj_Set1C(u8* self, s32 edx, s32 v);
u8* XB_FASTCALL xb_XLIVE_WORK_CLASS_Get2338(u8* self);
void xb_LiveTimer2_Reset(void);
void XB_FASTCALL xb_XLIVE_WORK_CLASS_UpdateTimer(void* self);
void xb_OnlineMenuDraw(void);
void XB_FASTCALL xb_WINSTR_CLASS_Update(void* self);
void XB_FASTCALL xb_CONNECT_USER_CLASS_UpdateIfActive(u8* self);
extern u8 D_00798CB0[];
s32 XB_FASTCALL CXBOnlineTask_Continue(void* self);
s32 XB_FASTCALL sub_000FBBB5(void* self);
void xb_xlive_main_SetMatchArgs(s32 hr, const char* file, s32 line, s32 a);
void sub_00107C43(s32 a, const char* file, s32 line, s32 b);
void xb_xlive_main_DrawStatus(s32 text);
extern char D_0025CCA0[];

void XB_FASTCALL xb_WINSTR_CLASS_Reset(u8* self) {
    *(s32*)(self + 8) = -1;
    *(s32*)(self + 0) = 0;
    *(s32*)(self + 4) = 0;
    *(f32*)(self + 0x18) = 0.0f;
    *(f32*)(self + 0x14) = 0.0f;
    *(f32*)(self + 0x10) = 0.0f;
    *(f32*)(self + 0xC) = 0.0f;
    self[0x30] = 0;
    *(f32*)(self + 0x2C) = 0.0f;
    *(u32*)(self + 0x28) = 0xA0000000;
}

void XB_FASTCALL WINSTR_CLASS_SetCenteringState(u8* self, s32 edx, s32 state) {
    (void)edx;

    if (!(state > -1 && state < 3)) {
        _assert(D_002B4FC0, D_002B4F50, 0x671);
    }

    *(s32*)(self + 0x1C) = state;
}

void XB_FASTCALL xb_WINSTR_CLASS_Release(s32* self) {
    xb_xlive_friend_Release(self[2]);
    self[2] = -1;
    self[0] = 0;
}

void XB_FASTCALL xb_WINSTR_CLASS_SetString(u8* self, s32 edx, const char* msg) {
    (void)edx;

    if (strlen(msg) > 0x1D) {
        _assert(D_002B5048, D_002B4F50, 0x6B3);
    }

    strcpy((char*)(self + 0x30), msg);
}

s32 XB_FASTCALL xb_WINSTR_CLASS_Exists(u8* self) {
    return xb_OnlineObj_Exists(*(s32*)(self + 8));
}

void XB_FASTCALL xb_XLIVE_WORK_CLASS_Tick15C(u8* self) {
    s32* t = (s32*)(self + 0x15C);

    if (++*t > 0x252) {
        *t = 0x1C;
    }
}

void xb_xlive_main_DrawMessage(s32 text) {
    xb_xlive_disp_DrawCell(D_003F8318, 5, text, 0, 0.6f, 19.0f, 0);
}

s32 xb_LiveWork_CheckMode3DC(void) {
    switch (*(s32*)(D_00798CAC + 0x3DC)) {
    case 0:
        return 0;

    case 1:
        return 1;

    case 2:
        return 1;
    }

    _assert(D_0025CCA0, D_002B4F50, 0x7DB);
    return 1;
}

s32 xb_LiveWork_UpdateMode3DC(void) {
    switch (*(s32*)(D_00798CAC + 0x3DC)) {
    case 0:
        return 0;

    case 2:
        xb_xlive_disp_DrawCell(D_003F8318, 5, 0xC, 0, 0.6f, 20.0f, 4);
        xb_xlive_main_DrawStatus(*(s32*)(D_00798CAC + 0x2D4));
        break;

    case 1:
        xb_xlive_disp_DrawCell(D_003F8318, 5, 0xC, 0, 0.6f, 20.0f, 4);
        xb_xlive_main_DrawMessage(*(s32*)(D_00798CAC + 0x2D0));
        break;
    }

    return 1;
}

s32 xb_LiveWork_Get14(void) {
    return *(s32*)(D_00798CAC + 0x14);
}

s32 XB_FASTCALL xb_XLIVE_WORK_CLASS_InitTask(u8* self) {
    s32 hr = xb_OnlineStartup(0);

    if (hr < 0) {
        _assert(D_002B5094, D_002B4F50, 0x89D);
    }

    if (hr != 0) {
        return -1;
    }

    *(s32*)(self + 0x264) = 0;
    *(s32*)(self + 0x268) = 0;
    xb_LiveWork_InitTaskThunk();
    return 1;
}

void xb_LiveWork_Call1071C4(void) {
    xb_XLIVE_WORK_CLASS_Setup(D_00798CAC);
}

s32 xb_LiveWork_Get1C4(void) {
    return *(s32*)(D_00798CAC + 0x1C4);
}

void xb_LiveWork_Set268(s32 v) {
    *(s32*)(D_00798CAC + 0x268) = v;
}

void xb_LiveWork_Set8(s32 v) {
    *(s32*)(D_00798CAC + 8) = v;
}

void xb_xlive_main_DrawBanner(void) {
    xb_xlive_friend_Release(D_003F8318);
    D_003F8318 = xb_xlive_disp_DrawRectF(120.0f, 140.0f, 520.0f, 340.0f, 99999.0f);
    xb_xlive_disp_SetObj0C(D_003F8318, 0xFF000000);
    xb_xlive_ResetObj(D_003F8318, 0);
}

s32 xb_LiveWork_Get2330(void) {
    if (D_00798CAC) {
        return *(s32*)(D_00798CAC + 0x2330);
    }

    return 0;
}

void xb_LiveWork_Set2330(s32 v) {
    if (D_00798CAC) {
        *(s32*)(D_00798CAC + 0x2330) = v;
    }
}

void xb_LiveWork_Set2334(s32 v) {
    if (D_00798CAC) {
        *(s32*)(D_00798CAC + 0x2334) = v;
    }
}

s32 xb_LiveWork_Get2334(void) {
    if (D_00798CAC) {
        return *(s32*)(D_00798CAC + 0x2334);
    }

    return -1;
}

void xb_CreateScreenTextures(void) {
    if (D_00798C9C) {
        xb_ReleaseResource(D_00798C9C);
        D_00798C9C = 0;

        if (D_00798CA0) {
            xb_ReleaseResource(D_00798CA0);
            D_00798CA0 = 0;
        }
    }

    D3DDevice__CreateTexture(640, 480, 1, 0, 0x12, 0, &D_00798CA0);
    xb_GetSurfaceLevel((void*)D_00798CA0, 0, (void**)&D_00798C9C);
    D3DDevice__Clear(0, 0, 0xF3, 0xFF000000, 1.0f, 0);
}

void xb_ReleaseScreenTextures(void) {
    if (D_00798C9C) {
        xb_ReleaseResource(D_00798C9C);
        D_00798C9C = 0;
    }

    if (D_00798CA0) {
        xb_ReleaseResource(D_00798CA0);
        D_00798CA0 = 0;
    }
}

/* xb_SelectRenderTarget 0x1074B7.
 *
 * Where the game draws: 0 the screen capture texture (D_00798C9C), 1 the
 * game screen texture (D_00474CCC), both cleared to black; anything else
 * the back buffer. Game.c draws the screen into the capture for the
 * Xbox Live overlay. */

extern void* D_00474CC4;
extern void* D_00474CC8;
extern void* D_00474CCC;
void XB_STDCALL D3DDevice__SetRenderTarget(void* target, void* zbuf);

void xb_SelectRenderTarget(s32 which) {
    if (which == 0) {
        D3DDevice__SetRenderTarget((void*)D_00798C9C, D_00474CC8);
    } else if (which == 1) {
        D3DDevice__SetRenderTarget(D_00474CCC, D_00474CC8);
    } else {
        D3DDevice__SetRenderTarget(D_00474CC4, D_00474CC8);
        return;
    }

    D3DDevice__Clear(0, 0, 0xF3, 0, 1.0f, 0);
}

/* xb_PresentScreenTexture 0x107503.
 *
 * Draws the capture texture's 384x224 game screen stretched over 640x448
 * at the back of the scene, blended, with the 640x480 viewport (which it
 * leaves set). The stage 0 and render states it changes are put back. */

typedef struct {
    f32 x;
    f32 y;
    f32 z;
    f32 rhw;
    f32 u;
    f32 v;
} XB_SCRVERTEX;

typedef struct {
    s32 x;
    s32 y;
    s32 w;
    s32 h;
    f32 min_z;
    f32 max_z;
} XB_SCRVIEWPORT;

extern u32 D_00463C84;
extern s32 D_0043FE60;
extern u32 D_004616B0;
s32 XB_STDCALL xb_GetTextureStageState(u32 stage, u32 state, u32* value);
s32 XB_STDCALL xb_SetTextureStageState(s32 stage, s32 state, s32 value);
s32 XB_STDCALL xb_SetRenderState(s32 state, s32 value);
void XB_STDCALL D3DDevice__SetTexture(s32 stage, s32 tex);
void XB_STDCALL D3DDevice__GetViewport(XB_SCRVIEWPORT* vp);
void XB_STDCALL D3DDevice__SetViewport(XB_SCRVIEWPORT* vp);
void XB_STDCALL D3DDevice__SetPixelShader(s32 handle);
void XB_STDCALL D3DDevice__SetVertexShader(s32 handle);
void XB_STDCALL D3DDevice__DrawPrimitiveUP(s32 type, s32 count, void* data, s32 stride);
s32 xb_Get7C5959(void);
void xb_UpdateRenderFlags(s32 flags);
s32 xb_ApplyRenderFlagChanges(s32 changed, s32 flags);
void xb_SetBlendMode(u32 cur, u32 next);

void xb_PresentScreenTexture(void) {
    XB_SCRVIEWPORT saved;
    XB_SCRVIEWPORT vp;
    XB_SCRVERTEX v[4];
    u32 op_c;
    u32 op_e;
    u32 op_f;
    u32 op_10;
    u32 op_12;
    u32 op_13;
    f32 x1;
    f32 y1;

    xb_GetTextureStageState(0, 0xC, &op_c);
    xb_GetTextureStageState(0, 0xE, &op_e);
    xb_GetTextureStageState(0, 0xF, &op_f);
    xb_GetTextureStageState(0, 0x10, &op_10);
    xb_GetTextureStageState(0, 0x12, &op_12);
    xb_GetTextureStageState(0, 0x13, &op_13);
    D3DDevice__SetTexture(0, D_00798CA0);
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
    D3DDevice__GetViewport(&saved);
    vp.min_z = 0.0f;
    vp.y = 0;
    vp.x = 0;
    vp.w = 640;
    vp.h = 480;
    vp.max_z = 1.0f;
    D3DDevice__SetViewport(&vp);
    xb_SetRenderState(0x3C, 1);
    xb_SetRenderState(0x4A, 0x8006);
    xb_SetRenderState(0x3E, 0x302);
    xb_SetRenderState(0x3F, 0x303);
    x1 = 0.0f + 640.0f - 1.0f;
    y1 = 0.0f + 448.0f;
    v[0].x = 0.0f;
    v[0].y = 0.0f;
    v[0].u = 0.5f;
    v[0].v = 0.5f;
    v[1].y = 0.0f;
    v[1].v = 0.5f;
    v[2].x = 0.0f;
    v[2].u = 0.5f;
    v[0].z = 0.999f;
    v[0].rhw = 1.0f;
    v[1].x = x1;
    v[1].z = 0.999f;
    v[1].rhw = 1.0f;
    v[1].u = 383.5f;
    v[2].y = y1;
    v[2].z = 0.999f;
    v[2].rhw = 1.0f;
    v[2].v = 223.5f;
    v[3].x = x1;
    v[3].y = y1;
    v[3].z = 0.999f;
    v[3].rhw = 1.0f;
    v[3].u = 383.5f;
    v[3].v = 223.5f;
    D3DDevice__SetPixelShader(0);
    D3DDevice__SetVertexShader(0x104);
    D3DDevice__DrawPrimitiveUP(6, 2, v, sizeof(XB_SCRVERTEX));
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
}

void xb_LiveTimer_Start(void) {
    CXBStopWatch_StartZero(D_00798D50);
}

f32 xb_LiveTimer_Elapsed(void) {
    return CXBStopWatch_GetElapsedSeconds(D_00798D50);
}

void xb_LiveTimer_Stop(void) {
    CXBStopWatch_Stop(D_00798D50);
    CXBStopWatch_Reset(D_00798D50);
}

void XB_FASTCALL xb_WINSTR_CLASS_Clear30(u8* self) {
    *(u8*)(self + 0x30) = 0x0;
}

void** XB_FASTCALL xb_XLIVE_PAGE_CLASS_ctor(void** self) {
    *self = D_002B8328;
    return self;
}

void xb_XLIVE_PAGE_CLASS_Clear(u8* page) {
    s32 i;

    for (i = 0; i < 0x14; i++) {
        ((s32*)page)[i + 1] = 0;
    }
}

void XB_FASTCALL xb_XLIVE_STARTMENU_CLASS_Set6E(u8* self, s32 edx, u8 v) {
    (void)edx;
    self[0x6E] = v;
}

void XB_FASTCALL xb_LiveObj_Set1C(u8* self, s32 edx, s32 v) {
    (void)edx;
    *(s32*)(self + 0x1C) = v;
}

s32 XB_FASTCALL xb_XLIVE_WORK_CLASS_Get60(u8* self) {
    return *(s32*)(self + 0x60);
}

u8* XB_FASTCALL xb_XLIVE_WORK_CLASS_Get2338(u8* self) {
    return self + 0x2338;
}

void XB_FASTCALL xb_XLIVE_WORK_CLASS_Set235C(u8* self, s32 edx, s8 v) {
    (void)edx;
    *(s32*)(self + 0x235C) = v;
}

void XB_FASTCALL xb_XLIVE_WORK_CLASS_Set2360(u8* self, s32 edx, s8 v) {
    (void)edx;
    *(s32*)(self + 0x2360) = v;
}

s32 XB_FASTCALL xb_XLIVE_WORK_CLASS_CheckNetLink(u8* self) {
    s32 r = 0;

    if (!CXBNetLink_IsActive(self + 0xD8)) {
        xb_XLIVE_WORK_CLASS_ResetSessions(self);
        r = -1;
    }

    return r;
}

s32 XB_FASTCALL xb_XLIVE_WORK_CLASS_Frame(u8* self) {
    xb_XLIVE_WORK_CLASS_UpdateTimer(self);
    xb_OnlineMenuDraw();

    if (xb_LiveWork_UpdateMode3DC()) {
        return 1;
    }

    self += 0x59E0;

    if (xb_XLIVE_WORK_CLASS_Get60(self) < 0) {
        return 1;
    }

    xb_WINSTR_CLASS_Update(D_00798D00);
    xb_WINSTR_CLASS_Update(D_00798CB0);
    xb_CONNECT_USER_CLASS_UpdateIfActive(self);
    return 0;
}

void xb_LiveTimer2_Reset(void) {
    xb_WINSTR_CLASS_Reset(D_00798D00);
}

/* xb_LiveTimer2_Start 0x10867E: shows str in the status window
 * (D_00798D00) across the top of the screen, centred. */
void XB_FASTCALL xb_LiveTimer2_Start(u8* self, s32 edx, const char* str) {
    xb_WINSTR_CLASS_SetPos(D_00798D00, edx, 28.0f, 26.0f, 614.0f, 54.0f, str);
    WINSTR_CLASS_SetCenteringState(D_00798D00, edx, 1);
}

/* xb_XLIVE_WORK_CLASS_ResetState 0x10884E: back to the start of the Live
 * flow with the status window showing D_007993A8. */
void XB_FASTCALL xb_XLIVE_WORK_CLASS_ResetState(u8* self) {
    s32 i;

    for (i = 0; i < 0x14; i++) {
        ((s32*)(self + 0x2364))[i] = 0;
        ((s32*)(self + 0x23B4))[i] = 0;
    }

    *(s32*)(self + 0xC) = 0;
    *(s32*)(self + 0x94) = 6;
    *(s32*)(self + 0x98) = 7;
    *(s32*)(self + 0x9C) = 8;
    *(s32*)(self + 0xA0) = 2;
    *(s32*)(self + 0x3DC) = 0;
    *(s32*)(self + 0x2CC) = 0;
    *(s32*)(self + 0xD0) = 0;
    memset(self + 0xB4, 0, 8);
    memset(self + 0xBC, 0, 0x10);
    *(s32*)(self + 0x158) = 0;
    *(s32*)(self + 0x15C) = 0x1C;
    *(s32*)(self + 0x3E0) = 0;
    xb_LiveTimer2_Reset();
    xb_LiveTimer2_Start(self, 0, D_007993A8);
    xb_LiveObj_Set1C(xb_XLIVE_WORK_CLASS_Get2338(self), 0, 0);
    xb_WINSTR_CLASS_Reset(D_003F8314);
}

void XB_FASTCALL xb_WINSTR_CLASS_SetPos(u8* self, s32 edx, f32 x, f32 y, f32 w, f32 h, const char* str) {
    xb_WINSTR_CLASS_SetString(self, edx, str);
    *(f32*)(self + 0xC) = x;
    *(f32*)(self + 0x10) = y;
    *(f32*)(self + 0x14) = w;
    *(s32*)(self + 0) = 1;
    *(f32*)(self + 0x18) = h;
}

void* XB_FASTCALL xb_ReturnThis(void* self, s32 edx, s32 a0) {
    (void)edx;
    (void)a0;
    return self;
}

s32 XB_FASTCALL xb_XLIVE_WORK_CLASS_ContinueTaskF8(u8* self) {
    s32 r = 0;
    s32 hr;

    if (*(s32*)(self + 0xC) != 0) {
        hr = CXBOnlineTask_Continue(self + 0xF8);

        if (hr < 0 || (hr = sub_000FBBB5(self + 0x25D0)) < 0) {
            xb_XLIVE_WORK_CLASS_ResetSessions(self);
            xb_xlive_main_SetMatchArgs(hr, D_002B4F50, 0x17C, 1);
            r = -1;
        }
    }

    return r;
}

s32 XB_FASTCALL xb_XLIVE_WORK_CLASS_Update(u8* self) {
    s32* f = (s32*)(self + 0x2358);

    if (*f && xb_XLIVE_WORK_CLASS_CheckNetLink(self) == -1) {
        *f = 0;
        sub_00107C43(1, D_002B4F50, 0x190, 1);
        return -1;
    }

    return (xb_XLIVE_WORK_CLASS_ContinueTaskF8(self) != -1) - 1;
}
