/* Pause.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * Flash_Pause_1st 0x96060 size 0x12.
 * Flash_Pause_2nd 0x96072 size 0x36.
 * dispControllerWasRemovedMessage 0x960A8 size 0x173. Read against the x86:
 * the Xbox draws the message with its debug font at fixed positions (x, y, and
 * step are unused), names the controller port of the pausing player, and adds
 * "and press START to continue."; Country 1 prints Shift-JIS text with a
 * full-width port digit. The scale is PrioBase[2]. The C is the Xbox code
 * (analysis-ps2map/overrides/Pause.c).
 * Check_Pause_Term 0x96336 size 0xAC. FLAG: PS2-only callees
 * Check_Play_Status; x86-only constants 0x40; x86-only globals mpp_w.
 * Exit_Pause 0x963E2 size 0xA2. FLAG: x86-only offsets -0x8.
 * Setup_Pause 0x96484 size 0x91.
 * Setup_Come_Out 0x96515 size 0x91.
 * xb_DrawPadRemovedBox 0x96648 size 0x37. FLAG: x86-only callees
 * xb_DrawTexturedRect,xb_DrawPadRemovedText.
 * Pause_Check 0x9667F size 0x53.
 * Pause_Move 0x966D2 size 0xF.
 * Flash_Pause_4th 0x966E1 size 0x2F. FLAG: x86-only constants 0x46.
 * Flash_Pause 0x96783 size 0x41.
 * Pause_Task 0x967C4 size 0x5D. FLAG: x86-only callees xb_GetOnlineFlag.
 * Flash_Pause_3rd is folded into 0x4384A with 58 other bodies. Unnamed.
 * Flash_Pause_Sleep is folded into 0x4384A with 58 other bodies. Unnamed.
 * Pause_Die is folded into 0x4384A with 58 other bodies. Unnamed.
 * Pause_Sleep is folded into 0x4384A with 58 other bodies. Unnamed.
 * Not located in sf33rd.xbe; their PS2 C is kept under #if 0:
 * Check_Play_Status.
 * Check_Play_Status has no XBE name and no aligned call.
 * SE_selected is folded into 0x9C793.
 * sprintf has no XBE name and no aligned call.
 * Data: PAUSE_X 0xC7CE8A.
 * Data: Stock_Turbo_Timer 0xC7CE88.
 * Data: Stock_Process_Counter 0xC7CE89.
 * Unnamed data used (not checked): Flash_Pause_2nd: 0x264e1c,0x264e28;
 * dispControllerWasRemovedMessage:
 * 0x252e20,0x252e24,0x252e28,0x252e2c,0x264e34,0x264e44,0x264e54,0x264e68.
 * Globals: __security_cookie 0x43CF74, Decide_ID 0x7A810A, Exit_Menu 0x7A8113,
 * Present_Mode 0x7A819C, Mode_Type 0x7A825A, Pause_Type 0x7A8264,
 * Allow_a_battle_f 0x7A82B8, Exec_Wipe 0x7A82F9, Order 0x7A8380, Demo_Flag
 * 0x7A842D, Order_Timer 0x7A8480, Pause_ID 0x7A8514, Pause_Down 0x7A8590,
 * Country 0x7A8748, Menu_Suicide 0x7A87A0, Pause 0x7A8816, Extra_Break
 * 0x7A89A0, Game_pause 0x7A89B0, mpp_w 0x7AA5C0, task 0x7BE020, PLsw 0x7C5570,
 * Process_Counter 0x7C5578, Interface_Type 0x7C56A4, Turbo_Timer 0x7C5980,
 * Stock_Turbo_Timer 0xC7CE88, Stock_Process_Counter 0xC7CE89, PAUSE_X
 * 0xC7CE8A, plw 0xC7CEA0, PrioBase 0xC7E560.
 */

#include "structs.h"
#include <stdio.h>

void sub_0009C793();
void dispControllerWasRemovedMessage(s32 x, s32 y, s32 step, s32 pl_id);
s32 xb_GetOnlineFlag(void);
int sprintf(char* buf, const char* fmt, ...);
void xb_PrintSetAttr(s32 attr);
void xb_PrintSetScale(f32 scale);
void xb_PrintSetColor(s32 a, s32 b);
void xb_PrintSetPos(s32 x, s32 y);
void xb_PrintString(const s8* str);
extern s8 D_007AA5F6[2];
extern f32 PrioBase[128];
void xb_DrawTexturedRect(s32 a, s32 b, s32 c, s32 d, s32 e, u32 color, s32 f, s32 g);
void xb_DrawPadRemovedText(s32 x, s32 y, s32 step, s32 pl);
void Pause_Check(struct _TASK* task_ptr);
void Pause_Move(struct _TASK* task_ptr);
void Pause_Sleep(struct _TASK* );
void Pause_Die(struct _TASK* );
u8 nowSoftReset();
extern u8 Mode_Type;
void Flash_Pause(struct _TASK* task_ptr);
s32 Check_Pause_Term(u16 sw, u8 PL_id);
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
void SSPutStr2(u16 x, u16 y, u8 atr, const s8* str);
extern u8 Interface_Type[2];
extern u8 Pause_Type;
extern u8 Country;
extern s8 Demo_Flag;
extern u8 Allow_a_battle_f;
extern u8 Extra_Break;
extern struct _VM_W vm_w;
extern s8 Exec_Wipe;
s32 Check_Play_Status(s16 PL_id);
extern u8 Present_Mode;
extern u8 Decide_ID;
extern PLW plw[2];
extern u8 Game_pause;
extern u8 Pause;
extern u8 Turbo_Timer;
extern u8 Process_Counter;
extern u8 Menu_Suicide[4];
void pulpul_request_again();
void cpExitTask(u16 num);
void SsBgmHalfVolume(s16 flag);
void cpReadyTask(u16 num, void* func_adrs);
void Menu_Task(struct _TASK* task_ptr);
extern struct _TASK task[11];
extern u8 Order[148];
extern u8 Order_Timer[148];
s32 effect_66_init(s16 order_index, s16 id, s16 master_player, s16 target_bg, s16 char_ix, s16 char_ix2, s16 option);
void spu_all_off();

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

void Flash_Pause_1st(struct _TASK* task_ptr) {
    if (--task_ptr->free[0] == 0) {
        task_ptr->r_no[2] = 2;
        task_ptr->free[0] = 60;
    }
}

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

/* The Xbox message is 12 pixels higher (y 0x46) and names the controller (Pause_ID). */
void Flash_Pause_4th(struct _TASK* task_ptr) {
    if (Interface_Type[Pause_ID] == 0) {
        dispControllerWasRemovedMessage(0x84, 0x46, 0x10, Pause_ID);
        return;
    }

    Pause_Type = 1;
    Setup_Pause(task_ptr);
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

void Setup_Pause(struct _TASK* task_ptr) {
    s16 ix;

    sub_0009C793();
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

    sub_0009C793();
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

void xb_DrawPadRemovedBox(s32 pl) {
    xb_DrawTexturedRect(0xAC, 0x70, 3, 0x124, 0xC0, 0xF8402020, 2, 8);
    xb_DrawPadRemovedText(0x84, 0x54, 0x10, pl);
}

#if 0
/* PS2 C for functions not located in sf33rd.xbe yet. */

s32 Check_Play_Status(s16 PL_id) {
    if (Mode_Type != 1) {
        return Round_Operator[PL_id];
    }

    return 1;
}
#endif
