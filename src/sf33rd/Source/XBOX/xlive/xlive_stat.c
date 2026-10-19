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
s32 XB_FASTCALL xb_XLIVE_STAT_CLASS_DrawPage0(u8* self);
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
void XB_FASTCALL xb_XLIVE_STAT_CLASS_DrawRanking(u8* self);

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
        xb_XLIVE_STAT_CLASS_DrawRanking(self);
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

void xb_xlive_disp_DrawMessageDefault(s32 col, s32 row, s32 text);
void xb_xlive_disp_DrawMessageRight(s32 col, s32 row, s32 text);
void xb_xlive_disp_DrawFocusBar(f32 x, f32 y, f32 w);
void XB_FASTCALL xb_XLIVE_STAT_CLASS_DrawHistory(u8* self);
extern f32 D_00219408;
extern f32 D_002B4D94;
extern f32 D_002190E8;

/* xb_XLIVE_STAT_CLASS_DrawPage0 0x1175E5: the stats menu (state 0) by its
 * page (+4): the menu with its focus bar (+0x5C), or the progress and
 * results of the stats query (+8) and its column (+0xC). */
s32 XB_FASTCALL xb_XLIVE_STAT_CLASS_DrawPage0(u8* self) {
    s32 c;

    switch (*(s32*)(self + 4)) {
    case 0:
        break;
    case 1:
        xb_xlive_disp_DrawMessageDefault(4, 0x16, 0);
        xb_xlive_disp_DrawFocusBar(D_00219408, D_002B4D94, (f32)*(s32*)(self + 0x5C) + D_002190E8);
        xb_xlive_disp_DrawMessageDefault(4, *(s32*)(self + 0x5C) + 0x18, 0);
        xb_xlive_disp_DrawMessageRight(4, 0x1E, 0);
        break;
    case 2:
        switch (*(s32*)(self + 8)) {
        case 0:
            xb_xlive_disp_DrawMessageDefault(4, 0, 0);
            break;
        case 1:
            xb_xlive_disp_DrawMessageDefault(4, 1, 0);
            c = *(s32*)(self + 0xC);

            if (c < 0) {
                break;
            }

            if (c <= 1) {
                xb_xlive_disp_DrawMessageDefault(4, 0xB, 0);
                xb_xlive_disp_DrawMessageRight(4, 0xC, 0);
            } else if (c == 2) {
                xb_xlive_disp_DrawMessageDefault(4, 0xD, 0);
            }

            break;
        case 2:
            xb_xlive_disp_DrawMessageDefault(4, 2, 0);
            c = *(s32*)(self + 0xC);

            if (c == 0) {
                xb_xlive_disp_DrawMessageDefault(4, 3, 0);
            } else if (c > 0) {
                if (c <= 2) {
                    xb_xlive_disp_DrawMessageDefault(4, 0xB, 0);
                    xb_xlive_disp_DrawMessageDefault(4, 0xC, 0);
                } else if (c == 3) {
                    xb_xlive_disp_DrawMessageDefault(4, 0xD, 0);
                }
            }

            break;
        case 3:
        case 4:
        case 5:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
            break;
        case 6:
            c = *(s32*)(self + 0xC);

            if (c < 0) {
                _assert(D_0025CCA0, D_002B83E0, 0x45B);
            } else if (c > 1) {
                if (c <= 3) {
                    xb_XLIVE_STAT_CLASS_DrawRanking(self);
                } else if (c == 4) {
                    xb_xlive_disp_DrawMessageDefault(4, 8, 0);

                    if (*(s32*)(self + 0x58) == 3) {
                        xb_xlive_disp_DrawMessageRight(4, 0x10, 0);
                    } else {
                        xb_xlive_disp_DrawMessageRight(4, 0x11, 0);
                    }
                } else {
                    _assert(D_0025CCA0, D_002B83E0, 0x45B);
                }
            }

            break;
        case 16:
            c = *(s32*)(self + 0xC);

            if (c < 0) {
                _assert(D_0025CCA0, D_002B83E0, 0x465);
            } else if (c > 1) {
                if (c <= 3) {
                    xb_XLIVE_STAT_CLASS_DrawRanking(self);
                } else if (c == 4) {
                    xb_XLIVE_STAT_CLASS_DrawHistory(self);
                } else {
                    _assert(D_0025CCA0, D_002B83E0, 0x465);
                }
            }

            break;
        default:
            _assert(D_0025CCA0, D_002B83E0, 0x46C);
            break;
        }

        break;
    case 3:
        break;
    default:
        _assert(D_0025CCA0, D_002B83E0, 0x470);
        break;
    }

    return 0;
}

