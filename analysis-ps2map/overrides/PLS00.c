/* The Xbox returns where the PS2 breaks out of the switch. */
void dm_04000(PLW* wk) {
    switch (wk->wu.cg_type) {
    case 9:
        if (wk->py->flag == 0) {
            // do nothing
        }

        break;

    case 64:
        if (setup_kuzureochi(wk) != 0) {
            break;
        }

        if (wk->py->flag == 0) {
            wk->tsukamarenai_flag = 7;

            if (wk->wu.pat_status < 32) {
                TO_nm_36000(&wk->wu);
                return;
            }

            TO_nm_37000(&wk->wu);
            break;
        }

        wk->wu.routine_no[2] = 19;
        wk->wu.routine_no[3] = 0;
        break;

        break;

    case 0xFF:
        if (setup_kuzureochi(wk) != 0) {
            break;
        }

        if (wk->py->flag == 0) {
            wk->tsukamarenai_flag = 7;

            if (wk->wu.pat_status < 32) {
                TO_nm_01000(&wk->wu);
                break;
            }

            TO_nm_09000(&wk->wu);
            break;
        }

        wk->wu.routine_no[2] = 19;
        wk->wu.routine_no[3] = 0;

        break;
    }
}

/* The Xbox returns where the PS2 breaks out of the switch. */
void dm_18000(PLW* wk) {
    switch (wk->wu.cg_type) {
    case 0xFF:
        if (wk->wu.vital_new < 0 && (check_sa_type_rebirth(wk) != 0)) {
            wk->py->flag = 0;
            execute_super_arts(wk);
            return;
        }

        if (wk->dead_flag) {
            wk->wu.routine_no[2] = 16;
        } else {
            wk->wu.routine_no[2] = 1;
        }

        wk->wu.routine_no[3] = 0;
        wk->wu.cg_type = 0;
        break;

    case 64:
        if (wk->py->flag == 0) {
            wk->tsukamarenai_flag = 7;
            TO_nm_36000(&wk->wu);
            break;
        }

        wk->wu.routine_no[2] = 19;
        wk->wu.routine_no[3] = 0;
        break;
    }
}
