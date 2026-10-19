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
s32 sub_0011031E(void);
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
s32 sub_0011CCAB(void);
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

s32 xb_xlive_match_Check11031E(void) {
    return sub_0011031E() != 0;
}

void xb_xlive_match_DrawStatus(void) {
    char buf[16];
    s32 v;

    if (xb_XLIVE_WORK_CLASS_Frame(D_00798CAC)) {
        return;
    }

    v = sub_0011CCAB();

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

u8** XB_FASTCALL xb_SearchResultIt_AddAssign(u8** self, s32 edx, s32 n) {
    (void)edx;
    *self += n * 0xBC;
    return self;
}

s32 XB_FASTCALL xb_SearchResultIt_Diff(u8** self, s32 edx, u8** other) {
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

void xb_SearchResult_Construct(void* where, void* src) {
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

void XB_FASTCALL xb_SearchResult_ConstructAt(void* self, s32 edx, void* p, void* src) {
    (void)self;
    (void)edx;
    xb_SearchResult_Construct(p, src);
}

void XB_FASTCALL xb_XLIVE_WORK_CLASS_SetState8(u8* self) {
    xb_xlive_match_ReleaseWindow();
    *(s32*)(self + 0x2370) = 0;
    *(s32*)(self + 0x236C) = 8;
    xb_xlive_match_PeerVoiceC(2);
}

void XB_FASTCALL xb_SearchResultVec_Ucopy(void* self, s32 edx, void* a, void* b, void* c) {
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
