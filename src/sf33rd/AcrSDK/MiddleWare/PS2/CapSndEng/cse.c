/* cseTsbRequest, retail sf33rd.xbe 0xF4464 size 0x4E. cseSysSetMono 0xF4510,
 * cseSysSetMasterVolume 0xF451D, cseSeStopAll 0xF452A, and
 * cseTsbSetBankAddr 0xF4532 follow it in the same object: retail calls them
 * where the PS2 files that define them (Sound3rd.c, color3rd.c) would let
 * the compiler inline them.
 *
 * It is a scanned start. Ten rtpc slots are cleared. A command below
 * 10 adds its parameter into that slot. The call is mlTsbRequest.
 * 0xF44CA and 0xF44F2 are xb_SetColorRamEntry and xb_GetColorRamEntry. 0xF44B2
 * is xb_ClearColorRamEntries.
 */

#include "types.h"

#include <stdarg.h>

extern s32 mlTsbRequest(u16 bank, u16 code, s32 *aRtpc);
extern void mlSysSetMono(u32 mono_sw);
extern void mlSysSetMasterVolume(s32 vol);
extern void xb_StopAllSeSlots(void);
typedef struct SoundEvent SoundEvent;
extern s32 mlTsbSetBankAddr(u32 bank, SoundEvent *addr);

s32 cseTsbRequest(u16 bank, u16 code, s32 NumArgSets, ...) {
    s32 rtpc[10] = {0};
    s32 i;
    s32 cmd;
    s32 prm;
    va_list vlist;

    va_start(vlist, NumArgSets);

    for (i = 0; i < NumArgSets; i++) {
        cmd = va_arg(vlist, s32);
        prm = va_arg(vlist, s32);

        if (cmd < 10) {
            rtpc[cmd] += prm;
        }
    }

    va_end(vlist);
    return mlTsbRequest(bank, code, rtpc);
}

/* Xbox: returns 0, not mlSysSetMono's result. */
s32 cseSysSetMono(u32 mono_sw) {
    mlSysSetMono(mono_sw);
    return 0;
}

/* Xbox: returns 0, not mlSysSetMasterVolume's result. */
s32 cseSysSetMasterVolume(s32 vol) {
    mlSysSetMasterVolume(vol);
    return 0;
}

/* Xbox: one stop call (xb_StopAllSeSlots), then 0. */
s32 cseSeStopAll(void) {
    xb_StopAllSeSlots();
    return 0;
}

/* The body is a tail jump to mlTsbSetBankAddr. */
s32 cseTsbSetBankAddr(u32 bank, SoundEvent *addr) {
    return mlTsbSetBankAddr(bank, addr);
}
