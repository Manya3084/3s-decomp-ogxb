/* Rewritten to match retail (tools/permute.py): < 1 -> <= 0; < 1 -> <= 0. */
void bbbs_com_execute(PLW* wk) {
    switch (Bonus_Stage_RNO[0]) {
    case 0:
        if (Allow_a_battle_f == 0) {
            break;
        }

        Bonus_Stage_Tix = 0;
        Bonus_Stage_RNO[0] = 1;

        if ((wk->wu.dir_timer = bbbs_table[bbbs_type][Bonus_Stage_Level][Bonus_Stage_Tix].timer)) {
            Bonus_Stage_RNO[1] = 1;
        } else {
            Bonus_Stage_RNO[1] = 2;
        }

        wk->zettai_muteki_flag = 1;
        effect_B1_init(wk, 0);
        effect_B1_init(wk, 1);
        effect_16_init(wk, 0);
        effect_16_init(wk, 1);
        effect_H9_init(wk);
        effect_H0_init(&wk->wu);
        break;

    case 1:
        switch (Bonus_Stage_RNO[1]) {
        case 0:
            if (wk->wu.routine_no[1] != 0) {
                break;
            }

            if (wk->wu.routine_no[2] != 1 && (wk->wu.routine_no[2] < 36 || wk->wu.routine_no[2] > 38)) {
                break;
            }

            Bonus_Stage_Tix++;

            if (bbbs_table[bbbs_type][Bonus_Stage_Level][Bonus_Stage_Tix].timer == -1) {
                Bonus_Stage_RNO[0] = 2;
                Bonus_Stage_RNO[1] = 0;
                break;
            }

            if ((wk->wu.dir_timer = bbbs_table[bbbs_type][Bonus_Stage_Level][Bonus_Stage_Tix].timer)) {
                if (bbbs_table[bbbs_type][Bonus_Stage_Level][Bonus_Stage_Tix].kosuu) {
                    Bonus_Stage_RNO[1] = 1;
                    break;
                } else {
                    Bonus_Stage_RNO[1] = 5;
                    break;
                }
            } else {
                if (bbbs_table[bbbs_type][Bonus_Stage_Level][Bonus_Stage_Tix].kosuu) {
                    Bonus_Stage_RNO[1] = 2;
                    break;
                } else {
                    Bonus_Stage_RNO[1] = 6;
                    break;
                }
            }

            break;

        case 1:
            if (--wk->wu.dir_timer <= 0) {
                Bonus_Stage_RNO[1] = 2;
            }

            break;

        case 2:
            Bonus_Stage_RNO[1] = 3;
            wk->wu.routine_no[1] = 4;
            wk->wu.routine_no[2] = 31;
            wk->wu.routine_no[3] = 0;
            wk->wu.char_index = 71;
            wk->wu.cmwk[5] = bbbs_table[bbbs_type][Bonus_Stage_Level][Bonus_Stage_Tix].kosuu;
            wk->wu.mvxy.d[0].sp = 0;
            wk->wu.mvxy.a[0].sp = 0;
            wk->wu.mvxy.a[1].sp = bbbs_jump_level[bbbs_table[bbbs_type][Bonus_Stage_Level][Bonus_Stage_Tix].jmplv][0];
            wk->wu.mvxy.d[1].sp = bbbs_jump_level[bbbs_table[bbbs_type][Bonus_Stage_Level][Bonus_Stage_Tix].jmplv][1];
            break;

        case 3:
            if (wk->wu.cg_type == 20) {
                wk->wu.cg_type = 0;
                setup_effI8(wk, &bbbs_table[bbbs_type][Bonus_Stage_Level][Bonus_Stage_Tix]);
                Bonus_Stage_RNO[1] = 4;
            }

            break;

        case 4:
            if (wk->wu.routine_no[1] == 4 && wk->wu.routine_no[2] == 31 && wk->wu.routine_no[3] == 3) {
                Bonus_Stage_RNO[1] = 0;
            }

            break;

        case 5:
            if (--wk->wu.dir_timer <= 0) {
                Bonus_Stage_RNO[1] = 6;
                Allow_a_battle_f = 0;
            }

            break;

        case 6:
            Bonus_Stage_RNO[0] = 2;
            Bonus_Stage_RNO[1] = 0;
            Allow_a_battle_f = 0;
            break;
        }

    case 2:
        break;
    }
}
