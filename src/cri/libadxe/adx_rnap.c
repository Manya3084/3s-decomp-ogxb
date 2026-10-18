/* ADXRNA_Init 0x170760. ADXRNA_Finish 0x170770. ADXRNA_Create 0x170790.
 * ADXRNA_SetPlaySw 0x1707E0. ADXRNA_ExecServer 0x170820.
 * ADXRNA_SetNumChan 0x170830. ADXRNA_SetSfreq 0x170840.
 * ADXRNA_SetOutVol 0x170850. ADXRNA_SetOutPan 0x170860.
 * ADXRNA_SetBitPerSmpl 0x170870. ADXRNA_GetNumData 0x170800.
 * ADXRNA_SetTransSw 0x1707D0.
 *
 * PS2 calls the PS2RNA helper and returns. This build tail-jumps to
 * 0x16B000, 0x16C1D0, 0x16BD40, 0x16BF50, mwRnaSetNumChan, 0x16B7D0, 0x16B800,
 * 0x16B840, 0x16B780, 0x16B710, 0x16BC60, and mwRnaCreate. The scanner
 * does not split after those jumps. Finish and Create are interior:
 * Init's padding is int3, and the scanner still does not split after
 * a tail jump. ADXT_Create is the only caller of Create. It passes
 * sjo and the channel count, and stores the result at +0xC.
 * SetPlaySw, GetNumData, and SetTransSw sit inside the span that
 * starts at 0x1707C0. That span runs through the ret at 0x170815.
 * ExecServer is its own scanned start. adxt_stat_prep is the matched
 * caller of GetNumData. The unnamed body at 0x171970 also calls it.
 * StopWithoutLsc calls SetTransSw with 0, and decinfo calls it with 1.
 * Playing's drained path also calls it with 0.
 */

#include "types.h"

extern void mwRnaInit(void);
extern void mwRnaFinish(void);
extern void mwRnaSetPlaySw(void *rna, s32 sw);
extern void mwRnaSetOutVol(void *rna, s32 vol);
extern void mwRnaSetOutPan(void *rna, s32 channel, s32 pan);
extern void mwRnaSetBitPerSmpl(void *rna, s32 bps);
extern void mwRnaExecServer(void);
extern void mwRnaSetNumChan(void *rna, s32 num_chan);
extern void mwRnaSetSfreq(void *rna, s32 sfreq);
extern s32 mwRnaGetNumData(void *rna);
extern void mwRnaSetTransSw(void *rna, s32 sw);
extern void *mwRnaCreate(void *sjo, s32 maxnch);

void ADXRNA_Init(void) {
    mwRnaInit();
}

void ADXRNA_Finish(void) {
    mwRnaFinish();
}

void *ADXRNA_Create(void *sjo, s32 maxnch) {
    return mwRnaCreate(sjo, maxnch);
}

void ADXRNA_SetPlaySw(void *rna, s32 sw) {
    mwRnaSetPlaySw(rna, sw);
}

s32 ADXRNA_GetNumData(void *rna) {
    return mwRnaGetNumData(rna);
}

void ADXRNA_SetTransSw(void *rna, s32 sw) {
    mwRnaSetTransSw(rna, sw);
}

void ADXRNA_ExecServer(void) {
    mwRnaExecServer();
}

void ADXRNA_SetNumChan(void *rna, s32 num_chan) {
    mwRnaSetNumChan(rna, num_chan);
}

void ADXRNA_SetSfreq(void *rna, s32 sfreq) {
    mwRnaSetSfreq(rna, sfreq);
}

void ADXRNA_SetOutVol(void *rna, s32 vol) {
    mwRnaSetOutVol(rna, vol);
}

void ADXRNA_SetOutPan(void *rna, s32 channel, s32 pan) {
    mwRnaSetOutPan(rna, channel, pan);
}

void ADXRNA_SetBitPerSmpl(void *rna, s32 bps) {
    mwRnaSetBitPerSmpl(rna, bps);
}
