/* Effect D3, retail sf33rd.xbe.
 * akebono_finish is 0xBBCE5 size 0x21C.
 * syungoku_finish is 0xBBF01 size 0x1EC.
 * effect_D3_init is 0xBC0ED size 0x42 and is interior.
 * effect_D3_move is 0xBC12F size 0x19 and is interior.
 * The pull failure is an early ret.
 * 0xBBBCA stays unnamed. 0xBC148 stays unnamed.
 *
 * 0xBBBCA repeats the scr_calc loop and the
 * overwrite_panel, ake_Family_Set2, position, and
 * Bg_Family_Set_appoint display calls of both finishes.
 * The PlayStation 2 source has no such function.
 * akebono_finish case 0 reads ake_timer_tbl[0] as the
 * immediate 4, and case 3 passes ake_color[0] as the
 * immediate -1. Each Bg loop keeps the mask in a dword
 * and does not store assign1 or assign2. The
 * syungoku_finish cases share the overwrite_panel,
 * position, and Bg_Family_Set_appoint tail. The init
 * stores old_rno[1] first. The C keeps the
 * PlayStation 2 order. ake_timer_tbl is 0x2848B8 and
 * ake_color is 0x2848D4. Both match the PlayStation 2
 * values. ake_bg_off is 0x275F5C. akebono_flag is
 * 0x7BC4A9. Extra_Break is 0x7A89A0. Pause_Hit_Marks is
 * 0x7A88AC. Conclusion_Flag is 0x7A88D4.
 * Conclusion_Type is 0x7A82D0. bg_w is 0x7BC520 and
 * stage is +3. plw is 0xC7CEA0, stride 0x46C.
 * Bg_On_R stays sub_000AF4AA. Bg_Off_R stays
 * sub_000AF4C2. ake_Family_Set2 stays sub_000B37B1.
 * Bg_Family_Set_appoint stays sub_000B36C0. Sound_SE
 * stays sub_00098407. effect_G8_init stays
 * sub_000BE766. request_center_message stays
 * sub_000652DF. all_cgps_put_back stays sub_0004384A.
 * push_effect_work stays sub_0004AC6C. pull_effect_work
 * stays sub_0004A6A8. scr_calc, Scrn_Move_Set,
 * overwrite_panel, effect_20_init, and effect_L9_init
 * are named. frw is 0xC806A0 and each object is 0x700
 * bytes.
 */

#include "types.h"

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
    u8 pad_cg[0x48 - 0x44];
    s8 cgromtype;
    u8 pad_dt[0x9A - 0x49];
    s16 dir_timer;
    u8 pad_end[0x388 - 0x9C];
} WORK;

typedef struct {
    WORK wu;
} WORK_Other;

typedef struct {
    WORK wu;
    u8 tail[0x46C - 0x388];
} PLW;

typedef struct {
    u8 raw0[0xA];
    s16 position_x;
    s16 position_y;
    u8 raw1[0x90 - 0xE];
} BGW;

typedef struct {
    u8 raw0[3];
    s8 stage;
    u8 raw1[0x1C - 4];
    s16 pos_offset;
    u8 raw2[0x38 - 0x1E];
    BGW bgw[7];
} BG;

typedef u8 EffectRow[0x700];

#if defined(__i386__)
_Static_assert(__builtin_offsetof(WORK, disp_flag) == 1, "disp_flag");
_Static_assert(__builtin_offsetof(WORK, type) == 4, "type");
_Static_assert(__builtin_offsetof(WORK, work_id) == 6, "work_id");
_Static_assert(__builtin_offsetof(WORK, id) == 8, "id");
_Static_assert(__builtin_offsetof(WORK, routine_no) == 0x24, "routine_no");
_Static_assert(__builtin_offsetof(WORK, old_rno) == 0x34, "old_rno");
_Static_assert(__builtin_offsetof(WORK, old_rno[1]) == 0x36, "old_rno1");
_Static_assert(__builtin_offsetof(WORK, cgromtype) == 0x48, "cgromtype");
_Static_assert(__builtin_offsetof(WORK, dir_timer) == 0x9A, "dir_timer");
_Static_assert(sizeof(WORK) == 0x388, "WORK");
_Static_assert(sizeof(PLW) == 0x46C, "PLW");
_Static_assert(sizeof(BGW) == 0x90, "BGW");
_Static_assert(__builtin_offsetof(BG, pos_offset) == 0x1C, "pos_offset");
_Static_assert(__builtin_offsetof(BG, bgw[3].position_x) == 0x1F2, "bgw3 position_x");
_Static_assert(__builtin_offsetof(BG, bgw[3].position_y) == 0x1F4, "bgw3 position_y");
#endif

