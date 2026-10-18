/* Xbox: no disc polling; the drive error is always cleared. */
void fsUpdateDiskDriveError() {
    DskDrvErrType = 0xFFFF;
}

/* Xbox disc-error screen loop; it does not return. */
void sub_00059948(void);
extern s16 D_00C7F4FA;

/* Xbox: no file-number check; a file of size 0 raises the disc error. */
s32 load_it_use_any_key2(u16 fnum, void** adrs, s16* key, u8 kokey, u8 group) {
    u32 size;
    u32 err;

    size = fsGetFileSize(fnum);

    if (size == 0) {
        DskDrvErrBe = 1;
        D_00C7F4FA = 1;
        sub_00059948();
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
