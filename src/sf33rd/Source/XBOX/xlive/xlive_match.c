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
void XB_FASTCALL sub_00107BF8(void* self);
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
void xb_xlive_main_SetMatchArgs(s32 hr, const char* file, s32 line, s32 a);
s32 sub_0011031E(void);
extern s16 D_00798E74;
void XB_FASTCALL sub_00115C20(void* self);
void XB_FASTCALL sub_00115C59(void* self);
void XB_FASTCALL sub_00115CB6(void* self);
void XB_FASTCALL sub_00115D13(void* self);
void xb_xlive_match_CreateSession(void);
void xb_xlive_match_UpdateSession(s32 a);
s32 XB_FASTCALL sub_000F5DA0(u8* self);
void XB_FASTCALL sub_000F5B5F(u8* self);
void* sub_0001219E(u32 size, void* where);
void xb_xlive_match_CheckVoiceReady(void);
void xb_xlive_match_DrawStatsIfHost(void);
void xb_xlive_match_PeerVoiceC(s32 a);
void xb_SearchResult_UninitCopyWrap(void* a, void* b, void* c, void* self);
void xb_xlive_disp_DrawTextAt(f32 x, f32 y, s32 text);
void xb_xlive_disp_DrawMessageDefault(s32 a, s32 b, s32 c);
u8* XB_FASTCALL xb_LiveWork_Get2408(u8* self);

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
        sub_00107BF8(self);
        break;
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

void xb_XLIVE_WORK_CLASS_HostDraw_State5(void) {
    xb_xlive_disp_DrawMessageDefault(3, 0x4A, 0);
    xb_xlive_disp_DrawMessageDefault(3, 0x63, 0);
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
    xb_xlive_match_ReleaseWindow();
    *(s32*)(self + 0x2370) = 0;
    *(s32*)(self + 0x236C) = 8;
    xb_xlive_match_PeerVoiceC(2);
}

void XB_FASTCALL xb_SearchResultVec_Ucopy(void* self, s32 edx, void* a, void* b, void* c) {
    (void)edx;
    xb_SearchResult_UninitCopyWrap(a, b, c, self);
}
