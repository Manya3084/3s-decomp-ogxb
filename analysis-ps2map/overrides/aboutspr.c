/* Rewritten to match retail (tools/permute.py): < 0x48 -> <= 0x47. */
s32 sort_push_request4(WORK* wk) {

    if (wk->my_mts == 0) {
        return 0;
    }

    if (wk->disp_flag == 0 || wk->cg_number == 0) {
        return 1;
    }

    if ((wk->disp_flag == 2) && ((wk->blink_timing + Game_timer) & 1)) {
        return 1;
    }

    wk->current_colcd = wk->my_col_code;

    if (wk->extra_col_2) {
        wk->current_colcd = wk->extra_col_2;
    }

    if (wk->extra_col) {
        wk->current_colcd = wk->extra_col;
    }

    if ((wk->id != 0x4C) && (wk->id != 0x46)) {
        if (judge_flag) {
            if (wk->position_z <= 0x47) {
                wk->my_bright_type = 1;
                wk->my_bright_level = 7;
            }
        } else {
            wk->my_bright_type = 0;
            wk->my_bright_level = 0;
        }
    }

    Mtrans_use_trans_mode(wk, 0);

    if (wk->kage_flag) {
        shadow_setup(wk, 0);
    }

    return 2;
}

/* Rewritten to match retail (tools/permute.py): draw_box parameter 7: s16 -> s32. */
s32 sort_push_requestB(WORK* wk) {
    PAL_CURSOR_COL oricol;
    s16 i;
    s16 mf;

    if (No_Trans) {
        return 2;
    }
    if (wk->disp_flag == 0) {
        return 1;
    }
    oricol.color = box_color_attr[wk->my_col_code & 0x1FF][0];
    if (wk->my_clear_level) {
        oricol.argb.a = wk->my_clear_level;
    }
    if (wk->disp_flag == 2) {
        switch (wk->blink_timing) {
        case 1:
            if (Interrupt_Timer & 0x80) {
                oricol.argb.a = (wk->my_clear_level + (0x80 - (Interrupt_Timer & 0x7F)));
            } else {
                oricol.argb.a = (wk->my_clear_level + (Interrupt_Timer & 0x7F));
            }
            break;
        case 0:
            if (Interrupt_Timer & 0x40) {
                oricol.argb.a = (wk->my_clear_level + (0x40 - (Interrupt_Timer & 0x3F)));
            } else {
                oricol.argb.a = (wk->my_clear_level + (Interrupt_Timer & 0x3F));
            }
            break;
        case 2:
            if (Interrupt_Timer & 0x20) {
                oricol.argb.a = (wk->my_clear_level + (0x20 - (Interrupt_Timer & 0x1F)));
            } else {
                oricol.argb.a = (wk->my_clear_level + (Interrupt_Timer & 0x1F));
            }
            break;
        }
    }
    mlt_obj_matrix(wk, 0);
    if (wk->rl_flag) {
        mf = -1;
    } else {
        mf = 1;
    }
    draw_box((f32)(wk->shell_ix[0] * mf),
             (f32)(wk->shell_ix[2]),
             (f32)(wk->shell_ix[1] * mf),
             (f32)(wk->shell_ix[3]),
             oricol.color,
             box_color_attr[wk->my_col_code][1],
             wk->position_z);

    for (i = 0; i < wk->charset_id; i++) {
        draw_box((f32)(mf * (wk->shell_ix[0] - (i + 1) * 2)),
                 (f32)(wk->shell_ix[2] + (1 << (i + 1))),
                 (f32)(mf * (wk->shell_ix[1] + (i + 1) * 2 * 2)),
                 (f32)(wk->shell_ix[3] - (1 << (i + 1)) * 2),
                 oricol.color,
                 box_color_attr[wk->my_col_code][1],
                 wk->position_z);

        draw_box((f32)(mf * (wk->shell_ix[0] + (1 << (i + 1)))),
                 (f32)(wk->shell_ix[2] - (i + 1) * 2),
                 (f32)(mf * (wk->shell_ix[1] - (1 << (i + 1)) * 2)),
                 (f32)(wk->shell_ix[3] + (i + 1) * 2 * 2),
                 oricol.color,
                 box_color_attr[wk->my_col_code][1],
                 wk->position_z);
    }
    return 2;
}

