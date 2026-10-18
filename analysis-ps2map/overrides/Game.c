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
                    Rep_Game_Infor[10].play_type = (Screen_PAL == 8) ? 3 : 4;
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

void xb_Game13();

/* Xbox: a fourteenth state, xb_Game13 (Xbox-only). */
void Game() {
    void (*Game_Jmp_Tbl[14])() = { Game00, Game01, Game02, Game03, Game04, Game05, Game06,
                                   Game07, Game08, Game09, Game10, Game11, Game12, xb_Game13 };

    if (G_No[1] == 2 || G_No[1] == 9) {
        Play_Game = 1;
    } else if (G_No[1] == 8) {
        Play_Game = 2;
    }

    Game_Jmp_Tbl[G_No[1]]();
}

/* Rewritten to match retail (tools/permute.py): grade_check_work_1st_init parameter 1: s16 -> s32. */
void Game06() {
    s16 xx;

    BG_Draw_System();
    Basic_Sub_Ex();

    if (!Break_Into) {
        switch (G_No[2]) {
        case 0:
            G_No[2] += 1;
            Game_pause = 0;
            Stock_Com_Color[Player_id] = -1;
            Stock_Com_Arts[Player_id] = -1;
            Last_Player_id = -1;
            Control_Time = 481;
            E_No[0] = 8;
            E_No[1] = 0;
            E_No[2] = 0;
            E_No[3] = 0;

            for (xx = 0; xx < 4; xx++) {
                GO_No[xx] = 0;
            }

            make_texcash_work(13);
            break;

        case 1:
            if (Game_Over()) {
                G_Timer = 60;

                if (Check_Disp_Ranking() != 0) {
                    G_No[2] += 1;
                } else {
                    G_No[2] = 3;
                }
            }

            break;

        case 2:
            if (Disp_Ranking() != 0) {
                G_No[2] += 1;
                G_Timer = 1;
            }

            break;

        case 3:
            if (--G_Timer == 0) {
                G_No[2] += 1;
                Clear_Disp_Ranking(0);
                Clear_Disp_Ranking(1);
                Switch_Screen_Init(1);
            }

            break;

        case 4:
            if (Switch_Screen(1) != 0) {
                Cover_Timer = 24;
                Forbid_Break = 0;
                Clear_Flash_No();
                Clear_Personal_Data(LOSER);
                grade_check_work_1st_init(LOSER, 0);
                grade_check_work_1st_init(LOSER, 1);

                if (Request_Break[0] != 0 || Request_Break[1] != 0) {
                    Request_Break_Sub(0);
                    Request_Break_Sub(1);
                    G_No[1] = 1;
                    G_No[2] = 0;
                    G_No[3] = 0;
                    E_No[0] = 2;
                    E_No[1] = 0;
                    E_No[2] = 0;
                    E_No[3] = 0;
                    break;
                }

                for (xx = 0; xx < 20; xx++) {
                    save_w[Present_Mode].Ranking[xx] = Ranking_Data[xx];
                }

                if (save_w[Present_Mode].Auto_Save) {
                    G_No[2] = 5;
                    G_No[3] = 0;
                    G_Timer = 4;
                    Pause_ID = Player_id;
                    cpReadyTask(MENU_TASK_NUM, Menu_Task);
                    System_all_clear_Level_B();
                    Menu_Init(&task[3]);
                    task[3].r_no[0] = 9;
                    task[3].r_no[1] = 0;
                    Forbid_Reset = 1;
                    make_texcash_work(12);
                    Unsubstantial_BG[0] = 1;
                    Copy_Check_w();
                    cpExitTask(SAVER_TASK_NUM);
                } else {
                    G_No[2] = 6;
                }
            }

            break;

        case 5:
            if (G_No[3] == 0) {
                FadeOut(1, 0xFF, 1);

                if (--G_Timer == 0) {
                    G_No[3] = 1;
                }
            }

            break;

        case 6:
            Switch_Screen(1);
            G_No[0] = 1;
            G_No[1] = 0x63;
            G_No[2] = 0;
            G_No[3] = 0;
            E_No[0] = 0;
            E_No[1] = 0x63;
            E_No[2] = 0;
            E_No[3] = 0;
            D_No[0] = 0;
            D_No[1] = 0;
            D_No[2] = 0;
            D_No[3] = 0;
            Get_Demo_Index = 0;
            Combo_Demo_Flag = 0;
            cpReadyTask(ENTRY_TASK_NUM, Entry_Task);
            Purge_mmtm_area(5);
            Make_texcash_of_list(5);
            System_all_clear_Level_B();
            break;
        }

        BG_move();
    }
}

