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
    void *buf;
    s32 bufsize;
    s32 unk11C;
    void *trbuf[32];
    s32 trbsize;
    s32 trxsize;
    s32 pause;
    s32 unk1AC;
    s8 lpsw;
    u8 unk1B1;
    s8 unk1B2;
    u8 gap1B3[5];
    s32 unk1B8;
    s32 phrase;
    s32 unk1C0;
    s32 lp_start;
    s32 lp_end;
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
_Static_assert(offsetof(AIX_PLY, trbsize) == 0x1A0, "trbsize");
_Static_assert(offsetof(AIX_PLY, phrase) == 0x1BC, "phrase");
_Static_assert(offsetof(AIX_PLY, fname) == 0x1CC, "fname");
_Static_assert(offsetof(AIX_PLY, adxt) == 0xC, "adxt");
_Static_assert(offsetof(AIX_PLY, lpsw) == 0x1B0, "lpsw");
_Static_assert(offsetof(AIX_PLY, unk1E0) == 0x1E0, "unk1E0");
_Static_assert(offsetof(AIX_PLY, spk_vol) == 0x204, "spk_vol");
#endif

extern void xb_aixerr_CallErrFunc1(const char *msg);
char *volatile aixp_build = "\nAIXP/XBOX Ver.1.86 Build:Feb 13 2004 21:08:22\n"; /* aixp_build is 0x2DF68C */
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
extern s32 xb_aix_GetField2B0(void *aix);
extern s32 xb_aix_GetMode(void *aix);
extern void xb_aix_GetTrackInfo(void *aix, s32 tr, s32 *a, s32 *b);
extern void *xb_aix_Create(s32 nsj, void *sjin, void **sjs);
extern void *ADXT_Create(s32 maxnch, void *work, s32 worksize);
extern void *SJRBF_Create(void *buf, s32 bsize, s32 xsize);
extern void *ADXSTM_Create(void *sj, s32 a);
extern s32 ADXSTM_Seek(void *stm, s32 offset);
extern void ADXSTM_SetEos(void *stm, s32 eos);
extern s32 ADXSTM_Start(void *stm);
extern void ADXSTM_ReleaseFileNw(void *stm);
extern void ADXSTM_BindFileNw(void *stm, const char *fname, void *dir, s32 ofst, s32 nsct);
extern void ADXSTM_SetBufSize(void *stm, s32 min, s32 max);
extern s32 ADXSTM_GetStat(void *obj);
extern void xb_aix_SetField3(void *aix, s32 v);
extern void xb_aix_SetField4(void *aix, s32 v);
extern s32 xb_aix_GetNumTrack(void *aix);
extern void xb_aix_Reset(void *aix);
extern s32 ADXT_GetStat(void *adxt);
extern void ADXT_SetLnkSw(void *adxt, s32 sw);
extern void ADXT_StartSj(void *adxt, void *sj);
extern s32 SVM_TestAndSet(s32 *flag);
extern s32 D_007A5318;
extern void xb_aix_ConfigTrack(void *adxt, s32 ch);
extern s32 ADXM_IsSetupThrd(void);
extern s32 SVM_SetCbSvr(s32 index, s32 (*func)(void *object), void *object);
extern void SVM_SetCbSvrId(s32 svtype, s32 id, s32 (*func)(void *object), void *object);
extern void SVM_DelCbSvr(s32 group, s32 id);
extern s32 xb_aixp_ReturnZero(void *object);
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

/* xb_aixp_EosFunc 0x166BF0.
 *
 * The end-of-stream callback xb_aixp_Create gives the stream. While
 * playing (+0x1AC is 1, or stat is 2) it steps the phrase at +0x1BC,
 * wrapping it to lp_start when lpsw is 1 and it reaches lp_end. With
 * +0x1B1 set and the phrase still in range it seeks the stream to the
 * phrase (or, in mode 1, to the file start with no end) and restarts it.
 */

