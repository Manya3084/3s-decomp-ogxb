/* Reset.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * Check_SoftReset 0x981BF size 0x31.
 * Setup_Next_Disposal 0x981F0 size 0x21.
 * Check_Reset 0x982B0 size 0x34. Read against the x86: rewritten for Xbox:
 * Present_Mode 2 (the Xbox-only mode from Mode_Select) blocks the reset like
 * Forbid_Reset. The C is the Xbox code (analysis-ps2map/overrides/Reset.c).
 * Reset_Move 0x982E4 size 0x47.
 * Not located in sf33rd.xbe; their PS2 C is kept under #if 0: Reset_Task,
 * Reset_Init, nowSoftReset, Reset_Wait, Reset_Sleep, Check_Reset_IO.
 * Data: Reset_Status 0xC7C838.
 * Data: RESET_X 0xC7C83A.
 * Unnamed data used (not checked): Setup_Next_Disposal: 0x7a8817; Check_Reset:
 * 0x7a8355.
 * Globals: Present_Mode 0x7A819C, G_No 0x7A825C, Pause_ID 0x7A8514,
 * Forbid_Reset 0x7A8778, Game_pause 0x7A89B0, Reset_Status 0xC7C838, RESET_X
 * 0xC7C83A.
 */

#include "structs.h"

void Check_Reset();
void ToneDown(u8 tone, u8 priority);
void sound_all_off();
s32 Setup_Next_Disposal();
void Request_LDREQ_Break();
void effect_work_init();
extern u8 Forbid_Reset;
extern u8 Present_Mode;
extern s8 Switch_Type;
u8 Check_SoftReset(s16 PL_id);
extern u8 Game_pause;
extern u8 Pause_ID;
extern u8 Reset_Bootrom;
extern u8 G_No[4];

extern u8 Reset_Status[2];

extern u8 RESET_X;

void Reset_Move(struct _TASK* task_ptr) {
    RESET_X = 0;
    Check_Reset();

    if (RESET_X) {
        ToneDown(0xFF, 0);
        sound_all_off();
        task_ptr->r_no[0] = 2;
        task_ptr->free[0] = Setup_Next_Disposal();
        task_ptr->r_no[1] = 0;
        Request_LDREQ_Break();
        effect_work_init();
    }
}

/* Xbox: no reset while Present_Mode is 2 (the Xbox-only mode). */
void Check_Reset() {
    if (Forbid_Reset || Present_Mode == 2) {
        RESET_X = 0;
        return;
    }

    Switch_Type = 1;

    if (Check_SoftReset(0) == 0) {
        Check_SoftReset(1);
    }
}

u8 Check_SoftReset(s16 PL_id) {
    if (Reset_Status[PL_id] == 0x63) {
        Game_pause = 0x81;
        Pause_ID = PL_id;
        return RESET_X = 1;
    }

    return RESET_X = 0;
}

s32 Setup_Next_Disposal() {
    if (Reset_Bootrom) {
        return 1;
    }

    if ((G_No[0] == 1) || ((G_No[0] == 2) && (G_No[1] == 0))) {
        return 1;
    }

    return 0;
}

#if 0
/* PS2 C for functions not located in sf33rd.xbe yet. */

void Reset_Task(struct _TASK* task_ptr) {
    void (*Main_Jmp_Tbl[4])() = { Reset_Init, Reset_Move, Reset_Wait, Reset_Sleep };
    Check_Reset_IO(task_ptr, 0);
    Check_Reset_IO(task_ptr, 1);
    Main_Jmp_Tbl[task_ptr->r_no[0]](task_ptr);
}

void Reset_Init(struct _TASK* task_ptr) {
    task_ptr->r_no[0] += 1;
    RESET_X = 0;
}

u8 nowSoftReset() {
    return RESET_X != 0;
}

void Reset_Wait(struct _TASK* task_ptr) {
    ToneDown(0xFF, 0);

    switch (task_ptr->r_no[1]) {
    case 0:
        sound_all_off();

        if (Check_LDREQ_Break() == 0) {
            task_ptr->r_no[1] += 1;
        }

        break;

    case 1:
        Soft_Reset_Sub();
        task_ptr->r_no[0] += 1;
        break;
    }
}

void Reset_Sleep(struct _TASK* task_ptr) {
    ToneDown(0xFF, 0);

    if (Pause_ID == 0) {
        if (!(p1sw_0 & 0x4000)) {
            task_ptr->r_no[0] = 0;
        }
    } else if (!(p2sw_0 & 0x4000)) {
        task_ptr->r_no[0] = 0;
    }

    if (task_ptr->r_no[0] == 0) {
        checkAdxFileLoaded();
        checkSelObjFileLoaded();
    }
}

void Check_Reset_IO(struct _TASK* /* unused */, s16 PL_id) {
    u16 sw;
    u16 plsw;

    if (Switch_Type == 0) {
        if (PL_id) {
            plsw = p2sw_0;
        } else {
            plsw = p1sw_0;
        }
    } else {
        plsw = PLsw[PL_id][0];
    }

    sw = plsw & 0xC000;

    if (sw == 0) {
        Reset_Status[PL_id] = 0;
        return;
    }

    switch (Reset_Status[PL_id]) {
    case 0:
        if (sw == 0xC000) {
            Reset_Status[PL_id] = 0x63;
            break;
        }

        if (sw & 0x4000) {
            Reset_Status[PL_id] = 0x62;
        }

        break;

    case 0x62:
        if (!(sw & 0x4000)) {
            Reset_Status[PL_id] = 0;
        }

        break;

    default:
        if (plsw != 0xC000) {
            Reset_Status[PL_id] = 0;
        }

        break;
    }
}
#endif