/* Xbox: clears the player-select state and puts the cursors at the
 * present mode's first positions. */
extern s16 Arts_Y[2];
extern s8 Last_Super_Arts[2];
extern s16 Sel_PL_Complete[2];
extern s8 Cursor_Move[2];
extern s16 Flash_Complete[2];
extern u8 SO_No[2];
extern u8 Face_No[2];
extern s8 Cursor_X[2];
extern s8 Cursor_Y[2];
extern s8 Appear_Cursor;
extern s8 Face_MV_Request;
extern s16 Face_Status;
extern s8 Face_Move;
extern s8 Select_Status[2];
extern s8 New_Challenger;
extern s8 Time_Stop;
extern u8 SP_No[2][4];
extern Permission permission_player[6];
void Setup_Face_ID(void);

void xb_InitSelectWork(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        SP_No[0][i] = 0;
        SP_No[1][i] = 0;
    }

    memset(Arts_Y, 0, sizeof(Arts_Y));
    memset(Super_Arts, 0, sizeof(Super_Arts));
    memset(Last_Super_Arts, 0, sizeof(Last_Super_Arts));
    memset(Sel_Arts_Complete, 0, sizeof(Sel_Arts_Complete));
    memset(Sel_PL_Complete, 0, sizeof(Sel_PL_Complete));
    memset(Cursor_Move, 0, sizeof(Cursor_Move));
    memset(Flash_Complete, 0, sizeof(Flash_Complete));
    memset(SO_No, 0, sizeof(SO_No));
    memset(Face_No, 0, sizeof(Face_No));
    Setup_Face_ID();
    Cursor_X[0] = permission_player[Present_Mode].cursor_infor[0].first_x;
    Cursor_Y[0] = permission_player[Present_Mode].cursor_infor[0].first_y;
    Appear_Cursor = 0;
    Face_MV_Request = 0;
    Face_Status = 0;
    Face_Move = 0;
    Select_Status[1] = 0;
    Select_Status[0] = 0;
    New_Challenger = 0;
    My_char[1] = 0;
    My_char[0] = 0;
    Time_Stop = 1;
    Cursor_X[1] = permission_player[Present_Mode].cursor_infor[1].first_x;
    Cursor_Y[1] = permission_player[Present_Mode].cursor_infor[1].first_y;
}

/* Xbox-only draw pass. The Xbox redraws the whole screen each frame, so
 * after Game_Task's logic runs, xb_GameDraw draws the BG, the effect
 * lists, the cockpit, and the current wipe or fade for the game phase. */
extern u8 M_No[4];
extern u8 Exit_No;
extern s16 Exit_Timer;
extern u8 counter_color;
void counter_write(u8 atr);
void vital_parts_allwrite(u8 Pl_Num);
void xb_draw_effect_work(s16 index);
void xb_cmb_win_draw(s8 pl);
void xb_sast_draw(void);
s32 xb_WipeInRedraw(u8 type);
s32 xb_WipeOutRedraw(u8 type);
s32 xb_FadeInRedraw(u8 type, u8 step, u8 priority);
s32 xb_FadeOutRedraw(u8 type, u8 step, u8 priority);
s32 xb_LiveWork_Get2330(void);
void xb_SelectRenderTarget(s32 n);
void xb_PresentScreenTexture(void);
void _assert(const char* expr, const char* file, unsigned line);

void xb_RedrawTransition(s32 type, u8 wipe_type) {
    switch (type) {
    case 0:
        xb_WipeInRedraw(wipe_type);
        break;

    case 1:
        xb_WipeOutRedraw(wipe_type);
        break;

    case 2:
        xb_FadeInRedraw(0, 4, 1);
        break;

    case 3:
        xb_FadeOutRedraw(0, 0xFF, 1);
        break;
    }
}

