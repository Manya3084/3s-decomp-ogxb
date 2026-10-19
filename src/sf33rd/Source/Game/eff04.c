/* Effect 04, retail sf33rd.xbe.
 * effect_04_move is 0x32973 size 0x8A and is interior.
 * effect_04_init is 0x329FD size 0xC3 and is interior.
 * The pull failure is an early ret.
 * 0x3292F stays unnamed. 0x32AC0 stays unnamed.
 *
 * The init stores my_family, type, and master_player
 * before be_flag. It stores char_table and dmcal_m
 * between the pushes and the call. The C keeps the
 * PlayStation 2 order.
 *
 * EFF04_Cursor_Data is 0x24B0E0. Each row is eight
 * pairs. Rows 1, 3, 4, and 5 match, and their eighth
 * pair is 0. Rows 0, 2, and 6 differ. The table holds
 * the Xbox rows, read from the XBE. The character table immediate is
 * 0x2FE100. Those bytes were not compared.
 * Menu_Suicide is 0x7A87A0. Menu_Cursor_Y is 0x7A827E.
 * bg_w is 0x7BC520. bgw[0] is 0x7BC558.
 * char_move is 0x2008E.
 * set_char_move_init is 0x200A9.
 * sort_push_request4 is 0x9E092.
 * push_effect_work is 0x4AC6C.
 * pull_effect_work is 0x4A6A8.
 * get_my_trans_mode is named. frw is 0xC806A0
 * and each object is 0x700 bytes.
 */

#include "types.h"
#include "structs.h"






typedef u8 EffectRow[0x700];

#if defined(__i386__)
_Static_assert(__builtin_offsetof(WORK, disp_flag) == 1, "disp_flag");
_Static_assert(__builtin_offsetof(WORK, type) == 4, "type");
_Static_assert(__builtin_offsetof(WORK, work_id) == 6, "work_id");
_Static_assert(__builtin_offsetof(WORK, id) == 8, "id");
_Static_assert(__builtin_offsetof(WORK, routine_no) == 0x24, "routine_no");
_Static_assert(__builtin_offsetof(WORK, position_x) == 0x54, "position_x");
_Static_assert(__builtin_offsetof(WORK, position_y) == 0x56, "position_y");
_Static_assert(__builtin_offsetof(WORK, position_z) == 0x58, "position_z");
_Static_assert(__builtin_offsetof(WORK, dir_timer) == 0x9A, "dir_timer");
_Static_assert(__builtin_offsetof(WORK, dmcal_m) == 0xA4, "dmcal_m");
_Static_assert(__builtin_offsetof(WORK, char_table) == 0x1AC, "char_table");
_Static_assert(__builtin_offsetof(WORK, my_col_code) == 0x23E, "my_col_code");
_Static_assert(__builtin_offsetof(WORK, my_priority) == 0x240, "my_priority");
_Static_assert(__builtin_offsetof(WORK, my_family) == 0x242, "my_family");
_Static_assert(__builtin_offsetof(WORK, my_mts) == 0x24C, "my_mts");
_Static_assert(__builtin_offsetof(WORK, my_trans_mode) == 0x254, "my_trans_mode");
_Static_assert(sizeof(WORK) == 0x388, "WORK");
_Static_assert(__builtin_offsetof(WORK_Other, master_player) == 0x390, "master_player");
_Static_assert(__builtin_offsetof(BGW, wxy[0].disp.pos) == 0x22, "wxy");
_Static_assert(sizeof(BGW) == 0x90, "BGW");
_Static_assert(__builtin_offsetof(BG, bgw) == 0x38, "bgw");
#endif

