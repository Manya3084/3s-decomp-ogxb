/* xb_0F50C9.c: Xbox-only code from 0xF50C9. xb_PurgeListEntry matches only apart from
 * the functions around it, so a file of Capcom's starts here.
 * Capcom's source is lost. Its C++ methods are written as C,
 * XB_FASTCALL (__fastcall) with this first. Each body was checked
 * against retail by analysis-ps2map/xbgen.py. The xb_ names are
 * made up. */

#include "types.h"
#include <string.h>

extern s32 D_007A7CF0[];
extern u8 D_00797BA8[];
s32 xb_LiveWork_Get2334(void);
void xb_StopAllSeSlots(void);
void xb_StopSeById(s16 id);
void XB_STDCALL xb_UnRegisterWaveBank(s32 engine, s32 bank);
s32 XB_STDCALL xb_XactCall_1B7FB7(s32 a);

void xb_PurgeListEntry(u8 id) {
    s32* e;

    D_007A7CF0[id] = -1;
    e = (s32*)(D_00797BA8 + id * 24);

    if (e[1] == 1) {
        if (xb_LiveWork_Get2334()) {
            xb_StopAllSeSlots();
        } else {
            xb_StopSeById(id);
        }

        if (e[5]) {
            xb_UnRegisterWaveBank(*(s32*)D_00797BA8, e[6]);
            e[6] = 0;
            e[5] = 0;
            ((u8*)e)[9] = 0xFF;
        }
        xb_XactCall_1B7FB7(e[4]);
        e[4] = 0;
        e[3] = 0;
        e[1] = 0;
    }
}

/* The 48 XACT voices (D_00797128) and the three sound bank slots
 * (D_00797BAC, after the engine pointer D_00797BA8). A voice holds the
 * request that started it, its cue, bank and sound source, and the
 * source's mix bin volumes (two bins, set through 0x1B8084). */

typedef struct {
    s32 state;
    u16 slot;
    u16 cue_idx;
    u8 grp;
    u8 prio;
    u8 padA[0xA];
    s32 cue;
    s32 bank;
    s32 source;
    s32 nbins;
    s32* bins;
    s32 bin0;
    s32 vol0;
    s32 bin1;
    s32 vol1;
} XB_VOICE;

typedef struct {
    s32 loaded;
    u8 unk4;
    u8 id;
    u8 unk6[2];
    u8* data;
    s32 sbank;
    u8* wbdata;
    s32 wbank;
} XB_SNDBANKSLOT;

typedef struct {
    u16 slot;
    u16 cue_idx;
    u8 grp;
    u8 prio;
    u8 e;
    u8 pad7;
    s32 pan;
    u16 g;
    u16 padE;
} XB_TSBREQ;

extern XB_VOICE D_00797128[48];
extern XB_SNDBANKSLOT D_00797BAC[3];
extern s32 D_00797100;
extern XB_TSBREQ D_00797BF8[0x30];
extern u32 D_00797EF8;
extern s32 D_003F3300[65];
extern s32 D_003F3408[65];
extern u8* D_0032FD80[];
extern s32 D_0032FDD8[];
s32 xb_LoadSoundBanks(u8 idx);
s32 xb_FindLoadedBank(u8 id);
void xb_LoadPanTables(void);
void xb_LoadSoundPack(void);
void mlSysSetMasterVolume(s32 vol);
s32 XB_STDCALL XACTEngineCreate(void* params, s32* engine);
s32 XB_STDCALL xb_RegisterWaveBank(s32 engine, void* data, s32 size, s32* out);
s32 XB_STDCALL xb_CreateSoundBank(s32 engine, void* data, s32 size, s32* out);
s32 XB_STDCALL xb_CreateSoundSource(s32 engine, s32 flags, s32* out);
s32 XB_STDCALL IXACTSoundSource__SetMixBins(s32 source, void* bins);
s32 XB_STDCALL IXACTSoundBank__Stop(s32 bank, s32 idx, s32 flags, s32 cue);
s32 XB_STDCALL IXACTSoundSource__StopSoundCues(s32 source);
s32 XB_STDCALL xb_GetNotification(s32 engine, void* desc, void* out);
s32 xb_SeGroupFree(u8 grp, u8 prio);
s32 XB_STDCALL IXACTSoundSource__SetMixBinVolumes(s32 source, void* bins);
s32 XB_STDCALL IXACTSoundBank__Prepare(s32 bank, u16 cue_idx, s32 flags, s32* out);
s32 xb_StopSeGroup(u8 grp);
s32 XB_STDCALL IXACTSoundBank__Play(s32 bank, s32 idx, s32 source, s32 flags, s32* cue);
s32 XB_STDCALL IXACTEngine__RegisterNotification(s32 engine, void* desc);

/* xb_StartSoundEntry 0xF5209.
 *
 * Starts cue cue_idx of the bank in slot on a free voice, unless the
 * group already plays something of higher priority. In stereo mode
 * (D_00797100 clear) pan -32..32 picks the left and right volumes from
 * the pan tables; 0x100 leaves the source's volumes alone. The voice
 * registers for the cue's end notification. Returns 0 when no voice is
 * free or XACT fails (the request stays queued), 1 otherwise. */

