/* xb_11D590.c: Xbox-only code from 0x11D590, the network sync state
 * setters. They match only outside the file that defines
 * xb_NetSync_SetState, so they are taken to be another module.
 * Capcom's source is lost. Its C++ methods are written as C,
 * XB_FASTCALL (__fastcall) with this first. Each body was checked
 * against retail by analysis-ps2map/xbgen.py. The xb_ names are
 * made up. */

#include "types.h"
#include <string.h>

void xb_NetSync_SetState(s32 state);

s32 xb_NetSync_SetState7(void) {
    xb_NetSync_SetState(7);
    return 1;
}

s32 xb_NetSync_SetState8(void) {
    xb_NetSync_SetState(8);
    return 1;
}

/* xb_LiveWork_Init 0x11ECB5.
 *
 * Points XLw (D_00798CAC) at the Xbox Live work object (0x79B838) and,
 * when its task starts, sets up the language, resets its state, starts
 * the Ethernet link polling and the save callbacks, and starts the
 * online object thread (+0x2408). */

extern u8* D_00798CAC;
extern u8 D_0079B838[];
s32 XB_FASTCALL xb_XLIVE_WORK_CLASS_InitTask(u8* self);
void XB_FASTCALL xb_XLIVE_WORK_CLASS_ResetState(u8* self);
void xb_SetupLiveLanguage(void);
void xb_ResetLinkPollTimer(void);
void xb_PollEthernetLink(void);
void xb_RegisterSaveCallbacks(void);
void xb_RegisterSaveHandlers(void);
void XB_FASTCALL xb_LiveObj_StartThread(u8* self);

void xb_LiveWork_Init(void) {
    D_00798CAC = D_0079B838;

    if (xb_XLIVE_WORK_CLASS_InitTask(D_0079B838)) {
        xb_SetupLiveLanguage();
        xb_XLIVE_WORK_CLASS_ResetState(D_0079B838);
        xb_ResetLinkPollTimer();
        xb_PollEthernetLink();
        xb_RegisterSaveCallbacks();
        xb_RegisterSaveHandlers();
        xb_LiveObj_StartThread(D_00798CAC + 0x2408);
        *(s32*)(D_00798CAC + 0x2330) = 0;
    }
}

/* The online match's link watch (Game's Live case): NetSync stepped each
 * frame; when the link drops (-1: NetSync's error, as an error code from
 * xb_NetSync_ErrorCode) or the Live work ends the match (-2), a message
 * is shown for at least a second and, once A is pressed, the select is
 * entered again. The steps are NetSync's two counters (GetCountA: 0 the
 * link, 1 the work) and their timers (GetCountB). */
s32 xb_NetSync_GetCountA(s32 i);
s32 xb_NetSync_IncCountA(s32 i);
s32 xb_NetSync_GetCountB(s32 i);
s32 xb_NetSync_IncCountB(s32 i);
s32 xb_NetSync_ClearCountB(s32 i);
s32 xb_NetSync_GetDesync(void);
s32 xb_NetSync_GetPacketTarget(void);
s32 xb_xlive_NetUpdate(void);
u16 Convert_User_Setting(s16 PL_id);
void xb_xlive_PadBits(u32 sw, u8* out);
s32 xb_LiveWork_Get14(void);
s32 xb_LivePadAccept(void);
void xb_SeSelectedThunk(void);
u8 xb_LiveWork_Get2360(void);
void xb_xlive_match_VoicePeerLookup(void);
void xb_xlive_select_Restart(void);
void xb_xlive_select_Enter(s32 mode);
s32 xb_GetOnlineFlag(void);
s32 sub_0004AFFA(void);
s32 xb_LiveWork_Update(void);
void xb_LiveWork_StopVoice(void);
s32 xb_xlive_net_Close(void);
void xb_LiveWork_ReleaseStartMenu(void);
void xb_LiveWork_ClearStartMenu(void);
void Request_LDREQ_Break(void);
s32 xb_xlive_main_SetErrorArgs(s32 hr, const char* file, s32 line, s32 fatal);
void xb_LiveWork_Set2334(s32 v);
void xb_LiveWork_EndError(void);
extern u16 p1sw_0;
extern u16 PLsw[2][2];
extern char D_002B87B8[];

/* xb_NetSync_ResetPads 0x11EDEF: player 1's pad set from the user's
 * settings. Retail passes the pad's address, not its switches, to
 * xb_xlive_PadBits, so p1sw_0 and PLsw get bits of that address. */
