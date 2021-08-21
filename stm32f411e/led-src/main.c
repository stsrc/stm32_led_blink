#include <stm32f4xx.h>
#include <core_cm4.h>
#include <stdlib.h>
#include "stupid_delay.h"

#define GPIO_setBit(PORT, PIN) (PORT->BSRR |= PIN)
#define GPIO_clearBit(PORT, PIN) (PORT->BSRR |= (PIN << 0x10))

static void init_blue_led() {
	//RCC clock enable
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
	GPIOD->MODER |= GPIO_MODER_MODER15_0;
	GPIOD->ODR |= GPIO_ODR_OD15;
}

int main(void){
	init_blue_led();
	delay_init();
	while(1){
		GPIO_setBit(GPIOD, 1 << 15);
		delay_ms(1000);
		GPIO_clearBit(GPIOD, 1 << 15);
		delay_ms(1000);
	}
}

