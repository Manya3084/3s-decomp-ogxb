
/* Xbox: after Entry_00, waits until xb_Get7A1808 is set before taking a
   start press. */
s32 xb_Get7A1808(void);

void Entry_01() {
    switch (E_No[2]) {
    case 0:
        E_No[2] += 1;
        E_No[1] = 1;
        Break_Into = 0;
        break;

    case 1:
        Entry_00();

        if (xb_Get7A1808() == 0) {
            return;
        }

        if (~p1sw_1 & p1sw_0 & 0x4000) {
            Entry_01_Sub(0);
            return;
        }

        if (~p2sw_1 & p2sw_0 & 0x4000) {
            Entry_01_Sub(1);
            return;
        }

        break;

    case 2:
        if (Request_E_No) {
            E_No[2] += 1;
            return;
        }

        break;

    default:
        Exit_Title_Sub_Entry();
        break;
    }
}

/* Xbox: case 0 breaks out where the PS2 returns. */
void Entry_03_2nd() {
    switch (E_No[2]) {
    case 0:
        if (--E_Timer == 0) {
            if (Check_LDREQ_Break() == 0) {
                E_No[2] += 1;
                Switch_Screen_Init(1);
                break;
            }

            E_Timer = 1;
            break;
        }

        break;

    case 1:
        if (Switch_Screen(1) != 0) {
            Cover_Timer = 23;
            G_No[1] = 1;
            G_No[2] = 0;
            G_No[3] = 0;
            E_No[0] = 2;
            E_No[1] = 0;
            E_No[2] = 0;
            E_No[3] = 0;
            plw[New_Challenger].wu.operator = 1;
            Operator_Status[New_Challenger] = 1;
            Sel_Arts_Complete[Champion] = -1;

            if (Continue_Coin[New_Challenger] == 0) {
                grade_check_work_1st_init(New_Challenger, 0);
            }
        }

        break;
    }
}

/* The Xbox runs one step: no sysFF fast-forward loop. */
void Entry_Task(struct _TASK* /* unused */) {
    void (*Main_Jmp_Tbl[11])() = { Entry_00, Entry_01, Entry_02, Entry_03, Entry_04, Entry_03,
                                   Entry_06, Entry_07, Entry_08, Entry_03, Entry_10 };

    if (Pause || nowSoftReset()) {
        return;
    }

    No_Trans = 0;
    letter_counter = 0;
    letter_ptr = letter_stack;
    Main_Jmp_Tbl[E_No[0]]();
}

/* Xbox: case 0 breaks out where the PS2 returns. */
void Entry_04_2nd() {
    switch (E_No[2]) {
    case 0:
        if (--E_Timer == 0) {
            if (Check_LDREQ_Break() == 0) {
                E_No[2] += 1;
                Switch_Screen_Init(1);
                break;
            }

            E_Timer = 1;
            break;
        }

        break;

    case 1:
        if (Switch_Screen(0) != 0) {
            E_No[2] += 1;
            Cover_Timer = 23;
            G_No[1] = 1;
            G_No[2] = 0;
            G_No[3] = 0;

            if (E_No[3] == 0xFF) {
                E_Number[LOSER][0] = 1;
                E_Number[LOSER][1] = 0;
                E_Number[LOSER][2] = 0;
                E_Number[LOSER][3] = 0;
            } else {
                Correct_BI_Data();
            }

            E_No[0] = 2;
            E_No[1] = 0;
            E_No[2] = 0;
            E_No[3] = 0;
            Game_pause = 0;
            plw[New_Challenger].wu.operator = 1;
            Operator_Status[New_Challenger] = 1;

            if (Continue_Coin[New_Challenger] == 0) {
                grade_check_work_1st_init(New_Challenger, 0);
            }
        }

        break;
    }
}

/* The Xbox breaks out of the switch where the PS2 returns. */
void Entry_Main_Sub(s16 PL_id, s16 Jump_Index) {
    ENTRY_X = 0;

    switch (E_Number[PL_id][0]) {
    case 0:
        if (!Ignore_Entry[LOSER]) {
            if ((E_No[0] == 10) || (E_No[0] == 8)) {
                E_Number[PL_id][0] = 99;
                return;
            }

            if (plw[PL_id].wu.operator == 0) {
                Entry_Common_Sub(PL_id, Jump_Index);
                break;
            }
        }

        break;

    case 1:
        if (PL_id) {
            if (Credit_Continue_2P() != 0) {
                Break_Into_Sub(PL_id, Jump_Index);
            }
        } else if (Credit_Continue_1P() != 0) {
            Break_Into_Sub(PL_id, Jump_Index);
        }

        if (Request_Break[PL_id]) {
            E_Number[PL_id][0] = 0;
            E_Number[PL_id][1] = 0;
            E_Number[PL_id][2] = 0;
            E_Number[PL_id][3] = 0;
            return;
        }

        if ((E_Number[PL_id][0] == 1) && (E_07_Flag[PL_id ^ 1] == 0)) {
            Entry_Continue_Sub(PL_id);
            return;
        }

        break;

    case 2:
        switch (E_Number[PL_id][1]) {
        case 0:
            E_Number[PL_id][1] += 1;
            Personal_Timer[PL_id] = 30;
            break;

        case 1:
            if (!--Personal_Timer[PL_id]) {
                E_Number[PL_id][1] += 1;
                Naming_Init(PL_id);
                break;
            }

            break;

        case 2:
            if (Forbid_Break != 1) {
                if (PL_id == 0) {
                    Naming_Cut_Sub_1P();
                } else {
                    Naming_Cut_Sub_2P();
                }

                if (Name_Input(PL_id)) {
                    Name_In_Sub(PL_id);

                    if (Naming_Cut[PL_id]) {
                        Clear_Personal_Data(PL_id);
                        return;
                    }

                    E_Number[PL_id][2] = 0;
                    E_Number[PL_id][3] = 0;

                    if (E_No[0] == 8) {
                        E_Number[PL_id][0] = 8;
                        E_Number[PL_id][1] = 1;
                        return;
                    }

                    E_Number[PL_id][0] = 8;
                    E_Number[PL_id][1] = 0;
                    return;
                }
            }

            break;
        }

        break;

    case 3:
        switch (E_Number[PL_id][1]) {
        case 0:
            if ((E_No[0] == 8) || (E_No[0] == 2)) {
                E_Number[PL_id][0] = 2;
                E_Number[PL_id][1] = 2;
                E_Number[PL_id][2] = 0;
                E_Number[PL_id][3] = 0;
                Naming_Init(PL_id);
                return;
            }

            break;

        case 1:
            if ((E_No[0] == 8) || (E_No[0] == 2)) {
                E_Number[PL_id][0] = 8;
                E_Number[PL_id][1] = 1;
                E_Number[PL_id][2] = 0;
                E_Number[PL_id][3] = 0;

                if (E_No[0] == 2) {
                    E_Number[PL_id][1] = 0;
                    return;
                }
            }

            break;
        }

        break;

    case 8:
        switch (E_Number[PL_id][1]) {
        case 0:
            In_Game_Sub(PL_id);
            break;

        case 1:
            In_Over_Sub(PL_id);
            break;
        }

        break;

    case 5:
        Loser_Scene_Sub(PL_id, Jump_Index);
        break;
    }
}
