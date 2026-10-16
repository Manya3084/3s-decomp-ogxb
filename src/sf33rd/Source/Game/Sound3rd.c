/* Go_BGM, retail sf33rd.xbe 0x9C646, size 0x29.
 * ptix is 0x7F and bank is 3. 0x9BD31 stays unnamed.
 */

#include "types.h"

typedef struct {
    s16 ptix;
    s16 bank;
    s16 port;
    s16 code;
} SoundPatchConfig;

#if defined(__i386__)
_Static_assert(sizeof(SoundPatchConfig) == 8, "SoundPatchConfig");
#endif

extern void sub_0009BD31(SoundPatchConfig *rmc, s16 pan);

void Go_BGM(void) {
    SoundPatchConfig rmcode;

    rmcode.ptix = 0x7F;
    rmcode.bank = 3;
    rmcode.port = 0;
    rmcode.code = 0;
    sub_0009BD31(&rmcode, 0);
}
