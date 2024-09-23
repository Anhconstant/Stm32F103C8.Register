/*
@author - github : Anhconstant
- MCU : stm32f103c8
PERIPHERAL : Led7segment
*/
#ifndef __LED7SEG_C__
#define __LED7SEG_C__
#include "stm32_led7seg.h"
volatile char  led7seg_convert[15]={ 0x3F,0x06,0x5B,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71   }  ;
void Led7seg_Init(void){
    switch ((uint32_t)PORT1)
    {
    case (uint32_t)GPIOA:
        RCC->APB2ENR |= RCC_APB2ENR_IOPAEN  ;
        break;
    case (uint32_t)GPIOB:
        RCC->APB2ENR |= RCC_APB2ENR_IOPBEN  ;
        break;
    case (uint32_t)GPIOC:
        RCC->APB2ENR |= RCC_APB2ENR_IOPCEN  ;
        break;
    }
    switch ((uint32_t)PORT2)
    {
    case (uint32_t)GPIOA:
        RCC->APB2ENR |= RCC_APB2ENR_IOPAEN  ;
        break;
    case (uint32_t)GPIOB:
        RCC->APB2ENR |= RCC_APB2ENR_IOPBEN  ;
        break;
    case (uint32_t)GPIOC:
        RCC->APB2ENR |= RCC_APB2ENR_IOPCEN  ;
        break;
    }
     GPIO_Init(PORT1,PIN_A|PIN_B|PIN_C|PIN_D,General_Output_PP_2mhz)     ;
     GPIO_Init(PORT2,PIN_E|PIN_F|PIN_G|PIN_dp,General_Output_PP_2mhz)    ;


}

void Led7seg_Write(char data){
        PORT1->BRR |= PIN_A | PIN_B | PIN_C | PIN_D ;
        PORT2->BRR |= PIN_E | PIN_F | PIN_G | PIN_dp ;
    if( ('0' <= data) && ( data <= '9' ) ){
        int temp = data - '0';
        if( ( led7seg_convert[temp] ) & (1<<0) ) PORT1->BSRR |= PIN_A  ;
        if( ( led7seg_convert[temp] ) & (1<<1) ) PORT1->BSRR |= PIN_B  ;
        if( ( led7seg_convert[temp] ) & (1<<2) ) PORT1->BSRR |= PIN_C  ;
        if( ( led7seg_convert[temp] ) & (1<<3) ) PORT1->BSRR |= PIN_D  ;
        if( ( led7seg_convert[temp] ) & (1<<4) ) PORT2->BSRR |= PIN_E  ;
        if( ( led7seg_convert[temp] ) & (1<<5) ) PORT2->BSRR |= PIN_F  ;
        if( ( led7seg_convert[temp] ) & (1<<6) ) PORT2->BSRR |= PIN_G  ;
        if( ( led7seg_convert[temp] ) & (1<<7) ) PORT2->BSRR |= PIN_dp  ;
    }
    if( ('A' <= data) && ( data <= 'F' ) ){
        int temp = data - 'A'+ 10 ;
        if( ( led7seg_convert[temp] ) & (1<<0) ) PORT1->BSRR |= PIN_A  ;
        if( ( led7seg_convert[temp] ) & (1<<1) ) PORT1->BSRR |= PIN_B  ;
        if( ( led7seg_convert[temp] ) & (1<<2) ) PORT1->BSRR |= PIN_C  ;
        if( ( led7seg_convert[temp] ) & (1<<3) ) PORT1->BSRR |= PIN_D  ;
        if( ( led7seg_convert[temp] ) & (1<<4) ) PORT2->BSRR |= PIN_E  ;
        if( ( led7seg_convert[temp] ) & (1<<5) ) PORT2->BSRR |= PIN_F  ;
        if( ( led7seg_convert[temp] ) & (1<<6) ) PORT2->BSRR |= PIN_G  ;
        if( ( led7seg_convert[temp] ) & (1<<7) ) PORT2->BSRR |= PIN_dp  ;
    }
}

#endif
