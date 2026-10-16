/* adxt_exec_main_thrd 0x1684C0. adxt_exec_tsvr 0x1684D0.
 * adxt_exec_fssvr 0x1684E0.
 *
 * Each ignores its object and returns 0. main_thrd calls
 * LSC_ExecServer. tsvr calls ADXT_ExecServer. fssvr calls
 * ADXT_ExecFsSvr.
 */

#include "types.h"

extern void LSC_ExecServer(void);
extern void ADXT_ExecServer(void);
extern void ADXT_ExecFsSvr(void);

s32 adxt_exec_main_thrd(void *object) {
    (void)object;
    LSC_ExecServer();
    return 0;
}

s32 adxt_exec_tsvr(void *object) {
    (void)object;
    ADXT_ExecServer();
    return 0;
}

s32 adxt_exec_fssvr(void *object) {
    (void)object;
    ADXT_ExecFsSvr();
    return 0;
}
