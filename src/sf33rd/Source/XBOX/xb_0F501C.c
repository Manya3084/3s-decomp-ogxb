/* xb_0F501C.c: Xbox-only code from the run of Xbox-only functions at 0xF501C, which no
 * PS2 file covers.
 * Capcom's source is lost. Its C++ methods are written as C,
 * XB_FASTCALL (__fastcall) with this first. Each body was checked
 * against retail by analysis-ps2map/xbgen.py. The xb_ names are
 * made up. */

#include "types.h"
#include <stdio.h>
#include <string.h>

typedef struct {
    s32 state;
    s16 id;
    u8 pad6[2];
    u8 grp;
    u8 prio;
    u8 padA[0xA];
    s32 cue;
    s32 bank;
    s32 x;
    u8 pad20[0x18];
} XB_SESLOT;
typedef struct {
    s32 v[3];
} XB_REQ12;
typedef struct {
    u16 lo;
    u16 hi;
} XB_SEQ;
typedef struct {
    u8 used;
    u8 active;
    u8 pad2[2];
    s32 id;
    s32 pad8;
} XB_MATCHWIN;
typedef struct {
    u8 pad0[0x184];
    XB_MATCHWIN win[4];
} XB_MATCHINFO;
extern XB_SESLOT D_00797128[];
s32 XB_STDCALL IXACTSoundSource__StopSoundCues(s32 a);
s32 XB_STDCALL IXACTSoundBank__Stop(s32 a, s32 b, s32 c, s32 d);
extern s32 D_00797BA8;
void xb_XactPollNotifications(void);
s32 XB_STDCALL XACTEngineDoWork(void);
s32 XB_STDCALL IXHVEngine__SetVoiceMask(s32 a, s32 b, s32 c);
s32 XB_STDCALL IXHVEngine__SetProcessingMode(s32 a, s32 b, s32 c);
void xb_deque_IterDeref(void);
void XB_FASTCALL xb_LiveObj_Update(u8* self);
void XB_FASTCALL CXBStopWatch_StartZero(void* self);
extern void (XB_STDCALL *D_00218DC8)(void* cs);
extern s32 D_00797F18;
s32 XB_STDCALL CreateThread(void* attr, u32 stack, void* start, void* param, u32 flags, u32* id);
s32 XB_STDCALL SetThreadPriority(s32 h, s32 prio);
s32 XB_STDCALL SetThreadPriorityBoost(s32 h, s32 off);
u32 XB_STDCALL ResumeThread(s32 h);
u32 XB_STDCALL xb_LiveVoice_Thread(void* arg);
extern u8 D_00797EFC[];
extern u8* D_00798CAC;
void XB_FASTCALL xb_WINSTR_CLASS_Update(void* self);
void XB_FASTCALL xb_WINSTR_CLASS_Release(s32* self);
void xb_xlive_disp_DrawMessage(s32 a, s32 b, s32 c, f32 scale, f32 alpha, s32 flags);
void xb_xlive_disp_DrawTextBox(f32 x, f32 y, f32 scale, s32 text, f32 alpha, s32 flags);
extern u8* D_00798B78;
s32 XB_STDCALL lstrcpynW(void* dst, const void* src, s32 n);
s32 XB_STDCALL XOnlineFriendsRequest(s32 user, XB_REQ12 friend_);
s32 XB_STDCALL XOnlineFriendsRequestEx(s32 user, XB_REQ12 friend_, s32 a, s32 b, s32 c);
void xb_OnlineObj_Move(s32 id);
s32 xb_xlive_disp_DrawRectF(f32 a, f32 b, f32 c, f32 d, f32 e);
s32 xb_xlive_disp_SetObj0C(s32 id, s32 v);
void xb_xlive_friend_Release(s32 id);
void xb_OnlineObj_Fade(s32 id);
s32 xb_LivePadTrigger(s32 key);
extern s32 D_003F8328[];
extern u8 D_0079902C[];
extern u8 D_00798EA8[];
extern u8 D_002B53F0[];
s32 xb_xlive_disp_DrawRectFloat(f32 x, f32 y, f32 w, f32 h);
extern s32 D_0079941C;

/* xb_SetupLiveLanguage's tables: each string global takes entry [lang] of
 * its two-entry table (0 Japanese, 1 English). */
s32 XB_STDCALL XGetLanguage(void);
s32 XB_STDCALL XGetGameRegion(void);
extern u8 D_00418574[], D_00418590[], D_004184D8[], D_0041847C[], D_00418498[], D_004183E0[];
extern u8* D_007993AC;
extern u8* D_0079923C;
extern u8* D_00799148;
extern s32 D_0041597C;
extern u8* D_0041592C[];
extern s32 D_00415954[];
extern s32 D_004183D8;
extern u8* D_004183C8[];
extern s32 D_004183D0[];
extern char* D_00799400;
extern char* D_00415980[2];
extern char* D_00799374;
extern char* D_00415988[2];
extern char* D_0079909C;
extern char* D_00415990[2];
extern char* D_007991B8;
extern char* D_00415998[2];
extern char* D_007992E8;
extern char* D_004159A0[2];
extern char* D_00799408;
extern char* D_004159A8[2];
extern char* D_0079936C;
extern char* D_004159B0[2];
extern char* D_007991FC;
extern char* D_004159B8[2];
extern char* D_00799118;
extern char* D_004159C0[2];
extern char* D_0079913C;
extern char* D_004159C8[2];
extern char* D_007992E4;
extern char* D_004159D0[2];
extern char* D_00799310;
extern char* D_004159D8[2];
extern char* D_00799080;
extern char* D_004159E0[2];
extern char* D_00799334;
extern char* D_004159E8[2];
extern char* D_00799270;
extern char* D_004159F0[2];
extern char* D_007991C0;
extern char* D_004159F8[2];
extern char* D_00799060;
extern char* D_00415A00[2];
extern char* D_00799234;
extern char* D_00415A08[2];
extern char* D_00799278;
extern char* D_00415A10[2];
extern char* D_0079925C;
extern char* D_00415A18[2];
extern char* D_007993B8;
extern char* D_00415A20[2];
extern char* D_00799210;
extern char* D_00415A28[2];
extern char* D_007992C8;
extern char* D_00415A30[2];
extern char* D_007992A8;
extern char* D_00415A38[2];
extern char* D_0079915C;
extern char* D_00415A40[2];
extern char* D_00799104;
extern char* D_00415A48[2];
extern char* D_007991A0;
extern char* D_00415A50[2];
extern char* D_007993C8;
extern char* D_00415A58[2];
extern char* D_007990EC;
extern char* D_00415A60[2];
extern char* D_007992C4;
extern char* D_00415A68[2];
extern char* D_00799090;
extern char* D_00415A70[2];
extern char* D_00799114;
extern char* D_00415A78[2];
extern char* D_00799124;
extern char* D_00415A80[2];
extern char* D_007991E0;
extern char* D_00415A88[2];
extern char* D_007990B4;
extern char* D_00415A90[2];
extern char* D_00799188;
extern char* D_00415A98[2];
extern char* D_007993BC;
extern char* D_00415AA0[2];
extern char* D_0079938C;
extern char* D_00415AA8[2];
extern char* D_00799290;
extern char* D_00415AB0[2];
extern char* D_00799378;
extern char* D_00415AB8[2];
extern char* D_007992C0;
extern char* D_00415AC0[2];
extern char* D_00799140;
extern char* D_00415AC8[2];
extern char* D_00799088;
extern char* D_00415AD0[2];
extern char* D_00799300;
extern char* D_00415AD8[2];
extern char* D_007993C4;
extern char* D_00415AE0[2];
extern char* D_00799268;
extern char* D_00415AE8[2];
extern char* D_00799228;
extern char* D_00415AF0[2];
extern char* D_007991E4;
extern char* D_00415AF8[2];
extern char* D_007992D4;
extern char* D_00415B00[2];
extern char* D_00799264;
extern char* D_00415B08[2];
extern char* D_00799064;
extern char* D_00415B10[2];
extern char* D_0079912C;
extern char* D_00415B18[2];
extern char* D_007990E8;
extern char* D_00415B20[2];
extern char* D_00799244;
extern char* D_00415B28[2];
extern char* D_007992BC;
extern char* D_00415B30[2];
extern char* D_00799198;
extern char* D_00415B38[2];
extern char* D_007991DC;
extern char* D_00415B40[2];
extern char* D_007993A0;
extern char* D_00415B48[2];
extern char* D_00799070;
extern char* D_00415B50[2];
extern char* D_007991D8;
extern char* D_00415B58[2];
extern char* D_007992B4;
extern char* D_00415B60[2];
extern char* D_00799110;
extern char* D_00415B68[2];
extern char* D_007991CC;
extern char* D_00415B70[2];
extern char* D_00799394;
extern char* D_00415B78[2];
extern char* D_0079908C;
extern char* D_00415B80[2];
extern char* D_007991C4;
extern char* D_00415B88[2];
extern char* D_00799238;
extern char* D_00415B90[2];
extern char* D_007990FC;
extern char* D_00415B98[2];
extern char* D_007991B4;
extern char* D_00415BA0[2];
extern char* D_007992E0;
extern char* D_00415BA8[2];
extern char* D_00799404;
extern char* D_00415BB0[2];
extern char* D_007991AC;
extern char* D_00415BB8[2];
extern char* D_00799230;
extern char* D_00415BC0[2];
extern char* D_007993FC;
extern char* D_00415BC8[2];
extern char* D_00799108;
extern char* D_00415BD0[2];
extern char* D_00799190;
extern char* D_00415BD8[2];
extern char* D_007993F8;
extern char* D_00415BE0[2];
extern char* D_00799208;
extern char* D_00415BE8[2];
extern char* D_0079932C;
extern char* D_00415BF0[2];
extern char* D_007993D8;
extern char* D_00415BF8[2];
extern char* D_00799138;
extern char* D_00415C00[2];
extern char* D_00799248;
extern char* D_00415C08[2];
extern char* D_0079933C;
extern char* D_00415C10[2];
extern char* D_007993E4;
extern char* D_00415C18[2];
extern char* D_00799150;
extern char* D_00415C20[2];
extern char* D_00799308;
extern char* D_00415C28[2];
extern char* D_007990A0;
extern char* D_00415C30[2];
extern char* D_007991BC;
extern char* D_00415C38[2];
extern char* D_007992D0;
extern char* D_00415C40[2];
extern char* D_00799388;
extern char* D_00415C48[2];
extern char* D_007990B0;
extern char* D_00415C50[2];
extern char* D_00799274;
extern char* D_00415C58[2];
extern char* D_007993C0;
extern char* D_00415C60[2];
extern char* D_00799084;
extern char* D_00415C68[2];
extern char* D_007991A8;
extern char* D_00415C70[2];
extern char* D_00799078;
extern char* D_00415C78[2];
extern char* D_007993EC;
extern char* D_00415C80[2];
extern char* D_007991F4;
extern char* D_00415C88[2];
extern char* D_0079931C;
extern char* D_00415C90[2];
extern char* D_007993CC;
extern char* D_00415C98[2];
extern char* D_007990F4;
extern char* D_00415CA0[2];
extern char* D_00799380;
extern char* D_00415CA8[2];
extern char* D_007990F0;
extern char* D_00415CB0[2];
extern char* D_0079916C;
extern char* D_00415CB8[2];
extern char* D_0079928C;
extern char* D_00415CC0[2];
extern char* D_007990C4;
extern char* D_00415CC8[2];
extern char* D_007990D4;
extern char* D_00415CD0[2];
extern char* D_00799324;
extern char* D_00415CD8[2];
extern char* D_007990CC;
extern char* D_00415CE0[2];
extern char* D_007990F8;
extern char* D_00415CE8[2];
extern char* D_007991F8;
extern char* D_00415CF0[2];
extern char* D_007993F4;
extern char* D_00415CF8[2];
extern char* D_00799158;
extern char* D_00415D00[2];
extern char* D_007991EC;
extern char* D_00415D08[2];
extern char* D_007992A4;
extern char* D_00415D10[2];
extern char* D_00799344;
extern char* D_00415D18[2];
extern char* D_0079910C;
extern char* D_00415D20[2];
extern char* D_00799354;
extern char* D_00415D28[2];
extern char* D_0079940C;
extern char* D_00415D30[2];
extern char* D_007990E0;
extern char* D_00415D38[2];
extern char* D_00799194;
extern char* D_00415D40[2];
extern char* D_0079926C;
extern char* D_00415D48[2];
extern char* D_00799174;
extern char* D_00415D50[2];
extern char* D_007991D4;
extern char* D_00415D58[2];
extern char* D_007992B0;
extern char* D_00415D60[2];
extern char* D_0079939C;
extern char* D_00415D68[2];
extern char* D_0079906C;
extern char* D_00415D70[2];
extern char* D_007993DC;
extern char* D_00415D78[2];
extern char* D_00799250;
extern char* D_00415D80[2];
extern char* D_007992F8;
extern char* D_00415D88[2];
extern char* D_007993E8;
extern char* D_00415D90[2];
extern char* D_007993E0;
extern char* D_00415D98[2];
extern char* D_007990D0;
extern char* D_00415DA0[2];
extern char* D_00799160;
extern char* D_00415DA8[2];
extern char* D_00799200;
extern char* D_00415DB0[2];
extern char* D_00799094;
extern char* D_00415DB8[2];
extern char* D_00799258;
extern char* D_00415DC0[2];
extern char* D_00799358;
extern char* D_00415DC8[2];
extern char* D_007991F0;
extern char* D_00415DD0[2];
extern char* D_007993B4;
extern char* D_00415DD8[2];
extern char* D_007990E4;
extern char* D_00415DE0[2];
extern char* D_007991D0;
extern char* D_00415DE8[2];
extern char* D_007993D0;
extern char* D_00415DF0[2];
extern char* D_0079929C;
extern char* D_00415DF8[2];
extern char* D_0079934C;
extern char* D_00415E00[2];
extern char* D_00799294;
extern char* D_00415E08[2];
extern char* D_00799318;
extern char* D_00415E10[2];
extern char* D_007992B8;
extern char* D_00415E18[2];
extern char* D_007990A4;
extern char* D_00415E20[2];
extern char* D_00799220;
extern char* D_00415E28[2];
extern char* D_00799254;
extern char* D_00415E30[2];
extern char* D_00799098;
extern char* D_00415E38[2];
extern char* D_0079920C;
extern char* D_00415E40[2];
extern char* D_00799120;
extern char* D_00415E48[2];
extern char* D_007992F4;
extern char* D_00415E50[2];
extern char* D_00799224;
extern char* D_00415E58[2];
extern char* D_007990D8;
extern char* D_00415E60[2];
extern char* D_007992F0;
extern char* D_00415E68[2];
extern char* D_00799074;
extern char* D_00415E70[2];
extern char* D_00799178;
extern char* D_00415E78[2];
extern char* D_007992DC;
extern char* D_00415E80[2];
extern char* D_00799130;
extern char* D_00415E88[2];
extern char* D_007991B0;
extern char* D_00415E90[2];
extern char* D_0079918C;
extern char* D_00415E98[2];
extern char* D_00799288;
extern char* D_00415EA0[2];
extern char* D_0079937C;
extern char* D_00415EA8[2];
extern char* D_0079935C;
extern char* D_00415EB0[2];
extern char* D_007992EC;
extern char* D_00415EB8[2];
extern char* D_00799068;
extern char* D_00415EC0[2];
extern char* D_0079917C;
extern char* D_00415EC8[2];
extern char* D_00799100;
extern char* D_00416140[2];
extern char* D_00799320;
extern char* D_00416148[2];
extern char* D_007992D8;
extern char* D_00416150[2];
extern char* D_0079914C;
extern char* D_00416158[2];
extern char* D_0079921C;
extern char* D_00415ED0[2];
extern char* D_007993A8;
extern char* D_00415ED8[2];
extern char* D_00799218;
extern char* D_00415EE0[2];
extern char* D_00799164;
extern char* D_00415EE8[2];
extern char* D_00799364;
extern char* D_00415EF0[2];
extern char* D_00799348;
extern char* D_00415EF8[2];
extern char* D_00799410;
extern char* D_00415F00[2];
extern char* D_0079907C;
extern char* D_00415F08[2];
extern char* D_00799170;
extern char* D_00415F10[2];
extern char* D_007993F0;
extern char* D_00415F18[2];
extern char* D_0079919C;
extern char* D_00415F20[2];
extern char* D_007992CC;
extern char* D_00415F28[2];
extern char* D_00799340;
extern char* D_00415F30[2];
extern char* D_007990BC;
extern char* D_00415F38[2];
extern char* D_00799168;
extern char* D_00415F40[2];
extern char* D_00799144;
extern char* D_00415F48[2];
extern char* D_007990AC;
extern char* D_00415FA4[2];
extern char* D_00799314;
extern char* D_00415FAC[2];
extern char* D_00799184;
extern char* D_00415FB4[2];
extern char* D_007992AC;
extern char* D_00415FBC[2];
extern char* D_00799398;
extern char* D_00415FC4[2];
extern char* D_00799390;
extern char* D_00415FCC[2];
extern char* D_00799128;
extern char* D_00415FD4[2];
extern char* D_0079930C;
extern char* D_00415FDC[2];
extern char* D_007993D4;
extern char* D_00416010[2];
extern char* D_0079924C;
extern char* D_00416018[2];
extern char* D_007993A4;
extern char* D_00416020[2];
extern char* D_007990C8;
extern char* D_00416028[2];
extern char* D_00799414;
extern char* D_00416030[2];
extern char* D_00799204;
extern char* D_00416038[2];
extern char* D_007992A0;
extern char* D_00416040[2];
extern char* D_00799240;
extern char* D_00416048[2];
extern char* D_007992FC;
extern char* D_00416050[2];
extern char* D_007990DC;
extern char* D_00416058[2];
extern char* D_00799298;
extern char* D_00416060[2];
extern char* D_00799328;
extern char* D_00416068[2];
extern char* D_00799280;
extern char* D_00416070[2];
extern char* D_00799370;
extern char* D_00416078[2];
extern char* D_00799368;
extern char* D_004160C0[2];
extern char* D_00799284;
extern char* D_004160C8[2];
extern char* D_00799384;
extern char* D_004160D0[2];
extern char* D_00799360;
extern char* D_004160D8[2];
extern char* D_007991C8;
extern char* D_004160E0[2];
extern char* D_00799330;
extern char* D_004160E8[2];
extern char* D_00799180;
extern char* D_004160F0[2];
extern char* D_0079927C;
extern char* D_004160F8[2];
extern char* D_0079922C;
extern char* D_00416080[2];
extern char* D_00799134;
extern char* D_00416088[2];
extern char* D_00799338;
extern char* D_00416108[2];
extern char* D_007990B8;
extern char* D_00416110[2];
extern char* D_00799214;
extern char* D_00416118[2];
extern char* D_007990C0;
extern char* D_00416120[2];
extern char* D_0079911C;
extern char* D_00416128[2];
extern char* D_00799154;
extern char* D_00416130[2];
extern char* D_00799260;
extern char* D_00416138[2];
extern char* D_007991E8;
extern char* D_00416090[2];
extern char* D_007993B0;
extern char* D_00416098[2];
extern char* D_007990A8;
extern char* D_004160A0[2];
extern char* D_00799350;
extern char* D_004160A8[2];
extern char* D_00799304;
extern char* D_004160B0[2];
extern char* D_007991A4;
extern char* D_004160B8[2];
extern s32 D_0079A160[];
extern u8 D_00799A60[];
extern s32 D_0079A170;
extern s32 D_00799440;
extern s32 D_0079A17C;
extern s32 D_0079A178;
s32 XB_STDCALL XNetGetEthernetLinkStatus(void);
extern s32 D_0079A358;
extern s32 D_0079A35C;
extern s32 D_0079A360;
extern s32 D_0079A364;
s32 xb_LiveWork_Get14(void);
extern u8* flpad_adr;
extern s32 D_0079A34C;
extern s32 D_0079A348;
extern s32 D_0079A350;
extern s32 D_0079A354;
s32 XB_STDCALL XNetQosRelease(void* qos);
void XB_FASTCALL xb_vector_TidyThunk(void* self);
void XB_FASTCALL xb_XLIVE_WORK_CLASS_QosListen(void* self);
s32 XB_FASTCALL xb_iterator_Deref(u8* self);
extern s32 D_0079A3C0;
void SsBgmFadeOut(s32 speed);
void xb_XLIVE_PAGE_CLASS_Clear(u8* page);
void XB_FASTCALL xb_XLIVE_STATMENU_CLASS_Init(u8* self);
s32 XB_FASTCALL xb_XLIVE_STATMENU_CLASS_StepTimer(u8* self);
extern u8 D_0079A472[];
extern u8 D_0079A418[];
extern u8 D_0079A470[];
s32 XB_STDCALL XOnlineStartup(s32 params);
extern void (*D_0079AF08)(void);
extern void (*D_0079AF04)(void);
extern s32 D_007A7BC4;
extern s32 D_007A7BC8;
extern u8 D_007A7BCC;
extern u8 D_007A7BCD;
extern u8 D_007A7BCE;
extern u8 D_007A7BCF;
extern u16 D_007A7BD0;
extern u16 D_007A7BD2;
extern u16 D_0079B714;
extern u8 D_007A7A1C;
extern s32 D_007A7A18;
extern u16 D_007A7A5A;
extern s8 D_007A7A0A;
extern u8 D_007A7600[];
s32 xb_NetSync_Receive(s32 sock, u8* buf, s16 len);
extern s16 D_007A7A38;
s32 XB_STDCALL send(s32 s, const void* buf, s32 len, s32 flags);
s32 XB_STDCALL WSAGetLastError(void);
extern u8 D_002B8708[];
void XB_FASTCALL xb_XLIVE_WORKBASE_CLASS_ctor(void* self);
void XB_FASTCALL xb_XLIVE_WORKBASE_CLASS_dtor(void* self);
extern u8 D_007A6460[];
extern s32 D_007A1390;
extern s32 D_007A1394;
extern u8 D_007C5878;
extern u8 D_007BD5E8[];
extern u8 D_007BD614[];
void sub_001206D8(void);
void sub_0004AFFA(void);
s32 xb_xlive_select_Init(void);
void xb_xlive_SetNetPad(s8 pl);
s32 xb_xlive_GetLocalPad(s8 pl, u32* out);
extern s32 D_007A14A0;
extern s32 D_007A14A4;
extern s32 D_007A156C;
extern s32 D_007A1574;
extern s32 D_007A1578;
extern s32 D_007A15CC;
extern s32** D_0043771C[];
void xb_PrintSetPos(s16 x, s16 y);
void xb_PrintString(const char* s);
void SE_selected(void);
void SE_cursor_move(void);
s32 load_it_use_any_key2(s32 ix, void* out, s32* size, s32 a, s32 b);
extern s32 D_0079B834;
s32 flLogOut(const char* fmt, ...);
extern char D_002B877C[];
extern s32 D_0079B828;
extern s32 D_0079B82C;
extern s32 D_0079B830;
extern s32 D_00795C10;
s32 XB_STDCALL DirectSoundCreate(void* guid, s32* ds, void* outer);
s32 XB_STDCALL DirectSoundUseLightHRTF(void);
s32 XB_STDCALL xb_DownloadEffectsImage(s32 dsound, s32 a, s32 b, s32* loc, void* out);
extern u8 D_007A1808;
s32 xb_NetSync_BuildRequest(s32 sock, s8 pl);
extern s32 D_007A7BC0;
extern u8 D_007A7A0C;

