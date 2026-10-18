/* xb_0F67F5.c: Xbox-only code from 0xF67F5, between Capcom's VoiceChat.cpp
 * and VoiceChatMessage.cpp. These match only outside the file that defines
 * xb_LiveObj_GetResult58, so they are taken to be another module.
 * Capcom's source is lost. Its C++ methods are written as C,
 * XB_FASTCALL (__fastcall) with this first. Each body was checked
 * against retail by analysis-ps2map/xbgen.py. The xb_ names are
 * made up. */

#include "types.h"

extern u8* D_00798CAC;
u8* XB_FASTCALL xb_LiveObj_Get8(u8* self);
s32 XB_FASTCALL xb_LiveObj_IsValid(u8* self);
s32 XB_FASTCALL xb_LiveObj_GetResult58(u8* self);
void xb_PollEthernetLink(void);
u8* XB_FASTCALL xb_LiveWork_Get2408(u8* self);

void XB_FASTCALL xb_LiveWork_Check2408(u8* self) {
    if (xb_LiveObj_IsValid(xb_LiveObj_Get8(D_00798CAC + 0x2408))) {
        xb_LiveObj_GetResult58(self);
        xb_PollEthernetLink();
    }
}

void xb_LiveWork_GetState(void) {
    xb_LiveWork_Check2408(xb_LiveWork_Get2408(D_00798CAC));
}
