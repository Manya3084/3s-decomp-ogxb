/* xlive_font.c: Xbox-only code from Capcom's xlive_font.cpp. Its _assert path names it, and the
 * code that pushes the path places it at 0xFB063 to 0xFB883.
 * Capcom's source is lost. Its C++ methods are written as C,
 * XB_FASTCALL (__fastcall) with this first. Each body was checked
 * against retail by analysis-ps2map/xbgen.py. The xb_ names are
 * made up. */

#include "types.h"
#include <string.h>

typedef struct {
    s32 d[0x12];
} XB_IMAGEINFO;
typedef struct {
    s32 d[4];
    s32 bits;
    s32 e[0xD];
} XB_PALINFO;
typedef struct {
    u8 pad0[0x10];
    u8* ptr;
} XB_PLCTX;
typedef struct {
    f32 m[4][4];
} XB_MATRIX;
typedef struct {
    f32 v[3];
} XB_VECTOR3;
typedef struct {
    s32 x;
    s32 y;
    s32 w;
    s32 h;
    f32 min_z;
    f32 max_z;
} XB_VIEWPORT;

/* A string to draw: pen, scale, cell, attribute and the text. */
typedef struct {
    s16 x;
    s16 y;
    f32 scale;
    u8 w;
    u8 h;
    u16 attr;
    const u8* text;
} XB_XFENTRY;

extern u8* D_00798B78;
void sub_0004384A(void* a, void* b);
void xb_xlive_font_ResetState(void);
void xb_xlive_font_Clear(void);
void xb_xlive_font_Reset(void);
void _assert(const char* expr, const char* file, u32 line);
extern char D_002B4C74[];
extern char D_002B4C78[];
extern char D_002B4CE8[];
extern u8 D_003F8218[];
extern XB_PLCTX D_003F81D0;
extern u32 D_003F8260[8][3];
s32 flSetRenderState(s32 state, u32 value);
s32 flCreateTextureHandle(void* bits, u32 attribute);
s32 flCreatePaletteHandle(void* bits, s32 flag);
s32 flLockPalette(void* rect, u32 th, XB_PALINFO* out, s32 flag);
void flUnlockPalette(u32 th);
s32 flLockTexture(s16* r, u32 h, XB_IMAGEINFO* out, s32 mode);
s32 flUnlockTexture(u32 h);
s32 xb_DrawQuadSaved2(void* q);
void xb_SetLightFloat(s32 type, f32 a, f32 b, f32 c, f32 d);
void xb_SetTransformRect(XB_MATRIX* out, XB_VECTOR3* eye, XB_VECTOR3* at, XB_VECTOR3* up);
u32 xb_AsciiToSjis(u8 c);
s32 XB_FASTCALL xb_SjisToIndex(u32 code);
void xb_xlive_font_SetPos(s16 x, s16 y);
void xb_xlive_font_SetScale(f32 scale);
void xb_xlive_font_SetColor(u8 a, u8 b);
void xb_xlive_font_SetAttr(u16 attr);

#define XB_IS_SJIS_LEAD(c) (((c) >= 0x80 && (c) <= 0x9F) || ((c) >= 0xE0 && (c) <= 0xFF))

/* The Live text layer (D_00798B78) is the debug print layer of
 * xb_012146.c with two cache textures: its work area holds the glyph
 * source (+0xC), the pen (+0x10 x, +0x12 y, +0x14 scale), the drawing
 * position (+0x18, +0x1A), the cell (+0x1C width, +0x1D height),
 * attribute (+0x1E), the palette buffer (+0x20), two string lists
 * (counts at +0x24, 0x10-byte XB_XFENTRY lists at +0x2C), the text
 * buffer (+0x34 used, +0x38), half-width ASCII (+0x3C), the glyph queue
 * (+0x44 drawn, +0x48 queued, indices at +0x4C), each glyph's cache slot
 * (+0x230), the next free slot (+0x3F30), the two cache textures
 * (+0x3F34) and sixteen palettes (+0x3F3C). 0x79 glyphs of 22x22 fit a
 * texture, 11 to a row. */

