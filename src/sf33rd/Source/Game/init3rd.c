/* init3rd.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * Init_Task_Aload 0xC7A72 size 0x2C. Read against the x86: Xbox drops the save
 * autoload here: the x86 has no SaveInit(0, 2) or SaveMove() and moves on at
 * once; Game0_0 and Game0_1 call SaveInit and SaveMove instead.
 * mpp_w.cutAnalogStickData is the byte at 0x7AA5F3. The C is changed to match.
 * Init_Task_2nd 0xC7A9E size 0x2E.
 * Init_Task_Test1 0xC7ACC size 0xFB. Read against the x86: 0xFE is a step of
 * the switch compare chain. The C is the PS2 C.
 * Init_Task_Test2 0xC7BC7 size 0x55.
 * Init_Task_End 0xC7C1C size 0x3C.
 * Init_Task_1st 0xC7C58 size 0x1E9. Read against the x86: the struct copies
 * are inlined (rep movsd), 0x208 is the save_w stride, 0xFF the save_w[4] and
 * [5] Time_Limit = -1 stores, and 0xC7A4B is Setup_Difficult_V. The save_w
 * copy uses the memcpy form. The C is the PS2 C.
 * Not located in sf33rd.xbe; their PS2 C is kept under #if 0: Init_Task,
 * Setup_Difficult_V.
 * CP3toPS2DrawOff has no XBE name and no aligned call.
 * Game_Data_Init has no XBE name and no aligned call.
 * SE_selected is folded into 0x9C793.
 * Setup_Difficult_V has no XBE name and no aligned call.
 * Data: Keep_Zoom_X 0x7AABE4.
 * Data: Test_Cursor 0x7AABE0.
 * Data: Difficult_V_Data is 0x289770, 0x4 bytes compared.
 * Data: Permission_PL_Data is 0x289774, 0x18 bytes compared.
 * Globals: Dir_Default_Data 0x2499D0, Permission_PL_Data 0x289774,
 * Present_Mode 0x7A819C, Request_Break 0x7A81B0, Max_vitality 0x7A81F8, G_No
 * 0x7A825C, Direction_Working 0x7A82D8, Disp_Attack_Data 0x7A82F8, Demo_Flag
 * 0x7A842D, Random_ix16 0x7A8470, Unsubstantial_BG 0x7A851C, Pause_Down
 * 0x7A8590, Replay_Status 0x7A86C8, DE_X 0x7A86D8, Forbid_Reset 0x7A8778,
 * Break_Into 0x7A8802, Forbid_Break 0x7A8804, test_flag 0x7A8902, Random_ix32
 * 0x7A891E, Extra_Break 0x7A89A0, S_No 0x7A89C8, Vital_Handicap 0x7A89E0,
 * Play_Game 0x7A89EC, E_No 0x7A89F8, mpp_w 0x7AA5C0, Test_Cursor 0x7AABE0,
 * Keep_Zoom_X 0x7AABE4, seraph_flag 0x7BC4F4, No_Trans 0x7BD3C9, p1sw_1
 * 0x7BD3CA, save_w 0x7BD3E0, Screen_PAL 0x7C557A, p1sw_0 0x7C557C, Turbo
 * 0x7C56A8, permission_player 0x7C5860, Turbo_Timer 0x7C5980, system_dir
 * 0x7C59E0, Screen_Zoom_X 0x7C5C20, Reset_Status 0xC7C838.
 */

#include "structs.h"

#define RESET_TASK_NUM 2
#define GAME_TASK_NUM 5
#define ENTRY_TASK_NUM 1
#define DEBUG_TASK_NUM 9

void sub_0009C793();
void init_texcash_1st();
void Init_texgrplds_work();
void Init_load_on_memory_data();
void Pause_Family_On();
void Bg_TexInit();
void Scrscreen_Init();
void effect_work_init();
extern u8 Usage;
extern s16 Max_vitality;
extern u8 reset_NG_flag;
extern s8 Break_Into;
extern s8 Forbid_Break;
extern u8 Extra_Break;
extern s8 Demo_Flag;
extern s16 Random_ix16;
extern s16 Random_ix32;
extern u8 test_flag;
extern u8 ixbfw_cut;
extern s8 PB_Music_Off;
extern s8 No_Death;
extern u8 Pause_Down;
extern u8 Disp_Attack_Data;
extern s8 seraph_flag;
extern s8 Request_Break[2];
extern s16 DE_X[2];
extern u8 No_Trans;
extern u8 Replay_Status[2];
extern u8 Play_Game;
extern u8 Present_Mode;
extern u8 G_No[4];
extern u8 E_No[4];
extern u8 S_No[4];
extern u8 Unsubstantial_BG[4];
void init_pulpul_work();
void Init_Load_Request_Queue_1st();
void Game_Data_Init();
extern SystemDir system_dir[6];
extern const SystemDir Dir_Default_Data;
extern Permission permission_player[6];
extern void* memcpy(void* dest, const void* src, size_t n);
extern struct _SAVE_W save_w[6];
extern u8 Direction_Working[6];
extern s8 Vital_Handicap[6][2];
void Copy_Check_w();
void Setup_Difficult_V();
void Setup_Limit_Time();
extern f32 Screen_Zoom_X;
extern u8 Reset_Bootrom;
void cpReadyTask(u16 num, void* func_adrs);
void Reset_Task(struct _TASK* task_ptr);
extern s8 Switch_Type;
extern u8 Reset_Status[2];
void pulpul_stop();
void Warning_Init();
void CP3toPS2DrawOff();
extern MPP mpp_w;
extern u8 Forbid_Reset;
s32 Warning();
void Setup_Disp_Size(s16 );
void CP3toPS2DrawOn();
extern u16 p1sw_1;
extern u16 p1sw_0;
void SE_cursor_move();
extern u8 Turbo;
extern u8 Screen_PAL;
extern u8 Turbo_Timer;
void Pal_Cursor_Put(s16 type);
void Put_Warning(s16 type);
void Game_Task(struct _TASK* task_ptr);
void Entry_Task(struct _TASK*);
void Debug_Task(struct _TASK* task_ptr);
void cpExitTask(u16 num);

