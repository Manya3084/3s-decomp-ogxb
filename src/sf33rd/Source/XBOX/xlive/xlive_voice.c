/* xlive_voice.c: the Xbox Live voice chat and its packets, retail sf33rd.xbe.
 * Xbox-only C++ (VoiceChat.cpp), written as C: a method is XB_FASTCALL with
 * this first and an unused edx parameter, and a call to one passes its
 * stack arguments after an XB_ARG, so that edx is not set. The xb_ names
 * are made up. The CXHVVoiceManager methods it calls are XDK sample code
 * and have no C. Bodies that differ from retail were read against the x86;
 * analysis-ps2map/xbgen.py --from checks them. */

#include "types.h"
#include <string.h>

typedef struct {
    u32 lo;
    u32 hi;
    u32 flags;
} XB_XUID;
s32 XB_FASTCALL xb_LiveObj_IsValid(u8* self);
u8 XB_FASTCALL xb_LiveObj_IsReady(u8* self, s32 edx, s32 arg);
XB_XUID* XB_FASTCALL xb_LiveObj_Lookup(u8* self, s32 edx, s32 i);
s32 XB_FASTCALL xb_LiveObj_Call2b(u8* self, s32 edx, s32 a, s32 b);
u8* XB_FASTCALL xb_LiveObj_Set2(u8* self, s32 edx, u8 v);
s32 xb_GetLiveObjSize(void);
s32 XB_FASTCALL CXBSocket_IsOpen(void* self);
s32 XB_FASTCALL CXBSocket_RecvFrom(void* self, s32 edx, void* buf, s32 len, void* from);
s32 XB_STDCALL WSAGetLastError(void);
void _assert(const char* expr, const char* file, u32 line);
s32 XB_FASTCALL xb_XLIVE_WORK_CLASS_FindUser(u8* self, s32 edx, XB_XUID* user);
void xb_xlive_match_PeerEvent1(u8* body, void* from);
void xb_xlive_match_PeerEvent2(u8* body, void* from);
void xb_xlive_match_PeerEvent3(u8* body, void* from);
void xb_xlive_match_PeerEvent4(u8* body, void* from);
void xb_xlive_match_IsGuestReady(u8* pkt);
s32 XB_STDCALL sub_0012AE70(s32 a, s32 b, s32* c);
s32 XB_STDCALL XHVEngine_SubmitIncomingVoicePacket(s32 engine, XB_XUID user, void* data, s32* size);
s32 XB_FASTCALL CXHVVoiceManager_AddRemoteTalker(u8* self, s32 edx, XB_XUID user);
s32 XB_FASTCALL CXHVVoiceManager_RemoveRemoteTalker(u8* self, s32 edx, XB_XUID user);
s32 XB_FASTCALL CXHVVoiceManager_SetRemoteTalkerPriority(u8* self, s32 edx, XB_XUID user, s32 local, s32 prio);
s32 XB_FASTCALL xb_LiveObj_Process(u8* self, s32 edx, s32 arg);
s32 XB_FASTCALL xb_LiveObj_GetType(u8* pkt);
u32* XB_FASTCALL xb_LiveObj_Init(u32* self, s32 edx, s16* addr);
extern u8* D_00798CAC;
extern u8 D_003F376C[];
extern char D_0025CCA0[];
extern char D_002B4580[];
extern char D_002B45F0[];
extern char D_002B45FC[];
extern char D_002B4620[];
extern char D_002B4640[];
extern char D_002B499C[];
extern char D_002B49B8[];

/* IXHVEngine__GetLocalTalkerStatus 0xF584A: xhv.h's inline wrapper, a jump
 * to the XHV engine's export at 0x12AE70. */
s32 XB_STDCALL IXHVEngine__GetLocalTalkerStatus(s32 engine, s32 port, s32* status) {
    return sub_0012AE70(engine, port, status);
}

/* xb_VoiceMgr_GetTalkerStatus 0xF58B5: the voice manager's engine (+4)
 * asked for a local talker's status. */
s32 XB_FASTCALL xb_VoiceMgr_GetTalkerStatus(u8* self, s32 edx, s32 port, s32* status) {
    (void)edx;
    return IXHVEngine__GetLocalTalkerStatus(*(s32*)(self + 4), port, status);
}

