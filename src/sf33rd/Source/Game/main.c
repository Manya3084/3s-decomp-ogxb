/* Task helpers, retail sf33rd.xbe.
 * cpReadyTask is 0xC82BC size 0x27, interior after the ret.
 * cpExitTask is 0xC82E3 size 0x1E, interior after the ret.
 * task is 0x7BE020, stride 0x14. func_adrs is +0, callback_adrs is +4,
 * and condition is +0xC.
 */

#include "types.h"
#include "structs.h"

typedef struct _TASK _TASK;

#if defined(__i386__)
#endif

extern _TASK task[];

void cpReadyTask(u16 num, void (*func_adrs)(void)) {
    _TASK *task_ptr = &task[num];
    u8 *dst = (u8 *)task_ptr;
    s32 ix;

    for (ix = 0; ix < 0x14; ix++) {
        dst[ix] = 0;
    }

    task_ptr->func_adrs = func_adrs;
    task_ptr->condition = 2;
}

void cpExitTask(u16 num) {
    _TASK *task_ptr = &task[num];

    task_ptr->condition = 0;

    if (task_ptr->callback_adrs != 0) {
        task_ptr->callback_adrs();
    }
}
