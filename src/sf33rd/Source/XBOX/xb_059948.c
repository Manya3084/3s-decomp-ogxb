/* xb_059948.c: Xbox-only code from the run of Xbox-only functions at 0x59948, which no
 * PS2 file covers.
 * Capcom's source is lost. Its C++ methods are written as C,
 * XB_FASTCALL (__fastcall) with this first. Each body was checked
 * against retail by analysis-ps2map/xbgen.py. The xb_ names are
 * made up. */

#include "types.h"

void sound_all_off(void);
extern s32 D_00795C80;
void render_start(void);
void render_end(void);
void xb_ApplyDisplaySize(void);
void xb_DrawTexturedRect(s32 a, s32 b, s32 c, s32 d, s32 e, u32 color, s32 f, s32 g);
void xb_DrawSystemMessage(s32 a, s32 x, s32 y, s32 w, s32 h, s32 c);
void xb_PrintFlush(void);
void xb_PrintClear(void);
void xb_PrintReset(void);
void njdp2d_draw(u32 mask);
void njdp2d_init(void);
void xb_EndFrame(s32 a);
void BGM_Server(void);

void xb_ShowDiskReadError(void) {
    sound_all_off();

    if (D_00795C80 == 0) {
        render_start();
    }

    while (1) {
        xb_ApplyDisplaySize();
        xb_DrawTexturedRect(0, 0, 7, 0x280, 0x1E0, 0xFF000000, 0, 8);
        xb_DrawTexturedRect(0x8C, 0x70, 5, 0x164, 0xC0, 0xF8402020, 2, 8);
        xb_DrawSystemMessage(2, 0xA0, 0x90, 0x16, 0x16, 0x20);
        xb_PrintFlush();
        xb_PrintClear();
        xb_PrintReset();
        njdp2d_draw(0x18);
        render_end();
        xb_EndFrame(0);
        BGM_Server();
        njdp2d_init();
        render_start();
    }
}
