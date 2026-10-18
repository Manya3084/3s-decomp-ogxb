/* Effect E6, retail sf33rd.xbe.
 * effe6_0010_sub is 0xBC66F size 0x43 and is interior.
 * effe6_init_common is 0xBC6B2 size 0x27 and is interior.
 * effect_E6_init is 0xBC6D9 size 0xFF and is interior.
 * ending_obj_load is 0xBC7D8 size 0x5E and is interior.
 * effe6_0000 is 0xBC836 size 0xC8 and is interior.
 * effe6_0001 is 0xBC8FE size 0x45 and is interior.
 * effe6_0002 is 0xBC943 size 0x4E and is interior.
 * effe6_0003 is 0xBC991 size 0x4B and is interior.
 * effe6_0004 is 0xBC9DC size 0x61 and is interior.
 * effe6_0005 is 0xBCA3D size 0x74 and is interior.
 * effe6_0006 is 0xBCAB1 size 0x6E and is interior.
 * effe6_0007 is 0xBCB1F size 0xA9 and is interior.
 * effe6_0009 is 0xBCBC8 size 0x7A and is interior.
 * effe6_0010 is 0xBCC42 size 0x8D and is interior.
 * effe6_0011 is 0xBCCCF size 0x75 and is interior.
 * effe6_0012 is 0xBCD44 size 0x7D and is interior.
 * effe6_0013 is 0xBCDC1 size 0x84 and is interior.
 * effe6_0014 is 0xBCE45 size 0x149 and is interior.
 * effe6_0015 is 0xBCF8E size 0xBA and is interior.
 * effe6_0016 is 0xBD048 size 0xA3 and is interior.
 * effe6_0017 is 0xBD0EB size 0x78 and is interior.
 * effe6_0018 is 0xBD163 size 0x72 and is interior.
 * effe6_0019 is 0xBD1D5 size 0xAA and is interior.
 * effe6_0020 is 0xBD27F size 0x74 and is interior.
 * effe6_0021 is 0xBD2F3 size 0x7C and is interior.
 * effe6_0022 is 0xBD36F size 0x85 and is interior.
 * effe6_0023 is 0xBD3F4 size 0x72 and is interior.
 * effe6_0024 is 0xBD466 size 0x7F and is interior.
 * effe6_0025 is 0xBD4E5 size 0x122 and is interior.
 * effe6_0026 is 0xBD607 size 0x5A and is interior.
 * effe6_0027 is 0xBD661 size 0x66 and is interior.
 * effe6_0028 is 0xBD6C7 size 0x4F and is interior.
 * effe6_0029 is 0xBD716 size 0xBA and is interior.
 * effe6_0030 is 0xBD7D0 size 0x122 and is interior.
 * effe6_0031 is 0xBD8F2 size 0xC5 and is interior.
 * effe6_0032 is 0xBD9B7 size 0x251 and is interior.
 * effe6_0033 is 0xBDC08 size 0xD3 and is interior.
 * effect_E6_move is 0xBDCDB size 0x13A and is interior.
 * The pull failure is an early ret. 0xBC760 is a
 * scanned start inside effect_E6_init.
 *
 * effect_E6_move stores effe6_0007 in table slots 7 and
 * 8 from one register. The handlers share their
 * disp_pos_trans_entry tails and test old_rno[6]
 * against end_w.r_no_2 before the routine switch. The
 * l_limit selects in effe6_0000 use setne and sbb.
 * effe6_0016 picks the timer with sbb. effe6_0030 copies
 * the ColorRAM rows with rep movsw. effe6_0031,
 * effe6_0032, and effe6_0033 divide the gill_range
 * values as immediates, and gill_range itself is not
 * read. effect_E6_init picks routine_no[2] with sbb.
 * The C keeps the PlayStation 2 order.
 * effe6_data_tbl is 0x284908, effe6_0010_col_tbl is
 * 0x285448, END_BCB is 0x2854F4, and END_COL is
 * 0x28551C. All four match the PlayStation 2 values.
 * end_w is 0x7AABF0 and r_no_2 is 0x7AABF4.
 * end_etc_flag is 0x7AAC03. End_PL is 0x7A89CC.
 * gill_time is 0x2861DC. end_0_1_time is 0x332DE8.
 * bg_w is 0x7BC520. ColorRAM is 0x7AAD60. p1sw_0 is
 * 0x7C557C. p2sw_0 is 0x7C5B90. p2sw_1 is 0x7C5568. The
 * _end_char_table immediate is 0x2F53B0. Those bytes
 * were not compared. disp_pos_trans_entry and
 * disp_pos_trans_entry5 share 0xEF0C0, which stays
 * disp_pos_trans_entry. char_move is 0x2008E.
 * char_move_z is 0x202CE. set_char_move_init2
 * stays set_char_move_init2. add_x_sub is folded into 0xEF072.
 * add_y_sub is folded into 0xEF088. cal_all_speed_data stays
 * cal_all_speed_data. push_effect_work is 0x4AC6C.
 * pull_effect_work is 0x4A6A8.
 * disp_pos_trans_entry_r, disp_pos_trans_entry_r4,
 * palUpdateGhostCP3, make_texcash_work,
 * load_any_texture_patnum, load_any_color, and
 * get_my_trans_mode are named. frw is 0xC806A0 and each
 * object is 0x700 bytes.
 */

#include "types.h"

typedef union {
    s32 cal;
    struct {
        s16 low;
        s16 pos;
    } disp;
} XY;

typedef union {
    s32 sp;
} Reg32SpReal;

typedef struct {
    Reg32SpReal a[2];
    Reg32SpReal d[2];
    s16 kop[2];
    u16 index;
} MVXY;

typedef struct {
    s8 be_flag;
    s8 disp_flag;
    s8 blink_timing;
    u8 pad_type[1];
    u8 type;
    u8 pad_work[1];
    s16 work_id;
    s16 id;
    u8 pad_rno[0x24 - 0xA];
    s16 routine_no[8];
    s16 old_rno[8];
    u8 pad_cg[4];
    s8 cgromtype;
    u8 pad_pos[0x58 - 0x49];
    s16 position_z;
    u8 pad_xyz[0xA];
    XY xyz[3];
    u8 pad_mv[0xC];
    MVXY mvxy;
    u8 pad_ct[0x1AC - 0x94];
    u32 *char_table[1];
    u8 pad_ci[0x208 - 0x1B0];
    s16 char_index;
    u8 pad_cg_type[0x214 - 0x20A];
    u8 cg_type;
    u8 pad_col[0x23C - 0x215];
    s16 my_col_mode;
    s16 my_col_code;
    s16 my_priority;
    s16 my_family;
    u8 pad_cl[0x24A - 0x244];
    s16 my_clear_level;
    s16 my_mts;
    s16 my_mr_flag;
    struct {
        struct {
            s16 x;
            s16 y;
        } size;
    } my_mr;
    s16 my_trans_mode;
    u8 pad_ec[0x342 - 0x256];
    s16 extra_col;
    u8 pad_end[0x388 - 0x344];
} WORK;

typedef struct {
    WORK wu;
} WORK_Other;

typedef struct {
    u8 raw0[6];
    s16 r_no_1;
    u8 raw1[0x18 - 8];
    XY xy[2];
    u8 raw2[0x68 - 0x20];
    s16 l_limit;
    u8 raw3[0x90 - 0x6A];
} BGW;

typedef struct {
    u8 raw0[0x38];
    BGW bgw[7];
} BG;

typedef struct {
    s16 r_no_0;
    s16 r_no_1;
    s16 r_no_2;
    s16 type;
    s16 end_flag;
    s16 timer;
} END_W;

typedef u8 EffectRow[0x700];

