/* xlive_match.c: Xbox-only code from Capcom's xlive_match.cpp. Its _assert path names it, and the
 * code that pushes the path places it at 0x10A017 to 0x10EDB7.
 * Capcom's source is lost. Its C++ methods are written as C,
 * XB_FASTCALL (__fastcall) with this first. Each body was checked
 * against retail by analysis-ps2map/xbgen.py. The xb_ names are
 * made up. */

#include "types.h"
#include <string.h>

extern u8* D_00798CAC;
void xb_xlive_match_ReleaseWindow(void);
s32 xb_xlive_match_AreWindowsDone(void);
void xb_xlive_match_FadeWindow(void);
void XB_FASTCALL xb_xlive_main_ClearWin(void* self);
void xb_xlive_disp_DrawMessage(s32 a, s32 b, s32 c, f32 scale, f32 alpha, s32 flags);
void* xb_GetMatchInfo(void);
s32 XB_FASTCALL CXBOnlineTask_Continue(void* self);
extern char D_002B4F38[];
extern char D_002B5150[];
s32 XB_STDCALL XNetUnregisterKey(void* key);
void _assert(const char* expr, const char* file, u32 line);
s32 XB_FASTCALL CXBOnlineTask_Close(void* self);
s32 XB_FASTCALL CXBOnlineTask_operator_addr(void* self);
s32 XB_STDCALL XOnlineMatchSessionDelete(s32 a, s32 b, s32 c, s32 d);
s32 xb_xlive_main_SetMatchArgs(s32 hr, const char* file, s32 line, s32 a);
s32 xb_xlive_net_Step(void);
extern s16 D_00798E74;
s32 XB_FASTCALL xb_xlive_stat_GetWins(void* self);
s32 XB_FASTCALL xb_xlive_stat_GetMatches(void* self);
s32 XB_FASTCALL xb_xlive_stat_GetGrade(void* self);
s32 XB_FASTCALL xb_xlive_stat_GetPoint(void* self);
s32 xb_xlive_match_CreateSession(void);
s32 xb_xlive_match_UpdateSession(u8 open);
s32 XB_FASTCALL xb_LiveObj_Start(u8* self);
void XB_FASTCALL xb_LiveObj_Stop(u8* self);
void* xb_vector_PlacementNew(u32 size, void* where);
s32 xb_xlive_match_CheckVoiceReady(void);
void xb_xlive_match_DrawStatsIfHost(void);
s32 xb_xlive_match_PeerVoiceC(u8 kind);
void xb_vector_SearchResult_UninitCopyWrap(void* a, void* b, void* c, void* self);
void xb_xlive_disp_DrawTextAt(f32 x, f32 y, s32 text);
void xb_xlive_disp_DrawMessageDefault(s32 a, s32 b, s32 c);
u8* XB_FASTCALL xb_LiveWork_Get2408(u8* self);
void xb_SeSelectedThunk(void);
void xb_xlive_match_OpenWindow(u8 kind, u8* w);
s32 XB_FASTCALL xb_XLIVE_WORK_CLASS_Frame(u8* self);
s32 xb_NetSync_GetProgress(void);
void xb_xlive_disp_SetBlueBar(s32 v);
s32 sprintf(char* buf, const char* fmt, ...);
extern char D_002B5378[];
void xb_xlive_match_ReopenWindow(s32 a, u8* w);
s32 xb_xlive_match_IsWindowDone(u8* w);
void xb_xlive_match_DrawRankingTable2(void);
void XB_FASTCALL xb_XLIVE_WORK_CLASS_RestartQos(u8* self);
s32 XB_FASTCALL sub_000F57C6(u8* self);
u8* XB_FASTCALL xb_XLIVE_WORK_CLASS_Get2338(u8* self);
s32 XB_FASTCALL xb_XLIVE_SIGNON_DropPlayer(u8* self);

void XB_FASTCALL xb_XLIVE_WORK_CLASS_JoinUpdate_State5(u8* self) {
    u8* m = xb_GetMatchInfo();

    switch (*(s32*)(self + 0x2370)) {
    case 0:
        *(s32*)(self + 0x2370) = 1;
        *(s32*)(self + 0x23B4) = 0x78;
        xb_SeSelectedThunk();
        xb_xlive_match_OpenWindow(2, m + 0x184);

    case 1:
        if (xb_xlive_match_AreWindowsDone() == 0) {
            return;
        }

        (*(s32*)(self + 0x2370))++;

    case 2:
        if (--*(s32*)(self + 0x23B4) >= 0) {
            return;
        }

        *(s32*)(self + 0x2370) = 0;
        *(s32*)(self + 0x236C) = 8;
        xb_xlive_match_ReleaseWindow();
    }
}

void XB_FASTCALL xb_XLIVE_WORK_CLASS_JoinUpdate_State15(u8* self) {
    switch (*(s32*)(self + 0x2370)) {
    case 2:
        *(s32*)(D_00798CAC + 0x2368) = 0;
        *(s32*)(D_00798CAC + 0x236C) = 0;
        *(s32*)(D_00798CAC + 0x2370) = 0;
        break;

    case 1:
        if (xb_xlive_match_AreWindowsDone()) {
            (*(s32*)(self + 0x2370))++;
            xb_xlive_match_ReleaseWindow();
        }

        break;

    case 0:
        *(s32*)(self + 0x2370) = 1;
        xb_xlive_match_FadeWindow();
        xb_xlive_main_ClearWin(self);
        break;
    }
}

void XB_FASTCALL xb_XLIVE_WORK_CLASS_JoinDraw_State0(u8* self) {
    if (((u8*)xb_GetMatchInfo())[0xCB] == 0) {
        (*(void (XB_FASTCALL**)(u8*))(*(u8**)self + 0x24))(self);
    } else {
        (*(void (XB_FASTCALL**)(u8*))(*(u8**)self + 0x20))(self);
    }
}

