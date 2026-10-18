/* TITLE_Init, retail sf33rd.xbe 0x69786, size 0xC9.
 * TITLE_Move 0x6984F, size 0x11B, interior after the ret.
 * sound_trg_init 0x6996A, size 0x11, interior after the ret.
 * sound_trg_move 0x6997B, size 0x32, interior after the ret.
 * OPBG_Trans 0x699AD, size 0xC5, interior after the ret.
 * oh_tsr_ck 0x69A72, size 0x27, interior after the ret.
 * oh_reload_tex 0x69A99, size 0x62, interior after the ret.
 * oh_bg_blk_w 0x69AFB, size 0x4B. oh_bg_blk_wh 0x69B46, size 0x4C.
 * oh_bg_blk_wv 0x69B92, size 0x4C. oh_bg_blk_whv 0x69BDE, size 0x4C.
 * opening_init 0x69C2A, size 0x8B, interior after the ret.
 * op_work_clear 0x69CB5, size 0x18, interior after the ret.
 * opning_init_00000 0x69CCD, size 0xE5, interior after the ret.
 * opning_init_01000 0x69DB2, size 0x41, interior after the ret.
 * opning_init_02000 0x69DF3, size 0x5E, interior after the ret.
 * opening_move 0x69E51, size 0x66, interior after the ret.
 * op_bg1_0000 0x69EB7, size 0x2B, interior after the ret.
 * op_bg1_0001 0x69EE2, size 0x81, interior after the ret.
 * op_bg1_0002 0x69F63, size 0xF0, interior after the ret.
 * op_bg1_0003 0x6A053, size 0x15A, interior after the ret.
 * op_bg2_0000 0x6A1AD, size 0x3A, interior after the ret.
 * op_bg2_0001 0x6A1E7, size 0x23, interior after the ret.
 * op_bg2_0002 0x6A20A, size 0x3A, interior after the ret.
 * op_bg2_0003 0x6A244, size 0x3A, interior after the ret.
 * opening_title_01 0x6A27E, size 0xB8, interior after the ret.
 * op_scrn_pos_set2 0x6A336, size 0x2E, interior after the ret.
 * Bg_Family_Set_op 0x6A364, size 0x9C, interior after the ret.
 * OPBG_Init 0x6A400, size 0xDC, interior after the ret.
 * opening_init2 0x6A4DC, size 0x2A, interior after the ret.
 * op_bg0_0000 0x6A506, size 0x33, interior. Stores r_no_0 = 1 and clears
 * xy[1].cal with and.
 * op_bg0_0001 0x6A539, size 0x42D, interior after the ret.
 * op_bg0_0002 0x6A966, size 0xE5, a scanned start.
 * op_bg0_0003 0x6AA4B, size 0x10D, interior. Stores r_no_0 = 1.
 * op_bg0_0004 0x6AB58, size 0x1A7, a scanned start.
 * op_bg0_0005 0x6ACFF, size 0x14C, interior after the ret.
 * op_bg0_0006 0x6AE4B, size 0x95, interior after the ret.
 * op_bg0_0007 0x6AEE0, size 0xB1, interior after the ret.
 * op_bg0_0008 0x6AF91, size 0xB0, interior after the ret. Case 0 falls through.
 * op_bg0_0010 0x6B041, size 0xB9, interior after the ret.
 * op_bg0_0011 0x6B0FA, size 0xD8, interior after the ret. Case 1 falls through.
 * op_bg0_0012 0x6B1D2, size 0xCA, interior after the ret.
 * op_bg0_0013 0x6B29C, size 0xB0, interior after the ret.
 * op_bg0_0014 0x6B34C, size 0x5, interior after the ret. It is one jmp
 * to op_bg0_0000, and the argument stays on the stack.
 * op_bg0_0015 0x6B351, size 0x126, interior after that jmp.
 * op_bg0_0016 0x6B477, size 0xD0, interior after the ret.
 * opening_title 0x6B5ED, size 0x2C, interior after the ret.
 * oh_opening_demo 0x6B619, size 0x3A.
 * op_bg1_move 0x6B547, size 0x57, interior after the ret.
 * op_bg2_move 0x6B59E, size 0x4F, interior after the ret.
 * op_bg0_move 0x6B653, size 0x24E.
 * OPBG_Move 0x6B8A1, size 0x12, interior after the ret.
 * op_bg_move 0x6B8B3, size 0x1C, interior after the ret.
 * opening_demo 0x6B8CF, size 0xBA, interior after the ret.
 * op_101_move 0x6B989, size 0x7F, interior after the ret.
 * op_117_move 0x6CEA5, size 0x78, interior after a tail jmp.
 * op_118_move 0x6CF1D, size 0x8D, interior after the ret.
 * op_100_move 0x6CFAA, size 0x10, interior after the ret.
 * op_102_move 0x6BA08, size 0xAF, interior after the ret.
 * op_103_move 0x6BAB7, size 0x28E, interior after the ret. Its jump table is
 * inside the size.
 * op_104_move 0x6BD45, size 0x1AB. It follows op_103_move's jump table.
 * op_105_move 0x6BEF0, size 0x47, interior after the ret.
 * op_106_move 0x6BF37, size 0xFC, interior after the ret.
 * op_107_move 0x6C033, size 0x288, interior after the ret. Its jump table is
 * inside the size.
 * op_108_move 0x6C2BB, size 0x309, interior because the three bytes before
 * this start decode as ret 6. Its jump table is inside the size.
 * op_109_move 0x6C5C4, size 0x117. It follows op_108_move's jump table.
 * op_110_move 0x6C6DB, size 0x13D, interior after the ret.
 * op_111_move 0x6C818, size 0xE8, interior after the ret.
 * op_112_move 0x6C900, size 0x228, interior after the ret. Its jump table is
 * inside the size.
 * op_113_move 0x6CB28, size 0xF4. It follows op_112_move's jump table.
 * op_114_move 0x6CC1C, size 0x13F, interior after the ret.
 * op_115_move 0x6CD5B, size 0x6B, interior after the ret.
 * op_116_move 0x6CDC6, size 0xDF, interior after the ret.
 *
 * Country is the byte at 0x7A8748. Opening_Now is the word at 0x7968A8.
 * ppgTitleList is 0x7A7E40 and ppgTitleTex is 0x7A7DC0. title_tex_flag is
 * the word at 0xC7E19E. op_w is 0xC7E1C0. op_timer0 is the word at 0xC7E4F0.
 * scr_sc is the float at 0x7C55F4. title[0] and title[1] both hold 0x25F3E8.
 * music_scene is the word at 0xC7E190. music_time is the word at 0xC7E54A.
 * op_plmove_timer is the word at 0xC7E19C. gSeqStatus[0] is the byte at
 * 0xC7C836. The time table is 0x25F4C8 and the trigger table is 0x25F6D0.
 * Both tables are the 257 PS2 entries, ending in -1.
 * ppgOpnBgList is 0x7A7DB8 and ppgOpnBgTex is 0x7A7DE0. Its textures word
 * is at 0x7A7DF0. optsr_tbl is 0x25F450 and holds 34 through 91, then -1.
 * No_Trans is the byte at 0x7BD3C9. Screen_Switch is the word at 0x7BC988.
 * OPBG_Trans tests its low byte. Screen_Switch_Buffer is the next word.
 * bg_prm[0] shifts are the words at 0x7C5960 and 0x7C5962. Layer 1 is
 * 0x7C5964 and 0x7C5966. Layer 2 is 0x7C5968 and 0x7C596A. mts is 0x7A8F20
 * and each element is 0x64 bytes, so mts[9] is 0x7A92A4.
 *
 * The load index is 0x54 when Country is 1 or 2, and 0x53 otherwise.
 * TITLE_Init also stores 1 at 0x32F858. Put_char is called with priority 2.
 * State 2 steps the timer on every call. OPBG_Trans returns after the three
 * screen tests and has no debug print. oh_tsr_ck compares 34 as an immediate,
 * then reads the table from the second entry through -1. OPBG_Init is the
 * only caller of sound_trg_init. bg_w is 0x7BC520. scno is the byte at
 * 0x7BC530 and pos_offset is the word at 0x7BC53C. The position_x store
 * subtracts the dword at that address, so it includes quake_x_index.
 * op_end_flag is the word at 0xC7E198. bg_stop is the word at 0x7BC4A0.
 * akebono_flag, bg_app, and sa_pa_flag are the bytes at 0x7BC4A9, 0x7BC4A8,
 * and 0x7BC4AA. aku_flag is 0x7BC4F0 and bg_app_stop is 0x7BC4E8.
 * base_y_pos is the word at 0x7BC516. op_demo_index is 0xC7E548.
 * op_sound_status is 0xC7E1A2. Game_timer is the word at 0x7A8830.
 * op_change_sound_tbl is 0x25F8D4. opening_move_jp is 0x32F860.
 * opening_move has no debug print. opening_init2 tail-jumps to the three
 * inits. opning_init_01000 calls 0xAF4C2 for both off helpers. opening_title
 * does not call the empty opening_title_00. opening_title_01 loads the dword
 * at pos_offset, adds -0x200, and keeps the low word. It does not clear
 * bg_app_stop. Bg_Family_Set_op subtracts the pos_offset word on the first
 * four layers. Layer 5 subtracts the dword at pos_offset from the dword at
 * wxy[0].disp.pos, masks the dword at xy[1].disp.pos with 0xFFFF03FF, and
 * keeps each low word. The loop uses that same mask on a zero-extended word.
 * opw_ptr is 0xC7E194 and bgw_ptr is 0x7BC510. D_No[3] is the byte at
 * 0x7A8203. op_obj_disp is the word at 0xC7E19A. opening_demo does not test
 * Game_pause, and its FadeIn call passes 1. op_100_move does not call
 * Disp_Sound_Code. op_101_move compares 11 and 0x65 as immediates.
 * op_102_move compares 9, 0x66, and 12 as immediates. op_106_move compares
 * 1, 0x6A, 3, and 7 as immediates. op_115_move compares 7 and 0x73 as
 * immediates. op_116_move passes 1 to FadeOut and calls 0x4384A with 2.
 * op_103_move, op_107_move, and op_109_move through op_114_move compare
 * sound thresholds as immediates. op_104_move reads op_104_sound at
 * 0x32F8AC, the words 0, 5, 6, 7, 9, 10, and 11. op_108_move compares
 * mv_ctr as immediates and skips the background move when cases 2, 4, 6,
 * 8, 10, and 12 are still short. op_scrn_end is the byte at 0xC7E1A0.
 * op_110_move case 1 only rejects 0x6E. op_107_move case 0 increments
 * op_plmove_timer, then r_no_2, then stores obj.
 * op_bg1_0000, op_bg1_0001, and op_bg2_0001 store 1 into r_no_0. The other
 * five handlers increment it. xy[1].disp.pos is cleared with and. The shift
 * into 0xAF4AA uses the low byte of fam_no. op_bg_mvxy is 0xC7E500 and each
 * entry is 0x18 bytes. op_bg2_0000 subtracts 0x10000 from wxy[0].cal. The
 * PS2 source spells that same delta as (0x8000 + 0x8000). r_limit is the
 * word at bgw+0x64 and l_limit is the word at bgw+0x68. free is the word at
 * bgw+0x60 and frame_deff is the word at bgw+0x62. op_quake_y_tbl0 is
 * 0x25F8F8. ot_bg0_0004_tbl is 0x25FAA8 and ot_bg0_0015_tbl is 0x25FAE0.
 * Both hold 0xFF00A0B0, 0xFF005888, 0xFF00A0B0, 0xFF005888, 0xFF000058,
 * and 0xFF000000. op_bg0_0005_tbl is 0x25FAC0. Frame_Zoom_X is the float
 * at 0x7C5B94 and Frame_Zoom_Y is the float at 0x7C5854. 384.0f is
 * 0x2497E8 and 224.0f is 0x2497E4. PrioBase[75] is 0xC7E68C. op_bg0_0002
 * and op_bg0_0004 pass 2 as the fifth draw argument and leave tex unset.
 * op_bg0_0004 case 3 writes 0xFF000000, the same bits as table entry 5.
 * op_bg0_0007 adds 0xC000, which is 0x7FFF + 0x4001. op_bg0_0008 adds
 * 0xFFFF4000, which is -(0x8000 + 0x4000). op_bg0_0012 steps when the
 * position word is <= 0x60, the same s16 test as < 0x61. 0xFF000000 is
 * the same bits as -0x01000000. Index 83 writes
 * layer 0 at 0xC7E1CC. Index 62 and the layer-1 block writes use 0xC7E2D8.
 * put_chr2 is 0xD0D67 size 0xB9 and is a scanned start. opbg_trans is
 * 0xD0E20 size 0x112 and is a scanned start. It clamps each shift to
 * 0..1023 and calls put_chr2. 0xD0F32 stays unnamed.
 * 0x4384A, 0x59FD2, 0x13EFE, 0x97103,
 * 0x1C902, 0x1C8ED, 0x30AAF, 0xB58A7, 0xEF72E,
 * 0x629B7, 0xAF4C2, 0xAF4AA, 0x48F0E, 0x4AFFA, and 0xAF47B stay unnamed.
 * ppgSetupTexChunk_1st is 0xF2B0A. ppgSetupTexChunk_2nd is 0xF2CFD.
 * ppgSetupTexChunk_3rd is 0xF3F82. ppgReleaseTextureHandle is 0xF416A.
 */

