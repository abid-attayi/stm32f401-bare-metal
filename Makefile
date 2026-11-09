CC = arm-none-eabi-gcc
MACH = cortex-m4
CFLAGS = -c -mcpu=$(MACH) -mthumb -mfloat-abi=soft -std=gnu11 -Wall -O0
LDFLAGS = -mcpu=$(MACH) -mthumb -mfloat-abi=soft --specs=nano.specs -T src/stm32_ls.ld -Wl,-Map=final.map

all: main.o led.o stm32_startup.o syscalls.o final.elf

main.o: src/main.c
	$(CC) $(CFLAGS) -o $@ $^

led.o: src/led.c
	$(CC) $(CFLAGS) -o $@ $^

stm32_startup.o: src/stm32_startup.c
	$(CC) $(CFLAGS) -o $@ $^

syscalls.o: src/syscalls.c
	$(CC) $(CFLAGS) -o $@ $^

final.elf: main.o led.o stm32_startup.o syscalls.o
	$(CC) $(LDFLAGS) -o $@ $^

clean: 
	rm -rf *.o *.elf

flash:
	openocd -f board\st_nucleo_f4.cfg



