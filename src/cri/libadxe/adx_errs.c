/* ADXERR_CallErrFunc1, retail sf33rd.xbe 0x168E10.
 * adxerr_msg is 0xCE8DA0. The callback is 0x7A55AC and its object is 0x7A55B0.
 * The copy length immediate is 0xFF. The function then tail-calls SVM_CallErr.
 */

#include "types.h"

#include <string.h>

extern char adxerr_msg[];
extern void (*adxerr_func)(void *object, char *msg);
extern void *adxerr_obj;
extern void SVM_CallErr(const char *format, ...);

void ADXERR_CallErrFunc1(const char *msg) {
    strncpy(adxerr_msg, msg, 0xFF);

    if (adxerr_func != 0) {
        adxerr_func(adxerr_obj, adxerr_msg);
    }

    SVM_CallErr(adxerr_msg);
}
