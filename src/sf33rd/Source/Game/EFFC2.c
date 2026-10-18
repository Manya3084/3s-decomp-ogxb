/* EFFC2.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * effc2_parts_work_chain_check 0x45052 size 0x109. FLAG: x86-only globals
 * __security_cookie.
 * c2_last_dir_select 0x4515B size 0x54.
 * setup_demojump 0x451AF size 0x75.
 * check_effc2_p2_rno 0x45224 size 0x29.
 * copy_rno 0x4524D size 0x25.
 * player_hosei_data 0x45272 size 0x7C. Read against the x86: +1 is the + 1 of
 * the hosei index. The C is the PS2 C.
 * set_c2_quake 0x452EE size 0x2F.
 * setup_prio_ix 0x4531D size 0x39. Read against the x86: 0x9E is &wu.vital_new
 * for a store through a pointer. The C is the PS2 C.
 * set_parts_priority 0x45356 size 0x38.
 * setup_vital_bonus2 0x4538E size 0x2A. Read against the x86: 0x16A is
 * &wu.cmwk[0] and 0x1C6 the distance to a second array walked with it. The C
 * is the PS2 C.
 * c3_new_damage 0x453B8 size 0x10D.
 * bs2_sync_bomb 0x454C5 size 0x12.
 * bs2_get_parts_break 0x454D7 size 0x26.
 * setup_parts_break 0x454FD size 0x7F. Read against the x86: 0x64 is the C's /
 * 100, and 0x16A is &wk->cmwk[0], the array the loop stores into (shell_ix is
 * read at 0x330). Matches the C.
 * setup_parts_break2 0x4557C size 0x43. Read against the x86: 0x64 is the /
 * 100 of vint * pbl_select / 100. The C is the PS2 C.
 * check_parts_break_level 0x455BF size 0x87.
 * bs2_score_add_next 0x45646 size 0x39. Read against the x86: 0x16C is
 * &wk->cmwk[1], the loop start (i from 1 to 7). The C is the PS2 C.
 * set_1st_Bonus_Game_result 0x4567F size 0x30. Read against the x86: 0x16C is
 * &wk->cmwk[1], the loop start. The C is the PS2 C.
 * set_bs2_floor 0x456AF size 0x99. Read against the x86: 8 is the hosei record
 * size in the index scale. The C is the PS2 C.
 * get_shizumi_guai 0x45748 size 0x37.
 * send_to_shizumi_guai 0x4577F size 0x20.
 * effC2_main_process_first 0x4579F size 0x284.
 * effC2_main_process_second 0x45A23 size 0x296.
 * c2_last_char_and_mvxy 0x45CB9 size 0x4F. Read against the x86: 0x5C is the +
 * 92 of dm_attlv + 92 + ix, with lea. The C is the PS2 C.
 * get_bs2_parts_data 0x45D08 size 0x87.
 * effect_C2_move 0x45D8F size 0x28B. Read against the x86: 0xFD is a step of
 * the switch compare chain. The C is the PS2 C.
 * effect_C2_init 0x4601A size 0x83.
 * Not located in sf33rd.xbe; their PS2 C is kept under #if 0:
 * c3_hit_disp_check, bs2_status_disp.
 * setup_effK4 is folded into 0x4384A.
 * Data: bs2_data_table is 0x252F00, 0x60 bytes compared.
 * Data: dm_copy_to_master is 0x252F60, 0x10 bytes compared.
 * Data: ix_exchange is 0x252F70, 0x10 bytes compared.
 * Data: sel_dm_quake is 0x252F80, 0x40 bytes compared.
 * Data: pbl_select is 0x252FC0, 0x80 bytes compared.
 * Data: pbs_table is 0x253040, 0x80 bytes compared.
 * Data: shizumi_guai is 0x2530C0, 0xD0 bytes compared.
 * Data: shindou_guai is 0x253190, 0x70 bytes compared.
 * Data: c2_last_bomb is 0x253200, 0x20 bytes compared.
 * Globals: bs2_data_table 0x252F00, dm_copy_to_master 0x252F60, ix_exchange
 * 0x252F70, sel_dm_quake 0x252F80, pbl_select 0x252FC0, pbs_table 0x253040,
 * shizumi_guai 0x2530C0, shindou_guai 0x253190, c2_last_bomb 0x253200,
 * __security_cookie 0x43CF74, bs2_floor 0x7A80C0, Time_Over 0x7A8150,
 * bs2_current_damage 0x7A82D2, bs2_hosei 0x7A82E8, Bonus_Game_result 0x7A881A,
 * Time_Stop 0x7A8918, Game_pause 0x7A89B0, EXE_flag 0xC7C834, frw 0xC806A0.
 */

#include "structs.h"

#define EFFECT_MAX 128

