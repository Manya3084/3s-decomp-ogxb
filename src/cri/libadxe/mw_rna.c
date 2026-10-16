/* mwRnaSetNumChan 0x16B730.
 *
 * A null handle reports E1205. A channel count above the byte at +2
 * reports E1211. Otherwise the count is stored at +3 and this
 * tail-calls the function at vtable +0x1C of the object at +0x50.
 * The argument is the stored byte, sign-extended. 0x1725A0 stays
 * unnamed. ADXRNA_SetNumChan tail-jumps here. 0x16BBFE also calls it.
 */

#include "types.h"

typedef void (*MwVfunc)(void *obj, s32 arg);

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

extern void sub_001725A0(const char *msg);
extern void ADXCRS_Lock(void);
extern void ADXCRS_Unlock(void);
extern s32 sub_0016B190(void *rna, s32 index, s32 pos, s8 *data, s32 count);
extern void SJ_SplitChunk(MwSjck *ck, s32 nbyte, MwSjck *ck1, MwSjck *ck2);
extern s32 dat_00CE48E0; /* 0xCE48E0 */
extern s32 dat_00CE48E4; /* 0xCE48E4 */

void mwRnaSetNumChan(void *rna, s32 nch) {
    u8 *bytes;
    void *obj;
    void **vtbl;

    if (rna == 0) {
        sub_001725A0("E1205:Illegal parameter (MWRNA=NULL)");
        return;
    }

    bytes = rna;
    if (nch > bytes[2]) {
        sub_001725A0("E1211:mwRnaSetNumChan Illegal parameter(NCH>MAXNCH)");
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
    ADXCRS_Lock();
    index = 0;
    while (index < bytes[3]) {
        if (*(s32 *)(bytes + 0x30 + index * 4) == 0) {
            sub_001725A0("E1213:mwlRnaAddWrPos rna->sj=NULL");
        }
        index += 1;
    }

    added = *(s32 *)(bytes + 0x54);
    sum = (s32)((u32)*(s32 *)(bytes + 0x44) + (u32)added);
    *(s32 *)(bytes + 0x44) = sum % *(s32 *)(bytes + 0x40);
    *(s32 *)(bytes + 0x4C) = (s32)((u32)*(s32 *)(bytes + 0x4C) + (u32)added);
    *(s32 *)(bytes + 0x54) = 0;
    *(s32 *)(bytes + 0x64) = (s32)((u32)*(s32 *)(bytes + 0x64) + (u32)added);
    ADXCRS_Unlock();
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
            sub_001725A0("E1212:mwlRnaStartTrans rna->sj=NULL");
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
            got = sub_0016B190(rna, index, *(s32 *)(bytes + 0x44), chunk[index].data, count);
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
            sub_001725A0("E1212:mwlRnaStartTrans rna->sj=NULL");
        }
        sj->vtbl->UngetChunk(sj, 1, &chunk[index]);
        index += 1;
    }
    return 0;
}
