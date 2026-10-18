/* Xbox: the fade back in runs at speed 1, not 8. */
void Saver_Exit(struct _TASK* task_ptr) {
    switch (task_ptr->r_no[1]) {
    case 0:
        task_ptr->r_no[1] += 1;
        FadeInit();
        /* fallthrough */

    case 1:
        if (FadeIn(1, 0xFF, 1) != 0) {
            Saver_Init(task_ptr);
        }
    }
}
