/* Stage sound wrappers, retail sf33rd.xbe.
 * BGM_Request_Code_Check is 0x9840C size 0xD, interior after the ret.
 * BGM_Stop is 0x98419 size 0x5, interior after the jmp.
 * SE_All_Off is 0x9841E size 0x5, interior after the jmp.
 * 0x98407 stays unnamed because Sound_SE and BGM_Request share that body.
 */

#include "types.h"

extern void SsRequest_CC(u16 num);
extern void SsBgmOff(void);
extern void spu_all_off(void);

void BGM_Request_Code_Check(u16 Code) {
    SsRequest_CC(Code);
}

void BGM_Stop(void) {
    SsBgmOff();
}

void SE_All_Off(void) {
    spu_all_off();
}
