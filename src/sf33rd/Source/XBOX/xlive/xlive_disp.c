/* xlive_disp.c: Xbox-only code from Capcom's xlive_disp.cpp. Its _assert path names it, and the
 * code that pushes the path places it at 0xF832F to 0xFAA91.
 * Capcom's source is lost. Its C++ methods are written as C,
 * XB_FASTCALL (__fastcall) with this first. Each body was checked
 * against retail by analysis-ps2map/xbgen.py. The xb_ names are
 * made up. */

#include "types.h"
#include <string.h>

void _assert(const char* expr, const char* file, u32 line);
extern char D_002B4B20[];
extern char D_002B4B48[];
extern u8 D_00798128[];
extern u8* D_003F3A10;
s32 xb_GetOnlineFlag(void);
void* operator_new(u32 size);
u8* xb_xlive_disp_FindObj(s32 id);
extern char D_002B4BF0[];
extern s32 D_0079812C[];
void xb_vector_XONLINE_USER_FillN(void* a, void* b, void* c, void* self);
void xb_vector20_FillN(void* a, void* b, void* c, void* self);
void xb_vector_XONLINE_USER_Destroy(void);
void xb_vector20_Clear(void);
extern char D_002B4C44[];
void xb_xlive_friend_Release(s32 id);
s32 xb_xlive_disp_DrawRectF(f32 a, f32 b, f32 c, f32 d, f32 e);
extern s32 D_00798118;
void xb_xlive_disp_DrawText(s32 font, f32 x, f32 y, f32 s, s32 w, s32 h, s32 a, s32 b, s32 c);
extern u8* D_0041592C[];
extern char D_002B4BB8[];
u8 XB_FASTCALL xb_iterator_eq(s32* self, s32 edx, s32* other);

void xb_xlive_disp_CheckIndex(s32 index, s32 a, s32 b) {
    u8* p;

    if (!(index >= 0 && index < 5)) {
        _assert(D_002B4B20, D_002B4B48, 0x574);
    }

    p = D_00798128 + index * 0x20;
    *(s32*)(p + 0x18) = a;
    *(s32*)(p + 0x1C) = b;
}

void xb_xlive_disp_DrawRect2(s32 index, f32 x, f32 y, f32 w, f32 h, f32 a, s32 b) {
    u8* e;

    (void)a;
    (void)b;

    if (!(index >= 0 && index < 5)) {
        _assert(D_002B4BB8, D_002B4B48, 0x57E);
    }

    e = D_00798128 + index * 0x20;
    memset(e + 8, 0, 12);
    *(s32*)(e + 0x1C) = 0;
    *(s16*)(e + 8) = (s16)x;
    *(s16*)(e + 0xA) = (s16)y;
    *(s16*)(e + 0xC) = (s16)w;
    *(s16*)(e + 0xE) = (s16)h;
    *(s32*)(e + 0x10) = *(s32*)e | 0xFFFF0000;
    *(s32*)(e + 0x18) = 0;
    e[0x14] = 1;
}

void xb_xlive_disp_DrawRect1(s32 a, f32 x, f32 y, f32 w) {
    xb_xlive_disp_DrawRect2(a, x, w, y, w, 1.0f, 1);
}

s32 xb_xlive_disp_IsEnabled(void) {
    return *D_003F3A10;
}

void xb_xlive_disp_GetScale(f32* x, f32* y) {
    u8* p = D_003F3A10;

    *x = *(f32*)(p + 4);
    *y = *(f32*)(p + 8);
}

s32 xb_GetOnlineFlagThunk(void) {
    return xb_GetOnlineFlag();
}

u8 xb_ReturnFalse(void) {
    return 0;
}

u32* XB_FASTCALL xb_iterator4_inc(u32* self) {
    *self += 4;
    return self;
}

s32 XB_FASTCALL xb_xlive_disp_IsMissing(s32* self, s32 edx, s32* other) {
    return xb_iterator_eq(self, edx, other) == 0;
}

void* XB_FASTCALL xb_Identity(void* self) {
    return self;
}

s32 xb_vector20_max_size(void) {
    return 0xCCCCCCC;
}

u8** XB_FASTCALL xb_iterator112_add(u8** self, s32 edx, s32 n) {
    (void)edx;
    *self += n * 0x70;
    return self;
}

u8** XB_FASTCALL xb_iterator20_add(u8** self, s32 edx, s32 n) {
    (void)edx;
    *self += n * 20;
    return self;
}

