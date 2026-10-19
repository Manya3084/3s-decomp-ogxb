/* Attract-mode demo, retail sf33rd.xbe.
 * Demo00 is 0x31608 size 0x1ED, interior after the ret.
 * Setup_Demo_PL is 0x317F5 size 0x25, interior after the ret.
 * Setup_Demo_Arts is 0x3181A size 0x35, interior after the jmp.
 * Setup_Demo_Stage is 0x3184F size 0x48, interior after the ret.
 * Setup_Select_Demo_PL is 0x31897 size 0x3B, interior after the ret.
 * Demo01 is 0x318D2 size 0x1BF, interior after the ret.
 * Play_Demo is 0x31A91 size 0x2C, interior after the jmp.
 * D_No[0] is 0x7A8200. Play_Game is 0x7A89EC. Next_Demo is the dword at 0x7A8300.
 * Cover_Timer is 0x7A81F4. D_Timer is 0x7A892E. G_No[2] is 0x7A825E.
 * Game_pause is 0x7A89B0. Conclusion_Flag is 0x7A88D4.
 * appear_type is the word at 0xC7D8E8. Control_Time is 0x7A81EE.
 * Round_Level is the word at 0x7A876A. Weak_PL is 0x7A8414.
 * Disappear_LOGO is 0x7A8429. Stop_SG is 0x7A8428. Stop_Combo is 0x7A82FC.
 * Demo_Flag is 0x7A842D. Present_Mode is 0x7A819C.
 * Select_Demo_Index is 0x7A82FE. Demo_Time_Stop is 0x7A8A32.
 * Demo_PL_Index is 0x7A813A. Demo_Stage_Index is 0x7A8516.
 * My_char[0] is 0x7A8114. Super_Arts is 0x7A89FE. Player_Color is 0x7A8906.
 * bg_w.stage is 0x7BC523 and bg_w.area is 0x7BC524.
 * Operator_Status is 0x7A816A. plw is 0xC7CEA0, stride 0x46C.
 * Demo_PL_Play_Data is 0x24992C. Arts_Rnd_Demo_Data is 0x249934.
 * Demo_Stage_Play_Data is 0x24993C. Demo_PL_Data is 0x249944.
 * Each row matches the PlayStation 2 bytes.
 * Demo00 does not test Debug_w[0x18]. Setup_Demo_PL does not test
 * Debug_w[0x1D] or Debug_w[0x1E]. The caller of Switch_Screen_Init
 * pushes 0. That function reads no argument.
 * 0x61C7F, 0x61CAB, 0x5BEC3, 0x5B3ED, 0x5B0EA, 0x5CD95, and 0x9326B are
 * Purge_texcash_of_list, Make_texcash_of_list, Game02, Game01,
 * Before_Select_Sub, grade_check_work_1st_init, and random_16.
 */

#include "types.h"
#include "structs.h"




#if defined(__i386__)
_Static_assert(__builtin_offsetof(WORK, operator) == 3, "operator");
_Static_assert(sizeof(PLW) == 0x46C, "PLW");
_Static_assert(__builtin_offsetof(BG, stage) == 3, "stage");
_Static_assert(__builtin_offsetof(BG, area) == 4, "area");
#endif

extern u8 D_No[4];
extern u8 Play_Game;
extern s32 Next_Demo;
extern s8 Cover_Timer;
extern s16 D_Timer;
extern u8 G_No[4];
extern u8 Game_pause;
extern u8 Conclusion_Flag;
extern s16 appear_type;
extern s16 Control_Time;
extern s16 Round_Level;
extern u8 Weak_PL;
extern u8 Disappear_LOGO;
extern s8 Stop_SG;
extern s8 Stop_Combo;
extern s8 Demo_Flag;
extern u8 Present_Mode;
extern s8 Select_Demo_Index;
extern s8 Demo_Time_Stop;
extern s8 Demo_PL_Index;
extern s8 Demo_Stage_Index;
extern u8 My_char[2];
extern s8 Super_Arts[2];
extern s8 Player_Color[2];
extern BG bg_w;
extern s8 Operator_Status[2];
extern PLW plw[2];
/* Tables pasted from the PS2 file; analysis-ps2map/portdata.py found
   each equal to retail. */
const s8 Demo_PL_Play_Data[4][2] = { { 15, 19 }, { 11, 18 }, { 2, 16 }, { 12, 8 } };

const u8 Arts_Rnd_Demo_Data[8] = { 0, 0, 0, 1, 1, 1, 2, 2 };

const s8 Demo_Stage_Play_Data[4][2] = { { 15, 19 }, { 11, 18 }, { 2, 16 }, { 12, 8 } };

const s8 Demo_PL_Data[4] = { 0, 1, 0, 1 };


extern void Purge_texcash_of_list(s16 ix);
extern void Make_texcash_of_list(s16 ix);
extern void Game02(void);
extern void Game01(void);
extern void Before_Select_Sub(void);
extern void grade_check_work_1st_init(s16 ix, s16 ix2);
extern s32 random_16(void);
extern void init_omop(void);
extern s32 Switch_Screen(u8 wipe_type);
extern void Switch_Screen_Init(void);
extern s32 Switch_Screen_Revival(u8 wipe_type);
extern void SsBgmFadeOut(u16 time);
extern void BGM_Stop(void);
extern void Clear_Break_Com(s16 pl_id);

void Demo00(void);
void Demo01(void);
void Setup_Demo_Arts(void);
void Setup_Select_Demo_PL(void);

