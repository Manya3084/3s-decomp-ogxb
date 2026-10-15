/* Disp_Copyright, retail sf33rd.xbe 0x9ABAE.
 * Country is the byte at 0x7A8748. SSPutStrPro is 0xE9C82 and is not named yet.
 */

#include "types.h"

extern u8 Country;
extern s32 SSPutStrPro(s32 kind, s32 x, s32 y, s32 color, s32 alpha, const char *text);

void Disp_Copyright(void) {
    s32 xres;
    u8 country = Country;

    if (country == 0 || country > 8) {
        return;
    }

    if (country <= 3 || country >= 7) {
        SSPutStrPro(1, 386, 208, 9, -1, "@CAPCOM CO., LTD. 1999, 2004 ALL RIGHTS RESERVED.");
        return;
    }

    xres = SSPutStrPro(1, 386, 212, 9, -1, "@CAPCOM U.S.A., INC. 1999, 2004 ALL RIGHTS RESERVED.");
    SSPutStrPro(0, xres, 202, 9, -1, "@CAPCOM CO., LTD. 1999, 2004,");
}