void* xb_vector20_allocate(s32 n, s32 hint) {
    (void)hint;
    return operator_new(n * 20);
}

u8 XB_FASTCALL xb_iterator_eq(s32* self, s32 edx, s32* other) {
    (void)edx;
    return *self == *other;
}

s32 xb_vector_XONLINE_USER_ThunkF87A8(void) {
    return xb_vector20_max_size();
}

void* XB_FASTCALL xb_vector_XONLINE_USER_Reserve(void* self, s32 edx, s32 n) {
    (void)self;
    (void)edx;
    return xb_vector20_allocate(n, 0);
}

u8** XB_FASTCALL xb_vector20_At(u8** self, s32 edx, u8** ret, s32 n) {
    u8* it = *self;

    *ret = *xb_iterator20_add(&it, edx, n);
    return ret;
}

s32 xb_xlive_disp_SetObj0C(s32 id, s32 v) {
    u8* o = xb_xlive_disp_FindObj(id);

    if (o == 0) {
        return -1;
    }

    *(s32*)(o + 0xC) = v;
    return 1;
}

void xb_xlive_disp_CheckIndex2(s32 index, s32 id) {
    u8* o;

    if (!(index >= 0 && index < 5)) {
        _assert(D_002B4B20, D_002B4B48, 0x55D);
    }

    D_0079812C[index * 8] = id;
    o = xb_xlive_disp_FindObj(id);

    if (o) {
        if (o[0x3E] >= 6) {
            _assert(D_002B4BF0, D_002B4B48, 0x564);
        }

        o[o[0x3E] + 0x38] = index;
        o[0x3E]++;
    }
}

void XB_FASTCALL xb_vector_XONLINE_USER_Fill(void* self, s32 edx, void* a, void* b, void* c) {
    (void)edx;
    xb_vector_XONLINE_USER_FillN(a, b, c, self);
}

void XB_FASTCALL xb_vector20_Fill(void* self, s32 edx, void* a, void* b, void* c) {
    (void)edx;
    xb_vector20_FillN(a, b, c, self);
}

void xb_xlive_disp_Thunk108FA6(void) {
    xb_vector_XONLINE_USER_Destroy();
}

void xb_xlive_disp_ThunkF9000(void) {
    xb_vector20_Clear();
}

void xb_xlive_disp_CheckHandle(s32* handle, f32 a, f32 b, f32 c, f32 d, f32 e) {
    if (handle == 0) {
        _assert(D_002B4C44, D_002B4B48, 0x116);
    }

    xb_xlive_friend_Release(*handle);
    *handle = -1;
    *handle = xb_xlive_disp_DrawRectF(a, b, c, d, e);
}

void xb_xlive_disp_DrawTextBox(f32 x, f32 y, f32 s, s32 text, f32 alpha, s32 flags) {
    (void)alpha;
    xb_xlive_disp_DrawText(D_00798118, x, y, s, 0x14, 0x14, flags, text, 1);
}

void xb_xlive_disp_DrawBox20(f32 x, f32 y, f32 s, s32 text, f32 alpha, s32 flags, s32 c) {
    (void)alpha;
    xb_xlive_disp_DrawText(D_00798118, x, y, s, 0x14, 0x14, flags, text, c);
}

void xb_xlive_disp_DrawMessage(s32 col, s32 row, s32 text, f32 s, f32 a, s32 flags) {
    u8* c;

    (void)a;

    if (col >= 0 && row >= 0) {
        c = D_0041592C[col] + row * 0x20C;
        xb_xlive_disp_DrawText(D_00798118, *(f32*)c, *(f32*)(c + 4), s, 0x14, 0x14, flags, *(s32*)(c + 0x208), text);
    }
}

void xb_xlive_disp_DrawRectI(s32 font, f32 x, f32 y, f32 s, s32 text, f32 size, s32 flags, s32 c) {
    xb_xlive_disp_DrawText(font, x, y, s, (s32)size, (s32)size, flags, text, c);
}

void xb_xlive_disp_DrawCell(s32 font, s32 col, s32 row, s32 text, f32 s, f32 a, s32 flags) {
    u8* c;

    (void)a;

    if (col >= 0 && row >= 0) {
        c = D_0041592C[col] + row * 0x20C;
        xb_xlive_disp_DrawText(font, *(f32*)c, *(f32*)(c + 4), s, 0x14, 0x14, flags, *(s32*)(c + 0x208), text);
    }
}

