IOP_BIN = smb2.irx
IOP_OBJS = main.o imports.o

IOP_LDFLAGS += -L$(PS2SDK)/iop/lib
IOP_LIBS += -lsmb2 -lgcc

include $(PS2SDK)/Defs.make
include ../Rules.bin.make
include ../Rules.make
