/* Sound requests, retail sf33rd.xbe.
 * Go_BGM is 0x9C646 size 0x29 and is a scanned start.
 * SsRequest is 0x9C5BF size 0x29 and is a scanned start.
 * SsRequest_CC is 0x9C5E8 size 0x2F and is a scanned start.
 * Standby_BGM is 0x9C617 size 0x2F and is a scanned start.
 * SsBgmOff is 0x9C66F size 0x29 and is a scanned start.
 * SsBgmFadeIn is 0x9C698 size 0x46 and is a scanned start.
 * SsBgmFadeOut is 0x9C6DE size 0x35 and is a scanned start.
 * SsBgmControl is 0x9C713 size 0x44 and is a scanned start.
 * SsBgmHalfVolume is 0x9C757 size 0x33 and is a scanned start.
 * Init_bgm_work is 0x9B845 size 0x1C, interior after the ret.
 * spu_all_off is 0x9B861 size 0xF, interior after the ret.
 * setSeVolume is 0x9B870 size 0x28, interior after the ret.
 * setupSoundMode is 0x9B898 size 0x26, interior after the ret.
 * Exit_sound_system is 0x9BCEC size 0x45, interior after the ret.
 * SE_cursor_move is 0x9C78A size 0x9, interior after the ret.
 * SE_dir_cursor_move is 0x9C79C size 0xC, interior after the ret.
 * sound_bgm_off is 0x9C7A8 size 0x18, interior after the ret.
 * sound_all_off is 0x9C7C0 size 0xA, interior after the jmp.
 * SsAllNoteOff is 0x9C7CA size 0x5, interior after the jmp.
 * ptix is 0x7F. system_init_level is the dword at 0x7AABDC.
 * se_level is the word at 0x9CA4B4. bgm_half_down is 0x8813F8.
 * bgm_exe is 0x8813E0 and bgm_req is 0xC7C810. adxt is 0x8813DC.
 * sound_mode is the byte at 0x7C5958. These requests do not call
 * Store_Sound_Code. 0x9BD31 and 0x9C57A stay unnamed. 0x9C793 stays
 * unnamed because SE_selected and SE_dir_selected share that body.
 */

#include "types.h"

typedef struct {
    s16 ptix;
    s16 bank;
    s16 port;
    s16 code;
} SoundPatchConfig;

typedef struct {
    s16 req;
    s16 kind;
    s16 data;
    s16 code;
} BGMRequest;

typedef struct {
    s16 kind;
    s16 rno;
    s16 code;
    s16 timer;
    s16 data;
    s16 volume;
    s16 state;
    u16 ownData;
    u16 nowSeamless;
    u16 exEntry;
    u16 exIndex;
} BGMExecution;

#if defined(__i386__)
_Static_assert(sizeof(SoundPatchConfig) == 8, "SoundPatchConfig");
_Static_assert(sizeof(BGMRequest) == 8, "BGMRequest");
_Static_assert(sizeof(BGMExecution) == 0x16, "BGMExecution");
#endif

extern s32 system_init_level;
extern s16 se_level;
extern s16 bgm_half_down;
extern BGMExecution bgm_exe;
extern BGMRequest bgm_req;
extern void *adxt;
extern s32 dword_795CF4;
extern u8 sound_mode;

extern void sub_0009BD31(SoundPatchConfig *rmc, s16 pan);
extern u16 sub_0009BBE2(u16 code, SoundPatchConfig *rmcode);
extern s32 sub_0009BB28(void);
extern void sub_0004A84E(void *dst, s32 size);
extern void sub_000F451D(s32 vol);
extern void sub_000F4510(u32 mono_sw);
extern void sub_001680B0(u32 mono_sw);
extern void sub_000F452A(void);
extern void sub_00167640(void);
extern void ADXT_Destroy(void *handle);
extern void ADXT_Finish(void);

void spu_all_off(void);
void SsBgmOff(void);
void SsRequest(u16 ReqNumber);
void sound_bgm_off(void);
void sound_all_off(void);

void Init_bgm_work(void) {
    sub_0004A84E(&bgm_exe, sizeof(BGMExecution));
    sub_0004A84E(&bgm_req, sizeof(BGMRequest));
}

