/* xb_0F44B2.c: Xbox-only code from the run of Xbox-only functions at 0xF44B2, which no
 * PS2 file covers.
 * Capcom's source is lost. Its C++ methods are written as C,
 * XB_FASTCALL (__fastcall) with this first. Each body was checked
 * against retail by analysis-ps2map/xbgen.py. The xb_ names are
 * made up. */

#include "types.h"

extern s32 D_007A7CF0[];
void xb_LoadListEntry(s32 id, s32 index, void* addr, u32 size);

s32 xb_ClearColorRamEntries(void) {
    D_007A7CF0[2] = -1;
    D_007A7CF0[1] = -1;
    D_007A7CF0[0] = -1;
    return 0;
}

s32 xb_SetColorRamEntry(void* addr, u32 size, s32 id, s32 index) {
    xb_LoadListEntry(id, index, addr, size);
    D_007A7CF0[id] = index;
    return 0;
}

s32 xb_GetColorRamEntry(s32 i) {
    return D_007A7CF0[i];
}