void xb_aixp_EosFunc(AIX_PLY *aixp) {
    s32 ofst;
    s32 size;
    s32 ph;

    if (aixp->unk1AC != 1 && aixp->stat != 2) {
        return;
    }

    ph = ++aixp->phrase;

    if (aixp->lpsw == 1 && ph >= aixp->lp_end) {
        aixp->phrase = aixp->lp_start;
    }

    if (aixp->unk1B1 != 1 || aixp->phrase >= xb_aix_GetField2B0(aixp->sjd)) {
        return;
    }

    sub_0016AA60();
    ph = aixp->phrase;

    switch (xb_aix_GetMode(aixp->sjd)) {
    case 0:
        xb_aix_GetTrackInfo(aixp->sjd, ph, &ofst, &size);
        ADXSTM_Seek(aixp->stm, ofst / 0x800);
        ADXSTM_SetEos(aixp->stm, (ofst + size) / 0x800);
        ADXSTM_Start(aixp->stm);
        break;
    case 1:
        ADXSTM_Seek(aixp->stm, 0);
        ADXSTM_SetEos(aixp->stm, -1);
        ADXSTM_Start(aixp->stm);
        sub_0016AA70();
        return;
    }

    sub_0016AA70();
}

#define SJ_RESET(sj) (*(void (**)(void *))(*(u8 **)(sj) + 0x14))(sj)

/* xb_aixp_RestartStream 0x166D20.
 *
 * Releases the stream's file, resets the file and track ring buffers,
 * rebinds the file, gives the stream half the file buffer, seeks it to
 * the start with the end at sector 3 (the header), and resets the
 * demuxer to read the header again. ADXSTM_GetStat is the folded
 * GetStat the stream and the demuxer share.
 */

void xb_aixp_RestartStream(AIX_PLY *aixp) {
    s32 i;

    ADXSTM_ReleaseFileNw(aixp->stm);
    SJ_RESET(aixp->sj_play);

    for (i = 0; i < aixp->maxntr; i++) {
        SJ_RESET(aixp->sjtr[i]);
    }

    ADXSTM_BindFileNw(aixp->stm, aixp->fname, aixp->dir, aixp->ofst, aixp->nsct);
    ADXSTM_SetBufSize(aixp->stm, aixp->bufsize / 2, 0x7FFFFFFF);
    ADXSTM_Seek(aixp->stm, 0);
    ADXSTM_SetEos(aixp->stm, 3);
    ADXSTM_Start(aixp->stm);
    xb_aix_SetField3(aixp->sjd, 1);
    xb_aix_Reset(aixp->sjd);
}

/* xb_aixp_ExecHndl 0x166DF0.
 *
 * Static (config/sf33rd/static.txt): the handle is in esi. In the
 * prepare state (stat 1) it holds the tracks paused until the demuxer
 * has the header (its stat 2), then seeks the stream to the start
 * phrase and starts every track on its ring buffer. Once every track
 * is playing it unpauses them (unless paused) and goes to stat 2. In
 * stat 2 it moves to 3 when the tracks have run out, and a stream
 * error (stat 4) is carried to the handle.
 */