void xb_NetSync_ResetPads(void) {
    u32 pad[13];

    memset(pad, 0, sizeof(pad));
    pad[1] = Convert_User_Setting(0);
    xb_xlive_PadBits((u32)pad, (u8*)&p1sw_0);
    xb_xlive_PadBits((u32)pad, (u8*)PLsw);
}

/* xb_NetSync_WaitCountB 0x11EE30: counter i's timer counted up to n;
 * 1 once it is there. */
s32 xb_NetSync_WaitCountB(s32 i, s32 n) {
    if (xb_NetSync_GetCountB(i) < n) {
        xb_NetSync_IncCountB(i);
        return 0;
    }

    return 1;
}

/* xb_xlive_GetPadIndex 0x11EE51: the Live pad's index (0 or 1). */
s32 xb_xlive_GetPadIndex(void) {
    return xb_LiveWork_Get14() & 1;
}

/* xb_xlive_ConfirmPressed 0x11EE5A: A pressed (with the select sound). */
s32 xb_xlive_ConfirmPressed(void) {
    xb_xlive_GetPadIndex();

    if (xb_LivePadAccept()) {
        xb_SeSelectedThunk();
        return 1;
    }

    return 0;
}

/* xb_NetSync_ErrorCode 0x11EE74: the message for how the link ended: 14
 * for a desync or a timeout, 13 for a lost connection, 16 for a send or
 * receive error, 15 for a long silence, else 17. */
s32 xb_NetSync_ErrorCode(void) {
    if (xb_NetSync_GetDesync()) {
        return 0xE;
    }

    switch (xb_NetSync_GetPacketTarget()) {
    case 3:
    case 4:
        return 0x10;
    case 0xB:
    case 0xC:
    case 0xD:
        return 0xD;
    case 0xE:
    case 0x12:
        return 0xE;
    case 0x10:
    case 0x11:
        return 0xF;
    }

    return 0x11;
}

/* xb_NetSync_SyncPads 0x11F0ED: one frame of the link (the arguments are
 * unused). Returns NetSync's result (1 when a frame was played), 0 while
 * a message is up, 1 offline. */
s32 xb_NetSync_SyncPads(s32 a, s32 b) {
    s32 r = 1;

    (void)a;
    (void)b;

    if (xb_LiveWork_Get2360() == 1) {
        xb_xlive_match_VoicePeerLookup();
        xb_xlive_select_Restart();
        return 0;
    }

    if (!xb_GetOnlineFlag()) {
        return r;
    }

    if (xb_NetSync_GetCountA(0) == 0 && xb_NetSync_GetCountA(1) == 0) {
        r = xb_xlive_NetUpdate();
    } else {
        r = -1;
    }

    if (sub_0004AFFA() == 0) {
        if (xb_NetSync_GetCountA(1) != 0) {
            r = -2;
        } else if (xb_LiveWork_Update()) {
            xb_NetSync_ClearCountB(1);
            r = -2;
        }
    }

    if (r == -2) {
        r = 0;

        switch (xb_NetSync_GetCountA(1)) {
        case 0:
            xb_NetSync_IncCountA(1);
            xb_LiveWork_StopVoice();
            xb_xlive_net_Close();
            xb_LiveWork_ReleaseStartMenu();
            xb_LiveWork_ClearStartMenu();
            /* fallthrough */
        case 1:
            if (xb_NetSync_WaitCountB(1, 0x3C) && xb_xlive_ConfirmPressed()) {
                xb_NetSync_IncCountA(1);
                xb_NetSync_ClearCountB(1);
                xb_LiveWork_EndError();
            }

            break;
        case 2:
            if (xb_NetSync_WaitCountB(1, 0x3C)) {
                xb_NetSync_IncCountA(1);
                xb_NetSync_ClearCountB(1);
            }

            break;
        default:
            xb_xlive_select_Restart();
            break;
        }
    } else if (r == -1) {
        switch (xb_NetSync_GetCountA(0)) {
        case 0:
            xb_NetSync_IncCountA(0);
            xb_NetSync_ClearCountB(0);
            xb_xlive_match_VoicePeerLookup();
            xb_LiveWork_StopVoice();
            xb_xlive_net_Close();
            xb_LiveWork_ReleaseStartMenu();
            xb_LiveWork_ClearStartMenu();
            r = xb_NetSync_ErrorCode();
            Request_LDREQ_Break();
            xb_xlive_main_SetErrorArgs(r, D_002B87B8, 0x169, 1);
            xb_LiveWork_Set2334(1);
            /* fallthrough */
        case 1:
            r = 0;

            if (xb_NetSync_WaitCountB(0, 0x3C) && xb_xlive_ConfirmPressed()) {
                xb_NetSync_IncCountA(0);
                xb_NetSync_ClearCountB(0);
                xb_LiveWork_EndError();
                xb_xlive_select_Enter(0);
                xb_LiveWork_Set2334(0);
            }

            break;
        case 2:
            r = 0;

            if (xb_NetSync_WaitCountB(0, 0x3C)) {
                xb_NetSync_IncCountA(0);
                xb_NetSync_ClearCountB(0);
            }

            break;
        default:
            xb_NetSync_ResetPads();
            break;
        }
    }

    return r;
}