#include "types.h"

typedef struct {
    u8 prefix[0x10];
    u16 textures;
} Texture;

typedef struct Palette Palette;

typedef struct {
    Texture *tex;
    Palette *pal;
} PPGDataList;

typedef union {
    s32 full;
} OPTW_Color;

typedef struct {
    u32 g_no;
    s32 trans;
    u16 hv;
    s16 ok;
    OPTW_Color col;
} OPTW_Small;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
    f32 s;
    f32 t;
} Vertex;

typedef struct {
    u32 g_no;
    u16 hv;
    s16 off_x;
    s16 off_y;
    f32 zx;
    f32 zy;
    s32 prio;
    s32 trans;
    OPTW_Color col;
} OPTW;

typedef struct {
    s8 r_no_0;
    s8 r_no_1;
    s8 dir;
    s8 ctr;
    s16 bg_no;
    u16 blk_no;
    s32 prio;
    OPTW_Small map[4][4];
} OPBW;

typedef struct {
    s8 r_no_0;
    s8 r_no_1;
    s8 r_no_2;
    s8 old_rno;
    s16 index;
    s16 mv_ctr;
    s16 free_work;
    s16 dummy;
    OPBW bgw[3];
} OP_W;

typedef struct {
    u16 bg_h_shift;
    u16 bg_v_shift;
} BackgroundParameters;

typedef struct {
    u8 bytes[0x64];
} MultiTexture;

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
    f32 x;
    f32 y;
} PAL_CURSOR_P;

typedef struct {
    u32 color;
} PAL_CURSOR_COL;

typedef struct {
    PAL_CURSOR_P *p;
    PAL_CURSOR_COL *col;
    PAL_CURSOR_COL *tex;
    u32 num;
} PAL_CURSOR;

typedef struct {
    u8 raw0[2];
    s16 fam_no;
    u8 raw1[6];
    s16 position_x;
    s16 position_y;
    u8 raw2[0xA];
    XY xy[2];
    XY wxy[2];
    u8 raw3[0xC];
    s32 zuubun;
    u8 raw4[0x10];
    s16 pos_x_work;
    s16 pos_y_work;
    s8 rewrite_flag;
    u8 raw5[3];
    XY hos_xy[2];
    u8 raw6[8];
    s16 free;
    s16 frame_deff;
    s16 r_limit;
    u8 raw7[2];
    s16 l_limit;
    u8 raw8[0x26];
} BGW;

typedef struct {
    u8 raw0[0x10];
    u8 scno;
    u8 raw1[8];
    s8 chase_flag;
    u8 raw2[2];
    s16 pos_offset;
    s16 quake_x_index;
    u8 raw3[0x18];
    BGW bgw[7];
} BG;

#if defined(__i386__)
_Static_assert(sizeof(OPTW_Small) == 0x10, "OPTW_Small");
_Static_assert(sizeof(Vertex) == 0x14, "Vertex");
_Static_assert(sizeof(OPTW) == 0x20, "OPTW");
_Static_assert(__builtin_offsetof(OPTW, hv) == 4, "OPTW.hv");
_Static_assert(__builtin_offsetof(OPTW, off_x) == 6, "OPTW.off_x");
_Static_assert(__builtin_offsetof(OPTW, off_y) == 8, "OPTW.off_y");
_Static_assert(__builtin_offsetof(OPTW, zx) == 0xC, "OPTW.zx");
_Static_assert(__builtin_offsetof(OPTW, zy) == 0x10, "OPTW.zy");
_Static_assert(__builtin_offsetof(OPTW, prio) == 0x14, "OPTW.prio");
_Static_assert(__builtin_offsetof(OPTW, trans) == 0x18, "OPTW.trans");
_Static_assert(__builtin_offsetof(OPTW, col) == 0x1C, "OPTW.col");
_Static_assert(sizeof(OPBW) == 0x10C, "OPBW");
_Static_assert(sizeof(OP_W) == 0x330, "OP_W");
_Static_assert(__builtin_offsetof(OPBW, map) == 0xC, "OPBW.map");
_Static_assert(__builtin_offsetof(OP_W, bgw) == 0xC, "OP_W.bgw");
_Static_assert(__builtin_offsetof(Texture, textures) == 0x10, "Texture.textures");
_Static_assert(sizeof(BackgroundParameters) == 4, "BackgroundParameters");
_Static_assert(sizeof(MultiTexture) == 0x64, "MultiTexture");
_Static_assert(sizeof(XY) == 4, "XY");
_Static_assert(__builtin_offsetof(XY, disp.pos) == 2, "XY.disp.pos");
_Static_assert(sizeof(BGW) == 0x90, "BGW");
_Static_assert(sizeof(BG) == 0x428, "BG");
_Static_assert(__builtin_offsetof(BGW, fam_no) == 0x2, "fam_no");
_Static_assert(__builtin_offsetof(BGW, position_x) == 0xA, "position_x");
_Static_assert(__builtin_offsetof(BGW, xy) == 0x18, "xy");
_Static_assert(__builtin_offsetof(BGW, wxy) == 0x20, "wxy");
_Static_assert(__builtin_offsetof(BGW, zuubun) == 0x34, "zuubun");
_Static_assert(__builtin_offsetof(BGW, pos_x_work) == 0x48, "pos_x_work");
_Static_assert(__builtin_offsetof(BGW, rewrite_flag) == 0x4C, "rewrite_flag");
_Static_assert(__builtin_offsetof(BGW, hos_xy) == 0x50, "hos_xy");
_Static_assert(__builtin_offsetof(BGW, free) == 0x60, "free");
_Static_assert(__builtin_offsetof(BGW, frame_deff) == 0x62, "frame_deff");
_Static_assert(__builtin_offsetof(BGW, r_limit) == 0x64, "r_limit");
_Static_assert(__builtin_offsetof(BGW, l_limit) == 0x68, "l_limit");
_Static_assert(sizeof(MVXY) == 0x18, "MVXY");
_Static_assert(sizeof(PAL_CURSOR_P) == 8, "PAL_CURSOR_P");
_Static_assert(sizeof(PAL_CURSOR) == 0x10, "PAL_CURSOR");
_Static_assert(__builtin_offsetof(MVXY, d) == 8, "MVXY.d");
_Static_assert(__builtin_offsetof(BG, scno) == 0x10, "scno");
_Static_assert(__builtin_offsetof(BG, chase_flag) == 0x19, "chase_flag");
_Static_assert(__builtin_offsetof(BG, pos_offset) == 0x1C, "pos_offset");
_Static_assert(__builtin_offsetof(BG, quake_x_index) == 0x1E, "quake_x_index");
_Static_assert(__builtin_offsetof(BG, bgw) == 0x38, "bgw");
#endif

extern u8 Country;
extern s16 Opening_Now;
extern PPGDataList ppgTitleList;
extern Texture ppgTitleTex;
extern s16 title_tex_flag;
extern s32 dword_0032F858;
extern OP_W op_w;
extern s16 op_timer0;
extern const f32 title00[];
extern f32 scr_sc;
extern s16 music_scene;
extern s16 music_time;
extern s16 op_plmove_timer;
extern const s16 sound_time_tbl[];
extern const s16 sound_trg_tbl[];
extern u8 gSeqStatus[1];
extern PPGDataList ppgOpnBgList;
extern Texture ppgOpnBgTex;
extern const s16 optsr_tbl[];
extern u8 No_Trans;
extern u16 Screen_Switch;
extern BackgroundParameters bg_prm[3];
extern MultiTexture mts[];
extern BG bg_w;
extern s16 op_end_flag;
extern s16 bg_stop;
extern s16 base_y_pos;
extern s8 akebono_flag;
extern s8 aku_flag;
extern s8 sa_pa_flag;
extern s8 bg_app;
extern s8 bg_app_stop;
extern s16 op_demo_index;
extern s16 op_sound_status;
extern u16 Game_timer;
extern const s16 op_change_sound_tbl[];
extern void (*opening_move_jp[19])(void);

extern void ppgSetupCurrentDataList(PPGDataList *dlist);
extern s16 Search_ramcnt_type(u8 kokey);
extern u32 Get_size_data_ramcnt_key(s16 key);
extern void *Get_ramcnt_address(s16 key);
extern void sub_0004384A(const char *tag);
extern u32 load_it_use_any_key2(s32 id, void **adrs, s16 *key, s32 arg3, s32 arg4);
extern void flLogOut(const char *text);
extern s32 ppgSetupTexChunk_1st(Texture *tch, u8 *adrs, s32 size, s32 ixNum1st, s32 ixNums, s32 ar, s32 arcnt);
extern s32 ppgSetupTexChunk_2nd(Texture *tch, s32 ixNum);
extern s32 ppgSetupTexChunk_3rd(Texture *tch, s32 ixNum, u32 attribute);
extern void sub_00097103(s16 key);
extern void ppgSourceDataReleased(PPGDataList *dlist);
extern void setTexAdrsMode(s32 mode);
extern void setFilterMode(s32 mode);
extern void Zoom_Value_Set(u16 zadd);
extern void Frame_Up(u16 x, u16 y, u16 add);
extern void Frame_Down(u16 x, u16 y, u16 add);
extern void Put_char(const f32 *ptr, u32 indexG, u16 prio, s16 x, s16 y, f32 zx, f32 zy);
extern void Scrn_Renew(void);
extern void Irl_Family(void);
extern void Irl_Scrn(void);
extern void scr_calc(u8 bgnm);
extern s32 ppgWriteQuadUseTrans(Vertex *pos, u32 col, void *tb, s32 tix, s32 cix, s32 flip, s32 pal);
extern s32 ppgReleaseTextureHandle(Texture *tch, s32 ixNum);
extern Palette *palGetChunkGhostCP3(void);
extern void make_texcash_work(s32 index);
extern void mlt_obj_melt2(MultiTexture *obj, s32 size);
extern void Family_Init(void);
extern void Scrn_Pos_Init(void);
extern void Zoomf_Init(void);
extern void sub_000AF4C2(s32 bits);
extern void sub_000AF4AA(s32 bits);
extern void Scrn_Move_Set(s8 bgnm, s16 x, s16 y);
extern void effect_E1_init(s32 a, s32 b, s32 c);
extern void sub_0004AFFA(s32 kind);
extern void sub_000AF47B(s32 fmnm, s32 x, s32 y);
extern void Disp_Copyright(void);
extern void Go_BGM(void);
extern OPBW *opw_ptr;
extern BGW *bgw_ptr;
extern MVXY op_bg_mvxy[3];
extern s16 op_obj_disp;
extern s8 op_scrn_end;
extern const s16 op_104_sound[7];
extern const s16 op_quake_y_tbl0[16];
extern const s32 ot_bg0_0004_tbl[6];
extern const s16 op_bg0_0005_tbl[16];
extern const s32 ot_bg0_0015_tbl[6];
extern f32 Frame_Zoom_X;
extern f32 Frame_Zoom_Y;
extern f32 PrioBase[];
extern void njDrawPolygon2D(PAL_CURSOR *poly, s32 n, f32 pri, s32 attr, s32 kind);
extern u8 D_No[4];
extern void ToneDown(u8 tone, u8 priority);
extern void effect_F6_init(s32 id);
extern void effect_48_init(s32 id);
extern void effect_36_init(s32 id);
extern s32 FadeIn(u8 type, u8 step, u8 priority);
extern void FadeInit(void);
extern s32 FadeOut(u8 type, u8 step, u8 priority);
extern void reset_dma_group(s32 group);
extern void purge_texcash_work(s32 index);
extern void TexRelease_OP(void);
extern s32 Request_Fade(u16 fade_code);
extern s32 Check_Fade_Complete(void);

static const f32 *title[2] = { title00, title00 };

void TITLE_Init(void) {
    void *loadAdrs;
    u32 loadSize;
    s16 key;
    s32 id;

    sub_0004384A("\nMAIN TITLE\n\n");
    Opening_Now = 0;
    ppgTitleList.tex = &ppgTitleTex;
    ppgTitleList.pal = 0;
    ppgSetupCurrentDataList(&ppgTitleList);

    if (Country == 1 || Country == 2) {
        id = 0x54;
    } else {
        id = 0x53;
    }

    loadSize = load_it_use_any_key2(id, &loadAdrs, &key, 2, 1);

    if (loadSize == 0) {
        flLogOut("メインタイトルのテクスチャが読み込めませんでした。\n");

        for (;;) {
        }
    }

    ppgSetupTexChunk_1st(0, loadAdrs, loadSize, 601, 1, 0, 0);
    ppgSetupTexChunk_2nd(0, 601);
    ppgSetupTexChunk_3rd(0, 601, 1);
    sub_00097103(key);
    ppgSourceDataReleased(0);
    title_tex_flag = 1;
    dword_0032F858 = 1;
    op_w.r_no_0 = 0;
}

