/* mwRnaSetNumChan 0x16B730.
 *
 * A null handle reports E1205. A channel count above the byte at +2
 * reports E1211. Otherwise the count is stored at +3 and this
 * tail-calls the function at vtable +0x1C of the object at +0x50.
 * The argument is the stored byte, sign-extended. 0x1725A0 is
 * xb_mwerr_CallErrFunc. ADXRNA_SetNumChan tail-jumps here. 0x16BBFE also calls
 * it.
 */

#include "types.h"

typedef void (*MwVfunc)(void *obj, s32 arg);
typedef void *(*MwOpenFn)(s32 nch);
typedef s32 (*MwRetFn)(void *obj);

typedef struct MwSjck {
    s8 *data;
    s32 len;
} MwSjck;

typedef struct MwSj MwSj;

typedef struct MwSjVtbl {
    void *slot[6];
    void (*GetChunk)(MwSj *sj, s32 id, s32 nbyte, MwSjck *ck);
    void (*UngetChunk)(MwSj *sj, s32 id, MwSjck *ck);
    void (*PutChunk)(MwSj *sj, s32 id, MwSjck *ck);
} MwSjVtbl;

struct MwSj {
    MwSjVtbl *vtbl;
};

extern void xb_mwerr_CallErrFunc(const char *msg);
extern void sub_0016AA60(void);
extern void sub_0016AA70(void);
extern s32 xb_mwrna_WriteChannel(void *rna, s32 index, s32 pos, s8 *data, s32 count);
extern void SJ_SplitChunk(MwSjck *ck, s32 nbyte, MwSjck *ck1, MwSjck *ck2);
extern double pow(double base, double exponent);
extern void *xb_mwrna_Alloc(void);
extern void xb_mwrna_InitHandle(void *rna);
extern void mwRnaSetBitPerSmpl(void *rna, s32 bps);
extern void mwRnaSetSfreq(void *rna, s32 sfreq);
extern void *dat_007A5A9C; /* 0x7A5A9C */
extern s32 dat_00CE48E0; /* 0xCE48E0 */
extern s32 dat_00CE48E4; /* 0xCE48E4 */

void mwRnaSetNumChan(void *rna, s32 nch) {
    u8 *bytes;
    void *obj;
    void **vtbl;

    if (rna == 0) {
        xb_mwerr_CallErrFunc("E1205:Illegal parameter (MWRNA=NULL)");
        return;
    }

    bytes = rna;
    if (nch > bytes[2]) {
        xb_mwerr_CallErrFunc("E1211:mwRnaSetNumChan Illegal parameter(NCH>MAXNCH)");
        return;
    }

    bytes[3] = (u8)nch;
    obj = *(void **)(bytes + 0x50);
    vtbl = *(void ***)obj;
    ((MwVfunc)vtbl[7])(obj, (s32)(s8)bytes[3]);
}

/* mwlRnaAddWrPos 0x16B240.
 *
 * The bytes take the object in esi. A null dword in the list at +0x30
 * reports E1213 and the loop continues. The count is the byte at +3.
 * The dword at +0x54 is added into +0x4C and +0x64. The remainder of
 * +0x44 plus that dword, divided by +0x40, is stored at +0x44. Then
 * +0x54 is cleared. The calls pass a stack slot to ADXCRS_Lock and
 * ADXCRS_Unlock. Those tail jumps ignore it. Callers are 0x16BCA1,
 * 0x16BE3D, and 0x16BFBC.
 */

void mwlRnaAddWrPos(void *rna) {
    u8 *bytes;
    s32 index;
    s32 added;
    s32 sum;

    bytes = rna;
    sub_0016AA60();
    index = 0;
    while (index < bytes[3]) {
        if (*(s32 *)(bytes + 0x30 + index * 4) == 0) {
            xb_mwerr_CallErrFunc("E1213:mwlRnaAddWrPos rna->sj=NULL");
        }
        index += 1;
    }

    added = *(s32 *)(bytes + 0x54);
    sum = (s32)((u32)*(s32 *)(bytes + 0x44) + (u32)added);
    *(s32 *)(bytes + 0x44) = sum % *(s32 *)(bytes + 0x40);
    *(s32 *)(bytes + 0x4C) = (s32)((u32)*(s32 *)(bytes + 0x4C) + (u32)added);
    *(s32 *)(bytes + 0x54) = 0;
    *(s32 *)(bytes + 0x64) = (s32)((u32)*(s32 *)(bytes + 0x64) + (u32)added);
    sub_0016AA70();
}

