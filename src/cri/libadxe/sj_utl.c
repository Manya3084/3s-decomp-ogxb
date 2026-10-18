/* SJ_SplitChunk 0x171E90. */

#include "types.h"

#include <stddef.h>

typedef struct {
    s8 *data;
    s32 len;
} SJCK;

#if defined(__i386__)
_Static_assert(offsetof(SJCK, len) == 4, "SJCK.len");
_Static_assert(sizeof(SJCK) == 8, "SJCK");
#endif

void SJ_SplitChunk(SJCK *ck, s32 nbyte, SJCK *ck1, SJCK *ck2) {
    *ck1 = *ck;
    ck2->len = ck1->len;

    if (ck1->len > nbyte) {
        ck1->len = nbyte;
    }

    ck2->len -= ck1->len;

    if (ck2->len == 0) {
        ck2->data = NULL;
    } else {
        ck2->data = ck1->data + ck1->len;
    }
}
