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

/* The Xbox has no Debug_w tests; S_Timer < 71 is <= 70. */
void Next_CPU_3rd() {
    switch (SC_No[1]) {
    case 0:
        if (Player_id) {
            Sel_CPU_Sub(1, ~p2sw_1 & p2sw_0, p2sw_0);
        } else {
            Sel_CPU_Sub(0, ~p1sw_1 & p1sw_0, p1sw_0);
        }

        if (!Sel_EM_Complete[Player_id]) {
            break;
        }

        SC_No[1]++;
        SC_No[2] = 0;

        Push_LDREQ_Queue_Player(COM_id, My_char[COM_id]);
        Setup_Next_Fighter();

        if (VS_Index[Player_id] < 8) {
            S_Timer = 50;
            break;
        }

        SC_No[1] = 2;
        S_Timer = 100;
        break;

    case 1:
        switch (SC_No[2]) {
        case 0:
            if (S_Timer < 10) {
                S_Timer = 9;
                SC_No[2]++;
                SsBgmFadeOut(0x1000);
            }

            break;
        }

        if ((S_Timer -= 1) == 0) {
            SC_No[0]++;
            SC_No[1] = 0;
            SC_No[2] = 0;
        }

        break;

    case 2:
        if ((S_Timer -= 1) <= 70) {
            if (Check_EM_Speech() == 0) {
                SC_No[1]++;
            } else {
                SC_No[0] = 4;
                SC_No[1] = 0;
            }

            SC_No[2] = 0;
            break;
        }

        break;

    case 3:
        switch (SC_No[2]) {
        case 0:
            if (Scene_Cut) {
                S_Timer = 9;
            }

            if (S_Timer < 10) {
                S_Timer = 9;
                SC_No[2]++;
                SsBgmFadeOut(0x1000U);
            }

            break;
        }

        if ((S_Timer -= 1) == 0) {
            SC_No[0]++;
            SC_No[1] = 0;
            SC_No[2] = 0;
        }

        break;
    }
}

/* The Xbox has no Debug_w tests; S_Timer < 51 is <= 50. */
void Select_CPU_3rd() {
    switch (SC_No[1]) {
    case 0:
        if (Demo_Flag == 0) {
            if (Player_id) {
                Sel_CPU_Sub(1, Check_Demo_Data(1), 0);
            } else {
                Sel_CPU_Sub(0, Check_Demo_Data(0), 0);
            }
        } else if (Player_id) {
            Sel_CPU_Sub(1, ~p2sw_1 & p2sw_0, p2sw_0);
        } else {
            Sel_CPU_Sub(0, ~p1sw_1 & p1sw_0, p1sw_0);
        }

        if (!Sel_EM_Complete[Player_id]) {
            break;
        }

        SC_No[1]++;

        Push_LDREQ_Queue_Player(COM_id, My_char[COM_id]);
        Setup_Next_Fighter();

        if (VS_Index[Player_id] < 8) {
            S_Timer = 50;
        } else {
            SC_No[1] = 2;
            S_Timer = 100;
        }

        break;

    case 1:
        if ((S_Timer -= 1) == 0) {
            SC_No[1] = 4;
        }

        break;

    case 2:
        if ((S_Timer -= 1) <= 50) {
            if (Check_LDREQ_Queue_Direct(9)) {
                SC_No[1]++;
            } else {
                S_Timer = 1;
            }
        }

        break;

    case 3:
        if (Scene_Cut) {
            S_Timer = 1;
        }

        if ((S_Timer -= 1) == 0) {
            SC_No[1]++;
        }

        break;

    case 4:
        SC_No[1] = 6;
        Order[Player_id + 11] = 4;
        Order_Timer[Player_id + 11] = 5;
        effect_38_init(COM_id, COM_id + 11, My_char[COM_id], 1, 2);
        Order[COM_id + 11] = 1;
        Order_Timer[COM_id + 11] = 1;

        if (check_use_all_SA() == 0 && check_without_SA() == 0 && EM_id != 0) {
            effect_98_init(COM_id, COM_id + 0x28, Super_Arts[COM_id], 2);
            Order[COM_id + 40] = 1;
            Order_Timer[COM_id + 40] = 1;
        }

        effect_75_init(42, 3, 2);
        Order[42] = 3;
        Order_Timer[42] = 1;
        Order_Dir[42] = 3;
        Target_BG_X[3] = bg_w.bgw[3].wxy[0].disp.pos + 480;
        Offset_BG_X[3] = 0;

        if (8 <= VS_Index[Player_id] && Check_EM_Speech()) {
            SC_No[1] = 5;
            Order[67] = 1;
            Order_Timer[67] = 10;
            Order_Dir[67] = 8;
            effect_76_init(67);
            Order[68] = 1;
            Order_Timer[68] = 10;
            Order_Dir[68] = 4;
            effect_76_init(68);
        }

        Next_Step = 0;
        Cut_Scroll = 2;
        bg_mvxy.a[0].sp = 0x200000;
        bg_mvxy.d[0].sp = 0x18000;
        effect_58_init(12, 1, 3);
        break;

    case 5:
        if (Next_Step & 0x80) {
            SC_No[1] = 7;
            S_Timer = 20;
            Introduce_Boss[Player_id][VS_Index[Player_id] - 8] = 1;
        }

        break;

    case 6:
        if (Next_Step & 1) {
            SC_No[1]++;
            S_Timer = 20;
        }

        break;

    case 7:
        switch (SC_No[2]) {
        case 0:
            if (Scene_Cut) {
                S_Timer = 9;
            }

            if (S_Timer < 10) {
                S_Timer = 9;
                SC_No[2]++;
                SsBgmFadeOut(0x1000);
            }

            break;
        }

        if ((S_Timer -= 1) == 0) {
            SC_No[0]++;
            SC_No[1] = 0;
            SC_No[2] = 0;
        }

        break;
    }
}
