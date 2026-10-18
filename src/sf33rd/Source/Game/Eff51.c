/* Effect 51, direction menu option letters, retail sf33rd.xbe.
 * Setup_Letter_51 is 0x52D5B size 0xBB.
 * effect_51_move is 0x52E16 size 0x4A.
 * effect_51_init is 0x52E60 size 0xD8.
 *
 * effect_51_init subtracts 3 from position_y only when Country is not 1.
 * The PS2 retail build subtracts it unconditionally (0x1B4E88), so this
 * test is new on Xbox.
 * Setup_Letter_51 stores each conn entry as col, ny, nx, chr and clears
 * col and ny with "and word, 0". The C keeps the PS2 order. effect_51_move
 * picks my_clear_level branchlessly: 0x80 unless Menu_Cursor_Y[0] equals
 * type.
 * Letter_Data_51 is 0x32A668, [10][6][4] string pointers.
 * Dir_Default_Data is 0x2499D0. system_dir is 0x7C59E0, 0x48 bytes per
 * entry, so system_dir[1].contents is 0x7C5A28. Menu_Page_Buff is 0x7A8810.
 * Country is 0x7A8748. Menu_Suicide is 0x7A87A0. Menu_Cursor_Y is 0x7A827E.
 * bg_w is 0x7BC520, bgw at +0x38, stride 0x90. bgw[f - 1].wxy[0].disp.pos
 * and wxy[1].disp.pos are read as 0x7BC4EA and 0x7BC4EE + f * 0x90.
 * conn is +0x398, 8 bytes per entry. num_of_conn is +0x396.
 * frw is 0xC806A0, 0x700 bytes per object.
 * push_effect_work is 0x4AC6C. pull_effect_work is 0x4A6A8.
 * sort_push_request3 is 0x9E423. get_my_trans_mode is 0xEF70B.
 */

#include "types.h"

typedef union {
    s32 cal;
    struct {
        s16 low;
        s16 pos;
    } disp;
} XY;

typedef struct {
    s8 be_flag;
    s8 disp_flag;
    u8 pad_type[2];
    u8 type;
    u8 pad_work[1];
    s16 work_id;
    s16 id;
    u8 pad_pos[0x54 - 0xA];
    s16 position_x;
    s16 position_y;
    s16 position_z;
    u8 pad_ci[0x208 - 0x5A];
    s16 char_index;
    u8 pad_col[0x23E - 0x20A];
    s16 my_col_code;
    u8 pad_fam[2];
    s16 my_family;
    u8 pad_clear[0x24A - 0x244];
    s16 my_clear_level;
    s16 my_mts;
    u8 pad_tm[0x254 - 0x24E];
    s16 my_trans_mode;
    u8 pad_end[0x388 - 0x256];
} WORK;

typedef struct {
    s16 nx;
    s16 ny;
    s16 col;
    u16 chr;
} CONN;

typedef struct {
    WORK wu;
    u32 *my_master;
    s16 master_work_id;
    s16 master_id;
    s16 master_player;
    s16 master_priority;
    s8 dm_refrect;
    s8 refrected;
    s16 num_of_conn;
    CONN conn[108];
} WORK_Other_CONN;

typedef struct {
    s8 contents[10][7];
    u16 sum;
} SystemDir;

typedef struct {
    u8 raw0[0x18];
    XY xy[2];
    XY wxy[2];
    u8 raw1[0x90 - 0x28];
} BGW;

typedef struct {
    u8 raw0[0x38];
    BGW bgw[7];
} BG;

typedef u8 EffectRow[0x700];