/* xb_xlive_font_ResetState 0xFAEAD. */

void xb_xlive_font_ResetState(void) {
    u8* p = D_00798B78;

    memset(p + 0x24, 0, 8);
    *(s16*)(p + 0x10) = 0;
    *(s16*)(p + 0x12) = 0;
    *(f32*)(p + 0x14) = 10.0f;
    p[0x1C] = p[4];
    p[0x1D] = p[8];
    *(s16*)(p + 0x1E) = 0;
    *(s32*)(p + 0x34) = 0;
    *(s32*)(p + 0x3C) = 1;
    *(s32*)(p + 0x48) = *(s32*)(p + 0x44);
}

/* xb_xlive_font_LoadPage 0xFAF2B: palette page (mod 16) from four
 * colours; colour 0 is transparent unless c0 has alpha. */

void xb_xlive_font_LoadPage(s32 page, u32 c0, u32 c1, u32 c2, u32 c3) {
    u8 rgb[12];
    XB_PALINFO ctx;
    u8* dst;
    u32* d;
    u32* s;
    u8 a;
    u8 r;
    u8 g;
    u8 b;
    s32 i;
    s32 ofs;
    u32 th;

    page %= 16;
    ofs = page * 0x40;
    dst = *(u8**)(D_00798B78 + 0x20) + ofs;
    a = (c0 & 0xFF000000) ? 0xFF : 0;

    for (i = 0; i < 3; i++) {
        rgb[0 * 3 + i] = c0;
        c0 >>= 8;
    }

    for (i = 0; i < 3; i++) {
        rgb[1 * 3 + i] = c1;
        c1 >>= 8;
    }

    for (i = 0; i < 3; i++) {
        rgb[2 * 3 + i] = c2;
        c2 >>= 8;
    }

    for (i = 0; i < 3; i++) {
        rgb[3 * 3 + i] = c3;
        c3 >>= 8;
    }

    for (i = 0; i < 4; i++) {
        r = rgb[i * 3];
        g = rgb[i * 3 + 1];
        b = rgb[i * 3 + 2];
        *dst++ = r;
        *dst++ = g;
        *dst++ = b;

        if ((i == 0) | a) {
            *dst = a;
        } else if (r == 0 && g == 0 && b == 0) {
            *dst = 0;
        } else {
            *dst = 0xFF;
        }

        dst++;
    }

    th = ((u32*)(D_00798B78 + 0x3F3C))[page];

    if (th != 0) {
        flLockPalette(0, th, &ctx, 2);
        s = (u32*)(*(u8**)(D_00798B78 + 0x20) + ofs);
        d = (u32*)ctx.bits;

        for (i = 0; i < 4; i++) {
            *d++ = *s++;
        }

        flUnlockPalette(th);
    }
}

void xb_xlive_font_SetColor(u8 a, u8 b) {
    u8* c;
    u8* d;

    if (D_00798B78 == 0) {
        _assert(D_002B4C74, D_002B4C78, 0x136);
    }

    c = D_00798B78 + 0x1C;
    d = D_00798B78 + 0x1D;
    *c = a;
    *d = b;
    sub_0004384A(c, d);
}

void xb_xlive_font_SetPos(s16 x, s16 y) {
    u8* p = D_00798B78;

    *(s16*)(p + 0x10) = x;
    *(s16*)(p + 0x12) = y;
    sub_0004384A(p + 0x10, p + 0x12);
}

void xb_xlive_font_SetScale(f32 scale) {
    *(f32*)(D_00798B78 + 0x14) = scale;
}

void xb_xlive_font_SetAttr(u16 attr) {
    *(u16*)(D_00798B78 + 0x1E) = attr;
}

void xb_xlive_font_Reset(void) {
    xb_xlive_font_ResetState();
    xb_xlive_font_Clear();
}

/* xb_xlive_font_SetProjection 0xFB19E: the Live screens' view, a 640x448
 * viewport with a camera 10 units back on z. */

