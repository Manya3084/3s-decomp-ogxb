/* Rewritten to match retail (tools/permute.py): <= 23 -> < 24. */
void effect_22_move(WORK_Other* ewk) {
    const s32* ptr;

    if (obr_no_disp_check()) {
        return;
    }

    if (compel_dead_check(ewk) != 0) {
        ewk->wu.routine_no[0] = 99;
        ewk->wu.disp_flag = 0;
        return;
    }

    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.dead_f = 1;
        set_char_move_init(&ewk->wu, 0, 11);
        ewk->wu.disp_flag = 1;
        ewk->wu.old_rno[0] = 0;
        /* fallthrough */

    case 1:
        ewk->wu.routine_no[0]++;
        ptr = &snow_sp[ewk->wu.old_rno[0]][ewk->wu.type][0];
        ewk->wu.mvxy.a[0].sp = *ptr++;
        ewk->wu.mvxy.d[0].sp = *ptr++;
        ewk->wu.mvxy.a[1].sp = *ptr++;
        ewk->wu.mvxy.d[1].sp = *ptr++;
        ewk->wu.xyz[0].disp.pos = snow_pos_tbl[ewk->wu.type][0];
        ewk->wu.xyz[1].disp.pos = snow_pos_tbl[ewk->wu.type][1];
        ewk->wu.old_rno[0]++;
        ewk->wu.old_rno[0] &= 3;
        break;

    case 2:
        if (!EXE_flag && !Game_pause) {
            sub_000EF072(ewk);
            sub_000EF088(ewk);

            if (ewk->wu.xyz[1].disp.pos < 24) {
                ewk->wu.routine_no[0] = 1;
            }
        }

        disp_pos_trans_entry_r(ewk);
        break;

    default:
        sub_0004384A(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}
