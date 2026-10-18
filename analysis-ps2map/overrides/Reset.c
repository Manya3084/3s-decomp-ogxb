/* Xbox: no reset while Present_Mode is 2 (the Xbox-only mode). */
void Check_Reset() {
    if (Forbid_Reset || Present_Mode == 2) {
        RESET_X = 0;
        return;
    }

    Switch_Type = 1;

    if (Check_SoftReset(0) == 0) {
        Check_SoftReset(1);
    }
}
