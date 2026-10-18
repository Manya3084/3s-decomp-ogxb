/* Sound3rd.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * Init_sound_system 0x9B6DC size 0xB3. FLAG: x86-only callees
 * xb_CreateDirectSound,AIXP_Init,AIXP_Create,flLogOut; PS2-only callees
 * flAdxInitialize,cseInitSndDrv; x86-only globals
 * Game_Default_Data,dword_795CF4.
 * sndInitialLoad 0x9B793 size 0x49. FLAG: x86-only callees
 * xb_InitSoundBankList,xb_ClearColorRamEntries,xb_SetColorRamEntry; PS2-only
 * callees cseMemMapInit,cseMemMapSetPhdAddr; x86-only constants 0x6f; x86-only
 * globals system_init_level.
 * checkAdxFileLoaded 0x9B7DC size 0x69. FLAG: x86-only constants 0x55.
 * Init_bgm_work 0x9B845 size 0x1C.
 * spu_all_off 0x9B861 size 0xF.
 * setSeVolume 0x9B870 size 0x28.
 * setupSoundMode 0x9B898 size 0x26.
 * bgm_separate_check 0x9B9FA size 0x17.
 * setupAlwaysSeamlessFlag 0x9BA11 size 0xC.
 * bgm_play_request 0x9BA1D size 0x40.
 * bgm_seamless_clear 0x9BA5D size 0x4D.
 * bgm_volume_setup 0x9BAAA size 0x7E.
 * adx_now_playing 0x9BB28 size 0x51. FLAG: x86-only callees
 * xb_ClearAdxtError,AIXP_GetStat.
 * adx_now_playend 0x9BB79 size 0x31. FLAG: x86-only callees AIXP_GetStat.
 * bgm_play_status 0x9BBAA size 0x1E.
 * bgmSkipCheck 0x9BBC8 size 0x1A.
 * remake_sound_code_for_DC 0x9BBE2 size 0x10A.
 * Exit_sound_system 0x9BCEC size 0x45. FLAG: x86-only callees AIXP_Finish;
 * x86-only globals dword_795CF4.
 * sound_request_for_dc 0x9BD31 size 0x119.
 * BGM_Server 0x9BE4A size 0x730. FLAG: x86-only callees
 * AIXP_Stop,xb_AixBgmStop,xb_AixBgmResume,xb_aixp_StartFnameSurround; x86-only
 * constants 0x40; x86-only offsets 0x1.
 * SsRequestPan 0x9C57A size 0x45.
 * SsRequest 0x9C5BF size 0x29.
 * SsRequest_CC 0x9C5E8 size 0x2F.
 * Standby_BGM 0x9C617 size 0x2F.
 * Go_BGM 0x9C646 size 0x29.
 * SsBgmOff 0x9C66F size 0x29.
 * SsBgmFadeIn 0x9C698 size 0x46.
 * SsBgmFadeOut 0x9C6DE size 0x35.
 * SsBgmControl 0x9C713 size 0x44.
 * SsBgmHalfVolume 0x9C757 size 0x33.
 * SE_cursor_move 0x9C78A size 0x9.
 * SE_dir_cursor_move 0x9C79C size 0xC.
 * sound_bgm_off 0x9C7A8 size 0x18.
 * sound_all_off 0x9C7C0 size 0xA.
 * SsAllNoteOff 0x9C7CA size 0x5.
 * cseSysSetMono 0xF4510 size 0xD. FLAG: not compared.
 * cseSysSetMasterVolume 0xF451D size 0xD. FLAG: not compared.
 * cseSeStopAll 0xF452A size 0x8. FLAG: not compared.
 * mlSysSetMono 0xF4D61 size 0xA. FLAG: PS2-only callees mlRpcQueueSetData.
 * mlSysSetMasterVolume 0xF4FF2 size 0x2A. FLAG: x86-only constants 0x7f.
 * sndCheckVTransStatus is folded into 0x9B78F with 7 other bodies. Unnamed.
 * SE_selected is folded into 0x9C793 with 1 other bodies. Unnamed.
 * SE_dir_selected is folded into 0x9C793 with 1 other bodies. Unnamed.
 * Not located in sf33rd.xbe; their PS2 C is kept under #if 0: cseMemMapInit,
 * cseSeStopAll, cseSysSetMasterVolume, cseSysSetMono.
 * Push_ramcnt_key is folded into 0x97103.
 * cseInitSndDrv has no XBE name and no aligned call.
 * cseMemMapInit has no XBE name and no aligned call.
 * cseMemMapSetPhdAddr has no XBE name and no aligned call.
 * flAdxInitialize has no XBE name and no aligned call.
 * mlSeStopAll has no XBE name and no aligned call.
 * mlTsbStopAll has no XBE name and no aligned call.
 * Data: cseTSBDataTable 0x32FD2C, not compared.
 * Data: csePHDDataTable: not located in the XBE, PS2 initializer kept.
 * Data: bgm_table: not located in the XBE, PS2 initializer kept.
 * Data: bgm_exdata: not located in the XBE, PS2 initializer kept.
 * Data: se_level 0x9CA4B4.
 * Data: bgm_level: defined elsewhere on Xbox.
 * Data: bgm_vol_mix: defined elsewhere on Xbox.
 * Data: bgm_vol_now: defined elsewhere on Xbox.
 * Data: bgm_fade_ix: defined elsewhere on Xbox.
 * Data: bgm_half_down 0x8813F8.
 * Data: current_bgm: defined elsewhere on Xbox.
 * Data: bgm_seamless_always 0x8813F6.
 * Data: bgm_fade: defined elsewhere on Xbox.
 * Data: adxt 0x8813DC.
 * Data: bgm_exe 0x8813E0.
 * Data: bgm_req 0xC7C810.
 * Data: sdbd: defined elsewhere on Xbox.
 * Data: adx_VS 0xC4BEE0.
 * Data: adx_EmSel 0xB24A00.
 * Data: adx_stm_work 0xAE7000.
 * Data: bgm_tableDC: not located in the XBE, PS2 initializer kept.
 * Data: bgm_exdataDC: not located in the XBE, PS2 initializer kept.
 * Data: bgm_tableAC: not located in the XBE, PS2 initializer kept.
 * Data: bgm_exdataAC: not located in the XBE, PS2 initializer kept.
 * Data: adx_NowOnMemoryType is 0x32FE2C, 0x1 bytes compared.
 * Data: adx_volume is 0x2682B8, 0x100 bytes compared.
 * cseSeStopAll is defined in sf33rd/AcrSDK/MiddleWare/PS2/CapSndEng/cse.c, the
 * object retail puts it in.
 * cseSysSetMasterVolume is defined in
 * sf33rd/AcrSDK/MiddleWare/PS2/CapSndEng/cse.c, the object retail puts it in.
 * cseSysSetMono is defined in sf33rd/AcrSDK/MiddleWare/PS2/CapSndEng/cse.c,
 * the object retail puts it in.
 * Unnamed data used (not checked): Init_sound_system:
 * 0x2683b8,0x2683d0,0xc7c818; setSeVolume: 0x2683e0; bgm_play_request:
 * 0x3304f0; bgm_volume_setup: 0xb249e4,0xc7c81a,0xc7c81c; adx_now_playing:
 * 0xae6fec; adx_now_playend: 0xae6fec; bgmSkipCheck: 0x3304f0;
 * remake_sound_code_for_DC: 0x265808; BGM_Server:
 * 0x2683e4,0x3304f0,0x3304f8,0xc7c818,0xc7c81c; mlSysSetMono: 0x797100;
 * mlSysSetMasterVolume: 0x3f3510,0x797ba8.
 * Globals: Game_Default_Data 0x265548, adx_volume 0x2682B8, cseTSBDataTable
 * 0x32FD2C, adx_NowOnMemoryType 0x32FE2C, dword_795CF4 0x795CF4, Country
 * 0x7A8748, mpp_w 0x7AA5C0, system_init_level 0x7AABDC, sys_w 0x7C5940, adxt
 * 0x8813DC, bgm_exe 0x8813E0, bgm_seamless_always 0x8813F6, bgm_half_down
 * 0x8813F8, se_level 0x9CA4B4, adx_stm_work 0xAE7000, adx_EmSel 0xB24A00,
 * adx_VS 0xC4BEE0, bgm_req 0xC7C810.
 */

