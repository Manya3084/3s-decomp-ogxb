/* Slow-motion flags, retail sf33rd.xbe.
 * init_slow_flag is 0x9940F size 0x15, interior after the ret.
 * set_conclusion_slow is 0x99424 size 0xA, interior after the ret.
 * set_EXE_flag is 0x9942E size 0x5D, interior after the ret.
 *
 * SLOW_timer is the word at 0xC7C830. SLOW_flag is the word at 0xC7C832.
 * EXE_flag is the word at 0xC7C834. Game_pause is the byte at 0x7A89B0.
 * Game_timer is the word at 0x7A8830. slow_timer_to_flag is 0x265504 and
 * matches the 32 PlayStation 2 bytes. set_conclusion_slow stores 95.
 */

#include "types.h"

extern s16 SLOW_timer;
extern s16 SLOW_flag;
extern s16 EXE_flag;
extern u8 Game_pause;
extern u16 Game_timer;
/* Tables pasted from the PS2 file; analysis-ps2map/portdata.py found
   each equal to retail. */
const s8 slow_timer_to_flag[32] = { 1, 1, 1, 1, 1, 1, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3,
                                    3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3 };


void init_slow_flag(void) {
    EXE_flag = 0;
    SLOW_flag = 0;
    SLOW_timer = 0;
}

void set_conclusion_slow(void) {
    SLOW_timer = 95;
}

void set_EXE_flag(void) {
    s16 tmw;

    if (!Game_pause) {
        if (SLOW_timer) {
            if (--SLOW_timer) {
                tmw = SLOW_timer / 8;

                if (tmw > 31) {
                    tmw = 31;
                }

                SLOW_flag = slow_timer_to_flag[tmw];
            } else {
                SLOW_flag = 0;
            }
        }

        EXE_flag = Game_timer % (SLOW_flag + 1);
    }
}
