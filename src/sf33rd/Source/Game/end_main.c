/* end_main.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * Ending_init 0xC72EA size 0x4E.
 * fadeout_to_staff_roll 0xC7338 size 0x17. Read against the x86: 0xFF is the
 * byte store of Forbid_Break = -1. The C is the PS2 C.
 * common_end_init00 0xC734F size 0xEA. Read against the x86: the offsets are
 * the bgw fields cleared in the 0x90-byte record loop. The C is the PS2 C.
 * end_fam_set 0xC7439 size 0x2D.
 * end_fam_set2 0xC7466 size 0x45.
 * end_bg_pos_hosei2 0xC74DA size 0x45.
 * end_scn_pos_set2 0xC751F size 0x67.
 * end_reset_etc 0xC7586 size 0x4D.
 * end_X_com01 0xC75D3 size 0x26.
 * end_fade_bgm 0xC75F9 size 0x1A.
 * end_fade_complete 0xC7613 size 0x19. Read against the x86: 0xFF is the byte
 * store of Forbid_Break = -1. The C is the PS2 C.
 * Cut_Cut_Cut_t 0xC762C size 0x41.
 * end_main_move 0xC766D size 0x16.
 * common_end_init01 0xC7683 size 0xC0.
 * normal_ending 0xC7743 size 0x2F1. Read against the x86: 0x32 is the
 * per-player name work size. The C is the PS2 C.
 * Ending_main 0xC7A34 size 0x17.
 * Not located in sf33rd.xbe; their PS2 C is kept under #if 0:
 * end_bg_pos_hosei.
 * Bg_Off_R is folded into 0xAF4C2.
 * Bg_Off_W is folded into 0xAF4C2.
 * Family_Set_W is folded into 0xAF47B.
 * setup_pos_remake_key is folded into 0x4384A.
 * Data: end_main_jp is 0x332F30, 20 entries compared.
 * Unnamed data used (not a difference): Ending_main: 0x7aabfc;
 * common_end_init00: 0x28691c,0x2868c8,0x2868dc; normal_ending: 0x7a9e38.
 * Globals: end_main_jp 0x332F30, Cover_Timer 0x7A81F4, LOSER 0x7A82FD,
 * Forbid_Break 0x7A8804, Game_timer 0x7A8830, WINNER 0x7A89BD, end_w 0x7AABF0,
 * end_no_cut 0x7AABFE, staff_r_no 0x7AAC02, end_etc_flag 0x7AAC03,
 * end_fade_flag 0x7AAC08, bgw_ptr 0x7BC510, base_y_pos 0x7BC516, bg_w
 * 0x7BC520, bg_disp_off 0x7BC982, Screen_Switch 0x7BC988, Screen_Switch_Buffer
 * 0x7BC98A, p1sw_1 0x7BD3CA, p2sw_1 0x7C5568, p1sw_0 0x7C557C, p2sw_0
 * 0x7C5B90.
 */

#include "structs.h"

