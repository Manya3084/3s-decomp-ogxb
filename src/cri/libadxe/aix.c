/* aix.c: the AIX demultiplexer under AIXP, 0x16EB40 to 0x16F690 (between
 * sj_rbf and sj_mem). The PS2 build has no AIX, so this is the Xbox CRI
 * code alone. Four handles of 0x195C bytes are at 0xCD6920 and the library
 * reference count is 0x7A6078. A handle keeps its track count at +0xAC,
 * per-track records of 0x10 bytes from +0x2B4, and its mode at +0x1958.
 */

#include "types.h"

#include <string.h>

extern void ADXERR_CallErrFunc1(const char *msg);
extern void sub_0016AA60(void);
extern void sub_0016AA70(void);
extern s32 D_007A6078; /* aix_init_cnt, the library reference count */
extern u8 aix_obj[4][0x195C]; /* aix_obj is 0xCD6920 */

void xb_aixerr_CallErrFunc1(const char *msg) {
    ADXERR_CallErrFunc1(msg);
}

void xb_aixp_InitLib(void) {
    sub_0016AA60();

    if (D_007A6078 == 0) {
        memset(aix_obj, 0, sizeof(aix_obj));
    }

    D_007A6078++;
    sub_0016AA70();
}

void xb_aixp_FinishLib(void) {
    sub_0016AA60();

    if (--D_007A6078 == 0) {
        memset(aix_obj, 0, sizeof(aix_obj));
    }

    sub_0016AA70();
}

void xb_aixp_FreeHandle(void *aix) {
    sub_0016AA60();

    if (aix != 0) {
        *(s32 *)aix = 0;
    }

    sub_0016AA70();
}

void xb_aix_Reset(void *aix) {
    u8 *bytes = aix;

    sub_0016AA60();
    *(s32 *)(bytes + 0x10) = 0;
    *(s32 *)(bytes + 8) = 0;
    *(s32 *)(bytes + 0xC) = 0;
    bytes[1] = 1;
    sub_0016AA70();
}

void xb_aix_SetField1C(void *aix, void *sj) {
    *(void **)((u8 *)aix + 0x1C) = sj;
}

void xb_aix_SetField3(void *aix, s8 v) {
    ((s8 *)aix)[3] = v;
}

void xb_aix_SetField4(void *aix, s8 v) {
    ((s8 *)aix)[4] = v;
}

s32 xb_aix_GetNumTrack(void *aix) {
    return ((s8 *)aix)[0xAC];
}

s32 xb_aix_GetField2B0(void *aix) {
    return *(s32 *)((u8 *)aix + 0x2B0);
}

void xb_aix_GetTrackInfo(void *aix, s32 tr, s32 *a, s32 *b) {
    if (a != 0) {
        *a = *(s32 *)((u8 *)aix + tr * 0x10 + 0x2B4);
    }

    if (b != 0) {
        *b = *(s32 *)((u8 *)aix + tr * 0x10 + 0x2B8);
    }
}

s32 xb_aix_GetMode(void *aix) {
    return *(s32 *)((u8 *)aix + 0x1958);
}

/* The demultiplexer. A handle reads an AIX stream from its input SJ: the
 * "AIXF" header (xb_aix_DecodeHeader) and then 16-byte-headed packets,
 * "AIXP" for track data and "AIXE" at the end. xb_aix_ExecDemux copies
 * each packet's payload into the SJ of its track. A stream with no AIXF
 * header is copied to the first track whole (xb_aix_ExecCopy). */

typedef struct {
    s8 *data;
    s32 len;
} SJCK;

typedef struct SJ_VTBL SJ_VTBL;
typedef struct SJ_OBJ {
    SJ_VTBL *vtbl;
} SJ_OBJ;
typedef SJ_OBJ *SJ;

struct SJ_VTBL {
    void (*QueryInterface)(void);
    void (*AddRef)(void);
    void (*Release)(void);
    void (*Destroy)(SJ sj);
    void *(*GetUuid)(SJ sj);
    void (*Reset)(SJ sj);
    void (*GetChunk)(SJ sj, s32 id, s32 nbyte, SJCK *ck);
    void (*UngetChunk)(SJ sj, s32 id, SJCK *ck);
    void (*PutChunk)(SJ sj, s32 id, SJCK *ck);
    s32 (*GetNumData)(SJ sj, s32 id);
};

