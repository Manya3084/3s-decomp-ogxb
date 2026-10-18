/* Effect F5, retail sf33rd.xbe.
 * effect_F5_move is 0xBE236 size 0x69.
 * 0xBE29F stays unnamed.
 *
 * The twelve efff5 handlers have empty bodies. The
 * retail image keeps one body for them, and
 * effect_F5_move stores 0x4384A, the address named
 * all_cgps_put_back elsewhere in this tree, in all
 * twelve table slots. Those handlers and effect_F5_init
 * are not named here because their bodies are shared.
 * The C keeps the PlayStation 2 handlers.
 */

#include "types.h"

typedef struct {
    u8 pad_rno[0x24];
    s16 routine_no[8];
    u8 pad_end[0x388 - 0x34];
} WORK;

typedef struct {
    WORK wu;
} WORK_Other;

#if defined(__i386__)
_Static_assert(__builtin_offsetof(WORK, routine_no) == 0x24, "routine_no");
_Static_assert(sizeof(WORK) == 0x388, "WORK");
#endif

void efff5_0000(WORK_Other *ewk);
void efff5_1000(WORK_Other *ewk);
void efff5_2000(WORK_Other *ewk);
void efff5_3000(WORK_Other *ewk);
void efff5_4000(WORK_Other *ewk);
void efff5_5000(WORK_Other *ewk);
void efff5_6000(WORK_Other *ewk);
void efff5_7000(WORK_Other *ewk);
void efff5_8000(WORK_Other *ewk);
void efff5_9000(WORK_Other *ewk);
void efff5_A000(WORK_Other *ewk);
void efff5_B000(WORK_Other *ewk);

void effect_F5_move(WORK_Other *ewk) {
    void (*efff5_jp[12])(WORK_Other *) = { efff5_0000, efff5_1000, efff5_2000, efff5_3000, efff5_4000, efff5_5000,
                                           efff5_6000, efff5_7000, efff5_8000, efff5_9000, efff5_A000, efff5_B000 };

    efff5_jp[ewk->wu.routine_no[0]](ewk);
}

void efff5_0000(WORK_Other *ewk) {}

void efff5_1000(WORK_Other *ewk) {}

void efff5_2000(WORK_Other *ewk) {}

void efff5_3000(WORK_Other *ewk) {}

void efff5_4000(WORK_Other *ewk) {}

void efff5_5000(WORK_Other *ewk) {}

void efff5_6000(WORK_Other *ewk) {}

void efff5_7000(WORK_Other *ewk) {}

void efff5_8000(WORK_Other *ewk) {}

void efff5_9000(WORK_Other *ewk) {}

void efff5_A000(WORK_Other *ewk) {}

void efff5_B000(WORK_Other *ewk) {}

s32 effect_F5_init(s16 unused) {
    return 0;
}
