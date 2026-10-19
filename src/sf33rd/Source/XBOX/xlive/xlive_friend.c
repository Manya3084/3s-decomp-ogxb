/* xlive_friend.c: Xbox-only code from Capcom's xlive_friend.cpp. Its _assert path names it, and the
 * code that pushes the path places it at 0xFBD74 to 0x1060BD.
 * Capcom's source is lost. Its C++ methods are written as C,
 * XB_FASTCALL (__fastcall) with this first. Each body was checked
 * against retail by analysis-ps2map/xbgen.py. The xb_ names are
 * made up. */

#include "types.h"
#include <stdarg.h>
#include <string.h>

void _assert(const char* expr, const char* file, u32 line);
extern char D_002B4D08[];
extern char D_002B4D7C[];
s32 XB_STDCALL wvsprintfW(void* buf, const void* fmt, va_list ap);
extern char D_002193D8[];
s32 XB_FASTCALL std__vector_ACTIONS__size(void* self);
void operator_delete(void* p);
void XB_FASTCALL xb_XLIVE_FRIEND_CLASS_InitPages(void* self);
void* XB_FASTCALL xb_vector_CopyCtor(void** self, s32 edx, void* p);
extern u8* D_00798CAC;
s32 XB_FASTCALL CXBOnlineTask_operator_addr(void* self);
s32 XB_STDCALL XOnlineFriendsEnumerate(s32 user, s32 a, s32 task);
void xb_xlive_main_SetMatchArgs(s32 hr, const char* file, s32 line, s32 a);
s32 XB_FASTCALL CXBOnlineTask_Close(void* self);
void XB_FASTCALL sub_00109037(void* self);
void XB_FASTCALL xb_XLIVE_FRIEND_CLASS_FadeWindow(u8* self, s32 edx, s32 i);

s32 XB_FASTCALL xb_XLIVE_FRIEND_CLASS_GetWindow(u8* self, s32 edx, s32 no) {
    (void)edx;

    if (!(no >= 0 && no < 2)) {
        _assert(D_002B4D7C, D_002B4D08, 0x135D);
    }

    return *(s32*)(self + no * 4 + 0xA8C);
}

void xb_xlive_friend_Printf(void* buf, const void* fmt, ...) {
    va_list ap;

    va_start(ap, fmt);

    if ((u32)wvsprintfW(buf, fmt, ap) >= 0x400) {
        _assert(D_002193D8, D_002B4D08, 0x14A7);
    }
}

s32 XB_FASTCALL xb_xlive_friend_IsEmpty(void* self) {
    return std__vector_ACTIONS__size(self) == 0;
}

s32 XB_FASTCALL xb_iterator_Deref(u8* self) {
    return *(s32*)(self + 0x0);
}

void XB_FASTCALL xb_deallocate(void* self, s32 edx, void* p, s32 n) {
    (void)self;
    (void)edx;
    (void)n;
    operator_delete(p);
}

void** XB_FASTCALL xb_iterator_ctor(void** self, s32 edx, void* p) {
    (void)edx;
    *self = p;
    return self;
}

void XB_FASTCALL xb_XLIVE_STAT_CLASS_Set440(u8* self, s32 edx, s32 v) {
    (void)edx;
    *(s32*)(self + 0x440) = v;
}

u8* XB_FASTCALL xb_XLIVE_FRIEND_CLASS_GetFriendList(u8* self) {
    return self + 0x860;
}

u8* XB_FASTCALL xb_XLIVE_FRIEND_CLASS_GetState2A48(u8* self) {
    return self + 0x2A48;
}

void XB_FASTCALL xb_XLIVE_STARTMENU_CLASS_Set80(u8* self, s32 edx, s32 v) {
    (void)edx;
    *(s32*)(self + 0x80) = v;
}

s32 XB_FASTCALL xb_iterator_Get4(u8* self) {
    return *(s32*)(self + 0x4);
}

