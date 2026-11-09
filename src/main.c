/*
 * main.c
 */

#include "main.h"
#include "led.h"

uint32_t var_init = 42;   //dummy var in .data
uint32_t var_zero;        //dummy var in .bss

int main(void)
{
	led_init();

	while(1)
	{
		led_toggle();
		delay(DELAY_COUNT);
	}
}