/* xb_LivePkt_GetType 0xF5884: a voice packet's type byte. */
u8 XB_FASTCALL xb_LivePkt_GetType(u8* pkt) {
    return pkt[2];
}

/* xb_LivePkt_GetData 0xF588C: the data after a packet's header. */
u8* XB_FASTCALL xb_LivePkt_GetData(u8* pkt) {
    return pkt + 4;
}

/* xb_LiveObj_Count 0xF57C6: the user list's count (+0x10). */
u32 XB_FASTCALL xb_LiveObj_Count(u8* self) {
    return *(u32*)(self + 0x10);
}

/* xb_LiveAddr_GetPort 0xF7374: a socket address's second word. */
void XB_FASTCALL xb_LiveAddr_GetPort(u8* self, s32 edx, u32* out) {
    (void)edx;
    *out = *(u32*)(self + 4);
}

/* xb_LivePkt_GetBody 0xF692B: the body of a packet of type 0 to 7 (after
 * its 4-byte header). */
u8* XB_FASTCALL xb_LivePkt_GetBody(u8* pkt) {
    switch (pkt[2]) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
        return pkt + 4;
    }

    _assert(D_0025CCA0, D_002B4640, 0x53);
    return 0;
}

/* IXHVEngine__SubmitIncomingVoicePacket 0xF584F: xhv.h's inline wrapper. */
s32 XB_STDCALL IXHVEngine__SubmitIncomingVoicePacket(s32 engine, XB_XUID user, void* data, s32* size) {
    return XHVEngine_SubmitIncomingVoicePacket(engine, user, data, size);
}

/* xb_VoiceMgr_SubmitPacket 0xF58D7: a remote talker's voice data handed to
 * the voice manager's engine (+4). */
s32 XB_FASTCALL xb_VoiceMgr_SubmitPacket(u8* self, s32 edx, XB_XUID user, void* data, s32 size) {
    (void)edx;
    return IXHVEngine__SubmitIncomingVoicePacket(*(s32*)(self + 4), user, data, (s32*)size);
}

s32 XB_FASTCALL xb_LiveObj_Process(u8* self, s32 edx, s32 arg) {
    u8* e;
    s32 st;
    XB_ARG a;
    XB_ARG b;

    (void)edx;

    if (xb_LiveObj_IsValid(self + 8) == 0) {
        return 1;
    }

    e = *(u8**)(self + 0xB0) + arg * 0x70;

    if ((*(s32*)e | *(s32*)(e + 4)) == 0) {
        return 0;
    }

    if (e[0xA] & 1) {
        return 1;
    }

    a.v = arg;
    b.v = (s32)&st;
    ((s32 (XB_FASTCALL*)(u8*, XB_ARG, XB_ARG))xb_VoiceMgr_GetTalkerStatus)(self + 8, a, b);
    return st != 0 ? 2 : 3;
}

void XB_FASTCALL xb_LiveObj_SetHandler(u8* self, s32 edx, s32 h) {
    XB_ARG a;
    XB_ARG b;
    XB_ARG c;
    XB_XUID* u;

    (void)edx;

    if (xb_LiveObj_IsValid(self + 8) == 0) {
        return;
    }

    *(s32*)(self + 0x50) = h;
    self[0x4C] = 1;
    a.v = *(s32*)(D_00798CAC + 0x14);

    if (((u8 (XB_FASTCALL*)(u8*, XB_ARG))xb_LiveObj_IsReady)(self, a) == 0) {
        return;
    }

    a.v = 0;
    u = ((XB_XUID* (XB_FASTCALL*)(u8*, XB_ARG))xb_LiveObj_Lookup)(D_00798CAC + 0x28, a);
    a.v = *(s32*)((u8*)u + 0xA0);
    b.v = 0;
    c.v = (s32)(D_003F376C + h * 0x14);
    ((s32 (XB_FASTCALL*)(u8*, XB_ARG, XB_ARG, XB_ARG))xb_LiveObj_Call2b)(self + 8, a, b, c);
}

/* xb_VoiceChat_OnTalker 0xF5E4A: a peer's type-8 message: voice data from
 * the user at that address, unless the user is muted (FindUser). */
