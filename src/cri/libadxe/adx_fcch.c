/* adx_fcch.c: ADXF_Ocbi, retail sf33rd.xbe.
 * On the PS2 it writes the data cache back over a read buffer. On the Xbox
 * it does nothing: the name is folded into the empty body at 0x1725E0 (with
 * ADXSTM_Finish). It is in a file of its own so that adx_fs.c's calls to it
 * are kept, as retail keeps them. */

#include "types.h"

void ADXF_Ocbi(s8 *buf, s32 bsize) {
}
