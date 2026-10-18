/* CHARSET.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * setupCharTableData 0x1D7E6 size 0x6B. Read against the x86: 0x214 is
 * &wk->cg_type, the C's dst. Matches.
 * char_move_wca_init 0x1D851 size 0x34.
 * comm_wca 0x1D885 size 0xE.
 * comm_end 0x1D893 size 0x23.
 * comm_sps 0x1D8B6 size 0x15.
 * comm_setr 0x1D8CB size 0x19.
 * comm_addr 0x1D8E4 size 0x1B.
 * comm_for 0x1D8FF size 0x5F. Read against the x86: test ah, 0x40 is the C's
 * ctc->pat & 0x4000.
 * comm_for2 0x1D95E size 0x5F. Read against the x86: test ah, 0x40 is the C's
 * ctc->pat & 0x4000.
 * comm_rja 0x1D9BD size 0x2D.
 * comm_rja2 0x1D9EA size 0x2D.
 * comm_rja3 0x1DA17 size 0x2D.
 * comm_rja4 0x1DA44 size 0x2D.
 * comm_rja5 0x1DA71 size 0x2D.
 * comm_rja6 0x1DA9E size 0x2D.
 * comm_rja7 0x1DACB size 0x2D.
 * comm_rmja 0x1DAF8 size 0x2D.
 * comm_mdat 0x1DB25 size 0x2D.
 * comm_mpos 0x1DB52 size 0x2B.
 * comm_cafr 0x1DB7D size 0x2D.
 * comm_care 0x1DBAA size 0x2D.
 * comm_psxy 0x1DBD7 size 0x42.
 * comm_ps_x 0x1DC19 size 0x32.
 * comm_ps_y 0x1DC4B size 0x5F.
 * comm_paxy 0x1DCAA size 0x5B.
 * comm_pa_x 0x1DD05 size 0x47.
 * comm_pa_y 0x1DD4C size 0x36.
 * comm_exec 0x1DD82 size 0x1E.
 * comm_mxyt 0x1DDA0 size 0x2B.
 * comm_hclr 0x1DDCB size 0x10.
 * comm_ixfw 0x1DDDB size 0x33.
 * comm_ixbw 0x1DE0E size 0x33.
 * comm_quax 0x1DE41 size 0x12.
 * comm_quay 0x1DE53 size 0x1C.
 * comm_gets 0x1DE6F size 0x14.
 * comm_s123 0x1DE83 size 0x24.
 * comm_s456 0x1DEA7 size 0x24.
 * comm_stop 0x1DEEF size 0x89.
 * comm_smhf 0x1DF78 size 0x15.
 * comm_ngme 0x1DF8D size 0x29.
 * comm_ngem 0x1DFB6 size 0x2F.
 * comm_asxy 0x1DFE5 size 0x38.
 * comm_schx 0x1E01D size 0x5B. Read against the x86: 0x84 is a WORK mvxy
 * field. Matches the C.
 * comm_schy 0x1E078 size 0x59. Read against the x86: 0x80 is a WORK mvxy
 * field. Matches the C.
 * comm_mvix 0x1E0D1 size 0x17.
 * comm_ccch 0x1E0E8 size 0x38. Read against the x86: 0x342 is wk->extra_col.
 * Matches the C.
 * comm_wset 0x1E120 size 0xDF.
 * comm_wswk 0x1E1FF size 0x14D.
 * comm_wadd 0x1E34C size 0x3A.
 * comm_wadd2 0x1E386 size 0x46.
 * comm_imgs 0x1E3CC size 0x64.
 * comm_imgc 0x1E430 size 0x35.
 * comm_rvxy 0x1E465 size 0xA0.
 * comm_rv_x 0x1E505 size 0x79.
 * comm_rv_y 0x1E57E size 0x47.
 * comm_ccfl 0x1E5C5 size 0xF.
 * comm_atmf 0x1E5D4 size 0x1E.
 * comm_retmj 0x1E5F2 size 0x63.
 * comm_sstx 0x1E655 size 0x13E. Read against the x86: 0x84 is the mvxy field
 * each case updates. Matches the C.
 * comm_ssty 0x1E793 size 0x165. Read against the x86: 0x80 and 0x88 are the
 * mvxy fields each case updates. Matches the C.
 * comm_flip 0x1E925 size 0x13.
 * comm_kage 0x1E938 size 0x24.
 * comm_dspf 0x1E95C size 0x12.
 * comm_srlf 0x1E96E size 0x33.
 * comm_scmd 0x1E9A1 size 0x17.
 * comm_rhsja 0x1E9B8 size 0x34.
 * decord_if_jump 0x1E9EC size 0x8D.
 * get_comm_if_lever 0x1EA79 size 0x2C. Read against the x86: 0x406 is the
 * stride of wcp[]. Matches the C.
 * get_comm_if_shot 0x1EAA5 size 0x2E. Read against the x86: 0x406 is the
 * stride of wcp[]. Matches the C.
 * get_comm_if_shot_now_off 0x1EAD3 size 0x66. Read against the x86: 0x406 is
 * the stride of wcp[]. Matches the C.
 * get_comm_if_shot_now 0x1EB39 size 0x2E. Read against the x86: 0x406 is the
 * stride of wcp[]. Matches the C.
 * get_comm_if_lvsh 0x1EB67 size 0x2E. Read against the x86: 0x406 is the
 * stride of wcp[]. Matches the C.
 * setup_comm_back 0x1EB95 size 0x44.
 * setup_comm_retmj 0x1EBD9 size 0x2F.
 * setup_comm_abbak 0x1EC08 size 0x3D.
 * check_xcopy_filter_se_req 0x1EC45 size 0x4C.
 * setup_metamor_kezuri 0x1EC91 size 0x15. Read against the x86: 0x2D4 is
 * wk->kezuri_pow, and 0x18 is kezuri_pow_table[4] (24) folded into the store.
 * Matches the C. WORK field the C tests, and 0x18 the value it stores when
 * that field is 0. Matches.
 * set_jugde_area 0x1ECA6 size 0x92.
 * char_move_cmms2 0x1ED38 size 0xE0.
 * char_move_cmms3 0x1EE18 size 0x151.
 * comm_if_l 0x1EF69 size 0x65.
 * comm_djmp 0x1EFCE size 0x3A.
 * comm_rngc 0x1F008 size 0x3F.
 * comm_pjmp 0x1F047 size 0x2D.
 * comm_hjmp 0x1F074 size 0x5D.
 * comm_if_s 0x1F0D1 size 0x77.
 * comm_iflb 0x1F148 size 0x4B.
 * comm_sajp 0x1F193 size 0x58. Read against the x86: 0xFF is a byte compare
 * with the C's -1.
 * comm_wceq 0x1F1EB size 0x35.
 * comm_wcne 0x1F220 size 0x35.
 * comm_wcgt 0x1F255 size 0x35.
 * comm_wclt 0x1F28A size 0x35.
 * comm_wceq2 0x1F2BF size 0x44.
 * comm_wcne2 0x1F303 size 0x44.
 * comm_wcgt2 0x1F347 size 0x44.
 * comm_wclt2 0x1F38B size 0x44.
 * comm_iflg 0x1F3CF size 0x3F.
 * comm_mpcy 0x1F40E size 0x49.
 * comm_epcy 0x1F457 size 0x47.
 * comm_myhp 0x1F49E size 0x60. Read against the x86: 0x64 is the C's * 100.
 * comm_emhp 0x1F4FE size 0x5C. Read against the x86: 0x64 is the C's * 100.
 * comm_chkwf 0x1F55A size 0x5A.
 * comm_ifrlf 0x1F5B4 size 0x35.
 * comm_bgrlf 0x1F5E9 size 0x42.
 * comm_rljmp 0x1F62B size 0x27.
 * comm_ifs2 0x1F652 size 0x4D.
 * comm_sse 0x1F69F size 0x68.
 * comm_s_chg 0x1F707 size 0x4D.
 * comm_schg2 0x1F754 size 0x4F.
 * comm_ifcom 0x1F7A3 size 0x27.
 * comm_axjmp 0x1F7CA size 0x3B.
 * comm_ayjmp 0x1F805 size 0x35.
 * comm_ifs3 0x1F83A size 0x4D.
 * set_new_attnum 0x1F887 size 0x18D. Read against the x86: 0x2C0 is &wk->att
 * (copied with movsd), and 0x38D the byte the C tests with & 0x40. Matches.
 * get_char_data_zanzou 0x1FA14 size 0x3D. Read against the x86: 0x270 is the
 * WORK field the 16-byte record is copied into. Matches the C.
 * check_cgd_patdat 0x1FA51 size 0x3B2. Read against the x86: -0xA0 is the C's
 * index bias folded into the lea, and 0x270 the field the record is copied
 * into. Matches.
 * check_cgd_patdat2 0x1FE03 size 0x19B. Read against the x86: -0xA0 is the C's
 * index bias folded into the lea, and 0x270 the field the record is copied
 * into. Matches.
 * exset_char_move_init 0x1FF9E size 0x88.
 * check_cm_extended_code 0x20026 size 0x68.
 * char_move 0x2008E size 0x1B.
 * set_char_move_init 0x200A9 size 0x110.
 * set_char_move_init2 0x201B9 size 0x115.
 * char_move_z 0x202CE size 0x2A.
 * char_move_wca 0x202F8 size 0x3B.
 * char_move_index 0x20333 size 0x37.
 * char_move_cmja 0x2036A size 0x30.
 * char_move_cmj4 0x2039A size 0x30.
 * char_move_cmms 0x203CA size 0x30.
 * char_move_cmhs 0x203FA size 0x40.
 * comm_roa 0x2043A size 0x53.
 * comm_jmp 0x2048D size 0x2D.
 * comm_jpss 0x204BA size 0x2D.
 * comm_jsr 0x204E7 size 0x5D.
 * comm_ret 0x20544 size 0x2A.
 * comm_nex 0x2056E size 0x47.
 * comm_nex2 0x205B5 size 0x47.
 * comm_uja 0x205FC size 0x32.
 * comm_uja2 0x2062E size 0x32.
 * comm_uja3 0x20660 size 0x32.
 * comm_uja4 0x20692 size 0x32.
 * comm_uja5 0x206C4 size 0x32.
 * comm_uja6 0x206F6 size 0x32.
 * comm_uja7 0x20728 size 0x32.
 * comm_umja 0x2075A size 0x32.
 * comm_rapp 0x2078C size 0x5B. Read against the x86: 0x406 is the stride of
 * wcp[]. Matches the C.
 * comm_rapk 0x207E7 size 0x5B. Read against the x86: 0x406 is the stride of
 * wcp[]. Matches the C.
 * comm_back 0x20842 size 0x2A.
 * comm_rapp2 0x2086C size 0x5B. Read against the x86: 0x406 is the stride of
 * wcp[]. Matches the C.
 * comm_rapk2 0x208C7 size 0x5B. Read against the x86: 0x406 is the stride of
 * wcp[]. Matches the C.
 * comm_abbak 0x20922 size 0x2A.
 * comm_uhsja 0x2094C size 0x39.
 * comm_a123 is folded into 0x1DECB with 1 other bodies. Unnamed.
 * comm_a456 is folded into 0x1DECB with 1 other bodies. Unnamed.
 * comm_dummy is folded into 0x9B78F with 3 other bodies. Unnamed.
 * comm_exbgc is folded into 0x9B78F with 3 other bodies. Unnamed.
 * comm_exbgs is folded into 0x9B78F with 3 other bodies. Unnamed.
 * comm_ngda is folded into 0x1E8F8 with 1 other bodies. Unnamed.
 * comm_ydat is folded into 0x1E8F8 with 1 other bodies. Unnamed.
 * Not located in sf33rd.xbe; their PS2 C is kept under #if 0:
 * get_comm_djmp_lever_dir.
 * get_comm_djmp_lever_dir is folded into 0xE4CA8.
 * pp_pulpara_remake_at_init is folded into 0x4384A.
 * Data: jphos_table is 0x240D58, 0x20 bytes compared.
 * Data: kezuri_pow_table is 0x240D78, 0xA bytes compared.
 * Data: decode_chcmd is 0x240D88, 125 entries compared.
 * Data: decode_if_lever is 0x240F80, 16 entries compared.
 * Data: acatkoa_table is 0x240FC0, 0x82 bytes compared.
 * Unnamed data used (not a difference): get_comm_if_lever: 0x7bbac2;
 * set_new_attnum: 0x795c84; get_comm_if_shot: 0x7bbac2; get_comm_if_shot_now:
 * 0x7bbac6; get_comm_if_lvsh: 0x7bbac2; comm_rapp2: 0x7bbae6;
 * get_comm_if_shot_now_off: 0x7bbac6,0x7bbac8; comm_rapk2: 0x7bbaea;
 * comm_rapk: 0x7bbaec; comm_rapp: 0x7bbae8.
 * Globals: jphos_table 0x240D58, kezuri_pow_table 0x240D78, decode_chcmd
 * 0x240D88, decode_if_lever 0x240F80, acatkoa_table 0x240FC0, effinitjptbl
 * 0x25B9F4, chain_normal_ground_table 0x25E5D0, chain_hidou_nm_ground_table
 * 0x25E5E0, chain_normal_air_table 0x25E5F0, chain_hidou_nm_air_table
 * 0x25E600, plpat_rno_filter 0x25E610, sound_effect_request 0x266008,
 * bs2_floor 0x7A80C0, My_char 0x7A8114, Max_vitality 0x7A81F8, Game_timer
 * 0x7A8830, test_flag 0x7A8902, bg_w 0x7BC520, plw 0xC7CEA0, pcon_dp_flag
 * 0xC7D8D0.
 */