void sub_000AF4C2();
void sub_000AF47B(s8 fmnm, s16 x, s16 y);
void sub_0004384A(s16 );
void end_00000(s16 pl_num);
void end_01000(s16 pl_num);
void end_02000(s16 pl_num);
void end_03000(s16 pl_num);
void end_04000(s16 pl_num);
void end_05000(s16 pl_num);
void end_06000(s16 pl_num);
void end_07000(s16 pl_num);
void end_08000(s16 pl_num);
void end_09000(s16 pl_num);
void end_10000(s16 pl_num);
void end_11000(s16 pl_num);
void end_12000(s16 pl_num);
void end_13000(s16 pl_num);
void end_14000(s16 pl_num);
void end_16000(s16 pl_num);
void end_17000(s16 pl_num);
void end_18000(s16 pl_num);
void end_19000(s16 pl_num);
void end_20000(s16 pl_num);
extern END_W end_w;
extern u16 Game_timer;
extern s8 ending_all_end;
extern s16 end_fade_timer;
extern s8 end_fade_flag;
extern s8 end_no_cut;
extern s8 staff_r_no;
extern s8 end_staff_flag;
void normal_ending(s16 pl_num);
s32 Switch_Screen(u8 Wipe_Type);
void System_all_clear_Level_B();
extern s8 Cover_Timer;
void Switch_Screen_Init(s32 );
s32 Switch_Screen_Revival(u8 Wipe_Type);
extern s8 Ignore_Entry[2];
extern s8 LOSER;
extern s8 Forbid_Break;
void end_main_move(s16 pl_num);
void effect_work_kill(s16 index, s16 kill_id);
void SsBgmFadeOut(u16 time);
s32 Cut_Cut_Cut_t();
void fadeout_to_staff_roll();
s16 end_fade_complete();
void overwrite_panel(u32 color, u8 priority);
void Zoomf_Init();
extern BG bg_w;
void end_scn_pos_set2();
void end_bg_pos_hosei2();
void end_fam_set2();
s32 Request_Fade(u16 fade_code);
void Bg_Close();
void scr_calc(u8 bgnm);
s32 staff_credits(u32 );
extern NAME_WK name_wk[2];
extern s8 WINNER;
extern s8 end_name_cut[2];
s32 bgm_play_status();
void end_fade_bgm();
void Family_Init();
void Scrn_Pos_Init();
extern const u8 ending_opaque[];
extern u16 Screen_Switch;
extern u16 Screen_Switch_Buffer;
extern u8 bg_disp_off;
extern const u8 end_use_scr[];
extern const u8 end_use_real_scr[];
void Bg_Texture_Load_Ending(s16 type);
void ending_obj_load();
extern s16 base_y_pos;
extern s8 end_etc_flag;
void end_reset_etc();
void end_fam_set(s16 i);
void Scrn_Move_Set(s8 bgnm, s16 x, s16 y);
s32 effect_E9_init();
void effect_F9_init(s16 END_PL_NO);
extern BGW* bgw_ptr;
s32 Check_Fade_Complete();
extern u16 p2sw_0;
extern u16 p2sw_1;
extern u16 p1sw_0;
extern u16 p1sw_1;

void (*end_main_jp[20])(s16) = { end_00000, end_01000, end_02000, end_03000, end_04000, end_05000, end_06000,
                                 end_07000, end_08000, end_09000, end_10000, end_11000, end_12000, end_13000,
                                 end_14000, end_16000, end_17000, end_18000, end_19000, end_20000 };

void Ending_init() {
    end_w.r_no_0 = 0;
    end_w.r_no_1 = 0;
    end_w.r_no_2 = 0;
    end_w.type = 0;
    end_w.end_flag = 0;
    Game_timer = 0;
    ending_all_end = 0;
    end_fade_timer = 0;
    end_fade_flag = 0;
    end_no_cut = 0;
    staff_r_no = 0;
    end_staff_flag = 0;
    sub_0004384A(6);
}

s8 Ending_main(s16 pl_num) {
    Game_timer++;
    normal_ending(pl_num);
    return ending_all_end;
}

