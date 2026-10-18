/* PLPCU.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * setup_caught_process_flags 0x8CFC9 size 0x95.
 * caught_cg_type_check 0x8D05E size 0x11F.
 * check_tsukamare_keizoku_check 0x8D17D size 0x56.
 * scdmd_12000 0x8D1D3 size 0x5E.
 * scdmd_18000 0x8D263 size 0x67.
 * scdmd_23000 0x8D2CF size 0x17.
 * scdmd_24000 0x8D2E6 size 0x10.
 * Player_caught 0x8D350 size 0x66.
 * Caught_01000 0x8D3B6 size 0xF9.
 * Caught_02000 0x8D4AF size 0xED.
 * scdmd_14000 is folded into 0x8D2F6 with 2 other bodies. Unnamed.
 * scdmd_16000 is folded into 0x8D231 with 2 other bodies. Unnamed.
 * scdmd_17000 is folded into 0x8D319 with 1 other bodies. Unnamed.
 * scdmd_19000 is folded into 0x8D231 with 2 other bodies. Unnamed.
 * scdmd_20000 is folded into 0x8D2CA with 2 other bodies. Unnamed.
 * scdmd_21000 is folded into 0x8D2F6 with 2 other bodies. Unnamed.
 * scdmd_26000 is folded into 0x8D2CA with 2 other bodies. Unnamed.
 * scdmd_27000 is folded into 0x8D2F6 with 2 other bodies. Unnamed.
 * scdmd_28000 is folded into 0x8D319 with 1 other bodies. Unnamed.
 * scdmd_30000 is folded into 0x8D231 with 2 other bodies. Unnamed.
 * scdmd_31000 is folded into 0x8D2CA with 2 other bodies. Unnamed.
 * Not located in sf33rd.xbe; their PS2 C is kept under #if 0: Caught_00000,
 * Caught_03000, scdmd_25000, scdmd_29000.
 * Data: setup_cu_dm_init_data is 0x263070, 20 entries compared.
 * Data: plpcu_lv_00 is 0x2630C0, 4 entries compared.
 * Unnamed data used (not a difference): scdmd_12000: 0x2f27c0,0x2f2bc0;
 * scdmd_18000: 0x2f2560.
 * Globals: plpcu_lv_00 0x2630C0.
 */

#include "structs.h"

#define NULL 0

void scdmd_12000(PLW* wk);
void scdmd_14000(PLW* wk);
void scdmd_16000(PLW* wk);
void scdmd_17000(PLW* wk);
void scdmd_18000(PLW* wk);
void scdmd_19000(PLW* wk);
void scdmd_20000(PLW* wk);
void scdmd_21000(PLW* wk);
void scdmd_23000(PLW* wk);
void scdmd_24000(PLW* wk);
void scdmd_25000(PLW* wk);
void scdmd_26000(PLW* wk);
void scdmd_27000(PLW* wk);
void scdmd_28000(PLW* wk);
void scdmd_29000(PLW* wk);
void scdmd_30000(PLW* wk);
void scdmd_31000(PLW* wk);
void Caught_00000(PLW* , PLW* );
void Caught_01000(PLW* wk, PLW* emwk);
void Caught_02000(PLW* wk, PLW* emwk);
void Caught_03000(PLW* , PLW* );
void setup_caught_process_flags(PLW* wk);
void pp_pulpara_caught(WORK* wk);
void clear_chainex_check(s16 ix);
void set_char_move_init(WORK* wk, s16 koc, s16 index);
s32 check_tsukamare_keizoku_check(PLW* wk, PLW* emwk);
void char_move(WORK* wk);
void char_move_index(WORK* wk, s16 ix);
void caught_cg_type_check(PLW* wk, PLW* emwk);
s32 effect_A7_init(PLW* wk);
void char_move_cmms(WORK* wk);
void char_move_z(WORK* wk);
void get_catch_off_data(PLW* wk, s16 ix);
s16 getObjectHeight(u16 cgnum);
extern s8 _dm_step_data[][32];
extern u8 _select_hit_dsd[64][8];
s8 get_weight_point(WORK* wk);
s32 setup_accessories(PLW* wk, u8 data);
s32 effect_D9_init(PLW* wk, u8 data);
void setup_butt_own_data(WORK* wk);
void cal_initial_speed_y(WORK* wk, s16 tm, s16 y1);
extern s16 _buttobi_time_table[][4];

