/* Super arts gauge, retail sf33rd.xbe.
 * sag_bug_fix is 0xEC8EB size 0x1C. satime_ko_after_clear is 0xEC907
 * size 0x82. sa_time_moji_send is 0xEC989 size 0xAC. sast_color_chenge
 * is 0xECA35 size 0x88. sa_color_chenge is 0xECABD size 0x43.
 * sagauge_color_chenge is 0xECB00 size 0x17C. sa_gauge_trans is 0xECC7C
 * size 0xED. spgauge_sound_request is 0xECD69 size 0x34.
 * spgauge_work_clear is 0xECD9D size 0xF1. sa_waku_trans is 0xECE8E
 * size 0x164. tr_spgauge_cont_init is 0xECFF2 size 0x1D3.
 * spgauge_cont_init is 0xED1C5 size 0x193. sa_moji_trans is 0xED358
 * size 0x12D. spgauge_wipe_write is 0xED485 size 0x3B.
 * tr_spgauge_cont_init2 is 0xED4C0 size 0x200. spgauge_cont_demo_init
 * is 0xED6C0 size 0x1C7. wipe_check is 0xED887 size 0x120.
 * samoji_control is 0xED9A7 size 0x146. sast_control is 0xEDAED size
 * 0x5AA. spgauge_control is 0xEE309 size 0x29F. spgauge_cont_main is
 * 0xEE5A8 size 0xA1.
 * spg_dat is 0x7A9A20, stride 0x34. super_arts is 0xC7D940, stride 0x2C.
 * plw is 0xC7CEA0, stride 0x46C, and sa is +0x3C4. sa_gauge_flash is
 * 0x7A820E. time_flag is 0x7A9A88. time_num is 0x7A9A8A. sast_now is
 * 0x7A9A8C. col is 0x7A9A8E. spg_work is 0x7A9A90. Exec_Wipe_F is
 * 0x7A9A92. spg_offset is 0x7A9A94. time_clear is 0x7A9A96.
 * time_operate is 0x7A9A98. max2 is 0x7A9A9A. time_timer is 0x7A9A9C.
 * max_rno2 is 0x7A99FC. Old_Stop_SG is 0x7A99FE. spg_number is 0x7A9A00.
 * sa_time_data_tbl is 0x2AEFD4. sa_color_data2_tbl is 0x2AEFEC.
 * sagauge_colchg_tbl is 0x2AEFF8. spgauge_tbl is 0x2AEF80.
 * spg1p_npos_tbl is 0x2AEF94. spg2p_npos_tbl is 0x2AEFB4.
 * spgauge_puttbl is 0x333074. spgauge_postbl is 0x33307C.
 * Those tables match the PlayStation 2 bytes. Stop_SG is 0x7A8428.
 * Exec_Wipe is 0x7A82F9. Conclusion_Flag is 0x7A88D4. gauge_stop_flag
 * is 0x7A8154. Game_pause is 0x7A89B0. EXE_flag is 0xC7C834. cmd_sel is
 * 0xC7D9D0. no_sa is 0xC7D9D6. My_char is 0x7A8114. omop_use_ex_gauge_ix
 * is 0x7C5CCC. Sound_SE stays BGM_Request. demo_set_sa_full stays
 * demo_set_sa_full. 0xEE097 size 0x272 stays unnamed: Stop_SG returns there
 * without wipe_check, and time_timer is not decremented.
 * 0xEE649 size 0x2B and 0xEE674 size 0x56 are check_shortcut and
 * set_credit_string.
 * sa_waku_trans, tr_spgauge_cont_init, spgauge_cont_init,
 * sa_moji_trans, tr_spgauge_cont_init2, spgauge_cont_demo_init,
 * sast_control, spgauge_control, and spgauge_cont_main are
 * scanned starts. sag_bug_fix, satime_ko_after_clear,
 * sa_time_moji_send, sast_color_chenge, sa_color_chenge,
 * sagauge_color_chenge, sa_gauge_trans, spgauge_sound_request,
 * spgauge_work_clear, spgauge_wipe_write, wipe_check, and
 * samoji_control are interior.
 */

#include "types.h"

typedef struct {
    s16 l;
    s16 h;
} LoHi16;

typedef struct {
    s16 kind_of_arts;
    u8 nmsa_g_ix;
    u8 exsa_g_ix;
    u8 exs2_g_ix;
    u8 nmsa_a_ix;
    u8 exsa_a_ix;
    u8 exs2_a_ix;
    s8 gauge_type;
    s8 mp;
    s8 ok;
    s8 ex;
    s8 ba;
    s8 dtm_mul;
    s8 mp_rno;
    s8 mp_rno2;
    s8 sa_rno;
    s8 sa_rno2;
    s8 ex_rno;
    s8 gt2;
    s8 saeff_ok;
    s8 saeff_mp;
    s16 gauge_len;
    union {
        s32 i;
        LoHi16 s;
    } gauge;
    s32 dtm;
    s16 store_max;
    s16 store;
    s16 id_arts;
    u8 ex4th_full;
    u8 ex4th_exec;
    s16 total_gauge;
    s16 bacckup_g_h;
} SA_WORK;

typedef struct {
    u8 raw[0x3C4];
    SA_WORK *sa;
    u8 rest[0xA4];
} PLW;

typedef struct {
    const u16 *spgtbl_ptr;
    const u16 *spgptbl_ptr;
    s16 current_spg;
    s16 old_spg;
    s16 spgcol_number;
    s16 spg_level;
    s16 spg_maxlevel;
    s16 spg_len;
    s16 spg_dotlen;
    s16 flag;
    s16 flag2;
    s16 level_flag;
    s16 timer;
    s16 timer2;
    s8 kind;
    s8 max;
    s8 max_old;
    s8 max_rno;
    s8 time;
    s8 time_rno;
    s16 gauge_flash_time;
    s16 gauge_flash_col;
    u16 mchar;
    u16 mass_len;
    s8 sa_flag;
    s8 ex_flag;
    s8 no_chgcol;
    s8 time_no_clear;
    s8 sa_mukou;
} SPG_DAT;

