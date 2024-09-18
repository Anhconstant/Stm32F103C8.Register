/*
@author - github : Anhconstant
- MCU : stm32f103c8
PERIPHERAL : SYSTICK TIMER
*/
#ifndef __SYSTICK_H__
#define __SYSTICK_H__
#include "stm32f10x.h"
#include "core_cm3.h"

#define STK ((SysTick_Type*)0xE000E010)

void Systick_Init(void)     ;
void Systick_Int_Enable(uint8_t val)    ;
void Systick_Enable(void)   ;
void Systick_Disable(void)  ;

#endif

