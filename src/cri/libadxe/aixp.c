/* AIXP_SetOutVolDolbyDigital 0x1669B0, AIXP_GetStat 0x166B00,
 * AIXP_GetAdxt 0x166B20, AIXP_SetLpSw 0x166B60, AIXP_Pause 0x167280.
 *
 * stat is the byte at +1. The ADXT table is the pointer array at +0xC.
 * Speaker volumes are the six dwords at +0x204. The loop switch is the
 * byte at +0x1B0. The per-track apply flag is the dword array at +0x1E0.
 * Error calls go to xb_aixerr_CallErrFunc1 (0x16EB40), a tail jmp to
 * ADXERR_CallErrFunc1.
 */

#include "types.h"
#include <string.h>

#include <stddef.h>

typedef struct {
    s8 used;
    s8 stat;
    s8 maxnch;
    s8 maxntr;
    void *sjd;
    void *stm;
    void *adxt[32];
    void *sj;
    void *sj_play;
    void *sjtr[32];
    u8 gap114[0x94];
    s32 pause;
    s32 unk1AC;
    s8 lpsw;
    u8 unk1B1;
    s8 unk1B2;
    u8 gap1B3[0x19];
    const char *fname;
    void *dir;
    s32 ofst;
    s32 nsct;
    s32 unk1DC;
    s32 unk1E0[9];
    s32 spk_vol[6];
} AIX_PLY;

typedef struct {
    s32 ch;
    s32 vol;
} AIXP_CHVOL;

typedef struct {
    s32 nch;
    AIXP_CHVOL *pair;
} AIXP_OUTVOL;

#if defined(__i386__)
_Static_assert(offsetof(AIX_PLY, stat) == 1, "stat");
_Static_assert(offsetof(AIX_PLY, adxt) == 0xC, "adxt");
_Static_assert(offsetof(AIX_PLY, lpsw) == 0x1B0, "lpsw");
_Static_assert(offsetof(AIX_PLY, unk1E0) == 0x1E0, "unk1E0");
_Static_assert(offsetof(AIX_PLY, spk_vol) == 0x204, "spk_vol");
#endif

extern void xb_aixerr_CallErrFunc1(const char *msg);
extern char *volatile aixp_build; /* aixp_build is 0x2DF68C */
extern char *volatile adxt_build;
extern s32 aixp_init_cnt; /* aixp_init_cnt is 0x7A5310 */
extern s32 aixp_svr_id; /* aixp_svr_id is 0x7A5314 */
extern AIX_PLY aixp_obj[4]; /* aixp_obj is 0xCE9B80 */
extern void (*xb_adxt_hook_a)(void); /* 0x7A533C */
extern void (*xb_adxt_hook_b)(void); /* 0x7A5340 */
extern void xb_aixp_InitLib(void);
extern void xb_aixp_FinishLib(void);
extern void xb_aixp_ExecHndlSafe(AIX_PLY *aixp);
extern void xb_aix_ExecServer(void);
extern void xb_aix_SetField1C(void *aix, void *sj);
extern void xb_aixp_FreeHandle(void *aix);
extern s32 ADXM_IsSetupThrd(void);
extern s32 SVM_SetCbSvr(s32 index, s32 (*func)(void *object), void *object);
extern void SVM_SetCbSvrId(s32 svtype, s32 id, s32 (*func)(void *object), void *object);
extern void SVM_DelCbSvr(s32 group, s32 id);
extern s32 sub_001669A0(void *object);
extern void sub_0016DFD0(void *stm, s32 a, s32 b);
extern void ADXSTM_Destroy(void *stm);
extern void ADXSTM_StopNw(void *stm);
extern void ADXT_Destroy(void *adxt);
extern void ADXT_Stop(void *adxt);
extern void ADXAMP_Stop(void *amp);
void AIXP_Stop(AIX_PLY *aixp);
void AIXP_Destroy(AIX_PLY *aixp);
extern void ADXT_Pause(void *adxt, s32 sw);
extern void sub_0016AA60(void);
extern void sub_0016AA70(void);
extern void xb_aixp_Pause(AIX_PLY *aixp, s32 sw);
extern void xb_aixp_SetTrackSpeakerVol(void *adxt, AIXP_OUTVOL *arg);
extern void xb_aixp_SetTrackMixBinVolumes(void *adxt, AIXP_OUTVOL *arg);

/* AIXP_GetStat 0x166B00.
 *
 * Returns the status byte at +1. A null handle reports E2003050209
 * and returns -1. The error call is the tail jmp at 0x16EB40.
 * The previous byte is int3, so it is interior.
 */

s32 AIXP_GetStat(AIX_PLY *aixp) {
    if (aixp == 0) {
        xb_aixerr_CallErrFunc1("E2003050209 : NULL pointer is specified.");
        return -1;
    }

    return aixp->stat;
}

void *AIXP_GetAdxt(AIX_PLY *aixp, s32 trno) {
    if (aixp == 0) {
        xb_aixerr_CallErrFunc1("E2003050210 : NULL pointer is specified.");
        return 0;
    }

    if (trno > 0x20) {
        xb_aixerr_CallErrFunc1("E2003052112 : The parameter 'trno' is out of range.");
        return 0;
    }

    return aixp->adxt[trno];
}

