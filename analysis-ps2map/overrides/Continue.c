/* The Xbox has no Check_Exit_Check and Debug_w test. */
s32 Continue_Scene() {
    void (*Continue_Jmp_Tbl[5])() = { Continue_1st, Continue_2nd, Continue_3rd, Continue_4th, Continue_5th };

    CONTINUE_X = 0;
    Continue_Jmp_Tbl[Cont_No[0]]();

    return CONTINUE_X;
}
