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

/* xb_DrawFilledRect 0xF8070.
 *
 * A w x h rectangle of col from the top left, with the quad states
 * saved around it. */

s32 xb_DrawFilledRectSaved(void* q);

void xb_DrawFilledRect(s32 w, s32 h, u32 col) {
    f32 q[9];

    q[0] = 0.0f;
    q[1] = 0.0f;
    q[4] = w;
    q[5] = h;
    q[6] = 0.0f;
    q[2] = 0.0f;
    q[7] = 1.0f;
    q[3] = 1.0f;
    *(u32*)&q[8] = col;
    xb_DrawFilledRectSaved(q);
}

/* xb_AsciiToSjis 0xFB428.
 *
 * An ASCII (or half-width katakana) byte to its full-width Shift-JIS
 * code; control characters and space give the full-width space. Retail
 * takes the byte in al. */

u32 xb_AsciiToSjis(u8 c) {
    if (c <= 0x20) {
        return 0x8140;
    }

    if (c < 0x60) {
        return c + 0x851F;
    }

    if (c < 0x80) {
        return c + 0x8520;
    }

    if (c == 0xA5) {
        return 0x85A3;
    }

    return c + 0x84FE;
}
