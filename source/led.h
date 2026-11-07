/*
 * led.h
 */

#ifndef LED_H_
#define LED_H_

#include <stdint.h>

/*
RCC base address = 0x4002 3800
RCC OFFSET for AHB1ENR = 0x30
Together = 0x40023830

GPIOA base register= 0x40020000
GPIOA offset for mode = 0x00
Together =  0x40020000

GPIOA base register= 0x40020000
GPIOA offset for output data register = 0x14
Together =  0x40020014
*/

#define RCC_AHB1ENR_ADDR    0x40023830U
#define GPIOA_MODER_ADDR    0x40020000U
#define GPIOA_ODR_ADDR      0x40020014U

#define LED_PIN             5   //LD2 on the Nucleo is PA5

void led_init(void);
void led_on(void);
void led_off(void);
void led_toggle(void);
void delay(uint32_t count);

#endif /* LED_H_ */
