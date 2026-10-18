/* EFFECT.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * move_effect_work 0x4A650 size 0x58.
 * pull_effect_work 0x4A6A8 size 0x9D.
 * search_effect_index 0x4A745 size 0x6C.
 * xb_FindEffect42 0x4A7B1 size 0x3F.
 * effect_work_kill 0x4A7F0 size 0x5E.
 * work_init_zero 0x4A84E size 0x1B.
 * write_my_shell_ix 0x4A869 size 0x2C. Read against the x86: 0x33E is
 * &wk->shell_ix[7] for the backward search; -2 is the element step. The C is
 * the PS2 C.
 * erase_my_shell_ix 0x4A895 size 0x4C.
 * get_my_shell_ix 0x4A8E1 size 0x39.
 * get_vs_shell_adrs 0x4A91A size 0x43.
 * clear_my_shell_ix 0x4A95D size 0x14. Read against the x86: 0x330 is
 * &wk->shell_ix[0], cleared with rep stosd. The C is the PS2 C.
 * setup_shell_hit_stop 0x4A971 size 0x3B.
 * shell_live_check 0x4A9AC size 0x9E.
 * clear_caution_flag 0x4AA4A size 0xE.
 * set_caution_flag 0x4AA58 size 0xE.
 * setup_status_flag 0x4AA66 size 0x11.
 * reset_extra_bg_flag 0x4AA77 size 0x12.
 * flip_my_rl_flag 0x4AA89 size 0x12.
 * setup_meoshi_hit_flag 0x4AA9B size 0x11.
 * exec_char_asxy 0x4AAAC size 0x3A.
 * setup_my_clear_level 0x4AAE6 size 0x14.
 * setup_my_bright_level 0x4AAFA size 0x14.
 * setup_bg_quake_x 0x4AB0E size 0xF.
 * setup_bg_quake_y 0x4AB1D size 0x19.
 * setup_exdm_ix 0x4AB36 size 0x11.
 * setup_dmv_use_flag 0x4AB47 size 0x11.
 * setup_disp_flag 0x4AB58 size 0xE.
 * setup_command_number 0x4AB66 size 0x14.
 * old_my_char_check 0x4AB7A size 0x30.
 * effect_work_kill_mod_plcol 0x4ABAA size 0xC.
 * setup_shadow_of_the_Effy 0x4ABB6 size 0x20.
 * set_init_A4_flag 0x4ABD6 size 0x1D.
 * effect_work_init 0x4ABF3 size 0x79.
 * push_effect_work 0x4AC6C size 0xF4.
 * effect_work_list_init 0x4AD60 size 0x7B.
 * effect_work_quick_init 0x4ADDB size 0x18.
 * setup_free_program is folded into 0x4AFFA with 1 other bodies. Unnamed.
 * Not located in sf33rd.xbe; their PS2 C is kept under #if 0:
 * disp_effect_work.
 * Data: frwctr 0xC80680.
 * Data: frwctr_min 0xCB86A0.
 * Data: head_ix 0xC80670.
 * Data: tail_ix 0xC80660.
 * Data: exec_tm 0xC80690.
 * Data: frw 0xC806A0.
 * Data: frwque 0xCB86C0.
 * TARGET_PS2 block in push_effect_work: kept the PS2 side of a TARGET_PS2
 * block.
 * Globals: effmovejptbl 0x25B658, Country 0x7A8748, another_bg 0x7A8910, bg_w
 * 0x7BC520, plw 0xC7CEA0, tail_ix 0xC80660, head_ix 0xC80670, frwctr 0xC80680,
 * exec_tm 0xC80690, frw 0xC806A0, frwctr_min 0xCB86A0, frwque 0xCB86C0.
 */

#include "structs.h"
#include <string.h>

#define EFFECT_MAX 128

extern const void (*effmovejptbl[])();
void work_init_zero(s32* adrs_int, s32 xx);
void effect_work_list_init(s16 lix, s16 iid);
void push_effect_work(WORK* wkhd);
extern s8 another_bg[2];
extern BG bg_w;
void pp_screen_quake(s16 ix);
extern u8 Country;
extern PLW plw[2];

extern s16 frwctr;

extern s16 frwctr_min;

extern s16 head_ix[8];

extern s16 tail_ix[8];

extern s16 exec_tm[8];

extern uintptr_t frw[EFFECT_MAX][448];

extern s16 frwque[EFFECT_MAX];