void XB_FASTCALL xb_VoiceChat_OnTalker(u8* self, s32 edx, u8* data, u8* from) {
    u32 port;
    u32 i;
    XB_ARG a;
    XB_ARG b;
    XB_XUID* u;
    u8* work;

    (void)edx;
    a.v = (s32)&port;
    ((void (XB_FASTCALL*)(u8*, XB_ARG))xb_LiveAddr_GetPort)(from, a);
    i = 0;

    if (*(s32*)(self + 0x54) == 0 || xb_LiveObj_IsValid(self + 8) == 0) {
        return;
    }

    work = D_00798CAC + 0x28;

    for (i = 0; i < xb_LiveObj_Count(work); i++, work = D_00798CAC + 0x28) {
        a.v = i;
        u = ((XB_XUID* (XB_FASTCALL*)(u8*, XB_ARG))xb_LiveObj_Lookup)(work, a);

        if (*(u32*)((u8*)u + 0xC) != port) {
            continue;
        }

        a.v = i;
        u = ((XB_XUID* (XB_FASTCALL*)(u8*, XB_ARG))xb_LiveObj_Lookup)(D_00798CAC + 0x28, a);
        a.v = (s32)u;

        if (((s32 (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_WORK_CLASS_FindUser)(D_00798CAC, a) != 0) {
            return;
        }

        a.v = i;
        u = ((XB_XUID* (XB_FASTCALL*)(u8*, XB_ARG))xb_LiveObj_Lookup)(D_00798CAC + 0x28, a);

        a.v = (s32)(data + 2);
        b.v = 10;

        if (((s32 (XB_FASTCALL*)(u8*, XB_XUID, XB_ARG, XB_ARG))xb_VoiceMgr_SubmitPacket)(self + 8, *u, a, b) != 0) {
            _assert(D_002B45F0, D_002B4580, 0x378);
        }

        return;
    }
}

/* xb_VoiceChat_OnPriority 0xF5F2F: a peer's type-9 message: its talker is
 * added (data +4 == 1, with priority when this side is talking) or
 * removed. */
void XB_FASTCALL xb_VoiceChat_OnPriority(u8* self, s32 edx, u8* data, u8* from) {
    u32 port;
    s32 i;
    XB_ARG a;
    XB_ARG b;
    XB_XUID* u;

    (void)edx;

    if (*(s32*)(self + 0x58) == 0) {
        return;
    }

    a.v = (s32)&port;
    ((void (XB_FASTCALL*)(u8*, XB_ARG))xb_LiveAddr_GetPort)(from, a);

    for (i = 0; i < (s32)xb_LiveObj_Count(D_00798CAC + 0x28); i++) {
        a.v = i;
        u = ((XB_XUID* (XB_FASTCALL*)(u8*, XB_ARG))xb_LiveObj_Lookup)(D_00798CAC + 0x28, a);

        if (*(u32*)((u8*)u + 0xC) != port) {
            continue;
        }

        a.v = i;
        u = ((XB_XUID* (XB_FASTCALL*)(u8*, XB_ARG))xb_LiveObj_Lookup)(D_00798CAC + 0x28, a);

        if (*(s32*)(data + 4) != 1) {
            ((s32 (XB_FASTCALL*)(u8*, XB_XUID))CXHVVoiceManager_RemoveRemoteTalker)(self + 8, *u);
            return;
        }

        ((s32 (XB_FASTCALL*)(u8*, XB_XUID))CXHVVoiceManager_AddRemoteTalker)(self + 8, *u);
        a.v = *(s32*)(D_00798CAC + 0x14);

        if (((s32 (XB_FASTCALL*)(u8*, XB_ARG))xb_LiveObj_Process)(self, a) > 1) {
            a.v = i;
            u = ((XB_XUID* (XB_FASTCALL*)(u8*, XB_ARG))xb_LiveObj_Lookup)(D_00798CAC + 0x28, a);
            a.v = *(s32*)(D_00798CAC + 0x14);
            b.v = 0xFFFF;
            ((s32 (XB_FASTCALL*)(u8*, XB_XUID, XB_ARG, XB_ARG))CXHVVoiceManager_SetRemoteTalkerPriority)(self + 8, *u, a, b);
        }

        return;
    }
}

/* xb_VoiceChat_Update 0xF63B5: one received voice-chat packet, by type. */
void XB_FASTCALL xb_VoiceChat_Update(u8* self, s32 edx, u8* pkt, u8* from) {
    XB_ARG a;
    XB_ARG b;

    (void)edx;

    switch (xb_LivePkt_GetType(pkt)) {
    case 0:
    case 1:
    case 6:
        break;

    case 2:
        xb_xlive_match_PeerEvent1(xb_LivePkt_GetBody(pkt), from);
        break;

    case 3:
        xb_xlive_match_PeerEvent2(xb_LivePkt_GetBody(pkt), from);
        break;

    case 4:
        xb_xlive_match_PeerEvent3(xb_LivePkt_GetBody(pkt), from);
        break;

    case 5:
        ((void (*)(u8*, u8*))xb_xlive_match_IsGuestReady)(xb_LivePkt_GetBody(pkt), from);
        break;

    case 7:
        xb_xlive_match_PeerEvent4(xb_LivePkt_GetBody(pkt), from);
        break;

    case 8:
        a.v = (s32)xb_LivePkt_GetData(pkt);
        b.v = (s32)from;
        ((void (XB_FASTCALL*)(u8*, XB_ARG, XB_ARG))xb_VoiceChat_OnTalker)(self, a, b);
        break;

    case 9:
        a.v = (s32)xb_LivePkt_GetData(pkt);
        b.v = (s32)from;
        ((void (XB_FASTCALL*)(u8*, XB_ARG, XB_ARG))xb_VoiceChat_OnPriority)(self, a, b);
        break;

    default:
        _assert(D_0025CCA0, D_002B4580, 0x34E);
        break;
    }
}

/* xb_LiveObj_GetType 0xF6835: the size of a voice-chat packet of the
 * type at +2. */
s32 XB_FASTCALL xb_LiveObj_GetType(u8* pkt) {
    switch (pkt[2]) {
    case 0:
        return 0xD;
    case 1:
        return 0x68;
    case 2:
    case 3:
    case 4:
    case 6:
        return 0x4C;
    case 5:
        return 6;
    case 7:
        return 7;
    case 8:
        return 0x10;
    case 9:
        return 0xC;
    }

    _assert(D_0025CCA0, D_002B4640, 0x22);
    return 0;
}

/* xb_LiveObj_Init 0xF72D6: a socket address (family 2 only) copied into
 * this 16-byte sockaddr_in: family (+0), port (+2), address (+4). */
u32* XB_FASTCALL xb_LiveObj_Init(u32* self, s32 edx, s16* addr) {
    (void)edx;
    memset(self, 0, 16);

    if (addr[0] != 2) {
        _assert(D_002B499C, D_002B49B8, 0x19);
    }

    *(s16*)self = 2;
    self[1] = *(u32*)(addr + 2);
    *(u16*)((u8*)self + 2) = addr[1];
    return self;
}

/* xb_LiveObj_Update 0xF6515: every voice-chat packet waiting on the
 * socket, received and handled. */
void XB_FASTCALL xb_LiveObj_Update(u8* self) {
    u8 buf[0x68];
    u32 from[4];
    u8 sa[0x10];
    s32 len;
    s32 n;
    XB_ARG a;
    XB_ARG b;
    XB_ARG c;

    if (CXBSocket_IsOpen(self + 4) == 0) {
        return;
    }

    a.v = 0;
    ((u8* (XB_FASTCALL*)(u8*, XB_ARG))xb_LiveObj_Set2)(buf, a);
    len = xb_GetLiveObjSize();

    do {
        a.v = (s32)buf;
        b.v = len;
        c.v = (s32)sa;
        n = ((s32 (XB_FASTCALL*)(void*, XB_ARG, XB_ARG, XB_ARG))CXBSocket_RecvFrom)(self + 4, a, b, c);
        a.v = (s32)sa;
        ((u32* (XB_FASTCALL*)(u32*, XB_ARG))xb_LiveObj_Init)(from, a);

        if (n == -1 || n < 1) {
            if (WSAGetLastError() != 0x2733) {
                _assert(D_002B45FC, D_002B4580, 0x300);
            }
        } else {
            if (n != xb_LiveObj_GetType(buf)) {
                _assert(D_002B4620, D_002B4580, 0x2FB);
            }

            a.v = (s32)buf;
            b.v = (s32)from;
            ((void (XB_FASTCALL*)(u8*, XB_ARG, XB_ARG))xb_VoiceChat_Update)(self, a, b);
        }
    } while (n != -1 && n > 0);
}