void xb_GameDraw1(void) {
    BG_Draw_System();
    bg_w.bgw[0].old_pos_x = bg_w.bgw[0].xy[0].disp.pos;
    xb_draw_effect_work(0);
    xb_draw_effect_work(1);
    xb_draw_effect_work(2);
    xb_draw_effect_work(3);
    xb_draw_effect_work(4);
    xb_draw_effect_work(5);

    switch (G_No[2]) {
    case 0:
    case 1:
        xb_RedrawTransition(1, 1);
        break;

    case 2:
        switch (S_No[0]) {
        case 0:
        case 1:
            xb_RedrawTransition(1, 1);
            break;

        case 2:
            xb_RedrawTransition(0, 0);
            /* fallthrough */

        case 3:
            xb_RedrawTransition(0, 0);
            break;
        }

        break;

    default:
        xb_RedrawTransition(1, 0);
        break;
    }

    switch (Exit_No) {
    case 4:
        if (Exit_Timer < 180) {
            Exit_Timer++;
        }

        /* fallthrough */

    case 3:
        xb_RedrawTransition(2, 1);
        break;
    }

    BG_move();
}

void xb_GameDraw3(void) {
    switch (G_No[2]) {
    case 0:
        switch (M_No[0]) {
        case 0:
            xb_RedrawTransition(1, 0);
            break;

        case 1:
            xb_RedrawTransition(1, 0);
            break;

        case 2:
            switch (M_No[1]) {
            case 0:
                xb_RedrawTransition(1, 0);
                break;

            case 1:
                xb_RedrawTransition(0, 1);
                break;
            }

            break;
        }

        /* fallthrough */

    case 1:
    case 2:
    case 3:
    case 4:
        xb_RedrawTransition(0, 1);
        break;
    }

    BG_Draw_System();
    xb_draw_effect_work(4);
    xb_draw_effect_work(5);
    BG_move();
}

void xb_GameDraw2(void) {
    BG_Draw_System();

    if ((G_No[2] == 1 || G_No[2] == 3 || G_No[2] == 5) && !(G_No[2] == 5 && G_No[3] == 0)) {
        switch (C_No[0]) {
        case 0:
            xb_RedrawTransition(1, 0);
            break;

        case 1:
            switch (C_No[1]) {
            case 0:
                xb_RedrawTransition(1, 0);
                break;

            case 1:
                if (C_No[2] == 0) {
                    xb_RedrawTransition(0, 0);
                }

                break;

            case 4:
                switch (C_No[2]) {
                case 0:
                    if (Round_num == 0) {
                        xb_RedrawTransition(3, 1);
                    }

                    break;

                case 1:
                    xb_RedrawTransition(3, 1);
                    break;
                }

                break;
            }

            break;

        case 4:
            if (C_No[1] >= 4) {
                if (C_No[1] <= 5) {
                    xb_RedrawTransition(1, 0);
                } else if (C_No[1] == 6) {
                    xb_RedrawTransition(0, 0);
                }
            }

            break;

        case 9:
            if (C_No[1] > 1) {
                xb_RedrawTransition(1, 0);
            }

            break;

        case 10:
            if (C_No[1] == 1) {
                xb_RedrawTransition(1, 0);
            }

            break;
        }

        reqPlayerDraw();
        xb_draw_effect_work(0);
        xb_draw_effect_work(1);
        xb_draw_effect_work(2);
        xb_draw_effect_work(3);
        xb_draw_effect_work(4);
        xb_draw_effect_work(5);

        if (Disp_Cockpit) {
            counter_write(counter_color);
            vital_parts_allwrite(0);
            vital_parts_allwrite(1);
            player_face();
            player_name();
            xb_cmb_win_draw(0);
            xb_cmb_win_draw(1);
            stngauge_cont_main();
            xb_sast_draw();
            Sa_frame_Write();
            Score_Sub();
            Flash_Lamp();
            Disp_Win_Record();
        }
    } else {
        switch (G_No[2]) {
        case 5:
            if (G_No[3] != 0) {
                break;
            }

            TATE00();
            /* fallthrough */

        case 0:
        case 6:
        case 7:
            xb_RedrawTransition(1, 0);
            break;
        }
    }

    BG_move_Ex(3);
}