/* The Live display's per-frame drawing, xb_OnlineUpdate, and the helpers
 * only it calls. The three scalers were static: retail passes their
 * pointer in a register (they are listed in config/sf33rd/static.txt). They scale by the
 * display's factors (D_003F3A10: a flag, then x and y) when it has them. */

s32 xb_GetOnlineFlagThunk(void);
s32 xb_LiveWork_Get2330(void);
s32 XB_FASTCALL xb_xlive_friend_IsEmpty(void* self);
s32 flSetRenderState(s32 func, u32 value);
void xb_xlive_font_SetProjection(void);
void xb_xlive_font_Clear(void);
s32 xb_xlive_font_PutChars(const char* str);
void xb_xlive_font_Flush(void);
void xb_xlive_font_Print(u8* rec);
void* XB_FASTCALL xb_xlive_friend_GetElem4(u8* self, s32 edx, void** ret);
void* XB_FASTCALL xb_xlive_friend_GetElem8(u8* self, s32 edx, void** ret);
s32 XB_FASTCALL xb_xlive_disp_IsMissing(s32* self, s32 edx, s32* other);
s32 XB_FASTCALL xb_xlive_ThunkFC23E(u8* self);
u32* XB_FASTCALL xb_iterator4_inc(u32* self);
u32 XB_FASTCALL std__vector_XONLINE_USER__size(void* self);
u32 XB_FASTCALL std__vector_Elem14__size(void* self);
u8* XB_FASTCALL xb_xlive_disp_LookupF8B77(void* self, s32 edx, u32 i);
u8* XB_FASTCALL xb_xlive_disp_LookupF8B96(void* self, s32 edx, u32 i);
void XB_FASTCALL xb_xlive_disp_VectorOpF990D(void* self, s32 edx, u32 n);
void XB_FASTCALL xb_xlive_disp_VectorOpF983A(void* self, s32 edx, u32 n);
u8* xb_FindOnlineObj(s32 id);
u8 xb_LiveWork_Call113F24(void);
void xb_DrawFilledRect(s32 w, s32 h, u32 col);
void xb_ClampFloatRect(f32 x, f32 y, f32 w, f32 h, f32 z, s32 a);
void xb_OnlineServiceStep(s32 a, f32 b, f32 c, f32 d, f32 e, f32 f, s32 g);
void xb_OnlineDrawIcon(u32 x, u32 y, s32 icon);
void xb_OnlineDrawScaled(u32 x, u32 y, s32 icon, f32 sx, f32 sy);
void sub_0004384A();
extern s32 D_003F3A14;
extern u8 D_007981C8[];
extern f32 D_002190AC;
extern u8 D_002B4C30[];
extern char D_002B4C10[];
extern char D_002B4C18[];
extern u8 D_00798110;
extern f32 D_00798114;
extern s32 D_0079811C;
extern s32 D_00798108;
extern f32 D_007980FC;
extern f32 D_00798100;
extern f32 D_007980F4;
extern f32 D_007980F0;
extern f32 D_00798104;
extern s32 D_007980F8;
extern u8 D_0079AEE0;

/* xb_xlive_disp_ScaleRect 0xF86BA: a window's rectangle (+0x1C to +0x28). */
void xb_xlive_disp_ScaleRect(u8* w) {
    f32* s = (f32*)D_003F3A10;

    if (D_003F3A10[0] == 0) {
        return;
    }

    *(f32*)(w + 0x1C) = *(f32*)(w + 0x1C) * s[1];
    *(f32*)(w + 0x20) = s[2] * *(f32*)(w + 0x20);
    *(f32*)(w + 0x24) = *(f32*)(w + 0x24) * s[1];
    *(f32*)(w + 0x28) = s[2] * *(f32*)(w + 0x28);
}

/* xb_xlive_disp_ScaleByte 0xF8600: a text record's position (+0, +2) and
 * glyph size (+8, +9). */
void xb_xlive_disp_ScaleByte(u8* r) {
    f32* s = (f32*)D_003F3A10;

    if (D_003F3A10[0] == 0) {
        return;
    }

    r[8] = (u8)(s32)((f32)r[8] * s[1]);
    r[9] = (u8)(s32)((f32)r[9] * s[2]);
    *(s16*)r = (s16)(s32)((f32)*(s16*)r * s[1]);
    *(s16*)(r + 2) = (s16)(s32)((f32)*(s16*)(r + 2) * s[2]);
}

