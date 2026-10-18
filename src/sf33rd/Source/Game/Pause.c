/* Pause.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * Flash_Pause_1st 0x96060 size 0x12.
 * dispControllerWasRemovedMessage 0x960A8 size 0x173. Read against the x86:
 * the Xbox draws the message with its debug font at fixed positions (x, y, and
 * step are unused), names the controller port of the pausing player, and adds
 * "and press START to continue."; Country 1 prints Shift-JIS text with a
 * full-width port digit. The scale is PrioBase[2]. The C is the Xbox code
 * (analysis-ps2map/overrides/Pause.c).
 * Exit_Pause 0x963E2 size 0xA2. FLAG: x86-only offsets -0x8.
 * Pause_Check 0x9667F size 0x53.
 * Pause_Move 0x966D2 size 0xF.
 * Flash_Pause 0x96783 size 0x41.
 * Pause_Task 0x967C4 size 0x5D. FLAG: x86-only callees xb_GetOnlineFlag.
 * Pause_Sleep is folded into 0x4384A with 56 other bodies. Unnamed.
 * Pause_Die is folded into 0x4384A with 56 other bodies. Unnamed.
 * Not located in sf33rd.xbe; their PS2 C is kept under #if 0:
 * Flash_Pause_Sleep, Flash_Pause_2nd, Flash_Pause_3rd, Flash_Pause_4th,
 * Check_Pause_Term, Setup_Pause, Setup_Come_Out, Check_Play_Status.
 * Check_Pause_Term stays sub_00096336, the one unnamed call left in its
 * caller.
 * SE_selected is folded into 0x9C793.
 * Setup_Come_Out has no XBE name and no aligned call.
 * Setup_Pause has no XBE name and no aligned call.
 * sprintf has no XBE name and no aligned call.
 * Data: PAUSE_X: defined elsewhere on Xbox.
 * Data: Stock_Turbo_Timer: defined elsewhere on Xbox.
 * Data: Stock_Process_Counter: defined elsewhere on Xbox.
 * Unnamed data used (not checked): dispControllerWasRemovedMessage:
 * 0x252e20,0x252e24,0x252e28,0x252e2c,0x264e34,0x264e44,0x264e54,0x264e68;
 * Exit_Pause: 0x7c5578,0xc7ce88,0xc7ce89; Pause_Check: 0xc7ce8a.
 * Globals: __security_cookie 0x43CF74, Exit_Menu 0x7A8113, Present_Mode
 * 0x7A819C, Mode_Type 0x7A825A, Pause_ID 0x7A8514, Pause_Down 0x7A8590,
 * Country 0x7A8748, Menu_Suicide 0x7A87A0, Pause 0x7A8816, Game_pause
 * 0x7A89B0, mpp_w 0x7AA5C0, PLsw 0x7C5570, Turbo_Timer 0x7C5980, PrioBase
 * 0xC7E560.
 */

#include "structs.h"
#include <stdio.h>

s32 sub_00096336(u16 sw, u8 PL_id);
void sub_0009C793();
s32 xb_GetOnlineFlag(void);
int sprintf(char* buf, const char* fmt, ...);
void xb_PrintSetAttr(s32 attr);
void xb_PrintSetScale(f32 scale);
void xb_PrintSetColor(s32 a, s32 b);
void xb_PrintSetPos(s32 x, s32 y);
void xb_PrintString(const s8* str);
extern s8 D_007AA5F6[2];
extern f32 PrioBase[128];
void Pause_Check(struct _TASK* task_ptr);
void Pause_Move(struct _TASK* task_ptr);
void Pause_Sleep(struct _TASK* );
void Pause_Die(struct _TASK* );
u8 nowSoftReset();
extern u8 Mode_Type;
void Flash_Pause(struct _TASK* task_ptr);
extern u16 PLsw[2][2];
void Setup_Pause(struct _TASK* task_ptr);
void Setup_Come_Out(struct _TASK* task_ptr);
extern u8 Pause_ID;
extern u8 Exit_Menu;
void Exit_Pause(struct _TASK* task_ptr);
void Flash_Pause_Sleep(struct _TASK* );
void Flash_Pause_1st(struct _TASK* task_ptr);
void Flash_Pause_2nd(struct _TASK* task_ptr);
void Flash_Pause_3rd(struct _TASK* );
void Flash_Pause_4th(struct _TASK* task_ptr);
extern u8 Pause_Down;
extern u8 Country;
extern u8 Present_Mode;
extern u8 Game_pause;
extern u8 Pause;
extern u8 Turbo_Timer;
extern u8 Process_Counter;
extern u8 Menu_Suicide[4];
void pulpul_request_again();
void cpExitTask(u16 num);
void SsBgmHalfVolume(s16 flag);

