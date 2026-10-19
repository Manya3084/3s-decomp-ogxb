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
XB_XUID* XB_FASTCALL xb_deque_LiveObj_Subscript(u8* self, s32 edx, s32 i);
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
s32 XB_STDCALL XHVEngine_GetLocalTalkerStatus(s32 a, s32 b, s32* c);
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
    return XHVEngine_GetLocalTalkerStatus(engine, port, status);
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
    u = ((XB_XUID* (XB_FASTCALL*)(u8*, XB_ARG))xb_deque_LiveObj_Subscript)(D_00798CAC + 0x28, a);
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
        u = ((XB_XUID* (XB_FASTCALL*)(u8*, XB_ARG))xb_deque_LiveObj_Subscript)(work, a);

        if (*(u32*)((u8*)u + 0xC) != port) {
            continue;
        }

        a.v = i;
        u = ((XB_XUID* (XB_FASTCALL*)(u8*, XB_ARG))xb_deque_LiveObj_Subscript)(D_00798CAC + 0x28, a);
        a.v = (s32)u;

        if (((s32 (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_WORK_CLASS_FindUser)(D_00798CAC, a) != 0) {
            return;
        }

        a.v = i;
        u = ((XB_XUID* (XB_FASTCALL*)(u8*, XB_ARG))xb_deque_LiveObj_Subscript)(D_00798CAC + 0x28, a);

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
        u = ((XB_XUID* (XB_FASTCALL*)(u8*, XB_ARG))xb_deque_LiveObj_Subscript)(D_00798CAC + 0x28, a);

        if (*(u32*)((u8*)u + 0xC) != port) {
            continue;
        }

        a.v = i;
        u = ((XB_XUID* (XB_FASTCALL*)(u8*, XB_ARG))xb_deque_LiveObj_Subscript)(D_00798CAC + 0x28, a);

        if (*(s32*)(data + 4) != 1) {
            ((s32 (XB_FASTCALL*)(u8*, XB_XUID))CXHVVoiceManager_RemoveRemoteTalker)(self + 8, *u);
            return;
        }

        ((s32 (XB_FASTCALL*)(u8*, XB_XUID))CXHVVoiceManager_AddRemoteTalker)(self + 8, *u);
        a.v = *(s32*)(D_00798CAC + 0x14);

        if (((s32 (XB_FASTCALL*)(u8*, XB_ARG))xb_LiveObj_Process)(self, a) > 1) {
            a.v = i;
            u = ((XB_XUID* (XB_FASTCALL*)(u8*, XB_ARG))xb_deque_LiveObj_Subscript)(D_00798CAC + 0x28, a);
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

typedef struct {
    u32 w[3];
} XB_PEER12;
s32 XB_FASTCALL xb_LiveObj_IsValid(u8* self);

/* xb_LiveObj_MarkPeer 0xF59B3: the voice object flagged (+0x64) for a
 * peer while its socket is open. */
void XB_FASTCALL xb_LiveObj_MarkPeer(u8* self, s32 edx, XB_PEER12 peer) {
    (void)edx;
    (void)peer;

    if (xb_LiveObj_IsValid(self + 8)) {
        *(s32*)(self + 0x64) = 1;
    }
}

/* VoiceChatMessage.cpp: a voice chat message is a 16-bit length, a type
 * byte and a body whose size the type sets. */

/* xb_VoiceMsg_SetType 0xF68A0: the type (0 to 9). */
void XB_FASTCALL xb_VoiceMsg_SetType(u8* self, s32 edx, u32 type) {
    (void)edx;

    switch (type) {
    case 0:
        self[2] = 0;
        break;
    case 1:
        self[2] = 1;
        break;
    case 2:
        self[2] = 2;
        break;
    case 3:
        self[2] = 3;
        break;
    case 4:
        self[2] = 4;
        break;
    case 5:
        self[2] = 5;
        break;
    case 6:
        self[2] = 6;
        break;
    case 7:
        self[2] = 7;
        break;
    case 8:
        self[2] = 8;
        break;
    case 9:
        self[2] = 9;
        break;
    default:
        _assert(D_0025CCA0, D_002B4640, 0x3C);
        break;
    }
}

/* xb_VoiceMsg_SetLength 0xF6976: the length for the type. */
void XB_FASTCALL xb_VoiceMsg_SetLength(u8* self) {
    switch (self[2]) {
    case 0:
        *(u16*)self = 0xB;
        break;
    case 1:
        *(u16*)self = 0x66;
        break;
    case 2:
    case 3:
    case 4:
    case 6:
        *(u16*)self = 0x4A;
        break;
    case 5:
    case 8:
        *(u16*)self = 4;
        break;
    case 7:
        *(u16*)self = 5;
        break;
    case 9:
        *(u16*)self = 0xA;
        break;
    default:
        _assert(D_0025CCA0, D_002B4640, 0x6D);
        break;
    }
}

/* xb_VoiceMsg_BodySize 0xF69E7: the body size for the type. */
u32 XB_FASTCALL xb_VoiceMsg_BodySize(u8* self) {
    switch (self[2]) {
    case 0:
        return 9;
    case 1:
        return 0x64;
    case 2:
    case 3:
    case 4:
    case 6:
        return 0x48;
    case 5:
        return 2;
    case 7:
        return 3;
    case 8:
        return 0xC;
    case 9:
        return 8;
    }

    _assert(D_0025CCA0, D_002B4640, 0x86);
    return 0;
}

/* A SOCKADDR_IN. */
typedef struct {
    u16 family;
    u16 port;
    u32 addr;
    u32 zero[2];
} XB_SOCKADDR;
u16 XB_STDCALL htons(u16 v);

/* xb_SockAddr_Init 0xF7346: an IPv4 address and port. */
XB_SOCKADDR* XB_FASTCALL xb_SockAddr_Init(XB_SOCKADDR* self, s32 edx, u32* ina, u16 port) {
    (void)edx;
    memset(self, 0, sizeof(*self));
    self->family = 2;
    self->addr = *ina;
    self->port = htons(port);
    return self;
}

typedef struct {
    u32 w[4];
} XB_KEY16;
s32 XB_FASTCALL CXBSocket_SendTo(void* self, s32 edx, const void* buf, s32 n, const void* to);
void* XB_FASTCALL xb_Identity(void* self);

/* xb_LiveObj_SendVoice 0xF59CD: a voice chat message of msg's type (its
 * first byte, 0 to 7) with msg as its body, sent to a peer's address at
 * the object's port (+0x48) while its socket (+4) is open. */
#define XB_VCTYPE(t) (a.v = (t), ((void (XB_FASTCALL*)(u32*, XB_ARG))xb_VoiceMsg_SetType)(pkt, a))

s32 XB_FASTCALL xb_LiveObj_SendVoice(u8* self, s32 edx, XB_KEY16 to, u8* msg) {
    u32 pkt[0x1A];
    XB_SOCKADDR sa;
    u32 n;
    XB_ARG a;
    XB_ARG b;
    XB_ARG c;

    (void)edx;
    a.v = 0;
    ((u8* (XB_FASTCALL*)(u32*, XB_ARG))xb_LiveObj_Set2)(pkt, a);

    switch (msg[0]) {
    case 0:
        XB_VCTYPE(0);
        break;
    case 1:
        XB_VCTYPE(1);
        break;
    case 2:
        XB_VCTYPE(2);
        break;
    case 3:
        XB_VCTYPE(3);
        break;
    case 4:
        XB_VCTYPE(4);
        break;
    case 5:
        XB_VCTYPE(5);
        break;
    case 6:
        XB_VCTYPE(6);
        break;
    case 7:
        XB_VCTYPE(7);
        break;
    }

    n = xb_VoiceMsg_BodySize((u8*)pkt);
    memcpy(xb_LivePkt_GetBody((u8*)pkt), msg, n);
    xb_VoiceMsg_SetLength((u8*)pkt);

    if (CXBSocket_IsOpen(self + 4) == 0) {
        return 0;
    }

    a.v = (s32)&to;
    b.v = *(u16*)(self + 0x48);
    a.v = (s32)xb_Identity(((XB_SOCKADDR* (XB_FASTCALL*)(XB_SOCKADDR*, XB_ARG, XB_ARG))xb_SockAddr_Init)(&sa, a, b));
    b.v = xb_LiveObj_GetType((u8*)pkt);
    c.v = (s32)pkt;
    return ((s32 (XB_FASTCALL*)(u8*, XB_ARG, XB_ARG, XB_ARG))CXBSocket_SendTo)(self + 4, c, b, a);
}

/* More of xhv.h's inline wrappers, each a call to xvoice's XHVEngine_
 * function. */
s32 XB_STDCALL XHVEngine_DoWork(s32 engine);
s32 XB_STDCALL XHVEngine_UnregisterLocalTalker(s32 engine, s32 port);
s32 XB_STDCALL XHVEngine_Release(s32 engine);
s32 XB_STDCALL XHVEngine_RegisterRemoteTalker(s32 engine, XB_XUID user);
s32 XB_STDCALL XHVEngine_UnregisterRemoteTalker(s32 engine, XB_XUID user);

/* IXHVEngine__DoWork 0xF583B. */
s32 XB_STDCALL IXHVEngine__DoWork(s32 engine) {
    return XHVEngine_DoWork(engine);
}

/* IXHVEngine__Release 0xF6D7F. */
s32 XB_STDCALL IXHVEngine__Release(s32 engine) {
    return XHVEngine_Release(engine);
}

/* IXHVEngine__UnregisterLocalTalker 0xF6D93. */
s32 XB_STDCALL IXHVEngine__UnregisterLocalTalker(s32 engine, s32 port) {
    return XHVEngine_UnregisterLocalTalker(engine, port);
}

/* IXHVEngine__RegisterRemoteTalker 0xF6D98. */
s32 XB_STDCALL IXHVEngine__RegisterRemoteTalker(s32 engine, XB_XUID user) {
    return XHVEngine_RegisterRemoteTalker(engine, user);
}

/* IXHVEngine__UnregisterRemoteTalker 0xF6DB4. */
s32 XB_STDCALL IXHVEngine__UnregisterRemoteTalker(s32 engine, XB_XUID user) {
    return XHVEngine_UnregisterRemoteTalker(engine, user);
}

s32 XB_FASTCALL CXBSocket_Open(void* self, s32 edx, s32 type);
s32 XB_FASTCALL CXBSocket_Bind(void* self, s32 edx, const void* addr);
s32 XB_FASTCALL CXBSocket_IoCtlSocket(void* self, s32 edx, u32 cmd, u32* arg);
s32 XB_FASTCALL CXBSocket_Close(void* self);

/* xb_SockAddr_InitAny 0xF731A: an IPv4 address (a value) and port. */
XB_SOCKADDR* XB_FASTCALL xb_SockAddr_InitAny(XB_SOCKADDR* self, s32 edx, u32 addr, u16 port) {
    (void)edx;
    memset(self, 0, sizeof(*self));
    self->family = 2;
    self->addr = addr;
    self->port = htons(port);
    return self;
}

/* The same SOCKADDR_IN with its sin_zero as chars, as the socket code
 * declares it (its locals get a /GS cookie). */
typedef struct {
    u16 family;
    u16 port;
    u32 addr;
    char zero[8];
} XB_SOCKADDR_IN;

/* xb_LiveObj_OpenSockets 0xF56C0: the voice socket (+4, bound to the
 * port at +0x48) and the second socket (+0x68, port 1002) opened as
 * non-blocking UDP (FIONBIO). 1 when both are. */
s32 XB_FASTCALL xb_LiveObj_OpenSockets(u8* self) {
    u8* s1 = self + 4;
    u8* s2;
    XB_SOCKADDR_IN sa1;
    XB_SOCKADDR_IN sa2;
    u32 on;
    XB_ARG a;
    XB_ARG b;

    a.v = 2;

    if (((s32 (XB_FASTCALL*)(u8*, XB_ARG))CXBSocket_Open)(s1, a) == 0) {
        return 0;
    }

    a.v = 0;
    b.v = *(u16*)(self + 0x48);
    a.v = (s32)xb_Identity(((XB_SOCKADDR* (XB_FASTCALL*)(XB_SOCKADDR*, XB_ARG, XB_ARG))xb_SockAddr_InitAny)((XB_SOCKADDR*)&sa1, a, b));

    if (((s32 (XB_FASTCALL*)(u8*, XB_ARG))CXBSocket_Bind)(s1, a) == -1) {
        return 0;
    }

    on = 1;
    a.v = 0x8004667E;
    b.v = (s32)&on;

    if (((s32 (XB_FASTCALL*)(u8*, XB_ARG, XB_ARG))CXBSocket_IoCtlSocket)(s1, a, b) == -1) {
        return 0;
    }

    s2 = self + 0x68;
    a.v = 2;

    if (((s32 (XB_FASTCALL*)(u8*, XB_ARG))CXBSocket_Open)(s2, a) == 0) {
        return 0;
    }

    a.v = 0;
    b.v = 0x3EA;
    a.v = (s32)xb_Identity(((XB_SOCKADDR* (XB_FASTCALL*)(XB_SOCKADDR*, XB_ARG, XB_ARG))xb_SockAddr_InitAny)((XB_SOCKADDR*)&sa2, a, b));

    if (((s32 (XB_FASTCALL*)(u8*, XB_ARG))CXBSocket_Bind)(s2, a) == -1) {
        return 0;
    }

    a.v = 0x8004667E;
    b.v = (s32)&on;
    return ((s32 (XB_FASTCALL*)(u8*, XB_ARG, XB_ARG))CXBSocket_IoCtlSocket)(s2, a, b) != -1;
}

void XB_FASTCALL xb_XLIVE_STARTMENU_CLASS_Set74(u8* self, s32 edx, s32 v);
void XB_FASTCALL xb_XLIVE_STATMENU_CLASS_Set64(u8* self, s32 edx, s32 v);
s32 XB_FASTCALL CXHVVoiceManager_SetVoiceThroughSpeakers(u8* self, s32 edx, s32 port, s32 on);
s32 XB_FASTCALL xb_LiveObj_Call2(u8* self, s32 edx, s32 a, s32 b);
void xb_xlive_net_SetVoiceMode(s32 v);
extern s32 D_002BA6BC;
extern s32 D_002BA734;
extern void (XB_STDCALL* D_00218DC0)(void* cs);
extern void (XB_STDCALL* D_00218DC4)(void* cs);
extern u8 D_00797EFC[];

/* xb_LiveObj_Stop 0xF5B5F: the voice socket closed (+0x60 set), the menus
 * told, and, in the voice lock, each port with a talker (state above 1)
 * set back to its first mode (D_002BA6BC); +0x64 set. */
void XB_FASTCALL xb_LiveObj_Stop(u8* self) {
    u32 i;
    XB_ARG a;
    XB_ARG b;

    CXBSocket_Close(self + 4);
    *(s32*)(self + 0x60) = 1;
    a.v = 1;
    ((void (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_STARTMENU_CLASS_Set74)(D_00798CAC + 0x24C0, a);
    a.v = 1;
    ((void (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_STATMENU_CLASS_Set64)(D_00798CAC + 0x2544, a);
    D_00218DC4(D_00797EFC);

    for (i = 0; i < 4; i++) {
        a.v = i;

        if (((s32 (XB_FASTCALL*)(u8*, XB_ARG))xb_LiveObj_Process)(self, a) > 1) {
            a.v = i;
            b.v = D_002BA6BC;
            ((s32 (XB_FASTCALL*)(u8*, XB_ARG, XB_ARG))xb_LiveObj_Call2)(self + 8, a, b);
        }
    }

    *(s32*)(self + 0x64) = 1;
    D_00218DC0(D_00797EFC);
}

/* xb_LiveObj_Start 0xF5DA0: the sockets opened (on a failure the voice
 * socket closed, +0x60 set, 0 returned); each port with a talker set to
 * the chat mode (D_002BA734), the stats menu told, this user's voice put
 * through the speakers when it has no headset, and voice on. */
s32 XB_FASTCALL xb_LiveObj_Start(u8* self) {
    s32 i;
    XB_ARG a;
    XB_ARG b;

    if (xb_LiveObj_OpenSockets(self) == 0) {
        CXBSocket_Close(self + 4);
        *(s32*)(self + 0x60) = 1;
        return 0;
    }

    for (i = 0; i < 4; i++) {
        a.v = i;

        if (((s32 (XB_FASTCALL*)(u8*, XB_ARG))xb_LiveObj_Process)(self, a) >= 2) {
            a.v = i;
            b.v = D_002BA734;
            ((s32 (XB_FASTCALL*)(u8*, XB_ARG, XB_ARG))xb_LiveObj_Call2)(self + 8, a, b);
        }
    }

    a.v = 1;
    ((void (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_STATMENU_CLASS_Set64)(D_00798CAC + 0x2544, a);
    a.v = *(s32*)(D_00798CAC + 0x14);

    if (((u8 (XB_FASTCALL*)(u8*, XB_ARG))xb_LiveObj_IsReady)(self, a) == 0 && *(s32*)(self + 0x94) == 0) {
        a.v = *(s32*)(D_00798CAC + 0x14);
        b.v = 1;
        ((s32 (XB_FASTCALL*)(u8*, XB_ARG, XB_ARG))CXHVVoiceManager_SetVoiceThroughSpeakers)(self + 8, a, b);
    }

    xb_xlive_net_SetVoiceMode(1);
    *(s32*)(self + 0x58) = 1;
    return 1;
}

/* xb_LiveObj_RecvAll2 0xF65FC: every packet waiting on the second socket
 * (+0x68) handled. */
s32 XB_FASTCALL xb_LiveObj_RecvAll2(u8* self) {
    u8* s2 = self + 0x68;
    u32 buf[0x1B];
    u32 from[4];
    u8 sa[0x10];
    s32 len;
    s32 n;
    XB_ARG a;
    XB_ARG b;
    XB_ARG c;

    if (CXBSocket_IsOpen(s2) == 0) {
        return 0;
    }

    a.v = 0;
    ((u8* (XB_FASTCALL*)(u32*, XB_ARG))xb_LiveObj_Set2)(buf, a);
    len = xb_GetLiveObjSize();

    for (;;) {
        a.v = (s32)buf;
        b.v = len;
        c.v = (s32)sa;
        n = ((s32 (XB_FASTCALL*)(void*, XB_ARG, XB_ARG, XB_ARG))CXBSocket_RecvFrom)(s2, a, b, c);

        if (n == -1 || n <= 0) {
            break;
        }

        a.v = (s32)sa;
        ((u32* (XB_FASTCALL*)(u32*, XB_ARG))xb_LiveObj_Init)(from, a);

        if (n != xb_LiveObj_GetType((u8*)buf)) {
            _assert(D_002B4620, D_002B4580, 0x328);
        }

        a.v = (s32)buf;
        b.v = (s32)from;
        ((void (XB_FASTCALL*)(u8*, XB_ARG, XB_ARG))xb_VoiceChat_Update)(self, a, b);
    }

    return 0;
}

u8* XB_FASTCALL xb_LiveObj_Get8(u8* self);
s32 XB_FASTCALL CXHVVoiceManager_DoWork(u8* self);
s32 XB_FASTCALL CXHVVoiceManager_ClearRemoteTalkers(u8* self);
s32 XB_FASTCALL CXHVVoiceManager_Shutdown(u8* self);
u32 XB_STDCALL GetLastError(void);

/* xb_LiveVoice_Thread 0xF66C0: the voice thread. In the voice lock, each
 * pass reads the second socket, runs the voice engine while voice is on
 * (work +0x2460), and acts on the requests: clear the talkers (+0x246C),
 * shut voice down (+0x2464), close the second socket (+0x2468). It never
 * returns. */
u32 XB_STDCALL xb_LiveVoice_Thread(void* arg) {
    u8* vm;

    (void)arg;

    for (;;) {
        D_00218DC4(D_00797EFC);
        xb_LiveObj_RecvAll2(D_00798CAC + 0x2408);

        if (*(s32*)(D_00798CAC + 0x2460) != 0) {
            vm = xb_LiveObj_Get8(D_00798CAC + 0x2408);

            if (xb_LiveObj_IsValid(vm) && CXHVVoiceManager_DoWork(vm) < 0) {
                GetLastError();
            }
        }

        if (*(s32*)(D_00798CAC + 0x246C) != 0) {
            *(s32*)(D_00798CAC + 0x246C) = 0;
            CXHVVoiceManager_ClearRemoteTalkers(xb_LiveObj_Get8(D_00798CAC + 0x2408));
        }

        if (*(s32*)(D_00798CAC + 0x2464) != 0) {
            *(s32*)(D_00798CAC + 0x2464) = 0;
            *(s32*)(D_00798CAC + 0x2460) = 0;
            CXHVVoiceManager_Shutdown(xb_LiveObj_Get8(D_00798CAC + 0x2408));
        }

        if (*(s32*)(D_00798CAC + 0x2468) != 0) {
            *(s32*)(D_00798CAC + 0x2468) = 0;
            CXBSocket_Close(D_00798CAC + 0x2470);
        }

        D_00218DC0(D_00797EFC);
    }
}

/* xb_LiveObj_SetPeerAddr 0xF56A8: the peer's address (its second word,
 * +0x3C and +0x40) set and voice on. Always 1. */
s32 XB_FASTCALL xb_LiveObj_SetPeerAddr(u8* self, s32 edx, XB_KEY16 to) {
    (void)edx;
    *(u32*)(self + 0x3C) = to.w[1];
    *(u32*)(self + 0x40) = to.w[1];
    xb_xlive_net_SetVoiceMode(1);
    return 1;
}

/* xb_LiveObj_AddPeerTalker 0xF619B: the player at the peer's port added
 * as a remote talker (top priority while this user has voice); the peer's
 * user (+0x44) kept. 1 when the player was found. */
s32 XB_FASTCALL xb_LiveObj_AddPeerTalker(u8* self, s32 edx, XB_KEY16 to, u16 user) {
    u8* vm = self + 8;
    s32 n;
    s32 i;
    XB_ARG a;
    XB_ARG b;

    (void)edx;

    if (xb_LiveObj_IsValid(vm) == 0) {
        return 0;
    }

    *(u16*)(self + 0x44) = user;
    n = xb_LiveObj_Count(D_00798CAC + 0x28);

    for (i = 0; i < n; i++) {
        a.v = i;

        if (*(u32*)((u8*)((XB_XUID* (XB_FASTCALL*)(u8*, XB_ARG))xb_deque_LiveObj_Subscript)(D_00798CAC + 0x28, a) + 0xC) ==
            to.w[1]) {
            a.v = i;
            ((s32 (XB_FASTCALL*)(u8*, XB_XUID))CXHVVoiceManager_AddRemoteTalker)(
                vm, *((XB_XUID* (XB_FASTCALL*)(u8*, XB_ARG))xb_deque_LiveObj_Subscript)(D_00798CAC + 0x28, a));
            a.v = *(s32*)(D_00798CAC + 0x14);

            if (((s32 (XB_FASTCALL*)(u8*, XB_ARG))xb_LiveObj_Process)(self, a) > 1) {
                a.v = i;
                b.v = *(s32*)(D_00798CAC + 0x14);
                {
                    XB_ARG c;

                    c.v = 0xFFFF;
                    ((s32 (XB_FASTCALL*)(u8*, XB_XUID, XB_ARG, XB_ARG))CXHVVoiceManager_SetRemoteTalkerPriority)(
                        vm, *((XB_XUID* (XB_FASTCALL*)(u8*, XB_ARG))xb_deque_LiveObj_Subscript)(D_00798CAC + 0x28, a), b, c);
                }
            }

            return 1;
        }
    }

    return 0;
}

u8* XB_FASTCALL xb_LiveWork_Get2408(u8* self);

/* xb_LiveWork_StopVoice 0xF5E38: the Live work's voice object stopped. */
void xb_LiveWork_StopVoice(void) {
    xb_LiveObj_Stop(xb_LiveWork_Get2408(D_00798CAC));
}

void** XB_FASTCALL xb_iterator_ctor(void** self, s32 edx, void* p);
void* XB_FASTCALL CXHVVoiceManager_ctor(void* self);
void XB_FASTCALL CXHVVoiceManager_dtor(void* self);
void* XB_FASTCALL CXBStopWatch_ctor(void* self);
void XB_FASTCALL CXBSocket_dtor(void* self);
extern void* D_002B4560[];

/* xb_VOICECHAT_CLASS_ctor 0xF5918: the voice chat object: two sockets
 * (+4, +0x68, none open), the voice manager (+8), a timer (+0x70), and
 * its state cleared (port +0x48 1001). */
u8* XB_FASTCALL xb_VOICECHAT_CLASS_ctor(u8* self) {
    XB_ARG a;

    *(void**)self = D_002B4560;
    a.v = -1;
    ((void** (XB_FASTCALL*)(void**, XB_ARG))xb_iterator_ctor)((void**)(self + 4), a);
    CXHVVoiceManager_ctor(self + 8);
    ((void** (XB_FASTCALL*)(void**, XB_ARG))xb_iterator_ctor)((void**)(self + 0x68), a);
    CXBStopWatch_ctor(self + 0x70);
    *(s32*)(self + 0x58) = 0;
    *(s32*)(self + 0x5C) = 0;
    *(s32*)(self + 0x60) = 0;
    *(s32*)(self + 0x40) = 0;
    *(u16*)(self + 0x44) = 0;
    self[0x4C] = 0;
    *(s32*)(self + 0x50) = 0;
    *(s32*)(self + 0x94) = 0;
    *(s32*)(self + 0x64) = 0;
    *(s32*)(self + 0x48) = 0x3E9;
    return self;
}

/* xb_VOICECHAT_CLASS_dtor 0xF565D. */
void XB_FASTCALL xb_VOICECHAT_CLASS_dtor(u8* self) {
    *(void**)self = D_002B4560;
    CXBSocket_dtor(self + 0x68);
    CXHVVoiceManager_dtor(self + 8);
    CXBSocket_dtor(self + 4);
}

s32 XB_STDCALL XHVEngine_EnableProcessingMode(s32 engine, s32 mode);
s32 XB_STDCALL XHVEngine_SetCallbackInterface(s32 engine, void* cb);
s32 XB_STDCALL XHVEngine_RegisterLocalTalker(s32 engine, s32 port);
s32 XB_STDCALL XHVEngine_SetMaxPlaybackStreamsCount(s32 engine, s32 n);

/* IXHVEngine__SetMaxPlaybackStreamsCount 0xF5873. */
s32 XB_STDCALL IXHVEngine__SetMaxPlaybackStreamsCount(s32 engine, s32 n) {
    return XHVEngine_SetMaxPlaybackStreamsCount(engine, n);
}

/* xb_VoiceMgr_SetMaxStreams 0xF58C8: the voice manager's engine (+4)
 * told how many voices it may play at once. */
s32 XB_FASTCALL xb_VoiceMgr_SetMaxStreams(u8* self, s32 edx, s32 n) {
    (void)edx;
    return IXHVEngine__SetMaxPlaybackStreamsCount(*(s32*)(self + 4), n);
}

/* IXHVEngine__EnableProcessingMode 0xF6D84. */
s32 XB_STDCALL IXHVEngine__EnableProcessingMode(s32 engine, s32 mode) {
    return XHVEngine_EnableProcessingMode(engine, mode);
}

/* IXHVEngine__SetCallbackInterface 0xF6D89. */
s32 XB_STDCALL IXHVEngine__SetCallbackInterface(s32 engine, void* cb) {
    return XHVEngine_SetCallbackInterface(engine, cb);
}

/* IXHVEngine__RegisterLocalTalker 0xF6D8E. */
s32 XB_STDCALL IXHVEngine__RegisterLocalTalker(s32 engine, s32 port) {
    return XHVEngine_RegisterLocalTalker(engine, port);
}

s32 XB_FASTCALL CXBSocket_Close(void* self);
u8* XB_STDCALL XOnlineGetLogonUsers(void);
s32 XB_FASTCALL CXHVVoiceManager_Initialize(u8* self, s32 edx, s32 dsound, u32* params, void* cb);
s32 XB_FASTCALL CXHVVoiceManager_RegisterLocalTalker(u8* self, s32 edx, s32 port);
s32 XB_FASTCALL xb_LiveObj_Call2(u8* self, s32 edx, s32 a, s32 b);
void XB_FASTCALL xb_XLIVE_STARTMENU_CLASS_Set74(u8* self, s32 edx, s32 v);
void xb_xlive_net_SetVoiceMode(s32 v);
extern s32 D_00795C10;
extern s32 D_0079B830;
extern s32 D_002BA6BC;

/* xb_VOICECHAT_CLASS_Start 0xF5C65: voice chat started for the signed-on
 * player: the state and socket reset, the logged-on users (+0xB0), the
 * voice manager (+8) set up on DirectSound (D_00795C10) with this object
 * as its callback (an error stops here), two voices at once, the local
 * talker registered unless the player has voice off (+0xA; a voice-banned
 * account sets +0x90), the voice routing of each pad, and the voice mode
 * and the start menu's voice item on. */
void XB_FASTCALL xb_VOICECHAT_CLASS_Start(u8* self) {
    u32 params[9];
    XB_XUID* u;
    s32 i;
    XB_ARG a;
    XB_ARG b;
    XB_ARG c;

    xb_xlive_net_SetVoiceMode(0);
    *(s32*)(self + 0x40) = 0;
    *(u16*)(self + 0x44) = 0;
    self[0x4C] = 0;
    *(s32*)(self + 0x48) = 0x3E9;
    *(s32*)(self + 0x50) = 0;
    CXBSocket_Close(self + 4);
    *(s32*)(self + 0x60) = 1;
    *(u8**)(self + 0xB0) = XOnlineGetLogonUsers();
    memset(&params[1], 0, 8 * 4);
    params[3] = 0;
    params[4] = D_0079B830;
    params[1] = 4;
    params[0] = 0x1E;
    params[2] = 0xA;
    params[5] = 5;
    a.v = D_00795C10;
    b.v = (s32)params;
    c.v = (s32)self;

    if (((s32 (XB_FASTCALL*)(u8*, XB_ARG, XB_ARG, XB_ARG))CXHVVoiceManager_Initialize)(self + 8, a, b, c) < 0) {
        _assert(D_0025CCA0, D_002B4580, 0xC8);
        return;
    }

    a.v = 2;
    ((s32 (XB_FASTCALL*)(u8*, XB_ARG))xb_VoiceMgr_SetMaxStreams)(self + 8, a);
    a.v = 0;
    u = ((XB_XUID* (XB_FASTCALL*)(u8*, XB_ARG))xb_deque_LiveObj_Subscript)(D_00798CAC + 0x28, a);

    if (!(((u8*)u)[0xA] & 1)) {
        a.v = *(s32*)(D_00798CAC + 0x14);
        ((s32 (XB_FASTCALL*)(u8*, XB_ARG))CXHVVoiceManager_RegisterLocalTalker)(self + 8, a);
    } else {
        a.v = 0;
        u = ((XB_XUID* (XB_FASTCALL*)(u8*, XB_ARG))xb_deque_LiveObj_Subscript)(D_00798CAC + 0x28, a);

        if (!(((u8*)u)[8] & 3)) {
            *(s32*)(self + 0x90) = 1;
        }
    }

    *(s32*)(self + 0x64) = 1;

    for (i = 0; i < 4; i++) {
        a.v = i;

        if (((s32 (XB_FASTCALL*)(u8*, XB_ARG))xb_LiveObj_Process)(self, a) > 1) {
            b.v = D_002BA6BC;
            ((s32 (XB_FASTCALL*)(u8*, XB_ARG, XB_ARG))xb_LiveObj_Call2)(self + 8, a, b);
        }
    }

    xb_xlive_net_SetVoiceMode(1);
    *(s32*)(self + 0x58) = 1;
    a.v = 1;
    ((void (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_STARTMENU_CLASS_Set74)(D_00798CAC + 0x24C0, a);
}
