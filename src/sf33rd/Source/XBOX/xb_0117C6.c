/* xb_0117C6.c: Xbox-only code from the run of Xbox-only functions at 0x117C6, which no
 * PS2 file covers.
 * Capcom's source is lost. Its C++ methods are written as C,
 * XB_FASTCALL (__fastcall) with this first. Each body was checked
 * against retail by analysis-ps2map/xbgen.py. The xb_ names are
 * made up. */

#include "types.h"
#include <string.h>

typedef struct {
    s16 x;
    s16 y;
    s32 color;
} XB_PIXEL;
/* An image description: flags (4 = palettized, 0x40 = 8-bit indices),
 * size, pitch, bits, bytes per pixel, then each channel's present flag,
 * shift and maximum, red, green, blue and alpha. */
typedef struct {
    u32 flags;
    s32 w;
    s32 h;
    s32 pitch;
    u8* bits;
    s32 bpp;
    s32 r_on;
    s32 r_shift;
    s32 r_max;
    s32 g_on;
    s32 g_shift;
    s32 g_max;
    s32 b_on;
    s32 b_shift;
    s32 b_max;
    s32 a_on;
    s32 a_shift;
    s32 a_max;
} XB_IMGDESC;
s32 xb_StoreImagePixel(XB_IMGDESC* img, XB_PIXEL* px);
u32 xb_GetImagePixel(s32 x, s32 y, XB_IMGDESC* img);
u8* xb_ImagePixelAddress(s32 x, s32 y, u8* img);
void xb_memset_bytes(void* p, s32 v, s32 n);
extern s32 D_0043E8CC;
extern s32 D_0043E89C;
void XB_STDCALL D3D_SetPushBufferSize(s32 size, s32 kick);
typedef struct {
    s32 w;
    s32 h;
    s32 progressive;
    s32 widescreen;
} XB_VIDEOMODE;
/* D3DPRESENT_PARAMETERS */
typedef struct {
    s32 width;
    s32 height;
    s32 format;
    s32 count;
    s32 multisample;
    s32 swap_effect;
    void* window;
    s32 windowed;
    s32 auto_depth;
    s32 depth_format;
    u32 flags;
    s32 refresh;
    s32 interval;
    void* surfaces[4];
} XB_PRESENTPARAMS;
s32 XB_STDCALL Direct3D_CreateDevice(s32 adapter, s32 type, void* window, s32 behavior, XB_PRESENTPARAMS* pp, void** dev);
void* XB_STDCALL Direct3DCreate8(s32 version);
s32 XB_STDCALL xb_SetPushBufferSize(s32 size, s32 kick);
s32 XB_STDCALL XGetVideoStandard(void);
s32 XB_STDCALL XGetAVPack(void);
u32 XB_STDCALL XGetVideoFlags(void);
void XB_STDCALL D3DDevice__GetDisplayMode(void* mode);
s32 XB_STDCALL xb_SetRenderState(s32 state, s32 value);
void XB_STDCALL xb_SetVerticalBlankCallback(s32 a0);
void XB_STDCALL xb_SetSwapCallback(s32 a0);
s32 XB_STDCALL xb_ResetDevice(XB_PRESENTPARAMS* pp);
s32 xb_IsSupportedVideoMode(XB_VIDEOMODE m, u32 flags);
void flPADInitialize(void);
void D3DDevice_SetRenderState(s32 state, s32 value);
void sub_00011BF0(void);
void sub_00011BFB(void);
extern void* D_0043ED08;
extern u32 D_0043FF44;
extern XB_PRESENTPARAMS D_0043FF48;
extern f32 D_0043FF8C;
extern s32 D_0043ED14;
extern u32 D_0043EE24;
extern s32 D_0044D390;
extern void* D_0043FE5C;
extern s32 D_0043EE28;
extern XB_VIDEOMODE D_002EC764[2];
s32 XB_STDCALL D3DDevice_Reset(XB_PRESENTPARAMS* pp);
void XB_STDCALL D3DDevice_SetVerticalBlankCallback(s32 a0);
void XB_STDCALL D3DDevice_SetSwapCallback(s32 a0);
void D3DDevice_PersistDisplay(void);

/* xb_SetViewportRect4 0x117C6.
 *
 * Builds the viewport matrix for a w x h rectangle at (x, y) with the
 * depth range zmin..zmax: scale by w/2 and -h/2, offset to the centre. */

void xb_SetViewportRect4(f32* m, s32 x, s32 y, s32 w, s32 h, f32 zmin, f32 zmax) {
    xb_memset_bytes(m, 0, 0x40);
    m[0] = (f32)w / 2.0f;
    m[5] = (f32)-h / 2.0f;
    m[10] = zmax - zmin;
    m[12] = (f32)(w / 2) + (f32)x;
    m[14] = zmin;
    m[13] = (f32)(h / 2) + (f32)y;
    m[15] = 1.0f;
}

/* xb_StoreImagePixel 0x118C2.
 *
 * Writes px's colour (D3DCOLOR, bytes B, G, R, A) into the image: as an
 * index into a palettized image, or scaled into each channel's bits. */

