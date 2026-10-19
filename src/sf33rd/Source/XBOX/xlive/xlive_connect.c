/* xlive_connect.c: the Live "connected users" counter, retail sf33rd.xbe.
 * Xbox-only C++ written as C, as in xlive_voice.c: a method is XB_FASTCALL
 * with this first and an unused edx, and calls to methods pass their stack
 * arguments as XB_ARG. The class (xb_CONNECT_USER_CLASS) is a text window
 * (xb_WINSTR_CLASS) that shows how many users are in sessions: it starts
 * an XOnlineMatchSearch with an online task at +0x58, polls it, and writes
 * the count. The xb_ names are made up. */

#include "types.h"
#include <string.h>
char* _itoa(s32 v, char* buf, s32 radix);

typedef struct {
    u32 id;
    u32 pad;
    s64 value;
} XB_XATTR;

s32 XB_FASTCALL CXBOnlineTask_IsOpen(void* self);
s32 XB_FASTCALL CXBOnlineTask_Close(void* self);
s32 XB_FASTCALL CXBOnlineTask_Continue(void* self);
s32 XB_FASTCALL CXBOnlineTask_operator_addr(void* self);
s32 XB_FASTCALL xb_iterator_Deref(u8* self);
void XB_FASTCALL xb_WINSTR_CLASS_SetString(u8* self, s32 edx, const char* msg);
void XB_FASTCALL xb_WINSTR_CLASS_Reset(u8* self);
void XB_FASTCALL xb_WINSTR_CLASS_SetPos(u8* self, s32 edx, f32 x, f32 y, f32 w, f32 h, const char* str);
void XB_FASTCALL WINSTR_CLASS_SetCenteringState(u8* self, s32 edx, s32 state);
void XB_FASTCALL xb_CONNECT_USER_CLASS_SetActive(u8* self, s32 edx, u8 on);
u8* XB_FASTCALL xb_xlive_match_GetAddr30(u8* self);
s32 xb_GetLiveLanguage(void);
s32 xb_xlive_main_SetMatchArgs(s32 hr, const char* file, s32 line, s32 a);
s32 XB_STDCALL XOnlineMatchSearchResultsLen(u32 max, u32 nattr, void* attr);
s32 XB_STDCALL XOnlineMatchSearch(u32 proc, u32 max, u32 nattr, XB_XATTR* attr, u32 len, void* ev, void* task);
s32 XB_STDCALL XOnlineMatchSearchGetResults(s32 task, void* results, u32* count);
extern u8* D_00798CAC;
extern char* D_00799100;
extern char* D_007992D8;
extern f32 D_002B4A30;
extern f32 D_002B4A34;
extern f32 D_002B4A38;
extern char D_002B4A40[];

/* xb_xlive_StartUserSearch 0xF7BE3: an XOnlineMatchSearch (procedure 5, up
 * to 50 results) on one 64-bit attribute; the largest value stands for
 * any (attribute 0xF00000). */
s32 xb_xlive_StartUserSearch(s64 v, void* ev, void* task) {
    XB_XATTR at;
    s32 len;

    len = XOnlineMatchSearchResultsLen(0x32, 0, 0);
    memset(&at.pad, 0, 12);

    if (v == 0x7FFFFFFFFFFFFFFF) {
        at.id = 0xF00000;
    } else {
        at.id = 0;
    }

    at.value = v;
    return XOnlineMatchSearch(5, 0x32, 1, &at, len, ev, task);
}

/* xb_WINSTR_CLASS_SetMargin 0xF7D72: a text window's margins (+0x20,
 * +0x24). */
void XB_FASTCALL xb_WINSTR_CLASS_SetMargin(u8* self, s32 edx, s32 x, s32 y) {
    (void)edx;
    *(s32*)(self + 0x20) = x;
    *(s32*)(self + 0x24) = y;
}

