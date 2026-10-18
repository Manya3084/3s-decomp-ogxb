void Dir_Move_Sub_LR(u16 sw, s16 /* unused */) {
    u8 last_pos = system_dir[1].contents[Menu_Page][Menu_Cursor_Y[0]];

    switch (sw) {
    case 0x4:
        SE_dir_cursor_move();
        system_dir[1].contents[Menu_Page][Menu_Cursor_Y[0]] -= 1;

        if (Menu_Cursor_Y[0] == Menu_Max) {
            if (system_dir[1].contents[Menu_Page][Menu_Cursor_Y[0]] < 0) {
                system_dir[1].contents[Menu_Page][Menu_Cursor_Y[0]] = 0;
                IO_Result = 0x400; /* Xbox: PS2 0x80 */
                return;
            }

            if (system_dir[1].contents[Menu_Page][Menu_Cursor_Y[0]] != last_pos) {
                Message_Data->order = 1;
                Message_Data->request = system_dir[1].contents[Menu_Page][Menu_Max] + 0x74;
                Message_Data->timer = 2;
            }
        } else {
            if (system_dir[1].contents[Menu_Page][Menu_Cursor_Y[0]] < 0) {
                system_dir[1].contents[Menu_Page][Menu_Cursor_Y[0]] = Dir_Menu_Max_Data[Menu_Page][Menu_Cursor_Y[0]];
            }
        }

        return;

    case 0x8:
        SE_dir_cursor_move();
        system_dir[1].contents[Menu_Page][Menu_Cursor_Y[0]] += 1;

        if (Menu_Cursor_Y[0] == Menu_Max) {
            if (system_dir[1].contents[Menu_Page][Menu_Cursor_Y[0]] > 2) {
                system_dir[1].contents[Menu_Page][Menu_Cursor_Y[0]] = 2;
                IO_Result = 0x40; /* Xbox: PS2 0x400 */
                return;
            }

            if (system_dir[1].contents[Menu_Page][Menu_Cursor_Y[0]] > 2) {
                system_dir[1].contents[Menu_Page][Menu_Cursor_Y[0]] = 2;
            }

            if (system_dir[1].contents[Menu_Page][Menu_Cursor_Y[0]] != last_pos) {
                Message_Data->order = 1;
                Message_Data->request = system_dir[1].contents[Menu_Page][Menu_Max] + 0x74;
                Message_Data->timer = 2;
            }
        } else {
            if (system_dir[1].contents[Menu_Page][Menu_Cursor_Y[0]] > Dir_Menu_Max_Data[Menu_Page][Menu_Cursor_Y[0]]) {
                system_dir[1].contents[Menu_Page][Menu_Cursor_Y[0]] = 0;
            }
        }

        return;

    case 0x100:
        SE_dir_cursor_move();

        if (Menu_Cursor_Y[0] == Menu_Max) {
            return;
        } else {
            system_dir[1].contents[Menu_Page][Menu_Cursor_Y[0]] += 1;

            if (system_dir[1].contents[Menu_Page][Menu_Cursor_Y[0]] > Dir_Menu_Max_Data[Menu_Page][Menu_Cursor_Y[0]]) {
                system_dir[1].contents[Menu_Page][Menu_Cursor_Y[0]] = 0;
            }
        }

        return;
    }
}

/* Xbox: the position steps by 1 and is applied times 4; the size goes down
   to 88 (PS2: 94). */
void Screen_Move_Sub_LR(u16 sw) {
    s16 flag = 0;

    if (sw == 4) {
        switch (Menu_Cursor_Y[0]) {
        case 0:
            X_Adjust_Buff[2] -= 1;

            if (X_Adjust_Buff[2] < -10) {
                X_Adjust_Buff[2] = -10;
            } else {
                flag = 1;
            }

            break;

        case 1:
            Y_Adjust_Buff[2] -= 1;

            if (Y_Adjust_Buff[2] < -10) {
                Y_Adjust_Buff[2] = -10;
            } else {
                flag = 1;
            }

            break;

        case 2:
            Disp_Size_H -= 2;

            if (Disp_Size_H < 88) {
                Disp_Size_H = 88;
            } else {
                flag = 1;
            }

            Setup_Disp_Size(1);
            break;

        case 3:
            Disp_Size_V -= 2;

            if (Disp_Size_V < 88) {
                Disp_Size_V = 88;
            } else {
                flag = 1;
            }

            Setup_Disp_Size(1);
            break;

        case 4:
            sys_w.screen_mode = (sys_w.screen_mode + 1) & 1;
            flag = 1;
            break;
        }
    } else if (sw == 8) {
        switch (Menu_Cursor_Y[0]) {
        case 0:
            X_Adjust_Buff[2] += 1;

            if (X_Adjust_Buff[2] > 10) {
                X_Adjust_Buff[2] = 10;
            } else {
                flag = 1;
            }

            break;

        case 1:
            Y_Adjust_Buff[2] += 1;

            if (Y_Adjust_Buff[2] > 10) {
                Y_Adjust_Buff[2] = 10;
            } else {
                flag = 1;
            }

            break;

        case 2:
            Disp_Size_H += 2;

            if (Disp_Size_H > 100) {
                Disp_Size_H = 100;
            } else {
                flag = 1;
            }

            Setup_Disp_Size(1);
            break;

        case 3:
            Disp_Size_V += 2;

            if (Disp_Size_V > 100) {
                Disp_Size_V = 100;
            } else {
                flag = 1;
            }

            Setup_Disp_Size(1);
            break;

        case 4:
            sys_w.screen_mode = (sys_w.screen_mode + 1) & 1;
            flag = 1;
            break;
        }
    }

    if (flag) {
        SE_dir_cursor_move();
    }

    X_Adjust = X_Adjust_Buff[0] = X_Adjust_Buff[1] = X_Adjust_Buff[2] * 4;
    Y_Adjust = Y_Adjust_Buff[0] = Y_Adjust_Buff[1] = Y_Adjust_Buff[2] * 4;
}

/* Xbox menu screen id, set by each menu on entry: 10 button config, 12 sound
   test, 13 memory card, 19 after replay, 20 mode select. */
extern s32 D_00796884;
extern u8 D_007AA5F1;
/* Xbox bytes inside mpp_w (0x7AA5C0) past inGame; the Xbox MPP layout from
   +0x2B on is not the PS2 one, so they keep their addresses. */
extern u8 D_007AA5EC;
extern u8 D_007AA5ED;
extern u8 D_007AA5EF;

/* Xbox: MC_Move_Sub moves again past rows that screen has no entry for. */
u16 MC_Move_Sub(u16 sw, s16 cursor_id, s16 menu_max, s16 cansel_menu) {
#define MC_SKIP_ROW(y)                                                                                             \
    ((D_00796884 == 12 && (y) < 3) || (D_00796884 == 10 && ((y) == 3 || (y) == 7)) || (D_00796884 == 19 && (y) == 1) || \
     (D_00796884 == 13 && (y) == 2))
    if (Menu_Cursor_Move > 0) {
        return 0;
    }

    switch (sw) {
    case 0x1:
        do {
            Menu_Cursor_Y[cursor_id] -= 1;

            if (Menu_Cursor_Y[cursor_id] < 0) {
                Menu_Cursor_Y[cursor_id] = menu_max;
            }

            if ((cansel_menu == Menu_Cursor_Y[cursor_id]) && (Connect_Status == 0)) {
                Menu_Cursor_Y[cursor_id] -= 1;
            }
        } while (MC_SKIP_ROW(Menu_Cursor_Y[cursor_id]));

        SE_cursor_move();
        return IO_Result = 1;

    case 0x2:
        do {
            Menu_Cursor_Y[cursor_id] += 1;

            if (Menu_Cursor_Y[cursor_id] > menu_max) {
                Menu_Cursor_Y[cursor_id] = 0;
            }

            if ((cansel_menu == Menu_Cursor_Y[cursor_id]) && (Connect_Status == 0)) {
                Menu_Cursor_Y[cursor_id] += 1;
            }
        } while (MC_SKIP_ROW(Menu_Cursor_Y[cursor_id]));

        SE_cursor_move();
        return IO_Result = 2;

    case 0x10:
        return IO_Result = 0x10;

    case 0x100:
        return IO_Result = 0x100;

    case 0x200:
        return IO_Result = 0x200;

    case 0x400:
        return IO_Result = 0x400;

    case 0x4000:
        return IO_Result = 0x4000;

    default:
        return IO_Result = 0;

    case 0x20:
        return IO_Result = 0x20;

    case 0x40:
        return IO_Result = 0x40;

    case 0x80:
        return IO_Result = 0x80;

    case 0x800:
        return IO_Result = 0x800;
    }
#undef MC_SKIP_ROW
}

/* Xbox-only code the mode select calls (Xbox Live entry). */
s32 xb_LiveWork_Get1C4(void);
extern s32 D_0032F858;
void xb_LiveWork_Set8(s32 arg);
extern u8 D_007AA5FA[4];
void xb_SetOnlineModeArgs(s32 port, s32 arg);
void xb_MenuEnterOnline(struct _TASK* task_ptr);
void xb_BgmFadeOutSpeed(s32 arg);

/* Xbox: eight entries. Entry 6 goes to the Xbox-only mode (task state 14),
   entry 7 exits, Back (0x200) soft-resets, and the first frame goes straight
   to the Xbox-only mode when xb_LiveWork_Get1C4 and D_0032F858 say so. */
