/* Pause.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * Flash_Pause_1st 0x96060 size 0x12.
 * Not located in sf33rd.xbe; their PS2 C is kept under #if 0: Pause_Task,
 * Pause_Check, Pause_Move, Pause_Sleep, Pause_Die, Flash_Pause,
 * Flash_Pause_Sleep, Flash_Pause_2nd, Flash_Pause_3rd, Flash_Pause_4th,
 * dispControllerWasRemovedMessage, Check_Pause_Term, Exit_Pause, Setup_Pause,
 * Setup_Come_Out, Check_Play_Status.
 * Data: PAUSE_X: defined elsewhere on Xbox.
 * Data: Stock_Turbo_Timer: defined elsewhere on Xbox.
 * Data: Stock_Process_Counter: defined elsewhere on Xbox.
 */

#include "structs.h"



extern u8 PAUSE_X;

extern u8 Stock_Turbo_Timer;

extern u8 Stock_Process_Counter;

;

;

void Flash_Pause_1st(struct _TASK* task_ptr) {
    if (--task_ptr->free[0] == 0) {
        task_ptr->r_no[2] = 2;
        task_ptr->free[0] = 60;
    }
}

#if 0
/* PS2 C for functions not located in sf33rd.xbe yet. */

void Pause_Task(struct _TASK* task_ptr) {
    void (*Main_Jmp_Tbl[4])(struct _TASK*) = { Pause_Check, Pause_Move, Pause_Sleep, Pause_Die };

    if (!nowSoftReset() && Mode_Type != 2 && Mode_Type != 3 && Mode_Type != 4) {
        Main_Jmp_Tbl[task_ptr->r_no[0]](task_ptr);
        Flash_Pause(task_ptr);
    }
}

void Pause_Check(struct _TASK* task_ptr) {
    PAUSE_X = 0;

    if (Check_Pause_Term(~(PLsw[0][1]) & (PLsw[0][0]), 0) == 0) {
        Check_Pause_Term(~(PLsw[1][1]) & (PLsw[1][0]), 1);
    }

    switch (PAUSE_X) {
    case 1:
        Setup_Pause(task_ptr);
        break;

    case 2:
        Setup_Come_Out(task_ptr);
        break;
    }
}

void Pause_Move(struct _TASK* task_ptr) {
    u16 sw = ~PLsw[Pause_ID][1] & PLsw[Pause_ID][0];

    if (Exit_Menu) {
        Exit_Pause(task_ptr);
    }
}

void Pause_Sleep(struct _TASK* /* unused */) {}

void Pause_Die(struct _TASK* /* unused */) {}

void Flash_Pause(struct _TASK* task_ptr) {
    void (*Flash_Jmp_Tbl[5])(
        struct _TASK*) = { Flash_Pause_Sleep, Flash_Pause_1st, Flash_Pause_2nd, Flash_Pause_3rd, Flash_Pause_4th };

    if (Pause_Down != 0) {
        Flash_Jmp_Tbl[task_ptr->r_no[2]](task_ptr);
    }
}

void Flash_Pause_Sleep(struct _TASK* /* unused */) {}

void Flash_Pause_2nd(struct _TASK* task_ptr) {
    if (--task_ptr->free[0]) {
        if (Pause_ID == 0) {
            SSPutStr2(20, 9, 9, "1P PAUSE");
            return;
        }

        SSPutStr2(20, 9, 9, "2P PAUSE");
        return;
    }

    task_ptr->r_no[2] = 1;
    task_ptr->free[0] = 30;
}

void Flash_Pause_3rd(struct _TASK* /* unused */) {}

void Flash_Pause_4th(struct _TASK* task_ptr) {
    if (Interface_Type[Pause_ID] == 0) {
        dispControllerWasRemovedMessage(0x84, 0x52, 0x10);
        return;
    }

    Pause_Type = 1;
    Setup_Pause(task_ptr);
}

