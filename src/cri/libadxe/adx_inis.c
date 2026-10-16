/* adxt_exec_main_thrd 0x1684C0.
 *
 * Ignores its object, calls LSC_ExecServer, and returns 0.
 */

#include "types.h"

extern void LSC_ExecServer(void);

s32 adxt_exec_main_thrd(void *object) {
    (void)object;
    LSC_ExecServer();
    return 0;
}
