/* xb_0F501C.c: Xbox-only code from the run of Xbox-only functions at 0xF501C, which no
 * PS2 file covers.
 * Capcom's source is lost. Its C++ methods are written as C,
 * XB_FASTCALL (__fastcall) with this first. Each body was checked
 * against retail by analysis-ps2map/xbgen.py. The xb_ names are
 * made up. */

#include "types.h"

void sub_000F57D0(void);
void xb_WINSTR_CLASS_Release(void);
extern u8 D_00798EA8[];
extern s32 D_0079941C;
extern s32 D_0079A170;
extern s32 D_00799440;
extern s32 D_0079A350;
extern s32 D_0079A354;
void xb_ClearLivePadLatch(void);
extern u16 D_0079B714;
extern s32 D_007A1390;
extern s32 D_007A1394;
void sub_0009C793(void);
void SE_cursor_move(void);
s32 XB_FASTCALL xb_iterator_Deref(u8* self);
extern u8 D_007C5878;
s32 XB_STDCALL XOnlineStartup(s32 params);
s32 XB_FASTCALL CXBOnlineTask_Continue(void* self);
void XB_FASTCALL sub_00115C20(void* self);
void XB_FASTCALL sub_00115C59(void* self);
void XB_FASTCALL sub_00115CB6(void* self);
void XB_FASTCALL sub_00115D13(void* self);
extern s32 D_0079A17C;
extern u8 D_002B8708[];
void XB_FASTCALL xb_XLIVE_WORKBASE_CLASS_dtor(void* self);
void XB_FASTCALL xb_WINSTR_CLASS_Update(void* self);
s32 sub_0011031E(void);

s32 XB_FASTCALL xb_LiveObj_GetHandle50(u8* self) {
    return *(s32*)(self + 0x50);
}

u8* XB_FASTCALL xb_LiveObj_Set2(u8* self, s32 edx, u8 v) {
    (void)edx;
    self[2] = v;
    return self;
}

s32 xb_GetLiveObjSize(void) {
    return 0x68;
}

s32 XB_FASTCALL xb_LiveObj_IsValid(u8* self) {
    return *(s32*)(self + 4) != 0;
}

u8* XB_FASTCALL xb_LiveObj_Get8(u8* self) {
    return self + 0x8;
}

u8* XB_FASTCALL xb_LiveWork_Get2408(u8* self) {
    return self + 0x2408;
}

void xb_LiveObj_Thunk(void) {
    sub_000F57D0();
}

void XB_FASTCALL xb_CONNECT_USER_CLASS_UpdateIfActive(u8* self) {
    if (self[0x50]) {
        xb_WINSTR_CLASS_Update(self);
    }
}

void XB_FASTCALL xb_CONNECT_USER_CLASS_SetActive(u8* self, s32 edx, u8 on) {
    (void)edx;
    self[0x50] = on;
}

void xb_CONNECT_USER_CLASS_Release(void) {
    xb_WINSTR_CLASS_Release();
}

s32 XB_FASTCALL xb_xlive_match_ReturnZero(void* self, s32 edx, s32 a0) {
    (void)self;
    (void)edx;
    (void)a0;
    return 0;
}

void XB_FASTCALL xb_xlive_match_Nop(void* self, s32 edx, s32 a0) {
    (void)self;
    (void)edx;
    (void)a0;
}

s32 XB_FASTCALL xb_XLIVE_WORK_CLASS_ContinueTask108(u8* self) {
    return CXBOnlineTask_Continue(self + 0x108);
}

s32 xb_xlive_match_Check11031E(void) {
    return sub_0011031E() != 0;
}

void XB_FASTCALL xb_XLIVE_WORK_CLASS_Stat2C0_A(u8* self) {
    sub_00115C20(self + 0x2C0);
}

void XB_FASTCALL xb_XLIVE_WORK_CLASS_Stat2C0_B(u8* self) {
    sub_00115C59(self + 0x2C0);
}

void XB_FASTCALL xb_XLIVE_WORK_CLASS_Stat2C0_C(u8* self) {
    sub_00115CB6(self + 0x2C0);
}

void XB_FASTCALL xb_XLIVE_WORK_CLASS_Stat2C0_D(u8* self) {
    sub_00115D13(self + 0x2C0);
}

u8* XB_FASTCALL xb_xlive_match_GetAddr30(u8* self) {
    return self + 0x30;
}

u8* XB_FASTCALL xb_xlive_match_GetAddr0C(u8* self) {
    return self + 0xC;
}

u8* XB_FASTCALL xb_xlive_match_GetAddr54(u8* self) {
    return self + 0x54;
}

void* xb_GetMatchInfo(void) {
    return D_00798EA8;
}

s32 xb_GetLiveLanguage(void) {
    return D_0079941C;
}

s32 xb_GetOnlineFlag(void) {
    return D_0079A170;
}

s32 xb_GetOnlineByte799440(void) {
    return D_00799440;
}

void xb_ResetLinkPollTimer(void) {
    D_0079A17C = 999;
}

s32 xb_GetOnlineModeArg(void) {
    return D_0079A350;
}

s32 xb_GetOnlineModeArg2(void) {
    return D_0079A354;
}

void xb_LiveWork_InitTaskThunk(void) {
    xb_ClearLivePadLatch();
}

s32 XB_FASTCALL xb_xlive_ThunkFC23E(u8* self) {
    return xb_iterator_Deref(self);
}

void XB_FASTCALL xb_XLIVE_STARTMENU_CLASS_Set6C(u8* self, s32 edx, u8 v) {
    (void)edx;
    self[0x6C] = v;
}

s32 XB_FASTCALL xb_XLIVE_STARTMENU_CLASS_Get74(u8* self) {
    return *(s32*)(self + 0x74);
}

u8 XB_FASTCALL xb_XLIVE_STARTMENU_CLASS_Get6D(u8* self) {
    return *(u8*)(self + 0x6D);
}

void XB_FASTCALL xb_XLIVE_STARTMENU_CLASS_Set6D(u8* self, s32 edx, u8 v) {
    (void)edx;
    self[0x6D] = v;
}

s32 XB_FASTCALL xb_XLIVE_STARTMENU_CLASS_Get70(u8* self) {
    return *(s32*)(self + 0x70);
}

void XB_FASTCALL xb_XLIVE_STARTMENU_CLASS_Set70(u8* self, s32 edx, s32 v) {
    (void)edx;
    *(s32*)(self + 0x70) = v;
}

u8 XB_FASTCALL xb_XLIVE_WORK_CLASS_Get235C(u8* self) {
    return *(u8*)(self + 0x235C);
}

s32 xb_OnlineStartup(s32 params) {
    return XOnlineStartup(params);
}

u16 xb_MsgQueueGetCount(void) {
    return D_0079B714;
}

void XB_FASTCALL xb_XLIVE_WORK_CLASS_dtor(void** self) {
    *self = D_002B8708;
    xb_XLIVE_WORKBASE_CLASS_dtor(self);
}

void xb_NetSync_SetFlag2(s32 v) {
    D_007A1390 = v;
}

s32 xb_NetSync_GetFlag2(void) {
    return D_007A1390;
}

void xb_NetSync_SetDone(s32 v) {
    D_007A1394 = v;
}

s32 xb_NetSync_IsDone(void) {
    return D_007A1394;
}

s32 xb_Get7C5878(void) {
    return D_007C5878;
}

void xb_SeSelectedThunk(void) {
    sub_0009C793();
}

void xb_SeCursorMoveThunk(void) {
    SE_cursor_move();
}
