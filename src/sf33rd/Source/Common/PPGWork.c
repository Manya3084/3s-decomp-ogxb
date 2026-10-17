/* ppgWorkInitializeApprication, retail sf33rd.xbe 0xF421B size 0x8B.
 * It is interior. The four background textures start at 0x7A7F60.
 * ppgRwBgTex is 0x7A7D00. ppgAkeTex is 0x7A7D20 and ppgAkePal is
 * 0x7A7E00. ppgAkaneTex is 0x7A8000 and ppgAkanePal is 0x7A7E20.
 * ppgScrTex is 0x7A7D60. ppgScrPal is 0x7A7DA0, ppgScrPalFace is
 * 0x7A7EC0, ppgScrPalShot is 0x7A7F20, and ppgScrPalOpt is 0x7A7F00.
 * ppgOpnBgTex is 0x7A7DE0. ppgTitleTex is 0x7A7DC0. ppgWarTex is
 * 0x7A7FE0, ppgWarPal is 0x7A8040, and ppgAdxPal is 0x7A7E80.
 * ppgCapLogoTex is 0x7A7EA0 and ppgCapLogoPal is 0x7A7F40.
 * mts[i].tex.be starts at 0x7A8F48 and steps by 0x64 through 0x7A98A8.
 * col3rd_w.palCP3 is 0x7AAC74 and palDC is 0x7AAC60.
 * Xbox also clears the loading-message texture at 0x7A8020. Its list
 * is 0x7A7E98 and its palette is ppgScrPal. The PlayStation 2 source
 * has no such object. 0xF42A6 stays unnamed.
 */

#include "types.h"

#include <stddef.h>

typedef struct {
    s8 be;
    u8 c_mode;
    u16 total;
    u16 *handle;
    s32 ixNum1st;
    u8 *srcAdrs;
    u32 srcSize;
} Palette;

typedef struct {
    s8 be;
    u8 flags;
    s16 arCnt;
    s16 arInit;
    u16 total;
    void *handle;
    s32 ixNum1st;
    u16 textures;
    u16 accnum;
    u32 *offset;
    u8 *srcAdrs;
    u32 srcSize;
} Texture;

typedef struct {
    u8 before_tex[0x28];
    Texture tex;
    u8 after_tex[0x1C];
} MultiTexture;

typedef struct {
    Palette palDC;
    Palette palCP3;
} Col3rd_W;

#if defined(__i386__)
_Static_assert(sizeof(Palette) == 0x14, "Palette");
_Static_assert(sizeof(Texture) == 0x20, "Texture");
_Static_assert(sizeof(MultiTexture) == 0x64, "MultiTexture");
_Static_assert(offsetof(MultiTexture, tex) == 0x28, "tex");
_Static_assert(offsetof(Col3rd_W, palCP3) == 0x14, "palCP3");
#endif

extern Texture ppgBgTex[4];
extern Texture ppgRwBgTex;
extern Texture ppgAkeTex;
extern Palette ppgAkePal;
extern Texture ppgAkaneTex;
extern Palette ppgAkanePal;
extern Texture ppgScrTex;
extern Palette ppgScrPal;
extern Palette ppgScrPalFace;
extern Palette ppgScrPalShot;
extern Palette ppgScrPalOpt;
extern Texture ppgOpnBgTex;
extern Texture ppgTitleTex;
extern Texture ppgWarTex;
extern Palette ppgWarPal;
extern Palette ppgAdxPal;
extern Texture ppgCapLogoTex;
extern Palette ppgCapLogoPal;
extern Texture ppgLoadMsgTex;
extern MultiTexture mts[24];
extern Col3rd_W col3rd_w;

void ppgWorkInitializeApprication(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        ppgBgTex[i].be = 0;
    }

    ppgRwBgTex.be = 0;
    ppgAkeTex.be = ppgAkePal.be = 0;
    ppgAkaneTex.be = ppgAkanePal.be = 0;
    ppgScrTex.be = ppgScrPal.be = ppgScrPalFace.be = ppgScrPalShot.be = ppgScrPalOpt.be = 0;
    ppgOpnBgTex.be = 0;
    ppgTitleTex.be = 0;
    ppgWarTex.be = ppgWarPal.be = ppgAdxPal.be = 0;
    ppgCapLogoTex.be = ppgCapLogoPal.be = 0;
    ppgLoadMsgTex.be = 0;

    for (i = 0; i < 24; i++) {
        mts[i].tex.be = 0;
    }

    col3rd_w.palDC.be = col3rd_w.palCP3.be = 0;
}
