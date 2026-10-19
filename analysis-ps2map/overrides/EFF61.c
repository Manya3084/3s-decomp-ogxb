extern s8 D_007AA5F1;

const s8* Menu_Letter_Data[2][67] = {
    {
        "ARCADE",
        "VERSUS",
        "TRAINING",
        "SYSTEM DIRECTION",
        "REPLAY",
        "OPTION",
        "Xbox Live",
        "SELECT GAME",
        "GAME OPTION",
        "BUTTON CONFIG.",
        "SCREEN ADJUST",
        "SOUND",
        "SAVE#/#LOAD",
        "EXTRA OPTION",
        "EXIT",
        "X POSITION^^^",
        "Y POSITION^^^",
        "X RANGE^^^^^^",
        "Y RANGE^^^^^^",
        "FILTER^^^^^^^",
        "DEFAULT SETTING",
        "EXIT",
        "SAVE  DATA",
        "LOAD  DATA",
        "AUTO  SAVE",
        "EXIT",
        "DIFFICULTY^^^^^^ L         #H",
        "TIME LIMIT^^^^^^",
        "ROUNDS(1P)^^^^^^",
        "ROUNDS(VS)^^^^^^",
        "DAMAGE LEVEL^^^^ L     #H",
        "GUARD JUDGMENT^^",
        "Thumbsticks^^^^^",
        "HANDICAP(VS)^^^^",
        "PLAYER1(VS)^^^^^",
        "PLAYER2(VS)^^^^^",
        "DEFAULT SETTING",
        "EXIT",
        "CONTINUE",
        "REPLAY SAVE",
        "EXIT",
        "CONTINUE",
        "REPLAY SAVE",
        "EXIT",
        "DIRECTION",
        "SAVE",
        "LOAD",
        "EXIT",
        "GAME OPTION",
        "BUTTON CONFIG.",
        "SCREEN ADJUST",
        "SOUND",
        "SAVE#/#LOAD",
        "EXIT",
        "NORMAL TRAINING",
        "PARRYING TRAINING",
        "EXIT",
        "RESTART",
        "SAVE",
        "EXIT",
        "AUDIO",
        "BGM LEVEL",
        "SE LEVEL",
        "BGM SELECT",
        "DEFAULT SETTING",
        "BGM TEST",
        "EXIT"
    },
    {
        "ARCADE",
        "VERSUS",
        "TRAINING",
        "SYSTEM DIRECTION",
        "REPLAY",
        "OPTION",
        "Xbox Live",
        "SELECT GAME",
        "GAME OPTION",
        "BUTTON CONFIG.",
        "SCREEN ADJUST",
        "SOUND",
        "SAVE#/#LOAD",
        "EXTRA OPTION",
        "EXIT",
        "X POSITION^^^",
        "Y POSITION^^^",
        "X RANGE^^^^^^",
        "Y RANGE^^^^^^",
        "FILTER^^^^^^^",
        "DEFAULT SETTING",
        "EXIT",
        "SAVE  DATA",
        "LOAD  DATA",
        "AUTO  SAVE",
        "EXIT",
        "DIFFICULTY^^^^^^ L         #H",
        "TIME LIMIT^^^^^^",
        "ROUNDS(1P)^^^^^^",
        "ROUNDS(VS)^^^^^^",
        "DAMAGE LEVEL^^^^ L     #H",
        "GUARD JUDGMENT^^",
        "Thumbsticks^^^^^",
        "HANDICAP(VS)^^^^",
        "PLAYER1(VS)^^^^^",
        "PLAYER2(VS)^^^^^",
        "DEFAULT SETTING",
        "EXIT",
        "CONTINUE",
        "REPLAY SAVE",
        "EXIT",
        "CONTINUE",
        "REPLAY SAVE",
        "EXIT",
        "DIRECTION",
        "SAVE",
        "LOAD",
        "EXIT",
        "GAME OPTION",
        "BUTTON CONFIG.",
        "SCREEN ADJUST",
        "SOUND",
        "SAVE#/#LOAD",
        "EXIT",
        "NORMAL TRAINING",
        "BLOCKING TRAINING",
        "EXIT",
        "RESTART",
        "SAVE",
        "EXIT",
        "AUDIO",
        "BGM LEVEL",
        "SE LEVEL",
        "BGM SELECT",
        "DEFAULT SETTING",
        "BGM TEST",
        "EXIT"
    }
};

