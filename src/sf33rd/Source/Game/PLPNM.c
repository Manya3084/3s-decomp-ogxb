/* PLPNM.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * setup_normal_process_flags 0x8F797 size 0xBC.
 * Normal_00000 0x8F853 size 0x5.
 * Normal_01000 0x8F858 size 0x44.
 * Normal_02000 0x8F89C size 0x4A.
 * Normal_03000 0x8F8E6 size 0x69.
 * Normal_04000 0x8F94F size 0x62.
 * Normal_05000 0x8F9B1 size 0x42.
 * nm_05_0000 0x8F9F3 size 0x63.
 * nm_05_0100 0x8FA56 size 0x92.
 * Normal_06000 0x8FAE8 size 0x42.
 * nm_06_0000 0x8FB2A size 0x34.
 * nm_06_0100 0x8FB5E size 0x63.
 * nm_06_0200 0x8FBC1 size 0x92.
 * Normal_07000 0x8FC53 size 0x44.
 * Normal_08000 0x8FC97 size 0x44.
 * Normal_09000 0x8FCDB size 0x44.
 * Normal_10000 0x8FD1F size 0x4A.
 * Normal_16000 0x8FD69 size 0x52.
 * Normal_17000 0x8FDBB size 0x52.
 * Normal_18000 0x8FE0D size 0x8E.
 * Normal_18000_init_unit 0x8FE9B size 0x4C.
 * Normal_27000 0x8FEE7 size 0x49.
 * Normal_31000 0x8FF30 size 0xAA.
 * Normal_35000 0x8FFDA size 0xE1.
 * Normal_38000 0x900DD size 0x48.
 * Normal_39000 0x90125 size 0x3C.
 * Normal_40000 0x90161 size 0x54.
 * Normal_41000 0x901B5 size 0x5D.
 * Normal_42000 0x90212 size 0x10D.
 * Normal_47000 0x9031F size 0x10A.
 * Normal_48000 0x90429 size 0xC5.
 * Normal_50000 0x904EE size 0xA3.
 * Normal_51000 0x90591 size 0x1F.
 * Normal_52000 0x905B0 size 0x98.
 * Normal_53000 0x90648 size 0xFB.
 * Normal_54000 0x90743 size 0x7A.
 * make_nm55_init_sp 0x907BD size 0x8C.
 * nm56_char_select 0x90849 size 0x81.
 * nm57_dir_select 0x908CA size 0x57.
 * Normal_58000 0x90921 size 0x5C.
 * Player_normal 0x9097D size 0x6E.
 * Normal_55000 0x909EB size 0x75.
 * Normal_56000 0x90A60 size 0x62.
 * Normal_57000 0x90AC2 size 0x9C.
 * Normal_36000 is folded into 0x900BB with 1 other bodies. Unnamed.
 * Normal_37000 is folded into 0x900BB with 1 other bodies. Unnamed.
 * pp_pulpara_remake_nm_move is folded into 0x4384A.
 * Data: nmPB_data is 0x263B88, 0x1E bytes compared.
 * Data: nmCE_data is 0x263BA8, 0x18 bytes compared.
 * Data: plpnm_lv_00 is 0x263BC0, 59 entries compared.
 * Data: normal_05 is 0x263CB0, 20 entries compared.
 * Data: normal_06 is 0x263D00, 20 entries compared.
 * Data: jpdat_tbl is 0x263D50, 0x24 bytes compared.
 * Globals: guard_kind 0x263948, nmPB_data 0x263B88, nmCE_data 0x263BA8,
 * plpnm_lv_00 0x263BC0, normal_05 0x263CB0, normal_06 0x263D00, jpdat_tbl
 * 0x263D50, Mode_Type 0x7A825A, Flash_MT 0x7A8266.
 */

#include "structs.h"