#define SJ_GetChunk(sj, id, nbyte, ck) ((sj)->vtbl->GetChunk)(sj, id, nbyte, ck)
#define SJ_UngetChunk(sj, id, ck) ((sj)->vtbl->UngetChunk)(sj, id, ck)
#define SJ_PutChunk(sj, id, ck) ((sj)->vtbl->PutChunk)(sj, id, ck)
#define SJ_GetNumData(sj, id) ((sj)->vtbl->GetNumData)(sj, id)

extern void SJ_SplitChunk(SJCK *ck, s32 nbyte, SJCK *ck1, SJCK *ck2);

#define AIX_BE16(p) (((p)[0] << 8) | (p)[1])
#define AIX_BE32(p) (((((((p)[0] << 8) | (p)[1]) << 8) | (p)[2]) << 8) | (p)[3])

typedef struct {
    u8 id;
    u8 pad1[3];
    u32 value;
    u8 pad8[8];
} AIX_TRKINF;

typedef struct {
    u32 a;
    u32 b;
    u32 c;
    u32 d;
} AIX_SECTION;

typedef struct {
    u16 w[4];
} AIX_LOOP;

typedef struct {
    u8 b0;
    u8 b1;
    u8 pad2[2];
    u32 d4;
    f32 rate;
    s8 ntrk;               /* the handle's +0xAC */
    u8 padD[3];
    AIX_TRKINF trk[32];    /* +0x10 */
    s32 nsec;              /* +0x210 */
    AIX_SECTION sec[360];  /* +0x214, the handle's +0x2B4 */
    s32 nloop;             /* +0x1894 */
    AIX_LOOP loop[4];      /* +0x1898 */
} AIX_HDR;

typedef struct {
    u8 used;
    u8 stat;
    s8 nsj;
    u8 b3;
    u8 b4;
    u8 pad5[3];
    s32 pos;
    s32 unkC;
    s32 unk10;
    u8 pad14[8];
    SJ sjin;
    SJ sj[32];
    AIX_HDR hdr;           /* +0xA0 */
    s32 mode;              /* +0x1958: 0 demultiplex, 1 copy */
} AIX_OBJ;

typedef struct {
    u32 id;
    u32 size;
    u8 trk;
    u8 ntrk;
    s16 len;
    u32 next;
} AIX_PKT;

typedef struct {
    s32 ch;
    s32 vol;
} AIX_CHVOL;

typedef struct {
    s32 nch;
    AIX_CHVOL *pair;
} AIX_OUTVOL;

#if defined(__i386__)
_Static_assert(sizeof(AIX_HDR) == 0x18B8, "AIX_HDR");
_Static_assert(sizeof(AIX_OBJ) == 0x195C, "AIX_OBJ");
#endif

extern void xb_aixp_SetTrackSpeakerVol(void *adxt, AIX_OUTVOL *arg);

AIX_OBJ *xb_aix_AllocHandle(SJ sjin, s32 nsj, SJ *sjs) {
    AIX_OBJ *aix = (AIX_OBJ *)aix_obj;
    s32 i;

    for (i = 0; i < 4; i++, aix++) {
        if (aix->used == 0) {
            break;
        }
    }

    if (i == 4) {
        return 0;
    }

    aix->sjin = sjin;
    aix->stat = 0;

    for (i = 0; i < nsj; i++) {
        aix->sj[i] = sjs[i];
    }

    aix->nsj = nsj;
    aix->b3 = 0;
    aix->b4 = 0;
    aix->used = 1;
    return aix;
}

void xb_aix_ClearHandle(AIX_HDR *hdr) {
    memset(hdr, 0, sizeof(AIX_HDR));
    hdr->nsec = 1;
    hdr->nloop = 1;
    hdr->loop[0].w[0] = 0;
    hdr->loop[0].w[1] = 1;
    hdr->loop[0].w[2] = 0;
    hdr->loop[0].w[3] = 0;
    hdr->ntrk = 1;
}

s32 xb_aix_ParsePacketHeader(s32 len, u8 *p, AIX_PKT *ph) {
    u8 *q;

    if (len < 0x10) {
        return 0;
    }

    ph->id = AIX_BE32(p);
    q = p + 4;
    ph->size = AIX_BE32(q);
    q += 4;
    ph->trk = q[0];
    ph->ntrk = q[1];
    q += 2;
    ph->len = AIX_BE16(q);
    q += 2;
    ph->next = AIX_BE32(q);
    q += 4;

    if (q - p != 0x10) {
        xb_aixerr_CallErrFunc1("E2003043001 : Packet header parsing failed.");
        return -1;
    }

    return 0x10;
}

