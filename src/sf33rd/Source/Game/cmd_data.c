/* cmd_data.c, retail sf33rd.xbe.
 * The PS2 file's data (ps2.path), checked by analysis-ps2map/portdata.py
 * against the XBE: each table at its data.txt address, or at the
 * address a checked table's pointer to it holds ("placed by").
 * chk22_tbl 0x241044 size 0x10: match.
 * dm_cmd_xx 0x27faf8 size 0x32: match (placed by p14_CMD).
 * lever_gacha_tbl 0x241054 size 0x20: match.
 * lvr_chk_tbl 0x332c98 size 0x10: match.
 * p0_CMD 0x3308c8 size 0xe0: match (placed by player_CMD).
 * p0_cmd 0x3307e8 size 0xe0: match (placed by player_cmd).
 * p0_cmd_20 0x27fb2c size 0x1a: match (placed by p0_CMD).
 * p0_cmd_21 0x27fb48 size 0x1a: match (placed by p0_CMD).
 * p0_cmd_22 0x27fb64 size 0x1a: match (placed by p0_CMD).
 * p0_cmd_24 0x27fb80 size 0x42: match (placed by p0_CMD).
 * p0_cmd_25 0x27fbc8 size 0x42: match (placed by p0_CMD).
 * p0_cmd_28 0x27fc0c size 0x32: match (placed by p0_CMD).
 * p0_cmd_29 0x27fc40 size 0x32: match (placed by p0_CMD).
 * p0_cmd_30 0x27fc74 size 0x32: match (placed by p0_CMD).
 * p0_cmd_31 0x27fca8 size 0x32: match (placed by p0_CMD).
 * p10_CMD 0x332308 size 0xe0: match (placed by player_CMD).
 * p10_CMD_20 0x282768 size 0x42: match (placed by p10_CMD).
 * p10_CMD_21 0x2827b0 size 0x42: match (placed by p10_CMD).
 * p10_CMD_22 0x2827f8 size 0x4a: match (placed by p10_CMD).
 * p10_cmd 0x332228 size 0xe0: match (placed by player_cmd).
 * p10_cmd_20 0x282690 size 0x42: match (placed by p10_cmd).
 * p10_cmd_21 0x2826d8 size 0x42: match (placed by p10_cmd).
 * p10_cmd_22 0x282720 size 0x42: match (placed by p10_cmd).
 * p10_cmd_28 0x282844 size 0x2a: match (placed by p10_CMD).
 * p10_cmd_29 0x282870 size 0x22: match (placed by p10_CMD).
 * p10_cmd_30 0x282894 size 0x3a: match (placed by p10_CMD).
 * p10_cmd_31 0x2828d0 size 0x3a: match (placed by p10_CMD).
 * p11_CMD 0x3324c8 size 0xe0: match (placed by player_CMD).
 * p11_CMD_20 0x2829e8 size 0x42: match (placed by p11_CMD).
 * p11_CMD_21 0x282a30 size 0x4a: match (placed by p11_CMD).
 * p11_CMD_22 0x282a80 size 0x42: match (placed by p11_CMD).
 * p11_cmd 0x3323e8 size 0xe0: match (placed by player_cmd).
 * p11_cmd_20 0x282910 size 0x42: match (placed by p11_cmd).
 * p11_cmd_21 0x282958 size 0x42: match (placed by p11_cmd).
 * p11_cmd_22 0x2829a0 size 0x42: match (placed by p11_cmd).
 * p11_cmd_28 0x282ac4 size 0x32: match (placed by p11_CMD).
 * p11_cmd_29 0x282af8 size 0x32: match (placed by p11_CMD).
 * p11_cmd_30 0x282b2c size 0x32: match (placed by p11_CMD).
 * p11_cmd_31 0x282b60 size 0x3a: match (placed by p11_CMD).
 * p11_cmd_46 0x282b9c size 0x32: match (placed by p11_CMD).
 * p12_CMD 0x332688 size 0xe0: match (placed by player_CMD).
 * p12_CMD_20 0x282ca8 size 0x42: match (placed by p12_CMD).
 * p12_CMD_21 0x282cf0 size 0x4a: match (placed by p12_CMD).
 * p12_CMD_22 0x282d40 size 0x42: match (placed by p12_CMD).
 * p12_cmd 0x3325a8 size 0xe0: match (placed by player_cmd).
 * p12_cmd_20 0x282bd0 size 0x42: match (placed by p12_cmd).
 * p12_cmd_21 0x282c18 size 0x42: match (placed by p12_cmd).
 * p12_cmd_22 0x282c60 size 0x42: match (placed by p12_cmd).
 * p12_cmd_28 0x282d84 size 0x2a: match (placed by p12_CMD).
 * p12_cmd_29 0x282db0 size 0x2a: match (placed by p12_CMD).
 * p12_cmd_30 0x282ddc size 0x32: match (placed by p12_CMD).
 * p12_cmd_31 0x282e10 size 0x3a: match (placed by p12_CMD).
 * p12_cmd_32 0x282e4c size 0x32: match (placed by p12_CMD).
 * p12_cmd_33 0x282e80 size 0x32: match (placed by p12_CMD).
 * p13_CMD 0x332848 size 0xe0: match (placed by player_CMD).
 * p13_CMD_20 0x282f90 size 0x42: match (placed by p13_CMD).
 * p13_CMD_21 0x282fd8 size 0x4a: match (placed by p13_CMD).
 * p13_CMD_38 0x283028 size 0x42: match (placed by p13_CMD).
 * p13_cmd 0x332768 size 0xe0: match (placed by player_cmd).
 * p13_cmd_20 0x282eb8 size 0x42: match (placed by p13_cmd).
 * p13_cmd_21 0x282f00 size 0x42: match (placed by p13_cmd).
 * p13_cmd_28 0x28306c size 0x32: match (placed by p13_CMD).
 * p13_cmd_29 0x2830a0 size 0x32: match (placed by p13_CMD).
 * p13_cmd_30 0x2830d4 size 0x32: match (placed by p13_CMD).
 * p13_cmd_38 0x282f48 size 0x42: match (placed by p13_cmd).
 * p13_cmd_46 0x283108 size 0x3a: match (placed by p13_CMD).
 * p13_cmd_47 0x283144 size 0x32: match (placed by p13_CMD).
 * p13_cmd_48 0x283178 size 0x32: match (placed by p13_CMD).
 * p13_cmd_49 0x2831ac size 0x3a: match (placed by p13_CMD).
 * p14_CMD 0x332a08 size 0xe0: match (placed by player_CMD).
 * p14_CMD_20 0x2832c0 size 0x42: match (placed by p14_CMD).
 * p14_CMD_21 0x283308 size 0x4a: match (placed by p14_CMD).
 * p14_CMD_22 0x283358 size 0x42: match (placed by p14_CMD).
 * p14_cmd 0x332928 size 0xe0: match (placed by player_cmd).
 * p14_cmd_20 0x2831e8 size 0x42: match (placed by p14_cmd).
 * p14_cmd_21 0x283230 size 0x42: match (placed by p14_cmd).
 * p14_cmd_22 0x283278 size 0x42: match (placed by p14_cmd).
 * p14_cmd_28 0x28339c size 0x2a: match (placed by p14_CMD).
 * p14_cmd_29 0x2833c8 size 0x2a: match (placed by p14_CMD).
 * p14_cmd_30 0x2833f4 size 0x2a: match (placed by p14_CMD).
 * p14_cmd_31 0x283420 size 0x32: match (placed by p14_CMD).
 * p1_CMD 0x330a88 size 0xe0: match (placed by player_CMD).
 * p1_CMD_20 0x27fd8c size 0x22: match (placed by p1_CMD).
 * p1_CMD_21 0x27fdb0 size 0x42: match (placed by p1_CMD).
 * p1_CMD_22 0x27fdf8 size 0x4a: match (placed by p1_CMD).
 * p1_cmd 0x3309a8 size 0xe0: match (placed by player_cmd).
 * p1_cmd_20 0x27fcdc size 0x22: match (placed by p1_cmd).
 * p1_cmd_21 0x27fd00 size 0x42: match (placed by p1_cmd).
 * p1_cmd_22 0x27fd48 size 0x42: match (placed by p1_cmd).
 * p1_cmd_28 0x27fe44 size 0x32: match (placed by p1_CMD).
 * p1_cmd_29 0x27fe78 size 0x32: match (placed by p1_CMD).
 * p1_cmd_30 0x27feac size 0x32: match (placed by p1_CMD).
 * p1_cmd_31 0x27fee0 size 0x2a: match (placed by p1_CMD).
 * p1_cmd_32 0x27ff0c size 0x2a: match (placed by p1_CMD).
 * p1_cmd_33 0x27ff38 size 0x32: match (placed by p1_CMD).
 * p2_CMD 0x330c48 size 0xe0: match (placed by player_CMD).
 * p2_CMD_20 0x280048 size 0x42: match (placed by p2_CMD).
 * p2_CMD_21 0x280090 size 0x4a: match (placed by p2_CMD).
 * p2_CMD_22 0x2800e0 size 0x42: match (placed by p2_CMD).
 * p2_cmd 0x330b68 size 0xe0: match (placed by player_cmd).
 * p2_cmd_20 0x27ff70 size 0x42: match (placed by p2_cmd).
 * p2_cmd_21 0x27ffb8 size 0x42: match (placed by p2_cmd).
 * p2_cmd_22 0x280000 size 0x42: match (placed by p2_cmd).
 * p2_cmd_28 0x280124 size 0x32: match (placed by p2_CMD).
 * p2_cmd_29 0x280158 size 0x32: match (placed by p2_CMD).
 * p2_cmd_30 0x28018c size 0x32: match (placed by p2_CMD).
 * p2_cmd_31 0x2801c0 size 0x3a: match (placed by p2_CMD).
 * p2_cmd_46 0x2801fc size 0x32: match (placed by p2_CMD).
 * p3_CMD 0x330e08 size 0xe0: match (placed by player_CMD).
 * p3_CMD_20 0x280308 size 0x4a: match (placed by p3_CMD).
 * p3_CMD_21 0x280358 size 0x42: match (placed by p3_CMD).
 * p3_CMD_22 0x2803a0 size 0x42: match (placed by p3_CMD).
 * p3_cmd 0x330d28 size 0xe0: match (placed by player_cmd).
 * p3_cmd_20 0x280230 size 0x42: match (placed by p3_cmd).
 * p3_cmd_21 0x280278 size 0x42: match (placed by p3_cmd).
 * p3_cmd_22 0x2802c0 size 0x42: match (placed by p3_cmd).
 * p3_cmd_28 0x2803e4 size 0x32: match (placed by p3_CMD).
 * p3_cmd_29 0x280418 size 0x32: match (placed by p3_CMD).
 * p3_cmd_30 0x28044c size 0x32: match (placed by p3_CMD).
 * p3_cmd_31 0x280480 size 0x32: match (placed by p3_CMD).
 * p3_cmd_32 0x2804b4 size 0x32: match (placed by p3_CMD).
 * p4_CMD 0x330fc8 size 0xe0: match (placed by player_CMD).
 * p4_CMD_20 0x2805c0 size 0x42: match (placed by p4_CMD).
 * p4_CMD_21 0x280608 size 0x42: match (placed by p4_CMD).
 * p4_CMD_22 0x280650 size 0x4a: match (placed by p4_CMD).
 * p4_cmd 0x330ee8 size 0xe0: match (placed by player_cmd).
 * p4_cmd_20 0x2804e8 size 0x42: match (placed by p4_cmd).
 * p4_cmd_21 0x280530 size 0x42: match (placed by p4_cmd).
 * p4_cmd_22 0x280578 size 0x42: match (placed by p4_cmd).
 * p4_cmd_28 0x28069c size 0x32: match (placed by p4_CMD).
 * p4_cmd_29 0x2806d0 size 0x42: match (placed by p4_CMD).
 * p4_cmd_30 0x280714 size 0x32: match (placed by p4_CMD).
 * p4_cmd_31 0x280748 size 0x32: match (placed by p4_CMD).
 * p4_cmd_32 0x28077c size 0x32: match (placed by p4_CMD).
 * p4_cmd_33 0x2807b0 size 0x32: match (placed by p4_CMD).
 * p5_CMD 0x331188 size 0xe0: match (placed by player_CMD).
 * p5_CMD_20 0x2808c0 size 0x42: match (placed by p5_CMD).
 * p5_CMD_21 0x280908 size 0x42: match (placed by p5_CMD).
 * p5_CMD_22 0x280950 size 0x4a: match (placed by p5_CMD).
 * p5_cmd 0x3310a8 size 0xe0: match (placed by player_cmd).
 * p5_cmd_20 0x2807e8 size 0x42: match (placed by p5_cmd).
 * p5_cmd_21 0x280830 size 0x42: match (placed by p5_cmd).
 * p5_cmd_22 0x280878 size 0x42: match (placed by p5_cmd).
 * p5_cmd_28 0x28099c size 0x3a: match (placed by p5_CMD).
 * p5_cmd_29 0x2809d8 size 0x32: match (placed by p5_CMD).
 * p5_cmd_30 0x280a0c size 0x3a: match (placed by p5_CMD).
 * p5_cmd_31 0x280a48 size 0x32: match (placed by p5_CMD).
 * p5_cmd_32 0x280a7c size 0x32: match (placed by p5_CMD).
 * p6_CMD 0x331348 size 0xe0: match (placed by player_CMD).
 * p6_CMD_20 0x280b6c size 0x2a: match (placed by p6_CMD).
 * p6_CMD_21 0x280b98 size 0x42: match (placed by p6_CMD).
 * p6_CMD_22 0x280be0 size 0x42: match (placed by p6_CMD).
 * p6_cmd 0x331268 size 0xe0: match (placed by player_cmd).
 * p6_cmd_20 0x280ab0 size 0x2a: match (placed by p6_cmd).
 * p6_cmd_21 0x280ae0 size 0x42: match (placed by p6_cmd).
 * p6_cmd_22 0x280b28 size 0x42: match (placed by p6_cmd).
 * p6_cmd_28 0x280c24 size 0x22: match (placed by p6_CMD).
 * p6_cmd_29 0x280c48 size 0x22: match (placed by p6_CMD).
 * p6_cmd_30 0x280c6c size 0x32: match (placed by p6_CMD).
 * p6_cmd_31 0x280ca0 size 0x32: match (placed by p6_CMD).
 * p6_cmd_32 0x280cd4 size 0x32: match (placed by p6_CMD).
 * p6_cmd_33 0x280d08 size 0x32: match (placed by p6_CMD).
 * p7_CMD 0x331508 size 0xe0: match (placed by player_CMD).
 * p7_CMD_20 0x280e18 size 0x42: match (placed by p7_CMD).
 * p7_CMD_21 0x280e60 size 0x42: match (placed by p7_CMD).
 * p7_CMD_38 0x280ea8 size 0x42: match (placed by p7_CMD).
 * p7_cmd 0x331428 size 0xe0: match (placed by player_cmd).
 * p7_cmd_20 0x280d40 size 0x42: match (placed by p7_cmd).
 * p7_cmd_21 0x280d88 size 0x42: match (placed by p7_cmd).
 * p7_cmd_28 0x280eec size 0x32: match (placed by p7_CMD).
 * p7_cmd_29 0x280f20 size 0x32: match (placed by p7_CMD).
 * p7_cmd_30 0x280f54 size 0x32: match (placed by p7_CMD).
 * p7_cmd_31 0x280f88 size 0x32: match (placed by p7_CMD).
 * p7_cmd_32 0x280fbc size 0x32: match (placed by p7_CMD).
 * p7_cmd_33 0x280ff0 size 0x32: match (placed by p7_CMD).
 * p7_cmd_34 0x281024 size 0x32: match (placed by p7_CMD).
 * p7_cmd_38 0x280dd0 size 0x42: match (placed by p7_cmd).
 * p7_cmd_46 0x281058 size 0x32: match (placed by p7_CMD).
 * p8_CMD 0x3316c8 size 0xe0: match (placed by player_CMD).
 * p8_CMD_20 0x281168 size 0x42: match (placed by p8_CMD).
 * p8_CMD_21 0x2811b0 size 0x4a: match (placed by p8_CMD).
 * p8_CMD_22 0x281200 size 0x42: match (placed by p8_CMD).
 * p8_cmd 0x3315e8 size 0xe0: match (placed by player_cmd).
 * p8_cmd_20 0x281090 size 0x42: match (placed by p8_cmd).
 * p8_cmd_21 0x2810d8 size 0x42: match (placed by p8_cmd).
 * p8_cmd_22 0x281120 size 0x42: match (placed by p8_cmd).
 * p8_cmd_28 0x281244 size 0x32: match (placed by p8_CMD).
 * p8_cmd_29 0x281278 size 0x32: match (placed by p8_CMD).
 * p8_cmd_30 0x2812ac size 0x32: match (placed by p8_CMD).
 * p8_cmd_31 0x2812e0 size 0x32: match (placed by p8_CMD).
 * p8_cmd_32 0x281314 size 0x32: match (placed by p8_CMD).
 * p9_CMD 0x331888 size 0xe0: match (placed by player_CMD).
 * p9_CMD_20 0x281420 size 0x42: match (placed by p9_CMD).
 * p9_CMD_21 0x281468 size 0x42: match (placed by p9_CMD).
 * p9_CMD_22 0x2814b0 size 0x4a: match (placed by p9_CMD).
 * p9_CMD_24 0x281548 size 0x42: match (placed by p9_CMD).
 * p9_cmd 0x3317a8 size 0xe0: match (placed by player_cmd).
 * p9_cmd_20 0x281348 size 0x42: match (placed by p9_cmd).
 * p9_cmd_21 0x281390 size 0x42: match (placed by p9_cmd).
 * p9_cmd_22 0x2813d8 size 0x42: match (placed by p9_cmd).
 * p9_cmd_24 0x281500 size 0x42: match (placed by p9_cmd).
 * p9_cmd_28 0x28158c size 0x2a: match (placed by p9_CMD).
 * p9_cmd_29 0x2815b8 size 0x32: match (placed by p9_CMD).
 * p9_cmd_30 0x2815ec size 0x2a: match (placed by p9_CMD).
 * p9_cmd_31 0x281618 size 0x32: match (placed by p9_CMD).
 * p9_cmd_46 0x28164c size 0x34: match (placed by p9_CMD).
 * p9_cmd_47 0x281680 size 0x32: match (placed by p9_CMD).
 * pA_CMD 0x331a48 size 0xe0: match (placed by player_CMD).
 * pA_CMD_20 0x281790 size 0x4a: match (placed by pA_CMD).
 * pA_CMD_21 0x2817e0 size 0x42: match (placed by pA_CMD).
 * pA_CMD_22 0x281828 size 0x42: match (placed by pA_CMD).
 * pA_cmd 0x331968 size 0xe0: match (placed by player_cmd).
 * pA_cmd_20 0x2816b8 size 0x42: match (placed by pA_cmd).
 * pA_cmd_21 0x281700 size 0x42: match (placed by pA_cmd).
 * pA_cmd_22 0x281748 size 0x42: match (placed by pA_cmd).
 * pA_cmd_28 0x28186c size 0x32: match (placed by pA_CMD).
 * pA_cmd_29 0x2818a0 size 0x32: match (placed by pA_CMD).
 * pA_cmd_30 0x2818d4 size 0x32: match (placed by pA_CMD).
 * pA_cmd_31 0x281908 size 0x32: match (placed by pA_CMD).
 * pA_cmd_32 0x28193c size 0x32: match (placed by pA_CMD).
 * pB_CMD 0x331c08 size 0xe0: match (placed by player_CMD).
 * pB_CMD_20 0x281a48 size 0x42: match (placed by pB_CMD).
 * pB_CMD_21 0x281a90 size 0x42: match (placed by pB_CMD).
 * pB_CMD_22 0x281ad8 size 0x4a: match (placed by pB_CMD).
 * pB_cmd 0x331b28 size 0xe0: match (placed by player_cmd).
 * pB_cmd_20 0x281970 size 0x42: match (placed by pB_cmd).
 * pB_cmd_21 0x2819b8 size 0x42: match (placed by pB_cmd).
 * pB_cmd_22 0x281a00 size 0x42: match (placed by pB_cmd).
 * pB_cmd_28 0x281b24 size 0x32: match (placed by pB_CMD).
 * pB_cmd_29 0x281b58 size 0x32: match (placed by pB_CMD).
 * pB_cmd_30 0x281b8c size 0x32: match (placed by pB_CMD).
 * pB_cmd_46 0x281bc0 size 0x32: match (placed by pB_CMD).
 * pC_CMD 0x331dc8 size 0xe0: match (placed by player_CMD).
 * pC_CMD_20 0x281cd0 size 0x4a: match (placed by pC_CMD).
 * pC_CMD_21 0x281d20 size 0x42: match (placed by pC_CMD).
 * pC_CMD_22 0x281d68 size 0x42: match (placed by pC_CMD).
 * pC_cmd 0x331ce8 size 0xe0: match (placed by player_cmd).
 * pC_cmd_20 0x281bf8 size 0x42: match (placed by pC_cmd).
 * pC_cmd_21 0x281c40 size 0x42: match (placed by pC_cmd).
 * pC_cmd_22 0x281c88 size 0x42: match (placed by pC_cmd).
 * pC_cmd_28 0x281dac size 0x32: match (placed by pC_CMD).
 * pC_cmd_29 0x281de0 size 0x32: match (placed by pC_CMD).
 * pC_cmd_30 0x281e14 size 0x32: match (placed by pC_CMD).
 * pC_cmd_31 0x281e48 size 0x32: match (placed by pC_CMD).
 * pC_cmd_32 0x281e7c size 0x32: match (placed by pC_CMD).
 * pD_CMD 0x331f88 size 0xe0: match (placed by player_CMD).
 * pD_CMD_20 0x281f88 size 0x42: match (placed by pD_CMD).
 * pD_CMD_21 0x281fd0 size 0x42: match (placed by pD_CMD).
 * pD_CMD_22 0x282018 size 0x4a: match (placed by pD_CMD).
 * pD_cmd 0x331ea8 size 0xe0: match (placed by player_cmd).
 * pD_cmd_20 0x281eb0 size 0x42: match (placed by pD_cmd).
 * pD_cmd_21 0x281ef8 size 0x42: match (placed by pD_cmd).
 * pD_cmd_22 0x281f40 size 0x42: match (placed by pD_cmd).
 * pD_cmd_28 0x282064 size 0x2a: match (placed by pD_CMD).
 * pD_cmd_29 0x282090 size 0x2a: match (placed by pD_CMD).
 * pD_cmd_30 0x2820bc size 0x32: match (placed by pD_CMD).
 * pD_cmd_31 0x2820f0 size 0x2a: match (placed by pD_CMD).
 * pE_CMD 0x332148 size 0xe0: match (placed by player_CMD).
 * pE_CMD_20 0x2821f8 size 0x42: match (placed by pE_CMD).
 * pE_CMD_21 0x282240 size 0x42: match (placed by pE_CMD).
 * pE_CMD_22 0x282288 size 0x4a: match (placed by pE_CMD).
 * pE_CMD_38 0x282590 size 0x42: match (placed by pE_CMD).
 * pE_CMD_39 0x2825d8 size 0x4a: match (placed by pE_CMD).
 * pE_cmd 0x332068 size 0xe0: match (placed by player_cmd).
 * pE_cmd_20 0x282120 size 0x42: match (placed by pE_cmd).
 * pE_cmd_21 0x282168 size 0x42: match (placed by pE_cmd).
 * pE_cmd_22 0x2821b0 size 0x42: match (placed by pE_cmd).
 * pE_cmd_24 0x2822d8 size 0x42: match (placed by pE_CMD).
 * pE_cmd_25 0x282320 size 0x42: match (placed by pE_CMD).
 * pE_cmd_28 0x282364 size 0x32: match (placed by pE_CMD).
 * pE_cmd_29 0x282398 size 0x32: match (placed by pE_CMD).
 * pE_cmd_30 0x2823cc size 0x32: match (placed by pE_CMD).
 * pE_cmd_31 0x282400 size 0x32: match (placed by pE_CMD).
 * pE_cmd_32 0x282434 size 0x32: match (placed by pE_CMD).
 * pE_cmd_33 0x282468 size 0x3a: match (placed by pE_CMD).
 * pE_cmd_34 0x2824a4 size 0x22: match (placed by pE_CMD).
 * pE_cmd_35 0x2824c8 size 0x32: match (placed by pE_CMD).
 * pE_cmd_38 0x282500 size 0x42: match (placed by pE_cmd).
 * pE_cmd_39 0x282548 size 0x42: match (placed by pE_cmd).
 * pE_cmd_46 0x282624 size 0x32: match (placed by pE_CMD).
 * pE_cmd_47 0x282658 size 0x32: match (placed by pE_CMD).
 * pc_cmd_00 0x27f850 size 0x3a: match (placed by p14_CMD).
 * pc_cmd_01 0x27f88c size 0x3a: match (placed by p14_CMD).
 * pc_cmd_02 0x27f8c8 size 0x2a: match (placed by p14_CMD).
 * pc_cmd_03 0x27f8f4 size 0x22: match (placed by p14_CMD).
 * pc_cmd_04 0x27f918 size 0x22: match (placed by p14_CMD).
 * pc_cmd_05 0x27f93c size 0x22: match (placed by p14_CMD).
 * pc_cmd_06 0x27f960 size 0x22: match (placed by p14_CMD).
 * pc_cmd_07 0x27f984 size 0x22: match (placed by p14_CMD).
 * pc_cmd_08 0x27f9a8 size 0x22: match (placed by p14_CMD).
 * pc_cmd_09 0x27f9cc size 0x22: match (placed by p14_CMD).
 * pc_cmd_10 0x27f9f0 size 0x22: match (placed by p14_CMD).
 * pc_cmd_11 0x27fa14 size 0x22: match (placed by p14_CMD).
 * pc_cmd_12 0x27fa38 size 0x22: match (placed by p14_CMD).
 * pc_cmd_13 0x27fa5c size 0x32: match (placed by p14_CMD).
 * pc_cmd_14 0x27fa90 size 0x32: match (placed by p14_CMD).
 * pc_cmd_15 0x27fac4 size 0x32: match (placed by p14_CMD).
 * pl_CMD 0x332b38 size 0x50: match.
 * pl_cmd 0x332ae8 size 0x50: match.
 * pl_cmd_num 0x27f738 size 0x118: match.
 * player_CMD 0x332bd8 size 0x50: match.
 * player_cmd 0x332b88 size 0x50: match.
 * ukemi_time_tbl 0x27f710 size 0x22: match.
 */

