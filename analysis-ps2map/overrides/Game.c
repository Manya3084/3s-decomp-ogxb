extern u8 D_007AA5EB;
/* Xbox-only: returns the dword at 0x79A170. */
s32 xb_GetOnlineFlag(void);
void xb_DrawSaveFrame(void);
void xb_rebattle_Select(s32 arg);

/* Xbox: the save autoload starts here (PS2: in Init_Task_Aload). */
void Game0_0() {
    if (Title_At_a_Dash() != 0) {
        G_No[2] += 1;
        SaveInit(0, 2);
    }
}

/* The save test is inverted, as the retail branch layout has it. */
void Game0_1() {
    Disp_Copyright();
    TITLE_Move(1);

    if (SaveMove() <= 0) {
        Pause = 0;

        if (Request_G_No) {
            G_No[2] += 1;
        }
        return;
    }

    xb_DrawSaveFrame();
    G_Timer = 0;
    Pause = 1;
}

/* Xbox: calls xb_GetOnlineFlag (the dword at 0x79A170) and xb_rebattle_Select. */
void Game2_0() {
    s16 ix;

    BG_Draw_System();
    Switch_Screen(0);

    if (Check_LDREQ_Clear() == 0) {
        return;
    }

    /* Xbox only */
    if (xb_GetOnlineFlag()) {
        xb_rebattle_Select(0);
    }

    System_all_clear_Level_B();

    switch (Mode_Type) {
    case 0:
        Play_Mode = 0;
        Replay_Status[0] = 0;
        Replay_Status[1] = 0;
        break;

    case 1:
        for (ix = 0; ix < 2; ix++) {
            if (save_w[1].Partner_Type[ix]) {
                plw[ix].wu.operator = 0;
                Operator_Status[ix] = 0;
            }
        }

        cpExitTask(1);
        /* fallthrough */

    case 2:
        Play_Mode = 1;
        All_Clear_Random_ix();
        All_Clear_Timer();

        /* Xbox: skipped while the xb_GetOnlineFlag flag is set */
        if (!xb_GetOnlineFlag()) {
            All_Clear_ETC();
        }

        break;

    case 5:
        Play_Mode = 3;
        All_Clear_Timer();
        break;
    }

    Check_Replay();

    if (Demo_Flag == 0) {
        Play_Mode = 0;
        Replay_Status[0] = 0;
        Replay_Status[1] = 0;
    }

    Game_difficulty = 15;
    Game_pause = 0;
    Demo_Time_Stop = 0;
    C_No[0] = 0;
    C_No[1] = 0;
    C_No[2] = 0;
    C_No[3] = 0;
    G_No[2] = 6;
    G_Timer = 10;
    Round_num = 0;
    Keep_Grade[0] = 0;
    Keep_Grade[1] = 0;

    if (Win_Record[0]) {
        Keep_Grade[0] = grade_get_my_grade(0) + 1;
    }

    if (Win_Record[1]) {
        Keep_Grade[1] = grade_get_my_grade(1) + 1;
    }

    Allow_a_battle_f = 0;
    Time_in_Time = 60;
    init_slow_flag();
    clear_hit_queue();
    pcon_rno[0] = pcon_rno[1] = pcon_rno[2] = pcon_rno[3] = 0;
    ca_check_flag = 1;
    bg_work_clear();
    win_lose_work_clear();
    sub_0004384A();
    sub_0004384A(3);
}

void Game02() {
    void (*Game02_Jmp_Tbl[8])() = { Game2_0, Game2_1, Game2_2, Game2_3, Game2_4, Game2_5, Game2_6, Game2_7 };

    xb_GetOnlineFlag(); /* Xbox only; the result is not used */
    Scene_Cut = Cut_Cut_Cut();
    Game02_Jmp_Tbl[G_No[2]]();
    BG_move_Ex(3);
}

/* Xbox: no ppgPurgeFromVRAM calls. */
void Game2_1() {
    mpp_w.inGame = 1;

    if (Game_pause != 0x81) {
        Game_timer += 1;
    }

    set_EXE_flag();
    Player_control();
    TATE00();
    Game_Management();
    BG_Draw_System();
    reqPlayerDraw();
    Basic_Sub_Ex();

    if (Disp_Cockpit) {
        Time_Control();
        vital_cont_main();
        player_face();
        player_name();
        combo_cont_main();
        stngauge_cont_main();
        spgauge_cont_main();
        Sa_frame_Write();
        Score_Sub();
        Flash_Lamp();
        Disp_Win_Record();
    }

    hit_check_main_process();
}

/* Xbox: sets the Xbox byte D_007AA5EB (inside mpp_w, past inGame) during
   the title states 0 and 1. */