void Mode_Select(struct _TASK* task_ptr) {
    s16 ix;
    s16 PL_id;
    s16 loop_counter = 8;

    D_00796884 = 20;

    switch (task_ptr->r_no[2]) {
    case 0:
        FadeOut(1, 0xFF, 1);
        task_ptr->r_no[2] += 1;
        task_ptr->timer = 5;
        Mode_Type = 0;
        Present_Mode = 1;

        if (task[1].condition != 1) {
            E_No[0] = 1;
            E_No[1] = 2;
            E_No[2] = 2;
            E_No[3] = 0;
            cpReadyTask(ENTRY_TASK_NUM, Entry_Task);
        }

        Menu_Common_Init();

        for (ix = 0; ix < 4; ix++) {
            Menu_Suicide[ix] = 0;
        }

        Clear_Personal_Data(0);
        Clear_Personal_Data(1);
        Menu_Cursor_Y[0] = Cursor_Y_Pos[0][0];
        Cursor_Y_Pos[0][1] = 0;
        Cursor_Y_Pos[0][2] = 0;
        Cursor_Y_Pos[0][3] = 0;

        for (ix = 0; ix < 4; ix++) {
            Vital_Handicap[ix][0] = 7;
            Vital_Handicap[ix][1] = 7;
        }

        VS_Stage = 0x14;
        Order[0x8A] = 4;
        Order_Timer[0x8A] = 1;

        for (ix = 0; ix < 4; ix++) {
            Message_Data[ix].order = 3;
        }

        effect_57_init(0x64, 0, 0, 0x3F, 2);
        Order[0x64] = 1;
        Order_Dir[0x64] = 8;
        Order_Timer[0x64] = 1;
        Menu_Suicide[0] = 0;
        effect_04_init(0, 0, 0, 0x48);

        for (ix = 0; ix < loop_counter; ix++) {
            effect_61_init(0, ix + 0x50, 0, 0, (u32)ix, ix, 0x7047);
            Order[ix + 0x50] = 1;
            Order_Dir[ix + 0x50] = 4;
            Order_Timer[ix + 0x50] = ix + 0x14;
        }

        Menu_Cursor_Move = loop_counter;

        if (xb_LiveWork_Get1C4() && D_0032F858) {
            Present_Mode = 2;
            xb_LiveWork_Set8(1);

            for (ix = 0; ix < 4; ix++) {
                if (D_007AA5FA[ix] == 0) {
                    xb_SetOnlineModeArgs(ix, 0);
                }
            }

            Menu_in_Sub(task_ptr);
            Bg_Close();

            for (ix = 0; ix < 4; ix++) {
                Cursor_Y_Pos[0][ix] = 0;
                Unsubstantial_BG[ix] = 1;
            }

            Menu_Cursor_Y[0] = 0;
            Menu_Cursor_Y[1] = 0;

            for (ix = 0; ix < 4; ix++) {
                Menu_Suicide[ix] = 1;
            }

            task_ptr->r_no[1] = 8;
            task_ptr->r_no[0] = 0xE;
            cpExitTask(SAVER_TASK_NUM);
            Order[0x4F] = 4;
            Order_Timer[0x4F] = 1;
            Decide_PL(0);
        }

        break;

    case 1:
        if (Menu_Sub_case1(task_ptr) != 0) {
            Order[0x4E] = 2;
            Order_Dir[0x4E] = 0;
            Order_Timer[0x4E] = 1;
            checkAdxFileLoaded();
            checkSelObjFileLoaded();
        }

        break;

    case 2:
        if (FadeIn(1, 0x19, 1) != 0) {
            task_ptr->r_no[2] += 1;
            Suicide[3] = 0;
        }

        break;

    case 3:
        if (Connect_Status == 0 && Menu_Cursor_Y[0] == 1) {
            Menu_Cursor_Y[0] = 2;
        } else {
            PL_id = 0;

            if (MC_Move_Sub(Check_Menu_Lever(0, 0), 0, loop_counter - 1, 1) == 0) {
                PL_id = 1;
                MC_Move_Sub(Check_Menu_Lever(1, 0), 0, loop_counter - 1, 1);
            }
        }

        switch (IO_Result) {
        case 0x100:
            switch (Menu_Cursor_Y[0]) {
            case 0:
                G_No[2] += 1;
                Mode_Type = 0;
                task_ptr->r_no[0] = 5;
                cpExitTask(SAVER_TASK_NUM);
                Decide_PL(PL_id);
                break;

            case 1:
                Setup_VS_Mode(task_ptr);
                G_No[1] = 0xC;
                G_No[2] = 1;
                Mode_Type = 1;
                cpExitTask(MENU_TASK_NUM);
                break;

            case 2:
            case 3:
            case 4:
            case 5:
                task_ptr->r_no[2] += 1;
                task_ptr->free[0] = 0;
                task_ptr->free[1] = Menu_Cursor_Y[0] + 2;
                break;

            case 6:
                Present_Mode = 2;
                xb_LiveWork_Set8(1);

                for (ix = 0; ix < 4; ix++) {
                    if (PL_id == 0) {
                        if (D_007AA5FA[ix] == 0) {
                            xb_SetOnlineModeArgs(ix, 0);
                        }
                    } else if (PL_id == 1) {
                        if (D_007AA5FA[ix] == 1) {
                            xb_SetOnlineModeArgs(ix, 1);
                        }
                    }
                }

                xb_MenuEnterOnline(task_ptr);
                xb_BgmFadeOutSpeed(0x40);
                Bg_Close();

                for (ix = 0; ix < 4; ix++) {
                    Cursor_Y_Pos[0][ix] = 0;
                    Unsubstantial_BG[ix] = 1;
                }

                Menu_Cursor_Y[0] = 0;
                Menu_Cursor_Y[1] = 0;

                for (ix = 0; ix < 4; ix++) {
                    Menu_Suicide[ix] = 1;
                }

                task_ptr->r_no[1] = 8;
                task_ptr->r_no[0] = 0xE;
                task_ptr->free[0] = 0;
                task_ptr->free[1] = 0;
                cpExitTask(SAVER_TASK_NUM);
                Order[0x4F] = 4;
                Order_Timer[0x4F] = 1;
                Decide_PL(PL_id);
                break;

            case 7:
                task_ptr->r_no[2] += 1;
                task_ptr->free[0] = 0;
                task_ptr->free[1] = Menu_Cursor_Y[0] + 1;
                break;

            default:
                break;
            }

            sub_0009C793();
            break;

        case 0x200:
            Soft_Reset_Sub();
            break;
        }

        break;

    default:
        Exit_Sub(task_ptr, 0, task_ptr->free[1]);
        break;
    }
}

/* Xbox: sets the screen id (10). */
void Button_Config(struct _TASK* task_ptr) {
    s16 ix;
    s16 disp_index;

    D_00796884 = 10;

    switch (task_ptr->r_no[2]) {
    case 0:
        FadeOut(1, 0xFF, 1);
        task_ptr->r_no[2] += 1;
        task_ptr->timer = 5;
        Menu_Common_Init();
        pp_operator_check_flag(0);
        Menu_Cursor_Y[0] = 0;
        Menu_Cursor_Y[1] = 0;
        Menu_Suicide[1] = 1;
        Menu_Suicide[2] = 0;
        Copy_Key_Disp_Work();
        Order[0x4F] = 4;
        Order_Timer[0x4F] = 1;
        Order[0x4E] = 2;
        Order_Dir[0x4E] = 2;
        Order_Timer[0x4E] = 1;
        effect_57_init(0x6B, 2, 0, 0x3F, 2);
        Order[0x6B] = 1;
        Order_Dir[0x6B] = 8;
        Order_Timer[0x6B] = 1;

        for (ix = 0; ix < 12; ix++) {
            effect_23_init(0, ix + 0x50, 0, 2, 2, ix, 0x70A7, ix + 9, 1);
            Order[ix + 0x50] = 1;
            Order_Dir[ix + 0x50] = 4;
            Order_Timer[ix + 0x50] = ix + 0x14;
            effect_23_init(1, ix + 0x5C, 0, 2, 3, ix, 0x70A7, ix + 9, 1);
            Order[ix + 0x5C] = 1;
            Order_Dir[ix + 0x5C] = 4;
            Order_Timer[ix + 0x5C] = ix + 0x14;
        }

        for (ix = 0; ix < 9; ix++) {
            if (ix == 8) {
                disp_index = 1;
            } else {
                disp_index = 0;
            }

            effect_23_init(0, ix + 0x78, 0, 2, disp_index, ix, 0x70A7, ix, 0);
            Order[ix + 0x78] = 1;
            Order_Dir[ix + 0x78] = 4;
            Order_Timer[ix + 0x78] = ix + 0x14;
            effect_23_init(1, ix + 0x81, 0, 2, disp_index, ix, 0x70A7, ix, 0);
            Order[ix + 0x81] = 1;
            Order_Dir[ix + 0x81] = 4;
            Order_Timer[ix + 0x81] = ix + 0x14;
        }

        Menu_Cursor_Move = 0x22;
        effect_66_init(0x8A, 7, 2, 0, -1, -1, -0x7FFF);
        Order[0x8A] = 1;
        Order_Dir[0x8A] = 4;
        Order_Timer[0x8A] = 0x14;
        effect_66_init(0x8B, 8, 2, 0, -1, -1, -0x7FFF);
        Order[0x8B] = 1;
        Order_Dir[0x8B] = 4;
        Order_Timer[0x8B] = 0x14;
        break;

    case 1:
        Menu_Sub_case1(task_ptr);
        break;

    case 2:
        if (FadeIn(1, 0x19, 1) != 0) {
            task_ptr->r_no[2] += 1;
            Suicide[3] = 0;
        }

        break;

    case 3:
        Button_Config_Sub(0);
        Button_Exit_Check(task_ptr, 0);
        Button_Config_Sub(1);
        Button_Exit_Check(task_ptr, 1);
        Save_Game_Data();
        break;
    }
}

/* Xbox: sets D_007AA5ED and the screen id (10). */
void Button_Config_Tr(struct _TASK* task_ptr) {
    D_007AA5ED = 1;
    D_00796884 = 10;
    switch (task_ptr->r_no[2]) {
    case 0:
        task_ptr->r_no[2]++;
        Menu_Common_Init();
        Menu_Cursor_Y[0] = 0;
        Menu_Cursor_Y[1] = 0;
        Menu_Suicide[0] = 1;
        Training_Index = 5;
        Copy_Key_Disp_Work();
        Setup_Button_Sub(6, 5, 1);
        pp_operator_check_flag(0);
        break;

    case 1:
        Button_Config_Sub(0);
        Button_Exit_Check_in_Tr(task_ptr, 0);
        Button_Config_Sub(1);
        Button_Exit_Check_in_Tr(task_ptr, 1);
        Save_Game_Data();
        break;
    }
}

