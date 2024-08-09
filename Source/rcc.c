#ifndef __RCC_C__
#define __RCC_C__

/*  path to file include    */

#include "../include/rcc.h"

/*  Function start    */

void Clock_Enable_GPIOA(void)
{
    RCC->APB2ENR.IOPAEN     |=  1   ;
}

void Clock_Enable_GPIOB(void)
{
    RCC->APB2ENR.IOPBEN     |=  1   ;
}

void Clock_Enable_GPIOC(void)
{
    RCC->APB2ENR.IOPCEN     |=  1   ;
}

void Clock_Enable_GPIOD(void)
{
    RCC->APB2ENR.IOPDEN     |=  1   ;
}

void Clock_Enable_GPIOE(void)
{
    RCC->APB2ENR.IOPEEN     |=  1   ;
}

#endif