typedef struct {
    
    s16 dir_timer; 
    s16 chix;      
    s16 vital;     
    s16 color;     
    s16 prio_hi;   
    s16 prio_low;  
} BS2;

void sub_0004384A(WORK* wk);
void bs2_status_disp(WORK_Other* );
extern s16 Bonus_Game_result;
void set_char_base_data(WORK* wk);
void setup_prio_ix(WORK_Other* c2wk);
void get_bs2_parts_data(WORK* wk);
void setup_vital_bonus2(WORK* wk);
s32 effect_C3_init(WORK_Other* wk, s16 data);
s32 effect_00_init(WORK* wk);
void clear_attack_num(WORK* wk);
s32 effect_J9_init(WORK_Other* wk, u8 data);
void effC2_main_process_second(WORK_Other* ewk, PLW* twk);
void effC2_main_process_first(WORK_Other* ewk, PLW* twk);
void set_bs2_floor(WORK_Other* wk);
extern s16 EXE_flag;
extern u8 Game_pause;
void illegal_setup_effK2(WORK* wk, s16 ix);
void c2_last_char_and_mvxy(WORK_Other* ewk);
void setup_demojump(PLW* twk, s16 ix);
void char_move(WORK* wk);
void add_mvxy_speed(WORK* wk);
void cal_mvxy_speed(WORK* wk);
void char_move_cmja(WORK* wk);
void add_mvxy_speed_direct(WORK* wk, s16 sx, s16 sy);
void set_c2_quake(WORK* wk);
s32 sort_push_request(WORK* wk);
void push_effect_work(WORK* wkhd);
void set_char_move_init(WORK* wk, s16 koc, s16 index);
s32 check_parts_break_level(WORK* wk);
void player_hosei_data(WORK_Other* ewk, s16 flag, s16 f2);
void setup_parts_break(WORK* wk);
void send_to_shizumi_guai(WORK* wk);
void copy_rno(WORK* wk);
void effc2_parts_work_chain_check(s16 flag);
s16 search_effect_index(s16 index, s16 flag, s16 tid);
extern uintptr_t frw[EFFECT_MAX][448];
extern s8 Time_Stop;
void bs2_score_add_next(WORK* wk);
void set_1st_Bonus_Game_result(WORK* wk);
void reset_mvxy_data(WORK* wk);
void char_move_z(WORK* wk);
extern s8 Time_Over;
void setup_parts_break2(WORK* wk);
void setup_effK2(WORK* wk);
void hit_push_request(WORK* hpr_wk);
void set_parts_priority(WORK* wk);
s16 c2_last_dir_select(PLW* wk, WORK* efw);
void setup_move_data_easy(WORK* wk, const s16* adrs, s16 prx, s16 pry);
s16 get_sel_hosei_tbl_ix(s16 plnum);
s16 check_work_position_bonus(WORK* hm, s16 tx);
extern s16 bs2_current_damage;
void Additinal_Score_DM(WORK_Other* wk, u16 ix);
extern s16 bs2_floor[3];
extern s16 bs2_hosei[3];
s16 pull_effect_work(s16 index);

const BS2 bs2_data_table[8] = { { 0, 70, 400, 8492, 30, 66 }, { 0, 60, 0, 8492, 29, 65 },
                                { 0, 50, 0, 8492, 29, 65 },   { 0, 0, 300, 8492, 28, 64 },
                                { 0, 40, 500, 8492, 27, 63 }, { 0, 30, 500, 8492, 27, 63 },
                                { 0, 20, 0, 8492, 26, 62 },   { 0, 10, 0, 8492, 26, 62 } };

const s16 dm_copy_to_master[8] = { 0, 4, 4, 2, 4, 4, 4, 4 };

const s16 ix_exchange[8] = { 0, 4, 5, 3, 4, 5, 4, 5 };

const s16 sel_dm_quake[4][8] = { { 80, 80, 80, 80, 80, 80, 80, 80 },
                                 { 82, 82, 82, 82, 82, 82, 82, 82 },
                                 { 84, 84, 84, 84, 84, 84, 84, 84 },
                                 { 84, 84, 84, 84, 84, 84, 84, 84 } };

const s16 pbl_select[8][8] = { { 90, 70, 50, 30, 20, 10, 0, 0 }, { 80, 70, 50, 30, 20, 10, 0, 0 },
                               { 80, 70, 50, 30, 20, 10, 0, 0 }, { 90, 80, 70, 50, 30, 10, 0, 0 },
                               { 80, 70, 50, 30, 20, 10, 0, 0 }, { 80, 70, 50, 30, 20, 10, 0, 0 },
                               { 80, 70, 50, 30, 20, 10, 0, 0 }, { 80, 70, 50, 30, 20, 10, 0, 0 } };

