/* ADXB_GetStat 0x172EE0.
 *
 * stat is the s32 at +4.
 */

#include "types.h"

#include <stddef.h>

typedef struct ADXB_OBJ {
    s16 unk0;
    s16 unk2;
    s32 stat;
} ADXB_OBJ;

typedef ADXB_OBJ *ADXB;

#if defined(__i386__)
_Static_assert(offsetof(ADXB_OBJ, stat) == 4, "stat");
#endif

s32 ADXB_GetStat(ADXB adxb) {
    return adxb->stat;
}
