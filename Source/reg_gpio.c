// #ifndef __REG_GPIO_C__
// #define __REG_GPIO_C__

/*  path to file include    */

#include "reg_gpio.h"

/*  Function start    */

void reg_GPIO_Init(reg_GPIO_TypeDef *reg_GPIO, unsigned int reg_GPIO_PIN, reg_GPIO_MODE GPIO_MODE)
{
    unsigned int set = 0;   /*	tao lap bien 32 bit ghi lai tam thoi cac pin duoc su dung		*/
    unsigned int reset = 0; /*	tao lap bien 32 bit ghi lai tam thoi cac pin khong su dung	    */
    int i;

    for (i = 0; i < 8; i++)
    {
        set <<= 4;
        reset <<= 4;
        if (reg_GPIO_PIN & 1 << i) /*	reg_GPIO_PIN & 1<<i: true neu khac 0 						    */
            set |= GPIO_MODE;
        else
            reset |= 0x0f;
        reg_GPIO->CRL &= reset; /*	reg_GPIO->CRL	: thanh ghi dieu khien Pin	0	~ 7			    */
        reg_GPIO->CRL |= set;
    }

    set = 0;
    reset = 0;

    for (i = 0; i < 8; i++)
    {
        set <<= 4;
        reset <<= 4;
        if (reg_GPIO_PIN & 1 << (i + 8))
            set |= GPIO_MODE;
        else
            reset |= 0x0f;
        reg_GPIO->CRH &= reset; /*	reg_GPIO->CRL	: thanh ghi dieu khien Pin	0	~ 7			    */
        reg_GPIO->CRH |= set;
    }
}

reg_GPIO_STATE reg_ReadGPIO(reg_GPIO_TypeDef *reg_GPIO, unsigned int GPIO_PIN)
{
    reg_GPIO_STATE pin_state;
    if ((reg_GPIO->IDR & GPIO_PIN) != GPIO_RESET)
        pin_state = GPIO_SET;
    else
        pin_state = GPIO_RESET;
    return pin_state;
}

void reg_WriteGPIO(reg_GPIO_TypeDef *reg_GPIO, unsigned int GPIO_PIN, reg_GPIO_STATE pin_state)
{
    if (pin_state == GPIO_RESET)
        reg_GPIO->BSRR.BR = GPIO_PIN;
    else
        reg_GPIO->BSRR.BS = GPIO_PIN;
}

void reg_ToggleGPIO(reg_GPIO_TypeDef *reg_GPIO, unsigned int GPIO_PIN)
{
    unsigned odr = reg_GPIO->ODR & GPIO_PIN;
    if (odr != 0)
        reg_GPIO->BSRR.BR = GPIO_PIN;
    else
        reg_GPIO->BSRR.BS = GPIO_PIN;
}

void reg_ResetALL(reg_GPIO_TypeDef *reg_GPIO)
{
    reg_GPIO->BSRR.BR = reg_GPIO_PIN_ALL;
}

void reg_SetALL(reg_GPIO_TypeDef *reg_GPIO)
{
    reg_GPIO->BSRR.BS = reg_GPIO_PIN_ALL;
}

void reg_LockPIN(reg_GPIO_TypeDef *reg_GPIO, unsigned int GPIO_PIN)
{   
    reg_GPIO->LCKR.LCKK |=  0   ;           /*  Unlock Register LCKK    */

    reg_GPIO->LCKR.LCK  |=  GPIO_PIN    ;   /*  Lock Pin                */

    reg_GPIO->LCKR.LCKK |=  1   ;           /*  Lock Register LCKK      */
}
// #endif