#include "structs.h"

#define ADX_STM_WORK_SIZE 252388
#define NULL 0
#define ADXT_STAT_PLAYING	(3)
#define ADXT_STAT_DECEND	(4)
#define ADXT_STAT_PLAYEND	(5)
#define	ADXT_MAX_NCH		(2)

typedef struct {
	struct _sj_vtbl *vtbl;		
								
} SJ_OBJ;

typedef char					Char8;

typedef unsigned int			Uint32;

typedef signed short			Sint16;

typedef SJ_OBJ *SJ;

typedef void	*ADXRNA;

typedef void *ADXSTM;

typedef void	*ADXSJD;

typedef  char				Sint8;

typedef signed int				Sint32;

typedef struct _adx_talk {
	 Sint8	used;						
	 Sint8	stat;						
	 Sint8	pmode;						
	 Sint8	maxnch;						
	 ADXSJD	sjd;						
	 ADXSTM	stm;						
	 ADXRNA	rna;						
	 SJ		sjf;						
	 SJ		sji;						
	 SJ		sjo[ADXT_MAX_NCH];			
	 Sint8	*ibuf;						
	 Sint32	ibuflen;					
	 Sint32	ibufxlen;					
	 Sint16	*obuf;						
	 Sint32	obufsize;					
	 Sint32	obufdist;					
	 Sint32	svrfreq;					
	 Sint16	maxsct;						
	 Sint16	minsct;						
	 Sint16	outvol;						
	 Sint16	outpan[ADXT_MAX_NCH];		
	 Sint16   unk46;
	 Sint32	maxdecsmpl;					
	 Sint32	lpcnt;						
	 Sint32	lp_skiplen;					
	 Sint32	trp;						
	 Sint32	wpos;						
	 Sint32	mofst;						
	 Sint16	ercode;						
	 Sint32	edecpos;					
	 Sint16	edeccnt;					
	 Sint16	eshrtcnt;					
	 Sint8	lpflg;						
	 Sint8	autorcvr;					
	 Sint8	fltmode;					
	 Sint8	execflag;					
	 Sint8	pstwait_flag;				
	 Sint8	pstready_flag;				
	 Sint8	pause_flag;					
	 void	*amp;						
	 SJ		ampsji[ADXT_MAX_NCH];		
	 SJ		ampsjo[ADXT_MAX_NCH];		
	 Sint32	time_ofst;					
	 Sint32	lesct;						
	 Sint32	trpnsmpl;					
	 void	*lsc;						
	 Sint8	lnkflg;						
	 Sint8	rsv;						
	 Sint16	rsv2;						
	 Uint32 tvofst;						
	 Uint32 svcnt;						
    										
	 Uint32 decofst;						
	 #ifdef __EE__
	 Sint32	flush_nsmpl;				
	 #endif
	 Sint8  unkAC;
	 Sint8  padAD[1];
     Char8* unkB0;
     Sint32 padB4;
     Sint32 padB8;
     Sint32 padBC;
     Sint32 padC0;
} ADX_TALK;

typedef	ADX_TALK	*ADXT;

