/* Effect 01, retail sf33rd.xbe.
 * get_new_parts_data is 0x31ABD size 0x11F and is interior.
 * set_parts_disp_flag is 0x31BDC size 0x50 and is interior.
 * effect_01_init is 0x31C2C size 0x8E and is interior.
 * effect_01_move is 0x31DA8 size 0x272 and is interior.
 * The pull failure is an early ret.
 * xb_effect_01_draw is 0x31CBA size 0xEE, the drawing half of effect_01_move.
 *
 * parts_colmd_table is 0x249C5C and parts_colcd_table is
 * 0x249C60. Both match. The rows were not pasted. The
 * init stores type before be_flag. The rl_flag flip is
 * a decrement. The C keeps the PlayStation 2 form.
 * Game_pause is 0x7A89B0. EXE_flag is 0xC7C834.
 * sort_push_request is 0x9DF9A.
 * push_effect_work is 0x4AC6C.
 * pull_effect_work is 0x4A6A8. frw is 0xC806A0
 * and each object is 0x700 bytes.
 */

#include "types.h"
#include "structs.h"

typedef struct {
    s16 parts_hos_x;
    s16 parts_hos_y;
    u8 parts_colmd;
    u8 parts_colcd;
    u8 parts_prio;
    u8 parts_flip;
    u8 parts_timer;
    u8 parts_disp;
    s16 parts_mts;
    u16 parts_nix;
    u16 parts_char;
} Parts;

typedef struct {
    s16 olc_ix[4];
} CgOlc;




typedef u8 EffectRow[0x700];

#if defined(__i386__)
_Static_assert(sizeof(Parts) == 0x10, "Parts");
_Static_assert(__builtin_offsetof(WORK, blink_timing) == 2, "blink");
_Static_assert(__builtin_offsetof(WORK, type) == 4, "type");
_Static_assert(__builtin_offsetof(WORK, work_id) == 6, "work_id");
_Static_assert(__builtin_offsetof(WORK, id) == 8, "id");
_Static_assert(__builtin_offsetof(WORK, rl_flag) == 0xA, "rl_flag");
_Static_assert(__builtin_offsetof(WORK, target_adrs) == 0xC, "target");
_Static_assert(__builtin_offsetof(WORK, myself) == 0x1A, "myself");
_Static_assert(__builtin_offsetof(WORK, dead_f) == 0x20, "dead_f");
_Static_assert(__builtin_offsetof(WORK, routine_no) == 0x24, "routine_no");
_Static_assert(__builtin_offsetof(WORK, cgromtype) == 0x48, "cgromtype");
_Static_assert(__builtin_offsetof(WORK, position_x) == 0x54, "position_x");
_Static_assert(__builtin_offsetof(WORK, position_y) == 0x56, "position_y");
_Static_assert(__builtin_offsetof(WORK, position_z) == 0x58, "position_z");
_Static_assert(__builtin_offsetof(WORK, overlap_char_tbl) == 0x1E8, "overlap");
_Static_assert(__builtin_offsetof(WORK, cg_olc) == 0x1F0, "cg_olc");
_Static_assert(__builtin_offsetof(WORK, cg_ix) == 0x204, "cg_ix");
_Static_assert(__builtin_offsetof(WORK, now_koc) == 0x206, "now_koc");
_Static_assert(__builtin_offsetof(WORK, cg_ctr) == 0x215, "cg_ctr");
_Static_assert(__builtin_offsetof(WORK, cg_number) == 0x21A, "cg_number");
_Static_assert(__builtin_offsetof(WORK, cg_flip) == 0x233, "cg_flip");
_Static_assert(__builtin_offsetof(WORK, old_cgnum) == 0x234, "old_cgnum");
_Static_assert(__builtin_offsetof(WORK, my_col_mode) == 0x23C, "my_col_mode");
_Static_assert(__builtin_offsetof(WORK, my_col_code) == 0x23E, "my_col_code");
_Static_assert(__builtin_offsetof(WORK, my_family) == 0x242, "my_family");
_Static_assert(__builtin_offsetof(WORK, my_mts) == 0x24C, "my_mts");
_Static_assert(__builtin_offsetof(WORK, olc_work_ix) == 0x262, "olc_work_ix");
_Static_assert(__builtin_offsetof(WORK, extra_col) == 0x342, "extra_col");
_Static_assert(__builtin_offsetof(WORK, extra_col_2) == 0x344, "extra_col_2");
_Static_assert(sizeof(WORK) == 0x388, "WORK");
_Static_assert(__builtin_offsetof(WORK_Other, my_master) == 0x388, "my_master");
_Static_assert(__builtin_offsetof(WORK_Other, master_work_id) == 0x38C, "mwid");
_Static_assert(__builtin_offsetof(WORK_Other, master_id) == 0x38E, "mid");
_Static_assert(__builtin_offsetof(PLW, player_number) == 0x394, "player");
_Static_assert(__builtin_offsetof(PLW, sa_stop_flag) == 0x3F0, "sa_stop");
#endif