void spu_all_off(void) {
    if (system_init_level & 1) {
        sub_000F452A();
    }
}

void setSeVolume(void) {
    f32 vol;

    if (system_init_level & 2) {
        vol = (127.0f / 15.0f) * (f32)se_level;
        sub_000F451D((s32)vol);
    }
}

void setupSoundMode(void) {
    if (system_init_level & 2) {
        sub_000F4510(sound_mode);
        sub_001680B0(sound_mode);
    }
}

void Exit_sound_system(void) {
    if (system_init_level & 2) {
        if (dword_795CF4 != 0) {
            sub_00167640();
        }

        ADXT_Destroy(adxt);
        ADXT_Finish();
        system_init_level &= ~2;
    }

    if (system_init_level & 1) {
        spu_all_off();
        system_init_level &= ~1;
    }
}

void SsRequest(u16 ReqNumber) {
    SoundPatchConfig rmcode;

    if (sub_0009BBE2(ReqNumber, &rmcode)) {
        return;
    }

    sub_0009BD31(&rmcode, 0);
}

void SsRequest_CC(u16 num) {
    SoundPatchConfig rmcode;

    if (sub_0009BBE2(num, &rmcode)) {
        return;
    }

    rmcode.bank = 9;
    sub_0009BD31(&rmcode, 0);
}

void Standby_BGM(u16 num) {
    SoundPatchConfig rmcode;

    if (sub_0009BBE2(num, &rmcode)) {
        return;
    }

    rmcode.bank = 2;
    sub_0009BD31(&rmcode, 0);
}

void Go_BGM(void) {
    SoundPatchConfig rmcode;

    rmcode.ptix = 0x7F;
    rmcode.bank = 3;
    rmcode.port = 0;
    rmcode.code = 0;
    sub_0009BD31(&rmcode, 0);
}

void SsBgmOff(void) {
    SoundPatchConfig rmcode;

    rmcode.ptix = 0x7F;
    rmcode.bank = 1;
    rmcode.port = 0;
    rmcode.code = 0;
    sub_0009BD31(&rmcode, 0);
}

void SsBgmFadeIn(u16 ReqNumber, u16 FadeSpeed) {
    SoundPatchConfig rmcode;
    s32 fade_time;

    if (sub_0009BBE2(ReqNumber, &rmcode) || rmcode.ptix != 0x7F) {
        return;
    }

    fade_time = 0x8000 / (s32)FadeSpeed;
    rmcode.bank = 6;
    rmcode.port = (s16)fade_time;
    sub_0009BD31(&rmcode, 0);
}

void SsBgmFadeOut(u16 time) {
    SoundPatchConfig rmcode;
    s32 fade_time = 0x8000 / (s32)time;

    rmcode.ptix = 0x7F;
    rmcode.bank = 5;
    rmcode.code = 0;
    rmcode.port = (s16)fade_time;
    sub_0009BD31(&rmcode, 0);
}

void SsBgmControl(s8 unused, s8 volume) {
    SoundPatchConfig rmcode;

    (void)unused;
    rmcode.ptix = 0x7F;
    rmcode.bank = 7;
    rmcode.code = 0;
    rmcode.port = volume;

    if (rmcode.port < -0x7F) {
        rmcode.port = -0x7F;
    }

    if (rmcode.port > 0) {
        rmcode.port = 0;
    }

    sub_0009BD31(&rmcode, 0);
}

void SsBgmHalfVolume(s16 flag) {
    SoundPatchConfig rmcode;

    bgm_half_down = flag;
    rmcode.ptix = 0x7F;
    rmcode.bank = 7;
    rmcode.code = 0;
    rmcode.port = 0;
    sub_0009BD31(&rmcode, 0);
}

void SE_cursor_move(void) {
    SsRequest(96);
}

void SE_dir_cursor_move(void) {
    SsRequest(343);
}

void sound_bgm_off(void) {
    if ((system_init_level & 2) && sub_0009BB28() != 0) {
        SsBgmOff();
    }
}

void sound_all_off(void) {
    sound_bgm_off();
    spu_all_off();
}

void SsAllNoteOff(void) {
    sound_all_off();
}
