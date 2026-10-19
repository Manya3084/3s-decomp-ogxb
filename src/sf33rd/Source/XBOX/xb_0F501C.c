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
s32 XB_FASTCALL xb_XLIVE_STATMENU_CLASS_Init(u8* self);
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
s32 xb_xlive_NetStart(void);
s32 sub_0004AFFA(void);
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
/* The NetSync state: the socket, the state (D_007A7BC4), the last state,
 * a started flag and a timer. */
typedef struct {
    s32 sock;
    s32 state;
    s32 prev;
    u8 started;
    u8 pad[3];
    s16 timer;
    u16 timer2;
} XB_NSSTATE;
extern XB_NSSTATE D_007A7BC0;
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
s32 XB_FASTCALL xb_XLIVE_STARTMENU_CLASS_StatUpdate(u8* self);
s32 xb_LiveWork_Get2330(void);
s32 XB_FASTCALL xb_XLIVE_STARTMENU_CLASS_Update(u8* self);
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
    if (xb_NetSync_BuildRequest(D_007A7BC0.sock, D_007A7A0C) < 0) {
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

        if (xb_NetSync_BuildPacket(D_007A7BC0.sock, D_007A7A0C, 0) < 0) {
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
        if (xb_NetSync_FindEntry(D_007A7BC0.sock, D_007A7600, 0x400) < 0) {
            xb_NetSync_SetState(9);
            return;
        }

        xb_MsgQueuePush(D_007A7600);
    }

    while ((m = xb_MsgQueuePop()) != 0) {
        if (xb_NetSync_ParsePacket(D_007A7BC0.sock, D_007A7A0C, m) == 0x3210) {
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

/* xb_xlive_NetStart 0x1206D8 (Live callback 0, once the link is up):
 * NetSync started for two players on the link, its session key seeding
 * the random numbers (Random_ix16, Random_ix32); this console's settings
 * (D_007A6480: the permission switches, on only when every character
 * colour is, save_w[1].PL_Color[0] and its Pad_Infor buttons) set and the
 * other console's marked missing (0xFF), and the peers' records given to
 * NetSync to send and receive. */
extern s16 Random_ix16;
extern s16 Random_ix32;
extern u8 D_007A63A8;
u8* xb_xlive_net_GetLink(void);
u8* xb_xlive_net_Peer(s32 i);
void xb_NetSync_SetSendData(u8* p, u8* b, s32 size);
void xb_NetSync_SetRecvData(u8* p, u8* b, s32 size);
void xb_NetSync_Open(s8 n, s8 pl, s32 sock, s32 key, s32 pad, u16* outkey, u16* out2);

s32 xb_xlive_NetStart(void) {
    u8* link;
    u8* p0;
    u8* p1;
    s32 i;

    link = xb_xlive_net_GetLink();
    xb_NetSync_Open(2, link[0x20] & 1, *(s32*)(link + 0x30), *(s32*)(link + 0x28), xb_GetOnlineModeArg2(),
                    (u16*)&Random_ix16, (u16*)&Random_ix32);
    D_007A63A8 = D_007A7A0C;
    p0 = xb_xlive_net_Peer(0);
    p1 = xb_xlive_net_Peer(1);
    permission_player[0x18] = 0;
    permission_player[0x60] = 0;
    permission_player[0x78] = 0;

    for (i = 1; i < 0x14; i++) {
        if (save_w[0x234 + i] == 0) {
            break;
        }
    }

    if (i == 0x14) {
        permission_player[0x18] = 1;
        permission_player[0x60] = 1;
        permission_player[0x78] = 1;
    }

    for (i = 0; i < 0x14; i++) {
        D_007A6480[1].color[i] = 0xFF;
        D_007A6480[0].color[i] = 0xFF;
    }

    for (i = 0; i < 0x14; i++) {
        D_007A6480[*(s32*)(link + 0x20)].color[i] = save_w[0x234 + i];
    }

    for (i = 0; i < 8; i++) {
        D_007A6480[1].shot[i] = 0xFF;
        D_007A6480[0].shot[i] = 0xFF;
    }

    /* save_w[1].Pad_Infor[n].Shot */
    i = xb_GetOnlineModeArg2();
    *(s32*)&D_007A6480[*(s32*)(link + 0x20)].shot[0] = *(s32*)(save_w + 0x208 + i * 12);
    *(s32*)&D_007A6480[*(s32*)(link + 0x20)].shot[4] = *(s32*)(save_w + 0x20C + i * 12);
    D_007A6480[1].flag = 0xFF;
    D_007A6480[0].flag = 0xFF;
    D_007A6480[*(s32*)(link + 0x20)].flag = permission_player[0x18];
    xb_NetSync_SetRecvData(p0, p1, 0x1D);
    xb_NetSync_Check();
    xb_NetSync_SetFlag2(0);
    xb_NetSync_SetDone(0);
    xb_NetSync_SetSendData(p0, p1, 0x1D);
    return 0;
}

void xb_RegisterSaveHandlers(void) {
    xb_SetLiveCallback(0, (s32)xb_xlive_NetStart);
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
void XB_FASTCALL xb_xlive_stat_ctor(u8* self, s32 edx, void* stats);

/* xb_XLIVE_PLAYER_ctor 0x110CF4. */
u8* XB_FASTCALL xb_XLIVE_PLAYER_ctor(u8* self) {
    XB_ARG a;

    a.v = 0;
    ((void (XB_FASTCALL*)(u8*, XB_ARG))xb_xlive_stat_ctor)(self + 0x30, a);
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

/* An XONLINES export not yet identified that takes a finished stats task
 * and the request again (its results). */
s32 XB_STDCALL sub_001D5422(s32 task, u32 n, void* specs, s32 a, s32 b);

/* xb_xlive_StatResults 0x11B870: the request's results read. */
s32 xb_xlive_StatResults(s32 task, u32 n, void* specs, s32 a, s32 b) {
    return sub_001D5422(task, n, specs, a, b);
}

/* xb_LivePadAccept 0x1108CE: A pressed (A and Start latched). */
s32 xb_LivePadAccept(void) {
    if (xb_LiveWork_Call113F24()) {
        return 0;
    }

    xb_LivePadLatch(0x8010);
    return *(s32*)XB_PAD(0x10) & 0x10;
}

/* xb_Handle_IsNull 0x12AA8: an online task handle not open. */
s32 XB_FASTCALL xb_Handle_IsNull(void* self) {
    return *(s32*)self == 0;
}

/* The same pad reads without the work's input check (the stats pages in a
 * match use them). */

/* xb_LivePadNewRaw 0x110AAF: buttons of mask newly pressed. */
s32 xb_LivePadNewRaw(s32 mask) {
    xb_LivePadLatch(mask);
    return *(s32*)XB_PAD(0x10) & mask;
}

/* xb_LivePadUpRaw 0x110AD3. */
s32 xb_LivePadUpRaw(void) {
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

/* xb_LivePadDownRaw 0x110B44. */
s32 xb_LivePadDownRaw(void) {
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

/* xb_LivePadLeftRaw 0x110BB1. */
s32 xb_LivePadLeftRaw(void) {
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

/* xb_LivePadRightRaw 0x110C1E. */
s32 xb_LivePadRightRaw(void) {
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

/* An XONLINES export not yet identified, given a stats write request. */
s32 XB_STDCALL sub_001D540C(u32 n, void* specs, s32 a, s32 b);

/* xb_xlive_StatWrite 0x11B889: the request passed on; the task (the
 * fifth argument) is not. */
s32 xb_xlive_StatWrite(u32 n, void* specs, s32 a, s32 b, void* task) {
    (void)task;
    return sub_001D540C(n, specs, a, b);
}

/* Two more XONLINES exports not yet identified: a leaderboard enumeration
 * (user, count, start rank, board, stats, task) and its results. */
s32 XB_STDCALL sub_001D5431(void* user, s32 a, s32 rank, s32 board, u32 n, void* stats, s32 ev, void* task);
s32 XB_STDCALL sub_001D5440(s32 task, u32 nrows, void* rows, u32 nstats, void* stats, void* a, void* count, s32 b, s32 c);

/* xb_xlive_StatEnumerate 0x11B89F. */
s32 xb_xlive_StatEnumerate(void* user, s32 a, s32 rank, s32 board, u32 n, void* stats, s32 ev, void* task) {
    return sub_001D5431(user, a, rank, board, n, stats, ev, task);
}

/* xb_xlive_StatEnumResults 0x11B8C1. */
s32 xb_xlive_StatEnumResults(s32 task, u32 nrows, void* rows, u32 nstats, void* stats, void* a, void* count, s32 b, s32 c) {
    return sub_001D5440(task, nrows, rows, nstats, stats, a, count, b, c);
}

void XBUtil_GetWide(const char* s, u16* out, s32 n);

/* xb_XLIVE_PLAYER_ctorFromRow 0x110D1A: a player record from a
 * leaderboard row (its user and gamertag) and its stats. */
u8* XB_FASTCALL xb_XLIVE_PLAYER_ctorFromRow(u8* self, s32 edx, u8* row, void* stats) {
    XB_ARG a;

    (void)edx;
    a.v = (s32)stats;
    ((void (XB_FASTCALL*)(u8*, XB_ARG))xb_xlive_stat_ctor)(self + 0x30, a);
    *(XB_PEER12*)self = *(XB_PEER12*)row;
    XBUtil_GetWide((char*)(row + 0xC), (u16*)(self + 0x10), 0x10);
    *(s32*)(self + 0xA8) = 0;
    return self;
}

s32 xb_xlive_disp_DrawRectF(f32 x, f32 y, f32 w, f32 h, f32 z);
s32 xb_xlive_disp_SetObj0C(s32 id, s32 v);
extern f32 D_002B4BEC;
extern f32 D_002B4DFC;
extern f32 D_002B4A34;
extern f32 D_002B4DE4;
extern f32 D_002B4D9C;
extern f32 D_002B4E00;
extern f32 D_002B4DDC;
extern f32 D_00219428;

/* xb_XLIVE_STATMENU_CLASS_Init 0x113448: the stats menu reset and its two
 * dark windows (+0x54 the menu, shorter in the offline build check
 * sub_0004AFFA, +0x60 the help) opened. */
s32 XB_FASTCALL xb_XLIVE_STATMENU_CLASS_Init(u8* self) {
    memset(self + 4, 0, 0x50);
    xb_xlive_friend_Release(*(s32*)(self + 0x54));
    xb_xlive_friend_Release(*(s32*)(self + 0x58));
    xb_xlive_friend_Release(*(s32*)(self + 0x5C));
    xb_xlive_friend_Release(*(s32*)(self + 0x60));
    *(s32*)(self + 0x54) = -1;
    *(s32*)(self + 0x58) = -1;
    *(s32*)(self + 0x5C) = -1;
    *(s32*)(self + 0x60) = xb_xlive_disp_DrawRectF(D_002B4BEC, D_002B4DFC, D_002B4A34, D_002B4DE4, D_002190A4);
    *(s32*)(self + 0x54) = xb_xlive_disp_DrawRectF(D_00219428, D_00219428, D_002B4E00,
                                                    sub_0004AFFA() ? D_002B4D9C : D_002B4DDC, D_002190A4);
    xb_xlive_disp_SetObj0C(*(s32*)(self + 0x54), 0xFF000000);
    xb_xlive_disp_SetObj0C(*(s32*)(self + 0x60), 0xFF000000);
    xb_OnlineObj_Move(*(s32*)(self + 0x54));
    xb_OnlineObj_Move(*(s32*)(self + 0x60));
    return 0;
}

s32 xb_LivePadRepeat(s32 mask);
void xb_SeSelectedThunk(void);
void xb_SeCursorMoveThunk(void);
s32 XB_FASTCALL xb_XLIVE_STATMENU_CLASS_Step5(u8* self);
s32 XB_FASTCALL xb_XLIVE_STATMENU_CLASS_Step6(u8* self);
extern s32 D_0079A3C4;

/* xb_XLIVE_STATMENU_CLASS_StepTimer 0x11502A: the stats menu once its
 * window is open: the choice (+8; two entries, one in the offline check)
 * with A and B, then the chosen page (6 or 5) until it ends. 1 when it
 * closes. */
s32 XB_FASTCALL xb_XLIVE_STATMENU_CLASS_StepTimer(u8* self) {
    s32 lim;
    s32 v;

    if (xb_OnlineObj_IsDone(*(s32*)(self + 0x54)) == 0) {
        return 0;
    }

    switch (*(s32*)(self + 4)) {
    case 0:
        D_0079A3C4 = sub_0004AFFA();
        (*(s32*)(self + 4))++;
        *(s32*)(self + 8) = 0;
    case 1:
        if (xb_LivePadRepeat(1)) {
            if (--*(s32*)(self + 8) < 0) {
                *(s32*)(self + 8) = 0;
            } else {
                xb_SeCursorMoveThunk();
            }
        } else if (xb_LivePadRepeat(2)) {
            (*(s32*)(self + 8))++;
            lim = 1 - D_0079A3C4;

            if (*(s32*)(self + 8) > lim) {
                *(s32*)(self + 8) = lim;
            } else {
                xb_SeCursorMoveThunk();
            }
        }

        if (xb_LivePadRepeat(0x10)) {
            if (*(s32*)(self + 0x64) == 0 && *(s32*)(self + 8) == 0) {
                return 0;
            }

            xb_OnlineObj_SetFlag(*(s32*)(self + 0x54), 0);
            xb_SeSelectedThunk();
            (*(s32*)(self + 4))++;
            *(s32*)(self + 0xC) = 0;
            *(s32*)(self + 0x10) = 0;
            return 0;
        }

        if (xb_LivePadRepeat(0x4020)) {
            xb_xlive_friend_Release(*(s32*)(self + 0x54));
            *(s32*)(self + 0x54) = -1;
            xb_xlive_friend_Release(*(s32*)(self + 0x60));
            *(s32*)(self + 0x60) = -1;
            xb_SeSelectedThunk();
            *(s32*)(self + 4) += 0x63;
            return 1;
        }

        return 0;
    case 2:
        switch (*(s32*)(self + 8)) {
        case 0:
            v = xb_XLIVE_STATMENU_CLASS_Step6(self);
            break;
        case 1:
            v = xb_XLIVE_STATMENU_CLASS_Step5(self);
            break;
        default:
            if (xb_LivePadRepeat(0x10)) {
                xb_SeSelectedThunk();
                (*(s32*)(self + 4))--;
            } else if (xb_LivePadRepeat(0x4020)) {
                xb_SeSelectedThunk();
                (*(s32*)(self + 4))--;
            }

            return 0;
        }

        if (v) {
            xb_OnlineObj_SetFlag(*(s32*)(self + 0x54), 1);
            (*(s32*)(self + 4))--;
        }

        return 0;
    }

    return 1;
}

u8* XB_FASTCALL xb_LiveWork_Get2408(u8* self);
s32 XB_FASTCALL xb_LiveObj_Process(u8* self, s32 edx, s32 arg);
u8* XB_FASTCALL xb_LiveObj_Get8(u8* self);
s32 XB_FASTCALL CXHVVoiceManager_SetVoiceThroughSpeakers(u8* self, s32 edx, s32 port, s32 on);
extern f32 D_002B4E98;

/* xb_XLIVE_STATMENU_CLASS_Step6 0x114707: the voice output page: through
 * the speakers or the headset (+0x10); A sets it (not the headset while
 * one is in use), B leaves. 1 when it closes. */
s32 XB_FASTCALL xb_XLIVE_STATMENU_CLASS_Step6(u8* self) {
    XB_ARG a;
    XB_ARG b;

    switch (*(s32*)(self + 0xC)) {
    case 0:
        *(s32*)(self + 0xC) = 1;
        *(s32*)(self + 0x10) = *(s32*)(xb_LiveWork_Get2408(D_00798CAC) + 0x94) == 0;
        *(s32*)(self + 0x5C) = xb_xlive_disp_DrawRectF(D_00219428, D_00219428, D_002B4E00, D_002B4E98, D_002190A4);
        xb_xlive_disp_SetObj0C(*(s32*)(self + 0x5C), 0xFF000000);
        xb_OnlineObj_Move(*(s32*)(self + 0x5C));
        xb_xlive_SetObjFlag58(*(s32*)(self + 0x60), 1);
    case 1:
        if (xb_OnlineObj_IsDone(*(s32*)(self + 0x5C)) == 0) {
            return 0;
        }

        if (xb_LivePadRepeat(1)) {
            if (--*(s32*)(self + 0x10) < 0) {
                *(s32*)(self + 0x10) = 0;
            } else {
                xb_SeCursorMoveThunk();
            }
        } else if (xb_LivePadRepeat(2)) {
            if (++*(s32*)(self + 0x10) > 1) {
                *(s32*)(self + 0x10) = 1;
            } else {
                xb_SeCursorMoveThunk();
            }
        }

        if (xb_LivePadRepeat(0x10)) {
            a.v = *(s32*)(D_00798CAC + 0x14);

            if (((s32 (XB_FASTCALL*)(u8*, XB_ARG))xb_LiveObj_Process)(xb_LiveWork_Get2408(D_00798CAC), a) != 2 ||
                *(s32*)(self + 0x10) != 1) {
                xb_SeSelectedThunk();

                if (*(s32*)(self + 0x10) == 0) {
                    a.v = *(s32*)(D_00798CAC + 0x14);
                    b.v = 1;
                    ((s32 (XB_FASTCALL*)(u8*, XB_ARG, XB_ARG))CXHVVoiceManager_SetVoiceThroughSpeakers)(
                        xb_LiveObj_Get8(xb_LiveWork_Get2408(D_00798CAC)), a, b);
                    *(s32*)(xb_LiveWork_Get2408(D_00798CAC) + 0x94) = 1;
                } else if (*(s32*)(self + 0x10) == 1) {
                    a.v = *(s32*)(D_00798CAC + 0x14);
                    b.v = 0;
                    ((s32 (XB_FASTCALL*)(u8*, XB_ARG, XB_ARG))CXHVVoiceManager_SetVoiceThroughSpeakers)(
                        xb_LiveObj_Get8(xb_LiveWork_Get2408(D_00798CAC)), a, b);
                    *(s32*)(xb_LiveWork_Get2408(D_00798CAC) + 0x94) = 0;
                }

                xb_xlive_friend_Release(*(s32*)(self + 0x5C));
                *(s32*)(self + 0x5C) = -1;
                *(s32*)(self + 0xC) = 0;
                return 1;
            }

            xb_SeSelectedThunk();
        }

        if (xb_LivePadRepeat(0x4020)) {
            xb_xlive_friend_Release(*(s32*)(self + 0x5C));
            *(s32*)(self + 0x5C) = -1;
            xb_SeSelectedThunk();
            *(s32*)(self + 0xC) = 0;
            return 1;
        }

        return 0;
    }

    return 1;
}

s32 XB_FASTCALL xb_iterator_Get4(u8* self);
s32 XB_STDCALL IXHVEngine__GetProcessingMode(s32 a, s32 b, s32 c);
s32 XB_FASTCALL xb_LiveObj_GetHandle50(u8* self);
void XB_FASTCALL xb_LiveObj_SetHandler(u8* self, s32 edx, s32 h);
s32 XB_FASTCALL xb_LiveObj_Call2(u8* self, s32 edx, s32 a, s32 b);
u8 XB_FASTCALL xb_LiveObj_IsReady(u8* self, s32 edx, s32 arg);
s32 xb_LivePadConnected(void);
extern s32 D_002BA81C;
extern f32 D_002B83C4;
extern f32 D_002B5068;
extern f32 D_002B4E9C;

#define XB_VOICE() xb_LiveWork_Get2408(D_00798CAC)
#define XB_USER() (*(s32*)(D_00798CAC + 0x14))
#define XB_SETMASK(m) (a.v = (m), ((void (XB_FASTCALL*)(u8*, XB_ARG))xb_LiveObj_SetHandler)(XB_VOICE(), a))
#define XB_SETMODE(m) (a.v = XB_USER(), b.v = (m), ((s32 (XB_FASTCALL*)(u8*, XB_ARG, XB_ARG))xb_LiveObj_Call2)(xb_LiveObj_Get8(XB_VOICE()), a, b))

/* xb_XLIVE_STATMENU_CLASS_Step5 0x114242: the voice mask page: the 17
 * masks (+0x10) in a window of 8 rows (row +0x74, top +0x7C), each tried
 * as it is chosen with the voice in its test mode (D_002BA81C; the old
 * mode +0x6C and mask +0x70 kept); A keeps it, B puts the old one back.
 * Without a headset it waits (2) until one is ready or B. 1 when it
 * closes. */
s32 XB_FASTCALL xb_XLIVE_STATMENU_CLASS_Step5(u8* self) {
    s32 r;
    XB_ARG a;
    XB_ARG b;

    switch (*(s32*)(self + 0xC)) {
    case 2:
        a.v = XB_USER();

        if (((u8 (XB_FASTCALL*)(u8*, XB_ARG))xb_LiveObj_IsReady)(XB_VOICE(), a)) {
            *(s32*)(self + 0xC) = 1;
            return 0;
        }

        if (xb_LivePadRepeat(0x4020) == 0) {
            return 0;
        }

        *(s32*)(self + 0x68) = 0;
        XB_SETMODE(*(s32*)(self + 0x6C));
        xb_xlive_friend_Release(*(s32*)(self + 0x58));
        *(s32*)(self + 0x58) = -1;
        xb_xlive_SetObjFlag58(*(s32*)(self + 0x60), 1);
        xb_SeSelectedThunk();
        *(s32*)(self + 0xC) = 0;
        return 1;
    case 0:
        r = 1;
        *(s32*)(self + 0xC) = 1;
        *(s32*)(self + 0x68) = 1;
        IXHVEngine__GetProcessingMode(xb_iterator_Get4(xb_LiveObj_Get8(XB_VOICE())), XB_USER(), (s32)(self + 0x6C));
        XB_SETMODE(D_002BA81C);
        *(s32*)(self + 0x10) = xb_LiveObj_GetHandle50(XB_VOICE());
        *(s32*)(self + 0x70) = xb_LiveObj_GetHandle50(XB_VOICE());
        *(s32*)(self + 0x80) = *(s32*)(self + 0x78);
        *(s32*)(self + 0x84) = *(s32*)(self + 0x7C);

        if (*(s32*)(self + 0x10) == 0) {
            *(s32*)(self + 0x74) = 0;
            *(s32*)(self + 0x7C) = 0;
        }

        *(s32*)(self + 0x58) = xb_xlive_disp_DrawRectF(D_002B83C4, D_00219428, D_002B5068, D_002B4E9C, D_002190A4);
        xb_xlive_disp_SetObj0C(*(s32*)(self + 0x58), 0xFF000000);
        xb_OnlineObj_Move(*(s32*)(self + 0x58));
        xb_xlive_SetObjFlag58(*(s32*)(self + 0x60), 0);
        break;
    case 1:
        r = 1;
        break;
    default:
        return 1;
    }

    if (xb_LivePadConnected()) {
        a.v = XB_USER();

        if (((u8 (XB_FASTCALL*)(u8*, XB_ARG))xb_LiveObj_IsReady)(XB_VOICE(), a) == 0) {
            *(s32*)(self + 0xC) = 2;
            return 0;
        }
    }

    if (xb_OnlineObj_IsDone(*(s32*)(self + 0x58)) == 0) {
        return 0;
    }

    if (xb_LivePadRepeat(r)) {
        if (--*(s32*)(self + 0x10) < 0) {
            *(s32*)(self + 0x10) = 0;
        } else {
            xb_SeCursorMoveThunk();
        }

        if (--*(s32*)(self + 0x74) < 0) {
            if (*(s32*)(self + 0x7C) < 9 || *(s32*)(self + 0x74) != -1) {
                *(s32*)(self + 0x74) = 0;

                if (*(s32*)(self + 0x7C) > 0) {
                    (*(s32*)(self + 0x7C))--;
                }
            }
        }

        *(s32*)(self + 0x78) = *(s32*)(self + 0x74);
        XB_SETMASK(*(s32*)(self + 0x10));
    } else if (xb_LivePadRepeat(2)) {
        if (++*(s32*)(self + 0x10) > 16) {
            *(s32*)(self + 0x10) = 16;
        } else {
            xb_SeCursorMoveThunk();
        }

        if (++*(s32*)(self + 0x74) > 7) {
            *(s32*)(self + 0x74) = 7;

            if (*(s32*)(self + 0x7C) < 9) {
                (*(s32*)(self + 0x7C))++;
            }
        }

        *(s32*)(self + 0x78) = *(s32*)(self + 0x74);

        if (*(s32*)(self + 0x7C) >= 9 && *(s32*)(self + 0x74) >= 7) {
            *(s32*)(self + 0x74) = 6;
        }

        XB_SETMASK(*(s32*)(self + 0x10));
    }

    if (xb_LivePadRepeat(4)) {
        if (*(s32*)(self + 0x7C) > 0) {
            xb_SeCursorMoveThunk();
        }

        *(s32*)(self + 0x7C) -= 8;

        if (*(s32*)(self + 0x7C) < 0) {
            *(s32*)(self + 0x7C) = 0;
        }

        if (*(s32*)(self + 0x74) == -1) {
            *(s32*)(self + 0x74) = 0;
        }

        *(s32*)(self + 0x10) = *(s32*)(self + 0x7C) + *(s32*)(self + 0x74);
        *(s32*)(self + 0x78) = *(s32*)(self + 0x74);
        XB_SETMASK(*(s32*)(self + 0x10));
    } else if (xb_LivePadRepeat(8)) {
        if (*(s32*)(self + 0x7C) < 9) {
            xb_SeCursorMoveThunk();
        }

        *(s32*)(self + 0x7C) += 8;

        if (*(s32*)(self + 0x7C) > 9) {
            *(s32*)(self + 0x7C) = 9;
        }

        *(s32*)(self + 0x10) = *(s32*)(self + 0x7C) + *(s32*)(self + 0x74);

        if (*(s32*)(self + 0x10) > 15) {
            *(s32*)(self + 0x74) = 6;
            *(s32*)(self + 0x10) = 15;
        }

        *(s32*)(self + 0x78) = *(s32*)(self + 0x74);
        XB_SETMASK(*(s32*)(self + 0x10));
        r = 1;
    }

    if (xb_LivePadRepeat(0x4020)) {
        *(s32*)(self + 0x68) = 0;
        XB_SETMODE(*(s32*)(self + 0x6C));
        XB_SETMASK(*(s32*)(self + 0x70));
        *(s32*)(self + 0x78) = *(s32*)(self + 0x80);
        *(s32*)(self + 0x74) = *(s32*)(self + 0x80);
        *(s32*)(self + 0x7C) = *(s32*)(self + 0x84);
        xb_xlive_friend_Release(*(s32*)(self + 0x58));
        *(s32*)(self + 0x58) = -1;
        xb_xlive_SetObjFlag58(*(s32*)(self + 0x60), r);
        xb_SeSelectedThunk();
        *(s32*)(self + 0xC) = 0;
        return r;
    }

    if (xb_LivePadRepeat(0x10)) {
        *(s32*)(self + 0x68) = 0;
        XB_SETMODE(*(s32*)(self + 0x6C));
        xb_xlive_friend_Release(*(s32*)(self + 0x58));
        *(s32*)(self + 0x58) = -1;
        xb_xlive_SetObjFlag58(*(s32*)(self + 0x60), r);
        xb_SeSelectedThunk();
        *(s32*)(self + 0xC) = 0;
        return r;
    }

    return 0;
}

void xb_xlive_disp_ScaleTime(void);
void XB_FASTCALL xb_XLIVE_WORK_CLASS_PollStatus(u8* self);
void XB_FASTCALL xb_XLIVE_WORK_CLASS_UpdateObj(u8* self);
s32 xb_LiveWork_CheckMode3DC(void);
s32 xb_LivePadActive(void);
s32 xb_LivePadButtons(s32 mask);
u8 xb_XLIVE_WORK_CLASS_IsHost(void);
void XB_FASTCALL xb_XLIVE_STARTMENU_CLASS_Reset(u8* self);
void XB_FASTCALL xb_XLIVE_STARTMENU_CLASS_Step1(u8* self);
void XB_FASTCALL xb_XLIVE_STARTMENU_CLASS_Step2(u8* self);
s32 XB_FASTCALL xb_XLIVE_STARTMENU_CLASS_Step4(u8* self);
void XB_FASTCALL xb_XLIVE_STARTMENU_CLASS_Countdown(u8* self);
s32 XB_FASTCALL xb_XLIVE_STATMENU_CLASS_Step3(u8* self);
s32 XB_FASTCALL xb_XLIVE_STATMENU_CLASS_StartRead(u8* self, s32 edx, u8 down);
void xb_xlive_disp_CheckHandle(s32* handle, f32 a, f32 b, f32 c, f32 d, f32 e);
s32 xb_OnlineObj_IsActive(s32 id);
extern s32 D_0079A3C8;
extern s32 D_00C7EA78;
extern s32 D_007A1398;
extern s32 D_002BA7A8;
extern s32 D_002BA734;
extern f32 D_00219424;
extern f32 D_002B5384;
extern f32 D_002B83D4;

/* xb_XLIVE_STARTMENU_CLASS_StatUpdate 0x115210: the in-game Live menu
 * (Start in an online match; +0x6C on): page +4 0 or 1 waits for Start
 * (L and R held a second open the stats instead), 2 is the menu (+8:
 * stats, friends, voice, the countdown and the options; fewer in the
 * offline check), 3 runs the choice (the host first puts its voice back),
 * 4 closes and 5 resets. 1 while the work is busy. */
s32 XB_FASTCALL xb_XLIVE_STARTMENU_CLASS_StatUpdate(u8* self) {
    s32 mode;
    s32 lim;
    XB_ARG a;
    XB_ARG b;

    xb_xlive_disp_ScaleTime();
    xb_XLIVE_WORK_CLASS_PollStatus(D_00798CAC);

    if (xb_XLIVE_STARTMENU_CLASS_Get70(self) && xb_LivePadActive()) {
        a.v = 0;
        ((void (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_STARTMENU_CLASS_Set70)(self, a);
    }

    if (self[0x6C] != 1) {
        return 0;
    }

    xb_XLIVE_WORK_CLASS_UpdateObj(D_00798CAC);
    *(s32*)(self + 0x5C) = *(s32*)(self + 0x58);
    *(s32*)(self + 0x58) = xb_LiveWork_CheckMode3DC();

    if (*(s32*)(self + 0x5C) | *(s32*)(self + 0x58)) {
        return 1;
    }

    if (*(s32*)(self + 0x80) != 0) {
        xb_XLIVE_STARTMENU_CLASS_ReleaseHandles(self);
        *(s32*)(self + 0x80) = 0;
    }

    switch (*(s32*)(self + 4)) {
    case 0:
        *(s32*)(self + 4) = 1;
        D_0079A3C8 = sub_0004AFFA() * 3;
    case 1:
        if (*(s32*)(self + 0x74) == 1) {
            if (xb_LivePadButtons(0x1000)) {
                if (*(s32*)(self + 0x78) < 60) {
                    (*(s32*)(self + 0x78))++;
                }
            } else {
                *(s32*)(self + 0x78) = 0;
            }

            if (xb_LivePadButtons(0x2000)) {
                if (*(s32*)(self + 0x7C) < 60) {
                    (*(s32*)(self + 0x7C))++;
                }
            } else {
                *(s32*)(self + 0x7C) = 0;
            }
        }

        if (xb_LivePadPressed(0x8000)) {
            xb_xlive_disp_CheckHandle((s32*)(self + 0x68), D_00219428, D_00219428, D_002B4E00, D_00219424, 1.0f);
            xb_xlive_disp_SetObj0C(*(s32*)(self + 0x68), 0xFF000000);
            xb_xlive_ResetObj(*(s32*)(self + 0x68), 0);
            xb_xlive_SetObjFlag58(*(s32*)(self + 0x68), 0);
            xb_xlive_disp_CheckHandle((s32*)(self + 0x64), D_00219428, D_002B5384, D_002B4E00, D_002B83D4, 1.0f);
            xb_xlive_disp_SetObj0C(*(s32*)(self + 0x64), 0xFF000000);
            xb_OnlineObj_Move(*(s32*)(self + 0x64));
            *(s32*)(self + 0x60) = 0;
            xb_SeSelectedThunk();
            a.v = 1;
            ((void (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_STARTMENU_CLASS_Set6D)(self, a);
            (*(s32*)(self + 4))++;
            break;
        }

        if (*(s32*)(self + 0x7C) >= 60 && xb_LivePadRepeat(0x1000)) {
            if (*(s32*)(self + 0x74) != 1) {
                break;
            }

            a.v = 0;
        } else {
            if (*(s32*)(self + 0x78) < 60 || xb_LivePadRepeat(0x2000) == 0 || *(s32*)(self + 0x74) != 1) {
                break;
            }

            a.v = 1;
        }

        if (((s32 (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_STATMENU_CLASS_StartRead)(D_00798CAC + 0x2544, a)) {
            *(s32*)(self + 0x60) = 0x1E;
        }

        break;
    case 2:
        if (xb_OnlineObj_IsActive(*(s32*)(self + 0x64)) == 0) {
            break;
        }

        if (xb_XLIVE_WORK_CLASS_IsHost() == 0) {
            lim = 4 - D_0079A3C8;

            if (xb_LivePadRepeat(1)) {
                xb_SeCursorMoveThunk();

                if (--*(s32*)(self + 8) < 0) {
                    *(s32*)(self + 8) = lim;
                }
            } else if (xb_LivePadRepeat(2)) {
                xb_SeCursorMoveThunk();

                if (++*(s32*)(self + 8) > 4 - D_0079A3C8) {
                    *(s32*)(self + 8) = 0;
                }
            }

            if (xb_LivePadRepeat(0x10)) {
                xb_OnlineObj_SetFlag(*(s32*)(self + 0x64), 0);
                xb_SeSelectedThunk();
                (*(s32*)(self + 4))++;
                *(s32*)(self + 0xC) = 0;

                if (*(s32*)(self + 8) == 4) {
                    xb_xlive_SetObjFlag58(*(s32*)(self + 0x68), 1);
                }
            } else if (xb_LivePadPressedConfirm()) {
                a.v = 1;
                ((void (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_STARTMENU_CLASS_Set70)(self, a);
                xb_OnlineObj_Fade(*(s32*)(self + 0x64));
                xb_SeSelectedThunk();
                *(s32*)(self + 4) = 4;
            }

            break;
        }

        goto reset;
    case 3:
        if (xb_XLIVE_WORK_CLASS_IsHost()) {
            if (*(s32*)(D_00798CAC + 0x25AC) != 0) {
                *(s32*)(D_00798CAC + 0x25AC) = 0;
                XB_SETMODE(*(s32*)(D_00798CAC + 0x25B0));
                XB_SETMASK(*(s32*)(D_00798CAC + 0x25B4));
            }

            IXHVEngine__GetProcessingMode(xb_iterator_Get4(xb_LiveObj_Get8(XB_VOICE())), XB_USER(), (s32)&mode);

            if (mode == D_002BA7A8) {
                XB_SETMODE(D_002BA734);
            }

        reset:
            xb_XLIVE_STARTMENU_CLASS_Reset(self);
        }

        if (sub_0004AFFA()) {
            switch (*(s32*)(self + 8)) {
            case 0:
                xb_XLIVE_STARTMENU_CLASS_Countdown(self);
                break;
            case 1:
                xb_XLIVE_STARTMENU_CLASS_Step4(self);
                break;
            case 2:
                *(s32*)(self + 4) -= 2;
                break;
            }
        } else {
            switch (*(s32*)(self + 8)) {
            case 0:
                xb_XLIVE_STARTMENU_CLASS_Step1(self);
                break;
            case 1:
                xb_XLIVE_STARTMENU_CLASS_Step2(self);
                break;
            case 2:
                if (xb_XLIVE_STATMENU_CLASS_Step3(D_00798CAC + 0x2544)) {
                    goto done;
                }

                break;
            case 3:
                xb_XLIVE_STARTMENU_CLASS_Countdown(self);
                break;
            case 4:
                if (xb_XLIVE_STARTMENU_CLASS_Step4(self)) {
                done:
                    xb_OnlineObj_SetFlag(*(s32*)(self + 0x64), 1);
                    xb_SeSelectedThunk();
                    *(s32*)(self + 4) = 2;
                }

                break;
            case 5:
                *(s32*)(self + 4) -= 2;
                break;
            }
        }

        break;
    case 4:
        if (xb_OnlineObj_IsDone(*(s32*)(self + 0x64)) || *(s32*)(self + 0x64) == -1) {
            (*(s32*)(self + 4))++;
        }

        break;
    case 5:
        *(s32*)(self + 4) = 1;
        *(s32*)(self + 0xC) = 0;
        xb_XLIVE_STARTMENU_CLASS_ReleaseHandles(self);
        D_00C7EA78 = 0;
        a.v = 0;
        ((void (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_STARTMENU_CLASS_Set6D)(self, a);
        D_007A1398 = 1;
        break;
    }

    return 0;
}

s32 XB_FASTCALL xb_XLIVE_STAT_CLASS_Clear(u8* self);
void XB_FASTCALL xb_XLIVE_FRIEND_CLASS_Session_Update(u8* self);
s32 XB_FASTCALL xb_XLIVE_FRIEND_CLASS_Session_Step(u8* self, s32 edx, s32 mode);
void XB_FASTCALL xb_XLIVE_FRIEND_CLASS_Session_SetArgs(u8* self, s32 edx, s32 a, s32 b);
s32 XB_FASTCALL xb_xlive_main_Update(u8* self);

/* xb_XLIVE_STARTMENU_CLASS_Reset 0x114FA3: the start menu back to its
 * choice: the stats pages, the friend session and the stats menu closed,
 * the windows hidden, the friend pages from the top. */
void XB_FASTCALL xb_XLIVE_STARTMENU_CLASS_Reset(u8* self) {
    XB_ARG a;
    XB_ARG b;

    *(s32*)(self + 4) = 3;
    xb_XLIVE_STAT_CLASS_Clear(D_00798CAC + 0x5090);
    xb_XLIVE_FRIEND_CLASS_Session_Update(D_00798CAC + 0x25D0);
    a.v = 0;
    ((s32 (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_FRIEND_CLASS_Session_Step)(D_00798CAC + 0x25D0, a);
    xb_xlive_SetObjFlag58(*(s32*)(self + 0x64), 0);
    xb_xlive_SetObjFlag58(*(s32*)(self + 0x68), 0);
    xb_XLIVE_STATMENU_CLASS_Release(D_00798CAC + 0x2544);
    *(s32*)(self + 8) = 1;
    *(s32*)(self + 0xC) = 1;
    a.v = 0x1E;
    b.v = 0x1E;
    ((void (XB_FASTCALL*)(u8*, XB_ARG, XB_ARG))xb_XLIVE_FRIEND_CLASS_Session_SetArgs)(D_00798CAC + 0x25D0, a, b);
}

/* xb_XLIVE_STARTMENU_CLASS_Step1 0x11334B: the friends page (session mode
 * 3) run until it ends (its window shown) or fails (the menu reset). */
void XB_FASTCALL xb_XLIVE_STARTMENU_CLASS_Step1(u8* self) {
    s32 v;
    XB_ARG a;

    switch (*(s32*)(self + 0xC)) {
    case 0:
        *(s32*)(self + 0xC) = 1;
        a.v = 3;
        ((s32 (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_FRIEND_CLASS_Session_Step)(D_00798CAC + 0x25D0, a);
    case 1:
        v = xb_xlive_main_Update(D_00798CAC + 0x25D0);

        if (v == -1) {
            xb_xlive_friend_Release(*(s32*)(self + 0x64));
            *(s32*)(self + 0x64) = -1;
            *(s32*)(self + 0xC) = 0;
            *(s32*)(self + 4) = 1;
        } else if (v == 1) {
            xb_OnlineObj_SetFlag(*(s32*)(self + 0x64), 1);
            (*(s32*)(self + 0xC))++;
        }

        break;
    default:
        (*(s32*)(self + 4))--;
        break;
    }
}

/* xb_XLIVE_STARTMENU_CLASS_Step2 0x1133B8: the same for the players page
 * (session mode 0); afterwards the session closed. */
void XB_FASTCALL xb_XLIVE_STARTMENU_CLASS_Step2(u8* self) {
    s32 v;
    XB_ARG a;

    switch (*(s32*)(self + 0xC)) {
    case 0:
        *(s32*)(self + 0xC) = 1;
        a.v = 0;
        ((s32 (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_FRIEND_CLASS_Session_Step)(D_00798CAC + 0x25D0, a);
    case 1:
        v = xb_xlive_main_Update(D_00798CAC + 0x25D0);

        if (v == -1) {
            xb_xlive_friend_Release(*(s32*)(self + 0x64));
            *(s32*)(self + 0x64) = -1;
            *(s32*)(self + 0xC) = 0;
            *(s32*)(self + 4) = 1;
        } else if (v == 1) {
            xb_xlive_SetObjFlag58(*(s32*)(self + 0x64), 1);
            xb_OnlineObj_SetFlag(*(s32*)(self + 0x64), 1);
            (*(s32*)(self + 0xC))++;
        }

        break;
    default:
        (*(s32*)(self + 4))--;
        xb_XLIVE_FRIEND_CLASS_Session_Update(D_00798CAC + 0x25D0);
        break;
    }
}

/* xb_XLIVE_STATMENU_CLASS_StartRead 0x114639: the voice mask stepped one
 * back (down 0) or on (1), wrapping, from the in-game menu's L and R. 0
 * without a ready headset. */
s32 XB_FASTCALL xb_XLIVE_STATMENU_CLASS_StartRead(u8* self, s32 edx, u8 down) {
    s32 v;
    XB_ARG a;

    (void)edx;

    if (xb_LivePadConnected()) {
        a.v = XB_USER();

        if (((u8 (XB_FASTCALL*)(u8*, XB_ARG))xb_LiveObj_IsReady)(XB_VOICE(), a) == 0) {
            return 0;
        }
    }

    v = xb_LiveObj_GetHandle50(XB_VOICE());
    *(s32*)(self + 0x10) = v;

    if (down == 0) {
        if (--*(s32*)(self + 0x74) < 0) {
            *(s32*)(self + 0x74) = 0;

            if (*(s32*)(self + 0x7C) > 0) {
                (*(s32*)(self + 0x7C))--;
            }
        }

        *(s32*)(self + 0x10) = --v;

        if (v < 0) {
            *(s32*)(self + 0x10) = 16;
            *(s32*)(self + 0x74) = 7;
            *(s32*)(self + 0x7C) = 9;
            goto set;
        }
    } else {
        if (++*(s32*)(self + 0x74) > 7) {
            *(s32*)(self + 0x74) = 7;

            if (*(s32*)(self + 0x7C) < 9) {
                (*(s32*)(self + 0x7C))++;
            }
        }

        *(s32*)(self + 0x10) = ++v;

        if (v > 16) {
            *(s32*)(self + 0x10) = 0;
            *(s32*)(self + 0x74) = 0;
            *(s32*)(self + 0x7C) = 0;
            goto set;
        }
    }

    xb_SeCursorMoveThunk();
set:
    XB_SETMASK(*(s32*)(self + 0x10));
    return 1;
}

/* xb_XLIVE_STATMENU_CLASS_Step3 0x11353B: the appear-online page: online
 * or offline (+0x10, bit 1 of the user's state +0x144 cleared or set);
 * A sets it, B leaves. 1 when it closes. */
s32 XB_FASTCALL xb_XLIVE_STATMENU_CLASS_Step3(u8* self) {
    switch (*(s32*)(self + 0xC)) {
    case 0:
        xb_XLIVE_STATMENU_CLASS_Init(self);
        (*(s32*)(self + 0xC))++;
        *(s32*)(self + 0x10) = (u8)~D_00798CAC[0x144] & 1;
        *(s32*)(self + 0x5C) = xb_xlive_disp_DrawRectF(D_00219428, D_00219428, D_002B4E00, D_002B4E98, D_002190A4);
        xb_xlive_disp_SetObj0C(*(s32*)(self + 0x5C), 0xFF000000);
        xb_OnlineObj_Move(*(s32*)(self + 0x5C));
        xb_xlive_SetObjFlag58(*(s32*)(self + 0x54), 0);
    case 1:
        if (xb_OnlineObj_IsDone(*(s32*)(self + 0x5C)) == 0) {
            return 0;
        }

        if (xb_LivePadRepeat(1)) {
            if (--*(s32*)(self + 0x10) < 0) {
                *(s32*)(self + 0x10) = 0;
            } else {
                xb_SeCursorMoveThunk();
            }
        } else if (xb_LivePadRepeat(2)) {
            if (++*(s32*)(self + 0x10) > 1) {
                *(s32*)(self + 0x10) = 1;
            } else {
                xb_SeCursorMoveThunk();
            }
        }

        if (xb_LivePadRepeat(0x10)) {
            xb_SeSelectedThunk();

            if (*(s32*)(self + 0x10) == 0) {
                *(u32*)(D_00798CAC + 0x144) |= 1;
            } else {
                *(u32*)(D_00798CAC + 0x144) &= ~1;
            }

            xb_xlive_friend_Release(*(s32*)(self + 0x5C));
            *(s32*)(self + 0x5C) = -1;
            xb_xlive_friend_Release(*(s32*)(self + 0x60));
            *(s32*)(self + 0x60) = -1;
        } else if (xb_LivePadRepeat(0x4020)) {
            xb_xlive_friend_Release(*(s32*)(self + 0x5C));
            *(s32*)(self + 0x5C) = -1;
            xb_xlive_friend_Release(*(s32*)(self + 0x60));
            *(s32*)(self + 0x60) = -1;
            xb_SeSelectedThunk();
        } else {
            return 0;
        }

        *(s32*)(self + 0xC) = 0;
        return 1;
    }

    return 1;
}

/* xb_LiveObj_Get54 0xFC51F: the voice object's +0x54. */
s32 XB_FASTCALL xb_LiveObj_Get54(u8* self) {
    return *(s32*)(self + 0x54);
}

/* The NetSync engine: one state routine (D_0041890C) a frame, given the
 * state (D_007A7BC0: the socket, the state, the last state, a started
 * flag and a timer). The players (D_007A7A0A of them, this console
 * D_007A7A0C, the ones still in the match the mask D_007A7A08) first
 * swap their settings and data (states 1 and 2), get ready (3), time
 * their pings (4) and start (5); in a match (6) each frame's pad is
 * queued (D_007A7BE0) and sent, and a frame is played once every
 * player's pad for it is in (D_007A6540, 64 frames a player). The
 * frames sent ahead (D_007A7A13, 6 to 16) and the resend timers adapt
 * to how often a frame is ready. Errors end in state 9, a closed link
 * in 10. The step's result is D_0079AF00 (1 when a frame was played). */
typedef struct {
    u16 frame;
    u16 pad;
    u16 sw0;
    u16 sw1;
    u32 data[2];
} XB_NSFRAME;
s32 xb_NetSync_BuildData(s32 sock, s8 pl, u8 flag);
s32 xb_NetSync_SendPing(s32 sock, s8 pl);
s32 xb_NetSync_SendFrames(s32 sock, u8 pl);
s32 xb_NetSync_SendSync(s32 sock, s8 pl);
s32 xb_NetSync_CanQueue(void);
s32 xb_NetSync_QueueFrame(u8 pl);
s32 xb_NetSync_CheckLag(s32 sock, s8 pl);
void xb_NetSync_CalcLatency(void);
s32 xb_NetSync_AdvanceFrame(s8 pl);
s32 xb_NetSync_GetDesync(void);
void xb_MsgQueueInit(void);
extern s32 D_0079AF00;
extern void (*D_0041890C[])(XB_NSSTATE* st);
extern s32 D_007A7A00[0x2B];
extern s32 D_007A7A04;
extern s16 D_007A7A08;
extern u8 D_007A7A0B;
extern s16 D_007A7A0E;
extern s8 D_007A7A10;
extern s8 D_007A7A11;
extern s8 D_007A7A12;
extern s8 D_007A7A13;
extern s8 D_007A7A14;
extern u8 D_007A7A1D;
extern u8 D_007A7A1E;
extern u16 D_007A7A20[4];
extern u16 D_007A7A28;
extern u16 D_007A7A2A;
extern u16 D_007A7A2C;
extern u16 D_007A7A2E;
extern u16 D_007A7A30;
extern u16 D_007A7A32;
extern u16 D_007A7A34;
extern u16 D_007A7A36;
extern s32 D_007A7A3C;
extern s32 D_007A7A40;
extern s32 D_007A7A44;
extern s32 D_007A7A48;
extern s32 D_007A7A4C;
extern s32 D_007A7A50;
extern s32 D_007A7A54;
extern u16 D_007A7A58;
extern u16 D_007A7A5C;
extern u16 D_007A7A5E;
extern s16 D_007A7A60;
extern s16 D_007A7A62;
extern u16 D_007A7A64;
extern u16 D_007A7A66;
extern u8 D_007A7A68;
extern s32 D_007A7A6C;
extern u8* D_007A7A70;
extern u8* D_007A7A74;
extern s32 D_007A7A78;
extern s32 D_007A7A7C;
extern u8* D_007A7A88;
extern s32 D_007A7A8C;
extern s32 D_007A7A90;
extern s32 D_007A7A94[2];
extern s32 D_007A7A9C[2];
extern u16* D_007A7AA4;
extern u16* D_007A7AA8;
extern s32 D_007A7AAC;
extern u8 D_007A7AE0[16];
extern u8 D_007A7AEC;
extern u8 D_007A7AEE;
extern s8 D_007A7AF0;
extern u16 D_007A7AF2;
extern u32 D_007A7AF8[2];
extern s8 D_007A7B00;
extern u16 D_007A7B20[4][16];
extern u16 D_007A7BA0[4];
extern XB_NSFRAME D_007A7BE0[16];
extern u16 D_007A7CE0;
extern u16 D_007A7CE2;
extern s8 D_007A64C0[16];
extern s32 D_007A64D4;
extern u16 D_007A64D8;
extern u16 D_007A64DA;
extern u16 D_007A64DC;
extern u16 D_007A64E0[4];
extern u16 D_007A6520;
extern XB_NSFRAME D_007A6540[4][64];
extern u8 D_007A7540[0x14];
extern s32 D_007A7548;
extern u8 D_007A7560[0x28];
extern u16 D_007A75A0[16];
extern u8 D_007A75C0[0x28];
extern u16 D_007A75E8;
extern u8 D_007A75F0[8];
extern u16 D_007A75F4;
extern f32 D_002190AC;
extern f32 D_002B4E30;

void xb_NetSync_ClearBuffers(void);

/* xb_NetSync_Open 0x11B95C: the engine started on a socket for n players
 * (this console pl), the session's key byte (never 0, 0x40 or 0xC0; it is
 * written to *key) and the local pad's index, with no frames ahead yet:
 * state 2. */
void xb_NetSync_Open(s8 n, s8 pl, s32 sock, s32 key, s32 pad, u16* outkey, u16* out2) {
    xb_NetSync_ClearBuffers();
    xb_MsgQueueInit();
    D_007A7A0A = n;
    D_007A7A0C = pl;
    D_007A7A10 = 2;
    D_007A7A13 = 6;
    D_007A7A12 = 6;
    D_007A7A14 = 0x10;
    D_007A7A0E = 0;
    D_007A7A0B = 0;
    D_007A7A68 = 0;
    D_007A7A08 = 0;
    D_007A7A1E = 0;
    D_007A7A1D = 0;
    D_007A7A58 = 0;
    D_007A7A5A = 0;
    D_007A7A5C = 0;
    D_007A7A5E = 0;
    D_007A7A60 = 0;
    D_007A7A62 = 0;
    D_007A7A64 = 0;
    D_007A7A4C = 0;
    D_007A7A48 = 0;
    D_007A7A66 = D_007A7548 / 100;
    D_007A7A90 = pad;
    memset(&D_007A7BC0, 0, 0x14);
    D_007A7BC0.sock = sock;
    memset(D_007A7B20, 0, sizeof(D_007A7B20));
    memset(D_007A64E0, 0, sizeof(D_007A64E0));
    memset(D_007A75A0, 0, 8);
    D_007A7A40 = 0;
    D_007A7A3C = 0;
    D_007A7A44 = 0x3C;
    D_007A7A50 = 0x1E;
    D_007A7A9C[1] = 0;
    D_007A7A9C[0] = 0;
    D_007A7A94[1] = 0;
    D_007A7A94[0] = 0;
    D_007A7A7C = 1;
    D_007A7A78 = 0;
    D_007A7A8C = 0;

    if ((u8)key == 0 || (u8)key == 0x40 || (u8)key == 0xC0) {
        key++;
    }

    if (outkey != 0) {
        *outkey = key;
    }

    if (out2 != 0) {
        *out2 = 0;
    }

    D_007A7AA4 = outkey;
    D_007A7AA8 = out2;
    xb_NetSync_SetState(2);
}

/* xb_NetSync_ClearBuffers 0x11B8FC: the engine's buffers cleared and its
 * socket closed (-1). */
void xb_NetSync_ClearBuffers(void) {
    memset(D_007A75C0, 0, sizeof(D_007A75C0));
    memset(D_007A7560, 0, sizeof(D_007A7560));
    memset(D_007A7AE0, 0, sizeof(D_007A7AE0));
    memset(D_007A7A00, 0, sizeof(D_007A7A00));
    memset(D_007A7600, 0, 0x400);
    memset(D_007A7540, 0, sizeof(D_007A7540));
    memset(D_007A75F0, 0, sizeof(D_007A75F0));
    memset(&D_007A7BC0, 0, 0x14);
    D_007A7BC0.sock = -1;
}

/* xb_NetSync_SetSendData 0x11BAD7: the data state 2 sends (size bytes at
 * p), and where the other console's goes (b). */
void xb_NetSync_SetSendData(u8* p, u8* b, s32 size) {
    D_007A7A6C = size;
    D_007A7A70 = p;
    D_007A7A74 = b;
}

/* xb_NetSync_SetRecvData 0x11BAF3: the settings message's data: this
 * console's (p, size bytes) and where the other console's goes (b). */
void xb_NetSync_SetRecvData(u8* p, u8* b, s32 size) {
    D_007A7A80 = size;
    D_007A7A84 = p;
    D_007A7A88 = b;
}

/* Two counters a player (0 or 1): -1 for other players. */
s32 xb_NetSync_GetCountA(s32 i) {
    if (i >= 0 && i < 2) {
        return D_007A7A94[i];
    }

    return -1;
}

s32 xb_NetSync_IncCountA(s32 i) {
    if (i >= 0 && i < 2) {
        return ++D_007A7A94[i];
    }

    return -1;
}

s32 xb_NetSync_GetCountB(s32 i) {
    if (i >= 0 && i < 2) {
        return D_007A7A9C[i];
    }

    return -1;
}

s32 xb_NetSync_IncCountB(s32 i) {
    if (i >= 0 && i < 2) {
        return ++D_007A7A9C[i];
    }

    return -1;
}

s32 xb_NetSync_ClearCountB(s32 i) {
    if (i >= 0 && i < 2) {
        D_007A7A9C[i] = 0;
        return 0;
    }

    return -1;
}

/* xb_NetSync_GetPadCallback 0x11BBAA: the local pad's reader. */
void* xb_NetSync_GetPadCallback(void) {
    return (void*)D_0079AF04;
}

/* xb_NetSync_GetDesync 0x11BBB0: the players whose pads disagreed. */
s32 xb_NetSync_GetDesync(void) {
    return D_007A7A1D;
}

/* xb_NetSync_Lerp 0x11BBB8: lo to hi by t of n (t capped at n), lo when
 * n is 0. Static: hi and n come in registers. */
s32 xb_NetSync_Lerp(s32 hi, s32 n, s32 lo, s32 t) {
    s32 d = hi - lo;

    if (n == 0) {
        return lo;
    }

    if (t > n) {
        t = n;
    }

    return d * t / n + lo;
}

/* xb_NetSync_CountBits 0x11BBDB: the low bits of mask that are set, up to
 * the first clear one. Static: mask comes in a register. */
s32 xb_NetSync_CountBits(u16 mask) {
    s32 n = 0;

    while (mask & 1) {
        n++;
        mask >>= 1;
    }

    return n;
}

/* xb_NetSync_CheckLag 0x11BC1F: each second's frame count (D_007A7A30)
 * kept in a ring of 16 (D_007A64C0); when the ring is full and at least 8
 * of them were 40 or more, with fewer than 5 of 57 or more, their average
 * is D_007A7B00, and under 54 the other console is told to slow down
 * (message 0x90). Returns 1 when sent, -1 on a send error. */
s32 xb_NetSync_CheckLag(s32 sock, s8 pl) {
    s32 hi;
    s32 sum;
    s32 i;
    s32 n;
    s32 v;
    s32 r;

    D_007A64C0[D_007A7AF0] = D_007A7A30;
    D_007A7AF0 = (D_007A7AF0 + 1) & 0xF;

    if (D_007A7AF0 != 0) {
        return 0;
    }

    hi = 0;
    sum = 0;
    n = 0;

    for (i = 0; i < 16; i++) {
        v = D_007A64C0[i];

        if (v >= 0x28) {
            sum += v;
            n++;

            if (v >= 0x39) {
                hi++;
            }
        }
    }

    if (n < 8 || hi >= 5) {
        return 0;
    }

    D_007A7B00 = sum / n;

    if (D_007A7B00 >= 0x36) {
        return 0;
    }

    D_007A7600[0] = 4;
    D_007A7600[1] = pl | 0x90;
    D_007A7600[2] = 0;
    D_007A7600[3] = 0;
    r = xb_NetSync_Send(sock, D_007A7600, 4);

    if (r != D_007A7600[0]) {
        xb_NetSync_SetPacketTarget(4, r);
        return -1;
    }

    return 1;
}

/* xb_NetSync_CalcLatency 0x11BCD7: each player's ping (D_007A7B20: three
 * averages, then 11 round trips) averaged, and the largest average
 * (D_007A7CE2), the largest best ping (D_007A7AF2) and the largest worst
 * ping (D_007A6520) kept. */
void xb_NetSync_CalcLatency(void) {
    u16 worst;
    u16 lo;
    u16 hi;
    s32 sum;
    s32 avg;
    s32 i;
    s32 j;
    s32 v;

    worst = 0;
    D_007A7AF2 = 0;
    D_007A6520 = 0;
    D_007A7CE2 = 0;

    for (i = 0; i < 4; i++) {
        if (D_007A7A08 & (1 << i)) {
            lo = 0xFF;
            hi = 0;
            sum = 0;

            for (j = 0; j < 11; j++) {
                v = D_007A7B20[i][3 + j] >> 1;

                if (v < lo) {
                    lo = v;
                } else if (v > hi) {
                    hi = v;
                }

                sum += v + 1;
            }

            avg = sum / 11;
            D_007A7B20[i][2] = avg;
            D_007A7B20[i][1] = avg;
            D_007A7B20[i][0] = avg;

            if (D_007A7CE2 < (u16)avg) {
                D_007A7CE2 = avg;
            }

            if (D_007A7AF2 < lo) {
                D_007A7AF2 = lo;
            }

            if (worst < hi) {
                worst = hi;
            }
        }
    }

    D_007A6520 = worst;
}

/* xb_NetSync_AdvanceFrame 0x11BDAD: plays the current frame (D_007A75E8)
 * once every player still in has sent it: this console's two words are
 * kept with it, the players whose pads for it disagree marked
 * (D_007A7A1D, shown in D_007A7A5E), each player's pad moved to the
 * last frame's (D_007A6500) and set from the frame (D_007A7AC0), and the
 * pad callback (D_0079AF08) run for each. Returns 1 when played. */
s32 xb_NetSync_AdvanceFrame(s8 pl) {
    u16 got;
    u16 k0;
    u16 k1;
    s32 n;
    s16 mask;
    u16 fr;
    s32 i;
    XB_NSFRAME* e;
    XB_NSFRAME* m;

    got = 0;
    k0 = 0;
    k1 = 0;

    if (D_007A7AA4 != 0) {
        k0 = *D_007A7AA4;
    }

    if (D_007A7AA8 != 0) {
        k1 = *D_007A7AA8;
    }

    n = D_007A7A0A;
    mask = D_007A7A08;
    fr = D_007A75E8;

    for (i = 0; i < n; i++) {
        if ((mask & (1 << i)) && D_007A7BA0[i] != fr) {
            got |= 1 << i;
        }
    }

    if ((got & mask) != mask) {
        return 0;
    }

    D_007A6540[pl][fr].sw0 = k0;
    D_007A6540[pl][fr].sw1 = k1;
    D_007A7A5E = 8;

    for (i = 0; i < n; i++) {
        if (pl != i && (mask & (1 << i)) && (((u8*)&D_007A6540[i][fr])[1] & 0x80)) {
            break;
        }
    }

    if (i == n) {
        D_007A7A1D = 0;

        for (i = 0; i < n; i++) {
            if (pl != i && (mask & (1 << i))) {
                e = &D_007A6540[i][fr];
                m = &D_007A6540[pl][e->frame];

                if (((u32)m->sw0 << 16 | m->sw1) != ((u32)e->sw0 << 16 | e->sw1)) {
                    D_007A7A1D |= 1 << i;
                }
            }
        }
    }

    if (D_007A7A1D != 0) {
        D_007A7A5E = (D_007A7A1D << 4) | 0xA;
    }

    for (i = 0; i < D_007A7A0A; i++) {
        *(XB_NETPAD*)&D_007A6500[i * 2] = D_007A7AC0[i];
        D_007A7AC0[i] = *(XB_NETPAD*)D_007A6540[i][fr].data;

        if (D_0079AF08 != 0) {
            ((void (*)(s32))D_0079AF08)(i);
            fr = D_007A75E8;
        }
    }

    D_007A7A04++;
    D_007A7A11--;
    D_007A7A30++;
    D_007A75E8 = (u16)(fr + 1) % 64;
    return 1;
}

/* xb_NetSync_Update 0x11BFDF: one step of the engine. In a match, the
 * frames sent ahead (D_007A7A13) go down when every frame of a period
 * (D_007A7A44) was played and up when too few were (D_007A7A50), each
 * period getting shorter after a change and longer after none. Returns
 * the step's result (D_0079AF00). */
s32 xb_NetSync_Update(void) {
    s32 chg;
    s32 due;
    s32 per;
    s32 per2;
    f32 f;

    D_0079AF00 = 0;
    D_0041890C[D_007A7BC4](&D_007A7BC0);

    if (D_007A64DC != 0) {
        D_007A64DC--;
    }

    if (D_007A7BC4 == 6) {
        chg = 0;
        due = 0;
        D_007A7A3C++;
        D_007A7A48++;

        if (D_0079AF00 == 1) {
            D_007A7A40++;
        } else {
            D_007A7A4C++;
        }

        per = D_007A7A44;

        if (D_007A7A3C >= per) {
            due = 1;

            if (D_007A7A40 == D_007A7A3C) {
                D_007A7A13--;
                chg = 1;
            }

            D_007A7A40 = 0;
            D_007A7A3C = 0;
        }

        per2 = D_007A7A50;

        if (D_007A7A48 >= per2) {
            due |= 2;
            f = per2 > 0 ? (f32)per2 : D_002190AC;

            if ((f32)D_007A7A4C * D_002B4E30 / f > D_002190A4 && D_007A7A48 != D_007A7A4C) {
                D_007A7A13++;
                chg |= 2;
            }

            D_007A7A4C = 0;
            D_007A7A48 = 0;
        }

        if (chg != 0) {
            if (D_007A7A13 < 6) {
                chg &= ~1;
                due &= ~1;
                D_007A7A13 = 6;
            }

            if (D_007A7A13 > 0x10) {
                chg &= ~2;
                due &= ~2;
                D_007A7A13 = 0x10;
            }
        }

        if (due & 1) {
            if (chg & 1) {
                D_007A7A54 = 0xB4;
                D_007A7A44 = per - 0x3C;

                if (D_007A7A44 <= 0x3C) {
                    D_007A7A44 = 0x3C;
                }
            } else {
                D_007A7A44 = per + 0x3C;

                if (D_007A7A44 >= 0x1E0) {
                    D_007A7A44 = 0x1E0;
                }
            }
        }

        if (due & 2) {
            if (chg & 2) {
                D_007A7A54 = 0xB4;
                D_007A7A50 = per2 - 0x1E;

                if (D_007A7A50 <= 0x1E) {
                    D_007A7A50 = 0x1E;
                }
            } else {
                D_007A7A50 = per2 + 0x1E;

                if (D_007A7A50 >= 0xF0) {
                    D_007A7A50 = 0xF0;
                }
            }
        }

        D_007A7A54--;
    }

    return D_0079AF00;
}

/* The state routines' common part: one received block queued when the
 * queue is empty (0 on a receive error). */
#define XB_NS_FILL(st_)                                                    \
    (xb_MsgQueueGetCount() != 0 ||                                         \
     (xb_NetSync_FindEntry((st_)->sock, D_007A7600, 0x400) >= 0 &&         \
      (xb_MsgQueuePush(D_007A7600), 1)))

/* xb_NetSync_StateSync 0x11C184 (state 1): waits up to a minute for the
 * other console's hello (0x3110: state 2). */
void xb_NetSync_StateSync(XB_NSSTATE* st) {
    u8* m;
    s32 r;

    D_0079AF00 = 0;

    if (st->started == 0) {
        st->started = 1;
        st->timer = 0xE10;
        D_007A7A66 = 0;
        D_007A7A64 = 0;
        D_007A7A62 = 0;
        D_007A7A60 = 0;
        D_007A7A5E = 0;
        D_007A7A5C = 0;
        D_007A7A5A = 0;
        D_007A7A58 = 0;
        return;
    }

    if (--st->timer < 0) {
        xb_NetSync_SetState(9);
        xb_NetSync_SetPacketTarget(0xA, 0);
        return;
    }

    if (!XB_NS_FILL(st)) {
        xb_NetSync_SetState(9);
        return;
    }

    while ((m = xb_MsgQueuePop()) != 0) {
        r = xb_NetSync_ParsePacket(st->sock, D_007A7A0C, m);

        if (r == 0x3110) {
            xb_NetSync_SetState(2);
            return;
        }

        if (r == 0x3210) {
            xb_NetSync_SetState(10);
            return;
        }
    }
}

/* xb_NetSync_StateData 0x11C26B (state 2): sends this console's data each
 * half second until every player has answered (state 3). */
void xb_NetSync_StateData(XB_NSSTATE* st) {
    u8* m;

    D_0079AF00 = 0;

    if (st->started == 0) {
        st->started = 1;
        st->timer = 0xE10;
        return;
    }

    if (--st->timer < 0) {
        xb_NetSync_SetState(9);
        xb_NetSync_SetPacketTarget(0xB, 0);
        return;
    }

    if (st->timer % 30 == 0 && xb_NetSync_BuildData(st->sock, D_007A7A0C, 0) < 0) {
        xb_NetSync_SetState(9);
        return;
    }

    if (!XB_NS_FILL(st)) {
        xb_NetSync_SetState(9);
        return;
    }

    while ((m = xb_MsgQueuePop()) != 0) {
        if (xb_NetSync_ParsePacket(st->sock, D_007A7A0C, m) == 0x3210) {
            xb_NetSync_SetState(10);
            return;
        }
    }

    if (xb_NetSync_CountBits(D_007A7A08) == D_007A7A0A) {
        xb_NetSync_SetState(3);
    }
}

/* xb_NetSync_StateReady 0x11C353 (state 3): the players to wait for
 * (D_007A7A0E) cleared, message 0x30 sent, and state 4 once each has
 * answered. */
void xb_NetSync_StateReady(XB_NSSTATE* st) {
    u8* m;
    s32 r;
    s32 i;

    D_0079AF00 = 0;

    if (st->started == 0) {
        st->started = 1;
        st->timer = 0xE10;

        if (D_007A7A0E != 0) {
            for (i = 0; i < D_007A7A0A; i++) {
                if (D_007A7A0E & (1 << i)) {
                    D_007A64E0[i] = 0;
                    memset(D_007A7B20[i], 0, sizeof(D_007A7B20[i]));
                    memset(D_007A75A0, 0, sizeof(D_007A75A0));
                }
            }
        }

        if (xb_NetSync_BuildPacket(st->sock, D_007A7A0C, 0) < 0) {
            xb_NetSync_SetState(9);
        }

        return;
    }

    if (--st->timer < 0) {
        xb_NetSync_SetState(9);
        xb_NetSync_SetPacketTarget(0x12, 0);
        return;
    }

    if (!XB_NS_FILL(st)) {
        xb_NetSync_SetState(9);
        return;
    }

    while ((m = xb_MsgQueuePop()) != 0) {
        r = xb_NetSync_ParsePacket(st->sock, D_007A7A0C, m);

        if (r == 0x3210) {
            xb_NetSync_SetState(10);
            return;
        }

        if ((u8)(r & 0xF0) == 0x30) {
            i = r & 0xF;
            D_007A64E0[i] = 0;
            memset(D_007A7B20[i], 0, sizeof(D_007A7B20[i]));
            memset(D_007A75A0, 0, sizeof(D_007A75A0));

            if ((u16)(D_007A7A08 & D_007A7A0E) == (u16)D_007A7A08) {
                xb_NetSync_SetState(4);
                D_007A7A0E = 0;
                return;
            }
        }
    }
}

/* xb_NetSync_StatePing 0x11C4CE (state 4): pings sent every
 * D_007A7A10 frames, 16 in all, their send times kept (D_007A75A0), until
 * each player has answered 16 (D_007A64E0); then the pings are averaged
 * and state 5. */
void xb_NetSync_StatePing(XB_NSSTATE* st) {
    u8* m;
    s32 i;

    D_0079AF00 = 0;

    if (st->started == 0) {
        st->started = 1;
        st->timer = 0xE10;
        D_007A7AAC = 0;
        D_007A64D4 = 0;
        D_007A7CE0 = 0;
        D_007A7AF2 = 0;
        D_007A6520 = 0;
        D_007A7CE2 = 0;

        if (D_007A7AEE == 1 && D_007A7A0A <= (s8)D_007A7A0C) {
            goto done;
        }

        if (xb_NetSync_SendPing(st->sock, D_007A7A0C) < 0) {
            goto error;
        }

        D_007A64D4++;
        return;
    }

    D_007A7AAC++;

    if (--st->timer < 0) {
        xb_NetSync_SetState(9);
        xb_NetSync_SetPacketTarget(0xC, 0);
        return;
    }

    if (++D_007A7CE0 >= D_007A7A10) {
        D_007A7CE0 = 0;

        if ((u32)D_007A64D4 < 0x10) {
            if (xb_NetSync_SendPing(st->sock, D_007A7A0C) < 0) {
                goto error;
            }

            D_007A75A0[D_007A64D4++] = D_007A7AAC;
        }
    }

    if (!XB_NS_FILL(st)) {
        goto error;
    }

    while ((m = xb_MsgQueuePop()) != 0) {
        if (xb_NetSync_ParsePacket(st->sock, D_007A7A0C, m) == 0x3210) {
            xb_NetSync_SetState(10);
            return;
        }
    }

    for (i = 0; i < D_007A7A0A; i++) {
        if (i != (s8)D_007A7A0C && D_007A64E0[i] < 0x10) {
            return;
        }
    }

done:
    xb_NetSync_CalcLatency();
    xb_NetSync_SetState(5);
    return;
error:
    xb_NetSync_SetState(9);
}

/* xb_NetSync_StateStart 0x11C65C (state 5): as state 3 for the frames
 * (D_007A6540, D_007A7BA0); once each player has answered, the match
 * (state 6) with the timers reset. */
void xb_NetSync_StateStart(XB_NSSTATE* st) {
    u8* m;
    s32 r;
    s32 i;

    D_0079AF00 = 0;

    if (st->started == 0) {
        st->started = 1;
        st->timer = 0xE10;

        if (D_007A7A0E != 0) {
            for (i = 0; i < D_007A7A0A; i++) {
                if (D_007A7A0E & (1 << i)) {
                    D_007A7BA0[i] = 0;
                    memset(D_007A6540[i], 0, sizeof(D_007A6540[i]));
                }
            }
        }

        if (xb_NetSync_BuildPacket(st->sock, D_007A7A0C, 0) < 0) {
            xb_NetSync_SetState(9);
        }

        return;
    }

    if (--st->timer < 0) {
        xb_NetSync_SetState(9);
        xb_NetSync_SetPacketTarget(0x12, 1);
        return;
    }

    if (!XB_NS_FILL(st)) {
        xb_NetSync_SetState(9);
        return;
    }

    while ((m = xb_MsgQueuePop()) != 0) {
        r = xb_NetSync_ParsePacket(st->sock, D_007A7A0C, m);

        if (r == 0x3210) {
            xb_NetSync_SetState(10);
            return;
        }

        if ((u8)(r & 0xF0) == 0x30) {
            i = r & 0xF;
            D_007A7BA0[i] = 0;
            memset(D_007A6540[i], 0, sizeof(D_007A6540[i]));

            if ((u16)(D_007A7A08 & D_007A7A0E) == (u16)D_007A7A08) {
                xb_NetSync_SetState(6);
                D_007A7A0E = 0;
                D_007A7A4C = 0;
                D_007A7A48 = 0;
                D_007A7A40 = 0;
                D_007A7A3C = 0;
                D_007A7A44 = 0x3C;
                D_007A7A50 = 0x1E;
                return;
            }
        }
    }
}

/* xb_NetSync_StateGame 0x11C7F4 (state 6): the match. Each second the
 * lag is checked and the counters rolled over; the frames since each
 * player was last heard from are counted (D_007A7A20, D_007A7A28; 10
 * seconds is an error, 15 seconds with none played closes the link); the
 * local pad queued, the queue sent when full or each second; the
 * messages read; and a frame played when it can be. */
void xb_NetSync_StateGame(XB_NSSTATE* st) {
    u8* m;
    s32 r;
    s32 i;

    D_0079AF00 = 0;

    if (st->started == 0) {
        st->started = 1;
        memset(D_007A7BE0, 0, sizeof(D_007A7BE0));
        memset(D_007A7AF8, 0, sizeof(D_007A7AF8));
        memset(D_007A64C0, 0, sizeof(D_007A64C0));
        D_007A7A00[0] = 0;
        D_007A7A04 = 0;
        D_007A7A11 = 0;
        D_007A7A38 = 0;
        D_007A7A36 = 0;
        D_007A7A34 = 0;
        D_007A7A32 = 0;
        D_007A7A30 = 0;
        D_007A7A2E = 0;
        D_007A7A2C = 0;
        memset(D_007A7A20, 0, 8);
        D_007A75E8 = 0;
        D_007A64DA = 0;
        D_007A64D8 = 0;
        D_007A7B00 = 0;
        D_007A7AF0 = 0;
        D_007A64DC = 0;
        D_007A7A28 = 0;
        D_007A7A2A = 0;
        return;
    }

    ((s32 (*)(s32, u8*))sub_0004AFFA)(st->sock, D_007A75F0);

    if (++D_007A7A2E >= 0x3C) {
        D_007A7A2E = 0;

        if (xb_NetSync_CheckLag(st->sock, D_007A7A0C) == -1) {
            goto error;
        }

        D_007A7A2C = D_007A7A30;
        D_007A7A32 = D_007A7A34;
        D_007A7A30 = 0;
        D_007A7A34 = 0;
        D_007A7A36 = D_007A7A38;
        D_007A7A38 = 0;
    }

    for (i = 0; i < D_007A7A0A; i++) {
        if (i != (s8)D_007A7A0C && (D_007A7A08 & (1 << i))) {
            D_007A7A20[i]++;
        }
    }

    if (D_007A7A62 < ++D_007A7A28) {
        D_007A7A62 = D_007A7A28;
    }

    D_007A7A2A++;

    if (D_007A7A28 > 0x258 && D_007A75F4 < 0xFE0) {
        D_007A7AEC = 1;
        xb_NetSync_SetState(9);
        xb_NetSync_SetPacketTarget(0x10, D_007A7A28);
        return;
    }

    if (D_007A7A2A > 0x384) {
        xb_NetSync_SetState(10);
        xb_NetSync_SetPacketTarget(0x11, D_007A7A2A);
        return;
    }

    D_007A64D8++;

    if (xb_NetSync_CanQueue()) {
        xb_NetSync_QueueFrame(D_007A7A0C);
    }

    if (D_007A7A10 <= D_007A64DA) {
        if (xb_NetSync_SendFrames(st->sock, D_007A7A0C) < 0) {
            goto error;
        }

        D_007A64D8 = 0;
    } else if (D_007A64D8 >= 0x3C) {
        if (xb_NetSync_SendSync(st->sock, D_007A7A0C) < 0) {
            goto error;
        }

        D_007A64D8 = 0;
    }

    if (!XB_NS_FILL(st)) {
        goto error;
    }

    while ((m = xb_MsgQueuePop()) != 0) {
        r = xb_NetSync_ParsePacket(st->sock, D_007A7A0C, m);

        if (r == 0x3210) {
            xb_NetSync_SetState(10);
            return;
        }

        if ((r & 0xF0) == 0x20 || (r & 0xF0) == 0x70 || (r & 0xF0) == 0xF0) {
            D_007A7A20[r & 0xF] = 0;
            D_007A7A28 = 0;
        }
    }

    if (xb_NetSync_AdvanceFrame(D_007A7A0C) == 1) {
        D_0079AF00 = 1;
        D_007A7A2A = 0;

        if (xb_NetSync_GetDesync()) {
            xb_NetSync_SetState(9);
            D_0079AF00 = 0;
        }
    }

    return;
error:
    xb_NetSync_SetState(9);
}

/* xb_NetSync_StateDone 0x11CB1D (state 7): the players' buffers cleared;
 * result 1. */
void xb_NetSync_StateDone(XB_NSSTATE* st) {
    (void)st;

    if (D_007A7A0A > 0) {
        memset(D_007A75C0, 0, D_007A7A0A * 20);
        memset(D_007A7560, 0, D_007A7A0A * 20);
    }

    D_0079AF00 = 1;
}

/* xb_NetSync_StateResync 0x11CB69 (state 8): as state 3, back to state 5
 * when every player has answered, keeping the most time any took
 * (D_007A7A60). */
void xb_NetSync_StateResync(XB_NSSTATE* st) {
    u8* m;
    s32 r;

    D_0079AF00 = 0;

    if (st->started == 0) {
        st->started = 1;
        st->timer = 0xE10;

        if (xb_NetSync_BuildPacket(st->sock, D_007A7A0C, 0) < 0) {
            xb_NetSync_SetState(9);
        }

        return;
    }

    if (--st->timer < 0) {
        xb_NetSync_SetState(9);
        xb_NetSync_SetPacketTarget(0xE, 0);
        return;
    }

    if (!XB_NS_FILL(st)) {
        xb_NetSync_SetState(9);
        return;
    }

    while ((m = xb_MsgQueuePop()) != 0) {
        r = xb_NetSync_ParsePacket(st->sock, D_007A7A0C, m);

        if (r == 0x3210) {
            xb_NetSync_SetState(10);
            return;
        }

        if ((u8)(r & 0xF0) == 0x30 && (u16)(D_007A7A0E & D_007A7A08) == (u16)D_007A7A08) {
            xb_NetSync_SetState(5);
            D_007A7A0E = 0;

            if (D_007A7A60 < st->timer) {
                D_007A7A60 = st->timer;
            }

            return;
        }
    }
}

/* xb_NetSync_StateError 0x11CC78 (state 9): result -1, the silence
 * counters cleared. */
void xb_NetSync_StateError(XB_NSSTATE* st) {
    (void)st;
    D_0079AF00 = -1;
    memset(D_007A7A20, 0, 8);
    D_007A7A28 = 0;
    D_007A7A2A = 0;
}

/* xb_NetSync_StateClosed 0x11CC9B (state 10): result -1. */
void xb_NetSync_StateClosed(XB_NSSTATE* st) {
    (void)st;
    D_0079AF00 = -1;
}

/* xb_NetSync_StateIdle 0x11CCA3 (states 0, 11 to 13): result 0. */
void xb_NetSync_StateIdle(XB_NSSTATE* st) {
    (void)st;
    D_0079AF00 = 0;
}

/* xb_NetSync_GetProgress 0x11CCAB: the connection's progress (0 to
 * 10000, D_007A7A8C) for the status bar: it creeps up 5 a frame inside
 * the range of the current state, which the state's own progress (the
 * players heard from, the pings answered) moves up. */
s32 xb_NetSync_GetProgress(void) {
    s32 lo;
    s32 hi;
    s32 sum;
    s32 n;
    s32 i;

    D_007A7A8C += 5;

    if (D_007A7BC4 >= 5) {
        lo = 10000;
        hi = 10000;
    } else if (D_007A7BC4 >= 4) {
        sum = 0;
        n = 0;

        for (i = 0; i < D_007A7A0A; i++) {
            if (i != (s8)D_007A7A0C) {
                sum += D_007A64E0[i];
                n += 0x10;
            }
        }

        hi = 10000;
        lo = xb_NetSync_Lerp(10000, n, 8000, sum);
    } else if (D_007A7BC4 >= 3) {
        hi = 8000;
        n = D_007A7A0A;
        lo = xb_NetSync_Lerp(8000, n, 6000, xb_NetSync_CountBits(D_007A7A0E));
    } else if (D_007A7BC4 >= 2) {
        hi = 6000;
        n = D_007A7A0A;
        lo = xb_NetSync_Lerp(6000, n, 4000, xb_NetSync_CountBits(D_007A7A08));
    } else {
        hi = 4000;
        lo = xb_NetSync_Lerp(4000, D_007A7A7C, 0, D_007A7A78);
    }

    if (D_007A7A8C < lo) {
        D_007A7A8C = lo;
    }

    if (D_007A7A8C > hi) {
        D_007A7A8C = hi;
    }

    return D_007A7A8C;
}

/* xb_MsgQueueInit 0x11CDA9: the message queue emptied. */
void xb_MsgQueueInit(void) {
    D_0079B710 = 0;
    D_0079B714 = 0;
    memset(D_0079AF10, 0, sizeof(D_0079AF10));
    D_00418944 = D_0079AF10;
    D_00418948 = D_0079AF10;
}

/* xb_NetSync_CanQueue 0x11D123: whether fewer frames are ahead
 * (D_007A7A11) than may be (D_007A7A13). */
s32 xb_NetSync_CanQueue(void) {
    if ((s8)D_007A7A0C < 0 || D_007A7A0A <= (s8)D_007A7A0C) {
        return 0;
    }

    return D_007A7A11 < D_007A7A13;
}

/* xb_NetSync_QueueFrame 0x11D149: the local pad (from the pad callback)
 * queued for sending (D_007A7BE0, up to D_007A7A10 a packet) for the next
 * frame, as two bytes (0x280) when it is the same as the last one, else
 * the frame's number, the two words and the pad, big-endian. */
s32 xb_NetSync_QueueFrame(u8 pl) {
    u32 d[2];
    u16 k0;
    u16 k1;
    XB_NSFRAME* e;
    void (*cb)(u8, u32*);

    (void)pl;
    k0 = 0;
    k1 = 0;
    cb = (void (*)(u8, u32*))xb_NetSync_GetPadCallback();

    if (D_007A7AA4 != 0) {
        k0 = *D_007A7AA4;
    }

    if (D_007A7AA8 != 0) {
        k1 = *D_007A7AA8;
    }

    if (cb != 0) {
        cb((u8)D_007A7A90, d);
    }

    if (D_007A64DA < D_007A7A10) {
        e = &D_007A7BE0[D_007A64DA];

        if (memcmp(D_007A7AF8, d, sizeof(d)) == 0) {
            e->frame = 0x280;
        } else {
            e->data[0] = d[0];
            e->data[1] = d[1];
            e->frame = ((D_007A75E8 >> 8) & 0x7F) | (u16)(D_007A75E8 << 8);
            e->sw0 = (k0 >> 8) | (u16)(k0 << 8);
            e->sw1 = (k1 >> 8) | (u16)(k1 << 8);
        }

        D_007A64DA++;
        D_007A7A00[0]++;
        D_007A7A11++;
        D_007A7AF8[0] = d[0];
        D_007A7AF8[1] = d[1];
    }

    return 0;
}

/* xb_NetSync_SendFrames 0x11D21F: the queued frames sent to player pl as
 * message 0x20 and queued as received. Returns 1, -1 on a send error. */
s32 xb_NetSync_SendFrames(s32 sock, u8 pl) {
    u32 off;
    u32 len;
    u16 w;
    s32 r;
    s32 i;

    off = 0;

    for (i = 0; i < D_007A64DA; i++) {
        w = D_007A7BE0[i].frame;

        if ((s8)w < 0) {
            len = ((w & 0x7F) << 8) | (w >> 8);
        } else {
            len = 0x10;
        }

        memcpy(D_007A7600 + 2 + off, &D_007A7BE0[i], len);
        off += len;
    }

    D_007A7600[0] = off + 2;
    D_007A7600[1] = pl | 0x20;
    memset(D_007A7600 + 2 + off, 0, 1);
    r = xb_NetSync_Send(sock, D_007A7600, D_007A7600[0]);

    if (r != D_007A7600[0]) {
        xb_NetSync_SetPacketTarget(4, r);
        return -1;
    }

    D_007A7A34 += r;
    D_007A64DA = 0;
    xb_MsgQueuePush(D_007A7600);
    return 1;
}

/* xb_NetSync_SendSync 0x11D2EB: the current frame's number sent to
 * player pl (message 0x70). Returns 1, -1 on a send error. */
s32 xb_NetSync_SendSync(s32 sock, s8 pl) {
    s32 r;

    if (pl < 0 || D_007A7A0A <= pl) {
        return 0;
    }

    D_007A7600[1] = pl | 0x70;
    D_007A7600[0] = 4;
    D_007A7600[2] = D_007A75E8 >> 8;
    D_007A7600[3] = D_007A75E8;
    r = xb_NetSync_Send(sock, D_007A7600, 4);

    if (r != D_007A7600[0]) {
        xb_NetSync_SetPacketTarget(4, r);
        return -1;
    }

    D_007A7A34 += r;
    return 1;
}

/* xb_NetSync_BuildData 0x11D354: unless flag is set, this console's data
 * (D_007A7A70, D_007A7A6C bytes) sent to player pl in 64-byte parts
 * (message 0xB0); then message 0x10 with the flag, which is queued. */
s32 xb_NetSync_BuildData(s32 sock, s8 pl, u8 flag) {
    s32 n;
    s32 i;
    s32 off;
    s32 len;
    s32 r;

    if (pl < 0 || D_007A7A0A <= pl) {
        return 0;
    }

    if (flag == 0) {
        n = D_007A7A6C / 64;

        if (D_007A7A6C % 64 > 0) {
            n++;
        }

        for (i = 0, off = 0; i < n; i++, off += 64) {
            len = D_007A7A6C - off;

            if (len > 64) {
                len = 64;
            }

            D_007A7600[0] = ((len & 1) ? len + 1 : len) + 6;
            D_007A7600[1] = pl | 0xB0;
            D_007A7600[2] = n;
            D_007A7600[3] = i;
            D_007A7600[4] = 0x40;
            D_007A7600[5] = len;

            if (len > 0) {
                memcpy(D_007A7600 + 6, D_007A7A70 + off, len);
            }

            r = xb_NetSync_Send(sock, D_007A7600, D_007A7600[0]);

            if (r != D_007A7600[0]) {
                xb_NetSync_SetPacketTarget(4, r);
                return -1;
            }
        }
    }

    D_007A7600[0] = 4;
    D_007A7600[1] = pl | 0x10;
    D_007A7600[2] = flag;
    D_007A7600[3] = 0;
    r = xb_NetSync_Send(sock, D_007A7600, 4);
    memset(D_007A7600 + 4, 0, 1);

    if (r != D_007A7600[0]) {
        xb_NetSync_SetPacketTarget(4, r);
        return -1;
    }

    xb_MsgQueuePush(D_007A7600);
    return 0;
}

/* xb_NetSync_SendPing 0x11D4B6: ping number D_007A64D4 sent to player pl
 * (message 0x50), padded to 16 bytes a frame ahead. */
s32 xb_NetSync_SendPing(s32 sock, s8 pl) {
    s32 r;

    if (pl < 0 || D_007A7A0A <= pl) {
        return 0;
    }

    D_007A7600[0] = D_007A7A10 * 16 + 4;
    D_007A7600[1] = pl | 0x50;
    D_007A7600[2] = 0;
    D_007A7600[3] = D_007A64D4;
    r = xb_NetSync_Send(sock, D_007A7600, D_007A7600[0]);

    if (r != D_007A7600[0]) {
        xb_NetSync_SetPacketTarget(4, r);
        return -1;
    }

    return 0;
}

/* xb_NetSync_GetPacketTarget 0x11CEEA: why the link last failed (the
 * code xb_NetSync_SetPacketTarget kept). */
s32 xb_NetSync_GetPacketTarget(void) {
    return D_007A7A1C;
}

/* xb_xlive_NetUpdate 0x1209D8. */
s32 xb_xlive_NetUpdate(void) {
    return xb_NetSync_Update();
}

/* xb_xlive_PadBits 0x120845: the pad switches' direction and button bits
 * (all but 0x1000 and 0x2000) into a byte. */
void xb_xlive_PadBits(u32 sw, u8* out) {
    u32 r = 0;

    if (sw & 1) {
        r = 1;
    }

    if (sw & 2) {
        r |= 2;
    }

    if (sw & 4) {
        r |= 4;
    }

    if (sw & 8) {
        r |= 8;
    }

    if (sw & 0x10) {
        r |= 0x10;
    }

    if (sw & 0x20) {
        r |= 0x20;
    }

    if (sw & 0x40) {
        r |= 0x40;
    }

    if (sw & 0x80) {
        r |= 0x80;
    }

    if ((u16)sw & 0x100) {
        r |= 0x100;
    }

    if ((u16)sw & 0x200) {
        r |= 0x200;
    }

    if ((u16)sw & 0x400) {
        r |= 0x400;
    }

    if ((u16)sw & 0x800) {
        r |= 0x800;
    }

    if ((u16)sw & 0x4000) {
        r |= 0x4000;
    }

    if ((u16)sw & 0x8000) {
        r |= 0x8000;
    }

    *out = r;
}

/* xb_LiveWork_ClearStartMenu 0x113F4B and xb_LiveWork_ReleaseStartMenu
 * 0x11519D: the Live work's start menu (+0x24C0). */
void xb_LiveWork_ClearStartMenu(void) {
    xb_XLIVE_STARTMENU_CLASS_Clear(D_00798CAC + 0x24C0);
}

void xb_LiveWork_ReleaseStartMenu(void) {
    xb_XLIVE_STARTMENU_CLASS_ReleaseHandles(D_00798CAC + 0x24C0);
}

void* xb_GetMatchInfo(void);
void XB_FASTCALL xb_XLIVE_WORK_CLASS_ResetSessions(void* self);
void XB_FASTCALL xb_XLIVE_WORK_CLASS_Set2360(u8* self, s32 edx, s8 v);
s32 xb_xlive_SetObjFlag58(s32 id, s32 on);
void XB_FASTCALL xb_XLIVE_STARTMENU_CLASS_Set6E(u8* self, s32 edx, u8 v);
extern f32 D_002B8348;
extern f32 D_002B834C;
extern f32 D_002B82D8;
extern char D_002B8350[];
extern char D_0025CCA0[];

/* xb_XLIVE_STARTMENU_CLASS_Step4 0x113FA4: the start menu's "end the
 * match?" box (+0x68, step +0xC): A shows the leaving messages for half a
 * second each (+0x50), then the box fades and the match ends (the Live
 * work's sessions and the match info reset, and the select restarted,
 * +0x2360); B closes it (returns 1). */
s32 XB_FASTCALL xb_XLIVE_STARTMENU_CLASS_Step4(u8* self) {
    u8* info;
    XB_ARG a;
    XB_ARG b;

    switch (*(s32*)(self + 0xC)) {
    case 0:
        *(s32*)(self + 0xC) = 1;
        xb_xlive_SetObjFlag58(*(s32*)(self + 0x68), 1);
        /* fallthrough */
    case 1:
        if (xb_LivePadRepeat(0x10)) {
            xb_SeSelectedThunk();
            (*(s32*)(self + 0xC))++;
            *(s32*)(self + 0x50) = 0x1E;
            a.v = 1;
            ((void (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_STARTMENU_CLASS_Set6E)(self, a);
        } else if (xb_LivePadRepeat(0x4020)) {
            xb_OnlineObj_SetFlag(*(s32*)(self + 0x68), 0);
            xb_SeSelectedThunk();
            *(s32*)(self + 0xC) = 0;
            return 1;
        }

        xb_xlive_disp_DrawRectI(*(s32*)(self + 0x68), D_00219424, D_002B8348, D_0025F370, (s32)D_007992C4, D_002B4BE4, 0, 0);
        xb_xlive_disp_DrawRectI(*(s32*)(self + 0x68), D_002B831C, D_002B82D8, D_0025F370, (s32)D_00799210, D_002B4BE4, 4, 0);
        break;
    case 2:
        if (--*(s32*)(self + 0x50) <= 0) {
            *(s32*)(self + 0xC) = 3;
            *(s32*)(self + 0x50) = 0x1E;
        }

        xb_xlive_disp_DrawRectI(*(s32*)(self + 0x68), D_00219424, D_002B834C, D_0025F370, (s32)D_00799090, D_002B4BE4, 0, 0);
        break;
    case 3:
        if (--*(s32*)(self + 0x50) <= 0) {
            *(s32*)(self + 0xC) = 4;
            *(s32*)(self + 0x50) = 0x1E;
            xb_OnlineObj_Move(*(s32*)(self + 0x68));
            xb_OnlineObj_Fade(*(s32*)(self + 0x68));
        }

        xb_xlive_disp_DrawRectI(*(s32*)(self + 0x68), D_00219424, D_002B834C, D_0025F370, (s32)D_00799114, D_002B4BE4, 0, 0);
        break;
    case 4:
        xb_UpdateOnlineObjs();

        if (xb_OnlineObj_IsDone(*(s32*)(self + 0x68))) {
            *(s32*)(D_00798CAC + 0x2364) = *(s32*)(D_00798CAC + 0x2358) ? 0 : 6;
            *(s32*)(D_00798CAC + 0x2364) = 0;
            *(s32*)(D_00798CAC + 0x2368) = 0;
            *(s32*)(D_00798CAC + 0x236C) = 0;
            info = xb_GetMatchInfo();

            if (info != 0) {
                memset(info, 0, 0x1B8);
            }

            b.v = 0;
            ((void (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_WORK_CLASS_Set235C)(D_00798CAC, b);
            xb_xlive_friend_Release(*(s32*)(self + 0x68));
            xb_XLIVE_WORK_CLASS_ResetSessions(D_00798CAC);
            xb_XLIVE_STARTMENU_CLASS_Clear(self);
            b.v = 1;
            ((void (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_WORK_CLASS_Set2360)(D_00798CAC, b);
            judge_flag = 0;
            D_007A138C = 0;
        }

        break;
    default:
        _assert(D_0025CCA0, D_002B8350, 0x5AD);
        break;
    }

    return 0;
}

s32 xb_LiveWork_UpdateMode3DC(void);
void XB_FASTCALL xb_XLIVE_WORK_CLASS_UpdateTimer(void* self);
void XB_FASTCALL xb_XLIVE_STATMENU_CLASS_Update(u8* self);
s32 XB_FASTCALL xb_XLIVE_STATMENU_CLASS_UpdateList(u8* self);
void xb_xlive_stat_Commit(void);
u8 xb_ReturnFalse(void);
void XB_FASTCALL xb_xlive_main_StepState(u8* self);
void xb_xlive_disp_DrawRect1(s32 a, f32 x, f32 y, f32 w);
void xb_xlive_disp_CheckIndex2(s32 index, s32 id);
void xb_xlive_disp_CheckIndex(s32 index, s32 a, s32 b);
void xb_xlive_disp_DrawObj(s32 id, f32 x, f32 y, f32 z, u32 col, s32 icon, f32 sx, f32 sy);
s32 xb_GetLiveLanguage(void);
extern u8 D_00798D00[];
extern u8 D_00798CB0[];
extern f32 D_002B4E70;
extern f32 D_002B82D0;
extern f32 D_0021942C;
extern f32 D_002B5374;
extern f32 D_002190BC;
extern f32 D_002190D4;
extern f32 D_002B83D0;
extern f32 D_002B4EA4;
extern f32 D_002B5380;
extern f32 D_00219410;
extern f32 D_002B83CC;

/* The voice icon by the voice item, lit by the talker's level (work
 * +0x15C). */
#define XB_SM_VOICE_ICON(icon_)                                                         \
    do {                                                                                \
        c = (*(u32*)(D_00798CAC + 0x15C) & 0x3F) << 2;                                  \
        col = ((((c | 0xFFFFFF00) << 8) | c) << 8) | c;                                 \
        lang = xb_GetLiveLanguage();                                                    \
        xb_xlive_disp_DrawObj(*(s32*)(self + 0x64), lang ? D_002B5380 : D_002B4EA4,     \
                              D_002190BC, D_002B83D0, col, (icon_), D_002190D4, D_002190D4);       \
    } while (0)

/* xb_XLIVE_STARTMENU_CLASS_Update 0x11491F: the start menu drawn each
 * frame (+0x6C on): page +4 1 commits the stats read (+0x60 frames), 2
 * draws the menu (its cursor +8; the voice item shows the icon when
 * someone talks, +0x158 or +0x150; fewer items in the offline check), 3
 * the chosen page (the stats or the voice options, or the "end the
 * match?" box). Then the two text windows and the online objects step.
 * 1 while the work is busy. */
s32 XB_FASTCALL xb_XLIVE_STARTMENU_CLASS_Update(u8* self) {
    u32 c;
    u32 col;
    s32 lang;

    if (xb_LiveWork_UpdateMode3DC()) {
        return 1;
    }

    xb_XLIVE_WORK_CLASS_UpdateTimer(D_00798CAC);

    if (self[0x6C] == 0) {
        return 0;
    }

    switch (*(s32*)(self + 4)) {
    case 1:
        if (*(s32*)(self + 0x60) > 0) {
            ((void (XB_FASTCALL*)(u8*))xb_xlive_stat_Commit)(D_00798CAC + 0x2544);
            (*(s32*)(self + 0x60))--;
        }

        break;
    case 2:
        if (sub_0004AFFA() == 0) {
            if (xb_OnlineObj_IsActive(*(s32*)(self + 0x64)) == 0) {
                break;
            }

            xb_xlive_disp_DrawRectI(*(s32*)(self + 0x64), D_002AEEA8, D_002B4E70, D_0025F370, (s32)D_00799080, D_002B4BE4, 5, 0);
            xb_xlive_disp_DrawRect1(2, D_00219428, D_002B4E00, *(s32*)(self + 8) + 1);
            xb_xlive_disp_CheckIndex2(2, *(s32*)(self + 0x64));

            if ((*(s32*)(self + 8) == 1 && *(s32*)(D_00798CAC + 0x158) != 0) ||
                (*(s32*)(self + 8) == 1 && *(s32*)(D_00798CAC + 0x150) != 0)) {
                xb_xlive_disp_CheckIndex(2, -0x16, 0);
            }

            xb_xlive_disp_DrawRectI(*(s32*)(self + 0x64), D_002B5374, D_0021942C, D_0025F370, (s32)D_00799270, D_002B4BE4, 0, 0);
            xb_xlive_disp_DrawRectI(*(s32*)(self + 0x64), D_002B4E98, D_002190BC, D_0025F370, (s32)D_007991C0, D_002B4BE4, 0, 0);

            if (*(s32*)(D_00798CAC + 0x158) != 0) {
                XB_SM_VOICE_ICON(3);
            } else if (*(s32*)(D_00798CAC + 0x150) != 0) {
                XB_SM_VOICE_ICON(1);
            }

            xb_xlive_disp_DrawRectI(*(s32*)(self + 0x64), D_002B5374, D_00219410, D_0025F370, (s32)D_007993C8, D_002B4BE4, 0, 0);
            xb_xlive_disp_DrawRectI(*(s32*)(self + 0x64), D_002B5374, D_002B4D9C, D_0025F370, (s32)D_007990EC, D_002B4BE4, 0, 0);
            xb_xlive_disp_DrawRectI(*(s32*)(self + 0x64), D_00219424, D_002B4DDC, D_0025F370, (s32)D_00799234, D_002B4BE4, 0, 0);
            xb_xlive_disp_DrawRectI(*(s32*)(self + 0x64), D_00219424, D_002B83CC, D_0025F370, (s32)D_007992C8, D_002B4BE4, 4, 0);
        } else {
            if (xb_OnlineObj_IsDone(*(s32*)(self + 0x64)) == 0) {
                break;
            }

            xb_xlive_disp_DrawRectI(*(s32*)(self + 0x64), D_002AEEA8, D_00219428, D_0025F370, (s32)D_00799080, D_002B4BE4, 5, 0);
            xb_xlive_disp_DrawRect1(2, D_00219428, D_002B4E00, *(s32*)(self + 8) + 1);
            xb_xlive_disp_CheckIndex2(2, *(s32*)(self + 0x64));
            xb_xlive_disp_DrawRectI(*(s32*)(self + 0x64), D_002B5374, D_0021942C, D_0025F370, (s32)D_00799060, D_002B4BE4, 0, 0);
            xb_xlive_disp_DrawRectI(*(s32*)(self + 0x64), D_00219424, D_00219410, D_0025F370, (s32)D_007992C8, D_002B4BE4, 4, 0);
        }

        break;
    case 3:
        if (sub_0004AFFA() == 0) {
            switch (*(s32*)(self + 8)) {
            case 2:
                xb_XLIVE_STATMENU_CLASS_Update(D_00798CAC + 0x2544);
                break;
            case 3:
                xb_XLIVE_STATMENU_CLASS_UpdateList(D_00798CAC + 0x2544);
                break;
            }
        } else {
            switch (*(s32*)(self + 8)) {
            case 0:
                xb_XLIVE_STATMENU_CLASS_UpdateList(D_00798CAC + 0x2544);
                break;
            case 1:
                xb_xlive_disp_DrawRectI(*(s32*)(self + 0x68), D_00219424, D_002B4E70, D_0025F370, (s32)D_007993B8, D_002B4BE4, 0, 0);
                xb_xlive_disp_DrawRectI(*(s32*)(self + 0x68), D_002B831C, D_002B82D0, D_0025F370, (s32)D_00799210, D_002B4BE4, 0, 0);
                xb_xlive_SetObjFlag58(*(s32*)(self + 0x68), 1);
                break;
            }
        }

        break;
    }

    if (xb_ReturnFalse() != 1) {
        xb_xlive_main_StepState(D_00798D00);
        xb_xlive_main_StepState(D_00798CB0);
        xb_WINSTR_CLASS_Update(D_00798D00);
        xb_WINSTR_CLASS_Update(D_00798CB0);

        if (xb_GetOnlineFlagThunk()) {
            xb_UpdateOnlineObjs();
        }
    }

    return 0;
}

u8 xb_OnlineObj_Exists(s32 id);
extern u8* D_00799148;
extern char* D_00799348;
extern char* D_00799410;
extern char* D_00799290;
extern f32 D_002B8340;
extern f32 D_002B8344;
extern f32 D_002B4E9C;

/* xb_XLIVE_STATMENU_CLASS_Update 0x113C9E: the stats menu (box +0x5C,
 * its cursor +0x10) once the box is up: the four kinds of stats from the
 * text table (D_00799148), and below (+0x60) what A does for the chosen
 * one and B to go back. The two other windows (+0x54, +0x58) hidden. */
void XB_FASTCALL xb_XLIVE_STATMENU_CLASS_Update(u8* self) {
    char* help[2];

    if (xb_OnlineObj_Exists(*(s32*)(self + 0x5C)) == 0 || xb_OnlineObj_IsDone(*(s32*)(self + 0x5C)) == 0) {
        return;
    }

    xb_xlive_SetObjFlag58(*(s32*)(self + 0x54), 0);
    xb_xlive_SetObjFlag58(*(s32*)(self + 0x58), 0);
    xb_xlive_disp_DrawRectI(*(s32*)(self + 0x5C), D_002B5374, D_002B8340, D_0025F370, *(s32*)(D_00799148 + 0x8C), D_002B4BE4, 5, 0);
    xb_xlive_disp_DrawRectI(*(s32*)(self + 0x5C), D_002190BC, D_0021942C, D_0025F370, *(s32*)(D_00799148 + 0x90), D_002B4BE4, 0, 0);
    xb_xlive_disp_DrawRectI(*(s32*)(self + 0x5C), D_002190BC, D_00219410, D_0025F370, *(s32*)(D_00799148 + 0x74), D_002B4BE4, 0, 0);
    xb_xlive_disp_DrawRectI(*(s32*)(self + 0x5C), D_002190BC, D_002B4D9C, D_0025F370, *(s32*)(D_00799148 + 0x78), D_002B4BE4, 0, 0);
    xb_xlive_disp_DrawRect1(2, D_00219428, D_002B4E00, *(s32*)(self + 0x10) + 2);
    xb_xlive_disp_CheckIndex2(2, *(s32*)(self + 0x5C));
    help[0] = D_00799348;
    help[1] = D_00799410;
    xb_xlive_disp_DrawRectI(*(s32*)(self + 0x60), 0.0f, D_002B8344, D_0025F370, (s32)help[*(s32*)(self + 0x10)], D_002B4BE4, 0, 0);
    xb_xlive_disp_DrawRectI(*(s32*)(self + 0x60), 0.0f, D_002B4E9C, D_0025F370, (s32)D_00799290, D_002B4BE4, 4, 0);
}

void xb_xlive_disp_DrawCell(s32 font, s32 col, s32 row, s32 text, f32 s, f32 a, s32 flags);
extern f32 D_002190B4;
extern f32 D_002B8338;
extern f32 D_002B833C;
extern f32 D_002B50E8;

/* The text table's entries (D_00799148, one string each). */
#define XB_SM_TEXT(i_) (*(s32*)(D_00799148 + (i_) * 4))

/* xb_XLIVE_STATMENU_CLASS_UpdateList 0x11369A: the stats pages drawn
 * (nothing while the work is busy, +0x3DC): pages +4 0 and 1 the kinds
 * of stats (box +0x54, cursor +8; the offline check has one more line),
 * page 2 either the leaderboards' list (+8 0: box +0x5C, cursor +0x10)
 * or a board (+8 1: box +0x58): its loading text (+0xC 2) or its eight
 * rows from +0x7C with the arrows when there are more, the cursor +0x74.
 * The pad hints go in +0x60. */
s32 XB_FASTCALL xb_XLIVE_STATMENU_CLASS_UpdateList(u8* self) {
    s32 hint;
    s32 i;

    if (*(s32*)(D_00798CAC + 0x3DC) != 0) {
        return 0;
    }

    switch (*(s32*)(self + 4)) {
    case 0:
    case 1:
        if (xb_OnlineObj_Exists(*(s32*)(self + 0x54)) == 0 || xb_OnlineObj_IsDone(*(s32*)(self + 0x54)) == 0) {
            break;
        }

        xb_xlive_SetObjFlag58(*(s32*)(self + 0x58), 0);
        xb_xlive_SetObjFlag58(*(s32*)(self + 0x5C), 0);
        xb_xlive_disp_DrawRectI(*(s32*)(self + 0x54), D_002B5374, D_002B8340, D_0025F370, XB_SM_TEXT(0), D_002B4BE4, 5, 0);
        xb_xlive_disp_DrawRect1(2, D_00219428, D_002B4E00, *(s32*)(self + 8) + 1);
        xb_xlive_disp_CheckIndex2(2, *(s32*)(self + 0x54));
        xb_xlive_disp_DrawRectI(*(s32*)(self + 0x54), D_002AEEA8, D_0021942C, D_0025F370, XB_SM_TEXT(2), D_002B4BE4, 0, 0);

        if (sub_0004AFFA() == 0) {
            xb_xlive_disp_DrawRectI(*(s32*)(self + 0x54), D_002AEEA8, D_002190BC, D_0025F370, XB_SM_TEXT(3), D_002B4BE4, 0, 0);
        } else {
            xb_xlive_disp_DrawRectI(*(s32*)(self + 0x54), D_002AEEA8, D_002B50E8, D_0025F370, XB_SM_TEXT(0x20), D_002B4BE4, 4, 0);
        }

        xb_xlive_disp_DrawCell(*(s32*)(self + 0x60), 9, *(s32*)(self + 8), 0, 0.0f, 1.0f, 0);
        xb_xlive_disp_DrawCell(*(s32*)(self + 0x60), 9, 4, 0, 0.0f, 1.0f, 4);
        break;
    case 2:
        switch (*(s32*)(self + 8)) {
        case 0:
            if (xb_OnlineObj_Exists(*(s32*)(self + 0x5C)) == 0 || xb_OnlineObj_IsDone(*(s32*)(self + 0x5C)) == 0) {
                break;
            }

            xb_xlive_SetObjFlag58(*(s32*)(self + 0x54), 0);
            xb_xlive_SetObjFlag58(*(s32*)(self + 0x58), 0);
            xb_xlive_disp_DrawRectI(*(s32*)(self + 0x5C), D_002190BC, D_0021942C, D_0025F370, XB_SM_TEXT(2), D_002B4BE4, 5, 0);
            xb_xlive_disp_DrawRectI(*(s32*)(self + 0x5C), D_002190BC, D_00219410, D_0025F370, XB_SM_TEXT(0x25), D_002B4BE4, 0, 0);
            xb_xlive_disp_DrawRectI(*(s32*)(self + 0x5C), D_002190BC, D_002B4D9C, D_0025F370, XB_SM_TEXT(0x26), D_002B4BE4, 0, 0);
            xb_xlive_disp_DrawCell(*(s32*)(self + 0x60), 9, *(s32*)(self + 0x10) + 2, 0, 1.0f, 1.0f, 0);
            xb_xlive_disp_DrawCell(*(s32*)(self + 0x60), 9, 4, 0, 0.0f, 1.0f, 4);
            xb_xlive_disp_DrawRect1(2, D_00219428, D_002B4E00, *(s32*)(self + 0x10) + 1);
            xb_xlive_disp_CheckIndex2(2, *(s32*)(self + 0x5C));
            break;
        case 1:
            if (xb_OnlineObj_Exists(*(s32*)(self + 0x58)) == 0 || xb_OnlineObj_IsDone(*(s32*)(self + 0x58)) == 0) {
                break;
            }

            xb_xlive_SetObjFlag58(*(s32*)(self + 0x54), 0);
            xb_xlive_SetObjFlag58(*(s32*)(self + 0x5C), 0);
            xb_xlive_disp_DrawRectI(*(s32*)(self + 0x58), D_002B5374, D_002B8340, D_0025F370, XB_SM_TEXT(0), D_002B4BE4, 5, 0);

            switch (*(s32*)(self + 0xC)) {
            case 1:
                hint = -1;
                xb_xlive_disp_DrawRectI(*(s32*)(self + 0x58), D_002AEEA8, D_0021942C, D_0025F370, XB_SM_TEXT(3), D_002B4BE4, 5, 0);

                if (*(s32*)(self + 0x7C) != 0) {
                    xb_xlive_disp_DrawRectI(*(s32*)(self + 0x58), D_002AEEA8, D_002190BC, D_0025F370, XB_SM_TEXT(0x21), D_002B4BE4, 5, 0);
                    hint = 0;
                }

                if (*(s32*)(self + 0x7C) + 7 < 0x10) {
                    xb_xlive_disp_DrawRectI(*(s32*)(self + 0x58), D_002AEEA8, D_002190B4, D_0025F370, XB_SM_TEXT(0x22), D_002B4BE4, 5, 0);
                }

                xb_xlive_disp_DrawRect1(2, D_00219428, D_002B4E00, *(s32*)(self + 0x74) + hint + 4);
                xb_xlive_disp_CheckIndex2(2, *(s32*)(self + 0x58));

                for (i = *(s32*)(self + 0x7C); i <= *(s32*)(self + 0x7C) + 7; i++) {
                    xb_xlive_disp_DrawRectI(*(s32*)(self + 0x58), D_00219424, (i - *(s32*)(self + 0x7C) + 4) * 20 + D_00219428, D_0025F370,
                                            XB_SM_TEXT(i + 10), D_002B4BE4, 0, 0);
                }

                xb_xlive_disp_DrawRectI(*(s32*)(self + 0x58), D_002B8338, D_002B833C, D_0025F370, XB_SM_TEXT(0x20), D_002B4BE4, 4, 0);
                break;
            case 2:
                xb_xlive_disp_DrawRectI(*(s32*)(self + 0x58), D_002AEEA8, D_0021942C, D_0025F370, XB_SM_TEXT(7), D_002B4BE4, 0, 0);
                xb_xlive_disp_DrawRectI(*(s32*)(self + 0x58), D_002B8338, D_002B833C, D_0025F370, XB_SM_TEXT(4), D_002B4BE4, 4, 0);
                break;
            }

            break;
        }

        break;
    }

    return 0;
}

void** XB_FASTCALL xb_XLIVE_PAGE_CLASS_ctor(void** self);
extern void* D_002B8328[];

/* xb_XLIVE_STATMENU_CLASS_ctor 0x114202: the stats menu, its windows
 * (+0x54 to +0x5C) none yet. */
u8* XB_FASTCALL xb_XLIVE_STATMENU_CLASS_ctor(u8* self) {
    xb_XLIVE_PAGE_CLASS_ctor((void**)self);
    *(s32*)(self + 0x74) = 0;
    *(s32*)(self + 0x7C) = 0;
    *(s32*)(self + 0x54) = -1;
    *(s32*)(self + 0x58) = -1;
    *(s32*)(self + 0x5C) = -1;
    *(void**)self = D_002B8328;
    *(s32*)(self + 0x64) = 1;
    return self;
}

/* xb_XLIVE_PAGE_CLASS_dtor 0x113441. */
void XB_FASTCALL xb_XLIVE_PAGE_CLASS_dtor(void** self) {
    *self = D_002B8328;
}

/* The sign-on (xlive_signon.cpp; the Live work's +0x2338): its step is
 * the Live work's +0x2368, a timer +0x23B4. */
s32 XB_FASTCALL xb_XLIVE_WORK_CLASS_Frame(u8* self);
void XB_FASTCALL xb_LiveTimer2_Start(u8* self, s32 edx, const char* str);
void XB_FASTCALL xb_xlive_main_SetWinText(u8* self, s32 edx, const char* msg);
void xb_xlive_main_ReleaseBanner(void);
void xb_LiveWork_Bind(void);
void xb_xlive_match_Set17E(u8 v);
void xb_LiveSet79A170(s32 v);
s32 xb_xlive_disp_DrawRectFloat(f32 x, f32 y, f32 w, f32 h);
s32 XB_FASTCALL xb_WINSTR_CLASS_Exists(u8* self);
void xb_xlive_disp_DrawMessageDefault(s32 a, s32 b, s32 c);
extern char* D_00799218;
extern f32 D_002193F0;
extern f32 D_002B4DE4;
extern f32 D_002B4A34;
extern char D_002B8240[];
s32 XB_FASTCALL xb_XLIVE_SIGNON_Start(u8* self);
s32 XB_FASTCALL xb_XLIVE_SIGNON_AccountList(u8* self);
s32 XB_FASTCALL xb_XLIVE_SIGNON_AskDashboard(u8* self);
s32 XB_FASTCALL xb_XLIVE_SIGNON_LaunchDashboard(u8* self);
s32 XB_FASTCALL xb_XLIVE_SIGNON_PassCode(u8* self);
s32 XB_FASTCALL xb_XLIVE_SIGNON_Logon(u8* self);
s32 XB_FASTCALL xb_XLIVE_SIGNON_LogonError(u8* self);

#define XB_SO_STEP (*(s32*)(D_00798CAC + 0x2368))
#define XB_SO_TIMER (*(s32*)(D_00798CAC + 0x23B4))

/* xb_XLIVE_SIGNON_Page 0x111471 (the Live work's state 3): signed off:
 * the sessions reset, a box (+4) with the banner text, two messages for
 * half a second each, then the box fades, the Live work is bound again
 * and starts over (state 0). */
s32 XB_FASTCALL xb_XLIVE_SIGNON_Page(u8* self) {
    XB_ARG a;

    switch (XB_SO_STEP) {
    case 0:
        XB_SO_STEP++;
        xb_XLIVE_WORK_CLASS_ResetSessions(D_00798CAC);
        a.v = (s32)D_00799218;

        if (xb_WINSTR_CLASS_Exists(D_00798D00) == 0) {
            ((void (XB_FASTCALL*)(u8*, XB_ARG))xb_LiveTimer2_Start)(D_00798CAC, a);
        } else {
            ((void (XB_FASTCALL*)(u8*, XB_ARG))xb_xlive_main_SetWinText)(D_00798CAC, a);
        }

        *(s32*)(self + 4) = xb_xlive_disp_DrawRectFloat(D_002B4BEC, D_002193F0, D_002B4A34, D_002B4DE4);
        xb_OnlineObj_Move(*(s32*)(self + 4));
        xb_xlive_main_ReleaseBanner();
        a.v = 0;
        ((void (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_WORK_CLASS_Set235C)(D_00798CAC, a);
        /* fallthrough */
    case 1:
        if (xb_OnlineObj_IsDone(*(s32*)(self + 4))) {
            XB_SO_STEP++;
            XB_SO_TIMER = 0x1E;
        }

        break;
    case 2:
        if (--XB_SO_TIMER == 0) {
            XB_SO_STEP++;
            XB_SO_TIMER = 0x1E;
        }

        if (xb_XLIVE_WORK_CLASS_Frame(D_00798CAC) == 0) {
            xb_xlive_disp_DrawMessageDefault(0, 0x16, 0);
        }

        return 0;
    case 3:
        if (--XB_SO_TIMER == 0) {
            XB_SO_STEP++;
            xb_OnlineObj_Fade(*(s32*)(self + 4));
        }

        if (xb_XLIVE_WORK_CLASS_Frame(D_00798CAC) == 0) {
            xb_xlive_disp_DrawMessageDefault(0, 0x17, 0);
        }

        return 0;
    case 4:
        if (xb_OnlineObj_IsDone(*(s32*)(self + 4))) {
            xb_LiveWork_Bind();
            *(s32*)(D_00798CAC + 0x2364) = 0;
            xb_LiveSet79A170(0);
            XB_SO_STEP = 0;
            xb_xlive_friend_Release(*(s32*)(self + 4));
            xb_xlive_match_Set17E(0);
        }

        break;
    default:
        _assert(D_0025CCA0, D_002B8240, 0x5BD);
        return 0;
    }

    xb_XLIVE_WORK_CLASS_Frame(D_00798CAC);
    return 0;
}

/* xb_XLIVE_SIGNON_Done 0x111453: signed on: the Live work leaves (state
 * 6). */
s32 XB_FASTCALL xb_XLIVE_SIGNON_Done(u8* self) {
    (void)self;
    *(s32*)(D_00798CAC + 0x2364) = 6;
    XB_SO_STEP = 0;
    return 0;
}

/* xb_XLIVE_SIGNON_Step 0x1130C5 (the Live work's state 1): the sign-on's
 * step. */
s32 XB_FASTCALL xb_XLIVE_SIGNON_Step(u8* self) {
    switch (XB_SO_STEP) {
    case 0:
        return xb_XLIVE_SIGNON_Start(self);
    case 1:
        return xb_XLIVE_SIGNON_AccountList(self);
    case 2:
        return xb_XLIVE_SIGNON_AskDashboard(self);
    case 3:
        return xb_XLIVE_SIGNON_LaunchDashboard(self);
    case 4:
        return xb_XLIVE_SIGNON_PassCode(self);
    case 5:
        return xb_XLIVE_SIGNON_Logon(self);
    case 6:
        return xb_XLIVE_SIGNON_LogonError(self);
    case 7:
        return xb_XLIVE_SIGNON_Done(self);
    }

    _assert(D_0025CCA0, D_002B8240, 0x5E);
    return xb_XLIVE_SIGNON_Done(self);
}

s32 xb_LivePadBack(void);
s32 XB_FASTCALL xb_vector_XONLINE_USER_empty(void* self);
u32 XB_FASTCALL std__vector_XONLINE_USER__size(void* self);
u8* XB_FASTCALL xb_vector_XONLINE_USER_Subscript(void* self, s32 edx, u32 i);
s32 xb_xlive_disp_TextLeft(s32 a, s32 right, const char* s);
void xb_xlive_disp_DrawWideCentered(f32 x, f32 y, const char* text);
void xb_xlive_disp_DrawTextAt(f32 x, f32 y, s32 text);
void xb_xlive_disp_DrawMessageRight(s32 col, s32 row, s32 text);
u32 XB_STDCALL XLaunchNewImageA(const char* path, void* data);
extern s32 D_00418620;
extern char* D_00799164;
extern f32 D_002B82D0;
extern f32 D_002190F4;

/* xb_XLIVE_SIGNON_DrawUsers 0x111757: the accounts on the console (the
 * list from the Live work's +0x23BC, six rows from y 108), the signed-on
 * one (+0x220) marked by the icon and its row kept (D_00418620); or the
 * "no accounts" text. */
void XB_FASTCALL xb_XLIVE_SIGNON_DrawUsers(u8* self, s32 edx, void* users) {
    u32 i;
    u32 y;
    s32 row;
    s32 x;
    u8* u;
    XB_ARG a;

    (void)self;
    (void)edx;
    D_00418620 = -1;

    if ((u8)xb_vector_XONLINE_USER_empty(users)) {
        x = 0x280 - (strlen(D_00799164) * 20 >> 1);
        xb_xlive_disp_DrawTextAt((f32)(u32)x / D_002190A4, D_002B82D0, (s32)D_00799164);
        return;
    }

    row = 0;
    i = *(u32*)(D_00798CAC + 0x23BC);

    for (y = 0x6C; y < 0xE4; y += 0x14, i++, row++) {
        if (i >= std__vector_XONLINE_USER__size(users)) {
            return;
        }

        a.v = i;
        x = xb_xlive_disp_TextLeft(-1, 0, (char*)(((u8* (XB_FASTCALL*)(void*, XB_ARG))xb_vector_XONLINE_USER_Subscript)(users, a) + 0xC));

        if (*(s32*)(D_00798CAC + 0x1C4) != 0) {
            u = ((u8* (XB_FASTCALL*)(void*, XB_ARG))xb_vector_XONLINE_USER_Subscript)(users, a);

            if (*(u32*)(D_00798CAC + 0x220) == *(u32*)u && *(u32*)(D_00798CAC + 0x224) == *(u32*)(u + 4)) {
                xb_xlive_disp_DrawObj(-1, (f32)(x - 0x11), (f32)y - D_002190A4, D_0025F370, -1, 3, D_002190D4, D_002190D4);
                D_00418620 = row;
            }
        }

        xb_xlive_disp_DrawWideCentered((f32)x, (f32)y,
                                       (char*)(((u8* (XB_FASTCALL*)(void*, XB_ARG))xb_vector_XONLINE_USER_Subscript)(users, a) + 0xC));
    }
}

#define XB_SO_SUB (*(s32*)(D_00798CAC + 0x236C))
#define XB_SO_DRAW_USERS() (b.v = (s32)(D_00798CAC + 0x18), ((void (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_SIGNON_DrawUsers)(self, b))

/* xb_XLIVE_SIGNON_AskDashboard 0x1118FA (step 2): "manage accounts on
 * the dashboard?": A goes there (step 3, launch reason 7), B back to the
 * account list (step 1). */
s32 XB_FASTCALL xb_XLIVE_SIGNON_AskDashboard(u8* self) {
    XB_ARG b;

    if (XB_SO_SUB == 0) {
        if (xb_LivePadAccept()) {
            XB_SO_STEP = 3;
            XB_SO_SUB = 0;
            *(s32*)(D_00798CAC + 0x26C) = 7;
            xb_SeSelectedThunk();
        } else if (xb_LivePadBack()) {
            XB_SO_STEP = 1;
            XB_SO_SUB = 0;
            xb_SeSelectedThunk();
        }
    }

    if (xb_XLIVE_WORK_CLASS_Frame(D_00798CAC) == 0) {
        xb_xlive_disp_DrawMessageDefault(0, 5, 0);
        xb_xlive_disp_DrawMessageRight(0, 6, 0);
        XB_SO_DRAW_USERS();
    }

    return 0;
}

/* xb_XLIVE_SIGNON_LaunchDashboard 0x1119A7 (step 3): after half a second
 * (+0x23B8) the dashboard is launched with the reason (+0x26C). */
s32 XB_FASTCALL xb_XLIVE_SIGNON_LaunchDashboard(u8* self) {
    u8 data[0xC00];
    XB_ARG b;

    switch (XB_SO_SUB) {
    case 0:
        XB_SO_SUB++;
        *(s32*)(D_00798CAC + 0x23B8) = 0x1E;
        break;
    case 1:
        if (--*(s32*)(D_00798CAC + 0x23B8) == 0) {
            memset(data, 0, sizeof(data));
            *(u32*)data = *(u32*)(D_00798CAC + 0x26C);
            XLaunchNewImageA(0, data);
        }

        break;
    }

    if (xb_XLIVE_WORK_CLASS_Frame(D_00798CAC) == 0) {
        xb_xlive_disp_DrawMessageDefault(0, 7, 0);
        XB_SO_DRAW_USERS();
    }

    return 0;
}

void XB_FASTCALL xb_XLIVE_WORK_CLASS_SetState4(u8* self);
s32 xb_xlive_main_SetErrorArgs(s32 hr, const char* file, s32 line, s32 fatal);
void xb_xlive_disp_Reset(void);
void xb_xlive_disp_RequestFade(s32 a, s32 step, s32 kind);
s32 xb_xlive_disp_IsFading(void);
void xb_xlive_disp_Thunk108FA6(void);
void XB_FASTCALL xb_CONNECT_USER_CLASS_SetActive(u8* self, s32 edx, u8 on);
void XB_FASTCALL xb_WINSTR_CLASS_SetPos(u8* self, s32 edx, f32 x, f32 y, f32 w, f32 h, const char* str);
s32 XBOnline_GetUserList(void* list);
extern u8 D_00798120;
extern u8* D_003F8310;
extern f32 D_002AEEE8;
extern f32 D_002B82D4;
extern f32 D_002B50E0;
extern f32 D_002B4A30;
extern f32 D_002B4A38;

/* xb_xlive_GetUserList 0x11B82B: the console's accounts into the list. */
s32 xb_xlive_GetUserList(void* list) {
    return XBOnline_GetUserList(list);
}

/* xb_xlive_disp_SetFlag798120 0xF80C5. */
void xb_xlive_disp_SetFlag798120(u8 v) {
    D_00798120 = v;
}

/* xb_XLIVE_SIGNON_Start 0x111F92 (step 0): fade in, the accounts read
 * (an error: state 4), the account signed on last (+0x220) chosen if it
 * is there (+0x18, the cursor +0x23B4 and the list's top +0x23BC), and the
 * list's box (+0) and the help box (+4) opened; once they are up, the
 * account list (step 1). */
s32 XB_FASTCALL xb_XLIVE_SIGNON_Start(u8* self) {
    s32 r = 0;
    s32 i;
    u8* u;
    u8* w;
    XB_ARG a;

    switch (XB_SO_SUB) {
    case 0:
        XB_SO_SUB++;
        xb_xlive_disp_RequestFade(0, 0x10, 0);
        XB_SO_TIMER = 0;
        *(s32*)(D_00798CAC + 0x23BC) = 0;
        *(s32*)(self + 0x1C) = 0;
        xb_xlive_disp_Reset();
        a.v = (s32)D_007993A8;
        ((void (XB_FASTCALL*)(u8*, XB_ARG))xb_LiveTimer2_Start)(D_00798CAC, a);
        ((void (XB_FASTCALL*)(void*))xb_xlive_disp_Thunk108FA6)(D_00798CAC + 0x18);

        if (xb_xlive_GetUserList(D_00798CAC + 0x18) < 0) {
            xb_XLIVE_WORK_CLASS_SetState4(D_00798CAC);
            return xb_xlive_main_SetErrorArgs(5, D_002B8240, 0x84, 1);
        }

        *(s32*)(self + 0x18) = 0;
        *(s32*)(D_00798CAC + 0x268) = *(s32*)(D_00798CAC + 0x1C4);
        w = D_00798CAC;

        if (*(s32*)(w + 0x268) != 0) {
            *(s32*)(w + 0x268) = 0;

            for (i = 0; i < (s32)std__vector_XONLINE_USER__size(D_00798CAC + 0x18); i++) {
                a.v = i;
                u = ((u8* (XB_FASTCALL*)(void*, XB_ARG))xb_vector_XONLINE_USER_Subscript)(D_00798CAC + 0x18, a);
                w = D_00798CAC;

                if (*(u32*)(w + 0x220) == *(u32*)u && *(u32*)(w + 0x224) == *(u32*)(u + 4)) {
                    *(s32*)(self + 0x18) = 1;
                    XB_SO_TIMER = i;
                    *(s32*)(D_00798CAC + 0x23BC) = XB_SO_TIMER;
                    w = D_00798CAC;

                    if (*(s32*)(w + 0x23BC) < 0) {
                        *(s32*)(w + 0x23BC) = 0;
                        w = D_00798CAC;
                    }

                    if (*(u32*)(w + 0x23BC) >= std__vector_XONLINE_USER__size(w + 0x18) - 6) {
                        *(u32*)(w + 0x23BC) = std__vector_XONLINE_USER__size(w + 0x18) - 6;
                        w = D_00798CAC;
                    }

                    break;
                }
            }
        }

        *(s32*)(w + 0x14C) = 0;
        *(s32*)self = xb_xlive_disp_DrawRectFloat(D_002B5384, D_002AEEE8, D_002B82D4, D_002B82D8);
        xb_OnlineObj_Move(*(s32*)self);
        *(s32*)(self + 4) = xb_xlive_disp_DrawRectFloat(D_002B4BEC, D_002B50E0, D_002B4A34, D_002B4DE4);
        xb_OnlineObj_Move(*(s32*)(self + 4));
        a.v = 0;
        ((void (XB_FASTCALL*)(u8*, XB_ARG))xb_CONNECT_USER_CLASS_SetActive)(D_00798CAC + 0x59E0, a);
        a.v = (s32)D_007993A8;
        ((void (XB_FASTCALL*)(u8*, f32, f32, f32, f32, XB_ARG))xb_WINSTR_CLASS_SetPos)(D_003F8310, D_002B4BEC, D_002B4A30,
                                                                                      D_002B4A34, D_002B4A38, a);
        xb_xlive_disp_SetFlag798120(0);
        break;
    case 1:
        if (xb_xlive_disp_IsFading() == 0 && xb_OnlineObj_IsDone(*(s32*)self) && xb_OnlineObj_IsDone(*(s32*)(self + 4))) {
            XB_SO_STEP = 1;
            XB_SO_SUB = 0;
        }

        xb_XLIVE_WORK_CLASS_Frame(D_00798CAC);
        break;
    }

    return r;
}

s32 xb_LivePadTrigger(s32 key);
void xb_xlive_main_CloseWin(void);
void xb_xlive_disp_ReleaseAllThunk(void);

/* xb_XLIVE_SIGNON_ReadPassKey 0x111352: the pass-code button pressed
 * this frame (the pad directions, X, Y, the triggers and the sticks as 1
 * to 10), or -1. */
s32 XB_FASTCALL xb_XLIVE_SIGNON_ReadPassKey(u8* self) {
    s32 keys[8][2];
    s32 r = -1;
    s32 i;

    (void)self;
    keys[0][0] = 1;
    keys[0][1] = 1;
    keys[1][0] = 2;
    keys[1][1] = 2;
    keys[2][0] = 4;
    keys[2][1] = 3;
    keys[3][0] = 8;
    keys[3][1] = 4;
    keys[4][0] = 0x100;
    keys[4][1] = 5;
    keys[5][0] = 0x200;
    keys[5][1] = 6;
    keys[6][0] = 0x80;
    keys[6][1] = 9;
    keys[7][0] = 0x800;
    keys[7][1] = 10;

    for (i = 0; i < 8; i++) {
        if (xb_LivePadTrigger(keys[i][0])) {
            r = keys[i][1];
            break;
        }
    }

    return r;
}

/* xb_XLIVE_SIGNON_PassCode 0x111A61 (step 4): the chosen account's
 * (+0x10) four-key pass code entered (+0x270, the count +0x23B8): A with
 * all four checks it (right: signing on, step 5; wrong: the message,
 * sub-step 2), B takes a key back or leaves (back to the list, or with
 * the account preset, out of the Live menu through sub-step 3). */
s32 XB_FASTCALL xb_XLIVE_SIGNON_PassCode(u8* self) {
    s32 busy;
    s32 k;
    XB_ARG a;
    XB_ARG b;

    busy = xb_XLIVE_WORK_CLASS_Frame(D_00798CAC);

    if (XB_SO_SUB > 2) {
        busy = 1;
    }

    if (busy == 0) {
        XB_SO_DRAW_USERS();
    }

    switch (XB_SO_SUB) {
    case 0:
        XB_SO_SUB++;
        *(s32*)(D_00798CAC + 0x23B8) = 0;
        /* fallthrough */
    case 1:
        if (*(s32*)(D_00798CAC + 0x23B8) < 4) {
            k = xb_XLIVE_SIGNON_ReadPassKey(self);

            if (k != -1) {
                D_00798CAC[0x270 + *(s32*)(D_00798CAC + 0x23B8)] = k;
                (*(s32*)(D_00798CAC + 0x23B8))++;
            }

            if (busy == 0) {
                xb_xlive_disp_DrawMessageRight(0, *(s32*)(D_00798CAC + 0x23B8) == 0 ? 0x10 : 0xF, 0);
            }
        } else {
            if (xb_LivePadAccept()) {
                a.v = *(s32*)(D_00798CAC + 0x10);

                if (*(u32*)(((u8* (XB_FASTCALL*)(void*, XB_ARG))xb_vector_XONLINE_USER_Subscript)(D_00798CAC + 0x18, a) + 0x20) ==
                    *(u32*)(D_00798CAC + 0x270)) {
                    XB_SO_STEP = 5;
                    *(s32*)(D_00798CAC + 0x2370) = 0;
                    XB_SO_SUB = 0;
                    xb_SeSelectedThunk();
                    return 0;
                }

                XB_SO_SUB++;
                xb_SeSelectedThunk();
            }

            if (busy == 0) {
                xb_xlive_disp_DrawMessageRight(0, 0xE, 0);
            }
        }

        if (xb_LivePadBack()) {
            xb_SeSelectedThunk();

            if (*(s32*)(D_00798CAC + 0x23B8) == 0) {
                if (*(s32*)(self + 0x18) == 0) {
                    XB_SO_STEP = 1;
                    XB_SO_SUB = 0;
                } else {
                    xb_xlive_main_CloseWin();
                    xb_OnlineObj_Fade(*(s32*)self);
                    xb_OnlineObj_Fade(*(s32*)(self + 4));
                    *(s32*)(self + 8) = 0x1E;
                    XB_SO_SUB = 3;
                }
            } else {
                (*(s32*)(D_00798CAC + 0x23B8))--;
            }
        }

        if (busy == 0) {
            xb_xlive_disp_DrawMessageDefault(0, 8, 0);
            xb_xlive_disp_DrawMessageDefault(0, *(s32*)(D_00798CAC + 0x23B8) + 9, 0);
        }

        break;
    case 2:
        if (xb_LivePadBack()) {
            XB_SO_SUB = 0;
        }

        if (busy == 0) {
            xb_xlive_disp_DrawMessageDefault(0, 0x11, 0);
            xb_xlive_disp_DrawMessageRight(0, 0x10, 0);
        }

        break;
    case 3:
        if (--*(s32*)(self + 8) > 0) {
            break;
        }

        if (xb_OnlineObj_IsDone(*(s32*)self) && xb_OnlineObj_IsDone(*(s32*)(self + 4))) {
            XB_SO_STEP = 7;
            XB_SO_SUB = 0;
            *(s32*)(D_00798CAC + 0x2364) = 6;
            xb_xlive_friend_Release(*(s32*)self);
            xb_xlive_friend_Release(*(s32*)(self + 4));
            xb_xlive_disp_ReleaseAllThunk();
        }

        xb_XLIVE_WORK_CLASS_Frame(D_00798CAC);
        break;
    }

    return 0;
}

s32 XB_STDCALL XOnlineTitleUpdate(u32 context);
s32 xb_xlive_main_SetMatchArgs(s32 hr, const char* file, s32 line, s32 a);
s32 xb_xlive_main_DrawLogonError(s32 code);
s32 XB_FASTCALL CXBOnlineTask_Close(void* self);

/* xb_xlive_TitleUpdate 0x11B849: the title update started (the console
 * reboots into it). */
s32 xb_xlive_TitleUpdate(u32 context) {
    return XOnlineTitleUpdate(context);
}

/* What A and B do on a logon error. */
#define XB_SO_GOTO(s_) (XB_SO_STEP = (s_), XB_SO_SUB = 0)
#define XB_SO_BACK()                                                                                                   \
    do {                                                                                                               \
        if (xb_LivePadBack()) {                                                                                        \
            if (*(s32*)(self + 0x18) == 0) {                                                                           \
                XB_SO_GOTO(1);                                                                                         \
                xb_SeSelectedThunk();                                                                                  \
            } else {                                                                                                   \
                XB_SO_GOTO(7);                                                                                         \
            }                                                                                                          \
        }                                                                                                              \
    } while (0)
#define XB_SO_BACK_CLOSE()                                                                                             \
    do {                                                                                                               \
        if (xb_LivePadBack()) {                                                                                        \
            if (*(s32*)(self + 0x18) == 0) {                                                                           \
                XB_SO_GOTO(1);                                                                                         \
                xb_SeSelectedThunk();                                                                                  \
                CXBOnlineTask_Close(D_00798CAC + 0xF8);                                                                \
            } else {                                                                                                   \
                XB_SO_GOTO(7);                                                                                         \
            }                                                                                                          \
        }                                                                                                              \
    } while (0)
#define XB_SO_DASHBOARD(reason_) \
    (XB_SO_GOTO(3), *(s32*)(D_00798CAC + 0x26C) = (reason_), xb_SeSelectedThunk())

/* xb_XLIVE_SIGNON_LogonError 0x111CD4 (step 6): the logon failed (the
 * error +0x2D4, its message shown with the account list): by the error, A
 * signs on again (step 5), updates the title, or goes to the dashboard to
 * fix the account or the network (launch reasons 6 and 8), and B goes
 * back to the list (or, with the account preset, leaves). */
s32 XB_FASTCALL xb_XLIVE_SIGNON_LogonError(u8* self) {
    s32 r = 0;
    s32 hr;
    XB_ARG b;

    switch (*(s32*)(D_00798CAC + 0x2D4)) {
    case (s32)0x80151003:
        if (xb_LivePadAccept()) {
            XB_SO_STEP = 5;
            *(s32*)(D_00798CAC + 0x2370) = 0;
            XB_SO_SUB = 0;
            xb_SeSelectedThunk();
        } else {
            XB_SO_BACK();
        }

        break;
    case (s32)0x80151002:
        if (xb_LivePadAccept()) {
            hr = xb_xlive_TitleUpdate(0);
            _assert(D_0025CCA0, D_002B8240, 0x4FA);
            xb_XLIVE_WORK_CLASS_SetState4(D_00798CAC);
            return xb_xlive_main_SetMatchArgs(hr, D_002B8240, 0x4FC, 0);
        }

        XB_SO_BACK_CLOSE();
        break;
    case (s32)0x80151000:
        if (xb_LivePadAccept()) {
            XB_SO_DASHBOARD(6);
        } else {
            XB_SO_BACK();
        }

        break;
    case (s32)0x80151001:
    case (s32)0x80151004:
        if (xb_LivePadAccept()) {
            XB_SO_DASHBOARD(6);
        } else {
            XB_SO_BACK_CLOSE();
        }

        break;
    case (s32)0x80151005:
        if (xb_LivePadAccept()) {
            if (*(s32*)(self + 0x18) == 0) {
                XB_SO_GOTO(1);
                xb_SeSelectedThunk();
            } else {
                XB_SO_GOTO(7);
            }
        }

        break;
    case (s32)0x80151006:
        if (xb_LivePadAccept()) {
            XB_SO_DASHBOARD(8);
        } else {
            XB_SO_BACK_CLOSE();
        }

        break;
    case (s32)0x80151101:
    case (s32)0x80151102:
        XB_SO_BACK();
        break;
    case (s32)0x80151200:
        if (xb_LivePadAccept()) {
            XB_SO_DASHBOARD(8);
        }

        break;
    default:
        if (xb_LivePadAccept()) {
            XB_SO_GOTO(7);
            xb_SeSelectedThunk();
        }

        break;
    }

    if (xb_XLIVE_WORK_CLASS_Frame(D_00798CAC) == 0) {
        xb_xlive_main_DrawLogonError(*(s32*)(D_00798CAC + 0x2D4));
        XB_SO_DRAW_USERS();
    }

    return r;
}

s32 xb_LivePadUp(void);
s32 xb_LivePadDown(void);
s32 xb_LivePadLeft(void);
s32 xb_LivePadRight(void);
void xb_SeCursorMoveThunk(void);
void xb_xlive_disp_DrawFocusBar(f32 x, f32 y, f32 w);
void xb_xlive_disp_CheckIndex(s32 index, s32 a, s32 b);
void xb_xlive_disp_DrawTextBox(f32 x, f32 y, f32 s, s32 text, f32 alpha, s32 flags);
s32 CXBMemUnit_GetMemUnitChanges(u32* ins, u32* rem);
extern char* D_007991F4;
extern char* D_0079931C;
extern f32 D_002B82E0;
extern f32 D_002B82DC;
extern f32 D_002B4D94;
extern f32 D_00219408;

/* xb_XLIVE_SIGNON_DrawCursor 0x111641: the account list's cursor bar
 * on row, with the signed-on mark beside it when the cursor is on the
 * signed-on account (D_00418620). */
void XB_FASTCALL xb_XLIVE_SIGNON_DrawCursor(u8* self, s32 edx, void* users, s32 row) {
    (void)self;
    (void)edx;

    if ((u8)xb_vector_XONLINE_USER_empty(users)) {
        return;
    }

    xb_xlive_disp_DrawFocusBar(D_00219408, D_002B4D94, row - 1);

    if (*(s32*)(D_00798CAC + 0x1C4) != 0 && D_00418620 == *(s32*)(D_00798CAC + 0x23B4)) {
        xb_xlive_disp_CheckIndex(0, -0x14, 0);
    }
}

#define XB_SO_CUR (*(s32*)(D_00798CAC + 0x23B4))
#define XB_SO_TOP (*(s32*)(D_00798CAC + 0x23BC))
#define XB_SO_USERS (D_00798CAC + 0x18)
#define XB_SO_COUNT() std__vector_XONLINE_USER__size(XB_SO_USERS)

/* xb_XLIVE_SIGNON_AccountList 0x112251 (step 1): the console's accounts
 * (read again when a memory unit comes or goes), six to a page: up and
 * down move, left and right turn the page, the right trigger asks for the
 * dashboard (step 2), A picks the account (its xuid +0x10, its name at
 * the work's +0x64 and +0x74; a pass-coded one goes to step 4, else to
 * logon, step 5; with the account preset, +0x18, this happens at once), B
 * closes the list and leaves the Live menu. */
s32 XB_FASTCALL xb_XLIVE_SIGNON_AccountList(u8* self) {
    s32 r = 0;
    u32 ins;
    u32 rem;
    u8* u;
    XB_ARG a;
    XB_ARG b;

    switch (XB_SO_SUB) {
    case 0:
        XB_SO_SUB++;
        CXBOnlineTask_Close(D_00798CAC + 0xF8);
        *(s32*)(self + 0x1C) = 0;
        /* fallthrough */
    case 1:
        if (*(s32*)(self + 0x18) != 0) {
            goto pick;
        }

        if (CXBMemUnit_GetMemUnitChanges(&ins, &rem)) {
            ((void (XB_FASTCALL*)(void*))xb_xlive_disp_Thunk108FA6)(XB_SO_USERS);

            if (xb_xlive_GetUserList(XB_SO_USERS) < 0) {
                xb_XLIVE_WORK_CLASS_SetState4(D_00798CAC);
                r = xb_xlive_main_SetErrorArgs(5, D_002B8240, 0xF4, 1);
                goto draw;
            }

            XB_SO_TOP = 0;
            XB_SO_CUR = XB_SO_TOP;
        }

        if (xb_LivePadUp()) {
            if (--XB_SO_CUR < 0) {
                XB_SO_CUR = 0;
            } else {
                xb_SeCursorMoveThunk();
            }

            if (XB_SO_CUR < XB_SO_TOP) {
                XB_SO_TOP = XB_SO_CUR;

                if (XB_SO_TOP < 0) {
                    XB_SO_TOP = 0;
                }
            }
        }

        if (xb_LivePadDown()) {
            XB_SO_CUR++;

            if ((u32)XB_SO_CUR >= XB_SO_COUNT()) {
                XB_SO_CUR = XB_SO_COUNT() - 1;
            } else {
                xb_SeCursorMoveThunk();
            }

            if (XB_SO_CUR >= XB_SO_TOP + 6) {
                XB_SO_TOP = XB_SO_CUR - 5;

                if ((u32)XB_SO_TOP >= XB_SO_COUNT() - 6) {
                    XB_SO_TOP = XB_SO_COUNT() - 6;
                }
            }
        }

        if (xb_LivePadLeft()) {
            XB_SO_TOP -= 6;

            if (XB_SO_TOP < 0) {
                XB_SO_TOP = 0;
            }

            if (XB_SO_CUR != 0) {
                xb_SeCursorMoveThunk();
            }

            XB_SO_CUR -= 6;

            if (XB_SO_CUR < 0) {
                XB_SO_CUR = 0;
            }
        }

        if (xb_LivePadRight()) {
            XB_SO_TOP += 6;

            if (XB_SO_TOP >= (s32)(XB_SO_COUNT() - 6)) {
                XB_SO_TOP = XB_SO_COUNT() - 6;

                if (XB_SO_TOP < 0) {
                    XB_SO_TOP = 0;
                }
            }

            if ((u32)XB_SO_CUR != XB_SO_COUNT() - 1) {
                xb_SeCursorMoveThunk();
            }

            XB_SO_CUR += 6;

            if ((u32)XB_SO_CUR >= XB_SO_COUNT()) {
                XB_SO_CUR = XB_SO_COUNT() - 1;
            }
        }

        if (xb_LivePadTrigger(0x200)) {
            XB_SO_STEP = 2;
            XB_SO_SUB = 0;
            goto draw;
        }

        if (!(u8)xb_vector_XONLINE_USER_empty(XB_SO_USERS) && xb_LivePadAccept()) {
        pick:
            *(s32*)(D_00798CAC + 0x10) = XB_SO_CUR;
            a.v = *(s32*)(D_00798CAC + 0x10);
            u = ((u8* (XB_FASTCALL*)(void*, XB_ARG))xb_vector_XONLINE_USER_Subscript)(XB_SO_USERS, a);
            *(u32*)(self + 0x10) = *(u32*)u;
            *(u32*)(self + 0x14) = *(u32*)(u + 4);
            a.v = *(s32*)(D_00798CAC + 0x10);
            strcpy((char*)(D_00798CAC + 0x64),
                   (char*)(((u8* (XB_FASTCALL*)(void*, XB_ARG))xb_vector_XONLINE_USER_Subscript)(XB_SO_USERS, a) + 0xC));
            mbstowcs((u16*)(D_00798CAC + 0x74), (char*)(D_00798CAC + 0x64), 0x10);
            a.v = *(s32*)(D_00798CAC + 0x10);

            if (((u8* (XB_FASTCALL*)(void*, XB_ARG))xb_vector_XONLINE_USER_Subscript)(XB_SO_USERS, a)[0x1C] & 1) {
                XB_SO_STEP = 4;
            } else {
                XB_SO_STEP = 5;
                *(s32*)(D_00798CAC + 0x2370) = 0;
            }

            XB_SO_SUB = 0;
            xb_SeSelectedThunk();
            goto draw;
        }

        if (xb_LivePadBack()) {
            XB_SO_SUB++;
            xb_SeSelectedThunk();
            xb_xlive_main_CloseWin();
            xb_OnlineObj_Fade(*(s32*)self);
            xb_OnlineObj_Fade(*(s32*)(self + 4));
        }

    draw:
        if (xb_XLIVE_WORK_CLASS_Frame(D_00798CAC) != 0) {
            break;
        }

        if (!(u8)xb_vector_XONLINE_USER_empty(XB_SO_USERS)) {
            xb_xlive_disp_DrawMessageDefault(0, 3, 0);
            xb_xlive_disp_DrawMessageRight(0, 4, 0);
        } else {
            xb_xlive_disp_DrawMessageDefault(0, 1, 0);
            xb_xlive_disp_DrawMessageRight(0, 2, 0);
        }

        XB_SO_DRAW_USERS();
        a.v = (s32)XB_SO_USERS;
        b.v = XB_SO_CUR - XB_SO_TOP + 5;
        ((void (XB_FASTCALL*)(u8*, XB_ARG, XB_ARG))xb_XLIVE_SIGNON_DrawCursor)(self, a, b);

        if (XB_SO_TOP != 0) {
            xb_xlive_disp_DrawTextBox(D_002B82E0, D_002AEEE8, D_0025F370, (s32)D_007991F4, 1.0f, 5);
        }

        if ((u32)(XB_SO_TOP + 6) < XB_SO_COUNT()) {
            xb_xlive_disp_DrawTextBox(D_002B82E0, D_002B82DC, D_0025F370, (s32)D_0079931C, 1.0f, 5);
        }

        break;
    case 2:
        if (xb_OnlineObj_IsDone(*(s32*)self) && xb_OnlineObj_IsDone(*(s32*)(self + 4))) {
            XB_SO_STEP = 7;
            XB_SO_SUB = 0;
            *(s32*)(D_00798CAC + 0x2364) = 6;
            xb_xlive_friend_Release(*(s32*)self);
            xb_xlive_friend_Release(*(s32*)(self + 4));
            xb_xlive_disp_ReleaseAllThunk();
        }

        xb_XLIVE_WORK_CLASS_Frame(D_00798CAC);
        break;
    }

    return r;
}

s32 XB_STDCALL XOnlineLogon(const void* users, const u32* services, u32 n, void* ev, void* task);
s32 XB_STDCALL XOnlineLogonTaskGetResults(s32 task);
u8* XB_STDCALL XOnlineGetLogonUsers(void);
s32 XB_STDCALL XOnlineGetServiceInfo(u32 id, void* info);
s32 XB_FASTCALL CXBOnlineTask_Continue(void* self);
s32 XB_FASTCALL CXBOnlineTask_operator_addr(void* self);
s32 XB_FASTCALL xb_iterator_Deref(u8* self);
s32 xb_xlive_net_Startup(void);
s32 XB_FASTCALL xb_XLIVE_FRIEND_CLASS_Start(u8* self, s32 edx, s32 user);
void XB_FASTCALL xb_XLIVE_WORK_CLASS_ClearRecent(u8* self);
s32 XB_FASTCALL xb_XLIVE_WORK_CLASS_CloseFriendTasks(u8* self);
s32 XB_FASTCALL xb_XLIVE_WORK_CLASS_CloseMatchTask(u8* self);
s32 XB_FASTCALL xb_XLIVE_WORK_CLASS_PollMuteList(u8* self);
s32 XB_FASTCALL xb_XLIVE_WORK_CLASS_LoadStats(u8* self);
void XB_FASTCALL xb_VOICECHAT_CLASS_Start(u8* self);
void XB_FASTCALL xb_LiveObj_SetHandler(u8* self, s32 edx, s32 h);
u8* XB_FASTCALL xb_XLIVE_PLAYER_ctor(u8* self);
void XB_FASTCALL xb_deque_LiveObj_PushBack(u8* self, s32 edx, u8* rec);
void XB_FASTCALL xb_xlive_main_ClearWin(void* self);
extern char D_002B82E4[];
void XB_FASTCALL xb_deque_LiveObj_Clear(u8* self);
s32 XB_FASTCALL xb_XLIVE_WORK_CLASS_SetMatchDone(u8* self);

/* xb_xlive_Logon 0x11B830 and the other XOnline wrappers of the sign-on. */
s32 xb_xlive_Logon(const void* users, const u32* services, u32 n, void* ev, void* task) {
    return XOnlineLogon(users, services, n, ev, task);
}

s32 xb_xlive_LogonGetResults(s32 task) {
    return XOnlineLogonTaskGetResults(task);
}

u8* xb_xlive_GetLogonUsers(void) {
    return XOnlineGetLogonUsers();
}

s32 xb_xlive_GetServiceInfo(u32 id, void* info) {
    return XOnlineGetServiceInfo(id, info);
}

/* xb_LiveObj_Set54 0x111348: the voice object's +0x54. */
void XB_FASTCALL xb_LiveObj_Set54(u8* self, s32 edx, s32 v) {
    (void)edx;
    *(s32*)(self + 0x54) = v;
}

/* xb_XLIVE_SIGNON_CheckServices 0x1113E0: each of the four services the
 * title uses (the work's +0x94) checked, stopping at an error. */
s32 XB_FASTCALL xb_XLIVE_SIGNON_CheckServices(u8* self) {
    s32 off;
    s32 r;

    (void)self;

    for (off = 0x94; off < 0xA4; off += 4) {
        r = xb_xlive_GetServiceInfo(*(u32*)(D_00798CAC + off), 0);

        if (r < 0) {
            break;
        }
    }

    return r;
}

/* xb_XLIVE_SIGNON_IsHardError 0x111408: 0 for the logon errors that keep
 * the logon task (no service, cannot reach Live, no account, the network
 * check), else 1. */
s32 XB_FASTCALL xb_XLIVE_SIGNON_IsHardError(u8* self, s32 edx, s32 hr) {
    (void)self;
    (void)edx;

    if (hr == (s32)0x80151002 || hr == (s32)0x80151200 || hr == (s32)0x80151001 || hr == (s32)0x80151006) {
        return 0;
    }

    return 1;
}

/* xb_XLIVE_SIGNON_LogonFailed 0x111432: the logon task (the work's
 * +0xF8) closed unless the error keeps it. */
void XB_FASTCALL xb_XLIVE_SIGNON_LogonFailed(u8* self, s32 edx, s32 hr) {
    XB_ARG a;

    (void)edx;
    a.v = hr;

    if (((s32 (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_SIGNON_IsHardError)(self, a)) {
        CXBOnlineTask_Close(D_00798CAC + 0xF8);
    }
}

#define XB_SO_FAIL(hr_, line_)                                                                \
    (a.v = (hr_), ((void (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_SIGNON_LogonFailed)(self, a),   \
     XB_SO_STEP = 6, XB_SO_SUB = 0, xb_xlive_main_SetMatchArgs((hr_), D_002B8240, (line_), 0))

/* xb_XLIVE_SIGNON_Logon 0x11280C (step 5): the chosen account logged on
 * to Live with the title's services, the network started; then the
 * logon polled (an account that needs attention: sub-step 3, asking for
 * the dashboard), the user's and the services' results checked, the
 * friend list started, the signed-on player (the work's sign-on list
 * +0x28) and the voice chat set up; then the mute list and the user's own
 * stats read, the voice output set, a moment's message, and the Live
 * menu (the Live work's state 2). Any error: the logon-error step (6). */
s32 XB_FASTCALL xb_XLIVE_SIGNON_Logon(u8* self) {
    u8 users[4][0x70];
    u8 player[0xB0];
    u8* lu;
    u8* p;
    u8* u;
    s32 hr;
    s32 i;
    XB_ARG a;
    XB_ARG b;

    memset(users, 0, sizeof(users));
    xb_XLIVE_PLAYER_ctor(player);

    switch (XB_SO_SUB) {
    case 0:
        XB_SO_SUB++;
        xb_deque_LiveObj_Clear(D_00798CAC + 0x28);
        a.v = *(s32*)(D_00798CAC + 0x10);
        memcpy(users[*(s32*)(D_00798CAC + 0x14)],
               ((u8* (XB_FASTCALL*)(void*, XB_ARG))xb_vector_XONLINE_USER_Subscript)(XB_SO_USERS, a), 0x70);
        hr = xb_xlive_Logon(users, (u32*)(D_00798CAC + 0x94), 4, 0, (void*)CXBOnlineTask_operator_addr(D_00798CAC + 0xF8));

        if (hr < 0) {
            XB_SO_FAIL(hr, 0x2D4);
            return 0;
        }

        if (xb_xlive_net_Startup() != 0) {
            xb_XLIVE_WORK_CLASS_SetState4(D_00798CAC);
            return xb_xlive_main_SetErrorArgs(2, D_002B8240, 0x2DC, 1);
        }

        /* fallthrough */
    case 1:
        hr = CXBOnlineTask_Continue(D_00798CAC + 0xF8);

        if (hr < 0) {
            XB_SO_FAIL(hr, 0x2F3);
        } else if (hr == 0x1512F0) {
            XB_SO_SUB = 3;
        } else if (hr != 0) {
            hr = xb_xlive_LogonGetResults(xb_iterator_Deref(D_00798CAC + 0xF8));

            if (hr < 0) {
                XB_SO_FAIL(hr, 0x305);
            } else if (hr == 0x1512F0) {
                XB_SO_SUB = 3;
            } else if (hr == 0x1510F0) {
                XB_SO_SUB = 2;
            }
        }

        break;
    case 2:
        XB_SO_SUB++;
        lu = xb_xlive_GetLogonUsers();

        if (lu == 0) {
            _assert(D_002B82E4, D_002B8240, 0x329);
            CXBOnlineTask_Close(D_00798CAC + 0xF8);
            XB_SO_STEP = 6;
            XB_SO_SUB = 0;
            xb_xlive_main_SetErrorArgs(4, D_002B8240, 0x32E, 0);
            break;
        }

        hr = *(s32*)(lu + *(s32*)(D_00798CAC + 0x14) * 0x70 + 0x6C);

        if (hr < 0) {
            XB_SO_FAIL(hr, 0x338);
            break;
        }

        if (hr == 0x1512F0 && *(s32*)(self + 0x1C) == 0) {
            XB_SO_SUB = 3;
            break;
        }

        hr = xb_XLIVE_SIGNON_CheckServices(self);

        if (hr < 0) {
            XB_SO_FAIL(hr, 0x34A);
            break;
        }

        *(s32*)(D_00798CAC + 0x144) = 1;
        memset(D_00798CAC + 0xB4, 0, 8);
        a.v = *(s32*)(D_00798CAC + 0x14);
        hr = ((s32 (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_FRIEND_CLASS_Start)(D_00798CAC + 0x25D0, a);

        if (hr < 0) {
            XB_SO_FAIL(hr, 0x35A);
            break;
        }

        xb_XLIVE_WORK_CLASS_ClearRecent(D_00798CAC);
        XB_SO_SUB = 4;
        *(s32*)(D_00798CAC + 0xC) = 1;
        *(s32*)(D_00798CAC + 0x150) = 0;
        *(s32*)(D_00798CAC + 0x158) = 0;

        for (i = 4, p = lu; i != 0; i--, p += 0x70) {
            a.v = *(s32*)(D_00798CAC + 0x10);
            u = ((u8* (XB_FASTCALL*)(void*, XB_ARG))xb_vector_XONLINE_USER_Subscript)(XB_SO_USERS, a);

            if (*(u32*)u == *(u32*)p && *(u32*)(u + 4) == *(u32*)(p + 4)) {
                u = ((u8* (XB_FASTCALL*)(void*, XB_ARG))xb_vector_XONLINE_USER_Subscript)(XB_SO_USERS, a);

                if (!((*(u32*)(u + 8) ^ *(u32*)(p + 8)) & 3)) {
                    memcpy(player, p, 12);
                }
            }
        }

        a.v = *(s32*)(D_00798CAC + 0x10);
        mbstowcs((u16*)(player + 0x10),
                 (char*)(((u8* (XB_FASTCALL*)(void*, XB_ARG))xb_vector_XONLINE_USER_Subscript)(XB_SO_USERS, a) + 0xC), 0x10);
        *(s32*)(player + 0xA0) = *(s32*)(D_00798CAC + 0x14);
        *(s32*)(player + 0xA8) = 0;
        a.v = (s32)player;
        ((void (XB_FASTCALL*)(u8*, XB_ARG))xb_deque_LiveObj_PushBack)(D_00798CAC + 0x28, a);
        xb_VOICECHAT_CLASS_Start(D_00798CAC + 0x2408);
        break;
    case 3:
        if (xb_LivePadAccept()) {
            XB_SO_DASHBOARD(8);
        } else if (xb_LivePadBack()) {
            XB_SO_SUB = 2;
            xb_SeSelectedThunk();
            *(s32*)(self + 0x1C) = 1;
        }

        if (xb_XLIVE_WORK_CLASS_Frame(D_00798CAC) != 0) {
            return 0;
        }

        xb_xlive_main_DrawLogonError(0x1512F0);
        goto draw_users;
    case 4:
        switch (*(s32*)(D_00798CAC + 0x2370)) {
        case 0:
            (*(s32*)(D_00798CAC + 0x2370))++;

            if (xb_XLIVE_WORK_CLASS_CloseMatchTask(D_00798CAC) == -1) {
                goto fail4;
            }

            /* fallthrough */
        case 1:
            hr = xb_XLIVE_WORK_CLASS_PollMuteList(D_00798CAC);

            if (hr == -1) {
                goto fail4;
            }

            if (hr == 1) {
                *(s32*)(D_00798CAC + 0x2370) = 0x63;
            }

            break;
        default:
            XB_SO_SUB++;
            *(s32*)(D_00798CAC + 0x2370) = 0;
            break;
        fail4:
            xb_XLIVE_WORK_CLASS_SetState4(D_00798CAC);
            xb_XLIVE_WORK_CLASS_CloseFriendTasks(D_00798CAC);
            break;
        }

        break;
    case 5:
        hr = xb_XLIVE_WORK_CLASS_LoadStats(D_00798CAC);

        if (hr == -1) {
            xb_XLIVE_WORK_CLASS_SetState4(D_00798CAC);
            xb_XLIVE_WORK_CLASS_ResetSessions(D_00798CAC);
            break;
        }

        if (hr == 0) {
            break;
        }

        if (hr != 1) {
            _assert(D_0025CCA0, D_002B8240, 0x407);
            xb_XLIVE_WORK_CLASS_SetState4(D_00798CAC);
            xb_XLIVE_WORK_CLASS_ResetSessions(D_00798CAC);
            break;
        }

        XB_SO_SUB = 6;
        *(s32*)(D_00798CAC + 0x23C0) = 0x1E;
        a.v = 0;
        ((void (XB_FASTCALL*)(u8*, XB_ARG))xb_LiveObj_SetHandler)(xb_LiveWork_Get2408(D_00798CAC), a);
        a.v = *(s32*)(D_00798CAC + 0x14);

        if (((s32 (XB_FASTCALL*)(u8*, XB_ARG))xb_LiveObj_Process)(xb_LiveWork_Get2408(D_00798CAC), a) == 2) {
            b.v = 1;
            ((s32 (XB_FASTCALL*)(u8*, XB_ARG, XB_ARG))CXHVVoiceManager_SetVoiceThroughSpeakers)(
                xb_LiveObj_Get8(xb_LiveWork_Get2408(D_00798CAC)), a, b);
            *(s32*)(xb_LiveWork_Get2408(D_00798CAC) + 0x94) = 1;
        }

        a.v = 0;
        a.v = ~*(u16*)(((u8* (XB_FASTCALL*)(u8*, XB_ARG))xb_deque_LiveObj_Subscript)(D_00798CAC + 0x28, a) + 0xA) & 1;
        ((void (XB_FASTCALL*)(u8*, XB_ARG))xb_LiveObj_Set54)(xb_LiveWork_Get2408(D_00798CAC), a);
        break;
    case 6:
        if (--*(s32*)(D_00798CAC + 0x23C0) == 0) {
            XB_SO_SUB++;
            xb_xlive_main_ClearWin(D_00798CAC);
            xb_OnlineObj_Fade(*(s32*)self);
            xb_OnlineObj_Fade(*(s32*)(self + 4));
        }

        if (xb_XLIVE_WORK_CLASS_Frame(D_00798CAC) != 0) {
            return 0;
        }

        xb_xlive_disp_DrawMessageDefault(0, 0x14, 0);
        goto draw_users;
    case 7:
        if (xb_OnlineObj_IsDone(*(s32*)self) && xb_OnlineObj_IsDone(*(s32*)(self + 4))) {
            *(s32*)(D_00798CAC + 0x2364) = 2;
            XB_SO_STEP = 0;
            XB_SO_SUB = 0;

            if (*(s32*)(D_00798CAC + 0x1C4) != 0) {
                a.v = 0;
                u = ((u8* (XB_FASTCALL*)(u8*, XB_ARG))xb_deque_LiveObj_Subscript)(D_00798CAC + 0x28, a);

                if (*(u32*)(D_00798CAC + 0x220) == *(u32*)u && *(u32*)(D_00798CAC + 0x224) == *(u32*)(u + 4)) {
                    memcpy(D_00798CAC + 0x168, D_00798CAC + 0x1C8, 0x56);
                    *(s32*)(D_00798CAC + 0x164) = 3;
                    xb_XLIVE_WORK_CLASS_SetMatchDone(D_00798CAC);
                    xb_LiveWork_ClearStartMenu();
                    a.v = 1;
                    ((void (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_WORK_CLASS_Set235C)(D_00798CAC, a);
                }
            }

            xb_xlive_friend_Release(*(s32*)self);
            xb_xlive_friend_Release(*(s32*)(self + 4));
        }

        xb_XLIVE_WORK_CLASS_Frame(D_00798CAC);
        return 0;
    default:
        return 0;
    }

    if (xb_XLIVE_WORK_CLASS_Frame(D_00798CAC) != 0) {
        return 0;
    }

    xb_xlive_disp_DrawMessageDefault(0, 0x12, 0);
draw_users:
    XB_SO_DRAW_USERS();
    a.v = (s32)XB_SO_USERS;
    b.v = XB_SO_CUR - XB_SO_TOP + 2;
    ((void (XB_FASTCALL*)(u8*, XB_ARG, XB_ARG))xb_XLIVE_SIGNON_DrawCursor)(self, a, b);
    return 0;
}

void SE_dir_cursor_move(void);

/* xb_SeDirCursorThunk 0x113158. */
void xb_SeDirCursorThunk(void) {
    SE_dir_cursor_move();
}

extern s32 D_0079A16C;

/* xb_xlive_net_IsLinkUp 0x11009C: the link is up (xb_xlive_net_SetDone). */
s32 xb_xlive_net_IsLinkUp(void) {
    return D_0079A16C;
}


void Sound_SE(s16 Code);

/* xb_SeNewChallenger 0x113199: the "here comes a new challenger" sound
 * (0xB6). */
void xb_SeNewChallenger(void) {
    Sound_SE(0xB6);
}