#if defined(__i386__)
_Static_assert(sizeof(SA_WORK) == 0x2C, "SA_WORK");
_Static_assert(__builtin_offsetof(SA_WORK, gauge_type) == 8, "gauge_type");
_Static_assert(__builtin_offsetof(SA_WORK, mp) == 9, "mp");
_Static_assert(__builtin_offsetof(SA_WORK, ok) == 0xA, "ok");
_Static_assert(__builtin_offsetof(SA_WORK, ex) == 0xB, "ex");
_Static_assert(__builtin_offsetof(SA_WORK, gt2) == 0x13, "gt2");
_Static_assert(__builtin_offsetof(SA_WORK, gauge_len) == 0x16, "gauge_len");
_Static_assert(__builtin_offsetof(SA_WORK, gauge.s.h) == 0x1A, "gauge.s.h");
_Static_assert(__builtin_offsetof(SA_WORK, store_max) == 0x20, "store_max");
_Static_assert(__builtin_offsetof(SA_WORK, store) == 0x22, "store");
_Static_assert(__builtin_offsetof(SA_WORK, bacckup_g_h) == 0x2A, "bacckup");
_Static_assert(sizeof(PLW) == 0x46C, "PLW");
_Static_assert(__builtin_offsetof(PLW, sa) == 0x3C4, "sa");
_Static_assert(sizeof(SPG_DAT) == 0x34, "SPG_DAT");
_Static_assert(__builtin_offsetof(SPG_DAT, current_spg) == 8, "current_spg");
_Static_assert(__builtin_offsetof(SPG_DAT, spgcol_number) == 0xC, "spgcol");
_Static_assert(__builtin_offsetof(SPG_DAT, spg_level) == 0xE, "spg_level");
_Static_assert(__builtin_offsetof(SPG_DAT, spg_maxlevel) == 0x10, "spg_max");
_Static_assert(__builtin_offsetof(SPG_DAT, spg_len) == 0x12, "spg_len");
_Static_assert(__builtin_offsetof(SPG_DAT, spg_dotlen) == 0x14, "dotlen");
_Static_assert(__builtin_offsetof(SPG_DAT, flag) == 0x16, "flag");
_Static_assert(__builtin_offsetof(SPG_DAT, timer) == 0x1C, "timer");
_Static_assert(__builtin_offsetof(SPG_DAT, timer2) == 0x1E, "timer2");
_Static_assert(__builtin_offsetof(SPG_DAT, kind) == 0x20, "kind");
_Static_assert(__builtin_offsetof(SPG_DAT, max) == 0x21, "max");
_Static_assert(__builtin_offsetof(SPG_DAT, max_old) == 0x22, "max_old");
_Static_assert(__builtin_offsetof(SPG_DAT, max_rno) == 0x23, "max_rno");
_Static_assert(__builtin_offsetof(SPG_DAT, time) == 0x24, "time");
_Static_assert(__builtin_offsetof(SPG_DAT, time_rno) == 0x25, "time_rno");
_Static_assert(__builtin_offsetof(SPG_DAT, gauge_flash_time) == 0x26, "flash_time");
_Static_assert(__builtin_offsetof(SPG_DAT, gauge_flash_col) == 0x28, "flash_col");
_Static_assert(__builtin_offsetof(SPG_DAT, mchar) == 0x2A, "mchar");
_Static_assert(__builtin_offsetof(SPG_DAT, mass_len) == 0x2C, "mass_len");
_Static_assert(__builtin_offsetof(SPG_DAT, sa_flag) == 0x2E, "sa_flag");
_Static_assert(__builtin_offsetof(SPG_DAT, ex_flag) == 0x2F, "ex_flag");
_Static_assert(__builtin_offsetof(SPG_DAT, no_chgcol) == 0x30, "no_chgcol");
_Static_assert(__builtin_offsetof(SPG_DAT, time_no_clear) == 0x31, "time_no_clear");
_Static_assert(__builtin_offsetof(SPG_DAT, sa_mukou) == 0x32, "sa_mukou");
#endif

extern SPG_DAT spg_dat[2];
extern SA_WORK super_arts[2];
extern PLW plw[2];
extern s8 sa_gauge_flash[2];
extern s8 time_flag[2];
extern s8 time_num;
extern s8 time_timer;
extern s8 time_operate[2];
extern s8 time_clear[2];
extern s8 sast_now[2];
extern s8 max2[2];
extern s8 max_rno2[2];
extern s8 Old_Stop_SG;
extern s8 Exec_Wipe_F;
extern s8 Exec_Wipe;
extern s8 Stop_SG;
extern s16 col;
extern s16 spg_number;
extern s16 spg_work;
extern s16 spg_offset;
extern u8 Game_pause;
extern s16 EXE_flag;
extern u16 gauge_stop_flag[2];
extern u8 Conclusion_Flag;
extern u8 My_char[2];
extern s16 omop_use_ex_gauge_ix[2];
extern u8 cmd_sel[2];
extern u8 no_sa[2];
extern const u16 sa_time_data_tbl[6][2];
extern const u16 sa_color_data2_tbl[3][2];
extern const u16 sagauge_colchg_tbl[4][2];
extern const u16 *spgauge_puttbl[2];
extern const u16 *spgauge_postbl[2];

void scfont_put2(u16 x, u16 y, u8 atr, u8 page, u8 cx, u8 cy);
void scfont_sqput2(u16 x, u16 y, u8 atr, u8 inverse, u8 page, u8 cx1, u8 cy1, u8 cx2, u8 cy2);
void sc_clear(u16 sposx, u16 sposy, u16 eposx, u16 eposy);
void max_mark_write(s8 Pl_Num, u8 Gauge_Len, u8 Mchar, u8 Mass_Len);
void sa_stock_trans(s16 St_Num, s16 Spg_Col, s8 Stpl_Num);
void sa_fullstock_trans(s16 St_Num, s16 Spg_Col, s8 Stpl_Num);
void sa_number_write(s8 Stpl_Num, u16 x);
void sq_paint_chenge(u16 x, u16 y, u16 sx, u16 sy, u16 atr);
void spgauge_base_put(u8 Pl_Num, s16 len);
void Sa_frame_Clear(void);
void Sa_frame_Clear2(u8 pl);
void sc_ram_to_vram(s8 sc_num);
void demo_set_sa_full(SA_WORK *sa);
void sub_00098407(s16 code);

void spgauge_control(s8 Spg_Num);
void wipe_check(void);
void satime_ko_after_clear(s8 Stpl_Num);
void sa_time_moji_send(void);
void samoji_control(s8 Stpl_Num);
void sast_control(s8 Stpl_Num);
void sast_color_chenge(s8 Stpl_Num);
void sa_color_chenge(s8 Stpl_Num);
void sagauge_color_chenge(s8 Stpl_Num);
void sa_moji_trans(s8 Stpl_Num, s8 Kind, s8 OnOff);
void sa_gauge_trans(s8 pl_kind);
void spgauge_sound_request(s8 Stpl_Num);
void spgauge_work_clear(s8 Stpl_Num);
void spgauge_wipe_write(s8 Stpl_Num);
void sa_waku_trans(s8 Stpl_Num, s8 Spg_Col);

