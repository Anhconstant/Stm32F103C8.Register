#ifndef __MAIN_H__
#define __MAIN_H__
/* 
================    DEFINE  ===================
-   Need define Clock to config Clock 
    USE_HSE_CLOCK:  {   8mhz   24mhz   36mhz   48mhz   56mhz   72mhz    } 
    USE_HSI_CLOCK:  {   8mhz   48mhz                                    }
    if use Peripheral USB : 72mhz or 48mhz
-   Need define USE_CLOCK to config timer and delay   
*/
#define USE_CLOCK 72000000
#define USE_HSE_CLOCK
//#define STM32F10X_MD
#define EXTERNAL_CLOCK 8000000
/* 
================    INCLUDE     ===================
*/
#include "stm32f10x.h"  /*HEADER    */
#include "stm32_main.h"
#include "stm32_gpio.h"
#include "stm32_rcc.h"
#include "delay.h"
#include "debug.h"
#include "stm32_uart.h"
#include "define.h"



// #define PORT_DEBUG GPIOA
// #define PIN_DEBUG 0


//#define STM32F10X_MD
//#define EXTERNAL_CLOCK 8000000

#endif
