/* EFF22.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * effect_22_move 0x386F3 size 0x10D.
 * effect_22_init 0x38800 size 0x9C.
 * add_x_sub is folded into 0xEF072.
 * add_y_sub is folded into 0xEF088.
 * all_cgps_put_back is folded into 0x4384A.
 * Data: snow_pos_tbl is 0x24D6A8, 0x30 bytes compared.
 * Data: snow_sp is 0x24D6D8, 0x300 bytes compared.
 * Globals: snow_pos_tbl 0x24D6A8, snow_sp 0x24D6D8, _rca_char_table 0x3061C0,
 * Game_pause 0x7A89B0, EXE_flag 0xC7C834, frw 0xC806A0.
 */

#include "structs.h"

#define EFFECT_MAX 128

void sub_000EF072(WORK_Other* ewk);
void sub_000EF088(WORK_Other* ewk);
void sub_0004384A(WORK* wk);
s32 obr_no_disp_check();
s32 compel_dead_check(WORK_Other* ewk);
void set_char_move_init(WORK* wk, s16 koc, s16 index);
extern s16 EXE_flag;
extern u8 Game_pause;
void disp_pos_trans_entry_r(WORK_Other* ewk);
void push_effect_work(WORK* wkhd);
s16 pull_effect_work(s16 index);
extern uintptr_t frw[EFFECT_MAX][448];
extern u32 _rca_char_table[];

const s16 snow_pos_tbl[12][2] = { { 112, 416 }, { 176, 256 }, { 216, 384 }, { 288, 448 }, { 368, 288 }, { 448, 384 },
                                  { 512, 240 }, { 576, 432 }, { 640, 328 }, { 704, 488 }, { 816, 256 }, { 880, 384 } };

const s32 snow_sp[4][12][4] = { { { 0x200, 0, -0x2000, 0 },
                                  { 0x400, 0, -0x1800, 0 },
                                  { 0x800, 0, -0x2000, 0 },
                                  { -0x200, 0, -0x2200, 0 },
                                  { 0x1200, 0, -0x2000, 0 },
                                  { 0, 0, -0x1C00, 0 },
                                  { -0x800, 0, -0x2100, 0 },
                                  { 0x400, 0, -0x1800, 0 },
                                  { 0x800, 0, -0x1E00, 0 },
                                  { -0x100, 0, -0x2000, 0 },
                                  { -0x400, 0, -0x2400, 0 },
                                  { -0x80, 0, -0x2800, 0 } },
                                {
                                    { 0x100, 0, -0x2100, 0 },
                                    { 0x200, 0, -0x1900, 0 },
                                    { -0x100, 0, -0x2500, 0 },
                                    { 0xC00, 0, -0x2300, 0 },
                                    { 0x1200, 0, -0x2000, 0 },
                                    { 0x1000, 0, -0x1F00, 0 },
                                    { -0x800, 0, -0x2100, 0 },
                                    { 0x1200, 0, -0x2700, 0 },
                                    { 0x200, 0, -0x2000, 0 },
                                    { -0x80, 0, -0x2300, 0 },
                                    { 0x80, 0, -0x1600, 0 },
                                    { -0x200, 0, -0x2900, 0 },
                                },
                                {
                                    { 0x100, 0, -0x1A00, 0 },
                                    { 0x200, 0, -0x2200, 0 },
                                    { 0x400, 0, -0x2600, 0 },
                                    { -0x1000, 0, -0x1200, 0 },
                                    { 0x1200, 0, -0x2000, 0 },
                                    { 0x2000, 0, -0x2000, 0 },
                                    { 0x800, 0, -0x1E00, 0 },
                                    { -0x400, 0, -0x2F00, 0 },
                                    { 0x180, 0, -0x2600, 0 },
                                    { -0x80, 0, -0x2200, 0 },
                                    { 0x100, 0, -0x1A00, 0 },
                                    { 0, 0, -0x2800, 0 },
                                },
                                { { 0x180, 0, -0x1A00, 0 },
                                  { 0, 0, -0x1400, 0 },
                                  { 0x1200, 0, -0x2400, 0 },
                                  { -0x800, 0, -0x2600, 0 },
                                  { 0x1200, 0, -0x2000, 0 },
                                  { -0x1000, 0, -0x1200, 0 },
                                  { 0x800, 0, -0x1E00, 0 },
                                  { 0x100, 0, -0x2200, 0 },
                                  { -0x100, 0, -0x1C00, 0 },
                                  { 0x100, 0, -0x1400, 0 },
                                  { -0x80, 0, -0x1800, 0 },
                                  { 0, 0, -0x2000, 0 } } };

/* Rewritten to match retail (tools/permute.py): <= 23 -> < 24. */
void effect_22_move(WORK_Other* ewk) {
    const s32* ptr;

    if (obr_no_disp_check()) {
        return;
    }

    if (compel_dead_check(ewk) != 0) {
        ewk->wu.routine_no[0] = 99;
        ewk->wu.disp_flag = 0;
        return;
    }

    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.dead_f = 1;
        set_char_move_init(&ewk->wu, 0, 11);
        ewk->wu.disp_flag = 1;
        ewk->wu.old_rno[0] = 0;
        /* fallthrough */

    case 1:
        ewk->wu.routine_no[0]++;
        ptr = &snow_sp[ewk->wu.old_rno[0]][ewk->wu.type][0];
        ewk->wu.mvxy.a[0].sp = *ptr++;
        ewk->wu.mvxy.d[0].sp = *ptr++;
        ewk->wu.mvxy.a[1].sp = *ptr++;
        ewk->wu.mvxy.d[1].sp = *ptr++;
        ewk->wu.xyz[0].disp.pos = snow_pos_tbl[ewk->wu.type][0];
        ewk->wu.xyz[1].disp.pos = snow_pos_tbl[ewk->wu.type][1];
        ewk->wu.old_rno[0]++;
        ewk->wu.old_rno[0] &= 3;
        break;

    case 2:
        if (!EXE_flag && !Game_pause) {
            sub_000EF072(ewk);
            sub_000EF088(ewk);

            if (ewk->wu.xyz[1].disp.pos < 24) {
                ewk->wu.routine_no[0] = 1;
            }
        }

        disp_pos_trans_entry_r(ewk);
        break;

    default:
        sub_0004384A(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}

s32 effect_22_init(s32 /* unused */) {
    s16 get_my_trans_mode(s32 curr);

    s16 ix;
    s16 i;
    WORK_Other* ewk;

    for (i = 0; i < 12; i++) {
        if ((ix = pull_effect_work(4)) == -1) {
            return -1;
        }

        ewk = (WORK_Other*)frw[ix];
        ewk->wu.be_flag = 1;
        ewk->wu.id = 22;
        ewk->wu.work_id = 16;
        ewk->wu.cgromtype = 1;
        ewk->wu.type = i;
        ewk->wu.my_family = 2;
        ewk->wu.my_col_mode = 0x4200;
        ewk->wu.my_col_code = 300;
        ewk->wu.my_mts = 7;
        ewk->wu.my_trans_mode = get_my_trans_mode(ewk->wu.my_mts);
        ewk->wu.char_table[0] = _rca_char_table;
        ewk->wu.my_priority = ewk->wu.position_z = 10;
    }

    return 0;
}
