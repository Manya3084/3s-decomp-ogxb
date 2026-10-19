/* mlPAD.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by hand: callees, constants, field offsets, and globals. Unless a note
 * says otherwise the C is the PS2 C.
 * flpad_ram_clear 0x1113D size 0x49. Read against the x86: the word loop is
 * rep stosd and the tail rep stosb. The C is the PS2 C.
 * flPADWorkClear 0x11186 size 0x21. Read against the x86: each clear is 0x220
 * bytes, four pads of 0x88. The C is the PS2 C over the Xbox array sizes.
 * flPADConfigSet 0x111A7 size 0x43. Read against the x86: the config copy is
 * 11 dwords (0x2C), then the Xbox flPADConfigSetACRtoXX at 0x171AF. The C
 * is the PS2 C with that call.
 * padconf_setup_depth 0x111EA size 0x2E. The C is the PS2 C.
 * flupdate_pad_stick_dir 0x11218 size 0x77. The C is the PS2 C.
 * flupdate_pad_button_data 0x1128F size 0x2B. The C is the PS2 C.
 * flupdate_pad_on_cnt 0x112BA size 0x34. The C is the PS2 C.
 * flPADSetRepeatSw 0x112EE size 0x67. The C is the PS2 C.
 * flPADInitialize 0x11355 size 0x3C. Read against the x86: Xbox has four
 * pads (PS2 two), and tarPADInit is the Xbox routine at 0x17592.
 * flPADACRConf 0x11391 size 0x34F. Read against the x86: four pads (PS2 two);
 * 0xB4, 0x168 and 0x21C are the C's 180, 360 and 540, and the call at the end
 * is the /GS cookie check. The C is the PS2 C with four pads.
 * flPADGetALL 0x116E0 size 0xE6. Read against the x86: four pads (PS2 two),
 * tarPADRead is the Xbox routine at 0x175D7, and flPADACRConf is a tail jump.
 * Not located in sf33rd.xbe; its PS2 C is kept under #if 0: flPADDestroy.
 * Globals: flpad_io_map 0x219748, flpad_root 0x43E300, NumOfValidPads
 * 0x43E520, flpad_config 0x43E528, flpad_conf 0x43E5D8, tarpad_root 0x7957B0
 * (four 0x34-byte pads), flpad_adr 0xCBA990.
 * Data: flpad_root is 0x43E300. flpad_config is 0x43E528. flpad_conf is
 * 0x43E5D8. tarpad_root is 0x7957B0. flpad_adr is 0xCBA990. NumOfValidPads
 * is the byte at 0x43E520. flpad_io_map is 0x219748. fltpad_config_basic
 * is 0x219718.
 */

#include "structs.h"

#define FLPAD_NUM 4

/* Pasted from the PS2 file. */
const u32 flpad_io_map[25] = { 0x1,     0x2,     0x4,      0x8,      0x10,     0x20,     0x40,   0x80,    0x100,
                               0x200,   0x400,   0x800,    0x1000,   0x2000,   0x4000,   0x8000, 0x10000, 0x20000,
                               0x40000, 0x80000, 0x100000, 0x200000, 0x400000, 0x800000, 0x0 };
extern TARPAD tarpad_root[FLPAD_NUM];

/* Xbox pad layer: tarPADInit, tarPADRead and flPADConfigSetACRtoXX. */
s32 xb_PADInit(void);
void xb_PADRead(void);
void xb_PADSetConfig(s32 padnum, s16 a, s16 b, s16 c);

