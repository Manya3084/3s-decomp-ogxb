/* xb_0F4537.c: Xbox-only code from the run of Xbox-only functions at 0xF4537, which no
 * PS2 file covers.
 * Capcom's source is lost. Its C++ methods are written as C,
 * XB_FASTCALL (__fastcall) with this first. Each body was checked
 * against retail by analysis-ps2map/xbgen.py. The xb_ names are
 * made up. */

#include "types.h"
#include "structs.h"

void xb_PersistDisplay(void);
s32 XB_STDCALL XLaunchNewImageA(const char* path, void* data);
extern s32 D_007970F4;
void xb_RestoreQuadStates(void);
extern s32 D_007970F8;
extern u8 D_007C5959;
extern s32 D_0043FE5C;
void xb_SaveQuadStates(s32 a);
void XB_STDCALL D3DDevice__SetVertexShader(s32 handle);
void dspwhUnpack(u8 dspwh, u8* h, u8* v);
extern u8 D_007BD60A;
extern u8 Disp_Size_H;
extern u8 Disp_Size_V;
void xb_SetViewportRect(s32 x, s32 y, s32 w, s32 h);

s32 Reboot_Program(const char* path) {
    xb_PersistDisplay();
    return XLaunchNewImageA(path, 0);
}

void xb_Set7970F4(void) {
    D_007970F4 = 1;
}

void ps2SeqsRenderQuadEnd(void) {
    xb_RestoreQuadStates();
}

void xb_ApplyDisplaySize(void) {
    dspwhUnpack(D_007BD60A, &Disp_Size_H, &Disp_Size_V);
    xb_SetViewportRect(0, 0, 0x27E - (s32)((100.0f - Disp_Size_H) * (f64)-3.3333333f), 0x34F - Disp_Size_V * 4);
}

/* CP3toPS2Draw 0xF45D1.
 *
 * With full-screen drawing on (CP3toPS2DrawOn) and the game not
 * stopped, sets the display area for the screen size option (the Xbox
 * Live layout when it is active), copies the screen there
 * (xb_DrawCP3Screen) and restores the normal display area. */

extern MPP mpp_w;
extern struct _SAVE_W save_w[6];
s32 xb_LiveWork_Get2330(void);
void xb_DrawCP3Screen(void);

void CP3toPS2Draw(void) {
    s32 w;
    s32 h;

    if (mpp_w.sysStop == 2 || D_007970F8 == 0) {
        return;
    }

    dspwhUnpack(save_w[1].Screen_Size, &Disp_Size_H, &Disp_Size_V);
    w = 0x247 - Disp_Size_H * 2;
    h = 0x1A7 - Disp_Size_V * 2;

    if (xb_LiveWork_Get2330() > 0) {
        w = 0x27F - (s32)((100.0f - Disp_Size_H) * (f64)-3.3333333f);
        h = 0x34F - Disp_Size_V * 4;
    }

    xb_SetViewportRect(0, 0, w, h);
    xb_DrawCP3Screen();
    xb_SetViewportRect(0, 0, 0x27E - (s32)((100.0f - Disp_Size_H) * (f64)-3.3333333f), 0x34F - Disp_Size_V * 4);
}

/* The PS2 ps2Quad.c renderers, drawn with D3D immediate-mode vertices
 * after ps2SeqsRenderQuadInit_A or _B. Each maps the first vertex's z
 * from -1..1 to 0..1 in place and draws a 4-vertex strip. */

s32 XB_STDCALL xb_Begin(s32 type);
s32 xb_End(void);
s32 XB_STDCALL xb_SetVertexDataColor(s32 reg, s32 color);
s32 XB_STDCALL xb_SetVertexData2f(s32 reg, f32 a, f32 b);
void XB_STDCALL D3DDevice__SetVertexData4f(s32 reg, f32 a, f32 b, f32 c, f32 d);

/* ps2SeqsRenderQuad_Ax 0xF4795.
 *
 * A textured rectangle given as two corners, a depth, texture corners
 * and a colour (the print layer's glyph quad). */

void ps2SeqsRenderQuad_Ax(f32* q) {
    q[2] = (q[2] + 1.0f) / 2.0f;
    xb_Begin(6);
    xb_SetVertexDataColor(3, *(s32*)&q[10]);
    xb_SetVertexData2f(9, q[6], q[7]);
    D3DDevice__SetVertexData4f(-1, q[0], q[1], q[2], 1.0f);
    xb_SetVertexData2f(9, q[8], q[7]);
    D3DDevice__SetVertexData4f(-1, q[3], q[1], q[2], 1.0f);
    xb_SetVertexData2f(9, q[6], q[9]);
    D3DDevice__SetVertexData4f(-1, q[0], q[4], q[2], 1.0f);
    xb_SetVertexData2f(9, q[8], q[9]);
    D3DDevice__SetVertexData4f(-1, q[3], q[4], q[2], 1.0f);
    xb_End();
}

/* ps2SeqsRenderQuad_A2 0xF48B1.
 *
 * A sprite drawn as the rectangle between its first and last vertices
 * and texture coordinates. */

