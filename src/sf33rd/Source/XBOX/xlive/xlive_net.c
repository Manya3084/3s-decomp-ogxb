/* xlive_net.c: the Live link's sockets, retail sf33rd.xbe 0x10FF9A on.
 * Its own file: xb_0F501C.c calls xb_xlive_net_Peer for nothing, which
 * retail keeps, so the body must not be visible there. The xb_ names are
 * made up. */

#include "types.h"

/* The Live link's sockets: the listen socket (D_00799450, open flag
 * D_00799454) and the peer socket (D_00799458, D_0079945C), the link
 * state (D_00799420) and two peers' 0x300-byte records (D_00799460). */
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

