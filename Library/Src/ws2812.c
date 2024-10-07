
#ifndef __WS2812_C__
#define __WS2812_C__
#include "ws2812.h"

static void delay_init(ws2812_InitStruct* ws2812){
	switch((uint32_t) (ws2812->TIM)){
		case (uint32_t) TIM1:
			RCC->APB2ENR |= RCC_APB2ENR_TIM1EN	;
			break	;
		case (uint32_t) TIM2:
			RCC->APB1ENR |= RCC_APB1ENR_TIM2EN	;
			break	;
		case (uint32_t) TIM3:
			RCC->APB1ENR |= RCC_APB1ENR_TIM3EN	;
			break	;
		case (uint32_t) TIM4:
			RCC->APB1ENR |= RCC_APB1ENR_TIM4EN	;
			break	;
	}
	ws2812->TIM->CR1	|= TIM_CR1_URS	;
	ws2812->TIM->CR1	|= TIM_CR1_CEN 	;
}
void ws2812_Init(ws2812_InitStruct * ws2812Init){
	delay_init(ws2812Init);
	switch((uint32_t)ws2812Init->IO_PORT){
		case (uint32_t)GPIOA:
			RCC->APB2ENR	|= RCC_APB2ENR_IOPAEN	;
			break;
		case (uint32_t)GPIOB:
			RCC->APB2ENR	|= RCC_APB2ENR_IOPBEN	;
			break;
		case (uint32_t)GPIOC:
			RCC->APB2ENR	|= RCC_APB2ENR_IOPCEN	;
			break;
	}
	for(int i=0;i<16;i++){
		if( ( ws2812Init->IO_PIN ) & ( 1<<i ) ) {
			if(i<8){
				ws2812Init->IO_PORT->CRL &= ~( 0x0F<<(4*i) )	;
				ws2812Init->IO_PORT->CRL |= 3<<(4*i)	;	/*	max 10mhz	*/
			}else{
				ws2812Init->IO_PORT->CRH &= ~( 0x0F<<(4*(i-8)	) )	;
				ws2812Init->IO_PORT->CRH |= 3<<(4*(i-8)	);	/*	max 10mhz	*/
			}
		}
	}
	(ws2812Init->IO_PORT)->ODR |= ws2812Init->IO_PIN;
}
void ws2812_Write(ws2812_InitStruct* ws2812Init , ws2812_data* ws2812data){
	
	ws2812Init->IO_PORT->BSRR |= ws2812Init->IO_PIN << 16 	;
	ws2812Init->TIM->CNT = 0	;
	while( ws2812Init->TIM->CNT < 500 ) ;
	ws2812Init->IO_PORT->BSRR |= ws2812Init->IO_PIN	;
	
	for(int i=0 ; i< ws2812data->size ; i++){
		for(int j=0 ; j<24 ; j++ ){
			if( (1<<(24-j)) & ( ws2812data->data[i] )){
				ws2812Init->IO_PORT->BSRR |= ws2812Init->IO_PIN	;
				ws2812Init->TIM->CNT = 0	;
				while( ws2812Init->TIM->CNT < 58 ) ;
				ws2812Init->IO_PORT->BSRR |= ws2812Init->IO_PIN << 16 	;
				ws2812Init->TIM->CNT = 0	;
				while( ws2812Init->TIM->CNT < 33 ) ;
			}else{
				ws2812Init->IO_PORT->BSRR |= ws2812Init->IO_PIN	;
				ws2812Init->TIM->CNT = 0	;
				while( ws2812Init->TIM->CNT < 29);
				ws2812Init->IO_PORT->BSRR |= ws2812Init->IO_PIN << 16 	;
				ws2812Init->TIM->CNT = 0	;
				while( ws2812Init->TIM->CNT < 61);
			}
		}
	}
	ws2812Init->IO_PORT->ODR |=(1<<2);
	
}
void ws2812_ResetData(ws2812_InitStruct* ws2812Init){
	ws2812Init->IO_PORT->BSRR |= ws2812Init->IO_PIN << 16 	;
	ws2812Init->TIM->CNT = 0	;
	while( ws2812Init->TIM->CNT < 500 ) ;
	ws2812Init->IO_PORT->BSRR |= ws2812Init->IO_PIN	;
}

#endif
