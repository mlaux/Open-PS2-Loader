#include "irx_imports.h"

static void test_smb(void) {
  // int sockfd;
  // struct sockaddr_in addr;
  // int err;
  // socklen_t err_size = sizeof(err);

  // sockfd = lwip_socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
  // if (sockfd == -1) {
  //   printf("socket() returned -1\n");
  // }

  // addr.sin_family = AF_INET;
  // addr.sin_port = htons(445);
  // ipaddr4_aton("172.16.1.136", (ip4_addr_t *) &addr.sin_addr.s_addr);

  // err = lwip_connect(sockfd, (struct sockaddr *) &addr, sizeof addr);
  // printf("connect() returned %d\n", err);

  // printf("getsockopt() returned %d\n", getsockopt(sockfd, SOL_SOCKET, SO_ERROR,
  //  (void *) &err, &err_size));
  // printf("the socket error was %d\n", err);


  struct smb2_context *smb2;

  smb2 = smb2_init_context();
  if (smb2 == NULL) {
    printf("couldn't initialize SMB context\n");
    return;
  }

  printf("initialized smb context\n");

  smb2_set_user(smb2, "guest");
  smb2_set_password(smb2, "");

  if (smb2_connect_share(smb2, "172.16.1.136", "share1", "guest") < 0) {
    printf("failed to connect to share: %s\n", smb2_get_error(smb2));
    printf("errno: %d\n", errno);
    smb2_destroy_context(smb2);
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
