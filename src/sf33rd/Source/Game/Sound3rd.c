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
 * xb_AixBgmVolume 0x9B8BE size 0x95. FLAG: x86-only callees
 * AIXP_SetOutVolDolbyDigital.
 * xb_AixBgmStop 0x9B953 size 0x64. FLAG: x86-only callees AIXP_Stop,AIXP_SetLp
 * Sw,AIXP_Pause,xb_aixp_StartFnameSurround,xb_AixBgmVolume.
 * xb_AixBgmResume 0x9B9B7 size 0x2F. FLAG: x86-only callees AIXP_Pause.
 * xb_ClearAdxtError 0x9B9E6 size 0x14. FLAG: x86-only callees
 * ADXT_ClearErrCode.
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
 * SE_selected 0x9C793 size 0x9.
 * SE_dir_cursor_move 0x9C79C size 0xC.
 * sound_bgm_off 0x9C7A8 size 0x18.
 * sound_all_off 0x9C7C0 size 0xA.
 * SsAllNoteOff 0x9C7CA size 0x5.
 * cseSysSetMono 0xF4510 size 0xD. FLAG: not compared.
 * cseSysSetMasterVolume 0xF451D size 0xD. FLAG: not compared.
 * cseSeStopAll 0xF452A size 0x8. FLAG: not compared.
 * mlSysSetMono 0xF4D61 size 0xA. FLAG: PS2-only callees mlRpcQueueSetData.
 * xb_CreateSoundSource 0xF4E40 size 0x5.
 * xb_CreateSoundBank 0xF4E45 size 0x5.
 * xb_RegisterWaveBank 0xF4E4A size 0x5.
 * xb_UnRegisterWaveBank 0xF4E4F size 0x5.
 * mlSysSetBankVolume 0xF4E54 size 0x5.
 * xb_GetNotification 0xF4E5E size 0x5.
 * IXACTSoundSource__SetMixBins 0xF4E63 size 0x5.
 * IXACTSoundSource__StopSoundCues 0xF4E6D size 0x5.
 * xb_XactCall_1B7FB7 0xF4ECA size 0x5.
 * IXACTSoundBank__Stop 0xF4F08 size 0x5.
 * xb_PlaySoundCue 0xF4F0D size 0x32. FLAG: x86-only callees
 * xb_DownloadEffectsImage.
 * mlSysSetMasterVolume 0xF4FF2 size 0x2A. FLAG: x86-only constants 0x7f.
 * sndCheckVTransStatus is folded into 0x9B78F with 9 other bodies. Unnamed.
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
 * Data: cseTSBDataTable 0x32FD28, not compared.
 * Data: csePHDDataTable: not located in the XBE, PS2 initializer kept.
 * Data: bgm_table: not located in the XBE, PS2 initializer kept.
 * Data: bgm_exdata: not located in the XBE, PS2 initializer kept.
 * Data: se_level 0x9CA4B4.
 * Data: bgm_level 0xC7C818.
 * Data: bgm_vol_mix 0xB249E4.
 * Data: bgm_vol_now 0xC7C81C.
 * Data: bgm_fade_ix 0xC7C81A.
 * Data: bgm_half_down 0x8813F8.
 * Data: current_bgm 0xAE6FE8.
 * Data: bgm_seamless_always 0x8813F6.
 * Data: bgm_fade 0xAE6FE0.
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
 * Unnamed data used (not checked): Init_sound_system: 0x2683b8,0x2683d0;
 * setSeVolume: 0x2683e0; xb_AixBgmVolume: 0xae6fec; xb_AixBgmStop:
 * 0x2683e4,0xae6fec; xb_AixBgmResume: 0xae6fec; bgm_play_request: 0x3304f0;
 * adx_now_playing: 0xae6fec; adx_now_playend: 0xae6fec; bgmSkipCheck:
 * 0x3304f0; BGM_Server: 0x2683e4,0x3304f0,0x3304f8; mlSysSetMono: 0x797100;
 * xb_PlaySoundCue: 0x795c10,0x797120; mlSysSetMasterVolume: 0x3f3510,0x797ba8.
 * Globals: Game_Default_Data 0x265548, sdcode_conv 0x265808, adx_volume
 * 0x2682B8, cseTSBDataTable 0x32FD28, adx_NowOnMemoryType 0x32FE2C,
 * dword_795CF4 0x795CF4, Country 0x7A8748, mpp_w 0x7AA5C0, system_init_level
 * 0x7AABDC, sys_w 0x7C5940, bgm_type 0x7C595A, adxt 0x8813DC, bgm_exe
 * 0x8813E0, bgm_seamless_always 0x8813F6, bgm_half_down 0x8813F8, se_level
 * 0x9CA4B4, bgm_fade 0xAE6FE0, current_bgm 0xAE6FE8, adx_stm_work 0xAE7000,
 * bgm_vol_mix 0xB249E4, adx_EmSel 0xB24A00, adx_VS 0xC4BEE0, bgm_req 0xC7C810,
 * bgm_level 0xC7C818, bgm_fade_ix 0xC7C81A, bgm_vol_now 0xC7C81C.
 */

