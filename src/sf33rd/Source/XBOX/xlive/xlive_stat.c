/* xlive_stat.c: Xbox-only code from Capcom's xlive_stat.cpp. Its _assert path names it, and the
 * code that pushes the path places it at 0x1156DF to 0x11AAB8.
 * Capcom's source is lost. Its C++ methods are written as C,
 * XB_FASTCALL (__fastcall) with this first. Each body was checked
 * against retail by analysis-ps2map/xbgen.py. The xb_ names are
 * made up. */

#include "types.h"

s32 XB_FASTCALL CXBOnlineTask_Close(void* self);
void xb_xlive_friend_Release(s32 id);
void XB_FASTCALL xb_WINSTR_CLASS_Release(s32* self);
void** XB_FASTCALL xb_iterator_ctor(void** self, s32 edx, void* p);
void _assert(const char* expr, const char* file, u32 line);
extern char D_002B83E0[];
extern char D_002B84C4[];
extern char D_002B84D0[];
extern char D_002B8500[];
extern char D_002B8530[];
extern char D_002B8560[];
extern char D_002B8590[];
extern char D_002B85C0[];

/* A player's Live statistics record: seven XONLINE_STATs (id, type, value)
 * of 0x10 bytes, the wins, matches, grade, points, region, rating (64-bit,
 * id 0xFFFE) and rank. 1 is XONLINE_STAT_LONG, 2 XONLINE_STAT_LONGLONG. */
typedef struct {
    u16 id;
    u16 pad;
    s32 type;
    s32 lo;
    s32 hi;
} XB_XSTAT;

s32 XB_FASTCALL xb_XLIVE_STAT_CLASS_CloseTasks(u8* self) {
    CXBOnlineTask_Close(self + 0x430);
    CXBOnlineTask_Close(self + 0x434);
    CXBOnlineTask_Close(self + 0x438);
    CXBOnlineTask_Close(self + 0x43C);
    return 0;
}

s32 XB_FASTCALL xb_XLIVE_STAT_CLASS_Clear(u8* self) {
    s32* w;

    xb_XLIVE_STAT_CLASS_CloseTasks(self);
    xb_WINSTR_CLASS_Release(*(s32**)(self + 0x4A0));
    w = (s32*)(self + 0x444);
    xb_xlive_friend_Release(*w);
    *w = -1;
    w = (s32*)(self + 0x448);
    xb_xlive_friend_Release(*w);
    *w = -1;
    w = (s32*)(self + 0x44C);
    xb_xlive_friend_Release(*w);
    *w = -1;
    return 0;
}

void* XB_FASTCALL xb_vector_CopyCtor(void** self, s32 edx, void* p) {
    xb_iterator_ctor(self, edx, p);
    return self;
}

/* xb_xlive_stat_IsUnset 0x115BCA: 1 when a stat has no type yet or the
 * rank is 0. */
s32 XB_FASTCALL xb_xlive_stat_IsUnset(XB_XSTAT* self) {
    u32 i;

    for (i = 0; i < 7; i++) {
        if (self[i].type == 0) {
            return 1;
        }
    }

    return self[6].lo == 0;
}

/* xb_xlive_stat_SetWins 0X115BEA: stat 0 set, negative values as 0. */
void XB_FASTCALL xb_xlive_stat_SetWins(XB_XSTAT* self, s32 edx, s32 v) {
    (void)edx;

    if (v < 0) {
        _assert(D_002B84C4, D_002B83E0, 0XD4F);
        v = 0;
    }

    self[0].id = 0;
    self[0].type = 1;
    self[0].lo = v;
}

/* xb_xlive_stat_GetWins 0X115C20: stat 0's value. */
s32 XB_FASTCALL xb_xlive_stat_GetWins(XB_XSTAT* self) {
    if (self[0].type != 1) {
        _assert(D_002B84D0, D_002B83E0, 0XD5F);
    }

    return self[0].lo;
}