void flPADWorkClear();
void flPADConfigSet(const FLPAD_CONFIG* adrs, s32 padnum);
void flPADACRConf();
void padconf_setup_depth(u8* deps, u8 num, u32 iodat);
void flupdate_pad_stick_dir(PAD_STICK* st);
void flupdate_pad_button_data(FLPAD* pad, u32 data);
void flupdate_pad_on_cnt(FLPAD* pad);
/* Pasted from the PS2 file. */
const FLPAD_CONFIG fltpad_config_basic = {
    { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
      16, 17, 18, 19, 20, 21, 22, 23, 24, 24, 24, 24, 24, 24, 24, 24 },
    0, /* flip_lever */
    0, /* flip_ast1 */
    0, /* flip_ast2 */
    0, /* free */
    32, /* abut_on: Xbox (PS2 8) */
    48, /* ast1_on */
    48, /* ast2_on */
    0 /* free2 */
};

/* fllever_flip_data is 0x219040 and fllever_depth_flip_data is 0x219080. */
const u8 fllever_flip_data[4][16] = {
    { 0x00, 0x01, 0x02, 0x00, 0x04, 0x05, 0x06, 0x00, 0x08, 0x09, 0x0A, 0x00, 0x00, 0x00, 0x00, 0x00 },
    { 0x00, 0x01, 0x02, 0x00, 0x08, 0x09, 0x0A, 0x00, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00 },
    { 0x00, 0x02, 0x01, 0x00, 0x04, 0x06, 0x05, 0x00, 0x08, 0x0A, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00 },
    { 0x00, 0x02, 0x01, 0x00, 0x08, 0x0A, 0x09, 0x00, 0x04, 0x06, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00 },
};

const u8 fllever_depth_flip_data[4][4] = {
    { 0x00, 0x01, 0x02, 0x03 },
    { 0x00, 0x01, 0x03, 0x02 },
    { 0x01, 0x00, 0x02, 0x03 },
    { 0x01, 0x00, 0x03, 0x02 },
};

FLPAD* flpad_adr[2];
FLPAD_CONFIG flpad_config[FLPAD_NUM];
u8 NumOfValidPads;

FLPAD flpad_root[FLPAD_NUM];
FLPAD flpad_conf[FLPAD_NUM];

f64 atan2(f64, f64);

void flpad_ram_clear(u32* adrs_int, s32 xx) {
    s32 i;
    s32 surr;
    s8* adrs_char;

    surr = xx % 4U;
    xx /= 4;

    for (i = 0; i < xx; i++) {
        *(adrs_int++) = 0;
    }

    if (surr != 0) {
        adrs_char = (s8*)adrs_int;

        for (i = 0; i < surr; i++) {
            *(adrs_char++) = 0;
        }
    }
}

s32 flPADInitialize() {
    s32 i;
    s32 flag = xb_PADInit();

    flPADWorkClear();

    flpad_adr[0] = flpad_root;
    flpad_adr[1] = flpad_conf;

    for (i = 0; i < 4; i++) {
        flPADConfigSet(&fltpad_config_basic, i);
    }

    return flag;
}

void flPADWorkClear() {
    flpad_ram_clear((u32*)flpad_root, sizeof(flpad_root));
    flpad_ram_clear((u32*)flpad_conf, sizeof(flpad_conf));
}

void flPADConfigSet(const FLPAD_CONFIG* adrs, s32 padnum) {
    flpad_config[padnum] = *adrs;

    xb_PADSetConfig(
        padnum, flpad_config[padnum].abut_on, flpad_config[padnum].ast1_on, flpad_config[padnum].ast2_on);
}

void flPADGetALL() {
    s16 i;

    xb_PADRead();
    NumOfValidPads = 0;

    for (i = 0; i < 4; i++) {
        flpad_adr[0][i].state = tarpad_root[i].state;
        flpad_adr[0][i].anstate = tarpad_root[i].anstate;
        flpad_adr[0][i].kind = tarpad_root[i].kind;
        flpad_adr[0][i].conn = tarpad_root[i].conn;

        if ((flpad_adr[0][i].kind != 0) && (flpad_adr[0][i].kind != 0x8000)) {
            NumOfValidPads += 1;
        }

        flpad_adr[0][i].stick[0] = tarpad_root[i].stick[0];
        flpad_adr[0][i].stick[1] = tarpad_root[i].stick[1];
        flpad_adr[0][i].anshot = tarpad_root[i].anshot;

        flupdate_pad_button_data(&flpad_adr[0][i], tarpad_root[i].sw);
        flupdate_pad_on_cnt(&flpad_adr[0][i]);
        flpad_adr[0][i].sw_repeat = flpad_adr[0][i].sw_new;
    }

    flPADACRConf();
}

