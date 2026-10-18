/* EFF61.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * EFF61_SLIDE_IN 0x3E7E8 size 0x100. Read against the x86: the unnamed words
 * are a two-short position table at 0x267FB8. The C is the PS2 C.
 * EFF61_SUDDENLY 0x3E8E8 size 0x9D. Read against the x86: the unnamed words
 * are the same position table at 0x267FB8. The C is the PS2 C.
 * Check_Die_61 0x3E985 size 0x13.
 * effect_61_init 0x3E998 size 0x17C. Read against the x86: two Xbox changes.
 * Menu_Letter_Data is [2][67] at 0x32AE70: each block adds "Xbox Live" at [6]
 * (so every later index is one more than on PS2) and has "Thumbsticks" for
 * ANALOG STICK, and block 1 has BLOCKING TRAINING; D_007AA5F1 picks the block.
 * And for a slash in the 14-pixel font, the Japanese setting only sets ny = 1,
 * where the other keeps the PS2 nx -= 8, ny += 17. The C table, index, and
 * branch are changed to match; all 134 entries were compared with the XBE. -6
 * and 0xE are the branchless 8/14 offset choice.
 * effect_61_move 0x3EB14 size 0x128. Read against the x86: the unnamed byte at
 * 0x7A8A03 is a menu state flag compared before the clear level is set. The C
 * is the PS2 C.
 * EFF61_WAIT is folded into 0x40E7F with 7 other bodies. Unnamed.
 * EFF61_SLIDE_OUT is folded into 0x4384A with 41 other bodies. Unnamed.
 * Data: Menu_Letter_Data: not located in the XBE, PS2 initializer kept.
 * Data: EFF61_Jmp_Tbl is 0x24F060, 4 entries compared.
 * Unnamed data used (not checked): EFF61_SLIDE_IN: 0x267fb8,0x267fba;
 * EFF61_SUDDENLY: 0x267fb8,0x267fba; effect_61_init: 0x32ae70; effect_61_move:
 * 0x7a8a03.
 * Globals: EFF61_Jmp_Tbl 0x24F060, Menu_Cursor_X 0x7A8218, Menu_Cursor_Y
 * 0x7A827E, Menu_Cursor_Move 0x7A82F2, Order 0x7A8380, Order_Timer 0x7A8480,
 * Menu_Suicide 0x7A87A0, mpp_w 0x7AA5C0, bg_w 0x7BC520, frw 0xC806A0.
 */

#include "structs.h"

#define EFFECT_MAX 128

extern s8 D_007AA5F1;
void EFF61_WAIT(WORK_Other_CONN* ewk);
void EFF61_SLIDE_IN(WORK_Other_CONN* ewk);
void EFF61_SLIDE_OUT(WORK_Other_CONN* );
void EFF61_SUDDENLY(WORK_Other_CONN* ewk);
s32 Check_Die_61(WORK_Other* ewk);
void push_effect_work(WORK* wkhd);
extern s8 Menu_Cursor_Y[2];
extern s8 Menu_Cursor_X[2];
extern u8 Connect_Status;
s32 sort_push_request3(WORK* wk);
extern u8 Order[148];
extern u8 Order_Timer[148];
extern BG bg_w;
extern const s16 Slide_Pos_Data_61[][2];
extern s8 Menu_Cursor_Move;
extern u8 Menu_Suicide[4];
s16 pull_effect_work(s16 index);
extern uintptr_t frw[EFFECT_MAX][448];
s16 get_my_trans_mode(s16 curr);