u32 XB_FASTCALL xb_LiveObj_Count(u8* self);
u8* XB_FASTCALL xb_deque_LiveObj_Subscript(u8* self, s32 edx, u32 i);
u8* XB_FASTCALL xb_XLIVE_FRIEND_CLASS_GetFriendList(u8* self);
u8 XB_FASTCALL std__vector_Elem60__empty(void* self);
void xb_xlive_disp_DrawRectI(s32 font, f32 x, f32 y, f32 s, s32 text, f32 size, s32 flags, s32 c);
void XB_FASTCALL xb_XLIVE_STAT_CLASS_DrawHeaders(u8* self);
void XB_FASTCALL sub_0011615C(u8* self, s32 edx, s32 a);
void XB_FASTCALL sub_00116246(u8* self, s32 edx, u8* item, s32 y, u32 i);
void XB_FASTCALL xb_XLIVE_STAT_CLASS_DrawRowBar(u8* self, s32 edx, s32 y, u32 i);
extern f32 D_0025F370;
extern char D_00799418[];
extern char D_0041600C[];

/* The window a stats page draws its hints on: the details window (+0x44C)
 * in states 3 and 4, none otherwise. */
#define XB_STAT_WINDOW(self) (*(s32*)((self) + 0x58) == 3 || *(s32*)((self) + 0x58) == 4 ? *(s32*)((self) + 0x44C) : -1)

/* A row inside the 14 shown from the top (+0x410). */
#define XB_STAT_SHOWN(r) ((r) >= 0 && (r) < 14)

/* xb_XLIVE_STAT_CLASS_DrawRanking 0x117261: the ranking list (+0x250):
 * its scroll hint, by where the cursor (+0x64) and this player (+0x6C,
 * states 3 and 4) are against the rows shown, and its rows from the top
 * (+0x410). An empty friend list, an empty ranking or a query error (+0x294)
 * shows its message instead. */
void XB_FASTCALL xb_XLIVE_STAT_CLASS_DrawRanking(u8* self) {
    s32 st = *(s32*)(self + 0x58);
    s32 id = XB_STAT_WINDOW(self);
    s32 top;
    s32 own;
    s32 sel;
    s32 r;
    u32 i;
    s32 y;
    XB_ARG a;
    XB_ARG b;
    XB_ARG c;
    XB_ARG d;

    if (*(s32*)(self + 0x420) != 0 &&
        std__vector_Elem60__empty(xb_XLIVE_FRIEND_CLASS_GetFriendList(D_00798CAC + 0x25D0))) {
        xb_xlive_disp_DrawCellLeft(*(s32*)(self + 0x44C), 4, 5, 0);
        xb_xlive_disp_DrawCellRight(id, 4, 0xE, 0);
        return;
    }

    if ((st == 3 || st == 4) && *(s32*)(self + 0x294) != 0) {
        xb_xlive_disp_DrawCellLeft(*(s32*)(self + 0x44C), 4, 7, 0);
        xb_xlive_disp_DrawCellRight(id, 4, 0xE, 0);
        return;
    }

    if (xb_LiveObj_Count(self + 0x250) == 0) {
        xb_xlive_disp_DrawCellLeft(*(s32*)(self + 0x44C), 4, 4, 0);
        xb_xlive_disp_DrawCellRight(id, 4, 0xE, 0);
        return;
    }

    top = *(s32*)(self + 0x410);
    sel = *(s32*)(self + 0x64) - top;

    if (*(s32*)(self + 0x420) != 0) {
        r = XB_STAT_SHOWN(sel) ? 0xE : 0x12;
    } else {
        own = st == 3 || st == 4 ? *(s32*)(self + 0x6C) - top : -top;

        if (!XB_STAT_SHOWN(own) && !XB_STAT_SHOWN(sel)) {
            r = st == 3 ? 0x14 : st == 4 ? 0x15 : 0x13;
        } else if (!XB_STAT_SHOWN(own)) {
            r = st == 3 ? 0x10 : st == 4 ? 0x11 : 0xF;
        } else {
            r = XB_STAT_SHOWN(sel) ? 0xE : 0x12;
        }
    }

    xb_xlive_disp_DrawCellRight(id, 4, r, 0);
    xb_XLIVE_STAT_CLASS_DrawHeaders(self);
    a.v = 0;
    ((void (XB_FASTCALL*)(u8*, XB_ARG))sub_0011615C)(self, a);
    *(s32*)(self + 0x60) = (*(s32*)(self + 0x60) + 1) & 7;

    for (i = top, y = 0x68; i < xb_LiveObj_Count(self + 0x250) && y < 0x180; i++, y += 0x14) {
        a.v = i;
        b.v = (s32)((u8* (XB_FASTCALL*)(u8*, XB_ARG))xb_deque_LiveObj_Subscript)(self + 0x250, a);
        c.v = y;
        d.v = i;
        ((void (XB_FASTCALL*)(u8*, XB_ARG, XB_ARG, XB_ARG))sub_00116246)(self, b, c, d);
    }
}

/* xb_XLIVE_STAT_CLASS_DrawHistory 0x117440: the recent players list
 * (+0x264), its rows, and the empty rows after it. A query error (+0x294)
 * or an empty ranking shows its message instead. */