/* mwlRnaStartTrans 0x16B310.
 *
 * The bytes take the object in eax. The scanner start at 0x16B4A0 is
 * the last byte of sar eax, 3. The ret is at 0x16B4F2. A null SJ at
 * +0x30 reports E1212 and the call still happens. Each channel gets a
 * chunk with id 1. The length uses the first chunk, or the smaller of
 * the first two when the byte at +3 is not 1. A positive count splits
 * that chunk, puts id 0, ungets id 1, stores the count at +0x54, and
 * returns it. Any other count ungets id 1 and returns 0. 0x16B190
 * takes the object in edi, the count in esi, and the data pointer in
 * edx. It stays unnamed. The only caller is 0x16BEAD.
 */

s32 mwlRnaStartTrans(void *rna) {
    u8 *bytes;
    MwSj *sj;
    MwSjck chunk[4];
    MwSjck ck1;
    MwSjck ck2;
    s32 bps;
    s32 unit;
    s32 aligned;
    s32 nch;
    s32 index;
    s32 len;
    s32 room;
    s32 count;
    s32 got;
    s32 nbytes;

    bytes = rna;
    bps = *(s32 *)(bytes + 8);
    unit = (s32)((u32)(0x20 / bps) << 3);
    room = (s32)((u32)*(s32 *)(bytes + 0x40) - (u32)*(s32 *)(bytes + 0x4C));
    aligned = (s32)((u32)(room / unit) * (u32)unit);
    nch = bytes[3];
    index = 0;
    while (index < nch) {
        sj = *(MwSj **)(bytes + 0x30 + index * 4);
        if (sj == 0) {
            xb_mwerr_CallErrFunc("E1212:mwlRnaStartTrans rna->sj=NULL");
        }
        nbytes = (s32)((u32)bps * (u32)aligned) / 8;
        sj->vtbl->GetChunk(sj, 1, nbytes, &chunk[index]);
        index += 1;
    }

    len = chunk[0].len;
    if (nch != 1) {
        if (len >= chunk[1].len) {
            len = chunk[1].len;
        }
    }
    len = (s32)((u32)(len / bps) << 3);
    if (len >= aligned) {
        len = aligned;
    }
    room = (s32)((u32)*(s32 *)(bytes + 0x40) - (u32)*(s32 *)(bytes + 0x44));
    if (len >= room) {
        len = room;
    }
    count = (s32)((u32)(len / unit) * (u32)unit);
    if (count > 0) {
        if (nch == 0) {
            *(s32 *)(bytes + 0x54) = 0;
            return 0;
        }
        index = 0;
        while (index < bytes[3]) {
            dat_00CE48E0 = 0;
            got = xb_mwrna_WriteChannel(rna, index, *(s32 *)(bytes + 0x44), chunk[index].data, count);
            dat_00CE48E4 = 0;
            nbytes = (s32)((u32)bps * (u32)got) / 8;
            SJ_SplitChunk(&chunk[index], nbytes, &ck1, &ck2);
            sj = *(MwSj **)(bytes + 0x30 + index * 4);
            sj->vtbl->PutChunk(sj, 0, &ck1);
            sj->vtbl->UngetChunk(sj, 1, &ck2);
            index += 1;
        }
        *(s32 *)(bytes + 0x54) = got;
        return got;
    }

    index = 0;
    while (index < nch) {
        sj = *(MwSj **)(bytes + 0x30 + index * 4);
        if (sj == 0) {
            xb_mwerr_CallErrFunc("E1212:mwlRnaStartTrans rna->sj=NULL");
        }
        sj->vtbl->UngetChunk(sj, 1, &chunk[index]);
        index += 1;
    }
    return 0;
}

/* mwRnaCalcSfreq 0x16BA40.
 *
 * One stack argument. A null handle reports E1205 and returns 0.
 * The cents value is the dword at +0x98 times 100, plus the dword
 * at +0x9C. The string does not say which field is transpose.
 * That sum is multiplied by the qword 1/1200 at 0x2E0800. The bytes
 * leave the qword 2.0 at 0x2686F0 in ST1 and call 0x17787C. That
 * helper is the MSVC __CIpow stub and stays unnamed. The C call is
 * the result, pow(2.0, cents/1200). The bytes then multiply by the
 * dword at +0xC. A result greater than the qword 2147483647.0 at
 * 0x2E07F8 pops the float, reports E1215, and returns 0x7FFFFFFF.
 * Otherwise this pops esi and tail-jumps to _ftol at 0x175B40, which
 * reads ST0. The C passes the value as an argument. Callers are
 * 0x168004 and 0x16C0BF. The body at 0x16BAB0 is mwRnaCreate.
 */

