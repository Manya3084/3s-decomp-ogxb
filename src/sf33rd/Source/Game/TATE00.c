/* Stage BG dispatcher, retail sf33rd.xbe.
 * ta0_init00 is 0x9CDA1 size 0xB.
 * ta0_init01 is 0x9CDAC size 0x19.
 * ta0_init02 is 0x9CDC5 size 0x14.
 * ta0_move is 0x9CDD9 size 0x31.
 * TATE00 is 0x9CE0A size 0x47.
 *
 * ta0_init00 tail-jumps to bg_initialize. ta0_init01 and ta0_init02
 * tail-jump through ta_move_tbl. TATE00 builds its four-entry table before it
 * tests Game_pause.
 * ta_move_tbl is 0x330500, 22 entries, matching the PS2 order (BG010 at
 * indexes 1 and 11, BG180 at 17 and 18). bg_w is 0x7BC520: bg_routine at +0,
 * quake_x_index at +0x1E, quake_y_index at +0x20, bg_index at +0x30.
 * Game_pause is 0x7A89B0. bg_initialize is 0xB3A32. akebono_initialize is
 * 0xB3C86. Scrn_Renew is 0xAF4DC. Irl_Family is 0xAF4E9. Irl_Scrn is 0xAF520.
 */

#include "types.h"

typedef struct {
    s8 bg_routine;
    u8 pad_q[0x1E - 1];
    s16 quake_x_index;
    s16 quake_y_index;
    u8 pad_ix[0x30 - 0x22];
    s16 bg_index;
} BG;

#if defined(__i386__)
_Static_assert(__builtin_offsetof(BG, quake_x_index) == 0x1E, "quake_x");
_Static_assert(__builtin_offsetof(BG, quake_y_index) == 0x20, "quake_y");
_Static_assert(__builtin_offsetof(BG, bg_index) == 0x30, "bg_index");
#endif

extern BG bg_w;
extern u8 Game_pause;
extern void (*const ta_move_tbl[22])(void);

void bg_initialize(void);
void akebono_initialize(void);
void Scrn_Renew(void);
void Irl_Family(void);
void Irl_Scrn(void);

void ta0_init00(void) {
    bg_w.bg_routine++;
    bg_initialize();
}

void ta0_init01(void) {
    bg_w.bg_routine++;
    akebono_initialize();
    ta_move_tbl[bg_w.bg_index]();
}

void ta0_init02(void) {
    bg_w.bg_routine++;
    ta_move_tbl[bg_w.bg_index]();
}

void ta0_move(void) {
    ta_move_tbl[bg_w.bg_index]();

    if (bg_w.quake_x_index > 0) {
        bg_w.quake_x_index--;
    }

    if (bg_w.quake_y_index > 0) {
        bg_w.quake_y_index--;
    }
}

void TATE00(void) {
    void (*jump_tbl[4])(void) = { ta0_init00, ta0_init01, ta0_init02, ta0_move };

    if (Game_pause & 0x80) {
        return;
    }

    jump_tbl[bg_w.bg_routine]();
    Scrn_Renew();
    Irl_Family();
    Irl_Scrn();
}
