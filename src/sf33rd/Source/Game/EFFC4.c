/* EFFC4.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * Setup_Letter_C4 0x46490 size 0xFF. Read against the x86: Ex_Letter_Data has
 * an outer [2] on Xbox: the x86 reads
 * Ex_Letter_Data[D_007AA5F1][Menu_Page_Buff][char_index][...], and the two
 * 4x7x17 blocks at 0x32E498 differ only in SEMI-PARRYING/AUTO PARRYING against
 * SEMI-BLOCKING/AUTO BLOCKING. The extern and index are changed to match.
 * Ex_Title_Data at 0x32F378 has no outer index.
 * effect_C4_move 0x4658F size 0x55.
 * effect_C4_init 0x465E4 size 0xE4. Read against the x86: the position offset
 * choice is branchless (0xE8 masked, minus 0xA0). The C is the PS2 C.
 * Globals: Ex_Letter_Data 0x32E498, Ex_Title_Data 0x32F378, Menu_Cursor_Y
 * 0x7A827E, Menu_Suicide 0x7A87A0, Menu_Page_Buff 0x7A8810, mpp_w 0x7AA5C0,
 * bg_w 0x7BC520, save_w 0x7BD3E0, frw 0xC806A0.
 */

#include "structs.h"

#define EFFECT_MAX 128

extern s8 D_007AA5F1;
extern u8 Menu_Suicide[4];
void push_effect_work(WORK* wkhd);
extern s8 Menu_Cursor_Y[2];
void Setup_Letter_C4(WORK_Other_CONN* ewk);
s32 sort_push_request3(WORK* wk);
s16 pull_effect_work(s16 index);
extern uintptr_t frw[EFFECT_MAX][448];
s16 get_my_trans_mode(s16 curr);
extern BG bg_w;
extern s8* Ex_Letter_Data[4][7][17];
extern s8 Menu_Page_Buff;
extern struct _SAVE_W save_w[6];
extern s8* Ex_Title_Data[4][7];



void effect_C4_move(WORK_Other_CONN* ewk) {
    if (Menu_Suicide[ewk->master_player]) {
        push_effect_work(&ewk->wu);
        return;
    }

    if (Menu_Cursor_Y[0] == ewk->wu.type) {
        ewk->wu.my_clear_level = 0;
    } else {
        ewk->wu.my_clear_level = 128;
    }

    if (ewk->master_id) {
        Setup_Letter_C4(ewk);
    }

    sort_push_request3(&ewk->wu);
}

s32 effect_C4_init(s16 id, s16 letter_type, s16 cursor_index, s16 master_player) {
    WORK_Other_CONN* ewk;
    s16 ix;
    s16 x;

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }

    ewk = (WORK_Other_CONN*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.disp_flag = 1;
    ewk->wu.id = 124;
    ewk->wu.work_id = 16;
    ewk->master_id = id;
    ewk->wu.my_col_code = 0x1AC;
    ewk->wu.my_family = 1;
    ewk->wu.char_index = letter_type;
    ewk->wu.type = cursor_index;
    ewk->master_player = master_player;
    ewk->wu.my_mts = 13;
    ewk->wu.my_trans_mode = get_my_trans_mode(ewk->wu.my_mts);
    Setup_Letter_C4(ewk);

    if (id == 0) {
        x = -160;
    } else {
        x = 72;
    }

    ewk->wu.position_x = bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos + x;
    ewk->wu.position_y = bg_w.bgw[ewk->wu.my_family - 1].wxy[1].disp.pos + 172 - (ewk->wu.type * 13);
    ewk->wu.position_z = 68;
    return 0;
}

void Setup_Letter_C4(WORK_Other_CONN* ewk) {
    s16 x;
    s16 ix;
    u8* ptr;

    if (ewk->master_id) {
        ptr = (u8*)Ex_Letter_Data[D_007AA5F1][Menu_Page_Buff][ewk->wu.char_index]
                                 [save_w[1].extra_option.contents[Menu_Page_Buff][ewk->wu.type]];
    } else {
        ptr = (u8*)Ex_Title_Data[Menu_Page_Buff][ewk->wu.char_index];
    }

    ix = 0;
    x = 0;

    while (*ptr != '\0') {
        if (*ptr == ' ') {
            x += 8;
            ptr++;
            continue;
        }

        if (*ptr == '/') {
            x += 4;
            ptr++;
            continue;
        }

        if (ewk->master_id) {
            if (save_w[1].extra_option.contents[Menu_Page_Buff][ewk->wu.type] !=
                save_w[0].extra_option.contents[Menu_Page_Buff][ewk->wu.type]) {
                ewk->conn[ix].col = 0x18;
            } else {
                ewk->conn[ix].col = 0;
            }
        }

        ewk->conn[ix].nx = x;
        ewk->conn[ix].ny = 0;
        ewk->conn[ix].chr = *ptr + 0x70A7;
        x += 8;
        ptr++;
        ix++;
    }

    ewk->num_of_conn = ix;
}
