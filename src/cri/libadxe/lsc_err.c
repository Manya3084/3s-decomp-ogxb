/* LSC_EntryErrFunc 0x172460. LSC_CallErrFunc 0x172490.
 *
 * lsc_err_func is 0x7A60A4. lsc_err_obj is 0x7A60A8.
 * lsc_err_msg is 0xCD0680. The formatter is the vsprintf SVM_CallErr
 * calls at 0x1764D2. That function stays unnamed.
 */

#include "types.h"

#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>

extern void (*lsc_err_func)(void *obj, char *msg); /* 0x7A60A4 */
extern void *lsc_err_obj; /* 0x7A60A8 */
extern char lsc_err_msg[]; /* 0xCD0680 */

void LSC_EntryErrFunc(void (*func)(void *obj, char *msg), void *obj) {
    if (func == NULL) {
        lsc_err_func = NULL;
        lsc_err_obj = NULL;
        return;
    }

    lsc_err_func = func;
    lsc_err_obj = obj;
}

void LSC_CallErrFunc(const char *format, ...) {
    va_list args;

    va_start(args, format);
    vsprintf(lsc_err_msg, format, args);
    va_end(args);

    if (lsc_err_func != NULL) {
        lsc_err_func(lsc_err_obj, lsc_err_msg);
    }
}