void spgauge_cont_init(void) {
    s8 lpy;

    Sa_frame_Clear();

    for (lpy = 0; lpy < 2; lpy++) {
        spg_dat[lpy].current_spg = 0;
        spg_dat[lpy].old_spg = 0;
        spg_dat[lpy].spgtbl_ptr = spgauge_puttbl[lpy];
        spg_dat[lpy].spg_level = 0;
        spg_dat[lpy].spg_maxlevel = super_arts[lpy].store_max;
        spg_dat[lpy].spg_len = super_arts[lpy].gauge_len / 8;
        spg_dat[lpy].spg_dotlen = super_arts[lpy].gauge_len;
        spg_dat[lpy].flag = 0;
        spg_dat[lpy].flag2 = 0;
        spg_dat[lpy].level_flag = 0;
        spg_dat[lpy].timer = 51;
        spg_dat[lpy].timer2 = 2;
        spg_dat[lpy].kind = 0;
        spg_dat[lpy].max = 0;
        spg_dat[lpy].max_old = 0;
        spg_dat[lpy].max_rno = 0;
        spg_dat[lpy].time_rno = 0;
        spg_dat[lpy].gauge_flash_time = 2;
        spg_dat[lpy].gauge_flash_col = 0;
        spg_dat[lpy].sa_flag = 0;
        spg_dat[lpy].ex_flag = 0;
        spg_dat[lpy].no_chgcol = 0;
        spg_dat[lpy].time_no_clear = 0;
        spg_dat[lpy].sa_mukou = 0;
        sa_gauge_flash[lpy] = 0;
        spg_dat[lpy].spgptbl_ptr = spgauge_postbl[lpy];

        if (super_arts[lpy].gauge_type == 1) {
            spg_dat[lpy].time = 1;
            time_flag[lpy] = 1;
        } else {
            spg_dat[lpy].time = 0;
            time_flag[lpy] = 0;
        }

        spg_dat[lpy].mass_len = spg_dat[lpy].spg_len - 5;

        if (spg_dat[lpy].spg_len & 1) {
            spg_dat[lpy].mchar = 5;
        } else {
            spg_dat[lpy].mass_len = spg_dat[lpy].mass_len - 1;
            spg_dat[lpy].mchar = 6;
        }

        spg_dat[lpy].mass_len /= 2;
        time_operate[lpy] = 0;
        sast_now[lpy] = 0;
        max2[lpy] = 0;
        max_rno2[lpy] = 0;
    }

    spg_dat[0].spgcol_number = 17;
    spg_dat[1].spgcol_number = 145;
    sa_stock_trans(0, 0, 0);
    sa_stock_trans(0, 0, 1);
    sa_waku_trans(0, 0);
    sa_waku_trans(1, 0);
    sa_gauge_trans(0);
    sa_gauge_trans(1);
    Old_Stop_SG = 0;
    Exec_Wipe_F = 0;
    time_clear[0] = 0;
    time_clear[1] = 0;
    spg_offset = 0;
    time_num = 0;
    time_timer = 3;
    col = 0;
}

void spgauge_cont_demo_init(void) {
    s8 lpy;

    Sa_frame_Clear();

    for (lpy = 0; lpy < 2; lpy++) {
        demo_set_sa_full(&super_arts[lpy]);
        spg_dat[lpy].current_spg = super_arts[lpy].gauge_len;
        spg_dat[lpy].old_spg = super_arts[lpy].gauge_len;
        spg_dat[lpy].spgtbl_ptr = spgauge_puttbl[lpy];
        spg_dat[lpy].spg_level = super_arts[lpy].store;
        spg_dat[lpy].spg_maxlevel = super_arts[lpy].store_max;
        spg_dat[lpy].spg_len = super_arts[lpy].gauge_len / 8;
        spg_dat[lpy].spg_dotlen = super_arts[lpy].gauge_len;
        spg_dat[lpy].flag = 1;
        spg_dat[lpy].flag2 = 0;
        spg_dat[lpy].level_flag = 0;
        spg_dat[lpy].timer = 51;
        spg_dat[lpy].timer2 = 2;
        spg_dat[lpy].kind = 1;
        spg_dat[lpy].max = 0;
        spg_dat[lpy].max_old = 1;
        spg_dat[lpy].max_rno = 2;
        spg_dat[lpy].time_rno = 5;
        spg_dat[lpy].gauge_flash_time = 2;
        spg_dat[lpy].gauge_flash_col = 0;
        spg_dat[lpy].sa_flag = 0;
        spg_dat[lpy].ex_flag = 0;
        spg_dat[lpy].no_chgcol = 0;
        spg_dat[lpy].time_no_clear = 0;
        spg_dat[lpy].sa_mukou = 0;
        sa_gauge_flash[lpy] = 0;
        spg_dat[lpy].spgptbl_ptr = spgauge_postbl[lpy];

        if (super_arts[lpy].gauge_type == 1) {
            spg_dat[lpy].time = 1;
            time_flag[lpy] = 1;
        } else {
            spg_dat[lpy].time = 0;
            time_flag[lpy] = 0;
        }

        spg_dat[lpy].mass_len = spg_dat[lpy].spg_len - 5;

        if (spg_dat[lpy].spg_len & 1) {
            spg_dat[lpy].mchar = 5;
        } else {
            spg_dat[lpy].mass_len = spg_dat[lpy].mass_len - 1;
            spg_dat[lpy].mchar = 6;
        }

        spg_dat[lpy].mass_len /= 2;
        time_operate[lpy] = 0;
        sast_now[lpy] = 0;
        max2[lpy] = 0;
        max_rno2[lpy] = 0;
    }

    spg_dat[0].spgcol_number = 17;
    spg_dat[1].spgcol_number = 145;
    sa_stock_trans(spg_dat[0].spg_maxlevel, 1, 0);
    sa_stock_trans(spg_dat[1].spg_maxlevel, 1, 1);
    sa_waku_trans(0, 1);
    sa_waku_trans(1, 1);
    sa_gauge_trans(0);
    sa_gauge_trans(1);
    sa_moji_trans(0, 0, 1);
    sa_moji_trans(1, 0, 1);
    Old_Stop_SG = 0;
    Exec_Wipe_F = 0;
    time_clear[0] = 0;
    time_clear[1] = 0;
    spg_offset = 0;
    time_num = 0;
    time_timer = 3;
    col = 1;
}

void spgauge_cont_main(void) {
    u8 i;

    for (i = 0; i < 2; i++) {
        spgauge_base_put(i, spg_dat[i].spg_len);
    }

    if ((Game_pause & 0x80) || EXE_flag) {
        return;
    }

    if (Stop_SG) {
        wipe_check();
        Old_Stop_SG = Stop_SG;
        return;
    }

    if (Old_Stop_SG) {
        Old_Stop_SG = 0;
        Exec_Wipe_F = 0;
        time_clear[0] = 0;
        time_clear[1] = 0;
    }

    sa_time_moji_send();

    if (gauge_stop_flag[0] == 0) {
        spgauge_control(0);
    }

    if (gauge_stop_flag[1] == 0) {
        spgauge_control(1);
    }
}

void sag_bug_fix(s32 side) {
    spg_dat[side].max = spg_dat[side].max_old = spg_dat[side].max_rno = 0;
}