s16 TITLE_Move(u16 type) {
    ppgSetupCurrentDataList(&ppgTitleList);
    setTexAdrsMode(0);
    setFilterMode(0);

    switch (type) {
    case 0:
        switch (op_w.r_no_0) {
        case 0:
            op_w.r_no_0 = (s8)(op_w.r_no_0 + 1);
            Zoom_Value_Set(0x40);
            Frame_Up(192, 112, 0x13);
            op_timer0 = 10;
            break;

        case 1:
            op_timer0 = (s16)(op_timer0 - 1);

            if (op_timer0 <= 0) {
                op_w.r_no_0 = (s8)(op_w.r_no_0 + 1);
                op_timer0 = 19;
            }

            break;

        case 2:
            if (op_timer0-- >= 0) {
                Frame_Down(0xC0, 0x70, 1);
            } else {
                op_w.r_no_0 = (s8)(op_w.r_no_0 + 1);
            }

            break;

        default:
            Zoom_Value_Set(0x40);
            break;
        }

        Put_char(title[type], 601, 2, 192, 96, scr_sc, scr_sc);
        return 0;

    case 1:
        Put_char(title[type], 601, 2, 192, 96, 1.0f, 1.0f);
        return 0;

    default:
        return 0;
    }
}

void sound_trg_init(void) {
    music_time = 0;
    music_scene = 0;
}

void sound_trg_move(void) {
    s16 buff;

    if (op_plmove_timer >= sound_time_tbl[music_scene]) {
        buff = sound_trg_tbl[music_scene];

        if (buff >= 0) {
            music_scene = (s16)(music_scene + 1);
            gSeqStatus[0] = (u8)buff;
        }
    }
}

void put_chr2(OPTW *optw) {
    Vertex tex[4];

    if (No_Trans) {
        return;
    }

    tex[0].x = Frame_Zoom_X * ((s32)optw->off_x * optw->zx);
    tex[0].y = Frame_Zoom_Y * ((s32)optw->off_y * optw->zy);
    tex[3].x = Frame_Zoom_X * ((optw->off_x + 0x100) * optw->zx);
    tex[3].y = Frame_Zoom_Y * ((optw->off_y + 0x100) * optw->zy);
    tex[0].z = tex[3].z = PrioBase[optw->prio];
    ppgWriteQuadUseTrans(tex, optw->col.full, (void *)0, optw->g_no, -1, optw->hv, 300);
}

void opbg_trans(OPBW *opbw, s16 x, s16 y) {
    OPTW optw;
    s16 i;
    s16 i0;
    s16 i1;
    s16 j;
    s16 j0;
    s16 j1;
    s16 xx;
    s16 yy;

    xx = (x < 0) ? 0 : x;
    yy = (y < 0) ? 0 : y;
    xx = (x > 1023) ? 1023 : xx;
    yy = (y > 1023) ? 1023 : yy;
    i0 = (s16)(xx >> 8);
    i1 = (s16)(((xx + 383) >> 8) & 3);
    j1 = (s16)(((yy + 223) >> 8) & 3);
    j0 = (s16)(yy >> 8);

    for (i = i0; i <= i1; i++) {
        for (j = j0; j <= j1; j++) {
            if (opbw->map[i][j].g_no != 0) {
                optw.g_no = opbw->map[i][j].g_no;
                optw.hv = opbw->map[i][j].hv;
                optw.off_x = (s16)((i << 8) - x);
                optw.off_y = (s16)((y + 224) - ((j << 8) + 256));
                optw.zx = optw.zy = scr_sc;
                optw.prio = opbw->prio;
                optw.trans = opbw->map[i][j].trans;
                optw.col.full = opbw->map[i][j].col.full;
                put_chr2(&optw);
            }
        }
    }
}

void OPBG_Trans(void) {
    if (No_Trans) {
        return;
    }

    setTexAdrsMode(1);
    setFilterMode(0);
    ppgSetupCurrentDataList(&ppgOpnBgList);
    Scrn_Renew();
    Irl_Family();
    Irl_Scrn();
    scr_calc(0);
    scr_calc(1);
    scr_calc(2);

    if (Screen_Switch & 1) {
        opbg_trans(&op_w.bgw[0], (s16)bg_prm[0].bg_h_shift, (s16)bg_prm[0].bg_v_shift);
    }

    if (Screen_Switch & 2) {
        opbg_trans(&op_w.bgw[1], (s16)bg_prm[1].bg_h_shift, (s16)bg_prm[1].bg_v_shift);
    }

    if (Screen_Switch & 4) {
        opbg_trans(&op_w.bgw[2], (s16)bg_prm[2].bg_h_shift, (s16)bg_prm[2].bg_v_shift);
    }
}

s16 oh_tsr_ck(s32 blk_no) {
    s16 i;

    for (i = 0; optsr_tbl[i] != -1; i++) {
        if (optsr_tbl[i] == (s16)blk_no) {
            return 1;
        }
    }

    return 0;
}

void oh_reload_tex(OPBW *opbw, s32 blk_no, s16 mapx, s16 mapy) {
    if (!oh_tsr_ck(blk_no) && (opbw->map[mapx][mapy].g_no != (u32)(blk_no + 0x259))) {
        if (opbw->map[mapx][mapy].g_no && !oh_tsr_ck(opbw->map[mapx][mapy].g_no - 0x259)) {
            ppgReleaseTextureHandle(&ppgOpnBgTex, opbw->map[mapx][mapy].g_no);
        }

        opbw->map[mapx][mapy].ok = 1;
    }
}

void oh_bg_blk_w(OPBW *opbw, s32 blk_no, s16 mapx, s16 mapy, s32 trans) {
    oh_reload_tex(opbw, blk_no, mapx, mapy);
    opbw->map[mapx][mapy].g_no = blk_no + 0x259;
    opbw->map[mapx][mapy].hv = 0;
    opbw->map[mapx][mapy].trans = trans;
    opbw->blk_no = (u16)blk_no;
    opbw->map[mapx][mapy].col.full = -1;
}

void oh_bg_blk_wh(OPBW *opbw, s32 blk_no, s16 mapx, s16 mapy, s32 trans) {
    oh_reload_tex(opbw, blk_no, mapx, mapy);
    opbw->map[mapx][mapy].g_no = blk_no + 0x259;
    opbw->map[mapx][mapy].hv = 1;
    opbw->map[mapx][mapy].trans = trans;
    opbw->blk_no = (u16)blk_no;
    opbw->map[mapx][mapy].col.full = -1;
}

void oh_bg_blk_wv(OPBW *opbw, s32 blk_no, s16 mapx, s16 mapy, s32 trans) {
    oh_reload_tex(opbw, blk_no, mapx, mapy);
    opbw->map[mapx][mapy].g_no = blk_no + 0x259;
    opbw->map[mapx][mapy].hv = 2;
    opbw->map[mapx][mapy].trans = trans;
    opbw->blk_no = (u16)blk_no;
    opbw->map[mapx][mapy].col.full = -1;
}

void oh_bg_blk_whv(OPBW *opbw, s32 blk_no, s16 mapx, s16 mapy, s32 trans) {
    oh_reload_tex(opbw, blk_no, mapx, mapy);
    opbw->map[mapx][mapy].g_no = blk_no + 0x259;
    opbw->map[mapx][mapy].hv = 3;
    opbw->map[mapx][mapy].trans = trans;
    opbw->blk_no = (u16)blk_no;
    opbw->map[mapx][mapy].col.full = -1;
}

void opening_init(void) {
    s16 i;
    s16 j;
    s16 k;

    op_w.r_no_0 = 0;
    op_w.r_no_1 = 0;
    op_w.r_no_2 = 0;
    op_w.index = 0;
    op_w.mv_ctr = 0;
    op_w.bgw[0].blk_no = op_w.bgw[1].blk_no = op_w.bgw[2].blk_no = 0;
    op_w.bgw[0].prio = 75;
    op_w.bgw[1].prio = 80;
    op_w.bgw[2].prio = 85;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            for (k = 0; k < 4; k++) {
                op_w.bgw[i].map[j][k].g_no = 0;
                op_w.bgw[i].map[j][k].trans = 0;
                op_w.bgw[i].map[j][k].hv = 0;
                op_w.bgw[i].map[j][k].ok = 0;
            }
        }
    }
}

void op_work_clear(void) {
    s16 i;

    for (i = 0; i < 3; i++) {
        op_w.bgw[i].r_no_0 = 0;
        op_w.bgw[i].r_no_1 = 0;
    }
}

void OPBG_Init(void) {
    void *loadAdrs;
    u32 loadSize;
    s16 i;
    s16 key;

    sub_0004384A("\nOPENING\n\n");
    ppgOpnBgList.tex = &ppgOpnBgTex;
    ppgOpnBgList.pal = palGetChunkGhostCP3();
    ppgSetupCurrentDataList(&ppgOpnBgList);
    key = Search_ramcnt_type(0x1D);

    if (key == 0) {
        flLogOut("オープニングデモテクスチャが読み込まれていません。\n");

        for (;;) {
        }
    }

    loadSize = Get_size_data_ramcnt_key(key);
    loadAdrs = Get_ramcnt_address(key);
    ppgSetupTexChunk_1st(0, loadAdrs, loadSize, 602, 91, 0, 0);

    for (i = 0; i < ppgOpnBgTex.textures; i++) {
        ppgSetupTexChunk_2nd(0, i + 602);
        ppgSetupTexChunk_3rd(0, i + 602, 1);
    }

    Opening_Now = 1;
    make_texcash_work(9);
    mlt_obj_melt2(&mts[9], 0x8C40);
    sound_trg_init();
    opening_init();
    Zoom_Value_Set(0x40);
}

void opning_init_00000(void) {
    s16 i;
    s32 span;

    op_w.r_no_1 = (s8)(op_w.r_no_1 + 1);
    op_end_flag = 0;
    Family_Init();
    Scrn_Pos_Init();
    Zoomf_Init();
    Zoom_Value_Set(0x40);
    bg_w.scno = 3;
    bg_w.pos_offset = 192;

    for (i = 0; i < 6; i++) {
        bg_w.bgw[i].pos_x_work = bg_w.bgw[i].pos_y_work = 0;
        bg_w.bgw[i].rewrite_flag = 0;
        bg_w.bgw[i].fam_no = 0;
        bg_w.bgw[i].zuubun = 0;
        bg_w.bgw[i].wxy[0].cal = 0x02000000;
        bg_w.bgw[i].xy[1].cal = 0;
        bg_w.bgw[i].wxy[0].cal = 0x02000000;
        bg_w.bgw[i].wxy[1].cal = 0;
        bg_w.bgw[i].hos_xy[0].cal = 0x02000000;
        bg_w.bgw[i].hos_xy[1].cal = 0;
        span = (s32)((u16)bg_w.pos_offset | ((u32)(u16)bg_w.quake_x_index << 16));
        bg_w.bgw[i].position_x = (s16)(0x200 - span);
        bg_w.bgw[i].position_y = 0;
    }

    for (i = 0; i < 3; i++) {
        bg_w.bgw[i].fam_no = i;
        op_w.bgw[i].r_no_0 = 0;
        op_w.bgw[i].r_no_1 = 0;
        op_w.bgw[i].bg_no = i;
    }

    op_w.r_no_2 = 0;
    op_end_flag = 0;
    bg_stop = 0;
    akebono_flag = 0;
    aku_flag = 0;
    sa_pa_flag = 0;
    bg_app = 0;
    bg_app_stop = 0;
    bg_w.chase_flag = 0;
}

void opning_init_01000(void) {
    op_w.r_no_1 = (s8)(op_w.r_no_1 + 1);
    sub_000AF4C2(0xF);
    sub_000AF4C2(0xF);
    op_w.free_work = 8;
    Scrn_Move_Set(0, 0x200 - bg_w.pos_offset, 0x200);
    base_y_pos = 40;
}

void opning_init_02000(void) {
    op_w.free_work = (s16)(op_w.free_work - 1);

    if (op_w.free_work < 0) {
        op_w.r_no_0 = (s8)(op_w.r_no_0 + 1);
        op_w.r_no_1 = 0;
        op_w.r_no_2 = 0;
    }

    Scrn_Move_Set(0, 0x200 - bg_w.pos_offset, 0x200);
    op_demo_index = 0;
    gSeqStatus[0] = 0;
    op_w.index = 0;
    op_sound_status = 0;
    op_plmove_timer = 2;
}

