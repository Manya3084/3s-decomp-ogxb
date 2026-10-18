/* xb_0F5BD5.c: Xbox-only code from 0xF5BD5. xb_LiveObj_IsReady matches only apart from
 * the functions around it, so a file of Capcom's starts here.
 * Capcom's source is lost. Its C++ methods are written as C,
 * XB_FASTCALL (__fastcall) with this first. Each body was checked
 * against retail by analysis-ps2map/xbgen.py. The xb_ names are
 * made up. */

#include "types.h"

s32 XB_FASTCALL xb_XLIVE_STARTMENU_CLASS_Get74(u8* self);
s32 XB_FASTCALL xb_LiveObj_Process(u8* self, s32 edx, s32 arg);
extern u8* D_00798CAC;

u8 XB_FASTCALL xb_LiveObj_IsReady(u8* self, s32 edx, s32 arg) {
    XB_ARG a;
    u8 ret;

    (void)edx;

    if (*(s32*)(self + 0x54) == 0) {
        ret = 0;
    } else if (xb_XLIVE_STARTMENU_CLASS_Get74(D_00798CAC + 0x24C0) == 0) {
        ret = 0;
    } else {
        a.v = arg;
        ret = ((s32 (XB_FASTCALL*)(u8*, XB_ARG))xb_LiveObj_Process)(self, a) > 2;
    }

    return ret;
}
