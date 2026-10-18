/* Cursor pieces, retail sf33rd.xbe.
 * effect_91_move is 0xB8145 size 0x8C and is interior.
 * effect_91_init is 0xB81D1 size 0xEF and is a scanned start.
 * The init's -1 path is an early ret. 0xB82C0 stays unnamed.
 *
 * EFF91_Pos_Data is 0x2845E4 and matches the 6 pairs.
 * The rows were not pasted. The move omits the Debug_w[49]
 * test. The init stores my_family and type before be_flag.
 * The C keeps the PlayStation 2 order. The character table
 * immediate is 0x2FE100. Those bytes were not compared.
 * Menu_Suicide is 0x7A87A0. Round_Operator is 0x7A833C.
 * Menu_Cursor_Y is 0x7A827E. Menu_Cursor_X is 0x7A8218.
 * Flash_Synchro is 0x7A87BC. my_clear_level is +0x24A.
 * master_id is +0x38E. master_player is +0x390.
 * bg_w is 0x7BC520. set_char_move_init2 is 0x201B9.
 * sort_push_request4 is 0x9E092. push_effect_work
 * stays push_effect_work. pull_effect_work is 0x4A6A8.
 * frw is 0xC806A0 and each object is 0x700 bytes.
 * 0xB6890 stays unnamed. 0xB61A0 stays unnamed.
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
    u8 pad_rno[0x24 - 0xA];
    s16 routine_no[8];
    s16 old_rno[8];
    u8 pad_cg[4];
    s8 cgromtype;
    u8 pad_pos[0xB];
    s16 position_x;
    s16 position_y;
    s16 position_z;
    u8 pad_ct[0x1AC - 0x5A];
    u32 *char_table[1];
    u8 pad_col[0x23C - 0x1B0];
    s16 my_col_mode;
    s16 my_col_code;
    s16 my_priority;
    s16 my_family;
    u8 pad_clear[6];
    s16 my_clear_level;
    s16 my_mts;
    u8 pad_trans[6];
    s16 my_trans_mode;
    u8 pad_end[0x388 - 0x256];
} WORK;

typedef struct {
    WORK wu;
    u32 *my_master;
    s16 master_work_id;
    s16 master_id;
    s16 master_player;
} WORK_Other;

typedef struct {
    u8 raw0[0xA];
    s16 position_x;
    s16 position_y;
    u8 raw1[0x18 - 0xE];
    XY xy[2];
    XY wxy[2];
    u8 raw2[0x30 - 0x28];
    s16 old_pos_x;
    u8 raw3[0x90 - 0x32];
} BGW;

typedef struct {
    u8 raw0[3];
    s8 stage;
    u8 raw1[0x38 - 4];
    BGW bgw[7];
} BG;

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
_Static_assert(__builtin_offsetof(WORK, char_table) == 0x1AC, "char_table");
_Static_assert(__builtin_offsetof(WORK, my_col_code) == 0x23E, "my_col_code");
_Static_assert(__builtin_offsetof(WORK, my_family) == 0x242, "my_family");
_Static_assert(__builtin_offsetof(WORK, my_clear_level) == 0x24A, "clear");
_Static_assert(__builtin_offsetof(WORK, my_mts) == 0x24C, "my_mts");
_Static_assert(__builtin_offsetof(WORK, my_trans_mode) == 0x254, "trans");
_Static_assert(sizeof(WORK) == 0x388, "WORK");
_Static_assert(__builtin_offsetof(WORK_Other, master_id) == 0x38E, "master_id");
_Static_assert(__builtin_offsetof(WORK_Other, master_player) == 0x390, "player");
_Static_assert(sizeof(BGW) == 0x90, "BGW");
_Static_assert(__builtin_offsetof(BG, bgw[1].wxy[0].disp.pos) == 0xEA, "wxy");
_Static_assert(__builtin_offsetof(BG, bgw[1].wxy[1].disp.pos) == 0xEE, "wxy1");
#endif

extern u8 Menu_Suicide[4];
extern s8 Round_Operator[2];
extern s8 Menu_Cursor_Y[2];
extern s8 Menu_Cursor_X[2];
extern s16 Flash_Synchro;
extern BG bg_w;
extern const s16 EFF91_Pos_Data[2][3][2];
extern EffectRow frw[];

void push_effect_work(WORK *wk);
void sort_push_request4(WORK *wk);
s16 pull_effect_work(s16 index);
s16 get_my_trans_mode(s16 curr);
void set_char_move_init2(WORK *wk, s16 koc, s16 index, s16 ip, s16 scf);

void effect_91_move(WORK_Other *ewk) {
    if (Menu_Suicide[ewk->master_player] != 0) {
        push_effect_work(&ewk->wu);
        return;
    }

    if (ewk->wu.be_flag == 0) {
        return;
    }

    if (ewk->wu.type == 1 && (Round_Operator[0] == 0 || Round_Operator[1] == 0)) {
        ewk->wu.my_clear_level = 205;
        sort_push_request4(&ewk->wu);
        return;
    }

    if (Menu_Cursor_Y[ewk->master_id] == ewk->wu.type) {
        if (Menu_Cursor_X[ewk->master_id] != 0) {
            ewk->wu.my_clear_level = 0;
        } else {
            ewk->wu.my_clear_level = Flash_Synchro;
        }
    } else {
        ewk->wu.routine_no[1] = 0;
        ewk->wu.my_clear_level = 128;
    }

    sort_push_request4(&ewk->wu);
}

s32 effect_91_init(s16 master_id, s16 type, s16 target_bg, s16 char_ix, s16 char_ix2, s16 master_player) {
    WORK_Other *ewk;
    s16 ix;

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }

    ewk = (WORK_Other *)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.disp_flag = 1;
    ewk->wu.id = 91;
    ewk->wu.work_id = 16;
    ewk->wu.my_col_code = 428;
    ewk->master_id = master_id;
    ewk->wu.my_family = (s16)(target_bg + 1);
    ewk->wu.char_table[0] = (u32 *)0x2FE100;
    ewk->wu.type = (u8)type;
    ewk->master_player = master_player;
    ewk->wu.my_mts = 13;
    ewk->wu.my_trans_mode = get_my_trans_mode(ewk->wu.my_mts);
    ewk->wu.position_x = (s16)(bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos +
                               EFF91_Pos_Data[master_id][ewk->wu.type][0]);
    ewk->wu.position_y = (s16)(bg_w.bgw[ewk->wu.my_family - 1].wxy[1].disp.pos +
                               EFF91_Pos_Data[master_id][ewk->wu.type][1]);
    ewk->wu.position_z = 68;
    set_char_move_init2(&ewk->wu, 0, char_ix, (s16)(char_ix2 + 1), 0);
    return 0;
}
