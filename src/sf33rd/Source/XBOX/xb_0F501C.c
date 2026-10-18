/* xb_0F501C.c: Xbox-only code from the run of Xbox-only functions at 0xF501C, which no
 * PS2 file covers.
 * Capcom's source is lost. Its C++ methods are written as C,
 * XB_FASTCALL (__fastcall) with this first. Each body was checked
 * against retail by analysis-ps2map/xbgen.py. The xb_ names are
 * made up. */

#include "types.h"
#include <string.h>

typedef struct {
    s32 state;
    s16 id;
    u8 pad6[2];
    u8 grp;
    u8 prio;
    u8 padA[0xA];
    s32 cue;
    s32 bank;
    s32 x;
    u8 pad20[0x18];
} XB_SESLOT;
typedef struct {
    s32 v[3];
} XB_REQ12;
typedef struct {
    u16 lo;
    u16 hi;
} XB_SEQ;
typedef struct {
    u8 used;
    u8 active;
    u8 pad2[2];
    s32 id;
    s32 pad8;
} XB_MATCHWIN;
typedef struct {
    u8 pad0[0x184];
    XB_MATCHWIN win[4];
} XB_MATCHINFO;
extern XB_SESLOT D_00797128[];
s32 XB_STDCALL xb_XactCall_1B8089(s32 a);
s32 XB_STDCALL xb_XactCall_1B8048(s32 a, s32 b, s32 c, s32 d);
extern s32 D_00797BA8;
void xb_XactPollNotifications(void);
s32 XB_STDCALL XACTEngineDoWork(void);
s32 XB_STDCALL xb_XHVThunks2(s32 a, s32 b, s32 c);
s32 XB_STDCALL xb_XHVThunks(s32 a, s32 b, s32 c);
void sub_000F57D0(void);
void XB_FASTCALL xb_LiveObj_Update(u8* self);
void XB_FASTCALL CXBStopWatch_StartZero(void* self);
extern void (XB_STDCALL *D_00218DC8)(void* cs);
extern s32 D_00797F18;
s32 XB_STDCALL CreateThread(void* attr, u32 stack, void* start, void* param, u32 flags, u32* id);
s32 XB_STDCALL SetThreadPriority(s32 h, s32 prio);
s32 XB_STDCALL SetThreadPriorityBoost(s32 h, s32 off);
u32 XB_STDCALL ResumeThread(s32 h);
void sub_000F66C0(void);
extern u8 D_00797EFC[];
extern u8* D_00798CAC;
void XB_FASTCALL xb_WINSTR_CLASS_Update(void* self);
void XB_FASTCALL xb_WINSTR_CLASS_Release(s32* self);
void xb_xlive_disp_DrawMessage(s32 a, s32 b, s32 c, f32 scale, f32 alpha, s32 flags);
void xb_xlive_disp_DrawTextBox(f32 x, f32 y, f32 scale, s32 text, f32 alpha, s32 flags);
extern u8* D_00798B78;
s32 XB_STDCALL lstrcpynW(void* dst, const void* src, s32 n);
s32 XB_STDCALL XOnlineFriendsRequest(s32 user, XB_REQ12 friend_);
s32 XB_STDCALL XOnlineFriendsRequestEx(s32 user, XB_REQ12 friend_, s32 a, s32 b, s32 c);
s32 xb_OnlineObj_Move(s32 id);
s32 xb_xlive_disp_DrawRectF(f32 a, f32 b, f32 c, f32 d, f32 e);
s32 xb_xlive_disp_SetObj0C(s32 id, s32 v);
void xb_xlive_friend_Release(s32 id);
void xb_OnlineObj_Fade(s32 id);
s32 sub_0011055B(s32 key);
extern s32 D_003F8328[];
extern u8 D_0079902C[];
extern u8 D_00798EA8[];
extern u8 D_002B53F0[];
s32 xb_xlive_disp_DrawRectFloat(f32 x, f32 y, f32 w, f32 h);
extern s32 D_0079941C;
extern s32 D_0079A160[];
extern u8 D_00799A60[];
extern s32 D_0079A170;
extern s32 D_00799440;
extern s32 D_0079A17C;
extern s32 D_0079A178;
s32 XB_STDCALL XNetGetEthernetLinkStatus(void);
extern s32 D_0079A358;
extern s32 D_0079A35C;
extern s32 D_0079A360;
extern s32 D_0079A364;
s32 xb_LiveWork_Get14(void);
extern u8* flpad_adr;
extern s32 D_0079A34C;
extern s32 D_0079A348;
extern s32 D_0079A350;
extern s32 D_0079A354;
s32 XB_STDCALL XNetQosRelease(void* qos);
void XB_FASTCALL sub_000F8F07(void* self);
void XB_FASTCALL xb_XLIVE_WORK_CLASS_QosListen(void* self);
s32 XB_FASTCALL xb_iterator_Deref(u8* self);
extern s32 D_0079A3C0;
void SsBgmFadeOut(s32 speed);
void xb_XLIVE_PAGE_CLASS_Clear(u8* page);
void XB_FASTCALL xb_XLIVE_STATMENU_CLASS_Init(u8* self);
s32 XB_FASTCALL xb_XLIVE_STATMENU_CLASS_StepTimer(u8* self);
extern u8 D_0079A472[];
extern u8 D_0079A418[];
extern u8 D_0079A470[];
s32 XB_STDCALL XOnlineStartup(s32 params);
extern void (*D_0079AF08)(void);
extern void (*D_0079AF04)(void);
extern s32 D_007A7BC4;
extern s32 D_007A7BC8;
extern u8 D_007A7BCC;
extern u8 D_007A7BCD;
extern u8 D_007A7BCE;
extern u8 D_007A7BCF;
extern u16 D_007A7BD0;
extern u16 D_007A7BD2;
extern u16 D_0079B714;
extern u8 D_007A7A1C;
extern s32 D_007A7A18;
extern u16 D_007A7A5A;
extern s8 D_007A7A0A;
extern u8 D_007A7600[];
s32 xb_NetSync_Receive(s32 a, u8* buf, s32 size);
extern s16 D_007A7A38;
s32 XB_STDCALL send(s32 s, const void* buf, s32 len, s32 flags);
s32 XB_STDCALL WSAGetLastError(void);
extern u8 D_002B8708[];
void XB_FASTCALL xb_XLIVE_WORKBASE_CLASS_ctor(void* self);
void XB_FASTCALL xb_XLIVE_WORKBASE_CLASS_dtor(void* self);
extern u8 D_007A6460[];
extern s32 D_007A1390;
extern s32 D_007A1394;
extern u8 D_007C5878;
extern u8 D_007BD5E8[];
extern u8 D_007BD614[];
void sub_001206D8(void);
void sub_0004AFFA(void);
void sub_001204D8(void);
void sub_001208DA(void);
void sub_0012097D(void);
extern s32 D_007A14A0;
extern s32 D_007A14A4;
extern s32 D_007A156C;
extern s32 D_007A1574;
extern s32 D_007A1578;
extern s32 D_007A15CC;
extern s32** D_0043771C[];
void xb_PrintSetPos(s16 x, s16 y);
void xb_PrintString(const char* s);
void SE_selected(void);
void SE_cursor_move(void);
s32 load_it_use_any_key2(s32 ix, void* out, s32* size, s32 a, s32 b);
extern s32 D_0079B834;
s32 flLogOut(const char* fmt, ...);
extern char D_002B877C[];
extern s32 D_0079B828;
extern s32 D_0079B82C;
extern s32 D_0079B830;
extern s32 D_00795C10;
s32 XB_STDCALL DirectSoundCreate(void* guid, s32* ds, void* outer);
s32 XB_STDCALL DirectSoundUseLightHRTF(void);
s32 XB_STDCALL xb_DownloadEffectsImage(s32 dsound, s32 a, s32 b, s32* loc, void* out);
extern u8 D_007A1808;
s32 xb_NetSync_BuildRequest(s32 sock, u8 id);
extern s32 D_007A7BC0;
extern u8 D_007A7A0C;
s32 xb_xlive_font_NextLine(void);
void xb_xlive_font_DrawQueued(void);
s32 xb_GetOnlineFlagThunk(void);
void XB_FASTCALL xb_XLIVE_STARTMENU_CLASS_StatUpdate(u8* self);
s32 xb_LiveWork_Get2330(void);
void XB_FASTCALL xb_XLIVE_STARTMENU_CLASS_Update(u8* self);
f32 xb_LiveTimer_Elapsed(void);
void xb_LiveTimer_Stop(void);
extern void (*D_00436F0C[])(void* w);
extern void (*D_00437F84[])(void* w);
void sub_0016AA60(void);
void sub_0016AA70(void);
void xb_PersistDisplay(void);
u32 XB_STDCALL XLaunchNewImageA(const char* path, void* data);
extern u8 D_00798B80[];
u8* xb_FindOnlineObj(s32 id);
void xb_OnlineObj_SetFlag(s32 id, u8 v);
u8 xb_OnlineObj_IsDone(s32 id);
s32 xb_NetSync_Send(s32 sock, const void* buf, s16 len);
void xb_SeSelectedThunk(void);

