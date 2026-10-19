/* xlive_net.c: the Live link's sockets, retail sf33rd.xbe 0x10FF9A on.
 * Its own file: xb_0F501C.c calls xb_xlive_net_Peer for nothing, which
 * retail keeps, so the body must not be visible there. The xb_ names are
 * made up. */

#include "types.h"
#include <string.h>

/* The Live link's sockets: the socket to the other console (D_00799450,
 * open flag D_00799454) and, on the host, the listen socket (D_00799458,
 * D_0079945C), the link state (D_00799420) and two peers' 0x300-byte
 * records (D_00799460). */
s32 XB_STDCALL closesocket(u32 s);
extern u32 D_00799450;
extern s32 D_00799454;
extern u32 D_00799458;
extern s32 D_0079945C;
extern u8 D_00799420[];
extern u8 D_00799460[];

/* xb_xlive_net_CloseSockets 0x10FF9A: both open sockets closed. */
s32 xb_xlive_net_CloseSockets(void) {
    if (D_0079945C != 0) {
        D_0079945C = 0;
        closesocket(D_00799458);
    }

    if (D_00799454 != 0) {
        D_00799454 = 0;
        closesocket(D_00799450);
    }

    return 0;
}

/* xb_xlive_net_Close 0x110040. */
s32 xb_xlive_net_Close(void) {
    xb_xlive_net_CloseSockets();
    return 0;
}

/* xb_xlive_net_GetLink 0x110048. */
u8* xb_xlive_net_GetLink(void) {
    return D_00799420;
}

/* xb_xlive_net_Peer 0x110064: peer 0 or 1's record, 0 for others. */
u8* xb_xlive_net_Peer(s32 i) {
    if (i >= 0 && i < 2) {
        return D_00799460 + i * 0x300;
    }

    return 0;
}


/* Bringing up the link: the host (D_00799424 0) accepts the other
 * console's connection, the client connects to the host's address
 * (D_0079944C) on port 1000; then NetSync is started on the socket and
 * stepped. The step (D_00799428) and a timer (D_00799438); the callbacks
 * D_0079A160 run when NetSync starts, at each frame played and at the
 * end. */
typedef struct {
    u16 family;
    u16 port;
    u32 addr;
    char zero[8];
} XB_SOCKADDR_IN;
s32 XB_STDCALL accept(u32 s, XB_SOCKADDR_IN* addr, s32* len);
s32 XB_STDCALL ioctlsocket(u32 s, s32 cmd, u32* arg);
s32 XB_STDCALL WSAGetLastError(void);
u32 XB_STDCALL socket(s32 af, s32 type, s32 protocol);
s32 XB_STDCALL connect(u32 s, const XB_SOCKADDR_IN* addr, s32 len);
u16 XB_STDCALL htons(u16 v);
s32 xb_GetOnlineModeArg2(void);
void xb_NetSync_Open(s8 n, s8 pl, s32 sock, s32 key, s32 pad, u16* outkey, u16* out2);
s32 xb_NetSync_Update(void);
extern s32 D_00799424;
extern s32 D_00799428;
extern s32 D_00799438;
extern s32 D_00799444;
extern s32 D_00799448;
extern u32 D_0079944C;
extern u8 D_00799440;
extern void (*D_0079A160[3])(void);
extern s32 D_0079A16C;
extern s32 D_0079A170;

/* xb_xlive_net_StartSync 0x1100B8: NetSync started for two players on
 * the link's socket. */
s32 xb_xlive_net_StartSync(void) {
    xb_NetSync_Open(2, D_00799440 & 1, D_00799450, D_00799448, xb_GetOnlineModeArg2(), 0, 0);

    if (D_0079A160[0] != 0) {
        D_0079A160[0]();
    }

    return 0;
}

/* xb_xlive_net_Sync 0x1100F3: one NetSync step; a played frame moves the
 * link on. -1 on an error. */
s32 xb_xlive_net_Sync(void) {
    s32 r = xb_NetSync_Update();

    if (r == -1) {
        return -1;
    }

    if (r == 1) {
        D_00799428++;

        if (D_0079A160[1] != 0) {
            D_0079A160[1]();
        }
    }

    return 0;
}

/* xb_xlive_net_SetDone 0x11011A: the link is up. */
s32 xb_xlive_net_SetDone(void) {
    D_0079A170 = 1;
    D_0079A16C = 1;

    if (D_0079A160[2] != 0) {
        D_0079A160[2]();
    }

    return 0;
}

/* xb_xlive_net_Accept 0x110135: the host's side: up to 20 seconds to
 * accept the connection, which is made blocking and the listen socket
 * closed. Returns 2 on a timeout, 4 when NetSync fails, 5 on another
 * error, else 0. */
