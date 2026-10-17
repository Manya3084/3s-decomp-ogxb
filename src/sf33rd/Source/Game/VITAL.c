/* Vital gauge, retail sf33rd.xbe.
 * vital_cont_init is 0x9CE51 size 0x34, interior after the ret.
 * vital_parts_allwrite is 0x9CE85 size 0x85, interior after the ret.
 * vital_control is 0x9CF0A size 0xDE, interior after the ret.
 * vital_cont_main is 0x9CFE8 size 0x62, interior after the ret.
 * vit is 0x7C5C30, stride 8. cyerw is +0, cred is +2, ored is +4,
 * and colnum is +6. vital_stop_flag is 0x7A8214. gauge_stop_flag is
 * 0x7A8154. Both arrays are cleared with stosd. omop_cockpit is
 * 0x7C5C6C. EXE_flag is 0xC7C834. Game_pause is 0x7A89B0.
 * No_Trans is 0x7BD3C9. plw is 0xC7CEA0, stride 0x46C, and vital_new
 * is +0x9E. omop_vt_bar_disp is 0x7C5C68. The equal-vitals return
 * tails into vital_parts_allwrite.
 */

#include "types.h"

typedef struct {
    u8 raw[0x9E];
    s16 vital_new;
} WORK;

typedef struct {
    WORK wu;
    u8 tail[0x46C - 0xA0];
} PLW;

typedef struct {
    s16 cyerw;
    s16 cred;
    s16 ored;
    s8 colnum;
} VIT;

#if defined(__i386__)
_Static_assert(sizeof(WORK) == 0xA0, "WORK");
_Static_assert(__builtin_offsetof(WORK, vital_new) == 0x9E, "vital_new");
_Static_assert(sizeof(PLW) == 0x46C, "PLW");
_Static_assert(sizeof(VIT) == 8, "VIT");
_Static_assert(__builtin_offsetof(VIT, colnum) == 6, "colnum");
#endif

extern VIT vit[2];
extern u16 vital_stop_flag[2];
extern u16 gauge_stop_flag[2];
extern s16 omop_cockpit;
extern s16 EXE_flag;
extern u8 Game_pause;
extern u8 No_Trans;
extern PLW plw[2];
extern s16 omop_vt_bar_disp[2];

void scfont_sqput(u16 x, u16 y, u8 atr, u8 page, u8 cx1, u8 cy1, u8 cx2, u8 cy2, u16 priority);
void vital_put(u8 Pl_Num, s8 atr, s16 vital, u8 kind, u16 priority);
void silver_vital_put(u8 Pl_Num);
void vital_base_put(u8 Pl_Num);
void vital_control(u8 pl);
void vital_parts_allwrite(u8 Pl_Num);

void vital_cont_init(void) {
    u8 i;

    for (i = 0; i < 2; i++) {
        vit[i].cyerw = 0xA0;
        vit[i].cred = 0xA0;
        vit[i].ored = 0xA0;
        vit[i].colnum = 1;
        gauge_stop_flag[i] = 0;
        vital_stop_flag[i] = 0;
    }
}

void vital_cont_main(void) {
    if (omop_cockpit != 0) {
        if (!EXE_flag && !Game_pause) {
            if (vital_stop_flag[0] == 0 && gauge_stop_flag[0] == 0) {
                vital_control(0);
            }

            if (vital_stop_flag[1] == 0 && gauge_stop_flag[1] == 0) {
                vital_control(1);
            }
        } else {
            vital_parts_allwrite(0);
            vital_parts_allwrite(1);
        }
    }
}

void vital_control(u8 pl) {
    if (plw[pl].wu.vital_new < 0xA1) {
        if ((vit[pl].cyerw == plw[pl].wu.vital_new) && (vit[pl].cred == plw[pl].wu.vital_new) &&
            (vit[pl].ored != (plw[pl].wu.vital_new + 1))) {
            if (No_Trans == 0) {
                vital_parts_allwrite(pl);
            }

            return;
        }

        if (vit[pl].cred < plw[pl].wu.vital_new) {
            vit[pl].cred = plw[pl].wu.vital_new;
        }

        vit[pl].cyerw = plw[pl].wu.vital_new;

        if (plw[pl].wu.vital_new < 0) {
            vit[pl].cyerw = 0;
        }

        if (plw[pl].wu.vital_new == 0xA0) {
            vit[pl].colnum = 1;
        } else if (plw[pl].wu.vital_new < 0x31) {
            vit[pl].colnum = 3;
        } else {
            vit[pl].colnum = 2;
        }

        if (No_Trans == 0) {
            vital_parts_allwrite(pl);
        }

        vit[pl].ored = vit[pl].cred;
        vit[pl].cred--;

        if (vit[pl].cred < plw[pl].wu.vital_new) {
            vit[pl].cred = plw[pl].wu.vital_new;
        }
    }
}

void vital_parts_allwrite(u8 Pl_Num) {
    scfont_sqput((Pl_Num * 27), 2, 1, 0, Pl_Num, (Pl_Num + 30), 21, 1, 5);

    if (omop_vt_bar_disp[Pl_Num] == 0) {
        silver_vital_put(Pl_Num);
        return;
    }

    vital_put(Pl_Num, vit[Pl_Num].colnum, vit[Pl_Num].cyerw, 0, 2);
    vital_put(Pl_Num, 1, vit[Pl_Num].cred, 1, 3);
    vital_base_put(Pl_Num);
}