#include "structs.h"

#define LO_2_BYTES(_val) (((s16*)&_val)[0])
#define HI_2_BYTES(_val) (((s16*)&_val)[1])
#define WK_AS_PLW ((PLW*)wk)
#define NULL 0

u8 sub_000E4CA8(PLW* wk);
void sub_0004384A();
s32 comm_dummy(WORK* , UNK11* );
s32 comm_roa(WORK* wk, UNK11* );
s32 comm_end(WORK* wk, UNK11* ctc);
s32 comm_jmp(WORK* wk, UNK11* ctc);
s32 comm_jpss(WORK* wk, UNK11* ctc);
s32 comm_jsr(WORK* wk, UNK11* ctc);
s32 comm_ret(WORK* wk, UNK11* );
s32 comm_sps(WORK* wk, UNK11* ctc);
s32 comm_setr(WORK* wk, UNK11* ctc);
s32 comm_addr(WORK* wk, UNK11* ctc);
s32 comm_if_l(WORK* wk, UNK11* ctc);
s32 comm_djmp(WORK* wk, UNK11* ctc);
s32 comm_for(WORK* wk, UNK11* ctc);
s32 comm_nex(WORK* wk, UNK11* ctc);
s32 comm_for2(WORK* wk, UNK11* ctc);
s32 comm_nex2(WORK* wk, UNK11* ctc);
s32 comm_rja(WORK* wk, UNK11* ctc);
s32 comm_uja(WORK* wk, UNK11* ctc);
s32 comm_rja2(WORK* wk, UNK11* ctc);
s32 comm_uja2(WORK* wk, UNK11* ctc);
s32 comm_rja3(WORK* wk, UNK11* ctc);
s32 comm_uja3(WORK* wk, UNK11* ctc);
s32 comm_rja4(WORK* wk, UNK11* ctc);
s32 comm_uja4(WORK* wk, UNK11* );
s32 comm_rja5(WORK* wk, UNK11* ctc);
s32 comm_uja5(WORK* wk, UNK11* );
s32 comm_rja6(WORK* wk, UNK11* ctc);
s32 comm_uja6(WORK* wk, UNK11* ctc);
s32 comm_rja7(WORK* wk, UNK11* ctc);
s32 comm_uja7(WORK* wk, UNK11* ctc);
s32 comm_rmja(WORK* wk, UNK11* ctc);
s32 comm_umja(WORK* wk, UNK11* );
s32 comm_mdat(WORK* wk, UNK11* ctc);
s32 comm_ydat(WORK* wk, UNK11* ctc);
s32 comm_mpos(WORK* wk, UNK11* ctc);
s32 comm_cafr(WORK* wk, UNK11* ctc);
s32 comm_care(WORK* wk, UNK11* ctc);
s32 comm_psxy(WORK* wk, UNK11* ctc);
s32 comm_ps_x(WORK* wk, UNK11* ctc);
s32 comm_ps_y(WORK* wk, UNK11* ctc);
s32 comm_paxy(WORK* wk, UNK11* ctc);
s32 comm_pa_x(WORK* wk, UNK11* ctc);
s32 comm_pa_y(WORK* wk, UNK11* ctc);
s32 comm_exec(WORK* wk, UNK11* ctc);
s32 comm_rngc(WORK* wk, UNK11* ctc);
s32 comm_mxyt(WORK* wk, UNK11* ctc);
s32 comm_pjmp(WORK* wk, UNK11* ctc);
s32 comm_hjmp(WORK* wk, UNK11* ctc);
s32 comm_hclr(WORK* wk, UNK11* );
s32 comm_ixfw(WORK* wk, UNK11* ctc);
s32 comm_ixbw(WORK* wk, UNK11* ctc);
s32 comm_quax(WORK* , UNK11* ctc);
s32 comm_quay(WORK* , UNK11* ctc);
s32 comm_if_s(WORK* wk, UNK11* ctc);
s32 comm_rapp(WORK* wk, UNK11* ctc);
s32 comm_rapk(WORK* wk, UNK11* ctc);
s32 comm_gets(WORK* wk, UNK11* );
s32 comm_s123(WORK* wk, UNK11* ctc);
s32 comm_s456(WORK* wk, UNK11* ctc);
s32 comm_a123(WORK* wk, UNK11* ctc);
s32 comm_a456(WORK* wk, UNK11* ctc);
s32 comm_stop(PLW* wk, UNK11* ctc);
s32 comm_smhf(WORK* wk, UNK11* ctc);
s32 comm_ngme(WORK* wk, UNK11* );
s32 comm_ngem(WORK* wk, UNK11* );
s32 comm_iflb(WORK* wk, UNK11* ctc);
s32 comm_asxy(WORK* wk, UNK11* ctc);
s32 comm_schx(WORK* wk, UNK11* ctc);
s32 comm_schy(WORK* wk, UNK11* ctc);
s32 comm_back(WORK* wk, UNK11* );
s32 comm_mvix(WORK* wk, UNK11* ctc);
s32 comm_sajp(WORK* wk, UNK11* ctc);
s32 comm_ccch(WORK* wk, UNK11* ctc);
s32 comm_wset(WORK* wk, UNK11* ctc);
s32 comm_wswk(WORK* wk, UNK11* ctc);
s32 comm_wadd(WORK* wk, UNK11* ctc);
s32 comm_wceq(WORK* wk, UNK11* ctc);
s32 comm_wcne(WORK* wk, UNK11* ctc);
s32 comm_wcgt(WORK* wk, UNK11* ctc);
s32 comm_wclt(WORK* wk, UNK11* ctc);
s32 comm_wadd2(WORK* wk, UNK11* ctc);
s32 comm_wceq2(WORK* wk, UNK11* ctc);
s32 comm_wcne2(WORK* wk, UNK11* ctc);
s32 comm_wcgt2(WORK* wk, UNK11* ctc);
s32 comm_wclt2(WORK* wk, UNK11* ctc);
s32 comm_rapp2(WORK* wk, UNK11* ctc);
s32 comm_rapk2(WORK* wk, UNK11* ctc);
s32 comm_iflg(WORK* wk, UNK11* ctc);
s32 comm_mpcy(WORK* wk, UNK11* ctc);
s32 comm_epcy(WORK* wk, UNK11* ctc);
s32 comm_imgs(PLW* wk, UNK11* ctc);
s32 comm_imgc(PLW* wk, UNK11* ctc);
s32 comm_rvxy(WORK* wk, UNK11* ctc);
s32 comm_rv_x(WORK* wk, UNK11* ctc);
s32 comm_rv_y(WORK* wk, UNK11* ctc);
s32 comm_ccfl(PLW* wk, UNK11* );
s32 comm_myhp(WORK* wk, UNK11* ctc);
s32 comm_emhp(WORK* wk, UNK11* ctc);
s32 comm_exbgs(WORK* , UNK11* );
s32 comm_exbgc(WORK* , UNK11* );
s32 comm_atmf(PLW* wk, UNK11* ctc);
s32 comm_chkwf(PLW* wk, UNK11* ctc);
s32 comm_retmj(PLW* wk, UNK11* );
s32 comm_sstx(WORK* wk, UNK11* ctc);
s32 comm_ssty(WORK* wk, UNK11* ctc);
s32 comm_ngda(WORK* wk, UNK11* ctc);
s32 comm_flip(WORK* wk, UNK11* );
s32 comm_kage(WORK* wk, UNK11* ctc);
s32 comm_dspf(WORK* wk, UNK11* ctc);
s32 comm_ifrlf(WORK* wk, UNK11* ctc);
s32 comm_srlf(WORK* wk, UNK11* ctc);
s32 comm_bgrlf(WORK* wk, UNK11* ctc);
s32 comm_scmd(PLW* wk, UNK11* ctc);
s32 comm_rljmp(WORK* wk, UNK11* ctc);
s32 comm_ifs2(WORK* wk, UNK11* ctc);
s32 comm_abbak(WORK* wk, UNK11* );
s32 comm_sse(WORK* wk, UNK11* ctc);
s32 comm_s_chg(WORK* wk, UNK11* ctc);
s32 comm_schg2(WORK* wk, UNK11* ctc);
s32 comm_rhsja(PLW* wk, UNK11* ctc);
s32 comm_uhsja(PLW* wk, UNK11* );
s32 comm_ifcom(WORK* wk, UNK11* ctc);
s32 comm_axjmp(WORK* wk, UNK11* ctc);
s32 comm_ayjmp(WORK* wk, UNK11* ctc);
s32 comm_ifs3(WORK* wk, UNK11* ctc);
s32 comm_wca(WORK* wk, UNK11* );
void setupCharTableData(WORK* wk, s32 clr, s32 info);
void grade_add_onaji_waza(s16 ix);
void char_move(WORK* wk);
void check_cgd_patdat2(WORK* wk);
extern u8 test_flag;
void setup_comm_back(WORK* wk);
void setup_comm_retmj(WORK* wk);
void check_cm_extended_code(WORK* wk);
void check_cgd_patdat(WORK* wk);
u16 get_comm_if_lever(WORK* wk);
s16 decord_if_jump(WORK* wk, UNK11* cpc, s16 ix);
extern BG bg_w;
extern s16 bs2_floor[3];
extern const s32 (*effinitjptbl[])();
s16 get_em_body_range(WORK* wk);
void setup_mvxy_data(WORK* wk, u16 ix);
void reset_mvxy_data(WORK* wk);
s32 random_32();
extern u8 ixbfw_cut;
void pp_screen_quake(s16 ix);
u16 get_comm_if_shot(WORK* wk);
extern u8 pcon_dp_flag;
extern WORK_CP wcp[2];
void setup_shell_hit_stop(WORK* wk, s16 tm, s16 fl);
extern u16 Game_timer;
u16 get_comm_if_lvsh(WORK* wk);
extern u8 My_char[2];
extern s16 Max_vitality;
void waza_flag_clear_only_1(s16 pl_id, s16 wznum);
s32 random_16();
extern void (*sound_effect_request[])();
u16 check_xcopy_filter_se_req(WORK* wk);
u16 get_comm_if_shot_now_off(WORK* wk);
u16 get_comm_if_shot_now(WORK* wk);
void set_new_attnum(WORK* wk);
void set_jugde_area(WORK* wk);
extern const u8 plpat_rno_filter[];
extern const u16 chain_hidou_nm_ground_table[];
extern const u16 chain_normal_ground_table[];
s16 hikusugi_check(WORK* wk);
extern const u16 chain_hidou_nm_air_table[];
extern const u16 chain_normal_air_table[];
extern PLW plw[2];
void grade_add_att_renew(WORK_Other* wk);
s16 cal_attdir(WORK* wk);
void add_sp_arts_gauge_init(PLW* wk);
void setup_metamor_kezuri(WORK* wk);

const s16 jphos_table[16] = { 0x0000, 0xFFF0, 0xFFF4, 0xFFF8, 0xFFFC, 0x0004, 0x0008, 0x000C,
                              0x0010, 0x0014, 0x0018, 0x001C, 0x0020, 0x0024, 0x0028, 0x002C };

const s16 kezuri_pow_table[5] = { 0, 4, 8, 16, 24 };

