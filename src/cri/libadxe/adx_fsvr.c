/* ADXT_ExecFsSvr 0x171EF0.
 *
 * A non-zero adxt_fssvr_enter_cnt tail-jumps to ADXCRS_Unlock.
 * After the first cvFsExecServer the counter becomes 5. This build
 * does not call SRD_ExecServer or a second cvFsExecServer.
 */

#include "types.h"

extern s32 adxt_fssvr_enter_cnt; /* 0x7A6098 */

extern void ADXCRS_Lock(void);
extern void ADXCRS_Unlock(void);
extern void ADXSTM_ExecServer(void);
extern void cvFsExecServer(void);
extern void ADXF_ExecServer(void);

void ADXT_ExecFsSvr(void) {
    ADXCRS_Lock();

    if (adxt_fssvr_enter_cnt != 0) {
        ADXCRS_Unlock();
        return;
    }

    adxt_fssvr_enter_cnt = 1;
    ADXCRS_Unlock();
    ADXSTM_ExecServer();
    adxt_fssvr_enter_cnt = 2;
    cvFsExecServer();
    adxt_fssvr_enter_cnt = 5;
    ADXSTM_ExecServer();
    adxt_fssvr_enter_cnt = 6;
    ADXF_ExecServer();
    adxt_fssvr_enter_cnt = 0;
}
