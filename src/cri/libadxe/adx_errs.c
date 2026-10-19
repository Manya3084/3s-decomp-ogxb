/* ADXERR_CallErrFunc1 0x168E10, ADXERR_CallErrFunc2 0x168E50,
 * ADXERR_ItoA 0x168EB0, ADXERR_ItoA2 0x168F20.
 * adxerr_msg is 0xCE8DA0. The callback is 0x7A55AC and its object is 0x7A55B0.
 * Both copies use length 0xFF. ItoA then copies out of the buffer at 0x7A558C.
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

void ADXERR_CallErrFunc2(const char *msg, const char *detail) {
    strncpy(adxerr_msg, msg, 0xFF);
    strncat(adxerr_msg, detail, 0xFF);

    if (adxerr_func != 0) {
        adxerr_func(adxerr_obj, adxerr_msg);
    }

    SVM_CallErr(adxerr_msg);
}

/* The first loop stores remainders into str. The digits that are copied back
 * come from this other buffer, which this function does not fill.
 */
extern char adxerr_digit_buf[];

void ADXERR_ItoA(s32 value, char *str, s32 base) {
    s32 i;
    s32 len;

    for (i = 0; i < 32; i++) {
        str[i] = (char)(value % 10);
        value /= 10;

        if (value == 0) {
            str[i] = 0;
            break;
        }
    }

    len = (s32)strlen(adxerr_digit_buf);

    if (len >= base - 1) {
        len = base - 1;
    }

    for (i = 0; i < len; i++) {
        str[i] = adxerr_digit_buf[len - i - 1];
    }

    str[i] = 0;
}

void ADXERR_ItoA2(s32 arg0, s32 arg1, char *str, s32 base) {
    s32 len;

    ADXERR_ItoA(arg0, str, base);
    len = (s32)strlen(str);
    strncat(str, " ", (size_t)(base - len - 1));
    len = (s32)strlen(str);
    ADXERR_ItoA(arg1, &str[len], 4 - len);
}

/* ADXERR_Init 0x168DF0 (ADXERR_Finish is folded with it). */
void ADXERR_Init(void) {
    memset(adxerr_msg, 0, 0x100);
    adxerr_func = 0;
    adxerr_obj = 0;
}
