/* Xbox-only flag getter (the dword at 0x79A170). */
s32 sub_001100AC(void);

/* Xbox: the random choice also runs while sub_001100AC is set. */
u16 effb8_normal_or_senyou() {
    if (sub_001100AC() == 0 && Country != 1) {
        return 0;
    }

    return random_16() & 1;
}