const s16 pbs_table[8][8] = { { 8, 9, 10, 18, 11, 12, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0 },
                              { 0, 0, 0, 0, 0, 0, 0, 0 },     { 6, 7, 8, 9, 10, 10, 10, 20 },
                              { 6, 6, 7, 7, 8, 9, 18, 19 },   { 6, 6, 7, 7, 8, 9, 18, 19 },
                              { 0, 0, 0, 0, 0, 0, 0, 0 },     { 0, 0, 0, 0, 0, 0, 0, 0 } };

const s16 shizumi_guai[13][8] = { { 0, 0, 0, 0, 0, 0, 0, 0 },       { -2, 0, 0, 0, 0, 0, 0, 0 },
                                  { -3, 0, 0, -2, -2, -2, -2, -2 }, { -3, 0, 0, -3, -3, -3, -3, -3 },
                                  { -2, 0, 0, -3, -3, -3, -3, -3 }, { -2, 0, 0, -2, -2, -2, -2, -2 },
                                  { -1, 0, 0, -2, -2, -2, -2, -2 }, { 0, 0, 0, -1, -1, -1, -1, -1 },
                                  { 0, 0, 0, -2, -2, -2, -2, -2 },  { 0, 0, 0, 1, 1, 1, 1, 1 },
                                  { 0, 0, 0, 2, 2, 2, 2, 2 },       { 0, 0, 0, -1, -1, -1, -1, -1 },
                                  { 0, 0, 0, -2, -2, -2, -2, -2 } };

const s16 shindou_guai[7][8] = { { 0, 0, 0, 0, 0, 0, 0, 0 },      { 0, 0, 0, 1, 1, 1, 1, 1 },
                                 { 0, 0, 0, 2, 2, 2, 2, 2 },      { 0, 0, 0, 3, 3, 3, 3, 3 },
                                 { 0, 0, 0, -1, -1, -1, -1, -1 }, { 0, 0, 0, -2, -2, -2, -2, -2 },
                                 { 0, 0, 0, -3, -3, -3, -3, -3 } };

const s16 c2_last_bomb[4][4] = {
    { 1024, 0, 1024, -112 }, { 896, 0, 1280, -112 }, { 768, 0, 1536, -112 }, { 640, 0, 1792, -112 }
};

void effect_C2_move(WORK_Other* ewk) {
    bs2_status_disp(ewk);

    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.routine_no[2] = 0;
        ewk->wu.routine_no[3] = 2;
        Bonus_Game_result = 0;
        ewk->wu.charset_id = 17;
        set_char_base_data(&ewk->wu);
        ewk->wu.vital_new = ewk->master_id == 0;
        setup_prio_ix(ewk);
        get_bs2_parts_data(&ewk->wu);
        setup_vital_bonus2(&ewk->wu);
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos;
        ewk->wu.cg_number = 9;
        effect_C3_init(ewk, 3);
        effect_C3_init(ewk, 4);
        effect_C3_init(ewk, 5);
        effect_C3_init(ewk, 6);
        effect_C3_init(ewk, 7);
        effect_C3_init(ewk, 1);
        effect_C3_init(ewk, 2);
        effect_00_init(&ewk->wu);
        clear_attack_num(&ewk->wu);
        ewk->wu.dir_old = 0;
        ewk->wu.direction = 0;
        ewk->wu.dir_timer = 0;
        ewk->wu.routine_no[1] = 0;
        ewk->wu.routine_no[2] = 0;
        effect_J9_init(ewk, 8);
        break;

    case 1:
        if (ewk->wu.dead_f == 1) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0] = 2;
            ewk->wu.routine_no[1] = 10;
            ewk->wu.hit_stop = 0;
            break;
        }

        if (ewk->wu.dir_timer) {
            effC2_main_process_second(ewk, (PLW*)ewk->wu.target_adrs);
        } else {
            effC2_main_process_first(ewk, (PLW*)ewk->wu.target_adrs);
        }

        set_bs2_floor(ewk);
        break;

    case 2:
        if (EXE_flag == 0 && Game_pause == 0) {
            switch (ewk->wu.routine_no[1]) {
            case 0:
                if (--ewk->wu.hit_stop > 0) {
                    break;
                }

                ewk->wu.routine_no[1] = 9;
                ewk->wu.routine_no[2] = 0;
                Bonus_Game_result |= 2;
                ewk->wu.xyz[1].disp.pos = 80;
                ewk->wu.next_y = 64;
                ewk->wu.position_z = 25;
                illegal_setup_effK2(&ewk->wu, 4);
                c2_last_char_and_mvxy(ewk);
                setup_demojump((PLW*)ewk->wu.target_adrs, 2);
                break;

            case 9:
                switch (ewk->wu.routine_no[2]) {
                case 0:
                    char_move(&ewk->wu);
                    add_mvxy_speed(&ewk->wu);
                    cal_mvxy_speed(&ewk->wu);

                    if (ewk->wu.mvxy.a[1].sp <= 0 && (ewk->wu.xyz[1].disp.pos <= ewk->wu.next_y)) {
                        ewk->wu.xyz[1].disp.pos = ewk->wu.next_y;
                        ewk->wu.routine_no[2] = 1;
                        char_move_cmja(&ewk->wu);
                    }

                    break;

                case 1:
                    char_move(&ewk->wu);

                    switch (ewk->wu.cg_type) {
                    case 1:
                        if (ewk->wu.mvxy.a[0].sp > 0) {
                            add_mvxy_speed_direct(&ewk->wu, 128, 0);
                        } else {
                            add_mvxy_speed_direct(&ewk->wu, -128, 0);
                        }

                        break;

                    case 2:
                        if (ewk->wu.mvxy.a[0].sp > 0) {
                            add_mvxy_speed_direct(&ewk->wu, 256, 0);
                        } else {
                            add_mvxy_speed_direct(&ewk->wu, -256, 0);
                        }

                        break;

                    case 0xFF:
                        ewk->wu.routine_no[2] = 2;
                        break;
                    }

                    break;
                }

                break;

            default:
                ewk->wu.routine_no[0] = 3;
                ewk->wu.routine_no[1] = 0;
                break;
            }

            ewk->wu.next_x = 0;
            set_c2_quake(&ewk->wu);
        }

        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos + ewk->wu.next_x;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos;
        sort_push_request(&ewk->wu);
        break;

    default:
        push_effect_work(&ewk->wu);
        break;
    }
}

