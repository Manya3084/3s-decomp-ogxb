/* Effect L2, retail sf33rd.xbe.
 * effl2_dir_check is 0xB8CF9 size 0x51 and is interior.
 * effect_L2_init is 0xB8D4A size 0x133 and is interior.
 * effect_L2_move is 0xB8E7D size 0xF3 and is interior.
 * The failure paths jump to the shared epilogue.
 * 0xB8CD3 stays unnamed. 0xB8F70 stays unnamed.
 *
 * effl2_dir_tbl is 0x28469C and matches the 32 bytes.
 * The rows were not pasted. Case 0 stores routine_no[0]
 * and disp_flag between the push and dir_check. Case 1
 * omits the second Conclusion_Flag test. position_y is
 * stored between the push and sort_push_request. The
 * init stores my_col_code among the kage stores and
 * xyz[0].cal after direction. The C keeps the
 * PlayStation 2 order. My_char is 0x7A8114. plw is
 * 0xC7CEA0, stride 0x46C. Allow_a_battle_f is
 * 0x7A82B8. Conclusion_Flag is 0x7A88D4. C_No is
 * 0x7A86C4. Complete_Victory is 0x7A8A04. Exec_Wipe
 * is 0x7A82F9. Winner_id is 0x7A8472. EXE_flag is
 * 0xC7C834. Game_pause is 0x7A89B0. The character
 * table immediate is 0x2F5030. Those bytes were not
 * compared. set_char_move_init is 0x200A9.
 * set_char_move_init2 is 0x201B9.
 * sort_push_request is 0x9DF9A.
 * all_cgps_put_back stays sub_0004384A.
 * push_effect_work is 0x4AC6C.
 * pull_effect_work is 0x4A6A8.
 * get_my_trans_mode is named. frw is 0xC806A0 and
 * each object is 0x700 bytes. 0xB6890 stays unnamed.
 * 0xB61A0 is push_color_trans_req. 0xB7EC3 stays unnamed.
 * 0xB82C0 stays unnamed. 0xB888D stays unnamed.
 */

#include "types.h"
#include "structs.h"

/* Retail addresses the code used as numbers. */
extern u32 _direct_03_char_table[];


typedef uintptr_t EffectRow[448]; /* 0x700 bytes on the 32-bit retail build */

#if defined(__i386__)
_Static_assert(__builtin_offsetof(WORK, disp_flag) == 1, "disp_flag");
_Static_assert(__builtin_offsetof(WORK, work_id) == 6, "work_id");
_Static_assert(__builtin_offsetof(WORK, id) == 8, "id");
_Static_assert(__builtin_offsetof(WORK, routine_no) == 0x24, "routine_no");
_Static_assert(__builtin_offsetof(WORK, old_rno) == 0x34, "old_rno");
_Static_assert(__builtin_offsetof(WORK, cgromtype) == 0x48, "cgromtype");
_Static_assert(__builtin_offsetof(WORK, kage_flag) == 0x49, "kage_flag");
_Static_assert(__builtin_offsetof(WORK, kage_hx) == 0x4A, "kage_hx");
_Static_assert(__builtin_offsetof(WORK, kage_hy) == 0x4C, "kage_hy");
_Static_assert(__builtin_offsetof(WORK, kage_prio) == 0x4E, "kage_prio");
_Static_assert(__builtin_offsetof(WORK, kage_char) == 0x52, "kage_char");
_Static_assert(__builtin_offsetof(WORK, position_x) == 0x54, "position_x");
_Static_assert(__builtin_offsetof(WORK, position_y) == 0x56, "position_y");
_Static_assert(__builtin_offsetof(WORK, position_z) == 0x58, "position_z");
_Static_assert(__builtin_offsetof(WORK, xyz[0].cal) == 0x64, "xyz0cal");
_Static_assert(__builtin_offsetof(WORK, xyz[0].disp.pos) == 0x66, "xyz0");
_Static_assert(__builtin_offsetof(WORK, xyz[1].cal) == 0x68, "xyz1cal");
_Static_assert(__builtin_offsetof(WORK, xyz[1].disp.pos) == 0x6A, "xyz1");
_Static_assert(__builtin_offsetof(WORK, direction) == 0x94, "direction");
_Static_assert(__builtin_offsetof(WORK, dir_old) == 0x96, "dir_old");
_Static_assert(__builtin_offsetof(WORK, char_table) == 0x1AC, "char_table");
_Static_assert(__builtin_offsetof(WORK, my_col_mode) == 0x23C, "my_col_mode");
_Static_assert(__builtin_offsetof(WORK, my_col_code) == 0x23E, "my_col_code");
_Static_assert(__builtin_offsetof(WORK, my_priority) == 0x240, "my_priority");
_Static_assert(__builtin_offsetof(WORK, my_family) == 0x242, "my_family");
_Static_assert(__builtin_offsetof(WORK, my_mts) == 0x24C, "my_mts");
_Static_assert(__builtin_offsetof(WORK, my_trans_mode) == 0x254, "my_trans_mode");
_Static_assert(sizeof(WORK) == 0x388, "WORK");
_Static_assert(__builtin_offsetof(WORK_Other, my_master) == 0x388, "my_master");
_Static_assert(__builtin_offsetof(WORK_Other, master_id) == 0x38E, "master_id");
_Static_assert(sizeof(PLW) == 0x46C, "PLW");
_Static_assert(__builtin_offsetof(PLW, wu.xyz[0].disp.pos) == 0x66, "plw xyz");
#endif

