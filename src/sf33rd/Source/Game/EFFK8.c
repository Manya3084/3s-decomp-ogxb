/* Effect K8, retail sf33rd.xbe.
 * effect_K8_move is 0x50D7A size 0x125.
 * effect_K8_init is 0x50E9F size 0xA6.
 *
 * In effect_K8_move the dead_f path of case 1 falls into the case 2 code
 * for its disp_flag and routine_no stores. When now_koc or char_index
 * changes, routine_no[0] is set to 2 before the Bg_Y_Sitei call.
 * Case 0 stores position_z before my_priority.
 * effect_K8_init stores type and my_master first. The C keeps the PS2
 * order.
 * _plef_char_table is 0x308B40. seraph_flag is 0x7BC4F4.
 * base_y_pos is 0x7BC516. Game_pause is 0x7A89B0. EXE_flag is 0xC7C834.
 * frw is 0xC806A0, 0x700 bytes per object.
 * dir_old is +0x96. my_mr_flag is +0x24E. my_mr.size is +0x250.
 * set_char_move_init is 0x200A9. char_move is 0x2008E.
 * push_color_trans_req is 0xB61A0.
 * Bg_Y_Sitei is 0xB32A5. Bg_Disp_Switch is 0xAF601.
 * push_effect_work is 0x4AC6C. pull_effect_work is 0x4A6A8.
 * sort_push_request is 0x9DF9A.
 */

#include "types.h"
#include "structs.h"

typedef struct {
    s16 x;
    s16 y;
} MRSize;



typedef uintptr_t EffectRow[448]; /* 0x700 bytes on the 32-bit retail build */

#if defined(__i386__)
#endif

extern u32 _plef_char_table[];
extern u8 seraph_flag;
extern s16 base_y_pos;
extern u8 Game_pause;
extern u16 EXE_flag;
extern EffectRow frw[];

void push_effect_work(WORK *wk);
s16 pull_effect_work(s16 index);
void sort_push_request(WORK *wk);
void Bg_Y_Sitei(u8 on_off, s16 pos);
void Bg_Disp_Switch(u8 on_off);
void set_char_move_init(WORK *wk, s16 koc, s32 index);
void char_move(WORK *wk);
void push_color_trans_req(s32 from_col, s32 to_col);

void effect_K8_move(WORK_Other *ewk) {
    WORK *mwk = (WORK *)ewk->my_master;

    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        seraph_flag = 1;
        Bg_Disp_Switch(1);
        ewk->wu.my_priority = ewk->wu.position_z = 67;
        ewk->wu.my_mr_flag = 1;
        ewk->wu.my_mr.size.x = 127;
        ewk->wu.my_mr.size.y = 127;
        set_char_move_init(&ewk->wu, 0, 0x8F);
        break;

    case 1:
        if (ewk->wu.dead_f != 0) {
            Bg_Y_Sitei(0, 0);
            Bg_Disp_Switch(0);
            seraph_flag = 0;
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0] = 3;
            break;
        }

        if (EXE_flag == 0 && Game_pause == 0) {
            char_move(&ewk->wu);

            if (ewk->wu.dir_old != mwk->now_koc || ewk->wu.dir_step != mwk->char_index) {
                ewk->wu.routine_no[0] = 2;
                Bg_Y_Sitei(0, 0);
                seraph_flag = 0;
                Bg_Disp_Switch(0);
            }
        }

        push_color_trans_req(ewk->wu.cg_type + 0x62, ewk->wu.my_col_code);
        sort_push_request(&ewk->wu);
        break;

    case 2:
        ewk->wu.disp_flag = 0;
        ewk->wu.routine_no[0] = 3;
        break;

    default:
        push_effect_work(&ewk->wu);
        break;
    }
}

s32 effect_K8_init(WORK *wk, u8 data) {
    WORK_Other *ewk;
    s16 ix;

    if ((ix = pull_effect_work(5)) == -1) {
        return -1;
    }

    ewk = (WORK_Other *)frw[ix];
    ewk->my_master = (u32 *)wk;
    ewk->wu.be_flag = 1;
    ewk->wu.id = 208;
    ewk->wu.type = data;
    ewk->wu.my_mts = 6;
    ewk->wu.work_id = 16;
    ewk->wu.my_family = 8;
    ewk->wu.cgromtype = 1;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_col_code = 2;
    ewk->wu.position_x = -8;
    ewk->wu.position_y = 240 - base_y_pos;
    ewk->wu.dir_old = wk->now_koc;
    ewk->wu.dir_step = wk->char_index;
    *ewk->wu.char_table = _plef_char_table;
    return 0;
}

/* Xbox-only functions of this object (analysis-ps2map/xbgen.py checked each). */
void xb_effect_K8_draw(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 1:
        if (ewk->wu.dead_f == 0) {
            push_color_trans_req(ewk->wu.cg_type + 0x62, ewk->wu.my_col_code);
            sort_push_request(&ewk->wu);
        }

        break;
    }
}
