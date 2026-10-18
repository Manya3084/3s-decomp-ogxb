/* xlive_stat.c: Xbox-only code from Capcom's xlive_stat.cpp. Its _assert path names it, and the
 * code that pushes the path places it at 0x1156DF to 0x11AAB8.
 * Capcom's source is lost. Its C++ methods are written as C,
 * XB_FASTCALL (__fastcall) with this first. Each body was checked
 * against retail by analysis-ps2map/xbgen.py. The xb_ names are
 * made up. */

#include "types.h"

s32 XB_FASTCALL CXBOnlineTask_Close(void* self);
void xb_xlive_friend_Release(s32 id);
void XB_FASTCALL xb_WINSTR_CLASS_Release(s32* self);
void** XB_FASTCALL xb_iterator_ctor(void** self, s32 edx, void* p);

s32 XB_FASTCALL xb_XLIVE_STAT_CLASS_CloseTasks(u8* self) {
    CXBOnlineTask_Close(self + 0x430);
    CXBOnlineTask_Close(self + 0x434);
    CXBOnlineTask_Close(self + 0x438);
    CXBOnlineTask_Close(self + 0x43C);
    return 0;
}

s32 XB_FASTCALL xb_XLIVE_STAT_CLASS_Clear(u8* self) {
    s32* w;

    xb_XLIVE_STAT_CLASS_CloseTasks(self);
    xb_WINSTR_CLASS_Release(*(s32**)(self + 0x4A0));
    w = (s32*)(self + 0x444);
    xb_xlive_friend_Release(*w);
    *w = -1;
    w = (s32*)(self + 0x448);
    xb_xlive_friend_Release(*w);
    *w = -1;
    w = (s32*)(self + 0x44C);
    xb_xlive_friend_Release(*w);
    *w = -1;
    return 0;
}

void* XB_FASTCALL xb_vector_CopyCtor(void** self, s32 edx, void* p) {
    xb_iterator_ctor(self, edx, p);
    return self;
}
