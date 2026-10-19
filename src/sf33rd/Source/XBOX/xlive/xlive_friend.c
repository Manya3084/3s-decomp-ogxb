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
s32 xb_xlive_main_SetMatchArgs(s32 hr, const char* file, s32 line, s32 a);
s32 XB_FASTCALL CXBOnlineTask_Close(void* self);
void XB_FASTCALL xb_vector_FRIEND_DestroyThunk(void* self);
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

/* xb_XLIVE_FRIEND_CLASS_PollTask10C 0xFBBB5: the work's task at +0x10C
 * polled while open; closed on an error, which is returned. */
s32 XB_FASTCALL CXBOnlineTask_Continue(void* self);
s32 XB_FASTCALL xb_iterator_Deref(u8* self);
s32 XB_FASTCALL CXBOnlineTask_Close(void* self);

s32 XB_FASTCALL xb_XLIVE_FRIEND_CLASS_PollTask10C(u8* self) {
    s32 hr = 0;

    if (xb_iterator_Deref(D_00798CAC + 0x10C) != 0) {
        hr = CXBOnlineTask_Continue(D_00798CAC + 0x10C);

        if (hr < 0) {
            CXBOnlineTask_Close(D_00798CAC + 0x10C);
        }
    }

    return hr;
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

    xb_vector_FRIEND_DestroyThunk(self + 0x860);
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

s32 XB_STDCALL XHVEngine_VoiceMailRecord(s32 engine, s32 port, u32 ms, u32 size, void* data);
s32 XB_STDCALL XHVEngine_VoiceMailPlay(s32 engine, s32 port, u32 len, void* data, u32 size);
s32 XB_STDCALL XHVEngine_VoiceMailStop(s32 engine, s32 port);
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
    return XHVEngine_VoiceMailRecord(engine, port, ms, size, data);
}

s32 XB_STDCALL IXHVEngine__VoiceMailPlay(s32 engine, s32 port, u32 len, void* data, u32 size) {
    return XHVEngine_VoiceMailPlay(engine, port, len, data, size);
}

s32 XB_STDCALL IXHVEngine__VoiceMailStop(s32 engine, s32 port) {
    return XHVEngine_VoiceMailStop(engine, port);
}

/* The engine: the voice chat object (work +0x2408)'s +4. */
#define xb_xlive_friend_Engine() xb_iterator_Get4(xb_LiveObj_Get8(D_00798CAC + 0x2408))

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

/* The page change: Session_SetArgs(page, next). */
#define xb_xlive_friend_SetPage(self, page, next)                                                        \
    do {                                                                                                 \
        XB_ARG pa_;                                                                                      \
        XB_ARG pb_;                                                                                      \
        pa_.v = (page);                                                                                  \
        pb_.v = (next);                                                                                  \
        ((void (XB_FASTCALL*)(u8*, XB_ARG, XB_ARG))xb_XLIVE_FRIEND_CLASS_Session_SetArgs)((self), pa_, pb_); \
    } while (0)

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
void xb_OnlineObj_Move(s32 id);
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
void xb_xlive_select_Enter(s32 mode);
void** XB_FASTCALL xb_vector60_IterAdd(void** self, s32 edx, u32 n);
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
    p = ((void** (XB_FASTCALL*)(void**, XB_ARG))xb_vector60_IterAdd)(p, a);
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
        xb_xlive_select_Enter(1);
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

s32 XB_FASTCALL xb_XLIVE_FRIEND_CLASS_SendFriendAction(u8* self, s32 edx, s32 msg, s32 task);
s32 XB_STDCALL IXHVEngine__GetProcessingMode(s32 a, s32 b, s32 c);
void XB_FASTCALL CXBStopWatch_Reset(void* self);
f32 XB_FASTCALL CXBStopWatch_GetElapsedSeconds(void* self);
f32 XB_FASTCALL CXBStopWatch_GetElapsedMilliseconds(void* self);
s32 XB_STDCALL XOnlineMessageCreate(s32 type, s32 nprops, s32 a, s32 b, s32 c, s32 d, s32 e, s32* msg);
s32 XB_STDCALL sub_001D7C10(s32 msg, s32 prop, s32 type, s32 value, s32 flags);
s32 XB_STDCALL XOnlineGameInviteSend(s32 user, s32 n, u8* friends, s32 sess_lo, s32 sess_hi, s32 flags, s32 msg, s32 ev,
                                     s32 task);
extern s32 D_00798C50;
extern char D_0025CCA0[];
extern s32 D_002BA7A8;
extern f32 D_00219428;
extern f32 D_002B4E00;
extern f32 D_002B4DFC;
extern f32 D_002B4DF4;
extern f32 D_002B4DF8;
extern f32 D_00219404;
extern f32 D_002190F4;

/* xb_XLIVE_FRIEND_CLASS_SendInvite 0xFBC68: a game invite for the current
 * session (work +0xB4) sent to one friend, with a voice message. */
s32 XB_FASTCALL xb_XLIVE_FRIEND_CLASS_SendInvite(u8* self, s32 edx, s32 user, u8* f, s32 msg, s32 task) {
    (void)self;
    (void)edx;
    return XOnlineGameInviteSend(user, 1, f, *(s32*)(D_00798CAC + 0xB4), *(s32*)(D_00798CAC + 0xB8), 0, msg, 0, task);
}

/* The voice-mail stopwatch (+0x890). */
#define XB_FRIEND_SW(self) ((self) + 0x890)

/* A received friend action's result shown: sent, the list full, already a
 * friend, or failed; 0 goes on to page 0x16. */
static void xb_xlive_friend_ActionResult(u8* self, s32 r) {
    u16 text[0x100];

    if (r == 0) {
        xb_xlive_friend_SetPage(self, 0x16, 0x16);
        return;
    }

    if (r == (s32)0x80152002) {
        XBUtil_GetWide(D_007991D4, text, 0x100);
    } else if (r == (s32)0x80152007) {
        XBUtil_GetWide(D_007992B0, text, 0x100);
    } else {
        XBUtil_GetWide(D_0079939C, text, 0x100);
    }

    xb_xlive_friend_Printf(self + 0x60, text);
    *(s32*)(self + 0x8B8) = 0;
    *(s32*)(self + 0x8BC) = 0;
    xb_xlive_friend_SetPage(self, 0xE, 1);
}

/* The invite or friend action (+0xA88: 0 an action, 1 an invite) sent,
 * with the voice message msg (0 for none). */
