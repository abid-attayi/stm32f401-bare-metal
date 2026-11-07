/*
 * main.c
 */

#include "main.h"
#include "led.h"

int main(void)
{
	led_init();

	while(1)
	{
		led_toggle();
		delay(DELAY_COUNT);
	}
}