void sub_0004384A();
void Normal_00000(PLW* wk);
void Normal_01000(PLW* wk);
void Normal_02000(PLW* wk);
void Normal_03000(PLW* wk);
void Normal_04000(PLW* wk);
void Normal_05000(PLW* wk);
void Normal_06000(PLW* wk);
void Normal_07000(PLW* wk);
void Normal_08000(PLW* wk);
void Normal_09000(PLW* wk);
void Normal_10000(PLW* wk);
void Normal_16000(PLW* wk);
void Normal_17000(PLW* wk);
void Normal_18000(PLW* wk);
void Normal_27000(PLW* wk);
void Normal_31000(PLW* wk);
void Normal_35000(PLW* wk);
void Normal_36000(PLW* wk);
void Normal_37000(PLW* wk);
void Normal_38000(PLW* wk);
void Normal_39000(PLW* wk);
void Normal_40000(PLW* wk);
void Normal_41000(PLW* wk);
void Normal_42000(PLW* wk);
void Normal_47000(PLW* wk);
void Normal_48000(PLW* wk);
void Normal_50000(PLW* wk);
void Normal_51000(PLW* wk);
void Normal_52000(PLW* wk);
void Normal_53000(PLW* wk);
void Normal_54000(PLW* wk);
void Normal_55000(PLW* wk);
void Normal_56000(PLW* wk);
void Normal_57000(PLW* wk);
void Normal_58000(PLW* wk);
void nm_05_0000(PLW* wk);
void nm_05_0100(PLW* wk);
void nm_06_0100(PLW* wk);
void nm_06_0200(PLW* wk);
void nm_06_0000(PLW* wk);
void setup_normal_process_flags(PLW* wk);
void clear_chainex_check(s16 ix);
void check_my_tk_power_off(PLW* wk, PLW* );
void check_em_tk_power_off(PLW* wk, PLW* tk);
void appear_player(PLW* wk);
void set_char_move_init(WORK* wk, s16 koc, s16 index);
void char_move(WORK* wk);
void setup_mvxy_data(WORK* wk, u16 ix);
void add_mvxy_speed(WORK* wk);
void cal_mvxy_speed(WORK* wk);
void jumping_guard_type_check(PLW* wk);
void jumping_union_process(WORK* wk, s16 num);
extern const u8 guard_kind[];
void set_hit_stop_hit_quake(WORK* wk);
void add_sp_arts_gauge_paring(PLW* wk);
void subtract_dm_vital(PLW* wk);
void pp_pulpara_blocking(WORK* wk);
void char_move_wca(WORK* wk);
void remake_mvxy_PoSB(WORK* wk);
void char_move_wca_init(WORK* wk);
extern u8 Mode_Type;
void win_player(PLW* wk);
void lose_player(PLW* wk);
extern s8 Flash_MT[2];
s32 effect_G6_init(WORK* wk, u8 dat);
void add_sp_arts_gauge_nagenuke(PLW* wk);
void grade_add_grap_def(s16 ix);
void remake_sankaku_tobi_mvxy(WORK* wk, u8 kabe);
s32 effect_I3_init(WORK* wk, u8 tix);
void char_move_z(WORK* wk);
void set_new_jpdir(PLW* wk);
void check_jump_rl_dir(PLW* wk);
s16 check_work_position(WORK* p1, WORK* p2);
void make_nm55_init_sp(PLW* wk);
s16 get_sel_hosei_tbl_ix(s16 plnum);
s16 check_work_position_bonus(WORK* hm, s16 tx);
void nm56_char_select(PLW* wk);
void nm57_dir_select(PLW* wk);

const s16 nmPB_data[5][3];

const s16 nmCE_data[4][3];

const u16 jpdat_tbl[9][2];

void (*const plpnm_lv_00[59])(PLW* wk);

void (*const normal_05[])(PLW* wk);

void (*const normal_06[])(PLW* wk);

const s16 nmPB_data[5][3] = { { 38, 23, 1 }, { 39, 23, 1 }, { 40, 24, 1 }, { 41, 25, 0 }, { 42, 25, 0 } };

const s16 nmCE_data[4][3] = { { 43, 26, 1 }, { 44, 27, 1 }, { 45, 28, 0 }, { 46, 29, 0 } };

void (*const plpnm_lv_00[59])(PLW* wk) = {
    Normal_00000, Normal_01000, Normal_02000, Normal_03000, Normal_04000, Normal_05000, Normal_06000, Normal_07000,
    Normal_08000, Normal_09000, Normal_10000, Normal_03000, Normal_04000, Normal_03000, Normal_03000, Normal_03000,
    Normal_16000, Normal_17000, Normal_18000, Normal_18000, Normal_18000, Normal_18000, Normal_18000, Normal_18000,
    Normal_18000, Normal_18000, Normal_18000, Normal_27000, Normal_27000, Normal_27000, Normal_27000, Normal_31000,
    Normal_31000, Normal_31000, Normal_35000, Normal_35000, Normal_36000, Normal_37000, Normal_38000, Normal_39000,
    Normal_40000, Normal_41000, Normal_42000, Normal_42000, Normal_42000, Normal_42000, Normal_42000, Normal_47000,
    Normal_48000, Normal_47000, Normal_50000, Normal_51000, Normal_52000, Normal_53000, Normal_54000, Normal_55000,
    Normal_56000, Normal_57000, Normal_58000
};

void (*const normal_05[])(PLW* wk) = { nm_05_0000, nm_05_0000, nm_05_0100, nm_05_0000, nm_05_0000,
                                       nm_05_0000, nm_05_0000, nm_05_0000, nm_05_0100, nm_05_0000,
                                       nm_05_0000, nm_05_0100, nm_05_0100, nm_05_0000, nm_05_0100,
                                       nm_05_0000, nm_05_0100, nm_05_0000, nm_05_0000, nm_05_0000 };

