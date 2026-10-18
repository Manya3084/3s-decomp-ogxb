/* EFF77.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * effect_77_move 0x40FC8 size 0x29E.
 * effect_77_init 0x41266 size 0x5E. Read against the x86: the unnamed word at
 * 0xCB87DA is cleared before pull_effect_work. The C is the PS2 C.
 * Bg_Off_R is folded into 0xAF4C2.
 * Bg_On_R is folded into 0xAF4AA.
 * all_cgps_put_back is folded into 0x4384A.
 * Data: chk77_flag: defined elsewhere on Xbox.
 * Data: eff77_data_tbl is 0x24F69C, 0x1C bytes compared, found by the bytes.
 * Data: eff77_col_tbl is 0x24F6B8, 0x8 bytes compared, found by the bytes.
 * Globals: eff77_data_tbl 0x24F69C, eff77_col_tbl 0x24F6B8, ake_bg_off
 * 0x275F5C, Flash_MT 0x7A8266, Suicide 0x7A8268, another_bg 0x7A8910,
 * Extra_Break 0x7A89A0, Game_pause 0x7A89B0, akebono_flag 0x7BC4A9, sa_pa_flag
 * 0x7BC4AA, bg_w 0x7BC520, EXE_flag 0xC7C834, plw 0xC7CEA0, frw 0xC806A0.
 */

#include "structs.h"

#define EFFECT_MAX 128

void sub_000AF4C2(u16 s_prm);
void sub_000AF4AA(u16 s_prm);
void sub_0004384A(WORK* wk);
extern s8 another_bg[2];
extern s8 Flash_MT[2];
extern s8 akebono_flag;
void scr_calc(u8 bgnm);
extern u8 Game_pause;
extern s16 EXE_flag;
extern PLW plw[2];
extern u8 Extra_Break;
extern s8 sa_pa_flag;
extern const u8 ake_bg_off[20];
extern BG bg_w;
void overwrite_panel(u32 color, u8 priority);
extern s8 Suicide[8];
void push_effect_work(WORK* wkhd);
s16 pull_effect_work(s16 index);
extern uintptr_t frw[EFFECT_MAX][448];

extern s16 chk77_flag;

const s16 eff77_data_tbl[7][2] = { { 64, 0 }, { 2, 0 }, { 1, 1 }, { 32, 1 }, { 22, 1 }, { 1, 0 }, { 1, 0 } };

const u32 eff77_col_tbl[2] = { 0xFFFFFFFF, 0xFF000000 };

void effect_77_move(WORK_Other* ewk) {
    s16 i;
    u16 bg;
    u16 mask;

    u16 assign1;
    u16 assign2;
    u16 assign3;

    another_bg[0] = another_bg[1] = 0;
    Flash_MT[0] = Flash_MT[1] = 0;

    if (akebono_flag) {
        ewk->wu.routine_no[0] = 99;
    }

    for (i = 0; i < 3; i++) {
        scr_calc(i);
    }

    switch (ewk->wu.routine_no[0]) {
    case 0:
        if (Game_pause || EXE_flag) {
            break;
        }

        ewk->wu.routine_no[0]++;
        plw[0].wu.disp_flag = 0;
        plw[1].wu.disp_flag = 0;

        if (ewk->wu.type == 0) {
            Extra_Break = 1;
        }

        /* fallthrough */

    case 1:
        if (Game_pause || EXE_flag) {
            break;
        }

        ewk->wu.routine_no[0]++;
        sa_pa_flag = 1;
        bg = ake_bg_off[bg_w.stage];
        mask = 1;

        for (i = 0; i < 4; i++, assign1 = mask *= 2) {
            if (bg & mask) {
                sub_000AF4C2(1 << i);
            }
        }

        ewk->wu.old_rno[0] = eff77_data_tbl[ewk->wu.type][0];
        ewk->wu.old_rno[1] = eff77_data_tbl[ewk->wu.type][1];
        overwrite_panel(eff77_col_tbl[ewk->wu.old_rno[1]], 0x46);
        break;

    case 2:
        if (Game_pause || EXE_flag) {
            overwrite_panel(eff77_col_tbl[ewk->wu.old_rno[1]], 0x46);
            break;
        }

        ewk->wu.routine_no[0]++;
        bg = ake_bg_off[bg_w.stage];
        mask = 1;

        for (i = 0; i < 4; i++, assign2 = mask *= 2) {
            if (bg & mask) {
                sub_000AF4C2(1 << i);
            }
        }

        sa_pa_flag = 1;
        /* fallthrough */

    case 3:
        if (Suicide[6]) {
            ewk->wu.old_rno[0] = 0;
        }

        if (!Game_pause && !EXE_flag) {
            ewk->wu.old_rno[0]--;

            if (ewk->wu.old_rno[0] <= 0) {
                sa_pa_flag = 0;
                ewk->wu.routine_no[0]++;
                plw[0].wu.disp_flag = 1;
                plw[1].wu.disp_flag = 1;
                overwrite_panel(eff77_col_tbl[ewk->wu.old_rno[1]], 0x46);
                bg = ake_bg_off[bg_w.stage];
                mask = 1;

                for (i = 0; i < 4; i++, assign3 = mask *= 2) {
                    if (bg & mask) {
                        sub_000AF4AA(1 << i);
                    }
                }

                break;
            }

            sa_pa_flag = 1;
        }

        overwrite_panel(eff77_col_tbl[ewk->wu.old_rno[1]], 0x46);
        break;

    case 4:
        if (Game_pause || EXE_flag) {
            break;
        }

        ewk->wu.routine_no[0]++;

        if (ewk->wu.type == 0) {
            Extra_Break = 0;
        }

        break;

    default:
        if (!Game_pause && !EXE_flag) {
            sa_pa_flag = 0;
            sub_0004384A(&ewk->wu);
            push_effect_work(&ewk->wu);
        }

        break;
    }
}

s32 effect_77_init(u8 /* unused */, u8 data) {
    WORK_Other* ewk;
    s16 ix;

    chk77_flag = 0;

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }

    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 77;
    ewk->wu.type = data;
    another_bg[0] = another_bg[1] = 0;
    Flash_MT[0] = Flash_MT[1] = 0;
    sa_pa_flag = 1;
    return 0;
}