#include "structs.h"

#define ADX_STM_WORK_SIZE 252388
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

extern void XB_STDCALL mlSysSetBankVolume(s32 port, s32 mask, s32 vol);
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
extern void *D_00AE6FEC;
void xb_ClearAdxtError(s32 which);
void xb_CreateDirectSound(const char* path);
void AIXP_Init(void);
void* AIXP_Create(s32 maxnch, s32 nstm, void* work, s32 worksize);
void* XB_STDCALL XPhysicalAlloc(u32 size, u32 address, u32 alignment, u32 protect);
extern const struct _SAVE_W Game_Default_Data;
void xb_InitSoundBankList(void);
void xb_ClearColorRamEntries(void);
void xb_SetColorRamEntry(void* addr, u32 size, s32 id, s32 index);
s32 AIXP_GetStat(void *aixp);
void ADXT_ClearErrCode(ADXT adxt);
void XB_STDCALL IXACTEngine_CreateSoundSource(s32 a0, s32 a1, s32 a2);
void XB_STDCALL IXACTEngine_CreateSoundBank(s32 a0, s32 a1, s32 a2, s32 a3);
void XB_STDCALL IXACTEngine_RegisterWaveBank(s32 a0, s32 a1, s32 a2, s32 a3);
void XB_STDCALL IXACTEngine_UnRegisterWaveBank(s32 a0, s32 a1);
void XB_STDCALL IXACTEngine_SetMasterVolume(s32 a0, s32 a1, s32 a2);
void XB_STDCALL IXACTEngine_GetNotification(s32 a0, s32 a1, s32 a2);
void XB_STDCALL IXACTSoundBank_Release(s32 a0);
void XB_STDCALL IXACTSoundBank_Stop(s32 a0, s32 a1, s32 a2, s32 a3);
extern s32 D_00795C10;
extern u8 D_00797120[];
s32 XB_STDCALL xb_DownloadEffectsImage(s32 dsound, s32 a, s32 b, s32* loc, void* out);
void XB_STDCALL sub_001B807F(s32 a0, s32 a1);
void XB_STDCALL sub_001B8089(s32 a0);
s32 AIXP_Pause(s32 aixp, s32 sw);
void AIXP_SetLpSw(void *aixp, s32 sw);
void AIXP_Stop(s32 aixp);
void AIXP_SetOutVolDolbyDigital(void *aixp, s32 spkid, s32 vol);
s32 xb_aixp_StartFnameSurround(void *aixp, const char *fname, void *dir);
s32 xb_AixBgmStop(u16 bgm, s32 fade);
s32 xb_AixBgmResume(u16 bgm);
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
extern struct _SYSTEM_W sys_w;
ADXT ADXT_Create(Sint32 maxnch, void* work, Sint32 worksize);
s32 flLogOut(s8* format, ...);
extern s32 system_init_level;
void load_any_color(u16 ix, u8 kokey);
s32 cseTsbSetBankAddr(u32 bank, SoundEvent* addr);
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
void ADXT_StartAfs(ADXT adxt, Sint32 patid, Sint32 fid);
void ADXT_EntryAfs(ADXT adxt, Sint32 patid, Sint32 fid);
void ADXT_ResetEntry(ADXT adxt);
extern u8 Country;
void ADXT_SetOutVol(ADXT adxt, Sint32 vol);
Sint32 ADXT_GetStat(ADXT adxt);
u16 remake_sound_code_for_DC(u16 code, SoundPatchConfig* rmcode);
extern const u16 sdcode_conv[];

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

