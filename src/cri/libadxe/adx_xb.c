/* adx_xb.c: the Xbox glue after mf_ci.c (0x16AFA0 to 0x16AFF5): per-track
 * DirectSound access for AIX playback, and the ADX for Xbox version string.
 * An ADXT's ADXRNA (+0xC) holds the mwsnd voice at +0x50, whose
 * DirectSound buffer is at +8. */

#include "types.h"

extern void xb_mwsnd_SetMixBins(void *snd, void *bins);
extern s32 XB_STDCALL IDirectSoundBuffer_SetMixBinVolumes_8(void *dsb, void *vols);
/* D_002E0650 is 0x2E0650. */
char D_002E0650[] = "\nADXXB/XBOX Ver.1.58 Build:Feb 13 2004 21:08:05\n";

/* xb_aixp_GetTrackDsb 0x16AFA0.
 *
 * Static (config/sf33rd/static.txt): the ADXT comes in eax. */

static void *xb_aixp_GetTrackDsb(u8 *adxt) {
    return *(void **)(*(u8 **)(*(u8 **)(adxt + 0xC) + 0x50) + 8);
}

/* xb_aixp_SetTrackSpeakerVol 0x16AFB0. */

void xb_aixp_SetTrackSpeakerVol(u8 *adxt, void *bins) {
    if (adxt != 0) {
        xb_mwsnd_SetMixBins(*(void **)(*(u8 **)(adxt + 0xC) + 0x50), bins);
    }
}

/* xb_aixp_SetTrackMixBinVolumes 0x16AFD0. */

void xb_aixp_SetTrackMixBinVolumes(u8 *adxt, void *vols) {
    if (adxt != 0) {
        IDirectSoundBuffer_SetMixBinVolumes_8(xb_aixp_GetTrackDsb(adxt), vols);
    }
}

/* xb_adxxb_GetVersionStr 0x16AFF0. */

char *xb_adxxb_GetVersionStr(void) {
    return D_002E0650;
}
