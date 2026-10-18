/* Located by their bytes and pointers (tools/locate_data.py): ldreq_process
 * is 0x25C724. */

/* Xbox: no disc polling; the drive error is always cleared. */
void fsUpdateDiskDriveError() {
    DskDrvErrType = 0xFFFF;
}

/* Xbox disc-error screen loop; it does not return. */
void xb_ShowDiskReadError(void);
extern s16 D_00C7F4FA;

/* Xbox: no file-number check; a file of size 0 raises the disc error. */
s32 load_it_use_any_key2(u16 fnum, void** adrs, s16* key, u8 kokey, u8 group) {
    u32 size;
    u32 err;

    size = fsGetFileSize(fnum);

    if (size == 0) {
        DskDrvErrBe = 1;
        D_00C7F4FA = 1;
        xb_ShowDiskReadError();
    }

    *key = Pull_ramcnt_key(fsCalSectorSize(size) << 11, kokey, group, 0);
    *adrs = (void*)Get_ramcnt_address(*key);

    err = load_it_use_this_key(fnum, *key);

    if (err != 0) {
        return size;
    }

    sub_00097103(*key);
    return 0;
}

/* Xbox: no vsync wait; it only runs the ADX and sound servers. */
void waitVsyncDummy() {
    ADXM_ExecMain();
    cseExecServer();
}

/* Xbox: the partition is D:\XB_HostPC\SF33RDXB.AFS. The wait polls
 * ADXF_GetPtStat and runs ADXM_ExecMain, and an error (4) shows the
 * disc-error screen. There is no vsync call and no CD read mode.
 * 0x2D0 is stored at 0xC7F4FA (PS2: DskDrvErrRetry = 0). */
s32 Setup_Directory_Record_Data() {
    s32 stat;

    DskDrvErrType = 0xFFFF;
    DskDrvErrBe = 0;
    D_00C7F4FA = 0x2D0;
    ADXF_LoadPartitionNw(0, "D:\\XB_HostPC\\SF33RDXB.AFS", NULL, sf3ptinfo);

    stat = ADXF_GetPtStat(0);

    while (stat != ADXF_STAT_READEND) {
        if (stat == 4) {
            xb_ShowDiskReadError();
        }

        ADXM_ExecMain();
        stat = ADXF_GetPtStat(0);
    }

    return 1;
}

/* Xbox: no flLogOut; it only clears the request. */
void q_ldreq_error(REQ* curr) {
    curr->be = 0;
}

/* Xbox: the archive has 0x5FB files (PS2 AFS_FILE_COUNT 0x5FF). */
u32 fsGetFileSize(u16 fnum) {
    if (fnum >= 0x5FB) {
        return 0;
    }

    return appFileSizes[fnum];
}

/* Xbox: ADXF_GetStat is called once */
s32 fsCheckCommandExecuting() {
    s32 stat;

    if (adxf == NULL) {
        return 0;
    }

    stat = ADXF_GetStat(adxf);

    if (stat == ADXF_STAT_READING || stat == ADXF_STAT_ERROR) {
        return 1;
    }

    return 0;
}

/* The Xbox AFS holds 0x5FB files. */
s32 fsOpen(REQ* req) {
    if (req->fnum >= 0x5FB) {
        return 0;
    }

    if (appFileSizes[req->fnum] == 0) {
        return 0;
    }

    if (adxf != NULL) {
        ADXF_Close(adxf);
    }

    adxf = ADXF_OpenAfs(0, req->fnum);

    if (adxf == NULL) {
        return 0;
    }

    req->info.number = 1;
    req->info.size = appFileSizes[req->fnum];
    return 1;
}

/* Xbox: no disp_ldreq_status debug display. */
void Check_LDREQ_Queue() {
    s16 i;

    if (ldreq_break) {
        if (q_ldreq->be == 1) {
            fsCansel(q_ldreq);
        }

        Init_Load_Request_Queue_1st();
        return;
    }

    if (q_ldreq->be != 0) {
        ldreq_process[q_ldreq->type](q_ldreq);

        if (q_ldreq->be == 0) {
            for (i = 0; i < 15; i++) {
                q_ldreq[i] = q_ldreq[i + 1];
            }

            q_ldreq[i].be = 0;
            q_ldreq[i].type = 0;
        }
    }
}