static void xb_aixp_ExecHndl(AIX_PLY *aixp) {
    void *aix;
    void **adxt;
    s32 ofst;
    s32 size;
    s32 ntr;
    s32 st;
    s32 i;

    aix = aixp->sjd;
    adxt = aixp->adxt;

    if (aixp->stat == 1) {
        for (i = 0; i < aixp->maxntr; i++) {
            ADXT_Pause(adxt[i], 1);
        }

        if (aixp->unk1AC == 0) {
            if (aixp->unk1DC != 0 && aixp->unk1DC != 1) {
                st = ADXSTM_GetStat(aix);

                if (st == 0) {
                    for (i = 0; i < aixp->maxntr; i++) {
                        SJ_RESET(aixp->sjtr[i]);
                    }

                    xb_aix_Reset(aix);
                } else if (st == 2) {
                    ntr = xb_aix_GetNumTrack(aix);

                    for (i = 0; i < ntr; i++) {
                        ADXT_StartSj(aixp->adxt[i], aixp->sjtr[i]);
                    }

                    aixp->unk1AC = 1;
                }
            } else {
                st = ADXSTM_GetStat(aixp->stm);
                sub_0016AA60();

                if (aixp->unk1B2 == 1 && st != 2) {
                    aixp->unk1B2 = 0;
                    sub_0016AA70();
                    xb_aixp_RestartStream(aixp);
                } else {
                    sub_0016AA70();
                }

                if (ADXSTM_GetStat(aix) == 2) {
                    ntr = xb_aix_GetNumTrack(aix);

                    switch (xb_aix_GetMode(aix)) {
                    case 0:
                        st = aixp->phrase = aixp->unk1C0;

                        if (st < 0 || st >= xb_aix_GetField2B0(aixp->sjd)) {
                            aixp->stat = 3;
                            return;
                        }

                        xb_aix_GetTrackInfo(aix, st, &ofst, &size);
                        ADXSTM_Seek(aixp->stm, ofst / 0x800);
                        ADXSTM_SetEos(aixp->stm, (size + ofst) / 0x800);
                        xb_aix_SetField3(aix, 0);

                        if (aixp->lpsw == 1 || aixp->unk1B1 == 1) {
                            xb_aix_SetField4(aix, 1);
                        }

                        for (i = 0; i < ntr; i++) {
                            ADXT_SetLnkSw(aixp->adxt[i], 1);
                            ADXT_StartSj(aixp->adxt[i], aixp->sjtr[i]);
                        }

                        break;
                    case 1:
                        ADXSTM_SetEos(aixp->stm, -1);
                        xb_aix_SetField3(aix, 0);

                        if (aixp->lpsw == 1 || aixp->unk1B1 == 1) {
                            xb_aix_SetField4(aix, 1);
                        }

                        ADXT_SetLnkSw(aixp->adxt[0], 1);
                        ADXT_StartSj(aixp->adxt[0], aixp->sjtr[0]);
                        break;
                    }

                    aixp->unk1AC = 1;
                }
            }
        } else {
            ntr = xb_aix_GetNumTrack(aix);

            for (i = 0; i < ntr; i++) {
                st = ADXT_GetStat(aixp->adxt[i]);

                if (st == 6) {
                    aixp->stat = 4;
                    break;
                }

                if (st != 3) {
                    break;
                }
            }

            if (i == ntr) {
                sub_0016AA60();

                if (aixp->pause == 0) {
                    for (i = 0; i < ntr; i++) {
                        ADXT_Pause(aixp->adxt[i], 0);
                    }
                }

                aixp->stat = 2;
                aixp->unk1AC = 0;
                sub_0016AA70();
            }
        }
    }

    if (aixp->stat == 2) {
        switch (xb_aix_GetMode(aix)) {
        case 0:
            if (ADXSTM_GetStat(aix) == 3) {
                for (i = 0; i < aixp->maxntr; i++) {
                    st = ADXT_GetStat(aixp->adxt[i]);

                    if (st != 5 && st != 0) {
                        break;
                    }
                }

                if (i == aixp->maxntr) {
                    aixp->stat = 3;
                }
            }

            break;
        case 1:
            if (ADXSTM_GetStat(aixp->stm) != 2) {
                st = ADXT_GetStat(aixp->adxt[0]);

                if (st == 5 || st == 0) {
                    aixp->stat = 3;
                }
            }

            break;
        }
    }

    sub_0016AA60();

    if (aixp->stm != 0 && ADXSTM_GetStat(aixp->stm) == 4) {
        aixp->stat = 4;
    }

    sub_0016AA70();
}

/* xb_aixp_ExecHndlSafe 0x1672A0.
 *
 * Runs xb_aixp_ExecHndl unless it is already running (the flag at
 * 0x7A5318).
 */

void xb_aixp_ExecHndlSafe(AIX_PLY *aixp) {
    if (SVM_TestAndSet(&D_007A5318)) {
        xb_aixp_ExecHndl(aixp);
        D_007A5318 = 0;
    }
}

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
            aixp_svr_id = SVM_SetCbSvr(5, xb_aixp_ReturnZero, 0);
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

/* xb_aixp_Create 0x1676A0.
 *
 * Static (config/sf33rd/static.txt): AIXP_Create passes the work buffer
 * in eax and its size in ecx. Takes a free aixp_obj slot and carves the
 * 64-aligned work into one ADXT and one 0x2000-byte ring buffer per
 * track, then the whole-file ring buffer from what is left (rounded down
 * to a sector, less 0x2000), the demuxer and the stream.
 */

