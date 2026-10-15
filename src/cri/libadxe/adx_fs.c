/* adxf_ChkPrmPt, retail sf33rd.xbe 0x165B80.
 * The compare is signed: ptid < 0 or ptid >= 256 returns -3.
 * ADXERR_CallErrFunc1 is 0x168E10.
 */

#include "types.h"

#define ADXF_PART_MAX 256
#define ADXF_ERR_OK 0
#define ADXF_ERR_PRM (-3)

extern void ADXERR_CallErrFunc1(const char *msg);

s32 adxf_ChkPrmPt(s32 ptid, void *ptinfo) {
    if (ptid < 0 || ptid >= ADXF_PART_MAX) {
        ADXERR_CallErrFunc1("E9040801:partition ID is range outside.(adxf_ChkPrmPt)");
        return ADXF_ERR_PRM;
    }

    if (ptinfo == 0) {
        ADXERR_CallErrFunc1("E9040802:'ptinfo' is NULL.(adxf_ChkPrmPt)");
        return ADXF_ERR_PRM;
    }

    return ADXF_ERR_OK;
}