void effC2_main_process_first(WORK_Other* ewk, PLW* twk) {
    if (EXE_flag == 0 && Game_pause == 0) {
        switch (ewk->wu.direction + (twk->bs2_on_car * 2)) {
        case 0:
            if (ewk->wu.routine_no[1] != 1 && ewk->wu.routine_no[2] != 0) {
                ewk->wu.routine_no[2] = 0;
                ewk->wu.routine_no[3] = 2;
            }

            break;

        case 3:
            if (ewk->wu.routine_no[1] != 1 && ewk->wu.routine_no[2] != 1) {
                ewk->wu.routine_no[2] = 1;
                ewk->wu.routine_no[3] = 2;
            }

            break;

        case 1:
            if (ewk->wu.routine_no[1] != 1 || ewk->wu.routine_no[2] != 0) {
                ewk->wu.routine_no[1] = 0;
                ewk->wu.routine_no[2] = 0;
                ewk->wu.routine_no[3] = 0;
            }

            break;

        case 2:
            if (ewk->wu.routine_no[1] != 1 || ewk->wu.routine_no[2] != 0) {
                ewk->wu.routine_no[1] = 0;
                ewk->wu.routine_no[2] = 1;
                ewk->wu.routine_no[3] = 0;
            }

            break;
        }

        ewk->wu.old_pos[0] = ewk->wu.old_pos[1] = 0;

        switch (ewk->wu.routine_no[1]) {
        case 0:
            switch (ewk->wu.routine_no[2]) {
            case 0:
                switch (ewk->wu.routine_no[3]) {
                case 0:
                    ewk->wu.routine_no[3]++;
                    set_char_move_init(&ewk->wu, 0, 76);
                    break;

                case 1:
                    char_move(&ewk->wu);

                    if (ewk->wu.cg_type != 0xFF) {
                        break;
                    }

                    ewk->wu.routine_no[3]++;
                    /* fallthrough */

                default:
                    ewk->wu.cg_type = 0;
                    ewk->wu.cg_number = 9;
                    break;
                }

                break;

            default:
                switch (ewk->wu.routine_no[3]) {
                case 0:
                    ewk->wu.routine_no[3]++;
                    set_char_move_init(&ewk->wu, 0, 77);
                    break;

                case 1:
                    char_move(&ewk->wu);

                    if (ewk->wu.cg_type != 0xFF) {
                        break;
                    }

                    ewk->wu.routine_no[3]++;
                    /* fallthrough */

                default:
                    ewk->wu.cg_type = 0;
                    ewk->wu.cg_number = 18;
                    break;
                }
            }

            ewk->wu.old_pos[0] = ewk->wu.cg_type;
            ewk->wu.cg_type = 0;
            break;

        case 1:
            switch (ewk->wu.routine_no[2]) {
            case 0:
                ewk->wu.shell_ix[0] -= ewk->wu.dm_vital;
                ewk->wu.dm_vital = 0;

                if (twk->bs2_on_car) {
                    ewk->wu.hit_stop = 0;
                } else {
                    ewk->wu.hit_stop = ewk->wu.dm_stop / 2;
                }

                ewk->wu.routine_no[2] = 1;
                set_char_move_init(&ewk->wu,
                                   0,
                                   (twk->bs2_on_car * 6) +
                                       ((ewk->wu.dm_rl == 0) + sel_dm_quake[ewk->wu.dm_attlv][ewk->wu.rl_waza]));

                if (ewk->wu.shell_ix[0] < 0) {
                    ewk->wu.dir_old = 1;
                    ewk->wu.dir_timer = 1;
                    ewk->wu.routine_no[1] = 0;
                    ewk->wu.routine_no[2] = 9;
                    break;
                }

                check_parts_break_level(&ewk->wu);
                /* fallthrough */

            case 1:
                if (--ewk->wu.hit_stop <= 0) {
                    char_move(&ewk->wu);

                    if (ewk->wu.cg_type == 0xFF) {
                        ewk->wu.routine_no[1] = 0;
                        ewk->wu.routine_no[2] = 0;
                        ewk->wu.cg_type = 0;
                    }
                }

                break;
            }

            ewk->wu.old_pos[1] = ewk->wu.cg_type;
            ewk->wu.cg_type = 0;
            break;
        }
    }

    player_hosei_data(ewk, ewk->wu.dir_timer, 1);
    setup_parts_break(&ewk->wu);
    setup_prio_ix(ewk);
    send_to_shizumi_guai(&ewk->wu);
    ewk->wu.direction = twk->bs2_on_car;
    copy_rno(&ewk->wu);

    if (!ewk->wu.dir_timer) {
        effc2_parts_work_chain_check(ewk->wu.vital_new);
    }
}

