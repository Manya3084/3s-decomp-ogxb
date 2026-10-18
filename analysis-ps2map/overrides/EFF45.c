/* The Xbox has no Debug_w test. */
void Check_Pig_Pig(WORK_Other_CONN* ewk) {
    s16 ix;

    switch (Message_Data[ewk->wu.dir_old].request) {
    case 22:
        for (ix = 0; ix < ewk->num_of_conn; ix++) {
            if (ewk->conn[ix].chr != 0x8020) {
                continue;
            }

            ewk->conn[ix].chr = vm_w.Block_Size + 0x7F81;
            ewk->conn[ix].col = 0x17;
            return;
        }

        break;

    case 23:
    case 25:
        Convert_16_10_2(ewk, vm_w.Block_Size);

        for (ix = 0; ix < ewk->num_of_conn; ix++) {
            if (ewk->conn[ix].chr != 0x8020) {
                continue;
            }

            ewk->conn[ix].chr = ewk->wu.old_rno[1] + 0x7F81;
            ewk->conn[ix].col = 0x17;

            if (ewk->wu.old_rno[1] == 0) {
                ewk->conn[ix].ny -= 0x100;
            }

            ewk->conn[(ix) + 1].chr = ewk->wu.old_rno[0] + 0x7F81;
            ewk->conn[(ix) + 1].col = 0x17;
            return;
        }

        break;

    case 24:
        for (ix = 0; ix < ewk->num_of_conn; ix++) {
            if (ewk->conn[ix].chr != 0x8020) {
                continue;
            }

            ewk->conn[ix].chr = ewk->wu.old_rno[2] + 0x7F81;
            ewk->conn[ix].col = 0x17;

            if (ewk->wu.old_rno[2] == 0) {
                ewk->conn[ix].ny -= 0x100;
            }

            ewk->conn[ix + 1].chr = ewk->wu.old_rno[1] + 0x7F81;
            ewk->conn[ix + 1].col = 0x17;

            if (ewk->wu.old_rno[1] == 0 && ewk->wu.old_rno[2] == 0) {
                ewk->conn[ix + 1].ny -= 0x100;
            }

            ewk->conn[ix + 2].chr = ewk->wu.old_rno[0] + 0x7F81;
            ewk->conn[ix + 2].col = 0x17;
            return;
        }

        break;
    }
}

/* The Xbox does not call Check_Pos_OBJ2. The table entry is on the left of the comparison. */
void effect_45_move(WORK_Other_CONN* ewk) {
    if (Check_Die_61((WORK_Other*)ewk) != 0 || Message_Data[ewk->wu.dir_old].order == 3) {
        push_effect_work(&ewk->wu);
        return;
    }

    if (Message_Data[ewk->wu.dir_old].order != ewk->wu.routine_no[0]) {
        ewk->wu.routine_no[0] = Message_Data[ewk->wu.dir_old].order;
        ewk->wu.routine_no[1] = 0;
    }

    EFF45_Jmp_Tbl[ewk->wu.routine_no[0]](ewk);

    if (ewk->wu.be_flag != 0) {
        ewk->wu.dir_step = Message_Data[ewk->wu.dir_old].order;
        sort_push_request3(&ewk->wu);
    }
}
