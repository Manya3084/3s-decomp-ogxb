/* Xbox-only flag getter (the dword at 0x79A170). */
s32 xb_GetOnlineFlag(void);

/* Xbox: the random choice also runs while xb_GetOnlineFlag is set. */
u16 effb8_normal_or_senyou() {
    if (xb_GetOnlineFlag() == 0 && Country != 1) {
        return 0;
    }

    return random_16() & 1;
}

/* Xbox-only functions of this object (analysis-ps2map/xbgen.py checked each). */
s32 sort_push_request3(WORK* wk);
extern s8 Suicide[8];

void xb_effect_B8_draw(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        return;

    case 1:
        if (Suicide[2] == 1) {
            return;
        }

        sort_push_request3(&ewk->wu);
        return;

    case 2:
        if (Suicide[2] == 1) {
            return;
        }

        sort_push_request3(&ewk->wu);
        return;
    }
}
