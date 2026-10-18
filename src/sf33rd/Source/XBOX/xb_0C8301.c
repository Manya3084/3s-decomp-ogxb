/* xb_0C8301.c: Xbox-only code from the run of Xbox-only functions at 0xC8301, which no
 * PS2 file covers.
 * Capcom's source is lost. Its C++ methods are written as C,
 * XB_FASTCALL (__fastcall) with this first. Each body was checked
 * against retail by analysis-ps2map/xbgen.py. The xb_ names are
 * made up. */

#include "types.h"
#include "structs.h"

void xb_ClearTasks(void);
extern struct _TASK task[12];

void xb_ExitAllTasks(void) {
    struct _TASK* t = task;
    s32 i;

    for (i = 12; i != 0; i--, t++) {
        switch (t->condition) {
        case 1:
        case 4:
            if (t->callback_adrs != 0) {
                t->callback_adrs();
            }

            break;
        }
    }

    xb_ClearTasks();
}