#if defined(__i386__)
_Static_assert(sizeof(MVXY) == 0x18, "MVXY");
_Static_assert(__builtin_offsetof(WORK, disp_flag) == 1, "disp_flag");
_Static_assert(__builtin_offsetof(WORK, blink_timing) == 2, "blink_timing");
_Static_assert(__builtin_offsetof(WORK, type) == 4, "type");
_Static_assert(__builtin_offsetof(WORK, work_id) == 6, "work_id");
_Static_assert(__builtin_offsetof(WORK, id) == 8, "id");
_Static_assert(__builtin_offsetof(WORK, routine_no) == 0x24, "routine_no");
_Static_assert(__builtin_offsetof(WORK, routine_no[1]) == 0x26, "rno1");
_Static_assert(__builtin_offsetof(WORK, routine_no[2]) == 0x28, "rno2");
_Static_assert(__builtin_offsetof(WORK, old_rno) == 0x34, "old_rno");
_Static_assert(__builtin_offsetof(WORK, old_rno[2]) == 0x38, "old_rno2");
_Static_assert(__builtin_offsetof(WORK, old_rno[4]) == 0x3C, "old_rno4");
_Static_assert(__builtin_offsetof(WORK, old_rno[5]) == 0x3E, "old_rno5");
_Static_assert(__builtin_offsetof(WORK, old_rno[6]) == 0x40, "old_rno6");
_Static_assert(__builtin_offsetof(WORK, old_rno[7]) == 0x42, "old_rno7");
_Static_assert(__builtin_offsetof(WORK, cgromtype) == 0x48, "cgromtype");
_Static_assert(__builtin_offsetof(WORK, position_z) == 0x58, "position_z");
_Static_assert(__builtin_offsetof(WORK, xyz[0].cal) == 0x64, "xyz0");
_Static_assert(__builtin_offsetof(WORK, xyz[1].cal) == 0x68, "xyz1");
_Static_assert(__builtin_offsetof(WORK, mvxy.a[0].sp) == 0x7C, "a0sp");
_Static_assert(__builtin_offsetof(WORK, mvxy.a[1].sp) == 0x80, "a1sp");
_Static_assert(__builtin_offsetof(WORK, mvxy.d[0].sp) == 0x84, "d0sp");
_Static_assert(__builtin_offsetof(WORK, mvxy.d[1].sp) == 0x88, "d1sp");
_Static_assert(__builtin_offsetof(WORK, char_table) == 0x1AC, "char_table");
_Static_assert(__builtin_offsetof(WORK, char_index) == 0x208, "char_index");
_Static_assert(__builtin_offsetof(WORK, cg_type) == 0x214, "cg_type");
_Static_assert(__builtin_offsetof(WORK, my_col_mode) == 0x23C, "my_col_mode");
_Static_assert(__builtin_offsetof(WORK, my_col_code) == 0x23E, "my_col_code");
_Static_assert(__builtin_offsetof(WORK, my_priority) == 0x240, "my_priority");
_Static_assert(__builtin_offsetof(WORK, my_family) == 0x242, "my_family");
_Static_assert(__builtin_offsetof(WORK, my_clear_level) == 0x24A, "my_clear_level");
_Static_assert(__builtin_offsetof(WORK, my_mts) == 0x24C, "my_mts");
_Static_assert(__builtin_offsetof(WORK, my_mr_flag) == 0x24E, "my_mr_flag");
_Static_assert(__builtin_offsetof(WORK, my_mr.size.x) == 0x250, "mr.x");
_Static_assert(__builtin_offsetof(WORK, my_trans_mode) == 0x254, "my_trans_mode");
_Static_assert(__builtin_offsetof(WORK, extra_col) == 0x342, "extra_col");
_Static_assert(sizeof(WORK) == 0x388, "WORK");
_Static_assert(sizeof(BGW) == 0x90, "BGW");
_Static_assert(__builtin_offsetof(BG, bgw[0].r_no_1) == 0x3E, "bgw0 r_no_1");
_Static_assert(__builtin_offsetof(BG, bgw[1].r_no_1) == 0xCE, "bgw1 r_no_1");
_Static_assert(__builtin_offsetof(BG, bgw[0].l_limit) == 0xA0, "bgw0 l_limit");
_Static_assert(__builtin_offsetof(BG, bgw[1].xy[0].disp.pos) == 0xE2, "bgw1 xy0");
#endif

extern EffectRow frw[];
extern BG bg_w;
extern END_W end_w;
extern u8 end_etc_flag;
extern u8 End_PL;
extern s16 gill_time[];
extern s16 end_0_1_time[];
extern u16 ColorRAM[512][64];
extern u16 p1sw_0;
extern u16 p2sw_0;
extern u16 p2sw_1;
extern u32 _end_char_table[];

void sub_000EF0C0(WORK_Other *ewk);
void disp_pos_trans_entry_r(WORK_Other *ewk);
void disp_pos_trans_entry_r4(WORK_Other *ewk);
void char_move(WORK *wk);
void char_move_z(WORK *wk);
void set_char_move_init2(WORK *wk, s16 koc, s16 index, s16 ip, s16 scf);
void sub_000EF072(WORK_Other *ewk);
void sub_000EF088(WORK_Other *ewk);
void cal_all_speed_data(WORK *wk, s16 tm, s16 tx, s16 ty, s16 ax, s16 ay);
void palUpdateGhostCP3(s32 pal, s32 nums);
void make_texcash_work(s16 ix);
s32 load_any_texture_patnum(u16 patnum, u8 kokey, u8 _unused);
void load_any_color(u16 ix, u8 kokey);
void push_effect_work(WORK *wk);
s16 pull_effect_work(s16 index);
s16 get_my_trans_mode(s16 curr);

void effe6_0000(WORK_Other *ewk);
void effe6_0001(WORK_Other *ewk);
void effe6_0002(WORK_Other *ewk);
void effe6_0003(WORK_Other *ewk);
void effe6_0004(WORK_Other *ewk);
void effe6_0005(WORK_Other *ewk);
void effe6_0006(WORK_Other *ewk);
void effe6_0007(WORK_Other *ewk);
void effe6_0009(WORK_Other *ewk);
void effe6_0010(WORK_Other *ewk);
void effe6_0010_sub(WORK_Other *ewk);
void effe6_0011(WORK_Other *ewk);
void effe6_0012(WORK_Other *ewk);
void effe6_0013(WORK_Other *ewk);
void effe6_0014(WORK_Other *ewk);
void effe6_0015(WORK_Other *ewk);
void effe6_0016(WORK_Other *ewk);
void effe6_0017(WORK_Other *ewk);
void effe6_0018(WORK_Other *ewk);
void effe6_0019(WORK_Other *ewk);
void effe6_0020(WORK_Other *ewk);
void effe6_0021(WORK_Other *ewk);
void effe6_0022(WORK_Other *ewk);
void effe6_0023(WORK_Other *ewk);
void effe6_0024(WORK_Other *ewk);
void effe6_0025(WORK_Other *ewk);
void effe6_0026(WORK_Other *ewk);
void effe6_0027(WORK_Other *ewk);
void effe6_0028(WORK_Other *ewk);
void effe6_0029(WORK_Other *ewk);
void effe6_0030(WORK_Other *ewk);
void effe6_0031(WORK_Other *ewk);
void effe6_0032(WORK_Other *ewk);
void effe6_0033(WORK_Other *ewk);
void effe6_init_common(WORK_Other *ewk);
s32 effect_E6_init(u8 char_num);