void spgauge_control(s8 Spg_Num) {
    if (sa_gauge_flash[Spg_Num] != 0 && plw[Spg_Num].sa->ex == -1) {
        spgauge_sound_request(Spg_Num);

        if (Conclusion_Flag != 0) {
            spg_dat[Spg_Num].sa_mukou = 1;
        }

        spg_dat[Spg_Num].max = 0;
        spg_dat[Spg_Num].max_rno = 0;
        spg_dat[Spg_Num].flag = 1;
        spg_dat[Spg_Num].flag2 = 1;
        spg_dat[Spg_Num].time_rno = 0;
        spg_dat[Spg_Num].timer2 = 2;
        spg_dat[Spg_Num].kind = 0;
        spg_dat[Spg_Num].no_chgcol = 0;
        spg_dat[Spg_Num].ex_flag = 1;
        spg_dat[Spg_Num].timer = 16;
        sa_gauge_flash[Spg_Num] &= ~2;
    } else if (sast_now[Spg_Num] == 0 && spg_dat[Spg_Num].flag2 == 0 && sa_gauge_flash[Spg_Num] != 0) {
        spgauge_sound_request(Spg_Num);

        if (super_arts[Spg_Num].gt2 == 1) {
            spg_dat[Spg_Num].time = 1;
            time_flag[Spg_Num] = 1;
        } else {
            spg_dat[Spg_Num].time = 0;
            time_flag[Spg_Num] = 0;
        }

        if (plw[Spg_Num].sa->store == plw[Spg_Num].sa->store_max && spg_dat[Spg_Num].max_old == 0 &&
            spg_dat[Spg_Num].max == 0) {
            spg_dat[Spg_Num].max = 1;
        } else {
            spg_dat[Spg_Num].max = 0;
        }

        spg_dat[Spg_Num].flag = 1;
        spg_dat[Spg_Num].flag2 = 1;
        spg_dat[Spg_Num].max_rno = 0;
        spg_dat[Spg_Num].time_rno = 0;
        spg_dat[Spg_Num].timer2 = 2;
        spg_dat[Spg_Num].kind = 0;
        spg_dat[Spg_Num].no_chgcol = 0;

        if (plw[Spg_Num].sa->ok == -1 || plw[Spg_Num].sa->mp == -1) {
            spg_dat[Spg_Num].sa_flag = 1;
            spg_dat[Spg_Num].timer = 51;

            if (Conclusion_Flag != 0) {
                if ((spg_dat[Spg_Num].time) == 1) {
                    spg_dat[Spg_Num].time_no_clear = 1;
                }

                if (My_char[Spg_Num] == 0 && ((plw[Spg_Num].sa->ok) == -1)) {
                    spg_dat[Spg_Num].sa_mukou = 0;
                } else {
                    spg_dat[Spg_Num].sa_mukou = 1;
                }
            }

            sa_gauge_flash[Spg_Num] &= ~4;
        } else {
            spg_dat[Spg_Num].timer = 25;
            sa_gauge_flash[Spg_Num] &= ~1;
        }
    }

    if (spg_dat[Spg_Num].max) {
        samoji_control(Spg_Num);
    } else if (spg_dat[Spg_Num].flag) {
        sast_control(Spg_Num);
    }

    if ((plw[Spg_Num].sa->ex != 0 || spg_dat[Spg_Num].ex_flag == 1 || spg_dat[Spg_Num].sa_flag == 1) && !Game_pause) {
        sagauge_color_chenge(Spg_Num);
    }

    if (spg_dat[Spg_Num].current_spg != plw[Spg_Num].sa->gauge.s.h || spg_dat[Spg_Num].max != 0) {
        if (spg_dat[Spg_Num].max) {
            spg_dat[Spg_Num].current_spg = spg_dat[Spg_Num].spg_dotlen;
        } else {
            spg_dat[Spg_Num].current_spg = plw[Spg_Num].sa->gauge.s.h;
        }

        if (max2[Spg_Num] != 1 && spg_dat[Spg_Num].max == 0 && spg_dat[Spg_Num].flag == 0 &&
            spg_dat[Spg_Num].max_old == 0 && spg_dat[Spg_Num].time_no_clear == 0) {
            sa_gauge_trans(Spg_Num);
        }
    }
}

void wipe_check(void) {
    if (Old_Stop_SG) {
        if (Exec_Wipe != 0) {
            return;
        }

        if (Exec_Wipe_F != 0) {
            return;
        }

        Exec_Wipe_F = 1;

        if (spg_dat[0].time == 1 && time_clear[0] == 1) {
            if (spg_dat[0].time_no_clear == 0) {
                spgauge_work_clear(0);
                sc_clear(1, 25, 4, 26);
                sast_color_chenge(0);
                spgauge_wipe_write(0);
            } else {
                satime_ko_after_clear(0);
            }
        }

        if (spg_dat[1].time == 1 && time_clear[1] == 1) {
            if (spg_dat[1].time_no_clear == 0) {
                spgauge_work_clear(1);
                sc_clear(43, 25, 46, 26);
                sast_color_chenge(1);
                spgauge_wipe_write(1);
            } else {
                satime_ko_after_clear(1);
            }
        }

    } else {
        if (spg_dat[0].time_no_clear == 1 || plw[0].sa->ok == -1) {
            plw[0].sa->ok = 0;
            time_clear[0] = 1;
            spg_dat[0].spg_level = plw[0].sa->store;
        }

        if (spg_dat[1].time_no_clear == 1 || plw[1].sa->ok == -1) {
            plw[1].sa->ok = 0;
            time_clear[1] = 1;
            spg_dat[1].spg_level = plw[1].sa->store;
        }
    }
}

void satime_ko_after_clear(s8 Stpl_Num) {
    spg_dat[Stpl_Num].max = 0;

    if (plw[Stpl_Num].sa->store == spg_dat[Stpl_Num].spg_maxlevel) {
        spg_dat[Stpl_Num].max_old = 1;
        spg_dat[Stpl_Num].max_rno = 2;
    } else {
        spg_dat[Stpl_Num].max_old = 0;
        spg_dat[Stpl_Num].max_rno = 0;
    }

    spg_dat[Stpl_Num].kind = 1;
    spg_dat[Stpl_Num].timer2 = 2;
    spg_dat[Stpl_Num].time_rno = 5;
    spg_dat[Stpl_Num].time_no_clear = 0;
    plw[Stpl_Num].sa->gauge.s.h = spg_dat[Stpl_Num].current_spg = plw[Stpl_Num].sa->bacckup_g_h;
    plw[Stpl_Num].sa->bacckup_g_h = 0;
}

void sa_time_moji_send(void) {
    if (time_flag[0] == 0 && time_flag[1] == 0) {
        return;
    }

    time_timer--;

    if (time_timer != 0) {
        return;
    }

    if (time_flag[0] == 1 && time_operate[0] == 1) {
        scfont_sqput2(1, 25, 11, 0, 2, sa_time_data_tbl[time_num][0], 0, 4, 2);
    }

    if (time_flag[1] == 1 && time_operate[1] == 1) {
        scfont_sqput2(43, 25, 11, 0, 2, sa_time_data_tbl[time_num][1], 0, 4, 2);
    }

    time_timer = 3;

    if (time_num == 5) {
        time_num = 0;
        return;
    }

    time_num++;
}

