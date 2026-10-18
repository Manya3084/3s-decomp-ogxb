/* cseTsbRequest, retail sf33rd.xbe 0xF4464 size 0x4E.
 * It is a scanned start. Ten rtpc slots are cleared. A command below
 * 10 adds its parameter into that slot. The call is mlTsbRequest.
 * 0xF44CA and 0xF44F2 are xb_SetColorRamEntry and xb_GetColorRamEntry. 0xF44B2
 * is xb_ClearColorRamEntries.
 */

#include "types.h"

#include <stdarg.h>

extern s32 mlTsbRequest(u16 bank, u16 code, s32 *aRtpc);

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