/* The NetSync message queue: length-prefixed messages in D_0079AF10,
 * read at D_00418944 and written at D_00418948; once the write end
 * reaches the end of the buffer, writing wraps to its start and
 * D_0079B710 marks how far. D_0079B714 counts the messages. */
extern u8 D_0079AF10[0x800];
extern u8* D_0079B710;
extern u8* D_00418944;
extern u8* D_00418948;
extern s32 D_007A7A80;
extern u8* D_007A7A84;
typedef struct {
    u32 fd_count;
    s32 fd_array[64];
} XB_FD_SET;
typedef struct {
    s32 tv_sec;
    s32 tv_usec;
} XB_TIMEVAL;
extern XB_FD_SET D_0079B718;
extern XB_TIMEVAL D_0079B81C;
s32 XB_STDCALL select(s32 nfds, XB_FD_SET* r, XB_FD_SET* w, XB_FD_SET* e, const XB_TIMEVAL* t);
s32 XB_STDCALL __WSAFDIsSet(s32 s, XB_FD_SET* set);
s32 XB_STDCALL recv(s32 s, void* buf, s32 len, s32 flags);
s32 xb_Get7C5878(void);
s32 xb_GetPlayerSetting(s32 i);
s32 xb_GetSettingByte(s32 i);
s32 xb_NetSync_ParsePacket(s32 sock, u8 pl, u8* msg);
s32 xb_NetSync_GetFlag2(void);
void xb_NetSync_SetFlag2(s32 v);
s32 xb_MsgQueuePush(u8* m);
u8* xb_MsgQueuePop(void);

/* Each console's settings as xb_NetSync_BuildRequest sends them: a flag
 * (0xFF until received), the 20 character colour switches of
 * save_w[1].PL_Color[0] and the 8 button bytes of a Pad_Infor. */
typedef struct {
    u8 flag;
    u8 color[20];
    u8 shot[8];
} XB_NSREC;
extern XB_NSREC D_007A6480[2];
extern u8 save_w[];
extern u8 permission_player[];
s32 xb_xlive_font_NextLine(void);
void xb_xlive_font_DrawQueued(void);
s32 xb_GetOnlineFlagThunk(void);
void XB_FASTCALL xb_XLIVE_STARTMENU_CLASS_StatUpdate(u8* self);
s32 xb_LiveWork_Get2330(void);
void XB_FASTCALL xb_XLIVE_STARTMENU_CLASS_Update(u8* self);
f32 xb_LiveTimer_Elapsed(void);
void xb_LiveTimer_Stop(void);
extern void (*D_00436F0C[])(void* w);

/* The save state machine (D_007A14A0): +0 and +4 its steps, +0x14 the
 * slot, +0x24 the result, +0xBC the data's size, +0xC4 a flag, +0xCC the
 * state (D_00436F0C), +0xD0 the buffer, +0xD4 the kind, +0xD8 the slot,
 * +0xE0 a flag. A kind's descriptor (D_00436F00): the save's name, the
 * image copied into it, the file and its size, the replay's second file
 * (sub.bin) with its data and size, the blocks a save takes, and the
 * number of slots (0: one save, named without a number). */
typedef struct {
    const char* title;
    const char* image;
    s32 r8;
    s32 rC;
    const char* file;
    s32 r14;
    u32 size;
    const char* sub;
    u8* subdata;
    u32 subsize;
    s32 blocks;
    s32 slots;
    s32 r30;
    s32 r34;
} XB_SAVEDESC;
extern XB_SAVEDESC* D_00436F00[3];
extern u16 D_007A13A0[0x40];
typedef struct {
    u32 lo;
    u32 hi;
} XB_U64;
typedef struct {
    u32 attr;
    u32 ctime[2];
    u32 atime[2];
    u32 wtime[2];
    u32 serial;
    u32 sizehi;
    u32 sizelo;
    u32 links;
    u32 idhi;
    u32 idlo;
} XB_FILEINFO;
typedef struct {
    u16 year;
    u16 month;
    u16 weekday;
    u16 day;
    u16 hour;
    u16 minute;
    u16 second;
    u16 ms;
} XB_SYSTIME;
u32 XB_STDCALL XCreateSaveGame(const char* root, const u16* name, u32 disp, u32 flags, char* path, u32 size);
s32 XB_STDCALL CreateFileA(const char* name, u32 access, u32 share, void* sec, u32 disp, u32 flags, s32 tmpl);
s32 XB_STDCALL CloseHandle(s32 h);
s32 XB_STDCALL ReadFile(s32 h, void* buf, u32 n, u32* got, void* ov);
s32 XB_STDCALL WriteFile(s32 h, const void* buf, u32 n, u32* put, void* ov);
u32 XB_STDCALL GetFileSize(s32 h, u32* hi);
s32 XB_STDCALL GetFileInformationByHandle(s32 h, XB_FILEINFO* info);
s32 XB_STDCALL FileTimeToLocalFileTime(const u32* ft, u32* local);
s32 XB_STDCALL FileTimeToSystemTime(const u32* ft, XB_SYSTIME* st);
s32 XB_STDCALL GetDiskFreeSpaceExA(const char* root, XB_U64* free, XB_U64* total, XB_U64* totalfree);
s32 XB_STDCALL CopyFileA(const char* from, const char* to, s32 fail);
u32 XB_STDCALL GetLastError(void);
void* XB_STDCALL XPhysicalAlloc(u32 size, u32 hi, u32 align, u32 prot);
void XB_STDCALL XPhysicalFree(void* p);
s32 XB_STDCALL XCalculateSignatureBegin(u32 flags);
u32 XB_STDCALL XCalculateSignatureUpdate(s32 h, const void* data, u32 n);
u32 XB_STDCALL XCalculateSignatureEnd(s32 h, void* sig);
s32 ADXF_GetStat(s32 adxf);
void ADXF_Close(s32 adxf);
void xb_ShowDiskReadError(void);
extern u8 D_007A1618[0x1E8];
void xb_memset_bytes(void* p, s32 v, s32 n);
void sub_0004384A();
/* the CRT's, with the Xbox's 16-bit wide characters */
u32 mbstowcs(u16* dst, const char* src, u32 n);

/* The state machine's results (+0x24). */
#define XB_SAVE_FAILED -0x100
#define XB_SAVE_NOFILE -0xFD

extern void (*D_00437F84[])(void* w);
void sub_0016AA60(void);
void sub_0016AA70(void);
void xb_PersistDisplay(void);
u32 XB_STDCALL XLaunchNewImageA(const char* path, void* data);
extern u8 D_00798B80[];
u8* xb_FindOnlineObj(s32 id);
void xb_OnlineObj_SetFlag(s32 id, u8 v);
u8 xb_OnlineObj_IsDone(s32 id);
s32 xb_NetSync_Send(s32 sock, const void* buf, s16 len);
void xb_SeSelectedThunk(void);

void xb_StopAllSeSlots(void) {
    u32 i;

    for (i = 0; i < 48; i++) {
        if (D_00797128[i].cue && D_00797128[i].state != 1) {
            IXACTSoundSource__StopSoundCues(D_00797128[i].x);

            if (IXACTSoundBank__Stop(D_00797128[i].bank, -1, 2, D_00797128[i].cue) == 0) {
                D_00797128[i].state = 1;
            }
        }
    }
}

void xb_StopSeById(s16 id) {
    u32 i;

    for (i = 0; i < 48; i++) {
        if (D_00797128[i].cue && D_00797128[i].state != 1 && D_00797128[i].id == id) {
            IXACTSoundSource__StopSoundCues(D_00797128[i].x);

            if (IXACTSoundBank__Stop(D_00797128[i].bank, -1, 2, D_00797128[i].cue) == 0) {
                D_00797128[i].state = 1;
            }
        }
    }
}

s32 xb_StopSeByGroup(s32 a, s32 b, u8 grp, u8 prio) {
    u32 i;

    (void)a;
    (void)b;

    for (i = 0; i < 48; i++) {
        if (D_00797128[i].cue && D_00797128[i].state != 1 && D_00797128[i].grp == grp && D_00797128[i].prio <= prio) {
            IXACTSoundSource__StopSoundCues(D_00797128[i].x);

            if (IXACTSoundBank__Stop(D_00797128[i].bank, -1, 2, D_00797128[i].cue)) {
                return 0;
            }

            D_00797128[i].state = 1;
        }
    }

    return 1;
}

void xb_XactFrame(void) {
    if (D_00797BA8 != 0) {
        xb_XactPollNotifications();
        XACTEngineDoWork();
    }
}

s32 XB_FASTCALL xb_LiveObj_GetHandle50(u8* self) {
    return *(s32*)(self + 0x50);
}

u8* XB_FASTCALL xb_LiveObj_Set2(u8* self, s32 edx, u8 v) {
    (void)edx;
    self[2] = v;
    return self;
}

s32 xb_GetLiveObjSize(void) {
    return 0x68;
}

s32 XB_FASTCALL xb_LiveObj_IsValid(u8* self) {
    return *(s32*)(self + 4) != 0;
}

s32 XB_FASTCALL xb_LiveObj_Call2b(u8* self, s32 edx, s32 a, s32 b) {
    (void)edx;
    return IXHVEngine__SetVoiceMask(*(s32*)(self + 4), a, b);
}

s32 XB_FASTCALL xb_LiveObj_Call2(u8* self, s32 edx, s32 a, s32 b) {
    (void)edx;
    return IXHVEngine__SetProcessingMode(*(s32*)(self + 4), a, b);
}

u8* XB_FASTCALL xb_LiveObj_Get8(u8* self) {
    return self + 0x8;
}

u8* XB_FASTCALL xb_LiveWork_Get2408(u8* self) {
    return self + 0x2408;
}

void xb_LiveObj_Thunk(void) {
    xb_deque_IterDeref();
}

s32 XB_FASTCALL xb_LiveObj_GetResult58(u8* self) {
    xb_LiveObj_Update(self);
    return *(s32*)(self + 0x58);
}

void XB_FASTCALL xb_LiveObj_StartThread(u8* self) {
    D_00797F18 = 0;
    D_00797F18 = CreateThread(0, 0, xb_LiveVoice_Thread, 0, 4, 0);
    SetThreadPriority(D_00797F18, -2);
    SetThreadPriorityBoost(D_00797F18, 0);
    ResumeThread(D_00797F18);
    CXBStopWatch_StartZero(self + 0x70);
    D_00218DC8(D_00797EFC);
}

void XB_FASTCALL xb_CONNECT_USER_CLASS_UpdateIfActive(u8* self) {
    if (self[0x50]) {
        xb_WINSTR_CLASS_Update(self);
    }
}

void XB_FASTCALL xb_CONNECT_USER_CLASS_SetActive(u8* self, s32 edx, u8 on) {
    (void)edx;
    self[0x50] = on;
}

void XB_FASTCALL xb_CONNECT_USER_CLASS_Release(s32* self) {
    xb_WINSTR_CLASS_Release(self);
}

u8* XB_FASTCALL xb_WINSTR_CLASS_ctor(u8* self) {
    *(s32*)(self + 8) = -1;
    *(s32*)(self + 0x1C) = 0;
    *(s32*)(self + 0x20) = 0;
    *(s32*)(self + 0x24) = 0;
    *(u32*)(self + 0x28) = 0xA0000000;
    *(f32*)(self + 0x2C) = 0.0f;
    return self;
}

s32 xb_xlive_SetObjFlag58(s32 id, s32 on) {
    u8* o = xb_FindOnlineObj(id);

    if (o == 0) {
        return -1;
    }

    o[0x58] = on >= 1;

    if (o[0x58]) {
        *(s32*)(o + 0x34) = *(s32*)(o + 0x2C);
    }

    return 1;
}

s32 xb_xlive_ResetObj(s32 id, s32 keep) {
    u8* o = xb_FindOnlineObj(id);

    if (o == 0) {
        return -1;
    }

    if (keep == 0) {
        *(f32*)(o + 0x1C) = *(f32*)(o + 0xC);
        o[1] = 0;
        *(f32*)(o + 0x20) = *(f32*)(o + 0x10);
        *(s32*)(o + 0x30) = *(s32*)(o + 0x2C);
        *(s32*)(o + 0x34) = *(s32*)(o + 0x2C);
        *(f32*)(o + 0x24) = *(f32*)(o + 0x14);
        *(f32*)(o + 0x28) = *(f32*)(o + 0x18);
    }

    return 1;
}

