/* Saver.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * Saver_Init 0x9B5A6 size 0x18.
 * Saver_Check 0x9B5BE size 0x39.
 * Saver_Move 0x9B5F7 size 0x6E.
 * Saver_Exit 0x9B665 size 0x3D.
 * Saver_Task 0x9B6A2 size 0x3A.
 * Globals: Demo_Flag 0x7A842D, PLsw 0x7C5570.
 */

#include "structs.h"

void Saver_Init(struct _TASK* task_ptr);
void Saver_Check(struct _TASK* task_ptr);
void Saver_Move(struct _TASK* task_ptr);
void Saver_Exit(struct _TASK* task_ptr);
u8 nowSoftReset();
extern s8 Demo_Flag;
extern u16 PLsw[2][2];
void FadeInit();
s32 FadeOut(u8 type, u8 step, u8 priority);
void ToneDown(u8 tone, u8 priority);
s32 FadeIn(u8 type, u8 step, u8 priority);



void Saver_Task(struct _TASK* task_ptr) {
    void (*const Main_Jmp_Tbl[4])(struct _TASK*) = { Saver_Init, Saver_Check, Saver_Move, Saver_Exit };

    if (!nowSoftReset()) {
        Main_Jmp_Tbl[task_ptr->r_no[0]](task_ptr);
    }
}

void Saver_Init(struct _TASK* task_ptr) {
    task_ptr->r_no[0] = 1;
    task_ptr->r_no[1] = 0;
    task_ptr->r_no[2] = 0;
    task_ptr->r_no[3] = 0;
    task_ptr->timer = 0;
}

void Saver_Check(struct _TASK* task_ptr) {
    if (Demo_Flag == 0) {
        task_ptr->timer = 0;
        return;
    }

    if ((PLsw[0][0] != 0) || (PLsw[1][0] != 0)) {
        task_ptr->timer = 0;
        return;
    }

    if ((task_ptr->timer += 1) > 18000) {
        task_ptr->r_no[0]++;
    }
}

void Saver_Move(struct _TASK* task_ptr) {
    if ((PLsw[0][0] != 0) || PLsw[1][0] != 0) {
        Saver_Init(task_ptr);

    } else {
        switch (task_ptr->r_no[1]) {
        case 0:
            task_ptr->r_no[1] += 1;
            task_ptr->free[0] = 0;
            FadeInit();
            /* fallthrough */

        case 1:
            FadeOut(1, 4, 0);

            if ((task_ptr->free[0]++) > 0x30) {
                task_ptr->r_no[1] += 1;
            }
            break;

        case 2:
            ToneDown(0xC8, 0);
            break;
        }
    }
}

/* Xbox: the fade back in runs at speed 1, not 8. */
void Saver_Exit(struct _TASK* task_ptr) {
    switch (task_ptr->r_no[1]) {
    case 0:
        task_ptr->r_no[1] += 1;
        FadeInit();
        /* fallthrough */

    case 1:
        if (FadeIn(1, 0xFF, 1) != 0) {
            Saver_Init(task_ptr);
        }
    }
}