void opening_move(void) {
    s16 work2;

    op_plmove_timer = (s16)(op_plmove_timer + 1);
    sound_trg_move();

    if (op_w.r_no_1 < 18) {
        work2 = (s16)gSeqStatus[0];

        if (op_sound_status != work2) {
            if (work2 == op_change_sound_tbl[op_w.r_no_1]) {
                op_w.r_no_1 = (s8)(op_w.r_no_1 + 1);
                op_w.r_no_2 = 0;
                op_work_clear();
            }
        }
    }

    opening_move_jp[op_w.r_no_1]();
    op_sound_status = (s16)gSeqStatus[0];
}

void op_bg1_0000(s16 /* unused */) {
    switch (opw_ptr->r_no_0) {
    case 0:
        opw_ptr->r_no_0 = 1;
        bgw_ptr->wxy[0].disp.pos = 0x200;
        bgw_ptr->xy[1].disp.pos = 0;
        sub_000AF4C2(2);
        break;

    case 1:
    case 2:
        break;
    }
}

void op_bg1_0001(s16 r_index) {
    switch (opw_ptr->r_no_0) {
    case 0:
        opw_ptr->r_no_0 = 1;
        sub_000AF4AA(1 << (u8)bgw_ptr->fam_no);
        bgw_ptr->wxy[0].cal = 0x02000000;
        bgw_ptr->xy[1].cal = 0;

        switch (r_index) {
        case 0x37:
            oh_bg_blk_w(&op_w.bgw[1], 1, 1, 0, 0);
            oh_bg_blk_w(&op_w.bgw[1], 2, 2, 0, 0);
            break;

        case 0x38:
            oh_bg_blk_w(&op_w.bgw[1], 3, 1, 0, 0);
            oh_bg_blk_w(&op_w.bgw[1], 4, 2, 0, 0);
            break;
        }

        break;

    case 1:
        break;
    }
}

void op_bg1_0002(s16 r_index) {
    switch (opw_ptr->r_no_0) {
    case 0:
        opw_ptr->r_no_0 = (s8)(opw_ptr->r_no_0 + 1);
        sub_000AF4AA(1 << (u8)bgw_ptr->fam_no);

        switch (r_index) {
        case 0x3C:
            bgw_ptr->wxy[0].cal = 0x01000000;
            bgw_ptr->xy[1].cal = 0;
            oh_bg_blk_w(&op_w.bgw[1], 7, 0, 0, 0);
            oh_bg_blk_w(&op_w.bgw[1], 8, 1, 0, 0);
            oh_bg_blk_w(&op_w.bgw[1], 9, 2, 0, 0);
            op_bg_mvxy[bgw_ptr->fam_no].a[0].sp = 0xC0000;
            op_bg_mvxy[bgw_ptr->fam_no].d[0].sp = 0;
            bgw_ptr->r_limit = 0x1E0;
            break;
        }

        break;

    case 1:
        op_bg_mvxy[bgw_ptr->fam_no].a[0].sp += op_bg_mvxy[bgw_ptr->fam_no].d[0].sp;
        bgw_ptr->wxy[0].cal += op_bg_mvxy[bgw_ptr->fam_no].a[0].sp;

        if (bgw_ptr->wxy[0].disp.pos >= bgw_ptr->r_limit) {
            opw_ptr->r_no_0 = (s8)(opw_ptr->r_no_0 + 1);
        }

        break;

    case 2:
        break;
    }
}

void op_bg1_0003(s16 r_index) {
    switch (opw_ptr->r_no_0) {
    case 0:
        opw_ptr->r_no_0 = (s8)(opw_ptr->r_no_0 + 1);
        sub_000AF4AA(1 << (u8)bgw_ptr->fam_no);

        switch (r_index) {
        case 83:
            bgw_ptr->wxy[0].cal = 0x2200000;
            bgw_ptr->xy[1].cal = 0;
            oh_bg_blk_w(op_w.bgw, 0x10, 1, 0, 0);
            oh_bg_blk_w(op_w.bgw, 0x11, 2, 0, 0);
            op_bg_mvxy[bgw_ptr->fam_no].a[0].sp = 0x80000;
            op_bg_mvxy[bgw_ptr->fam_no].d[0].sp = -0x8000;
            bgw_ptr->r_limit = 0x200;
            break;

        case 62:
            bgw_ptr->wxy[0].cal = 0x1E00000;
            bgw_ptr->xy[1].cal = 0;
            oh_bg_blk_w(&op_w.bgw[1], 0xA, 0, 0, 0);
            oh_bg_blk_w(&op_w.bgw[1], 0xB, 1, 0, 0);
            oh_bg_blk_w(&op_w.bgw[1], 0xC, 2, 0, 0);
            op_bg_mvxy[bgw_ptr->fam_no].a[0].sp = (s32)0xFFF80000;
            op_bg_mvxy[bgw_ptr->fam_no].d[0].sp = 0;
            break;
        }

        break;

    case 1:
        op_bg_mvxy[bgw_ptr->fam_no].a[0].sp += op_bg_mvxy[bgw_ptr->fam_no].d[0].sp;
        bgw_ptr->wxy[0].cal += op_bg_mvxy[bgw_ptr->fam_no].a[0].sp;

        if (bgw_ptr->wxy[0].disp.pos <= bgw_ptr->l_limit) {
            opw_ptr->r_no_0 = (s8)(opw_ptr->r_no_0 + 1);
        }

        break;

    case 2:
        break;
    }
}

void op_bg2_0000(void) {
    switch (opw_ptr->r_no_0) {
    case 0:
        opw_ptr->r_no_0 = (s8)(opw_ptr->r_no_0 + 1);
        bgw_ptr->wxy[0].disp.pos = 0x200;
        bgw_ptr->xy[1].disp.pos = 0;
        break;

    case 1:
        bgw_ptr->wxy[0].cal -= 0x10000;
        break;

    case 2:
        break;
    }
}

void op_bg2_0001(void) {
    switch (opw_ptr->r_no_0) {
    case 0:
        opw_ptr->r_no_0 = 1;
        bgw_ptr->wxy[0].disp.pos = 0x200;
        bgw_ptr->xy[1].disp.pos = 0;
        break;

    case 1:
        break;
    }
}

void op_bg2_0002(void) {
    switch (opw_ptr->r_no_0) {
    case 0:
        opw_ptr->r_no_0 = (s8)(opw_ptr->r_no_0 + 1);
        bgw_ptr->wxy[0].disp.pos = 0x200;
        bgw_ptr->xy[1].disp.pos = 0;
        break;

    case 1:
        bgw_ptr->xy[1].cal += 0x10000;
        break;

    case 2:
        break;
    }
}

void op_bg2_0003(void) {
    switch (opw_ptr->r_no_0) {
    case 0:
        opw_ptr->r_no_0 = (s8)(opw_ptr->r_no_0 + 1);
        bgw_ptr->wxy[0].disp.pos = 0x200;
        bgw_ptr->xy[1].disp.pos = 0;
        break;

    case 1:
        bgw_ptr->wxy[0].cal += 0x10000;
        break;

    case 2:
        break;
    }
}

void opening_title_01(void) {
    s16 pos_work_x;
    s32 span;

    effect_E1_init(1, 0, 1);
    effect_E1_init(0, 0, 1);
    sub_0004AFFA(0x10);
    sub_0004AFFA(0x11);
    sub_0004AFFA(0x12);
    sub_0004AFFA(9);
    Disp_Copyright();
    sub_000AF4C2(0xF);
    Scrn_Move_Set(0, 0x200 - bg_w.pos_offset, 0);
    Scrn_Move_Set(1, 0x200 - bg_w.pos_offset, 0);
    span = (s32)((u16)bg_w.pos_offset | ((u32)(u16)bg_w.quake_x_index << 16));
    pos_work_x = (s16)(span - 0x200);
    sub_000AF47B(1, pos_work_x, 0x300);
    op_end_flag = 1;
    bg_stop = 0;
    akebono_flag = 0;
    aku_flag = 0;
    sa_pa_flag = 0;
    bg_app = 0;
    bg_w.chase_flag = 0;
}

void op_scrn_pos_set2(s16 bg_no) {
    s16 pos_x;
    s16 pos_y;

    pos_x = bg_w.bgw[bg_no].wxy[0].disp.pos;
    pos_y = bg_w.bgw[bg_no].xy[1].disp.pos;
    Scrn_Move_Set(bg_no, pos_x - bg_w.pos_offset, pos_y);
}

void Bg_Family_Set_op(void) {
    s16 pos_work_x;
    s16 pos_work_y;
    s16 i;
    s32 wx;
    s32 span;
    s32 yspan;

    for (i = 0; i < 4; i++) {
        bg_w.bgw[i].xy[0].cal = bg_w.bgw[i].wxy[0].cal;
        bg_w.bgw[i].position_y = bg_w.bgw[i].xy[1].disp.pos;
        bg_w.bgw[i].position_x = (s16)(bg_w.bgw[i].wxy[0].disp.pos - bg_w.pos_offset);
        pos_work_x = (s16)(-bg_w.bgw[i].position_x);
        pos_work_y = bg_w.bgw[i].position_y;
        pos_work_y = (s16)(0x300 - (pos_work_y & 0x3FF));
        sub_000AF47B(i + 1, pos_work_x, pos_work_y);
    }

    bg_w.bgw[5].position_y = bg_w.bgw[5].xy[1].disp.pos;
    wx = (s32)((u16)bg_w.bgw[5].wxy[0].disp.pos | ((u32)(u16)bg_w.bgw[5].wxy[1].disp.low << 16));
    span = (s32)((u16)bg_w.pos_offset | ((u32)(u16)bg_w.quake_x_index << 16));
    bg_w.bgw[5].position_x = (s16)(wx - span);
    pos_work_x = (s16)(-bg_w.bgw[5].position_x);
    yspan = (s32)((u16)bg_w.bgw[5].xy[1].disp.pos | ((u32)(u16)bg_w.bgw[5].wxy[0].disp.low << 16));
    pos_work_y = (s16)(0x300 - (s32)((u32)yspan & 0xFFFF03FFu));
    sub_000AF47B(6, pos_work_x, pos_work_y);
}

void opening_init2(void) {
    Game_timer = 0;

    switch (op_w.r_no_1) {
    case 0:
        opning_init_00000();
        break;

    case 1:
        opning_init_01000();
        break;

    case 2:
        opning_init_02000();
        break;
    }
}

void opening_title(void) {
    switch (op_w.r_no_1) {
    case 0:
        op_w.r_no_1 = (s8)(op_w.r_no_1 + 1);
        break;

    case 1:
        op_w.free_work = (s16)(op_w.free_work - 1);

        if (op_w.free_work <= 0) {
            opening_title_01();
            op_w.r_no_1 = (s8)(op_w.r_no_1 + 1);
        }

        break;

    case 2:
        break;
    }
}

s16 oh_opening_demo(void) {
    void (*opening_demo_jp[3])(void) = { opening_init2, opening_move, opening_title };

    Game_timer = (u16)(Game_timer + 1);
    opening_demo_jp[op_w.r_no_0]();
    Bg_Family_Set_op();
    return op_end_flag;
}

void op_bg1_move(s16 r_index) {
    opw_ptr = &op_w.bgw[1];
    bgw_ptr = &bg_w.bgw[1];

    switch (r_index) {
    case 55:
    case 56:
        op_bg1_0001(r_index);
        break;

    case 60:
        op_bg1_0002(r_index);
        break;

    case 62:
        op_bg1_0003(r_index);
        break;

    default:
        op_bg1_0000(r_index);
        break;
    }

    op_scrn_pos_set2(1);
}

void op_bg2_move(s16 r_index) {
    opw_ptr = &op_w.bgw[2];
    bgw_ptr = &bg_w.bgw[2];

    switch (r_index) {
    case 0:
    case 24:
        op_bg2_0000();
        break;

    case 2:
        op_bg2_0002();
        break;

    case 28:
        op_bg2_0003();
        break;

    default:
        op_bg2_0001();
        break;
    }

    op_scrn_pos_set2(2);
}

void op_bg0_0000(s16 /* unused */) {
    switch (opw_ptr->r_no_0) {
    case 0:
        opw_ptr->r_no_0 = 1;
        sub_000AF4C2(1);
        bgw_ptr->wxy[0].cal = 0x2000000;
        bgw_ptr->xy[1].cal = 0;
        break;
    }

    op_scrn_pos_set2(0);
}