/* Rewritten to match retail (tools/permute.py): draw_box parameter 7: s16 -> s32. */
s32 sort_push_requestA(WORK* wk) {
    PAL_CURSOR_COL oricol;
    s16 i;
    s16 mf;

    if (No_Trans) {
        return 2;
    }
    if (wk->disp_flag == 0) {
        return 1;
    }
    oricol.color = box_color_attr[wk->my_col_code & 0x1FF][0];
    if (wk->my_clear_level) {
        oricol.argb.a = wk->my_clear_level;
    }
    if (wk->disp_flag == 2) {
        switch (wk->blink_timing) {
        case 1:
            if (Interrupt_Timer & 0x80) {
                oricol.argb.a = (wk->my_clear_level + (0x80 - (Interrupt_Timer & 0x7F)));
            } else {
                oricol.argb.a = (wk->my_clear_level + (Interrupt_Timer & 0x7F));
            }
            break;
        case 0:
            if (Interrupt_Timer & 0x40) {
                oricol.argb.a = (wk->my_clear_level + (0x40 - (Interrupt_Timer & 0x3F)));
            } else {
                oricol.argb.a = (wk->my_clear_level + (Interrupt_Timer & 0x3F));
            }
            break;
        case 2:
            if (Interrupt_Timer & 0x20) {
                oricol.argb.a = (wk->my_clear_level + (0x20 - (Interrupt_Timer & 0x1F)));
            } else {
                oricol.argb.a = (wk->my_clear_level + (Interrupt_Timer & 0x1F));
            }
            break;
        }
    }
    mlt_obj_matrix(wk, base_y_pos);
    if (wk->rl_flag) {
        mf = -1;
    } else {
        mf = 1;
    }
    draw_box((f32)(wk->shell_ix[0] * mf),
             (f32)(wk->shell_ix[2]),
             (f32)(wk->shell_ix[1] * mf),
             (f32)(wk->shell_ix[3]),
             oricol.color,
             box_color_attr[wk->my_col_code][1],
             wk->position_z);

    for (i = 0; i < wk->charset_id; i++) {
        draw_box((f32)((wk->shell_ix[0] - (i + 1) * 2) * mf),
                 (f32)(wk->shell_ix[2] + (1 << (i + 1))),
                 (f32)(mf * (wk->shell_ix[1] + (i + 1) * 2 * 2)),
                 (f32)(wk->shell_ix[3] - (1 << (i + 1)) * 2),
                 oricol.color,
                 box_color_attr[wk->my_col_code][1],
                 wk->position_z);

        draw_box((f32)(mf * (wk->shell_ix[0] + (1 << (i + 1)))),
                 (f32)(wk->shell_ix[2] - (i + 1) * 2),
                 (f32)(mf * (wk->shell_ix[1] - (1 << (i + 1)) * 2)),
                 (f32)(wk->shell_ix[3] + (i + 1) * 2 * 2),
                 oricol.color,
                 box_color_attr[wk->my_col_code][1],
                 wk->position_z);
    }
    return 2;
}

/* Xbox: no Debug_w[0x23] check. */
void shadow_drawing(WORK* wk, s16 bsy) {
    s16 shadow;

    dmwk_kage.position_x = (wk->position_x + wk->kage_hx * (1 - (wk->rl_flag != 0) * 2));
    dmwk_kage.position_y = wk->kage_hy;
    dmwk_kage.position_z = wk->kage_prio;
    dmwk_kage.my_family = wk->my_family;
    shadow = wk->kage_char - get_kage_width(wk->xyz[1].disp.pos - wk->kage_hy);

    if (shadow >= 0x1D) {
        shadow = 0x1C;
    } else if (shadow < 0) {
        shadow = 0;
    }

    dmwk_kage.cg_number = shadow + 0x7308;
    Mtrans_use_trans_mode(&dmwk_kage, bsy);
}