/* Xbox: sets the screen id (10). */
void Button_Config_in_Game(struct _TASK* task_ptr) {
    s16 ix;

    D_00796884 = 10;

    if (Check_Pad_in_Pause(task_ptr) != 0) {
        Order[0x8A] = 3;
        Order_Timer[0x8A] = 1;
        effect_66_init(0x8A, 9, 2, 7, -1, -1, -0x3FFC);
        return;
    }

    switch (task_ptr->r_no[2]) {
    case 0:
        task_ptr->r_no[2]++;
        Menu_Common_Init();
        Menu_Cursor_Y[0] = 0;
        Menu_Cursor_Y[1] = 0;
        Copy_Key_Disp_Work();
        Setup_Button_Sub(6, 5, 3);
        Order[0x8A] = 3;
        Order_Timer[0x8A] = 1;
        effect_66_init(0x8B, 0xA, 3, 7, -1, -1, -0x3FFB);
        Order[0x8B] = 3;
        Order_Timer[0x8B] = 1;
        effect_66_init(0x8C, 0xB, 3, 7, -1, -1, -0x3FFB);
        Order[0x8C] = 3;
        Order_Timer[0x8C] = 1;
        break;

    case 1:
        Button_Config_Sub(0);
        Button_Exit_Check_in_Game(task_ptr, 0);
        Button_Config_Sub(1);
        Button_Exit_Check_in_Game(task_ptr, 1);
        Save_Game_Data();
        break;
    }
}

/* Xbox: sets the screen id (13), and the four labels start at 0x16 (PS2: 0x15). */
void Memory_Card(struct _TASK* task_ptr) {
    s16 ix;
    s16 char_index;

    s16 unused_s3;
    s16 unused_s2;

    D_00796884 = 13;

    switch (task_ptr->r_no[2]) {
    case 0:
        FadeOut(1, 0xFF, 1);
        task_ptr->r_no[2] += 1;
        task_ptr->timer = 5;
        Menu_Common_Init();
        Menu_Cursor_Y[0] = 0;
        Menu_Suicide[1] = 1;
        Menu_Suicide[2] = 0;
        Order[0x4F] = 4;
        Order_Timer[0x4F] = 1;
        Order[0x4E] = 2;
        Order_Dir[0x4E] = 4;
        Order_Timer[0x4E] = 1;
        effect_57_init(0x69, 5, 0, 0x3F, 2);
        Order[0x69] = 1;
        Order_Dir[0x69] = 8;
        Order_Timer[0x69] = 1;

        for (ix = 0, unused_s3 = char_index = 0x16; ix < 4; ix++, unused_s2 = char_index++) {
            effect_61_init(0, ix + 0x50, 1, 2, char_index, ix, 0x7047);
            Order[ix + 0x50] = 1;
            Order_Dir[ix + 0x50] = 4;
            Order_Timer[ix + 0x50] = ix + 0x14;
        }

        Menu_Cursor_Move = 4;
        effect_64_init(0x61, 1, 2, 0, 2, 0x7047, 0, 3, 0);
        Order[0x61] = 1;
        Order_Dir[0x61] = 4;
        Order_Timer[0x61] = 0x18;
        effect_66_init(0x8A, 8, 2, 1, -1, -1, -0x7FF5);
        Order[0x8A] = 3;
        Order_Timer[0x8A] = 1;
        effect_04_init(2, 2, 2, 0x48);
        Setup_File_Property(0, 0xFF);
        break;

    case 1:
        Menu_Sub_case1(task_ptr);
        break;

    case 2:
        if (FadeIn(1, 0x19, 1) != 0) {
            task_ptr->r_no[2] += 1;
            Suicide[3] = 0;
        }

        break;

    case 3:
        Memory_Card_Sub(0);
        Button_Exit_Check(task_ptr, 0);

        if (IO_Result == 0) {
            Memory_Card_Sub(1);
            Button_Exit_Check(task_ptr, 0);
        }

        break;

    case 4:
    case 5:
    case 6:
        Save_Load_Menu(task_ptr);
        break;
    }
}

/* Xbox: screen id 12; the cursor starts on row 3, the labels start at 0x3C (PS2: 0x3B), and the reset entry sets both levels to 0xB (PS2: 0xF). */
void Sound_Test(struct _TASK* task_ptr) {
    s16 char_index;
    s16 ix;
    u8 last_mode;

    Clear_Flash_Sub();

    D_00796884 = 12;

    switch (task_ptr->r_no[2]) {
    case 0:
        FadeOut(1, 0xFF, 1);
        task_ptr->r_no[2] += 1;
        task_ptr->timer = 5;
        setupAlwaysSeamlessFlag(((plsw_00[0] | plsw_00[1]) & 0x4000) != 0);
        Clear_Flash_Init(4);
        Menu_Common_Init();
        Menu_Cursor_Y[0] = 3;
        Menu_Suicide[1] = 1;
        Menu_Suicide[2] = 0;
        Convert_Buff[3][1][5] = 0;

        if (sys_w.sound_mode == 0) {
            Convert_Buff[3][1][0] = 0;
        } else {
            Convert_Buff[3][1][0] = 1;
        }

        if (sys_w.bgm_type == 0) {
            Convert_Buff[3][1][3] = 0;
        } else {
            Convert_Buff[3][1][3] = 1;
        }

        Convert_Buff[3][1][7] = 1;
        Order[0x4F] = 4;
        Order_Timer[0x4F] = 1;
        Order[0x4E] = 2;
        Order_Dir[0x4E] = 2;
        Order_Timer[0x4E] = 1;
        effect_57_init(0x72, 4, 0, 0x3F, 2);
        Order[0x72] = 1;
        Order_Dir[0x72] = 8;
        Order_Timer[0x72] = 1;
        effect_04_init(2, 6, 2, 0x48);

        {
            s32 ixSoundMenuItem[4] = { 10, 11, 11, 12 };

            for (ix = 0; ix < 4; ix++) {
                Order[ix + 0x57] = 1;
                Order_Dir[ix + 0x57] = 4;
                Order_Timer[ix + 0x57] = ix + 0x14;
                effect_64_init(ix + 0x57, 0, 2, ixSoundMenuItem[ix] + 1, ix, 0x7047, ix + 0xC, 3, 1);
            }
        }

        Order_Dir[0x78] = 0;
        effect_A8_init(0, 0x78, 0, 2, 5, 0x70A7, 0);
        Order_Dir[0x79] = 1;
        effect_A8_init(0, 0x79, 0, 2, 5, 0x70A7, 1);
        effect_A8_init(3, 0x7A, 0, 2, 5, 0x70A7, 3);
        Convert_Buff[3][1][5] = 0;
        Order_Dir[0x7B] = 0;
        effect_A8_init(2, 0x7B, 0, 2, 5, 0x70A7, 2);

        {
            s16 unused_s2;
            s16 unused_s3;

            for (ix = 0, unused_s3 = char_index = 0x3C; ix < 7; ix++, unused_s2 = char_index++) {
                effect_61_init(0, ix + 0x50, 0, 2, char_index, ix, 0x7047);
                Order[ix + 0x50] = 1;
                Order_Dir[ix + 0x50] = 4;
                Order_Timer[ix + 0x50] = ix + 0x14;
            }
        }

        Menu_Cursor_Move = 5;
        break;

    case 1:
        Menu_Sub_case1(task_ptr);
        break;

    case 2:
        if (FadeIn(1, 0x19, 1) != 0) {
            task_ptr->r_no[2] += 1;
            Suicide[3] = 0;
        }

        break;

    case 3:
        last_mode = Convert_Buff[3][1][0];
        Sound_Cursor_Sub(0);

        if (IO_Result == 0) {
            Sound_Cursor_Sub(1);
        }

        if ((Menu_Cursor_Y[0] == 4) && (IO_Result == 0x100)) {
            sub_0009C793();
            Convert_Buff[3][1][0] = 0;
            Convert_Buff[3][1][1] = 0xB;
            Convert_Buff[3][1][2] = 0xB;
            Convert_Buff[3][1][3] = 0;
        }

        if (bgm_level != (s16)Convert_Buff[3][1][1]) {
            bgm_level = Convert_Buff[3][1][1];
            save_w[Present_Mode].BGM_Level = Convert_Buff[3][1][1];
            SsBgmHalfVolume(0);
        }

        if (se_level != (s16)Convert_Buff[3][1][2]) {
            se_level = Convert_Buff[3][1][2];
            setSeVolume(save_w[Present_Mode].SE_Level = Convert_Buff[3][1][2]);
        }

        save_w[Present_Mode].BgmType = Convert_Buff[3][1][3];

        if (sys_w.bgm_type != Convert_Buff[3][1][3]) {
            sys_w.bgm_type = Convert_Buff[3][1][3];
            Convert_Buff[3][1][5] = 0;
            BGM_Request_Code_Check(0x41);
        }

        Order_Dir[0x7B] = Convert_Buff[3][1][5];
        Setup_Sound_Mode(last_mode);
        Save_Game_Data();

        if (Menu_Cursor_Y[0] == 5) {
            if (IO_Result == 0x100) {
                SsRequest((u16)Order_Dir[0x7B] + 1);
                Convert_Buff[3][1][7] = 1;
                return;
            }

            if ((IO_Result == 0x200) && Convert_Buff[3][1][7]) {
                Convert_Buff[3][1][7] = 0;
                BGM_Stop();
                return;
            }
        }

        if (IO_Result == 0x200 || ((Menu_Cursor_Y[0] == 6) && (IO_Result == 0x100 || IO_Result == 0x4000))) {
            sub_0009C793();
            Return_Option_Mode_Sub(task_ptr);
            setupAlwaysSeamlessFlag(0);
            Order[0x72] = 4;
            Order_Timer[0x72] = 4;
            BGM_Request_Code_Check(0x41);
        }

        break;
    }
}

