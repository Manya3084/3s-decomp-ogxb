/* ADXT_ExecFsSvr 0x171EF0.
 *
 * A non-zero adxt_fssvr_enter_cnt tail-jumps to ADXCRS_Unlock.
 * After the first cvFsExecServer the counter becomes 5. This build
 * does not call SRD_ExecServer or a second cvFsExecServer.
 */

#include "types.h"

extern s32 adxt_fssvr_enter_cnt; /* 0x7A6098 */

extern void sub_0016AA60(void);
extern void sub_0016AA70(void);
extern void ADXSTM_ExecServer(void);
extern void cvFsExecServer(void);
extern void ADXF_ExecServer(void);

void ADXT_ExecFsSvr(void) {
    sub_0016AA60();

    if (adxt_fssvr_enter_cnt != 0) {
        sub_0016AA70();
        return;
    }

    adxt_fssvr_enter_cnt = 1;
    sub_0016AA70();
    ADXSTM_ExecServer();
    adxt_fssvr_enter_cnt = 2;
    cvFsExecServer();
    adxt_fssvr_enter_cnt = 5;
    ADXSTM_ExecServer();
    adxt_fssvr_enter_cnt = 6;
    ADXF_ExecServer();
    adxt_fssvr_enter_cnt = 0;
}
