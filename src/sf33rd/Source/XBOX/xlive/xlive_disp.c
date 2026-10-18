/* xlive_disp.c: Xbox-only code from Capcom's xlive_disp.cpp. Its _assert path names it, and the
 * code that pushes the path places it at 0xF832F to 0xFAA91.
 * Capcom's source is lost. Its C++ methods are written as C,
 * XB_FASTCALL (__fastcall) with this first. Each body was checked
 * against retail by analysis-ps2map/xbgen.py. The xb_ names are
 * made up. */

#include "types.h"

void xb_vector_XONLINE_USER_Destroy(void);
void xb_vector20_Clear(void);
s32 xb_GetOnlineFlag(void);
extern u8* D_003F3A10;
void* operator_new(u32 size);

s32 xb_xlive_disp_IsEnabled(void) {
    return *D_003F3A10;
}

s32 xb_GetOnlineFlagThunk(void) {
    return xb_GetOnlineFlag();
}

u8 xb_ReturnFalse(void) {
    return 0;
}

u32* XB_FASTCALL xb_iterator4_inc(u32* self) {
    *self += 4;
    return self;
}

s32 XB_FASTCALL xb_xlive_disp_IsMissing(s32* self, s32 edx, s32* other) {
    return xb_iterator_eq(self, edx, other) == 0;
}

void* XB_FASTCALL xb_Identity(void* self) {
    return self;
}

s32 xb_vector20_max_size(void) {
    return 0xCCCCCCC;
}

u8** XB_FASTCALL xb_iterator112_add(u8** self, s32 edx, s32 n) {
    (void)edx;
    *self += n * 0x70;
    return self;
}

u8** XB_FASTCALL xb_iterator20_add(u8** self, s32 edx, s32 n) {
    (void)edx;
    *self += n * 20;
    return self;
}

void* xb_vector20_allocate(s32 n, s32 hint) {
    (void)hint;
    return operator_new(n * 20);
}

u8 XB_FASTCALL xb_iterator_eq(s32* self, s32 edx, s32* other) {
    (void)edx;
    return *self == *other;
}

s32 xb_vector_XONLINE_USER_ThunkF87A8(void) {
    return xb_vector20_max_size();
}

void* XB_FASTCALL xb_vector_XONLINE_USER_Reserve(void* self, s32 edx, s32 n) {
    (void)self;
    (void)edx;
    return xb_vector20_allocate(n, 0);
}

void xb_xlive_disp_Thunk108FA6(void) {
    xb_vector_XONLINE_USER_Destroy();
}

void xb_xlive_disp_ThunkF9000(void) {
    xb_vector20_Clear();
}