s32 xb_StoreImagePixel(XB_IMGDESC* img, XB_PIXEL* px) {
    s32 x = px->x;
    u8* p = xb_ImagePixelAddress(x, px->y, (u8*)img);
    u8* c = (u8*)&px->color;
    u32 v;

    if (p == 0) {
        return 0;
    }

    if (img->flags & 4) {
        switch (img->bpp) {
        case 0:
            if (img->flags & 0x40) {
                *p = (u8)px->color;
            } else {
                u32 d = *p;

                v = px->color & 0xF;

                if (((img->flags >> 4) ^ x) & 1) {
                    d &= 0xF0;
                } else {
                    v <<= 4;
                    d &= 0xF;
                }

                *p = d | v;
            }

            break;
        case 1:
            *p = (u8)px->color;
            break;
        case 2:
            *(u16*)p = (u16)px->color;
            break;
        case 4:
            *(s32*)p = px->color;
            break;
        }
    } else {
        v = (c[2] * img->r_max / 0xFF) << img->r_shift |
            (c[1] * img->g_max / 0xFF) << img->g_shift |
            (c[3] * img->a_max / 0xFF) << img->a_shift |
            ((s32)(px->color & 0xFF) * img->b_max / 0xFF) << img->b_shift;

        switch (img->bpp) {
        case 2:
            *(u16*)p = v;
            break;
        case 3:
            p[0] = v;
            p[1] = v >> 8;
            p[2] = v >> 16;
            break;
        case 4:
            *(u32*)p = v;
            break;
        }
    }

    return 1;
}

/* xb_GetImagePixel 0x11A11.
 *
 * Reads a pixel: a palettized image gives the index, any other the
 * colour as A8R8G8B8 (alpha 0xFF and other channels 0 where absent).
 * An unsupported size returns an unset value, as in retail. */

u32 xb_GetImagePixel(s32 x, s32 y, XB_IMGDESC* img) {
    u8* p = xb_ImagePixelAddress(x, y, (u8*)img);
    u32 v;
    u32 a;
    u32 r;
    u32 g;
    u32 b;

    if (p == 0) {
        return 0;
    }

    if (img->flags & 4) {
        switch (img->bpp) {
        case 0:
            if (img->flags & 0x40) {
                return *p;
            }

            if (((img->flags >> 4) ^ x) & 1) {
                return *p & 0xF;
            }

            return (*p >> 4) & 0xF;
        case 1:
            return *p;
        case 2:
            return *(u16*)p;
        case 4:
            return *(u32*)p;
        }

        return g;
    }

    switch (img->bpp) {
    case 2:
        v = *(u16*)p;
        break;
    case 3:
        v = ((p[2] << 8 | p[1]) << 8) | p[0];
        break;
    case 4:
        v = *(u32*)p;
        break;
    default:
        v = g;
        break;
    }

    a = img->a_on ? ((v >> img->a_shift) & img->a_max) * 0xFF / img->a_max : 0xFF;
    r = img->r_on ? ((v >> img->r_shift) & img->r_max) * 0xFF / img->r_max : 0;
    g = img->g_on ? ((v >> img->g_shift) & img->g_max) * 0xFF / img->g_max : 0;
    b = img->b_on ? ((v >> img->b_shift) & img->b_max) * 0xFF / img->b_max : 0;
    return ((a << 8 | r) << 8 | g) << 8 | b;
}

u8* xb_ImagePixelAddress(s32 x, s32 y, u8* img) {
    s32 bpp;

    if (x < 0 || y < 0 || x >= *(s32*)(img + 4) || y >= *(s32*)(img + 8)) {
        return 0;
    }

    bpp = *(s32*)(img + 0x14);

    if (bpp == 0) {
        if (img[0] & 0x40) {
            return *(s32*)(img + 0xC) * y + *(u8**)(img + 0x10) + x;
        }

        return *(s32*)(img + 0xC) * y + x / 2 + *(u8**)(img + 0x10);
    }

    return *(s32*)(img + 0xC) * y + bpp * x + *(u8**)(img + 0x10);
}

void xb_SetImagePixel(void* img, s16 x, s16 y, s32 color) {
    XB_PIXEL px;

    px.x = x;
    px.y = y;
    px.color = color;
    xb_StoreImagePixel((XB_IMGDESC*)img, &px);
}

s32 xb_ConvertImagePixels(u8* img, XB_IMGDESC* src) {
    s32 x;
    s32 y;

    for (y = 0; y < *(s32*)(img + 8); y++) {
        for (x = 0; x < *(s32*)(img + 4); x++) {
            xb_SetImagePixel(img, x, y, xb_GetImagePixel(x, y, src));
        }
    }

    return 1;
}

s32 xb_IsSupportedVideoMode(XB_VIDEOMODE m, u32 flags) {
    s32 ok = 1;

    if (m.h == 480) {
        if (m.widescreen && !(flags & 1)) {
            ok = 0;
        } else if (m.progressive && !(flags & 8)) {
            ok = 0;
        }
    } else if (m.h == 720) {
        if (!(flags & 2)) {
            ok = 0;
        }
    } else if (m.h == 1080) {
        if (!(flags & 4)) {
            ok = 0;
        }
    }

    return ok;
}

