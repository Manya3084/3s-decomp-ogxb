/* EFFB5.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * current_name_move 0x441D9 size 0xB1.
 * effect_B5_move 0x4428A size 0x1D7.
 * Flash_Violent is folded into 0x9B78F.
 * all_cgps_put_back is folded into 0x4384A.
 * disp_pos_trans_entry is folded into 0xEF0C0.
 */

#include "structs.h"

s32 sub_0009B78F(WORK_Other* , s32 );
void sub_0004384A(WORK* wk);
void sub_000EF0C0(WORK_Other* ewk);
void set_char_move_init2(WORK* wk, s16 koc, s16 index, s16 ip, s16 scf);
void current_name_move(WORK_Other* ewk, NAME_WK* np);
void push_effect_work(WORK* wkhd);



void effect_B5_move(WORK_Other* ewk) {
    NAME_WK* np = (NAME_WK*)ewk->my_master;

    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.hit_stop = 0;
        ewk->wu.old_rno[3] = 0;
        ewk->wu.old_rno[1] = 47;
        ewk->wu.disp_flag = 1;
        set_char_move_init2(&ewk->wu, 0, 6, np->code[ewk->wu.old_rno[2]] + 1, 0);
        /* fallthrough */

    case 1:
    case_1:
        if (np->end_flag[ewk->wu.type]) {
            ewk->wu.disp_flag = 1;
            set_char_move_init2(&ewk->wu, 0, 6, np->code[ewk->wu.old_rno[2]] + 1, 0);
            ewk->wu.routine_no[0]++;
        } else {
            current_name_move(ewk, (NAME_WK*)np);
        }

        break;

    case 2:
        if (np->r_no_0 == 7) {
            ewk->wu.routine_no[0] = 3;
            ewk->wu.routine_no[2] = 1;
            ewk->wu.routine_no[3] = 3;
            ewk->wu.routine_no[4] = 0;
            ewk->wu.vitality = 0;
            ewk->wu.vital_new = 66;
            ewk->wu.vital_old = 67;
        }

        if (np->end_flag[ewk->wu.type] == 0) {
            ewk->wu.old_rno[0] = 0;
            ewk->wu.old_rno[4] = 0;
            ewk->wu.routine_no[0] = 1;
            set_char_move_init2(&ewk->wu, 0, 6, np->code[ewk->wu.old_rno[2]] + 1, 0);
            ewk->wu.old_rno[3] = np->code[np->index];
            goto case_1;
        }

        if (ewk->wu.old_rno[3] != np->code[ewk->wu.type]) {
            ewk->wu.old_rno[0] = 0;
            ewk->wu.old_rno[4] = 1;
            set_char_move_init2(&ewk->wu, 0, 6, np->code[ewk->wu.old_rno[2]] + 1, 0);
            ewk->wu.old_rno[3] = np->code[ewk->wu.type];
        }

        break;

    case 3:
        if (sub_0009B78F(ewk, 9)) {
            ewk->wu.routine_no[0]++;
        }

        if (ewk->wu.vitality) {
            set_char_move_init2(&ewk->wu, 0, 6, np->code[ewk->wu.old_rno[2]] + 1, 0);
        }

        break;

    case 4:
        break;

    default:
        sub_0004384A(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }

    if (ewk->wu.old_rno[3] != np->code[ewk->wu.type]) {
        ewk->wu.old_rno[4] = 0;
        ewk->wu.old_rno[0] = 0;
        set_char_move_init2(&ewk->wu, 0, 6, np->code[ewk->wu.type] + 1, 0);
        ewk->wu.old_rno[3] = np->code[ewk->wu.type];
    }

    sub_000EF0C0(ewk);
}

void current_name_move(WORK_Other* ewk, NAME_WK* np) {
    if (np->index != ewk->wu.old_rno[2]) {
        return;
    }

    switch (ewk->wu.hit_stop) {
    case 0:
        ewk->wu.hit_stop++;
        ewk->wu.old_rno[4] = 0;
        ewk->wu.old_rno[0] = 0;
        set_char_move_init2(&ewk->wu, 0, 6, np->code[ewk->wu.old_rno[2]] + 1, 0);
        ewk->wu.old_rno[3] = np->code[np->index];
        break;

    case 1:
        if (np->r_no_0 > 5) {
            ewk->wu.routine_no[0]++;
            break;
        }

        ewk->wu.old_rno[0]++;

        if (ewk->wu.old_rno[0] <= 16) {
            break;
        }

        ewk->wu.old_rno[0] = 0;
        ewk->wu.old_rno[4]++;

        if (ewk->wu.old_rno[4] > 2) {
            ewk->wu.old_rno[4] = 0;
        }

        if (ewk->wu.old_rno[4] != 2) {
            set_char_move_init2(&ewk->wu, 0, 6, np->code[np->index] + 1, 0);
        } else {
            set_char_move_init2(&ewk->wu, 0, 6, 48, 0);
        }

        break;
    }
}
