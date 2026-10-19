/* Notes from the hand port this file replaced:
 * eff35_0000 is 0xB7197 size 0x59 and is interior.
 * eff35_0001 is 0xB71F0 size 0xFD and is interior.
 * eff35_0002 is 0xB72ED size 0x9C and is interior.
 * eff35_0003 is 0xB7389 size 0x157 and is interior.
 * eff35_0004 is 0xB74E0 size 0xEE and is interior.
 * eff35_0005 is 0xB75CE size 0xC2 and is interior.
 * eff35_0006 is 0xB7690 size 0xC9 and is interior.
 * effect_35_init is 0xB7759 size 0x13B and is interior.
 * effect_35_move is 0xB7894 size 0x46 and is a scanned start.
 * The init's -1 path is an early ret. 0xB78DA is eff36_move00.
 *
 * eff35_data_tbl is 0x2842C8 and matches the 12 rows.
 * eff35_03_b is 0x284370 and eff35_03_s is 0x284378.
 * Both match. The rows were not pasted.
 * Break_Into is 0x7A8802. Next_Step is 0x7A86D2.
 * pcon_rno[0] is 0xC7E020 and pcon_rno[2] is 0xC7E024.
 * Bonus_Game_result is 0x7A881A. Bonus_Game_ex_result is
 * 0x7A842A. Country is 0x7A8748. EXE_flag is 0xC7C834.
 * Game_pause is 0x7A89B0. bg_w is 0x7BC520.
 * The character table immediate is 0x3027D0. Those bytes
 * were not compared. The init stores my_family after the
 * table reads. The C keeps the PlayStation 2 order.
 * disp_pos_trans_entry and disp_pos_trans_entry5 share
 * 0xEF0C0. add_x_sub is folded into 0xEF072. char_move stays
 * char_move. set_char_move_init is 0x200A9.
 * set_char_move_init2 is 0x201B9. effect_58_init
 * stays effect_58_init. all_cgps_put_back stays sub_0004384A.
 * push_effect_work is 0x4AC6C. pull_effect_work
 * stays pull_effect_work. frw is 0xC806A0 and each object is
 * 0x700 bytes.
 */

typedef uintptr_t EffectRow[448]; /* 0x700 bytes on the 32-bit retail build */

extern s8 Break_Into;
extern s8 Next_Step;
extern s16 EXE_flag;
extern u8 Game_pause;
extern s16 pcon_rno[4];
extern s16 Bonus_Game_result;
extern s16 Bonus_Game_ex_result;
extern u8 Country;
extern BG bg_w;
extern EffectRow frw[];
void set_char_move_init2(WORK *wk, s16 koc, s16 index, s16 ip, s16 scf);
void set_char_move_init(WORK *wk, s16 koc, s16 index);
void char_move(WORK *wk);
void sub_000EF0C0(WORK_Other *ewk);
void sub_000EF072(WORK_Other *ewk);
s32 effect_58_init(s16 id, s16 time0, s16 option);
void sub_0004384A(WORK *wk);
void push_effect_work(WORK *wk);
s16 pull_effect_work(s16 index);
s16 get_my_trans_mode(s16 curr);

/* A retail address the code used as a number. */
extern u32 _bns_char_table[];

void effect_35_move(WORK_Other *ewk) {
    void (*eff35_jp[7])(WORK_Other *) = { eff35_0000, eff35_0001, eff35_0002, eff35_0003,
                                          eff35_0004, eff35_0005, eff35_0006 };

    eff35_jp[ewk->wu.routine_no[0]](ewk);
}

void eff35_0000(WORK_Other *ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.old_rno[1]--;

        if (ewk->wu.old_rno[1] <= 0) {
            ewk->wu.routine_no[1]++;
            ewk->wu.disp_flag = 1;
            set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.old_rno[3], 0);
        }

        break;

    case 1:
        sub_000EF0C0(ewk);
        break;

    default:
        sub_0004384A(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}

void eff35_0001(WORK_Other *ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (Break_Into != 0) {
            ewk->wu.routine_no[1] = 4;
            break;
        }

        ewk->wu.old_rno[1]--;

        if (ewk->wu.old_rno[1] <= 0) {
            ewk->wu.routine_no[1]++;
            ewk->wu.disp_flag = 1;
            ewk->wu.my_mr_flag = 1;
            ewk->wu.my_mr.size.x = 127;
            ewk->wu.my_mr.size.y = 63;
            set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.old_rno[3], 0);
        }

        break;

    case 1:
        if (Break_Into != 0) {
            ewk->wu.routine_no[1] = 4;
            break;
        }

        ewk->wu.my_mr.size.x -= 12;

        if (ewk->wu.my_mr.size.x <= 0) {
            ewk->wu.routine_no[1]++;
            ewk->wu.my_mr.size.x = 0;
        }

        sub_000EF0C0(ewk);
        break;

    case 2:
        if (Break_Into != 0) {
            ewk->wu.routine_no[1] = 4;
            break;
        }

        ewk->wu.my_mr.size.x += 12;

        if (ewk->wu.my_mr.size.x >= 63) {
            ewk->wu.routine_no[1]++;
            ewk->wu.my_mr.size.x = 63;
        }

        sub_000EF0C0(ewk);
        break;

    case 3:
        if (Break_Into != 0) {
            ewk->wu.routine_no[1] = 4;
            break;
        }

        ewk->wu.old_rno[4]--;

        if (ewk->wu.old_rno[4] <= 0) {
            ewk->wu.routine_no[1]++;
            ewk->wu.disp_flag = 0;
            Next_Step = 1;
        }

        sub_000EF0C0(ewk);
        break;

    case 4:
        ewk->wu.routine_no[1]++;
        break;

    default:
        sub_0004384A(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}

