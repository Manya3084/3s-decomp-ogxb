/* Effect 84, the round message timer, retail sf33rd.xbe.
 * effect_84_move is 0x41BE4 size 0x133.
 * effect_84_init is 0x41D17 size 0x2C.
 *
 * effect_84_move tail-jumps to push_effect_work when Suicide[0] is set.
 * The message_index cases share one call to effect_56_init. Cases 3 and 4
 * and the default share one routine_no[1] increment. In case 1 the
 * routine_no stores run routine_no[1] first.
 * Time_Data is 0x24F6DC, one byte per message, indexed by the signed
 * request_message. request_message is 0x7A8112. message_index is 0x7A8310.
 * Message_Suicide is 0x7A87F8. Bonus_Game_Flag is 0x7A8272.
 * bg_w.stage is the byte at 0x7BC523. Suicide is 0x7A8268.
 * Game_pause is 0x7A89B0. frw is 0xC806A0, 0x700 bytes per object.
 * dead_voice_request stays sub_000940B0. effect_56_init is 0x3DC87.
 * push_effect_work is 0x4AC6C. pull_effect_work is 0x4A6A8.
 */

#include "types.h"

typedef struct {
    s8 be_flag;
    s8 disp_flag;
    u8 pad_type[6];
    s16 id;
    u8 pad_rno[0x24 - 0xA];
    s16 routine_no[8];
    u8 pad_dir[0x9A - 0x34];
    s16 dir_timer;
    u8 pad_end[0x388 - 0x9C];
} WORK;

typedef struct {
    WORK wu;
} WORK_Other;

typedef struct {
    u8 pad0[3];
    u8 stage;
} BG;

typedef u8 EffectRow[0x700];

#if defined(__i386__)
_Static_assert(__builtin_offsetof(WORK, id) == 8, "id");
_Static_assert(__builtin_offsetof(WORK, routine_no) == 0x24, "routine_no");
_Static_assert(__builtin_offsetof(WORK, dir_timer) == 0x9A, "dir_timer");
_Static_assert(sizeof(WORK) == 0x388, "WORK");
_Static_assert(__builtin_offsetof(BG, stage) == 3, "stage");
#endif

extern const u8 Time_Data[];
extern s8 request_message;
extern u8 message_index;
extern u8 Message_Suicide[4];
extern s16 Bonus_Game_Flag;
extern BG bg_w;
extern s8 Suicide[8];
extern u8 Game_pause;
extern EffectRow frw[];

void push_effect_work(WORK *wk);
s16 pull_effect_work(s16 index);
s32 effect_56_init(u8 type, u8 kill);
void sub_000940B0(void);

void effect_84_move(WORK_Other *ewk) {
    if (Suicide[0]) {
        push_effect_work(&ewk->wu);
        return;
    }

    switch (ewk->wu.routine_no[0]) {
    case 0:
        if (request_message) {
            ewk->wu.routine_no[0]++;
            ewk->wu.dir_timer = Time_Data[request_message];
        }

        break;

    case 1:
        switch (ewk->wu.routine_no[1]) {
        case 0:
            switch (message_index) {
            case 0:
                Game_pause = 1;
                ewk->wu.routine_no[1]++;
                effect_56_init(0, 0);
                break;

            case 1:
                Game_pause = 1;
                ewk->wu.routine_no[1]++;
                effect_56_init(1, 0);
                break;

            case 2:
                Game_pause = 1;
                ewk->wu.routine_no[1]++;

                if (Bonus_Game_Flag == 20 && bg_w.stage == 20) {
                    ewk->wu.dir_timer = 90;
                }

                effect_56_init(2, 0);
                break;

            case 3:
                ewk->wu.routine_no[1]++;
                effect_56_init(3, 3);
                break;

            case 4:
            default:
                ewk->wu.routine_no[1]++;
                effect_56_init(4, 2);
                break;
            }

            break;

        case 1:
            if ((ewk->wu.dir_timer -= 1) != 0) {
                break;
            }

            switch (message_index) {
            case 4:
                Message_Suicide[2] = 1;
                break;

            case 3:
                Message_Suicide[3] = 1;
                break;

            default:
                Message_Suicide[0] = 1;
                break;
            }

            sub_000940B0();
            request_message = 0;
            Game_pause = 0;
            ewk->wu.routine_no[0] = ewk->wu.routine_no[1] = 0;
            break;
        }

        break;

    case 2:
        break;
    }
}

s32 effect_84_init(void) {
    WORK_Other *ewk;
    s16 ix;

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }

    ewk = (WORK_Other *)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 84;
    return 0;
}