/* The Xbox has no Debug_w test. */
void move_effect_work(s16 index) {
    WORK* c_addr;
    s16 curr_ix;
    s16 next_ix;

    exec_tm[index] += 1;

    for (curr_ix = head_ix[index]; curr_ix != -1; curr_ix = next_ix) {
        c_addr = (WORK*)frw[curr_ix];
        next_ix = c_addr->behind;

        if (c_addr->timing != exec_tm[index]) {
            c_addr->timing = exec_tm[index];
            effmovejptbl[c_addr->id](c_addr);
        }
    }
}

void effect_work_init() {
    WORK* c_addr;
    s16 i;

    work_init_zero((s32*)frw, sizeof(frw));

    for (i = 0; i < EFFECT_MAX; i++) {
        frwctr = (EFFECT_MAX - 1) - i;
        c_addr = (WORK*)frw[frwctr];
        frwque[i] = c_addr->myself = frwctr;
        c_addr->before = c_addr->behind = -1;
    }

    frwctr = EFFECT_MAX;
    frwctr_min = frwctr;

    for (i = 0; i < 8; i++) {
        head_ix[i] = tail_ix[i] = -1;
        exec_tm[i] = 0;
    }
}

void effect_work_quick_init() {
    s16 i;

    for (i = 0; i < 8; i += 1) {
        effect_work_list_init(i, -1);
    }
}

void effect_work_list_init(s16 lix, s16 iid) {
    WORK* c_addr;
    s16 curr_ix;
    s16 next_ix;

    curr_ix = head_ix[lix];

    if (iid == -1) {
        while (curr_ix != -1) {
            c_addr = (WORK*)frw[curr_ix];
            next_ix = c_addr->behind;
            push_effect_work(c_addr);
            curr_ix = next_ix;
        }

        exec_tm[lix] = 0;
    } else {
        while (curr_ix != -1) {
            c_addr = (WORK*)frw[curr_ix];
            next_ix = c_addr->behind;

            if (c_addr->id == iid) {
                push_effect_work(c_addr);
            }

            curr_ix = next_ix;
        }
    }
}

s16 pull_effect_work(s16 index) {
    s16 qix;
    WORK* tadr;
    WORK* wrk;

    if (frwctr < 1) {
        return -1;
    }

    qix = frwque[(frwctr -= 1)];
    tadr = (WORK*)frw[qix];

    if (head_ix[index] == -1) {
        tail_ix[index] = qix;
        head_ix[index] = qix;
    } else {
        wrk = (WORK*)frw[tail_ix[index]];
        wrk->behind = qix;
        tadr->before = tail_ix[index];
        tail_ix[index] = qix;
    }

    tadr->timing = exec_tm[index];
    tadr->listix = index;

    if (frwctr_min > frwctr) {
        frwctr_min = frwctr;
    }

    return qix;
}

/// @brief Searches for an effect.
/// @param index Index of the list to perform search in.
/// @param flag Set to `true` to search from the tail, `false` to search from the head.
/// @param tid ID to search for.
/// @return Index of the effect, or `-1` if it couldn't be found.
s16 search_effect_index(s16 index, s16 flag, s16 tid) {
    WORK* c_addr;
    s16 aix;

    if (flag) {
        aix = tail_ix[index];

        while (aix != -1) {
            c_addr = (WORK*)frw[aix];

            if (c_addr->id != tid) {
                aix = c_addr->before;
            } else {
                break;
            }
        }
    } else {
        aix = head_ix[index];

        while (aix != -1) {
            c_addr = (WORK*)frw[aix];

            if (c_addr->id != tid) {
                aix = c_addr->behind;
            } else {
                break;
            }
        }
    }

    return aix;
}

void push_effect_work(WORK* wkhd) {
    WORK* c_addr;
    WORK* c_addr2;
    s16 qix;
    s16 lix;

    lix = wkhd->listix;
    qix = wkhd->myself;
    c_addr = (WORK*)frw[qix];


    switch ((qix == head_ix[lix]) + (qix == tail_ix[lix]) * 2) {
    case 0:
        c_addr2 = (WORK*)frw[c_addr->before];
        c_addr2->behind = c_addr->behind;
        c_addr2 = (WORK*)frw[c_addr->behind];
        c_addr2->before = c_addr->before;
        break;

    case 1:
        head_ix[lix] = c_addr->behind;
        c_addr2 = (WORK*)frw[c_addr->behind];
        c_addr2->before = -1;
        break;

    case 2:
        c_addr2 = (WORK*)frw[c_addr->before];
        c_addr2->behind = -1;
        tail_ix[lix] = c_addr->before;
        break;

    default:
        head_ix[lix] = tail_ix[lix] = -1;
        break;
    }

    work_init_zero((s32*)frw[qix], sizeof(frw[0]));
    c_addr->before = c_addr->behind = -1;
    frwque[frwctr++] = qix;
    c_addr->myself = qix;
}