void (*const setup_cu_dm_init_data[20])(PLW* wk);

void (*const plpcu_lv_00[4])(PLW*, PLW*);

void (*const setup_cu_dm_init_data[20])(PLW* wk) = { scdmd_12000, scdmd_12000, scdmd_14000, scdmd_14000, scdmd_16000,
                                                     scdmd_17000, scdmd_18000, scdmd_19000, scdmd_20000, scdmd_21000,
                                                     scdmd_21000, scdmd_23000, scdmd_24000, scdmd_25000, scdmd_26000,
                                                     scdmd_27000, scdmd_28000, scdmd_29000, scdmd_30000, scdmd_31000 };

void (*const plpcu_lv_00[4])(PLW*, PLW*) = { Caught_00000, Caught_01000, Caught_02000, Caught_03000 };

void Player_caught(PLW* wk) {
    PLW* emwk = (PLW*)wk->wu.dmg_adrs;

    setup_caught_process_flags(wk);

    if (wk->wu.routine_no[3] == 0) {
        wk->ukemi_ok_timer = wk->backup_ok_timer = emwk->wu.cmyd.koc;
        wk->uot_cd_ok_flag = 0;
        wk->ukemi_success = 0;
        wk->wu.dir_old = 1;
        pp_pulpara_caught(&wk->wu);
        clear_chainex_check(wk->wu.id);
    }

    plpcu_lv_00[wk->wu.routine_no[2]](wk, emwk);
}

void setup_caught_process_flags(PLW* wk) {
    wk->wu.next_z = wk->wu.my_priority;
    wk->running_f = 0;
    wk->guard_flag = 3;
    wk->guard_chuu = 0;
    wk->tsukami_f = 0;
    wk->tsukamare_f = 1;
    wk->scr_pos_set_flag = 0;
    wk->dm_hos_flag = 0;
    wk->zuru_timer = 0;
    wk->zuru_ix_counter = 0;
    wk->atemi_flag = 0;
    wk->caution_flag = 0;
    wk->sa->saeff_ok = 0;
    wk->sa->saeff_mp = 0;
    wk->cancel_timer = 0;
    wk->cmd_request = 0;
    wk->hsjp_ok = 0;
    wk->high_jump_flag = 0;
    wk->wu.swallow_no_effect = 0;

    if (wk->wu.routine_no[3]) {
        wk->sa_stop_flag = 0;
    }
}

void Caught_01000(PLW* wk, PLW* emwk) {
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        set_char_move_init(&wk->wu, 3, emwk->wu.cmyd.ix);
        emwk->kind_of_catch = 0;
        wk->wu.cmwk[11] = 0;
        /* fallthrough */

    case 1:
        if (check_tsukamare_keizoku_check(wk, emwk) != 0) {
            break;
        }

        if (emwk->wu.curr_rca == NULL) {
            break;
        }

        if (emwk->wu.curr_rca->catch_nix == wk->wu.dir_old) {
            char_move(&wk->wu);
        } else {
            char_move_index(&wk->wu, emwk->wu.curr_rca->catch_nix);
            wk->wu.dir_old = emwk->wu.curr_rca->catch_nix;
        }

        wk->wu.rl_flag = emwk->wu.rl_flag ^ emwk->wu.curr_rca->catch_flip;

        if (emwk->wu.rl_flag) {
            wk->wu.xyz[0].disp.pos = emwk->wu.xyz[0].disp.pos - emwk->wu.curr_rca->catch_hos_x;
        } else {
            wk->wu.xyz[0].disp.pos = emwk->wu.xyz[0].disp.pos + emwk->wu.curr_rca->catch_hos_x;
        }

        wk->wu.xyz[1].disp.pos = emwk->wu.xyz[1].disp.pos + emwk->wu.curr_rca->catch_hos_y;

        if (emwk->wu.curr_rca->catch_prio == 2) {
            wk->wu.next_z = emwk->wu.next_z - 1;
        } else {
            wk->wu.next_z = emwk->wu.next_z + 1;
        }

        caught_cg_type_check(wk, emwk);
    }
}