const s16 effe6_data_tbl[180][8] = {
    { 1, 0, 1, 512, 64, 80, 1, 0 },     { 1, 0, 1, 512, 64, 80, 2, 0 },     { 1, 0, 1, 512, 64, 80, 4, 0 },
    { 1, 0, 1, 576, 64, 78, 5, 0 },     { 1, 0, 1, 512, 64, 80, 6, 0 },     { 1, 0, 1, 512, 64, 82, 8, 0 },
    { 1, 1, 1, 512, 64, 80, 7, 0 },     { 1, 0, 1, 480, 96, 80, 9, 0 },     { 1, 1, 1, 512, 64, 78, 10, 4 },
    { 1, 0, 2, 512, 16, 80, 1, 0 },     { 1, 0, 2, 512, 0, 80, 2, 0 },      { 1, 0, 2, 512, 136, 80, 3, 0 },
    { 1, 1, 3, 608, 136, 80, 4, 0 },    { 1, 1, 4, 432, 136, 80, 1, 17 },   { 2, 1, 5, 512, 144, 78, 1, 1 },
    { 1, 0, 2, 704, 136, 80, 4, 0 },    { 2, 2, 2, 512, 144, 80, 7, 0 },    { 1, 1, 2, -256, 136, 80, 5, 6 },
    { 1, 1, 2, -640, 136, 80, 5, 6 },   { 1, 0, 2, -1792, 136, 80, 6, 5 },  { 1, 1, 2, -1024, 136, 80, 5, 6 },
    { 1, 1, 2, -1408, 136, 80, 5, 6 },  { 3, 0, 6, 384, 768, 40, 1, 7 },    { 3, 0, 6, 128, 544, 40, 1, 7 },
    { 3, 0, 7, 256, 160, 40, 1, 7 },    { 2, 0, 8, 704, 384, 80, 1, 9 },    { 1, 0, 9, 512, 80, 80, 1, 10 },
    { 3, 0, 7, 128, 0, 40, 1, 7 },      { 3, 0, 7, -128, -160, 40, 1, 7 },  { 1, 0, 9, 512, 64, 78, 2, 0 },
    { 1, 0, 9, 512, 128, 80, 3, 0 },    { 1, 0, 10, 512, 64, 78, 1, 2 },    { 3, 1, 9, 320, 896, 80, 5, 0 },
    { 3, 1, 9, 544, 928, 80, 6, 0 },    { 3, 1, 9, 496, 832, 78, 7, 0 },    { 2, 1, 9, 512, 768, 81, 4, 0 },
    { 1, 0, 13, 512, 166, 80, 1, 1 },   { 1, 0, 11, 512, 64, 80, 2, 0 },    { 1, 0, 11, 512, 64, 80, 3, 0 },
    { 1, 0, 11, 496, 64, 78, 4, 0 },    { 1, 0, 11, 512, 96, 78, 5, 0 },    { 1, 0, 12, 448, 144, 76, 1, 12 },
    { 1, 1, 14, 512, 686, 80, 1, 1 },   { 1, 0, 15, 512, 136, 78, 1, 4 },   { 2, 0, 15, 512, 136, 76, 2, 0 },
    { 1, 0, 15, 512, 136, 80, 3, 0 },   { 1, 0, 16, 608, 80, 78, 1, 3 },    { 1, 0, 15, 512, 136, 80, 4, 0 },
    { 1, 1, 15, 512, 136, 80, 5, 0 },   { 1, 0, 16, 608, 80, 78, 1, 3 },    { 1, 0, 17, 512, 96, 78, 1, 13 },
    { 1, 0, 17, 512, 64, 78, 2, 13 },   { 1, 1, 17, 512, 80, 80, 3, 0 },    { 1, 0, 17, 512, 64, 78, 4, 0 },
    { 2, 0, 17, 544, 64, 78, 5, 0 },    { 1, 0, 17, 224, 96, 80, 6, 0 },    { 2, 0, 21, 511, 64, 78, 1, 0 },
    { 1, 1, 18, 512, 136, 80, 1, 0 },   { 1, 0, 18, 512, 136, 80, 2, 0 },   { 1, 0, 18, 512, 136, 80, 3, 0 },
    { 1, 2, 18, 544, 136, 80, 4, 0 },   { 1, 1, 20, 512, 136, 78, 1, 1 },   { 1, 0, 21, 424, 824, 78, 2, 0 },
    { 1, 0, 21, 512, 376, 80, 3, 0 },   { 1, 0, 21, 512, 304, 78, 4, 0 },   { 2, 0, 21, 288, 64, 80, 5, 0 },
    { 1, 0, 22, 512, 64, 80, 1, 1 },    { 1, 0, 21, 512, 144, 78, 6, 14 },  { 1, 1, 21, 512, 376, 80, 7, 0 },
    { 1, 1, 21, 512, 304, 78, 8, 0 },   { 1, 0, 23, 567, 136, 80, 1, 0 },   { 1, 1, 23, 512, 136, 80, 2, 0 },
    { 1, 1, 24, 544, 88, 80, 1, 1 },    { 1, 1, 2, 448, 136, 80, 8, 6 },    { 1, 2, 17, 512, 64, 78, 7, 0 },
    { 1, 2, 25, 512, 80, 80, 1, 2 },    { 1, 0, 26, 512, 64, 80, 1, 0 },    { 2, 0, 26, 512, 464, 78, 2, 0 },
    { 3, 0, 26, 512, 400, 80, 3, 0 },   { 6, 3, 26, 512, 496, 88, 4, 0 },   { 1, 2, 26, 512, 64, 80, 5, 0 },
    { 1, 1, 27, 576, -64, 80, 1, 15 },  { 1, 1, 26, 512, 64, 78, 7, 0 },    { 1, 1, 26, 544, 80, 80, 8, 0 },
    { 1, 1, 27, 672, 48, 80, 6, 0 },    { 1, 1, 28, 575, 136, 80, 1, 0 },   { 1, 0, 28, 512, 136, 80, 2, 0 },
    { 1, 0, 28, 512, 136, 80, 3, 0 },   { 1, 1, 28, 512, 136, 80, 4, 0 },   { 1, 0, 30, 432, 64, 80, 1, 0 },
    { 1, 0, 31, 464, 64, 80, 1, 16 },   { 1, 0, 32, 512, 64, 80, 1, 1 },    { 1, 0, 26, 512, 64, 78, 9, 0 },
    { 2, 0, 33, 768, 136, 78, 2, 0 },   { 3, 0, 33, 536, 392, 80, 3, 0 },   { 2, 0, 33, 368, 320, 80, 4, 0 },
    { 1, 0, 36, 512, -112, 80, 1, 18 }, { 1, 0, 37, 576, 0, 80, 1, 19 },    { 1, 0, 36, 512, 232, 80, 2, 20 },
    { 1, 0, 36, 544, 48, 80, 3, 0 },    { 1, 0, 38, 392, 48, 78, 1, 21 },   { 1, 0, 36, 512, 64, 80, 5, 0 },
    { 1, 0, 36, 511, 64, 78, 6, 0 },    { 1, 0, 36, 480, 64, 76, 7, 0 },    { 1, 0, 36, 512, 112, 74, 8, 0 },
    { 1, 0, 36, 512, 48, 80, 9, 0 },    { 1, 2, 36, 512, 48, 76, 10, 23 },  { 1, 0, 36, 512, -64, 78, 11, 22 },
    { 1, 1, 36, 512, 48, 80, 12, 0 },   { 1, 2, 36, 320, 304, 76, 10, 23 }, { 1, 2, 36, 704, -208, 76, 10, 23 },
    { 1, 0, 39, 511, 64, 80, 1, 1 },    { 1, 0, 40, 511, 64, 80, 1, 1 },    { 1, 0, 41, 511, 64, 80, 1, 1 },
    { 1, 0, 42, 511, 64, 80, 1, 1 },    { 1, 0, 43, 511, 80, 80, 1, 1 },    { 1, 3, 45, 560, 64, 78, 1, 0 },
    { 1, 0, 45, 512, 64, 78, 2, 0 },    { 1, 0, 45, 512, 64, 80, 3, 0 },    { 1, 0, 44, 495, 64, 80, 1, 1 },
    { 1, 0, 45, 512, 64, 80, 4, 0 },    { 1, 1, 65, 544, 64, 80, 1, 29 },   { 1, 0, 45, 560, 64, 78, 1, 0 },
    { 3, 0, 46, 128, 0, 80, 1, 0 },     { 1, 0, 47, 304, 0, 78, 1, 1 },     { 1, 0, 48, 512, 0, 80, 1, 1 },
    { 1, 0, 49, 512, 0, 78, 1, 1 },     { 3, 0, 46, 560, 0, 78, 2, 0 },     { 3, 1, 50, 560, 0, 78, 1, 1 },
    { 2, 0, 1, 416, 64, 78, 3, 0 },     { 3, 0, 1, 576, 64, 80, 12, 0 },    { 2, 0, 1, 512, 64, 78, 11, 0 },
    { 1, 0, 52, 672, 160, 78, 1, 28 },  { 1, 0, 53, 568, 184, 78, 1, 28 },  { 1, 0, 54, 552, 96, 78, 1, 28 },
    { 1, 0, 55, 320, 128, 78, 1, 28 },  { 1, 1, 61, 512, 208, 78, 1, 1 },   { 1, 1, 66, 512, 176, 79, 1, 26 },
    { 1, 1, 60, 704, 135, 76, 1, 24 },  { 1, 1, 67, 368, 135, 76, 1, 24 },  { 1, 1, 57, 448, 208, 77, 1, 1 },
    { 1, 1, 58, 576, 208, 77, 1, 1 },   { 1, 0, 26, 512, 64, 78, 10, 0 },   { 1, 0, 56, 512, 136, 78, 6, 0 },
    { 1, 1, 59, 512, 136, 78, 1, 27 },  { 1, 0, 21, 208, 992, 80, 11, 0 },  { 1, 0, 64, 120, 1016, 78, 1, 1 },
    { 1, 0, 64, 104, 1048, 82, 1, 1 },  { 1, 0, 64, 304, 1008, 78, 1, 1 },  { 1, 0, 64, 264, 1040, 82, 1, 1 },
    { 1, 0, 15, 512, 136, 80, 3, 0 },   { 1, 0, 16, 608, 80, 78, 1, 25 },   { 2, 0, 15, 512, 136, 76, 6, 0 },
    { 1, 2, 18, 512, 136, 79, 5, 0 },   { 1, 0, 62, 512, 64, 80, 1, 0 },    { 1, 0, 62, 512, 64, 80, 2, 0 },
    { 1, 0, 26, 512, 64, 78, 11, 0 },   { 1, 0, 62, 513, 512, 80, 4, 0 },   { 1, 0, 62, 512, 64, 80, 5, 0 },
    { 1, 0, 62, 464, 80, 80, 6, 30 },   { 1, 1, 62, 480, 64, 80, 7, 0 },    { 1, 0, 63, 256, 64, 80, 1, 0 },
    { 1, 1, 45, 576, 64, 78, 6, 0 },    { 1, 0, 63, 512, 64, 78, 3, 0 },    { 1, 0, 63, 512, 64, 80, 4, 0 },
    { 1, 0, 26, 544, 48, 78, 12, 0 },   { 1, 1, 63, 512, 272, 80, 6, 0 },   { 1, 1, 68, 544, 135, 76, 1, 3 },
    { 1, 0, 69, 256, 64, 80, 2, 0 },    { 1, 0, 69, 768, 64, 81, 3, 0 },    { 1, 0, 69, 768, -80, 79, 5, 31 },
    { 1, 0, 69, 768, 64, 80, 4, 33 },   { 1, 0, 69, 256, 64, 81, 6, 0 },    { 1, 0, 69, 769, 64, 80, 7, 0 },
    { 2, 0, 69, 256, 64, 80, 1, 32 },   { 2, 0, 69, 256, 64, 79, 8, 32 },   { 1, 0, 70, 257, 240, 83, 1, 32 },
    { 1, 0, 71, 256, 240, 82, 1, 32 },  { 1, 0, 72, 256, 240, 81, 1, 32 },  { 1, 0, 62, 512, 512, 80, 4, 0 }
};