s32 (*const decode_chcmd[125])() = {
    comm_dummy, comm_roa,   comm_end,   comm_jmp,   comm_jpss,  comm_jsr,   comm_ret,   comm_sps,   comm_setr,
    comm_addr,  comm_if_l,  comm_djmp,  comm_for,   comm_nex,   comm_for2,  comm_nex2,  comm_rja,   comm_uja,
    comm_rja2,  comm_uja2,  comm_rja3,  comm_uja3,  comm_rja4,  comm_uja4,  comm_rja5,  comm_uja5,  comm_rja6,
    comm_uja6,  comm_rja7,  comm_uja7,  comm_rmja,  comm_umja,  comm_mdat,  comm_ydat,  comm_mpos,  comm_cafr,
    comm_care,  comm_psxy,  comm_ps_x,  comm_ps_y,  comm_paxy,  comm_pa_x,  comm_pa_y,  comm_exec,  comm_rngc,
    comm_mxyt,  comm_pjmp,  comm_hjmp,  comm_hclr,  comm_ixfw,  comm_ixbw,  comm_quax,  comm_quay,  comm_if_s,
    comm_rapp,  comm_rapk,  comm_gets,  comm_s123,  comm_s456,  comm_a123,  comm_a456,  comm_stop,  comm_smhf,
    comm_ngme,  comm_ngem,  comm_iflb,  comm_asxy,  comm_schx,  comm_schy,  comm_back,  comm_mvix,  comm_sajp,
    comm_ccch,  comm_wset,  comm_wswk,  comm_wadd,  comm_wceq,  comm_wcne,  comm_wcgt,  comm_wclt,  comm_wadd2,
    comm_wceq2, comm_wcne2, comm_wcgt2, comm_wclt2, comm_rapp2, comm_rapk2, comm_iflg,  comm_mpcy,  comm_epcy,
    comm_imgs,  comm_imgc,  comm_rvxy,  comm_rv_x,  comm_rv_y,  comm_ccfl,  comm_myhp,  comm_emhp,  comm_exbgs,
    comm_exbgc, comm_atmf,  comm_chkwf, comm_retmj, comm_sstx,  comm_ssty,  comm_ngda,  comm_flip,  comm_kage,
    comm_dspf,  comm_ifrlf, comm_srlf,  comm_bgrlf, comm_scmd,  comm_rljmp, comm_ifs2,  comm_abbak, comm_sse,
    comm_s_chg, comm_schg2, comm_rhsja, comm_uhsja, comm_ifcom, comm_axjmp, comm_ayjmp, comm_ifs3
};

s32 (*const decode_if_lever[16])() = { comm_dummy, comm_ret,  comm_uja,   comm_uja2, comm_uja3, comm_uja4,
                                       comm_uja5,  comm_uja6, comm_uja7,  comm_umja, comm_back, comm_nex,
                                       comm_nex2,  comm_wca,  comm_retmj, comm_abbak };

const u16 acatkoa_table[65] = { 4,   4,   8,   8,   8,   8,   8,   8,   16,  16,  16,  16,  16,  16,  16,  16,  32,
                                32,  32,  32,  32,  32,  32,  32,  64,  64,  64,  64,  64,  64,  64,  64,  128, 128,
                                128, 128, 128, 128, 128, 128, 256, 256, 256, 256, 256, 256, 256, 256, 128, 128, 128,
                                128, 128, 128, 128, 128, 256, 256, 256, 256, 256, 256, 256, 256, 2048 };

void set_char_move_init(WORK* wk, s16 koc, s16 index) {
    wk->now_koc = koc;
    wk->char_index = index;
    wk->set_char_ad = &wk->char_table[koc][wk->char_table[koc][index] / 4];
    setupCharTableData(wk, 1, 1);
    wk->cg_ix = -wk->cgd_type;
    wk->cg_ctr = 1;
    wk->cg_next_ix = 0;
    wk->old_cgnum = 0;
    wk->cg_wca_ix = 0;
    wk->cmoa.koc = wk->now_koc;
    wk->cmoa.ix = wk->char_index;
    wk->cmoa.pat = 1;
    wk->cmwk[8] = 0;
    wk->cmwk[15] = 0;
    wk->kow = wk->kind_of_waza;

    if (wk->work_id & 0xF) {
        wk->at_koa = acatkoa_table[wk->kind_of_waza];
    }

    if (wk->work_id == 1) {
        ((PLW*)wk)->tc_1st_flag = 0;

        if (wk->now_koc == 4 || wk->now_koc == 5) {
            grade_add_onaji_waza(wk->id);
        }

        ((PLW*)wk)->ja_nmj_rno = 0;
        sub_0004384A(wk);
    }

    wk->K5_init_flag = 1;
    char_move(wk);
}

void setupCharTableData(WORK* wk, s32 clr, s32 info) {
    u32* dst = (u32*)&wk->cg_type;
    u32* src;
    s32 i;

    if (info != 0) {
        src = wk->set_char_ad;
        dst[-1] = src[-1];
        dst[-2] = src[-2];

        if (clr != 0) {
            for (i = 0; i < 6; i++) {
                dst[i] = 0;
            }
        }
    } else {
        src = wk->set_char_ad + wk->cg_ix;

        for (i = 0; i < wk->cgd_type; i++) {
            dst[i] = src[i];
        }
    }
}

void set_char_move_init2(WORK* wk, s16 koc, s16 index, s16 ip, s16 scf) {
    u8 pst;
    u8 kow;

    if (index < 0) {
        index = 0;
    }

    if (ip <= 0) {
        ip = 1;
    }

    pst = wk->pat_status;
    kow = wk->kind_of_waza;
    wk->now_koc = koc;
    wk->char_index = index;
    wk->set_char_ad = wk->char_table[koc] + (wk->char_table[koc][index] / 4);
    setupCharTableData(wk, 1, 1);
    wk->cg_ix = (ip - 1) * wk->cgd_type - wk->cgd_type;
    wk->cg_ctr = 1;
    wk->cg_next_ix = 0;
    wk->old_cgnum = 0;
    wk->cg_wca_ix = 0;

    if (wk->cmoa.pat == 0) {
        wk->cmoa.koc = wk->now_koc;
        wk->cmoa.ix = wk->char_index;
        wk->cmoa.pat = 1;
    }

    if (scf) {
        wk->pat_status = pst;
        wk->kind_of_waza = kow;
    } else {
        wk->kow = wk->kind_of_waza;
    }

    if (wk->work_id & 0xF) {
        wk->at_koa = acatkoa_table[wk->kind_of_waza];
    }

    wk->K5_init_flag = 1;
    char_move(wk);
}

void exset_char_move_init(WORK* wk, s16 koc, s16 index) {
    u8 now_ctr;

    wk->now_koc = koc;
    wk->char_index = index;
    wk->set_char_ad = &wk->char_table[koc][wk->char_table[koc][index] / 4];
    now_ctr = wk->cg_ctr;
    setupCharTableData(wk, 0, 0);
    wk->cg_ctr = now_ctr;
    wk->cmoa.koc = wk->now_koc;
    wk->cmoa.ix = wk->char_index;
    wk->cmoa.pat = 1;
    wk->K5_init_flag = 1;
    check_cgd_patdat2(wk);
}

void char_move_z(WORK* wk) {
    if (test_flag) {
        wk->cg_next_ix = 0;
    }

    wk->cg_ctr = 1;
    wk->K5_init_flag = 1;
    char_move(wk);
}

void char_move_wca(WORK* wk) {
    wk->cg_next_ix = 0;
    wk->cg_ix = (wk->cg_wca_ix - 1) * wk->cgd_type - wk->cgd_type;
    wk->cg_ctr = 1;
    wk->K5_init_flag = 1;
    char_move(wk);
}

void char_move_wca_init(WORK* wk) {
    wk->cg_next_ix = 0;
    wk->cg_ix = (wk->cg_wca_ix - 1) * wk->cgd_type - wk->cgd_type;
    wk->cg_ctr = 1;
    wk->K5_init_flag = 1;
}

s32 comm_wca(WORK* wk, UNK11* /* unused */) {
    char_move_wca_init(wk);
    return 1;
}

void char_move_index(WORK* wk, s16 ix) {
    wk->cg_next_ix = 0;
    wk->cg_ix = (ix - 1) * wk->cgd_type - wk->cgd_type;
    wk->cg_ctr = 1;
    wk->K5_init_flag = 1;
    char_move(wk);
}

void char_move_cmja(WORK* wk) {
    setup_comm_back(wk);
    set_char_move_init2(wk, wk->cmja.koc, wk->cmja.ix, wk->cmja.pat, 0);
}

void char_move_cmj4(WORK* wk) {
    setup_comm_back(wk);
    set_char_move_init2(wk, wk->cmj4.koc, wk->cmj4.ix, wk->cmj4.pat, 0);
}

void char_move_cmms(WORK* wk) {
    setup_comm_back(wk);
    set_char_move_init2(wk, wk->cmms.koc, wk->cmms.ix, wk->cmms.pat, 0);
}

void char_move_cmms2(WORK* wk) {
    u32* to_ram;
    s16 i;
    s16 now_cgd;

    setup_comm_back(wk);
    now_cgd = wk->cgd_type;
    wk->now_koc = wk->cmms.koc;
    wk->char_index = wk->cmms.ix;
    wk->set_char_ad = &wk->char_table[wk->now_koc][wk->char_table[wk->now_koc][wk->char_index] / 4];
    setupCharTableData(wk, 0, 1);

    if (now_cgd > wk->cgd_type) {
        to_ram = (u32*)&wk->cg_wca_ix;

        for (i = 0; i < (now_cgd - wk->cgd_type); i++) {
            *--to_ram = 0;
        }
    }

    wk->cg_ix = (wk->cmms.pat - 1) * wk->cgd_type - wk->cgd_type;
    wk->cg_ctr = 1;
    wk->cg_next_ix = 0;
    wk->old_cgnum = 0;
    wk->cg_wca_ix = 0;
    wk->kow = wk->kind_of_waza;
}

s32 char_move_cmms3(PLW* wk) {
    UNK11* cpc;
    u32* to_ram;
    s16 i;
    s16 now_cgd;

    wk->meoshi_jump_flag = 1;
    setup_comm_retmj(&wk->wu);
    setup_comm_back(&wk->wu);
    now_cgd = wk->wu.cgd_type;
    wk->wu.now_koc = wk->wu.cmms.koc;
    wk->wu.char_index = wk->wu.cmms.ix;
    wk->wu.set_char_ad = &wk->wu.char_table[wk->wu.now_koc][wk->wu.char_table[wk->wu.now_koc][wk->wu.char_index] / 4];
    setupCharTableData(&wk->wu, 0, 1);
    wk->wu.cg_ix = wk->wu.cmms.pat * wk->wu.cgd_type - wk->wu.cgd_type;
    wk->wu.kow = wk->wu.kind_of_waza;

    while (1) {
        cpc = (UNK11*)&wk->wu.set_char_ad[wk->wu.cg_ix];

        if (cpc->code >= 0x100) {
            break;
        }

        if (decode_chcmd[cpc->code](wk, cpc) != 0) {
            wk->wu.cg_ix += wk->wu.cgd_type;
        } else if (wk->meoshi_jump_flag != 0) {
            break;
        } else {
            return 0;
        }
    }

    if (now_cgd > wk->wu.cgd_type) {
        to_ram = (u32*)&wk->wu.cg_wca_ix;

        for (i = 0; i < now_cgd - wk->wu.cgd_type; i++) {
            *--to_ram = 0;
        }
    }

    wk->wu.cg_ix -= wk->wu.cgd_type;
    wk->wu.cg_ctr = 1;
    wk->wu.cg_next_ix = 0;
    wk->wu.old_cgnum = 0;
    wk->wu.cg_wca_ix = 0;
    wk->meoshi_jump_flag = 0;
    return 1;
}

void char_move_cmhs(PLW* wk) {
    if (wk->hsjp_ok != 0) {
        setup_comm_back(&wk->wu);
        wk->hsjp_ok = 0;
        set_char_move_init2(&wk->wu, wk->wu.cmhs.koc, wk->wu.cmhs.ix, wk->wu.cmhs.pat, 0);
    }
}

void char_move(WORK* wk) {
    wk->K5_exec_ok = 1;

    if (--wk->cg_ctr == 0) {
        check_cm_extended_code(wk);
    }
}

void check_cm_extended_code(WORK* wk) {
    UNK11* cpc;

    if (wk->cg_next_ix) {
        wk->cg_ix = (wk->cg_next_ix - 1) * wk->cgd_type;
    } else {
        wk->cg_ix += wk->cgd_type;
    }

    while (1) {
        cpc = (UNK11*)(wk->set_char_ad + wk->cg_ix);

        if (cpc->code >= 0x100) {
            check_cgd_patdat(wk);
            return;
        }

        if (decode_chcmd[cpc->code](wk, cpc) == 0) {
            break;
        }

        wk->cg_ix += wk->cgd_type;
    }
}

s32 comm_dummy(WORK* /* unused */, UNK11* /* unused */) {
    return 1;
}

s32 comm_roa(WORK* wk, UNK11* /* unused */) {
    if (wk->cmoa.pat == 0) {
        wk->cmoa.koc = wk->now_koc;
        wk->cmoa.ix = wk->char_index;
        wk->cmoa.pat = 1;
    }

    set_char_move_init2(wk, wk->cmoa.koc, wk->cmoa.ix, wk->cmoa.pat, 0);
    return 0;
}

s32 comm_end(WORK* wk, UNK11* ctc) {
    wk->cg_ix = (ctc->pat - 2) * wk->cgd_type;
    return 1;
}

s32 comm_jmp(WORK* wk, UNK11* ctc) {
    setup_comm_back(wk);
    set_char_move_init2(wk, ctc->koc, ctc->ix, ctc->pat, 0);
    return 0;
}

