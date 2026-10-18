/* xb_0F501C.c: Xbox-only code from the run of Xbox-only functions at 0xF5788, which no PS2 file covers.
 * Capcom's source is lost. The C++ methods are written as C,
 * XB_FASTCALL (__fastcall) with this first (analysis-ps2map/xbgen.py wrote
 * these from their shapes). The names are made up (xb_). */

#include "types.h"

extern s32 D_0079941C;
extern s32 D_00799440;
extern s32 D_0079A170;
extern s32 D_0079A350;
extern s32 D_0079A354;
extern s32 D_007A1390;
extern s32 D_007A1394;
extern u16 D_0079B714;
extern u8 D_00798EA8[];
void SE_cursor_move(void);
void sub_0009C793(void);
void sub_000F57D0(void);
void xb_ClearLivePadLatch(void);
void xb_WINSTR_CLASS_Release(void);

s32 XB_FASTCALL xb_LiveObj_GetHandle50(u8* self) {
    return *(s32*)(self + 0x50);
}

s32 xb_GetLiveObjSize(void) {
    return 0x68;
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

s32 xb_GetOnlineModeArg(void) {
    return D_0079A350;
}

s32 xb_GetOnlineModeArg2(void) {
    return D_0079A354;
}

void xb_LiveWork_InitTaskThunk(void) {
    xb_ClearLivePadLatch();
}

s32 XB_FASTCALL xb_XLIVE_STARTMENU_CLASS_Get74(u8* self) {
    return *(s32*)(self + 0x74);
}

u8 XB_FASTCALL xb_XLIVE_STARTMENU_CLASS_Get6D(u8* self) {
    return *(u8*)(self + 0x6D);
}

s32 XB_FASTCALL xb_XLIVE_STARTMENU_CLASS_Get70(u8* self) {
    return *(s32*)(self + 0x70);
}

u8 XB_FASTCALL xb_XLIVE_WORK_CLASS_Get235C(u8* self) {
    return *(u8*)(self + 0x235C);
}

u16 xb_MsgQueueGetCount(void) {
    return D_0079B714;
}

s32 xb_NetSync_GetFlag2(void) {
    return D_007A1390;
}

s32 xb_NetSync_IsDone(void) {
    return D_007A1394;
}

void xb_SeSelectedThunk(void) {
    sub_0009C793();
}

void xb_SeCursorMoveThunk(void) {
    SE_cursor_move();
}
