/* mw_err.c: the MW error hook, 0x172550 and 0x1725A0. The hook is the
 * function/object pair at 0x7A60AC/0x7A60B0 and the formatted message is the
 * 0x100-byte buffer at 0xCD0580. */

#include "types.h"

#include <stdarg.h>
#include <stdio.h>
#include <string.h>

extern void (*mwerr_func)(void *obj, char *msg); /* mwerr_func is 0x7A60AC */
extern void *mwerr_obj; /* mwerr_obj is 0x7A60B0 */
extern char mwerr_msg[0x100]; /* mwerr_msg is 0xCD0580 */

void xb_mwerr_EntryErrFunc(void (*func)(void *obj, char *msg), void *obj) {
    if (func == 0) {
        mwerr_func = 0;
        mwerr_obj = 0;
    } else {
        mwerr_func = func;
        mwerr_obj = obj;
    }

    memset(mwerr_msg, 0, sizeof(mwerr_msg));
}

void xb_mwerr_CallErrFunc(const char *fmt, ...) {
    va_list ap;

    va_start(ap, fmt);
    vsprintf(mwerr_msg, fmt, ap);
    va_end(ap);

    if (mwerr_func != 0) {
        mwerr_func(mwerr_obj, mwerr_msg);
    }
}
