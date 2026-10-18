/* ADXM_IsSetupThrd 0x165460.
 *
 * It returns whether adxm_init_level at 0x7A5158 is nonzero.
 * The setup body at 0x1658E0 tests that counter and increments it.
 * That setup stays unnamed. ADXT_Init compares this result with 1.
 * The other caller, 0x167320, does the same compare.
 */

#include "types.h"

extern volatile s32 adxm_init_level; /* re-read each use, as retail does */

s32 ADXM_IsSetupThrd(void) {
    return adxm_init_level != 0;
}