void effc2_parts_work_chain_check(s16 flag) {
    WORK* adr0;
    WORK* adr1;
    WORK* adr2;
    WORK* adr3;
    s16 wix = search_effect_index(1, 0, 0x7B);
    s16 bff;
    s16 bhf;
    s16 bf[4];
    s16 bh[4];

    if (wix == -1) {
        return;
    }

    while (wix != -1) {
        adr1 = (WORK*)frw[wix];

        if (adr1->type == 4 || adr1->type == 5) {
            goto jump;
        }

        wix = adr1->behind;
    }

    return;

jump:
    if (flag) {
        if (adr1->type == 4) {
            return;
        }
    } else if (adr1->type == 5) {
        return;
    }

    if (adr1->behind == -1) {
        return;
    }

    adr2 = (WORK*)frw[adr1->behind];

    if (flag) {
        if (adr2->type != 4) {
            return;
        }
    } else if (adr2->type != 5) {
        return;
    }

    bff = bhf = 0;
    adr0 = (WORK*)frw[adr1->before];
    adr3 = (WORK*)frw[adr2->behind];
    bf[1] = adr1->before;
    bf[2] = adr2->before;
    bf[3] = adr3->before;
    bh[0] = adr0->behind;
    bh[1] = adr1->behind;
    bh[2] = adr2->behind;
    adr0->behind = bh[1];
    adr1->behind = bh[2];
    adr2->behind = bh[0];
    adr1->before = bf[3];
    adr2->before = bf[1];
    adr3->before = bf[2];
}