void effect_work_kill(s16 index, s16 kill_id) {
    WORK* c_addr;
    s16 aix = head_ix[index];

    if (kill_id == -1) {
        while (aix != -1) {
            c_addr = (WORK*)frw[aix];
            c_addr->dead_f = 1;
            aix = c_addr->behind;
        }

        return;
    }

    while (aix != -1) {
        c_addr = (WORK*)frw[aix];

        if (c_addr->id == kill_id) {
            c_addr->dead_f = 1;
        }

        aix = c_addr->behind;
    }
}

/* The Xbox clears the block with memset. */
void work_init_zero(s32* adrs_int, s32 xx) {
    memset(adrs_int, 0, xx);
}

void write_my_shell_ix(WORK* wk, s16 ix) {
    s32 i;

    for (i = 7; i > 0; i -= 1) {
        wk->shell_ix[i] = wk->shell_ix[i - 1];
    }

    wk->shell_ix[0] = ix;
}

s32 erase_my_shell_ix(WORK* wk, s16 ix) {
    s32 i;
    s32 j;

    for (i = 0; i < 8; i++) {
        if (wk->shell_ix[i] == ix) {
            goto ok;
        }
    }

    return 0;

ok:
    for (j = i; j < 7; j++) {
        wk->shell_ix[j] = wk->shell_ix[j + 1];
    }

    wk->shell_ix[7] = -1;
    return 1;
}

s32 get_my_shell_ix(WORK* wk, s16 ix, WORK** tmw) {
    if (wk->shell_ix[ix] == -1) {
        return 0;
    }

    *tmw = (WORK*)frw[wk->shell_ix[ix]];

    if ((*tmw)->be_flag) {
        return 1;
    }

    return 0;
}

s32 get_vs_shell_adrs(WORK* wk, s16 id, s16 ix, WORK_Other** tmw) {
    if (wk->shell_ix[ix] == -1) {
        return 0;
    }

    *tmw = (WORK_Other*)frw[wk->shell_ix[ix]];

    if ((*tmw)->master_id == id) {
        return 1;
    }

    return 0;
}

void clear_my_shell_ix(WORK* wk) {
    s32 i;

    for (i = 0; i < 8; i += 1) {
        wk->shell_ix[i] = -1;
    }
}

void setup_shell_hit_stop(WORK* wk, s16 tm, s16 fl) {
    WORK* tmw;
    s32 i;

    for (i = 0; i < 8; i++) {
        if (get_my_shell_ix(wk, i, &tmw) != 0) {
            if (fl == 0 || tmw->id != 0x29) {
                tmw->hit_stop = tm;
            }
        }
    }
}

s32 shell_live_check(PLW* wk, s16 wix) {
    WORK_Other* tmw;
    s16 i;

    if (wk->player_number != 0xE) {
        for (i = 0; i < 8; i++) {
            if (wk->wu.shell_ix[i] == -1) {
                break;
            }

            tmw = (WORK_Other*)frw[wk->wu.shell_ix[i]];

            if ((!tmw->refrected) && (tmw->wu.original_vitality == wix)) {
                return 1;
            }
        }

        return 0;
    }

    for (i = 0; i < 8; i++) {
        if (wk->wu.shell_ix[i] == -1) {
            break;
        }

        tmw = (WORK_Other*)frw[wk->wu.shell_ix[i]];

        if (tmw->refrected) {
            continue;
        }

        if ((tmw->wu.original_vitality == 31) || (tmw->wu.original_vitality == 33) ||
            (tmw->wu.original_vitality == 46)) {
            return 1;
        }
    }

    return 0;
}

s32 clear_caution_flag(PLW* wk, u8 /* unused */) {
    wk->caution_flag = 0;
    return 0;
}

s32 set_caution_flag(PLW* wk, u8 /* unused */) {
    wk->caution_flag = 1;
    return 0;
}

s32 setup_status_flag(WORK* wk, u8 data) {
    wk->pat_status = data;
    return 0;
}

