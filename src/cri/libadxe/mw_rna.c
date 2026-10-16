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

extern void sub_001725A0(const char *msg);
extern void ADXCRS_Lock(void);
extern void ADXCRS_Unlock(void);

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
