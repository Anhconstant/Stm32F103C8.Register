#ifndef __GPIO_C__
#define __GPIO_C__

/*  path to file include    */

#include "../include/gpio.h"

/*  Function start    */

void GPIO_Init(GPIO_TypeDef *GPIO, unsigned int GPIO_PIN, GPIO_MODE GPIO_MODE)
{
    unsigned int set = 0;   /*	tao lap bien 32 bit ghi lai tam thoi cac pin duoc su dung		*/
    unsigned int reset = 0; /*	tao lap bien 32 bit ghi lai tam thoi cac pin khong su dung	    */
    int i;

    for (i = 0; i < 8; i++)
    {
        set <<= 4;
        reset <<= 4;
        if (GPIO_PIN & 1 << i) /*	GPIO_PIN & 1<<i: true neu khac 0 						    */
            set |= GPIO_MODE;
        else
            reset |= 0x0f;
        GPIO->CRL &= reset; /*	GPIO->CRL	: thanh ghi dieu khien Pin	0	~ 7			    */
        GPIO->CRL |= set;
    }

    set = 0;
    reset = 0;

    for (i = 0; i < 8; i++)
    {
        set <<= 4;
        reset <<= 4;
        if (GPIO_PIN & 1 << (i + 8))
            set |= GPIO_MODE;
        else
            reset |= 0x0f;
        GPIO->CRH &= reset; /*	GPIO->CRL	: thanh ghi dieu khien Pin	0	~ 7			    */
        GPIO->CRH |= set;
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
        GPIO->BSRR.BR = GPIO_PIN;
    else
        GPIO->BSRR.BS = GPIO_PIN;
}

void ToggleGPIO(GPIO_TypeDef *GPIO, unsigned int GPIO_PIN)
{
    unsigned odr = GPIO->ODR & GPIO_PIN;
    if (odr != 0)
        GPIO->BSRR.BR = GPIO_PIN;
    else
        GPIO->BSRR.BS = GPIO_PIN;
}

void ResetALL(GPIO_TypeDef *GPIO)
{
    GPIO->BSRR.BR = GPIO_PIN_ALL;
}

void SetALL(GPIO_TypeDef *GPIO)
{
    GPIO->BSRR.BS = GPIO_PIN_ALL;
}

void LockPIN(GPIO_TypeDef *GPIO, unsigned int GPIO_PIN)
{   
    GPIO->LCKR.LCKK |=  0   ;           /*  Unlock Register LCKK    */

    GPIO->LCKR.LCK  |=  GPIO_PIN    ;   /*  Lock Pin                */

    GPIO->LCKR.LCKK |=  1   ;           /*  Lock Register LCKK      */
}
#endif

