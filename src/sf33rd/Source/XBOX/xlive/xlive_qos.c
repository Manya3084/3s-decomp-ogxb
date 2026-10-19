/* xlive_qos.c: Xbox-only code from Capcom's xlive_qos.cpp. Its _assert path names it, and the
 * code that pushes the path places it at 0x110D57 to 0x110FA5.
 * Capcom's source is lost. Its C++ methods are written as C,
 * XB_FASTCALL (__fastcall) with this first. Each body was checked
 * against retail by analysis-ps2map/xbgen.py. The xb_ names are
 * made up. */

#include "types.h"

extern char D_002B4F38[];
extern char D_002B81C8[];
void _assert(const char* expr, const char* file, u32 line);
s32 XB_STDCALL XNetQosListen(void* key, s32 a, s32 b, s32 c, s32 d);
s32 XB_FASTCALL xb_XLIVE_WORK_CLASS_ReleaseQos(u8* self);

s32 XB_FASTCALL xb_XLIVE_WORK_CLASS_QosListen(u8* self) {
    s32 hr;

    if (*(s32*)(self + 0xD0) != 1) {
        return -1;
    }

    hr = XNetQosListen(self + 0xB4, 0, 0, 0, 2);

    if (hr) {
        _assert(D_002B4F38, D_002B81C8, 0x33);
    }

    *(s32*)(self + 0x294) = 0;
    return hr;
}

/* xb_XLIVE_WORK_CLASS_GetQosResult 0x110DA3: session i's QoS result (the
 * probes +0x2C8, valid with +0x290): its round trip when it answered,
 * else -2 (or -1 when the target was not reached); -1 with no such
 * session. */
s32 XB_FASTCALL xb_XLIVE_WORK_CLASS_GetQosResult(u8* self, s32 edx, s32 i) {
    u8* q;
    u8* e;

    (void)edx;

    if (*(s32*)(self + 0x290) == 0) {
        return -1;
    }

    q = *(u8**)(self + 0x2C8);

    if (i >= *(s32*)q) {
        return -1;
    }

    e = q + 8 + i * 24;

    if ((e[0] & 1) && *(u16*)(e + 4) != 0) {
        return *(u16*)(e + 0xE);
    }

    return ((e[0] >> 2) & 1) | -2;
}

/* xb_XLIVE_WORK_CLASS_QosStart 0x110FA5: the earlier probes released
 * and, with the session's key registered (+0xD0), QoS answering turned
 * on for it (+0x294 set). */
s32 XB_FASTCALL xb_XLIVE_WORK_CLASS_QosStart(u8* self) {
    s32 hr;

    xb_XLIVE_WORK_CLASS_ReleaseQos(self);

    if (*(s32*)(self + 0xD0) != 1) {
        return -1;
    }

    hr = XNetQosListen(self + 0xB4, 0, 0, 0, 1);

    if (hr) {
        _assert(D_002B4F38, D_002B81C8, 0x27);
    } else {
        *(s32*)(self + 0x294) = 1;
    }

    return hr;
}
