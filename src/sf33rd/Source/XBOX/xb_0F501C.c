/* xb_0F501C.c: Xbox-only code from the run of Xbox-only functions at 0xF501C, which no
 * PS2 file covers.
 * Capcom's source is lost. Its C++ methods are written as C,
 * XB_FASTCALL (__fastcall) with this first. Each body was checked
 * against retail by analysis-ps2map/xbgen.py. The xb_ names are
 * made up. */

#include "types.h"
#include <string.h>

typedef struct {
    s32 v[3];
} XB_REQ12;
void sub_000F57D0(void);
void xb_WINSTR_CLASS_Release(void);
extern u8 D_00798EA8[];
extern s32 D_0079941C;
extern s32 D_0079A170;
extern s32 D_00799440;
extern s32 D_0079A350;
extern s32 D_0079A354;
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
void xb_NetSync_SetState(s32 state);
extern u8 D_007BD614[];
void XB_FASTCALL xb_LiveObj_Update(u8* self);
extern u8* D_00798CAC;
extern u8* D_00798B78;
void xb_xlive_disp_DrawMessageDefault(s32 a, s32 b, s32 c);
extern u8 D_0079902C[];
extern s32 D_0079A34C;
extern s32 D_0079A348;
extern u8 D_007A6460[];
extern s32 D_0079A160[];
s32 XB_FASTCALL xb_LiveWork_Check2408(u8* self);
s32 XB_FASTCALL sub_000F5DA0(u8* self);
void** XB_FASTCALL xb_iterator_ctor(void** self, s32 edx, void* p);
void sub_001208DA(void);
void sub_0012097D(void);
s32 XB_STDCALL xb_XHVThunks2(s32 a, s32 b, s32 c);
s32 XB_STDCALL xb_XHVThunks(s32 a, s32 b, s32 c);
void XB_FASTCALL xb_XLIVE_WORK_CLASS_ReleaseQos(void* self);
void XB_FASTCALL xb_XLIVE_WORK_CLASS_QosListen(void* self);
void XB_FASTCALL xb_XLIVE_STATMENU_CLASS_ReleaseSlot(void* self);
void xb_XLIVE_PAGE_CLASS_Clear(u8* page);
extern void (*D_0079AF08)(void);
extern void (*D_0079AF04)(void);
extern s32 D_00797BA8;
void xb_XactPollNotifications(void);
s32 XB_STDCALL XACTEngineDoWork(void);
void xb_xlive_match_DrawStatsIfHost(void);
extern u8 D_007BD5E8[];
extern s32 D_007A15CC;
extern s32** D_0043771C[];
extern s32 D_0079A358;
extern s32 D_0079A35C;
extern s32 D_0079A360;
extern s32 D_0079A364;
void xb_SearchResult_UninitCopyWrap(void* a, void* b, void* c, void* self);
void xb_OnlineObj_Fade(s32 id);
s32 xb_LiveWork_Get14(void);
extern u8* flpad_adr;
extern u8 D_0079A472[];
extern u8 D_00799A60[];
extern s32 D_0079A3C0;
void SsBgmFadeOut(s32 speed);
void XB_FASTCALL xb_XLIVE_WORKBASE_CLASS_ctor(void* self);
void xb_xlive_friend_Release(s32 id);
void XB_FASTCALL sub_000F5B5F(u8* self);
void xb_xlive_match_CheckVoiceReady(void);
extern u8 D_007A7A1C;
extern s32 D_007A7A18;
extern u16 D_007A7A5A;
s32 XB_STDCALL XOnlineFriendsRequest(s32 user, XB_REQ12 friend_);
void xb_xlive_match_CreateSession(void);
extern u8 D_0079A470[];
void xb_PrintSetPos(s16 x, s16 y);
void xb_PrintString(const char* s);
void XB_FASTCALL xb_xlive_match_ReleaseWindow(void* self);
void xb_xlive_match_PeerVoiceC(s32 a);
s32 XB_STDCALL lstrcpynW(void* dst, const void* src, s32 n);
void XB_FASTCALL CXBStopWatch_StartZero(void* self);
void* sub_0001219E(u32 size, void* where);
extern s32 D_0079A178;
s32 XB_STDCALL XNetGetEthernetLinkStatus(void);
extern s32 D_007A14A0;
extern s32 D_007A14A4;
extern s32 D_007A156C;
extern s32 D_007A1574;
extern s32 D_007A1578;
s32 XB_FASTCALL CXBOnlineTask_Close(void* self);
void* xb_GetMatchInfo(void);