const s16 effe6_0010_col_tbl[8] = { 8521, 8524, 8525, 8526, 8527, 8526, 8525, 8524 };

const s32 gill_range[7] = { 0x900000, 0x900000, 0x100000, 0x900000, 0x900000, 0x200000, 0x50000 };

static const u16 END_BCB[20] = { 0x8D00, 0x8D40, 0x8D60, 0x8DC0, 0x8DE0, 0x8E00, 0x8E20, 0x8E40, 0x8E60, 0x8E80,
                                 0x8EA0, 0x8EC0, 0x8EE0, 0x8F00, 0x8F20, 0x8F60, 0x8F80, 0x8FA0, 0x8FC0, 0x9000 };

static const u16 END_COL[20] = {
    89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108
};

void effe6_0010_sub(WORK_Other *ewk) {
    ewk->wu.old_rno[5]--;

    if (ewk->wu.old_rno[5] >= 0) {
        return;
    }

    ewk->wu.old_rno[5] = 8;
    ewk->wu.old_rno[2]++;

    if (ewk->wu.old_rno[2] >= 8) {
        ewk->wu.routine_no[1]++;
    }

    ewk->wu.old_rno[2] &= 7;
    ewk->wu.extra_col = effe6_0010_col_tbl[ewk->wu.old_rno[2]];
}

void effe6_init_common(WORK_Other *ewk) {
    ewk->wu.routine_no[1]++;
    ewk->wu.disp_flag = 1;
    set_char_move_init2(&ewk->wu, 0, ewk->wu.old_rno[4], ewk->wu.char_index, 0);
}

s32 effect_E6_init(u8 char_num) {
    WORK_Other *ewk;
    s16 ix;
    const s16 *data_ptr;

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }

    ewk = (WORK_Other *)frw[ix];
    ewk->wu.id = 146;
    ewk->wu.be_flag = 1;
    ewk->wu.type = char_num;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.old_rno[0] = end_w.r_no_2;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.char_table[0] = (u32 *)_end_char_table;
    ewk->wu.my_col_code = 0x12C;
    data_ptr = &effe6_data_tbl[char_num][0];
    ewk->wu.my_family = *data_ptr++;
    ewk->wu.old_rno[6] = *data_ptr++;
    ewk->wu.old_rno[6] += end_w.r_no_2;
    ewk->wu.old_rno[4] = *data_ptr++;
    ewk->wu.xyz[0].disp.pos = *data_ptr++;
    ewk->wu.xyz[1].disp.pos = *data_ptr++;
    ewk->wu.my_priority = ewk->wu.position_z = *data_ptr++;
    ewk->wu.char_index = *data_ptr++;
    ewk->wu.old_rno[1] = ewk->wu.char_index - 1;
    ewk->wu.routine_no[0] = *data_ptr;
    ewk->wu.my_mts = 8;
    ewk->wu.my_trans_mode = get_my_trans_mode(ewk->wu.my_mts);

    switch (char_num) {
    case 79:
        ewk->wu.routine_no[2] = 0;
        break;

    default:
        ewk->wu.routine_no[2] = 4649;
        break;
    }

    return 0;
}

void ending_obj_load(void) {
    make_texcash_work(12);
    load_any_texture_patnum(0x7F30, 23, 0);
    load_any_texture_patnum(0x78B0, 23, 0);
    make_texcash_work(8);
    load_any_texture_patnum(END_BCB[End_PL], 23, 0);
    load_any_color(END_COL[End_PL], 2);
}

void effe6_0000(WORK_Other *ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        effe6_init_common(ewk);
        sub_000EF0C0(ewk);
        break;

    case 1:
        if (ewk->wu.old_rno[6] < end_w.r_no_2) {
            ewk->wu.routine_no[2] = 99;
        }

        if (End_PL == 17) {
            switch (ewk->wu.type) {
            case 0x74:
                ewk->wu.my_col_code = bg_w.bgw[0].l_limit ? 0x12E : 0x12C;
                break;

            case 0x75:
                ewk->wu.my_col_code = bg_w.bgw[0].l_limit ? 0x130 : 0x12C;
                break;

            case 0x76:
                ewk->wu.my_col_code = bg_w.bgw[0].l_limit ? 0x132 : 0x12C;
                break;

            case 0x78:
                ewk->wu.my_col_code = bg_w.bgw[0].l_limit ? 0x138 : 0x12C;
                break;

            case 0xA2:
                ewk->wu.my_col_code = bg_w.bgw[0].l_limit ? 0x12D : 0x12C;
                break;
            }
        }

        sub_000EF0C0(ewk);
    }
}

void effe6_0001(WORK_Other *ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        effe6_init_common(ewk);
        sub_000EF0C0(ewk);
        break;

    case 1:
        if (ewk->wu.old_rno[6] < end_w.r_no_2) {
            ewk->wu.routine_no[2] = 99;
        } else {
            char_move(&ewk->wu);
        }

        sub_000EF0C0(ewk);
        break;
    }
}

void effe6_0002(WORK_Other *ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        effe6_init_common(ewk);
        break;

    case 1:
        if (ewk->wu.old_rno[6] < end_w.r_no_2) {
            ewk->wu.routine_no[2] = 99;
        } else {
            char_move(&ewk->wu);

            if (ewk->wu.cg_type) {
                end_etc_flag = 1;
            }
        }

        sub_000EF0C0(ewk);
        break;
    }
}

void effe6_0003(WORK_Other *ewk) {
    if (ewk->wu.old_rno[6] < end_w.r_no_2) {
        ewk->wu.routine_no[2] = 99;
    }

    switch (ewk->wu.routine_no[1]) {
    case 0:
        effe6_init_common(ewk);
        break;

    case 1:
        char_move(&ewk->wu);

        if (ewk->wu.cg_type) {
            ewk->wu.routine_no[2] = 99;
        }

        sub_000EF0C0(ewk);
        break;
    }
}

void effe6_0004(WORK_Other *ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        effe6_init_common(ewk);
        ewk->wu.old_rno[2] = 1;
        ewk->wu.old_rno[5] = 1;
        sub_000EF0C0(ewk);
        break;

    case 1:
        if (ewk->wu.old_rno[6] < end_w.r_no_2) {
            ewk->wu.routine_no[2] = 99;
        } else {
            ewk->wu.old_rno[5]--;

            if (ewk->wu.old_rno[5] <= 0) {
                ewk->wu.disp_flag ^= 1;
                ewk->wu.old_rno[5] = ewk->wu.old_rno[2];
            }
        }

        sub_000EF0C0(ewk);
        break;
    }
}

