
/* Xbox: no early returns, the candidates are filled from index 0, and
 * slot 9 says whether the player is character 0. */
void Check_Same_CPU(s16 PL_id) {
    s16 ix;
    s16 ok_urien;

    ok_urien = random_16();

    for (ix = 0; ix < 16; ix++) {
        Candidate_Buff[ix] = 0xFF;
    }

    Setup_Candidate_Buff(PL_id);

    for (ix = 0; ix < 8; ix++) {
        EM_Candidate[PL_id][0][ix] = (u8)Check_EM_Buff(ix, ok_urien);
        EM_Candidate[PL_id][1][ix] = (u8)Check_EM_Buff(ix, ok_urien);
    }

    EM_Candidate[PL_id][0][8] = Middle_Class_Boss_Data[My_char[PL_id]];
    EM_Candidate[PL_id][1][8] = Middle_Class_Boss_Data[My_char[PL_id]];

    if (My_char[PL_id] != 0) {
        EM_Candidate[PL_id][0][9] = 0;
        EM_Candidate[PL_id][1][9] = 0;
    } else {
        EM_Candidate[PL_id][0][9] = 1;
        EM_Candidate[PL_id][1][9] = 1;
    }
}
