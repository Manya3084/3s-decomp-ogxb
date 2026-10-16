/* SJUNI_Init 0x171F50. SJUNI_Finish 0x171F70.
 * SJUNI_Destroy 0x171F90.
 *
 * Sixty-four objects of 0x30 bytes sit at 0xCD4E80, the exclusive end of
 * the LSC table. The counter is 0x7A609C. A zero count clears 0x300 dwords.
 * Finish is interior: Init ends on a bare ret, so the scanner does not
 * split. Finish decrements the counter and clears the same table at zero.
 * Destroy clears one object as 0xC dwords, then stores used at +4.
 * It does not take the stream lock. The locked clear at 0x16FA10 is
 * a different body.
 */

#include "types.h"

#include <stddef.h>
#include <string.h>

#define SJUNI_MAX_OBJ 64

typedef struct {
    void *vtbl;
    s8 used;
    s8 mode;
    s8 pad[2];
    void *uuid;
    void *work;
    s32 chunk_count;
    void *chain_pool;
    void *unk18[4];
    void (*err_func)(void *obj, s32 ecode);
    void *err_obj;
} SJUNI_OBJ;

#if defined(__i386__)
_Static_assert(sizeof(SJUNI_OBJ) == 0x30, "SJUNI_OBJ");
#endif

extern s32 sjuni_init_cnt;
extern SJUNI_OBJ sjuni_obj[SJUNI_MAX_OBJ];

void SJUNI_Init(void) {
    if (sjuni_init_cnt == 0) {
        memset(sjuni_obj, 0, sizeof(sjuni_obj));
    }

    sjuni_init_cnt += 1;
}

void SJUNI_Finish(void) {
    if (--sjuni_init_cnt == 0) {
        memset(sjuni_obj, 0, sizeof(sjuni_obj));
    }
}

void SJUNI_Destroy(SJUNI_OBJ *sjuni) {
    if (sjuni != 0) {
        memset(sjuni, 0, sizeof(SJUNI_OBJ));
        sjuni->used = 0;
    }
}