void Game00() {
    void (*Game00_Jmp_Tbl[3])() = { Game0_0, Game0_1, Game0_2 };

    Game00_Jmp_Tbl[G_No[2]]();
    njSetBackColor(0, 0, 0);
    BG_Draw_System();
    Basic_Sub();
    Check_Back_Demo();

    if (G_No[2] < 2) {
        D_007AA5EB = 1;
    }
}

/* Xbox: the player whose START or A (0x4100) is new, player 1 first, else
   -1. */
s16 xb_GetJoiningPlayer(void);

/* Xbox: the joining player comes from xb_GetJoiningPlayer (START or A; PS2 START
   only). */
s16 Ck_Coin() {
    s16 PL_id;

    switch (G_No[3]) {
    case 0:
        PL_id = xb_GetJoiningPlayer();

        if (PL_id == -1) {
            return 0;
        }

        ToneDown(0xFF, 0);
        Request_LDREQ_Break();
        G_No[3] = 1;
        plw[PL_id].wu.operator = 1;
        Operator_Status[PL_id] = 1;
        Champion = PL_id;
        plw[PL_id ^ 1].wu.operator = 0;
        Operator_Status[PL_id ^ 1] = 0;
        return 0;

    default:
    case 1:
        ToneDown(0xFF, 0);
        PL_id = Check_LDREQ_Break();
        return PL_id ^ 1;
    }
}

/* Xbox: calls xb_GetOnlineFlag first, as Game02 does. */
void Game12() {
    void (*Game12_Jmp_Tbl[3])() = { Game12_0, Game12_1, Game12_2 };

    xb_GetOnlineFlag(); /* Xbox only; the result is not used */
    Game12_Jmp_Tbl[G_No[2]]();
    BG_Draw_System();
    Basic_Sub();
    bg_pos_hosei_sub2(0);
    bg_pos_hosei_sub2(1);
    bg_pos_hosei_sub2(2);
    Bg_Family_Set_appoint(0);
    Bg_Family_Set_appoint(1);
    Bg_Family_Set_appoint(2);
    BG_move_Ex(0);
}

/* Xbox-only routine Game12_2 calls on leaving. */
void xb_LiveWork_Set2330(s32 arg);

/* Xbox: calls xb_LiveWork_Set2330(0) after cpExitTask(3). */
void Game12_2() {
    if (Switch_Screen(1) != 0) {
        G_No[1] = 1;
        G_No[2] = 0;
        G_No[3] = 0;
        Control_Time = 481;
        Cover_Timer = 23;
        effect_work_init();
        cpExitTask(3);
        xb_LiveWork_Set2330(0);
    }
}

/* Xbox-only routine that starts the G_No 13 state. */
void xb_ClearRebattleWork(void);

/* Xbox: a versus win (Mode_Type 2), and case 2 while xb_GetOnlineFlag is set,
   go to G_No 13 through xb_ClearRebattleWork and return without BG_move; the PS2
   replay-info and champion setup for versus is gone. */
void Game03() {
    BG_Draw_System();
    move_effect_work(4);
    move_effect_work(5);
    Play_Mode = 0;
    Replay_Status[0] = 0;
    Replay_Status[1] = 0;

    switch (G_No[2]) {
    case 0:
        if (Winner_Scene() != 0) {
            switch (Mode_Type) {
            case 1:
                G_No[2] += 1;
                Rep_Game_Infor[10].play_type = 1;
                Rep_Game_Infor[10].winner = Winner_id;
                Switch_Screen_Init(0);

                if (Country == 3) {
                    if (Screen_PAL == 8) {
                        Rep_Game_Infor[10].play_type = 3;
                    } else {
                        Rep_Game_Infor[10].play_type = 4;
                    }
                }

                break;

            case 2:
                xb_ClearRebattleWork();
                G_No[1] = 13;
                G_No[2] = 0;

                if (xb_GetOnlineFlag()) {
                    xb_rebattle_Select(1);
                }

                return;

            case 5:
                G_No[2] = 5;
                cpReadyTask(MENU_TASK_NUM, Menu_Task);
                task[3].r_no[0] = 8;
                break;

            default:
                G_No[1] = 5;
                G_No[2] = 0;
                G_No[3] = 0;
                E_No[0] = 9;
                E_No[1] = 0;
                E_No[2] = 0;
                E_No[3] = 0;

                if (Battle_Q[WINNER]) {
                    G_No[1] = 0xB;
                    G_No[2] = 3;
                    G_No[3] = 0;
                }

                Cover_Timer = 24;

                if (Round_Operator[LOSER]) {
                    E_Number[LOSER][0] = 1;
                    E_Number[LOSER][1] = 0;
                    E_Number[LOSER][2] = 0;
                    E_Number[LOSER][3] = 0;
                }

                break;
            }
        }

        break;

    case 1:
        if (Switch_Screen(1) != 0) {
            G_No[2] += 1;
            E_No[0] = 1;
            E_No[1] = 2;
            E_No[2] = 2;
            E_No[3] = 0;
            Request_E_No = 0;
            cpReadyTask(MENU_TASK_NUM, Menu_Task);
            task[3].r_no[1] = 16;
            Cursor_Y_Pos[0][0] = 0;
            Cursor_Y_Pos[1][0] = 0;
            G_Timer = 4;
        }

        break;

    case 2:
        Switch_Screen(1);

        if (--G_Timer == 0) {
            Cover_Timer = 10;
            G_No[1] = 12;
            G_No[2] = 0;
            G_No[3] = 0;
        }

        if (xb_GetOnlineFlag()) {
            xb_ClearRebattleWork();
            G_No[1] = 13;
            G_No[2] = 0;
            return;
        }

        if (xb_GetOnlineFlag()) {
            xb_rebattle_Select(1);
        }

        break;

    case 3:
        if (Switch_Screen(1) != 0) {
            G_No[2] += 1;
            task[7].r_no[0] = 1;
            G_Timer = 4;
        }

        break;

    case 4:
        Switch_Screen(1);

        if (--G_Timer == 0) {
            // Do nothing
        }

        break;

    case 5:
        // Do nothing
        break;
    }

    BG_move();
}