void effe6_0005(WORK_Other *ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        effe6_init_common(ewk);
        sub_000EF0C0(ewk);
        break;

    case 1:
        if (ewk->wu.old_rno[6] < end_w.r_no_2) {
            ewk->wu.routine_no[1]++;
            ewk->wu.mvxy.a[0].sp = 0x80000;
            ewk->wu.mvxy.d[0].sp = 0x40000;
        }

        sub_000EF0C0(ewk);
        break;

    case 2:
        sub_000EF072(ewk);

        if (ewk->wu.xyz[0].disp.pos > -1216) {
            ewk->wu.routine_no[2] = 99;
            ewk->wu.disp_flag = 0;
            end_etc_flag = 1;
        }

        sub_000EF0C0(ewk);
        break;
    }
}

void effe6_0006(WORK_Other *ewk) {
    s16 work;

    switch (ewk->wu.routine_no[1]) {
    case 0:
        effe6_init_common(ewk);
        ewk->wu.old_rno[2] = ewk->wu.xyz[0].disp.pos;
        sub_000EF0C0(ewk);
        break;

    case 1:
        if (ewk->wu.old_rno[6] < end_w.r_no_2) {
            ewk->wu.routine_no[2] = 99;
        } else {
            if (ewk->wu.type == 73) {
                work = ewk->wu.old_rno[2] - 704;
            } else {
                work = ewk->wu.old_rno[2] - 384;
            }

            if (work > bg_w.bgw[ewk->wu.my_family - 1].xy[0].disp.pos) {
                ewk->wu.routine_no[2] = 99;
            }
        }

        sub_000EF0C0(ewk);
        break;
    }
}

void effe6_0007(WORK_Other *ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        switch (ewk->wu.type) {
        case 22:
            ewk->wu.my_col_code = 0x12C;
            break;

        case 23:
            ewk->wu.my_col_code = 0x12D;
            break;

        case 24:
        case 27:
        case 28:
            ewk->wu.my_col_code = 0x12E;
            break;
        }

        ewk->wu.my_col_mode = 0x200;
        effe6_init_common(ewk);
        sub_000EF0C0(ewk);
        break;

    case 1:
        if (ewk->wu.old_rno[6] < end_w.r_no_2) {
            ewk->wu.routine_no[2] = 99;
        } else if (ewk->wu.routine_no[0] & 1) {
            char_move(&ewk->wu);
        }

        switch (ewk->wu.type) {
        case 22:
        case 23:
        case 24:
        case 27:
        case 28:
            disp_pos_trans_entry_r4(ewk);
            break;

        default:
            disp_pos_trans_entry_r(ewk);
            break;
        }

        break;
    }
}

void effe6_0009(WORK_Other *ewk) {
    if (ewk->wu.old_rno[6] < end_w.r_no_2) {
        ewk->wu.routine_no[2] = 99;
    }

    switch (ewk->wu.routine_no[1]) {
    case 0:
        effe6_init_common(ewk);
        sub_000EF0C0(ewk);
        break;

    case 1:
        ewk->wu.xyz[0].cal -= 0xB000;
        ewk->wu.xyz[1].cal += -0x1A000;

        if (ewk->wu.xyz[1].disp.pos < -199) {
            ewk->wu.routine_no[1]++;
            bg_w.bgw[0].r_no_1++;
            bg_w.bgw[1].r_no_1++;
        }

        char_move(&ewk->wu);
        sub_000EF0C0(ewk);
        break;

    case 2:
        char_move(&ewk->wu);
        ewk->wu.xyz[1].cal += 0x800;
        sub_000EF0C0(ewk);
        break;
    }
}

void effe6_0010(WORK_Other *ewk) {
    if (ewk->wu.old_rno[6] < end_w.r_no_2) {
        ewk->wu.routine_no[2] = 99;
    }

    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.old_rno[2] = 0;
        ewk->wu.old_rno[5] = 8;
        ewk->wu.my_col_mode = 0x200;
        effe6_init_common(ewk);
        ewk->wu.extra_col = 0x2149;
        sub_000EF0C0(ewk);
        break;

    case 1:
        ewk->wu.xyz[1].cal += 0x20000;

        if (ewk->wu.xyz[1].disp.pos > 160) {
            ewk->wu.routine_no[1]++;
            ewk->wu.xyz[1].cal = 0xA00000;
            bg_w.bgw[0].r_no_1++;
        }

        /* fallthrough */

    case 2:
        effe6_0010_sub(ewk);
        /* fallthrough */

    case 3:
        sub_000EF0C0(ewk);
        break;
    }
}

void effe6_0011(WORK_Other *ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        effe6_init_common(ewk);
        ewk->wu.old_rno[2] = 30;
        sub_000EF0C0(ewk);
        break;

    case 1:
        ewk->wu.old_rno[2]--;

        if (ewk->wu.old_rno[2] <= 0) {
            ewk->wu.routine_no[1]++;
        }

        sub_000EF0C0(ewk);
        break;

    case 2:
        if (ewk->wu.old_rno[6] < end_w.r_no_2) {
            ewk->wu.routine_no[2] = 99;
        } else if (ewk->wu.type == 30) {
            ewk->wu.xyz[1].cal -= 0x8000;

            if (ewk->wu.xyz[1].disp.pos < 65) {
                ewk->wu.routine_no[2] = 99;
                ewk->wu.xyz[1].cal = 0x400000;
            }
        }

        sub_000EF0C0(ewk);
        break;
    }
}

void effe6_0012(WORK_Other *ewk) {
    if (ewk->wu.old_rno[6] < end_w.r_no_2) {
        ewk->wu.routine_no[2] = 99;
    }

    switch (ewk->wu.routine_no[1]) {
    case 0:
        effe6_init_common(ewk);
        sub_000EF0C0(ewk);
        break;

    case 1:
        char_move(&ewk->wu);

        if (ewk->wu.cg_type == 0xFF) {
            ewk->wu.routine_no[1]++;
            ewk->wu.mvxy.a[1].sp = -0x5000;
            ewk->wu.mvxy.d[1].sp = -0x2000;
        }

        sub_000EF0C0(ewk);
        break;

    case 2:
        sub_000EF088(ewk);

        if (ewk->wu.xyz[1].disp.pos < 48) {
            ewk->wu.routine_no[2] = 99;
        }

        sub_000EF0C0(ewk);
        break;
    }
}

void effe6_0013(WORK_Other *ewk) {
    if (ewk->wu.old_rno[6] < end_w.r_no_2) {
        ewk->wu.routine_no[2] = 99;
    }

    switch (ewk->wu.routine_no[1]) {
    case 0:
        effe6_init_common(ewk);
        sub_000EF0C0(ewk);

        if (ewk->wu.type == 50) {
            ewk->wu.mvxy.a[1].sp = 0;
            ewk->wu.mvxy.d[1].sp = 0x400;
            break;
        }

        ewk->wu.mvxy.a[1].sp = 0;
        ewk->wu.mvxy.d[1].sp = -0x400;
        break;

    case 1:
        sub_000EF088(ewk);

        if (ewk->wu.type == 50) {
            if (ewk->wu.xyz[1].disp.pos > 272) {
                ewk->wu.routine_no[2] = 99;
            }
        } else if (ewk->wu.xyz[1].disp.pos < 32) {
            ewk->wu.routine_no[2] = 99;
        }

        sub_000EF0C0(ewk);
        break;
    }
}

void effe6_0014(WORK_Other *ewk) {
    if (ewk->wu.old_rno[6] < end_w.r_no_2) {
        ewk->wu.routine_no[2] = 99;
    }

    switch (ewk->wu.routine_no[1]) {
    case 0:
        effe6_init_common(ewk);
        ewk->wu.my_mr_flag = 1;
        ewk->wu.old_rno[2] = 4;
        ewk->wu.my_mr.size.x = 63;
        ewk->wu.my_mr.size.y = 63;
        sub_000EF0C0(ewk);
        break;

    case 1:
        ewk->wu.old_rno[2]--;

        if (ewk->wu.old_rno[2] < 0) {
            ewk->wu.routine_no[1]++;
            ewk->wu.old_rno[2] = 4;
        }

        sub_000EF0C0(ewk);
        break;

    case 2:
        ewk->wu.old_rno[2]--;

        if (ewk->wu.old_rno[2] < 0) {
            ewk->wu.old_rno[2] = 2;
            ewk->wu.my_mr.size.x--;
            ewk->wu.my_mr.size.y--;

            if (ewk->wu.my_mr.size.x < 60) {
                ewk->wu.routine_no[1]++;
                set_char_move_init2(&ewk->wu, 0, 21, 9, 0);
                ewk->wu.old_rno[2] = 4;
            } else {
                ewk->wu.old_rno[2] = 3;
            }
        }

        sub_000EF0C0(ewk);
        break;

    case 3:
        ewk->wu.old_rno[2]--;

        if (ewk->wu.old_rno[2] < 0) {
            ewk->wu.old_rno[2] = 3;
            ewk->wu.my_mr.size.x--;
            ewk->wu.my_mr.size.y--;

            if (ewk->wu.my_mr.size.x < 56) {
                ewk->wu.routine_no[1]++;
                set_char_move_init2(&ewk->wu, 0, 21, 10, 0);
                ewk->wu.old_rno[2] = 4;
            }
        }

        sub_000EF0C0(ewk);
        break;

    case 4:
        ewk->wu.old_rno[2]--;

        if (ewk->wu.old_rno[2] < 0) {
            ewk->wu.old_rno[2] = 4;
            ewk->wu.my_mr.size.x--;
            ewk->wu.my_mr.size.y--;

            if (ewk->wu.my_mr.size.x <= 0) {
                ewk->wu.routine_no[2] = 99;
                ewk->wu.my_mr.size.x = 0;
                ewk->wu.my_mr.size.y = 0;
            }
        }

        sub_000EF0C0(ewk);
        break;
    }
}

