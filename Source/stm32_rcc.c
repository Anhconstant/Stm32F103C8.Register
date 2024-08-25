#ifndef __RCC_C__
#define __RCC_C__

/*  path to file include    */

#include "stm32_rcc.h"

/*  Function start    */

void Clock_Enable_GPIOA(void){
    RCC->APB2ENR.IOPAEN     |=  1   ;
}

void Clock_Enable_GPIOB(void){
    RCC->APB2ENR.IOPBEN     |=  1   ;
}

void Clock_Enable_GPIOC(void){
    RCC->APB2ENR.IOPCEN     |=  1   ;
}

void Clock_Enable_GPIOD(void){
    RCC->APB2ENR.IOPDEN     |=  1   ;
}

void Clock_Enable_GPIOE(void){
    RCC->APB2ENR.IOPEEN     |=  1   ;
}

void Clock_Enable_TIM2(void){
		RCC->APB1ENR.TIM2EN			|=	1		;
}

void Clock_Enable_TIM3(void){
		RCC->APB1ENR.TIM3EN			|=	1		;
}

void Clock_Enable_TIM4(void){
		RCC->APB1ENR.TIM4EN			|=	1		;
}

void Clock_Enable_TIM5(void){
		RCC->APB1ENR.TIM5EN			|=	1		;
}

void Clock_Enable_TIM6(void){
		RCC->APB1ENR.TIM6EN			|=	1		;
}

void Clock_Enable_TIM7(void){
		RCC->APB1ENR.TIM7EN			|=	1		;
}

void Clock_Enable_TIM12(void){
		RCC->APB1ENR.TIM12EN		|=	1		;
}

void Clock_Enable_TIM13(void){
		RCC->APB1ENR.TIM13EN		|=	1		;
}

void Clock_Enable_TIM14(void){
		RCC->APB1ENR.TIM14EN		|=	1		;
}

void Clock_64mhz(void){
		/*Clock 64Mhz with HSI clock 8mhz	*/
}

void Clock_72mhz(void){
		/*Clock 72Mhz with HSE crystal 8mhz	*/
}

#endif