void eff35_0002(WORK_Other *ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (Break_Into != 0) {
            ewk->wu.routine_no[1] = 4;
            break;
        }

        ewk->wu.old_rno[1]--;

        if (ewk->wu.old_rno[1] <= 0) {
            ewk->wu.routine_no[1]++;
            ewk->wu.disp_flag = 1;
            set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.old_rno[3], 0);
            effect_58_init(6, 4, 0xA8);
        }

        break;

    case 1:
        if (Break_Into != 0) {
            ewk->wu.routine_no[1] = 4;
            break;
        }

        ewk->wu.old_rno[4]--;

        if (ewk->wu.old_rno[4] <= 0) {
            ewk->wu.routine_no[1]++;
            ewk->wu.disp_flag = 0;
        }

        sub_000EF0C0(ewk);
        break;

    case 2:
        ewk->wu.routine_no[1]++;
        break;

    default:
        sub_0004384A(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}

void eff35_0003(WORK_Other *ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;
        ewk->wu.old_rno[4] = 0;
        /* fallthrough */

    case 1:
        if (Break_Into != 0) {
            ewk->wu.routine_no[1] = 99;
            break;
        }

        ewk->wu.old_rno[1]--;

        if (ewk->wu.old_rno[1] > 0) {
            break;
        }

        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.old_rno[3], 0);

        if (ewk->wu.type == 2) {
            ewk->wu.xyz[0].disp.pos = eff35_data_tbl[2][0];
            ewk->wu.xyz[0].disp.low = 0;
            ewk->wu.xyz[1].disp.pos = eff35_data_tbl[2][1];
            ewk->wu.xyz[1].disp.low = 0;
            ewk->wu.mvxy.a[0].sp = -0x78000;
            ewk->wu.mvxy.d[0].sp = 0;
        } else {
            ewk->wu.xyz[0].disp.pos = eff35_data_tbl[3][0];
            ewk->wu.xyz[0].disp.low = 0;
            ewk->wu.xyz[1].disp.pos = eff35_data_tbl[3][1];
            ewk->wu.xyz[1].disp.low = 0;
            ewk->wu.mvxy.a[0].sp = 0x5C000;
            ewk->wu.mvxy.d[0].sp = 0;
        }

        break;

    case 2:
        if (Break_Into != 0) {
            ewk->wu.routine_no[1] = 99;
            break;
        }

        if (EXE_flag == 0 && Game_pause == 0) {
            sub_000EF072(ewk);
        }

        if (ewk->wu.type == 2) {
            if (ewk->wu.xyz[0].disp.pos < 416) {
                ewk->wu.routine_no[1] = 1;
                ewk->wu.disp_flag = 0;
                ewk->wu.old_rno[4]++;
                ewk->wu.old_rno[4] &= 3;
                ewk->wu.old_rno[1] = eff35_03_b[ewk->wu.old_rno[4]];
            }
        } else if (ewk->wu.xyz[0].disp.pos > 768) {
            ewk->wu.routine_no[1] = 1;
            ewk->wu.disp_flag = 0;
            ewk->wu.old_rno[4]++;
            ewk->wu.old_rno[4] &= 3;
            ewk->wu.old_rno[1] = eff35_03_s[ewk->wu.old_rno[4]];
        }

        sub_000EF0C0(ewk);
        break;

    case 99:
        ewk->wu.routine_no[1]++;
        break;

    default:
        sub_0004384A(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}

void eff35_0004(WORK_Other *ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.old_rno[1]--;

        if (ewk->wu.old_rno[1] <= 0) {
            ewk->wu.routine_no[1]++;
            ewk->wu.disp_flag = 1;
            set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.old_rno[3], 0);
        }

        break;

    case 1:
        if (pcon_rno[0] == 2 && pcon_rno[2] >= 3) {
            if (Bonus_Game_result >= 10 || Bonus_Game_ex_result >= 10) {
                ewk->wu.routine_no[1]++;
            } else {
                ewk->wu.routine_no[1] = 3;
            }
        } else if (EXE_flag == 0 && Game_pause == 0) {
            char_move(&ewk->wu);
        }

        sub_000EF0C0(ewk);
        break;

    case 2:
        if (EXE_flag == 0 && Game_pause == 0) {
            char_move(&ewk->wu);
        }

        if (ewk->wu.cg_type == 9) {
            ewk->wu.routine_no[1]++;
            set_char_move_init(&ewk->wu, 0, 8);
        }

        sub_000EF0C0(ewk);
        break;

    case 3:
        if (EXE_flag == 0 && Game_pause == 0) {
            char_move(&ewk->wu);
        }

        sub_000EF0C0(ewk);
        break;

    default:
        sub_0004384A(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}

