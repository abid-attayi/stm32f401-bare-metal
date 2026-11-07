/*
 * led.c
 */

#include "led.h"

void led_init(void)
{
	volatile uint32_t *pClkCtrlReg = (volatile uint32_t*)RCC_AHB1ENR_ADDR;
	volatile uint32_t *pPortAModeReg = (volatile uint32_t*)GPIOA_MODER_ADDR;

	*pClkCtrlReg |= 0x01; //enable GPIOA clock

	*pPortAModeReg &= ~(0x03 << (LED_PIN * 2)); //clear
	*pPortAModeReg |= (0x01 << (LED_PIN * 2)); //set PA5 as output
}

void led_on(void)
{
	volatile uint32_t *pPortAOutReg = (volatile uint32_t*)GPIOA_ODR_ADDR;

	*pPortAOutReg |= (0x01 << LED_PIN); //set PA5 high
}

void led_off(void)
{
	volatile uint32_t *pPortAOutReg = (volatile uint32_t*)GPIOA_ODR_ADDR;

	*pPortAOutReg &= ~(0x01 << LED_PIN); //set PA5 low
}

void led_toggle(void)
{
	volatile uint32_t *pPortAOutReg = (volatile uint32_t*)GPIOA_ODR_ADDR;

	*pPortAOutReg ^= (0x01 << LED_PIN); //flip PA5
}

void delay(uint32_t count)
{
	for(volatile uint32_t i = 0; i < count; i++); //busy wait
}