/* Xbox: screen id 19, and the labels start at '9' (PS2: '8'). */
void After_Replay(struct _TASK* task_ptr) {
    s16 ix;
    s16 char_ix;

    s16 s5;
    s16 s4;
    s16 s3;
    s16 s2;

    D_00796884 = 19;

    switch (task_ptr->r_no[1]) {
    case 0:
        task_ptr->r_no[1]++;
        ToneDown(192, 32);
        Menu_Common_Init();
        Menu_Suicide[0] = 0;
        Menu_Cursor_Y[0] = 0;

        for (ix = 0, s5 = char_ix = '9'; ix < 3; ix++, s4 = char_ix++) {
            effect_61_init(0, ix + 80, 0, 0, char_ix, ix, 0x7047);
            Order[ix + 80] = 3;
            Order_Timer[ix + 80] = 1;
        }

        effect_66_init(138, 38, 0, 0, -1, -1, -0x7FF7);
        Order[138] = 3;
        Order_Timer[138] = 1;
        break;

    case 1:
        ToneDown(192, 32);
        Pause_ID = 0;

        if (MC_Move_Sub(Check_Menu_Lever(0, 0), 0, 2, 0xFF) == 0) {
            Pause_ID = 1;
            MC_Move_Sub(Check_Menu_Lever(1, 0), 0, 2, 0xFF);
        }

        switch (IO_Result) {
        case 0x100:
            sub_0009C793();
            task_ptr->r_no[1] = Menu_Cursor_Y[0] + 2;
            break;

        case 0x200:
            sub_0009C793();
            task_ptr->r_no[1] = 4;
            break;
        }

        break;

    case 4:
        ToneDown(192, 32);
        Back_to_Mode_Select(task_ptr);
        break;

    case 2:
        ToneDown(192, 32);
        task_ptr->r_no[1] = 12;
        task_ptr->r_no[2] = 0;
        task_ptr->r_no[3] = 0;

    case 12:
        Load_Replay_Sub(task_ptr);
        break;

    case 3:
        task_ptr->free[0] = 0;
        task_ptr->r_no[1] = 5;
        task_ptr->r_no[2] = 0;

    case 5:
        ToneDown(192, 32);

        if (Exit_Sub(task_ptr, 0, 6)) {
            Menu_Suicide[0] = 1;
            Menu_Suicide[1] = Menu_Suicide[2] = Menu_Suicide[3] = 0;
        }

        break;

    case 6:
        ToneDown(232, 32);
        switch (task_ptr->r_no[2]) {
        case 0:
            FadeOut(1, 0xFF, 1);
            task_ptr->r_no[2]++;
            task_ptr->timer = 5;
            Menu_Suicide[0] = 0;
            Menu_Common_Init();
            Menu_Cursor_X[0] = 0;
            Setup_BG(1, 512, 0);
            effect_57_init(110, 9, 0, 63, 999);
            Order[110] = 3;
            Order_Dir[110] = 8;
            Order_Timer[110] = 1;
            Setup_File_Property(1, 0xFF);
            SaveInit(2, 1);
            effect_66_init(138, 41, 0, 0, -1, -1, -0x7FF3);
            Order[138] = 3;
            Order_Timer[138] = 1;
            break;

        case 1:
            Menu_Sub_case1(task_ptr);
            break;

        case 2:
            Setup_Save_Replay_2nd(task_ptr, 1);
            break;

        case 3:
            if (SaveMove() > 0) {
                break;
            }

            task_ptr->r_no[2]++;
            /* fallthrough */

        case 4:
            Exit_Sub(task_ptr, 0, 7);
            break;
        }

        break;

    case 7:
        FadeOut(1, 0xFF, 1);
        Order[110] = 4;
        Order_Timer[110] = 1;
        Menu_Suicide[0] = 1;
        task_ptr->r_no[1]++;
        break;

    case 8:
        FadeOut(1, 0xFF, 1);
        Menu_Suicide[0] = 0;

        for (ix = 0, s3 = char_ix = '9'; ix < 3; ix++, s2 = char_ix++) {
            effect_61_init(0, ix + 80, 0, 0, char_ix, ix, 0x7047);
            Order[ix + 80] = 3;
            Order_Timer[ix + 80] = 1;
        }

        effect_66_init(138, 38, 0, 0, -1, -1, -0x7FF7);
        Order[138] = 3;
        Order_Timer[138] = 1;
        task_ptr->r_no[1]++;
        FadeInit();

    case 9:
        ToneDown(192, 32);

        if (FadeIn(1, 25, 1)) {
            task_ptr->r_no[2] = 0;
            task_ptr->r_no[1] = 1;
        }
    }
}

/* Xbox pad check: (buttons & 0x30) == 0x10 (START) gives 1, == 0x20 (BACK)
   gives 0, otherwise -1. */
s32 xb_GetStartBackPress(s32 pl_id);

/* Xbox: no cursor; START soft-resets and BACK returns, both with the select
   sound. */
s32 Yes_No_Cursor_Move_Sub(struct _TASK* task_ptr) {
    s32 ret;

    switch (xb_GetStartBackPress(Pause_ID)) {
    case 0:
        task_ptr->r_no[2] = 1;
        Menu_Suicide[0] = 0;
        Menu_Suicide[1] = 1;
        Cursor_Y_Pos[0][0] = 2;
        ret = 1;
        break;

    case 1:
        Soft_Reset_Sub();
        ret = -1;
        break;

    default:
        return 0;
    }

    sub_0009C793();
    return ret;
}

/* Xbox: no cursor sound, the Japanese message table when D_007AA5F1 is
   set, and pages turn on 0x400 (left) and 0x40 (right) only. */
void Extra_Option(struct _TASK* task_ptr) {
    Menu_Cursor_Y[1] = Menu_Cursor_Y[0];

    switch (task_ptr->r_no[2]) {
    case 0:
        FadeOut(1, 0xFF, 1);
        task_ptr->r_no[2]++;
        task_ptr->r_no[3] = 0;
        task_ptr->timer = 5;
        Menu_Suicide[1] = 1;
        Menu_Suicide[2] = 0;
        Menu_Page = 0;
        Page_Max = 3;
        Menu_Page_Buff = Menu_Page;
        Message_Data->kind_req = 4;
        break;

    case 1:
        FadeOut(1, 0xFF, 1);
        task_ptr->r_no[2]++;
        Setup_Next_Page(task_ptr, task_ptr->r_no[3]);
        /* fallthrough */

    case 2:
        FadeOut(1, 0xFF, 1);

        if (--task_ptr->timer == 0) {
            task_ptr->r_no[2]++;
            task_ptr->r_no[3] = 1;
            FadeInit();
        }

        break;

    case 3:
        if (FadeIn(1, 25, 1)) {
            task_ptr->r_no[2]++;
            break;
        }

        break;

    case 4:
        Pause_ID = 0;
        Dir_Move_Sub(task_ptr, 0);

        if (IO_Result == 0) {
            Pause_ID = 1;
            Dir_Move_Sub(task_ptr, 1);
        }

        if (Menu_Cursor_Y[1] != Menu_Cursor_Y[0]) {
            save_w[Present_Mode].extra_option.contents[Menu_Page][Menu_Max] = 1;

            if (Menu_Cursor_Y[0] < Menu_Max) {
                Message_Data->order = 1;
                Message_Data->request = Ex_Account_Data[Menu_Page] + Menu_Cursor_Y[0];
                Message_Data->timer = 2;

                if (msgExtraTbl[D_007AA5F1 != 0]->msgNum[Menu_Cursor_Y[0] + (Menu_Page * 8)] == 1) {
                    Message_Data->pos_y = 54;
                } else {
                    Message_Data->pos_y = 62;
                }
            } else {
                Message_Data->order = 1;
                Message_Data->request = save_w[Present_Mode].extra_option.contents[Menu_Page][Menu_Max] + 32;
                Message_Data->timer = 2;
                Message_Data->pos_y = 54;
            }
        }

        switch (IO_Result) {
        case 0x200:
            Return_Option_Mode_Sub(task_ptr);
            Order[115] = 4;
            Order_Timer[115] = 4;
            save_w[4].extra_option = save_w[1].extra_option;
            save_w[5].extra_option = save_w[1].extra_option;
            sub_0009C793();
            break;

        case 0x400:
            task_ptr->r_no[2] = 1;
            task_ptr->timer = 5;

            if (--Menu_Page < 0) {
                Menu_Page = Page_Max;
            }

            sub_0009C793();
            break;

        case 0x40:
            task_ptr->r_no[2] = 1;
            task_ptr->timer = 5;

            if (++Menu_Page > Page_Max) {
                Menu_Page = 0;
            }

            sub_0009C793();
            break;

        case 0x100:
            if (Menu_Page == 0 && Menu_Cursor_Y[0] == 6) {
                save_w[Present_Mode].extra_option = save_w[0].extra_option;
                sub_0009C793();
                break;
            }

            if (Menu_Cursor_Y[0] != Menu_Max) {
                break;
            }

            switch (save_w[Present_Mode].extra_option.contents[Menu_Page][Menu_Max]) {
            case 0:
                task_ptr->r_no[2] = 1;
                task_ptr->timer = 5;

                if (--Menu_Page < 0) {
                    Menu_Page = Page_Max;
                }

                break;

            case 2:
                task_ptr->r_no[2] = 1;
                task_ptr->timer = 5;

                if (++Menu_Page > Page_Max) {
                    Menu_Page = 0;
                }

                break;

            default:
                Return_Option_Mode_Sub(task_ptr);
                save_w[4].extra_option = save_w[1].extra_option;
                save_w[5].extra_option = save_w[1].extra_option;
                Order[115] = 4;
                Order_Timer[115] = 4;
                break;
            }

            sub_0009C793();

            break;
        }

        break;
    }
}