void eff35_0005(WORK_Other *ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (Break_Into != 0) {
            ewk->wu.routine_no[1] = 4;
            break;
        }

        ewk->wu.old_rno[1]--;

        if (ewk->wu.old_rno[1] <= 0) {
            ewk->wu.routine_no[1]++;
            ewk->wu.disp_flag = 1;
            ewk->wu.my_col_code = 0x49;
            set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.old_rno[3], 0);
        }

        break;

    case 1:
        if (Break_Into != 0) {
            ewk->wu.routine_no[1] = 4;
            break;
        }

        ewk->wu.old_rno[4]--;

        if (ewk->wu.old_rno[4] <= 0) {
            ewk->wu.routine_no[1]++;
            ewk->wu.disp_flag = 0;
        }

        ewk->wu.xyz[0].disp.pos = bg_w.bgw[1].wxy[0].disp.pos + eff35_data_tbl[ewk->wu.type][0];
        ewk->wu.xyz[1].disp.pos = bg_w.bgw[1].xy[1].disp.pos + eff35_data_tbl[ewk->wu.type][1];
        sub_000EF0C0(ewk);
        break;

    case 2:
        ewk->wu.routine_no[1]++;
        break;

    default:
        sub_0004384A(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}

void eff35_0006(WORK_Other *ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (Break_Into != 0) {
            ewk->wu.routine_no[1] = 4;
            break;
        }

        ewk->wu.old_rno[1]--;

        if (ewk->wu.old_rno[1] <= 0) {
            ewk->wu.routine_no[1]++;
            ewk->wu.disp_flag = 1;
            ewk->wu.my_col_code = 0x49;
            set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.old_rno[3], 0);
        }

        break;

    case 1:
        if (Break_Into != 0) {
            ewk->wu.routine_no[1] = 4;
            break;
        }

        ewk->wu.old_rno[4]--;

        if (ewk->wu.old_rno[4] <= 0) {
            ewk->wu.routine_no[1]++;
            ewk->wu.disp_flag = 0;
            Next_Step = 1;
        }

        ewk->wu.xyz[0].disp.pos = bg_w.bgw[1].wxy[0].disp.pos + eff35_data_tbl[ewk->wu.type][0];
        ewk->wu.xyz[1].disp.pos = bg_w.bgw[1].xy[1].disp.pos + eff35_data_tbl[ewk->wu.type][1];
        sub_000EF0C0(ewk);
        break;

    case 2:
        ewk->wu.routine_no[1]++;
        break;

    default:
        sub_0004384A(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}

s32 effect_35_init(s16 wait_timer, s16 c_type) {
    WORK_Other *ewk;
    s16 ix;
    const s16 *data_ptr;
    u8 char_num;

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }

    ewk = (WORK_Other *)frw[ix];
    ewk->wu.id = 35;

    switch (c_type) {
    case 5:
        if (Country == 1 || Country == 8) {
            char_num = 5;
        } else {
            char_num = 9;
        }

        break;

    case 7:
        if (Country == 1 || Country == 8) {
            char_num = 7;
        } else {
            char_num = 8;
        }

        break;

    case 10:
        switch (Bonus_Game_result) {
        case 2:
            char_num = 11;
            break;

        case 3:
            char_num = 10;
            break;

        default:
            char_num = 10;
            ewk->wu.routine_no[1] = 99;
            Next_Step = 1;
            break;
        }

        break;

    default:
        char_num = c_type;
        break;
    }

    data_ptr = eff35_data_tbl[char_num];
    ewk->wu.be_flag = 1;
    ewk->wu.old_rno[1] = wait_timer;
    ewk->wu.type = char_num;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.char_table[0] = _bns_char_table;
    ewk->wu.my_col_code = 0x12C;
    ewk->wu.my_mts = 7;
    ewk->wu.my_trans_mode = get_my_trans_mode(ewk->wu.my_mts);
    ewk->wu.my_family = 2;
    ewk->wu.xyz[0].disp.pos = *data_ptr++;
    ewk->wu.xyz[1].disp.pos = *data_ptr++;
    ewk->wu.my_priority = ewk->wu.position_z = *data_ptr++;
    ewk->wu.char_index = *data_ptr++;
    ewk->wu.old_rno[3] = *data_ptr++;
    ewk->wu.routine_no[0] = *data_ptr++;
    ewk->wu.old_rno[4] = *data_ptr++;
    return 0;
}
