/* Option direction setup, retail sf33rd.xbe.
 * init_omop is 0x9CC94 size 0x10D, interior after the ret.
 * Mode_Type is 0x7A825A. Demo_Flag is 0x7A842D. Present_Mode is 0x7A819C.
 * Direction_Working is 0x7A82D8. system_dir is 0x7C59E0, stride 0x48.
 * save_w is 0x7BD3E0, stride 0x208, and extra_option is at +0x54.
 * omop_spmv_ng_table is 0xC7D8D8. omop_spmv_ng_table2 is 0xC7D9C8.
 * The two ORs into table2[0] fold into one store of 0xC00000.
 * sysdir_base_move is 0x268408 and matches the 20 PlayStation 2 dwords.
 * cmd_sel is 0xC7D9D0. vib_sel is 0xC7D9D2. no_sa is 0xC7D9D6.
 * My_char is 0x7A8114. 0x9C9D3 and 0x9C834 stay unnamed.
 */

#include "types.h"

typedef struct {
    s8 contents[10][7];
    u16 sum;
} SystemDir;

typedef struct {
    s8 contents[10][7];
    u16 sum;
} DirData;

typedef struct {
    u8 raw[0x54];
    u8 extra_option;
    u8 tail[0x208 - 0x55];
} _SAVE_W;

#if defined(__i386__)
_Static_assert(sizeof(SystemDir) == 0x48, "SystemDir");
_Static_assert(__builtin_offsetof(SystemDir, sum) == 0x46, "sum");
_Static_assert(sizeof(DirData) == 0x48, "DirData");
_Static_assert(sizeof(_SAVE_W) == 0x208, "_SAVE_W");
_Static_assert(__builtin_offsetof(_SAVE_W, extra_option) == 0x54, "extra_option");
#endif

extern u8 Mode_Type;
extern s8 Demo_Flag;
extern u8 Present_Mode;
extern u8 Direction_Working[6];
extern SystemDir system_dir[6];
extern _SAVE_W save_w[6];
extern u32 omop_spmv_ng_table[2];
extern u32 omop_spmv_ng_table2[2];
extern const u32 sysdir_base_move[20];
extern u8 My_char[2];
extern u8 cmd_sel[2];
extern u8 no_sa[2];
extern s8 vib_sel[2];

extern void sub_0009C9D3(DirData *sysdir_data);
extern void sub_0009C834(u8 *extra);

void init_omop(void) {
    omop_spmv_ng_table2[0] = 0;
    omop_spmv_ng_table[0] = 0;
    omop_spmv_ng_table2[1] = 0;
    omop_spmv_ng_table[1] = 0;
    omop_spmv_ng_table2[0] |= 0x400000;
    omop_spmv_ng_table2[0] |= 0x800000;

    if (Mode_Type == 2) {
        sub_0009C9D3((DirData *)&system_dir[2]);
        sub_0009C834(&save_w[2].extra_option);
    } else if (Demo_Flag == 0) {
        sub_0009C9D3((DirData *)&system_dir[0]);
        sub_0009C834(&save_w->extra_option);
    } else {
        if (Direction_Working[Present_Mode]) {
            sub_0009C9D3((DirData *)&system_dir[Present_Mode]);
        } else {
            sub_0009C9D3((DirData *)&system_dir[0]);
        }

        sub_0009C834(&save_w[Present_Mode].extra_option);
    }

    omop_spmv_ng_table[0] |= sysdir_base_move[My_char[0]];
    omop_spmv_ng_table[1] |= sysdir_base_move[My_char[1]];
    cmd_sel[0] = (u8)((omop_spmv_ng_table[0] & 0x08000000) == 0);
    cmd_sel[1] = (u8)((omop_spmv_ng_table[1] & 0x08000000) == 0);
    no_sa[0] = (u8)((omop_spmv_ng_table[0] & 0xC0000000) != 0);
    no_sa[1] = (u8)((omop_spmv_ng_table[1] & 0xC0000000) != 0);
    vib_sel[0] = 1;
    vib_sel[1] = 1;
}
