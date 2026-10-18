/* The Xbox breaks out of the switch where the PS2 returns. */
void effect_G6_move(WORK_Other* ewk) {
    WORK* mwk = (WORK*)ewk->my_master;

    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0] += 1;
        ewk->wu.dmcal_m = effg6_data[ewk->wu.type][0];
        ewk->wu.dir_timer = effg6_data[ewk->wu.type][1];
        ewk->wu.next_x = effg6_data[ewk->wu.type][2];
        ewk->wu.next_y = effg6_data[ewk->wu.type][3];
        ewk->wu.mvxy.a[0].sp = effg6_data[ewk->wu.type][4];
        ewk->wu.mvxy.a[1].sp = effg6_data[ewk->wu.type][5];
        ewk->wu.now_koc = effg6_data[ewk->wu.type][6];
        ewk->wu.direction = effg6_data[ewk->wu.type][7];

        if (ewk->wu.rl_flag) {
            ewk->wu.next_x = -ewk->wu.next_x;
        }

        ewk->wu.mvxy.a[0].sp *= 256;
        ewk->wu.mvxy.a[1].sp *= 256;
        ewk->wu.disp_flag = ewk->wu.now_koc / 256;
        ewk->wu.now_koc &= 0xFF;
        /* fallthrough */

    case 1:
        if (ewk->wu.dead_f == 1) {
            ewk->wu.routine_no[0] += 1;
            break;
        }

        if (((ewk->wu.dmcal_m & 1) && (ewk->wu.old_pos[1] != mwk->xyz[1].disp.pos)) ||
            ((ewk->wu.dmcal_m & 2) && (mwk->disp_flag == 0)) ||
            ((ewk->wu.dmcal_m & 4) && (ewk->wu.dm_vital != mwk->dm_count_up)) ||
            ((ewk->wu.dmcal_m & 8) &&
             ((ewk->wu.old_rno[0] != mwk->routine_no[0]) || (ewk->wu.old_rno[1] != mwk->routine_no[1]) ||
              (ewk->wu.old_rno[2] != mwk->routine_no[2])))) {
        block_22:
            ewk->wu.routine_no[0] += 1;
            return;
        }

        if ((EXE_flag != 0) || (Game_pause != 0)) {
            break;
        }

        if (ewk->wu.dmcal_m & 0x10) {
            if (ewk->wu.dir_timer-- <= 0) {
                goto block_22;
            }
        }

        if (ewk->wu.now_koc & (players_timer + ewk->wu.blink_timing)) {
            break;
        }

        if (ewk->wu.dmcal_m & 0x20) {
            if ((mwk->hit_stop == 0) && (ewk->wu.old_pos[0] == mwk->xyz[0].disp.pos) &&
                (ewk->wu.old_pos[1] == mwk->xyz[1].disp.pos)) {
                goto block_22;
            }
        } else if ((ewk->wu.old_pos[0] == mwk->xyz[0].disp.pos) && (ewk->wu.old_pos[1] == mwk->xyz[1].disp.pos)) {
            break;
        }

        ewk->wu.old_pos[0] = mwk->xyz[0].disp.pos;
        ewk->wu.old_pos[1] = mwk->xyz[1].disp.pos;
        ewk->wu.xyz[0].disp.pos = ewk->wu.old_pos[0] + ewk->wu.next_x;
        ewk->wu.xyz[1].disp.pos = ewk->wu.old_pos[1] + ewk->wu.next_y;
        ewk->wu.position_z = mwk->position_z;
        effect_G9_init(&ewk->wu);
        break;

    case 2:
    default:
        push_effect_work(&ewk->wu);
        break;
    }
}
