/* adxt_exec_main_thrd 0x1684C0. adxt_exec_tsvr 0x1684D0.
 * adxt_exec_fssvr 0x1684E0. adxt_exec_main_nothrd 0x168560.
 * ADXT_Init 0x168580. ADXT_Finish 0x1684F0.
 *
 * Each exec callback ignores its object and returns 0. main_thrd calls
 * LSC_ExecServer. tsvr calls ADXT_ExecServer. fssvr calls
 * ADXT_ExecFsSvr. nothrd calls tsvr, then fssvr, then main_thrd.
 *
 * Init reads the build pointer at 0x2DFADC and counts at 0x7A5364.
 * The talk table is 16 objects of 0xC0 at 0xCE8F60. The vsync flag is
 * 0x43C8E8, the file-server id is 0x7A5370, the main id is 0x7A536C,
 * and adxt_vsync_cnt is 0x7A5374. ADXRNA_Init and ADXRNA_Finish are called.
 * The error clear is 0x168DF0 and the shared error callback is 0x1684B0.
 * Those two stay unnamed. The thread check is ADXM_IsSetupThrd.
 * Finish does not store a dtx send switch. The stream finish stays
 * 0x1725E0. Unlock is a tail jump.
 */

#include "types.h"

#include <string.h>

extern void LSC_ExecServer(void);
extern void ADXT_ExecServer(void);
extern void ADXT_ExecFsSvr(void);
char *volatile adxt_build = "\nADXT/XBOX Ver.9.15 Build:Feb 13 2004 21:08:09\n";
extern s32 adxt_init_cnt;
s32 adxt_vsync_svr_flag = 1;
extern s32 adxt_svr_fs_id;
extern s32 adxt_svr_main_id;
extern s32 adxt_vsync_cnt;
extern u8 adxt_obj[0xC00];
extern void ADXCRS_Init(void);
extern void sub_0016AA60(void);
extern void sub_0016AA70(void);
extern void SJUNI_Init(void);
extern void SJRBF_Init(void);
extern void SJMEM_Init(void);
extern void sub_00168DF0(void);
extern s32 ADXSTM_Init(void);
extern void ADXSJD_Init(void);
extern void ADXF_Init(void);
extern void ADXRNA_Init(void);
extern void LSC_Init(void);
extern void SVM_Init(void);
extern void sub_001684B0(void *obj, char *msg);
extern void ADXRNA_EntryErrFunc(void (*func)(void *obj, char *msg), void *obj);
extern void LSC_EntryErrFunc(void (*func)(void *obj, char *msg), void *obj);
extern s32 ADXM_IsSetupThrd(void);
extern void SVM_SetCbSvrId(s32 svtype, s32 id, s32 (*func)(void *object), void *object);
extern s32 SVM_SetCbSvr(s32 index, s32 (*func)(void *object), void *object);
extern void ADXT_SetDefSvrFreq(s32 freq);
extern void ADXRNA_Finish(void);
extern void ADXF_Finish(void);
extern void sub_001725E0(void);
extern void LSC_Finish(void);
extern void SVM_DelCbSvr(s32 group, s32 id);
extern void SVM_Finish(void);
extern void ADXSJD_Finish(void);
extern void SJMEM_Finish(void);
extern void SJRBF_Finish(void);
extern void SJUNI_Finish(void);

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

s32 adxt_exec_main_nothrd(void *object) {
    (void)object;
    adxt_exec_tsvr(0);
    adxt_exec_fssvr(0);
    adxt_exec_main_thrd(0);
    return 0;
}

void ADXT_Init(void) {
    s32 is_thread_setup;

    (void)adxt_build;

    if (adxt_init_cnt == 0) {
        ADXCRS_Init();
        sub_0016AA60();
        SJUNI_Init();
        SJRBF_Init();
        SJMEM_Init();
        sub_00168DF0();
        ADXSTM_Init();
        ADXSJD_Init();
        ADXF_Init();
        ADXRNA_Init();
        LSC_Init();
        SVM_Init();
        ADXRNA_EntryErrFunc(sub_001684B0, 0);
        LSC_EntryErrFunc(sub_001684B0, 0);
        memset(adxt_obj, 0, sizeof(adxt_obj));
        is_thread_setup = ADXM_IsSetupThrd();

        if ((is_thread_setup == 1) && (adxt_vsync_svr_flag == 1)) {
            SVM_SetCbSvrId(2, 1, adxt_exec_tsvr, 0);
            adxt_svr_fs_id = SVM_SetCbSvr(4, adxt_exec_fssvr, 0);
            adxt_svr_main_id = SVM_SetCbSvr(5, adxt_exec_main_thrd, 0);
        } else {
            adxt_svr_main_id = SVM_SetCbSvr(5, adxt_exec_main_nothrd, 0);
        }

        adxt_vsync_cnt = 0;
        ADXT_SetDefSvrFreq(60);
        sub_0016AA70();
    }

    adxt_init_cnt += 1;
}

void ADXT_Finish(void) {
    if (--adxt_init_cnt == 0) {
        ADXRNA_Finish();
        ADXF_Finish();
        sub_001725E0();
        LSC_Finish();
        sub_0016AA60();
        SVM_DelCbSvr(2, 1);
        SVM_DelCbSvr(4, adxt_svr_fs_id);
        SVM_DelCbSvr(5, adxt_svr_main_id);
        SVM_Finish();
        ADXSJD_Finish();
        sub_00168DF0();
        SJMEM_Finish();
        SJRBF_Finish();
        SJUNI_Finish();
        sub_0016AA70();
    }
}
