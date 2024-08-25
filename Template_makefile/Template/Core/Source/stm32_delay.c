/*
@author: Tran Tuan Anh 
@github: Anhconstant
- MCU : stm32f103c8
USE: PERIPHERAL GENENAL PURPOSE TIMER 4 
*/

#ifndef __DELAY_C__
#define __DELAY_C__

#include "stm32_delay.h"

void delay_config(void){
	Clock_Enable_TIM4();
	TIM4->PSC = PRESCALER;
	TIM4->ARR	= 0xffff;
	TIM4->CR1.CEN	=	1 ;
	TIM4->EGR.UG	=	1	;
}

void delay_1ms(void){
	TIM4->CNT = 0U;
	while(TIM4->CNT<(1000));
}


void delay_ms( int times ){
	/* delay  (1ms x times)*/
	while(times){
		delay_1ms();
		
		times--;
	}
}

void delay(int times){
	/*relative delay  (1ms x times)*/
	unsigned long a =(unsigned long) (times*(Freq/8000));
	while(a--);
}
#endif
