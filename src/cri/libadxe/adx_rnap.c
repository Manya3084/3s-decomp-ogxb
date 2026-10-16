/* ADXRNA_SetPlaySw 0x1707E0. ADXRNA_SetOutVol 0x170850.
 * ADXRNA_SetOutPan 0x170860.
 *
 * PS2 calls the PS2RNA helper and returns. This build tail-jumps to
 * 0x16BD40, 0x16B800, and 0x16B840. The scanner does not split after
 * those jumps. SetPlaySw sits inside the span that starts at 0x1707C0.
 */

#include "types.h"

extern void sub_0016BD40(void *rna, s32 sw);
extern void sub_0016B800(void *rna, s32 vol);
extern void sub_0016B840(void *rna, s32 channel, s32 pan);

void ADXRNA_SetPlaySw(void *rna, s32 sw) {
    sub_0016BD40(rna, sw);
}

void ADXRNA_SetOutVol(void *rna, s32 vol) {
    sub_0016B800(rna, vol);
}

void ADXRNA_SetOutPan(void *rna, s32 channel, s32 pan) {
    sub_0016B840(rna, channel, pan);
}