const s8* Menu_Letter_Data[2][67] = {
    {
        "ARCADE",
        "VERSUS",
        "TRAINING",
        "SYSTEM DIRECTION",
        "REPLAY",
        "OPTION",
        "Xbox Live",
        "SELECT GAME",
        "GAME OPTION",
        "BUTTON CONFIG.",
        "SCREEN ADJUST",
        "SOUND",
        "SAVE#/#LOAD",
        "EXTRA OPTION",
        "EXIT",
        "X POSITION^^^",
        "Y POSITION^^^",
        "X RANGE^^^^^^",
        "Y RANGE^^^^^^",
        "FILTER^^^^^^^",
        "DEFAULT SETTING",
        "EXIT",
        "SAVE  DATA",
        "LOAD  DATA",
        "AUTO  SAVE",
        "EXIT",
        "DIFFICULTY^^^^^^ L         #H",
        "TIME LIMIT^^^^^^",
        "ROUNDS(1P)^^^^^^",
        "ROUNDS(VS)^^^^^^",
        "DAMAGE LEVEL^^^^ L     #H",
        "GUARD JUDGMENT^^",
        "Thumbsticks^^^^^",
        "HANDICAP(VS)^^^^",
        "PLAYER1(VS)^^^^^",
        "PLAYER2(VS)^^^^^",
        "DEFAULT SETTING",
        "EXIT",
        "CONTINUE",
        "REPLAY SAVE",
        "EXIT",
        "CONTINUE",
        "REPLAY SAVE",
        "EXIT",
        "DIRECTION",
        "SAVE",
        "LOAD",
        "EXIT",
        "GAME OPTION",
        "BUTTON CONFIG.",
        "SCREEN ADJUST",
        "SOUND",
        "SAVE#/#LOAD",
        "EXIT",
        "NORMAL TRAINING",
        "PARRYING TRAINING",
        "EXIT",
        "RESTART",
        "SAVE",
        "EXIT",
        "AUDIO",
        "BGM LEVEL",
        "SE LEVEL",
        "BGM SELECT",
        "DEFAULT SETTING",
        "BGM TEST",
        "EXIT"
    },
    {
        "ARCADE",
        "VERSUS",
        "TRAINING",
        "SYSTEM DIRECTION",
        "REPLAY",
        "OPTION",
        "Xbox Live",
        "SELECT GAME",
        "GAME OPTION",
        "BUTTON CONFIG.",
        "SCREEN ADJUST",
        "SOUND",
        "SAVE#/#LOAD",
        "EXTRA OPTION",
        "EXIT",
        "X POSITION^^^",
        "Y POSITION^^^",
        "X RANGE^^^^^^",
        "Y RANGE^^^^^^",
        "FILTER^^^^^^^",
        "DEFAULT SETTING",
        "EXIT",
        "SAVE  DATA",
        "LOAD  DATA",
        "AUTO  SAVE",
        "EXIT",
        "DIFFICULTY^^^^^^ L         #H",
        "TIME LIMIT^^^^^^",
        "ROUNDS(1P)^^^^^^",
        "ROUNDS(VS)^^^^^^",
        "DAMAGE LEVEL^^^^ L     #H",
        "GUARD JUDGMENT^^",
        "Thumbsticks^^^^^",
        "HANDICAP(VS)^^^^",
        "PLAYER1(VS)^^^^^",
        "PLAYER2(VS)^^^^^",
        "DEFAULT SETTING",
        "EXIT",
        "CONTINUE",
        "REPLAY SAVE",
        "EXIT",
        "CONTINUE",
        "REPLAY SAVE",
        "EXIT",
        "DIRECTION",
        "SAVE",
        "LOAD",
        "EXIT",
        "GAME OPTION",
        "BUTTON CONFIG.",
        "SCREEN ADJUST",
        "SOUND",
        "SAVE#/#LOAD",
        "EXIT",
        "NORMAL TRAINING",
        "BLOCKING TRAINING",
        "EXIT",
        "RESTART",
        "SAVE",
        "EXIT",
        "AUDIO",
        "BGM LEVEL",
        "SE LEVEL",
        "BGM SELECT",
        "DEFAULT SETTING",
        "BGM TEST",
        "EXIT"
    }
};

void (*const EFF61_Jmp_Tbl[4])() = { EFF61_WAIT, EFF61_SLIDE_IN, EFF61_SLIDE_OUT, EFF61_SUDDENLY };

void effect_61_move(WORK_Other_CONN* ewk) {
    if (Check_Die_61((WORK_Other*)ewk)) {
        push_effect_work(&ewk->wu);
        return;
    }

    EFF61_Jmp_Tbl[ewk->wu.routine_no[0]](ewk);

    if (ewk->wu.be_flag == 0) {
        return;
    }

    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0xFFFF;
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0xFFFF;

    if (ewk->wu.char_index >= 37 && ewk->wu.char_index < 43) {
        if (Menu_Cursor_Y[ewk->master_id] == ewk->wu.type) {
            if (Menu_Cursor_X[ewk->master_id]) {
                ewk->wu.my_clear_level = 0;
            } else {
                ewk->wu.my_clear_level = 51;
            }
        } else {
            ewk->wu.my_clear_level = 179;
        }
    } else if (ewk->wu.char_index >= 56 && ewk->wu.char_index < 59) {
        if (Menu_Cursor_Y[ewk->master_id] == ewk->wu.type) {
            ewk->wu.my_bright_type = 0;
            ewk->wu.my_bright_level = 0;
            ewk->wu.my_clear_level = 0;
        } else {
            ewk->wu.my_bright_type = 1;
            ewk->wu.my_bright_level = 8;
            ewk->wu.my_clear_level = 51;
        }
    } else if (Menu_Cursor_Y[ewk->master_id] == ewk->wu.type) {
        ewk->wu.my_clear_level = 0;
    } else if (ewk->wu.char_index == 1 && Connect_Status == 0) {
        ewk->wu.my_clear_level = 179;
    } else {
        ewk->wu.my_clear_level = 128;
    }

    sort_push_request3(&ewk->wu);
}

