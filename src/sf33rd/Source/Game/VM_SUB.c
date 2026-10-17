/* Memory-card file setup, retail sf33rd.xbe.
 * VM_Access_Request is 0x9D04A size 0x15, interior after the ret.
 * Setup_File_Property is 0x9D05F size 0x9D, interior after the ret.
 * vm_w is 0x7C5580. Drive is +0x1C. Access is +0x1D.
 * Request is +0x1E. File_Type is +0x50. File_Name is +0x54.
 * Save_Size is +0x58. Block_Size is +0x5C. Icon_Type is +0x5E.
 * SystemFileName is 0x3330A8 and points at "SystemFile".
 * Replay_File_Name is 0x330558. SysDir_File_Name is 0x330580.
 * Both name tables match the PlayStation 2 strings.
 */

#include "types.h"

typedef struct {
    u8 raw0[0x1C];
    u8 Drive;
    s8 Access;
    s8 Request;
    u8 raw1[0x50 - 0x1F];
    u8 File_Type;
    u8 pad[3];
    s8 *File_Name;
    u32 Save_Size;
    u16 Block_Size;
    u8 Icon_Type;
} _VM_W;

#if defined(__i386__)
_Static_assert(__builtin_offsetof(_VM_W, Drive) == 0x1C, "Drive");
_Static_assert(__builtin_offsetof(_VM_W, Access) == 0x1D, "Access");
_Static_assert(__builtin_offsetof(_VM_W, Request) == 0x1E, "Request");
_Static_assert(__builtin_offsetof(_VM_W, File_Type) == 0x50, "File_Type");
_Static_assert(__builtin_offsetof(_VM_W, File_Name) == 0x54, "File_Name");
_Static_assert(__builtin_offsetof(_VM_W, Save_Size) == 0x58, "Save_Size");
_Static_assert(__builtin_offsetof(_VM_W, Block_Size) == 0x5C, "Block_Size");
_Static_assert(__builtin_offsetof(_VM_W, Icon_Type) == 0x5E, "Icon_Type");
#endif

extern _VM_W vm_w;
extern s8 *SystemFileName;
extern s8 *Replay_File_Name[10];
extern s8 *SysDir_File_Name[10];

u8 VM_Access_Request(u8 Request, u8 Drive) {
    vm_w.Request = Request;
    vm_w.Drive = Drive;
    return 1;
}

void Setup_File_Property(s16 file_type, u8 number) {
    switch (file_type) {
    case 0:
        vm_w.File_Name = SystemFileName;
        vm_w.File_Type = 0;
        vm_w.Save_Size = 0xC00;
        vm_w.Block_Size = 3;
        vm_w.Icon_Type = 0;
        break;

    case 3:
        break;

    case 1:
        vm_w.File_Name = Replay_File_Name[number];
        vm_w.File_Type = 1;
        vm_w.Save_Size = 0x3C00;
        vm_w.Block_Size = 0xF;
        vm_w.Icon_Type = 2;
        break;

    case 2:
        vm_w.File_Name = SysDir_File_Name[number];
        vm_w.File_Type = 2;
        vm_w.Save_Size = 0x400;
        vm_w.Block_Size = 1;
        vm_w.Icon_Type = 5;
        break;
    }
}