static AIX_PLY *xb_aixp_Create(u8 *work, s32 wksize, s32 maxntr, s32 maxnch) {
    AIX_PLY *aixp;
    u8 *wk;
    s32 rem;
    s32 trsize;
    s32 i;

    wk = (u8 *)(((s32)work + 0x3F) & ~0x3F);
    rem = (s32)(work - wk) + wksize;
    trsize = (maxnch * 0x40C0 + 0x7F) & ~0x3F;

    if (work == 0) {
        xb_aixerr_CallErrFunc1("E2003050201 : NULL pointer is specified.");
        return 0;
    }

    for (i = 0, aixp = aixp_obj; (s32)aixp < (s32)&aixp_obj[4]; aixp++, i++) {
        if (aixp->used == 0) {
            break;
        }
    }

    if (i == 4) {
        return 0;
    }

    aixp = &aixp_obj[i];
    memset(aixp, 0, sizeof(AIX_PLY));
    aixp->maxnch = maxnch;
    aixp->trbsize = 0x2000;
    aixp->trxsize = 0x40;

    for (i = 0; i < maxntr; i++) {
        if ((aixp->adxt[i] = ADXT_Create(maxnch, wk, trsize)) == 0) {
            goto fail;
        }

        wk += trsize;
        aixp->trbuf[i] = wk;
        wk += 0x2040;
        rem += -0x2040 - trsize;

        if (rem < 0) {
            goto fail;
        }

        if ((aixp->sjtr[i] = SJRBF_Create(aixp->trbuf[i], aixp->trbsize, aixp->trxsize)) == 0) {
            goto fail;
        }
    }

    aixp->bufsize = (rem - 0x2000) / 0x800 * 0x800;
    aixp->unk11C = 0x2000;
    aixp->buf = wk;
    aixp->sj_play = 0;

    if ((aixp->sj = SJRBF_Create(wk, aixp->bufsize, 0x2000)) == 0) {
        goto fail;
    }

    if ((aixp->sjd = xb_aix_Create(maxntr, aixp->sj_play, aixp->sjtr)) == 0) {
        goto fail;
    }

    if ((aixp->stm = ADXSTM_Create(aixp->sj, 0)) == 0) {
        goto fail;
    }

    sub_0016DFD0(aixp->stm, (s32)xb_aixp_EosFunc, (s32)aixp);
    aixp->maxnch = maxnch;
    aixp->pause = 0;
    aixp->unk1B1 = 1;
    aixp->unk1B8 = 0;
    aixp->unk1C0 = 0;
    aixp->phrase = 0;
    aixp->lp_start = 0;
    aixp->lp_end = 1;
    aixp->used = 1;
    aixp->maxntr = maxntr;
    aixp->lpsw = 0;
    return aixp;

fail:
    AIXP_Destroy(aixp);
    return 0;
}

AIX_PLY *AIXP_Create(s32 maxntr, s32 maxnch, void *work, s32 wksize) {
    AIX_PLY *aixp;

    sub_0016AA60();
    aixp = xb_aixp_Create(work, wksize, maxntr, maxnch);
    sub_0016AA70();
    return aixp;
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

/* xb_aixp_StartFnameSurround 0x167520.
 *
 * Gives each track not yet set up (its flag at +0x1E0) its output
 * channels before AIXP_StartFname: with stereo tracks, up to 3 tracks
 * from output channel 6 as left/right pairs; with mono tracks, up to 6
 * from channel 0. The flags and the channel table overlap for more
 * than 3 tracks, as in the retail code.
 */

void xb_aixp_StartFnameSurround(AIX_PLY *aixp, const char *fname, void *dir) {
    s32 ntr;
    s32 mode;
    s32 base;
    s32 i;

    if (aixp == 0 || fname == 0) {
        xb_aixerr_CallErrFunc1("E2003050204 : NULL pointer is specified.");
        return;
    }

    if (aixp->maxnch > 1) {
        ntr = aixp->maxntr < 3 ? aixp->maxntr : 3;
        base = 6;
        mode = 2;
    } else {
        ntr = aixp->maxntr < 6 ? aixp->maxntr : 6;
        base = 0;
        mode = 1;
    }

    for (i = 0; i < ntr; i++) {
        if (aixp->unk1E0[i] == 0) {
            if (mode == 2) {
                aixp->unk1E0[3 + i * 2] = i;
                aixp->unk1E0[4 + i * 2] = i + base + 1 - base;
                aixp->spk_vol[i * 2] = 0;
                aixp->spk_vol[i * 2 + 1] = 0;
            } else {
                aixp->unk1E0[3 + i] = i;
                aixp->spk_vol[i] = 0;
            }

            xb_aix_ConfigTrack(aixp->adxt[i], i + base);
            aixp->unk1E0[i] = 1;
        }
    }

    AIXP_StartFname(aixp, fname, dir);
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

/* xb_aixp_ReturnZero 0x1669A0: a callback that does nothing. */
s32 xb_aixp_ReturnZero(void *object) {
    return 0;
}
