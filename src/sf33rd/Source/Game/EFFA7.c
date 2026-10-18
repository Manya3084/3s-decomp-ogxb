/* EFFA7.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * effect_A7_move 0x43446 size 0x321.
 * effect_A7_init 0x43767 size 0xE3.
 * Data: _ef01_char_table is 0x3064A0, the char table effect_A7_move stores.
 * Globals: hit_mark_dir_table 0x249C80, hmdt 0x249CA0, hcct 0x24A378, gqdt
 * 0x24A388, explem 0x24A3D4, explem2 0x24A3F0, sound_effect_request 0x266008,
 * Suicide 0x7A8268, Last_Called_SE 0x7A8796, Pause_Hit_Marks 0x7A88AC,
 * Game_pause 0x7A89B0, bg_w 0x7BC520, EXE_flag 0xC7C834, frw 0xC806A0.
 */

#include "structs.h"

#define EFFECT_MAX 128

typedef struct {
    
    u16 chix; 
    s16 hx;   
    s16 hy;   
} EXPLEM;
typedef struct {
    
    u16 se;    
    u8 hits;   
    u8 deff;   
    u8 kezu;   
    u8 fsin;   
    u8 status; 
    u8 quake;  
    u8 dir;    
    u8 col;    
    u8 myhix;  
    u8 emhix;  
} HMDT;
extern u32 _ef01_char_table[];
extern const HMDT hmdt[];
extern void (*sound_effect_request[])();
extern s16 Last_Called_SE;
extern BG bg_w;
extern const s16 gqdt[][2];
void pp_screen_quake(s16 ix);
void push_effect_work(WORK* wkhd);
extern const s16 hcct[];
extern const EXPLEM explem2[][20];
extern const EXPLEM explem[];
s32 random_16();
void set_char_move_init(WORK* wk, s16 koc, s16 index);
extern const s16 hit_mark_dir_table[16];
extern u8 Pause_Hit_Marks;
s32 sort_push_request8(WORK* wk);
extern s8 Suicide[8];
extern s16 EXE_flag;
extern u8 Game_pause;
void char_move(WORK* wk);
s16 pull_effect_work(s16 index);
extern uintptr_t frw[EFFECT_MAX][448];



