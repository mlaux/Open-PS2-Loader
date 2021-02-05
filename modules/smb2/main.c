#include <loadcore.h>
#include <ioman.h>
#include <irx.h>
#include <stdio.h>

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
  if (AddDrv(&smb2_device) == 0) {
    printf("smb2 AddDrv success");
    return MODULE_RESIDENT_END;
  } else {
    printf("smb2 AddDrv failure");
    return MODULE_NO_RESIDENT_END;
  }
}
