
#ifndef __WS2812_C__
#define __WS2812_C__
#include "ws2812.h"

void ws2812_Init(ws2812_InitStruct * ws2812Init){
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
				ws2812Init->IO_PORT->CRL |= 3<<(4*i)	;	/*	max 50mhz	*/
			}else{
				ws2812Init->IO_PORT->CRH &= ~( 0x0F<<(4*(i-8)	) )	;
				ws2812Init->IO_PORT->CRH |= 3<<(4*(i-8)	);	/*	max 50mhz	*/
			}
		}
	}
	(ws2812Init->IO_PORT)->ODR |= ws2812Init->IO_PIN;
}
void ws2812_Write(ws2812_InitStruct* ws2812Init , ws2812_data* ws2812data){
	ws2812Init->IO_PORT->BSRR |= ws2812Init->IO_PIN << 16 	;
	for(int i=0;i<0x300;i++)__nop();
	for(int i=0 ; i< ws2812data->size ; i++){
		for(int j=23 ; j>=0 ; j-- ){
			if( (1<<(j)) & ( ws2812data->data[i] )){
				ws2812Init->IO_PORT->BSRR |= ws2812Init->IO_PIN	;
				ws2812Init->IO_PORT->BSRR |= ws2812Init->IO_PIN	;
				ws2812Init->IO_PORT->BSRR |= ws2812Init->IO_PIN	;
				ws2812Init->IO_PORT->BSRR |= ws2812Init->IO_PIN	;
				ws2812Init->IO_PORT->BSRR |= ws2812Init->IO_PIN << 16 	;
			}
			else{
				ws2812Init->IO_PORT->BSRR |= ws2812Init->IO_PIN	;
				ws2812Init->IO_PORT->BSRR |= ws2812Init->IO_PIN	;
				ws2812Init->IO_PORT->BSRR |= ws2812Init->IO_PIN << 16 	;
				ws2812Init->IO_PORT->BSRR |= ws2812Init->IO_PIN << 16 	;
				ws2812Init->IO_PORT->BSRR |= ws2812Init->IO_PIN << 16 	;
			}
		}
	}
	ws2812Init->IO_PORT->ODR |=(1<<2);
	
}
void ws2812_ResetData(ws2812_InitStruct* ws2812Init){
	ws2812Init->IO_PORT->BSRR |= ws2812Init->IO_PIN << 16 	;
	for(int i=0;i<0xFFF;i++)__nop();
	ws2812Init->IO_PORT->BSRR |= ws2812Init->IO_PIN	;
}

#endif