/* xb_xlive_stat_SetMatches 0x115C45: stat 1 set. */
void XB_FASTCALL xb_xlive_stat_SetMatches(XB_XSTAT* self, s32 edx, s32 v) {
    (void)edx;
    self[1].id = 1;
    self[1].type = 1;
    self[1].lo = v;
}

/* xb_xlive_stat_GetMatches 0X115C59: stat 1's value. */
s32 XB_FASTCALL xb_xlive_stat_GetMatches(XB_XSTAT* self) {
    if (self[1].type != 1) {
        _assert(D_002B8500, D_002B83E0, 0XD7F);
    }

    return self[1].lo;
}

/* xb_xlive_stat_SetGrade 0X115C7E: stat 2 set, negative values as 0. */
void XB_FASTCALL xb_xlive_stat_SetGrade(XB_XSTAT* self, s32 edx, s32 v) {
    (void)edx;

    if (v < 0) {
        _assert(D_002B84C4, D_002B83E0, 0XD90);
        v = 0;
    }

    self[2].id = 2;
    self[2].type = 1;
    self[2].lo = v;
}

/* xb_xlive_stat_GetGrade 0X115CB6: stat 2's value. */
s32 XB_FASTCALL xb_xlive_stat_GetGrade(XB_XSTAT* self) {
    if (self[2].type != 1) {
        _assert(D_002B8530, D_002B83E0, 0XDA0);
    }

    return self[2].lo;
}

/* xb_xlive_stat_SetPoint 0X115CDB: stat 3 set, negative values as 0. */
void XB_FASTCALL xb_xlive_stat_SetPoint(XB_XSTAT* self, s32 edx, s32 v) {
    (void)edx;

    if (v < 0) {
        _assert(D_002B84C4, D_002B83E0, 0XDB0);
        v = 0;
    }

    self[3].id = 3;
    self[3].type = 1;
    self[3].lo = v;
}

/* xb_xlive_stat_GetPoint 0X115D13: stat 3's value. */
s32 XB_FASTCALL xb_xlive_stat_GetPoint(XB_XSTAT* self) {
    if (self[3].type != 1) {
        _assert(D_002B8560, D_002B83E0, 0XDC0);
    }

    return self[3].lo;
}

/* xb_xlive_stat_SetRegion 0X115D38: stat 4 set, negative values as 0. */
void XB_FASTCALL xb_xlive_stat_SetRegion(XB_XSTAT* self, s32 edx, s32 v) {
    (void)edx;

    if (v < 0) {
        _assert(D_002B84C4, D_002B83E0, 0XDD0);
        v = 0;
    }

    self[4].id = 4;
    self[4].type = 1;
    self[4].lo = v;
}

/* xb_xlive_stat_GetRegion 0X115D70: stat 4's value. */
s32 XB_FASTCALL xb_xlive_stat_GetRegion(XB_XSTAT* self) {
    if (self[4].type != 1) {
        _assert(D_002B8590, D_002B83E0, 0XDE0);
    }

    return self[4].lo;
}

/* xb_xlive_stat_SetRating 0x115D95: the 64-bit rating (stat 5, id
 * 0xFFFE). */
void XB_FASTCALL xb_xlive_stat_SetRating(XB_XSTAT* self, s32 edx, s32 lo, s32 hi) {
    (void)edx;
    self[5].lo = lo;
    self[5].id = 0xFFFE;
    self[5].type = 2;
    self[5].hi = hi;
}

/* xb_xlive_stat_GetRank 0X115DB3: stat 6's value. */
s32 XB_FASTCALL xb_xlive_stat_GetRank(XB_XSTAT* self) {
    if (self[6].type != 1) {
        _assert(D_002B85C0, D_002B83E0, 0XE01);
    }

    return self[6].lo;
}

extern char D_0025CCA0[];
void XB_FASTCALL xb_XLIVE_STAT_CLASS_DrawPage0(u8* self);
s32 XB_FASTCALL xb_XLIVE_STAT_CLASS_DrawPage3(u8* self);

