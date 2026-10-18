/* xb_0C7E80.c: Xbox-only code from the run of Xbox-only functions at 0xC7E80, which no
 * PS2 file covers.
 * Capcom's source is lost. Its C++ methods are written as C,
 * XB_FASTCALL (__fastcall) with this first. Each body was checked
 * against retail by analysis-ps2map/xbgen.py. The xb_ names are
 * made up. */

#include "types.h"
#include <string.h>

typedef struct {
    s32 tex;
    u8 quad[0x50];
    s32 mode;
    u8 pad58[4];
} XB_BUTTONIMG;
void xb_PoolFree(void);
extern s8 D_007AA5F1;
extern u8 task[];
extern u16 PLsw[];
extern u16 D_007C556A;
extern u16 D_007C55FE;
void setFilterMode(s32 mode);
s32 ps2SeqsRenderQuadInit_A(void);
typedef struct {
    u8 used;
    u8 a;
    u16 b;
    s32 tex;
    u8 quad[0x54];
} XB_BUTTONQ;
typedef struct {
    s32 count;
    XB_BUTTONQ e[16];
} XB_BUTTONLIST;
extern XB_BUTTONLIST D_007AA618;
extern XB_BUTTONIMG D_007AA620[];
void flSetRenderState(s32 state, s32 value);
void ps2SeqsRenderQuad_A2(void* q, s32 tex);
void ps2SeqsRenderQuadEnd(void);
void xb_ClearButtonImages(void);
s32 XB_STDCALL XGetLanguage(void);
s32 XB_STDCALL XGetGameRegion(void);
extern u8 Turbo;
extern u8 Screen_PAL;
extern u8 Country;
extern u8 Game_pause;
extern u8 Turbo_Timer;
extern u8 Process_Counter;
extern u32 D_007C56B4;

void xb_QueueButtonImage(void* quad, s32 tex, u8 a, u16 b) {
    if (D_007AA618.count < 16) {
        D_007AA618.e[D_007AA618.count].used = 1;
        D_007AA618.e[D_007AA618.count].a = a;
        D_007AA618.e[D_007AA618.count].b = b;
        memcpy(D_007AA618.e[D_007AA618.count].quad, quad, 0x54);
        D_007AA618.e[D_007AA618.count].tex = tex;
        D_007AA618.count++;
    }
}

void xb_DrawButtonImages(void) {
    s32 i;

    setFilterMode(1);
    ps2SeqsRenderQuadInit_A();

    for (i = 0; i < D_007AA618.count; i++) {
        flSetRenderState(4, D_007AA620[i].mode);
        ps2SeqsRenderQuad_A2(D_007AA620[i].quad, D_007AA620[i].tex);
    }

    ps2SeqsRenderQuadEnd();
    xb_ClearButtonImages();
}

s32 xb_GetJapaneseNames(void) {
    return D_007AA5F1;
}

void xb_ShiftWords7C5570(void) {
    PLsw[1] = PLsw[0];
    PLsw[3] = PLsw[2];
    PLsw[0] = D_007C556A;
    PLsw[2] = D_007C55FE;
}

void xb_PoolFreeThunk(void) {
    xb_PoolFree();
}

s32 xb_IsJapaneseNames(void) {
    return D_007AA5F1 != 0;
}

void xb_SetupRegion(void) {
    s32 lang = XGetLanguage();

    Turbo = 0;
    Screen_PAL = 0;

    switch (XGetGameRegion()) {
    default:
        Country = 3;
        break;

    case 2:
        switch (lang) {
        default:
            Country = 2;
            break;

        case 2:
            Country = 1;
            D_007AA5F1 = 1;
            break;
        }

        break;

    case 1:
        Country = 4;
        break;
    }
}

void xb_TurboFrameStep(void) {
    u8* t = task;

    Process_Counter = 1;

    if (Turbo && Game_pause != 0x81 && --Turbo_Timer == 0) {
        Turbo_Timer = Turbo;
        Process_Counter = 2;
    }

    D_007C56B4 = 0;

    do {
        switch (*(u16*)(t + 0xC)) {
        case 1:
            (*(void (**)(void*))t)(t);
            break;

        case 2:
            *(u16*)(t + 0xC) = 1;
            break;
        }

        t += 0x14;
    } while (++D_007C56B4 < 12);
}

void xb_ClearTasks(void) {
    memset(task, 0, 0xF0);
}