s32 comm_jpss(WORK* wk, UNK11* ctc) {
    setup_comm_back(wk);
    set_char_move_init2(wk, ctc->koc, ctc->ix, ctc->pat, 1);
    return 0;
}

s32 comm_jsr(WORK* wk, UNK11* ctc) {
    wk->cmsw.koc = wk->now_koc;
    wk->cmsw.ix = wk->char_index;
    wk->cmsw.pat = (wk->cg_ix / wk->cgd_type) + 2;
    set_char_move_init2(wk, ctc->koc, ctc->ix, ctc->pat, 0);
    return 0;
}

s32 comm_ret(WORK* wk, UNK11* /* unused */) {
    set_char_move_init2(wk, wk->cmsw.koc, wk->cmsw.ix, wk->cmsw.pat, 0);
    return 0;
}

s32 comm_sps(WORK* wk, UNK11* ctc) {
    wk->pat_status = ctc->pat;
    return 1;
}

s32 comm_setr(WORK* wk, UNK11* ctc) {
    wk->routine_no[ctc->koc] = ctc->ix;
    return 1;
}

s32 comm_addr(WORK* wk, UNK11* ctc) {
    wk->routine_no[ctc->koc] += ctc->ix;
    return 1;
}

s32 comm_if_l(WORK* wk, UNK11* ctc) {
    u16 lvdat;
    u16 my_lvdat;

    if (ctc->koc & 0x4000) {
        my_lvdat = wk->cmwk[ctc->koc & 0xF];
    } else {
        my_lvdat = ctc->koc;
    }

    lvdat = get_comm_if_lever(wk);

    if (!(my_lvdat & 0x7FFF)) {
        if (lvdat == 0) {
            return decord_if_jump(wk, ctc, ctc->ix);
        }

        return decord_if_jump(wk, ctc, ctc->pat);
    }

    if (my_lvdat & 0x8000) {
        if (lvdat == (my_lvdat & 0xF)) {
            return decord_if_jump(wk, ctc, ctc->ix);
        }

        return decord_if_jump(wk, ctc, ctc->pat);
    }

    if (lvdat & my_lvdat) {
        return decord_if_jump(wk, ctc, ctc->ix);
    }

    return decord_if_jump(wk, ctc, ctc->pat);
}

s32 comm_djmp(WORK* wk, UNK11* ctc) {
    u8 ldir;

    if ((ldir = sub_000E4CA8((PLW*)wk))) {
        if (ldir == 1) {
            return decord_if_jump(wk, ctc, ctc->ix);
        }

        return decord_if_jump(wk, ctc, ctc->pat);
    }

    return decord_if_jump(wk, ctc, ctc->koc);
}

s32 comm_for(WORK* wk, UNK11* ctc) {
    if (ctc->pat & 0x4000) {
        wk->cmlp.code = wk->cmwk[ctc->pat & 0xF];
    } else {
        wk->cmlp.code = ctc->pat;
    }

    wk->cmlp.koc = wk->now_koc;
    wk->cmlp.ix = wk->char_index;
    wk->cmlp.pat = wk->cg_ix / wk->cgd_type + 2;
    return 1;
}

s32 comm_nex(WORK* wk, UNK11* ctc) {
    if (wk->cmlp.code) {
        if (--wk->cmlp.code > 0) {
            set_char_move_init2(wk, wk->cmlp.koc, wk->cmlp.ix, wk->cmlp.pat, 1);
            return 0;
        }
    }

    return 1;
}

s32 comm_for2(WORK* wk, UNK11* ctc) {
    if (ctc->pat & 0x4000) {
        wk->cml2.code = wk->cmwk[ctc->pat & 0xF];
    } else {
        wk->cml2.code = ctc->pat;
    }

    wk->cml2.koc = wk->now_koc;
    wk->cml2.ix = wk->char_index;
    wk->cml2.pat = (wk->cg_ix / wk->cgd_type) + 2;
    return 1;
}

s32 comm_nex2(WORK* wk, UNK11* ctc) {
    if (wk->cml2.code && --wk->cml2.code > 0) {
        set_char_move_init2(wk, wk->cml2.koc, wk->cml2.ix, wk->cml2.pat, 1);
        return 0;
    }

    return 1;
}

s32 comm_rja(WORK* wk, UNK11* ctc) {
    wk->cmja.koc = ctc->koc;
    wk->cmja.ix = ctc->ix;
    wk->cmja.pat = ctc->pat;
    return 1;
}

s32 comm_uja(WORK* wk, UNK11* ctc) {
    setup_comm_back(wk);
    set_char_move_init2(wk, wk->cmja.koc, wk->cmja.ix, wk->cmja.pat, 0);
    return 0;
}

s32 comm_rja2(WORK* wk, UNK11* ctc) {
    wk->cmj2.koc = ctc->koc;
    wk->cmj2.ix = ctc->ix;
    wk->cmj2.pat = ctc->pat;
    return 1;
}

s32 comm_uja2(WORK* wk, UNK11* ctc) {
    setup_comm_back(wk);
    set_char_move_init2(wk, wk->cmj2.koc, wk->cmj2.ix, wk->cmj2.pat, 0);
    return 0;
}

s32 comm_rja3(WORK* wk, UNK11* ctc) {
    wk->cmj3.koc = ctc->koc;
    wk->cmj3.ix = ctc->ix;
    wk->cmj3.pat = ctc->pat;
    return 1;
}

s32 comm_uja3(WORK* wk, UNK11* ctc) {
    setup_comm_back(wk);
    set_char_move_init2(wk, wk->cmj3.koc, wk->cmj3.ix, wk->cmj3.pat, 0);
    return 0;
}

s32 comm_rja4(WORK* wk, UNK11* ctc) {
    wk->cmj4.koc = ctc->koc;
    wk->cmj4.ix = ctc->ix;
    wk->cmj4.pat = ctc->pat;
    return 1;
}

s32 comm_uja4(WORK* wk, UNK11* /* unused */) {
    setup_comm_back(wk);
    set_char_move_init2(wk, wk->cmj4.koc, wk->cmj4.ix, wk->cmj4.pat, 0);
    return 0;
}

s32 comm_rja5(WORK* wk, UNK11* ctc) {
    wk->cmj5.koc = ctc->koc;
    wk->cmj5.ix = ctc->ix;
    wk->cmj5.pat = ctc->pat;
    return 1;
}

s32 comm_uja5(WORK* wk, UNK11* /* unused */) {
    setup_comm_back(wk);
    set_char_move_init2(wk, wk->cmj5.koc, wk->cmj5.ix, wk->cmj5.pat, 0);
    return 0;
}

s32 comm_rja6(WORK* wk, UNK11* ctc) {
    wk->cmj6.koc = ctc->koc;
    wk->cmj6.ix = ctc->ix;
    wk->cmj6.pat = ctc->pat;
    return 1;
}

s32 comm_uja6(WORK* wk, UNK11* ctc) {
    setup_comm_back(wk);
    set_char_move_init2(wk, wk->cmj6.koc, wk->cmj6.ix, wk->cmj6.pat, 0);
    return 0;
}

s32 comm_rja7(WORK* wk, UNK11* ctc) {
    wk->cmj7.koc = ctc->koc;
    wk->cmj7.ix = ctc->ix;
    wk->cmj7.pat = ctc->pat;
    return 1;
}

s32 comm_uja7(WORK* wk, UNK11* ctc) {
    setup_comm_back(wk);
    set_char_move_init2(wk, wk->cmj7.koc, wk->cmj7.ix, wk->cmj7.pat, 0);
    return 0;
}

s32 comm_rmja(WORK* wk, UNK11* ctc) {
    wk->cmms.koc = ctc->koc;
    wk->cmms.ix = ctc->ix;
    wk->cmms.pat = ctc->pat;
    return 1;
}

s32 comm_umja(WORK* wk, UNK11* /* unused */) {
    setup_comm_back(wk);
    set_char_move_init2(wk, wk->cmms.koc, wk->cmms.ix, wk->cmms.pat, 0);
    return 0;
}

s32 comm_mdat(WORK* wk, UNK11* ctc) {
    wk->cmmd.koc = ctc->koc;
    wk->cmmd.ix = ctc->ix;
    wk->cmmd.pat = ctc->pat;
    return 1;
}

s32 comm_ydat(WORK* wk, UNK11* ctc) {
    wk->cmyd.koc = ctc->koc;
    wk->cmyd.ix = ctc->ix;
    wk->cmyd.pat = ctc->pat;
    return 1;
}

s32 comm_mpos(WORK* wk, UNK11* ctc) {
    wk->att.hit_mark = ctc->koc;
    wk->hit_mark_x = ctc->ix;
    wk->hit_mark_y = ctc->pat;
    return 1;
}

s32 comm_cafr(WORK* wk, UNK11* ctc) {
    wk->cmcf.koc = ctc->koc;
    wk->cmcf.ix = ctc->ix;
    wk->cmcf.pat = ctc->pat;
    return 1;
}

s32 comm_care(WORK* wk, UNK11* ctc) {
    wk->cmcr.koc = ctc->koc;
    wk->cmcr.ix = ctc->ix;
    wk->cmcr.pat = ctc->pat;
    return 1;
}

s32 comm_psxy(WORK* wk, UNK11* ctc) {
    WORK* emwk;

    switch (ctc->koc) {
    case 0:
        wk->xyz[0].disp.pos = ctc->ix;
        wk->xyz[1].disp.pos = ctc->pat;
        break;

    case 2:
        wk->xyz[0].disp.pos = ctc->ix;
        wk->xyz[1].disp.pos = ctc->pat;
        /* fallthrough */

    default:
        emwk = (WORK*)wk->target_adrs;
        emwk->xyz[0].disp.pos = ctc->ix;
        emwk->xyz[1].disp.pos = ctc->pat;
        break;
    }

    return 1;
}

s32 comm_ps_x(WORK* wk, UNK11* ctc) {
    WORK* emwk;

    switch (ctc->koc) {
    case 0:
        wk->xyz[0].disp.pos = ctc->ix;
        break;

    case 2:
        wk->xyz[0].disp.pos = ctc->ix;
        /* fallthrough */

    default:
        emwk = (WORK*)wk->target_adrs;
        emwk->xyz[0].disp.pos = ctc->ix;
        break;
    }

    return 1;
}

s32 comm_ps_y(WORK* wk, UNK11* ctc) {
    WORK* emwk;

    if (wk->work_id == 1) {
        switch (ctc->koc) {
        case 0:
            if (bg_w.stage == 20 && ((PLW*)wk)->bs2_on_car && ctc->pat < bs2_floor[2]) {
                wk->xyz[1].disp.pos = bs2_floor[2];
            } else {
                wk->xyz[1].disp.pos = ctc->pat;
            }

            break;

        case 2:
            wk->xyz[1].disp.pos = ctc->pat;
            /* fallthrough */

        default:
            emwk = (WORK*)wk->target_adrs;
            emwk->xyz[1].disp.pos = ctc->pat;
            break;
        }

        return 1;
    }

    switch (ctc->koc) {
    case 0:
        wk->xyz[1].disp.pos = ctc->pat;
        break;

    case 2:
        wk->xyz[1].disp.pos = ctc->pat;
        /* fallthrough */

    default:
        emwk = (WORK*)wk->target_adrs;
        emwk->xyz[1].disp.pos = ctc->pat;
        break;
    }

    return 1;
}

s32 comm_paxy(WORK* wk, UNK11* ctc) {
    WORK* emwk;

    switch (ctc->koc) {
    case 0:
        if (wk->rl_flag) {
            wk->xyz[0].cal += ctc->ix << 8;
        } else {
            wk->xyz[0].cal -= ctc->ix << 8;
        }

        wk->xyz[1].cal += ctc->pat << 8;
        break;

    case 2:
        if (wk->rl_flag) {
            wk->xyz[0].cal += ctc->ix << 8;
        } else {
            wk->xyz[0].cal -= ctc->ix << 8;
        }

        wk->xyz[1].cal += ctc->pat << 8;
        /* fallthrough */

    default:
        emwk = (WORK*)wk->target_adrs;

        if (emwk->rl_flag) {
            emwk->xyz[0].cal += ctc->ix << 8;
        } else {
            emwk->xyz[0].cal -= ctc->ix << 8;
        }

        emwk->xyz[1].cal += ctc->pat << 8;
        break;
    }

    return 1;
}

s32 comm_pa_x(WORK* wk, UNK11* ctc) {
    WORK* emwk;

    switch (ctc->koc) {
    case 0:
        if (wk->rl_flag) {
            wk->xyz[0].cal += ctc->ix << 8;
        } else {
            wk->xyz[0].cal -= ctc->ix << 8;
        }

        break;

    case 2:
        if (wk->rl_flag) {
            wk->xyz[0].cal += ctc->ix << 8;
        } else {
            wk->xyz[0].cal -= ctc->ix << 8;
        }

        /* fallthrough */

    default:
        emwk = (WORK*)wk->target_adrs;

        if (emwk->rl_flag) {
            emwk->xyz[0].cal += ctc->ix << 8;
        } else {
            emwk->xyz[0].cal -= ctc->ix << 8;
        }

        break;
    }

    return 1;
}

