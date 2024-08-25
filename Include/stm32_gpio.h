/*
@author: Tran Tuan Anh 
@github: Anhconstant
- MCU : stm32f103c8
PERIPHERAL : GENERAL PURPOSE INPUT OUTPUT 
*/

#ifndef __GPIO_H__
#define __GPIO_H__

/*  include start */

#include "stm32_rcc.h"

/*  include end */

/* TypeDef stuct GIPO start         */

typedef struct
{
    unsigned long CRL   ;

    unsigned long CRH   ;

    unsigned long IDR   ;

    unsigned long ODR   ;

    struct
    {
        unsigned int BS ;
        unsigned int BR ;
    } BSRR  ;

    struct
    {
        unsigned long b0    :   1   ;
        unsigned long b1    :   1   ;
        unsigned long b2    :   1   ;
        unsigned long b3    :   1   ;
        unsigned long b4    :   1   ;
        unsigned long b5    :   1   ;
        unsigned long b6    :   1   ;
        unsigned long b7    :   1   ;

        unsigned long b8    :   1   ;
        unsigned long b9    :   1   ;
        unsigned long b10   :   1   ;
        unsigned long b11   :   1   ;
        unsigned long b12   :   1   ;
        unsigned long b13   :   1   ;
        unsigned long b14   :   1   ;
        unsigned long b15   :   1   ;

        unsigned long _res  :   16  ;

    } BRR   ;

    struct
    {
        unsigned int LCK    ;
        unsigned long LCKK  :    1  ;

        unsigned long _res  :    15 ;

    } LCKR  ;

} GPIO_TypeDef  ;

/* TypeDef stuct GIPO end          */

/* Define gpio address register start      */

#define GPIOA           ((GPIO_TypeDef *)0x40010800UL   )
#define GPIOB           ((GPIO_TypeDef *)0x40010C00UL   )
#define GPIOC           ((GPIO_TypeDef *)0x40011000UL   )
#define GPIOD           ((GPIO_TypeDef *)0x40011400UL   )
#define GPIOE           ((GPIO_TypeDef *)0x40011800UL   )
#define GPIOF           ((GPIO_TypeDef *)0x40011C00UL   )
#define GPIOG           ((GPIO_TypeDef *)0x40012000UL   )

#define GPIO_PIN_0      ((unsigned int)0x0001   )           /*  Select pin 0    : 0000 0000 0000 0001      */
#define GPIO_PIN_1      ((unsigned int)0x0002   )           /*  Select pin 1    : 0000 0000 0000 0010      */
#define GPIO_PIN_2      ((unsigned int)0x0004   )           /*  Select pin 2    : 0000 0000 0000 0100      */
#define GPIO_PIN_3      ((unsigned int)0x0008   )           /*  Select pin 3    : 0000 0000 0000 1000      */
#define GPIO_PIN_4      ((unsigned int)0x0010   )           /*  Select pin 4    : 0000 0000 0001 0000      */    
#define GPIO_PIN_5      ((unsigned int)0x0020   )           /*  Select pin 5    : 0000 0000 0010 0000      */
#define GPIO_PIN_6      ((unsigned int)0x0040   )           /*  Select pin 6    : 0000 0000 0100 0000      */
#define GPIO_PIN_7      ((unsigned int)0x0080   )           /*  Select pin 7    : 0000 0000 1000 0000      */                    
#define GPIO_PIN_8      ((unsigned int)0x0100   )           /*  Select pin 8    : 0000 0001 0000 0000      */
#define GPIO_PIN_9      ((unsigned int)0x0200   )           /*  Select pin 9    : 0000 0010 0000 0000      */
#define GPIO_PIN_10     ((unsigned int)0x0400   )           /*  Select pin 10   : 0000 0100 0000 0000      */
#define GPIO_PIN_11     ((unsigned int)0x0800   )           /*  Select pin 11   : 0000 1000 0000 0000      */
#define GPIO_PIN_12     ((unsigned int)0x1000   )           /*  Select pin 12   : 0001 0000 0000 0000      */
#define GPIO_PIN_13     ((unsigned int)0x2000   )           /*  Select pin 13   : 0010 0000 0000 0000      */
#define GPIO_PIN_14     ((unsigned int)0x4000   )           /*  Select pin 14   : 0100 0000 0000 0000      */
#define GPIO_PIN_15     ((unsigned int)0x8000   )           /*  Select pin 15   : 1000 0000 0000 0000      */
#define GPIO_PIN_ALL    ((unsigned int)0xFFFF   )           /*  Select all pin  : 1111 1111 1111 1111      */

/* Define gpio address register end        */

/* Declare Type start                        */

typedef enum
{
    // cau hinh CNF & MODE
    Analog                      =   (0 << 2) | 0,               // 0000
    Floating_Input              =   (1 << 2) | 0,               // 0100
    Input_PULL                  =   (2 << 2) | 0,               // 1000

    General_Output_PP_10mhz     =   (0 << 2) | 1,               // 0001
    General_Output_OD_10mhz     =   (1 << 2) | 1,               // 0101
    Alternate_Output_PP_10mhz   =   (2 << 2) | 1,               // 1001
    Alternate_Output_OP_10mhz   =   (3 << 2) | 1,               // 1101

    General_Output_PP_2mhz      =   (0 << 2) | 2,               // 0010
    General_Output_OD_2mhz      =   (1 << 2) | 2,               // 0110
    Alternate_Output_PP_2mhz    =   (2 << 2) | 2,               // 1010
    Alternate_Output_OP_2mhz    =   (3 << 2) | 2,               // 1110

    General_Output_PP_50mhz     =   (0 << 2) | 3,               // 0010
    General_Output_OD_50mhz     =   (1 << 2) | 3,               // 0110
    Alternate_Output_PP_50mhz   =   (2 << 2) | 3,               // 1010
    Alternate_Output_OP_50mhz   =   (3 << 2) | 3,               // 1110

} GPIO_MODE;

typedef enum
{
    GPIO_RESET = 0u,
    GPIO_SET
} GPIO_STATE;

/* Declare Type end                         */

/* Declare Function start                   */

void GPIO_Init(GPIO_TypeDef *GPIO, unsigned int GPIO_PIN, GPIO_MODE GPIO_MODE);

GPIO_STATE ReadGPIO(GPIO_TypeDef *GPIO, unsigned int GPIO_PIN);

void WriteGPIO(GPIO_TypeDef *GPIO, unsigned int GPIO_PIN, GPIO_STATE pin_state);

void ToggleGPIO(GPIO_TypeDef *GPIO, unsigned int GPIO_PIN);

void ResetALL(GPIO_TypeDef *GPIO);

void SetALL(GPIO_TypeDef *GPIO);

void LockPIN(GPIO_TypeDef *GPIO, unsigned int GPIO_PIN);

/* Declare Function end                   */

#endif