/* xb_CONNECT_USER_CLASS_SetCountText 0xF7CB8: the window's text, the
 * label (D_00799100) and the count, and the count kept at +0x54. */
void XB_FASTCALL xb_CONNECT_USER_CLASS_SetCountText(u8* self, s32 edx, s32 n) {
    char num[0x14];
    char text[0x20];
    XB_ARG a;

    (void)edx;
    memset(num, 0, sizeof(num));
    strcpy(text, D_00799100);
    _itoa(n, num, 10);
    strcat(text, num);
    a.v = (s32)text;
    ((void (XB_FASTCALL*)(u8*, XB_ARG))xb_WINSTR_CLASS_SetString)(self, a);
    *(s32*)(self + 0x54) = n;
}

/* xb_CONNECT_USER_CLASS_IsTaskDone 0xF7C3E: unless a search is running,
 * starts one for the current user (work +8) and shows the waiting text
 * (D_007992D8). Returns the search's result, 0 when one was running. */
s32 XB_FASTCALL xb_CONNECT_USER_CLASS_IsTaskDone(u8* self) {
    s32 r;
    XB_ARG a;

    if (CXBOnlineTask_IsOpen(self + 0x58) != 0) {
        return 0;
    }

    r = xb_xlive_StartUserSearch(*(s32*)(D_00798CAC + 8), 0, (void*)CXBOnlineTask_operator_addr(self + 0x58));
    *(s32*)(self + 0x5C) = 1;
    a.v = (s32)D_007992D8;
    ((void (XB_FASTCALL*)(u8*, XB_ARG))xb_WINSTR_CLASS_SetString)(self, a);
    return r;
}

/* xb_CONNECT_USER_CLASS_Open 0xF7DD3: the window placed (its y by the
 * Live language), centred, with its margins, and shown. */
void XB_FASTCALL xb_CONNECT_USER_CLASS_Open(u8* self) {
    s32 y;
    XB_ARG a;
    XB_ARG b;

    xb_WINSTR_CLASS_Reset(self);
    y = xb_GetLiveLanguage() != 0 ? 0x12C : 0x19A;
    a.v = (s32)xb_xlive_match_GetAddr30(self);
    ((void (XB_FASTCALL*)(u8*, f32, f32, f32, f32, XB_ARG))xb_WINSTR_CLASS_SetPos)(self, (f32)y, D_002B4A30, D_002B4A34, D_002B4A38, a);
    a.v = 1;
    ((void (XB_FASTCALL*)(u8*, XB_ARG))WINSTR_CLASS_SetCenteringState)(self, a);
    a.v = y + 10;
    b.v = 0;
    ((void (XB_FASTCALL*)(u8*, XB_ARG, XB_ARG))xb_WINSTR_CLASS_SetMargin)(self, a, b);
    a.v = 1;
    ((void (XB_FASTCALL*)(u8*, XB_ARG))xb_CONNECT_USER_CLASS_SetActive)(self, a);
}

/* xb_CONNECT_USER_CLASS_PollSearch 0xF7E4B: the running search polled.
 * When it ends the users of all sessions it found are counted and shown
 * (returns 1); on an error the task is closed, the count cleared, the
 * error reported and kept at +0x60 (returned). 0 while it runs. */
s32 XB_FASTCALL xb_CONNECT_USER_CLASS_PollSearch(u8* self) {
    u8** res;
    u32 n;
    u32 i;
    s32 users;
    s32 hr;
    XB_ARG a;

    hr = CXBOnlineTask_Continue(self + 0x58);

    if (hr == 0) {
        return 0;
    }

    if (hr >= 0) {
        hr = XOnlineMatchSearchGetResults(xb_iterator_Deref(self + 0x58), &res, &n);

        if (hr >= 0) {
            users = 0;

            for (i = 0; i < n; i++) {
                users += *(s32*)(res[i] + 0x48);
            }

            a.v = users;
            ((void (XB_FASTCALL*)(u8*, XB_ARG))xb_CONNECT_USER_CLASS_SetCountText)(self, a);
            CXBOnlineTask_Close(self + 0x58);
            *(s32*)(self + 0x5C) = 0;
            return 1;
        }
    }

    CXBOnlineTask_Close(self + 0x58);
    a.v = 0;
    ((void (XB_FASTCALL*)(u8*, XB_ARG))xb_CONNECT_USER_CLASS_SetCountText)(self, a);
    *(s32*)(self + 0x5C) = 2;
    xb_xlive_main_SetMatchArgs(hr, D_002B4A40, 0xD5, 1);
    *(s32*)(self + 0x60) = hr;
    return hr;
}