s32 comm_pa_y(WORK* wk, UNK11* ctc) {
    WORK* emwk;

    switch (ctc->koc) {
    case 0:
        wk->xyz[1].cal += ctc->pat << 8;
        break;

    case 2:
        wk->xyz[1].cal += ctc->pat << 8;
        /* fallthrough */

    default:
        emwk = (WORK*)wk->target_adrs;
        emwk->xyz[1].cal += ctc->pat << 8;
        break;
    }

    return 1;
}

s32 comm_exec(WORK* wk, UNK11* ctc) {
    effinitjptbl[ctc->koc](wk, (u8)ctc->ix);
    return 1;
}

s32 comm_rngc(WORK* wk, UNK11* ctc) {
    s16 rngdat;

    if (wk->work_id == 1) {
        rngdat = get_em_body_range(wk);
    } else {
        rngdat = get_em_body_range((WORK*)((WORK_Other*)wk)->my_master);
    }

    if (rngdat > ctc->koc) {
        return decord_if_jump(wk, ctc, ctc->pat);
    }

    return decord_if_jump(wk, ctc, ctc->ix);
}

s32 comm_mxyt(WORK* wk, UNK11* ctc) {
    if (ctc->koc) {
        setup_mvxy_data(wk, ctc->koc);
    } else {
        reset_mvxy_data(wk);
    }

    return 1;
}

s32 comm_pjmp(WORK* wk, UNK11* ctc) {
    if (random_32() < ctc->koc) {
        return decord_if_jump(wk, ctc, ctc->ix);
    }

    return decord_if_jump(wk, ctc, ctc->pat);
}

s32 comm_hjmp(WORK* wk, UNK11* ctc) {
    if (wk->meoshi_hit_flag != 0 && wk->hf.hit_flag != 0) {
        if (wk->hf.hit_flag & 0x303) {
            return decord_if_jump(wk, ctc, ctc->koc);
        }

        if (wk->hf.hit_flag & 0x3030) {
            return decord_if_jump(wk, ctc, ctc->ix);
        }

        if (wk->hf.hit_flag & 0xC0C0) {
            return decord_if_jump(wk, ctc, ctc->pat);
        }
    }

    return 1;
}

s32 comm_hclr(WORK* wk, UNK11* /* unused */) {
    wk->hf.hit_flag = 0;
    return 1;
}

s32 comm_ixfw(WORK* wk, UNK11* ctc) {
    if (test_flag == 0 || ixbfw_cut == 0) {
        wk->cg_ix += (ctc->pat - 1) * wk->cgd_type;
    }

    return 1;
}

s32 comm_ixbw(WORK* wk, UNK11* ctc) {
    if ((test_flag == 0) || (ixbfw_cut == 0)) {
        wk->cg_ix -= (ctc->pat + 1) * wk->cgd_type;
    }

    return 1;
}

s32 comm_quax(WORK* /* unused */, UNK11* ctc) {
    bg_w.quake_x_index = ctc->koc;
    return 1;
}

s32 comm_quay(WORK* /* unused */, UNK11* ctc) {
    bg_w.quake_y_index = ctc->koc;
    pp_screen_quake(bg_w.quake_y_index);
    return 1;
}

s32 comm_if_s(WORK* wk, UNK11* ctc) {
    u16 shdat;
    u16 my_shdat;

    if (ctc->koc & 0x4000) {
        my_shdat = wk->cmwk[ctc->koc & 0xF];
    } else {
        my_shdat = ctc->koc;
    }

    shdat = get_comm_if_shot(wk);

    if (wk->work_id == 1 && ((PLW*)wk)->player_number == 16 && ((PLW*)wk)->spmv_ng_flag & 2 && my_shdat == 0x440 &&
        pcon_dp_flag) {
        shdat = 0;
    }

    if (my_shdat == shdat) {
        return decord_if_jump(wk, ctc, ctc->ix);
    }

    return decord_if_jump(wk, ctc, ctc->pat);
}

s32 comm_rapp(WORK* wk, UNK11* ctc) {
    if (wk->work_id == 1) {
        if (wcp[wk->id].waza_flag[9]) {
            setup_comm_back(wk);
            set_char_move_init2(wk, ctc->koc, ctc->ix, ctc->pat, 1);
            return 0;
        }

        return 1;
    }

    if (wcp[((WORK_Other*)wk)->master_id & 1].waza_flag[9]) {
        setup_comm_back(wk);
        set_char_move_init2(wk, ctc->koc, ctc->ix, ctc->pat, 1);
        return 0;
    }

    return 1;
}

s32 comm_rapk(WORK* wk, UNK11* ctc) {
    if (wk->work_id == 1) {
        if (wcp[wk->id].waza_flag[11]) {
            setup_comm_back(wk);
            set_char_move_init2(wk, ctc->koc, ctc->ix, ctc->pat, 1);
            return 0;
        }

        return 1;
    }

    if (wcp[((WORK_Other*)wk)->master_id & 1].waza_flag[11]) {
        setup_comm_back(wk);
        set_char_move_init2(wk, ctc->koc, ctc->ix, ctc->pat, 1);
        return 0;
    }

    return 1;
}

s32 comm_gets(WORK* wk, UNK11* /* unused */) {
    setupCharTableData(wk, 0, 1);
    return 1;
}

s32 comm_s123(WORK* wk, UNK11* ctc) {
    wk->routine_no[1] = ctc->koc;
    wk->routine_no[2] = ctc->ix;
    wk->routine_no[3] = ctc->pat;
    return 1;
}

s32 comm_s456(WORK* wk, UNK11* ctc) {
    wk->routine_no[4] = ctc->koc;
    wk->routine_no[5] = ctc->ix;
    wk->routine_no[6] = ctc->pat;
    return 1;
}

s32 comm_a123(WORK* wk, UNK11* ctc) {
    wk->routine_no[4] += ctc->koc;
    wk->routine_no[5] += ctc->ix;
    wk->routine_no[6] += ctc->pat;
    return 1;
}

s32 comm_a456(WORK* wk, UNK11* ctc) {
    wk->routine_no[4] += ctc->koc;
    wk->routine_no[5] += ctc->ix;
    wk->routine_no[6] += ctc->pat;
    return 1;
}

s32 comm_stop(PLW* wk, UNK11* ctc) {
    PLW* wk2;

    if (test_flag == 0) {
        wk->wu.dm_stop = 0;
        wk->wu.hit_stop = ctc->koc;
        wk2 = (PLW*)wk->wu.target_adrs;
        wk2->wu.hit_stop = ctc->ix;
        wk2->sa_stop_sai = ctc->ix - 4;

        if (wk2->sa_stop_sai < 0) {
            wk2->sa_stop_sai = 1;
        }

        setup_shell_hit_stop(&wk->wu, ctc->ix, ctc->pat);
        setup_shell_hit_stop(&wk2->wu, ctc->ix, 0);
        wk->sa_stop_flag = 0;
        wk2->sa_stop_flag = 2;
        wk2->just_sa_stop_timer = Game_timer;
    }

    return 1;
}

s32 comm_smhf(WORK* wk, UNK11* ctc) {
    wk->meoshi_hit_flag = ctc->koc;
    return 1;
}

s32 comm_ngme(WORK* wk, UNK11* /* unused */) {
    WORK* emwk;

    emwk = (WORK*)wk->hit_adrs;
    emwk->routine_no[1] = 3;
    emwk->routine_no[2] = 1;
    emwk->routine_no[3] = 1;

    if (test_flag) {
        wk->cmyd.pat = 1;
    }

    return 1;
}

s32 comm_ngem(WORK* wk, UNK11* /* unused */) {
    WORK* emwk;

    emwk = (WORK*)wk->hit_adrs;
    emwk->routine_no[1] = 3;
    emwk->routine_no[2] = 2;
    emwk->routine_no[3] = 1;

    if (test_flag) {
        wk->cmyd.pat = 2;
    }

    return 1;
}

s32 comm_iflb(WORK* wk, UNK11* ctc) {
    u16 shdat;
    u16 my_shdat;

    if (ctc->koc & 0x4000) {
        my_shdat = wk->cmwk[ctc->koc & 0xF];
    } else {
        my_shdat = ctc->koc;
    }

    shdat = get_comm_if_lvsh(wk);

    if (my_shdat == shdat) {
        return decord_if_jump(wk, ctc, ctc->ix);
    }

    return decord_if_jump(wk, ctc, ctc->pat);
}

s32 comm_asxy(WORK* wk, UNK11* ctc) {
    s16* from_rom2 = &wk->step_xy_table[ctc->koc];
    s32 st = *from_rom2++;

    st <<= 8;

    if (wk->rl_flag) {
        wk->xyz[0].cal += st;
    } else {
        wk->xyz[0].cal -= st;
    }

    st = *from_rom2;
    st <<= 8;
    wk->xyz[1].cal += st;
    return 1;
}

s32 comm_schx(WORK* wk, UNK11* ctc) {
    switch (ctc->koc) {
    case 0:
        wk->mvxy.a[0].sp = (wk->mvxy.a[0].sp * ctc->ix) / ctc->pat;
        break;

    case 2:
        wk->mvxy.a[0].sp = (wk->mvxy.a[0].sp * ctc->ix) / ctc->pat;
        /* fallthrough */

    case 1:
        wk->mvxy.d[0].sp = (wk->mvxy.d[0].sp * ctc->ix) / ctc->pat;
        break;
    }

    return 1;
}

s32 comm_schy(WORK* wk, UNK11* ctc) {
    switch (ctc->koc) {
    case 0:
        wk->mvxy.a[1].sp = (wk->mvxy.a[1].sp * ctc->ix) / ctc->pat;
        break;

    case 2:
        wk->mvxy.a[1].sp = (wk->mvxy.a[1].sp * ctc->ix) / ctc->pat;
        /* fallthrough */

    case 1:
        wk->mvxy.d[1].sp = (wk->mvxy.d[1].sp * ctc->ix) / ctc->pat;
        break;
    }

    return 1;
}

s32 comm_back(WORK* wk, UNK11* /* unused */) {
    set_char_move_init2(wk, wk->cmbk.koc, wk->cmbk.ix, wk->cmbk.pat, 0);
    return 0;
}

s32 comm_mvix(WORK* wk, UNK11* ctc) {
    wk->mvxy.index = ctc->koc;
    return 1;
}

s32 comm_sajp(WORK* wk, UNK11* ctc) {
    PLW* pwk;

    if (wk->work_id == 1) {
        if (My_char[wk->id] != 18 && ((PLW*)wk)->sa->kind_of_arts == ctc->koc && ((PLW*)wk)->sa->ok == -1) {
            return decord_if_jump(wk, ctc, ctc->ix);
        }
    } else {
        pwk = (PLW*)((WORK_Other*)wk)->my_master;

        if (pwk->wu.work_id == 1 && pwk->sa->kind_of_arts == ctc->koc && pwk->sa->ok == -1) {
            return decord_if_jump(&pwk->wu, ctc, ctc->ix);
        }
    }

    return 1;
}

s32 comm_ccch(WORK* wk, UNK11* ctc) {
    if (ctc->koc) {
        wk->extra_col += ctc->ix;
        wk->extra_col &= 0x2FFF;
    } else {
        wk->extra_col = ctc->ix;
    }

    return 1;
}

s32 comm_wset(WORK* wk, UNK11* ctc) {
    switch (ctc->ix) {
    default:
        wk->cmwk[ctc->koc & 0xF] = ctc->pat;
        break;

    case 1:
        wk->cmwk[ctc->koc & 0xF] &= ctc->pat;
        break;

    case 2:
        wk->cmwk[ctc->koc & 0xF] |= ctc->pat;
        break;

    case 3:
        wk->cmwk[ctc->koc & 0xF] += ctc->pat;
        break;

    case 4:
        wk->cmwk[ctc->koc & 0xF] -= ctc->pat;
        break;

    case 5:
        wk->cmwk[ctc->koc & 0xF] *= ctc->pat;
        break;

    case 6:
        wk->cmwk[ctc->koc & 0xF] /= ctc->pat;
        break;
    }

    return 1;
}

s32 comm_wswk(WORK* wk, UNK11* ctc) {
    switch (ctc->ix) {
    default:
        wk->cmwk[ctc->koc & 0xF] = wk->cmwk[ctc->pat & 0xF];
        break;

    case 1:
        wk->cmwk[ctc->koc & 0xF] &= wk->cmwk[ctc->pat & 0xF];
        break;

    case 2:
        wk->cmwk[ctc->koc & 0xF] |= wk->cmwk[ctc->pat & 0xF];
        break;

    case 3:
        wk->cmwk[ctc->koc & 0xF] += wk->cmwk[ctc->pat & 0xF];
        break;

    case 4:
        wk->cmwk[ctc->koc & 0xF] -= wk->cmwk[ctc->pat & 0xF];
        break;

    case 5:
        wk->cmwk[ctc->koc & 0xF] *= wk->cmwk[ctc->pat & 0xF];
        break;

    case 6:
        wk->cmwk[ctc->koc & 0xF] /= wk->cmwk[ctc->pat & 0xF];
        break;
    }

    return 1;
}

