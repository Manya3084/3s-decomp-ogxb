/* Eff50.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * effect_50_move 0x52A0A size 0x1FA. Read against the x86: the unnamed array
 * at 0x7A88E0 is Plate_Y. The C is the PS2 C.
 * effect_50_init 0x52C04 size 0x157. Read against the x86: the unnamed dword
 * array at 0x7A843C is Synchro_Address; 0x267AA4 and 0x267D78 are position
 * tables. The C is the PS2 C.
 * Unnamed data used (not checked): effect_50_init: 0x267d78,0x267d7a,0x7a843c.
 * Globals: Plate_Pos_Data_79 0x267AA4, _sel_pl_char_table 0x2FE100, Play_Type
 * 0x7A812D, Plate_X 0x7A8140, Moving_Plate 0x7A81C2, Select_Arts 0x7A82F0,
 * Sel_Arts_Complete 0x7A87E0, Plate_Y 0x7A88E0, p1sw_0 0x7C557C, p2sw_0
 * 0x7C5B90, frw 0xC806A0.
 */

#include "structs.h"

#define EFFECT_MAX 128

extern u16 p2sw_0;
extern u16 p1sw_0;
extern s16 Sel_Arts_Complete[2];
extern u32* Synchro_Address[2][2];
extern s8 Select_Arts[2];
extern s8 Moving_Plate[2];
void set_char_move_init(WORK* wk, s16 koc, s16 index);
void char_move(WORK* wk);
void char_move_z(WORK* wk);
void push_effect_work(WORK* wkhd);
extern s16 Plate_X[2][3];
extern s16 Plate_Y[2][3];
s32 sort_push_request4(WORK* wk);
s16 pull_effect_work(s16 index);
extern uintptr_t frw[EFFECT_MAX][448];
extern u32 _sel_pl_char_table[];
s16 get_my_trans_mode(s16 curr);
extern const s16 Plate_Pos_Data_79[2][2][3][2];
extern u8 Play_Type;
extern const s16 EFF50_Correct_Data[2][2][2];
void set_char_move_init2(WORK* wk, s16 koc, s16 index, s16 ip, s16 scf);



void effect_50_move(WORK_Other* ewk) {
    WORK_Other* pwk;
    u16 sw;

    if (ewk->master_id) {
        sw = p2sw_0 & 3;
    } else {
        sw = p1sw_0 & 3;
    }

    if (Sel_Arts_Complete[ewk->master_id] < 0) {
        ewk->wu.routine_no[0] = 3;
        ewk->wu.dir_timer = 1;
        return;
    }

    pwk = (WORK_Other*)Synchro_Address[ewk->master_id][(ewk->wu.direction - 1) ^ 1];

    switch (ewk->wu.routine_no[0]) {
    case 0:
        if (Select_Arts[ewk->master_id] == 0) {
            ewk->wu.routine_no[0]++;
            ewk->wu.disp_flag = 1;
        }

        break;

    case 1:
        if (Sel_Arts_Complete[ewk->master_id]) {
            ewk->wu.routine_no[0] = 3;
            ewk->wu.dir_timer = 5;
        } else if (Moving_Plate[ewk->master_id] == ewk->wu.direction && ewk->wu.dm_vital == 0) {
            ewk->wu.routine_no[0]++;
            ewk->wu.char_index++;
            ewk->wu.dmcal_m += 3;
            ewk->wu.dmcal_d--;
            set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        }

        if (ewk->wu.dm_vital == 0) {
            char_move(&ewk->wu);
        }

        break;

    case 2:
        if (ewk->wu.cg_type != 0 && sw != ewk->wu.direction) {
            ewk->wu.routine_no[0] = 1;
            ewk->wu.char_index--;
            set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
            ewk->wu.cg_ix = pwk->wu.cg_ix - ewk->wu.cgd_type;
            char_move_z(&ewk->wu);
            ewk->wu.cg_ctr = pwk->wu.cg_ctr;
            ewk->wu.dmcal_m -= 3;
            ewk->wu.dmcal_d++;

            if (ewk->wu.direction != 1) {
                break;
            }
        }

        char_move(&ewk->wu);
        break;

    case 3:
        if (--ewk->wu.dir_timer != 0) {
            break;
        }

        ewk->wu.disp_flag = 0;
        ewk->wu.routine_no[0]++;
        return;

    default:
        push_effect_work(&ewk->wu);
        return;
    }

    ewk->wu.xyz[0].disp.pos = ewk->wu.dmcal_m + Plate_X[ewk->master_id][0];
    ewk->wu.xyz[1].disp.pos = ewk->wu.dmcal_d + Plate_Y[ewk->master_id][0];
    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0xFFFF;
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0xFFFF;
    sort_push_request4(&ewk->wu);
}

s32 effect_50_init(s16 PL_id, s16 Direction, s16 dm_vital) {
    WORK_Other* ewk;
    s16 ix;

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }

    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 50;
    ewk->wu.work_id = 16;
    ewk->wu.my_col_code = 0x2090;
    ewk->wu.my_family = 3;
    ewk->master_id = PL_id;
    *ewk->wu.char_table = _sel_pl_char_table;
    ewk->wu.dm_vital = dm_vital;
    ewk->wu.direction = Direction;
    ewk->wu.my_mts = 13;
    ewk->wu.my_trans_mode = get_my_trans_mode(ewk->wu.my_mts);

    if (dm_vital == 0) {
        Synchro_Address[ewk->master_id][ewk->wu.direction - 1] = (u32*)ewk;
    }

    ewk->wu.xyz[0].disp.pos = Plate_Pos_Data_79[Play_Type][ewk->master_id][0][0];
    ewk->wu.xyz[1].disp.pos = Plate_Pos_Data_79[Play_Type][ewk->master_id][0][1];

    if (dm_vital == 1) {
        ewk->wu.char_index = 31;
        ewk->wu.dir_step = Direction - 1;
    } else {
        ewk->wu.char_index = ((Direction - 1) * 2) + 27;
        ewk->wu.dir_step = 0;
    }

    ewk->wu.dmcal_m = EFF50_Correct_Data[Direction - 1][dm_vital][0];
    ewk->wu.dmcal_d = EFF50_Correct_Data[Direction - 1][dm_vital][1];
    ewk->wu.position_z = 30;
    set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
    return 0;
}