s32 xb_TickFrameCounter(void) {
    if (D_0043E8CC != 0) {
        return --D_0043E8CC == 0;
    }

    if (D_0043E89C) {
        D_0043E8CC = D_0043E89C;
        return 0;
    }

    return 1;
}

s32 XB_STDCALL xb_SetPushBufferSize(s32 size, s32 kick) {
    D3D_SetPushBufferSize(size, kick);
    return 0;
}

s32 XB_STDCALL xb_ResetDevice(XB_PRESENTPARAMS* pp) {
    return D3DDevice_Reset(pp);
}

void XB_STDCALL xb_SetVerticalBlankCallback(s32 a0) {
    D3DDevice_SetVerticalBlankCallback(a0);
}

void XB_STDCALL xb_SetSwapCallback(s32 a0) {
    D3DDevice_SetSwapCallback(a0);
}

void xb_PersistDisplayThunk(void) {
    D3DDevice_PersistDisplay();
}

void xb_PersistDisplay(void) {
    xb_PersistDisplayThunk();
}

/* xb_CreateDevice 0x11C39.
 *
 * IDirect3D8::CreateDevice, a jump to Direct3D_CreateDevice. */

s32 XB_STDCALL xb_CreateDevice(s32 adapter, s32 type, void* window, s32 behavior, XB_PRESENTPARAMS* pp, void** dev) {
    return Direct3D_CreateDevice(adapter, type, window, behavior, pp, dev);
}

/* xb_SetRenderState 0x11E44.
 *
 * IDirect3DDevice8::SetRenderState. */

s32 XB_STDCALL xb_SetRenderState(s32 state, s32 value) {
    D3DDevice_SetRenderState(state, value);
    return 0;
}

/* xb_InitGraphics 0x11E67.
 *
 * Creates Direct3D and the device: a 0x30000-byte push buffer, the
 * best supported 640x480 mode from D_002EC764 (progressive first),
 * 60 Hz for NTSC and for PAL with PAL-60, a 16:9 or 4:3 aspect ratio
 * (D_0043FF8C), a double-buffered X8R8G8B8 back buffer with a D24S8
 * depth buffer, and the vertical blank and swap callbacks. Returns 0, or
 * E_FAIL. */

s32 xb_InitGraphics(void) {
    s32 mode[5];
    s32 i;
    u32 vflags;

    if ((D_0043ED08 = Direct3DCreate8(0)) == 0) {
        return 0x80004005;
    }

    xb_SetPushBufferSize(0x30000, 0x2000);
    memset(&D_0043FF48, 0, sizeof(XB_PRESENTPARAMS));
    D_0043FF44 = XGetVideoStandard();
    D_0043ED14 = XGetAVPack();
    D_0043EE24 = vflags = XGetVideoFlags();

    if (D_0043FF44 > 0) {
        if (D_0043FF44 > 2) {
            if (D_0043FF44 == 3) {
                D_0043FF48.refresh = 60;

                if (!(vflags & 0x40)) {
                    D_0043FF48.flags |= 0x200;
                }
            }
        } else {
            D_0043FF48.refresh = 60;
        }
    }

    for (i = 1; i >= 0; i--) {
        if (xb_IsSupportedVideoMode(D_002EC764[i], vflags)) {
            D_0044D390 = i;
            break;
        }
    }

    i = D_0044D390;
    D_0043FF48.height = D_002EC764[i].h;
    D_0043FF48.flags |= (D_002EC764[i].progressive ? 0x40 : 0x20) | (D_002EC764[i].widescreen ? 0x10 : 0);
    D_0043FF48.width = D_002EC764[i].w;

    if (vflags & 1) {
        D_0043FF48.flags |= 0x10;
        D_0043FF8C = 16.0f / 9.0f;
    } else {
        D_0043FF8C = 4.0f / 3.0f;
    }

    if (D_0043FF48.width <= 640) {
        D_0043FF48.flags |= 0x100;
    }

    D_0043FF48.format = 7;
    D_0043FF48.count = 2;
    D_0043FF48.auto_depth = 1;
    D_0043FF48.depth_format = 0x2A;
    D_0043FF48.swap_effect = 1;
    D_0043FF48.interval = 1;

    if (xb_CreateDevice(0, 1, 0, 0x40, &D_0043FF48, &D_0043FE5C) < 0) {
        return 0x80004005;
    }

    D3DDevice__GetDisplayMode(mode);
    xb_SetRenderState(0x41, 1);
    D_0043EE28 = 0;
    xb_SetVerticalBlankCallback((s32)sub_00011BF0);
    xb_SetSwapCallback((s32)sub_00011BFB);
    flPADInitialize();
    return 0;
}

/* xb_ResetDeviceOneBackBuffer 0x1202F.
 *
 * Resets the device with a single back buffer, hanging if that fails. */

void xb_ResetDeviceOneBackBuffer(void) {
    D_0043FF48.count = 1;

    if (xb_ResetDevice(&D_0043FF48) != 0) {
        for (;;) {
        }
    }
}
