/* AcrUtil.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * setBlendOperation 0x1C8B7 size 0x15. Read against the x86: the unnamed table
 * is the static ope_mode, at 0x329D44, values compared.
 * setBlendSource 0x1C8CC size 0x21. Read against the x86: the unnamed tables
 * are the static src_mode at 0x329D50 and dst_mode at 0x329D78, values
 * compared.
 * setFilterMode 0x1C8ED size 0x15. Read against the x86: the unnamed table is
 * the static filter_mode, at 0x329DA0, values compared.
 * setTexAdrsMode 0x1C902 size 0x15. Read against the x86: the unnamed table is
 * the static addressing_mode, at 0x329DA8, values compared.
 * setBackGroundColor 0x1C917 size 0xE.
 * setBlendMode 0x1C925 size 0x1A.
 * initRenderState 0x1C93F size 0xB4. Read against the x86: the Xbox build ends
 * with a call the PS2 C does not have, sub_0001404C(0, 0, 640, 448).
 * sub_0001404C stores its four arguments to 0x43ED18, 0x44D394, 0x43ED0C, and
 * 0x43ED10, apparently a viewport origin and size. The call is added to the C.
 * fogstart and fogend are the floats at 0x23AD54 and 0x23AD50.
 * Not located in sf33rd.xbe; their PS2 C is kept under #if 0: appViewSetItems,
 * appViewGetItems, appViewMatrix, render_start, render_end, setZ_Operation.
 * Data: appView: defined elsewhere on Xbox.
 * Unnamed data used (not checked): setBlendOperation: 0x329d44;
 * setBlendSource: 0x329d50,0x329d78; setFilterMode: 0x329da0; setTexAdrsMode:
 * 0x329da8; initRenderState: 0x23ad50,0x23ad54.
 */

#include "structs.h"

#define REINTERPRET_AS_U32(_num) (*(u32*)&(_num))

typedef struct {
    // total size: 0x60
    MTX mtx;     // offset 0x0, size 0x40
    VPRM prm;    // offset 0x40, size 0x18
    s8 pad58[8]; // offset 0x58, size 0x8
} AppView;

void sub_0001404C(s32 x, s32 y, s32 w, s32 h);
s32 flSetRenderState(enum _FLSETRENDERSTATE func, u32 value);
void setBlendMode(s32 ope, s32 src, s32 dst);
void setFilterMode(s32 mode);
void setBlendSource(s32 src, s32 dst);
void setBlendOperation(s32 ope);

extern AppView appView;

void initRenderState(s32 flag) {
    f32 fogstart = 20000.0f;
    f32 fogend = 30000.0f;

    if (flag == 0) {
        flSetRenderState(FLRENDER_AMBIENT, 0);
        flSetRenderState(FLRENDER_LIGHTING, 0x200);
        flSetRenderState(FLRENDER_MATERIAL, 2);
        flSetRenderState(FLRENDER_FOGCOLOR, 0x80FFFFFF);
        flSetRenderState(FLRENDER_FOGSTART, REINTERPRET_AS_U32(fogstart));
        flSetRenderState(FLRENDER_FOGEND, REINTERPRET_AS_U32(fogend));
        flSetRenderState(FLRENDER_ALPHATEST, 4);
        flSetRenderState(FLRENDER_ZWRITE, 1);
        flSetRenderState(FLRENDER_ZOPE, 1);
    }

    setBlendMode(0, 4, 5);
    setFilterMode(1);
    flSetRenderState(FLRENDER_ALPHAREF, 0);
    sub_0001404C(0, 0, 640, 448);
}

void setBlendMode(s32 ope, s32 src, s32 dst) {
    setBlendSource(src, dst);
    setBlendOperation(ope);
}

void setBlendOperation(s32 ope) {
    static unsigned int ope_mode[3] = { 0, 0x400, 0x800 };
    flSetRenderState(FLRENDER_BLENDOPE, ope_mode[ope]);
}

void setBlendSource(s32 src, s32 dst) {
    static u32 src_mode[10] = { 0x00, 0x01, 0x04, 0x05, 0x02, 0x03, 0x08, 0x09, 0x06, 0x07 };
    static u32 dst_mode[10] = { 0x00, 0x10, 0x40, 0x50, 0x20, 0x30, 0x80, 0x90, 0x60, 0x70 };
    flSetRenderState(FLRENDER_ALPHABLENDMODE, src_mode[src] | dst_mode[dst]);
}

void setFilterMode(s32 mode) {
    static u32 filter_mode[2] = { 0x10000, 0 };
    flSetRenderState(FLRENDER_TEXTUREFILTER, filter_mode[mode]);
}

void setTexAdrsMode(s32 mode) {
    static u32 addressing_mode[3] = { 0x20000, 0, 0x40000 };
    flSetRenderState(FLRENDER_TEXTUREADDRESSING, addressing_mode[mode]);
}

void setBackGroundColor(u32 color) {
    flSetRenderState(FLRENDER_BACKCOLOR, color);
}

#if 0
/* PS2 C for functions not located in sf33rd.xbe yet. */

void appViewSetItems(VPRM* prm) {
    appView.prm = *prm;
}

void appViewGetItems(VPRM* prm) {
    *prm = appView.prm;
}

void appViewMatrix() {
    flmatMakeViewport(
        &appView.mtx, appView.prm.x0, appView.prm.y0, appView.prm.x1, appView.prm.y1, appView.prm.ne, appView.prm.fa);
}

void render_start() {
    flBeginRender();
}

void render_end() {
    flEndRender();
}

void setZ_Operation(s32 flag) {
    static u32 ope_mode[7] = { 0, 1, 2, 3, 4, 5, 6 };
    flSetRenderState(FLRENDER_ZOPE, ope_mode[flag]);
}
#endif
