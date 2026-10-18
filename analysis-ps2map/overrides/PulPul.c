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

/* Xbox: the parameters are int, so callers sign-extend the id */
void pulpul_request(s32 id, s32 ix) {
    PULREQ* adr;

    if (vib_sel[id] == 0) {
        return;
    }

    if (ix == 0) {
        return;
    }

    if (test_flag) {
        adr = &ot_pulreq[ix];
        adr->adrs = ot_pulreq_xx;
    } else {
        adr = &pulreq[ix];
    }

    vib_req[id][adr->prio] = ix;

    pulpul_req_copy(id, adr);
}

/* The table value is read once, into a u16. */
void pp_screen_quake(s16 ix) {
    u16 q;

    ix /= 3;

    if (ix > 0xA) {
        ix = 0xA;
    }

    q = comm_quay_pulpul[ix];
    pulpul_request(0, q);
    pulpul_request(1, q);
}

/* Xbox: the pad is the player's port byte's (D_007AA5F6), and the unit is
   there when the pad has a handle. */
s32 chkVibUnit(s32 port) {
    if (((flpad_adr)[0][D_007AA5F6[port]].kind == 0) || ((flpad_adr)[0][D_007AA5F6[port]].kind) == 0x8000)
        return 0;

    return (flpad_adr)[0][D_007AA5F6[port]].conn.xbox.handle != 0;
}