void XB_FASTCALL xb_XLIVE_STAT_CLASS_DrawHistory(u8* self) {
    s32 id = XB_STAT_WINDOW(self);
    u8* q;
    u32 i;
    s32 y;
    s32 k;
    XB_ARG a;
    XB_ARG b;
    XB_ARG c;
    XB_ARG d;

    if (*(s32*)(self + 0x294) != 0) {
        xb_xlive_disp_DrawCellLeft(id, 4, 8, 0);
        xb_xlive_disp_DrawCellRight(id, 4, 0xF, 0);
        return;
    }

    if (xb_LiveObj_Count(self + 0x250) == 0) {
        xb_xlive_disp_DrawCellLeft(id, 4, 4, 0);
        xb_xlive_disp_DrawCellRight(id, 4, 0xF, 0);
        return;
    }

    xb_xlive_disp_DrawCellRight(id, 4, 0xF, 0);
    xb_XLIVE_STAT_CLASS_DrawHeaders(self);
    *(s32*)(self + 0x60) = (*(s32*)(self + 0x60) + 1) & 7;
    q = self + 0x264;

    for (i = 0, y = 0x68; i < xb_LiveObj_Count(q); i++, y += 0x14) {
        a.v = i;
        b.v = (s32)((u8* (XB_FASTCALL*)(u8*, XB_ARG))xb_deque_LiveObj_Subscript)(q, a);
        c.v = y;
        d.v = i;
        ((void (XB_FASTCALL*)(u8*, XB_ARG, XB_ARG, XB_ARG))sub_00116246)(self, b, c, d);
    }

    if (xb_LiveObj_Count(q) < 14) {
        xb_xlive_disp_DrawRectI(id, 0.0f, (f32)(u32)(xb_LiveObj_Count(q) * 20 + 0x68), D_0025F370, (s32)D_00799418, 1.0f, 0, 0);
        return;
    }

    for (k = 0; xb_LiveObj_Count(q) + k < 14; k++) {
        y = (xb_LiveObj_Count(q) + k) * 20 + 0x68;
        xb_xlive_disp_DrawRectI(id, 0.0f, (f32)y, D_0025F370, (s32)D_0041600C, 1.0f, 0, 0);
        a.v = y;
        b.v = xb_LiveObj_Count(q) + k;
        ((void (XB_FASTCALL*)(u8*, XB_ARG, XB_ARG))xb_XLIVE_STAT_CLASS_DrawRowBar)(self, a, b);
    }
}

void xb_xlive_disp_DrawTextF(s32 id, s32 x, s32 y, f32 s, s32 flags, const char* fmt, ...);
void xb_DrawFramedQuad(f32 x0, f32 y0, f32 x1, f32 y1, f32 z, u32 col);
extern char* D_007990AC;
extern char* D_00799314;
extern char* D_00799184;
extern char* D_007992AC;
extern char* D_00799398;
extern char* D_00799390;
extern char* D_00799128;
extern char* D_0079930C;
extern f32 D_002B8450;
extern f32 D_002B4A34;
extern f32 D_002B4BEC;

/* xb_XLIVE_STAT_CLASS_DrawHeaders 0x1157A6: the column headings of the
 * stats lists. */
void XB_FASTCALL xb_XLIVE_STAT_CLASS_DrawHeaders(u8* self) {
    s32 id = XB_STAT_WINDOW(self);

    xb_xlive_disp_DrawTextF(id, 0x22, 0x45, D_0025F370, 5, D_007990AC);
    xb_xlive_disp_DrawTextF(id, 0x5A, 0x45, D_0025F370, 0, D_00799314);
    xb_xlive_disp_DrawTextF(id, 0x128, 0x45, D_0025F370, 5, D_00799184);
    xb_xlive_disp_DrawTextF(id, 0x176, 0x45, D_0025F370, 0, D_007992AC);
    xb_xlive_disp_DrawTextF(id, 0x18A, 0x45, D_0025F370, 5, D_00799398);
    xb_xlive_disp_DrawTextF(id, 0x1D0, 0x45, D_0025F370, 0, D_00799390);
    xb_xlive_disp_DrawTextF(id, 0x1DE, 0x45, D_0025F370, 5, D_00799128);
    xb_xlive_disp_DrawTextF(id, 0x22C, 0x45, D_0025F370, 0, D_0079930C);
}

/* xb_XLIVE_STAT_CLASS_DrawRowBar 0x1158C8: a list row's bar, its shade
 * alternating with the row. A stats method; the page is not used. */
void XB_FASTCALL xb_XLIVE_STAT_CLASS_DrawRowBar(u8* self, s32 edx, s32 y, u32 i) {
    (void)self;
    (void)edx;
    xb_DrawFramedQuad(D_002B4BEC, (f32)y, D_002B4A34, (f32)(y + 0x14), D_002B8450,
                      (s32)i % 2 != 0 ? 0xFF202020 : 0xFF404040);
}
