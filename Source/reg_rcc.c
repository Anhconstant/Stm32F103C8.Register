// #ifndef __REG_RCC_C__
// #define __REG_RCC_C__

/*  path to file include    */

#include "reg_rcc.h"

/*  Function start    */

void reg_Clock_Enable_GPIOA(void)
{
    reg_RCC->APB2ENR.IOPAEN     |=  1   ;
}

void reg_Clock_Enable_GPIOB(void)
{
    reg_RCC->APB2ENR.IOPBEN     |=  1   ;
}

void reg_Clock_Enable_GPIOC(void)
{
    reg_RCC->APB2ENR.IOPCEN     |=  1   ;
}

void reg_Clock_Enable_GPIOD(void)
{
    reg_RCC->APB2ENR.IOPDEN     |=  1   ;
}

void reg_Clock_Enable_GPIOE(void)
{
    reg_RCC->APB2ENR.IOPEEN     |=  1   ;
}
