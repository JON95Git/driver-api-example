CC := gcc

C_SOURCE = main.c

C_INCLUDE := \
-Iinclude/

CFLAGS := $(C_INCLUDE)
C_TARGET := driver_api_exe
C_OBJS := $(C_SOURCE:.c=.o)

# Target-specific variables
arm: C_SOURCE += driver/driver_arm.c
ppc: C_SOURCE += driver/driver_ppc.c
x86: C_SOURCE += driver/driver_x86.c

arm:
	$(CC) $(CFLAGS) -o $(C_TARGET) $(C_SOURCE)

ppc:
	$(CC) $(CFLAGS) -o $(C_TARGET) $(C_SOURCE)

x86:
	$(CC) $(CFLAGS) -o $(C_TARGET) $(C_SOURCE)

clean:
	rm -rf *.o
	rm -f $(C_TARGET)
