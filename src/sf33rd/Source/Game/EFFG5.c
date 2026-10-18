/* EFFG5.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * xb_effect_G5_draw 0x4B7F3 size 0x2C. FLAG: x86-only callees
 * sort_push_request8.
 * effect_G5_move 0x4B81F size 0x100.
 * effect_G5_init 0x4B91F size 0x8C.
 * setup_ase_extra 0x4B9AB size 0xA7.
 * Data: num_of_ase is 0x256850, 0x8 bytes compared.
 * Data: ase_dir_hosei is 0x256858, 0x30 bytes compared.
 * Data: ase_speed_hosei is 0x256888, 0x30 bytes compared.
 * Data: ase_delta_hosei is 0x2568B8, 0x30 bytes compared.
 * Globals: num_of_ase 0x256850, ase_dir_hosei 0x256858, ase_speed_hosei
 * 0x256888, ase_delta_hosei 0x2568B8, _plef_char_table 0x308B40,
 * Pause_Hit_Marks 0x7A88AC, Game_pause 0x7A89B0, EXE_flag 0xC7C834, frw
 * 0xC806A0.
 */

#include "structs.h"

#define EFFECT_MAX 128

s32 sort_push_request8(WORK* wk);
extern s8 Pause_Hit_Marks;
void add_pos_dir_064(WORK* wk, s16 sp);
void set_char_move_init(WORK* wk, s16 koc, s16 index);
s32 random_16();
extern s16 EXE_flag;
extern u8 Game_pause;
void char_move(WORK* wk);
void push_effect_work(WORK* wkhd);
s16 pull_effect_work(s16 index);
extern uintptr_t frw[EFFECT_MAX][448];
extern u32 _plef_char_table[];

const s16 num_of_ase[4] = { 0, 3, 5, 6 };

const s16 ase_dir_hosei[4][6] = {
    { -2, 3, -1, 30, 1, 33 }, { 2, -3, 1, 33, -1, 30 }, { 1, -2, 2, 34, 0, 31 }, { -1, 2, -2, 31, 0, 34 }
};

const s16 ase_speed_hosei[4][6] = { { 0x480, 0x500, 0x680, 0x400, 0x700, 0x500 },
                                    { 0x480, 0x500, 0x680, 0x400, 0x700, 0x500 },
                                    { 0x480, 0x500, 0x680, 0x400, 0x700, 0x500 },
                                    { 0x480, 0x500, 0x680, 0x400, 0x700, 0x500 } };

const s16 ase_delta_hosei[4][6] = { { -88, -96, -112, -80, -128, -88 },
                                    { -88, -96, -112, -80, -128, -88 },
                                    { -88, -96, -112, -80, -128, -88 },
                                    { -88, -96, -112, -80, -128, -88 } };

void effect_G5_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.my_col_mode = 0x4200;
        ewk->wu.my_col_code = 0x2020;
        add_pos_dir_064(&ewk->wu, ewk->wu.dir_old * 4);
        set_char_move_init(&ewk->wu, 0, (random_16() & 1) + 8);
        /* fallthrough */

    case 1:
        if (ewk->wu.dead_f == 1) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0]++;
            break;
        }

        if (Pause_Hit_Marks) {
            break;
        }

        if (EXE_flag == 0 && Game_pause == 0) {
            ewk->wu.dir_old += ewk->wu.dir_step;

            if (ewk->wu.dir_old < 0) {
                ewk->wu.dir_old = 0;
            }

            add_pos_dir_064(&ewk->wu, ewk->wu.dir_old);
            char_move(&ewk->wu);

            if (ewk->wu.cg_type == 0xFF || ewk->wu.dir_old < 0) {
                ewk->wu.disp_flag = 0;
                ewk->wu.routine_no[0]++;
                break;
            }
        }

        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos;
        sort_push_request8(&ewk->wu);
        break;

    case 2:
        ewk->wu.routine_no[0] = 3;
        break;

    default:
        push_effect_work(&ewk->wu);
        break;
    }
}

s32 effect_G5_init(WORK* wk, s16 dr, s16 sp, s16 dl) {
    WORK_Other* ewk;
    s16 ix;

    if ((ix = pull_effect_work(3)) == -1) {
        return -1;
    }

    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 165;
    ewk->wu.work_id = 16;
    ewk->wu.direction = dr;
    ewk->wu.dir_old = sp;
    ewk->wu.dir_step = dl;
    ewk->wu.my_family = wk->my_family;
    ewk->wu.xyz[0].disp.pos = wk->position_x;
    ewk->wu.xyz[1].disp.pos = wk->position_y;
    ewk->wu.position_z = wk->position_z + 1;
    *ewk->wu.char_table = _plef_char_table;
    return 0;
}

s32 setup_ase_extra(WORK* wk, u8 num) {
    s16 i;
    s16 way;
    s16 rnd_00;
    s16 rnd_01;

    if (num_of_ase[num] == 0) {
        return 0;
    }

    way = wk->direction * 4;
    rnd_00 = random_16() & 3;
    rnd_01 = random_16() & 3;

    for (i = 0; i < num_of_ase[num]; i++) {
        effect_G5_init(
            wk, way + ase_dir_hosei[rnd_00][i] & 0x3F, ase_speed_hosei[rnd_01][i], ase_delta_hosei[rnd_01][i]);
    }

    return 0;
}

void xb_effect_G5_draw(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 1:
        if (Pause_Hit_Marks == 0) {
            ewk->wu.position_x = ewk->wu.xyz[0].disp.pos;
            ewk->wu.position_y = ewk->wu.xyz[1].disp.pos;
            sort_push_request8(&ewk->wu);
        }

        break;
    }
}