void effe6_0015(WORK_Other *ewk) {
    if (ewk->wu.old_rno[6] < end_w.r_no_2) {
        ewk->wu.routine_no[2] = 99;
    }

    switch (ewk->wu.routine_no[1]) {
    case 0:
        effe6_init_common(ewk);
        ewk->wu.old_rno[2] = 40;
        cal_all_speed_data(&ewk->wu, ewk->wu.old_rno[2], 544, 48, 2, 2);
        break;

    case 1:
        if (ewk->wu.old_rno[6] == end_w.r_no_2) {
            ewk->wu.routine_no[1] = 3;
            ewk->wu.xyz[0].disp.pos = 544;
            ewk->wu.xyz[1].disp.pos = 48;
        } else {
            ewk->wu.old_rno[2]--;

            if (ewk->wu.old_rno[2] <= 0) {
                ewk->wu.routine_no[1]++;
                ewk->wu.xyz[0].disp.pos = 544;
                ewk->wu.xyz[1].disp.pos = 48;
            } else {
                sub_000EF072(ewk);
                sub_000EF088(ewk);
            }
        }

        sub_000EF0C0(ewk);
        break;

    case 2:
        if (ewk->wu.old_rno[6] == end_w.r_no_2) {
            ewk->wu.routine_no[1] = 3;
        } else {
            char_move(&ewk->wu);

            if (ewk->wu.cg_type) {
                ewk->wu.routine_no[1] = 3;
            }
        }

        /* fallthrough */

    case 3:
        sub_000EF0C0(ewk);
        break;
    }
}

void effe6_0016(WORK_Other *ewk) {
    if (ewk->wu.old_rno[6] < end_w.r_no_2) {
        ewk->wu.routine_no[2] = 99;
    }

    switch (ewk->wu.routine_no[1]) {
    case 0:
        effe6_init_common(ewk);
        break;

    case 1:
    case 3:
        char_move(&ewk->wu);

        if (ewk->wu.cg_type == 9) {
            if (ewk->wu.routine_no[1] == 1) {
                ewk->wu.old_rno[2] = 10;
            } else {
                ewk->wu.old_rno[2] = 80;
            }

            ewk->wu.routine_no[1]++;
            char_move_z(&ewk->wu);
        } else {
            sub_000EF0C0(ewk);
        }

        break;

    case 2:
    case 4:
        ewk->wu.old_rno[2]--;

        if (ewk->wu.old_rno[2] < 1) {
            ewk->wu.routine_no[1]++;
        }

        break;

    case 5:
        char_move(&ewk->wu);

        if (ewk->wu.cg_type == 0xFF) {
            ewk->wu.routine_no[2] = 99;
        }

        sub_000EF0C0(ewk);
        break;
    }
}

void effe6_0017(WORK_Other *ewk) {
    if (ewk->wu.old_rno[6] < end_w.r_no_2) {
        ewk->wu.routine_no[2] = 99;
    }

    switch (ewk->wu.routine_no[1]) {
    case 0:
        effe6_init_common(ewk);
        sub_000EF0C0(ewk);
        break;

    case 1:
        char_move(&ewk->wu);

        if (ewk->wu.cg_type) {
            ewk->wu.routine_no[1]++;
            ewk->wu.disp_flag = 2;
            ewk->wu.blink_timing = 1;
            ewk->wu.old_rno[2] = 60;
        }

        sub_000EF0C0(ewk);
        break;

    case 2:
        ewk->wu.old_rno[2]--;

        if (ewk->wu.old_rno[2] <= 0) {
            ewk->wu.routine_no[2] = 99;
            ewk->wu.disp_flag = 0;
        }

        sub_000EF0C0(ewk);
        break;
    }
}

void effe6_0018(WORK_Other *ewk) {
    if (ewk->wu.old_rno[6] < end_w.r_no_2) {
        ewk->wu.routine_no[2] = 99;
    }

    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;
        ewk->wu.old_rno[2] = 70;
        break;

    case 1:
        ewk->wu.old_rno[2]--;

        if (ewk->wu.old_rno[2] <= 0) {
            effe6_init_common(ewk);
            sub_000EF0C0(ewk);
        }

        break;

    case 2:
        ewk->wu.xyz[1].cal += 0x10000;

        if (ewk->wu.xyz[1].disp.pos >= 48) {
            ewk->wu.routine_no[1]++;
        }

        /* fallthrough */

    case 3:
        sub_000EF0C0(ewk);
        break;
    }
}

void effe6_0019(WORK_Other *ewk) {
    if (ewk->wu.old_rno[0] != end_w.r_no_2) {
        ewk->wu.routine_no[2] = 99;
    }

    switch (ewk->wu.routine_no[1]) {
    case 0:
        effe6_init_common(ewk);
        break;

    case 1:
        char_move(&ewk->wu);

        if (ewk->wu.cg_type) {
            ewk->wu.routine_no[1]++;
            ewk->wu.xyz[0].disp.pos = 496;
            ewk->wu.xyz[1].disp.pos = 16;
            set_char_move_init2(&ewk->wu, 0, 37, 1, 0);
        }

        sub_000EF0C0(ewk);
        break;

    case 2:
        char_move(&ewk->wu);

        if (ewk->wu.cg_type) {
            ewk->wu.routine_no[1]++;
            ewk->wu.xyz[0].disp.pos = 416;
            ewk->wu.xyz[1].disp.pos = 48;
            set_char_move_init2(&ewk->wu, 0, 37, 1, 0);
        }

        sub_000EF0C0(ewk);
        break;

    case 3:
        char_move(&ewk->wu);

        if (ewk->wu.cg_type) {
            ewk->wu.routine_no[2] = 99;
            end_etc_flag = 1;
            ewk->wu.disp_flag = 0;
        }

        sub_000EF0C0(ewk);
        break;
    }
}

void effe6_0020(WORK_Other *ewk) {
    if (ewk->wu.old_rno[6] < end_w.r_no_2) {
        ewk->wu.routine_no[2] = 99;
    }

    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;
        ewk->wu.old_rno[2] = 1;
        break;

    case 1:
        ewk->wu.old_rno[2]--;

        if (ewk->wu.old_rno[2] <= 0) {
            effe6_init_common(ewk);
            sub_000EF0C0(ewk);
        }

        break;

    case 2:
        ewk->wu.xyz[1].cal += -0x18000;

        if (ewk->wu.xyz[1].disp.pos <= 0) {
            ewk->wu.routine_no[1]++;
            ewk->wu.xyz[1].cal = 0;
        }

        /* fallthrough */

    case 3:
        sub_000EF0C0(ewk);
        break;
    }
}

void effe6_0021(WORK_Other *ewk) {
    if (ewk->wu.old_rno[6] < end_w.r_no_2) {
        ewk->wu.routine_no[2] = 99;
    }

    switch (ewk->wu.routine_no[1]) {
    case 0:
        effe6_init_common(ewk);
        ewk->wu.old_rno[2] = 48;
        ewk->wu.my_mr_flag = 1;
        ewk->wu.my_mr.size.x = 63;
        ewk->wu.my_mr.size.y = 63;
        sub_000EF0C0(ewk);
        break;

    case 1:
        char_move(&ewk->wu);

        if (ewk->wu.xyz[0].disp.pos >= 576) {
            ewk->wu.routine_no[1]++;
            ewk->wu.xyz[0].cal = 0x2400000;
        }

        /* fallthrough */

    case 2:
        sub_000EF0C0(ewk);
        break;
    }
}

