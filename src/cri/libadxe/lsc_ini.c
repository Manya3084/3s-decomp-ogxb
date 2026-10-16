/* LSC_Init 0x1723C0.
 *
 * The build string is "\nLSC/XBOX Ver.2.15 Build:Feb 13 2004 21:08:01\n".
 * Thirty-two objects of 0x238 bytes sit at 0xCD0780. The counter is
 * 0x7A60A0. The empty lsc_EntrySvrInt is omitted.
 */

#include "types.h"

#include <stddef.h>
#include <string.h>

#define LSC_MAX_OBJ 32

typedef struct {
    s8 used;
    u8 gap[0x237];
} LSC_OBJ;

#if defined(__i386__)
_Static_assert(sizeof(LSC_OBJ) == 0x238, "LSC_OBJ");
_Static_assert(offsetof(LSC_OBJ, used) == 0, "used");
#endif

/* "\nLSC/XBOX Ver.2.15 Build:Feb 13 2004 21:08:01\n" */
extern char *volatile lsc_build; /* 0x2E1584 */
extern s32 lsc_init_cnt; /* 0x7A60A0 */
extern LSC_OBJ lsc_obj[LSC_MAX_OBJ]; /* 0xCD0780 */
extern void LSC_LockCrs(s32 *unused);
extern void LSC_UnlockCrs(s32 *unused);
extern void LSC_EntryErrFunc(void (*func)(void *obj, char *msg), void *obj);

void LSC_Init(void) {
    s32 lock;

    (void)lsc_build;

    LSC_LockCrs(&lock);

    if (lsc_init_cnt == 0) {
        memset(lsc_obj, 0, sizeof(lsc_obj));
        LSC_EntryErrFunc(NULL, NULL);
    }

    lsc_init_cnt += 1;
    LSC_UnlockCrs(&lock);
}
