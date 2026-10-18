/* Notes from the hand port this file replaced:
 * Country is the byte at 0x7A8748. The character test is the dword 14.
 * A character of 20 with the same country test is a different function.
 */

s32 chkNameAkuma(s32 plnum, s32 rnum) {
    if (plnum == 14 && (Country == 4 || Country == 2 || Country == 3)) {
        return rnum;
    }

    return 0;
}
