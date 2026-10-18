/* Xbox motor call: port byte, level, time. */
extern s8 D_007AA5F6[2];
void xb_PADSetVibration(s32 port, s32 level, s32 time);

/* Xbox: rewritten for the Xbox controller motors. The PS2 version built a
 * DualShock actuator packet from the pad profile. */
s32 vibParamTrans(s32 id, PULPARA* prm) {
    u32 level;

    if (prm->power != 0 && prm->unit != 0) {
        level = prm->power + 1;

        if (level > 7) {
            level = 7;
        }

        xb_PADSetVibration(D_007AA5F6[id], level, 0xF0);
    } else {
        xb_PADSetVibration(D_007AA5F6[id], 0, 0);
    }

    return 1;
}
