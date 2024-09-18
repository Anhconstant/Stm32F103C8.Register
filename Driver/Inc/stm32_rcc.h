/*
@author - github: Anhconstant
- MCU : stm32f103c8
PERIPHERAL : RCC
*/

#ifndef __RCC_H__
#define __RCC_H__
#include "stm32f10x.h"
typedef enum
{
    HSE_OK = 0u,
    HSE_NOTOK = ~HSE_OK
} HSE_Status;

typedef enum
{
    HSI_OK = 0u,
    HSI_NOTOK = ~HSI_OK
} HSI_Status;
typedef enum{
	SYS_Clock 	= 0	,
	APB1_Clock 	= 1	,
	APB2_Clock  = 2	,
	AHB_Clock	= 3		
}Clock	;
//typedef enum
//{
//    clock_8mhz      = 1 ,
//    clock_16mhz     = 2 ,
//    clock_32mhz     = 3 ,
//    clock_36mhz     = 4 ,
//    Clock_72mhz     = 5 
//} CLOCK_FREQ;
/* Declare Type end                        */

/* Declare Function start                   */

HSE_Status HSE_Detect(void)     ;

HSE_Status HSE_Ready(void)      ;

HSE_Status HSE_On(void)         ;

HSI_Status HSI_Ready(void)      ;

HSI_Status HSI_On(void)         ;

void Clock_Enable(uint32_t *Periph) ; // ENABLE PERIPH 

void Clock_Enable_GPIOA(void)   ;

void Clock_Enable_GPIOB(void)   ;

void Clock_Enable_GPIOC(void)   ;

void Clock_Enable_GPIOD(void)   ;

void Clock_Enable_GPIOE(void)   ;

// void Clock_Enable_TIM7(void)		;

void Clock_Enable_TIM2(void)		;

void Clock_Enable_TIM3(void)		;

void Clock_Enable_TIM4(void)		;

void Clock_Enable_USART1(void)      ;

void Clock_Enable_USART2(void)      ;

void Clock_Enable_USART3(void)      ;


#ifdef USE_HSE_CLOCK
void Clock_8mhz(void)					;

void Clock_24mhz(void)					;

void Clock_36mhz(void)					;

void Clock_48mhz(void)					;

void Clock_56mhz(void)					;

void Clock_72mhz(void)          ;
#endif

#ifdef USE_HSI_CLOCK
void Clock_48mhz(void)					;
#endif


uint32_t Get_clock(Clock clock) ;


/* Declare Function end                   */

#endif
