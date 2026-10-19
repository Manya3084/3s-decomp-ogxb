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

u32 XB_FASTCALL std__vector_ElemBC__size(void* self);
u8* XB_FASTCALL xb_vector_SearchResult_At(u8* self, s32 edx, u32 i);
u8* XB_FASTCALL xb_xlive_match_GetAddr0C(u8* self);
u8* XB_FASTCALL xb_xlive_match_GetAddr30(u8* self);
u8* XB_FASTCALL xb_LivePkt_GetData(u8* pkt);
void XB_FASTCALL xb_vector_ptr_PushBack(u8* self, s32 edx, void** v);
s32* XB_FASTCALL xb_vector_ACTIONS_Subscript(void* self, s32 edx, u32 i);
s32 XB_STDCALL XOnlineGetServiceInfo(u32 id, void* info);
s32 XB_STDCALL XNetQosLookup(u32 cxna, void* xna, void* kid, void* key, u32 cina, u32* ina, u32* svc, u32 probes,
                             u32 bps, u32 flags, void* ev, void* out);

#define XB_QOS_PUSH(vec_, get_)                                                                     \
    (a.v = i, p = get_(((u8* (XB_FASTCALL*)(u8*, XB_ARG))xb_vector_SearchResult_At)(self + 0xA4, a)), \
     a.v = (s32)&p, ((void (XB_FASTCALL*)(u8*, XB_ARG))xb_vector_ptr_PushBack)(self + (vec_), a))
#define XB_QOS_FIRST(vec_) (a.v = 0, ((s32* (XB_FASTCALL*)(void*, XB_ARG))xb_vector_ACTIONS_Subscript)(self + (vec_), a))

/* xb_XLIVE_WORK_CLASS_QosLookup 0x111226: the found sessions (+0xA4)
 * probed: their addresses, key IDs and keys gathered (+0x298, +0x2A8,
 * +0x2B8) and an XNetQosLookup started with eight probes each, also of
 * the matchmaking service (+0x94) when its address is known; the result
 * at +0x2C8 (valid, +0x290). -1 with no sessions. */
s32 XB_FASTCALL xb_XLIVE_WORK_CLASS_QosLookup(u8* self) {
    u32 svc[7];
    void* p;
    u32* ina;
    u32* id;
    u32 cina;
    s32 n;
    s32 i;
    s32 hr;
    XB_ARG a;

    xb_XLIVE_WORK_CLASS_ReleaseQos(self);
    n = std__vector_ElemBC__size(self + 0xA4);

    if (n == 0) {
        return -1;
    }

    for (i = 0; i < n; i++) {
        XB_QOS_PUSH(0x298, xb_xlive_match_GetAddr0C);
        XB_QOS_PUSH(0x2A8, xb_LivePkt_GetData);
        XB_QOS_PUSH(0x2B8, xb_xlive_match_GetAddr30);
    }

    ina = 0;
    id = 0;
    cina = 0;

    if (XOnlineGetServiceInfo(*(u32*)(self + 0x94), svc) >= 0) {
        cina = 1;
        ina = &svc[1];
        id = &svc[0];
    }

    hr = XNetQosLookup(n, XB_QOS_FIRST(0x298), XB_QOS_FIRST(0x2A8), XB_QOS_FIRST(0x2B8), cina, ina, id, 8, 0, 0, 0,
                       self + 0x2C8);
    *(s32*)(self + 0x290) = 1;
    return hr;
}
