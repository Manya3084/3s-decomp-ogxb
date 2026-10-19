/* Xbox-only flag getter (the dword at 0x79A170). */
s32 xb_GetOnlineFlag(void);

/* Xbox: the random choice also runs while xb_GetOnlineFlag is set. */
u16 effb8_normal_or_senyou() {
    if (xb_GetOnlineFlag() == 0 && Country != 1) {
        return 0;
    }

    return random_16() & 1;
}

/* Xbox-only functions of this object (analysis-ps2map/xbgen.py checked each). */
s32 sort_push_request3(WORK* wk);
extern s8 Suicide[8];

void xb_effect_B8_draw(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        return;

    case 1:
        if (Suicide[2] == 1) {
            return;
        }

        sort_push_request3(&ewk->wu);
        return;

    case 2:
        if (Suicide[2] == 1) {
            return;
        }

        sort_push_request3(&ewk->wu);
        return;
    }
}

/* Xbox: outside Japan, while xb_GetOnlineFlag is set, mes_already is held
   to 20..27 before the message is set up. */
void effect_B8_move(WORK_Other_CONN* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.my_mts = 12;
        mes_timer = mes_timer - 1;

        if (--mes_timer > 0) {
            break;
        }

        ewk->wu.routine_no[0]++;

        if (xb_GetOnlineFlag() && Country != 1) {
            if (mes_already < 20) {
                mes_already = 20;
            } else if (mes_already > 27) {
                mes_already = 27;
            }
        }

        get_message_conn_data(ewk, 0, ewk->master_player, mes_already);
        ewk->wu.disp_flag = 1;
        ewk->wu.vitality = 240;
        mes_timer = 55;
        ewk->wu.mvxy.a[0].sp = -0x100000;
        ewk->wu.mvxy.d[0].sp = 0;
        ewk->wu.hit_quake = bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos - 152;
        ewk->wu.mvxy.a[0].sp = -0x100000;
        ewk->wu.mvxy.d[0].sp = 0;
        break;

    case 1:
        if (Suicide[2] == 1) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0] = 3;
            break;
        }

        ewk->wu.xyz[0].cal += ewk->wu.mvxy.a[0].sp;
        ewk->wu.mvxy.a[0].sp += ewk->wu.mvxy.d[0].sp;

        if (ewk->wu.hit_quake >= ewk->wu.xyz[0].disp.pos) {
            ewk->wu.routine_no[0] = 2;
            ewk->wu.xyz[0].disp.pos = ewk->wu.hit_quake;
        }

        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos;
        ewk->wu.cg_number++;
        ewk->wu.cg_number &= 0x7FFF;
        sort_push_request3(&ewk->wu);
        break;

    case 2:
        if (Suicide[2] == 1) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0]++;
            break;
        }

        sort_push_request3(&ewk->wu);
        break;

    case 3:
        ewk->wu.routine_no[0]++;
        break;

    default:
        push_effect_work(&ewk->wu);
        break;
    }
}