void effe6_0022(WORK_Other *ewk) {
    if (ewk->wu.old_rno[6] < end_w.r_no_2) {
        ewk->wu.routine_no[2] = 99;
    }

    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;
        ewk->wu.old_rno[2] = 180;
        break;

    case 1:
        ewk->wu.old_rno[2]--;

        if (ewk->wu.old_rno[2] < 0) {
            ewk->wu.mvxy.a[1].sp = 0x28000;
            effe6_init_common(ewk);
            sub_000EF0C0(ewk);
        }

        break;

    case 2:
        ewk->wu.xyz[1].cal += ewk->wu.mvxy.a[1].sp;

        if (ewk->wu.xyz[1].disp.pos >= 48) {
            ewk->wu.routine_no[1]++;
            ewk->wu.xyz[1].cal = 0x300000;
        }

        /* fallthrough */

    case 3:
        sub_000EF0C0(ewk);
        break;
    }
}

void effe6_0023(WORK_Other *ewk) {
    if (ewk->wu.old_rno[6] < end_w.r_no_2) {
        ewk->wu.routine_no[2] = 99;
    }

    switch (ewk->wu.routine_no[1]) {
    case 0:
        effe6_init_common(ewk);
        ewk->wu.mvxy.a[0].sp = 0x12000;
        ewk->wu.mvxy.a[1].sp = 0x18000;
        sub_000EF0C0(ewk);
        break;

    case 1:
        ewk->wu.xyz[0].cal += ewk->wu.mvxy.a[0].sp;
        ewk->wu.xyz[1].cal -= ewk->wu.mvxy.a[1].sp;

        if (ewk->wu.xyz[1].disp.pos < -207) {
            ewk->wu.xyz[0].cal = 0x1400000;
            ewk->wu.xyz[1].cal = 0x1300000;
        }

        sub_000EF0C0(ewk);
        break;
    }
}

void effe6_0024(WORK_Other *ewk) {
    if (ewk->wu.old_rno[6] < end_w.r_no_2) {
        ewk->wu.routine_no[2] = 99;
    }

    switch (ewk->wu.routine_no[1]) {
    case 0:
        effe6_init_common(ewk);
        sub_000EF0C0(ewk);
        break;

    case 1:
        if (ewk->wu.old_rno[6] == end_w.r_no_2) {
            ewk->wu.routine_no[1]++;
            ewk->wu.old_rno[2] = 0;
        }

        sub_000EF0C0(ewk);
        break;

    case 2:
        char_move(&ewk->wu);

        if (ewk->wu.type == 138) {
            if (ewk->wu.xyz[0].disp.pos < 641) {
                ewk->wu.routine_no[1]++;
            }
        } else if (ewk->wu.xyz[0].disp.pos >= 424) {
            ewk->wu.routine_no[1]++;
        }

        /* fallthrough */

    case 3:
        sub_000EF0C0(ewk);
        break;
    }
}

void effe6_0025(WORK_Other *ewk) {
    u16 work;

    switch (ewk->wu.routine_no[1]) {
    case 0:
        effe6_init_common(ewk);
        sub_000EF0C0(ewk);
        ewk->wu.old_rno[2] = 0;
        break;

    case 1:
        if (ewk->wu.type == 150) {
            if (p1sw_0 & 8) {
                ewk->wu.xyz[0].disp.pos++;
            }

            if (p1sw_0 & 4) {
                ewk->wu.xyz[0].disp.pos--;
            }

            if (p1sw_0 & 1) {
                ewk->wu.xyz[1].disp.pos++;
            }

            if (p1sw_0 & 2) {
                ewk->wu.xyz[1].disp.pos--;
            }
        } else {
            if (p2sw_0 & 8) {
                ewk->wu.xyz[0].disp.pos++;
            }

            if (p2sw_0 & 4) {
                ewk->wu.xyz[0].disp.pos--;
            }

            if (p2sw_0 & 1) {
                ewk->wu.xyz[1].disp.pos++;
            }

            if (p2sw_0 & 2) {
                ewk->wu.xyz[1].disp.pos--;
            }

            work = p2sw_0 & ~p2sw_1;

            if (work & 0x10) {
                char_move_z(&ewk->wu);
                ewk->wu.old_rno[2]++;

                if (ewk->wu.old_rno[2] >= 7) {
                    ewk->wu.old_rno[2] = 0;
                }
            }

            switch (ewk->wu.old_rno[2]) {
            case 0:
                ewk->wu.xyz[0].disp.pos = 608;
                break;

            case 1:
                ewk->wu.xyz[0].disp.pos = 609;
                break;

            case 2:
                ewk->wu.xyz[0].disp.pos = 610;
                break;

            case 3:
                ewk->wu.xyz[0].disp.pos = 607;
                break;

            case 4:
                ewk->wu.xyz[0].disp.pos = 606;
                break;

            case 5:
                ewk->wu.xyz[0].disp.pos = 611;
            }
        }

        sub_000EF0C0(ewk);
        break;

    default:
        push_effect_work(&ewk->wu);
        break;
    }
}

void effe6_0026(WORK_Other *ewk) {
    if (ewk->wu.old_rno[6] < end_w.r_no_2) {
        ewk->wu.routine_no[2] = 99;
    }

    switch (ewk->wu.routine_no[1]) {
    case 0:
        effe6_init_common(ewk);
        sub_000EF0C0(ewk);
        break;

    case 1:
        char_move(&ewk->wu);

        if (ewk->wu.xyz[1].disp.pos < 152) {
            ewk->wu.routine_no[1]++;
        }

        /* fallthrough */

    case 2:
        sub_000EF0C0(ewk);
        break;

    default:
        push_effect_work(&ewk->wu);
        break;
    }
}

void effe6_0027(WORK_Other *ewk) {
    if (ewk->wu.old_rno[6] < end_w.r_no_2) {
        ewk->wu.routine_no[2] = 99;
    }

    switch (ewk->wu.routine_no[1]) {
    case 0:
        effe6_init_common(ewk);
        sub_000EF0C0(ewk);
        break;

    case 1:
        char_move(&ewk->wu);

        if (ewk->wu.cg_type == 0xFF) {
            ewk->wu.routine_no[1]++;
            effect_E6_init(0xA7);
        }

        /* fallthrough */

    case 2:
        sub_000EF0C0(ewk);
        break;

    default:
        push_effect_work(&ewk->wu);
        break;
    }
}

void effe6_0028(WORK_Other *ewk) {
    if (ewk->wu.old_rno[6] < end_w.r_no_2) {
        ewk->wu.routine_no[2] = 99;
    }

    switch (ewk->wu.routine_no[1]) {
    case 0:
        effe6_init_common(ewk);
        sub_000EF0C0(ewk);
        break;

    case 1:
        char_move(&ewk->wu);

        if (ewk->wu.cg_type == 9) {
            ewk->wu.disp_flag = 0;
        } else {
            ewk->wu.disp_flag = 1;
        }

        sub_000EF0C0(ewk);
        break;

    default:
        push_effect_work(&ewk->wu);
        break;
    }
}

void effe6_0029(WORK_Other *ewk) {
    if (ewk->wu.old_rno[6] < end_w.r_no_2) {
        ewk->wu.routine_no[2] = 99;
    }

    switch (ewk->wu.routine_no[1]) {
    case 0:
        effe6_init_common(ewk);
        ewk->wu.old_rno[2] = 5;
        ewk->wu.my_mr_flag = 1;
        ewk->wu.my_mr.size.x = 63;
        ewk->wu.my_mr.size.y = 63;
        sub_000EF0C0(ewk);
        break;

    case 1:
        char_move(&ewk->wu);

        if (ewk->wu.xyz[0].disp.pos < 224) {
            ewk->wu.routine_no[2] = 99;
        } else {
            ewk->wu.old_rno[2]--;

            if (ewk->wu.old_rno[2] <= 0) {
                ewk->wu.old_rno[2] = 5;
                ewk->wu.my_mr.size.x++;
                ewk->wu.my_mr.size.y++;

                if (ewk->wu.my_mr.size.x >= 127) {
                    ewk->wu.routine_no[1]++;
                    ewk->wu.my_mr.size.x = 127;
                    ewk->wu.my_mr.size.y = 127;
                }
            }
        }

        sub_000EF0C0(ewk);
        break;

    case 2:
        sub_000EF0C0(ewk);
        break;

    default:
        push_effect_work(&ewk->wu);
        break;
    }
}