void mlSysSetMono(u32 mono_sw);
void mlSysSetMasterVolume(s32 vol);
void ADXT_Init(void);
extern s32 dword_795CF4;
extern u8 sound_mode;
extern void work_init_zero(void *dst, s32 size);
extern void ADXT_SetOutputMono(u32 mono_sw);
extern void AIXP_Finish(void);
extern void ADXT_Finish(void);
void sound_all_off(void);
extern u8 bgm_type;
extern s16 load_it_use_any_key(u16 fnum, u8 kokey, u8 group);
extern void* Get_ramcnt_address(s16 key);
extern s32 ppgSetupCmpChunk(u8* srcAdrs, s32 num, void* dstAdrs);
extern void sub_00097103(s16 key);
extern s32 D_00797100;
extern s32 D_00797BA8;
extern s32 D_003F3510[128];
extern void mlSysSetBankVolume(s32 port, s32 mask, s32 vol);
extern void *D_00AE6FEC;
void xb_ClearAdxtError(s32 which);
s32 AIXP_GetStat(void *aixp);
extern SoundEvent TSB_SE[208];
extern SoundEvent TSB_PL00[65];
extern SoundEvent TSB_PL01[65];
extern SoundEvent TSB_PL02[65];
extern SoundEvent TSB_PL03[65];
extern SoundEvent TSB_PL04[65];
extern SoundEvent TSB_PL05[65];
extern SoundEvent TSB_PL06[65];
extern SoundEvent TSB_PL07[65];
extern SoundEvent TSB_PL08[65];
extern SoundEvent TSB_PL09[65];
extern SoundEvent TSB_PL10[65];
extern SoundEvent TSB_PL11[65];
extern SoundEvent TSB_PL12[65];
extern SoundEvent TSB_PL13[65];
extern SoundEvent TSB_PL14[65];
extern SoundEvent TSB_PL15[65];
extern SoundEvent TSB_PL16[65];
extern SoundEvent TSB_PL17[65];
extern SoundEvent TSB_PL18[65];
extern SoundEvent TSB_PL19[65];
extern s8 PHD_SE[5088];
extern s8 PHD_PL00[1024];
extern s8 PHD_PL01[944];
extern s8 PHD_PL02[944];
extern s8 PHD_PL03[912];
extern s8 PHD_PL04[992];
extern s8 PHD_PL05[1024];
extern s8 PHD_PL06[1328];
extern s8 PHD_PL07[944];
extern s8 PHD_PL08[1248];
extern s8 PHD_PL09[992];
extern s8 PHD_PL10[1072];
extern s8 PHD_PL11[1024];
extern s8 PHD_PL12[1152];
extern s8 PHD_PL13[1072];
extern s8 PHD_PL14[912];
extern s8 PHD_PL15[1328];
extern s8 PHD_PL16[1440];
extern s8 PHD_PL17[864];
extern s8 PHD_PL18[1072];
extern s8 PHD_PL19[1024];
extern struct _SYSTEM_W sys_w;
void flAdxInitialize(s8* host_root, s8* cvd_root);
ADXT ADXT_Create(Sint32 maxnch, void* work, Sint32 worksize);
extern s32 system_init_level;
s32 cseInitSndDrv();
s32 cseMemMapInit(void* pSpuMemMap);
extern s8* SpuMap;
s32 cseMemMapSetPhdAddr(u32 bank, void* addr);
s32 cseTsbSetBankAddr(u32 bank, SoundEvent* addr);
void load_any_color(u16 ix, u8 kokey);
void ADXT_Destroy(ADXT adxt);
void spu_all_off(void);
void sound_bgm_off(void);
s32 cseSeStopAll();
s32 adx_now_playing();
void SsBgmOff(void);
s32 cseSysSetMasterVolume(s32 vol);
s32 cseSysSetMono(u32 mono_sw);
s32 cseTsbRequest(u16 bank, u16 code, s32 NumArgSets, ...);
void ADXT_Stop(ADXT adxt);
void bgm_seamless_clear();
s32 bgm_separate_check();
void bgm_volume_setup(s16 data);
void ADXT_Pause(ADXT adxt, Sint32 sw);
void bgm_play_request(s32 filenum, s32 flag);
void ADXT_StartSeamless(ADXT adxt);
void ADXT_StartMem(ADXT adxt, void* adxdat);
Sint32 ADXT_GetStatPause(ADXT adxt);
Sint32 ADXT_GetNumFiles(ADXT adxt);
extern MPP mpp_w;
void ADXT_EntryAfs(ADXT adxt, Sint32 patid, Sint32 fid);
void ADXT_StartAfs(ADXT adxt, Sint32 patid, Sint32 fid);
void ADXT_ResetEntry(ADXT adxt);
extern u8 Country;
extern s8 Debug_w[72];
void ADXT_SetOutVol(ADXT adxt, Sint32 vol);
Sint32 ADXT_GetStat(ADXT adxt);
u16 remake_sound_code_for_DC(u16 code, SoundPatchConfig* rmcode);
void Store_Sound_Code(u16 code, SoundPatchConfig* rmc);
extern const u16 sdcode_conv[];
s32 flPrintL(s32 posi_x, s32 posi_y, const s8* format, ...);
void njWaitVSync_with_N();

extern s16 se_level;

extern s16 bgm_level;

extern s16 bgm_vol_mix;

extern s16 bgm_vol_now;

extern s16 bgm_fade_ix;

extern s16 bgm_half_down;

extern s16 current_bgm;

extern s16 bgm_seamless_always;

extern BGMFade bgm_fade;

extern ADXT adxt;

extern BGMExecution bgm_exe;

extern BGMRequest bgm_req;

extern s8* sdbd[3];

extern u8 adx_VS[198954];

extern u8 adx_EmSel[391168];

extern s8 adx_stm_work[ADX_STM_WORK_SIZE];

BGMTableEntry bgm_tableDC[68] = {
    { 0, 0, 0 },         { 16384, 58, 572 },  { 16385, 64, 588 },  { 16386, 64, 598 },  { 16387, 60, 616 },
    { 16388, 60, 642 },  { 16389, 60, 653 },  { 16390, 72, 681 },  { 16391, 72, 695 },  { 16392, 72, 716 },
    { 16393, 74, 728 },  { 16394, 76, 742 },  { 16395, 74, 758 },  { 16396, 80, 776 },  { 16397, 72, 790 },
    { 16398, 76, 808 },  { 16399, 72, 822 },  { 16400, 72, 833 },  { 16401, 72, 844 },  { 16402, 72, 857 },
    { 16403, 72, 871 },  { 16404, 72, 885 },  { 16405, 64, 904 },  { 16406, 64, 918 },  { 16407, 64, 932 },
    { 16408, 64, 946 },  { 16409, 64, 963 },  { 16410, 64, 977 },  { 16411, 78, 994 },  { 16412, 74, 1012 },
    { 16413, 74, 1026 }, { 16414, 78, 1044 }, { 16415, 76, 1064 }, { 16416, 76, 1075 }, { 16417, 78, 1093 },
    { 16418, 78, 1110 }, { 16419, 78, 1124 }, { 16420, 68, 1140 }, { 16421, 68, 1154 }, { 16422, 68, 1168 },
    { 16423, 72, 1186 }, { 16424, 72, 1204 }, { 16425, 72, 1223 }, { 16426, 56, 1241 }, { 16427, 56, 1255 },
    { 16428, 56, 1269 }, { 16429, 64, 1288 }, { 16430, 64, 1306 }, { 16431, 64, 1325 }, { 0, 72, 1344 },
    { 0, 72, 1345 },     { 0, 72, 1346 },     { 0, 84, 1347 },     { 0, 86, 1348 },     { 0, 56, 1349 },
    { 0, 76, 1350 },     { 0, 72, 1351 },     { 0, 72, 1352 },     { 0, 64, 1353 },     { 0, 72, 1354 },
    { 0, 56, 1355 },     { 0, 60, 1356 },     { 0, 60, 1357 },     { 0, 72, 1358 },     { 0, 72, 1359 },
    { 0, 48, 1360 },     { 0, 64, 1361 },     { 0, 112, 1362 }
};

