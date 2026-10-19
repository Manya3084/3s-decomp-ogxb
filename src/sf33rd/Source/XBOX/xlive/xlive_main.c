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
s32 xb_OnlineMenuDraw(void);
void XB_FASTCALL xb_WINSTR_CLASS_Update(void* self);
void XB_FASTCALL xb_CONNECT_USER_CLASS_UpdateIfActive(u8* self);
extern u8 D_00798CB0[];
s32 XB_FASTCALL CXBOnlineTask_Continue(void* self);
s32 XB_FASTCALL xb_XLIVE_FRIEND_CLASS_PollTask10C(void* self);
s32 xb_xlive_main_SetMatchArgs(s32 hr, const char* file, s32 line, s32 a);
s32 xb_xlive_main_SetErrorArgs(s32 hr, const char* file, s32 line, s32 fatal);
s32 xb_xlive_main_DrawStatus(s32 code);
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

        if (hr < 0 || (hr = xb_XLIVE_FRIEND_CLASS_PollTask10C(self + 0x25D0)) < 0) {
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
        xb_xlive_main_SetErrorArgs(1, D_002B4F50, 0x190, 1);
        return -1;
    }

    return (xb_XLIVE_WORK_CLASS_ContinueTaskF8(self) != -1) - 1;
}

extern char D_002B50CC[];

/* xb_LiveWork_Clear3DC 0x10730E: the work's +0x3DC cleared. */
void xb_LiveWork_Clear3DC(void) {
    if (D_00798CAC == 0) {
        _assert(D_002B50CC, D_002B4F50, 0x935);
    }

    *(s32*)(D_00798CAC + 0x3DC) = 0;
}

/* xb_xlive_main_ClearWin 0x107BF8: the main text window (D_00798D00)
 * cleared. */
void XB_FASTCALL xb_xlive_main_ClearWin(void* self) {
    xb_WINSTR_CLASS_Clear30(D_00798D00);
}

extern char D_002B50A4[];

/* xb_LiveWork_SetFlag 0x1072B7: one of the work's 20 flags (+0x2364). */
void xb_LiveWork_SetFlag(s32 i, s32 v) {
    if (D_00798CAC == 0) {
        _assert(D_002B50CC, D_002B4F50, 0x92A);
    }

    if (i < 0 || i >= 0x14) {
        _assert(D_002B50A4, D_002B4F50, 0x92B);
    }

    *(s32*)(D_00798CAC + i * 4 + 0x2364) = v;
}

void XB_FASTCALL xb_CONNECT_USER_CLASS_SetState(u8* self);

/* xb_LiveWork_StopUserCount 0x1073B8: the connected users counter
 * (+0x59E0) stopped. */
void xb_LiveWork_StopUserCount(void) {
    xb_CONNECT_USER_CLASS_SetState(D_00798CAC + 0x59E0);
}

/* xb_XLIVE_WORK_CLASS_Get2360 0x107906. */
u8 XB_FASTCALL xb_XLIVE_WORK_CLASS_Get2360(u8* self) {
    return self[0x2360];
}

/* xb_LiveWork_Get2360 0x10790D. */
u8 xb_LiveWork_Get2360(void) {
    return xb_XLIVE_WORK_CLASS_Get2360(D_00798CAC);
}

