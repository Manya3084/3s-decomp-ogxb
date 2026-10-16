/* LSC_SetStmHndl 0x1709B0. LSC_ResetEntry 0x170AB0.
 * LSC_Stop 0x170AE0.
 * LSC_GetStat 0x170B60. LSC_GetNumStm 0x170B80.
 * LSC_SetFlowLimit 0x170BA0. LSC_Destroy 0x170C00.
 * LSC_Start 0x170C20.
 *
 * The object is 0x238 bytes. Thirty-two objects sit at 0xCD0780.
 * Sixteen streams start at +0x38. stm_hndl is +0x28.
 */

#include "types.h"

#include <stddef.h>
#include <string.h>

#define LSC_MAX_STM 16

typedef struct {
    s32 id;
    const char *fname;
    s32 unk8;
    void *dir;
    s32 unk10;
    s32 unk14;
    s32 stat;
    s32 rd_sct;
} LSC_STM;

typedef struct LSC_OBJ {
    s8 used;
    s8 stat;
    s8 unk2;
    s8 lp_flg;
    s8 unk4;
    u8 pad5[3];
    void *sj;
    s32 unkC;
    s32 unk10;
    s32 flow_limit;
    s32 unk18;
    s32 last_stm_index;
    s32 unk20;
    s32 num_stm;
    void *stm_hndl;
    s32 unk2C;
    s32 pad30;
    s32 unk34;
    LSC_STM stm[LSC_MAX_STM];
} LSC_OBJ;

#if defined(__i386__)
_Static_assert(offsetof(LSC_STM, fname) == 4, "fname");
_Static_assert(offsetof(LSC_STM, unk8) == 8, "unk8");
_Static_assert(offsetof(LSC_STM, dir) == 0x0C, "dir");
_Static_assert(offsetof(LSC_STM, unk10) == 0x10, "unk10");
_Static_assert(offsetof(LSC_STM, unk14) == 0x14, "unk14");
_Static_assert(offsetof(LSC_STM, stat) == 0x18, "stm.stat");
_Static_assert(offsetof(LSC_STM, rd_sct) == 0x1C, "rd_sct");
_Static_assert(sizeof(LSC_STM) == 0x20, "LSC_STM");
_Static_assert(offsetof(LSC_OBJ, stat) == 1, "stat");
_Static_assert(offsetof(LSC_OBJ, unk2) == 2, "unk2");
_Static_assert(offsetof(LSC_OBJ, sj) == 8, "sj");
_Static_assert(offsetof(LSC_OBJ, flow_limit) == 0x14, "flow_limit");
_Static_assert(offsetof(LSC_OBJ, unk18) == 0x18, "unk18");
_Static_assert(offsetof(LSC_OBJ, last_stm_index) == 0x1C, "last");
_Static_assert(offsetof(LSC_OBJ, unk20) == 0x20, "unk20");
_Static_assert(offsetof(LSC_OBJ, num_stm) == 0x24, "num_stm");
_Static_assert(offsetof(LSC_OBJ, stm_hndl) == 0x28, "stm_hndl");
_Static_assert(offsetof(LSC_OBJ, unk2C) == 0x2C, "unk2C");
_Static_assert(offsetof(LSC_OBJ, unk34) == 0x34, "unk34");
_Static_assert(offsetof(LSC_OBJ, stm) == 0x38, "stm");
_Static_assert(sizeof(LSC_OBJ) == 0x238, "LSC_OBJ");
#endif

extern void LSC_CallErrFunc(const char *format, ...);
extern void sub_0016DFA0(void *stm);

void LSC_SetStmHndl(LSC_OBJ *lsc, void *stm) {
    lsc->stm_hndl = stm;
}

void LSC_ResetEntry(LSC_OBJ *lsc) {
    if (lsc == NULL) {
        LSC_CallErrFunc("E0003: Illigal parameter lsc=NULL\n");
        return;
    }

    if (lsc->stat == 0) {
        lsc->last_stm_index = 0;
        lsc->unk20 = 0;
        lsc->num_stm = 0;
    }
}

void LSC_Stop(LSC_OBJ *lsc) {
    if (lsc == NULL) {
        LSC_CallErrFunc("E0003: Illigal parameter lsc=NULL\n");
        return;
    }

    if (lsc->stat != 0) {
        lsc->stat = 0;

        if ((lsc->stm_hndl != NULL) && (lsc->unk2 == 1)) {
            sub_0016DFA0(lsc->stm_hndl);
            lsc->unk2 = 0;
        }

        lsc->unk2C = 0;
        LSC_ResetEntry(lsc);
        lsc->unk34 = 0;
    }
}

s32 LSC_GetStat(LSC_OBJ *lsc) {
    if (lsc == NULL) {
        LSC_CallErrFunc("E0003: Illigal parameter lsc=NULL\n");
        return -1;
    }

    return lsc->stat;
}

s32 LSC_GetNumStm(LSC_OBJ *lsc) {
    if (lsc == NULL) {
        LSC_CallErrFunc("E0003: Illigal parameter lsc=NULL\n");
        return -1;
    }

    return lsc->num_stm;
}

void LSC_SetFlowLimit(LSC_OBJ *lsc, s32 min) {
    if (lsc == NULL) {
        LSC_CallErrFunc("E0003: Illigal parameter lsc=NULL\n");
        return;
    }

    if ((min < 0) || (lsc->unk18 < min)) {
        LSC_CallErrFunc("E0010: Illigal parameter min=%d\n", min);
        return;
    }

    lsc->flow_limit = min;
}

void LSC_Destroy(LSC_OBJ *lsc) {
    if (lsc != NULL) {
        LSC_Stop(lsc);
        lsc->used = 0;
        memset(lsc, 0, sizeof(LSC_OBJ));
    }
}

void LSC_Start(LSC_OBJ *lsc) {
    if (lsc == NULL) {
        LSC_CallErrFunc("E0003: Illigal parameter lsc=NULL\n");
        return;
    }

    if (lsc->stat != 0) {
        LSC_Stop(lsc);
    }

    if (lsc->num_stm > 0) {
        lsc->stat = 2;
    } else {
        lsc->stat = 1;
    }
}
