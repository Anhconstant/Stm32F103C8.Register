#ifndef __WS2812_H__
#define __WS2812_H__
#include "stm32f10x.h"
#include "stdint.h"
#define PORT_default 	(GPIOA)
#define PIN_default 	(1<<0)
#define MAX_SIZE	10
/*
Decription : MCU stm32f103 
System clock at 72mhz
Need : 1 pin and 1 timer 
*/

typedef struct{
	TIM_TypeDef* 	TIM		;
	GPIO_TypeDef* 	IO_PORT	;
	uint16_t		IO_PIN	;
}ws2812_InitStruct	;

typedef struct{
	uint32_t size	;
	uint32_t data[MAX_SIZE]	;
}ws2812_data;

static void delay_init(ws2812_InitStruct* ws2812);
void ws2812_Init(ws2812_InitStruct * ws2812Init);

void ws2812_Write(ws2812_InitStruct* ws2812Init , ws2812_data* ws2812data)	;
void ws2812_ResetData(ws2812_InitStruct* ws2812Init);




#endif