void EFF61_WAIT(WORK_Other_CONN* ewk) {
    if ((ewk->wu.routine_no[0] = Order[ewk->wu.dir_old])) {
        ewk->wu.routine_no[1] = 0;
    }
}

void EFF61_SLIDE_IN(WORK_Other_CONN* ewk) {
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
            bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos + Slide_Pos_Data_61[ewk->wu.char_index][0] + 384;
        ewk->wu.xyz[1].disp.pos =
            bg_w.bgw[ewk->wu.my_family - 1].wxy[1].disp.pos + Slide_Pos_Data_61[ewk->wu.char_index][1];
        ewk->wu.position_z = 68;
        ewk->wu.hit_quake = bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos + Slide_Pos_Data_61[ewk->wu.char_index][0];
        ewk->wu.mvxy.a[0].sp = -0x400000;
        ewk->wu.mvxy.d[0].sp = 0x50000;
        break;

    default:
        ewk->wu.xyz[0].cal += ewk->wu.mvxy.a[0].sp;
        ewk->wu.mvxy.a[0].sp += ewk->wu.mvxy.d[0].sp;

        if (ewk->wu.hit_quake < ewk->wu.xyz[0].disp.pos) {
            break;
        }

        if (Order[ewk->wu.dir_old] == ewk->wu.routine_no[0]) {
            Order[ewk->wu.dir_old] = 0;
        }

        ewk->wu.routine_no[0] = 0;
        ewk->wu.xyz[0].disp.pos = ewk->wu.hit_quake;
        Menu_Cursor_Move--;
        break;
    }
}

void EFF61_SLIDE_OUT(WORK_Other_CONN* /* unused */) {}

void EFF61_SUDDENLY(WORK_Other_CONN* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (--Order_Timer[ewk->wu.dir_old]) {
            break;
        }

        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.xyz[0].disp.pos =
            bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos + Slide_Pos_Data_61[ewk->wu.char_index][0];
        ewk->wu.xyz[1].disp.pos =
            bg_w.bgw[ewk->wu.my_family - 1].wxy[1].disp.pos + Slide_Pos_Data_61[ewk->wu.char_index][1];
        ewk->wu.position_z = 68;

        if (ewk->wu.char_index >= 56 && ewk->wu.char_index < 59) {
            ewk->wu.position_z = 20;
        }

        break;

    default:
        ewk->wu.routine_no[0] = 0;
        Order[ewk->wu.dir_old] = 0;
        break;
    }
}

s32 Check_Die_61(WORK_Other* ewk) {
    return Menu_Suicide[ewk->master_player];
}

s32 effect_61_init(s16 master, u8 dir_old, s16 sync_bg, s16 master_player, s16 char_ix, s16 cursor_index,
                   u16 letter_type) {
    WORK_Other_CONN* ewk;
    s16 ix;
    u16 x;
    s16 offset_x;
    const u8* ptr;

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }

    ewk = (WORK_Other_CONN*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 61;
    ewk->wu.work_id = 16;
    ewk->master_id = master;
    ewk->wu.my_family = sync_bg + 1;
    ewk->wu.my_col_code = 0x1AC;
    ewk->wu.type = cursor_index;
    ewk->wu.char_index = char_ix;
    ewk->wu.old_cgnum = letter_type;
    ewk->wu.dir_old = dir_old;
    ewk->master_player = master_player;

    if (ewk->wu.old_cgnum == 0x70A7) {
        offset_x = 8;
    } else {
        offset_x = 14;
    }

    ptr = (u8*)Menu_Letter_Data[D_007AA5F1][char_ix];
    ix = 0;
    x = 0;

    while (*ptr != '\0') {
        if (*ptr == ' ') {
            x += offset_x;
            ptr++;
            continue;
        }

        if (*ptr == '#') {
            x += offset_x / 2;
            ptr++;
            continue;
        }

        ewk->conn[ix].nx = x;
        ewk->conn[ix].ny = 0;
        ewk->conn[ix].col = 0;
        ewk->conn[ix].chr = ewk->wu.old_cgnum + *ptr;

        if (offset_x == 14 && *ptr == '/') {
            if (D_007AA5F1) {
                ewk->conn[ix].ny = 1; /* Xbox only */
            } else {
                ewk->conn[ix].nx -= 8;
                ewk->conn[ix].ny += 17;
            }
        }

        x += offset_x;
        ptr++;
        ix++;
    }

    ewk->num_of_conn = ix;
    ewk->wu.my_mts = 13;
    ewk->wu.my_trans_mode = get_my_trans_mode(ewk->wu.my_mts);
    return 0;
}