/* Xbox-only routines Game01 calls. */
s32 xb_NetSync_IsDone(void);
void xb_NetSync_Step(void);
s32 xb_NetSync_CheckPlayers(void);
void xb_NetSync_SetDone(s32 arg);
void xb_LiveWork_Menu24C0(s32 arg);
void xb_ReleaseScreenTextures(void);
void xb_LiveWork_Set2334(s32 arg);

/* The Xbox has no Debug_w test. */
void Game01() {
    if (xb_NetSync_IsDone() == 0) {
        xb_NetSync_Step();

        if (xb_NetSync_CheckPlayers() == 0) {
            return;
        }

        xb_NetSync_SetDone(1);
    }

    xb_GetOnlineFlag(); /* Xbox only; the result is not used */
    BG_Draw_System();
    Basic_Sub();
    Setup_Play_Type();

    switch (G_No[2]) {
    case 0:
        if (xb_GetOnlineFlag()) {
            xb_rebattle_Select(0);
            xb_LiveWork_Menu24C0(1);
        }

        Switch_Screen(1);
        G_No[2] += 1;
        S_No[0] = 0;
        S_No[1] = 0;
        S_No[2] = 0;
        S_No[3] = 0;
        xb_ReleaseScreenTextures();

        if (xb_GetOnlineFlag()) {
            xb_LiveWork_Set2334(1);
        }

        SsBgmHalfVolume(0);

        if (Mode_Type == 0) {
            sub_00098407(53);
        } else {
            sub_00098407(66);
        }

        Break_Into = 0;
        Stop_Combo = 0;

        if (Mode_Type != 2) {
            Random_ix32 = Interrupt_Timer;
            Random_ix32_ex = Interrupt_Timer;
        } else {
            sub_0009A8D0();
            All_Clear_Timer();
        }

        init_slow_flag();
        System_all_clear_Level_B();
        pulpul_stop();
        init_pulpul_work();
        break;

    case 1:
        Switch_Screen(1);
        G_No[2] += 1;
        break;

    case 2:
        if (Select_Player()) {
            G_No[2] += 1;
            Bonus_Game_Flag = 0;
            Switch_Screen_Init(0);
        }

        break;

    default:
        Select_Player();

        if (Switch_Screen(0) != 0) {
            Game01_Sub();
            Cover_Timer = 5;
            appear_type = 1;
            set_hitmark_color();

            Purge_texcash_of_list(3);
            Make_texcash_of_list(3);

            if (Demo_Flag) {
                G_No[1] = 2;
                G_No[2] = 0;
                G_No[3] = 0;
                E_No[0] = 4;
                E_No[1] = 0;
                E_No[2] = 0;
                E_No[3] = 0;
            } else {
                Demo_Time_Stop = 1;
                plw[0].wu.operator = 0;
                Operator_Status[0] = 0;
                plw[1].wu.operator = 0;
                Operator_Status[1] = 0;
            }

            if (plw[0].wu.operator != 0) {
                Sel_Arts_Complete[0] = -1;
            }

            if (plw[1].wu.operator != 0) {
                Sel_Arts_Complete[1] = -1;
            }

            if ((plw[0].wu.operator != 0) && (plw[1].wu.operator != 0)) {
                Play_Type = 1;
            } else {
                Play_Type = 0;
            }
        }

        break;
    }

    BG_move();
}
