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
void njUserInit(void);
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
void keyConvert(void);
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
        njUserInit();
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
    keyConvert();
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

/* njUserInit 0xC832C.
 *
 * The Xbox njUserInit (the PS2 main.c one, at the same call site): the
 * 384x224 view, memory and the SEQS, PPG, zlib and print work from the
 * work pool, the print palettes (six from D_00332F80, the rest white),
 * the online buffers, RAM control, the screen state, the display size,
 * region (a region of 0 hangs), sound, the first task, and the Xbox
 * Live work. */

typedef struct {
    u32 c0;
    u32 c1;
    u32 c2;
} XB_PRTPAL;

extern struct _SYSTEM_W sys_w;
extern u8 Country;
extern u8 Turbo_Timer;
extern f32 Screen_Zoom_X;
extern f32 Screen_Zoom_Y;
extern f32 Frame_Zoom_X;
extern f32 Frame_Zoom_Y;
extern f32 SA_Zoom_X;
extern f32 SA_Zoom_Y;
extern u8 Disp_Size_H;
extern u8 Disp_Size_V;
extern s32 D_007C59D8;
extern s32 D_007C59C0;
extern s32 D_007C56AC;
extern void* D_007AA5A4;
extern u8 D_00334900[];
extern XB_PRTPAL D_00332F80[6];
void mmSystemInitialize(void);
void xb_WorkPoolGetBlock(void* frame);
u32 seqsGetUseMemorySize(void);
void* xb_WorkPoolAllocThunk(u32 size);
void seqsInitialize(void* adrs);
void ppg_Initialize(void* adrs, s32 size);
void zlib_Initialize(void* adrs, s32 size);
u32 xb_GetExtraLoadBufferSize(void);
void xb_PrintInit(void* buf);
void xb_PrintResetAll(void);
void xb_SetExtraLoadBuffer(void* buf);
void xb_PrintSetPalette(s32 page, u32 c0, u32 c1, u32 c2, u32 c3);
void xb_Set7970F4(void);
void xb_InitOnlineBuffers(void);
u32 xb_WorkPoolUsedSize(void);
void Init_ram_control_work(u8* adrs, s32 size);
void xb_ResetScreenState(void);
void xb_SetupRegion(void);
void Setup_Disp_Size(s32 flag);
void xb_ResetInputState(void);
void Init_sound_system(void);
void Init_bgm_work(void);
void Setup_Directory_Record_Data(void);
void sndInitialLoad(void);
void cpReadyTask(u16 num, void* func_adrs);
void Init_Task(struct _TASK* task_ptr);
void xb_SetScreenShotColor(u32 color);
void xb_ClearButtonImages(void);
void xb_LiveWork_Init(void);
void xb_LiveWork_Create(void);
void xb_LiveWork_Call1071C4(void);
void xb_LiveWork_Set268(s32 v);

void njUserInit(void) {
    u32 size;
    s32 i;

    mpp_w.vprm.x0 = 0.0f;
    mpp_w.vprm.y0 = 0.0f;
    mpp_w.vprm.x1 = 384.0f;
    mpp_w.vprm.y1 = 224.0f;
    mpp_w.vprm.ne = -1.0f;
    mpp_w.sysStop = 0;
    mpp_w.inGame = 0;
    mpp_w.ctrDemo = 0;
    mpp_w.language = 0;
    mpp_w.langload = -1;
    mpp_w.xb_unk35 = 0;
    mpp_w.vprm.fa = 1.0f;
    appViewSetItems(&mpp_w.vprm);
    appViewMatrix();
    mmSystemInitialize();
    xb_WorkPoolGetBlock(&mpp_w.fmsFrame);
    seqsInitialize(xb_WorkPoolAllocThunk(seqsGetUseMemorySize()));
    ppg_Initialize(xb_WorkPoolAllocThunk(0x60000), 0x60000);
    zlib_Initialize(xb_WorkPoolAllocThunk(0x10000), 0x10000);
    xb_PrintInit(xb_WorkPoolAllocThunk(xb_GetExtraLoadBufferSize()));
    xb_PrintResetAll();
    xb_SetExtraLoadBuffer(D_00334900);

    for (i = 0; i < 6; i++) {
        xb_PrintSetPalette(i, 0, D_00332F80[i].c0, D_00332F80[i].c1, D_00332F80[i].c2);
    }

    for (; i < 16; i++) {
        xb_PrintSetPalette(i, 0, -1, -1, -1);
    }

    xb_Set7970F4();
    D_007AA5A4 = xb_WorkPoolAllocThunk(0xD400);
    xb_InitOnlineBuffers();
    size = xb_WorkPoolUsedSize();
    mpp_w.ramcntBuff = xb_WorkPoolAllocThunk(size);
    Init_ram_control_work(mpp_w.ramcntBuff, size);
    xb_ResetScreenState();

    for (i = 0; i < 20; i++) {
        mpp_w.useChar[i] = 0;
    }

    Interrupt_Timer = 0;
    SA_Zoom_X = 0.0f;
    SA_Zoom_Y = 0.0f;
    Disp_Size_H = 100;
    Disp_Size_V = 100;
    mpp_w.ds_h[1] = 100;
    mpp_w.ds_h[0] = 100;
    mpp_w.ds_v[1] = 100;
    mpp_w.ds_v[0] = 100;
    Country = 0;
    xb_SetupRegion();

    if (Country == 0) {
        while (1) {
        }
    }

    Turbo_Timer = 1;
    Screen_Zoom_X = 1.0f;
    Screen_Zoom_Y = 1.0f;
    Setup_Disp_Size(0);
    Frame_Zoom_X = Screen_Zoom_X + SA_Zoom_X;
    Correct_X[0] = 0;
    Correct_Y[0] = 0;
    Frame_Zoom_Y = Screen_Zoom_Y + SA_Zoom_Y;
    D_007C59D8 = 0;
    D_007C59C0 = 0;
    D_007C56AC = 0;
    sys_w.disp.new = 1;
    sys_w.disp.now = 1;
    sys_w.pause = 0;
    sys_w.reset = 0;
    xb_ResetInputState();
    Init_sound_system();
    Init_bgm_work();
    Setup_Directory_Record_Data();
    sndInitialLoad();
    xb_ClearTasks();
    cpReadyTask(0, Init_Task);
    xb_SetScreenShotColor(0xFFFFFF);
    xb_ClearButtonImages();
    xb_LiveWork_Init();
    xb_LiveWork_Create();
    xb_LiveWork_Call1071C4();
    xb_LiveWork_Set268(0);
}

