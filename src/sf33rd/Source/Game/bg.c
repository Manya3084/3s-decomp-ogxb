/* Zoom and screen helpers, retail sf33rd.xbe.
 * Zoomf_Init 0xAF2BA size 0x37, interior after the ret.
 * Zoom_Value_Set 0xAF2F1 size 0x75, interior after the ret.
 * Frame_Adgjust 0xAF366 size 0x96, interior after the ret.
 * Scrn_Pos_Init 0xAF3FC size 0x40, interior after the ret.
 * Scrn_Move_Set 0xAF43C size 0x23, interior after the ret.
 * Family_Init 0xAF45F size 0x1C, interior after the ret.
 * Scrn_Renew 0xAF4DC size 0xD, interior after the ret.
 * Irl_Family 0xAF4E9 size 0x37, interior after the ret.
 * Irl_Scrn 0xAF520 size 0x69, interior after the ret.
 * Frame_Up 0xAFAE3 size 0x43, interior after the ret.
 * Frame_Down 0xAFB26 size 0x43, interior after the ret.
 *
 * zoom_add is the word at 0x7BC4A6. scr_sc is the float at 0x7C55F4.
 * sca_x is the dword at 0x7C55F0 and sca_y is the dword at 0x7C584C.
 * scrn_adgjust_x is the word at 0x7BC51E. scrn_adgjust_y is the word at
 * 0x7BC4EA. bg_pos is 0x7C5BA0 and fm_pos is 0x7C5620, eight entries of
 * 0x10 bytes. bg_prm is 0x7C5960 and end_prm is 0x7BC960, stride 4.
 * Screen_Switch is the word at 0x7BC988. Screen_Switch_Buffer is the word
 * at 0x7BC98A. 1.0f is 0x2190AC and 64.0f is 0x2193F0. Frame_Down's clamp
 * constant is 0x273F44.
 *
 * Frame_Adgjust's >= 0x40 path multiplies in 32 bits, shifts, masks with
 * 0xFFFF01FF, negates, and stores the low word. The < 0x40 path masks with
 * 0x1FF. The stored word matches the PS2 u16 product. Frame_Up and
 * Frame_Down are the only callers. Irl_Scrn does not emit the PS2 statements
 * that only name a shift. 0xAF47B is both Family_Set_R and Family_Set_W.
 * 0xAF4AA is both Bg_On_R and Bg_On_W. 0xAF4C2 is both Bg_Off_R and Bg_Off_W.
 * Those three stay unnamed.
 */

#include "types.h"

typedef struct {
    s16 l;
    s16 h;
} LoHi16;

typedef union {
    s32 long_pos;
    LoHi16 word_pos;
} POS_FLOAT;

typedef struct {
    POS_FLOAT scr_x;
    POS_FLOAT scr_x_buff;
    POS_FLOAT scr_y;
    POS_FLOAT scr_y_buff;
} BG_POS;

typedef struct {
    u16 bg_h_shift;
    u16 bg_v_shift;
} BackgroundParameters;

#if defined(__i386__)
_Static_assert(sizeof(LoHi16) == 4, "LoHi16");
_Static_assert(__builtin_offsetof(LoHi16, h) == 2, "LoHi16.h");
_Static_assert(sizeof(BG_POS) == 0x10, "BG_POS");
_Static_assert(__builtin_offsetof(BG_POS, scr_x_buff) == 4, "scr_x_buff");
_Static_assert(__builtin_offsetof(BG_POS, scr_y) == 8, "scr_y");
_Static_assert(__builtin_offsetof(BG_POS, scr_y_buff) == 0xC, "scr_y_buff");
_Static_assert(sizeof(BackgroundParameters) == 4, "BackgroundParameters");
_Static_assert(__builtin_offsetof(BackgroundParameters, bg_v_shift) == 2, "bg_v_shift");
#endif

extern u16 zoom_add;
extern f32 scr_sc;
extern s32 sca_x;
extern s32 sca_y;
extern s16 scrn_adgjust_x;
extern s16 scrn_adgjust_y;
extern BG_POS bg_pos[8];
extern BG_POS fm_pos[8];
extern BackgroundParameters bg_prm[8];
extern BackgroundParameters end_prm[8];
extern u16 Screen_Switch;
extern u16 Screen_Switch_Buffer;

void Zoomf_Init(void) {
    zoom_add = 64;
    scr_sc = 1.0f;
    sca_x = 0;
    sca_y = 1023;
    scrn_adgjust_x = 0;
    scrn_adgjust_y = 0;
}

