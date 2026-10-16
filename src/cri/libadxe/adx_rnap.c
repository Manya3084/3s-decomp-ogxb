/* ADXRNA_SetPlaySw 0x1707E0. ADXRNA_ExecServer 0x170820.
 * ADXRNA_SetNumChan 0x170830. ADXRNA_SetSfreq 0x170840.
 * ADXRNA_SetOutVol 0x170850. ADXRNA_SetOutPan 0x170860.
 * ADXRNA_SetBitPerSmpl 0x170870.
 *
 * PS2 calls the PS2RNA helper and returns. This build tail-jumps to
 * 0x16BD40, 0x16BF50, 0x16B730, 0x16B7D0, 0x16B800, 0x16B840, and
 * 0x16B780. The scanner does not split after those jumps. SetPlaySw
 * sits inside the span that starts at 0x1707C0. ExecServer is its own
 * scanned start.
 */

#include "types.h"

extern void sub_0016BD40(void *rna, s32 sw);
extern void sub_0016B800(void *rna, s32 vol);
extern void sub_0016B840(void *rna, s32 channel, s32 pan);
extern void sub_0016B780(void *rna, s32 bps);
extern void sub_0016BF50(void);
extern void sub_0016B730(void *rna, s32 num_chan);
extern void sub_0016B7D0(void *rna, s32 sfreq);

void ADXRNA_SetPlaySw(void *rna, s32 sw) {
    sub_0016BD40(rna, sw);
}

void ADXRNA_ExecServer(void) {
    sub_0016BF50();
}

void ADXRNA_SetNumChan(void *rna, s32 num_chan) {
    sub_0016B730(rna, num_chan);
}

void ADXRNA_SetSfreq(void *rna, s32 sfreq) {
    sub_0016B7D0(rna, sfreq);
}

void ADXRNA_SetOutVol(void *rna, s32 vol) {
    sub_0016B800(rna, vol);
}

void ADXRNA_SetOutPan(void *rna, s32 channel, s32 pan) {
    sub_0016B840(rna, channel, pan);
}

void ADXRNA_SetBitPerSmpl(void *rna, s32 bps) {
    sub_0016B780(rna, bps);
}
