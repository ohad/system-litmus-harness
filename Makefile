CC = aarch64-linux-gnu-gcc
LD = aarch64-linux-gnu-ld
QEMU = qemu-system-aarch64
OBJCOPY = aarch64-linux-gnu-objcopy
OBJDUMP = aarch64-linux-gnu-objdump
OUT_NAME = main.bin
SSH_NAME = pi@rems-rpi4b
RUN_CMD = 	\
	$(QEMU) \
		-nodefaults -machine virt,accel=tcg -cpu cortex-a57 \
		-device virtio-serial-device -device virtconsole,chardev=ctd \
		-chardev testdev,id=ctd -device pci-testdev -display none -serial stdio \
		-kernel ./bin/$(OUT_NAME) -smp 4 # -initrd /tmp/tmp.UUenc9WRhz

CFLAGS = -O0 -nostdlib -I inc/ -I inc/litmus -ffreestanding -fomit-frame-pointer -fno-pie -fno-pic -DTRACE
LDFLAGS = -nostdlib -n -pie
SSHFLAGS = -K

LIB_FILES = $(wildcard lib/*.c)
LITMUS_FILES = $(wildcard litmus/*.c)

TOP_ASM_FILES = $(wildcard *.s)
TOP_C_FILES = $(wildcard *.c)

ASM_FILES = $(TOP_ASM_FILES)
C_FILES = $(LIB_FILES) $(LITMUS_FILES) $(TOP_C_FILES)
BIN_FILES = $(addprefix bin/,$(C_FILES:.c=.o) $(ASM_FILES:.s=.o))


.PHONY: all
all: bin/main.bin

bindir:
	mkdir -p bin/lib/
	mkdir -p bin/litmus/

bin/lib/%.o: lib/%.c
	$(CC) $(CFLAGS) -c -o $@ $^

bin/litmus/%.o: litmus/%.c
	$(CC) $(CFLAGS) -c -o $@ $^

bin/cpu_entry.o:  cpu_entry.s
	$(CC) $(CFLAGS) -c -o bin/cpu_entry.o cpu_entry.s

bin/vector_table.o:  vector_table.s
	$(CC) $(CFLAGS) -c -o bin/vector_table.o vector_table.s

bin/main.o: main.c
	$(CC) $(CFLAGS) -c -o bin/main.o main.c

bin/main.elf: $(BIN_FILES)
	$(LD) $(LDFLAGS) -o bin/main.elf -T bin.lds $(BIN_FILES)
	$(OBJDUMP) -D -r bin/main.elf > bin/main.elf.s

bin/main.bin: bindir bin/main.elf
	$(OBJCOPY) -O binary bin/main.elf bin/main.bin

run: bin/main.bin
	$(RUN_CMD)

debug: bin/main.bin
	{ $(RUN_CMD) -s -S & echo $$! > bin/.debug.pid; }
	gdb-multiarch  --eval-command "set arch aarch64" --eval-command "target remote localhost:1234"
	{ cat bin/.debug.pid | xargs kill $$pid ; rm bin/.debug.pid; }

ssh: OUT_NAME=litmus.bin
ssh:
	scp ./bin/main.bin $(SSH_NAME):litmus.bin
	echo "$(RUN_CMD)" > bin/litmus.exe
	chmod +x bin/litmus.exe
	scp bin/litmus.exe $(SSH_NAME):litmus.exe
	ssh $(SSHFLAGS) $(SSH_NAME) "./litmus.exe"

.PHONY: clean
clean:
	rm -rf bin/