void samoji_control(s8 Stpl_Num) {
    switch (spg_dat[Stpl_Num].max_rno) {
    case 0:
        max2[Stpl_Num] = 0;
        max_rno2[Stpl_Num] = 1;
        sa_moji_trans(Stpl_Num, 0, 1);
        spg_dat[Stpl_Num].spg_level = plw[Stpl_Num].sa->store;
        sa_stock_trans(spg_dat[Stpl_Num].spg_level, 1, Stpl_Num);
        sa_waku_trans(Stpl_Num, 1);
        sagauge_color_chenge(Stpl_Num);
        spg_dat[Stpl_Num].max_rno = 1;
        break;

    case 1:
        spg_dat[Stpl_Num].timer--;

        if (spg_dat[Stpl_Num].timer) {
            spg_dat[Stpl_Num].timer2--;

            if (spg_dat[Stpl_Num].timer2 != 0) {
                break;
            }

            spg_dat[Stpl_Num].kind++;

            if (spg_dat[Stpl_Num].kind == 3) {
                spg_dat[Stpl_Num].kind = 0;
            }

            sa_waku_trans(Stpl_Num, spg_dat[Stpl_Num].kind);
            sa_stock_trans(spg_dat[Stpl_Num].spg_level, spg_dat[Stpl_Num].kind, Stpl_Num);
            spg_dat[Stpl_Num].timer2 = 1;
        } else {
            sa_waku_trans(Stpl_Num, 1);
            sa_stock_trans(spg_dat[Stpl_Num].spg_level, 1, Stpl_Num);
            spg_dat[Stpl_Num].max = 0;
            spg_dat[Stpl_Num].max_old = 1;
            spg_dat[Stpl_Num].kind = 1;
            spg_dat[Stpl_Num].timer2 = 2;
            spg_dat[Stpl_Num].max_rno = 2;
            spg_dat[Stpl_Num].time_rno = 5;
            spg_dat[Stpl_Num].flag2 = 0;
            max_rno2[Stpl_Num] = 0;
        }

        break;

    case 2:
        break;
    }
}