#include "structs.h"
#include <stddef.h>

/* from sf33rd/Source/Game/cmd_data.h */
typedef const s16* const_s16_arr;

// bss

WORK_CP wcp[2];
T_PL_LVR t_pl_lvr[2];
WAZA_WORK waza_work[2][56];

// sbss

s16 cmd_id;
s16* cmd_tbl_ptr;
u16 sw_work;
T_PL_LVR* chk_pl;
s16 waza_type[2];
WAZA_WORK* waza_ptr;
PLW* cmd_pl;

// rodata

const s16 ukemi_time_tbl[17] = { 0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 7 };

const s16 pl_cmd_num[20][7] = {
    { 16, 23, 26, 32, 38, 42, 46 }, { 16, 23, 24, 34, 38, 42, 46 }, { 16, 23, 24, 32, 38, 42, 47 },
    { 16, 23, 24, 33, 38, 42, 46 }, { 16, 23, 24, 34, 38, 42, 46 }, { 16, 23, 24, 33, 38, 42, 46 },
    { 16, 23, 24, 34, 38, 42, 46 }, { 16, 22, 24, 35, 39, 42, 47 }, { 16, 23, 24, 33, 38, 42, 46 },
    { 16, 23, 25, 32, 38, 42, 48 }, { 16, 23, 24, 33, 38, 42, 46 }, { 16, 23, 24, 31, 38, 42, 47 },
    { 16, 23, 24, 33, 38, 42, 46 }, { 16, 23, 24, 32, 38, 42, 46 }, { 16, 23, 26, 36, 40, 42, 48 },
    { 16, 23, 24, 32, 38, 42, 46 }, { 16, 23, 24, 32, 38, 42, 47 }, { 16, 23, 24, 34, 38, 42, 46 },
    { 16, 22, 24, 30, 39, 42, 50 }, { 16, 23, 24, 32, 38, 42, 46 }
};

const s16 pc_cmd_00[29] = { 8, 8, 2, 0, 0, 0,  0, 128, 0,      0,  0, 0, 1,      1, 1,
                            4, 1, 6, 0, 0, 20, 6, 0,   -32764, 19, 6, 6, -32764, 28 };

const s16 pc_cmd_01[29] = { 8, 4, 2, 0, 0, 0,  0, 128, 0,      0,  0, 0, 1,      1, 0,
                            8, 1, 6, 0, 0, 20, 6, 0,   -32760, 19, 6, 6, -32760, 28 };

const s16 pc_cmd_02[21] = { 8, 0, 0, 0, 0, 0, 0, 128, 0, 0, 0, 0, 25, 1, 0, 2, 25, 8, 0, 1, 28 };

const s16 pc_cmd_03[17] = { 11, 0, 0, 0, 0, 0, 0, 128, 0, 0, 0, 0, 11, 0, 0, 4, 28 };

const s16 pc_cmd_04[17] = { 11, 0, 0, 0, 0, 0, 0, 128, 0, 0, 0, 0, 11, 0, 0, 2, 28 };

const s16 pc_cmd_05[17] = { 8, 0, 0, 0, 0, 0, 0, 128, 0, 0, 0, 0, 11, 0, 0, 4, 28 };

const s16 pc_cmd_06[17] = { 8, 0, 0, 0, 0, 0, 0, 128, 0, 0, 0, 0, 11, 0, 0, 2, 28 };

const s16 pc_cmd_07[17] = { 2, 0, 0, 0, 0, 0, 0, 128, 0, 0, 0, 0, 24, 8, 0, 2, 28 };

