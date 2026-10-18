/* EFF63.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * effect_63_move 0x3ED67 size 0x5B.
 * EFF63_SLIDE_IN 0x3EDC2 size 0x10A. Read against the x86: the unnamed words
 * are a position table at 0x2680C4. The C is the PS2 C.
 * Setup_Letter_63 0x3EECC size 0x78. Read against the x86: 0x15 is the
 * 21-entry row. Letter_Data_63 is 0x32B088. Its second row differs on Xbox:
 * eight screen sizes, 86% to 100% in steps of 2, where the PS2 build has 94%
 * to 100%. The C table is changed to match and all 63 entries were compared
 * with the XBE.
 * Disp_63_Sub 0x3EF44 size 0x5C. Read against the x86: all four cases differ
 * on Xbox. X_Adjust and Y_Adjust are divided by 4 (signed) before the + 10,
 * and Disp_Size_H and Disp_Size_V have 86 subtracted instead of 94, matching
 * the 86% to 100% size list. X_Adjust is 0x7C5850. Y_Adjust is 0x7C55EC.
 * Disp_Size_H is 0x7C55FC. Disp_Size_V is 0x7C56A0. The C is changed to match.
 * EFF63_WAIT 0x3EFA0 size 0x29.
 * effect_63_init 0x3EFC9 size 0xBA.
 * EFF63_CHAR_CHANGE is folded into 0x4384A with 25 other bodies. Unnamed.
 * EFF63_SUDDENLY is folded into 0x4384A with 25 other bodies. Unnamed.
 * Data: Letter_Data_63: not located in the XBE, PS2 initializer kept.
 * Data: EFF63_Jmp_Tbl is 0x24F2F4, 4 entries compared.
 * Globals: EFF63_Jmp_Tbl 0x24F2F4, Menu_Cursor_Y 0x7A827E, Order 0x7A8380,
 * Order_Timer 0x7A8480, bg_w 0x7BC520, sys_w 0x7C5940, frw 0xC806A0.
 */

#include "structs.h"

#define NULL 0
#define EFFECT_MAX 128

void EFF63_WAIT(WORK_Other_CONN* ewk);
void EFF63_SLIDE_IN(WORK_Other_CONN* ewk);
void EFF63_CHAR_CHANGE(WORK_Other_CONN* /* unused */);
void EFF63_SUDDENLY(WORK_Other_CONN* /* unused */);
s32 Check_Die_61(WORK_Other* ewk);
void push_effect_work(WORK* wkhd);
extern s8 Menu_Cursor_Y[2];
s32 sort_push_request3(WORK* wk);
extern u8 Order[148];
void Disp_63_Sub(WORK_Other_CONN* ewk);
extern u8 Order_Timer[148];
extern BG bg_w;
extern const s16 Slide_Pos_Data_63[][2];
s16 pull_effect_work(s16 index);
extern uintptr_t frw[EFFECT_MAX][448];
s16 get_my_trans_mode(s16 curr);
extern s32 X_Adjust;
extern s32 Y_Adjust;
extern u8 Disp_Size_H;
extern u8 Disp_Size_V;
extern struct _SYSTEM_W sys_w;
void Setup_Letter_63(WORK_Other_CONN* ewk, s16 disp_index);

const s8* Letter_Data_63[3][21] = { { "-10", "-9", "-8", "-7", "-6", "-5", "-4", "-3", "-2", "-1", "0",
                                      "1",   "2",  "3",  "4",  "5",  "6",  "7",  "8",  "9",  "10" },
                                    /* Xbox: eight sizes from 86%; the PS2 build lists 94% to 100%. */
                                    { "86%", "88%", "90%", "92%", "94%", "96%", "98%", "100%", NULL, NULL, NULL,
                                      NULL,  NULL,  NULL,  NULL,   NULL, NULL, NULL, NULL, NULL, NULL },
                                    { "OFF", "ON", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
                                      NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL } };

void (*const EFF63_Jmp_Tbl[4])() = { EFF63_WAIT, EFF63_SLIDE_IN, EFF63_CHAR_CHANGE, EFF63_SUDDENLY };

void effect_63_move(WORK_Other_CONN* ewk) {
    if (Check_Die_61((WORK_Other*)ewk) != 0) {
        push_effect_work(&ewk->wu);
        return;
    }

    EFF63_Jmp_Tbl[ewk->wu.routine_no[0]](ewk);
    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0xFFFF;
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0xFFFF;

    if (Menu_Cursor_Y[0] == ewk->wu.type) {
        ewk->wu.my_clear_level = 0;
    } else {
        ewk->wu.my_clear_level = 128;
    }

    sort_push_request3(&ewk->wu);
}