void xb_xlive_disp_DrawMessageDefault(s32 a, s32 b, s32 c) {
    xb_xlive_disp_DrawMessage(a, b, c, 0.6f, 1.0f, 0);
}

void xb_xlive_disp_DrawTextAt(f32 x, f32 y, s32 text) {
    xb_xlive_disp_DrawTextBox(x, y, 0.6f, text, 1.0f, 0);
}

void xb_xlive_font_Clear(void) {
    u8* f = D_00798B78;
    s32 i;

    for (i = 0; i < 0xF40; i++) {
        ((s32*)(f + 0x230))[i] = 0xFF00FF;
    }

    *(s32*)(f + 0x3F30) = 0;
    *(s32*)(f + 0x44) = 0;
    *(s32*)(f + 0x48) = 0;
}

void xb_xlive_font_SetPage(s32 page) {
    *(s32*)(D_00798B78 + 0xC) = page;
}

void xb_xlive_font_Flush(void) {
    *(s32*)(D_00798B78 + 0x40) = -1;

    if (xb_xlive_font_NextLine()) {
        xb_xlive_font_Clear();
        xb_xlive_font_NextLine();
    }

    xb_xlive_font_DrawQueued();
}

void xb_LaunchDefaultXbe(void) {
    xb_PersistDisplay();
    XLaunchNewImageA("D:\\default.xbe", D_00798B80);
}

void XB_FASTCALL xb_XLIVE_FRIEND_CLASS_SetMode(u8* self, s32 edx, s32 mode) {
    (void)edx;

    switch (mode) {
    case 0:
    case 1:
    case 6:
        xb_SeSelectedThunk();
        *(s32*)(self + 0x8B0) = *(s32*)(self + 0x8B4);
        break;
    }
}

void XB_FASTCALL xb_XLIVE_FRIEND_CLASS_SetName(u8* self, s32 edx, const void* name) {
    (void)edx;
    lstrcpynW(self + 0x8D8, name, 0x40);
    CXBStopWatch_StartZero(self + 0x870);
}

s32 XB_FASTCALL xb_XLIVE_FRIEND_CLASS_RequestFriend(u8* self) {
    return XOnlineFriendsRequest(*(s32*)(D_00798CAC + 0x14), *(XB_REQ12*)(self + 0x960));
}

s32 XB_FASTCALL xb_XLIVE_FRIEND_CLASS_SendFriendAction(u8* self, s32 edx, s32 a, s32 b) {
    (void)edx;
    return XOnlineFriendsRequestEx(*(s32*)(D_00798CAC + 0x14), *(XB_REQ12*)(self + 0x960), a, 0, b);
}

s32 XB_FASTCALL xb_XLIVE_FRIEND_CLASS_OpenWindow(u8* self, s32 edx, s32 i, f32 a, f32 b, f32 c, f32 d) {
    s32* h = (s32*)(self + i * 4 + 0xA8C);

    (void)edx;

    if (*h == -1) {
        *h = xb_xlive_disp_DrawRectF(a, b, c, d, 1.2f);
        xb_xlive_disp_SetObj0C(*h, 0xFF000000);
        xb_OnlineObj_Move(*h);
    }

    return (s8)xb_OnlineObj_IsDone(*h);
}

s32 XB_FASTCALL xb_XLIVE_FRIEND_CLASS_UpdateWindows(u8* self) {
    s32 done = 1;
    s32 any = 0;
    s32* w = (s32*)(self + 0xA8C);
    s32 i;

    for (i = 0; i < 2; i++, w++) {
        if (*w != -1) {
            any = 1;
            done &= (s8)xb_OnlineObj_IsDone(*w);
        }
    }

    return any ? done : 0;
}

void XB_FASTCALL xb_XLIVE_FRIEND_CLASS_CloseWindow(u8* self, s32 edx, s32 i) {
    s32* w = (s32*)(self + i * 4 + 0xA8C);

    (void)edx;

    if (*w != -1) {
        xb_xlive_friend_Release(*w);
        *w = -1;
    }
}

void XB_FASTCALL xb_XLIVE_FRIEND_CLASS_FadeWindow(u8* self, s32 edx, s32 i) {
    s32 id = *(s32*)(self + i * 4 + 0xA8C);

    (void)edx;

    if (id != -1) {
        xb_OnlineObj_Fade(id);
    }
}

void XB_FASTCALL xb_XLIVE_WORK_CLASS_SetState3(u8* self) {
    *(s32*)(self + 0x2364) = 3;
    *(s32*)(self + 0x2370) = 0;
    *(s32*)(self + 0x236C) = 0;
    *(s32*)(self + 0x2368) = 0;
}

void XB_FASTCALL xb_XLIVE_WORK_CLASS_SetState4(u8* self) {
    *(s32*)(self + 0x2364) = 4;
    *(s32*)(self + 0x2370) = 0;
    *(s32*)(self + 0x236C) = 0;
    *(s32*)(self + 0x2368) = 0;
}

void XB_FASTCALL xb_XLIVE_WORK_CLASS_ReleaseWindows(u8* self) {
    xb_xlive_friend_Release(*(s32*)(self + 0x138));
    xb_xlive_friend_Release(*(s32*)(self + 0x140));
}

s32 XB_FASTCALL xb_XLIVE_WORK_CLASS_CheckPad(u8* self) {
    s32* c;

    if (xb_LivePadTrigger(0xF)) {
        c = (s32*)(self + 0x2CC);

        if (xb_LivePadTrigger(D_003F8328[*c])) {
            (*c)++;
        } else {
            *c = 0;
        }
    }

    return D_003F8328[*(s32*)(self + 0x2CC)] == -1;
}

void xb_xlive_match_ClearRecordWork(void) {
    memset(D_0079902C, 0, 0x30);
}

void* xb_GetMatchInfo(void) {
    return D_00798EA8;
}

void xb_xlive_match_OpenWindow(u8 kind, u8* w) {
    f32* r = (f32*)(D_002B53F0 + kind * 16);

    if (w[0] == 0) {
        w[0] = 1;
        w[1] = 0;
        *(s32*)(w + 4) = xb_xlive_disp_DrawRectFloat(r[0], r[1], r[2], r[3]);
        xb_OnlineObj_Move(*(s32*)(w + 4));
    }
}

void xb_xlive_match_ReopenWindow(s32 a, u8* w) {
    if (w[0]) {
        xb_xlive_friend_Release(*(s32*)(w + 4));
        w[1] = 0;
        w[0] = 0;
    }

    xb_xlive_match_OpenWindow(a, w);
}

/* xb_xlive_match_AreWindowsDone 0x10F270: 1 once an open window has
 * finished moving (marked active), or when the first is not open. */
s32 xb_xlive_match_AreWindowsDone(void) {
    XB_MATCHINFO* info = xb_GetMatchInfo();
    s32 i;

    for (i = 0; i < 4; i++) {
        if (info->win[i].used != 0 && xb_OnlineObj_IsDone(info->win[i].id)) {
            info->win[i].active = 1;
            return 1;
        }
    }

    return info->win[0].used == 0;
}

void xb_xlive_match_FadeWindow(void) {
    XB_MATCHINFO* info = xb_GetMatchInfo();
    s32 i;

    for (i = 0; i < 4; i++) {
        if (info->win[i].used != 0) {
            info->win[i].active = 0;
            xb_OnlineObj_Fade(info->win[i].id);
        }
    }
}

void xb_xlive_match_ReleaseWindow(void) {
    XB_MATCHINFO* info = xb_GetMatchInfo();
    s32 i;

    for (i = 0; i < 4; i++) {
        if (info->win[i].used != 0) {
            info->win[i].used = 0;
            info->win[i].active = 0;
            xb_xlive_friend_Release(info->win[i].id);
        }
    }
}

s32 xb_xlive_match_IsWindowDone(u8* w) {
    if (w[0] == 0) {
        return -1;
    }

    if (xb_OnlineObj_IsDone(*(s32*)(w + 4))) {
        w[1] = 1;
        return 1;
    }

    return 0;
}

s32 xb_GetLiveLanguage(void) {
    return D_0079941C;
}

/* xb_SetupLiveLanguage 0x10F2C1: picks the Live text language, Japanese
 * only on a Japanese console in the Japanese region, and points every
 * Live string at that language's copy. The text records of the two
 * record tables keep both copies and a pointer at their end (+0x208 of a
 * 0x20C record, +0x104 of a 0x108 record) to the current one. */
void xb_SetupLiveLanguage(void) {
    s32 lang = XGetLanguage();
    s32 region = XGetGameRegion();
    s32 en;
    s32 sel;
    s32 i;
    s32 j;
    u8* p;

    if (lang == 2 && region == lang) {
        D_007993AC = D_00418574;
        D_0079923C = D_00418590;
        D_00799148 = D_004184D8;
        en = 0;
        sel = 0;
        D_0079941C = 0;
    } else {
        D_007993AC = D_0041847C;
        D_0079923C = D_00418498;
        D_00799148 = D_004183E0;
        en = 1;
        sel = 1;
        D_0079941C = 1;
    }

    for (i = 0; i < D_0041597C; i++) {
        p = D_0041592C[i];

        for (j = 0; j < D_00415954[i]; j++) {
            switch (sel) {
            case 0:
                *(u8**)(p + 0x208) = p + 8;
                break;
            case 1:
                *(u8**)(p + 0x208) = p + 0x108;
                break;
            }

            p += 0x20C;
        }
    }

    for (i = 0; i < D_004183D8; i++) {
        p = D_004183C8[i];

        for (j = 0; j < D_004183D0[i]; j++) {
            switch (sel) {
            case 0:
                *(u8**)(p + 0x104) = p + 4;
                break;
            case 1:
                *(u8**)(p + 0x104) = p + 0x84;
                break;
            }

            p += 0x108;
        }
    }

    D_00799400 = D_00415980[en];
    D_00799374 = D_00415988[en];
    D_0079909C = D_00415990[en];
    D_007991B8 = D_00415998[en];
    D_007992E8 = D_004159A0[en];
    D_00799408 = D_004159A8[en];
    D_0079936C = D_004159B0[en];
    D_007991FC = D_004159B8[en];
    D_00799118 = D_004159C0[en];
    D_0079913C = D_004159C8[en];
    D_007992E4 = D_004159D0[en];
    D_00799310 = D_004159D8[en];
    D_00799080 = D_004159E0[en];
    D_00799334 = D_004159E8[en];
    D_00799270 = D_004159F0[en];
    D_007991C0 = D_004159F8[en];
    D_00799060 = D_00415A00[en];
    D_00799234 = D_00415A08[en];
    D_00799278 = D_00415A10[en];
    D_0079925C = D_00415A18[en];
    D_007993B8 = D_00415A20[en];
    D_00799210 = D_00415A28[en];
    D_007992C8 = D_00415A30[en];
    D_007992A8 = D_00415A38[en];
    D_0079915C = D_00415A40[en];
    D_00799104 = D_00415A48[en];
    D_007991A0 = D_00415A50[en];
    D_007993C8 = D_00415A58[en];
    D_007990EC = D_00415A60[en];
    D_007992C4 = D_00415A68[en];
    D_00799090 = D_00415A70[en];
    D_00799114 = D_00415A78[en];
    D_00799124 = D_00415A80[en];
    D_007991E0 = D_00415A88[en];
    D_007990B4 = D_00415A90[en];
    D_00799188 = D_00415A98[en];
    D_007993BC = D_00415AA0[en];
    D_0079938C = D_00415AA8[en];
    D_00799290 = D_00415AB0[en];
    D_00799378 = D_00415AB8[en];
    D_007992C0 = D_00415AC0[en];
    D_00799140 = D_00415AC8[en];
    D_00799088 = D_00415AD0[en];
    D_00799300 = D_00415AD8[en];
    D_007993C4 = D_00415AE0[en];
    D_00799268 = D_00415AE8[en];
    D_00799228 = D_00415AF0[en];
    D_007991E4 = D_00415AF8[en];
    D_007992D4 = D_00415B00[en];
    D_00799264 = D_00415B08[en];
    D_00799064 = D_00415B10[en];
    D_0079912C = D_00415B18[en];
    D_007990E8 = D_00415B20[en];
    D_00799244 = D_00415B28[en];
    D_007992BC = D_00415B30[en];
    D_00799198 = D_00415B38[en];
    D_007991DC = D_00415B40[en];
    D_007993A0 = D_00415B48[en];
    D_00799070 = D_00415B50[en];
    D_007991D8 = D_00415B58[en];
    D_007992B4 = D_00415B60[en];
    D_00799110 = D_00415B68[en];
    D_007991CC = D_00415B70[en];
    D_00799394 = D_00415B78[en];
    D_0079908C = D_00415B80[en];
    D_007991C4 = D_00415B88[en];
    D_00799238 = D_00415B90[en];
    D_007990FC = D_00415B98[en];
    D_007991B4 = D_00415BA0[en];
    D_007992E0 = D_00415BA8[en];
    D_00799404 = D_00415BB0[en];
    D_007991AC = D_00415BB8[en];
    D_00799230 = D_00415BC0[en];
    D_007993FC = D_00415BC8[en];
    D_00799108 = D_00415BD0[en];
    D_00799190 = D_00415BD8[en];
    D_007993F8 = D_00415BE0[en];
    D_00799208 = D_00415BE8[en];
    D_0079932C = D_00415BF0[en];
    D_007993D8 = D_00415BF8[en];
    D_00799138 = D_00415C00[en];
    D_00799248 = D_00415C08[en];
    D_0079933C = D_00415C10[en];
    D_007993E4 = D_00415C18[en];
    D_00799150 = D_00415C20[en];
    D_00799308 = D_00415C28[en];
    D_007990A0 = D_00415C30[en];
    D_007991BC = D_00415C38[en];
    D_007992D0 = D_00415C40[en];
    D_00799388 = D_00415C48[en];
    D_007990B0 = D_00415C50[en];
    D_00799274 = D_00415C58[en];
    D_007993C0 = D_00415C60[en];
    D_00799084 = D_00415C68[en];
    D_007991A8 = D_00415C70[en];
    D_00799078 = D_00415C78[en];
    D_007993EC = D_00415C80[en];
    D_007991F4 = D_00415C88[en];
    D_0079931C = D_00415C90[en];
    D_007993CC = D_00415C98[en];
    D_007990F4 = D_00415CA0[en];
    D_00799380 = D_00415CA8[en];
    D_007990F0 = D_00415CB0[en];
    D_0079916C = D_00415CB8[en];
    D_0079928C = D_00415CC0[en];
    D_007990C4 = D_00415CC8[en];
    D_007990D4 = D_00415CD0[en];
    D_00799324 = D_00415CD8[en];
    D_007990CC = D_00415CE0[en];
    D_007990F8 = D_00415CE8[en];
    D_007991F8 = D_00415CF0[en];
    D_007993F4 = D_00415CF8[en];
    D_00799158 = D_00415D00[en];
    D_007991EC = D_00415D08[en];
    D_007992A4 = D_00415D10[en];
    D_00799344 = D_00415D18[en];
    D_0079910C = D_00415D20[en];
    D_00799354 = D_00415D28[en];
    D_0079940C = D_00415D30[en];
    D_007990E0 = D_00415D38[en];
    D_00799194 = D_00415D40[en];
    D_0079926C = D_00415D48[en];
    D_00799174 = D_00415D50[en];
    D_007991D4 = D_00415D58[en];
    D_007992B0 = D_00415D60[en];
    D_0079939C = D_00415D68[en];
    D_0079906C = D_00415D70[en];
    D_007993DC = D_00415D78[en];
    D_00799250 = D_00415D80[en];
    D_007992F8 = D_00415D88[en];
    D_007993E8 = D_00415D90[en];
    D_007993E0 = D_00415D98[en];
    D_007990D0 = D_00415DA0[en];
    D_00799160 = D_00415DA8[en];
    D_00799200 = D_00415DB0[en];
    D_00799094 = D_00415DB8[en];
    D_00799258 = D_00415DC0[en];
    D_00799358 = D_00415DC8[en];
    D_007991F0 = D_00415DD0[en];
    D_007993B4 = D_00415DD8[en];
    D_007990E4 = D_00415DE0[en];
    D_007991D0 = D_00415DE8[en];
    D_007993D0 = D_00415DF0[en];
    D_0079929C = D_00415DF8[en];
    D_0079934C = D_00415E00[en];
    D_00799294 = D_00415E08[en];
    D_00799318 = D_00415E10[en];
    D_007992B8 = D_00415E18[en];
    D_007990A4 = D_00415E20[en];
    D_00799220 = D_00415E28[en];
    D_00799254 = D_00415E30[en];
    D_00799098 = D_00415E38[en];
    D_0079920C = D_00415E40[en];
    D_00799120 = D_00415E48[en];
    D_007992F4 = D_00415E50[en];
    D_00799224 = D_00415E58[en];
    D_007990D8 = D_00415E60[en];
    D_007992F0 = D_00415E68[en];
    D_00799074 = D_00415E70[en];
    D_00799178 = D_00415E78[en];
    D_007992DC = D_00415E80[en];
    D_00799130 = D_00415E88[en];
    D_007991B0 = D_00415E90[en];
    D_0079918C = D_00415E98[en];
    D_00799288 = D_00415EA0[en];
    D_0079937C = D_00415EA8[en];
    D_0079935C = D_00415EB0[en];
    D_007992EC = D_00415EB8[en];
    D_00799068 = D_00415EC0[en];
    D_0079917C = D_00415EC8[en];
    D_00799100 = D_00416140[en];
    D_00799320 = D_00416148[en];
    D_007992D8 = D_00416150[en];
    D_0079914C = D_00416158[en];
    D_0079921C = D_00415ED0[en];
    D_007993A8 = D_00415ED8[en];
    D_00799218 = D_00415EE0[en];
    D_00799164 = D_00415EE8[en];
    D_00799364 = D_00415EF0[en];
    D_00799348 = D_00415EF8[en];
    D_00799410 = D_00415F00[en];
    D_0079907C = D_00415F08[en];
    D_00799170 = D_00415F10[en];
    D_007993F0 = D_00415F18[en];
    D_0079919C = D_00415F20[en];
    D_007992CC = D_00415F28[en];
    D_00799340 = D_00415F30[en];
    D_007990BC = D_00415F38[en];
    D_00799168 = D_00415F40[en];
    D_00799144 = D_00415F48[en];
    D_007990AC = D_00415FA4[en];
    D_00799314 = D_00415FAC[en];
    D_00799184 = D_00415FB4[en];
    D_007992AC = D_00415FBC[en];
    D_00799398 = D_00415FC4[en];
    D_00799390 = D_00415FCC[en];
    D_00799128 = D_00415FD4[en];
    D_0079930C = D_00415FDC[en];
    D_007993D4 = D_00416010[en];
    D_0079924C = D_00416018[en];
    D_007993A4 = D_00416020[en];
    D_007990C8 = D_00416028[en];
    D_00799414 = D_00416030[en];
    D_00799204 = D_00416038[en];
    D_007992A0 = D_00416040[en];
    D_00799240 = D_00416048[en];
    D_007992FC = D_00416050[en];
    D_007990DC = D_00416058[en];
    D_00799298 = D_00416060[en];
    D_00799328 = D_00416068[en];
    D_00799280 = D_00416070[en];
    D_00799370 = D_00416078[en];
    D_00799368 = D_004160C0[en];
    D_00799284 = D_004160C8[en];
    D_00799384 = D_004160D0[en];
    D_00799360 = D_004160D8[en];
    D_007991C8 = D_004160E0[en];
    D_00799330 = D_004160E8[en];
    D_00799180 = D_004160F0[en];
    D_0079927C = D_004160F8[en];
    D_0079922C = D_00416080[en];
    D_00799134 = D_00416088[en];
    D_00799338 = D_00416108[en];
    D_007990B8 = D_00416110[en];
    D_00799214 = D_00416118[en];
    D_007990C0 = D_00416120[en];
    D_0079911C = D_00416128[en];
    D_00799154 = D_00416130[en];
    D_00799260 = D_00416138[en];
    D_007991E8 = D_00416090[en];
    D_007993B0 = D_00416098[en];
    D_007990A8 = D_004160A0[en];
    D_00799350 = D_004160A8[en];
    D_00799304 = D_004160B0[en];
    D_007991A4 = D_004160B8[en];
}