/* xb_LiveWork_Set2360 0x107918. */
void xb_LiveWork_Set2360(s32 v) {
    XB_ARG a;

    a.v = v;
    ((void (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_WORK_CLASS_Set2360)(D_00798CAC, a);
}

/* xb_XLIVE_WORK_CLASS_ResetFlags 0x107928: the work's flags (+0x2364)
 * and their second set (+0x23B4) cleared and its settings back to their
 * defaults. */
void XB_FASTCALL xb_XLIVE_WORK_CLASS_ResetFlags(u8* self) {
    s32 i;
    XB_ARG a;

    for (i = 0; i < 0x14; i++) {
        *(s32*)(self + 0x2364 + i * 4) = 0;
        *(s32*)(self + 0x23B4 + i * 4) = 0;
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
    a.v = 0;
    ((void (XB_FASTCALL*)(u8*, XB_ARG))xb_LiveObj_Set1C)(xb_XLIVE_WORK_CLASS_Get2338(self), a);
}

extern u8* D_003F8310;
void XB_FASTCALL xb_CONNECT_USER_CLASS_Release(u8* self);
void xb_xlive_disp_Reset(void);
void XB_FASTCALL xb_XLIVE_STARTMENU_CLASS_ReleaseHandles(u8* self);

/* xb_xlive_main_SetMatchArgs 0x107D24: a Live error kept for the error
 * page: the result (+0x2D4), the source file (+0x2D8, 0xFE characters)
 * and line (+0x3D8); a fatal one (+0x3DC 2) also closes the windows.
 * Returns -1. */
s32 xb_xlive_main_SetMatchArgs(s32 hr, const char* file, s32 line, s32 fatal) {
    s32 n;

    *(s32*)(D_00798CAC + 0x2D4) = hr;
    *(s32*)(D_00798CAC + 0x3DC) = fatal != 0 ? 2 : 0;

    if (fatal != 0) {
        if (xb_WINSTR_CLASS_Exists(D_003F8310)) {
            xb_WINSTR_CLASS_Release((s32*)D_003F8310);
        }

        if (xb_WINSTR_CLASS_Exists(D_003F8314)) {
            xb_WINSTR_CLASS_Release((s32*)D_003F8314);
        }

        xb_CONNECT_USER_CLASS_Release(D_00798CAC + 0x59E0);
        xb_xlive_disp_Reset();
        xb_xlive_main_DrawBanner();
        xb_XLIVE_STARTMENU_CLASS_ReleaseHandles(D_00798CAC + 0x24C0);
    }

    n = strlen(file);

    if (n < 0xFE) {
        strcpy((char*)D_00798CAC + 0x2D8, file);
    } else {
        /* retail offsets the copy by the length, not the source */
        strcpy((char*)D_00798CAC + 0x2D8 + (n - 0xFE), file);
    }

    *(s32*)(D_00798CAC + 0x3D8) = line;
    return -1;
}

s32 XB_FASTCALL xb_XLIVE_STAT_CLASS_CloseTasks(u8* self);
s32 XB_FASTCALL CXBOnlineTask_Close(void* self);
s32 XB_STDCALL XNetUnregisterKey(void* kid);
extern char D_002B4F38[];

/* xb_XLIVE_WORK_CLASS_ResetSessions 0x10668F: every online task closed
 * (the two stats pages' and the work's), the session key unregistered,
 * and the invitation state cleared. */
void XB_FASTCALL xb_XLIVE_WORK_CLASS_ResetSessions(void* self) {
    u8* w = (u8*)self;

    *(s32*)(w + 0xC) = 0;
    xb_XLIVE_STAT_CLASS_CloseTasks(w + 0x5090);
    xb_XLIVE_STAT_CLASS_CloseTasks(w + 0x5538);
    CXBOnlineTask_Close(w + 0x100);
    CXBOnlineTask_Close(w + 0x108);
    CXBOnlineTask_Close(w + 0x11C);
    CXBOnlineTask_Close(w + 0x118);
    CXBOnlineTask_Close(w + 0x110);
    CXBOnlineTask_Close(w + 0x114);
    CXBOnlineTask_Close(w + 0x10C);
    CXBOnlineTask_Close(w + 0xFC);
    CXBOnlineTask_Close(w + 0xF8);

    if (*(s32*)(D_00798CAC + 0xD0) != 0) {
        if (XNetUnregisterKey(w + 0xB4) != 0) {
            _assert(D_002B4F38, D_002B4F50, 0x470);
        }

        *(s32*)(D_00798CAC + 0xD0) = 0;
        memset(w + 0xB4, 0, 8);
    }

    *(s32*)(w + 0x1C4) = 0;
    *(s32*)(w + 0x264) = 0;
    *(s32*)(w + 0x2464) = 1;
}

/* The launch data the game passes itself when it relaunches from a
 * friend's invitation: a flag, the accepted invitation (0x56 bytes) and
 * the session's 12 bytes. */
typedef struct {
    u8 b[0x56];
} XB_INVITE56;
typedef struct {
    u32 w[3];
} XB_KEY12;
typedef struct {
    u8 flag;
    XB_INVITE56 invite;
    u8 pad57;
    XB_KEY12 key;
} XB_LIVELAUNCH;
s32 XB_STDCALL XGetLaunchInfo(u32* type, void* data);
/* An XONLINES export not yet identified, given the invitation buffer. */
s32 XB_STDCALL sub_001D5373(void* invite);

/* xb_XLIVE_WORK_CLASS_Setup 0x1071C4: an accepted game invitation, from
 * XONLINES or from the launch data (type 0, flag set), copied in (+0x1C8,
 * +0x220) and flagged (+0x1C4, +0x264). */
void XB_FASTCALL xb_XLIVE_WORK_CLASS_Setup(void* self) {
    u8* w = (u8*)self;
    u32 type;
    s32 hr;
    u8 data[0xC00];
    XB_LIVELAUNCH ld;

    hr = sub_001D5373(w + 0x1C8);
    *(s32*)(w + 0x1C4) = 0;
    type = 0xFFFFFFFF;
    memset(data, 0, sizeof(data));

    if (XGetLaunchInfo(&type, data) == 0 && type == 0) {
        ld = *(XB_LIVELAUNCH*)data;

        if (ld.flag != 0) {
            hr = 0;
            *(XB_INVITE56*)(w + 0x1C8) = ld.invite;
            *(XB_KEY12*)(w + 0x220) = ld.key;
        }
    }

    if (hr == 0) {
        *(s32*)(w + 0x1C4) = 1;
        *(s32*)(w + 0x264) = 1;
    }
}

void** XB_FASTCALL xb_iterator_ctor(void** self, s32 edx, void* p);
void* XB_FASTCALL xb_xlive_friend_GetElem4(void* self, s32 edx, void* out);
void* XB_FASTCALL xb_xlive_friend_GetElem8(void* self, s32 edx, void* out);
void xb_vector_FindIf(void** out, void* first, void* last, void* key);
s32 XB_FASTCALL xb_xlive_disp_IsMissing(s32* self, s32 edx, s32* other);

/* xb_XLIVE_WORK_CLASS_FindUser 0x108C55: whether the key is in the
 * work's user list (+0x120). */
s32 XB_FASTCALL xb_XLIVE_WORK_CLASS_FindUser(u8* self, s32 edx, void* key) {
    void* k;
    void* first;
    void* last;
    void* end;
    void* r;
    void** pk;
    void** pl;
    void** pf;
    XB_ARG a;

    (void)edx;
    a.v = (s32)key;
    pk = ((void** (XB_FASTCALL*)(void**, XB_ARG))xb_iterator_ctor)(&k, a);
    a.v = (s32)&last;
    pl = (void**)((void* (XB_FASTCALL*)(u8*, XB_ARG))xb_xlive_friend_GetElem8)(self + 0x120, a);
    a.v = (s32)&first;
    pf = (void**)((void* (XB_FASTCALL*)(u8*, XB_ARG))xb_xlive_friend_GetElem4)(self + 0x120, a);
    xb_vector_FindIf(&r, *pf, *pl, *pk);
    a.v = (s32)&end;
    a.v = (s32)((void* (XB_FASTCALL*)(u8*, XB_ARG))xb_xlive_friend_GetElem8)(self + 0x120, a);
    return (u8)((s32 (XB_FASTCALL*)(void*, XB_ARG))xb_xlive_disp_IsMissing)(&r, a) != 0;
}

/* Two XONLINES exports not yet identified: the first takes a task, the
 * second the user, a count (250), a task, a buffer and a count out. */
s32 XB_STDCALL sub_001D538D(s32 a, s32 task);
s32 XB_FASTCALL CXBOnlineTask_operator_addr(void* self);
s32 XB_STDCALL sub_001D537E(s32 user, u32 max, s32 a, s32 task, void* buf, void* count);
void XB_FASTCALL xb_vector10_Resize(void* self, s32 edx, u32 n);
u8* XB_FASTCALL xb_vector10_Subscript(void* self, s32 edx, u32 i);

/* xb_XLIVE_WORK_CLASS_CloseMatchTask 0x109C88: the tasks at +0x118 and
 * +0x11C restarted: the first, then the second into a list of 250 (+0x120,
 * count +0x130). On an error both are closed and -1 returned. */
s32 XB_FASTCALL xb_XLIVE_WORK_CLASS_CloseMatchTask(u8* self) {
    u8* t1 = self + 0x118;
    s32 hr;
    XB_ARG a;
    XB_ARG b;

    CXBOnlineTask_Close(t1);
    CXBOnlineTask_Close(self + 0x11C);
    hr = sub_001D538D(0, CXBOnlineTask_operator_addr(t1));

    if (hr < 0) {
        xb_xlive_main_SetMatchArgs(hr, D_002B4F50, 0x4D7, 1);
    } else {
        a.v = 0xFA;
        ((void (XB_FASTCALL*)(u8*, XB_ARG))xb_vector10_Resize)(self + 0x120, a);
        b.v = 0;
        hr = sub_001D537E(*(s32*)(self + 0x14), 0xFA, 0, CXBOnlineTask_operator_addr(self + 0x11C),
                          ((u8* (XB_FASTCALL*)(u8*, XB_ARG))xb_vector10_Subscript)(self + 0x120, b), self + 0x130);

        if (hr >= 0) {
            *(s32*)(self + 0x134) = 0;
            return 0;
        }

        xb_xlive_main_SetMatchArgs(hr, D_002B4F50, 0x4E4, 1);
    }

    CXBOnlineTask_Close(t1);
    CXBOnlineTask_Close(self + 0x11C);
    return -1;
}

/* The Live error codes with their own message (D_004185D0, -1 ends). */
extern s32 D_004185D0[];
extern f32 D_002B5084;
extern f32 D_0025F370;
extern f32 D_002B4E98;
extern f32 D_00219420;
extern char D_002B5088[];
s32 XB_FASTCALL xb_XLIVE_WORK_CLASS_CheckPad(u8* self);
void xb_xlive_disp_DrawRectI(s32 font, f32 x, f32 y, f32 s, s32 text, f32 size, s32 flags, s32 c);
int sprintf(char* buf, const char* fmt, ...);

/* xb_xlive_main_DrawStatus 0x106EC0: the message for a Live error code;
 * one without its own shows the general message and, with a pad check,
 * the code (the work's +0x2D4). 1 for a known code. */
s32 xb_xlive_main_DrawStatus(s32 code) {
    char buf[0x20];
    s32 i;

    for (i = 0; D_004185D0[i] != code; i++) {
        if (D_004185D0[i] == -1) {
            xb_xlive_disp_DrawCell(D_003F8318, 5, 0x11, 0, D_0025F370, D_002B5084, 0);

            if (xb_XLIVE_WORK_CLASS_CheckPad(D_00798CAC)) {
                sprintf(buf, D_002B5088, *(s32*)(D_00798CAC + 0x2D4));
                xb_xlive_disp_DrawRectI(D_003F8318, D_00219420, D_002B4E98, D_0025F370, (s32)buf, D_002B5084, 0, 1);
            }

            return 0;
        }
    }

    xb_xlive_disp_DrawCell(D_003F8318, 6, i, 0, D_0025F370, D_002B5084, 0);
    return 1;
}

s32 sub_0004AFFA(void);
extern s32 D_0079811C;
extern f32 D_002190E8;
extern f32 D_002B4BE4;
extern f32 D_002190A4;
extern f32 D_0021CCE0;

#define XB_WINSTR_Y(w) ((*(f32*)((w) + 0x18) + *(f32*)((w) + 0x10) - D_002B4BE4) / D_002190A4)

/* xb_WINSTR_CLASS_Update 0x1068F3: a shown text window's (state 3) text
 * (+0x30) drawn on its own object (+8, the focus object D_0079811C while
 * its alpha +0x2C is low), centred in its height: from the left edge,
 * centred in its width, or at its margin (+0x20) by its alignment
 * (+0x1C). */
void XB_FASTCALL xb_WINSTR_CLASS_Update(void* self) {
    u8* w = (u8*)self;
    s32 obj;

    if (sub_0004AFFA() != 0 || *(s32*)w != 3) {
        return;
    }

    obj = *(f32*)(w + 0x2C) > D_002190E8 ? *(s32*)(w + 8) : D_0079811C;

    switch (*(s32*)(w + 0x1C)) {
    case 0:
        xb_xlive_disp_DrawRectI(obj, 0.0f, XB_WINSTR_Y(w), D_0025F370, (s32)(w + 0x30), D_002B4BE4, 5, 0);
        break;
    case 1:
        xb_xlive_disp_DrawRectI(obj, (*(f32*)(w + 0x14) + *(f32*)(w + 0xC)) / D_002190A4 - (f32)strlen((char*)(w + 0x30)) / D_002190A4 * D_0021CCE0, XB_WINSTR_Y(w),
                                D_0025F370, (s32)(w + 0x30), D_002B4BE4, 5, 1);
        break;
    case 2:
        xb_xlive_disp_DrawRectI(obj, (f32)*(s32*)(w + 0x20), XB_WINSTR_Y(w), D_0025F370, (s32)(w + 0x30), D_002B4BE4, 5, 1);
        break;
    }
}

/* xb_xlive_disp_DrawObj takes the depth as its fourth argument, which it
 * does not use (xlive_disp.c names it u0). */
void xb_xlive_disp_DrawObj(s32 id, f32 x, f32 y, f32 z, u32 col, s32 icon, f32 sx, f32 sy);
extern f32 D_002B5068;
extern f32 D_002B506C;
extern f32 D_002B5070;
extern f32 D_002B5074;
extern f32 D_002B5078;
extern f32 D_002B507C;
extern f32 D_002B5080;
extern f32 D_002190AC;
extern f32 D_002190D4;
extern f32 D_002190F0;
extern f32 D_002193F4;
extern f32 D_00289A4C;

/* xb_XLIVE_WORK_CLASS_UpdateTimer 0x106B44: while the work runs (+0xC),
 * the two pad icons that pulse in (+0x158: icon 3, +0x150: icon 1): each
 * grows in for 30 frames, shrinks out for 30, five times (+0x161, +0x155),
 * then stays. Their alpha fades with the timer +0x15C. */
void XB_FASTCALL xb_XLIVE_WORK_CLASS_UpdateTimer(void* self) {
    u8* w = (u8*)self;
    s32 t;
    s32 a;
    u32 col;
    f32 s;

    if (*(s32*)(w + 0xC) == 0) {
        return;
    }

    t = *(s32*)(w + 0x15C);

    if (t < 0x3C) {
        a = (t - 0x1C) * 0xFF / 0x20;
    } else if (t > 0x232) {
        a = (0x252 - t) * 0xFF / 0x20;
    } else {
        a = 0xFF;
    }

    col = ((((a << 8) | a) << 8 | a) << 8) | a;

    if (*(s32*)(w + 0x158) != 0) {
        w[0x160]++;

        if ((s8)w[0x161] < 5) {
            if ((s8)w[0x160] < 0x1E) {
                s = (f32)(s8)w[0x160] * D_002B5080 + D_002190AC;
                xb_xlive_disp_DrawObj(-1, D_002B5074 - (f32)(s8)w[0x160] * D_002B507C, D_002B5078 - (f32)(s8)w[0x160] * D_002B507C,
                                      D_002190F0, col, 3, s, s);
            }

            if ((s8)w[0x160] > 0x1E) {
                s = D_00289A4C - ((f32)(s8)w[0x160] - D_00219420) * D_002B5080;
                xb_xlive_disp_DrawObj(-1, ((f32)(s8)w[0x160] - D_00219420) * D_002B507C + D_002B5070,
                                      ((f32)(s8)w[0x160] - D_00219420) * D_002B507C + D_002193F4, D_002190F0, col, 3, s, s);
            }

            if ((s8)w[0x160] > 0x3C) {
                w[0x161]++;
                w[0x160] = 0;
            }
        } else {
            xb_xlive_disp_DrawObj(-1, D_002B5074, D_002B5078, D_002190F0, col, 3, D_002190D4, D_002190D4);
        }
    }

    if (*(s32*)(w + 0x150) != 0) {
        w[0x154]++;

        if ((s8)w[0x155] < 5) {
            if ((s8)w[0x154] < 0x1E) {
                s = (f32)(s8)w[0x154] * D_002B5080 + D_002190AC;
                xb_xlive_disp_DrawObj(-1, D_002B506C - (f32)(s8)w[0x154] * D_002B507C, D_002B5078 - (f32)(s8)w[0x154] * D_002B507C,
                                      D_002190F0, col, 1, s, s);
            }

            if ((s8)w[0x154] > 0x1E) {
                s = D_00289A4C - ((f32)(s8)w[0x154] - D_00219420) * D_002B5080;
                xb_xlive_disp_DrawObj(-1, ((f32)(s8)w[0x154] - D_00219420) * D_002B507C + D_002B5068,
                                      ((f32)(s8)w[0x154] - D_00219420) * D_002B507C + D_002193F4, D_002190F0, col, 1, s, s);
            }

            if ((s8)w[0x154] > 0x3C) {
                w[0x155]++;
                w[0x154] = 0;
            }
        } else {
            xb_xlive_disp_DrawObj(-1, D_002B506C, D_002B5078, D_002190F0, col, 1, D_002190D4, D_002190D4);
        }
    }
}

void XB_FASTCALL xb_WINSTR_CLASS_SetString(u8* self, s32 edx, const char* msg);

/* xb_xlive_main_SetWinText 0x107BEE: the main text window's (D_00798D00)
 * text. A work method; the work is not used. */
void XB_FASTCALL xb_xlive_main_SetWinText(u8* self, s32 edx, const char* msg) {
    XB_ARG a;

    (void)self;
    (void)edx;
    a.v = (s32)msg;
    ((void (XB_FASTCALL*)(u8*, XB_ARG))xb_WINSTR_CLASS_SetString)(D_00798D00, a);
}

/* The three end of match messages (D_00798E94, filled once, flag bit 1 of
 * D_00798EA0). */
extern u32 D_00798EA0;
extern char* D_00798E94[3];
extern char* D_0079911C;
extern char* D_00799154;
extern char* D_00799260;

/* xb_XLIVE_WORK_CLASS_ShowMessage 0x109E03: end of match message i in the
 * main text window. */
void XB_FASTCALL xb_XLIVE_WORK_CLASS_ShowMessage(u8* self, s32 edx, u8 i) {
    XB_ARG a;

    (void)self;
    (void)edx;

    if ((D_00798EA0 & 1) == 0) {
        D_00798EA0 |= 1;
        D_00798E94[0] = D_0079911C;
        D_00798E94[1] = D_00799154;
        D_00798E94[2] = D_00799260;
    }

    a.v = (s32)D_00798E94[i];
    ((void (XB_FASTCALL*)(u8*, XB_ARG))xb_xlive_main_SetWinText)(D_00798CAC, a);
}

/* xb_xlive_main_SetErrorArgs 0x107C43: as xb_xlive_main_SetMatchArgs, for
 * the other result (+0x2D0); a fatal one sets +0x3DC to 1. Returns -1. */
s32 xb_xlive_main_SetErrorArgs(s32 hr, const char* file, s32 line, s32 fatal) {
    s32 n;

    *(s32*)(D_00798CAC + 0x2D0) = hr;
    *(s32*)(D_00798CAC + 0x3DC) = fatal != 0;

    if (fatal != 0) {
        if (xb_WINSTR_CLASS_Exists(D_003F8310)) {
            xb_WINSTR_CLASS_Release((s32*)D_003F8310);
        }

        if (xb_WINSTR_CLASS_Exists(D_003F8314)) {
            xb_WINSTR_CLASS_Release((s32*)D_003F8314);
        }

        xb_CONNECT_USER_CLASS_Release(D_00798CAC + 0x59E0);
        xb_xlive_disp_Reset();
        xb_xlive_main_DrawBanner();
        xb_XLIVE_STARTMENU_CLASS_ReleaseHandles(D_00798CAC + 0x24C0);
    }

    n = strlen(file);

    if (n < 0xFE) {
        strcpy((char*)D_00798CAC + 0x2D8, file);
    } else {
        strcpy((char*)D_00798CAC + 0x2D8 + (n - 0xFE), file);
    }

    *(s32*)(D_00798CAC + 0x3D8) = line;
    return -1;
}

/* xb_WINSTR_CLASS_SetState6 0x106ABC. */
void XB_FASTCALL xb_WINSTR_CLASS_SetState6(u8* self) {
    *(s32*)self = 6;
}

/* xb_WINSTR_CLASS_SetColor 0x106A6C: a text window's colour (+0x28). */
void XB_FASTCALL xb_WINSTR_CLASS_SetColor(u8* self, s32 edx, u32 col) {
    (void)edx;
    *(u32*)(self + 0x28) = col;
}

/* xb_WINSTR_CLASS_SetAlpha 0x106A76: a text window's alpha (+0x2C). */
void XB_FASTCALL xb_WINSTR_CLASS_SetAlpha(u8* self, s32 edx, f32 a) {
    (void)edx;
    *(f32*)(self + 0x2C) = a;
}

s32 xb_xlive_disp_DrawRectFloat(f32 x, f32 y, f32 w, f32 h);
void xb_OnlineObj_Move(s32 id);
void xb_OnlineObj_Fade(s32 id);
u8 xb_OnlineObj_IsDone(s32 id);
extern char D_0025CCA0[];

/* xb_xlive_main_StepState 0x1067BE: a text window's window (+8): opened
 * from its rectangle (+0xC, its alpha +0x2C and colour +0x28) in state 1,
 * or at once in state 7, shown (3), closed (4 to 6) and released. */
void XB_FASTCALL xb_xlive_main_StepState(u8* self) {
    s32 id;

    switch (*(s32*)self) {
    case 0:
    case 3:
        break;
    case 1:
    case 7:
        if (sub_0004AFFA()) {
            break;
        }

        if (*(f32*)(self + 0x2C) > D_002190E8) {
            id = xb_xlive_disp_DrawRectF(*(f32*)(self + 0xC), *(f32*)(self + 0x10), *(f32*)(self + 0x14), *(f32*)(self + 0x18),
                                         *(f32*)(self + 0x2C));
        } else {
            id = xb_xlive_disp_DrawRectFloat(*(f32*)(self + 0xC), *(f32*)(self + 0x10), *(f32*)(self + 0x14), *(f32*)(self + 0x18));
        }

        *(s32*)(self + 8) = id;
        xb_xlive_disp_SetObj0C(id, *(s32*)(self + 0x28));
        xb_OnlineObj_Move(*(s32*)(self + 8));

        if (*(s32*)self == 7) {
            xb_xlive_ResetObj(*(s32*)(self + 8), 0);
            *(s32*)self = 3;
        } else {
            *(s32*)self = 2;
        }

        break;
    case 2:
        if (xb_OnlineObj_IsDone(*(s32*)(self + 8))) {
            *(s32*)self = 3;
        }

        break;
    case 4:
        xb_OnlineObj_Fade(*(s32*)(self + 8));
        *(s32*)self = 5;
        break;
    case 5:
        if (xb_OnlineObj_IsDone(*(s32*)(self + 8)) == 0) {
            break;
        }
    case 6:
        xb_xlive_friend_Release(*(s32*)(self + 8));
        *(s32*)(self + 8) = -1;
        *(s32*)self = 0;
        break;
    default:
        _assert(D_0025CCA0, D_002B4F50, 0x61D);
        break;
    }
}

/* A notification read (XOnlineNotificationIsPending's result, an export
 * not yet named): its type, then the rest. */
typedef struct {
    u8 type;
    u8 pad1;
    u16 pad2;
    u32 a;
    u8 b;
} XB_NOTE9;
s32 XB_STDCALL sub_001D52A1(s32 user, XB_NOTE9* note, s32* n);
void XB_FASTCALL xb_XLIVE_WORK_CLASS_Tick15C(u8* self);

/* xb_XLIVE_WORK_CLASS_PollStatus 0x107B56: a pending notification starts
 * the pad icons pulsing: a friend request (2) the first, a game invitation
 * (3) the second with its fade timer. */
void XB_FASTCALL xb_XLIVE_WORK_CLASS_PollStatus(u8* self) {
    XB_NOTE9 note;
    s32 n;

    memset(&note, 0, 9);
    n = 0;

    if (*(s32*)(self + 0xC) != 0 && sub_001D52A1(*(s32*)(self + 0x14), &note, &n)) {
        if (note.type == 2) {
            *(s32*)(self + 0x150) = 1;
            self[0x154] = 0;
            self[0x155] = 0;
        }

        if (note.type == 3) {
            *(s32*)(self + 0x158) = 1;
            *(s32*)(self + 0x15C) = 0x1C;
            self[0x160] = 0;
            self[0x161] = 0;
        }
    }

    xb_XLIVE_WORK_CLASS_Tick15C(self);
}

s32 XB_FASTCALL xb_iterator_Deref(u8* self);
u8* XB_FASTCALL xb_LiveWork_Get2408(u8* self);
u8 XB_FASTCALL xb_LiveObj_IsReady(u8* self, s32 edx, s32 arg);
typedef struct {
    u32 lo;
    u32 hi;
} XB_XNKID;
s32 XB_STDCALL XOnlineNotificationSetState(s32 user, u32 flags, XB_XNKID kid, u32 n, u8* data);

/* xb_XLIVE_WORK_CLASS_UpdateObj 0x1085D7: the user's online state (+0x144,
 * bit 8 voice) sent when it changes, with whether the session is joinable
 * (+8). 1 when sent or unchanged, 0 without a session or on an error. */
s32 XB_FASTCALL xb_XLIVE_WORK_CLASS_UpdateObj(u8* self) {
    u8 joinable;
    s32 hr;
    XB_ARG a;

    if (xb_iterator_Deref(self + 0xF8) == 0 || *(s32*)(self + 0xC) == 0) {
        return 0;
    }

    a.v = *(s32*)(self + 0x14);

    if (((u8 (XB_FASTCALL*)(u8*, XB_ARG))xb_LiveObj_IsReady)(xb_LiveWork_Get2408(D_00798CAC), a)) {
        *(u32*)(self + 0x144) |= 8;
    } else {
        *(u32*)(self + 0x144) &= ~8;
    }

    joinable = *(s32*)(self + 8) != 0;

    if (*(u32*)(self + 0x144) != *(u32*)(self + 0x148)) {
        hr = XOnlineNotificationSetState(*(s32*)(self + 0x14), *(u32*)(self + 0x144), *(XB_XNKID*)(self + 0xB4), 1, &joinable);

        if (hr != 0) {
            xb_xlive_main_SetMatchArgs(hr, D_002B4F50, 0x4B1, 1);
            return 0;
        }
    }

    *(u32*)(self + 0x148) = *(u32*)(self + 0x144);
    return 1;
}

/* The friend window's pages, each given the pad's menu input. */
typedef s32 (XB_FASTCALL* XB_FRIENDPAGE)(u8* self, XB_ARG in);
s32 xb_LivePadMenuInput(void);
void XBUtil_GetWide(const char* s, u16* out, s32 n);
void xb_xlive_friend_Printf(void* buf, const void* fmt, ...);
void XB_FASTCALL xb_XLIVE_FRIEND_CLASS_Session_SetArgs(u8* self, s32 edx, s32 a, s32 b);
void XB_FASTCALL xb_XLIVE_FRIEND_CLASS_Session_Update(u8* self);
void XB_FASTCALL xb_XLIVE_FRIEND_CLASS_InitPages(void* self);
void XB_FASTCALL xb_XLIVE_FRIEND_CLASS_SetName(u8* self, s32 edx, const void* name);
s32 XB_FASTCALL xb_XLIVE_FRIEND_CLASS_Page_102D50(u8* self);
void xb_LaunchDashboard(void);
s32 XB_FASTCALL CXBOnlineTask_Continue(void* self);
f32 XB_FASTCALL CXBStopWatch_GetElapsedSeconds(void* self);
extern char* D_0079933C;
extern char D_002B4D08[];
extern char D_002193D4[];
extern f32 D_002190A8;
s32 XB_FASTCALL xb_XLIVE_FRIEND_CLASS_Page_10496C(u8* self, s32 edx, s32 in);
s32 XB_FASTCALL xb_XLIVE_FRIEND_CLASS_Page_104DD8(u8* self, s32 edx, s32 in);
s32 XB_FASTCALL xb_XLIVE_FRIEND_CLASS_Page_105251(u8* self, s32 edx, s32 in);
s32 XB_FASTCALL xb_XLIVE_FRIEND_CLASS_Page_FD137(u8* self, s32 edx, s32 in);
s32 XB_FASTCALL xb_XLIVE_FRIEND_CLASS_Page_104085(u8* self, s32 edx, s32 in);
s32 XB_FASTCALL xb_XLIVE_FRIEND_CLASS_Page_FCEE2(u8* self, s32 edx, s32 in);
s32 XB_FASTCALL xb_XLIVE_FRIEND_CLASS_Page_FD064(u8* self, s32 edx, s32 in);
s32 XB_FASTCALL xb_XLIVE_FRIEND_CLASS_Page_1013A5(u8* self, s32 edx, s32 in);
s32 XB_FASTCALL xb_XLIVE_FRIEND_CLASS_Page_10110C(u8* self, s32 edx, s32 in);
s32 XB_FASTCALL xb_XLIVE_FRIEND_CLASS_Page_FD2A9(u8* self, s32 edx, s32 in);
s32 XB_FASTCALL xb_XLIVE_FRIEND_CLASS_Page_FE321(u8* self, s32 edx, s32 in);
s32 XB_FASTCALL xb_XLIVE_FRIEND_CLASS_Page_FD1DA(u8* self, s32 edx, s32 in);
s32 XB_FASTCALL xb_XLIVE_FRIEND_CLASS_Poll_1057D2(u8* self, s32 edx, s32 in);
void XB_FASTCALL xb_XLIVE_FRIEND_CLASS_SetMode(u8* self, s32 edx, s32 mode);
s32 XB_FASTCALL xb_xlive_main_Page_105910(u8* self, s32 edx, s32 in);
s32 XB_FASTCALL xb_XLIVE_FRIEND_CLASS_Page_FE486(u8* self, s32 edx, s32 in);
s32 XB_FASTCALL xb_XLIVE_FRIEND_CLASS_Page_FED22(u8* self, s32 edx, s32 in);
s32 XB_FASTCALL xb_XLIVE_FRIEND_CLASS_Step_FD611(u8* self, s32 edx, s32 in);
s32 XB_FASTCALL xb_XLIVE_FRIEND_CLASS_Page_FD785(u8* self, s32 edx, s32 in);
s32 XB_FASTCALL xb_XLIVE_FRIEND_CLASS_Page_FEF2D(u8* self, s32 edx, s32 in);
s32 XB_FASTCALL xb_XLIVE_FRIEND_CLASS_Page_FD942(u8* self, s32 edx, s32 in);
s32 XB_FASTCALL xb_XLIVE_FRIEND_CLASS_Page_101235(u8* self, s32 edx, s32 in);
s32 XB_FASTCALL xb_XLIVE_FRIEND_CLASS_Page_FDA1F(u8* self, s32 edx, s32 in);
s32 XB_FASTCALL xb_XLIVE_FRIEND_CLASS_Page_FDAE1(u8* self, s32 edx, s32 in);
s32 XB_FASTCALL xb_XLIVE_FRIEND_CLASS_Page_101597(u8* self, s32 edx, s32 in);
s32 XB_FASTCALL xb_XLIVE_FRIEND_CLASS_Page_101785(u8* self, s32 edx, s32 in);
s32 XB_FASTCALL xb_XLIVE_FRIEND_CLASS_MatchPage(u8* self, s32 edx, s32 in);
s32 XB_FASTCALL xb_XLIVE_FRIEND_CLASS_Step_FDDC6(u8* self, s32 edx, s32 in);
s32 XB_FASTCALL xb_XLIVE_FRIEND_CLASS_Page_101954(u8* self, s32 edx, s32 in);
s32 XB_FASTCALL xb_XLIVE_FRIEND_CLASS_Page_100F5A(u8* self, s32 edx, s32 in);

#define XB_PAGE(f) ((XB_FRIENDPAGE)(f))(self, a)

/* xb_xlive_main_Update 0x1060BD: one frame of the friend window (+0x8B0
 * its page): a failed friend request (task +0x118) reported and shown,
 * the page run with the pad, the status text cleared after its time,
 * and the window drawn. 1 when it closes. */
s32 XB_FASTCALL xb_xlive_main_Update(u8* self) {
    u16 msg[0x100];
    s32 r = 0;
    s32 hr;
    XB_ARG a;
    XB_ARG b;

    a.v = xb_LivePadMenuInput();

    if (xb_iterator_Deref(D_00798CAC + 0x118)) {
        hr = CXBOnlineTask_Continue(D_00798CAC + 0x118);

        if (*(s32*)(self + 0x8B0) != 0xE && *(s32*)(self + 0x8B0) != 0x11 && hr < 0) {
            xb_xlive_main_SetMatchArgs(hr, D_002B4D08, 0x110, 0);
            XBUtil_GetWide(D_0079933C, msg, 0x100);
            xb_xlive_friend_Printf(self + 0x60, msg);
            b.v = 0xE;
            {
                XB_ARG c;

                c.v = 0x11;
                ((void (XB_FASTCALL*)(u8*, XB_ARG, XB_ARG))xb_XLIVE_FRIEND_CLASS_Session_SetArgs)(self, b, c);
            }
        }
    }

    switch (*(s32*)(self + 0x8B0)) {
    case 0:
        XB_PAGE(xb_XLIVE_FRIEND_CLASS_Page_10496C);
        break;
    case 1:
        XB_PAGE(xb_XLIVE_FRIEND_CLASS_Page_104DD8);
        break;
    case 2:
        XB_PAGE(xb_XLIVE_FRIEND_CLASS_Page_105251);
        break;
    case 3:
    case 4:
        XB_PAGE(xb_XLIVE_FRIEND_CLASS_Page_FD137);
        break;
    case 5:
        XB_PAGE(xb_XLIVE_FRIEND_CLASS_Page_104085);
        break;
    case 6:
        XB_PAGE(xb_XLIVE_FRIEND_CLASS_Page_FCEE2);
        break;
    case 7:
        XB_PAGE(xb_XLIVE_FRIEND_CLASS_Page_FD064);
        break;
    case 8:
        XB_PAGE(xb_XLIVE_FRIEND_CLASS_Page_1013A5);
        break;
    case 9:
        XB_PAGE(xb_XLIVE_FRIEND_CLASS_Page_10110C);
        break;
    case 10:
        XB_PAGE(xb_XLIVE_FRIEND_CLASS_Page_FD2A9);
        break;
    case 11:
        XB_PAGE(xb_XLIVE_FRIEND_CLASS_Page_FE321);
        break;
    case 12:
        xb_LaunchDashboard();
        break;
    case 13:
        XB_PAGE(xb_XLIVE_FRIEND_CLASS_Page_FD1DA);
        break;
    case 14:
        XB_PAGE(xb_XLIVE_FRIEND_CLASS_Poll_1057D2);
        break;
    case 15:
        XB_PAGE(xb_XLIVE_FRIEND_CLASS_SetMode);
        break;
    case 16:
    case 17:
        xb_XLIVE_FRIEND_CLASS_Session_Update(self);
        xb_XLIVE_FRIEND_CLASS_InitPages(self);
        r = 1;
        break;
    case 18:
        XB_PAGE(xb_xlive_main_Page_105910);
        break;
    case 19:
        XB_PAGE(xb_XLIVE_FRIEND_CLASS_Page_FE486);
        break;
    case 20:
        XB_PAGE(xb_XLIVE_FRIEND_CLASS_Page_FED22);
        break;
    case 21:
        XB_PAGE(xb_XLIVE_FRIEND_CLASS_Step_FD611);
        break;
    case 22:
        XB_PAGE(xb_XLIVE_FRIEND_CLASS_Page_FD785);
        break;
    case 23:
        XB_PAGE(xb_XLIVE_FRIEND_CLASS_Page_FEF2D);
        break;
    case 24:
        XB_PAGE(xb_XLIVE_FRIEND_CLASS_Page_FD942);
        break;
    case 25:
        XB_PAGE(xb_XLIVE_FRIEND_CLASS_Page_101235);
        break;
    case 26:
        XB_PAGE(xb_XLIVE_FRIEND_CLASS_Page_FDA1F);
        break;
    case 27:
        XB_PAGE(xb_XLIVE_FRIEND_CLASS_Page_FDAE1);
        break;
    case 28:
        XB_PAGE(xb_XLIVE_FRIEND_CLASS_Page_101597);
        break;
    case 29:
        XB_PAGE(xb_XLIVE_FRIEND_CLASS_Page_101785);
        break;
    case 30:
        XB_PAGE(xb_XLIVE_FRIEND_CLASS_MatchPage);
        break;
    case 31:
        XB_PAGE(xb_XLIVE_FRIEND_CLASS_Step_FDDC6);
        break;
    case 32:
        XB_PAGE(xb_XLIVE_FRIEND_CLASS_Page_101954);
        break;
    case 33:
        XB_PAGE(xb_XLIVE_FRIEND_CLASS_Page_100F5A);
        break;
    case 34:
        break;
    default:
        _assert(D_0025CCA0, D_002B4D08, 0x152);
        break;
    }

    if (CXBStopWatch_GetElapsedSeconds(self + 0x870) > D_002190A8) {
        b.v = (s32)D_002193D4;
        ((void (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_FRIEND_CLASS_SetName)(self, b);
        CXBStopWatch_Stop(self + 0x870);
    }

    if (sub_0004AFFA() == 0 && xb_XLIVE_WORK_CLASS_Frame(D_00798CAC) == 0) {
        xb_XLIVE_FRIEND_CLASS_Page_102D50(self);
    }

    return r;
}