void Caught_02000(PLW* wk, PLW* emwk) {
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        set_char_move_init(&wk->wu, 3, emwk->wu.cmyd.ix);
        emwk->kind_of_catch = 1;
        wk->wu.cmwk[11] = 0;
        /* fallthrough */

    case 1:
        if (check_tsukamare_keizoku_check(wk, emwk) != 0) {
            break;
        }

        if (emwk->wu.curr_rca == NULL) {
            break;
        }

        if (emwk->wu.curr_rca->catch_nix == wk->wu.dir_old) {
            char_move(&wk->wu);
        } else {
            char_move_index(&wk->wu, emwk->wu.curr_rca->catch_nix);
            wk->wu.dir_old = emwk->wu.curr_rca->catch_nix;
        }

        wk->wu.rl_flag = emwk->wu.rl_flag ^ emwk->wu.curr_rca->catch_flip;

        if (emwk->wu.rl_flag) {
            emwk->wu.xyz[0].disp.pos = wk->wu.xyz[0].disp.pos + emwk->wu.curr_rca->catch_hos_x;
        } else {
            emwk->wu.xyz[0].disp.pos = wk->wu.xyz[0].disp.pos - emwk->wu.curr_rca->catch_hos_x;
        }

        emwk->wu.xyz[1].disp.pos = wk->wu.xyz[1].disp.pos - emwk->wu.curr_rca->catch_hos_y;

        if (emwk->wu.curr_rca->catch_prio == 2) {
            wk->wu.next_z = emwk->wu.next_z - 1;
        } else {
            wk->wu.next_z = emwk->wu.next_z + 1;
        }

        caught_cg_type_check(wk, emwk);
    }
}

void caught_cg_type_check(PLW* wk, PLW* emwk) {
    switch (wk->wu.cg_type) {
    case 2:
        wk->wu.hit_quake = wk->wu.dm_quake;
        wk->wu.dm_quake = 0;
        wk->wu.cg_type = 0;
        break;

    case 3:
        effect_A7_init(wk);
        wk->wu.cg_type = 0;
        break;

    case 9:
        if (wk->wu.now_koc == 3 && wk->wu.char_index == 60) {
            if (wk->dead_flag) {
                char_move_cmms(&wk->wu);
            } else {
                char_move_z(&wk->wu);
            }

            wk->wu.cmmd.koc = 1;
            wk->wu.cmmd.ix = 12;
            wk->wu.cmmd.pat = 1;
        } else if (wk->dead_flag) {
            char_move_cmms(&wk->wu);
        } else {
            char_move_z(&wk->wu);
        }

        wk->wu.routine_no[1] = wk->wu.cmmd.koc;
        wk->wu.routine_no[2] = wk->wu.cmmd.ix;
        wk->wu.routine_no[3] = wk->wu.cmmd.pat;
        wk->dm_ix = wk->wu.char_index;

        if (wk->wu.xyz[1].disp.pos < 0) {
            wk->wu.xyz[1].cal = 0;
        }

        setup_cu_dm_init_data[wk->wu.routine_no[2] - 12](wk);
        get_catch_off_data(wk, emwk->wu.att.reaction);

        if (wk->ukemi_success == 0) {
            wk->ukemi_ok_timer = wk->backup_ok_timer;
            wk->uot_cd_ok_flag = 0;
        }

        break;
    }
}

s32 check_tsukamare_keizoku_check(PLW* wk, PLW* emwk) {
    if (emwk->tsukami_f == 0) {
        wk->wu.routine_no[1] = 1;
        wk->wu.routine_no[2] = 88;
        wk->wu.routine_no[3] = 0;
        wk->wu.dm_stop = wk->wu.hit_stop = 0;

        if (wk->wu.cg_flip & 2) {
            wk->reserv_add_y = -getObjectHeight(wk->wu.cg_number);
        } else {
            wk->reserv_add_y = 0;
        }

        return 1;
    }

    return 0;
}