extern EffectRow frw[];
/* The Xbox rows (eight pairs each), read from the XBE. */
const s16 EFF04_Cursor_Data[7][8][2] = { { { 8, 164 },
                                           { 24, 144 },
                                           { 40, 124 },
                                           { 56, 104 },
                                           { 72, 84 },
                                           { 88, 64 },
                                           { 104, 44 },
                                           { 120, 24 } },
                                         { { 16, 164 },
                                           { 32, 142 },
                                           { 48, 120 },
                                           { 64, 98 },
                                           { 80, 76 },
                                           { 96, 54 },
                                           { 112, 32 },
                                           { 0, 0 } },
                                         { { 48, 132 },
                                           { 72, 100 },
                                           { 112, 68 },
                                           { 112, 68 },
                                           { 0, 0 },
                                           { 0, 0 },
                                           { 0, 0 },
                                           { 0, 0 } },
                                         { { 48, 156 },
                                           { 64, 124 },
                                           { 80, 92 },
                                           { 96, 60 },
                                           { 112, 28 },
                                           { 0, 0 },
                                           { 0, 0 },
                                           { 0, 0 } },
                                         { { 32, 156 },
                                           { 48, 132 },
                                           { 64, 108 },
                                           { 80, 84 },
                                           { 96, 60 },
                                           { 112, 36 },
                                           { 0, 0 },
                                           { 0, 0 } },
                                         { { 24, 132 },
                                           { 48, 92 },
                                           { 112, 52 },
                                           { 0, 0 },
                                           { 0, 0 },
                                           { 0, 0 },
                                           { 0, 0 },
                                           { 0, 0 } },
                                         { { -16, 163 },
                                           { 0, 145 },
                                           { 16, 127 },
                                           { 32, 145 },
                                           { 48, 109 },
                                           { 68, 68 },
                                           { 120, 28 },
                                           { 0, 0 } } };
extern u32 _sel_pl_char_table[];
extern u8 Menu_Suicide[4];
extern s8 Menu_Cursor_Y[2];
extern BG bg_w;

void char_move(WORK *wk);
void set_char_move_init(WORK *wk, s16 koc, s16 index);
void sort_push_request4(WORK *wk);
void push_effect_work(WORK *wk);
s16 pull_effect_work(s16 index);
s16 get_my_trans_mode(s16 curr);

void effect_04_move(WORK_Other *ewk) {
    if (Menu_Suicide[ewk->master_player]) {
        push_effect_work(&ewk->wu);
        return;
    }

    switch (ewk->wu.routine_no[0]) {
    case 0:
        if (--ewk->wu.dir_timer) {
            break;
        }

        ewk->wu.routine_no[0]++;
        /* fallthrough */

    case 1:
        ewk->wu.position_x = EFF04_Cursor_Data[ewk->wu.type][Menu_Cursor_Y[0]][0] + ewk->wu.dmcal_m;
        ewk->wu.position_y = EFF04_Cursor_Data[ewk->wu.type][Menu_Cursor_Y[0]][1] + 0;
        char_move(&ewk->wu);
        sort_push_request4(&ewk->wu);
        break;
    }
}

s32 effect_04_init(s16 Death_Type, s16 cg_type, s16 sync_bg, s16 priority) {
    WORK_Other *ewk;
    s16 ix;

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }

    ewk = (WORK_Other *)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.disp_flag = 1;
    ewk->wu.id = 4;
    ewk->wu.work_id = 16;
    ewk->wu.my_family = sync_bg + 1;
    ewk->wu.my_col_code = 0x1AC;
    ewk->wu.dir_timer = 20;
    ewk->wu.type = cg_type;
    ewk->master_player = Death_Type;
    ewk->wu.my_priority = ewk->wu.position_z = priority;
    ewk->wu.my_mts = 13;
    ewk->wu.my_trans_mode = get_my_trans_mode(ewk->wu.my_mts);
    ewk->wu.char_table[0] = _sel_pl_char_table;
    ewk->wu.dmcal_m = bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos;
    set_char_move_init(&ewk->wu, 0, 62);
    return 0;
}

/* Xbox-only functions of this object (analysis-ps2map/xbgen.py checked each). */
void xb_effect_04_draw(WORK_Other* ewk) {
    ewk->wu.position_x = EFF04_Cursor_Data[ewk->wu.type][Menu_Cursor_Y[0]][0] + ewk->wu.dmcal_m;
    ewk->wu.position_y = EFF04_Cursor_Data[ewk->wu.type][Menu_Cursor_Y[0]][1] + 0;
    sort_push_request4(&ewk->wu);
}
