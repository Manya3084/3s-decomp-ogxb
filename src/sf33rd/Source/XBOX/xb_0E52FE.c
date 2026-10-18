/* xb_0E52FE.c: Xbox-only code from the run of Xbox-only functions at 0xE52FE, which no
 * PS2 file covers.
 * Capcom's source is lost. Its C++ methods are written as C,
 * XB_FASTCALL (__fastcall) with this first. Each body was checked
 * against retail by analysis-ps2map/xbgen.py. The xb_ names are
 * made up. */

#include "types.h"

s32 load_it_use_any_key2(s32 ix, void* out, s32* size, s32 a, s32 b);
s32 flLogOut(const char* fmt, ...);
extern void* D_007A7E98[];
void ppgLoadMsgTex(void);
void ppgScrPal(void);
void ppgSetupCurrentDataList(void* list);
extern char D_002AEE14[];
void ppgSetupTexChunk_1st(void* a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g);
void ppgSetupTexChunk_2nd(void* a, s32 i);
void ppgSetupTexChunk_3rd(void* a, s32 i, s32 b);
void sub_00097103(s32 key);
void ppgSourceDataReleased(void* a);

void xb_LoadExitScreen(void) {
    s32 adr;
    s32 key;
    s32 tex;
    s32 i;
    s32 n = 4;

    D_007A7E98[0] = ppgLoadMsgTex;
    D_007A7E98[1] = ppgScrPal;
    ppgSetupCurrentDataList(D_007A7E98);
    tex = load_it_use_any_key2(0xF, &adr, &key, 2, 0);

    if (tex == 0) {
        flLogOut(D_002AEE14);
        while (1) {}
    }

    ppgSetupTexChunk_1st(0, adr, tex, 0, n, 0, 0);

    for (i = 0; n != 0; i++, n--) {
        ppgSetupTexChunk_2nd(0, i);
        ppgSetupTexChunk_3rd(0, i, 1);
    }

    sub_00097103(key);
    ppgSourceDataReleased(0);
}