s32 comm_wadd(WORK* wk, UNK11* ctc) {
    wk->cmwk[ctc->koc & 0xF] += ctc->ix;
    wk->cmwk[ctc->koc & 0xF] &= ctc->pat;
    return 1;
}

s32 comm_wceq(WORK* wk, UNK11* ctc) {
    if (wk->cmwk[ctc->koc & 0xF] == ctc->ix) {
        return decord_if_jump(wk, ctc, ctc->pat);
    }

    return 1;
}

s32 comm_wcne(WORK* wk, UNK11* ctc) {
    if (wk->cmwk[ctc->koc & 0xF] != ctc->ix) {
        return decord_if_jump(wk, ctc, ctc->pat);
    }
    return 1;
}

s32 comm_wcgt(WORK* wk, UNK11* ctc) {
    if (wk->cmwk[ctc->koc & 0xF] > ctc->ix) {
        return decord_if_jump(wk, ctc, ctc->pat);
    }

    return 1;
}

s32 comm_wclt(WORK* wk, UNK11* ctc) {
    if (wk->cmwk[ctc->koc & 0xF] < ctc->ix) {
        return decord_if_jump(wk, ctc, ctc->pat);
    }

    return 1;
}

s32 comm_wadd2(WORK* wk, UNK11* ctc) {
    wk->cmwk[ctc->koc & 0xF] += wk->cmwk[ctc->ix & 0xF];
    wk->cmwk[ctc->koc & 0xF] &= ctc->pat;
    return 1;
}

s32 comm_wceq2(WORK* wk, UNK11* ctc) {
    if (wk->cmwk[ctc->koc & 0xF] == wk->cmwk[ctc->ix & 0xF]) {
        return decord_if_jump(wk, ctc, ctc->pat);
    }

    return 1;
}

s32 comm_wcne2(WORK* wk, UNK11* ctc) {
    if (wk->cmwk[ctc->koc & 0xF] != wk->cmwk[ctc->ix & 0xF]) {
        return decord_if_jump(wk, ctc, ctc->pat);
    }

    return 1;
}

s32 comm_wcgt2(WORK* wk, UNK11* ctc) {
    if (wk->cmwk[ctc->koc & 0xF] > wk->cmwk[ctc->ix & 0xF]) {
        return decord_if_jump(wk, ctc, ctc->pat);
    }

    return 1;
}

s32 comm_wclt2(WORK* wk, UNK11* ctc) {
    if (wk->cmwk[ctc->koc & 0xF] < wk->cmwk[ctc->ix & 0xF]) {
        return decord_if_jump(wk, ctc, ctc->pat);
    }

    return 1;
}

s32 comm_rapp2(WORK* wk, UNK11* ctc) {
    if (wk->work_id == 1) {
        if (wcp[wk->id].waza_flag[8]) {
            setup_comm_back(wk);
            set_char_move_init2(wk, ctc->koc, ctc->ix, ctc->pat, 1);
            return 0;
        }

        return 1;
    }

    if (wcp[((WORK_Other*)wk)->master_id & 1].waza_flag[8]) {
        setup_comm_back(wk);
        set_char_move_init2(wk, ctc->koc, ctc->ix, ctc->pat, 1);
        return 0;
    }

    return 1;
}

s32 comm_rapk2(WORK* wk, UNK11* ctc) {
    if (wk->work_id == 1) {
        if (wcp[wk->id].waza_flag[10]) {
            setup_comm_back(wk);
            set_char_move_init2(wk, ctc->koc, ctc->ix, ctc->pat, 1);
            return 0;
        }

        return 1;
    }

    if (wcp[((WORK_Other*)wk)->master_id & 1].waza_flag[10]) {
        setup_comm_back(wk);
        set_char_move_init2(wk, ctc->koc, ctc->ix, ctc->pat, 1);
        return 0;
    }

    return 1;
}

s32 comm_iflg(WORK* wk, UNK11* ctc) {
    if (ctc->koc == 0) {
        if (wk->cmwk[11] < ctc->ix) {
            return 1;
        }

        return decord_if_jump(wk, ctc, ctc->pat);
    }

    if (((WORK*)wk->target_adrs)->cmwk[11] < ctc->ix) {
        return 1;
    }

    return decord_if_jump(wk, ctc, ctc->pat);
}

s32 comm_mpcy(WORK* wk, UNK11* ctc) {
    s16 ans = 0;

    switch (ctc->ix) {
    case 1:
        if (wk->xyz[1].disp.pos > ctc->koc) {
            ans = 1;
        }

        break;

    case 2:
        if (wk->xyz[1].disp.pos < ctc->koc) {
            ans = 1;
        }

        break;

    default:
        if (wk->xyz[1].disp.pos == ctc->koc) {
            ans = 1;
        }

        break;
    }

    if (ans == 0) {
        return 1;
    }

    return decord_if_jump(wk, ctc, ctc->pat);
}

s32 comm_epcy(WORK* wk, UNK11* ctc) {
    WORK* emwk = (WORK*)wk->target_adrs;
    s16 ans = 0;

    switch (ctc->ix) {
    case 1:
        if (emwk->xyz[1].disp.pos > ctc->koc) {
            ans = 1;
        }

        break;

    case 2:
        if (emwk->xyz[1].disp.pos < ctc->koc) {
            ans = 1;
        }

        break;

    default:
        if (emwk->xyz[1].disp.pos == ctc->koc) {
            ans = 1;
        }

        break;
    }

    if (ans == 0) {
        return 1;
    }

    return decord_if_jump(wk, ctc, ctc->pat);
}

s32 comm_imgs(PLW* wk, UNK11* ctc) {
    PLW* tk;

    if (test_flag == 0) {
        tk = (PLW*)wk->wu.target_adrs;

        switch (ctc->koc) {
        case 0:
            wk->image_setup_flag = 2;
            wk->image_data_index = ctc->ix;
            break;

        default:
            wk->image_setup_flag = 2;
            wk->image_data_index = ctc->ix;
            /* fallthrough */

        case 1:
            tk->image_setup_flag = 2;
            tk->image_data_index = ctc->ix;
            break;
        }
    }

    return 1;
}

s32 comm_imgc(PLW* wk, UNK11* ctc) {
    PLW* tk = (PLW*)wk->wu.target_adrs;

    switch (ctc->koc) {
    case 0:
        wk->image_setup_flag = 0;
        break;

    default:
        wk->image_setup_flag = 0;
        /* fallthrough */

    case 1:
        tk->image_setup_flag = 0;
        break;
    }

    return 1;
}

s32 comm_rvxy(WORK* wk, UNK11* ctc) {
    WORK* emwk = (WORK*)wk->target_adrs;

    switch (ctc->koc) {
    case 0:
        if (wk->rl_flag) {
            wk->xyz[0].cal = emwk->xyz[0].cal + (ctc->ix << 8);
        } else {
            wk->xyz[0].cal = emwk->xyz[0].cal - (ctc->ix << 8);
        }

        wk->xyz[1].cal = emwk->xyz[1].cal + (ctc->pat << 8);
        break;

    case 2:
        if (wk->rl_flag) {
            wk->xyz[0].cal = emwk->xyz[0].cal + (ctc->ix << 8);
        } else {
            wk->xyz[0].cal = emwk->xyz[0].cal - (ctc->ix << 8);
        }

        wk->xyz[1].cal = emwk->xyz[1].cal + (ctc->pat << 8);
        /* fallthrough */

    default:
        if (wk->rl_flag) {
            emwk->xyz[0].cal = wk->xyz[0].cal + (ctc->ix << 8);
        } else {
            emwk->xyz[0].cal = wk->xyz[0].cal - (ctc->ix << 8);
        }

        emwk->xyz[1].cal = wk->xyz[1].cal + (ctc->pat << 8);
        break;
    }

    return 1;
}

s32 comm_rv_x(WORK* wk, UNK11* ctc) {
    WORK* emwk = (WORK*)wk->target_adrs;

    switch (ctc->koc) {
    case 0:
        if (wk->rl_flag) {
            wk->xyz[0].cal = emwk->xyz[0].cal + (ctc->ix << 8);
        } else {
            wk->xyz[0].cal = emwk->xyz[0].cal - (ctc->ix << 8);
        }

        break;

    case 2:
        if (wk->rl_flag) {
            wk->xyz[0].cal = emwk->xyz[0].cal + (ctc->ix << 8);
        } else {
            wk->xyz[0].cal = emwk->xyz[0].cal - (ctc->ix << 8);
        }

        /* fallthrough */

    default:
        if (wk->rl_flag) {
            emwk->xyz[0].cal = wk->xyz[0].cal + (ctc->ix << 8);
        } else {
            emwk->xyz[0].cal = wk->xyz[0].cal - (ctc->ix << 8);
        }

        break;
    }

    return 1;
}

s32 comm_rv_y(WORK* wk, UNK11* ctc) {
    WORK* emwk = (WORK*)wk->target_adrs;

    switch (ctc->koc) {
    case 0:
        wk->xyz[1].cal = emwk->xyz[1].cal + (ctc->pat << 8);
        break;

    case 2:
        wk->xyz[1].cal = emwk->xyz[1].cal + (ctc->pat << 8);
        /* fallthrough */

    default:
        emwk->xyz[1].cal = wk->xyz[1].cal + (ctc->pat << 8);
        break;
    }

    return 1;
}

s32 comm_ccfl(PLW* wk, UNK11* /* unused */) {
    wk->caution_flag = 0;
    return 1;
}

s32 comm_myhp(WORK* wk, UNK11* ctc) {
    s16 num = 0;
    s32 cmpvital = (Max_vitality * ctc->ix) / 100;

    switch (ctc->koc) {
    case 1:
        if (wk->vital_new > cmpvital) {
            num = 1;
        }

        break;

    case 2:
        if (wk->vital_new < cmpvital) {
            num = 1;
        }

        break;

    default:
        if (wk->vital_new == cmpvital) {
            num = 1;
        }

        break;
    }

    if (num) {
        return decord_if_jump(wk, ctc, ctc->pat);
    }

    return 1;
}

s32 comm_emhp(WORK* wk, UNK11* ctc) {
    WORK* emwk = (WORK*)wk->target_adrs;
    s16 num = 0;
    s32 cmpvital = (Max_vitality * ctc->ix) / 100;

    switch (ctc->koc) {
    case 1:
        if (cmpvital < emwk->vital_new) {
            num = 1;
        }

        break;

    case 2:
        if (emwk->vital_new < cmpvital) {
            num = 1;
        }

        break;

    default:
        if (emwk->vital_new == cmpvital) {
            num = 1;
        }

        break;
    }

    if (num) {
        return decord_if_jump(wk, ctc, ctc->pat);
    }

    return 1;
}

s32 comm_exbgs(WORK* /* unused */, UNK11* /* unused */) {
    return 1;
}

s32 comm_exbgc(WORK* /* unused */, UNK11* /* unused */) {
    return 1;
}

s32 comm_atmf(PLW* wk, UNK11* ctc) {
    wk->atemi_flag = ctc->koc;
    wk->atemi_point = ctc->ix;
    return 1;
}

s32 comm_chkwf(PLW* wk, UNK11* ctc) {
    if (wk->cp->waza_flag[ctc->koc] == 0 || wk->cp->waza_flag[ctc->koc] == -1) {
        return decord_if_jump(&wk->wu, ctc, ctc->pat);
    }

    waza_flag_clear_only_1(wk->wu.id, ctc->koc);
    return decord_if_jump(&wk->wu, ctc, ctc->ix);
}

s32 comm_retmj(PLW* wk, UNK11* /* unused */) {
    wk->wu.now_koc = wk->wu.cmb2.koc;
    wk->wu.char_index = wk->wu.cmb2.ix;
    wk->wu.cg_ix = wk->wu.cmb2.pat;
    wk->wu.set_char_ad = &wk->wu.char_table[wk->wu.now_koc][wk->wu.char_table[wk->wu.now_koc][wk->wu.char_index] / 4];
    setupCharTableData(&wk->wu, 0, 1);
    wk->meoshi_jump_flag = 0;
    return 0;
}