s8* csePHDDataTable[21] = { 0 };

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

/* The Xbox takes the levels from Game_Default_Data, creates DirectSound, and allocates an AIX player (D_00AE6FEC) in 0x6952C bytes of physical memory; it has no PS2 sound driver. */
void Init_sound_system() {
    bgm_level = Game_Default_Data.BGM_Level;
    se_level = Game_Default_Data.SE_Level;
    bgm_half_down = 0;
    current_bgm = 0;
    bgm_seamless_always = 0;
    sys_w.sound_mode = 0;
    sys_w.bgm_type = 0;
    xb_CreateDirectSound("D:\\XB_HostPC\\");
    ADXT_Init();
    AIXP_Init();
    adxt = ADXT_Create(2, adx_stm_work, ADX_STM_WORK_SIZE);
    dword_795CF4 = (s32)XPhysicalAlloc(0x6952C, -1, 0, 4);

    if (dword_795CF4 != 0) {
        D_00AE6FEC = AIXP_Create(3, 2, (void*)dword_795CF4, 0x6952C);
    } else {
        flLogOut("AIXP_Create Failed.\n");
    }

    system_init_level |= 2;
}

/* Xbox: always 1; the code after it in the PS2 slot (0x9B792) is another function */
s32 sndCheckVTransStatus(s32 type) {
    return 1;
}

