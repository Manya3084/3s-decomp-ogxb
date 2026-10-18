/* Xbox-only flag getter (the dword at 0x79A170). */
s32 xb_GetOnlineFlag(void);

/* Xbox: the random choice also runs while xb_GetOnlineFlag is set. */
u16 effb8_normal_or_senyou() {
    if (xb_GetOnlineFlag() == 0 && Country != 1) {
        return 0;
    }

    return random_16() & 1;
}
