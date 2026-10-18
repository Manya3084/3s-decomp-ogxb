/* Saver.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * Saver_Init 0x9B5A6 size 0x18.
 * Not located in sf33rd.xbe; their PS2 C is kept under #if 0: Saver_Task,
 * Saver_Check, Saver_Move, Saver_Exit.
 */

#include "structs.h"





void Saver_Init(struct _TASK* task_ptr) {
    task_ptr->r_no[0] = 1;
    task_ptr->r_no[1] = 0;
    task_ptr->r_no[2] = 0;
    task_ptr->r_no[3] = 0;
    task_ptr->timer = 0;
}

#if 0
/* PS2 C for functions not located in sf33rd.xbe yet. */

void Saver_Task(struct _TASK* task_ptr) {
    void (*const Main_Jmp_Tbl[4])(struct _TASK*) = { Saver_Init, Saver_Check, Saver_Move, Saver_Exit };

    if (!nowSoftReset()) {
        Main_Jmp_Tbl[task_ptr->r_no[0]](task_ptr);
    }
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

void Saver_Exit(struct _TASK* task_ptr) {
    switch (task_ptr->r_no[1]) {
    case 0:
        task_ptr->r_no[1] += 1;
        FadeInit();
        /* fallthrough */

    case 1:
        if (FadeIn(1, 0xFF, 8) != 0) {
            Saver_Init(task_ptr);
        }
    }
}
#endif