void xb_xlive_font_SetProjection(void) {
    XB_VECTOR3 up;
    XB_VECTOR3 at;
    XB_VECTOR3 eye;
    XB_VIEWPORT vp;
    XB_ALIGN16 XB_MATRIX m;

    vp.x = 0;
    vp.y = 0;
    eye.v[2] = 10.0f;
    eye.v[1] = 0.0f;
    eye.v[0] = 0.0f;
    up.v[0] = 0.0f;
    at.v[2] = 0.0f;
    at.v[1] = 0.0f;
    at.v[0] = 0.0f;
    up.v[1] = 1.0f;
    up.v[2] = 0.0f;
    vp.w = 0x280;
    vp.h = 0x1C0;
    vp.min_z = 0.0f;
    vp.max_z = 1.0f;
    xb_SetLightFloat(0x20, 1500.0f, 1.0f, 0.7853982f, 1.3333334f);
    flSetRenderState(0x18, (u32)&vp);
    xb_SetTransformRect(&m, &eye, &at, &up);
    flSetRenderState(0x16, (u32)&m);
}

/* xb_xlive_font_CreateTextures 0xFB27E: the two cache textures and the
 * sixteen palettes, then the default palette. Returns the first texture. */

s32 xb_xlive_font_CreateTextures(void) {
    s32 i;

    for (i = 0; i < 2; i++) {
        ((s32*)(D_00798B78 + 0x3F34))[i] = flCreateTextureHandle(D_003F8218, 3);
    }

    for (i = 0; i < 16; i++) {
        D_003F81D0.ptr = *(u8**)(D_00798B78 + 0x20) + i * 0x40;
        ((s32*)(D_00798B78 + 0x3F3C))[i] = flCreatePaletteHandle(&D_003F81D0, 3);
    }

    xb_xlive_font_LoadPage(0, 0, 0xFF333333, 0xFF999999, 0xFFFFFFFF);
    xb_xlive_font_Clear();
    return *(s32*)(D_00798B78 + 0x3F34);
}

/* xb_xlive_font_DrawGlyphUV 0xFB304: one cached glyph at the drawing
 * position. */

static void xb_xlive_font_DrawGlyphUV(s32 idx, XB_XFENTRY* e) {
    u8* p = D_00798B78;
    s32 slot = ((u16*)(p + 0x230))[idx];
    s32 cell = slot % 0x79;
    u32 th = (((s32*)(p + 0x3F3C))[(s16)e->attr] << 16) | ((s32*)(p + 0x3F34))[slot / 0x79];
    struct {
        s16 x;
        s16 y;
        s16 w;
        s16 h;
        s32 color;
        s16 u0;
        s16 v0;
        s16 u1;
        s16 v1;
    } q;

    sub_0004384A((void*)1, &th);
    flSetRenderState(4, th);
    flSetRenderState(0x63, (e->w == 0x16 && e->h == 0x16) ? 0x10000 : 0);
    p = D_00798B78;
    q.x = *(s16*)(p + 0x18);
    q.y = *(s16*)(p + 0x1A);
    q.w = e->w;
    q.h = e->h;
    q.color = -1;
    q.v0 = cell / 11 * 0x16;
    q.u0 = cell % 11 * 0x16;
    q.u1 = q.u0 + 0x16;
    q.v1 = q.v0 + 0x16;
    xb_DrawQuadSaved2(&q);
}

s32 XB_FASTCALL xb_xlive_font_SjisIndex(u32 code) {
    s32 r = xb_SjisToIndex(code);
    s32 idx = (r >> 8) * 94 + (r & 0xFF) - 0xC3F;

    if (idx >= 0x1E80) {
        return -1;
    }

    return idx;
}

/* xb_xlive_font_QueueGlyph 0xFB3F6: gives an uncached glyph the next slot
 * and queues it. */

static void xb_xlive_font_QueueGlyph(u16 idx) {
    u8* p = D_00798B78;
    u16* slot = &((u16*)(p + 0x230))[idx];

    if (*slot == 0xFF) {
        *slot = *(u16*)(p + 0x3F30);
        (*(s32*)(p + 0x3F30))++;
        ((u16*)(p + 0x4C))[(*(s32*)(p + 0x48))++] = idx;
    }
}

