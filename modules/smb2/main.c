#include "irx_imports.h"

static void test_smb(void) {
  // smb2 = smb2_init_context();
  // if (smb2 == NULL) {
  //         scr_setXY(10, y++);
  //         scr_printf("init context failed.\n");
  //         return 0;
  // }
  // scr_setXY(10, y++);
  // scr_printf("init context SUCCEEDED.\n");
  // sleep(10);
  
  // smb2_set_user(smb2, USER);
  // smb2_set_password(smb2, PASSWORD);

  // if (smb2_connect_share(smb2, SERVER, SHARE, USER) < 0) {
  //         scr_setXY(10, y++);
  //         scr_printf("smb2_connect_share failed. %s\n", smb2_get_error(smb2));
  //         return 0;
  // }
}

static int smb2_device_op_init(iop_device_t *device) {
  return 0;
}

static int smb2_device_op_unimplemented(void) {
  return -1;
}

iop_device_ops_t smb2_device_ops = {
  smb2_device_op_init,
  (void *) smb2_device_op_unimplemented,
  (void *) smb2_device_op_unimplemented,
  (void *) smb2_device_op_unimplemented,
  (void *) smb2_device_op_unimplemented,
  (void *) smb2_device_op_unimplemented,
  (void *) smb2_device_op_unimplemented,
  (void *) smb2_device_op_unimplemented,
  (void *) smb2_device_op_unimplemented,
  (void *) smb2_device_op_unimplemented,
  (void *) smb2_device_op_unimplemented,
  (void *) smb2_device_op_unimplemented,
  (void *) smb2_device_op_unimplemented,
  (void *) smb2_device_op_unimplemented,
  (void *) smb2_device_op_unimplemented,
  (void *) smb2_device_op_unimplemented,
  (void *) smb2_device_op_unimplemented,
};

iop_device_t smb2_device = {
  "smb2",
  IOP_DT_BLOCK, // IOP_DT_FS?
  1,
  "smb2",
  &smb2_device_ops,
};

int _start(int argc, char *argv[]) {
  if (AddDrv(&smb2_device) != 0) {
    printf("smb2 AddDrv failure");
    return MODULE_NO_RESIDENT_END;
  }

  printf("smb2 AddDrv success");
  test_smb();
  return MODULE_RESIDENT_END;
}