/* xb_xlive_disp_ScaleWord 0xF8671: an icon's position (+0, +2). */
void xb_xlive_disp_ScaleWord(u16* p) {
    f32* s = (f32*)D_003F3A10;

    if (D_003F3A10[0] == 0) {
        return;
    }

    p[0] = (u16)(s32)((f32)p[0] * s[1]);
    p[1] = (u16)(s32)((f32)p[1] * s[2]);
}

/* xb_OnlineUpdate 0xF9BA6: the Live display's frame. When online (or in
 * the Live menus) and the display list (D_007981C8) is not empty, its
 * glyphs are loaded, then each display object's window is drawn, when
 * shown (the window's flag at +0x58 with +0x34 at least 2, or the current
 * or focused object), with its text records, the cursor markers on them,
 * and its icons, behind one dimming rectangle; each object's per-frame
 * lists are then emptied. */
void xb_OnlineUpdate(void) {
    u8 win[0x5C];
    u8 rec[0x70];
    u8 mark[0x70];
    void* it;
    void* end;
    u8* obj;
    u8* w;
    u8* e;
    u8* p;
    u32 i;
    s32 j;
    u8 dimmed;
    XB_ARG a;

    if (xb_GetOnlineFlagThunk() == 0 && xb_LiveWork_Get2330() == 0) {
        return;
    }

    if ((u8)xb_xlive_friend_IsEmpty(D_007981C8) != 0) {
        return;
    }

    D_003F3A14 = (D_003F3A10[0] == 0) + 1;
    flSetRenderState(0x61, 0x1000000);
    flSetRenderState(0x5E, 0x32);
    flSetRenderState(0x5F, 5);
    flSetRenderState(0x60, 0);
    flSetRenderState(0x6C, 0);
    xb_xlive_font_SetProjection();
    xb_xlive_font_Clear();
    xb_xlive_font_PutChars((const char*)D_002B4C30);

    /* the glyphs every object's text needs */
    a.v = (s32)&it;
    ((void* (XB_FASTCALL*)(u8*, XB_ARG))xb_xlive_friend_GetElem4)(D_007981C8, a);

    for (;;) {
        a.v = (s32)&end;
        a.v = (s32)((void* (XB_FASTCALL*)(u8*, XB_ARG))xb_xlive_friend_GetElem8)(D_007981C8, a);

        if ((u8)((s32 (XB_FASTCALL*)(void*, XB_ARG))xb_xlive_disp_IsMissing)(&it, a) == 0) {
            break;
        }

        obj = *(u8**)xb_xlive_ThunkFC23E((u8*)&it);

        if (*(s32*)obj == -1) {
            _assert(D_002B4C18, D_002B4B48, 0x1FD);
        }

        for (i = 0; i < std__vector_XONLINE_USER__size(obj + 0x14); i++) {
            a.v = i;
            xb_xlive_font_PutChars((const char*)(((u8* (XB_FASTCALL*)(void*, XB_ARG))xb_xlive_disp_LookupF8B77)(obj + 0x14, a) + 0xC));
        }

        xb_iterator4_inc((u32*)&it);
    }

    xb_xlive_font_Flush();
    dimmed = 0;
    a.v = (s32)&it;
    ((void* (XB_FASTCALL*)(u8*, XB_ARG))xb_xlive_friend_GetElem4)(D_007981C8, a);

    for (;;) {
        a.v = (s32)&end;
        a.v = (s32)((void* (XB_FASTCALL*)(u8*, XB_ARG))xb_xlive_friend_GetElem8)(D_007981C8, a);

        if ((u8)((s32 (XB_FASTCALL*)(void*, XB_ARG))xb_xlive_disp_IsMissing)(&it, a) == 0) {
            break;
        }

        obj = *(u8**)xb_xlive_ThunkFC23E((u8*)&it);

        if (*(s32*)obj == -1) {
            _assert(D_002B4C18, D_002B4B48, 0x20F);
        }

        w = xb_FindOnlineObj(*(s32*)obj);

        if (w == 0) {
            _assert(D_002B4C10, D_002B4B48, 0x214);
        }

        if (!dimmed && xb_LiveWork_Call113F24() && *(f32*)(obj + 4) == D_002190AC) {
            xb_DrawFilledRect(0x280, 0x1C0, 0xA0000000);
            dimmed = 1;
        }

        if ((w[0x58] != 0 && *(s32*)(w + 0x34) >= 2) || *(s32*)obj == D_00798118 || *(s32*)obj == D_0079811C) {
            memcpy(win, w, sizeof(win));
            xb_xlive_disp_ScaleRect(win);
            xb_ClampFloatRect(*(f32*)(win + 0x1C), *(f32*)(win + 0x20), *(f32*)(win + 0x24), *(f32*)(win + 0x28), 0.0f,
                              *(s32*)(obj + 0xC));

            if (D_00798110 != 0 && D_00798114 == *(f32*)(obj + 4)) {
                xb_OnlineServiceStep(D_00798108, D_007980FC, D_00798100, D_007980F4, D_007980F0, D_00798104, D_007980F8);
            }

            for (i = 0; i < std__vector_XONLINE_USER__size(obj + 0x14); i++) {
                a.v = i;
                memcpy(rec, ((u8* (XB_FASTCALL*)(void*, XB_ARG))xb_xlive_disp_LookupF8B77)(obj + 0x14, a), sizeof(rec));
                xb_xlive_disp_ScaleByte(rec);
                xb_xlive_font_Print(rec);

                for (j = 0; j < obj[0x3E]; j++) {
                    e = D_00798128 + obj[0x38 + j] * 0x20;

                    if ((s32)i != *(s16*)(e + 0xA)) {
                        continue;
                    }

                    a.v = i;
                    memcpy(mark, ((u8* (XB_FASTCALL*)(void*, XB_ARG))xb_xlive_disp_LookupF8B77)(obj + 0x14, a), sizeof(mark));
                    *(s16*)mark += (s16)(*(s16*)(e + 0x18) - 0x14);
                    *(f32*)(mark + 4) = 0.0f;
                    mark[8] = 0x14;
                    mark[9] = 0x14;
                    *(u16*)(mark + 0xA) = 5;
                    memcpy(mark + 0xC, D_002B4C30, 3);
                    xb_xlive_disp_ScaleByte(mark);
                    xb_xlive_font_Print(mark);
                }
            }

            for (i = 0; i < std__vector_Elem14__size(obj + 0x28); i++) {
                a.v = i;
                p = ((u8* (XB_FASTCALL*)(void*, XB_ARG))xb_xlive_disp_LookupF8B96)(obj + 0x28, a);
                xb_xlive_disp_ScaleWord((u16*)p);

                if (*(s32*)(p + 0xC) == 0) {
                    xb_OnlineDrawIcon(*(u16*)p, *(u16*)(p + 2), *(s32*)(p + 0x10));
                } else {
                    xb_OnlineDrawScaled(*(u16*)p, *(u16*)(p + 2), *(s32*)(p + 0x10), *(f32*)(p + 4), *(f32*)(p + 8));
                }
            }
        }

        *(s32*)(obj + 0x24) = 0;
        *(s32*)(obj + 8) = 0;
        ((void (XB_FASTCALL*)(void*))xb_xlive_disp_ThunkF9000)(obj + 0x28);
        ((void (XB_FASTCALL*)(void*))xb_xlive_disp_Thunk108FA6)(obj + 0x14);
        a.v = 8;
        ((void (XB_FASTCALL*)(void*, XB_ARG))xb_xlive_disp_VectorOpF990D)(obj + 0x28, a);
        a.v = 0x80;
        ((void (XB_FASTCALL*)(void*, XB_ARG))xb_xlive_disp_VectorOpF983A)(obj + 0x14, a);
        obj[0x3E] = 0;
        xb_iterator4_inc((u32*)&it);
    }

    sub_0004384A();
    memset(D_00798128, 0, 0xA0);
    D_00798110 = 0;
    flSetRenderState(0x6C, 1);
    D_0079AEE0 = 0;
}