BGMExecutionData bgm_exdataDC[48] = {
    { 573, 587, 574, 0 },    { 589, 597, 590, 0 },    { 599, 615, 600, 0 },    { 617, 641, 618, 0 },
    { 643, 652, 645, 0 },    { 654, 680, 657, 0 },    { 682, 694, 687, 0 },    { 696, 715, 700, 0 },
    { 717, 727, 720, 0 },    { 729, 741, 730, 0 },    { 743, 757, 746, 0 },    { 759, 775, 764, 0 },
    { 777, 789, 778, 0 },    { 791, 807, 792, 0 },    { 809, 821, 810, 0 },    { 823, 832, 824, 0 },
    { 834, 843, 835, 0 },    { 845, 856, 846, 0 },    { 858, 870, 859, 0 },    { 872, 884, 873, 0 },
    { 886, 903, 888, 0 },    { 905, 917, 906, 0 },    { 919, 931, 920, 0 },    { 933, 945, 934, 0 },
    { 947, 962, 951, 0 },    { 964, 976, 965, 0 },    { 978, 993, 982, 0 },    { 995, 1011, 1000, 0 },
    { 1013, 1025, 1014, 0 }, { 1027, 1043, 1028, 0 }, { 1045, 1063, 1048, 0 }, { 1065, 1074, 1067, 0 },
    { 1076, 1092, 1077, 0 }, { 1094, 1109, 1096, 0 }, { 1111, 1123, 1112, 0 }, { 1125, 1139, 1126, 0 },
    { 1141, 1153, 1142, 0 }, { 1155, 1167, 1156, 0 }, { 1169, 1185, 1170, 0 }, { 1187, 1203, 1188, 0 },
    { 1205, 1222, 1207, 0 }, { 1224, 1240, 1225, 0 }, { 1242, 1254, 1243, 0 }, { 1256, 1268, 1257, 0 },
    { 1270, 1287, 1272, 0 }, { 1289, 1305, 1290, 0 }, { 1307, 1324, 1309, 0 }, { 1326, 1343, 1328, 0 }
};

BGMTableEntry bgm_tableAC[68] = {
    { 0, 0, 0 },         { 16384, 104, 91 },  { 16385, 104, 107 }, { 32768, 0, 0 },     { 16386, 104, 119 },
    { 16387, 104, 133 }, { 32768, 0, 0 },     { 16388, 104, 144 }, { 16389, 104, 159 }, { 32768, 0, 0 },
    { 16390, 104, 182 }, { 16391, 104, 196 }, { 32768, 0, 0 },     { 16392, 104, 212 }, { 16393, 104, 227 },
    { 32768, 0, 0 },     { 16394, 104, 246 }, { 16395, 104, 257 }, { 32768, 0, 0 },     { 16396, 104, 268 },
    { 16397, 104, 282 }, { 32768, 0, 0 },     { 16398, 104, 296 }, { 16399, 104, 310 }, { 32768, 0, 0 },
    { 16400, 104, 325 }, { 16401, 104, 342 }, { 32768, 0, 0 },     { 16402, 104, 356 }, { 16403, 104, 374 },
    { 32768, 0, 0 },     { 16404, 104, 389 }, { 16405, 104, 409 }, { 32768, 0, 0 },     { 16406, 104, 419 },
    { 16407, 104, 436 }, { 32768, 0, 0 },     { 16408, 104, 451 }, { 16409, 104, 465 }, { 32768, 0, 0 },
    { 16410, 104, 481 }, { 16411, 104, 499 }, { 32768, 0, 0 },     { 16412, 104, 517 }, { 16413, 104, 525 },
    { 32768, 0, 0 },     { 16414, 104, 534 }, { 16415, 104, 544 }, { 32768, 0, 0 },     { 0, 104, 555 },
    { 0, 104, 556 },     { 0, 104, 557 },     { 0, 104, 558 },     { 0, 104, 559 },     { 0, 104, 560 },
    { 0, 104, 561 },     { 0, 104, 562 },     { 0, 104, 563 },     { 0, 104, 564 },     { 0, 104, 565 },
    { 0, 104, 566 },     { 0, 104, 567 },     { 0, 104, 568 },     { 0, 104, 569 },     { 0, 72, 1359 },
    { 0, 48, 1360 },     { 0, 104, 570 },     { 0, 104, 571 }
};

BGMExecutionData bgm_exdataAC[32] = {
    { 92, 106, 93, 0 },   { 108, 118, 111, 0 }, { 120, 132, 121, 0 }, { 134, 143, 136, 0 }, { 145, 158, 151, 0 },
    { 160, 181, 166, 0 }, { 183, 195, 184, 0 }, { 197, 211, 200, 0 }, { 213, 226, 215, 0 }, { 228, 245, 230, 0 },
    { 247, 256, 249, 0 }, { 258, 267, 260, 0 }, { 269, 281, 270, 0 }, { 283, 295, 284, 0 }, { 297, 309, 298, 0 },
    { 311, 324, 313, 0 }, { 326, 341, 330, 0 }, { 343, 355, 344, 0 }, { 357, 373, 362, 0 }, { 375, 388, 377, 0 },
    { 390, 408, 393, 0 }, { 410, 418, 411, 0 }, { 420, 435, 422, 0 }, { 437, 450, 439, 0 }, { 452, 464, 453, 0 },
    { 466, 480, 469, 0 }, { 482, 498, 483, 0 }, { 500, 516, 501, 0 }, { 518, 524, 519, 0 }, { 526, 533, 528, 0 },
    { 535, 543, 536, 0 }, { 545, 554, 547, 0 }
};