/* AIXP_SetOutVolDolbyDigital 0x1669B0.
 *
 * Scales vol by 10 and clamps it to -10000..0, then stores it at
 * spk_vol[spkid] before the range check. spkid above 5 reports
 * E2003110703. Speakers 0 and 1 use channels 0 and 1, speakers 2 and 3
 * use channels 4 and 5, and speakers 4 and 5 use channels 2 and 3.
 * The pair is applied to adxt[spkid / 2]. The first apply calls
 * 0x16AFB0 and sets unk1E0. Later applies call 0x16AFD0. The jump
 * table is at 0x166ADC. It is a scanned start.
 */

void AIXP_SetOutVolDolbyDigital(AIX_PLY *aixp, s32 spkid, s32 vol) {
    s32 scaled;
    s32 track;
    AIXP_CHVOL pair[2];
    AIXP_OUTVOL arg;

    if (aixp == 0) {
        xb_aixerr_CallErrFunc1("E2003110701 : NULL pointer is specified.");
        return;
    }

    scaled = vol * 10;

    if (scaled > 0) {
        scaled = 0;
    } else if (scaled < -10000) {
        scaled = -10000;
    }

    aixp->spk_vol[spkid] = scaled;

    if ((u32)spkid > 5) {
        xb_aixerr_CallErrFunc1("E2003110703 : Illegal speaker ID is specified.");
        return;
    }

    if (spkid <= 1) {
        pair[0].ch = 0;
        pair[0].vol = aixp->spk_vol[0];
        pair[1].ch = 1;
        pair[1].vol = aixp->spk_vol[1];
    } else if (spkid <= 3) {
        pair[0].ch = 4;
        pair[0].vol = aixp->spk_vol[2];
        pair[1].ch = 5;
        pair[1].vol = aixp->spk_vol[3];
    } else {
        pair[0].ch = 2;
        pair[0].vol = aixp->spk_vol[4];
        pair[1].ch = 3;
        pair[1].vol = aixp->spk_vol[5];
    }

    track = spkid / 2;
    arg.nch = 2;
    arg.pair = pair;

    if (aixp->unk1E0[track] == 0) {
        xb_aixp_SetTrackSpeakerVol(aixp->adxt[track], &arg);
        aixp->unk1E0[track] = 1;
    } else {
        xb_aixp_SetTrackMixBinVolumes(aixp->adxt[track], &arg);
    }
}

/* AIXP_SetLpSw 0x166B60.
 *
 * Stores the low byte of sw at +0x1B0. The unnamed body at 0x166BF0
 * wraps the phrase at +0x1BC back to +0x1C4 when this byte is 1 and
 * the phrase reaches +0x1C8. The next byte, +0x1B1, gates the link
 * path in that same body. A null handle reports E2003050211.
 * It is a scanned start.
 */

void AIXP_SetLpSw(AIX_PLY *aixp, s32 sw) {
    if (aixp == 0) {
        xb_aixerr_CallErrFunc1("E2003050211 : NULL pointer is specified.");
        return;
    }

    aixp->lpsw = (s8)sw;
}

/* xb_aixp_Pause 0x166B90.
 *
 * Static (config/sf33rd/static.txt): AIXP_Pause passes the handle in esi.
 * The pause switch is the s32 at +0x1A8.
 */

void xb_aixp_Pause(AIX_PLY *aixp, s32 sw) {
    s32 i;

    if (aixp == 0) {
        xb_aixerr_CallErrFunc1("E2003050222 : NULL pointer is specified.");
        return;
    }

    AIXP_GetStat(aixp);
    *(s32 *)((u8 *)aixp + 0x1A8) = sw;

    if (aixp->stat == 1) {
        return;
    }

    for (i = 0; i < aixp->maxntr; i++) {
        if (aixp->adxt[i] != 0) {
            ADXT_Pause(aixp->adxt[i], sw);
        }
    }
}

/* AIXP_Pause 0x167280.
 *
 * Locks, then calls 0x166B90. Xbox passes the handle in esi and pushes
 * only sw. That body stores sw at +0x1A8. Unless stat is 1, it calls
 * ADXT_Pause on each adxt[i]. A null handle there tail-jumps through
 * 0x16EB40 with E2003050222. This wrapper tail-jumps to ADXCRS_Unlock.
 * The previous byte is int3, so it is interior.
 */

void AIXP_Pause(AIX_PLY *aixp, s32 sw) {
    sub_0016AA60();
    xb_aixp_Pause(aixp, sw);
    sub_0016AA70();
}

/* AIXP_Stop 0x1671E0, xb_aixp_ExecAllHndl 0x1672D0, xb_aixp_ExecServer
 * 0x167300, xb_aixp_ExecServerCb 0x167310, AIXP_Init 0x167320,
 * AIXP_Destroy 0x1673A0, AIXP_StartFname 0x167490, AIXP_Finish 0x167640,
 * and the two optional hooks 0x1678F0/0x167900. The four handles are
 * 0x21C bytes at 0xCE9B80. */

