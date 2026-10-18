/* xlive_qos.c: Xbox-only code from Capcom's xlive_qos.cpp. Its _assert path names it, and the
 * code that pushes the path places it at 0x110D57 to 0x110D57.
 * Capcom's source is lost. Its C++ methods are written as C,
 * XB_FASTCALL (__fastcall) with this first. Each body was checked
 * against retail by analysis-ps2map/xbgen.py. The xb_ names are
 * made up. */

#include "types.h"

extern char D_002B4F38[];
extern char D_002B81C8[];
void _assert(const char* expr, const char* file, u32 line);
s32 XB_STDCALL sub_001C22D8(void* key, s32 a, s32 b, s32 c, s32 d);

s32 XB_FASTCALL xb_XLIVE_WORK_CLASS_QosListen(u8* self) {
    s32 hr;

    if (*(s32*)(self + 0xD0) != 1) {
        return -1;
    }

    hr = sub_001C22D8(self + 0xB4, 0, 0, 0, 2);

    if (hr) {
        _assert(D_002B4F38, D_002B81C8, 0x33);
    }

    *(s32*)(self + 0x294) = 0;
    return hr;
}
