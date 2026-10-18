/* Rewritten to match retail (tools/permute.py): < 2 -> <= 1. */
void grade_add_guard_success(s16 ix) {
    if ((u16)ix <= 1) {
        judge_item[ix][Play_Type].guard_succ++;
    }
}
