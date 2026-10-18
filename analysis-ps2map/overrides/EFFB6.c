/* Xbox: the upper bounds are written inclusive (<= 0x9F, <= 0xFF). */
s32 msgCheckCodeSize(u8 data) {
    if (data >= 0x80 && data <= 0x9F) {
        return 2;
    }

    if (data >= 0xE0 && data <= 0xFF) {
        return 2;
    }

    return 1;
}
