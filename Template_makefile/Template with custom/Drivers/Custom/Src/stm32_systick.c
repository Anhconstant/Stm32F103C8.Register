/*
@author - github : Anhconstant
- MCU : stm32f103c8
PERIPHERAL : SYSTICK TIMER
*/
#ifndef __SYSTICK_C__
#define __SYSTICK_C__
#include "stm32_systick.h"
#include "core_cm3.h"

#define Enable  1
#define ENABLE  1
#define enable  1
#define Disable  0
#define disable  0
#define DISABLE  0

void Systick_Init(void){
    STK->LOAD   |= 72000 - 1              ;
    STK->VAL    |= 72000 - 1              ;
    STK->CTRL   |= SysTick_CTRL_CLKSOURCE ;
    STK->CTRL   |= SysTick_CTRL_TICKINT   ;
    STK->CTRL   |= SysTick_CTRL_ENABLE    ;
}
void Systick_Int_Enable(uint8_t val){
    if(val){
        STK->CTRL |= SysTick_CTRL_TICKINT   ;
    }
    else{
        STK->CTRL |= ~SysTick_CTRL_TICKINT  ;
    }    
}
void Systick_Enable(void){
    STK->CTRL |= SysTick_CTRL_ENABLE   ;
}
void Systick_Disable(void){
    STK->CTRL |= ~SysTick_CTRL_ENABLE  ;
}
#endif