void op_bg0_0001(s16 r_index) {
    switch (opw_ptr->r_no_0) {
    case 0:
        opw_ptr->r_no_0 = (s8)(opw_ptr->r_no_0 + 1);
        bgw_ptr->free = 1;
        bgw_ptr->frame_deff = 0;
        sub_000AF4AA(1);
        bgw_ptr->wxy[0].cal = 0x2000000;
        bgw_ptr->xy[1].cal = 0;

        switch (r_index) {
        case 0x1:
            oh_bg_blk_w(op_w.bgw, 0x30, 1, 0, 1);
            oh_bg_blk_w(op_w.bgw, 0x31, 2, 0, 1);
            break;

        case 0x3:
            oh_bg_blk_wv(op_w.bgw, 0x45, 1, 0, 1);
            oh_bg_blk_wv(op_w.bgw, 0x46, 2, 0, 1);
            op_w.bgw[0].map[1][0].col.full = -0x01000000;
            op_w.bgw[0].map[2][0].col.full = -0x01000000;
            break;

        case 0x4:
        case 0x16:
        case 0x21:
            oh_bg_blk_wh(op_w.bgw, 0x35, 1, 0, 1);
            oh_bg_blk_wh(op_w.bgw, 0x34, 2, 0, 1);
            break;

        case 0x7:
            oh_bg_blk_w(op_w.bgw, 0x3F, 1, 0, 1);
            oh_bg_blk_w(op_w.bgw, 0x40, 2, 0, 1);
            break;

        case 0x9:
        case 0x48:
            oh_bg_blk_w(op_w.bgw, 0x36, 1, 0, 1);
            oh_bg_blk_w(op_w.bgw, 0x37, 2, 0, 1);
            break;

        case 0xB:
        case 0x1E:
            oh_bg_blk_wh(op_w.bgw, 0x33, 1, 0, 1);
            oh_bg_blk_wh(op_w.bgw, 0x32, 2, 0, 1);
            break;

        case 0xC:
            oh_bg_blk_w(op_w.bgw, 0x43, 1, 0, 1);
            oh_bg_blk_w(op_w.bgw, 0x44, 2, 0, 1);
            break;

        case 0xF:
            oh_bg_blk_wh(op_w.bgw, 0x3C, 2, 0, 1);
            oh_bg_blk_wh(op_w.bgw, 0x3D, 1, 0, 1);
            break;

        case 0x12:
            oh_bg_blk_wv(op_w.bgw, 0x32, 1, 0, 1);
            oh_bg_blk_wv(op_w.bgw, 0x33, 2, 0, 1);
            break;

        case 0x13:
            oh_bg_blk_w(op_w.bgw, 0x47, 1, 0, 1);
            oh_bg_blk_w(op_w.bgw, 0x48, 2, 0, 1);
            break;

        case 0x15:
            oh_bg_blk_w(op_w.bgw, 0x38, 1, 0, 1);
            op_w.bgw[0].map[2][0].g_no = 0;
            break;

        case 0x1F:
            oh_bg_blk_w(op_w.bgw, 0x49, 1, 0, 1);
            oh_bg_blk_w(op_w.bgw, 0x4A, 2, 0, 1);
            break;

        case 0x20:
            oh_bg_blk_w(op_w.bgw, 0x4B, 1, 0, 1);
            oh_bg_blk_w(op_w.bgw, 0x4C, 2, 0, 1);
            break;

        case 0x23:
            oh_bg_blk_w(op_w.bgw, 0x59, 1, 0, 1);
            oh_bg_blk_w(op_w.bgw, 0x5A, 2, 0, 1);
            break;

        case 0x24:
            oh_bg_blk_w(op_w.bgw, 0x22, 1, 0, 1);
            oh_bg_blk_w(op_w.bgw, 0x23, 2, 0, 1);
            break;

        case 0x26:
        case 0x27:
            oh_bg_blk_w(op_w.bgw, 0x3D, 1, 0, 1);
            oh_bg_blk_w(op_w.bgw, 0x3E, 2, 0, 1);
            break;

        case 0x37:
        case 0x38:
            oh_bg_blk_w(op_w.bgw, 0x4D, 1, 0, 1);
            oh_bg_blk_w(op_w.bgw, 0x4E, 2, 0, 1);
            break;

        case 0x3C:
        case 0x3E:
        case 0x50:
        case 0x52:
            oh_bg_blk_w(op_w.bgw, 0x57, 1, 0, 1);
            oh_bg_blk_w(op_w.bgw, 0x58, 2, 0, 1);
            break;

        case 0x41:
            oh_bg_blk_w(op_w.bgw, 0x4F, 1, 0, 1);
            oh_bg_blk_w(op_w.bgw, 0x50, 2, 0, 1);
            break;

        case 0x42:
            oh_bg_blk_w(op_w.bgw, 0x51, 1, 0, 1);
            oh_bg_blk_w(op_w.bgw, 0x52, 2, 0, 1);
            break;

        case 0x49:
            oh_bg_blk_w(op_w.bgw, 0x53, 1, 0, 1);
            oh_bg_blk_w(op_w.bgw, 0x54, 2, 0, 1);
            break;

        case 0x4B:
            op_w.bgw[0].map[1][0].g_no = 0;
            op_w.bgw[0].map[2][0].g_no = 0;
            oh_bg_blk_whv(op_w.bgw, 0x53, 2, 0, 1);
            oh_bg_blk_whv(op_w.bgw, 0x54, 1, 0, 1);
            break;

        case 0x4C:
            oh_bg_blk_w(op_w.bgw, 0x55, 1, 0, 1);
            oh_bg_blk_w(op_w.bgw, 0x56, 2, 0, 1);
            break;
        }

        /* fallthrough */

    case 1:
        bgw_ptr->free -= 1;

        if (bgw_ptr->free <= 0) {
            bgw_ptr->free = 1;
            bgw_ptr->frame_deff = (s16)(bgw_ptr->frame_deff + 1);
            bgw_ptr->frame_deff &= 0xF;
            bgw_ptr->xy[1].disp.pos += op_quake_y_tbl0[bgw_ptr->frame_deff];
        }

        break;
    }

    op_scrn_pos_set2(0);
}

void op_bg0_0002(s16 r_index) {
    PAL_CURSOR beta_poly;
    PAL_CURSOR_P beta_p[4];
    PAL_CURSOR_COL beta_col[4];

    beta_poly.p = beta_p;
    beta_poly.col = beta_col;
    beta_poly.num = 4;
    beta_col[0].color = beta_col[1].color = beta_col[2].color = beta_col[3].color = 0xFF000000;
    beta_p[0].x = beta_p[2].x = 0.0f;
    beta_p[1].x = beta_p[3].x = 384.0f * Frame_Zoom_X;
    beta_p[0].y = beta_p[1].y = 0.0f;
    beta_p[2].y = beta_p[3].y = 224.0f * Frame_Zoom_Y;

    switch (opw_ptr->r_no_0) {
    case 0:
        opw_ptr->r_no_0 = (s8)(opw_ptr->r_no_0 + 1);
        sub_000AF4C2(1);

        if (r_index == 87) {
            Zoomf_Init();
        }

        bgw_ptr->wxy[0].cal = 0x2000000;
        bgw_ptr->xy[1].cal = 0;
        /* fallthrough */

    case 1:
        if (!No_Trans) {
            njDrawPolygon2D(&beta_poly, 4, PrioBase[75], 0x20, 2);
        }

        break;
    }

    op_scrn_pos_set2(0);
}

void op_bg0_0003(s16 r_index) {
    switch (opw_ptr->r_no_0) {
    case 0:
        opw_ptr->r_no_0 = 1;
        bgw_ptr->free = 1;
        bgw_ptr->frame_deff = 0;
        sub_000AF4AA(1);
        bgw_ptr->wxy[0].cal = 0x2000000;
        bgw_ptr->xy[1].cal = 0;

        switch (r_index) {
        case 0x2A:
            oh_bg_blk_w(op_w.bgw, 0x24, 1, 0, 1);
            oh_bg_blk_w(op_w.bgw, 0x25, 2, 0, 1);
            break;

        case 0x2C:
            oh_bg_blk_w(op_w.bgw, 0x26, 1, 0, 1);
            oh_bg_blk_w(op_w.bgw, 0x27, 2, 0, 1);
            break;

        case 0x2E:
            oh_bg_blk_w(op_w.bgw, 0x28, 1, 0, 1);
            oh_bg_blk_w(op_w.bgw, 0x29, 2, 0, 1);
            break;

        case 0x30:
            oh_bg_blk_w(op_w.bgw, 0x2A, 1, 0, 1);
            oh_bg_blk_w(op_w.bgw, 0x2B, 2, 0, 1);
            break;

        case 0x32:
            oh_bg_blk_w(op_w.bgw, 0x2C, 1, 0, 1);
            oh_bg_blk_w(op_w.bgw, 0x2D, 2, 0, 1);
            break;

        case 0x34:
            oh_bg_blk_w(op_w.bgw, 0x2E, 1, 0, 1);
            oh_bg_blk_w(op_w.bgw, 0x2F, 2, 0, 1);
            break;
        }

        break;

    case 1:
        break;
    }

    op_scrn_pos_set2(0);
}

void op_bg0_0004(s16 /* unused */) {
    PAL_CURSOR beta_poly;
    PAL_CURSOR_P beta_p[4];
    PAL_CURSOR_COL beta_col[4];

    beta_poly.p = beta_p;
    beta_poly.col = beta_col;
    beta_poly.num = 4;
    beta_col[0].color = beta_col[1].color = beta_col[2].color = beta_col[3].color = 0xFF000000;
    beta_p[0].x = beta_p[2].x = 0.0f;
    beta_p[1].x = beta_p[3].x = 384.0f * Frame_Zoom_X;
    beta_p[0].y = beta_p[1].y = 0.0f;
    beta_p[2].y = beta_p[3].y = 224.0f * Frame_Zoom_Y;

    switch (opw_ptr->r_no_0) {
    case 0:
        opw_ptr->r_no_0 = (s8)(opw_ptr->r_no_0 + 1);
        bgw_ptr->free = 1;
        bgw_ptr->frame_deff = 0;
        sub_000AF4C2(1);
        bgw_ptr->wxy[0].cal = 0x2000000;
        bgw_ptr->xy[1].cal = 0;

        if (!No_Trans) {
            njDrawPolygon2D(&beta_poly, 4, PrioBase[75], 0x20, 2);
        }

        break;

    case 1:
        if (!No_Trans) {
            njDrawPolygon2D(&beta_poly, 4, PrioBase[75], 0x20, 2);
        }

        if (!op_scrn_end) {
            break;
        }

        opw_ptr->r_no_0 = (s8)(opw_ptr->r_no_0 + 1);
        bgw_ptr->free = 1;
        bgw_ptr->l_limit = 0;
        /* fallthrough */

    case 2:
        bgw_ptr->free = (s16)(bgw_ptr->free - 1);

        if (bgw_ptr->free <= 0) {
            bgw_ptr->l_limit = (s16)(bgw_ptr->l_limit + 1);

            if (bgw_ptr->l_limit >= 6) {
                opw_ptr->r_no_0 = (s8)(opw_ptr->r_no_0 + 1);
            } else {
                bgw_ptr->free = 1;
                beta_col[0].color = beta_col[1].color = beta_col[2].color = beta_col[3].color =
                    (u32)ot_bg0_0004_tbl[bgw_ptr->l_limit];
            }
        }

        if (!No_Trans) {
            njDrawPolygon2D(&beta_poly, 4, PrioBase[75], 0x20, 2);
        }

        break;

    case 3:
        beta_col[0].color = beta_col[1].color = beta_col[2].color = beta_col[3].color = 0xFF000000;

        if (!No_Trans) {
            njDrawPolygon2D(&beta_poly, 4, PrioBase[75], 0x20, 2);
        }

        break;
    }

    op_scrn_pos_set2(0);
}

void op_bg0_0005(s16 /* unused */) {
    switch (opw_ptr->r_no_0) {
    case 0:
        opw_ptr->r_no_0 = (s8)(opw_ptr->r_no_0 + 1);
        bgw_ptr->free = 1;
        bgw_ptr->frame_deff = 0;
        sub_000AF4AA(1);
        bgw_ptr->wxy[0].cal = 0x2000000;
        bgw_ptr->xy[1].cal = 0;
        oh_bg_blk_w(op_w.bgw, 5, 1, 0, 0);
        oh_bg_blk_w(op_w.bgw, 6, 2, 0, 0);
        Zoom_Value_Set(0x40);
        bgw_ptr->frame_deff = 12;
        Frame_Up(0xC0, 0xE0, bgw_ptr->frame_deff);
        break;

    case 1:
        bgw_ptr->frame_deff = (s16)(bgw_ptr->frame_deff - 2);

        if (bgw_ptr->frame_deff <= 0) {
            opw_ptr->r_no_0 = (s8)(opw_ptr->r_no_0 + 1);
            Zoomf_Init();
            Zoom_Value_Set(0x40);
            bgw_ptr->free = 0;
            bgw_ptr->wxy[0].disp.pos += op_bg0_0005_tbl[bgw_ptr->free];
            bgw_ptr->xy[1].disp.pos += op_bg0_0005_tbl[bgw_ptr->free];
        } else {
            Frame_Down(0xC0, 0xE0, 2);
        }

        break;

    case 2:
        bgw_ptr->free = (s16)(bgw_ptr->free + 1);

        if (bgw_ptr->free >= 0x10) {
            opw_ptr->r_no_0 = (s8)(opw_ptr->r_no_0 + 1);
        } else {
            bgw_ptr->wxy[0].disp.pos += op_bg0_0005_tbl[bgw_ptr->free];
            bgw_ptr->xy[1].disp.pos += op_bg0_0005_tbl[bgw_ptr->free];
        }

        break;
    }

    op_scrn_pos_set2(0);
}