/* xb_XLIVE_STAT_CLASS_DrawPage 0x117F08: the stats page drawn by its state
 * (+0x58): the list (0) or the details (3, 4); 1, 2, 5 and 6 draw
 * nothing. */
s32 XB_FASTCALL xb_XLIVE_STAT_CLASS_DrawPage(u8* self) {
    switch (*(s32*)(self + 0x58)) {
    case 0:
        xb_XLIVE_STAT_CLASS_DrawPage0(self);
        break;
    case 1:
    case 2:
        break;
    case 3:
    case 4:
        xb_XLIVE_STAT_CLASS_DrawPage3(self);
        break;
    case 5:
    case 6:
        break;
    default:
        _assert(D_0025CCA0, D_002B83E0, 0x3F8);
        break;
    }

    return 0;
}

/* The XGetLanguage codes' short names. */
extern char D_00415FE4[];
extern char D_00415FE8[];
extern char D_00415FEC[];
extern char D_00415FF0[];
extern char D_00415FF4[];
extern char D_00415FF8[];
extern char D_00415FFC[];
extern char D_00416000[];
extern char D_00416004[];
extern char D_00416008[];

/* xb_XLIVE_STAT_CLASS_LangName 0x115B49: a language code's name (ENG,
 * JPN, DEU, FRA, ESN, ITA, KOR, ROC, PTG), ETC for others. */
char* XB_FASTCALL xb_XLIVE_STAT_CLASS_LangName(u8* self, s32 edx, s32 lang) {
    (void)self;
    (void)edx;

    switch (lang) {
    case 1:
        return D_00415FE4;
    case 2:
        return D_00415FE8;
    case 3:
        return D_00415FEC;
    case 4:
        return D_00415FF0;
    case 5:
        return D_00415FF4;
    case 6:
        return D_00415FF8;
    case 7:
        return D_00415FFC;
    case 8:
        return D_00416000;
    case 9:
        return D_00416004;
    }

    return D_00416008;
}

s32 XB_FASTCALL xb_xlive_stat_GetRank(XB_XSTAT* self);
u32 XB_STDCALL XGetLanguage(void);

/* xb_XLIVE_STAT_CLASS_GetLanguage 0x115BC5: XGetLanguage (the page is not
 * used). */
s32 XB_FASTCALL xb_XLIVE_STAT_CLASS_GetLanguage(u8* self) {
    (void)self;
    return XGetLanguage();
}

/* xb_XLIVE_STAT_CLASS_GetRank 0x116809: the page's (+0x2C0) rank, at most
 * 9999. */
s32 XB_FASTCALL xb_XLIVE_STAT_CLASS_GetRank(u8* self) {
    s32 r = xb_xlive_stat_GetRank((XB_XSTAT*)(self + 0x2C0));

    return r > 9999 ? 9999 : r;
}

extern u8* D_00798CAC;
void xb_xlive_disp_DrawCellLeft(s32 font, s32 col, s32 row, s32 text);
void xb_xlive_disp_DrawCellRight(s32 font, s32 col, s32 row, s32 text);
void XB_FASTCALL sub_00117261(u8* self);

/* xb_XLIVE_STAT_CLASS_DrawPage3 0x1177E3: the details pages (states 3 and
 * 4, on window +0x44C): with the stats loaded (+8 6) by column (+0xC):
 * the list (2, 3) or the empty page (4: its message, and the hint for
 * state 3 or 4). */
