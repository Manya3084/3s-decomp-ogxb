/* ADXRNA_Init 0x170760. ADXRNA_Finish 0x170770.
 * ADXRNA_SetPlaySw 0x1707E0. ADXRNA_ExecServer 0x170820.
 * ADXRNA_SetNumChan 0x170830. ADXRNA_SetSfreq 0x170840.
 * ADXRNA_SetOutVol 0x170850. ADXRNA_SetOutPan 0x170860.
 * ADXRNA_SetBitPerSmpl 0x170870. ADXRNA_GetNumData 0x170800.
 *
 * PS2 calls the PS2RNA helper and returns. This build tail-jumps to
 * 0x16B000, 0x16C1D0, 0x16BD40, 0x16BF50, 0x16B730, 0x16B7D0, 0x16B800,
 * 0x16B840, 0x16B780, and 0x16B710. The scanner does not split after
 * those jumps. Finish is interior: Init's padding is int3, and the
 * scanner still does not split after a tail jump. SetPlaySw and
 * GetNumData sit inside the span that starts at 0x1707C0. That span
 * runs through the ret at 0x170815. ExecServer is its own scanned
 * start. adxt_stat_prep is the matched caller of GetNumData. The
 * unnamed body at 0x171970 also calls it.
 */

#include "types.h"

extern void sub_0016B000(void);
extern void sub_0016C1D0(void);
extern void sub_0016BD40(void *rna, s32 sw);
extern void sub_0016B800(void *rna, s32 vol);
extern void sub_0016B840(void *rna, s32 channel, s32 pan);
extern void sub_0016B780(void *rna, s32 bps);
extern void sub_0016BF50(void);
extern void sub_0016B730(void *rna, s32 num_chan);
extern void sub_0016B7D0(void *rna, s32 sfreq);
extern s32 sub_0016B710(void *rna);

void ADXRNA_Init(void) {
    sub_0016B000();
}

void ADXRNA_Finish(void) {
    sub_0016C1D0();
}

void ADXRNA_SetPlaySw(void *rna, s32 sw) {
    sub_0016BD40(rna, sw);
}

s32 ADXRNA_GetNumData(void *rna) {
    return sub_0016B710(rna);
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