/* The display list (D_007981C8, a std::list of the 30 display objects at
 * D_007981D8, 0x40 bytes each: id, depth, ...) kept in depth order. */

void* XB_FASTCALL xb_vector_Insert(void* self, s32 edx, void** ret, void* it);
void XB_FASTCALL xb_xlive_disp_vector4_Draw(void* self, s32 edx, void** ret, void* it, u8** val);
void XB_FASTCALL xb_xlive_disp_vector4_DrawRect(void* self, s32 edx, u8** val);
void XB_FASTCALL xb_xlive_disp_vector20_Draw(void* self, s32 edx, u8* val);
void xb_OnlineObj_Kill(s32 id);
void xb_OnlineObj_ClearAll(void);
s32 xb_FindFreeOnlineObj(f32 x, f32 y, f32 w, f32 h);
s32 xb_xlive_SetObjFlag58(s32 id, s32 on);
f32 xb_SetLightRange(f32 v);
extern u8 D_007981D8[];
extern f32 D_002190D4;
extern f32 D_002190B0;
extern f32 D_002190B4;
extern f32 D_002190B8;
extern f32 D_002190BC;
extern f32 D_00219090;
extern f32 D_002197DC;
extern s32 D_00798964;
extern s32 D_0079810C;
extern u8 D_0079A418[];
extern f32 D_0025F370;
extern f32 D_002B8A14;
extern char D_002B4C34[];
extern char D_002B4C4C[];
extern char D_002B4C60[];