void xb_GameDraw12(void) {
    if (G_No[2] == 2) {
        xb_RedrawTransition(1, 1);
    }

    BG_Draw_System();
    xb_draw_effect_work(0);
    xb_draw_effect_work(1);
    xb_draw_effect_work(2);
    xb_draw_effect_work(3);
    xb_draw_effect_work(4);
    xb_draw_effect_work(5);
    bg_pos_hosei_sub2(0);
    bg_pos_hosei_sub2(1);
    bg_pos_hosei_sub2(2);
    Bg_Family_Set_appoint(0);
    Bg_Family_Set_appoint(1);
    Bg_Family_Set_appoint(2);
    BG_move_Ex(0);
}

void xb_GameDraw(void) {
    init_color_trans_req();
    init_texcash_before_process();
    seqsBeforeProcess();

    switch (G_No[1]) {
    case 1:
        xb_GameDraw1();
        break;

    case 2:
        xb_GameDraw2();
        break;

    case 3:
        xb_GameDraw3();
        break;

    case 12:
        xb_GameDraw12();
        break;

    default:
        if (G_No[1] != 13) {
            _assert("FALSE", "\\ac_work\\bloom_projects\\StreetFighterAnniversaryCollection_20040826v00\\sf33rd\\Source\\Game\\Game.c", 3228);
        }

        break;
    }

    if (xb_LiveWork_Get2330() > 0) {
        xb_SelectRenderTarget(0);
    }

    seqsAfterProcess();

    if (xb_LiveWork_Get2330() > 0) {
        xb_SelectRenderTarget(1);
        xb_PresentScreenTexture();
    }

    texture_cash_update();
    Check_LDREQ_Queue();
}

/* Xbox: online play first exchanges the pads through xb_NetSync_SyncPads and
 * only draws until it succeeds; the PS2 debug checks after the loop are
 * gone, and the render target switches around seqsAfterProcess. */
extern u16 p1sw_0;
extern u16 p1sw_1;
extern u16 p2sw_0;
extern u16 p2sw_1;
extern u16 D_00795CD8;
extern u16 D_00795CDC;
extern u16 D_00795CE0;
extern u16 D_00795CE4;
extern u16 D_007C56B8;
extern u16 D_007BE118;
extern u16 D_007C59D4;
extern u16 D_007C59D6;
s32 xb_GetOnlineFlag(void);
s32 xb_NetSync_IsDone(void);
s32 xb_NetSync_SyncPads(s32 a, s32 b);
void xb_GameDraw(void);
void move_pulpul_work(void);
void Check_Off_Vib(void);

void Game_Task(struct _TASK* task_ptr) {
    s16 ix;
    s16 ff;

    void (*Main_Jmp_Tbl[3])(struct _TASK*) = { Wait_Auto_Load, Loop_Demo, Game };

    if (xb_GetOnlineFlag() && G_No[1] != 13 && G_No[1] != 12 && xb_NetSync_IsDone()) {
        p1sw_1 = D_00795CD8;
        p2sw_1 = D_00795CDC;
        D_007C56B8 = D_00795CE0;
        D_007BE118 = D_00795CE4;

        if (xb_NetSync_SyncPads(4, 0) == 0) {
            xb_GameDraw();
            return;
        }

        D_00795CD8 = p1sw_0;
        D_00795CDC = p2sw_0;
        D_00795CE0 = D_007C59D6;
        D_00795CE4 = D_007C59D4;
    }

    init_color_trans_req();
    ff = Process_Counter;

    for (ix = 0; ix < ff; ix++) {
        if (ix == ff - 1) {
            No_Trans = 0;

            if (Turbo != 0 && (Process_Counter > 1) && (Turbo_Timer != 5)) {
                Play_Game = 0;
                break;
            }
        } else {
            No_Trans = 1;
        }

        Play_Game = 0;

        if (Game_pause != 0x81) {
            system_timer += 1;
        }

        init_texcash_before_process();
        seqsBeforeProcess();

        if (nowSoftReset() == 0) {
            Main_Jmp_Tbl[G_No[0]](task_ptr);
        }

        if (xb_LiveWork_Get2330() > 0) {
            xb_SelectRenderTarget(0);
        }

        seqsAfterProcess();

        if (xb_LiveWork_Get2330() > 0) {
            xb_SelectRenderTarget(1);
            xb_PresentScreenTexture();
        }

        texture_cash_update();
        move_pulpul_work();
        Check_Off_Vib();
        Check_LDREQ_Queue();
    }
}