void (*const normal_06[])(PLW* wk) = { nm_06_0100, nm_06_0100, nm_06_0200, nm_06_0000, nm_06_0100,
                                       nm_06_0100, nm_06_0100, nm_06_0100, nm_06_0000, nm_06_0100,
                                       nm_06_0000, nm_06_0200, nm_06_0200, nm_06_0100, nm_06_0200,
                                       nm_06_0000, nm_06_0200, nm_06_0100, nm_06_0100, nm_06_0100 };

const u16 jpdat_tbl[9][2] = { { 17, 6 },  { 18, 7 },  { 19, 8 },  { 14, 9 }, { 15, 10 },
                              { 16, 11 }, { 20, 12 }, { 21, 13 }, { 22, 14 } };

void Player_normal(PLW* wk) {
    setup_normal_process_flags(wk);

    if (wk->wu.routine_no[3] == 0) {
        clear_chainex_check(wk->wu.id);
    }

    check_my_tk_power_off(wk, (PLW*)wk->wu.target_adrs);
    check_em_tk_power_off(wk, (PLW*)wk->wu.target_adrs);
    sub_0004384A(wk);
    plpnm_lv_00[wk->wu.routine_no[2]](wk);

    if (wk->wu.cg_prio) {
        wk->wu.next_z = ((WORK*)wk->wu.target_adrs)->my_priority;

        if (wk->wu.cg_prio == 1) {
            wk->wu.next_z++;
            return;
        }

        wk->wu.next_z -= 3;
    }
}

void setup_normal_process_flags(PLW* wk) {
    wk->wu.next_z = wk->wu.my_priority;
    wk->running_f = 0;
    wk->py->flag = 0;
    wk->guard_flag = 0;
    wk->guard_chuu = 0;
    wk->tsukami_f = 0;
    wk->tsukamare_f = 0;
    wk->scr_pos_set_flag = 1;
    wk->dm_hos_flag = 0;
    wk->ukemi_success = 0;
    wk->zuru_timer = 0;
    wk->zuru_ix_counter = 0;
    wk->sa_stop_flag = 0;
    wk->atemi_flag = 0;
    wk->caution_flag = 0;
    wk->sa->saeff_ok = 0;
    wk->sa->saeff_mp = 0;
    wk->ukemi_success = 0;
    wk->ukemi_ok_timer = 0;
    wk->uot_cd_ok_flag = 0;
    wk->cancel_timer = 0;
    wk->hazusenai_flag = 0;
    wk->cat_break_reserve = 0;
    wk->cmd_request = 0;
    wk->hsjp_ok = 0;

    if (wk->wu.routine_no[2] != 17) {
        wk->high_jump_flag = 0;
    }

    wk->wu.swallow_no_effect = 0;
}

void Normal_00000(PLW* wk) {
    appear_player(wk);
}

void Normal_01000(PLW* wk) {
    if (wk->the_same_players) {
        wk->wu.next_z = wk->wu.my_priority + 1;
    }

    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        set_char_move_init(&wk->wu, 0, 0);
        break;

    case 1:
        char_move(&wk->wu);
        break;
    }
}

void Normal_02000(PLW* wk) {
    if (wk->the_same_players) {
        wk->wu.next_z = wk->wu.my_priority + 1;
    }

    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = wk->wu.rl_waza;
        set_char_move_init(&wk->wu, 0, 1);
        break;

    case 1:
        char_move(&wk->wu);
        break;
    }
}

void Normal_03000(PLW* wk) {
    if (wk->the_same_players) {
        wk->wu.next_z = wk->wu.my_priority - 1;
    }

    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        set_char_move_init(&wk->wu, 0, 2);
        setup_mvxy_data(&wk->wu, 0);
        wk->wu.mvxy.a[0].sp >>= 1;
        add_mvxy_speed(&wk->wu);
        wk->wu.mvxy.a[0].sp *= 2;
        break;

    case 1:
        cal_mvxy_speed(&wk->wu);
        add_mvxy_speed(&wk->wu);
        char_move(&wk->wu);
        break;
    }
}

void Normal_04000(PLW* wk) {
    if (wk->the_same_players) {
        wk->wu.next_z = wk->wu.my_priority + 1;
    }

    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        set_char_move_init(&wk->wu, 0, 3);
        setup_mvxy_data(&wk->wu, 1);
        add_mvxy_speed(&wk->wu);
        break;

    case 1:
        cal_mvxy_speed(&wk->wu);
        add_mvxy_speed(&wk->wu);
        char_move(&wk->wu);
        break;
    }
}

void Normal_05000(PLW* wk) {
    if (wk->the_same_players) {
        wk->wu.next_z = wk->wu.my_priority - 1;
    }

    wk->running_f = 1;
    wk->guard_flag = 3;
    normal_05[wk->player_number](wk);
    jumping_guard_type_check(wk);
}

