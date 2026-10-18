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