/* xb_xlive_disp_FindObj 0xF8D79: the display object with the id. */
u8* xb_xlive_disp_FindObj(s32 id) {
    void* it;
    void* end;
    u8* obj;
    XB_ARG a;

    if ((u8)xb_xlive_friend_IsEmpty(D_007981C8) != 0) {
        return 0;
    }

    a.v = (s32)&it;
    ((void* (XB_FASTCALL*)(u8*, XB_ARG))xb_xlive_friend_GetElem4)(D_007981C8, a);

    for (;;) {
        a.v = (s32)&end;
        a.v = (s32)((void* (XB_FASTCALL*)(u8*, XB_ARG))xb_xlive_friend_GetElem8)(D_007981C8, a);

        if ((u8)((s32 (XB_FASTCALL*)(void*, XB_ARG))xb_xlive_disp_IsMissing)(&it, a) == 0) {
            return 0;
        }

        obj = *(u8**)xb_xlive_ThunkFC23E((u8*)&it);

        if (*(s32*)obj == id) {
            return obj;
        }

        xb_iterator4_inc((u32*)&it);
    }
}

/* xb_xlive_disp_ReleaseAll 0xF90FA: every display object taken off the
 * list with its lists emptied, the online objects cleared, and the 30
 * slots made free (id -1, depth D_002190D4). */
void xb_xlive_disp_ReleaseAll(void) {
    void* it;
    void* end;
    void* next;
    u8* p;
    XB_ARG a;
    XB_ARG b;

    a.v = (s32)&it;
    ((void* (XB_FASTCALL*)(u8*, XB_ARG))xb_xlive_friend_GetElem4)(D_007981C8, a);

    for (;;) {
        a.v = (s32)&end;
        a.v = (s32)((void* (XB_FASTCALL*)(u8*, XB_ARG))xb_xlive_friend_GetElem8)(D_007981C8, a);

        if ((u8)((s32 (XB_FASTCALL*)(void*, XB_ARG))xb_xlive_disp_IsMissing)(&it, a) == 0) {
            break;
        }

        ((void (XB_FASTCALL*)(void*))xb_xlive_disp_Thunk108FA6)(*(u8**)xb_xlive_ThunkFC23E((u8*)&it) + 0x14);
        ((void (XB_FASTCALL*)(void*))xb_xlive_disp_ThunkF9000)(*(u8**)xb_xlive_ThunkFC23E((u8*)&it) + 0x28);
        a.v = (s32)&next;
        b.v = (s32)it;
        it = *(void**)((void* (XB_FASTCALL*)(u8*, XB_ARG, XB_ARG))xb_vector_Insert)(D_007981C8, a, b);
    }

    xb_OnlineObj_ClearAll();
    memset(D_007981D8, 0, 0x780);

    for (p = D_007981D8; p < D_007981D8 + 0x780; p += 0x40) {
        *(s32*)p = -1;
        *(f32*)(p + 4) = D_002190D4;
    }
}

/* xb_xlive_disp_ReleaseAllThunk 0xF924A. */
void xb_xlive_disp_ReleaseAllThunk(void) {
    xb_xlive_disp_ReleaseAll();
}

/* xb_xlive_friend_Release 0xF9199: the display object with the id taken
 * off the list, its online object killed, its lists emptied and its slot
 * freed. */