s32 XB_FASTCALL xb_XLIVE_STAT_CLASS_DrawPage3(u8* self) {
    s32 id;
    s32 c;

    if (*(s32*)(self + 0x58) == 3 || *(s32*)(self + 0x58) == 4) {
        id = *(s32*)(self + 0x44C);
    } else {
        id = -1;
    }

    if (*(s32*)(self + 4) < 0 || *(s32*)(self + 4) > 2) {
        _assert(D_0025CCA0, D_002B83E0, 0x497);
        return 0;
    }

    if (*(s32*)(self + 8) != 6) {
        return 0;
    }

    c = *(s32*)(self + 0xC);

    switch (c) {
    case 0:
    case 1:
        break;
    case 2:
    case 3:
        sub_00117261(self);
        break;
    case 4:
        xb_xlive_disp_DrawCellLeft(id, c, 8, 0);
        if (*(s32*)(self + 0x58) == 3) {
            xb_xlive_disp_DrawCellRight(id, 4, 0x10, 0);
        } else {
            xb_xlive_disp_DrawCellRight(id, 4, 0x11, 0);
        }
        break;
    default:
        _assert(D_0025CCA0, D_002B83E0, 0x492);
        break;
    }

    return 0;
}

s32 XB_FASTCALL xb_XLIVE_WORK_CLASS_Update(u8* self);
void XB_FASTCALL xb_XLIVE_WORK_CLASS_SetState4(u8* self);
s32 XB_FASTCALL xb_XLIVE_WORK_CLASS_Frame(u8* self);
s32 XB_FASTCALL xb_XLIVE_STAT_CLASS_ProcessResults(u8* self, s32 edx, s32* st);
s32 XB_FASTCALL xb_XLIVE_STAT_CLASS_Step1(u8* self, s32 edx, s32* st);
s32 XB_FASTCALL xb_XLIVE_STAT_CLASS_Step2(u8* self, s32 edx, s32* st);
s32 XB_FASTCALL xb_XLIVE_STAT_CLASS_Step3(u8* self, s32 edx, s32* st);
s32 XB_FASTCALL xb_XLIVE_STAT_CLASS_Step4(u8* self, s32 edx, s32* st);
s32 XB_FASTCALL xb_XLIVE_STAT_CLASS_Step5(u8* self, s32 edx, s32* st);
void XB_FASTCALL xb_xlive_main_StepState(u8* self);
void XB_FASTCALL xb_WINSTR_CLASS_Update(void* self);
s32 sub_0004AFFA(void);

/* xb_XLIVE_STAT_CLASS_Frame 0x11AAB8: one frame of the stats pages: the
 * work stepped (-1 on its error, the tasks closed), the page's state
 * (+0x58) stepped, the page drawn unless the work drew, and the text
 * window (+0x4A0). The step's result is returned, its status set. */
s32 XB_FASTCALL xb_XLIVE_STAT_CLASS_Frame(u8* self, s32 edx, s32* out) {
    s32 st = 0;
    s32 r = 0;
    XB_ARG a;

    (void)edx;

    if (xb_XLIVE_WORK_CLASS_Update(D_00798CAC) == -1) {
        xb_XLIVE_STAT_CLASS_CloseTasks(self);
        xb_XLIVE_WORK_CLASS_SetState4(D_00798CAC);
        return -1;
    }

    a.v = (s32)&st;

    switch (*(s32*)(self + 0x58)) {
    case 0:
        r = ((s32 (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_STAT_CLASS_ProcessResults)(self, a);
        break;
    case 1:
        r = ((s32 (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_STAT_CLASS_Step1)(self, a);
        break;
    case 2:
        r = ((s32 (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_STAT_CLASS_Step3)(self, a);
        break;
    case 3:
    case 4:
        r = ((s32 (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_STAT_CLASS_Step4)(self, a);
        break;
    case 5:
        r = ((s32 (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_STAT_CLASS_Step5)(self, a);
        break;
    case 6:
        r = ((s32 (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_STAT_CLASS_Step2)(self, a);
        break;
    default:
        _assert(D_0025CCA0, D_002B83E0, 0x3D8);
        break;
    }

    if (sub_0004AFFA() == 0 && xb_XLIVE_WORK_CLASS_Frame(D_00798CAC) == 0) {
        xb_XLIVE_STAT_CLASS_DrawPage(self);
    }

    xb_xlive_main_StepState(*(u8**)(self + 0x4A0));
    xb_WINSTR_CLASS_Update(*(u8**)(self + 0x4A0));
    *out = st;
    return r;
}