/* xb_CONNECT_USER_CLASS_SetState 0xF7EF0: a running search stopped and
 * the count cleared. */
void XB_FASTCALL xb_CONNECT_USER_CLASS_SetState(u8* self) {
    XB_ARG a;

    if (CXBOnlineTask_IsOpen(self + 0x58) != 0) {
        CXBOnlineTask_Close(self + 0x58);
        a.v = 0;
        ((void (XB_FASTCALL*)(u8*, XB_ARG))xb_CONNECT_USER_CLASS_SetCountText)(self, a);
    }

    *(s32*)(self + 0x5C) = 0;
}

u8* XB_FASTCALL xb_WINSTR_CLASS_ctor(u8* self);
void** XB_FASTCALL xb_iterator_ctor(void** self, s32 edx, void* p);
void XB_FASTCALL CXBOnlineTask_dtor(void* self);

/* xb_CONNECT_USER_CLASS_ctor 0xF7D83: the counter window with no search
 * (task +0x58) and no count. */
u8* XB_FASTCALL xb_CONNECT_USER_CLASS_ctor(u8* self) {
    XB_ARG a;

    xb_WINSTR_CLASS_ctor(self);
    self[0x50] = 0;
    *(s32*)(self + 0x54) = 0;
    a.v = 0;
    ((void** (XB_FASTCALL*)(void**, XB_ARG))xb_iterator_ctor)((void**)(self + 0x58), a);
    *(s32*)(self + 0x5C) = 0;
    *(s32*)(self + 0x60) = 0;
    xb_WINSTR_CLASS_Reset(self);
    return self;
}

/* xb_CONNECT_USER_CLASS_dtor 0xF7DCB. */
void XB_FASTCALL xb_CONNECT_USER_CLASS_dtor(u8* self) {
    CXBOnlineTask_dtor(self + 0x58);
}

void xb_SeSelectedThunk(void);
s32 xb_LivePadAccept(void);
void xb_LiveWork_EndError(void);
void XB_FASTCALL xb_XLIVE_WORK_CLASS_SetState3(u8* self);
void XB_FASTCALL xb_xlive_main_StepState(u8* self);
void _assert(const char* expr, const char* file, u32 line);
extern char D_002B4AB8[];

/* xb_CONNECT_USER_CLASS_Poll 0xF7F19: the users count's search: 1
 * polled (its result kept, +0x60), 2 (an error) waits for A, ends the
 * error and goes back to the Live menu. Returns the result (<0: error). */
s32 XB_FASTCALL xb_CONNECT_USER_CLASS_Poll(u8* self) {
    if (*(s32*)(self + 0x5C) <= -1 || *(s32*)(self + 0x5C) >= 3) {
        _assert(D_002B4AB8, D_002B4A40, 0x60);
    }

    switch (*(s32*)(self + 0x5C)) {
    case 0:
        *(s32*)(self + 0x60) = 0;
        break;
    case 1:
        *(s32*)(self + 0x60) = xb_CONNECT_USER_CLASS_PollSearch(self);
        break;
    case 2:
        if (xb_LivePadAccept()) {
            xb_SeSelectedThunk();
            xb_LiveWork_EndError();
            xb_XLIVE_WORK_CLASS_SetState3(D_00798CAC);
            *(s32*)(self + 0x5C) = 0;
        }

        break;
    }

    return *(s32*)(self + 0x60);
}