/* Xbox: the Japanese message tables when D_007AA5F1 is set. */
void Setup_Next_Page(struct _TASK* task_ptr, u8 /* unused */) {
    s16 ix;
    s16 disp_index;
    s16 mode_type;

    s16 unused_s3;

    Menu_Page_Buff = Menu_Page;
    effect_work_init();
    Menu_Common_Init();
    Menu_Cursor_Y[0] = 0;
    Order[0x4E] = 5;
    Order_Timer[0x4E] = 1;

    if (task_ptr->r_no[1] == 0xE) {
        mode_type = 1;
        Menu_Max = Ex_Page_Data[Menu_Page];
        save_w[1].extra_option.contents[Menu_Page][Menu_Max] = 1;
        Order_Dir[0x4E] = 1;
        effect_57_init(0x4E, 1, 0, 0x45, 0);
        Order[0x73] = 3;
        Order_Dir[0x73] = 8;
        Order_Timer[0x73] = 1;
        effect_57_init(0x73, 6, 0, 0x3F, 2);
        effect_66_init(0x5C, 0x27, 2, 0, 0x47, 0xB, 0);
        Order[0x5C] = 3;
        Order_Timer[0x5C] = 1;
        effect_66_init(0x5D, 0x28, 2, 0, 0x40, (s16)Menu_Page + 1, 0);
        Order[0x5D] = 3;
        Order_Timer[0x5D] = 1;

        if ((msgExtraTbl[D_007AA5F1 != 0]->msgNum[Menu_Cursor_Y[0] + Menu_Page * 8]) == 1) {
            Message_Data->pos_y = 0x36;
        } else {
            Message_Data->pos_y = 0x3E;
        }

        Message_Data->request = Ex_Account_Data[Menu_Page] + Menu_Cursor_Y[0];
    } else {
        mode_type = 0;
        Menu_Max = Page_Data[Menu_Page];
        system_dir[1].contents[Menu_Page][Menu_Max] = 1;
        effect_66_init(0x5B, 0x14, 2, 0, 0x47, 0xA, 0);
        Order[0x5B] = 3;
        Order_Timer[0x5B] = 1;
        Order[0x4E] = 5;
        Order_Dir[0x4E] = 3;
        effect_57_init(0x4E, 0, 0, 0x45, 0);
        effect_66_init(0x5C, 0x15, 2, 0, 0x47, 0xB, 0);
        Order[0x5C] = 3;
        Order_Timer[0x5C] = 1;
        effect_66_init(0x5D, 0x16, 2, 0, 0x40, (s16)Menu_Page + 1, 0);
        Order[0x5D] = 3;
        Order_Timer[0x5D] = 1;

        if ((msgSysDirTbl[D_007AA5F1 != 0]->msgNum[Menu_Page * 0xC + Menu_Cursor_Y[0] * 2 + 1]) == 1) {
            Message_Data->pos_y = 0x36;
        } else {
            Message_Data->pos_y = 0x3E;
        }

        disp_index = Menu_Page * 0xC;
        Message_Data->request = disp_index + 1;
    }

    Menu_Cursor_Y[0] = 0;
    effect_66_init(0x8A, 0x13, 2, 0, -1, -1, -0x8000);
    Order[0x8A] = 3;
    Order_Timer[0x8A] = 1;
    Message_Data->order = 0;
    Message_Data->timer = 1;
    Message_Data->pos_x = 0;
    Message_Data->pos_z = 0x45;
    effect_45_init(0, 0, 2);

    for (ix = 0; ix < Menu_Max; ix++, unused_s3 = disp_index += 2) {
        if (mode_type == 0) {
            effect_18_init(disp_index, ix, 0, 2);
            effect_51_init(ix, ix, 2);
        } else {
            effect_C4_init(0, ix, ix, 2);

            if (Menu_Page != 0 || ix != (Menu_Max - 1)) {
                effect_C4_init(1, ix, ix, 2);
            }
        }
    }

    effect_40_init(mode_type, 0, 0x48, 0, 2, 1);
    effect_40_init(mode_type, 1, 0x49, 0, 2, 1);
    effect_40_init(mode_type, 2, 0x4A, 0, 2, 0);
    effect_40_init(mode_type, 3, 0x4B, 0, 2, 2);
}

/* Xbox: no cursor sound, the Japanese message table when D_007AA5F1 is
   set, and pages turn on 0x400 (left) and 0x40 (right) only. */
void Direction_Menu(struct _TASK* task_ptr) {
    Menu_Cursor_Y[1] = Menu_Cursor_Y[0];

    switch (task_ptr->r_no[2]) {
    case 0:
        FadeOut(1, 0xFF, 1);
        task_ptr->r_no[2] += 1;
        task_ptr->timer = 5;
        Menu_Suicide[1] = 1;
        Menu_Suicide[2] = 0;
        Menu_Page = 0;
        Menu_Page_Buff = Menu_Page;
        Message_Data->kind_req = 3;
        break;

    case 1:
        FadeOut(1, 0xFF, 1);
        task_ptr->r_no[2] += 1;
        Setup_Next_Page(task_ptr, 0);
        /* fallthrough */

    case 2:
        FadeOut(1, 0xFF, 1);

        if (--task_ptr->timer == 0) {
            task_ptr->r_no[2] += 1;
            FadeInit();
        }

        break;

    case 3:
        if (FadeIn(1, 0x19, 1) != 0) {
            task_ptr->r_no[2] += 1;
        }

        break;

    case 4:
        Pause_ID = 0;

        Dir_Move_Sub(task_ptr, 0);

        if (IO_Result == 0) {
            Pause_ID = 1;
            Dir_Move_Sub(task_ptr, 1);
        }

        if (Menu_Cursor_Y[1] != Menu_Cursor_Y[0]) {
            system_dir[1].contents[Menu_Page][Menu_Max] = 1;

            if (Menu_Cursor_Y[0] < Menu_Max) {
                Message_Data->order = 1;
                Message_Data->request = Menu_Page * 0xC + Menu_Cursor_Y[0] * 2 + 1;
                Message_Data->timer = 2;

                if (msgSysDirTbl[D_007AA5F1 != 0]->msgNum[Menu_Page * 0xC + Menu_Cursor_Y[0] * 2 + 1] == 1) {
                    Message_Data->pos_y = 0x36;
                } else {
                    Message_Data->pos_y = 0x3E;
                }
            } else {
                Message_Data->order = 1;
                Message_Data->request = system_dir[1].contents[Menu_Page][Menu_Max] + 0x74;
                Message_Data->timer = 2;
                Message_Data->pos_y = 0x36;
            }
        }

        switch (IO_Result) {
        case 0x200:
            task_ptr->r_no[2] += 1;
            Menu_Suicide[0] = 0;
            Menu_Suicide[1] = 0;
            Menu_Suicide[2] = 1;
            sub_0009C793();
            break;

        case 0x400:
            task_ptr->r_no[2] = 1;
            task_ptr->timer = 5;

            if (--Menu_Page < 0) {
                Menu_Page = (s8)Page_Max;
            }

            sub_0009C793();
            break;

        case 0x40:
            task_ptr->r_no[2] = 1;
            task_ptr->timer = 5;

            if (++Menu_Page > Page_Max) {
                Menu_Page = 0;
            }

            sub_0009C793();
            break;

        case 0x100:
            if (Menu_Cursor_Y[0] == Menu_Max) {
                switch (system_dir[1].contents[Menu_Page][Menu_Max]) {
                case 0:
                    task_ptr->r_no[2] = 1;
                    task_ptr->timer = 5;

                    if (--Menu_Page < 0) {
                        Menu_Page = (s8)Page_Max;
                    }

                    break;

                case 2:
                    task_ptr->r_no[2] = 1;
                    task_ptr->timer = 5;

                    if (++Menu_Page > Page_Max) {
                        Menu_Page = 0;
                    }

                    break;

                default:
                    task_ptr->r_no[2] += 1;
                    Menu_Suicide[0] = 0;
                    Menu_Suicide[1] = 0;
                    Menu_Suicide[2] = 1;
                    break;
                }

                sub_0009C793();
                break;
            }

            break;
        }

        break;

    default:
        Exit_Sub(task_ptr, 2, 5);
        break;
    }
}

/* Xbox: leaving the pause sets r_no[2] to 0 (PS2: 0x63). */
s32 Pause_1st_Sub(struct _TASK* task_ptr) {
    u16 sw = ~plsw_01[Pause_ID] & plsw_00[Pause_ID];

    if (Pause_Down) {
        SSPutStr2(17, 12, 9, "PRESS   BUTTON");
        dispButtonImage2(0xB2, 0x5B, 1, 0x13, 0xF, 0, 4);
        SSPutStr2(18, 14, 9, "TO PAUSE MENU");
    }

    if (sw & 0x4000) {
        if (((Mode_Type == 3) || (Mode_Type == 4)) && (Check_Pause_Term_Tr(Pause_ID ^ 1) != 0) &&
            plw[Pause_ID ^ 1].wu.operator && (Interface_Type[Pause_ID ^ 1] == 0)) {
            Pause_ID = Pause_ID ^ 1;
            return 0;
        }

        task_ptr->r_no[2] = 0;
        Exit_Menu = 1;
        sub_0009C793();
        return 1;
    }

    if (sw & 0x100) {
        task_ptr->r_no[2] += 1;
        Cursor_Y_Pos[0][0] = 0;
        sub_0009C793();
    }

    return 0;
}

/* Xbox-only helpers the select-game exit calls. */
void xb_DrawSystemMessage(s32 a, s32 x, s32 y, s32 w, s32 h, s32 c);
void xb_ResetDeviceOneBackBuffer(void);
void xb_LoadExitScreen(void);
void xb_ExitToSelectGame(s32 a);
void xb_LaunchDefaultXbe(void);

/* Xbox: the button image is xb_DrawSystemMessage, case 1 shows no message, the BGM
   fades out on 0x100, and the last two states shut down through Xbox code
   instead of jmpRebootProgram. */