s32 xb_aix_ExecDemux(AIX_OBJ *aix) {
    SJ sj = aix->sjin;
    s32 n = aix->hdr.ntrk;
    s32 ret = -3;
    s32 i;
    s32 total;
    s32 s;
    s32 off;
    SJCK ck;
    SJCK ck2;
    SJCK ock;
    AIX_PKT ph;

    for (i = 0; i < n; i++) {
        SJ_GetChunk(sj, 1, 0x7FFFFFFF, &ck);

        if ((u32)ck.len < 0x10) {
            SJ_UngetChunk(sj, 1, &ck);
            return ret;
        }

        if (xb_aix_ParsePacketHeader(ck.len, (u8 *)ck.data, &ph) == 0) {
            SJ_UngetChunk(sj, 1, &ck);
            return ret;
        }

        total = ph.size + 8;

        if (ck.len < total) {
            SJ_UngetChunk(sj, 1, &ck);
            return ret;
        }

        if (ph.id == 0x41495845) { /* "AIXE" */
            SJ_SplitChunk(&ck, ph.size + 8, &ck, &ck2);
            SJ_PutChunk(sj, 0, &ck);
            SJ_UngetChunk(sj, 1, &ck2);

            if (SJ_GetNumData(sj, 1) <= 0) {
                aix->b4 = 0;
            }

            if (aix->b4 == 0) {
                aix->stat = 3;
            }

            return ret;
        }

        if (ph.trk >= aix->nsj) {
            xb_aixerr_CallErrFunc1("E2003043003 : Illegal track number.");
            SJ_UngetChunk(sj, 1, &ck);
            aix->stat = 4;
            return ret;
        }

        s = ph.len;

        if (SJ_GetNumData(aix->sj[ph.trk], 0) < s) {
            SJ_UngetChunk(sj, 1, &ck);
            return ret;
        }

        ret = ph.next;
        SJ_SplitChunk(&ck, total, &ck, &ck2);
        SJ_UngetChunk(sj, 1, &ck2);
        SJ_SplitChunk(&ck, 0x10, &ck, &ck2);
        SJ_PutChunk(sj, 0, &ck);

        if (ck2.len < s) {
            xb_aixerr_CallErrFunc1("E2003043004 : Illegal track length.");
            SJ_UngetChunk(sj, 1, &ck2);
            SJ_UngetChunk(sj, 1, &ck);
            aix->stat = 4;
            return ret;
        }

        for (off = 0; off < s; off += ock.len) {
            SJ_GetChunk(aix->sj[ph.trk], 0, ck2.len - off, &ock);
            memcpy(ock.data, ck2.data + off, ock.len);
            SJ_PutChunk(aix->sj[ph.trk], 1, &ock);
        }

        SJ_PutChunk(sj, 0, &ck2);
        aix->pos += ck2.len + 0x10;
    }

    return ret;
}

void xb_aix_ExecCopy(AIX_OBJ *aix) {
    SJ sj = aix->sjin;
    SJCK ck;
    SJCK ck2;
    SJCK ock;

    SJ_GetChunk(sj, 1, 0x7FFFFFFF, &ck);
    SJ_GetChunk(aix->sj[0], 0, ck.len, &ock);
    memcpy(ock.data, ck.data, ock.len);
    SJ_PutChunk(aix->sj[0], 1, &ock);
    SJ_SplitChunk(&ck, ock.len, &ck, &ck2);
    SJ_PutChunk(sj, 0, &ck);
    SJ_UngetChunk(sj, 1, &ck2);
    aix->pos += ock.len;
}

AIX_OBJ *xb_aix_Create(s32 nsj, SJ sjin, SJ *sjs) {
    AIX_OBJ *aix;

    sub_0016AA60();
    aix = xb_aix_AllocHandle(sjin, nsj, sjs);
    sub_0016AA70();
    return aix;
}

