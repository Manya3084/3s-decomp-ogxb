/* mwSndStop 0x16C380.
 *
 * A failed stop reports E1229 and returns. Otherwise this waits while
 * status bit 0 is set. The limit is the 64-bit value from 0x123331
 * divided by 0x5DC. The scanner start at 0x16C3F0 is inside the wait.
 * 0x199ED8, 0x199F34, 0x123320, 0x123331, 0x1786E0, and 0x1725A0 stay
 * unnamed. The only caller is 0x16C783.
 */

#include "types.h"

typedef struct {
    u32 lo;
    u32 hi;
} MwU64;

extern s32 sub_00199ED8(void *dsb);
extern void sub_00199F34(void *dsb, u32 *stat);
extern void sub_00123320(MwU64 *out);
extern void sub_00123331(MwU64 *out);
extern unsigned long long sub_001786E0(u32 lo, u32 hi, u32 dlo, u32 dhi);
extern void sub_001725A0(const char *msg);

void mwSndStop(void *dsb) {
    MwU64 start;
    MwU64 now;
    MwU64 scale;
    unsigned long long limit;
    long long elapsed;
    long long start_ticks;
    long long now_ticks;
    u32 stat;

    if (sub_00199ED8(dsb) != 0) {
        sub_001725A0("E1229:IDirectSoundBuffer_Stop return error in mwSndStop");
        return;
    }

    sub_00123320(&start);
    sub_00199F34(dsb, &stat);
    if ((stat & 1) == 0) {
        return;
    }

    do {
        sub_00123331(&scale);
        limit = sub_001786E0(scale.lo, scale.hi, 0x5DC, 0);
        sub_00123320(&now);
        now_ticks = (long long)(((unsigned long long)now.hi << 32) | now.lo);
        start_ticks = (long long)(((unsigned long long)start.hi << 32) | start.lo);
        elapsed = now_ticks - start_ticks;
        if (elapsed > (long long)limit) {
            break;
        }
        if (now_ticks <= start_ticks) {
            break;
        }
        sub_00199F34(dsb, &stat);
    } while ((stat & 1) != 0);
}
