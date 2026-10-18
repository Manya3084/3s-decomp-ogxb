/* Two early returns, as the retail branch order has them. */
void Check_Reset() {
    if (Forbid_Reset) {
        RESET_X = 0;
        return;
    }

    if (Present_Mode == 2) {
        RESET_X = 0;
        return;
    }

    Switch_Type = 1;

    if (Check_SoftReset(0) == 0) {
        Check_SoftReset(1);
    }
}
