/* Rewritten to match retail (tools/permute.py): <= 0 -> < 1. */
void set_char_move_init2(WORK* wk, s16 koc, s16 index, s16 ip, s16 scf) {
    u8 pst;
    u8 kow;

    if (index < 0) {
        index = 0;
    }

    if (ip < 1) {
        ip = 1;
    }

    pst = wk->pat_status;
    kow = wk->kind_of_waza;
    wk->now_koc = koc;
    wk->char_index = index;
    wk->set_char_ad = wk->char_table[koc] + (wk->char_table[koc][index] / 4);
    setupCharTableData(wk, 1, 1);
    wk->cg_ix = (ip - 1) * wk->cgd_type - wk->cgd_type;
    wk->cg_ctr = 1;
    wk->cg_next_ix = 0;
    wk->old_cgnum = 0;
    wk->cg_wca_ix = 0;

    if (wk->cmoa.pat == 0) {
        wk->cmoa.koc = wk->now_koc;
        wk->cmoa.ix = wk->char_index;
        wk->cmoa.pat = 1;
    }

    if (scf) {
        wk->pat_status = pst;
        wk->kind_of_waza = kow;
    } else {
        wk->kow = wk->kind_of_waza;
    }

    if (wk->work_id & 0xF) {
        wk->at_koa = acatkoa_table[wk->kind_of_waza];
    }

    wk->K5_init_flag = 1;
    char_move(wk);
}

/* Rewritten to match retail (tools/permute.py): cmpvital < emwk->vital_new -> emwk->vital_new > cmpvital. */
s32 comm_emhp(WORK* wk, UNK11* ctc) {
    WORK* emwk = (WORK*)wk->target_adrs;
    s16 num = 0;
    s32 cmpvital = (Max_vitality * ctc->ix) / 100;

    switch (ctc->koc) {
    case 1:
        if (emwk->vital_new > cmpvital) {
            num = 1;
        }

        break;

    case 2:
        if (emwk->vital_new < cmpvital) {
            num = 1;
        }

        break;

    default:
        if (emwk->vital_new == cmpvital) {
            num = 1;
        }

        break;
    }

    if (num) {
        return decord_if_jump(wk, ctc, ctc->pat);
    }

    return 1;
}
