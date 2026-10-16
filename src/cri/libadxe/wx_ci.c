/* wxCiGetFileSize 0x169310.
 *
 * A null name reports E0092901 and returns 0. Otherwise the name is
 * copied into a 0x104 buffer and the size comes from 0x1692E0.
 * 0x168FE0 and 0x169190 stay unnamed. The only reference is the
 * pointer at 0x43C900, eight bytes into the device table at 0x43C8F8.
 */

#include "types.h"

extern void sub_00169190(const char *fname, const char *msg);
extern void sub_00168FE0(char *dst, const char *src);
extern s32 sub_001692E0(char *path);

s32 wxCiGetFileSize(const char *fname) {
    char path[0x104];

    if (fname == 0) {
        sub_00169190(fname, "E0092901:fname is null.(wxCiGetFileSize)");
        return 0;
    }

    sub_00168FE0(path, fname);
    return sub_001692E0(path);
}