s32 xb_aix_DecodeHeader(s32 len, u8 *p, AIX_HDR *hdr) {
    s32 hsize;
    s32 i;
    u8 *q;

    if (len < 0x1800) {
        return -1;
    }

    if ((u32)AIX_BE32(p) != 0x41495846) { /* "AIXF" */
        xb_aix_ClearHandle(hdr);
        return 0;
    }

    q = p + 4;
    hsize = AIX_BE32(q);
    q += 4;

    if (memcmp(p + hsize + 2, "(c)CRI", 6) != 0) {
        return -1;
    }

    hdr->b0 = q[0];
    hdr->b1 = q[1];
    q += 2;
    hdr->rate = (f32)AIX_BE16(q);
    q += 2;
    hdr->d4 = AIX_BE32(q);
    q += 0xC;
    hdr->nsec = AIX_BE16(q);
    q += 8;

    for (i = 0; i < hdr->nsec; i++) {
        hdr->sec[i].a = AIX_BE32(q);
        hdr->sec[i].b = AIX_BE32(q + 4);
        hdr->sec[i].c = AIX_BE32(q + 8);
        hdr->sec[i].d = AIX_BE32(q + 12);
        q += 0x10;
    }

    hdr->nloop = (s8)q[0];
    q += 8;

    for (i = 0; i < hdr->nloop; i++) {
        hdr->loop[i].w[0] = AIX_BE16(q);
        hdr->loop[i].w[1] = AIX_BE16(q + 2);
        hdr->loop[i].w[2] = AIX_BE16(q + 4);
        hdr->loop[i].w[3] = AIX_BE16(q + 6);
        q += 8;
    }

    hdr->ntrk = q[0];
    q += 8;

    for (i = 0; i < hdr->ntrk; i++) {
        hdr->trk[i].value = AIX_BE32(q);
        hdr->trk[i].id = q[4];
        q += 8;
    }

    return hsize + 8;
}

void xb_aix_ExecHeader(AIX_OBJ *aix) {
    SJ sj = aix->sjin;
    SJCK ck;
    SJCK ck2;
    s32 r;

    SJ_GetChunk(sj, 1, 0x1800, &ck);
    r = xb_aix_DecodeHeader(ck.len, (u8 *)ck.data, &aix->hdr);

    if (r == -1) {
        SJ_UngetChunk(sj, 1, &ck);
        return;
    }

    if (r == 0) {
        aix->mode = 1;
    } else if (r == ck.len) {
        aix->mode = 0;
    } else {
        xb_aixerr_CallErrFunc1("E2003043002 : Illegal header size.");
        SJ_UngetChunk(sj, 1, &ck);
        aix->stat = 4;
        return;
    }

    SJ_SplitChunk(&ck, r, &ck, &ck2);
    SJ_PutChunk(sj, 0, &ck);
    SJ_UngetChunk(sj, 1, &ck2);
    aix->pos += r;
    aix->stat = 2;
}

void xb_aix_ExecHndl(AIX_OBJ *aix) {
    if (aix->used != 1) {
        return;
    }

    if (aix->stat == 1) {
        xb_aix_ExecHeader(aix);
    } else if (aix->stat == 2 && aix->b3 == 0) {
        switch (aix->mode) {
        case 0:
            if (xb_aix_ExecDemux(aix) == -1) {
                xb_aix_ExecDemux(aix);
            }

            break;

        case 1:
            xb_aix_ExecCopy(aix);
            break;
        }
    }
}

void xb_aix_ExecHndlLocked(AIX_OBJ *aix) {
    sub_0016AA60();
    xb_aix_ExecHndl(aix);
    sub_0016AA70();
}

void xb_aix_ExecServer(void) {
    AIX_OBJ *aix;

    for (aix = (AIX_OBJ *)aix_obj; aix < (AIX_OBJ *)aix_obj + 4; aix++) {
        xb_aix_ExecHndlLocked(aix);
    }
}

s32 xb_aix_SetTrackMode(s32 mode, AIX_CHVOL *pair) {
    switch (mode) {
    case 0:
        pair[0].ch = 0;
        pair[0].vol = 0;
        return 1;

    case 1:
        pair[0].ch = 1;
        pair[0].vol = 0;
        return 1;

    case 2:
        pair[0].ch = 4;
        pair[0].vol = 0;
        return 1;

    case 3:
        pair[0].ch = 5;
        pair[0].vol = 0;
        return 1;

    case 4:
        pair[0].ch = 2;
        pair[0].vol = 0;
        return 1;

    case 5:
        pair[0].ch = 3;
        pair[0].vol = 0;
        return 1;

    case 6:
        pair[0].ch = 0;
        pair[1].ch = 1;
        pair[1].vol = 0;
        pair[0].vol = 0;
        return 2;

    case 7:
        pair[0].ch = 4;
        pair[1].ch = 5;
        pair[1].vol = 0;
        pair[0].vol = 0;
        return 2;

    case 8:
        pair[0].ch = 2;
        pair[1].ch = 3;
        pair[1].vol = 0;
        pair[0].vol = 0;
        return 2;
    }

    return 1;
}

void xb_aix_ConfigTrack(void *adxt, s32 mode) {
    AIX_CHVOL pair[8];
    AIX_OUTVOL arg;

    arg.nch = xb_aix_SetTrackMode(mode, pair);
    arg.pair = pair;
    xb_aixp_SetTrackSpeakerVol(adxt, &arg);
}
