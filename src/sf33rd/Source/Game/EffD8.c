/* EffD8.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * Setup_EffD8_Pos 0x569D9 size 0x44.
 * Setup_Face_Offset_X 0x56A1D size 0x1A.
 * effect_D8_move 0x56A37 size 0x1F2.
 * effect_D8_init 0x56C29 size 0xD7. Read against the x86: 0x2B is (Type * 3) +
 * 43 with lea. The C is the PS2 C.
 * Data: D8_Priority_Data is 0x25C3C0, 0x4 bytes compared.
 * Globals: D8_Priority_Data 0x25C3C0, Face_Pos_Data 0x267658,
 * _sel_pl_char_table 0x2FE100, Play_Type 0x7A812D, Sel_PL_Complete 0x7A81BC,
 * Cursor_X 0x7A81D4, ID_of_Face 0x7A8240, Mode_Type 0x7A825A, Unit_Of_Timer
 * 0x7A82A8, Complete_Face 0x7A847C, New_Challenger 0x7A86D6, Cursor_Y
 * 0x7A8812, S_No 0x7A89C8, Select_Timer 0x7A89D1, Select_Start 0x7A8A36,
 * Play_Type_1st 0x7A9AA4, frw 0xC806A0.
 */

#include "structs.h"

#define EFFECT_MAX 128

extern u8 Mode_Type;
extern s8 New_Challenger;
extern u8 S_No[4];
extern s8 Complete_Face;
void set_char_move_init(WORK* wk, s16 koc, s16 index);
extern s8 Cursor_X[2];
extern s8 Cursor_Y[2];
extern u8 Play_Type;
s32 Setup_Face_Offset_X(s16 x);
extern s16 Play_Type_1st;
void Setup_EffD8_Pos(WORK_Other* ewk, s16 );
void set_char_move_init2(WORK* wk, s16 koc, s16 index, s16 ip, s16 scf);
extern s16 Sel_PL_Complete[2];
void char_move(WORK* wk);
extern s8 Select_Start[2];
extern s8 Select_Timer;
extern s16 Unit_Of_Timer;
void push_effect_work(WORK* wkhd);
s32 sort_push_request4(WORK* wk);
s16 pull_effect_work(s16 index);
extern uintptr_t frw[EFFECT_MAX][448];
extern u32 _sel_pl_char_table[];
s16 get_my_trans_mode(s16 curr);
extern s8 ID_of_Face[3][8];
extern const s16 Face_Pos_Data[20][2];

const u8 D8_Priority_Data[4] = { 55, 55, 52, 53 };

// Funcs

void effect_D8_move(WORK_Other* ewk) {
    s16 offset_x;

    ewk->wu.hit_quake += 1;

    switch (ewk->wu.routine_no[0]) {
    case 0:
        if (((Mode_Type == 3) || (Mode_Type == 4)) && (ewk->master_id == New_Challenger) && (S_No[3] < 2)) {
            return;
        }

        if (Complete_Face <= 0) {
            ewk->wu.routine_no[0] += 1;
            ewk->wu.dir_timer = 10;
        }

        break;

    case 1:
        if (--ewk->wu.dir_timer == 0) {
            ewk->wu.routine_no[0] += 1;
            ewk->wu.disp_flag = 1;
            set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        }

        break;

    case 2:
        if ((ewk->wu.vital_new != Cursor_X[ewk->master_id]) || (ewk->wu.vital_old != Cursor_Y[ewk->master_id])) {
            ewk->wu.vital_new = Cursor_X[ewk->master_id];
            ewk->wu.vital_old = Cursor_Y[ewk->master_id];

            if (Play_Type == 1) {
                offset_x = Setup_Face_Offset_X(99);
            } else {
                offset_x = Setup_Face_Offset_X(Play_Type_1st);
            }

            Setup_EffD8_Pos(ewk, offset_x);
            set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, (ewk->wu.cg_ix / ewk->wu.cgd_type) + 1, 0);
        }

        if (Sel_PL_Complete[ewk->master_id]) {
            ewk->wu.routine_no[0] += 1;
            ewk->wu.dir_timer = 20;
            ewk->wu.char_index += 1;
            set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        } else {
            char_move(&ewk->wu);
        }

        break;

    case 3:
        if (--ewk->wu.dir_timer) {
            char_move(&ewk->wu);
        } else {
            ewk->wu.routine_no[0] += 1;
            Sel_PL_Complete[ewk->master_id] = -0x8000;

            if (Select_Start[ewk->master_id] == 0) {
                Select_Timer = 32;
            }

            Unit_Of_Timer = 50;
            ewk->wu.char_index += 1;
            set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        }

        break;

    case 4:
        ewk->wu.routine_no[0] += 1;
        ewk->wu.disp_flag = 0;
        break;

    default:
        push_effect_work(&ewk->wu);
        return;
    }

    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0xFFFF;
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0xFFFF;

    if (ewk->wu.direction == 0) {
        if (ewk->wu.hit_quake & 1) {
            ewk->wu.position_z = 56;
        } else {
            ewk->wu.position_z = 54;
        }
    }

    sort_push_request4(&ewk->wu);
}

s32 effect_D8_init(s16 PL_id, s16 Type) {
    WORK_Other* ewk;
    s16 ix;
    s16 offset_x;

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }

    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 0x8A;
    ewk->wu.work_id = 0x10;
    ewk->wu.my_col_code = 0x90;
    ewk->wu.my_family = 2;
    ewk->wu.char_table[0] = _sel_pl_char_table;
    ewk->wu.char_index = (Type * 3) + 43;
    ewk->master_id = PL_id;
    ewk->wu.vital_new = Cursor_X[ewk->master_id];
    ewk->wu.vital_old = Cursor_Y[ewk->master_id];
    ewk->wu.position_z = D8_Priority_Data[Type];
    ewk->wu.direction = Type;
    ewk->wu.hit_quake = 0;
    ewk->wu.my_mts = 0xD;
    ewk->wu.my_trans_mode = get_my_trans_mode(ewk->wu.my_mts);
    offset_x = Setup_Face_Offset_X(Play_Type_1st);
    Setup_EffD8_Pos(ewk, offset_x);
    return 0;
}

void Setup_EffD8_Pos(WORK_Other* ewk, s16 /* unused */) {
    s16 xx = ID_of_Face[Cursor_Y[ewk->master_id]][Cursor_X[ewk->master_id]];
    ewk->wu.xyz[0].disp.pos = Face_Pos_Data[xx][0] + 512;
    ewk->wu.xyz[1].disp.pos = Face_Pos_Data[xx][1] + 0;
}

s32 Setup_Face_Offset_X(s16 x) {
    switch (x) {
    case 0:
        return 0;

    case 1:
        return -184;

    default:
        return -92;
    }
}