void flPADACRConf() {
    u8* csh;
    u32 conf_data;
    u32 conf_data2;
    u32 st0;
    u32 ast1;
    u32 ast2;
    s16 i;
    s16 j;
    u8 depthflip[32];

    for (i = 0; i < 4; i++) {
        flpad_adr[1][i].state = flpad_adr[0][i].state;
        flpad_adr[1][i].anstate = flpad_adr[0][i].anstate;
        flpad_adr[1][i].kind = flpad_adr[0][i].kind;
        flpad_adr[1][i].conn = flpad_adr[0][i].conn;

        st0 = flpad_adr[0][i].sw & 0xF;
        ast1 = flpad_adr[0][i].sw >> 16 & 0xF;
        ast2 = flpad_adr[0][i].sw >> 20 & 0xF;
        conf_data = flpad_adr[0][i].sw & 0xFFF0;

        conf_data |= fllever_flip_data[flpad_config[i].flip_lever][st0];
        conf_data |= fllever_flip_data[flpad_config[i].flip_ast1][ast1] << 0x10;
        conf_data |= fllever_flip_data[flpad_config[i].flip_ast2][ast2] << 0x14;

        csh = flpad_config[i].conf_sw;

        for (j = 0; j < 4; j++) {
            depthflip[j] = flpad_adr[0][i].anshot.pow[fllever_depth_flip_data[flpad_config[i].flip_lever][j]];
        }

        for (j = 4; j < 0x10; j++) {
            depthflip[j] = flpad_adr[0][i].anshot.pow[j];
        }

        for (j = 0; j < 0x10; j++) {
            flpad_adr[1][i].anshot.pow[j] = 0;
        }

        conf_data2 = 0;

        for (j = 0; j < 0x18; j++) {
            if (conf_data & flpad_io_map[j]) {
                conf_data2 |= flpad_io_map[csh[j]];
            }

            if (csh[j] < 0x10) {
                if (flpad_adr[1][i].anshot.pow[csh[j]] < depthflip[j]) {
                    flpad_adr[1][i].anshot.pow[csh[j]] = depthflip[j];
                }
            } else if (csh[j] > 0x18) {
                padconf_setup_depth(flpad_adr[1][i].anshot.pow, depthflip[j], flpad_io_map[csh[j]]);
            }
        }

        flupdate_pad_button_data(&flpad_adr[1][i], conf_data2);
        flupdate_pad_on_cnt(&flpad_adr[1][i]);

        flpad_adr[1][i].sw_repeat = flpad_adr[1][i].sw_new;
        flpad_adr[1][i].stick[0] = flpad_adr[0][i].stick[0];

        switch (flpad_config[i].flip_ast1) {
        case 1:
            flpad_adr[1][i].stick[0].x = flpad_adr[1][i].stick[0].x * -1;
            flpad_adr[1][i].stick[0].ang = 540 - flpad_adr[1][i].stick[0].ang;
            break;

        case 2:
            flpad_adr[1][i].stick[0].y = flpad_adr[1][i].stick[0].y * -1;
            flpad_adr[1][i].stick[0].ang = 360 - flpad_adr[1][i].stick[0].ang;
            break;

        case 3:
            flpad_adr[1][i].stick[0].x = flpad_adr[1][i].stick[0].x * -1;
            flpad_adr[1][i].stick[0].y = flpad_adr[1][i].stick[0].y * -1;
            flpad_adr[1][i].stick[0].ang = flpad_adr[1][i].stick[0].ang + 180;
            break;
        }

        flpad_adr[1][i].stick[1] = flpad_adr[0][i].stick[1];

        switch (flpad_config[i].flip_ast2) {
        case 1:
            flpad_adr[1][i].stick[1].x = flpad_adr[1][i].stick[1].x * -1;
            flpad_adr[1][i].stick[1].ang = 540 - flpad_adr[1][i].stick[1].ang;
            break;

        case 2:
            flpad_adr[1][i].stick[1].y = flpad_adr[1][i].stick[1].y * -1;
            flpad_adr[1][i].stick[1].ang = 360 - flpad_adr[1][i].stick[1].ang;
            break;

        case 3:
            flpad_adr[1][i].stick[1].x = flpad_adr[1][i].stick[1].x * -1;
            flpad_adr[1][i].stick[1].y = flpad_adr[1][i].stick[1].y * -1;
            flpad_adr[1][i].stick[1].ang = flpad_adr[1][i].stick[1].ang + 180;
            break;
        }

        flpad_adr[1][i].stick[0].ang = flpad_adr[1][i].stick[0].ang % 360;
        flpad_adr[1][i].stick[1].ang = flpad_adr[1][i].stick[1].ang % 360;

        flupdate_pad_stick_dir(&flpad_adr[1][i].stick[0]);
        flupdate_pad_stick_dir(&flpad_adr[1][i].stick[1]);
    }
}

