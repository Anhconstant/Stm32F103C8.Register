/*
@author: Tran Tuan Anh 
@github: Anhconstant
- MCU : stm32f103c8
PERIPHERALS : GENERAL PURPOSE TIMER (TIM2 TO TIM5) (<===>) APB1 BUS
PERIPHERALS : GENERAL PURPOSE TIMER (TIM9 TO TIM14)
TIM9    TIM10   TIM11 (<===>)      APB2 BUS
TIM12   TIM 13  TIM14 (<===>)      APB1 BUS
*/

#ifndef __GPTIM_H__
#define __GPTIM_H__

#include "stm32_rcc.h"

typedef struct 
{
		struct{
			unsigned long CEN		:	1		;
			unsigned long UDIS	:	1		;
			unsigned long URS		:	1		;
			unsigned long OPM		:	1		;
			unsigned long DIR		:	1		;
			unsigned long CMS		:	2		;
			unsigned long ARPE	:	1		;
			
			unsigned long CKD		:	2		;
			unsigned long _RES	:	22	;
		} CR1	;
    unsigned long   CR2         ;
    unsigned long   SMCR        ;
    unsigned long   DIER        ;
    unsigned long   SR          ;
		struct{
			unsigned long UG		:	1		;
			unsigned long CC1G	:	1		;
			unsigned long CC2G	:	1		;
			unsigned long CC3G	:	1		;
			unsigned long CC4G	:	1		;
			unsigned long	_RES_1:	1		;
			unsigned long TG		:	1		;
			unsigned long _RES_2:	25	;
    } EGR ;
    unsigned long   CCMR1       ;
    unsigned long   CCMR2       ;	/*	TIM9 to TIM14 IS RES	*/
    unsigned long   CCER        ;
    unsigned long   CNT         ;
    unsigned long   PSC         ;
    unsigned long   ARR         ;
    unsigned long   _RES1       ;
    unsigned long   CCR1        ;
    unsigned long   CCR2        ;	/* CCR2 REGISTER TIM10 AND TIM11 AND TIM13 AND TIM14 IS _RES*/
    unsigned long   CCR3        ;	/*	TIM9 to TIM14 IS RES	*/
    unsigned long   CCR4        ;	/*	TIM9 to TIM14 IS RES	*/
    unsigned long   _RES2       ;	/*	TIM9 to TIM14 IS RES	*/
    unsigned long   DCR         ;	/*	TIM9 to TIM14 IS RES	*/
    unsigned long   DMAR        ;	/*	TIM9 to TIM14 IS RES	*/
    
} GPTIM_TypeDef    ;

#define 	TIM2    ((GPTIM_TypeDef *)0x40000000UL )
#define 	TIM3    ((GPTIM_TypeDef *)0x40000400UL )
#define 	TIM4    ((GPTIM_TypeDef *)0x40000800UL )
#define 	TIM5    ((GPTIM_TypeDef *)0x40000C00UL )

#define   TIM9    ((GPTIM_TypeDef *)0x40014C00UL )
#define   TIM10   ((GPTIM_TypeDef *)0x40015000UL )
#define   TIM11   ((GPTIM_TypeDef *)0x40015400UL )
#define   TIM12   ((GPTIM_TypeDef *)0x40001800UL )
#define   TIM13   ((GPTIM_TypeDef *)0x40001C00UL )
#define   TIM14   ((GPTIM_TypeDef *)0x40002000UL )


#endif
