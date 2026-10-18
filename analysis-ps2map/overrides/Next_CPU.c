/* Rewritten to match retail (tools/permute.py): Push_LDREQ_Queue_BG parameter 1: s16 -> s32. */
s8 Check_Bonus_Stage() {
    Setup_ID();
    Bonus_Type = Check_Bonus_Type();

    if (Bonus_Type == 0) {
        return 0;
    }

    bg_w.stage = Bonus_Type;
    bg_w.area = 0;

    if (Bonus_Type == 21) {
        My_char[COM_id] = 0xC;
    } else {
        My_char[COM_id] = My_char[Player_id];
    }

    Setup_Com_Color();
    Setup_PL_Color(COM_id, Com_Color_Shot);
    Push_LDREQ_Queue_Player(COM_id, My_char[COM_id]);
    Push_LDREQ_Queue_BG(Bonus_Type + 0);
    return Completion_Bonus[Player_id][Bonus_Type - 20] = 1;
}

/* The Xbox has no Debug_w test. */
void Setup_Next_Fighter() {
    paring_counter[COM_id] = 0;
    paring_bonus_r[COM_id] = 0;
    My_char[COM_id] = EM_id;

    if (EM_id == 17) {
        Battle_Country = Q_Country;
        bg_w.stage = Q_Country;
    } else {
        Battle_Country = EM_id;

        if (My_char[Player_id] == 0 && EM_id == 1) {
            Battle_Country = 0;
        }

        bg_w.stage = Battle_Country;
    }

    Push_LDREQ_Queue_BG(bg_w.stage + 0);
    bg_w.area = 0;
    Super_Arts[COM_id] = Stock_Com_Arts[Player_id] = Setup_Com_Arts();

    Setup_Com_Color();
    Setup_PL_Color(COM_id, Com_Color_Shot);
}

/* The Xbox has no Debug_w test. */
s16 Next_Q() {
    void (*Next_Q_Tbl[6])() = {
        Next_Q_1st, Next_Q_2nd, Next_Q_3rd, Wait_Load_Complete, Wait_Load_Complete, Next_CPU_6th
    };

    if (Break_Into) {
        return 0;
    }

    SEL_CPU_X = 0;
    Scene_Cut = Cut_Cut_Cut();
    Next_Q_Tbl[SC_No[0]]();

    Time_Over = 0;
    return SEL_CPU_X;
}

/* The Xbox has no Debug_w test. */
s16 Next_CPU() {
    void (*Next_CPU_Tbl[12])() = { Next_CPU_1st,   Next_CPU_2nd,   Next_CPU_3rd,       Next_CPU_4th,
                                   Next_CPU_5th,   Next_CPU_6th,   Next_Bonus_1st,     Next_Bonus_2nd,
                                   Next_Bonus_3rd, Next_Bonus_End, Wait_Load_Complete, Wait_Load_Complete2 };

    if (Break_Into) {
        return 0;
    }

    SEL_CPU_X = 0;
    Scene_Cut = Cut_Cut_Cut();
    Next_CPU_Tbl[SC_No[0]]();
    Time_Over = 0;

    return SEL_CPU_X;
}

/* The Xbox has no Debug_w[0x2E] test and returns an s32. */
s32 Check_Bonus_Type() {
    if (save_w[Present_Mode].extra_option.contents[0][5] == 0) {
        return 0;
    }

    if (VS_Index[Player_id] >= 6) {
        if (Completion_Bonus[Player_id][1] & 0x80) {
            return 0;
        }

        return 21;
    }

    if (VS_Index[Player_id] >= 3) {
        if (Completion_Bonus[Player_id][0] & 0x80) {
            return 0;
        }

        return 20;
    }

    return 0;
}
