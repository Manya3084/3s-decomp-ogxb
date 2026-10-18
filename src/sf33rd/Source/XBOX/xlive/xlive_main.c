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
void XB_FASTCALL xb_XLIVE_WORK_CLASS_UpdateTimer(void* self);
void xb_OnlineMenuDraw(void);
s32 xb_LiveWork_UpdateMode3DC(void);
void XB_FASTCALL xb_WINSTR_CLASS_Update(void* self);
void XB_FASTCALL xb_CONNECT_USER_CLASS_UpdateIfActive(u8* self);
extern u8 D_00798CB0[];
s32 XB_FASTCALL CXBOnlineTask_Continue(void* self);
s32 XB_FASTCALL sub_000FBBB5(void* self);
void xb_xlive_main_SetMatchArgs(s32 hr, const char* file, s32 line, s32 a);
void sub_00107C43(s32 a, const char* file, s32 line, s32 b);

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