void op_bg0_0006(s16 /* unused */) {
    switch (opw_ptr->r_no_0) {
    case 0:
        opw_ptr->r_no_0 = (s8)(opw_ptr->r_no_0 + 1);
        bgw_ptr->free = 0;
        sub_000AF4AA(1);
        bgw_ptr->wxy[0].cal = 0xC00000;
        bgw_ptr->xy[1].cal = 0;
        oh_bg_blk_w(op_w.bgw, 0xD, 0, 0, 0);
        oh_bg_blk_w(op_w.bgw, 0xE, 1, 0, 0);
        oh_bg_blk_w(op_w.bgw, 0xF, 2, 0, 0);
        break;

    case 1:
        bgw_ptr->wxy[0].cal += 0x40000;

        if (bgw_ptr->wxy[0].disp.pos > 0x2C0) {
            opw_ptr->r_no_0 = (s8)(opw_ptr->r_no_0 + 1);
        }

        break;
    }

    op_scrn_pos_set2(0);
}

void op_bg0_0007(s16 /* unused */) {
    switch (opw_ptr->r_no_0) {
    case 0:
        opw_ptr->r_no_0 = (s8)(opw_ptr->r_no_0 + 1);
        bgw_ptr->free = 1;
        bgw_ptr->frame_deff = 0;
        sub_000AF4AA(1);
        bgw_ptr->wxy[0].cal = 0x1D00000;
        bgw_ptr->xy[1].cal = (s32)0xFFF00000;
        oh_bg_blk_w(op_w.bgw, 0x16, 1, 0, 0);
        oh_bg_blk_w(op_w.bgw, 0x17, 2, 0, 0);
        break;

    case 1:
        if (bgw_ptr->wxy[0].disp.pos < 0x200) {
            bgw_ptr->wxy[0].cal += 0xC000;
        } else {
            bgw_ptr->wxy[0].cal = 0x2000000;
        }

        if (bgw_ptr->xy[1].disp.pos < 0) {
            bgw_ptr->xy[1].cal += 0x4000;
        } else {
            bgw_ptr->xy[1].cal = 0;
        }

        break;
    }

    op_scrn_pos_set2(0);
}

void op_bg0_0008(s16 /* unused */) {
    switch (opw_ptr->r_no_0) {
    case 0:
        opw_ptr->r_no_0 = (s8)(opw_ptr->r_no_0 + 1);
        bgw_ptr->free = 1;
        bgw_ptr->frame_deff = 0;
        sub_000AF4AA(1);
        bgw_ptr->wxy[0].cal = 0x2300000;
        bgw_ptr->xy[1].cal = (s32)0xFFF00000;
        oh_bg_blk_w(op_w.bgw, 0x18, 1, 0, 0);
        oh_bg_blk_w(op_w.bgw, 0x19, 2, 0, 0);
        /* fallthrough */

    case 1:
        if (bgw_ptr->wxy[0].disp.pos > 0x200) {
            bgw_ptr->wxy[0].cal -= 0xC000;
        } else {
            bgw_ptr->wxy[0].cal = 0x2000000;
        }

        if (bgw_ptr->xy[1].disp.pos < 0) {
            bgw_ptr->xy[1].cal += 0x4000;
        } else {
            bgw_ptr->xy[1].cal = 0;
        }

        break;
    }

    op_scrn_pos_set2(0);
}

void op_bg0_0010(s16 /* unused */) {
    switch (opw_ptr->r_no_0) {
    case 0:
        opw_ptr->r_no_0 = (s8)(opw_ptr->r_no_0 + 1);
        bgw_ptr->free = 1;
        bgw_ptr->frame_deff = 0;
        sub_000AF4AA(1);
        Zoomf_Init();
        Zoom_Value_Set(0x40);
        bgw_ptr->wxy[0].cal = 0x2000000;
        bgw_ptr->xy[1].cal = 0;
        oh_bg_blk_w(op_w.bgw, 0x12, 1, 0, 0);
        oh_bg_blk_w(op_w.bgw, 0x13, 2, 0, 0);
        break;

    case 1:
        opw_ptr->r_no_0 = (s8)(opw_ptr->r_no_0 + 1);
        break;

    case 2:
        opw_ptr->r_no_0 = (s8)(opw_ptr->r_no_0 + 1);
        bgw_ptr->frame_deff = 12;
        Frame_Up(0xC0, 0xE0, bgw_ptr->frame_deff);
        break;
    }

    op_scrn_pos_set2(0);
}

void op_bg0_0011(s16 /* unused */) {
    switch (opw_ptr->r_no_0) {
    case 0:
        opw_ptr->r_no_0 = (s8)(opw_ptr->r_no_0 + 1);
        sub_000AF4AA(1);
        Zoomf_Init();
        Zoom_Value_Set(0x40);
        bgw_ptr->wxy[0].cal = 0x2000000;
        bgw_ptr->xy[1].cal = 0;
        oh_bg_blk_w(op_w.bgw, 0x14, 1, 0, 0);
        oh_bg_blk_w(op_w.bgw, 0x15, 2, 0, 0);
        break;

    case 1:
        opw_ptr->r_no_0 = (s8)(opw_ptr->r_no_0 + 1);
        bgw_ptr->frame_deff = 0x38;
        Frame_Up(0xC0, 0x40, bgw_ptr->frame_deff);
        bgw_ptr->xy[1].cal = (s32)0xFFE00000;
        /* fallthrough */

    case 2:
        if (bgw_ptr->xy[1].disp.pos < 0) {
            bgw_ptr->xy[1].cal += 0x20000;
        }

        if (bgw_ptr->frame_deff > 0) {
            bgw_ptr->frame_deff = (s16)(bgw_ptr->frame_deff - 1);
            Frame_Down(0xC0, 0x40, 1);
        }

        break;
    }

    op_scrn_pos_set2(0);
}

void op_bg0_0012(s16 /* unused */) {
    switch (opw_ptr->r_no_0) {
    case 0:
        opw_ptr->r_no_0 = (s8)(opw_ptr->r_no_0 + 1);
        bgw_ptr->free = 1;
        bgw_ptr->frame_deff = 0;
        sub_000AF4AA(1);
        Zoomf_Init();
        Zoom_Value_Set(0x40);
        bgw_ptr->wxy[0].cal = 0x2000000;
        bgw_ptr->xy[1].cal = 0x1000000;
        oh_bg_blk_w(op_w.bgw, 0x1E, 1, 1, 0);
        oh_bg_blk_w(op_w.bgw, 0x1F, 2, 1, 0);
        oh_bg_blk_w(op_w.bgw, 0x20, 1, 0, 0);
        oh_bg_blk_w(op_w.bgw, 0x21, 2, 0, 0);
        break;

    case 1:
        bgw_ptr->xy[1].cal += (s32)0xFFFE0000;

        if (bgw_ptr->xy[1].disp.pos <= 0x60) {
            opw_ptr->r_no_0 = (s8)(opw_ptr->r_no_0 + 1);
        }

        break;
    }

    op_scrn_pos_set2(0);
}

void op_bg0_0013(s16 /* unused */) {
    switch (opw_ptr->r_no_0) {
    case 0:
        opw_ptr->r_no_0 = (s8)(opw_ptr->r_no_0 + 1);
        bgw_ptr->free = 1;
        bgw_ptr->frame_deff = 0;
        bgw_ptr->wxy[0].cal = 0x2000000;
        bgw_ptr->xy[1].cal = 0x600000;
        oh_bg_blk_w(op_w.bgw, 0x1A, 1, 1, 0);
        oh_bg_blk_w(op_w.bgw, 0x1B, 2, 1, 0);
        oh_bg_blk_w(op_w.bgw, 0x1C, 1, 0, 0);
        oh_bg_blk_w(op_w.bgw, 0x1D, 2, 0, 0);
        break;

    case 1:
        bgw_ptr->xy[1].cal += 0x20000;

        if (bgw_ptr->xy[1].disp.pos > 0x100) {
            opw_ptr->r_no_0 = (s8)(opw_ptr->r_no_0 + 1);
        }

        break;
    }

    op_scrn_pos_set2(0);
}

void op_bg0_0014(s16 r_index) {
    op_bg0_0000(r_index);
}

void op_bg0_0015(s16 r_index) {
    switch (opw_ptr->r_no_0) {
    case 0:
        opw_ptr->r_no_0 = (s8)(opw_ptr->r_no_0 + 1);
        bgw_ptr->free = 1;
        bgw_ptr->l_limit = 0;
        sub_000AF4AA(1);
        bgw_ptr->wxy[0].cal = 0x2000000;
        bgw_ptr->xy[1].cal = 0;

        switch (r_index) {
        case 8:
            oh_bg_blk_w(op_w.bgw, 0x41, 1, 0, 1);
            oh_bg_blk_w(op_w.bgw, 0x42, 2, 0, 1);
            break;

        case 14:
            oh_bg_blk_w(op_w.bgw, 0x45, 1, 0, 1);
            oh_bg_blk_w(op_w.bgw, 0x46, 2, 0, 1);
            break;
        }

        op_w.bgw[0].map[1][0].col.full = (s32)0xFF000000;
        op_w.bgw[0].map[2][0].col.full = (s32)0xFF000000;
        break;

    case 1:
        op_w.bgw[0].map[1][0].col.full = (s32)0xFF000000;
        op_w.bgw[0].map[2][0].col.full = (s32)0xFF000000;
        bgw_ptr->free = (s16)(bgw_ptr->free - 1);

        if (bgw_ptr->free <= 0) {
            bgw_ptr->l_limit = (s16)(bgw_ptr->l_limit + 1);

            if (bgw_ptr->l_limit >= 6) {
                opw_ptr->r_no_0 = (s8)(opw_ptr->r_no_0 + 1);
            } else {
                bgw_ptr->free = 1;
                op_w.bgw[0].map[1][0].col.full = ot_bg0_0015_tbl[bgw_ptr->l_limit];
                op_w.bgw[0].map[2][0].col.full = ot_bg0_0015_tbl[bgw_ptr->l_limit];
            }
        }

        break;

    case 2:
        op_w.bgw[0].map[1][0].col.full = (s32)0xFF000000;
        op_w.bgw[0].map[2][0].col.full = (s32)0xFF000000;
        break;
    }

    op_scrn_pos_set2(0);
}

void op_bg0_0016(s16 /* unused */) {
    switch (opw_ptr->r_no_0) {
    case 0:
        opw_ptr->r_no_0 = (s8)(opw_ptr->r_no_0 + 1);
        sub_000AF4AA(1);
        bgw_ptr->wxy[0].cal = 0x2000000;
        bgw_ptr->xy[1].cal = 0;
        op_scrn_end = 0;
        bgw_ptr->frame_deff = 0x13;
        Frame_Up(0xC0, 0x70, bgw_ptr->frame_deff);
        bgw_ptr->free = 0xA;
        break;

    case 1:
        bgw_ptr->free = (s16)(bgw_ptr->free - 1);

        if (bgw_ptr->free <= 0) {
            opw_ptr->r_no_0 = (s8)(opw_ptr->r_no_0 + 1);
        }

        break;

    case 2:
        bgw_ptr->frame_deff = (s16)(bgw_ptr->frame_deff - 1);

        if (bgw_ptr->frame_deff >= 0) {
            Frame_Down(0xC0, 0x70, 1);
        } else {
            opw_ptr->r_no_0 = (s8)(opw_ptr->r_no_0 + 1);
            op_scrn_end = 1;
        }

        break;

    case 3:
        break;
    }

    op_scrn_pos_set2(0);
}

