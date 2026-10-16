/* LSC_EntryErrFunc 0x172460.
 *
 * lsc_err_func is 0x7A60A4. lsc_err_obj is 0x7A60A8.
 */

#include "types.h"

#include <stddef.h>

extern void (*lsc_err_func)(void *obj, char *msg); /* 0x7A60A4 */
extern void *lsc_err_obj; /* 0x7A60A8 */

void LSC_EntryErrFunc(void (*func)(void *obj, char *msg), void *obj) {
    if (func == NULL) {
        lsc_err_func = NULL;
        lsc_err_obj = NULL;
        return;
    }

    lsc_err_func = func;
    lsc_err_obj = obj;
}
