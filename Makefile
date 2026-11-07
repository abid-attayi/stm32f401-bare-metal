CC = arm-none-eabi-gcc
MACH = cortex-m4
CFLAGS = -c -mcpu=$(MACH) -mthumb -std=gnu11 -O0

all: main.o led.o

main.o: src/main.c
	$(CC) $(CFLAGS) -o $@ $^

led.o: src/led.c
	$(CC) $(CFLAGS) -o $@ $^