s32 xb_xlive_net_Accept(void) {
    XB_SOCKADDR_IN addr;
    s32 len;
    u32 nb;

    nb = 0;
    len = sizeof(addr);

    switch (D_00799428) {
    case 0:
        D_00799428 = 1;
        D_00799438 = 0x4B0;
        /* fallthrough */
    case 1:
        if (--D_00799438 <= 0) {
            return 2;
        }

        D_00799450 = accept(D_00799458, &addr, &len);

        if (D_00799450 == (u32)-1) {
            D_00799444 = WSAGetLastError();

            if (D_00799444 == 0x2733) {
                return 0;
            }

            return 5;
        }

        ioctlsocket(D_00799450, 0x8004667E, &nb);
        D_0079945C = 0;
        D_00799454 = 1;
        closesocket(D_00799458);
        D_00799428++;
        /* fallthrough */
    case 2:
        xb_xlive_net_StartSync();
        D_00799428++;
        /* fallthrough */
    case 3:
        if (xb_xlive_net_Sync() < 0) {
            return 4;
        }

        return 0;
    case 4:
        xb_xlive_net_SetDone();
        return 0;
    }

    return 5;
}

/* xb_xlive_net_Connect 0x110226: the client's side: a second's wait,
 * then a TCP connection to the host. Returns 4 when NetSync fails, 5 on
 * another error, else 0. */
s32 xb_xlive_net_Connect(void) {
    XB_SOCKADDR_IN a;

    switch (D_00799428) {
    case 0:
        D_00799428 = 1;
        D_00799438 = 0x3C;
        /* fallthrough */
    case 1:
        if (--D_00799438 <= 0) {
            D_00799428++;
        }

        return 0;
    case 2:
        D_00799450 = socket(2, 1, 6);

        if (D_00799450 == (u32)-1) {
            return 5;
        }

        a.family = 2;
        a.addr = D_0079944C;
        a.port = htons(1000);

        if (connect(D_00799450, &a, sizeof(a)) != 0) {
            closesocket(D_00799450);
            return 5;
        }

        D_00799428++;
        D_00799454 = 1;
        /* fallthrough */
    case 3:
        xb_xlive_net_StartSync();
        D_00799428++;
        /* fallthrough */
    case 4:
        if (xb_xlive_net_Sync() < 0) {
            return 4;
        }

        return 0;
    case 5:
        xb_xlive_net_SetDone();
        return 0;
    }

    return 5;
}

/* xb_xlive_net_Step 0x11031E: one step of bringing up the link; an
 * error stops it (step -1). */
s32 xb_xlive_net_Step(void) {
    s32 r;

    if (D_00799424 == 0) {
        r = xb_xlive_net_Accept();
    } else {
        r = xb_xlive_net_Connect();
    }

    if (r != 0) {
        D_00799428 = -1;
    }

    return r;
}


extern s32 D_0079A344;

/* xb_xlive_net_SetVoiceMode 0x11033F. */
void xb_xlive_net_SetVoiceMode(s32 v) {
    D_0079A344 = v;
}

/* The network's start-up: the link flag (D_0079A178), XNet's and
 * Winsock's started flags (D_0079A31C, D_0079A320), XNet's start-up
 * parameters (D_0079A180) and the Winsock data (D_0079A18C). */
u32 XB_STDCALL XNetGetEthernetLinkStatus(void);
s32 XB_STDCALL XNetStartup(void* params);
s32 XB_STDCALL WSAStartup(u16 version, void* data);
s32 XB_STDCALL XNetCleanup(void);
extern s32 D_0079A178;
extern s32 D_0079A31C;
extern s32 D_0079A320;
extern u8 D_0079A180[12];
extern u8 D_0079A18C[];
extern u32 D_0079A324[2];
extern u32 D_0079A32C[4];
extern u32 D_0079A33C[2];

/* xb_xlive_net_UpdateLink 0x11037E: whether the Ethernet cable is in. */
void xb_xlive_net_UpdateLink(void) {
    D_0079A178 = XNetGetEthernetLinkStatus() & 1;
}

/* xb_xlive_net_IsLinked 0x11038C. */
s32 xb_xlive_net_IsLinked(void) {
    return D_0079A178;
}

/* xb_xlive_net_Startup 0x110392: with the cable in, XNet (once, with the
 * bypass-security flag) and Winsock 2.2 (once) started and the link's
 * records cleared. 0, or -1 with no link or on an error. */
s32 xb_xlive_net_Startup(void) {
    xb_xlive_net_UpdateLink();

    if (xb_xlive_net_IsLinked() == 0) {
        return -1;
    }

    if (D_0079A31C == 0) {
        memset(D_0079A180, 0, sizeof(D_0079A180));
        D_0079A180[0] = 0xC;
        D_0079A180[7] = 0x20;

        if (XNetStartup(D_0079A180) != 0) {
            return -1;
        }

        D_0079A31C = 1;
    }

    if (D_0079A320 == 0) {
        if (WSAStartup(0x202, D_0079A18C) != 0) {
            XNetCleanup();
            return -1;
        }

        D_0079A320 = 1;
    }

    memset(D_0079A324, 0, sizeof(D_0079A324));
    memset(D_0079A32C, 0, sizeof(D_0079A32C));
    memset(D_0079A33C, 0, sizeof(D_0079A33C));
    return 0;
}