void effC2_main_process_second(WORK_Other* ewk, PLW* twk) {
    if (EXE_flag == 0 && Game_pause == 0) {
        switch (ewk->wu.routine_no[1]) {
        case 0:
            switch (ewk->wu.routine_no[2]) {
            case 0:
                break;

            case 9:
                if (ewk->wu.hit_stop == 0) {
                    illegal_setup_effK2(&ewk->wu, 0);
                }

                if (--ewk->wu.hit_stop < 0) {
                    Time_Stop = 1;
                    setup_demojump(twk, 0);
                    ewk->wu.routine_no[2]++;
                    ewk->wu.mvxy.a[1].sp = 0x20000;
                    ewk->wu.mvxy.d[1].sp = -0x8000;
                    ewk->wu.xyz[1].disp.pos = 64;
                    set_char_move_init(&ewk->wu, 0, 71);
                    ewk->wu.disp_flag = 1;
                    bs2_score_add_next(&ewk->wu);
                    set_1st_Bonus_Game_result(&ewk->wu);
                }

                break;

            case 10:
                add_mvxy_speed(&ewk->wu);
                cal_mvxy_speed(&ewk->wu);

                if (ewk->wu.xyz[1].disp.pos <= 0) {
                    ewk->wu.routine_no[2]++;
                    ewk->wu.position_y = 0;
                    ewk->wu.xyz[1].cal = 0;
                    ewk->wu.mvxy.a[1].sp = 0;
                    reset_mvxy_data(&ewk->wu);
                    char_move_z(&ewk->wu);
                    illegal_setup_effK2(&ewk->wu, 1);
                }

                break;

            case 11:
                char_move(&ewk->wu);

                switch (ewk->wu.cg_type) {
                case 2:
                    illegal_setup_effK2(&ewk->wu, 2);
                    ewk->wu.cg_type = 0;
                    break;

                case 3:
                    illegal_setup_effK2(&ewk->wu, 3);
                    ewk->wu.cg_type = 0;
                    break;
                }

                if (ewk->wu.cg_type == 0xFF) {
                    set_char_move_init(&ewk->wu, 0, 70);
                    ewk->wu.dir_old = 0;
                    ewk->wu.routine_no[2] = 0;
                    ewk->wu.original_vitality = ewk->wu.shell_ix[0] = 0x640;
                    ewk->wu.vital_old = 0;
                    Time_Stop = 0;
                }

                break;
            }

            break;

        case 1:
            switch (ewk->wu.routine_no[2]) {
            case 0:
                if (Time_Over) {
                    ewk->wu.dm_vital = 0;
                }

                ewk->wu.shell_ix[0] -= ewk->wu.dm_vital;
                ewk->wu.dm_vital = 0;
                ewk->wu.hit_stop = ewk->wu.dm_stop;

                if (ewk->wu.hit_stop < 0) {
                    ewk->wu.hit_stop = -ewk->wu.hit_stop;
                }

                ewk->wu.hit_stop /= 2;
                ewk->wu.routine_no[2] = 1;
                setup_parts_break2(&ewk->wu);

                if (check_parts_break_level(&ewk->wu) != 0) {
                    char_move_z(&ewk->wu);
                    setup_effK2(&ewk->wu);
                }

                sub_0004384A(&ewk->wu);

                if (ewk->wu.shell_ix[0] < 0 || ewk->wu.cg_type == 0xFF) {
                    ewk->wu.dir_old = 1;
                    ewk->wu.routine_no[0] = 2;
                    ewk->wu.routine_no[1] = 0;
                    ewk->wu.routine_no[2] = 0;
                    ewk->wu.cg_type = 0;
                    Time_Stop = 1;
                }

                break;

            case 1:
                if (--ewk->wu.hit_stop <= 0) {
                    ewk->wu.routine_no[1] = 0;
                    ewk->wu.routine_no[2] = 0;
                }

                break;
            }

            break;
        }

        if (ewk->wu.dir_old == 0) {
            hit_push_request(&ewk->wu);
        }

        ewk->wu.next_x = 0;
        set_c2_quake(&ewk->wu);
    }

    setup_prio_ix(ewk);
    set_parts_priority(&ewk->wu);
    player_hosei_data(ewk, ewk->wu.dir_timer, 1);
    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos + ewk->wu.next_x;
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos;
    sort_push_request(&ewk->wu);
}

void c2_last_char_and_mvxy(WORK_Other* ewk) {
    s16 ix = c2_last_dir_select((PLW*)ewk->wu.target_adrs, &ewk->wu);

    set_char_move_init(&ewk->wu, 0, ewk->wu.dm_attlv + 92 + ix);
    setup_move_data_easy(&ewk->wu, c2_last_bomb[ewk->wu.dm_attlv], 1, 0);

    if (ix) {
        ewk->wu.mvxy.a[0].sp = -ewk->wu.mvxy.a[0].sp;
    }
}

s16 c2_last_dir_select(PLW* wk, WORK* efw) {
    s16 ix = get_sel_hosei_tbl_ix(wk->player_number) + 1;
    s16* dad = efw->hosei_adrs[ix].hos_box;

    ix = 4;

    if (check_work_position_bonus(&wk->wu, dad[0] + (dad[1] / 2) + efw->xyz[0].disp.pos)) {
        ix = 0;
    }

    return ix;
}

void setup_demojump(PLW* twk, s16 ix) {
    switch (ix) {
    case 0:
        if (twk->wu.xyz[1].disp.pos > 3) {
            twk->wu.routine_no[1] = 0;
            twk->wu.routine_no[2] = 56;
            twk->wu.routine_no[3] = 0;
        }

        break;

    case 1:
        if (twk->bs2_on_car) {
            twk->wu.routine_no[1] = 0;
            twk->wu.routine_no[2] = 58;
            twk->wu.routine_no[3] = 0;
        }

        break;

    case 2:
        if ((twk->wu.pat_status >= 14 && twk->wu.pat_status <= 30) || twk->bs2_on_car) {
            twk->wu.routine_no[1] = 0;
            twk->wu.routine_no[2] = 56;
            twk->wu.routine_no[3] = 0;
        }

        break;
    }

    if (twk->wu.hit_stop) {
        twk->wu.hit_stop /= 2;

        if (twk->wu.hit_stop == 0) {
            twk->wu.hit_stop = 1;
        }
    }
}

s32 check_effc2_p2_rno(WORK* wk) {
    WORK* c2wk = (WORK*)wk->my_effadrs;

    if (c2wk->dir_timer == 0) {
        return 0;
    }

    if (c2wk->routine_no[1] != 0 || c2wk->routine_no[2] != 10) {
        return 0;
    }

    return 1;
}