s32 reset_extra_bg_flag(WORK* wk, u8 /* unused */) {
    another_bg[wk->id] = 0;
    return 0;
}

s32 flip_my_rl_flag(WORK* wk, u8 /* unused */) {
    wk->rl_flag = wk->rl_flag + 1U & 1;
    return 0;
}

s32 setup_meoshi_hit_flag(WORK* wk, u8 data) {
    wk->meoshi_hit_flag = data;
    return 0;
}

s32 exec_char_asxy(WORK* wk, u8 data) {
    s16* from_rom2;
    s32 st;
    s16 ix = data;

    ix *= 2;
    from_rom2 = &wk->step_xy_table[ix];
    st = *from_rom2++;
    st *= 256;

    if (wk->rl_flag) {
        wk->xyz[0].cal += st;
    } else {
        wk->xyz[0].cal -= st;
    }

    st = *from_rom2;
    st *= 256;
    wk->xyz[1].cal += st;
    return 0;
}

s32 setup_my_clear_level(WORK* wk, u8 data) {
    wk->my_clear_level = data;
    return 0;
}

s32 setup_my_bright_level(WORK* wk, u8 data) {
    wk->my_bright_level = data;
    return 0;
}

s32 setup_free_program(s32 /* unused */, s32 /* unused */) {
    return 0;
}

s32 setup_bg_quake_x(s32 /* unused */, u8 data) {
    bg_w.quake_x_index = data;
    return 0;
}

s32 setup_bg_quake_y(s32 /* unused */, u8 data) {
    bg_w.quake_y_index = data;
    pp_screen_quake(bg_w.quake_y_index);
    return 0;
}

s32 setup_exdm_ix(PLW* wk, u8 data) {
    wk->exdm_ix = data;
    return 0;
}

s32 setup_dmv_use_flag(PLW* wk, u8 data) {
    wk->dm_vital_use = data;
    return 0;
}

s32 setup_disp_flag(WORK* wk, u8 data) {
    wk->disp_flag = data;
    return 0;
}

s32 setup_command_number(PLW* wk, u8 data) {
    wk->cmd_request = data;
    return 0;
}

u8 old_my_char_check(u8 num, u8 flag) {
    switch (flag) {
    case 0:
        if ((Country == 1) || (Country == 8)) {
            if (num > 14) {
                num += 1;
            }
        } else if (num > 13) {
            num += 1;
        }

        break;

    case 1:
        if (num > 14) {
            num += 1;
        }

        break;
    }

    return num;
}

void effect_work_kill_mod_plcol() {
    effect_work_kill(6, -1);
}

void setup_shadow_of_the_Effy(WORK* wk) {
    wk->kage_flag = 1;
    wk->kage_hx = 0;
    wk->kage_hy = -0xA;
    wk->kage_prio = 0x47;
    wk->kage_char = 0xC;
}

void set_init_A4_flag() {
    plw[0].init_E3_flag = 1;
    plw[1].init_E3_flag = 1;
    plw[0].init_E4_flag = 1;
    plw[1].init_E4_flag = 1;
}

/* Xbox-only functions of this object (analysis-ps2map/xbgen.py checked each). */
s32 xb_FindEffect42(s16 num) {
    s16 ix;
    WORK_Other* ewk;

    for (ix = head_ix[4]; ix != -1; ix = ewk->wu.behind) {
        ewk = (WORK_Other*)frw[ix];

        if (ewk->wu.id == 0x42) {
            if (num == (ewk->master_priority & 0x3FFF)) {
                return 1;
            }

            break;
        }
    }

    return 0;
}

#if 0
/* PS2 C for functions not located in sf33rd.xbe yet. */

void disp_effect_work() {
    WORK* c_addr;
    s16 index;
    s16 curr_ix;
    s16 next_ix;
    s32 px;
    s32 py;

    if (Debug_w[0x29] == 0) {
        return;
    }

    px = 7;
    py = 15;

    for (index = 0; index <= 7; index += 1) {
        curr_ix = head_ix[index];
        px += 5;
        py = 14;

        for (curr_ix; curr_ix != -1; curr_ix = next_ix) {
            if (py > 49) {
                py = 14;
                px += 3;
            }

            c_addr = (WORK*)frw[curr_ix];
            next_ix = c_addr->behind;
            flPrintL(px, py, "%c%d", "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"[(c_addr->id / 10)], c_addr -> id % 10);
            py++;
        }
    }
}
#endif
