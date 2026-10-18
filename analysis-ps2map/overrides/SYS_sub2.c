/* The Xbox does not call the empty display setup (0x4384A). */
void Setup_Disp_Size(s16 /* unused */) {
    s16 dixH = 3;
    s16 dixV = 3;

    Correct_X[3] = Adjust_XY_Data[dixH][0];
    Correct_Y[3] = Adjust_XY_Data[dixV][1];
    Screen_Zoom_X = 1.0f;
    Screen_Zoom_Y = 1.0f;
    Correct_X[1] = Correct_X[2] = Correct_X[3];
    Correct_Y[1] = Correct_Y[2] = Correct_Y[3];
}