void XB_FASTCALL xb_XLIVE_FRIEND_CLASS_FadeAllWindows(u8* self) {
    s32 i;

    for (i = 0; i < 2; i++) {
        XB_ARG a;

        a.v = i;
        ((void (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_FRIEND_CLASS_FadeWindow)(self, a);
    }
}

void XB_FASTCALL xb_XLIVE_FRIEND_CLASS_Session_SetArgs(u8* self, s32 edx, s32 a, s32 b) {
    (void)edx;
    *(s32*)(self + 0x8B0) = a;
    *(s32*)(self + 0x8B4) = b;
    xb_XLIVE_FRIEND_CLASS_InitPages(self);
}

void* XB_FASTCALL xb_xlive_friend_GetElem4(u8* self, s32 edx, void** ret) {
    xb_vector_CopyCtor(ret, edx, *(void**)(self + 4));
    return ret;
}

void* XB_FASTCALL xb_xlive_friend_GetElem8(u8* self, s32 edx, void** ret) {
    xb_vector_CopyCtor(ret, edx, *(void**)(self + 8));
    return ret;
}

s32 XB_FASTCALL xb_XLIVE_FRIEND_CLASS_StartEnumerate(u8* self) {
    s32 hr = XOnlineFriendsEnumerate(*(s32*)(D_00798CAC + 0x14), 0, CXBOnlineTask_operator_addr(D_00798CAC + 0x110));

    if (hr < 0) {
        xb_xlive_main_SetMatchArgs(hr, D_002B4D08, 0x1A05, 0);
        CXBOnlineTask_Close(D_00798CAC + 0x110);
        return -1;
    }

    sub_00109037(self + 0x860);
    return 1;
}

s32 xb_LivePadRepeat(u32 mask);
u32 XB_STDCALL XLaunchNewImageA(const char* path, void* data);

/* xb_LivePadMenuInput 0xFB951: the Live menus' input: the first repeating
 * button of up, down, left, right, A, B, X, Y, start, back and ... as 0 to
 * 9, or 10 for button 8, 11 for none. */
s32 xb_LivePadMenuInput(void) {
    if (xb_LivePadRepeat(0x10)) {
        return 0;
    }

    if (xb_LivePadRepeat(0x20)) {
        return 1;
    }

    if (xb_LivePadRepeat(0x100)) {
        return 2;
    }

    if (xb_LivePadRepeat(0x200)) {
        return 3;
    }

    if (xb_LivePadRepeat(0x4000)) {
        return 4;
    }

    if (xb_LivePadRepeat(0x40)) {
        return 5;
    }

    if (xb_LivePadRepeat(0x400)) {
        return 6;
    }

    if (xb_LivePadRepeat(1)) {
        return 7;
    }

    if (xb_LivePadRepeat(2)) {
        return 8;
    }

    if (xb_LivePadRepeat(4)) {
        return 9;
    }

    return xb_LivePadRepeat(8) != 0 ? 10 : 11;
}

/* xb_XLIVE_FRIEND_CLASS_SetState 0xFBA4B: the friend window's wait state
 * (+0x2A3C); 2 and 3 also set its flags (+0x2A48 to +0x2A54). */
void XB_FASTCALL xb_XLIVE_FRIEND_CLASS_SetState(u8* self, s32 edx, s32 st) {
    (void)edx;

    switch (st) {
    case 2:
        *(s32*)(self + 0x2A4C) = 0;
        *(s32*)(self + 0x2A54) = 0;
        *(s32*)(self + 0x2A48) = 1;
        *(s32*)(self + 0x2A50) = 1;
        break;

    case 3:
        *(s32*)(self + 0x2A48) = 0;
        *(s32*)(self + 0x2A54) = 1;
        *(s32*)(self + 0x2A4C) = 1;
        *(s32*)(self + 0x2A50) = 1;
        break;
    }

    *(s32*)(self + 0x2A3C) = st;
}

/* xb_LaunchDashboard 0xFBB75: back to the dashboard (XLaunchNewImage with
 * no path and empty launch data). */
void xb_LaunchDashboard(void) {
    u8 ld[0xC00];

    memset(ld, 0, sizeof(ld));
    *(u32*)ld = 0;
    XLaunchNewImageA(0, ld);
}

/* The friend window's voice mail: record, stop, play and send a message
 * to a friend, through xhv.h's inline wrappers. */

s32 XB_STDCALL sub_0012AF3A(s32 engine, s32 port, u32 ms, u32 size, void* data);
s32 XB_STDCALL sub_0012AF43(s32 engine, s32 port, u32 len, void* data, u32 size);
s32 XB_STDCALL sub_0012AF4C(s32 engine, s32 port);
void xb_SeSelectedThunk(void);
void XB_FASTCALL CXBStopWatch_Stop(void* self);
void XB_FASTCALL CXBStopWatch_StartZero(void* self);
u8* XB_FASTCALL xb_LiveObj_Get8(u8* self);
s32 XB_FASTCALL xb_LiveObj_Call2(u8* self, s32 edx, s32 a, s32 b);
u32 XB_STDCALL GetLastError(void);
void XB_FASTCALL xb_XLIVE_FRIEND_CLASS_CloseWindow(u8* self, s32 edx, s32 i);
s32 xb_xlive_disp_DrawRectF(f32 x, f32 y, f32 w, f32 h, f32 z);
s32 xb_xlive_disp_SetObj0C(s32 id, s32 v);
extern void (XB_STDCALL* D_00218DC0)(void* cs);
extern void (XB_STDCALL* D_00218DC4)(void* cs);
extern u8 D_00797EFC[];
extern f32 D_002B4DCC;
extern f32 D_002190A4;
extern f32 D_002190A8;
extern s32 D_003F82C0;
extern s32 D_003F82C4;
extern s32 D_003F82C8;

/* IXHVEngine__VoiceMailRecord 0xFC437, __VoiceMailPlay 0xFC440,
 * __VoiceMailStop 0xFC449: the inline wrappers, jumps to the engine's. */
s32 XB_STDCALL IXHVEngine__VoiceMailRecord(s32 engine, s32 port, u32 ms, u32 size, void* data) {
    return sub_0012AF3A(engine, port, ms, size, data);
}

s32 XB_STDCALL IXHVEngine__VoiceMailPlay(s32 engine, s32 port, u32 len, void* data, u32 size) {
    return sub_0012AF43(engine, port, len, data, size);
}

s32 XB_STDCALL IXHVEngine__VoiceMailStop(s32 engine, s32 port) {
    return sub_0012AF4C(engine, port);
}

/* The engine: the voice chat object (work +0x2408)'s +4. */
static s32 xb_xlive_friend_Engine(void) {
    return xb_iterator_Get4(xb_LiveObj_Get8(D_00798CAC + 0x2408));
}

/* xb_XLIVE_FRIEND_CLASS_SetMailState 0xFBA96: which voice-mail actions
 * are open in state 0 to 5: record (+0x2A48), stop (+0x2A4C), play
 * (+0x2A50), send (+0x2A54). */
void XB_FASTCALL xb_XLIVE_FRIEND_CLASS_SetMailState(u8* self, s32 edx, s32 st) {
    (void)edx;

    switch (st) {
    case 0:
        *(s32*)(self + 0x2A48) = 1;
        *(s32*)(self + 0x2A54) = 0;
        *(s32*)(self + 0x2A50) = 0;
        *(s32*)(self + 0x2A4C) = 0;
        break;

    case 1:
        *(s32*)(self + 0x2A4C) = 1;
        *(s32*)(self + 0x2A54) = 0;
        *(s32*)(self + 0x2A50) = 0;
        *(s32*)(self + 0x2A48) = 0;
        break;

    case 2:
        *(s32*)(self + 0x2A54) = 1;
        *(s32*)(self + 0x2A50) = 1;
        *(s32*)(self + 0x2A48) = 1;
        *(s32*)(self + 0x2A4C) = 0;
        break;

    case 3:
        *(s32*)(self + 0x2A50) = 0;
        *(s32*)(self + 0x2A48) = 0;
        *(s32*)(self + 0x2A54) = 1;
        *(s32*)(self + 0x2A4C) = 1;
        break;

    case 4:
        *(s32*)(self + 0x2A48) = 0;
        *(s32*)(self + 0x2A54) = 1;
        *(s32*)(self + 0x2A50) = 0;
        *(s32*)(self + 0x2A4C) = 0;
        break;

    case 5:
        *(s32*)(self + 0x2A48) = 0;
        *(s32*)(self + 0x2A54) = 1;
        *(s32*)(self + 0x2A50) = 1;
        *(s32*)(self + 0x2A4C) = 0;
        break;
    }
}

/* xb_XLIVE_FRIEND_CLASS_Update 0xFC541: the voice-mail page's input: the
 * cursor (+0x8B8, 0 to 3) moves with 7 and 8, 1 and 4 leave (+4 = 4),
 * and 0 runs the action under it: record (up to 15 s into +0x2A2C), stop,
 * play back, or stop and send it to the friend (+0x2A60). A wait (+0x2AB8)
 * holds the input. */
void XB_FASTCALL xb_XLIVE_FRIEND_CLASS_Update(u8* self, s32 edx, s32 in) {
    u8* work;
    XB_ARG a;
    XB_ARG b;

    (void)edx;

    if (*(s32*)(self + 0x2AB8) > 0) {
        (*(s32*)(self + 0x2AB8))--;
        return;
    }

    *(s32*)(self + 0x2AB8) = 0;

    switch (in) {
    case 1:
    case 4:
        xb_SeSelectedThunk();
        *(s32*)(self + 4) = 4;
        *(u32*)(self + 0x8B8) = 0;
        return;

    case 7:
        if (*(u32*)(self + 0x8B8) == 0) {
            *(u32*)(self + 0x8B8) = 0;
        } else {
            (*(u32*)(self + 0x8B8))--;
        }

        return;

    case 8:
        if (++*(u32*)(self + 0x8B8) > 3) {
            *(u32*)(self + 0x8B8) = 3;
        }

        return;

    case 0:
        break;

    default:
        return;
    }

    xb_SeSelectedThunk();

    switch (*(u32*)(self + 0x8B8)) {
    case 0:
        if (*(s32*)(self + 0x2A48) == 0) {
            return;
        }

        memset(*(void**)(self + 0x2A2C), 0, *(u32*)(self + 0x2A30));
        D_00218DC4(D_00797EFC);

        if (IXHVEngine__VoiceMailRecord(xb_xlive_friend_Engine(), *(s32*)(D_00798CAC + 0x14), 0x3A98, 0x499A,
                                        *(void**)(self + 0x2A2C)) < 0) {
            GetLastError();
        }

        work = D_00798CAC;
        *(s32*)(work + 0x24AC) = 0;
        *(s32*)(D_00798CAC + 0x24A8) = 0;
        *(s32*)(D_00798CAC + 0x24A0) = 0;
        *(s32*)(D_00798CAC + 0x24A4) = 0;
        D_00218DC0(D_00797EFC);
        *(f32*)(D_00798CAC + 0x24B0) = 0.0f;
        *(f32*)(D_00798CAC + 0x24B4) = D_002B4DCC;
        CXBStopWatch_StartZero(self + 0x890);
        *(f32*)(self + 0x2A40) = 0.0f;
        a.v = 1;
        ((void (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_FRIEND_CLASS_SetMailState)(self, a);
        *(s32*)(self + 4) = 0xA;
        return;

    case 1:
        if (*(s32*)(self + 0x2A4C) == 0) {
            return;
        }

        D_00218DC4(D_00797EFC);
        IXHVEngine__VoiceMailStop(xb_xlive_friend_Engine(), *(s32*)(D_00798CAC + 0x14));
        D_00218DC0(D_00797EFC);
        CXBStopWatch_Stop(self + 0x890);
        a.v = 2;
        ((void (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_FRIEND_CLASS_SetMailState)(self, a);
        *(s32*)(self + 0x2AB8) = 0x1E;
        return;

    case 2:
        if (*(s32*)(self + 0x2A50) == 0) {
            return;
        }

        D_00218DC4(D_00797EFC);
        work = D_00798CAC;
        IXHVEngine__VoiceMailPlay(xb_xlive_friend_Engine(), *(s32*)(work + 0x14), *(u32*)(work + 0x24AC),
                                  *(void**)(self + 0x2A2C), *(u32*)(work + 0x249C));
        *(s32*)(D_00798CAC + 0x24A4) = 0;
        D_00218DC0(D_00797EFC);
        *(f32*)(D_00798CAC + 0x24B0) = 0.0f;
        CXBStopWatch_StartZero(self + 0x890);
        a.v = 3;
        ((void (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_FRIEND_CLASS_SetMailState)(self, a);
        *(s32*)(self + 4) = 0x14;
        return;

    case 3:
        if (*(s32*)(self + 0x2A54) == 0) {
            return;
        }

        CXBStopWatch_Stop(self + 0x890);
        D_00218DC4(D_00797EFC);
        IXHVEngine__VoiceMailStop(xb_xlive_friend_Engine(), *(s32*)(D_00798CAC + 0x14));
        a.v = *(s32*)(D_00798CAC + 0x14);
        b.v = *(s32*)(self + 0x2A60);
        ((s32 (XB_FASTCALL*)(u8*, XB_ARG, XB_ARG))xb_LiveObj_Call2)(xb_LiveObj_Get8(D_00798CAC + 0x2408), a, b);
        D_00218DC0(D_00797EFC);
        *(s32*)(self + 4) = 0x1E;
        *(s32*)(self + 0x2AB8) = 0x1E;
        return;
    }
}

/* xb_XLIVE_FRIEND_CLASS_InitPages 0xFC847: both windows closed and the
 * three page rectangles (D_003F82C0, C4, C8) made when missing, black. */
void XB_FASTCALL xb_XLIVE_FRIEND_CLASS_InitPages(void* self) {
    s32 i;
    XB_ARG a;

    for (i = 0; i < 2; i++) {
        a.v = i;
        ((void (XB_FASTCALL*)(void*, XB_ARG))xb_XLIVE_FRIEND_CLASS_CloseWindow)(self, a);
    }

    if (D_003F82C0 == -1) {
        D_003F82C0 = xb_xlive_disp_DrawRectF(0.0f, 0.0f, 0.0f, 0.0f, D_002190A4);
    }

    if (D_003F82C4 == -1) {
        D_003F82C4 = xb_xlive_disp_DrawRectF(0.0f, 0.0f, 0.0f, 0.0f, D_002190A8);
    }

    if (D_003F82C8 == -1) {
        D_003F82C8 = xb_xlive_disp_DrawRectF(0.0f, 0.0f, 0.0f, 0.0f, D_002190A8);
    }

    xb_xlive_disp_SetObj0C(D_003F82C0, 0xFF000000);
    xb_xlive_disp_SetObj0C(D_003F82C4, 0xFF000000);
    xb_xlive_disp_SetObj0C(D_003F82C8, 0xFF000000);
}

/* The friend window's pages: each takes the menu input. The text of a
 * result is written to the window (+0x60) and the page changes with
 * Session_SetArgs (page +0x8B0, next +0x8B4). */

typedef struct {
    u32 lo;
    u32 hi;
    u32 flags;
} XB_FXUID;

void xb_SeCursorMoveThunk(void);
void XBUtil_GetWide(const char* s, u16* out, s32 n);
s32 XB_STDCALL XOnlineFeedbackSend(s32 user, XB_FXUID xuid, s32 type, void* params, void* ev, s32 task);
s32 XB_FASTCALL xb_XLIVE_FRIEND_CLASS_RequestFriend(u8* self);
s32 XB_FASTCALL CXBOnlineTask_Continue(void* self);
extern s32 D_003F82D4[];
extern char* D_00799174;
extern char* D_007991D4;
extern char* D_007992B0;
extern char* D_00799378;
extern char* D_0079938C;
extern char* D_0079939C;

static void xb_xlive_friend_SetPage(u8* self, s32 page, s32 next) {
    XB_ARG a;
    XB_ARG b;

    a.v = page;
    b.v = next;
    ((void (XB_FASTCALL*)(u8*, XB_ARG, XB_ARG))xb_XLIVE_FRIEND_CLASS_Session_SetArgs)(self, a, b);
}

/* xb_XLIVE_FRIEND_CLASS_Page_FCEE2: the feedback page: one of seven
 * complaints (+0x8B8) chosen and confirmed (+0x8BC), then sent with
 * XOnlineFeedbackSend about the friend (+0x960, named at +0x970). */
void XB_FASTCALL xb_XLIVE_FRIEND_CLASS_Page_FCEE2(u8* self, s32 edx, s32 in) {
    u16 text[0x100];
    void* name;
    s32 hr;

    (void)edx;

    if (*(s32*)(self + 0x8BC) == 0) {
        switch (in) {
        case 0:
            xb_SeSelectedThunk();
            *(s32*)(self + 0x8BC) = 1;
            break;

        case 1:
        case 4:
            xb_SeSelectedThunk();
            xb_xlive_friend_SetPage(self, 2, 2);
            *(s32*)(self + 0x8B8) = 0;
            break;

        case 7:
            xb_SeCursorMoveThunk();

            if (*(s32*)(self + 0x8B8) == 0) {
                *(s32*)(self + 0x8B8) = 6;
            } else {
                (*(s32*)(self + 0x8B8))--;
            }

            break;

        case 8:
            xb_SeCursorMoveThunk();

            if (*(s32*)(self + 0x8B8) == 6) {
                *(s32*)(self + 0x8B8) = 0;
            } else {
                (*(s32*)(self + 0x8B8))++;
            }

            break;
        }

        return;
    }

    switch (in) {
    case 0:
        name = self + 0x970;
        xb_SeSelectedThunk();
        hr = XOnlineFeedbackSend(*(s32*)(D_00798CAC + 0x14), *(XB_FXUID*)(self + 0x960), D_003F82D4[*(s32*)(self + 0x8B8)],
                                 &name, 0, CXBOnlineTask_operator_addr(D_00798CAC + 0x114));

        if (hr < 0) {
            xb_xlive_main_SetMatchArgs(hr, D_002B4D08, 0x1F4, 0);
            XBUtil_GetWide(D_00799378, text, 0x100);
            xb_xlive_friend_Printf(self + 0x60, text);
            xb_xlive_friend_SetPage(self, 0xE, 0x11);
        } else {
            *(s32*)(self + 0x8B0) = 7;
            xb_xlive_friend_SetPage(self, 7, 7);
        }

        break;

    case 1:
    case 4:
        xb_SeSelectedThunk();
        *(s32*)(self + 0x8BC) = 0;
        break;
    }
}

/* xb_XLIVE_FRIEND_CLASS_Page_FD064: waiting for the feedback to be sent:
 * the result shown (D_0079938C, or D_00799378 on an error). */
void XB_FASTCALL xb_XLIVE_FRIEND_CLASS_Page_FD064(u8* self, s32 edx, s32 in) {
    u16 text[0x100];
    s32 hr;

    (void)edx;
    (void)in;
    hr = CXBOnlineTask_Continue(D_00798CAC + 0x114);

    if (hr == 0) {
        return;
    }

    CXBOnlineTask_Close(D_00798CAC + 0x114);

    if (hr < 0) {
        XBUtil_GetWide(D_00799378, text, 0x100);
        xb_xlive_friend_Printf(self + 0x60, text);
        xb_xlive_main_SetMatchArgs(hr, D_002B4D08, 0x22F, 0);
        xb_xlive_friend_SetPage(self, 0xE, 0x11);
        return;
    }

    XBUtil_GetWide(D_0079938C, text, 0x100);
    xb_xlive_friend_Printf(self + 0x60, text);
    xb_xlive_friend_SetPage(self, 0xE, 1);
    *(s32*)(self + 0x8B8) = 0;
    *(s32*)(self + 0x8BC) = 0;
}

/* xb_XLIVE_FRIEND_CLASS_Page_FD137: a friend request sent, and its result
 * shown: sent, the list full (0x80152002), already a friend (0x80152007),
 * or failed. */
void XB_FASTCALL xb_XLIVE_FRIEND_CLASS_Page_FD137(u8* self, s32 edx, s32 in) {
    u16 text[0x100];
    s32 r;

    (void)edx;
    (void)in;
    r = xb_XLIVE_FRIEND_CLASS_RequestFriend(self);

    if (r == (s32)0x80152002) {
        XBUtil_GetWide(D_007991D4, text, 0x100);
    } else if (r == (s32)0x80152007) {
        XBUtil_GetWide(D_007992B0, text, 0x100);
    } else if (r == 0) {
        XBUtil_GetWide(D_00799174, text, 0x100);
    } else {
        XBUtil_GetWide(D_0079939C, text, 0x100);
    }

    xb_xlive_friend_Printf(self + 0x60, text);
    *(s32*)(self + 0x8B8) = 0;
    *(s32*)(self + 0x8BC) = 0;
    xb_xlive_friend_SetPage(self, 0xE, 1);
}

s32 XB_FASTCALL xb_XLIVE_STAT_CLASS_Frame(u8* self, s32 edx, s32* hr);
s32 XB_FASTCALL xb_XLIVE_FRIEND_CLASS_UpdateWindows(u8* self);
extern char* D_007990C4;
extern char* D_0079933C;

static void xb_xlive_friend_Error(u8* self, s32 hr, s32 line, const char* msg) {
    u16 text[0x100];

    xb_xlive_main_SetMatchArgs(hr, D_002B4D08, line, 0);
    XBUtil_GetWide(msg, text, 0x100);
    xb_xlive_friend_Printf(self + 0x60, text);
    xb_xlive_friend_SetPage(self, 0xE, 0x11);
}

/* xb_XLIVE_FRIEND_CLASS_Page_FD1DA: the friend's statistics page, run by
 * the second stat object (work +0x5538); when it is done the page goes
 * back by +0xA84. */
void XB_FASTCALL xb_XLIVE_FRIEND_CLASS_Page_FD1DA(u8* self, s32 edx, s32 in) {
    u16 text[0x100];
    s32 r;
    s32 back;
    XB_ARG a;

    (void)edx;
    a.v = in;
    ((void (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_STAT_CLASS_Set440)(D_00798CAC + 0x5538, a);
    a.v = (s32)&in;
    r = ((s32 (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_STAT_CLASS_Frame)(D_00798CAC + 0x5538, a);

    if (r == -1) {
        xb_xlive_main_SetMatchArgs(in, D_002B4D08, 0x661, 0);
        XBUtil_GetWide(D_007990C4, text, 0x100);
        xb_xlive_friend_Printf(self + 0x60, text);
        xb_xlive_friend_SetPage(self, 0xE, 0x11);
        *(s32*)(self + 0x8B8) = 0;
        *(s32*)(self + 0x8BC) = 0;
    } else if (r == 1) {
        *(s32*)(self + 0x8B8) = 0;
        *(s32*)(self + 0x8BC) = 0;
        back = *(s32*)(self + 0xA84) != 0;
        xb_xlive_friend_SetPage(self, back, back);
    }
}

/* xb_XLIVE_FRIEND_CLASS_Page_FD2A9: waiting for the friend tasks (work
 * +0x110, then +0x10C and +0x118); when they are through the next page
 * comes, and the friends are enumerated again for the user (+0x5C). */
void XB_FASTCALL xb_XLIVE_FRIEND_CLASS_Page_FD2A9(u8* self, s32 edx, s32 in) {
    s32 hr;

    (void)edx;
    (void)in;

    if (xb_XLIVE_FRIEND_CLASS_UpdateWindows(self) != 0) {
        xb_XLIVE_FRIEND_CLASS_InitPages(self);
    }

    hr = CXBOnlineTask_Continue(D_00798CAC + 0x110);

    if (hr == 0x1500F0) {
        hr = CXBOnlineTask_Continue(D_00798CAC + 0x10C);

        if (hr == 0x1500F2) {
            hr = CXBOnlineTask_Continue(D_00798CAC + 0x118);
        }
    }

    if (hr < 0) {
        xb_xlive_friend_Error(self, hr, 0x6DC, D_0079933C);
        return;
    }

    if (hr != 0x1500F2) {
        return;
    }

    *(s32*)(self + 0x8BC) = 0;
    *(s32*)(self + 0x8B8) = 0;
    *(s32*)(self + 0x8B0) = *(s32*)(self + 0x8B4);

    if (xb_iterator_Deref(D_00798CAC + 0x110) != 0) {
        CXBOnlineTask_Close(D_00798CAC + 0x110);
    }

    hr = XOnlineFriendsEnumerate(*(s32*)(self + 0x5C), 0, CXBOnlineTask_operator_addr(D_00798CAC + 0x110));

    if (hr < 0) {
        xb_xlive_friend_Error(self, hr, 0x6F0, D_0079933C);
    }
}

void XB_FASTCALL xb_XLIVE_FRIEND_CLASS_SetState(u8* self, s32 edx, s32 st);
void xb_xlive_friend_Release(s32 id);
extern s32 D_003F82CC;
extern s32 D_003F82D0;
extern u32 D_003F830C;
extern f32 D_00219620;

/* xb_XLIVE_FRIEND_CLASS_SetPage 0xFD3DE: the input of the page of a
 * received voice message (cursor +0x8B8, up to 3 less D_003F830C): stop,
 * play it (+0x2A2C, length +0x2A34), reply (the message sent, the page's
 * rectangles released), or back (+4 = 0x14). */
void XB_FASTCALL xb_XLIVE_FRIEND_CLASS_SetPage(u8* self, s32 edx, s32 in) {
    XB_ARG a;
    XB_ARG b;

    (void)edx;

    switch (in) {
    case 8:
        if (++*(u32*)(self + 0x8B8) > 3 - D_003F830C) {
            *(u32*)(self + 0x8B8) = 3 - D_003F830C;
        }

        return;

    case 7:
        if (*(u32*)(self + 0x8B8) == 0) {
            *(u32*)(self + 0x8B8) = 0;
        } else {
            (*(u32*)(self + 0x8B8))--;
        }

        return;

    case 0:
        break;

    default:
        return;
    }

    xb_SeSelectedThunk();

    switch (*(u32*)(self + 0x8B8)) {
    case 0:
        if (*(s32*)(self + 0x2A48) == 0) {
            return;
        }

        D_00218DC4(D_00797EFC);
        IXHVEngine__VoiceMailStop(xb_xlive_friend_Engine(), *(s32*)(D_00798CAC + 0x14));
        D_00218DC0(D_00797EFC);
        a.v = 3;
        ((void (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_FRIEND_CLASS_SetState)(self, a);
        *(s32*)(self + 4) = 7;
        return;

    case 1:
        if (*(s32*)(self + 0x2A4C) == 0) {
            return;
        }

        D_00218DC4(D_00797EFC);
        IXHVEngine__VoiceMailPlay(xb_xlive_friend_Engine(), *(s32*)(D_00798CAC + 0x14), *(u32*)(self + 0x2A34),
                                  *(void**)(self + 0x2A2C), *(u32*)(D_00798CAC + 0x249C));
        *(s32*)(D_00798CAC + 0x24A4) = 0;
        D_00218DC0(D_00797EFC);
        a.v = 2;
        ((void (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_FRIEND_CLASS_SetState)(self, a);
        *(f32*)(D_00798CAC + 0x24B0) = 0.0f;
        *(f32*)(D_00798CAC + 0x24B4) = *(f32*)(self + 0x2A44) / D_00219620;
        CXBStopWatch_StartZero(self + 0x890);
        *(f32*)(self + 0x2A40) = 0.0f;
        *(s32*)(self + 4) = 6;
        return;

    case 2:
        if (*(s32*)(self + 0x2A50) == 0) {
            return;
        }

        D_00218DC4(D_00797EFC);
        IXHVEngine__VoiceMailStop(xb_xlive_friend_Engine(), *(s32*)(D_00798CAC + 0x14));
        a.v = *(s32*)(D_00798CAC + 0x14);
        b.v = *(s32*)(self + 0x2A60);
        ((s32 (XB_FASTCALL*)(u8*, XB_ARG, XB_ARG))xb_LiveObj_Call2)(xb_LiveObj_Get8(D_00798CAC + 0x2408), a, b);
        D_00218DC0(D_00797EFC);
        xb_xlive_friend_Release(D_003F82CC);
        D_003F82CC = -1;
        xb_xlive_friend_Release(D_003F82D0);
        D_003F82D0 = -1;
        xb_xlive_friend_SetPage(self, 0x17, 0x17);
        *(s32*)(self + 0x8B8) = 0;
        *(s32*)(self + 0x8BC) = 0;
        *(s32*)(self + 4) = 0;
        *(s32*)(self + 0x2A3C) = 2;
        return;

    case 3:
        *(s32*)(self + 4) = 0x14;
        return;
    }
}

void xb_xlive_disp_CheckHandle(s32* handle, f32 a, f32 b, f32 c, f32 d, f32 e);
s32 xb_OnlineObj_Move(s32 id);
u8 xb_OnlineObj_IsDone(s32 id);
u8* XB_FASTCALL xb_LiveWork_Get2408(u8* self);
s32 XB_FASTCALL xb_LiveObj_Process(u8* self, s32 edx, s32 arg);
void XB_STDCALL sub_001D7C05(s32 msg);
extern f32 D_002B4BEC;
extern f32 D_002193F0;
extern f32 D_002B4A34;
extern f32 D_002B4DE4;
extern char* D_007993DC;
extern char* D_007993E4;

/* The voice-message box (D_003F82CC): made, shown and moved in. */
static void xb_xlive_friend_OpenBox(void) {
    xb_xlive_disp_CheckHandle(&D_003F82CC, D_002B4BEC, D_002193F0, D_002B4A34, D_002B4DE4, D_002190A8);
    xb_xlive_disp_SetObj0C(D_003F82CC, 0xFF000000);
    xb_OnlineObj_Move(D_003F82CC);
}

/* xb_XLIVE_FRIEND_CLASS_Step_FD611: the voice-message box opened (+8: 0
 * open, 1 wait, 2 run), then its two pages (+4): the message's choice,
 * which needs the voice peripheral (+0xA84 1, LiveObj_Process 2) or
 * leaves to page 0x13 without it, and the playing page. */
void XB_FASTCALL xb_XLIVE_FRIEND_CLASS_Step_FD611(u8* self, s32 edx, s32 in) {
    XB_ARG a;

    (void)edx;

    switch (*(s32*)(self + 8)) {
    case 0:
        if (D_003F82CC != -1) {
            *(s32*)(self + 8) = 2;
            return;
        }

        xb_xlive_friend_OpenBox();
        (*(s32*)(self + 8))++;
        /* fall through */

    case 1:
        if (xb_OnlineObj_IsDone(D_003F82CC)) {
            (*(s32*)(self + 8))++;
        }

        return;

    case 2:
        break;

    default:
        return;
    }

    switch (*(s32*)(self + 4)) {
    case 1:
        if (in == 1 || in == 4) {
            xb_SeSelectedThunk();
            *(s32*)(self + 4) = 0;
            *(s32*)(self + 8) = 0;
        }

        return;

    case 0:
        if (*(s32*)(self + 0xA84) != 1) {
            return;
        }

        if (in == 0) {
            xb_SeSelectedThunk();
            a.v = *(s32*)(D_00798CAC + 0x14);

            if (((s32 (XB_FASTCALL*)(u8*, XB_ARG))xb_LiveObj_Process)(xb_LiveWork_Get2408(D_00798CAC), a) == 2) {
                *(s32*)(self + 4) = 1;
                *(s32*)(self + 8) = 0;
                return;
            }

            xb_xlive_friend_SetPage(self, 0x13, 0x16);
            *(s32*)(self + 0x2A18) = 0;
            *(s32*)(self + 4) = 0;
            *(s32*)(self + 8) = 0;
            *(s32*)(self + 0x2A5C) = 0xD;
            xb_xlive_friend_Release(D_003F82CC);
        } else if (in == 1 || in == 4) {
            xb_SeSelectedThunk();
            xb_xlive_friend_SetPage(self, 4, 3);
            *(s32*)(self + 0x8B8) = 0;
            *(s32*)(self + 0x8BC) = 0;
            *(s32*)(self + 8) = 0;
        }

        return;
    }
}

/* xb_XLIVE_FRIEND_CLASS_Page_FD785: the box opened (+4: 0 open, 1 wait),
 * then the answer to a message (task +0x2A1C) waited for; its result
 * (+0xA88: accepted or declined) shown, and the message (+0x2A18)
 * destroyed when one was made. */
void XB_FASTCALL xb_XLIVE_FRIEND_CLASS_Page_FD785(u8* self, s32 edx, s32 in) {
    u16 text[0x100];
    s32 hr;
    s32 back;

    (void)edx;
    (void)in;

    switch (*(s32*)(self + 4)) {
    case 0:
        xb_xlive_friend_OpenBox();
        (*(s32*)(self + 4))++;
        /* fall through */

    case 1:
        if (xb_OnlineObj_IsDone(D_003F82CC)) {
            (*(s32*)(self + 4))++;
        }

        return;

    case 2:
        break;

    default:
        return;
    }

    hr = CXBOnlineTask_Continue(self + 0x2A1C);

    if (hr == 0) {
        return;
    }

    if (hr == 0x1500F0) {
        if (*(s32*)(self + 0xA88) == 0) {
            XBUtil_GetWide(D_00799174, text, 0x100);
            xb_xlive_friend_Printf(self + 0x60, text);
        } else if (*(s32*)(self + 0xA88) == 1) {
            XBUtil_GetWide(D_007993DC, text, 0x100);
            xb_xlive_friend_Printf(self + 0x60, text);
        }

        back = *(s32*)(self + 0xA84) != 0;
        xb_xlive_friend_SetPage(self, 0xE, back);
    } else if (*(s32*)(self + 0xA88) == 0) {
        /* retail converts the message without showing it */
        XBUtil_GetWide(D_0079939C, text, 0x100);
        *(s32*)(self + 0x8B8) = 0;
        *(s32*)(self + 0x8BC) = 0;
        xb_xlive_friend_SetPage(self, 0xE, 1);
    } else if (*(s32*)(self + 0xA88) == 1) {
        XBUtil_GetWide(D_007993E4, text, 0x100);
        xb_xlive_friend_Printf(self + 0x60, text);
        xb_xlive_friend_SetPage(self, 0xE, 0x11);
    }

    *(s32*)(self + 0x8B8) = 0;
    *(s32*)(self + 0x8BC) = 0;
    CXBOnlineTask_Close(self + 0x2A1C);

    if (*(s32*)(D_00798CAC + 0x24AC) != 0) {
        sub_001D7C05(*(s32*)(self + 0x2A18));
    }
}

extern char* D_00799308;
extern char* D_007993E8;

/* xb_XLIVE_FRIEND_CLASS_Page_FD942: waiting for a friend action (task
 * work +0x114) to finish; its result shown (D_0079938C, or D_00799378 on
 * an error). */
void XB_FASTCALL xb_XLIVE_FRIEND_CLASS_Page_FD942(u8* self, s32 edx, s32 in) {
    u16 text[0x100];
    s32 hr;
    s32 back;

    (void)edx;
    (void)in;
    hr = CXBOnlineTask_Continue(D_00798CAC + 0x114);

    if (hr == 0) {
        return;
    }

    CXBOnlineTask_Close(D_00798CAC + 0x114);

    if (hr < 0) {
        XBUtil_GetWide(D_00799378, text, 0x100);
        xb_xlive_friend_Printf(self + 0x60, text);
        xb_xlive_main_SetMatchArgs(hr, D_002B4D08, 0xD73, 0);
        xb_xlive_friend_SetPage(self, 0xE, 0x11);
        return;
    }

    XBUtil_GetWide(D_0079938C, text, 0x100);
    xb_xlive_friend_Printf(self + 0x60, text);
    back = *(s32*)(self + 0xA84) != 0;
    xb_xlive_friend_SetPage(self, 0xE, back);
    *(s32*)(self + 0x8B8) = 0;
    *(s32*)(self + 0x8BC) = 0;
}

/* Pages FDA1F and FDAE1: a message task (+0x2A1C) waited for, after a
 * delay (+4 counted down); the message on success, D_007993E4 on an
 * error. */
static void xb_xlive_friend_MessageWait(u8* self, const char* ok) {
    u16 text[0x100];
    s32 hr;
    s32 back;

    hr = CXBOnlineTask_Continue(self + 0x2A1C);

    if (hr == 0) {
        return;
    }

    if (*(s32*)(self + 4) != 0) {
        (*(s32*)(self + 4))--;
        return;
    }

    if (hr == 0x1500F0) {
        XBUtil_GetWide(ok, text, 0x100);
        xb_xlive_friend_Printf(self + 0x60, text);
        *(s32*)(self + 0x8B8) = 0;
        *(s32*)(self + 0x8BC) = 0;
        back = *(s32*)(self + 0xA84) != 0;
        xb_xlive_friend_SetPage(self, 0xE, back);
    } else {
        XBUtil_GetWide(D_007993E4, text, 0x100);
        xb_xlive_friend_Printf(self + 0x60, text);
        xb_xlive_friend_SetPage(self, 0xE, 0x11);
    }

    CXBOnlineTask_Close(self + 0x2A1C);
}

void XB_FASTCALL xb_XLIVE_FRIEND_CLASS_Page_FDA1F(u8* self, s32 edx, s32 in) {
    (void)edx;
    (void)in;
    xb_xlive_friend_MessageWait(self, D_007993E8);
}

void XB_FASTCALL xb_XLIVE_FRIEND_CLASS_Page_FDAE1(u8* self, s32 edx, s32 in) {
    (void)edx;
    (void)in;
    xb_xlive_friend_MessageWait(self, D_00799308);
}

u8* xb_GetMatchInfo(void);
void xb_OnlineObj_Fade(s32 id);
void XB_FASTCALL xb_XLIVE_WORK_CLASS_SetState8(u8* self);
void XB_FASTCALL xb_XLIVE_WORK_CLASS_SetState5(u8* self);

/* xb_XLIVE_FRIEND_CLASS_MatchPage 0xFDBA3: the box (D_003F82CC) asking
 * whether to join the friend's match: opened (0, 1), the answer taken (2;
 * 10 when the match info's +0x17E is clear, which allows only leaving),
 * faded (3, 11) and closed (4, 12): to the match (pages 0x10, Live work
 * state 8, start menu +0x80) or back. */
void XB_FASTCALL xb_XLIVE_FRIEND_CLASS_MatchPage(u8* self, s32 edx, s32 in) {
    u8* info;
    s32 back;
    XB_ARG a;

    (void)edx;
    info = xb_GetMatchInfo();

    switch (*(s32*)(self + 4)) {
    case 0:
        xb_xlive_disp_CheckHandle(&D_003F82CC, D_002B4BEC, D_002193F0, D_002B4A34, D_002B4DE4, D_002190A4);
        xb_xlive_disp_SetObj0C(D_003F82CC, 0xFF000000);
        xb_OnlineObj_Move(D_003F82CC);
        xb_xlive_friend_Release(D_003F82D0);
        D_003F82D0 = -1;
        (*(s32*)(self + 4))++;
        *(s32*)(self + 8) = 0;
        /* fall through */

    case 1:
        if (xb_OnlineObj_IsDone(D_003F82CC)) {
            (*(s32*)(self + 4))++;
        }

        return;

    case 2:
        if (info[0x17E] == 0) {
            *(s32*)(self + 4) = 10;
        }

        if (in == 0) {
            xb_SeSelectedThunk();
            *(s32*)(self + 8) = 1;
            (*(s32*)(self + 4))++;
        } else if (in == 1 || in == 4) {
            xb_SeSelectedThunk();
            *(s32*)(self + 8) = 2;
            (*(s32*)(self + 4))++;
        }

        return;

    case 3:
        xb_OnlineObj_Fade(D_003F82CC);
        (*(s32*)(self + 4))++;
        /* fall through */

    case 4:
        if (!xb_OnlineObj_IsDone(D_003F82CC)) {
            return;
        }

        xb_xlive_friend_Release(D_003F82CC);
        D_003F82CC = -1;

        if (*(s32*)(self + 8) == 1) {
            xb_xlive_friend_SetPage(self, 0x10, 0x10);
            xb_XLIVE_WORK_CLASS_SetState8(D_00798CAC);
            a.v = 1;
            ((void (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_STARTMENU_CLASS_Set80)(D_00798CAC + 0x24C0, a);
        } else {
            *(s32*)(self + 0x8B8) = 0;
            *(s32*)(self + 0x8BC) = 0;
            back = *(s32*)(self + 0xA84) != 0;
            xb_xlive_friend_SetPage(self, back, back);
            xb_XLIVE_WORK_CLASS_SetState5(D_00798CAC);
        }

        *(s32*)(self + 8) = 0;
        *(s32*)(self + 4) = 0;
        return;

    case 10:
        if (in == 1 || in == 4) {
            xb_SeSelectedThunk();
            (*(s32*)(self + 4))++;
        }

        return;

    case 11:
        xb_OnlineObj_Fade(D_003F82CC);
        (*(s32*)(self + 4))++;
        return;

    case 12:
        if (!xb_OnlineObj_IsDone(D_003F82CC)) {
            return;
        }

        xb_xlive_friend_Release(D_003F82CC);
        D_003F82CC = -1;
        back = *(s32*)(self + 0xA84) != 0;
        *(s32*)(self + 0x8B8) = 0;
        *(s32*)(self + 0x8BC) = 0;
        xb_xlive_friend_SetPage(self, back, back);
        *(s32*)(self + 8) = 0;
        *(s32*)(self + 4) = 0;
        return;
    }
}

void XB_FASTCALL xb_XLIVE_STAT_CLASS_Clear(u8* self);

/* xb_XLIVE_FRIEND_CLASS_Step_FDDC6: a yes/no box (D_003F82CC): opened (0,
 * 1), answered (2), faded (3) and closed (4): yes to page 0x20, no back
 * to page 2. */
void XB_FASTCALL xb_XLIVE_FRIEND_CLASS_Step_FDDC6(u8* self, s32 edx, s32 in) {
    (void)edx;

    switch (*(s32*)(self + 4)) {
    case 0:
        xb_xlive_disp_CheckHandle(&D_003F82CC, D_002B4BEC, D_002193F0, D_002B4A34, D_002B4DE4, D_002190A4);
        xb_xlive_disp_SetObj0C(D_003F82CC, 0xFF000000);
        xb_OnlineObj_Move(D_003F82CC);
        (*(s32*)(self + 4))++;
        *(s32*)(self + 8) = 0;
        /* fall through */

    case 1:
        if (xb_OnlineObj_IsDone(D_003F82CC)) {
            (*(s32*)(self + 4))++;
        }

        return;

    case 2:
        if (in == 0) {
            xb_SeSelectedThunk();
            *(s32*)(self + 8) = 1;
            (*(s32*)(self + 4))++;
        } else if (in == 1 || in == 4) {
            xb_SeSelectedThunk();
            *(s32*)(self + 8) = 2;
            (*(s32*)(self + 4))++;
        }

        return;

    case 3:
        xb_OnlineObj_Fade(D_003F82CC);
        (*(s32*)(self + 4))++;
        /* fall through */

    case 4:
        if (!xb_OnlineObj_IsDone(D_003F82CC)) {
            return;
        }

        xb_xlive_friend_Release(D_003F82CC);
        D_003F82CC = -1;

        if (*(s32*)(self + 8) == 1) {
            xb_xlive_friend_SetPage(self, 0x20, 0x20);
        } else {
            *(s32*)(self + 0x8B8) = 0;
            *(s32*)(self + 0x8BC) = 0;
            xb_xlive_friend_SetPage(self, 2, 2);
        }

        *(s32*)(self + 8) = 0;
        *(s32*)(self + 4) = 0;
        return;
    }
}

/* xb_XLIVE_FRIEND_CLASS_Session_Update 0xFDEFF: the friend window closed:
 * the voice lock left when the voice page held it, the friend tasks
 * closed, the statistics cleared, and the page rectangles released. */
void XB_FASTCALL xb_XLIVE_FRIEND_CLASS_Session_Update(u8* self) {
    if (*(s32*)(self + 0x8B0) == 0x13 && *(s32*)(self + 4) == 1) {
        D_00218DC0(D_00797EFC);
    }

    CXBOnlineTask_Close(D_00798CAC + 0x110);
    CXBOnlineTask_Close(D_00798CAC + 0x118);
    CXBOnlineTask_Close(D_00798CAC + 0x11C);
    CXBOnlineTask_Close(D_00798CAC + 0x114);
    xb_xlive_friend_SetPage(self, 0x10, 0x10);
    xb_XLIVE_STAT_CLASS_Clear(D_00798CAC + 0x5538);
    *(s32*)(self + 0x8B8) = 0;
    *(s32*)(self + 0x8BC) = 0;
    xb_xlive_friend_Release(D_003F82C0);
    xb_xlive_friend_Release(D_003F82C4);
    xb_xlive_friend_Release(D_003F82C8);
    xb_xlive_friend_Release(D_003F82CC);
    D_003F82CC = -1;
    D_003F82C8 = -1;
    D_003F82C4 = -1;
    D_003F82C0 = -1;
}

void* XB_STDCALL XPhysicalAlloc(u32 size, u32 max, u32 align, u32 protect);
void XB_STDCALL XPhysicalFree(void* p);
s32 wsprintfW(u16* buf, const u16* fmt, ...);
u16* XB_STDCALL lstrcatW(u16* a, const u16* b);
s32 XB_FASTCALL xb_XLIVE_WORK_CLASS_CloseMatchTask(u8* self);
void XB_FASTCALL xb_XLIVE_WORK_CLASS_SetMatchDone(u8* self);
void XB_FASTCALL xb_XLIVE_WORK_CLASS_ReleaseWindows(u8* self);
s32 XB_STDCALL sub_001D5272(s32 state);
void sub_0011EF42(s32 mode);
void** XB_FASTCALL sub_000FCC47(void** self, s32 edx, u32 n);
s32 XB_FASTCALL xb_xlive_ThunkFC23E(u8* self);
s32 xb_GetOnlineFlagThunk(void);
extern char* D_007990F4;
extern u16 D_002B4DE8[];

/* xb_XLIVE_FRIEND_CLASS_FriendAt 0xFDFD2: the friend list's i-th entry. */
u8* XB_FASTCALL xb_XLIVE_FRIEND_CLASS_FriendAt(u8* self, s32 edx, u32 i) {
    void* it;
    void** p;
    XB_ARG a;

    a.v = (s32)&it;
    p = (void**)((void* (XB_FASTCALL*)(u8*, XB_ARG))xb_xlive_friend_GetElem4)(self, a);
    a.v = i;
    p = ((void** (XB_FASTCALL*)(void**, XB_ARG))sub_000FCC47)(p, a);
    return (u8*)xb_xlive_ThunkFC23E((u8*)p);
}

/* xb_XLIVE_FRIEND_CLASS_Session_Step 0xFE14F: the friend window opened
 * for a mode (+0x58; 3 and up open it from the match, +0xA84): its state
 * cleared, a voice-mail buffer allocated (+0x2A2C, 0x499A bytes), the
 * friends enumerated, and the match task closed. */
s32 XB_FASTCALL xb_XLIVE_FRIEND_CLASS_Session_Step(u8* self, s32 edx, s32 mode) {
    u16 text[0x100];
    s32 hr;

    (void)edx;
    memset(self + 4, 0, 0x50);
    *(u32*)(self + 0x2A30) = 0x499A;

    if (*(void**)(self + 0x2A2C) != 0) {
        XPhysicalFree(*(void**)(self + 0x2A2C));
    }

    *(void**)(self + 0x2A2C) = XPhysicalAlloc(*(u32*)(self + 0x2A30), 0xFFFFFFFF, 0x1000, 4);
    memset(*(void**)(self + 0x2A2C), 0, *(u32*)(self + 0x2A30));
    *(s32*)(self + 0x2A18) = 0;
    *(s32*)(self + 0xA8C) = -1;
    *(s32*)(self + 0xA90) = -1;
    xb_xlive_friend_Release(D_003F82C0);
    xb_xlive_friend_Release(D_003F82C4);
    xb_xlive_friend_Release(D_003F82C8);
    D_003F82C8 = -1;
    D_003F82C4 = -1;
    D_003F82C0 = -1;
    *(s32*)(self + 0x58) = mode;
    *(s32*)(self + 0xA84) = mode >= 3;
    xb_XLIVE_FRIEND_CLASS_Session_Update(self);
    xb_xlive_friend_SetPage(self, 5, 5);
    *(s32*)(self + 0xA80) = 0;
    *(s32*)(self + 0x2AB4) = 0x3C;
    *(s32*)(self + 0x2AB8) = 0;

    if (xb_iterator_Deref(D_00798CAC + 0x110) != 0) {
        CXBOnlineTask_Close(D_00798CAC + 0x110);
    }

    hr = XOnlineFriendsEnumerate(*(s32*)(self + 0x5C), 0, CXBOnlineTask_operator_addr(D_00798CAC + 0x110));

    if (hr < 0) {
        xb_xlive_friend_Error(self, hr, 0xEB, D_0079933C);
    }

    if (xb_XLIVE_WORK_CLASS_CloseMatchTask(D_00798CAC) == -1) {
        XBUtil_GetWide(D_0079933C, text, 0x100);
        xb_xlive_friend_Printf(self + 0x60, text);
        xb_xlive_friend_SetPage(self, 0xE, 0x10);
    }

    return 0;
}

/* xb_XLIVE_FRIEND_CLASS_Page_FE321: joining the chosen friend's game
 * (+0x8C4): when the friend's session can be joined its record goes to
 * the Live work (+0x168) and the match starts (online, or from the menus
 * with the mode set); otherwise the friend's name is shown with
 * D_007990F4. */
void XB_FASTCALL xb_XLIVE_FRIEND_CLASS_Page_FE321(u8* self, s32 edx, s32 in) {
    u16 text[0x100];
    u16 name[0x100];
    u8* f;
    s32 back;
    XB_ARG a;

    (void)edx;
    (void)in;
    a.v = *(s32*)(self + 0x8C4);
    f = ((u8* (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_FRIEND_CLASS_FriendAt)(self + 0x860, a);

    if (sub_001D5272(*(s32*)(f + 0x30)) == 0) {
        XBUtil_GetWide(D_007990F4, text, 0x100);
        wsprintfW(name, D_002B4DE8, 0x100, self + 0x2A64);
        lstrcatW(name, text);
        xb_xlive_friend_Printf(self + 0x60, name);
        back = *(s32*)(self + 0xA84) != 0;
        xb_xlive_friend_SetPage(self, 0xE, back);
        return;
    }

    a.v = *(s32*)(self + 0x8C4);
    f = ((u8* (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_FRIEND_CLASS_FriendAt)(self + 0x860, a);
    memcpy(D_00798CAC + 0x168, f, 0x56);

    if (xb_GetOnlineFlagThunk() != 0) {
        sub_0011EF42(1);
    } else {
        if (*(s32*)(self + 0x58) == 1 || *(s32*)(self + 0x58) == 4) {
            *(s32*)(D_00798CAC + 0x164) = 3;
        }

        if (*(s32*)(D_00798CAC + 0x3E0) != 0) {
            *(s32*)(D_00798CAC + 0x164) = 1;
        }

        xb_XLIVE_WORK_CLASS_SetMatchDone(D_00798CAC);
    }

    a.v = 1;
    ((void (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_STARTMENU_CLASS_Set80)(D_00798CAC + 0x24C0, a);
    xb_XLIVE_FRIEND_CLASS_Session_Update(self);
    xb_XLIVE_WORK_CLASS_ReleaseWindows(D_00798CAC);
    xb_XLIVE_STAT_CLASS_Clear(D_00798CAC + 0x5090);
    xb_xlive_friend_SetPage(self, 0x10, 0x10);
}