void op_bg0_move(s16 r_index) {
    void (*op_bg0_move_jp[94])(s16) = {
        op_bg0_0000, op_bg0_0001, op_bg0_0000, op_bg0_0001, op_bg0_0001, op_bg0_0001, op_bg0_0000, op_bg0_0001,
        op_bg0_0015, op_bg0_0001, op_bg0_0000, op_bg0_0001, op_bg0_0001, op_bg0_0000, op_bg0_0015, op_bg0_0001,
        op_bg0_0000, op_bg0_0000, op_bg0_0001, op_bg0_0001, op_bg0_0000, op_bg0_0001, op_bg0_0001, op_bg0_0000,
        op_bg0_0000, op_bg0_0000, op_bg0_0000, op_bg0_0000, op_bg0_0000, op_bg0_0000, op_bg0_0001, op_bg0_0001,
        op_bg0_0001, op_bg0_0001, op_bg0_0000, op_bg0_0001, op_bg0_0001, op_bg0_0000, op_bg0_0001, op_bg0_0001,
        op_bg0_0000, op_bg0_0002, op_bg0_0003, op_bg0_0002, op_bg0_0003, op_bg0_0002, op_bg0_0003, op_bg0_0002,
        op_bg0_0003, op_bg0_0002, op_bg0_0003, op_bg0_0002, op_bg0_0003, op_bg0_0000, op_bg0_0004, op_bg0_0001,
        op_bg0_0001, op_bg0_0004, op_bg0_0005, op_bg0_0002, op_bg0_0001, op_bg0_0002, op_bg0_0001, op_bg0_0002,
        op_bg0_0006, op_bg0_0001, op_bg0_0001, op_bg0_0001, op_bg0_0007, op_bg0_0008, op_bg0_0000, op_bg0_0000,
        op_bg0_0001, op_bg0_0001, op_bg0_0000, op_bg0_0001, op_bg0_0001, op_bg0_0000, op_bg0_0000, op_bg0_0004,
        op_bg0_0001, op_bg0_0004, op_bg0_0001, op_bg0_0002, op_bg1_0003, op_bg0_0002, op_bg0_0010, op_bg0_0002,
        op_bg0_0011, op_bg0_0012, op_bg0_0013, op_bg0_0014, op_bg0_0002, op_bg0_0016
    };

    opw_ptr = &op_w.bgw[0];
    bgw_ptr = &bg_w.bgw[0];
    op_bg0_move_jp[r_index](r_index);
}

s16 OPBG_Move(s32) {
    s16 flag;

    flag = oh_opening_demo();
    OPBG_Trans();
    return flag;
}

void op_bg_move(s16 r_index) {
    op_bg0_move(r_index);
    op_bg1_move(r_index);
    op_bg2_move(r_index);
}

s16 opening_demo(void) {
    switch (D_No[3]) {
    case 0:
        D_No[3] = (u8)(D_No[3] + 1);
        OPBG_Init();
        break;

    case 1:
        if (OPBG_Move(0)) {
            D_No[3] = (u8)(D_No[3] + 1);
            reset_dma_group(0x8C40);
            purge_texcash_work(9);
            TexRelease_OP();
            TITLE_Init();
            FadeInit();
        }

        break;

    case 2:
        TITLE_Move(0);

        if (FadeIn(0, 4, 1) != 0) {
            D_No[3] = (u8)(D_No[3] + 1);
            op_timer0 = 300;
        }

        break;

    case 3:
        op_timer0 = (s16)(op_timer0 - 1);

        if (op_timer0 == 0) {
            D_No[3] = 99;
        }

        TITLE_Move(1);
        Disp_Copyright();
        break;

    default:
        TITLE_Move(1);
        Disp_Copyright();
        return 1;
    }

    return 0;
}

void op_101_move(void) {
    switch (op_w.r_no_2) {
    case 0:
        op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
        ToneDown(0xFF, 0);
        op_bg_move(0);
        effect_F6_init(0);
        effect_F6_init(1);
        op_obj_disp = 0;
        effect_48_init(0);
        break;

    case 1:
        if (gSeqStatus[0] >= 11 && gSeqStatus[0] != 0x65) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_w.index = 1;
            op_obj_disp = 1;
            op_work_clear();
            break;
        }

        op_bg_move(0);
        break;

    default:
        op_bg_move(1);
        break;
    }
}

void op_102_move(void) {
    switch (op_w.r_no_2) {
    case 0:
        op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
        op_w.index = 2;
        effect_F6_init(2);
        effect_F6_init(3);
        effect_F6_init(4);
        op_obj_disp = 0;
        effect_48_init(1);
        op_work_clear();
        op_bg_move(2);
        break;

    case 1:
        if (gSeqStatus[0] >= 9 && gSeqStatus[0] != 0x66) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_w.index = 3;
            op_obj_disp = 1;
            op_work_clear();
            op_bg_move(3);
            break;
        }

        op_bg_move(2);
        break;

    case 2:
        if (gSeqStatus[0] >= 12) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_w.index = 4;
            op_work_clear();
            op_bg_move(4);
            break;
        }

        op_bg_move(3);
        break;

    default:
        op_bg_move(4);
        break;
    }
}

void op_103_move(void) {
    switch (op_w.r_no_2) {
    case 0:
        op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
        op_w.index = 5;
        effect_F6_init(5);
        effect_F6_init(6);
        effect_F6_init(7);
        effect_F6_init(8);
        effect_F6_init(9);
        effect_F6_init(10);
        op_work_clear();
        op_bg_move(5);
        break;

    case 1:
        if (gSeqStatus[0] >= 1 && gSeqStatus[0] != 0x67) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_w.index = 6;
            op_work_clear();
            effect_F6_init(11);
            effect_F6_init(12);
            effect_F6_init(13);
            effect_F6_init(14);
            effect_F6_init(15);
            effect_F6_init(16);
            break;
        }

        op_bg_move(5);
        break;

    case 2:
        if (gSeqStatus[0] >= 2) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 7;
            op_obj_disp = 0;
            effect_48_init(8);
            break;
        }

        op_bg_move(6);
        break;

    case 3:
        if (gSeqStatus[0] >= 3) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 8;
            op_obj_disp = 1;
            op_scrn_end = 0;
            effect_36_init(22);
            break;
        }

        op_bg_move(7);
        break;

    case 4:
        if (gSeqStatus[0] >= 4) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 9;
            break;
        }

        op_bg_move(8);
        break;

    case 5:
        if (gSeqStatus[0] >= 5) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 10;
            break;
        }

        op_bg_move(9);
        break;

    case 6:
        if (gSeqStatus[0] >= 7) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 11;
            break;
        }

        op_bg_move(10);
        break;

    case 7:
        if (gSeqStatus[0] >= 8) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 12;
            op_obj_disp = 0;
            effect_48_init(9);
            break;
        }

        op_bg_move(11);
        break;

    case 8:
        if (gSeqStatus[0] >= 9) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 13;
            op_obj_disp = 1;
            break;
        }

        op_bg_move(12);
        break;

    case 9:
        if (gSeqStatus[0] >= 11) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 14;
            op_scrn_end = 0;
            effect_36_init(23);
            break;
        }

        op_bg_move(13);
        break;

    case 10:
        if (gSeqStatus[0] >= 12) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 15;
        }

        op_bg_move(14);
        break;

    case 11:
        if (gSeqStatus[0] >= 13) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 16;
            break;
        }

        op_bg_move(15);
        break;

    default:
        op_bg_move(16);
        break;
    }
}

void op_104_move(void) {
    switch (op_w.r_no_2) {
    case 0:
        op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
        op_work_clear();
        op_w.index = 17;
        op_bg_move(17);
        effect_F6_init(17);
        effect_F6_init(18);
        effect_F6_init(19);
        effect_F6_init(20);
        effect_F6_init(21);
        effect_F6_init(22);
        effect_F6_init(23);
        break;

    case 1:
        if (gSeqStatus[0] >= op_104_sound[op_w.r_no_2] && gSeqStatus[0] != 0x68) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 18;
            break;
        }

        op_bg_move(17);
        break;

    case 2:
        if (gSeqStatus[0] >= op_104_sound[op_w.r_no_2]) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 19;
            op_obj_disp = 0;
            effect_48_init(10);
            break;
        }

        op_bg_move(18);
        break;

    case 3:
        if (gSeqStatus[0] >= op_104_sound[op_w.r_no_2]) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 20;
            op_obj_disp = 1;
            break;
        }

        op_bg_move(19);
        break;

    case 4:
        if (gSeqStatus[0] >= op_104_sound[op_w.r_no_2]) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 21;
            op_obj_disp = 0;
            effect_48_init(11);
            break;
        }

        op_bg_move(20);
        break;

    case 5:
        if (gSeqStatus[0] >= op_104_sound[op_w.r_no_2]) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 22;
            op_obj_disp = 1;
            break;
        }

        op_bg_move(21);
        break;

    case 6:
        if (gSeqStatus[0] >= op_104_sound[op_w.r_no_2]) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 23;
            break;
        }

        op_bg_move(22);
        break;

    default:
        op_bg_move(23);
        break;
    }
}

void op_105_move(void) {
    switch (op_w.r_no_2) {
    case 0:
        op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
        op_work_clear();
        op_w.index = 24;
        op_bg_move(24);
        effect_F6_init(24);
        op_obj_disp = 0;
        effect_48_init(12);
        break;

    case 1:
    default:
        op_bg_move(24);
        break;
    }
}

void op_106_move(void) {
    switch (op_w.r_no_2) {
    case 0:
        op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
        op_work_clear();
        op_w.index = 25;
        op_obj_disp = 1;
        op_bg_move(25);
        effect_F6_init(25);
        effect_F6_init(26);
        effect_F6_init(27);
        effect_F6_init(28);
        effect_36_init(18);
        effect_36_init(19);
        effect_36_init(20);
        effect_36_init(21);
        break;

    case 1:
        if (gSeqStatus[0] >= 1 && gSeqStatus[0] != 0x6A) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 26;
            break;
        }

        op_bg_move(25);
        break;

    case 2:
        if (gSeqStatus[0] >= 3) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 27;
            break;
        }

        op_bg_move(26);
        break;

    case 3:
        if (gSeqStatus[0] >= 7) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 28;
            op_obj_disp = 0;
            effect_48_init(15);
            break;
        }

        op_bg_move(27);
        break;

    default:
        op_bg_move(28);
        break;
    }
}

void op_107_move(void) {
    switch (op_w.r_no_2) {
    case 0:
        op_plmove_timer = (s16)(op_plmove_timer + 1);
        op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
        op_obj_disp = 1;
        op_work_clear();
        op_w.index = 29;
        op_bg_move(29);
        effect_F6_init(29);
        effect_F6_init(30);
        effect_F6_init(31);
        effect_F6_init(32);
        effect_F6_init(33);
        effect_F6_init(34);
        break;

    case 1:
        if (gSeqStatus[0] >= 1 && gSeqStatus[0] != 0x6B) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 30;
            break;
        }

        op_bg_move(29);
        break;

    case 2:
        if (gSeqStatus[0] >= 2) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 31;
            break;
        }

        op_bg_move(30);
        break;

    case 3:
        if (gSeqStatus[0] >= 3) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 32;
            op_obj_disp = 0;
            effect_48_init(13);
            break;
        }

        op_bg_move(31);
        break;

    case 4:
        if (gSeqStatus[0] >= 4) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 33;
            op_obj_disp = 1;
            break;
        }

        op_bg_move(32);
        break;

    case 5:
        if (gSeqStatus[0] >= 5) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 34;
            effect_F6_init(35);
            effect_F6_init(36);
            effect_F6_init(37);
            effect_F6_init(38);
            effect_F6_init(39);
            effect_F6_init(40);
            break;
        }

        op_bg_move(33);
        break;

    case 6:
        if (gSeqStatus[0] >= 7) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 35;
            break;
        }

        op_bg_move(34);
        break;

    case 7:
        if (gSeqStatus[0] >= 8) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 36;
            op_obj_disp = 0;
            effect_48_init(14);
            break;
        }

        op_bg_move(35);
        break;

    case 8:
        if (gSeqStatus[0] >= 9) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 37;
            op_obj_disp = 1;
            break;
        }

        op_bg_move(36);
        break;

    case 9:
        if (gSeqStatus[0] >= 11) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 38;
            break;
        }

        op_bg_move(37);
        break;

    case 10:
        if (gSeqStatus[0] >= 12) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 39;
            break;
        }

        op_bg_move(38);
        break;

    case 11:
        if (gSeqStatus[0] >= 13) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 40;
            break;
        }

        op_bg_move(39);
        break;

    default:
        op_bg_move(40);
        break;
    }
}

