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
void XB_FASTCALL xb_WINSTR_CLASS_Reset(void* self);
void XB_FASTCALL xb_XLIVE_WORK_CLASS_Setup(void* self);
s8 xb_OnlineObj_Exists(s32 id);

s32 XB_FASTCALL xb_WINSTR_CLASS_Exists(u8* self) {
    return xb_OnlineObj_Exists(*(s32*)(self + 8));
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

void xb_LiveTimer_Start(void) {
    CXBStopWatch_StartZero(D_00798D50);
}

f32 xb_LiveTimer_Elapsed(void) {
    return CXBStopWatch_GetElapsedSeconds(D_00798D50);
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

void xb_LiveTimer2_Reset(void) {
    xb_WINSTR_CLASS_Reset(D_00798D00);
}

void* XB_FASTCALL xb_ReturnThis(void* self, s32 edx, s32 a0) {
    (void)edx;
    (void)a0;
    return self;
}