void sast_control(s8 Stpl_Num) {
    sast_now[Stpl_Num] = 1;

    if (spg_dat[Stpl_Num].time) {
        switch (spg_dat[Stpl_Num].time_rno) {
        case 0:
            if (plw[Stpl_Num].sa->ok == -1) {
                spg_dat[Stpl_Num].time_rno = 1;
            } else {
                if (plw[Stpl_Num].sa->store > spg_dat[Stpl_Num].spg_level) {
                    spg_dat[Stpl_Num].current_spg = spg_dat[Stpl_Num].spg_dotlen;
                    sa_gauge_trans(Stpl_Num);
                    spg_dat[Stpl_Num].spg_level = plw[Stpl_Num].sa->store;
                    sa_stock_trans(spg_dat[Stpl_Num].spg_level, col, Stpl_Num);
                }

                spg_dat[Stpl_Num].time_rno = 3;
                goto case_3;
            }

            /* fallthrough */

        case 1:
            spg_dat[Stpl_Num].timer--;

            if ((!spg_dat[Stpl_Num].sa_mukou || spg_dat[Stpl_Num].timer != 0) &&
                (spg_dat[Stpl_Num].spg_level == plw[Stpl_Num].sa->store)) {
                spg_dat[Stpl_Num].timer2--;

                if (spg_dat[Stpl_Num].kind == 0) {
                    if (spg_dat[Stpl_Num].timer2 == 0) {
                        sa_stock_trans(spg_dat[Stpl_Num].spg_level, 0, Stpl_Num);
                        sa_waku_trans(Stpl_Num, 0);
                        spg_dat[Stpl_Num].kind = 1;
                        spg_dat[Stpl_Num].timer2 = 2;
                    }
                } else if (spg_dat[Stpl_Num].timer2 == 0) {
                    sa_stock_trans(spg_dat[Stpl_Num].spg_level, 1, Stpl_Num);
                    sa_waku_trans(Stpl_Num, 1);
                    spg_dat[Stpl_Num].kind = 0;
                    spg_dat[Stpl_Num].timer2 = 2;
                }

                return;
            }

            if (spg_dat[Stpl_Num].sa_flag != 0 && spg_dat[Stpl_Num].sa_mukou == 0) {
                sa_waku_trans(Stpl_Num, 1);
                sa_moji_trans(Stpl_Num, 1, 1);
                time_operate[Stpl_Num] = 1;
                sast_color_chenge(Stpl_Num);
                spg_dat[Stpl_Num].time_rno = 2;
                spg_dat[Stpl_Num].no_chgcol = 1;

                spg_dat[Stpl_Num].current_spg = spg_dat[Stpl_Num].spg_dotlen;
                sa_gauge_trans(Stpl_Num);
                return;
            }

            goto jump;

        case 2:
            if (spg_dat[Stpl_Num].current_spg > 0 && plw[Stpl_Num].sa->ok == -1) {
                if (spg_dat[Stpl_Num].current_spg != spg_dat[Stpl_Num].old_spg) {
                    sa_gauge_trans(Stpl_Num);
                }

                spg_dat[Stpl_Num].old_spg = spg_dat[Stpl_Num].current_spg;
            } else {
                spg_dat[Stpl_Num].time_rno = 4;
            }

            return;

        case 3:
        case_3:
            spg_dat[Stpl_Num].timer--;

            if (spg_dat[Stpl_Num].timer) {
                spg_dat[Stpl_Num].timer2--;

                if (spg_dat[Stpl_Num].kind == 0) {
                    if (spg_dat[Stpl_Num].timer2 == 0) {
                        sa_stock_trans(spg_dat[Stpl_Num].spg_level, 0, Stpl_Num);
                        sa_waku_trans(Stpl_Num, 0);
                        spg_dat[Stpl_Num].kind = 1;
                        spg_dat[Stpl_Num].timer2 = 2;
                    }
                } else {
                    if (spg_dat[Stpl_Num].timer2 == 0) {
                        sa_stock_trans(spg_dat[Stpl_Num].spg_level, 1, Stpl_Num);
                        sa_waku_trans(Stpl_Num, 1);
                        spg_dat[Stpl_Num].kind = 0;
                        spg_dat[Stpl_Num].timer2 = 2;
                    }
                }

                return;
            }

            if ((spg_dat[Stpl_Num].ex_flag == 1 && omop_use_ex_gauge_ix[Stpl_Num] == 0) &&
                (spg_dat[Stpl_Num].max_old == 1 || max_rno2[Stpl_Num] == 1)) {
                break;
            }

            if (plw[Stpl_Num].sa->store == plw[Stpl_Num].sa->store_max) {
                max2[Stpl_Num] = 1;
            }

            if (spg_dat[Stpl_Num].sa_mukou == 1) {
                max2[Stpl_Num] = 0;
            }

            spg_dat[Stpl_Num].time_rno = 4;
            /* fallthrough */

        case 4:
            if (spg_dat[Stpl_Num].sa_mukou == 0) {
                sa_moji_trans(Stpl_Num, 1, 0);
                spg_dat[Stpl_Num].max_old = 0;
            }

        jump:
            time_operate[Stpl_Num] = 0;
            sast_color_chenge(Stpl_Num);
            spg_dat[Stpl_Num].spg_level = plw[Stpl_Num].sa->store;
            sa_stock_trans(spg_dat[Stpl_Num].spg_level, col, Stpl_Num);
            sa_waku_trans(Stpl_Num, col);

            if (max2[Stpl_Num] == 0 && spg_dat[Stpl_Num].sa_mukou == 0) {
                sa_gauge_trans(Stpl_Num);
            }

            spg_dat[Stpl_Num].flag = 0;
            spg_dat[Stpl_Num].time_rno = 5;
            spg_dat[Stpl_Num].max_rno = 0;
            spg_dat[Stpl_Num].sa_flag = 0;
            spg_dat[Stpl_Num].ex_flag = 0;
            spg_dat[Stpl_Num].no_chgcol = 0;
            spg_dat[Stpl_Num].sa_mukou = 0;

            spg_dat[Stpl_Num].flag2 = 0;
            sast_now[Stpl_Num] = 0;
            return;

        default:
        case 5:
            sast_now[Stpl_Num] = 0;
            return;
        }

        sast_color_chenge(Stpl_Num);
        sa_stock_trans(spg_dat[Stpl_Num].spg_level, col, Stpl_Num);
        sa_waku_trans(Stpl_Num, col);

        spg_dat[Stpl_Num].flag = 1;
        spg_dat[Stpl_Num].time_rno = 5;
        spg_dat[Stpl_Num].max_old = 1;
        spg_dat[Stpl_Num].max_rno = 2;
        spg_dat[Stpl_Num].sa_flag = 0;
        spg_dat[Stpl_Num].ex_flag = 0;
        spg_dat[Stpl_Num].no_chgcol = 0;
        spg_dat[Stpl_Num].sa_mukou = 0;
        spg_dat[Stpl_Num].flag2 = 0;
        max2[Stpl_Num] = 0;
        max_rno2[Stpl_Num] = 0;
        sast_now[Stpl_Num] = 0;
        return;
    }

    switch (spg_dat[Stpl_Num].max_rno) {
    case 0:
        if (plw[Stpl_Num].sa->store > spg_dat[Stpl_Num].spg_level) {
            spg_dat[Stpl_Num].current_spg = spg_dat[Stpl_Num].spg_dotlen;
            sa_gauge_trans(Stpl_Num);
            spg_dat[Stpl_Num].spg_level = plw[Stpl_Num].sa->store;
            sa_stock_trans(spg_dat[Stpl_Num].spg_level, col, Stpl_Num);
        }

        spg_dat[Stpl_Num].max_rno = 1;
        /* fallthrough */

    case 1:
        spg_dat[Stpl_Num].timer--;

        if (spg_dat[Stpl_Num].timer) {
            spg_dat[Stpl_Num].timer2--;

            if (spg_dat[Stpl_Num].kind == 0) {
                if (spg_dat[Stpl_Num].timer2 == 0) {
                    sa_stock_trans(spg_dat[Stpl_Num].spg_level, 0, Stpl_Num);
                    sa_waku_trans(Stpl_Num, 0);
                    spg_dat[Stpl_Num].kind = 1;
                    spg_dat[Stpl_Num].timer2 = 2;
                }
            } else if (spg_dat[Stpl_Num].timer2 == 0) {
                sa_stock_trans(spg_dat[Stpl_Num].spg_level, 1, Stpl_Num);
                sa_waku_trans(Stpl_Num, 1);
                spg_dat[Stpl_Num].kind = 0;
                spg_dat[Stpl_Num].timer2 = 2;
            }

            return;
        }

        if (plw[Stpl_Num].sa->store == plw[Stpl_Num].sa->store_max) {
            max2[Stpl_Num] = 1;
        }

        if (spg_dat[Stpl_Num].sa_mukou == 1) {
            max2[Stpl_Num] = 0;
        }

        if ((spg_dat[Stpl_Num].ex_flag == 1 && omop_use_ex_gauge_ix[Stpl_Num] == 0) &&
            (spg_dat[Stpl_Num].max_old == 1 || max_rno2[Stpl_Num] == 1)) {
            break;
        }

        if (spg_dat[Stpl_Num].max_old != 0 && spg_dat[Stpl_Num].sa_mukou == 0) {
            sa_moji_trans(Stpl_Num, 0, 0);
            spg_dat[Stpl_Num].max_old = 0;
        }

        sast_color_chenge(Stpl_Num);
        spg_dat[Stpl_Num].spg_level = plw[Stpl_Num].sa->store;
        sa_stock_trans(spg_dat[Stpl_Num].spg_level, col, Stpl_Num);
        sa_waku_trans(Stpl_Num, col);

        if (max2[Stpl_Num] == 0 && spg_dat[Stpl_Num].max_old == 0 && spg_dat[Stpl_Num].sa_mukou == 0) {
            sa_gauge_trans(Stpl_Num);
        }

        spg_dat[Stpl_Num].flag = 0;
        spg_dat[Stpl_Num].max_rno = 2;
        spg_dat[Stpl_Num].sa_flag = 0;
        spg_dat[Stpl_Num].ex_flag = 0;
        spg_dat[Stpl_Num].sa_mukou = 0;

        spg_dat[Stpl_Num].flag2 = 0;
        sast_now[Stpl_Num] = 0;
        /* fallthrough */

    default:
    case 2:
        sast_now[Stpl_Num] = 0;
        return;
    }

    sast_color_chenge(Stpl_Num);
    sa_stock_trans(spg_dat[Stpl_Num].spg_level, col, Stpl_Num);
    sa_waku_trans(Stpl_Num, col);

    spg_dat[Stpl_Num].flag = 1;
    spg_dat[Stpl_Num].max_old = 1;
    spg_dat[Stpl_Num].max_rno = 2;
    spg_dat[Stpl_Num].sa_flag = 0;
    spg_dat[Stpl_Num].ex_flag = 0;
    spg_dat[Stpl_Num].sa_mukou = 0;
    spg_dat[Stpl_Num].flag2 = 0;

    max2[Stpl_Num] = 0;
    max_rno2[Stpl_Num] = 0;
    sast_now[Stpl_Num] = 0;
}

void sast_color_chenge(s8 Stpl_Num) {
    if (plw[Stpl_Num].sa->gauge_type == 1 && plw[Stpl_Num].sa->ok == -1) {
        col = 1;

        if (Stpl_Num == 0) {
            spg_dat[0].spgcol_number = 14;
        } else {
            spg_dat[1].spgcol_number = 142;
        }

        return;
    } else if (plw[Stpl_Num].sa->store) {
        col = 1;

        if (Stpl_Num == 0) {
            spg_dat[0].spgcol_number = 18;
        } else {
            spg_dat[1].spgcol_number = 146;
        }
    } else {
        col = 0;

        if (Stpl_Num == 0) {
            spg_dat[0].spgcol_number = 17;
        } else {
            spg_dat[1].spgcol_number = 145;
        }
    }
}

void sa_color_chenge(s8 Stpl_Num) {
    if (spg_dat[Stpl_Num].kind) {
        if (Stpl_Num == 0) {
            spg_dat[0].spgcol_number = 18;
        } else {
            spg_dat[1].spgcol_number = 146;
        }
    } else {
        if (Stpl_Num == 0) {
            spg_dat[0].spgcol_number = 17;
        } else {
            spg_dat[1].spgcol_number = 145;
        }
    }
}