void nm_05_0000(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = wk->wu.rl_waza;
        set_char_move_init(&wk->wu, 0, 4);
        setup_mvxy_data(&wk->wu, 2);
        /* fallthrough */

    case 1:
        if (wk->wu.cg_type == 1) {
            add_mvxy_speed(&wk->wu);
            wk->wu.routine_no[3]++;
            break;
        }

        char_move(&wk->wu);
        break;

    case 2:
        jumping_union_process(&wk->wu, 3);
        break;

    case 3:
        char_move(&wk->wu);
        break;
    }
}

void nm_05_0100(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = wk->wu.rl_waza;
        set_char_move_init(&wk->wu, 0, 4);
        setup_mvxy_data(&wk->wu, 2);

        if (wk->wu.cg_type == 1) {
            add_mvxy_speed(&wk->wu);
            wk->wu.routine_no[3]++;
            wk->wu.cg_type = 0;
            break;
        }

        break;

    case 1:
        char_move(&wk->wu);

        if (wk->wu.cg_type == 1) {
            add_mvxy_speed(&wk->wu);
            wk->wu.routine_no[3]++;
            wk->wu.cg_type = 0;
            break;
        }

        break;

    case 2:
        char_move(&wk->wu);

        if (wk->wu.cg_type == 1) {
            wk->wu.routine_no[3]++;
            wk->wu.cg_type = 0;
            break;
        }

        cal_mvxy_speed(&wk->wu);
        add_mvxy_speed(&wk->wu);
        break;

    case 3:
        char_move(&wk->wu);
        break;
    }
}

void Normal_06000(PLW* wk) {
    if (wk->the_same_players) {
        wk->wu.next_z = wk->wu.my_priority + 1;
    }

    wk->running_f = 2;
    wk->guard_flag = 3;
    normal_06[wk->player_number](wk);
    jumping_guard_type_check(wk);
}

void nm_06_0000(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = wk->wu.rl_waza;
        set_char_move_init(&wk->wu, 0, 5);
        break;

    case 1:
        char_move(&wk->wu);
        break;
    }
}

void nm_06_0100(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = wk->wu.rl_waza;
        set_char_move_init(&wk->wu, 0, 5);
        setup_mvxy_data(&wk->wu, 3);
        /* fallthrough */

    case 1:
        if (wk->wu.cg_type == 1) {
            add_mvxy_speed(&wk->wu);
            wk->wu.routine_no[3]++;
            break;
        }

        char_move(&wk->wu);
        break;

    case 2:
        jumping_union_process(&wk->wu, 3);
        break;

    case 3:
        char_move(&wk->wu);
        break;
    }
}

void nm_06_0200(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = wk->wu.rl_waza;
        set_char_move_init(&wk->wu, 0, 5);
        setup_mvxy_data(&wk->wu, 3);

        if (wk->wu.cg_type == 1) {
            add_mvxy_speed(&wk->wu);
            wk->wu.routine_no[3]++;
            wk->wu.cg_type = 0;
            break;
        }

        break;

    case 1:
        char_move(&wk->wu);

        if (wk->wu.cg_type == 1) {
            add_mvxy_speed(&wk->wu);
            wk->wu.routine_no[3]++;
            wk->wu.cg_type = 0;
            break;
        }

        break;

    case 2:
        char_move(&wk->wu);

        if (wk->wu.cg_type == 1) {
            wk->wu.routine_no[3]++;
            wk->wu.cg_type = 0;
            break;
        }

        cal_mvxy_speed(&wk->wu);
        add_mvxy_speed(&wk->wu);
        break;

    case 3:
        char_move(&wk->wu);
        break;
    }
}

void Normal_07000(PLW* wk) {
    if (wk->the_same_players) {
        wk->wu.next_z = wk->wu.my_priority - 1;
    }

    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        set_char_move_init(&wk->wu, 0, 11);
        break;

    case 1:
        char_move(&wk->wu);
        break;
    }
}

void Normal_08000(PLW* wk) {
    if (wk->the_same_players) {
        wk->wu.next_z = wk->wu.my_priority - 1;
    }

    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        set_char_move_init(&wk->wu, 0, 6);
        break;

    case 1:
        char_move(&wk->wu);
        break;
    }
}

void Normal_09000(PLW* wk) {
    if (wk->the_same_players) {
        wk->wu.next_z = wk->wu.my_priority - 1;
    }

    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        set_char_move_init(&wk->wu, 0, 7);
        break;

    case 1:
        char_move(&wk->wu);
        break;
    }
}

void Normal_10000(PLW* wk) {
    if (wk->the_same_players) {
        wk->wu.next_z = wk->wu.my_priority - 1;
    }

    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = wk->wu.rl_waza;
        set_char_move_init(&wk->wu, 0, 8);
        break;

    case 1:
        char_move(&wk->wu);
        break;
    }
}

void Normal_16000(PLW* wk) {
    if (wk->the_same_players) {
        wk->wu.next_z = wk->wu.my_priority + 1;
    }

    wk->guard_flag = 3;

    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->extra_jump = 0;
        set_char_move_init(&wk->wu, 0, 12);
        break;

    case 1:
        char_move(&wk->wu);
        break;
    }
}

