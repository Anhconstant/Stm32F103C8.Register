/*
@author - github: Anhconstant
- MCU : stm32f103c8
LIBRATY : STM32_DEBUG
DEBUG DATA WITH GPIO
*/
#ifndef __DEBUG_C__
#define __DEBUG_C__

#include "debug.h"
#include "delay.h"
/*  DEFAULT PORT_DEBUG PORTA    
    DEFAULT PIN_DEBUG GPIO_PIN_0 */
void debug_init(void){
    RCC->APB2ENR    |= RCC_APB2ENR_IOPAEN   ;
    if(PIN_DEBUG < 8){
        PORT_DEBUG->CRL     &= ~(0x0000000f<<(PIN_DEBUG*4))  ;          // reset mode , cnf of pin
        PORT_DEBUG->CRL     |= 1<<(PIN_DEBUG*4)            ;            // config output putpull 10mhz
    }
    else if(PIN_DEBUG>= 8){
        PORT_DEBUG->CRH     &= ~(0x0000000f<< ((PIN_DEBUG-8)*4))  ;     // reset mode , cnf of pin
        PORT_DEBUG->CRH     |= 1<<((PIN_DEBUG-8)*4)            ;        // config output putpull 10mhz
    }         
}
void debug_send_data(char byte){
    /*  MSB   */
    debug_init();
    int i= 0 ;
    for( i=0;i<8;++i ) {
        if( (byte<<i) & 0x80){
            PORT_DEBUG->ODR |= 1<<PIN_DEBUG;
            delay_us(40)    ;
            PORT_DEBUG->ODR &= ~(1<<PIN_DEBUG);
            delay_us(10)    ;
        }
        else{
            PORT_DEBUG->ODR |= 1<<PIN_DEBUG;
            delay_us(10)    ;
            PORT_DEBUG->ODR &= ~(1<<PIN_DEBUG);
            delay_us(40)    ;
        }
    }
    
}
void debug_click(void){
    debug_init();
    delay_ms(200);
    PORT_DEBUG->ODR |= 1<<PIN_DEBUG;
    delay_ms(50)    ;
    PORT_DEBUG->ODR &= ~(1<<PIN_DEBUG);
    delay_ms(20)    ;
    PORT_DEBUG->ODR |= 1<<PIN_DEBUG;
    delay_ms(50)    ;
    PORT_DEBUG->ODR &= ~(1<<PIN_DEBUG);
    delay_ms(20)    ;
    delay_ms(200);
}

#endif