void sagauge_color_chenge(s8 Stpl_Num) {
    if (spg_dat[Stpl_Num].no_chgcol) {
        return;
    }

    spg_dat[Stpl_Num].gauge_flash_time--;

    if (spg_dat[Stpl_Num].gauge_flash_time != 0) {
        return;
    }

    spg_dat[Stpl_Num].gauge_flash_time = 2;

    if (Stpl_Num == 0) {
        sq_paint_chenge(6, 26, spg_dat[0].spg_len, 1, sagauge_colchg_tbl[spg_dat[0].gauge_flash_col][0]);
    } else if (spg_dat[1].max == 1 || spg_dat[1].max_old == 1 || spg_dat[1].spg_level == spg_dat[1].spg_maxlevel) {
        sq_paint_chenge(
            42 - spg_dat[1].spg_len, 26, spg_dat[1].mass_len, 1, sagauge_colchg_tbl[spg_dat[1].gauge_flash_col][1]);
        sq_paint_chenge(42 - spg_dat[1].spg_len + spg_dat[1].mass_len,
                        26,
                        spg_dat[1].mchar,
                        1,
                        sagauge_colchg_tbl[spg_dat[1].gauge_flash_col][0]);
        sq_paint_chenge(42 - spg_dat[1].spg_len + spg_dat[1].mass_len + spg_dat[1].mchar,
                        26,
                        spg_dat[1].mass_len,
                        1,
                        sagauge_colchg_tbl[spg_dat[1].gauge_flash_col][1]);
    } else {
        sq_paint_chenge(
            42 - spg_dat[1].spg_len, 26, spg_dat[1].spg_len, 1, sagauge_colchg_tbl[spg_dat[1].gauge_flash_col][1]);
    }

    if (spg_dat[Stpl_Num].gauge_flash_col == 3) {
        spg_dat[Stpl_Num].gauge_flash_col = 0;
    } else {
        spg_dat[Stpl_Num].gauge_flash_col++;
    }

    spg_dat[Stpl_Num].spgcol_number = sagauge_colchg_tbl[spg_dat[Stpl_Num].gauge_flash_col][Stpl_Num];
}

/* The Xbox returns where the PS2 breaks out of the switch. */
void sa_moji_trans(s8 Stpl_Num, s8 Kind, s8 OnOff) {
    switch (Kind) {
    case 0:
        if (OnOff) {
            spg_dat[Stpl_Num].current_spg = spg_dat[Stpl_Num].spg_dotlen;
            sa_gauge_trans(Stpl_Num);
            max_mark_write(Stpl_Num, spg_dat[Stpl_Num].spg_len, spg_dat[Stpl_Num].mchar, spg_dat[Stpl_Num].mass_len);
            break;
        }

        if (max2[Stpl_Num] == 0) {
            sa_gauge_trans(Stpl_Num);
        }

        break;

    default:
    case 1:
        if (Stpl_Num == 0) {
            if (OnOff) {
                scfont_sqput2(1, 25, 11, 0, 2, sa_time_data_tbl[time_num][0], 0, 4, 2);
                scfont_sqput2(1, 27, 11, 0, 0, 13, 12, 2, 1);
                break;
            }

            sc_clear(1, 25, 4, 26);
            sc_clear(1, 27, 2, 27);
            return;
        }

        if (OnOff) {
            scfont_sqput2(43, 25, 11, 0, 2, sa_time_data_tbl[time_num][1], 0, 4, 2);
            scfont_sqput2(45, 27, 11, 0, 0, 14, 8, 2, 1);
            break;
        }

        sc_clear(43, 25, 46, 26);
        sc_clear(45, 27, 46, 27);
        break;
    }
}

void sa_gauge_trans(s8 pl_kind) {
    s8 i;
    s16 len;
    const u16* sa_char_ptr;

    spg_work = 0;
    spg_number = 0;
    sa_char_ptr = *spgauge_puttbl;
    len = super_arts[pl_kind].gauge_len / 8;

    for (i = 0; i < len; i++) {
        spg_work += 8;

        if (spg_work >= spg_dat[pl_kind].current_spg) {
            if (spg_dat[pl_kind].current_spg >= (spg_work - 8)) {
                spg_offset = spg_dat[pl_kind].current_spg - (i * 8);
                scfont_put2((&spg_dat[pl_kind].spgptbl_ptr[spg_number])[16 - len],
                            26,
                            spg_dat[pl_kind].spgcol_number,
                            0,
                            sa_char_ptr[spg_offset],
                            11);
            } else {
                scfont_put2((&spg_dat[pl_kind].spgptbl_ptr[spg_number])[16 - len],
                            26,
                            spg_dat[pl_kind].spgcol_number,
                            0,
                            0,
                            11);
            }
        } else {
            scfont_put2(
                (&spg_dat[pl_kind].spgptbl_ptr[spg_number])[16 - len], 26, spg_dat[pl_kind].spgcol_number, 0, 8, 11);
        }

        spg_number++;
    }
}

void spgauge_sound_request(s8 Stpl_Num) {
    if (plw[Stpl_Num].sa->store > spg_dat[Stpl_Num].spg_level) {
        sub_00098407(Stpl_Num + 107);
    }
}

void spgauge_work_clear(s8 Stpl_Num) {
    plw[Stpl_Num].sa->gauge.s.h = spg_dat[Stpl_Num].current_spg = plw[Stpl_Num].sa->bacckup_g_h;
    plw[Stpl_Num].sa->bacckup_g_h = 0;
    spg_dat[Stpl_Num].old_spg = spg_dat[Stpl_Num].current_spg;
    spg_dat[Stpl_Num].flag = 0;
    spg_dat[Stpl_Num].flag2 = 0;
    spg_dat[Stpl_Num].level_flag = 0;

    if (plw[Stpl_Num].sa->store) {
        spg_dat[Stpl_Num].timer = 0;
        spg_dat[Stpl_Num].time_rno = 5;
    } else {
        spg_dat[Stpl_Num].timer = 51;
        spg_dat[Stpl_Num].time_rno = 0;
    }

    spg_dat[Stpl_Num].timer2 = 2;
    spg_dat[Stpl_Num].kind = 0;
    spg_dat[Stpl_Num].max = 0;
    spg_dat[Stpl_Num].max_old = 0;
    spg_dat[Stpl_Num].max_rno = 0;
    spg_dat[Stpl_Num].gauge_flash_time = 2;
    spg_dat[Stpl_Num].gauge_flash_col = 0;
    spg_dat[Stpl_Num].sa_flag = 0;
    spg_dat[Stpl_Num].ex_flag = 0;
    spg_dat[Stpl_Num].no_chgcol = 0;
    spg_dat[Stpl_Num].time_no_clear = 0;
    spg_dat[Stpl_Num].sa_mukou = 0;
    sa_gauge_flash[Stpl_Num] = 0;
    sa_color_chenge(Stpl_Num);
    time_operate[Stpl_Num] = 0;
    sast_now[Stpl_Num] = 0;
    max2[Stpl_Num] = 0;
}

void spgauge_wipe_write(s8 Stpl_Num) {
    sa_stock_trans(spg_dat[Stpl_Num].spg_level, col, Stpl_Num);
    sa_gauge_trans(Stpl_Num);
    sa_waku_trans(Stpl_Num, col);
}