void ps2SeqsRenderQuad_A2(Sprite* spr, u32 col) {
    spr->v[0].z = (spr->v[0].z + 1.0f) / 2.0f;
    xb_Begin(6);
    xb_SetVertexDataColor(3, col);
    xb_SetVertexData2f(9, spr->t[0].s, spr->t[0].t);
    D3DDevice__SetVertexData4f(-1, spr->v[0].x, spr->v[0].y, spr->v[0].z, 1.0f);
    xb_SetVertexData2f(9, spr->t[3].s, spr->t[0].t);
    D3DDevice__SetVertexData4f(-1, spr->v[3].x, spr->v[0].y, spr->v[0].z, 1.0f);
    xb_SetVertexData2f(9, spr->t[0].s, spr->t[3].t);
    D3DDevice__SetVertexData4f(-1, spr->v[0].x, spr->v[3].y, spr->v[0].z, 1.0f);
    xb_SetVertexData2f(9, spr->t[3].s, spr->t[3].t);
    D3DDevice__SetVertexData4f(-1, spr->v[3].x, spr->v[3].y, spr->v[0].z, 1.0f);
    xb_End();
}

/* ps2SeqsRenderQuad_A 0xF49CE.
 *
 * A sprite drawn from its four vertices and texture coordinates.
 * Retail also keeps an empty loop over the vertices, left from the PS2
 * code. */

void ps2SeqsRenderQuad_A(Sprite* spr, u32 col) {
    spr->v[0].z = (spr->v[0].z + 1.0f) / 2.0f;
    xb_Begin(6);
    xb_SetVertexDataColor(3, col);
    xb_SetVertexData2f(9, spr->t[0].s, spr->t[0].t);
    D3DDevice__SetVertexData4f(-1, spr->v[0].x, spr->v[0].y, spr->v[0].z, 1.0f);
    xb_SetVertexData2f(9, spr->t[1].s, spr->t[1].t);
    D3DDevice__SetVertexData4f(-1, spr->v[1].x, spr->v[1].y, spr->v[0].z, 1.0f);
    xb_SetVertexData2f(9, spr->t[2].s, spr->t[2].t);
    D3DDevice__SetVertexData4f(-1, spr->v[2].x, spr->v[2].y, spr->v[0].z, 1.0f);
    xb_SetVertexData2f(9, spr->t[3].s, spr->t[3].t);
    D3DDevice__SetVertexData4f(-1, spr->v[3].x, spr->v[3].y, spr->v[0].z, 1.0f);
    xb_End();
}

/* ps2SeqsRenderQuad_B 0xF4AFA.
 *
 * An untextured quad from its four vertices. */

void ps2SeqsRenderQuad_B(Quad* q, u32 col) {
    q->v[0].z = (q->v[0].z + 1.0f) / 2.0f;
    xb_Begin(6);
    xb_SetVertexDataColor(3, col);
    D3DDevice__SetVertexData4f(-1, q->v[0].x, q->v[0].y, q->v[0].z, 1.0f);
    D3DDevice__SetVertexData4f(-1, q->v[1].x, q->v[1].y, q->v[0].z, 1.0f);
    D3DDevice__SetVertexData4f(-1, q->v[2].x, q->v[2].y, q->v[0].z, 1.0f);
    D3DDevice__SetVertexData4f(-1, q->v[3].x, q->v[3].y, q->v[0].z, 1.0f);
    xb_End();
}

/* xb_DrawColoredQuad 0xF4BCE.
 *
 * A flat rectangle: x0, y0, z, x1, y1, then the colour at +0x18. */

void xb_DrawColoredQuad(f32* q) {
    q[2] = (q[2] + 1.0f) / 2.0f;
    xb_Begin(6);
    xb_SetVertexDataColor(3, *(s32*)&q[6]);
    D3DDevice__SetVertexData4f(-1, q[0], q[1], q[2], 1.0f);
    D3DDevice__SetVertexData4f(-1, q[3], q[1], q[2], 1.0f);
    D3DDevice__SetVertexData4f(-1, q[0], q[4], q[2], 1.0f);
    D3DDevice__SetVertexData4f(-1, q[3], q[4], q[2], 1.0f);
    xb_End();
}

s32 getCP3toFullScreenDrawFlag(void) {
    return D_007970F8;
}

void CP3toPS2DrawOn(void) {
    D_007970F8 = 1;
}

void CP3toPS2DrawOff(void) {
    D_007970F8 = 0;
}

s32 xb_Get7C5959(void) {
    return D_007C5959;
}

s32 ps2SeqsRenderQuadInit_A(void) {
    if (D_0043FE5C == 0) {
        return 0;
    }

    xb_SaveQuadStates(1);
    D3DDevice__SetVertexShader(0x144);
    return 1;
}

s32 ps2SeqsRenderQuadInit_B(void) {
    if (D_0043FE5C == 0) {
        return 0;
    }

    xb_SaveQuadStates(0);
    D3DDevice__SetVertexShader(0x44);
    return 1;
}