extern EffectRow frw[];
/* Tables pasted from the PS2 file; analysis-ps2map/portdata.py found
   each equal to retail. */
const s16 parts_colmd_table[2] = { 0x4000, 0x0 };

const s16 parts_colcd_table[14] = {
    0x2000, 0x0, 0x6, 0x2000, 0x4, 0x2020, 0x4, 0x4, 0x0, 0x6, 0x5, 0x4, 0x203C, 0x202A
};

extern u8 Game_pause;
extern s16 EXE_flag;

void get_new_parts_data(WORK_Other *ewk, PLW *mwk);
void set_parts_disp_flag(WORK_Other *ewk, PLW *mwk);
s16 pull_effect_work(s16 index);
void push_effect_work(WORK *wk);
void sort_push_request(WORK *wk);

/* Xbox-only: the drawing half of effect_01_move, called through the
 * effect draw table by xb_draw_effect_work. */
void xb_effect_01_draw(WORK_Other *ewk) {
    WORK *mwk;

    mwk = (WORK *)ewk->my_master;

    switch (ewk->wu.routine_no[0]) {
    case 1:
        if (ewk->wu.dead_f == 1 || mwk->olc_work_ix[ewk->wu.type] != ewk->wu.myself) {
            return;
        }

        if (mwk->cg_olc.olc_ix[ewk->wu.type] == 0) {
            return;
        }

        if (Game_pause == 0 && EXE_flag == 0) {
            if (ewk->wu.cg_number == 0) {
                break;
            }

            ewk->wu.position_x = mwk->position_x;
            ewk->wu.position_y = mwk->position_y;
            ewk->wu.position_z = mwk->position_z;
        }

        if (ewk->wu.cg_number == 0) {
            break;
        }

        set_parts_disp_flag(ewk, (PLW *)mwk);

        if (ewk->wu.overlap_char_tbl->parts_colcd == 0) {
            ewk->wu.my_col_code = mwk->my_col_code;
            ewk->wu.extra_col = mwk->extra_col;
            ewk->wu.extra_col_2 = mwk->extra_col_2;
        }

        if (ewk->wu.overlap_char_tbl->parts_mts != 0) {
            ewk->wu.my_mts = 14;
        } else {
            ewk->wu.my_mts = mwk->my_mts;
        }

        sort_push_request(&ewk->wu);
        break;
    }
}

void effect_01_move(WORK_Other *ewk) {
    WORK *mwk;

    mwk = (WORK *)ewk->my_master;

    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.cgromtype = mwk->cgromtype;
        ewk->wu.cg_number = ewk->wu.old_cgnum = 0;
        ewk->wu.blink_timing = mwk->blink_timing;
        ewk->wu.cg_olc.olc_ix[ewk->wu.type] = 0;
        return;

    case 1:
        if (ewk->wu.dead_f == 1 || mwk->olc_work_ix[ewk->wu.type] != ewk->wu.myself) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0]++;
            return;
        }

        if (mwk->cg_olc.olc_ix[ewk->wu.type] == 0) {
            ewk->wu.cg_olc.olc_ix[ewk->wu.type] = 0;
            return;
        }

        if (Game_pause == 0 && EXE_flag == 0) {
            if (ewk->wu.cg_olc.olc_ix[ewk->wu.type] != mwk->cg_olc.olc_ix[ewk->wu.type]) {
                ewk->wu.cg_olc.olc_ix[ewk->wu.type] = ewk->wu.cg_ix = mwk->cg_olc.olc_ix[ewk->wu.type];
                ewk->wu.now_koc = ewk->wu.cg_ix;

                if (ewk->wu.type == 0 && ((PLW *)mwk)->player_number == 0 && mwk->rl_flag != 0) {
                    ewk->wu.now_koc++;
                }

                get_new_parts_data(ewk, (PLW *)mwk);
            } else if (((PLW *)mwk)->sa_stop_flag == 0) {
                if (--ewk->wu.cg_ctr == 0) {
                    if (ewk->wu.overlap_char_tbl->parts_nix != 0) {
                        ewk->wu.cg_ix = ewk->wu.overlap_char_tbl->parts_nix;
                    } else {
                        ewk->wu.cg_ix++;
                    }

                    ewk->wu.now_koc = ewk->wu.cg_ix;
                    get_new_parts_data(ewk, (PLW *)mwk);
                }
            }

            if (ewk->wu.cg_number == 0) {
                break;
            }

            ewk->wu.position_x = mwk->position_x;
            ewk->wu.position_y = mwk->position_y;
            ewk->wu.position_z = mwk->position_z;
            ewk->wu.rl_flag = mwk->rl_flag;
            ewk->wu.cg_flip = ewk->wu.overlap_char_tbl->parts_flip & 3;

            if ((ewk->wu.overlap_char_tbl->parts_flip & 4) != 0) {
                ewk->wu.cg_flip ^= mwk->cg_flip;

                if ((mwk->cg_flip & 1) != 0) {
                    ewk->wu.rl_flag = (ewk->wu.rl_flag + 1) & 1;
                }
            }

            if (ewk->wu.rl_flag != 0) {
                ewk->wu.position_x -= ewk->wu.overlap_char_tbl->parts_hos_x;
            } else {
                ewk->wu.position_x += ewk->wu.overlap_char_tbl->parts_hos_x;
            }

            ewk->wu.position_y += ewk->wu.overlap_char_tbl->parts_hos_y;

            if ((ewk->wu.overlap_char_tbl->parts_flip & 4) != 0 && (mwk->cg_flip & 2) != 0) {
                ewk->wu.position_y -= ewk->wu.overlap_char_tbl->parts_hos_y * 2;
            }

            if (ewk->wu.overlap_char_tbl->parts_prio == 2) {
                ewk->wu.position_z -= (ewk->wu.type + 1) * 2;
            } else {
                ewk->wu.position_z += (ewk->wu.type + 1) * 2;
            }
        }

        if (ewk->wu.cg_number == 0) {
            break;
        }

        set_parts_disp_flag(ewk, (PLW *)mwk);

        if (ewk->wu.overlap_char_tbl->parts_colcd == 0) {
            ewk->wu.my_col_code = mwk->my_col_code;
            ewk->wu.extra_col = mwk->extra_col;
            ewk->wu.extra_col_2 = mwk->extra_col_2;
        }

        if (ewk->wu.overlap_char_tbl->parts_mts != 0) {
            ewk->wu.my_mts = 14;
        } else {
            ewk->wu.my_mts = mwk->my_mts;
        }

        sort_push_request(&ewk->wu);
        break;

    case 2:
    default:
        push_effect_work(&ewk->wu);
        break;
    }
}

