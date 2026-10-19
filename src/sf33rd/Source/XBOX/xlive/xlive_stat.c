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
void XB_FASTCALL xb_XLIVE_STAT_CLASS_DrawScroll(u8* self, s32 edx, s32 a);
void XB_FASTCALL xb_XLIVE_STAT_CLASS_DrawRow(u8* self, s32 edx, u8* item, s32 y, u32 i);
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
    ((void (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_STAT_CLASS_DrawScroll)(self, a);
    *(s32*)(self + 0x60) = (*(s32*)(self + 0x60) + 1) & 7;

    for (i = top, y = 0x68; i < xb_LiveObj_Count(self + 0x250) && y < 0x180; i++, y += 0x14) {
        a.v = i;
        b.v = (s32)((u8* (XB_FASTCALL*)(u8*, XB_ARG))xb_deque_LiveObj_Subscript)(self + 0x250, a);
        c.v = y;
        d.v = i;
        ((void (XB_FASTCALL*)(u8*, XB_ARG, XB_ARG, XB_ARG))xb_XLIVE_STAT_CLASS_DrawRow)(self, b, c, d);
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
        ((void (XB_FASTCALL*)(u8*, XB_ARG, XB_ARG, XB_ARG))xb_XLIVE_STAT_CLASS_DrawRow)(self, b, c, d);
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

void xb_xlive_disp_DrawRectI1(s32 font, f32 x, f32 y, f32 s, s32 text, f32 size, s32 flags);
extern char* D_007991F4;
extern char* D_0079931C;
extern f32 D_002B85F0;
extern f32 D_002B85F4;
extern f32 D_002497E8;
extern f32 D_002B4BE4;

/* xb_XLIVE_STAT_CLASS_DrawScroll 0x11615C: the scroll arrows of the
 * ranking (0) or recent players (1) list: up when not at the top, down
 * when rows follow the 14 shown. */
void XB_FASTCALL xb_XLIVE_STAT_CLASS_DrawScroll(u8* self, s32 edx, s32 list) {
    u32 n = 0;
    s32 id;

    (void)edx;

    switch (list) {
    case 0:
        n = xb_LiveObj_Count(self + 0x250);
        break;
    case 1:
        n = xb_LiveObj_Count(self + 0x264);
        break;
    default:
        _assert(D_0025CCA0, D_002B83E0, 0x2E1);
        break;
    }

    id = XB_STAT_WINDOW(self);

    if (*(s32*)(self + 0x410) != 0) {
        xb_xlive_disp_DrawRectI1(id, D_002B85F0, D_002B85F4, D_0025F370, (s32)D_007991F4, D_002B4BE4, 5);
    }

    if ((u32)(*(s32*)(self + 0x410) + 14) < n) {
        xb_xlive_disp_DrawRectI1(id, D_002B85F0, D_002497E8, D_0025F370, (s32)D_0079931C, D_002B4BE4, 5);
    }
}

int sprintf(char* buf, const char* fmt, ...);
u32 wcstombs(char* dst, const u16* src, u32 n);
s32 XB_FASTCALL xb_xlive_stat_GetWins(XB_XSTAT* self);
s32 XB_FASTCALL xb_xlive_stat_GetMatches(XB_XSTAT* self);
s32 XB_FASTCALL xb_xlive_stat_GetGrade(XB_XSTAT* self);
s32 XB_FASTCALL xb_xlive_stat_GetPoint(XB_XSTAT* self);
s32 XB_FASTCALL xb_xlive_stat_GetRegion(XB_XSTAT* self);
extern char* D_00418868[];
extern s32 D_004188C8[];
extern s32 D_004188E8[];
extern char D_0023ABE8[];
extern char D_002B8608[];
extern char D_002B8604[];
extern char D_002B85FC[];
extern char D_002B85F8[];
extern f32 D_002B8600;

/* xb_XLIVE_STAT_CLASS_GradeName 0x115B3B: a grade's letters. */
char* XB_FASTCALL xb_XLIVE_STAT_CLASS_GradeName(u8* self, s32 edx, s32 grade) {
    (void)self;
    (void)edx;
    return D_00418868[grade];
}

/* xb_XLIVE_STAT_CLASS_DrawRow 0x116246: one list row: rank (at most 999),
 * gamertag (coloured for the cursor's player, +0x298, by the blink +0x68,
 * and for this player, +0x2A4, in states 3 and 4), points, grade (the top
 * grades 17 to 19 cycle colours, +0x60, and 18 and 19 get a shadow), wins,
 * matches (each at most 99999) and language. */
void XB_FASTCALL xb_XLIVE_STAT_CLASS_DrawRow(u8* self, s32 edx, u8* item, s32 y, u32 i) {
    char buf[0x100];
    XB_XSTAT* st;
    s32 col;
    s32 grade;
    s32 c2;
    XB_ARG a;
    XB_ARG b;

    (void)edx;
    a.v = y;
    b.v = i;
    ((void (XB_FASTCALL*)(u8*, XB_ARG, XB_ARG))xb_XLIVE_STAT_CLASS_DrawRowBar)(self, a, b);
    st = (XB_XSTAT*)(item + 0x30);
    y++;
    sprintf(buf, D_0023ABE8, xb_xlive_stat_GetRank(st) > 999 ? 999 : xb_xlive_stat_GetRank(st));
    xb_xlive_disp_DrawTextF(*(s32*)(self + 0x44C), 0x1E, y, D_0025F370, 5, buf);
    col = 0;

    if (*(u32*)item == *(u32*)(self + 0x298) && *(u32*)(item + 4) == *(u32*)(self + 0x29C)) {
        if (*(s32*)(self + 0x68) != 0) {
            col = D_004188E8[*(s32*)(self + 0x68) & 3];
        } else {
            col = 2;
        }
    }

    if ((*(s32*)(self + 0x58) == 3 || *(s32*)(self + 0x58) == 4) && *(u32*)item == *(u32*)(self + 0x2A4) &&
        *(u32*)(item + 4) == *(u32*)(self + 0x2A8)) {
        col = 3;
    }

    wcstombs(buf, (u16*)(item + 0x10), 0x10);
    xb_xlive_disp_DrawTextF(*(s32*)(self + 0x44C), 0x56, y, D_0025F370, col, buf);
    sprintf(buf, D_002B8608, xb_xlive_stat_GetPoint(st) > 99999 ? 99999 : xb_xlive_stat_GetPoint(st));
    xb_xlive_disp_DrawTextF(*(s32*)(self + 0x44C), 0x128, y, D_0025F370, 5, buf);
    grade = xb_xlive_stat_GetGrade(st);
    a.v = grade;
    sprintf(buf, D_002B8604, ((char* (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_STAT_CLASS_GradeName)(self, a));

    switch (grade) {
    case 0x11:
        xb_xlive_disp_DrawTextF(*(s32*)(self + 0x44C), 0x170, y, D_0025F370, D_004188C8[*(s32*)(self + 0x60)], buf);
        break;
    case 0x12:
    case 0x13:
        c2 = (*(s32*)(self + 0x60) + 2) & 7;
        xb_xlive_disp_DrawTextF(*(s32*)(self + 0x44C), 0x170, y, D_0025F370, D_004188C8[*(s32*)(self + 0x60)], buf);
        xb_xlive_disp_DrawTextF(*(s32*)(self + 0x44C), 0x174, y + 4, D_002B8600, D_004188C8[c2], buf);
        break;
    default:
        xb_xlive_disp_DrawTextF(*(s32*)(self + 0x44C), 0x16E, y, D_0025F370, 0, buf);
        break;
    }

    sprintf(buf, D_002B8608, xb_xlive_stat_GetWins(st) > 99999 ? 99999 : xb_xlive_stat_GetWins(st));
    xb_xlive_disp_DrawTextF(*(s32*)(self + 0x44C), 0x18A, y, D_0025F370, 5, buf);
    xb_xlive_disp_DrawTextF(*(s32*)(self + 0x44C), 0x1D0, y, D_0025F370, 0, D_00799390);
    sprintf(buf, D_002B85FC, xb_xlive_stat_GetMatches(st) > 99999 ? 99999 : xb_xlive_stat_GetMatches(st));
    xb_xlive_disp_DrawTextF(*(s32*)(self + 0x44C), 0x1DE, y, D_0025F370, 5, buf);
    a.v = xb_xlive_stat_GetRegion(st);
    sprintf(buf, D_002B85F8, ((char* (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_STAT_CLASS_LangName)(self, a));
    xb_xlive_disp_DrawTextF(*(s32*)(self + 0x44C), 0x232, y, D_0025F370, 0, buf);
}

void XB_FASTCALL xb_xlive_stat_SetWins(XB_XSTAT* self, s32 edx, s32 v);
void XB_FASTCALL xb_xlive_stat_SetMatches(XB_XSTAT* self, s32 edx, s32 v);
void XB_FASTCALL xb_xlive_stat_SetGrade(XB_XSTAT* self, s32 edx, s32 v);
void XB_FASTCALL xb_xlive_stat_SetPoint(XB_XSTAT* self, s32 edx, s32 v);
void XB_FASTCALL xb_xlive_stat_SetRegion(XB_XSTAT* self, s32 edx, s32 v);
void XB_FASTCALL xb_xlive_stat_SetRating(XB_XSTAT* self, s32 edx, s32 lo, s32 hi);

/* xb_xlive_stat_Reset 0x11681F: a new player's stats: all zero, this
 * console's language, and the rank stat (id 0xFFFF) zero. */
void XB_FASTCALL xb_xlive_stat_Reset(XB_XSTAT* self) {
    XB_ARG a;
    XB_ARG b;

    a.v = 0;
    ((void (XB_FASTCALL*)(XB_XSTAT*, XB_ARG))xb_xlive_stat_SetWins)(self, a);
    ((void (XB_FASTCALL*)(XB_XSTAT*, XB_ARG))xb_xlive_stat_SetMatches)(self, a);
    ((void (XB_FASTCALL*)(XB_XSTAT*, XB_ARG))xb_xlive_stat_SetGrade)(self, a);
    ((void (XB_FASTCALL*)(XB_XSTAT*, XB_ARG))xb_xlive_stat_SetPoint)(self, a);
    a.v = XGetLanguage();
    ((void (XB_FASTCALL*)(XB_XSTAT*, XB_ARG))xb_xlive_stat_SetRegion)(self, a);
    a.v = 0;
    b.v = 0;
    ((void (XB_FASTCALL*)(XB_XSTAT*, XB_ARG, XB_ARG))xb_xlive_stat_SetRating)(self, a, b);
    self[6].id = 0xFFFF;
    self[6].lo = 0;
    self[6].type = 1;
}

/* The stats pages' query steps share a shape: page +4 counts 0 (start the
 * user count search), 1 (set the query up), 2 (run it,
 * xb_XLIVE_STAT_CLASS_Dispatch). */
typedef struct {
    XB_XSTAT s[7];
} XB_XSTAT7;
s32 XB_FASTCALL xb_XLIVE_STAT_CLASS_Dispatch(u8* self, s32 edx, s32* st);
s32 XB_FASTCALL xb_CONNECT_USER_CLASS_IsTaskDone(u8* self);
s32 xb_xlive_main_SetErrorArgs(s32 hr, const char* file, s32 line, s32 fatal);

#define XB_STAT_DISPATCH(self, st) (a.v = (s32)&(st), ((s32 (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_STAT_CLASS_Dispatch)((self), a))

/* xb_XLIVE_STAT_CLASS_Step2 0x11A7ED: the query of kind 9. */
s32 XB_FASTCALL xb_XLIVE_STAT_CLASS_Step2(u8* self, s32 edx, s32* out) {
    s32 st = 0;
    s32 r;
    XB_ARG a;

    (void)edx;

    switch (*(s32*)(self + 4)) {
    case 0:
        *(s32*)(self + 4) = 1;
        xb_CONNECT_USER_CLASS_IsTaskDone(D_00798CAC + 0x59E0);
    case 1:
        (*(s32*)(self + 4))++;
        *(s32*)(self + 8) = 9;
        *(s32*)(self + 0xC) = 0;
    case 2:
        r = XB_STAT_DISPATCH(self, st);
        break;
    default:
        _assert(D_0025CCA0, D_002B83E0, 0x5F7);
        xb_xlive_main_SetErrorArgs(7, D_002B83E0, 0x5F9, 1);
        xb_XLIVE_STAT_CLASS_CloseTasks(self);
        r = -1;
        break;
    }

    *out = st;
    return r;
}

/* xb_XLIVE_STAT_CLASS_Step3 0x11A878: this player's stats (kind 10, 17
 * stats); once read they are kept (+0x170 to +0x2C0). */
s32 XB_FASTCALL xb_XLIVE_STAT_CLASS_Step3(u8* self, s32 edx, s32* out) {
    s32 st = 0;
    s32 r = 0;
    XB_ARG a;

    (void)edx;

    switch (*(s32*)(self + 4)) {
    case 0:
        *(s32*)(self + 4) = 1;
        xb_CONNECT_USER_CLASS_IsTaskDone(D_00798CAC + 0x59E0);
    case 1:
        (*(s32*)(self + 4))++;
        *(s32*)(self + 8) = 0xA;
        *(s32*)(self + 0xC) = 0;
        *(s32*)(self + 0x290) = 0x11;
        break;
    case 2:
        r = XB_STAT_DISPATCH(self, st);

        if (r == 1) {
            *(XB_XSTAT7*)(self + 0x2C0) = *(XB_XSTAT7*)(self + 0x170);
        }

        break;
    default:
        _assert(D_0025CCA0, D_002B83E0, 0x623);
        xb_xlive_main_SetErrorArgs(7, D_002B83E0, 0x625, 1);
        xb_XLIVE_STAT_CLASS_CloseTasks(self);
        r = -1;
        break;
    }

    *out = st;
    return r;
}

/* xb_XLIVE_STAT_CLASS_Step4 0x11A92B: the leaderboard around this player
 * (kind 5, 6 stats, 100 rows, from the user +0x2A4 and page +0x54). */
s32 XB_FASTCALL xb_XLIVE_STAT_CLASS_Step4(u8* self, s32 edx, s32* out) {
    s32 st = 0;
    s32 r;
    XB_ARG a;

    (void)edx;

    switch (*(s32*)(self + 4)) {
    case 0:
        *(s32*)(self + 4) = 1;
        xb_CONNECT_USER_CLASS_IsTaskDone(D_00798CAC + 0x59E0);
    case 1:
        (*(s32*)(self + 4))++;
        *(u8**)(self + 0x288) = self + 0x2A4;
        *(s32*)(self + 8) = 5;
        *(s32*)(self + 0xC) = 0;
        *(s32*)(self + 0x290) = 6;
        *(s32*)(self + 0x28C) = (*(s32*)(self + 0x54) + 1) * 3;
        *(s32*)(self + 0x420) = 0;
        *(s32*)(self + 0x424) = 0x64;
        *(s32*)(self + 0x428) = 0;
    case 2:
        r = XB_STAT_DISPATCH(self, st);
        break;
    default:
        _assert(D_0025CCA0, D_002B83E0, 0x64D);
        xb_xlive_main_SetErrorArgs(7, D_002B83E0, 0x64F, 1);
        xb_XLIVE_STAT_CLASS_CloseTasks(self);
        r = -1;
        break;
    }

    *out = st;
    return r;
}

/* xb_XLIVE_STAT_CLASS_Step5 0x11A9F3: this player's stats again (kind 11),
 * kept once read; a player without stats gets new ones. */
s32 XB_FASTCALL xb_XLIVE_STAT_CLASS_Step5(u8* self, s32 edx, s32* out) {
    s32 st = 0;
    s32 r;
    XB_ARG a;

    (void)edx;

    switch (*(s32*)(self + 4)) {
    case 0:
        *(s32*)(self + 4) = 1;
        xb_CONNECT_USER_CLASS_IsTaskDone(D_00798CAC + 0x59E0);
    case 1:
        (*(s32*)(self + 4))++;
        *(s32*)(self + 8) = 0xB;
        *(s32*)(self + 0xC) = 0;
        *(s32*)(self + 0x290) = 0x11;
    case 2:
        r = XB_STAT_DISPATCH(self, st);

        if (r == 1) {
            *(XB_XSTAT7*)(self + 0x2C0) = *(XB_XSTAT7*)(self + 0x170);

            if (xb_xlive_stat_IsUnset((XB_XSTAT*)(self + 0x2C0))) {
                xb_xlive_stat_Reset((XB_XSTAT*)(self + 0x2C0));
            }
        }

        break;
    default:
        _assert(D_0025CCA0, D_002B83E0, 0x67C);
        xb_xlive_main_SetErrorArgs(7, D_002B83E0, 0x67E, 1);
        xb_XLIVE_STAT_CLASS_CloseTasks(self);
        r = -1;
        break;
    }

    *out = st;
    return r;
}

/* The stats queries by kind (+8, 3 to 16), each a step of the query
 * that returns 1 when done, 0 while it runs and -1 on an error. */
s32 XB_FASTCALL xb_XLIVE_STAT_CLASS_Update(u8* self, s32 edx, s32* st);
s32 XB_FASTCALL xb_XLIVE_STAT_CLASS_Kind4(u8* self, s32 edx, s32* st);
s32 XB_FASTCALL sub_00119116(u8* self, s32 edx, s32* st);
s32 XB_FASTCALL xb_XLIVE_STAT_CLASS_Kind6(u8* self, s32 edx, s32* st);
s32 XB_FASTCALL xb_XLIVE_STAT_CLASS_Kind7(u8* self, s32 edx, s32* st);
s32 XB_FASTCALL xb_XLIVE_STAT_CLASS_Kind8(u8* self, s32 edx, s32* st);
s32 XB_FASTCALL xb_XLIVE_STAT_CLASS_Kind9(u8* self, s32 edx, s32* st);
s32 XB_FASTCALL xb_XLIVE_STAT_CLASS_Kind10(u8* self, s32 edx, s32* st);
s32 XB_FASTCALL xb_XLIVE_STAT_CLASS_Kind11(u8* self, s32 edx, s32* st);
s32 XB_FASTCALL xb_XLIVE_STAT_CLASS_Kind12(u8* self, s32 edx, s32* st);
s32 XB_FASTCALL xb_XLIVE_STAT_CLASS_Kind13(u8* self, s32 edx, s32* st);
s32 XB_FASTCALL xb_XLIVE_STAT_CLASS_Kind14(u8* self, s32 edx, s32* st);
s32 XB_FASTCALL xb_XLIVE_STAT_CLASS_Kind15(u8* self, s32 edx, s32* st);
s32 XB_FASTCALL xb_XLIVE_STAT_CLASS_Kind16(u8* self, s32 edx, s32* st);

#define XB_STAT_KIND(f) (r = ((s32 (XB_FASTCALL*)(u8*, XB_ARG))(f))(self, a))

/* xb_XLIVE_STAT_CLASS_Dispatch 0x11A199: one step of the query of the
 * page's kind. */
s32 XB_FASTCALL xb_XLIVE_STAT_CLASS_Dispatch(u8* self, s32 edx, s32* out) {
    s32 st = 0;
    s32 r = 0;
    XB_ARG a;

    (void)edx;
    a.v = (s32)&st;

    switch (*(s32*)(self + 8)) {
    case 3:
        XB_STAT_KIND(xb_XLIVE_STAT_CLASS_Update);
        break;
    case 4:
        XB_STAT_KIND(xb_XLIVE_STAT_CLASS_Kind4);
        break;
    case 5:
        XB_STAT_KIND(sub_00119116);
        break;
    case 6:
        XB_STAT_KIND(xb_XLIVE_STAT_CLASS_Kind6);
        break;
    case 7:
        XB_STAT_KIND(xb_XLIVE_STAT_CLASS_Kind7);
        break;
    case 8:
        XB_STAT_KIND(xb_XLIVE_STAT_CLASS_Kind8);
        break;
    case 9:
        XB_STAT_KIND(xb_XLIVE_STAT_CLASS_Kind9);
        break;
    case 10:
        XB_STAT_KIND(xb_XLIVE_STAT_CLASS_Kind10);
        break;
    case 11:
        XB_STAT_KIND(xb_XLIVE_STAT_CLASS_Kind11);
        break;
    case 12:
        XB_STAT_KIND(xb_XLIVE_STAT_CLASS_Kind12);
        break;
    case 13:
        XB_STAT_KIND(xb_XLIVE_STAT_CLASS_Kind13);
        break;
    case 14:
        XB_STAT_KIND(xb_XLIVE_STAT_CLASS_Kind14);
        break;
    case 15:
        XB_STAT_KIND(xb_XLIVE_STAT_CLASS_Kind15);
        break;
    case 16:
        XB_STAT_KIND(xb_XLIVE_STAT_CLASS_Kind16);
        break;
    default:
        _assert(D_0025CCA0, D_002B83E0, 0x6A4);
        break;
    }

    *out = st;
    return r;
}

u8* XB_FASTCALL xb_vector_StatRow_Subscript(u8* self, s32 edx, u32 i);

#define XB_STAT_ROW(i) (a.v = (i), ((u8* (XB_FASTCALL*)(u8*, XB_ARG))xb_vector_StatRow_Subscript)(self + 0x278, a))

/* xb_XLIVE_STAT_CLASS_Step1 0x11A673: the four players' stats (kind 8, 17
 * stats): this player's (+0x330, new ones if none) and three more (+0x90,
 * +0x100, +0x170), then the leaderboard (kind 4). */
s32 XB_FASTCALL xb_XLIVE_STAT_CLASS_Step1(u8* self, s32 edx, s32* out) {
    s32 st = 0;
    s32 r;
    XB_ARG a;

    (void)edx;

    switch (*(s32*)(self + 4)) {
    case 0:
        *(s32*)(self + 4) = 1;
        xb_CONNECT_USER_CLASS_IsTaskDone(D_00798CAC + 0x59E0);
    case 1:
        (*(s32*)(self + 4))++;
        *(s32*)(self + 8) = 8;
        *(s32*)(self + 0xC) = 0;
        *(s32*)(self + 0x290) = 0x11;
    case 2:
        r = XB_STAT_DISPATCH(self, st);

        if (r == -1 || r == 0) {
            break;
        }

        if (r != 1) {
            _assert(D_0025CCA0, D_002B83E0, 0x5C2);
            xb_xlive_main_SetErrorArgs(7, D_002B83E0, 0x5C4, 1);
            xb_XLIVE_STAT_CLASS_CloseTasks(self);
            r = -1;
            break;
        }

        *(XB_XSTAT7*)(self + 0x330) = *(XB_XSTAT7*)(XB_STAT_ROW(0) + 0x10);

        if (xb_xlive_stat_IsUnset((XB_XSTAT*)(self + 0x330))) {
            xb_xlive_stat_Reset((XB_XSTAT*)(self + 0x330));
        }

        *(XB_XSTAT7*)(self + 0x90) = *(XB_XSTAT7*)(XB_STAT_ROW(1) + 0x10);
        *(XB_XSTAT7*)(self + 0x100) = *(XB_XSTAT7*)(XB_STAT_ROW(2) + 0x10);
        *(XB_XSTAT7*)(self + 0x170) = *(XB_XSTAT7*)(XB_STAT_ROW(3) + 0x10);
        (*(s32*)(self + 4))++;
        *(s32*)(self + 8) = 4;
        *(s32*)(self + 0xC) = 0;
        r = 0;
        break;
    case 3:
        r = XB_STAT_DISPATCH(self, st);
        break;
    default:
        _assert(D_0025CCA0, D_002B83E0, 0x5D0);
        xb_xlive_main_SetErrorArgs(7, D_002B83E0, 0x5D2, 1);
        xb_XLIVE_STAT_CLASS_CloseTasks(self);
        r = -1;
        break;
    }

    *out = st;
    return r;
}

s32 XB_FASTCALL xb_XLIVE_STAT_CLASS_RequestUser(u8* self, s32 edx, u8* user);
s32 XB_FASTCALL xb_XLIVE_STAT_CLASS_RequestFriends(u8* self);
s32 XB_FASTCALL xb_XLIVE_STAT_CLASS_WriteStats(u8* self);

/* xb_XLIVE_STAT_CLASS_Kind7 0x119F51: the stats of the user +0x2B0 asked
 * for, then the wait (kind 3). */
s32 XB_FASTCALL xb_XLIVE_STAT_CLASS_Kind7(u8* self, s32 edx, s32* st) {
    s32 hr;
    XB_ARG a;

    (void)edx;
    a.v = (s32)(self + 0x2B0);
    hr = ((s32 (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_STAT_CLASS_RequestUser)(self, a);
    *st = hr;

    if (hr < 0) {
        return -1;
    }

    *(s32*)(self + 0xC) = 0;
    *(s32*)(self + 8) = 3;
    return 0;
}

/* xb_XLIVE_STAT_CLASS_Kind11 0x119F22: the same for the user +0x298. */
s32 XB_FASTCALL xb_XLIVE_STAT_CLASS_Kind11(u8* self, s32 edx, s32* st) {
    s32 hr;
    XB_ARG a;

    (void)edx;
    a.v = (s32)(self + 0x298);
    hr = ((s32 (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_STAT_CLASS_RequestUser)(self, a);
    *st = hr;

    if (hr < 0) {
        return -1;
    }

    *(s32*)(self + 0xC) = 0;
    *(s32*)(self + 8) = 3;
    return 0;
}

/* xb_XLIVE_STAT_CLASS_Kind13 0x119F80: 0, or -1 when the request fails. */
s32 XB_FASTCALL xb_XLIVE_STAT_CLASS_Kind13(u8* self, s32 edx, s32* st) {
    s32 hr;

    (void)edx;
    hr = xb_XLIVE_STAT_CLASS_RequestFriends(self);
    *st = hr;
    return (hr >= 0) - 1;
}

/* xb_XLIVE_STAT_CLASS_Kind15 0x1159E2: after a delay (+0x70) the friends'
 * leaderboard (kind 5, 16 stats, 14 rows, from the user +0x298). */
s32 XB_FASTCALL xb_XLIVE_STAT_CLASS_Kind15(u8* self, s32 edx, s32* st) {
    (void)edx;
    (void)st;

    if (*(s32*)(self + 0x70) == 0) {
        *(s32*)(self + 0xC) = 0;
        *(s32*)(self + 8) = 5;
        *(s32*)(self + 0x290) = 0x10;
        *(u8**)(self + 0x288) = self + 0x298;
        *(s32*)(self + 0x424) = 0xE;
        *(s32*)(self + 0x428) = 1;
    } else {
        (*(s32*)(self + 0x70))--;
    }

    return 0;
}

/* xb_XLIVE_STAT_CLASS_Kind9 0x11A0C0: a lost match written (+0x3A0: no
 * wins, matches less the penalty +0x418, grade 0, the language), then the
 * wait (kind 3, 4 stats). */
s32 XB_FASTCALL xb_XLIVE_STAT_CLASS_Kind9(u8* self, s32 edx, s32* st) {
    XB_XSTAT* s = (XB_XSTAT*)(self + 0x3A0);
    s32 hr;
    XB_ARG a;

    (void)edx;
    a.v = 0;
    ((void (XB_FASTCALL*)(XB_XSTAT*, XB_ARG))xb_xlive_stat_SetWins)(s, a);
    a.v = -*(s32*)(self + 0x418);
    ((void (XB_FASTCALL*)(XB_XSTAT*, XB_ARG))xb_xlive_stat_SetMatches)(s, a);
    a.v = 0;
    ((void (XB_FASTCALL*)(XB_XSTAT*, XB_ARG))xb_xlive_stat_SetGrade)(s, a);
    *(s32*)(self + 0x414) = 1;
    a.v = XGetLanguage();
    ((void (XB_FASTCALL*)(XB_XSTAT*, XB_ARG))xb_xlive_stat_SetRegion)(s, a);
    hr = xb_XLIVE_STAT_CLASS_WriteStats(self);
    *st = hr;

    if (hr < 0) {
        return -1;
    }

    *(s32*)(self + 0xC) = 0;
    *(s32*)(self + 8) = 3;
    *(s32*)(self + 0x290) = 4;
    return 0;
}

/* xb_XLIVE_STAT_CLASS_Kind10 0x11A133: a won match written (+0x3A0: the
 * wins +0x41C, no matches, the language), then the wait (kind 3, 4
 * stats). */
s32 XB_FASTCALL xb_XLIVE_STAT_CLASS_Kind10(u8* self, s32 edx, s32* st) {
    XB_XSTAT* s = (XB_XSTAT*)(self + 0x3A0);
    s32 hr;
    XB_ARG a;

    (void)edx;
    a.v = *(s32*)(self + 0x41C);
    ((void (XB_FASTCALL*)(XB_XSTAT*, XB_ARG))xb_xlive_stat_SetWins)(s, a);
    a.v = 0;
    ((void (XB_FASTCALL*)(XB_XSTAT*, XB_ARG))xb_xlive_stat_SetMatches)(s, a);
    *(s32*)(self + 0x414) = 0;
    a.v = XGetLanguage();
    ((void (XB_FASTCALL*)(XB_XSTAT*, XB_ARG))xb_xlive_stat_SetRegion)(s, a);
    hr = xb_XLIVE_STAT_CLASS_WriteStats(self);
    *st = hr;

    if (hr < 0) {
        return -1;
    }

    *(s32*)(self + 0xC) = 0;
    *(s32*)(self + 8) = 3;
    *(s32*)(self + 0x290) = 4;
    return 0;
}

/* xb_xlive_stat_GetStats6 0x115DD8: the record and its stats count (6). */
XB_XSTAT* XB_FASTCALL xb_xlive_stat_GetStats6(XB_XSTAT* self, s32 edx, u32* n) {
    (void)edx;
    *n = 6;
    return self;
}

/* xb_xlive_stat_GetStats7 0x115DE7: the record and its stats count (7). */
XB_XSTAT* XB_FASTCALL xb_xlive_stat_GetStats7(XB_XSTAT* self, s32 edx, u32* n) {
    (void)edx;
    *n = 7;
    return self;
}

typedef struct {
    u32 w[3];
} XB_PEER12;

/* A stats request entry (XONLINE_STAT_SPEC): the user, the leaderboard,
 * and its stats. */
typedef struct {
    u32 user[3];
    u32 board;
    u32 n;
    XB_XSTAT* stats;
} XB_STATSPEC;
void XB_FASTCALL xb_vector_StatSpec_Resize(u8* self, s32 edx, u32 n);
XB_STATSPEC* XB_FASTCALL xb_vector_StatSpec_Subscript(u8* self, s32 edx, u32 i);
s32 xb_xlive_StatRequest(u32 n, void* specs, s32 a, s32 b, void* task);
s32 XB_FASTCALL CXBOnlineTask_operator_addr(void* self);

#define XB_SPEC(i) (a.v = (i), ((XB_STATSPEC* (XB_FASTCALL*)(u8*, XB_ARG))xb_vector_StatSpec_Subscript)(self + 0x7C, a))

/* xb_XLIVE_STAT_CLASS_WriteStats 0x11994A: the match's result written for
 * the user (+0x298) on the page's three leaderboards (+0x54 * 3 + 1 to 3),
 * the records +0x90 to +0x170 reset first. */
s32 XB_FASTCALL xb_XLIVE_STAT_CLASS_WriteStats(u8* self) {
    XB_XSTAT* st;
    s32 i;
    s32 board;
    XB_XSTAT* p;
    u32 n;
    s32 hr;
    XB_ARG a;

    *(u8**)(self + 0x2BC) = self + 0x298;
    a.v = 3;
    ((void (XB_FASTCALL*)(u8*, XB_ARG))xb_vector_StatSpec_Resize)(self + 0x7C, a);

    for (i = 0, st = (XB_XSTAT*)(self + 0x90); i < 3; i++, st += 7) {
        xb_xlive_stat_Reset(st);
        *(XB_PEER12*)XB_SPEC(i)->user = **(XB_PEER12**)(self + 0x2BC);
        board = *(s32*)(self + 0x54) * 3 + i + 1;
        XB_SPEC(i)->board = board;
        a.v = (s32)&n;
        p = ((XB_XSTAT* (XB_FASTCALL*)(XB_XSTAT*, XB_ARG))xb_xlive_stat_GetStats7)(st, a);
        XB_SPEC(i)->stats = p;
        XB_SPEC(i)->n = n;
    }

    hr = xb_xlive_StatRequest(3, XB_SPEC(0), 0, 0, (void*)CXBOnlineTask_operator_addr(self + 0x434));

    if (hr < 0) {
        xb_xlive_main_SetErrorArgs(7, D_002B83E0, 0xB9F, 1);
        xb_XLIVE_STAT_CLASS_CloseTasks(self);
    }

    return hr;
}

/* xb_XLIVE_STAT_CLASS_RequestUser 0x119B61: as WriteStats, for a given
 * user. */
s32 XB_FASTCALL xb_XLIVE_STAT_CLASS_RequestUser(u8* self, s32 edx, u8* user) {
    XB_XSTAT* st;
    s32 i;
    s32 board;
    XB_XSTAT* p;
    u32 n;
    s32 hr;
    XB_ARG a;

    (void)edx;
    *(u8**)(self + 0x2BC) = user;
    a.v = 3;
    ((void (XB_FASTCALL*)(u8*, XB_ARG))xb_vector_StatSpec_Resize)(self + 0x7C, a);

    for (i = 0, st = (XB_XSTAT*)(self + 0x90); i < 3; i++, st += 7) {
        xb_xlive_stat_Reset(st);
        *(XB_PEER12*)XB_SPEC(i)->user = **(XB_PEER12**)(self + 0x2BC);
        board = *(s32*)(self + 0x54) * 3 + i + 1;
        XB_SPEC(i)->board = board;
        a.v = (s32)&n;
        p = ((XB_XSTAT* (XB_FASTCALL*)(XB_XSTAT*, XB_ARG))xb_xlive_stat_GetStats7)(st, a);
        XB_SPEC(i)->stats = p;
        XB_SPEC(i)->n = n;
    }

    hr = xb_xlive_StatRequest(3, XB_SPEC(0), 0, 0, (void*)CXBOnlineTask_operator_addr(self + 0x434));

    if (hr < 0) {
        xb_xlive_main_SetErrorArgs(7, D_002B83E0, 0xBE3, 1);
        xb_XLIVE_STAT_CLASS_CloseTasks(self);
    }

    return hr;
}

void XB_FASTCALL xb_deque_LiveObj_Clear(u8* self);
void XB_FASTCALL xb_vector_StatSpec_Clear(u8* self);
void XB_FASTCALL xb_deque_LiveObj_PushBack(u8* self, s32 edx, u8* rec);
u8* XB_FASTCALL xb_XLIVE_FRIEND_CLASS_FriendAt(u8* self, s32 edx, u32 i);
u8* XB_FASTCALL xb_vector_XONLINE_USER_Subscript(void* self, s32 edx, u32 i);
u32 XB_FASTCALL std__vector_Elem18__size(void* self);
u32 XB_FASTCALL std__vector_Elem60__size(void* self);
u8* XB_FASTCALL xb_XLIVE_PLAYER_ctor(u8* self);
void XBUtil_GetWide(const char* s, u16* out, s32 n);

#define XB_FRIEND(i) (a.v = (i), ((u8* (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_FRIEND_CLASS_FriendAt)(list, a))
#define XB_ME() (a.v = *(s32*)(D_00798CAC + 0x10), ((u8* (XB_FASTCALL*)(u8*, XB_ARG))xb_vector_XONLINE_USER_Subscript)(D_00798CAC + 0x18, a))

/* xb_XLIVE_STAT_CLASS_RequestFriends 0x119C47: the friends' leaderboard
 * (+0x28C): up to 99 friends and this user made the page's players
 * (+0x250) and their stats asked for; then the wait (kind 3, 14 stats).
 * With no friends the page goes to kind 14. */
s32 XB_FASTCALL xb_XLIVE_STAT_CLASS_RequestFriends(u8* self) {
    u8 rec[0xB0];
    u8 me[0xB0];
    u8* list;
    u32 n;
    u32 i;
    u32 cnt;
    XB_XSTAT* p;
    s32 hr;
    XB_ARG a;

    list = xb_XLIVE_FRIEND_CLASS_GetFriendList(D_00798CAC + 0x25D0);

    if (std__vector_Elem60__empty(list)) {
        *(s32*)(self + 0xC) = 0;
        *(s32*)(self + 8) = 0xE;
        return 0;
    }

    xb_deque_LiveObj_Clear(self + 0x250);
    xb_vector_StatSpec_Clear(self + 0x7C);
    n = std__vector_Elem60__size(list) < 0x63 ? std__vector_Elem60__size(list) : 0x63;
    a.v = n + 1;
    ((void (XB_FASTCALL*)(u8*, XB_ARG))xb_vector_StatSpec_Resize)(self + 0x7C, a);

    for (i = 0; i < n; i++) {
        xb_XLIVE_PLAYER_ctor(rec);
        *(XB_PEER12*)rec = *(XB_PEER12*)XB_FRIEND(i);
        XBUtil_GetWide((char*)(XB_FRIEND(i) + 0xC), (u16*)(rec + 0x10), 0x10);
        a.v = (s32)rec;
        ((void (XB_FASTCALL*)(u8*, XB_ARG))xb_deque_LiveObj_PushBack)(self + 0x250, a);
        *(XB_PEER12*)XB_SPEC(i)->user = *(XB_PEER12*)XB_FRIEND(i);
        XB_SPEC(i)->board = *(u32*)(self + 0x28C);
        a.v = i;
        {
            XB_ARG b;

            b.v = (s32)&cnt;
            p = ((XB_XSTAT* (XB_FASTCALL*)(XB_XSTAT*, XB_ARG))xb_xlive_stat_GetStats7)(
                (XB_XSTAT*)(((u8* (XB_FASTCALL*)(u8*, XB_ARG))xb_deque_LiveObj_Subscript)(self + 0x250, a) + 0x30), b);
        }
        XB_SPEC(i)->stats = p;
        XB_SPEC(i)->n = cnt;
    }

    xb_XLIVE_PLAYER_ctor(me);
    *(XB_PEER12*)me = *(XB_PEER12*)XB_ME();
    XBUtil_GetWide((char*)(XB_ME() + 0xC), (u16*)(me + 0x10), 0x10);
    a.v = (s32)me;
    ((void (XB_FASTCALL*)(u8*, XB_ARG))xb_deque_LiveObj_PushBack)(self + 0x250, a);
    *(XB_PEER12*)XB_SPEC(n)->user = *(XB_PEER12*)me;
    XB_SPEC(n)->board = *(u32*)(self + 0x28C);
    a.v = n;
    {
        XB_ARG b;

        b.v = (s32)&cnt;
        p = ((XB_XSTAT* (XB_FASTCALL*)(XB_XSTAT*, XB_ARG))xb_xlive_stat_GetStats7)(
            (XB_XSTAT*)(((u8* (XB_FASTCALL*)(u8*, XB_ARG))xb_deque_LiveObj_Subscript)(self + 0x250, a) + 0x30), b);
    }
    XB_SPEC(n)->stats = p;
    XB_SPEC(n)->n = cnt;
    hr = xb_xlive_StatRequest(std__vector_Elem18__size(self + 0x7C), XB_SPEC(0), 0, 0,
                              (void*)CXBOnlineTask_operator_addr(self + 0x434));

    if (hr < 0) {
        xb_xlive_main_SetErrorArgs(7, D_002B83E0, 0xC25, 1);
        xb_XLIVE_STAT_CLASS_CloseTasks(self);
    } else {
        *(s32*)(self + 8) = 3;
        *(s32*)(self + 0xC) = 0;
        *(s32*)(self + 0x290) = 0xE;
    }

    return hr;
}

typedef struct {
    u32 w[2];
} XB_DQIT;
XB_DQIT* XB_FASTCALL xb_deque_LiveObj_Begin(u8* self, s32 edx, XB_DQIT* out);
XB_DQIT* XB_FASTCALL xb_deque_LiveObj_End(u8* self, s32 edx, XB_DQIT* out);
XB_DQIT* XB_FASTCALL xb_deque_iterator_Add(XB_DQIT* self, s32 edx, XB_DQIT* out, u32 n);
XB_DQIT* XB_FASTCALL xb_deque_LiveObj_Erase(u8* self, s32 edx, XB_DQIT* out, XB_DQIT where);
u8 XB_FASTCALL xb_deque_LiveObj_Empty(u8* self);
void xb_deque_LiveObj_Sort(XB_DQIT first, XB_DQIT last, u8 pred);

/* xb_XLIVE_STAT_CLASS_Kind14 0x118A56: the friends' leaderboard read: the
 * players without stats dropped and the rest sorted; then kind 6. */
s32 XB_FASTCALL xb_XLIVE_STAT_CLASS_Kind14(u8* self, s32 edx, s32* st) {
    u8* q = self + 0x250;
    u32 i = 0;
    XB_DQIT b;
    XB_DQIT it;
    XB_DQIT r;
    u8 pred;
    XB_ARG a;
    XB_ARG c;

    (void)edx;
    (void)st;
    *(s32*)(self + 8) = 6;
    *(s32*)(self + 0xC) = 0;
    *(s32*)(self + 0x294) = 0;

    while (i < xb_LiveObj_Count(q)) {
        a.v = i;

        if (xb_xlive_stat_IsUnset((XB_XSTAT*)(((u8* (XB_FASTCALL*)(u8*, XB_ARG))xb_deque_LiveObj_Subscript)(q, a) + 0x30))) {
            a.v = (s32)&b;
            c.v = (s32)&it;
            {
                XB_ARG d;
                XB_DQIT* p;

                d.v = i;
                p = ((XB_DQIT* (XB_FASTCALL*)(XB_DQIT*, XB_ARG, XB_ARG))xb_deque_iterator_Add)(
                    ((XB_DQIT* (XB_FASTCALL*)(u8*, XB_ARG))xb_deque_LiveObj_Begin)(q, a), c, d);
                a.v = (s32)&r;
                ((XB_DQIT* (XB_FASTCALL*)(u8*, XB_ARG, XB_DQIT))xb_deque_LiveObj_Erase)(q, a, *p);
            }
        } else {
            i++;
        }
    }

    if (!xb_deque_LiveObj_Empty(q)) {
        XB_DQIT* e;
        XB_DQIT* f;

        pred = 0;
        a.v = (s32)&r;
        e = ((XB_DQIT* (XB_FASTCALL*)(u8*, XB_ARG))xb_deque_LiveObj_End)(q, a);
        a.v = (s32)&b;
        f = ((XB_DQIT* (XB_FASTCALL*)(u8*, XB_ARG))xb_deque_LiveObj_Begin)(q, a);
        xb_deque_LiveObj_Sort(*f, *e, pred);
    }

    return 0;
}

void XB_FASTCALL xb_vector_StatRow_Resize(u8* self, s32 edx, u32 n);
s32 XB_FASTCALL xb_XLIVE_STAT_CLASS_RequestRows(u8* self);

#define XB_ROW(i) (a.v = (i), ((u8* (XB_FASTCALL*)(u8*, XB_ARG))xb_vector_StatRow_Subscript)(self + 0x278, a))

/* xb_XLIVE_STAT_CLASS_Kind8 0x119F98: a lost match against a user (+0x2B0)
 * written: the loss record (+0x3A0) and four rows, the opponent on the
 * page's points board and this player (+0x298) on its three boards; then
 * the wait (kind 3, 17 stats). */
s32 XB_FASTCALL xb_XLIVE_STAT_CLASS_Kind8(u8* self, s32 edx, s32* st) {
    XB_XSTAT* s = (XB_XSTAT*)(self + 0x3A0);
    s32 hr;
    s32 board;
    XB_ARG a;

    (void)edx;
    a.v = 0;
    ((void (XB_FASTCALL*)(XB_XSTAT*, XB_ARG))xb_xlive_stat_SetWins)(s, a);
    a.v = *(s32*)(self + 0x418);
    ((void (XB_FASTCALL*)(XB_XSTAT*, XB_ARG))xb_xlive_stat_SetMatches)(s, a);
    a.v = 0;
    ((void (XB_FASTCALL*)(XB_XSTAT*, XB_ARG))xb_xlive_stat_SetGrade)(s, a);
    *(s32*)(self + 0x414) = 1;
    a.v = XGetLanguage();
    ((void (XB_FASTCALL*)(XB_XSTAT*, XB_ARG))xb_xlive_stat_SetRegion)(s, a);
    a.v = 4;
    ((void (XB_FASTCALL*)(u8*, XB_ARG))xb_vector_StatRow_Resize)(self + 0x278, a);
    *(XB_PEER12*)XB_ROW(0) = *(XB_PEER12*)(self + 0x2B0);
    board = (*(s32*)(self + 0x54) + 1) * 3;
    *(s32*)(XB_ROW(0) + 0x80) = board;
    *(XB_PEER12*)XB_ROW(1) = *(XB_PEER12*)(self + 0x298);
    board = *(s32*)(self + 0x54) * 3 + 1;
    *(s32*)(XB_ROW(1) + 0x80) = board;
    *(XB_PEER12*)XB_ROW(2) = *(XB_PEER12*)(self + 0x298);
    board = *(s32*)(self + 0x54) * 3 + 2;
    *(s32*)(XB_ROW(2) + 0x80) = board;
    *(XB_PEER12*)XB_ROW(3) = *(XB_PEER12*)(self + 0x298);
    board = (*(s32*)(self + 0x54) + 1) * 3;
    *(s32*)(XB_ROW(3) + 0x80) = board;
    hr = xb_XLIVE_STAT_CLASS_RequestRows(self);
    *st = hr;

    if (hr < 0) {
        return -1;
    }

    *(s32*)(self + 0xC) = 0;
    *(s32*)(self + 8) = 3;
    *(s32*)(self + 0x290) = 0x11;
    return 0;
}

u32 XB_FASTCALL std__vector_Elem88__size(void* self);

/* xb_XLIVE_STAT_CLASS_RequestRows 0x119A32: a stats request with one entry
 * per row (+0x278, 0x88 bytes: the user, its stats at +0x10 and its board
 * at +0x80); the records +0x90 on are reset first. */
s32 XB_FASTCALL xb_XLIVE_STAT_CLASS_RequestRows(u8* self) {
    XB_XSTAT* st;
    s32 i;
    XB_XSTAT* p;
    u32 cnt;
    s32 hr;
    XB_ARG a;

    a.v = std__vector_Elem88__size(self + 0x278);
    ((void (XB_FASTCALL*)(u8*, XB_ARG))xb_vector_StatSpec_Resize)(self + 0x7C, a);

    for (i = 0, st = (XB_XSTAT*)(self + 0x90); i < (s32)std__vector_Elem88__size(self + 0x278); i++, st += 7) {
        xb_xlive_stat_Reset(st);
        *(XB_PEER12*)XB_SPEC(i)->user = *(XB_PEER12*)XB_ROW(i);
        XB_SPEC(i)->board = *(u32*)(XB_ROW(i) + 0x80);
        {
            XB_ARG b;

            b.v = (s32)&cnt;
            p = ((XB_XSTAT* (XB_FASTCALL*)(XB_XSTAT*, XB_ARG))xb_xlive_stat_GetStats7)((XB_XSTAT*)(XB_ROW(i) + 0x10), b);
        }
        XB_SPEC(i)->stats = p;
        XB_SPEC(i)->n = cnt;
    }

    hr = xb_xlive_StatRequest(std__vector_Elem18__size(self + 0x7C), XB_SPEC(0), 0, 0,
                              (void*)CXBOnlineTask_operator_addr(self + 0x434));

    if (hr < 0) {
        xb_xlive_main_SetErrorArgs(7, D_002B83E0, 0xBC1, 1);
        xb_XLIVE_STAT_CLASS_CloseTasks(self);
    }

    return hr;
}

/* xb_XLIVE_STAT_CLASS_FindPlayer 0x11787C: the row of the player with the
 * user id (its first 8 bytes) in the page's players (+0x250), or -1. */
s32 XB_FASTCALL xb_XLIVE_STAT_CLASS_FindPlayer(u8* self, s32 edx, u32* user) {
    u8* q = self + 0x250;
    s32 i;
    u32* p;
    XB_ARG a;

    (void)edx;

    for (i = 0; i < (s32)xb_LiveObj_Count(q); i++) {
        a.v = i;
        p = (u32*)((u8* (XB_FASTCALL*)(u8*, XB_ARG))xb_deque_LiveObj_Subscript)(q, a);

        if (p[0] == user[0] && p[1] == user[1]) {
            return i;
        }
    }

    return -1;
}

/* xb_XLIVE_STAT_CLASS_ResetCursor 0x1178C5: the list at the top, the
 * cursor on this player. */
void XB_FASTCALL xb_XLIVE_STAT_CLASS_ResetCursor(u8* self) {
    XB_ARG a;

    *(s32*)(self + 0x410) = 0;
    *(s32*)(self + 0x42C) = 0;
    a.v = (s32)(self + 0x298);
    *(s32*)(self + 0x64) = ((s32 (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_STAT_CLASS_FindPlayer)(self, a);
    *(s32*)(self + 0x68) = 0;
}

/* xb_XLIVE_STAT_CLASS_ClampTop 0x1165AD: a top row kept in the list. */
s32 XB_FASTCALL xb_XLIVE_STAT_CLASS_ClampTop(u8* self, s32 edx, s32 top) {
    u8* q = self + 0x250;

    (void)edx;

    if (top > (s32)xb_LiveObj_Count(q) - 14) {
        top = xb_LiveObj_Count(q) - 14;
    }

    if (top < 0) {
        top = 0;
    }

    return top;
}

void XB_FASTCALL xb_WINSTR_CLASS_SetState6(u8* self);
s32 xb_xlive_disp_DrawRectFloat(f32 x, f32 y, f32 w, f32 h);
void xb_OnlineObj_Move(s32 id);
u8 xb_OnlineObj_IsDone(s32 id);
s32 xb_LivePadUp(void);
s32 xb_LivePadDown(void);
s32 xb_LivePadLeft(void);
s32 xb_LivePadRight(void);
s32 xb_LivePadBack(void);
s32 xb_LivePadTrigger(s32 mask);
void xb_SeSelectedThunk(void);
void xb_xlive_friend_Release(s32 id);
extern f32 D_002193F0;
extern f32 D_002B4DE4;

/* xb_XLIVE_STAT_CLASS_Kind16 0x118109: browsing a leaderboard (column
 * +0xC): its window opened, the cursor on this player, then the stick
 * scrolls a row or a page, X goes to the top, Y to this player (or, with
 * none, to a no-rank state 4 that X leaves); B closes it (1). */
s32 XB_FASTCALL xb_XLIVE_STAT_CLASS_Kind16(u8* self, s32 edx, s32* st) {
    s32 r = 0;
    s32 v;
    XB_ARG a;

    (void)edx;

    switch (*(s32*)(self + 0xC)) {
    case 0:
        *(s32*)(self + 0xC) = 1;
        xb_WINSTR_CLASS_SetState6(*(u8**)(self + 0x4A0));
        *(s32*)(self + 0x44C) = xb_xlive_disp_DrawRectFloat(D_002B4BEC, D_002193F0, D_002B4A34, D_002B4DE4);
        xb_OnlineObj_Move(*(s32*)(self + 0x44C));
    case 1:
        if (xb_OnlineObj_IsDone(*(s32*)(self + 0x44C)) == 0) {
            goto out;
        }

        (*(s32*)(self + 0xC))++;
    case 2:
        (*(s32*)(self + 0xC))++;
        xb_XLIVE_STAT_CLASS_ResetCursor(self);
    case 3:
        if (xb_LivePadUp()) {
            (*(s32*)(self + 0x410))--;
        }

        if (xb_LivePadDown()) {
            (*(s32*)(self + 0x410))++;
        }

        if (xb_LivePadLeft()) {
            *(s32*)(self + 0x410) -= 14;
        }

        if (xb_LivePadRight()) {
            *(s32*)(self + 0x410) += 14;
        }

        v = -*(s32*)(self + 0x410);

        if (!XB_STAT_SHOWN(v) && xb_LivePadTrigger(0x100)) {
            *(s32*)(self + 0x410) = 0;
        }

        v = *(s32*)(self + 0x64) - *(s32*)(self + 0x410);

        if (!XB_STAT_SHOWN(v) && xb_LivePadTrigger(0x200)) {
            *(s32*)(self + 0x68) = 0x1E;

            if (*(s32*)(self + 0x64) == -1) {
                *(s32*)(self + 0xC) = 4;
            } else {
                *(s32*)(self + 0x410) = *(s32*)(self + 0x64) - 7;
            }
        }

        if (*(s32*)(self + 0x68) != 0) {
            (*(s32*)(self + 0x68))--;
        }

        a.v = *(s32*)(self + 0x410);
        *(s32*)(self + 0x410) = ((s32 (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_STAT_CLASS_ClampTop)(self, a);
        break;
    case 4:
        if (xb_LivePadTrigger(0x100)) {
            *(s32*)(self + 0xC) = 3;
            xb_XLIVE_STAT_CLASS_ResetCursor(self);
        }

        break;
    default:
        _assert(D_0025CCA0, D_002B83E0, 0xA06);
        r = xb_xlive_main_SetErrorArgs(7, D_002B83E0, 0xA07, 1);
        xb_XLIVE_STAT_CLASS_CloseTasks(self);
        goto out;
    }

    if (xb_LivePadBack()) {
        r = 1;
        xb_SeSelectedThunk();
        xb_xlive_friend_Release(*(s32*)(self + 0x44C));
        *(s32*)(self + 0x44C) = -1;
    }

out:
    *st = 0;
    return r;
}

/* xb_WINSTR_CLASS_IsShown 0x1160D1: a text window in state 3. */
s32 XB_FASTCALL xb_WINSTR_CLASS_IsShown(u8* self) {
    return *(s32*)self == 3;
}

/* xb_XLIVE_STAT_CLASS_StateHasWait 0x1159A8: the page states that show
 * the wait window (0, 3 and 4). */
s32 XB_FASTCALL xb_XLIVE_STAT_CLASS_StateHasWait(u8* self, s32 edx, s32 state) {
    (void)self;
    (void)edx;

    switch (state) {
    case 0:
    case 3:
    case 4:
        return 1;
    case 1:
    case 2:
    case 5:
    case 6:
        break;
    default:
        _assert(D_0025CCA0, D_002B83E0, 0xA43);
        break;
    }

    return 0;
}

s32 XB_FASTCALL CXBOnlineTask_Continue(void* self);
s32 XB_FASTCALL CXBOnlineTask_Close(void* self);
s32 XB_FASTCALL xb_iterator_Deref(u8* self);
s32 XB_FASTCALL xb_WINSTR_CLASS_Exists(u8* self);
void XB_FASTCALL xb_WINSTR_CLASS_SetPos(u8* self, s32 edx, f32 x, f32 y, f32 w, f32 h, const char* str);
s32 xb_xlive_StatResults(s32 task, u32 n, void* specs, s32 a, s32 b);
extern char* D_00799340;

/* xb_XLIVE_STAT_CLASS_Update 0x117F48: the wait for a stats task (kind 3):
 * the wait window shown while the page has one, the task run, and its
 * results read; then the next kind (+0x290), or 1 when that is 17. */
s32 XB_FASTCALL xb_XLIVE_STAT_CLASS_Update(u8* self, s32 edx, s32* st) {
    s32 r = 0;
    s32 hr = 0;
    XB_ARG a;
    XB_ARG b;

    (void)edx;

    switch (*(s32*)(self + 0xC)) {
    case 0:
        a.v = *(s32*)(self + 0x58);

        if (((s32 (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_STAT_CLASS_StateHasWait)(self, a)) {
            *(s32*)(self + 0xC) = 1;

            if (xb_WINSTR_CLASS_Exists(*(u8**)(self + 0x4A0)) == 0) {
                b.v = (s32)D_00799340;
                ((void (XB_FASTCALL*)(u8*, f32, f32, f32, f32, XB_ARG))xb_WINSTR_CLASS_SetPos)(
                    *(u8**)(self + 0x4A0), D_002B4BEC, D_002193F0, D_002B4A34, D_002B4DE4, b);
            }
        } else {
            *(s32*)(self + 0xC) = 2;
        }

        break;
    case 1:
        if (xb_WINSTR_CLASS_IsShown(*(u8**)(self + 0x4A0)) == 0) {
            break;
        }

        *(s32*)(self + 0xC) = 2;
    case 2:
        hr = CXBOnlineTask_Continue(self + 0x434);

        if (hr == 0) {
            break;
        }

        if (hr < 0) {
            r = xb_xlive_main_SetErrorArgs(7, D_002B83E0, 0x771, 1);
            xb_XLIVE_STAT_CLASS_CloseTasks(self);
            break;
        }

        hr = xb_xlive_StatResults(xb_iterator_Deref(self + 0x434), std__vector_Elem18__size(self + 0x7C), XB_SPEC(0), 0, 0);

        if (hr < 0) {
            r = xb_xlive_main_SetErrorArgs(7, D_002B83E0, 0x778, 1);
            xb_XLIVE_STAT_CLASS_CloseTasks(self);
            break;
        }

        if (*(s32*)(self + 0x290) == 0x11) {
            r = 1;
        } else {
            *(s32*)(self + 8) = *(s32*)(self + 0x290);
            *(s32*)(self + 0xC) = 0;
        }

        CXBOnlineTask_Close(self + 0x434);
        break;
    default:
        _assert(D_0025CCA0, D_002B83E0, 0x78C);
        r = xb_xlive_main_SetErrorArgs(7, D_002B83E0, 0x78D, 1);
        xb_XLIVE_STAT_CLASS_CloseTasks(self);
        break;
    }

    *st = hr;
    return r;
}

s32 xb_LivePadAccept(void);
void xb_SeCursorMoveThunk(void);
void XB_FASTCALL xb_xlive_main_ClearWin(void* self);
void XB_FASTCALL xb_xlive_main_SetWinText(u8* self, s32 edx, const char* msg);
void xb_OnlineObj_Fade(s32 id);
extern u32 D_0079A3F4;
extern char* D_0079A3E8[3];
extern char* D_00799170;
extern char* D_007993F0;
extern char* D_0079919C;
extern char* D_0079907C;
extern f32 D_002B50E4;
extern f32 D_002B86EC;
extern f32 D_002B4D98;

#define XB_WINTEXT(t) (a.v = (s32)(t), ((void (XB_FASTCALL*)(u8*, XB_ARG))xb_xlive_main_SetWinText)(D_00798CAC, a))

/* xb_XLIVE_STAT_CLASS_ProcessResults 0x11A2B9: the stats menu (state 0):
 * its two windows opened (page 0), the choice of the three leaderboards
 * (page 1, +0x5C; A starts its query, B closes), the query run (page 2),
 * and the windows closed (page 3, 1). */
s32 XB_FASTCALL xb_XLIVE_STAT_CLASS_ProcessResults(u8* self, s32 edx, s32* out) {
    s32 r = 0;
    s32 st = 0;
    XB_ARG a;

    (void)edx;

    if ((D_0079A3F4 & 1) == 0) {
        D_0079A3F4 |= 1;
        D_0079A3E8[0] = D_00799170;
        D_0079A3E8[1] = D_007993F0;
        D_0079A3E8[2] = D_0079919C;
    }

    switch (*(s32*)(self + 4)) {
    case 0:
        switch (*(s32*)(self + 8)) {
        case 0:
            *(s32*)(self + 8) = 1;
            xb_CONNECT_USER_CLASS_IsTaskDone(D_00798CAC + 0x59E0);
        case 1:
            (*(s32*)(self + 8))++;
            XB_WINTEXT(D_0079907C);
            *(s32*)(self + 0x444) = xb_xlive_disp_DrawRectFloat(D_00219408, D_002B50E4, D_002B4D94, D_002B86EC);
            xb_OnlineObj_Move(*(s32*)(self + 0x444));
            *(s32*)(self + 0x448) = xb_xlive_disp_DrawRectFloat(D_002B4BEC, D_002B4D98, D_002B4A34, D_002B4DE4);
            xb_OnlineObj_Move(*(s32*)(self + 0x448));
        case 2:
            if (xb_OnlineObj_IsDone(*(s32*)(self + 0x444)) && xb_OnlineObj_IsDone(*(s32*)(self + 0x448))) {
                (*(s32*)(self + 4))++;
                *(s32*)(self + 0x290) = 0x11;
                *(s32*)(self + 8) = 0;
                *(s32*)(self + 0xC) = 0;
            }

            break;
        default:
            _assert(D_0025CCA0, D_002B83E0, 0x4D6);
            xb_xlive_main_SetErrorArgs(7, D_002B83E0, 0x4D8, 1);
            xb_XLIVE_STAT_CLASS_CloseTasks(self);
            r = -1;
            break;
        }

        break;
    case 1:
        if (xb_LivePadTrigger(1)) {
            xb_SeCursorMoveThunk();

            if (--*(s32*)(self + 0x5C) < 0) {
                *(s32*)(self + 0x5C) = 2;
            }
        } else if (xb_LivePadDown()) {
            xb_SeCursorMoveThunk();

            if (++*(s32*)(self + 0x5C) >= 3) {
                *(s32*)(self + 0x5C) = 0;
            }
        }

        if (xb_LivePadAccept()) {
            xb_SeSelectedThunk();
            (*(s32*)(self + 4))++;
            xb_xlive_main_ClearWin(D_00798CAC);
            xb_xlive_friend_Release(*(s32*)(self + 0x444));
            *(s32*)(self + 0x444) = -1;
            xb_xlive_friend_Release(*(s32*)(self + 0x448));
            *(s32*)(self + 0x448) = -1;
            xb_CONNECT_USER_CLASS_IsTaskDone(D_00798CAC + 0x59E0);

            if (*(s32*)(self + 0x5C) < 0 || *(s32*)(self + 0x5C) > 2) {
                _assert(D_0025CCA0, D_002B83E0, 0x51F);
                xb_xlive_main_SetErrorArgs(7, D_002B83E0, 0x521, 1);
                xb_XLIVE_STAT_CLASS_CloseTasks(self);
                r = -1;
            } else {
                *(s32*)(self + 8) = 5;
                *(s32*)(self + 0xC) = 0;
                *(s32*)(self + 0x290) = 0xF;
                *(s32*)(self + 0x70) = 0x3C;
                *(s32*)(self + 0x288) = 0;
                *(s32*)(self + 0x28C) = *(s32*)(self + 0x54) * 3 + *(s32*)(self + 0x5C) + 1;
                *(s32*)(self + 0x420) = 0;
                *(s32*)(self + 0x424) = 0x64;
                *(s32*)(self + 0x428) = 0;
                XB_WINTEXT(D_0079A3E8[*(s32*)(self + 0x5C)]);
            }

            *(s32*)(self + 0xC) = 0;
        } else if (xb_LivePadBack()) {
            *(s32*)(self + 4) = 3;
            xb_SeSelectedThunk();
            xb_xlive_main_ClearWin(D_00798CAC);
            xb_OnlineObj_Fade(*(s32*)(self + 0x444));
            xb_OnlineObj_Fade(*(s32*)(self + 0x448));
        }

        break;
    case 2:
        r = XB_STAT_DISPATCH(self, st);

        if (r == -1 || r == 0) {
            break;
        }

        if (r != 1) {
            _assert(D_0025CCA0, D_002B83E0, 0x540);
            xb_xlive_main_SetErrorArgs(7, D_002B83E0, 0x542, 1);
            xb_XLIVE_STAT_CLASS_CloseTasks(self);
            r = -1;
            break;
        }

        *(s32*)(self + 4) = 0;
        r = 0;
        *(s32*)(self + 8) = 0;
        *(s32*)(self + 0xC) = 0;
        break;
    case 3:
        if (xb_OnlineObj_IsDone(*(s32*)(self + 0x444)) && xb_OnlineObj_IsDone(*(s32*)(self + 0x448))) {
            r = 1;
            xb_xlive_friend_Release(*(s32*)(self + 0x444));
            *(s32*)(self + 0x444) = -1;
            xb_xlive_friend_Release(*(s32*)(self + 0x448));
            *(s32*)(self + 0x448) = -1;
        }

        break;
    default:
        _assert(D_0025CCA0, D_002B83E0, 0x552);
        xb_xlive_main_SetErrorArgs(7, D_002B83E0, 0x554, 1);
        xb_XLIVE_STAT_CLASS_CloseTasks(self);
        r = -1;
        break;
    }

    *out = st;
    return r;
}

s32 XB_FASTCALL xb_XLIVE_FRIEND_CLASS_StartEnumerate(u8* self);
s32 XB_FASTCALL xb_XLIVE_FRIEND_CLASS_PollEnumerate(u8* self);
s32 XB_FASTCALL xb_XLIVE_FRIEND_CLASS_EndEnumerate(u8* self);
void XB_FASTCALL xb_WINSTR_CLASS_Clear30(u8* self);

/* The friend tasks the friends' leaderboard uses, closed on its errors. */
#define XB_CLOSE_FRIEND_TASKS()                      \
    CXBOnlineTask_Close(D_00798CAC + 0x110);         \
    CXBOnlineTask_Close(D_00798CAC + 0x118);         \
    CXBOnlineTask_Close(D_00798CAC + 0x11C)

/* xb_XLIVE_STAT_CLASS_Kind12 0x1165E0: the friends list read for the
 * friends' leaderboard: the wait window, the enumeration started and run,
 * its result taken; then the next kind (+0x290), or 1 for 17. Errors
 * report the work's result (+0x2D4). */
s32 XB_FASTCALL xb_XLIVE_STAT_CLASS_Kind12(u8* self, s32 edx, s32* st) {
    s32 r = 0;
    s32 hr = 0;
    s32 v;
    XB_ARG a;
    XB_ARG b;

    (void)edx;

    switch (*(s32*)(self + 0xC)) {
    case 0:
        a.v = *(s32*)(self + 0x58);

        if (((s32 (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_STAT_CLASS_StateHasWait)(self, a)) {
            *(s32*)(self + 0xC) = 1;
            b.v = (s32)D_00799340;
            ((void (XB_FASTCALL*)(u8*, f32, f32, f32, f32, XB_ARG))xb_WINSTR_CLASS_SetPos)(
                *(u8**)(self + 0x4A0), D_002B4BEC, D_002193F0, D_002B4A34, D_002B4DE4, b);
        } else {
            *(s32*)(self + 0xC) = 2;
        }

        break;
    case 1:
        if (xb_WINSTR_CLASS_IsShown(*(u8**)(self + 0x4A0)) == 0) {
            break;
        }

        *(s32*)(self + 0xC) = 2;
    case 2:
        (*(s32*)(self + 0xC))++;

        if (xb_XLIVE_FRIEND_CLASS_StartEnumerate(D_00798CAC + 0x25D0) == -1) {
            hr = *(s32*)(D_00798CAC + 0x2D4);
            r = xb_xlive_main_SetErrorArgs(9, D_002B83E0, 0xB32, 1);
            break;
        }
    case 3:
        v = xb_XLIVE_FRIEND_CLASS_PollEnumerate(D_00798CAC + 0x25D0);

        if (v == -1) {
            hr = *(s32*)(D_00798CAC + 0x2D4);
            r = xb_xlive_main_SetErrorArgs(9, D_002B83E0, 0xB3F, 1);
        } else if (v == 0) {
        } else if (v == 1) {
            (*(s32*)(self + 0xC))++;
        } else {
            _assert(D_0025CCA0, D_002B83E0, 0xB42);
            r = xb_xlive_main_SetErrorArgs(9, D_002B83E0, 0xB43, 1);
            XB_CLOSE_FRIEND_TASKS();
        }

        break;
    case 4:
        v = xb_XLIVE_FRIEND_CLASS_EndEnumerate(D_00798CAC + 0x25D0);

        if (v == -1) {
            hr = *(s32*)(D_00798CAC + 0x2D4);
            r = xb_xlive_main_SetErrorArgs(9, D_002B83E0, 0xB66, 1);
        } else if (v == 0) {
        } else if (v != 1) {
            _assert(D_0025CCA0, D_002B83E0, 0xB69);
            r = xb_xlive_main_SetErrorArgs(9, D_002B83E0, 0xB6A, 1);
            XB_CLOSE_FRIEND_TASKS();
        } else if (*(s32*)(self + 0x290) != 0x11) {
            *(s32*)(self + 8) = *(s32*)(self + 0x290);
            *(s32*)(self + 0xC) = 0;
        } else {
            r = 1;
            a.v = *(s32*)(self + 0x58);

            if (((s32 (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_STAT_CLASS_StateHasWait)(self, a)) {
                xb_WINSTR_CLASS_Clear30(*(u8**)(self + 0x4A0));
            }
        }

        break;
    default:
        _assert(D_0025CCA0, D_002B83E0, 0xB72);
        r = xb_xlive_main_SetErrorArgs(9, D_002B83E0, 0xB73, 1);
        XB_CLOSE_FRIEND_TASKS();
        break;
    }

    *st = hr;
    return r;
}

/* xb_XLIVE_STAT_CLASS_ResetCursorMatch 0x1180BD: this player (+0x6C) and
 * the cursor's player (+0x64) found, the list topped six rows above this
 * player in states 3 and 4 (else above the cursor). */
void XB_FASTCALL xb_XLIVE_STAT_CLASS_ResetCursorMatch(u8* self) {
    s32 top;
    XB_ARG a;

    a.v = (s32)(self + 0x2A4);
    *(s32*)(self + 0x6C) = ((s32 (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_STAT_CLASS_FindPlayer)(self, a);
    a.v = (s32)(self + 0x298);
    top = ((s32 (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_STAT_CLASS_FindPlayer)(self, a);
    *(s32*)(self + 0x64) = top;

    if (*(s32*)(self + 0x58) == 3 || *(s32*)(self + 0x58) == 4) {
        top = *(s32*)(self + 0x6C);
    }

    top -= 6;
    *(s32*)(self + 0x410) = top;
    a.v = top;
    *(s32*)(self + 0x410) = ((s32 (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_STAT_CLASS_ClampTop)(self, a);
}

s32 xb_LivePadNewRaw(s32 mask);
s32 xb_LivePadUpRaw(void);
s32 xb_LivePadDownRaw(void);
s32 xb_LivePadLeftRaw(void);
s32 xb_LivePadRightRaw(void);
s32 xb_LivePadPressedConfirm(void);
s32 xb_xlive_disp_DrawRectF(f32 x, f32 y, f32 w, f32 h, f32 z);
s32 xb_xlive_disp_SetObj0C(s32 id, s32 v);

/* xb_XLIVE_STAT_CLASS_Kind6 0x11851B: browsing a leaderboard in a match:
 * as Kind16, but in states 3 and 4 (the match results, dark window) the
 * scroll comes from the game (+0x440: 7 up, 8 down, 9 and 10 a page) and X
 * goes to this player; A closes it. */
s32 XB_FASTCALL xb_XLIVE_STAT_CLASS_Kind6(u8* self, s32 edx, s32* st) {
    s32 r = 0;
    s32 v;
    s32 s;
    XB_ARG a;

    (void)edx;

    switch (*(s32*)(self + 0xC)) {
    case 0:
        *(s32*)(self + 0xC) = 1;
        xb_WINSTR_CLASS_SetState6(*(u8**)(self + 0x4A0));
        *(s32*)(self + 0x44C) = xb_xlive_disp_DrawRectF(D_002B4BEC, D_002193F0, D_002B4A34, D_002B4DE4, 1.0f);

        if (*(s32*)(self + 0x58) == 3 || *(s32*)(self + 0x58) == 4) {
            xb_xlive_disp_SetObj0C(*(s32*)(self + 0x44C), 0xFF000000);
        }

        xb_OnlineObj_Move(*(s32*)(self + 0x44C));
    case 1:
        if (xb_OnlineObj_IsDone(*(s32*)(self + 0x44C)) == 0) {
            goto out;
        }

        (*(s32*)(self + 0xC))++;
    case 2:
        (*(s32*)(self + 0xC))++;
        xb_XLIVE_STAT_CLASS_ResetCursorMatch(self);
    case 3:
        s = *(s32*)(self + 0x58);

        if (s != 3 && s != 4) {
            if (xb_LivePadUpRaw()) {
                (*(s32*)(self + 0x410))--;
            }

            if (xb_LivePadDownRaw()) {
                (*(s32*)(self + 0x410))++;
            }

            if (xb_LivePadLeftRaw()) {
                *(s32*)(self + 0x410) -= 14;
            }

            if (xb_LivePadRightRaw()) {
                *(s32*)(self + 0x410) += 14;
            }
        } else {
            switch (*(s32*)(self + 0x440)) {
            case 7:
                (*(s32*)(self + 0x410))--;
                break;
            case 8:
                (*(s32*)(self + 0x410))++;
                break;
            case 9:
                *(s32*)(self + 0x410) -= 14;
                break;
            case 10:
                *(s32*)(self + 0x410) += 14;
                break;
            }
        }

        s = *(s32*)(self + 0x58);

        if (s == 3 || s == 4) {
            v = *(s32*)(self + 0x6C) - *(s32*)(self + 0x410);

            if (!XB_STAT_SHOWN(v) && xb_LivePadNewRaw(0x100)) {
                *(s32*)(self + 0x410) = *(s32*)(self + 0x6C) - 7;
            }
        }

        v = *(s32*)(self + 0x64) - *(s32*)(self + 0x410);

        if (!XB_STAT_SHOWN(v) && xb_LivePadNewRaw(0x200)) {
            if (*(s32*)(self + 0x64) != -1) {
                *(s32*)(self + 0x68) = 0x1E;
                *(s32*)(self + 0x410) = *(s32*)(self + 0x64) - 7;
            } else {
                *(s32*)(self + 0xC) = 4;
            }
        }

        if (*(s32*)(self + 0x68) != 0) {
            (*(s32*)(self + 0x68))--;
        }

        a.v = *(s32*)(self + 0x410);
        *(s32*)(self + 0x410) = ((s32 (XB_FASTCALL*)(u8*, XB_ARG))xb_XLIVE_STAT_CLASS_ClampTop)(self, a);
        break;
    case 4:
        if (xb_LivePadNewRaw(0x100)) {
            *(s32*)(self + 0xC) = 3;
            xb_XLIVE_STAT_CLASS_ResetCursorMatch(self);
        }

        break;
    default:
        _assert(D_0025CCA0, D_002B83E0, 0x97C);
        r = xb_xlive_main_SetErrorArgs(7, D_002B83E0, 0x97D, 1);
        xb_XLIVE_STAT_CLASS_CloseTasks(self);
        goto out;
    }

    if (xb_LivePadPressedConfirm()) {
        r = 1;
        xb_SeSelectedThunk();
        xb_xlive_friend_Release(*(s32*)(self + 0x44C));
        *(s32*)(self + 0x44C) = -1;
    }

out:
    *st = 0;
    return r;
}

/* The grades: the matches (at least) and win rate each needs (D_00418638,
 * 20), and the points a win scores by the two players' grades
 * (D_004186D8, 20 by 20, highest grades first). */
typedef struct {
    s32 matches;
    f32 rate;
} XB_GRADEREQ;
extern XB_GRADEREQ D_00418638[20];
extern u8 D_004186D8[400];
extern char D_002B8460[];
extern char D_002B8454[];
extern char D_002B8498[];
extern char D_002B846C[];

/* xb_XLIVE_STAT_CLASS_Rating 0x115A28: the rating stat, points by 20
 * plus the grade. */
s32 XB_FASTCALL xb_XLIVE_STAT_CLASS_Rating(u8* self, s32 edx, s32 points, s32 grade) {
    (void)self;
    (void)edx;
    return points * 20 + grade;
}

/* xb_XLIVE_STAT_CLASS_GradeFor 0x115A39: the highest grade whose matches
 * and win rate the record reaches (19 when none). */
s32 XB_FASTCALL xb_XLIVE_STAT_CLASS_GradeFor(u8* self, s32 edx, s32 wins, s32 matches) {
    s32 g = 19;
    s32 i;
    f32 rate;

    (void)self;
    (void)edx;

    if (wins < 0) {
        _assert(D_002B8460, D_002B83E0, 0xC60);
        wins = 0;
    }

    if (matches < 0) {
        _assert(D_002B8454, D_002B83E0, 0xC63);
        matches = 0;
    }

    if (matches != 0) {
        rate = (f32)wins / (f32)matches;
    } else {
        rate = 0.0f;
    }

    for (i = 19; i >= 0; i--) {
        if (matches >= D_00418638[i].matches && rate >= D_00418638[i].rate) {
            g = i;
            break;
        }
    }

    return g;
}

/* xb_XLIVE_STAT_CLASS_PointsFor 0x115AB9: a win's points: base times the
 * table entry for the two grades (each kept to 0..19). */
s32 XB_FASTCALL xb_XLIVE_STAT_CLASS_PointsFor(u8* self, s32 edx, s32 base, s32 mine, s32 theirs) {
    (void)self;
    (void)edx;

    if (mine < 0 || mine >= 20) {
        _assert(D_002B8498, D_002B83E0, 0xC9C);
    }

    if (mine < 0) {
        mine = 0;
    }

    if (mine > 19) {
        mine = 19;
    }

    if (theirs < 0 || theirs >= 20) {
        _assert(D_002B846C, D_002B83E0, 0xCA0);
    }

    if (theirs < 0) {
        theirs = 0;
    }

    if (theirs > 19) {
        theirs = 19;
    }

    return D_004186D8[399 - mine * 20 - theirs] * base;
}

s32 xb_xlive_StatWrite(u32 n, void* specs, s32 a, s32 b, void* task);

#define XB_MIN999999(x_) ((x_) > 999999 ? 999999 : (x_))
#define XB_SET(f, s_, x_) (a.v = (x_), ((void (XB_FASTCALL*)(XB_XSTAT*, XB_ARG))(f))((s_), a))

/* xb_XLIVE_STAT_CLASS_Kind4 0x119672: a match's result (+0x3A0) added to
 * the player's three boards (+0x90 on, each kept below a million): wins,
 * matches, points by the result's kind (+0x414: 0 a win scored by grade,
 * 1 none, 2 as given), the grade recomputed, the language and rating, and
 * the boards written (task +0x430); then this player's stats kept. */
s32 XB_FASTCALL xb_XLIVE_STAT_CLASS_Kind4(u8* self, s32 edx, s32* out) {
    XB_XSTAT* res = (XB_XSTAT*)(self + 0x3A0);
    XB_XSTAT* st;
    XB_XSTAT* p;
    s32 r = 0;
    s32 hr = 0;
    s32 i;
    s32 v;
    u32 n;
    XB_ARG a;
    XB_ARG b;
    XB_ARG c;

    (void)edx;

    switch (*(s32*)(self + 0xC)) {
    case 0:
        a.v = 3;
        ((void (XB_FASTCALL*)(u8*, XB_ARG))xb_vector_StatSpec_Resize)(self + 0x7C, a);
        (*(s32*)(self + 0xC))++;

        for (i = 0, st = (XB_XSTAT*)(self + 0x90); i < 3; i++, st += 7) {
            *(XB_PEER12*)XB_SPEC(i)->user = **(XB_PEER12**)(self + 0x2BC);
            v = *(s32*)(self + 0x54) * 3 + i + 1;
            XB_SPEC(i)->board = v;
            a.v = (s32)&n;
            p = ((XB_XSTAT* (XB_FASTCALL*)(XB_XSTAT*, XB_ARG))xb_xlive_stat_GetStats6)(st, a);
            XB_SPEC(i)->stats = p;
            XB_SPEC(i)->n = n;

            if (xb_xlive_stat_IsUnset(st)) {
                xb_xlive_stat_Reset(st);
            }

            v = xb_xlive_stat_GetWins(st) + xb_xlive_stat_GetWins(res);
            XB_SET(xb_xlive_stat_SetWins, st, XB_MIN999999(v));
            v = xb_xlive_stat_GetMatches(st) + xb_xlive_stat_GetMatches(res);
            XB_SET(xb_xlive_stat_SetMatches, st, XB_MIN999999(v));

            switch (*(s32*)(self + 0x414)) {
            case 0:
                a.v = *(s32*)(self + 0x41C);
                b.v = xb_xlive_stat_GetGrade(st);
                c.v = xb_xlive_stat_GetGrade((XB_XSTAT*)(self + 0x330));
                v = ((s32 (XB_FASTCALL*)(u8*, XB_ARG, XB_ARG, XB_ARG))xb_XLIVE_STAT_CLASS_PointsFor)(self, a, b, c);
                v += xb_xlive_stat_GetPoint(st);
                XB_SET(xb_xlive_stat_SetPoint, st, XB_MIN999999(v));
                break;
            case 1:
                break;
            case 2:
                v = xb_xlive_stat_GetPoint(st) + xb_xlive_stat_GetPoint(res);
                XB_SET(xb_xlive_stat_SetPoint, st, XB_MIN999999(v));
                break;
            default:
                _assert(D_0025CCA0, D_002B83E0, 0x7DE);
                r = xb_xlive_main_SetErrorArgs(8, D_002B83E0, 0x7DF, 1);
                xb_XLIVE_STAT_CLASS_CloseTasks(self);
                return r;
            }

            a.v = xb_xlive_stat_GetWins(st);
            b.v = xb_xlive_stat_GetMatches(st);
            v = ((s32 (XB_FASTCALL*)(u8*, XB_ARG, XB_ARG))xb_XLIVE_STAT_CLASS_GradeFor)(self, a, b);
            XB_SET(xb_xlive_stat_SetGrade, st, v);
            XB_SET(xb_xlive_stat_SetRegion, st, xb_xlive_stat_GetRegion(res));
            a.v = xb_xlive_stat_GetPoint(st);
            b.v = xb_xlive_stat_GetGrade(st);
            v = ((s32 (XB_FASTCALL*)(u8*, XB_ARG, XB_ARG))xb_XLIVE_STAT_CLASS_Rating)(self, a, b);
            a.v = v;
            b.v = v >> 31;
            ((void (XB_FASTCALL*)(XB_XSTAT*, XB_ARG, XB_ARG))xb_xlive_stat_SetRating)(st, a, b);
        }

        hr = xb_xlive_StatWrite(std__vector_Elem18__size(self + 0x7C), XB_SPEC(0), 0, 0,
                                (void*)CXBOnlineTask_operator_addr(self + 0x430));

        if (hr < 0) {
            r = xb_xlive_main_SetErrorArgs(8, D_002B83E0, 0x805, 1);
            xb_XLIVE_STAT_CLASS_CloseTasks(self);
            break;
        }
    case 1:
        hr = CXBOnlineTask_Continue(self + 0x430);

        if (hr == 0) {
            break;
        }

        if (hr < 0) {
            r = xb_xlive_main_SetErrorArgs(8, D_002B83E0, 0x80F, 1);
            xb_XLIVE_STAT_CLASS_CloseTasks(self);
            break;
        }

        r = 1;
        CXBOnlineTask_Close(self + 0x430);
        *(XB_XSTAT7*)(self + 0x2C0) = *(XB_XSTAT7*)(self + 0x170);
        break;
    default:
        _assert(D_0025CCA0, D_002B83E0, 0x824);
        r = xb_xlive_main_SetErrorArgs(8, D_002B83E0, 0x825, 1);
        xb_XLIVE_STAT_CLASS_CloseTasks(self);
        break;
    }

    *out = hr;
    return r;
}