void toSelectGame(struct _TASK* task_ptr) {
    u16 sw;

    switch (task_ptr->r_no[2]) {
    case 0:
        Forbid_Reset = 1;
        Menu_in_Sub(task_ptr);
        Setup_BG(1, 0x200, 0);
        effect_66_init(0x8A, 8, 1, 0, -1, -1, -0x7FF2);
        Order[0x8A] = 3;
        Order_Timer[0x8A] = 1;
        task_ptr->free[0] = 0;
        task_ptr->timer = 0x10;
        break;

    case 1:
        if (Menu_Sub_case1(task_ptr) != 0) {
            xb_DrawSystemMessage(0, 0x82, 0x8C, 0x16, 0x16, 0x20);
        }

        break;

    case 2:
        if (FadeIn(1, 0x19, 1) != 0) {
            task_ptr->r_no[2] += 1;
        }

        xb_DrawSystemMessage(0, 0x82, 0x8C, 0x16, 0x16, 0x20);
        break;

    case 3:
        xb_DrawSystemMessage(0, 0x82, 0x8C, 0x16, 0x16, 0x20);
        sw = (~plsw_01[0] & plsw_00[0]) | (~plsw_01[1] & plsw_00[1]);
        sw &= 0x300;

        if (sw != 0) {
            if (sw != 0x300) {
                if (sw & 0x100) {
                    SsBgmFadeOut(0xCCC);
                    task_ptr->free[0] = 1;
                }

                sub_0009C793();
                FadeInit();
                task_ptr->r_no[2] = 8;
                break;
            }
        }

        break;

    case 8:
        xb_DrawSystemMessage(0, 0x82, 0x8C, 0x16, 0x16, 0x20);

        if (FadeOut(1, 0x19, 1) != 0) {
            task_ptr->r_no[2] = task_ptr->free[0] ? 0xA : 9;
        }

        break;

    case 9:
        Menu_Suicide[0] = 0;
        Menu_Suicide[1] = 1;
        task_ptr->r_no[1] = 1;
        task_ptr->r_no[2] = 0;
        task_ptr->r_no[3] = 0;
        task_ptr->free[0] = 0;
        FadeOut(1, 0xFF, 1);
        Forbid_Reset = 0;
        break;

    case 10:
        FadeOut(1, 0xFF, 1);
        xb_ResetDeviceOneBackBuffer();
        xb_LoadExitScreen();
        task_ptr->r_no[2] += 1;
        break;

    default:
        xb_ExitToSelectGame(4);
        Exit_sound_system();
        xb_LaunchDefaultXbe();
        break;
    }
}

/* Xbox: the menu letter table has an extra entry (Xbox Live) at 6, so the
   label numbers from 7 up are one higher. */
void Training_Mode(struct _TASK* task_ptr) {
    s16 ix;
    s16 char_index;
    s16 PL_id;

    s16 unused_s4;
    s16 unused_s3;

    switch (task_ptr->r_no[2]) {
    case 0:
        Menu_in_Sub(task_ptr);
        mpp_w.initTrainingData = 1;
        effect_57_init(0x6F, 0xB, 0, 0x3F, 2);
        Order[0x6F] = 1;
        Order_Dir[0x6F] = 8;
        Order_Timer[0x6F] = 1;
        effect_04_init(1, 5, 0, 0x48);

        ix = 0;
        unused_s4 = char_index = 0x36;

        while (ix < 3) {
            effect_61_init(0, ix + 0x50, 0, 1, char_index, ix, 0x7047);
            Order[ix + 0x50] = 1;
            Order_Dir[ix + 0x50] = 4;
            Order_Timer[ix + 0x50] = ix + 0x14;
            ix++;
            unused_s3 = char_index++;
        }

        Menu_Cursor_Move = 3;
        system_dir[4] = system_dir[1];
        system_dir[5] = system_dir[1];
        break;

    case 1:
        Menu_Sub_case1(task_ptr);
        break;

    case 2:
        if (FadeIn(1, 0x19, 1) != 0) {
            task_ptr->r_no[2] += 1;
            Suicide[3] = 0;
        }

        break;

    case 3:
        PL_id = 0;

        if (MC_Move_Sub(Check_Menu_Lever(0, 0), 0, 2, 0xFF) == 0) {
            PL_id = 1;
            MC_Move_Sub(Check_Menu_Lever(1, 0), 0, 2, 0xFF);
        }

        switch (IO_Result) {
        case 0x100:
        case 0x200:
            break;

        default:
            return;
        }

        sub_0009C793();

        if (Menu_Cursor_Y[0] == 2 || IO_Result == 0x200) {
            Menu_Suicide[0] = 0;
            Menu_Suicide[1] = 1;
            task_ptr->r_no[1] = 1;
            task_ptr->r_no[2] = 0;
            task_ptr->r_no[3] = 0;
            task_ptr->free[0] = 0;
            Order[0x6F] = 4;
            Order_Timer[0x6F] = 4;
            break;
        }

        Decide_ID = PL_id;

        if (Menu_Cursor_Y[0] == 0) {
            Mode_Type = 3;
            Present_Mode = 4;
        } else {
            Mode_Type = 4;
            Present_Mode = 5;
        }

        Setup_VS_Mode(task_ptr);
        G_No[2] += 1;
        task_ptr->r_no[0] = 5;
        cpExitTask(SAVER_TASK_NUM);
        Champion = PL_id;
        Pause_ID = PL_id;
        Training_ID = PL_id;
        New_Challenger = PL_id ^ 1;
        cpExitTask(ENTRY_TASK_NUM);

        break;
    }
}
void Option_Select(struct _TASK* task_ptr) {
    s16 ix;
    s16 char_index;

    s16 unused_s5;
    s16 unused_s4;
    s16 unused_s3;
    s16 unused_s2;

    switch (task_ptr->r_no[2]) {
    case 0:
        Menu_in_Sub(task_ptr);
        Order[0x4E] = 2;
        Order_Dir[0x4E] = 0;
        Order_Timer[0x4E] = 1;
        effect_57_init(0x4F, 1, 0, 0x3F, 2);
        Order[0x4F] = 1;
        Order_Dir[0x4F] = 8;
        Order_Timer[0x4F] = 1;

        if (save_w[Present_Mode].Extra_Option == 0) {
            effect_04_init(1, 4, 0, 0x48);

            ix = 0;
            unused_s5 = char_index = 0x30;

            while (ix < 6) {
                effect_61_init(0, ix + 0x50, 0, 1, char_index, ix, 0x7047);
                Order[ix + 0x50] = 1;
                Order_Dir[ix + 0x50] = 4;
                Order_Timer[ix + 0x50] = ix + 0x14;
                ix++;
                unused_s4 = char_index++;
            }

            Menu_Cursor_Move = 6;
            break;
        }

        effect_04_init(1, 1, 0, 0x48);

        ix = 0;
        unused_s3 = char_index = 8;

        while (ix < 7) {
            effect_61_init(0, ix + 0x50, 0, 1, char_index, ix, 0x7047);
            Order[ix + 0x50] = 1;
            Order_Dir[ix + 0x50] = 4;
            Order_Timer[ix + 0x50] = ix + 0x14;
            ix++;
            unused_s2 = char_index++;
        }

        Menu_Cursor_Move = 7;
        break;

    case 1:
        if (Menu_Sub_case1(task_ptr) != 0) {
            checkSelObjFileLoaded();
        }

        break;

    case 2:
        if (FadeIn(1, 0x19, 1) != 0) {
            task_ptr->r_no[2] += 1;
            Suicide[3] = 0;
        }

        break;

    case 3:
        if (save_w[Present_Mode].Extra_Option) {
            ix = 1;
        } else {
            ix = 0;
        }

        if (MC_Move_Sub(Check_Menu_Lever(0, 0), 0, ix + 5, 0xFF) == 0) {
            MC_Move_Sub(Check_Menu_Lever(1, 0), 0, ix + 5, 0xFF);
        }

        switch (IO_Result) {
        case 0x100:
        case 0x200:
            break;

        default:
            return;
        }

        sub_0009C793();

        if (Menu_Cursor_Y[0] == ix + 5 || IO_Result == 0x200) {
            Menu_Suicide[0] = 0;
            Menu_Suicide[1] = 1;
            task_ptr->r_no[1] = 1;
            task_ptr->r_no[2] = 0;
            task_ptr->r_no[3] = 0;
            task_ptr->free[0] = 0;
            Order[0x4F] = 4;
            Order_Timer[0x4F] = 4;

            if (Check_Change_Contents()) {
                if (save_w[Present_Mode].Auto_Save) {
                    task_ptr->r_no[0] = 4;
                    task_ptr->r_no[1] = 0;
                    Forbid_Reset = 1;
                    Copy_Check_w();
                    break;
                }
            }

            break;
        }

        task_ptr->r_no[2] += 1;
        task_ptr->free[0] = 0;
        X_Adjust_Buff[0] = X_Adjust;
        X_Adjust_Buff[1] = X_Adjust;
        X_Adjust_Buff[2] = X_Adjust;
        Y_Adjust_Buff[0] = Y_Adjust;
        Y_Adjust_Buff[1] = Y_Adjust;
        Y_Adjust_Buff[2] = Y_Adjust;
        Correct_X[1] = Correct_X[0];
        Correct_X[2] = Correct_X[0];
        Correct_X[3] = Correct_X[0];
        Correct_Y[1] = Correct_Y[0];
        Correct_Y[2] = Correct_Y[0];
        Correct_Y[3] = Correct_Y[0];
        break;

    default:
        Exit_Sub(task_ptr, 1, Menu_Cursor_Y[0] + 9);
        break;
    }
}
void System_Direction(struct _TASK* task_ptr) {
    s16 ix;
    s16 char_index;

    s16 unused_s3;
    s16 unused_s2;

    switch (task_ptr->r_no[2]) {
    case 0:
        Menu_in_Sub(task_ptr);
        Order[0x4E] = 2;
        Order_Dir[0x4E] = 3;
        Order_Timer[0x4E] = 1;
        effect_57_init(0x6D, 0xA, 0, 0x3F, 2);
        Order[0x6D] = 1;
        Order_Dir[0x6D] = 8;
        Order_Timer[0x6D] = 1;
        effect_04_init(1, 3, 0, 0x48);
        Convert_Buff[3][0][0] = Direction_Working[1];
        effect_64_init(0x61U, 0, 1, 0xA, 0, 0x7047, 0xB, 3, 0);
        Order[0x61] = 1;
        Order_Dir[0x61] = 4;
        Order_Timer[0x61] = 0x14;

        ix = 0;
        unused_s3 = char_index = 0x2C;

        while (ix < 4) {
            effect_61_init(0, ix + 0x50, 0, 1, char_index, ix + 1, 0x7047);
            Order[ix + 0x50] = 1;
            Order_Dir[ix + 0x50] = 4;
            Order_Timer[ix + 0x50] = ix + 0x15;
            ix++;
            unused_s2 = char_index++;
        }

        Menu_Cursor_Move = 4;
        Page_Max = Check_SysDir_Page();
        break;

    case 1:
        Menu_Sub_case1(task_ptr);
        break;

    case 2:
        if (FadeIn(1, 0x19, 1) != 0) {
            task_ptr->r_no[2] += 1;
            Suicide[3] = 0;
        }

        break;

    case 3:
        System_Dir_Move_Sub(0);

        if (IO_Result == 0) {
            System_Dir_Move_Sub(1);
        }

        switch (IO_Result) {
        case 0x100:
            if (Menu_Cursor_Y[0] == 0) {
                break;
            }

            // fallthrough

        case 0x200:
            sub_0009C793();
            Order[0x6D] = 4;
            Order_Timer[0x6D] = 4;

            if (Menu_Cursor_Y[0] == 4 || IO_Result == 0x200) {
                Menu_Suicide[0] = 0;
                Menu_Suicide[1] = 1;
                task_ptr->r_no[1] = 1;
                task_ptr->r_no[2] = 0;
                task_ptr->r_no[3] = 0;
                task_ptr->free[0] = 0;
                break;
            }

            task_ptr->r_no[2] += 1;
            task_ptr->free[0] = 0;

            break;
        }

        break;

    default:
        Exit_Sub(task_ptr, 1, Menu_Cursor_Y[0] + 0x11);
        break;
    }
}
void Game_Option(struct _TASK* task_ptr) {
    s16 char_index;
    s16 ix;

    s16 unused_s3;
    s16 unused_s2;

    switch (task_ptr->r_no[2]) {
    case 0:
        FadeOut(1, 0xFF, 1);
        task_ptr->r_no[2] += 1;
        task_ptr->timer = 5;
        Menu_Common_Init();
        Menu_Cursor_Y[0] = 0;
        Menu_Suicide[1] = 1;
        Menu_Suicide[2] = 0;
        Menu_Cursor_Y[0] = 0;
        Menu_Cursor_Y[1] = 0;
        Order[0x4F] = 4;
        Order_Timer[0x4F] = 1;
        Order[0x4E] = 2;
        Order_Dir[0x4E] = 2;
        Order_Timer[0x4E] = 1;
        effect_57_init(0x6A, 7, 0, 0x3F, 2);
        Order[0x6A] = 1;
        Order_Dir[0x6A] = 8;
        Order_Timer[0x6A] = 1;

        for (ix = 0, unused_s3 = char_index = 0x1A; ix < 0xC; ix++, unused_s2 = char_index++) {
            effect_61_init(0, ix + 0x50, 0, 2, char_index, ix, 0x70A7);
            Order[ix + 0x50] = 1;
            Order_Dir[ix + 0x50] = 4;
            Order_Timer[ix + 0x50] = ix + 0x14;
        }

        Menu_Cursor_Move = 0xA;

        for (ix = 0; ix < 0xA; ix++) {
            effect_64_init(ix + 0x5D, 0, 2, Setup_Index_64[ix], ix, 0x70A7, ix + 1, 0, 0);
            Order[ix + 0x5D] = 1;
            Order_Dir[ix + 0x5D] = 4;
            Order_Timer[ix + 0x5D] = ix + 0x14;
        }

        break;

    case 1:
        Menu_Sub_case1(task_ptr);
        break;

    case 2:
        if (FadeIn(1, 0x19, 1) != 0) {
            task_ptr->r_no[2] += 1;
            Suicide[3] = 0;
        }

        break;

    case 3:
        Game_Option_Sub(0);
        Button_Exit_Check(task_ptr, 0);
        Game_Option_Sub(1);
        Button_Exit_Check(task_ptr, 1);
        Save_Game_Data();
        break;

    default:
        Exit_Sub(task_ptr, 2, 5);
        break;
    }
}

