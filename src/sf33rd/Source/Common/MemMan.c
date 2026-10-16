/* mmSystemInitialize, retail sf33rd.xbe 0xF2134.
 * mmRoundUp 0xF213C. mmRoundOff 0xF214E. mmAllocSub 0xF215A.
 * mmFree 0xF2211.
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

MEMMAN_CELL *mmAllocSub(MEMMAN_OBJ *mmobj, s32 size, s32 flag) {
    MEMMAN_CELL *myself;
    MEMMAN_CELL *next;
    MEMMAN_CELL *cell;
    s32 sizeTrue;
    s32 gap;
    s32 gapMin;

    sizeTrue = mmobj->ownUnit + (s32)mmRoundUp((u32)mmobj->ownUnit, (u32)size);
    gapMin = 0x7FFFFFFF;
    cell = 0;

    if (flag != 1) {
        myself = mmobj->cell_1st;

        do {
            next = myself->next;
            gap = (s32)((u8 *)next - (u8 *)myself) - myself->size;

            if (gap >= sizeTrue) {
                if (gap == sizeTrue) {
                    cell = myself;
                    break;
                }

                if ((gap - sizeTrue) < gapMin) {
                    gapMin = gap - sizeTrue;
                    cell = myself;
                }
            }

            myself = next;
        } while (myself->next != 0);

        if (cell == 0) {
            return 0;
        }

        myself = (MEMMAN_CELL *)((u8 *)cell + cell->size);
        myself->prev = cell;
        myself->next = cell->next;
        myself->size = sizeTrue;
        cell->next->prev = myself;
        cell->next = myself;
        return myself;
    }

    myself = mmobj->cell_fin;

    do {
        next = myself->prev;
        gap = (s32)((u8 *)myself - (u8 *)next) - next->size;

        if (gap >= sizeTrue) {
            if (gap == sizeTrue) {
                cell = myself;
                break;
            }

            if ((gap - sizeTrue) < gapMin) {
                gapMin = gap - sizeTrue;
                cell = myself;
            }
        }

        myself = next;
    } while (myself->prev != 0);

    if (cell == 0) {
        return 0;
    }

    myself = (MEMMAN_CELL *)((u8 *)cell - sizeTrue);
    myself->prev = cell->prev;
    myself->next = cell;
    myself->size = sizeTrue;
    cell->prev->next = myself;
    cell->prev = myself;
    return myself;
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