/* xb_CONNECT_USER_CLASS_Step 0xF7C94: the window stepped when shown. */
s32 XB_FASTCALL xb_CONNECT_USER_CLASS_Step(u8* self) {
    if (self[0x50] != 0) {
        xb_xlive_main_StepState(self);
    }

    return 0;
}

/* The four matchmaking searches (procedures 1 to 4, their attribute
 * specs D_003F38C8, D_003F3918, D_003F3968, D_003F39B8): fourteen 64-bit
 * attributes, the largest value standing for any (attribute 0xF00000);
 * up to 50 results. */
extern u8 D_003F38C8[];
extern u8 D_003F3918[];
extern u8 D_003F3968[];
extern u8 D_003F39B8[];

#define XB_MS_ATTR(i_, v_)                                                 \
    do {                                                                   \
        at[(i_)].id = (v_) == 0x7FFFFFFFFFFFFFFF ? 0xF00000 : 0;           \
        at[(i_)].value = (v_);                                             \
    } while (0)

#define XB_MATCH_SEARCH(name_, proc_, spec_)                                                                     \
    s32 name_(s64 v0, s64 v1, s64 v2, s64 v3, s64 v4, s64 v5, s64 v6, s64 v7, s64 v8, s64 v9, s64 v10, s64 v11, \
              s64 v12, s64 v13, void* ev, void* task) {                                                          \
        XB_XATTR at[14];                                                                                         \
        s32 len;                                                                                                 \
                                                                                                                 \
        len = XOnlineMatchSearchResultsLen(0x32, 0xA, spec_);                                                    \
        memset(&at[0].pad, 0, sizeof(at) - 4);                                                                   \
        XB_MS_ATTR(0, v0);                                                                                       \
        XB_MS_ATTR(1, v1);                                                                                       \
        XB_MS_ATTR(2, v2);                                                                                       \
        XB_MS_ATTR(3, v3);                                                                                       \
        XB_MS_ATTR(4, v4);                                                                                       \
        XB_MS_ATTR(5, v5);                                                                                       \
        XB_MS_ATTR(6, v6);                                                                                       \
        XB_MS_ATTR(7, v7);                                                                                       \
        XB_MS_ATTR(8, v8);                                                                                       \
        XB_MS_ATTR(9, v9);                                                                                       \
        XB_MS_ATTR(10, v10);                                                                                     \
        XB_MS_ATTR(11, v11);                                                                                     \
        XB_MS_ATTR(12, v12);                                                                                     \
        XB_MS_ATTR(13, v13);                                                                                     \
        return XOnlineMatchSearch((proc_), 0x32, 0xE, at, len, ev, task);                                        \
    }

/* xb_xlive_StartMatchSearch1 0xF7380. */
XB_MATCH_SEARCH(xb_xlive_StartMatchSearch1, 1, D_003F38C8)

/* xb_xlive_StartMatchSearch2 0xF75AA. */
XB_MATCH_SEARCH(xb_xlive_StartMatchSearch2, 2, D_003F3918)

/* xb_xlive_StartMatchSearch3 0xF77BD. */
XB_MATCH_SEARCH(xb_xlive_StartMatchSearch3, 3, D_003F3968)

/* xb_xlive_StartMatchSearch4 0xF79D0. */
XB_MATCH_SEARCH(xb_xlive_StartMatchSearch4, 4, D_003F39B8)

s32 XB_STDCALL XOnlineMatchSearchParse(const u8* result, u32 nattr, const void* spec, void* out);

/* xb_xlive_ParseSearchResult 0xF7593: a search result's attributes read
 * (with search procedure 1's spec) into out. */
s32 xb_xlive_ParseSearchResult(u8* result, void* out) {
    return XOnlineMatchSearchParse(result, *(u32*)(result + 0x50), D_003F38C8, out);
}