static void xb_xlive_friend_Send(u8* self, s32 msg, s32 line) {
    XB_ARG a;
    XB_ARG b;
    XB_ARG c;
    XB_ARG d;
    u8* f;

    switch (*(s32*)(self + 0xA88)) {
    case 0:
        a.v = msg;
        b.v = CXBOnlineTask_operator_addr(self + 0x2A1C);
        xb_xlive_friend_ActionResult(self, ((s32 (XB_FASTCALL*)(u8*, XB_ARG, XB_ARG))xb_XLIVE_FRIEND_CLASS_SendFriendAction)(self, a, b));
        return;

    case 1:
        d.v = CXBOnlineTask_operator_addr(self + 0x2A1C);
        a.v = *(s32*)(self + 0x8C4);
        f = ((u8* (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_FRIEND_CLASS_FriendAt)(self + 0x860, a);
        a.v = *(s32*)(D_00798CAC + 0x14);
        b.v = (s32)f;
        c.v = msg;
        ((s32 (XB_FASTCALL*)(u8*, XB_ARG, XB_ARG, XB_ARG, XB_ARG))xb_XLIVE_FRIEND_CLASS_SendInvite)(self, a, b, c, d);
        xb_xlive_friend_SetPage(self, 0x16, 0x16);
        return;
    }

    _assert(D_0025CCA0, D_002B4D08, line);
}

/* xb_XLIVE_FRIEND_CLASS_Page_FE486: composing a voice message for an
 * invite or friend action: the two boxes opened (0, 1; the voice lock is
 * held while they open), the message recorded (10), played back (0x14)
 * and chosen (3, with the voice-mail actions), the boxes faded (4) and
 * closed back to page 2 (5), and the message sent (0x1E): as an
 * XOnline message with the voice data when one was recorded. */
void XB_FASTCALL xb_XLIVE_FRIEND_CLASS_Page_FE486(u8* self, s32 edx, s32 in) {
    s32 one;
    s32 len;
    s32 st;
    f32 n;
    f32 ms;
    XB_ARG a;
    XB_ARG b;

    (void)edx;

    switch (*(s32*)(self + 4)) {
    case 0:
        D_00218DC4(D_00797EFC);
        xb_xlive_disp_CheckHandle(&D_003F82CC, D_00219428, D_002B4BEC, D_002B4E00, D_00219404, D_002190A8);
        xb_xlive_disp_SetObj0C(D_003F82CC, 0xFF000000);
        xb_OnlineObj_Move(D_003F82CC);
        xb_xlive_disp_CheckHandle(&D_003F82D0, D_002B4BEC, D_002B4DFC, D_002B4A34, D_002B4DE4, D_002190A8);
        xb_xlive_disp_SetObj0C(D_003F82D0, 0xFF000000);
        xb_OnlineObj_Move(D_003F82D0);
        *(s32*)(self + 0x8B8) = 0;
        memset(*(void**)(self + 0x2A2C), 0, *(u32*)(self + 0x2A30));
        IXHVEngine__GetProcessingMode(xb_xlive_friend_Engine(), *(s32*)(D_00798CAC + 0x14), (s32)(self + 0x2A60));
        a.v = *(s32*)(D_00798CAC + 0x14);
        b.v = D_002BA7A8;
        ((s32 (XB_FASTCALL*)(u8*, XB_ARG, XB_ARG))xb_LiveObj_Call2)(xb_LiveObj_Get8(D_00798CAC + 0x2408), a, b);
        *(s32*)(D_00798CAC + 0x24AC) = 0;
        *(s32*)(D_00798CAC + 0x24A8) = 0;
        *(f32*)(D_00798CAC + 0x24B0) = 0.0f;
        *(f32*)(D_00798CAC + 0x24B4) = D_002B4DCC;
        CXBStopWatch_Stop(XB_FRIEND_SW(self));
        CXBStopWatch_Reset(XB_FRIEND_SW(self));
        *(f32*)(self + 0x2A40) = CXBStopWatch_GetElapsedSeconds(XB_FRIEND_SW(self));
        (*(s32*)(self + 4))++;
        /* fall through */

    case 1:
        if (!xb_OnlineObj_IsDone(D_003F82CC)) {
            return;
        }

        (*(s32*)(self + 4))++;
        D_00218DC0(D_00797EFC);
        st = 0;
        break;

    case 2:
        *(s32*)(self + 4) = 3;
        /* fall through */

    case 3:
        if (D_00798C50 != 0) {
            D_00218DC4(D_00797EFC);
            a.v = *(s32*)(D_00798CAC + 0x14);
            b.v = D_002BA7A8;
            ((s32 (XB_FASTCALL*)(u8*, XB_ARG, XB_ARG))xb_LiveObj_Call2)(xb_LiveObj_Get8(D_00798CAC + 0x2408), a, b);
            D_00218DC0(D_00797EFC);
            D_00798C50 = 0;
        }

        a.v = *(s32*)(D_00798CAC + 0x14);

        if (((s32 (XB_FASTCALL*)(u8*, XB_ARG))xb_LiveObj_Process)(xb_LiveWork_Get2408(D_00798CAC), a) == 2) {
            D_00798C50 = 1;
            st = *(f32*)(D_00798CAC + 0x24B4) == D_002B4DCC ? 4 : 5;
        } else {
            st = *(f32*)(D_00798CAC + 0x24B4) == D_002B4DCC ? 0 : 2;
        }

        a.v = st;
        ((void (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_FRIEND_CLASS_SetMailState)(self, a);
        a.v = in;
        ((void (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_FRIEND_CLASS_Update)(self, a);

        if (in == 1 || in == 4) {
            xb_SeSelectedThunk();
            *(s32*)(self + 4) = 4;
        }

        return;

    case 4:
        D_00218DC4(D_00797EFC);
        IXHVEngine__VoiceMailStop(xb_xlive_friend_Engine(), *(s32*)(D_00798CAC + 0x14));
        a.v = *(s32*)(D_00798CAC + 0x14);
        b.v = *(s32*)(self + 0x2A60);
        ((s32 (XB_FASTCALL*)(u8*, XB_ARG, XB_ARG))xb_LiveObj_Call2)(xb_LiveObj_Get8(D_00798CAC + 0x2408), a, b);
        D_00218DC0(D_00797EFC);
        xb_OnlineObj_Fade(D_003F82CC);
        xb_OnlineObj_Fade(D_003F82D0);
        (*(s32*)(self + 4))++;
        return;

    case 5:
        if (!xb_OnlineObj_IsDone(D_003F82CC)) {
            return;
        }

        xb_xlive_friend_Release(D_003F82CC);
        D_003F82CC = -1;
        xb_xlive_friend_Release(D_003F82D0);
        D_003F82D0 = -1;
        *(s32*)(self + 4) = 0;
        xb_xlive_friend_SetPage(self, 2, 2);
        return;

    case 10:
        a.v = in;
        ((void (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_FRIEND_CLASS_Update)(self, a);
        *(f32*)(D_00798CAC + 0x24B0) = CXBStopWatch_GetElapsedSeconds(XB_FRIEND_SW(self)) * D_002B4DF4;

        if (*(f32*)(D_00798CAC + 0x24B0) > D_002B4DF8) {
            *(f32*)(D_00798CAC + 0x24B0) = D_002B4DF8;
        }

        *(f32*)(self + 0x2A40) = CXBStopWatch_GetElapsedSeconds(XB_FRIEND_SW(self));
        *(f32*)(D_00798CAC + 0x24B4) = D_002B4DCC - CXBStopWatch_GetElapsedSeconds(XB_FRIEND_SW(self));

        if (*(s32*)(D_00798CAC + 0x24A0) != 0) {
            *(s32*)(self + 4) = 3;
            CXBStopWatch_Stop(XB_FRIEND_SW(self));
            a.v = 2;
            ((void (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_FRIEND_CLASS_SetMailState)(self, a);
        }

        a.v = *(s32*)(D_00798CAC + 0x14);

        if (((s32 (XB_FASTCALL*)(u8*, XB_ARG))xb_LiveObj_Process)(xb_LiveWork_Get2408(D_00798CAC), a) != 2) {
            return;
        }

        *(s32*)(self + 4) = 3;
        memset(*(void**)(self + 0x2A2C), 0, *(u32*)(self + 0x2A30));
        D_00798C50 = 1;
        D_00218DC4(D_00797EFC);
        *(s32*)(D_00798CAC + 0x24AC) = 0;
        *(s32*)(D_00798CAC + 0x24A8) = 0;
        IXHVEngine__VoiceMailStop(xb_xlive_friend_Engine(), *(s32*)(D_00798CAC + 0x14));
        D_00218DC0(D_00797EFC);
        *(f32*)(D_00798CAC + 0x24B0) = 0.0f;
        *(f32*)(D_00798CAC + 0x24B4) = D_002B4DCC;
        CXBStopWatch_Stop(XB_FRIEND_SW(self));
        CXBStopWatch_Reset(XB_FRIEND_SW(self));
        *(f32*)(self + 0x2A40) = CXBStopWatch_GetElapsedSeconds(XB_FRIEND_SW(self));
        st = 4;
        break;

    case 0x14:
        a.v = *(s32*)(D_00798CAC + 0x14);

        if (((s32 (XB_FASTCALL*)(u8*, XB_ARG))xb_LiveObj_Process)(xb_LiveWork_Get2408(D_00798CAC), a) == 2) {
            D_00798C50 = 1;
        }

        a.v = in;
        ((void (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_FRIEND_CLASS_Update)(self, a);
        ms = CXBStopWatch_GetElapsedMilliseconds(XB_FRIEND_SW(self));
        len = *(s32*)(D_00798CAC + 0x24A8);
        n = (f32)len;

        if (len < 0) {
            n += D_002190F4;
        }

        *(f32*)(D_00798CAC + 0x24B0) = ms * (D_002B4DF8 / n);
        len = *(s32*)(D_00798CAC + 0x24A8);
        n = (f32)len;

        if (len < 0) {
            n += D_002190F4;
        }

        n = n / D_00219620;
        *(f32*)(D_00798CAC + 0x24B4) = n - CXBStopWatch_GetElapsedSeconds(XB_FRIEND_SW(self));

        if (*(f32*)(D_00798CAC + 0x24B0) > D_002B4DF8) {
            *(f32*)(D_00798CAC + 0x24B0) = D_002B4DF8;
        }

        if (*(s32*)(D_00798CAC + 0x24A4) == 0) {
            return;
        }

        *(s32*)(self + 4) = 3;
        CXBStopWatch_Stop(XB_FRIEND_SW(self));
        st = 2;
        break;

    case 0x1E:
        if (*(s32*)(self + 0x2AB8) > 0) {
            (*(s32*)(self + 0x2AB8))--;
            return;
        }

        *(s32*)(self + 0x2AB8) = 0;
        xb_xlive_friend_Release(D_003F82CC);
        D_003F82CC = -1;
        xb_xlive_friend_Release(D_003F82D0);
        D_003F82D0 = -1;
        *(s32*)(self + 4) = 0;

        if (*(s32*)(D_00798CAC + 0x24AC) == 0) {
            xb_xlive_friend_Send(self, 0, 0xA00);
            return;
        }

        switch (*(s32*)(self + 0xA88)) {
        case 0:
            XOnlineMessageCreate(2, 3, 0, 0, 0, 4, 0, (s32*)(self + 0x2A18));
            break;

        case 1:
            XOnlineMessageCreate(3, 4, 0, 0, 0, 4, 0, (s32*)(self + 0x2A18));
            sub_001D7C10(*(s32*)(self + 0x2A18), 0x581, 8, (s32)(D_00798CAC + 0xB4), 0);
            break;

        default:
            _assert(D_0025CCA0, D_002B4D08, 0xA1B);
            break;
        }

        one = 1;
        D_00218DC4(D_00797EFC);
        sub_001D7C10(*(s32*)(self + 0x2A18), 0x9C1, *(s32*)(D_00798CAC + 0x24AC), *(s32*)(self + 0x2A2C), 0);
        sub_001D7C10(*(s32*)(self + 0x2A18), 0x3C2, 2, (s32)&one, 0);
        len = *(s32*)(D_00798CAC + 0x24A8);
        sub_001D7C10(*(s32*)(self + 0x2A18), 0x4C3, 4, (s32)&len, 0);
        D_00218DC0(D_00797EFC);
        CXBOnlineTask_Close(self + 0x2A1C);
        xb_xlive_friend_Send(self, *(s32*)(self + 0x2A18), 0xA5C);
        return;

    default:
        return;
    }

    a.v = st;
    ((void (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_FRIEND_CLASS_SetMailState)(self, a);
}

s32 XB_STDCALL XOnlineFriendsGameInvite(s32 user, s32 sess_lo, s32 sess_hi, s32 n, u8* friends);
s32 swprintf(u16* buf, const u16* fmt, ...);
extern s32 D_003F82F4[];
extern s32 D_00798C54;
extern s32 D_00798C58;
extern u16 D_00219430[];
extern f32 D_00219098;
extern f32 D_002B4CF4;
extern f32 D_002B4E04;

/* xb_XLIVE_FRIEND_CLASS_GameInvite 0xFBC45: the current session (work
 * +0xB4) offered to one friend. */
s32 XB_FASTCALL xb_XLIVE_FRIEND_CLASS_GameInvite(u8* self, s32 edx, s32 user, u8* f) {
    (void)self;
    (void)edx;
    return XOnlineFriendsGameInvite(user, *(s32*)(D_00798CAC + 0xB4), *(s32*)(D_00798CAC + 0xB8), 1, f);
}

/* xb_XLIVE_FRIEND_CLASS_Page_FED22: the box opened (+8, as in Step_FD611),
 * then the invite choice (+4): invite with a voice message (needs the
 * voice peripheral, else page 0x13), or a plain game invite (the result
 * shown). */
void XB_FASTCALL xb_XLIVE_FRIEND_CLASS_Page_FED22(u8* self, s32 edx, s32 in) {
    u16 text[0x100];
    s32 r;
    s32 back;
    u8* f;
    XB_ARG a;
    XB_ARG b;

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
        if (*(s32*)(self + 0xA84) != 1 && *(s32*)(self + 0xA84) != 0) {
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
            *(s32*)(self + 0x2A5C) = 0;
            xb_xlive_friend_Release(D_003F82CC);
            return;
        }

        if (in != 1 && in != 4) {
            return;
        }

        xb_SeSelectedThunk();
        a.v = *(s32*)(self + 0x8C4);
        f = ((u8* (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_FRIEND_CLASS_FriendAt)(self + 0x860, a);
        a.v = *(s32*)(self + 0x5C);
        b.v = (s32)f;
        r = ((s32 (XB_FASTCALL*)(u8*, XB_ARG, XB_ARG))xb_XLIVE_FRIEND_CLASS_GameInvite)(self, a, b);

        if (r < 0) {
            XBUtil_GetWide(D_007993E4, text, 0x100);
            xb_xlive_friend_Printf(self + 0x60, text);
            xb_xlive_friend_SetPage(self, 0xE, 0x11);
        } else {
            XBUtil_GetWide(D_007993DC, text, 0x100);
            xb_xlive_friend_Printf(self + 0x60, text);
            back = *(s32*)(self + 0xA84) != 0;
            *(s32*)(self + 0x8B8) = 0;
            *(s32*)(self + 0x8BC) = 0;
            xb_xlive_friend_SetPage(self, 0xE, back);
        }

        *(s32*)(self + 8) = 0;
        return;
    }
}

/* xb_XLIVE_FRIEND_CLASS_Page_FEF2D: feedback about a friend from the
 * friend list: the box opened (0, 1), a complaint chosen and confirmed
 * (2, +0x8BC) and sent with the friend's name, the box faded (3) and
 * closed (4) to the pages kept in D_00798C54 and D_00798C58. */
void XB_FASTCALL xb_XLIVE_FRIEND_CLASS_Page_FEF2D(u8* self, s32 edx, s32 in) {
    u16 text[0x100];
    u16 name[0x10];
    void* pname;
    u8* f;
    s32 hr;
    XB_ARG a;

    (void)edx;

    switch (*(s32*)(self + 4)) {
    case 0:
        xb_xlive_disp_CheckHandle(&D_003F82CC, D_00219098, D_002B4CF4, D_002B4E04, D_002B4DFC, D_002190A8);
        xb_xlive_disp_SetObj0C(D_003F82CC, 0xFF000000);
        xb_OnlineObj_Move(D_003F82CC);
        (*(s32*)(self + 4))++;
        /* fall through */

    case 1:
        if (xb_OnlineObj_IsDone(D_003F82CC)) {
            (*(s32*)(self + 4))++;
            *(s32*)(self + 0x8B8) = 0;
        }

        return;

    case 2:
        if (*(s32*)(self + 0x8BC) == 0) {
            if (in == 0) {
                xb_SeSelectedThunk();
                *(s32*)(self + 0x8BC) = 1;
            } else if (in == 1 || in == 4) {
                xb_SeSelectedThunk();
                (*(s32*)(self + 4))++;
                D_00798C54 = 0x12;
                D_00798C58 = 0x12;
            }

            return;
        }

        if (in == 1 || in == 4) {
            xb_SeSelectedThunk();
            *(s32*)(self + 0x8BC) = 0;
            return;
        }

        if (in != 0) {
            return;
        }

        a.v = *(s32*)(self + 0x8C4);
        swprintf(name, D_00219430, ((u8* (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_FRIEND_CLASS_FriendAt)(self + 0x860, a) + 0xC);
        pname = name;
        xb_SeSelectedThunk();
        a.v = *(s32*)(self + 0x8C4);
        f = ((u8* (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_FRIEND_CLASS_FriendAt)(self + 0x860, a);
        hr = XOnlineFeedbackSend(*(s32*)(D_00798CAC + 0x14), *(XB_FXUID*)f, D_003F82F4[*(s32*)(self + 0x8B8)], &pname, 0,
                                 CXBOnlineTask_operator_addr(D_00798CAC + 0x114));

        if (hr < 0) {
            xb_xlive_main_SetMatchArgs(hr, D_002B4D08, 0xD1F, 0);
            XBUtil_GetWide(D_00799378, text, 0x100);
            xb_xlive_friend_Printf(self + 0x60, text);
            xb_xlive_friend_Release(D_003F82CC);
            D_003F82CC = -1;
            xb_xlive_friend_SetPage(self, 0xE, 0x11);
            return;
        }

        (*(s32*)(self + 4))++;
        D_00798C54 = 0x18;
        D_00798C58 = 0x18;
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
        xb_xlive_friend_SetPage(self, D_00798C54, D_00798C58);
        *(s32*)(self + 0x8BC) = 0;
        *(s32*)(self + 4) = 0;
        *(s32*)(self + 0x8B8) = 0;
        return;
    }
}

u32 XB_FASTCALL std__vector_Elem60__size(void* self);
s32 XB_STDCALL XOnlineFriendsRevokeGameInvite(s32 user, s32 sess_lo, s32 sess_hi, s32 n, u8* friends);
s32 XB_STDCALL sub_001D5352(s32 user, u8* f, s32 a);
s32 XB_STDCALL sub_001D535D(s32 user, u8* f, s32 a);
s32 XB_STDCALL sub_001D5368(s32 user, u8* f);
s32 XB_STDCALL sub_001D626C(s32 user, u8* rec, s32 a, s32 b, s32 c);
extern char D_002B4E08[];

/* The chosen friend (+0x8C4), asserted in the list. */
static u8* xb_xlive_friend_Current(u8* self, s32 line) {
    XB_ARG a;

    if (*(u32*)(self + 0x8C4) >= std__vector_Elem60__size(self + 0x860)) {
        _assert(D_002B4E08, D_002B4D08, line);
    }

    a.v = *(s32*)(self + 0x8C4);
    return ((u8* (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_FRIEND_CLASS_FriendAt)(self + 0x860, a);
}

/* Whether a friend other than the chosen one has the flag (+0x1F). */
static s32 xb_xlive_friend_OtherHas(u8* self, u8 flag) {
    s32 i;
    s32 any = 0;
    XB_ARG a;

    for (i = 0; i < (s32)std__vector_Elem60__size(self + 0x860); i++) {
        if (i == *(s32*)(self + 0x8C4)) {
            continue;
        }

        a.v = i;

        if (((u8* (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_FRIEND_CLASS_FriendAt)(self + 0x860, a)[0x1F] & flag) {
            any = 1;
        }
    }

    return any;
}

/* xb_XLIVE_FRIEND_CLASS_GetCurrFriend 0xFF297: the invite to the chosen
 * friend revoked. */
s32 XB_FASTCALL xb_XLIVE_FRIEND_CLASS_GetCurrFriend(u8* self) {
    u8* f = xb_xlive_friend_Current(self, 0x1231);

    return XOnlineFriendsRevokeGameInvite(*(s32*)(self + 0x5C), *(s32*)(D_00798CAC + 0xB4), *(s32*)(D_00798CAC + 0xB8), 1, f);
}

/* xb_XLIVE_FRIEND_CLASS_FriendAction_L4679 0xFF2F3 and _L4702 0xFF38D:
 * the chosen friend's request (0x80) or game invite (0x08) answered;
 * whether another is still pending is kept at work +0x150 or +0x158. */
s32 XB_FASTCALL xb_XLIVE_FRIEND_CLASS_FriendAction_L4679(u8* self, s32 edx, s32 answer) {
    (void)edx;
    xb_xlive_friend_Current(self, 0x1247);
    *(s32*)(D_00798CAC + 0x150) = 0;
    *(s32*)(D_00798CAC + 0x150) = xb_xlive_friend_OtherHas(self, 0x80);
    return sub_001D5352(*(s32*)(self + 0x5C), xb_xlive_friend_Current(self, 0x1247), answer);
}

s32 XB_FASTCALL xb_XLIVE_FRIEND_CLASS_FriendAction_L4702(u8* self, s32 edx, s32 answer) {
    (void)edx;
    xb_xlive_friend_Current(self, 0x125E);
    *(s32*)(D_00798CAC + 0x158) = 0;
    *(s32*)(D_00798CAC + 0x158) = xb_xlive_friend_OtherHas(self, 0x08);
    return sub_001D535D(*(s32*)(self + 0x5C), xb_xlive_friend_Current(self, 0x125E), answer);
}

/* xb_XLIVE_FRIEND_CLASS_BuildActions 0xFF427: the chosen friend's game
 * invite answered with its record (XUID, name, title, session). */
s32 XB_FASTCALL xb_XLIVE_FRIEND_CLASS_BuildActions(u8* self, s32 edx, s32 a, s32 b) {
    u8 rec[0x30];
    u8* f;

    (void)edx;
    xb_xlive_friend_Current(self, 0x1271);
    *(s32*)(D_00798CAC + 0x158) = 0;
    *(s32*)(D_00798CAC + 0x158) = xb_xlive_friend_OtherHas(self, 0x08);
    f = xb_xlive_friend_Current(self, 0x1271);
    *(s32*)(rec + 0x1C) = *(s32*)(f + 0x30);
    *(s32*)(rec + 0x28) = *(s32*)(f + 0x20);
    *(s32*)(rec + 0x2C) = *(s32*)(f + 0x24);
    *(s32*)(rec + 0x20) = *(s32*)(f + 0x28);
    *(s32*)(rec + 0x24) = *(s32*)(f + 0x2C);
    memcpy(rec + 0xC, f + 0xC, 0x10);
    memcpy(rec, f, 0xC);
    return sub_001D626C(*(s32*)(self + 0x5C), rec, a, 0, b);
}

/* xb_XLIVE_FRIEND_CLASS_UpdateFriendPage 0xFF549: the chosen friend
 * removed. */
s32 XB_FASTCALL xb_XLIVE_FRIEND_CLASS_UpdateFriendPage(u8* self) {
    return sub_001D5368(*(s32*)(self + 0x5C), xb_xlive_friend_Current(self, 0x1290));
}

void** XB_FASTCALL xb_iterator_ctor(void** self, s32 edx, void* p);
void xb_vector60_FindIf(void** out, void* first, void* last, void* key);
s32 XB_FASTCALL xb_xlive_disp_IsMissing(s32* self, s32 edx, s32* other);
u8* XB_FASTCALL xb_vector_IterDerefThunk(void** self);
void** XB_FASTCALL xb_vector60_IterInc(void** self);
s32 XB_STDCALL sub_001D52D8(s32 title, s32 lang, s32 n, u16* name);
s32 XB_STDCALL sub_001D52C2(s32 task);

/* xb_XLIVE_FRIEND_CLASS_FindFriend 0x100DE8: the friend entry key (an
 * iterator value) found in the list (std::find); its +0x1C, or -1. */
s32 XB_FASTCALL xb_XLIVE_FRIEND_CLASS_FindFriend(u8* self, s32 edx, void* key) {
    void* k;
    void* first;
    void* last;
    void* end;
    void* r;
    void** pk;
    void** pl;
    void** pf;
    XB_ARG a;

    (void)edx;
    a.v = (s32)key;
    pk = ((void** (XB_FASTCALL*)(void**, XB_ARG))xb_iterator_ctor)(&k, a);
    a.v = (s32)&last;
    pl = (void**)((void* (XB_FASTCALL*)(u8*, XB_ARG))xb_xlive_friend_GetElem8)(self + 0x860, a);
    a.v = (s32)&first;
    pf = (void**)((void* (XB_FASTCALL*)(u8*, XB_ARG))xb_xlive_friend_GetElem4)(self + 0x860, a);
    xb_vector60_FindIf(&r, *pf, *pl, *pk);
    a.v = (s32)&end;
    a.v = (s32)((void* (XB_FASTCALL*)(u8*, XB_ARG))xb_xlive_friend_GetElem8)(self + 0x860, a);

    if ((u8)((s32 (XB_FASTCALL*)(void*, XB_ARG))xb_xlive_disp_IsMissing)(&r, a) == 0) {
        return -1;
    }

    return *(s32*)(xb_vector_IterDerefThunk(&r) + 0x1C);
}

/* xb_XLIVE_FRIEND_CLASS_ScanFriendsA 0x100E5F: the index of the friend
 * with the user id (its first 8 bytes), or -1. */
s32 XB_FASTCALL xb_XLIVE_FRIEND_CLASS_ScanFriendsA(u8* self, s32 edx, u32* id) {
    void* it;
    void* end;
    u32* e;
    s32 i = 0;
    XB_ARG a;

    (void)edx;
    a.v = (s32)&it;
    ((void* (XB_FASTCALL*)(u8*, XB_ARG))xb_xlive_friend_GetElem4)(self + 0x860, a);

    for (;;) {
        a.v = (s32)&end;
        a.v = (s32)((void* (XB_FASTCALL*)(u8*, XB_ARG))xb_xlive_friend_GetElem8)(self + 0x860, a);

        if ((u8)((s32 (XB_FASTCALL*)(void*, XB_ARG))xb_xlive_disp_IsMissing)(&it, a) == 0) {
            return -1;
        }

        e = (u32*)xb_vector_IterDerefThunk(&it);

        if (e[0] == id[0] && e[1] == id[1]) {
            return i;
        }

        i++;
        xb_vector60_IterInc(&it);
    }
}

/* xb_XLIVE_FRIEND_CLASS_ScanFriendsB 0x100EDA: the friend with the user
 * id, or 0. */
u8* XB_FASTCALL xb_XLIVE_FRIEND_CLASS_ScanFriendsB(u8* self, s32 edx, u32* id) {
    void* it;
    void* end;
    u32* e;
    s32 i = 0;
    XB_ARG a;

    (void)edx;
    a.v = (s32)&it;
    ((void* (XB_FASTCALL*)(u8*, XB_ARG))xb_xlive_friend_GetElem4)(self + 0x860, a);

    for (;;) {
        a.v = (s32)&end;
        a.v = (s32)((void* (XB_FASTCALL*)(u8*, XB_ARG))xb_xlive_friend_GetElem8)(self + 0x860, a);

        if ((u8)((s32 (XB_FASTCALL*)(void*, XB_ARG))xb_xlive_disp_IsMissing)(&it, a) == 0) {
            return 0;
        }

        e = (u32*)xb_vector_IterDerefThunk(&it);

        if (e[0] == id[0] && e[1] == id[1]) {
            a.v = i;
            return ((u8* (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_FRIEND_CLASS_FriendAt)(self + 0x860, a);
        }

        i++;
        xb_vector60_IterInc(&it);
    }
}

/* xb_XLIVE_FRIEND_CLASS_Page_100F5A: the chosen friend's title name
 * (+0x2A64) looked up; when there is one, the enumeration's results are
 * taken and the friend page (0xA) shown. */
void XB_FASTCALL xb_XLIVE_FRIEND_CLASS_Page_100F5A(u8* self, s32 edx, s32 in) {
    u16 text[0x100];
    s32 hr;
    XB_ARG a;

    (void)edx;
    (void)in;
    CXBOnlineTask_Continue(D_00798CAC + 0x110);
    a.v = *(s32*)(self + 0x8C4);
    sub_001D52D8(*(s32*)(((u8* (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_FRIEND_CLASS_FriendAt)(self + 0x860, a) + 0x30), 1, 0x28,
                 (u16*)(self + 0x2A64));

    if (*(u16*)(self + 0x2A64) == 0) {
        return;
    }

    hr = sub_001D52C2(xb_iterator_Deref(D_00798CAC + 0x110));

    if (hr < 0) {
        xb_xlive_main_SetMatchArgs(hr, D_002B4D08, 0x1AB1, 0);
        XBUtil_GetWide(D_0079933C, text, 0x100);
        xb_xlive_friend_Printf(self + 0x60, text);
        xb_xlive_friend_SetPage(self, 0xE, 0x11);
    } else {
        xb_xlive_friend_SetPage(self, 0xA, 0xB);
    }
}

s32 XB_STDCALL sub_001D52E3(s32 user, u8* f);
void xb_SoftResetAndExit(void);
u8* XB_FASTCALL xb_deque_LiveObj_Subscript(u8* self, s32 edx, s32 i);
extern u8 D_00798B80;
extern u8 D_00798B81[];
extern u8 D_00798BD8[];
extern s32 D_0079A170;
extern char* D_00799150;
extern char* D_007992F8;

/* xb_XLIVE_FRIEND_CLASS_Answer_FF592: an XOnline call on the chosen
 * friend (0x1D52E3; with FriendAction_L4702 the game-invite answers). */
s32 XB_FASTCALL xb_XLIVE_FRIEND_CLASS_Answer_FF592(u8* self) {
    return sub_001D52E3(*(s32*)(self + 0x5C), xb_xlive_friend_Current(self, 0x129A));
}

/* xb_LiveSet79A170 0x1100A2. */
void xb_LiveSet79A170(s32 v) {
    D_0079A170 = v;
}

/* xb_XLIVE_FRIEND_CLASS_Page_10110C: a game invite answered (cursor
 * +0x8B8: 0 with Answer_FF592, otherwise declined through FriendAction):
 * the result shown (by the friend's flag 0x40). */
void XB_FASTCALL xb_XLIVE_FRIEND_CLASS_Page_10110C(u8* self, s32 edx, s32 in) {
    u16 text[0x100];
    s32 r;
    s32 back;
    u8* f;
    XB_ARG a;

    (void)edx;

    if (in == 1 || in == 4) {
        xb_SeSelectedThunk();
        xb_xlive_friend_SetPage(self, 2, 2);
        *(s32*)(self + 0x8B8) = 0;
        *(s32*)(self + 0x8BC) = 0;
        return;
    }

    if (in != 0) {
        return;
    }

    xb_SeSelectedThunk();

    if (*(s32*)(self + 0x8B8) != 0) {
        a.v = 2;
        r = ((s32 (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_FRIEND_CLASS_FriendAction_L4702)(self, a);
    } else {
        r = xb_XLIVE_FRIEND_CLASS_Answer_FF592(self);
    }

    if (r < 0) {
        XBUtil_GetWide(D_007993E4, text, 0x100);
        xb_xlive_main_SetMatchArgs(r, D_002B4D08, 0x62E, 0);
        xb_xlive_friend_Printf(self + 0x60, text);
        xb_xlive_friend_SetPage(self, 0xE, 0x11);
        return;
    }

    a.v = *(s32*)(self + 0x8C4);
    f = ((u8* (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_FRIEND_CLASS_FriendAt)(self + 0x860, a);
    XBUtil_GetWide((f[0x1F] & 0x40) ? D_00799150 : D_00799308, text, 0x100);
    xb_xlive_friend_Printf(self + 0x60, text);
    back = *(s32*)(self + 0xA84) != 0;
    *(s32*)(self + 0x8B8) = 0;
    *(s32*)(self + 0x8BC) = 0;
    xb_xlive_friend_SetPage(self, 0xE, back);
}

/* xb_XLIVE_FRIEND_CLASS_Page_101235: waiting to join the friend's game
 * (task +0x2A1C, after a delay +4): another title's game is launched (the
 * friend and the user kept in D_00798B80 and up, the game reset); in this
 * title the friend page follows; otherwise the reason is shown. */
void XB_FASTCALL xb_XLIVE_FRIEND_CLASS_Page_101235(u8* self, s32 edx, s32 in) {
    u16 text[0x100];
    s32 hr;
    u8* f;
    XB_ARG a;

    (void)edx;
    (void)in;
    hr = CXBOnlineTask_Continue(self + 0x2A1C);

    if (hr == 0) {
        return;
    }

    if (*(s32*)(self + 4) != 0) {
        (*(s32*)(self + 4))--;
        return;
    }

    if (hr != 0x1500F0) {
        XBUtil_GetWide(D_007993E4, text, 0x100);
        xb_xlive_friend_Printf(self + 0x60, text);
        xb_xlive_friend_SetPage(self, 0xE, 0x11);
        CXBOnlineTask_Close(self + 0x2A1C);
        return;
    }

    a.v = *(s32*)(self + 0x8C4);
    f = ((u8* (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_FRIEND_CLASS_FriendAt)(self + 0x860, a);

    if (sub_001D5272(*(s32*)(f + 0x30)) == 0) {
        XBUtil_GetWide(D_007992F8, text, 0x100);
        xb_xlive_friend_Printf(self + 0x60, text);
        xb_xlive_friend_SetPage(self, 0x21, 0xA);
        CXBOnlineTask_Close(self + 0x2A1C);
        return;
    }

    a.v = *(s32*)(self + 0x8C4);
    f = ((u8* (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_FRIEND_CLASS_FriendAt)(self + 0x860, a);

    if (f[0x35] == (u32)*(s32*)(D_00798CAC + 8)) {
        xb_xlive_friend_SetPage(self, 0xB, 0xB);
        CXBOnlineTask_Close(self + 0x2A1C);
        return;
    }

    CXBOnlineTask_Close(self + 0x2A1C);
    D_00798B80 = 1;
    a.v = *(s32*)(self + 0x8C4);
    memcpy(D_00798B81, ((u8* (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_FRIEND_CLASS_FriendAt)(self + 0x860, a), 0x56);
    a.v = 0;
    memcpy(D_00798BD8, ((u8* (XB_FASTCALL*)(u8*, XB_ARG))xb_deque_LiveObj_Subscript)(D_00798CAC + 0x28, a), 0xC);
    xb_SoftResetAndExit();
    *(s32*)(D_00798CAC + 0x2330) = 0;
    xb_xlive_friend_SetPage(self, 0x22, 0x22);
    xb_LiveSet79A170(0);
}

s32 xb_OnlineObj_IsActive(s32 id);
extern char* D_00799068;
extern char* D_00799160;
extern char* D_0079917C;
extern char* D_007992EC;

/* xb_XLIVE_FRIEND_CLASS_Page_1013A5: a friend request accepted: the box
 * opened (0, 1), the answer sent (2; the result shown: accepted, or why
 * not: 0x80152004, 0x80152008), or back to page 2; the box faded (3) and
 * closed (4). */
void XB_FASTCALL xb_XLIVE_FRIEND_CLASS_Page_1013A5(u8* self, s32 edx, s32 in) {
    u16 text[0x100];
    s32 r;
    s32 back;
    XB_ARG a;

    (void)edx;

    switch (*(s32*)(self + 4)) {
    case 0:
        xb_xlive_friend_OpenBox();
        (*(s32*)(self + 4))++;
        /* fall through */

    case 1:
        if (xb_OnlineObj_IsActive(D_003F82CC) != 0) {
            (*(s32*)(self + 4))++;
        }

        return;

    case 2:
        if (in == 1 || in == 4) {
            xb_SeSelectedThunk();
            xb_xlive_friend_Release(D_003F82CC);
            D_003F82CC = -1;
            *(s32*)(self + 4) = 0;
            xb_xlive_friend_SetPage(self, 2, 2);
            return;
        }

        if (in != 0) {
            return;
        }

        xb_SeSelectedThunk();
        a.v = 2;
        r = ((s32 (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_FRIEND_CLASS_FriendAction_L4679)(self, a);

        if (r >= 0) {
            XBUtil_GetWide(D_00799160, text, 0x100);
            xb_xlive_friend_Printf(self + 0x60, text);
            back = *(s32*)(self + 0xA84) != 0;
            *(s32*)(self + 0x8B8) = 0;
            *(s32*)(self + 0x8BC) = 0;
            xb_xlive_friend_SetPage(self, 0xE, back);
            return;
        }

        if (r == (s32)0x80152004) {
            XBUtil_GetWide(D_0079917C, text, 0x100);
        } else if (r == (s32)0x80152008) {
            XBUtil_GetWide(D_00799068, text, 0x100);
        } else if (r == 1) {
            XBUtil_GetWide(D_007992EC, text, 0x100);
        } else {
            XBUtil_GetWide(D_007993E4, text, 0x100);
        }

        xb_xlive_friend_Printf(self + 0x60, text);
        xb_xlive_friend_SetPage(self, 0xE, 0x11);
        return;

    case 3:
        xb_OnlineObj_Fade(D_003F82CC);
        (*(s32*)(self + 4))++;
        /* fall through */

    case 4:
        if (xb_OnlineObj_IsDone(D_003F82CC)) {
            xb_xlive_friend_Release(D_003F82CC);
            D_003F82CC = -1;
            *(s32*)(self + 4) = 0;
        }

        return;
    }
}

extern s32 D_00798C5C;
extern s32 D_00798C60;

/* The chosen friend's game invite answered (1 accept, 0 decline) with its
 * record (task +0x2A1C); on an error the reason is shown. Returns 1 when
 * sent. */
static s32 xb_xlive_friend_AnswerInvite(u8* self, s32 answer) {
    u16 text[0x100];
    XB_ARG a;
    XB_ARG b;

    CXBOnlineTask_Close(self + 0x2A1C);
    a.v = answer;
    b.v = CXBOnlineTask_operator_addr(self + 0x2A1C);

    if (((s32 (XB_FASTCALL*)(u8*, XB_ARG, XB_ARG))xb_XLIVE_FRIEND_CLASS_BuildActions)(self, a, b) >= 0) {
        return 1;
    }

    CXBOnlineTask_Close(self + 0x2A1C);
    XBUtil_GetWide(D_007993E4, text, 0x100);
    xb_xlive_friend_Printf(self + 0x60, text);
    xb_xlive_friend_SetPage(self, 0xE, 0x11);
    return 0;
}

/* xb_XLIVE_FRIEND_CLASS_Page_101597: a game invite to accept or decline:
 * the box opened (0, 1), the answer taken (2: accept to page 0x19), the
 * box faded (3) and closed (4), and an acceptance sent (then a wait of
 * 0x3C). */
void XB_FASTCALL xb_XLIVE_FRIEND_CLASS_Page_101597(u8* self, s32 edx, s32 in) {
    (void)edx;

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
        if (in == 0) {
            xb_SeSelectedThunk();
            *(s32*)(self + 4) = 3;
            D_00798C60 = 0x19;
            D_00798C5C = 0x19;
        } else if (in == 1 || in == 4) {
            xb_SeSelectedThunk();
            *(s32*)(self + 4) = 3;
            D_00798C60 = 0;
            D_00798C5C = 0;
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

        if (D_00798C60 != 0x19) {
            *(s32*)(self + 0x8B8) = 0;
            *(s32*)(self + 0x8BC) = 0;
            xb_xlive_friend_SetPage(self, D_00798C60, D_00798C5C);
            *(s32*)(self + 4) = 0;
            return;
        }

        if (xb_xlive_friend_AnswerInvite(self, 1)) {
            xb_xlive_friend_SetPage(self, D_00798C60, D_00798C5C);
            *(s32*)(self + 4) = 0x3C;
        }

        return;
    }
}

/* xb_XLIVE_FRIEND_CLASS_Page_101785: the same for an invite from the
 * friend list (+8: 0 accept, 1 decline): an acceptance goes to page 0x19,
 * a decline back to page 2. */
void XB_FASTCALL xb_XLIVE_FRIEND_CLASS_Page_101785(u8* self, s32 edx, s32 in) {
    (void)edx;

    switch (*(s32*)(self + 4)) {
    case 0:
        xb_xlive_friend_OpenBox();
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
            *(s32*)(self + 8) = 0;
            (*(s32*)(self + 4))++;
        } else if (in == 1 || in == 4) {
            xb_SeSelectedThunk();
            *(s32*)(self + 4) = 3;
            *(s32*)(self + 8) = 1;
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

        if (*(s32*)(self + 8) == 0) {
            xb_SeSelectedThunk();

            if (!xb_xlive_friend_AnswerInvite(self, 1)) {
                return;
            }

            xb_xlive_friend_SetPage(self, 0x19, 0x19);
            *(s32*)(self + 4) = 0x3C; /* cleared below, as in retail */
        } else if (*(s32*)(self + 8) == 1 || in == 4) {
            xb_SeSelectedThunk();
            xb_xlive_friend_SetPage(self, 2, 2);
        }

        *(s32*)(self + 8) = 0;
        *(s32*)(self + 4) = 0;
        return;
    }
}

/* xb_XLIVE_FRIEND_CLASS_Page_101954: the chosen friend's game invite
 * declined (to page 0x1A). */
void XB_FASTCALL xb_XLIVE_FRIEND_CLASS_Page_101954(u8* self, s32 edx, s32 in) {
    (void)edx;
    (void)in;

    if (xb_xlive_friend_AnswerInvite(self, 0)) {
        xb_xlive_friend_SetPage(self, 0x1A, 0x1A);
    }
}

void xb_xlive_disp_DrawRectI(s32 font, f32 x, f32 y, f32 s, s32 text, f32 size, s32 flags, s32 c);
s32 XB_FASTCALL xb_XLIVE_STAT_CLASS_DrawPage(u8* self);
void xb_OnlineObj_SetRect(s32 id, s32 a, s32 b, s32 c, s32 d);
void xb_xlive_disp_DrawRectCentered(s32 id, f32 x, f32 y, f32 s, s32 text, f32 size, s32 flags, s32 c);
s32 XB_FASTCALL sub_00012AA8(void* self);
void xb_xlive_WideToAnsi(const u16* src, char* dst, s32 n);
s32 XB_STDCALL WideCharToMultiByte(u32 cp, u32 flags, const u16* src, s32 n, char* dst, s32 size, const char* def, s32* used);
u32 wcslen(const u16* s);
extern char D_00219674[];
extern char D_00219680[];
extern char D_00219690[];
extern char D_002B4DB8[];
s32 sub_0004AFFA(void);
void XB_FASTCALL xb_xlive_friend_DrawText(u16* self);
void XB_FASTCALL xb_XLIVE_FRIEND_CLASS_DrawFriendList(u8* self, s32 edx, u32 first, u32 cur, u8* list, u16* msg, s32 show);
void XB_FASTCALL xb_XLIVE_FRIEND_CLASS_DrawPlayerList(u8* self, s32 edx, u32 first, u32 cur, u8* list, u16* msg);
void XB_FASTCALL xb_xlive_friend_DrawFeedback(u16* self, s32 edx, u32 cur, s32 confirm, u8* user);
void XB_FASTCALL xb_xlive_friend_DrawActions(u16* self, s32 edx, u32 cur, u8* actions, u8* f);
void XB_FASTCALL xb_xlive_friend_DrawRequest(u16* self, s32 edx, s32 cur, u8* f);
void XB_FASTCALL xb_xlive_friend_DrawReceived(u16* self, s32 edx, s32 st, s32 cur);
void XB_FASTCALL xb_xlive_friend_DrawVoiceMail(u16* self, s32 edx, s32 st, s32 cur);
void XB_FASTCALL xb_xlive_friend_DrawBoxMessage(u16* self, s32 edx, s32 state, s32 kind);
void XB_FASTCALL xb_xlive_friend_DrawComplaint(u16* self, s32 edx, u32 cur, s32 confirm, u8* f);
extern f32 D_002B4BE4;
extern f32 D_0025F370;
extern f32 D_00219410;
extern f32 D_002190BC;
extern f32 D_002190E8;
extern f32 D_002B4CF8;
extern f32 D_002B4D9C;
extern f32 D_002B4DDC;
extern f32 D_0021941C;
extern f32 D_002190D4;
extern char D_002B4EA8[];
extern s32 D_00799070;
extern s32 D_00799074;
extern s32 D_007990D8;
extern s32 D_0079914C;
extern s32 D_007991B0;
extern s32 D_00799224;
extern s32 D_00799228;
extern s32 D_00799258;
extern s32 D_00799264;
extern s32 D_00799288;
extern s32 D_007992DC;
extern s32 D_007992F0;

/* A box's message and its prompt, two lines (at D_00219410 and
 * D_00219404) of the box id. */
#define XB_FRIEND_BOX2(id, msg)                                                                   \
    do {                                                                                          \
        xb_xlive_disp_DrawRectI((id), 0.0f, D_00219410, D_0025F370, (msg), D_002B4BE4, 0, 0);       \
        xb_xlive_disp_DrawRectI((id), 0.0f, D_00219404, D_0025F370, D_00799070, D_002B4BE4, 4, 0); \
    } while (0)

/* xb_XLIVE_FRIEND_CLASS_Page_102D50: the friend window drawn, by page
 * (+0x8B0): the lists and their cursors (+0x8B8, +0x8BC) through the page
 * drawers, the friend's name, and the boxes' messages. */
s32 XB_FASTCALL xb_XLIVE_FRIEND_CLASS_Page_102D50(u8* self) {
    char name[0x200];
    u8* info;
    u8* f;
    s32 text;
    XB_ARG a;
    XB_ARG b;
    XB_ARG c;
    XB_ARG d;
    XB_ARG e;

    info = (u8*)xb_GetMatchInfo();
    xb_OnlineObj_SetRect(D_003F82C4, 0, 0, 0, 0);
    xb_OnlineObj_SetRect(D_003F82C8, 0, 0, 0, 0);

    switch (*(u32*)(self + 0x8B0)) {
    case 0:
        if (sub_00012AA8(D_00798CAC + 0x110) == 0) {
            a.v = *(s32*)(self + 0x8BC);
            b.v = *(s32*)(self + 0x8B8);
            c.v = (s32)(self + 0x860);
            d.v = (s32)(self + 0x8D8);
            e.v = *(s32*)(self + 0xA80);
            ((void (XB_FASTCALL*)(u8*, XB_ARG, XB_ARG, XB_ARG, XB_ARG, XB_ARG))xb_XLIVE_FRIEND_CLASS_DrawFriendList)(self + 0x60, a, b, c, d, e);
        }

        break;

    case 1:
        if (sub_00012AA8(D_00798CAC + 0x110) == 0) {
            a.v = *(s32*)(self + 0x8BC);
            b.v = *(s32*)(self + 0x8B8);
            c.v = (s32)(D_00798CAC + 0x3C);
            d.v = (s32)(self + 0x8D8);
            ((void (XB_FASTCALL*)(u8*, XB_ARG, XB_ARG, XB_ARG, XB_ARG))xb_XLIVE_FRIEND_CLASS_DrawPlayerList)(self + 0x60, a, b, c, d);
        }

        break;

    case 2:
        if ((u8)xb_xlive_friend_IsEmpty(self + 0xA70) != 0) {
            _assert(D_002B4EA8, D_002B4D08, 0x13A0);
        }

        if (*(s32*)(self + 0xA84) != 0) {
            xb_xlive_WideToAnsi((const u16*)(self + 0x970), name, 0x200);
            text = (s32)name;
        } else {
            a.v = *(s32*)(self + 0x8C4);
            text = (s32)(((u8* (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_FRIEND_CLASS_FriendAt)(self + 0x860, a) + 0xC);
        }

        xb_xlive_disp_DrawRectI(D_003F82C4, D_002190BC, D_002B4CF8 + D_002190E8, D_0025F370, text, D_002B4BE4, 7, 0);

        if (*(s32*)(self + 0xA84) != 0) {
            a.v = (s32)(self + 0x960);
            f = ((u8* (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_FRIEND_CLASS_ScanFriendsB)(self, a);
        } else {
            a.v = *(s32*)(self + 0x8C4);
            f = ((u8* (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_FRIEND_CLASS_FriendAt)(self + 0x860, a);
        }

        a.v = *(s32*)(self + 0x8B8);
        b.v = (s32)(self + 0xA70);
        c.v = (s32)f;
        ((void (XB_FASTCALL*)(u8*, XB_ARG, XB_ARG, XB_ARG))xb_xlive_friend_DrawActions)(self + 0x60, a, b, c);
        break;

    case 3:
        xb_xlive_WideToAnsi((const u16*)(self + 0x970), name, 0x200);
        xb_xlive_disp_DrawRectI(D_003F82C4, D_002190BC, D_002B4CF8 + D_002190E8, D_0025F370, (s32)name, D_002B4BE4, 7, 0);
        break;

    case 4:
        if (xb_OnlineObj_IsDone(D_003F82CC)) {
            XB_FRIEND_BOX2(D_003F82CC, D_00799258);
        }

        break;

    case 6:
        a.v = *(s32*)(self + 0x8B8);
        b.v = *(s32*)(self + 0x8BC);
        c.v = (s32)(self + 0x960);
        ((void (XB_FASTCALL*)(u8*, XB_ARG, XB_ARG, XB_ARG))xb_xlive_friend_DrawFeedback)(self + 0x60, a, b, c);
        break;

    case 8:
        if (xb_OnlineObj_IsActive(D_003F82CC) != 0) {
            XB_FRIEND_BOX2(D_003F82C4, D_007992DC);
        }

        break;

    case 9:
        if (*(u32*)(self + 0x8C4) >= std__vector_Elem60__size(self + 0x860)) {
            _assert(D_002B4E08, D_002B4D08, 0x13D6);
        }

        xb_xlive_disp_DrawRectI(D_003F82C4, D_002190BC, D_002B4CF8 + D_002190E8, D_0025F370, D_00799228, D_002B4BE4, 5, 0);
        a.v = *(s32*)(self + 0x8C4);
        b.v = (s32)((u8* (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_FRIEND_CLASS_FriendAt)(self + 0x860, a);
        a.v = *(s32*)(self + 0x8B8);
        ((void (XB_FASTCALL*)(u8*, XB_ARG, XB_ARG))xb_xlive_friend_DrawRequest)(self + 0x60, a, b);
        break;

    case 0xD:
        if (sub_0004AFFA() != 0) {
            xb_XLIVE_STAT_CLASS_DrawPage(D_00798CAC + 0x5538);
        }

        break;

    case 0xE:
        xb_xlive_friend_DrawText((u16*)(self + 0x60));
        break;

    case 0x12:
        a.v = *(s32*)(self + 4);
        b.v = *(s32*)(self + 0x8B8);
        ((void (XB_FASTCALL*)(u8*, XB_ARG, XB_ARG))xb_xlive_friend_DrawReceived)(self + 0x60, a, b);
        break;

    case 0x13:
        a.v = *(s32*)(self + 4);
        b.v = *(s32*)(self + 0x8B8);
        ((void (XB_FASTCALL*)(u8*, XB_ARG, XB_ARG))xb_xlive_friend_DrawVoiceMail)(self + 0x60, a, b);
        break;

    case 0x14:
    case 0x15:
        a.v = *(s32*)(self + 4);
        b.v = *(u32*)(self + 0x8B0) == 0x14 ? 0 : 0xD;
        ((void (XB_FASTCALL*)(u8*, XB_ARG, XB_ARG))xb_xlive_friend_DrawBoxMessage)(self + 0x60, a, b);
        break;

    case 0x16:
        if (xb_OnlineObj_IsDone(D_003F82CC)) {
            xb_xlive_disp_DrawRectI(D_003F82C4, 0.0f, D_002B4D9C, D_0025F370,
                                    *(s32*)(self + 0x2A5C) != 0 ? D_00799288 : D_007991B0, D_002B4BE4, 0, 0);
        }

        break;

    case 0x17:
        a.v = *(s32*)(self + 0x8C4);
        c.v = (s32)((u8* (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_FRIEND_CLASS_FriendAt)(self + 0x860, a);
        a.v = *(s32*)(self + 0x8B8);
        b.v = *(s32*)(self + 0x8BC);
        ((void (XB_FASTCALL*)(u8*, XB_ARG, XB_ARG, XB_ARG))xb_xlive_friend_DrawComplaint)(self + 0x60, a, b, c);
        break;

    case 0x1C:
        if (xb_OnlineObj_IsActive(D_003F82CC) != 0) {
            XB_FRIEND_BOX2(D_003F82C4, D_0079914C);
        }

        break;

    case 0x1D:
        if (xb_OnlineObj_IsActive(D_003F82CC) != 0) {
            XB_FRIEND_BOX2(D_003F82CC, D_00799224);
        }

        break;

    case 0x1E:
        if (*(s32*)(self + 4) == 10) {
            xb_xlive_disp_DrawRectI(D_003F82CC, 0.0f, D_00219410, D_0025F370, (s32)(info + 0x120), D_002B4BE4, 7, 0);
            xb_xlive_disp_DrawRectI(D_003F82CC, 0.0f, D_002B4DDC, D_0025F370, D_00799074, D_002B4BE4, 0, 0);
            xb_xlive_disp_DrawRectI(D_003F82CC, 0.0f, D_00219404, D_0025F370, D_00799264, D_002B4BE4, 4, 0);
        } else if (xb_OnlineObj_IsActive(D_003F82CC) != 0) {
            xb_xlive_disp_DrawRectCentered(D_003F82CC, D_002190D4, D_0021941C, D_0025F370, (s32)(info + 0x120), D_002B4BE4, 7, 0);
            XB_FRIEND_BOX2(D_003F82CC, D_007990D8);
        }

        break;

    case 0x1F:
        if (xb_OnlineObj_IsActive(D_003F82CC) != 0) {
            XB_FRIEND_BOX2(D_003F82CC, D_007992F0);
        }

        break;

    case 5:
    case 7:
    case 0xA:
    case 0xB:
    case 0xC:
    case 0xF:
    case 0x10:
    case 0x11:
    case 0x18:
    case 0x19:
    case 0x1A:
    case 0x1B:
    case 0x20:
    case 0x21:
    case 0x22:
        break;

    default:
        _assert(D_0025CCA0, D_002B4D08, 0x1459);
        break;
    }

    return 0;
}

s32 XB_STDCALL XOnlineMutelistRemove(s32 user, XB_FXUID xuid);
void* XB_FASTCALL xb_vector16_erase(void* self, s32 edx, void** ret, void* it);
void xb_vector_FindIf(void** out, void* first, void* last, void* key);
u32 XB_FASTCALL xb_LiveObj_Count(u8* self);
extern char D_002B4EBC[];
extern char D_002B4ED8[];
extern char D_002B4F00[];

/* xb_XLIVE_FRIEND_CLASS_ToggleMute 0x10351F: the user unmuted: the friend
 * (+0x8C4, which must be muted, +0x58) or, from a match, the session's
 * user (+0x958); taken off the mute list and off the Live work's list of
 * muted users (+0x120). Returns XOnlineMutelistRemove's result. */
s32 XB_FASTCALL xb_XLIVE_FRIEND_CLASS_ToggleMute(u8* self) {
    XB_FXUID x;
    void* k;
    void* first;
    void* last;
    void* end;
    void* r;
    void* ret;
    void** pk;
    void** pl;
    void** pf;
    u8* u;
    s32 hr;
    XB_ARG a;
    XB_ARG b;

    if (*(s32*)(self + 0xA84) != 0) {
        if (*(u32*)(self + 0x958) >= xb_LiveObj_Count(D_00798CAC + 0x3C)) {
            _assert(D_002B4F00, D_002B4D08, 0x12A9);
        }

        a.v = *(s32*)(self + 0x958);
        u = ((u8* (XB_FASTCALL*)(u8*, XB_ARG))xb_deque_LiveObj_Subscript)(D_00798CAC + 0x3C, a);
    } else {
        if (*(u32*)(self + 0x8C4) >= std__vector_Elem60__size(self + 0x860)) {
            _assert(D_002B4E08, D_002B4D08, 0x12AD);
        }

        a.v = *(s32*)(self + 0x8C4);

        if (*(s32*)(((u8* (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_FRIEND_CLASS_FriendAt)(self + 0x860, a) + 0x58) == 0) {
            _assert(D_002B4ED8, D_002B4D08, 0x12AE);
        }

        a.v = *(s32*)(self + 0x8C4);
        u = ((u8* (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_FRIEND_CLASS_FriendAt)(self + 0x860, a);
    }

    x = *(XB_FXUID*)u;
    hr = XOnlineMutelistRemove(*(s32*)(self + 0x5C), x);
    a.v = (s32)&x;
    pk = ((void** (XB_FASTCALL*)(void**, XB_ARG))xb_iterator_ctor)(&k, a);
    a.v = (s32)&last;
    pl = (void**)((void* (XB_FASTCALL*)(u8*, XB_ARG))xb_xlive_friend_GetElem8)(D_00798CAC + 0x120, a);
    a.v = (s32)&first;
    pf = (void**)((void* (XB_FASTCALL*)(u8*, XB_ARG))xb_xlive_friend_GetElem4)(D_00798CAC + 0x120, a);
    xb_vector_FindIf(&r, *pf, *pl, *pk);
    a.v = (s32)&end;
    a.v = (s32)((void* (XB_FASTCALL*)(u8*, XB_ARG))xb_xlive_friend_GetElem8)(D_00798CAC + 0x120, a);

    if ((u8)((s32 (XB_FASTCALL*)(void*, XB_ARG))xb_xlive_disp_IsMissing)(&r, a) == 0) {
        _assert(D_002B4EBC, D_002B4D08, 0x12BE);
    }

    a.v = (s32)&end;
    a.v = (s32)((void* (XB_FASTCALL*)(u8*, XB_ARG))xb_xlive_friend_GetElem8)(D_00798CAC + 0x120, a);

    if ((u8)((s32 (XB_FASTCALL*)(void*, XB_ARG))xb_xlive_disp_IsMissing)(&r, a) != 0) {
        a.v = (s32)&ret;
        b.v = (s32)r;
        ((void* (XB_FASTCALL*)(void*, XB_ARG, XB_ARG))xb_vector16_erase)(D_00798CAC + 0x120, a, b);
    }

    if (*(s32*)(self + 0xA84) == 0) {
        a.v = *(s32*)(self + 0x8C4);
        *(s32*)(((u8* (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_FRIEND_CLASS_FriendAt)(self + 0x860, a) + 0x58) = 0;
    }

    return hr;
}

s32 XB_FASTCALL xb_XLIVE_FRIEND_CLASS_OpenWindow(u8* self, s32 edx, s32 i, f32 a, f32 b, f32 c, f32 d);
void xb_xlive_disp_CheckIndex2(s32 index, s32 id);
void xb_xlive_disp_DrawRect1(s32 a, f32 x, f32 y, f32 w);
void xb_xlive_disp_DrawObj(s32 id, f32 x, f32 y, s32 u0, s32 u1, s32 icon, f32 sx, f32 sy);
u8 XB_FASTCALL std__vector_Elem60__empty(void* self);
s32 XB_FASTCALL CXHVVoiceManager_IsTalking(u8* self, s32 edx, XB_FXUID x, s32 user);
u8* xb_FindOnlineObj(s32 id);
extern u16 D_00798C00[];
extern f32 D_002190AC;
s32 xb_GetLiveLanguage(void);
extern f32 D_00219408;
extern f32 D_002B4D94;
extern f32 D_002B4D98;
extern f32 D_002B4CFC;
extern f32 D_002B4DA4;
extern f32 D_002B4E6C;
extern f32 D_002AEEC4;
extern f32 D_002190C8;
extern f32 D_002B4E64;
extern f32 D_002B4E68;
extern f32 D_002B4E5C;
extern f32 D_002B4E54;
extern f32 D_002AEF74;
extern f32 D_002B4E30;
extern f32 D_003F8304;
extern f32 D_003F8308;
extern char D_002B4E60[];
extern char D_002B4E58[];
extern char D_002B4E34[];
extern s32 D_007991E4;
extern s32 D_007991F4;
extern s32 D_0079931C;
extern s32 D_007991CC;
extern char* D_007992D0;
extern char* D_007991BC;
extern char* D_00799388;
extern char* D_007990B0;
extern char* D_00799274;
extern char* D_007993C0;
extern char* D_00799084;
extern char* D_007991A8;
extern char* D_00799078;
extern char* D_007993EC;

/* xb_xlive_friend_GetStatus 0xFBED2: a friend's two icons from its flags
 * (+0x1C): *voice 7 muted (+0x58), 6 with voice (0x08), else 0; *state 1
 * online (0x01), then 2 to 5 for a request sent, received, an invite
 * received, or one to this title. */
void XB_FASTCALL xb_xlive_friend_GetStatus(u8* self, s32 edx, u8* f, s32* voice, s32* state) {
    u32 flags;

    (void)self;
    (void)edx;
    flags = *(u32*)(f + 0x1C);
    *voice = *(s32*)(f + 0x58) != 0 ? 7 : (flags & 8) ? 6 : 0;

    if (flags & 1) {
        *state = 1;
    }

    if ((s32)flags < 0) {
        *state = 2;
    } else if (flags & 0x40000000) {
        *state = 3;
    } else if (flags & 0x8000000) {
        *state = 4;
    } else if ((flags & 0x4000000) && !(flags & 0x30000000)) {
        *state = 5;
    }
}

/* xb_xlive_friend_TitleName 0xFBEAC: a title's name (D_00798C00), empty
 * when unknown. */
u16* XB_FASTCALL xb_xlive_friend_TitleName(u8* self, s32 edx, s32 title) {
    (void)self;
    (void)edx;

    if (sub_001D52D8(title, 1, 0x28, D_00798C00) < 0) {
        D_00798C00[0] = 0;
    }

    return D_00798C00;
}

/* A line of the friend text: the message, after (Japanese) or before the
 * title name. */
static void xb_xlive_friend_TitleLine(u8* self, u16* line, u16* tmp, const char* msg, s32 title) {
    XB_ARG a;

    a.v = title;

    if (xb_GetLiveLanguage() == 0) {
        wsprintfW(line, D_002B4DE8, 0x80, ((u16* (XB_FASTCALL*)(u8*, XB_ARG))xb_xlive_friend_TitleName)(self, a));
        XBUtil_GetWide(msg, tmp, 0x100);
    } else {
        XBUtil_GetWide(msg, tmp, 0x100);
        lstrcatW(line, tmp);
        wsprintfW(tmp, D_002B4DE8, 0x80, ((u16* (XB_FASTCALL*)(u8*, XB_ARG))xb_xlive_friend_TitleName)(self, a));
    }
}

/* One of the list's icons, at a row. */
static void xb_xlive_friend_RowIcon(f32 x, s32 y, s32 icon) {
    xb_xlive_disp_DrawObj(D_003F82C4, x, (f32)(u32)y + D_002B4DA4 - D_002190AC, *(s32*)&D_0025F370, -1, icon, D_002190D4,
                          D_002190D4);
}

/* xb_XLIVE_FRIEND_CLASS_DrawFriendList 0xFF5DB: the friend list page
 * (this is the window, friend window +0x60): the list from entry first,
 * 8 rows, the cursor on entry cur, each friend's icons, voice state and
 * name, the scroll marks, and the chosen friend's state, title and the
 * text (msg); with an empty list only the window and its message. */
void XB_FASTCALL xb_XLIVE_FRIEND_CLASS_DrawFriendList(u8* self, s32 edx, u32 first, u32 cur, u8* list, u16* msg, s32 show) {
    char text[0x200];
    u16 line[0x100];
    u16 tmp[0x100];
    u8* friend = D_00798CAC + 0x25D0;
    u8* f;
    u8* o;
    s32 w;
    s32 y;
    u32 row;
    u32 i;
    s32 voice;
    s32 state;
    u32 flags;
    s32 more;
    const char* s;
    XB_ARG a;
    XB_ARG b;
    XB_ARG c;

    (void)edx;

    if (show == 0) {
        return;
    }

    if (std__vector_Elem60__empty(list)) {
        a.v = 0;
        w = ((s32 (XB_FASTCALL*)(u8*, XB_ARG, f32, f32, f32, f32))xb_XLIVE_FRIEND_CLASS_OpenWindow)(friend, a, D_00219408, D_002B4CF4,
                                                                                                 D_002B4D94, D_002B4D98);
        a.v = 1;

        if ((w & ((s32 (XB_FASTCALL*)(u8*, XB_ARG, f32, f32, f32, f32))xb_XLIVE_FRIEND_CLASS_OpenWindow)(
                     friend, a, D_002B4BEC, D_002B4CFC, D_002B4A34, D_002B4DE4)) == 0) {
            return;
        }

        a.v = 0;
        w = ((s32 (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_FRIEND_CLASS_GetWindow)(friend, a);
        xb_xlive_disp_DrawRectI(w, D_002190BC, D_002B4CF8 + D_002190E8, D_0025F370, D_00799228, D_002B4BE4, 5, 0);
        xb_xlive_disp_DrawRectI(w, D_002190BC, D_002B4DA4, D_0025F370, D_007991E4, D_002B4BE4, 0, 0);
        xb_xlive_disp_DrawRectI(w, D_002190BC, D_003F8308 - D_002B4BE4, D_0025F370, D_00799264, D_002B4BE4, 4, 0);
        return;
    }

    a.v = 0;
    o = xb_FindOnlineObj(((s32 (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_FRIEND_CLASS_GetWindow)(friend, a));

    if (o != 0 && *(f32*)(o + 0x14) != D_002B4E6C) {
        a.v = 0;
        ((void (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_FRIEND_CLASS_CloseWindow)(friend, a);
        a.v = 1;
        ((void (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_FRIEND_CLASS_CloseWindow)(friend, a);
    }

    a.v = 0;
    w = ((s32 (XB_FASTCALL*)(u8*, XB_ARG, f32, f32, f32, f32))xb_XLIVE_FRIEND_CLASS_OpenWindow)(friend, a, D_002AEEC4, D_002B4CF4,
                                                                                             D_002B4E6C, D_002B4D98);
    a.v = 1;

    if ((w & ((s32 (XB_FASTCALL*)(u8*, XB_ARG, f32, f32, f32, f32))xb_XLIVE_FRIEND_CLASS_OpenWindow)(friend, a, D_002B4BEC,
                                                                                                    D_002B4CFC, D_002B4A34,
                                                                                                    D_002B4DE4)) == 0) {
        return;
    }

    a.v = 0;
    w = ((s32 (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_FRIEND_CLASS_GetWindow)(friend, a);
    xb_xlive_disp_DrawRectI(w, D_002190BC, D_002B4CF8 + D_002190E8 + D_002190C8, D_0025F370, D_00799228, D_002B4BE4, 5, 0);

    for (i = first, y = 0, row = 1; i < std__vector_Elem60__size(list) && row < 0x19; i++, row += 3, y += 0x14) {
        if (cur == i) {
            xb_xlive_disp_CheckIndex2(2, w);
            xb_xlive_disp_DrawRect1(2, D_00219408, D_002B4D94, (f32)row);
        }

        voice = 0;
        state = 0;
        a.v = i;
        a.v = (s32)((u8* (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_FRIEND_CLASS_FriendAt)(list, a);
        b.v = (s32)&voice;
        c.v = (s32)&state;
        ((void (XB_FASTCALL*)(u8*, XB_ARG, XB_ARG, XB_ARG))xb_xlive_friend_GetStatus)(self, a, b, c);

        switch (state) {
        case 1:
            xb_xlive_friend_RowIcon(D_002B4E64, y, 0);
            break;
        case 2:
            xb_xlive_friend_RowIcon(D_002B4E68, y, 1);
            break;
        case 3:
            xb_xlive_friend_RowIcon(D_002B4E68, y, 2);
            break;
        case 4:
            xb_xlive_friend_RowIcon(D_002B4E64, y, 3);
            break;
        case 5:
            xb_xlive_friend_RowIcon(D_002B4E64, y, 4);
            break;
        }

        /* the talking count: 10 frames on, 10 off while the friend talks */
        a.v = i;
        f = ((u8* (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_FRIEND_CLASS_FriendAt)(list, a);

        if (*(s32*)(f + 0x5C) == 0) {
            a.v = *(s32*)(D_00798CAC + 0x14);

            if (((s32 (XB_FASTCALL*)(u8*, XB_FXUID, XB_ARG))CXHVVoiceManager_IsTalking)(xb_LiveObj_Get8(D_00798CAC + 0x2408), *(XB_FXUID*)f,
                                                                                        a) != 0) {
                *(s32*)(f + 0x5C) = 10;
            }
        } else if (*(s32*)(f + 0x5C) < 0) {
            (*(s32*)(f + 0x5C))++;
        }

        if (*(s32*)(f + 0x5C) > 0 && --*(s32*)(f + 0x5C) == 0) {
            *(s32*)(f + 0x5C) = -10;
        }

        switch (voice) {
        case 6:
            if (*(s32*)(f + 0x5C) >= 0) {
                xb_xlive_friend_RowIcon(D_002B4D94, y, 5);
            }

            break;
        case 7:
            xb_xlive_friend_RowIcon(D_002B4D94, y, 6);
            break;
        case 8:
            xb_xlive_friend_RowIcon(D_002B4D94, y, 7);
            break;
        }

        xb_xlive_disp_DrawRectCentered(w, D_00219428, (f32)(u32)y + D_002B4DA4, D_0025F370, (s32)(f + 0xC), D_002B4BE4, 0, 1);
        xb_xlive_disp_DrawRectI(w, D_002B4E5C, (f32)(u32)y + D_002B4DA4, D_0025F370, (s32)D_002B4E60, D_002B4BE4, 0, 1);
        xb_xlive_disp_DrawRectI(w, D_002B4E00, (f32)(u32)y + D_002B4DA4, D_0025F370, (s32)D_002B4E58, D_002B4BE4, 0, 1);
    }

    more = first + 8 < std__vector_Elem60__size(list);

    if (first != 0) {
        xb_xlive_disp_DrawRectI(w, D_002190BC, D_002B4E54, D_0025F370, D_007991F4, D_002B4BE4, 5, 0);
    }

    if (more) {
        xb_xlive_disp_DrawRectI(w, D_002190BC, D_002AEF74, D_0025F370, D_0079931C, D_002B4BE4, 5, 0);
    }

    if (cur >= std__vector_Elem60__size(list)) {
        _assert(D_002B4E34, D_002B4D08, 0x1557);
    }

    a.v = cur;
    f = ((u8* (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_FRIEND_CLASS_FriendAt)(list, a);
    flags = *(u32*)(f + 0x1C);
    memset(line, 0, sizeof(line));
    memset(tmp, 0, sizeof(tmp));

    /* online, in which title, and joinable */
    if ((flags & 1) && (s32)flags >= 0) {
        if (flags & 2) {
            xb_xlive_friend_TitleLine(self, line, tmp, D_007992D0, *(s32*)(f + 0x30));

            if (flags & 0x10) {
                lstrcatW(line, tmp);
                XBUtil_GetWide(D_007991BC, tmp, 0x100);
            }
        } else {
            xb_xlive_friend_TitleLine(self, line, tmp, D_00799388, *(s32*)(f + 0x30));
        }
    } else {
        XBUtil_GetWide(D_007990B0, tmp, 0x100);
    }

    lstrcatW(line, tmp);
    xb_xlive_WideToAnsi(line, text, 0x200);
    xb_xlive_disp_DrawRectI(w, D_002190BC, D_003F8304 + D_002190C8, D_0025F370, (s32)text, D_002B4BE4, 0, 0);
    memset(line, 0, sizeof(line));

    /* the request or invite state */
    if ((s32)flags < 0) {
        s = D_00799274;
    } else if (flags & 0x40000000) {
        s = D_007993C0;
    } else if (flags & 0x8000000) {
        s = D_00799084;
    } else if (flags & 0x4000000) {
        s = (flags & 0x10000000) ? D_007991A8 : (flags & 0x20000000) ? D_00799078 : D_007993EC;
    } else {
        s = 0;
    }

    if (s != 0) {
        XBUtil_GetWide(s, tmp, 0x100);
        lstrcatW(line, tmp);
    }

    xb_xlive_WideToAnsi(line, text, 0x200);
    xb_xlive_disp_DrawRectI(w, D_002190BC, D_003F8308 - D_002AEEC4 + D_002190C8, D_0025F370, (s32)text, D_002B4BE4, 0, 0);
    xb_xlive_WideToAnsi(msg, text, 0x200);
    xb_xlive_disp_DrawRectI(w, D_002190BC, D_003F8308 - D_002B4E30 + D_002190C8, D_0025F370, (s32)text, D_002B4BE4, 0, 0);
    xb_xlive_disp_DrawRectI(w, D_002190BC, D_003F8308 - D_002B4BE4, D_0025F370, D_007991CC, D_002B4BE4, 4, 0);
}

s32 XB_FASTCALL xb_XLIVE_WORK_CLASS_FindUser(u8* self, s32 edx, u8* user);
extern s32 D_00799198;
extern s32 D_0079906C;

/* xb_xlive_friend_GetState 0xFBF4E: GetStatus's state icon, from the
 * flags alone. */
void XB_FASTCALL xb_xlive_friend_GetState(u8* self, s32 edx, u32 flags, s32* state) {
    (void)self;
    (void)edx;

    if (flags & 1) {
        *state = 1;
    }

    if ((s32)flags < 0) {
        *state = 2;
    } else if (flags & 0x40000000) {
        *state = 3;
    } else if (flags & 0x8000000) {
        *state = 4;
    } else if ((flags & 0x4000000) && !(flags & 0x30000000)) {
        *state = 5;
    }
}

/* xb_XLIVE_FRIEND_CLASS_DrawPlayerList 0x101A00: the players page, as
 * DrawFriendList for the session's players (list, work +0x3C): each
 * player's friend state, voice state (muted, or the local guest's own),
 * talking count (+0xA4) and name; the chosen player's state when it is a
 * friend. */
void XB_FASTCALL xb_XLIVE_FRIEND_CLASS_DrawPlayerList(u8* self, s32 edx, u32 first, u32 cur, u8* list, u16* msg) {
    char text[0x200];
    u16 line[0x100];
    u16 tmp[0x100];
    u8* friend = D_00798CAC + 0x25D0;
    u8* p;
    u8* q;
    u8* f;
    u8* o;
    s32 w;
    s32 y;
    u32 row;
    u32 i;
    s32 idx;
    s32 voice;
    s32 state;
    s32 guest;
    u32 flags;
    s32 more;
    const char* s;
    XB_ARG a;
    XB_ARG b;

    (void)edx;

    if (xb_LiveObj_Count(D_00798CAC + 0x3C) == 0) {
        a.v = 0;
        w = ((s32 (XB_FASTCALL*)(u8*, XB_ARG, f32, f32, f32, f32))xb_XLIVE_FRIEND_CLASS_OpenWindow)(friend, a, D_00219408, D_002B4CF4,
                                                                                                 D_002B4D94, D_002B4D98);
        a.v = 1;

        if ((w & ((s32 (XB_FASTCALL*)(u8*, XB_ARG, f32, f32, f32, f32))xb_XLIVE_FRIEND_CLASS_OpenWindow)(
                     friend, a, D_002B4BEC, D_002B4CFC, D_002B4A34, D_002B4DE4)) == 0) {
            return;
        }

        a.v = 0;
        w = ((s32 (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_FRIEND_CLASS_GetWindow)(friend, a);
        xb_xlive_disp_DrawRectI(w, D_002190BC, D_002B4CF8 + D_002190E8 + D_002190C8, D_0025F370, D_00799198, D_002B4BE4, 5, 0);
        xb_xlive_disp_DrawRectI(w, D_002190BC, D_002B4DA4, D_0025F370, D_0079906C, D_002B4BE4, 0, 0);
        xb_xlive_disp_DrawRectI(w, D_002190BC, D_003F8308 - D_002B4BE4, D_0025F370, D_00799264, D_002B4BE4, 4, 0);
        return;
    }

    a.v = 0;
    o = xb_FindOnlineObj(((s32 (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_FRIEND_CLASS_GetWindow)(friend, a));

    if (o != 0 && *(f32*)(o + 0x14) != D_002B4E6C) {
        a.v = 0;
        ((void (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_FRIEND_CLASS_CloseWindow)(friend, a);
        a.v = 1;
        ((void (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_FRIEND_CLASS_CloseWindow)(friend, a);
    }

    a.v = 0;
    w = ((s32 (XB_FASTCALL*)(u8*, XB_ARG, f32, f32, f32, f32))xb_XLIVE_FRIEND_CLASS_OpenWindow)(friend, a, D_002AEEC4, D_002B4CF4,
                                                                                             D_002B4E6C, D_002B4D98);
    a.v = 1;

    if ((w & ((s32 (XB_FASTCALL*)(u8*, XB_ARG, f32, f32, f32, f32))xb_XLIVE_FRIEND_CLASS_OpenWindow)(friend, a, D_002B4BEC,
                                                                                                    D_002B4CFC, D_002B4A34,
                                                                                                    D_002B4DE4)) == 0) {
        return;
    }

    a.v = 0;
    w = ((s32 (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_FRIEND_CLASS_GetWindow)(friend, a);
    xb_xlive_disp_DrawRectI(w, D_002190BC, D_002B4CF8 + D_002190E8, D_0025F370, D_00799198, D_002B4BE4, 5, 0);
    guest = 0;

    for (i = first, y = 0, row = 1; i < xb_LiveObj_Count(list) && row < 0x19; i++, row += 3, y += 0x14) {
        /* with two local players, the second is a guest of the first */
        if (xb_LiveObj_Count(D_00798CAC + 0x28) == 2) {
            a.v = 1;
            p = ((u8* (XB_FASTCALL*)(u8*, XB_ARG))xb_deque_LiveObj_Subscript)(D_00798CAC + 0x28, a);
            a.v = i;
            q = ((u8* (XB_FASTCALL*)(u8*, XB_ARG))xb_deque_LiveObj_Subscript)(list, a);
            guest = *(u32*)p == *(u32*)q && *(u32*)(p + 4) == *(u32*)(q + 4) && ((*(u32*)(p + 8) ^ *(u32*)(q + 8)) & 3) == 0;
        }

        if (cur == i) {
            xb_xlive_disp_CheckIndex2(2, w);
            xb_xlive_disp_DrawRect1(2, D_00219408, D_002B4D94, (f32)row);
        }

        voice = 0;
        state = 0;
        a.v = i;
        a.v = (s32)((u8* (XB_FASTCALL*)(u8*, XB_ARG))xb_deque_LiveObj_Subscript)(list, a);
        idx = ((s32 (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_FRIEND_CLASS_FindFriend)(friend, a);

        if (idx != -1) {
            a.v = idx;
            b.v = (s32)&state;
            ((void (XB_FASTCALL*)(u8*, XB_ARG, XB_ARG))xb_xlive_friend_GetState)(self, a, b);
        }

        switch (state) {
        case 1:
            xb_xlive_friend_RowIcon(D_002B4E64, y, 0);
            break;
        case 2:
            xb_xlive_friend_RowIcon(D_002B4E68, y, 1);
            break;
        case 3:
            xb_xlive_friend_RowIcon(D_002B4E68, y, 2);
            break;
        case 4:
            xb_xlive_friend_RowIcon(D_002B4E64, y, 3);
            break;
        case 5:
            xb_xlive_friend_RowIcon(D_002B4E64, y, 4);
            break;
        }

        a.v = i;
        p = ((u8* (XB_FASTCALL*)(u8*, XB_ARG))xb_deque_LiveObj_Subscript)(list, a);
        a.v = (s32)p;

        if (((s32 (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_WORK_CLASS_FindUser)(D_00798CAC, a) != 0) {
            voice = 7;
        } else if (guest) {
            a.v = 1;
            voice = *(s32*)(((u8* (XB_FASTCALL*)(u8*, XB_ARG))xb_deque_LiveObj_Subscript)(D_00798CAC + 0x28, a) + 0xA8) != 0 ? 6 : 0;
        }

        if (*(s32*)(p + 0xA4) == 0) {
            a.v = *(s32*)(D_00798CAC + 0x14);

            if (((s32 (XB_FASTCALL*)(u8*, XB_FXUID, XB_ARG))CXHVVoiceManager_IsTalking)(xb_LiveObj_Get8(D_00798CAC + 0x2408), *(XB_FXUID*)p,
                                                                                        a) != 0) {
                *(s32*)(p + 0xA4) = 10;
            }
        } else if (*(s32*)(p + 0xA4) < 0) {
            (*(s32*)(p + 0xA4))++;
        }

        if (*(s32*)(p + 0xA4) > 0 && --*(s32*)(p + 0xA4) == 0) {
            *(s32*)(p + 0xA4) = -10;
        }

        switch (voice) {
        case 6:
            if (*(s32*)(p + 0xA4) >= 0) {
                xb_xlive_friend_RowIcon(D_002B4D94, y, 5);
            }

            break;
        case 7:
            xb_xlive_friend_RowIcon(D_002B4D94, y, 6);
            break;
        case 8:
            xb_xlive_friend_RowIcon(D_002B4D94, y, 7);
            break;
        }

        xb_xlive_WideToAnsi((const u16*)(p + 0x10), text, 0x200);
        xb_xlive_disp_DrawRectCentered(w, D_00219428, (f32)(u32)y + D_002B4DA4, D_0025F370, (s32)text, D_002B4BE4, guest ? 0 : 4, 1);
        xb_xlive_disp_DrawRectI(w, D_002B4E5C, (f32)(u32)y + D_002B4DA4, D_0025F370, (s32)D_002B4E60, D_002B4BE4, 0, 1);
        xb_xlive_disp_DrawRectI(w, D_002B4E00, (f32)(u32)y + D_002B4DA4, D_0025F370, (s32)D_002B4E58, D_002B4BE4, 0, 1);
    }

    more = first + 8 < xb_LiveObj_Count(list);

    if (first != 0) {
        xb_xlive_disp_DrawRectI(w, D_002190BC, D_002B4E54, D_0025F370, D_007991F4, D_002B4BE4, 5, 0);
    }

    if (more) {
        xb_xlive_disp_DrawRectI(w, D_002190BC, D_002AEF74, D_0025F370, D_0079931C, D_002B4BE4, 5, 0);
    }

    memset(line, 0, sizeof(line));
    memset(tmp, 0, sizeof(tmp));
    a.v = cur;
    a.v = (s32)((u8* (XB_FASTCALL*)(u8*, XB_ARG))xb_deque_LiveObj_Subscript)(list, a);
    f = ((u8* (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_FRIEND_CLASS_ScanFriendsB)(friend, a);

    if (f != 0) {
        flags = *(u32*)(f + 0x1C);

        if ((flags & 1) && (s32)flags >= 0) {
            if (flags & 2) {
                xb_xlive_friend_TitleLine(self, line, tmp, D_007992D0, *(s32*)(f + 0x30));

                if (flags & 0x10) {
                    lstrcatW(line, tmp);
                    XBUtil_GetWide(D_007991BC, tmp, 0x100);
                }
            } else {
                xb_xlive_friend_TitleLine(self, line, tmp, D_00799388, *(s32*)(f + 0x30));
            }
        } else {
            XBUtil_GetWide(D_007990B0, tmp, 0x100);
        }

        lstrcatW(line, tmp);
        xb_xlive_WideToAnsi(line, text, 0x200);
        xb_xlive_disp_DrawRectI(w, D_002190BC, D_003F8304 + D_002190C8, D_0025F370, (s32)text, D_002B4BE4, 0, 0);
        memset(line, 0, sizeof(line));

        if ((s32)flags < 0) {
            s = D_00799274;
        } else if (flags & 0x40000000) {
            s = D_007993C0;
        } else if (flags & 0x8000000) {
            s = D_00799084;
        } else if (flags & 0x4000000) {
            s = (flags & 0x10000000) ? D_007991A8 : (flags & 0x20000000) ? D_00799078 : D_007993EC;
        } else {
            s = 0;
        }

        if (s != 0) {
            XBUtil_GetWide(s, tmp, 0x100);
            lstrcatW(line, tmp);
        }
    }

    xb_xlive_WideToAnsi(line, text, 0x200);
    xb_xlive_disp_DrawRectI(w, D_002190BC, D_003F8308 - D_002AEEC4 + D_002190C8, D_0025F370, (s32)text, D_002B4BE4, 0, 0);
    xb_xlive_WideToAnsi(msg, text, 0x200);
    xb_xlive_disp_DrawRectI(w, D_002190BC, D_003F8308 - D_002B4E30 + D_002190C8, D_0025F370, (s32)text, D_002B4BE4, 0, 0);
    xb_xlive_disp_DrawRectI(w, D_002190BC, D_003F8308 - D_002B4BE4, D_0025F370, D_007991CC, D_002B4BE4, 4, 0);
}

/* xb_xlive_WideToAnsi 0xFC14A: wide text converted to the code page, at
 * most n - 1 characters. */
void xb_xlive_WideToAnsi(const u16* src, char* dst, s32 n) {
    s32 len;

    if (dst == 0) {
        _assert(D_00219690, D_002B4D08, 0x1AC2);
    }

    if (src == 0) {
        _assert(D_00219680, D_002B4D08, 0x1AC3);
    }

    if (n <= 0) {
        _assert(D_00219674, D_002B4D08, 0x1AC8);
    }

    len = wcslen(src);

    if (len > n - 1) {
        len = n - 1;
    }

    if (len != WideCharToMultiByte(0, 0, src, len, dst, n, 0, 0) - 1) {
        _assert(D_002B4DB8, D_002B4D08, 0x1AD3);
    }
}

/* The page drawers below are methods of the window's text (friend window
 * +0x60, which Printf writes). */

extern f32 D_002B4CF0;
extern f32 D_002AEEEC;
extern char D_002B4DA8[];
extern s32 D_00799178;
extern s32 D_007991DC;
extern s32 D_007993A0;
extern s32 D_00799294;
extern s32 D_00799318;
extern s32 D_007992B8;
extern s32 D_007990A4;

/* xb_xlive_friend_DrawRequest 0xFBDD9: the friend request box (the page
 * rectangle D_003F82C4): sent or received (flag 0x40), and its prompt. */
void XB_FASTCALL xb_xlive_friend_DrawRequest(u16* self, s32 edx, s32 cur, u8* f) {
    (void)self;
    (void)edx;
    (void)cur;

    if (f == 0) {
        _assert(D_002B4DA8, D_002B4D08, 0x188D);
    }

    xb_xlive_disp_DrawRectI(D_003F82C4, D_002B4CF0, D_002B4DA4, D_0025F370, (f[0x1F] & 0x40) ? D_007991DC : D_007993A0, D_002B4BE4,
                            0, 0);
    xb_xlive_disp_DrawRectI(D_003F82C4, D_002B4CF0, D_002AEEEC, D_0025F370, D_00799070, D_002B4BE4, 4, 0);
    xb_OnlineObj_SetRect(D_003F82C4, 0x8C, 0x4E, 0x1F4, 0xD4);
}

/* xb_xlive_friend_DrawBoxMessage 0xFBFA4: the message box's text by
 * state: 0 the message (kind 0xD for the other one) and its prompt, 1 the
 * player's own (by user index) and its prompt. */
void XB_FASTCALL xb_xlive_friend_DrawBoxMessage(u16* self, s32 edx, s32 state, s32 kind) {
    s32 tbl[4];
    s32 msg;

    (void)self;
    (void)edx;
    msg = kind != 0 ? D_00799258 : D_00799178;

    switch (state) {
    case 0:
        if (xb_OnlineObj_IsDone(D_003F82CC)) {
            xb_xlive_disp_DrawRectI(D_003F82CC, 0.0f, D_00219410, D_0025F370, msg, D_002B4BE4, 0, 0);
            xb_xlive_disp_DrawRectI(D_003F82CC, 0.0f, D_00219404, D_0025F370, D_00799070, D_002B4BE4, 4, 0);
        }

        break;

    case 1:
        if (xb_OnlineObj_IsDone(D_003F82CC)) {
            tbl[0] = D_00799294;
            tbl[1] = D_00799318;
            tbl[2] = D_007992B8;
            tbl[3] = D_007990A4;
            xb_xlive_disp_DrawRectI(D_003F82CC, 0.0f, D_002B4D9C, D_0025F370, tbl[*(s32*)(D_00798CAC + 0x14)], D_002B4BE4, 0, 0);
            xb_xlive_disp_DrawRectI(D_003F82CC, 0.0f, D_00219404, D_0025F370, D_00799264, D_002B4BE4, 4, 0);
        }

        break;
    }
}

/* xb_xlive_friend_DrawText 0xFCB83: the window's text in the box, with
 * its prompt. */
void XB_FASTCALL xb_xlive_friend_DrawText(u16* self) {
    char text[0x200];

    if (xb_OnlineObj_IsActive(D_003F82CC) == 0) {
        return;
    }

    xb_xlive_WideToAnsi(self, text, 0x200);
    xb_xlive_disp_DrawRectI(D_003F82CC, 0.0f, D_00219410, D_0025F370, (s32)text, D_002B4BE4, 0, 0);
    xb_xlive_disp_DrawRectI(D_003F82CC, 0.0f, D_00219404, D_0025F370, D_00799264, D_002B4BE4, 4, 0);
}

extern f32 D_002AEF7C;
extern f32 D_002B4DE0;
extern f32 D_002B4DA0;
extern f32 D_002B4DD8;
extern f32 D_002B4DD4;
extern f32 D_002B4DD0;
extern s32 D_007991E0;
extern s32 D_00799124;
extern s32 D_00799290;
extern s32 D_00799188;
extern s32 D_007993BC;

/* xb_xlive_friend_DrawFeedback 0xFC94F: the feedback page: the user's
 * name (+0x10), then the complaints with the cursor (in the box
 * D_003F82C8) or, when confirming, the question. */
void XB_FASTCALL xb_xlive_friend_DrawFeedback(u16* self, s32 edx, u32 cur, s32 confirm, u8* user) {
    char text[0x200];

    (void)self;
    (void)edx;
    xb_xlive_WideToAnsi((const u16*)(user + 0x10), text, 0x200);
    xb_xlive_disp_DrawRectCentered(D_003F82C4, D_002190D4, D_002AEF7C, D_0025F370, (s32)text, D_002B4BE4, 7, 0);
    xb_xlive_disp_DrawRectI(D_003F82C4, D_002B4DE0, D_002B4DA4, D_0025F370, D_007991E0, D_002B4BE4, 5, 0);

    if (confirm == 0) {
        xb_xlive_disp_DrawRect1(3, D_00219408, D_002B4D94, (f32)cur);
        xb_xlive_disp_CheckIndex2(3, D_003F82C8);
        xb_xlive_disp_DrawRectI(D_003F82C8, D_002B4DDC, D_002B4DA0, D_0025F370, D_00799124, D_002B4BE4, 0, 0);
        xb_xlive_disp_DrawRectI(D_003F82C8, D_002B4DDC, D_002B4DD8, D_0025F370, D_00799290, D_002B4BE4, 4, 0);
        xb_OnlineObj_SetRect(D_003F82C8, 0x8C, 0x4E, 0x1F4, 0x156);
    } else {
        xb_xlive_disp_DrawRectI(D_003F82C8, D_002190BC, D_002B4DA0, D_0025F370, D_00799188, D_002B4BE4, 0, 0);
        xb_xlive_disp_DrawRectI(D_003F82C8, D_002B4DD0, D_002B4DD4, D_0025F370, D_007993BC, D_002B4BE4, 4, 0);
        xb_OnlineObj_SetRect(D_003F82C8, 0x8C, 0x4E, 0x1F4, 0xDE);
    }
}

/* The friend window's getters. */
s32 XB_FASTCALL xb_XLIVE_FRIEND_CLASS_GetFromMatch(u8* self) {
    return *(s32*)(self + 0xA84);
}

s32 XB_FASTCALL xb_XLIVE_FRIEND_CLASS_GetPlayerCursor(u8* self) {
    return *(s32*)(self + 0x958);
}

s32 XB_FASTCALL xb_XLIVE_FRIEND_CLASS_GetFriendCursor(u8* self) {
    return *(s32*)(self + 0x8C4);
}

s32 XB_FASTCALL xb_XLIVE_FRIEND_CLASS_GetWaitState(u8* self) {
    return *(s32*)(self + 0x2A3C);
}

/* xb_XLIVE_FRIEND_CLASS_CopyPlayer 0xFC4D3: the chosen player (+0x960,
 * 0xB0 bytes) copied out. */
u8* XB_FASTCALL xb_XLIVE_FRIEND_CLASS_CopyPlayer(u8* self, s32 edx, u8* out) {
    (void)edx;
    memcpy(out, self + 0x960, 0xB0);
    return out;
}

extern f32 D_002B4E98;
extern s32 D_00799088;
extern s32 D_007993C4;
extern s32 D_007992F4;
extern char* D_00799268;

/* xb_xlive_friend_DrawComplaint 0x1006F0: the box asking whether to send
 * feedback about a player: the list with the cursor (or the question when
 * confirming), and the player's name: the chosen player from a match, or
 * the chosen friend. */
void XB_FASTCALL xb_xlive_friend_DrawComplaint(u16* self, s32 edx, u32 cur, s32 confirm, u8* f) {
    char title[0x200];
    char name[0x200];
    u8 player[0xB0];
    u8* friend;
    u8* list;
    s32 match;
    XB_ARG a;

    (void)self;
    (void)edx;
    (void)f;

    if (xb_OnlineObj_IsActive(D_003F82CC) == 0) {
        return;
    }

    if (confirm == 0) {
        xb_xlive_disp_DrawRectI(D_003F82CC, 0.0f, D_00219410, D_0025F370, D_00799088, D_002B4BE4, 0, 0);
        xb_xlive_disp_DrawRect1(3, D_00219408, D_002B4D94, (f32)cur);
        xb_xlive_disp_CheckIndex2(3, D_003F82CC);
        xb_xlive_disp_DrawRectI(D_003F82CC, 0.0f, D_002B4E98, D_0025F370, D_007993C4, D_002B4BE4, 4, 0);
    } else {
        xb_xlive_disp_DrawRectI(D_003F82CC, 0.0f, D_00219410, D_0025F370, D_00799188, D_002B4BE4, 0, 0);
        xb_xlive_disp_DrawRectI(D_003F82CC, 0.0f, D_002B4E98, D_0025F370, D_007993BC, D_002B4BE4, 4, 0);
    }

    xb_xlive_disp_DrawRectI(D_003F82CC, 0.0f, D_00219098, D_0025F370, D_007992F4, D_002B4BE4, 5, 0);
    friend = D_00798CAC + 0x25D0;
    match = xb_XLIVE_FRIEND_CLASS_GetFromMatch(friend);
    memset(title, 0, sizeof(title));
    memset(name, 0, sizeof(name));
    list = xb_XLIVE_FRIEND_CLASS_GetFriendList(friend);
    strcpy(title, D_00799268);

    if (match != 0) {
        a.v = (s32)player;
        xb_xlive_WideToAnsi((const u16*)(((u8* (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_FRIEND_CLASS_CopyPlayer)(friend, a) + 0x10), name, 0x200);
    } else {
        a.v = xb_XLIVE_FRIEND_CLASS_GetFriendCursor(friend);
        strcpy(name, (const char*)(((u8* (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_FRIEND_CLASS_FriendAt)(list, a) + 0xC));
    }

    strcat(title, name);
    xb_xlive_disp_DrawRectI(D_003F82CC, 0.0f, D_00219408, D_0025F370, (s32)title, D_002B4BE4, 7, 0);
}

u32* XB_FASTCALL xb_iterator4_inc(u32* self);
extern s32 D_00799238;
extern s32 D_007990FC;
extern s32 D_007991B4;
extern s32 D_007992E0;
extern s32 D_00799404;
extern s32 D_007991AC;
extern s32 D_00799230;
extern s32 D_007993FC;
extern s32 D_00799108;
extern s32 D_00799190;
extern s32 D_007993F8;
extern s32 D_00799208;
extern s32 D_0079932C;
extern s32 D_007993D8;
extern s32 D_00799138;
extern s32 D_00799200;
extern s32 D_007990D4;
extern s32 D_00799324;
extern s32 D_007990CC;
extern s32 D_007990F8;
extern s32 D_007991F8;
extern s32 D_007993F4;
extern s32 D_00799158;
extern s32 D_007991EC;
extern s32 D_007992A4;
extern s32 D_00799344;
extern s32 D_0079910C;
extern s32 D_00799354;
extern s32 D_0079940C;
extern s32 D_007990E0;
extern s32 D_00799194;
extern s32 D_00799094;
extern s32 D_00799248;
extern s32 D_0079926C;
extern f32 D_002AEEA8;
extern f32 D_002B4E70;
extern char D_002B4E74[];
extern char D_002B4E84[];

/* xb_xlive_friend_DrawActions 0x100305: the friend's action menu: each
 * action of the list (the window's +0xA70, at most 16) by name, the cursor
 * with its help, a pending request (flag 0x40) shown for action 8, and the
 * box sized to the list. */
void XB_FASTCALL xb_xlive_friend_DrawActions(u16* self, s32 edx, u32 cur, u8* actions, u8* f) {
    s32 name[16];
    s32 help[16];
    void* it;
    void* end;
    s32 act;
    s32 sent;
    u32 i;
    s32 y;
    XB_ARG a;

    (void)self;
    (void)edx;

    if ((u8)xb_xlive_friend_IsEmpty(actions) != 0) {
        _assert(D_002B4E84, D_002B4D08, 0x178B);
    }

    name[0] = D_00799238;
    name[1] = D_007990FC;
    name[2] = D_007991B4;
    name[3] = D_007992E0;
    name[4] = D_00799404;
    name[5] = D_007991AC;
    name[6] = D_00799230;
    name[7] = D_007993FC;
    name[8] = D_00799108;
    name[9] = D_00799190;
    name[10] = D_007993F8;
    name[11] = D_00799208;
    name[12] = D_0079932C;
    name[13] = D_007993D8;
    name[14] = D_00799138;
    name[15] = D_00799200;
    help[0] = D_007990D4;
    help[1] = D_00799324;
    help[2] = D_007990CC;
    help[3] = D_007990F8;
    help[4] = D_007991F8;
    help[5] = D_007993F4;
    help[6] = D_00799158;
    help[7] = D_007991EC;
    help[8] = D_007992A4;
    help[9] = D_00799344;
    help[10] = D_0079910C;
    help[11] = D_00799354;
    help[12] = D_0079940C;
    help[13] = D_007990E0;
    help[14] = D_00799194;
    help[15] = D_00799094;
    sent = f != 0 && (f[0x1F] & 0x40);
    a.v = (s32)&it;
    ((void* (XB_FASTCALL*)(u8*, XB_ARG))xb_xlive_friend_GetElem4)(actions, a);

    for (i = 0, y = 0;; i++, y += 0x14) {
        a.v = (s32)&end;
        a.v = (s32)((void* (XB_FASTCALL*)(u8*, XB_ARG))xb_xlive_friend_GetElem8)(actions, a);

        if ((u8)((s32 (XB_FASTCALL*)(void*, XB_ARG))xb_xlive_disp_IsMissing)(&it, a) == 0) {
            break;
        }

        if (*(s32*)xb_xlive_ThunkFC23E((u8*)&it) >= 0x10) {
            _assert(D_002B4E74, D_002B4D08, 0x17D9);
        }

        act = *(s32*)xb_xlive_ThunkFC23E((u8*)&it);
        xb_xlive_disp_DrawRectI(D_003F82C4, D_002AEEA8, (f32)(u32)y + D_002B4DA4, D_0025F370, (sent && act == 8) ? D_00799248 : name[act],
                                D_002B4BE4, 0, 0);

        if (cur == i) {
            xb_xlive_disp_CheckIndex2(3, D_003F82C4);
            xb_xlive_disp_DrawRect1(3, D_00219408, D_002B4D94, (f32)(i + 1));
            act = *(s32*)xb_xlive_ThunkFC23E((u8*)&it);
            xb_xlive_disp_DrawRectI(D_003F82C4, D_002190BC, D_003F8308 - D_002AEEC4, D_0025F370,
                                    (sent && act == 8) ? D_0079926C : help[act], D_002B4BE4, 0, 0);
        }

        xb_iterator4_inc((u32*)&it);
    }

    xb_OnlineObj_SetRect(D_003F82C4, 0x8C, 0x4E, 0x1F4, (s32)((f32)((i * 5 + 5) * 4) + D_002B4E70));
    xb_xlive_disp_DrawRectI(D_003F82C4, D_002190BC, D_003F8308 - D_002B4BE4, D_0025F370, D_007991CC, D_002B4BE4, 4, 0);
    xb_OnlineObj_SetRect(D_003F82C8, 0x1C, 0x13E, 0x266, 0x1A6);
}

u8* XB_FASTCALL xb_XLIVE_FRIEND_CLASS_GetState2A48(u8* self);
void xb_xlive_disp_SetBar(s32 v, f32 x, f32 y, f32 w, f32 h, f32 z, s32 col, f32 depth);
s32 sprintf(char* buf, const char* fmt, ...);
extern f32 D_0021940C;
extern f32 D_002193F8;
extern f32 D_0021942C;
extern f32 D_002B4EA0;
extern f32 D_002B4E9C;
extern f32 D_002190B4;
extern s32 D_007993B4;
extern s32 D_007990E4;
extern s32 D_007991D0;
extern s32 D_007993D0;
extern s32 D_00799220;
extern s32 D_00799254;
extern s32 D_00799098;
extern s32 D_0079920C;
extern s32 D_00799064;
extern char* D_007991F0;
extern char* D_0079929C;

/* xb_xlive_friend_DrawVoiceMail 0x10098A: the voice-mail page: the four
 * actions (grey when closed), the cursor, the friend's or player's name,
 * the recording bar and seconds left, and the message for the action
 * under the cursor (in the box D_003F82D0). */
void XB_FASTCALL xb_xlive_friend_DrawVoiceMail(u16* self, s32 edx, s32 st, s32 cur) {
    char title[0x200];
    char name[0x200];
    u8 player[0xB0];
    u8* friend;
    u8* list;
    s32* open;
    s32 match;
    s32 msg;
    XB_ARG a;

    (void)self;
    (void)edx;
    (void)st;

    if (xb_OnlineObj_IsActive(D_003F82CC) == 0) {
        return;
    }

    msg = 0;

    switch (cur) {
    case 0:
        msg = D_00799220;
        break;
    case 1:
        msg = D_00799254;
        break;
    case 2:
        msg = D_00799098;
        break;
    case 3:
        msg = D_0079920C;
        break;
    }

    open = (s32*)xb_XLIVE_FRIEND_CLASS_GetState2A48(D_00798CAC + 0x25D0);
    xb_xlive_disp_DrawRectI(D_003F82CC, 0.0f, D_00219410, D_0025F370, D_007993B4, D_002B4BE4, open[0] != 0 ? 0 : 6, 0);
    xb_xlive_disp_DrawRectI(D_003F82CC, 0.0f, D_002B4D9C, D_0025F370, D_007990E4, D_002B4BE4, open[1] != 0 ? 0 : 6, 0);
    xb_xlive_disp_DrawRectI(D_003F82CC, 0.0f, D_002B4DDC, D_0025F370, D_007991D0, D_002B4BE4, open[2] != 0 ? 0 : 6, 0);
    xb_xlive_disp_DrawRectI(D_003F82CC, 0.0f, D_0021940C, D_0025F370, D_007993D0, D_002B4BE4, open[3] != 0 ? 0 : 6, 0);
    xb_xlive_disp_DrawRect1(2, 0.0f, 0.0f, (f32)cur);
    xb_xlive_disp_CheckIndex2(2, D_003F82CC);
    xb_xlive_disp_DrawRectI(D_003F82CC, 0.0f, D_002193F8, D_0025F370, D_00799200, D_002B4BE4, 5, 0);
    friend = D_00798CAC + 0x25D0;
    match = xb_XLIVE_FRIEND_CLASS_GetFromMatch(friend);
    memset(title, 0, sizeof(title));
    memset(name, 0, sizeof(name));
    list = xb_XLIVE_FRIEND_CLASS_GetFriendList(friend);
    strcpy(title, D_007991F0);

    if (match == 0) {
        a.v = xb_XLIVE_FRIEND_CLASS_GetFriendCursor(friend);
        strcpy(name, (const char*)(((u8* (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_FRIEND_CLASS_FriendAt)(list, a) + 0xC));
    } else {
        a.v = (s32)player;
        xb_xlive_WideToAnsi((const u16*)(((u8* (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_FRIEND_CLASS_CopyPlayer)(friend, a) + 0x10), name, 0x200);
    }

    strcat(title, name);
    xb_xlive_disp_DrawRectI(D_003F82CC, 0.0f, D_002AEEC4, D_0025F370, (s32)title, D_002B4BE4, 7, 0);
    xb_xlive_disp_SetBar((s32)*(f32*)(D_00798CAC + 0x24B0), D_0021942C, D_002B4EA0, D_00219404, D_002B4DCC, 0.0f, 0xFFFF0000,
                         D_002190A8);
    sprintf(title, D_0079929C, (s32)*(f32*)(D_00798CAC + 0x24B4));
    xb_xlive_disp_DrawRectI(D_003F82CC, 0.0f, D_0021941C, D_0025F370, (s32)title, D_002B4BE4, 2, 0);
    xb_xlive_disp_DrawRectI(D_003F82D0, 0.0f, D_002190B4, D_0025F370, msg, D_002B4BE4, 0, 0);
    xb_xlive_disp_DrawRectI(D_003F82D0, 0.0f, D_002B4E9C, D_0025F370, D_00799064, D_002B4BE4, 4, 0);
}

u8 xb_OnlineObj_Exists(s32 id);
extern f32 D_002B4EA4;
extern s32 D_0079937C;
extern s32 D_0079935C;
extern s32 D_00799130;

/* xb_xlive_friend_DrawReceived 0x1027DE: a received voice message's page:
 * its three actions (grey when closed), the cursor, the sender, the
 * playing bar and seconds left, and the message for the action; from
 * state 10 the box's closing message. */
void XB_FASTCALL xb_xlive_friend_DrawReceived(u16* self, s32 edx, s32 st, s32 cur) {
    char title[0x200];
    char name[0x200];
    u8* friend;
    u8* list;
    s32* open;
    s32 match;
    s32 msg;
    XB_ARG a;

    (void)self;
    (void)edx;

    if (st >= 10) {
        if (xb_OnlineObj_IsActive(D_003F82CC) != 0) {
            xb_xlive_disp_DrawRectI(D_003F82CC, 0.0f, D_00219410, D_0025F370, D_00799130, D_002B4BE4, 0, 0);
            xb_xlive_disp_DrawRectI(D_003F82CC, 0.0f, D_00219404, D_0025F370, D_00799264, D_002B4BE4, 4, 0);
        }

        return;
    }

    if (!xb_OnlineObj_Exists(D_003F82CC) || !xb_OnlineObj_IsDone(D_003F82CC)) {
        return;
    }

    friend = D_00798CAC + 0x25D0;

    if (xb_XLIVE_FRIEND_CLASS_GetWaitState(friend) == 1) {
        return;
    }

    msg = 0;

    switch (cur) {
    case 0:
        msg = D_0079937C;
        break;
    case 1:
        msg = D_0079935C;
        break;
    case 2:
        msg = D_0079910C;
        break;
    }

    open = (s32*)xb_XLIVE_FRIEND_CLASS_GetState2A48(friend);
    xb_xlive_disp_DrawRectI(D_003F82CC, 0.0f, D_002AEEA8, D_0025F370, D_007990E4, D_002B4BE4, open[0] != 0 ? 0 : 6, 0);
    xb_xlive_disp_DrawRectI(D_003F82CC, 0.0f, D_002B4EA4, D_0025F370, D_007991D0, D_002B4BE4, open[1] != 0 ? 0 : 6, 0);
    xb_xlive_disp_DrawRectI(D_003F82CC, 0.0f, D_002B4DE0, D_0025F370, D_007992F4, D_002B4BE4, open[2] != 0 ? 0 : 6, 0);
    xb_xlive_disp_DrawRect1(2, 0.0f, 0.0f, (f32)cur);
    xb_xlive_disp_CheckIndex2(2, D_003F82CC);
    xb_xlive_disp_DrawRectI(D_003F82CC, 0.0f, D_002193F8, D_0025F370, D_00799200, D_002B4BE4, 5, 0);
    match = xb_XLIVE_FRIEND_CLASS_GetFromMatch(friend);
    memset(title, 0, sizeof(title));
    memset(name, 0, sizeof(name));
    list = xb_XLIVE_FRIEND_CLASS_GetFriendList(friend);
    strcpy(title, D_007991F0);

    if (match == 0) {
        a.v = xb_XLIVE_FRIEND_CLASS_GetFriendCursor(friend);
        strcpy(name, (const char*)(((u8* (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_FRIEND_CLASS_FriendAt)(list, a) + 0xC));
    } else {
        a.v = xb_XLIVE_FRIEND_CLASS_GetPlayerCursor(friend);
        xb_xlive_WideToAnsi((const u16*)(((u8* (XB_FASTCALL*)(u8*, XB_ARG))xb_deque_LiveObj_Subscript)(D_00798CAC + 0x3C, a) + 0x10), name, 0x200);
    }

    strcat(title, name);
    xb_xlive_disp_DrawRectI(D_003F82CC, 0.0f, D_002AEEC4, D_0025F370, (s32)title, D_002B4BE4, 7, 0);
    xb_xlive_disp_SetBar((s32)*(f32*)(D_00798CAC + 0x24B0), D_0021942C, D_002B4EA0, D_00219404, D_002B4DCC, 0.0f, 0xFFFF0000,
                         D_002190A8);
    sprintf(title, D_0079929C, (s32)*(f32*)(D_00798CAC + 0x24B4));
    xb_xlive_disp_DrawRectI(D_003F82CC, 0.0f, D_0021941C, D_0025F370, (s32)title, D_002B4BE4, 2, 0);
    xb_xlive_disp_DrawRectI(D_003F82D0, 0.0f, D_002190B4, D_0025F370, msg, D_002B4BE4, 0, 0);
    xb_xlive_disp_DrawRectI(D_003F82D0, 0.0f, D_002B4E9C, D_0025F370, D_00799064, D_002B4BE4, 4, 0);
}
