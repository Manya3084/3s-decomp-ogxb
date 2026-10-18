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

/* Xbox: both motors run; the PS2 loop stops after the first. */
void move_pulpul(PPWORK* wk) {
    s32 i;
    s32 index;
    s32 data;
    s32 result;

    if (wk->ok_dev) {
        if (chkVibUnit(wk->id) == 0) {
            wk->ok_dev = 0;
            vibParamTrans(wk->id, &pulpara[1]);
            return;
        }

        for (i = 0; i < 2; i++) {
            switch (wk->p[i].rno[0]) {
            case 0:
                if (wk->p[i].ppnew == 0)
                    break;

                wk->p[i].rno[0] = 1;
                wk->p[i].ppnew = 0;
                wk->p[i].exix = -1;
                /* fallthrough */
            case 1:
                wk->p[i].exix += 1;

            lbl:
                index = wk->p[i].padr[wk->p[i].exix].ix;
                data = wk->p[i].padr[wk->p[i].exix].timer;

                if (index <= 0) {
                    if (index == 0) {
                        wk->p[i].rno[0] = 0;
                        vib_req[wk->id][i] = 0;
                        vibParamTrans(wk->id, &pulpara[1]);
                        break;
                    } else if (index == -1) {
                        wk->p[i].exix = data;
                        goto lbl;
                    }

                    if (index == -3) {
                        wk->p[i].rno[0] = 0;

                        if (test_flag) {
                            *ot_mot_of = data;
                            ot_make_curr_vib_data();
                        }

                        pulpul_request((s16)wk->id, data);
                        break;
                    }

                    if (index == -2) {
                        if (wk->vital >= data) {
                            wk->p[i].exix += 1;
                        } else {
                            wk->p[i].exix += 2;
                        }
                        goto lbl;
                    }

                    wk->p[i].rno[0] = 0;
                    break;
                }
                wk->p[i].rno[0] = 2;
                /* fallthrough */

            case 2:
                result = pulpul_pdVibMxStart(wk, i, wk->port, &pulpara[wk->p[i].padr[wk->p[i].exix].ix]);

                if (!result) {
                    break;
                }

                wk->p[i].rno[0] = 3;

                if (i == 1) {
                    wk->p[i].life = ((wk->p[i].padr[wk->p[i].exix].timer) * (0x20 - pul[wk->id].tim_ans)) / 0x20;
                } else {
                    wk->p[i].life = wk->p[i].padr[wk->p[i].exix].timer;
                }
                /* fallthrough */

            case 3:
                if (--wk->p[i].life < 0) {
                    wk->p[i].rno[0] = 1;
                }
                break;
            }
        }
        return;
    }

    if (chkVibUnit(wk->id) != 0) {
        wk->ok_dev = 1;
        wk->p[0].rno[0] = wk->p[1].rno[0] = 0;
        wk->p[0].ppnew = wk->p[1].ppnew = 0;
    }
}