extern EffectRow frw[];
extern PLW plw[2];
extern BG bg_w;
extern const u8 ake_bg_off[];
extern s8 akebono_flag;
extern u8 Extra_Break;
extern s8 Pause_Hit_Marks;
extern u8 Conclusion_Flag;
extern s8 Conclusion_Type;

const s16 ake_timer_tbl[13] = { 4, 4, 4, 4, 4, 10, 10, 10, 10, 10, 10, 10, 20 };

const u32 ake_color[13] = { 0xFFFFFFFF, 0x10FFFFFF, 0xFFFFFFFF, 0x10FFFFFF, 0xFFFFFFFF, 0x10FFFFFF, 0x28FFFFFF,
                            0x40FFFFFF, 0x60FFFFFF, 0x88FFFFFF, 0xB0FFFFFF, 0xD8FFFFFF, 0xFFFFFFFF };

void scr_calc(u8 bgnm);
void Scrn_Move_Set(s8 bgnm, s16 x, s16 y);
void overwrite_panel(u32 color, u8 priority);
void sub_000AF4AA(s32 bits);
void sub_000AF4C2(s32 bits);
void sub_000B37B1(void);
void sub_000B36C0(s32 num_of_bg);
void sub_00098407(s16 code);
s32 sub_000BE766(void);
s32 effect_20_init(WORK_Other *oya);
s32 effect_L9_init(WORK_Other *oya, u8 ten_type);
void sub_000652DF(s16 type);
void sub_0004384A(WORK *wk);
void sub_0004AC6C(WORK *wk);
s16 sub_0004A6A8(s16 index);

void akebono_finish(WORK_Other *ewk);
void syungoku_finish(WORK_Other *ewk);

void akebono_finish(WORK_Other *ewk) {
    s16 i;
    u16 bg;
    u16 mask;
    u16 assign1;
    u16 assign2;

    for (i = 0; i < 3; i++) {
        scr_calc(i);
    }

    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0] += 1;
        ewk->wu.old_rno[1] = 0;
        ewk->wu.dir_timer = ake_timer_tbl[0];
        ewk->wu.disp_flag = 0;
        bg = ake_bg_off[bg_w.stage];
        mask = 1 & 0xFFFF;

        for (i = 0; i < 4; i++, assign1 = mask *= 2) {
            if (bg & mask) {
                sub_000AF4C2(1 << i);
            }
        }

        sub_000AF4AA(8);
        akebono_flag = 1;
        sub_00098407(117);
        Scrn_Move_Set(3, 192 - bg_w.pos_offset, 16);
        bg_w.bgw[3].position_x = 192 - bg_w.pos_offset;
        bg_w.bgw[3].position_y = 16;
        overwrite_panel(ake_color[ewk->wu.old_rno[1]], 69);
        break;

    case 1:
        ewk->wu.dir_timer -= 1;

        if ((ewk->wu.dir_timer) < 0) {
            akebono_flag = 1;
            ewk->wu.old_rno[1] += 1;

            if (ewk->wu.old_rno[1] < 4) {
                ewk->wu.dir_timer = ake_timer_tbl[ewk->wu.old_rno[1]];
            } else {
                ewk->wu.routine_no[0] += 1;
                sub_000BE766();
            }
        }

        overwrite_panel(ake_color[ewk->wu.old_rno[1]], 69);
        sub_000B37B1();
        break;

    case 2:
        ewk->wu.dir_timer -= 1;

        if ((ewk->wu.dir_timer) < 0) {
            ewk->wu.old_rno[1] += 1;
            ewk->wu.dir_timer = ake_timer_tbl[ewk->wu.old_rno[1]];

            if (ewk->wu.old_rno[1] == 12) {
                ewk->wu.routine_no[0] += 1;
                sub_000AF4C2(8);
            }
        }

        overwrite_panel(ake_color[ewk->wu.old_rno[1]], 69);
        sub_000B37B1();
        break;

    case 3:
        ewk->wu.dir_timer -= 1;

        if (ewk->wu.dir_timer == 0) {
            bg = ake_bg_off[bg_w.stage];
            mask = 1;

            for (i = 0; i < 4; i++, assign2 = mask *= 2) {
                if (bg & mask) {
                    sub_000AF4AA(1 << i);
                }
            }
        }

        if (ewk->wu.dir_timer < 0) {
            ewk->wu.routine_no[0] += 1;
            akebono_flag = 0;
            break;
        }

        overwrite_panel(ake_color[0], 69);
        break;

    case 4:
        sub_0004384A(&ewk->wu);
        sub_0004AC6C(&ewk->wu);
        break;
    }

}

