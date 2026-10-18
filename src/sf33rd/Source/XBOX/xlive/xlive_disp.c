/* xlive_disp.c: Xbox-only code from Capcom's xlive_disp.cpp (its _assert path names it and places
 * it at 0xF832F to 0xFAA91).
 * Capcom's source is lost. The C++ methods are written as C,
 * XB_FASTCALL (__fastcall) with this first (analysis-ps2map/xbgen.py wrote
 * these from their shapes). The names are made up (xb_). */

#include "types.h"

void xb_vector20_Clear(void);
void xb_vector_XONLINE_USER_Destroy(void);

u8 xb_ReturnFalse(void) {
    return 0;
}

void* XB_FASTCALL xb_Identity(void* self) {
    return self;
}

s32 xb_vector20_max_size(void) {
    return 0xCCCCCCC;
}

void xb_xlive_disp_Thunk108FA6(void) {
    xb_vector_XONLINE_USER_Destroy();
}

void xb_xlive_disp_ThunkF9000(void) {
    xb_vector20_Clear();
}
