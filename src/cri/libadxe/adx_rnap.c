/* ADXRNA_SetPlaySw 0x1707E0.
 *
 * PS2 calls PS2RNA_SetPlaySw and returns. This build tail-jumps to
 * 0x16BD40. The scanner does not split after that jump, so this function
 * sits inside the span that starts at 0x1707C0.
 */

#include "types.h"

extern void sub_0016BD40(void *rna, s32 sw);

void ADXRNA_SetPlaySw(void *rna, s32 sw) {
    sub_0016BD40(rna, sw);
}