const s16 pc_cmd_08[17] = { 7, 0, 0, 0, 1, 2, 3, 5, 0, 1, 2, 19, 15, 48, 48, 16, 28 };

const s16 pc_cmd_09[17] = { 11, 0, 0, 0, 1, 2, 3, 5, 0, 1, 2, 19, 15, 72, 72, 16, 28 };

const s16 pc_cmd_10[17] = { 7, 0, 0, 0, 1, 2, 3, 5, 4, 5, 6, 23, 15, 48, 48, 256, 28 };

const s16 pc_cmd_11[17] = { 11, 0, 0, 0, 1, 2, 3, 5, 4, 5, 6, 23, 15, 72, 72, 256, 28 };

const s16 pc_cmd_12[17] = { 6, 0, 0, 0, 0, 0, 0, 128, 0, 0, 0, 0, 11, 0, 0, 4, 28 };

const s16 pc_cmd_13[25] = { 4, 1, 0, 0, 0, 0, 0, 128, 0, 0, 0, 0, 22, 1, 1, -32766, 10, 6, 0, 0, 10, 6, 0, -32766, 28 };

const s16 pc_cmd_14[25] = { 12, 1, 0,      10, 10, 10, 10, 3,  0, 1, 2,      19, 22,
                            1,  1, -32766, 10, 6,  0,  0,  10, 6, 0, -32766, 28 };

const s16 pc_cmd_15[25] = { 12, 1, 0,      10, 10, 10, 10, 3,  4, 5, 6,      23, 22,
                            1,  1, -32766, 10, 6,  0,  0,  10, 6, 0, -32766, 28 };

const s16 dm_cmd_xx[25] = { 12, 0, 0,      0, 0,  0, 0,      5, 0,  1, 2,      19, 1,
                            0,  0, -32766, 1, 10, 0, -32762, 1, 10, 0, -32764, 28 };

const s16 p0_cmd_20[13] = { 12, 0, 0, 21, 21, 21, 21, 5, 0, 1, 2, 19, 21 };

const s16 p0_cmd_21[13] = { 12, 0, 0, 21, 21, 21, 21, 5, 0, 1, 2, 19, 21 };

const s16 p0_cmd_22[13] = { 12, 0, 0, 21, 21, 21, 21, 5, 0, 1, 2, 19, 21 };