void padconf_setup_depth(u8* deps, u8 num, u32 iodat) {
    s32 i;

    for (i = 0; i < 0x10; i++) {
        if (iodat & flpad_io_map[i]) {
            if (deps[i] < num) {
                deps[i] = num;
            }

            if ((iodat ^= flpad_io_map[i]) == 0) {
                break;
            }
        }
    }
}

void flupdate_pad_stick_dir(PAD_STICK* st) {
    f32 radian;

    if ((st->y | st->x) == 0) {
        radian = 0.0f;
    } else {
        radian = atan2(-st->y, st->x);

        if (radian < 0.0f) {
            radian += 6.2831855f; // Pi * 2
        }
    }

    st->rad = radian;
}

void flupdate_pad_button_data(FLPAD* pad, u32 data) {
    pad->sw_old = pad->sw;
    pad->sw = data;
    pad->sw_new = pad->sw & (pad->sw_old ^ pad->sw);
    pad->sw_off = pad->sw_old & (pad->sw_old ^ pad->sw);
    pad->sw_chg = pad->sw_new | pad->sw_off;
}

void flupdate_pad_on_cnt(FLPAD* pad) {
    s16 i;

    for (i = 0; i < 0x18; i++) {
        if (pad->sw & flpad_io_map[i]) {
            if (pad->rpsw[i].ctr.press != 0xFF) {
                pad->rpsw[i].ctr.press += 1;
            }
        } else {
            pad->rpsw[i].work = 0;
        }
    }
}

void flPADSetRepeatSw(FLPAD* pad, u32 IOdata, u8 ctr, u8 times) {
    s32 i;
    u8 cmpctr;

    for (i = 0; i < 0x18; i++) {
        if (IOdata & flpad_io_map[i]) {
            if (pad->rpsw[i].ctr.sw_up >= times) {
                pad->rpsw[i].ctr.sw_up = times - 1;
            }

            cmpctr = ctr - pad->rpsw[i].ctr.sw_up * (ctr / times);

            if (pad->rpsw[i].ctr.press >= cmpctr) {
                pad->rpsw[i].ctr.press = 0;
                pad->rpsw[i].ctr.sw_up += 1;
                pad->sw_repeat |= flpad_io_map[i];
            }
        }
    }
}

#if 0
/* PS2 C for functions not located in sf33rd.xbe yet. */
void flPADDestroy() {
    tarPADDestroy();
}
#endif
