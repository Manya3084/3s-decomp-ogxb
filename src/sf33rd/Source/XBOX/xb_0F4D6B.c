/* xb_0F4D6B.c: Xbox-only code from the run of Xbox-only functions at 0xF4E40, which no PS2 file covers.
 * Capcom's source is lost. The C++ methods are written as C,
 * XB_FASTCALL (__fastcall) with this first (analysis-ps2map/xbgen.py wrote
 * these from their shapes). The names are made up (xb_). */

#include "types.h"

void XB_STDCALL IXACTEngine_CreateSoundBank(s32 a0, s32 a1, s32 a2, s32 a3);
void XB_STDCALL IXACTEngine_CreateSoundSource(s32 a0, s32 a1, s32 a2);
void XB_STDCALL IXACTEngine_GetNotification(s32 a0, s32 a1, s32 a2);
void XB_STDCALL IXACTEngine_RegisterWaveBank(s32 a0, s32 a1, s32 a2, s32 a3);
void XB_STDCALL IXACTEngine_SetMasterVolume(s32 a0, s32 a1, s32 a2);
void XB_STDCALL IXACTEngine_UnRegisterWaveBank(s32 a0, s32 a1);
void XB_STDCALL IXACTSoundBank_Release(s32 a0);
void XB_STDCALL IXACTSoundBank_Stop(s32 a0, s32 a1, s32 a2, s32 a3);

void XB_STDCALL xb_CreateSoundSource(s32 a0, s32 a1, s32 a2) {
    IXACTEngine_CreateSoundSource(a0, a1, a2);
}

void XB_STDCALL xb_CreateSoundBank(s32 a0, s32 a1, s32 a2, s32 a3) {
    IXACTEngine_CreateSoundBank(a0, a1, a2, a3);
}

void XB_STDCALL xb_RegisterWaveBank(s32 a0, s32 a1, s32 a2, s32 a3) {
    IXACTEngine_RegisterWaveBank(a0, a1, a2, a3);
}

void XB_STDCALL xb_UnRegisterWaveBank(s32 a0, s32 a1) {
    IXACTEngine_UnRegisterWaveBank(a0, a1);
}

void XB_STDCALL mlSysSetBankVolume(s32 a0, s32 a1, s32 a2) {
    IXACTEngine_SetMasterVolume(a0, a1, a2);
}

void XB_STDCALL xb_GetNotification(s32 a0, s32 a1, s32 a2) {
    IXACTEngine_GetNotification(a0, a1, a2);
}

void XB_STDCALL xb_XactCall_1B7FB7(s32 a0) {
    IXACTSoundBank_Release(a0);
}

void XB_STDCALL xb_XactCall_1B8048(s32 a0, s32 a1, s32 a2, s32 a3) {
    IXACTSoundBank_Stop(a0, a1, a2, a3);
}
