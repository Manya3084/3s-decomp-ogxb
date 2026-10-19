/* xb_0C8301.c: Xbox-only code from the run of Xbox-only functions at 0xC8301, which no
 * PS2 file covers.
 * Capcom's source is lost. Its C++ methods are written as C,
 * XB_FASTCALL (__fastcall) with this first. Each body was checked
 * against retail by analysis-ps2map/xbgen.py. The xb_ names are
 * made up. */

#include "types.h"
#include "structs.h"

void xb_ClearTasks(void);
extern struct _TASK task[12];
extern MPP mpp_w;
extern s32 D_00796880;
extern u8 D_00796888;
extern s32 D_007A138C;
extern s32 system_init_level;
extern s16 Correct_X[2];
extern s16 Correct_Y[2];
extern s32 X_Adjust;
extern s32 Y_Adjust;
extern u8 Play_Mode;
extern u8 Game_pause;
extern u8 Mode_Type;
extern u8 Interrupt_Flag;
extern u32 Interrupt_Timer;
extern u16 p1sw_0;
extern u16 p1sw_1;
extern u16 p2sw_0;
extern u16 p2sw_1;
extern u16 p3sw_0;
extern u16 p3sw_1;
extern u16 p4sw_0;
extern u16 p4sw_1;
extern u16 p1sw_buff;
extern u16 p2sw_buff;
extern u16 p3sw_buff;
extern u16 p4sw_buff;
void xb_InitVideoMemory(s32 w, s32 h);
s32 flSetRenderState(s32 func, u32 value);
void ppgWorkInitializeApprication(void);
void xb_InitDisplayArea(void);
void palCreateGhost(void);
void ppgMakeConvTableTexDC(void);
void njdp2d_init(void);
void initRenderState(s32 a);
void xb_LiveWork_Set2330(s32 arg);
void appViewSetItems(void* prm);
void appViewMatrix(void);
void xb_SetDisplayArgs(s32 x, s32 y);
void setBackGroundColor(u32 color);
void appSetupTempPriority(void);
void flPADGetALL(void);
void xb_AssignPadsToPlayers(void);
void xb_ShiftWords7C5570(void);
void xb_LiveWork_GetState(void);
void xb_LiveWork_Poll24C0(void);
void render_start(void);
void render_end(void);
void xb_DrawScreenBorder(void);
void xb_GetPadRemovedState(void);
void seqsBeforeProcess(void);
void seqsAfterProcess(void);
s32 xb_LiveWork_Get2334(void);
s32 xb_LiveWork_Get2330(void);
void xb_OnlineUpdate(void);
void xb_LiveWork_Update24C0(void);
void xb_DrawFilledRect(s32 w, s32 h, u32 color);
s32 xb_GetOnlineFlagThunk(void);
void xb_OnlineMenuDraw(void);
void njdp2d_draw(u32 mask);
void CP3toPS2Draw(void);
void xb_PrintFlush(void);
void xb_PrintClear(void);
void xb_PrintReset(void);
void xb_DrawButtonImages(void);
void sub_0004384A(void);
void xb_EndFrame(s32 a);
void Scrn_Renew(void);
void Irl_Family(void);
void Irl_Scrn(void);
void BGM_Server(void);
extern u8 CPU_Time_Lag[2];
extern u8 CPU_Rec[2];
extern u8 Replay_Status[2];
extern f32 Frame_Zoom_X;
extern f32 Frame_Zoom_Y;
extern f32 Screen_Zoom_X;
extern f32 Screen_Zoom_Y;
extern f32 SA_Zoom_X;
extern f32 SA_Zoom_Y;
extern struct _SYSTEM_W sys_w;
extern PLW plw[2];
void Check_Replay_Status(s16 PL_id, u8 Status);
void cpLoopTask(void);

void xb_ExitAllTasks(void) {
    struct _TASK* t = task;
    s32 i;

    for (i = 12; i != 0; i--, t++) {
        switch (t->condition) {
        case 1:
        case 4:
            if (t->callback_adrs != 0) {
                t->callback_adrs();
            }

            break;
        }
    }

    xb_ClearTasks();
}

/* SA_Zoom_X is 0x7C55F8 and SA_Zoom_Y is 0x7C59C4. The PS2 "FAKE REC"
 * prints are gone. */
s32 njUserMain(void) {
    CPU_Time_Lag[0] = 0;
    CPU_Time_Lag[1] = 0;
    CPU_Rec[0] = 0;
    CPU_Rec[1] = 0;

    Check_Replay_Status(0, Replay_Status[0]);
    Check_Replay_Status(1, Replay_Status[1]);

    Frame_Zoom_X = Screen_Zoom_X + SA_Zoom_X;
    Frame_Zoom_Y = Screen_Zoom_Y + SA_Zoom_Y;

    if (sys_w.disp.now == sys_w.disp.new) {
        cpLoopTask();

        if ((Game_pause != 0x81) && (Mode_Type == 1) && (Play_Mode == 1)) {
            if ((plw[0].wu.operator == 0) && (CPU_Rec[0] == 0) && (Replay_Status[0] == 1)) {
                p1sw_0 = 0;
                Check_Replay_Status(0, 1);
            }

            if ((plw[1].wu.operator == 0) && (CPU_Rec[1] == 0) && (Replay_Status[1] == 1)) {
                p2sw_0 = 0;
                Check_Replay_Status(1, 1);
            }
        }
    } else {
        sys_w.disp.now = sys_w.disp.new;
    }

    return sys_w.gd_error;
}