void Normal_17000(PLW* wk) {
    if (wk->the_same_players) {
        wk->wu.next_z = wk->wu.my_priority + 1;
    }

    wk->guard_flag = 3;

    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->extra_jump = 0;
        set_char_move_init(&wk->wu, 0, 13);
        break;

    case 1:
        char_move(&wk->wu);
        break;
    }
}

void Normal_18000(PLW* wk) {
    if (wk->the_same_players) {
        wk->wu.next_z = wk->wu.my_priority + 1;
    }

    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        set_char_move_init(&wk->wu, 0, jpdat_tbl[wk->wu.routine_no[2] - 18][0]);
        setup_mvxy_data(&wk->wu, jpdat_tbl[wk->wu.routine_no[2] - 18][1]);
        add_mvxy_speed(&wk->wu);
        wk->air_jump_ok_time = 4;
        wk->bs2_on_car = 0;
        break;

    case 1:
        jumping_union_process(&wk->wu, 2);
        break;

    case 2:
        char_move(&wk->wu);
        break;
    }

    jumping_guard_type_check(wk);
}

void Normal_18000_init_unit(PLW* wk, u8 ps) {
    ps = (ps - 14) / 2;

    if (ps > 8) {
        ps = 4;
    }

    set_char_move_init(&wk->wu, 0, jpdat_tbl[ps][0]);
    setup_mvxy_data(&wk->wu, jpdat_tbl[ps][1]);
    add_mvxy_speed(&wk->wu);
}

void Normal_27000(PLW* wk) {
    if (wk->the_same_players) {
        wk->wu.next_z = wk->wu.my_priority + 1;
    }

    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        set_char_move_init(&wk->wu, 0, wk->wu.routine_no[2] + 2);
        break;

    case 1:
        char_move(&wk->wu);
        break;
    }
}

void Normal_31000(PLW* wk) {
    if (((WORK*)wk->wu.target_adrs)->cg_prio != 2) {
        wk->wu.next_z = 32;
    }

    wk->guard_chuu = guard_kind[wk->wu.routine_no[2] - 27];
    wk->scr_pos_set_flag = 0;

    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = (wk->wu.dm_rl + 1) & 1;
        set_char_move_init(&wk->wu, 0, wk->wu.routine_no[2] - 7);

        if (wk->wu.dm_stop > 0) {
            wk->wu.dm_stop = -wk->wu.dm_stop;
        }

        set_hit_stop_hit_quake(&wk->wu);
        add_sp_arts_gauge_paring(wk);
        subtract_dm_vital(wk);
        pp_pulpara_blocking(&wk->wu);
        break;

    case 1:
        wk->wu.routine_no[3]++;
        char_move_wca(&wk->wu);
        break;

    case 2:
        char_move(&wk->wu);
        break;
    }
}

void Normal_35000(PLW* wk) {
    if (wk->the_same_players) {
        wk->wu.next_z = wk->wu.my_priority - 1;
    }

    wk->guard_chuu = guard_kind[(wk->wu.routine_no[2] - 27)];

    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;

        if (wk->wu.dm_stop > 0) {
            wk->wu.dm_stop = -wk->wu.dm_stop;
        }

        set_hit_stop_hit_quake(&wk->wu);

        if (wk->wu.rl_flag != ((wk->wu.dm_rl + 1) & 1)) {
            wk->wu.rl_flag = ((wk->wu.dm_rl + 1) & 1);
            wk->wu.mvxy.a[0].sp = -wk->wu.mvxy.a[0].sp;
            wk->wu.mvxy.d[0].sp = -wk->wu.mvxy.d[0].sp;
        }

        remake_mvxy_PoSB(&wk->wu);
        set_char_move_init(&wk->wu, 0, 27);
        add_sp_arts_gauge_paring(wk);
        subtract_dm_vital(wk);
        pp_pulpara_blocking(&wk->wu);
        break;

    case 1:
        wk->wu.routine_no[3]++;
        char_move_wca_init(&wk->wu);
        /* fallthrough */

    case 2:
        if (((WORK*)wk->wu.target_adrs)->cg_prio != 2) {
            wk->wu.next_z = 32;
        }

        jumping_union_process(&wk->wu, 3);
        break;

    case 3:
        char_move(&wk->wu);
        break;
    }
}

void Normal_36000(PLW* wk) {
    if (wk->the_same_players) {
        wk->wu.next_z = wk->wu.my_priority + 1;
    }

    char_move(&wk->wu);
}

void Normal_37000(PLW* wk) {
    if (wk->the_same_players) {
        wk->wu.next_z = wk->wu.my_priority + 1;
    }

    char_move(&wk->wu);
}

void Normal_38000(PLW* wk) {
    if (wk->the_same_players) {
        wk->wu.next_z = wk->wu.my_priority + 1;
    }

    switch (wk->wu.routine_no[3]) {
    case 0:
    case 1:
        jumping_union_process(&wk->wu, 2);
        break;

    case 2:
        char_move(&wk->wu);
        break;
    }

    jumping_guard_type_check(wk);
}