s32 Play_Demo(void) {
    void (*main_jmp_tbl[2])(void) = { Demo00, Demo01 };

    Next_Demo = 0;
    main_jmp_tbl[D_No[0]]();
    return Next_Demo;
}

void Demo00(void) {
    Play_Game = 1;

    switch (D_No[1]) {
    case 0:
        Switch_Screen(1);
        Purge_texcash_of_list(3);
        Make_texcash_of_list(3);
        D_No[1] += 1;
        G_No[2] = 0;
        Game_pause = 0;
        Conclusion_Flag = 0;
        appear_type = 1;
        Control_Time = 0x800;
        Round_Level = 7;
        Weak_PL = (u8)(random_16() & 1);
        break;

    case 1:
        Switch_Screen(1);
        Game02();

        if (--Cover_Timer == 0) {
            D_No[1] += 1;
            Switch_Screen_Init();
            return;
        }

        break;

    case 2:
        Game02();

        if (Switch_Screen_Revival(0) != 0) {
            D_No[1] += 1;
            D_Timer = 1800;
            Stop_SG = 0;
            return;
        }

        break;

    case 3:
        Game02();

        if (--D_Timer == 1) {
            D_No[1] += 1;
            Stop_Combo = 1;
            return;
        }

        if (Conclusion_Flag) {
            D_No[1] += 1;
            Stop_Combo = 1;
            D_Timer = 90;
            return;
        }

        break;

    case 4:
        Game02();

        if (--D_Timer == 0) {
            D_No[1] += 1;
            Game_pause = 1;
            Disappear_LOGO = 1;
            D_Timer = 16;
            return;
        }

        break;

    case 5:
        Game02();

        if (--D_Timer == 0) {
            D_No[1] += 1;
            Switch_Screen_Init();
            SsBgmFadeOut(0x800);
            return;
        }

        break;

    case 6:
        Game02();

        if (Switch_Screen(0) != 0) {
            D_No[1] += 1;
            Demo_Flag = 0;
            Present_Mode = 0;
            Cover_Timer = 23;
            BGM_Stop();

            if (++Select_Demo_Index > 3) {
                Select_Demo_Index = 0;
                return;
            }
        }

        break;

    default:
        Switch_Screen(1);
        Next_Demo = 1;
        break;
    }
}

void Demo01(void) {
    if (D_No[1] >= 2) {
        Play_Game = 1;
    }

    switch (D_No[1]) {
    case 0:
        Switch_Screen(1);
        D_No[1] += 1;
        Game_pause = 0;
        Demo_Time_Stop = 0;
        Before_Select_Sub();
        Setup_Select_Demo_PL();
        Setup_Demo_Arts();
        Weak_PL = (u8)(random_16() & 1);
        Clear_Break_Com(0);
        grade_check_work_1st_init(0, 0);
        grade_check_work_1st_init(0, 1);
        Clear_Break_Com(1);
        grade_check_work_1st_init(1, 0);
        grade_check_work_1st_init(1, 1);
        Game01();
        break;

    case 1:
        Game01();

        if (Demo_Time_Stop) {
            D_No[1] += 1;
            G_No[2] = 0;
            return;
        }

        break;

    case 2:
        Switch_Screen(1);
        Game02();

        if (--Cover_Timer == 0) {
            D_No[1] += 1;
            Switch_Screen_Init();
            return;
        }

        break;

    case 3:
        Game02();

        if (Switch_Screen_Revival(0) != 0) {
            D_No[1] += 1;
            D_Timer = 1200;
            Stop_SG = 0;
            return;
        }

        break;

    case 4:
        Game02();

        if (--D_Timer == 1) {
            Stop_Combo = 1;
            Disappear_LOGO = 1;
            return;
        }

        if (!D_Timer) {
            D_No[1] += 1;
            D_Timer = 16;
            Demo_Time_Stop = 1;
            Game_pause = 1;
            return;
        }

        break;

    case 5:
        Game02();

        if (--D_Timer == 0) {
            D_No[1] += 1;
            Switch_Screen_Init();
            SsBgmFadeOut(0x800);
            return;
        }

        break;

    case 6:
        Game02();

        if (Switch_Screen(0) != 0) {
            D_No[1] += 1;
            Cover_Timer = 23;
            BGM_Stop();
            return;
        }

        break;

    default:
        Next_Demo = 1;
        break;
    }
}

void Setup_Demo_PL(void) {
    My_char[0] = (u8)Demo_PL_Play_Data[Demo_PL_Index][0];
    My_char[1] = (u8)Demo_PL_Play_Data[Demo_PL_Index][1];
    init_omop();
}

void Setup_Demo_Arts(void) {
    Super_Arts[0] = (s8)Arts_Rnd_Demo_Data[random_16() & 7];
    Super_Arts[1] = (s8)Arts_Rnd_Demo_Data[random_16() & 7];
    Player_Color[0] = 0;
    Player_Color[1] = 0;
}

void Setup_Demo_Stage(void) {
    s16 rnd = (s16)(random_16() & 1);

    bg_w.area = 0;
    bg_w.stage = Demo_Stage_Play_Data[Demo_Stage_Index][rnd];
    Demo_Stage_Index += 1;

    if (++Demo_PL_Index > 3) {
        Demo_PL_Index = 0;
        Demo_Stage_Index = 0;
    }
}

void Setup_Select_Demo_PL(void) {
    plw[0].wu.operator = 0;
    plw[1].wu.operator = 0;
    Operator_Status[0] = 0;
    Operator_Status[1] = 0;
    plw[Demo_PL_Data[Select_Demo_Index]].wu.operator = 1;
    Operator_Status[Demo_PL_Data[Select_Demo_Index]] = 1;
}
