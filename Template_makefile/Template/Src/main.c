#include "stm32f10x.h"

void delayms(unsigned long i);

void delayms(unsigned long i){
	while(i){
		--i;
	}
}


int main(void)
{
	RCC->APB2ENR |= RCC_APB2ENR_IOPBEN	;
	GPIOB->CRL = 0x44444144;

	while(1) {
		GPIOB->ODR |=  1<<2	;
		delayms(0xFFFF);
		GPIOB->ODR &=  ~1<<2;
		delayms(0xFFFF);
	}
	
}