void Normal_39000(PLW* wk) {
    if (wk->the_same_players) {
        wk->wu.next_z = wk->wu.my_priority - 1;
    }

    if (wk->wu.routine_no[3]) {
        char_move(&wk->wu);
        return;
    }

    wk->wu.routine_no[3]++;
    set_char_move_init(&wk->wu, 0, 23);
}

void Normal_40000(PLW* wk) {
    wk->wu.next_z = 38;

    if ((Mode_Type == 3) || (Mode_Type == 4)) {
        switch (wk->wu.routine_no[3]) {
        case 0:
            if (wk->wu.now_koc != 0 || (wk->wu.char_index != 0)) {
                set_char_move_init(&wk->wu, 0, 0);
            }

            wk->wu.routine_no[3] = 9;
            break;
        }

        char_move(&wk->wu);
        return;
    }

    win_player(wk);
}

void Normal_41000(PLW* wk) {
    wk->wu.next_z = 34;

    if ((Mode_Type == 3) || (Mode_Type == 4)) {
        switch (wk->wu.routine_no[3]) {
        case 0:
            if (wk->wu.vital_new >= 0 && (wk->wu.now_koc != 0 || wk->wu.char_index != 0)) {
                set_char_move_init(&wk->wu, 0, 0);
            }

            wk->wu.routine_no[3] = 9;
            break;
        }

        char_move(&wk->wu);
        return;
    }

    lose_player(wk);
}

void Normal_42000(PLW* wk) {
    const s16* dadr = nmPB_data[wk->wu.routine_no[2] - 42];

    if (((WORK*)wk->wu.target_adrs)->cg_prio != 2) {
        wk->wu.next_z = 32;
    }

    if (wk->wu.dm_work_id & 11) {
        wk->dm_hos_flag = 1;
    }

    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = (wk->wu.dm_rl + 1) & 1;

        if (dadr[2]) {
            wk->wu.xyz[1].disp.pos = 0;
        }

        set_char_move_init(&wk->wu, 0, dadr[0]);
        setup_mvxy_data(&wk->wu, dadr[1]);
        Flash_MT[(wk->wu.id)] = 2;
        add_sp_arts_gauge_paring(wk);
        set_hit_stop_hit_quake(&wk->wu);

        if (wk->wu.hit_stop > 0) {
            wk->wu.hit_stop = -wk->wu.hit_stop;
            break;
        }

        break;

    case 1:
        if (1) {
            wk->wu.routine_no[3]++;
            char_move_wca(&wk->wu);
        } else {
            /* fallthrough */

        case 2:
            char_move(&wk->wu);
        }

        if (wk->wu.cg_type == 1) {
            wk->wu.routine_no[3]++;
            add_mvxy_speed(&wk->wu);

            if (dadr[2]) {
                effect_G6_init(&wk->wu, wk->wu.weight_level);
            }
        }

        break;

    case 3:
        jumping_union_process(&wk->wu, 4);
        break;

    case 4:
        char_move(&wk->wu);
        break;
    }
}

void Normal_47000(PLW* wk) {
    const s16* datix = nmCE_data[wk->wu.routine_no[2] - 47];

    if (((WORK*)wk->wu.target_adrs)->cg_prio != 2) {
        wk->wu.next_z = 32;
    }

    if (wk->wu.dm_work_id & 11) {
        wk->dm_hos_flag = 1;
    }

    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = wk->wu.rl_waza;

        if (datix[2]) {
            wk->wu.xyz[1].disp.pos = 0;
        }

        set_char_move_init(&wk->wu, 0, datix[0]);
        setup_mvxy_data(&wk->wu, datix[1]);
        wk->wu.hit_stop = -18;
        wk->wu.hit_quake = 0;
        wk->wu.dm_stop = wk->wu.dm_quake = 0;
        add_sp_arts_gauge_nagenuke(wk);
        grade_add_grap_def(wk->wu.id);
        break;

    case 1:
        if (1) {
            wk->wu.routine_no[3]++;
            char_move_wca(&wk->wu);
        } else {
            /* fallthrough */

        case 2:
            char_move(&wk->wu);
        }

        if (wk->wu.cg_type == 1) {
            wk->wu.cg_type = 0;
            wk->wu.routine_no[3]++;
            add_mvxy_speed(&wk->wu);

            if (datix[2]) {
                effect_G6_init(&wk->wu, wk->wu.weight_level);
                break;
            }
        }

        break;

    case 3:
        jumping_union_process(&wk->wu, 4);
        break;

    case 4:
        char_move(&wk->wu);
        break;
    }
}