void EFF63_WAIT(WORK_Other_CONN* ewk) {
    if ((ewk->wu.routine_no[0] = Order[ewk->wu.dir_old])) {
        ewk->wu.routine_no[1] = 0;
    }

    Disp_63_Sub(ewk);
}

void EFF63_SLIDE_IN(WORK_Other_CONN* ewk) {
    if (Order[ewk->wu.dir_old] != 1) {
        ewk->wu.routine_no[0] = Order[ewk->wu.dir_old];
        ewk->wu.routine_no[1] = 0;
        return;
    }

    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (--Order_Timer[ewk->wu.dir_old]) {
            break;
        }

        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.xyz[0].disp.pos =
            bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos + Slide_Pos_Data_63[ewk->wu.type][0] + 384;
        ewk->wu.xyz[1].disp.pos = bg_w.bgw[ewk->wu.my_family - 1].wxy[1].disp.pos + Slide_Pos_Data_63[ewk->wu.type][1];
        ewk->wu.position_z = 68;
        ewk->wu.hit_quake = bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos + Slide_Pos_Data_63[ewk->wu.type][0];
        ewk->wu.mvxy.a[0].sp = -0x400000;
        ewk->wu.mvxy.d[0].sp = 0x50000;
        break;

    default:
        ewk->wu.xyz[0].cal += ewk->wu.mvxy.a[0].sp;
        ewk->wu.mvxy.a[0].sp += ewk->wu.mvxy.d[0].sp;

        if (0 < ewk->wu.mvxy.a[0].sp) {
            if (ewk->wu.hit_quake <= ewk->wu.xyz[0].disp.pos) {
                if (Order[ewk->wu.dir_old] == ewk->wu.routine_no[0]) {
                    Order[ewk->wu.dir_old] = 0;
                }

                ewk->wu.routine_no[0] = 0;
                ewk->wu.xyz[0].disp.pos = ewk->wu.hit_quake;
            }

            break;
        }

        if (ewk->wu.hit_quake >= ewk->wu.xyz[0].disp.pos) {
            if (Order[ewk->wu.dir_old] == ewk->wu.routine_no[0]) {
                Order[ewk->wu.dir_old] = 0;
            }

            ewk->wu.routine_no[0] = 0;
            ewk->wu.xyz[0].disp.pos = ewk->wu.hit_quake;
        }

        break;
    }
}

void EFF63_CHAR_CHANGE(WORK_Other_CONN* /* unused */) {}

void EFF63_SUDDENLY(WORK_Other_CONN* /* unused */) {}

s32 effect_63_init(u8 dir_old, s16 sync_bg, s16 master_player, s16 letter_type, s16 cursor_index) {
    WORK_Other_CONN* ewk;
    s16 ix;

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }

    ewk = (WORK_Other_CONN*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 63;
    ewk->wu.work_id = 16;
    ewk->wu.my_family = (sync_bg + 1);
    ewk->wu.my_col_code = 0x1AC;
    ewk->wu.type = cursor_index;

    switch (letter_type) {
    case 0:
    case 1:
        ewk->wu.dir_step = 0;
        break;

    case 2:
    case 3:
        ewk->wu.dir_step = 1;
        break;

    default:
        ewk->wu.dir_step = 2;
        break;
    }

    ewk->wu.dir_old = dir_old;
    ewk->master_player = master_player;
    ewk->wu.my_mts = 13;
    ewk->wu.my_trans_mode = get_my_trans_mode(ewk->wu.my_mts);
    Disp_63_Sub(ewk);
    return 0;
}

void Disp_63_Sub(WORK_Other_CONN* ewk) {
    s16 disp_index;

    switch (ewk->wu.type) {
    /* Xbox: the adjusts are kept times 4, and the sizes start at 86. */
    case 0:
        disp_index = X_Adjust / 4 + 10;
        break;

    case 1:
        disp_index = Y_Adjust / 4 + 10;
        break;

    case 2:
        disp_index = (s16)Disp_Size_H - 86;
        disp_index >>= 1;
        break;

    case 3:
        disp_index = (s16)Disp_Size_V - 86;
        disp_index >>= 1;
        break;

    default:
        disp_index = sys_w.screen_mode;
        break;
    }

    Setup_Letter_63(ewk, disp_index);
}

void Setup_Letter_63(WORK_Other_CONN* ewk, s16 disp_index) {
    const u8* ptr = (u8*)Letter_Data_63[ewk->wu.dir_step][disp_index];
    s16 ix = 0;
    s16 x = 0;

    while (*ptr != '\0') {
        if (*ptr == ' ') {
            x += 12;
            ptr++;
            continue;
        }

        ewk->conn[ix].nx = x;
        ewk->conn[ix].ny = 0;
        ewk->conn[ix].col = 0;
        ewk->conn[ix].chr = *ptr + 0x7047;
        x += 16;
        ptr++;
        ix++;
    }

    ewk->num_of_conn = ix;
}
