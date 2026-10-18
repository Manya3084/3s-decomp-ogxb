/* Rewritten to match retail (tools/permute.py): <= 0 -> < 1. */
s32 check_be_car_object() {
    PLW* com;

    if (pcon_rno[0] == 0) {
        return 1;
    }

    if (plw[0].wu.operator) {
        com = &plw[1];
    } else {
        com = &plw[0];
    }

    if (com->wu.routine_no[0] < 1) {
        return 1;
    }

    return ((PLW*)com->wu.my_effadrs)->wu.be_flag != 0;
}

/* Rewritten to match retail (tools/permute.py): < 2 -> <= 1. */
s16 cal_sa_gauge_waribiki(PLW* wk, s16 asag) {
    s16 num;

    if (wk->cb->total <= 1) {
        return asag;
    }

    num = 32 - (wk->cb->total - 1) * 2;

    if (num <= 0) {
        num = 1;
    }

    asag = (asag * num) / 32;

    if (asag == 0) {
        asag = 1;
    }

    return asag;
}

/* Rewritten to match retail (tools/permute.py): <= 0 -> < 1. */
void remake_mvxy_PoGR(WORK* wk) {
    if (wk->mvxy.d[1].sp) {
        switch ((wk->mvxy.a[1].sp > 0) + ((wk->mvxy.a[1].sp < 0) * 2)) {
        case 1:
            wk->mvxy.a[1].sp = (wk->mvxy.a[1].sp * 80) / 100;
            break;

        default:
            wk->mvxy.a[1].sp = (wk->mvxy.a[1].sp * 10) / 100;
            break;
        }
    }

    switch ((wk->mvxy.a[0].sp > 0) + ((wk->mvxy.a[0].sp < 0) * 2)) {
    case 2:
        wk->mvxy.a[0].sp = (wk->mvxy.a[0].sp * 30) / 100;
        break;

    default:
        wk->mvxy.a[0].sp = (wk->mvxy.a[0].sp * 50) / 100;

        if (wk->mvxy.a[0].real.h < 1) {
            wk->mvxy.a[0].real.h = 1;
        }

        wk->mvxy.d[0].sp = 0;
        wk->mvxy.a[0].sp = -wk->mvxy.a[0].sp;
    }
}

/* Rewritten to match retail (tools/permute.py): cal_sa_gauge_waribiki parameter 2: s16 -> s32. */
void add_sp_arts_gauge_hit_dm(PLW* wk) {
    PLW* emwk;
    s16 asag;

    if (wk->wu.work_id != 1) {
        return;
    }

    emwk = (PLW*)wk->wu.target_adrs;
    asag = _add_arts_gauge[emwk->player_number][wk->wu.dm_arts_point][2];

    if (asag != 0) {
        add_super_arts_gauge(wk->sa, wk->wu.id, asag / 3, wk->metamorphose);

        if (emwk->wu.operator == 0) {
            asag += asagh_zuru[save_w[Present_Mode].Difficulty];
        }

        if (asag <= 0) {
            asag = 1;
        }

        asag = cal_sa_gauge_waribiki(wk, asag);

        if (emwk->wu.operator == 0 && Break_Into_CPU == 1) {
            asag = (asag * 120) / 100;
        }

        add_super_arts_gauge(emwk->sa, emwk->wu.id, asag, emwk->metamorphose);
    }

    wk->wu.dm_arts_point = 0;
}

/* Rewritten to match retail (tools/permute.py): < 1 -> <= 0; meri_case_switch parameter 1: s16 -> s32; < 1 -> <= 0. */
void check_body_touch() {
    PLW* p1w = &plw[0];
    PLW* p2w = &plw[1];
    s16 meri;

    if (p1w->wu.h_hos->hos_box[0] != 0 && p2w->wu.h_hos->hos_box[0] != 0) {
        meri = hit_check_subroutine(&p1w->wu, &p2w->wu, &p1w->wu.h_hos->hos_box[0], &p2w->wu.h_hos->hos_box[0]);

        if (meri != 0) {
            meri = meri_case_switch(meri);

            if (p1w->wu.old_pos[1] <= 0 && p2w->wu.old_pos[1] <= 0) {
                if (ichikannkei) {
                    goto one;
                }

                goto two;
            }

            if (check_work_position(&p1w->wu, &p2w->wu)) {
                goto one;
            }

            goto two;
        }
    }

    p1w->hos_em_flag = 0;
    p2w->hos_em_flag = 0;
    return;

one:
    p1w->wu.xyz[0].disp.pos += meri * (p1w->micchaku_flag != 1);
    p2w->wu.xyz[0].disp.pos -= meri * (p2w->micchaku_flag != 2);
    p1w->hos_em_flag = 2;
    p2w->hos_em_flag = 1;
    return;

two:
    p1w->wu.xyz[0].disp.pos -= meri * (p1w->micchaku_flag != 2);
    p2w->wu.xyz[0].disp.pos += meri * (p2w->micchaku_flag != 1);
    p1w->hos_em_flag = 1;
    p2w->hos_em_flag = 2;
}