void xb_xlive_friend_Release(s32 id) {
    void* it;
    void* end;
    u8* obj;
    XB_ARG a;
    XB_ARG b;

    if ((u8)xb_xlive_friend_IsEmpty(D_007981C8) != 0 || id == -1) {
        return;
    }

    a.v = (s32)&it;
    ((void* (XB_FASTCALL*)(u8*, XB_ARG))xb_xlive_friend_GetElem4)(D_007981C8, a);

    for (;;) {
        a.v = (s32)&end;
        a.v = (s32)((void* (XB_FASTCALL*)(u8*, XB_ARG))xb_xlive_friend_GetElem8)(D_007981C8, a);

        if ((u8)((s32 (XB_FASTCALL*)(void*, XB_ARG))xb_xlive_disp_IsMissing)(&it, a) == 0) {
            return;
        }

        obj = *(u8**)xb_xlive_ThunkFC23E((u8*)&it);

        if (*(s32*)obj == id) {
            break;
        }

        xb_iterator4_inc((u32*)&it);
    }

    a.v = (s32)&end;
    b.v = (s32)it;
    ((void* (XB_FASTCALL*)(u8*, XB_ARG, XB_ARG))xb_vector_Insert)(D_007981C8, a, b);
    xb_OnlineObj_Kill(id);
    ((void (XB_FASTCALL*)(void*))xb_xlive_disp_Thunk108FA6)(obj + 0x14);
    ((void (XB_FASTCALL*)(void*))xb_xlive_disp_ThunkF9000)(obj + 0x28);
    memset(obj, 0, 0x40);
    *(s32*)obj = -1;
}

/* xb_xlive_disp_DrawHandleRect 0xFA171: a free slot given the online
 * object's handle and the depth, and put on the list before the first
 * object at least as deep. Retail passes the handle in ebx (a static,
 * config/sf33rd/static.txt). */
void xb_xlive_disp_DrawHandleRect(s32 handle, f32 z) {
    u8* slot;
    void* it;
    void* end;
    void* ret;
    XB_ARG a;
    XB_ARG b;
    XB_ARG c;

    if (handle == -1) {
        _assert(D_002B4C34, D_002B4B48, 0x161);
    }

    for (slot = D_007981D8; *(s32*)slot != -1; ) {
        slot += 0x40;

        if (slot >= D_007981D8 + 0x780) {
            return;
        }
    }

    memset(slot, 0, 0x40);
    *(s32*)slot = handle;
    *(f32*)(slot + 4) = z;
    *(u32*)(slot + 0xC) = 0xA0000000;

    if ((u8)xb_xlive_friend_IsEmpty(D_007981C8) != 0) {
        a.v = (s32)&slot;
        ((void (XB_FASTCALL*)(void*, XB_ARG))xb_xlive_disp_vector4_DrawRect)(D_007981C8, a);
        return;
    }

    a.v = (s32)&it;
    ((void* (XB_FASTCALL*)(u8*, XB_ARG))xb_xlive_friend_GetElem4)(D_007981C8, a);

    for (;;) {
        a.v = (s32)&end;
        a.v = (s32)((void* (XB_FASTCALL*)(u8*, XB_ARG))xb_xlive_friend_GetElem8)(D_007981C8, a);

        if ((u8)((s32 (XB_FASTCALL*)(void*, XB_ARG))xb_xlive_disp_IsMissing)(&it, a) == 0) {
            break;
        }

        if (*(f32*)(*(u8**)xb_xlive_ThunkFC23E((u8*)&it) + 4) >= *(f32*)(slot + 4)) {
            a.v = (s32)&ret;
            b.v = (s32)it;
            c.v = (s32)&slot;
            ((void (XB_FASTCALL*)(void*, XB_ARG, XB_ARG, XB_ARG))xb_xlive_disp_vector4_Draw)(D_007981C8, a, b, c);
            break;
        }

        xb_iterator4_inc((u32*)&it);
    }

    a.v = (s32)&end;
    a.v = (s32)((void* (XB_FASTCALL*)(u8*, XB_ARG))xb_xlive_friend_GetElem8)(D_007981C8, a);

    if (((u8 (XB_FASTCALL*)(s32*, XB_ARG))xb_iterator_eq)((s32*)&it, a) != 0) {
        a.v = (s32)&slot;
        ((void (XB_FASTCALL*)(void*, XB_ARG))xb_xlive_disp_vector4_DrawRect)(D_007981C8, a);
    }
}

/* xb_xlive_disp_DrawObj 0xFA5E1: an icon added to a display object's
 * icon list (0 or -1 for the base object): position (less 10 and 5),
 * scale (the default value meaning 1), the icon. */
