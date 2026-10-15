/* ADXT_GetStat 0x167B40, ADXT_Pause 0x167EF0, ADXT_GetStatPause 0x167FC0.
 *
 * Xbox ADXT fields used here: stat +0x01, rna +0x0C, pause_flag +0x72,
 * tvofst +0x9C, svcnt +0xA0. tvofst is the truncated integer of the float
 * expression, and adxt_time_unit (0xCE9B64) is read as an integer.
 * adxt_time_mode is 0x7A5330. adxt_vsync_cnt is 0x7A5374.
 *
 * On the pause path (sw == 1) this build also calls 0x16BF80. That function
 * is not named yet. A null argument there reports
 * "E1205:Illegal parameter (MWRNA=NULL)".
 * ADXT_GetTime is 0x167C10. ADXRNA_SetPlaySw's thunk is 0x1707E0.
 */

#include "types.h"

#include <stddef.h>

#define ADXT_ERR_SHRTBUF (-1)

typedef struct ADX_TALK {
    s8 used;
    s8 stat;
    u8 gap02[0x0A];
    void *rna;
    u8 gap10[0x62];
    s8 pause_flag;
    u8 gap73[0x29];
    s32 tvofst;
    s32 svcnt;
} ADX_TALK;

#if defined(__i386__)
_Static_assert(offsetof(ADX_TALK, stat) == 0x01, "stat");
_Static_assert(offsetof(ADX_TALK, rna) == 0x0C, "rna");
_Static_assert(offsetof(ADX_TALK, pause_flag) == 0x72, "pause_flag");
_Static_assert(offsetof(ADX_TALK, tvofst) == 0x9C, "tvofst");
_Static_assert(offsetof(ADX_TALK, svcnt) == 0xA0, "svcnt");
#endif

typedef struct ADX_TALK *ADXT;

extern s32 adxt_time_mode;
extern s32 adxt_vsync_cnt;
extern s32 adxt_time_unit;

extern void ADXERR_CallErrFunc1(const char *msg);
extern void ADXCRS_Lock(void);
extern void ADXCRS_Unlock(void);
extern void ADXRNA_SetPlaySw(void *rna, s32 sw);
extern void sub_0016BF80(void *rna);
extern void ADXT_GetTime(ADXT adxt, s32 *ncount, s32 *tscale);

s32 ADXT_GetStat(ADXT adxt) {
    if (adxt == 0) {
        ADXERR_CallErrFunc1("E02080814 ADXT_GetStat: parameter error");
        return ADXT_ERR_SHRTBUF;
    }

    return adxt->stat;
}

void ADXT_Pause(ADXT adxt, s32 sw) {
    s32 ncount;
    s32 tscale;
    s32 time_mode_temp;
    s8 stat;

    if (adxt == 0) {
        ADXERR_CallErrFunc1("E02080846 ADXT_Pause: parameter error");
        return;
    }

    stat = adxt->stat;

    if (sw == adxt->pause_flag) {
        return;
    }

    ADXCRS_Lock();
    adxt->pause_flag = (s8)sw;

    if (stat == 3 || stat == 4) {
        if (sw == 1) {
            ADXRNA_SetPlaySw(adxt->rna, 0);
            sub_0016BF80(adxt->rna);
        } else {
            ADXRNA_SetPlaySw(adxt->rna, 1);
            adxt->svcnt = adxt_vsync_cnt;
        }

        time_mode_temp = adxt_time_mode;
        adxt_time_mode = 0;
        ADXT_GetTime(adxt, &ncount, &tscale);
        adxt_time_mode = time_mode_temp;
        adxt->tvofst = (s32)((f32)ncount / (f32)tscale * (f32)adxt_time_unit);
    }

    ADXCRS_Unlock();
}

s32 ADXT_GetStatPause(ADXT adxt) {
    if (adxt == 0) {
        ADXERR_CallErrFunc1("E02080847 ADXT_GetStatPause: parameter error");
        return 0;
    }

    return adxt->pause_flag;
}