/* xb_xlive_font_DrawQueue 0xFB45F: expands one glyph (20x20, two bits a
 * pixel, 5 bytes a row) into a 22x22 cell of 8-bit palette indices with
 * a pitch of 256. */

void XB_FASTCALL xb_xlive_font_DrawQueue(u8* dst, u8* src) {
    s32 y;
    s32 x;
    u8 c;

    for (y = 0x14; y != 0; y--) {
        for (x = 5; x != 0; x--) {
            c = *src++;
            *dst++ = c >> 6;
            *dst++ = c >> 4 & 3;
            *dst++ = c >> 2 & 3;
            *dst++ = c & 3;
        }

        *(u16*)dst = 0;
        dst += 2;
        dst += 0xEA;
    }

    for (y = 2; y != 0; y--) {
        memset(dst, 0, 0x16);
        dst += 0x16;
        dst += 0xEA;
    }
}

/* xb_xlive_font_DrawQueued 0xFB4C8: draws the queued glyphs into the
 * cache textures, locking each once. */

void xb_xlive_font_DrawQueued(void) {
    u8* p = D_00798B78;
    XB_IMAGEINFO info;
    u32 th;
    s32 pg;
    s32 n;

    if (*(s32*)(p + 0x44) == *(s32*)(p + 0x48)) {
        return;
    }

    for (pg = *(s32*)(p + 0x44) / 0x79; pg <= *(s32*)(p + 0x48) / 0x79; pg++) {
        th = ((s32*)(p + 0x3F34))[pg];
        flLockTexture(0, th, &info, 0);
        p = D_00798B78;

        while ((n = *(s32*)(p + 0x44)) / 0x79 == pg && n < 0xF2 && n != *(s32*)(p + 0x48)) {
            xb_xlive_font_DrawQueue((u8*)info.d[4] + (((n % 0x79 / 11) << 8) + n % 11) * 0x16,
                                    *(u8**)(p + 0xC) + ((u16*)(p + 0x4C))[n] * 0x64);
            (*(s32*)(p + 0x44))++;
        }

        flUnlockTexture(th);
        p = D_00798B78;
    }
}

/* xb_xlive_font_Init 0xFB5B8: lays out the 0xD400-byte work area. */

void xb_xlive_font_Init(void* buf) {
    u8* w = buf;
    u8* b = buf;
    s32 i;

    memset(w, 0, 0xD400);
    b += 0x3F80;
    *(u8**)(w + 0x20) = b;
    D_00798B78 = w;
    b += 0x400;

    for (i = 0; i < 2; i++) {
        ((u8**)(w + 0x2C))[i] = b;
        b += 0x800;
    }

    *(u8**)(w + 0x38) = b;
    *(s32*)(w + 4) = 0x16;
    *(s32*)(w + 8) = 0x16;
    *(s32*)D_00798B78 = xb_xlive_font_CreateTextures();
}

/* xb_xlive_font_LoadPages 0xFB610: the eight text colours of
 * D_003F8260, white for any page the table does not cover. */

void xb_xlive_font_LoadPages(void) {
    s32 i;

    xb_xlive_font_Reset();

    for (i = 0; i < sizeof(D_003F8260) / sizeof(D_003F8260[0]); i++) {
        xb_xlive_font_LoadPage(i, 0, D_003F8260[i][0], D_003F8260[i][1], D_003F8260[i][2]);
    }

    for (; i < 8; i++) {
        xb_xlive_font_LoadPage(i, 0, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF);
    }
}

/* xb_xlive_font_PutChars 0xFB656: queues a string's uncached glyphs.
 * Returns 1 when the queue (0xF2) fills first. */

s32 xb_xlive_font_PutChars(const char* str) {
    const u8* s = (const u8*)str;
    u32 c;
    s32 idx;

    while ((c = *s++) != 0) {
        if (c == '\n') {
            continue;
        }

        if (XB_IS_SJIS_LEAD(c)) {
            if (*s == 0) {
                break;
            }

            c = (c << 8) | *s++;
        } else {
            c = xb_AsciiToSjis(c);
        }

        if (c == 0x8140) {
            continue;
        }

        idx = xb_xlive_font_SjisIndex(c);

        if (idx < 0 || idx >= 0x1E80) {
            continue;
        }

        xb_xlive_font_QueueGlyph(idx);

        if (*(s32*)(D_00798B78 + 0x48) >= 0xF2) {
            return 1;
        }
    }

    return 0;
}