/* The pad words: p1sw_buff is 0x7C556A, p2sw_buff is 0x7C55FE, p3sw_buff
 * is 0x7C5C24, p4sw_buff is 0x7C5600, p3sw_0 is 0x7C59D6, p4sw_0 is
 * 0x7C59D4, p3sw_1 is 0x7C56B8, and p4sw_1 is 0x7BE118. Interrupt_Flag is
 * 0x7C5579. SA_Zoom_X is 0x7C55F8 and SA_Zoom_Y is 0x7C59C4. */
void xb_RunFrame(void) {
    u16 sw_buff;

    if (D_00796880 == 0) {
        D_00796880 = 1;
        xb_InitVideoMemory(0x280, 0x1C0);
        flSetRenderState(0x14, 0);
        system_init_level = 0;
        ppgWorkInitializeApprication();
        xb_InitDisplayArea();
        palCreateGhost();
        ppgMakeConvTableTexDC();
        return;
    }

    njdp2d_init();
    initRenderState(0);
    mpp_w.vprm.x0 = 0.0f;
    mpp_w.vprm.y0 = 0.0f;
    mpp_w.vprm.ne = -1.0f;
    mpp_w.ds_h[0] = mpp_w.ds_h[1];
    mpp_w.ds_v[0] = mpp_w.ds_v[1];
    mpp_w.ds_h[1] = 100;
    mpp_w.ds_v[1] = 100;
    mpp_w.vprm.fa = 1.0f;

    if (D_00796888 == 1) {
        mpp_w.vprm.x1 = 640.0f;
        mpp_w.vprm.y1 = 480.0f;
        xb_LiveWork_Set2330(1);
    } else {
        mpp_w.vprm.x1 = (mpp_w.ds_h[0] * 384) / 100.0f;
        mpp_w.vprm.y1 = (mpp_w.ds_v[0] * 224) / 100.0f;
        xb_LiveWork_Set2330(0);
    }

    appViewSetItems(&mpp_w.vprm);
    appViewMatrix();
    xb_SetDisplayArgs(X_Adjust + Correct_X[0], Y_Adjust + Correct_Y[0]);
    setBackGroundColor(0xFF000000);
    appSetupTempPriority();
    flPADGetALL();
    xb_AssignPadsToPlayers();
    Interrupt_Flag = 0;

    if ((Play_Mode != 3 && Play_Mode != 1) || Game_pause != 0x81) {
        p1sw_1 = p1sw_0;
        p2sw_1 = p2sw_0;
        p3sw_1 = p3sw_0;
        p4sw_1 = p4sw_0;
        p1sw_0 = p1sw_buff;
        p2sw_0 = p2sw_buff;
        p3sw_0 = p3sw_buff;
        p4sw_0 = p4sw_buff;

        if (task[3].condition == 1 && Mode_Type == 4 && Play_Mode == 1) {
            sw_buff = p2sw_0;
            p2sw_0 = p1sw_0;
            p1sw_0 = sw_buff;
        }
    }

    xb_ShiftWords7C5570();
    xb_LiveWork_GetState();
    xb_LiveWork_Poll24C0();
    render_start();
    mpp_w.inGame = 0;
    mpp_w.xb_unk2B[0] = 0;
    mpp_w.xb_unk2B[1] = 0;
    mpp_w.xb_unk2B[2] = 0;
    mpp_w.xb_unk2B[3] = 0;
    njUserMain();
    xb_DrawScreenBorder();
    xb_GetPadRemovedState();
    seqsBeforeProcess();

    if (xb_LiveWork_Get2334() == 0) {
        xb_OnlineUpdate();
    }

    xb_LiveWork_Update24C0();

    if (D_007A138C > 0) {
        flSetRenderState(0x6C, 0);
        xb_DrawFilledRect(0x280, 0x1E0, 0xFF000000);
        flSetRenderState(0x6C, 1);
    }

    if (xb_LiveWork_Get2330() == 0) {
        xb_GetOnlineFlagThunk();
    }

    if (xb_GetOnlineFlagThunk()) {
        xb_OnlineMenuDraw();
    }

    njdp2d_draw(7);
    seqsAfterProcess();

    if (xb_LiveWork_Get2334()) {
        xb_OnlineUpdate();
    }

    CP3toPS2Draw();
    xb_PrintFlush();
    xb_PrintClear();
    xb_PrintReset();
    xb_DrawButtonImages();
    njdp2d_draw(0x18);
    render_end();
    sub_0004384A();
    xb_EndFrame(0);
    Interrupt_Timer++;
    Interrupt_Flag = 1;
    Scrn_Renew();
    Irl_Family();
    Irl_Scrn();
    BGM_Server();
}