/* The Xbox sets up its sound bank list and color RAM entries, loads three color files (109, 110, 111), and sets init level bit 0; it has no SPU memory map. */
void sndInitialLoad() {
    xb_InitSoundBankList();
    xb_ClearColorRamEntries();
    load_any_color(109, 20); // This loads SE.bd (index 7)
    load_any_color(110, 20);
    load_any_color(111, 20);
    cseTsbSetBankAddr(0, *cseTSBDataTable);
    xb_SetColorRamEntry(0, 0, 0, 0);
    system_init_level |= 1;
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

/* Xbox: the AIX player is stopped with ADXT; a track change goes through
   xb_AixBgmStop and a resume through xb_AixBgmResume, and the opening
   theme (0x34) in the new arrangement plays as ST3_3_OP.aix. */
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
        AIXP_Stop((s32)D_00AE6FEC);
        ADXT_Stop(adxt);
        bgm_seamless_clear();
        current_bgm = 0;
        bgm_exe.kind = 0;
        break;

    case 2:
        AIXP_Stop((s32)D_00AE6FEC);
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
        } else if (xb_AixBgmStop(bgm_exe.code, 0) != 1) {
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
        if (xb_AixBgmResume(bgm_exe.code) != 1) {
            ADXT_Pause(adxt, 0);
        }

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
            AIXP_Stop((s32)D_00AE6FEC);
            bgm_volume_setup(0);

            /* Xbox: the opening theme in the new arrangement is the 5.1
               AIX stream */
            if (bgm_exe.code == 0x34 && sys_w.bgm_type == 0) {
                ADXT_Stop(adxt);
                xb_aixp_StartFnameSurround(D_00AE6FEC, "ST3_3_OP.aix", 0);
            } else if (adx_NowOnMemoryType == sys_w.bgm_type) {
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

/* The flag test is inverted, as the retail branch layout has it. */
void bgm_play_request(s32 filenum, s32 flag) {
    if (flag != 0) {
        ADXT_StartAfs(adxt, 0, bgm_table[sys_w.bgm_type][filenum].fnum);
    } else {
        ADXT_EntryAfs(adxt, 0, filenum);
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

/* The Xbox has no Debug_w[44] test. */
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

/* The Xbox does not call Store_Sound_Code. */
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

    sound_request_for_dc(&rmcode, start);
}

/* Xbox: a bad code is reported in the return value; the PS2 loop that
 * printed it forever is gone. sdcode_conv is 0x265808. */
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
        rmcode->ptix = 0x7FFF;
        rmcode->bank = 0;
        rmcode->port = 0;
        rnum = 1;
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

void xb_ClearAdxtError(s32 which) {
    if (which == 0) {
        ADXT_ClearErrCode(adxt);
    }
}

void XB_STDCALL xb_CreateSoundSource(s32 a0, s32 a1, s32 a2) {
    IXACTEngine_CreateSoundSource(a0, a1, a2);
}

void XB_STDCALL xb_CreateSoundBank(s32 a0, s32 a1, s32 a2, s32 a3) {
    IXACTEngine_CreateSoundBank(a0, a1, a2, a3);
}

void XB_STDCALL xb_RegisterWaveBank(s32 a0, s32 a1, s32 a2, s32 a3) {
    IXACTEngine_RegisterWaveBank(a0, a1, a2, a3);
}

void XB_STDCALL xb_UnRegisterWaveBank(s32 a0, s32 a1) {
    IXACTEngine_UnRegisterWaveBank(a0, a1);
}

void XB_STDCALL mlSysSetBankVolume(s32 a0, s32 a1, s32 a2) {
    IXACTEngine_SetMasterVolume(a0, a1, a2);
}

void XB_STDCALL xb_GetNotification(s32 a0, s32 a1, s32 a2) {
    IXACTEngine_GetNotification(a0, a1, a2);
}

void XB_STDCALL xb_XactCall_1B7FB7(s32 a0) {
    IXACTSoundBank_Release(a0);
}

void XB_STDCALL IXACTSoundBank__Stop(s32 a0, s32 a1, s32 a2, s32 a3) {
    IXACTSoundBank_Stop(a0, a1, a2, a3);
}

void XB_STDCALL IXACTSoundSource__SetMixBins(s32 a0, s32 a1) {
    sub_001B807F(a0, a1);
}

void XB_STDCALL IXACTSoundSource__StopSoundCues(s32 a0) {
    sub_001B8089(a0);
}

s32 xb_PlaySoundCue(s32 addr, s32 size) {
    s32 loc[2];

    loc[0] = -1;
    loc[1] = -1;
    return xb_DownloadEffectsImage(D_00795C10, addr, size, loc, D_00797120) >= 0;
}

void xb_AixBgmVolume(s32 fade) {
    s32 i;

    bgm_fade_ix = fade;
    bgm_vol_now = bgm_vol_mix + fade;

    if (bgm_half_down != 0) {
        if (Country == 1) {
            bgm_vol_now = bgm_vol_now / 3;
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

    for (i = 0; i < 6; i++) {
        if (i != 5) {
            AIXP_SetOutVolDolbyDigital(D_00AE6FEC, i, adx_volume[bgm_vol_now]);
        } else {
            AIXP_SetOutVolDolbyDigital(D_00AE6FEC, 5, adx_volume[bgm_vol_now]);
        }
    }
}

s32 xb_AixBgmStop(u16 bgm, s32 fade) {
    if (bgm == 0x34 && bgm_type == 0) {
        if (dword_795CF4 != 0) {
            AIXP_Stop((s32)D_00AE6FEC);
            AIXP_SetLpSw(D_00AE6FEC, 0);
            AIXP_Pause((s32)D_00AE6FEC, 1);
            xb_aixp_StartFnameSurround(D_00AE6FEC, "ST3_3_OP.aix", 0);
            xb_AixBgmVolume(fade);
        }

        return 1;
    }

    return 0;
}

s32 xb_AixBgmResume(u16 bgm) {
    if (bgm == 0x34 && bgm_type == 0) {
        if (dword_795CF4 != 0) {
            AIXP_Pause((s32)D_00AE6FEC, 0);
        }

        return 1;
    }

    return 0;
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