void get_new_parts_data(WORK_Other *ewk, PLW *mwk) {
    ewk->wu.now_koc = ewk->wu.cg_ix;

    if (ewk->wu.type == 0 && mwk->player_number == 0 && mwk->wu.rl_flag != 0) {
        ewk->wu.now_koc++;
    }

    ewk->wu.overlap_char_tbl = mwk->wu.overlap_char_tbl + ewk->wu.now_koc;
    ewk->wu.cg_ctr = ewk->wu.overlap_char_tbl->parts_timer;

    if (ewk->wu.overlap_char_tbl->parts_colmd != 0) {
        if (ewk->wu.overlap_char_tbl->parts_colmd == 1) {
            ewk->wu.my_col_mode = ((WORK *)mwk->wu.target_adrs)->my_col_mode;
        } else {
            ewk->wu.my_col_mode = parts_colmd_table[ewk->wu.overlap_char_tbl->parts_colmd];
        }
    } else {
        ewk->wu.my_col_mode = mwk->wu.my_col_mode;
    }

    if (ewk->wu.overlap_char_tbl->parts_colcd != 0) {
        ewk->wu.extra_col = 0;
        ewk->wu.extra_col_2 = 0;
        ewk->wu.my_col_code = parts_colcd_table[ewk->wu.overlap_char_tbl->parts_colcd];

        if ((ewk->wu.my_col_code & 0x2000) == 0) {
            ewk->wu.my_col_code += mwk->wu.my_col_code;
        }
    } else {
        ewk->wu.my_col_code = mwk->wu.my_col_code;
        ewk->wu.my_col_code = mwk->wu.my_col_code;
        ewk->wu.extra_col = mwk->wu.extra_col;
        ewk->wu.extra_col_2 = mwk->wu.extra_col_2;
    }

    ewk->wu.cg_number = ewk->wu.overlap_char_tbl->parts_char;
}

void set_parts_disp_flag(WORK_Other *ewk, PLW *mwk) {
    switch (ewk->wu.overlap_char_tbl->parts_disp) {
    case 1:
        if (mwk->wu.disp_flag != 0) {
            ewk->wu.disp_flag = 1;
            break;
        }

        ewk->wu.disp_flag = 0;
        break;

    case 2:
        if (mwk->wu.disp_flag != 0) {
            ewk->wu.disp_flag = 2;
            break;
        }

        ewk->wu.disp_flag = 0;
        break;

    case 11:
        ewk->wu.disp_flag = 1;
        break;

    case 12:
        ewk->wu.disp_flag = 2;
        break;

    default:
        ewk->wu.disp_flag = mwk->wu.disp_flag;
        break;
    }
}

s32 effect_01_init(WORK *wk, u8 koolc) {
    WORK_Other *ewk;
    s16 ix;

    if ((ix = pull_effect_work(1)) == -1) {
        return -1;
    }

    ewk = (WORK_Other *)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 1;
    ewk->wu.work_id = 32;
    ewk->wu.type = koolc;
    ewk->wu.my_family = wk->my_family;
    ewk->wu.blink_timing = wk->blink_timing;
    ewk->my_master = (u32 *)wk;
    ewk->master_work_id = wk->work_id;
    ewk->master_id = wk->id;
    ewk->wu.my_mts = wk->my_mts;
    wk->olc_work_ix[koolc] = ewk->wu.myself;
    return 0;
}
