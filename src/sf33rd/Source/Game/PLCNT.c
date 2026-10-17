/* Dizzy status, retail sf33rd.xbe.
 * set_kizetsu_status is 0x85BF2 size 0x7B, interior after the ret.
 * clear_kizetsu_point is 0x85C6D size 0x43, interior after the ret.
 * piyori_type is 0xC7D9A0, stride 0x14. flag is +0, genkai is +2,
 * time is +4, now.timer is +8, recover is +0xC, and store is +0x10.
 * My_char is 0x7A8114. omop_stun_gauge_len is 0x7C5C48.
 * stun_gauge_len_omake is 0x268480 and matches the 5 PlayStation 2
 * words. pl_piyo_tbl is 0x262420 and matches the 20 words.
 * pl_nr_piyo_tbl is 0x262448 and matches the 20 dwords.
 * player_number is PLW + 0x394. py is PLW + 0x3CC.
 */

#include "types.h"

typedef struct {
    s32 timer;
} Now;

typedef struct {
    u8 flag;
    s16 genkai;
    s16 time;
    u8 gap[2];
    Now now;
    s32 recover;
    s16 store;
    u8 tail[2];
} PiyoriType;

typedef struct {
    u8 raw[0x394];
    s16 player_number;
    u8 mid[0x3CC - 0x396];
    PiyoriType *py;
} PLW;

#if defined(__i386__)
_Static_assert(sizeof(PiyoriType) == 0x14, "PiyoriType");
_Static_assert(__builtin_offsetof(PiyoriType, genkai) == 2, "genkai");
_Static_assert(__builtin_offsetof(PiyoriType, time) == 4, "time");
_Static_assert(__builtin_offsetof(PiyoriType, now.timer) == 8, "timer");
_Static_assert(__builtin_offsetof(PiyoriType, recover) == 0xC, "recover");
_Static_assert(__builtin_offsetof(PiyoriType, store) == 0x10, "store");
_Static_assert(__builtin_offsetof(PLW, player_number) == 0x394, "player_number");
_Static_assert(__builtin_offsetof(PLW, py) == 0x3CC, "py");
#endif

extern PiyoriType piyori_type[2];
extern u8 My_char[2];
extern s16 omop_stun_gauge_len[2];
extern const s16 stun_gauge_len_omake[5];
extern const s16 pl_piyo_tbl[20];
extern const s32 pl_nr_piyo_tbl[20];

void set_kizetsu_status(s16 ix) {
    s16 plnum = My_char[ix];

    piyori_type[ix].flag = 0;
    piyori_type[ix].time = 0;
    piyori_type[ix].now.timer = 0;
    piyori_type[ix].store = 0;
    piyori_type[ix].recover = pl_nr_piyo_tbl[plnum];
    piyori_type[ix].genkai = pl_piyo_tbl[plnum] + stun_gauge_len_omake[omop_stun_gauge_len[ix]];

    if (piyori_type[ix].genkai < 56) {
        piyori_type[ix].genkai = 56;
    }

    if (piyori_type[ix].genkai > 72) {
        piyori_type[ix].genkai = 72;
    }
}

void clear_kizetsu_point(PLW *wk) {
    wk->py->flag = 0;
    wk->py->time = 0;
    wk->py->now.timer = 0;
    wk->py->store = 0;
    wk->py->recover = pl_nr_piyo_tbl[wk->player_number];
}
