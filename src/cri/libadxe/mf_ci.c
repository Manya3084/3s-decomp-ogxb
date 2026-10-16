/* mfCiOpen 0x16AC30.
 *
 * A null name reports E01100301. A non-zero rw reports E01100302.
 * A failed alloc reports E01100303. Each of those returns 0. Otherwise
 * the name is copied to +0x1C and 0x16ABF0 finishes the handle.
 * 0x16AA90, 0x16ABB0, and 0x16ABF0 stay unnamed. The only reference
 * is the pointer at 0x43C970.
 */

#include "types.h"

extern void sub_0016AA90(void *obj, const char *msg);
extern void *sub_0016ABB0(void);
extern void sub_0016ABF0(void *hn);

void *mfCiOpen(const char *fname, void *arg1, s32 rw) {
    void *hn;
    char *dst;
    const char *src;
    char c;

    (void)arg1;

    if (fname == 0) {
        sub_0016AA90((void *)fname, "E01100301:fname is null.(mfCiOpen)");
        return 0;
    }

    if (rw != 0) {
        sub_0016AA90(0, "E01100302:rw is illigal.(mfCiOpen)");
        return 0;
    }

    hn = sub_0016ABB0();
    if (hn == 0) {
        sub_0016AA90(0, "E01100303:not enough handle resource.(mfCiOpen)");
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

    sub_0016ABF0(hn);
    return hn;
}