/* Xbox: the position is applied times 4, the labels start at 0xF (PS2:
   0xE), and each frame the settings are copied to Convert_Buff and to
   save_w[1] before saving. */
void Screen_Adjust(struct _TASK* task_ptr) {
    s16 char_index;
    s16 ix;

    s16 unused_s3;
    s16 unused_s2;

    X_Adjust = X_Adjust_Buff[0];
    X_Adjust_Buff[0] = X_Adjust_Buff[1];
    X_Adjust_Buff[1] = X_Adjust_Buff[2] * 4;
    Y_Adjust = Y_Adjust_Buff[0];
    Y_Adjust_Buff[0] = Y_Adjust_Buff[1];
    Y_Adjust_Buff[1] = Y_Adjust_Buff[2] * 4;
    Correct_X[0] = Correct_X[1];
    Correct_X[1] = Correct_X[2];
    Correct_X[2] = Correct_X[3];
    Correct_Y[0] = Correct_Y[1];
    Correct_Y[1] = Correct_Y[2];
    Correct_Y[2] = Correct_Y[3];

    switch (task_ptr->r_no[2]) {
    case 0:
        FadeOut(1, 0xFF, 1);
        task_ptr->r_no[2] += 1;
        task_ptr->timer = 5;
        Menu_Common_Init();
        Menu_Cursor_Y[0] = 0;
        Menu_Suicide[1] = 1;
        Menu_Suicide[2] = 0;
        Order[0x4F] = 4;
        Order_Timer[0x4F] = 1;
        Order[0x4E] = 2;
        Order_Dir[0x4E] = 2;
        Order_Timer[0x4E] = 1;
        effect_57_init(0x65, 3, 0, 0x3F, 2);
        Order[0x65] = 1;
        Order_Dir[0x65] = 8;
        Order_Timer[0x65] = 1;

        for (ix = 0; ix < 5; ix++) {
            effect_63_init(ix + 0x66, 0, 2, ix, ix);
            Order[ix + 0x66] = 1;
            Order_Dir[ix + 0x66] = 4;
            Order_Timer[ix + 0x66] = ix + 0x14;
        }

        for (ix = 0, unused_s3 = char_index = 0xF; ix < 7; ix++, unused_s2 = char_index++) {
            effect_61_init(0, ix + 0x50, 0, 2, char_index, ix, 0x7047);
            Order[ix + 0x50] = 1;
            Order_Dir[ix + 0x50] = 4;
            Order_Timer[ix + 0x50] = ix + 0x14;
        }

        Menu_Cursor_Move = 5;
        break;

    case 1:
        Menu_Sub_case1(task_ptr);
        break;

    case 2:
        if (FadeIn(1, 0x19, 1) != 0) {
            task_ptr->r_no[2] += 1;
            Suicide[3] = 0;
        }

        break;

    case 3:
        Screen_Adjust_Sub(0);
        Screen_Exit_Check(task_ptr, 0);

        if (IO_Result == 0) {
            Screen_Adjust_Sub(1);
            Screen_Exit_Check(task_ptr, 0);
        }

        Convert_Buff[0][0][0] = X_Adjust_Buff[2];
        Convert_Buff[0][0][1] = Y_Adjust_Buff[2];
        Convert_Buff[0][0][2] = save_w[1].Screen_Size = dspwhPack(Disp_Size_H, Disp_Size_V);
        Convert_Buff[0][0][3] = save_w[1].Screen_Mode = sys_w.screen_mode;
        Save_Game_Data();
        break;
    }
}

/* Xbox rewrite of dispControllerWasRemovedMessage: Country-dependent text
   and the port number, so it takes the player as a fourth argument. */
void xb_DrawReconnectMessage(s32 x, s32 y, s32 step, s32 pl_id);

/* Xbox: the removed-controller message is xb_DrawReconnectMessage, 12 pixels higher
   (y 70, PS2 82), for the pausing player. */
void Wait_Pause_in_Tr(struct _TASK* task_ptr) {
    u16 ans;
    u16 ix;

    Training_Data_Disp();
    Control_Player_Tr();

    if (End_Training) {
        Next_Be_Tr_Menu(task_ptr);
        return;
    }

    switch (task_ptr->r_no[1]) {
    case 0:
        if (Allow_a_battle_f) {
            task_ptr->r_no[1]++;

            if (Present_Mode == 4) {
                Disp_Attack_Data = Training->contents[0][1][1];
            } else {
                Disp_Attack_Data = 0;
            }
        } else {
            Disp_Attack_Data = 0;
        }

        /* fallthrough */

    case 1:
        if (Allow_a_battle_f == 0 || Extra_Break != 0) {
            return;
        }

        ans = 0;

        if (Check_Pause_Term_Tr(0)) {
            ans = Pause_Check_Tr(0);
        }

        if (ans == 0 && Check_Pause_Term_Tr(1)) {
            ans = Pause_Check_Tr(1);
        }

        switch (ans) {
        case 1:
            Setup_Tr_Pause(task_ptr);
            break;

        case 2:
            Setup_Tr_Pause(task_ptr);
            task_ptr->r_no[1] = 3;
            break;
        }

        break;

    case 2:
        if (Interface_Type[Pause_ID] == 0) {
            Setup_Tr_Pause(task_ptr);
            task_ptr->r_no[1] = 3;
            break;
        }

        if (Pause_Down) {
            Flash_1P_or_2P(task_ptr);
        }

        switch (Pause_in_Normal_Tr(task_ptr)) {
        case 1:
            task_ptr->r_no[1] = 0;
            sub_0009C793();
            Game_pause = 0;
            Pause = 0;
            Pause_Down = 0;
            Disp_Attack_Data = Training->contents[0][1][1];

            for (ix = 0; ix < 4; ix++) {
                Menu_Suicide[ix] = 1;
            }

            pulpul_request_again();
            SsBgmHalfVolume(0);
            break;

        case 2:
            Next_Be_Tr_Menu(task_ptr);
            break;
        }

        break;

    case 3:
        if (Interface_Type[Pause_ID] == 0) {
            xb_DrawReconnectMessage(132, 70, 16, Pause_ID);
            break;
        }

        Setup_Tr_Pause(task_ptr);
        break;
    }
}

