/* xlive_friend.c: Xbox-only code from Capcom's xlive_friend.cpp (its _assert path names it and places
 * it at 0xFBD74 to 0x1060BD).
 * Capcom's source is lost. The C++ methods are written as C,
 * XB_FASTCALL (__fastcall) with this first (analysis-ps2map/xbgen.py wrote
 * these from their shapes). The names are made up (xb_). */

#include "types.h"

s32 XB_FASTCALL xb_iterator_Deref(u8* self) {
    return *(s32*)(self + 0x0);
}

u8* XB_FASTCALL xb_XLIVE_FRIEND_CLASS_GetFriendList(u8* self) {
    return self + 0x860;
}

u8* XB_FASTCALL xb_XLIVE_FRIEND_CLASS_GetState2A48(u8* self) {
    return self + 0x2A48;
}

s32 XB_FASTCALL xb_iterator_Get4(u8* self) {
    return *(s32*)(self + 0x4);
}