void syungoku_finish(WORK_Other *ewk) {
    s16 i;
    u16 bg;
    u16 mask;
    u16 assign1;
    u16 assign2;

    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0] += 1;
        akebono_flag = 1;
        Extra_Break = 1;
        sub_00098407(126);
        plw[0].wu.disp_flag = 0;
        plw[1].wu.disp_flag = 0;
        Pause_Hit_Marks = 1;
        bg = ake_bg_off[bg_w.stage];
        mask = 1 & 0xFFFF;

        for (i = 0; i < 4; i++, assign1 = mask *= 2) {
            if (bg & mask) {
                sub_000AF4C2(1 << i);
            }
        }

        overwrite_panel(0xFF000000, 70);
        bg_w.bgw[3].position_x = 256 - bg_w.pos_offset;
        bg_w.bgw[3].position_y = 0;
        ewk->wu.dir_timer = 2;
        sub_000B36C0(3);
        break;

    case 1:
        ewk->wu.dir_timer -= 1;

        if (ewk->wu.dir_timer <= 0) {
            ewk->wu.routine_no[0] += 1;
            ewk->wu.old_rno[0] = 0;
            effect_20_init(ewk);
            effect_L9_init(ewk, 0);
            effect_L9_init(ewk, 1);
        }

        overwrite_panel(0xFF000000, 70);
        bg_w.bgw[3].position_x = 768 - bg_w.pos_offset;
        bg_w.bgw[3].position_y = 0;
        sub_000B36C0(3);
        break;

    case 2:
        if (ewk->wu.old_rno[0]) {
            ewk->wu.routine_no[0] += 1;
            akebono_flag = 0;
            plw[0].wu.disp_flag = 1;
            plw[1].wu.disp_flag = 1;
            Pause_Hit_Marks = 0;
            bg = ake_bg_off[bg_w.stage];
            mask = 1 & 0xFFFF;

            for (i = 0; i < 4; i++, assign2 = mask *= 2) {
                if (bg & mask) {
                    sub_000AF4AA(1 << i);
                }
            }
        }

        overwrite_panel(0xFF000000, 70);
        bg_w.bgw[3].position_x = 768 - bg_w.pos_offset;
        bg_w.bgw[3].position_y = 0;
        sub_000B36C0(3);
        break;

    case 3:
        ewk->wu.routine_no[0] += 1;
        Conclusion_Flag = 1;
        Conclusion_Type = 0;
        sub_000652DF(0);
        bg_w.bgw[3].position_x = 256 - bg_w.pos_offset;
        bg_w.bgw[3].position_y = 0;
        sub_000B36C0(3);
        break;

    default:
        akebono_flag = 0;
        sub_0004384A(&ewk->wu);
        sub_0004AC6C(&ewk->wu);
        break;
    }

}

s32 effect_D3_init(u8 ake_type) {
    WORK_Other *ewk;
    s16 ix;

    if ((ix = sub_0004A6A8(3)) == -1) {
        return -1;
    }

    ewk = (WORK_Other *)frw[ix];
    ewk->wu.id = 133;
    ewk->wu.be_flag = 1;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.old_rno[1] = 0;
    ewk->wu.type = ake_type;
    return 0;
}

void effect_D3_move(WORK_Other *ewk) {
    if (ewk->wu.type == 0) {
        akebono_finish(ewk);
    } else {
        syungoku_finish(ewk);
    }
}