void sa_waku_trans(s8 Stpl_Num, s8 Spg_Col) {
    s8 lpy;

    sc_ram_to_vram(Stpl_Num + (Spg_Col * 2));

    if (Stpl_Num == 0) {
        for (lpy = 0; lpy < spg_dat[0].spg_len; lpy++) {
            scfont_put2(lpy + 6, 27, sa_color_data2_tbl[Spg_Col][0], 0, 15, 12);
        }

        if (cmd_sel[0] == 0 && no_sa[0] == 0) {
            sa_number_write(0, lpy + 6);
        } else {
            scfont_sqput2(lpy + 6, 26, 14, 0, 2, 27, 2, 1, 2);
        }

        sa_fullstock_trans(spg_dat[0].spg_maxlevel, Spg_Col, 0);
        return;
    }

    for (lpy = 0; lpy < spg_dat[1].spg_len; lpy++) {
        scfont_put2(41 - lpy, 27, sa_color_data2_tbl[Spg_Col][1], 0, 15, 12);
    }

    if (cmd_sel[1] == 0 && no_sa[1] == 0) {
        sa_number_write(1, 40 - lpy);
    } else {
        scfont_sqput2(41 - lpy, 26, 142, 1, 2, 27, 2, 1, 2);
    }

    sa_fullstock_trans(spg_dat[1].spg_maxlevel, Spg_Col, 1);
}

void tr_spgauge_cont_init(s8 pl) {
    Sa_frame_Clear2(pl);
    spg_dat[pl].current_spg = 0;
    spg_dat[pl].old_spg = 0;
    spg_dat[pl].spgtbl_ptr = spgauge_puttbl[pl];
    spg_dat[pl].spg_level = 0;
    spg_dat[pl].spg_maxlevel = super_arts[pl].store_max;
    spg_dat[pl].spg_len = super_arts[pl].gauge_len / 8;
    spg_dat[pl].spg_dotlen = super_arts[pl].gauge_len;
    spg_dat[pl].flag = 0;
    spg_dat[pl].flag2 = 0;
    spg_dat[pl].level_flag = 0;
    spg_dat[pl].timer = 51;
    spg_dat[pl].timer2 = 2;
    spg_dat[pl].kind = 0;
    spg_dat[pl].max = 0;
    spg_dat[pl].max_old = 0;
    spg_dat[pl].max_rno = 0;
    spg_dat[pl].time_rno = 0;
    spg_dat[pl].gauge_flash_time = 2;
    spg_dat[pl].gauge_flash_col = 0;
    spg_dat[pl].sa_flag = 0;
    spg_dat[pl].ex_flag = 0;
    spg_dat[pl].no_chgcol = 0;
    spg_dat[pl].time_no_clear = 0;
    spg_dat[pl].sa_mukou = 0;
    sa_gauge_flash[pl] = 0;
    spg_dat[pl].spgptbl_ptr = spgauge_postbl[pl];

    if (super_arts[pl].gauge_type == 1) {
        spg_dat[pl].time = 1;
        time_flag[pl] = 1;
    } else {
        spg_dat[pl].time = 0;
        time_flag[pl] = 0;
    }

    spg_dat[pl].mass_len = spg_dat[pl].spg_len - 5;

    if (spg_dat[pl].spg_len & 1) {
        spg_dat[pl].mchar = 5;
    } else {
        spg_dat[pl].mass_len = spg_dat[pl].mass_len - 1;
        spg_dat[pl].mchar = 6;
    }

    spg_dat[pl].mass_len /= 2;
    time_operate[pl] = 0;
    sast_now[pl] = 0;
    max2[pl] = 0;
    max_rno2[pl] = 0;

    if (pl == 0) {
        spg_dat[0].spgcol_number = 17;
    } else {
        spg_dat[1].spgcol_number = 145;
    }

    sa_stock_trans(0, 0, pl);
    sa_waku_trans(pl, 0);
    sa_gauge_trans(pl);
    Old_Stop_SG = 0;
    Exec_Wipe_F = 0;
    time_clear[pl] = 0;
    spg_offset = 0;
    time_num = 0;
    time_timer = 3;
    col = 0;
}

void tr_spgauge_cont_init2(s8 pl) {
    Sa_frame_Clear2(pl);
    demo_set_sa_full(&super_arts[pl]);
    spg_dat[pl].current_spg = super_arts[pl].gauge_len;
    spg_dat[pl].old_spg = super_arts[pl].gauge_len;
    spg_dat[pl].spgtbl_ptr = spgauge_puttbl[pl];
    spg_dat[pl].spg_level = super_arts[pl].store;
    spg_dat[pl].spg_maxlevel = super_arts[pl].store_max;
    spg_dat[pl].spg_len = super_arts[pl].gauge_len / 8;
    spg_dat[pl].spg_dotlen = super_arts[pl].gauge_len;
    spg_dat[pl].flag = 1;
    spg_dat[pl].flag2 = 0;
    spg_dat[pl].level_flag = 0;
    spg_dat[pl].timer = 51;
    spg_dat[pl].timer2 = 2;
    spg_dat[pl].kind = 1;
    spg_dat[pl].max = 0;
    spg_dat[pl].max_old = 1;
    spg_dat[pl].max_rno = 2;
    spg_dat[pl].time_rno = 5;
    spg_dat[pl].gauge_flash_time = 2;
    spg_dat[pl].gauge_flash_col = 0;
    spg_dat[pl].sa_flag = 0;
    spg_dat[pl].ex_flag = 0;
    spg_dat[pl].no_chgcol = 0;
    spg_dat[pl].time_no_clear = 0;
    spg_dat[pl].sa_mukou = 0;
    sa_gauge_flash[pl] = 0;
    spg_dat[pl].spgptbl_ptr = spgauge_postbl[pl];

    if (super_arts[pl].gauge_type == 1) {
        spg_dat[pl].time = 1;
        time_flag[pl] = 1;
    } else {
        spg_dat[pl].time = 0;
        time_flag[pl] = 0;
    }

    spg_dat[pl].mass_len = spg_dat[pl].spg_len - 5;

    if (spg_dat[pl].spg_len & 1) {
        spg_dat[pl].mchar = 5;
    } else {
        spg_dat[pl].mass_len = spg_dat[pl].mass_len - 1;
        spg_dat[pl].mchar = 6;
    }

    spg_dat[pl].mass_len /= 2;
    time_operate[pl] = 0;
    sast_now[pl] = 0;
    max2[pl] = 0;
    max_rno2[pl] = 0;

    if (pl == 0) {
        spg_dat[0].spgcol_number = 17;
    } else {
        spg_dat[1].spgcol_number = 145;
    }

    sa_stock_trans(spg_dat[pl].spg_maxlevel, 1, pl);
    sa_waku_trans(pl, 1);
    sa_gauge_trans(pl);
    sa_moji_trans(pl, 0, 1);
    Old_Stop_SG = 0;
    Exec_Wipe_F = 0;
    time_clear[pl] = 0;
    spg_offset = 0;
    time_num = 0;
    time_timer = 3;
    col = 1;
}
