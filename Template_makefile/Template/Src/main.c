#include "stm32_main.h"
void delayms(unsigned long i);

void delayms(unsigned long i){
	while(i){
		--i;
	}
}
int main(void)
{
	RCC->APB2ENR |= RCC_APB2ENR_IOPBEN	;
	RCC->APB2ENR |= RCC_APB2ENR_IOPCEN	;
	GPIO_Init(GPIOB,GPIO_PIN_2,General_Output_PP_2mhz);
	GPIO_Init(GPIOC,GPIO_PIN_13,General_Output_PP_2mhz);
	while(1) {
		GPIOC->ODR |= 1<<13	;
		// GPIOB->ODR |=  1<<2	;
		WriteGPIO(GPIOB,GPIO_PIN_2,GPIO_SET);
		delayms(0x555555);
		// GPIOB->ODR &=  ~1<<2;
		WriteGPIO(GPIOB,GPIO_PIN_2,GPIO_RESET);
		GPIOC->ODR &= ~1<<13;
		delayms(0x555555);
	}
}
