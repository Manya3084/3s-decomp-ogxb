/* lsc_svr.c, retail sf33rd.xbe.
 * PlayStation 2 C, not hand-adjusted for Xbox. Each named body was located
 * from the PS2 retail map: call graph, source order, and agreement of
 * constants, field offsets, callees, and size. See docs/decompiling.md.
 * The #include lines name headers in the PS2 tree (ps2.path).
 * lsc_ExecHndl 0x173C00 size 0x70.
 * The other functions in this file are not located in sf33rd.xbe yet.
 */

#include "common.h"
#include <cri/private/libadxe/lsc_svr.h>

#if defined(TARGET_PS2)
INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/lsc_svr", D_0055DA68);
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/lsc_svr", lsc_StatWait);
#else
void lsc_StatWait(LSC lsc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/lsc_svr", D_0055DAA8);
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/lsc_svr", lsc_StatRead);
#else
void lsc_StatRead(LSC lsc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/lsc_svr", lsc_StatEnd);
#else
void lsc_StatEnd(LSC lsc) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/lsc_svr", lsc_ExecHndl);
#else
void lsc_ExecHndl(LSC lsc) {
    if ((lsc->unk4 == 1) || (lsc->stat != 2) || (lsc->num_stm <= 0)) {
        return;
    }

    if (lsc->stm[lsc->unk20].stat == 1) {
        lsc_StatRead(lsc);
    }

    if (lsc->stm[lsc->unk20].stat == 2) {
        lsc_StatEnd(lsc);
    }

    if (lsc->stm[lsc->unk20].stat != 0) {
        return;
    }

    lsc_StatWait(lsc);
}
#endif