void XB_STDCALL xb_xlive_match_DrawTextRight(f32 x, f32 y, const char* s) {
    u32 n = strlen(s);

    if (n) {
        xb_xlive_disp_DrawTextAt(x - (s32)(n - 1) * 10.0f, y, (s32)s);
    }
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

void xb_XLIVE_WORK_CLASS_JoinDraw_State6(void) {
    if (((u8*)xb_GetMatchInfo())[0x180] != 4) {
        xb_xlive_disp_DrawMessageDefault(3, 0x3F, 0);
    } else {
        xb_xlive_disp_DrawMessageDefault(3, 0x4D, 0);
    }
}

void xb_XLIVE_WORK_CLASS_JoinDraw_State7(void) {
    xb_xlive_disp_DrawMessageDefault(3, 0x65, 0);
}

void xb_XLIVE_WORK_CLASS_JoinDraw_State14(void) {
    xb_xlive_disp_DrawMessageDefault(3, 0x5F, 0);
    xb_xlive_disp_DrawMessage(3, 0x59, 0, 0.6f, 1.0f, 4);
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

void XB_FASTCALL xb_XLIVE_WORK_CLASS_HostDraw_State0(u8* self) {
    (*(void (XB_FASTCALL**)(u8*))(*(u8**)self + 0x28))(self);
}

void xb_XLIVE_WORK_CLASS_HostDraw_State5(void) {
    xb_xlive_disp_DrawMessageDefault(3, 0x4A, 0);
    xb_xlive_disp_DrawMessageDefault(3, 0x63, 0);
}

void XB_FASTCALL xb_XLIVE_WORK_CLASS_HostDraw_State11(u8* self) {
    (*(void (XB_FASTCALL**)(u8*))(*(u8**)self + 0x2C))(self);
    xb_xlive_disp_DrawMessageDefault(3, 0x5E, 0);
}

void xb_xlive_match_UnregisterKey(void) {
    if (*(s32*)(D_00798CAC + 0xD0)) {
        if (XNetUnregisterKey(D_00798CAC + 0xB4)) {
            _assert(D_002B4F38, D_002B5150, 0x12E7);
        }

        *(s32*)(D_00798CAC + 0xD0) = 0;
        memset(D_00798CAC + 0xB4, 0, 8);
    }
}

void XB_FASTCALL xb_XLIVE_WORK_CLASS_CloseMatchTasks(u8* self) {
    CXBOnlineTask_Close(self + 0xFC);
    CXBOnlineTask_Close(self + 0x100);
    CXBOnlineTask_Close(self + 0x108);
}

s32 XB_FASTCALL xb_xlive_match_DeleteSession(u8* self, s32 edx, s32 quiet) {
    s32 hr;

    (void)edx;
    CXBOnlineTask_Close(self + 0xFC);
    hr = XOnlineMatchSessionDelete(*(s32*)(self + 0xB4), *(s32*)(self + 0xB8), 0, CXBOnlineTask_operator_addr(self + 0x108));

    if (quiet == 0 && hr < 0) {
        *(s32*)(self + 0x2370) = 0;
        *(s32*)(self + 0x236C) = 0xC;
        xb_xlive_main_SetMatchArgs(hr, D_002B5150, 0x130C, 1);
    }

    return hr;
}

void* XB_FASTCALL xb_xlive_match_Rec54_ctor(void* self) {
    memset(self, 0, 0x54);
    return self;
}

s32 xb_xlive_match_StepLink(void) {
    return xb_xlive_net_Step() != 0;
}

void xb_xlive_match_DrawStatus(void) {
    char buf[16];
    s32 v;

    if (xb_XLIVE_WORK_CLASS_Frame(D_00798CAC)) {
        return;
    }

    v = xb_NetSync_GetProgress();

    if (v > 0x26AC) {
        v = 10000;
    }

    xb_xlive_disp_SetBlueBar(v);
    sprintf(buf, D_002B5378, v / 100);
    xb_xlive_disp_DrawTextAt(300.0f, 385.0f, (s32)buf);
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

void xb_xlive_match_DrawBlinkMessage(s32 a, s32 b, s32 c) {
    if (D_00798E74-- == 0) {
        D_00798E74 = 0x3F;
    }

    if (D_00798E74 & 0x20) {
        xb_xlive_disp_DrawMessageDefault(a, b, c);
    }
}

void xb_xlive_match_DrawLabel(f32 x, f32 y, const char* s, s32 center) {
    f32 px;

    if (center == 0) {
        px = x;
    } else {
        px = x - (s32)strlen(s) / 2 * 10.0f;
    }

    xb_xlive_disp_DrawTextAt(px, y, (s32)s);
}

u8** XB_FASTCALL xb_vector_SearchResult_ItAddAssign(u8** self, s32 edx, s32 n) {
    (void)edx;
    *self += n * 0xBC;
    return self;
}

s32 XB_FASTCALL xb_vector_SearchResult_ItDiff(u8** self, s32 edx, u8** other) {
    (void)edx;
    return (*self - *other) / 0xBC;
}

s32 XB_FASTCALL xb_XLIVE_STAT_CLASS_GetWins(u8* self) {
    return xb_xlive_stat_GetWins(self + 0x2C0);
}

s32 XB_FASTCALL xb_XLIVE_STAT_CLASS_GetMatches(u8* self) {
    return xb_xlive_stat_GetMatches(self + 0x2C0);
}

s32 XB_FASTCALL xb_XLIVE_STAT_CLASS_GetGrade(u8* self) {
    return xb_xlive_stat_GetGrade(self + 0x2C0);
}

s32 XB_FASTCALL xb_XLIVE_STAT_CLASS_GetPoint(u8* self) {
    return xb_xlive_stat_GetPoint(self + 0x2C0);
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

s32 xb_xlive_match_TickTimer16E(void) {
    u8* m = xb_GetMatchInfo();
    s16* t = (s16*)(m + 0x16E);

    if (--*t < 0) {
        if (m[0x17F]) {
            return 1;
        }

        xb_xlive_match_ResetTimer16E();
    }

    return 0;
}

void xb_xlive_match_SetJoinState15(void) {
    *(s32*)(D_00798CAC + 0x2368) = 2;
    *(s32*)(D_00798CAC + 0x236C) = 0xF;
    *(s32*)(D_00798CAC + 0x2370) = 0;
    xb_xlive_match_ClearFlag10();
    xb_xlive_match_ClearFlag2();
}

void xb_XLIVE_WORK_CLASS_JoinDraw_State2(void) {
    if (((u8*)xb_GetMatchInfo())[0xCB] == 1) {
        xb_xlive_match_DrawBlinkMessage(3, 0x42, 0);
    } else {
        xb_xlive_match_DrawBlinkMessage(3, 0x41, 0);
    }
}

void xb_xlive_match_CreateSessionAndWait(void) {
    xb_xlive_match_CreateSession();
    *(s32*)(D_00798CAC + 0x236C) = 2;
    *(s32*)(D_00798CAC + 0x2370) = 0;
}

void xb_xlive_match_StartUpdateSession(void) {
    *(s32*)(D_00798CAC + 0x236C) = 3;
    *(s32*)(D_00798CAC + 0x2370) = 2;
    *(s32*)(D_00798CAC + 0x2374) = 0;
    xb_xlive_match_SetFlag2();
    xb_xlive_match_SetFlag10();
    xb_xlive_match_UpdateSession(1);
    xb_xlive_match_ResetTimer16C();
    xb_xlive_match_ResetTimer16E();
}

u8 xb_XLIVE_WORK_CLASS_IsHost(void) {
    if (xb_xlive_match_IsGuest() && *(s32*)(D_00798CAC + 0x236C) == 3) {
        return ((u8*)xb_GetMatchInfo())[0x17E];
    }

    return 0;
}

void XB_FASTCALL xb_XLIVE_WORK_CLASS_HostUpdate_State5(u8* self) {
    u8* m = xb_GetMatchInfo();
    s32* st = (s32*)(self + 0x2370);

    switch (*st) {
    case 0:
        *st = 1;
        *(s32*)(self + 0x23B4) = 0x78;
        xb_SeSelectedThunk();

    case 1:
        if (--*(s32*)(self + 0x23B4) >= 0) {
            break;
        }

        switch (*(s32*)(self + 0x2374)) {
        case 2:
            xb_xlive_match_StartUpdateSession();
            *(s32*)(self + 0x2374) = 0;
            break;

        case 0:
            xb_xlive_match_ReopenWindow(1, m + 0x184);
            xb_xlive_match_ReopenWindow(3, m + 0x190);
            (*(s32*)(self + 0x2374))++;

        case 1:
            if (xb_xlive_match_IsWindowDone(m + 0x184)) {
                (*(s32*)(self + 0x2374))++;
            }

            break;
        }

        break;
    }
}

s32 xb_xlive_match_Voice_F5DA0(void) {
    return xb_LiveObj_Start(xb_LiveWork_Get2408(D_00798CAC));
}

void xb_xlive_match_Voice_F5B5F(void) {
    ((u8*)xb_GetMatchInfo())[0x17D] = 0;
    xb_LiveObj_Stop(xb_LiveWork_Get2408(D_00798CAC));
}

void xb_xlive_match_IsGuestReady(u8* pkt) {
    u8* m = xb_GetMatchInfo();

    if (xb_xlive_match_IsGuest() == 0) {
        m[0x180] = pkt[1];
    }
}

void xb_vector_SearchResult_Construct(void* where, void* src) {
    void* p = xb_vector_PlacementNew(0xBC, where);

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

void xb_xlive_match_ResetPeer(void) {
    u8* w;

    xb_XLIVE_WORK_CLASS_RestartQos(D_00798CAC);
    xb_xlive_match_UnregisterKey();
    w = D_00798CAC;

    if (sub_000F57C6(w + 0x28) == 2) {
        xb_XLIVE_SIGNON_DropPlayer(xb_XLIVE_WORK_CLASS_Get2338(w));
    }

    xb_xlive_match_Voice_F5B5F();
}

void xb_xlive_match_DrawWaitMessage(void) {
    xb_xlive_match_DrawStatsIfHost();
    xb_xlive_disp_DrawMessageDefault(3, 0x62, 0);
}

void XB_FASTCALL xb_XLIVE_WORK_CLASS_HostDraw_State2(u8* self) {
    (*(void (XB_FASTCALL**)(u8*))(*(u8**)self + 0x2C))(self);
    xb_xlive_match_DrawRankingTable2();
}

void XB_FASTCALL xb_XLIVE_WORK_CLASS_HostDraw_State3(u8* self) {
    switch (*(s32*)(D_00798CAC + 0x2370)) {
    case 0:
    case 1:
    case 2:
        (*(void (XB_FASTCALL**)(u8*))(*(u8**)self + 0x2C))(self);
        xb_xlive_match_DrawRankingTable2();
        break;
    }
}

void XB_FASTCALL xb_vector_SearchResult_ConstructAt(void* self, s32 edx, void* p, void* src) {
    (void)self;
    (void)edx;
    xb_vector_SearchResult_Construct(p, src);
}

void XB_FASTCALL xb_XLIVE_WORK_CLASS_SetState8(u8* self) {
    xb_xlive_match_ReleaseWindow();
    *(s32*)(self + 0x2370) = 0;
    *(s32*)(self + 0x236C) = 8;
    xb_xlive_match_PeerVoiceC(2);
}

void XB_FASTCALL xb_vector_SearchResult_Ucopy(void* self, s32 edx, void* a, void* b, void* c) {
    (void)edx;
    xb_vector_SearchResult_UninitCopyWrap(a, b, c, self);
}

void XB_FASTCALL xb_XLIVE_WORK_CLASS_ShowMessage(u8* self, s32 edx, s32 won);
void xb_xlive_match_JoinFromID(void);

/* xb_XLIVE_WORK_CLASS_SetMatchDone 0x10D187: the match marked over (match
 * info +0xCB 2) and its stats recorded; the host (+0x164 1) goes back to
 * its menu (flags 3, 11, 0), the others rejoin. */
s32 XB_FASTCALL xb_XLIVE_WORK_CLASS_SetMatchDone(u8* self) {
    XB_ARG a;

    ((u8*)xb_GetMatchInfo())[0xCB] = 2;
    a.v = 1;
    ((void (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_WORK_CLASS_ShowMessage)(self, a);

    switch (*(s32*)(self + 0x164)) {
    case 1:
        *(s32*)(D_00798CAC + 0x2368) = 3;
        *(s32*)(D_00798CAC + 0x236C) = 0xB;
        *(s32*)(D_00798CAC + 0x2370) = 0;
        *(s32*)(self + 0x3E0) = 0;
        break;
    case 2:
        xb_xlive_match_JoinFromID();
        break;
    case 3:
        xb_xlive_match_JoinFromID();
        break;
    case 4:
        xb_xlive_match_JoinFromID();
        break;
    }

    return 0;
}

/* The work's peers (+0x28) are a std::deque of 12-byte records. */
typedef struct {
    u32 w[3];
} XB_PEER12;
void* XB_FASTCALL xb_deque_LiveObj_Begin(void* self, s32 edx, void* out);
void* XB_FASTCALL xb_deque_LiveObj_End(void* self, s32 edx, void* out);
s32 XB_FASTCALL xb_deque_iterator_ne(void* self, s32 edx, void* other);
void* XB_FASTCALL xb_deque_iterator_inc(void* self);
XB_PEER12* XB_FASTCALL xb_deque_DerefThunk(void* self);
void xb_xlive_match_VoicePeer(XB_PEER12 peer);

/* xb_XLIVE_WORK_CLASS_SetState5 0x10E320: the menu to state 5; voice
 * with the first peer after the first, and voice mode 3. */
void XB_FASTCALL xb_XLIVE_WORK_CLASS_SetState5(u8* self) {
    u32 it[2];
    u32 b[2];
    u32 e[2];
    XB_ARG a;

    *(s32*)(self + 0x2370) = 0;
    *(s32*)(self + 0x236C) = 5;
    a.v = (s32)it;
    ((void* (XB_FASTCALL*)(u8*, XB_ARG))xb_deque_LiveObj_Begin)(D_00798CAC + 0x28, a);

    for (;;) {
        a.v = (s32)e;
        a.v = (s32)((void* (XB_FASTCALL*)(u8*, XB_ARG))xb_deque_LiveObj_End)(D_00798CAC + 0x28, a);

        if ((u8)((s32 (XB_FASTCALL*)(void*, XB_ARG))xb_deque_iterator_ne)(it, a) == 0) {
            break;
        }

        a.v = (s32)b;
        a.v = (s32)((void* (XB_FASTCALL*)(u8*, XB_ARG))xb_deque_LiveObj_Begin)(D_00798CAC + 0x28, a);

        if ((u8)((s32 (XB_FASTCALL*)(void*, XB_ARG))xb_deque_iterator_ne)(it, a) != 0) {
            xb_xlive_match_VoicePeer(*xb_deque_DerefThunk(it));
            break;
        }

        xb_deque_iterator_inc(it);
    }

    xb_xlive_match_PeerVoiceC(3);
}

u8* XB_FASTCALL xb_LiveWork_Get2408(u8* self);
u8 XB_FASTCALL xb_LiveObj_IsReady(u8* self, s32 edx, s32 arg);
u32 XB_FASTCALL xb_LiveObj_Count(u8* self);
u8* XB_FASTCALL xb_XLIVE_WORK_CLASS_Get2338(u8* self);
typedef struct {
    u32 w[4];
} XB_KEY16;
s32 XB_FASTCALL xb_LiveObj_SendVoice(u8* self, s32 edx, XB_KEY16 to, u8* msg);
void XB_FASTCALL xb_LiveObj_MarkPeer(u8* self, s32 edx, XB_PEER12 peer);

/* xb_xlive_match_CheckVoiceReady 0x10BFFC: a voice message (kind 7) with
 * whether this user's voice is ready, sent to the match's peer (+0x144). */
s32 xb_xlive_match_CheckVoiceReady(void) {
    u8* m = xb_GetMatchInfo();
    u8 msg[4];
    XB_ARG a;

    msg[0] = 7;
    msg[1] = 0;
    a.v = *(s32*)(D_00798CAC + 0x14);
    msg[2] = ((u8 (XB_FASTCALL*)(u8*, XB_ARG))xb_LiveObj_IsReady)(xb_LiveWork_Get2408(D_00798CAC), a);
    a.v = (s32)msg;
    return ((s32 (XB_FASTCALL*)(u8*, XB_KEY16, XB_ARG))xb_LiveObj_SendVoice)(xb_LiveWork_Get2408(D_00798CAC),
                                                                              *(XB_KEY16*)(m + 0x144), a);
}

/* xb_xlive_match_Voice_F59B3 0x10BD4F: the peer marked for voice. */
void xb_xlive_match_Voice_F59B3(XB_PEER12 peer) {
    ((u8*)xb_GetMatchInfo())[0x17D] = 0;
    ((void (XB_FASTCALL*)(u8*, XB_PEER12))xb_LiveObj_MarkPeer)(xb_LiveWork_Get2408(D_00798CAC), peer);
}

/* xb_xlive_match_VoicePeer 0x10CC37: with two players the sign-on's
 * player pair is settled first. */
void xb_xlive_match_VoicePeer(XB_PEER12 peer) {
    u8* w;

    ((u8*)xb_GetMatchInfo())[0x17E] = 0;
    w = D_00798CAC;

    if (xb_LiveObj_Count(w + 0x28) == 2) {
        xb_XLIVE_SIGNON_DropPlayer(xb_XLIVE_WORK_CLASS_Get2338(w));
    }

    xb_xlive_match_Voice_F59B3(peer);
}

void XB_FASTCALL xb_LiveAddr_GetPort(u8* self, s32 edx, u32* port);
u8* XB_FASTCALL xb_deque_LiveObj_Subscript(u8* self, s32 edx, u32 i);
void XB_FASTCALL xb_XLIVE_SIGNON_SetPlayerA8(u8* self, s32 edx, u32 player, u32 v);

/* xb_xlive_match_PeerEvent4 0x10D6C2: a peer's setting (body byte 1 to
 * match info +0x17F, byte 2 to +0x140); a guest, or a host in state 1,
 * passes byte 2 on for the player whose port the sender's is. */
void xb_xlive_match_PeerEvent4(u8* data, u8* from) {
    u8* m = xb_GetMatchInfo();
    u32 port;
    u32 i;
    XB_ARG a;
    XB_ARG b;

    m[0x17F] = data[1];
    *(s32*)(m + 0x140) = data[2];

    if (xb_xlive_match_IsGuest() == 0 && m[0x180] != 1) {
        return;
    }

    for (i = 0; i < xb_LiveObj_Count(D_00798CAC + 0x28); i++) {
        a.v = (s32)&port;
        ((void (XB_FASTCALL*)(u8*, XB_ARG))xb_LiveAddr_GetPort)(from, a);
        a.v = i;

        if (*(u32*)(((u8* (XB_FASTCALL*)(u8*, XB_ARG))xb_deque_LiveObj_Subscript)(D_00798CAC + 0x28, a) + 0xC) == port) {
            a.v = i;
            b.v = data[2];
            ((void (XB_FASTCALL*)(u8*, XB_ARG, XB_ARG))xb_XLIVE_SIGNON_SetPlayerA8)(xb_XLIVE_WORK_CLASS_Get2338(D_00798CAC), a, b);
            return;
        }
    }
}

typedef struct {
    u32 lo;
    u32 hi;
} XB_XNKID;
s32 XB_STDCALL XOnlineMatchSessionUpdate(XB_XNKID kid, u32 pubCur, u32 pubAvail, u32 privCur, u32 privAvail,
                                         u32 nattr, void* attr, void* ev, void* task);
s32 XB_FASTCALL CXBOnlineTask_Close(void* self);
s32 XB_FASTCALL CXBOnlineTask_operator_addr(void* self);
/* The session's attributes (XONLINE_ATTRIBUTE: id, changed, value). */
typedef struct {
    u32 id;
    u32 changed;
    s64 value;
} XB_XATTR;
extern XB_XATTR D_00798DA0[12];

/* xb_xlive_match_UpdateSession 0x10AC56: the session's slots updated
 * (its 12 attributes at D_00798DA0) with the task at +0xFC: open (one
 * slot used and one free, in the private slots for a private match +0xC6)
 * or full (both taken). */
s32 xb_xlive_match_UpdateSession(u8 open) {
    u8* m = xb_GetMatchInfo();
    u32 pubCur;
    u32 pubAvail;
    u32 privCur;
    u32 privAvail;

    if (open) {
        if (m[0xC6] == 0) {
            pubCur = 1;
            pubAvail = 1;
            privCur = 1;
        } else {
            pubCur = 0;
            pubAvail = 0;
            privCur = 1;
        }

        privAvail = 1;
    } else {
        if (m[0xC6] == 0) {
            pubCur = 2;
            privCur = 0;
        } else {
            pubCur = 0;
            privCur = 2;
        }

        privAvail = 0;
        pubAvail = 0;
    }

    CXBOnlineTask_Close(D_00798CAC + 0xFC);
    return XOnlineMatchSessionUpdate(*(XB_XNKID*)(D_00798CAC + 0xB4), pubCur, pubAvail, privCur, privAvail, 0xC,
                                     D_00798DA0, 0, (void*)CXBOnlineTask_operator_addr(D_00798CAC + 0xFC));
}

/* The match settings message (voice chat type 3) a host sends. */
typedef struct {
    u8 type;
    u8 kind;
    u8 key[0x10];
    u8 pad12[2];
    XB_PEER12 peer;
    s32 user;
    s32 v[6];
    s32 side;
    s32 x174;
    u8 ready;
    u8 c3;
    u8 pad46[2];
} XB_VCSETTINGS;

/* xb_xlive_match_PeerVoiceC 0x10D56B: the match settings sent to the
 * peer: the session key (+0xD4), the first player, this user, the six
 * settings (+0x108), the side (+0x170), +0x174 and voice ready. */
s32 xb_xlive_match_PeerVoiceC(u8 kind) {
    u8* m = xb_GetMatchInfo();
    XB_VCSETTINGS msg;
    XB_ARG a;

    msg.type = 3;
    msg.kind = kind;
    memcpy(msg.key, m + 0xD4, 0x10);
    a.v = 0;
    msg.peer = *(XB_PEER12*)((u8* (XB_FASTCALL*)(u8*, XB_ARG))xb_deque_LiveObj_Subscript)(D_00798CAC + 0x28, a);
    msg.user = *(s32*)(D_00798CAC + 0x14);
    msg.v[0] = *(s32*)(m + 0x108);
    msg.v[1] = *(s32*)(m + 0x10C);
    msg.v[2] = *(s32*)(m + 0x110);
    msg.v[3] = *(s32*)(m + 0x114);
    msg.v[4] = *(s32*)(m + 0x118);
    msg.v[5] = *(s32*)(m + 0x11C);
    msg.side = m[0x170];
    msg.x174 = *(s32*)(m + 0x174);
    a.v = *(s32*)(D_00798CAC + 0x14);
    msg.ready = ((u8 (XB_FASTCALL*)(u8*, XB_ARG))xb_LiveObj_IsReady)(xb_LiveWork_Get2408(D_00798CAC), a);
    a.v = (s32)&msg;
    return ((s32 (XB_FASTCALL*)(u8*, XB_KEY16, XB_ARG))xb_LiveObj_SendVoice)(xb_LiveWork_Get2408(D_00798CAC),
                                                                              *(XB_KEY16*)(m + 0x144), a);
}

/* The stats pages drawn side by side on the match screens. Retail passes
 * xb_xlive_match_DrawColorText its kind in al and value in ecx, and
 * xb_xlive_match_DrawStatsPage its record in ebx; both are static here
 * (config/sf33rd/static.txt). */
int sprintf(char* buf, const char* fmt, ...);
void xb_xlive_disp_DrawTextBox(f32 x, f32 y, f32 s, s32 text, f32 alpha, s32 flags);
char* XB_FASTCALL xb_XLIVE_STAT_CLASS_LangName(u8* self, s32 edx, s32 lang);
extern char* D_003F8398[];
extern f32 D_003F8438;
extern f32 D_003F843C;
extern f32 D_003F8440;
extern f32 D_003F8444;
extern f32 D_003F8448;
extern f32 D_003F844C;
extern f32 D_003F8450;
extern f32 D_003F8454[];
extern f32 D_0025F370;
extern f32 D_0021CCE0;
extern f32 D_002AEEC4;
extern f32 D_002B4BE4;
extern char D_002B5348[];
extern char D_002B533C[];
extern char D_002B5330[];
extern char D_002B5324[];
extern char D_002B5318[];
extern char D_002B530C[];
extern char D_002B5304[];
extern char D_002B5300[];
extern char D_002B52FC[];
extern f32 D_0021941C;
extern f32 D_002B4E68;
extern f32 D_002B53D8;
extern char D_002B53D0[];
extern char D_002B53C8[];

/* xb_xlive_match_DrawColorText 0x10A535: text v of colour table kind
 * (D_003F8398, 20 to a kind). */
void xb_xlive_match_DrawColorText(u8 kind, s32 v, f32 x, f32 y) {
    xb_xlive_disp_DrawTextAt(x, y, (s32)D_003F8398[kind * 20 + v]);
}

/* xb_xlive_match_DrawStatsPage 0x10A631: a player's stats record in
 * column side: the name, then rank (---- for none), points, grade,
 * wins, matches and language. */
void xb_xlive_match_DrawStatsPage(u8 side, u8* rec) {
    char buf[0x80];
    f32 x = D_003F8454[side];

    xb_xlive_disp_DrawTextBox(x - D_0021CCE0 - (f32)((s32)strlen((char*)rec) / 2) * D_0021CCE0, D_003F8438, D_0025F370,
                              (s32)rec, 1.0f, 7);
    x = x - D_002AEEC4;
    sprintf(buf, D_002B5348);
    xb_xlive_disp_DrawTextBox(x, D_003F843C, D_0025F370, (s32)buf, 1.0f, 5);
    sprintf(buf, D_002B533C);
    xb_xlive_disp_DrawTextBox(x, D_003F8440, D_0025F370, (s32)buf, 1.0f, 5);
    sprintf(buf, D_002B5330);
    xb_xlive_disp_DrawTextBox(x, D_003F8444, D_0025F370, (s32)buf, 1.0f, 5);
    sprintf(buf, D_002B5324);
    xb_xlive_disp_DrawTextBox(x, D_003F8448, D_0025F370, (s32)buf, 1.0f, 5);
    sprintf(buf, D_002B5318);
    xb_xlive_disp_DrawTextBox(x, D_003F844C, D_0025F370, (s32)buf, 1.0f, 5);
    sprintf(buf, D_002B530C);
    xb_xlive_disp_DrawTextBox(x, D_003F8450, D_0025F370, (s32)buf, 1.0f, 5);
    x = x + D_002AEEC4;

    if (*(s32*)(rec + 0x40) == 0) {
        strcpy(buf, D_002B5304);
    } else {
        sprintf(buf, D_002B5300, *(s32*)(rec + 0x40));
    }

    xb_xlive_disp_DrawTextAt(x, D_003F843C, (s32)buf);
    sprintf(buf, D_002B5300, *(s32*)(rec + 0x44));
    xb_xlive_disp_DrawTextAt(x, D_003F8440, (s32)buf);
    xb_xlive_match_DrawColorText(1, *(s32*)(rec + 0x3C), x + D_002B4BE4, D_003F8444);
    sprintf(buf, D_002B5300, *(s32*)(rec + 0x38));
    xb_xlive_disp_DrawTextAt(x, D_003F8448, (s32)buf);
    sprintf(buf, D_002B5300, *(s32*)(rec + 0x34));
    xb_xlive_disp_DrawTextAt(x, D_003F844C, (s32)buf);
    {
        XB_ARG a;

        a.v = *(s32*)(rec + 0x48);
        sprintf(buf, D_002B52FC, ((char* (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_STAT_CLASS_LangName)(D_00798CAC + 0x5090, a));
    }
    xb_xlive_disp_DrawTextAt(x, D_003F8450, (s32)buf);
}

/* xb_xlive_match_DrawStatsIfHost 0x10B756: both players' stats, this
 * console's on the left (the host's records are +0x120 and +0xD4). */
void xb_xlive_match_DrawStatsIfHost(void) {
    u8* m = xb_GetMatchInfo();

    xb_xlive_disp_DrawTextAt(D_0021941C, D_002B53D8, (s32)D_002B53D0);
    xb_xlive_match_DrawStatsPage(0, xb_xlive_match_IsGuest() ? m + 0xD4 : m + 0x120);
    xb_xlive_disp_DrawTextAt(D_002B4E68, D_002B53D8, (s32)D_002B53C8);
    xb_xlive_match_DrawStatsPage(1, xb_xlive_match_IsGuest() ? m + 0x120 : m + 0xD4);
}

void xb_xlive_disp_DrawBox20(f32 x, f32 y, f32 s, s32 text, f32 alpha, s32 flags, s32 c);
void xb_xlive_disp_DrawMessageDefault(s32 a, s32 b, s32 c);
extern char D_002B53A8[];
extern char D_002B5388[];
extern f32 D_002B4EA4;
extern f32 D_002B4E98;
extern f32 D_002B5384;
extern f32 D_002B5380;

/* The opponent's line on the ranking screens: name (+0x120), rank (when
 * +0x160 is set), points (+0x164), wins (+0x154), matches (+0x158),
 * language (+0x168), grade (+0x15C), and whether the gap in points
 * (+0x178) is over 160. */
#define XB_DRAW_OPPONENT()                                                                                             \
    xb_xlive_disp_DrawMessage(3, 0x43, 0, D_0025F370, 1.0f, 5);                                                        \
    xb_xlive_disp_DrawBox20(0.0f, D_002B4EA4, D_0025F370, (s32)(m + 0x120), 1.0f, 7, 0);                              \
    xb_xlive_disp_DrawMessageDefault(3, 0x44, 0);                                                                      \
    a.v = *(s32*)(m + 0x168);                                                                                          \
                                                                                                                       \
    if (*(s32*)(m + 0x160) == 0) {                                                                                     \
        sprintf(buf, D_002B53A8, *(s32*)(m + 0x164), *(s32*)(m + 0x154), *(s32*)(m + 0x158),                          \
                ((char* (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_STAT_CLASS_LangName)(D_00798CAC + 0x5090, a));          \
    } else {                                                                                                           \
        sprintf(buf, D_002B5388, *(s32*)(m + 0x160), *(s32*)(m + 0x164), *(s32*)(m + 0x154), *(s32*)(m + 0x158),     \
                ((char* (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_STAT_CLASS_LangName)(D_00798CAC + 0x5090, a));          \
    }                                                                                                                  \
                                                                                                                       \
    xb_xlive_disp_DrawTextAt(D_002B5384, D_002B4E98, (s32)buf);                                                        \
    xb_xlive_match_DrawColorText(0, *(s32*)(m + 0x15C), D_002B5380, D_002B4E98);                                       \
                                                                                                                       \
    if (*(s32*)(m + 0x178) > 0xA0) {                                                                                   \
        xb_xlive_disp_DrawMessage(3, 0x46, 0, D_0025F370, 1.0f, 5);                                                    \
    } else {                                                                                                           \
        xb_xlive_disp_DrawMessage(3, 0x45, 0, D_0025F370, 1.0f, 4);                                                    \
    }

/* xb_xlive_match_DrawRankingTable 0x10B532: the opponent's line, with
 * two players. */
void xb_xlive_match_DrawRankingTable(void) {
    char buf[0x100];
    u8* m = xb_GetMatchInfo();
    XB_ARG a;

    if (xb_LiveObj_Count(D_00798CAC + 0x28) == 2) {
        XB_DRAW_OPPONENT();
    }
}

/* xb_xlive_match_DrawRankingTable2 0x10BA9C: the host's waiting screen:
 * the blinking wait message, and once an opponent has joined (+0x17E) its
 * line and the accept and decline prompts. */
void xb_xlive_match_DrawRankingTable2(void) {
    char buf[0x100];
    u8* m = xb_GetMatchInfo();
    XB_ARG a;

    switch (*(s32*)(D_00798CAC + 0x236C)) {
    case 2:
        xb_xlive_match_DrawBlinkMessage(3, 0x48, 0);
        return;
    }

    if (m[0x17E] == 0) {
        xb_xlive_match_DrawBlinkMessage(3, 0x48, 0);
        xb_xlive_disp_DrawMessage(3, 0x49, 0, D_0025F370, 1.0f, 4);
        return;
    }

    XB_DRAW_OPPONENT();
    xb_xlive_disp_DrawMessageDefault(3, 0x39, 0);
    xb_xlive_disp_DrawMessage(3, 0x3B, 0, D_0025F370, 1.0f, 4);
}


void XB_FASTCALL xb_XLIVE_SIGNON_AddPlayer(u8* self, s32 edx, u32* port, XB_PEER12* peer, XB_KEY16* key, s32 user, s32 v);
void xb_xlive_match_Voice_F619B(void);

/* xb_xlive_match_PeerEvent3 0x10BD7E: the host gets a guest's settings
 * (state 1): the guest's key, player, user and stats into the match info,
 * the guest added as a player, and voice set up. */
void xb_xlive_match_PeerEvent3(u8* data, u8* from) {
    u8* m = xb_GetMatchInfo();
    XB_VCSETTINGS* in = (XB_VCSETTINGS*)data;
    XB_KEY16* key;
    XB_PEER12* peer;
    u32 port;
    u8* w;
    XB_ARG a;
    XB_ARG b;
    XB_ARG c;
    XB_ARG d;
    XB_ARG e;

    if (xb_xlive_match_IsGuest()) {
        return;
    }

    m[0x180] = 1;
    key = (XB_KEY16*)(m + 0x120);
    *key = *(XB_KEY16*)in->key;
    peer = (XB_PEER12*)(m + 0x130);
    *peer = in->peer;
    *(s32*)(m + 0x13C) = in->user;
    *(s32*)(m + 0x154) = in->v[0];
    *(s32*)(m + 0x158) = in->v[1];
    *(s32*)(m + 0x15C) = in->v[2];
    *(s32*)(m + 0x160) = in->v[3];
    *(s32*)(m + 0x164) = in->v[4];
    *(s32*)(m + 0x168) = in->v[5];
    m[0xC3] = in->c3;
    m[0x170] = (u8)in->side;
    *(s32*)(m + 0x174) = in->x174;
    *(s32*)(m + 0x140) = in->ready;

    w = D_00798CAC;

    if (xb_LiveObj_Count(w + 0x28) == 2) {
        xb_XLIVE_SIGNON_DropPlayer(xb_XLIVE_WORK_CLASS_Get2338(w));
    }

    a.v = (s32)&port;
    ((void (XB_FASTCALL*)(u8*, XB_ARG))xb_LiveAddr_GetPort)(from, a);
    a.v = (s32)&port;
    b.v = (s32)peer;
    c.v = (s32)key;
    d.v = *(s32*)(m + 0x13C);
    e.v = *(s32*)(m + 0x140);
    ((void (XB_FASTCALL*)(u8*, XB_ARG, XB_ARG, XB_ARG, XB_ARG, XB_ARG))xb_XLIVE_SIGNON_AddPlayer)(xb_XLIVE_WORK_CLASS_Get2338(D_00798CAC), a, b, c, d, e);
    xb_xlive_match_Voice_F619B();
}

/* xb_xlive_match_PeerEvent2 0x10BEFB: a guest gets the host's settings;
 * the first time (not state 1) the host is added as a player and voice is
 * set up. The state becomes the message's kind. */
void xb_xlive_match_PeerEvent2(u8* data, u8* from) {
    u8* m = xb_GetMatchInfo();
    XB_VCSETTINGS* in = (XB_VCSETTINGS*)data;
    u32 port;
    u8* w;
    XB_ARG a;
    XB_ARG b;
    XB_ARG c;
    XB_ARG d;
    XB_ARG e;

    *(XB_KEY16*)(m + 0x120) = *(XB_KEY16*)in->key;
    *(XB_PEER12*)(m + 0x130) = in->peer;
    *(s32*)(m + 0x13C) = in->user;
    *(s32*)(m + 0x154) = in->v[0];
    *(s32*)(m + 0x158) = in->v[1];
    *(s32*)(m + 0x15C) = in->v[2];
    *(s32*)(m + 0x160) = in->v[3];
    *(s32*)(m + 0x164) = in->v[4];
    *(s32*)(m + 0x168) = in->v[5];
    m[0x170] = (u8)in->side;
    *(s32*)(m + 0x174) = in->x174;
    *(s32*)(m + 0x140) = in->ready;

    if (m[0x180] != 1) {
        w = D_00798CAC;

        if (xb_LiveObj_Count(w + 0x28) == 2) {
            xb_XLIVE_SIGNON_DropPlayer(xb_XLIVE_WORK_CLASS_Get2338(w));
        }

        a.v = (s32)&port;
        ((void (XB_FASTCALL*)(u8*, XB_ARG))xb_LiveAddr_GetPort)(from, a);
        a.v = (s32)&port;
        b.v = (s32)(m + 0x130);
        c.v = (s32)(m + 0x120);
        d.v = *(s32*)(m + 0x13C);
        e.v = *(s32*)(m + 0x140);
        ((void (XB_FASTCALL*)(u8*, XB_ARG, XB_ARG, XB_ARG, XB_ARG, XB_ARG))xb_XLIVE_SIGNON_AddPlayer)(xb_XLIVE_WORK_CLASS_Get2338(D_00798CAC), a, b, c, d, e);
        xb_xlive_match_Voice_F619B();
    }

    m[0x180] = in->kind;
}

void XB_FASTCALL xb_LiveObj_AddPeerTalker(u8* self, s32 edx, XB_KEY16 to, u16 user);
s32 xb_xlive_match_Voice_F56A8(void);
void xb_xlive_match_SetFlag10(void);
void xb_xlive_match_ClearFlag10(void);

/* xb_xlive_match_Voice_F619B 0x10BD1A: the peer (+0x144, user +0x13C)
 * added as a voice talker. */
void xb_xlive_match_Voice_F619B(void) {
    u8* m = xb_GetMatchInfo();
    XB_ARG a;

    a.v = *(u16*)(m + 0x13C);
    ((void (XB_FASTCALL*)(u8*, XB_KEY16, XB_ARG))xb_LiveObj_AddPeerTalker)(xb_LiveWork_Get2408(D_00798CAC), *(XB_KEY16*)(m + 0x144), a);
}

/* xb_xlive_match_VoiceCheck 0x10BE87: an acknowledgement (type 5, 4) to
 * the sender's port; the rest of the address is not set. Static: retail
 * passes from in ecx (config/sf33rd/static.txt). */
void xb_xlive_match_VoiceCheck(u8* from) {
    u32 tmp;
    u8 msg[4];
    struct {
        u32 a;
        u32 port;
        char b[8];
    } to;
    XB_ARG a;

    a.v = (s32)&tmp;
    to.port = *((u32* (XB_FASTCALL*)(u8*, XB_ARG))xb_LiveAddr_GetPort)(from, a);
    msg[0] = 5;
    msg[1] = 4;
    a.v = (s32)msg;
    ((s32 (XB_FASTCALL*)(u8*, XB_KEY16, XB_ARG))xb_LiveObj_SendVoice)(xb_LiveWork_Get2408(D_00798CAC), *(XB_KEY16*)&to, a);
}

/* xb_xlive_match_PeerVoiceB 0x10D470: this console's settings (type 4) sent
 * to the peer, the voice set up first (once, +0x17C). */
void xb_xlive_match_PeerVoiceB(void) {
    u8* m = xb_GetMatchInfo();
    XB_VCSETTINGS msg;
    XB_ARG a;

    msg.type = 4;
    memcpy(msg.key, m + 0xD4, 0x10);
    a.v = 0;
    msg.peer = *(XB_PEER12*)((u8* (XB_FASTCALL*)(u8*, XB_ARG))xb_deque_LiveObj_Subscript)(D_00798CAC + 0x28, a);
    msg.user = *(s32*)(D_00798CAC + 0x14);
    msg.v[0] = *(s32*)(m + 0x108);
    msg.v[1] = *(s32*)(m + 0x10C);
    msg.v[2] = *(s32*)(m + 0x110);
    msg.v[3] = *(s32*)(m + 0x114);
    msg.v[4] = *(s32*)(m + 0x118);
    msg.v[5] = *(s32*)(m + 0x11C);
    msg.c3 = m[0xC3];
    msg.side = m[0x170];
    msg.x174 = *(s32*)(m + 0x174);
    a.v = *(s32*)(D_00798CAC + 0x14);
    msg.ready = ((u8 (XB_FASTCALL*)(u8*, XB_ARG))xb_LiveObj_IsReady)(xb_LiveWork_Get2408(D_00798CAC), a);

    if (m[0x17C] == 0) {
        m[0x17C] = 1;
        xb_xlive_match_Voice_F56A8();
    }

    xb_xlive_match_Voice_F619B();
    a.v = (s32)&msg;
    ((s32 (XB_FASTCALL*)(u8*, XB_KEY16, XB_ARG))xb_LiveObj_SendVoice)(xb_LiveWork_Get2408(D_00798CAC), *(XB_KEY16*)(m + 0x144), a);
}

/* The ranking message (voice chat type 2) the host sends a guest. */
typedef struct {
    u8 type;
    u8 kind;
    u8 key[0x10];
    u8 pad12[2];
    XB_PEER12 peer;
    s32 user;
    s32 v[6];
    s32 gap;
    u8 ready;
    u8 pad41[3];
} XB_VCRANK;

/* xb_xlive_match_PeerEvent1 0x10E3B8: a guest gets the host's ranking
 * message. Kind 1 closes the match (the peer's voice dropped); otherwise
 * the first one sets up the host as a player (address +0x148, key, player,
 * user, stats, the points gap +0x178), sends this console's settings, and
 * later ones are acknowledged. */
void xb_xlive_match_PeerEvent1(u8* data, u8* from) {
    u8* m = xb_GetMatchInfo();
    XB_VCRANK* in = (XB_VCRANK*)data;
    XB_KEY16* key;
    XB_PEER12* peer;
    u32 it[2];
    u32 b[2];
    u32 e[2];
    u32 tmp;
    u32 port;
    u8* w;
    XB_ARG a;
    XB_ARG c;
    XB_ARG d;
    XB_ARG f;
    XB_ARG g;

    if (xb_xlive_match_IsGuest() == 0) {
        return;
    }

    if (in->kind == 1) {
        m[0x17E] = 0;
        xb_xlive_match_SetFlag10();
        a.v = (s32)it;
        ((void* (XB_FASTCALL*)(u8*, XB_ARG))xb_deque_LiveObj_Begin)(D_00798CAC + 0x28, a);

        for (;;) {
            a.v = (s32)e;
            a.v = (s32)((void* (XB_FASTCALL*)(u8*, XB_ARG))xb_deque_LiveObj_End)(D_00798CAC + 0x28, a);

            if ((u8)((s32 (XB_FASTCALL*)(void*, XB_ARG))xb_deque_iterator_ne)(it, a) == 0) {
                break;
            }

            a.v = (s32)b;
            a.v = (s32)((void* (XB_FASTCALL*)(u8*, XB_ARG))xb_deque_LiveObj_Begin)(D_00798CAC + 0x28, a);

            if ((u8)((s32 (XB_FASTCALL*)(void*, XB_ARG))xb_deque_iterator_ne)(it, a) != 0) {
                xb_xlive_match_Voice_F59B3(*xb_deque_DerefThunk(it));
                break;
            }

            xb_deque_iterator_inc(it);
        }

        w = D_00798CAC;

        if (xb_LiveObj_Count(w + 0x28) == 2) {
            xb_XLIVE_SIGNON_DropPlayer(xb_XLIVE_WORK_CLASS_Get2338(w));
        }

        return;
    }

    if (m[0x17E] != 0) {
        xb_xlive_match_VoiceCheck(from);
        return;
    }

    m[0x17E] = 1;
    a.v = (s32)&tmp;
    *(u32*)(m + 0x148) = *((u32* (XB_FASTCALL*)(u8*, XB_ARG))xb_LiveAddr_GetPort)(from, a);
    key = (XB_KEY16*)(m + 0x120);
    *key = *(XB_KEY16*)in->key;
    peer = (XB_PEER12*)(m + 0x130);
    *peer = in->peer;
    *(s32*)(m + 0x13C) = in->user;
    *(s32*)(m + 0x154) = in->v[0];
    *(s32*)(m + 0x158) = in->v[1];
    *(s32*)(m + 0x15C) = in->v[2];
    *(s32*)(m + 0x160) = in->v[3];
    *(s32*)(m + 0x164) = in->v[4];
    *(s32*)(m + 0x168) = in->v[5];
    *(s32*)(m + 0x178) = in->gap;
    *(s32*)(m + 0x140) = in->ready;
    w = D_00798CAC;

    if (xb_LiveObj_Count(w + 0x28) == 2) {
        xb_XLIVE_SIGNON_DropPlayer(xb_XLIVE_WORK_CLASS_Get2338(w));
    }

    a.v = (s32)&port;
    ((void (XB_FASTCALL*)(u8*, XB_ARG))xb_LiveAddr_GetPort)(from, a);
    a.v = (s32)&port;
    c.v = (s32)peer;
    d.v = (s32)key;
    f.v = *(s32*)(m + 0x13C);
    g.v = *(s32*)(m + 0x140);
    ((void (XB_FASTCALL*)(u8*, XB_ARG, XB_ARG, XB_ARG, XB_ARG, XB_ARG))xb_XLIVE_SIGNON_AddPlayer)(xb_XLIVE_WORK_CLASS_Get2338(D_00798CAC), a, c, d, f, g);
    xb_xlive_match_ClearFlag10();
    xb_xlive_match_PeerVoiceB();
}

s32 XB_FASTCALL xb_LiveObj_SetPeerAddr(u8* self, s32 edx, XB_KEY16 to);

/* xb_xlive_match_Voice_F56A8 0x10BCB9: the peer's address handed to the
 * voice object; +0x17D set if that failed. */
s32 xb_xlive_match_Voice_F56A8(void) {
    u8* m = xb_GetMatchInfo();

    m[0x17D] = 0;

    if (((s32 (XB_FASTCALL*)(u8*, XB_KEY16))xb_LiveObj_SetPeerAddr)(xb_LiveWork_Get2408(D_00798CAC), *(XB_KEY16*)(m + 0x144)) == 0) {
        m[0x17D] = 1;
    }

    return 0;
}

typedef unsigned short XB_WCHAR;
u32 wcslen(const XB_WCHAR* s);
u32 wcstombs(char* dst, const XB_WCHAR* src, u32 n);
s32 XB_STDCALL XOnlineMatchSessionFindFromID(XB_XNKID kid, void* ev, void* task);
void xb_xlive_match_LoadOwnStats(void);

/* xb_xlive_match_JoinFromID 0x10C31B: joining the session of a friend's
 * invitation (+0x190): the windows released, voice stopped, the timer
 * (+0xC8) at 600, the work to its joining states and the session looked up
 * by its id (task +0x100); an error is reported and the work's state set
 * to 11. A guest by invitation (+0x164 2) first converts its gamertag
 * (unused). */
void xb_xlive_match_JoinFromID(void) {
    char name[0x80];
    u8* m = xb_GetMatchInfo();
    s32 n;
    s32 hr;

    xb_xlive_match_ReleaseWindow();

    if (*(s32*)(D_00798CAC + 0x164) == 2) {
        n = wcslen((XB_WCHAR*)xb_xlive_match_GetAddr54(D_00798CAC + 0x5A4C));
        wcstombs(name, (XB_WCHAR*)xb_xlive_match_GetAddr54(D_00798CAC + 0x5A4C), n);
        name[n] = 0;
    }

    xb_xlive_match_Voice_F5B5F();
    *(u16*)(m + 0xC8) = 600;
    *(s32*)(D_00798CAC + 0x2368) = 2;
    *(s32*)(D_00798CAC + 0x236C) = 2;
    *(s32*)(D_00798CAC + 0x2370) = 0;
    xb_xlive_match_SetFlagC0();
    xb_xlive_match_LoadOwnStats();
    xb_xlive_match_SetFlag2();
    *(s32*)(D_00798CAC + 0x164) = 2;
    CXBOnlineTask_Close(D_00798CAC + 0x100);
    hr = XOnlineMatchSessionFindFromID(*(XB_XNKID*)(D_00798CAC + 0x190), 0,
                                       (void*)CXBOnlineTask_operator_addr(D_00798CAC + 0x100));

    if (hr < 0) {
        *(s32*)(D_00798CAC + 0x236C) = 0xB;
        *(s32*)(D_00798CAC + 0x2370) = 0;
        xb_xlive_main_SetMatchArgs(hr, D_002B5150, 0x308, 1);
    }
}

s32 XB_FASTCALL xb_XLIVE_STAT_CLASS_GetRank(u8* self);
s32 XB_FASTCALL xb_XLIVE_STAT_CLASS_GetLanguage(u8* self);

/* xb_xlive_match_LoadOwnStats 0x10C1EA: this console's gamertag (work
 * +0x64) and stats (from its stats page, +0x5090) into the match info for
 * the settings messages. */
void xb_xlive_match_LoadOwnStats(void) {
    u8* m = xb_GetMatchInfo();

    strcpy((char*)(m + 0xD4), (char*)(D_00798CAC + 0x64));
    *(s32*)(m + 0x108) = xb_XLIVE_STAT_CLASS_GetWins(D_00798CAC + 0x5090);
    *(s32*)(m + 0x10C) = xb_XLIVE_STAT_CLASS_GetMatches(D_00798CAC + 0x5090);
    *(s32*)(m + 0x114) = xb_XLIVE_STAT_CLASS_GetRank(D_00798CAC + 0x5090);
    *(s32*)(m + 0x110) = xb_XLIVE_STAT_CLASS_GetGrade(D_00798CAC + 0x5090);
    *(s32*)(m + 0x118) = xb_XLIVE_STAT_CLASS_GetPoint(D_00798CAC + 0x5090);
    *(s32*)(m + 0x11C) = xb_XLIVE_STAT_CLASS_GetLanguage(D_00798CAC + 0x5090);
}

int rand(void);
s32 XB_STDCALL XOnlineMatchSessionCreate(u32 pubCur, u32 pubAvail, u32 privCur, u32 privAvail, u32 nattr, void* attr,
                                         void* ev, void* task);

/* xb_xlive_match_CreateSession 0x10A9D6: a session hosted (task +0xFC)
 * with this console's 12 attributes: the gamertag (work +0x74), matches,
 * points, rank, grade, language, the match setting +0xC2, the language
 * again unless +0xC4, +0xC5, 1, the side and the user; the public slot is
 * left out for a private match (+0xC6). The match seed (+0x174) is new.
 * On an error the work goes to state 12. */
s32 xb_xlive_match_CreateSession(void) {
    u8* m = xb_GetMatchInfo();
    s32 i;
    u32 pub;
    s32 hr;

    *(s32*)(D_00798CAC + 0x236C) = 2;
    *(s32*)(D_00798CAC + 0x2370) = 2;
    memset(D_00798DA0, 0, sizeof(D_00798DA0));

    for (i = 0; i < 12; i++) {
        D_00798DA0[i].changed = 1;
    }

    *(s32*)(m + 0x174) = rand();
    m[0x170] = m[0xC2];
    m[0x171] = m[0xC3];
    pub = m[0xC6] == 0;
    D_00798DA0[0].id = 0x100001;
    D_00798DA0[1].id = 2;
    *(u8**)&D_00798DA0[0].value = D_00798CAC + 0x74;
    D_00798DA0[1].value = *(s32*)(m + 0x10C);
    D_00798DA0[2].id = 3;
    D_00798DA0[2].value = *(s32*)(m + 0x118);
    D_00798DA0[3].id = 4;
    D_00798DA0[3].value = *(s32*)(m + 0x114);
    D_00798DA0[4].id = 5;
    D_00798DA0[4].value = *(s32*)(m + 0x110);
    D_00798DA0[5].id = 6;
    D_00798DA0[5].value = *(s32*)(m + 0x11C);
    D_00798DA0[6].id = 7;
    D_00798DA0[6].value = (s8)m[0xC2];
    D_00798DA0[7].id = 8;

    if (m[0xC4] == 0) {
        D_00798DA0[7].value = *(s32*)(m + 0x11C);
    } else {
        D_00798DA0[7].value = 0;
    }

    D_00798DA0[8].id = 9;
    D_00798DA0[8].value = (s8)m[0xC5];
    D_00798DA0[9].id = 0xA;
    D_00798DA0[9].value = 1;
    D_00798DA0[10].id = 0xB;
    D_00798DA0[10].value = m[0x171];
    D_00798DA0[11].id = 0xC;
    D_00798DA0[11].value = *(s32*)(D_00798CAC + 8);
    CXBOnlineTask_Close(D_00798CAC + 0xFC);
    hr = XOnlineMatchSessionCreate(1, pub, 1, 1, 12, D_00798DA0, 0, (void*)CXBOnlineTask_operator_addr(D_00798CAC + 0xFC));

    for (i = 0; i < 12; i++) {
        D_00798DA0[i].changed = 0;
    }

    if (hr < 0) {
        *(s32*)(D_00798CAC + 0x236C) = 12;
        *(s32*)(D_00798CAC + 0x2370) = 0;
        return xb_xlive_main_SetMatchArgs(hr, D_002B5150, 0xAD9, 1);
    }

    return hr;
}

/* xb_xlive_match_VoicePeerLookup 0x10D2CA: with two players, voice ended
 * for the other (the sign-on's second player). */
void xb_xlive_match_VoicePeerLookup(void) {
    u8* d = D_00798CAC + 0x28;
    XB_ARG a;

    if (xb_LiveObj_Count(d) == 2) {
        a.v = 1;
        xb_xlive_match_VoicePeer(*((XB_PEER12* (XB_FASTCALL*)(u8*, XB_ARG))xb_deque_LiveObj_Subscript)(d, a));
    }
}

void xb_xlive_match_ClearRecordWork(void);

/* xb_XLIVE_WORK_CLASS_ResetMatch 0x10CFBB: the match info (xb_GetMatchInfo)
 * reset for a new match, with this console's two settings from the work
 * (its vtable +0x10 and +0x14), and matchmaking started: joining (mode
 * 2) or, when join is 0, hosting (mode 3); the own stats read. */
void XB_FASTCALL xb_XLIVE_WORK_CLASS_ResetMatch(u8* self, s32 edx, u8 join) {
    u8* m;

    (void)self;
    (void)edx;
    m = (u8*)xb_GetMatchInfo();
    memset(m + 0x17E, 0, 3);
    m[0xC1] = 0;
    m[0xC2] = ((u8 (XB_FASTCALL*)(u8*))(*(void***)D_00798CAC)[4])(D_00798CAC);
    m[0xC3] = ((u8 (XB_FASTCALL*)(u8*))(*(void***)D_00798CAC)[5])(D_00798CAC);
    m[0xC4] = 0;
    m[0xC5] = 0;
    m[0xC6] = 0;
    m[0xCA] = 0;
    m[0xC7] = 0;
    m[0x17C] = 0;
    m[0x17D] = 0;
    m[0xCB] = 0;

    if (join == 0) {
        *(s32*)(D_00798CAC + 0x2368) = 3;
        *(s32*)(D_00798CAC + 0x236C) = 1;
        *(s32*)(D_00798CAC + 0x2370) = 0;
        xb_xlive_match_ClearFlagC0();
    } else {
        *(s32*)(D_00798CAC + 0x2368) = 2;
        *(s32*)(D_00798CAC + 0x236C) = 1;
        *(s32*)(D_00798CAC + 0x2370) = 0;
        xb_xlive_match_SetFlagC0();
    }

    xb_xlive_match_LoadOwnStats();
    xb_xlive_match_SetFlag2();
}

/* xb_XLIVE_WORK_CLASS_Mode1Step 0x10D0DA (mode 1, quick match): a match
 * set up to join (with +0xCB set, a quick match), the record work
 * cleared and the searching message shown. */
s32 XB_FASTCALL xb_XLIVE_WORK_CLASS_Mode1Step(u8* self) {
    u8* m;
    XB_ARG a;

    m = (u8*)xb_GetMatchInfo();
    a.v = 1;
    ((void (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_WORK_CLASS_ResetMatch)(self, a);
    m[0xCB] = 1;
    *(s32*)(self + 0x2370) = 0;
    *(s32*)(self + 0x236C) = 1;
    self[0x274] = 0;
    xb_xlive_match_ClearRecordWork();
    a.v = 0;
    ((void (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_WORK_CLASS_ShowMessage)(self, a);
    xb_XLIVE_WORK_CLASS_Frame(self);
    return 0;
}

void XB_FASTCALL xb_XLIVE_WORK_CLASS_JoinUpdate_GetResults(u8* self);
void XB_FASTCALL xb_XLIVE_WORK_CLASS_JoinUpdate_Qos(u8* self);
void XB_FASTCALL xb_XLIVE_WORK_CLASS_JoinUpdate_State4(u8* self);
void XB_FASTCALL xb_XLIVE_WORK_CLASS_JoinUpdate_State5(u8* self);
void XB_FASTCALL xb_XLIVE_WORK_CLASS_JoinUpdate_State6(u8* self);
void XB_FASTCALL xb_XLIVE_WORK_CLASS_JoinUpdate_State7(u8* self);
void XB_FASTCALL xb_XLIVE_WORK_CLASS_JoinUpdate_State8(u8* self);
void XB_FASTCALL xb_XLIVE_WORK_CLASS_JoinUpdate_State9(u8* self);
void XB_FASTCALL xb_XLIVE_WORK_CLASS_JoinUpdate_State10(u8* self);
void XB_FASTCALL xb_XLIVE_WORK_CLASS_JoinUpdate_State11(u8* self);
void XB_FASTCALL xb_XLIVE_WORK_CLASS_JoinUpdate_State12(u8* self);
void XB_FASTCALL xb_XLIVE_WORK_CLASS_JoinUpdate_State13(u8* self);
void XB_FASTCALL xb_XLIVE_WORK_CLASS_JoinUpdate_State14(u8* self);
void XB_FASTCALL xb_XLIVE_WORK_CLASS_JoinUpdate_State15(u8* self);
void XB_FASTCALL xb_XLIVE_WORK_CLASS_JoinDraw_State0(u8* self);
void xb_XLIVE_WORK_CLASS_JoinDraw_State2(void);
void XB_FASTCALL xb_XLIVE_WORK_CLASS_JoinDraw_State3(u8* self);
void xb_XLIVE_WORK_CLASS_JoinDraw_State4(void);
void xb_XLIVE_WORK_CLASS_JoinDraw_State5(void);
void xb_XLIVE_WORK_CLASS_JoinDraw_State6(void);
void xb_XLIVE_WORK_CLASS_JoinDraw_State7(void);
void xb_xlive_match_DrawWaitMessage(void);
void xb_XLIVE_WORK_CLASS_JoinDraw_State10(void);
void xb_XLIVE_WORK_CLASS_JoinDraw_State14(void);

#define XB_VCALL(self_, i_) ((void (XB_FASTCALL*)(u8*))(*(void***)(self_))[(i_)])(self_)

/* xb_XLIVE_WORK_CLASS_JoinStep 0x10EF9F (mode 2): one step of joining
 * a match (the step +0x236C: the search set up and started by the work's
 * own methods, its results, the QoS probes, choosing and joining a
 * session, and the wait for the host), then, unless the work is busy,
 * the mode is gone or the match info hides it (+0x185), the step's
 * screen. */
s32 XB_FASTCALL xb_XLIVE_WORK_CLASS_JoinStep(u8* self) {
    u8* m = (u8*)xb_GetMatchInfo();

    switch (*(s32*)(self + 0x236C)) {
    case 0:
        XB_VCALL(self, 12);
        break;
    case 1:
        XB_VCALL(self, 13);
        break;
    case 2:
        xb_XLIVE_WORK_CLASS_JoinUpdate_GetResults(self);
        break;
    case 3:
        xb_XLIVE_WORK_CLASS_JoinUpdate_Qos(self);
        break;
    case 4:
        xb_XLIVE_WORK_CLASS_JoinUpdate_State4(self);
        break;
    case 5:
        xb_XLIVE_WORK_CLASS_JoinUpdate_State5(self);
        break;
    case 6:
        xb_XLIVE_WORK_CLASS_JoinUpdate_State6(self);
        break;
    case 7:
        xb_XLIVE_WORK_CLASS_JoinUpdate_State7(self);
        break;
    case 8:
        xb_XLIVE_WORK_CLASS_JoinUpdate_State8(self);
        break;
    case 9:
        xb_XLIVE_WORK_CLASS_JoinUpdate_State9(self);
        break;
    case 10:
        xb_XLIVE_WORK_CLASS_JoinUpdate_State10(self);
        break;
    case 11:
        xb_XLIVE_WORK_CLASS_JoinUpdate_State11(self);
        break;
    case 12:
        xb_XLIVE_WORK_CLASS_JoinUpdate_State12(self);
        break;
    case 13:
        xb_XLIVE_WORK_CLASS_JoinUpdate_State13(self);
        break;
    case 14:
        xb_XLIVE_WORK_CLASS_JoinUpdate_State14(self);
        break;
    case 15:
        xb_XLIVE_WORK_CLASS_JoinUpdate_State15(self);
        break;
    }

    if (xb_XLIVE_WORK_CLASS_Frame(self) != 0 || *(s32*)(self + 0x2368) == 0 || m[0x185] == 0) {
        return 0;
    }

    switch (*(s32*)(self + 0x236C)) {
    case 0:
        xb_XLIVE_WORK_CLASS_JoinDraw_State0(self);
        break;
    case 1:
        XB_VCALL(self, 9);
        break;
    case 2:
        xb_XLIVE_WORK_CLASS_JoinDraw_State2();
        break;
    case 3:
        xb_XLIVE_WORK_CLASS_JoinDraw_State3(self);
        break;
    case 4:
        xb_XLIVE_WORK_CLASS_JoinDraw_State4();
        break;
    case 5:
        xb_XLIVE_WORK_CLASS_JoinDraw_State5();
        break;
    case 6:
        xb_XLIVE_WORK_CLASS_JoinDraw_State6();
        break;
    case 7:
        xb_XLIVE_WORK_CLASS_JoinDraw_State7();
        break;
    case 8:
    case 9:
        xb_xlive_match_DrawWaitMessage();
        break;
    case 10:
        xb_XLIVE_WORK_CLASS_JoinDraw_State10();
        break;
    case 13:
        XB_VCALL(self, 8);
        break;
    case 14:
        xb_XLIVE_WORK_CLASS_JoinDraw_State14();
        break;
    }

    return 0;
}

void XB_FASTCALL xb_XLIVE_WORK_CLASS_HostUpdate_SessionCreated(u8* self);
void XB_FASTCALL xb_XLIVE_WORK_CLASS_HostUpdate_State3(u8* self);
void XB_FASTCALL xb_XLIVE_WORK_CLASS_HostUpdate_State4(u8* self);
void XB_FASTCALL xb_XLIVE_WORK_CLASS_HostUpdate_State5(u8* self);
void XB_FASTCALL xb_XLIVE_WORK_CLASS_HostUpdate_State6(u8* self);
void XB_FASTCALL xb_XLIVE_WORK_CLASS_HostUpdate_State7(u8* self);
void XB_FASTCALL xb_XLIVE_WORK_CLASS_HostUpdate_State8(u8* self);
void XB_FASTCALL xb_XLIVE_WORK_CLASS_HostUpdate_State9(u8* self);
void XB_FASTCALL xb_XLIVE_WORK_CLASS_HostUpdate_State10(u8* self);
void XB_FASTCALL xb_XLIVE_WORK_CLASS_HostUpdate_State11(u8* self);
void XB_FASTCALL xb_XLIVE_WORK_CLASS_HostUpdate_State12(u8* self);
void XB_FASTCALL xb_XLIVE_WORK_CLASS_HostUpdate_DeleteSession(u8* self);
void XB_FASTCALL xb_XLIVE_WORK_CLASS_HostUpdate_State14(u8* self);
void XB_FASTCALL xb_XLIVE_WORK_CLASS_HostDraw_State0(u8* self);
void XB_FASTCALL xb_XLIVE_WORK_CLASS_HostDraw_State2(u8* self);
void XB_FASTCALL xb_XLIVE_WORK_CLASS_HostDraw_State3(u8* self);
void xb_XLIVE_WORK_CLASS_HostDraw_State4(void);
void xb_XLIVE_WORK_CLASS_HostDraw_State5(void);
void xb_XLIVE_WORK_CLASS_HostDraw_State6(void);
void XB_FASTCALL xb_XLIVE_WORK_CLASS_HostDraw_State11(u8* self);
void xb_xlive_match_DrawNewChallenger(void);

/* xb_XLIVE_WORK_CLASS_HostStep 0x10E927 (mode 3): one step of hosting a
 * match (the step +0x236C: the session set up and created by the work's
 * own methods, then waiting for and taking a challenger, and deleting the
 * session), then, unless the work is busy or the mode is gone, the new
 * challenger banner and (unless hidden, +0x185) the step's screen. */
s32 XB_FASTCALL xb_XLIVE_WORK_CLASS_HostStep(u8* self) {
    u8* m = (u8*)xb_GetMatchInfo();

    switch (*(s32*)(self + 0x236C)) {
    case 0:
        XB_VCALL(self, 14);
        break;
    case 1:
        XB_VCALL(self, 15);
        break;
    case 2:
        xb_XLIVE_WORK_CLASS_HostUpdate_SessionCreated(self);
        break;
    case 3:
        xb_XLIVE_WORK_CLASS_HostUpdate_State3(self);
        break;
    case 4:
        xb_XLIVE_WORK_CLASS_HostUpdate_State4(self);
        break;
    case 5:
        xb_XLIVE_WORK_CLASS_HostUpdate_State5(self);
        break;
    case 6:
        xb_XLIVE_WORK_CLASS_HostUpdate_State6(self);
        break;
    case 7:
        xb_XLIVE_WORK_CLASS_HostUpdate_State7(self);
        break;
    case 8:
        xb_XLIVE_WORK_CLASS_HostUpdate_State8(self);
        break;
    case 9:
        xb_XLIVE_WORK_CLASS_HostUpdate_State9(self);
        break;
    case 10:
        xb_XLIVE_WORK_CLASS_HostUpdate_State10(self);
        break;
    case 11:
        xb_XLIVE_WORK_CLASS_HostUpdate_State11(self);
        break;
    case 12:
        xb_XLIVE_WORK_CLASS_HostUpdate_State12(self);
        break;
    case 13:
        xb_XLIVE_WORK_CLASS_HostUpdate_DeleteSession(self);
        break;
    case 14:
        xb_XLIVE_WORK_CLASS_HostUpdate_State14(self);
        break;
    }

    if (xb_XLIVE_WORK_CLASS_Frame(self) != 0 || *(s32*)(self + 0x2368) == 0) {
        return 0;
    }

    xb_xlive_match_DrawNewChallenger();

    if (m[0x185] == 0) {
        return 0;
    }

    switch (*(s32*)(self + 0x236C)) {
    case 0:
        xb_XLIVE_WORK_CLASS_HostDraw_State0(self);
        break;
    case 1:
        XB_VCALL(self, 10);
        break;
    case 2:
        xb_XLIVE_WORK_CLASS_HostDraw_State2(self);
        break;
    case 3:
        xb_XLIVE_WORK_CLASS_HostDraw_State3(self);
        break;
    case 4:
        xb_XLIVE_WORK_CLASS_HostDraw_State4();
        break;
    case 5:
        xb_XLIVE_WORK_CLASS_HostDraw_State5();
        break;
    case 6:
        xb_XLIVE_WORK_CLASS_HostDraw_State6();
        break;
    case 8:
    case 9:
    case 10:
        xb_xlive_match_DrawWaitMessage();
        break;
    case 11:
        xb_XLIVE_WORK_CLASS_HostDraw_State11(self);
        break;
    }

    return 0;
}

s32 xb_xlive_StartMatchSearch1(s64 v0, s64 v1, s64 v2, s64 v3, s64 v4, s64 v5, s64 v6, s64 v7, s64 v8, s64 v9,
                               s64 v10, s64 v11, s64 v12, s64 v13, void* ev, void* task);
s32 xb_xlive_StartMatchSearch2(s64 v0, s64 v1, s64 v2, s64 v3, s64 v4, s64 v5, s64 v6, s64 v7, s64 v8, s64 v9,
                               s64 v10, s64 v11, s64 v12, s64 v13, void* ev, void* task);
s32 xb_xlive_StartMatchSearch3(s64 v0, s64 v1, s64 v2, s64 v3, s64 v4, s64 v5, s64 v6, s64 v7, s64 v8, s64 v9,
                               s64 v10, s64 v11, s64 v12, s64 v13, void* ev, void* task);
s32 xb_xlive_StartMatchSearch4(s64 v0, s64 v1, s64 v2, s64 v3, s64 v4, s64 v5, s64 v6, s64 v7, s64 v8, s64 v9,
                               s64 v10, s64 v11, s64 v12, s64 v13, void* ev, void* task);

#define XB_MS_ANY 0x7FFFFFFFFFFFFFFF
#define XB_MS_CALL(fn_) \
    fn_(user, XB_MS_ANY, XB_MS_ANY, XB_MS_ANY, XB_MS_ANY, XB_MS_ANY, XB_MS_ANY, XB_MS_ANY, XB_MS_ANY, rounds, c3, c4, \
        time, XB_MS_ANY, 0, (void*)CXBOnlineTask_operator_addr(D_00798CAC + 0x100))

/* xb_xlive_match_BeginSearch 0x10A017: the join search started (step 2,
 * the timeout +0xC8 ten seconds): a quick match (+0xCB) searches on the
 * user and setting C4 only, else on the settings too (the time unless
 * any). The retry (+0xCA, 0 to 3) picks the search procedure (3, 4, 1,
 * 2). An error ends the join (step 11). */
void XB_FASTCALL xb_xlive_match_BeginSearch(u8* self) {
    u8* m;
    s64 user;
    s64 rounds;
    s64 c3;
    s64 c4;
    s64 time;
    s32 hr;

    (void)self;
    m = (u8*)xb_GetMatchInfo();
    *(s32*)(D_00798CAC + 0x236C) = 2;
    *(s32*)(D_00798CAC + 0x2370) = 0;
    *(u16*)(m + 0xC8) = 0x258;
    user = *(s32*)(D_00798CAC + 8);
    rounds = XB_MS_ANY;
    c3 = XB_MS_ANY;
    time = XB_MS_ANY;

    if (m[0xCB] == 1) {
        c4 = m[0xC4] == 0 ? *(s32*)(m + 0x11C) : 0;
    } else {
        rounds = (s8)m[0xC2];
        c3 = (s8)m[0xC3];
        c4 = m[0xC4] == 0 ? *(s32*)(m + 0x11C) : 0;

        if (m[0xC5] != 2) {
            time = (s8)m[0xC5];
        }
    }

    switch (m[0xCA]) {
    case 0:
        hr = XB_MS_CALL(xb_xlive_StartMatchSearch3);
        break;
    case 1:
        hr = XB_MS_CALL(xb_xlive_StartMatchSearch4);
        break;
    case 2:
        hr = XB_MS_CALL(xb_xlive_StartMatchSearch1);
        break;
    case 3:
        hr = XB_MS_CALL(xb_xlive_StartMatchSearch2);
        break;
    default:
        return;
    }

    if (hr < 0) {
        *(s32*)(D_00798CAC + 0x236C) = 0xB;
        *(s32*)(D_00798CAC + 0x2370) = 0;
        xb_xlive_main_SetMatchArgs(hr, D_002B5150, 0x29A, 1);
    }
}

s32 xb_LivePadAccept(void);
void XB_FASTCALL xb_XLIVE_WORK_CLASS_SetState4(u8* self);
extern char D_0025CCA0[];
void xb_xlive_match_ResetPeer(void);
void xb_xlive_match_ConnectPeer(void);
s32 XB_FASTCALL xb_XLIVE_WORK_CLASS_LoadPeerStats(u8* self, s32 edx, s32 join);

/* xb_XLIVE_WORK_CLASS_JoinUpdate_State6 0x10C4A6: no session was found:
 * the message for four seconds (or until A, when the match info's +0x180
 * is 4); then back to the settings (step 1), or out of a quick match. */
void XB_FASTCALL xb_XLIVE_WORK_CLASS_JoinUpdate_State6(u8* self) {
    u8* m = (u8*)xb_GetMatchInfo();

    switch (*(s32*)(self + 0x2370)) {
    case 0:
        *(s32*)(self + 0x2370) = 1;
        *(s32*)(self + 0x23B4) = 0x78;
        xb_SeSelectedThunk();
        xb_xlive_match_OpenWindow(2, m + 0x184);
        /* fallthrough */
    case 1:
        if (xb_xlive_match_AreWindowsDone() == 0) {
            return;
        }

        (*(s32*)(self + 0x2370))++;
        /* fallthrough */
    case 2:
        if (m[0x180] == 4) {
            if (xb_LivePadAccept() == 0) {
                return;
            }
        } else if (--*(s32*)(self + 0x23B4) >= 0) {
            return;
        }

        (*(s32*)(self + 0x2370))++;
        return;
    case 3:
        if (m[0xCB] == 0) {
            *(s32*)(self + 0x236C) = 1;
            *(s32*)(self + 0x2370) = 0;
            xb_xlive_match_ReleaseWindow();
        } else {
            xb_xlive_match_SetJoinState15();
        }

        xb_xlive_match_ResetPeer();
        return;
    }
}

/* xb_XLIVE_WORK_CLASS_JoinUpdate_State7 0x10C554: the session could not
 * be joined: the message for eight seconds, then the search again (or
 * out of a quick match). */
void XB_FASTCALL xb_XLIVE_WORK_CLASS_JoinUpdate_State7(u8* self) {
    u8* m = (u8*)xb_GetMatchInfo();

    switch (*(s32*)(self + 0x2370)) {
    case 0:
        *(s32*)(self + 0x2370) = 1;
        *(s32*)(self + 0x23B4) = 0xF0;
        xb_SeSelectedThunk();
        xb_xlive_match_OpenWindow(2, m + 0x184);
        /* fallthrough */
    case 1:
        if (xb_xlive_match_AreWindowsDone() == 0) {
            return;
        }

        (*(s32*)(self + 0x2370))++;
        /* fallthrough */
    case 2:
        if (--*(s32*)(self + 0x23B4) >= 0) {
            return;
        }

        if (m[0xCB] == 0) {
            xb_xlive_match_ReleaseWindow();
            xb_xlive_match_BeginSearch(self);
        } else {
            xb_xlive_match_SetJoinState15();
        }

        return;
    }
}

/* xb_XLIVE_WORK_CLASS_JoinUpdate_State8 0x10C5D3: a session joined: the
 * versus windows opened and the opponent's stats read; then connect to
 * the host (an error: state 4). */
void XB_FASTCALL xb_XLIVE_WORK_CLASS_JoinUpdate_State8(u8* self) {
    u8* m = (u8*)xb_GetMatchInfo();
    s32 r;
    XB_ARG a;

    switch (*(s32*)(self + 0x2370)) {
    case 0:
        *(s32*)(self + 0x2370) = 1;
        xb_xlive_match_OpenWindow(4, m + 0x184);
        xb_xlive_match_OpenWindow(5, m + 0x190);
        xb_xlive_match_OpenWindow(6, m + 0x19C);
        return;
    case 1:
        if (xb_xlive_match_AreWindowsDone() == 0) {
            return;
        }

        (*(s32*)(self + 0x2370))++;
        *(s32*)(self + 0x2374) = 0;
        /* fallthrough */
    case 2:
        a.v = 1;
        r = ((s32 (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_WORK_CLASS_LoadPeerStats)(self, a);

        if (r == -1) {
            xb_XLIVE_WORK_CLASS_SetState4(self);
        } else if (r == 1) {
            xb_xlive_match_ConnectPeer();
        } else if (r != 0) {
            _assert(D_0025CCA0, D_002B5150, 0x683);
        }

        return;
    }
}

s32 xb_xlive_match_StepLink(void);
s32 xb_xlive_net_Close(void);
s32 xb_xlive_net_IsLinkUp(void);
s32 XB_FASTCALL xb_XLIVE_SIGNON_DropPlayer(u8* self);
u8* XB_FASTCALL xb_XLIVE_WORK_CLASS_Get2338(u8* self);
void xb_xlive_match_Voice_F5B5F(void);
void XB_FASTCALL xb_xlive_match_ResetConnection(u8* self, s32 edx, s32 rejoin);
void xb_xlive_main_HideWin(void);
void XB_FASTCALL xb_CONNECT_USER_CLASS_Release(u8* self);
void xb_xlive_disp_ReleaseOlder(f32 z);
void xb_xlive_match_DrawStatus(void);
s32 xb_xlive_main_SetErrorArgs(s32 hr, const char* file, s32 line, s32 fatal);
s32 xb_LivePadBack(void);
s32 xb_LivePadTrigger(s32 mask);
void xb_LiveWork_EndError(void);
void XB_FASTCALL xb_XLIVE_WORK_CLASS_SetState3(u8* self);
s32 XB_FASTCALL xb_XLIVE_WORK_CLASS_SaveResult(u8* self);

#define XB_RESET_CONNECTION(v_) (a.v = (v_), ((void (XB_FASTCALL*)(u8*, XB_ARG))xb_xlive_match_ResetConnection)(self, a))

/* xb_XLIVE_WORK_CLASS_JoinUpdate_State9 0x10C688: the link to the host
 * brought up (its progress shown); once up the windows are released for
 * the match. A failure drops the link and the player and ends with error
 * 13 (step 12). */
void XB_FASTCALL xb_XLIVE_WORK_CLASS_JoinUpdate_State9(u8* self) {
    XB_ARG a;

    switch (*(s32*)(self + 0x2370)) {
    case 0:
        if (xb_xlive_match_StepLink()) {
            (*(s32*)(self + 0x2370))++;
            xb_xlive_net_Close();
            xb_XLIVE_SIGNON_DropPlayer(xb_XLIVE_WORK_CLASS_Get2338(D_00798CAC));
            xb_xlive_match_Voice_F5B5F();
            XB_RESET_CONNECTION(1);
            xb_xlive_match_ReleaseWindow();
            return;
        }

        if (xb_xlive_net_IsLinkUp()) {
            xb_xlive_match_ClearRecordWork();
            xb_xlive_main_HideWin();
            xb_CONNECT_USER_CLASS_Release(D_00798CAC + 0x59E0);
            xb_xlive_disp_ReleaseOlder(1.0f);
            return;
        }

        xb_xlive_match_DrawStatus();
        return;
    case 1:
        *(s32*)(self + 0x2370) = 0;
        *(s32*)(self + 0x236C) = 0xC;
        xb_xlive_main_SetErrorArgs(0xD, D_002B5150, 0x6BD, 1);
        return;
    }
}

/* xb_XLIVE_WORK_CLASS_JoinUpdate_State10 0x10C736: waiting for the host
 * to accept: the search again every ten seconds (+0xC8) and on the left
 * trigger, B back to the settings (except in a match from an invitation,
 * +0xCB 2). */
void XB_FASTCALL xb_XLIVE_WORK_CLASS_JoinUpdate_State10(u8* self) {
    u8* m = (u8*)xb_GetMatchInfo();

    if (m[0xCB] != 2) {
        if (--*(s16*)(m + 0xC8) < 0) {
            *(u16*)(m + 0xC8) = 0x258;
            xb_xlive_match_BeginSearch(self);
            return;
        }
    }

    if (xb_LivePadBack()) {
        xb_SeSelectedThunk();

        if (m[0xCB] != 2) {
            *(s32*)(self + 0x2370) = 0;
            *(s32*)(self + 0x236C) = 1;
            xb_xlive_match_ReleaseWindow();
        } else {
            xb_xlive_match_SetJoinState15();
        }

        return;
    }

    if (xb_LivePadTrigger(0x100) && m[0xCB] != 2) {
        xb_SeSelectedThunk();
        xb_xlive_match_BeginSearch(self);
    }
}

/* xb_XLIVE_WORK_CLASS_JoinUpdate_State11 0x10C7C1: an error: A ends it,
 * the connection reset, and the error state. */
void XB_FASTCALL xb_XLIVE_WORK_CLASS_JoinUpdate_State11(u8* self) {
    XB_ARG a;

    if (xb_LivePadAccept()) {
        xb_SeSelectedThunk();
        xb_xlive_match_ClearRecordWork();
        XB_RESET_CONNECTION(0);
        xb_LiveWork_EndError();
        xb_XLIVE_WORK_CLASS_SetState3(D_00798CAC);
    }
}

/* xb_XLIVE_WORK_CLASS_JoinUpdate_State12 0x10C7F3: a lost link: A saves
 * the match's result (the voice stopped), then leaves the join. */
void XB_FASTCALL xb_XLIVE_WORK_CLASS_JoinUpdate_State12(u8* self) {
    s32 r;

    switch (*(s32*)(self + 0x2370)) {
    case 0:
        if (xb_LivePadAccept()) {
            (*(s32*)(self + 0x2370))++;
            *(s32*)(self + 0x2374) = 0;
            xb_SeSelectedThunk();
            xb_xlive_match_Voice_F5B5F();
        }

        return;
    case 1:
        r = xb_XLIVE_WORK_CLASS_SaveResult(self);

        if (r == -1) {
            xb_XLIVE_WORK_CLASS_SetState4(self);
        } else if (r == 1) {
            xb_LiveWork_EndError();
            xb_xlive_match_SetJoinState15();
        } else if (r != 0) {
            _assert(D_0025CCA0, D_002B5150, 0x736);
        }

        return;
    default:
        _assert(D_0025CCA0, D_002B5150, 0x73C);
        return;
    }
}

/* xb_XLIVE_WORK_CLASS_JoinUpdate_State14 0x10C894: a message until B,
 * which leaves the join. */
void XB_FASTCALL xb_XLIVE_WORK_CLASS_JoinUpdate_State14(u8* self) {
    u8* m = (u8*)xb_GetMatchInfo();
    XB_ARG a;

    switch (*(s32*)(self + 0x2370)) {
    case 0:
        *(s32*)(self + 0x2370) = 1;
        xb_xlive_match_OpenWindow(2, m + 0x184);
        return;
    case 1:
        if (xb_xlive_match_AreWindowsDone()) {
            (*(s32*)(self + 0x2370))++;
        }

        return;
    case 2:
        if (xb_LivePadBack()) {
            xb_xlive_match_SetJoinState15();
            XB_RESET_CONNECTION(0);
            xb_SeSelectedThunk();
        }

        return;
    }
}

void xb_xlive_match_ClearFlag10(void);
void xb_xlive_match_ClearFlag2(void);
void xb_xlive_match_UnregisterKey(void);
void XB_FASTCALL xb_XLIVE_WORK_CLASS_CloseMatchTasks(u8* self);
void xb_LiveSet79A170(s32 v);
s32 xb_xlive_match_IsGuest(void);
void xb_ClearRebattleWork(void);
void xb_xlive_ClearPeers(void);
void xb_xlive_SetPeer0(const char* name, s32 a, s32 b, s32 c, s32 d, u8 e);
void xb_xlive_SetPeer1(const char* name, s32 a, s32 b, s32 c, s32 d, u8 e);
s32 xb_xlive_net_Setup(s32 client, s32 me, u32* addr, s32 key);
u8* XB_FASTCALL xb_LivePkt_GetData(u8* pkt);
u8* XB_FASTCALL xb_xlive_match_GetAddr0C(u8* self);
s32 XB_STDCALL XNetXnAddrToInAddr(const void* xna, const void* xnkid, u32* ina);

/* xb_xlive_match_ResetConnection 0x10C052: the session's flags cleared,
 * its tasks (+0xFC, +0x100, +0x108) closed, the QoS listening restarted
 * if it was on (+0xD0), and the session key unregistered. The argument
 * is unused. */
void XB_FASTCALL xb_xlive_match_ResetConnection(u8* self, s32 edx, s32 rejoin) {
    (void)edx;
    (void)rejoin;
    xb_xlive_match_ClearFlag10();
    xb_xlive_match_ClearFlag2();
    CXBOnlineTask_Close(self + 0xFC);
    CXBOnlineTask_Close(self + 0x100);
    CXBOnlineTask_Close(self + 0x108);

    if (*(s32*)(self + 0xD0) != 0) {
        xb_XLIVE_WORK_CLASS_RestartQos(self);
    }

    xb_xlive_match_UnregisterKey();
}

/* xb_xlive_match_ConnectPeer 0x10C099: the match agreed: the match
 * tasks closed, the link set up (the host listens, step 10; the client
 * connects to the host's address, from the session record +0x5A4C, step
 * 9; no address is error 17), the two players' records set from the
 * match info, and the work's own set-up (vtable +0xC). */
void xb_xlive_match_ConnectPeer(void) {
    u8* m;
    s32 client;
    s32 me;
    u32 ina;
    u8* rec;

    m = (u8*)xb_GetMatchInfo();
    xb_XLIVE_WORK_CLASS_CloseMatchTasks(D_00798CAC);
    xb_XLIVE_WORK_CLASS_RestartQos(D_00798CAC);
    xb_LiveSet79A170(1);

    if (xb_xlive_match_IsGuest()) {
        *(s32*)(D_00798CAC + 0x236C) = 0xA;
        *(s32*)(D_00798CAC + 0x2370) = 0;
        client = 0;
        me = 0;
        ina = 0;
    } else {
        *(s32*)(D_00798CAC + 0x236C) = 9;
        *(s32*)(D_00798CAC + 0x2370) = 0;
        client = 1;
        me = 1;
        rec = D_00798CAC + 0x5A4C;

        if (XNetXnAddrToInAddr(xb_xlive_match_GetAddr0C(rec), xb_LivePkt_GetData(rec), &ina) != 0) {
            *(s32*)(D_00798CAC + 0x236C) = 0xB;
            *(s32*)(D_00798CAC + 0x2370) = 0;
            xb_xlive_main_SetErrorArgs(0x11, D_002B5150, 0x138E, 1);
            return;
        }
    }

    xb_ClearRebattleWork();
    xb_xlive_ClearPeers();
    xb_xlive_SetPeer0((char*)(m + 0xD4), *(s32*)(m + 0x10C), *(s32*)(m + 0x108), 0, 0, *(u8*)(m + 0x110));
    xb_xlive_SetPeer1((char*)(m + 0x120), *(s32*)(m + 0x158), *(s32*)(m + 0x154), 0, 0, *(u8*)(m + 0x15C));
    XB_VCALL(D_00798CAC, 3);
    xb_xlive_net_Setup(client, me, &ina, *(s32*)(m + 0x174));
}

/* The new-challenger banner's x (D_00798E6C) and colour step
 * (D_00798E64, through the colours D_003F8348). */
extern s32 D_00798E6C;
extern s32 D_00798E64;
extern s32 D_003F8348[];
extern f32 D_002190E8;
extern f32 D_00219420;
extern char D_002B5354[];
extern f32 D_002B5374;

/* xb_xlive_match_DrawNewChallenger 0x10ADBB: while hosting with a
 * challenger in (+0x17E), the "new challenger" banner scrolling right to
 * left in changing colours. */
void xb_xlive_match_DrawNewChallenger(void) {
    u8* m = (u8*)xb_GetMatchInfo();

    if (*(s32*)(D_00798CAC + 0x236C) != 3 || *(s32*)(D_00798CAC + 0x2370) < 3) {
        return;
    }

    if (m[0x17E] == 0) {
        D_00798E6C = 0x280;
        return;
    }

    D_00798E6C -= 2;

    if (D_00798E6C < -0x118) {
        D_00798E6C = 0x280;
    }

    if (++D_00798E64 > 6) {
        D_00798E64 = 0;
    }

    xb_xlive_disp_DrawTextBox(D_00798E6C + D_002190E8, D_00219420, D_0025F370, (s32)D_002B5354, 1.0f,
                              D_003F8348[D_00798E64]);
}

/* xb_XLIVE_WORK_CLASS_JoinDraw_State4 0x10B6D1: the join's QoS screen
 * (sub-step 3): by the match info's +0x180, the ranking table with its
 * messages, or the no-match message. */
void xb_XLIVE_WORK_CLASS_JoinDraw_State4(void) {
    u8* m = (u8*)xb_GetMatchInfo();
    s8 c;

    if (*(s32*)(D_00798CAC + 0x2370) != 3) {
        return;
    }

    c = m[0x180];

    if (c < 0) {
        return;
    }

    if (c <= 1) {
        xb_xlive_match_DrawRankingTable();
        xb_xlive_match_DrawBlinkMessage(3, 0x3C, 0);

        if (m[0x17D] == 1) {
            xb_xlive_disp_DrawMessageDefault(3, 0x3D, 0);
        }

        xb_xlive_disp_DrawMessage(3, 0x5D, 0, D_0025F370, 1.0f, 4);
    } else if (c == 2) {
        xb_xlive_disp_DrawMessageDefault(3, 0x3E, 0);
    }
}

/* xb_XLIVE_WORK_CLASS_JoinDraw_State10 0x10A59E: waiting for the host
 * (an invited match has its own message). */
void xb_XLIVE_WORK_CLASS_JoinDraw_State10(void) {
    if (((u8*)xb_GetMatchInfo())[0xCB] == 2) {
        xb_xlive_disp_DrawMessageDefault(3, 0x60, 0);
        xb_xlive_disp_DrawMessage(3, 0x5A, 0, D_0025F370, 1.0f, 4);
    } else {
        xb_xlive_disp_DrawMessageDefault(3, 0x17, 0);
        xb_xlive_disp_DrawMessage(3, 0x51, 0, D_0025F370, 1.0f, 4);
    }
}

/* xb_XLIVE_WORK_CLASS_HostDraw_State6 0x10AE8D: the challenger's name
 * (+0x120) with its messages (sub-step 2). */
void xb_XLIVE_WORK_CLASS_HostDraw_State6(void) {
    u8* m = (u8*)xb_GetMatchInfo();

    if (*(s32*)(D_00798CAC + 0x2370) != 2) {
        return;
    }

    xb_xlive_disp_DrawMessageDefault(3, 0x4A, 0);
    xb_xlive_disp_DrawBox20(0.0f, D_002B5374, D_0025F370, (s32)(m + 0x120), 1.0f, 7, 0);
    xb_xlive_disp_DrawMessageDefault(3, 0x4E, 0);
}

void xb_xlive_match_StartUpdateSession(void);
s32 XB_FASTCALL xb_XLIVE_WORK_CLASS_ContinueTask108(u8* self);
s32 XB_FASTCALL xb_xlive_match_DeleteSession(u8* self, s32 edx, s32 quiet);

#define XB_DELETE_SESSION(q_) (a.v = (q_), ((s32 (XB_FASTCALL*)(u8*, XB_ARG))xb_xlive_match_DeleteSession)(self, a))

/* xb_XLIVE_WORK_CLASS_HostUpdate_State7 0x10B9E1: the session's update
 * (task +0xFC) polled; done: the next update started. An error ends the
 * host (step 13). */
void XB_FASTCALL xb_XLIVE_WORK_CLASS_HostUpdate_State7(u8* self) {
    s32 hr = CXBOnlineTask_Continue(self + 0xFC);

    if (hr == 0) {
        return;
    }

    if (hr >= 0) {
        xb_xlive_match_StartUpdateSession();
        return;
    }

    *(s32*)(self + 0x2370) = 0;
    *(s32*)(self + 0x236C) = 0xD;
    xb_xlive_main_SetMatchArgs(hr, D_002B5150, 0xDF9, 1);
}

/* xb_XLIVE_WORK_CLASS_HostUpdate_State9 0x10CC7D: a challenger taken:
 * the session deleted (quietly), then connect to them. An error ends the
 * host (step 14). */
void XB_FASTCALL xb_XLIVE_WORK_CLASS_HostUpdate_State9(u8* self) {
    s32 hr;
    s32 line;
    XB_ARG a;

    switch (*(s32*)(self + 0x2370)) {
    case 0:
        *(s32*)(self + 0x2370) = 1;
        hr = XB_DELETE_SESSION(1);

        if (hr >= 0) {
            return;
        }

        line = 0xE50;
        break;
    case 1:
        hr = xb_XLIVE_WORK_CLASS_ContinueTask108(self);

        if (hr == 0) {
            return;
        }

        if (hr >= 0) {
            xb_xlive_match_ConnectPeer();
            return;
        }

        line = 0xE62;
        break;
    default:
        return;
    }

    *(s32*)(self + 0x2370) = 0;
    *(s32*)(self + 0x236C) = 0xE;
    xb_xlive_main_SetMatchArgs(hr, D_002B5150, line, 1);
}

/* xb_XLIVE_WORK_CLASS_HostUpdate_State12 0x10CE8D: an error: A ends it,
 * the connection reset, and the error state. */
void XB_FASTCALL xb_XLIVE_WORK_CLASS_HostUpdate_State12(u8* self) {
    XB_ARG a;

    if (xb_LivePadAccept()) {
        xb_SeSelectedThunk();
        XB_RESET_CONNECTION(0);
        xb_LiveWork_EndError();
        xb_xlive_match_ClearRecordWork();
        xb_XLIVE_WORK_CLASS_SetState3(D_00798CAC);
    }
}

/* xb_XLIVE_WORK_CLASS_HostUpdate_DeleteSession 0x10BA23 (step 13): the
 * session deleted, then the error step (12). */
void XB_FASTCALL xb_XLIVE_WORK_CLASS_HostUpdate_DeleteSession(u8* self) {
    s32 hr;
    XB_ARG a;

    switch (*(s32*)(self + 0x2370)) {
    case 0:
        *(s32*)(self + 0x2370) = 1;
        XB_DELETE_SESSION(0);
        return;
    case 1:
        hr = xb_XLIVE_WORK_CLASS_ContinueTask108(self);

        if (hr == 0) {
            return;
        }

        if (hr >= 0) {
            (*(s32*)(self + 0x2370))++;
            return;
        }

        *(s32*)(self + 0x2370) = 0;
        *(s32*)(self + 0x236C) = 0xC;
        xb_xlive_main_SetMatchArgs(hr, D_002B5150, 0xF39, 1);
        return;
    case 2:
        *(s32*)(self + 0x2370) = 0;
        *(s32*)(self + 0x236C) = 0xC;
        return;
    }
}

/* xb_XLIVE_WORK_CLASS_HostUpdate_State14 0x10D2FF: a lost link: A ends
 * the voice with the challenger and saves the result, then leaves. */
void XB_FASTCALL xb_XLIVE_WORK_CLASS_HostUpdate_State14(u8* self) {
    s32 r;
    XB_ARG a;

    switch (*(s32*)(self + 0x2370)) {
    case 0:
        if (xb_LivePadAccept()) {
            (*(s32*)(self + 0x2370))++;
            *(s32*)(self + 0x2374) = 0;
            xb_SeSelectedThunk();
            a.v = 1;
            xb_xlive_match_VoicePeer(*((XB_PEER12* (XB_FASTCALL*)(u8*, XB_ARG))xb_deque_LiveObj_Subscript)(self + 0x28, a));
            xb_xlive_match_Voice_F5B5F();
        }

        return;
    case 1:
        r = xb_XLIVE_WORK_CLASS_SaveResult(self);

        if (r == -1) {
            xb_XLIVE_WORK_CLASS_SetState4(self);
        } else if (r == 1) {
            xb_LiveWork_EndError();
            xb_xlive_match_SetJoinState15();
        } else if (r != 0) {
            _assert(D_0025CCA0, D_002B5150, 0xF70);
        }

        return;
    default:
        _assert(D_0025CCA0, D_002B5150, 0xF76);
        return;
    }
}

void xb_xlive_match_JoinFromID(void);
void xb_xlive_match_ReopenWindow(s32 a, u8* w);
s32 xb_xlive_match_IsWindowDone(u8* w);

/* xb_XLIVE_WORK_CLASS_HostUpdate_State11 0x10CCE7: the host given up:
 * the session deleted (loudly), the connection reset, then by the
 * match's kind (+0xCB): back to the settings, out of a quick match, or
 * joining the inviter. An error goes to step 12. */
void XB_FASTCALL xb_XLIVE_WORK_CLASS_HostUpdate_State11(u8* self) {
    u8* m = (u8*)xb_GetMatchInfo();
    s32 hr;
    XB_ARG a;

    switch (*(s32*)(self + 0x2370)) {
    case 0:
        *(s32*)(self + 0x2370) = 1;
        *(s32*)(self + 0x3E0) = 0;
        XB_DELETE_SESSION(0);
        return;
    case 1:
        hr = xb_XLIVE_WORK_CLASS_ContinueTask108(self);

        if (hr == 0) {
            return;
        }

        if (hr < 0) {
            *(s32*)(self + 0x236C) = 0xC;
            *(s32*)(self + 0x2370) = 0;
            xb_xlive_main_SetMatchArgs(hr, D_002B5150, 0xE8A, 1);
            return;
        }

        XB_RESET_CONNECTION(0);

        switch (m[0xCB]) {
        case 0:
            *(s32*)(self + 0x236C) = 1;
            *(s32*)(self + 0x2370) = 0;
            return;
        case 1:
            xb_xlive_match_SetJoinState15();
            return;
        case 2:
            xb_xlive_match_JoinFromID();
            return;
        }

        return;
    }
}

/* xb_XLIVE_WORK_CLASS_HostUpdate_State8 0x10ACEA: a challenger: the
 * versus windows, the challenger's stats read (as the host), then take
 * them (step 9). */
void XB_FASTCALL xb_XLIVE_WORK_CLASS_HostUpdate_State8(u8* self) {
    u8* m = (u8*)xb_GetMatchInfo();
    s32 r;
    XB_ARG a;

    switch (*(s32*)(self + 0x2370)) {
    case 0:
        *(s32*)(self + 0x2370) = 1;
        xb_xlive_match_OpenWindow(4, m + 0x184);
        xb_xlive_match_OpenWindow(5, m + 0x190);
        xb_xlive_match_OpenWindow(6, m + 0x19C);
        return;
    case 1:
        if (xb_xlive_match_AreWindowsDone() == 0) {
            return;
        }

        (*(s32*)(self + 0x2370))++;
        *(s32*)(self + 0x2374) = 0;
        /* fallthrough */
    case 2:
        a.v = 1;
        r = ((s32 (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_WORK_CLASS_LoadPeerStats)(self, a);

        if (r == -1) {
            xb_XLIVE_WORK_CLASS_SetState4(self);
        } else if (r == 1) {
            *(s32*)(self + 0x2370) = 0;
            *(s32*)(self + 0x236C) = 9;
        } else if (r != 0) {
            _assert(D_0025CCA0, D_002B5150, 0xE32);
        }

        return;
    }
}

/* xb_XLIVE_WORK_CLASS_HostUpdate_State6 0x10B905: a challenger left:
 * the message for four seconds, then the settings' windows back and the
 * session updated again. */
void XB_FASTCALL xb_XLIVE_WORK_CLASS_HostUpdate_State6(u8* self) {
    u8* m = (u8*)xb_GetMatchInfo();

    switch (*(s32*)(self + 0x2370)) {
    case 0:
        *(s32*)(self + 0x2370) = 1;
        xb_xlive_match_OpenWindow(0, m + 0x184);
        xb_xlive_match_OpenWindow(3, m + 0x190);
        return;
    case 1:
        if (xb_xlive_match_AreWindowsDone() == 0) {
            return;
        }

        (*(s32*)(self + 0x2370))++;
        *(s32*)(self + 0x23B4) = 0x78;
        xb_SeSelectedThunk();
        /* fallthrough */
    case 2:
        if (--*(s32*)(self + 0x23B4) >= 0) {
            return;
        }

        switch (*(s32*)(self + 0x2374)) {
        case 0:
            xb_xlive_match_ReopenWindow(1, m + 0x184);
            xb_xlive_match_ReopenWindow(3, m + 0x190);
            (*(s32*)(self + 0x2374))++;
            /* fallthrough */
        case 1:
            if (xb_xlive_match_IsWindowDone(m + 0x184)) {
                (*(s32*)(self + 0x2374))++;
            }

            return;
        case 2:
            xb_xlive_match_StartUpdateSession();
            *(s32*)(self + 0x2374) = 0;
            return;
        }

        return;
    }
}

typedef struct {
    u8 b[8];
} XB_XNKID8;
s32 XB_STDCALL XOnlineNotificationSetState(u32 user, u32 flags, XB_XNKID8 kid, u32 size, const u8* data);
void xb_xlive_match_DrawRankingTable2(void);
/* HostDraw_State4's colour step through D_003F8348. */
extern s32 D_00798E70;

/* xb_XLIVE_WORK_CLASS_HostDraw_State4 0x10CEE8: the host's waiting
 * screen: the waiting messages in changing colours (sub-steps 2 and 3),
 * then the ranking table (4); with the blinking line for an invited match
 * (+0x17D). */
void xb_XLIVE_WORK_CLASS_HostDraw_State4(void) {
    u8* m = (u8*)xb_GetMatchInfo();

    switch (*(s32*)(D_00798CAC + 0x2370)) {
    case 2:
        D_00798E70 = 0;
        /* fallthrough */
    case 3:
        if (m[0x17D] == 1) {
            xb_xlive_match_DrawBlinkMessage(3, 0x4C, 0);
        }

        if (++D_00798E70 > 6) {
            D_00798E70 = 0;
        }

        xb_xlive_disp_DrawMessage(3, 0x4A, 0, D_0025F370, 1.0f, D_003F8348[D_00798E70]);
        xb_xlive_disp_DrawMessage(3, 0x4B, 0, D_0025F370, 1.0f, D_003F8348[D_00798E70]);
        return;
    case 4:
        if (m[0x17D] == 1) {
            xb_xlive_match_DrawBlinkMessage(3, 0x4C, 0);
        }

        xb_xlive_disp_DrawMessageDefault(3, 0x4A, 0);
        xb_xlive_match_DrawRankingTable2();
        return;
    }
}

/* xb_XLIVE_WORK_CLASS_HostUpdate_State10 0x10CD93: the link to the
 * challenger brought up (its progress shown); once up, the Live
 * notification state set (playing, joinable unless signed on as a guest,
 * +8) and the windows released for the match. A failure drops the link
 * and the player and ends with error 13 (step 14). */
void XB_FASTCALL xb_XLIVE_WORK_CLASS_HostUpdate_State10(u8* self) {
    XB_XNKID8 kid;
    u8 joinable;
    XB_ARG a;

    switch (*(s32*)(self + 0x2370)) {
    case 0:
        if (xb_xlive_match_StepLink()) {
            (*(s32*)(self + 0x2370))++;
            xb_xlive_net_Close();
            xb_XLIVE_SIGNON_DropPlayer(xb_XLIVE_WORK_CLASS_Get2338(D_00798CAC));
            xb_xlive_match_Voice_F5B5F();
            XB_RESET_CONNECTION(1);
            xb_xlive_match_ReleaseWindow();
            return;
        }

        if (xb_xlive_net_IsLinkUp()) {
            joinable = *(s32*)(self + 8) != 0;
            memset(&kid, 0, sizeof(kid));
            XOnlineNotificationSetState(*(u32*)(self + 0x14), *(u32*)(self + 0x144), kid, 1, &joinable);
            xb_xlive_match_ClearRecordWork();
            xb_xlive_main_HideWin();
            xb_CONNECT_USER_CLASS_Release(D_00798CAC + 0x59E0);
            xb_xlive_disp_ReleaseOlder(1.0f);
            return;
        }

        xb_xlive_match_DrawStatus();
        return;
    case 1:
        *(s32*)(self + 0x236C) = 0xE;
        *(s32*)(self + 0x2370) = 0;
        xb_xlive_main_SetErrorArgs(0xD, D_002B5150, 0xF01, 1);
        return;
    }
}

s32 xb_LivePadUp(void);
s32 xb_LivePadDown(void);
s32 xb_LivePadLeft(void);
s32 xb_LivePadRight(void);
void xb_SeCursorMoveThunk(void);

/* The session list's cursor (the match info's +0xCC): [0] the chosen
 * row, [2] the page's top, [3] the row on the page, [4] the rows, [5]
 * the rows a page. The four movers are static: the cursor comes in a
 * register. */
s32 xb_xlive_match_CursorMoveA(u8* c) {
    s32 old = c[2] + c[3];

    if ((s8)--c[3] < 0) {
        c[3] = 0;

        if (c[2] != 0) {
            c[2]--;
        }
    }

    c[0] = c[3] + c[2];

    if (c[0] != old) {
        xb_SeCursorMoveThunk();
    }

    return 0;
}

s32 xb_xlive_match_CursorMoveB(u8* c) {
    u8 top = c[2];
    u8 cur = c[3];
    s32 old = top + cur;
    u8 n = c[5];

    c[3] = ++cur;

    if (cur > n - 1) {
        if (cur + top < c[4]) {
            c[2] = top + 1;
        }

        c[3] = n - 1;
    } else if (cur + top >= c[4]) {
        c[3] = cur - 1;
    }

    c[0] = c[3] + c[2];

    if (c[0] != old) {
        xb_SeCursorMoveThunk();
    }

    return 0;
}

s32 xb_xlive_match_ScrollPageDown(u8* c) {
    u8 n = c[5];
    u8 cnt = c[4];

    if (n < cnt) {
        if (c[0] + n < cnt - n) {
            c[2] += n;
        } else {
            c[2] = cnt - n;
        }
    }

    c[0] = c[3] + c[2];
    return 0;
}

s32 xb_xlive_match_ScrollPageUp(u8* c) {
    u8 n = c[5];

    if (c[4] > n) {
        if (n > c[2]) {
            c[2] = 0;
        } else {
            c[2] -= n;
        }
    }

    c[0] = c[3] + c[2];
    return 0;
}

s32 XB_FASTCALL xb_XLIVE_WORK_CLASS_GetQosResult(u8* self, s32 edx, u32 i);
void XB_FASTCALL xb_XLIVE_WORK_CLASS_JoinChosen(u8* self);

/* xb_XLIVE_WORK_CLASS_JoinUpdate_Qos 0x10E5D2 (join step 3): the found
 * sessions' list (QoS-ranked): up and down move, left and right turn the
 * page, A joins the chosen one if it answered, B goes back to the
 * settings, the left trigger searches again and the right trigger
 * searches the next way (+0xCA, 0 to 3). */
void XB_FASTCALL xb_XLIVE_WORK_CLASS_JoinUpdate_Qos(u8* self) {
    u8* m = (u8*)xb_GetMatchInfo();
    XB_ARG a;

    if (xb_LivePadUp()) {
        xb_xlive_match_CursorMoveA(m + 0xCC);
        return;
    }

    if (xb_LivePadDown()) {
        xb_xlive_match_CursorMoveB(m + 0xCC);
        return;
    }

    if (xb_LivePadAccept()) {
        a.v = m[0xCC];

        if (((s32 (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_WORK_CLASS_GetQosResult)(self, a) >= 0) {
            xb_SeSelectedThunk();
            xb_XLIVE_WORK_CLASS_JoinChosen(self);
        } else {
            xb_SeSelectedThunk();
        }

        return;
    }

    if (xb_LivePadRight()) {
        xb_xlive_match_ScrollPageDown(m + 0xCC);
        return;
    }

    if (xb_LivePadLeft()) {
        xb_xlive_match_ScrollPageUp(m + 0xCC);
        return;
    }

    if (xb_LivePadBack()) {
        *(s32*)(self + 0x2370) = 0;
        *(s32*)(self + 0x236C) = 1;
        xb_SeSelectedThunk();
        xb_xlive_match_ReleaseWindow();
        return;
    }

    if (xb_LivePadTrigger(0x100)) {
        xb_SeSelectedThunk();
    } else if (xb_LivePadTrigger(0x400)) {
        xb_SeSelectedThunk();

        if (++m[0xCA] > 3) {
            m[0xCA] = 0;
        }
    } else {
        return;
    }

    xb_xlive_match_BeginSearch(self);
}

u8* XB_FASTCALL xb_vector_SearchResult_At(u8* self, s32 edx, u32 i);
s32 XB_STDCALL XNetRegisterKey(const void* kid, const void* key);
u8* XB_FASTCALL xb_xlive_match_GetAddr30(u8* self);
s32 xb_xlive_match_Voice_F5DA0(void);
s32 xb_xlive_match_Voice_F56A8(void);
void xb_xlive_match_ResetTimer16C(void);
void xb_xlive_match_ResetTimer16E(void);
void xb_xlive_match_PeerVoiceA(void);

/* xb_XLIVE_WORK_CLASS_JoinChosen 0x10D7D7: the chosen session (the
 * results +0xA4, the list's row) joined: kept as the session record
 * (+0x5A4C) and its QoS result (+0x178), its key registered (+0xB4, on
 * +0xD0), the host's address (+0xCC, also the match info's +0x148), the
 * voice set up and the timers reset; then join step 4. A failure is error
 * 17 (step 11). */
void XB_FASTCALL xb_XLIVE_WORK_CLASS_JoinChosen(u8* self) {
    u8* m;
    u8* r;
    u32* kid;
    s32 line;
    XB_ARG a;

    (void)self;
    m = (u8*)xb_GetMatchInfo();
    a.v = m[0xCC];
    r = ((u8* (XB_FASTCALL*)(u8*, XB_ARG))xb_vector_SearchResult_At)(D_00798CAC + 0xA4, a);
    memcpy(D_00798CAC + 0x5A4C, r, 0xBC);
    *(s32*)(D_00798CAC + 0x236C) = 4;
    *(s32*)(D_00798CAC + 0x2370) = 1;
    *(s32*)(D_00798CAC + 0x2374) = 0;
    xb_xlive_match_ReleaseWindow();
    m[0x180] = 0;
    a.v = m[0xCC];
    *(s32*)(m + 0x178) = ((s32 (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_WORK_CLASS_GetQosResult)(D_00798CAC, a);
    xb_XLIVE_WORK_CLASS_RestartQos(D_00798CAC);
    xb_xlive_match_UnregisterKey();
    kid = (u32*)xb_LivePkt_GetData(r);

    if (XNetRegisterKey(kid, xb_xlive_match_GetAddr30(r)) != 0) {
        line = 0x4A9;
        goto fail;
    }

    *(s32*)(D_00798CAC + 0xD0) = 1;
    *(u32*)(D_00798CAC + 0xB4) = kid[0];
    *(u32*)(D_00798CAC + 0xB8) = kid[1];

    if (XNetXnAddrToInAddr(xb_xlive_match_GetAddr0C(r), D_00798CAC + 0xB4, (u32*)(D_00798CAC + 0xCC)) != 0) {
        line = 0x4BC;
        goto fail;
    }

    *(s32*)(m + 0x148) = *(s32*)(D_00798CAC + 0xCC);

    if (xb_xlive_match_Voice_F5DA0() == 0) {
        line = 0x4CA;
        goto fail;
    }

    xb_xlive_match_Voice_F56A8();
    xb_xlive_match_ResetTimer16C();
    xb_xlive_match_ResetTimer16E();
    xb_xlive_match_PeerVoiceA();
    return;
fail:
    *(s32*)(D_00798CAC + 0x236C) = 0xB;
    *(s32*)(D_00798CAC + 0x2370) = 0;
    xb_xlive_main_SetErrorArgs(0x11, D_002B5150, line, 1);
}

s32 XB_STDCALL XOnlineMatchSessionGetInfo(s32 task, void* kid, void* key);
s32 XB_FASTCALL xb_XLIVE_WORK_CLASS_QosStart(u8* self);
s32 XB_FASTCALL xb_iterator_Deref(u8* self);

/* The joining player's hello (kind 2) to the host: their name, xuid,
 * pad, settings and QoS, and whether their voice is ready. */
typedef struct {
    u8 kind;
    u8 pad1;
    u8 name[16];
    u8 pad12[2];
    u32 xuid[3];
    s32 port;
    s32 set108;
    s32 set10C;
    s32 set110;
    s32 set114;
    s32 set118;
    s32 set11C;
    s32 qos;
    u8 ready;
} XB_HELLO;

/* xb_xlive_match_PeerVoiceA 0x10D39C: the hello sent to the host. */
void xb_xlive_match_PeerVoiceA(void) {
    u8* m = (u8*)xb_GetMatchInfo();
    XB_HELLO h;
    XB_ARG a;

    h.kind = 2;
    h.pad1 = 0;
    memcpy(h.name, m + 0xD4, 16);
    a.v = 0;
    memcpy(h.xuid, ((u8* (XB_FASTCALL*)(u8*, XB_ARG))xb_deque_LiveObj_Subscript)(D_00798CAC + 0x28, a), 12);
    h.port = *(s32*)(D_00798CAC + 0x14);
    h.set108 = *(s32*)(m + 0x108);
    h.set10C = *(s32*)(m + 0x10C);
    h.set110 = *(s32*)(m + 0x110);
    h.set114 = *(s32*)(m + 0x114);
    h.set118 = *(s32*)(m + 0x118);
    h.set11C = *(s32*)(m + 0x11C);
    h.qos = *(s32*)(m + 0x178);
    a.v = *(s32*)(D_00798CAC + 0x14);
    h.ready = ((u8 (XB_FASTCALL*)(u8*, XB_ARG))xb_LiveObj_IsReady)(xb_LiveWork_Get2408(D_00798CAC), a);
    a.v = (s32)&h;
    ((s32 (XB_FASTCALL*)(u8*, XB_KEY16, XB_ARG))xb_LiveObj_SendVoice)(xb_LiveWork_Get2408(D_00798CAC),
                                                                       *(XB_KEY16*)(m + 0x144), a);
}

/* xb_XLIVE_WORK_CLASS_HostUpdate_SessionCreated 0x10C90A (host step 2):
 * the settings' windows, then the session's creation (task +0xFC)
 * polled: its key read (+0xB4, +0xBC) and registered (+0xD0), the voice
 * set up, QoS answering on, and the first update. A failure ends the host
 * (steps 12 and 13; error 17). */
void XB_FASTCALL xb_XLIVE_WORK_CLASS_HostUpdate_SessionCreated(u8* self) {
    u8* m = (u8*)xb_GetMatchInfo();
    s32 hr;
    s32 line;

    switch (*(s32*)(self + 0x2370)) {
    case 0:
        *(s32*)(self + 0x2370) = 1;
        xb_xlive_match_OpenWindow(1, m + 0x184);
        xb_xlive_match_OpenWindow(3, m + 0x190);
        return;
    case 1:
        if (xb_xlive_match_AreWindowsDone()) {
            (*(s32*)(self + 0x2370))++;
        }

        return;
    case 2:
        hr = CXBOnlineTask_Continue(self + 0xFC);

        if (hr == 0) {
            return;
        }

        if (hr < 0) {
            *(s32*)(self + 0x236C) = 0xC;
            line = 0xB04;
            goto task_fail;
        }

        xb_xlive_match_UnregisterKey();
        hr = XOnlineMatchSessionGetInfo(xb_iterator_Deref(self + 0xFC), self + 0xB4, self + 0xBC);

        if (hr < 0) {
            *(s32*)(self + 0x236C) = 0xD;
            line = 0xB13;
            goto task_fail;
        }

        if (XNetRegisterKey(self + 0xB4, self + 0xBC) != 0) {
            line = 0xB1E;
            goto fail;
        }

        *(s32*)(D_00798CAC + 0xD0) = 1;
        m[0x17C] = 0;
        m[0x17D] = 0;

        if (xb_xlive_match_Voice_F5DA0() == 0) {
            line = 0xB2F;
            goto fail;
        }

        *(s32*)(self + 0x3E0) = 1;
        xb_XLIVE_WORK_CLASS_QosStart(self);
        xb_xlive_match_StartUpdateSession();
        return;
    }

    return;
task_fail:
    *(s32*)(self + 0x2370) = 0;
    xb_xlive_main_SetMatchArgs(hr, D_002B5150, line, 1);
    return;
fail:
    *(s32*)(self + 0x2370) = 0;
    *(s32*)(self + 0x236C) = 0xD;
    xb_xlive_main_SetErrorArgs(0x11, D_002B5150, line, 1);
}

void XB_FASTCALL xb_LiveObj_Update(u8* self);
void xb_xlive_match_TickTimer16C(void);
s32 xb_xlive_match_UpdateSession(u8 open);
s32 XB_FASTCALL xb_XLIVE_FRIEND_CLASS_Session_Step(u8* self, s32 edx, s32 mode);
s32 XB_FASTCALL xb_xlive_main_Update(u8* self);
void XB_FASTCALL xb_XLIVE_FRIEND_CLASS_Session_Update(u8* self);
void xb_SeNewChallenger(void);

/* xb_XLIVE_WORK_CLASS_HostUpdate_State3 0x10CA5D: waiting for a
 * challenger (the session's update task +0xFC polled; an error ends the
 * host, step 13): the settings' windows, then until a challenger comes in
 * (+0x17E: the sound, step 4, the session closed to others) B gives up
 * (step 11). Sub-steps 3 and 4 show the friend window's friends (2) or
 * recent players (5) page while waiting. */
void XB_FASTCALL xb_XLIVE_WORK_CLASS_HostUpdate_State3(u8* self) {
    u8* m = (u8*)xb_GetMatchInfo();
    s32 hr;
    XB_ARG a;

    xb_LiveObj_Update(xb_LiveWork_Get2408(D_00798CAC));
    hr = CXBOnlineTask_Continue(self + 0xFC);

    if (hr < 0) {
        *(s32*)(self + 0x236C) = 0xD;
        *(s32*)(self + 0x2370) = 0;
        xb_xlive_main_SetMatchArgs(hr, D_002B5150, 0xB6B, 1);
        return;
    }

    if (m[0x17E] != 0) {
        xb_xlive_match_TickTimer16C();
    }

    switch (*(s32*)(self + 0x2370)) {
    case 0:
        *(s32*)(self + 0x2370) = 1;
        xb_xlive_match_OpenWindow(1, m + 0x184);
        xb_xlive_match_OpenWindow(3, m + 0x190);
        return;
    case 1:
        if (xb_xlive_match_AreWindowsDone()) {
            (*(s32*)(self + 0x2370))++;
        }

        return;
    case 2:
        if (m[0x17E] != 0) {
            xb_SeNewChallenger();
            *(s32*)(self + 0x236C) = 4;
            *(s32*)(self + 0x2370) = 2;
            *(s32*)(self + 0x2374) = 0;
            xb_xlive_match_ResetTimer16C();
            xb_xlive_match_ResetTimer16E();
            xb_xlive_match_ClearFlag10();
            xb_xlive_match_UpdateSession(0);
        } else if (xb_LivePadBack()) {
            xb_xlive_match_Voice_F5B5F();
            *(s32*)(self + 0x2370) = 0;
            *(s32*)(self + 0x236C) = 0xB;
            xb_SeSelectedThunk();
        }

        return;
    case 3:
    case 4:
        switch (*(s32*)(self + 0x2374)) {
        case 0:
            *(s32*)(self + 0x2374) = 1;
            xb_xlive_match_ReleaseWindow();

            if (*(s32*)(self + 0x2370) == 3) {
                a.v = 2;
                ((s32 (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_FRIEND_CLASS_Session_Step)(D_00798CAC + 0x25D0, a);
                *(s32*)(D_00798CAC + 0x164) = 1;
            } else {
                a.v = 5;
                ((s32 (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_FRIEND_CLASS_Session_Step)(D_00798CAC + 0x25D0, a);
            }

            /* fallthrough */
        case 1:
            if (xb_xlive_main_Update(D_00798CAC + 0x25D0)) {
                (*(s32*)(self + 0x2374))++;
            }

            return;
        default:
            xb_XLIVE_FRIEND_CLASS_Session_Update(D_00798CAC + 0x25D0);
            *(s32*)(self + 0x2370) = 0;
            *(s32*)(self + 0x2374) = 0;
            return;
        }
    }
}