void xb_XactFrame(void) {
    if (D_00797BA8 != 0) {
        xb_XactPollNotifications();
        XACTEngineDoWork();
    }
}

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

s32 XB_FASTCALL xb_LiveObj_Call2b(u8* self, s32 edx, s32 a, s32 b) {
    (void)edx;
    return xb_XHVThunks2(*(s32*)(self + 4), a, b);
}

s32 XB_FASTCALL xb_LiveObj_Call2(u8* self, s32 edx, s32 a, s32 b) {
    (void)edx;
    return xb_XHVThunks(*(s32*)(self + 4), a, b);
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

s32 XB_FASTCALL xb_LiveObj_GetResult58(u8* self) {
    xb_LiveObj_Update(self);
    return *(s32*)(self + 0x58);
}

s32 xb_LiveWork_GetState(void) {
    return xb_LiveWork_Check2408(xb_LiveWork_Get2408(D_00798CAC));
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

u8* XB_FASTCALL xb_WINSTR_CLASS_ctor(u8* self) {
    *(s32*)(self + 8) = -1;
    *(s32*)(self + 0x1C) = 0;
    *(s32*)(self + 0x20) = 0;
    *(s32*)(self + 0x24) = 0;
    *(u32*)(self + 0x28) = 0xA0000000;
    *(f32*)(self + 0x2C) = 0.0f;
    return self;
}

void xb_xlive_font_SetPage(s32 page) {
    *(s32*)(D_00798B78 + 0xC) = page;
}

void XB_FASTCALL xb_XLIVE_FRIEND_CLASS_SetName(u8* self, s32 edx, const void* name) {
    (void)edx;
    lstrcpynW(self + 0x8D8, name, 0x40);
    CXBStopWatch_StartZero(self + 0x870);
}

s32 XB_FASTCALL xb_XLIVE_FRIEND_CLASS_RequestFriend(u8* self) {
    return XOnlineFriendsRequest(*(s32*)(D_00798CAC + 0x14), *(XB_REQ12*)(self + 0x960));
}

void XB_FASTCALL xb_XLIVE_FRIEND_CLASS_CloseWindow(u8* self, s32 edx, s32 i) {
    s32* w = (s32*)(self + i * 4 + 0xA8C);

    (void)edx;

    if (*w != -1) {
        xb_xlive_friend_Release(*w);
        *w = -1;
    }
}

void XB_FASTCALL xb_XLIVE_FRIEND_CLASS_FadeWindow(u8* self, s32 edx, s32 i) {
    s32 id = *(s32*)(self + i * 4 + 0xA8C);

    (void)edx;

    if (id != -1) {
        xb_OnlineObj_Fade(id);
    }
}

void XB_FASTCALL xb_XLIVE_WORK_CLASS_SetState3(u8* self) {
    *(s32*)(self + 0x2364) = 3;
    *(s32*)(self + 0x2370) = 0;
    *(s32*)(self + 0x236C) = 0;
    *(s32*)(self + 0x2368) = 0;
}

void XB_FASTCALL xb_XLIVE_WORK_CLASS_SetState4(u8* self) {
    *(s32*)(self + 0x2364) = 4;
    *(s32*)(self + 0x2370) = 0;
    *(s32*)(self + 0x236C) = 0;
    *(s32*)(self + 0x2368) = 0;
}

void XB_FASTCALL xb_XLIVE_WORK_CLASS_ReleaseWindows(u8* self) {
    xb_xlive_friend_Release(*(s32*)(self + 0x138));
    xb_xlive_friend_Release(*(s32*)(self + 0x140));
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

void xb_XLIVE_WORK_CLASS_JoinDraw_State5(void) {
    xb_xlive_disp_DrawMessageDefault(3, 0x3E, 0);
}

void xb_XLIVE_WORK_CLASS_JoinDraw_State7(void) {
    xb_xlive_disp_DrawMessageDefault(3, 0x65, 0);
}

void xb_xlive_match_Set17E(u8 v) {
    u8* m = xb_GetMatchInfo();

    if (m) {
        m[0x17E] = v;
    }
}

void xb_xlive_match_SetState6(void) {
    *(s32*)(D_00798CAC + 0x236C) = 6;
    *(s32*)(D_00798CAC + 0x2370) = 0;
}

s32 XB_FASTCALL xb_XLIVE_WORK_CLASS_ContinueTask108(u8* self) {
    return CXBOnlineTask_Continue(self + 0x108);
}

void xb_XLIVE_WORK_CLASS_HostDraw_State5(void) {
    xb_xlive_disp_DrawMessageDefault(3, 0x4A, 0);
    xb_xlive_disp_DrawMessageDefault(3, 0x63, 0);
}

void XB_FASTCALL xb_XLIVE_WORK_CLASS_CloseMatchTasks(u8* self) {
    CXBOnlineTask_Close(self + 0xFC);
    CXBOnlineTask_Close(self + 0x100);
    CXBOnlineTask_Close(self + 0x108);
}

void* XB_FASTCALL xb_xlive_match_Rec54_ctor(void* self) {
    memset(self, 0, 0x54);
    return self;
}

s32 xb_xlive_match_Check11031E(void) {
    return sub_0011031E() != 0;
}

void XB_STDCALL xb_xlive_match_CursorInc(s8* cursor, s8 max) {
    if (++*cursor > max) {
        *cursor = 0;
    }
}

void XB_STDCALL xb_xlive_match_CursorDec(s8* cursor, s8 max) {
    if (--*cursor < 0) {
        *cursor = max;
    }
}

void xb_xlive_match_ClearFlagC0(void) {
    ((u8*)xb_GetMatchInfo())[0xC0] = 0;
}

void xb_xlive_match_SetFlagC0(void) {
    ((u8*)xb_GetMatchInfo())[0xC0] = 1;
}

void xb_xlive_match_SetFlag2(void) {
    *(s32*)(D_00798CAC + 0x144) |= 2;
}

void xb_xlive_match_SetFlag10(void) {
    *(s32*)(D_00798CAC + 0x144) |= 0x10;
}

void xb_xlive_match_ClearFlag2(void) {
    *(s32*)(D_00798CAC + 0x144) &= ~2;
}

void xb_xlive_match_ClearFlag10(void) {
    *(s32*)(D_00798CAC + 0x144) &= ~0x10;
}

void xb_xlive_match_ResetTimer16C(void) {
    *(u16*)((u8*)xb_GetMatchInfo() + 0x16C) = 600;
}

void xb_xlive_match_ResetTimer16E(void) {
    u8* m = xb_GetMatchInfo();

    m[0x17F] = 1;
    *(u16*)(m + 0x16E) = 1800;
}

s32 xb_xlive_match_IsGuest(void) {
    return ((u8*)xb_GetMatchInfo())[0xC0] == 0;
}

s32 xb_xlive_match_Is110LE1(void) {
    s32 v = *(s32*)((u8*)xb_GetMatchInfo() + 0x110);

    if (v == 0 || v == 1) {
        return 1;
    }

    return 0;
}

u8** XB_FASTCALL xb_SearchResultIt_AddAssign(u8** self, s32 edx, s32 n) {
    (void)edx;
    *self += n * 0xBC;
    return self;
}

s32 XB_FASTCALL xb_SearchResultIt_Diff(u8** self, s32 edx, u8** other) {
    (void)edx;
    return (*self - *other) / 0xBC;
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

s64 XB_FASTCALL xb_xlive_match_GetQwB4(u8* self) {
    return *(s64*)(self + 0xB4);
}

u8* XB_FASTCALL xb_xlive_match_GetAddr54(u8* self) {
    return self + 0x54;
}

s64 XB_FASTCALL xb_xlive_match_GetQw8C(u8* self) {
    return *(s64*)(self + 0x8C);
}

s64 XB_FASTCALL xb_xlive_match_GetQw94(u8* self) {
    return *(s64*)(self + 0x94);
}

void xb_xlive_match_CreateSessionAndWait(void) {
    xb_xlive_match_CreateSession();
    *(s32*)(D_00798CAC + 0x236C) = 2;
    *(s32*)(D_00798CAC + 0x2370) = 0;
}

u8 xb_XLIVE_WORK_CLASS_IsHost(void) {
    if (xb_xlive_match_IsGuest() && *(s32*)(D_00798CAC + 0x236C) == 3) {
        return ((u8*)xb_GetMatchInfo())[0x17E];
    }

    return 0;
}

s32 xb_xlive_match_Voice_F5DA0(void) {
    return sub_000F5DA0(xb_LiveWork_Get2408(D_00798CAC));
}

void xb_xlive_match_Voice_F5B5F(void) {
    ((u8*)xb_GetMatchInfo())[0x17D] = 0;
    sub_000F5B5F(xb_LiveWork_Get2408(D_00798CAC));
}

void xb_SearchResult_Construct(void* where, void* src) {
    void* p = sub_0001219E(0xBC, where);

    if (p) {
        memcpy(p, src, 0xBC);
    }
}

void xb_xlive_match_TickTimer16C(void) {
    s16* t = (s16*)((u8*)xb_GetMatchInfo() + 0x16C);

    if (--*t < 0) {
        xb_xlive_match_ResetTimer16C();
        xb_xlive_match_CheckVoiceReady();
    }
}

void xb_xlive_match_DrawWaitMessage(void) {
    xb_xlive_match_DrawStatsIfHost();
    xb_xlive_disp_DrawMessageDefault(3, 0x62, 0);
}

void XB_FASTCALL xb_SearchResult_ConstructAt(void* self, s32 edx, void* p, void* src) {
    (void)self;
    (void)edx;
    xb_SearchResult_Construct(p, src);
}

void XB_FASTCALL xb_XLIVE_WORK_CLASS_SetState8(u8* self) {
    xb_xlive_match_ReleaseWindow(self);
    *(s32*)(self + 0x2370) = 0;
    *(s32*)(self + 0x236C) = 8;
    xb_xlive_match_PeerVoiceC(2);
}

void XB_FASTCALL xb_SearchResultVec_Ucopy(void* self, s32 edx, void* a, void* b, void* c) {
    (void)edx;
    xb_SearchResult_UninitCopyWrap(a, b, c, self);
}

void xb_xlive_match_ClearRecordWork(void) {
    memset(D_0079902C, 0, 0x30);
}

void* xb_GetMatchInfo(void) {
    return D_00798EA8;
}

s32 xb_GetLiveLanguage(void) {
    return D_0079941C;
}

void xb_SetLiveCallback(s32 i, s32 cb) {
    D_0079A160[i] = cb;
}

u8* xb_GetOnlinePlayer(s32 i) {
    if (i >= 0 && i < 2) {
        return D_00799A60 + i * 0x300;
    }

    return 0;
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

void xb_PollEthernetLink(void) {
    if (++D_0079A17C > 30) {
        D_0079A17C = 0;
        D_0079A178 = XNetGetEthernetLinkStatus() & 1;
    }
}

void xb_ClearLivePadState(void) {
    D_0079A358 = 0;
    D_0079A35C = 0;
    D_0079A360 = 0;
    D_0079A364 = 0;
}

s32 xb_LivePadActive(void) {
    return *(s32*)(xb_LiveWork_Get14() * 0x88 + flpad_adr + 0x10) != 0;
}

void xb_ClearLivePadLatch(void) {
    D_0079A34C = 0;
    D_0079A348 = 0;
}

s32 xb_LivePadButtons(s32 mask) {
    return *(s32*)(xb_LiveWork_Get14() * 0x88 + flpad_adr + 8) & mask;
}

s32 xb_GetOnlineModeArg(void) {
    return D_0079A350;
}

void xb_SetOnlineModeArgs(s32 a, s32 b) {
    D_0079A350 = a;
    D_0079A354 = b;
}

s32 xb_GetOnlineModeArg2(void) {
    return D_0079A354;
}

void xb_LiveWork_InitTaskThunk(void) {
    xb_ClearLivePadLatch();
}

s32 XB_FASTCALL xb_XLIVE_WORK_CLASS_RestartQos(void* self) {
    xb_XLIVE_WORK_CLASS_ReleaseQos(self);
    xb_XLIVE_WORK_CLASS_QosListen(self);
    return 0;
}

s32 XB_FASTCALL xb_xlive_ThunkFC23E(u8* self) {
    return xb_iterator_Deref(self);
}

void xb_BgmFadeOutSpeed(s16 frames) {
    D_0079A3C0 = 0;
    SsBgmFadeOut(0x8000 / frames);
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

u8 xb_LiveWork_Call113F24(void) {
    return xb_XLIVE_STARTMENU_CLASS_Get6D(D_00798CAC + 0x24C0);
}

s32 XB_FASTCALL xb_XLIVE_STATMENU_CLASS_Release(u8* self) {
    xb_XLIVE_STATMENU_CLASS_ReleaseSlot(self);
    xb_XLIVE_PAGE_CLASS_Clear(self);
    return 0;
}

void* XB_FASTCALL xb_vector_CopyCtor(void** self, s32 edx, void* p) {
    xb_iterator_ctor(self, edx, p);
    return self;
}

s32 xb_OnlineObj_IsId(s32 id) {
    return *(s16*)(D_0079A472 + (id >> 16) * 0x5C) == (s16)id;
}

void xb_OnlineObj_SetFlag(s32 id, u8 v) {
    if (xb_OnlineObj_IsId(id)) {
        D_0079A470[(id >> 16) * 0x5C] = v;
    }
}

s32 xb_OnlineStartup(s32 params) {
    return XOnlineStartup(params);
}

void xb_SetSaveCallbacks(void (*save)(void), void (*load)(void)) {
    D_0079AF08 = save;
    D_0079AF04 = load;
}

u16 xb_MsgQueueGetCount(void) {
    return D_0079B714;
}

void xb_NetSync_SetPacketTarget(u8 player, s32 target) {
    D_007A7A1C = player;
    D_007A7A18 = target;
    D_007A7A5A = player;
}

s32 xb_NetSync_SetState7(void) {
    xb_NetSync_SetState(7);
    return 1;
}

s32 xb_NetSync_SetState8(void) {
    xb_NetSync_SetState(8);
    return 1;
}

void* XB_FASTCALL xb_XLIVE_WORK_CLASS_ctor(u8* self) {
    xb_XLIVE_WORKBASE_CLASS_ctor(self);
    *(void**)self = D_002B8708;
    *(s32*)(self + 0x232C) = 5;
    return self;
}

void XB_FASTCALL xb_XLIVE_WORK_CLASS_dtor(void** self) {
    *self = D_002B8708;
    xb_XLIVE_WORKBASE_CLASS_dtor(self);
}

void xb_rebattle_Select(s32 sel) {
    if (sel == 1) {
        xb_NetSync_SetState7();
        return;
    }

    if (sel == 0) {
        xb_NetSync_SetState8();
    }
}

void xb_ClearRebattleWork(void) {
    memset(D_007A6460, 0, 0x18);
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

s32 xb_GetPlayerSetting(s32 i) {
    return D_007BD5E8[xb_GetOnlineModeArg2() * 12 + i];
}

s32 xb_GetSettingByte(s32 i) {
    return D_007BD614[i];
}

void xb_RegisterSaveCallbacks(void) {
    xb_SetSaveCallbacks(sub_001208DA, sub_0012097D);
}

void xb_SaveStateReset(s32 a, s32 b) {
    D_007A14A0 = 0;
    D_007A14A4 = 0;
    D_007A156C = 0;
    D_007A1574 = a;
    D_007A1578 = b;
}

s32 xb_GetLocalizedText(s32 i) {
    return (*D_0043771C[D_007A15CC])[i];
}

s32 xb_PrintAt(s32 x, s32 y, const char* s) {
    xb_PrintSetPos(x, y);

    if (*s) {
        xb_PrintString(s);
    }

    return 0;
}

void xb_SeSelectedThunk(void) {
    sub_0009C793();
}

void xb_SeCursorMoveThunk(void) {
    SE_cursor_move();
}
