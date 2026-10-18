/* lsc_Alloc 0x1708A0. LSC_Create 0x1708E0.
 * LSC_SetStmHndl 0x1709B0. LSC_EntryFileRange 0x1709C0.
 * LSC_ResetEntry 0x170AB0.
 * LSC_Stop 0x170AE0. LSC_ExecServer 0x170B30.
 * LSC_GetStat 0x170B60. LSC_GetNumStm 0x170B80.
 * LSC_SetFlowLimit 0x170BA0. LSC_CallStatFunc 0x170BE0.
 * LSC_Destroy 0x170C00.
 * LSC_Start 0x170C20.
 *
 * The object is 0x238 bytes. Thirty-two objects sit at 0xCD0780.
 * Sixteen streams start at +0x38. stm_hndl is +0x28.
 * lsc_stat_func is 0x7A6084, lsc_stat_obj1 is 0x7A6088, and lsc_stat_obj2
 * is 0x7A608C.
 */

#include "types.h"

#include <stddef.h>
#include <string.h>

#define LSC_MAX_OBJ 32
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

typedef struct SJ_OBJ SJ_OBJ;
typedef SJ_OBJ *SJ;

typedef struct {
    void *gap[9];
    s32 (*GetNumData)(SJ sj, s32 id);
} SJ_VTBL;

struct SJ_OBJ {
    SJ_VTBL *vtbl;
};

#define SJ_GetNumData(sj, id) ((sj)->vtbl->GetNumData)(sj, id)

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
_Static_assert(offsetof(SJ_VTBL, GetNumData) == 0x24, "GetNumData");
#endif

extern void LSC_CallErrFunc(const char *format, ...);
extern void ADXSTM_Stop(void *stm);
extern void lsc_ExecHndl(LSC_OBJ *lsc);
extern void LSC_LockCrs(s32 *unused);
extern void LSC_UnlockCrs(s32 *unused);
extern LSC_OBJ lsc_obj[LSC_MAX_OBJ]; /* 0xCD0780 */

LSC_OBJ *lsc_Alloc(void) {
    s32 i;

    for (i = 0; i < LSC_MAX_OBJ; i++) {
        if (lsc_obj[i].used == 0) {
            return &lsc_obj[i];
        }
    }

    return NULL;
}

LSC_OBJ *LSC_Create(SJ sj) {
    LSC_OBJ *lsc;
    s32 lock;
    s32 i;

    if (sj == NULL) {
        LSC_CallErrFunc("E0001: Illigal parameter=sj (LSC_Create)\n");
        return NULL;
    }

    LSC_LockCrs(&lock);
    lsc = lsc_Alloc();

    if (lsc == NULL) {
        LSC_CallErrFunc("E0002: Not enough instance (LSC_Create)\n");
    } else {
        lsc->sj = sj;
        lsc->stat = 0;
        lsc->unk18 = SJ_GetNumData(sj, 0) + SJ_GetNumData(sj, 1);
        lsc->flow_limit = (lsc->unk18 * 8) / 10;

        for (i = 0; i < LSC_MAX_STM; i++) {
            lsc->stm[i].stat = 0;
        }

        lsc->used = 1;
    }

    LSC_UnlockCrs(&lock);
    return lsc;
}

void LSC_SetStmHndl(LSC_OBJ *lsc, void *stm) {
    lsc->stm_hndl = stm;
}

s32 LSC_EntryFileRange(LSC_OBJ *lsc, const char *fname, void *dir, s32 ofst, s32 fnsct) {
    LSC_STM *stm;
    s32 id;
    s32 prev;
    s32 length;
    s32 i;

    if (lsc == NULL) {
        LSC_CallErrFunc("E0003: Illigal parameter lsc=NULL\n");
        return -1;
    }

    if (lsc->num_stm >= LSC_MAX_STM) {
        return -1;
    }

    if (fname == NULL) {
        LSC_CallErrFunc("E0011: Illigal parameter fname=%s\n", fname);
        return -1;
    }

    prev = (lsc->last_stm_index + LSC_MAX_STM - 1) % LSC_MAX_STM;
    stm = &lsc->stm[lsc->last_stm_index];
    stm->fname = fname;
    id = (lsc->stm[prev].id != 0x7FFFFFFF) ? (lsc->stm[prev].id + 1) : 0;
    stm->id = id;
    length = (s32)strlen(fname);
    stm->unk8 = 0;

    for (i = 0; i < length; i++) {
        stm->unk8 += (u8)fname[i];
    }

    stm->unk10 = ofst;
    stm->unk14 = fnsct;
    stm->dir = dir;
    stm->stat = 0;
    stm->rd_sct = 0;
    lsc->num_stm += 1;
    lsc->last_stm_index += 1;
    lsc->last_stm_index %= LSC_MAX_STM;

    if (lsc->stat == 1) {
        lsc->stat = 2;
    }

    return id;
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
            ADXSTM_Stop(lsc->stm_hndl);
            lsc->unk2 = 0;
        }

        lsc->unk2C = 0;
        LSC_ResetEntry(lsc);
        lsc->unk34 = 0;
    }
}

void LSC_ExecServer(void) {
    s32 i;

    for (i = 0; i < LSC_MAX_OBJ; i++) {
        if (lsc_obj[i].used == 1) {
            lsc_ExecHndl(&lsc_obj[i]);
        }
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

    if ((min < 0) || (min > lsc->unk18)) {
        LSC_CallErrFunc("E0010: Illigal parameter min=%d\n", min);
        return;
    }

    lsc->flow_limit = min;
}

extern void (*lsc_stat_func)(void *obj1, void *obj2); /* 0x7A6084 */
extern void *lsc_stat_obj1; /* 0x7A6088 */
extern void *lsc_stat_obj2; /* 0x7A608C */

void LSC_CallStatFunc(void) {
    if (lsc_stat_func != NULL) {
        lsc_stat_func(lsc_stat_obj1, lsc_stat_obj2);
    }
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