s32 effect_61_init(s16 master, u8 dir_old, s16 sync_bg, s16 master_player, s16 char_ix, s16 cursor_index,
                   u16 letter_type) {
    WORK_Other_CONN* ewk;
    s16 ix;
    u16 x;
    s16 offset_x;
    const u8* ptr;

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }

    ewk = (WORK_Other_CONN*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 61;
    ewk->wu.work_id = 16;
    ewk->master_id = master;
    ewk->wu.my_family = sync_bg + 1;
    ewk->wu.my_col_code = 0x1AC;
    ewk->wu.type = cursor_index;
    ewk->wu.char_index = char_ix;
    ewk->wu.old_cgnum = letter_type;
    ewk->wu.dir_old = dir_old;
    ewk->master_player = master_player;

    if (ewk->wu.old_cgnum == 0x70A7) {
        offset_x = 8;
    } else {
        offset_x = 14;
    }

    ptr = (u8*)Menu_Letter_Data[D_007AA5F1][char_ix];
    ix = 0;
    x = 0;

    while (*ptr != '\0') {
        if (*ptr == ' ') {
            x += offset_x;
            ptr++;
            continue;
        }

        if (*ptr == '#') {
            x += offset_x / 2;
            ptr++;
            continue;
        }

        ewk->conn[ix].nx = x;
        ewk->conn[ix].ny = 0;
        ewk->conn[ix].col = 0;
        ewk->conn[ix].chr = ewk->wu.old_cgnum + *ptr;

        if (offset_x == 14 && *ptr == '/') {
            if (D_007AA5F1) {
                ewk->conn[ix].ny = 1; /* Xbox only */
            } else {
                ewk->conn[ix].nx -= 8;
                ewk->conn[ix].ny += 17;
            }
        }

        x += offset_x;
        ptr++;
        ix++;
    }

    ewk->num_of_conn = ix;
    ewk->wu.my_mts = 13;
    ewk->wu.my_trans_mode = get_my_trans_mode(ewk->wu.my_mts);
    return 0;
}

/* Xbox: the menu letters these ranges pick are one index later than on
   PS2 (38..43 and 57..59; PS2 37..42 and 56..58). */
void effect_61_move(WORK_Other_CONN* ewk) {
    if (Check_Die_61((WORK_Other*)ewk)) {
        push_effect_work(&ewk->wu);
        return;
    }

    EFF61_Jmp_Tbl[ewk->wu.routine_no[0]](ewk);

    if (ewk->wu.be_flag == 0) {
        return;
    }

    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0xFFFF;
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0xFFFF;

    if (ewk->wu.char_index >= 38 && ewk->wu.char_index < 44) {
        if (Menu_Cursor_Y[ewk->master_id] == ewk->wu.type) {
            if (Menu_Cursor_X[ewk->master_id]) {
                ewk->wu.my_clear_level = 0;
            } else {
                ewk->wu.my_clear_level = 51;
            }
        } else {
            ewk->wu.my_clear_level = 179;
        }
    } else if (ewk->wu.char_index >= 57 && ewk->wu.char_index < 60) {
        if (Menu_Cursor_Y[ewk->master_id] == ewk->wu.type) {
            ewk->wu.my_bright_type = 0;
            ewk->wu.my_bright_level = 0;
            ewk->wu.my_clear_level = 0;
        } else {
            ewk->wu.my_bright_type = 1;
            ewk->wu.my_bright_level = 8;
            ewk->wu.my_clear_level = 51;
        }
    } else if (Menu_Cursor_Y[ewk->master_id] == ewk->wu.type) {
        ewk->wu.my_clear_level = 0;
    } else if (ewk->wu.char_index == 1 && Connect_Status == 0) {
        ewk->wu.my_clear_level = 179;
    } else {
        ewk->wu.my_clear_level = 128;
    }

    sort_push_request3(&ewk->wu);
}

/* Xbox: as effect_61_move, 57..59 (PS2 56..58). */
void EFF61_SUDDENLY(WORK_Other_CONN* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (--Order_Timer[ewk->wu.dir_old]) {
            break;
        }

        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.xyz[0].disp.pos =
            bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos + Slide_Pos_Data_61[ewk->wu.char_index][0];
        ewk->wu.xyz[1].disp.pos =
            bg_w.bgw[ewk->wu.my_family - 1].wxy[1].disp.pos + Slide_Pos_Data_61[ewk->wu.char_index][1];
        ewk->wu.position_z = 68;

        if (ewk->wu.char_index >= 57 && ewk->wu.char_index < 60) {
            ewk->wu.position_z = 20;
        }

        break;

    default:
        ewk->wu.routine_no[0] = 0;
        Order[ewk->wu.dir_old] = 0;
        break;
    }
}
