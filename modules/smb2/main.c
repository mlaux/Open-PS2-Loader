#include "irx_imports.h"

static void test_smb(void) {
  struct smb2_context *smb2;

  smb2 = smb2_init_context();
  if (smb2 == NULL) {
    printf("couldn't initialize SMB context\n");
    return;
  }

  printf("initialized smb context\n");

  smb2_set_user(smb2, "guest");
  smb2_set_password(smb2, "");

  if (smb2_connect_share(smb2, "172.16.0.110", "share1", "guest") < 0) {
    printf("failed to connect to share: %s\n", smb2_get_error(smb2));
    return;
  }

  printf("connected to share!\n");
  smb2_destroy_context(smb2);
}

static int smb2_device_op_init(iop_device_t *device) {
  return 0;
}

static int smb2_device_op_unimplemented(void) {
  return -EIO;
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
    printf("smb2 AddDrv failure\n");
    return MODULE_NO_RESIDENT_END;
  }

  printf("smb2 AddDrv success\n");
  test_smb();
  return MODULE_RESIDENT_END;
}