void scdmd_12000(PLW* wk) {
    wk->dm_step_tbl = _dm_step_data[_select_hit_dsd[wk->wu.dm_impact][get_weight_point(&wk->wu)]];

    if (!wk->wu.dm_attribute) {
        return;
    }

    setup_accessories(wk, wk->wu.pat_status);

    if (wk->wu.dm_attribute != 2) {
        effect_D9_init(wk, (u8)wk->wu.dm_attribute);
    }
}

void scdmd_14000(PLW* wk) {
    setup_butt_own_data(&wk->wu);
    wk->wu.mvxy.a[1].sp = wk->wu.mvxy.d[1].sp = wk->wu.mvxy.kop[1] = 0;
}

void scdmd_16000(PLW* wk) {
    setup_butt_own_data(&wk->wu);
    cal_initial_speed_y(&wk->wu, _buttobi_time_table[wk->wu.char_index][wk->wu.dm_attlv], 0);
}

void scdmd_17000(PLW* wk) {
    setup_butt_own_data(&wk->wu);
    cal_initial_speed_y(&wk->wu, _buttobi_time_table[wk->wu.char_index][wk->wu.dm_attlv], wk->wu.xyz[1].disp.pos);
}

void scdmd_18000(PLW* wk) {
    setup_butt_own_data(&wk->wu);
    cal_initial_speed_y(&wk->wu, _buttobi_time_table[wk->wu.char_index][wk->wu.dm_attlv], wk->wu.xyz[1].disp.pos);

    if (!wk->wu.dm_attribute) {
        return;
    }

    setup_accessories(wk, wk->wu.pat_status);

    if (wk->wu.dm_attribute != 2) {
        effect_D9_init(wk, (u8)wk->wu.dm_attribute);
    }
}

void scdmd_19000(PLW* wk) {
    setup_butt_own_data(&wk->wu);
    cal_initial_speed_y(&wk->wu, _buttobi_time_table[wk->wu.char_index][wk->wu.dm_attlv], 0);
}

void scdmd_20000(PLW* wk) {
    setup_butt_own_data(&wk->wu);
}

void scdmd_21000(PLW* wk) {
    setup_butt_own_data(&wk->wu);
    wk->wu.mvxy.a[1].sp = wk->wu.mvxy.d[1].sp = wk->wu.mvxy.kop[1] = 0;
}

void scdmd_23000(PLW* wk) {
    if (wk->wu.xyz[1].disp.pos < 0) {
        wk->wu.xyz[1].cal = 0;
    }

    setup_butt_own_data(&wk->wu);
}

void scdmd_24000(PLW* wk) {
    wk->wu.routine_no[2] = 0;
    wk->wu.routine_no[3] = 1;
}

void scdmd_26000(PLW* wk) {
    setup_butt_own_data(&wk->wu);
}

void scdmd_27000(PLW* wk) {
    setup_butt_own_data(&wk->wu);
    wk->wu.mvxy.a[1].sp = wk->wu.mvxy.d[1].sp = wk->wu.mvxy.kop[1] = 0;
}

void scdmd_28000(PLW* wk) {
    setup_butt_own_data(&wk->wu);
    cal_initial_speed_y(&wk->wu, _buttobi_time_table[wk->wu.char_index][wk->wu.dm_attlv], wk->wu.xyz[1].disp.pos);
}

void scdmd_30000(PLW* wk) {
    setup_butt_own_data(&wk->wu);
    cal_initial_speed_y(&wk->wu, _buttobi_time_table[wk->wu.char_index][wk->wu.dm_attlv], 0);
}

void scdmd_31000(PLW* wk) {
    setup_butt_own_data(&wk->wu);
}

#if 0
/* PS2 C for functions not located in sf33rd.xbe yet. */

void Caught_00000(PLW* /* unused */, PLW* /* unused */) {}

void Caught_03000(PLW* /* unused */, PLW* /* unused */) {}

void scdmd_25000(PLW* wk) {}

void scdmd_29000(PLW* wk) {}
#endif