SoundEvent* cseTSBDataTable[21] = { TSB_SE,   TSB_PL00, TSB_PL01, TSB_PL02, TSB_PL03, TSB_PL04, TSB_PL05,
                                    TSB_PL06, TSB_PL07, TSB_PL08, TSB_PL09, TSB_PL10, TSB_PL11, TSB_PL12,
                                    TSB_PL13, TSB_PL14, TSB_PL15, TSB_PL16, TSB_PL17, TSB_PL18, TSB_PL19 };

s8* csePHDDataTable[21] = { PHD_SE,   PHD_PL00, PHD_PL01, PHD_PL02, PHD_PL03, PHD_PL04, PHD_PL05,
                            PHD_PL06, PHD_PL07, PHD_PL08, PHD_PL09, PHD_PL10, PHD_PL11, PHD_PL12,
                            PHD_PL13, PHD_PL14, PHD_PL15, PHD_PL16, PHD_PL17, PHD_PL18, PHD_PL19 };

u8 adx_NowOnMemoryType = 0xFF;

BGMTableEntry* bgm_table[2] = { bgm_tableDC, bgm_tableAC };

BGMExecutionData* bgm_exdata[2] = { bgm_exdataDC, bgm_exdataAC };

const s16 adx_volume[128] = { -999, -608, -576, -544, -512, -480, -448, -416, -400, -384, -368, -352, -336, -320, -304,
                              -288, -280, -272, -264, -256, -248, -240, -232, -224, -216, -208, -200, -192, -184, -176,
                              -168, -160, -156, -152, -148, -144, -140, -136, -132, -128, -124, -120, -116, -112, -108,
                              -104, -100, -96,  -94,  -92,  -90,  -88,  -86,  -84,  -82,  -80,  -78,  -76,  -74,  -72,
                              -70,  -68,  -66,  -64,  -63,  -62,  -61,  -60,  -59,  -58,  -57,  -56,  -55,  -54,  -53,
                              -52,  -51,  -50,  -49,  -48,  -47,  -46,  -45,  -44,  -43,  -42,  -41,  -40,  -39,  -38,
                              -37,  -36,  -35,  -34,  -33,  -32,  -31,  -30,  -29,  -28,  -27,  -26,  -25,  -24,  -23,
                              -22,  -21,  -20,  -19,  -18,  -17,  -16,  -15,  -14,  -13,  -12,  -11,  -10,  -9,   -8,
                              -7,   -6,   -5,   -4,   -3,   -2,   -1,   0 };

void Init_sound_system() {
    se_level = 15;
    bgm_level = 15;
    bgm_half_down = 0;
    current_bgm = 0;
    bgm_seamless_always = 0;
    sys_w.sound_mode = 0;
    sys_w.bgm_type = 0;
    flAdxInitialize(NULL, "\\THIRD\\");
    ADXT_Init();
    adxt = ADXT_Create(2, adx_stm_work, ADX_STM_WORK_SIZE);
    system_init_level |= 2;
    cseInitSndDrv();
    system_init_level |= 1;
}

/* Xbox: always 1; the code after it in the PS2 slot (0x9B792) is another function */
s32 sndCheckVTransStatus(s32 type) {
    return 1;
}

void sndInitialLoad() {
    cseMemMapInit(&SpuMap);
    cseMemMapSetPhdAddr(0, *csePHDDataTable);
    cseTsbSetBankAddr(0, *cseTSBDataTable);
    load_any_color(109, 20); // This loads SE.bd (index 7)
}

void checkAdxFileLoaded(void) {
    u8* adr;
    s16 key;
    u16 fnum;

    if (adx_NowOnMemoryType == bgm_type) {
        return;
    }

    if (bgm_type == 0) {
        fnum = 85;
    } else {
        fnum = 86;
    }

    do {
        key = load_it_use_any_key(fnum, 21, 0);
    } while (key == 0);

    adr = (u8*)Get_ramcnt_address(key);
    ppgSetupCmpChunk(adr, 0, adx_VS);
    ppgSetupCmpChunk(adr, 1, adx_EmSel);
    sub_00097103(key);
    adx_NowOnMemoryType = bgm_type;
}

void Exit_sound_system(void) {
    if (system_init_level & 2) {
        if (dword_795CF4 != 0) {
            AIXP_Finish();
        }

        ADXT_Destroy(adxt);
        ADXT_Finish();
        system_init_level &= ~2;
    }

    if (system_init_level & 1) {
        spu_all_off();
        system_init_level &= ~1;
    }
}

void Init_bgm_work(void) {
    work_init_zero(&bgm_exe, sizeof(BGMExecution));
    work_init_zero(&bgm_req, sizeof(BGMRequest));
}

void sound_all_off(void) {
    sound_bgm_off();
    spu_all_off();
}

void spu_all_off(void) {
    if (system_init_level & 1) {
        cseSeStopAll();
    }
}

void sound_bgm_off(void) {
    if ((system_init_level & 2) && adx_now_playing() != 0) {
        SsBgmOff();
    }
}

void setSeVolume(void) {
    f32 vol;

    if (system_init_level & 2) {
        vol = (127.0f / 15.0f) * (f32)se_level;
        cseSysSetMasterVolume((s32)vol);
    }
}

void setupSoundMode(void) {
    if (system_init_level & 2) {
        cseSysSetMono(sound_mode);
        ADXT_SetOutputMono(sound_mode);
    }
}

void sound_request_for_dc(SoundPatchConfig* rmc, s16 pan) {
    if (rmc->ptix != 0x7F) {
        if (pan < -0x20) {
            pan = -0x20;
        }

        if (pan > 0x20) {
            pan = 0x20;
        }

        if (rmc->code > 0x7F) {
            rmc->port = 0;
        }

        cseTsbRequest(rmc->ptix, rmc->code, 2, 6, pan, 2, rmc->port);
        return;
    }

    bgm_req.req = 1;

    switch (bgm_req.kind = rmc->bank) {
    case 5:
        if (bgm_exe.kind == 5) {
            bgm_req.req = 0;
            break;
        }

    case 7:
        bgm_req.data = rmc->port;
        bgm_req.code = -1;
        break;

    case 9:
        if ((adx_now_playing() != 0) && (bgm_exe.code == rmc->code)) {
            bgm_req.kind = 7;
            bgm_req.data = 0;
            bgm_req.code = -1;
            return;
        }

        bgm_req.kind = 4;
        /* fallthrough */

    case 2:
    case 4:
        bgm_req.data = 0;
        bgm_req.code = rmc->code;
        break;

    case 6:
        bgm_req.data = rmc->port;
        bgm_req.code = rmc->code;
        break;

    case 0:
    case 1:
    case 3:
    case 8:
        bgm_req.data = 0;
        bgm_req.code = -1;
        /* fallthrough */

    default:
        break;
    }
}