void Normal_48000(PLW* wk) {
    wk->guard_flag = 3;

    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = wk->wu.rl_waza;
        wk->wu.xyz[1].disp.pos = 0;
        set_char_move_init(&wk->wu, 0, 44);
        setup_mvxy_data(&wk->wu, 27);
        wk->wu.hit_stop = -17;
        wk->wu.hit_quake = 8;
        wk->wu.dm_stop = wk->wu.dm_quake = 0;
        break;

    case 1:
        if (1) {
            wk->wu.routine_no[3]++;
            char_move_wca(&wk->wu);
        } else {
            /* fallthrough */

        case 2:
            char_move(&wk->wu);
        }

        if (wk->wu.cg_type == 1) {
            wk->wu.cg_type = 0;
            wk->wu.routine_no[3]++;
            char_move_wca(&wk->wu);
            add_mvxy_speed(&wk->wu);
            effect_G6_init(&wk->wu, wk->wu.weight_level);
        }

        break;

    case 3:
        char_move(&wk->wu);
        cal_mvxy_speed(&wk->wu);
        add_mvxy_speed(&wk->wu);
        break;
    }
}

void Normal_50000(PLW* wk) {
    wk->guard_flag = 3;

    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = wk->wu.rl_waza;
        set_char_move_init(&wk->wu, 0, 46);
        setup_mvxy_data(&wk->wu, 29);
        wk->wu.hit_stop = -17;
        wk->wu.hit_quake = 8;
        wk->wu.dm_stop = wk->wu.dm_quake = 0;
        return;

    case 1:
        if (1) {
            wk->wu.routine_no[3]++;
            char_move_wca(&wk->wu);
        } else {
            /* fallthrough */

        case 2:
            char_move(&wk->wu);
        }

        if (wk->wu.cg_type == 1) {
            wk->wu.cg_type = 0;
            wk->wu.routine_no[3]++;
            add_mvxy_speed(&wk->wu);
        }

        break;

    case 3:
        jumping_union_process(&wk->wu, 4);
        break;

    case 4:
        char_move(&wk->wu);
        break;
    }
}

void Normal_51000(PLW* wk) {
    if (wk->wu.routine_no[3] == 0) {
        wk->wu.routine_no[3]++;
        set_char_move_init(&wk->wu, 0, 12);
    }
}

void Normal_52000(PLW* wk) {
    wk->guard_flag = 3;

    if (wk->the_same_players) {
        wk->wu.next_z = wk->wu.my_priority + 1;
    }

    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->extra_jump = 1;
        remake_sankaku_tobi_mvxy(&wk->wu, wk->micchaku_flag);
        set_char_move_init(&wk->wu, 0, 48);
        effect_I3_init(&wk->wu, 0);
        break;

    case 1:
        char_move(&wk->wu);

        if (wk->wu.cg_type == 0xFF) {
            wk->wu.routine_no[2] = 21;
            wk->wu.routine_no[3] = 1;
            set_char_move_init(&wk->wu, 0, 14);
            char_move_z(&wk->wu);
            add_mvxy_speed(&wk->wu);
        }

        break;
    }
}

void Normal_53000(PLW* wk) {
    if (wk->the_same_players) {
        wk->wu.next_z = wk->wu.my_priority + 1;
    }

    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->extra_jump = 1;
        set_char_move_init(&wk->wu, 0, 49);
        break;

    case 1:
        char_move(&wk->wu);
        set_new_jpdir(wk);
        if (wk->wu.cg_type == 0xFF) {
            check_jump_rl_dir(wk);

            switch (wk->jpdir) {
            case 1:
                wk->wu.routine_no[2] = 21;
                break;
            case 2:
                wk->wu.routine_no[2] = 23;
                break;
            default:
                wk->wu.routine_no[2] = 22;
                break;
            }

            wk->wu.routine_no[3] = 1;
            set_char_move_init(&wk->wu, 0, jpdat_tbl[wk->wu.routine_no[2] - 18][0]);
            char_move_z(&wk->wu);
            setup_mvxy_data(&wk->wu, jpdat_tbl[wk->wu.routine_no[2] - 18][1]);
            wk->wu.mvxy.a[0].real.h = ((wk->wu.mvxy.a[0].real.h * 3) << 1) / 10;
            wk->wu.mvxy.a[1].real.h = (wk->wu.mvxy.a[1].real.h << 3) / 10;
            add_mvxy_speed(&wk->wu);
        }
        break;
    }
}

/* The check_work_position result is on the left of the comparison. */
void Normal_54000(PLW* wk) {
    if (wk->the_same_players) {
        wk->wu.next_z = wk->wu.my_priority + 1;
    }

    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        set_char_move_init(&wk->wu, 0, 12);
        break;

    case 1:
        char_move(&wk->wu);

        if (wk->wu.cg_type == 0xFF) {
            wk->wu.cg_type = 0;
            wk->wu.routine_no[2] = 18;
            wk->wu.routine_no[3] = 0;

            if (check_work_position(&wk->wu, (WORK*)wk->wu.target_adrs) != wk->wu.rl_flag) {
                wk->wu.routine_no[2] = 20;
            }
        }

        break;
    }
}