void xb_xlive_disp_DrawObj(s32 id, f32 x, f32 y, s32 u0, s32 u1, s32 icon, f32 sx, f32 sy) {
    u8* obj;
    u8 e[0x14];
    XB_ARG a;

    (void)u0;
    (void)u1;

    if (id == -1) {
        id = D_00798118;
    }

    obj = xb_xlive_disp_FindObj(id);

    if (obj == 0) {
        return;
    }

    *(s32*)(e + 0xC) = 1;
    *(s32*)(e + 0x10) = icon;
    *(u16*)e = (u16)((s32)x - 10);
    *(u16*)(e + 2) = (u16)((s32)y - 5);
    *(f32*)(e + 4) = sx == D_002190D4 ? D_002190AC : sx;
    *(f32*)(e + 8) = sy == D_002190D4 ? D_002190AC : sy;
    a.v = (s32)e;
    ((void (XB_FASTCALL*)(void*, XB_ARG))xb_xlive_disp_vector20_Draw)(obj + 0x28, a);
    (*(s32*)(obj + 0x24))++;
}

/* xb_xlive_disp_DrawRectFloat 0xFA6F1 and xb_xlive_disp_DrawRectF 0xFA733:
 * a new online rectangle object put on the display list (at depth 0, or
 * the given depth). Return its handle, -1 when none was free. */
s32 xb_xlive_disp_DrawRectFloat(f32 x, f32 y, f32 w, f32 h) {
    s32 handle = xb_FindFreeOnlineObj(x, y, w, h);

    if (handle != -1) {
        xb_xlive_disp_DrawHandleRect(handle, 0.0f);
    }

    return handle;
}

s32 xb_xlive_disp_DrawRectF(f32 x, f32 y, f32 w, f32 h, f32 z) {
    s32 handle = xb_FindFreeOnlineObj(x, y, w, h);

    if (handle != -1) {
        xb_xlive_disp_DrawHandleRect(handle, z);
    }

    return handle;
}

/* xb_OnlineObj_ClearAll 0x11B232: the online object table cleared. */
void xb_OnlineObj_ClearAll(void) {
    memset(D_0079A418, 0, 0xAC8);
}

/* xb_xlive_disp_SetScale 0xF85CC: the display's x and y factors. */
void xb_xlive_disp_SetScale(f32 x, f32 y) {
    ((f32*)D_003F3A10)[1] = x;
    ((f32*)D_003F3A10)[2] = y;
}

/* xb_xlive_disp_SetDefaultScale 0x1204BB. */
void xb_xlive_disp_SetDefaultScale(void) {
    xb_xlive_disp_SetScale(D_0025F370, D_002B8A14);
}

/* xb_xlive_disp_Reset 0xFAA91: everything released, the slots freed, and
 * the base and focus objects (D_00798118, D_0079811C) made anew, hidden. */
void xb_xlive_disp_Reset(void) {
    u8* p;

    xb_xlive_disp_ReleaseAllThunk();
    memset(D_007981D8, 0, 0x780);

    for (p = D_007981D8; p < D_007981D8 + 0x780; p += 0x40) {
        *(s32*)p = -1;
        *(f32*)(p + 4) = D_002190D4;
    }

    D_00798118 = xb_xlive_disp_DrawRectFloat(0.0f, 0.0f, 0.0f, 0.0f);
    xb_xlive_SetObjFlag58(D_00798118, 0);

    if (D_00798118 == -1) {
        _assert(D_002B4C60, D_002B4B48, 0x9F);
    }

    D_0079811C = xb_xlive_disp_DrawRectFloat(0.0f, 0.0f, 0.0f, 0.0f);
    xb_xlive_SetObjFlag58(D_0079811C, 0);

    if (D_0079811C == -1) {
        _assert(D_002B4C4C, D_002B4B48, 0xA2);
    }

    xb_xlive_disp_SetDefaultScale();
}

/* xb_xlive_disp_ScaleTime 0xF841D: the cursor's pulse: frame D_00798964
 * (of 16) through xb_SetLightRange to an alpha for all five cursors. */
void xb_xlive_disp_ScaleTime(void) {
    u8* p;
    f32 t;
    s32 v;

    t = xb_SetLightRange((f32)(D_00798964 << 12) * D_002190B4 / D_002190B0 * D_002190B8 / D_002190BC) * D_00219090 + D_002197DC;
    v = (s32)t;
    D_0079810C = v;

    for (p = D_00798128; p < D_00798128 + 0xA0; p += 0x20) {
        *(s32*)p = v;
    }

    if (++D_00798964 > 15) {
        D_00798964 = 0;
    }
}
