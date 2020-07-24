#include <stm32f1xx.h>
#include <core_cm3.h>
#include <stdlib.h>
#include "stupid_delay.h"
#include "timers.h"

#define LED_port GPIOC
#define LED_Blue (1 << 8)
#define GPIO_setBit(PORT, PIN) (PORT->BSRR |= PIN)
#define GPIO_clearBit(PORT, PIN) (PORT->BSRR |= (PIN << 0x10))

void init_blue_led() {
	LED_port->CRH &= ~GPIO_CRH_CNF8;
	LED_port->CRH |= GPIO_CRH_MODE8_0;
}

int main(void){
	NVIC_prioritySet();
	delay_init();
	init_blue_led();
	while(1){
		delay_ms(500);
		GPIO_setBit(LED_port, LED_Blue);
		delay_ms(500);
		GPIO_clearBit(LED_port, LED_Blue);
	}
}

