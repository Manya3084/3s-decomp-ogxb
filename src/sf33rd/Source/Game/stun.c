/* Stun gauge, retail sf33rd.xbe.
 * stngauge_cont_init is 0xEEB9C size 0x82 and is a scanned start.
 * stngauge_control is 0xEEC1E size 0x190 and is a scanned start.
 * stngauge_work_clear is 0xEEDAE size 0x63, interior after the ret.
 * stngauge_cont_main is 0xEEE11 size 0xA8 and is a scanned start.
 * sdat is 0x7A99E0, stride 0xA. cstn is +0, sflag is +2,
 * osflag is +3, g_or_s is +4, stimer is +5, slen is +6,
 * and proccess_dead is +8. piyori_type is 0xC7D9A0, stride 0x14.
 * flag is +0, genkai is +2, and now.quantity.h is +0xA.
 * plw is 0xC7CEA0, stride 0x46C. routine_no[1] is +0x26.
 * py is +0x3CC. dead_flag is +0x3D1. omop_st_bar_disp is 0x7C5C60.
 * omop_cockpit is 0x7C5C6C. gauge_stop_flag is 0x7A8154.
 * EXE_flag is 0xC7C834. Game_pause is 0x7A89B0. No_Trans is 0x7BD3C9.
 */

#include "types.h"
#include "structs.h"


typedef struct {
    s16 h;
} Quantity;

typedef struct {
    u8 raw[2];
    Quantity quantity;
} Now;




#if defined(__i386__)
_Static_assert(__builtin_offsetof(WORK, routine_no) == 0x24, "routine_no");
_Static_assert(sizeof(PiyoriType) == 0x14, "PiyoriType");
_Static_assert(__builtin_offsetof(PiyoriType, genkai) == 2, "genkai");
_Static_assert(__builtin_offsetof(PiyoriType, now.quantity.h) == 0xA, "quantity.h");
_Static_assert(__builtin_offsetof(PLW, py) == 0x3CC, "py");
_Static_assert(__builtin_offsetof(PLW, dead_flag) == 0x3D1, "dead_flag");
_Static_assert(sizeof(PLW) == 0x46C, "PLW");
_Static_assert(sizeof(SDAT) == 0xA, "SDAT");
_Static_assert(__builtin_offsetof(SDAT, slen) == 6, "slen");
_Static_assert(__builtin_offsetof(SDAT, proccess_dead) == 8, "proccess_dead");
#endif

extern SDAT sdat[2];
extern PiyoriType piyori_type[2];
extern PLW plw[2];
extern s16 omop_st_bar_disp[2];
extern s16 omop_cockpit;
extern u16 gauge_stop_flag[2];
extern s16 EXE_flag;
extern u8 Game_pause;
extern u8 No_Trans;

void stun_base_put(u8 Pl_Num, s16 len);
void stun_gauge_waku_write(s16 p1len, s16 p2len);
void stun_mark_write(u8 Pl_Num, s16 Len);
void stun_put(u8 Pl_Num, u8 stun);
void stngauge_control(u8 pl);

void stngauge_cont_init(void) {
    u8 i;

    for (i = 0; i < 2; i++) {
        sdat[i].cstn = 0;
        sdat[i].sflag = 0;
        sdat[i].osflag = 0;
        sdat[i].g_or_s = 0;
        sdat[i].stimer = 2;
        sdat[i].slen = (piyori_type[i].genkai / 8);
        sdat[i].proccess_dead = 0;

        if (omop_st_bar_disp[i]) {
            stun_base_put(i, sdat[i].slen);
        }
    }

    stun_gauge_waku_write(sdat->slen, sdat[1].slen);
}

void stngauge_cont_main(void) {
    u8 i;

    if (omop_cockpit != 0) {
        if (gauge_stop_flag[0] == 0) {
            stngauge_control(0);
        } else {
            stun_put(0, sdat->cstn);
        }

        if (gauge_stop_flag[1] == 0) {
            stngauge_control(1);
        } else {
            stun_put(1, sdat[1].cstn);
        }

        for (i = 0; i < 2; i++) {
            if (omop_st_bar_disp[i]) {
                stun_base_put(i, sdat[i].slen);
            }
        }

        stun_gauge_waku_write(sdat->slen, sdat[1].slen);
    }
}

void stngauge_control(u8 pl) {
    if (!sdat[pl].proccess_dead) {
        if (plw[pl].dead_flag) {
            sdat[pl].proccess_dead = 1;
            sdat[pl].cstn = 0;
            return;
        }

        if (((plw[pl].wu.routine_no[1] == 1) && (plw[pl].wu.routine_no[2] == 0x19) &&
             (plw[pl].wu.routine_no[3] != 0)) ||
            (plw[pl].py->flag == 1)) {
            sdat[pl].sflag = 1;

            if (sdat[pl].osflag == 0) {
                sdat[pl].cstn = piyori_type[pl].genkai;
            }

            if (!EXE_flag && !Game_pause) {
                sdat[pl].stimer--;
            }

            if (sdat[pl].g_or_s == 0) {
                if (No_Trans == 0) {
                    stun_mark_write(pl, sdat[pl].slen);
                    stun_put(pl, sdat[pl].cstn);
                }

                if (sdat[pl].stimer == 0) {
                    sdat[pl].g_or_s = 1;
                    sdat[pl].stimer = 2;
                }
            } else {
                if (No_Trans == 0) {
                    stun_put(pl, sdat[pl].cstn);
                }

                if (sdat[pl].stimer == 0) {
                    sdat[pl].g_or_s = 0;
                    sdat[pl].stimer = 2;
                }
            }

            sdat[pl].osflag = sdat[pl].sflag;
            return;
        }

        sdat[pl].sflag = 0;

        if (sdat[pl].osflag == 1) {
            sdat[pl].osflag = sdat[pl].sflag;
            sdat[pl].g_or_s = 0;
            sdat[pl].stimer = 2;
            sdat[pl].cstn = plw[pl].py->now.quantity.h;
            sdat[pl].osflag = sdat[pl].sflag;

            if (No_Trans == 0) {
                stun_put(pl, sdat[pl].cstn);
            }

            return;
        }

        if (sdat[pl].cstn != plw[pl].py->now.quantity.h) {
            sdat[pl].cstn = plw[pl].py->now.quantity.h;
        }

        if (No_Trans == 0) {
            stun_put(pl, sdat[pl].cstn);
        }
    }
}

void stngauge_work_clear(void) {
    sdat[0].cstn = 0;
    sdat[0].sflag = 0;
    sdat[0].osflag = 0;
    sdat[0].g_or_s = 0;
    sdat[0].stimer = 2;
    sdat[0].proccess_dead = 0;
    stun_put(0, 0);
    sdat[1].cstn = 0;
    sdat[1].sflag = 0;
    sdat[1].osflag = 0;
    sdat[1].g_or_s = 0;
    sdat[1].stimer = 2;
    sdat[1].proccess_dead = 0;
    stun_put(1, 0);
}
