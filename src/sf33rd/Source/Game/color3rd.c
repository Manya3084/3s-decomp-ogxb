/* cseTsbSetBankAddr, retail sf33rd.xbe 0xF4532 size 0x5.
 * It is interior. The body is a tail jump to mlTsbSetBankAddr.
 * 0xF4510, 0xF451D, and 0xF452A stay unnamed.
 */

#include "types.h"

typedef struct SoundEvent SoundEvent;

extern s32 mlTsbSetBankAddr(u32 bank, SoundEvent *addr);

s32 cseTsbSetBankAddr(u32 bank, SoundEvent *addr) {
    return mlTsbSetBankAddr(bank, addr);
}
