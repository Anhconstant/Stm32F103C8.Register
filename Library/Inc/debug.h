/*
@author - github: Anhconstant
- MCU : stm32f103c8
LIBRATY : STM32_DEBUG
DEBUG DATA WITH GPIO
*/
#ifndef __DEBUG_H__
#define __DEBUG_H__

#include "stm32f10x.h"
/*  DEFAULT PORT_DEBUG PORTA    
    DEFAULT PIN_DEBUG GPIO_PIN_0 */

#ifndef PORT_DEBUG
#define PORT_DEBUG (GPIOA)
#endif
#ifndef PIN_DEBUG
#define PIN_DEBUG  0 /* 0 ,1,...15     */
#endif
void debug_init(void)           ;
void debug_send_data(char byte) ;
void debug_click(void)          ;
#endif