s32 xb_StartSoundEntry(u16 slot, u16 cue_idx, u8 grp, u8 prio, u8 e, s32 pan, u16 g) {
    XB_SNDBANKSLOT* bank = (XB_SNDBANKSLOT*)((u8*)D_00797BAC + slot * 0x18);
    XB_VOICE* v;
    s32 desc[6];
    s32 cue;
    s32 src;
    u32 i;

    if (bank->loaded == 0 || !xb_SeGroupFree(grp, prio)) {
        return 1;
    }

    for (i = 0; i < 48; i++) {
        if (D_00797128[i].cue == 0) {
            break;
        }
    }

    if (i >= 48) {
        return 0;
    }

    v = &D_00797128[i];
    src = v->source;

    if (D_00797100 == 0) {
        if (pan != 0x100) {
            if (pan < -32) {
                pan = -32;
            }

            if (pan > 32) {
                pan = 32;
            }

            v->bin0 = 0;
            v->nbins = 2;
            v->vol0 = D_003F3300[pan + 32];
            v->vol1 = D_003F3408[pan + 32];
            v->bin1 = 1;
            IXACTSoundSource__SetMixBinVolumes(src, &v->nbins);
        }
    } else {
        v->vol0 = D_003F3300[32];
        v->nbins = 2;
        v->bin0 = 0;
        v->vol1 = D_003F3408[32];
        v->bin1 = 1;
        IXACTSoundSource__SetMixBinVolumes(src, &v->nbins);
    }

    if (IXACTSoundBank__Prepare(bank->sbank, cue_idx, 8, &cue) != 0) {
        return 0;
    }

    xb_StopSeGroup(grp);
    v->cue = cue;

    if (IXACTSoundBank__Play(bank->sbank, -1, src, 4, &v->cue) != 0) {
        return 0;
    }

    memset(desc, 0, sizeof(desc));
    desc[2] = -1;
    desc[1] = bank->sbank;
    desc[3] = v->cue;
    ((u16*)desc)[0] = 1;
    ((u16*)desc)[1] = 4;
    desc[4] = 0;
    desc[5] = 0;

    if (IXACTEngine__RegisterNotification(*(s32*)((u8*)D_00797BAC - 4), desc) < 0) {
        return 0;
    }

    v->slot = slot;
    v->cue_idx = cue_idx;
    v->grp = grp;
    v->prio = prio;
    v->state = 0;
    v->bank = bank->sbank;
    return 1;
}

/* xb_InitSoundBankList 0xF53C4.
 *
 * Clears the bank slots, voices and request queue, loads the pan tables
 * and the sound pack, creates the XACT engine and one sound source per
 * voice (two mix bins at the source's own volume) and sets the master
 * volume. */

s32 xb_InitSoundBankList(void) {
    s32 params[5];
    XB_VOICE* v;
    s32 i;

    D_00797100 = 0;
    D_00797EF8 = 0;
    xb_LoadPanTables();

    for (i = 0; i < 3; i++) {
        D_00797BAC[i].loaded = 0;
        D_00797BAC[i].id = 0xFF;
        D_00797BAC[i].data = 0;
        D_00797BAC[i].sbank = 0;
        D_00797BAC[i].wbdata = 0;
        D_00797BAC[i].wbank = 0;
    }

    for (i = 0; i < 48; i++) {
        D_00797128[i].state = 0;
        D_00797128[i].cue = 0;
    }

    xb_LoadSoundPack();
    memset(&params[1], 0, 16);
    params[0] = 0xBC;
    params[1] = 0;
    params[2] = 0;
    params[3] = 0x5DC;
    params[4] = 0xFA;

    if (XACTEngineCreate(params, (s32*)((u8*)D_00797BAC - 4)) < 0) {
        return 0;
    }

    for (v = D_00797128; v < &D_00797128[48]; v++) {
        if (xb_CreateSoundSource(*(s32*)((u8*)D_00797BAC - 4), 1, &v->source) < 0) {
            return 0;
        }

        v->nbins = 2;
        v->bins = &v->bin0;
        v->bin0 = 0;
        v->vol0 = 0;
        v->bin1 = 1;
        v->vol1 = 0;
        IXACTSoundSource__SetMixBins(v->source, &v->nbins);
    }

    mlSysSetMasterVolume(0x7F);
    return 1;
}

/* xb_XactPollNotifications 0xF54B0.
 *
 * Frees the voice of each cue XACT reports finished (stopping it when
 * it was marked to stop), then starts queued requests in order until
 * one cannot start. */