/* NetSync's state as xb_0F501C.c keeps it (see there). */
typedef struct {
    u16 frame;
    u16 pad;
    u16 sw0;
    u16 sw1;
    u32 data[2];
} XB_NSFRAME;
typedef struct {
    u8 flag;
    u8 color[20];
    u8 shot[8];
} XB_NSREC;
typedef struct {
    u16 lo;
    u16 hi;
} XB_SEQ;
typedef struct {
    u8 b[12];
} XB_NSHELLO;
s32 xb_NetSync_BuildData(s32 sock, s8 pl, u8 flag);
s32 xb_NetSync_BuildAck(s32 sock, s8 pl, u8 a, u8 b);
s32 xb_NetSync_BuildHeader(s32 sock, s32 a, s32 b, XB_SEQ seq, s32 c, s32* id);
extern s8 D_007A7A0A;
extern s16 D_007A7A08;
extern u8 D_007A7A0B;
extern s16 D_007A7A0E;
extern s8 D_007A7A13;
extern s8 D_007A7A14;
extern s16 D_007A7A58;
extern u16 D_007A7A5C;
extern s32 D_007A7A6C;
extern u8* D_007A7A74;
extern s32 D_007A7A78;
extern s32 D_007A7A7C;
extern s32 D_007A7A80;
extern u8* D_007A7A88;
extern s32 D_007A7AAC;
extern u16 D_007A7B20[4][16];
extern u16 D_007A7BA0[4];
extern u16 D_007A64DC;
extern u16 D_007A64E0[4];
extern XB_NSFRAME D_007A6540[4][64];
extern u16 D_007A75A0[16];
extern XB_NSREC D_007A6480[2];

/* xb_NetSync_ParsePacket 0x11D5F2: one message from player (its second
 * byte's low nibble; the high nibble is its kind) acted on: 0x10 data
 * done (1: the player is in, D_007A7A08; 0: send ours again), 0x20 the
 * player's frames (a two-byte entry repeats the last pad), 0x30 the
 * player is ready, 0x50 a ping (0) or its answer (1: the round trip
 * kept), 0x60 a hello (0x1031: answered, 0x3110) or a goodbye (0x1032:
 * 0x3210), 0x90 slow down (one more frame ahead, at most every 40
 * seconds), 0xB0 a part of the player's data, 0xC0 its settings and data.
 * Returns the message's kind and player byte, 0x3110 or 0x3210, 0 when
 * our data was sent again, -2 for an unknown kind. */