/* xb_xlive_font_DrawGlyphAt 0xFB6DB: draws a string from the cache at
 * e's pen; a newline goes back to its x and down a cell. */

static void xb_xlive_font_DrawGlyphAt(const u8* s, XB_XFENTRY* e) {
    u8* p = D_00798B78;
    u32 c;
    s32 idx;
    s32 half;

    *(s16*)(p + 0x18) = e->x;
    *(s16*)(p + 0x1A) = e->y;

    while ((c = *s++) != 0) {
        if (c == '\n') {
            *(s16*)(p + 0x18) = e->x;
            *(s16*)(p + 0x1A) += e->h;
            continue;
        }

        if (XB_IS_SJIS_LEAD(c)) {
            if (*s == 0) {
                break;
            }

            c = (c << 8) | *s++;
            half = 0;
        } else {
            c = xb_AsciiToSjis(c);
            half = 1;
        }

        if (c != 0x8140 && (idx = xb_xlive_font_SjisIndex(c)) >= 0) {
            xb_xlive_font_DrawGlyphUV(idx, e);
            p = D_00798B78;
        }

        if (!half) {
            *(s16*)(p + 0x18) += e->w;
        } else if (*(s32*)(p + 0x3C) != 0) {
            *(s16*)(p + 0x18) += e->w >> 1;
        } else {
            *(s16*)(p + 0x18) += e->w * 2 / 3;
        }
    }
}

/* xb_xlive_font_NextLine 0xFB7B3: queues every uncached glyph of both
 * string lists. Returns 1 when the queue fills first. */

s32 xb_xlive_font_NextLine(void) {
    s32* count = (s32*)(D_00798B78 + 0x24);
    s32 k;
    s32 i;
    XB_XFENTRY* e;
    const u8* s;
    u32 c;
    s32 idx;

    for (k = 0; k < 2; k++, count++) {
        for (i = 0, e = (XB_XFENTRY*)count[2]; i < *count; i++, e++) {
            s = e->text;

            while ((c = *s++) != 0) {
                if (c == '\n') {
                    continue;
                }

                if (XB_IS_SJIS_LEAD(c)) {
                    if (*s == 0) {
                        break;
                    }

                    c = (c << 8) | *s++;
                } else {
                    c = xb_AsciiToSjis(c);
                }

                if (c == 0x8140) {
                    continue;
                }

                idx = xb_xlive_font_SjisIndex(c);

                if (idx < 0 || idx >= 0x1E80) {
                    continue;
                }

                xb_xlive_font_QueueGlyph(idx);

                if (*(s32*)(D_00798B78 + 0x48) >= 0xF2) {
                    return 1;
                }
            }
        }
    }

    return 0;
}

/* xb_xlive_font_Print 0xFB883: sets the pen, scale, cell and attribute
 * from a text record (an XB_XFENTRY head with the text inline at +0xC)
 * and draws it at once. */

void xb_xlive_font_Print(u8* rec) {
    XB_XFENTRY e;
    u8* p;

    if (rec == 0) {
        _assert(D_002B4CE8, D_002B4C78, 0x195);
    }

    e.attr = *(u16*)(rec + 0xA);
    e.text = rec + 0xC;
    xb_xlive_font_SetPos(*(u16*)rec, *(u16*)(rec + 2));
    xb_xlive_font_SetScale(*(f32*)(rec + 4));
    xb_xlive_font_SetColor(rec[8], rec[9]);
    xb_xlive_font_SetAttr(*(u16*)(rec + 0xA));
    p = D_00798B78;
    e.x = *(s16*)(p + 0x10);
    e.y = *(s16*)(p + 0x12);
    e.w = p[0x1C];
    e.h = p[0x1D];
    e.scale = *(f32*)(p + 0x14);
    xb_xlive_font_DrawGlyphAt(rec + 0xC, &e);
}
