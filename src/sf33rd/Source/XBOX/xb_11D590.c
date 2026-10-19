/* xb_11D590.c: Xbox-only code from 0x11D590, the network sync state
 * setters. They match only outside the file that defines
 * xb_NetSync_SetState, so they are taken to be another module.
 * Capcom's source is lost. Its C++ methods are written as C,
 * XB_FASTCALL (__fastcall) with this first. Each body was checked
 * against retail by analysis-ps2map/xbgen.py. The xb_ names are
 * made up. */

#include "types.h"

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