void copy_rno(WORK* wk) {
    wk->old_rno[0] = wk->routine_no[0];
    wk->old_rno[1] = wk->routine_no[1];
    wk->old_rno[2] = wk->routine_no[2];
    wk->old_rno[3] = wk->routine_no[3];
}

void player_hosei_data(WORK_Other* ewk, s16 flag, s16 f2) {
    if (f2) {
        if (ewk->wu.type) {
            ewk->wu.cg_ja.hoix = get_sel_hosei_tbl_ix(ewk->master_player) + 1 + ((flag == 1) * 2);
            ewk->wu.h_hos = &ewk->wu.hosei_adrs[ewk->wu.cg_ja.hoix];
        } else {
            ewk->wu.cg_ja.hoix = get_sel_hosei_tbl_ix(ewk->master_player) + ((flag == 1) * 2);
            ewk->wu.h_hos = &ewk->wu.hosei_adrs[ewk->wu.cg_ja.hoix];
        }
    } else {
        ewk->wu.cg_ja.hoix = 0;
        ewk->wu.h_hos = &ewk->wu.hosei_adrs[ewk->wu.cg_ja.hoix];
    }
}

void set_c2_quake(WORK* wk) {
    if (!wk->hit_stop) {
        return;
    }

    if (wk->hit_stop & 1) {
        wk->next_x = -1;
    }

    if (wk->hit_stop > 6) {
        wk->next_x *= 2;
    }

    if (wk->dm_rl) {
        wk->next_x = -wk->next_x;
    }
}

void get_bs2_parts_data(WORK* wk) {
    const BS2* bs2 = &bs2_data_table[wk->type];

    wk->work_id = 2;
    wk->dir_timer = bs2->dir_timer;
    wk->dir_step = bs2->chix;
    wk->my_col_code = bs2->color;
    wk->xyz[0].disp.pos = 448;
    wk->xyz[1].disp.pos = 0;
    wk->my_priority = bs2->prio_low;
    wk->vital_old = 0;
    wk->dmcal_m = 1;
    wk->dmcal_d = 2;
    wk->dm_vital = 0;
    wk->dir_atthit = -1;
    wk->vs_id = -1;
    set_parts_priority(wk);
}

void setup_prio_ix(WORK_Other* c2wk) {
    PLW* mwk = (PLW*)c2wk->my_master;
    PLW* twk = (PLW*)mwk->wu.target_adrs;

    c2wk->wu.vital_new = 0;

    if (twk->bs2_on_car || twk->bs2_over_car2 || mwk->wu.xyz[0].disp.pos < twk->wu.xyz[0].disp.pos) {
        c2wk->wu.vital_new = 1;
    }
}

void set_parts_priority(WORK* wk) {
    const BS2* bs2 = &bs2_data_table[wk->type];
    WORK* c2wk = (WORK*)wk->my_effadrs;

    if (c2wk->vital_new) {
        wk->my_priority = bs2->prio_low;
    } else {
        wk->my_priority = bs2->prio_hi;
    }

    wk->position_z = wk->my_priority;
}

void setup_vital_bonus2(WORK* wk) {
    s16 i;

    for (i = 0; i < 8; i++) {
        wk->shell_ix[i] = bs2_data_table[i].vital;
        wk->cmwk[i] = 0;
    }
}

void c3_new_damage(WORK* wk) {
    WORK* c2wk;
    s16 ix;
    s16 brlv;

    if (Time_Over) {
        wk->dm_vital = 0;
    }

    c2wk = (WORK*)wk->my_effadrs;
    c2wk->routine_no[1] = 1;
    c2wk->routine_no[2] = 0;
    c2wk->dm_attlv = wk->dm_attlv;
    c2wk->dm_rl = wk->dm_rl;
    c2wk->dm_dir = wk->dm_dir;
    c2wk->dm_stop = wk->dm_stop;
    c2wk->rl_waza = wk->type;

    if (c2wk->dm_stop < 0) {
        c2wk->dm_stop = -c2wk->dm_stop;
    }

    wk->dm_vital = (wk->dm_vital * wk->dmcal_m) / wk->dmcal_d;
    ix = ix_exchange[wk->type];
    brlv = dm_copy_to_master[wk->type];
    c2wk->shell_ix[ix] -= wk->dm_vital;

    if (c2wk->shell_ix[ix] <= 0) {
        c2wk->dm_vital += wk->dm_vital;
        c2wk->shell_ix[ix] = 0;
    } else if (c2wk->cmwk[ix] >= brlv) {
        c2wk->dm_vital += wk->dm_vital / 2;
    }

    wk->dm_vital = 0;
    bs2_current_damage = wk->type;
}