void BGM_Server() {
    if (!(system_init_level & 2)) {
        return;
    }

    if (bgm_req.req) {
        bgm_req.req = 0;
        bgm_exe.kind = bgm_req.kind;
        bgm_exe.data = bgm_req.data;

        if (bgm_req.code != -1) {
            bgm_exe.code = bgm_req.code;
        }

        bgm_exe.rno = 0;

        if (bgm_table[sys_w.bgm_type][bgm_exe.code].data & 0x8000) {
            bgm_exe.kind = 0;
        }
    }

    if (bgm_exe.code != 0) {
        bgm_vol_mix = bgm_level * bgm_table[sys_w.bgm_type][bgm_exe.code].vol / 15;
    }

    switch (bgm_exe.kind) {
    case 1:
        ADXT_Stop(adxt);
        bgm_seamless_clear();
        current_bgm = 0;
        bgm_exe.kind = 0;
        break;

    case 2:
        ADXT_Stop(adxt);

        if ((bgm_table[sys_w.bgm_type][bgm_exe.code].data & 0x4000) && (bgm_separate_check() != 0)) {
            bgm_exe.exIndex = bgm_table[sys_w.bgm_type][bgm_exe.code].data & 0xFF;
            bgm_exe.exEntry = bgm_exdata[sys_w.bgm_type][bgm_exe.exIndex].numStart;
            ADXT_Destroy(adxt);
            adxt = ADXT_Create(2, adx_stm_work, ADX_STM_WORK_SIZE);
            bgm_volume_setup(0);
            ADXT_Pause(adxt, 1);
            bgm_play_request(bgm_exe.exEntry, 0);
            bgm_exe.nowSeamless = 1;
            ADXT_StartSeamless(adxt);
        } else {
            bgm_seamless_clear();
            bgm_volume_setup(0);
            ADXT_Pause(adxt, 1);

            if (adx_NowOnMemoryType == sys_w.bgm_type) {
                switch (bgm_exe.code) {
                case 0x33:
                    ADXT_StartMem(adxt, adx_VS);
                    break;

                case 0x39:
                    ADXT_StartMem(adxt, adx_EmSel);
                    break;

                default:
                    bgm_play_request(bgm_exe.code, 1);
                    break;
                }
            } else {
                bgm_play_request(bgm_exe.code, 1);
            }
        }

        current_bgm = bgm_exe.code;
        bgm_exe.kind = 0;
        break;

    case 3:
        ADXT_Pause(adxt, 0);
        bgm_exe.kind = 0;
        break;

    case 4:
        if ((bgm_table[sys_w.bgm_type][bgm_exe.code].data & 0x4000) && (bgm_separate_check() != 0)) {
            if ((bgm_exe.nowSeamless == 0) || (bgm_exe.code != current_bgm)) {
                bgm_exe.exIndex = bgm_table[sys_w.bgm_type][bgm_exe.code].data & 0xFF;
                bgm_exe.exEntry = bgm_exdata[sys_w.bgm_type][bgm_exe.exIndex].numStart;

                if (bgm_exe.nowSeamless == 0) {
                    ADXT_Destroy(adxt);
                    adxt = ADXT_Create(2, adx_stm_work, ADX_STM_WORK_SIZE);
                    bgm_volume_setup(0);
                }

                bgm_play_request(bgm_exe.exEntry, 0);

                if (bgm_exe.nowSeamless == 0) {
                    bgm_exe.nowSeamless = 1;
                    ADXT_StartSeamless(adxt);
                }
            }
        } else {
            bgm_seamless_clear();
            bgm_volume_setup(0);

            if (adx_NowOnMemoryType == sys_w.bgm_type) {
                switch (bgm_exe.code) {
                case 0x33:
                    ADXT_StartMem(adxt, adx_VS);
                    break;

                case 0x39:
                    ADXT_StartMem(adxt, adx_EmSel);
                    break;

                default:
                    bgm_play_request(bgm_exe.code, 1);
                    break;
                }
            } else {
                bgm_play_request(bgm_exe.code, 1);
            }
        }

        if (ADXT_GetStatPause(adxt) != 0) {
            ADXT_Pause(adxt, 0);
        }

        current_bgm = bgm_exe.code;
        bgm_exe.kind = 0;
        break;

    case 5:
        switch (bgm_exe.rno) {
        case 0:
            bgm_fade.in.dex.hi = bgm_vol_now;
            bgm_fade.in.dex.low = -0x8000;
            bgm_fade.speed = -(bgm_fade.in.cal / bgm_exe.data);
            bgm_fade.in.cal = 0;
            bgm_exe.rno = 1;
            /* fallthrough */

        case 1:
            if (adx_now_playing() == 0) {
                bgm_exe.rno = 3;
                break;
            } else {
                bgm_exe.rno = 2;
                bgm_exe.volume = 0;
            }

            /* fallthrough */

        case 2:
            bgm_fade.in.cal += bgm_fade.speed;
            bgm_volume_setup(bgm_fade.in.dex.hi);

            if (bgm_vol_now) {
                break;
            }

            /* fallthrough */

        default:
            bgm_exe.kind = 1;
            break;
        }

        break;

    case 6:
        switch (bgm_exe.rno) {
        case 0:
            bgm_fade.in.dex.hi = bgm_vol_mix;
            bgm_fade.in.dex.low = -0x8000;
            bgm_fade.speed = bgm_fade.in.cal / bgm_exe.data;

            if ((bgm_table[sys_w.bgm_type][bgm_exe.code].data & 0x4000) && (bgm_separate_check() != 0)) {
                if ((bgm_exe.nowSeamless == 0) || (bgm_exe.code != current_bgm)) {
                    bgm_exe.exIndex = bgm_table[sys_w.bgm_type][bgm_exe.code].data & 0xFF;
                    bgm_exe.exEntry = bgm_exdata[sys_w.bgm_type][bgm_exe.exIndex].numStart;

                    if (bgm_exe.nowSeamless == 0) {
                        ADXT_Destroy(adxt);
                        adxt = ADXT_Create(2, adx_stm_work, ADX_STM_WORK_SIZE);
                    }

                    bgm_play_request(bgm_exe.exEntry, 0);

                    if (bgm_exe.nowSeamless == 0) {
                        bgm_exe.nowSeamless = 1;
                        ADXT_StartSeamless(adxt);
                    }
                }
            } else {
                bgm_seamless_clear();

                if (adx_NowOnMemoryType == sys_w.bgm_type) {
                    switch (bgm_exe.code) {
                    case 0x33:
                        ADXT_StartMem(adxt, adx_VS);
                        break;

                    case 0x39:
                        ADXT_StartMem(adxt, adx_EmSel);
                        break;

                    default:
                        bgm_play_request(bgm_exe.code, 1);
                        break;
                    }
                } else {
                    bgm_play_request(bgm_exe.code, 1);
                }
            }

            if (ADXT_GetStatPause(adxt) != 0) {
                ADXT_Pause(adxt, 0);
            }

            bgm_volume_setup(-0x7F);
            current_bgm = bgm_exe.code;
            bgm_exe.rno = 1;
            bgm_fade.in.dex.hi = -bgm_vol_mix;
            bgm_fade.in.dex.low = -0x8000;
            /* fallthrough */

        case 1:
            if (adx_now_playing() != 0) {
                bgm_exe.rno = 2;
                bgm_exe.volume = 0;
            } else {
                break;
            }

            /* fallthrough */

        case 2:
            bgm_fade.in.cal += bgm_fade.speed;
            bgm_volume_setup(bgm_fade.in.dex.hi);

            if (bgm_vol_now < bgm_vol_mix) {
                break;
            }

            /* fallthrough */

        default:
            bgm_exe.kind = 0;
            break;
        }

        break;

    case 7:
        bgm_vol_mix = bgm_level * bgm_table[sys_w.bgm_type][current_bgm].vol / 15;
        bgm_volume_setup(bgm_exe.data);
        bgm_exe.kind = 0;
        break;

    case 8:
        bgm_exe.kind = 0;
        break;
    }

    if (bgm_exe.nowSeamless && (ADXT_GetNumFiles(adxt) <= 0)) {
        bgm_exe.exEntry += 1;

        if (bgm_exe.exEntry > bgm_exdata[sys_w.bgm_type][bgm_exe.exIndex].numEnd) {
            bgm_exe.exEntry = bgm_exdata[sys_w.bgm_type][bgm_exe.exIndex].numLoop;
        }

        bgm_play_request(bgm_exe.exEntry, 0);
    }
}