void xb_XactPollNotifications(void) {
    s32 n[11];
    XB_VOICE* v;
    u32 i;
    u32 k;
    u32 count;

    while (xb_GetNotification(*(s32*)((u8*)D_00797BAC - 4), 0, n) == 0) {
        for (i = 0; i < 48; i++) {
            if (D_00797128[i].cue == n[3]) {
                v = &D_00797128[i];

                if (v->state == 1) {
                    IXACTSoundBank__Stop(v->bank, -1, 2, n[3]);
                }

                v->cue = 0;
                v->state = 1;
                break;
            }
        }
    }

    count = D_00797EF8;

    for (k = 0; k < count; k++) {
        if (!xb_StartSoundEntry(D_00797BF8[0].slot, D_00797BF8[0].cue_idx, D_00797BF8[0].grp, D_00797BF8[0].prio,
                                D_00797BF8[0].e, D_00797BF8[0].pan, D_00797BF8[0].g)) {
            break;
        }

        D_00797EF8--;
        memcpy(&D_00797BF8[0], &D_00797BF8[1], D_00797EF8 * sizeof(XB_TSBREQ));
    }
}

/* xb_LoadListEntry 0xF55C2.
 *
 * Loads sound bank `bank` into slot idx (0 is the resident set),
 * purging what the slot held and registering the wave bank at wbdata
 * unless another slot already has that bank. */

s32 xb_LoadListEntry(u8 idx, u8 bank, u8* wbdata, s32 wbsize) {
    XB_SNDBANKSLOT* slot;

    if (idx == 0) {
        return xb_LoadSoundBanks(0);
    }

    slot = (XB_SNDBANKSLOT*)((u8*)D_00797BAC + idx * 0x18);

    if (slot->loaded == 1) {
        xb_PurgeListEntry(idx);
    }

    if (!xb_FindLoadedBank(bank)) {
        slot->wbdata = wbdata;

        if (xb_RegisterWaveBank(*(s32*)((u8*)D_00797BAC - 4), wbdata, wbsize, &slot->wbank) < 0) {
            return 0;
        }
    }

    slot->data = D_0032FD80[bank];

    if (xb_CreateSoundBank(*(s32*)((u8*)D_00797BAC - 4), slot->data, D_0032FDD8[bank], &slot->sbank) < 0) {
        return 0;
    }

    slot->loaded = 1;
    slot->id = bank;
    return 1;
}

s32 XB_STDCALL IXACTEngine_RegisterNotification(s32 engine, void* desc);
s32 XB_STDCALL IXACTSoundBank_PrepareEx(s32 bank, void* params, s32* cue);
s32 XB_STDCALL IXACTSoundBank_PlayEx(s32 bank, void* params, s32* cue);
s32 XB_STDCALL sub_001B8084(s32 source, void* bins);

/* xb_SeGroupFree 0xF4D92: 0 when a playing voice of group grp has a
 * priority above prio, else 1. */
s32 xb_SeGroupFree(u8 grp, u8 prio) {
    u32 i;

    for (i = 0; i < 48; i++) {
        if (D_00797128[i].cue != 0 && D_00797128[i].state != 1 && D_00797128[i].grp == grp &&
            D_00797128[i].prio > prio) {
            return 0;
        }
    }

    return 1;
}

/* The XDK header's inline wrappers this file's code uses. */
s32 XB_STDCALL IXACTEngine__RegisterNotification(s32 engine, void* desc) {
    return IXACTEngine_RegisterNotification(engine, desc);
}

s32 XB_STDCALL IXACTSoundSource__SetMixBinVolumes(s32 source, void* bins) {
    return sub_001B8084(source, bins);
}

/* xb_XactPrepare 0xF4E72 and xb_XactPlay 0xF4E9D: the cue parameters on
 * the stack for IXACTSoundBank_PrepareEx and IXACTSoundBank_PlayEx. */
s32 xb_XactPrepare(s32 bank, s32 idx, s32 flags, s32* cue) {
    s32 p[4];

    p[2] = 0;
    p[3] = 0;
    p[0] = flags;
    p[1] = idx;
    return IXACTSoundBank_PrepareEx(bank, p, cue);
}

s32 xb_XactPlay(s32 bank, s32 idx, s32 source, s32 flags, s32* cue) {
    s32 p[4];

    p[3] = 0;
    p[0] = flags;
    p[1] = idx;
    p[2] = source;
    return IXACTSoundBank_PlayEx(bank, p, cue);
}

s32 XB_STDCALL IXACTSoundBank__Prepare(s32 bank, u16 cue_idx, s32 flags, s32* out) {
    return xb_XactPrepare(bank, cue_idx, flags, out);
}

s32 XB_STDCALL IXACTSoundBank__Play(s32 bank, s32 idx, s32 source, s32 flags, s32* cue) {
    return xb_XactPlay(bank, idx, source, flags, cue);
}

/* xb_StopSeGroup 0xF5138: stops every playing voice of group grp.
 * Returns 0 when a stop fails. */
s32 xb_StopSeGroup(u8 grp) {
    u32 i;

    for (i = 0; i < 48; i++) {
        if (D_00797128[i].cue != 0 && D_00797128[i].state != 1 && D_00797128[i].grp == grp) {
            IXACTSoundSource__StopSoundCues(D_00797128[i].source);

            if (IXACTSoundBank__Stop(D_00797128[i].bank, -1, 2, D_00797128[i].cue) != 0) {
                return 0;
            }

            D_00797128[i].state = 1;
        }
    }

    return 1;
}