s32 comm_sstx(WORK* wk, UNK11* ctc) {
    SST sstx;

    sstx.patl = 0;
    sstx.pats.h = ctc->pat;
    sstx.patl >>= 8;

    switch (ctc->koc) {
    case 0:
        switch (ctc->ix) {
        default:
            wk->mvxy.a[0].sp = sstx.patl;
            break;

        case 1:
            wk->mvxy.a[0].sp &= sstx.patl;
            break;

        case 2:
            wk->mvxy.a[0].sp |= sstx.patl;
            break;

        case 3:
            wk->mvxy.a[0].sp += sstx.patl;
            break;

        case 4:
            wk->mvxy.a[0].sp -= sstx.patl;
            break;

        case 5:
            wk->mvxy.a[0].sp *= sstx.patl;
            break;

        case 6:
            wk->mvxy.a[0].sp /= sstx.patl;
            break;
        }

        break;

    case 2:
        switch (ctc->ix) {
        default:
            wk->mvxy.a[0].sp = sstx.patl;
            break;

        case 1:
            wk->mvxy.a[0].sp &= sstx.patl;
            break;

        case 2:
            wk->mvxy.a[0].sp |= sstx.patl;
            break;

        case 3:
            wk->mvxy.a[0].sp += sstx.patl;
            break;

        case 4:
            wk->mvxy.a[0].sp -= sstx.patl;
            break;

        case 5:
            wk->mvxy.a[0].sp *= sstx.patl;
            break;

        case 6:
            wk->mvxy.a[0].sp /= sstx.patl;
            break;
        }

        /* fallthrough */

    case 1:
        switch (ctc->ix) {
        default:
            wk->mvxy.d[0].sp = sstx.patl;
            break;

        case 1:
            wk->mvxy.d[0].sp &= sstx.patl;
            break;

        case 2:
            wk->mvxy.d[0].sp |= sstx.patl;
            break;

        case 3:
            wk->mvxy.d[0].sp += sstx.patl;
            break;

        case 4:
            wk->mvxy.d[0].sp -= sstx.patl;
            break;

        case 5:
            wk->mvxy.d[0].sp *= sstx.patl;
            break;

        case 6:
            wk->mvxy.d[0].sp /= sstx.patl;
            break;
        }

        break;

    default:
        wk->mvxy.kop[0] = ctc->pat;
        break;
    }

    return 1;
}

s32 comm_ssty(WORK* wk, UNK11* ctc) {
    SST ssty;

    ssty.patl = 0;
    ssty.pats.h = ctc->pat;
    ssty.patl >>= 8;

    switch (ctc->koc) {
    case 0:
        switch (ctc->ix) {
        default:
            wk->mvxy.a[1].sp = ssty.patl;
            break;

        case 1:
            wk->mvxy.a[1].sp &= ssty.patl;
            break;

        case 2:
            wk->mvxy.a[1].sp |= ssty.patl;
            break;

        case 3:
            wk->mvxy.a[1].sp += ssty.patl;
            break;

        case 4:
            wk->mvxy.a[1].sp -= ssty.patl;
            break;

        case 5:
            wk->mvxy.a[1].sp *= ssty.patl;
            break;

        case 6:
            wk->mvxy.a[1].sp /= ssty.patl;
            break;
        }

        break;

    case 2:
        switch (ctc->ix) {
        default:
            wk->mvxy.a[1].sp = ssty.patl;
            break;

        case 1:
            wk->mvxy.a[1].sp &= ssty.patl;
            break;

        case 2:
            wk->mvxy.a[1].sp |= ssty.patl;
            break;

        case 3:
            wk->mvxy.a[1].sp += ssty.patl;
            break;

        case 4:
            wk->mvxy.a[1].sp -= ssty.patl;
            break;

        case 5:
            wk->mvxy.a[1].sp *= ssty.patl;
            break;

        case 6:
            wk->mvxy.a[1].sp /= ssty.patl;
            break;
        }

        /* fallthrough */

    case 1:
        switch (ctc->ix) {
        default:
            wk->mvxy.d[1].sp = ssty.patl;
            break;

        case 1:
            wk->mvxy.d[1].sp &= ssty.patl;
            break;

        case 2:
            wk->mvxy.d[1].sp |= ssty.patl;
            break;

        case 3:
            wk->mvxy.d[1].sp += ssty.patl;
            break;

        case 4:
            wk->mvxy.d[1].sp -= ssty.patl;
            break;

        case 5:
            wk->mvxy.d[1].sp *= ssty.patl;
            break;

        case 6:
            wk->mvxy.d[1].sp /= ssty.patl;
            break;
        }

        break;

    default:
        wk->mvxy.kop[1] = ctc->pat;
        break;
    }

    return 1;
}

s32 comm_ngda(WORK* wk, UNK11* ctc) {
    wk->cmyd.koc = ctc->koc;
    wk->cmyd.ix = ctc->ix;
    wk->cmyd.pat = ctc->pat;
    return 1;
}

s32 comm_flip(WORK* wk, UNK11* /* unused */) {
    wk->rl_flag = (wk->rl_flag + 1) & 1;
    return 1;
}

s32 comm_kage(WORK* wk, UNK11* ctc) {
    wk->kage_hx = ctc->koc;
    wk->kage_hy = ctc->ix;
    wk->kage_char = ctc->pat;
    return 1;
}

s32 comm_dspf(WORK* wk, UNK11* ctc) {
    wk->disp_flag = ctc->koc;
    return 1;
}

s32 comm_ifrlf(WORK* wk, UNK11* ctc) {
    if (ctc->koc) {
        if (wk->rl_flag == wk->rl_waza) {
            return decord_if_jump(wk, ctc, ctc->pat);
        }

        return decord_if_jump(wk, ctc, ctc->ix);
    }

    if (wk->rl_flag == wk->rl_waza) {
        return decord_if_jump(wk, ctc, ctc->ix);
    }

    return decord_if_jump(wk, ctc, ctc->pat);
}

s32 comm_srlf(WORK* wk, UNK11* ctc) {
    if (ctc->koc) {
        if (wk->rl_flag != wk->rl_waza) {
            wk->rl_flag = wk->rl_waza;
        }
    } else if (wk->rl_flag == wk->rl_waza) {
        wk->rl_flag = (wk->rl_flag + 1) & 1;
    }

    return 1;
}

s32 comm_bgrlf(WORK* wk, UNK11* ctc) {
    if (wk->rl_flag) {
        if (wk->position_x > bg_w.bgw[1].pos_x_work) {
            return decord_if_jump(wk, ctc, ctc->pat);
        }

        return decord_if_jump(wk, ctc, ctc->ix);
    }

    if (wk->position_x < bg_w.bgw[1].pos_x_work) {
        return decord_if_jump(wk, ctc, ctc->pat);
    }

    return decord_if_jump(wk, ctc, ctc->ix);
}

s32 comm_scmd(PLW* wk, UNK11* ctc) {
    wk->cmd_request = ctc->koc;
    return 1;
}

s32 comm_rljmp(WORK* wk, UNK11* ctc) {
    if (wk->rl_flag) {
        return decord_if_jump(wk, ctc, ctc->pat);
    }

    return decord_if_jump(wk, ctc, ctc->ix);
}

s32 comm_ifs2(WORK* wk, UNK11* ctc) {
    u16 shdat;
    u16 my_shdat;

    if (ctc->koc & 0x4000) {
        my_shdat = wk->cmwk[ctc->koc & 0xF];
    } else {
        my_shdat = ctc->koc;
    }

    shdat = get_comm_if_shot(wk);

    if (my_shdat & shdat) {
        return decord_if_jump(wk, ctc, ctc->ix);
    }

    return decord_if_jump(wk, ctc, ctc->pat);
}

s32 comm_abbak(WORK* wk, UNK11* /* unused */) {
    set_char_move_init2(wk, wk->cmb3.koc, wk->cmb3.ix, wk->cmb3.pat, 0);
    return 0;
}

s32 comm_sse(WORK* wk, UNK11* ctc) {
    u16* seadrs;

    wk->cg_se = ctc->koc;

    if (wk->cg_se & 0x800) {
        seadrs = (u16*)&wk->se_random_table[wk->se_random_table[wk->cg_se & 0x7FF] / 4];
        wk->cg_se = seadrs[random_16()];
    }

    if (wk->cg_se) {
        sound_effect_request[wk->cg_se](wk, check_xcopy_filter_se_req(wk));
    }

    return 1;
}

s32 comm_s_chg(WORK* wk, UNK11* ctc) {
    u16 shdat;
    u16 my_shdat;

    if (ctc->koc & 0x4000) {
        my_shdat = wk->cmwk[ctc->koc & 0xF];
    } else {
        my_shdat = ctc->koc;
    }

    shdat = get_comm_if_shot_now_off(wk);

    if (my_shdat == shdat) {
        return decord_if_jump(wk, ctc, ctc->ix);
    }

    return decord_if_jump(wk, ctc, ctc->pat);
}

s32 comm_schg2(WORK* wk, UNK11* ctc) {
    u16 shdat;
    u16 my_shdat;

    if (ctc->koc & 0x4000) {
        my_shdat = wk->cmwk[ctc->koc & 0xF];
    } else {
        my_shdat = ctc->koc;
    }

    shdat = get_comm_if_shot_now_off(wk);

    if (my_shdat & shdat) {
        return decord_if_jump(wk, ctc, ctc->ix);
    }

    return decord_if_jump(wk, ctc, ctc->pat);
}

s32 comm_rhsja(PLW* wk, UNK11* ctc) {
    wk->wu.cmhs.koc = ctc->koc;
    wk->wu.cmhs.ix = ctc->ix;
    wk->wu.cmhs.pat = ctc->pat;
    wk->hsjp_ok = 1;
    return 1;
}

s32 comm_uhsja(PLW* wk, UNK11* /* unused */) {
    setup_comm_back(&wk->wu);
    wk->hsjp_ok = 0;
    set_char_move_init2(&wk->wu, wk->wu.cmhs.koc, wk->wu.cmhs.ix, wk->wu.cmhs.pat, 0);
    return 0;
}

s32 comm_ifcom(WORK* wk, UNK11* ctc) {
    if (wk->operator) {
        return decord_if_jump(wk, ctc, ctc->pat);
    }

    return decord_if_jump(wk, ctc, ctc->ix);
}

s32 comm_axjmp(WORK* wk, UNK11* ctc) {
    if (wk->mvxy.a[0].real.h > 2) {
        return decord_if_jump(wk, ctc, ctc->koc);
    }

    if (wk->mvxy.a[0].real.h < -2) {
        return decord_if_jump(wk, ctc, ctc->pat);
    }

    return decord_if_jump(wk, ctc, ctc->ix);
}

s32 comm_ayjmp(WORK* wk, UNK11* ctc) {
    if (wk->mvxy.a[1].real.h > 0) {
        return decord_if_jump(wk, ctc, ctc->koc);
    }

    if (wk->mvxy.a[1].real.h < 0) {
        return decord_if_jump(wk, ctc, ctc->pat);
    }

    return decord_if_jump(wk, ctc, ctc->ix);
}

s32 comm_ifs3(WORK* wk, UNK11* ctc) {
    u16 shdat;
    u16 my_shdat;

    if (ctc->koc & 0x4000) {
        my_shdat = wk->cmwk[ctc->koc & 0xF];
    } else {
        my_shdat = ctc->koc;
    }

    shdat = get_comm_if_shot_now(wk);

    if (my_shdat & shdat) {
        return decord_if_jump(wk, ctc, ctc->ix);
    }

    return decord_if_jump(wk, ctc, ctc->pat);
}

s16 decord_if_jump(WORK* wk, UNK11* cpc, s16 ix) {
    s16 rnum;

    switch (ix & 0xE000) {
    case 0x4000:
        wk->cg_ix += ((ix & 0xFF) - 1) * wk->cgd_type;
        rnum = 1;
        break;

    case 0x8000:
        wk->cg_ix -= ((ix & 0xFF) + 1) * wk->cgd_type;
        rnum = 1;
        break;

    case 0x2000:
        rnum = decode_if_lever[ix & 0xFF](wk, cpc);
        break;

    default:
        wk->cg_ix = (ix - 2) * wk->cgd_type;
        rnum = 1;
        break;
    }

    return rnum;
}

u16 get_comm_if_lever(WORK* wk) {
    u16 num;

    if (wk->work_id == 1) {
        num = wcp[wk->id].sw_new & 0xF;
    } else {
        num = wcp[((WORK_Other*)wk)->master_id & 1].sw_new & 0xF;
    }

    return num;
}

u16 get_comm_if_shot(WORK* wk) {
    u16 num;

    if (wk->work_id == 1) {
        num = wcp[wk->id].sw_new & 0x770;
    } else {
        num = wcp[((WORK_Other*)wk)->master_id & 1].sw_new & 0x770;
    }

    return num;
}

u16 get_comm_if_shot_now_off(WORK* wk) {
    u16 num;

    if (wk->work_id == 1) {
        num = wcp[wk->id].sw_now & 0x770;
    } else {
        num = wcp[((WORK_Other*)wk)->master_id & 1].sw_now & 0x770;
    }

    if (wk->cg_cancel & 0x80) {
        if (wk->work_id == 1) {
            num |= wcp[wk->id].sw_off & 0x770;
        } else {
            num |= wcp[((WORK_Other*)wk)->master_id & 1].sw_off & 0x770;
        }
    }

    return num;
}

