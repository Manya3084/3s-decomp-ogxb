/* xlive_disp.c: Xbox-only code from Capcom's xlive_disp.cpp. Its _assert path names it, and the
 * code that pushes the path places it at 0xF832F to 0xFAA91.
 * Capcom's source is lost. Its C++ methods are written as C,
 * XB_FASTCALL (__fastcall) with this first. Each body was checked
 * against retail by analysis-ps2map/xbgen.py. The xb_ names are
 * made up. */

#include "types.h"

void xb_vector_XONLINE_USER_Destroy(void);
void xb_vector20_Clear(void);
s32 xb_GetOnlineFlag(void);
extern u8* D_003F3A10;
void* operator_new(u32 size);
void xb_vector_XONLINE_USER_FillN(void* a, void* b, void* c, void* self);
void xb_vector20_FillN(void* a, void* b, void* c, void* self);
u8* xb_xlive_disp_FindObj(s32 id);
extern s32 D_00798118;
void xb_xlive_disp_DrawText(s32 font, f32 x, f32 y, f32 s, s32 w, s32 h, s32 a, s32 b, s32 c);
void xb_xlive_disp_DrawRect2(s32 a, f32 b, f32 c, f32 d, f32 e, f32 f, s32 g);
void _assert(const char* expr, const char* file, u32 line);
extern char D_002B4B20[];
extern char D_002B4B48[];
extern u8 D_00798128[];
extern u8* D_0041592C[];
extern void (XB_STDCALL *D_00218DC8)(void* cs);
extern char D_002B4C44[];
void xb_xlive_friend_Release(s32 id);
s32 xb_xlive_disp_DrawRectF(f32 a, f32 b, f32 c, f32 d, f32 e);
extern char D_002B4BF0[];
extern s32 D_0079812C[];
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