extern EffectRow frw[];
extern u8 My_char[2];
extern PLW plw[2];
/* Tables pasted from the PS2 file; analysis-ps2map/portdata.py found
   each equal to retail. */
const s8 effl2_dir_tbl[2][16] = { { 0, 0, 0, 1, 2, 2, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4 },
                                  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 3 } };

extern u8 Allow_a_battle_f;
extern u8 Conclusion_Flag;
extern u8 C_No[4];
extern s8 Complete_Victory;
extern s8 Exec_Wipe;
extern s8 Winner_id;
extern s16 EXE_flag;
extern u8 Game_pause;

void effl2_dir_check(WORK_Other *ewk);
void set_char_move_init(WORK *wk, s16 koc, s16 index);
void set_char_move_init2(WORK *wk, s16 koc, s16 index, s16 ip, s16 scf);
void sort_push_request(WORK *wk);
void sub_0004384A(WORK *wk);
void push_effect_work(WORK *wk);
s16 pull_effect_work(s16 index);
s16 get_my_trans_mode(s16 curr);

void effect_L2_move(WORK_Other *ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        effl2_dir_check(ewk);
        set_char_move_init2(&ewk->wu, 0, 0, 1, 0);
        break;

    case 1:
        if (Allow_a_battle_f == 0 && Conclusion_Flag == 1 && C_No[0] >= 2) {
            if (Complete_Victory != 0) {
                ewk->wu.routine_no[0]++;
                ewk->wu.old_rno[0] = 0;

                if (Winner_id != ewk->master_id) {
                    set_char_move_init(&ewk->wu, 0, 2);
                } else {
                    set_char_move_init(&ewk->wu, 0, 1);
                }
            }
        } else if (EXE_flag == 0 && Game_pause == 0) {
            effl2_dir_check(ewk);
        }

        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos;
        sort_push_request(&ewk->wu);
        break;

    case 2:
        if (Exec_Wipe != 0) {
            ewk->wu.old_rno[0] = 1;
        }

        if (ewk->wu.old_rno[0] != 0 && Exec_Wipe == 0) {
            ewk->wu.routine_no[0] = 0;
        }

        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos;
        sort_push_request(&ewk->wu);
        break;

    default:
        sub_0004384A(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}

void effl2_dir_check(WORK_Other *ewk) {
    s16 work;

    work = plw[ewk->master_id].wu.xyz[0].disp.pos;
    work >>= 6;
    work &= 15;

    if (effl2_dir_tbl[ewk->master_id][work] != ewk->wu.direction) {
        ewk->wu.direction = effl2_dir_tbl[ewk->master_id][work];
        set_char_move_init2(&ewk->wu, 0, 0, ewk->wu.direction + 1, 0);
    }
}

s32 effect_L2_init(void) {
    WORK_Other *ewk;
    s16 ix;
    s16 oya_id;

    if (My_char[0] == 10 || My_char[1] == 10) {
        return -1;
    }

    if (My_char[0] == 3 && My_char[1] == 3) {
        return -1;
    }

    if (My_char[0] == 3) {
        oya_id = 0;
    } else if (My_char[1] == 3) {
        oya_id = 1;
    } else {
        return -1;
    }

    if ((ix = pull_effect_work(3)) == -1) {
        return -1;
    }

    ewk = (WORK_Other *)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 212;
    ewk->wu.work_id = 16;
    ewk->master_id = oya_id;
    ewk->wu.cgromtype = 1;
    ewk->wu.disp_flag = 1;
    ewk->wu.my_family = 2;
    ewk->my_master = (u32 *)&plw[oya_id];
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_mts = 7;
    ewk->wu.my_trans_mode = get_my_trans_mode(ewk->wu.my_mts);

    if (oya_id != 0) {
        ewk->wu.my_col_code = 0x2016;
    } else {
        ewk->wu.my_col_code = 0x2006;
    }

    ewk->wu.my_priority = ewk->wu.position_z = 71;

    if (oya_id != 0) {
        ewk->wu.xyz[0].cal = 0x3000000;
    } else {
        ewk->wu.xyz[0].cal = 0xF00000;
    }

    ewk->wu.xyz[1].cal = 0xA0000;
    ewk->wu.char_table[0] = _direct_03_char_table;
    ewk->wu.kage_flag = 1;
    ewk->wu.kage_hx = 0;
    ewk->wu.kage_hy = 11;
    ewk->wu.kage_char = 10;
    ewk->wu.kage_prio = ewk->wu.position_z + 1;
    ewk->wu.dir_old = 0;
    ewk->wu.direction = 0;
    return 0;
}