/* Xbox: no Debug_w[5] test */
s32 bgm_separate_check() {
    return (mpp_w.inGame | bgm_seamless_always) != 0;
}

void setupAlwaysSeamlessFlag(s16 flag) {
    bgm_seamless_always = flag;
}

void bgm_play_request(s32 filenum, s32 flag) {
    if (flag == 0) {
        ADXT_EntryAfs(adxt, 0, filenum);
    } else {
        ADXT_StartAfs(adxt, 0, bgm_table[sys_w.bgm_type][filenum].fnum);
    }
}

void bgm_seamless_clear() {
    if (!bgm_exe.nowSeamless) {
        return;
    }

    bgm_exe.nowSeamless = 0;
    ADXT_Stop(adxt);
    ADXT_ResetEntry(adxt);
    ADXT_Destroy(adxt);
    adxt = ADXT_Create(2, adx_stm_work, ADX_STM_WORK_SIZE);
}

void bgm_volume_setup(s16 data) {
    s16 bhd;

    bgm_fade_ix = data;
    bhd = bgm_fade_ix;
    bgm_vol_now = bhd + bgm_vol_mix;

    if (bgm_half_down) {
        if (Country == 1) {
            bgm_vol_now /= 3;
        } else {
            bgm_vol_now = 0;
        }
    }

    if (bgm_vol_now > bgm_vol_mix) {
        bgm_vol_now = bgm_vol_mix;
    }

    if (bgm_vol_now < 0) {
        bgm_vol_now = 0;
    }

    if (Debug_w[44]) {
        bgm_vol_now = 0;
    }

    ADXT_SetOutVol(adxt, adx_volume[bgm_vol_now]);
}

/* Xbox: an ADXT error state (6) is cleared, and the AIX player (handle at 0xAE6FEC) also counts: state 2 is playing, state 4 an error that is cleared */
s32 adx_now_playing() {
    s32 stat;

    bgm_exe.state = ADXT_GetStat(adxt);

    if ((bgm_exe.state == ADXT_STAT_PLAYING) || (bgm_exe.state == ADXT_STAT_DECEND)) {
        return 1;
    }

    if (bgm_exe.state == 6) {
        xb_ClearAdxtError(0);
    }

    stat = AIXP_GetStat(D_00AE6FEC);

    if (stat == 2) {
        return 1;
    }

    if (stat == 4) {
        xb_ClearAdxtError(1);
    }

    return 0;
}

s32 adx_now_playend() {
    bgm_exe.state = ADXT_GetStat(adxt);

    if (bgm_exe.state == ADXT_STAT_PLAYEND) {
        return 1;
    }

    return AIXP_GetStat(D_00AE6FEC) == 3;
}

/* Xbox: 2 only while adx_now_playing() returns 1 (branchless in retail). */
s32 bgm_play_status() {
    if (bgm_exe.kind == 5) {
        return 1;
    }

    if (adx_now_playing() == 1) {
        return 2;
    }

    return 0;
}

s32 bgmSkipCheck(s32 code) {
    return (bgm_table[sys_w.bgm_type][code].data & 0x8000) != 0;
}

void SsAllNoteOff(void) {
    sound_all_off();
}

void SsRequestPan(u16 reqNum, s16 start, s16 /* unused */, s32 /* unused */, s32 /* unused */) {
    SoundPatchConfig rmcode;

    start -= 0x40;

    if (start < -0x3F) {
        start = -0x3F;
    }

    if (start > 0x3F) {
        start = 0x3F;
    }

    if (remake_sound_code_for_DC(reqNum, &rmcode)) {
        return;
    }

    Store_Sound_Code(reqNum, &rmcode);
    sound_request_for_dc(&rmcode, start);
}

