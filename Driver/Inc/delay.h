/*
@author - github: Anhconstant
- MCU : stm32f103c8
LIBRATY : DELAY 
*/
#ifndef __DELAY_H__
#define __DELAY_H__

#include "stm32f10x.h"
#include "stm32_rcc.h"
void delay_config(void);

void delay1ms(void);

void delay_us(int times);

void delay_ms(int times);

#endif
