/*
@author - github: Anhconstant
- MCU : stm32f103c8
LIBRATY : DELAY 
*/
#ifndef __DELAY_C__
#define __DELAY_C__
#include "delay.h"

#define USE_CLOCK 72000000
void delay_config(void){
    Clock_Enable_TIM4()			;	
	TIM4->PSC	|= USE_CLOCK/1000000 -	1	;
	TIM4->ARR	|= TIM_ARR_ARR	;
	TIM4->CR1	|= TIM_CR1_CEN	;
	TIM4->EGR	|= TIM_EGR_UG	;
}

void delay1ms(void){
	TIM4->CNT 	= 0u 			;
	while(TIM4->CNT<(1000))		;
}

void delay_ms(int times){
	while(times){
		delay1ms();
		times--;
	}
}

void delay_us(int times){
	TIM4->CNT 	= 0u 			;
	while(TIM4->CNT<(times))	;
}

#endif