void op_108_move(void) {
    switch (op_w.r_no_2) {
    case 0:
        op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
        op_work_clear();
        op_w.index = 41;
        op_bg_move(41);
        op_w.mv_ctr = 0;
        effect_36_init(0);
        effect_36_init(1);
        effect_36_init(2);
        effect_36_init(3);
        effect_36_init(4);
        effect_36_init(5);
        effect_36_init(6);
        effect_36_init(7);
        break;

    case 1:
        op_w.mv_ctr = (s16)(op_w.mv_ctr + 1);

        if (op_w.mv_ctr >= 4) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 42;
            op_bg_move(42);
            break;
        }

        op_bg_move(41);
        break;

    case 2:
        op_w.mv_ctr = (s16)(op_w.mv_ctr + 1);

        if (op_w.mv_ctr >= 20) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 43;
            op_bg_move(43);
            effect_36_init(8);
            effect_36_init(9);
            effect_36_init(10);
            effect_36_init(11);
            effect_36_init(12);
            effect_36_init(13);
            effect_36_init(14);
            effect_36_init(15);
        }

        break;

    case 3:
        op_w.mv_ctr = (s16)(op_w.mv_ctr + 1);

        if (op_w.mv_ctr >= 24) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 44;
            op_bg_move(44);
            break;
        }

        op_bg_move(43);
        break;

    case 4:
        op_w.mv_ctr = (s16)(op_w.mv_ctr + 1);

        if (op_w.mv_ctr >= 28) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 45;
            op_bg_move(45);
        }

        break;

    case 5:
        op_w.mv_ctr = (s16)(op_w.mv_ctr + 1);

        if (op_w.mv_ctr >= 32) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 46;
            op_bg_move(46);
            break;
        }

        op_bg_move(45);
        break;

    case 6:
        op_w.mv_ctr = (s16)(op_w.mv_ctr + 1);

        if (op_w.mv_ctr >= 48) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 47;
            op_bg_move(47);
        }

        break;

    case 7:
        op_w.mv_ctr = (s16)(op_w.mv_ctr + 1);

        if (op_w.mv_ctr >= 52) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 48;
            op_bg_move(48);
            break;
        }

        op_bg_move(47);
        break;

    case 8:
        op_w.mv_ctr = (s16)(op_w.mv_ctr + 1);

        if (op_w.mv_ctr >= 60) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 49;
            op_bg_move(49);
        }

        break;

    case 9:
        op_w.mv_ctr = (s16)(op_w.mv_ctr + 1);

        if (op_w.mv_ctr >= 64) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 50;
            op_bg_move(50);
            break;
        }

        op_bg_move(49);
        break;

    case 10:
        op_w.mv_ctr = (s16)(op_w.mv_ctr + 1);

        if (op_w.mv_ctr >= 76) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 51;
            op_bg_move(51);
        }

        break;

    case 11:
        op_w.mv_ctr = (s16)(op_w.mv_ctr + 1);

        if (op_w.mv_ctr >= 80) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 52;
            op_bg_move(52);
            break;
        }

        op_bg_move(51);
        break;

    case 12:
        op_w.mv_ctr = (s16)(op_w.mv_ctr + 1);

        if (op_w.mv_ctr >= 86) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 53;
            op_bg_move(53);
        }

        break;

    default:
        break;
    }
}

void op_109_move(void) {
    switch (op_w.r_no_2) {
    case 0:
        op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
        op_scrn_end = 0;
        op_work_clear();
        op_w.index = 54;
        op_bg_move(54);
        op_obj_disp = 0;
        effect_48_init(16);
        break;

    case 1:
        if (gSeqStatus[0] >= 3 && gSeqStatus[0] != 0x6D) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 55;
            op_obj_disp = 1;
            break;
        }

        op_bg_move(54);
        break;

    case 2:
        if (gSeqStatus[0] >= 5) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 56;
            break;
        }

        op_bg_move(55);
        break;

    case 3:
        if (gSeqStatus[0] >= 7) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_scrn_end = 0;
            op_work_clear();
            op_w.index = 57;
            op_obj_disp = 0;
            effect_48_init(17);
            break;
        }

        op_bg_move(56);
        break;

    case 4:
        if (gSeqStatus[0] >= 11) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 58;
            op_obj_disp = 1;
            break;
        }

        op_bg_move(57);
        break;

    default:
        op_bg_move(58);
        break;
    }
}

void op_110_move(void) {
    switch (op_w.r_no_2) {
    case 0:
        op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
        Zoom_Value_Set(64);
        op_work_clear();
        op_w.index = 59;
        op_bg_move(59);
        op_obj_disp = 0;
        effect_48_init(2);
        break;

    case 1:
        /* The PS2 threshold is 0. */
        if (gSeqStatus[0] != 0x6E) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 60;
            op_obj_disp = 1;
            break;
        }

        op_bg_move(59);
        break;

    case 2:
        if (gSeqStatus[0] >= 3) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 61;
            op_obj_disp = 0;
            effect_48_init(3);
            break;
        }

        op_bg_move(60);
        break;

    case 3:
        if (gSeqStatus[0] >= 4) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 62;
            op_obj_disp = 1;
            break;
        }

        op_bg_move(61);
        break;

    case 4:
        if (gSeqStatus[0] >= 7) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 63;
            op_obj_disp = 0;
            effect_48_init(4);
            break;
        }

        op_bg_move(62);
        break;

    case 5:
        if (gSeqStatus[0] >= 9) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 64;
            op_obj_disp = 1;
            break;
        }

        op_bg_move(63);
        break;

    default:
        op_bg_move(64);
        break;
    }
}

void op_111_move(void) {
    switch (op_w.r_no_2) {
    case 0:
        op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
        op_work_clear();
        op_w.index = 65;
        op_bg_move(65);
        effect_F6_init(41);
        effect_F6_init(42);
        effect_F6_init(43);
        break;

    case 1:
        if (gSeqStatus[0] >= 2 && gSeqStatus[0] != 0x6F) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 66;
            break;
        }

        op_bg_move(65);
        break;

    case 2:
        if (gSeqStatus[0] >= 4) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 67;
            break;
        }

        op_bg_move(66);
        break;

    case 3:
        if (gSeqStatus[0] >= 7) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 68;
            break;
        }

        op_bg_move(67);
        break;

    case 4:
        if (gSeqStatus[0] >= 11) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 69;
            break;
        }

        op_bg_move(68);
        break;

    default:
        op_bg_move(69);
        break;
    }
}

void op_112_move(void) {
    switch (op_w.r_no_2) {
    case 0:
        op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
        op_work_clear();
        op_w.index = 70;
        op_bg_move(70);
        effect_F6_init(54);
        effect_F6_init(44);
        effect_F6_init(45);
        effect_F6_init(46);
        effect_F6_init(47);
        effect_F6_init(48);
        effect_F6_init(49);
        effect_F6_init(50);
        effect_F6_init(51);
        break;

    case 1:
        if (gSeqStatus[0] >= 8 && gSeqStatus[0] != 0x70) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.mv_ctr = 0;
            op_w.index = 71;
            break;
        }

        op_bg_move(70);
        break;

    case 2:
        op_w.mv_ctr = (s16)(op_w.mv_ctr + 1);

        if (op_w.mv_ctr >= 8) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 72;
            break;
        }

        op_bg_move(71);
        break;

    case 3:
        op_w.mv_ctr = (s16)(op_w.mv_ctr + 1);

        if (op_w.mv_ctr >= 14) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 73;
            op_obj_disp = 0;
            effect_48_init(18);
            break;
        }

        op_bg_move(72);
        break;

    case 4:
        op_w.mv_ctr = (s16)(op_w.mv_ctr + 1);

        if (op_w.mv_ctr >= 19) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 74;
            op_obj_disp = 1;
            break;
        }

        op_bg_move(73);
        break;

    case 5:
        op_w.mv_ctr = (s16)(op_w.mv_ctr + 1);

        if (op_w.mv_ctr >= 26) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 75;
            break;
        }

        op_bg_move(74);
        break;

    case 6:
        op_w.mv_ctr = (s16)(op_w.mv_ctr + 1);

        if (op_w.mv_ctr >= 34) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 76;
            op_obj_disp = 0;
            effect_48_init(19);
            break;
        }

        op_bg_move(75);
        break;

    case 7:
        op_w.mv_ctr = (s16)(op_w.mv_ctr + 1);

        if (op_w.mv_ctr >= 40) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 77;
            op_obj_disp = 1;
            break;
        }

        op_bg_move(76);
        break;

    case 8:
        op_w.mv_ctr = (s16)(op_w.mv_ctr + 1);

        if (op_w.mv_ctr >= 44) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 78;
            break;
        }

        op_bg_move(77);
        break;

    default:
        op_bg_move(78);
        break;
    }
}

void op_113_move(void) {
    switch (op_w.r_no_2) {
    case 0:
        op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
        op_scrn_end = 0;
        op_work_clear();
        op_w.index = 79;
        op_bg_move(79);
        effect_F6_init(52);
        effect_F6_init(53);
        op_obj_disp = 0;
        effect_48_init(20);
        break;

    case 1:
        if (gSeqStatus[0] >= 3 && gSeqStatus[0] != 0x71) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 80;
            op_obj_disp = 1;
            break;
        }

        op_bg_move(79);
        break;

    case 2:
        if (gSeqStatus[0] >= 7) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_scrn_end = 0;
            op_work_clear();
            op_w.index = 81;
            op_obj_disp = 0;
            effect_48_init(21);
            break;
        }

        op_bg_move(80);
        break;

    case 3:
        if (gSeqStatus[0] >= 11) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 82;
            op_obj_disp = 1;
            break;
        }

        op_bg_move(81);
        break;

    default:
        op_bg_move(82);
        break;
    }
}

void op_114_move(void) {
    switch (op_w.r_no_2) {
    case 0:
        op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
        op_work_clear();
        op_w.index = 83;
        op_bg_move(83);
        op_obj_disp = 0;
        effect_48_init(5);
        break;

    case 1:
        if (gSeqStatus[0] >= 2 && gSeqStatus[0] != 0x72) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 84;
            op_obj_disp = 1;
            break;
        }

        op_bg_move(83);
        break;

    case 2:
        if (gSeqStatus[0] >= 3) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 85;
            op_obj_disp = 0;
            effect_48_init(6);
            break;
        }

        op_bg_move(84);
        break;

    case 3:
        if (gSeqStatus[0] >= 4) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 86;
            op_obj_disp = 1;
            break;
        }

        op_bg_move(85);
        break;

    case 4:
        if (gSeqStatus[0] >= 7) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            Zoom_Value_Set(64);
            op_work_clear();
            op_w.index = 87;
            op_obj_disp = 0;
            effect_48_init(7);
            break;
        }

        op_bg_move(86);
        break;

    case 5:
        if (gSeqStatus[0] >= 9) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 88;
            op_obj_disp = 1;
            break;
        }

        op_bg_move(87);
        break;

    default:
        op_bg_move(88);
        break;
    }
}

void op_115_move(void) {
    switch (op_w.r_no_2) {
    case 0:
        op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
        Zoom_Value_Set(64);
        op_work_clear();
        op_w.index = 89;
        op_bg_move(89);
        effect_36_init(16);
        break;

    case 1:
        if (gSeqStatus[0] >= 7 && gSeqStatus[0] != 0x73) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_work_clear();
            op_w.index = 90;
            break;
        }

        op_bg_move(89);
        break;

    default:
        op_bg_move(90);
        break;
    }
}

void op_116_move(void) {
    switch (op_w.r_no_2) {
    case 0:
        op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
        op_work_clear();
        op_w.index = 91;
        sub_0004384A((const char *)2);
        op_bg_move(91);
        effect_36_init(17);
        effect_36_init(28);
        op_w.mv_ctr = 88;
        FadeInit();
        break;

    case 1:
        op_bg_move(91);

        if (op_w.mv_ctr < 4) {
            FadeOut(0, 8, 1);
        }

        op_w.mv_ctr = (s16)(op_w.mv_ctr - 1);

        if (op_w.mv_ctr <= 0) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            op_w.mv_ctr = 16;
        }

        break;

    case 2:
        if (FadeOut(0, 8, 1) != 0) {
            op_w.mv_ctr = (s16)(op_w.mv_ctr - 1);

            if (op_w.mv_ctr <= 0) {
                op_w.index = 0x7FFF;
                op_end_flag = 1;
                op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            }
        }

        op_bg_move(91);
        break;

    default:
        op_bg_move(91);
        break;
    }
}

void op_117_move(void) {
    switch (op_w.r_no_2) {
    case 0:
        op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
        Zoomf_Init();
        op_work_clear();
        op_w.index = 92;
        op_bg_move(92);
        effect_E1_init(1, 0, 1);
        effect_E1_init(0, 0, 1);
        sub_0004AFFA(0x10);
        sub_0004AFFA(0x11);
        sub_0004AFFA(0x12);
        sub_0004AFFA(9);
        op_bg_move(92);
        op_w.r_no_1 = (s8)(op_w.r_no_1 + 1);
        op_w.r_no_2 = 0;
        op_work_clear();
        break;
    }
}

void op_118_move(void) {
    switch (op_w.r_no_2) {
    case 0:
        op_w.mv_ctr = 60;
        op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
        break;

    case 1:
    case 4:
        op_w.mv_ctr = (s16)(op_w.mv_ctr - 1);

        if (op_w.mv_ctr < 0) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
        }

        break;

    case 2:
        if (Request_Fade(0x28) != 0) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
        }

        break;

    case 3:
        if (Check_Fade_Complete() != 0) {
            op_w.r_no_2 = (s8)(op_w.r_no_2 + 1);
            Disp_Copyright();
            op_w.mv_ctr = 240;
        }

        op_w.index = 93;
        op_bg_move(93);
        break;

    case 5:
        op_end_flag = 1;
        sub_000AF4C2(14);
        op_bg_move(93);
        break;
    }
}

void op_100_move(void) {
    op_w.r_no_1 = (s8)(op_w.r_no_1 + 1);
    Go_BGM();
    op_101_move();
}