extern u8 PAUSE_X;

extern u8 Stock_Turbo_Timer;

extern u8 Stock_Process_Counter;

;

;

/* The Xbox does not pause during an online match (xb_GetOnlineFlag). */
void Pause_Task(struct _TASK* task_ptr) {
    void (*Main_Jmp_Tbl[4])(struct _TASK*) = { Pause_Check, Pause_Move, Pause_Sleep, Pause_Die };

    if (!nowSoftReset() && Mode_Type != 2 && Mode_Type != 3 && Mode_Type != 4 && !xb_GetOnlineFlag()) {
        Main_Jmp_Tbl[task_ptr->r_no[0]](task_ptr);
        Flash_Pause(task_ptr);
    }
}

void Pause_Check(struct _TASK* task_ptr) {
    PAUSE_X = 0;

    if (sub_00096336(~(PLsw[0][1]) & (PLsw[0][0]), 0) == 0) {
        sub_00096336(~(PLsw[1][1]) & (PLsw[1][0]), 1);
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

void Flash_Pause_1st(struct _TASK* task_ptr) {
    if (--task_ptr->free[0] == 0) {
        task_ptr->r_no[2] = 2;
        task_ptr->free[0] = 60;
    }
}

/* Xbox: drawn with the debug font at fixed positions; x, y, and step are not
 * used. The message names the controller port of player pl_id and ends with
 * "and press START to continue.". Country 1 prints the Japanese text. */
void dispControllerWasRemovedMessage(s32 x, s32 y, s32 step, s32 pl_id) {
    const s8* port_jp[4];
    char buf[32];

    xb_PrintSetAttr(0);
    xb_PrintSetScale(PrioBase[2]);

    if (Country == 1) {
        port_jp[0] = "\x82P";
        port_jp[1] = "\x82Q";
        port_jp[2] = "\x82R";
        port_jp[3] = "\x82S";
        xb_PrintSetColor(0x16, 0x16);
        sprintf(buf, "\x83\x8D\x81[\x83\x89\x92[\x8Eq%s\x82\xC9\x90\xDA\x91\xB1\x82\xB5\x81" "A", port_jp[D_007AA5F6[pl_id]]);
        xb_PrintSetPos(0xD0, 0x98);
        xb_PrintString("\x83R\x83\x93\x83g\x83\x8D\x81[\x83\x89\x82\xF0\x83R\x83\x93\x83g");
        xb_PrintSetPos(0xD0, 0xB8);
        xb_PrintString(buf);
        xb_PrintSetPos(0xD0, 0xD8);
        xb_PrintString("START\x83{\x83^\x83\x93\x82\xF0\x89\x9F\x82\xB5\x82\xC4");
        xb_PrintSetPos(0xD0, 0xF8);
        xb_PrintString("\x82\xAD\x82\xBE\x82\xB3\x82\xA2\x81" "B");
        return;
    }

    xb_PrintSetColor(0x16, 0x16);
    sprintf(buf, "controller port %d", D_007AA5F6[pl_id] + 1);
    xb_PrintSetPos(0xE0, 0x88);
    xb_PrintString("Please reconnect");
    xb_PrintSetPos(0xE0, 0xA8);
    xb_PrintString("the controller to");
    xb_PrintSetPos(0xE0, 0xC8);
    xb_PrintString(buf);
    xb_PrintSetPos(0xE0, 0xE8);
    xb_PrintString("and press START");
    xb_PrintSetPos(0xE0, 0x108);
    xb_PrintString("to continue.");
}

void Exit_Pause(struct _TASK* task_ptr) {
    u8 ix;

    if (Present_Mode != 3 && sub_00096336(0, (Pause_ID ^ 1))) {
        Exit_Menu = 0;
        return;
    }

    sub_0009C793();
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

#if 0
/* PS2 C for functions not located in sf33rd.xbe yet. */

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