const s16 p0_cmd_24[33] = { 12, 0, 0,      20, 20, 20, 20,     5, 0,  1, 2,      19, 1,  0, 0,      -32766, 1,
                            10, 0, -32762, 1,  10, 0,  -32764, 1, 14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 p0_cmd_25[33] = { 12, 0, 0,      22, 22, 22, 22,     5, 4,  5, 6,      23, 1,  0, 0,      -32766, 1,
                            10, 0, -32762, 1,  10, 0,  -32764, 1, 14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 p0_cmd_28[25] = { 12, 0, 0,      18, 18, 18, 18,     5, 0,  1, 2,      19, 27,
                            1,  0, -32764, 1,  5,  0,  -32766, 1, 10, 0, -32762, 28 };

const s16 p0_cmd_29[25] = {
    12, 0, 0, 17, 17, 17, 17, 5, 4, 5, 6, 23, 1, 0, 0, -32764, 1, 14, 0, 2, 1, 14, 0, -32760, 28
};

const s16 p0_cmd_30[25] = { 12, 1, 0,      16, 16, 16, 16,     2053, 0,  1, 2,      19, 1,
                            0,  0, -32766, 1,  10, 0,  -32762, 1,    10, 0, -32764, 28 };

const s16 p0_cmd_31[25] = { 12, 0, 0,      19, 19, 19, 19,     5, 0,  1, 2,      19, 1,
                            0,  0, -32766, 1,  10, 0,  -32758, 1, 10, 0, -32760, 28 };

const s16 p1_cmd_20[17] = { 12, 0, 0, 19, 19, 19, 19, 5, 0, 1, 2, 19, 7, 32, 32, 0, 28 };

const s16 p1_cmd_21[33] = { 12, 0, 0,      20, 20, 20, 20,     5, 0,  1, 2,      19, 1,  0, 0,      -32766, 1,
                            10, 0, -32762, 1,  10, 0,  -32764, 1, 14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 p1_cmd_22[33] = { 12, 0, 0,      21, 21, 21, 21,     5, 0,  1, 2,      19, 1,  0, 0,      -32766, 1,
                            10, 0, -32762, 1,  10, 0,  -32764, 1, 14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 p1_CMD_20[17] = { 12, 0, 0, 19, 19, 19, 19, 5, 0, 1, 2, 19, 7, 32, 32, 0, 28 };

const s16 p1_CMD_21[33] = { 12, 0, 0,      20, 20, 20, 20,     5, 0,  1, 2,      19, 1,  0, 0,      -32766, 1,
                            10, 0, -32762, 1,  10, 0,  -32764, 1, 14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 p1_CMD_22[37] = { 12, 0,  0, 21,     21, 21, 21, 5,      0, 1,  2, 19,     1, 0,  0, -32766, 1, 10, 0, -32758,
                            1,  10, 0, -32760, 1,  14, 0,  -32766, 1, 10, 0, -32758, 1, 10, 0, -32760, 28 };

const s16 p1_cmd_28[25] = { 12, 1, 0,      17, 17, 17, 17,     1029, 4,  5, 6,      23, 27,
                            1,  0, -32764, 1,  5,  0,  -32766, 1,    10, 0, -32762, 28 };

const s16 p1_cmd_29[25] = {
    12, 1, 0, 18, 18, 18, 18, 5, 0, 1, 2, 19, 1, 0, 0, -32764, 1, 14, 0, 2, 1, 14, 0, -32760, 28
};

const s16 p1_cmd_30[25] = { 12, 1, 0,      16, 16, 16, 16,     1029, 0,  1, 2,      19, 1,
                            0,  0, -32766, 1,  10, 0,  -32762, 1,    10, 0, -32764, 28 };

const s16 p1_cmd_31[21] = { 12, 0, 0, 22, 22, 22, 25, 1029, 4, 5, 6, 23, 2, 42, 42, 2, 1, 10, 0, 1, 28 };

const s16 p1_cmd_32[21] = { 12, 1, 0, 26, 26, 26, 26, 1029, 4, 5, 6, 23, 2, 42, 42, 8, 1, 10, 0, -32764, 28 };

const s16 p1_cmd_33[25] = {
    12, 1, 0, 24, 24, 24, 24, 5, 4, 5, 6, 23, 1, 0, 0, -32764, 1, 14, 0, 2, 1, 14, 0, -32760, 28
};

const s16 p2_cmd_20[33] = { 12, 0, 0,      19, 19, 19, 19,     5, 0,  1, 2,      19, 1,  0, 0,      -32766, 1,
                            10, 0, -32762, 1,  10, 0,  -32764, 1, 14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 p2_cmd_21[33] = { 12, 0, 0,      21, 21, 21, 21,     5, 0,  1, 2,      19, 1,  0, 0,      -32766, 1,
                            10, 0, -32762, 1,  10, 0,  -32764, 1, 14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 p2_cmd_22[33] = { 12, 0, 0,      20, 20, 20, 20,     5, 0,  1, 2,      19, 1,  0, 0,      -32766, 1,
                            10, 0, -32762, 1,  10, 0,  -32764, 1, 14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 p2_CMD_20[33] = { 12, 0, 0,      19, 19, 19, 19,     5, 0,  1, 2,      19, 1,  0, 0,      -32766, 1,
                            10, 0, -32762, 1,  10, 0,  -32764, 1, 14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 p2_CMD_21[37] = { 12, 0,  0, 21,     21, 21, 21, 5,      0, 1,  2, 19,     1, 0,  0, -32766, 1, 10, 0, -32758,
                            1,  10, 0, -32760, 1,  14, 0,  -32766, 1, 10, 0, -32758, 1, 10, 0, -32760, 28 };

const s16 p2_CMD_22[33] = { 12, 0, 0,      20, 20, 20, 20,     5, 4,  5, 6,      23, 1,  0, 0,      -32766, 1,
                            10, 0, -32762, 1,  10, 0,  -32764, 1, 14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 p2_cmd_28[25] = { 12, 1, 0,      17, 17, 17, 17,     1029, 0,  1, 2,      19, 27,
                            1,  0, -32764, 1,  5,  0,  -32766, 1,    10, 0, -32762, 28 };

const s16 p2_cmd_29[25] = { 12, 1, 0,      16, 16, 16, 16,     3077, 0,  1, 2,      19, 1,
                            0,  0, -32766, 1,  10, 0,  -32762, 1,    10, 0, -32764, 28 };

const s16 p2_cmd_30[25] = { 12, 1, 0,      18, 18, 18, 18,     1029, 4,  5, 6,      23, 1,
                            0,  0, -32766, 1,  10, 0,  -32758, 1,    10, 0, -32760, 28 };

const s16 p2_cmd_31[29] = { 12,     1, 0,  23, 23,     23, 23, 1029, 4,      5, 6,  23, 1,      0, 0,
                            -32760, 1, 10, 0,  -32758, 1,  10, 0,    -32766, 1, 10, 0,  -32762, 28 };

const s16 p2_cmd_46[25] = { 12, 1, 0,      22, 22, 22, 22,     1029, 4,  5, 6,      23, 1,
                            0,  0, -32766, 1,  10, 0,  -32758, 1,    10, 0, -32760, 28 };

const s16 p3_cmd_20[33] = { 12, 0, 0,      19, 19, 19, 19,     5, 0,  1, 2,      19, 1,  0, 0,      -32766, 1,
                            10, 0, -32762, 1,  10, 0,  -32764, 1, 14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 p3_cmd_21[33] = { 12, 0, 0,      20, 20, 20, 20,     5, 0,  1, 2,      19, 1,  0, 0,      -32766, 1,
                            10, 0, -32762, 1,  10, 0,  -32764, 1, 14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 p3_cmd_22[33] = { 12, 0, 0,      21, 21, 21, 21,     5, 0,  1, 2,      19, 1,  0, 0,      -32766, 1,
                            10, 0, -32762, 1,  10, 0,  -32764, 1, 14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 p3_CMD_20[37] = { 12, 0,  0, 19,     19, 19, 19, 5,      0, 1,  2, 19,     1, 0,  0, -32766, 1, 10, 0, -32758,
                            1,  10, 0, -32760, 1,  14, 0,  -32766, 1, 10, 0, -32758, 1, 10, 0, -32760, 28 };

const s16 p3_CMD_21[33] = { 12, 0, 0,      20, 20, 20, 20,     5, 4,  5, 6,      23, 1,  0, 0,      -32766, 1,
                            10, 0, -32762, 1,  10, 0,  -32764, 1, 14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 p3_CMD_22[33] = { 12, 0, 0,      21, 21, 21, 21,     5, 0,  1, 2,      19, 1,  0, 0,      -32766, 1,
                            10, 0, -32762, 1,  10, 0,  -32764, 1, 14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 p3_cmd_28[25] = {
    12, 1, 0, 22, 22, 22, 22, 5, 4, 5, 6, 23, 1, 0, 0, -32764, 1, 14, 0, 2, 1, 14, 0, -32760, 28
};

const s16 p3_cmd_29[25] = { 12, 1, 0,      24, 24, 24, 24,     1029, 0,  1, 2,      19, 27,
                            1,  0, -32764, 1,  5,  0,  -32766, 1,    10, 0, -32762, 28 };

const s16 p3_cmd_30[25] = { 12, 1, 0,      16, 16, 16, 16,     517, 0,  1, 2,      19, 1,
                            0,  0, -32766, 1,  10, 0,  -32758, 1,   10, 0, -32760, 28 };

const s16 p3_cmd_31[25] = { 12, 1, 0,      17, 17, 17, 17,     1029, 4,  5, 6,      23, 27,
                            1,  0, -32764, 1,  5,  0,  -32766, 1,    10, 0, -32762, 28 };

const s16 p3_cmd_32[25] = { 12, 1, 0,      18, 18, 18, 18,     1029, 0,  1, 2,      19, 1,
                            0,  0, -32766, 1,  10, 0,  -32762, 1,    10, 0, -32764, 28 };

const s16 p4_cmd_20[33] = { 12, 0, 0,      19, 19, 19, 19,     5, 0,  1, 2,      19, 1,  0, 0,      -32766, 1,
                            10, 0, -32762, 1,  10, 0,  -32764, 1, 14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 p4_cmd_21[33] = { 12, 0, 0,      20, 20, 20, 20,     5, 0,  1, 2,      19, 1,  0, 0,      -32766, 1,
                            10, 0, -32762, 1,  10, 0,  -32764, 1, 14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 p4_cmd_22[33] = { 12, 0, 0,      21, 21, 21, 21,     5, 0,  1, 2,      19, 1,  0, 0,      -32766, 1,
                            10, 0, -32762, 1,  10, 0,  -32764, 1, 14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 p4_CMD_20[33] = { 12, 0, 0,      19, 19, 19, 19,     5, 4,  5, 6,      23, 1,  0, 0,      -32766, 1,
                            10, 0, -32762, 1,  10, 0,  -32764, 1, 14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 p4_CMD_21[33] = { 12, 0, 0,      20, 20, 20, 20,     5, 0,  1, 2,      19, 1,  0, 0,      -32766, 1,
                            10, 0, -32762, 1,  10, 0,  -32764, 1, 14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 p4_CMD_22[37] = { 12, 0,  0, 21,     21, 21, 21, 5,      0, 1,  2, 19,     1, 0,  0, -32766, 1, 10, 0, -32758,
                            1,  10, 0, -32760, 1,  14, 0,  -32766, 1, 10, 0, -32758, 1, 10, 0, -32760, 28 };

const s16 p4_cmd_28[25] = { 12, 1, 0,      16, 16, 16, 16,     1029, 0,  1, 2,      19, 27,
                            1,  0, -32764, 1,  5,  0,  -32766, 1,    10, 0, -32762, 28 };

const s16 p4_cmd_29[33] = { 12, 1, 0, 25, 25, 25, 25,     1029, 0,  1, 2,      19, 1,  0, 0,      -32764, 1,
                            10, 0, 2, 1,  10, 0,  -32760, 1,    10, 0, -32768, 1,  10, 0, -32764, 28 };

const s16 p4_cmd_30[25] = { 12, 1, 0,      18, 18, 18, 18, 1029, 0,  1, 2,      19, 1,
                            0,  0, -32764, 1,  14, 0,  2,  1,    14, 0, -32760, 28 };

const s16 p4_cmd_31[25] = { 12, 1, 0,      17, 17, 17, 17, 1029, 0,  1, 2,      19, 1,
                            0,  0, -32760, 1,  14, 0,  2,  1,    14, 0, -32764, 28 };

const s16 p4_cmd_32[25] = {
    12, 1, 0, 22, 22, 22, 22, 5, 4, 5, 6, 23, 1, 0, 0, -32760, 1, 14, 0, 2, 1, 14, 0, -32764, 28
};

const s16 p4_cmd_33[25] = { 12, 1, 0,      22, 22, 22, 22, 1029, 4,  5, 6,      23, 1,
                            0,  0, -32764, 1,  14, 0,  2,  1,    14, 0, -32760, 28 };

const s16 p5_cmd_20[33] = { 12, 0, 0,      18, 18, 18, 18,     5, 0,  1, 2,      19, 1,  0, 0,      -32766, 1,
                            10, 0, -32762, 1,  10, 0,  -32764, 1, 14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 p5_cmd_21[33] = { 12, 0, 0,      20, 20, 20, 20,     5, 0,  1, 2,      19, 1,  0, 0,      -32766, 1,
                            10, 0, -32762, 1,  10, 0,  -32764, 1, 14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 p5_cmd_22[33] = { 12, 0, 0,      22, 22, 22, 22,     5, 0,  1, 2,      19, 1,  0, 0,      -32766, 1,
                            10, 0, -32762, 1,  10, 0,  -32764, 1, 14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 p5_CMD_20[33] = { 12, 0, 0,      18, 18, 18, 18,     5, 0,  1, 2,      19, 1,  0, 0,      -32766, 1,
                            10, 0, -32762, 1,  10, 0,  -32764, 1, 14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 p5_CMD_21[33] = { 12, 0, 0,      20, 20, 20, 20,     5, 4,  5, 6,      23, 1,  0, 0,      -32766, 1,
                            10, 0, -32762, 1,  10, 0,  -32764, 1, 14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 p5_CMD_22[37] = { 12, 0,  0, 22,     22, 22, 22, 5,      0, 1,  2, 19,     1, 0,  0, -32766, 1, 10, 0, -32758,
                            1,  10, 0, -32760, 1,  14, 0,  -32766, 1, 10, 0, -32758, 1, 10, 0, -32760, 28 };

const s16 p5_cmd_28[29] = { 12,     1, 0,  19, 19,     19, 19, 5, 4,      5, 6,  23, 1,      0, 0,
                            -32758, 1, 10, 0,  -32766, 1,  10, 0, -32762, 1, 10, 0,  -32764, 28 };

const s16 p5_cmd_29[25] = { 12, 0, 0,      17, 17, 17, 17,     5, 0,  1, 2,      19, 27,
                            1,  0, -32764, 1,  5,  0,  -32766, 1, 10, 0, -32762, 28 };

const s16 p5_cmd_30[29] = { 12,     1, 0,  16, 16,     16, 16, 1029, 0,      1, 2,  19, 1,      0, 0,
                            -32758, 1, 10, 0,  -32766, 1,  10, 0,    -32762, 1, 10, 0,  -32764, 28 };

const s16 p5_cmd_31[25] = { 12, 1, 0,      21, 21, 21, 25,     1029, 0,  1, 2,      19, 1,
                            0,  0, -32766, 1,  10, 0,  -32758, 1,    10, 0, -32760, 28 };

const s16 p5_cmd_32[25] = { 12, 1, 0,      24, 24, 24, 26,     1029, 4,  5, 6,      23, 1,
                            0,  0, -32766, 1,  10, 0,  -32758, 1,    10, 0, -32760, 28 };

const s16 p6_cmd_20[21] = { 12, 0, 0, 22, 22, 22, 22, 5, 0, 1, 2, 19, 7, 32, 32, 0, 7, 32, 32, 0, 28 };

const s16 p6_cmd_21[33] = { 12, 0, 0,      23, 23, 23, 23,     5, 4,  5, 6,      23, 1,  0, 0,      -32766, 1,
                            10, 0, -32762, 1,  10, 0,  -32764, 1, 14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 p6_cmd_22[33] = { 12, 0, 0,      21, 21, 21, 21,     5, 0,  1, 2,      19, 1,  0, 0,      -32766, 1,
                            10, 0, -32762, 1,  10, 0,  -32764, 1, 14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 p6_CMD_20[21] = { 12, 0, 0, 22, 22, 22, 22, 5, 0, 1, 2, 19, 7, 32, 32, 0, 7, 32, 32, 0, 28 };

const s16 p6_CMD_21[33] = { 12, 0, 0,      23, 23, 23, 23,     5, 4,  5, 6,      23, 1,  0, 0,      -32766, 1,
                            10, 0, -32762, 1,  10, 0,  -32764, 1, 14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 p6_CMD_22[33] = { 12, 0, 0,      21, 21, 21, 21,     5, 0,  1, 2,      19, 1,  0, 0,      -32766, 1,
                            10, 0, -32762, 1,  10, 0,  -32764, 1, 14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 p6_cmd_28[17] = { 12, 0, 0, 17, 17, 17, 17, 5, 0, 1, 2, 19, 7, 32, 32, 0, 28 };

const s16 p6_cmd_29[17] = { 12, 0, 0, 24, 24, 24, 24, 5, 4, 5, 6, 23, 7, 32, 32, 0, 28 };

const s16 p6_cmd_30[25] = { 12, 1, 0,      20, 20, 20, 20,     5, 4,  5, 6,      23, 27,
                            1,  0, -32764, 1,  5,  0,  -32766, 1, 10, 0, -32762, 28 };

const s16 p6_cmd_31[25] = { 12, 1, 0,      16, 16, 16, 16,     1029, 0,  1, 2,      19, 1,
                            0,  0, -32766, 1,  10, 0,  -32758, 1,    10, 0, -32760, 28 };

const s16 p6_cmd_32[25] = { 12, 1, 0,      18, 18, 18, 25,     1029, 4,  5, 6,      23, 1,
                            0,  0, -32766, 1,  10, 0,  -32762, 1,    10, 0, -32764, 28 };

const s16 p6_cmd_33[25] = {
    12, 1, 0, 19, 19, 19, 19, 5, 4, 5, 6, 23, 1, 0, 0, -32764, 1, 14, 0, 2, 1, 14, 0, -32760, 28
};

const s16 p7_cmd_20[33] = { 12, 0, 0,      19, 19, 19, 19,     5, 0,  1, 2,      19, 1,  0, 0,      -32766, 1,
                            10, 0, -32762, 1,  10, 0,  -32764, 1, 14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 p7_cmd_21[33] = { 12, 0, 0,      21, 21, 21, 21,     5, 0,  1, 2,      19, 1,  0, 0,      -32766, 1,
                            10, 0, -32762, 1,  10, 0,  -32764, 1, 14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 p7_cmd_38[33] = { 12, 0, 0,      24, 24, 24, 24,     5, 0,  1, 2,      19, 1,  0, 0,      -32766, 1,
                            10, 0, -32762, 1,  10, 0,  -32764, 1, 14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 p7_CMD_20[33] = { 12, 0, 0,      19, 19, 19, 19,     5, 4,  5, 6,      23, 1,  0, 0,      -32766, 1,
                            10, 0, -32762, 1,  10, 0,  -32764, 1, 14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 p7_CMD_21[33] = { 12, 0, 0,      21, 21, 21, 21,     5, 0,  1, 2,      19, 1,  0, 0,      -32766, 1,
                            10, 0, -32762, 1,  10, 0,  -32764, 1, 14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 p7_CMD_38[33] = { 12, 0, 0,      24, 24, 24, 24,     5, 0,  1, 2,      19, 1,  0, 0,      -32766, 1,
                            10, 0, -32762, 1,  10, 0,  -32764, 1, 14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 p7_cmd_28[25] = { 12, 1, 0,      16, 16, 16, 16,     1029, 4,  5, 6,      23, 27,
                            1,  0, -32764, 1,  5,  0,  -32766, 1,    10, 0, -32762, 28 };

const s16 p7_cmd_29[25] = {
    12, 1, 0, 18, 18, 18, 18, 5, 0, 1, 2, 19, 1, 0, 0, -32764, 1, 14, 0, 2, 1, 14, 0, -32760, 28
};

const s16 p7_cmd_30[25] = { 12, 1, 0,      22, 22, 22, 26,     1029, 4,  5, 6,      23, 1,
                            0,  0, -32760, 1,  10, 0,  -32766, 1,    10, 0, -32758, 28 };

const s16 p7_cmd_31[25] = { 12, 1, 0,      25, 25, 25, 25,     5, 0,  1, 2,      19, 27,
                            1,  0, -32764, 1,  5,  0,  -32766, 1, 10, 0, -32762, 28 };

const s16 p7_cmd_32[25] = { 12, 1, 0,      20, 20, 20, 20,     1029, 4,  5, 6,      23, 1,
                            0,  0, -32766, 1,  10, 0,  -32758, 1,    10, 0, -32760, 28 };

const s16 p7_cmd_33[25] = { 12, 1, 0,      17, 17, 17, 17,     1029, 0,  1, 2,      19, 1,
                            0,  0, -32766, 1,  10, 0,  -32762, 1,    10, 0, -32764, 28 };

const s16 p7_cmd_34[25] = { 12, 1, 0,      25, 25, 25, 25,     5, 4,  5, 6,      23, 1,
                            0,  0, -32766, 1,  10, 0,  -32762, 1, 10, 0, -32764, 28 };

const s16 p7_cmd_46[25] = { 12, 1, 0,      23, 23, 23, 23,     1029, 0,  1, 2,      19, 1,
                            0,  0, -32766, 1,  10, 0,  -32762, 1,    10, 0, -32764, 28 };

const s16 p8_cmd_20[33] = { 12, 0, 0,      19, 19, 19, 19,     5, 4,  5, 6,      23, 1,  0, 0,      -32766, 1,
                            10, 0, -32762, 1,  10, 0,  -32764, 1, 14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 p8_cmd_21[33] = { 12, 0, 0,      20, 20, 20, 20,     5, 4,  5, 6,      23, 1,  0, 0,      -32766, 1,
                            10, 0, -32762, 1,  10, 0,  -32764, 1, 14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 p8_cmd_22[33] = { 12, 0, 0,      21, 21, 21, 21,     5, 0,  1, 2,      19, 1,  0, 0,      -32766, 1,
                            10, 0, -32762, 1,  10, 0,  -32764, 1, 14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 p8_CMD_20[33] = { 12, 0, 0,      19, 19, 19, 19,     5, 4,  5, 6,      23, 1,  0, 0,      -32766, 1,
                            10, 0, -32762, 1,  10, 0,  -32764, 1, 14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 p8_CMD_21[37] = { 12, 0,  0, 20,     20, 20, 20, 5,      4, 5,  6, 23,     1, 0,  0, -32766, 1, 10, 0, -32758,
                            1,  10, 0, -32760, 1,  14, 0,  -32766, 1, 10, 0, -32758, 1, 10, 0, -32760, 28 };

const s16 p8_CMD_22[33] = { 12, 0, 0,      21, 21, 21, 21,     5, 0,  1, 2,      19, 1,  0, 0,      -32766, 1,
                            10, 0, -32762, 1,  10, 0,  -32764, 1, 14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 p8_cmd_28[25] = { 12, 1, 0,      16, 16, 16, 16,     1029, 4,  5, 6,      23, 27,
                            1,  0, -32764, 1,  5,  0,  -32766, 1,    10, 0, -32762, 28 };

const s16 p8_cmd_29[25] = { 12, 1, 0,      17, 17, 17, 17, 1029, 4,  5, 6,      23, 1,
                            0,  0, -32760, 1,  14, 0,  2,  1,    14, 0, -32764, 28 };

const s16 p8_cmd_30[25] = { 12, 1, 0,      18, 18, 18, 18, 1029, 0,  1, 2,      19, 1,
                            0,  0, -32764, 1,  14, 0,  2,  1,    14, 0, -32760, 28 };

const s16 p8_cmd_31[25] = { 12, 1, 0,      24, 24, 24, 24,     1029, 4,  5, 6,      23, 1,
                            0,  0, -32760, 1,  10, 0,  -32766, 1,    10, 0, -32758, 28 };

const s16 p8_cmd_32[25] = { 12, 1, 0,      23, 23, 23, 23,     1029, 4,  5, 6,      23, 1,
                            0,  0, -32766, 1,  10, 0,  -32758, 1,    10, 0, -32760, 28 };

const s16 p9_cmd_20[33] = { 12, 0, 0,      20, 20, 20, 27,     1029, 0,  1, 2,      19, 1,  0, 0,      -32766, 1,
                            10, 0, -32762, 1,  10, 0,  -32764, 1,    14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 p9_cmd_21[33] = { 12, 0, 0,      21, 21, 21, 21,     5, 0,  1, 2,      19, 1,  0, 0,      -32766, 1,
                            10, 0, -32762, 1,  10, 0,  -32764, 1, 14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 p9_cmd_22[33] = { 12, 0, 0,      22, 22, 22, 28,     1029, 0,  1, 2,      19, 1,  0, 0,      -32766, 1,
                            10, 0, -32762, 1,  10, 0,  -32764, 1,    14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 p9_CMD_20[33] = { 12, 0, 0,      20, 20, 20, 27,     1029, 4,  5, 6,      23, 1,  0, 0,      -32766, 1,
                            10, 0, -32762, 1,  10, 0,  -32764, 1,    14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 p9_CMD_21[33] = { 12, 0, 0,      21, 21, 21, 21,     5, 0,  1, 2,      19, 1,  0, 0,      -32766, 1,
                            10, 0, -32762, 1,  10, 0,  -32764, 1, 14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 p9_CMD_22[37] = { 12, 0,  0, 22,     22, 22, 28, 1029,   0, 1,  2, 19,     1, 0,  0, -32766, 1, 10, 0, -32758,
                            1,  10, 0, -32760, 1,  14, 0,  -32766, 1, 10, 0, -32758, 1, 10, 0, -32760, 28 };

const s16 p9_cmd_24[33] = { 12, 0, 0,      26, 26, 26, 26,     5, 3,  3, 3,      19, 1,  0, 0,      -32766, 1,
                            10, 0, -32762, 1,  10, 0,  -32764, 1, 14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 p9_CMD_24[33] = { 12, 0, 0,      26, 26, 26, 26,     5, 3,  3, 3,      19, 1,  0, 0,      -32766, 1,
                            10, 0, -32762, 1,  10, 0,  -32764, 1, 14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 p9_cmd_28[21] = { 12, 0, 0, 17, 17, 17, 17, 1029, 0, 1, 2, 19, 2, 42, 42, 2, 1, 10, 0, 1, 28 };

const s16 p9_cmd_29[25] = {
    12, 1, 0, 19, 19, 19, 19, 5, 0, 1, 2, 19, 1, 0, 0, -32764, 1, 14, 0, 2, 1, 14, 0, -32760, 28
};

const s16 p9_cmd_30[21] = { 12, 1, 0, 16, 16, 16, 16, 3077, 0, 1, 2, 19, 2, 42, 42, 8, 1, 10, 0, -32764, 28 };

const s16 p9_cmd_31[25] = { 12, 0, 0,      24, 24, 24, 25,     1029, 4,  5, 6,      23, 1,
                            0,  0, -32766, 1,  10, 0,  -32762, 1,    10, 0, -32764, 28 };

const s16 p9_cmd_46[26] = { 12, 1, 0, 18,     18, 18, 18, 5,      0, 1,  2, 19,     21,
                            1,  0, 0, -32766, 1,  10, 0,  -32762, 1, 10, 0, -32764, 28 };

const s16 p9_cmd_47[25] = { 12, 1, 0,      23, 23, 23, 23,     1029, 4,  5, 6,      23, 1,
                            0,  0, -32766, 1,  10, 0,  -32762, 1,    10, 0, -32764, 28 };

const s16 pA_cmd_20[33] = { 12, 0, 0,      19, 19, 19, 19,     5, 0,  1, 2,      19, 1,  0, 0,      -32766, 1,
                            10, 0, -32762, 1,  10, 0,  -32764, 1, 14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 pA_cmd_21[33] = { 12, 0, 0,      20, 20, 20, 20,     5, 0,  1, 2,      19, 1,  0, 0,      -32766, 1,
                            10, 0, -32762, 1,  10, 0,  -32764, 1, 14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 pA_cmd_22[33] = { 12, 0, 0,      21, 21, 21, 21,     5, 4,  5, 6,      23, 1,  0, 0,      -32766, 1,
                            10, 0, -32762, 1,  10, 0,  -32764, 1, 14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 pA_CMD_20[37] = { 12, 0,  0, 19,     19, 19, 19, 5,      0, 1,  2, 19,     1, 0,  0, -32766, 1, 10, 0, -32758,
                            1,  10, 0, -32760, 1,  14, 0,  -32766, 1, 10, 0, -32758, 1, 10, 0, -32760, 28 };

const s16 pA_CMD_21[33] = { 12, 0, 0,      20, 20, 20, 20,     5, 0,  1, 2,      19, 1,  0, 0,      -32766, 1,
                            10, 0, -32762, 1,  10, 0,  -32764, 1, 14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 pA_CMD_22[33] = { 12, 0, 0,      21, 21, 21, 21,     5, 4,  5, 6,      23, 1,  0, 0,      -32766, 1,
                            10, 0, -32762, 1,  10, 0,  -32764, 1, 14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 pA_cmd_28[25] = {
    12, 1, 0, 22, 22, 22, 22, 5, 4, 5, 6, 23, 1, 0, 0, -32764, 1, 14, 0, 2, 1, 14, 0, -32760, 28
};

const s16 pA_cmd_29[25] = { 12, 1, 0,      23, 23, 23, 23,     5, 4,  5, 6,      23, 27,
                            1,  0, -32764, 1,  5,  0,  -32766, 1, 10, 0, -32762, 28 };

const s16 pA_cmd_30[25] = { 12, 1, 0,      18, 18, 18, 18,     1029, 0,  1, 2,      19, 1,
                            0,  0, -32766, 1,  10, 0,  -32762, 1,    10, 0, -32764, 28 };

const s16 pA_cmd_31[25] = { 12, 1, 0,      17, 17, 17, 17,     1029, 4,  5, 6,      23, 1,
                            0,  0, -32766, 1,  10, 0,  -32762, 1,    10, 0, -32764, 28 };

const s16 pA_cmd_32[25] = { 12, 1, 0,      16, 16, 16, 16,     517, 0,  1, 2,      19, 1,
                            0,  0, -32766, 1,  10, 0,  -32758, 1,   10, 0, -32760, 28 };

const s16 pB_cmd_20[33] = { 12, 0, 0,      19, 19, 19, 19,     5, 0,  1, 2,      19, 1,  0, 0,      -32766, 1,
                            10, 0, -32762, 1,  10, 0,  -32764, 1, 14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 pB_cmd_21[33] = { 12, 0, 0,      20, 20, 20, 20,     5, 4,  5, 6,      23, 1,  0, 0,      -32766, 1,
                            10, 0, -32762, 1,  10, 0,  -32764, 1, 14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 pB_cmd_22[33] = { 12, 0, 0,      21, 21, 21, 21,     5, 4,  5, 6,      23, 1,  0, 0,      -32766, 1,
                            10, 0, -32762, 1,  10, 0,  -32764, 1, 14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 pB_CMD_20[33] = { 12, 0, 0,      19, 19, 19, 19,     5, 0,  1, 2,      19, 1,  0, 0,      -32766, 1,
                            10, 0, -32762, 1,  10, 0,  -32764, 1, 14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 pB_CMD_21[33] = { 12, 0, 0,      20, 20, 20, 20,     5, 4,  5, 6,      23, 1,  0, 0,      -32766, 1,
                            10, 0, -32762, 1,  10, 0,  -32764, 1, 14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 pB_CMD_22[37] = { 12, 0,  0, 21,     21, 21, 21, 5,      4, 5,  6, 23,     1, 0,  0, -32766, 1, 10, 0, -32758,
                            1,  10, 0, -32760, 1,  14, 0,  -32766, 1, 10, 0, -32758, 1, 10, 0, -32760, 28 };

const s16 pB_cmd_28[25] = { 12, 1, 0,      17, 17, 17, 17,     1029, 0,  1, 2,      19, 27,
                            1,  0, -32764, 1,  5,  0,  -32766, 1,    10, 0, -32762, 28 };

const s16 pB_cmd_29[25] = { 12, 1, 0,      16, 16, 16, 16,     3077, 0,  1, 2,      19, 1,
                            0,  0, -32766, 1,  10, 0,  -32762, 1,    10, 0, -32764, 28 };

const s16 pB_cmd_30[25] = { 12, 1, 0,      18, 18, 18, 18,     1029, 4,  5, 6,      23, 1,
                            0,  0, -32766, 1,  10, 0,  -32758, 1,    10, 0, -32760, 28 };

const s16 pB_cmd_46[25] = { 12, 1, 0,      22, 22, 22, 22,     1029, 4,  5, 6,      23, 1,
                            0,  0, -32766, 1,  10, 0,  -32758, 1,    10, 0, -32760, 28 };

const s16 pC_cmd_20[33] = { 12, 0, 0,      16, 16, 16, 16,     5, 0,  1, 2,      19, 1,  0, 0,      -32766, 1,
                            10, 0, -32762, 1,  10, 0,  -32764, 1, 14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 pC_cmd_21[33] = { 12, 0, 0,      17, 17, 17, 17,     5, 0,  1, 2,      19, 1,  0, 0,      -32766, 1,
                            10, 0, -32762, 1,  10, 0,  -32764, 1, 14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 pC_cmd_22[33] = { 12, 0, 0,      18, 18, 18, 18,     5, 0,  1, 2,      19, 1,  0, 0,      -32766, 1,
                            10, 0, -32762, 1,  10, 0,  -32764, 1, 14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 pC_CMD_20[37] = { 12, 0,  0, 16,     16, 16, 16, 5,      0, 1,  2, 19,     1, 0,  0, -32766, 1, 10, 0, -32758,
                            1,  10, 0, -32760, 1,  14, 0,  -32766, 1, 10, 0, -32758, 1, 10, 0, -32760, 28 };

const s16 pC_CMD_21[33] = { 12, 0, 0,      17, 17, 17, 17,     5, 0,  1, 2,      19, 1,  0, 0,      -32766, 1,
                            10, 0, -32762, 1,  10, 0,  -32764, 1, 14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 pC_CMD_22[33] = { 12, 0, 0,      18, 18, 18, 18,     5, 4,  5, 6,      23, 1,  0, 0,      -32766, 1,
                            10, 0, -32762, 1,  10, 0,  -32764, 1, 14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 pC_cmd_28[25] = { 12, 1, 0,      22, 22, 22, 22, 1029, 0,  1, 2,      19, 1,
                            0,  0, -32760, 1,  14, 0,  2,  1,    14, 0, -32764, 28 };

const s16 pC_cmd_29[25] = { 12, 1, 0,      24, 24, 24, 24,     1029, 0,  1, 2,      19, 27,
                            1,  0, -32764, 1,  5,  0,  -32766, 1,    10, 0, -32762, 28 };

const s16 pC_cmd_30[25] = { 12, 1, 0,      19, 19, 19, 25,     1029, 4,  5, 6,      23, 1,
                            0,  0, -32766, 1,  10, 0,  -32762, 1,    10, 0, -32764, 28 };

const s16 pC_cmd_31[25] = { 12, 1, 0,      20, 20, 20, 20,     5, 0,  1, 2,      19, 1,
                            0,  0, -32766, 1,  10, 0,  -32758, 1, 10, 0, -32760, 28 };

const s16 pC_cmd_32[25] = { 12, 1, 0,      21, 21, 21, 21,     1029, 4,  5, 6,      23, 1,
                            0,  0, -32766, 1,  10, 0,  -32758, 1,    10, 0, -32760, 28 };

const s16 pD_cmd_20[33] = { 12, 0, 0,      20, 20, 20, 20,     5, 0,  1, 2,      19, 1,  0, 0,      -32766, 1,
                            10, 0, -32762, 1,  10, 0,  -32764, 1, 14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 pD_cmd_21[33] = { 12, 0, 0,      21, 21, 21, 21,     5, 0,  1, 2,      19, 1,  0, 0,      -32766, 1,
                            10, 0, -32762, 1,  10, 0,  -32764, 1, 14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 pD_cmd_22[33] = { 12, 0, 0,      22, 22, 22, 22,     517, 0,  1, 2,      19, 1,  0, 0,      -32766, 1,
                            10, 0, -32762, 1,  10, 0,  -32764, 1,   14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 pD_CMD_20[33] = { 12, 0, 0,      20, 20, 20, 20,     5, 4,  5, 6,      23, 1,  0, 0,      -32766, 1,
                            10, 0, -32762, 1,  10, 0,  -32764, 1, 14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 pD_CMD_21[33] = { 12, 0, 0,      21, 21, 21, 21,     5, 0,  1, 2,      19, 1,  0, 0,      -32766, 1,
                            10, 0, -32762, 1,  10, 0,  -32764, 1, 14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 pD_CMD_22[37] = { 12, 0,  0, 22,     22, 22, 22, 517,    0, 1,  2, 19,     1, 0,  0, -32766, 1, 10, 0, -32758,
                            1,  10, 0, -32760, 1,  14, 0,  -32766, 1, 10, 0, -32758, 1, 10, 0, -32760, 28 };

const s16 pD_cmd_28[21] = { 12, 1, 0, 23, 23, 23, 23, 1029, 4, 5, 6, 23, 2, 42, 42, 8, 1, 10, 0, -32764, 28 };

const s16 pD_cmd_29[21] = { 12, 0, 0, 24, 24, 24, 17, 1029, 4, 5, 6, 23, 2, 42, 42, 2, 1, 10, 0, 1, 28 };

const s16 pD_cmd_30[25] = { 12, 1, 0,      16, 16, 16, 16,     3077, 0,  1, 2,      19, 1,
                            0,  0, -32766, 1,  10, 0,  -32762, 1,    10, 0, -32764, 28 };

const s16 pD_cmd_31[21] = { 12, 0, 0, 19, 19, 19, 19, 1029, 0, 1, 2, 19, 2, 42, 42, 2, 1, 10, 0, 1, 28 };

const s16 pE_cmd_20[33] = { 12, 0, 0,      16, 16, 16, 16,     5, 0,  1, 2,      19, 1,  0, 0,      -32766, 1,
                            10, 0, -32762, 1,  10, 0,  -32764, 1, 14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 pE_cmd_21[33] = { 12, 0, 0,      20, 20, 20, 20,     5, 0,  1, 2,      19, 1,  0, 0,      -32766, 1,
                            10, 0, -32762, 1,  10, 0,  -32764, 1, 14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 pE_cmd_22[33] = { 12, 0, 0,      17, 17, 17, 17,     5, 4,  5, 6,      23, 1,  0, 0,      -32766, 1,
                            10, 0, -32762, 1,  10, 0,  -32764, 1, 14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 pE_CMD_20[33] = { 12, 0, 0,      16, 16, 16, 16,     5, 0,  1, 2,      19, 1,  0, 0,      -32766, 1,
                            10, 0, -32762, 1,  10, 0,  -32764, 1, 14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 pE_CMD_21[33] = { 12, 0, 0,      20, 20, 20, 20,     5, 4,  5, 6,      23, 1,  0, 0,      -32766, 1,
                            10, 0, -32762, 1,  10, 0,  -32764, 1, 14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 pE_CMD_22[37] = { 12, 0,  0, 17,     17, 17, 17, 5,      4, 5,  6, 23,     1, 0,  0, -32766, 1, 10, 0, -32758,
                            1,  10, 0, -32760, 1,  14, 0,  -32766, 1, 10, 0, -32758, 1, 10, 0, -32760, 28 };

const s16 pE_cmd_24[33] = { 12, 0, 0, 24, 24, 24, 24, 259, 18, 18, 18, 18, 6,  0, 0,   16, 6,
                            10, 0, 0, 6,  10, 0,  16, 22,  16, 0,  4,  6,  10, 0, 256, 28 };

const s16 pE_cmd_25[33] = { 12, 0, 0, 26, 26, 26, 26,     5,  19, 19, 19, 19, 22, 1, 1,      -32766, 10,
                            6,  0, 0, 10, 6,  0,  -32766, 10, 6,  0,  0,  10, 6,  0, -32766, 28 };

const s16 pE_cmd_28[25] = { 12, 1, 0,      23, 23, 23, 23,     5, 19, 19, 23,     23, 27,
                            1,  0, -32764, 1,  5,  0,  -32766, 1, 10, 0,  -32762, 28 };

const s16 pE_cmd_29[25] = { 12, 1, 0,      23, 23, 23, 23,     5, 19, 19, 23,     23, 1,
                            0,  0, -32760, 1,  10, 0,  -32766, 1, 10, 0,  -32758, 28 };

const s16 pE_cmd_30[25] = { 12, 1, 0,      17, 17, 17, 17,     5, 0,  1, 2,      19, 27,
                            1,  0, -32764, 1,  5,  0,  -32766, 1, 10, 0, -32762, 28 };

const s16 pE_cmd_31[25] = { 12, 1, 0,      16, 16, 16, 16,     2053, 0,  1, 2,      19, 1,
                            0,  0, -32766, 1,  10, 0,  -32762, 1,    10, 0, -32764, 28 };

const s16 pE_cmd_32[25] = { 12, 1, 0,      18, 18, 18, 18,     5, 4,  5, 6,      23, 1,
                            0,  0, -32766, 1,  10, 0,  -32758, 1, 10, 0, -32760, 28 };

const s16 pE_cmd_33[29] = { 12,     1, 0,  16, 16,     16, 16, 2053, 0,      1, 2,  19, 1,      0, 0,
                            -32762, 1, 10, 0,  -32766, 1,  10, 0,    -32758, 1, 10, 0,  -32760, 28 };

const s16 pE_cmd_34[17] = { 12, 1, 0, 21, 21, 21, 21, 5, 4, 5, 6, 23, 21, 0, 0, -32764, 28 };

const s16 pE_cmd_35[25] = { 12, 1, 0,      27, 27, 27, 27,     5, 4,  5, 6,      23, 27,
                            1,  0, -32764, 1,  5,  0,  -32766, 1, 10, 0, -32762, 28 };

const s16 pE_cmd_38[33] = { 12, 0, 0,      25, 25, 25, 25,     5, 0,  1, 2,      19, 1,  0, 0,      -32766, 1,
                            10, 0, -32762, 1,  10, 0,  -32764, 1, 14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 pE_cmd_39[33] = { 12, 0, 0,      19, 19, 19, 19,     5, 4,  5, 6,      23, 1,  0, 0,      -32766, 1,
                            10, 0, -32762, 1,  10, 0,  -32764, 1, 14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 pE_CMD_38[33] = { 12, 0, 0,      25, 25, 25, 25,     5, 0,  1, 2,      19, 1,  0, 0,      -32766, 1,
                            10, 0, -32762, 1,  10, 0,  -32764, 1, 14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 pE_CMD_39[37] = { 12, 0,  0, 19,     19, 19, 19, 5,      4, 5,  6, 23,     1, 0,  0, -32766, 1, 10, 0, -32758,
                            1,  10, 0, -32760, 1,  14, 0,  -32766, 1, 10, 0, -32758, 1, 10, 0, -32760, 28 };

const s16 pE_cmd_46[25] = { 12, 1, 0,      25, 25, 25, 25,     2053, 0,  1, 2,      19, 1,
                            0,  0, -32766, 1,  10, 0,  -32762, 1,    10, 0, -32764, 28 };

const s16 pE_cmd_47[25] = { 12, 1, 0,      22, 22, 22, 22,     5, 4,  5, 6,      23, 1,
                            0,  0, -32766, 1,  10, 0,  -32758, 1, 10, 0, -32760, 28 };

const s16 p10_cmd_20[33] = { 12, 0, 0,      18, 18, 18, 18,     5, 0,  1, 2,      19, 1,  0, 0,      -32766, 1,
                             10, 0, -32762, 1,  10, 0,  -32764, 1, 14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 p10_cmd_21[33] = { 12, 0, 0,      20, 20, 20, 20,     5, 4,  5, 6,      23, 1,  0, 0,      -32766, 1,
                             10, 0, -32762, 1,  10, 0,  -32764, 1, 14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 p10_cmd_22[33] = { 12, 0, 0,      22, 22, 22, 22,     5, 4,  5, 6,      23, 1,  0, 0,      -32766, 1,
                             10, 0, -32762, 1,  10, 0,  -32764, 1, 14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 p10_CMD_20[33] = { 12, 0, 0,      18, 18, 18, 18,     5, 0,  1, 2,      19, 1,  0, 0,      -32766, 1,
                             10, 0, -32762, 1,  10, 0,  -32764, 1, 14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 p10_CMD_21[33] = { 12, 0, 0,      20, 20, 20, 20,     5, 4,  5, 6,      23, 1,  0, 0,      -32766, 1,
                             10, 0, -32762, 1,  10, 0,  -32764, 1, 14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 p10_CMD_22[37] = { 12, 0,      0,      22, 22, 22,     22,     5,  4,  5,      6,      23, 1,
                             0,  0,      -32766, 1,  10, 0,      -32758, 1,  10, 0,      -32760, 1,  14,
                             0,  -32766, 1,      10, 0,  -32758, 1,      10, 0,  -32760, 28 };

const s16 p10_cmd_28[21] = { 12, 0, 0, 16, 16, 16, 16, 1029, 4, 5, 6, 23, 2, 42, 42, 2, 1, 10, 0, 1, 28 };

const s16 p10_cmd_29[17] = { 10, 1, 0, 17, 17, 17, 17, 1029, 4, 5, 6, 23, 5, 98, 98, 256, 28 };

const s16 p10_cmd_30[29] = { 12,     1, 0,  19, 19,     19, 19, 3077, 0,      1, 2,  19, 1,      0, 0,
                             -32758, 1, 10, 0,  -32766, 1,  10, 0,    -32762, 1, 10, 0,  -32764, 28 };

const s16 p10_cmd_31[29] = { 12,     1, 0,  21, 21,     21, 21, 1029, 4,      5, 6,  23, 1,      0, 0,
                             -32762, 1, 10, 0,  -32766, 1,  10, 0,    -32758, 1, 10, 0,  -32760, 28 };

const s16 p11_cmd_20[33] = { 12, 0, 0,      17, 17, 17, 17,     5, 4,  5, 6,      23, 1,  0, 0,      -32766, 1,
                             10, 0, -32762, 1,  10, 0,  -32764, 1, 14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 p11_cmd_21[33] = { 12, 0, 0,      19, 19, 19, 19,     517, 0,  1, 2,      19, 1,  0, 0,      -32766, 1,
                             10, 0, -32762, 1,  10, 0,  -32764, 1,   14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 p11_cmd_22[33] = { 12, 0, 0,      18, 18, 18, 18,     5, 0,  1, 2,      19, 1,  0, 0,      -32766, 1,
                             10, 0, -32762, 1,  10, 0,  -32764, 1, 14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 p11_CMD_20[33] = { 12, 0, 0,      17, 17, 17, 17,     5, 4,  5, 6,      23, 1,  0, 0,      -32766, 1,
                             10, 0, -32762, 1,  10, 0,  -32764, 1, 14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 p11_CMD_21[37] = { 12, 0,      0,      19, 19, 19,     19,     517, 0,  1,      2,      19, 1,
                             0,  0,      -32766, 1,  10, 0,      -32758, 1,   10, 0,      -32760, 1,  14,
                             0,  -32766, 1,      10, 0,  -32758, 1,      10,  0,  -32760, 28 };

const s16 p11_CMD_22[33] = { 12, 0, 0,      18, 18, 18, 18,     5, 0,  1, 2,      19, 1,  0, 0,      -32766, 1,
                             10, 0, -32762, 1,  10, 0,  -32764, 1, 14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 p11_cmd_28[25] = { 12, 1, 0,      18, 18, 18, 18,     1029, 0,  1, 2,      19, 27,
                             1,  0, -32764, 1,  5,  0,  -32766, 1,    10, 0, -32762, 28 };

const s16 p11_cmd_29[25] = { 12, 1, 0,      18, 18, 18, 18,     1029, 0,  1, 2,      19, 1,
                             0,  0, -32766, 1,  10, 0,  -32758, 1,    10, 0, -32760, 28 };

const s16 p11_cmd_30[25] = { 12, 1, 0,      16, 16, 16, 16,     1029, 0,  1, 2,      19, 1,
                             0,  0, -32766, 1,  10, 0,  -32762, 1,    10, 0, -32764, 28 };

const s16 p11_cmd_31[29] = { 12,     1, 0,  16, 16,     16, 16, 5, 4,      5, 6,  23, 1,      0, 0,
                             -32762, 1, 10, 0,  -32766, 1,  10, 0, -32758, 1, 10, 0,  -32760, 28 };

const s16 p11_cmd_46[25] = { 12, 1, 0,      20, 20, 20, 20,     9221, 4,  5, 6,      23, 1,
                             0,  0, -32766, 1,  10, 0,  -32758, 1,    10, 0, -32760, 28 };

const s16 p12_cmd_20[33] = { 12, 0, 0,      20, 20, 20, 20,     5, 0,  1, 2,      19, 1,  0, 0,      -32766, 1,
                             10, 0, -32762, 1,  10, 0,  -32764, 1, 14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 p12_cmd_21[33] = { 12, 0, 0,      21, 21, 21, 21,     5, 0,  1, 2,      19, 1,  0, 0,      -32766, 1,
                             10, 0, -32762, 1,  10, 0,  -32764, 1, 14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 p12_cmd_22[33] = { 12, 0, 0,      22, 22, 22, 22,     5, 0,  1, 2,      19, 1,  0, 0,      -32766, 1,
                             10, 0, -32762, 1,  10, 0,  -32764, 1, 14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 p12_CMD_20[33] = { 12, 0, 0,      20, 20, 20, 20,     5, 0,  1, 2,      19, 1,  0, 0,      -32766, 1,
                             10, 0, -32762, 1,  10, 0,  -32764, 1, 14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 p12_CMD_21[37] = { 12, 0,      0,      21, 21, 21,     21,     5,  0,  1,      2,      19, 1,
                             0,  0,      -32766, 1,  10, 0,      -32758, 1,  10, 0,      -32760, 1,  14,
                             0,  -32766, 1,      10, 0,  -32758, 1,      10, 0,  -32760, 28 };

const s16 p12_CMD_22[33] = { 12, 0, 0,      22, 22, 22, 22,     5, 4,  5, 6,      23, 1,  0, 0,      -32766, 1,
                             10, 0, -32762, 1,  10, 0,  -32764, 1, 14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 p12_cmd_28[21] = { 12, 1, 0, 16, 16, 16, 16, 1029, 0, 1, 2, 19, 2, 42, 42, 8, 1, 10, 0, -32764, 28 };

const s16 p12_cmd_29[21] = { 12, 1, 0, 17, 17, 17, 17, 1029, 4, 5, 6, 23, 2, 42, 42, 8, 1, 10, 0, -32764, 28 };

const s16 p12_cmd_30[25] = { 12, 1, 0,      18, 18, 18, 18,     1029, 0,  1, 2,      19, 1,
                             0,  0, -32766, 1,  10, 0,  -32758, 1,    10, 0, -32760, 28 };

const s16 p12_cmd_31[29] = { 12,     1, 0,  19, 19,     19, 19, 5, 4,      5, 6,  23, 1,      0, 0,
                             -32762, 1, 10, 0,  -32766, 1,  10, 0, -32758, 1, 10, 0,  -32760, 28 };

const s16 p12_cmd_32[25] = { 12, 1, 0,      23, 23, 23, 23,     4101, 0,  1, 2,      19, 1,
                             0,  0, -32766, 1,  10, 0,  -32762, 1,    10, 0, -32764, 28 };

const s16 p12_cmd_33[25] = { 12, 1, 0,      24, 24, 24, 24,     4101, 4,  5, 6,      23, 1,
                             0,  0, -32766, 1,  10, 0,  -32762, 1,    10, 0, -32764, 28 };

const s16 p13_cmd_20[33] = { 12, 0, 0,      20, 20, 20, 20,     5, 0,  1, 2,      19, 1,  0, 0,      -32766, 1,
                             10, 0, -32762, 1,  10, 0,  -32764, 1, 14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 p13_cmd_21[33] = { 12, 0, 0,      22, 22, 22, 22,     5, 0,  1, 2,      19, 1,  0, 0,      -32766, 1,
                             10, 0, -32762, 1,  10, 0,  -32764, 1, 14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 p13_cmd_38[33] = { 12, 0, 0,      27, 27, 27, 27,     5, 4,  5, 6,      23, 1,  0, 0,      -32766, 1,
                             10, 0, -32762, 1,  10, 0,  -32764, 1, 14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 p13_CMD_20[33] = { 12, 0, 0,      20, 20, 20, 20,     5, 0,  1, 2,      19, 1,  0, 0,      -32766, 1,
                             10, 0, -32762, 1,  10, 0,  -32764, 1, 14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 p13_CMD_21[37] = { 12, 0,      0,      22, 22, 22,     22,     5,  0,  1,      2,      19, 1,
                             0,  0,      -32766, 1,  10, 0,      -32758, 1,  10, 0,      -32760, 1,  14,
                             0,  -32766, 1,      10, 0,  -32758, 1,      10, 0,  -32760, 28 };

const s16 p13_CMD_38[33] = { 12, 0, 0,      27, 27, 27, 27,     5, 4,  5, 6,      23, 1,  0, 0,      -32766, 1,
                             10, 0, -32762, 1,  10, 0,  -32764, 1, 14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 p13_cmd_28[25] = { 12, 0, 0,      16, 16, 16, 16,     1029, 0,  1, 2,      19, 1,
                             0,  0, -32766, 1,  10, 0,  -32758, 1,    10, 0, -32760, 28 };

const s16 p13_cmd_29[25] = { 12, 0, 0,      19, 19, 19, 19,     1029, 0,  1, 2,      19, 1,
                             0,  0, -32766, 1,  10, 0,  -32762, 1,    10, 0, -32764, 28 };

const s16 p13_cmd_30[25] = { 12, 0, 0,      19, 19, 19, 19,     1029, 4,  5, 6,      23, 1,
                             0,  0, -32766, 1,  10, 0,  -32762, 1,    10, 0, -32764, 28 };

const s16 p13_cmd_46[29] = { 8, 8, 2, 17, 17, 17, 17, 128, 0,      0,  0, 0, 1,      1, 1,
                             4, 1, 6, 0,  0,  20, 6,  0,   -32764, 19, 6, 6, -32764, 28 };

const s16 p13_cmd_47[25] = { 12, 1, 0,      18, 18, 18, 18,     1029, 4,  5, 6,      23, 1,
                             0,  0, -32766, 1,  10, 0,  -32758, 1,    10, 0, -32760, 28 };

const s16 p13_cmd_48[25] = { 12, 1, 0,      23, 23, 23, 23,     1029, 0,  1, 2,      19, 1,
                             0,  0, -32766, 1,  10, 0,  -32758, 1,    10, 0, -32760, 28 };

const s16 p13_cmd_49[29] = { 8, 4, 2, 17, 17, 17, 17, 128, 0,      0,  0, 0, 1,      1, 0,
                             8, 1, 6, 0,  0,  20, 6,  0,   -32760, 19, 6, 6, -32760, 28 };

const s16 p14_cmd_20[33] = { 12, 0, 0,      16, 16, 16, 16,     5, 0,  1, 2,      19, 1,  0, 0,      -32766, 1,
                             10, 0, -32762, 1,  10, 0,  -32764, 1, 14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 p14_cmd_21[33] = { 12, 0, 0,      20, 20, 20, 20,     5, 4,  5, 6,      23, 1,  0, 0,      -32766, 1,
                             10, 0, -32762, 1,  10, 0,  -32764, 1, 14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 p14_cmd_22[33] = { 12, 0, 0,      17, 17, 17, 17,     5, 4,  5, 6,      23, 1,  0, 0,      -32766, 1,
                             10, 0, -32762, 1,  10, 0,  -32764, 1, 14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 p14_CMD_20[33] = { 12, 0, 0,      16, 16, 16, 16,     5, 0,  1, 2,      19, 1,  0, 0,      -32766, 1,
                             10, 0, -32762, 1,  10, 0,  -32764, 1, 14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 p14_CMD_21[37] = { 12, 0,      0,      20, 20, 20,     20,     5,  4,  5,      6,      23, 1,
                             0,  0,      -32766, 1,  10, 0,      -32758, 1,  10, 0,      -32760, 1,  14,
                             0,  -32766, 1,      10, 0,  -32758, 1,      10, 0,  -32760, 28 };

const s16 p14_CMD_22[33] = { 12, 0, 0,      17, 17, 17, 17,     5, 4,  5, 6,      23, 1,  0, 0,      -32766, 1,
                             10, 0, -32762, 1,  10, 0,  -32764, 1, 14, 0, -32766, 1,  10, 0, -32762, 28 };

const s16 p14_cmd_28[21] = { 12, 0, 0, 17, 17, 17, 17, 1029, 4, 5, 6, 23, 2, 42, 42, 2, 1, 10, 0, 1, 28 };

const s16 p14_cmd_29[21] = { 12, 1, 0, 16, 16, 16, 16, 3077, 0, 1, 2, 19, 2, 42, 42, 8, 1, 10, 0, -32764, 28 };

const s16 p14_cmd_30[21] = { 12, 1, 0, 16, 16, 16, 16, 3077, 4, 5, 6, 23, 2, 42, 42, 8, 1, 10, 0, -32764, 28 };

const s16 p14_cmd_31[25] = { 12, 1, 0,      18, 18, 18, 18,     1029, 4,  5, 6,      23, 1,
                             0,  0, -32766, 1,  10, 0,  -32758, 1,    10, 0, -32760, 28 };

const u16 chk22_tbl[8] = { 1, 9, 8, 10, 2, 6, 4, 5 };

const s16 lever_gacha_tbl[16] = { 0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4 };

// data

const_s16_arr p0_cmd[56] = { pc_cmd_00, pc_cmd_01, pc_cmd_02, pc_cmd_03, pc_cmd_04, pc_cmd_05, pc_cmd_06, pc_cmd_07,
                             pc_cmd_08, pc_cmd_09, pc_cmd_10, pc_cmd_11, pc_cmd_12, pc_cmd_13, pc_cmd_14, pc_cmd_15,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, p0_cmd_20, p0_cmd_21, p0_cmd_22, dm_cmd_xx,
                             p0_cmd_24, p0_cmd_25, dm_cmd_xx, dm_cmd_xx, p0_cmd_28, p0_cmd_29, p0_cmd_30, p0_cmd_31,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx };

const_s16_arr p0_CMD[56] = { pc_cmd_00, pc_cmd_01, pc_cmd_02, pc_cmd_03, pc_cmd_04, pc_cmd_05, pc_cmd_06, pc_cmd_07,
                             pc_cmd_08, pc_cmd_09, pc_cmd_10, pc_cmd_11, pc_cmd_12, pc_cmd_13, pc_cmd_14, pc_cmd_15,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, p0_cmd_20, p0_cmd_21, p0_cmd_22, dm_cmd_xx,
                             p0_cmd_24, p0_cmd_25, dm_cmd_xx, dm_cmd_xx, p0_cmd_28, p0_cmd_29, p0_cmd_30, p0_cmd_31,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx };

const_s16_arr p1_cmd[56] = { pc_cmd_00, pc_cmd_01, pc_cmd_02, pc_cmd_03, pc_cmd_04, pc_cmd_05, pc_cmd_06, pc_cmd_07,
                             pc_cmd_08, pc_cmd_09, pc_cmd_10, pc_cmd_11, pc_cmd_12, pc_cmd_13, pc_cmd_14, pc_cmd_15,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, p1_cmd_20, p1_cmd_21, p1_cmd_22, dm_cmd_xx,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, p1_cmd_28, p1_cmd_29, p1_cmd_30, p1_cmd_31,
                             p1_cmd_32, p1_cmd_33, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx };

const_s16_arr p1_CMD[56] = { pc_cmd_00, pc_cmd_01, pc_cmd_02, pc_cmd_03, pc_cmd_04, pc_cmd_05, pc_cmd_06, pc_cmd_07,
                             pc_cmd_08, pc_cmd_09, pc_cmd_10, pc_cmd_11, pc_cmd_12, pc_cmd_13, pc_cmd_14, pc_cmd_15,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, p1_CMD_20, p1_CMD_21, p1_CMD_22, dm_cmd_xx,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, p1_cmd_28, p1_cmd_29, p1_cmd_30, p1_cmd_31,
                             p1_cmd_32, p1_cmd_33, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx };

const_s16_arr p2_cmd[56] = { pc_cmd_00, pc_cmd_01, pc_cmd_02, pc_cmd_03, pc_cmd_04, pc_cmd_05, pc_cmd_06, pc_cmd_07,
                             pc_cmd_08, pc_cmd_09, pc_cmd_10, pc_cmd_11, pc_cmd_12, pc_cmd_13, pc_cmd_14, pc_cmd_15,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, p2_cmd_20, p2_cmd_21, p2_cmd_22, dm_cmd_xx,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, p2_cmd_28, p2_cmd_29, p2_cmd_30, p2_cmd_31,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, p2_cmd_46, dm_cmd_xx,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx };

const_s16_arr p2_CMD[56] = { pc_cmd_00, pc_cmd_01, pc_cmd_02, pc_cmd_03, pc_cmd_04, pc_cmd_05, pc_cmd_06, pc_cmd_07,
                             pc_cmd_08, pc_cmd_09, pc_cmd_10, pc_cmd_11, pc_cmd_12, pc_cmd_13, pc_cmd_14, pc_cmd_15,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, p2_CMD_20, p2_CMD_21, p2_CMD_22, dm_cmd_xx,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, p2_cmd_28, p2_cmd_29, p2_cmd_30, p2_cmd_31,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, p2_cmd_46, dm_cmd_xx,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx };

const_s16_arr p3_cmd[56] = { pc_cmd_00, pc_cmd_01, pc_cmd_02, pc_cmd_03, pc_cmd_04, pc_cmd_05, pc_cmd_06, pc_cmd_07,
                             pc_cmd_08, pc_cmd_09, pc_cmd_10, pc_cmd_11, pc_cmd_12, pc_cmd_13, pc_cmd_14, pc_cmd_15,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, p3_cmd_20, p3_cmd_21, p3_cmd_22, dm_cmd_xx,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, p3_cmd_28, p3_cmd_29, p3_cmd_30, p3_cmd_31,
                             p3_cmd_32, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx };

const_s16_arr p3_CMD[56] = { pc_cmd_00, pc_cmd_01, pc_cmd_02, pc_cmd_03, pc_cmd_04, pc_cmd_05, pc_cmd_06, pc_cmd_07,
                             pc_cmd_08, pc_cmd_09, pc_cmd_10, pc_cmd_11, pc_cmd_12, pc_cmd_13, pc_cmd_14, pc_cmd_15,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, p3_CMD_20, p3_CMD_21, p3_CMD_22, dm_cmd_xx,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, p3_cmd_28, p3_cmd_29, p3_cmd_30, p3_cmd_31,
                             p3_cmd_32, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx };

const_s16_arr p4_cmd[56] = { pc_cmd_00, pc_cmd_01, pc_cmd_02, pc_cmd_03, pc_cmd_04, pc_cmd_05, pc_cmd_06, pc_cmd_07,
                             pc_cmd_08, pc_cmd_09, pc_cmd_10, pc_cmd_11, pc_cmd_12, pc_cmd_13, pc_cmd_14, pc_cmd_15,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, p4_cmd_20, p4_cmd_21, p4_cmd_22, dm_cmd_xx,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, p4_cmd_28, p4_cmd_29, p4_cmd_30, p4_cmd_31,
                             p4_cmd_32, p4_cmd_33, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx };

const_s16_arr p4_CMD[56] = { pc_cmd_00, pc_cmd_01, pc_cmd_02, pc_cmd_03, pc_cmd_04, pc_cmd_05, pc_cmd_06, pc_cmd_07,
                             pc_cmd_08, pc_cmd_09, pc_cmd_10, pc_cmd_11, pc_cmd_12, pc_cmd_13, pc_cmd_14, pc_cmd_15,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, p4_CMD_20, p4_CMD_21, p4_CMD_22, dm_cmd_xx,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, p4_cmd_28, p4_cmd_29, p4_cmd_30, p4_cmd_31,
                             p4_cmd_32, p4_cmd_33, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx };

const_s16_arr p5_cmd[56] = { pc_cmd_00, pc_cmd_01, pc_cmd_02, pc_cmd_03, pc_cmd_04, pc_cmd_05, pc_cmd_06, pc_cmd_07,
                             pc_cmd_08, pc_cmd_09, pc_cmd_10, pc_cmd_11, pc_cmd_12, pc_cmd_13, pc_cmd_14, pc_cmd_15,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, p5_cmd_20, p5_cmd_21, p5_cmd_22, dm_cmd_xx,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, p5_cmd_28, p5_cmd_29, p5_cmd_30, p5_cmd_31,
                             p5_cmd_32, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx };

const_s16_arr p5_CMD[56] = { pc_cmd_00, pc_cmd_01, pc_cmd_02, pc_cmd_03, pc_cmd_04, pc_cmd_05, pc_cmd_06, pc_cmd_07,
                             pc_cmd_08, pc_cmd_09, pc_cmd_10, pc_cmd_11, pc_cmd_12, pc_cmd_13, pc_cmd_14, pc_cmd_15,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, p5_CMD_20, p5_CMD_21, p5_CMD_22, dm_cmd_xx,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, p5_cmd_28, p5_cmd_29, p5_cmd_30, p5_cmd_31,
                             p5_cmd_32, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx };

const_s16_arr p6_cmd[56] = { pc_cmd_00, pc_cmd_01, pc_cmd_02, pc_cmd_03, pc_cmd_04, pc_cmd_05, pc_cmd_06, pc_cmd_07,
                             pc_cmd_08, pc_cmd_09, pc_cmd_10, pc_cmd_11, pc_cmd_12, pc_cmd_13, pc_cmd_14, pc_cmd_15,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, p6_cmd_20, p6_cmd_21, p6_cmd_22, dm_cmd_xx,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, p6_cmd_28, p6_cmd_29, p6_cmd_30, p6_cmd_31,
                             p6_cmd_32, p6_cmd_33, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx };

const_s16_arr p6_CMD[56] = { pc_cmd_00, pc_cmd_01, pc_cmd_02, pc_cmd_03, pc_cmd_04, pc_cmd_05, pc_cmd_06, pc_cmd_07,
                             pc_cmd_08, pc_cmd_09, pc_cmd_10, pc_cmd_11, pc_cmd_12, pc_cmd_13, pc_cmd_14, pc_cmd_15,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, p6_CMD_20, p6_CMD_21, p6_CMD_22, dm_cmd_xx,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, p6_cmd_28, p6_cmd_29, p6_cmd_30, p6_cmd_31,
                             p6_cmd_32, p6_cmd_33, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx };

const_s16_arr p7_cmd[56] = { pc_cmd_00, pc_cmd_01, pc_cmd_02, pc_cmd_03, pc_cmd_04, pc_cmd_05, pc_cmd_06, pc_cmd_07,
                             pc_cmd_08, pc_cmd_09, pc_cmd_10, pc_cmd_11, pc_cmd_12, pc_cmd_13, pc_cmd_14, pc_cmd_15,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, p7_cmd_20, p7_cmd_21, dm_cmd_xx, dm_cmd_xx,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, p7_cmd_28, p7_cmd_29, p7_cmd_30, p7_cmd_31,
                             p7_cmd_32, p7_cmd_33, p7_cmd_34, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, p7_cmd_38, dm_cmd_xx,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, p7_cmd_46, dm_cmd_xx,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx };

const_s16_arr p7_CMD[56] = { pc_cmd_00, pc_cmd_01, pc_cmd_02, pc_cmd_03, pc_cmd_04, pc_cmd_05, pc_cmd_06, pc_cmd_07,
                             pc_cmd_08, pc_cmd_09, pc_cmd_10, pc_cmd_11, pc_cmd_12, pc_cmd_13, pc_cmd_14, pc_cmd_15,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, p7_CMD_20, p7_CMD_21, dm_cmd_xx, dm_cmd_xx,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, p7_cmd_28, p7_cmd_29, p7_cmd_30, p7_cmd_31,
                             p7_cmd_32, p7_cmd_33, p7_cmd_34, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, p7_CMD_38, dm_cmd_xx,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, p7_cmd_46, dm_cmd_xx,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx };

const_s16_arr p8_cmd[56] = { pc_cmd_00, pc_cmd_01, pc_cmd_02, pc_cmd_03, pc_cmd_04, pc_cmd_05, pc_cmd_06, pc_cmd_07,
                             pc_cmd_08, pc_cmd_09, pc_cmd_10, pc_cmd_11, pc_cmd_12, pc_cmd_13, pc_cmd_14, pc_cmd_15,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, p8_cmd_20, p8_cmd_21, p8_cmd_22, dm_cmd_xx,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, p8_cmd_28, p8_cmd_29, p8_cmd_30, p8_cmd_31,
                             p8_cmd_32, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx };

const_s16_arr p8_CMD[56] = { pc_cmd_00, pc_cmd_01, pc_cmd_02, pc_cmd_03, pc_cmd_04, pc_cmd_05, pc_cmd_06, pc_cmd_07,
                             pc_cmd_08, pc_cmd_09, pc_cmd_10, pc_cmd_11, pc_cmd_12, pc_cmd_13, pc_cmd_14, pc_cmd_15,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, p8_CMD_20, p8_CMD_21, p8_CMD_22, dm_cmd_xx,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, p8_cmd_28, p8_cmd_29, p8_cmd_30, p8_cmd_31,
                             p8_cmd_32, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx };

const_s16_arr p9_cmd[56] = { pc_cmd_00, pc_cmd_01, pc_cmd_02, pc_cmd_03, pc_cmd_04, pc_cmd_05, pc_cmd_06, pc_cmd_07,
                             pc_cmd_08, pc_cmd_09, pc_cmd_10, pc_cmd_11, pc_cmd_12, pc_cmd_13, pc_cmd_14, pc_cmd_15,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, p9_cmd_20, p9_cmd_21, p9_cmd_22, dm_cmd_xx,
                             p9_cmd_24, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, p9_cmd_28, p9_cmd_29, p9_cmd_30, p9_cmd_31,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, p9_cmd_46, p9_cmd_47,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx };

const_s16_arr p9_CMD[56] = { pc_cmd_00, pc_cmd_01, pc_cmd_02, pc_cmd_03, pc_cmd_04, pc_cmd_05, pc_cmd_06, pc_cmd_07,
                             pc_cmd_08, pc_cmd_09, pc_cmd_10, pc_cmd_11, pc_cmd_12, pc_cmd_13, pc_cmd_14, pc_cmd_15,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, p9_CMD_20, p9_CMD_21, p9_CMD_22, dm_cmd_xx,
                             p9_CMD_24, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, p9_cmd_28, p9_cmd_29, p9_cmd_30, p9_cmd_31,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, p9_cmd_46, p9_cmd_47,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx };

const_s16_arr pA_cmd[56] = { pc_cmd_00, pc_cmd_01, pc_cmd_02, pc_cmd_03, pc_cmd_04, pc_cmd_05, pc_cmd_06, pc_cmd_07,
                             pc_cmd_08, pc_cmd_09, pc_cmd_10, pc_cmd_11, pc_cmd_12, pc_cmd_13, pc_cmd_14, pc_cmd_15,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, pA_cmd_20, pA_cmd_21, pA_cmd_22, dm_cmd_xx,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, pA_cmd_28, pA_cmd_29, pA_cmd_30, pA_cmd_31,
                             pA_cmd_32, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx };

const_s16_arr pA_CMD[56] = { pc_cmd_00, pc_cmd_01, pc_cmd_02, pc_cmd_03, pc_cmd_04, pc_cmd_05, pc_cmd_06, pc_cmd_07,
                             pc_cmd_08, pc_cmd_09, pc_cmd_10, pc_cmd_11, pc_cmd_12, pc_cmd_13, pc_cmd_14, pc_cmd_15,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, pA_CMD_20, pA_CMD_21, pA_CMD_22, dm_cmd_xx,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, pA_cmd_28, pA_cmd_29, pA_cmd_30, pA_cmd_31,
                             pA_cmd_32, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx };

const_s16_arr pB_cmd[56] = { pc_cmd_00, pc_cmd_01, pc_cmd_02, pc_cmd_03, pc_cmd_04, pc_cmd_05, pc_cmd_06, pc_cmd_07,
                             pc_cmd_08, pc_cmd_09, pc_cmd_10, pc_cmd_11, pc_cmd_12, pc_cmd_13, pc_cmd_14, pc_cmd_15,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, pB_cmd_20, pB_cmd_21, pB_cmd_22, dm_cmd_xx,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, pB_cmd_28, pB_cmd_29, pB_cmd_30, dm_cmd_xx,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, pB_cmd_46, dm_cmd_xx,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx };

const_s16_arr pB_CMD[56] = { pc_cmd_00, pc_cmd_01, pc_cmd_02, pc_cmd_03, pc_cmd_04, pc_cmd_05, pc_cmd_06, pc_cmd_07,
                             pc_cmd_08, pc_cmd_09, pc_cmd_10, pc_cmd_11, pc_cmd_12, pc_cmd_13, pc_cmd_14, pc_cmd_15,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, pB_CMD_20, pB_CMD_21, pB_CMD_22, dm_cmd_xx,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, pB_cmd_28, pB_cmd_29, pB_cmd_30, dm_cmd_xx,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, pB_cmd_46, dm_cmd_xx,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx };

const_s16_arr pC_cmd[56] = { pc_cmd_00, pc_cmd_01, pc_cmd_02, pc_cmd_03, pc_cmd_04, pc_cmd_05, pc_cmd_06, pc_cmd_07,
                             pc_cmd_08, pc_cmd_09, pc_cmd_10, pc_cmd_11, pc_cmd_12, pc_cmd_13, pc_cmd_14, pc_cmd_15,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, pC_cmd_20, pC_cmd_21, pC_cmd_22, dm_cmd_xx,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, pC_cmd_28, pC_cmd_29, pC_cmd_30, pC_cmd_31,
                             pC_cmd_32, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx };

const_s16_arr pC_CMD[56] = { pc_cmd_00, pc_cmd_01, pc_cmd_02, pc_cmd_03, pc_cmd_04, pc_cmd_05, pc_cmd_06, pc_cmd_07,
                             pc_cmd_08, pc_cmd_09, pc_cmd_10, pc_cmd_11, pc_cmd_12, pc_cmd_13, pc_cmd_14, pc_cmd_15,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, pC_CMD_20, pC_CMD_21, pC_CMD_22, dm_cmd_xx,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, pC_cmd_28, pC_cmd_29, pC_cmd_30, pC_cmd_31,
                             pC_cmd_32, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx };

const_s16_arr pD_cmd[56] = { pc_cmd_00, pc_cmd_01, pc_cmd_02, pc_cmd_03, pc_cmd_04, pc_cmd_05, pc_cmd_06, pc_cmd_07,
                             pc_cmd_08, pc_cmd_09, pc_cmd_10, pc_cmd_11, pc_cmd_12, pc_cmd_13, pc_cmd_14, pc_cmd_15,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, pD_cmd_20, pD_cmd_21, pD_cmd_22, dm_cmd_xx,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, pD_cmd_28, pD_cmd_29, pD_cmd_30, pD_cmd_31,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx };

const_s16_arr pD_CMD[56] = { pc_cmd_00, pc_cmd_01, pc_cmd_02, pc_cmd_03, pc_cmd_04, pc_cmd_05, pc_cmd_06, pc_cmd_07,
                             pc_cmd_08, pc_cmd_09, pc_cmd_10, pc_cmd_11, pc_cmd_12, pc_cmd_13, pc_cmd_14, pc_cmd_15,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, pD_CMD_20, pD_CMD_21, pD_CMD_22, dm_cmd_xx,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, pD_cmd_28, pD_cmd_29, pD_cmd_30, pD_cmd_31,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx };

const_s16_arr pE_cmd[56] = { pc_cmd_00, pc_cmd_01, pc_cmd_02, pc_cmd_03, pc_cmd_04, pc_cmd_05, pc_cmd_06, pc_cmd_07,
                             pc_cmd_08, pc_cmd_09, pc_cmd_10, pc_cmd_11, pc_cmd_12, pc_cmd_13, pc_cmd_14, pc_cmd_15,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, pE_cmd_20, pE_cmd_21, pE_cmd_22, dm_cmd_xx,
                             pE_cmd_24, pE_cmd_25, dm_cmd_xx, dm_cmd_xx, pE_cmd_28, pE_cmd_29, pE_cmd_30, pE_cmd_31,
                             pE_cmd_32, pE_cmd_33, pE_cmd_34, pE_cmd_35, dm_cmd_xx, dm_cmd_xx, pE_cmd_38, pE_cmd_39,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, pE_cmd_46, pE_cmd_47,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx };

const_s16_arr pE_CMD[56] = { pc_cmd_00, pc_cmd_01, pc_cmd_02, pc_cmd_03, pc_cmd_04, pc_cmd_05, pc_cmd_06, pc_cmd_07,
                             pc_cmd_08, pc_cmd_09, pc_cmd_10, pc_cmd_11, pc_cmd_12, pc_cmd_13, pc_cmd_14, pc_cmd_15,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, pE_CMD_20, pE_CMD_21, pE_CMD_22, dm_cmd_xx,
                             pE_cmd_24, pE_cmd_25, dm_cmd_xx, dm_cmd_xx, pE_cmd_28, pE_cmd_29, pE_cmd_30, pE_cmd_31,
                             pE_cmd_32, pE_cmd_33, pE_cmd_34, pE_cmd_35, dm_cmd_xx, dm_cmd_xx, pE_CMD_38, pE_CMD_39,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, pE_cmd_46, pE_cmd_47,
                             dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx };

const_s16_arr p10_cmd[56] = { pc_cmd_00,  pc_cmd_01,  pc_cmd_02,  pc_cmd_03,  pc_cmd_04, pc_cmd_05, pc_cmd_06,
                              pc_cmd_07,  pc_cmd_08,  pc_cmd_09,  pc_cmd_10,  pc_cmd_11, pc_cmd_12, pc_cmd_13,
                              pc_cmd_14,  pc_cmd_15,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx, dm_cmd_xx, p10_cmd_20,
                              p10_cmd_21, p10_cmd_22, dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
                              p10_cmd_28, p10_cmd_29, p10_cmd_30, p10_cmd_31, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
                              dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
                              dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
                              dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx, dm_cmd_xx, dm_cmd_xx };

const_s16_arr p10_CMD[56] = { pc_cmd_00,  pc_cmd_01,  pc_cmd_02,  pc_cmd_03,  pc_cmd_04, pc_cmd_05, pc_cmd_06,
                              pc_cmd_07,  pc_cmd_08,  pc_cmd_09,  pc_cmd_10,  pc_cmd_11, pc_cmd_12, pc_cmd_13,
                              pc_cmd_14,  pc_cmd_15,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx, dm_cmd_xx, p10_CMD_20,
                              p10_CMD_21, p10_CMD_22, dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
                              p10_cmd_28, p10_cmd_29, p10_cmd_30, p10_cmd_31, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
                              dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
                              dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
                              dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx, dm_cmd_xx, dm_cmd_xx };

const_s16_arr p11_cmd[56] = { pc_cmd_00,  pc_cmd_01,  pc_cmd_02,  pc_cmd_03,  pc_cmd_04,  pc_cmd_05, pc_cmd_06,
                              pc_cmd_07,  pc_cmd_08,  pc_cmd_09,  pc_cmd_10,  pc_cmd_11,  pc_cmd_12, pc_cmd_13,
                              pc_cmd_14,  pc_cmd_15,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx, p11_cmd_20,
                              p11_cmd_21, p11_cmd_22, dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx, dm_cmd_xx,
                              p11_cmd_28, p11_cmd_29, p11_cmd_30, p11_cmd_31, dm_cmd_xx,  dm_cmd_xx, dm_cmd_xx,
                              dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx, dm_cmd_xx,
                              dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  p11_cmd_46, dm_cmd_xx, dm_cmd_xx,
                              dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx, dm_cmd_xx };

const_s16_arr p11_CMD[56] = { pc_cmd_00,  pc_cmd_01,  pc_cmd_02,  pc_cmd_03,  pc_cmd_04,  pc_cmd_05, pc_cmd_06,
                              pc_cmd_07,  pc_cmd_08,  pc_cmd_09,  pc_cmd_10,  pc_cmd_11,  pc_cmd_12, pc_cmd_13,
                              pc_cmd_14,  pc_cmd_15,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx, p11_CMD_20,
                              p11_CMD_21, p11_CMD_22, dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx, dm_cmd_xx,
                              p11_cmd_28, p11_cmd_29, p11_cmd_30, p11_cmd_31, dm_cmd_xx,  dm_cmd_xx, dm_cmd_xx,
                              dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx, dm_cmd_xx,
                              dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  p11_cmd_46, dm_cmd_xx, dm_cmd_xx,
                              dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx, dm_cmd_xx };

const_s16_arr p12_cmd[56] = { pc_cmd_00,  pc_cmd_01,  pc_cmd_02,  pc_cmd_03,  pc_cmd_04,  pc_cmd_05,  pc_cmd_06,
                              pc_cmd_07,  pc_cmd_08,  pc_cmd_09,  pc_cmd_10,  pc_cmd_11,  pc_cmd_12,  pc_cmd_13,
                              pc_cmd_14,  pc_cmd_15,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  p12_cmd_20,
                              p12_cmd_21, p12_cmd_22, dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,
                              p12_cmd_28, p12_cmd_29, p12_cmd_30, p12_cmd_31, p12_cmd_32, p12_cmd_33, dm_cmd_xx,
                              dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,
                              dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,
                              dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx };

const_s16_arr p12_CMD[56] = { pc_cmd_00,  pc_cmd_01,  pc_cmd_02,  pc_cmd_03,  pc_cmd_04,  pc_cmd_05,  pc_cmd_06,
                              pc_cmd_07,  pc_cmd_08,  pc_cmd_09,  pc_cmd_10,  pc_cmd_11,  pc_cmd_12,  pc_cmd_13,
                              pc_cmd_14,  pc_cmd_15,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  p12_CMD_20,
                              p12_CMD_21, p12_CMD_22, dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,
                              p12_cmd_28, p12_cmd_29, p12_cmd_30, p12_cmd_31, p12_cmd_32, p12_cmd_33, dm_cmd_xx,
                              dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,
                              dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,
                              dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx };

const_s16_arr p13_cmd[56] = { pc_cmd_00,  pc_cmd_01,  pc_cmd_02,  pc_cmd_03,  pc_cmd_04,  pc_cmd_05,  pc_cmd_06,
                              pc_cmd_07,  pc_cmd_08,  pc_cmd_09,  pc_cmd_10,  pc_cmd_11,  pc_cmd_12,  pc_cmd_13,
                              pc_cmd_14,  pc_cmd_15,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  p13_cmd_20,
                              p13_cmd_21, dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,
                              p13_cmd_28, p13_cmd_29, p13_cmd_30, dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,
                              dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  p13_cmd_38, dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,
                              dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  p13_cmd_46, p13_cmd_47, p13_cmd_48,
                              p13_cmd_49, dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx };

const_s16_arr p13_CMD[56] = { pc_cmd_00,  pc_cmd_01,  pc_cmd_02,  pc_cmd_03,  pc_cmd_04,  pc_cmd_05,  pc_cmd_06,
                              pc_cmd_07,  pc_cmd_08,  pc_cmd_09,  pc_cmd_10,  pc_cmd_11,  pc_cmd_12,  pc_cmd_13,
                              pc_cmd_14,  pc_cmd_15,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  p13_CMD_20,
                              p13_CMD_21, dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,
                              p13_cmd_28, p13_cmd_29, p13_cmd_30, dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,
                              dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  p13_CMD_38, dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,
                              dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  p13_cmd_46, p13_cmd_47, p13_cmd_48,
                              p13_cmd_49, dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx };

const_s16_arr p14_cmd[56] = { pc_cmd_00,  pc_cmd_01,  pc_cmd_02,  pc_cmd_03,  pc_cmd_04, pc_cmd_05, pc_cmd_06,
                              pc_cmd_07,  pc_cmd_08,  pc_cmd_09,  pc_cmd_10,  pc_cmd_11, pc_cmd_12, pc_cmd_13,
                              pc_cmd_14,  pc_cmd_15,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx, dm_cmd_xx, p14_cmd_20,
                              p14_cmd_21, p14_cmd_22, dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
                              p14_cmd_28, p14_cmd_29, p14_cmd_30, p14_cmd_31, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
                              dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
                              dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
                              dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx, dm_cmd_xx, dm_cmd_xx };

const_s16_arr p14_CMD[56] = { pc_cmd_00,  pc_cmd_01,  pc_cmd_02,  pc_cmd_03,  pc_cmd_04, pc_cmd_05, pc_cmd_06,
                              pc_cmd_07,  pc_cmd_08,  pc_cmd_09,  pc_cmd_10,  pc_cmd_11, pc_cmd_12, pc_cmd_13,
                              pc_cmd_14,  pc_cmd_15,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx, dm_cmd_xx, p14_CMD_20,
                              p14_CMD_21, p14_CMD_22, dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
                              p14_cmd_28, p14_cmd_29, p14_cmd_30, p14_cmd_31, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
                              dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
                              dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
                              dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx,  dm_cmd_xx, dm_cmd_xx, dm_cmd_xx };

// sdata

void* pl_cmd[20] = { p0_cmd, p1_cmd, p2_cmd, p3_cmd, p4_cmd, p5_cmd,  p6_cmd,  p7_cmd,  p8_cmd,  p9_cmd,
                     pA_cmd, pB_cmd, pC_cmd, pD_cmd, pE_cmd, p10_cmd, p11_cmd, p12_cmd, p13_cmd, p14_cmd };

void* pl_CMD[20] = { p0_CMD, p1_CMD, p2_CMD, p3_CMD, p4_CMD, p5_CMD,  p6_CMD,  p7_CMD,  p8_CMD,  p9_CMD,
                     pA_CMD, pB_CMD, pC_CMD, pD_CMD, pE_CMD, p10_CMD, p11_CMD, p12_CMD, p13_CMD, p14_CMD };

const_s16_arr* player_cmd[20] = { p0_cmd, p1_cmd, p2_cmd, p3_cmd, p4_cmd, p5_cmd,  p6_cmd,  p7_cmd,  p8_cmd,  p9_cmd,
                                  pA_cmd, pB_cmd, pC_cmd, pD_cmd, pE_cmd, p10_cmd, p11_cmd, p12_cmd, p13_cmd, p14_cmd };

const_s16_arr* player_CMD[20] = { p0_CMD, p1_CMD, p2_CMD, p3_CMD, p4_CMD, p5_CMD,  p6_CMD,  p7_CMD,  p8_CMD,  p9_CMD,
                                  pA_CMD, pB_CMD, pC_CMD, pD_CMD, pE_CMD, p10_CMD, p11_CMD, p12_CMD, p13_CMD, p14_CMD };

s16 lvr_chk_tbl[2][4] = { { 5, 6, 9, 10 }, { 1, 2, 4, 8 } };
