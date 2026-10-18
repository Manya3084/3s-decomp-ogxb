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
