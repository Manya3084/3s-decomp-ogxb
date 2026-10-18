/* xb_04A5F8.c: Xbox-only code from the run of Xbox-only functions at 0x4A5F8, which no
 * PS2 file covers.
 * Capcom's source is lost. Its C++ methods are written as C,
 * XB_FASTCALL (__fastcall) with this first. Each body was checked
 * against retail by analysis-ps2map/xbgen.py. The xb_ names are
 * made up. */

#include "types.h"
#include "structs.h"

extern s16 head_ix[8];
extern s16 exec_tm[8];
extern uintptr_t frw[128][448];
extern void (*const D_0025B2C0[])(WORK* wk);

void xb_draw_effect_work(s16 index) {
    WORK* c_addr;
    s16 curr_ix;
    s16 next_ix;

    exec_tm[index] += 1;

    for (curr_ix = head_ix[index]; curr_ix != -1; curr_ix = next_ix) {
        c_addr = (WORK*)frw[curr_ix];
        next_ix = c_addr->behind;

        if (c_addr->timing != exec_tm[index]) {
            c_addr->timing = exec_tm[index];
            D_0025B2C0[c_addr->id](c_addr);
        }
    }
}
