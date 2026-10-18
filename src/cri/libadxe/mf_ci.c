/* mfCiOpen 0x16AC30. mfCiReqRd 0x16AD50.
 * mfci_get_adr_size 0x16AAC0.
 *
 * A null name reports E01100301. A non-zero rw reports E01100302.
 * A failed alloc reports E01100303. Each of those returns 0. Otherwise
 * the name is copied to +0x1C and 0x16ABF0 finishes the handle.
 * 0x16AA90, 0x16ABB0, and 0x16ABF0 are mfci_call_errfn, mfci_alloc, and
 * xb_mfci_SetupHandle. The only reference
 * is the pointer at 0x43C970.
 *
 * ReqRd reports E01100307, E01100308, and E01100309. A zero sector
 * count stores stat 1 before the stat 2 test. The copy comes from
 * mfci_get_adr_size, and the bytes past that size are cleared. The
 * only reference is the pointer at 0x43C980.
 *
 * get_adr_size is interior. The scanner span starts at 0x16AA90.
 * A name that is not 17 bytes reports E01100308. A name whose ninth
 * byte is not '.' reports E01100309. Both checks fall through.
 * The first hex field is the address and the second is the size.
 * 0x16AAB0 tail-jumps to strtoul. The message buffer is 0xCE4900.
 */

#include "types.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern void mfci_call_errfn(void *obj, const char *msg);
extern void *mfci_alloc(void);
extern void xb_mfci_SetupHandle(void *hn);
extern char mfci_msg[]; /* 0xCE4900 */

void *mfci_get_adr_size(char *fname, s32 *size);
extern void sub_0016AA60(void);
extern void sub_0016AA70(void);

typedef struct {
    u8 used;
    u8 stat;
    u8 pad[2];
    s32 sctlen;
    s32 unk8;
    s32 totalsct;
    s32 ofst;
    s32 unk14;
    s32 reqsct;
    char fname[0x14];
    s32 byte_ofs;
    s32 nbytes;
} MFCI_OBJ;

#if defined(__i386__)
_Static_assert(sizeof(MFCI_OBJ) == 0x38, "MFCI_OBJ");
_Static_assert(offsetof(MFCI_OBJ, stat) == 1, "stat");
_Static_assert(offsetof(MFCI_OBJ, sctlen) == 4, "sctlen");
_Static_assert(offsetof(MFCI_OBJ, unk8) == 8, "unk8");
_Static_assert(offsetof(MFCI_OBJ, totalsct) == 0x0C, "totalsct");
_Static_assert(offsetof(MFCI_OBJ, ofst) == 0x10, "ofst");
_Static_assert(offsetof(MFCI_OBJ, unk14) == 0x14, "unk14");
_Static_assert(offsetof(MFCI_OBJ, reqsct) == 0x18, "reqsct");
_Static_assert(offsetof(MFCI_OBJ, fname) == 0x1C, "fname");
_Static_assert(offsetof(MFCI_OBJ, byte_ofs) == 0x30, "byte_ofs");
_Static_assert(offsetof(MFCI_OBJ, nbytes) == 0x34, "nbytes");
#endif

void *mfCiOpen(const char *fname, void *arg1, s32 rw) {
    void *hn;
    char *dst;
    const char *src;
    char c;

    (void)arg1;

    if (fname == 0) {
        mfci_call_errfn((void *)fname, "E01100301:fname is null.(mfCiOpen)");
        return 0;
    }

    if (rw != 0) {
        mfci_call_errfn(0, "E01100302:rw is illigal.(mfCiOpen)");
        return 0;
    }

    hn = mfci_alloc();
    if (hn == 0) {
        mfci_call_errfn(0, "E01100303:not enough handle resource.(mfCiOpen)");
        return 0;
    }

    dst = (char *)hn + 0x1C;
    src = fname;
    do {
        c = *src;
        *dst = c;
        src += 1;
        dst += 1;
    } while (c != 0);

    xb_mfci_SetupHandle(hn);
    return hn;
}

s32 mfCiReqRd(MFCI_OBJ *hn, s32 nsct, void *buf) {
    s32 remain;
    s32 count;
    s32 byte_ofs;
    s32 nbytes;
    s32 limit;
    s32 marked;
    void *base;

    if (hn == 0) {
        mfci_call_errfn(hn, "E01100307:handl is null.");
        return 0;
    }

    if (nsct < 0) {
        mfci_call_errfn(hn, "E01100308:nsct < 0.(mfCiReqRd)");
        return 0;
    }

    if (buf == 0) {
        mfci_call_errfn(hn, "E01100309:buf is null.(mfCiReqRd)");
        return 0;
    }

    if (nsct == 0) {
        hn->stat = 1;
        return 0;
    }

    if (hn->stat == 2) {
        return 0;
    }

    sub_0016AA60();
    remain = hn->totalsct - hn->ofst;
    hn->unk14 = 0;
    count = nsct;
    if (nsct >= remain) {
        count = remain;
    }

    byte_ofs = hn->sctlen * hn->ofst;
    nbytes = hn->sctlen * count;
    hn->reqsct = count;
    if (nbytes == 0) {
        hn->stat = 1;
        sub_0016AA70();
        return 0;
    }

    hn->nbytes = nbytes;
    hn->byte_ofs = byte_ofs;
    hn->stat = 2;
    base = mfci_get_adr_size(hn->fname, &limit);
    marked = nbytes;
    if (nbytes > limit - byte_ofs) {
        marked = limit - byte_ofs;
    }

    sub_0016AA70();
    memcpy(buf, (u8 *)base + byte_ofs, (size_t)nbytes);
    memset((u8 *)buf + marked, 0, (size_t)(nbytes - marked));
    sub_0016AA60();
    hn->unk14 = hn->reqsct * hn->sctlen;
    hn->ofst += hn->reqsct;
    hn->stat = 1;
    sub_0016AA70();
    return hn->reqsct;
}

void *mfci_get_adr_size(char *fname, s32 *size) {
    char *end;
    unsigned long adr;

    if (strlen(fname) != 17) {
        sprintf(mfci_msg, "E01100308:length of '%s' is not 17 bytes.(mfci_get_adr_size)", fname);
        mfci_call_errfn(0, mfci_msg);
    }

    if (fname[8] != '.') {
        sprintf(mfci_msg, "E01100309:illegal file name format '%s'(mfci_get_adr_size)", fname);
        mfci_call_errfn(0, mfci_msg);
    }

    adr = strtoul(fname, &end, 16);
    if (*end != 0) {
        end += 1;
    }

    if (size != 0) {
        *size = (s32)strtoul(end, &end, 16);
    }

    return (void *)adr;
}
