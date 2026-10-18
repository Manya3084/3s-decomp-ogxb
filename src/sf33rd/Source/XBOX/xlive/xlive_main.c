/* xlive_main.c: Xbox-only code from Capcom's xlive_main.cpp. Its _assert path names it, and the
 * code that pushes the path places it at 0x10668F to 0x109C88.
 * Capcom's source is lost. Its C++ methods are written as C,
 * XB_FASTCALL (__fastcall) with this first. Each body was checked
 * against retail by analysis-ps2map/xbgen.py. The xb_ names are
 * made up. */

#include "types.h"

extern u8* D_00798CAC;
extern u8 D_002B8328[];
extern u8 D_00798D50[];
void XB_FASTCALL CXBStopWatch_StartZero(void* self);
f32 XB_FASTCALL CXBStopWatch_GetElapsedSeconds(void* self);
extern u8 D_00798D00[];
void XB_FASTCALL xb_XLIVE_WORK_CLASS_Setup(void* self);
s8 xb_OnlineObj_Exists(s32 id);
void xb_xlive_friend_Release(s32 id);
void XB_FASTCALL CXBStopWatch_Stop(void* self);
void XB_FASTCALL CXBStopWatch_Reset(void* self);
s32 XB_FASTCALL CXBNetLink_IsActive(void* self);
void XB_FASTCALL xb_XLIVE_WORK_CLASS_ResetSessions(void* self);
extern s32 D_00798C9C;
extern s32 D_00798CA0;
void XB_STDCALL xb_ReleaseResource(s32 res);
void xb_xlive_disp_DrawCell(s32 a, s32 b, s32 c, s32 d, f32 e, f32 f, s32 g);
extern s32 D_003F8318;
void _assert(const char* expr, const char* file, u32 line);
extern char D_002B4FC0[];
extern char D_002B4F50[];
void XB_FASTCALL xb_WINSTR_CLASS_SetString(u8* self, s32 edx, s32 str);

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

void xb_LiveTimer2_Reset(void) {
    xb_WINSTR_CLASS_Reset(D_00798D00);
}

void XB_FASTCALL xb_WINSTR_CLASS_SetPos(u8* self, s32 edx, f32 x, f32 y, f32 w, f32 h, s32 str) {
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
