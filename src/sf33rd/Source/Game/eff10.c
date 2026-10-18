/* Effect 10, retail sf33rd.xbe.
 * effect_10_move is 0x34F2F size 0x165 and is a scanned start.
 * effect_10_init is 0x35094 size 0x79 and is a scanned start.
 * The pass is the shared stub at 0x4384A and stays unnamed.
 * 0x3510D stays unnamed.
 *
 * Type 5 calls sub_000E95C4. x is (pos * 8) - 5,
 * scaled by 5/3. y is (pos * 8) - 5, scaled by 2.
 * The arguments are 10, 33, 32, and 0. The PlayStation 2
 * source calls dispButtonImage2 with (x * 8) - 6,
 * (y * 8) - 5, 1, 22, 17, and 0. Type 0 with
 * master_priority 3 calls
 * sub_000C8B21(1, 0xBE, 0xAA, 0x16, 0x16, 0x16) and
 * returns. The PlayStation 2 source falls through to
 * SSPutStr2. The C keeps the PlayStation 2 order aside
 * from those two calls.
 *
 * The init stores master_id, type, master_priority,
 * cg_type, master_player, and xyz[0] before be_flag.
 * It stores xyz[1] after id and work_id. The C keeps
 * the PlayStation 2 order. The pull failure is an early
 * ret.
 *
 * Contents_Check_Data is 0x24B67C and matches the 8
 * bytes. button_string_data is 0x32AB18. The 96 strings
 * match. The rows were not pasted. The scale constants
 * are 0x2497DC and 0x2190A4. Game_pause is 0x7A89B0.
 * Pause_Down is 0x7A8590. Menu_Suicide is 0x7A87A0.
 * Menu_Cursor_Y is 0x7A827E. Interface_Type is 0x7C56A4.
 * Convert_Buff[1] is 0x7A8958. push_effect_work stays
 * sub_0004AC6C. pull_effect_work stays sub_0004A6A8.
 * SSPutStr2 is named. frw is 0xC806A0 and each object
 * is 0x700 bytes.
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
    u8 pad_type[3];
    u8 type;
    u8 pad_wid[1];
    s16 work_id;
    s16 id;
    u8 pad_xyz[0x5A];
    XY xyz[3];
    u8 pad_cg[0x1A4];
    u8 cg_type;
    u8 pad_end[0x173];
} WORK;

typedef struct {
    WORK wu;
    u8 pad_master[6];
    s16 master_id;
    s16 master_player;
    s16 master_priority;
} WORK_Other;

typedef u8 EffectRow[0x700];

#if defined(__i386__)
_Static_assert(__builtin_offsetof(WORK, type) == 4, "type");
_Static_assert(__builtin_offsetof(WORK, work_id) == 6, "work_id");
_Static_assert(__builtin_offsetof(WORK, id) == 8, "id");
_Static_assert(__builtin_offsetof(WORK, xyz[0].disp.pos) == 0x66, "xyz0");
_Static_assert(__builtin_offsetof(WORK, xyz[1].disp.pos) == 0x6A, "xyz1");
_Static_assert(__builtin_offsetof(WORK, cg_type) == 0x214, "cg_type");
_Static_assert(sizeof(WORK) == 0x388, "WORK");
_Static_assert(__builtin_offsetof(WORK_Other, master_id) == 0x38E, "master_id");
_Static_assert(__builtin_offsetof(WORK_Other, master_player) == 0x390, "master_player");
_Static_assert(__builtin_offsetof(WORK_Other, master_priority) == 0x392, "master_priority");
#endif

extern EffectRow frw[];
extern u8 Game_pause;
extern u8 Pause_Down;
extern u8 Menu_Suicide[4];
extern s8 Menu_Cursor_Y[2];
extern u8 Interface_Type[2];
extern const u8 Contents_Check_Data[8];
extern s8 Convert_Buff[4][2][12];
extern const s8 *button_string_data[8][12];

void sub_0004AC6C(WORK *wk);
s16 sub_0004A6A8(s16 kind);
void SSPutStr2(u16 x, u16 y, u8 atr, const s8 *str);
void sub_000E95C4(s32 px, s32 py, s32 pz, s32 sx, s32 sy, s32 cl, s32 ix);
void sub_000C8B21(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);

void effect_10_move(WORK_Other *ewk) {
    s16 color;
    s16 correct_index;
    s16 ix;

    if (Game_pause == 0x81 && Pause_Down == 0) {
        return;
    }

    if (Menu_Suicide[ewk->master_player] != 0) {
        sub_0004AC6C(&ewk->wu);
        return;
    }

    correct_index = 0;

    if (ewk->master_priority != Menu_Cursor_Y[ewk->master_id]) {
        color = 9;
    } else {
        color = 5;
    }

    if (ewk->wu.type == 5 && Interface_Type[ewk->master_id] == 1) {
        if (ewk->master_priority == 2) {
            correct_index = 4;
        }

        if (ewk->master_priority == 5) {
            correct_index = 2;
        }
    }

    if (Contents_Check_Data[ewk->wu.type] == 1) {
        ix = Convert_Buff[1][ewk->master_id][ewk->master_priority];
    } else {
        ix = ewk->wu.cg_type;
    }

    if (ewk->wu.type == 5) {
        sub_000E95C4((s32)((f32)((ewk->wu.xyz[0].disp.pos * 8) - 5) * (5.0f / 3.0f)),
                     (s32)((f32)((ewk->wu.xyz[1].disp.pos * 8) - 5) * 2.0f), 10, 33, 32, 0,
                     ix + correct_index);
        return;
    }

    if (ewk->wu.type == 0 && ewk->master_priority == 3) {
        sub_000C8B21(1, 0xBE, 0xAA, 0x16, 0x16, 0x16);
        return;
    }

    SSPutStr2(ewk->wu.xyz[0].disp.pos, ewk->wu.xyz[1].disp.pos, (u8)color,
              button_string_data[ewk->wu.type][ix + correct_index]);
}

s32 effect_10_init(s16 id, u8 Type, u8 Type_in_Type, u8 dir_step, u8 Death_Type, s16 pos_x, s16 pos_y) {
    WORK_Other *ewk;
    s16 ix;

    if ((ix = sub_0004A6A8(4)) == -1) {
        return -1;
    }

    ewk = (WORK_Other *)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 10;
    ewk->wu.work_id = 16;
    ewk->master_id = id;
    ewk->wu.type = Type;
    ewk->master_priority = Type_in_Type;
    ewk->wu.cg_type = dir_step;
    ewk->master_player = Death_Type;
    ewk->wu.xyz[0].disp.pos = pos_x;
    ewk->wu.xyz[1].disp.pos = pos_y;
    return 0;
}
