/* Bonus stage 2 CPU, retail sf33rd.xbe.
 * bbbs_com_execute2 is 0x1CE75 size 0xE4.
 *
 * The x86 tests case 1 first. It follows the PlayStation 2 C.
 * Bonus_Stage_RNO is 0x7A86F0, two s16. Allow_a_battle_f is 0x7A82B8.
 * pcon_dp_flag is 0xC7D8D0. zettai_muteki_flag is +0x428.
 * my_effadrs is +0x32C. my_mts is +0x24C.
 * purge_texcash_work is 0xEFA99. make_texcash_work is 0xEF72E.
 * effect_C2_init is 0x4601A. effect_16_init is 0x37E62.
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
    u8 pad_type[6];
    s16 id;
    u8 pad_rno[0x24 - 0xA];
    s16 routine_no[8];
    u8 pad_xyz[0x64 - 0x34];
    XY xyz[3];
    u8 pad_mts[0x24C - 0x70];
    s16 my_mts;
    u8 pad_eff[0x32C - 0x24E];
    u32 *my_effadrs;
    u8 pad_end[0x388 - 0x330];
} WORK;

typedef struct {
    WORK wu;
    u8 pad_mu[0x428 - 0x388];
    s8 zettai_muteki_flag;
} PLW;

#if defined(__i386__)
_Static_assert(__builtin_offsetof(WORK, routine_no) == 0x24, "routine_no");
_Static_assert(__builtin_offsetof(WORK, xyz[0].disp.pos) == 0x66, "xyz0");
_Static_assert(__builtin_offsetof(WORK, my_mts) == 0x24C, "my_mts");
_Static_assert(__builtin_offsetof(WORK, my_effadrs) == 0x32C, "my_effadrs");
_Static_assert(sizeof(WORK) == 0x388, "WORK");
_Static_assert(__builtin_offsetof(PLW, zettai_muteki_flag) == 0x428, "muteki");
#endif

extern s16 Bonus_Stage_RNO[2];
extern u8 Allow_a_battle_f;
extern u8 pcon_dp_flag;

void purge_texcash_work(s16 type);
void make_texcash_work(s16 type);
s32 effect_C2_init(WORK *wk, s16 data);
s32 effect_16_init(PLW *wk, s16 dir);

void bbbs_com_execute2(PLW *wk) {
    switch (Bonus_Stage_RNO[0]) {
    case 0:
        if (Bonus_Stage_RNO[1]) {
            if (!Allow_a_battle_f) {
                break;
            }

            Bonus_Stage_RNO[0] = 1;
            Bonus_Stage_RNO[1] = 0;
            wk->zettai_muteki_flag = 1;

            break;
        }

        if (wk->wu.id) {
            purge_texcash_work(4);
            wk->wu.my_mts = 3;
        } else {
            purge_texcash_work(3);
            wk->wu.my_mts = 4;
        }

        make_texcash_work(5);
        wk->wu.xyz[0].disp.pos = 468;
        wk->wu.xyz[1].disp.pos = 0;
        effect_C2_init(&wk->wu, 0);
        effect_16_init(wk, 0);
        effect_16_init(wk, 1);
        Bonus_Stage_RNO[1] = 1;

        break;

    case 1:
        if (((WORK *)wk->wu.my_effadrs)->routine_no[0] == 2 && ((WORK *)wk->wu.my_effadrs)->routine_no[1] == 9) {
            Bonus_Stage_RNO[0] = 2;
            Bonus_Stage_RNO[1] = 0;
            Allow_a_battle_f = 0;
            pcon_dp_flag = 1;
        }

        wk->wu.xyz[0].disp.pos = 468;

        break;

    case 2:
        break;
    }
}