void Zoom_Value_Set(u16 zadd) {
    f32 work;
    u16 add;

    if (zadd < 0x40) {
        scr_sc = 64.0f / zadd;
        return;
    }

    if (zadd == 0x40) {
        scr_sc = 1.0f;
        return;
    }

    add = (u16)(zadd & 0x3F);
    work = 1.0f / (64.0f / add);
    add = (u16)(zadd & 0xFFC0);
    add >>= 6;
    scr_sc = 1.0f / (add + work);
}

void Frame_Adgjust(u16 pos_x, u16 pos_y) {
    u16 buff;

    if (zoom_add >= 0x40) {
        buff = (u16)(zoom_add - 0x40);
        buff = (u16)(buff * pos_x);
        buff >>= 6;
        buff &= 0x1FF;
        scrn_adgjust_x = (s16)-buff;
    } else {
        buff = (u16)(0x40 - zoom_add);
        buff = (u16)(buff * pos_x);
        buff >>= 6;
        buff &= 0x1FF;
        scrn_adgjust_x = (s16)buff;
    }

    if (zoom_add >= 0x40) {
        buff = (u16)(zoom_add - 0x40);
        buff = (u16)(buff * (pos_y + 0x15));
        buff >>= 6;
        buff &= 0x1FF;
        scrn_adgjust_y = (s16)-buff;

        if (scrn_adgjust_y == -0x14) {
            scrn_adgjust_y = (s16)(scrn_adgjust_y + 1);
        }
    } else {
        buff = (u16)(0x40 - zoom_add);
        buff = (u16)(buff * (pos_y + 0x15));
        buff >>= 6;
        buff &= 0x1FF;
        scrn_adgjust_y = (s16)buff;

        if (scrn_adgjust_y == -0x14) {
            scrn_adgjust_y = (s16)(scrn_adgjust_y + 1);
        }
    }
}

void Frame_Up(u16 x, u16 y, u16 add) {
    if (zoom_add < 2) {
        scr_sc = 64.0f;
        return;
    }

    zoom_add = (u16)(zoom_add - add);
    Zoom_Value_Set(zoom_add);
    Frame_Adgjust(x, y);
}

void Frame_Down(u16 x, u16 y, u16 add) {
    if (zoom_add >= 0xFFC0) {
        scr_sc = 0.0009775171f;
        return;
    }

    zoom_add = (u16)(zoom_add + add);
    Zoom_Value_Set(zoom_add);
    Frame_Adgjust(x, y);
}

void Scrn_Pos_Init(void) {
    u8 i;

    for (i = 0; i < 8; i++) {
        bg_pos[i].scr_x.long_pos = 0;
        bg_pos[i].scr_x_buff.long_pos = 0;
        bg_pos[i].scr_y.long_pos = 0;
        bg_pos[i].scr_y_buff.long_pos = 0;
        bg_prm[i].bg_h_shift = 0;
        bg_prm[i].bg_v_shift = 0;
        end_prm[i].bg_h_shift = 0;
        end_prm[i].bg_v_shift = 0;
    }
}

void Scrn_Move_Set(s8 bgnm, s16 x, s16 y) {
    bg_pos[bgnm].scr_x.word_pos.h = x;
    bg_pos[bgnm].scr_y.word_pos.h = (s16)(y + 16);
}

void Family_Init(void) {
    u8 i;

    for (i = 0; i < 8; i++) {
        fm_pos[i].scr_x.long_pos = 0;
        fm_pos[i].scr_y.long_pos = 0;
        fm_pos[i].scr_x_buff.long_pos = 0;
        fm_pos[i].scr_y_buff.long_pos = 0;
    }
}

void Scrn_Renew(void) {
    Screen_Switch_Buffer = Screen_Switch;
}

void Irl_Family(void) {
    u8 i;

    for (i = 0; i < 8; i++) {
        fm_pos[i].scr_x_buff.long_pos = fm_pos[i].scr_x.long_pos;
        fm_pos[i].scr_y_buff.long_pos = fm_pos[i].scr_y.long_pos;
        bg_pos[i].scr_x_buff.long_pos = bg_pos[i].scr_x.long_pos;
        bg_pos[i].scr_y_buff.long_pos = bg_pos[i].scr_y.long_pos;
    }
}

void Irl_Scrn(void) {
    s8 i;

    for (i = 0; i < 8; i++) {
        bg_prm[i].bg_h_shift = (u16)(scrn_adgjust_x + bg_pos[i].scr_x_buff.word_pos.h);
        end_prm[i].bg_h_shift = (u16)(scrn_adgjust_x + fm_pos[i].scr_x_buff.word_pos.h);
        bg_prm[i].bg_v_shift = (u16)(bg_pos[i].scr_y_buff.word_pos.h - scrn_adgjust_y);
        end_prm[i].bg_v_shift = (u16)(fm_pos[i].scr_y_buff.word_pos.h - scrn_adgjust_y);
    }
}