s32 xb_NetSync_ParsePacket(s32 sock, u8 pl, u8* msg) {
    XB_NSHELLO h;
    u16 len;
    u16 kind;
    u16 from;
    s32 r;
    s32 off;
    s32 n;
    s32 i;
    u16 w;
    u16* next;
    XB_NSFRAME* e;
    XB_NSFRAME* prev;

    len = msg[0];
    kind = msg[1] & 0xF0;
    from = msg[1] & 0xF;
    r = msg[1];

    if (D_007A7A0A <= from) {
        kind = 0;
    }

    switch (kind) {
    case 0x60:
        h = *(XB_NSHELLO*)(msg + 2);

        switch ((h.b[2] << 8) | h.b[3]) {
        case 0x1031:
            /* Retail passes no id here, which xb_NetSync_BuildHeader reads. */
            xb_NetSync_BuildHeader(sock, pl, *(s32*)(msg + 2), *(XB_SEQ*)(msg + 6), *(s32*)(msg + 10), 0);
            r = 0x3110;
            break;
        case 0x1032:
            D_007A7A0B++;
            r = 0x3210;
            break;
        }

        break;
    case 0x50:
        switch (msg[2]) {
        case 0:
            xb_NetSync_BuildAck(sock, pl, from, msg[3]);
            break;
        case 1:
            if (msg[4] == (s8)pl) {
                D_007A64E0[from]++;
                D_007A7B20[from][msg[3]] = D_007A7AAC - D_007A75A0[msg[3]];
            }

            break;
        }

        break;
    case 0x30:
        if (msg[2] == 0) {
            D_007A7A0E |= 1 << from;
        }

        break;
    case 0x20:
        off = 2;

        if (len > 2) {
            next = &D_007A7BA0[from];

            do {
                e = &D_007A6540[from][*next];
                w = (msg[off] << 8) | msg[off + 1];

                if ((s16)w < 0) {
                    prev = &D_007A6540[from][*next == 0 ? 0x3F : *next - 1];
                    e->frame = w;
                    e->data[0] = prev->data[0];
                    e->sw0 = 0;
                    e->sw1 = 0;
                    n = w & 0x7FFF;
                    e->data[1] = prev->data[1];
                } else {
                    e->frame = w;
                    e->sw0 = (msg[off + 4] << 8) | msg[off + 5];
                    e->sw1 = (msg[off + 6] << 8) | msg[off + 7];
                    e->data[0] = *(u32*)(msg + off + 8);
                    n = 0x10;
                    e->data[1] = *(u32*)(msg + off + 12);
                }

                off += n;
                len -= n;
                *next = (u16)(*next + 1) % 64;
            } while (len > 2);
        }

        break;
    case 0x10:
        switch (msg[2]) {
        case 0:
            xb_NetSync_BuildData(sock, pl, 1);
            r = 0;
            break;
        case 1:
            D_007A7A08 |= 1 << from;
            D_007A7A5C = D_007A7A08;
            break;
        }

        break;
    case 0x70:
        break;
    case 0xC0:
        D_007A6480[from].flag = msg[2];
        D_007A6480[from].shot[0] = msg[3];
        D_007A6480[from].shot[1] = msg[4];
        D_007A6480[from].shot[2] = msg[5];
        D_007A6480[from].shot[3] = msg[6];
        D_007A6480[from].shot[4] = msg[7];
        D_007A6480[from].shot[5] = msg[8];
        D_007A6480[from].shot[6] = msg[9];
        D_007A6480[from].shot[7] = msg[10];

        for (i = 0; i < 0x14; i++) {
            D_007A6480[from].color[i] = msg[11 + i];
        }

        n = len - 0x1F;

        if (n > 0 && from != (s8)pl && D_007A7A88 != 0 && D_007A7A80 >= n) {
            memcpy(D_007A7A88, msg + 0x1F, n);
        }

        break;
    case 0xB0:
        if (len - 6 > 0 && from != (s8)pl) {
            w = msg[3] * msg[4];
            n = msg[5];
            D_007A7A7C = msg[2];
            D_007A7A78 = msg[3];

            if (D_007A7A7C > 0) {
                D_007A7A78++;
            }

            if (n > 0 && D_007A7A74 != 0 && D_007A7A6C >= w + n) {
                memcpy(D_007A7A74 + w, msg + 6, n);
            }
        }

        break;
    case 0x90:
        if (D_007A64DC == 0) {
            if (D_007A7A13 <= D_007A7A14) {
                D_007A7A13++;

                if (D_007A7A58 < D_007A7A13) {
                    D_007A7A58 = D_007A7A13;
                }
            }

            D_007A64DC = 0x960;
        }

        break;
    case 0xF0:
        break;
    default:
        r = -2;
        break;
    }

    return r;
}

s32 XB_FASTCALL xb_XLIVE_WORK_CLASS_Run(u8* self);
extern u8 D_0079B838[];

/* xb_LiveWork_Step 0x11ED1A: one frame of the Live work (the Xbox Live
 * menu); 1 once it is left. */
s32 xb_LiveWork_Step(void) {
    return xb_XLIVE_WORK_CLASS_Run(D_0079B838);
}

/* XLIVE_WORK_CLASS's virtual methods (vtable D_002B8708; the base's is
 * D_002B50F0). Slots 12 to 15 start and step the join and host modes,
 * 8 to 10 draw their screens, 3 to 7 give the match's settings and the
 * texts for them. */
void XB_FASTCALL xb_XLIVE_WORK_CLASS_dtor(void** self);
void operator_delete(void* p);
u8* xb_GetMatchInfo(void);
void XB_FASTCALL xb_XLIVE_WORK_CLASS_ResetMatch(u8* self, s32 edx, u8 join);
void XB_FASTCALL xb_XLIVE_WORK_CLASS_ShowMessage(u8* self, s32 edx, u8 i);
void xb_xlive_match_ClearRecordWork(void);
s32 XB_FASTCALL xb_CONNECT_USER_CLASS_IsTaskDone(u8* self);
extern char* D_00799368;
extern char* D_00799284;
extern char* D_00799360;
extern char* D_007991C8;
extern char* D_00799330;
extern char* D_00799180;
extern char* D_0079927C;
extern char* D_00799298;
extern char* D_00799328;
extern char* D_007990DC;
extern char* D_00799370;
extern char* D_00799280;
/* The matchmaking screen's texts. */
extern char* D_007A1340;
extern char* D_007A1344;
extern char* D_007A1348;
extern char* D_007A134C;
extern char* D_007A1350;
extern char* D_007A1354;
extern char* D_007A1358;
/* Two function-local static tables and their guards. */
extern char* D_007A135C[3];
extern u32 D_007A1368;
extern char* D_007A136C[2];
extern u32 D_007A1374;

