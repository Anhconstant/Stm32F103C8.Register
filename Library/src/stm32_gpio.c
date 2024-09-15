/*
@author - github : Anhconstant
- MCU : stm32f103c8
PERIPHERAL : GENERAL PURPOSE INPUT OUTPUT 
*/
#ifndef __GPIO_C__
#define __GPIO_C__

/*  path to file include    */

#include "stm32_gpio.h"

/*  Function start    */

void GPIO_Init(GPIO_TypeDef *GPIO, unsigned int GPIO_PIN, GPIO_MODE GPIO_MODE)
{
    int i;
    for (i = 0; i < 8; i++)
    {
        if (GPIO_PIN & 1 << i){ /*	GPIO_PIN & 1<<i: true neu khac 0 						    */
            GPIO->CRL &=~ ( 0x0f<<(4*i) )     ;
            GPIO->CRL |= GPIO_MODE<<( 4*i )   ;  
        }
    }

    for (i = 0; i < 8; i++)
    {

        if (GPIO_PIN & 1 << (i + 8)){
            GPIO->CRH &=~ ( 0x0f<<(4*i) )     ;
            GPIO->CRH |= GPIO_MODE<<( 4*i )   ;
        }
    }
}

GPIO_STATE ReadGPIO(GPIO_TypeDef *GPIO, unsigned int GPIO_PIN)
{
    GPIO_STATE pin_state;
    if ((GPIO->IDR & GPIO_PIN) != GPIO_RESET)
        pin_state = GPIO_SET;
    else
        pin_state = GPIO_RESET;
    return pin_state;
}

void WriteGPIO(GPIO_TypeDef *GPIO, unsigned int GPIO_PIN, GPIO_STATE pin_state)
{
    if (pin_state == GPIO_RESET)
        GPIO->BSRR |= GPIO_PIN<<16;
    else
        GPIO->BSRR |= GPIO_PIN;
}

void ToggleGPIO(GPIO_TypeDef *GPIO, unsigned int GPIO_PIN)
{
    unsigned odr = GPIO->ODR & GPIO_PIN;
    if (odr != 0)
        GPIO->BSRR |= GPIO_PIN<<16  ;
    else
        GPIO->BSRR |= GPIO_PIN      ;
}

void ResetALL(GPIO_TypeDef *GPIO)
{
    GPIO->BSRR = GPIO_PIN_ALL;
}

void SetALL(GPIO_TypeDef *GPIO)
{
    GPIO->BSRR = GPIO_PIN_ALL;
}

void LockPIN(GPIO_TypeDef *GPIO, unsigned int GPIO_PIN)
{   
    GPIO->LCKR &= ~1<<16     ;           /*  Unlock Register LCKK    */

    GPIO->LCKR |=  GPIO_PIN    ;   /*  Lock Pin                */

    GPIO->LCKR |=  1<<16   ;           /*  Lock Register LCKK      */
}
#endif

