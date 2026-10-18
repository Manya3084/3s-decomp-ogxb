/* op_sub.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * TexRelease 0xD0CBE size 0x75.
 * TexRelease_OP 0xD0D33 size 0x34.
 * put_chr2 0xD0D67 size 0xB9.
 * opbg_trans 0xD0E20 size 0x112. Read against the x86: 0x17F and 0xDF are the
 * +383 and +223 rounding adds, 4 is a field step, and 0x20 the y offset. The C
 * is the PS2 C.
 * COLOR_COPYn 0xD0F32 size 0x29.
 * Globals: ppgOpnBgList 0x7A7DB8, ppgTitleTex 0x7A7DC0, ppgOpnBgTex 0x7A7DE0,
 * ppgAdxPal 0x7A7E80, ppgCapLogoTex 0x7A7EA0, ppgCapLogoPal 0x7A7F40,
 * ppgWarPal 0x7A8040, ColorRAM 0x7AAD60, No_Trans 0x7BD3C9, scr_sc 0x7C55F4,
 * Frame_Zoom_Y 0x7C5854, Frame_Zoom_X 0x7C5B94, title_tex_flag 0xC7E19E,
 * PrioBase 0xC7E560.
 */

#include "structs.h"

#define NULL 0

extern s16 title_tex_flag;
s32 ppgReleaseTextureHandle(Texture* tch, s32 ixNum);
extern Texture ppgWarTex;
s32 ppgReleasePaletteHandle(Palette* pch, s32 ixNum);
extern Palette ppgWarPal;
extern Palette ppgAdxPal;
extern Texture ppgCapLogoTex;
extern Palette ppgCapLogoPal;
extern Texture ppgTitleTex;
void Purge_memory_of_kind_of_key(u8 kokey);
void ppgSourceDataReleased(PPGDataList* dlist);
extern PPGDataList ppgOpnBgList;
extern Texture ppgOpnBgTex;
void reset_dma_group(u16 num);
void purge_texcash_work(s16 ix);
extern u8 No_Trans;
extern f32 Frame_Zoom_X;
extern f32 Frame_Zoom_Y;
extern f32 PrioBase[128];
s32 ppgWriteQuadUseTrans(Vertex* pos, u32 col, PPGDataList* tb, s32 tix, s32 cix, s32 flip, s32 pal);
extern f32 scr_sc;
extern u16 ColorRAM[512][64];
void njSetPaletteData(s32 offset, s32 count, void* data);



void TexRelease(u32 G_Num) {
    if (G_Num == 601) {
        title_tex_flag = 0;
    }

    switch (G_Num) {
    case 590:
        ppgReleaseTextureHandle(&ppgWarTex, -1);
        ppgReleasePaletteHandle(&ppgWarPal, -1);
        ppgReleasePaletteHandle(&ppgAdxPal, -1);
        break;

    case 600:
        ppgReleaseTextureHandle(&ppgCapLogoTex, -1);
        ppgReleasePaletteHandle(&ppgCapLogoPal, -1);
        break;

    case 601:
        ppgReleaseTextureHandle(&ppgTitleTex, -1);
        break;
    }
}

void TexRelease_OP() {
    Purge_memory_of_kind_of_key(0x1D);
    ppgSourceDataReleased(&ppgOpnBgList);
    ppgReleaseTextureHandle(&ppgOpnBgTex, -1);
    reset_dma_group(0x8C40);
    purge_texcash_work(9);
}

void put_chr2(OPTW* optw) {
    Vertex tex[4];

    if (No_Trans) {
        return;
    }

    tex[0].x = Frame_Zoom_X * ((s32)optw->off_x * optw->zx);
    tex[0].y = Frame_Zoom_Y * ((s32)optw->off_y * optw->zy);
    tex[3].x = Frame_Zoom_X * ((optw->off_x + 0x100) * optw->zx);
    tex[3].y = Frame_Zoom_Y * ((optw->off_y + 0x100) * optw->zy);
    tex[0].z = tex[3].z = PrioBase[optw->prio];
    ppgWriteQuadUseTrans(tex, optw->col.full, NULL, optw->g_no, -1, optw->hv, 300);
}

void opbg_trans(OPBW* opbw, s16 x, s16 y) {
    OPTW optw;
    s16 i;
    s16 i0;
    s16 i1;
    s16 j;
    s16 j0;
    s16 j1;
    s16 xx;
    s16 yy;

    xx = (x < 0) ? 0 : x;
    yy = (y < 0) ? 0 : y;
    xx = (x > 1023) ? 1023 : xx;
    yy = (y > 1023) ? 1023 : yy;

    i0 = xx >> 8;
    i1 = ((xx + 383) >> 8) & 3;
    j1 = ((yy + 223) >> 8) & 3;
    j0 = yy >> 8;

    for (i = i0; i <= i1; i++) {
        for (j = j0; j <= j1; j++) {
            if (opbw->map[i][j].g_no != 0) {
                optw.g_no = opbw->map[i][j].g_no;
                optw.hv = opbw->map[i][j].hv;
                optw.off_x = (i << 8) - x;
                optw.off_y = (y + 224) - ((j << 8) + 256);
                optw.zx = optw.zy = scr_sc;
                optw.prio = opbw->prio;
                optw.trans = opbw->map[i][j].trans;
                optw.col.full = opbw->map[i][j].col.full;
                put_chr2(&optw);
            }
        }
    }
}

void COLOR_COPYn(s16 dst, s16 colcd, s16 n) {
    s16* colram = (s16*)ColorRAM;
    njSetPaletteData(dst * 16, n * 16, &colram[colcd * 16]);
}