u16 get_comm_if_shot_now(WORK* wk) {
    u16 num;

    if (wk->work_id == 1) {
        num = wcp[wk->id].sw_now & 0x770;
    } else {
        num = wcp[((WORK_Other*)wk)->master_id & 1].sw_now & 0x770;
    }

    return num;
}

u16 get_comm_if_lvsh(WORK* wk) {
    u16 num;

    if (wk->work_id == 1) {
        num = wcp[wk->id].sw_new & 0x77F;
    } else {
        num = wcp[((WORK_Other*)wk)->master_id & 1].sw_new & 0x77F;
    }

    return num;
}

void setup_comm_back(WORK* wk) {
    wk->K5_init_flag = 1;
    wk->cmbk.koc = wk->now_koc;
    wk->cmbk.ix = wk->char_index;
    wk->cmbk.pat = (wk->cg_ix / wk->cgd_type) + 2;
}

void setup_comm_retmj(WORK* wk) {
    wk->cmb2.koc = wk->now_koc;
    wk->cmb2.ix = wk->char_index;
    wk->cmb2.pat = wk->cg_ix;
}

void setup_comm_abbak(WORK* wk) {
    wk->cmb3.koc = wk->now_koc;
    wk->cmb3.ix = wk->char_index;
    wk->cmb3.pat = (wk->cg_ix / wk->cgd_type) + 2;
}

void check_cgd_patdat(WORK* wk) {
    ST st;

    u16* seAdrs;
    s16* from_rom2;

    setupCharTableData(wk, 0, 0);

    switch (wk->cgd_type) {
    case 6:
        if (wk->cg_add_xy) {
            from_rom2 = wk->step_xy_table + wk->cg_add_xy;
            st.l = *from_rom2++;
            st.l <<= 8;

            if (wk->rl_flag) {
                wk->xyz[0].cal += st.l;
            } else {
                wk->xyz[0].cal -= st.l;
            }

            st.l = *from_rom2;
            st.l <<= 8;
            wk->xyz[1].cal += st.l;
        }

        if (wk->cg_status & 0x80) {
            wk->pat_status = wk->cg_status & 0x7F;
        }

        /* fallthrough */

    case 4:
        wk->cg_meoshi = wk->cg_hit_ix & 0x1FFF;
        st.w.h = wk->cg_att_ix;
        st.w.l = wk->cg_hit_ix;
        wk->cg_att_ix >>= 6;
        st.l *= 8;
        wk->cg_hit_ix = st.w.h & 0x1FF;

        if (wk->cg_att_ix) {
            set_new_attnum(wk);
        }

        if (wk->cg_effect) {
            effinitjptbl[wk->cg_effect](wk, wk->cg_eftype);
        }

        break;
    }

    wk->cg_jphos = jphos_table[wk->cg_olc_ix & 0xF];
    wk->cg_olc_ix >>= 4;
    wk->cg_flip = wk->cg_se & 3;
    wk->cg_prio = (wk->cg_se & 0xF) >> 2;
    wk->cg_se >>= 4;

    if (wk->cg_se & 0x800) {
        seAdrs = (u16*)(wk->se_random_table + (wk->se_random_table[wk->cg_se & 0x7FF] / 4));
        wk->cg_se = seAdrs[random_16()];
    }

    if (wk->cg_se) {
        sound_effect_request[wk->cg_se](wk, check_xcopy_filter_se_req(wk));
    }

    if (wk->work_id == 1) {
        if (wk->cg_rival == 0) {
            wk->curr_rca = NULL;
        } else {
            wk->curr_rca = wk->rival_catch_tbl + (wk->cg_rival - 20 + ((PLW*)wk)->tsukami_num);
        }

        wk->cg_olc = wk->olc_ix_table[wk->cg_olc_ix];
    }

    if (wk->work_id < 16) {
        wk->cg_ja = wk->hit_ix_table[wk->cg_hit_ix];
        set_jugde_area(wk);
    }

    if ((wk->cg_type != 0xFF) && (wk->cg_type & 0x80)) {
        wk->cg_wca_ix = wk->cg_type & 0x7F;
        wk->cg_type = 0;
    }

    if (wk->work_id == 1) {
        if ((WK_AS_PLW->spmv_ng_flag2 & 1) && (wk->cg_cancel & 8) && !(wk->kow & 0xF8)) {
            if (wk->kow & 6) {
                wk->cg_cancel &= 0xF7;
                wk->cg_meoshi = 0;
            } else if (wk->cg_meoshi & 0x110) {
                wk->cg_meoshi &= 0xF99F;
            } else {
                wk->cg_cancel &= 0xF7;
                wk->cg_meoshi = 0;
            }
        }

        if (WK_AS_PLW->spmv_ng_flag2 & 8) {
            if (wk->kow & 0x60) {
                wk->cg_cancel &= 0xBF;
            }
        } else if ((wk->kow & 0x60) && (wk->cg_cancel & 0x40)) {
            wk->meoshi_hit_flag = 1;
        }

        if (!(WK_AS_PLW->spmv_ng_flag2 & 2) && !(wk->kow & 0x60) && (wk->kow & 0xF8) && (wk->cg_cancel & 0x40)) {
            wk->cg_cancel |= 0x60;
        }

        if (!(wk->kow & 0xF8) && (wk->routine_no[1] == 4) && (wk->routine_no[2] < 16)) {
            switch (plpat_rno_filter[wk->routine_no[2]]) {
            case 9:
                if (wk->routine_no[3] != 1) {
                    break;
                }

                /* fallthrough */

            case 1:
                if (!(WK_AS_PLW->spmv_ng_flag2 & 0x01000000)) {
                    wk->cg_cancel |= 1;
                }

                if (!(WK_AS_PLW->spmv_ng_flag2 & 0x02000000)) {
                    wk->cg_cancel |= 2;
                }

                if (!(WK_AS_PLW->spmv_ng_flag2 & 0x100000)) {
                    if (WK_AS_PLW->player_number == 4) {
                        wk->cg_meoshi = chain_hidou_nm_ground_table[wk->kow & 7];
                        wk->cg_cancel |= 8;
                        return;
                    }

                    wk->cg_meoshi = chain_normal_ground_table[wk->kow & 7];
                    wk->cg_cancel |= 8;
                    return;
                }

                break;

            case 2:
                if (!(WK_AS_PLW->spmv_ng_flag2 & 0x200000) && !hikusugi_check(wk)) {
                    if (WK_AS_PLW->player_number == 7) {
                        wk->cg_meoshi = chain_hidou_nm_air_table[wk->kow & 7];
                        wk->cg_cancel |= 8;
                        return;
                    }

                    wk->cg_meoshi = chain_normal_air_table[wk->kow & 7];
                    wk->cg_cancel |= 8;
                }

                break;
            }
        }
    }
}

u16 check_xcopy_filter_se_req(WORK* wk) {
    u16 voif;

    if ((voif = wk->cg_se) < 0x160) {
        return voif;
    }

    if (wk->work_id != 1) {
        if (LO_2_BYTES(WK_AS_PLW->spmv_ng_flag) != 1) {
            return voif;
        }

        if ((u16)HI_2_BYTES(WK_AS_PLW->spmv_ng_flag) > 1) {
            return voif;
        }

        if (plw[HI_2_BYTES(WK_AS_PLW->spmv_ng_flag)].metamorphose == 0) {
            return voif;
        }

        return voif + 0x600;
    }

    if (WK_AS_PLW->metamorphose == 0) {
        return voif;
    }

    return voif + 0x600;
}

void check_cgd_patdat2(WORK* wk) {
    ST st;
    u16* seadrs;

    switch (wk->cgd_type) {
    case 6:
        if (wk->cg_status & 0x80) {
            wk->pat_status = wk->cg_status & 0x7F;
        }

        /* fallthrough */

    case 4:
        wk->cg_meoshi = wk->cg_hit_ix & 0x1FFF;
        st.w.h = wk->cg_att_ix;
        st.w.l = wk->cg_hit_ix;
        wk->cg_att_ix >>= 6;
        st.l *= 8;
        wk->cg_hit_ix = st.w.h & 0x1FF;

        if (wk->cg_att_ix) {
            set_new_attnum(wk);
        }

        break;
    }

    wk->cg_jphos = jphos_table[wk->cg_olc_ix & 0xF];
    wk->cg_olc_ix >>= 4;
    wk->cg_flip = wk->cg_se & 3;
    wk->cg_prio = (wk->cg_se & 0xF) >> 2;
    wk->cg_se >>= 4;

    if (wk->cg_se & 0x800) {
        seadrs = (u16*)&wk->se_random_table[wk->se_random_table[wk->cg_se & 0x7FF] / 4];
        wk->cg_se = seadrs[random_16()];
    }

    if (wk->work_id == 1) {
        if (wk->cg_rival == 0) {
            wk->curr_rca = NULL;
        } else {
            wk->curr_rca = wk->rival_catch_tbl + (wk->cg_rival - 20 + ((PLW*)wk)->tsukami_num);
        }
    }

    wk->cg_olc = wk->olc_ix_table[wk->cg_olc_ix];
    wk->cg_ja = wk->hit_ix_table[wk->cg_hit_ix];

    set_jugde_area(wk);

    if (wk->cg_type != 0xFF && wk->cg_type & 0x80) {
        wk->cg_wca_ix = wk->cg_type & 0x7F;
        wk->cg_type = 0;
    }
}

void set_new_attnum(WORK* wk) {
    s16 aag_sw;
    uintptr_t dspadrs;
    static u16 att_req;

    wk->renew_attack = wk->cg_att_ix;

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunsequenced"

    if ((att_req = (++att_req & 0x7FFF)) == 0) {
        att_req++;
    }

#pragma clang diagnostic pop

    aag_sw = 0;

    if (wk->cg_att_ix < 0) {
        wk->cg_att_ix = -wk->cg_att_ix;
        wk->attack_num = att_req;
        wk->att_hit_ok = 1;
        aag_sw = 1;
        wk->meoshi_hit_flag = 0;

        if (wk->work_id == 1) {
            WK_AS_PLW->caution_flag = 1;
            WK_AS_PLW->total_att_hit_ok += 1;
        }

        grade_add_att_renew((WORK_Other*)wk);
    }

    wk->att = *(wk->att_ix_table + wk->cg_att_ix);
    dspadrs = (uintptr_t)(wk->att_ix_table + wk->cg_att_ix);
    wk->zu_flag = wk->att.level & 0x80;
    wk->jump_att_flag = wk->att.level & 0x40;
    wk->at_attribute = (wk->att.level >> 4) & 3;
    wk->no_death_attack = wk->att.level & 8;
    wk->att.level &= 7;
    wk->kezuri_pow = kezuri_pow_table[(wk->att.guard >> 6) & 3];
    wk->att.guard &= 0x3F;
    wk->att_zuru = (wk->att.dir >> 4) & 7;
    wk->att.dir &= 0xF;
    wk->add_arts_point = (wk->att.piyo >> 4) & 0xF;
    wk->att.piyo &= 0xF;
    wk->vs_id = (wk->att.ng_type >> 4) & 0xF;
    wk->att.ng_type &= 0xF;
    wk->dir_atthit = cal_attdir(wk);

    if (aag_sw) {
        add_sp_arts_gauge_init((PLW*)wk);
    }

    if ((wk->work_id == 1) && !(WK_AS_PLW->spmv_ng_flag & 0x4000)) {
        setup_metamor_kezuri(wk);
    }
}

void setup_metamor_kezuri(WORK* wk) {
    if (wk->kezuri_pow == 0) {
        wk->kezuri_pow = kezuri_pow_table[4];
    }
}

void set_jugde_area(WORK* wk) {
    wk->h_bod = wk->body_adrs + wk->cg_ja.boix;
    wk->h_cat = wk->catch_adrs + wk->cg_ja.caix;
    wk->h_cau = wk->caught_adrs + wk->cg_ja.cuix;
    wk->h_att = wk->attack_adrs + wk->cg_ja.atix;
    wk->h_hos = wk->hosei_adrs + wk->cg_ja.hoix;
    wk->h_han = wk->hand_adrs + (wk->cg_ja.bhix + wk->cg_ja.haix);
}

void get_char_data_zanzou(WORK* wk) {
    if (wk->cg_att_ix) {
        set_new_attnum(wk);
    }

    wk->cg_ja = wk->hit_ix_table[wk->cg_hit_ix];
    set_jugde_area(wk);
}

#if 0
/* PS2 C for functions not located in sf33rd.xbe yet. */

u8 get_comm_djmp_lever_dir(PLW* wk) {
    u8 num;

    if (wk->wu.work_id == 1) {
        if (wk->py->flag == 0) {
            num = wcp[wk->wu.id].lever_dir;
        } else {
            num = 0;
        }
    } else {
        num = wcp[((WORK_Other*)wk)->master_id & 1].lever_dir;
    }

    return num;
}
#endif
