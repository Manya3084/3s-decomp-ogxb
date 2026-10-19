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
