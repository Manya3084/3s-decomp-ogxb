/* main, retail sf33rd.xbe 0x1204A.
 * mainXapiStartup calls this with three zeros after _cinit, then
 * XapiBootToDash. 0x11E67, 0x11C0E, and 0xC86E7 stay unnamed.
 * 0x4616AC and 0x43FE58 are cleared on entry. Nothing else in the
 * image references 0x43FE58.
 */

#include "types.h"

extern s32 dword_4616AC;
extern s32 dword_43FE58;
extern s32 sub_00011E67(void);
extern s32 sub_00011C0E(void);
extern void sub_000C86E7(void);

s32 main(s32 argc, char **argv, char **envp) {
    (void)argc;
    (void)argv;
    (void)envp;

    if (sub_00011E67() < 0) {
        return 0;
    }

    dword_4616AC = 0;
    dword_43FE58 = 0;

    for (;;) {
        if (dword_43FE58 != 0) {
            dword_4616AC = sub_00011C0E() == 0;
        }

        sub_000C86E7();
    }
}
