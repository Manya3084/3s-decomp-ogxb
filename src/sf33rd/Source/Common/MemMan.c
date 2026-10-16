/* mmSystemInitialize, retail sf33rd.xbe 0xF2134.
 * mmRoundUp 0xF213C. mmRoundOff 0xF214E. mmFree 0xF2211.
 * mmInitialNumber is 0x7968AC. The store is an and with zero.
 * A cell is 12 bytes. The heap object is 0x2C bytes.
 * ownUnit is +0xC, remainder is +0x10, prev is +0, next is +4, and size is +8.
 */

#include "types.h"

typedef struct MEMMAN_CELL {
    struct MEMMAN_CELL *prev;
    struct MEMMAN_CELL *next;
    s32 size;
} MEMMAN_CELL;

typedef struct MEMMAN_OBJ {
    u8 *memHead;
    s32 memSize;
    u32 ownNumber;
    s32 ownUnit;
    s32 remainder;
    s32 remainderMin;
    MEMMAN_CELL *cell_1st;
    MEMMAN_CELL *cell_fin;
    u8 *oriHead;
    s32 oriSize;
    s32 debIndex;
} MEMMAN_OBJ;

#if defined(__i386__)
_Static_assert(sizeof(MEMMAN_CELL) == 12, "MEMMAN_CELL");
_Static_assert(sizeof(MEMMAN_OBJ) == 0x2C, "MEMMAN_OBJ");
#endif

extern u32 mmInitialNumber;

void mmSystemInitialize(void) {
    mmInitialNumber = 0;
}

u32 mmRoundUp(u32 unit, u32 num) {
    return ~(unit - 1) & (num + unit - 1);
}

u32 mmRoundOff(u32 unit, u32 num) {
    return num & ~(unit - 1);
}

void mmFree(MEMMAN_OBJ *mmobj, void *adrs) {
    MEMMAN_CELL *cell;

    if (adrs == 0) {
        return;
    }

    cell = (MEMMAN_CELL *)((u8 *)adrs - mmobj->ownUnit);
    mmobj->remainder += cell->size;
    cell->prev->next = cell->next;
    cell->next->prev = cell->prev;
}
