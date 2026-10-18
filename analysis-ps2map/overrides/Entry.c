
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