void xb_StopAllSeSlots(void) {
    u32 i;

    for (i = 0; i < 48; i++) {
        if (D_00797128[i].cue && D_00797128[i].state != 1) {
            xb_XactCall_1B8089(D_00797128[i].x);

            if (xb_XactCall_1B8048(D_00797128[i].bank, -1, 2, D_00797128[i].cue) == 0) {
                D_00797128[i].state = 1;
            }
        }
    }
}

void xb_StopSeById(s16 id) {
    u32 i;

    for (i = 0; i < 48; i++) {
        if (D_00797128[i].cue && D_00797128[i].state != 1 && D_00797128[i].id == id) {
            xb_XactCall_1B8089(D_00797128[i].x);

            if (xb_XactCall_1B8048(D_00797128[i].bank, -1, 2, D_00797128[i].cue) == 0) {
                D_00797128[i].state = 1;
            }
        }
    }
}

s32 xb_StopSeByGroup(s32 a, s32 b, u8 grp, u8 prio) {
    u32 i;

    (void)a;
    (void)b;

    for (i = 0; i < 48; i++) {
        if (D_00797128[i].cue && D_00797128[i].state != 1 && D_00797128[i].grp == grp && D_00797128[i].prio <= prio) {
            xb_XactCall_1B8089(D_00797128[i].x);

            if (xb_XactCall_1B8048(D_00797128[i].bank, -1, 2, D_00797128[i].cue)) {
                return 0;
            }

            D_00797128[i].state = 1;
        }
    }

    return 1;
}

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