void Normal_55000(PLW* wk) {
    if (wk->the_same_players) {
        wk->wu.next_z = wk->wu.my_priority + 1;
    }

    wk->bs2_on_car = 0;

    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->extra_jump = 1;
        set_char_move_init(&wk->wu, 0, 18);
        setup_mvxy_data(&wk->wu, 7);
        make_nm55_init_sp(wk);
        add_mvxy_speed(&wk->wu);
        break;

    case 1:
        jumping_union_process(&wk->wu, 2);
        break;

    case 2:
        char_move(&wk->wu);
        break;
    }
}

void make_nm55_init_sp(PLW* wk) {
    WORK* efw;
    s16* dad;
    s16 ix;
    s16 isp;

    wk->wu.mvxy.a[1].sp /= 3;
    isp = (wk->move_power << 2) / 5;

    if (isp < 3) {
        isp = 3;
    }

    wk->wu.mvxy.a[0].real.h = isp;
    efw = (WORK*)((WORK*)wk->wu.target_adrs)->my_effadrs;
    ix = get_sel_hosei_tbl_ix(wk->player_number) + 1;
    dad = efw->hosei_adrs[ix].hos_box;

    if (!check_work_position_bonus(&wk->wu, dad[0] + (dad[1] / 2) + efw->xyz[0].disp.pos)) {
        if (wk->wu.rl_flag) {
            wk->wu.mvxy.a[0].real.h = -wk->wu.mvxy.a[0].real.h;
        }
        return;
    }

    if (wk->wu.rl_flag == 0) {
        wk->wu.mvxy.a[0].real.h = -wk->wu.mvxy.a[0].real.h;
    }
}

void Normal_56000(PLW* wk) {
    if (wk->the_same_players) {
        wk->wu.next_z = wk->wu.my_priority + 1;
    }

    wk->bs2_on_car = 0;

    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        nm56_char_select(wk);
        add_mvxy_speed(&wk->wu);
        wk->bs2_on_car = 0;
        break;

    case 1:
        jumping_union_process(&wk->wu, 2);
        break;

    case 2:
        char_move(&wk->wu);
        break;
    }
}

void nm56_char_select(PLW* wk) {
    WORK* efw;
    s16* dad;
    s16 ix;

    efw = (WORK*)((WORK*)wk->wu.target_adrs)->my_effadrs;
    ix = get_sel_hosei_tbl_ix(wk->player_number) + 1;
    dad = efw->hosei_adrs[ix].hos_box;
    setup_mvxy_data(&wk->wu, 17);
    ix = 16;

    if (check_work_position_bonus(&wk->wu, dad[0] + (dad[1] / 2) + efw->xyz[0].disp.pos)) {
        if (wk->wu.rl_flag) {
            ix = 14;
        }
    } else if (wk->wu.rl_flag == 0) {
        ix = 14;
    }

    if (ix == 14) {
        wk->wu.mvxy.a[0].sp = -wk->wu.mvxy.a[0].sp;
    }

    set_char_move_init(&wk->wu, 0, ix);
}

void Normal_57000(PLW* wk) {
    if (wk->the_same_players) {
        wk->wu.next_z = wk->wu.my_priority + 1;
    }

    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        nm57_dir_select(wk);
        wk->wu.xyz[1].disp.pos = 0;
        set_char_move_init(&wk->wu, 0, 50);
        setup_mvxy_data(&wk->wu, 18);
        break;

    case 1:
        char_move(&wk->wu);

        if (wk->wu.cg_type == 1) {
            wk->wu.cg_type = 0;
            wk->wu.routine_no[3]++;
            add_mvxy_speed(&wk->wu);
            effect_G6_init(&wk->wu, wk->wu.weight_level);
            break;
        }

        break;

    case 2:
        jumping_union_process(&wk->wu, 3);
        break;

    case 3:
        char_move(&wk->wu);
        break;
    }
}

void nm57_dir_select(PLW* wk) {
    WORK* efw;
    s16* dad;
    s16 ix;

    efw = (WORK*)((WORK*)wk->wu.target_adrs)->my_effadrs;
    ix = get_sel_hosei_tbl_ix(wk->player_number) + 1;
    dad = (s16*)efw->hosei_adrs[ix].hos_box;
    wk->wu.rl_flag = 1;

    if (check_work_position_bonus(&wk->wu, dad[0] + (dad[1] / 2) + efw->xyz[0].disp.pos)) {
        wk->wu.rl_flag = 0;
    }
}

void Normal_58000(PLW* wk) {
    if (wk->the_same_players) {
        wk->wu.next_z = wk->wu.my_priority + 1;
    }

    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        set_char_move_init(&wk->wu, 0, 18);
        setup_mvxy_data(&wk->wu, 7);
        break;

    case 1:
        jumping_union_process(&wk->wu, 2);
        break;

    case 2:
        char_move(&wk->wu);
        break;
    }
}