u16 remake_sound_code_for_DC(u16 code, SoundPatchConfig* rmcode) {
    u16 cd;
    u16 mtf;
    u16 p2s;
    u16 rnum;

    rnum = mtf = p2s = 0;

    if (code >= 0x760) {
        code -= 0x600;
        mtf = 1;
    }

    if (code >= 0x400) {
        code -= 0x300;
        p2s = 1;
    }

    rmcode->code = (cd = sdcode_conv[code]) & 0xFFF;

    switch (cd & 0xF000) {
    case 0x0:
        switch (p2s + mtf * 2) {
        case 0:
            rmcode->ptix = 1;
            rmcode->bank = 0;
            rmcode->port = 0;
            break;

        case 1:
            rmcode->ptix = 2;
            rmcode->bank = 1;
            rmcode->port = 3;
            break;

        case 2:
            rmcode->ptix = 2;
            rmcode->bank = 1;
            rmcode->port = 0;
            rmcode->code += 32;
            break;

        case 3:
            rmcode->ptix = 1;
            rmcode->bank = 0;
            rmcode->port = 3;
            rmcode->code += 32;
            break;
        }

        break;

    case 0x2000:
        rmcode->ptix = 0;
        rmcode->bank = 0;

        if (p2s) {
            rmcode->port = 3;
        } else {
            rmcode->port = 0;
        }

        break;

    case 0x3000:
        rmcode->ptix = 0;
        rmcode->bank = 0;

        if (p2s) {
            rmcode->port = -3;
        } else {
            rmcode->port = 0;
        }

        break;

    case 0x8000:
        rmcode->ptix = 0x7F;
        rmcode->bank = 4;
        rmcode->port = 0;
        break;

    default:
    case 0x7000:
        rmcode->ptix = 0x7FFF;
        rmcode->bank = 0;
        rmcode->port = 0;
        rnum = 1;

        while (1) {
            flPrintL(3, 5, "BAD SE CODE %X", code);
            njWaitVSync_with_N();
        }

        break;
    }

    return rnum;
}

void SsRequest(u16 ReqNumber) {
    SoundPatchConfig rmcode;

    if (remake_sound_code_for_DC(ReqNumber, &rmcode)) {
        return;
    }

    sound_request_for_dc(&rmcode, 0);
}

void SsRequest_CC(u16 num) {
    SoundPatchConfig rmcode;

    if (remake_sound_code_for_DC(num, &rmcode)) {
        return;
    }

    rmcode.bank = 9;
    sound_request_for_dc(&rmcode, 0);
}

void Standby_BGM(u16 num) {
    SoundPatchConfig rmcode;

    if (remake_sound_code_for_DC(num, &rmcode)) {
        return;
    }

    rmcode.bank = 2;
    sound_request_for_dc(&rmcode, 0);
}

void Go_BGM(void) {
    SoundPatchConfig rmcode;

    rmcode.ptix = 0x7F;
    rmcode.bank = 3;
    rmcode.port = 0;
    rmcode.code = 0;
    sound_request_for_dc(&rmcode, 0);
}

void SsBgmOff(void) {
    SoundPatchConfig rmcode;

    rmcode.ptix = 0x7F;
    rmcode.bank = 1;
    rmcode.port = 0;
    rmcode.code = 0;
    sound_request_for_dc(&rmcode, 0);
}

void SsBgmFadeIn(u16 ReqNumber, u16 FadeSpeed) {
    SoundPatchConfig rmcode;
    s32 fade_time;

    if (remake_sound_code_for_DC(ReqNumber, &rmcode) || rmcode.ptix != 0x7F) {
        return;
    }

    fade_time = 0x8000 / (s32)FadeSpeed;
    rmcode.bank = 6;
    rmcode.port = (s16)fade_time;
    sound_request_for_dc(&rmcode, 0);
}

void SsBgmFadeOut(u16 time) {
    SoundPatchConfig rmcode;
    s32 fade_time = 0x8000 / (s32)time;

    rmcode.ptix = 0x7F;
    rmcode.bank = 5;
    rmcode.code = 0;
    rmcode.port = (s16)fade_time;
    sound_request_for_dc(&rmcode, 0);
}

void SsBgmControl(s8 unused, s8 volume) {
    SoundPatchConfig rmcode;

    (void)unused;
    rmcode.ptix = 0x7F;
    rmcode.bank = 7;
    rmcode.code = 0;
    rmcode.port = volume;

    if (rmcode.port < -0x7F) {
        rmcode.port = -0x7F;
    }

    if (rmcode.port > 0) {
        rmcode.port = 0;
    }

    sound_request_for_dc(&rmcode, 0);
}

void SsBgmHalfVolume(s16 flag) {
    SoundPatchConfig rmcode;

    bgm_half_down = flag;
    rmcode.ptix = 0x7F;
    rmcode.bank = 7;
    rmcode.code = 0;
    rmcode.port = 0;
    sound_request_for_dc(&rmcode, 0);
}

void SE_cursor_move(void) {
    SsRequest(96);
}

void SE_selected() {
    SsRequest(98);
}

void SE_dir_cursor_move(void) {
    SsRequest(343);
}

void SE_dir_selected() {
    SsRequest(98);
}

void mlSysSetMono(u32 mono_sw) {
    D_00797100 = mono_sw;
}

void mlSysSetMasterVolume(s32 vol) {
    if (vol < 0) {
        vol = 0;
    }

    if (vol > 127) {
        vol = 127;
    }

    mlSysSetBankVolume(D_00797BA8, 0xFF, D_003F3510[vol]);
}

#if 0
/* PS2 C for functions not located in sf33rd.xbe yet. */

s32 cseMemMapInit(void* pSpuMemMap) {
    return mlMemMapInit(pSpuMemMap);
}

s32 cseSeStopAll() {
    mlTsbStopAll();
    mlSeStopAll();
    return 0;
}

s32 cseSysSetMasterVolume(s32 vol) {
    return mlSysSetMasterVolume(vol);
}

s32 cseSysSetMono(u32 mono_sw) {
    return mlSysSetMono(mono_sw);
}
#endif
