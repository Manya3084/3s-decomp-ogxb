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
