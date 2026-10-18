/* xb_03E0BC.c: Xbox-only code from the run of Xbox-only functions at 0x3E0BC, which no
 * PS2 file covers.
 * Capcom's source is lost. Its C++ methods are written as C,
 * XB_FASTCALL (__fastcall) with this first. Each body was checked
 * against retail by analysis-ps2map/xbgen.py. The xb_ names are
 * made up. */

#include "types.h"

extern u8 Order[148];
extern u8 Order_Timer[148];
extern u8 Order_Dir[148];
extern s32 D_00795CD0;
void xb_CreateScreenTextures(void);
void Purge_mmtm_area(s16 ix);
void Make_texcash_of_list(s16 ix);
void bg_etc_write(s16 type);
s32 load_any_texture_patnum(u16 patnum, u8 kokey, u8 _unused);
s32 effect_57_init(s16 dir_old, s16 ID, s16 Target_BG, s16 char_ix, s16 option);

void xb_SetupSelectBG(void) {
    if (D_00795CD0 != 0) {
        return;
    }

    D_00795CD0 = 1;
    xb_CreateScreenTextures();
    Purge_mmtm_area(2);
    Make_texcash_of_list(2);
    bg_etc_write(2);
    Order[0x4E] = 5;
    load_any_texture_patnum(0x7F30, 0xC, 0);
    Order_Timer[0x4E] = 1;
    effect_57_init(0x4E, 0, 0, 0x45, 0);
    Order_Dir[0x4E] = 0;
}

void xb_ClearSelectBGFlag(void) {
    D_00795CD0 = 0;
}

void xb_CloseSelectBG(void) {
    Order[0x4E] = 4;
    Order_Timer[0x4E] = 0;
    xb_ClearSelectBGFlag();
}