void dispControllerWasRemovedMessage(s32 x, s32 y, s32 step) {
    SSPutStrPro(0, x, y, 9, -1, "Please reconnect");
    SSPutStrPro(0, x, (y + step), 9, -1, "the controller to");

    if (Pause_ID) {
        SSPutStrPro(0, x, (y + (step * 2)), 9, -1, "controller port 2.");
        return;
    }

    SSPutStrPro(0, x, (y + (step * 2)), 9, -1, "controller port 1.");
}

s32 Check_Pause_Term(u16 sw, u8 PL_id) {
    if (Demo_Flag == 0) {
        return 0;
    }

    if (Allow_a_battle_f == 0 || Extra_Break != 0) {
        return 0;
    }

    if (vm_w.Access != 0 || vm_w.Request != 0) {
        return PAUSE_X = 0;
    }

    if (Exec_Wipe) {
        return 0;
    }

    Pause_ID = PL_id;

    if (Check_Play_Status(PL_id) == 0) {
        return 0;
    }

    if (sw & 0x4000) {
        Pause_Type = 1;
        return PAUSE_X = 1;
    }

    if (Present_Mode == 3) {
        if (Interface_Type[Decide_ID] == 0) {
            Pause_ID = Decide_ID;
            Pause_Type = 2;
            return PAUSE_X = 2;
        }
    } else if (Interface_Type[PL_id] == 0 && plw[PL_id].wu.operator) {
        Pause_Type = 2;
        return PAUSE_X = 2;
    }

    return 0;
}

void Exit_Pause(struct _TASK* task_ptr) {
    u8 ix;

    if (Present_Mode != 3 && Check_Pause_Term(0, (Pause_ID ^ 1))) {
        Exit_Menu = 0;
        return;
    }

    SE_selected();
    Game_pause = 0;
    Pause = 0;
    Pause_Down = 0;
    Turbo_Timer = Stock_Turbo_Timer;
    Process_Counter = Stock_Process_Counter;

    for (ix = 0; ix < 4; ix++) {
        task_ptr->r_no[ix] = 0;
        task_ptr->free[ix] = 0;
    }

    Menu_Suicide[0] = 1;
    Menu_Suicide[1] = 1;
    Menu_Suicide[2] = 1;
    Menu_Suicide[3] = 1;
    pulpul_request_again();
    cpExitTask(6);
    cpExitTask(3);
    SsBgmHalfVolume(0);
}

void Setup_Pause(struct _TASK* task_ptr) {
    s16 ix;

    SE_selected();
    Pause_Down = 1;
    Game_pause = 0x81;
    task_ptr->r_no[0] = 1;
    task_ptr->r_no[2] = 1;
    task_ptr->free[0] = 1;
    Stock_Turbo_Timer = Turbo_Timer;
    Stock_Process_Counter = Process_Counter;
    cpReadyTask(3U, Menu_Task);
    task[3].r_no[0] = 1;
    Exit_Menu = 0;

    for (ix = 0; ix < 4; ix++) {
        Menu_Suicide[ix] = 0;
    }

    Order[0x8A] = 3;
    Order_Timer[0x8A] = 1;
    effect_66_init(0x8A, 9, 2, 7, -1, -1, -0x3FFC);
    SsBgmHalfVolume(1);
    spu_all_off();
}

void Setup_Come_Out(struct _TASK* task_ptr) {
    s16 ix;

    SE_selected();
    Pause_Down = 1;
    Game_pause = 0x81;
    task_ptr->r_no[0] = 1;
    task_ptr->r_no[2] = 4;
    task_ptr->free[0] = 1;
    Stock_Turbo_Timer = Turbo_Timer;
    Stock_Process_Counter = Process_Counter;
    cpReadyTask(3, Menu_Task);
    task[3].r_no[0] = 1;
    Exit_Menu = 0;

    for (ix = 0; ix < 4; ix++) {
        Menu_Suicide[(ix)] = 0;
    }

    Order[0x8A] = 3;
    Order_Timer[0x8A] = 1;
    effect_66_init(0x8A, 9, 2, 7, -1, -1, -0x3FFC);
    SsBgmHalfVolume(1);
    spu_all_off();
}

s32 Check_Play_Status(s16 PL_id) {
    if (Mode_Type != 1) {
        return Round_Operator[PL_id];
    }

    return 1;
}
#endif