/* xb_XLIVE_WORK_CLASS_vdtor 0x11ED50 (slot 0): the scalar deleting
 * destructor. */
void* XB_FASTCALL xb_XLIVE_WORK_CLASS_vdtor(u8* self, s32 edx, u32 flags) {
    (void)edx;
    xb_XLIVE_WORK_CLASS_dtor((void**)self);

    if (flags & 1) {
        operator_delete(self);
    }

    return self;
}

/* xb_XLIVE_WORK_CLASS_GetMatch170 0x11EC1A (slot 3). */
s32 XB_FASTCALL xb_XLIVE_WORK_CLASS_GetMatch170(u8* self) {
    (void)self;
    return xb_GetMatchInfo()[0x170];
}

/* xb_XLIVE_WORK_CLASS_ClearMatch170 0x11EC27 (slot 4): the setting
 * cleared; 0. */
u8 XB_FASTCALL xb_XLIVE_WORK_CLASS_ClearMatch170(u8* self) {
    (void)self;
    xb_GetMatchInfo()[0x170] = 0;
    return 0;
}

/* xb_XLIVE_WORK_CLASS_ClearMatchC3 0x11EC36 (slot 5). */
u8 XB_FASTCALL xb_XLIVE_WORK_CLASS_ClearMatchC3(u8* self) {
    (void)self;
    xb_GetMatchInfo()[0xC3] = 0;
    return 0;
}

/* xb_XLIVE_WORK_CLASS_GetRuleText 0x11EC45 (slot 6): the text for one of
 * the three rule settings. */
char* XB_FASTCALL xb_XLIVE_WORK_CLASS_GetRuleText(u8* self, s32 edx, s8 i) {
    (void)self;
    (void)edx;

    if (!(D_007A1368 & 1)) {
        D_007A1368 |= 1;
        D_007A135C[0] = D_00799298;
        D_007A135C[1] = D_00799328;
        D_007A135C[2] = D_007990DC;
    }

    return D_007A135C[i];
}

/* xb_XLIVE_WORK_CLASS_GetModeText 0x11EC82 (slot 7): the text for one of
 * the two mode settings. */
char* XB_FASTCALL xb_XLIVE_WORK_CLASS_GetModeText(u8* self, s32 edx, s8 i) {
    (void)self;
    (void)edx;

    if (!(D_007A1374 & 1)) {
        D_007A1374 |= 1;
        D_007A136C[0] = D_00799370;
        D_007A136C[1] = D_00799280;
    }

    return D_007A136C[i];
}

#define XB_MM_TEXTS()              \
    do {                           \
        D_007A134C = D_00799368;   \
        D_007A1350 = D_00799284;   \
        D_007A1340 = D_00799360;   \
        D_007A1344 = D_007991C8;   \
        D_007A1348 = D_00799330;   \
        D_007A1354 = D_00799180;   \
        D_007A1358 = D_0079927C;   \
    } while (0)

/* xb_XLIVE_WORK_CLASS_JoinStart 0x11DBAD (slot 12, the join mode's step
 * 0): a match to join set up, the record work cleared, the join message
 * and the matchmaking texts. */
void XB_FASTCALL xb_XLIVE_WORK_CLASS_JoinStart(u8* self) {
    XB_ARG a;

    a.v = 1;
    ((void (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_WORK_CLASS_ResetMatch)(self, a);
    xb_xlive_match_ClearRecordWork();
    ((void (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_WORK_CLASS_ShowMessage)(self, a);
    XB_MM_TEXTS();
}

/* xb_XLIVE_WORK_CLASS_HostStart 0x11E3F4 (slot 14): the same for hosting,
 * and the users count asked for. */
s32 XB_FASTCALL xb_XLIVE_WORK_CLASS_HostStart(u8* self) {
    XB_ARG a;

    a.v = 0;
    ((void (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_WORK_CLASS_ResetMatch)(self, a);
    xb_xlive_match_ClearRecordWork();
    a.v = 2;
    ((void (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_WORK_CLASS_ShowMessage)(self, a);
    XB_MM_TEXTS();
    return xb_CONNECT_USER_CLASS_IsTaskDone(D_00798CAC + 0x59E0);
}
