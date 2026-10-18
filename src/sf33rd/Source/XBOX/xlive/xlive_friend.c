/* xlive_friend.c: Xbox-only code from Capcom's xlive_friend.cpp. Its _assert path names it, and the
 * code that pushes the path places it at 0xFBD74 to 0x1060BD.
 * Capcom's source is lost. Its C++ methods are written as C,
 * XB_FASTCALL (__fastcall) with this first. Each body was checked
 * against retail by analysis-ps2map/xbgen.py. The xb_ names are
 * made up. */

#include "types.h"

s32 XB_FASTCALL std__vector_ACTIONS__size(void* self);
void operator_delete(void* p);
void* XB_FASTCALL xb_vector_CopyCtor(void** self, s32 edx, void* p);
void XB_FASTCALL xb_XLIVE_FRIEND_CLASS_InitPages(void* self);

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