s16 bs2_sync_bomb(WORK* wk) {
    return ((WORK*)wk->my_effadrs)->dir_old;
}

void bs2_get_parts_break(WORK* wk) {
    wk->scr_mv_x = ((WORK*)wk->my_effadrs)->cg_number;
    wk->scr_mv_y = ((WORK*)wk->my_effadrs)->cmwk[wk->type];
}

void setup_parts_break(WORK* wk) {
    s32 vint;
    s16 i;
    s16 j;
    s16 ix;

    for (i = 0; i < 8; i++) {
        ix = ix_exchange[i];
        vint = bs2_data_table[ix].vital;

        for (j = 0; j < 7; j++) {
            if (wk->shell_ix[ix] > (vint * pbl_select[ix][j]) / 100) {
                break;
            }
        }

        wk->cmwk[i] = j;
    }
}

void setup_parts_break2(WORK* wk) {
    s32 vint = wk->original_vitality;
    s16 j;

    for (j = 0; j < 7; j++) {
        if (wk->shell_ix[0] > (vint * pbl_select[0][j]) / 100) {
            break;
        }
    }

    wk->cmwk[0] = j;
}

s32 check_parts_break_level(WORK* wk) {
    WORK* c2wk = (WORK*)wk->my_effadrs;
    s16 i;

    if (wk->vital_old == c2wk->cmwk[wk->type]) {
        return 0;
    }

    if ((wk->id != 0x7A || c2wk->dir_timer != 0) && wk->vital_old < c2wk->cmwk[wk->type]) {
        for (i = wk->vital_old; i < c2wk->cmwk[wk->type]; i++) {
            Additinal_Score_DM((WORK_Other*)wk->target_adrs, pbs_table[wk->type][i]);
        }
    }

    wk->vital_old = c2wk->cmwk[wk->type];
    return 1;
}

void bs2_score_add_next(WORK* wk) {
    s16 i;

    for (i = 1; i < 8; i++) {
        Additinal_Score_DM((WORK_Other*)wk->target_adrs, pbs_table[i][wk->cmwk[i]]);
    }
}

void set_1st_Bonus_Game_result(WORK* wk) {
    s16 i;
    s16 num = 0;

    for (i = 1; i < 8; i++) {
        num += wk->cmwk[i];
    }

    if (num == 49) {
        Bonus_Game_result = 1;
    }
}

void set_bs2_floor(WORK_Other* wk) {
    PLW* em = (PLW*)((WORK*)wk->my_master)->target_adrs;
    s16* dad;

    player_hosei_data(wk, wk->wu.dir_timer, 1);
    dad = wk->wu.hosei_adrs[wk->wu.cg_ja.hoix].hos_box;
    bs2_floor[0] = wk->wu.xyz[0].disp.pos + dad[0];
    bs2_floor[1] = wk->wu.xyz[0].disp.pos + dad[0] + dad[1];
    bs2_floor[2] = dad[2] + dad[3];
    dad = wk->wu.hosei_adrs[wk->wu.cg_ja.hoix + 1].hos_box;
    bs2_hosei[0] = wk->wu.xyz[0].disp.pos + dad[0];
    bs2_hosei[1] = wk->wu.xyz[0].disp.pos + dad[0] + dad[1];
    bs2_hosei[2] = dad[2] + dad[3];
}

void get_shizumi_guai(WORK* wk) {
    wk->next_x = shindou_guai[((WORK*)wk->my_effadrs)->old_pos[1]][wk->type];
    wk->next_y = shizumi_guai[((WORK*)wk->my_effadrs)->old_pos[0]][wk->type];
}

void send_to_shizumi_guai(WORK* wk) {
    ((WORK*)wk->target_adrs)->next_y = shizumi_guai[((WORK*)wk->my_effadrs)->old_pos[0]][0];
}

s32 effect_C2_init(WORK* wk, u8 data) {
    WORK_Other* ewk;
    s16 ix;

    if ((ix = pull_effect_work(1)) == -1) {
        return -1;
    }

    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 0x7A;
    ewk->wu.type = data;
    ewk->wu.my_mts = 5;
    ewk->my_master = (u32*)wk;
    ewk->wu.target_adrs = (u32*)wk->target_adrs;
    ewk->master_player = ((PLW*)wk)->player_number;
    ewk->master_id = wk->id;
    ewk->master_work_id = wk->work_id;
    wk->my_effadrs = (u32*)ewk;
    ewk->wu.my_effadrs = (u32*)ewk;
    effect_C2_move(ewk);
    return 0;
}

#if 0
/* PS2 C for functions not located in sf33rd.xbe yet. */

s16 c3_hit_disp_check(u8 ix) {
    return bs2_data_table[ix].vital;
}

void bs2_status_disp(WORK_Other* /* unused */) {
    if (Usage == 7) {
        return;
    }
}
#endif