/* Xbox: rows 3 and 7 are not drawn (the Xbox pad has no such buttons), so the
   list starts 2 lower and the header sits at y + 18 (PS2: y + 20). */
void Setup_Button_Sub(s16 x, s16 y, s16 master_player) {
    s16 ix;

    y += 2;
    effect_10_init(0, 7, 99, 0, master_player, x + 7, y + 16);
    effect_10_init(0, 7, 99, 1, master_player, x + 29, y + 16);

    for (ix = 0; ix < 8; ix++, y += 2) {
        if (ix == 3 || ix == 7) {
            y -= 2;
            continue;
        }

        effect_10_init(0, 5, ix, ix, master_player, x, y);
        effect_10_init(1, 5, ix, ix, master_player, x + 22, y);
        effect_10_init(0, 2, ix, Convert_Buff[1][0][ix], master_player, x + 3, y);
        effect_10_init(1, 2, ix, Convert_Buff[1][1][ix], master_player, x + 25, y);
    }

    effect_10_init(0, 3, 8, Convert_Buff[1][0][8], master_player, x, y);
    effect_10_init(1, 3, 8, Convert_Buff[1][1][8], master_player, x + 22, y);
    effect_10_init(0, 4, 9, 0, master_player, x, y + 2);
    effect_10_init(1, 4, 9, 0, master_player, x + 22, y + 2);
    effect_10_init(0, 0, 10, 2, master_player, x, y + 4);
    effect_10_init(1, 0, 10, 2, master_player, x + 22, y + 4);
}

/* Xbox: the page-change results are 0x400 (left) and 0x40 (right). */
void Ex_Move_Sub_LR(u16 sw, s16 PL_id) {
    u8 last_pos = save_w[Present_Mode].extra_option.contents[Menu_Page][Menu_Cursor_Y[0]];

    switch (sw) {
    case 4:
        if (Menu_Page_Buff != 0 || Menu_Cursor_Y[0] != 4) {
            SE_dir_cursor_move();
        }

        save_w[1].extra_option.contents[Menu_Page_Buff][Menu_Cursor_Y[0]]--;

        if (Menu_Cursor_Y[0] == Menu_Max) {
            if (save_w[1].extra_option.contents[Menu_Page_Buff][Menu_Cursor_Y[0]] < 0) {
                save_w[1].extra_option.contents[Menu_Page_Buff][Menu_Cursor_Y[0]] = 0;
                IO_Result = 0x400; /* Xbox: PS2 0x80 */
                break;
            }

            if (save_w[1].extra_option.contents[Menu_Page_Buff][Menu_Cursor_Y[0]] != last_pos) {
                Message_Data->order = 1;
                Message_Data->request = save_w[1].extra_option.contents[Menu_Page_Buff][Menu_Max] + 32;
                Message_Data->timer = 2;
            }
        } else if (save_w[1].extra_option.contents[Menu_Page_Buff][Menu_Cursor_Y[0]] < 0) {
            save_w[1].extra_option.contents[Menu_Page_Buff][Menu_Cursor_Y[0]] =
                Ex_Menu_Max_Data[Menu_Page][Menu_Cursor_Y[0]];
        }

        return;

    case 8:
        if (Menu_Page_Buff != 0 || Menu_Cursor_Y[0] != 4) {
            SE_dir_cursor_move();
        }

        save_w[1].extra_option.contents[Menu_Page_Buff][Menu_Cursor_Y[0]]++;

        if (Menu_Cursor_Y[0] == Menu_Max) {
            if (save_w[1].extra_option.contents[Menu_Page_Buff][Menu_Cursor_Y[0]] > 2) {
                save_w[1].extra_option.contents[Menu_Page_Buff][Menu_Cursor_Y[0]] = 2;
                IO_Result = 0x40; /* Xbox: PS2 0x400 */
                return;
            }

            if (save_w[1].extra_option.contents[Menu_Page_Buff][Menu_Cursor_Y[0]] > 2) {
                save_w[1].extra_option.contents[Menu_Page_Buff][Menu_Cursor_Y[0]] = 2;
            }

            if (save_w[1].extra_option.contents[Menu_Page_Buff][Menu_Cursor_Y[0]] != last_pos) {
                Message_Data->order = 1;
                Message_Data->request = save_w[1].extra_option.contents[Menu_Page_Buff][Menu_Max] + 32;
                Message_Data->timer = 2;
            }
        } else if (save_w[1].extra_option.contents[Menu_Page_Buff][Menu_Cursor_Y[0]] >
                   Ex_Menu_Max_Data[Menu_Page][Menu_Cursor_Y[0]]) {
            save_w[1].extra_option.contents[Menu_Page_Buff][Menu_Cursor_Y[0]] = 0;
        }

        return;

    case 0x400:
        if (Interface_Type[PL_id] == 2) {
            break;
        }

    case 0x100:
        if (Menu_Page_Buff != 0 || Menu_Cursor_Y[0] != 4) {
            SE_dir_cursor_move();
        }

        if (Menu_Cursor_Y[0] == Menu_Max) {
            break;
        }

        save_w[1].extra_option.contents[Menu_Page_Buff][Menu_Cursor_Y[0]]++;

        if (save_w[1].extra_option.contents[Menu_Page_Buff][Menu_Cursor_Y[0]] >
            Ex_Menu_Max_Data[Menu_Page][Menu_Cursor_Y[0]]) {
            save_w[1].extra_option.contents[Menu_Page_Buff][Menu_Cursor_Y[0]] = 0;
        }

        return;
    }
}

/* Xbox: the player comes from D_007AA5EF; the PS2 choice is only a
   fallback when that is -1 (never, for a u8). */
void Load_Replay(struct _TASK* task_ptr) {
    Menu_Cursor_X[1] = Menu_Cursor_X[0];
    Clear_Flash_Sub();

    switch (task_ptr->r_no[2]) {
    case 0:
        Menu_in_Sub(task_ptr);
        Menu_Cursor_X[0] = 0;
        Setup_BG(1, 0x200, 0);
        Setup_Replay_Sub(1, 0x6E, 9, 1);
        Clear_Flash_Init(4);
        Message_Data->kind_req = 5;
        break;

    case 1:
        if (Menu_Sub_case1(task_ptr) != 0) {
            SaveInit(2, 0);
        }

        break;

    case 2:
        if (FadeIn(1, 0x19, 1) != 0) {
            task_ptr->r_no[2] += 1;
            task_ptr->free[3] = 0;
            Menu_Cursor_X[0] = Setup_Final_Cursor_Pos(0, 8);
        }

        break;

    case 3:
        switch (SaveMove()) {
        case 0:
            Decide_ID = D_007AA5EF;

            if (Decide_ID == -1) {
                Decide_ID = 0;

                if (Interface_Type[0] == 0) {
                    Decide_ID = 1;
                }
            }

            task_ptr->r_no[2] += 1;
            task_ptr->r_no[3] = 0;
            break;

        case -1:
            IO_Result = 0x200;
            Load_Replay_MC_Sub(task_ptr, 0);
            break;
        }

        break;

    case 4:
        Load_Replay_Sub(task_ptr);
        break;
    }
}

/* Xbox: sets D_007AA5EC after each menu step. */
void After_Title(struct _TASK* task_ptr) {
    void (*AT_Jmp_Tbl[21])() = { Menu_Init,        Mode_Select,   Option_Select, Option_Select,  Training_Mode,
                                 System_Direction, Load_Replay,   Option_Select, toSelectGame,   Game_Option,
                                 Button_Config,    Screen_Adjust, Sound_Test,    Memory_Card,    Extra_Option,
                                 Option_Select,    VS_Result,     Save_Replay,   Direction_Menu, Save_Direction,
                                 Load_Direction };

    AT_Jmp_Tbl[task_ptr->r_no[1]](task_ptr);
    D_007AA5EC = 1;
}

/* Xbox: also calls Setup_BG_General after bg_etc_write_ex. */
void Menu_Init(struct _TASK* task_ptr) {
    s16 ix;
    s16 fade_on;

    if (Pause_Type == 2) {
        task_ptr->r_no[1] = 4;
    } else {
        task_ptr->r_no[1] = 1;
    }

    task_ptr->r_no[2] = 0;
    task_ptr->r_no[3] = 0;
    Menu_Cursor_Y[0] = 0;
    Menu_Cursor_Y[1] = 0;

    for (ix = 0; ix < 4; ix++) {
        Menu_Suicide[ix] = 0;
        Unsubstantial_BG[ix] = 0;
        Cursor_Y_Pos[0][ix] = 0;
    }

    All_Clear_Suicide();
    pulpul_stop();

    if (task_ptr->r_no[0] == 0) {
        FadeOut(1, 0xFF, 1);
        bg_etc_write_ex(2);
        Setup_BG_General();
        Setup_Virtual_BG(0, 0x200, 0);
        Setup_BG(1, 0x200, 0);
        Setup_BG(2, 0x200, 0);
        base_y_pos = 0;

        if (task_ptr->r_no[1] != 0x12) {
            fade_on = 0;
        } else {
            fade_on = 1;
        }

        Order[0x4E] = 5;
        Order_Timer[0x4E] = 1;
        effect_57_init(0x4E, 0, 0, 0x45, fade_on);
        load_any_texture_patnum(0x7F30, 0xC, 0);
        sub_0004384A(0);
    }

    cpReadyTask(SAVER_TASK_NUM, Saver_Task);
}