void XB_FASTCALL xb_LiveObj_StartThread(u8* self) {
    D_00797F18 = 0;
    D_00797F18 = CreateThread(0, 0, sub_000F66C0, 0, 4, 0);
    SetThreadPriority(D_00797F18, -2);
    SetThreadPriorityBoost(D_00797F18, 0);
    ResumeThread(D_00797F18);
    CXBStopWatch_StartZero(self + 0x70);
    D_00218DC8(D_00797EFC);
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

void XB_FASTCALL xb_CONNECT_USER_CLASS_Release(s32* self) {
    xb_WINSTR_CLASS_Release(self);
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

s32 xb_xlive_SetObjFlag58(s32 id, s32 on) {
    u8* o = xb_FindOnlineObj(id);

    if (o == 0) {
        return -1;
    }

    o[0x58] = on >= 1;

    if (o[0x58]) {
        *(s32*)(o + 0x34) = *(s32*)(o + 0x2C);
    }

    return 1;
}

s32 xb_xlive_ResetObj(s32 id, s32 keep) {
    u8* o = xb_FindOnlineObj(id);

    if (o == 0) {
        return -1;
    }

    if (keep == 0) {
        *(f32*)(o + 0x1C) = *(f32*)(o + 0xC);
        o[1] = 0;
        *(f32*)(o + 0x20) = *(f32*)(o + 0x10);
        *(s32*)(o + 0x30) = *(s32*)(o + 0x2C);
        *(s32*)(o + 0x34) = *(s32*)(o + 0x2C);
        *(f32*)(o + 0x24) = *(f32*)(o + 0x14);
        *(f32*)(o + 0x28) = *(f32*)(o + 0x18);
    }

    return 1;
}

void xb_xlive_disp_DrawMessageDefault(s32 a, s32 b, s32 c) {
    xb_xlive_disp_DrawMessage(a, b, c, 0.6f, 1.0f, 0);
}

void xb_xlive_disp_DrawTextAt(f32 x, f32 y, s32 text) {
    xb_xlive_disp_DrawTextBox(x, y, 0.6f, text, 1.0f, 0);
}

void xb_xlive_font_Clear(void) {
    u8* f = D_00798B78;
    s32 i;

    for (i = 0; i < 0xF40; i++) {
        ((s32*)(f + 0x230))[i] = 0xFF00FF;
    }

    *(s32*)(f + 0x3F30) = 0;
    *(s32*)(f + 0x44) = 0;
    *(s32*)(f + 0x48) = 0;
}

void xb_xlive_font_SetPage(s32 page) {
    *(s32*)(D_00798B78 + 0xC) = page;
}

void xb_xlive_font_Flush(void) {
    *(s32*)(D_00798B78 + 0x40) = -1;

    if (xb_xlive_font_NextLine()) {
        xb_xlive_font_Clear();
        xb_xlive_font_NextLine();
    }

    xb_xlive_font_DrawQueued();
}

void xb_LaunchDefaultXbe(void) {
    xb_PersistDisplay();
    XLaunchNewImageA("D:\\default.xbe", D_00798B80);
}

void XB_FASTCALL xb_XLIVE_FRIEND_CLASS_SetMode(u8* self, s32 edx, s32 mode) {
    (void)edx;

    switch (mode) {
    case 0:
    case 1:
    case 6:
        xb_SeSelectedThunk();
        *(s32*)(self + 0x8B0) = *(s32*)(self + 0x8B4);
        break;
    }
}

void XB_FASTCALL xb_XLIVE_FRIEND_CLASS_SetName(u8* self, s32 edx, const void* name) {
    (void)edx;
    lstrcpynW(self + 0x8D8, name, 0x40);
    CXBStopWatch_StartZero(self + 0x870);
}

s32 XB_FASTCALL xb_XLIVE_FRIEND_CLASS_RequestFriend(u8* self) {
    return XOnlineFriendsRequest(*(s32*)(D_00798CAC + 0x14), *(XB_REQ12*)(self + 0x960));
}

s32 XB_FASTCALL xb_XLIVE_FRIEND_CLASS_SendFriendAction(u8* self, s32 edx, s32 a, s32 b) {
    (void)edx;
    return XOnlineFriendsRequestEx(*(s32*)(D_00798CAC + 0x14), *(XB_REQ12*)(self + 0x960), a, 0, b);
}

s32 XB_FASTCALL xb_XLIVE_FRIEND_CLASS_OpenWindow(u8* self, s32 edx, s32 i, f32 a, f32 b, f32 c, f32 d) {
    s32* h = (s32*)(self + i * 4 + 0xA8C);

    (void)edx;

    if (*h == -1) {
        *h = xb_xlive_disp_DrawRectF(a, b, c, d, 1.2f);
        xb_xlive_disp_SetObj0C(*h, 0xFF000000);
        xb_OnlineObj_Move(*h);
    }

    return (s8)xb_OnlineObj_IsDone(*h);
}

s32 XB_FASTCALL xb_XLIVE_FRIEND_CLASS_UpdateWindows(u8* self) {
    s32 done = 1;
    s32 any = 0;
    s32* w = (s32*)(self + 0xA8C);
    s32 i;

    for (i = 0; i < 2; i++, w++) {
        if (*w != -1) {
            any = 1;
            done &= (s8)xb_OnlineObj_IsDone(*w);
        }
    }

    return any ? done : 0;
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

s32 XB_FASTCALL xb_XLIVE_WORK_CLASS_CheckPad(u8* self) {
    s32* c;

    if (sub_0011055B(0xF)) {
        c = (s32*)(self + 0x2CC);

        if (sub_0011055B(D_003F8328[*c])) {
            (*c)++;
        } else {
            *c = 0;
        }
    }

    return D_003F8328[*(s32*)(self + 0x2CC)] == -1;
}

void xb_xlive_match_ClearRecordWork(void) {
    memset(D_0079902C, 0, 0x30);
}

void* xb_GetMatchInfo(void) {
    return D_00798EA8;
}

s32 xb_xlive_match_OpenWindow(u8 kind, u8* w) {
    f32* r = (f32*)(D_002B53F0 + kind * 16);

    if (w[0] == 0) {
        w[0] = 1;
        w[1] = 0;
        *(s32*)(w + 4) = xb_xlive_disp_DrawRectFloat(r[0], r[1], r[2], r[3]);
        return xb_OnlineObj_Move(*(s32*)(w + 4));
    }

    return (s32)r;
}

s32 xb_xlive_match_ReopenWindow(s32 a, u8* w) {
    if (w[0]) {
        xb_xlive_friend_Release(*(s32*)(w + 4));
        w[1] = 0;
        w[0] = 0;
    }

    return xb_xlive_match_OpenWindow(a, w);
}

void xb_xlive_match_FadeWindow(void) {
    XB_MATCHINFO* info = xb_GetMatchInfo();
    s32 i;

    for (i = 0; i < 4; i++) {
        if (info->win[i].used != 0) {
            info->win[i].active = 0;
            xb_OnlineObj_Fade(info->win[i].id);
        }
    }
}

void xb_xlive_match_ReleaseWindow(void) {
    XB_MATCHINFO* info = xb_GetMatchInfo();
    s32 i;

    for (i = 0; i < 4; i++) {
        if (info->win[i].used != 0) {
            info->win[i].used = 0;
            info->win[i].active = 0;
            xb_xlive_friend_Release(info->win[i].id);
        }
    }
}

s32 xb_xlive_match_IsWindowDone(u8* w) {
    if (w[0] == 0) {
        return -1;
    }

    if (xb_OnlineObj_IsDone(*(s32*)(w + 4))) {
        w[1] = 1;
        return 1;
    }

    return 0;
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

void xb_LivePadHeld(void) {
    if (xb_LiveTimer_Elapsed() > 0.15f || *(s16*)(flpad_adr + xb_LiveWork_Get14() * 0x88 + 0x30) < 0x28) {
        xb_LiveTimer_Stop();
        xb_ClearLivePadState();
    }
}

s32 xb_LivePadActive(void) {
    return *(s32*)(xb_LiveWork_Get14() * 0x88 + flpad_adr + 0x10) != 0;
}

s32 xb_LivePadConnected(void) {
    if (*(u16*)(xb_LiveWork_Get14() * 0x88 + flpad_adr + 2) == 0 ||
        *(u16*)(xb_LiveWork_Get14() * 0x88 + flpad_adr + 2) == 0x8000) {
        return 0;
    }

    return 1;
}

void xb_ClearLivePadLatch(void) {
    D_0079A34C = 0;
    D_0079A348 = 0;
}

void xb_LivePadLatch(s32 mask) {
    D_0079A348 |= *(s32*)(xb_LiveWork_Get14() * 0x88 + flpad_adr + 0x10) & mask;
    D_0079A34C |= *(s32*)(xb_LiveWork_Get14() * 0x88 + flpad_adr + 0xC) & mask;
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

s32 xb_LivePadPressedConfirm(void) {
    xb_LivePadLatch(0x4020);
    return *(s32*)(xb_LiveWork_Get14() * 0x88 + flpad_adr + 0x10) & 0x4020;
}

s32 xb_LivePadPressed(s32 mask) {
    xb_LivePadLatch(mask);

    if ((*(s32*)(xb_LiveWork_Get14() * 0x88 + flpad_adr + 0x10) & mask) &&
        !(*(s32*)(xb_LiveWork_Get14() * 0x88 + flpad_adr + 0xC) & mask)) {
        return 1;
    }

    return 0;
}

s32 XB_FASTCALL xb_XLIVE_WORK_CLASS_ReleaseQos(u8* self) {
    if (*(s32*)(self + 0x290)) {
        XNetQosRelease(*(void**)(self + 0x2C8));
        *(s32*)(self + 0x2C8) = 0;
        *(s32*)(self + 0x290) = 0;
    }

    sub_000F8F07(self + 0x298);
    sub_000F8F07(self + 0x2A8);
    sub_000F8F07(self + 0x2B8);
    return 0;
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

void XB_FASTCALL xb_XLIVE_STARTMENU_CLASS_Clear(u8* self) {
    memset(self + 4, 0, 0x50);
    *(s32*)(self + 0x64) = -1;
    *(s32*)(self + 0x58) = 0;
    *(s32*)(self + 0x5C) = 0;
    self[0x6C] = 1;
    *(s32*)(self + 0x7C) = 0;
    *(s32*)(self + 0x78) = 0;
    self[0x6D] = 0;
}

void XB_FASTCALL xb_XLIVE_STARTMENU_CLASS_Set6C(u8* self, s32 edx, u8 v) {
    (void)edx;
    self[0x6C] = v;
}

void XB_FASTCALL xb_XLIVE_STATMENU_CLASS_ReleaseSlot(u8* self) {
    if (*(s32*)(self + 0x54) != -1) {
        xb_xlive_friend_Release(*(s32*)(self + 0x54));
        *(s32*)(self + 0x54) = -1;
    }

    if (*(s32*)(self + 0x58) != -1) {
        xb_xlive_friend_Release(*(s32*)(self + 0x58));
        *(s32*)(self + 0x58) = -1;
    }

    if (*(s32*)(self + 0x5C) != -1) {
        xb_xlive_friend_Release(*(s32*)(self + 0x5C));
        *(s32*)(self + 0x5C) = -1;
    }

    if (*(s32*)(self + 0x60) != -1) {
        xb_xlive_friend_Release(*(s32*)(self + 0x60));
        *(s32*)(self + 0x60) = -1;
    }
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

void xb_LiveWork_Menu24C0(s32 v) {
    XB_ARG a;

    a.v = v;
    ((void (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_STARTMENU_CLASS_Set6C)(D_00798CAC + 0x24C0, a);
}

s32 XB_FASTCALL xb_XLIVE_STATMENU_CLASS_Release(u8* self) {
    xb_XLIVE_STATMENU_CLASS_ReleaseSlot(self);
    xb_XLIVE_PAGE_CLASS_Clear(self);
    return 0;
}

void xb_LiveWork_Update24C0(void) {
    if (xb_LiveWork_Call113F24() || xb_LiveWork_Get2330() || xb_GetOnlineFlagThunk()) {
        xb_XLIVE_STARTMENU_CLASS_Update(D_00798CAC + 0x24C0);
    }
}

void XB_FASTCALL xb_XLIVE_STARTMENU_CLASS_Countdown(u8* self) {
    switch (*(s32*)(self + 0xC)) {
    default:
        (*(s32*)(self + 4))--;
        break;

    case 0:
        *(s32*)(self + 0xC) = 1;
        xb_XLIVE_STATMENU_CLASS_Init(D_00798CAC + 0x2544);

    case 1:
        if (xb_XLIVE_STATMENU_CLASS_StepTimer(D_00798CAC + 0x2544)) {
            xb_OnlineObj_SetFlag(*(s32*)(self + 0x64), 1);
            (*(s32*)(self + 0xC))++;
        }

        break;
    }
}

void xb_LiveWork_Poll24C0(void) {
    if (xb_XLIVE_WORK_CLASS_Get235C(D_00798CAC) || xb_GetOnlineFlagThunk()) {
        xb_XLIVE_STARTMENU_CLASS_StatUpdate(D_00798CAC + 0x24C0);
    }
}

s32 xb_OnlineObj_IsId(s32 id) {
    return *(s16*)(D_0079A472 + (id >> 16) * 0x5C) == (s16)id;
}

u8* xb_FindOnlineObj(s32 id) {
    s32 i = id >> 16;
    u8* r = 0;

    if (i < 0 || i >= 30) {
        return 0;
    }

    if (*(s16*)(D_0079A418 + i * 0x5C + 0x5A) == (s16)id) {
        r = D_0079A418 + i * 0x5C;
    }

    return r;
}

void xb_OnlineObj_Kill(s32 id) {
    if (xb_OnlineObj_IsId(id) == 1) {
        memset(D_0079A418 + (id >> 16) * 0x5C, 0, 0x5C);
    }
}

void xb_OnlineObj_SetFlag(s32 id, u8 v) {
    if (xb_OnlineObj_IsId(id)) {
        D_0079A470[(id >> 16) * 0x5C] = v;
    }
}

u8 xb_OnlineObj_IsDone(s32 id) {
    if (xb_OnlineObj_IsId(id) == 0) {
        return 1;
    }

    {
        u8 r = D_0079A418[(id >> 16) * 0x5C + 1] == 0;

        return r;
    }
}

u8 xb_OnlineObj_Exists(s32 id) {
    u8 r = xb_OnlineObj_IsId(id) != 0;

    return r;
}

s32 xb_OnlineStartup(s32 params) {
    return XOnlineStartup(params);
}

void xb_SetSaveCallbacks(void (*save)(void), void (*load)(void)) {
    D_0079AF08 = save;
    D_0079AF04 = load;
}

void xb_NetSync_SetState(s32 state) {
    D_007A7BC8 = D_007A7BC4;
    D_007A7BC4 = state;
    D_007A7BCC = 0;
    D_007A7BCD = 0;
    D_007A7BCE = 0;
    D_007A7BCF = 0;
    D_007A7BD0 = 0;
    D_007A7BD2 = 0;
}

u16 xb_MsgQueueGetCount(void) {
    return D_0079B714;
}

void xb_NetSync_SetPacketTarget(u8 player, s32 target) {
    D_007A7A1C = player;
    D_007A7A18 = target;
    D_007A7A5A = player;
}

s32 xb_NetSync_BuildHeader(s32 sock, s32 a, s32 b, XB_SEQ seq, s32 c, s32* id) {
    s32 r;

    D_007A7600[6] = seq.hi >> 8;
    D_007A7600[7] = seq.hi;
    D_007A7600[0] = 0x82;
    D_007A7600[1] = 2;
    D_007A7600[2] = 0x10;
    D_007A7600[3] = 0x31;
    D_007A7600[4] = 0;
    D_007A7600[5] = 8;
    D_007A7600[8] = 0;
    D_007A7600[9] = 0xFF;
    D_007A7600[10] = 0xFF;
    D_007A7600[11] = 0xFF;
    *(s32*)(D_007A7600 + 12) = id[0];
    *(s32*)(D_007A7600 + 16) = id[1];
    r = xb_NetSync_Send(sock, D_007A7600, 0x14);

    if (r != 0x14) {
        xb_NetSync_SetPacketTarget(4, r);
        return -1;
    }

    return 0;
}

void xb_NetSync_Check(void) {
    if (xb_NetSync_BuildRequest(D_007A7BC0, D_007A7A0C) < 0) {
        xb_NetSync_SetState(9);
    }
}

s32 xb_NetSync_BuildAck(s32 sock, s8 pl, u8 a, u8 b) {
    s32 r;

    if (pl < 0 || D_007A7A0A <= pl) {
        return 0;
    }

    D_007A7600[1] = pl | 0x50;
    D_007A7600[3] = b;
    D_007A7600[0] = 6;
    D_007A7600[2] = 1;
    D_007A7600[4] = a;
    D_007A7600[5] = 0;
    r = xb_NetSync_Send(sock, D_007A7600, 6);

    if (r != D_007A7600[0]) {
        xb_NetSync_SetPacketTarget(4, r);
        return -1;
    }

    return 0;
}

s32 xb_NetSync_FindEntry(s32 a, u8* buf, s32 size) {
    s32 n = xb_NetSync_Receive(a, buf, size);

    if (n < 0 || n >= size) {
        xb_NetSync_SetPacketTarget(3, n);
        return -1;
    }

    memset(&buf[n], 0, 1);

    if (n == 0) {
        return 0;
    }

    D_007A7A38 += n;
    return n;
}

s32 xb_NetSync_Send(s32 sock, const void* buf, s16 len) {
    s32 r = send(sock, buf, len, 0);

    if (r == -1) {
        return WSAGetLastError() == 0x2733 ? 0 : -1;
    }

    return r;
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

s32 xb_LiveWork_Create(void) {
    s32 size = 0;
    s32 key = load_it_use_any_key2(0xC, &D_0079B834, &size, 2, 0);

    if (key == 0) {
        flLogOut(D_002B877C);
        while (1) {}
    }

    D_0079B828 = 0;
    D_0079B82C = 0;
    DirectSoundCreate(0, &D_00795C10, 0);
    DirectSoundUseLightHRTF();
    xb_DownloadEffectsImage(D_00795C10, D_0079B834, key, &D_0079B828, &D_0079B830);
    return 1;
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

void xb_RegisterSaveHandlers(void) {
    xb_SetLiveCallback(0, (s32)sub_001206D8);
    xb_SetLiveCallback(1, (s32)sub_0004AFFA);
    xb_SetLiveCallback(2, (s32)sub_001204D8);
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

void xb_SaveStateRun(void) {
    sub_0016AA60();
    D_00436F0C[D_007A156C](&D_007A14A0);
    sub_0016AA70();
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

s32 xb_Get7A1808(void) {
    return D_007A1808;
}

void xb_SeSelectedThunk(void) {
    SE_selected();
}

void xb_SeCursorMoveThunk(void) {
    SE_cursor_move();
}
