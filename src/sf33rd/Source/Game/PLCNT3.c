/* PLCNT3.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * Player_control_bonus2 0x87621 size 0xEF.
 * plcnt_b2_move 0x87710 size 0x7D.
 * plcnt_b2_die 0x8778D size 0x102.
 * Data: player_bonus2_process is 0x2626FC, 3 entries compared.
 * Globals: player_bonus2_process 0x2626FC, No_Death 0x7A80CF, Time_Over
 * 0x7A8150, players_timer 0x7A81F6, Bonus_Stage_RNO 0x7A86F0, Break_Into
 * 0x7A8802, Time_Stop 0x7A8918, Game_pause 0x7A89B0, EXE_flag 0xC7C834, plw
 * 0xC7CEA0, pcon_rno 0xC7E020.
 */

#include "structs.h"

void plcnt_b_init();
void plcnt_b2_move();
void plcnt_b2_die();
extern s16 pcon_rno[4];
extern u8 Game_pause;
extern s16 EXE_flag;
extern u16 players_timer;
s32 check_be_car_object();
void check_body_touch2();
void check_damage_hosei_bonus();
void set_quake(PLW* wk);
extern PLW plw[2];
void hit_push_request(WORK* hpr_wk);
void add_next_position(PLW* wk);
void check_cg_zoom();
void store_player_after_image_data();
extern s8 No_Death;
extern s8 Break_Into;
void move_player_work_bonus();
extern s16 Bonus_Stage_RNO[4];
extern s8 Time_Stop;
extern s8 Time_Over;
s16 footwork_check_bns(s8 ix);
void complete_victory_pause();

void (*const player_bonus2_process[3])() = { plcnt_b_init, plcnt_b2_move, plcnt_b2_die };

s32 Player_control_bonus2() {
    if (((pcon_rno[0] + pcon_rno[1]) == 0) || (!Game_pause && !EXE_flag)) {
        players_timer++;
        players_timer &= 0x7FFF;
        player_bonus2_process[pcon_rno[0]]();

        if (check_be_car_object()) {
            check_body_touch2();
            check_damage_hosei_bonus();
        }

        set_quake(&plw[0]);
        set_quake(&plw[1]);

        if (plw[0].zuru_flag == 0 && plw[0].zettai_muteki_flag == 0) {
            hit_push_request(&plw[0].wu);
        }

        if (plw[1].zuru_flag == 0 && plw[1].zettai_muteki_flag == 0) {
            hit_push_request(&plw[1].wu);
        }

        add_next_position(plw);
        add_next_position(&plw[1]);
        check_cg_zoom();
    }

    if (Game_pause != 0x81) {
        store_player_after_image_data();
    }

    if (pcon_rno[0] == 2 && pcon_rno[1] == 0 && pcon_rno[2] == 2) {
        return 1;
    }

    return 0;
}

void plcnt_b2_move() {
    if (No_Death) {
        plw[0].wu.dm_vital = plw[1].wu.dm_vital = 0;
    }

    if (Break_Into) {
        plw[0].wu.dm_vital = plw[1].wu.dm_vital = 0;
    }

    move_player_work_bonus();

    if (Bonus_Stage_RNO[0] == 2) {
        Time_Stop = 1;
        pcon_rno[0] = 2;
        pcon_rno[1] = 0;
        pcon_rno[2] = 0;
    }

    if (Time_Over) {
        pcon_rno[0] = 2;
        pcon_rno[1] = 0;
        pcon_rno[2] = 0;
    }
}

void plcnt_b2_die() {
    plw[0].wu.dm_vital = plw[1].wu.dm_vital = 0;

    switch (pcon_rno[2]) {
    case 0:
        plw[0].wkey_flag = plw[1].wkey_flag = 1;
        plw[0].image_setup_flag = plw[1].image_setup_flag = 0;
        pcon_rno[2]++;
        /* fallthrough */

    case 1:
        if (footwork_check_bns(0) && footwork_check_bns(1)) {
            pcon_rno[2]++;
        }

        break;

    case 2:
        complete_victory_pause();

        if (plw[0].wu.operator) {
            plw[0].wu.routine_no[1] = 0;
            plw[0].wu.routine_no[2] = 40;
            plw[0].wu.routine_no[3] = 0;
        } else {
            plw[0].wu.routine_no[3] = 9;
        }

        if (plw[1].wu.operator) {
            plw[1].wu.routine_no[1] = 0;
            plw[1].wu.routine_no[2] = 40;
            plw[1].wu.routine_no[3] = 0;
        } else {
            plw[1].wu.routine_no[3] = 9;
        }

        plw[0].wu.cg_type = plw[1].wu.cg_type = 0;
        pcon_rno[2]++;
        break;

    case 3:
        if ((plw[0].wu.routine_no[3] == 9) && (plw[1].wu.routine_no[3] == 9)) {
            pcon_rno[2]++;
        }

        break;
    }

    move_player_work_bonus();
}
