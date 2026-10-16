/* AIXP_GetAdxt 0x166B20.
 *
 * The error string names trno. The ADXT table is the pointer array at
 * +0xC. trno > 0x20 reports E2003052112 and returns 0, so index 32 is
 * accepted. A null handle reports E2003050210 and returns 0. The error
 * call is the tail jmp at 0x16EB40, which jumps to ADXERR_CallErrFunc1.
 * It is a scanned start.
 */

#include "types.h"

#include <stddef.h>

typedef struct {
    s8 used;
    s8 stat;
    s8 maxnch;
    s8 maxntr;
    void *sjd;
    void *stm;
    void *adxt[32];
} AIX_PLY;

#if defined(__i386__)
_Static_assert(offsetof(AIX_PLY, stat) == 1, "stat");
_Static_assert(offsetof(AIX_PLY, adxt) == 0xC, "adxt");
#endif

extern void ADXERR_CallErrFunc1(const char *msg);

void *AIXP_GetAdxt(AIX_PLY *aixp, s32 trno) {
    if (aixp == 0) {
        ADXERR_CallErrFunc1("E2003050210 : NULL pointer is specified.");
        return 0;
    }

    if (trno > 0x20) {
        ADXERR_CallErrFunc1("E2003052112 : The parameter 'trno' is out of range.");
        return 0;
    }

    return aixp->adxt[trno];
}