void AIXP_Stop(AIX_PLY *aixp) {
    s32 i;

    if (aixp == 0) {
        xb_aixerr_CallErrFunc1("E2003050208 : NULL pointer is specified.");
        return;
    }

    for (i = 0; i < aixp->maxntr; i++) {
        ADXT_Stop(AIXP_GetAdxt(aixp, i));
    }

    if (aixp->stm != 0) {
        ADXSTM_StopNw(aixp->stm);
    }

    sub_0016AA60();

    if (aixp->sjd != 0) {
        ADXAMP_Stop(aixp->sjd);
    }

    if (aixp->unk1DC == 2) {
        void *sj = aixp->sj_play;

        aixp->sj_play = 0;

        if (sj != 0) {
            (*(void (**)(void *))(*(u8 **)sj + 0xC))(sj);
        }
    }

    aixp->sj_play = 0;
    aixp->stat = 0;
    aixp->unk1AC = 0;
    sub_0016AA70();
}

void xb_aixp_ExecAllHndl(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        if (aixp_obj[i].used == 1) {
            xb_aixp_ExecHndlSafe(&aixp_obj[i]);
        }
    }
}

s32 xb_aixp_ExecServer(void *obj) {
    (void)obj;
    xb_aixp_ExecAllHndl();
    xb_aix_ExecServer();
    return 0;
}

s32 xb_aixp_ExecServerCb(void *obj) {
    (void)obj;
    xb_aixp_ExecServer(0);
    return 0;
}

void AIXP_Init(void) {
    (void)aixp_build;

    if (aixp_init_cnt == 0) {
        xb_aixp_InitLib();
        memset(aixp_obj, 0, sizeof(aixp_obj));

        if (ADXM_IsSetupThrd() == 1) {
            SVM_SetCbSvrId(2, 0, xb_aixp_ExecServer, 0);
            aixp_svr_id = SVM_SetCbSvr(5, sub_001669A0, 0);
        } else {
            aixp_svr_id = SVM_SetCbSvr(5, xb_aixp_ExecServerCb, 0);
        }
    }

    aixp_init_cnt++;
}

void AIXP_Destroy(AIX_PLY *aixp) {
    void *stm;
    void *sj;
    s32 i;

    if (aixp == 0) {
        xb_aixerr_CallErrFunc1("E2003050202 : NULL pointer is specified.");
        return;
    }

    AIXP_Stop(aixp);
    stm = aixp->stm;

    if (stm != 0) {
        aixp->stm = 0;
        sub_0016DFD0(stm, 0, 0);
        ADXSTM_Destroy(stm);
    }

    for (i = 0; i < aixp->maxntr; i++) {
        if (aixp->adxt[i] != 0) {
            void *adxt = aixp->adxt[i];

            aixp->adxt[i] = 0;
            ADXT_Destroy(adxt);
        }
    }

    sub_0016AA60();

    for (i = 0; i < aixp->maxntr; i++) {
        sj = aixp->sjtr[i];

        if (sj != 0) {
            aixp->sjtr[i] = 0;
            (*(void (**)(void *))(*(u8 **)sj + 0xC))(sj);
        }
    }

    sj = aixp->sj;

    if (sj != 0) {
        aixp->sj = 0;
        (*(void (**)(void *))(*(u8 **)sj + 0xC))(sj);
    }

    if (aixp->sjd != 0) {
        void *aix = aixp->sjd;

        aixp->sjd = 0;
        xb_aixp_FreeHandle(aix);
    }

    memset(aixp, 0, sizeof(AIX_PLY));
    aixp->used = 0;
    sub_0016AA70();
}

void AIXP_StartFname(AIX_PLY *aixp, const char *fname, void *dir) {
    (void)adxt_build;

    if (aixp == 0 || fname == 0) {
        xb_aixerr_CallErrFunc1("E2003050203 : NULL pointer is specified.");
        return;
    }

    AIXP_Stop(aixp);
    sub_0016AA60();
    aixp->fname = fname;
    aixp->dir = dir;
    aixp->ofst = 0;
    aixp->nsct = 0xFFFFF;
    aixp->sj_play = aixp->sj;
    xb_aix_SetField1C(aixp->sjd, aixp->sj);
    aixp->unk1DC = 0;
    aixp->unk1B2 = 1;
    aixp->stat = 1;
    sub_0016AA70();
}

void AIXP_Finish(void) {
    s32 i;

    if (--aixp_init_cnt == 0) {
        for (i = 0; i < 4; i++) {
            if (aixp_obj[i].used == 1) {
                AIXP_Destroy(&aixp_obj[i]);
            }
        }

        memset(aixp_obj, 0, sizeof(aixp_obj));
        SVM_DelCbSvr(2, 0);
        SVM_DelCbSvr(5, aixp_svr_id);
        xb_aixp_FinishLib();
    }
}

void xb_adxt_DetachHookA(void) {
    if (xb_adxt_hook_a != 0) {
        xb_adxt_hook_a();
    }
}

void xb_adxt_DetachHookB(void) {
    if (xb_adxt_hook_b != 0) {
        xb_adxt_hook_b();
    }
}