s32 mwRnaCalcSfreq(void *rna) {
    u8 *bytes;
    s32 cents;
    double freq;

    if (rna == 0) {
        xb_mwerr_CallErrFunc("E1205:Illegal parameter (MWRNA=NULL)");
        return 0;
    }

    bytes = rna;
    cents = (s32)((u32)*(s32 *)(bytes + 0x98) * 100u + (u32)*(s32 *)(bytes + 0x9C));
    freq = pow(2.0, (double)cents * (1.0 / 1200.0));
    freq = freq * (double)*(s32 *)(bytes + 0xC);
    if (freq > 2147483647.0) {
        xb_mwerr_CallErrFunc("E1215:mwRnaCalcSfreq Illegal parameter(trnsps or(and) detune is too big.)");
        return 0x7FFFFFFF;
    }
    return (s32)freq;
}

/* mwRnaCreate 0x16BAB0.
 *
 * Two stack arguments. A channel count outside 1..4 reports E1201
 * and returns 0. A null SJ list, or a null entry, reports E1202 and
 * returns 0. 0x16B130 returning null reports E1203 and returns 0.
 * The count is stored at +2 and +3, and the SJ pointers are copied
 * to +0x30. The function pointer at offset 0x14 of the object loaded
 * from 0x7A5A9C is called with the count. A null return is stored at
 * +0x50, reports E1204, and returns 0. The instance is not freed.
 * Otherwise this locks, calls 0x16B0C0 with the object in eax, calls
 * 0x16B780 with 0x10, calls 0x16B7D0 with 0xAC44, and calls
 * mwRnaSetNumChan with the byte at +3. Those two callees stay
 * unnamed. The function at vtable +0x18 of the object at +0x50 is
 * called with that object. The return is stored at +0x40, byte +0
 * becomes 1, and this unlocks and returns the instance. The calls
 * pass a stack slot to ADXCRS_Lock and ADXCRS_Unlock. Those tail
 * jumps ignore it. The only reference is the tail jump at
 * ADXRNA_Create. The jmp at 0x16BAAB ends on this address.
 */

void *mwRnaCreate(void *sjo, s32 maxnch) {
    u8 *bytes;
    void **list;
    void **table;
    void **vtbl;
    void *rna;
    void *snd;
    s32 index;

    if (maxnch < 1 || maxnch > 4) {
        xb_mwerr_CallErrFunc("E1201:mwRnaCreate Illegal parameter (MAXNCH)");
        return 0;
    }

    if (sjo == 0) {
        xb_mwerr_CallErrFunc("E1202:mwRnaCreate Illegal parameter (SJ)");
        return 0;
    }

    list = sjo;
    index = 0;
    while (index < maxnch) {
        if (list[index] == 0) {
            xb_mwerr_CallErrFunc("E1202:mwRnaCreate Illegal parameter (SJ)");
            return 0;
        }
        index += 1;
    }

    rna = xb_mwrna_Alloc();
    if (rna == 0) {
        xb_mwerr_CallErrFunc("E1203:mwRnaCreate Not enough instance (MWRNA)");
        return 0;
    }

    bytes = rna;
    bytes[3] = (u8)maxnch;
    bytes[2] = (u8)maxnch;
    index = 0;
    while (index < maxnch) {
        *(void **)(bytes + 0x30 + index * 4) = list[index];
        index += 1;
    }

    table = dat_007A5A9C;
    snd = ((MwOpenFn)table[5])(maxnch);
    *(void **)(bytes + 0x50) = snd;
    if (snd == 0) {
        xb_mwerr_CallErrFunc("E1204:mwRnaCreate Cannot open MWSND");
        return 0;
    }

    sub_0016AA60();
    xb_mwrna_InitHandle(rna);
    mwRnaSetBitPerSmpl(rna, 0x10);
    mwRnaSetSfreq(rna, 0xAC44);
    mwRnaSetNumChan(rna, bytes[3]);
    vtbl = *(void ***)snd;
    *(s32 *)(bytes + 0x40) = ((MwRetFn)vtbl[6])(snd);
    bytes[0] = 1;
    sub_0016AA70();
    return rna;
}
