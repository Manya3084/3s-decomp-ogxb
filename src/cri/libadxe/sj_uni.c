/* SJUNI_Init 0x171F50.
 *
 * Sixty-four objects of 0x30 bytes sit at 0xCD4E80, the exclusive end of
 * the LSC table. The counter is 0x7A609C. A zero count clears 0x300 dwords.
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
