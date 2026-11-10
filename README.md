# stm32f401-bare-metal

Firmware for the STM32F401RE (Nucleo-F401RE) built from nothing: no STM32CubeIDE, no HAL, no vendor startup files. Every file in this repo is hand-written.


## What's here
- **Startup code**: vector table, reset handler, `.data` copy and `.bss` zeroing before `main`
- **Linker script**: flash and RAM layout for the F401RE (512 KB flash, 96 KB RAM)
- **Makefile**: builds with `arm-none-eabi-gcc`, no IDE
- **Register-level GPIO**: LED blink by writing RCC and GPIO registers directly

## Build and flash
    make
    make flash      # uses [OpenOCD / st-flash]

Requires `arm-none-eabi-gcc`, `make`, and [OpenOCD / stlink-tools].

## Roadmap
- [x] Startup, linker script, blinky
- [ ] SysTick timebase and UART driver
- [ ] Custom bootloader: UART firmware update, jump to application

## What I learned
- **What happens before `main`.** The CPU reads its initial stack pointer and reset handler address from the first two words of the vector table at the start of flash. If the linker script doesn't place the table there, nothing runs.
- **Why startup code exists.** Initialized globals live in flash and have to be copied into RAM, and `.bss` has to be zeroed. Skip either and variables start with garbage, with no error to tell you why.
- **The linker script is the memory map.** It defines the symbols the startup code uses to find where `.data` and `.bss` begin and end.
- **Peripherals are off by default.** Writing to a GPIO register does nothing until that port's clock is enabled in RCC, which is the first thing an IDE normally hides.