void xb_SetLiveCallback(s32 i, s32 cb) {
    D_0079A160[i] = cb;
}

u8* xb_GetOnlinePlayer(s32 i) {
    if (i >= 0 && i < 2) {
        return D_00799A60 + i * 0x300;
    }

    return 0;
}

s32 xb_GetOnlineFlag(void) {
    return D_0079A170;
}

s32 xb_GetOnlineByte799440(void) {
    return D_00799440;
}

void xb_ResetLinkPollTimer(void) {
    D_0079A17C = 999;
}

void xb_PollEthernetLink(void) {
    if (++D_0079A17C > 30) {
        D_0079A17C = 0;
        D_0079A178 = XNetGetEthernetLinkStatus() & 1;
    }
}

void xb_ClearLivePadState(void) {
    D_0079A358 = 0;
    D_0079A35C = 0;
    D_0079A360 = 0;
    D_0079A364 = 0;
}

void xb_LivePadHeld(void) {
    if (xb_LiveTimer_Elapsed() > 0.15f || *(s16*)(flpad_adr + xb_LiveWork_Get14() * 0x88 + 0x30) < 0x28) {
        xb_LiveTimer_Stop();
        xb_ClearLivePadState();
    }
}

s32 xb_LivePadActive(void) {
    return *(s32*)(xb_LiveWork_Get14() * 0x88 + flpad_adr + 0x10) != 0;
}

s32 xb_LivePadConnected(void) {
    if (*(u16*)(xb_LiveWork_Get14() * 0x88 + flpad_adr + 2) == 0 ||
        *(u16*)(xb_LiveWork_Get14() * 0x88 + flpad_adr + 2) == 0x8000) {
        return 0;
    }

    return 1;
}

void xb_ClearLivePadLatch(void) {
    D_0079A34C = 0;
    D_0079A348 = 0;
}

void xb_LivePadLatch(s32 mask) {
    D_0079A348 |= *(s32*)(xb_LiveWork_Get14() * 0x88 + flpad_adr + 0x10) & mask;
    D_0079A34C |= *(s32*)(xb_LiveWork_Get14() * 0x88 + flpad_adr + 0xC) & mask;
}

s32 xb_LivePadButtons(s32 mask) {
    return *(s32*)(xb_LiveWork_Get14() * 0x88 + flpad_adr + 8) & mask;
}

s32 xb_GetOnlineModeArg(void) {
    return D_0079A350;
}

void xb_SetOnlineModeArgs(s32 a, s32 b) {
    D_0079A350 = a;
    D_0079A354 = b;
}

s32 xb_GetOnlineModeArg2(void) {
    return D_0079A354;
}

void xb_LiveWork_InitTaskThunk(void) {
    xb_ClearLivePadLatch();
}

s32 xb_LivePadPressedConfirm(void) {
    xb_LivePadLatch(0x4020);
    return *(s32*)(xb_LiveWork_Get14() * 0x88 + flpad_adr + 0x10) & 0x4020;
}

s32 xb_LivePadPressed(s32 mask) {
    xb_LivePadLatch(mask);

    if ((*(s32*)(xb_LiveWork_Get14() * 0x88 + flpad_adr + 0x10) & mask) &&
        !(*(s32*)(xb_LiveWork_Get14() * 0x88 + flpad_adr + 0xC) & mask)) {
        return 1;
    }

    return 0;
}

s32 XB_FASTCALL xb_XLIVE_WORK_CLASS_ReleaseQos(u8* self) {
    if (*(s32*)(self + 0x290)) {
        XNetQosRelease(*(void**)(self + 0x2C8));
        *(s32*)(self + 0x2C8) = 0;
        *(s32*)(self + 0x290) = 0;
    }

    xb_vector_TidyThunk(self + 0x298);
    xb_vector_TidyThunk(self + 0x2A8);
    xb_vector_TidyThunk(self + 0x2B8);
    return 0;
}

s32 XB_FASTCALL xb_XLIVE_WORK_CLASS_RestartQos(void* self) {
    xb_XLIVE_WORK_CLASS_ReleaseQos(self);
    xb_XLIVE_WORK_CLASS_QosListen(self);
    return 0;
}

s32 XB_FASTCALL xb_xlive_ThunkFC23E(u8* self) {
    return xb_iterator_Deref(self);
}

void xb_BgmFadeOutSpeed(s16 frames) {
    D_0079A3C0 = 0;
    SsBgmFadeOut(0x8000 / frames);
}

void XB_FASTCALL xb_XLIVE_STARTMENU_CLASS_Clear(u8* self) {
    memset(self + 4, 0, 0x50);
    *(s32*)(self + 0x64) = -1;
    *(s32*)(self + 0x58) = 0;
    *(s32*)(self + 0x5C) = 0;
    self[0x6C] = 1;
    *(s32*)(self + 0x7C) = 0;
    *(s32*)(self + 0x78) = 0;
    self[0x6D] = 0;
}

void XB_FASTCALL xb_XLIVE_STARTMENU_CLASS_Set6C(u8* self, s32 edx, u8 v) {
    (void)edx;
    self[0x6C] = v;
}

void XB_FASTCALL xb_XLIVE_STATMENU_CLASS_ReleaseSlot(u8* self) {
    if (*(s32*)(self + 0x54) != -1) {
        xb_xlive_friend_Release(*(s32*)(self + 0x54));
        *(s32*)(self + 0x54) = -1;
    }

    if (*(s32*)(self + 0x58) != -1) {
        xb_xlive_friend_Release(*(s32*)(self + 0x58));
        *(s32*)(self + 0x58) = -1;
    }

    if (*(s32*)(self + 0x5C) != -1) {
        xb_xlive_friend_Release(*(s32*)(self + 0x5C));
        *(s32*)(self + 0x5C) = -1;
    }

    if (*(s32*)(self + 0x60) != -1) {
        xb_xlive_friend_Release(*(s32*)(self + 0x60));
        *(s32*)(self + 0x60) = -1;
    }
}

s32 XB_FASTCALL xb_XLIVE_STARTMENU_CLASS_Get74(u8* self) {
    return *(s32*)(self + 0x74);
}

u8 XB_FASTCALL xb_XLIVE_STARTMENU_CLASS_Get6D(u8* self) {
    return *(u8*)(self + 0x6D);
}

void XB_FASTCALL xb_XLIVE_STARTMENU_CLASS_Set6D(u8* self, s32 edx, u8 v) {
    (void)edx;
    self[0x6D] = v;
}

s32 XB_FASTCALL xb_XLIVE_STARTMENU_CLASS_Get70(u8* self) {
    return *(s32*)(self + 0x70);
}

void XB_FASTCALL xb_XLIVE_STARTMENU_CLASS_Set70(u8* self, s32 edx, s32 v) {
    (void)edx;
    *(s32*)(self + 0x70) = v;
}

u8 XB_FASTCALL xb_XLIVE_WORK_CLASS_Get235C(u8* self) {
    return *(u8*)(self + 0x235C);
}

u8 xb_LiveWork_Call113F24(void) {
    return xb_XLIVE_STARTMENU_CLASS_Get6D(D_00798CAC + 0x24C0);
}