void normal_ending(s16 pl_num) {
    switch (end_w.r_no_0) {
    case 0:
        end_w.r_no_0++;
        Switch_Screen(1);
        sub_000AF4C2(7);
        System_all_clear_Level_B();
        Cover_Timer = 29;
        end_main_jp[pl_num](pl_num);
        break;

    case 1:
        Switch_Screen(1);

        if (!(Cover_Timer -= 1)) {
            end_w.r_no_0++;
            Switch_Screen_Init(1);
            end_main_jp[pl_num](pl_num);
        }

        break;

    case 2:
        if (Switch_Screen_Revival(1)) {
            end_w.r_no_0++;
            Ignore_Entry[LOSER] = 0;
            Forbid_Break = -1;
        }

        break;

    case 3:
        end_main_move(pl_num);

        if (end_w.end_flag) {
            end_w.r_no_0++;
            end_no_cut = 1;
            effect_work_kill(4, 0x9F);
            SsBgmFadeOut(0x111);
        } else if (Cut_Cut_Cut_t()) {
            end_w.timer = 0;
            effect_work_kill(4, 0x9F);
            end_main_move(pl_num);
            end_fade_flag = 0;
        }

        Forbid_Break = -1;
        break;

    case 4:
        if (end_no_cut == 0) {
            fadeout_to_staff_roll();
        } else {
            end_w.r_no_0++;
        }

        Forbid_Break = -1;
        break;

    case 5:
        if (end_fade_complete()) {
            end_w.r_no_0++;
            end_w.r_no_2++;
            overwrite_panel(0xFF000000, 0x12);

            if (end_w.type == 4) {
                Zoomf_Init();
            }

            end_w.r_no_0++;
            end_no_cut = 1;
            bg_w.bgw[0].xy[0].disp.pos = 256;
            bg_w.bgw[0].abs_x = 512;
            bg_w.bgw[0].xy[1].disp.pos = 0;
            bg_w.bgw[0].abs_y = 0;
            end_scn_pos_set2();
            end_bg_pos_hosei2();
            end_fam_set2();
            sub_000AF4C2(0xF);
        }

        Forbid_Break = -1;
        break;

    case 6:
        overwrite_panel(0xFF000000, 0x12);
        end_w.r_no_0++;
        break;

    case 7:
        end_w.r_no_0++;
        overwrite_panel(0xFF000000, 0x12);
        Request_Fade(6);
        end_no_cut = 1;
        Forbid_Break = -1;
        break;

    case 8:
        if (end_fade_complete()) {
            sub_0004384A(7);
            end_w.r_no_0++;
            end_no_cut = 0;
            Bg_Close();
        }

        Forbid_Break = -1;
        break;

    case 9:
        scr_calc(5);

        if (staff_credits(end_staff_flag)) {
            end_w.r_no_0++;
        }

        break;

    case 10:
        end_w.r_no_0++;

        if (name_wk[WINNER].timer >= 1) {
            name_wk[WINNER].timer = 0;
            end_name_cut[WINNER] = 1;
            end_w.timer = 180;

            if (bgm_play_status() == 2) {
                SsBgmFadeOut(0xB6);
            }

            break;
        }

        end_w.timer = 60;

        if (bgm_play_status() == 2) {
            SsBgmFadeOut(0x222);
        }

        break;

    case 11:
        end_w.timer--;

        if (end_w.timer < 0) {
            end_w.r_no_0++;
            ending_all_end = 1;
        }

        break;

    case 12:
        ending_all_end = 1;
        break;
    }
}

void end_main_move(s16 pl_num) {
    end_main_jp[pl_num](pl_num);
    end_fade_bgm();
}

void fadeout_to_staff_roll() {
    Request_Fade(7);
    end_no_cut = 1;
    Forbid_Break = -1;
}

void common_end_init00(s16 pl_num) {
    s16 i;

    Family_Init();
    Scrn_Pos_Init();
    Zoomf_Init();
    bg_w.bg_opaque = ending_opaque[pl_num];
    Screen_Switch = 0;
    Screen_Switch_Buffer = 0;
    bg_disp_off = 0;
    end_w.type = pl_num;
    bg_w.scno = end_use_scr[end_w.type];
    bg_w.scrno = end_use_real_scr[end_w.type];
    Bg_Texture_Load_Ending(end_w.type);
    ending_obj_load();
    bg_w.pos_offset = 192;
    base_y_pos = 40;

    for (i = 0; i < 7; i++) {
        bg_w.bgw[i].r_no_0 = 0;
        bg_w.bgw[i].r_no_1 = 0;
        bg_w.bgw[i].r_no_2 = 0;
        bg_w.bgw[i].pos_x_work = bg_w.bgw[i].pos_y_work = 0;
        bg_w.bgw[i].zuubun = 0;
        bg_w.bgw[i].xy[0].cal = 0;
        bg_w.bgw[i].xy[1].cal = 0;
        bg_w.bgw[i].wxy[0].cal = 0;
        bg_w.bgw[i].wxy[1].cal = 0;
        bg_w.bgw[i].hos_xy[0].cal = 0;
        bg_w.bgw[i].hos_xy[1].cal = 0;
        bg_w.bgw[i].rewrite_flag = 0;
    }

    for (i = 0; i < bg_w.scno; i++) {
        bg_w.bgw[i].r_no_1 = bg_w.bgw[i].r_no_2 = 0;
        bg_w.bgw[i].fam_no = i;
    }
}

void common_end_init01() {
    bg_w.scr_stop = 0;
    bg_w.frame_flag = 0;
    bg_w.bg_f_x = 9;
    bg_w.bg_f_y = 9;
    bg_w.bg2_sp_x2 = bg_w.bg2_sp_x = 0;
    bg_w.max_x = 6;
    bg_w.old_chase_flag = bg_w.chase_flag = 0;
    bg_w.quake_x_index = 0;
    bg_w.quake_y_index = 0;
    end_etc_flag = 0;
    end_reset_etc();
    bg_w.bgw[3].wxy[0].cal = bg_w.bgw[3].xy[0].cal = 0x2000000;
    bg_w.bgw[3].xy[1].cal = 0;
    bg_w.bgw[3].position_x = 512 - bg_w.pos_offset;
    bg_w.bgw[3].position_y = 0;
    end_fam_set(3);
    Scrn_Move_Set(3, bg_w.bgw[3].position_x, bg_w.bgw[3].position_y);
    effect_E9_init();
    effect_F9_init(end_w.type);
}

