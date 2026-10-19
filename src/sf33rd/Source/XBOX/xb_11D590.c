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
