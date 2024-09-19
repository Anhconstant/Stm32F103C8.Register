/*
@author - github : Anhconstant
- MCU : stm32f103c8
PERIPHERAL : Led7segment
*/
/* Decription Led7segment
a->g
----------------------------------------
         AAAA
        F    B
        F    B
         GGGG
        E    C
        E    C  dp
         DDDD

*/
#ifndef __LED7SEG_H__
#define __LED7SEG_H__
#include "stm32_gpio.h"
/*  Config  */
#define A   1<<0
#define B   1<<1
#define C   1<<2
#define D   1<<3
#define E   1<<4
#define F   1<<5
#define G   1<<6
#define dp  1<<7
#define PORT1   GPIOA   /*  Port1 pin a    ->  d   */
#define PIN_A   GPIO_PIN_0
#define PIN_B   GPIO_PIN_1
#define PIN_C   GPIO_PIN_2
#define PIN_D   GPIO_PIN_3

#define PORT2   GPIOA   /*  Port2 pin e    ->  g   */
#define PIN_E   GPIO_PIN_4
#define PIN_F   GPIO_PIN_5
#define PIN_G   GPIO_PIN_6
#define PIN_dp   GPIO_PIN_7
/*  dpABC DEFG   */


void Led7seg_Write(char data)   ;
void Led7seg_Init(void)         ;


#endif