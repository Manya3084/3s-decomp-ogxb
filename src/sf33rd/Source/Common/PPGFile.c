/* ppg_Initialize, retail sf33rd.xbe 0xF22FA.
 * ppgMallocF 0xF2320. ppgMallocR 0xF2334. ppgFree 0xF2348.
 * ppgSetupCurrentDataList 0xF2363.
 * ppg_w is 0x7A8080. cur is +0, hanPal is +4, and the heap object is +8.
 * The unit is 16. A null address stops. mmHeapInitialize ignores the name.
 */

#include "types.h"

#include <stddef.h>

typedef struct {
    u8 *memHead;
    s32 memSize;
    u32 ownNumber;
    s32 ownUnit;
    s32 remainder;
    s32 remainderMin;
    void *cell_1st;
    void *cell_fin;
    u8 *oriHead;
    s32 oriSize;
    s32 debIndex;
} MEMMAN_OBJ;

typedef struct {
    void *tex;
    void *pal;
} PPGDataList;

typedef struct {
    PPGDataList *cur;
    u16 hanPal;
    u16 hanTex;
    MEMMAN_OBJ mm;
} PPG_W;

#if defined(__i386__)
_Static_assert(sizeof(MEMMAN_OBJ) == 0x2C, "MEMMAN_OBJ");
_Static_assert(offsetof(PPG_W, hanPal) == 4, "hanPal");
_Static_assert(offsetof(PPG_W, mm) == 8, "mm");
#endif

extern PPG_W ppg_w;

extern void mmHeapInitialize(MEMMAN_OBJ *mobj, void *adrs, s32 size, s32 unit, const char *name);
extern void *mmAlloc(MEMMAN_OBJ *mobj, s32 size, s32 flag);
extern void mmFree(MEMMAN_OBJ *mobj, void *adrs);

void ppg_Initialize(void *lcmAdrs, s32 lcmSize) {
    if (lcmAdrs == 0) {
        for (;;) {
        }
    }

    mmHeapInitialize(&ppg_w.mm, lcmAdrs, lcmSize, 16, "- for PPG -");
}

void *ppgMallocF(s32 size) {
    return mmAlloc(&ppg_w.mm, size, 0);
}

void *ppgMallocR(s32 size) {
    return mmAlloc(&ppg_w.mm, size, 1);
}

void ppgFree(void *adrs) {
    mmFree(&ppg_w.mm, adrs);
}

void ppgSetupCurrentDataList(PPGDataList *dlist) {
    ppg_w.cur = dlist;
}