void xb_LiveWork_Menu24C0(s32 v) {
    XB_ARG a;

    a.v = v;
    ((void (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_STARTMENU_CLASS_Set6C)(D_00798CAC + 0x24C0, a);
}

s32 XB_FASTCALL xb_XLIVE_STATMENU_CLASS_Release(u8* self) {
    xb_XLIVE_STATMENU_CLASS_ReleaseSlot(self);
    xb_XLIVE_PAGE_CLASS_Clear(self);
    return 0;
}

void xb_LiveWork_Update24C0(void) {
    if (xb_LiveWork_Call113F24() || xb_LiveWork_Get2330() || xb_GetOnlineFlagThunk()) {
        xb_XLIVE_STARTMENU_CLASS_Update(D_00798CAC + 0x24C0);
    }
}

void XB_FASTCALL xb_XLIVE_STARTMENU_CLASS_Countdown(u8* self) {
    switch (*(s32*)(self + 0xC)) {
    default:
        (*(s32*)(self + 4))--;
        break;

    case 0:
        *(s32*)(self + 0xC) = 1;
        xb_XLIVE_STATMENU_CLASS_Init(D_00798CAC + 0x2544);

    case 1:
        if (xb_XLIVE_STATMENU_CLASS_StepTimer(D_00798CAC + 0x2544)) {
            xb_OnlineObj_SetFlag(*(s32*)(self + 0x64), 1);
            (*(s32*)(self + 0xC))++;
        }

        break;
    }
}

void xb_LiveWork_Poll24C0(void) {
    if (xb_XLIVE_WORK_CLASS_Get235C(D_00798CAC) || xb_GetOnlineFlagThunk()) {
        xb_XLIVE_STARTMENU_CLASS_StatUpdate(D_00798CAC + 0x24C0);
    }
}

typedef struct {
    s16 x0;
    s16 y0;
    s16 x1;
    s16 y1;
    u32 col;
} XB_RECT16;
void xb_DrawQuadWithSavedStates(XB_RECT16* r);
extern s32 D_003F3A14;

/* xb_DrawFramedRect 0x11B134: a filled rectangle in col with a white
 * frame D_003F3A14 wide inside its edges; nothing for an all-zero one. */
void xb_DrawFramedRect(f32 x0, f32 y0, f32 x1, f32 y1, f32 z, u32 col) {
    XB_RECT16 r;
    s16 iy1;
    s32 ix0;
    s32 iy0;
    s32 ix1;

    if (x0 != 0.0f || y0 != 0.0f || x1 != 0.0f || y1 != 0.0f) {
        iy1 = (s16)y1;
        r.y1 = iy1;
        r.col = col;
        ix0 = (s32)x0;
        iy0 = (s32)y0;
        ix1 = (s32)x1;
        r.x0 = ix0;
        r.y0 = iy0;
        r.x1 = ix1;
        xb_DrawQuadWithSavedStates(&r);
        r.col = 0xFFFFFFFF;
        r.x1 = D_003F3A14 + ix0;
        r.y1 = iy1;
        r.x0 = ix0;
        r.y0 = iy0;
        xb_DrawQuadWithSavedStates(&r);
        r.x1 = ix1;
        r.x0 = ix1 - D_003F3A14;
        xb_DrawQuadWithSavedStates(&r);
        r.y0 = iy0;
        r.x0 = ix0;
        r.x1 = ix1;
        r.y1 = iy0 + D_003F3A14;
        xb_DrawQuadWithSavedStates(&r);
        r.y1 = iy1;
        r.y0 = iy1 - D_003F3A14;
        xb_DrawQuadWithSavedStates(&r);
    }
}

s32 xb_OnlineObj_IsId(s32 id) {
    return *(s16*)(D_0079A472 + (id >> 16) * 0x5C) == (s16)id;
}

u8* xb_FindOnlineObj(s32 id) {
    s32 i = id >> 16;
    u8* r = 0;

    if (i < 0 || i >= 30) {
        return 0;
    }

    if (*(s16*)(D_0079A418 + i * 0x5C + 0x5A) == (s16)id) {
        r = D_0079A418 + i * 0x5C;
    }

    return r;
}

void xb_OnlineObj_Kill(s32 id) {
    if (xb_OnlineObj_IsId(id) == 1) {
        memset(D_0079A418 + (id >> 16) * 0x5C, 0, 0x5C);
    }
}

void xb_OnlineObj_SetFlag(s32 id, u8 v) {
    if (xb_OnlineObj_IsId(id)) {
        D_0079A470[(id >> 16) * 0x5C] = v;
    }
}

u8 xb_OnlineObj_IsDone(s32 id) {
    if (xb_OnlineObj_IsId(id) == 0) {
        return 1;
    }

    {
        u8 r = D_0079A418[(id >> 16) * 0x5C + 1] == 0;

        return r;
    }
}

u8 xb_OnlineObj_Exists(s32 id) {
    u8 r = xb_OnlineObj_IsId(id) != 0;

    return r;
}

/* The Live menus' windows (D_0079A418, 30 of 0x5C bytes): one opens from
 * its centre to its rectangle in a number of steps, and closes back. Its
 * id is the slot in the high half and a serial (D_00418900) in the low. */
typedef struct {
    u8 used;
    u8 moving;
    u8 open;
    u8 pad3;
    f32 cx;
    f32 cy;
    f32 x0;
    f32 y0;
    f32 x1;
    f32 y1;
    f32 cur[4];
    s32 steps;
    s32 count;
    s32 left;
    f32 d[4];
    f32 r[4];
    u8 dirty;
    u8 pad59;
    s16 id;
} XB_OOBJ;
extern s16 D_00418900;
extern f32 D_002190A4;

#define xb_oobj ((XB_OOBJ*)D_0079A418)

/* xb_FindFreeOnlineObj 0x11B243: a free window, closed at the centre of
 * its rectangle, and its id; -1 when none is free. */
s32 xb_FindFreeOnlineObj(f32 x0, f32 y0, f32 x1, f32 y1) {
    s32 i;
    f32 cx;
    f32 cy;

    for (i = 0; i < 30; i++) {
        if (xb_oobj[i].used == 0) {
            cx = (x1 - x0) / D_002190A4 + x0;
            cy = (y1 - y0) / D_002190A4 + y0;
            xb_oobj[i].id = D_00418900++;
            xb_oobj[i].used = 1;
            xb_oobj[i].moving = 0;
            xb_oobj[i].cx = cx;
            xb_oobj[i].cy = cy;
            xb_oobj[i].x0 = x0;
            xb_oobj[i].y0 = y0;
            xb_oobj[i].x1 = x1;
            xb_oobj[i].y1 = y1;
            xb_oobj[i].cur[0] = cx;
            xb_oobj[i].cur[1] = cy;
            xb_oobj[i].cur[2] = cx;
            xb_oobj[i].cur[3] = cy;
            xb_oobj[i].steps = 7;
            xb_oobj[i].dirty = 1;
            xb_oobj[i].left = 7;

            if (D_00418900 == 0) {
                D_00418900 = 1;
            }

            return (i << 16) | (u16)xb_oobj[i].id;
        }
    }

    return -1;
}

extern u8 D_0079AEE0;

/* xb_UpdateOnlineObjs 0x11B389: once a frame (D_0079AEE0), each moving
 * window one step on; at the last it snaps to its rectangle when opening,
 * or back to its first step and off when closing. */
void xb_UpdateOnlineObjs(void) {
    s32 i;

    if (D_0079AEE0 != 0) {
        return;
    }

    for (i = 0; i < 30; i++) {
        if (xb_oobj[i].used == 1 && xb_oobj[i].moving == 1 && xb_oobj[i].count != xb_oobj[i].steps) {
            xb_oobj[i].cur[0] += xb_oobj[i].d[0];
            xb_oobj[i].cur[1] += xb_oobj[i].d[1];
            xb_oobj[i].cur[2] += xb_oobj[i].d[2];
            xb_oobj[i].cur[3] += xb_oobj[i].d[3];
            xb_oobj[i].count++;

            if (xb_oobj[i].open == 1) {
                xb_oobj[i].left++;
            }

            if (xb_oobj[i].count == xb_oobj[i].steps) {
                if (xb_oobj[i].open == 1) {
                    xb_oobj[i].cur[0] = xb_oobj[i].x0;
                    xb_oobj[i].cur[1] = xb_oobj[i].y0;
                    xb_oobj[i].cur[2] = xb_oobj[i].x1;
                    xb_oobj[i].cur[3] = xb_oobj[i].y1;
                } else {
                    xb_oobj[i].dirty = 0;
                    xb_oobj[i].cur[0] = xb_oobj[i].r[0];
                    xb_oobj[i].cur[1] = xb_oobj[i].r[1];
                    xb_oobj[i].cur[2] = xb_oobj[i].r[2];
                    xb_oobj[i].cur[3] = xb_oobj[i].r[3];
                }

                xb_oobj[i].moving = 0;
            }
        }
    }

    D_0079AEE0 = 1;
}

s32 xb_xlive_disp_IsEnabled(void);
extern f32 D_002B4DF8;
extern f32 D_002190AC;
extern f32 D_002190C8;

/* xb_OnlineDrawBar 0x11B45F: SetBar's bar: v of D_002B4DF8 of the width
 * filled in col, the rest black, and a white frame around it (thicker
 * with the display scaled). */
void xb_OnlineDrawBar(s32 v, f32 x, f32 y, f32 w, f32 h, f32 z, u32 col) {
    XB_RECT16 r;
    f32 fill;
    f32 t;
    s32 ix;
    s32 iy;
    s32 ie;
    s32 it;
    s32 ih;
    s32 iw;

    fill = (f32)v * w / D_002B4DF8;

    if (fill > w) {
        fill = w;
    }

    ix = (s32)x;
    r.x1 = (s32)w + ix;
    ie = (s32)fill + ix;
    iy = (s32)y;
    r.y0 = iy;
    r.x0 = ie;
    r.y1 = (s32)h + iy;
    r.col = 0xFF000000;
    xb_DrawQuadWithSavedStates(&r);
    r.col = col;
    r.x0 = ix;
    r.x1 = ie;
    xb_DrawQuadWithSavedStates(&r);
    x -= D_002190A4;
    y -= D_002190A4;
    w += D_002190C8;
    h += D_002190C8;
    t = xb_xlive_disp_IsEnabled() ? D_002190AC : D_002190A4;
    ix = (s32)x;
    iy = (s32)y;
    ih = (s32)h;
    r.col = 0xFFFFFFFF;
    it = (s32)t;
    r.x1 = it + ix;
    r.y1 = ih + iy;
    r.x0 = ix;
    r.y0 = iy;
    xb_DrawQuadWithSavedStates(&r);
    iw = (s32)w;
    r.x1 = iw + ix;
    r.x0 = iw - it + ix;
    xb_DrawQuadWithSavedStates(&r);
    r.x0 = ix;
    r.x1 = iw + ix;
    r.y1 = it + iy;
    r.y0 = iy;
    xb_DrawQuadWithSavedStates(&r);
    r.y1 = ih + iy;
    r.y0 = ih - it + iy;
    xb_DrawQuadWithSavedStates(&r);
}

/* xb_OnlineObj_Move 0x11B606: the window starts opening: per-step moves
 * of its edges from the centre, and the first step. */
void xb_OnlineObj_Move(s32 id) {
    s32 i = id >> 16;
    f32 n;

    if (xb_OnlineObj_IsId(id)) {
        n = (f32)xb_oobj[i].steps;
        xb_oobj[i].count = 0;
        xb_oobj[i].left = 0;
        xb_oobj[i].d[0] = 0.0f - (xb_oobj[i].cx - xb_oobj[i].x0) / n;
        xb_oobj[i].d[1] = 0.0f - (xb_oobj[i].cy - xb_oobj[i].y0) / n;
        xb_oobj[i].d[2] = (xb_oobj[i].x1 - xb_oobj[i].cx) / n;
        xb_oobj[i].d[3] = (xb_oobj[i].y1 - xb_oobj[i].cy) / n;
        xb_oobj[i].moving = 1;
        xb_oobj[i].r[0] = xb_oobj[i].d[0] + xb_oobj[i].cx;
        xb_oobj[i].r[1] = xb_oobj[i].d[1] + xb_oobj[i].cy;
        xb_oobj[i].r[2] = xb_oobj[i].d[2] + xb_oobj[i].cx;
        xb_oobj[i].r[3] = xb_oobj[i].d[3] + xb_oobj[i].cy;
        xb_oobj[i].open = 1;
        xb_oobj[i].dirty = 1;
    }
}

/* xb_OnlineObj_Fade 0x11B710: the window starts closing, its moves
 * reversed. */
void xb_OnlineObj_Fade(s32 id) {
    s32 i = id >> 16;

    if (xb_OnlineObj_IsId(id)) {
        xb_oobj[i].count = 0;
        xb_oobj[i].d[0] = 0.0f - xb_oobj[i].d[0];
        xb_oobj[i].d[1] = 0.0f - xb_oobj[i].d[1];
        xb_oobj[i].d[2] = 0.0f - xb_oobj[i].d[2];
        xb_oobj[i].moving = 1;
        xb_oobj[i].d[3] = 0.0f - xb_oobj[i].d[3];
        xb_oobj[i].open = 0;
        xb_oobj[i].dirty = 1;
        xb_oobj[i].left = 7;
    }
}

/* xb_OnlineObj_IsActive 0x11B7EF: the window has finished opening. */
s32 xb_OnlineObj_IsActive(s32 id) {
    if (xb_OnlineObj_IsId(id) == 0 || xb_OnlineObj_IsDone(id) == 0) {
        return 0;
    }

    return xb_FindOnlineObj(id)[2] != 0;
}

s32 xb_OnlineStartup(s32 params) {
    return XOnlineStartup(params);
}

void xb_SetSaveCallbacks(void (*save)(void), void (*load)(void)) {
    D_0079AF08 = save;
    D_0079AF04 = load;
}

void xb_NetSync_SetState(s32 state) {
    D_007A7BC8 = D_007A7BC4;
    D_007A7BC4 = state;
    D_007A7BCC = 0;
    D_007A7BCD = 0;
    D_007A7BCE = 0;
    D_007A7BCF = 0;
    D_007A7BD0 = 0;
    D_007A7BD2 = 0;
}

u16 xb_MsgQueueGetCount(void) {
    return D_0079B714;
}

/* xb_MsgQueuePush 0x11CDD5: queues each message of a zero-terminated run.
 * Returns the queue count, or -1 when the wrapped part would run into
 * unread messages. */
s32 xb_MsgQueuePush(u8* m) {
    u32 n;

    while (*m > 0) {
        n = *m;

        if (D_0079B710 != 0) {
            if (D_00418944 - D_0079B710 < (s32)n) {
                return -1;
            }

            memcpy(D_0079B710, m, n);
            D_0079B710 += n;
        } else {
            if (D_00418948 + n > D_0079AF10 + sizeof(D_0079AF10)) {
                D_0079B710 = D_0079AF10;
                continue;
            }

            memcpy(D_00418948, m, n);
            D_00418948 += n;
        }

        m += n;
        D_0079B714++;
    }

    return D_0079B714;
}

/* xb_MsgQueuePop 0x11CE71: the next message, or 0 when the queue is empty. */
u8* xb_MsgQueuePop(void) {
    u8* m;
    u8* next;

    if (D_00418948 == D_0079AF10) {
        return 0;
    }

    m = D_00418944;
    next = m + *m;
    D_00418944 = next;

    if (next == D_00418948) {
        D_00418944 = D_0079AF10;

        if (D_0079B710 != 0) {
            D_00418948 = D_0079B710;
            D_0079B710 = 0;
        } else {
            D_00418948 = D_0079AF10;
        }
    }

    D_0079B714--;
    return m;
}

void xb_NetSync_SetPacketTarget(u8 player, s32 target) {
    D_007A7A1C = player;
    D_007A7A18 = target;
    D_007A7A5A = player;
}

s32 xb_NetSync_BuildHeader(s32 sock, s32 a, s32 b, XB_SEQ seq, s32 c, s32* id) {
    s32 r;

    D_007A7600[6] = seq.hi >> 8;
    D_007A7600[7] = seq.hi;
    D_007A7600[0] = 0x82;
    D_007A7600[1] = 2;
    D_007A7600[2] = 0x10;
    D_007A7600[3] = 0x31;
    D_007A7600[4] = 0;
    D_007A7600[5] = 8;
    D_007A7600[8] = 0;
    D_007A7600[9] = 0xFF;
    D_007A7600[10] = 0xFF;
    D_007A7600[11] = 0xFF;
    *(s32*)(D_007A7600 + 12) = id[0];
    *(s32*)(D_007A7600 + 16) = id[1];
    r = xb_NetSync_Send(sock, D_007A7600, 0x14);

    if (r != 0x14) {
        xb_NetSync_SetPacketTarget(4, r);
        return -1;
    }

    return 0;
}

/* xb_NetSync_BuildRequest 0x11CF85: sends this console's settings (see
 * XB_NSREC) and the D_007A7A80 bytes at D_007A7A84 to player pl. */
s32 xb_NetSync_BuildRequest(s32 sock, s8 pl) {
    s32 n;
    s32 i;
    s32 r;

    if (pl < 0 || D_007A7A0A <= pl) {
        return 0;
    }

    n = D_007A7A80;
    D_007A7600[0] = n + 0x1F;
    D_007A7600[1] = pl | 0xC0;
    D_007A7600[2] = xb_Get7C5878();
    D_007A7600[3] = xb_GetPlayerSetting(0);
    D_007A7600[4] = xb_GetPlayerSetting(1);
    D_007A7600[5] = xb_GetPlayerSetting(2);
    D_007A7600[6] = xb_GetPlayerSetting(3);
    D_007A7600[7] = xb_GetPlayerSetting(4);
    D_007A7600[8] = xb_GetPlayerSetting(5);
    D_007A7600[9] = xb_GetPlayerSetting(6);
    D_007A7600[10] = xb_GetPlayerSetting(7);

    for (i = 0; i < 0x14; i++) {
        D_007A7600[0xB + i] = xb_GetSettingByte(i);
    }

    memcpy(D_007A7600 + 0x1F, D_007A7A84, n);
    r = xb_NetSync_Send(sock, D_007A7600, D_007A7600[0]);

    if (r != D_007A7600[0]) {
        xb_NetSync_SetPacketTarget(4, r);
        return -1;
    }

    return 0;
}

void xb_NetSync_Check(void) {
    if (xb_NetSync_BuildRequest(D_007A7BC0, D_007A7A0C) < 0) {
        xb_NetSync_SetState(9);
    }
}

/* xb_NetSync_BuildPacket 0x11D0AF: sends player pl the four-byte message
 * 0x30 with argument a and queues a copy of it. */
s32 xb_NetSync_BuildPacket(s32 sock, s8 pl, u8 a) {
    s32 r;

    if (pl < 0 || D_007A7A0A <= pl) {
        return 0;
    }

    D_007A7600[1] = pl | 0x30;
    D_007A7600[0] = 4;
    D_007A7600[2] = a;
    D_007A7600[3] = 0;
    r = xb_NetSync_Send(sock, D_007A7600, 4);
    memset(&D_007A7600[4], 0, 1);

    if (r != D_007A7600[0]) {
        xb_NetSync_SetPacketTarget(4, r);
        return -1;
    }

    xb_MsgQueuePush(D_007A7600);
    return 0;
}

s32 xb_NetSync_BuildAck(s32 sock, s8 pl, u8 a, u8 b) {
    s32 r;

    if (pl < 0 || D_007A7A0A <= pl) {
        return 0;
    }

    D_007A7600[1] = pl | 0x50;
    D_007A7600[3] = b;
    D_007A7600[0] = 6;
    D_007A7600[2] = 1;
    D_007A7600[4] = a;
    D_007A7600[5] = 0;
    r = xb_NetSync_Send(sock, D_007A7600, 6);

    if (r != D_007A7600[0]) {
        xb_NetSync_SetPacketTarget(4, r);
        return -1;
    }

    return 0;
}

s32 xb_NetSync_FindEntry(s32 a, u8* buf, s32 size) {
    s32 n = xb_NetSync_Receive(a, buf, size);

    if (n < 0 || n >= size) {
        xb_NetSync_SetPacketTarget(3, n);
        return -1;
    }

    memset(&buf[n], 0, 1);

    if (n == 0) {
        return 0;
    }

    D_007A7A38 += n;
    return n;
}

/* xb_NetSync_Step 0x11DA18: Game01's settings exchange. The first call
 * sends message 0x30 and allows 600 frames; later calls read and parse
 * messages until one answers (0x3210), which moves to state 10, or time
 * runs out (state 9). */
void xb_NetSync_Step(void) {
    u8* m;

    if (xb_NetSync_GetFlag2() == 0) {
        xb_NetSync_SetFlag2(1);
        D_007A7BD0 = 600;

        if (xb_NetSync_BuildPacket(D_007A7BC0, D_007A7A0C, 0) < 0) {
            xb_NetSync_SetState(9);
        }

        return;
    }

    if ((s16)--D_007A7BD0 < 0) {
        xb_NetSync_SetState(9);
        xb_NetSync_SetPacketTarget(0xE, 0);
        return;
    }

    if (xb_MsgQueueGetCount() == 0) {
        if (xb_NetSync_FindEntry(D_007A7BC0, D_007A7600, 0x400) < 0) {
            xb_NetSync_SetState(9);
            return;
        }

        xb_MsgQueuePush(D_007A7600);
    }

    while ((m = xb_MsgQueuePop()) != 0) {
        if (xb_NetSync_ParsePacket(D_007A7BC0, D_007A7A0C, m) == 0x3210) {
            xb_NetSync_SetState(10);
            return;
        }
    }
}

s32 xb_NetSync_Send(s32 sock, const void* buf, s16 len) {
    s32 r = send(sock, buf, len, 0);

    if (r == -1) {
        return WSAGetLastError() == 0x2733 ? 0 : -1;
    }

    return r;
}

/* xb_NetSync_Receive 0x11DB08: reads what socket sock has ready without
 * waiting. Returns the byte count, 0 for nothing (or WSAEWOULDBLOCK), or
 * -1. */
s32 xb_NetSync_Receive(s32 sock, u8* buf, s16 len) {
    s32 r;

    D_0079B81C.tv_sec = 0;
    D_0079B81C.tv_usec = 0;
    D_0079B718.fd_array[0] = sock;
    D_0079B718.fd_count = 1;
    r = select(sock + 1, &D_0079B718, 0, 0, &D_0079B81C);

    if (r > 0) {
        if (__WSAFDIsSet(sock, &D_0079B718)) {
            r = recv(sock, buf, len, 0);

            if (r == -1) {
                r = WSAGetLastError() == 0x2733 ? 0 : -1;
            }
        }
    } else {
        r = 0;
    }

    return r;
}

void* XB_FASTCALL xb_XLIVE_WORK_CLASS_ctor(u8* self) {
    xb_XLIVE_WORKBASE_CLASS_ctor(self);
    *(void**)self = D_002B8708;
    *(s32*)(self + 0x232C) = 5;
    return self;
}

void XB_FASTCALL xb_XLIVE_WORK_CLASS_dtor(void** self) {
    *self = D_002B8708;
    xb_XLIVE_WORKBASE_CLASS_dtor(self);
}

s32 xb_LiveWork_Create(void) {
    s32 size = 0;
    s32 key = load_it_use_any_key2(0xC, &D_0079B834, &size, 2, 0);

    if (key == 0) {
        flLogOut(D_002B877C);
        while (1) {}
    }

    D_0079B828 = 0;
    D_0079B82C = 0;
    DirectSoundCreate(0, &D_00795C10, 0);
    DirectSoundUseLightHRTF();
    xb_DownloadEffectsImage(D_00795C10, D_0079B834, key, &D_0079B828, &D_0079B830);
    return 1;
}

void xb_ClearRebattleWork(void) {
    memset(D_007A6460, 0, 0x18);
}

void xb_NetSync_SetFlag2(s32 v) {
    D_007A1390 = v;
}

s32 xb_NetSync_GetFlag2(void) {
    return D_007A1390;
}

/* xb_NetSync_CheckPlayers 0x12058B: once both consoles' settings
 * (D_007A6480) have arrived, takes each one's buttons into
 * save_w[2].Pad_Infor and turns a character colour or the permission
 * switches on where either console has it on. Returns 1 when done. */
s32 xb_NetSync_CheckPlayers(void) {
    s8 me = xb_GetOnlineByte799440() & 1;
    s8 other = ~xb_GetOnlineByte799440() & 1;
    s32 i;

    xb_GetOnlinePlayer(0);
    xb_GetOnlinePlayer(1);
    xb_NetSync_Check();

    if (D_007A6480[0].flag == 0xFF || D_007A6480[1].flag == 0xFF) {
        return 0;
    }

    if (D_007A6480[0].flag == 1 || D_007A6480[1].flag == 1) {
        permission_player[0x30] = 1;
        permission_player[0x18] = 1;
        permission_player[0x60] = 1;
        permission_player[0x78] = 1;
    } else {
        permission_player[0x30] = 0;
        permission_player[0x18] = 0;
        permission_player[0x60] = 0;
        permission_player[0x78] = 0;
    }

    for (i = 0; i < 8; i++) {
        if (D_007A6480[other].shot[i] == 0xFF) {
            return 0;
        }
    }

    /* save_w[2].Pad_Infor[n].Shot */
    *(s32*)(save_w + 0x410 + me * 12) = *(s32*)&D_007A6480[me].shot[0];
    *(s32*)(save_w + 0x414 + me * 12) = *(s32*)&D_007A6480[me].shot[4];
    *(s32*)(save_w + 0x410 + other * 12) = *(s32*)&D_007A6480[other].shot[0];
    *(s32*)(save_w + 0x414 + other * 12) = *(s32*)&D_007A6480[other].shot[4];

    for (i = 0; i < 0x14; i++) {
        if (D_007A6480[other].color[i] == 0xFF) {
            return 0;
        }
    }

    /* save_w[2].PL_Color[0] and [1] */
    for (i = 0; i < 0x14; i++) {
        if (D_007A6480[me].color[i] == 1 || D_007A6480[other].color[i] == 1) {
            save_w[0x43C + i] = 1;
            save_w[0x450 + i] = 1;
        } else {
            save_w[0x43C + i] = 0;
            save_w[0x450 + i] = 0;
        }
    }

    return 1;
}

void xb_NetSync_SetDone(s32 v) {
    D_007A1394 = v;
}

s32 xb_NetSync_IsDone(void) {
    return D_007A1394;
}

s32 xb_Get7C5878(void) {
    return D_007C5878;
}

s32 xb_GetPlayerSetting(s32 i) {
    return D_007BD5E8[xb_GetOnlineModeArg2() * 12 + i];
}

s32 xb_GetSettingByte(s32 i) {
    return D_007BD614[i];
}

void xb_RegisterSaveHandlers(void) {
    xb_SetLiveCallback(0, (s32)sub_001206D8);
    xb_SetLiveCallback(1, (s32)sub_0004AFFA);
    xb_SetLiveCallback(2, (s32)xb_xlive_select_Init);
}

void xb_RegisterSaveCallbacks(void) {
    xb_SetSaveCallbacks((void (*)(void))xb_xlive_SetNetPad, (void (*)(void))xb_xlive_GetLocalPad);
}

/* xb_SaveStateIdle: the state machine back to idle. */
static void xb_SaveStateIdle(void) {
    D_007A156C = 0;
    *(s32*)((u8*)&D_007A14A0 + 0xE0) = 0;
}

/* xb_SaveStateFinish: idle again once a result is in. */
static void xb_SaveStateFinish(u8* st) {
    if (*(s32*)(st + 0x24) != -1) {
        xb_SaveStateIdle();
    }
}

/* xb_SaveStateStartHeader: starts reading a save's header into buf. */
void xb_SaveStateStartHeader(s32 unused, s32 buf) {
    u8* st = (u8*)&D_007A14A0;

    *(s32*)(st + 0x24) = -1;
    *(s32*)(st + 0) = 0;
    *(s32*)(st + 4) = 0;
    D_007A156C = 1;
    *(s32*)(st + 0xD0) = buf;
}

/* xb_save_SaveName: the kind's save name (numbered by slot when it has
 * several) as the wide string XCreateSaveGame takes. */
#define XB_SAVE_NAME(d, st, title)                                              \
    xb_memset_bytes(D_007A13A0, 0, 0x80);                                       \
    if ((d)->slots != 0) {                                                      \
        xb_memset_bytes(title, 0, 0x80);                                        \
        sprintf(title, "%s%02d", (d)->title, *(s32*)((st) + 0xD8) + 1);         \
        mbstowcs(D_007A13A0, title, strlen(title));                             \
    } else {                                                                    \
        mbstowcs(D_007A13A0, (d)->title, strlen((d)->title));                   \
    }

/* xb_SaveStateReadHeader: state 1: a save's header: its time stamp from the
 * file's write time (8 bytes) and, for a kind with a second file, that
 * file's first bytes after checking its signature. */
void xb_SaveStateReadHeader(u8* st) {
    XB_SAVEDESC* d = D_00436F00[*(s32*)(st + 0xD4)];
    char root[4];
    char path[0x104];
    char title[0x80];
    u8 sig[20];
    u8 sig2[20];
    u8 hdr[8];
    XB_FILEINFO info;
    u32 local[2];
    XB_SYSTIME tm;
    s32 h;
    u32 size;
    u32 hi;
    u32 got;
    u32 max;
    u8* mem;
    s32 ok;
    s32 sh;

    *(u32*)root = 0x5C3A55;
    XB_SAVE_NAME(d, st, title);

    if (root[0] == 0) {
        goto failed;
    }

    if (XCreateSaveGame(root, D_007A13A0, 3, 0, path, 0x104) != 0) {
        goto nofile;
    }

    /* the path from XCreateSaveGame ends with a backslash */
    strcpy(path + strlen(path), "\\");
    strcpy(path + strlen(path) - 1, d->file);
    h = CreateFileA(path, 0x80000000, 0, 0, 3, 0x80, 0);

    if (h != -1) {
        GetFileInformationByHandle(h, &info);
        FileTimeToLocalFileTime(info.wtime, local);
        FileTimeToSystemTime(local, &tm);
        *(u16*)(hdr + 6) = tm.year;
        hdr[5] = tm.month;
        hdr[0] = tm.weekday;
        hdr[4] = tm.day;
        hdr[3] = tm.hour;
        hdr[2] = tm.minute;
        hdr[1] = tm.second;
        CloseHandle(h);
        *(s32*)(st + 0x24) = 0;
    } else {
        *(s32*)(st + 0x24) = XB_SAVE_NOFILE;
    }

    if (d->sub != 0) {
        if (XCreateSaveGame(root, D_007A13A0, 3, 0, path, 0x104) != 0) {
            goto nofile;
        }

        strcpy(path + strlen(path), "\\");
        strcpy(path + strlen(path) - 1, d->sub);
        h = CreateFileA(path, 0x80000000, 0, 0, 3, 0x80, 0);

        if (h == -1) {
            goto nofile;
        }

        size = GetFileSize(h, &hi);
        max = d->blocks << 14;

        if (size > max || size < 0x14 || (size -= 0x14) == 0 || size > max || !ReadFile(h, sig, 0x14, &got, 0)) {
            CloseHandle(h);
            goto failed;
        }

        mem = XPhysicalAlloc(size, 0xFFFFFFFF, 0, 4);
        ok = ReadFile(h, mem, size, &got, 0);
        CloseHandle(h);

        if (!ok) {
            XPhysicalFree(mem);
            goto failed;
        }

        memcpy(*(u8**)(st + 0xD0), mem, d->subsize);
        sh = XCalculateSignatureBegin(0);
        XCalculateSignatureUpdate(sh, mem, size);
        XCalculateSignatureEnd(sh, sig2);

        if (memcmp(sig, sig2, 20) != 0) {
            XPhysicalFree(mem);
            goto failed;
        }

        XPhysicalFree(mem);
        *(s32*)(st + 0x24) = 0;
    }

    memcpy(*(u8**)(st + 0xD0), hdr, 8);
    goto done;

failed:
    *(s32*)(st + 0x24) = XB_SAVE_FAILED;
    goto done;

nofile:
    *(s32*)(st + 0x24) = XB_SAVE_NOFILE;

done:
    xb_SaveStateFinish(st);
}

/* xb_SaveStateStartRead: starts reading slot a's data into buf. */
void xb_SaveStateStartRead(s32 a, s32 buf) {
    u8* st = (u8*)&D_007A14A0;

    *(s32*)(st + 0x24) = -1;
    *(s32*)(st + 0) = 0;
    *(s32*)(st + 4) = 0;
    *(s32*)(st + 0x14) = a;
    *(s32*)(st + 0xD0) = buf;
    D_007A156C = 2;
    *(u32*)(st + 0xBC) = D_00436F00[D_007A1574]->size;
}

/* xb_SaveStateRead: states 2 and 3: reads a save's data file into the
 * buffer after checking its signature. */
void xb_SaveStateRead(u8* st) {
    XB_SAVEDESC* d = D_00436F00[*(s32*)(st + 0xD4)];
    char root[4];
    char path[0x104];
    char title[0x80];
    u8 sig[20];
    u8 sig2[20];
    s32 h;
    u32 size;
    u32 hi;
    u32 got;
    u32 max;
    u8* mem;
    s32 ok;
    s32 sh;

    *(u32*)root = 0x5C3A55;
    XB_SAVE_NAME(d, st, title);

    if (XCreateSaveGame(root, D_007A13A0, 3, 0, path, 0x104) != 0) {
        goto nofile;
    }

    strcpy(path + strlen(path), "\\");
    strcpy(path + strlen(path) - 1, d->file);
    h = CreateFileA(path, 0x80000000, 0, 0, 3, 0x80, 0);

    if (h == -1) {
        goto nofile;
    }

    size = GetFileSize(h, &hi);
    max = d->blocks << 14;

    if (size > max || size < 0x14 || (size -= 0x14) == 0 || size > max || !ReadFile(h, sig, 0x14, &got, 0)) {
        CloseHandle(h);
        goto failed;
    }

    mem = XPhysicalAlloc(size, 0xFFFFFFFF, 0, 4);
    ok = ReadFile(h, mem, size, &got, 0);
    CloseHandle(h);

    if (!ok) {
        XPhysicalFree(mem);
        goto failed;
    }

    memcpy(*(u8**)(st + 0xD0), mem, *(u32*)(st + 0xBC));
    sh = XCalculateSignatureBegin(0);
    XCalculateSignatureUpdate(sh, mem, size);
    XCalculateSignatureEnd(sh, sig2);

    if (memcmp(sig, sig2, 20) != 0) {
        XPhysicalFree(mem);
        goto failed;
    }

    XPhysicalFree(mem);
    *(s32*)(st + 0x24) = 0;
    goto done;

failed:
    *(s32*)(st + 0x24) = XB_SAVE_FAILED;
    goto done;

nofile:
    *(s32*)(st + 0x24) = XB_SAVE_NOFILE;

done:
    xb_SaveStateFinish(st);
}

/* xb_SaveStateStartLoad: starts reading slot a into buf (cleared first). */
void xb_SaveStateStartLoad(s32 a, s32 buf, s32 c) {
    u8* st = (u8*)&D_007A14A0;
    u32 size;

    *(s32*)(st + 0x24) = -1;
    *(s32*)(st + 0) = 0;
    *(s32*)(st + 4) = 0;
    *(s32*)(st + 0x14) = a;
    *(s32*)(st + 0xC4) = c;
    *(s32*)(st + 0xD0) = buf;
    D_007A156C = 3;
    size = D_00436F00[D_007A1574]->size;
    *(u32*)(st + 0xBC) = size;
    memset((void*)buf, 0, size);
}

/* xb_SaveStateStartWrite: starts writing buf; a kind's second file takes the
 * bytes after the data. */
void xb_SaveStateStartWrite(s32 a, s32 buf) {
    XB_SAVEDESC* d = D_00436F00[D_007A1574];
    u8* st = (u8*)&D_007A14A0;

    *(s32*)(st + 0x24) = -1;
    *(s32*)(st + 0) = 0;
    *(s32*)(st + 4) = 0;
    *(s32*)(st + 8) = 0;
    D_007A156C = 4;
    *(u32*)(st + 0xBC) = d->size;
    *(s32*)(st + 0xD0) = buf;
    d->subdata = (u8*)buf + d->size;
    *(s32*)(st + 0xE0) = 1;
}

/* xb_SaveStateWrite: state 4: writes a save: its data file (signature, then
 * data) and second file, after checking there is room (-0xFC when
 * there is not), then copies its image in. */
void xb_SaveStateWrite(u8* st) {
    XB_SAVEDESC* d = D_00436F00[*(s32*)(st + 0xD4)];
    char root[4];
    char title[0x80];
    char path[0x104];
    char* tail;
    u8 sig[20];
    XB_U64 free;
    XB_U64 total;
    XB_U64 tfree;
    u32 hi;
    u32 put;
    u32 size;
    s32 h;
    s32 sh;
    u8 tries;
    u32 e;

    *(u32*)root = 0x5C3A55;
    XB_SAVE_NAME(d, st, title);

    if (XCreateSaveGame(root, D_007A13A0, 4, 0, path, 0x104) == 0) {
        tail = path + strlen(path);
        strcpy(tail, "\\");
        strcpy(tail, d->file);
        h = CreateFileA(path, 0x80000000, 0, 0, 3, 0x80, 0);

        if (h != -1) {
            size = GetFileSize(h, &hi);
            CloseHandle(h);

            if (size > *(u32*)(st + 0xBC) + 0x14) {
                GetDiskFreeSpaceExA(root, &free, &total, &tfree);

                if (free.lo + size < *(u32*)(st + 0xBC) + 0x14) {
                    *(s32*)(st + 0x24) = -0xFC;
                    goto done;
                }
            }
        } else {
            GetDiskFreeSpaceExA(root, &free, &total, &tfree);

            if (free.lo < *(u32*)(st + 0xBC) + 0x14) {
                *(s32*)(st + 0x24) = -0xFC;
                goto done;
            }
        }
    }

    h = CreateFileA(path, 0x40000000, 0, 0, 2, 0x80, 0);

    if (h == -1) {
        goto failed;
    }

    sh = XCalculateSignatureBegin(0);
    XCalculateSignatureUpdate(sh, *(u8**)(st + 0xD0), *(u32*)(st + 0xBC));
    XCalculateSignatureEnd(sh, sig);

    if (!WriteFile(h, sig, 0x14, &put, 0) || !WriteFile(h, *(u8**)(st + 0xD0), *(u32*)(st + 0xBC), &put, 0)) {
        goto failed;
    }

    CloseHandle(h);

    if (d->sub != 0) {
        if (XCreateSaveGame(root, D_007A13A0, 4, 0, path, 0x104) == 0) {
            tail = path + strlen(path);
            strcpy(tail, "\\");
            strcpy(tail, d->sub);
            h = CreateFileA(path, 0x80000000, 0, 0, 3, 0x80, 0);

            if (h != -1) {
                size = GetFileSize(h, &hi);
                CloseHandle(h);

                if (size > d->subsize + 0x14) {
                    GetDiskFreeSpaceExA(root, &free, &total, &tfree);

                    if (free.lo + size < d->subsize + 0x14) {
                        *(s32*)(st + 0x24) = -0xFC;
                        goto done;
                    }
                }
            } else {
                GetDiskFreeSpaceExA(root, &free, &total, &tfree);

                if (free.lo < d->subsize + 0x14) {
                    *(s32*)(st + 0x24) = -0xFC;
                    goto done;
                }
            }
        }

        h = CreateFileA(path, 0x40000000, 0, 0, 2, 0x80, 0);

        if (h == -1) {
            goto failed;
        }

        sh = XCalculateSignatureBegin(0);
        XCalculateSignatureUpdate(sh, d->subdata, d->subsize);
        XCalculateSignatureEnd(sh, sig);

        if (!WriteFile(h, sig, 0x14, &put, 0) || !WriteFile(h, d->subdata, d->subsize, &put, 0)) {
            goto failed;
        }

        CloseHandle(h);
    }

    strcpy(tail, "saveimage.xbx");

    for (tries = 0; tries < 5; tries++) {
        if (CopyFileA(d->image, path, 0)) {
            break;
        }
    }

    if (tries >= 5) {
        e = GetLastError();

        if (e == 2 || e == 0x1E) {
            xb_ShowDiskReadError();
        }
    }

    *(s32*)(st + 0x24) = 0;
    goto done;

failed:
    *(s32*)(st + 0x24) = XB_SAVE_FAILED;

done:
    xb_SaveStateFinish(st);
}

/* xb_SaveStateResult: the state machine's result. */
s32 xb_SaveStateResult(void) {
    return *(s32*)((u8*)&D_007A14A0 + 0x24);
}

/* xb_SaveNeededBlocks: the blocks a save of the kind takes. */
s32 xb_SaveNeededBlocks(s32 unused) {
    XB_SAVEDESC* d = D_00436F00[D_007A1574];

    d->r34 = d->blocks;
    return d->blocks;
}

/* xb_SaveFreeBlocks: the free 16 KB blocks on the save drive (U:). */
s32 xb_SaveFreeBlocks(void) {
    char root[4];
    XB_U64 free;
    XB_U64 total;
    XB_U64 tfree;

    *(u32*)root = 0x5C3A55;
    GetDiskFreeSpaceExA(root, &free, &total, &tfree);
    return (s32)((((u64)free.hi << 32 | free.lo) + 0x3FFF) >> 14);
}

/* xb_SaveMenuFileBusy: 1 while the save menu's file (+0x44) is still being
 * read; else closes it. */
s32 xb_SaveMenuFileBusy(void) {
    s32 f = *(s32*)(D_007A1618 + 0x44);

    if (f != 0) {
        if (ADXF_GetStat(f) == 2) {
            return 1;
        }

        ADXF_Close(*(s32*)(D_007A1618 + 0x44));
        *(s32*)(D_007A1618 + 0x44) = 0;
    }

    return 0;
}

/* The kinds: the system data, the directions (three slots) and the
 * replays (three slots, with a 16-byte second file), and the states. */
XB_SAVEDESC D_00436E58 = { "S.F.III 3rd System", "d:\\XB_HostPC\\saveimage_sf33rd0.xbx", 0, 0x4800, "SaveGame", 0,
                           0x218, 0, 0, 0, 5, 0, 0, 0x7FFFFFFF };
XB_SAVEDESC D_00436E90 = { "S.F.III 3rd Direction", "d:\\XB_HostPC\\saveimage_sf33rd1.xbx", 0, 0x4800, "SaveGame", 0,
                           0x58, 0, 0, 0, 5, 3, 0, 0x7FFFFFFF };
XB_SAVEDESC D_00436EC8 = { "S.F.III 3rd Replay", "d:\\XB_HostPC\\saveimage_sf33rd2.xbx", 0, 0x4800, "SaveGame", 0,
                           0x7458, "sub.bin", 0, 0x10, 7, 3, 0, 0x7FFFFFFF };
XB_SAVEDESC* D_00436F00[3] = { &D_00436E58, &D_00436E90, &D_00436EC8 };
void (*D_00436F0C[5])(void* w) = { (void (*)(void*))sub_0004384A, (void (*)(void*))xb_SaveStateReadHeader,
                                   (void (*)(void*))xb_SaveStateRead, (void (*)(void*))xb_SaveStateRead,
                                   (void (*)(void*))xb_SaveStateWrite };

void xb_SaveStateReset(s32 a, s32 b) {
    D_007A14A0 = 0;
    D_007A14A4 = 0;
    D_007A156C = 0;
    D_007A1574 = a;
    D_007A1578 = b;
}

void xb_SaveStateRun(void) {
    sub_0016AA60();
    D_00436F0C[D_007A156C](&D_007A14A0);
    sub_0016AA70();
}

s32 xb_GetLocalizedText(s32 i) {
    return (*D_0043771C[D_007A15CC])[i];
}

s32 xb_PrintAt(s32 x, s32 y, const char* s, s32 unused) {
    xb_PrintSetPos(x, y);

    if (*s) {
        xb_PrintString(s);
    }

    return 0;
}

s32 xb_Get7A1808(void) {
    return D_007A1808;
}

void xb_SeSelectedThunk(void) {
    SE_selected();
}

void xb_SeCursorMoveThunk(void) {
    SE_cursor_move();
}

/* The xhv.h IXHVEngine:: inline wrappers, out of line: jumps to the
 * library's XHVEngine_SetProcessingMode (0x12AE61) and
 * XHVEngine_SetVoiceMask (0x12AE6B). */

s32 XB_STDCALL XHVEngine_SetProcessingMode(s32 a, s32 b, s32 c);
s32 XB_STDCALL XHVEngine_SetVoiceMask(s32 a, s32 b, s32 c);

s32 XB_STDCALL IXHVEngine__SetProcessingMode(s32 a, s32 b, s32 c) {
    return XHVEngine_SetProcessingMode(a, b, c);
}

s32 XB_STDCALL IXHVEngine__SetVoiceMask(s32 a, s32 b, s32 c) {
    return XHVEngine_SetVoiceMask(a, b, c);
}

/* The Live menus' music: the code playing (D_0079A3C0). */
void sub_00098407(s16 Code);
extern s32 D_0079A3C0;

/* xb_LiveBgm_Request 0x11315D: a new code played. */
void xb_LiveBgm_Request(s16 code) {
    if (code != D_0079A3C0) {
        D_0079A3C0 = code;
        sub_00098407(code);
    }
}

/* xb_LiveBgm_Clear 0x113191. */
void xb_LiveBgm_Clear(void) {
    D_0079A3C0 = 0;
}

/* xb_XLIVE_STARTMENU_CLASS_IsMulti 0x113EF1: more than one player. */
s32 XB_FASTCALL xb_XLIVE_STARTMENU_CLASS_IsMulti(u8* self) {
    return *(s32*)(self + 4) > 1;
}

/* xb_LiveStartMenu_IsMulti 0x113EFB: the work's start menu (+0x24C0). */
s32 xb_LiveStartMenu_IsMulti(void) {
    return xb_XLIVE_STARTMENU_CLASS_IsMulti(D_00798CAC + 0x24C0);
}

void XB_FASTCALL xb_XLIVE_WORK_CLASS_Set235C(u8* self, s32 edx, s8 v);

/* xb_LiveWork_Set235C 0x113F6D. */
void xb_LiveWork_Set235C(s32 v) {
    XB_ARG a;

    a.v = v;
    ((void (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_WORK_CLASS_Set235C)(D_00798CAC, a);
}

/* xb_LiveStartMenu_Get70 0x11490E. */
s32 xb_LiveStartMenu_Get70(void) {
    return xb_XLIVE_STARTMENU_CLASS_Get70(D_00798CAC + 0x24C0);
}

/* xb_MatchInfo_Side 0x11ED24: the match's side (+0x170) as the save
 * data's value: 0 -> 1, 1 -> 2, 2 -> 0. */
u8 xb_MatchInfo_Side(void) {
    switch (((u8*)xb_GetMatchInfo())[0x170]) {
    case 0:
        return 1;
    case 1:
        return 2;
    case 2:
        return 0;
    }

    return 1;
}

/* xb_MatchInfo_GetC3 0x11ED44. */
u8 xb_MatchInfo_GetC3(void) {
    return ((u8*)xb_GetMatchInfo())[0xC3];
}

extern u8 task[];
void xb_InitSelectWork(void);
void xb_ClearSelectBGFlag(void);
void xb_SetupSelectBG(void);
void xb_LiveSet79A170(s32 v);
s32 xb_xlive_net_Close(void);
u8* xb_xlive_net_Peer(s32 i);
extern u8 G_No[4];
extern s8 judge_flag;
extern u16 VS_Win_Record[2];
extern u8 D_00796888;
extern s32 D_007A138C;
void cpReadyTask(u16 num, void* func_adrs);
void cpExitTask(u16 num);
void Menu_Task(struct _TASK* task_ptr);
void System_all_clear_Level_B(void);
void Request_LDREQ_Break(void);
void CP3toPS2DrawOn(void);
void All_Clear_ETC(void);
void xb_LiveWork_Set2330(s32 v);
void xb_LiveWork_SetFlag(s32 i, s32 v);
void xb_LiveWork_Clear3DC(void);
void xb_LiveWork_StopUserCount(void);
void xb_xlive_disp_SetEnabled(s32 v);
void xb_xlive_match_Set17E(u8 v);

/* xb_xlive_select_Enter 0x11EF42: from the Live menus to the character
 * select (G_No 2,12) with the menu task in its select state (14); mode 1
 * (from a friend's invitation) sets other flags. */
void xb_xlive_select_Enter(s32 mode) {
    xb_xlive_net_Close();
    cpExitTask(3);
    cpReadyTask(3, Menu_Task);
    task[0x44] = 0xE;
    xb_LiveWork_Set2330(1);
    D_00796888 = 1;
    System_all_clear_Level_B();
    G_No[0] = 2;
    G_No[1] = 0xC;
    G_No[3] = 0;
    G_No[2] = 0;

    switch (mode) {
    case 1:
        xb_LiveWork_SetFlag(0, 5);
        xb_LiveWork_SetFlag(2, 1);
        break;
    default:
        xb_LiveWork_SetFlag(0, 2);
        xb_LiveWork_SetFlag(2, 0);
        break;
    }

    xb_LiveWork_SetFlag(1, 0);
    xb_LiveWork_Clear3DC();
    xb_InitSelectWork();
    xb_ClearSelectBGFlag();
    xb_SetupSelectBG();
    xb_LiveSet79A170(0);
    xb_xlive_disp_SetEnabled(-1);
    xb_LiveWork_StopUserCount();
    xb_LiveBgm_Clear();
    xb_LiveBgm_Request(0x42);
    judge_flag = 0;
    xb_xlive_match_Set17E(0);
    Request_LDREQ_Break();
    D_007A138C = 0;
}

/* xb_xlive_select_Init 0x1204D8: the online select's start (Live
 * callback 2): the match's sides and options into save_w[2] and the win
 * record cleared. */
s32 xb_xlive_select_Init(void) {
    xb_xlive_net_Peer(0);
    xb_xlive_net_Peer(1);
    D_00796888++;
    CP3toPS2DrawOn();
    save_w[0x42A] = xb_MatchInfo_Side();
    save_w[0x42B] = xb_MatchInfo_Side();
    save_w[0x434] = xb_MatchInfo_GetC3();
    save_w[0x418] = save_w[0x210];
    save_w[0x424] = save_w[0x21C];
    xb_InitSelectWork();
    All_Clear_ETC();
    VS_Win_Record[1] = 0;
    VS_Win_Record[0] = 0;
    return 0;
}

extern u8 D_0079B838[];
void XB_FASTCALL xb_XLIVE_WORK_CLASS_ResetFlags(u8* self);
u8 xb_LiveWork_Get2360(void);
void xb_LiveWork_Set2360(s32 v);
void xb_LiveWork_Set235C(s32 v);

/* xb_LiveWork_Bind 0x11ED0A: the work (D_0079B838) made current with its
 * flags reset. */
void xb_LiveWork_Bind(void) {
    D_00798CAC = D_0079B838;
    xb_XLIVE_WORK_CLASS_ResetFlags(D_0079B838);
}

/* xb_xlive_select_Restart 0x11F012: back to the online character select
 * after a match, the work rebound and its flags cleared. */
void xb_xlive_select_Restart(void) {
    cpExitTask(3);
    cpReadyTask(3, Menu_Task);
    task[0x44] = 0xE;
    xb_LiveWork_Set2330(1);
    D_00796888 = 1;
    G_No[0] = 2;
    G_No[1] = 0xC;
    G_No[3] = 0;
    G_No[2] = 0;
    xb_LiveWork_Bind();
    xb_LiveWork_SetFlag(0, 0);
    xb_LiveWork_SetFlag(1, 0);
    xb_LiveWork_SetFlag(2, 0);
    xb_LiveWork_Clear3DC();
    xb_LiveSet79A170(0);
    System_all_clear_Level_B();
    xb_InitSelectWork();
    xb_ClearSelectBGFlag();
    xb_SetupSelectBG();
    xb_xlive_disp_SetEnabled(-1);
    xb_LiveWork_StopUserCount();
    xb_LiveWork_Set2360(0);
    Request_LDREQ_Break();
    xb_LiveBgm_Clear();
    xb_LiveBgm_Request(0x42);
    xb_xlive_match_Set17E(0);
    judge_flag = 0;
    xb_LiveWork_Set235C(0);
    D_007A138C = 0;
}

/* The online game's step (Game's Live case): its state (D_007A6460[0])
 * picks a routine from D_00418958, which leaves its result in
 * D_007A6471. */
extern void (*D_00418958[])(void);
extern u8 D_007A6471;

/* xb_xlive_game_Step 0x1202D2: the select restarted when the work asks
 * for it (+0x2360), else one step of the online game. */
s32 xb_xlive_game_Step(void) {
    if (xb_LiveWork_Get2360()) {
        xb_xlive_select_Restart();
        return 0;
    }

    D_007A6471 = 0;
    D_00418958[D_007A6460[0]]();
    return D_007A6471;
}

/* The pads in an online match: each console's latest pad (D_007A7AC0:
 * buttons, then the 16-bit switch word), the last frame's buttons
 * (D_007A6500), and the copies the game reads (D_007A6340, D_007A63B0,
 * D_007A6478). */
typedef struct {
    u32 sw;
    u16 sw2;
    u16 pad;
} XB_NETPAD;
typedef struct {
    u32 w[13];
} XB_IOPAD;
extern u8 io_w[];
extern XB_NETPAD D_007A7AC0[2];
extern u32 D_007A6500[4];
extern XB_IOPAD D_007A6340[2];
extern u32 D_007A63B0[2];
extern u32 D_007A6478[2];
extern u16 p1sw_buff;
extern u16 p1sw_0;
extern u16 p2sw_buff;
extern u16 p2sw_0;

/* xb_xlive_SetNetPad 0x1208DA (save callback): player pl's pad from the
 * received data, its edges against the last frame, into io_w and the
 * player's copies. */
void xb_xlive_SetNetPad(s8 pl) {
    XB_NETPAD* in = &D_007A7AC0[pl];
    u32* p = (u32*)(io_w + pl * 0x34);
    u32 now;
    u32 old;
    u32 chg;
    u32 off;
    u32 on;

    *(u16*)(io_w + 0xD0 + pl * 2) = in->sw2;
    old = D_007A6500[pl * 2];
    now = in->sw;
    chg = now ^ old;
    off = chg & old;
    on = chg & now;
    p[4] = off;
    p[2] = old;
    p[1] = now;
    p[3] = on;
    p[5] = off | on;

    switch (pl) {
    case 0:
        D_007A63B0[0] = now;
        D_007A6478[0] = old;
        p1sw_buff = p1sw_0 = *(u16*)(io_w + 0xD0);
        D_007A6340[0] = *(XB_IOPAD*)p;
        break;
    case 1:
        D_007A63B0[1] = now;
        D_007A6478[1] = old;
        p2sw_buff = p2sw_0 = *(u16*)(io_w + 0xD2);
        D_007A6340[1] = *(XB_IOPAD*)p;
        break;
    }
}

s32 xb_LiveStartMenu_IsMulti(void);
s32 xb_LiveStartMenu_Get70(void);

/* xb_xlive_GetLocalPad 0x12097D (save callback): player pl's pad to send:
 * in a session the last frame's buttons are kept for it; else its buttons
 * and switch word go to out. */
s32 xb_xlive_GetLocalPad(s8 pl, u32* out) {
    memset(out, 0, 8);

    if (xb_LiveStartMenu_IsMulti() || xb_LiveStartMenu_Get70()) {
        D_007A6478[pl] = *(u32*)(io_w + pl * 0x34 + 8);
    } else {
        out[0] = *(u32*)(io_w + pl * 0x34 + 4);
        out[1] = *(u16*)(io_w + 0xD0 + pl * 2);
    }

    return 0;
}

/* The pad button icons the Live menus draw (dispButtonImage2 at depth
 * 0x80), D_002B4BE4 wide, scaled with the display. */
void dispButtonImage2(s32 px, s32 py, s32 pz, s32 sx, s32 sy, s32 cl, s32 ix);
void xb_xlive_disp_GetScale(f32* x, f32* y);
extern f32 D_002B4BE4;

/* xb_OnlineDrawScaled 0x120300: button icon (0 to 7 as A, B, X, Y,
 * black, white, left and right trigger) at a size of sx and sy icons. */
void xb_OnlineDrawScaled(u16 x, u16 y, s32 icon, f32 sx, f32 sy) {
    s32 tbl[8];
    s32 id;
    f32 w;
    f32 h;
    f32 gx;
    f32 gy;

    w = sx * D_002B4BE4;
    h = sy * D_002B4BE4;
    tbl[0] = 0xC;
    tbl[1] = 0xA;
    tbl[2] = 0xB;
    tbl[3] = 8;
    tbl[4] = 9;
    tbl[5] = 0xD;
    tbl[6] = 0xE;
    tbl[7] = 0xF;
    id = tbl[icon];

    if (xb_xlive_disp_IsEnabled()) {
        xb_xlive_disp_GetScale(&gx, &gy);
        x -= 5;
        y -= 3;
        w = gx * w;
        h = gy * h;
    }

    dispButtonImage2((u16)(x + 10), (u16)(y + 5), 0x80, (s32)w, (s32)h, 0, id);
}

/* xb_OnlineDrawIcon 0x1203E1: a button icon at its normal size, in
 * colour set 1. */
void xb_OnlineDrawIcon(u16 x, u16 y, s32 icon) {
    f32 sx = D_002B4BE4;
    f32 sy = D_002B4BE4;
    f32 w;
    f32 h;

    if (xb_xlive_disp_IsEnabled()) {
        xb_xlive_disp_GetScale(&sx, &sy);
        x += 5;
        y += 3;
        w = sx * D_002B4BE4;
        h = sy * D_002B4BE4;
    } else {
        x += 10;
        y += 8;
        w = sy;
        h = sx;
    }

    switch (icon) {
    case 0:
        icon = 4;
        break;
    case 1:
        icon = 5;
        break;
    case 2:
        icon = 0;
        break;
    case 3:
        icon = 1;
        break;
    case 4:
        icon = 3;
        break;
    case 5:
        icon = 7;
        break;
    case 6:
        icon = 2;
        break;
    case 7:
        icon = 6;
        break;
    }

    dispButtonImage2(x, y, 0x80, (s32)w, (s32)h, 1, icon);
}

/* The start menu's help bar (window D_0041862C): the pad hint for the
 * page (xb_LiveWork_Get14) and the back hint; hidden while no pad is
 * connected. */
extern s32 D_0041862C;
extern char* D_007992E4;
extern char* D_00799310;
extern f32 D_002B8318;
extern f32 D_002B831C;
extern f32 D_002B8320;
extern f32 D_002B8324;
extern f32 D_002B4E00;
extern f32 D_002B4DDC;
extern f32 D_0025F370;
extern f32 D_002AEEA8;
extern f32 D_00219418;
extern f32 D_00219428;
s32 xb_LivePadConnected(void);
s32 xb_LiveWork_Get14(void);
s32 xb_xlive_disp_SetObj0C(s32 id, s32 v);
void xb_xlive_disp_DrawRectI(s32 font, f32 x, f32 y, f32 s, s32 text, f32 size, s32 flags, s32 c);

/* xb_OnlineMenuDraw 0x1131CB: 1 when drawn. */
s32 xb_OnlineMenuDraw(void) {
    if (xb_LivePadConnected() == 0) {
        if (xb_FindOnlineObj(D_0041862C) == 0) {
            D_0041862C = xb_xlive_disp_DrawRectF(D_002B8318, D_002B831C, D_002B4E00, D_002B8320, D_002B8324);
            xb_xlive_disp_SetObj0C(D_0041862C, 0xF8402020);
            xb_xlive_ResetObj(D_0041862C, 0);
            xb_xlive_SetObjFlag58(D_0041862C, 0);
        }

        switch (xb_LiveWork_Get14()) {
        case 0:
            xb_xlive_disp_DrawRectI(D_0041862C, D_00219418, D_002AEEA8, D_0025F370, (s32)D_007991FC, D_002B4BE4, 0, 0);
            break;
        case 1:
            xb_xlive_disp_DrawRectI(D_0041862C, D_00219418, D_002AEEA8, D_0025F370, (s32)D_00799118, D_002B4BE4, 0, 0);
            break;
        case 2:
            xb_xlive_disp_DrawRectI(D_0041862C, D_00219418, D_002AEEA8, D_0025F370, (s32)D_0079913C, D_002B4BE4, 0, 0);
            break;
        case 3:
            xb_xlive_disp_DrawRectI(D_0041862C, D_00219418, D_002AEEA8, D_0025F370, (s32)D_007992E4, D_002B4BE4, 0, 0);
            break;
        }

        xb_xlive_disp_DrawRectI(D_0041862C, D_00219428, D_002B4DDC, D_0025F370, (s32)D_00799310, D_002B4BE4, 0, 0);
        xb_xlive_SetObjFlag58(D_0041862C, 1);
        return 1;
    }

    xb_xlive_SetObjFlag58(D_0041862C, 0);
    return 0;
}

void xb_xlive_friend_Release(s32 id);
void XB_FASTCALL xb_XLIVE_FRIEND_CLASS_Session_Update(u8* self);

/* xb_XLIVE_STARTMENU_CLASS_ReleaseHandles 0x114E79: the start menu's
 * windows (+0x64, +0x68), the stats menu and the friend session closed,
 * and its page cleared. */
s32 XB_FASTCALL xb_XLIVE_STARTMENU_CLASS_ReleaseHandles(u8* self) {
    XB_ARG a;

    xb_xlive_friend_Release(*(s32*)(self + 0x64));
    *(s32*)(self + 0x64) = -1;
    xb_xlive_friend_Release(-1);
    *(s32*)(self + 0x64) = -1;
    xb_xlive_friend_Release(*(s32*)(self + 0x68));
    *(s32*)(self + 0x68) = -1;
    xb_XLIVE_STATMENU_CLASS_Release(D_00798CAC + 0x2544);
    xb_XLIVE_FRIEND_CLASS_Session_Update(D_00798CAC + 0x25D0);
    a.v = 0;
    ((void (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_STARTMENU_CLASS_Set6D)(self, a);
    self[0x6C] = 1;
    xb_XLIVE_PAGE_CLASS_Clear(self);
    return 0;
}

/* xb_XLIVE_STARTMENU_CLASS_Set74 0x113F0C. */
void XB_FASTCALL xb_XLIVE_STARTMENU_CLASS_Set74(u8* self, s32 edx, s32 v) {
    (void)edx;
    *(s32*)(self + 0x74) = v;
}

/* xb_XLIVE_STATMENU_CLASS_Set64 0x113F1A. */
void XB_FASTCALL xb_XLIVE_STATMENU_CLASS_Set64(u8* self, s32 edx, s32 v) {
    (void)edx;
    *(s32*)(self + 0x64) = v;
}

/* xlive_signon.cpp's player record (0xB0 bytes): cleared, with its stats
 * (+0x30) made. */
void XB_FASTCALL sub_00116D41(u8* self, s32 edx, s32 a);

/* xb_XLIVE_PLAYER_ctor 0x110CF4. */
u8* XB_FASTCALL xb_XLIVE_PLAYER_ctor(u8* self) {
    XB_ARG a;

    a.v = 0;
    ((void (XB_FASTCALL*)(u8*, XB_ARG))sub_00116D41)(self + 0x30, a);
    memset(self, 0, 12);
    *(u16*)(self + 0x10) = 0;
    *(s32*)(self + 0xA8) = 0;
    return self;
}

u32 XB_FASTCALL xb_LiveObj_Count(u8* self);
void XB_FASTCALL xb_deque_LiveObj_PopBack(u8* self);
extern char D_002B8240[];
extern char D_002B82B4[];
void _assert(const char* expr, const char* file, u32 line);

/* xb_XLIVE_SIGNON_DropPlayer 0x1116AC: with the two players of a match,
 * the second taken off the work's list (+0x28). 1, or -1 when there are
 * not two. A sign-on method; the object is not used. */
s32 XB_FASTCALL xb_XLIVE_SIGNON_DropPlayer(u8* self) {
    u8 rec[0xB0];
    u8* q;

    (void)self;
    xb_XLIVE_PLAYER_ctor(rec);

    if (xb_LiveObj_Count(D_00798CAC + 0x28) != 2) {
        _assert(D_002B82B4, D_002B8240, 0x60A);
    }

    q = D_00798CAC + 0x28;

    if (xb_LiveObj_Count(q) != 2) {
        return -1;
    }

    if (xb_LiveObj_Count(q) == 2) {
        xb_deque_LiveObj_PopBack(q);
    }

    return 1;
}

u8* XB_FASTCALL xb_deque_LiveObj_Subscript(u8* self, s32 edx, u32 i);

/* xb_XLIVE_SIGNON_SetPlayerA8 0x111735: player i's +0xA8. A sign-on
 * method; the object is not used. */
s32 XB_FASTCALL xb_XLIVE_SIGNON_SetPlayerA8(u8* self, s32 edx, u32 i, u32 v) {
    XB_ARG a;

    (void)self;
    (void)edx;
    a.v = i;
    *(u32*)(((u8* (XB_FASTCALL*)(u8*, XB_ARG))xb_deque_LiveObj_Subscript)(D_00798CAC + 0x28, a) + 0xA8) = v;
    return 1;
}

typedef struct {
    u32 w[3];
} XB_PEER12;

/* A deque iterator (two words). */
typedef struct {
    u32 w[2];
} XB_DQIT;
void** XB_FASTCALL xb_iterator_ctor(void** self, s32 edx, void* p);
XB_DQIT* XB_FASTCALL xb_deque_LiveObj_Begin(u8* self, s32 edx, XB_DQIT* out);
XB_DQIT* XB_FASTCALL xb_deque_LiveObj_End(u8* self, s32 edx, XB_DQIT* out);
s32 XB_FASTCALL xb_deque_iterator_ne(XB_DQIT* self, s32 edx, XB_DQIT* other);
void xb_deque_LiveObj_Find(XB_DQIT* out, XB_DQIT first, XB_DQIT last, void* key);
XB_DQIT* XB_FASTCALL xb_deque_LiveObj_Erase(u8* self, s32 edx, XB_DQIT* out, XB_DQIT where);
void XB_FASTCALL xb_deque_LiveObj_PushFront(u8* self, s32 edx, u8* rec);
void XB_FASTCALL xb_deque_LiveObj_PushBack(u8* self, s32 edx, u8* rec);

/* xb_XLIVE_WORK_CLASS_AddRecentPlayer 0x109BE2: a player put first in the
 * recent players (+0x3C, at most ten), taken out first if there. */
void XB_FASTCALL xb_XLIVE_WORK_CLASS_AddRecentPlayer(u8* self, s32 edx, u8* rec) {
    void* k;
    XB_DQIT r;
    XB_DQIT e1;
    XB_DQIT b1;
    XB_DQIT e2;
    void** pk;
    u8* q;
    XB_DQIT* e;
    XB_DQIT* b;
    XB_ARG a;
    XB_ARG c;

    (void)edx;
    a.v = (s32)rec;
    pk = ((void** (XB_FASTCALL*)(void**, XB_ARG))xb_iterator_ctor)(&k, a);
    q = self + 0x3C;
    a.v = (s32)&e2;
    e = ((XB_DQIT* (XB_FASTCALL*)(u8*, XB_ARG))xb_deque_LiveObj_End)(q, a);
    a.v = (s32)&e1;
    b = ((XB_DQIT* (XB_FASTCALL*)(u8*, XB_ARG))xb_deque_LiveObj_Begin)(q, a);
    xb_deque_LiveObj_Find(&r, *b, *e, *pk);
    a.v = (s32)&b1;
    a.v = (s32)((XB_DQIT* (XB_FASTCALL*)(u8*, XB_ARG))xb_deque_LiveObj_End)(D_00798CAC + 0x3C, a);

    if ((u8)((s32 (XB_FASTCALL*)(XB_DQIT*, XB_ARG))xb_deque_iterator_ne)(&r, a)) {
        a.v = (s32)&b1;
        ((XB_DQIT* (XB_FASTCALL*)(u8*, XB_ARG, XB_DQIT))xb_deque_LiveObj_Erase)(D_00798CAC + 0x3C, a, r);
    }

    if (xb_LiveObj_Count(q) >= 10) {
        xb_deque_LiveObj_PopBack(q);
    }

    c.v = (s32)rec;
    ((void (XB_FASTCALL*)(u8*, XB_ARG))xb_deque_LiveObj_PushFront)(q, c);
}

extern char D_002B82F4[];

/* xb_XLIVE_SIGNON_AddPlayer 0x112FFF: the opponent added as the match's
 * second player (one must be there): its player id, port, gamertag (as
 * wide characters), user and a setting; and remembered as a recent
 * player. 1, or -1. A sign-on method; the object is not used. */
s32 XB_FASTCALL xb_XLIVE_SIGNON_AddPlayer(u8* self, s32 edx, u32* port, XB_PEER12* peer, char* name, s32 user, s32 v) {
    u8 rec[0xB0];
    XB_ARG a;

    (void)self;
    (void)edx;
    xb_XLIVE_PLAYER_ctor(rec);

    if (xb_LiveObj_Count(D_00798CAC + 0x28) != 1) {
        _assert(D_002B82F4, D_002B8240, 0x5D3);
    }

    if (xb_LiveObj_Count(D_00798CAC + 0x28) != 1) {
        return -1;
    }

    *(XB_PEER12*)rec = *peer;
    *(u32*)(rec + 0xC) = *port;
    mbstowcs((u16*)(rec + 0x10), name, 0x10);
    *(s32*)(rec + 0xA0) = user;
    *(s32*)(rec + 0xA4) = 0;
    *(s32*)(rec + 0xA8) = v;
    a.v = (s32)rec;
    ((void (XB_FASTCALL*)(u8*, XB_ARG))xb_deque_LiveObj_PushBack)(D_00798CAC + 0x28, a);
    a.v = (s32)rec;
    ((void (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_WORK_CLASS_AddRecentPlayer)(D_00798CAC, a);
    return 1;
}

s32 flSetRenderState(s32 state, u32 value);
void sub_0004384A(void* a, void* b, void* c, void* d, void* e, void* f);

/* xb_DrawFramedQuad 0x11B032: a filled rectangle in col with a white
 * frame two pixels wide inside its edges. */
void xb_DrawFramedQuad(f32 x0, f32 y0, f32 x1, f32 y1, f32 z, u32 col) {
    XB_RECT16 r;
    s32 a;
    s32 b;

    flSetRenderState(0x6C, 0);
    b = 2;
    a = 2;
    sub_0004384A(&x0, &y0, &x1, &y1, &b, &a);
    r.x0 = (s32)x0;
    r.y0 = (s32)y0;
    r.x1 = (s32)x1;
    r.y1 = (s32)y1;
    r.col = col;
    xb_DrawQuadWithSavedStates(&r);
    r.col = 0xFFFFFFFF;
    r.x0 = (s32)x0;
    r.x1 = (s32)x0 + 2;
    r.y1 = (s32)y1;
    r.y0 = (s32)y0;
    xb_DrawQuadWithSavedStates(&r);
    r.x1 = (s32)x1;
    r.x0 = (s32)x1 - 2;
    xb_DrawQuadWithSavedStates(&r);
    r.x0 = (s32)x0;
    r.y0 = (s32)y0;
    r.y1 = (s32)y0 + 2;
    r.x1 = (s32)x1;
    xb_DrawQuadWithSavedStates(&r);
    r.y1 = (s32)y1;
    r.y0 = (s32)y1 - 2;
    xb_DrawQuadWithSavedStates(&r);
    flSetRenderState(0x6C, 1);
}

/* An XONLINES export not yet identified that takes a stats request (a
 * count, its specs, and two more words). */
s32 XB_STDCALL sub_001D5417(u32 n, void* specs, s32 a, s32 b);

/* xb_xlive_StatRequest 0x11B8E6: the request passed on; the task (the
 * fifth argument) is not. */
s32 xb_xlive_StatRequest(u32 n, void* specs, s32 a, s32 b, void* task) {
    (void)task;
    return sub_001D5417(n, specs, a, b);
}

/* The Live menus' stick directions: a push past 80 starts the repeat
 * timer (the other axis zeroed) and counts once, then the pad's repeat
 * bits do. */
void xb_LiveTimer_Start(void);
extern s32 D_0079A358;
extern s32 D_0079A35C;
extern s32 D_0079A364;

#define XB_PAD(off) (flpad_adr + xb_LiveWork_Get14() * 0x88 + (off))

/* xb_LivePadUp 0x1106E6. */
s32 xb_LivePadUp(void) {
    if (xb_LiveWork_Call113F24()) {
        return 0;
    }

    xb_LivePadLatch(1);

    if (D_0079A360 == 0 && *(s16*)XB_PAD(0x2E) < -0x50) {
        xb_LiveTimer_Start();
        *(s16*)XB_PAD(0x2C) = 0;
        D_0079A360 = 1;
        return 1;
    }

    xb_LivePadHeld();
    return *(s32*)XB_PAD(0x44) & 1;
}

/* xb_LivePadDown 0x110763. */
s32 xb_LivePadDown(void) {
    if (xb_LiveWork_Call113F24()) {
        return 0;
    }

    xb_LivePadLatch(2);

    if (D_0079A364 == 0 && *(s16*)XB_PAD(0x2E) > 0x50) {
        xb_LiveTimer_Start();
        *(s16*)XB_PAD(0x2C) = 0;
        D_0079A364 = 1;
        return 1;
    }

    xb_LivePadHeld();
    return *(s32*)XB_PAD(0x44) & 2;
}

/* xb_LivePadLeft 0x1107DC. */
s32 xb_LivePadLeft(void) {
    if (xb_LiveWork_Call113F24()) {
        return 0;
    }

    xb_LivePadLatch(4);

    if (D_0079A35C == 0 && *(s16*)XB_PAD(0x2C) < -0x50) {
        xb_LiveTimer_Start();
        *(s16*)XB_PAD(0x2E) = 0;
        D_0079A35C = 1;
        return 1;
    }

    xb_LivePadHeld();
    return *(s32*)XB_PAD(0x44) & 4;
}

/* xb_LivePadRight 0x110855. */
s32 xb_LivePadRight(void) {
    if (xb_LiveWork_Call113F24()) {
        return 0;
    }

    xb_LivePadLatch(8);

    if (D_0079A358 == 0 && *(s16*)XB_PAD(0x2C) > 0x50) {
        xb_LiveTimer_Start();
        *(s16*)XB_PAD(0x2E) = 0;
        D_0079A358 = 1;
        return 1;
    }

    xb_LivePadHeld();
    return *(s32*)XB_PAD(0x44) & 8;
}

/* xb_LivePadBack 0x1108FE: B or Back pressed. */
s32 xb_LivePadBack(void) {
    if (xb_LiveWork_Call113F24()) {
        return 0;
    }

    xb_LivePadLatch(0x4020);
    return *(s32*)XB_PAD(0x10) & 0x4020;
}

/* xb_LivePadTrigger 0x11055B: buttons of mask pressed; a direction in it
 * (the first of up, down, left, right) uses the stick as above and the
 * repeat bits. */
s32 xb_LivePadTrigger(s32 mask) {
    s32 up;

    if (xb_LiveWork_Call113F24()) {
        return 0;
    }

    xb_LivePadLatch(mask);
    up = mask & 1;

    if (up) {
        if (D_0079A360 == 0 && *(s16*)XB_PAD(0x2E) < -0x50) {
            xb_LiveTimer_Start();
            *(s16*)XB_PAD(0x2C) = 0;
            D_0079A360 = 1;
            return 1;
        }
    } else if (mask & 2) {
        if (D_0079A364 == 0 && *(s16*)XB_PAD(0x2E) > 0x50) {
            xb_LiveTimer_Start();
            *(s16*)XB_PAD(0x2C) = 0;
            D_0079A364 = 1;
            return 1;
        }
    } else if (mask & 4) {
        if (D_0079A35C == 0 && *(s16*)XB_PAD(0x2C) < -0x50) {
            xb_LiveTimer_Start();
            D_0079A35C = 1;
            *(s16*)XB_PAD(0x2E) = 0;
            return 1;
        }
    } else if (mask & 8) {
        if (D_0079A358 == 0 && *(s16*)XB_PAD(0x2C) > 0x50) {
            xb_LiveTimer_Start();
            D_0079A358 = 1;
            *(s16*)XB_PAD(0x2E) = 0;
            return 1;
        }
    }

    xb_LivePadHeld();

    if (up == 0 && (mask & 0xE) == 0) {
        return *(s32*)XB_PAD(0x10) & mask;
    }

    return *(s32*)XB_PAD(0x44) & mask;
}

/* xb_LivePadRepeat 0x110930: as xb_LivePadTrigger, always read, with the
 * stick's left and right swapped (4 right, 8 left). */
s32 xb_LivePadRepeat(s32 mask) {
    s32 up;

    xb_LivePadLatch(mask);
    up = mask & 1;

    if (up) {
        if (D_0079A360 == 0 && *(s16*)XB_PAD(0x2E) < -0x50) {
            xb_LiveTimer_Start();
            *(s16*)XB_PAD(0x2C) = 0;
            D_0079A360 = 1;
            return 1;
        }
    } else if (mask & 2) {
        if (D_0079A364 == 0 && *(s16*)XB_PAD(0x2E) > 0x50) {
            xb_LiveTimer_Start();
            *(s16*)XB_PAD(0x2C) = 0;
            D_0079A364 = 1;
            return 1;
        }
    } else if (mask & 4) {
        if (D_0079A35C == 0 && *(s16*)XB_PAD(0x2C) > 0x50) {
            xb_LiveTimer_Start();
            D_0079A35C = 1;
            *(s16*)XB_PAD(0x2E) = 0;
            return 1;
        }
    } else if (mask & 8) {
        if (D_0079A358 == 0 && *(s16*)XB_PAD(0x2C) < -0x50) {
            xb_LiveTimer_Start();
            D_0079A358 = 1;
            *(s16*)XB_PAD(0x2E) = 0;
            return 1;
        }
    }

    xb_LivePadHeld();

    if (up == 0 && (mask & 0xE) == 0) {
        return *(s32*)XB_PAD(0x10) & mask;
    }

    return *(s32*)XB_PAD(0x44) & mask;
}