#if defined(__i386__)
_Static_assert(__builtin_offsetof(WORK, type) == 4, "type");
_Static_assert(__builtin_offsetof(WORK, position_x) == 0x54, "position_x");
_Static_assert(__builtin_offsetof(WORK, char_index) == 0x208, "char_index");
_Static_assert(__builtin_offsetof(WORK, my_col_code) == 0x23E, "my_col_code");
_Static_assert(__builtin_offsetof(WORK, my_family) == 0x242, "my_family");
_Static_assert(__builtin_offsetof(WORK, my_clear_level) == 0x24A, "clear");
_Static_assert(__builtin_offsetof(WORK, my_mts) == 0x24C, "my_mts");
_Static_assert(__builtin_offsetof(WORK, my_trans_mode) == 0x254, "my_trans_mode");
_Static_assert(sizeof(WORK) == 0x388, "WORK");
_Static_assert(__builtin_offsetof(WORK_Other_CONN, master_player) == 0x390, "player");
_Static_assert(__builtin_offsetof(WORK_Other_CONN, num_of_conn) == 0x396, "num_of_conn");
_Static_assert(__builtin_offsetof(WORK_Other_CONN, conn[0].chr) == 0x39E, "chr");
_Static_assert(sizeof(SystemDir) == 0x48, "SystemDir");
_Static_assert(sizeof(BGW) == 0x90, "BGW");
_Static_assert(__builtin_offsetof(BG, bgw[0].wxy[0].disp.pos) == 0x5A, "wxy0");
#endif

extern s8 *Letter_Data_51[10][6][4];
extern const SystemDir Dir_Default_Data;
extern SystemDir system_dir[6];
extern s8 Menu_Page_Buff;
extern u8 Country;
extern u8 Menu_Suicide[4];
extern s8 Menu_Cursor_Y[2];
extern BG bg_w;
extern EffectRow frw[];

void push_effect_work(WORK *wk);
s16 pull_effect_work(s16 index);
void sort_push_request3(WORK *wk);
s16 get_my_trans_mode(s32 curr);
void Setup_Letter_51(WORK_Other_CONN *ewk);

void effect_51_move(WORK_Other_CONN *ewk) {
    if (Menu_Suicide[ewk->master_player]) {
        push_effect_work(&ewk->wu);
        return;
    }

    if (Menu_Cursor_Y[0] == ewk->wu.type) {
        ewk->wu.my_clear_level = 0;
    } else {
        ewk->wu.my_clear_level = 128;
    }

    Setup_Letter_51(ewk);
    sort_push_request3(&ewk->wu);
}

s32 effect_51_init(s16 letter_type, s16 cursor_index, s16 master_player) {
    WORK_Other_CONN *ewk;
    s16 ix;

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }

    ewk = (WORK_Other_CONN *)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.disp_flag = 1;
    ewk->wu.id = 51;
    ewk->wu.work_id = 16;
    ewk->wu.my_col_code = 0x1AC;
    ewk->wu.my_family = 1;
    ewk->wu.char_index = letter_type;
    ewk->wu.type = cursor_index;
    ewk->master_player = master_player;
    ewk->wu.my_mts = 13;
    ewk->wu.my_trans_mode = get_my_trans_mode(ewk->wu.my_mts);
    Setup_Letter_51(ewk);
    ewk->wu.position_x = bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos + 112;
    ewk->wu.position_y = bg_w.bgw[ewk->wu.my_family - 1].wxy[1].disp.pos + 187 - (ewk->wu.type * 18);
    ewk->wu.position_z = 68;

    if (Country != 1) {
        ewk->wu.position_y -= 3;
    }

    return 0;
}

void Setup_Letter_51(WORK_Other_CONN *ewk) {
    u8 *ptr =
        (u8 *)Letter_Data_51[Menu_Page_Buff][ewk->wu.char_index][system_dir[1].contents[Menu_Page_Buff][ewk->wu.type]];
    s16 ix = 0;
    s16 x = 0;

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

        if (system_dir[1].contents[Menu_Page_Buff][ewk->wu.type] !=
            Dir_Default_Data.contents[Menu_Page_Buff][ewk->wu.type]) {
            ewk->conn[ix].col = 0x18;
        } else {
            ewk->conn[ix].col = 0;
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
