/* xb_09D6D2.c: Xbox-only code from the run of Xbox-only functions at 0x9D6D2, which no
 * PS2 file covers.
 * Capcom's source is lost. Its C++ methods are written as C,
 * XB_FASTCALL (__fastcall) with this first. Each body was checked
 * against retail by analysis-ps2map/xbgen.py. The xb_ names are
 * made up. */

#include "types.h"
#include <string.h>

extern u8* D_007AA5A4;
void xb_xlive_font_Init(void* buf);
void xb_xlive_font_LoadPages(void);
void xb_xlive_font_SetPage(s32 page);
extern u8 D_00334900[];
extern s16 load_it_use_any_key(u16 fnum, u8 kokey, u8 group);
extern u32 Get_size_data_ramcnt_key(s16 key);
extern void* Get_ramcnt_address(s16 key);
void xb_PlaySoundCue(void* data, u32 size);
void Push_ramcnt_key(s16 key);
extern u16 D_00283A5C;

void xb_InitOnlineBuffers(void) {
    memset(D_007AA5A4, 0, 0xD400);
    xb_xlive_font_Init(D_007AA5A4);
    xb_xlive_font_LoadPages();
    xb_xlive_font_SetPage((s32)D_00334900);
}

void xb_LoadSoundPack(void) {
    s16 key = load_it_use_any_key(D_00283A5C, 2, 0);

    xb_PlaySoundCue(Get_ramcnt_address(key), Get_size_data_ramcnt_key(key));
    Push_ramcnt_key(key);
}