void effect_A7_move(WORK_Other* ewk) {
    const HMDT* tad;
    const EXPLEM* edt;

    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        *ewk->wu.char_table = _ef01_char_table;
        tad = &hmdt[ewk->wu.kohm];

        if (tad->hits == 0) {
            if (tad->se) {
                sound_effect_request[tad->se](ewk, tad->se);
                Last_Called_SE = tad->se;
            } else {
                Last_Called_SE = 0;
            }

            if (tad->quake != 0) {
                bg_w.quake_y_index = gqdt[tad->quake][1];
                pp_screen_quake(bg_w.quake_y_index);
            }

            push_effect_work(&ewk->wu);
            break;
        }

        if (tad->status & 8) {
            ewk->wu.disp_flag = 2;
        } else {
            ewk->wu.disp_flag = 1;
        }

        if (tad->status & 0x40) {
            if (((WORK*)ewk->wu.target_adrs)->work_id == 1) {
                ewk->wu.dir_timer = ((PLW*)ewk->wu.target_adrs)->player_number;
            } else {
                ewk->wu.dir_timer = ((WORK_Other*)ewk->wu.target_adrs)->master_player;
            }
        }

        if (tad->col) {
            ewk->wu.my_col_code = hcct[tad->col];
        } else if (tad->status & 0x80) {
            ewk->wu.my_col_code = ((WORK*)ewk->wu.target_adrs)->my_col_code + 1;
        }

        if (tad->se) {
            sound_effect_request[tad->se](ewk, tad->se);
            Last_Called_SE = tad->se;
        } else {
            Last_Called_SE = 0;
        }

        if (tad->status & 0x10) {
            if (tad->status & 0x20) {
                edt = &explem2[tad->emhix][ewk->wu.dir_timer];
            } else {
                edt = &explem[tad->myhix];
            }

            if (ewk->wu.rl_flag) {
                ewk->wu.xyz[0].disp.pos -= *(s16*)&edt->hx;
            } else {
                ewk->wu.xyz[0].disp.pos += *(s16*)&edt->hx;
            }

            ewk->wu.xyz[1].disp.pos += *(s16*)&edt->hy;
        }

        if (tad->status & 2) {
            ewk->wu.xyz[0].disp.pos += random_16() - 7;
            ewk->wu.xyz[1].disp.pos += (random_16() & 7) - 3;
        }

        ewk->wu.scr_mv_x = gqdt[tad->quake][0];
        ewk->wu.scr_mv_y = gqdt[tad->quake][1];
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos;
        ewk->wu.position_z = ewk->wu.xyz[2].disp.pos;

        if (tad->status & 0x10) {
            set_char_move_init(&ewk->wu, 0, edt->chix);
        } else {
            ewk->wu.dir_old = 0;

            if (tad->dir) {
                ewk->wu.dir_old = hit_mark_dir_table[ewk->wu.direction];

                if (ewk->wu.dir_old < 0) {
                    ewk->wu.rl_flag = 1;
                    ewk->wu.dir_old = -ewk->wu.dir_old;
                }
            }

            set_char_move_init(&ewk->wu, 0, tad->hits + ewk->wu.dir_old);
        }

        if (ewk->wu.char_index == 75) {
            ewk->wu.my_mr_flag = 1;
            ewk->wu.my_mr.size.x = 127;
            ewk->wu.my_mr.size.y = 63;
            ewk->wu.my_col_code |= (ewk->master_id == 1) * 16;
        }

        if (!Pause_Hit_Marks) {
            sort_push_request8(&ewk->wu);
        }

        break;

    case 1:
        if (ewk->wu.dead_f == 1 || Suicide[6] != 0) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0]++;
            break;
        }

        if (Pause_Hit_Marks) {
            break;
        }

        if (EXE_flag == 0 && Game_pause == 0) {
            char_move(&ewk->wu);

            if (ewk->wu.cg_type == 0xFF) {
                ewk->wu.disp_flag = 0;
                ewk->wu.routine_no[0]++;
                break;
            }

            if (ewk->wu.scr_mv_x && --ewk->wu.scr_mv_x == 0) {
                bg_w.quake_y_index = ewk->wu.scr_mv_y;
                pp_screen_quake(bg_w.quake_y_index);
            }
        }

        sort_push_request8(&ewk->wu);
        break;

    case 2:
        ewk->wu.routine_no[0] = 3;
        break;

    default:
        push_effect_work(&ewk->wu);
        break;
    }
}

s32 effect_A7_init(PLW* wk) {
    WORK_Other* ewk;
    PLW* twk;
    s16 ix;

    if (wk->wu.work_id != 1) {
        return -1;
    }

    if ((ix = pull_effect_work(2)) == -1) {
        return -1;
    }

    ewk = (WORK_Other*)frw[ix];
    twk = (PLW*)wk->wu.target_adrs;
    ewk->wu.be_flag = 1;
    ewk->wu.id = 107;
    ewk->wu.work_id = 64;
    ewk->wu.rl_flag = wk->wu.rl_flag;
    ewk->wu.kohm = wk->wu.hm_dm_side;
    ewk->wu.cgromtype = 1;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_family = 2;
    ewk->wu.my_mr_flag = 0;
    ewk->wu.xyz[0].disp.pos = ewk->wu.position_x = wk->wu.xyz[0].disp.pos;
    ewk->wu.xyz[1].disp.pos = ewk->wu.position_y = wk->wu.xyz[1].disp.pos;
    ewk->wu.xyz[2].disp.pos = 26;
    ewk->my_master = (u32*)wk->wu.target_adrs;
    ewk->master_id = twk->wu.id;
    ewk->master_work_id = twk->wu.work_id;
    ewk->wu.target_adrs = (u32*)wk;
    ewk->wu.my_col_code = twk->wu.my_col_code + 1;
    ewk->master_player = ewk->wu.dir_timer = twk->player_number;
    ewk->wu.blink_timing = ewk->master_id;
    return 0;
}