void effe6_0030(WORK_Other *ewk) {
    s16 i;

    if (ewk->wu.old_rno[6] < end_w.r_no_2) {
        ewk->wu.routine_no[2] = 99;
    }

    switch (ewk->wu.routine_no[1]) {
    case 0:
        effe6_init_common(ewk);
        sub_000EF0C0(ewk);
        break;

    case 1:
        if (end_w.r_no_2 == 4 && bg_w.bgw[0].r_no_1 == 1) {
            switch (bg_w.bgw[0].l_limit) {
            case 0:
                ewk->wu.my_col_code = 0x130;
                break;

            case 1:
                ewk->wu.my_col_code = 0x134;
                break;

            case 2:
                ewk->wu.my_col_code = 0x138;
                break;

            case 3:
                ewk->wu.my_col_code = 0x13C;
                break;
            }
        }

        if (end_etc_flag) {
            ewk->wu.routine_no[1]++;

            for (i = 0; i < 64; i++) {
                ColorRAM[327][i] = ColorRAM[343][i];
            }

            for (i = 0; i < 64; i++) {
                ColorRAM[328][i] = ColorRAM[343][i];
            }

            for (i = 0; i < 64; i++) {
                ColorRAM[329][i] = ColorRAM[343][i];
            }

            for (i = 0; i < 64; i++) {
                ColorRAM[330][i] = ColorRAM[343][i];
            }

            ewk->wu.disp_flag = 2;
            ewk->wu.blink_timing = 1;
            ewk->wu.old_rno[2] = 30;
            palUpdateGhostCP3(0x147, 4);
        }

        sub_000EF0C0(ewk);
        break;

    case 2:
        ewk->wu.old_rno[2]--;

        if (ewk->wu.old_rno[2] < 0) {
            ewk->wu.routine_no[2] = 99;
        }

        sub_000EF0C0(ewk);
        break;

    default:
        push_effect_work(&ewk->wu);
        break;
    }
}

void effe6_0031(WORK_Other *ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        effe6_init_common(ewk);
        ewk->wu.old_rno[5] = gill_time[0];
        sub_000EF0C0(ewk);
        break;

    case 1:
        ewk->wu.xyz[1].cal += gill_range[0] / gill_time[0];

        if (!(--ewk->wu.old_rno[5])) {
            ewk->wu.routine_no[1]++;
        }

        sub_000EF0C0(ewk);
        break;

    case 2:
        if (end_etc_flag) {
            ewk->wu.routine_no[1]++;
            ewk->wu.old_rno[5] = gill_time[1];
            end_etc_flag = 0;
        }

        sub_000EF0C0(ewk);
        break;

    case 3:
        ewk->wu.xyz[1].cal -= gill_range[1] / gill_time[1];

        if (!ewk->wu.old_rno[5]--) {
            ewk->wu.routine_no[1]++;
        }

        sub_000EF0C0(ewk);
        break;

    case 4:
        if (ewk->wu.old_rno[6] < end_w.r_no_2) {
            ewk->wu.routine_no[2] = 99;
        }

        sub_000EF0C0(ewk);
        break;
    }
}

void effe6_0032(WORK_Other *ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        effe6_init_common(ewk);
        ewk->wu.old_rno[5] = gill_time[2];
        ewk->wu.old_rno[2] = ewk->wu.old_rno[7] = 0;

        switch (ewk->wu.type) {
        case 176:
            ewk->wu.routine_no[1] = 9;
            break;

        case 177:
        case 178:
            ewk->wu.routine_no[1] = 10;
            ewk->wu.old_rno[5] = gill_time[9];
            break;
        }

        sub_000EF0C0(ewk);
        break;

    case 1:
        if (ewk->wu.old_rno[6] < end_w.r_no_2) {
            ewk->wu.routine_no[2] = 99;
        }

        switch (ewk->wu.type) {
        case 174:
            ewk->wu.xyz[1].cal -= gill_range[2] / gill_time[2];
            break;

        case 175:
            ewk->wu.xyz[1].cal -= gill_range[3] / gill_time[2];
            break;
        }

        if (!ewk->wu.old_rno[5]--) {
            ewk->wu.routine_no[1]++;
        }

        sub_000EF0C0(ewk);
        break;

    case 2:
        if (ewk->wu.old_rno[6] < end_w.r_no_2) {
            ewk->wu.routine_no[2] = 99;
        }

        ewk->wu.routine_no[1]++;
        ewk->wu.old_rno[5] = gill_time[3];
        sub_000EF0C0(ewk);

    case 3:
        if (ewk->wu.old_rno[6] < end_w.r_no_2) {
            ewk->wu.routine_no[2] = 99;
        }

        ewk->wu.xyz[1].cal -= gill_range[4] / gill_time[3];

        if (!ewk->wu.old_rno[5]--) {
            ewk->wu.routine_no[1]++;
        }

        sub_000EF0C0(ewk);
        break;

    case 4:
        if (ewk->wu.old_rno[6] < end_w.r_no_2) {
            ewk->wu.routine_no[2] = 99;
        }

        sub_000EF0C0(ewk);
        break;

    case 9:
        char_move(&ewk->wu);

        if (ewk->wu.cg_type) {
            ewk->wu.routine_no[1]++;
            end_etc_flag = 1;
            effect_E6_init(177);
            effect_E6_init(178);
            ewk->wu.old_rno[5] = gill_time[9];
        }

        sub_000EF0C0(ewk);
        break;

    case 10:
        if (ewk->wu.old_rno[6] < end_w.r_no_2) {
            ewk->wu.routine_no[2] = 99;
        }

        ewk->wu.routine_no[1]++;
        ewk->wu.old_rno[5] = gill_time[4];
        char_move(&ewk->wu);
        sub_000EF0C0(ewk);
        break;

    case 11:
        if (ewk->wu.old_rno[6] < end_w.r_no_2) {
            ewk->wu.routine_no[2] = 99;
        }

        switch (ewk->wu.type) {
        case 177:
            ewk->wu.xyz[0].cal -= gill_range[5] / gill_time[4];
            break;

        case 178:
            ewk->wu.xyz[0].cal += gill_range[6] / gill_time[4];
            break;
        }

        if (!ewk->wu.old_rno[5]--) {
            ewk->wu.routine_no[1]++;
        }

        char_move(&ewk->wu);
        sub_000EF0C0(ewk);
        break;

    case 12:
        if (ewk->wu.old_rno[6] < end_w.r_no_2) {
            ewk->wu.routine_no[2] = 99;
        }

        char_move(&ewk->wu);
        sub_000EF0C0(ewk);
        break;
    }
}

void effe6_0033(WORK_Other *ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        effe6_init_common(ewk);
        ewk->wu.old_rno[5] = end_0_1_time[0] + gill_time[0];
        ewk->wu.my_clear_level = 0xFF;
        sub_000EF0C0(ewk);
        break;

    case 1:
        if (ewk->wu.old_rno[6] < end_w.r_no_2) {
            ewk->wu.routine_no[2] = 99;
        }

        if (!ewk->wu.old_rno[5]--) {
            ewk->wu.routine_no[1]++;
        }

        sub_000EF0C0(ewk);
        break;

    case 2:
        if (ewk->wu.old_rno[6] < end_w.r_no_2) {
            ewk->wu.routine_no[2] = 99;
        }

        ewk->wu.my_clear_level -= 256 / gill_time[7];

        if (ewk->wu.my_clear_level <= 0) {
            ewk->wu.routine_no[1]++;
            ewk->wu.my_clear_level = 0;
        }

        sub_000EF0C0(ewk);
        break;

    case 3:
        if (ewk->wu.old_rno[6] < end_w.r_no_2) {
            ewk->wu.routine_no[2] = 99;
        }

        sub_000EF0C0(ewk);
        break;
    }
}

void effect_E6_move(WORK_Other *ewk) {
    void (*effe6_jp[34])(WORK_Other *) = { effe6_0000, effe6_0001, effe6_0002, effe6_0003, effe6_0004, effe6_0005,
                                          effe6_0006, effe6_0007, effe6_0007, effe6_0009, effe6_0010, effe6_0011,
                                          effe6_0012, effe6_0013, effe6_0014, effe6_0015, effe6_0016, effe6_0017,
                                          effe6_0018, effe6_0019, effe6_0020, effe6_0021, effe6_0022, effe6_0023,
                                          effe6_0024, effe6_0025, effe6_0026, effe6_0027, effe6_0028, effe6_0029,
                                          effe6_0030, effe6_0031, effe6_0032, effe6_0033 };

    switch (ewk->wu.routine_no[2]) {
    case 0x0:
        effe6_jp[ewk->wu.routine_no[0]](ewk);
        break;

    case 99:
        ewk->wu.routine_no[2]++;
        break;

    case 100:
        push_effect_work(&ewk->wu);
        break;

    case 4649:
        ewk->wu.routine_no[2] = 0;
        break;
    }
}
