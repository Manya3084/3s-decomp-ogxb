/* aix.c: the AIX demultiplexer under AIXP, 0x16EB40 to 0x16F690 (between
 * sj_rbf and sj_mem). The PS2 build has no AIX, so this is the Xbox CRI
 * code alone. Four handles of 0x195C bytes are at 0xCD6920 and the library
 * reference count is 0x7A6078. A handle keeps its track count at +0xAC,
 * per-track records of 0x10 bytes from +0x2B4, and its mode at +0x1958.
 */

#include "types.h"

#include <string.h>

extern void ADXERR_CallErrFunc1(const char *msg);
extern void sub_0016AA60(void);
extern void sub_0016AA70(void);
extern s32 aix_init_cnt; /* aix_init_cnt is 0x7A6078 */
extern u8 aix_obj[4][0x195C]; /* aix_obj is 0xCD6920 */

void xb_aixerr_CallErrFunc1(const char *msg) {
    ADXERR_CallErrFunc1(msg);
}

void xb_aixp_InitLib(void) {
    sub_0016AA60();

    if (aix_init_cnt == 0) {
        memset(aix_obj, 0, sizeof(aix_obj));
    }

    aix_init_cnt++;
    sub_0016AA70();
}

void xb_aixp_FinishLib(void) {
    sub_0016AA60();

    if (--aix_init_cnt == 0) {
        memset(aix_obj, 0, sizeof(aix_obj));
    }

    sub_0016AA70();
}

void xb_aixp_FreeHandle(void *aix) {
    sub_0016AA60();

    if (aix != 0) {
        *(s32 *)aix = 0;
    }

    sub_0016AA70();
}

void xb_aix_Reset(void *aix) {
    u8 *bytes = aix;

    sub_0016AA60();
    *(s32 *)(bytes + 0x10) = 0;
    *(s32 *)(bytes + 8) = 0;
    *(s32 *)(bytes + 0xC) = 0;
    bytes[1] = 1;
    sub_0016AA70();
}

void xb_aix_SetField1C(void *aix, void *sj) {
    *(void **)((u8 *)aix + 0x1C) = sj;
}

void xb_aix_SetField3(void *aix, s8 v) {
    ((s8 *)aix)[3] = v;
}

void xb_aix_SetField4(void *aix, s8 v) {
    ((s8 *)aix)[4] = v;
}

s32 xb_aix_GetNumTrack(void *aix) {
    return ((s8 *)aix)[0xAC];
}

s32 xb_aix_GetField2B0(void *aix) {
    return *(s32 *)((u8 *)aix + 0x2B0);
}

void xb_aix_GetTrackInfo(void *aix, s32 tr, s32 *a, s32 *b) {
    if (a != 0) {
        *a = *(s32 *)((u8 *)aix + tr * 0x10 + 0x2B4);
    }

    if (b != 0) {
        *b = *(s32 *)((u8 *)aix + tr * 0x10 + 0x2B8);
    }
}

s32 xb_aix_GetMode(void *aix) {
    return *(s32 *)((u8 *)aix + 0x1958);
}