void end_fam_set(s16 i) {
    s16 pos_work_x = bg_w.bgw[i].position_x;
    s16 pos_work_y = bg_w.bgw[i].position_y;

    pos_work_x = pos_work_x & 0xFFFF;
    pos_work_y = (pos_work_y + 16) & 0xFFFF;

    sub_000AF47B(i + 1, pos_work_x, pos_work_y);
}

void end_fam_set2() {
    s16 i;
    s16 pos_work_x;
    s16 pos_work_y;

    for (i = 0; i < bg_w.scno; i++) {
        pos_work_x = bg_w.bgw[i].position_x;
        pos_work_y = bg_w.bgw[i].position_y;
        pos_work_x = pos_work_x & 0xFFFF;
        pos_work_y = (pos_work_y + 16) & 0xFFFF;
        sub_000AF47B(i + 1, pos_work_x, pos_work_y);
    }
}

void end_bg_pos_hosei2() {
    s16 bg_no;
    u16 pos_work;

    for (bg_no = 0; bg_no < bg_w.scno; bg_no++) {
        pos_work = bg_w.bgw[bg_no].abs_x & 0xFFFF;
        pos_work -= bg_w.pos_offset;
        bg_w.bgw[bg_no].position_x = pos_work & 0xFFFF;
        pos_work = bg_w.bgw[bg_no].abs_y & 0xFFFF;
        bg_w.bgw[bg_no].position_y = pos_work;
    }
}

void end_scn_pos_set2() {
    s16 bg_no;

    for (bg_no = 0; bg_no < bg_w.scno; bg_no++) {
        Scrn_Move_Set(bg_w.bgw[bg_no].fam_no,
                      (bg_w.bgw[bg_no].xy[0].disp.pos & 0xFFFF) - bg_w.pos_offset,
                      bg_w.bgw[bg_no].xy[1].disp.pos);
        bg_w.bgw[bg_no].wxy[0].cal = bg_w.bgw[bg_no].xy[0].cal;
        bg_w.bgw[bg_no].wxy[1].cal = bg_w.bgw[bg_no].xy[1].cal;
    }
}

void end_reset_etc() {
    s16 i;

    for (i = 0; i < bg_w.scno; i++) {
        bg_w.bgw[i].r_no_1 = 0;
        bg_w.bgw[i].abs_x = bg_w.bgw[i].xy[0].disp.pos = 512;
        bg_w.bgw[i].abs_y = bg_w.bgw[i].xy[1].disp.pos = 0;
    }
}

void end_X_com01() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        sub_000AF4C2(1 << bgw_ptr->fam_no);
        break;

    case 1:
        break;
    }
}

void end_fade_bgm() {
    if (end_fade_flag != 0) {
        end_fade_timer -= 1;

        if (end_fade_timer < 0) {
            end_fade_flag = 0;
        }
    }
}

s16 end_fade_complete() {
    if (Check_Fade_Complete()) {
        Forbid_Break = -1;
        return 1;
    }

    return 0;
}

s32 Cut_Cut_Cut_t() {
    u16 sw_w;

    if (end_no_cut == 0) {
        if (WINNER) {
            sw_w = p2sw_0 & ~p2sw_1;
        } else {
            sw_w = p1sw_0 & ~p1sw_1;
        }

        if (sw_w & 0xFF0) {
            return 1;
        }
    }

    return 0;
}

#if 0
/* PS2 C for functions not located in sf33rd.xbe yet. */

void end_bg_pos_hosei(s16 bg_no) {
    s16 pos_work = bg_w.bgw[bg_no].abs_x & 0xFFFF;
    pos_work -= bg_w.pos_offset;
    bg_w.bgw[bg_no].position_x = pos_work & 0xFFFF;
    pos_work = bg_w.bgw[bg_no].abs_y & 0xFFFF;
    bg_w.bgw[bg_no].position_y = pos_work;
}
#endif
