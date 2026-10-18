/* Effect 02, retail sf33rd.xbe.
 * urian_guard_se_check is 0x32086 size 0x56 and is interior.
 * effect_02_init is 0x320DC size 0x19C and is interior.
 * effect_02_move is 0x32278 size 0x382 and is a scanned start.
 * The pull failure is an early ret. The Combo_Demo_Flag
 * path jumps to the shared epilogue.
 * 0x3201A stays unnamed. 0x325FA is eff03_disp_pos.
 *
 * hit_mark_dir_table is 0x249C80. hmdt is 0x249CA0.
 * hcct is 0x24A378. gqdt is 0x24A388. explem is 0x24A3D4.
 * explem2 is 0x24A3F0. hit_mark_hosei_table is 0x24A4E0.
 * All of them match. The rows were not pasted. Four zero
 * bytes at 0x24A384 pad hcct. Four zero bytes at 0x24A3EC
 * pad explem.
 *
 * The init stores vital_new, vital_old, and dm_rl before
 * be_flag. It stores my_mr_flag before dm_vital. It stores
 * weight_level before old_pos[1]. The player path stores
 * weight_level before dir_timer. The C keeps the PlayStation
 * 2 order. Case 1 stores routine_no[0] before disp_flag on
 * the cg_type path. The character table immediate is
 * 0x3064A0. Those bytes were not compared.
 * Combo_Demo_Flag is 0x7A8198. Last_Called_SE is 0x7A8796.
 * Suicide is 0x7A8268. Pause_Hit_Marks is 0x7A88AC.
 * EXE_flag is 0xC7C834. Game_pause is 0x7A89B0.
 * bg_w.quake_y_index is 0x7BC540.
 * sound_effect_request is 0x266008.
 * char_move is 0x2008E.
 * set_char_move_init is 0x200A9.
 * random_16 is 0x9326B.
 * pp_screen_quake is 0x96BD3.
 * sort_push_request8 is 0x9E174.
 * push_effect_work is 0x4AC6C.
 * pull_effect_work is 0x4A6A8. frw is 0xC806A0
 * and each object is 0x700 bytes.
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

typedef struct {
    u16 chix;
    s16 hx;
    s16 hy;
} EXPLEM;

typedef struct {
    u8 pad[0xE];
    u8 hit_mark;
} Att;

typedef struct {
    struct {
        s16 x;
        s16 y;
    } size;
} Mr;

typedef struct {
    s8 be_flag;
    s8 disp_flag;
    u8 blink_timing;
    u8 pad_id[3];
    s16 work_id;
    s16 id;
    s8 rl_flag;
    u8 pad_tgt[1];
    u32 *target_adrs;
    u8 pad_dead[0x10];
    s16 dead_f;
    u8 pad_rno[2];
    s16 routine_no[8];
    u8 pad_cg[0x14];
    s8 cgromtype;
    u8 pad_pos[0xB];
    s16 position_x;
    s16 position_y;
    s16 position_z;
    u8 pad_scr[6];
    s16 scr_mv_x;
    s16 scr_mv_y;
    XY xyz[3];
    s16 old_pos[2];
    u8 pad_dir[0x20];
    s16 direction;
    s16 dir_old;
    u8 pad_dt[2];
    s16 dir_timer;
    u8 pad_vn[2];
    s16 vital_new;
    s16 vital_old;
    s16 dm_vital;
    u8 pad_wt[4];
    s8 weight_level;
    u8 pad_ct[0x103];
    u32 *char_table[1];
    u8 pad_ci[0x58];
    s16 char_index;
    u8 pad_cgt[0xA];
    u8 cg_type;
    u8 pad_col[0x27];
    s16 my_col_mode;
    s16 my_col_code;
    u8 pad_fam[2];
    s16 my_family;
    u8 pad_mr[0xA];
    s16 my_mr_flag;
    Mr my_mr;
    u8 pad_att[0x6C];
    Att att;
    u8 pad_kez[5];
    s16 kezuri_pow;
    u8 pad_dira[8];
    s16 dir_atthit;
    u8 pad_hm[0x18];
    s16 hit_mark_x;
    s16 hit_mark_y;
    u8 pad_kohm[2];
    s16 kohm;
    u8 pad_rl[0x10];
    s8 dm_rl;
    u8 pad_end[0x77];
} WORK;

typedef struct {
    WORK wu;
    u32 *my_master;
    s16 master_work_id;
    s16 master_id;
    s16 master_player;
} WORK_Other;

typedef struct {
    WORK wu;
    u8 pad_pl[0xC];
    s16 player_number;
    u8 pad_mu[0x18];
    s16 muriyari_ugoku;
} PLW;

typedef struct {
    u8 pad[0x20];
    s16 quake_y_index;
} BG;

typedef u8 EffectRow[0x700];
typedef void (*SERequest)(WORK_Other *ewk, u16 oto);

#if defined(__i386__)
_Static_assert(sizeof(HMDT) == 0xC, "HMDT");
_Static_assert(sizeof(EXPLEM) == 6, "EXPLEM");
_Static_assert(__builtin_offsetof(HMDT, hits) == 2, "hits");
_Static_assert(__builtin_offsetof(HMDT, deff) == 3, "deff");
_Static_assert(__builtin_offsetof(HMDT, kezu) == 4, "kezu");
_Static_assert(__builtin_offsetof(HMDT, status) == 6, "status");
_Static_assert(__builtin_offsetof(HMDT, quake) == 7, "quake");
_Static_assert(__builtin_offsetof(HMDT, dir) == 8, "dir");
_Static_assert(__builtin_offsetof(HMDT, col) == 9, "col");
_Static_assert(__builtin_offsetof(HMDT, myhix) == 0xA, "myhix");
_Static_assert(__builtin_offsetof(HMDT, emhix) == 0xB, "emhix");
_Static_assert(__builtin_offsetof(EXPLEM, hx) == 2, "hx");
_Static_assert(__builtin_offsetof(EXPLEM, hy) == 4, "hy");
_Static_assert(__builtin_offsetof(WORK, be_flag) == 0, "be_flag");
_Static_assert(__builtin_offsetof(WORK, disp_flag) == 1, "disp_flag");
_Static_assert(__builtin_offsetof(WORK, blink_timing) == 2, "blink");
_Static_assert(__builtin_offsetof(WORK, work_id) == 6, "work_id");
_Static_assert(__builtin_offsetof(WORK, id) == 8, "id");
_Static_assert(__builtin_offsetof(WORK, rl_flag) == 0xA, "rl_flag");
_Static_assert(__builtin_offsetof(WORK, target_adrs) == 0xC, "target");
_Static_assert(__builtin_offsetof(WORK, dead_f) == 0x20, "dead_f");
_Static_assert(__builtin_offsetof(WORK, routine_no) == 0x24, "routine_no");
_Static_assert(__builtin_offsetof(WORK, cgromtype) == 0x48, "cgromtype");
_Static_assert(__builtin_offsetof(WORK, position_x) == 0x54, "position_x");
_Static_assert(__builtin_offsetof(WORK, position_y) == 0x56, "position_y");
_Static_assert(__builtin_offsetof(WORK, position_z) == 0x58, "position_z");
_Static_assert(__builtin_offsetof(WORK, scr_mv_x) == 0x60, "scr_mv_x");
_Static_assert(__builtin_offsetof(WORK, scr_mv_y) == 0x62, "scr_mv_y");
_Static_assert(__builtin_offsetof(WORK, xyz) == 0x64, "xyz");
_Static_assert(__builtin_offsetof(WORK, xyz[0].disp.pos) == 0x66, "xyz0");
_Static_assert(__builtin_offsetof(WORK, xyz[1].disp.pos) == 0x6A, "xyz1");
_Static_assert(__builtin_offsetof(WORK, xyz[2].disp.pos) == 0x6E, "xyz2");
_Static_assert(__builtin_offsetof(WORK, old_pos) == 0x70, "old_pos");
_Static_assert(__builtin_offsetof(WORK, direction) == 0x94, "direction");
_Static_assert(__builtin_offsetof(WORK, dir_old) == 0x96, "dir_old");
_Static_assert(__builtin_offsetof(WORK, dir_timer) == 0x9A, "dir_timer");
_Static_assert(__builtin_offsetof(WORK, vital_new) == 0x9E, "vital_new");
_Static_assert(__builtin_offsetof(WORK, vital_old) == 0xA0, "vital_old");
_Static_assert(__builtin_offsetof(WORK, dm_vital) == 0xA2, "dm_vital");
_Static_assert(__builtin_offsetof(WORK, weight_level) == 0xA8, "weight");
_Static_assert(__builtin_offsetof(WORK, char_table) == 0x1AC, "char_table");
_Static_assert(__builtin_offsetof(WORK, char_index) == 0x208, "char_index");
_Static_assert(__builtin_offsetof(WORK, cg_type) == 0x214, "cg_type");
_Static_assert(__builtin_offsetof(WORK, my_col_mode) == 0x23C, "my_col_mode");
_Static_assert(__builtin_offsetof(WORK, my_col_code) == 0x23E, "my_col_code");
_Static_assert(__builtin_offsetof(WORK, my_family) == 0x242, "my_family");
_Static_assert(__builtin_offsetof(WORK, my_mr_flag) == 0x24E, "my_mr_flag");
_Static_assert(__builtin_offsetof(WORK, my_mr.size.x) == 0x250, "mr_x");
_Static_assert(__builtin_offsetof(WORK, my_mr.size.y) == 0x252, "mr_y");
_Static_assert(__builtin_offsetof(WORK, att.hit_mark) == 0x2CE, "hit_mark");
_Static_assert(__builtin_offsetof(WORK, kezuri_pow) == 0x2D4, "kezuri");
_Static_assert(__builtin_offsetof(WORK, dir_atthit) == 0x2DE, "dir_atthit");
_Static_assert(__builtin_offsetof(WORK, hit_mark_x) == 0x2F8, "hmx");
_Static_assert(__builtin_offsetof(WORK, hit_mark_y) == 0x2FA, "hmy");
_Static_assert(__builtin_offsetof(WORK, kohm) == 0x2FE, "kohm");
_Static_assert(__builtin_offsetof(WORK, dm_rl) == 0x310, "dm_rl");
_Static_assert(sizeof(WORK) == 0x388, "WORK");
_Static_assert(__builtin_offsetof(WORK_Other, my_master) == 0x388, "my_master");
_Static_assert(__builtin_offsetof(WORK_Other, master_work_id) == 0x38C, "mwid");
_Static_assert(__builtin_offsetof(WORK_Other, master_id) == 0x38E, "mid");
_Static_assert(__builtin_offsetof(WORK_Other, master_player) == 0x390, "mplayer");
_Static_assert(__builtin_offsetof(PLW, player_number) == 0x394, "player");
_Static_assert(__builtin_offsetof(PLW, muriyari_ugoku) == 0x3AE, "muriyari");
_Static_assert(__builtin_offsetof(BG, quake_y_index) == 0x20, "quake_y");
#endif

extern EffectRow frw[];
extern u32 _ef01_char_table[];
extern const s16 hit_mark_dir_table[16];
extern const HMDT hmdt[146];
extern const s16 hcct[6];
extern const s16 gqdt[19][2];
extern const EXPLEM explem[4];
extern const EXPLEM explem2[2][20];
extern BG bg_w;
extern u8 Combo_Demo_Flag;
extern u8 Pause_Hit_Marks;
extern s16 Last_Called_SE;
extern s8 Suicide[8];
extern s16 EXE_flag;
extern u8 Game_pause;
extern SERequest sound_effect_request[];

void urian_guard_se_check(WORK_Other *ewk, PLW *twk, u16 oto);
void char_move(WORK *wk);
void set_char_move_init(WORK *wk, s16 koc, s16 index);
s16 random_16(void);
void pp_screen_quake(s32 ix);
void sort_push_request8(WORK *wk);
void push_effect_work(WORK *wk);
s16 pull_effect_work(s16 index);

void effect_02_move(WORK_Other *ewk) {
    const HMDT *tad;
    const EXPLEM *edt;

    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.char_table[0] = _ef01_char_table;
        tad = &hmdt[ewk->wu.kohm];

        if (ewk->wu.vital_old == 2) {
            ewk->wu.kohm = tad->deff;

            if (ewk->wu.dm_vital != 0) {
                ewk->wu.kohm = tad->kezu;
            }
        }

        tad = &hmdt[ewk->wu.kohm];

        if (tad->hits == 0) {
            if (tad->se) {
                urian_guard_se_check(ewk, (PLW *)ewk->wu.target_adrs, tad->se);
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
            if (((PLW *)ewk->wu.target_adrs)->wu.work_id == 1) {
                ewk->wu.dir_timer = ((PLW *)ewk->wu.target_adrs)->player_number;
            } else {
                ewk->wu.dir_timer = ((WORK_Other *)ewk->wu.target_adrs)->master_player;
            }
        }

        if (tad->col) {
            ewk->wu.my_col_code = hcct[tad->col];
        } else if (tad->status & 0x80) {
            ewk->wu.my_col_code = ((PLW *)ewk->wu.target_adrs)->wu.my_col_code;
        }

        if (tad->se) {
            urian_guard_se_check(ewk, (PLW *)ewk->wu.target_adrs, tad->se);
        } else {
            Last_Called_SE = 0;
        }

        if (tad->status & 4) {
            ewk->wu.rl_flag = ewk->wu.dm_rl;
        }

        if (tad->status & 0x10) {
            if (tad->status & 0x20) {
                edt = &explem2[tad->emhix][ewk->wu.dir_timer];
            } else {
                edt = &explem[tad->myhix];
            }

            if (ewk->wu.rl_flag) {
                ewk->wu.xyz[0].disp.pos -= *(s16 *)&edt->hx;
            } else {
                ewk->wu.xyz[0].disp.pos += *(s16 *)&edt->hx;
            }

            ewk->wu.xyz[1].disp.pos += *(s16 *)&edt->hy;
        } else {
            ewk->wu.xyz[0].disp.pos += ewk->wu.old_pos[0];
            ewk->wu.xyz[1].disp.pos += ewk->wu.old_pos[1];
        }

        if (ewk->wu.weight_level) {
            ewk->wu.xyz[0].disp.pos += ((PLW *)ewk->my_master)->muriyari_ugoku;
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

        if (ewk->wu.char_index == 0x4B) {
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

void urian_guard_se_check(WORK_Other *ewk, PLW *twk, u16 oto) {
    if (twk->player_number == 13 && (oto == 266 || oto == 267)) {
        sound_effect_request[280](ewk, 280);
        Last_Called_SE = 280;
        return;
    }

    sound_effect_request[oto](ewk, oto);
    Last_Called_SE = oto;
}

s32 effect_02_init(WORK *wk, s8 dmgp, s8 mkst, s8 dmrl) {
    WORK_Other *ewk;
    WORK_Other *dwk;
    s16 ix;

    if (Combo_Demo_Flag & 0x80) {
        return 0;
    }

    if ((ix = pull_effect_work(2)) == -1) {
        return -1;
    }

    ewk = (WORK_Other *)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 2;
    ewk->wu.work_id = 64;
    ewk->wu.vital_new = dmgp;
    ewk->wu.vital_old = mkst;
    ewk->wu.dm_rl = dmrl;
    ewk->wu.kohm = wk->att.hit_mark;
    ewk->wu.direction = wk->dir_atthit;
    ewk->wu.dm_vital = wk->kezuri_pow;
    ewk->wu.cgromtype = 1;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_family = 2;
    ewk->wu.my_mr_flag = 0;
    ewk->wu.xyz[0].disp.pos = ewk->wu.position_x = wk->xyz[0].disp.pos;
    ewk->wu.xyz[1].disp.pos = ewk->wu.position_y = wk->xyz[1].disp.pos;
    ewk->wu.xyz[2].disp.pos = 26;
    ewk->wu.old_pos[0] = wk->hit_mark_x - wk->xyz[0].disp.pos;
    ewk->wu.old_pos[1] = wk->hit_mark_y - wk->xyz[1].disp.pos;
    ewk->wu.weight_level = 0;

    if (wk->work_id == 1) {
        ewk->my_master = (u32 *)wk;
        ewk->master_id = wk->id;
        ewk->master_work_id = wk->work_id;
        ewk->wu.target_adrs = wk->target_adrs;
        ewk->wu.my_col_code = wk->my_col_code;
        ewk->master_player = ewk->wu.dir_timer = ((PLW *)wk)->player_number;
        ewk->wu.weight_level = 1;
    } else {
        dwk = (WORK_Other *)wk;
        ewk->my_master = (u32 *)dwk->my_master;
        ewk->master_id = dwk->master_id;
        ewk->master_work_id = dwk->master_work_id;
        ewk->wu.target_adrs = ((WORK *)dwk->my_master)->target_adrs;
        ewk->wu.my_col_code = ((WORK *)dwk->my_master)->my_col_code;
        ewk->master_player = ewk->wu.dir_timer = dwk->master_player;
    }

    ewk->wu.blink_timing = ewk->master_id;
    return 0;
}
