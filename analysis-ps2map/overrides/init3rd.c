/* The PS2 C assigns an array; this is the same copy as a memcpy. */
void Init_Task_1st(struct _TASK* task_ptr) {
    s16 ix;

    task_ptr->r_no[0] = 1;
    init_texcash_1st();
    Init_texgrplds_work();
    Init_load_on_memory_data();
    Pause_Family_On();
    Bg_TexInit();
    Scrscreen_Init();
    effect_work_init();
    Usage = 7;
    Max_vitality = 160;
    reset_NG_flag = 0;
    Break_Into = 0;
    Forbid_Break = 0;
    Extra_Break = 0;
    Demo_Flag = 0;
    Random_ix16 = 0;
    Random_ix32 = 0;
    test_flag = 0;
    ixbfw_cut = 0;
    PB_Music_Off = 0;
    No_Death = 0;
    Pause_Down = 0;
    Disp_Attack_Data = 0;
    seraph_flag = 0;
    Request_Break[0] = 0;
    Request_Break[1] = 0;
    DE_X[0] = 2;
    DE_X[1] = 0x1B;
    No_Trans = 0;
    Replay_Status[0] = 0;
    Replay_Status[1] = 0;
    Play_Game = 0;
    Present_Mode = 1;

    for (ix = 0; ix < 4; ix++) {
        G_No[ix] = 0;
        E_No[ix] = 0;
        S_No[ix] = 0;
        Unsubstantial_BG[ix] = 0;
    }

    init_pulpul_work();
    Init_Load_Request_Queue_1st();
    Game_Data_Init();

    for (ix = 0; ix < 6; ix++) {
        system_dir[ix] = Dir_Default_Data;
        permission_player[ix] = Permission_PL_Data;

        memcpy(&save_w[ix].extra_option.contents,
               &save_w[0].extra_option.contents,
               sizeof(save_w[ix].extra_option.contents));

        Direction_Working[ix] = 0;
        Vital_Handicap[ix][0] = 7;
        Vital_Handicap[ix][1] = 7;
        permission_player[ix].cursor_infor[0].first_x = 1;
        permission_player[ix].cursor_infor[0].first_y = 0;
        permission_player[ix].cursor_infor[1].first_x = 5;
        permission_player[ix].cursor_infor[1].first_y = 2;
    }

    Copy_Check_w();
    Direction_Working[2] = 1;
    save_w[4].Time_Limit = -1;
    save_w[5].Time_Limit = -1;
    Setup_Difficult_V();
    Setup_Limit_Time();
    Keep_Zoom_X = Screen_Zoom_X;
    Reset_Bootrom = 1;
    cpReadyTask(RESET_TASK_NUM, Reset_Task);
    Switch_Type = 0;
    Reset_Status[0] = 0;
    Reset_Status[1] = 0;
    pulpul_stop();
    Warning_Init();
    sub_000F4743(); /* CP3toPS2DrawOff (PS2 twins KnjFinish, mmSystemInitialize) */
}

void Init_Task_Aload(struct _TASK* task_ptr) {
    switch (task_ptr->r_no[1]) {
    case 0:
    case 1:
        task_ptr->r_no[1] = 2;
        /* fallthrough */

    case 2:
        /* Xbox: no SaveInit/SaveMove autoload here; Game0_0 and Game0_1 do it. */
        task_ptr->r_no[0] += 1;
        task_ptr->r_no[1] = 0;
        mpp_w.cutAnalogStickData = 0;
        Forbid_Reset = 1;
        break;

    case 10:
        break;
    }
}
