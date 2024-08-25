#ifndef __RCC_C__
#define __RCC_C__

/*  path to file include    */

#include "stm32_rcc.h"
#include "stm32_flash.h"

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
	volatile int counter = 0;	/*	counter variable	*/
	
	RCC->CFGR.PLLMUL	=	RCC_CFGR_PLLMUL_MUL_9						;
	RCC->CR.HSEON			=	RCC_CR_HSE_ON										;
	
	counter = 0u;
	while((!RCC->CR.HSERDY)&&(counter<50))
	{
		counter++;
	}
	
	RCC->CFGR.PLLSRC	= RCC_CFGR_PLLSRC_HSE							;
	RCC->CR.PLLON			= RCC_CR_PLLON										;
	
	counter = 0u;
	while((!RCC->CR.PLLRDY)&&(counter<50))
	{
		counter++;
	}
	
	FLASH->ACR.PRFTBE	=	1	;
	FLASH->ACR.LATENCY	=	FLASH_ACR_LATENCY_Two;
	RCC->CFGR.SW			=	RCC_CFGR_SW_PLL_SELECTED				;
	
	counter = 0u;
	while((!(RCC->CFGR.SWS	== RCC_CFGR_SWS_PLL)) && (counter<50))
	{
		counter++;
	}
	
	RCC->CFGR.HPRE		=	RCC_CFGR_HPRE_SYSCLK_NOT_DIVIDED;
	RCC->CFGR.PPRE1		= RCC_CFGR_PPRE1_HCLR_DIVIDED_2		;
	RCC->CFGR.PPRE2		=	RCC_CFGR_PPRE2_HCLR_NOT_DIVIDED	;
	RCC->CFGR.ADCPRE	=	RCC_CFGR_ADCPRE_PCLR2_DIVIDED_6	;
	RCC->CFGR.USBPRE	= RCC_CFGR_USBPRE_48mhz						;
		
}


#endif

