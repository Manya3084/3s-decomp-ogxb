/* Init_ram_control_work, retail sf33rd.xbe 0x96EF8.
 * Search_ramcnt_type 0x9700F, Test_ramcnt_key 0x9703B,
 * Push_ramcnt_key_original_2 0x96F5F, Purge_memory_of_kind_of_key 0x9711B,
 * Set_size_data_ramcnt_key 0x96FBD, Get_size_data_ramcnt_key 0x96FD9,
 * Get_ramcnt_address 0x96FF4.
 * 0x97103 stays unnamed.
 * mmFree is 0xF2211 and purge_texture_group is 0xF002D. Both stay unnamed.
 * Heap unit argument is 16. RCKeyWork is 12 bytes. rckeymin is not written.
 * mmHeapInitialize is 0xF2236 and is not named yet.
 * adr is +0, size is +4, search_type is +8, group_num is +9, type is +0xA,
 * and use is +0xB.
 *
 * rckey_mmobj  0xC7CA20
 * rckey_work   0xC7CA60
 * rckeyque     0xC7CD60
 * rckeyctr     0xC7CDE0
 */

#include "types.h"

#define RCKEY_WORK_MAX 64

typedef struct MEMMAN_OBJ MEMMAN_OBJ;

typedef struct {
    void *adr;
    u32 size;
    u8 search_type;
    u8 group_num;
    u8 type;
    u8 use;
} RCKeyWork;

#if defined(__i386__)
_Static_assert(sizeof(RCKeyWork) == 12, "RCKeyWork");
#endif

extern MEMMAN_OBJ rckey_mmobj;
extern RCKeyWork rckey_work[RCKEY_WORK_MAX];
extern s16 rckeyque[RCKEY_WORK_MAX];
extern s16 rckeyctr;

extern void mmHeapInitialize(MEMMAN_OBJ *mobj, void *adrs, s32 size, s32 unit, const char *name);
extern void sub_000F2211(MEMMAN_OBJ *mobj, void *adr);
extern void sub_000F002D(u8 group);
extern void sub_00097103(s16 key);

void Init_ram_control_work(u8 *adrs, s32 size) {
    s16 i;

    mmHeapInitialize(&rckey_mmobj, adrs, size, 16, "- for Ramcnt -");

    for (i = 0; i < (RCKEY_WORK_MAX - 1); i++) {
        rckeyque[i] = (s16)((RCKEY_WORK_MAX - 1) - i);
    }

    rckeyque[RCKEY_WORK_MAX - 1] = 0;
    rckeyctr = (s16)(RCKEY_WORK_MAX - 1);

    rckey_work[0].adr = 0;
    rckey_work[0].size = 0;
    rckey_work[0].search_type = 0;
    rckey_work[0].group_num = 0;
    rckey_work[0].type = 0;
    rckey_work[0].use = 0;

    for (i = 1; i < RCKEY_WORK_MAX; i++) {
        rckey_work[i] = rckey_work[0];
    }
}

s16 Search_ramcnt_type(u8 kokey) {
    s16 i;

    for (i = 1; i < RCKEY_WORK_MAX; i++) {
        if (rckey_work[i].use != 0 && kokey == rckey_work[i].type) {
            return i;
        }
    }

    return 0;
}

s32 Test_ramcnt_key(s16 key) {
    if (key == 0) {
        return 1;
    }

    if (rckey_work[key].use == 0) {
        return 0;
    }

    if (rckey_work[key].group_num != 0) {
        return 0;
    }

    return 1;
}

void Push_ramcnt_key_original_2(s16 key) {
    RCKeyWork *rwk = &rckey_work[key];

    if (rwk->use == 0) {
        return;
    }

    sub_000F2211(&rckey_mmobj, rwk->adr);
    rwk->type = 0;
    rwk->use = 0;

    if (rwk->group_num != 0) {
        sub_000F002D(rwk->group_num);
    }

    rwk->group_num = 0;
    rckeyque[rckeyctr++] = key;
}

void Purge_memory_of_kind_of_key(u8 kokey) {
    RCKeyWork *rwk;
    s16 i;

    for (i = 0; i < RCKEY_WORK_MAX; i++) {
        rwk = &rckey_work[i];

        if (rwk->use != 0 && rwk->type == kokey) {
            sub_00097103(i);
        }
    }
}

void Set_size_data_ramcnt_key(s16 key, u32 size) {
    if (key <= 0) {
        return;
    }

    rckey_work[key].size = size;
}

u32 Get_size_data_ramcnt_key(s16 key) {
    if (key <= 0) {
        return 0;
    }

    return rckey_work[key].size;
}

void *Get_ramcnt_address(s16 key) {
    if (key <= 0) {
        return 0;
    }

    return rckey_work[key].adr;
}