extern f32 Keep_Zoom_X;

extern s8 Test_Cursor;

const u8 Difficult_V_Data[2][2] = { { 0, 0 }, { 1, 2 } };

const Permission Permission_PL_Data = { { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
                                        { { 0, 0 }, { 0, 0 } } };

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
    CP3toPS2DrawOff();
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

void Init_Task_2nd(struct _TASK* task_ptr) {
    if (Warning() == 0) {
        return;
    }

    task_ptr->r_no[0] += 1;
    Setup_Disp_Size(0);
    Screen_Zoom_X = Keep_Zoom_X;
    CP3toPS2DrawOn();
}

void Init_Task_Test1(struct _TASK* task_ptr) {
    u16 sw;

    switch (task_ptr->r_no[1]) {
    case 0:
        task_ptr->r_no[1] += 1;
        task_ptr->timer = 1800;
        Test_Cursor = 1;
        /* fallthrough */

    case 1:
        sw = ~p1sw_1 & p1sw_0;

        if (--task_ptr->timer <= 0) {
            sw = 0x100;
            Test_Cursor = 1;
        }

        switch (sw) {
        case 1:
            Test_Cursor -= 1;

            if (Test_Cursor < 0) {
                Test_Cursor = 0;
            } else {
                SE_cursor_move();
            }

            break;

        case 2:
            Test_Cursor += 1;

            if (Test_Cursor > 2) {
                Test_Cursor = 2;
            } else {
                SE_cursor_move();
            }

            break;

        case 0x100:
            if (Test_Cursor == 0) {
                task_ptr->r_no[0] = 4;
                task_ptr->r_no[1] = 0;
            } else {
                task_ptr->r_no[1] += 1;
            }

            sub_0009C793();
            break;
        }

        break;

    case 2:
        if (Test_Cursor == 2) {
            Turbo = 0;
            Screen_PAL = 0;
            Warning_Init();
        } else {
            Turbo = 5;
            Turbo_Timer = 1;
            Screen_PAL = 8;
            Warning_Init();
        }

        task_ptr->r_no[0] = 1;
        return;
    }

    Pal_Cursor_Put(Test_Cursor);
    Put_Warning(2);
}

void Init_Task_Test2(struct _TASK* task_ptr) {
    switch (task_ptr->r_no[1]) {
    case 0:
        task_ptr->r_no[1] += 1;
        task_ptr->timer = 300;
        Turbo = 0;
        Screen_PAL = 0;
        Warning_Init();
        return;

    case 1:
        if (--task_ptr->timer <= 0) {
            task_ptr->r_no[0] = 3;
            task_ptr->r_no[1] = 0;
            Screen_PAL = 8;
            Warning_Init();
            return;
        }

    default:
        Put_Warning(3);
        return;
    }
}

void Init_Task_End(struct _TASK* task_ptr) {
    cpReadyTask(GAME_TASK_NUM, Game_Task);
    task_ptr->r_no[0] += 1;
    task_ptr->r_no[1] = 0;
    G_No[0] = 1;
    cpReadyTask(ENTRY_TASK_NUM, Entry_Task);

    if (Usage == 7) {
        cpReadyTask(DEBUG_TASK_NUM, Debug_Task);
    }

    cpExitTask(0);
    Forbid_Reset = 0;
}

#if 0
/* PS2 C for functions not located in sf33rd.xbe yet. */

void Init_Task(struct _TASK* task_ptr) {
    void (*Main_Jmp_Tbl[6])() = { Init_Task_1st, Init_Task_Aload, Init_Task_2nd,
                                  Init_Task_End, Init_Task_Test1, Init_Task_Test2 };

    Main_Jmp_Tbl[task_ptr->r_no[0]](task_ptr);
}

void Setup_Difficult_V() {
    u8 country;

    if (Country == 1) {
        country = 0;
    } else {
        country = 1;
    }

    CC_Value[0] = Difficult_V_Data[country][0];
    CC_Value[1] = Difficult_V_Data[country][1];
}
#endif