/* xb_DrawScreenBorder 0xC7F57.
 *
 * With full-screen drawing on, masks the edges past the game screen
 * with two black quads (right and bottom): for the 640x480 layout when
 * D_00796888 is 1, otherwise for the 384x224 one. */

extern f32 PrioBase[];
void appViewGetItems(void* prm);
s32 getCP3toFullScreenDrawFlag(void);
void njdp2d_sort(f32* pos, f32 pri, u32 col, s32 flag);

void xb_DrawScreenBorder(void) {
    f32 q[8];
    VPRM vprm;

    appViewGetItems(&vprm);

    if (!getCP3toFullScreenDrawFlag()) {
        return;
    }

    if (D_00796888 == 1) {
        q[4] = q[0] = 640.0f;
        q[6] = q[2] = 704.0f;
        q[3] = q[1] = 0.0f;
        q[7] = q[5] = 544.0f;
        njdp2d_sort(q, PrioBase[0], 0xFF000000, 2);
        q[4] = q[0] = 0.0f;
        q[6] = q[2] = 641.0f;
        q[3] = q[1] = 480.0f;
        q[7] = q[5] = 544.0f;
    } else {
        q[4] = q[0] = 384.0f;
        q[6] = q[2] = 448.0f;
        q[3] = q[1] = 0.0f;
        q[7] = q[5] = 288.0f;
        njdp2d_sort(q, PrioBase[0], 0xFF000000, 2);
        q[4] = q[0] = 0.0f;
        q[6] = q[2] = 385.0f;
        q[3] = q[1] = 224.0f;
        q[7] = q[5] = 288.0f;
    }

    njdp2d_sort(q, PrioBase[0], 0xFF000000, 2);
}

/* xb_ResetScreenState 0xC8106.
 *
 * Resets the priorities, render state, a 640x448 view and display area
 * on black, and draws three black frames to clear the screen. */

void appSetupBasePriority(void);
void xb_SetViewportRect(s32 x, s32 y, s32 w, s32 h);
void xb_DrawTexturedRect(s32 x, s32 y, s32 a, s32 w, s32 h, u32 col, s32 b, s32 c);

void xb_ResetScreenState(void) {
    s32 i;

    appSetupBasePriority();
    appSetupTempPriority();
    initRenderState(0);
    mpp_w.vprm.x0 = 0.0f;
    mpp_w.vprm.y0 = 0.0f;
    mpp_w.vprm.x1 = 640.0f;
    mpp_w.vprm.y1 = 448.0f;
    mpp_w.vprm.ne = -1.0f;
    mpp_w.vprm.fa = 1.0f;
    appViewSetItems(&mpp_w.vprm);
    appViewMatrix();
    xb_SetDisplayArgs(0, 0);
    setBackGroundColor(0xFF000000);
    xb_SetViewportRect(0, 0, 640, 448);

    for (i = 3; i != 0; i--) {
        njdp2d_init();
        render_start();
        xb_DrawTexturedRect(0, 0, 7, 640, 448, 0xFF000000, 0, 8);
        njdp2d_draw(8);
        render_end();
        xb_EndFrame(0);
    }
}
